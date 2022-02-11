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
const struct V_78 * V_79 ;
T_1 V_34 ;
unsigned long V_36 ;
void T_2 * V_80 ;
V_34 = F_3 ( V_5 ) ;
V_79 = & V_81 [ V_33 -> type ] ;
V_80 = V_10 -> V_24 [ V_34 ] + V_33 -> V_82 ;
V_36 = V_79 -> V_83 [ V_77 ] . V_84 & V_79 -> V_85 ;
F_9 ( V_79 -> V_85 << V_33 -> V_86 , F_10 ( V_80 ) ) ;
F_9 ( V_36 << V_33 -> V_86 , V_80 ) ;
F_14 ( L_8 ,
V_5 , V_77 ) ;
return 0 ;
}
static int F_24 ( struct V_7 * V_8 ,
T_1 V_5 , T_1 V_77 )
{
struct V_9 * V_10 = F_5 ( V_8 ) ;
struct V_32 * V_33 = & V_10 -> V_11 -> V_44 [ V_5 ] ;
const struct V_87 * V_88 ;
T_1 V_34 ;
void T_2 * V_89 ;
V_88 = & V_90 [ V_33 -> type ] ;
if ( V_77 & ( ~ ( V_88 -> V_85 ) ) )
goto V_91;
V_34 = F_3 ( V_5 ) ;
V_89 = V_10 -> V_24 [ V_34 ] + V_33 -> V_92 ;
F_9 ( V_88 -> V_93 << V_33 -> V_94 , F_10 ( V_89 ) ) ;
F_9 ( V_77 << V_33 -> V_94 , V_89 ) ;
return 0 ;
V_91:
F_25 ( L_9 ,
V_5 , V_33 -> type , V_77 ) ;
return - V_95 ;
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
F_25 ( L_10 ,
V_5 , type , V_63 ) ;
return - V_95 ;
}
V_43 = F_24 ( V_8 ,
V_5 , V_77 ) ;
F_14 ( L_11 ,
V_5 , V_77 , V_63 , V_43 ? L_12 : L_13 ) ;
return V_43 ;
}
static int F_27 ( struct V_7 * V_8 ,
struct V_96 * V_97 , T_1 V_5 )
{
struct V_9 * V_10 = F_5 ( V_8 ) ;
T_1 V_52 ;
F_28 ( V_10 -> V_46 ,
L_14 , V_5 ) ;
for ( V_52 = 0 ; V_52 < V_97 -> V_98 ; V_52 ++ ) {
if ( V_5 == V_97 -> V_99 [ V_52 ] )
break;
}
if ( V_52 >= V_97 -> V_98 ) {
F_18 ( V_10 -> V_46 ,
L_15 ,
V_5 ) ;
return - V_100 ;
}
F_17 ( V_10 , V_5 , V_101 ) ;
return 0 ;
}
static int F_29 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_5 ( V_8 ) ;
return V_10 -> V_11 -> V_102 ;
}
static const char * F_30 ( struct V_7 * V_8 ,
T_1 V_103 )
{
struct V_9 * V_10 = F_5 ( V_8 ) ;
return V_10 -> V_11 -> V_59 [ V_103 ] . V_15 ;
}
static int F_31 ( struct V_7 * V_8 ,
T_1 V_103 , const T_1 * * V_99 , T_1 * V_104 )
{
struct V_9 * V_10 = F_5 ( V_8 ) ;
* V_104 = V_10 -> V_11 -> V_59 [ V_103 ] . V_104 ;
* V_99 = V_10 -> V_11 -> V_59 [ V_103 ] . V_99 ;
return 0 ;
}
static int F_32 ( struct V_7 * V_8 ,
struct V_105 * V_106 ,
struct V_107 * * V_108 ,
T_1 * V_109 )
{
return F_33 ( V_8 , V_106 , V_108 ,
V_109 , V_110 ) ;
}
static void F_34 ( struct V_7 * V_8 ,
struct V_107 * V_108 , T_1 V_109 )
{
F_35 ( V_108 ) ;
}
static int F_36 ( struct V_7 * V_8 ,
unsigned V_5 , unsigned long * V_111 ,
unsigned V_112 )
{
T_3 V_113 , V_114 ;
int V_52 , V_115 ;
for ( V_52 = 0 ; V_52 < V_112 ; V_52 ++ ) {
V_113 = F_37 ( V_111 [ V_52 ] ) ;
V_114 = F_38 ( V_111 [ V_52 ] ) ;
F_14 ( L_16 ,
V_5 , V_116 [ V_5 ] . V_15 , V_113 , V_114 ) ;
switch ( V_113 ) {
case V_117 :
V_115 = F_23 ( V_8 ,
V_5 , V_118 ) ;
if ( V_115 )
return V_115 ;
break;
case V_119 :
V_115 = F_23 ( V_8 ,
V_5 , V_120 ) ;
if ( V_115 )
return V_115 ;
break;
case V_121 :
V_115 = F_23 ( V_8 ,
V_5 , V_122 ) ;
if ( V_115 )
return V_115 ;
break;
case V_123 :
V_115 = F_23 ( V_8 ,
V_5 , V_124 ) ;
if ( V_115 )
return V_115 ;
break;
case V_125 :
V_115 = F_26 ( V_8 ,
V_5 , V_114 ) ;
if ( V_115 )
return V_115 ;
break;
default:
return - V_95 ;
}
F_14 ( L_17 ,
V_5 , V_116 [ V_5 ] . V_15 , V_113 , V_114 ) ;
}
return 0 ;
}
static int F_39 ( struct V_7 * V_8 ,
unsigned V_103 , unsigned long * V_111 ,
unsigned V_112 )
{
const unsigned * V_99 ;
unsigned V_98 ;
int V_126 , V_43 ;
V_43 = F_31 ( V_8 , V_103 , & V_99 , & V_98 ) ;
if ( V_43 )
return V_43 ;
for ( V_126 = 0 ; V_126 < V_98 ; V_126 ++ ) {
if ( F_36 ( V_8 , V_99 [ V_126 ] ,
V_111 , V_112 ) )
return - V_95 ;
}
return 0 ;
}
static int F_40 ( struct V_127 * V_128 )
{
int V_43 , V_52 ;
struct V_9 * V_10 ;
struct V_105 * V_129 = V_128 -> V_46 . V_130 ;
T_1 V_131 = V_132 ;
V_10 = F_41 ( & V_128 -> V_46 , sizeof( * V_10 ) , V_133 ) ;
if ( ! V_10 )
return - V_134 ;
V_10 -> V_46 = & V_128 -> V_46 ;
V_10 -> V_11 = & V_135 ;
V_10 -> V_136 . V_15 = L_18 ;
V_10 -> V_136 . V_99 = V_10 -> V_11 -> V_137 ;
V_10 -> V_136 . V_98 = V_10 -> V_11 -> V_138 ;
V_10 -> V_136 . V_139 = & V_140 ;
V_10 -> V_136 . V_141 = & V_142 ;
V_10 -> V_136 . V_143 = & V_144 ;
for ( V_52 = 0 ; V_52 < V_131 ; V_52 ++ ) {
V_10 -> V_24 [ V_52 ] = F_42 ( V_129 , V_52 ) ;
if ( ! V_10 -> V_24 [ V_52 ] ) {
F_18 ( & V_128 -> V_46 ,
L_19 , V_52 ) ;
V_43 = - V_134 ;
goto V_145;
}
}
V_10 -> V_146 = F_43 ( & V_10 -> V_136 , & V_128 -> V_46 , V_10 ) ;
if ( F_44 ( V_10 -> V_146 ) ) {
F_18 ( & V_128 -> V_46 , L_20 ) ;
V_43 = F_45 ( V_10 -> V_146 ) ;
goto V_145;
}
F_46 ( V_128 , V_10 ) ;
F_47 ( & V_128 -> V_46 , L_21 ) ;
return 0 ;
V_145:
for ( V_52 = 0 ; V_52 < V_131 ; V_52 ++ ) {
if ( ! V_10 -> V_24 [ V_52 ] )
break;
F_48 ( V_10 -> V_24 [ V_52 ] ) ;
}
return V_43 ;
}
static int F_49 ( struct V_147 * V_46 )
{
struct V_9 * V_10 = F_50 ( V_46 ) ;
struct V_148 * V_149 ;
struct V_32 * V_33 ;
const struct V_87 * V_88 ;
const struct V_78 * V_79 ;
int V_52 ;
T_1 V_34 ;
unsigned long V_36 ;
for ( V_52 = 0 ; V_52 < V_10 -> V_136 . V_98 ; V_52 ++ ) {
V_33 = & V_10 -> V_11 -> V_44 [ V_52 ] ;
V_34 = F_3 ( V_52 ) ;
V_149 = & V_10 -> V_150 [ V_52 ] ;
V_36 = F_13 ( V_10 -> V_24 [ V_34 ] + V_33 -> V_49 ) ;
V_149 -> V_42 = ( V_36 >> V_33 -> V_48 ) & V_47 ;
if ( V_33 -> V_39 == - 1 )
goto V_151;
V_36 = F_13 ( V_10 -> V_24 [ V_34 ] + V_33 -> V_39 ) ;
if ( ! ( V_36 & ( V_33 -> V_38 << V_37 ) ) )
V_149 -> V_42 = V_45 ;
V_151:
if ( V_33 -> V_92 == - 1 )
goto V_152;
V_88 = & V_90 [ V_33 -> type ] ;
V_36 = F_13 ( V_10 -> V_24 [ V_34 ] + V_33 -> V_92 ) ;
V_149 -> V_153 = ( V_36 >> V_33 -> V_94 ) & V_88 -> V_85 ;
V_152:
V_79 = & V_81 [ V_33 -> type ] ;
V_36 = F_13 ( V_10 -> V_24 [ V_34 ] + V_33 -> V_82 ) ;
V_36 = ( V_36 >> V_33 -> V_86 ) & V_79 -> V_85 ;
V_149 -> V_154 = V_79 -> V_155 [ V_36 ] . V_84 ;
}
for ( V_52 = 0 ; V_52 < V_156 ; V_52 ++ ) {
V_10 -> V_157 [ V_52 ] = F_13 ( V_10 -> V_24 [ V_25 ] +
V_158 + 0x8 * V_52 ) ;
V_10 -> V_159 [ V_52 ] = F_13 ( V_10 -> V_24 [ V_25 ] +
V_160 + 0x8 * V_52 ) ;
}
return 0 ;
}
static int F_51 ( struct V_147 * V_46 )
{
struct V_9 * V_10 = F_50 ( V_46 ) ;
struct V_148 * V_149 ;
struct V_32 * V_33 ;
int V_52 ;
T_1 V_34 ;
for ( V_52 = 0 ; V_52 < V_10 -> V_136 . V_98 ; V_52 ++ ) {
V_33 = & V_10 -> V_11 -> V_44 [ V_52 ] ;
V_34 = F_3 ( V_52 ) ;
V_149 = & V_10 -> V_150 [ V_52 ] ;
F_17 ( V_10 , V_52 , ( T_1 ) V_149 -> V_42 & 0xff ) ;
if ( V_45 == V_149 -> V_42 )
goto V_161;
F_24 ( V_10 -> V_146 , V_52 ,
( T_1 ) V_149 -> V_153 & 0xff ) ;
V_161:
F_23 ( V_10 -> V_146 , V_52 ,
( T_1 ) V_149 -> V_154 & 0xff ) ;
}
for ( V_52 = 0 ; V_52 < V_156 ; V_52 ++ ) {
F_9 ( ~ 0 , V_10 -> V_24 [ V_25 ] +
V_162 + 0x8 * V_52 ) ;
F_9 ( V_10 -> V_157 [ V_52 ] , V_10 -> V_24 [ V_25 ] +
V_158 + 0x8 * V_52 ) ;
F_9 ( ~ 0 , V_10 -> V_24 [ V_25 ] +
V_163 + 0x8 * V_52 ) ;
F_9 ( V_10 -> V_159 [ V_52 ] , V_10 -> V_24 [ V_25 ] +
V_160 + 0x8 * V_52 ) ;
}
return 0 ;
}
static int T_4 F_52 ( void )
{
return F_53 ( & V_164 ) ;
}
static inline struct
V_165 * F_54 ( struct V_1 * V_166 , T_1 V_167 )
{
return & V_166 -> V_131 [ F_55 ( V_167 ) ] ;
}
static int F_56 ( struct V_1 * V_166 , T_1 V_167 )
{
struct V_165 * V_34 ;
T_1 V_168 ;
V_34 = F_54 ( V_166 , V_167 ) ;
V_168 = V_167 - V_34 -> V_169 ;
if ( V_168 >= V_34 -> V_170 )
return - V_171 ;
return V_34 -> V_172 [ V_168 ] ;
}
static void F_57 ( struct V_173 * V_174 )
{
struct V_2 * V_3 = F_58 ( V_174 ) ;
struct V_1 * V_166 = F_1 ( V_3 ) ;
struct V_165 * V_34 ;
void T_2 * V_175 ;
T_1 V_176 , V_177 ;
unsigned long V_178 ;
V_34 = F_54 ( V_166 , V_174 -> V_179 ) ;
V_177 = V_174 -> V_179 - V_34 -> V_169 ;
V_175 = F_59 ( V_34 , V_177 ) ;
F_60 ( & V_166 -> V_180 , V_178 ) ;
V_176 = F_13 ( V_175 ) ;
F_9 ( V_176 , V_175 ) ;
F_61 ( & V_166 -> V_180 , V_178 ) ;
}
static void F_62 ( struct V_1 * V_166 , int V_52 )
{
struct V_165 * V_34 ;
void T_2 * V_175 ;
T_1 V_176 , V_177 ;
V_34 = F_54 ( V_166 , V_52 ) ;
V_177 = V_52 - V_34 -> V_169 ;
V_175 = F_59 ( V_34 , V_177 ) ;
V_176 = F_13 ( V_175 ) ;
V_176 &= ~ ( V_181 |
V_182 ) ;
F_9 ( V_176 , V_175 ) ;
}
static void F_63 ( struct V_173 * V_174 )
{
struct V_2 * V_3 = F_58 ( V_174 ) ;
struct V_1 * V_166 = F_1 ( V_3 ) ;
unsigned long V_178 ;
F_60 ( & V_166 -> V_180 , V_178 ) ;
F_62 ( V_166 , V_174 -> V_179 ) ;
F_61 ( & V_166 -> V_180 , V_178 ) ;
}
static void F_64 ( struct V_173 * V_174 )
{
struct V_2 * V_3 = F_58 ( V_174 ) ;
struct V_1 * V_166 = F_1 ( V_3 ) ;
struct V_165 * V_34 ;
void T_2 * V_175 ;
T_1 V_176 , V_177 ;
unsigned long V_178 ;
V_34 = F_54 ( V_166 , V_174 -> V_179 ) ;
V_177 = V_174 -> V_179 - V_34 -> V_169 ;
V_175 = F_59 ( V_34 , V_177 ) ;
F_60 ( & V_166 -> V_180 , V_178 ) ;
V_176 = F_13 ( V_175 ) ;
V_176 &= ~ V_182 ;
V_176 |= V_181 ;
F_9 ( V_176 , V_175 ) ;
F_61 ( & V_166 -> V_180 , V_178 ) ;
}
static int F_65 ( struct V_173 * V_174 ,
unsigned int type )
{
struct V_2 * V_3 = F_58 ( V_174 ) ;
struct V_1 * V_166 = F_1 ( V_3 ) ;
struct V_165 * V_34 ;
void T_2 * V_175 ;
T_1 V_176 , V_177 ;
unsigned long V_178 ;
V_34 = F_54 ( V_166 , V_174 -> V_179 ) ;
V_177 = V_174 -> V_179 - V_34 -> V_169 ;
V_175 = F_59 ( V_34 , V_177 ) ;
F_60 ( & V_166 -> V_180 , V_178 ) ;
V_176 = F_13 ( V_175 ) ;
V_176 &= ~ ( V_182 |
V_181 ) ;
switch ( type ) {
case V_183 :
break;
case V_184 :
V_176 |= V_185 |
V_186 ;
V_176 &= ~ V_187 ;
break;
case V_188 :
V_176 &= ~ V_185 ;
V_176 |= V_187 |
V_186 ;
break;
case V_189 :
V_176 |= V_185 |
V_187 |
V_186 ;
break;
case V_190 :
V_176 &= ~ ( V_185 |
V_186 ) ;
V_176 |= V_187 ;
break;
case V_191 :
V_176 |= V_185 ;
V_176 &= ~ ( V_187 |
V_186 ) ;
break;
}
F_9 ( V_176 , V_175 ) ;
F_61 ( & V_166 -> V_180 , V_178 ) ;
return 0 ;
}
static void F_66 ( struct V_192 * V_193 )
{
struct V_2 * V_3 = F_67 ( V_193 ) ;
struct V_1 * V_166 = F_1 ( V_3 ) ;
struct V_165 * V_34 = NULL ;
T_1 V_149 , V_194 ;
int V_177 = 0 , V_52 ;
struct V_195 * V_4 = F_68 ( V_193 ) ;
unsigned int V_196 = F_69 ( V_193 ) ;
for ( V_52 = 0 ; V_52 < V_166 -> V_197 ; V_52 ++ ) {
V_34 = & V_166 -> V_131 [ V_52 ] ;
if ( V_34 -> V_196 == V_196 )
break;
}
F_20 ( V_52 == V_166 -> V_197 ) ;
F_70 ( V_4 , V_193 ) ;
V_149 = F_13 ( F_71 ( V_34 ) ) ;
if ( ! V_149 ) {
F_72 ( L_22 ,
V_198 , V_3 -> V_199 , V_149 ) ;
F_73 ( V_193 ) ;
return;
}
while ( V_149 ) {
V_194 = F_13 ( F_59 ( V_34 , V_177 ) ) ;
if ( ( V_149 & 0x1 ) && ( V_194 & V_181 ) ) {
F_14 ( L_23 ,
V_198 , V_3 -> V_199 ,
V_34 -> V_169 + V_177 ) ;
F_74 (
F_75 ( V_3 -> V_200 ,
V_34 -> V_169 + V_177 ) ) ;
}
if ( ++ V_177 >= V_34 -> V_170 )
break;
V_149 = V_149 >> 1 ;
}
F_76 ( V_4 , V_193 ) ;
}
static void F_77 ( struct V_1 * V_166 ,
unsigned int V_167 )
{
struct V_165 * V_34 ;
void T_2 * V_175 ;
T_1 V_176 , V_177 ;
V_34 = F_54 ( V_166 , V_167 ) ;
V_177 = V_167 - V_34 -> V_169 ;
V_175 = F_59 ( V_34 , V_177 ) ;
V_176 = F_13 ( V_175 ) ;
V_176 &= ~ V_201 ;
F_9 ( V_176 , V_175 ) ;
}
static int F_78 ( struct V_2 * V_4 ,
unsigned int V_167 )
{
struct V_1 * V_166 = F_1 ( V_4 ) ;
int V_43 ;
unsigned long V_178 ;
V_43 = F_56 ( V_166 , V_167 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( F_79 ( V_4 -> V_202 + V_167 ) )
return - V_171 ;
F_60 ( & V_166 -> V_180 , V_178 ) ;
F_77 ( V_166 , V_167 ) ;
F_62 ( V_166 , V_167 ) ;
F_61 ( & V_166 -> V_180 , V_178 ) ;
return 0 ;
}
static void F_80 ( struct V_2 * V_4 ,
unsigned int V_167 )
{
struct V_1 * V_166 = F_1 ( V_4 ) ;
unsigned long V_178 ;
F_60 ( & V_166 -> V_180 , V_178 ) ;
F_62 ( V_166 , V_167 ) ;
F_77 ( V_166 , V_167 ) ;
F_61 ( & V_166 -> V_180 , V_178 ) ;
F_81 ( V_4 -> V_202 + V_167 ) ;
}
static int F_82 ( struct V_2 * V_4 ,
unsigned int V_167 )
{
struct V_1 * V_166 = F_1 ( V_4 ) ;
unsigned long V_178 ;
F_60 ( & V_166 -> V_180 , V_178 ) ;
F_77 ( V_166 , V_167 ) ;
F_61 ( & V_166 -> V_180 , V_178 ) ;
return 0 ;
}
static void F_83 ( struct V_1 * V_166 ,
unsigned int V_167 , int V_203 )
{
struct V_165 * V_34 ;
void T_2 * V_175 ;
T_1 V_204 , V_177 ;
V_34 = F_54 ( V_166 , V_167 ) ;
V_177 = V_167 - V_34 -> V_169 ;
V_175 = F_59 ( V_34 , V_177 ) ;
V_204 = F_13 ( V_175 ) ;
if ( V_203 )
V_204 |= V_205 ;
else
V_204 &= ~ V_205 ;
V_204 &= ~ V_181 ;
V_204 |= V_201 ;
F_9 ( V_204 , V_175 ) ;
}
static int F_84 ( struct V_2 * V_4 ,
unsigned int V_167 , int V_203 )
{
struct V_1 * V_166 = F_1 ( V_4 ) ;
unsigned long V_178 ;
F_60 ( & V_166 -> V_180 , V_178 ) ;
F_83 ( V_166 , V_167 , V_203 ) ;
F_61 ( & V_166 -> V_180 , V_178 ) ;
return 0 ;
}
static int F_85 ( struct V_2 * V_4 ,
unsigned int V_167 )
{
struct V_1 * V_166 = F_1 ( V_4 ) ;
struct V_165 * V_34 ;
T_1 V_176 , V_177 ;
unsigned long V_178 ;
V_34 = F_54 ( V_166 , V_167 ) ;
V_177 = V_167 - V_34 -> V_169 ;
F_60 ( & V_166 -> V_180 , V_178 ) ;
V_176 = F_13 ( F_59 ( V_34 , V_177 ) ) ;
F_61 ( & V_166 -> V_180 , V_178 ) ;
return ! ! ( V_176 & V_206 ) ;
}
static void F_86 ( struct V_2 * V_4 ,
unsigned int V_167 , int V_203 )
{
struct V_1 * V_166 = F_1 ( V_4 ) ;
struct V_165 * V_34 ;
void T_2 * V_175 ;
T_1 V_194 , V_177 ;
unsigned long V_178 ;
V_34 = F_54 ( V_166 , V_167 ) ;
V_177 = V_167 - V_34 -> V_169 ;
V_175 = F_59 ( V_34 , V_177 ) ;
F_60 ( & V_166 -> V_180 , V_178 ) ;
V_194 = F_13 ( V_175 ) ;
if ( V_203 )
V_194 |= V_205 ;
else
V_194 &= ~ V_205 ;
F_9 ( V_194 , V_175 ) ;
F_61 ( & V_166 -> V_180 , V_178 ) ;
}
static int F_87 ( struct V_127 * V_128 )
{
struct V_105 * V_129 = V_128 -> V_46 . V_130 ;
struct V_1 * V_166 ;
struct V_2 * V_4 ;
T_1 V_197 ;
int V_43 , V_52 ;
V_43 = F_88 ( V_129 , L_24 , & V_197 ) ;
if ( V_43 ) {
F_18 ( & V_128 -> V_46 ,
L_25 ,
V_43 ) ;
return V_43 ;
}
V_166 = F_41 ( & V_128 -> V_46 , sizeof( * V_166 ) +
sizeof( struct V_165 ) * V_197 , V_133 ) ;
if ( ! V_166 )
return - V_134 ;
V_166 -> V_207 = F_89 ( V_129 , 0 ) ;
if ( ! F_44 ( V_166 -> V_207 ) ) {
V_43 = F_90 ( V_166 -> V_207 ) ;
if ( V_43 ) {
F_18 ( & V_128 -> V_46 ,
L_26 ) ;
return V_43 ;
}
}
V_166 -> V_208 = F_42 ( V_129 , 0 ) ;
if ( ! V_166 -> V_208 ) {
F_18 ( & V_128 -> V_46 , L_27 ) ;
return - V_134 ;
}
V_166 -> V_197 = V_197 ;
F_91 ( & V_166 -> V_180 ) ;
V_4 = & V_166 -> V_4 ;
V_4 -> V_209 = F_78 ;
V_4 -> free = F_80 ;
V_4 -> V_210 = F_82 ;
V_4 -> V_211 = F_85 ;
V_4 -> V_212 = F_84 ;
V_4 -> V_213 = F_86 ;
V_4 -> V_202 = - 1 ;
V_4 -> V_170 = V_214 * V_197 ;
V_4 -> V_199 = F_92 ( V_129 -> V_15 , V_133 ) ;
V_4 -> V_130 = V_129 ;
V_4 -> V_215 = 2 ;
V_4 -> V_46 = & V_128 -> V_46 ;
V_43 = F_93 ( V_4 ) ;
if ( V_43 ) {
F_18 ( & V_128 -> V_46 ,
L_28 ,
V_129 -> V_15 , V_43 ) ;
goto V_216;
}
V_43 = F_94 ( V_4 , & V_217 ,
0 , V_218 , V_183 ) ;
if ( V_43 ) {
F_18 ( & V_128 -> V_46 ,
L_29 ) ;
goto V_216;
}
for ( V_52 = 0 ; V_52 < V_197 ; V_52 ++ ) {
struct V_219 * V_220 ;
struct V_165 * V_34 ;
V_34 = & V_166 -> V_131 [ V_52 ] ;
V_34 -> V_202 = F_95 ( V_166 , V_52 ) ;
V_43 = F_96 ( V_129 , V_52 ) ;
if ( V_43 == - V_221 ) {
F_18 ( & V_128 -> V_46 ,
L_30 , V_43 ) ;
goto V_216;
}
V_34 -> V_196 = V_43 ;
F_97 ( V_4 , & V_217 ,
V_34 -> V_196 , F_66 ) ;
F_98 (pin_range, &chip->pin_ranges, node) {
struct V_96 * V_97 ;
V_97 = & V_220 -> V_97 ;
if ( V_97 -> V_222 == V_214 * V_52 ) {
V_34 -> V_169 = V_97 -> V_222 ;
V_34 -> V_170 = V_97 -> V_98 ;
V_34 -> V_172 = V_97 -> V_99 ;
V_34 -> V_8 = V_220 -> V_8 ;
break;
}
}
F_20 ( ! V_34 -> V_8 ) ;
}
F_46 ( V_128 , V_166 ) ;
F_47 ( & V_128 -> V_46 , L_31 ) ;
return 0 ;
V_216:
return V_43 ;
}
static int F_99 ( struct V_147 * V_46 )
{
struct V_1 * V_166 = F_50 ( V_46 ) ;
struct V_165 * V_34 ;
void T_2 * V_175 ;
T_1 V_52 , V_5 ;
for ( V_52 = 0 ; V_52 < V_166 -> V_197 ; V_52 ++ ) {
V_34 = & V_166 -> V_131 [ V_52 ] ;
for ( V_5 = 0 ; V_5 < V_34 -> V_170 ; V_5 ++ ) {
V_175 = F_59 ( V_34 , V_5 ) ;
V_34 -> V_150 [ V_5 ] = F_13 ( V_175 ) ;
}
}
return 0 ;
}
static int F_100 ( struct V_147 * V_46 )
{
struct V_1 * V_166 = F_50 ( V_46 ) ;
struct V_165 * V_34 ;
void T_2 * V_175 ;
T_1 V_52 , V_5 ;
for ( V_52 = 0 ; V_52 < V_166 -> V_197 ; V_52 ++ ) {
V_34 = & V_166 -> V_131 [ V_52 ] ;
for ( V_5 = 0 ; V_5 < V_34 -> V_170 ; V_5 ++ ) {
V_175 = F_59 ( V_34 , V_5 ) ;
F_9 ( V_34 -> V_150 [ V_5 ] , V_175 ) ;
}
}
return 0 ;
}
static int T_4 F_101 ( void )
{
return F_53 ( & V_223 ) ;
}
