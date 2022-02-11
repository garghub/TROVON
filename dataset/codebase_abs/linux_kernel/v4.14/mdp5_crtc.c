static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static void F_4 ( struct V_2 * V_3 , T_1 V_9 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_6 ( V_9 , & V_10 -> V_9 ) ;
F_7 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
}
static void F_8 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_9 ( & V_10 -> V_13 ) ;
}
static T_2 F_10 ( struct V_2 * V_3 , T_2 V_14 )
{
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
struct V_18 * V_19 = V_16 -> V_19 ;
struct V_20 * V_21 = & V_16 -> V_21 ;
F_12 ( L_1 , V_3 -> V_22 , V_14 ) ;
return F_13 ( V_19 , V_21 , V_14 ) ;
}
static T_2 F_14 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
struct V_23 * V_24 , * V_25 ;
struct V_26 * V_27 ;
T_1 V_14 = 0 ;
if ( F_15 ( ! V_16 -> V_19 ) )
return 0 ;
F_16 (plane, crtc) {
V_14 |= F_17 ( V_27 ) ;
}
V_24 = V_16 -> V_21 . V_24 ;
V_14 |= F_18 ( V_24 -> V_28 ) ;
V_25 = V_16 -> V_21 . V_25 ;
if ( V_25 )
V_14 |= F_18 ( V_25 -> V_28 ) ;
return F_10 ( V_3 , V_14 ) ;
}
static void F_19 ( struct V_2 * V_3 , struct V_29 * V_30 )
{
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
struct V_20 * V_21 = & V_16 -> V_21 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_18 * V_19 = V_16 -> V_19 ;
struct V_31 * V_6 = V_3 -> V_6 ;
struct V_32 * V_33 ;
unsigned long V_34 ;
F_20 ( & V_6 -> V_35 , V_34 ) ;
V_33 = V_10 -> V_33 ;
if ( V_33 ) {
V_10 -> V_33 = NULL ;
F_12 ( L_2 , V_3 -> V_22 , V_33 ) ;
F_21 ( V_3 , V_33 ) ;
}
F_22 ( & V_6 -> V_35 , V_34 ) ;
if ( V_19 && ! V_3 -> V_17 -> V_36 ) {
F_23 ( V_19 , V_21 , NULL , NULL , 0 , 0 ) ;
}
}
static void F_24 ( struct V_37 * V_38 , void * V_39 )
{
struct V_10 * V_10 =
F_25 ( V_38 , struct V_10 , V_40 ) ;
struct V_1 * V_1 = F_1 ( & V_10 -> V_11 ) ;
struct V_41 * V_8 = & V_1 -> V_11 . V_11 ;
F_26 ( V_39 , V_8 -> V_42 ) ;
F_27 ( V_39 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_29 ( V_3 ) ;
F_30 ( & V_10 -> V_40 ) ;
F_31 ( V_10 ) ;
}
static inline T_2 F_32 ( enum V_43 V_44 )
{
switch ( V_44 ) {
case V_45 : return V_46 ;
case V_47 : return V_48 ;
case V_49 : return V_50 ;
case V_51 : return V_52 ;
case V_53 : return V_54 ;
case V_55 : return V_56 ;
case V_57 : return V_58 ;
default:
return 0 ;
}
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
struct V_20 * V_21 = & V_16 -> V_21 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_26 * V_27 ;
const struct V_59 * V_60 ;
struct V_61 * V_62 , * V_63 [ V_64 + 1 ] = { NULL } ;
const struct V_65 * V_66 ;
struct V_23 * V_24 = V_21 -> V_24 ;
T_1 V_28 = V_24 -> V_28 ;
struct V_23 * V_25 = V_21 -> V_25 ;
T_1 V_67 = V_25 ? V_25 -> V_28 : 0 ;
struct V_18 * V_19 = V_16 -> V_19 ;
T_1 V_68 , V_69 , V_70 , V_71 = 0 ;
unsigned long V_34 ;
enum V_72 V_44 [ V_64 + 1 ] [ V_73 ] = { { V_74 } } ;
enum V_72 V_75 [ V_64 + 1 ] [ V_73 ] = { { V_74 } } ;
int V_76 , V_77 = 0 ;
bool V_78 = false ;
T_2 V_79 = 0 ;
T_2 V_39 ;
#define F_34 ( V_44 ) ((stage) - STAGE0)
V_60 = F_35 ( V_1 -> V_80 ) ;
F_20 ( & V_10 -> V_81 , V_34 ) ;
if ( ! V_19 )
goto V_82;
F_16 (plane, crtc) {
enum V_72 V_83 ;
V_62 = F_36 ( V_27 -> V_17 ) ;
V_63 [ V_62 -> V_44 ] = V_62 ;
V_44 [ V_62 -> V_44 ] [ V_84 ] = F_37 ( V_27 ) ;
if ( V_25 )
V_75 [ V_62 -> V_44 ] [ V_84 ] =
F_37 ( V_27 ) ;
V_83 = F_38 ( V_27 ) ;
if ( V_83 ) {
V_44 [ V_62 -> V_44 ] [ V_85 ] = V_83 ;
V_75 [ V_62 -> V_44 ] [ V_85 ] = V_83 ;
}
V_77 ++ ;
}
if ( ! V_63 [ V_86 ] ) {
V_71 |= V_87 ;
F_12 ( L_3 ) ;
} else if ( V_77 ) {
V_66 = F_39 ( F_40 ( V_63 [ V_86 ] -> V_11 . V_88 ) ) ;
if ( V_66 -> V_89 )
V_78 = true ;
}
for ( V_76 = V_45 ; V_76 <= V_64 ; V_76 ++ ) {
if ( ! V_63 [ V_76 ] )
continue;
V_66 = F_39 (
F_40 ( V_63 [ V_76 ] -> V_11 . V_88 ) ) ;
V_27 = V_63 [ V_76 ] -> V_11 . V_27 ;
V_68 = F_41 ( V_90 ) |
F_42 ( V_91 ) ;
V_69 = V_63 [ V_76 ] -> V_92 ;
V_70 = 0xFF - V_63 [ V_76 ] -> V_92 ;
if ( ! V_66 -> V_89 && V_78 )
V_79 = 0 ;
else
V_79 |= F_32 ( V_76 ) ;
F_12 ( L_4 , V_76 , V_69 , V_70 ) ;
if ( V_66 -> V_89 && V_63 [ V_76 ] -> V_93 ) {
V_68 = F_41 ( V_90 ) |
F_42 ( V_94 ) ;
if ( V_69 != 0xff ) {
V_70 = V_69 ;
V_68 |=
V_95 |
V_96 ;
} else {
V_68 |= V_97 ;
}
} else if ( V_66 -> V_89 ) {
V_68 = F_41 ( V_94 ) |
F_42 ( V_94 ) ;
if ( V_69 != 0xff ) {
V_70 = V_69 ;
V_68 |=
V_98 |
V_99 |
V_95 |
V_96 ;
} else {
V_68 |= V_97 ;
}
}
F_43 ( V_1 , F_44 ( V_28 ,
F_34 ( V_76 ) ) , V_68 ) ;
F_43 ( V_1 , F_45 ( V_28 ,
F_34 ( V_76 ) ) , V_69 ) ;
F_43 ( V_1 , F_46 ( V_28 ,
F_34 ( V_76 ) ) , V_70 ) ;
if ( V_25 ) {
F_43 ( V_1 , F_44 ( V_67 ,
F_34 ( V_76 ) ) , V_68 ) ;
F_43 ( V_1 , F_45 ( V_67 ,
F_34 ( V_76 ) ) , V_69 ) ;
F_43 ( V_1 , F_46 ( V_67 ,
F_34 ( V_76 ) ) , V_70 ) ;
}
}
V_39 = F_47 ( V_1 , F_48 ( V_28 ) ) ;
F_43 ( V_1 , F_48 ( V_28 ) ,
V_39 | V_79 ) ;
if ( V_25 ) {
V_39 = F_47 ( V_1 , F_48 ( V_67 ) ) ;
F_43 ( V_1 , F_48 ( V_67 ) ,
V_39 | V_79 ) ;
}
F_23 ( V_19 , V_21 , V_44 , V_75 , V_77 ,
V_71 ) ;
V_82:
F_22 ( & V_10 -> V_81 , V_34 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_23 * V_24 = V_16 -> V_21 . V_24 ;
struct V_23 * V_25 = V_16 -> V_21 . V_25 ;
T_1 V_28 = V_24 -> V_28 ;
T_2 V_100 , V_39 ;
unsigned long V_34 ;
struct V_101 * V_102 ;
if ( F_15 ( ! V_3 -> V_17 ) )
return;
V_102 = & V_3 -> V_17 -> V_103 ;
F_12 ( L_5 ,
V_3 -> V_22 , V_102 -> V_11 . V_104 , V_102 -> V_22 ,
V_102 -> V_105 , V_102 -> clock ,
V_102 -> V_106 , V_102 -> V_107 ,
V_102 -> V_108 , V_102 -> V_109 ,
V_102 -> V_110 , V_102 -> V_111 ,
V_102 -> V_112 , V_102 -> V_113 ,
V_102 -> type , V_102 -> V_34 ) ;
V_100 = V_102 -> V_106 ;
if ( V_25 )
V_100 /= 2 ;
F_20 ( & V_10 -> V_81 , V_34 ) ;
F_43 ( V_1 , F_50 ( V_28 ) ,
F_51 ( V_100 ) |
F_52 ( V_102 -> V_110 ) ) ;
V_39 = F_47 ( V_1 , F_48 ( V_28 ) ) ;
V_39 &= ~ V_114 ;
F_43 ( V_1 , F_48 ( V_28 ) , V_39 ) ;
if ( V_25 ) {
T_2 V_67 = V_25 -> V_28 ;
F_43 ( V_1 , F_50 ( V_67 ) ,
F_51 ( V_100 ) |
F_52 ( V_102 -> V_110 ) ) ;
V_39 = F_47 ( V_1 , F_48 ( V_67 ) ) ;
V_39 |= V_114 ;
F_43 ( V_1 , F_48 ( V_67 ) , V_39 ) ;
}
F_22 ( & V_10 -> V_81 , V_34 ) ;
}
static void F_53 ( struct V_2 * V_3 ,
struct V_115 * V_116 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_117 * V_6 = & V_1 -> V_118 -> V_6 ;
F_12 ( L_6 , V_3 -> V_22 ) ;
if ( F_15 ( ! V_10 -> V_119 ) )
return;
if ( V_16 -> V_120 )
F_54 ( & V_1 -> V_11 , & V_10 -> V_121 ) ;
F_54 ( & V_1 -> V_11 , & V_10 -> V_122 ) ;
F_55 ( V_6 ) ;
V_10 -> V_119 = false ;
}
static void F_56 ( struct V_2 * V_3 ,
struct V_115 * V_116 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_117 * V_6 = & V_1 -> V_118 -> V_6 ;
F_12 ( L_6 , V_3 -> V_22 ) ;
if ( F_15 ( V_10 -> V_119 ) )
return;
F_57 ( V_6 ) ;
F_49 ( V_3 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_122 ) ;
if ( V_16 -> V_120 )
F_7 ( & V_1 -> V_11 , & V_10 -> V_121 ) ;
V_10 -> V_119 = true ;
}
int F_58 ( struct V_2 * V_3 ,
struct V_115 * V_123 ,
bool V_124 )
{
struct V_15 * V_16 =
F_11 ( V_123 ) ;
struct V_20 * V_21 = & V_16 -> V_21 ;
struct V_125 * V_126 ;
bool V_127 = false ;
V_127 = ! V_21 -> V_24 ;
if ( ( V_124 && ! V_21 -> V_25 ) ||
( ! V_124 && V_21 -> V_25 ) )
V_127 = true ;
if ( V_127 ) {
struct V_23 * V_128 = V_21 -> V_24 ;
struct V_23 * V_129 = V_21 -> V_25 ;
T_2 V_130 ;
int V_131 ;
V_130 = V_132 ;
if ( V_124 )
V_130 |= V_133 ;
V_131 = F_59 ( V_123 -> V_17 , V_3 , V_130 ,
& V_21 -> V_24 , V_124 ?
& V_21 -> V_25 : NULL ) ;
if ( V_131 )
return V_131 ;
F_60 ( V_123 -> V_17 , V_128 ) ;
if ( V_129 ) {
F_60 ( V_123 -> V_17 , V_129 ) ;
if ( ! V_124 )
V_21 -> V_25 = NULL ;
}
}
V_126 = V_21 -> V_126 ;
V_16 -> V_134 = F_61 ( V_126 -> V_135 ) ;
V_16 -> V_136 = F_62 ( V_21 -> V_24 , V_126 ) ;
if ( ( V_126 -> type == V_137 ) &&
( V_126 -> V_102 == V_138 ) ) {
V_16 -> V_139 = F_63 ( V_21 -> V_24 ) ;
V_16 -> V_120 = true ;
} else {
V_16 -> V_139 = 0 ;
V_16 -> V_120 = false ;
}
return 0 ;
}
static int F_64 ( const void * V_140 , const void * V_141 )
{
struct V_142 * V_143 = (struct V_142 * ) V_140 ;
struct V_142 * V_144 = (struct V_142 * ) V_141 ;
return V_143 -> V_17 -> V_145 - V_144 -> V_17 -> V_145 ;
}
static bool F_65 ( struct V_115 * V_146 ,
struct V_147 * V_62 )
{
return ( V_62 -> V_148 <= 0 ) && ( V_62 -> V_149 <= 0 ) &&
( ( V_62 -> V_148 + V_62 -> V_150 ) >= V_146 -> V_102 . V_106 ) &&
( ( V_62 -> V_149 + V_62 -> V_151 ) >= V_146 -> V_102 . V_110 ) ;
}
static enum V_43 F_66 ( struct V_2 * V_3 ,
struct V_115 * V_123 ,
struct V_147 * V_152 )
{
struct V_15 * V_16 =
F_11 ( V_123 ) ;
if ( V_16 -> V_21 . V_25 )
return V_45 ;
if ( ! F_65 ( V_123 , V_152 ) )
return V_45 ;
return V_86 ;
}
static int F_67 ( struct V_2 * V_3 ,
struct V_115 * V_17 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_26 * V_27 ;
struct V_31 * V_6 = V_3 -> V_6 ;
struct V_142 V_63 [ V_64 + 1 ] ;
const struct V_59 * V_60 ;
const struct V_147 * V_62 ;
const struct V_101 * V_102 = & V_17 -> V_103 ;
bool V_153 = false ;
bool V_124 = false ;
int V_154 = 0 , V_76 ;
int V_131 ;
enum V_43 V_155 ;
F_12 ( L_7 , V_3 -> V_22 ) ;
F_68 (plane, pstate, state) {
V_63 [ V_154 ] . V_27 = V_27 ;
V_63 [ V_154 ] . V_17 = F_36 ( V_62 ) ;
if ( V_63 [ V_154 ] . V_17 -> V_156 )
V_124 = true ;
V_154 ++ ;
if ( V_27 -> type == V_157 )
V_153 = true ;
}
if ( ! V_154 )
return 0 ;
V_60 = F_35 ( V_1 -> V_80 ) ;
if ( V_102 -> V_106 > V_60 -> V_28 . V_158 )
V_124 = true ;
V_131 = F_58 ( V_3 , V_17 , V_124 ) ;
if ( V_131 ) {
F_69 ( V_6 -> V_6 , L_8 , V_131 ) ;
return V_131 ;
}
F_70 ( V_63 , V_154 , sizeof( V_63 [ 0 ] ) , F_64 , NULL ) ;
F_15 ( V_153 &&
( V_63 [ V_154 - 1 ] . V_27 -> type != V_157 ) ) ;
V_155 = F_66 ( V_3 , V_17 , & V_63 [ 0 ] . V_17 -> V_11 ) ;
if ( ( V_154 + V_155 - 1 ) >= V_60 -> V_28 . V_159 ) {
F_69 ( V_6 -> V_6 , L_9 ,
V_154 , V_155 ) ;
return - V_160 ;
}
for ( V_76 = 0 ; V_76 < V_154 ; V_76 ++ ) {
if ( V_153 && ( V_76 == ( V_154 - 1 ) ) )
V_63 [ V_76 ] . V_17 -> V_44 = V_60 -> V_28 . V_159 ;
else
V_63 [ V_76 ] . V_17 -> V_44 = V_155 + V_76 ;
F_12 ( L_10 , V_3 -> V_22 ,
V_63 [ V_76 ] . V_27 -> V_22 ,
V_63 [ V_76 ] . V_17 -> V_44 ) ;
}
return 0 ;
}
static void F_71 ( struct V_2 * V_3 ,
struct V_115 * V_161 )
{
F_12 ( L_11 , V_3 -> V_22 ) ;
}
static void F_72 ( struct V_2 * V_3 ,
struct V_115 * V_161 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
struct V_31 * V_6 = V_3 -> V_6 ;
unsigned long V_34 ;
F_12 ( L_12 , V_3 -> V_22 , V_3 -> V_17 -> V_33 ) ;
F_15 ( V_10 -> V_33 ) ;
F_20 ( & V_6 -> V_35 , V_34 ) ;
V_10 -> V_33 = V_3 -> V_17 -> V_33 ;
F_22 ( & V_6 -> V_35 , V_34 ) ;
if ( F_73 ( ! V_16 -> V_19 ) )
return;
F_33 ( V_3 ) ;
if ( V_16 -> V_120 )
F_8 ( V_3 ) ;
V_10 -> V_162 = F_14 ( V_3 ) ;
V_10 -> V_12 . V_163 = V_16 -> V_136 ;
V_10 -> V_122 . V_163 = V_16 -> V_134 ;
V_10 -> V_121 . V_163 = V_16 -> V_139 ;
F_4 ( V_3 , V_164 ) ;
}
static void F_74 ( struct V_2 * V_3 , T_1 * V_165 , T_1 * V_166 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
T_1 V_167 = V_3 -> V_102 . V_106 ;
T_1 V_168 = V_3 -> V_102 . V_110 ;
* V_165 = F_75 ( V_10 -> V_169 . V_170 , V_167 -
V_10 -> V_169 . V_171 ) ;
* V_166 = F_75 ( V_10 -> V_169 . V_172 , V_168 -
V_10 -> V_169 . V_173 ) ;
}
static int F_76 ( struct V_2 * V_3 ,
struct V_29 * V_30 , T_1 V_174 ,
T_1 V_170 , T_1 V_172 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
struct V_20 * V_21 = & V_16 -> V_21 ;
struct V_31 * V_6 = V_3 -> V_6 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_175 * V_118 = V_1 -> V_118 ;
struct V_41 * V_8 = & V_1 -> V_11 . V_11 ;
struct V_176 * V_177 , * V_178 = NULL ;
T_1 V_179 , V_180 ;
T_3 V_181 ;
struct V_18 * V_19 ;
int V_131 , V_28 ;
enum V_182 V_183 = V_184 ;
T_1 V_14 = F_77 ( 0 ) ;
T_1 V_165 , V_166 ;
bool V_185 = true ;
unsigned long V_34 ;
if ( ( V_170 > V_186 ) || ( V_172 > V_187 ) ) {
F_69 ( V_6 -> V_6 , L_13 , V_170 , V_172 ) ;
return - V_160 ;
}
V_19 = V_16 -> V_19 ;
if ( ! V_19 )
return - V_160 ;
if ( V_16 -> V_21 . V_25 )
return - V_160 ;
if ( ! V_174 ) {
F_12 ( L_14 ) ;
V_185 = false ;
F_57 ( & V_118 -> V_6 ) ;
goto V_188;
}
V_177 = F_78 ( V_30 , V_174 ) ;
if ( ! V_177 )
return - V_189 ;
V_131 = F_79 ( V_177 , V_8 -> V_42 , & V_181 ) ;
if ( V_131 )
return - V_160 ;
V_28 = V_16 -> V_21 . V_24 -> V_28 ;
V_180 = V_170 * F_80 ( V_190 , 0 ) ;
F_57 ( & V_118 -> V_6 ) ;
F_20 ( & V_10 -> V_169 . V_191 , V_34 ) ;
V_178 = V_10 -> V_169 . V_192 ;
V_10 -> V_169 . V_192 = V_177 ;
V_10 -> V_169 . V_170 = V_170 ;
V_10 -> V_169 . V_172 = V_172 ;
F_74 ( V_3 , & V_165 , & V_166 ) ;
F_43 ( V_1 , F_81 ( V_28 ) , V_180 ) ;
F_43 ( V_1 , F_82 ( V_28 ) ,
F_83 ( V_193 ) ) ;
F_43 ( V_1 , F_84 ( V_28 ) ,
F_85 ( V_172 ) |
F_86 ( V_170 ) ) ;
F_43 ( V_1 , F_87 ( V_28 ) ,
F_88 ( V_166 ) |
F_89 ( V_165 ) ) ;
F_43 ( V_1 , F_90 ( V_28 ) , V_181 ) ;
V_179 = V_194 ;
V_179 |= F_91 ( V_183 ) ;
F_43 ( V_1 , F_92 ( V_28 ) , V_179 ) ;
F_22 ( & V_10 -> V_169 . V_191 , V_34 ) ;
V_188:
V_131 = F_93 ( V_19 , V_21 , 0 , V_185 ) ;
if ( V_131 ) {
F_69 ( V_6 -> V_6 , L_15 ,
V_185 ? L_16 : L_17 , V_131 ) ;
goto V_195;
}
F_10 ( V_3 , V_14 ) ;
V_195:
F_55 ( & V_118 -> V_6 ) ;
if ( V_178 ) {
F_94 ( & V_10 -> V_40 , V_178 ) ;
F_4 ( V_3 , V_196 ) ;
}
return V_131 ;
}
static int F_95 ( struct V_2 * V_3 , int V_171 , int V_173 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
T_1 V_28 = V_16 -> V_21 . V_24 -> V_28 ;
T_1 V_14 = F_77 ( 0 ) ;
T_1 V_165 ;
T_1 V_166 ;
unsigned long V_34 ;
if ( V_16 -> V_21 . V_25 )
return - V_160 ;
if ( F_73 ( ! V_3 -> V_17 -> V_36 ) )
return 0 ;
V_10 -> V_169 . V_171 = V_171 = F_96 ( V_171 , 0 ) ;
V_10 -> V_169 . V_173 = V_173 = F_96 ( V_173 , 0 ) ;
F_74 ( V_3 , & V_165 , & V_166 ) ;
F_57 ( & V_1 -> V_118 -> V_6 ) ;
F_20 ( & V_10 -> V_169 . V_191 , V_34 ) ;
F_43 ( V_1 , F_87 ( V_28 ) ,
F_88 ( V_166 ) |
F_89 ( V_165 ) ) ;
F_43 ( V_1 , F_97 ( V_28 ) ,
F_98 ( V_173 ) |
F_99 ( V_171 ) ) ;
F_22 ( & V_10 -> V_169 . V_191 , V_34 ) ;
F_10 ( V_3 , V_14 ) ;
F_55 ( & V_1 -> V_118 -> V_6 ) ;
return 0 ;
}
static void
F_100 ( struct V_197 * V_198 ,
const struct V_115 * V_17 )
{
struct V_15 * V_16 = F_11 ( V_17 ) ;
struct V_20 * V_21 = & V_16 -> V_21 ;
struct V_1 * V_1 = F_1 ( V_17 -> V_3 ) ;
if ( F_15 ( ! V_21 ) )
return;
F_101 ( V_198 , L_18 , V_21 -> V_24 ?
V_21 -> V_24 -> V_22 : L_19 ) ;
if ( V_1 -> V_130 & V_199 )
F_101 ( V_198 , L_20 , V_21 -> V_25 ?
V_21 -> V_25 -> V_22 : L_19 ) ;
}
static void F_102 ( struct V_2 * V_3 )
{
struct V_15 * V_16 ;
if ( V_3 -> V_17 ) {
F_103 ( V_3 -> V_17 ) ;
F_31 ( F_11 ( V_3 -> V_17 ) ) ;
}
V_16 = F_104 ( sizeof( * V_16 ) , V_200 ) ;
if ( V_16 ) {
V_16 -> V_11 . V_3 = V_3 ;
V_3 -> V_17 = & V_16 -> V_11 ;
}
}
static struct V_115 *
F_105 ( struct V_2 * V_3 )
{
struct V_15 * V_16 ;
if ( F_15 ( ! V_3 -> V_17 ) )
return NULL ;
V_16 = F_106 ( F_11 ( V_3 -> V_17 ) ,
sizeof( * V_16 ) , V_200 ) ;
if ( ! V_16 )
return NULL ;
F_107 ( V_3 , & V_16 -> V_11 ) ;
return & V_16 -> V_11 ;
}
static void F_108 ( struct V_2 * V_3 , struct V_115 * V_17 )
{
struct V_15 * V_16 = F_11 ( V_17 ) ;
F_103 ( V_17 ) ;
F_31 ( V_16 ) ;
}
static void F_109 ( struct V_201 * V_202 , T_1 V_203 )
{
struct V_10 * V_10 = F_25 ( V_202 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_54 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_110 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_164 ) {
F_19 ( V_3 , NULL ) ;
}
if ( V_9 & V_196 )
F_111 ( & V_10 -> V_40 , V_5 -> V_204 ) ;
}
static void F_112 ( struct V_201 * V_202 , T_1 V_203 )
{
struct V_10 * V_10 = F_25 ( V_202 , struct V_10 , V_122 ) ;
F_12 ( L_21 , V_10 -> V_11 . V_22 , V_203 ) ;
}
static void F_113 ( struct V_201 * V_202 , T_1 V_203 )
{
struct V_10 * V_10 = F_25 ( V_202 , struct V_10 ,
V_121 ) ;
F_114 ( & V_10 -> V_13 ) ;
}
static void F_115 ( struct V_2 * V_3 )
{
struct V_31 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
int V_131 ;
V_131 = F_116 ( & V_10 -> V_13 ,
F_117 ( 50 ) ) ;
if ( V_131 == 0 )
F_118 ( V_6 -> V_6 , L_22 ,
V_16 -> V_21 . V_24 -> V_28 ) ;
}
static void F_119 ( struct V_2 * V_3 )
{
struct V_31 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
struct V_18 * V_19 = V_16 -> V_19 ;
int V_131 ;
if ( ! V_19 )
return;
V_131 = F_120 ( V_3 ) ;
if ( V_131 )
return;
V_131 = F_121 ( V_6 -> V_12 [ F_122 ( V_3 ) ] . V_205 ,
( ( F_123 ( V_19 ) &
V_10 -> V_162 ) == 0 ) ,
F_117 ( 50 ) ) ;
if ( V_131 <= 0 )
F_118 ( V_6 -> V_6 , L_23 , V_10 -> V_104 ) ;
V_10 -> V_162 = 0 ;
F_124 ( V_3 ) ;
}
T_1 F_125 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_163 ;
}
void F_126 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_127 ( & V_1 -> V_11 ) ;
F_128 ( V_16 -> V_19 , & V_16 -> V_21 ) ;
}
struct V_18 * F_129 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
return V_16 -> V_19 ;
}
struct V_23 * F_130 ( struct V_2 * V_3 )
{
struct V_15 * V_16 ;
if ( F_15 ( ! V_3 ) )
return F_131 ( - V_160 ) ;
V_16 = F_11 ( V_3 -> V_17 ) ;
return F_15 ( ! V_16 -> V_21 . V_24 ) ?
F_131 ( - V_160 ) : V_16 -> V_21 . V_24 ;
}
struct V_20 * F_132 ( struct V_2 * V_3 )
{
struct V_15 * V_16 ;
if ( F_15 ( ! V_3 ) )
return F_131 ( - V_160 ) ;
V_16 = F_11 ( V_3 -> V_17 ) ;
return & V_16 -> V_21 ;
}
void F_133 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
if ( V_16 -> V_120 )
F_115 ( V_3 ) ;
else
F_119 ( V_3 ) ;
}
struct V_2 * F_134 ( struct V_31 * V_6 ,
struct V_26 * V_27 ,
struct V_26 * V_153 , int V_104 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
V_10 = F_104 ( sizeof( * V_10 ) , V_200 ) ;
if ( ! V_10 )
return F_131 ( - V_206 ) ;
V_3 = & V_10 -> V_11 ;
V_10 -> V_104 = V_104 ;
F_135 ( & V_10 -> V_81 ) ;
F_135 ( & V_10 -> V_169 . V_191 ) ;
F_136 ( & V_10 -> V_13 ) ;
V_10 -> V_12 . V_202 = F_109 ;
V_10 -> V_122 . V_202 = F_112 ;
V_10 -> V_121 . V_202 = F_113 ;
if ( V_153 )
F_137 ( V_6 , V_3 , V_27 , V_153 ,
& V_207 , NULL ) ;
else
F_137 ( V_6 , V_3 , V_27 , NULL ,
& V_208 , NULL ) ;
F_138 ( & V_10 -> V_40 ,
L_24 , F_24 ) ;
F_139 ( V_3 , & V_209 ) ;
V_27 -> V_3 = V_3 ;
return V_3 ;
}
