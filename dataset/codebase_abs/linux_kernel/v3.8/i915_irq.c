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
F_37 ( & V_58 -> V_61 ) ;
F_33 ( L_6 ) ;
F_38 (encoder, &mode_config->encoder_list, base.head)
if ( V_60 -> V_62 )
V_60 -> V_62 ( V_60 ) ;
F_39 ( & V_58 -> V_61 ) ;
F_40 ( V_9 ) ;
}
static void F_41 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_10 ;
T_2 V_63 , V_64 , V_65 , V_66 ;
T_3 V_67 ;
unsigned long V_46 ;
F_10 ( & V_68 , V_46 ) ;
F_42 ( V_69 , F_16 ( V_69 ) ) ;
V_67 = V_1 -> V_70 . V_71 ;
F_42 ( V_69 , V_72 ) ;
V_63 = F_16 ( V_73 ) ;
V_64 = F_16 ( V_74 ) ;
V_65 = F_16 ( V_75 ) ;
V_66 = F_16 ( V_76 ) ;
if ( V_63 > V_65 ) {
if ( V_1 -> V_70 . V_71 != V_1 -> V_70 . V_77 )
V_67 = V_1 -> V_70 . V_71 - 1 ;
if ( V_67 < V_1 -> V_70 . V_77 )
V_67 = V_1 -> V_70 . V_77 ;
} else if ( V_64 < V_66 ) {
if ( V_1 -> V_70 . V_71 != V_1 -> V_70 . V_78 )
V_67 = V_1 -> V_70 . V_71 + 1 ;
if ( V_67 > V_1 -> V_70 . V_78 )
V_67 = V_1 -> V_70 . V_78 ;
}
if ( F_43 ( V_9 , V_67 ) )
V_1 -> V_70 . V_71 = V_67 ;
F_13 ( & V_68 , V_46 ) ;
return;
}
static void F_44 ( struct V_8 * V_9 ,
struct V_79 * V_80 )
{
struct V_47 * V_1 = V_9 -> V_10 ;
if ( V_80 -> V_81 == NULL )
return;
F_45 ( V_80 , V_80 -> V_82 ( V_80 , false ) ) ;
F_46 ( & V_80 -> V_83 ) ;
if ( V_84 ) {
V_1 -> V_85 = 0 ;
F_47 ( & V_1 -> V_86 ,
F_48 ( V_87 + V_88 ) ) ;
}
}
static void F_49 ( struct V_54 * V_55 )
{
T_1 * V_1 = F_36 ( V_55 , T_1 ,
V_89 . V_55 ) ;
T_2 V_90 , V_91 ;
T_3 V_67 ;
F_50 ( & V_1 -> V_89 . V_92 ) ;
V_90 = V_1 -> V_89 . V_90 ;
V_1 -> V_89 . V_90 = 0 ;
V_91 = F_16 ( V_93 ) ;
F_2 ( V_93 , 0 ) ;
F_51 ( & V_1 -> V_89 . V_92 ) ;
if ( ( V_90 & V_94 ) == 0 )
return;
F_37 ( & V_1 -> V_89 . V_95 ) ;
if ( V_90 & V_96 )
V_67 = V_1 -> V_89 . V_71 + 1 ;
else
V_67 = V_1 -> V_89 . V_71 - 1 ;
if ( ! ( V_67 > V_1 -> V_89 . V_77 ||
V_67 < V_1 -> V_89 . V_78 ) ) {
F_52 ( V_1 -> V_9 , V_67 ) ;
}
F_39 ( & V_1 -> V_89 . V_95 ) ;
}
static void F_53 ( struct V_54 * V_55 )
{
T_1 * V_1 = F_36 ( V_55 , T_1 ,
V_97 . V_98 ) ;
T_2 V_99 , V_100 , V_101 , V_102 ;
char * V_103 [ 5 ] ;
T_4 V_104 ;
unsigned long V_46 ;
F_37 ( & V_1 -> V_9 -> V_105 ) ;
V_104 = F_16 ( V_106 ) ;
F_2 ( V_106 , V_104 & ~ V_107 ) ;
F_3 ( V_106 ) ;
V_99 = F_16 ( V_108 ) ;
V_100 = F_54 ( V_99 ) ;
V_101 = F_55 ( V_99 ) ;
V_102 = F_56 ( V_99 ) ;
F_2 ( V_108 , V_109 |
V_110 ) ;
F_3 ( V_108 ) ;
F_2 ( V_106 , V_104 ) ;
F_10 ( & V_1 -> V_12 , V_46 ) ;
V_1 -> V_111 &= ~ V_112 ;
F_2 ( V_113 , V_1 -> V_111 ) ;
F_13 ( & V_1 -> V_12 , V_46 ) ;
F_39 ( & V_1 -> V_9 -> V_105 ) ;
V_103 [ 0 ] = L_7 ;
V_103 [ 1 ] = F_57 ( V_114 , L_8 , V_100 ) ;
V_103 [ 2 ] = F_57 ( V_114 , L_9 , V_101 ) ;
V_103 [ 3 ] = F_57 ( V_114 , L_10 , V_102 ) ;
V_103 [ 4 ] = NULL ;
F_58 ( & V_1 -> V_9 -> V_115 -> V_116 . V_117 ,
V_118 , V_103 ) ;
F_59 ( L_11 ,
V_100 , V_101 , V_102 ) ;
F_60 ( V_103 [ 3 ] ) ;
F_60 ( V_103 [ 2 ] ) ;
F_60 ( V_103 [ 1 ] ) ;
}
static void F_61 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_46 ;
if ( ! F_62 ( V_9 ) )
return;
F_10 ( & V_1 -> V_12 , V_46 ) ;
V_1 -> V_111 |= V_112 ;
F_2 ( V_113 , V_1 -> V_111 ) ;
F_13 ( & V_1 -> V_12 , V_46 ) ;
F_63 ( V_1 -> V_119 , & V_1 -> V_97 . V_98 ) ;
}
static void F_64 ( struct V_8 * V_9 ,
struct V_47 * V_1 ,
T_2 V_120 )
{
if ( V_120 & ( V_121 |
V_122 ) )
F_44 ( V_9 , & V_1 -> V_80 [ V_123 ] ) ;
if ( V_120 & V_124 )
F_44 ( V_9 , & V_1 -> V_80 [ V_125 ] ) ;
if ( V_120 & V_126 )
F_44 ( V_9 , & V_1 -> V_80 [ V_127 ] ) ;
if ( V_120 & ( V_128 |
V_129 |
V_130 ) ) {
F_31 ( L_12 , V_120 ) ;
F_65 ( V_9 , false ) ;
}
if ( V_120 & V_112 )
F_61 ( V_9 ) ;
}
static void F_66 ( struct V_47 * V_1 ,
T_2 V_90 )
{
unsigned long V_46 ;
F_10 ( & V_1 -> V_89 . V_92 , V_46 ) ;
V_1 -> V_89 . V_90 |= V_90 ;
F_2 ( V_93 , V_1 -> V_89 . V_90 ) ;
F_3 ( V_93 ) ;
F_13 ( & V_1 -> V_89 . V_92 , V_46 ) ;
F_63 ( V_1 -> V_119 , & V_1 -> V_89 . V_55 ) ;
}
static T_5 F_67 ( int V_131 , void * V_132 )
{
struct V_8 * V_9 = (struct V_8 * ) V_132 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_133 , V_120 , V_90 ;
T_5 V_37 = V_134 ;
unsigned long V_11 ;
int V_5 ;
T_2 V_135 [ V_136 ] ;
bool V_137 ;
F_68 ( & V_1 -> V_138 ) ;
while ( true ) {
V_133 = F_16 ( V_139 ) ;
V_120 = F_16 ( V_140 ) ;
V_90 = F_16 ( V_141 ) ;
if ( V_120 == 0 && V_90 == 0 && V_133 == 0 )
goto V_142;
V_37 = V_143 ;
F_64 ( V_9 , V_1 , V_120 ) ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_69 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_135 [ V_5 ] = F_16 ( V_7 ) ;
if ( V_135 [ V_5 ] & 0x8000ffff ) {
if ( V_135 [ V_5 ] & V_144 )
F_19 ( L_13 ,
F_20 ( V_5 ) ) ;
F_2 ( V_7 , V_135 [ V_5 ] ) ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
F_69 (pipe) {
if ( V_135 [ V_5 ] & V_145 )
F_70 ( V_9 , V_5 ) ;
if ( V_135 [ V_5 ] & V_146 ) {
F_71 ( V_9 , V_5 ) ;
F_72 ( V_9 , V_5 ) ;
}
}
if ( V_133 & V_147 ) {
T_2 V_148 = F_16 ( V_149 ) ;
F_19 ( L_14 ,
V_148 ) ;
if ( V_148 & V_1 -> V_150 )
F_63 ( V_1 -> V_119 ,
& V_1 -> V_56 ) ;
F_2 ( V_149 , V_148 ) ;
F_16 ( V_149 ) ;
}
if ( V_135 [ V_5 ] & V_151 )
V_137 = true ;
if ( V_90 & V_94 )
F_66 ( V_1 , V_90 ) ;
F_2 ( V_140 , V_120 ) ;
F_2 ( V_141 , V_90 ) ;
F_2 ( V_139 , V_133 ) ;
}
V_142:
return V_37 ;
}
static void F_73 ( struct V_8 * V_9 , T_2 V_152 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( V_152 & V_153 )
F_63 ( V_1 -> V_119 , & V_1 -> V_56 ) ;
if ( V_152 & V_154 )
F_19 ( L_15 ,
( V_152 & V_154 ) >>
V_155 ) ;
if ( V_152 & V_156 )
F_19 ( L_16 ) ;
if ( V_152 & V_157 )
F_19 ( L_17 ) ;
if ( V_152 & V_158 )
F_19 ( L_18 ) ;
if ( V_152 & V_159 )
F_31 ( L_19 ) ;
if ( V_152 & V_160 )
F_69 (pipe)
F_19 ( L_20 ,
F_20 ( V_5 ) ,
F_16 ( F_74 ( V_5 ) ) ) ;
if ( V_152 & ( V_161 | V_162 ) )
F_19 ( L_21 ) ;
if ( V_152 & ( V_163 | V_164 ) )
F_19 ( L_22 ) ;
if ( V_152 & V_165 )
F_19 ( L_23 ) ;
if ( V_152 & V_166 )
F_19 ( L_24 ) ;
}
static void F_75 ( struct V_8 * V_9 , T_2 V_152 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( V_152 & V_167 )
F_63 ( V_1 -> V_119 , & V_1 -> V_56 ) ;
if ( V_152 & V_168 )
F_19 ( L_15 ,
( V_152 & V_168 ) >>
V_169 ) ;
if ( V_152 & V_170 )
F_19 ( L_25 ) ;
if ( V_152 & V_171 )
F_19 ( L_16 ) ;
if ( V_152 & V_172 )
F_19 ( L_26 ) ;
if ( V_152 & V_173 )
F_19 ( L_27 ) ;
if ( V_152 & V_174 )
F_69 (pipe)
F_19 ( L_20 ,
F_20 ( V_5 ) ,
F_16 ( F_74 ( V_5 ) ) ) ;
}
static T_5 F_76 ( int V_131 , void * V_132 )
{
struct V_8 * V_9 = (struct V_8 * ) V_132 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_175 , V_120 , V_176 , V_90 ;
T_5 V_37 = V_134 ;
int V_177 ;
F_68 ( & V_1 -> V_138 ) ;
V_176 = F_16 ( V_178 ) ;
F_2 ( V_178 , V_176 & ~ V_179 ) ;
V_120 = F_16 ( V_140 ) ;
if ( V_120 ) {
F_64 ( V_9 , V_1 , V_120 ) ;
F_2 ( V_140 , V_120 ) ;
V_37 = V_143 ;
}
V_175 = F_16 ( V_180 ) ;
if ( V_175 ) {
if ( V_175 & V_181 )
F_77 ( V_9 ) ;
for ( V_177 = 0 ; V_177 < 3 ; V_177 ++ ) {
if ( V_175 & ( V_182 << ( 5 * V_177 ) ) )
F_70 ( V_9 , V_177 ) ;
if ( V_175 & ( V_183 << ( 5 * V_177 ) ) ) {
F_71 ( V_9 , V_177 ) ;
F_78 ( V_9 , V_177 ) ;
}
}
if ( V_175 & V_184 ) {
T_2 V_152 = F_16 ( V_185 ) ;
F_75 ( V_9 , V_152 ) ;
F_2 ( V_185 , V_152 ) ;
}
F_2 ( V_180 , V_175 ) ;
V_37 = V_143 ;
}
V_90 = F_16 ( V_141 ) ;
if ( V_90 ) {
if ( V_90 & V_94 )
F_66 ( V_1 , V_90 ) ;
F_2 ( V_141 , V_90 ) ;
V_37 = V_143 ;
}
F_2 ( V_178 , V_176 ) ;
F_3 ( V_178 ) ;
return V_37 ;
}
static void F_79 ( struct V_8 * V_9 ,
struct V_47 * V_1 ,
T_2 V_120 )
{
if ( V_120 & ( V_186 | V_187 ) )
F_44 ( V_9 , & V_1 -> V_80 [ V_123 ] ) ;
if ( V_120 & V_188 )
F_44 ( V_9 , & V_1 -> V_80 [ V_125 ] ) ;
}
static T_5 F_80 ( int V_131 , void * V_132 )
{
struct V_8 * V_9 = (struct V_8 * ) V_132 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_37 = V_134 ;
T_2 V_175 , V_120 , V_176 , V_152 , V_90 ;
F_68 ( & V_1 -> V_138 ) ;
V_176 = F_16 ( V_178 ) ;
F_2 ( V_178 , V_176 & ~ V_179 ) ;
F_3 ( V_178 ) ;
V_175 = F_16 ( V_180 ) ;
V_120 = F_16 ( V_140 ) ;
V_152 = F_16 ( V_185 ) ;
V_90 = F_16 ( V_141 ) ;
if ( V_175 == 0 && V_120 == 0 && V_152 == 0 &&
( ! F_81 ( V_9 ) || V_90 == 0 ) )
goto V_189;
V_37 = V_143 ;
if ( F_82 ( V_9 ) )
F_79 ( V_9 , V_1 , V_120 ) ;
else
F_64 ( V_9 , V_1 , V_120 ) ;
if ( V_175 & V_13 )
F_77 ( V_9 ) ;
if ( V_175 & V_190 )
F_70 ( V_9 , 0 ) ;
if ( V_175 & V_191 )
F_70 ( V_9 , 1 ) ;
if ( V_175 & V_192 ) {
F_71 ( V_9 , 0 ) ;
F_78 ( V_9 , 0 ) ;
}
if ( V_175 & V_193 ) {
F_71 ( V_9 , 1 ) ;
F_78 ( V_9 , 1 ) ;
}
if ( V_175 & V_194 ) {
if ( F_83 ( V_9 ) )
F_75 ( V_9 , V_152 ) ;
else
F_73 ( V_9 , V_152 ) ;
}
if ( F_82 ( V_9 ) && V_175 & V_195 )
F_41 ( V_9 ) ;
if ( F_81 ( V_9 ) && V_90 & V_94 )
F_66 ( V_1 , V_90 ) ;
F_2 ( V_185 , V_152 ) ;
F_2 ( V_140 , V_120 ) ;
F_2 ( V_180 , V_175 ) ;
F_2 ( V_141 , V_90 ) ;
V_189:
F_2 ( V_178 , V_176 ) ;
F_3 ( V_178 ) ;
return V_37 ;
}
static void F_84 ( struct V_54 * V_55 )
{
T_1 * V_1 = F_36 ( V_55 , T_1 ,
V_98 ) ;
struct V_8 * V_9 = V_1 -> V_9 ;
char * V_196 [] = { L_28 , NULL } ;
char * V_197 [] = { L_29 , NULL } ;
char * V_198 [] = { L_30 , NULL } ;
F_58 ( & V_9 -> V_115 -> V_116 . V_117 , V_118 , V_196 ) ;
if ( F_85 ( & V_1 -> V_199 . V_200 ) ) {
F_19 ( L_31 ) ;
F_58 ( & V_9 -> V_115 -> V_116 . V_117 , V_118 , V_197 ) ;
if ( ! F_86 ( V_9 ) ) {
F_87 ( & V_1 -> V_199 . V_200 , 0 ) ;
F_58 ( & V_9 -> V_115 -> V_116 . V_117 , V_118 , V_198 ) ;
}
F_88 ( & V_1 -> V_201 ) ;
}
}
static void F_89 ( struct V_8 * V_9 ,
T_4 * V_202 )
{
struct V_47 * V_1 = V_9 -> V_10 ;
memset ( V_202 , 0 , sizeof( * V_202 ) * V_203 ) ;
switch( F_12 ( V_9 ) -> V_15 ) {
case 2 :
case 3 :
V_202 [ 0 ] = F_16 ( V_204 ) ;
break;
case 4 :
case 5 :
case 6 :
V_202 [ 0 ] = F_16 ( V_205 ) ;
V_202 [ 1 ] = F_16 ( V_206 ) ;
break;
default:
F_90 ( 1 , L_32 ) ;
case 7 :
V_202 [ 0 ] = F_16 ( V_207 ) ;
V_202 [ 1 ] = F_16 ( V_208 ) ;
V_202 [ 2 ] = F_16 ( V_209 ) ;
V_202 [ 3 ] = F_16 ( V_210 ) ;
break;
}
}
static struct V_211 *
F_91 ( struct V_47 * V_1 ,
struct V_212 * V_213 )
{
struct V_211 * V_214 ;
int V_177 , V_215 ;
T_2 V_216 ;
if ( V_213 == NULL || V_213 -> V_217 == NULL )
return NULL ;
V_215 = V_213 -> V_218 . V_219 / V_220 ;
V_214 = F_92 ( sizeof( * V_214 ) + V_215 * sizeof( T_2 * ) , V_221 ) ;
if ( V_214 == NULL )
return NULL ;
V_216 = V_213 -> V_222 ;
for ( V_177 = 0 ; V_177 < V_215 ; V_177 ++ ) {
unsigned long V_46 ;
void * V_223 ;
V_223 = F_92 ( V_220 , V_221 ) ;
if ( V_223 == NULL )
goto V_224;
F_93 ( V_46 ) ;
if ( V_216 < V_1 -> V_199 . V_225 &&
V_213 -> V_226 ) {
void T_6 * V_227 ;
V_227 = F_94 ( V_1 -> V_199 . V_228 ,
V_216 ) ;
F_95 ( V_223 , V_227 , V_220 ) ;
F_96 ( V_227 ) ;
} else {
struct V_229 * V_229 ;
void * V_227 ;
V_229 = F_97 ( V_213 , V_177 ) ;
F_98 ( & V_229 , 1 ) ;
V_227 = F_99 ( V_229 ) ;
memcpy ( V_223 , V_227 , V_220 ) ;
F_100 ( V_227 ) ;
F_98 ( & V_229 , 1 ) ;
}
F_101 ( V_46 ) ;
V_214 -> V_217 [ V_177 ] = V_223 ;
V_216 += V_220 ;
}
V_214 -> V_230 = V_215 ;
V_214 -> V_222 = V_213 -> V_222 ;
return V_214 ;
V_224:
while ( V_177 -- )
F_60 ( V_214 -> V_217 [ V_177 ] ) ;
F_60 ( V_214 ) ;
return NULL ;
}
static void
F_102 ( struct V_211 * V_81 )
{
int V_229 ;
if ( V_81 == NULL )
return;
for ( V_229 = 0 ; V_229 < V_81 -> V_230 ; V_229 ++ )
F_60 ( V_81 -> V_217 [ V_229 ] ) ;
F_60 ( V_81 ) ;
}
void
F_103 ( struct V_231 * V_232 )
{
struct V_233 * error = F_36 ( V_232 ,
F_104 ( * error ) , V_234 ) ;
int V_177 ;
for ( V_177 = 0 ; V_177 < F_105 ( error -> V_80 ) ; V_177 ++ ) {
F_102 ( error -> V_80 [ V_177 ] . V_235 ) ;
F_102 ( error -> V_80 [ V_177 ] . V_236 ) ;
F_60 ( error -> V_80 [ V_177 ] . V_237 ) ;
}
F_60 ( error -> V_238 ) ;
F_60 ( error -> V_239 ) ;
F_60 ( error ) ;
}
static void F_106 ( struct V_240 * V_241 ,
struct V_212 * V_81 )
{
V_241 -> V_219 = V_81 -> V_218 . V_219 ;
V_241 -> V_242 = V_81 -> V_218 . V_242 ;
V_241 -> V_243 = V_81 -> V_244 ;
V_241 -> V_245 = V_81 -> V_246 ;
V_241 -> V_222 = V_81 -> V_222 ;
V_241 -> V_247 = V_81 -> V_218 . V_247 ;
V_241 -> V_248 = V_81 -> V_218 . V_248 ;
V_241 -> V_249 = V_81 -> V_249 ;
V_241 -> V_250 = 0 ;
if ( V_81 -> V_251 > 0 )
V_241 -> V_250 = 1 ;
if ( V_81 -> V_252 > 0 )
V_241 -> V_250 = - 1 ;
V_241 -> V_253 = V_81 -> V_254 ;
V_241 -> V_255 = V_81 -> V_255 ;
V_241 -> V_256 = V_81 -> V_257 != V_258 ;
V_241 -> V_80 = V_81 -> V_80 ? V_81 -> V_80 -> V_259 : - 1 ;
V_241 -> V_260 = V_81 -> V_260 ;
}
static T_2 F_107 ( struct V_240 * V_241 ,
int V_215 , struct V_261 * V_262 )
{
struct V_212 * V_81 ;
int V_177 = 0 ;
F_38 (obj, head, mm_list) {
F_106 ( V_241 ++ , V_81 ) ;
if ( ++ V_177 == V_215 )
break;
}
return V_177 ;
}
static T_2 F_108 ( struct V_240 * V_241 ,
int V_215 , struct V_261 * V_262 )
{
struct V_212 * V_81 ;
int V_177 = 0 ;
F_38 (obj, head, gtt_list) {
if ( V_81 -> V_251 == 0 )
continue;
F_106 ( V_241 ++ , V_81 ) ;
if ( ++ V_177 == V_215 )
break;
}
return V_177 ;
}
static void F_109 ( struct V_8 * V_9 ,
struct V_233 * error )
{
struct V_47 * V_1 = V_9 -> V_10 ;
int V_177 ;
switch ( F_12 ( V_9 ) -> V_15 ) {
case 7 :
case 6 :
for ( V_177 = 0 ; V_177 < 16 ; V_177 ++ )
error -> V_263 [ V_177 ] = F_110 ( V_264 + ( V_177 * 8 ) ) ;
break;
case 5 :
case 4 :
for ( V_177 = 0 ; V_177 < 16 ; V_177 ++ )
error -> V_263 [ V_177 ] = F_110 ( V_265 + ( V_177 * 8 ) ) ;
break;
case 3 :
if ( F_111 ( V_9 ) || F_112 ( V_9 ) || F_113 ( V_9 ) )
for ( V_177 = 0 ; V_177 < 8 ; V_177 ++ )
error -> V_263 [ V_177 + 8 ] = F_16 ( V_266 + ( V_177 * 4 ) ) ;
case 2 :
for ( V_177 = 0 ; V_177 < 8 ; V_177 ++ )
error -> V_263 [ V_177 ] = F_16 ( V_267 + ( V_177 * 4 ) ) ;
break;
}
}
static struct V_211 *
F_114 ( struct V_47 * V_1 ,
struct V_79 * V_80 )
{
struct V_212 * V_81 ;
T_2 V_268 ;
if ( ! V_80 -> V_82 )
return NULL ;
if ( F_115 ( V_1 -> V_9 ) ) {
T_2 V_269 = F_16 ( V_270 ) ;
if ( F_116 ( V_80 -> V_259 != V_123 ) )
return NULL ;
V_81 = V_80 -> V_271 ;
if ( V_269 >= V_81 -> V_222 &&
V_269 < V_81 -> V_222 + V_81 -> V_218 . V_219 )
return F_91 ( V_1 , V_81 ) ;
}
V_268 = V_80 -> V_82 ( V_80 , false ) ;
F_38 (obj, &dev_priv->mm.active_list, mm_list) {
if ( V_81 -> V_80 != V_80 )
continue;
if ( F_117 ( V_268 , V_81 -> V_244 ) )
continue;
if ( ( V_81 -> V_218 . V_247 & V_272 ) == 0 )
continue;
return F_91 ( V_1 , V_81 ) ;
}
return NULL ;
}
static void F_118 ( struct V_8 * V_9 ,
struct V_233 * error ,
struct V_79 * V_80 )
{
struct V_47 * V_1 = V_9 -> V_10 ;
if ( F_12 ( V_9 ) -> V_15 >= 6 ) {
error -> V_273 [ V_80 -> V_259 ] = F_16 ( V_80 -> V_274 + 0x50 ) ;
error -> V_275 [ V_80 -> V_259 ] = F_16 ( F_119 ( V_80 ) ) ;
error -> V_276 [ V_80 -> V_259 ] [ 0 ]
= F_16 ( F_120 ( V_80 -> V_274 ) ) ;
error -> V_276 [ V_80 -> V_259 ] [ 1 ]
= F_16 ( F_121 ( V_80 -> V_274 ) ) ;
error -> V_277 [ V_80 -> V_259 ] [ 0 ] = V_80 -> V_278 [ 0 ] ;
error -> V_277 [ V_80 -> V_259 ] [ 1 ] = V_80 -> V_278 [ 1 ] ;
}
if ( F_12 ( V_9 ) -> V_15 >= 4 ) {
error -> V_279 [ V_80 -> V_259 ] = F_16 ( F_122 ( V_80 -> V_274 ) ) ;
error -> V_280 [ V_80 -> V_259 ] = F_16 ( F_123 ( V_80 -> V_274 ) ) ;
error -> V_281 [ V_80 -> V_259 ] = F_16 ( F_124 ( V_80 -> V_274 ) ) ;
error -> V_202 [ V_80 -> V_259 ] = F_16 ( F_125 ( V_80 -> V_274 ) ) ;
error -> V_282 [ V_80 -> V_259 ] = F_16 ( F_126 ( V_80 -> V_274 ) ) ;
if ( V_80 -> V_259 == V_123 )
error -> V_283 = F_110 ( V_284 ) ;
} else {
error -> V_279 [ V_80 -> V_259 ] = F_16 ( V_285 ) ;
error -> V_280 [ V_80 -> V_259 ] = F_16 ( V_286 ) ;
error -> V_281 [ V_80 -> V_259 ] = F_16 ( V_287 ) ;
error -> V_202 [ V_80 -> V_259 ] = F_16 ( V_204 ) ;
}
error -> V_288 [ V_80 -> V_259 ] = F_127 ( & V_80 -> V_83 ) ;
error -> V_289 [ V_80 -> V_259 ] = F_16 ( F_128 ( V_80 -> V_274 ) ) ;
error -> V_268 [ V_80 -> V_259 ] = V_80 -> V_82 ( V_80 , false ) ;
error -> V_269 [ V_80 -> V_259 ] = F_129 ( V_80 ) ;
error -> V_262 [ V_80 -> V_259 ] = F_130 ( V_80 ) ;
error -> V_290 [ V_80 -> V_259 ] = F_131 ( V_80 ) ;
error -> V_291 [ V_80 -> V_259 ] = F_132 ( V_80 ) ;
error -> V_292 [ V_80 -> V_259 ] = V_80 -> V_262 ;
error -> V_293 [ V_80 -> V_259 ] = V_80 -> V_290 ;
}
static void F_133 ( struct V_8 * V_9 ,
struct V_233 * error )
{
struct V_47 * V_1 = V_9 -> V_10 ;
struct V_79 * V_80 ;
struct V_294 * V_295 ;
int V_177 , V_215 ;
F_134 (ring, dev_priv, i) {
F_118 ( V_9 , error , V_80 ) ;
error -> V_80 [ V_177 ] . V_235 =
F_114 ( V_1 , V_80 ) ;
error -> V_80 [ V_177 ] . V_236 =
F_91 ( V_1 , V_80 -> V_81 ) ;
V_215 = 0 ;
F_38 (request, &ring->request_list, list)
V_215 ++ ;
error -> V_80 [ V_177 ] . V_296 = V_215 ;
error -> V_80 [ V_177 ] . V_237 =
F_92 ( V_215 * sizeof( struct V_297 ) ,
V_221 ) ;
if ( error -> V_80 [ V_177 ] . V_237 == NULL ) {
error -> V_80 [ V_177 ] . V_296 = 0 ;
continue;
}
V_215 = 0 ;
F_38 (request, &ring->request_list, list) {
struct V_297 * V_298 ;
V_298 = & error -> V_80 [ V_177 ] . V_237 [ V_215 ++ ] ;
V_298 -> V_268 = V_295 -> V_268 ;
V_298 -> V_87 = V_295 -> V_299 ;
V_298 -> V_290 = V_295 -> V_290 ;
}
}
}
static void F_135 ( struct V_8 * V_9 )
{
struct V_47 * V_1 = V_9 -> V_10 ;
struct V_212 * V_81 ;
struct V_233 * error ;
unsigned long V_46 ;
int V_177 , V_5 ;
F_10 ( & V_1 -> V_300 , V_46 ) ;
error = V_1 -> V_301 ;
F_13 ( & V_1 -> V_300 , V_46 ) ;
if ( error )
return;
error = F_136 ( sizeof( * error ) , V_221 ) ;
if ( ! error ) {
F_19 ( L_33 ) ;
return;
}
F_137 ( L_34 ,
V_9 -> V_115 -> V_302 ) ;
F_138 ( & error -> V_234 ) ;
error -> V_303 = F_16 ( V_304 ) ;
error -> V_305 = F_16 ( V_306 ) ;
error -> V_307 = F_16 ( V_308 ) ;
if ( F_11 ( V_9 ) )
error -> V_309 = F_16 ( V_178 ) | F_16 ( V_310 ) ;
else if ( F_9 ( V_9 ) )
error -> V_309 = F_16 ( V_310 ) | F_16 ( V_311 ) ;
else if ( F_139 ( V_9 ) )
error -> V_309 = F_140 ( V_312 ) ;
else
error -> V_309 = F_16 ( V_312 ) ;
if ( F_12 ( V_9 ) -> V_15 >= 6 )
error -> V_313 = F_16 ( V_314 ) ;
if ( F_9 ( V_9 ) )
error -> V_315 = F_16 ( V_316 ) ;
else if ( F_12 ( V_9 ) -> V_15 >= 7 )
error -> V_315 = F_16 ( V_317 ) ;
else if ( F_12 ( V_9 ) -> V_15 == 6 )
error -> V_315 = F_16 ( V_318 ) ;
F_69 ( V_5 )
error -> V_6 [ V_5 ] = F_16 ( F_6 ( V_5 ) ) ;
if ( F_12 ( V_9 ) -> V_15 >= 6 ) {
error -> error = F_16 ( V_319 ) ;
error -> V_320 = F_16 ( V_321 ) ;
}
if ( F_12 ( V_9 ) -> V_15 == 7 )
error -> V_322 = F_16 ( V_323 ) ;
F_89 ( V_9 , error -> V_324 ) ;
F_109 ( V_9 , error ) ;
F_133 ( V_9 , error ) ;
error -> V_238 = NULL ;
error -> V_325 = NULL ;
V_177 = 0 ;
F_38 (obj, &dev_priv->mm.active_list, mm_list)
V_177 ++ ;
error -> V_326 = V_177 ;
F_38 (obj, &dev_priv->mm.bound_list, gtt_list)
if ( V_81 -> V_251 )
V_177 ++ ;
error -> V_327 = V_177 - error -> V_326 ;
error -> V_238 = NULL ;
error -> V_325 = NULL ;
if ( V_177 ) {
error -> V_238 = F_92 ( sizeof( * error -> V_238 ) * V_177 ,
V_221 ) ;
if ( error -> V_238 )
error -> V_325 =
error -> V_238 + error -> V_326 ;
}
if ( error -> V_238 )
error -> V_326 =
F_107 ( error -> V_238 ,
error -> V_326 ,
& V_1 -> V_199 . V_328 ) ;
if ( error -> V_325 )
error -> V_327 =
F_108 ( error -> V_325 ,
error -> V_327 ,
& V_1 -> V_199 . V_329 ) ;
F_141 ( & error -> time ) ;
error -> V_239 = F_142 ( V_9 ) ;
error -> V_330 = F_143 ( V_9 ) ;
F_10 ( & V_1 -> V_300 , V_46 ) ;
if ( V_1 -> V_301 == NULL ) {
V_1 -> V_301 = error ;
error = NULL ;
}
F_13 ( & V_1 -> V_300 , V_46 ) ;
if ( error )
F_103 ( & error -> V_234 ) ;
}
void F_144 ( struct V_8 * V_9 )
{
struct V_47 * V_1 = V_9 -> V_10 ;
struct V_233 * error ;
unsigned long V_46 ;
F_10 ( & V_1 -> V_300 , V_46 ) ;
error = V_1 -> V_301 ;
V_1 -> V_301 = NULL ;
F_13 ( & V_1 -> V_300 , V_46 ) ;
if ( error )
F_145 ( & error -> V_234 , F_103 ) ;
}
static void F_146 ( struct V_8 * V_9 )
{
struct V_47 * V_1 = V_9 -> V_10 ;
T_4 V_202 [ V_203 ] ;
T_2 V_303 = F_16 ( V_304 ) ;
int V_5 , V_177 ;
if ( ! V_303 )
return;
F_147 ( L_35 , V_303 ) ;
F_89 ( V_9 , V_202 ) ;
if ( F_148 ( V_9 ) ) {
if ( V_303 & ( V_331 | V_332 ) ) {
T_2 V_280 = F_16 ( V_333 ) ;
F_147 ( L_36 , F_16 ( V_333 ) ) ;
F_147 ( L_37 , F_16 ( V_334 ) ) ;
for ( V_177 = 0 ; V_177 < F_105 ( V_202 ) ; V_177 ++ )
F_147 ( L_38 , V_177 , V_202 [ V_177 ] ) ;
F_147 ( L_39 , F_16 ( V_335 ) ) ;
F_147 ( L_40 , F_16 ( V_336 ) ) ;
F_2 ( V_333 , V_280 ) ;
F_3 ( V_333 ) ;
}
if ( V_303 & V_337 ) {
T_2 V_338 = F_16 ( V_306 ) ;
F_147 ( L_41 ) ;
F_147 ( L_42 , V_338 ) ;
F_2 ( V_306 , V_338 ) ;
F_3 ( V_306 ) ;
}
}
if ( ! F_139 ( V_9 ) ) {
if ( V_303 & V_339 ) {
T_2 V_338 = F_16 ( V_306 ) ;
F_147 ( L_41 ) ;
F_147 ( L_42 , V_338 ) ;
F_2 ( V_306 , V_338 ) ;
F_3 ( V_306 ) ;
}
}
if ( V_303 & V_340 ) {
F_147 ( L_43 ) ;
F_69 (pipe)
F_147 ( L_44 ,
F_20 ( V_5 ) , F_16 ( F_6 ( V_5 ) ) ) ;
}
if ( V_303 & V_341 ) {
F_147 ( L_45 ) ;
F_147 ( L_46 , F_16 ( V_342 ) ) ;
for ( V_177 = 0 ; V_177 < F_105 ( V_202 ) ; V_177 ++ )
F_147 ( L_38 , V_177 , V_202 [ V_177 ] ) ;
if ( F_12 ( V_9 ) -> V_15 < 4 ) {
T_2 V_280 = F_16 ( V_286 ) ;
F_147 ( L_36 , F_16 ( V_286 ) ) ;
F_147 ( L_37 , F_16 ( V_287 ) ) ;
F_147 ( L_40 , F_16 ( V_270 ) ) ;
F_2 ( V_286 , V_280 ) ;
F_3 ( V_286 ) ;
} else {
T_2 V_280 = F_16 ( V_333 ) ;
F_147 ( L_36 , F_16 ( V_333 ) ) ;
F_147 ( L_37 , F_16 ( V_334 ) ) ;
F_147 ( L_39 , F_16 ( V_335 ) ) ;
F_147 ( L_40 , F_16 ( V_336 ) ) ;
F_2 ( V_333 , V_280 ) ;
F_3 ( V_333 ) ;
}
}
F_2 ( V_304 , V_303 ) ;
F_3 ( V_304 ) ;
V_303 = F_16 ( V_304 ) ;
if ( V_303 ) {
F_31 ( L_47 , V_303 ) ;
F_2 ( V_343 , F_16 ( V_343 ) | V_303 ) ;
F_2 ( V_344 , V_345 ) ;
}
}
void F_65 ( struct V_8 * V_9 , bool V_200 )
{
struct V_47 * V_1 = V_9 -> V_10 ;
struct V_79 * V_80 ;
int V_177 ;
F_135 ( V_9 ) ;
F_146 ( V_9 ) ;
if ( V_200 ) {
F_149 ( V_1 -> V_201 ) ;
F_87 ( & V_1 -> V_199 . V_200 , 1 ) ;
F_134 (ring, dev_priv, i)
F_46 ( & V_80 -> V_83 ) ;
}
F_63 ( V_1 -> V_119 , & V_1 -> V_98 ) ;
}
static void F_150 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = V_9 -> V_10 ;
struct V_48 * V_49 = V_1 -> V_346 [ V_5 ] ;
struct V_347 * V_347 = F_151 ( V_49 ) ;
struct V_212 * V_81 ;
struct V_348 * V_55 ;
unsigned long V_46 ;
bool V_349 ;
if ( V_347 == NULL )
return;
F_10 ( & V_9 -> V_350 , V_46 ) ;
V_55 = V_347 -> V_351 ;
if ( V_55 == NULL ||
F_85 ( & V_55 -> V_352 ) >= V_353 ||
! V_55 -> V_354 ) {
F_13 ( & V_9 -> V_350 , V_46 ) ;
return;
}
V_81 = V_55 -> V_355 ;
if ( F_12 ( V_9 ) -> V_15 >= 4 ) {
int V_356 = F_152 ( V_347 -> V_357 ) ;
V_349 = F_153 ( F_16 ( V_356 ) ) ==
V_81 -> V_222 ;
} else {
int V_358 = F_154 ( V_347 -> V_357 ) ;
V_349 = F_16 ( V_358 ) == ( V_81 -> V_222 +
V_49 -> V_359 * V_49 -> V_360 -> V_361 [ 0 ] +
V_49 -> V_362 * V_49 -> V_360 -> V_363 / 8 ) ;
}
F_13 ( & V_9 -> V_350 , V_46 ) ;
if ( V_349 ) {
F_19 ( L_48 ) ;
F_71 ( V_9 , V_347 -> V_357 ) ;
}
}
static int F_155 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_51 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( F_12 ( V_9 ) -> V_15 >= 4 )
F_5 ( V_1 , V_5 ,
V_364 ) ;
else
F_5 ( V_1 , V_5 ,
V_365 ) ;
if ( V_1 -> V_366 -> V_15 == 3 )
F_2 ( V_342 , F_156 ( V_367 ) ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_157 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_51 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_1 ( V_1 , ( V_5 == 0 ) ?
V_190 : V_191 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_158 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_51 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_1 ( V_1 ,
V_182 << ( 5 * V_5 ) ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_159 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
T_2 V_368 ;
if ( ! F_14 ( V_9 , V_5 ) )
return - V_51 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
V_368 = F_16 ( V_369 ) ;
if ( V_5 == 0 )
V_368 &= ~ V_370 ;
else
V_368 &= ~ V_371 ;
F_2 ( V_369 , V_368 ) ;
F_5 ( V_1 , V_5 ,
V_364 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
return 0 ;
}
static void F_160 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_1 -> V_366 -> V_15 == 3 )
F_2 ( V_342 , F_161 ( V_367 ) ) ;
F_7 ( V_1 , V_5 ,
V_365 |
V_364 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static void F_162 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_4 ( V_1 , ( V_5 == 0 ) ?
V_190 : V_191 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static void F_163 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_4 ( V_1 ,
V_182 << ( V_5 * 5 ) ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static void F_164 ( struct V_8 * V_9 , int V_5 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
unsigned long V_11 ;
T_2 V_368 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
F_7 ( V_1 , V_5 ,
V_364 ) ;
V_368 = F_16 ( V_369 ) ;
if ( V_5 == 0 )
V_368 |= V_370 ;
else
V_368 |= V_371 ;
F_2 ( V_369 , V_368 ) ;
F_13 ( & V_1 -> V_12 , V_11 ) ;
}
static T_2
F_165 ( struct V_79 * V_80 )
{
return F_166 ( V_80 -> V_372 . V_373 ,
struct V_294 , V_374 ) -> V_268 ;
}
static bool F_167 ( struct V_79 * V_80 , bool * V_241 )
{
if ( F_168 ( & V_80 -> V_372 ) ||
F_117 ( V_80 -> V_82 ( V_80 , false ) ,
F_165 ( V_80 ) ) ) {
if ( F_127 ( & V_80 -> V_83 ) ) {
F_31 ( L_49 ,
V_80 -> V_242 ) ;
F_46 ( & V_80 -> V_83 ) ;
* V_241 = true ;
}
return true ;
}
return false ;
}
static bool F_169 ( struct V_79 * V_80 )
{
struct V_8 * V_9 = V_80 -> V_9 ;
struct V_47 * V_1 = V_9 -> V_10 ;
T_2 V_375 = F_132 ( V_80 ) ;
if ( V_375 & V_376 ) {
F_31 ( L_50 ,
V_80 -> V_242 ) ;
F_170 ( V_80 , V_375 ) ;
return true ;
}
return false ;
}
static bool F_171 ( struct V_8 * V_9 )
{
T_1 * V_1 = V_9 -> V_10 ;
if ( V_1 -> V_85 ++ > 1 ) {
bool V_377 = true ;
F_31 ( L_51 ) ;
F_65 ( V_9 , true ) ;
if ( ! F_139 ( V_9 ) ) {
struct V_79 * V_80 ;
int V_177 ;
F_134 (ring, dev_priv, i)
V_377 &= ! F_169 ( V_80 ) ;
}
return V_377 ;
}
return false ;
}
void F_172 ( unsigned long V_378 )
{
struct V_8 * V_9 = (struct V_8 * ) V_378 ;
T_1 * V_1 = V_9 -> V_10 ;
T_4 V_269 [ V_379 ] , V_202 [ V_203 ] ;
struct V_79 * V_80 ;
bool V_241 = false , V_380 ;
int V_177 ;
if ( ! V_84 )
return;
memset ( V_269 , 0 , sizeof( V_269 ) ) ;
V_380 = true ;
F_134 (ring, dev_priv, i) {
V_380 &= F_167 ( V_80 , & V_241 ) ;
V_269 [ V_177 ] = F_129 ( V_80 ) ;
}
if ( V_380 ) {
if ( V_241 ) {
if ( F_171 ( V_9 ) )
return;
goto V_381;
}
V_1 -> V_85 = 0 ;
return;
}
F_89 ( V_9 , V_202 ) ;
if ( memcmp ( V_1 -> V_382 , V_269 , sizeof( V_269 ) ) == 0 &&
memcmp ( V_1 -> V_383 , V_202 , sizeof( V_202 ) ) == 0 ) {
if ( F_171 ( V_9 ) )
return;
} else {
V_1 -> V_85 = 0 ;
memcpy ( V_1 -> V_382 , V_269 , sizeof( V_269 ) ) ;
memcpy ( V_1 -> V_383 , V_202 , sizeof( V_202 ) ) ;
}
V_381:
F_47 ( & V_1 -> V_86 ,
F_48 ( V_87 + V_88 ) ) ;
}
static void F_173 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
F_87 ( & V_1 -> V_138 , 0 ) ;
F_2 ( V_384 , 0xeffe ) ;
F_2 ( V_4 , 0xffffffff ) ;
F_2 ( V_178 , 0x0 ) ;
F_3 ( V_178 ) ;
F_2 ( V_113 , 0xffffffff ) ;
F_2 ( V_310 , 0x0 ) ;
F_3 ( V_310 ) ;
F_2 ( V_385 , 0xffffffff ) ;
F_2 ( V_386 , 0x0 ) ;
F_3 ( V_386 ) ;
}
static void F_174 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_87 ( & V_1 -> V_138 , 0 ) ;
F_2 ( V_369 , 0 ) ;
F_2 ( F_175 ( V_387 ) , 0 ) ;
F_2 ( F_175 ( V_388 ) , 0 ) ;
F_2 ( F_175 ( V_389 ) , 0 ) ;
F_2 ( V_140 , F_16 ( V_140 ) ) ;
F_2 ( V_140 , F_16 ( V_140 ) ) ;
F_2 ( V_113 , 0xffffffff ) ;
F_2 ( V_310 , 0x0 ) ;
F_3 ( V_310 ) ;
F_2 ( V_390 , 0xff ) ;
F_2 ( V_391 , 0 ) ;
F_2 ( V_149 , F_16 ( V_149 ) ) ;
F_69 (pipe)
F_2 ( F_6 ( V_5 ) , 0xffff ) ;
F_2 ( V_139 , 0xffffffff ) ;
F_2 ( V_369 , 0xffffffff ) ;
F_2 ( V_311 , 0x0 ) ;
F_3 ( V_311 ) ;
}
static void F_176 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_392 ;
V_392 = F_16 ( V_393 ) ;
V_392 &= ~ ( V_394 | V_395 | V_396 ) ;
V_392 |= V_397 | V_398 ;
V_392 |= V_399 | V_400 ;
V_392 |= V_401 | V_402 ;
F_2 ( V_393 , V_392 ) ;
}
static int F_177 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_403 = V_179 | V_13 | V_194 |
V_192 | V_193 ;
T_2 V_404 ;
T_2 V_405 ;
V_1 -> V_3 = ~ V_403 ;
F_2 ( V_180 , F_16 ( V_180 ) ) ;
F_2 ( V_4 , V_1 -> V_3 ) ;
F_2 ( V_178 , V_403 | V_190 | V_191 ) ;
F_3 ( V_178 ) ;
V_1 -> V_111 = ~ 0 ;
F_2 ( V_140 , F_16 ( V_140 ) ) ;
F_2 ( V_113 , V_1 -> V_111 ) ;
if ( F_81 ( V_9 ) )
V_404 =
V_186 |
V_124 |
V_126 ;
else
V_404 =
V_186 |
V_187 |
V_188 ;
F_2 ( V_310 , V_404 ) ;
F_3 ( V_310 ) ;
if ( F_83 ( V_9 ) ) {
V_405 = ( V_406 |
V_407 |
V_408 |
V_409 ) ;
} else {
V_405 = ( V_410 |
V_411 |
V_412 |
V_413 |
V_414 ) ;
}
V_1 -> V_415 = ~ V_405 ;
F_2 ( V_185 , F_16 ( V_185 ) ) ;
F_2 ( V_385 , V_1 -> V_415 ) ;
F_2 ( V_386 , V_405 ) ;
F_3 ( V_386 ) ;
F_176 ( V_9 ) ;
if ( F_178 ( V_9 ) ) {
F_2 ( V_180 , V_195 ) ;
F_2 ( V_178 , F_16 ( V_178 ) | V_195 ) ;
F_1 ( V_1 , V_195 ) ;
}
return 0 ;
}
static int F_179 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_403 =
V_179 | V_181 | V_184 |
V_416 |
V_417 |
V_183 ;
T_2 V_404 ;
T_2 V_405 ;
V_1 -> V_3 = ~ V_403 ;
F_2 ( V_180 , F_16 ( V_180 ) ) ;
F_2 ( V_4 , V_1 -> V_3 ) ;
F_2 ( V_178 ,
V_403 |
V_418 |
V_419 |
V_182 ) ;
F_3 ( V_178 ) ;
V_1 -> V_111 = ~ V_112 ;
F_2 ( V_140 , F_16 ( V_140 ) ) ;
F_2 ( V_113 , V_1 -> V_111 ) ;
V_404 = V_186 | V_124 |
V_126 | V_112 ;
F_2 ( V_310 , V_404 ) ;
F_3 ( V_310 ) ;
V_405 = ( V_406 |
V_407 |
V_408 |
V_409 ) ;
V_1 -> V_415 = ~ V_405 ;
F_2 ( V_185 , F_16 ( V_185 ) ) ;
F_2 ( V_385 , V_1 -> V_415 ) ;
F_2 ( V_386 , V_405 ) ;
F_3 ( V_386 ) ;
F_176 ( V_9 ) ;
return 0 ;
}
static int F_180 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_420 ;
T_2 V_421 = F_16 ( V_391 ) ;
T_2 V_422 = V_423 ;
T_2 V_404 ;
T_7 V_424 ;
V_420 = V_147 ;
V_420 |= V_425 |
V_370 |
V_426 |
V_371 ;
V_1 -> V_3 = ( ~ V_420 ) |
V_370 |
V_371 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
F_181 ( V_1 -> V_9 -> V_427 , 0x94 , 0xfee00000 ) ;
F_182 ( V_9 -> V_427 , 0x98 , & V_424 ) ;
V_424 &= 0xff ;
V_424 |= ( 1 << 14 ) ;
F_183 ( V_1 -> V_9 -> V_427 , 0x98 , V_424 ) ;
F_2 ( V_369 , V_1 -> V_3 ) ;
F_2 ( V_311 , V_420 ) ;
F_2 ( V_139 , 0xffffffff ) ;
F_2 ( F_6 ( 0 ) , 0xffff ) ;
F_2 ( F_6 ( 1 ) , 0xffff ) ;
F_3 ( V_311 ) ;
F_5 ( V_1 , 0 , V_422 ) ;
F_5 ( V_1 , 1 , V_422 ) ;
F_2 ( V_139 , 0xffffffff ) ;
F_2 ( V_139 , 0xffffffff ) ;
F_2 ( V_140 , F_16 ( V_140 ) ) ;
F_2 ( V_113 , V_1 -> V_111 ) ;
V_404 = V_186 | V_124 |
V_126 ;
F_2 ( V_310 , V_404 ) ;
F_3 ( V_310 ) ;
#if 0
I915_WRITE(DPINVGTT, DPINVGTT_STATUS_MASK);
I915_WRITE(DPINVGTT, DPINVGTT_EN_MASK);
#endif
F_2 ( V_428 , V_429 ) ;
if ( V_1 -> V_150 & V_430 )
V_421 |= V_431 ;
if ( V_1 -> V_150 & V_432 )
V_421 |= V_433 ;
if ( V_1 -> V_150 & V_434 )
V_421 |= V_435 ;
if ( V_1 -> V_150 & V_436 )
V_421 |= V_437 ;
if ( V_1 -> V_150 & V_438 )
V_421 |= V_439 ;
if ( V_1 -> V_150 & V_440 ) {
V_421 |= V_441 ;
V_421 |= V_442 ;
}
F_2 ( V_391 , V_421 ) ;
return 0 ;
}
static void F_184 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( ! V_1 )
return;
F_69 (pipe)
F_2 ( F_6 ( V_5 ) , 0xffff ) ;
F_2 ( V_384 , 0xffffffff ) ;
F_2 ( V_391 , 0 ) ;
F_2 ( V_149 , F_16 ( V_149 ) ) ;
F_69 (pipe)
F_2 ( F_6 ( V_5 ) , 0xffff ) ;
F_2 ( V_139 , 0xffffffff ) ;
F_2 ( V_369 , 0xffffffff ) ;
F_2 ( V_311 , 0x0 ) ;
F_3 ( V_311 ) ;
}
static void F_185 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
if ( ! V_1 )
return;
F_2 ( V_384 , 0xffffffff ) ;
F_2 ( V_4 , 0xffffffff ) ;
F_2 ( V_178 , 0x0 ) ;
F_2 ( V_180 , F_16 ( V_180 ) ) ;
F_2 ( V_113 , 0xffffffff ) ;
F_2 ( V_310 , 0x0 ) ;
F_2 ( V_140 , F_16 ( V_140 ) ) ;
F_2 ( V_385 , 0xffffffff ) ;
F_2 ( V_386 , 0x0 ) ;
F_2 ( V_185 , F_16 ( V_185 ) ) ;
}
static void F_186 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_87 ( & V_1 -> V_138 , 0 ) ;
F_69 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_42 ( V_443 , 0xffff ) ;
F_42 ( V_312 , 0x0 ) ;
F_187 ( V_312 ) ;
}
static int F_188 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
F_42 ( V_343 ,
~ ( V_339 | V_340 ) ) ;
V_1 -> V_3 =
~ ( V_425 |
V_426 |
V_444 |
V_445 |
V_345 ) ;
F_42 ( V_443 , V_1 -> V_3 ) ;
F_42 ( V_312 ,
V_425 |
V_426 |
V_345 |
V_446 ) ;
F_187 ( V_312 ) ;
return 0 ;
}
static T_5 F_189 ( int V_131 , void * V_132 )
{
struct V_8 * V_9 = (struct V_8 * ) V_132 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_7 V_133 , V_447 ;
T_2 V_135 [ 2 ] ;
unsigned long V_11 ;
int V_138 ;
int V_5 ;
T_7 V_448 =
V_444 |
V_445 ;
F_68 ( & V_1 -> V_138 ) ;
V_133 = F_140 ( V_344 ) ;
if ( V_133 == 0 )
return V_134 ;
while ( V_133 & ~ V_448 ) {
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_133 & V_345 )
F_65 ( V_9 , false ) ;
F_69 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_135 [ V_5 ] = F_16 ( V_7 ) ;
if ( V_135 [ V_5 ] & 0x8000ffff ) {
if ( V_135 [ V_5 ] & V_144 )
F_19 ( L_13 ,
F_20 ( V_5 ) ) ;
F_2 ( V_7 , V_135 [ V_5 ] ) ;
V_138 = 1 ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
F_42 ( V_344 , V_133 & ~ V_448 ) ;
V_447 = F_140 ( V_344 ) ;
F_190 ( V_9 ) ;
if ( V_133 & V_446 )
F_44 ( V_9 , & V_1 -> V_80 [ V_123 ] ) ;
if ( V_135 [ 0 ] & V_145 &&
F_70 ( V_9 , 0 ) ) {
if ( V_133 & V_444 ) {
F_71 ( V_9 , 0 ) ;
F_72 ( V_9 , 0 ) ;
V_448 &= ~ V_444 ;
}
}
if ( V_135 [ 1 ] & V_145 &&
F_70 ( V_9 , 1 ) ) {
if ( V_133 & V_445 ) {
F_71 ( V_9 , 1 ) ;
F_72 ( V_9 , 1 ) ;
V_448 &= ~ V_445 ;
}
}
V_133 = V_447 ;
}
return V_143 ;
}
static void F_191 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_69 (pipe) {
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( F_6 ( V_5 ) , F_16 ( F_6 ( V_5 ) ) ) ;
}
F_42 ( V_443 , 0xffff ) ;
F_42 ( V_312 , 0x0 ) ;
F_42 ( V_344 , F_140 ( V_344 ) ) ;
}
static void F_192 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_87 ( & V_1 -> V_138 , 0 ) ;
if ( F_193 ( V_9 ) ) {
F_2 ( V_391 , 0 ) ;
F_2 ( V_149 , F_16 ( V_149 ) ) ;
}
F_42 ( V_384 , 0xeffe ) ;
F_69 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( V_443 , 0xffffffff ) ;
F_2 ( V_312 , 0x0 ) ;
F_3 ( V_312 ) ;
}
static int F_194 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_420 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
F_2 ( V_343 , ~ ( V_339 | V_340 ) ) ;
V_1 -> V_3 =
~ ( V_449 |
V_425 |
V_426 |
V_444 |
V_445 |
V_345 ) ;
V_420 =
V_449 |
V_425 |
V_426 |
V_345 |
V_446 ;
if ( F_193 ( V_9 ) ) {
V_420 |= V_147 ;
V_1 -> V_3 &= ~ V_147 ;
}
F_2 ( V_443 , V_1 -> V_3 ) ;
F_2 ( V_312 , V_420 ) ;
F_3 ( V_312 ) ;
if ( F_193 ( V_9 ) ) {
T_2 V_421 = F_16 ( V_391 ) ;
if ( V_1 -> V_150 & V_430 )
V_421 |= V_431 ;
if ( V_1 -> V_150 & V_432 )
V_421 |= V_433 ;
if ( V_1 -> V_150 & V_434 )
V_421 |= V_435 ;
if ( V_1 -> V_150 & V_436 )
V_421 |= V_437 ;
if ( V_1 -> V_150 & V_438 )
V_421 |= V_439 ;
if ( V_1 -> V_150 & V_440 ) {
V_421 |= V_441 ;
V_421 |= V_442 ;
}
F_2 ( V_391 , V_421 ) ;
}
F_195 ( V_9 ) ;
return 0 ;
}
static T_5 F_196 ( int V_131 , void * V_132 )
{
struct V_8 * V_9 = (struct V_8 * ) V_132 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_133 , V_447 , V_135 [ V_136 ] ;
unsigned long V_11 ;
T_2 V_448 =
V_444 |
V_445 ;
T_2 V_450 [ 2 ] = {
V_444 ,
V_445
} ;
int V_5 , V_37 = V_134 ;
F_68 ( & V_1 -> V_138 ) ;
V_133 = F_16 ( V_344 ) ;
do {
bool V_138 = ( V_133 & ~ V_448 ) != 0 ;
bool V_137 = false ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_133 & V_345 )
F_65 ( V_9 , false ) ;
F_69 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_135 [ V_5 ] = F_16 ( V_7 ) ;
if ( V_135 [ V_5 ] & 0x8000ffff ) {
if ( V_135 [ V_5 ] & V_144 )
F_19 ( L_13 ,
F_20 ( V_5 ) ) ;
F_2 ( V_7 , V_135 [ V_5 ] ) ;
V_138 = true ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
if ( ! V_138 )
break;
if ( ( F_193 ( V_9 ) ) &&
( V_133 & V_147 ) ) {
T_2 V_148 = F_16 ( V_149 ) ;
F_19 ( L_14 ,
V_148 ) ;
if ( V_148 & V_1 -> V_150 )
F_63 ( V_1 -> V_119 ,
& V_1 -> V_56 ) ;
F_2 ( V_149 , V_148 ) ;
F_3 ( V_149 ) ;
}
F_2 ( V_344 , V_133 & ~ V_448 ) ;
V_447 = F_16 ( V_344 ) ;
if ( V_133 & V_446 )
F_44 ( V_9 , & V_1 -> V_80 [ V_123 ] ) ;
F_69 (pipe) {
int V_357 = V_5 ;
if ( F_197 ( V_9 ) )
V_357 = ! V_357 ;
if ( V_135 [ V_5 ] & V_145 &&
F_70 ( V_9 , V_5 ) ) {
if ( V_133 & V_450 [ V_357 ] ) {
F_71 ( V_9 , V_357 ) ;
F_72 ( V_9 , V_5 ) ;
V_448 &= ~ V_450 [ V_357 ] ;
}
}
if ( V_135 [ V_5 ] & V_151 )
V_137 = true ;
}
if ( V_137 || ( V_133 & V_449 ) )
F_198 ( V_9 ) ;
V_37 = V_143 ;
V_133 = V_447 ;
} while ( V_133 & ~ V_448 );
F_190 ( V_9 ) ;
return V_37 ;
}
static void F_199 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( F_193 ( V_9 ) ) {
F_2 ( V_391 , 0 ) ;
F_2 ( V_149 , F_16 ( V_149 ) ) ;
}
F_42 ( V_384 , 0xffff ) ;
F_69 (pipe) {
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( F_6 ( V_5 ) , F_16 ( F_6 ( V_5 ) ) ) ;
}
F_2 ( V_443 , 0xffffffff ) ;
F_2 ( V_312 , 0x0 ) ;
F_2 ( V_344 , F_16 ( V_344 ) ) ;
}
static void F_200 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
F_87 ( & V_1 -> V_138 , 0 ) ;
F_2 ( V_391 , 0 ) ;
F_2 ( V_149 , F_16 ( V_149 ) ) ;
F_2 ( V_384 , 0xeffe ) ;
F_69 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( V_443 , 0xffffffff ) ;
F_2 ( V_312 , 0x0 ) ;
F_3 ( V_312 ) ;
}
static int F_201 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_421 ;
T_2 V_420 ;
T_2 V_451 ;
V_1 -> V_3 = ~ ( V_449 |
V_147 |
V_425 |
V_426 |
V_444 |
V_445 |
V_345 ) ;
V_420 = ~ V_1 -> V_3 ;
V_420 |= V_446 ;
if ( F_148 ( V_9 ) )
V_420 |= V_452 ;
V_1 -> V_6 [ 0 ] = 0 ;
V_1 -> V_6 [ 1 ] = 0 ;
if ( F_148 ( V_9 ) ) {
V_451 = ~ ( V_337 |
V_331 |
V_332 |
V_340 ) ;
} else {
V_451 = ~ ( V_339 |
V_340 ) ;
}
F_2 ( V_343 , V_451 ) ;
F_2 ( V_443 , V_1 -> V_3 ) ;
F_2 ( V_312 , V_420 ) ;
F_3 ( V_312 ) ;
V_421 = 0 ;
if ( V_1 -> V_150 & V_430 )
V_421 |= V_431 ;
if ( V_1 -> V_150 & V_432 )
V_421 |= V_433 ;
if ( V_1 -> V_150 & V_434 )
V_421 |= V_435 ;
if ( F_148 ( V_9 ) ) {
if ( V_1 -> V_150 & V_453 )
V_421 |= V_437 ;
if ( V_1 -> V_150 & V_454 )
V_421 |= V_439 ;
} else {
if ( V_1 -> V_150 & V_455 )
V_421 |= V_437 ;
if ( V_1 -> V_150 & V_456 )
V_421 |= V_439 ;
}
if ( V_1 -> V_150 & V_440 ) {
V_421 |= V_441 ;
if ( F_148 ( V_9 ) )
V_421 |= V_457 ;
V_421 |= V_442 ;
}
F_2 ( V_391 , V_421 ) ;
F_195 ( V_9 ) ;
return 0 ;
}
static T_5 F_202 ( int V_131 , void * V_132 )
{
struct V_8 * V_9 = (struct V_8 * ) V_132 ;
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
T_2 V_133 , V_447 ;
T_2 V_135 [ V_136 ] ;
unsigned long V_11 ;
int V_138 ;
int V_37 = V_134 , V_5 ;
F_68 ( & V_1 -> V_138 ) ;
V_133 = F_16 ( V_344 ) ;
for (; ; ) {
bool V_137 = false ;
V_138 = V_133 != 0 ;
F_10 ( & V_1 -> V_12 , V_11 ) ;
if ( V_133 & V_345 )
F_65 ( V_9 , false ) ;
F_69 (pipe) {
int V_7 = F_6 ( V_5 ) ;
V_135 [ V_5 ] = F_16 ( V_7 ) ;
if ( V_135 [ V_5 ] & 0x8000ffff ) {
if ( V_135 [ V_5 ] & V_144 )
F_19 ( L_13 ,
F_20 ( V_5 ) ) ;
F_2 ( V_7 , V_135 [ V_5 ] ) ;
V_138 = 1 ;
}
}
F_13 ( & V_1 -> V_12 , V_11 ) ;
if ( ! V_138 )
break;
V_37 = V_143 ;
if ( V_133 & V_147 ) {
T_2 V_148 = F_16 ( V_149 ) ;
F_19 ( L_14 ,
V_148 ) ;
if ( V_148 & V_1 -> V_150 )
F_63 ( V_1 -> V_119 ,
& V_1 -> V_56 ) ;
F_2 ( V_149 , V_148 ) ;
F_16 ( V_149 ) ;
}
F_2 ( V_344 , V_133 ) ;
V_447 = F_16 ( V_344 ) ;
if ( V_133 & V_446 )
F_44 ( V_9 , & V_1 -> V_80 [ V_123 ] ) ;
if ( V_133 & V_452 )
F_44 ( V_9 , & V_1 -> V_80 [ V_125 ] ) ;
if ( V_133 & V_444 )
F_71 ( V_9 , 0 ) ;
if ( V_133 & V_445 )
F_71 ( V_9 , 1 ) ;
F_69 (pipe) {
if ( V_135 [ V_5 ] & V_458 &&
F_70 ( V_9 , V_5 ) ) {
F_150 ( V_9 , V_5 ) ;
F_72 ( V_9 , V_5 ) ;
}
if ( V_135 [ V_5 ] & V_151 )
V_137 = true ;
}
if ( V_137 || ( V_133 & V_449 ) )
F_198 ( V_9 ) ;
V_133 = V_447 ;
}
F_190 ( V_9 ) ;
return V_37 ;
}
static void F_203 ( struct V_8 * V_9 )
{
T_1 * V_1 = ( T_1 * ) V_9 -> V_10 ;
int V_5 ;
if ( ! V_1 )
return;
F_2 ( V_391 , 0 ) ;
F_2 ( V_149 , F_16 ( V_149 ) ) ;
F_2 ( V_384 , 0xffffffff ) ;
F_69 (pipe)
F_2 ( F_6 ( V_5 ) , 0 ) ;
F_2 ( V_443 , 0xffffffff ) ;
F_2 ( V_312 , 0x0 ) ;
F_69 (pipe)
F_2 ( F_6 ( V_5 ) ,
F_16 ( F_6 ( V_5 ) ) & 0x8000ffff ) ;
F_2 ( V_344 , F_16 ( V_344 ) ) ;
}
void F_204 ( struct V_8 * V_9 )
{
struct V_47 * V_1 = V_9 -> V_10 ;
F_205 ( & V_1 -> V_56 , F_35 ) ;
F_205 ( & V_1 -> V_98 , F_84 ) ;
F_205 ( & V_1 -> V_89 . V_55 , F_49 ) ;
F_205 ( & V_1 -> V_97 . V_98 , F_53 ) ;
V_9 -> V_459 -> V_460 = F_18 ;
V_9 -> V_461 = 0xffffff ;
if ( F_148 ( V_9 ) || F_12 ( V_9 ) -> V_15 >= 5 ) {
V_9 -> V_461 = 0xffffffff ;
V_9 -> V_459 -> V_460 = F_23 ;
}
if ( F_206 ( V_9 , V_462 ) )
V_9 -> V_459 -> V_463 = F_30 ;
else
V_9 -> V_459 -> V_463 = NULL ;
V_9 -> V_459 -> V_464 = F_25 ;
if ( F_9 ( V_9 ) ) {
V_9 -> V_459 -> V_465 = F_67 ;
V_9 -> V_459 -> V_466 = F_174 ;
V_9 -> V_459 -> V_467 = F_180 ;
V_9 -> V_459 -> V_468 = F_184 ;
V_9 -> V_459 -> V_469 = F_159 ;
V_9 -> V_459 -> V_470 = F_164 ;
} else if ( F_207 ( V_9 ) ) {
V_9 -> V_459 -> V_465 = F_76 ;
V_9 -> V_459 -> V_466 = F_173 ;
V_9 -> V_459 -> V_467 = F_179 ;
V_9 -> V_459 -> V_468 = F_185 ;
V_9 -> V_459 -> V_469 = F_158 ;
V_9 -> V_459 -> V_470 = F_163 ;
} else if ( F_208 ( V_9 ) ) {
V_9 -> V_459 -> V_465 = F_76 ;
V_9 -> V_459 -> V_466 = F_173 ;
V_9 -> V_459 -> V_467 = F_179 ;
V_9 -> V_459 -> V_468 = F_185 ;
V_9 -> V_459 -> V_469 = F_158 ;
V_9 -> V_459 -> V_470 = F_163 ;
} else if ( F_11 ( V_9 ) ) {
V_9 -> V_459 -> V_465 = F_80 ;
V_9 -> V_459 -> V_466 = F_173 ;
V_9 -> V_459 -> V_467 = F_177 ;
V_9 -> V_459 -> V_468 = F_185 ;
V_9 -> V_459 -> V_469 = F_157 ;
V_9 -> V_459 -> V_470 = F_162 ;
} else {
if ( F_12 ( V_9 ) -> V_15 == 2 ) {
V_9 -> V_459 -> V_466 = F_186 ;
V_9 -> V_459 -> V_467 = F_188 ;
V_9 -> V_459 -> V_465 = F_189 ;
V_9 -> V_459 -> V_468 = F_191 ;
} else if ( F_12 ( V_9 ) -> V_15 == 3 ) {
V_9 -> V_459 -> V_466 = F_192 ;
V_9 -> V_459 -> V_467 = F_194 ;
V_9 -> V_459 -> V_468 = F_199 ;
V_9 -> V_459 -> V_465 = F_196 ;
} else {
V_9 -> V_459 -> V_466 = F_200 ;
V_9 -> V_459 -> V_467 = F_201 ;
V_9 -> V_459 -> V_468 = F_203 ;
V_9 -> V_459 -> V_465 = F_202 ;
}
V_9 -> V_459 -> V_469 = F_155 ;
V_9 -> V_459 -> V_470 = F_160 ;
}
}
