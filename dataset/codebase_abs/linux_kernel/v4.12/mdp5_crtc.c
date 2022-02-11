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
F_26 ( V_39 , V_1 -> V_41 ) ;
F_27 ( V_39 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
F_29 ( V_3 ) ;
F_30 ( & V_10 -> V_40 ) ;
F_31 ( V_10 ) ;
}
static inline T_2 F_32 ( enum V_42 V_43 )
{
switch ( V_43 ) {
case V_44 : return V_45 ;
case V_46 : return V_47 ;
case V_48 : return V_49 ;
case V_50 : return V_51 ;
case V_52 : return V_53 ;
case V_54 : return V_55 ;
case V_56 : return V_57 ;
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
const struct V_58 * V_59 ;
struct V_60 * V_61 , * V_62 [ V_63 + 1 ] = { NULL } ;
const struct V_64 * V_65 ;
struct V_23 * V_24 = V_21 -> V_24 ;
T_1 V_28 = V_24 -> V_28 ;
struct V_23 * V_25 = V_21 -> V_25 ;
T_1 V_66 = V_25 ? V_25 -> V_28 : 0 ;
struct V_18 * V_19 = V_16 -> V_19 ;
T_1 V_67 , V_68 , V_69 , V_70 = 0 ;
unsigned long V_34 ;
enum V_71 V_43 [ V_63 + 1 ] [ V_72 ] = { V_73 } ;
enum V_71 V_74 [ V_63 + 1 ] [ V_72 ] = { V_73 } ;
int V_75 , V_76 = 0 ;
bool V_77 = false ;
T_2 V_78 = 0 ;
T_2 V_39 ;
#define F_34 ( V_43 ) ((stage) - STAGE0)
V_59 = F_35 ( V_1 -> V_79 ) ;
F_20 ( & V_10 -> V_80 , V_34 ) ;
if ( ! V_19 )
goto V_81;
F_16 (plane, crtc) {
enum V_71 V_82 ;
V_61 = F_36 ( V_27 -> V_17 ) ;
V_62 [ V_61 -> V_43 ] = V_61 ;
V_43 [ V_61 -> V_43 ] [ V_83 ] = F_37 ( V_27 ) ;
if ( V_25 )
V_74 [ V_61 -> V_43 ] [ V_83 ] =
F_37 ( V_27 ) ;
V_82 = F_38 ( V_27 ) ;
if ( V_82 ) {
V_43 [ V_61 -> V_43 ] [ V_84 ] = V_82 ;
V_74 [ V_61 -> V_43 ] [ V_84 ] = V_82 ;
}
V_76 ++ ;
}
if ( ! V_62 [ V_85 ] ) {
V_70 |= V_86 ;
F_12 ( L_3 ) ;
} else if ( V_76 ) {
V_65 = F_39 ( F_40 ( V_62 [ V_85 ] -> V_11 . V_87 ) ) ;
if ( V_65 -> V_88 )
V_77 = true ;
}
for ( V_75 = V_44 ; V_75 <= V_63 ; V_75 ++ ) {
if ( ! V_62 [ V_75 ] )
continue;
V_65 = F_39 (
F_40 ( V_62 [ V_75 ] -> V_11 . V_87 ) ) ;
V_27 = V_62 [ V_75 ] -> V_11 . V_27 ;
V_67 = F_41 ( V_89 ) |
F_42 ( V_90 ) ;
V_68 = V_62 [ V_75 ] -> V_91 ;
V_69 = 0xFF - V_62 [ V_75 ] -> V_91 ;
if ( ! V_65 -> V_88 && V_77 )
V_78 = 0 ;
else
V_78 |= F_32 ( V_75 ) ;
F_12 ( L_4 , V_75 , V_68 , V_69 ) ;
if ( V_65 -> V_88 && V_62 [ V_75 ] -> V_92 ) {
V_67 = F_41 ( V_89 ) |
F_42 ( V_93 ) ;
if ( V_68 != 0xff ) {
V_69 = V_68 ;
V_67 |=
V_94 |
V_95 ;
} else {
V_67 |= V_96 ;
}
} else if ( V_65 -> V_88 ) {
V_67 = F_41 ( V_93 ) |
F_42 ( V_93 ) ;
if ( V_68 != 0xff ) {
V_69 = V_68 ;
V_67 |=
V_97 |
V_98 |
V_94 |
V_95 ;
} else {
V_67 |= V_96 ;
}
}
F_43 ( V_1 , F_44 ( V_28 ,
F_34 ( V_75 ) ) , V_67 ) ;
F_43 ( V_1 , F_45 ( V_28 ,
F_34 ( V_75 ) ) , V_68 ) ;
F_43 ( V_1 , F_46 ( V_28 ,
F_34 ( V_75 ) ) , V_69 ) ;
if ( V_25 ) {
F_43 ( V_1 , F_44 ( V_66 ,
F_34 ( V_75 ) ) , V_67 ) ;
F_43 ( V_1 , F_45 ( V_66 ,
F_34 ( V_75 ) ) , V_68 ) ;
F_43 ( V_1 , F_46 ( V_66 ,
F_34 ( V_75 ) ) , V_69 ) ;
}
}
V_39 = F_47 ( V_1 , F_48 ( V_28 ) ) ;
F_43 ( V_1 , F_48 ( V_28 ) ,
V_39 | V_78 ) ;
if ( V_25 ) {
V_39 = F_47 ( V_1 , F_48 ( V_66 ) ) ;
F_43 ( V_1 , F_48 ( V_66 ) ,
V_39 | V_78 ) ;
}
F_23 ( V_19 , V_21 , V_43 , V_74 , V_76 ,
V_70 ) ;
V_81:
F_22 ( & V_10 -> V_80 , V_34 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_23 * V_24 = V_16 -> V_21 . V_24 ;
struct V_23 * V_25 = V_16 -> V_21 . V_25 ;
T_1 V_28 = V_24 -> V_28 ;
T_2 V_99 , V_39 ;
unsigned long V_34 ;
struct V_100 * V_101 ;
if ( F_15 ( ! V_3 -> V_17 ) )
return;
V_101 = & V_3 -> V_17 -> V_102 ;
F_12 ( L_5 ,
V_3 -> V_22 , V_101 -> V_11 . V_41 , V_101 -> V_22 ,
V_101 -> V_103 , V_101 -> clock ,
V_101 -> V_104 , V_101 -> V_105 ,
V_101 -> V_106 , V_101 -> V_107 ,
V_101 -> V_108 , V_101 -> V_109 ,
V_101 -> V_110 , V_101 -> V_111 ,
V_101 -> type , V_101 -> V_34 ) ;
V_99 = V_101 -> V_104 ;
if ( V_25 )
V_99 /= 2 ;
F_20 ( & V_10 -> V_80 , V_34 ) ;
F_43 ( V_1 , F_50 ( V_28 ) ,
F_51 ( V_99 ) |
F_52 ( V_101 -> V_108 ) ) ;
V_39 = F_47 ( V_1 , F_48 ( V_28 ) ) ;
V_39 &= ~ V_112 ;
F_43 ( V_1 , F_48 ( V_28 ) , V_39 ) ;
if ( V_25 ) {
T_2 V_66 = V_25 -> V_28 ;
F_43 ( V_1 , F_50 ( V_66 ) ,
F_51 ( V_99 ) |
F_52 ( V_101 -> V_108 ) ) ;
V_39 = F_47 ( V_1 , F_48 ( V_66 ) ) ;
V_39 |= V_112 ;
F_43 ( V_1 , F_48 ( V_66 ) , V_39 ) ;
}
F_22 ( & V_10 -> V_80 , V_34 ) ;
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_12 ( L_6 , V_3 -> V_22 ) ;
if ( F_15 ( ! V_10 -> V_113 ) )
return;
if ( V_16 -> V_114 )
F_54 ( & V_1 -> V_11 , & V_10 -> V_115 ) ;
F_54 ( & V_1 -> V_11 , & V_10 -> V_116 ) ;
F_55 ( V_1 ) ;
V_10 -> V_113 = false ;
}
static void F_56 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_12 ( L_6 , V_3 -> V_22 ) ;
if ( F_15 ( V_10 -> V_113 ) )
return;
F_57 ( V_1 ) ;
F_7 ( & V_1 -> V_11 , & V_10 -> V_116 ) ;
if ( V_16 -> V_114 )
F_7 ( & V_1 -> V_11 , & V_10 -> V_115 ) ;
V_10 -> V_113 = true ;
}
int F_58 ( struct V_2 * V_3 ,
struct V_117 * V_118 ,
bool V_119 )
{
struct V_15 * V_16 =
F_11 ( V_118 ) ;
struct V_20 * V_21 = & V_16 -> V_21 ;
struct V_120 * V_121 ;
bool V_122 = false ;
V_122 = ! V_21 -> V_24 ;
if ( ( V_119 && ! V_21 -> V_25 ) ||
( ! V_119 && V_21 -> V_25 ) )
V_122 = true ;
if ( V_122 ) {
struct V_23 * V_123 = V_21 -> V_24 ;
struct V_23 * V_124 = V_21 -> V_25 ;
T_2 V_125 ;
int V_126 ;
V_125 = V_127 ;
if ( V_119 )
V_125 |= V_128 ;
V_126 = F_59 ( V_118 -> V_17 , V_3 , V_125 ,
& V_21 -> V_24 , V_119 ?
& V_21 -> V_25 : NULL ) ;
if ( V_126 )
return V_126 ;
F_60 ( V_118 -> V_17 , V_123 ) ;
if ( V_124 ) {
F_60 ( V_118 -> V_17 , V_124 ) ;
if ( ! V_119 )
V_21 -> V_25 = NULL ;
}
}
V_121 = V_21 -> V_121 ;
V_16 -> V_129 = F_61 ( V_121 -> V_130 ) ;
V_16 -> V_131 = F_62 ( V_21 -> V_24 , V_121 ) ;
if ( ( V_121 -> type == V_132 ) &&
( V_121 -> V_101 == V_133 ) ) {
V_16 -> V_134 = F_63 ( V_21 -> V_24 ) ;
V_16 -> V_114 = true ;
} else {
V_16 -> V_134 = 0 ;
V_16 -> V_114 = false ;
}
return 0 ;
}
static int F_64 ( const void * V_135 , const void * V_136 )
{
struct V_137 * V_138 = (struct V_137 * ) V_135 ;
struct V_137 * V_139 = (struct V_137 * ) V_136 ;
return V_138 -> V_17 -> V_140 - V_139 -> V_17 -> V_140 ;
}
static bool F_65 ( struct V_117 * V_141 ,
struct V_142 * V_61 )
{
return ( V_61 -> V_143 <= 0 ) && ( V_61 -> V_144 <= 0 ) &&
( ( V_61 -> V_143 + V_61 -> V_145 ) >= V_141 -> V_101 . V_104 ) &&
( ( V_61 -> V_144 + V_61 -> V_146 ) >= V_141 -> V_101 . V_108 ) ;
}
enum V_42 F_66 ( struct V_2 * V_3 ,
struct V_117 * V_118 ,
struct V_142 * V_147 )
{
struct V_15 * V_16 =
F_11 ( V_118 ) ;
if ( V_16 -> V_21 . V_25 )
return V_44 ;
if ( ! F_65 ( V_118 , V_147 ) )
return V_44 ;
return V_85 ;
}
static int F_67 ( struct V_2 * V_3 ,
struct V_117 * V_17 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_26 * V_27 ;
struct V_31 * V_6 = V_3 -> V_6 ;
struct V_137 V_62 [ V_63 + 1 ] ;
const struct V_58 * V_59 ;
const struct V_142 * V_61 ;
const struct V_100 * V_101 = & V_17 -> V_102 ;
bool V_148 = false ;
bool V_119 = false ;
int V_149 = 0 , V_75 ;
int V_126 ;
enum V_42 V_150 ;
F_12 ( L_7 , V_3 -> V_22 ) ;
F_68 (plane, pstate, state) {
V_62 [ V_149 ] . V_27 = V_27 ;
V_62 [ V_149 ] . V_17 = F_36 ( V_61 ) ;
if ( V_62 [ V_149 ] . V_17 -> V_151 )
V_119 = true ;
V_149 ++ ;
if ( V_27 -> type == V_152 )
V_148 = true ;
}
if ( ! V_149 )
return 0 ;
V_59 = F_35 ( V_1 -> V_79 ) ;
if ( V_101 -> V_104 > V_59 -> V_28 . V_153 )
V_119 = true ;
V_126 = F_58 ( V_3 , V_17 , V_119 ) ;
if ( V_126 ) {
F_69 ( V_6 -> V_6 , L_8 , V_126 ) ;
return V_126 ;
}
F_70 ( V_62 , V_149 , sizeof( V_62 [ 0 ] ) , F_64 , NULL ) ;
F_15 ( V_148 &&
( V_62 [ V_149 - 1 ] . V_27 -> type != V_152 ) ) ;
V_150 = F_66 ( V_3 , V_17 , & V_62 [ 0 ] . V_17 -> V_11 ) ;
if ( ( V_149 + V_150 - 1 ) >= V_59 -> V_28 . V_154 ) {
F_69 ( V_6 -> V_6 , L_9 ,
V_149 , V_150 ) ;
return - V_155 ;
}
for ( V_75 = 0 ; V_75 < V_149 ; V_75 ++ ) {
if ( V_148 && ( V_75 == ( V_149 - 1 ) ) )
V_62 [ V_75 ] . V_17 -> V_43 = V_59 -> V_28 . V_154 ;
else
V_62 [ V_75 ] . V_17 -> V_43 = V_150 + V_75 ;
F_12 ( L_10 , V_3 -> V_22 ,
V_62 [ V_75 ] . V_27 -> V_22 ,
V_62 [ V_75 ] . V_17 -> V_43 ) ;
}
return 0 ;
}
static void F_71 ( struct V_2 * V_3 ,
struct V_117 * V_156 )
{
F_12 ( L_11 , V_3 -> V_22 ) ;
}
static void F_72 ( struct V_2 * V_3 ,
struct V_117 * V_156 )
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
if ( V_16 -> V_114 )
F_8 ( V_3 ) ;
V_10 -> V_157 = F_14 ( V_3 ) ;
V_10 -> V_12 . V_158 = V_16 -> V_131 ;
V_10 -> V_116 . V_158 = V_16 -> V_129 ;
V_10 -> V_115 . V_158 = V_16 -> V_134 ;
F_4 ( V_3 , V_159 ) ;
}
static void F_74 ( struct V_2 * V_3 , T_1 * V_160 , T_1 * V_161 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
T_1 V_162 = V_3 -> V_101 . V_104 ;
T_1 V_163 = V_3 -> V_101 . V_108 ;
* V_160 = F_75 ( V_10 -> V_164 . V_165 , V_162 -
V_10 -> V_164 . V_166 ) ;
* V_161 = F_75 ( V_10 -> V_164 . V_167 , V_163 -
V_10 -> V_164 . V_168 ) ;
}
static int F_76 ( struct V_2 * V_3 ,
struct V_29 * V_30 , T_1 V_169 ,
T_1 V_165 , T_1 V_167 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
struct V_20 * V_21 = & V_16 -> V_21 ;
struct V_31 * V_6 = V_3 -> V_6 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_170 * V_171 , * V_172 = NULL ;
T_1 V_173 , V_174 ;
T_3 V_175 ;
struct V_18 * V_19 ;
int V_126 , V_28 ;
enum V_176 V_177 = V_178 ;
T_1 V_14 = F_77 ( 0 ) ;
T_1 V_160 , V_161 ;
bool V_179 = true ;
unsigned long V_34 ;
if ( ( V_165 > V_180 ) || ( V_167 > V_181 ) ) {
F_69 ( V_6 -> V_6 , L_13 , V_165 , V_167 ) ;
return - V_155 ;
}
V_19 = V_16 -> V_19 ;
if ( ! V_19 )
return - V_155 ;
if ( V_16 -> V_21 . V_25 )
return - V_155 ;
if ( ! V_169 ) {
F_12 ( L_14 ) ;
V_179 = false ;
goto V_182;
}
V_171 = F_78 ( V_30 , V_169 ) ;
if ( ! V_171 )
return - V_183 ;
V_126 = F_79 ( V_171 , V_1 -> V_41 , & V_175 ) ;
if ( V_126 )
return - V_155 ;
V_28 = V_16 -> V_21 . V_24 -> V_28 ;
V_174 = V_165 * F_80 ( V_184 , 0 ) ;
F_20 ( & V_10 -> V_164 . V_185 , V_34 ) ;
V_172 = V_10 -> V_164 . V_186 ;
V_10 -> V_164 . V_186 = V_171 ;
V_10 -> V_164 . V_165 = V_165 ;
V_10 -> V_164 . V_167 = V_167 ;
F_74 ( V_3 , & V_160 , & V_161 ) ;
F_43 ( V_1 , F_81 ( V_28 ) , V_174 ) ;
F_43 ( V_1 , F_82 ( V_28 ) ,
F_83 ( V_187 ) ) ;
F_43 ( V_1 , F_84 ( V_28 ) ,
F_85 ( V_167 ) |
F_86 ( V_165 ) ) ;
F_43 ( V_1 , F_87 ( V_28 ) ,
F_88 ( V_161 ) |
F_89 ( V_160 ) ) ;
F_43 ( V_1 , F_90 ( V_28 ) , V_175 ) ;
V_173 = V_188 ;
V_173 |= F_91 ( V_177 ) ;
F_43 ( V_1 , F_92 ( V_28 ) , V_173 ) ;
F_22 ( & V_10 -> V_164 . V_185 , V_34 ) ;
V_182:
V_126 = F_93 ( V_19 , V_21 , 0 , V_179 ) ;
if ( V_126 ) {
F_69 ( V_6 -> V_6 , L_15 ,
V_179 ? L_16 : L_17 , V_126 ) ;
goto V_189;
}
F_10 ( V_3 , V_14 ) ;
V_189:
if ( V_172 ) {
F_94 ( & V_10 -> V_40 , V_172 ) ;
F_4 ( V_3 , V_190 ) ;
}
return V_126 ;
}
static int F_95 ( struct V_2 * V_3 , int V_166 , int V_168 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
T_1 V_28 = V_16 -> V_21 . V_24 -> V_28 ;
T_1 V_14 = F_77 ( 0 ) ;
T_1 V_160 ;
T_1 V_161 ;
unsigned long V_34 ;
if ( V_16 -> V_21 . V_25 )
return - V_155 ;
if ( F_73 ( ! V_3 -> V_17 -> V_36 ) )
return 0 ;
V_10 -> V_164 . V_166 = V_166 = F_96 ( V_166 , 0 ) ;
V_10 -> V_164 . V_168 = V_168 = F_96 ( V_168 , 0 ) ;
F_74 ( V_3 , & V_160 , & V_161 ) ;
F_20 ( & V_10 -> V_164 . V_185 , V_34 ) ;
F_43 ( V_1 , F_87 ( V_28 ) ,
F_88 ( V_161 ) |
F_89 ( V_160 ) ) ;
F_43 ( V_1 , F_97 ( V_28 ) ,
F_98 ( V_168 ) |
F_99 ( V_166 ) ) ;
F_22 ( & V_10 -> V_164 . V_185 , V_34 ) ;
F_10 ( V_3 , V_14 ) ;
return 0 ;
}
static void
F_100 ( struct V_191 * V_192 ,
const struct V_117 * V_17 )
{
struct V_15 * V_16 = F_11 ( V_17 ) ;
struct V_20 * V_21 = & V_16 -> V_21 ;
struct V_1 * V_1 = F_1 ( V_17 -> V_3 ) ;
if ( F_15 ( ! V_21 ) )
return;
F_101 ( V_192 , L_18 , V_21 -> V_24 ?
V_21 -> V_24 -> V_22 : L_19 ) ;
if ( V_1 -> V_125 & V_193 )
F_101 ( V_192 , L_20 , V_21 -> V_25 ?
V_21 -> V_25 -> V_22 : L_19 ) ;
}
static void F_102 ( struct V_2 * V_3 )
{
struct V_15 * V_16 ;
if ( V_3 -> V_17 ) {
F_103 ( V_3 -> V_17 ) ;
F_31 ( F_11 ( V_3 -> V_17 ) ) ;
}
V_16 = F_104 ( sizeof( * V_16 ) , V_194 ) ;
if ( V_16 ) {
V_16 -> V_11 . V_3 = V_3 ;
V_3 -> V_17 = & V_16 -> V_11 ;
}
}
static struct V_117 *
F_105 ( struct V_2 * V_3 )
{
struct V_15 * V_16 ;
if ( F_15 ( ! V_3 -> V_17 ) )
return NULL ;
V_16 = F_106 ( F_11 ( V_3 -> V_17 ) ,
sizeof( * V_16 ) , V_194 ) ;
if ( ! V_16 )
return NULL ;
F_107 ( V_3 , & V_16 -> V_11 ) ;
return & V_16 -> V_11 ;
}
static void F_108 ( struct V_2 * V_3 , struct V_117 * V_17 )
{
struct V_15 * V_16 = F_11 ( V_17 ) ;
F_103 ( V_17 ) ;
F_31 ( V_16 ) ;
}
static void F_109 ( struct V_195 * V_196 , T_1 V_197 )
{
struct V_10 * V_10 = F_25 ( V_196 , struct V_10 , V_12 ) ;
struct V_2 * V_3 = & V_10 -> V_11 ;
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
unsigned V_9 ;
F_54 ( & F_1 ( V_3 ) -> V_11 , & V_10 -> V_12 ) ;
V_9 = F_110 ( & V_10 -> V_9 , 0 ) ;
if ( V_9 & V_159 ) {
F_19 ( V_3 , NULL ) ;
}
if ( V_9 & V_190 )
F_111 ( & V_10 -> V_40 , V_5 -> V_198 ) ;
}
static void F_112 ( struct V_195 * V_196 , T_1 V_197 )
{
struct V_10 * V_10 = F_25 ( V_196 , struct V_10 , V_116 ) ;
F_12 ( L_21 , V_10 -> V_11 . V_22 , V_197 ) ;
}
static void F_113 ( struct V_195 * V_196 , T_1 V_197 )
{
struct V_10 * V_10 = F_25 ( V_196 , struct V_10 ,
V_115 ) ;
F_114 ( & V_10 -> V_13 ) ;
}
static void F_115 ( struct V_2 * V_3 )
{
struct V_31 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
int V_126 ;
V_126 = F_116 ( & V_10 -> V_13 ,
F_117 ( 50 ) ) ;
if ( V_126 == 0 )
F_118 ( V_6 -> V_6 , L_22 ,
V_16 -> V_21 . V_24 -> V_28 ) ;
}
static void F_119 ( struct V_2 * V_3 )
{
struct V_31 * V_6 = V_3 -> V_6 ;
struct V_10 * V_10 = F_5 ( V_3 ) ;
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
struct V_18 * V_19 = V_16 -> V_19 ;
int V_126 ;
if ( ! V_19 )
return;
V_126 = F_120 ( V_3 ) ;
if ( V_126 )
return;
V_126 = F_121 ( V_6 -> V_12 [ F_122 ( V_3 ) ] . V_199 ,
( ( F_123 ( V_19 ) &
V_10 -> V_157 ) == 0 ) ,
F_117 ( 50 ) ) ;
if ( V_126 <= 0 )
F_118 ( V_6 -> V_6 , L_23 , V_10 -> V_41 ) ;
V_10 -> V_157 = 0 ;
F_124 ( V_3 ) ;
}
T_1 F_125 ( struct V_2 * V_3 )
{
struct V_10 * V_10 = F_5 ( V_3 ) ;
return V_10 -> V_12 . V_158 ;
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
return F_131 ( - V_155 ) ;
V_16 = F_11 ( V_3 -> V_17 ) ;
return F_15 ( ! V_16 -> V_21 . V_24 ) ?
F_131 ( - V_155 ) : V_16 -> V_21 . V_24 ;
}
struct V_20 * F_132 ( struct V_2 * V_3 )
{
struct V_15 * V_16 ;
if ( F_15 ( ! V_3 ) )
return F_131 ( - V_155 ) ;
V_16 = F_11 ( V_3 -> V_17 ) ;
return & V_16 -> V_21 ;
}
void F_133 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = F_11 ( V_3 -> V_17 ) ;
if ( V_16 -> V_114 )
F_115 ( V_3 ) ;
else
F_119 ( V_3 ) ;
}
struct V_2 * F_134 ( struct V_31 * V_6 ,
struct V_26 * V_27 ,
struct V_26 * V_148 , int V_41 )
{
struct V_2 * V_3 = NULL ;
struct V_10 * V_10 ;
V_10 = F_104 ( sizeof( * V_10 ) , V_194 ) ;
if ( ! V_10 )
return F_131 ( - V_200 ) ;
V_3 = & V_10 -> V_11 ;
V_10 -> V_41 = V_41 ;
F_135 ( & V_10 -> V_80 ) ;
F_135 ( & V_10 -> V_164 . V_185 ) ;
F_136 ( & V_10 -> V_13 ) ;
V_10 -> V_12 . V_196 = F_109 ;
V_10 -> V_116 . V_196 = F_112 ;
V_10 -> V_115 . V_196 = F_113 ;
if ( V_148 )
F_137 ( V_6 , V_3 , V_27 , V_148 ,
& V_201 , NULL ) ;
else
F_137 ( V_6 , V_3 , V_27 , NULL ,
& V_202 , NULL ) ;
F_138 ( & V_10 -> V_40 ,
L_24 , F_24 ) ;
F_139 ( V_3 , & V_203 ) ;
V_27 -> V_3 = V_3 ;
return V_3 ;
}
