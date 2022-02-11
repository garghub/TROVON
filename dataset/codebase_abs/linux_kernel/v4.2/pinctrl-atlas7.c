static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline T_1 F_3 ( T_1 V_5 )
{
return ( V_5 >= V_6 ) ? 1 : 0 ;
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_5 ( V_8 ) ;
return V_10 -> V_11 -> V_12 ;
}
static const char * F_6 ( struct V_7 * V_8 ,
T_1 V_13 )
{
struct V_9 * V_10 = F_5 ( V_8 ) ;
return V_10 -> V_11 -> V_14 [ V_13 ] . V_15 ;
}
static int F_7 ( struct V_7 * V_8 ,
T_1 V_13 , const char * const * * V_16 ,
T_1 * const V_17 )
{
struct V_9 * V_10 = F_5 ( V_8 ) ;
* V_16 = V_10 -> V_11 -> V_14 [ V_13 ] . V_16 ;
* V_17 = V_10 -> V_11 -> V_14 [ V_13 ] . V_17 ;
return 0 ;
}
static void F_8 ( struct V_9 * V_10 ,
const struct V_18 * V_19 )
{
if ( V_19 -> V_20 && V_19 -> V_21 ) {
F_9 ( V_22 << V_19 -> V_23 ,
V_10 -> V_24 [ V_25 ] + F_10 ( V_19 -> V_20 ) ) ;
F_9 ( V_26 << V_19 -> V_23 ,
V_10 -> V_24 [ V_25 ] + V_19 -> V_20 ) ;
F_9 ( V_27 << V_19 -> V_28 ,
V_10 -> V_24 [ V_25 ] + F_10 ( V_19 -> V_21 ) ) ;
F_9 ( V_29 << V_19 -> V_28 ,
V_10 -> V_24 [ V_25 ] + V_19 -> V_21 ) ;
}
}
static void F_11 ( struct V_9 * V_10 ,
const struct V_18 * V_19 )
{
if ( V_19 -> V_20 && V_19 -> V_21 ) {
F_9 ( V_22 << V_19 -> V_23 ,
V_10 -> V_24 [ V_25 ] + F_10 ( V_19 -> V_20 ) ) ;
F_9 ( V_30 << V_19 -> V_23 ,
V_10 -> V_24 [ V_25 ] + V_19 -> V_20 ) ;
F_9 ( V_27 << V_19 -> V_28 ,
V_10 -> V_24 [ V_25 ] + F_10 ( V_19 -> V_21 ) ) ;
F_9 ( V_31 << V_19 -> V_28 ,
V_10 -> V_24 [ V_25 ] + V_19 -> V_21 ) ;
}
}
static int F_12 ( struct V_9 * V_10 ,
struct V_32 * V_33 ,
T_1 V_34 , T_1 V_35 )
{
unsigned long V_36 ;
F_9 ( V_37 << V_33 -> V_38 ,
V_10 -> V_24 [ V_34 ] + F_10 ( V_33 -> V_39 ) ) ;
V_36 = F_13 ( V_10 -> V_24 [ V_34 ] + V_33 -> V_39 ) ;
V_36 &= ~ ( V_37 << V_33 -> V_38 ) ;
F_9 ( V_36 | ( V_35 << V_33 -> V_38 ) ,
V_10 -> V_24 [ V_34 ] + V_33 -> V_39 ) ;
V_36 = F_13 ( V_10 -> V_24 [ V_34 ] + V_33 -> V_39 ) ;
F_14 ( L_1 ,
V_34 , V_33 -> V_39 , V_36 ) ;
return 0 ;
}
static int F_15 ( struct V_9 * V_10 ,
struct V_32 * V_33 , T_1 V_34 )
{
if ( V_33 -> type != V_40 )
return - V_41 ;
return F_12 ( V_10 , V_33 , V_34 , 0 ) ;
}
static int F_16 ( struct V_9 * V_10 ,
struct V_32 * V_33 , T_1 V_34 )
{
if ( V_33 -> type != V_40 )
return 0 ;
return F_12 ( V_10 , V_33 , V_34 , 1 ) ;
}
static int F_17 ( struct V_9 * V_10 ,
T_1 V_5 , T_1 V_42 )
{
struct V_32 * V_33 ;
T_1 V_34 ;
int V_43 ;
unsigned long V_36 ;
F_14 ( L_2 ,
V_5 , V_42 ) ;
V_33 = & V_10 -> V_11 -> V_44 [ V_5 ] ;
V_34 = F_3 ( V_5 ) ;
if ( V_45 == V_42 ) {
V_43 = F_15 ( V_10 , V_33 , V_34 ) ;
if ( V_43 )
F_18 ( V_10 -> V_46 ,
L_3 ,
V_5 , V_43 ) ;
return V_43 ;
}
V_43 = F_16 ( V_10 , V_33 , V_34 ) ;
if ( V_43 ) {
F_18 ( V_10 -> V_46 ,
L_4 ,
V_5 , V_43 ) ;
return V_43 ;
}
F_9 ( V_47 << V_33 -> V_48 ,
V_10 -> V_24 [ V_34 ] + F_10 ( V_33 -> V_49 ) ) ;
V_36 = F_13 ( V_10 -> V_24 [ V_34 ] + V_33 -> V_49 ) ;
V_36 &= ~ ( V_47 << V_33 -> V_48 ) ;
F_9 ( V_36 | ( V_42 << V_33 -> V_48 ) ,
V_10 -> V_24 [ V_34 ] + V_33 -> V_49 ) ;
V_36 = F_13 ( V_10 -> V_24 [ V_34 ] + V_33 -> V_49 ) ;
F_14 ( L_1 ,
V_34 , V_33 -> V_49 , V_36 ) ;
return 0 ;
}
static int F_19 ( struct V_7 * V_8 ,
T_1 V_50 , T_1 V_51 )
{
int V_52 , V_43 ;
struct V_9 * V_10 = F_5 ( V_8 ) ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
const struct V_57 * V_58 ;
const struct V_18 * V_19 ;
V_54 = & V_10 -> V_11 -> V_14 [ V_50 ] ;
V_56 = & V_10 -> V_11 -> V_59 [ V_51 ] ;
F_14 ( L_5 ,
V_54 -> V_15 , V_56 -> V_15 ) ;
V_58 = V_54 -> V_60 ;
for ( V_52 = 0 ; V_52 < V_58 -> V_61 ; V_52 ++ ) {
V_19 = & V_58 -> V_62 [ V_52 ] ;
F_8 ( V_10 , V_19 ) ;
V_43 = F_17 ( V_10 , V_19 -> V_5 , V_19 -> V_42 ) ;
if ( V_43 ) {
F_18 ( V_10 -> V_46 ,
L_6 ,
V_54 -> V_15 , V_56 -> V_15 ,
V_19 -> V_5 , V_19 -> V_42 , V_43 ) ;
F_20 ( 1 ) ;
}
F_11 ( V_10 , V_19 ) ;
}
F_14 ( L_7 ,
V_54 -> V_15 , V_56 -> V_15 ) ;
return 0 ;
}
static T_1 F_21 ( T_1 type , T_1 V_63 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < F_22 ( V_64 ) ; V_52 ++ ) {
if ( V_64 [ V_52 ] . V_63 != V_63 )
continue;
if ( type == V_65 || type == V_66 )
return V_64 [ V_52 ] . V_67 ;
else if ( type == V_68 )
return V_64 [ V_52 ] . V_69 ;
else if ( type == V_70 || type == V_71 )
return V_64 [ V_52 ] . V_72 ;
else if ( type == V_73 || type == V_74 )
return V_64 [ V_52 ] . V_75 ;
}
return V_76 ;
}
static int F_23 ( struct V_7 * V_8 ,
T_1 V_5 , T_1 V_77 )
{
struct V_9 * V_10 = F_5 ( V_8 ) ;
struct V_32 * V_33 = & V_10 -> V_11 -> V_44 [ V_5 ] ;
T_1 type = V_33 -> type ;
T_1 V_78 = V_33 -> V_79 ;
T_1 V_34 = F_3 ( V_5 ) ;
void T_2 * V_80 , * V_81 ;
V_80 = V_10 -> V_24 [ V_34 ] + V_33 -> V_82 ;
V_81 = F_10 ( V_80 ) ;
if ( type == V_65 || type == V_66 ) {
F_9 ( V_83 << V_78 , V_81 ) ;
if ( V_77 == V_84 )
F_9 ( V_85 << V_78 , V_80 ) ;
else if ( V_77 == V_86 )
F_9 ( V_87 << V_78 , V_80 ) ;
else if ( V_77 == V_88 )
F_9 ( V_89 << V_78 , V_80 ) ;
else if ( V_77 == V_90 )
F_9 ( V_91 << V_78 , V_80 ) ;
else {
F_24 ( L_8 ,
V_5 ) ;
return - V_92 ;
}
} else if ( type == V_68 ) {
F_9 ( V_93 << V_78 , V_81 ) ;
if ( V_77 == V_84 )
F_9 ( V_94 << V_78 , V_80 ) ;
else if ( V_77 == V_88 )
F_9 ( V_95 << V_78 , V_80 ) ;
else if ( V_77 == V_90 )
F_9 ( V_96 << V_78 , V_80 ) ;
else {
F_24 ( L_9 ,
V_5 ) ;
return - V_92 ;
}
} else if ( type == V_70 ||
type == V_71 ||
type == V_73 ||
type == V_74 ) {
F_9 ( V_97 << V_78 , V_81 ) ;
if ( V_77 == V_84 )
F_9 ( V_98 << V_78 , V_80 ) ;
else if ( V_77 == V_90 )
F_9 ( V_99 << V_78 , V_80 ) ;
else {
F_24 ( L_10 ,
V_5 ) ;
return - V_92 ;
}
} else if ( type == V_40 ) {
F_9 ( V_100 << V_78 , V_81 ) ;
if ( V_77 == V_84 )
F_9 ( V_101 << V_78 , V_80 ) ;
else if ( V_77 == V_88 )
F_9 ( V_102 << V_78 , V_80 ) ;
else if ( V_77 == V_90 )
F_9 ( V_103 << V_78 , V_80 ) ;
else {
F_24 ( L_11 ,
V_5 ) ;
return - V_92 ;
}
} else {
F_24 ( L_12 ,
type , V_5 ) ;
return - V_92 ;
}
F_14 ( L_13 ,
V_5 , V_77 ) ;
return 0 ;
}
static int F_25 ( struct V_7 * V_8 ,
T_1 V_5 , T_1 V_77 )
{
struct V_9 * V_10 = F_5 ( V_8 ) ;
struct V_32 * V_33 = & V_10 -> V_11 -> V_44 [ V_5 ] ;
T_1 type = V_33 -> type ;
T_1 V_78 = V_33 -> V_104 ;
T_1 V_34 = F_3 ( V_5 ) ;
void T_2 * V_105 , * V_106 ;
V_105 = V_10 -> V_24 [ V_34 ] + V_33 -> V_107 ;
V_106 = F_10 ( V_105 ) ;
if ( type == V_65 || type == V_66 ) {
if ( V_77 & ( ~ V_108 ) )
goto V_109;
F_9 ( V_110 << V_78 , V_106 ) ;
F_9 ( V_77 << V_78 , V_105 ) ;
return 0 ;
} else if ( type == V_68 ) {
if ( V_77 & ( ~ V_111 ) )
goto V_109;
F_9 ( V_112 << V_78 , V_106 ) ;
F_9 ( V_77 << V_78 , V_105 ) ;
return 0 ;
} else if ( type == V_70 || type == V_71 ||
type == V_73 || type == V_74 ) {
if ( V_77 & ( ~ V_113 ) )
goto V_109;
F_9 ( V_114 << V_78 , V_106 ) ;
F_9 ( V_77 << V_78 , V_105 ) ;
return 0 ;
}
V_109:
F_24 ( L_14 ,
V_5 , type , V_77 ) ;
return - V_92 ;
}
static int F_26 ( struct V_7 * V_8 ,
T_1 V_5 , T_1 V_63 )
{
struct V_9 * V_10 = F_5 ( V_8 ) ;
struct V_32 * V_33 = & V_10 -> V_11 -> V_44 [ V_5 ] ;
T_1 type = V_33 -> type ;
T_1 V_77 ;
int V_43 ;
V_77 = F_21 ( V_33 -> type , V_63 ) ;
if ( V_76 == V_77 ) {
F_24 ( L_15 ,
V_5 , type , V_63 ) ;
return - V_92 ;
}
V_43 = F_25 ( V_8 ,
V_5 , V_77 ) ;
F_14 ( L_16 ,
V_5 , V_77 , V_63 , V_43 ? L_17 : L_18 ) ;
return V_43 ;
}
static int F_27 ( struct V_7 * V_8 ,
struct V_115 * V_116 , T_1 V_5 )
{
struct V_9 * V_10 = F_5 ( V_8 ) ;
T_1 V_52 ;
F_28 ( V_10 -> V_46 ,
L_19 , V_5 ) ;
for ( V_52 = 0 ; V_52 < V_116 -> V_117 ; V_52 ++ ) {
if ( V_5 == V_116 -> V_118 [ V_52 ] )
break;
}
if ( V_52 >= V_116 -> V_117 ) {
F_18 ( V_10 -> V_46 ,
L_20 ,
V_5 ) ;
return - V_119 ;
}
F_17 ( V_10 , V_5 , V_120 ) ;
return 0 ;
}
static int F_29 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_5 ( V_8 ) ;
return V_10 -> V_11 -> V_121 ;
}
static const char * F_30 ( struct V_7 * V_8 ,
T_1 V_122 )
{
struct V_9 * V_10 = F_5 ( V_8 ) ;
return V_10 -> V_11 -> V_59 [ V_122 ] . V_15 ;
}
static int F_31 ( struct V_7 * V_8 ,
T_1 V_122 , const T_1 * * V_118 , T_1 * V_123 )
{
struct V_9 * V_10 = F_5 ( V_8 ) ;
* V_123 = V_10 -> V_11 -> V_59 [ V_122 ] . V_123 ;
* V_118 = V_10 -> V_11 -> V_59 [ V_122 ] . V_118 ;
return 0 ;
}
static int F_32 ( struct V_7 * V_8 ,
struct V_124 * V_125 ,
struct V_126 * * V_127 ,
T_1 * V_128 )
{
return F_33 ( V_8 , V_125 , V_127 ,
V_128 , V_129 ) ;
}
static void F_34 ( struct V_7 * V_8 ,
struct V_126 * V_127 , T_1 V_128 )
{
F_35 ( V_127 ) ;
}
static int F_36 ( struct V_7 * V_8 ,
unsigned V_5 , unsigned long * V_130 ,
unsigned V_131 )
{
T_3 V_132 , V_133 ;
int V_52 , V_134 ;
for ( V_52 = 0 ; V_52 < V_131 ; V_52 ++ ) {
V_132 = F_37 ( V_130 [ V_52 ] ) ;
V_133 = F_38 ( V_130 [ V_52 ] ) ;
F_14 ( L_21 ,
V_5 , V_135 [ V_5 ] . V_15 , V_132 , V_133 ) ;
switch ( V_132 ) {
case V_136 :
V_134 = F_23 ( V_8 ,
V_5 , V_84 ) ;
if ( V_134 )
return V_134 ;
break;
case V_137 :
V_134 = F_23 ( V_8 ,
V_5 , V_90 ) ;
if ( V_134 )
return V_134 ;
break;
case V_138 :
V_134 = F_23 ( V_8 ,
V_5 , V_86 ) ;
if ( V_134 )
return V_134 ;
break;
case V_139 :
V_134 = F_23 ( V_8 ,
V_5 , V_88 ) ;
if ( V_134 )
return V_134 ;
break;
case V_140 :
V_134 = F_26 ( V_8 ,
V_5 , V_133 ) ;
if ( V_134 )
return V_134 ;
break;
default:
return - V_92 ;
}
F_14 ( L_22 ,
V_5 , V_135 [ V_5 ] . V_15 , V_132 , V_133 ) ;
}
return 0 ;
}
static int F_39 ( struct V_7 * V_8 ,
unsigned V_122 , unsigned long * V_130 ,
unsigned V_131 )
{
const unsigned * V_118 ;
unsigned V_117 ;
int V_141 , V_43 ;
V_43 = F_31 ( V_8 , V_122 , & V_118 , & V_117 ) ;
if ( V_43 )
return V_43 ;
for ( V_141 = 0 ; V_141 < V_117 ; V_141 ++ ) {
if ( F_36 ( V_8 , V_118 [ V_141 ] ,
V_130 , V_131 ) )
return - V_92 ;
}
return 0 ;
}
static int F_40 ( struct V_142 * V_143 )
{
int V_43 , V_52 ;
struct V_9 * V_10 ;
struct V_124 * V_144 = V_143 -> V_46 . V_145 ;
T_1 V_146 = V_147 ;
V_10 = F_41 ( & V_143 -> V_46 , sizeof( * V_10 ) , V_148 ) ;
if ( ! V_10 )
return - V_149 ;
V_10 -> V_46 = & V_143 -> V_46 ;
V_10 -> V_11 = & V_150 ;
V_10 -> V_151 . V_15 = L_23 ;
V_10 -> V_151 . V_118 = V_10 -> V_11 -> V_152 ;
V_10 -> V_151 . V_117 = V_10 -> V_11 -> V_153 ;
V_10 -> V_151 . V_154 = & V_155 ;
V_10 -> V_151 . V_156 = & V_157 ;
V_10 -> V_151 . V_158 = & V_159 ;
for ( V_52 = 0 ; V_52 < V_146 ; V_52 ++ ) {
V_10 -> V_24 [ V_52 ] = F_42 ( V_144 , V_52 ) ;
if ( ! V_10 -> V_24 [ V_52 ] ) {
F_18 ( & V_143 -> V_46 ,
L_24 , V_52 ) ;
V_43 = - V_149 ;
goto V_160;
}
}
V_10 -> V_161 = F_43 ( & V_10 -> V_151 , & V_143 -> V_46 , V_10 ) ;
if ( F_44 ( V_10 -> V_161 ) ) {
F_18 ( & V_143 -> V_46 , L_25 ) ;
V_43 = F_45 ( V_10 -> V_161 ) ;
goto V_160;
}
F_46 ( V_143 , V_10 ) ;
F_47 ( & V_143 -> V_46 , L_26 ) ;
return 0 ;
V_160:
for ( V_52 = 0 ; V_52 < V_146 ; V_52 ++ ) {
if ( ! V_10 -> V_24 [ V_52 ] )
break;
F_48 ( V_10 -> V_24 [ V_52 ] ) ;
}
return V_43 ;
}
static int T_4 F_49 ( void )
{
return F_50 ( & V_162 ) ;
}
static inline struct
V_163 * F_51 ( struct V_1 * V_164 , T_1 V_165 )
{
return & V_164 -> V_146 [ F_52 ( V_165 ) ] ;
}
static int F_53 ( struct V_1 * V_164 , T_1 V_165 )
{
struct V_163 * V_34 ;
T_1 V_166 ;
V_34 = F_51 ( V_164 , V_165 ) ;
V_166 = V_165 - V_34 -> V_167 ;
if ( V_166 >= V_34 -> V_168 )
return - V_169 ;
return V_34 -> V_170 [ V_166 ] ;
}
static void F_54 ( struct V_171 * V_172 )
{
struct V_2 * V_3 = F_55 ( V_172 ) ;
struct V_1 * V_164 = F_1 ( V_3 ) ;
struct V_163 * V_34 ;
void T_2 * V_173 ;
T_1 V_174 , V_175 ;
unsigned long V_176 ;
V_34 = F_51 ( V_164 , V_172 -> V_177 ) ;
V_175 = V_172 -> V_177 - V_34 -> V_167 ;
V_173 = F_56 ( V_34 , V_175 ) ;
F_57 ( & V_164 -> V_178 , V_176 ) ;
V_174 = F_13 ( V_173 ) ;
F_9 ( V_174 , V_173 ) ;
F_58 ( & V_164 -> V_178 , V_176 ) ;
}
static void F_59 ( struct V_1 * V_164 , int V_52 )
{
struct V_163 * V_34 ;
void T_2 * V_173 ;
T_1 V_174 , V_175 ;
V_34 = F_51 ( V_164 , V_52 ) ;
V_175 = V_52 - V_34 -> V_167 ;
V_173 = F_56 ( V_34 , V_175 ) ;
V_174 = F_13 ( V_173 ) ;
V_174 &= ~ ( V_179 |
V_180 ) ;
F_9 ( V_174 , V_173 ) ;
}
static void F_60 ( struct V_171 * V_172 )
{
struct V_2 * V_3 = F_55 ( V_172 ) ;
struct V_1 * V_164 = F_1 ( V_3 ) ;
unsigned long V_176 ;
F_57 ( & V_164 -> V_178 , V_176 ) ;
F_59 ( V_164 , V_172 -> V_177 ) ;
F_58 ( & V_164 -> V_178 , V_176 ) ;
}
static void F_61 ( struct V_171 * V_172 )
{
struct V_2 * V_3 = F_55 ( V_172 ) ;
struct V_1 * V_164 = F_1 ( V_3 ) ;
struct V_163 * V_34 ;
void T_2 * V_173 ;
T_1 V_174 , V_175 ;
unsigned long V_176 ;
V_34 = F_51 ( V_164 , V_172 -> V_177 ) ;
V_175 = V_172 -> V_177 - V_34 -> V_167 ;
V_173 = F_56 ( V_34 , V_175 ) ;
F_57 ( & V_164 -> V_178 , V_176 ) ;
V_174 = F_13 ( V_173 ) ;
V_174 &= ~ V_180 ;
V_174 |= V_179 ;
F_9 ( V_174 , V_173 ) ;
F_58 ( & V_164 -> V_178 , V_176 ) ;
}
static int F_62 ( struct V_171 * V_172 ,
unsigned int type )
{
struct V_2 * V_3 = F_55 ( V_172 ) ;
struct V_1 * V_164 = F_1 ( V_3 ) ;
struct V_163 * V_34 ;
void T_2 * V_173 ;
T_1 V_174 , V_175 ;
unsigned long V_176 ;
V_34 = F_51 ( V_164 , V_172 -> V_177 ) ;
V_175 = V_172 -> V_177 - V_34 -> V_167 ;
V_173 = F_56 ( V_34 , V_175 ) ;
F_57 ( & V_164 -> V_178 , V_176 ) ;
V_174 = F_13 ( V_173 ) ;
V_174 &= ~ ( V_180 |
V_179 ) ;
switch ( type ) {
case V_181 :
break;
case V_182 :
V_174 |= V_183 |
V_184 ;
V_174 &= ~ V_185 ;
break;
case V_186 :
V_174 &= ~ V_183 ;
V_174 |= V_185 |
V_184 ;
break;
case V_187 :
V_174 |= V_183 |
V_185 |
V_184 ;
break;
case V_188 :
V_174 &= ~ ( V_183 |
V_184 ) ;
V_174 |= V_185 ;
break;
case V_189 :
V_174 |= V_183 ;
V_174 &= ~ ( V_185 |
V_184 ) ;
break;
}
F_9 ( V_174 , V_173 ) ;
F_58 ( & V_164 -> V_178 , V_176 ) ;
return 0 ;
}
static void F_63 ( unsigned int V_190 , struct V_191 * V_192 )
{
struct V_2 * V_3 = F_64 ( V_192 ) ;
struct V_1 * V_164 = F_1 ( V_3 ) ;
struct V_163 * V_34 = NULL ;
T_1 V_193 , V_194 ;
int V_175 = 0 , V_52 ;
struct V_195 * V_4 = F_65 ( V_190 ) ;
for ( V_52 = 0 ; V_52 < V_164 -> V_196 ; V_52 ++ ) {
V_34 = & V_164 -> V_146 [ V_52 ] ;
if ( V_34 -> V_190 == V_190 )
break;
}
F_20 ( V_52 == V_164 -> V_196 ) ;
F_66 ( V_4 , V_192 ) ;
V_193 = F_13 ( F_67 ( V_34 ) ) ;
if ( ! V_193 ) {
F_68 ( L_27 ,
V_197 , V_3 -> V_198 , V_193 ) ;
F_69 ( V_190 , V_192 ) ;
return;
}
while ( V_193 ) {
V_194 = F_13 ( F_56 ( V_34 , V_175 ) ) ;
if ( ( V_193 & 0x1 ) && ( V_194 & V_179 ) ) {
F_14 ( L_28 ,
V_197 , V_3 -> V_198 ,
V_34 -> V_167 + V_175 ) ;
F_70 (
F_71 ( V_3 -> V_199 ,
V_34 -> V_167 + V_175 ) ) ;
}
if ( ++ V_175 >= V_34 -> V_168 )
break;
V_193 = V_193 >> 1 ;
}
F_72 ( V_4 , V_192 ) ;
}
static void F_73 ( struct V_1 * V_164 ,
unsigned int V_165 )
{
struct V_163 * V_34 ;
void T_2 * V_173 ;
T_1 V_174 , V_175 ;
V_34 = F_51 ( V_164 , V_165 ) ;
V_175 = V_165 - V_34 -> V_167 ;
V_173 = F_56 ( V_34 , V_175 ) ;
V_174 = F_13 ( V_173 ) ;
V_174 &= ~ V_200 ;
F_9 ( V_174 , V_173 ) ;
}
static int F_74 ( struct V_2 * V_4 ,
unsigned int V_165 )
{
struct V_1 * V_164 = F_1 ( V_4 ) ;
int V_43 ;
unsigned long V_176 ;
V_43 = F_53 ( V_164 , V_165 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( F_75 ( V_4 -> V_201 + V_165 ) )
return - V_169 ;
F_57 ( & V_164 -> V_178 , V_176 ) ;
F_73 ( V_164 , V_165 ) ;
F_59 ( V_164 , V_165 ) ;
F_58 ( & V_164 -> V_178 , V_176 ) ;
return 0 ;
}
static void F_76 ( struct V_2 * V_4 ,
unsigned int V_165 )
{
struct V_1 * V_164 = F_1 ( V_4 ) ;
unsigned long V_176 ;
F_57 ( & V_164 -> V_178 , V_176 ) ;
F_59 ( V_164 , V_165 ) ;
F_73 ( V_164 , V_165 ) ;
F_58 ( & V_164 -> V_178 , V_176 ) ;
F_77 ( V_4 -> V_201 + V_165 ) ;
}
static int F_78 ( struct V_2 * V_4 ,
unsigned int V_165 )
{
struct V_1 * V_164 = F_1 ( V_4 ) ;
unsigned long V_176 ;
F_57 ( & V_164 -> V_178 , V_176 ) ;
F_73 ( V_164 , V_165 ) ;
F_58 ( & V_164 -> V_178 , V_176 ) ;
return 0 ;
}
static void F_79 ( struct V_1 * V_164 ,
unsigned int V_165 , int V_202 )
{
struct V_163 * V_34 ;
void T_2 * V_173 ;
T_1 V_203 , V_175 ;
V_34 = F_51 ( V_164 , V_165 ) ;
V_175 = V_165 - V_34 -> V_167 ;
V_173 = F_56 ( V_34 , V_175 ) ;
V_203 = F_13 ( V_173 ) ;
if ( V_202 )
V_203 |= V_204 ;
else
V_203 &= ~ V_204 ;
V_203 &= ~ V_179 ;
V_203 |= V_200 ;
F_9 ( V_203 , V_173 ) ;
}
static int F_80 ( struct V_2 * V_4 ,
unsigned int V_165 , int V_202 )
{
struct V_1 * V_164 = F_1 ( V_4 ) ;
unsigned long V_176 ;
F_57 ( & V_164 -> V_178 , V_176 ) ;
F_79 ( V_164 , V_165 , V_202 ) ;
F_58 ( & V_164 -> V_178 , V_176 ) ;
return 0 ;
}
static int F_81 ( struct V_2 * V_4 ,
unsigned int V_165 )
{
struct V_1 * V_164 = F_1 ( V_4 ) ;
struct V_163 * V_34 ;
T_1 V_174 , V_175 ;
unsigned long V_176 ;
V_34 = F_51 ( V_164 , V_165 ) ;
V_175 = V_165 - V_34 -> V_167 ;
F_57 ( & V_164 -> V_178 , V_176 ) ;
V_174 = F_13 ( F_56 ( V_34 , V_175 ) ) ;
F_58 ( & V_164 -> V_178 , V_176 ) ;
return ! ! ( V_174 & V_205 ) ;
}
static void F_82 ( struct V_2 * V_4 ,
unsigned int V_165 , int V_202 )
{
struct V_1 * V_164 = F_1 ( V_4 ) ;
struct V_163 * V_34 ;
void T_2 * V_173 ;
T_1 V_194 , V_175 ;
unsigned long V_176 ;
V_34 = F_51 ( V_164 , V_165 ) ;
V_175 = V_165 - V_34 -> V_167 ;
V_173 = F_56 ( V_34 , V_175 ) ;
F_57 ( & V_164 -> V_178 , V_176 ) ;
V_194 = F_13 ( V_173 ) ;
if ( V_202 )
V_194 |= V_204 ;
else
V_194 &= ~ V_204 ;
F_9 ( V_194 , V_173 ) ;
F_58 ( & V_164 -> V_178 , V_176 ) ;
}
static int F_83 ( struct V_142 * V_143 )
{
struct V_124 * V_144 = V_143 -> V_46 . V_145 ;
struct V_1 * V_164 ;
struct V_2 * V_4 ;
T_1 V_196 ;
int V_43 , V_52 ;
V_43 = F_84 ( V_144 , L_29 , & V_196 ) ;
if ( V_43 ) {
F_18 ( & V_143 -> V_46 ,
L_30 ,
V_43 ) ;
return V_43 ;
}
V_164 = F_41 ( & V_143 -> V_46 , sizeof( * V_164 ) +
sizeof( struct V_163 ) * V_196 , V_148 ) ;
if ( ! V_164 )
return - V_149 ;
V_164 -> V_206 = F_85 ( V_144 , 0 ) ;
if ( ! F_44 ( V_164 -> V_206 ) ) {
V_43 = F_86 ( V_164 -> V_206 ) ;
if ( V_43 ) {
F_18 ( & V_143 -> V_46 ,
L_31 ) ;
return V_43 ;
}
}
V_164 -> V_207 = F_42 ( V_144 , 0 ) ;
if ( ! V_164 -> V_207 ) {
F_18 ( & V_143 -> V_46 , L_32 ) ;
return - V_149 ;
}
V_164 -> V_196 = V_196 ;
F_87 ( & V_164 -> V_178 ) ;
V_4 = & V_164 -> V_4 ;
V_4 -> V_208 = F_74 ;
V_4 -> free = F_76 ;
V_4 -> V_209 = F_78 ;
V_4 -> V_210 = F_81 ;
V_4 -> V_211 = F_80 ;
V_4 -> V_212 = F_82 ;
V_4 -> V_201 = - 1 ;
V_4 -> V_168 = V_213 * V_196 ;
V_4 -> V_198 = F_88 ( V_144 -> V_15 , V_148 ) ;
V_4 -> V_145 = V_144 ;
V_4 -> V_214 = 2 ;
V_4 -> V_46 = & V_143 -> V_46 ;
V_43 = F_89 ( V_4 ) ;
if ( V_43 ) {
F_18 ( & V_143 -> V_46 ,
L_33 ,
V_144 -> V_15 , V_43 ) ;
goto V_215;
}
V_43 = F_90 ( V_4 , & V_216 ,
0 , V_217 , V_181 ) ;
if ( V_43 ) {
F_18 ( & V_143 -> V_46 ,
L_34 ) ;
goto V_215;
}
for ( V_52 = 0 ; V_52 < V_196 ; V_52 ++ ) {
struct V_218 * V_219 ;
struct V_163 * V_34 ;
V_34 = & V_164 -> V_146 [ V_52 ] ;
V_34 -> V_201 = F_91 ( V_164 , V_52 ) ;
V_43 = F_92 ( V_144 , V_52 ) ;
if ( V_43 == - V_220 ) {
F_18 ( & V_143 -> V_46 ,
L_35 , V_43 ) ;
goto V_215;
}
V_34 -> V_190 = V_43 ;
F_93 ( V_4 , & V_216 ,
V_34 -> V_190 , F_63 ) ;
F_94 (pin_range, &chip->pin_ranges, node) {
struct V_115 * V_116 ;
V_116 = & V_219 -> V_116 ;
if ( V_116 -> V_221 == V_213 * V_52 ) {
V_34 -> V_167 = V_116 -> V_221 ;
V_34 -> V_168 = V_116 -> V_117 ;
V_34 -> V_170 = V_116 -> V_118 ;
V_34 -> V_8 = V_219 -> V_8 ;
break;
}
}
F_20 ( ! V_34 -> V_8 ) ;
}
F_47 ( & V_143 -> V_46 , L_36 ) ;
return 0 ;
V_215:
return V_43 ;
}
static int T_4 F_95 ( void )
{
return F_50 ( & V_222 ) ;
}
