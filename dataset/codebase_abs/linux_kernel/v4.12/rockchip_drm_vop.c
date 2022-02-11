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
static inline void F_6 ( struct V_1 * V_1 , T_1 V_2 ,
T_1 V_10 , T_1 V_9 , T_1 V_3 ,
bool V_11 , bool V_12 )
{
if ( ! V_10 )
return;
if ( V_11 ) {
V_3 = ( ( V_3 << V_9 ) & 0xffff ) | ( V_10 << ( V_9 + 16 ) ) ;
} else {
T_1 V_13 = V_1 -> V_5 [ V_2 >> 2 ] ;
V_3 = ( V_13 & ~ ( V_10 << V_9 ) ) | ( ( V_3 & V_10 ) << V_9 ) ;
V_1 -> V_5 [ V_2 >> 2 ] = V_3 ;
}
if ( V_12 )
F_7 ( V_3 , V_1 -> V_4 + V_2 ) ;
else
F_2 ( V_3 , V_1 -> V_4 + V_2 ) ;
}
static inline T_1 F_8 ( struct V_1 * V_1 ,
const struct V_7 * V_8 , int type )
{
T_1 V_14 , V_15 = 0 ;
T_1 V_4 = F_5 ( V_1 , 0 , V_8 ) ;
for ( V_14 = 0 ; V_14 < V_1 -> V_16 -> V_17 -> V_18 ; V_14 ++ ) {
if ( ( type & V_1 -> V_16 -> V_17 -> V_19 [ V_14 ] ) && ( V_4 & 1 << V_14 ) )
V_15 |= V_1 -> V_16 -> V_17 -> V_19 [ V_14 ] ;
}
return V_15 ;
}
static inline void F_9 ( struct V_1 * V_1 )
{
F_10 ( V_1 , V_20 , 1 ) ;
}
static bool F_11 ( T_1 V_21 )
{
switch ( V_21 ) {
case V_22 :
case V_23 :
case V_24 :
case V_25 :
return true ;
default:
return false ;
}
}
static enum V_26 F_12 ( T_1 V_21 )
{
switch ( V_21 ) {
case V_27 :
case V_28 :
case V_22 :
case V_23 :
return V_29 ;
case V_30 :
case V_24 :
return V_31 ;
case V_32 :
case V_25 :
return V_33 ;
case V_34 :
return V_35 ;
case V_36 :
return V_37 ;
case V_38 :
return V_39 ;
default:
F_13 ( L_1 , V_21 ) ;
return - V_40 ;
}
}
static bool F_14 ( T_1 V_21 )
{
switch ( V_21 ) {
case V_34 :
case V_36 :
case V_38 :
return true ;
default:
return false ;
}
}
static bool F_15 ( T_1 V_21 )
{
switch ( V_21 ) {
case V_28 :
case V_23 :
return true ;
default:
return false ;
}
}
static T_2 F_16 ( enum V_41 V_42 , T_1 V_43 ,
T_1 V_44 , bool V_45 ,
int V_46 , int * V_47 )
{
T_2 V_48 = 1 << V_49 ;
if ( V_45 ) {
if ( V_42 == V_50 )
V_48 = F_17 ( V_43 , V_44 ) ;
else if ( V_42 == V_51 )
V_48 = F_18 ( V_43 , V_44 ) ;
} else {
if ( V_42 == V_50 ) {
if ( V_46 == V_52 )
V_48 = F_19 ( V_43 , V_44 ) ;
else
V_48 = F_17 ( V_43 , V_44 ) ;
} else if ( V_42 == V_51 ) {
if ( V_47 ) {
* V_47 = F_20 ( V_43 , V_44 ) ;
V_48 = F_21 ( V_43 , V_44 ,
* V_47 ) ;
} else {
V_48 = F_18 ( V_43 , V_44 ) ;
}
}
}
return V_48 ;
}
static void F_22 ( struct V_1 * V_1 , const struct V_53 * V_54 ,
T_1 V_55 , T_1 V_56 , T_1 V_57 ,
T_1 V_58 , T_1 V_59 )
{
T_2 V_60 , V_61 ;
T_2 V_62 = V_63 ;
T_2 V_64 = V_63 ;
int V_65 = F_23 ( V_59 ) ;
int V_66 = F_24 ( V_59 ) ;
bool V_67 = F_14 ( V_59 ) ;
T_2 V_68 = V_55 / V_65 ;
T_2 V_69 = V_56 / V_66 ;
T_2 V_46 ;
T_2 V_70 ;
T_1 V_48 ;
int V_47 = 0 ;
if ( V_57 > 3840 ) {
F_25 ( V_1 -> V_71 , L_2 ) ;
return;
}
if ( ! V_54 -> V_72 -> V_73 -> V_74 ) {
F_26 ( V_1 , V_54 , V_75 ,
F_27 ( V_55 , V_57 ) ) ;
F_26 ( V_1 , V_54 , V_76 ,
F_27 ( V_56 , V_58 ) ) ;
if ( V_67 ) {
F_26 ( V_1 , V_54 , V_77 ,
F_27 ( V_68 , V_57 ) ) ;
F_26 ( V_1 , V_54 , V_78 ,
F_27 ( V_69 , V_58 ) ) ;
}
return;
}
V_60 = F_28 ( V_55 , V_57 ) ;
V_61 = F_28 ( V_56 , V_58 ) ;
if ( V_67 ) {
V_62 = F_28 ( V_68 , V_57 ) ;
V_64 = F_28 ( V_69 , V_58 ) ;
if ( V_62 == V_51 )
V_70 = F_29 ( V_57 , true ) ;
else
V_70 = F_29 ( V_68 , true ) ;
} else {
if ( V_60 == V_51 )
V_70 = F_29 ( V_57 , false ) ;
else
V_70 = F_29 ( V_55 , false ) ;
}
F_30 ( V_1 , V_54 , V_70 , V_70 ) ;
if ( V_70 == V_79 ) {
if ( V_61 != V_63 ) {
F_25 ( V_1 -> V_71 , L_3 ) ;
return;
}
if ( V_64 != V_63 ) {
F_25 ( V_1 -> V_71 , L_4 ) ;
return;
}
V_46 = V_52 ;
} else if ( V_70 == V_80 ) {
V_46 = V_52 ;
} else {
V_46 = V_81 ;
}
V_48 = F_16 ( V_60 , V_55 , V_57 ,
true , 0 , NULL ) ;
F_26 ( V_1 , V_54 , V_75 , V_48 ) ;
V_48 = F_16 ( V_61 , V_56 , V_58 ,
false , V_46 , & V_47 ) ;
F_26 ( V_1 , V_54 , V_76 , V_48 ) ;
F_30 ( V_1 , V_54 , V_82 , V_47 == 4 ) ;
F_30 ( V_1 , V_54 , V_83 , V_47 == 2 ) ;
F_30 ( V_1 , V_54 , V_60 , V_60 ) ;
F_30 ( V_1 , V_54 , V_61 , V_61 ) ;
F_30 ( V_1 , V_54 , V_84 , V_85 ) ;
F_30 ( V_1 , V_54 , V_86 , V_85 ) ;
F_30 ( V_1 , V_54 , V_87 , V_46 ) ;
if ( V_67 ) {
V_48 = F_16 ( V_62 , V_68 ,
V_57 , true , 0 , NULL ) ;
F_26 ( V_1 , V_54 , V_77 , V_48 ) ;
V_48 = F_16 ( V_64 , V_69 ,
V_58 , false , V_46 , & V_47 ) ;
F_26 ( V_1 , V_54 , V_78 , V_48 ) ;
F_30 ( V_1 , V_54 , V_88 , V_47 == 4 ) ;
F_30 ( V_1 , V_54 , V_89 , V_47 == 2 ) ;
F_30 ( V_1 , V_54 , V_62 , V_62 ) ;
F_30 ( V_1 , V_54 , V_64 , V_64 ) ;
F_30 ( V_1 , V_54 , V_90 , V_85 ) ;
F_30 ( V_1 , V_54 , V_91 , V_85 ) ;
F_30 ( V_1 , V_54 , V_92 , V_46 ) ;
}
}
static void F_31 ( struct V_1 * V_1 )
{
unsigned long V_93 ;
if ( F_32 ( ! V_1 -> V_94 ) )
return;
F_33 ( & V_1 -> V_95 , V_93 ) ;
F_34 ( V_1 , V_96 , V_97 , 1 ) ;
F_34 ( V_1 , V_98 , V_97 , 1 ) ;
F_35 ( & V_1 -> V_95 , V_93 ) ;
}
static void F_36 ( struct V_1 * V_1 )
{
unsigned long V_93 ;
if ( F_32 ( ! V_1 -> V_94 ) )
return;
F_33 ( & V_1 -> V_95 , V_93 ) ;
F_34 ( V_1 , V_98 , V_97 , 0 ) ;
F_35 ( & V_1 -> V_95 , V_93 ) ;
}
static bool F_37 ( struct V_1 * V_1 )
{
T_1 V_99 ;
unsigned long V_93 ;
F_33 ( & V_1 -> V_95 , V_93 ) ;
V_99 = F_38 ( V_1 , V_98 , V_100 ) ;
F_35 ( & V_1 -> V_95 , V_93 ) ;
return ! ! V_99 ;
}
static void F_39 ( struct V_1 * V_1 , int V_101 )
{
unsigned long V_93 ;
if ( F_32 ( ! V_1 -> V_94 ) )
return;
F_33 ( & V_1 -> V_95 , V_93 ) ;
F_10 ( V_1 , V_102 [ 0 ] , V_101 ) ;
F_34 ( V_1 , V_96 , V_100 , 1 ) ;
F_34 ( V_1 , V_98 , V_100 , 1 ) ;
F_35 ( & V_1 -> V_95 , V_93 ) ;
}
static void F_40 ( struct V_1 * V_1 )
{
unsigned long V_93 ;
if ( F_32 ( ! V_1 -> V_94 ) )
return;
F_33 ( & V_1 -> V_95 , V_93 ) ;
F_34 ( V_1 , V_98 , V_100 , 0 ) ;
F_35 ( & V_1 -> V_95 , V_93 ) ;
}
static int F_41 ( struct V_103 * V_104 )
{
struct V_1 * V_1 = F_42 ( V_104 ) ;
int V_15 ;
V_15 = F_43 ( V_1 -> V_71 ) ;
if ( V_15 < 0 ) {
F_44 ( V_1 -> V_71 , L_5 , V_15 ) ;
return V_15 ;
}
V_15 = F_45 ( V_1 -> V_105 ) ;
if ( F_32 ( V_15 < 0 ) )
goto V_106;
V_15 = F_45 ( V_1 -> V_107 ) ;
if ( F_32 ( V_15 < 0 ) )
goto V_108;
V_15 = F_45 ( V_1 -> V_109 ) ;
if ( F_32 ( V_15 < 0 ) )
goto V_110;
V_15 = F_46 ( V_1 -> V_111 , V_1 -> V_71 ) ;
if ( V_15 ) {
F_44 ( V_1 -> V_71 , L_6 , V_15 ) ;
goto V_112;
}
memcpy ( V_1 -> V_4 , V_1 -> V_5 , V_1 -> V_113 ) ;
F_9 ( V_1 ) ;
V_1 -> V_94 = true ;
F_47 ( & V_1 -> V_114 ) ;
F_10 ( V_1 , V_115 , 0 ) ;
F_48 ( & V_1 -> V_114 ) ;
F_49 ( V_1 -> V_116 ) ;
F_50 ( V_104 ) ;
return 0 ;
V_112:
F_51 ( V_1 -> V_109 ) ;
V_110:
F_51 ( V_1 -> V_107 ) ;
V_108:
F_51 ( V_1 -> V_105 ) ;
V_106:
F_52 ( V_1 -> V_71 ) ;
return V_15 ;
}
static void F_53 ( struct V_103 * V_104 )
{
struct V_1 * V_1 = F_42 ( V_104 ) ;
int V_14 ;
F_32 ( V_1 -> V_117 ) ;
F_54 ( & V_1 -> V_104 ) ;
for ( V_14 = 0 ; V_14 < V_1 -> V_16 -> V_118 ; V_14 ++ ) {
struct V_119 * V_119 = & V_1 -> V_54 [ V_14 ] ;
const struct V_53 * V_54 = V_119 -> V_16 ;
F_47 ( & V_1 -> V_114 ) ;
F_55 ( V_1 , V_54 , V_98 , 0 ) ;
F_48 ( & V_1 -> V_114 ) ;
}
F_9 ( V_1 ) ;
F_56 ( V_104 ) ;
F_57 ( & V_1 -> V_120 ) ;
F_31 ( V_1 ) ;
F_47 ( & V_1 -> V_114 ) ;
F_10 ( V_1 , V_115 , 1 ) ;
F_48 ( & V_1 -> V_114 ) ;
F_58 ( & V_1 -> V_120 ) ;
F_36 ( V_1 ) ;
F_59 ( V_1 -> V_116 ) ;
V_1 -> V_94 = false ;
F_60 ( V_1 -> V_111 , V_1 -> V_71 ) ;
F_51 ( V_1 -> V_107 ) ;
F_51 ( V_1 -> V_109 ) ;
F_51 ( V_1 -> V_105 ) ;
F_61 ( V_1 -> V_71 ) ;
if ( V_104 -> V_121 -> V_117 && ! V_104 -> V_121 -> V_122 ) {
F_62 ( & V_104 -> V_71 -> V_123 ) ;
F_63 ( V_104 , V_104 -> V_121 -> V_117 ) ;
F_64 ( & V_104 -> V_71 -> V_123 ) ;
V_104 -> V_121 -> V_117 = NULL ;
}
}
static void F_65 ( struct V_124 * V_125 )
{
F_66 ( V_125 ) ;
}
static int F_67 ( struct V_124 * V_125 ,
struct V_126 * V_121 )
{
struct V_103 * V_104 = V_121 -> V_104 ;
struct V_127 * V_128 ;
struct V_129 * V_130 = V_121 -> V_130 ;
struct V_119 * V_119 = F_68 ( V_125 ) ;
const struct V_53 * V_54 = V_119 -> V_16 ;
int V_15 ;
struct V_131 V_132 ;
int V_133 = V_54 -> V_72 -> V_73 ? F_69 ( 1 , 8 ) :
V_134 ;
int V_135 = V_54 -> V_72 -> V_73 ? F_69 ( 8 , 1 ) :
V_134 ;
if ( ! V_104 || ! V_130 )
return 0 ;
V_128 = F_70 ( V_121 -> V_121 , V_104 ) ;
if ( F_32 ( ! V_128 ) )
return - V_40 ;
V_132 . V_136 = 0 ;
V_132 . y1 = 0 ;
V_132 . V_137 = V_128 -> V_138 . V_139 ;
V_132 . V_140 = V_128 -> V_138 . V_141 ;
V_15 = F_71 ( V_121 , & V_132 ,
V_133 , V_135 ,
true , true ) ;
if ( V_15 )
return V_15 ;
if ( ! V_121 -> V_142 )
return 0 ;
V_15 = F_12 ( V_130 -> V_21 -> V_21 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( F_14 ( V_130 -> V_21 -> V_21 ) && ( ( V_121 -> V_43 . V_136 >> 16 ) % 2 ) )
return - V_40 ;
return 0 ;
}
static void F_72 ( struct V_124 * V_125 ,
struct V_126 * V_143 )
{
struct V_119 * V_119 = F_68 ( V_125 ) ;
const struct V_53 * V_54 = V_119 -> V_16 ;
struct V_1 * V_1 = F_42 ( V_143 -> V_104 ) ;
if ( ! V_143 -> V_104 )
return;
F_47 ( & V_1 -> V_114 ) ;
F_55 ( V_1 , V_54 , V_98 , 0 ) ;
F_48 ( & V_1 -> V_114 ) ;
}
static void F_73 ( struct V_124 * V_125 ,
struct V_126 * V_143 )
{
struct V_126 * V_121 = V_125 -> V_121 ;
struct V_103 * V_104 = V_121 -> V_104 ;
struct V_119 * V_119 = F_68 ( V_125 ) ;
const struct V_53 * V_54 = V_119 -> V_16 ;
struct V_1 * V_1 = F_42 ( V_121 -> V_104 ) ;
struct V_129 * V_130 = V_121 -> V_130 ;
unsigned int V_144 , V_145 ;
unsigned int V_146 , V_147 ;
T_1 V_148 , V_149 , V_150 ;
struct V_131 * V_43 = & V_121 -> V_43 ;
struct V_131 * V_151 = & V_121 -> V_44 ;
struct V_152 * V_153 , * V_154 ;
struct V_155 * V_156 , * V_157 ;
unsigned long V_2 ;
T_3 V_158 ;
T_1 V_48 ;
bool V_159 ;
int V_21 ;
if ( F_32 ( ! V_104 ) )
return;
if ( F_32 ( ! V_1 -> V_94 ) )
return;
if ( ! V_121 -> V_142 ) {
F_72 ( V_125 , V_143 ) ;
return;
}
V_153 = F_74 ( V_130 , 0 ) ;
V_156 = F_75 ( V_153 ) ;
V_144 = F_76 ( V_43 ) >> 16 ;
V_145 = F_77 ( V_43 ) >> 16 ;
V_148 = ( V_145 - 1 ) << 16 | ( ( V_144 - 1 ) & 0xffff ) ;
V_149 = ( F_77 ( V_151 ) - 1 ) << 16 ;
V_149 |= ( F_76 ( V_151 ) - 1 ) & 0xffff ;
V_146 = V_151 -> V_136 + V_104 -> V_42 . V_160 - V_104 -> V_42 . V_161 ;
V_147 = V_151 -> y1 + V_104 -> V_42 . V_162 - V_104 -> V_42 . V_163 ;
V_150 = V_147 << 16 | ( V_146 & 0xffff ) ;
V_2 = ( V_43 -> V_136 >> 16 ) * V_130 -> V_21 -> V_164 [ 0 ] ;
V_2 += ( V_43 -> y1 >> 16 ) * V_130 -> V_165 [ 0 ] ;
V_158 = V_156 -> V_158 + V_2 + V_130 -> V_166 [ 0 ] ;
V_21 = F_12 ( V_130 -> V_21 -> V_21 ) ;
F_47 ( & V_1 -> V_114 ) ;
F_55 ( V_1 , V_54 , V_21 , V_21 ) ;
F_55 ( V_1 , V_54 , V_167 , V_130 -> V_165 [ 0 ] >> 2 ) ;
F_55 ( V_1 , V_54 , V_168 , V_158 ) ;
if ( F_14 ( V_130 -> V_21 -> V_21 ) ) {
int V_65 = F_23 ( V_130 -> V_21 -> V_21 ) ;
int V_66 = F_24 ( V_130 -> V_21 -> V_21 ) ;
int V_169 = V_130 -> V_21 -> V_164 [ 1 ] ;
V_154 = F_74 ( V_130 , 1 ) ;
V_157 = F_75 ( V_154 ) ;
V_2 = ( V_43 -> V_136 >> 16 ) * V_169 / V_65 ;
V_2 += ( V_43 -> y1 >> 16 ) * V_130 -> V_165 [ 1 ] / V_66 ;
V_158 = V_157 -> V_158 + V_2 + V_130 -> V_166 [ 1 ] ;
F_55 ( V_1 , V_54 , V_170 , V_130 -> V_165 [ 1 ] >> 2 ) ;
F_55 ( V_1 , V_54 , V_171 , V_158 ) ;
}
if ( V_54 -> V_72 -> V_73 )
F_22 ( V_1 , V_54 , V_144 , V_145 ,
F_76 ( V_151 ) , F_77 ( V_151 ) ,
V_130 -> V_21 -> V_21 ) ;
F_55 ( V_1 , V_54 , V_148 , V_148 ) ;
F_55 ( V_1 , V_54 , V_149 , V_149 ) ;
F_55 ( V_1 , V_54 , V_150 , V_150 ) ;
V_159 = F_11 ( V_130 -> V_21 -> V_21 ) ;
F_55 ( V_1 , V_54 , V_159 , V_159 ) ;
if ( F_15 ( V_130 -> V_21 -> V_21 ) ) {
F_55 ( V_1 , V_54 , V_172 ,
F_78 ( V_173 ) ) ;
V_48 = F_79 ( 1 ) | F_80 ( V_174 ) |
F_81 ( V_175 ) |
F_82 ( V_176 ) |
F_83 ( V_177 ) |
F_84 ( V_178 ) ;
F_55 ( V_1 , V_54 , V_179 , V_48 ) ;
} else {
F_55 ( V_1 , V_54 , V_179 , F_79 ( 0 ) ) ;
}
F_55 ( V_1 , V_54 , V_98 , 1 ) ;
F_48 ( & V_1 -> V_114 ) ;
}
static int F_85 ( struct V_103 * V_104 )
{
struct V_1 * V_1 = F_42 ( V_104 ) ;
unsigned long V_93 ;
if ( F_32 ( ! V_1 -> V_94 ) )
return - V_180 ;
F_33 ( & V_1 -> V_95 , V_93 ) ;
F_34 ( V_1 , V_96 , V_181 , 1 ) ;
F_34 ( V_1 , V_98 , V_181 , 1 ) ;
F_35 ( & V_1 -> V_95 , V_93 ) ;
return 0 ;
}
static void F_86 ( struct V_103 * V_104 )
{
struct V_1 * V_1 = F_42 ( V_104 ) ;
unsigned long V_93 ;
if ( F_32 ( ! V_1 -> V_94 ) )
return;
F_33 ( & V_1 -> V_95 , V_93 ) ;
F_34 ( V_1 , V_98 , V_181 , 0 ) ;
F_35 ( & V_1 -> V_95 , V_93 ) ;
}
static bool F_87 ( struct V_103 * V_104 ,
const struct V_182 * V_42 ,
struct V_182 * V_138 )
{
struct V_1 * V_1 = F_42 ( V_104 ) ;
V_138 -> clock =
F_88 ( V_1 -> V_107 , V_42 -> clock * 1000 ) / 1000 ;
return true ;
}
static void F_89 ( struct V_103 * V_104 )
{
struct V_1 * V_1 = F_42 ( V_104 ) ;
const struct V_183 * V_183 = V_1 -> V_16 ;
struct V_184 * V_185 = F_90 ( V_104 -> V_121 ) ;
struct V_182 * V_138 = & V_104 -> V_121 -> V_138 ;
T_4 V_186 = V_138 -> V_187 - V_138 -> V_161 ;
T_4 V_139 = V_138 -> V_139 ;
T_4 V_160 = V_138 -> V_160 ;
T_4 V_188 = V_138 -> V_160 - V_138 -> V_161 ;
T_4 V_189 = V_188 + V_139 ;
T_4 V_141 = V_138 -> V_141 ;
T_4 V_162 = V_138 -> V_162 ;
T_4 V_190 = V_138 -> V_191 - V_138 -> V_163 ;
T_4 V_192 = V_138 -> V_162 - V_138 -> V_163 ;
T_4 V_193 = V_192 + V_141 ;
T_1 V_194 , V_48 ;
int V_15 ;
F_32 ( V_1 -> V_117 ) ;
V_15 = F_41 ( V_104 ) ;
if ( V_15 ) {
F_25 ( V_1 -> V_71 , L_7 , V_15 ) ;
return;
}
if ( F_91 ( V_1 -> V_107 ) ) {
F_57 ( & V_1 -> V_120 ) ;
F_31 ( V_1 ) ;
F_47 ( & V_1 -> V_114 ) ;
F_10 ( V_1 , V_115 , 1 ) ;
F_48 ( & V_1 -> V_114 ) ;
F_58 ( & V_1 -> V_120 ) ;
F_36 ( V_1 ) ;
}
V_194 = F_92 ( V_195 ) ;
V_194 |= ( V_138 -> V_93 & V_196 ) ?
F_92 ( V_197 ) : 0 ;
V_194 |= ( V_138 -> V_93 & V_198 ) ?
F_92 ( V_199 ) : 0 ;
F_10 ( V_1 , V_194 , V_194 ) ;
switch ( V_185 -> V_200 ) {
case V_201 :
F_10 ( V_1 , V_202 , 1 ) ;
F_10 ( V_1 , V_203 , V_194 ) ;
break;
case V_204 :
F_10 ( V_1 , V_205 , V_194 ) ;
F_10 ( V_1 , V_206 , 1 ) ;
break;
case V_207 :
F_10 ( V_1 , V_208 , V_194 ) ;
F_10 ( V_1 , V_209 , 1 ) ;
break;
case V_210 :
F_10 ( V_1 , V_211 , V_194 ) ;
F_10 ( V_1 , V_212 , 1 ) ;
break;
case V_213 :
V_194 &= ~ F_92 ( V_195 ) ;
F_10 ( V_1 , V_214 , V_194 ) ;
F_10 ( V_1 , V_215 , 1 ) ;
break;
default:
F_25 ( V_1 -> V_71 , L_8 ,
V_185 -> V_200 ) ;
}
if ( V_185 -> V_216 == V_217 &&
! ( V_183 -> V_218 & V_219 ) )
V_185 -> V_216 = V_220 ;
F_10 ( V_1 , V_221 , V_185 -> V_216 ) ;
F_10 ( V_1 , V_222 , ( V_160 << 16 ) | V_186 ) ;
V_48 = V_188 << 16 ;
V_48 |= V_189 ;
F_10 ( V_1 , V_223 , V_48 ) ;
F_10 ( V_1 , V_224 , V_48 ) ;
F_10 ( V_1 , V_225 , ( V_162 << 16 ) | V_190 ) ;
V_48 = V_192 << 16 ;
V_48 |= V_193 ;
F_10 ( V_1 , V_226 , V_48 ) ;
F_10 ( V_1 , V_227 , V_48 ) ;
F_93 ( V_1 -> V_107 , V_138 -> clock * 1000 ) ;
F_10 ( V_1 , V_115 , 0 ) ;
F_94 ( & V_1 -> V_104 ) ;
}
static bool F_95 ( struct V_1 * V_1 )
{
return F_38 ( V_1 , V_228 , V_181 ) ;
}
static void F_96 ( struct V_1 * V_1 )
{
bool V_229 ;
int V_15 ;
V_15 = F_97 ( F_95 , V_1 , V_229 ,
! V_229 , 0 , 10 * 1000 ) ;
if ( V_15 )
F_25 ( V_1 -> V_71 , L_9 ) ;
F_98 ( V_1 -> V_116 ) ;
}
static void F_99 ( struct V_103 * V_104 ,
struct V_127 * V_230 )
{
struct V_231 * V_143 = V_230 -> V_121 ;
struct V_126 * V_232 ;
struct V_1 * V_1 = F_42 ( V_104 ) ;
struct V_124 * V_125 ;
int V_14 ;
if ( F_32 ( ! V_1 -> V_94 ) )
return;
F_47 ( & V_1 -> V_114 ) ;
F_9 ( V_1 ) ;
F_48 ( & V_1 -> V_114 ) ;
F_96 ( V_1 ) ;
F_62 ( & V_104 -> V_71 -> V_123 ) ;
if ( V_104 -> V_121 -> V_117 ) {
F_32 ( F_100 ( V_104 ) != 0 ) ;
F_32 ( V_1 -> V_117 ) ;
V_1 -> V_117 = V_104 -> V_121 -> V_117 ;
V_104 -> V_121 -> V_117 = NULL ;
}
F_64 ( & V_104 -> V_71 -> V_123 ) ;
F_101 (old_state, plane, old_plane_state, i) {
if ( ! V_232 -> V_130 )
continue;
if ( V_232 -> V_130 == V_125 -> V_121 -> V_130 )
continue;
F_102 ( V_232 -> V_130 ) ;
F_103 ( & V_1 -> V_233 , V_232 -> V_130 ) ;
F_104 ( V_234 , & V_1 -> V_229 ) ;
F_32 ( F_100 ( V_104 ) != 0 ) ;
}
}
static void F_105 ( struct V_103 * V_104 ,
struct V_127 * V_230 )
{
F_106 ( V_104 ) ;
}
static void F_107 ( struct V_103 * V_104 )
{
F_108 ( V_104 ) ;
}
static void F_109 ( struct V_103 * V_104 )
{
if ( V_104 -> V_121 )
F_110 ( V_104 -> V_121 ) ;
F_111 ( V_104 -> V_121 ) ;
V_104 -> V_121 = F_112 ( sizeof( struct V_184 ) , V_235 ) ;
if ( V_104 -> V_121 )
V_104 -> V_121 -> V_104 = V_104 ;
}
static struct V_127 * F_113 ( struct V_103 * V_104 )
{
struct V_184 * V_236 ;
V_236 = F_112 ( sizeof( * V_236 ) , V_235 ) ;
if ( ! V_236 )
return NULL ;
F_114 ( V_104 , & V_236 -> V_6 ) ;
return & V_236 -> V_6 ;
}
static void F_115 ( struct V_103 * V_104 ,
struct V_127 * V_121 )
{
struct V_184 * V_185 = F_90 ( V_121 ) ;
F_110 ( & V_185 -> V_6 ) ;
F_111 ( V_185 ) ;
}
static struct V_237 * F_116 ( struct V_1 * V_1 )
{
struct V_103 * V_104 = & V_1 -> V_104 ;
struct V_237 * V_238 ;
F_117 ( & V_104 -> V_71 -> V_239 . V_240 ) ;
F_118 (connector, crtc->dev)
if ( V_238 -> V_241 == V_204 ) {
F_119 ( & V_104 -> V_71 -> V_239 . V_240 ) ;
return V_238 ;
}
F_119 ( & V_104 -> V_71 -> V_239 . V_240 ) ;
return NULL ;
}
static int F_120 ( struct V_103 * V_104 ,
const char * V_242 , T_5 * V_243 )
{
struct V_1 * V_1 = F_42 ( V_104 ) ;
struct V_237 * V_238 ;
int V_15 ;
V_238 = F_116 ( V_1 ) ;
if ( ! V_238 )
return - V_40 ;
* V_243 = 3 ;
if ( V_242 && strcmp ( V_242 , L_10 ) == 0 )
V_15 = F_121 ( V_238 ) ;
else if ( ! V_242 )
V_15 = F_122 ( V_238 ) ;
else
V_15 = - V_40 ;
return V_15 ;
}
static int F_120 ( struct V_103 * V_104 ,
const char * V_242 , T_5 * V_243 )
{
return - V_244 ;
}
static void F_123 ( struct V_245 * V_246 , void * V_48 )
{
struct V_1 * V_1 = F_124 ( V_246 , struct V_1 , V_233 ) ;
struct V_129 * V_130 = V_48 ;
F_125 ( & V_1 -> V_104 ) ;
F_126 ( V_130 ) ;
}
static void F_127 ( struct V_1 * V_1 )
{
struct V_247 * V_248 = V_1 -> V_111 ;
struct V_103 * V_104 = & V_1 -> V_104 ;
unsigned long V_93 ;
F_33 ( & V_248 -> V_123 , V_93 ) ;
if ( V_1 -> V_117 ) {
F_63 ( V_104 , V_1 -> V_117 ) ;
F_125 ( V_104 ) ;
V_1 -> V_117 = NULL ;
}
F_35 ( & V_248 -> V_123 , V_93 ) ;
if ( F_128 ( V_234 , & V_1 -> V_229 ) )
F_129 ( & V_1 -> V_233 , V_249 ) ;
}
static T_6 F_130 ( int V_116 , void * V_16 )
{
struct V_1 * V_1 = V_16 ;
struct V_103 * V_104 = & V_1 -> V_104 ;
T_1 V_250 ;
unsigned long V_93 ;
int V_15 = V_251 ;
F_33 ( & V_1 -> V_95 , V_93 ) ;
V_250 = F_38 ( V_1 , V_228 , V_252 ) ;
if ( V_250 )
F_34 ( V_1 , V_96 , V_250 , 1 ) ;
F_35 ( & V_1 -> V_95 , V_93 ) ;
if ( ! V_250 )
return V_251 ;
if ( V_250 & V_97 ) {
F_131 ( & V_1 -> V_120 ) ;
V_250 &= ~ V_97 ;
V_15 = V_253 ;
}
if ( V_250 & V_100 ) {
F_131 ( & V_1 -> V_254 ) ;
V_250 &= ~ V_100 ;
V_15 = V_253 ;
}
if ( V_250 & V_181 ) {
F_132 ( V_104 ) ;
F_127 ( V_1 ) ;
V_250 &= ~ V_181 ;
V_15 = V_253 ;
}
if ( V_250 )
F_25 ( V_1 -> V_71 , L_11 ,
V_250 ) ;
return V_15 ;
}
static int F_133 ( struct V_1 * V_1 )
{
const struct V_183 * V_183 = V_1 -> V_16 ;
struct V_255 * V_71 = V_1 -> V_71 ;
struct V_247 * V_111 = V_1 -> V_111 ;
struct V_124 * V_256 = NULL , * V_257 = NULL , * V_125 , * V_258 ;
struct V_103 * V_104 = & V_1 -> V_104 ;
struct V_259 * V_260 ;
int V_15 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_183 -> V_118 ; V_14 ++ ) {
struct V_119 * V_119 = & V_1 -> V_54 [ V_14 ] ;
const struct V_53 * V_261 = V_119 -> V_16 ;
if ( V_261 -> type != V_262 &&
V_261 -> type != V_263 )
continue;
V_15 = F_134 ( V_1 -> V_111 , & V_119 -> V_6 ,
0 , & V_264 ,
V_261 -> V_72 -> V_265 ,
V_261 -> V_72 -> V_266 ,
V_261 -> type , NULL ) ;
if ( V_15 ) {
F_25 ( V_1 -> V_71 , L_12 ,
V_15 ) ;
goto V_267;
}
V_125 = & V_119 -> V_6 ;
F_135 ( V_125 , & V_268 ) ;
if ( V_125 -> type == V_262 )
V_256 = V_125 ;
else if ( V_125 -> type == V_263 )
V_257 = V_125 ;
}
V_15 = F_136 ( V_111 , V_104 , V_256 , V_257 ,
& V_269 , NULL ) ;
if ( V_15 )
goto V_267;
F_137 ( V_104 , & V_270 ) ;
for ( V_14 = 0 ; V_14 < V_183 -> V_118 ; V_14 ++ ) {
struct V_119 * V_119 = & V_1 -> V_54 [ V_14 ] ;
const struct V_53 * V_261 = V_119 -> V_16 ;
unsigned long V_271 = 1 << F_138 ( V_104 ) ;
if ( V_261 -> type != V_272 )
continue;
V_15 = F_134 ( V_1 -> V_111 , & V_119 -> V_6 ,
V_271 ,
& V_264 ,
V_261 -> V_72 -> V_265 ,
V_261 -> V_72 -> V_266 ,
V_261 -> type , NULL ) ;
if ( V_15 ) {
F_25 ( V_1 -> V_71 , L_13 ,
V_15 ) ;
goto V_273;
}
F_135 ( & V_119 -> V_6 , & V_268 ) ;
}
V_260 = F_139 ( V_71 -> V_274 , L_14 ) ;
if ( ! V_260 ) {
F_25 ( V_1 -> V_71 , L_15 ,
V_71 -> V_274 -> V_275 ) ;
V_15 = - V_276 ;
goto V_273;
}
F_140 ( & V_1 -> V_233 , L_16 ,
F_123 ) ;
F_141 ( & V_1 -> V_120 ) ;
F_141 ( & V_1 -> V_254 ) ;
V_104 -> V_260 = V_260 ;
return 0 ;
V_273:
F_108 ( V_104 ) ;
V_267:
F_142 (plane, tmp, &drm_dev->mode_config.plane_list,
head)
F_66 ( V_125 ) ;
return V_15 ;
}
static void F_143 ( struct V_1 * V_1 )
{
struct V_103 * V_104 = & V_1 -> V_104 ;
struct V_247 * V_111 = V_1 -> V_111 ;
struct V_124 * V_125 , * V_258 ;
F_144 ( V_104 -> V_260 ) ;
F_142 (plane, tmp, &drm_dev->mode_config.plane_list,
head)
F_65 ( V_125 ) ;
F_108 ( V_104 ) ;
F_145 ( & V_1 -> V_233 ) ;
}
static int F_146 ( struct V_1 * V_1 )
{
const struct V_183 * V_183 = V_1 -> V_16 ;
const struct V_277 * V_278 = V_183 -> V_278 ;
struct V_279 * V_280 ;
int V_14 , V_15 ;
V_1 -> V_105 = F_147 ( V_1 -> V_71 , L_17 ) ;
if ( F_148 ( V_1 -> V_105 ) ) {
F_44 ( V_1 -> V_71 , L_18 ) ;
return F_149 ( V_1 -> V_105 ) ;
}
V_1 -> V_109 = F_147 ( V_1 -> V_71 , L_19 ) ;
if ( F_148 ( V_1 -> V_109 ) ) {
F_44 ( V_1 -> V_71 , L_20 ) ;
return F_149 ( V_1 -> V_109 ) ;
}
V_1 -> V_107 = F_147 ( V_1 -> V_71 , L_21 ) ;
if ( F_148 ( V_1 -> V_107 ) ) {
F_44 ( V_1 -> V_71 , L_22 ) ;
return F_149 ( V_1 -> V_107 ) ;
}
V_15 = F_43 ( V_1 -> V_71 ) ;
if ( V_15 < 0 ) {
F_44 ( V_1 -> V_71 , L_5 , V_15 ) ;
return V_15 ;
}
V_15 = F_150 ( V_1 -> V_107 ) ;
if ( V_15 < 0 ) {
F_44 ( V_1 -> V_71 , L_23 ) ;
goto V_106;
}
V_15 = F_151 ( V_1 -> V_105 ) ;
if ( V_15 < 0 ) {
F_44 ( V_1 -> V_71 , L_24 ) ;
goto V_281;
}
V_15 = F_151 ( V_1 -> V_109 ) ;
if ( V_15 < 0 ) {
F_44 ( V_1 -> V_71 , L_25 ) ;
goto V_108;
}
V_280 = F_152 ( V_1 -> V_71 , L_26 ) ;
if ( F_148 ( V_280 ) ) {
F_44 ( V_1 -> V_71 , L_27 ) ;
V_15 = F_149 ( V_280 ) ;
goto V_112;
}
F_153 ( V_280 ) ;
F_154 ( 10 , 20 ) ;
F_155 ( V_280 ) ;
memcpy ( V_1 -> V_5 , V_1 -> V_4 , V_1 -> V_113 ) ;
for ( V_14 = 0 ; V_14 < V_183 -> V_282 ; V_14 ++ )
F_1 ( V_1 , V_278 [ V_14 ] . V_2 , V_278 [ V_14 ] . V_283 ) ;
for ( V_14 = 0 ; V_14 < V_183 -> V_118 ; V_14 ++ ) {
const struct V_53 * V_54 = & V_183 -> V_54 [ V_14 ] ;
F_55 ( V_1 , V_54 , V_98 , 0 ) ;
}
F_9 ( V_1 ) ;
V_1 -> V_284 = F_152 ( V_1 -> V_71 , L_28 ) ;
if ( F_148 ( V_1 -> V_284 ) ) {
F_44 ( V_1 -> V_71 , L_29 ) ;
V_15 = F_149 ( V_1 -> V_284 ) ;
goto V_112;
}
F_153 ( V_1 -> V_284 ) ;
F_154 ( 10 , 20 ) ;
F_155 ( V_1 -> V_284 ) ;
F_51 ( V_1 -> V_105 ) ;
F_51 ( V_1 -> V_109 ) ;
V_1 -> V_94 = false ;
F_52 ( V_1 -> V_71 ) ;
return 0 ;
V_112:
F_156 ( V_1 -> V_109 ) ;
V_108:
F_156 ( V_1 -> V_105 ) ;
V_281:
F_157 ( V_1 -> V_107 ) ;
V_106:
F_52 ( V_1 -> V_71 ) ;
return V_15 ;
}
static void F_158 ( struct V_1 * V_1 )
{
const struct V_183 * V_183 = V_1 -> V_16 ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_183 -> V_118 ; V_14 ++ ) {
struct V_119 * V_119 = & V_1 -> V_54 [ V_14 ] ;
const struct V_53 * V_261 = & V_183 -> V_54 [ V_14 ] ;
V_119 -> V_16 = V_261 ;
V_119 -> V_1 = V_1 ;
}
}
int F_159 ( struct V_103 * V_104 , unsigned int V_101 ,
unsigned int V_285 )
{
struct V_1 * V_1 = F_42 ( V_104 ) ;
unsigned long V_286 ;
if ( ! V_104 || ! V_1 -> V_94 )
return - V_244 ;
if ( V_101 > V_104 -> V_42 . V_162 || V_285 <= 0 )
return - V_40 ;
if ( F_37 ( V_1 ) )
return - V_287 ;
F_57 ( & V_1 -> V_254 ) ;
F_39 ( V_1 , V_101 ) ;
V_286 = F_160 ( & V_1 -> V_254 ,
F_161 ( V_285 ) ) ;
F_40 ( V_1 ) ;
if ( V_286 == 0 ) {
F_44 ( V_1 -> V_71 , L_30 ) ;
return - V_288 ;
}
return 0 ;
}
static int F_162 ( struct V_255 * V_71 , struct V_255 * V_289 , void * V_16 )
{
struct V_290 * V_291 = F_163 ( V_71 ) ;
const struct V_183 * V_183 ;
struct V_247 * V_111 = V_16 ;
struct V_1 * V_1 ;
struct V_292 * V_293 ;
T_5 V_294 ;
int V_15 , V_116 ;
V_183 = F_164 ( V_71 ) ;
if ( ! V_183 )
return - V_244 ;
V_294 = sizeof( * V_1 ) + sizeof( * V_1 -> V_54 ) * V_183 -> V_118 ;
V_1 = F_165 ( V_71 , V_294 , V_235 ) ;
if ( ! V_1 )
return - V_295 ;
V_1 -> V_71 = V_71 ;
V_1 -> V_16 = V_183 ;
V_1 -> V_111 = V_111 ;
F_166 ( V_71 , V_1 ) ;
F_158 ( V_1 ) ;
V_293 = F_167 ( V_291 , V_296 , 0 ) ;
V_1 -> V_113 = F_168 ( V_293 ) ;
V_1 -> V_4 = F_169 ( V_71 , V_293 ) ;
if ( F_148 ( V_1 -> V_4 ) )
return F_149 ( V_1 -> V_4 ) ;
V_1 -> V_5 = F_165 ( V_71 , V_1 -> V_113 , V_235 ) ;
if ( ! V_1 -> V_5 )
return - V_295 ;
V_116 = F_170 ( V_291 , 0 ) ;
if ( V_116 < 0 ) {
F_44 ( V_71 , L_31 ) ;
return V_116 ;
}
V_1 -> V_116 = ( unsigned int ) V_116 ;
F_171 ( & V_1 -> V_114 ) ;
F_171 ( & V_1 -> V_95 ) ;
F_172 ( & V_1 -> V_297 ) ;
V_15 = F_173 ( V_71 , V_1 -> V_116 , F_130 ,
V_298 , F_174 ( V_71 ) , V_1 ) ;
if ( V_15 )
return V_15 ;
F_59 ( V_1 -> V_116 ) ;
V_15 = F_133 ( V_1 ) ;
if ( V_15 )
goto V_299;
F_175 ( & V_291 -> V_71 ) ;
V_15 = F_146 ( V_1 ) ;
if ( V_15 < 0 ) {
F_44 ( & V_291 -> V_71 , L_32 , V_15 ) ;
goto V_300;
}
return 0 ;
V_300:
F_176 ( & V_291 -> V_71 ) ;
F_143 ( V_1 ) ;
V_299:
F_49 ( V_1 -> V_116 ) ;
return V_15 ;
}
static void F_177 ( struct V_255 * V_71 , struct V_255 * V_289 , void * V_16 )
{
struct V_1 * V_1 = F_178 ( V_71 ) ;
F_176 ( V_71 ) ;
F_143 ( V_1 ) ;
F_157 ( V_1 -> V_109 ) ;
F_157 ( V_1 -> V_105 ) ;
F_157 ( V_1 -> V_107 ) ;
}
