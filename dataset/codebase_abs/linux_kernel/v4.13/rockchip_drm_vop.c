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
static void F_39 ( struct V_1 * V_1 )
{
unsigned long V_93 ;
if ( F_32 ( ! V_1 -> V_94 ) )
return;
F_33 ( & V_1 -> V_95 , V_93 ) ;
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
static int F_41 ( struct V_101 * V_102 )
{
struct V_1 * V_1 = F_42 ( V_102 ) ;
int V_15 , V_14 ;
V_15 = F_43 ( V_1 -> V_71 ) ;
if ( V_15 < 0 ) {
F_44 ( V_1 -> V_71 , L_5 , V_15 ) ;
return V_15 ;
}
V_15 = F_45 ( V_1 -> V_103 ) ;
if ( F_32 ( V_15 < 0 ) )
goto V_104;
V_15 = F_45 ( V_1 -> V_105 ) ;
if ( F_32 ( V_15 < 0 ) )
goto V_106;
V_15 = F_45 ( V_1 -> V_107 ) ;
if ( F_32 ( V_15 < 0 ) )
goto V_108;
V_15 = F_46 ( V_1 -> V_109 , V_1 -> V_71 ) ;
if ( V_15 ) {
F_44 ( V_1 -> V_71 , L_6 , V_15 ) ;
goto V_110;
}
memcpy ( V_1 -> V_4 , V_1 -> V_5 , V_1 -> V_111 ) ;
for ( V_14 = 0 ; V_14 < V_1 -> V_16 -> V_112 ; V_14 ++ ) {
struct V_113 * V_113 = & V_1 -> V_54 [ V_14 ] ;
const struct V_53 * V_54 = V_113 -> V_16 ;
F_47 ( & V_1 -> V_114 ) ;
F_48 ( V_1 , V_54 , V_98 , 0 ) ;
F_49 ( & V_1 -> V_114 ) ;
}
F_9 ( V_1 ) ;
V_1 -> V_94 = true ;
F_47 ( & V_1 -> V_114 ) ;
F_10 ( V_1 , V_115 , 0 ) ;
F_49 ( & V_1 -> V_114 ) ;
F_50 ( V_1 -> V_116 ) ;
F_51 ( V_102 ) ;
return 0 ;
V_110:
F_52 ( V_1 -> V_107 ) ;
V_108:
F_52 ( V_1 -> V_105 ) ;
V_106:
F_52 ( V_1 -> V_103 ) ;
V_104:
F_53 ( V_1 -> V_71 ) ;
return V_15 ;
}
static void F_54 ( struct V_101 * V_102 )
{
struct V_1 * V_1 = F_42 ( V_102 ) ;
F_32 ( V_1 -> V_117 ) ;
F_55 ( & V_1 -> V_102 ) ;
F_56 ( V_102 ) ;
F_57 ( & V_1 -> V_118 ) ;
F_31 ( V_1 ) ;
F_47 ( & V_1 -> V_114 ) ;
F_10 ( V_1 , V_115 , 1 ) ;
F_49 ( & V_1 -> V_114 ) ;
F_58 ( & V_1 -> V_118 ) ;
F_36 ( V_1 ) ;
F_59 ( V_1 -> V_116 ) ;
V_1 -> V_94 = false ;
F_60 ( V_1 -> V_109 , V_1 -> V_71 ) ;
F_52 ( V_1 -> V_105 ) ;
F_52 ( V_1 -> V_107 ) ;
F_52 ( V_1 -> V_103 ) ;
F_61 ( V_1 -> V_71 ) ;
if ( V_102 -> V_119 -> V_117 && ! V_102 -> V_119 -> V_120 ) {
F_62 ( & V_102 -> V_71 -> V_121 ) ;
F_63 ( V_102 , V_102 -> V_119 -> V_117 ) ;
F_64 ( & V_102 -> V_71 -> V_121 ) ;
V_102 -> V_119 -> V_117 = NULL ;
}
}
static void F_65 ( struct V_122 * V_123 )
{
F_66 ( V_123 ) ;
}
static int F_67 ( struct V_122 * V_123 ,
struct V_124 * V_119 )
{
struct V_101 * V_102 = V_119 -> V_102 ;
struct V_125 * V_126 ;
struct V_127 * V_128 = V_119 -> V_128 ;
struct V_113 * V_113 = F_68 ( V_123 ) ;
const struct V_53 * V_54 = V_113 -> V_16 ;
int V_15 ;
struct V_129 V_130 ;
int V_131 = V_54 -> V_72 -> V_73 ? F_69 ( 1 , 8 ) :
V_132 ;
int V_133 = V_54 -> V_72 -> V_73 ? F_69 ( 8 , 1 ) :
V_132 ;
if ( ! V_102 || ! V_128 )
return 0 ;
V_126 = F_70 ( V_119 -> V_119 , V_102 ) ;
if ( F_32 ( ! V_126 ) )
return - V_40 ;
V_130 . V_134 = 0 ;
V_130 . y1 = 0 ;
V_130 . V_135 = V_126 -> V_136 . V_137 ;
V_130 . V_138 = V_126 -> V_136 . V_139 ;
V_15 = F_71 ( V_119 , & V_130 ,
V_131 , V_133 ,
true , true ) ;
if ( V_15 )
return V_15 ;
if ( ! V_119 -> V_140 )
return 0 ;
V_15 = F_12 ( V_128 -> V_21 -> V_21 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( F_14 ( V_128 -> V_21 -> V_21 ) && ( ( V_119 -> V_43 . V_134 >> 16 ) % 2 ) ) {
F_13 ( L_7 ) ;
return - V_40 ;
}
return 0 ;
}
static void F_72 ( struct V_122 * V_123 ,
struct V_124 * V_141 )
{
struct V_113 * V_113 = F_68 ( V_123 ) ;
const struct V_53 * V_54 = V_113 -> V_16 ;
struct V_1 * V_1 = F_42 ( V_141 -> V_102 ) ;
if ( ! V_141 -> V_102 )
return;
F_47 ( & V_1 -> V_114 ) ;
F_48 ( V_1 , V_54 , V_98 , 0 ) ;
F_49 ( & V_1 -> V_114 ) ;
}
static void F_73 ( struct V_122 * V_123 ,
struct V_124 * V_141 )
{
struct V_124 * V_119 = V_123 -> V_119 ;
struct V_101 * V_102 = V_119 -> V_102 ;
struct V_113 * V_113 = F_68 ( V_123 ) ;
const struct V_53 * V_54 = V_113 -> V_16 ;
struct V_1 * V_1 = F_42 ( V_119 -> V_102 ) ;
struct V_127 * V_128 = V_119 -> V_128 ;
unsigned int V_142 , V_143 ;
unsigned int V_144 , V_145 ;
T_1 V_146 , V_147 , V_148 ;
struct V_129 * V_43 = & V_119 -> V_43 ;
struct V_129 * V_149 = & V_119 -> V_44 ;
struct V_150 * V_151 , * V_152 ;
struct V_153 * V_154 , * V_155 ;
unsigned long V_2 ;
T_3 V_156 ;
T_1 V_48 ;
bool V_157 ;
int V_21 ;
if ( F_32 ( ! V_102 ) )
return;
if ( F_32 ( ! V_1 -> V_94 ) )
return;
if ( ! V_119 -> V_140 ) {
F_72 ( V_123 , V_141 ) ;
return;
}
V_151 = F_74 ( V_128 , 0 ) ;
V_154 = F_75 ( V_151 ) ;
V_142 = F_76 ( V_43 ) >> 16 ;
V_143 = F_77 ( V_43 ) >> 16 ;
V_146 = ( V_143 - 1 ) << 16 | ( ( V_142 - 1 ) & 0xffff ) ;
V_147 = ( F_77 ( V_149 ) - 1 ) << 16 ;
V_147 |= ( F_76 ( V_149 ) - 1 ) & 0xffff ;
V_144 = V_149 -> V_134 + V_102 -> V_42 . V_158 - V_102 -> V_42 . V_159 ;
V_145 = V_149 -> y1 + V_102 -> V_42 . V_160 - V_102 -> V_42 . V_161 ;
V_148 = V_145 << 16 | ( V_144 & 0xffff ) ;
V_2 = ( V_43 -> V_134 >> 16 ) * V_128 -> V_21 -> V_162 [ 0 ] ;
V_2 += ( V_43 -> y1 >> 16 ) * V_128 -> V_163 [ 0 ] ;
V_156 = V_154 -> V_156 + V_2 + V_128 -> V_164 [ 0 ] ;
V_21 = F_12 ( V_128 -> V_21 -> V_21 ) ;
F_47 ( & V_1 -> V_114 ) ;
F_48 ( V_1 , V_54 , V_21 , V_21 ) ;
F_48 ( V_1 , V_54 , V_165 , F_78 ( V_128 -> V_163 [ 0 ] , 4 ) ) ;
F_48 ( V_1 , V_54 , V_166 , V_156 ) ;
if ( F_14 ( V_128 -> V_21 -> V_21 ) ) {
int V_65 = F_23 ( V_128 -> V_21 -> V_21 ) ;
int V_66 = F_24 ( V_128 -> V_21 -> V_21 ) ;
int V_167 = V_128 -> V_21 -> V_162 [ 1 ] ;
V_152 = F_74 ( V_128 , 1 ) ;
V_155 = F_75 ( V_152 ) ;
V_2 = ( V_43 -> V_134 >> 16 ) * V_167 / V_65 ;
V_2 += ( V_43 -> y1 >> 16 ) * V_128 -> V_163 [ 1 ] / V_66 ;
V_156 = V_155 -> V_156 + V_2 + V_128 -> V_164 [ 1 ] ;
F_48 ( V_1 , V_54 , V_168 , F_78 ( V_128 -> V_163 [ 1 ] , 4 ) ) ;
F_48 ( V_1 , V_54 , V_169 , V_156 ) ;
}
if ( V_54 -> V_72 -> V_73 )
F_22 ( V_1 , V_54 , V_142 , V_143 ,
F_76 ( V_149 ) , F_77 ( V_149 ) ,
V_128 -> V_21 -> V_21 ) ;
F_48 ( V_1 , V_54 , V_146 , V_146 ) ;
F_48 ( V_1 , V_54 , V_147 , V_147 ) ;
F_48 ( V_1 , V_54 , V_148 , V_148 ) ;
V_157 = F_11 ( V_128 -> V_21 -> V_21 ) ;
F_48 ( V_1 , V_54 , V_157 , V_157 ) ;
if ( F_15 ( V_128 -> V_21 -> V_21 ) ) {
F_48 ( V_1 , V_54 , V_170 ,
F_79 ( V_171 ) ) ;
V_48 = F_80 ( 1 ) | F_81 ( V_172 ) |
F_82 ( V_173 ) |
F_83 ( V_174 ) |
F_84 ( V_175 ) |
F_85 ( V_176 ) ;
F_48 ( V_1 , V_54 , V_177 , V_48 ) ;
} else {
F_48 ( V_1 , V_54 , V_177 , F_80 ( 0 ) ) ;
}
F_48 ( V_1 , V_54 , V_98 , 1 ) ;
F_49 ( & V_1 -> V_114 ) ;
}
static int F_86 ( struct V_101 * V_102 )
{
struct V_1 * V_1 = F_42 ( V_102 ) ;
unsigned long V_93 ;
if ( F_32 ( ! V_1 -> V_94 ) )
return - V_178 ;
F_33 ( & V_1 -> V_95 , V_93 ) ;
F_34 ( V_1 , V_96 , V_179 , 1 ) ;
F_34 ( V_1 , V_98 , V_179 , 1 ) ;
F_35 ( & V_1 -> V_95 , V_93 ) ;
return 0 ;
}
static void F_87 ( struct V_101 * V_102 )
{
struct V_1 * V_1 = F_42 ( V_102 ) ;
unsigned long V_93 ;
if ( F_32 ( ! V_1 -> V_94 ) )
return;
F_33 ( & V_1 -> V_95 , V_93 ) ;
F_34 ( V_1 , V_98 , V_179 , 0 ) ;
F_35 ( & V_1 -> V_95 , V_93 ) ;
}
static bool F_88 ( struct V_101 * V_102 ,
const struct V_180 * V_42 ,
struct V_180 * V_136 )
{
struct V_1 * V_1 = F_42 ( V_102 ) ;
V_136 -> clock =
F_89 ( V_1 -> V_105 , V_42 -> clock * 1000 ) / 1000 ;
return true ;
}
static void F_90 ( struct V_101 * V_102 )
{
struct V_1 * V_1 = F_42 ( V_102 ) ;
const struct V_181 * V_181 = V_1 -> V_16 ;
struct V_182 * V_183 = F_91 ( V_102 -> V_119 ) ;
struct V_180 * V_136 = & V_102 -> V_119 -> V_136 ;
T_4 V_184 = V_136 -> V_185 - V_136 -> V_159 ;
T_4 V_137 = V_136 -> V_137 ;
T_4 V_158 = V_136 -> V_158 ;
T_4 V_186 = V_136 -> V_158 - V_136 -> V_159 ;
T_4 V_187 = V_186 + V_137 ;
T_4 V_139 = V_136 -> V_139 ;
T_4 V_160 = V_136 -> V_160 ;
T_4 V_188 = V_136 -> V_189 - V_136 -> V_161 ;
T_4 V_190 = V_136 -> V_160 - V_136 -> V_161 ;
T_4 V_191 = V_190 + V_139 ;
T_1 V_192 , V_48 ;
int V_15 ;
F_32 ( V_1 -> V_117 ) ;
V_15 = F_41 ( V_102 ) ;
if ( V_15 ) {
F_25 ( V_1 -> V_71 , L_8 , V_15 ) ;
return;
}
if ( F_92 ( V_1 -> V_105 ) ) {
F_57 ( & V_1 -> V_118 ) ;
F_31 ( V_1 ) ;
F_47 ( & V_1 -> V_114 ) ;
F_10 ( V_1 , V_115 , 1 ) ;
F_49 ( & V_1 -> V_114 ) ;
F_58 ( & V_1 -> V_118 ) ;
F_36 ( V_1 ) ;
}
V_192 = F_93 ( V_193 ) ;
V_192 |= ( V_136 -> V_93 & V_194 ) ?
F_93 ( V_195 ) : 0 ;
V_192 |= ( V_136 -> V_93 & V_196 ) ?
F_93 ( V_197 ) : 0 ;
F_10 ( V_1 , V_192 , V_192 ) ;
switch ( V_183 -> V_198 ) {
case V_199 :
F_10 ( V_1 , V_200 , 1 ) ;
F_10 ( V_1 , V_201 , V_192 ) ;
break;
case V_202 :
F_10 ( V_1 , V_203 , V_192 ) ;
F_10 ( V_1 , V_204 , 1 ) ;
break;
case V_205 :
F_10 ( V_1 , V_206 , V_192 ) ;
F_10 ( V_1 , V_207 , 1 ) ;
break;
case V_208 :
F_10 ( V_1 , V_209 , V_192 ) ;
F_10 ( V_1 , V_210 , 1 ) ;
break;
case V_211 :
V_192 &= ~ F_93 ( V_193 ) ;
F_10 ( V_1 , V_212 , V_192 ) ;
F_10 ( V_1 , V_213 , 1 ) ;
break;
default:
F_25 ( V_1 -> V_71 , L_9 ,
V_183 -> V_198 ) ;
}
if ( V_183 -> V_214 == V_215 &&
! ( V_181 -> V_216 & V_217 ) )
V_183 -> V_214 = V_218 ;
F_10 ( V_1 , V_219 , V_183 -> V_214 ) ;
F_10 ( V_1 , V_220 , ( V_158 << 16 ) | V_184 ) ;
V_48 = V_186 << 16 ;
V_48 |= V_187 ;
F_10 ( V_1 , V_221 , V_48 ) ;
F_10 ( V_1 , V_222 , V_48 ) ;
F_10 ( V_1 , V_223 , ( V_160 << 16 ) | V_188 ) ;
V_48 = V_190 << 16 ;
V_48 |= V_191 ;
F_10 ( V_1 , V_224 , V_48 ) ;
F_10 ( V_1 , V_225 , V_48 ) ;
F_10 ( V_1 , V_226 [ 0 ] , V_191 ) ;
F_94 ( V_1 -> V_105 , V_136 -> clock * 1000 ) ;
F_10 ( V_1 , V_115 , 0 ) ;
F_95 ( & V_1 -> V_102 ) ;
}
static bool F_96 ( struct V_1 * V_1 )
{
return F_38 ( V_1 , V_227 , V_179 ) ;
}
static void F_97 ( struct V_1 * V_1 )
{
bool V_228 ;
int V_15 ;
V_15 = F_98 ( F_96 , V_1 , V_228 ,
! V_228 , 0 , 10 * 1000 ) ;
if ( V_15 )
F_25 ( V_1 -> V_71 , L_10 ) ;
F_99 ( V_1 -> V_116 ) ;
}
static void F_100 ( struct V_101 * V_102 ,
struct V_125 * V_229 )
{
struct V_230 * V_141 = V_229 -> V_119 ;
struct V_124 * V_231 ;
struct V_1 * V_1 = F_42 ( V_102 ) ;
struct V_122 * V_123 ;
int V_14 ;
if ( F_32 ( ! V_1 -> V_94 ) )
return;
F_47 ( & V_1 -> V_114 ) ;
F_9 ( V_1 ) ;
F_49 ( & V_1 -> V_114 ) ;
F_97 ( V_1 ) ;
F_62 ( & V_102 -> V_71 -> V_121 ) ;
if ( V_102 -> V_119 -> V_117 ) {
F_32 ( F_101 ( V_102 ) != 0 ) ;
F_32 ( V_1 -> V_117 ) ;
V_1 -> V_117 = V_102 -> V_119 -> V_117 ;
V_102 -> V_119 -> V_117 = NULL ;
}
F_64 ( & V_102 -> V_71 -> V_121 ) ;
F_102 (old_state, plane, old_plane_state, i) {
if ( ! V_231 -> V_128 )
continue;
if ( V_231 -> V_128 == V_123 -> V_119 -> V_128 )
continue;
F_103 ( V_231 -> V_128 ) ;
F_104 ( & V_1 -> V_232 , V_231 -> V_128 ) ;
F_105 ( V_233 , & V_1 -> V_228 ) ;
F_32 ( F_101 ( V_102 ) != 0 ) ;
}
}
static void F_106 ( struct V_101 * V_102 ,
struct V_125 * V_229 )
{
F_107 ( V_102 ) ;
}
static void F_108 ( struct V_101 * V_102 )
{
F_109 ( V_102 ) ;
}
static void F_110 ( struct V_101 * V_102 )
{
if ( V_102 -> V_119 )
F_111 ( V_102 -> V_119 ) ;
F_112 ( V_102 -> V_119 ) ;
V_102 -> V_119 = F_113 ( sizeof( struct V_182 ) , V_234 ) ;
if ( V_102 -> V_119 )
V_102 -> V_119 -> V_102 = V_102 ;
}
static struct V_125 * F_114 ( struct V_101 * V_102 )
{
struct V_182 * V_235 ;
V_235 = F_113 ( sizeof( * V_235 ) , V_234 ) ;
if ( ! V_235 )
return NULL ;
F_115 ( V_102 , & V_235 -> V_6 ) ;
return & V_235 -> V_6 ;
}
static void F_116 ( struct V_101 * V_102 ,
struct V_125 * V_119 )
{
struct V_182 * V_183 = F_91 ( V_119 ) ;
F_111 ( & V_183 -> V_6 ) ;
F_112 ( V_183 ) ;
}
static struct V_236 * F_117 ( struct V_1 * V_1 )
{
struct V_236 * V_237 ;
struct V_238 V_239 ;
F_118 ( V_1 -> V_109 , & V_239 ) ;
F_119 (connector, &conn_iter) {
if ( V_237 -> V_240 == V_202 ) {
F_120 ( & V_239 ) ;
return V_237 ;
}
}
F_120 ( & V_239 ) ;
return NULL ;
}
static int F_121 ( struct V_101 * V_102 ,
const char * V_241 , T_5 * V_242 )
{
struct V_1 * V_1 = F_42 ( V_102 ) ;
struct V_236 * V_237 ;
int V_15 ;
V_237 = F_117 ( V_1 ) ;
if ( ! V_237 )
return - V_40 ;
* V_242 = 3 ;
if ( V_241 && strcmp ( V_241 , L_11 ) == 0 )
V_15 = F_122 ( V_237 ) ;
else if ( ! V_241 )
V_15 = F_123 ( V_237 ) ;
else
V_15 = - V_40 ;
return V_15 ;
}
static int F_121 ( struct V_101 * V_102 ,
const char * V_241 , T_5 * V_242 )
{
return - V_243 ;
}
static void F_124 ( struct V_244 * V_245 , void * V_48 )
{
struct V_1 * V_1 = F_125 ( V_245 , struct V_1 , V_232 ) ;
struct V_127 * V_128 = V_48 ;
F_126 ( & V_1 -> V_102 ) ;
F_127 ( V_128 ) ;
}
static void F_128 ( struct V_1 * V_1 )
{
struct V_246 * V_247 = V_1 -> V_109 ;
struct V_101 * V_102 = & V_1 -> V_102 ;
unsigned long V_93 ;
F_33 ( & V_247 -> V_121 , V_93 ) ;
if ( V_1 -> V_117 ) {
F_63 ( V_102 , V_1 -> V_117 ) ;
F_126 ( V_102 ) ;
V_1 -> V_117 = NULL ;
}
F_35 ( & V_247 -> V_121 , V_93 ) ;
if ( F_129 ( V_233 , & V_1 -> V_228 ) )
F_130 ( & V_1 -> V_232 , V_248 ) ;
}
static T_6 F_131 ( int V_116 , void * V_16 )
{
struct V_1 * V_1 = V_16 ;
struct V_101 * V_102 = & V_1 -> V_102 ;
T_1 V_249 ;
unsigned long V_93 ;
int V_15 = V_250 ;
F_33 ( & V_1 -> V_95 , V_93 ) ;
V_249 = F_38 ( V_1 , V_227 , V_251 ) ;
if ( V_249 )
F_34 ( V_1 , V_96 , V_249 , 1 ) ;
F_35 ( & V_1 -> V_95 , V_93 ) ;
if ( ! V_249 )
return V_250 ;
if ( V_249 & V_97 ) {
F_132 ( & V_1 -> V_118 ) ;
V_249 &= ~ V_97 ;
V_15 = V_252 ;
}
if ( V_249 & V_100 ) {
F_132 ( & V_1 -> V_253 ) ;
V_249 &= ~ V_100 ;
V_15 = V_252 ;
}
if ( V_249 & V_179 ) {
F_133 ( V_102 ) ;
F_128 ( V_1 ) ;
V_249 &= ~ V_179 ;
V_15 = V_252 ;
}
if ( V_249 )
F_25 ( V_1 -> V_71 , L_12 ,
V_249 ) ;
return V_15 ;
}
static int F_134 ( struct V_1 * V_1 )
{
const struct V_181 * V_181 = V_1 -> V_16 ;
struct V_254 * V_71 = V_1 -> V_71 ;
struct V_246 * V_109 = V_1 -> V_109 ;
struct V_122 * V_255 = NULL , * V_256 = NULL , * V_123 , * V_257 ;
struct V_101 * V_102 = & V_1 -> V_102 ;
struct V_258 * V_259 ;
int V_15 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_181 -> V_112 ; V_14 ++ ) {
struct V_113 * V_113 = & V_1 -> V_54 [ V_14 ] ;
const struct V_53 * V_260 = V_113 -> V_16 ;
if ( V_260 -> type != V_261 &&
V_260 -> type != V_262 )
continue;
V_15 = F_135 ( V_1 -> V_109 , & V_113 -> V_6 ,
0 , & V_263 ,
V_260 -> V_72 -> V_264 ,
V_260 -> V_72 -> V_265 ,
V_260 -> type , NULL ) ;
if ( V_15 ) {
F_25 ( V_1 -> V_71 , L_13 ,
V_15 ) ;
goto V_266;
}
V_123 = & V_113 -> V_6 ;
F_136 ( V_123 , & V_267 ) ;
if ( V_123 -> type == V_261 )
V_255 = V_123 ;
else if ( V_123 -> type == V_262 )
V_256 = V_123 ;
}
V_15 = F_137 ( V_109 , V_102 , V_255 , V_256 ,
& V_268 , NULL ) ;
if ( V_15 )
goto V_266;
F_138 ( V_102 , & V_269 ) ;
for ( V_14 = 0 ; V_14 < V_181 -> V_112 ; V_14 ++ ) {
struct V_113 * V_113 = & V_1 -> V_54 [ V_14 ] ;
const struct V_53 * V_260 = V_113 -> V_16 ;
unsigned long V_270 = 1 << F_139 ( V_102 ) ;
if ( V_260 -> type != V_271 )
continue;
V_15 = F_135 ( V_1 -> V_109 , & V_113 -> V_6 ,
V_270 ,
& V_263 ,
V_260 -> V_72 -> V_264 ,
V_260 -> V_72 -> V_265 ,
V_260 -> type , NULL ) ;
if ( V_15 ) {
F_25 ( V_1 -> V_71 , L_14 ,
V_15 ) ;
goto V_272;
}
F_136 ( & V_113 -> V_6 , & V_267 ) ;
}
V_259 = F_140 ( V_71 -> V_273 , L_15 ) ;
if ( ! V_259 ) {
F_25 ( V_1 -> V_71 , L_16 ,
V_71 -> V_273 -> V_274 ) ;
V_15 = - V_275 ;
goto V_272;
}
F_141 ( & V_1 -> V_232 , L_17 ,
F_124 ) ;
F_142 ( & V_1 -> V_118 ) ;
F_142 ( & V_1 -> V_253 ) ;
V_102 -> V_259 = V_259 ;
return 0 ;
V_272:
F_109 ( V_102 ) ;
V_266:
F_143 (plane, tmp, &drm_dev->mode_config.plane_list,
head)
F_66 ( V_123 ) ;
return V_15 ;
}
static void F_144 ( struct V_1 * V_1 )
{
struct V_101 * V_102 = & V_1 -> V_102 ;
struct V_246 * V_109 = V_1 -> V_109 ;
struct V_122 * V_123 , * V_257 ;
F_145 ( V_102 -> V_259 ) ;
F_143 (plane, tmp, &drm_dev->mode_config.plane_list,
head)
F_65 ( V_123 ) ;
F_109 ( V_102 ) ;
F_146 ( & V_1 -> V_232 ) ;
}
static int F_147 ( struct V_1 * V_1 )
{
const struct V_181 * V_181 = V_1 -> V_16 ;
const struct V_276 * V_277 = V_181 -> V_277 ;
struct V_278 * V_279 ;
int V_14 , V_15 ;
V_1 -> V_103 = F_148 ( V_1 -> V_71 , L_18 ) ;
if ( F_149 ( V_1 -> V_103 ) ) {
F_44 ( V_1 -> V_71 , L_19 ) ;
return F_150 ( V_1 -> V_103 ) ;
}
V_1 -> V_107 = F_148 ( V_1 -> V_71 , L_20 ) ;
if ( F_149 ( V_1 -> V_107 ) ) {
F_44 ( V_1 -> V_71 , L_21 ) ;
return F_150 ( V_1 -> V_107 ) ;
}
V_1 -> V_105 = F_148 ( V_1 -> V_71 , L_22 ) ;
if ( F_149 ( V_1 -> V_105 ) ) {
F_44 ( V_1 -> V_71 , L_23 ) ;
return F_150 ( V_1 -> V_105 ) ;
}
V_15 = F_43 ( V_1 -> V_71 ) ;
if ( V_15 < 0 ) {
F_44 ( V_1 -> V_71 , L_5 , V_15 ) ;
return V_15 ;
}
V_15 = F_151 ( V_1 -> V_105 ) ;
if ( V_15 < 0 ) {
F_44 ( V_1 -> V_71 , L_24 ) ;
goto V_104;
}
V_15 = F_152 ( V_1 -> V_103 ) ;
if ( V_15 < 0 ) {
F_44 ( V_1 -> V_71 , L_25 ) ;
goto V_280;
}
V_15 = F_152 ( V_1 -> V_107 ) ;
if ( V_15 < 0 ) {
F_44 ( V_1 -> V_71 , L_26 ) ;
goto V_106;
}
V_279 = F_153 ( V_1 -> V_71 , L_27 ) ;
if ( F_149 ( V_279 ) ) {
F_44 ( V_1 -> V_71 , L_28 ) ;
V_15 = F_150 ( V_279 ) ;
goto V_110;
}
F_154 ( V_279 ) ;
F_155 ( 10 , 20 ) ;
F_156 ( V_279 ) ;
memcpy ( V_1 -> V_5 , V_1 -> V_4 , V_1 -> V_111 ) ;
for ( V_14 = 0 ; V_14 < V_181 -> V_281 ; V_14 ++ )
F_1 ( V_1 , V_277 [ V_14 ] . V_2 , V_277 [ V_14 ] . V_282 ) ;
for ( V_14 = 0 ; V_14 < V_181 -> V_112 ; V_14 ++ ) {
const struct V_53 * V_54 = & V_181 -> V_54 [ V_14 ] ;
F_48 ( V_1 , V_54 , V_98 , 0 ) ;
}
F_9 ( V_1 ) ;
V_1 -> V_283 = F_153 ( V_1 -> V_71 , L_29 ) ;
if ( F_149 ( V_1 -> V_283 ) ) {
F_44 ( V_1 -> V_71 , L_30 ) ;
V_15 = F_150 ( V_1 -> V_283 ) ;
goto V_110;
}
F_154 ( V_1 -> V_283 ) ;
F_155 ( 10 , 20 ) ;
F_156 ( V_1 -> V_283 ) ;
F_52 ( V_1 -> V_103 ) ;
F_52 ( V_1 -> V_107 ) ;
V_1 -> V_94 = false ;
F_53 ( V_1 -> V_71 ) ;
return 0 ;
V_110:
F_157 ( V_1 -> V_107 ) ;
V_106:
F_157 ( V_1 -> V_103 ) ;
V_280:
F_158 ( V_1 -> V_105 ) ;
V_104:
F_53 ( V_1 -> V_71 ) ;
return V_15 ;
}
static void F_159 ( struct V_1 * V_1 )
{
const struct V_181 * V_181 = V_1 -> V_16 ;
unsigned int V_14 ;
for ( V_14 = 0 ; V_14 < V_181 -> V_112 ; V_14 ++ ) {
struct V_113 * V_113 = & V_1 -> V_54 [ V_14 ] ;
const struct V_53 * V_260 = & V_181 -> V_54 [ V_14 ] ;
V_113 -> V_16 = V_260 ;
V_113 -> V_1 = V_1 ;
}
}
int F_160 ( struct V_101 * V_102 , unsigned int V_284 )
{
struct V_1 * V_1 = F_42 ( V_102 ) ;
unsigned long V_285 ;
if ( ! V_102 || ! V_1 -> V_94 )
return - V_243 ;
if ( V_284 <= 0 )
return - V_40 ;
if ( F_37 ( V_1 ) )
return - V_286 ;
F_57 ( & V_1 -> V_253 ) ;
F_39 ( V_1 ) ;
V_285 = F_161 ( & V_1 -> V_253 ,
F_162 ( V_284 ) ) ;
F_40 ( V_1 ) ;
if ( V_285 == 0 ) {
F_44 ( V_1 -> V_71 , L_31 ) ;
return - V_287 ;
}
return 0 ;
}
static int F_163 ( struct V_254 * V_71 , struct V_254 * V_288 , void * V_16 )
{
struct V_289 * V_290 = F_164 ( V_71 ) ;
const struct V_181 * V_181 ;
struct V_246 * V_109 = V_16 ;
struct V_1 * V_1 ;
struct V_291 * V_292 ;
T_5 V_293 ;
int V_15 , V_116 ;
V_181 = F_165 ( V_71 ) ;
if ( ! V_181 )
return - V_243 ;
V_293 = sizeof( * V_1 ) + sizeof( * V_1 -> V_54 ) * V_181 -> V_112 ;
V_1 = F_166 ( V_71 , V_293 , V_234 ) ;
if ( ! V_1 )
return - V_294 ;
V_1 -> V_71 = V_71 ;
V_1 -> V_16 = V_181 ;
V_1 -> V_109 = V_109 ;
F_167 ( V_71 , V_1 ) ;
F_159 ( V_1 ) ;
V_292 = F_168 ( V_290 , V_295 , 0 ) ;
V_1 -> V_111 = F_169 ( V_292 ) ;
V_1 -> V_4 = F_170 ( V_71 , V_292 ) ;
if ( F_149 ( V_1 -> V_4 ) )
return F_150 ( V_1 -> V_4 ) ;
V_1 -> V_5 = F_166 ( V_71 , V_1 -> V_111 , V_234 ) ;
if ( ! V_1 -> V_5 )
return - V_294 ;
V_116 = F_171 ( V_290 , 0 ) ;
if ( V_116 < 0 ) {
F_44 ( V_71 , L_32 ) ;
return V_116 ;
}
V_1 -> V_116 = ( unsigned int ) V_116 ;
F_172 ( & V_1 -> V_114 ) ;
F_172 ( & V_1 -> V_95 ) ;
F_173 ( & V_1 -> V_296 ) ;
V_15 = F_174 ( V_71 , V_1 -> V_116 , F_131 ,
V_297 , F_175 ( V_71 ) , V_1 ) ;
if ( V_15 )
return V_15 ;
F_59 ( V_1 -> V_116 ) ;
V_15 = F_134 ( V_1 ) ;
if ( V_15 )
goto V_298;
F_176 ( & V_290 -> V_71 ) ;
V_15 = F_147 ( V_1 ) ;
if ( V_15 < 0 ) {
F_44 ( & V_290 -> V_71 , L_33 , V_15 ) ;
goto V_299;
}
return 0 ;
V_299:
F_177 ( & V_290 -> V_71 ) ;
F_144 ( V_1 ) ;
V_298:
F_50 ( V_1 -> V_116 ) ;
return V_15 ;
}
static void F_178 ( struct V_254 * V_71 , struct V_254 * V_288 , void * V_16 )
{
struct V_1 * V_1 = F_179 ( V_71 ) ;
F_177 ( V_71 ) ;
F_144 ( V_1 ) ;
F_158 ( V_1 -> V_107 ) ;
F_158 ( V_1 -> V_103 ) ;
F_158 ( V_1 -> V_105 ) ;
}
