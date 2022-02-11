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
static inline void F_6 ( struct V_1 * V_1 )
{
F_2 ( 0x01 , V_1 -> V_4 + V_11 ) ;
}
static inline void F_7 ( struct V_1 * V_1 , T_1 V_2 ,
T_1 V_10 , T_1 V_3 )
{
if ( V_10 ) {
T_1 V_12 = V_1 -> V_5 [ V_2 >> 2 ] ;
V_12 = ( V_12 & ~ V_10 ) | V_3 ;
F_2 ( V_12 , V_1 -> V_4 + V_2 ) ;
V_1 -> V_5 [ V_2 >> 2 ] = V_12 ;
}
}
static inline void F_8 ( struct V_1 * V_1 , T_1 V_2 ,
T_1 V_10 , T_1 V_3 )
{
if ( V_10 ) {
T_1 V_12 = V_1 -> V_5 [ V_2 >> 2 ] ;
V_12 = ( V_12 & ~ V_10 ) | V_3 ;
F_9 ( V_12 , V_1 -> V_4 + V_2 ) ;
V_1 -> V_5 [ V_2 >> 2 ] = V_12 ;
}
}
static bool F_10 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_14 :
case V_15 :
case V_16 :
case V_17 :
return true ;
default:
return false ;
}
}
static enum V_18 F_11 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_19 :
case V_20 :
case V_14 :
case V_15 :
return V_21 ;
case V_22 :
case V_16 :
return V_23 ;
case V_24 :
case V_17 :
return V_25 ;
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
case V_30 :
return V_31 ;
default:
F_12 ( L_1 , V_13 ) ;
return - V_32 ;
}
}
static bool F_13 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_26 :
case V_28 :
case V_30 :
return true ;
default:
return false ;
}
}
static bool F_14 ( T_1 V_13 )
{
switch ( V_13 ) {
case V_20 :
case V_15 :
return true ;
default:
return false ;
}
}
static T_2 F_15 ( enum V_33 V_34 , T_1 V_35 ,
T_1 V_36 , bool V_37 ,
int V_38 , int * V_39 )
{
T_2 V_40 = 1 << V_41 ;
if ( V_37 ) {
if ( V_34 == V_42 )
V_40 = F_16 ( V_35 , V_36 ) ;
else if ( V_34 == V_43 )
V_40 = F_17 ( V_35 , V_36 ) ;
} else {
if ( V_34 == V_42 ) {
if ( V_38 == V_44 )
V_40 = F_18 ( V_35 , V_36 ) ;
else
V_40 = F_16 ( V_35 , V_36 ) ;
} else if ( V_34 == V_43 ) {
if ( V_39 ) {
* V_39 = F_19 ( V_35 , V_36 ) ;
V_40 = F_20 ( V_35 , V_36 ,
* V_39 ) ;
} else {
V_40 = F_17 ( V_35 , V_36 ) ;
}
}
}
return V_40 ;
}
static void F_21 ( struct V_1 * V_1 , const struct V_45 * V_46 ,
T_1 V_47 , T_1 V_48 , T_1 V_49 ,
T_1 V_50 , T_1 V_51 )
{
T_2 V_52 , V_53 ;
T_2 V_54 = V_55 ;
T_2 V_56 = V_55 ;
int V_57 = F_22 ( V_51 ) ;
int V_58 = F_23 ( V_51 ) ;
bool V_59 = F_13 ( V_51 ) ;
T_2 V_60 = V_47 / V_57 ;
T_2 V_61 = V_48 / V_58 ;
T_2 V_38 ;
T_2 V_62 ;
T_1 V_40 ;
int V_39 ;
if ( V_49 > 3840 ) {
F_12 ( L_2 ) ;
return;
}
V_52 = F_24 ( V_47 , V_49 ) ;
V_53 = F_24 ( V_48 , V_50 ) ;
if ( V_59 ) {
V_54 = F_24 ( V_60 , V_49 ) ;
V_56 = F_24 ( V_61 , V_50 ) ;
if ( V_54 == V_43 )
V_62 = F_25 ( V_49 , true ) ;
else
V_62 = F_25 ( V_60 , true ) ;
} else {
if ( V_52 == V_43 )
V_62 = F_25 ( V_49 , false ) ;
else
V_62 = F_25 ( V_47 , false ) ;
}
F_26 ( V_1 , V_46 , V_62 , V_62 ) ;
if ( V_62 == V_63 ) {
if ( V_53 != V_55 ) {
F_12 ( L_3 ) ;
return;
}
if ( V_56 != V_55 ) {
F_12 ( L_4 ) ;
return;
}
V_38 = V_44 ;
} else if ( V_62 == V_64 ) {
V_38 = V_44 ;
} else {
V_38 = V_65 ;
}
V_40 = F_15 ( V_52 , V_47 , V_49 ,
true , 0 , NULL ) ;
F_26 ( V_1 , V_46 , V_66 , V_40 ) ;
V_40 = F_15 ( V_53 , V_48 , V_50 ,
false , V_38 , & V_39 ) ;
F_26 ( V_1 , V_46 , V_67 , V_40 ) ;
F_26 ( V_1 , V_46 , V_68 , V_39 == 4 ) ;
F_26 ( V_1 , V_46 , V_69 , V_39 == 2 ) ;
F_26 ( V_1 , V_46 , V_52 , V_52 ) ;
F_26 ( V_1 , V_46 , V_53 , V_53 ) ;
F_26 ( V_1 , V_46 , V_70 , V_71 ) ;
F_26 ( V_1 , V_46 , V_72 , V_71 ) ;
F_26 ( V_1 , V_46 , V_73 , V_38 ) ;
if ( V_59 ) {
V_40 = F_15 ( V_54 , V_60 ,
V_49 , true , 0 , NULL ) ;
F_26 ( V_1 , V_46 , V_74 , V_40 ) ;
V_40 = F_15 ( V_56 , V_61 ,
V_50 , false , V_38 , & V_39 ) ;
F_26 ( V_1 , V_46 , V_75 , V_40 ) ;
F_26 ( V_1 , V_46 , V_76 , V_39 == 4 ) ;
F_26 ( V_1 , V_46 , V_77 , V_39 == 2 ) ;
F_26 ( V_1 , V_46 , V_54 , V_54 ) ;
F_26 ( V_1 , V_46 , V_56 , V_56 ) ;
F_26 ( V_1 , V_46 , V_78 , V_71 ) ;
F_26 ( V_1 , V_46 , V_79 , V_71 ) ;
F_26 ( V_1 , V_46 , V_80 , V_38 ) ;
}
}
static void F_27 ( struct V_1 * V_1 )
{
unsigned long V_81 ;
if ( F_28 ( ! V_1 -> V_82 ) )
return;
F_29 ( & V_1 -> V_83 , V_81 ) ;
F_7 ( V_1 , V_84 , V_85 ,
F_30 ( 1 ) ) ;
F_31 ( & V_1 -> V_83 , V_81 ) ;
}
static void F_32 ( struct V_1 * V_1 )
{
unsigned long V_81 ;
if ( F_28 ( ! V_1 -> V_82 ) )
return;
F_29 ( & V_1 -> V_83 , V_81 ) ;
F_7 ( V_1 , V_84 , V_85 ,
F_30 ( 0 ) ) ;
F_31 ( & V_1 -> V_83 , V_81 ) ;
}
static void F_33 ( struct V_86 * V_87 )
{
struct V_1 * V_1 = F_34 ( V_87 ) ;
int V_88 ;
if ( V_1 -> V_82 )
return;
V_88 = F_35 ( V_1 -> V_89 ) ;
if ( V_88 < 0 ) {
F_36 ( V_1 -> V_89 , L_5 , V_88 ) ;
return;
}
V_88 = F_37 ( V_1 -> V_90 ) ;
if ( V_88 < 0 ) {
F_36 ( V_1 -> V_89 , L_6 , V_88 ) ;
return;
}
V_88 = F_37 ( V_1 -> V_91 ) ;
if ( V_88 < 0 ) {
F_36 ( V_1 -> V_89 , L_7 , V_88 ) ;
goto V_92;
}
V_88 = F_37 ( V_1 -> V_93 ) ;
if ( V_88 < 0 ) {
F_36 ( V_1 -> V_89 , L_8 , V_88 ) ;
goto V_94;
}
V_88 = F_38 ( V_1 -> V_95 , V_1 -> V_89 ) ;
if ( V_88 ) {
F_36 ( V_1 -> V_89 , L_9 , V_88 ) ;
goto V_96;
}
memcpy ( V_1 -> V_4 , V_1 -> V_5 , V_1 -> V_97 ) ;
V_1 -> V_82 = true ;
F_39 ( & V_1 -> V_98 ) ;
F_40 ( V_1 , V_99 , 0 ) ;
F_41 ( & V_1 -> V_98 ) ;
F_42 ( V_1 -> V_100 ) ;
F_43 ( V_1 -> V_95 , V_1 -> V_101 ) ;
return;
V_96:
F_44 ( V_1 -> V_93 ) ;
V_94:
F_44 ( V_1 -> V_91 ) ;
V_92:
F_44 ( V_1 -> V_90 ) ;
}
static void F_45 ( struct V_86 * V_87 )
{
struct V_1 * V_1 = F_34 ( V_87 ) ;
if ( ! V_1 -> V_82 )
return;
F_46 ( V_87 -> V_89 , V_1 -> V_101 ) ;
F_47 ( & V_1 -> V_102 ) ;
F_27 ( V_1 ) ;
F_39 ( & V_1 -> V_98 ) ;
F_40 ( V_1 , V_99 , 1 ) ;
F_41 ( & V_1 -> V_98 ) ;
F_48 ( & V_1 -> V_102 ) ;
F_32 ( V_1 ) ;
F_49 ( V_1 -> V_100 ) ;
V_1 -> V_82 = false ;
F_50 ( V_1 -> V_95 , V_1 -> V_89 ) ;
F_44 ( V_1 -> V_91 ) ;
F_44 ( V_1 -> V_93 ) ;
F_44 ( V_1 -> V_90 ) ;
F_51 ( V_1 -> V_89 ) ;
}
static struct V_103 * F_52 ( struct V_104 * V_104 )
{
struct V_105 * V_106 ;
struct V_105 * V_107 = V_104 -> V_107 ;
if ( F_53 ( & V_104 -> V_108 ) )
return V_107 ? V_107 -> V_109 : NULL ;
V_106 = F_54 ( & V_104 -> V_108 , struct V_105 , V_110 ) ;
return V_106 ? V_106 -> V_109 : NULL ;
}
static int F_55 ( struct V_104 * V_104 ,
struct V_103 * V_109 , T_3 V_111 ,
struct V_112 * V_113 )
{
struct V_105 * V_114 ;
V_114 = F_56 ( sizeof( * V_114 ) , V_115 ) ;
if ( ! V_114 )
return - V_116 ;
V_114 -> V_109 = V_109 ;
V_114 -> V_111 = V_111 ;
V_114 -> V_113 = V_113 ;
F_57 ( & V_114 -> V_110 , & V_104 -> V_108 ) ;
return 0 ;
}
static int F_58 ( struct V_117 * V_118 ,
struct V_86 * V_87 ,
struct V_103 * V_109 , int V_119 ,
int V_120 , unsigned int V_121 ,
unsigned int V_122 , T_1 V_123 ,
T_1 V_124 , T_1 V_47 ,
T_1 V_48 ,
struct V_112 * V_113 )
{
struct V_104 * V_104 = F_59 ( V_118 ) ;
const struct V_45 * V_46 = V_104 -> V_125 ;
struct V_1 * V_1 = F_34 ( V_87 ) ;
struct V_126 * V_127 ;
struct V_128 * V_129 ;
struct V_126 * V_130 ;
struct V_128 * V_131 ;
unsigned long V_2 ;
unsigned int V_132 ;
unsigned int V_133 ;
unsigned int V_134 ;
unsigned int V_135 ;
unsigned int V_136 ;
unsigned int V_137 = 0 ;
T_3 V_111 ;
T_3 V_138 = 0 ;
enum V_18 V_13 ;
T_1 V_40 ;
bool V_139 ;
bool V_140 ;
bool V_59 ;
bool V_141 ;
int V_88 ;
struct V_142 V_143 = {
. V_144 = V_119 ,
. y1 = V_120 ,
. V_145 = V_119 + V_121 ,
. V_146 = V_120 + V_122 ,
} ;
struct V_142 V_35 = {
. V_144 = V_123 ,
. y1 = V_124 ,
. V_145 = V_123 + V_47 ,
. V_146 = V_124 + V_48 ,
} ;
const struct V_142 V_147 = {
. V_145 = V_87 -> V_34 . V_148 ,
. V_146 = V_87 -> V_34 . V_149 ,
} ;
bool V_150 = V_118 -> type != V_151 ;
int V_152 = V_46 -> V_153 -> V_154 ? F_60 ( 1 , 8 ) :
V_155 ;
int V_156 = V_46 -> V_153 -> V_154 ? F_60 ( 8 , 1 ) :
V_155 ;
V_88 = F_61 ( V_118 , V_87 , V_109 ,
& V_35 , & V_143 , & V_147 ,
V_152 ,
V_156 ,
V_150 , false , & V_141 ) ;
if ( V_88 )
return V_88 ;
if ( ! V_141 )
return 0 ;
V_139 = F_14 ( V_109 -> V_51 ) ;
V_140 = F_10 ( V_109 -> V_51 ) ;
V_59 = F_13 ( V_109 -> V_51 ) ;
V_13 = F_11 ( V_109 -> V_51 ) ;
if ( V_13 < 0 )
return V_13 ;
V_127 = F_62 ( V_109 , 0 ) ;
if ( ! V_127 ) {
F_12 ( L_10 ) ;
return - V_32 ;
}
V_129 = F_63 ( V_127 ) ;
if ( V_59 ) {
V_40 = ( V_35 . V_144 >> 16 ) % 2 ;
V_35 . V_144 += V_40 << 16 ;
V_35 . V_145 += V_40 << 16 ;
}
V_132 = ( V_35 . V_145 - V_35 . V_144 ) >> 16 ;
V_133 = ( V_35 . V_146 - V_35 . y1 ) >> 16 ;
V_134 = V_143 . V_144 + V_87 -> V_34 . V_157 - V_87 -> V_34 . V_158 ;
V_135 = V_143 . y1 + V_87 -> V_34 . V_159 - V_87 -> V_34 . V_160 ;
V_2 = ( V_35 . V_144 >> 16 ) * F_64 ( V_109 -> V_51 , 0 ) ;
V_2 += ( V_35 . y1 >> 16 ) * V_109 -> V_161 [ 0 ] ;
V_111 = V_129 -> V_162 + V_2 + V_109 -> V_163 [ 0 ] ;
V_136 = V_109 -> V_161 [ 0 ] >> 2 ;
if ( V_59 ) {
int V_57 = F_22 ( V_109 -> V_51 ) ;
int V_58 = F_23 ( V_109 -> V_51 ) ;
int V_164 = F_64 ( V_109 -> V_51 , 1 ) ;
V_130 = F_62 ( V_109 , 1 ) ;
if ( ! V_130 ) {
F_12 ( L_11 ) ;
return - V_32 ;
}
V_131 = F_63 ( V_130 ) ;
V_137 = V_109 -> V_161 [ 1 ] >> 2 ;
V_2 = ( V_35 . V_144 >> 16 ) * V_164 / V_57 ;
V_2 += ( V_35 . y1 >> 16 ) * V_109 -> V_161 [ 1 ] / V_58 ;
V_138 = V_131 -> V_162 + V_2 + V_109 -> V_163 [ 1 ] ;
}
F_65 ( & V_1 -> V_165 ) ;
if ( V_109 != F_52 ( V_104 ) ) {
V_88 = F_66 ( V_118 -> V_89 , V_1 -> V_101 ) ;
if ( V_88 ) {
F_12 ( L_12 , V_88 ) ;
F_67 ( & V_1 -> V_165 ) ;
return V_88 ;
}
F_68 ( V_109 ) ;
V_88 = F_55 ( V_104 , V_109 , V_111 , V_113 ) ;
if ( V_88 ) {
F_69 ( V_118 -> V_89 , V_1 -> V_101 ) ;
F_67 ( & V_1 -> V_165 ) ;
return V_88 ;
}
V_1 -> V_166 = true ;
}
F_67 ( & V_1 -> V_165 ) ;
F_39 ( & V_1 -> V_98 ) ;
F_70 ( V_1 , V_46 , V_13 , V_13 ) ;
F_70 ( V_1 , V_46 , V_167 , V_136 ) ;
F_70 ( V_1 , V_46 , V_111 , V_111 ) ;
if ( V_59 ) {
F_70 ( V_1 , V_46 , V_168 , V_137 ) ;
F_70 ( V_1 , V_46 , V_138 , V_138 ) ;
}
if ( V_46 -> V_153 -> V_154 )
F_21 ( V_1 , V_46 , V_132 , V_133 ,
V_143 . V_145 - V_143 . V_144 , V_143 . V_146 - V_143 . y1 ,
V_109 -> V_51 ) ;
V_40 = ( V_133 - 1 ) << 16 ;
V_40 |= ( V_132 - 1 ) & 0xffff ;
F_70 ( V_1 , V_46 , V_169 , V_40 ) ;
V_40 = ( V_143 . V_146 - V_143 . y1 - 1 ) << 16 ;
V_40 |= ( V_143 . V_145 - V_143 . V_144 - 1 ) & 0xffff ;
F_70 ( V_1 , V_46 , V_170 , V_40 ) ;
V_40 = V_135 << 16 ;
V_40 |= V_134 & 0xffff ;
F_70 ( V_1 , V_46 , V_171 , V_40 ) ;
F_70 ( V_1 , V_46 , V_140 , V_140 ) ;
if ( V_139 ) {
F_70 ( V_1 , V_46 , V_172 ,
F_71 ( V_173 ) ) ;
V_40 = F_72 ( 1 ) | F_73 ( V_174 ) |
F_74 ( V_175 ) |
F_75 ( V_176 ) |
F_76 ( V_177 ) |
F_77 ( V_178 ) ;
F_70 ( V_1 , V_46 , V_179 , V_40 ) ;
} else {
F_70 ( V_1 , V_46 , V_179 , F_72 ( 0 ) ) ;
}
F_70 ( V_1 , V_46 , V_180 , 1 ) ;
F_6 ( V_1 ) ;
F_41 ( & V_1 -> V_98 ) ;
return 0 ;
}
static int F_78 ( struct V_117 * V_118 , struct V_86 * V_87 ,
struct V_103 * V_109 , int V_119 , int V_120 ,
unsigned int V_121 , unsigned int V_122 ,
T_1 V_123 , T_1 V_124 , T_1 V_47 ,
T_1 V_48 )
{
return F_58 ( V_118 , V_87 , V_109 , V_119 , V_120 , V_121 ,
V_122 , V_123 , V_124 , V_47 , V_48 ,
NULL ) ;
}
static int F_79 ( struct V_86 * V_87 ,
struct V_112 * V_113 )
{
unsigned int V_121 , V_122 ;
V_121 = V_87 -> V_181 -> V_109 -> V_182 - V_87 -> V_183 ;
V_122 = V_87 -> V_181 -> V_109 -> V_184 - V_87 -> V_185 ;
return F_58 ( V_87 -> V_181 , V_87 , V_87 -> V_181 -> V_109 ,
0 , 0 , V_121 , V_122 , V_87 -> V_183 << 16 ,
V_87 -> V_185 << 16 , V_121 << 16 ,
V_122 << 16 , V_113 ) ;
}
static int F_80 ( struct V_117 * V_118 )
{
struct V_104 * V_104 = F_59 ( V_118 ) ;
const struct V_45 * V_46 = V_104 -> V_125 ;
struct V_1 * V_1 ;
int V_88 ;
if ( ! V_118 -> V_87 )
return 0 ;
V_1 = F_34 ( V_118 -> V_87 ) ;
V_88 = F_66 ( V_118 -> V_89 , V_1 -> V_101 ) ;
if ( V_88 ) {
F_12 ( L_12 , V_88 ) ;
return V_88 ;
}
F_65 ( & V_1 -> V_165 ) ;
V_88 = F_55 ( V_104 , NULL , 0 , NULL ) ;
if ( V_88 ) {
F_69 ( V_118 -> V_89 , V_1 -> V_101 ) ;
F_67 ( & V_1 -> V_165 ) ;
return V_88 ;
}
V_1 -> V_166 = true ;
F_67 ( & V_1 -> V_165 ) ;
F_39 ( & V_1 -> V_98 ) ;
F_70 ( V_1 , V_46 , V_180 , 0 ) ;
F_6 ( V_1 ) ;
F_41 ( & V_1 -> V_98 ) ;
return 0 ;
}
static void F_81 ( struct V_117 * V_118 )
{
F_80 ( V_118 ) ;
F_82 ( V_118 ) ;
}
int F_83 ( struct V_86 * V_87 ,
int V_186 ,
int V_187 )
{
struct V_1 * V_1 = F_34 ( V_87 ) ;
V_1 -> V_186 = V_186 ;
V_1 -> V_188 = V_187 ;
return 0 ;
}
static int F_84 ( struct V_86 * V_87 )
{
struct V_1 * V_1 = F_34 ( V_87 ) ;
unsigned long V_81 ;
if ( ! V_1 -> V_82 )
return - V_189 ;
F_29 ( & V_1 -> V_83 , V_81 ) ;
F_7 ( V_1 , V_84 , V_190 , F_85 ( 1 ) ) ;
F_31 ( & V_1 -> V_83 , V_81 ) ;
return 0 ;
}
static void F_86 ( struct V_86 * V_87 )
{
struct V_1 * V_1 = F_34 ( V_87 ) ;
unsigned long V_81 ;
if ( ! V_1 -> V_82 )
return;
F_29 ( & V_1 -> V_83 , V_81 ) ;
F_7 ( V_1 , V_84 , V_190 , F_85 ( 0 ) ) ;
F_31 ( & V_1 -> V_83 , V_81 ) ;
}
static void F_87 ( struct V_86 * V_87 , int V_34 )
{
F_88 ( L_13 , V_87 -> V_6 . V_191 , V_34 ) ;
switch ( V_34 ) {
case V_192 :
F_33 ( V_87 ) ;
break;
case V_193 :
case V_194 :
case V_195 :
F_45 ( V_87 ) ;
break;
default:
F_88 ( L_14 , V_34 ) ;
break;
}
}
static void F_89 ( struct V_86 * V_87 )
{
F_87 ( V_87 , V_192 ) ;
}
static bool F_90 ( struct V_86 * V_87 ,
const struct V_196 * V_34 ,
struct V_196 * V_197 )
{
if ( V_197 -> V_157 == 0 || V_197 -> V_159 == 0 )
return false ;
return true ;
}
static int F_91 ( struct V_86 * V_87 , int V_183 , int V_185 ,
struct V_103 * V_198 )
{
int V_88 ;
V_87 -> V_183 = V_183 ;
V_87 -> V_185 = V_185 ;
V_88 = F_79 ( V_87 , NULL ) ;
if ( V_88 < 0 ) {
F_12 ( L_15 ) ;
return V_88 ;
}
return 0 ;
}
static int F_92 ( struct V_86 * V_87 ,
struct V_196 * V_34 ,
struct V_196 * V_197 ,
int V_183 , int V_185 , struct V_103 * V_109 )
{
struct V_1 * V_1 = F_34 ( V_87 ) ;
T_4 V_199 = V_197 -> V_200 - V_197 -> V_158 ;
T_4 V_148 = V_197 -> V_148 ;
T_4 V_157 = V_197 -> V_157 ;
T_4 V_201 = V_197 -> V_157 - V_197 -> V_158 ;
T_4 V_202 = V_201 + V_148 ;
T_4 V_149 = V_197 -> V_149 ;
T_4 V_159 = V_197 -> V_159 ;
T_4 V_203 = V_197 -> V_204 - V_197 -> V_160 ;
T_4 V_205 = V_197 -> V_159 - V_197 -> V_160 ;
T_4 V_206 = V_205 + V_149 ;
int V_88 , V_207 ;
T_1 V_40 ;
F_44 ( V_1 -> V_91 ) ;
switch ( V_1 -> V_186 ) {
case V_208 :
F_40 ( V_1 , V_209 , 1 ) ;
break;
case V_210 :
F_40 ( V_1 , V_211 , 1 ) ;
break;
case V_212 :
F_40 ( V_1 , V_213 , 1 ) ;
break;
default:
F_12 ( L_16 ,
V_1 -> V_186 ) ;
V_88 = - V_32 ;
goto V_214;
} ;
F_40 ( V_1 , V_187 , V_1 -> V_188 ) ;
V_40 = 0x8 ;
V_40 |= ( V_197 -> V_81 & V_215 ) ? 0 : 1 ;
V_40 |= ( V_197 -> V_81 & V_216 ) ? 0 : ( 1 << 1 ) ;
F_40 ( V_1 , V_217 , V_40 ) ;
F_40 ( V_1 , V_218 , ( V_157 << 16 ) | V_199 ) ;
V_40 = V_201 << 16 ;
V_40 |= V_202 ;
F_40 ( V_1 , V_219 , V_40 ) ;
F_40 ( V_1 , V_220 , V_40 ) ;
F_40 ( V_1 , V_221 , ( V_159 << 16 ) | V_203 ) ;
V_40 = V_205 << 16 ;
V_40 |= V_206 ;
F_40 ( V_1 , V_222 , V_40 ) ;
F_40 ( V_1 , V_223 , V_40 ) ;
V_88 = F_91 ( V_87 , V_183 , V_185 , V_109 ) ;
if ( V_88 )
goto V_214;
F_93 ( V_1 -> V_224 ) ;
F_94 ( 10 , 20 ) ;
F_95 ( V_1 -> V_224 ) ;
F_96 ( V_1 -> V_91 , V_197 -> clock * 1000 ) ;
V_214:
V_207 = F_37 ( V_1 -> V_91 ) ;
if ( V_207 < 0 ) {
F_36 ( V_1 -> V_89 , L_7 , V_207 ) ;
return V_207 ;
}
return V_88 ;
}
static void F_97 ( struct V_86 * V_87 )
{
}
static int F_98 ( struct V_86 * V_87 ,
struct V_103 * V_109 ,
struct V_112 * V_113 ,
T_1 V_225 )
{
struct V_1 * V_1 = F_34 ( V_87 ) ;
struct V_103 * V_198 = V_87 -> V_181 -> V_109 ;
int V_88 ;
if ( ! V_1 -> V_82 ) {
F_99 ( L_17 ) ;
return 0 ;
}
V_87 -> V_181 -> V_109 = V_109 ;
V_88 = F_79 ( V_87 , V_113 ) ;
if ( V_88 )
V_87 -> V_181 -> V_109 = V_198 ;
return V_88 ;
}
static void F_100 ( struct V_104 * V_104 ,
struct V_105 * V_114 )
{
struct V_1 * V_1 = V_104 -> V_1 ;
struct V_86 * V_87 = & V_1 -> V_87 ;
struct V_226 * V_227 = V_87 -> V_89 ;
unsigned long V_81 ;
if ( V_114 -> V_113 ) {
F_29 ( & V_227 -> V_228 , V_81 ) ;
F_101 ( V_87 , V_114 -> V_113 ) ;
F_31 ( & V_227 -> V_228 , V_81 ) ;
}
F_102 ( & V_114 -> V_110 ) ;
F_69 ( V_87 -> V_89 , V_1 -> V_101 ) ;
}
static void F_103 ( struct V_86 * V_87 )
{
F_104 ( V_87 ) ;
}
static bool F_105 ( struct V_104 * V_104 ,
struct V_105 * V_114 )
{
bool V_107 = false ;
if ( V_114 -> V_109 ) {
T_3 V_111 ;
V_111 = F_106 ( V_104 -> V_1 , V_104 -> V_125 ) ;
V_107 = ( V_111 == V_114 -> V_111 ) ;
} else {
bool V_229 ;
V_229 = F_107 ( V_104 -> V_1 , V_104 -> V_125 , V_180 ) ;
V_107 = ( V_229 == 0 ) ;
}
return V_107 ;
}
static void F_108 ( struct V_105 * V_114 )
{
struct V_103 * V_109 = V_114 -> V_109 ;
if ( V_109 )
F_109 ( V_109 ) ;
F_110 ( V_114 ) ;
}
static void F_111 ( struct V_104 * V_104 )
{
struct V_105 * V_114 , * V_230 , * V_231 = NULL ;
F_112 (state, &vop_win->pending, head)
if ( F_105 ( V_104 , V_114 ) ) {
V_231 = V_114 ;
break;
}
if ( ! V_231 )
return;
F_113 (state, n, &vop_win->pending, head) {
if ( V_114 == V_231 )
break;
F_100 ( V_104 , V_114 ) ;
F_108 ( V_114 ) ;
}
F_100 ( V_104 , V_231 ) ;
if ( V_104 -> V_107 )
F_108 ( V_104 -> V_107 ) ;
V_104 -> V_107 = V_231 ;
}
static bool F_114 ( struct V_104 * V_104 )
{
return ! F_53 ( & V_104 -> V_108 ) ;
}
static T_5 F_115 ( int V_100 , void * V_125 )
{
struct V_1 * V_1 = V_125 ;
const struct V_232 * V_232 = V_1 -> V_125 ;
unsigned int V_233 ;
F_65 ( & V_1 -> V_165 ) ;
if ( ! V_1 -> V_166 )
goto V_234;
V_1 -> V_166 = false ;
for ( V_233 = 0 ; V_233 < V_232 -> V_235 ; V_233 ++ ) {
struct V_104 * V_104 = & V_1 -> V_46 [ V_233 ] ;
F_111 ( V_104 ) ;
if ( F_114 ( V_104 ) )
V_1 -> V_166 = true ;
}
V_234:
F_67 ( & V_1 -> V_165 ) ;
return V_236 ;
}
static T_5 F_116 ( int V_100 , void * V_125 )
{
struct V_1 * V_1 = V_125 ;
T_1 V_237 , V_238 ;
unsigned long V_81 ;
int V_88 = V_239 ;
F_29 ( & V_1 -> V_83 , V_81 ) ;
V_237 = F_3 ( V_1 , V_84 ) ;
V_238 = V_237 & V_240 ;
if ( V_238 )
F_1 ( V_1 , V_84 ,
V_237 | ( V_238 << V_241 ) ) ;
F_31 ( & V_1 -> V_83 , V_81 ) ;
if ( ! V_238 )
return V_239 ;
if ( V_238 & V_242 ) {
F_117 ( & V_1 -> V_102 ) ;
V_238 &= ~ V_242 ;
V_88 = V_236 ;
}
if ( V_238 & V_243 ) {
F_118 ( V_1 -> V_95 , V_1 -> V_101 ) ;
V_238 &= ~ V_243 ;
V_88 = ( V_1 -> V_166 ) ? V_244 : V_236 ;
}
if ( V_238 )
F_12 ( L_18 , V_238 ) ;
return V_88 ;
}
static int F_119 ( struct V_1 * V_1 )
{
const struct V_232 * V_232 = V_1 -> V_125 ;
struct V_245 * V_89 = V_1 -> V_89 ;
struct V_226 * V_95 = V_1 -> V_95 ;
struct V_117 * V_181 = NULL , * V_246 = NULL , * V_118 ;
struct V_86 * V_87 = & V_1 -> V_87 ;
struct V_247 * V_248 ;
int V_88 ;
int V_233 ;
for ( V_233 = 0 ; V_233 < V_232 -> V_235 ; V_233 ++ ) {
struct V_104 * V_104 = & V_1 -> V_46 [ V_233 ] ;
const struct V_45 * V_249 = V_104 -> V_125 ;
if ( V_249 -> type != V_151 &&
V_249 -> type != V_250 )
continue;
V_88 = F_120 ( V_1 -> V_95 , & V_104 -> V_6 ,
0 , & V_251 ,
V_249 -> V_153 -> V_252 ,
V_249 -> V_153 -> V_253 ,
V_249 -> type ) ;
if ( V_88 ) {
F_12 ( L_19 ) ;
goto V_254;
}
V_118 = & V_104 -> V_6 ;
if ( V_118 -> type == V_151 )
V_181 = V_118 ;
else if ( V_118 -> type == V_250 )
V_246 = V_118 ;
}
V_88 = F_121 ( V_95 , V_87 , V_181 , V_246 ,
& V_255 ) ;
if ( V_88 )
return V_88 ;
F_122 ( V_87 , & V_256 ) ;
for ( V_233 = 0 ; V_233 < V_232 -> V_235 ; V_233 ++ ) {
struct V_104 * V_104 = & V_1 -> V_46 [ V_233 ] ;
const struct V_45 * V_249 = V_104 -> V_125 ;
unsigned long V_257 = 1 << F_123 ( V_87 ) ;
if ( V_249 -> type != V_258 )
continue;
V_88 = F_120 ( V_1 -> V_95 , & V_104 -> V_6 ,
V_257 ,
& V_251 ,
V_249 -> V_153 -> V_252 ,
V_249 -> V_153 -> V_253 ,
V_249 -> type ) ;
if ( V_88 ) {
F_12 ( L_20 ) ;
goto V_259;
}
}
V_248 = F_124 ( V_89 -> V_260 , L_21 ) ;
if ( ! V_248 ) {
F_12 ( L_22 ,
V_89 -> V_260 -> V_261 ) ;
goto V_259;
}
F_125 ( & V_1 -> V_102 ) ;
V_87 -> V_248 = V_248 ;
V_1 -> V_101 = F_123 ( V_87 ) ;
F_126 ( V_95 , & V_262 , V_1 -> V_101 ) ;
return 0 ;
V_259:
F_104 ( V_87 ) ;
V_254:
F_112 (plane, &drm_dev->mode_config.plane_list, head)
F_82 ( V_118 ) ;
return V_88 ;
}
static void F_127 ( struct V_1 * V_1 )
{
struct V_86 * V_87 = & V_1 -> V_87 ;
F_128 ( V_1 -> V_95 , V_1 -> V_101 ) ;
F_129 ( V_87 -> V_248 ) ;
F_104 ( V_87 ) ;
}
static int F_130 ( struct V_1 * V_1 )
{
const struct V_232 * V_232 = V_1 -> V_125 ;
const struct V_263 * V_264 = V_232 -> V_264 ;
struct V_265 * V_266 ;
int V_233 , V_88 ;
V_1 -> V_90 = F_131 ( V_1 -> V_89 , L_23 ) ;
if ( F_132 ( V_1 -> V_90 ) ) {
F_36 ( V_1 -> V_89 , L_24 ) ;
return F_133 ( V_1 -> V_90 ) ;
}
V_1 -> V_93 = F_131 ( V_1 -> V_89 , L_25 ) ;
if ( F_132 ( V_1 -> V_93 ) ) {
F_36 ( V_1 -> V_89 , L_26 ) ;
return F_133 ( V_1 -> V_93 ) ;
}
V_1 -> V_91 = F_131 ( V_1 -> V_89 , L_27 ) ;
if ( F_132 ( V_1 -> V_91 ) ) {
F_36 ( V_1 -> V_89 , L_28 ) ;
return F_133 ( V_1 -> V_91 ) ;
}
V_88 = F_134 ( V_1 -> V_91 ) ;
if ( V_88 < 0 ) {
F_36 ( V_1 -> V_89 , L_29 ) ;
return V_88 ;
}
V_88 = F_135 ( V_1 -> V_90 ) ;
if ( V_88 < 0 ) {
F_36 ( V_1 -> V_89 , L_30 ) ;
goto V_267;
}
V_88 = F_135 ( V_1 -> V_93 ) ;
if ( V_88 < 0 ) {
F_36 ( V_1 -> V_89 , L_31 ) ;
goto V_92;
}
V_266 = F_136 ( V_1 -> V_89 , L_32 ) ;
if ( F_132 ( V_266 ) ) {
F_36 ( V_1 -> V_89 , L_33 ) ;
V_88 = F_133 ( V_266 ) ;
goto V_96;
}
F_93 ( V_266 ) ;
F_94 ( 10 , 20 ) ;
F_95 ( V_266 ) ;
memcpy ( V_1 -> V_5 , V_1 -> V_4 , V_1 -> V_97 ) ;
for ( V_233 = 0 ; V_233 < V_232 -> V_268 ; V_233 ++ )
F_1 ( V_1 , V_264 [ V_233 ] . V_2 , V_264 [ V_233 ] . V_269 ) ;
for ( V_233 = 0 ; V_233 < V_232 -> V_235 ; V_233 ++ ) {
const struct V_45 * V_46 = & V_232 -> V_46 [ V_233 ] ;
F_70 ( V_1 , V_46 , V_180 , 0 ) ;
}
F_6 ( V_1 ) ;
V_1 -> V_224 = F_136 ( V_1 -> V_89 , L_34 ) ;
if ( F_132 ( V_1 -> V_224 ) ) {
F_36 ( V_1 -> V_89 , L_35 ) ;
V_88 = F_133 ( V_1 -> V_224 ) ;
goto V_96;
}
F_93 ( V_1 -> V_224 ) ;
F_94 ( 10 , 20 ) ;
F_95 ( V_1 -> V_224 ) ;
F_44 ( V_1 -> V_90 ) ;
F_44 ( V_1 -> V_93 ) ;
V_1 -> V_82 = false ;
return 0 ;
V_96:
F_137 ( V_1 -> V_93 ) ;
V_92:
F_137 ( V_1 -> V_90 ) ;
V_267:
F_138 ( V_1 -> V_91 ) ;
return V_88 ;
}
static void F_139 ( struct V_1 * V_1 )
{
const struct V_232 * V_232 = V_1 -> V_125 ;
unsigned int V_233 ;
for ( V_233 = 0 ; V_233 < V_232 -> V_235 ; V_233 ++ ) {
struct V_104 * V_104 = & V_1 -> V_46 [ V_233 ] ;
const struct V_45 * V_249 = & V_232 -> V_46 [ V_233 ] ;
V_104 -> V_125 = V_249 ;
V_104 -> V_1 = V_1 ;
F_140 ( & V_104 -> V_108 ) ;
}
}
static int F_141 ( struct V_245 * V_89 , struct V_245 * V_270 , void * V_125 )
{
struct V_271 * V_272 = F_142 ( V_89 ) ;
const struct V_273 * V_274 ;
const struct V_232 * V_232 ;
struct V_226 * V_95 = V_125 ;
struct V_1 * V_1 ;
struct V_275 * V_276 ;
T_6 V_277 ;
int V_88 , V_100 ;
V_274 = F_143 ( V_278 , V_89 ) ;
V_232 = V_274 -> V_125 ;
if ( ! V_232 )
return - V_279 ;
V_277 = sizeof( * V_1 ) + sizeof( * V_1 -> V_46 ) * V_232 -> V_235 ;
V_1 = F_144 ( V_89 , V_277 , V_115 ) ;
if ( ! V_1 )
return - V_116 ;
V_1 -> V_89 = V_89 ;
V_1 -> V_125 = V_232 ;
V_1 -> V_95 = V_95 ;
F_145 ( V_89 , V_1 ) ;
F_139 ( V_1 ) ;
V_276 = F_146 ( V_272 , V_280 , 0 ) ;
V_1 -> V_97 = F_147 ( V_276 ) ;
V_1 -> V_4 = F_148 ( V_89 , V_276 ) ;
if ( F_132 ( V_1 -> V_4 ) )
return F_133 ( V_1 -> V_4 ) ;
V_1 -> V_5 = F_144 ( V_89 , V_1 -> V_97 , V_115 ) ;
if ( ! V_1 -> V_5 )
return - V_116 ;
V_88 = F_130 ( V_1 ) ;
if ( V_88 < 0 ) {
F_36 ( & V_272 -> V_89 , L_36 , V_88 ) ;
return V_88 ;
}
V_100 = F_149 ( V_272 , 0 ) ;
if ( V_100 < 0 ) {
F_36 ( V_89 , L_37 ) ;
return V_100 ;
}
V_1 -> V_100 = ( unsigned int ) V_100 ;
F_150 ( & V_1 -> V_98 ) ;
F_150 ( & V_1 -> V_83 ) ;
F_151 ( & V_1 -> V_165 ) ;
V_88 = F_152 ( V_89 , V_1 -> V_100 , F_116 , F_115 ,
V_281 , F_153 ( V_89 ) , V_1 ) ;
if ( V_88 )
return V_88 ;
F_49 ( V_1 -> V_100 ) ;
V_88 = F_119 ( V_1 ) ;
if ( V_88 )
return V_88 ;
F_154 ( & V_272 -> V_89 ) ;
return 0 ;
}
static void F_155 ( struct V_245 * V_89 , struct V_245 * V_270 , void * V_125 )
{
struct V_1 * V_1 = F_156 ( V_89 ) ;
F_157 ( V_89 ) ;
F_127 ( V_1 ) ;
}
static int F_158 ( struct V_271 * V_272 )
{
struct V_245 * V_89 = & V_272 -> V_89 ;
if ( ! V_89 -> V_260 ) {
F_36 ( V_89 , L_38 ) ;
return - V_279 ;
}
return F_159 ( V_89 , & V_282 ) ;
}
static int F_160 ( struct V_271 * V_272 )
{
F_161 ( & V_272 -> V_89 , & V_282 ) ;
return 0 ;
}
