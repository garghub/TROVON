static inline T_1 F_1 ( T_1 V_1 )
{
return ( V_1 >= V_2 ) ? 1 : 0 ;
}
static int F_2 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
return V_6 -> V_7 -> V_8 ;
}
static const char * F_4 ( struct V_3 * V_4 ,
T_1 V_9 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
return V_6 -> V_7 -> V_10 [ V_9 ] . V_11 ;
}
static int F_5 ( struct V_3 * V_4 ,
T_1 V_9 , const char * const * * V_12 ,
T_1 * const V_13 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
* V_12 = V_6 -> V_7 -> V_10 [ V_9 ] . V_12 ;
* V_13 = V_6 -> V_7 -> V_10 [ V_9 ] . V_13 ;
return 0 ;
}
static void F_6 ( struct V_5 * V_6 ,
const struct V_14 * V_15 )
{
if ( V_15 -> V_16 && V_15 -> V_17 ) {
F_7 ( V_18 << V_15 -> V_19 ,
V_6 -> V_20 [ V_21 ] + F_8 ( V_15 -> V_16 ) ) ;
F_7 ( V_22 << V_15 -> V_19 ,
V_6 -> V_20 [ V_21 ] + V_15 -> V_16 ) ;
F_7 ( V_23 << V_15 -> V_24 ,
V_6 -> V_20 [ V_21 ] + F_8 ( V_15 -> V_17 ) ) ;
F_7 ( V_25 << V_15 -> V_24 ,
V_6 -> V_20 [ V_21 ] + V_15 -> V_17 ) ;
}
}
static void F_9 ( struct V_5 * V_6 ,
const struct V_14 * V_15 )
{
if ( V_15 -> V_16 && V_15 -> V_17 ) {
F_7 ( V_18 << V_15 -> V_19 ,
V_6 -> V_20 [ V_21 ] + F_8 ( V_15 -> V_16 ) ) ;
F_7 ( V_26 << V_15 -> V_19 ,
V_6 -> V_20 [ V_21 ] + V_15 -> V_16 ) ;
F_7 ( V_23 << V_15 -> V_24 ,
V_6 -> V_20 [ V_21 ] + F_8 ( V_15 -> V_17 ) ) ;
F_7 ( V_27 << V_15 -> V_24 ,
V_6 -> V_20 [ V_21 ] + V_15 -> V_17 ) ;
}
}
static int F_10 ( struct V_5 * V_6 ,
struct V_28 * V_29 ,
T_1 V_30 , T_1 V_31 )
{
unsigned long V_32 ;
F_7 ( V_33 << V_29 -> V_34 ,
V_6 -> V_20 [ V_30 ] + F_8 ( V_29 -> V_35 ) ) ;
V_32 = F_11 ( V_6 -> V_20 [ V_30 ] + V_29 -> V_35 ) ;
V_32 &= ~ ( V_33 << V_29 -> V_34 ) ;
F_7 ( V_32 | ( V_31 << V_29 -> V_34 ) ,
V_6 -> V_20 [ V_30 ] + V_29 -> V_35 ) ;
V_32 = F_11 ( V_6 -> V_20 [ V_30 ] + V_29 -> V_35 ) ;
F_12 ( L_1 ,
V_30 , V_29 -> V_35 , V_32 ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 ,
struct V_28 * V_29 , T_1 V_30 )
{
if ( V_29 -> type != V_36 )
return - V_37 ;
return F_10 ( V_6 , V_29 , V_30 , 0 ) ;
}
static int F_14 ( struct V_5 * V_6 ,
struct V_28 * V_29 , T_1 V_30 )
{
if ( V_29 -> type != V_36 )
return 0 ;
return F_10 ( V_6 , V_29 , V_30 , 1 ) ;
}
static int F_15 ( struct V_5 * V_6 ,
T_1 V_1 , T_1 V_38 )
{
struct V_28 * V_29 ;
T_1 V_30 ;
int V_39 ;
unsigned long V_32 ;
F_12 ( L_2 ,
V_1 , V_38 ) ;
V_29 = & V_6 -> V_7 -> V_40 [ V_1 ] ;
V_30 = F_1 ( V_1 ) ;
if ( V_41 == V_38 ) {
V_39 = F_13 ( V_6 , V_29 , V_30 ) ;
if ( V_39 )
F_16 ( V_6 -> V_42 ,
L_3 ,
V_1 , V_39 ) ;
return V_39 ;
}
V_39 = F_14 ( V_6 , V_29 , V_30 ) ;
if ( V_39 ) {
F_16 ( V_6 -> V_42 ,
L_4 ,
V_1 , V_39 ) ;
return V_39 ;
}
F_7 ( V_43 << V_29 -> V_44 ,
V_6 -> V_20 [ V_30 ] + F_8 ( V_29 -> V_45 ) ) ;
V_32 = F_11 ( V_6 -> V_20 [ V_30 ] + V_29 -> V_45 ) ;
V_32 &= ~ ( V_43 << V_29 -> V_44 ) ;
F_7 ( V_32 | ( V_38 << V_29 -> V_44 ) ,
V_6 -> V_20 [ V_30 ] + V_29 -> V_45 ) ;
V_32 = F_11 ( V_6 -> V_20 [ V_30 ] + V_29 -> V_45 ) ;
F_12 ( L_1 ,
V_30 , V_29 -> V_45 , V_32 ) ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 ,
T_1 V_46 , T_1 V_47 )
{
int V_48 , V_39 ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
const struct V_53 * V_54 ;
const struct V_14 * V_15 ;
V_50 = & V_6 -> V_7 -> V_10 [ V_46 ] ;
V_52 = & V_6 -> V_7 -> V_55 [ V_47 ] ;
F_12 ( L_5 ,
V_50 -> V_11 , V_52 -> V_11 ) ;
if ( V_52 -> V_56 == ( unsigned int * ) & V_57 ) {
if ( ! strcmp ( V_50 -> V_11 , L_6 ) )
F_7 ( 1 , V_6 -> V_58 + V_59 ) ;
else
F_7 ( 0 , V_6 -> V_58 + V_59 ) ;
}
V_54 = V_50 -> V_60 ;
for ( V_48 = 0 ; V_48 < V_54 -> V_61 ; V_48 ++ ) {
V_15 = & V_54 -> V_62 [ V_48 ] ;
F_6 ( V_6 , V_15 ) ;
V_39 = F_15 ( V_6 , V_15 -> V_1 , V_15 -> V_38 ) ;
if ( V_39 ) {
F_16 ( V_6 -> V_42 ,
L_7 ,
V_50 -> V_11 , V_52 -> V_11 ,
V_15 -> V_1 , V_15 -> V_38 , V_39 ) ;
F_18 ( 1 ) ;
}
F_9 ( V_6 , V_15 ) ;
}
F_12 ( L_8 ,
V_50 -> V_11 , V_52 -> V_11 ) ;
return 0 ;
}
static T_1 F_19 ( T_1 type , T_1 V_63 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < F_20 ( V_64 ) ; V_48 ++ ) {
if ( V_64 [ V_48 ] . V_63 != V_63 )
continue;
if ( type == V_65 || type == V_66 )
return V_64 [ V_48 ] . V_67 ;
else if ( type == V_68 )
return V_64 [ V_48 ] . V_69 ;
else if ( type == V_70 || type == V_71 )
return V_64 [ V_48 ] . V_72 ;
else if ( type == V_73 || type == V_74 )
return V_64 [ V_48 ] . V_75 ;
}
return V_76 ;
}
static int F_21 ( struct V_3 * V_4 ,
T_1 V_1 , T_1 V_77 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_28 * V_29 = & V_6 -> V_7 -> V_40 [ V_1 ] ;
const struct V_78 * V_79 ;
T_1 V_30 ;
unsigned long V_32 ;
void T_2 * V_80 ;
V_30 = F_1 ( V_1 ) ;
V_79 = & V_81 [ V_29 -> type ] ;
V_80 = V_6 -> V_20 [ V_30 ] + V_29 -> V_82 ;
V_32 = V_79 -> V_83 [ V_77 ] . V_84 & V_79 -> V_85 ;
F_7 ( V_79 -> V_85 << V_29 -> V_86 , F_8 ( V_80 ) ) ;
F_7 ( V_32 << V_29 -> V_86 , V_80 ) ;
F_12 ( L_9 ,
V_1 , V_77 ) ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 ,
T_1 V_1 , T_1 V_77 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_28 * V_29 = & V_6 -> V_7 -> V_40 [ V_1 ] ;
const struct V_87 * V_88 ;
T_1 V_30 ;
void T_2 * V_89 ;
V_88 = & V_90 [ V_29 -> type ] ;
if ( V_77 & ( ~ ( V_88 -> V_85 ) ) )
goto V_91;
V_30 = F_1 ( V_1 ) ;
V_89 = V_6 -> V_20 [ V_30 ] + V_29 -> V_92 ;
F_7 ( V_88 -> V_93 << V_29 -> V_94 , F_8 ( V_89 ) ) ;
F_7 ( V_77 << V_29 -> V_94 , V_89 ) ;
return 0 ;
V_91:
F_23 ( L_10 ,
V_1 , V_29 -> type , V_77 ) ;
return - V_95 ;
}
static int F_24 ( struct V_3 * V_4 ,
T_1 V_1 , T_1 V_63 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_28 * V_29 = & V_6 -> V_7 -> V_40 [ V_1 ] ;
T_1 type = V_29 -> type ;
T_1 V_77 ;
int V_39 ;
V_77 = F_19 ( V_29 -> type , V_63 ) ;
if ( V_76 == V_77 ) {
F_23 ( L_11 ,
V_1 , type , V_63 ) ;
return - V_95 ;
}
V_39 = F_22 ( V_4 ,
V_1 , V_77 ) ;
F_12 ( L_12 ,
V_1 , V_77 , V_63 , V_39 ? L_13 : L_14 ) ;
return V_39 ;
}
static int F_25 ( struct V_3 * V_4 ,
struct V_96 * V_97 , T_1 V_1 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
T_1 V_48 ;
F_26 ( V_6 -> V_42 ,
L_15 , V_1 ) ;
for ( V_48 = 0 ; V_48 < V_97 -> V_98 ; V_48 ++ ) {
if ( V_1 == V_97 -> V_56 [ V_48 ] )
break;
}
if ( V_48 >= V_97 -> V_98 ) {
F_16 ( V_6 -> V_42 ,
L_16 ,
V_1 ) ;
return - V_99 ;
}
F_15 ( V_6 , V_1 , V_100 ) ;
return 0 ;
}
static int F_27 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
return V_6 -> V_7 -> V_101 ;
}
static const char * F_28 ( struct V_3 * V_4 ,
T_1 V_102 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
return V_6 -> V_7 -> V_55 [ V_102 ] . V_11 ;
}
static int F_29 ( struct V_3 * V_4 ,
T_1 V_102 , const T_1 * * V_56 , T_1 * V_103 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
* V_103 = V_6 -> V_7 -> V_55 [ V_102 ] . V_103 ;
* V_56 = V_6 -> V_7 -> V_55 [ V_102 ] . V_56 ;
return 0 ;
}
static int F_30 ( struct V_3 * V_4 ,
struct V_104 * V_105 ,
struct V_106 * * V_107 ,
T_1 * V_108 )
{
return F_31 ( V_4 , V_105 , V_107 ,
V_108 , V_109 ) ;
}
static void F_32 ( struct V_3 * V_4 ,
struct V_106 * V_107 , T_1 V_108 )
{
F_33 ( V_107 ) ;
}
static int F_34 ( struct V_3 * V_4 ,
unsigned V_1 , unsigned long * V_110 ,
unsigned V_111 )
{
T_3 V_112 , V_113 ;
int V_48 , V_114 ;
for ( V_48 = 0 ; V_48 < V_111 ; V_48 ++ ) {
V_112 = F_35 ( V_110 [ V_48 ] ) ;
V_113 = F_36 ( V_110 [ V_48 ] ) ;
F_12 ( L_17 ,
V_1 , V_115 [ V_1 ] . V_11 , V_112 , V_113 ) ;
switch ( V_112 ) {
case V_116 :
V_114 = F_21 ( V_4 ,
V_1 , V_117 ) ;
if ( V_114 )
return V_114 ;
break;
case V_118 :
V_114 = F_21 ( V_4 ,
V_1 , V_119 ) ;
if ( V_114 )
return V_114 ;
break;
case V_120 :
V_114 = F_21 ( V_4 ,
V_1 , V_121 ) ;
if ( V_114 )
return V_114 ;
break;
case V_122 :
V_114 = F_21 ( V_4 ,
V_1 , V_123 ) ;
if ( V_114 )
return V_114 ;
break;
case V_124 :
V_114 = F_24 ( V_4 ,
V_1 , V_113 ) ;
if ( V_114 )
return V_114 ;
break;
default:
return - V_95 ;
}
F_12 ( L_18 ,
V_1 , V_115 [ V_1 ] . V_11 , V_112 , V_113 ) ;
}
return 0 ;
}
static int F_37 ( struct V_3 * V_4 ,
unsigned V_102 , unsigned long * V_110 ,
unsigned V_111 )
{
const unsigned * V_56 ;
unsigned V_98 ;
int V_125 , V_39 ;
V_39 = F_29 ( V_4 , V_102 , & V_56 , & V_98 ) ;
if ( V_39 )
return V_39 ;
for ( V_125 = 0 ; V_125 < V_98 ; V_125 ++ ) {
if ( F_34 ( V_4 , V_56 [ V_125 ] ,
V_110 , V_111 ) )
return - V_95 ;
}
return 0 ;
}
static int F_38 ( struct V_126 * V_127 )
{
int V_39 , V_48 ;
struct V_5 * V_6 ;
struct V_104 * V_128 = V_127 -> V_42 . V_129 ;
T_1 V_130 = V_131 ;
struct V_104 * V_132 ;
struct V_133 V_134 ;
V_6 = F_39 ( & V_127 -> V_42 , sizeof( * V_6 ) , V_135 ) ;
if ( ! V_6 )
return - V_136 ;
V_132 = F_40 ( NULL , L_19 ) ;
if ( ! V_132 )
return - V_37 ;
V_39 = F_41 ( V_132 , 0 , & V_134 ) ;
if ( V_39 )
return V_39 ;
V_6 -> V_58 = F_42 ( & V_127 -> V_42 , & V_134 ) ;
if ( F_43 ( V_6 -> V_58 ) )
return - V_136 ;
V_6 -> V_42 = & V_127 -> V_42 ;
V_6 -> V_7 = & V_137 ;
V_6 -> V_138 . V_11 = L_20 ;
V_6 -> V_138 . V_56 = V_6 -> V_7 -> V_139 ;
V_6 -> V_138 . V_98 = V_6 -> V_7 -> V_140 ;
V_6 -> V_138 . V_141 = & V_142 ;
V_6 -> V_138 . V_143 = & V_144 ;
V_6 -> V_138 . V_145 = & V_146 ;
for ( V_48 = 0 ; V_48 < V_130 ; V_48 ++ ) {
V_6 -> V_20 [ V_48 ] = F_44 ( V_128 , V_48 ) ;
if ( ! V_6 -> V_20 [ V_48 ] ) {
F_16 ( & V_127 -> V_42 ,
L_21 , V_48 ) ;
V_39 = - V_136 ;
goto V_147;
}
}
V_6 -> V_148 = F_45 ( & V_6 -> V_138 , & V_127 -> V_42 , V_6 ) ;
if ( F_43 ( V_6 -> V_148 ) ) {
F_16 ( & V_127 -> V_42 , L_22 ) ;
V_39 = F_46 ( V_6 -> V_148 ) ;
goto V_147;
}
F_47 ( V_127 , V_6 ) ;
F_48 ( & V_127 -> V_42 , L_23 ) ;
return 0 ;
V_147:
for ( V_48 = 0 ; V_48 < V_130 ; V_48 ++ ) {
if ( ! V_6 -> V_20 [ V_48 ] )
break;
F_49 ( V_6 -> V_20 [ V_48 ] ) ;
}
return V_39 ;
}
static int F_50 ( struct V_149 * V_42 )
{
struct V_5 * V_6 = F_51 ( V_42 ) ;
struct V_150 * V_151 ;
struct V_28 * V_29 ;
const struct V_87 * V_88 ;
const struct V_78 * V_79 ;
int V_48 ;
T_1 V_30 ;
unsigned long V_32 ;
for ( V_48 = 0 ; V_48 < V_6 -> V_138 . V_98 ; V_48 ++ ) {
V_29 = & V_6 -> V_7 -> V_40 [ V_48 ] ;
V_30 = F_1 ( V_48 ) ;
V_151 = & V_6 -> V_152 [ V_48 ] ;
V_32 = F_11 ( V_6 -> V_20 [ V_30 ] + V_29 -> V_45 ) ;
V_151 -> V_38 = ( V_32 >> V_29 -> V_44 ) & V_43 ;
if ( V_29 -> V_35 == - 1 )
goto V_153;
V_32 = F_11 ( V_6 -> V_20 [ V_30 ] + V_29 -> V_35 ) ;
if ( ! ( V_32 & ( V_29 -> V_34 << V_33 ) ) )
V_151 -> V_38 = V_41 ;
V_153:
if ( V_29 -> V_92 == - 1 )
goto V_154;
V_88 = & V_90 [ V_29 -> type ] ;
V_32 = F_11 ( V_6 -> V_20 [ V_30 ] + V_29 -> V_92 ) ;
V_151 -> V_155 = ( V_32 >> V_29 -> V_94 ) & V_88 -> V_85 ;
V_154:
V_79 = & V_81 [ V_29 -> type ] ;
V_32 = F_11 ( V_6 -> V_20 [ V_30 ] + V_29 -> V_82 ) ;
V_32 = ( V_32 >> V_29 -> V_86 ) & V_79 -> V_85 ;
V_151 -> V_156 = V_79 -> V_157 [ V_32 ] . V_84 ;
}
for ( V_48 = 0 ; V_48 < V_158 ; V_48 ++ ) {
V_6 -> V_159 [ V_48 ] = F_11 ( V_6 -> V_20 [ V_21 ] +
V_160 + 0x8 * V_48 ) ;
V_6 -> V_161 [ V_48 ] = F_11 ( V_6 -> V_20 [ V_21 ] +
V_162 + 0x8 * V_48 ) ;
}
return 0 ;
}
static int F_52 ( struct V_149 * V_42 )
{
struct V_5 * V_6 = F_51 ( V_42 ) ;
struct V_150 * V_151 ;
struct V_28 * V_29 ;
int V_48 ;
T_1 V_30 ;
for ( V_48 = 0 ; V_48 < V_6 -> V_138 . V_98 ; V_48 ++ ) {
V_29 = & V_6 -> V_7 -> V_40 [ V_48 ] ;
V_30 = F_1 ( V_48 ) ;
V_151 = & V_6 -> V_152 [ V_48 ] ;
F_15 ( V_6 , V_48 , ( T_1 ) V_151 -> V_38 & 0xff ) ;
if ( V_41 == V_151 -> V_38 )
goto V_163;
F_22 ( V_6 -> V_148 , V_48 ,
( T_1 ) V_151 -> V_155 & 0xff ) ;
V_163:
F_21 ( V_6 -> V_148 , V_48 ,
( T_1 ) V_151 -> V_156 & 0xff ) ;
}
for ( V_48 = 0 ; V_48 < V_158 ; V_48 ++ ) {
F_7 ( ~ 0 , V_6 -> V_20 [ V_21 ] +
V_164 + 0x8 * V_48 ) ;
F_7 ( V_6 -> V_159 [ V_48 ] , V_6 -> V_20 [ V_21 ] +
V_160 + 0x8 * V_48 ) ;
F_7 ( ~ 0 , V_6 -> V_20 [ V_21 ] +
V_165 + 0x8 * V_48 ) ;
F_7 ( V_6 -> V_161 [ V_48 ] , V_6 -> V_20 [ V_21 ] +
V_162 + 0x8 * V_48 ) ;
}
return 0 ;
}
static int T_4 F_53 ( void )
{
return F_54 ( & V_166 ) ;
}
static inline struct
V_167 * F_55 ( struct V_168 * V_169 , T_1 V_170 )
{
return & V_169 -> V_130 [ F_56 ( V_170 ) ] ;
}
static int F_57 ( struct V_168 * V_169 , T_1 V_170 )
{
struct V_167 * V_30 ;
T_1 V_171 ;
V_30 = F_55 ( V_169 , V_170 ) ;
V_171 = V_170 - V_30 -> V_172 ;
if ( V_171 >= V_30 -> V_173 )
return - V_174 ;
return V_30 -> V_175 [ V_171 ] ;
}
static void F_58 ( struct V_176 * V_177 )
{
struct V_178 * V_179 = F_59 ( V_177 ) ;
struct V_168 * V_169 = F_60 ( V_179 ) ;
struct V_167 * V_30 ;
void T_2 * V_180 ;
T_1 V_181 , V_182 ;
unsigned long V_183 ;
V_30 = F_55 ( V_169 , V_177 -> V_184 ) ;
V_182 = V_177 -> V_184 - V_30 -> V_172 ;
V_180 = F_61 ( V_30 , V_182 ) ;
F_62 ( & V_169 -> V_185 , V_183 ) ;
V_181 = F_11 ( V_180 ) ;
F_7 ( V_181 , V_180 ) ;
F_63 ( & V_169 -> V_185 , V_183 ) ;
}
static void F_64 ( struct V_168 * V_169 , int V_48 )
{
struct V_167 * V_30 ;
void T_2 * V_180 ;
T_1 V_181 , V_182 ;
V_30 = F_55 ( V_169 , V_48 ) ;
V_182 = V_48 - V_30 -> V_172 ;
V_180 = F_61 ( V_30 , V_182 ) ;
V_181 = F_11 ( V_180 ) ;
V_181 &= ~ ( V_186 |
V_187 ) ;
F_7 ( V_181 , V_180 ) ;
}
static void F_65 ( struct V_176 * V_177 )
{
struct V_178 * V_179 = F_59 ( V_177 ) ;
struct V_168 * V_169 = F_60 ( V_179 ) ;
unsigned long V_183 ;
F_62 ( & V_169 -> V_185 , V_183 ) ;
F_64 ( V_169 , V_177 -> V_184 ) ;
F_63 ( & V_169 -> V_185 , V_183 ) ;
}
static void F_66 ( struct V_176 * V_177 )
{
struct V_178 * V_179 = F_59 ( V_177 ) ;
struct V_168 * V_169 = F_60 ( V_179 ) ;
struct V_167 * V_30 ;
void T_2 * V_180 ;
T_1 V_181 , V_182 ;
unsigned long V_183 ;
V_30 = F_55 ( V_169 , V_177 -> V_184 ) ;
V_182 = V_177 -> V_184 - V_30 -> V_172 ;
V_180 = F_61 ( V_30 , V_182 ) ;
F_62 ( & V_169 -> V_185 , V_183 ) ;
V_181 = F_11 ( V_180 ) ;
V_181 &= ~ V_187 ;
V_181 |= V_186 ;
F_7 ( V_181 , V_180 ) ;
F_63 ( & V_169 -> V_185 , V_183 ) ;
}
static int F_67 ( struct V_176 * V_177 ,
unsigned int type )
{
struct V_178 * V_179 = F_59 ( V_177 ) ;
struct V_168 * V_169 = F_60 ( V_179 ) ;
struct V_167 * V_30 ;
void T_2 * V_180 ;
T_1 V_181 , V_182 ;
unsigned long V_183 ;
V_30 = F_55 ( V_169 , V_177 -> V_184 ) ;
V_182 = V_177 -> V_184 - V_30 -> V_172 ;
V_180 = F_61 ( V_30 , V_182 ) ;
F_62 ( & V_169 -> V_185 , V_183 ) ;
V_181 = F_11 ( V_180 ) ;
V_181 &= ~ ( V_187 |
V_186 ) ;
switch ( type ) {
case V_188 :
break;
case V_189 :
V_181 |= V_190 |
V_191 ;
V_181 &= ~ V_192 ;
break;
case V_193 :
V_181 &= ~ V_190 ;
V_181 |= V_192 |
V_191 ;
break;
case V_194 :
V_181 |= V_190 |
V_192 |
V_191 ;
break;
case V_195 :
V_181 &= ~ ( V_190 |
V_191 ) ;
V_181 |= V_192 ;
break;
case V_196 :
V_181 |= V_190 ;
V_181 &= ~ ( V_192 |
V_191 ) ;
break;
}
F_7 ( V_181 , V_180 ) ;
F_63 ( & V_169 -> V_185 , V_183 ) ;
return 0 ;
}
static void F_68 ( struct V_197 * V_198 )
{
struct V_178 * V_179 = F_69 ( V_198 ) ;
struct V_168 * V_169 = F_60 ( V_179 ) ;
struct V_167 * V_30 = NULL ;
T_1 V_151 , V_199 ;
int V_182 = 0 , V_48 ;
struct V_200 * V_201 = F_70 ( V_198 ) ;
unsigned int V_202 = F_71 ( V_198 ) ;
for ( V_48 = 0 ; V_48 < V_169 -> V_203 ; V_48 ++ ) {
V_30 = & V_169 -> V_130 [ V_48 ] ;
if ( V_30 -> V_202 == V_202 )
break;
}
F_18 ( V_48 == V_169 -> V_203 ) ;
F_72 ( V_201 , V_198 ) ;
V_151 = F_11 ( F_73 ( V_30 ) ) ;
if ( ! V_151 ) {
F_74 ( L_24 ,
V_204 , V_179 -> V_205 , V_151 ) ;
F_75 ( V_198 ) ;
return;
}
while ( V_151 ) {
V_199 = F_11 ( F_61 ( V_30 , V_182 ) ) ;
if ( ( V_151 & 0x1 ) && ( V_199 & V_186 ) ) {
F_12 ( L_25 ,
V_204 , V_179 -> V_205 ,
V_30 -> V_172 + V_182 ) ;
F_76 (
F_77 ( V_179 -> V_206 ,
V_30 -> V_172 + V_182 ) ) ;
}
if ( ++ V_182 >= V_30 -> V_173 )
break;
V_151 = V_151 >> 1 ;
}
F_78 ( V_201 , V_198 ) ;
}
static void F_79 ( struct V_168 * V_169 ,
unsigned int V_170 )
{
struct V_167 * V_30 ;
void T_2 * V_180 ;
T_1 V_181 , V_182 ;
V_30 = F_55 ( V_169 , V_170 ) ;
V_182 = V_170 - V_30 -> V_172 ;
V_180 = F_61 ( V_30 , V_182 ) ;
V_181 = F_11 ( V_180 ) ;
V_181 &= ~ V_207 ;
F_7 ( V_181 , V_180 ) ;
}
static int F_80 ( struct V_178 * V_201 ,
unsigned int V_170 )
{
struct V_168 * V_169 = F_60 ( V_201 ) ;
int V_39 ;
unsigned long V_183 ;
V_39 = F_57 ( V_169 , V_170 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( F_81 ( V_201 -> V_208 + V_170 ) )
return - V_174 ;
F_62 ( & V_169 -> V_185 , V_183 ) ;
F_79 ( V_169 , V_170 ) ;
F_64 ( V_169 , V_170 ) ;
F_63 ( & V_169 -> V_185 , V_183 ) ;
return 0 ;
}
static void F_82 ( struct V_178 * V_201 ,
unsigned int V_170 )
{
struct V_168 * V_169 = F_60 ( V_201 ) ;
unsigned long V_183 ;
F_62 ( & V_169 -> V_185 , V_183 ) ;
F_64 ( V_169 , V_170 ) ;
F_79 ( V_169 , V_170 ) ;
F_63 ( & V_169 -> V_185 , V_183 ) ;
F_83 ( V_201 -> V_208 + V_170 ) ;
}
static int F_84 ( struct V_178 * V_201 ,
unsigned int V_170 )
{
struct V_168 * V_169 = F_60 ( V_201 ) ;
unsigned long V_183 ;
F_62 ( & V_169 -> V_185 , V_183 ) ;
F_79 ( V_169 , V_170 ) ;
F_63 ( & V_169 -> V_185 , V_183 ) ;
return 0 ;
}
static void F_85 ( struct V_168 * V_169 ,
unsigned int V_170 , int V_209 )
{
struct V_167 * V_30 ;
void T_2 * V_180 ;
T_1 V_210 , V_182 ;
V_30 = F_55 ( V_169 , V_170 ) ;
V_182 = V_170 - V_30 -> V_172 ;
V_180 = F_61 ( V_30 , V_182 ) ;
V_210 = F_11 ( V_180 ) ;
if ( V_209 )
V_210 |= V_211 ;
else
V_210 &= ~ V_211 ;
V_210 &= ~ V_186 ;
V_210 |= V_207 ;
F_7 ( V_210 , V_180 ) ;
}
static int F_86 ( struct V_178 * V_201 ,
unsigned int V_170 , int V_209 )
{
struct V_168 * V_169 = F_60 ( V_201 ) ;
unsigned long V_183 ;
F_62 ( & V_169 -> V_185 , V_183 ) ;
F_85 ( V_169 , V_170 , V_209 ) ;
F_63 ( & V_169 -> V_185 , V_183 ) ;
return 0 ;
}
static int F_87 ( struct V_178 * V_201 ,
unsigned int V_170 )
{
struct V_168 * V_169 = F_60 ( V_201 ) ;
struct V_167 * V_30 ;
T_1 V_181 , V_182 ;
unsigned long V_183 ;
V_30 = F_55 ( V_169 , V_170 ) ;
V_182 = V_170 - V_30 -> V_172 ;
F_62 ( & V_169 -> V_185 , V_183 ) ;
V_181 = F_11 ( F_61 ( V_30 , V_182 ) ) ;
F_63 ( & V_169 -> V_185 , V_183 ) ;
return ! ! ( V_181 & V_212 ) ;
}
static void F_88 ( struct V_178 * V_201 ,
unsigned int V_170 , int V_209 )
{
struct V_168 * V_169 = F_60 ( V_201 ) ;
struct V_167 * V_30 ;
void T_2 * V_180 ;
T_1 V_199 , V_182 ;
unsigned long V_183 ;
V_30 = F_55 ( V_169 , V_170 ) ;
V_182 = V_170 - V_30 -> V_172 ;
V_180 = F_61 ( V_30 , V_182 ) ;
F_62 ( & V_169 -> V_185 , V_183 ) ;
V_199 = F_11 ( V_180 ) ;
if ( V_209 )
V_199 |= V_211 ;
else
V_199 &= ~ V_211 ;
F_7 ( V_199 , V_180 ) ;
F_63 ( & V_169 -> V_185 , V_183 ) ;
}
static int F_89 ( struct V_126 * V_127 )
{
struct V_104 * V_128 = V_127 -> V_42 . V_129 ;
struct V_168 * V_169 ;
struct V_178 * V_201 ;
T_1 V_203 ;
int V_39 , V_48 ;
V_39 = F_90 ( V_128 , L_26 , & V_203 ) ;
if ( V_39 ) {
F_16 ( & V_127 -> V_42 ,
L_27 ,
V_39 ) ;
return V_39 ;
}
V_169 = F_39 ( & V_127 -> V_42 , sizeof( * V_169 ) +
sizeof( struct V_167 ) * V_203 , V_135 ) ;
if ( ! V_169 )
return - V_136 ;
V_169 -> V_213 = F_91 ( V_128 , 0 ) ;
if ( ! F_43 ( V_169 -> V_213 ) ) {
V_39 = F_92 ( V_169 -> V_213 ) ;
if ( V_39 ) {
F_16 ( & V_127 -> V_42 ,
L_28 ) ;
return V_39 ;
}
}
V_169 -> V_214 = F_44 ( V_128 , 0 ) ;
if ( ! V_169 -> V_214 ) {
F_16 ( & V_127 -> V_42 , L_29 ) ;
return - V_136 ;
}
V_169 -> V_203 = V_203 ;
F_93 ( & V_169 -> V_185 ) ;
V_201 = & V_169 -> V_201 ;
V_201 -> V_215 = F_80 ;
V_201 -> free = F_82 ;
V_201 -> V_216 = F_84 ;
V_201 -> V_217 = F_87 ;
V_201 -> V_218 = F_86 ;
V_201 -> V_219 = F_88 ;
V_201 -> V_208 = - 1 ;
V_201 -> V_173 = V_220 * V_203 ;
V_201 -> V_205 = F_94 ( V_128 -> V_11 , V_135 ) ;
V_201 -> V_129 = V_128 ;
V_201 -> V_221 = 2 ;
V_201 -> V_222 = & V_127 -> V_42 ;
V_39 = F_95 ( V_201 , V_169 ) ;
if ( V_39 ) {
F_16 ( & V_127 -> V_42 ,
L_30 ,
V_128 -> V_11 , V_39 ) ;
goto V_223;
}
V_39 = F_96 ( V_201 , & V_224 ,
0 , V_225 , V_188 ) ;
if ( V_39 ) {
F_16 ( & V_127 -> V_42 ,
L_31 ) ;
goto V_223;
}
for ( V_48 = 0 ; V_48 < V_203 ; V_48 ++ ) {
struct V_226 * V_227 ;
struct V_167 * V_30 ;
V_30 = & V_169 -> V_130 [ V_48 ] ;
V_30 -> V_208 = F_97 ( V_169 , V_48 ) ;
V_39 = F_98 ( V_128 , V_48 ) ;
if ( V_39 == - V_228 ) {
F_16 ( & V_127 -> V_42 ,
L_32 , V_39 ) ;
goto V_223;
}
V_30 -> V_202 = V_39 ;
F_99 ( V_201 , & V_224 ,
V_30 -> V_202 , F_68 ) ;
F_100 (pin_range, &chip->pin_ranges, node) {
struct V_96 * V_97 ;
V_97 = & V_227 -> V_97 ;
if ( V_97 -> V_229 == V_220 * V_48 ) {
V_30 -> V_172 = V_97 -> V_229 ;
V_30 -> V_173 = V_97 -> V_98 ;
V_30 -> V_175 = V_97 -> V_56 ;
V_30 -> V_4 = V_227 -> V_4 ;
break;
}
}
F_18 ( ! V_30 -> V_4 ) ;
}
F_47 ( V_127 , V_169 ) ;
F_48 ( & V_127 -> V_42 , L_33 ) ;
return 0 ;
V_223:
return V_39 ;
}
static int F_101 ( struct V_149 * V_42 )
{
struct V_168 * V_169 = F_51 ( V_42 ) ;
struct V_167 * V_30 ;
void T_2 * V_180 ;
T_1 V_48 , V_1 ;
for ( V_48 = 0 ; V_48 < V_169 -> V_203 ; V_48 ++ ) {
V_30 = & V_169 -> V_130 [ V_48 ] ;
for ( V_1 = 0 ; V_1 < V_30 -> V_173 ; V_1 ++ ) {
V_180 = F_61 ( V_30 , V_1 ) ;
V_30 -> V_152 [ V_1 ] = F_11 ( V_180 ) ;
}
}
return 0 ;
}
static int F_102 ( struct V_149 * V_42 )
{
struct V_168 * V_169 = F_51 ( V_42 ) ;
struct V_167 * V_30 ;
void T_2 * V_180 ;
T_1 V_48 , V_1 ;
for ( V_48 = 0 ; V_48 < V_169 -> V_203 ; V_48 ++ ) {
V_30 = & V_169 -> V_130 [ V_48 ] ;
for ( V_1 = 0 ; V_1 < V_30 -> V_173 ; V_1 ++ ) {
V_180 = F_61 ( V_30 , V_1 ) ;
F_7 ( V_30 -> V_152 [ V_1 ] , V_180 ) ;
}
}
return 0 ;
}
static int T_4 F_103 ( void )
{
return F_54 ( & V_230 ) ;
}
