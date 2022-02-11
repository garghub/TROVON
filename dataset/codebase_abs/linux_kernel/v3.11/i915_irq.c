static void
F_1 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( & V_1 -> V_3 ) ;
if ( ( V_1 -> V_4 & V_2 ) != 0 ) {
V_1 -> V_4 &= ~ V_2 ;
F_3 ( V_5 , V_1 -> V_4 ) ;
F_4 ( V_5 ) ;
}
}
static void
F_5 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( & V_1 -> V_3 ) ;
if ( ( V_1 -> V_4 & V_2 ) != V_2 ) {
V_1 -> V_4 |= V_2 ;
F_3 ( V_5 , V_1 -> V_4 ) ;
F_4 ( V_5 ) ;
}
}
static bool F_6 ( struct V_6 * V_7 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
struct V_10 * V_11 ;
enum V_12 V_12 ;
F_2 ( & V_1 -> V_3 ) ;
F_7 (pipe) {
V_11 = F_8 ( V_1 -> V_13 [ V_12 ] ) ;
if ( V_11 -> V_14 )
return false ;
}
return true ;
}
static bool F_9 ( struct V_6 * V_7 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
enum V_12 V_12 ;
struct V_10 * V_11 ;
F_7 (pipe) {
V_11 = F_8 ( V_1 -> V_13 [ V_12 ] ) ;
if ( V_11 -> V_15 )
return false ;
}
return true ;
}
static void F_10 ( struct V_6 * V_7 ,
enum V_12 V_12 , bool V_16 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
T_3 V_17 = ( V_12 == V_18 ) ? V_19 :
V_20 ;
if ( V_16 )
F_1 ( V_1 , V_17 ) ;
else
F_5 ( V_1 , V_17 ) ;
}
static void F_11 ( struct V_6 * V_7 ,
bool V_16 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
if ( V_16 ) {
if ( ! F_6 ( V_7 ) )
return;
F_3 ( V_21 , V_22 |
V_23 |
V_24 ) ;
F_1 ( V_1 , V_25 ) ;
} else {
F_5 ( V_1 , V_25 ) ;
}
}
static void F_12 ( struct V_10 * V_11 ,
bool V_16 )
{
struct V_6 * V_7 = V_11 -> V_26 . V_7 ;
struct V_8 * V_1 = V_7 -> V_9 ;
T_3 V_17 = ( V_11 -> V_12 == V_18 ) ? V_27 :
V_28 ;
if ( V_16 )
F_3 ( V_29 , F_13 ( V_29 ) & ~ V_17 ) ;
else
F_3 ( V_29 , F_13 ( V_29 ) | V_17 ) ;
F_4 ( V_29 ) ;
}
static void F_14 ( struct V_6 * V_7 ,
enum V_30 V_31 ,
bool V_16 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
if ( V_16 ) {
if ( ! F_9 ( V_7 ) )
return;
F_3 ( V_32 , V_33 |
V_34 |
V_35 ) ;
F_3 ( V_29 , F_13 ( V_29 ) & ~ V_36 ) ;
} else {
F_3 ( V_29 , F_13 ( V_29 ) | V_36 ) ;
}
F_4 ( V_29 ) ;
}
bool F_15 ( struct V_6 * V_7 ,
enum V_12 V_12 , bool V_16 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
struct V_37 * V_11 = V_1 -> V_13 [ V_12 ] ;
struct V_10 * V_10 = F_8 ( V_11 ) ;
unsigned long V_38 ;
bool V_39 ;
F_16 ( & V_1 -> V_3 , V_38 ) ;
V_39 = ! V_10 -> V_14 ;
if ( V_16 == V_39 )
goto V_40;
V_10 -> V_14 = ! V_16 ;
if ( F_17 ( V_7 ) || F_18 ( V_7 ) )
F_10 ( V_7 , V_12 , V_16 ) ;
else if ( F_19 ( V_7 ) )
F_11 ( V_7 , V_16 ) ;
V_40:
F_20 ( & V_1 -> V_3 , V_38 ) ;
return V_39 ;
}
bool F_21 ( struct V_6 * V_7 ,
enum V_30 V_31 ,
bool V_16 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
enum V_12 V_41 ;
struct V_37 * V_11 ;
struct V_10 * V_10 ;
unsigned long V_38 ;
bool V_39 ;
if ( F_22 ( V_7 ) ) {
V_11 = NULL ;
F_7 (p) {
struct V_37 * V_42 = V_1 -> V_13 [ V_41 ] ;
if ( F_23 ( V_42 , V_43 ) ) {
V_11 = V_42 ;
break;
}
}
if ( ! V_11 ) {
F_24 ( L_1 ) ;
return false ;
}
} else {
V_11 = V_1 -> V_13 [ V_31 ] ;
}
V_10 = F_8 ( V_11 ) ;
F_16 ( & V_1 -> V_3 , V_38 ) ;
V_39 = ! V_10 -> V_15 ;
if ( V_16 == V_39 )
goto V_40;
V_10 -> V_15 = ! V_16 ;
if ( F_25 ( V_7 ) )
F_12 ( V_10 , V_16 ) ;
else
F_14 ( V_7 , V_31 , V_16 ) ;
V_40:
F_20 ( & V_1 -> V_3 , V_38 ) ;
return V_39 ;
}
void
F_26 ( T_1 * V_1 , int V_12 , T_2 V_2 )
{
T_2 V_44 = F_27 ( V_12 ) ;
T_2 V_45 = F_13 ( V_44 ) & 0x7fff0000 ;
if ( ( V_45 & V_2 ) == V_2 )
return;
V_45 |= V_2 | ( V_2 >> 16 ) ;
F_3 ( V_44 , V_45 ) ;
F_4 ( V_44 ) ;
}
void
F_28 ( T_1 * V_1 , int V_12 , T_2 V_2 )
{
T_2 V_44 = F_27 ( V_12 ) ;
T_2 V_45 = F_13 ( V_44 ) & 0x7fff0000 ;
if ( ( V_45 & V_2 ) == 0 )
return;
V_45 &= ~ V_2 ;
F_3 ( V_44 , V_45 ) ;
F_4 ( V_44 ) ;
}
static void F_29 ( struct V_6 * V_7 )
{
T_1 * V_1 = V_7 -> V_9 ;
unsigned long V_46 ;
if ( ! V_1 -> V_47 . V_48 || ! F_30 ( V_7 ) )
return;
F_16 ( & V_1 -> V_3 , V_46 ) ;
F_26 ( V_1 , 1 , V_49 ) ;
if ( F_31 ( V_7 ) -> V_50 >= 4 )
F_26 ( V_1 , 0 , V_49 ) ;
F_20 ( & V_1 -> V_3 , V_46 ) ;
}
static int
F_32 ( struct V_6 * V_7 , int V_12 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
if ( F_33 ( V_7 , V_51 ) ) {
struct V_37 * V_11 = V_1 -> V_13 [ V_12 ] ;
struct V_10 * V_10 = F_8 ( V_11 ) ;
return V_10 -> V_52 ;
} else {
return F_13 ( F_34 ( V_12 ) ) & V_53 ;
}
}
static T_2 F_35 ( struct V_6 * V_7 , int V_12 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
unsigned long V_54 ;
unsigned long V_55 ;
T_2 V_56 , V_57 , V_58 ;
if ( ! F_32 ( V_7 , V_12 ) ) {
F_36 ( L_2
L_3 , F_37 ( V_12 ) ) ;
return 0 ;
}
V_54 = F_38 ( V_12 ) ;
V_55 = F_39 ( V_12 ) ;
do {
V_56 = F_13 ( V_54 ) & V_59 ;
V_58 = F_13 ( V_55 ) & V_60 ;
V_57 = F_13 ( V_54 ) & V_59 ;
} while ( V_56 != V_57 );
V_56 >>= V_61 ;
V_58 >>= V_62 ;
return ( V_56 << 8 ) | V_58 ;
}
static T_2 F_40 ( struct V_6 * V_7 , int V_12 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
int V_44 = F_41 ( V_12 ) ;
if ( ! F_32 ( V_7 , V_12 ) ) {
F_36 ( L_2
L_3 , F_37 ( V_12 ) ) ;
return 0 ;
}
return F_13 ( V_44 ) ;
}
static int F_42 ( struct V_6 * V_7 , int V_12 ,
int * V_63 , int * V_64 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
T_2 V_65 = 0 , V_66 = 0 ;
int V_67 , V_68 , V_69 , V_70 ;
bool V_71 = true ;
int V_39 = 0 ;
enum V_30 V_72 = F_43 ( V_1 ,
V_12 ) ;
if ( ! F_32 ( V_7 , V_12 ) ) {
F_36 ( L_4
L_3 , F_37 ( V_12 ) ) ;
return 0 ;
}
V_70 = 1 + ( ( F_13 ( F_44 ( V_72 ) ) >> 16 ) & 0x1fff ) ;
if ( F_31 ( V_7 ) -> V_50 >= 4 ) {
V_66 = F_13 ( F_45 ( V_12 ) ) ;
* V_63 = V_66 & 0x1fff ;
* V_64 = 0 ;
} else {
V_66 = ( F_13 ( F_39 ( V_12 ) ) & V_73 ) >> V_74 ;
V_69 = 1 + ( ( F_13 ( F_46 ( V_72 ) ) >> 16 ) & 0x1fff ) ;
* V_63 = V_66 / V_69 ;
* V_64 = V_66 - ( * V_63 * V_69 ) ;
}
V_65 = F_13 ( F_47 ( V_72 ) ) ;
V_67 = V_65 & 0x1fff ;
V_68 = ( V_65 >> 16 ) & 0x1fff ;
if ( ( * V_63 < V_67 ) || ( * V_63 > V_68 ) )
V_71 = false ;
if ( V_71 && ( * V_63 >= V_67 ) )
* V_63 = * V_63 - V_70 ;
if ( V_65 > 0 )
V_39 |= V_75 | V_76 ;
if ( V_71 )
V_39 |= V_77 ;
return V_39 ;
}
static int F_48 ( struct V_6 * V_7 , int V_12 ,
int * V_78 ,
struct V_79 * V_80 ,
unsigned V_38 )
{
struct V_37 * V_11 ;
if ( V_12 < 0 || V_12 >= F_31 ( V_7 ) -> V_81 ) {
F_24 ( L_5 , V_12 ) ;
return - V_82 ;
}
V_11 = F_49 ( V_7 , V_12 ) ;
if ( V_11 == NULL ) {
F_24 ( L_5 , V_12 ) ;
return - V_82 ;
}
if ( ! V_11 -> V_83 ) {
F_50 ( L_6 , V_12 ) ;
return - V_84 ;
}
return F_51 ( V_7 , V_12 , V_78 ,
V_80 , V_38 ,
V_11 ) ;
}
static int F_52 ( struct V_6 * V_7 , struct V_85 * V_86 )
{
enum V_87 V_88 ;
F_53 ( ! F_54 ( & V_7 -> V_89 . V_90 ) ) ;
V_88 = V_86 -> V_91 ;
V_86 -> V_91 = V_86 -> V_92 -> V_93 ( V_86 , false ) ;
F_50 ( L_7 ,
V_86 -> V_26 . V_94 ,
F_55 ( V_86 ) ,
V_88 , V_86 -> V_91 ) ;
return ( V_88 != V_86 -> V_91 ) ;
}
static void F_56 ( struct V_95 * V_96 )
{
T_1 * V_1 = F_57 ( V_96 , T_1 ,
V_97 ) ;
struct V_6 * V_7 = V_1 -> V_7 ;
struct V_98 * V_89 = & V_7 -> V_89 ;
struct V_99 * V_99 ;
struct V_100 * V_100 ;
struct V_85 * V_86 ;
unsigned long V_46 ;
bool V_101 = false ;
bool V_102 = false ;
T_2 V_103 ;
if ( ! V_1 -> V_104 )
return;
F_58 ( & V_89 -> V_90 ) ;
F_50 ( L_8 ) ;
F_16 ( & V_1 -> V_3 , V_46 ) ;
V_103 = V_1 -> V_103 ;
V_1 -> V_103 = 0 ;
F_59 (connector, &mode_config->connector_list, head) {
V_99 = F_60 ( V_86 ) ;
V_100 = V_99 -> V_105 ;
if ( V_100 -> V_106 > V_107 &&
V_1 -> V_108 [ V_100 -> V_106 ] . V_109 == V_110 &&
V_86 -> V_111 == V_112 ) {
F_61 ( L_9
L_10 ,
F_55 ( V_86 ) ) ;
V_1 -> V_108 [ V_100 -> V_106 ] . V_109 = V_113 ;
V_86 -> V_111 = V_114
| V_115 ;
V_101 = true ;
}
if ( V_103 & ( 1 << V_100 -> V_106 ) ) {
F_50 ( L_11 ,
F_55 ( V_86 ) , V_100 -> V_106 ) ;
}
}
if ( V_101 ) {
F_62 ( V_7 ) ;
F_63 ( & V_1 -> V_116 ,
V_117 + F_64 ( V_118 ) ) ;
}
F_20 ( & V_1 -> V_3 , V_46 ) ;
F_59 (connector, &mode_config->connector_list, head) {
V_99 = F_60 ( V_86 ) ;
V_100 = V_99 -> V_105 ;
if ( V_103 & ( 1 << V_100 -> V_106 ) ) {
if ( V_100 -> V_119 )
V_100 -> V_119 ( V_100 ) ;
if ( F_52 ( V_7 , V_86 ) )
V_102 = true ;
}
}
F_65 ( & V_89 -> V_90 ) ;
if ( V_102 )
F_66 ( V_7 ) ;
}
static void F_67 ( struct V_6 * V_7 )
{
T_1 * V_1 = V_7 -> V_9 ;
T_2 V_120 , V_121 , V_122 , V_123 ;
T_4 V_124 ;
unsigned long V_38 ;
F_16 ( & V_125 , V_38 ) ;
F_68 ( V_126 , F_13 ( V_126 ) ) ;
V_124 = V_1 -> V_127 . V_128 ;
F_68 ( V_126 , V_129 ) ;
V_120 = F_13 ( V_130 ) ;
V_121 = F_13 ( V_131 ) ;
V_122 = F_13 ( V_132 ) ;
V_123 = F_13 ( V_133 ) ;
if ( V_120 > V_122 ) {
if ( V_1 -> V_127 . V_128 != V_1 -> V_127 . V_134 )
V_124 = V_1 -> V_127 . V_128 - 1 ;
if ( V_124 < V_1 -> V_127 . V_134 )
V_124 = V_1 -> V_127 . V_134 ;
} else if ( V_121 < V_123 ) {
if ( V_1 -> V_127 . V_128 != V_1 -> V_127 . V_135 )
V_124 = V_1 -> V_127 . V_128 + 1 ;
if ( V_124 > V_1 -> V_127 . V_135 )
V_124 = V_1 -> V_127 . V_135 ;
}
if ( F_69 ( V_7 , V_124 ) )
V_1 -> V_127 . V_128 = V_124 ;
F_20 ( & V_125 , V_38 ) ;
return;
}
static void F_70 ( struct V_6 * V_7 ,
struct V_136 * V_137 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
if ( V_137 -> V_138 == NULL )
return;
F_71 ( V_137 , V_137 -> V_139 ( V_137 , false ) ) ;
F_72 ( & V_137 -> V_140 ) ;
if ( V_141 ) {
F_63 ( & V_1 -> V_142 . V_143 ,
F_73 ( V_117 + V_144 ) ) ;
}
}
static void F_74 ( struct V_95 * V_96 )
{
T_1 * V_1 = F_57 ( V_96 , T_1 ,
V_145 . V_96 ) ;
T_2 V_146 , V_147 ;
T_4 V_124 ;
F_75 ( & V_1 -> V_145 . V_148 ) ;
V_146 = V_1 -> V_145 . V_146 ;
V_1 -> V_145 . V_146 = 0 ;
V_147 = F_13 ( V_149 ) ;
F_3 ( V_149 , V_147 & ~ V_150 ) ;
F_76 ( & V_1 -> V_145 . V_148 ) ;
if ( ( V_146 & V_150 ) == 0 )
return;
F_58 ( & V_1 -> V_145 . V_151 ) ;
if ( V_146 & V_152 ) {
V_124 = V_1 -> V_145 . V_128 + 1 ;
if ( F_77 ( V_1 -> V_7 ) &&
V_1 -> V_145 . V_128 < V_1 -> V_145 . V_153 )
V_124 = V_1 -> V_145 . V_153 ;
} else
V_124 = V_1 -> V_145 . V_128 - 1 ;
if ( V_124 >= V_1 -> V_145 . V_135 &&
V_124 <= V_1 -> V_145 . V_134 ) {
if ( F_77 ( V_1 -> V_7 ) )
F_78 ( V_1 -> V_7 , V_124 ) ;
else
F_79 ( V_1 -> V_7 , V_124 ) ;
}
if ( F_77 ( V_1 -> V_7 ) ) {
F_80 ( V_1 -> V_154 , & V_1 -> V_145 . V_155 ,
F_64 ( 100 ) ) ;
}
F_65 ( & V_1 -> V_145 . V_151 ) ;
}
static void F_81 ( struct V_95 * V_96 )
{
T_1 * V_1 = F_57 ( V_96 , T_1 ,
V_156 . V_157 ) ;
T_2 V_158 , V_159 , V_160 , V_161 ;
char * V_162 [ 5 ] ;
T_3 V_163 ;
unsigned long V_38 ;
F_58 ( & V_1 -> V_7 -> V_164 ) ;
V_163 = F_13 ( V_165 ) ;
F_3 ( V_165 , V_163 & ~ V_166 ) ;
F_4 ( V_165 ) ;
V_158 = F_13 ( V_167 ) ;
V_159 = F_82 ( V_158 ) ;
V_160 = F_83 ( V_158 ) ;
V_161 = F_84 ( V_158 ) ;
F_3 ( V_167 , V_168 |
V_169 ) ;
F_4 ( V_167 ) ;
F_3 ( V_165 , V_163 ) ;
F_16 ( & V_1 -> V_3 , V_38 ) ;
V_1 -> V_170 &= ~ V_171 ;
F_3 ( V_172 , V_1 -> V_170 ) ;
F_20 ( & V_1 -> V_3 , V_38 ) ;
F_65 ( & V_1 -> V_7 -> V_164 ) ;
V_162 [ 0 ] = L_12 ;
V_162 [ 1 ] = F_85 ( V_173 , L_13 , V_159 ) ;
V_162 [ 2 ] = F_85 ( V_173 , L_14 , V_160 ) ;
V_162 [ 3 ] = F_85 ( V_173 , L_15 , V_161 ) ;
V_162 [ 4 ] = NULL ;
F_86 ( & V_1 -> V_7 -> V_174 -> V_175 . V_176 ,
V_177 , V_162 ) ;
F_87 ( L_16 ,
V_159 , V_160 , V_161 ) ;
F_88 ( V_162 [ 3 ] ) ;
F_88 ( V_162 [ 2 ] ) ;
F_88 ( V_162 [ 1 ] ) ;
}
static void F_89 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
unsigned long V_38 ;
if ( ! F_90 ( V_7 ) )
return;
F_16 ( & V_1 -> V_3 , V_38 ) ;
V_1 -> V_170 |= V_171 ;
F_3 ( V_172 , V_1 -> V_170 ) ;
F_20 ( & V_1 -> V_3 , V_38 ) ;
F_91 ( V_1 -> V_154 , & V_1 -> V_156 . V_157 ) ;
}
static void F_92 ( struct V_6 * V_7 ,
struct V_8 * V_1 ,
T_2 V_178 )
{
if ( V_178 &
( V_179 | V_180 ) )
F_70 ( V_7 , & V_1 -> V_137 [ V_181 ] ) ;
if ( V_178 & V_182 )
F_70 ( V_7 , & V_1 -> V_137 [ V_183 ] ) ;
if ( V_178 & V_184 )
F_70 ( V_7 , & V_1 -> V_137 [ V_185 ] ) ;
if ( V_178 & ( V_186 |
V_187 |
V_188 ) ) {
F_24 ( L_17 , V_178 ) ;
F_93 ( V_7 , false ) ;
}
if ( V_178 & V_171 )
F_89 ( V_7 ) ;
}
static void F_94 ( struct V_8 * V_1 ,
T_2 V_146 )
{
unsigned long V_38 ;
F_16 ( & V_1 -> V_145 . V_148 , V_38 ) ;
V_1 -> V_145 . V_146 |= V_146 ;
F_3 ( V_149 , V_1 -> V_145 . V_146 ) ;
F_4 ( V_149 ) ;
F_20 ( & V_1 -> V_145 . V_148 , V_38 ) ;
F_91 ( V_1 -> V_154 , & V_1 -> V_145 . V_96 ) ;
}
static inline void F_95 ( struct V_6 * V_7 ,
T_2 V_189 ,
const T_2 * V_190 )
{
T_1 * V_1 = V_7 -> V_9 ;
int V_191 ;
bool V_192 = false ;
if ( ! V_189 )
return;
F_96 ( & V_1 -> V_3 ) ;
for ( V_191 = 1 ; V_191 < V_193 ; V_191 ++ ) {
if ( ! ( V_190 [ V_191 ] & V_189 ) ||
V_1 -> V_108 [ V_191 ] . V_109 != V_194 )
continue;
V_1 -> V_103 |= ( 1 << V_191 ) ;
if ( ! F_97 ( V_117 , V_1 -> V_108 [ V_191 ] . V_195 ,
V_1 -> V_108 [ V_191 ] . V_195
+ F_64 ( V_196 ) ) ) {
V_1 -> V_108 [ V_191 ] . V_195 = V_117 ;
V_1 -> V_108 [ V_191 ] . V_197 = 0 ;
} else if ( V_1 -> V_108 [ V_191 ] . V_197 > V_198 ) {
V_1 -> V_108 [ V_191 ] . V_109 = V_110 ;
V_1 -> V_103 &= ~ ( 1 << V_191 ) ;
F_50 ( L_18 , V_191 ) ;
V_192 = true ;
} else {
V_1 -> V_108 [ V_191 ] . V_197 ++ ;
}
}
if ( V_192 )
V_1 -> V_199 . V_200 ( V_7 ) ;
F_98 ( & V_1 -> V_3 ) ;
F_91 ( V_1 -> V_154 ,
& V_1 -> V_97 ) ;
}
static void F_99 ( struct V_6 * V_7 )
{
struct V_8 * V_1 = ( T_1 * ) V_7 -> V_9 ;
F_72 ( & V_1 -> V_201 ) ;
}
static void F_100 ( struct V_6 * V_7 )
{
struct V_8 * V_1 = ( T_1 * ) V_7 -> V_9 ;
F_72 ( & V_1 -> V_201 ) ;
}
static void F_101 ( struct V_8 * V_1 ,
T_2 V_146 )
{
unsigned long V_38 ;
F_16 ( & V_1 -> V_145 . V_148 , V_38 ) ;
V_1 -> V_145 . V_146 |= V_146 & V_150 ;
if ( V_1 -> V_145 . V_146 ) {
F_3 ( V_149 , V_1 -> V_145 . V_146 ) ;
F_53 ( F_102 ( V_149 ) & ~ V_150 ) ;
F_91 ( V_1 -> V_154 , & V_1 -> V_145 . V_96 ) ;
}
F_20 ( & V_1 -> V_145 . V_148 , V_38 ) ;
if ( V_146 & ~ V_150 ) {
if ( V_146 & V_202 )
F_70 ( V_1 -> V_7 , & V_1 -> V_137 [ V_203 ] ) ;
if ( V_146 & V_204 ) {
F_24 ( L_19 , V_146 ) ;
F_93 ( V_1 -> V_7 , false ) ;
}
}
}
static T_5 F_103 ( int V_205 , void * V_206 )
{
struct V_6 * V_7 = (struct V_6 * ) V_206 ;
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
T_2 V_207 , V_178 , V_146 ;
T_5 V_39 = V_208 ;
unsigned long V_46 ;
int V_12 ;
T_2 V_209 [ V_210 ] ;
F_104 ( & V_1 -> V_211 ) ;
while ( true ) {
V_207 = F_13 ( V_212 ) ;
V_178 = F_13 ( V_213 ) ;
V_146 = F_13 ( V_214 ) ;
if ( V_178 == 0 && V_146 == 0 && V_207 == 0 )
goto V_215;
V_39 = V_216 ;
F_92 ( V_7 , V_1 , V_178 ) ;
F_16 ( & V_1 -> V_3 , V_46 ) ;
F_7 (pipe) {
int V_44 = F_27 ( V_12 ) ;
V_209 [ V_12 ] = F_13 ( V_44 ) ;
if ( V_209 [ V_12 ] & 0x8000ffff ) {
if ( V_209 [ V_12 ] & V_217 )
F_36 ( L_20 ,
F_37 ( V_12 ) ) ;
F_3 ( V_44 , V_209 [ V_12 ] ) ;
}
}
F_20 ( & V_1 -> V_3 , V_46 ) ;
F_7 (pipe) {
if ( V_209 [ V_12 ] & V_218 )
F_105 ( V_7 , V_12 ) ;
if ( V_209 [ V_12 ] & V_219 ) {
F_106 ( V_7 , V_12 ) ;
F_107 ( V_7 , V_12 ) ;
}
}
if ( V_207 & V_220 ) {
T_2 V_221 = F_13 ( V_222 ) ;
T_2 V_189 = V_221 & V_223 ;
F_36 ( L_21 ,
V_221 ) ;
F_95 ( V_7 , V_189 , V_224 ) ;
F_3 ( V_222 , V_221 ) ;
F_13 ( V_222 ) ;
}
if ( V_209 [ 0 ] & V_225 )
F_99 ( V_7 ) ;
if ( V_146 & V_150 )
F_94 ( V_1 , V_146 ) ;
F_3 ( V_213 , V_178 ) ;
F_3 ( V_214 , V_146 ) ;
F_3 ( V_212 , V_207 ) ;
}
V_215:
return V_39 ;
}
static void F_108 ( struct V_6 * V_7 , T_2 V_226 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
int V_12 ;
T_2 V_189 = V_226 & V_227 ;
F_95 ( V_7 , V_189 , V_228 ) ;
if ( V_226 & V_229 ) {
int V_230 = F_109 ( ( V_226 & V_229 ) >>
V_231 ) ;
F_36 ( L_22 ,
F_110 ( V_230 ) ) ;
}
if ( V_226 & V_232 )
F_100 ( V_7 ) ;
if ( V_226 & V_233 )
F_99 ( V_7 ) ;
if ( V_226 & V_234 )
F_36 ( L_23 ) ;
if ( V_226 & V_235 )
F_36 ( L_24 ) ;
if ( V_226 & V_236 )
F_24 ( L_25 ) ;
if ( V_226 & V_237 )
F_7 (pipe)
F_36 ( L_26 ,
F_37 ( V_12 ) ,
F_13 ( F_111 ( V_12 ) ) ) ;
if ( V_226 & ( V_238 | V_239 ) )
F_36 ( L_27 ) ;
if ( V_226 & ( V_240 | V_241 ) )
F_36 ( L_28 ) ;
if ( V_226 & V_27 )
if ( F_21 ( V_7 , V_242 ,
false ) )
F_36 ( L_29 ) ;
if ( V_226 & V_28 )
if ( F_21 ( V_7 , V_243 ,
false ) )
F_36 ( L_30 ) ;
}
static void F_112 ( struct V_6 * V_7 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
T_2 V_244 = F_13 ( V_21 ) ;
if ( V_244 & V_245 )
F_24 ( L_31 ) ;
if ( V_244 & V_22 )
if ( F_15 ( V_7 , V_18 , false ) )
F_36 ( L_32 ) ;
if ( V_244 & V_23 )
if ( F_15 ( V_7 , V_246 , false ) )
F_36 ( L_33 ) ;
if ( V_244 & V_24 )
if ( F_15 ( V_7 , V_247 , false ) )
F_36 ( L_34 ) ;
F_3 ( V_21 , V_244 ) ;
}
static void F_113 ( struct V_6 * V_7 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
T_2 V_248 = F_13 ( V_32 ) ;
if ( V_248 & V_249 )
F_24 ( L_25 ) ;
if ( V_248 & V_33 )
if ( F_21 ( V_7 , V_242 ,
false ) )
F_36 ( L_29 ) ;
if ( V_248 & V_34 )
if ( F_21 ( V_7 , V_243 ,
false ) )
F_36 ( L_30 ) ;
if ( V_248 & V_35 )
if ( F_21 ( V_7 , V_250 ,
false ) )
F_36 ( L_35 ) ;
F_3 ( V_32 , V_248 ) ;
}
static void F_114 ( struct V_6 * V_7 , T_2 V_226 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
int V_12 ;
T_2 V_189 = V_226 & V_251 ;
F_95 ( V_7 , V_189 , V_252 ) ;
if ( V_226 & V_253 ) {
int V_230 = F_109 ( ( V_226 & V_253 ) >>
V_254 ) ;
F_36 ( L_36 ,
F_110 ( V_230 ) ) ;
}
if ( V_226 & V_255 )
F_100 ( V_7 ) ;
if ( V_226 & V_256 )
F_99 ( V_7 ) ;
if ( V_226 & V_257 )
F_36 ( L_37 ) ;
if ( V_226 & V_258 )
F_36 ( L_38 ) ;
if ( V_226 & V_259 )
F_7 (pipe)
F_36 ( L_26 ,
F_37 ( V_12 ) ,
F_13 ( F_111 ( V_12 ) ) ) ;
if ( V_226 & V_36 )
F_113 ( V_7 ) ;
}
static T_5 F_115 ( int V_205 , void * V_206 )
{
struct V_6 * V_7 = (struct V_6 * ) V_206 ;
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
T_2 V_260 , V_178 , V_261 , V_146 , V_262 = 0 ;
T_5 V_39 = V_208 ;
int V_191 ;
F_104 ( & V_1 -> V_211 ) ;
if ( F_116 ( V_7 ) &&
( F_102 ( V_263 ) & V_264 ) ) {
F_24 ( L_39 ) ;
F_117 ( V_263 , V_264 ) ;
}
V_261 = F_13 ( V_265 ) ;
F_3 ( V_265 , V_261 & ~ V_266 ) ;
if ( ! F_118 ( V_7 ) ) {
V_262 = F_13 ( V_267 ) ;
F_3 ( V_267 , 0 ) ;
F_4 ( V_267 ) ;
}
if ( F_116 ( V_7 ) ) {
F_96 ( & V_1 -> V_3 ) ;
F_5 ( V_1 , V_25 ) ;
F_98 ( & V_1 -> V_3 ) ;
}
V_178 = F_13 ( V_213 ) ;
if ( V_178 ) {
F_92 ( V_7 , V_1 , V_178 ) ;
F_3 ( V_213 , V_178 ) ;
V_39 = V_216 ;
}
V_260 = F_13 ( V_268 ) ;
if ( V_260 ) {
if ( V_260 & V_25 )
F_112 ( V_7 ) ;
if ( V_260 & V_269 )
F_100 ( V_7 ) ;
if ( V_260 & V_270 )
F_119 ( V_7 ) ;
for ( V_191 = 0 ; V_191 < 3 ; V_191 ++ ) {
if ( V_260 & ( V_271 << ( 5 * V_191 ) ) )
F_105 ( V_7 , V_191 ) ;
if ( V_260 & ( V_272 << ( 5 * V_191 ) ) ) {
F_106 ( V_7 , V_191 ) ;
F_120 ( V_7 , V_191 ) ;
}
}
if ( ! F_118 ( V_7 ) && ( V_260 & V_273 ) ) {
T_2 V_226 = F_13 ( V_274 ) ;
F_114 ( V_7 , V_226 ) ;
F_3 ( V_274 , V_226 ) ;
}
F_3 ( V_268 , V_260 ) ;
V_39 = V_216 ;
}
V_146 = F_13 ( V_214 ) ;
if ( V_146 ) {
if ( F_116 ( V_7 ) )
F_101 ( V_1 , V_146 ) ;
else if ( V_146 & V_150 )
F_94 ( V_1 , V_146 ) ;
F_3 ( V_214 , V_146 ) ;
V_39 = V_216 ;
}
if ( F_116 ( V_7 ) ) {
F_96 ( & V_1 -> V_3 ) ;
if ( F_6 ( V_7 ) )
F_1 ( V_1 , V_25 ) ;
F_98 ( & V_1 -> V_3 ) ;
}
F_3 ( V_265 , V_261 ) ;
F_4 ( V_265 ) ;
if ( ! F_118 ( V_7 ) ) {
F_3 ( V_267 , V_262 ) ;
F_4 ( V_267 ) ;
}
return V_39 ;
}
static void F_121 ( struct V_6 * V_7 ,
struct V_8 * V_1 ,
T_2 V_178 )
{
if ( V_178 &
( V_179 | V_180 ) )
F_70 ( V_7 , & V_1 -> V_137 [ V_181 ] ) ;
if ( V_178 & V_275 )
F_70 ( V_7 , & V_1 -> V_137 [ V_183 ] ) ;
}
static T_5 F_122 ( int V_205 , void * V_206 )
{
struct V_6 * V_7 = (struct V_6 * ) V_206 ;
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
int V_39 = V_208 ;
T_2 V_260 , V_178 , V_261 , V_146 , V_262 ;
F_104 ( & V_1 -> V_211 ) ;
V_261 = F_13 ( V_265 ) ;
F_3 ( V_265 , V_261 & ~ V_266 ) ;
F_4 ( V_265 ) ;
V_262 = F_13 ( V_267 ) ;
F_3 ( V_267 , 0 ) ;
F_4 ( V_267 ) ;
V_260 = F_13 ( V_268 ) ;
V_178 = F_13 ( V_213 ) ;
V_146 = F_13 ( V_214 ) ;
if ( V_260 == 0 && V_178 == 0 && ( ! F_18 ( V_7 ) || V_146 == 0 ) )
goto V_40;
V_39 = V_216 ;
if ( F_17 ( V_7 ) )
F_121 ( V_7 , V_1 , V_178 ) ;
else
F_92 ( V_7 , V_1 , V_178 ) ;
if ( V_260 & V_276 )
F_100 ( V_7 ) ;
if ( V_260 & V_277 )
F_119 ( V_7 ) ;
if ( V_260 & V_278 )
F_105 ( V_7 , 0 ) ;
if ( V_260 & V_279 )
F_105 ( V_7 , 1 ) ;
if ( V_260 & V_280 )
F_24 ( L_31 ) ;
if ( V_260 & V_19 )
if ( F_15 ( V_7 , V_18 , false ) )
F_36 ( L_32 ) ;
if ( V_260 & V_20 )
if ( F_15 ( V_7 , V_246 , false ) )
F_36 ( L_33 ) ;
if ( V_260 & V_281 ) {
F_106 ( V_7 , 0 ) ;
F_120 ( V_7 , 0 ) ;
}
if ( V_260 & V_282 ) {
F_106 ( V_7 , 1 ) ;
F_120 ( V_7 , 1 ) ;
}
if ( V_260 & V_283 ) {
T_2 V_226 = F_13 ( V_274 ) ;
if ( F_123 ( V_7 ) )
F_114 ( V_7 , V_226 ) ;
else
F_108 ( V_7 , V_226 ) ;
F_3 ( V_274 , V_226 ) ;
}
if ( F_17 ( V_7 ) && V_260 & V_284 )
F_67 ( V_7 ) ;
if ( F_18 ( V_7 ) && V_146 & V_150 )
F_94 ( V_1 , V_146 ) ;
F_3 ( V_213 , V_178 ) ;
F_3 ( V_268 , V_260 ) ;
F_3 ( V_214 , V_146 ) ;
V_40:
F_3 ( V_265 , V_261 ) ;
F_4 ( V_265 ) ;
F_3 ( V_267 , V_262 ) ;
F_4 ( V_267 ) ;
return V_39 ;
}
static void F_124 ( struct V_95 * V_96 )
{
struct V_285 * error = F_57 ( V_96 , struct V_285 ,
V_96 ) ;
T_1 * V_1 = F_57 ( error , T_1 ,
V_142 ) ;
struct V_6 * V_7 = V_1 -> V_7 ;
struct V_136 * V_137 ;
char * V_286 [] = { L_40 , NULL } ;
char * V_287 [] = { L_41 , NULL } ;
char * V_288 [] = { L_42 , NULL } ;
int V_191 , V_39 ;
F_86 ( & V_7 -> V_174 -> V_175 . V_176 , V_177 , V_286 ) ;
if ( F_125 ( error ) && ! F_126 ( error ) ) {
F_36 ( L_43 ) ;
F_86 ( & V_7 -> V_174 -> V_175 . V_176 , V_177 ,
V_287 ) ;
V_39 = F_127 ( V_7 ) ;
if ( V_39 == 0 ) {
F_128 () ;
F_104 ( & V_1 -> V_142 . V_289 ) ;
F_86 ( & V_7 -> V_174 -> V_175 . V_176 ,
V_177 , V_288 ) ;
} else {
F_129 ( & error -> V_289 , V_290 ) ;
}
F_130 (ring, dev_priv, i)
F_72 ( & V_137 -> V_140 ) ;
F_131 ( V_7 ) ;
F_72 ( & V_1 -> V_142 . V_291 ) ;
}
}
static void F_132 ( struct V_6 * V_7 ,
T_3 * V_292 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
memset ( V_292 , 0 , sizeof( * V_292 ) * V_293 ) ;
switch( F_31 ( V_7 ) -> V_50 ) {
case 2 :
case 3 :
V_292 [ 0 ] = F_13 ( V_294 ) ;
break;
case 4 :
case 5 :
case 6 :
V_292 [ 0 ] = F_13 ( V_295 ) ;
V_292 [ 1 ] = F_13 ( V_296 ) ;
break;
default:
F_133 ( 1 , L_44 ) ;
case 7 :
V_292 [ 0 ] = F_13 ( V_297 ) ;
V_292 [ 1 ] = F_13 ( V_298 ) ;
V_292 [ 2 ] = F_13 ( V_299 ) ;
V_292 [ 3 ] = F_13 ( V_300 ) ;
break;
}
}
static struct V_301 *
F_134 ( struct V_8 * V_1 ,
struct V_302 * V_303 ,
const int V_304 )
{
struct V_301 * V_305 ;
int V_191 ;
T_2 V_306 ;
if ( V_303 == NULL || V_303 -> V_307 == NULL )
return NULL ;
V_305 = F_135 ( sizeof( * V_305 ) + V_304 * sizeof( T_2 * ) , V_308 ) ;
if ( V_305 == NULL )
return NULL ;
V_306 = V_303 -> V_309 ;
for ( V_191 = 0 ; V_191 < V_304 ; V_191 ++ ) {
unsigned long V_38 ;
void * V_310 ;
V_310 = F_135 ( V_311 , V_308 ) ;
if ( V_310 == NULL )
goto V_312;
F_136 ( V_38 ) ;
if ( V_306 < V_1 -> V_313 . V_314 &&
V_303 -> V_315 ) {
void T_6 * V_316 ;
V_316 = F_137 ( V_1 -> V_313 . V_317 ,
V_306 ) ;
F_138 ( V_310 , V_316 , V_311 ) ;
F_139 ( V_316 ) ;
} else if ( V_303 -> V_318 ) {
unsigned long V_319 ;
V_319 = V_1 -> V_320 . V_321 ;
V_319 += V_303 -> V_318 -> V_322 ;
V_319 += V_191 << V_323 ;
F_138 ( V_310 , ( void T_6 * ) V_319 , V_311 ) ;
} else {
struct V_324 * V_324 ;
void * V_316 ;
V_324 = F_140 ( V_303 , V_191 ) ;
F_141 ( & V_324 , 1 ) ;
V_316 = F_142 ( V_324 ) ;
memcpy ( V_310 , V_316 , V_311 ) ;
F_143 ( V_316 ) ;
F_141 ( & V_324 , 1 ) ;
}
F_144 ( V_38 ) ;
V_305 -> V_307 [ V_191 ] = V_310 ;
V_306 += V_311 ;
}
V_305 -> V_325 = V_304 ;
V_305 -> V_309 = V_303 -> V_309 ;
return V_305 ;
V_312:
while ( V_191 -- )
F_88 ( V_305 -> V_307 [ V_191 ] ) ;
F_88 ( V_305 ) ;
return NULL ;
}
static void
F_145 ( struct V_301 * V_138 )
{
int V_324 ;
if ( V_138 == NULL )
return;
for ( V_324 = 0 ; V_324 < V_138 -> V_325 ; V_324 ++ )
F_88 ( V_138 -> V_307 [ V_324 ] ) ;
F_88 ( V_138 ) ;
}
void
F_146 ( struct V_326 * V_327 )
{
struct V_328 * error = F_57 ( V_327 ,
F_147 ( * error ) , V_329 ) ;
int V_191 ;
for ( V_191 = 0 ; V_191 < F_148 ( error -> V_137 ) ; V_191 ++ ) {
F_145 ( error -> V_137 [ V_191 ] . V_330 ) ;
F_145 ( error -> V_137 [ V_191 ] . V_331 ) ;
F_145 ( error -> V_137 [ V_191 ] . V_332 ) ;
F_88 ( error -> V_137 [ V_191 ] . V_333 ) ;
}
F_88 ( error -> V_334 ) ;
F_88 ( error -> V_335 ) ;
F_88 ( error -> V_199 ) ;
F_88 ( error ) ;
}
static void F_149 ( struct V_336 * V_337 ,
struct V_302 * V_138 )
{
V_337 -> V_338 = V_138 -> V_26 . V_338 ;
V_337 -> V_339 = V_138 -> V_26 . V_339 ;
V_337 -> V_340 = V_138 -> V_341 ;
V_337 -> V_342 = V_138 -> V_343 ;
V_337 -> V_309 = V_138 -> V_309 ;
V_337 -> V_344 = V_138 -> V_26 . V_344 ;
V_337 -> V_345 = V_138 -> V_26 . V_345 ;
V_337 -> V_346 = V_138 -> V_346 ;
V_337 -> V_347 = 0 ;
if ( V_138 -> V_348 > 0 )
V_337 -> V_347 = 1 ;
if ( V_138 -> V_349 > 0 )
V_337 -> V_347 = - 1 ;
V_337 -> V_350 = V_138 -> V_351 ;
V_337 -> V_352 = V_138 -> V_352 ;
V_337 -> V_353 = V_138 -> V_354 != V_355 ;
V_337 -> V_137 = V_138 -> V_137 ? V_138 -> V_137 -> V_94 : - 1 ;
V_337 -> V_356 = V_138 -> V_356 ;
}
static T_2 F_150 ( struct V_336 * V_337 ,
int V_357 , struct V_358 * V_359 )
{
struct V_302 * V_138 ;
int V_191 = 0 ;
F_59 (obj, head, mm_list) {
F_149 ( V_337 ++ , V_138 ) ;
if ( ++ V_191 == V_357 )
break;
}
return V_191 ;
}
static T_2 F_151 ( struct V_336 * V_337 ,
int V_357 , struct V_358 * V_359 )
{
struct V_302 * V_138 ;
int V_191 = 0 ;
F_59 (obj, head, global_list) {
if ( V_138 -> V_348 == 0 )
continue;
F_149 ( V_337 ++ , V_138 ) ;
if ( ++ V_191 == V_357 )
break;
}
return V_191 ;
}
static void F_152 ( struct V_6 * V_7 ,
struct V_328 * error )
{
struct V_8 * V_1 = V_7 -> V_9 ;
int V_191 ;
switch ( F_31 ( V_7 ) -> V_50 ) {
case 7 :
case 6 :
for ( V_191 = 0 ; V_191 < V_1 -> V_360 ; V_191 ++ )
error -> V_361 [ V_191 ] = F_153 ( V_362 + ( V_191 * 8 ) ) ;
break;
case 5 :
case 4 :
for ( V_191 = 0 ; V_191 < 16 ; V_191 ++ )
error -> V_361 [ V_191 ] = F_153 ( V_363 + ( V_191 * 8 ) ) ;
break;
case 3 :
if ( F_154 ( V_7 ) || F_155 ( V_7 ) || F_156 ( V_7 ) )
for ( V_191 = 0 ; V_191 < 8 ; V_191 ++ )
error -> V_361 [ V_191 + 8 ] = F_13 ( V_364 + ( V_191 * 4 ) ) ;
case 2 :
for ( V_191 = 0 ; V_191 < 8 ; V_191 ++ )
error -> V_361 [ V_191 ] = F_13 ( V_365 + ( V_191 * 4 ) ) ;
break;
default:
F_157 () ;
}
}
static struct V_301 *
F_158 ( struct V_8 * V_1 ,
struct V_136 * V_137 )
{
struct V_302 * V_138 ;
T_2 V_366 ;
if ( ! V_137 -> V_139 )
return NULL ;
if ( F_159 ( V_1 -> V_7 ) ) {
T_2 V_367 = F_13 ( V_368 ) ;
if ( F_53 ( V_137 -> V_94 != V_181 ) )
return NULL ;
V_138 = V_137 -> V_369 ;
if ( V_367 >= V_138 -> V_309 &&
V_367 < V_138 -> V_309 + V_138 -> V_26 . V_338 )
return F_160 ( V_1 , V_138 ) ;
}
V_366 = V_137 -> V_139 ( V_137 , false ) ;
F_59 (obj, &dev_priv->mm.active_list, mm_list) {
if ( V_138 -> V_137 != V_137 )
continue;
if ( F_161 ( V_366 , V_138 -> V_341 ) )
continue;
if ( ( V_138 -> V_26 . V_344 & V_370 ) == 0 )
continue;
return F_160 ( V_1 , V_138 ) ;
}
return NULL ;
}
static void F_162 ( struct V_6 * V_7 ,
struct V_328 * error ,
struct V_136 * V_137 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
if ( F_31 ( V_7 ) -> V_50 >= 6 ) {
error -> V_371 [ V_137 -> V_94 ] = F_13 ( V_137 -> V_372 + 0x50 ) ;
error -> V_373 [ V_137 -> V_94 ] = F_13 ( F_163 ( V_137 ) ) ;
error -> V_374 [ V_137 -> V_94 ] [ 0 ]
= F_13 ( F_164 ( V_137 -> V_372 ) ) ;
error -> V_374 [ V_137 -> V_94 ] [ 1 ]
= F_13 ( F_165 ( V_137 -> V_372 ) ) ;
error -> V_375 [ V_137 -> V_94 ] [ 0 ] = V_137 -> V_376 [ 0 ] ;
error -> V_375 [ V_137 -> V_94 ] [ 1 ] = V_137 -> V_376 [ 1 ] ;
}
if ( F_31 ( V_7 ) -> V_50 >= 4 ) {
error -> V_377 [ V_137 -> V_94 ] = F_13 ( F_166 ( V_137 -> V_372 ) ) ;
error -> V_378 [ V_137 -> V_94 ] = F_13 ( F_167 ( V_137 -> V_372 ) ) ;
error -> V_379 [ V_137 -> V_94 ] = F_13 ( F_168 ( V_137 -> V_372 ) ) ;
error -> V_292 [ V_137 -> V_94 ] = F_13 ( F_169 ( V_137 -> V_372 ) ) ;
error -> V_380 [ V_137 -> V_94 ] = F_13 ( F_170 ( V_137 -> V_372 ) ) ;
if ( V_137 -> V_94 == V_181 )
error -> V_381 = F_153 ( V_382 ) ;
} else {
error -> V_377 [ V_137 -> V_94 ] = F_13 ( V_383 ) ;
error -> V_378 [ V_137 -> V_94 ] = F_13 ( V_384 ) ;
error -> V_379 [ V_137 -> V_94 ] = F_13 ( V_385 ) ;
error -> V_292 [ V_137 -> V_94 ] = F_13 ( V_294 ) ;
}
error -> V_386 [ V_137 -> V_94 ] = F_171 ( & V_137 -> V_140 ) ;
error -> V_387 [ V_137 -> V_94 ] = F_13 ( F_172 ( V_137 -> V_372 ) ) ;
error -> V_366 [ V_137 -> V_94 ] = V_137 -> V_139 ( V_137 , false ) ;
error -> V_367 [ V_137 -> V_94 ] = F_173 ( V_137 ) ;
error -> V_359 [ V_137 -> V_94 ] = F_174 ( V_137 ) ;
error -> V_388 [ V_137 -> V_94 ] = F_175 ( V_137 ) ;
error -> V_389 [ V_137 -> V_94 ] = F_176 ( V_137 ) ;
error -> V_390 [ V_137 -> V_94 ] = V_137 -> V_359 ;
error -> V_391 [ V_137 -> V_94 ] = V_137 -> V_388 ;
}
static void F_177 ( struct V_136 * V_137 ,
struct V_328 * error ,
struct V_392 * V_393 )
{
struct V_8 * V_1 = V_137 -> V_7 -> V_9 ;
struct V_302 * V_138 ;
if ( V_137 -> V_94 != V_181 || ! error -> V_394 )
return;
F_59 (obj, &dev_priv->mm.bound_list, global_list) {
if ( ( error -> V_394 & V_395 ) == V_138 -> V_309 ) {
V_393 -> V_332 = F_134 ( V_1 ,
V_138 , 1 ) ;
}
}
}
static void F_178 ( struct V_6 * V_7 ,
struct V_328 * error )
{
struct V_8 * V_1 = V_7 -> V_9 ;
struct V_136 * V_137 ;
struct V_396 * V_397 ;
int V_191 , V_357 ;
F_130 (ring, dev_priv, i) {
F_162 ( V_7 , error , V_137 ) ;
error -> V_137 [ V_191 ] . V_330 =
F_158 ( V_1 , V_137 ) ;
error -> V_137 [ V_191 ] . V_331 =
F_160 ( V_1 , V_137 -> V_138 ) ;
F_177 ( V_137 , error , & error -> V_137 [ V_191 ] ) ;
V_357 = 0 ;
F_59 (request, &ring->request_list, list)
V_357 ++ ;
error -> V_137 [ V_191 ] . V_398 = V_357 ;
error -> V_137 [ V_191 ] . V_333 =
F_135 ( V_357 * sizeof( struct V_399 ) ,
V_308 ) ;
if ( error -> V_137 [ V_191 ] . V_333 == NULL ) {
error -> V_137 [ V_191 ] . V_398 = 0 ;
continue;
}
V_357 = 0 ;
F_59 (request, &ring->request_list, list) {
struct V_399 * V_400 ;
V_400 = & error -> V_137 [ V_191 ] . V_333 [ V_357 ++ ] ;
V_400 -> V_366 = V_397 -> V_366 ;
V_400 -> V_117 = V_397 -> V_401 ;
V_400 -> V_388 = V_397 -> V_388 ;
}
}
}
static void F_179 ( struct V_6 * V_7 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
struct V_302 * V_138 ;
struct V_328 * error ;
unsigned long V_38 ;
int V_191 , V_12 ;
F_16 ( & V_1 -> V_142 . V_148 , V_38 ) ;
error = V_1 -> V_142 . V_402 ;
F_20 ( & V_1 -> V_142 . V_148 , V_38 ) ;
if ( error )
return;
error = F_180 ( sizeof( * error ) , V_308 ) ;
if ( ! error ) {
F_36 ( L_45 ) ;
return;
}
F_61 ( L_46
L_47 ,
V_7 -> V_174 -> V_403 ) ;
F_181 ( & error -> V_329 ) ;
error -> V_404 = F_13 ( V_405 ) ;
error -> V_406 = F_13 ( V_407 ) ;
if ( F_182 ( V_7 ) )
error -> V_394 = F_13 ( V_408 ) ;
if ( F_183 ( V_7 ) )
error -> V_409 = F_13 ( V_265 ) | F_13 ( V_410 ) ;
else if ( F_77 ( V_7 ) )
error -> V_409 = F_13 ( V_410 ) | F_13 ( V_411 ) ;
else if ( F_184 ( V_7 ) )
error -> V_409 = F_185 ( V_412 ) ;
else
error -> V_409 = F_13 ( V_412 ) ;
if ( F_31 ( V_7 ) -> V_50 >= 6 )
error -> V_413 = F_13 ( V_414 ) ;
if ( F_77 ( V_7 ) )
error -> V_415 = F_13 ( V_416 ) ;
else if ( F_31 ( V_7 ) -> V_50 >= 7 )
error -> V_415 = F_13 ( V_417 ) ;
else if ( F_31 ( V_7 ) -> V_50 == 6 )
error -> V_415 = F_13 ( V_418 ) ;
if ( ! F_183 ( V_7 ) )
F_7 ( V_12 )
error -> V_45 [ V_12 ] = F_13 ( F_27 ( V_12 ) ) ;
if ( F_31 ( V_7 ) -> V_50 >= 6 ) {
error -> error = F_13 ( V_419 ) ;
error -> V_420 = F_13 ( V_421 ) ;
}
if ( F_31 ( V_7 ) -> V_50 == 7 )
error -> V_244 = F_13 ( V_21 ) ;
F_132 ( V_7 , error -> V_422 ) ;
F_152 ( V_7 , error ) ;
F_178 ( V_7 , error ) ;
error -> V_334 = NULL ;
error -> V_423 = NULL ;
V_191 = 0 ;
F_59 (obj, &dev_priv->mm.active_list, mm_list)
V_191 ++ ;
error -> V_424 = V_191 ;
F_59 (obj, &dev_priv->mm.bound_list, global_list)
if ( V_138 -> V_348 )
V_191 ++ ;
error -> V_425 = V_191 - error -> V_424 ;
error -> V_334 = NULL ;
error -> V_423 = NULL ;
if ( V_191 ) {
error -> V_334 = F_135 ( sizeof( * error -> V_334 ) * V_191 ,
V_308 ) ;
if ( error -> V_334 )
error -> V_423 =
error -> V_334 + error -> V_424 ;
}
if ( error -> V_334 )
error -> V_424 =
F_150 ( error -> V_334 ,
error -> V_424 ,
& V_1 -> V_320 . V_426 ) ;
if ( error -> V_423 )
error -> V_425 =
F_151 ( error -> V_423 ,
error -> V_425 ,
& V_1 -> V_320 . V_427 ) ;
F_186 ( & error -> time ) ;
error -> V_335 = F_187 ( V_7 ) ;
error -> V_199 = F_188 ( V_7 ) ;
F_16 ( & V_1 -> V_142 . V_148 , V_38 ) ;
if ( V_1 -> V_142 . V_402 == NULL ) {
V_1 -> V_142 . V_402 = error ;
error = NULL ;
}
F_20 ( & V_1 -> V_142 . V_148 , V_38 ) ;
if ( error )
F_146 ( & error -> V_329 ) ;
}
void F_189 ( struct V_6 * V_7 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
struct V_328 * error ;
unsigned long V_38 ;
F_16 ( & V_1 -> V_142 . V_148 , V_38 ) ;
error = V_1 -> V_142 . V_402 ;
V_1 -> V_142 . V_402 = NULL ;
F_20 ( & V_1 -> V_142 . V_148 , V_38 ) ;
if ( error )
F_190 ( & error -> V_329 , F_146 ) ;
}
static void F_191 ( struct V_6 * V_7 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
T_3 V_292 [ V_293 ] ;
T_2 V_404 = F_13 ( V_405 ) ;
int V_12 , V_191 ;
if ( ! V_404 )
return;
F_192 ( L_48 , V_404 ) ;
F_132 ( V_7 , V_292 ) ;
if ( F_193 ( V_7 ) ) {
if ( V_404 & ( V_428 | V_429 ) ) {
T_2 V_378 = F_13 ( V_430 ) ;
F_192 ( L_49 , F_13 ( V_430 ) ) ;
F_192 ( L_50 , F_13 ( V_431 ) ) ;
for ( V_191 = 0 ; V_191 < F_148 ( V_292 ) ; V_191 ++ )
F_192 ( L_51 , V_191 , V_292 [ V_191 ] ) ;
F_192 ( L_52 , F_13 ( V_432 ) ) ;
F_192 ( L_53 , F_13 ( V_433 ) ) ;
F_3 ( V_430 , V_378 ) ;
F_4 ( V_430 ) ;
}
if ( V_404 & V_434 ) {
T_2 V_435 = F_13 ( V_407 ) ;
F_192 ( L_54 ) ;
F_192 ( L_55 , V_435 ) ;
F_3 ( V_407 , V_435 ) ;
F_4 ( V_407 ) ;
}
}
if ( ! F_184 ( V_7 ) ) {
if ( V_404 & V_436 ) {
T_2 V_435 = F_13 ( V_407 ) ;
F_192 ( L_54 ) ;
F_192 ( L_55 , V_435 ) ;
F_3 ( V_407 , V_435 ) ;
F_4 ( V_407 ) ;
}
}
if ( V_404 & V_437 ) {
F_192 ( L_56 ) ;
F_7 (pipe)
F_192 ( L_57 ,
F_37 ( V_12 ) , F_13 ( F_27 ( V_12 ) ) ) ;
}
if ( V_404 & V_438 ) {
F_192 ( L_58 ) ;
F_192 ( L_59 , F_13 ( V_439 ) ) ;
for ( V_191 = 0 ; V_191 < F_148 ( V_292 ) ; V_191 ++ )
F_192 ( L_51 , V_191 , V_292 [ V_191 ] ) ;
if ( F_31 ( V_7 ) -> V_50 < 4 ) {
T_2 V_378 = F_13 ( V_384 ) ;
F_192 ( L_49 , F_13 ( V_384 ) ) ;
F_192 ( L_50 , F_13 ( V_385 ) ) ;
F_192 ( L_53 , F_13 ( V_368 ) ) ;
F_3 ( V_384 , V_378 ) ;
F_4 ( V_384 ) ;
} else {
T_2 V_378 = F_13 ( V_430 ) ;
F_192 ( L_49 , F_13 ( V_430 ) ) ;
F_192 ( L_50 , F_13 ( V_431 ) ) ;
F_192 ( L_52 , F_13 ( V_432 ) ) ;
F_192 ( L_53 , F_13 ( V_433 ) ) ;
F_3 ( V_430 , V_378 ) ;
F_4 ( V_430 ) ;
}
}
F_3 ( V_405 , V_404 ) ;
F_4 ( V_405 ) ;
V_404 = F_13 ( V_405 ) ;
if ( V_404 ) {
F_24 ( L_60 , V_404 ) ;
F_3 ( V_440 , F_13 ( V_440 ) | V_404 ) ;
F_3 ( V_441 , V_442 ) ;
}
}
void F_93 ( struct V_6 * V_7 , bool V_443 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
struct V_136 * V_137 ;
int V_191 ;
F_179 ( V_7 ) ;
F_191 ( V_7 ) ;
if ( V_443 ) {
F_194 ( V_444 ,
& V_1 -> V_142 . V_289 ) ;
F_130 (ring, dev_priv, i)
F_72 ( & V_137 -> V_140 ) ;
}
F_91 ( V_1 -> V_154 , & V_1 -> V_142 . V_96 ) ;
}
static void T_7 F_195 ( struct V_6 * V_7 , int V_12 )
{
T_1 * V_1 = V_7 -> V_9 ;
struct V_37 * V_11 = V_1 -> V_13 [ V_12 ] ;
struct V_10 * V_10 = F_8 ( V_11 ) ;
struct V_302 * V_138 ;
struct V_445 * V_96 ;
unsigned long V_38 ;
bool V_446 ;
if ( V_10 == NULL )
return;
F_16 ( & V_7 -> V_447 , V_38 ) ;
V_96 = V_10 -> V_448 ;
if ( V_96 == NULL ||
F_196 ( & V_96 -> V_449 ) >= V_450 ||
! V_96 -> V_451 ) {
F_20 ( & V_7 -> V_447 , V_38 ) ;
return;
}
V_138 = V_96 -> V_452 ;
if ( F_31 ( V_7 ) -> V_50 >= 4 ) {
int V_453 = F_197 ( V_10 -> V_454 ) ;
V_446 = F_198 ( F_13 ( V_453 ) ) ==
V_138 -> V_309 ;
} else {
int V_455 = F_199 ( V_10 -> V_454 ) ;
V_446 = F_13 ( V_455 ) == ( V_138 -> V_309 +
V_11 -> V_456 * V_11 -> V_457 -> V_458 [ 0 ] +
V_11 -> V_459 * V_11 -> V_457 -> V_460 / 8 ) ;
}
F_20 ( & V_7 -> V_447 , V_38 ) ;
if ( V_446 ) {
F_36 ( L_61 ) ;
F_106 ( V_7 , V_10 -> V_454 ) ;
}
}
static int F_200 ( struct V_6 * V_7 , int V_12 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
unsigned long V_46 ;
if ( ! F_32 ( V_7 , V_12 ) )
return - V_82 ;
F_16 ( & V_1 -> V_3 , V_46 ) ;
if ( F_31 ( V_7 ) -> V_50 >= 4 )
F_26 ( V_1 , V_12 ,
V_461 ) ;
else
F_26 ( V_1 , V_12 ,
V_462 ) ;
if ( V_1 -> V_463 -> V_50 == 3 )
F_3 ( V_439 , F_201 ( V_464 ) ) ;
F_20 ( & V_1 -> V_3 , V_46 ) ;
return 0 ;
}
static int F_202 ( struct V_6 * V_7 , int V_12 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
unsigned long V_46 ;
if ( ! F_32 ( V_7 , V_12 ) )
return - V_82 ;
F_16 ( & V_1 -> V_3 , V_46 ) ;
F_1 ( V_1 , ( V_12 == 0 ) ?
V_278 : V_279 ) ;
F_20 ( & V_1 -> V_3 , V_46 ) ;
return 0 ;
}
static int F_203 ( struct V_6 * V_7 , int V_12 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
unsigned long V_46 ;
if ( ! F_32 ( V_7 , V_12 ) )
return - V_82 ;
F_16 ( & V_1 -> V_3 , V_46 ) ;
F_1 ( V_1 ,
V_271 << ( 5 * V_12 ) ) ;
F_20 ( & V_1 -> V_3 , V_46 ) ;
return 0 ;
}
static int F_204 ( struct V_6 * V_7 , int V_12 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
unsigned long V_46 ;
T_2 V_465 ;
if ( ! F_32 ( V_7 , V_12 ) )
return - V_82 ;
F_16 ( & V_1 -> V_3 , V_46 ) ;
V_465 = F_13 ( V_466 ) ;
if ( V_12 == 0 )
V_465 &= ~ V_467 ;
else
V_465 &= ~ V_468 ;
F_3 ( V_466 , V_465 ) ;
F_26 ( V_1 , V_12 ,
V_461 ) ;
F_20 ( & V_1 -> V_3 , V_46 ) ;
return 0 ;
}
static void F_205 ( struct V_6 * V_7 , int V_12 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
unsigned long V_46 ;
F_16 ( & V_1 -> V_3 , V_46 ) ;
if ( V_1 -> V_463 -> V_50 == 3 )
F_3 ( V_439 , F_206 ( V_464 ) ) ;
F_28 ( V_1 , V_12 ,
V_462 |
V_461 ) ;
F_20 ( & V_1 -> V_3 , V_46 ) ;
}
static void F_207 ( struct V_6 * V_7 , int V_12 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
unsigned long V_46 ;
F_16 ( & V_1 -> V_3 , V_46 ) ;
F_5 ( V_1 , ( V_12 == 0 ) ?
V_278 : V_279 ) ;
F_20 ( & V_1 -> V_3 , V_46 ) ;
}
static void F_208 ( struct V_6 * V_7 , int V_12 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
unsigned long V_46 ;
F_16 ( & V_1 -> V_3 , V_46 ) ;
F_5 ( V_1 ,
V_271 << ( V_12 * 5 ) ) ;
F_20 ( & V_1 -> V_3 , V_46 ) ;
}
static void F_209 ( struct V_6 * V_7 , int V_12 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
unsigned long V_46 ;
T_2 V_465 ;
F_16 ( & V_1 -> V_3 , V_46 ) ;
F_28 ( V_1 , V_12 ,
V_461 ) ;
V_465 = F_13 ( V_466 ) ;
if ( V_12 == 0 )
V_465 |= V_467 ;
else
V_465 |= V_468 ;
F_3 ( V_466 , V_465 ) ;
F_20 ( & V_1 -> V_3 , V_46 ) ;
}
static T_2
F_210 ( struct V_136 * V_137 )
{
return F_211 ( V_137 -> V_469 . V_470 ,
struct V_396 , V_471 ) -> V_366 ;
}
static bool
F_212 ( struct V_136 * V_137 , T_2 V_366 )
{
return ( F_213 ( & V_137 -> V_469 ) ||
F_161 ( V_366 , F_210 ( V_137 ) ) ) ;
}
static struct V_136 *
F_214 ( struct V_136 * V_137 , T_2 * V_366 )
{
struct V_8 * V_1 = V_137 -> V_7 -> V_9 ;
T_2 V_472 , V_379 , V_367 , V_473 ;
V_379 = F_13 ( F_168 ( V_137 -> V_372 ) ) ;
if ( ( V_379 & ~ ( 0x3 << 16 ) ) !=
( V_474 | V_475 | V_476 ) )
return NULL ;
V_367 = F_173 ( V_137 ) & V_477 ;
V_473 = F_215 ( ( int ) V_367 - 3 * 4 , 0 ) ;
do {
V_472 = F_216 ( V_137 -> V_478 + V_367 ) ;
if ( V_472 == V_379 )
break;
V_367 -= 4 ;
if ( V_367 < V_473 )
return NULL ;
} while ( 1 );
* V_366 = F_216 ( V_137 -> V_478 + V_367 + 4 ) + 1 ;
return & V_1 -> V_137 [ ( V_137 -> V_94 + ( ( ( V_379 >> 17 ) & 1 ) + 1 ) ) % 3 ] ;
}
static int F_217 ( struct V_136 * V_137 )
{
struct V_8 * V_1 = V_137 -> V_7 -> V_9 ;
struct V_136 * V_479 ;
T_2 V_366 , V_389 ;
V_137 -> V_480 . V_481 = true ;
V_479 = F_214 ( V_137 , & V_366 ) ;
if ( V_479 == NULL || V_479 -> V_480 . V_481 )
return - 1 ;
V_389 = F_176 ( V_479 ) ;
if ( V_389 & V_482 && F_217 ( V_479 ) < 0 )
return - 1 ;
return F_161 ( V_479 -> V_139 ( V_479 , false ) , V_366 ) ;
}
static void F_218 ( struct V_8 * V_1 )
{
struct V_136 * V_137 ;
int V_191 ;
F_130 (ring, dev_priv, i)
V_137 -> V_480 . V_481 = false ;
}
static enum V_483
F_219 ( struct V_136 * V_137 , T_2 V_367 )
{
struct V_6 * V_7 = V_137 -> V_7 ;
struct V_8 * V_1 = V_7 -> V_9 ;
T_2 V_484 ;
if ( V_137 -> V_480 . V_367 != V_367 )
return V_52 ;
if ( F_184 ( V_7 ) )
return V_485 ;
V_484 = F_176 ( V_137 ) ;
if ( V_484 & V_486 ) {
F_24 ( L_62 ,
V_137 -> V_339 ) ;
F_220 ( V_137 , V_484 ) ;
return V_487 ;
}
if ( F_31 ( V_7 ) -> V_50 >= 6 && V_484 & V_482 ) {
switch ( F_217 ( V_137 ) ) {
default:
return V_485 ;
case 1 :
F_24 ( L_63 ,
V_137 -> V_339 ) ;
F_220 ( V_137 , V_484 ) ;
return V_487 ;
case 0 :
return V_488 ;
}
}
return V_485 ;
}
void F_221 ( unsigned long V_489 )
{
struct V_6 * V_7 = (struct V_6 * ) V_489 ;
T_1 * V_1 = V_7 -> V_9 ;
struct V_136 * V_137 ;
int V_191 ;
int V_490 = 0 , V_491 = 0 ;
bool V_492 [ V_493 ] = { 0 } ;
#define F_222 1
#define F_223 5
#define F_224 20
#define F_225 30
if ( ! V_141 )
return;
F_130 (ring, dev_priv, i) {
T_2 V_366 , V_367 ;
bool V_494 = true ;
F_218 ( V_1 ) ;
V_366 = V_137 -> V_139 ( V_137 , false ) ;
V_367 = F_173 ( V_137 ) ;
if ( V_137 -> V_480 . V_366 == V_366 ) {
if ( F_212 ( V_137 , V_366 ) ) {
if ( F_171 ( & V_137 -> V_140 ) ) {
F_24 ( L_64 ,
V_137 -> V_339 ) ;
F_72 ( & V_137 -> V_140 ) ;
V_137 -> V_480 . V_495 += F_224 ;
} else
V_494 = false ;
} else {
int V_495 ;
V_137 -> V_480 . V_496 = F_219 ( V_137 ,
V_367 ) ;
switch ( V_137 -> V_480 . V_496 ) {
case V_488 :
V_495 = 0 ;
break;
case V_52 :
V_495 = F_222 ;
break;
case V_487 :
V_495 = F_223 ;
break;
case V_485 :
V_495 = F_224 ;
V_492 [ V_191 ] = true ;
break;
}
V_137 -> V_480 . V_495 += V_495 ;
}
} else {
if ( V_137 -> V_480 . V_495 > 0 )
V_137 -> V_480 . V_495 -- ;
}
V_137 -> V_480 . V_366 = V_366 ;
V_137 -> V_480 . V_367 = V_367 ;
V_490 += V_494 ;
}
F_130 (ring, dev_priv, i) {
if ( V_137 -> V_480 . V_495 > F_225 ) {
F_24 ( L_65 ,
V_492 [ V_191 ] ? L_66 : L_67 ,
V_137 -> V_339 ) ;
V_491 ++ ;
}
}
if ( V_491 )
return F_93 ( V_7 , true ) ;
if ( V_490 )
F_63 ( & V_1 -> V_142 . V_143 ,
F_73 ( V_117 +
V_144 ) ) ;
}
static void F_226 ( struct V_6 * V_7 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
if ( F_118 ( V_7 ) )
return;
F_3 ( V_29 , 0xffffffff ) ;
F_3 ( V_267 , 0xffffffff ) ;
F_4 ( V_267 ) ;
}
static void F_227 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
F_129 ( & V_1 -> V_211 , 0 ) ;
F_3 ( V_497 , 0xeffe ) ;
F_3 ( V_5 , 0xffffffff ) ;
F_3 ( V_265 , 0x0 ) ;
F_4 ( V_265 ) ;
F_3 ( V_172 , 0xffffffff ) ;
F_3 ( V_410 , 0x0 ) ;
F_4 ( V_410 ) ;
F_226 ( V_7 ) ;
}
static void F_228 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
F_129 ( & V_1 -> V_211 , 0 ) ;
F_3 ( V_497 , 0xeffe ) ;
F_3 ( V_5 , 0xffffffff ) ;
F_3 ( V_265 , 0x0 ) ;
F_4 ( V_265 ) ;
F_3 ( V_172 , 0xffffffff ) ;
F_3 ( V_410 , 0x0 ) ;
F_4 ( V_410 ) ;
F_3 ( V_149 , 0xffffffff ) ;
F_3 ( V_498 , 0x0 ) ;
F_4 ( V_498 ) ;
F_226 ( V_7 ) ;
}
static void F_229 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
int V_12 ;
F_129 ( & V_1 -> V_211 , 0 ) ;
F_3 ( V_466 , 0 ) ;
F_3 ( F_230 ( V_499 ) , 0 ) ;
F_3 ( F_230 ( V_500 ) , 0 ) ;
F_3 ( F_230 ( V_501 ) , 0 ) ;
F_3 ( V_213 , F_13 ( V_213 ) ) ;
F_3 ( V_213 , F_13 ( V_213 ) ) ;
F_3 ( V_172 , 0xffffffff ) ;
F_3 ( V_410 , 0x0 ) ;
F_4 ( V_410 ) ;
F_3 ( V_502 , 0xff ) ;
F_3 ( V_503 , 0 ) ;
F_3 ( V_222 , F_13 ( V_222 ) ) ;
F_7 (pipe)
F_3 ( F_27 ( V_12 ) , 0xffff ) ;
F_3 ( V_212 , 0xffffffff ) ;
F_3 ( V_466 , 0xffffffff ) ;
F_3 ( V_411 , 0x0 ) ;
F_4 ( V_411 ) ;
}
static void F_231 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
struct V_98 * V_89 = & V_7 -> V_89 ;
struct V_100 * V_100 ;
T_2 V_2 = ~ F_13 ( V_29 ) ;
T_2 V_504 ;
if ( F_25 ( V_7 ) ) {
V_2 &= ~ V_227 ;
F_59 (intel_encoder, &mode_config->encoder_list, base.head)
if ( V_1 -> V_108 [ V_100 -> V_106 ] . V_109 == V_194 )
V_2 |= V_228 [ V_100 -> V_106 ] ;
} else {
V_2 &= ~ V_251 ;
F_59 (intel_encoder, &mode_config->encoder_list, base.head)
if ( V_1 -> V_108 [ V_100 -> V_106 ] . V_109 == V_194 )
V_2 |= V_252 [ V_100 -> V_106 ] ;
}
F_3 ( V_29 , ~ V_2 ) ;
V_504 = F_13 ( V_505 ) ;
V_504 &= ~ ( V_506 | V_507 | V_508 ) ;
V_504 |= V_509 | V_510 ;
V_504 |= V_511 | V_512 ;
V_504 |= V_513 | V_514 ;
F_3 ( V_505 , V_504 ) ;
}
static void F_232 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
T_2 V_2 ;
if ( F_118 ( V_7 ) )
return;
if ( F_25 ( V_7 ) ) {
V_2 = V_233 | V_232 | V_28 |
V_27 | V_236 ;
} else {
V_2 = V_256 | V_255 | V_36 ;
F_3 ( V_32 , F_13 ( V_32 ) ) ;
}
F_3 ( V_274 , F_13 ( V_274 ) ) ;
F_3 ( V_29 , ~ V_2 ) ;
}
static int F_233 ( struct V_6 * V_7 )
{
unsigned long V_46 ;
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
T_2 V_515 = V_266 | V_277 | V_283 |
V_281 | V_282 |
V_276 | V_20 |
V_19 | V_280 ;
T_2 V_516 ;
V_1 -> V_4 = ~ V_515 ;
F_3 ( V_268 , F_13 ( V_268 ) ) ;
F_3 ( V_5 , V_1 -> V_4 ) ;
F_3 ( V_265 , V_515 |
V_278 | V_279 | V_284 ) ;
F_4 ( V_265 ) ;
V_1 -> V_170 = ~ 0 ;
F_3 ( V_213 , F_13 ( V_213 ) ) ;
F_3 ( V_172 , V_1 -> V_170 ) ;
V_516 = V_179 ;
if ( F_18 ( V_7 ) )
V_516 |= V_184 | V_182 ;
else
V_516 |= V_180 |
V_275 ;
F_3 ( V_410 , V_516 ) ;
F_4 ( V_410 ) ;
F_232 ( V_7 ) ;
if ( F_234 ( V_7 ) ) {
F_16 ( & V_1 -> V_3 , V_46 ) ;
F_1 ( V_1 , V_284 ) ;
F_20 ( & V_1 -> V_3 , V_46 ) ;
}
return 0 ;
}
static int F_235 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
T_2 V_515 =
V_266 | V_270 | V_273 |
V_517 |
V_518 |
V_272 |
V_269 |
V_25 ;
T_2 V_519 = V_150 ;
T_2 V_516 ;
V_1 -> V_4 = ~ V_515 ;
F_3 ( V_21 , F_13 ( V_21 ) ) ;
F_3 ( V_268 , F_13 ( V_268 ) ) ;
F_3 ( V_5 , V_1 -> V_4 ) ;
F_3 ( V_265 ,
V_515 |
V_520 |
V_521 |
V_271 ) ;
F_4 ( V_265 ) ;
V_1 -> V_170 = ~ V_171 ;
F_3 ( V_213 , F_13 ( V_213 ) ) ;
F_3 ( V_172 , V_1 -> V_170 ) ;
V_516 = V_179 | V_182 |
V_184 | V_171 ;
F_3 ( V_410 , V_516 ) ;
F_4 ( V_410 ) ;
F_3 ( V_214 , F_13 ( V_214 ) ) ;
if ( F_236 ( V_7 ) )
V_519 |= V_202 |
V_204 ;
F_3 ( V_149 ,
( F_13 ( V_149 ) | ~ V_150 ) & ~ V_519 ) ;
F_3 ( V_498 ,
( F_13 ( V_498 ) & V_150 ) | V_519 ) ;
F_4 ( V_498 ) ;
F_232 ( V_7 ) ;
return 0 ;
}
static int F_237 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
T_2 V_516 ;
T_2 V_522 ;
T_2 V_523 = V_524 ;
V_522 = V_220 ;
V_522 |= V_525 |
V_467 |
V_526 |
V_468 ;
V_1 -> V_4 = ( ~ V_522 ) |
V_467 |
V_468 ;
F_3 ( V_503 , 0 ) ;
F_4 ( V_503 ) ;
F_3 ( V_466 , V_1 -> V_4 ) ;
F_3 ( V_411 , V_522 ) ;
F_3 ( V_212 , 0xffffffff ) ;
F_3 ( F_27 ( 0 ) , 0xffff ) ;
F_3 ( F_27 ( 1 ) , 0xffff ) ;
F_4 ( V_411 ) ;
F_26 ( V_1 , 0 , V_523 ) ;
F_26 ( V_1 , 0 , V_527 ) ;
F_26 ( V_1 , 1 , V_523 ) ;
F_3 ( V_212 , 0xffffffff ) ;
F_3 ( V_212 , 0xffffffff ) ;
F_3 ( V_213 , F_13 ( V_213 ) ) ;
F_3 ( V_172 , V_1 -> V_170 ) ;
V_516 = V_179 | V_182 |
V_184 ;
F_3 ( V_410 , V_516 ) ;
F_4 ( V_410 ) ;
#if 0
I915_WRITE(DPINVGTT, DPINVGTT_STATUS_MASK);
I915_WRITE(DPINVGTT, DPINVGTT_EN_MASK);
#endif
F_3 ( V_528 , V_529 ) ;
return 0 ;
}
static void F_238 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
int V_12 ;
if ( ! V_1 )
return;
F_239 ( & V_1 -> V_116 ) ;
F_7 (pipe)
F_3 ( F_27 ( V_12 ) , 0xffff ) ;
F_3 ( V_497 , 0xffffffff ) ;
F_3 ( V_503 , 0 ) ;
F_3 ( V_222 , F_13 ( V_222 ) ) ;
F_7 (pipe)
F_3 ( F_27 ( V_12 ) , 0xffff ) ;
F_3 ( V_212 , 0xffffffff ) ;
F_3 ( V_466 , 0xffffffff ) ;
F_3 ( V_411 , 0x0 ) ;
F_4 ( V_411 ) ;
}
static void F_240 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
if ( ! V_1 )
return;
F_239 ( & V_1 -> V_116 ) ;
F_3 ( V_497 , 0xffffffff ) ;
F_3 ( V_5 , 0xffffffff ) ;
F_3 ( V_265 , 0x0 ) ;
F_3 ( V_268 , F_13 ( V_268 ) ) ;
if ( F_19 ( V_7 ) )
F_3 ( V_21 , F_13 ( V_21 ) ) ;
F_3 ( V_172 , 0xffffffff ) ;
F_3 ( V_410 , 0x0 ) ;
F_3 ( V_213 , F_13 ( V_213 ) ) ;
if ( F_118 ( V_7 ) )
return;
F_3 ( V_29 , 0xffffffff ) ;
F_3 ( V_267 , 0x0 ) ;
F_3 ( V_274 , F_13 ( V_274 ) ) ;
if ( F_123 ( V_7 ) || F_22 ( V_7 ) )
F_3 ( V_32 , F_13 ( V_32 ) ) ;
}
static void F_241 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
int V_12 ;
F_129 ( & V_1 -> V_211 , 0 ) ;
F_7 (pipe)
F_3 ( F_27 ( V_12 ) , 0 ) ;
F_68 ( V_530 , 0xffff ) ;
F_68 ( V_412 , 0x0 ) ;
F_242 ( V_412 ) ;
}
static int F_243 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
F_68 ( V_440 ,
~ ( V_436 | V_437 ) ) ;
V_1 -> V_4 =
~ ( V_525 |
V_526 |
V_531 |
V_532 |
V_442 ) ;
F_68 ( V_530 , V_1 -> V_4 ) ;
F_68 ( V_412 ,
V_525 |
V_526 |
V_442 |
V_533 ) ;
F_242 ( V_412 ) ;
return 0 ;
}
static bool F_244 ( struct V_6 * V_7 ,
int V_12 , T_8 V_207 )
{
T_1 * V_1 = V_7 -> V_9 ;
T_8 V_534 = F_245 ( V_12 ) ;
if ( ! F_105 ( V_7 , V_12 ) )
return false ;
if ( ( V_207 & V_534 ) == 0 )
return false ;
F_106 ( V_7 , V_12 ) ;
if ( F_185 ( V_535 ) & V_534 )
return false ;
F_107 ( V_7 , V_12 ) ;
return true ;
}
static T_5 F_246 ( int V_205 , void * V_206 )
{
struct V_6 * V_7 = (struct V_6 * ) V_206 ;
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
T_8 V_207 , V_536 ;
T_2 V_209 [ 2 ] ;
unsigned long V_46 ;
int V_211 ;
int V_12 ;
T_8 V_537 =
V_531 |
V_532 ;
F_104 ( & V_1 -> V_211 ) ;
V_207 = F_185 ( V_441 ) ;
if ( V_207 == 0 )
return V_208 ;
while ( V_207 & ~ V_537 ) {
F_16 ( & V_1 -> V_3 , V_46 ) ;
if ( V_207 & V_442 )
F_93 ( V_7 , false ) ;
F_7 (pipe) {
int V_44 = F_27 ( V_12 ) ;
V_209 [ V_12 ] = F_13 ( V_44 ) ;
if ( V_209 [ V_12 ] & 0x8000ffff ) {
if ( V_209 [ V_12 ] & V_217 )
F_36 ( L_20 ,
F_37 ( V_12 ) ) ;
F_3 ( V_44 , V_209 [ V_12 ] ) ;
V_211 = 1 ;
}
}
F_20 ( & V_1 -> V_3 , V_46 ) ;
F_68 ( V_441 , V_207 & ~ V_537 ) ;
V_536 = F_185 ( V_441 ) ;
F_247 ( V_7 ) ;
if ( V_207 & V_533 )
F_70 ( V_7 , & V_1 -> V_137 [ V_181 ] ) ;
if ( V_209 [ 0 ] & V_218 &&
F_244 ( V_7 , 0 , V_207 ) )
V_537 &= ~ F_245 ( 0 ) ;
if ( V_209 [ 1 ] & V_218 &&
F_244 ( V_7 , 1 , V_207 ) )
V_537 &= ~ F_245 ( 1 ) ;
V_207 = V_536 ;
}
return V_216 ;
}
static void F_248 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
int V_12 ;
F_7 (pipe) {
F_3 ( F_27 ( V_12 ) , 0 ) ;
F_3 ( F_27 ( V_12 ) , F_13 ( F_27 ( V_12 ) ) ) ;
}
F_68 ( V_530 , 0xffff ) ;
F_68 ( V_412 , 0x0 ) ;
F_68 ( V_441 , F_185 ( V_441 ) ) ;
}
static void F_249 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
int V_12 ;
F_129 ( & V_1 -> V_211 , 0 ) ;
if ( F_250 ( V_7 ) ) {
F_3 ( V_503 , 0 ) ;
F_3 ( V_222 , F_13 ( V_222 ) ) ;
}
F_68 ( V_497 , 0xeffe ) ;
F_7 (pipe)
F_3 ( F_27 ( V_12 ) , 0 ) ;
F_3 ( V_530 , 0xffffffff ) ;
F_3 ( V_412 , 0x0 ) ;
F_4 ( V_412 ) ;
}
static int F_251 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
T_2 V_522 ;
F_3 ( V_440 , ~ ( V_436 | V_437 ) ) ;
V_1 -> V_4 =
~ ( V_538 |
V_525 |
V_526 |
V_531 |
V_532 |
V_442 ) ;
V_522 =
V_538 |
V_525 |
V_526 |
V_442 |
V_533 ;
if ( F_250 ( V_7 ) ) {
F_3 ( V_503 , 0 ) ;
F_4 ( V_503 ) ;
V_522 |= V_220 ;
V_1 -> V_4 &= ~ V_220 ;
}
F_3 ( V_530 , V_1 -> V_4 ) ;
F_3 ( V_412 , V_522 ) ;
F_4 ( V_412 ) ;
F_29 ( V_7 ) ;
return 0 ;
}
static bool F_252 ( struct V_6 * V_7 ,
int V_454 , int V_12 , T_2 V_207 )
{
T_1 * V_1 = V_7 -> V_9 ;
T_2 V_534 = F_245 ( V_454 ) ;
if ( ! F_105 ( V_7 , V_12 ) )
return false ;
if ( ( V_207 & V_534 ) == 0 )
return false ;
F_106 ( V_7 , V_454 ) ;
if ( F_13 ( V_535 ) & V_534 )
return false ;
F_107 ( V_7 , V_12 ) ;
return true ;
}
static T_5 F_253 ( int V_205 , void * V_206 )
{
struct V_6 * V_7 = (struct V_6 * ) V_206 ;
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
T_2 V_207 , V_536 , V_209 [ V_210 ] ;
unsigned long V_46 ;
T_2 V_537 =
V_531 |
V_532 ;
int V_12 , V_39 = V_208 ;
F_104 ( & V_1 -> V_211 ) ;
V_207 = F_13 ( V_441 ) ;
do {
bool V_211 = ( V_207 & ~ V_537 ) != 0 ;
bool V_539 = false ;
F_16 ( & V_1 -> V_3 , V_46 ) ;
if ( V_207 & V_442 )
F_93 ( V_7 , false ) ;
F_7 (pipe) {
int V_44 = F_27 ( V_12 ) ;
V_209 [ V_12 ] = F_13 ( V_44 ) ;
if ( V_209 [ V_12 ] & 0x8000ffff ) {
if ( V_209 [ V_12 ] & V_217 )
F_36 ( L_20 ,
F_37 ( V_12 ) ) ;
F_3 ( V_44 , V_209 [ V_12 ] ) ;
V_211 = true ;
}
}
F_20 ( & V_1 -> V_3 , V_46 ) ;
if ( ! V_211 )
break;
if ( ( F_250 ( V_7 ) ) &&
( V_207 & V_220 ) ) {
T_2 V_221 = F_13 ( V_222 ) ;
T_2 V_189 = V_221 & V_223 ;
F_36 ( L_21 ,
V_221 ) ;
F_95 ( V_7 , V_189 , V_224 ) ;
F_3 ( V_222 , V_221 ) ;
F_4 ( V_222 ) ;
}
F_3 ( V_441 , V_207 & ~ V_537 ) ;
V_536 = F_13 ( V_441 ) ;
if ( V_207 & V_533 )
F_70 ( V_7 , & V_1 -> V_137 [ V_181 ] ) ;
F_7 (pipe) {
int V_454 = V_12 ;
if ( F_30 ( V_7 ) )
V_454 = ! V_454 ;
if ( V_209 [ V_12 ] & V_218 &&
F_252 ( V_7 , V_454 , V_12 , V_207 ) )
V_537 &= ~ F_245 ( V_454 ) ;
if ( V_209 [ V_12 ] & V_540 )
V_539 = true ;
}
if ( V_539 || ( V_207 & V_538 ) )
F_119 ( V_7 ) ;
V_39 = V_216 ;
V_207 = V_536 ;
} while ( V_207 & ~ V_537 );
F_247 ( V_7 ) ;
return V_39 ;
}
static void F_254 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
int V_12 ;
F_239 ( & V_1 -> V_116 ) ;
if ( F_250 ( V_7 ) ) {
F_3 ( V_503 , 0 ) ;
F_3 ( V_222 , F_13 ( V_222 ) ) ;
}
F_68 ( V_497 , 0xffff ) ;
F_7 (pipe) {
F_3 ( F_27 ( V_12 ) , 0 ) ;
F_3 ( F_27 ( V_12 ) , F_13 ( F_27 ( V_12 ) ) ) ;
}
F_3 ( V_530 , 0xffffffff ) ;
F_3 ( V_412 , 0x0 ) ;
F_3 ( V_441 , F_13 ( V_441 ) ) ;
}
static void F_255 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
int V_12 ;
F_129 ( & V_1 -> V_211 , 0 ) ;
F_3 ( V_503 , 0 ) ;
F_3 ( V_222 , F_13 ( V_222 ) ) ;
F_3 ( V_497 , 0xeffe ) ;
F_7 (pipe)
F_3 ( F_27 ( V_12 ) , 0 ) ;
F_3 ( V_530 , 0xffffffff ) ;
F_3 ( V_412 , 0x0 ) ;
F_4 ( V_412 ) ;
}
static int F_256 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
T_2 V_522 ;
T_2 V_541 ;
V_1 -> V_4 = ~ ( V_538 |
V_220 |
V_525 |
V_526 |
V_531 |
V_532 |
V_442 ) ;
V_522 = ~ V_1 -> V_4 ;
V_522 &= ~ ( V_531 |
V_532 ) ;
V_522 |= V_533 ;
if ( F_193 ( V_7 ) )
V_522 |= V_542 ;
F_26 ( V_1 , 0 , V_527 ) ;
if ( F_193 ( V_7 ) ) {
V_541 = ~ ( V_434 |
V_428 |
V_429 |
V_437 ) ;
} else {
V_541 = ~ ( V_436 |
V_437 ) ;
}
F_3 ( V_440 , V_541 ) ;
F_3 ( V_530 , V_1 -> V_4 ) ;
F_3 ( V_412 , V_522 ) ;
F_4 ( V_412 ) ;
F_3 ( V_503 , 0 ) ;
F_4 ( V_503 ) ;
F_29 ( V_7 ) ;
return 0 ;
}
static void F_257 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
struct V_98 * V_89 = & V_7 -> V_89 ;
struct V_100 * V_100 ;
T_2 V_543 ;
F_2 ( & V_1 -> V_3 ) ;
if ( F_250 ( V_7 ) ) {
V_543 = F_13 ( V_503 ) ;
V_543 &= ~ V_544 ;
F_59 (intel_encoder, &mode_config->encoder_list, base.head)
if ( V_1 -> V_108 [ V_100 -> V_106 ] . V_109 == V_194 )
V_543 |= V_545 [ V_100 -> V_106 ] ;
if ( F_193 ( V_7 ) )
V_543 |= V_546 ;
V_543 &= ~ V_547 ;
V_543 |= V_548 ;
F_3 ( V_503 , V_543 ) ;
}
}
static T_5 F_258 ( int V_205 , void * V_206 )
{
struct V_6 * V_7 = (struct V_6 * ) V_206 ;
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
T_2 V_207 , V_536 ;
T_2 V_209 [ V_210 ] ;
unsigned long V_46 ;
int V_211 ;
int V_39 = V_208 , V_12 ;
T_2 V_537 =
V_531 |
V_532 ;
F_104 ( & V_1 -> V_211 ) ;
V_207 = F_13 ( V_441 ) ;
for (; ; ) {
bool V_539 = false ;
V_211 = ( V_207 & ~ V_537 ) != 0 ;
F_16 ( & V_1 -> V_3 , V_46 ) ;
if ( V_207 & V_442 )
F_93 ( V_7 , false ) ;
F_7 (pipe) {
int V_44 = F_27 ( V_12 ) ;
V_209 [ V_12 ] = F_13 ( V_44 ) ;
if ( V_209 [ V_12 ] & 0x8000ffff ) {
if ( V_209 [ V_12 ] & V_217 )
F_36 ( L_20 ,
F_37 ( V_12 ) ) ;
F_3 ( V_44 , V_209 [ V_12 ] ) ;
V_211 = 1 ;
}
}
F_20 ( & V_1 -> V_3 , V_46 ) ;
if ( ! V_211 )
break;
V_39 = V_216 ;
if ( V_207 & V_220 ) {
T_2 V_221 = F_13 ( V_222 ) ;
T_2 V_189 = V_221 & ( F_193 ( V_7 ) ?
V_549 :
V_223 ) ;
F_36 ( L_21 ,
V_221 ) ;
F_95 ( V_7 , V_189 ,
F_193 ( V_7 ) ? V_550 : V_224 ) ;
F_3 ( V_222 , V_221 ) ;
F_13 ( V_222 ) ;
}
F_3 ( V_441 , V_207 & ~ V_537 ) ;
V_536 = F_13 ( V_441 ) ;
if ( V_207 & V_533 )
F_70 ( V_7 , & V_1 -> V_137 [ V_181 ] ) ;
if ( V_207 & V_542 )
F_70 ( V_7 , & V_1 -> V_137 [ V_183 ] ) ;
F_7 (pipe) {
if ( V_209 [ V_12 ] & V_551 &&
F_252 ( V_7 , V_12 , V_12 , V_207 ) )
V_537 &= ~ F_245 ( V_12 ) ;
if ( V_209 [ V_12 ] & V_540 )
V_539 = true ;
}
if ( V_539 || ( V_207 & V_538 ) )
F_119 ( V_7 ) ;
if ( V_209 [ 0 ] & V_225 )
F_99 ( V_7 ) ;
V_207 = V_536 ;
}
F_247 ( V_7 ) ;
return V_39 ;
}
static void F_259 ( struct V_6 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_7 -> V_9 ;
int V_12 ;
if ( ! V_1 )
return;
F_239 ( & V_1 -> V_116 ) ;
F_3 ( V_503 , 0 ) ;
F_3 ( V_222 , F_13 ( V_222 ) ) ;
F_3 ( V_497 , 0xffffffff ) ;
F_7 (pipe)
F_3 ( F_27 ( V_12 ) , 0 ) ;
F_3 ( V_530 , 0xffffffff ) ;
F_3 ( V_412 , 0x0 ) ;
F_7 (pipe)
F_3 ( F_27 ( V_12 ) ,
F_13 ( F_27 ( V_12 ) ) & 0x8000ffff ) ;
F_3 ( V_441 , F_13 ( V_441 ) ) ;
}
static void F_260 ( unsigned long V_489 )
{
T_1 * V_1 = ( T_1 * ) V_489 ;
struct V_6 * V_7 = V_1 -> V_7 ;
struct V_98 * V_89 = & V_7 -> V_89 ;
unsigned long V_46 ;
int V_191 ;
F_16 ( & V_1 -> V_3 , V_46 ) ;
for ( V_191 = ( V_107 + 1 ) ; V_191 < V_193 ; V_191 ++ ) {
struct V_85 * V_86 ;
if ( V_1 -> V_108 [ V_191 ] . V_109 != V_113 )
continue;
V_1 -> V_108 [ V_191 ] . V_109 = V_194 ;
F_59 (connector, &mode_config->connector_list, head) {
struct V_99 * V_99 = F_60 ( V_86 ) ;
if ( V_99 -> V_105 -> V_106 == V_191 ) {
if ( V_86 -> V_111 != V_99 -> V_111 )
F_36 ( L_68 ,
F_55 ( V_86 ) ) ;
V_86 -> V_111 = V_99 -> V_111 ;
if ( ! V_86 -> V_111 )
V_86 -> V_111 = V_112 ;
}
}
}
if ( V_1 -> V_199 . V_200 )
V_1 -> V_199 . V_200 ( V_7 ) ;
F_20 ( & V_1 -> V_3 , V_46 ) ;
}
void F_261 ( struct V_6 * V_7 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
F_262 ( & V_1 -> V_97 , F_56 ) ;
F_262 ( & V_1 -> V_142 . V_96 , F_124 ) ;
F_262 ( & V_1 -> V_145 . V_96 , F_74 ) ;
F_262 ( & V_1 -> V_156 . V_157 , F_81 ) ;
F_263 ( & V_1 -> V_142 . V_143 ,
F_221 ,
( unsigned long ) V_7 ) ;
F_263 ( & V_1 -> V_116 , F_260 ,
( unsigned long ) V_1 ) ;
F_264 ( & V_1 -> V_552 , V_553 , V_554 ) ;
V_7 -> V_555 -> V_556 = F_35 ;
V_7 -> V_557 = 0xffffff ;
if ( F_193 ( V_7 ) || F_31 ( V_7 ) -> V_50 >= 5 ) {
V_7 -> V_557 = 0xffffffff ;
V_7 -> V_555 -> V_556 = F_40 ;
}
if ( F_33 ( V_7 , V_51 ) )
V_7 -> V_555 -> V_558 = F_48 ;
else
V_7 -> V_555 -> V_558 = NULL ;
V_7 -> V_555 -> V_559 = F_42 ;
if ( F_77 ( V_7 ) ) {
V_7 -> V_555 -> V_560 = F_103 ;
V_7 -> V_555 -> V_561 = F_229 ;
V_7 -> V_555 -> V_562 = F_237 ;
V_7 -> V_555 -> V_563 = F_238 ;
V_7 -> V_555 -> V_564 = F_204 ;
V_7 -> V_555 -> V_565 = F_209 ;
V_1 -> V_199 . V_200 = F_257 ;
} else if ( F_265 ( V_7 ) || F_116 ( V_7 ) ) {
V_7 -> V_555 -> V_560 = F_115 ;
V_7 -> V_555 -> V_561 = F_228 ;
V_7 -> V_555 -> V_562 = F_235 ;
V_7 -> V_555 -> V_563 = F_240 ;
V_7 -> V_555 -> V_564 = F_203 ;
V_7 -> V_555 -> V_565 = F_208 ;
V_1 -> V_199 . V_200 = F_231 ;
} else if ( F_183 ( V_7 ) ) {
V_7 -> V_555 -> V_560 = F_122 ;
V_7 -> V_555 -> V_561 = F_227 ;
V_7 -> V_555 -> V_562 = F_233 ;
V_7 -> V_555 -> V_563 = F_240 ;
V_7 -> V_555 -> V_564 = F_202 ;
V_7 -> V_555 -> V_565 = F_207 ;
V_1 -> V_199 . V_200 = F_231 ;
} else {
if ( F_31 ( V_7 ) -> V_50 == 2 ) {
V_7 -> V_555 -> V_561 = F_241 ;
V_7 -> V_555 -> V_562 = F_243 ;
V_7 -> V_555 -> V_560 = F_246 ;
V_7 -> V_555 -> V_563 = F_248 ;
} else if ( F_31 ( V_7 ) -> V_50 == 3 ) {
V_7 -> V_555 -> V_561 = F_249 ;
V_7 -> V_555 -> V_562 = F_251 ;
V_7 -> V_555 -> V_563 = F_254 ;
V_7 -> V_555 -> V_560 = F_253 ;
V_1 -> V_199 . V_200 = F_257 ;
} else {
V_7 -> V_555 -> V_561 = F_255 ;
V_7 -> V_555 -> V_562 = F_256 ;
V_7 -> V_555 -> V_563 = F_259 ;
V_7 -> V_555 -> V_560 = F_258 ;
V_1 -> V_199 . V_200 = F_257 ;
}
V_7 -> V_555 -> V_564 = F_200 ;
V_7 -> V_555 -> V_565 = F_205 ;
}
}
void F_266 ( struct V_6 * V_7 )
{
struct V_8 * V_1 = V_7 -> V_9 ;
struct V_98 * V_89 = & V_7 -> V_89 ;
struct V_85 * V_86 ;
unsigned long V_46 ;
int V_191 ;
for ( V_191 = 1 ; V_191 < V_193 ; V_191 ++ ) {
V_1 -> V_108 [ V_191 ] . V_197 = 0 ;
V_1 -> V_108 [ V_191 ] . V_109 = V_194 ;
}
F_59 (connector, &mode_config->connector_list, head) {
struct V_99 * V_99 = F_60 ( V_86 ) ;
V_86 -> V_111 = V_99 -> V_111 ;
if ( ! V_86 -> V_111 && F_250 ( V_7 ) && V_99 -> V_105 -> V_106 > V_107 )
V_86 -> V_111 = V_112 ;
}
F_16 ( & V_1 -> V_3 , V_46 ) ;
if ( V_1 -> V_199 . V_200 )
V_1 -> V_199 . V_200 ( V_7 ) ;
F_20 ( & V_1 -> V_3 , V_46 ) ;
}
