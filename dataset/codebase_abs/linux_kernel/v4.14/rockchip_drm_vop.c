static inline void F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_1 -> V_4 + V_2 ) ;
V_1 -> V_5 [ V_2 >> 2 ] = V_3 ;
}
static inline T_1 F_3 ( struct V_1 * V_1 , T_1 V_2 )
{
return F_4 ( V_1 -> V_4 + V_2 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_1 , T_1 V_6 ,
const struct V_7 * V_8 )
{
return ( F_3 ( V_1 , V_6 + V_8 -> V_2 ) >> V_8 -> V_9 ) & V_8 -> V_10 ;
}
static void F_6 ( struct V_1 * V_1 , const struct V_7 * V_8 ,
T_1 V_11 , T_1 V_12 , T_1 V_3 ,
const char * V_13 )
{
int V_2 , V_10 , V_9 ;
if ( ! V_8 || ! V_8 -> V_10 ) {
F_7 ( V_1 -> V_14 , L_1 , V_13 ) ;
return;
}
V_2 = V_8 -> V_2 + V_11 ;
V_10 = V_8 -> V_10 & V_12 ;
V_9 = V_8 -> V_9 ;
if ( V_8 -> V_15 ) {
V_3 = ( ( V_3 << V_9 ) & 0xffff ) | ( V_10 << ( V_9 + 16 ) ) ;
} else {
T_1 V_16 = V_1 -> V_5 [ V_2 >> 2 ] ;
V_3 = ( V_16 & ~ ( V_10 << V_9 ) ) | ( ( V_3 & V_10 ) << V_9 ) ;
V_1 -> V_5 [ V_2 >> 2 ] = V_3 ;
}
if ( V_8 -> V_17 )
F_8 ( V_3 , V_1 -> V_4 + V_2 ) ;
else
F_2 ( V_3 , V_1 -> V_4 + V_2 ) ;
}
static inline T_1 F_9 ( struct V_1 * V_1 ,
const struct V_7 * V_8 , int type )
{
T_1 V_18 , V_19 = 0 ;
T_1 V_4 = F_5 ( V_1 , 0 , V_8 ) ;
for ( V_18 = 0 ; V_18 < V_1 -> V_20 -> V_21 -> V_22 ; V_18 ++ ) {
if ( ( type & V_1 -> V_20 -> V_21 -> V_23 [ V_18 ] ) && ( V_4 & 1 << V_18 ) )
V_19 |= V_1 -> V_20 -> V_21 -> V_23 [ V_18 ] ;
}
return V_19 ;
}
static inline void F_10 ( struct V_1 * V_1 )
{
F_11 ( V_1 , V_24 , V_25 , 1 ) ;
}
static bool F_12 ( T_1 V_26 )
{
switch ( V_26 ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
return true ;
default:
return false ;
}
}
static enum V_31 F_13 ( T_1 V_26 )
{
switch ( V_26 ) {
case V_32 :
case V_33 :
case V_27 :
case V_28 :
return V_34 ;
case V_35 :
case V_29 :
return V_36 ;
case V_37 :
case V_30 :
return V_38 ;
case V_39 :
return V_40 ;
case V_41 :
return V_42 ;
case V_43 :
return V_44 ;
default:
F_14 ( L_2 , V_26 ) ;
return - V_45 ;
}
}
static bool F_15 ( T_1 V_26 )
{
switch ( V_26 ) {
case V_39 :
case V_41 :
case V_43 :
return true ;
default:
return false ;
}
}
static bool F_16 ( T_1 V_26 )
{
switch ( V_26 ) {
case V_33 :
case V_28 :
return true ;
default:
return false ;
}
}
static T_2 F_17 ( enum V_46 V_47 , T_1 V_48 ,
T_1 V_49 , bool V_50 ,
int V_51 , int * V_52 )
{
T_2 V_53 = 1 << V_54 ;
if ( V_50 ) {
if ( V_47 == V_55 )
V_53 = F_18 ( V_48 , V_49 ) ;
else if ( V_47 == V_56 )
V_53 = F_19 ( V_48 , V_49 ) ;
} else {
if ( V_47 == V_55 ) {
if ( V_51 == V_57 )
V_53 = F_20 ( V_48 , V_49 ) ;
else
V_53 = F_18 ( V_48 , V_49 ) ;
} else if ( V_47 == V_56 ) {
if ( V_52 ) {
* V_52 = F_21 ( V_48 , V_49 ) ;
V_53 = F_22 ( V_48 , V_49 ,
* V_52 ) ;
} else {
V_53 = F_19 ( V_48 , V_49 ) ;
}
}
}
return V_53 ;
}
static void F_23 ( struct V_1 * V_1 , const struct V_58 * V_59 ,
T_1 V_60 , T_1 V_61 , T_1 V_62 ,
T_1 V_63 , T_1 V_64 )
{
T_2 V_65 , V_66 ;
T_2 V_67 = V_68 ;
T_2 V_69 = V_68 ;
int V_70 = F_24 ( V_64 ) ;
int V_71 = F_25 ( V_64 ) ;
bool V_72 = F_15 ( V_64 ) ;
T_2 V_73 = V_60 / V_70 ;
T_2 V_74 = V_61 / V_71 ;
T_2 V_51 ;
T_2 V_75 ;
T_1 V_53 ;
int V_52 = 0 ;
if ( V_62 > 3840 ) {
F_26 ( V_1 -> V_14 , L_3 ) ;
return;
}
if ( ! V_59 -> V_76 -> V_77 -> V_78 ) {
F_27 ( V_1 , V_59 , V_79 ,
F_28 ( V_60 , V_62 ) ) ;
F_27 ( V_1 , V_59 , V_80 ,
F_28 ( V_61 , V_63 ) ) ;
if ( V_72 ) {
F_27 ( V_1 , V_59 , V_81 ,
F_28 ( V_73 , V_62 ) ) ;
F_27 ( V_1 , V_59 , V_82 ,
F_28 ( V_74 , V_63 ) ) ;
}
return;
}
V_65 = F_29 ( V_60 , V_62 ) ;
V_66 = F_29 ( V_61 , V_63 ) ;
if ( V_72 ) {
V_67 = F_29 ( V_73 , V_62 ) ;
V_69 = F_29 ( V_74 , V_63 ) ;
if ( V_67 == V_56 )
V_75 = F_30 ( V_62 , true ) ;
else
V_75 = F_30 ( V_73 , true ) ;
} else {
if ( V_65 == V_56 )
V_75 = F_30 ( V_62 , false ) ;
else
V_75 = F_30 ( V_60 , false ) ;
}
F_31 ( V_1 , V_59 , V_75 , V_75 ) ;
if ( V_75 == V_83 ) {
if ( V_66 != V_68 ) {
F_26 ( V_1 -> V_14 , L_4 ) ;
return;
}
if ( V_69 != V_68 ) {
F_26 ( V_1 -> V_14 , L_5 ) ;
return;
}
V_51 = V_57 ;
} else if ( V_75 == V_84 ) {
V_51 = V_57 ;
} else {
V_51 = V_85 ;
}
V_53 = F_17 ( V_65 , V_60 , V_62 ,
true , 0 , NULL ) ;
F_27 ( V_1 , V_59 , V_79 , V_53 ) ;
V_53 = F_17 ( V_66 , V_61 , V_63 ,
false , V_51 , & V_52 ) ;
F_27 ( V_1 , V_59 , V_80 , V_53 ) ;
F_31 ( V_1 , V_59 , V_86 , V_52 == 4 ) ;
F_31 ( V_1 , V_59 , V_87 , V_52 == 2 ) ;
F_31 ( V_1 , V_59 , V_65 , V_65 ) ;
F_31 ( V_1 , V_59 , V_66 , V_66 ) ;
F_31 ( V_1 , V_59 , V_88 , V_89 ) ;
F_31 ( V_1 , V_59 , V_90 , V_89 ) ;
F_31 ( V_1 , V_59 , V_91 , V_51 ) ;
if ( V_72 ) {
V_53 = F_17 ( V_67 , V_73 ,
V_62 , true , 0 , NULL ) ;
F_27 ( V_1 , V_59 , V_81 , V_53 ) ;
V_53 = F_17 ( V_69 , V_74 ,
V_63 , false , V_51 , & V_52 ) ;
F_27 ( V_1 , V_59 , V_82 , V_53 ) ;
F_31 ( V_1 , V_59 , V_92 , V_52 == 4 ) ;
F_31 ( V_1 , V_59 , V_93 , V_52 == 2 ) ;
F_31 ( V_1 , V_59 , V_67 , V_67 ) ;
F_31 ( V_1 , V_59 , V_69 , V_69 ) ;
F_31 ( V_1 , V_59 , V_94 , V_89 ) ;
F_31 ( V_1 , V_59 , V_95 , V_89 ) ;
F_31 ( V_1 , V_59 , V_96 , V_51 ) ;
}
}
static void F_32 ( struct V_1 * V_1 )
{
unsigned long V_97 ;
if ( F_33 ( ! V_1 -> V_98 ) )
return;
F_34 ( & V_1 -> V_99 , V_97 ) ;
F_35 ( V_1 , V_100 , V_101 , 1 ) ;
F_35 ( V_1 , V_102 , V_101 , 1 ) ;
F_36 ( & V_1 -> V_99 , V_97 ) ;
}
static void F_37 ( struct V_1 * V_1 )
{
unsigned long V_97 ;
if ( F_33 ( ! V_1 -> V_98 ) )
return;
F_34 ( & V_1 -> V_99 , V_97 ) ;
F_35 ( V_1 , V_102 , V_101 , 0 ) ;
F_36 ( & V_1 -> V_99 , V_97 ) ;
}
static bool F_38 ( struct V_1 * V_1 )
{
T_1 V_103 ;
unsigned long V_97 ;
F_34 ( & V_1 -> V_99 , V_97 ) ;
V_103 = F_39 ( V_1 , V_102 , V_104 ) ;
F_36 ( & V_1 -> V_99 , V_97 ) ;
return ! ! V_103 ;
}
static void F_40 ( struct V_1 * V_1 )
{
unsigned long V_97 ;
if ( F_33 ( ! V_1 -> V_98 ) )
return;
F_34 ( & V_1 -> V_99 , V_97 ) ;
F_35 ( V_1 , V_100 , V_104 , 1 ) ;
F_35 ( V_1 , V_102 , V_104 , 1 ) ;
F_36 ( & V_1 -> V_99 , V_97 ) ;
}
static void F_41 ( struct V_1 * V_1 )
{
unsigned long V_97 ;
if ( F_33 ( ! V_1 -> V_98 ) )
return;
F_34 ( & V_1 -> V_99 , V_97 ) ;
F_35 ( V_1 , V_102 , V_104 , 0 ) ;
F_36 ( & V_1 -> V_99 , V_97 ) ;
}
static int F_42 ( struct V_105 * V_106 )
{
struct V_1 * V_1 = F_43 ( V_106 ) ;
int V_19 , V_18 ;
V_19 = F_44 ( V_1 -> V_14 ) ;
if ( V_19 < 0 ) {
F_45 ( V_1 -> V_14 , L_6 , V_19 ) ;
return V_19 ;
}
V_19 = F_46 ( V_1 -> V_107 ) ;
if ( F_33 ( V_19 < 0 ) )
goto V_108;
V_19 = F_46 ( V_1 -> V_109 ) ;
if ( F_33 ( V_19 < 0 ) )
goto V_110;
V_19 = F_46 ( V_1 -> V_111 ) ;
if ( F_33 ( V_19 < 0 ) )
goto V_112;
V_19 = F_47 ( V_1 -> V_113 , V_1 -> V_14 ) ;
if ( V_19 ) {
F_45 ( V_1 -> V_14 , L_7 , V_19 ) ;
goto V_114;
}
memcpy ( V_1 -> V_4 , V_1 -> V_5 , V_1 -> V_115 ) ;
for ( V_18 = 0 ; V_18 < V_1 -> V_20 -> V_116 ; V_18 ++ ) {
struct V_117 * V_117 = & V_1 -> V_59 [ V_18 ] ;
const struct V_58 * V_59 = V_117 -> V_20 ;
F_48 ( & V_1 -> V_118 ) ;
F_49 ( V_1 , V_59 , V_102 , 0 ) ;
F_50 ( & V_1 -> V_118 ) ;
}
F_10 ( V_1 ) ;
V_1 -> V_98 = true ;
F_48 ( & V_1 -> V_118 ) ;
F_11 ( V_1 , V_24 , V_119 , 1 ) ;
F_50 ( & V_1 -> V_118 ) ;
F_51 ( V_1 -> V_120 ) ;
F_52 ( V_106 ) ;
return 0 ;
V_114:
F_53 ( V_1 -> V_111 ) ;
V_112:
F_53 ( V_1 -> V_109 ) ;
V_110:
F_53 ( V_1 -> V_107 ) ;
V_108:
F_54 ( V_1 -> V_14 ) ;
return V_19 ;
}
static void F_55 ( struct V_105 * V_106 ,
struct V_121 * V_122 )
{
struct V_1 * V_1 = F_43 ( V_106 ) ;
F_33 ( V_1 -> V_123 ) ;
F_56 ( & V_1 -> V_106 ) ;
F_57 ( V_106 ) ;
F_58 ( & V_1 -> V_124 ) ;
F_32 ( V_1 ) ;
F_48 ( & V_1 -> V_118 ) ;
F_11 ( V_1 , V_24 , V_119 , 1 ) ;
F_50 ( & V_1 -> V_118 ) ;
F_59 ( & V_1 -> V_124 ) ;
F_37 ( V_1 ) ;
F_60 ( V_1 -> V_120 ) ;
V_1 -> V_98 = false ;
F_61 ( V_1 -> V_113 , V_1 -> V_14 ) ;
F_53 ( V_1 -> V_109 ) ;
F_53 ( V_1 -> V_111 ) ;
F_53 ( V_1 -> V_107 ) ;
F_62 ( V_1 -> V_14 ) ;
if ( V_106 -> V_125 -> V_123 && ! V_106 -> V_125 -> V_126 ) {
F_63 ( & V_106 -> V_14 -> V_127 ) ;
F_64 ( V_106 , V_106 -> V_125 -> V_123 ) ;
F_65 ( & V_106 -> V_14 -> V_127 ) ;
V_106 -> V_125 -> V_123 = NULL ;
}
}
static void F_66 ( struct V_128 * V_129 )
{
F_67 ( V_129 ) ;
}
static int F_68 ( struct V_128 * V_129 ,
struct V_130 * V_125 )
{
struct V_105 * V_106 = V_125 -> V_106 ;
struct V_121 * V_131 ;
struct V_132 * V_133 = V_125 -> V_133 ;
struct V_117 * V_117 = F_69 ( V_129 ) ;
const struct V_58 * V_59 = V_117 -> V_20 ;
int V_19 ;
struct V_134 V_135 ;
int V_136 = V_59 -> V_76 -> V_77 ? F_70 ( 1 , 8 ) :
V_137 ;
int V_138 = V_59 -> V_76 -> V_77 ? F_70 ( 8 , 1 ) :
V_137 ;
if ( ! V_106 || ! V_133 )
return 0 ;
V_131 = F_71 ( V_125 -> V_125 , V_106 ) ;
if ( F_33 ( ! V_131 ) )
return - V_45 ;
V_135 . V_139 = 0 ;
V_135 . y1 = 0 ;
V_135 . V_140 = V_131 -> V_141 . V_142 ;
V_135 . V_143 = V_131 -> V_141 . V_144 ;
V_19 = F_72 ( V_125 , & V_135 ,
V_136 , V_138 ,
true , true ) ;
if ( V_19 )
return V_19 ;
if ( ! V_125 -> V_145 )
return 0 ;
V_19 = F_13 ( V_133 -> V_26 -> V_26 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( F_15 ( V_133 -> V_26 -> V_26 ) && ( ( V_125 -> V_48 . V_139 >> 16 ) % 2 ) ) {
F_14 ( L_8 ) ;
return - V_45 ;
}
return 0 ;
}
static void F_73 ( struct V_128 * V_129 ,
struct V_130 * V_122 )
{
struct V_117 * V_117 = F_69 ( V_129 ) ;
const struct V_58 * V_59 = V_117 -> V_20 ;
struct V_1 * V_1 = F_43 ( V_122 -> V_106 ) ;
if ( ! V_122 -> V_106 )
return;
F_48 ( & V_1 -> V_118 ) ;
F_49 ( V_1 , V_59 , V_102 , 0 ) ;
F_50 ( & V_1 -> V_118 ) ;
}
static void F_74 ( struct V_128 * V_129 ,
struct V_130 * V_122 )
{
struct V_130 * V_125 = V_129 -> V_125 ;
struct V_105 * V_106 = V_125 -> V_106 ;
struct V_117 * V_117 = F_69 ( V_129 ) ;
const struct V_58 * V_59 = V_117 -> V_20 ;
struct V_1 * V_1 = F_43 ( V_125 -> V_106 ) ;
struct V_132 * V_133 = V_125 -> V_133 ;
unsigned int V_146 , V_147 ;
unsigned int V_148 , V_149 ;
T_1 V_150 , V_151 , V_152 ;
struct V_134 * V_48 = & V_125 -> V_48 ;
struct V_134 * V_153 = & V_125 -> V_49 ;
struct V_154 * V_155 , * V_156 ;
struct V_157 * V_158 , * V_159 ;
unsigned long V_2 ;
T_3 V_160 ;
T_1 V_53 ;
bool V_161 ;
int V_26 ;
if ( F_33 ( ! V_106 ) )
return;
if ( F_33 ( ! V_1 -> V_98 ) )
return;
if ( ! V_125 -> V_145 ) {
F_73 ( V_129 , V_122 ) ;
return;
}
V_155 = F_75 ( V_133 , 0 ) ;
V_158 = F_76 ( V_155 ) ;
V_146 = F_77 ( V_48 ) >> 16 ;
V_147 = F_78 ( V_48 ) >> 16 ;
V_150 = ( V_147 - 1 ) << 16 | ( ( V_146 - 1 ) & 0xffff ) ;
V_151 = ( F_78 ( V_153 ) - 1 ) << 16 ;
V_151 |= ( F_77 ( V_153 ) - 1 ) & 0xffff ;
V_148 = V_153 -> V_139 + V_106 -> V_47 . V_162 - V_106 -> V_47 . V_163 ;
V_149 = V_153 -> y1 + V_106 -> V_47 . V_164 - V_106 -> V_47 . V_165 ;
V_152 = V_149 << 16 | ( V_148 & 0xffff ) ;
V_2 = ( V_48 -> V_139 >> 16 ) * V_133 -> V_26 -> V_166 [ 0 ] ;
V_2 += ( V_48 -> y1 >> 16 ) * V_133 -> V_167 [ 0 ] ;
V_160 = V_158 -> V_160 + V_2 + V_133 -> V_168 [ 0 ] ;
V_26 = F_13 ( V_133 -> V_26 -> V_26 ) ;
F_48 ( & V_1 -> V_118 ) ;
F_49 ( V_1 , V_59 , V_26 , V_26 ) ;
F_49 ( V_1 , V_59 , V_169 , F_79 ( V_133 -> V_167 [ 0 ] , 4 ) ) ;
F_49 ( V_1 , V_59 , V_170 , V_160 ) ;
if ( F_15 ( V_133 -> V_26 -> V_26 ) ) {
int V_70 = F_24 ( V_133 -> V_26 -> V_26 ) ;
int V_71 = F_25 ( V_133 -> V_26 -> V_26 ) ;
int V_171 = V_133 -> V_26 -> V_166 [ 1 ] ;
V_156 = F_75 ( V_133 , 1 ) ;
V_159 = F_76 ( V_156 ) ;
V_2 = ( V_48 -> V_139 >> 16 ) * V_171 / V_70 ;
V_2 += ( V_48 -> y1 >> 16 ) * V_133 -> V_167 [ 1 ] / V_71 ;
V_160 = V_159 -> V_160 + V_2 + V_133 -> V_168 [ 1 ] ;
F_49 ( V_1 , V_59 , V_172 , F_79 ( V_133 -> V_167 [ 1 ] , 4 ) ) ;
F_49 ( V_1 , V_59 , V_173 , V_160 ) ;
}
if ( V_59 -> V_76 -> V_77 )
F_23 ( V_1 , V_59 , V_146 , V_147 ,
F_77 ( V_153 ) , F_78 ( V_153 ) ,
V_133 -> V_26 -> V_26 ) ;
F_49 ( V_1 , V_59 , V_150 , V_150 ) ;
F_49 ( V_1 , V_59 , V_151 , V_151 ) ;
F_49 ( V_1 , V_59 , V_152 , V_152 ) ;
V_161 = F_12 ( V_133 -> V_26 -> V_26 ) ;
F_49 ( V_1 , V_59 , V_161 , V_161 ) ;
if ( F_16 ( V_133 -> V_26 -> V_26 ) ) {
F_49 ( V_1 , V_59 , V_174 ,
F_80 ( V_175 ) ) ;
V_53 = F_81 ( 1 ) | F_82 ( V_176 ) |
F_83 ( V_177 ) |
F_84 ( V_178 ) |
F_85 ( V_179 ) |
F_86 ( V_180 ) ;
F_49 ( V_1 , V_59 , V_181 , V_53 ) ;
} else {
F_49 ( V_1 , V_59 , V_181 , F_81 ( 0 ) ) ;
}
F_49 ( V_1 , V_59 , V_102 , 1 ) ;
F_50 ( & V_1 -> V_118 ) ;
}
static int F_87 ( struct V_105 * V_106 )
{
struct V_1 * V_1 = F_43 ( V_106 ) ;
unsigned long V_97 ;
if ( F_33 ( ! V_1 -> V_98 ) )
return - V_182 ;
F_34 ( & V_1 -> V_99 , V_97 ) ;
F_35 ( V_1 , V_100 , V_183 , 1 ) ;
F_35 ( V_1 , V_102 , V_183 , 1 ) ;
F_36 ( & V_1 -> V_99 , V_97 ) ;
return 0 ;
}
static void F_88 ( struct V_105 * V_106 )
{
struct V_1 * V_1 = F_43 ( V_106 ) ;
unsigned long V_97 ;
if ( F_33 ( ! V_1 -> V_98 ) )
return;
F_34 ( & V_1 -> V_99 , V_97 ) ;
F_35 ( V_1 , V_102 , V_183 , 0 ) ;
F_36 ( & V_1 -> V_99 , V_97 ) ;
}
static bool F_89 ( struct V_105 * V_106 ,
const struct V_184 * V_47 ,
struct V_184 * V_141 )
{
struct V_1 * V_1 = F_43 ( V_106 ) ;
V_141 -> clock =
F_90 ( V_1 -> V_109 , V_47 -> clock * 1000 ) / 1000 ;
return true ;
}
static void F_91 ( struct V_105 * V_106 ,
struct V_121 * V_122 )
{
struct V_1 * V_1 = F_43 ( V_106 ) ;
const struct V_185 * V_185 = V_1 -> V_20 ;
struct V_186 * V_187 = F_92 ( V_106 -> V_125 ) ;
struct V_184 * V_141 = & V_106 -> V_125 -> V_141 ;
T_4 V_188 = V_141 -> V_189 - V_141 -> V_163 ;
T_4 V_142 = V_141 -> V_142 ;
T_4 V_162 = V_141 -> V_162 ;
T_4 V_190 = V_141 -> V_162 - V_141 -> V_163 ;
T_4 V_191 = V_190 + V_142 ;
T_4 V_144 = V_141 -> V_144 ;
T_4 V_164 = V_141 -> V_164 ;
T_4 V_192 = V_141 -> V_193 - V_141 -> V_165 ;
T_4 V_194 = V_141 -> V_164 - V_141 -> V_165 ;
T_4 V_195 = V_194 + V_144 ;
T_1 V_196 , V_53 ;
int V_19 ;
F_33 ( V_1 -> V_123 ) ;
V_19 = F_42 ( V_106 ) ;
if ( V_19 ) {
F_26 ( V_1 -> V_14 , L_9 , V_19 ) ;
return;
}
V_196 = F_93 ( V_197 ) ;
V_196 |= ( V_141 -> V_97 & V_198 ) ?
F_93 ( V_199 ) : 0 ;
V_196 |= ( V_141 -> V_97 & V_200 ) ?
F_93 ( V_201 ) : 0 ;
F_11 ( V_1 , V_202 , V_196 , V_196 ) ;
switch ( V_187 -> V_203 ) {
case V_204 :
F_11 ( V_1 , V_202 , V_205 , 1 ) ;
F_11 ( V_1 , V_202 , V_206 , V_196 ) ;
break;
case V_207 :
F_11 ( V_1 , V_202 , V_208 , V_196 ) ;
F_11 ( V_1 , V_202 , V_209 , 1 ) ;
break;
case V_210 :
F_11 ( V_1 , V_202 , V_211 , V_196 ) ;
F_11 ( V_1 , V_202 , V_212 , 1 ) ;
break;
case V_213 :
F_11 ( V_1 , V_202 , V_214 , V_196 ) ;
F_11 ( V_1 , V_202 , V_215 , 1 ) ;
break;
case V_216 :
V_196 &= ~ F_93 ( V_197 ) ;
F_11 ( V_1 , V_202 , V_217 , V_196 ) ;
F_11 ( V_1 , V_202 , V_218 , 1 ) ;
break;
default:
F_26 ( V_1 -> V_14 , L_10 ,
V_187 -> V_203 ) ;
}
if ( V_187 -> V_219 == V_220 &&
! ( V_185 -> V_221 & V_222 ) )
V_187 -> V_219 = V_223 ;
F_11 ( V_1 , V_24 , V_224 , V_187 -> V_219 ) ;
F_11 ( V_1 , V_225 , V_226 , ( V_162 << 16 ) | V_188 ) ;
V_53 = V_190 << 16 ;
V_53 |= V_191 ;
F_11 ( V_1 , V_225 , V_227 , V_53 ) ;
F_11 ( V_1 , V_225 , V_228 , V_53 ) ;
F_11 ( V_1 , V_225 , V_229 , ( V_164 << 16 ) | V_192 ) ;
V_53 = V_194 << 16 ;
V_53 |= V_195 ;
F_11 ( V_1 , V_225 , V_230 , V_53 ) ;
F_11 ( V_1 , V_225 , V_231 , V_53 ) ;
F_11 ( V_1 , V_21 , V_232 [ 0 ] , V_195 ) ;
F_94 ( V_1 -> V_109 , V_141 -> clock * 1000 ) ;
F_11 ( V_1 , V_24 , V_119 , 0 ) ;
F_95 ( & V_1 -> V_106 ) ;
}
static bool F_96 ( struct V_1 * V_1 )
{
return F_39 ( V_1 , V_233 , V_183 ) ;
}
static void F_97 ( struct V_1 * V_1 )
{
bool V_234 ;
int V_19 ;
V_19 = F_98 ( F_96 , V_1 , V_234 ,
! V_234 , 0 , 10 * 1000 ) ;
if ( V_19 )
F_26 ( V_1 -> V_14 , L_11 ) ;
F_99 ( V_1 -> V_120 ) ;
}
static void F_100 ( struct V_105 * V_106 ,
struct V_121 * V_235 )
{
struct V_236 * V_122 = V_235 -> V_125 ;
struct V_130 * V_237 , * V_238 ;
struct V_1 * V_1 = F_43 ( V_106 ) ;
struct V_128 * V_129 ;
int V_18 ;
if ( F_33 ( ! V_1 -> V_98 ) )
return;
F_48 ( & V_1 -> V_118 ) ;
F_10 ( V_1 ) ;
F_50 ( & V_1 -> V_118 ) ;
F_97 ( V_1 ) ;
F_63 ( & V_106 -> V_14 -> V_127 ) ;
if ( V_106 -> V_125 -> V_123 ) {
F_33 ( F_101 ( V_106 ) != 0 ) ;
F_33 ( V_1 -> V_123 ) ;
V_1 -> V_123 = V_106 -> V_125 -> V_123 ;
V_106 -> V_125 -> V_123 = NULL ;
}
F_65 ( & V_106 -> V_14 -> V_127 ) ;
F_102 (old_state, plane, old_plane_state,
new_plane_state, i) {
if ( ! V_237 -> V_133 )
continue;
if ( V_237 -> V_133 == V_238 -> V_133 )
continue;
F_103 ( V_237 -> V_133 ) ;
F_104 ( & V_1 -> V_239 , V_237 -> V_133 ) ;
F_105 ( V_240 , & V_1 -> V_234 ) ;
F_33 ( F_101 ( V_106 ) != 0 ) ;
}
}
static void F_106 ( struct V_105 * V_106 ,
struct V_121 * V_235 )
{
F_107 ( V_106 ) ;
}
static void F_108 ( struct V_105 * V_106 )
{
F_109 ( V_106 ) ;
}
static void F_110 ( struct V_105 * V_106 )
{
if ( V_106 -> V_125 )
F_111 ( V_106 -> V_125 ) ;
F_112 ( V_106 -> V_125 ) ;
V_106 -> V_125 = F_113 ( sizeof( struct V_186 ) , V_241 ) ;
if ( V_106 -> V_125 )
V_106 -> V_125 -> V_106 = V_106 ;
}
static struct V_121 * F_114 ( struct V_105 * V_106 )
{
struct V_186 * V_242 ;
V_242 = F_113 ( sizeof( * V_242 ) , V_241 ) ;
if ( ! V_242 )
return NULL ;
F_115 ( V_106 , & V_242 -> V_6 ) ;
return & V_242 -> V_6 ;
}
static void F_116 ( struct V_105 * V_106 ,
struct V_121 * V_125 )
{
struct V_186 * V_187 = F_92 ( V_125 ) ;
F_111 ( & V_187 -> V_6 ) ;
F_112 ( V_187 ) ;
}
static struct V_243 * F_117 ( struct V_1 * V_1 )
{
struct V_243 * V_244 ;
struct V_245 V_246 ;
F_118 ( V_1 -> V_113 , & V_246 ) ;
F_119 (connector, &conn_iter) {
if ( V_244 -> V_247 == V_207 ) {
F_120 ( & V_246 ) ;
return V_244 ;
}
}
F_120 ( & V_246 ) ;
return NULL ;
}
static int F_121 ( struct V_105 * V_106 ,
const char * V_248 , T_5 * V_249 )
{
struct V_1 * V_1 = F_43 ( V_106 ) ;
struct V_243 * V_244 ;
int V_19 ;
V_244 = F_117 ( V_1 ) ;
if ( ! V_244 )
return - V_45 ;
* V_249 = 3 ;
if ( V_248 && strcmp ( V_248 , L_12 ) == 0 )
V_19 = F_122 ( V_244 ) ;
else if ( ! V_248 )
V_19 = F_123 ( V_244 ) ;
else
V_19 = - V_45 ;
return V_19 ;
}
static int F_121 ( struct V_105 * V_106 ,
const char * V_248 , T_5 * V_249 )
{
return - V_250 ;
}
static void F_124 ( struct V_251 * V_252 , void * V_53 )
{
struct V_1 * V_1 = F_125 ( V_252 , struct V_1 , V_239 ) ;
struct V_132 * V_133 = V_53 ;
F_126 ( & V_1 -> V_106 ) ;
F_127 ( V_133 ) ;
}
static void F_128 ( struct V_1 * V_1 )
{
struct V_253 * V_254 = V_1 -> V_113 ;
struct V_105 * V_106 = & V_1 -> V_106 ;
unsigned long V_97 ;
F_34 ( & V_254 -> V_127 , V_97 ) ;
if ( V_1 -> V_123 ) {
F_64 ( V_106 , V_1 -> V_123 ) ;
F_126 ( V_106 ) ;
V_1 -> V_123 = NULL ;
}
F_36 ( & V_254 -> V_127 , V_97 ) ;
if ( F_129 ( V_240 , & V_1 -> V_234 ) )
F_130 ( & V_1 -> V_239 , V_255 ) ;
}
static T_6 F_131 ( int V_120 , void * V_20 )
{
struct V_1 * V_1 = V_20 ;
struct V_105 * V_106 = & V_1 -> V_106 ;
T_1 V_256 ;
unsigned long V_97 ;
int V_19 = V_257 ;
F_34 ( & V_1 -> V_99 , V_97 ) ;
V_256 = F_39 ( V_1 , V_233 , V_258 ) ;
if ( V_256 )
F_35 ( V_1 , V_100 , V_256 , 1 ) ;
F_36 ( & V_1 -> V_99 , V_97 ) ;
if ( ! V_256 )
return V_257 ;
if ( V_256 & V_101 ) {
F_132 ( & V_1 -> V_124 ) ;
V_256 &= ~ V_101 ;
V_19 = V_259 ;
}
if ( V_256 & V_104 ) {
F_132 ( & V_1 -> V_260 ) ;
V_256 &= ~ V_104 ;
V_19 = V_259 ;
}
if ( V_256 & V_183 ) {
F_133 ( V_106 ) ;
F_128 ( V_1 ) ;
V_256 &= ~ V_183 ;
V_19 = V_259 ;
}
if ( V_256 )
F_26 ( V_1 -> V_14 , L_13 ,
V_256 ) ;
return V_19 ;
}
static int F_134 ( struct V_1 * V_1 )
{
const struct V_185 * V_185 = V_1 -> V_20 ;
struct V_261 * V_14 = V_1 -> V_14 ;
struct V_253 * V_113 = V_1 -> V_113 ;
struct V_128 * V_262 = NULL , * V_263 = NULL , * V_129 , * V_264 ;
struct V_105 * V_106 = & V_1 -> V_106 ;
struct V_265 * V_266 ;
int V_19 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_185 -> V_116 ; V_18 ++ ) {
struct V_117 * V_117 = & V_1 -> V_59 [ V_18 ] ;
const struct V_58 * V_267 = V_117 -> V_20 ;
if ( V_267 -> type != V_268 &&
V_267 -> type != V_269 )
continue;
V_19 = F_135 ( V_1 -> V_113 , & V_117 -> V_6 ,
0 , & V_270 ,
V_267 -> V_76 -> V_271 ,
V_267 -> V_76 -> V_272 ,
NULL , V_267 -> type , NULL ) ;
if ( V_19 ) {
F_26 ( V_1 -> V_14 , L_14 ,
V_19 ) ;
goto V_273;
}
V_129 = & V_117 -> V_6 ;
F_136 ( V_129 , & V_274 ) ;
if ( V_129 -> type == V_268 )
V_262 = V_129 ;
else if ( V_129 -> type == V_269 )
V_263 = V_129 ;
}
V_19 = F_137 ( V_113 , V_106 , V_262 , V_263 ,
& V_275 , NULL ) ;
if ( V_19 )
goto V_273;
F_138 ( V_106 , & V_276 ) ;
for ( V_18 = 0 ; V_18 < V_185 -> V_116 ; V_18 ++ ) {
struct V_117 * V_117 = & V_1 -> V_59 [ V_18 ] ;
const struct V_58 * V_267 = V_117 -> V_20 ;
unsigned long V_277 = 1 << F_139 ( V_106 ) ;
if ( V_267 -> type != V_278 )
continue;
V_19 = F_135 ( V_1 -> V_113 , & V_117 -> V_6 ,
V_277 ,
& V_270 ,
V_267 -> V_76 -> V_271 ,
V_267 -> V_76 -> V_272 ,
NULL , V_267 -> type , NULL ) ;
if ( V_19 ) {
F_26 ( V_1 -> V_14 , L_15 ,
V_19 ) ;
goto V_279;
}
F_136 ( & V_117 -> V_6 , & V_274 ) ;
}
V_266 = F_140 ( V_14 -> V_280 , L_16 ) ;
if ( ! V_266 ) {
F_26 ( V_1 -> V_14 , L_17 ,
V_14 -> V_280 ) ;
V_19 = - V_281 ;
goto V_279;
}
F_141 ( & V_1 -> V_239 , L_18 ,
F_124 ) ;
F_142 ( & V_1 -> V_124 ) ;
F_142 ( & V_1 -> V_260 ) ;
V_106 -> V_266 = V_266 ;
return 0 ;
V_279:
F_109 ( V_106 ) ;
V_273:
F_143 (plane, tmp, &drm_dev->mode_config.plane_list,
head)
F_67 ( V_129 ) ;
return V_19 ;
}
static void F_144 ( struct V_1 * V_1 )
{
struct V_105 * V_106 = & V_1 -> V_106 ;
struct V_253 * V_113 = V_1 -> V_113 ;
struct V_128 * V_129 , * V_264 ;
F_145 ( V_106 -> V_266 ) ;
F_143 (plane, tmp, &drm_dev->mode_config.plane_list,
head)
F_66 ( V_129 ) ;
F_109 ( V_106 ) ;
F_146 ( & V_1 -> V_239 ) ;
}
static int F_147 ( struct V_1 * V_1 )
{
const struct V_185 * V_185 = V_1 -> V_20 ;
struct V_282 * V_283 ;
int V_18 , V_19 ;
V_1 -> V_107 = F_148 ( V_1 -> V_14 , L_19 ) ;
if ( F_149 ( V_1 -> V_107 ) ) {
F_45 ( V_1 -> V_14 , L_20 ) ;
return F_150 ( V_1 -> V_107 ) ;
}
V_1 -> V_111 = F_148 ( V_1 -> V_14 , L_21 ) ;
if ( F_149 ( V_1 -> V_111 ) ) {
F_45 ( V_1 -> V_14 , L_22 ) ;
return F_150 ( V_1 -> V_111 ) ;
}
V_1 -> V_109 = F_148 ( V_1 -> V_14 , L_23 ) ;
if ( F_149 ( V_1 -> V_109 ) ) {
F_45 ( V_1 -> V_14 , L_24 ) ;
return F_150 ( V_1 -> V_109 ) ;
}
V_19 = F_44 ( V_1 -> V_14 ) ;
if ( V_19 < 0 ) {
F_45 ( V_1 -> V_14 , L_6 , V_19 ) ;
return V_19 ;
}
V_19 = F_151 ( V_1 -> V_109 ) ;
if ( V_19 < 0 ) {
F_45 ( V_1 -> V_14 , L_25 ) ;
goto V_108;
}
V_19 = F_152 ( V_1 -> V_107 ) ;
if ( V_19 < 0 ) {
F_45 ( V_1 -> V_14 , L_26 ) ;
goto V_284;
}
V_19 = F_152 ( V_1 -> V_111 ) ;
if ( V_19 < 0 ) {
F_45 ( V_1 -> V_14 , L_27 ) ;
goto V_110;
}
V_283 = F_153 ( V_1 -> V_14 , L_28 ) ;
if ( F_149 ( V_283 ) ) {
F_45 ( V_1 -> V_14 , L_29 ) ;
V_19 = F_150 ( V_283 ) ;
goto V_114;
}
F_154 ( V_283 ) ;
F_155 ( 10 , 20 ) ;
F_156 ( V_283 ) ;
memcpy ( V_1 -> V_5 , V_1 -> V_4 , V_1 -> V_115 ) ;
F_11 ( V_1 , V_285 , V_286 , 1 ) ;
F_11 ( V_1 , V_24 , V_287 , 0 ) ;
for ( V_18 = 0 ; V_18 < V_185 -> V_116 ; V_18 ++ ) {
const struct V_58 * V_59 = & V_185 -> V_59 [ V_18 ] ;
int V_288 = V_18 * 2 + 1 ;
F_49 ( V_1 , V_59 , V_288 , ( V_288 + 1 ) << 4 | V_288 ) ;
F_49 ( V_1 , V_59 , V_102 , 0 ) ;
F_49 ( V_1 , V_59 , V_289 , 1 ) ;
}
F_10 ( V_1 ) ;
V_1 -> V_290 = F_153 ( V_1 -> V_14 , L_30 ) ;
if ( F_149 ( V_1 -> V_290 ) ) {
F_45 ( V_1 -> V_14 , L_31 ) ;
V_19 = F_150 ( V_1 -> V_290 ) ;
goto V_114;
}
F_154 ( V_1 -> V_290 ) ;
F_155 ( 10 , 20 ) ;
F_156 ( V_1 -> V_290 ) ;
F_53 ( V_1 -> V_107 ) ;
F_53 ( V_1 -> V_111 ) ;
V_1 -> V_98 = false ;
F_54 ( V_1 -> V_14 ) ;
return 0 ;
V_114:
F_157 ( V_1 -> V_111 ) ;
V_110:
F_157 ( V_1 -> V_107 ) ;
V_284:
F_158 ( V_1 -> V_109 ) ;
V_108:
F_54 ( V_1 -> V_14 ) ;
return V_19 ;
}
static void F_159 ( struct V_1 * V_1 )
{
const struct V_185 * V_185 = V_1 -> V_20 ;
unsigned int V_18 ;
for ( V_18 = 0 ; V_18 < V_185 -> V_116 ; V_18 ++ ) {
struct V_117 * V_117 = & V_1 -> V_59 [ V_18 ] ;
const struct V_58 * V_267 = & V_185 -> V_59 [ V_18 ] ;
V_117 -> V_20 = V_267 ;
V_117 -> V_1 = V_1 ;
}
}
int F_160 ( struct V_105 * V_106 , unsigned int V_291 )
{
struct V_1 * V_1 = F_43 ( V_106 ) ;
unsigned long V_292 ;
if ( ! V_106 || ! V_1 -> V_98 )
return - V_250 ;
if ( V_291 <= 0 )
return - V_45 ;
if ( F_38 ( V_1 ) )
return - V_293 ;
F_58 ( & V_1 -> V_260 ) ;
F_40 ( V_1 ) ;
V_292 = F_161 ( & V_1 -> V_260 ,
F_162 ( V_291 ) ) ;
F_41 ( V_1 ) ;
if ( V_292 == 0 ) {
F_45 ( V_1 -> V_14 , L_32 ) ;
return - V_294 ;
}
return 0 ;
}
static int F_163 ( struct V_261 * V_14 , struct V_261 * V_295 , void * V_20 )
{
struct V_296 * V_297 = F_164 ( V_14 ) ;
const struct V_185 * V_185 ;
struct V_253 * V_113 = V_20 ;
struct V_1 * V_1 ;
struct V_298 * V_299 ;
T_5 V_300 ;
int V_19 , V_120 ;
V_185 = F_165 ( V_14 ) ;
if ( ! V_185 )
return - V_250 ;
V_300 = sizeof( * V_1 ) + sizeof( * V_1 -> V_59 ) * V_185 -> V_116 ;
V_1 = F_166 ( V_14 , V_300 , V_241 ) ;
if ( ! V_1 )
return - V_301 ;
V_1 -> V_14 = V_14 ;
V_1 -> V_20 = V_185 ;
V_1 -> V_113 = V_113 ;
F_167 ( V_14 , V_1 ) ;
F_159 ( V_1 ) ;
V_299 = F_168 ( V_297 , V_302 , 0 ) ;
V_1 -> V_115 = F_169 ( V_299 ) ;
V_1 -> V_4 = F_170 ( V_14 , V_299 ) ;
if ( F_149 ( V_1 -> V_4 ) )
return F_150 ( V_1 -> V_4 ) ;
V_1 -> V_5 = F_166 ( V_14 , V_1 -> V_115 , V_241 ) ;
if ( ! V_1 -> V_5 )
return - V_301 ;
V_120 = F_171 ( V_297 , 0 ) ;
if ( V_120 < 0 ) {
F_45 ( V_14 , L_33 ) ;
return V_120 ;
}
V_1 -> V_120 = ( unsigned int ) V_120 ;
F_172 ( & V_1 -> V_118 ) ;
F_172 ( & V_1 -> V_99 ) ;
F_173 ( & V_1 -> V_303 ) ;
V_19 = F_174 ( V_14 , V_1 -> V_120 , F_131 ,
V_304 , F_175 ( V_14 ) , V_1 ) ;
if ( V_19 )
return V_19 ;
F_60 ( V_1 -> V_120 ) ;
V_19 = F_134 ( V_1 ) ;
if ( V_19 )
goto V_305;
F_176 ( & V_297 -> V_14 ) ;
V_19 = F_147 ( V_1 ) ;
if ( V_19 < 0 ) {
F_45 ( & V_297 -> V_14 , L_34 , V_19 ) ;
goto V_306;
}
return 0 ;
V_306:
F_177 ( & V_297 -> V_14 ) ;
F_144 ( V_1 ) ;
V_305:
F_51 ( V_1 -> V_120 ) ;
return V_19 ;
}
static void F_178 ( struct V_261 * V_14 , struct V_261 * V_295 , void * V_20 )
{
struct V_1 * V_1 = F_179 ( V_14 ) ;
F_177 ( V_14 ) ;
F_144 ( V_1 ) ;
F_158 ( V_1 -> V_111 ) ;
F_158 ( V_1 -> V_107 ) ;
F_158 ( V_1 -> V_109 ) ;
}
