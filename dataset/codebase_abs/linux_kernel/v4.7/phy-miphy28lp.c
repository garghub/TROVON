static inline void F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
T_2 V_4 ;
F_2 ( V_5 , V_3 + V_6 ) ;
V_4 = V_5 | V_7 ;
F_2 ( V_4 , V_3 + V_6 ) ;
F_2 ( V_5 , V_3 + V_6 ) ;
if ( V_2 -> type == V_8 ) {
V_4 = V_9 | V_10 ;
F_2 ( V_4 , V_3 + V_11 ) ;
} else {
V_4 = V_9 | V_10 | V_12 ;
F_2 ( V_4 , V_3 + V_11 ) ;
}
}
static inline void F_3 ( struct V_1 * V_2 ,
struct V_13 * V_13 )
{
void T_1 * V_3 = V_2 -> V_3 ;
T_2 V_4 ;
F_2 ( 0x1d , V_3 + V_14 ) ;
F_2 ( V_13 -> V_15 , V_3 + V_16 ) ;
F_2 ( V_13 -> V_17 , V_3 + V_18 ) ;
F_2 ( V_13 -> V_19 , V_3 + V_20 ) ;
F_2 ( V_13 -> V_21 , V_3 + V_22 ) ;
F_2 ( V_13 -> V_23 , V_3 + V_24 ) ;
F_2 ( V_13 -> V_25 , V_3 + V_26 ) ;
F_2 ( V_27 , V_3 + V_28 ) ;
V_4 = ( 0x68 << 1 ) | V_29 ;
F_2 ( V_4 , V_3 + V_30 ) ;
V_4 = V_31 | V_32 | V_33 ;
if ( V_2 -> type != V_34 )
V_4 |= V_35 ;
F_2 ( V_4 , V_3 + V_36 ) ;
if ( V_2 -> type == V_37 ) {
F_2 ( 0x00 , V_3 + V_38 ) ;
F_2 ( 0x70 , V_3 + V_39 ) ;
F_2 ( V_40 , V_3 + V_41 ) ;
F_2 ( V_40 , V_3 + V_42 ) ;
F_2 ( V_40 , V_3 + V_43 ) ;
V_4 = V_44 | V_40 ;
F_2 ( V_4 , V_3 + V_45 ) ;
}
}
static inline void F_4 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_5 ( V_47 ) ; V_46 ++ ) {
struct V_48 * V_49 = & V_47 [ V_46 ] ;
F_2 ( V_49 -> V_50 , V_3 + V_38 ) ;
F_2 ( V_49 -> V_51 , V_3 + V_52 ) ;
F_2 ( V_49 -> V_53 , V_3 + V_54 ) ;
F_2 ( V_49 -> V_55 , V_3 + V_56 ) ;
F_2 ( V_49 -> V_57 , V_3 + V_58 ) ;
F_2 ( V_49 -> V_59 , V_3 + V_60 ) ;
F_2 ( V_49 -> V_61 , V_3 + V_62 ) ;
F_2 ( V_49 -> V_63 , V_3 + V_64 ) ;
F_2 ( V_49 -> V_65 , V_3 + V_66 ) ;
F_2 ( V_49 -> V_67 , V_3 + V_68 ) ;
F_2 ( V_49 -> V_69 , V_3 + V_70 ) ;
}
}
static inline void F_6 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_5 ( V_71 ) ; V_46 ++ ) {
struct V_48 * V_49 = & V_71 [ V_46 ] ;
F_2 ( V_49 -> V_50 , V_3 + V_38 ) ;
F_2 ( V_49 -> V_51 , V_3 + V_52 ) ;
F_2 ( V_49 -> V_53 , V_3 + V_54 ) ;
F_2 ( V_49 -> V_55 , V_3 + V_56 ) ;
F_2 ( V_49 -> V_72 , V_3 + V_73 ) ;
F_2 ( V_49 -> V_57 , V_3 + V_58 ) ;
F_2 ( V_49 -> V_59 , V_3 + V_60 ) ;
F_2 ( V_49 -> V_74 , V_3 + V_75 ) ;
F_2 ( V_49 -> V_61 , V_3 + V_62 ) ;
F_2 ( V_49 -> V_63 , V_3 + V_64 ) ;
F_2 ( V_49 -> V_65 , V_3 + V_66 ) ;
F_2 ( V_49 -> V_67 , V_3 + V_68 ) ;
}
}
static inline int F_7 ( struct V_1 * V_2 )
{
unsigned long V_76 = V_77 + 5 * V_78 ;
T_2 V_4 ;
do {
V_4 = F_8 ( V_2 -> V_3 + V_79 ) ;
if ( F_9 ( V_77 , V_76 ) )
return - V_80 ;
F_10 () ;
} while ( ! ( V_4 & V_81 ) );
return 0 ;
}
static inline int F_11 ( struct V_1 * V_2 ,
struct V_13 * V_13 )
{
void T_1 * V_3 = V_2 -> V_3 ;
F_2 ( V_82 | V_83 , V_3 + V_84 ) ;
F_2 ( 0x00 , V_3 + V_85 ) ;
F_2 ( V_13 -> V_15 , V_3 + V_16 ) ;
F_2 ( V_86 , V_3 + V_87 ) ;
if ( V_2 -> type == V_8 )
F_2 ( V_82 , V_3 + V_84 ) ;
F_2 ( 0x00 , V_3 + V_84 ) ;
F_2 ( V_88 , V_3 + V_85 ) ;
F_2 ( V_89 , V_3 + V_90 ) ;
F_2 ( 0x00 , V_3 + V_91 ) ;
if ( V_2 -> type == V_8 )
return F_7 ( V_2 ) ;
return 0 ;
}
static inline void F_12 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
T_2 V_4 ;
F_2 ( V_5 , V_3 + V_6 ) ;
F_2 ( 0x00 , V_3 + V_6 ) ;
F_2 ( V_83 , V_3 + V_84 ) ;
V_4 = V_83 | V_82 ;
F_2 ( V_4 , V_3 + V_84 ) ;
F_2 ( 0x00 , V_3 + V_85 ) ;
F_2 ( 0x1e , V_3 + V_16 ) ;
F_2 ( V_86 , V_3 + V_87 ) ;
F_2 ( V_82 , V_3 + V_84 ) ;
F_2 ( 0x00 , V_3 + V_84 ) ;
F_2 ( V_88 , V_3 + V_85 ) ;
F_2 ( 0x00 , V_3 + V_38 ) ;
F_2 ( 0x00 , V_3 + V_92 ) ;
F_2 ( 0x00 , V_3 + V_93 ) ;
F_2 ( 0x00 , V_3 + V_38 ) ;
F_2 ( V_89 , V_3 + V_90 ) ;
F_2 ( 0xa5 , V_3 + V_94 ) ;
F_2 ( 0x00 , V_3 + V_38 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
T_2 V_4 ;
V_4 = F_8 ( V_3 + V_95 ) ;
V_4 |= V_96 ;
F_2 ( V_4 , V_3 + V_95 ) ;
V_4 = F_8 ( V_3 + V_28 ) ;
V_4 |= V_97 ;
F_2 ( V_4 , V_3 + V_28 ) ;
for ( V_4 = 0 ; V_4 < V_98 ; V_4 ++ ) {
F_2 ( V_4 , V_3 + V_38 ) ;
F_2 ( 0x3c , V_3 + V_99 ) ;
F_2 ( 0x6c , V_3 + V_100 ) ;
F_2 ( 0x81 , V_3 + V_101 ) ;
F_2 ( 0x00 , V_3 + V_90 ) ;
F_2 ( V_89 , V_3 + V_90 ) ;
F_2 ( 0x00 , V_3 + V_90 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
T_2 V_4 ;
V_4 = F_8 ( V_3 + V_95 ) ;
V_4 |= V_96 ;
F_2 ( V_4 , V_3 + V_95 ) ;
V_4 = F_8 ( V_3 + V_28 ) ;
V_4 |= V_97 ;
F_2 ( V_4 , V_3 + V_28 ) ;
for ( V_4 = 0 ; V_4 < V_102 ; V_4 ++ ) {
F_2 ( V_4 , V_3 + V_38 ) ;
F_2 ( 0x69 , V_3 + V_100 ) ;
F_2 ( 0x21 , V_3 + V_101 ) ;
F_2 ( 0x3c , V_3 + V_99 ) ;
F_2 ( 0x21 , V_3 + V_101 ) ;
F_2 ( 0x00 , V_3 + V_90 ) ;
F_2 ( V_89 , V_3 + V_90 ) ;
F_2 ( 0x00 , V_3 + V_90 ) ;
}
}
static inline void F_15 ( struct V_1 * V_2 )
{
F_2 ( 0x02 , V_2 -> V_3 + V_91 ) ;
}
static inline int F_16 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
int V_103 ;
T_2 V_4 ;
F_1 ( V_2 ) ;
F_3 ( V_2 , & V_104 ) ;
F_4 ( V_2 ) ;
F_2 ( 0x21 , V_3 + V_105 ) ;
F_2 ( 0x00 , V_3 + V_6 ) ;
V_103 = F_11 ( V_2 , & V_104 ) ;
if ( V_103 )
return V_103 ;
if ( V_2 -> V_106 ) {
V_4 = F_8 ( V_2 -> V_3 + V_11 ) ;
V_4 |= V_107 ;
F_2 ( V_4 , V_2 -> V_3 + V_11 ) ;
}
if ( V_2 -> V_108 )
F_13 ( V_2 ) ;
if ( V_2 -> V_109 )
F_15 ( V_2 ) ;
return 0 ;
}
static inline int F_17 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
int V_103 ;
F_1 ( V_2 ) ;
F_3 ( V_2 , & V_110 ) ;
F_6 ( V_2 ) ;
F_2 ( 0x21 , V_3 + V_105 ) ;
F_2 ( 0x00 , V_3 + V_6 ) ;
V_103 = F_11 ( V_2 , & V_110 ) ;
if ( V_103 )
return V_103 ;
if ( V_2 -> V_108 )
F_14 ( V_2 ) ;
if ( V_2 -> V_109 )
F_15 ( V_2 ) ;
return 0 ;
}
static inline void F_18 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_3 ;
T_2 V_4 ;
F_1 ( V_2 ) ;
F_3 ( V_2 , & V_111 ) ;
F_2 ( 0x00 , V_3 + V_38 ) ;
V_4 = V_112 | V_113 ;
F_2 ( V_4 , V_3 + V_52 ) ;
F_2 ( 0x1c , V_3 + V_114 ) ;
F_2 ( 0x51 , V_3 + V_115 ) ;
F_2 ( 0x70 , V_3 + V_116 ) ;
V_4 = V_35 | V_31 |
V_32 | V_33 ;
F_2 ( V_4 , V_3 + V_36 ) ;
F_2 ( 0x22 , V_3 + V_117 ) ;
F_2 ( 0x0e , V_3 + V_118 ) ;
V_4 = V_119 | V_120 ;
F_2 ( V_4 , V_3 + V_62 ) ;
F_2 ( 0x78 , V_3 + V_66 ) ;
F_2 ( 0x1b , V_3 + V_121 ) ;
F_2 ( 0x02 , V_3 + V_91 ) ;
V_4 = V_97 | V_122 ;
F_2 ( V_4 , V_3 + V_28 ) ;
F_2 ( 0x00 , V_3 + V_54 ) ;
F_2 ( 0xa7 , V_3 + V_56 ) ;
F_2 ( V_96 , V_3 + V_95 ) ;
F_2 ( 0x00 , V_3 + V_38 ) ;
F_2 ( 0x5a , V_3 + V_100 ) ;
F_2 ( 0xa0 , V_3 + V_101 ) ;
F_2 ( 0x3c , V_3 + V_99 ) ;
F_2 ( 0xa1 , V_3 + V_101 ) ;
F_2 ( 0x00 , V_3 + V_90 ) ;
F_2 ( 0x02 , V_3 + V_90 ) ;
F_2 ( 0x00 , V_3 + V_90 ) ;
F_2 ( 0xca , V_3 + V_75 ) ;
F_2 ( 0x21 , V_3 + V_105 ) ;
F_2 ( 0x29 , V_3 + V_105 ) ;
F_2 ( 0x1a , V_3 + V_123 ) ;
F_12 ( V_2 ) ;
}
static inline int F_19 ( struct V_1 * V_2 )
{
unsigned long V_76 = V_77 + 5 * V_78 ;
T_2 V_124 = V_125 | V_126 ;
T_2 V_4 ;
if ( V_2 -> type == V_34 )
V_124 |= V_127 ;
do {
V_4 = F_8 ( V_2 -> V_3 + V_128 ) ;
if ( ( V_4 & V_124 ) != V_124 )
F_10 () ;
else
return 0 ;
} while ( ! F_9 ( V_77 , V_76 ) );
return - V_80 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_129 * V_130 = V_2 -> V_131 ;
unsigned long V_76 = V_77 + 5 * V_78 ;
T_3 V_4 ;
if ( ! V_2 -> V_132 )
return 0 ;
if ( ! V_2 -> V_133 [ V_134 ] )
return - V_135 ;
do {
F_21 ( V_130 -> V_136 ,
V_2 -> V_133 [ V_134 ] , & V_4 ) ;
if ( ( V_4 & V_137 ) != V_137 )
F_10 () ;
else
return 0 ;
} while ( ! F_9 ( V_77 , V_76 ) );
return - V_80 ;
}
static int F_22 ( struct V_138 * V_139 ,
char * V_140 , struct V_141 * V_142 )
{
int V_143 ;
V_143 = F_23 ( V_139 , L_1 , V_140 ) ;
if ( V_143 < 0 )
return - V_144 ;
return F_24 ( V_139 , V_143 , V_142 ) ;
}
static int F_25 ( struct V_145 * V_146 ,
struct V_138 * V_139 , char * V_140 ,
void T_1 * * V_3 )
{
struct V_141 V_142 ;
int V_147 ;
V_147 = F_22 ( V_139 , V_140 , & V_142 ) ;
if ( ! V_147 ) {
* V_3 = F_26 ( V_146 , V_142 . V_148 , F_27 ( & V_142 ) ) ;
if ( ! * V_3 ) {
F_28 ( V_146 , L_2
, V_140 ) ;
return - V_149 ;
}
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , T_3 V_150 )
{
int V_103 ;
struct V_129 * V_130 = V_2 -> V_131 ;
if ( ! V_2 -> V_133 [ V_151 ] )
return - V_135 ;
V_103 = F_30 ( V_2 -> V_152 ) ;
if ( V_103 ) {
F_28 ( V_130 -> V_146 , L_3 ) ;
return V_103 ;
}
if ( V_2 -> V_153 )
V_150 |= V_154 ;
F_31 ( V_130 -> V_136 ,
V_2 -> V_133 [ V_151 ] ,
V_155 , V_150 ) ;
V_103 = F_32 ( V_2 -> V_152 ) ;
if ( V_103 ) {
F_28 ( V_130 -> V_146 , L_3 ) ;
return V_103 ;
}
return F_20 ( V_2 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_129 * V_130 = V_2 -> V_131 ;
int V_103 , V_156 = V_157 ;
if ( ( ! V_2 -> V_133 [ V_158 ] ) ||
( ! V_2 -> V_133 [ V_159 ] ) ||
( ! V_2 -> V_3 ) )
return - V_135 ;
F_34 ( V_130 -> V_146 , L_4 , V_2 -> V_3 ) ;
V_156 |= ( ( V_2 -> V_160 - V_161 ) << V_162 ) ;
F_31 ( V_130 -> V_136 ,
V_2 -> V_133 [ V_158 ] ,
V_163 , V_156 ) ;
F_31 ( V_130 -> V_136 , V_2 -> V_133 [ V_159 ] ,
V_164 , V_165 ) ;
V_103 = F_29 ( V_2 , V_166 ) ;
if ( V_103 ) {
F_28 ( V_130 -> V_146 , L_5 ) ;
return V_103 ;
}
F_16 ( V_2 ) ;
return F_19 ( V_2 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_129 * V_130 = V_2 -> V_131 ;
int V_103 ;
if ( ( ! V_2 -> V_133 [ V_158 ] ) ||
( ! V_2 -> V_133 [ V_159 ] )
|| ( ! V_2 -> V_3 ) || ( ! V_2 -> V_167 ) )
return - V_135 ;
F_34 ( V_130 -> V_146 , L_6 , V_2 -> V_3 ) ;
F_31 ( V_130 -> V_136 ,
V_2 -> V_133 [ V_158 ] ,
V_163 , V_165 ) ;
F_31 ( V_130 -> V_136 , V_2 -> V_133 [ V_159 ] ,
V_164 , V_168 ) ;
V_103 = F_29 ( V_2 , V_166 ) ;
if ( V_103 ) {
F_28 ( V_130 -> V_146 , L_7 ) ;
return V_103 ;
}
V_103 = F_17 ( V_2 ) ;
if ( V_103 )
return V_103 ;
F_2 ( 0x68 , V_2 -> V_167 + 0x104 ) ;
F_2 ( 0x61 , V_2 -> V_167 + 0x105 ) ;
F_2 ( 0x68 , V_2 -> V_167 + 0x108 ) ;
F_2 ( 0x61 , V_2 -> V_167 + 0x109 ) ;
F_2 ( 0x68 , V_2 -> V_167 + 0x10c ) ;
F_2 ( 0x60 , V_2 -> V_167 + 0x10d ) ;
return F_19 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_129 * V_130 = V_2 -> V_131 ;
int V_103 ;
if ( ( ! V_2 -> V_3 ) || ( ! V_2 -> V_167 ) )
return - V_135 ;
F_34 ( V_130 -> V_146 , L_8 , V_2 -> V_3 ) ;
V_103 = F_29 ( V_2 , V_169 ) ;
if ( V_103 ) {
F_28 ( V_130 -> V_146 , L_9 ) ;
return V_103 ;
}
F_18 ( V_2 ) ;
F_2 ( 0x68 , V_2 -> V_167 + 0x23 ) ;
F_2 ( 0x61 , V_2 -> V_167 + 0x24 ) ;
F_2 ( 0x68 , V_2 -> V_167 + 0x26 ) ;
F_2 ( 0x61 , V_2 -> V_167 + 0x27 ) ;
F_2 ( 0x18 , V_2 -> V_167 + 0x29 ) ;
F_2 ( 0x61 , V_2 -> V_167 + 0x2a ) ;
F_2 ( 0X67 , V_2 -> V_167 + 0x68 ) ;
F_2 ( 0x0d , V_2 -> V_167 + 0x69 ) ;
F_2 ( 0X67 , V_2 -> V_167 + 0x6a ) ;
F_2 ( 0X0d , V_2 -> V_167 + 0x6b ) ;
F_2 ( 0X67 , V_2 -> V_167 + 0x6c ) ;
F_2 ( 0X0d , V_2 -> V_167 + 0x6d ) ;
F_2 ( 0X67 , V_2 -> V_167 + 0x6e ) ;
F_2 ( 0X0d , V_2 -> V_167 + 0x6f ) ;
return F_19 ( V_2 ) ;
}
static int F_37 ( struct V_170 * V_170 )
{
struct V_1 * V_2 = F_38 ( V_170 ) ;
struct V_129 * V_130 = V_2 -> V_131 ;
int V_147 ;
F_39 ( & V_130 -> V_171 ) ;
switch ( V_2 -> type ) {
case V_34 :
V_147 = F_33 ( V_2 ) ;
break;
case V_8 :
V_147 = F_35 ( V_2 ) ;
break;
case V_37 :
V_147 = F_36 ( V_2 ) ;
break;
default:
V_147 = - V_135 ;
break;
}
F_40 ( & V_130 -> V_171 ) ;
return V_147 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_129 * V_130 = V_2 -> V_131 ;
struct V_138 * V_172 = V_2 -> V_170 -> V_146 . V_173 ;
int V_103 ;
if ( ( V_2 -> type != V_34 ) &&
( V_2 -> type != V_8 ) &&
( V_2 -> type != V_37 ) ) {
return - V_135 ;
}
V_103 = F_25 ( V_130 -> V_146 , V_172 ,
V_174 [ V_2 -> type - V_34 ] ,
& V_2 -> V_3 ) ;
if ( V_103 )
return V_103 ;
if ( ( V_2 -> type == V_8 ) ||
( V_2 -> type == V_37 ) ) {
V_103 = F_25 ( V_130 -> V_146 , V_172 , L_10 ,
& V_2 -> V_167 ) ;
if ( V_103 )
return V_103 ;
}
return 0 ;
}
static struct V_170 * F_42 ( struct V_145 * V_146 ,
struct V_175 * args )
{
struct V_129 * V_130 = F_43 ( V_146 ) ;
struct V_1 * V_2 = NULL ;
struct V_138 * V_172 = args -> V_176 ;
int V_147 , V_143 = 0 ;
if ( args -> V_177 != 1 ) {
F_28 ( V_146 , L_11 ) ;
return F_44 ( - V_135 ) ;
}
for ( V_143 = 0 ; V_143 < V_130 -> V_178 ; V_143 ++ )
if ( V_172 == V_130 -> V_179 [ V_143 ] -> V_170 -> V_146 . V_173 ) {
V_2 = V_130 -> V_179 [ V_143 ] ;
break;
}
if ( ! V_2 ) {
F_28 ( V_146 , L_12 ) ;
return F_44 ( - V_135 ) ;
}
V_2 -> type = args -> args [ 0 ] ;
V_147 = F_41 ( V_2 ) ;
if ( V_147 < 0 )
return F_44 ( V_147 ) ;
return V_2 -> V_170 ;
}
static int F_45 ( struct V_138 * V_180 ,
struct V_1 * V_2 )
{
struct V_129 * V_130 = V_2 -> V_131 ;
int V_103 ;
V_2 -> V_152 =
F_46 ( V_180 , L_13 ) ;
if ( F_47 ( V_2 -> V_152 ) ) {
F_28 ( V_130 -> V_146 ,
L_14 ) ;
return F_48 ( V_2 -> V_152 ) ;
}
V_103 = F_32 ( V_2 -> V_152 ) ;
if ( V_103 ) {
F_28 ( V_130 -> V_146 , L_3 ) ;
return V_103 ;
}
return 0 ;
}
static int F_49 ( struct V_138 * V_176 ,
struct V_1 * V_2 )
{
int V_46 ;
T_3 V_181 ;
V_2 -> V_153 =
F_50 ( V_176 , L_15 ) ;
V_2 -> V_132 = F_50 ( V_176 , L_16 ) ;
V_2 -> V_106 =
F_50 ( V_176 , L_17 ) ;
V_2 -> V_108 = F_50 ( V_176 , L_18 ) ;
V_2 -> V_109 =
F_50 ( V_176 , L_19 ) ;
F_51 ( V_176 , L_20 , & V_2 -> V_160 ) ;
if ( ! V_2 -> V_160 )
V_2 -> V_160 = V_161 ;
for ( V_46 = 0 ; V_46 < V_182 ; V_46 ++ ) {
if ( ! F_52 ( V_176 , L_21 , V_46 , & V_181 ) )
V_2 -> V_133 [ V_46 ] = V_181 ;
}
return 0 ;
}
static int F_53 ( struct V_183 * V_184 )
{
struct V_138 * V_139 , * V_176 = V_184 -> V_146 . V_173 ;
struct V_129 * V_130 ;
struct V_185 * V_186 ;
struct V_170 * V_170 ;
int V_147 , V_187 = 0 ;
V_130 = F_54 ( & V_184 -> V_146 , sizeof( * V_130 ) , V_188 ) ;
if ( ! V_130 )
return - V_189 ;
V_130 -> V_178 = F_55 ( V_176 ) ;
V_130 -> V_179 = F_56 ( & V_184 -> V_146 , V_130 -> V_178 ,
sizeof( * V_130 -> V_179 ) , V_188 ) ;
if ( ! V_130 -> V_179 )
return - V_189 ;
V_130 -> V_136 = F_57 ( V_176 , L_21 ) ;
if ( F_47 ( V_130 -> V_136 ) ) {
F_28 ( V_130 -> V_146 , L_22 ) ;
return F_48 ( V_130 -> V_136 ) ;
}
V_130 -> V_146 = & V_184 -> V_146 ;
F_58 ( & V_184 -> V_146 , V_130 ) ;
F_59 ( & V_130 -> V_171 ) ;
F_60 (np, child) {
struct V_1 * V_2 ;
V_2 = F_54 ( & V_184 -> V_146 , sizeof( * V_2 ) ,
V_188 ) ;
if ( ! V_2 ) {
V_147 = - V_189 ;
goto V_190;
}
V_130 -> V_179 [ V_187 ] = V_2 ;
V_170 = F_61 ( & V_184 -> V_146 , V_139 , & V_191 ) ;
if ( F_47 ( V_170 ) ) {
F_28 ( & V_184 -> V_146 , L_23 ) ;
V_147 = F_48 ( V_170 ) ;
goto V_190;
}
V_130 -> V_179 [ V_187 ] -> V_170 = V_170 ;
V_130 -> V_179 [ V_187 ] -> V_131 = V_130 ;
V_147 = F_49 ( V_139 , V_2 ) ;
if ( V_147 )
goto V_190;
V_147 = F_45 ( V_139 , V_130 -> V_179 [ V_187 ] ) ;
if ( V_147 )
goto V_190;
F_62 ( V_170 , V_130 -> V_179 [ V_187 ] ) ;
V_187 ++ ;
}
V_186 = F_63 ( & V_184 -> V_146 , F_42 ) ;
return F_64 ( V_186 ) ;
V_190:
F_65 ( V_139 ) ;
return V_147 ;
}
