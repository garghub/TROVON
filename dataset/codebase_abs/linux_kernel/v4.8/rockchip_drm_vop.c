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
T_1 V_10 , T_1 V_3 )
{
if ( V_10 ) {
T_1 V_11 = V_1 -> V_5 [ V_2 >> 2 ] ;
V_11 = ( V_11 & ~ V_10 ) | V_3 ;
F_2 ( V_11 , V_1 -> V_4 + V_2 ) ;
V_1 -> V_5 [ V_2 >> 2 ] = V_11 ;
}
}
static inline void F_7 ( struct V_1 * V_1 , T_1 V_2 ,
T_1 V_10 , T_1 V_3 )
{
if ( V_10 ) {
T_1 V_11 = V_1 -> V_5 [ V_2 >> 2 ] ;
V_11 = ( V_11 & ~ V_10 ) | V_3 ;
F_8 ( V_11 , V_1 -> V_4 + V_2 ) ;
V_1 -> V_5 [ V_2 >> 2 ] = V_11 ;
}
}
static inline T_1 F_9 ( struct V_1 * V_1 ,
const struct V_7 * V_8 , int type )
{
T_1 V_12 , V_13 = 0 ;
T_1 V_4 = F_5 ( V_1 , 0 , V_8 ) ;
for ( V_12 = 0 ; V_12 < V_1 -> V_14 -> V_15 -> V_16 ; V_12 ++ ) {
if ( ( type & V_1 -> V_14 -> V_15 -> V_17 [ V_12 ] ) && ( V_4 & 1 << V_12 ) )
V_13 |= V_1 -> V_14 -> V_15 -> V_17 [ V_12 ] ;
}
return V_13 ;
}
static inline void F_10 ( struct V_1 * V_1 )
{
F_11 ( V_1 , V_18 , 1 ) ;
}
static bool F_12 ( T_1 V_19 )
{
switch ( V_19 ) {
case V_20 :
case V_21 :
case V_22 :
case V_23 :
return true ;
default:
return false ;
}
}
static enum V_24 F_13 ( T_1 V_19 )
{
switch ( V_19 ) {
case V_25 :
case V_26 :
case V_20 :
case V_21 :
return V_27 ;
case V_28 :
case V_22 :
return V_29 ;
case V_30 :
case V_23 :
return V_31 ;
case V_32 :
return V_33 ;
case V_34 :
return V_35 ;
case V_36 :
return V_37 ;
default:
F_14 ( L_1 , V_19 ) ;
return - V_38 ;
}
}
static bool F_15 ( T_1 V_19 )
{
switch ( V_19 ) {
case V_32 :
case V_34 :
case V_36 :
return true ;
default:
return false ;
}
}
static bool F_16 ( T_1 V_19 )
{
switch ( V_19 ) {
case V_26 :
case V_21 :
return true ;
default:
return false ;
}
}
static T_2 F_17 ( enum V_39 V_40 , T_1 V_41 ,
T_1 V_42 , bool V_43 ,
int V_44 , int * V_45 )
{
T_2 V_46 = 1 << V_47 ;
if ( V_43 ) {
if ( V_40 == V_48 )
V_46 = F_18 ( V_41 , V_42 ) ;
else if ( V_40 == V_49 )
V_46 = F_19 ( V_41 , V_42 ) ;
} else {
if ( V_40 == V_48 ) {
if ( V_44 == V_50 )
V_46 = F_20 ( V_41 , V_42 ) ;
else
V_46 = F_18 ( V_41 , V_42 ) ;
} else if ( V_40 == V_49 ) {
if ( V_45 ) {
* V_45 = F_21 ( V_41 , V_42 ) ;
V_46 = F_22 ( V_41 , V_42 ,
* V_45 ) ;
} else {
V_46 = F_19 ( V_41 , V_42 ) ;
}
}
}
return V_46 ;
}
static void F_23 ( struct V_1 * V_1 , const struct V_51 * V_52 ,
T_1 V_53 , T_1 V_54 , T_1 V_55 ,
T_1 V_56 , T_1 V_57 )
{
T_2 V_58 , V_59 ;
T_2 V_60 = V_61 ;
T_2 V_62 = V_61 ;
int V_63 = F_24 ( V_57 ) ;
int V_64 = F_25 ( V_57 ) ;
bool V_65 = F_15 ( V_57 ) ;
T_2 V_66 = V_53 / V_63 ;
T_2 V_67 = V_54 / V_64 ;
T_2 V_44 ;
T_2 V_68 ;
T_1 V_46 ;
int V_45 = 0 ;
if ( V_55 > 3840 ) {
F_14 ( L_2 ) ;
return;
}
if ( ! V_52 -> V_69 -> V_70 -> V_71 ) {
F_26 ( V_1 , V_52 , V_72 ,
F_27 ( V_53 , V_55 ) ) ;
F_26 ( V_1 , V_52 , V_73 ,
F_27 ( V_54 , V_56 ) ) ;
if ( V_65 ) {
F_26 ( V_1 , V_52 , V_74 ,
F_27 ( V_66 , V_55 ) ) ;
F_26 ( V_1 , V_52 , V_75 ,
F_27 ( V_67 , V_56 ) ) ;
}
return;
}
V_58 = F_28 ( V_53 , V_55 ) ;
V_59 = F_28 ( V_54 , V_56 ) ;
if ( V_65 ) {
V_60 = F_28 ( V_66 , V_55 ) ;
V_62 = F_28 ( V_67 , V_56 ) ;
if ( V_60 == V_49 )
V_68 = F_29 ( V_55 , true ) ;
else
V_68 = F_29 ( V_66 , true ) ;
} else {
if ( V_58 == V_49 )
V_68 = F_29 ( V_55 , false ) ;
else
V_68 = F_29 ( V_53 , false ) ;
}
F_30 ( V_1 , V_52 , V_68 , V_68 ) ;
if ( V_68 == V_76 ) {
if ( V_59 != V_61 ) {
F_14 ( L_3 ) ;
return;
}
if ( V_62 != V_61 ) {
F_14 ( L_4 ) ;
return;
}
V_44 = V_50 ;
} else if ( V_68 == V_77 ) {
V_44 = V_50 ;
} else {
V_44 = V_78 ;
}
V_46 = F_17 ( V_58 , V_53 , V_55 ,
true , 0 , NULL ) ;
F_26 ( V_1 , V_52 , V_72 , V_46 ) ;
V_46 = F_17 ( V_59 , V_54 , V_56 ,
false , V_44 , & V_45 ) ;
F_26 ( V_1 , V_52 , V_73 , V_46 ) ;
F_30 ( V_1 , V_52 , V_79 , V_45 == 4 ) ;
F_30 ( V_1 , V_52 , V_80 , V_45 == 2 ) ;
F_30 ( V_1 , V_52 , V_58 , V_58 ) ;
F_30 ( V_1 , V_52 , V_59 , V_59 ) ;
F_30 ( V_1 , V_52 , V_81 , V_82 ) ;
F_30 ( V_1 , V_52 , V_83 , V_82 ) ;
F_30 ( V_1 , V_52 , V_84 , V_44 ) ;
if ( V_65 ) {
V_46 = F_17 ( V_60 , V_66 ,
V_55 , true , 0 , NULL ) ;
F_26 ( V_1 , V_52 , V_74 , V_46 ) ;
V_46 = F_17 ( V_62 , V_67 ,
V_56 , false , V_44 , & V_45 ) ;
F_26 ( V_1 , V_52 , V_75 , V_46 ) ;
F_30 ( V_1 , V_52 , V_85 , V_45 == 4 ) ;
F_30 ( V_1 , V_52 , V_86 , V_45 == 2 ) ;
F_30 ( V_1 , V_52 , V_60 , V_60 ) ;
F_30 ( V_1 , V_52 , V_62 , V_62 ) ;
F_30 ( V_1 , V_52 , V_87 , V_82 ) ;
F_30 ( V_1 , V_52 , V_88 , V_82 ) ;
F_30 ( V_1 , V_52 , V_89 , V_44 ) ;
}
}
static void F_31 ( struct V_1 * V_1 )
{
unsigned long V_90 ;
if ( F_32 ( ! V_1 -> V_91 ) )
return;
F_33 ( & V_1 -> V_92 , V_90 ) ;
F_34 ( V_1 , V_93 , V_94 , 1 ) ;
F_35 ( & V_1 -> V_92 , V_90 ) ;
}
static void F_36 ( struct V_1 * V_1 )
{
unsigned long V_90 ;
if ( F_32 ( ! V_1 -> V_91 ) )
return;
F_33 ( & V_1 -> V_92 , V_90 ) ;
F_34 ( V_1 , V_93 , V_94 , 0 ) ;
F_35 ( & V_1 -> V_92 , V_90 ) ;
}
static void F_37 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
int V_13 ;
V_13 = F_39 ( V_1 -> V_97 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_5 , V_13 ) ;
return;
}
V_13 = F_41 ( V_1 -> V_98 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_6 , V_13 ) ;
return;
}
V_13 = F_41 ( V_1 -> V_99 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_7 , V_13 ) ;
goto V_100;
}
V_13 = F_41 ( V_1 -> V_101 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_8 , V_13 ) ;
goto V_102;
}
V_13 = F_42 ( V_1 -> V_103 , V_1 -> V_97 ) ;
if ( V_13 ) {
F_40 ( V_1 -> V_97 , L_9 , V_13 ) ;
goto V_104;
}
memcpy ( V_1 -> V_4 , V_1 -> V_5 , V_1 -> V_105 ) ;
V_1 -> V_91 = true ;
F_43 ( & V_1 -> V_106 ) ;
F_11 ( V_1 , V_107 , 0 ) ;
F_44 ( & V_1 -> V_106 ) ;
F_45 ( V_1 -> V_108 ) ;
F_46 ( V_96 ) ;
return;
V_104:
F_47 ( V_1 -> V_101 ) ;
V_102:
F_47 ( V_1 -> V_99 ) ;
V_100:
F_47 ( V_1 -> V_98 ) ;
}
static void F_48 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
int V_12 ;
F_32 ( V_1 -> V_109 ) ;
for ( V_12 = 0 ; V_12 < V_1 -> V_14 -> V_110 ; V_12 ++ ) {
struct V_111 * V_111 = & V_1 -> V_52 [ V_12 ] ;
const struct V_51 * V_52 = V_111 -> V_14 ;
F_43 ( & V_1 -> V_106 ) ;
F_49 ( V_1 , V_52 , V_93 , 0 ) ;
F_44 ( & V_1 -> V_106 ) ;
}
F_50 ( V_96 ) ;
F_51 ( & V_1 -> V_112 ) ;
F_31 ( V_1 ) ;
F_43 ( & V_1 -> V_106 ) ;
F_11 ( V_1 , V_107 , 1 ) ;
F_44 ( & V_1 -> V_106 ) ;
F_52 ( & V_1 -> V_112 ) ;
F_36 ( V_1 ) ;
F_53 ( V_1 -> V_108 ) ;
V_1 -> V_91 = false ;
F_54 ( V_1 -> V_103 , V_1 -> V_97 ) ;
F_47 ( V_1 -> V_99 ) ;
F_47 ( V_1 -> V_101 ) ;
F_47 ( V_1 -> V_98 ) ;
F_55 ( V_1 -> V_97 ) ;
if ( V_96 -> V_113 -> V_109 && ! V_96 -> V_113 -> V_114 ) {
F_56 ( & V_96 -> V_97 -> V_115 ) ;
F_57 ( V_96 , V_96 -> V_113 -> V_109 ) ;
F_58 ( & V_96 -> V_97 -> V_115 ) ;
V_96 -> V_113 -> V_109 = NULL ;
}
}
static void F_59 ( struct V_116 * V_117 )
{
F_60 ( V_117 ) ;
}
static int F_61 ( struct V_116 * V_117 ,
const struct V_118 * V_119 )
{
if ( V_117 -> V_113 -> V_120 )
F_62 ( V_117 -> V_113 -> V_120 ) ;
return 0 ;
}
static void F_63 ( struct V_116 * V_117 ,
const struct V_118 * V_121 )
{
if ( V_121 -> V_120 )
F_64 ( V_121 -> V_120 ) ;
}
static int F_65 ( struct V_116 * V_117 ,
struct V_118 * V_113 )
{
struct V_95 * V_96 = V_113 -> V_96 ;
struct V_122 * V_123 ;
struct V_124 * V_120 = V_113 -> V_120 ;
struct V_111 * V_111 = F_66 ( V_117 ) ;
struct V_125 * V_125 = F_67 ( V_113 ) ;
const struct V_51 * V_52 = V_111 -> V_14 ;
bool V_126 ;
int V_13 ;
struct V_127 * V_128 = & V_125 -> V_128 ;
struct V_127 * V_41 = & V_125 -> V_41 ;
struct V_127 V_129 ;
int V_130 = V_52 -> V_69 -> V_70 ? F_68 ( 1 , 8 ) :
V_131 ;
int V_132 = V_52 -> V_69 -> V_70 ? F_68 ( 8 , 1 ) :
V_131 ;
if ( ! V_96 || ! V_120 )
goto V_133;
V_123 = F_69 ( V_113 -> V_113 , V_96 ) ;
if ( F_32 ( ! V_123 ) )
return - V_38 ;
V_41 -> V_134 = V_113 -> V_135 ;
V_41 -> y1 = V_113 -> V_136 ;
V_41 -> V_137 = V_113 -> V_135 + V_113 -> V_53 ;
V_41 -> V_138 = V_113 -> V_136 + V_113 -> V_54 ;
V_128 -> V_134 = V_113 -> V_139 ;
V_128 -> y1 = V_113 -> V_140 ;
V_128 -> V_137 = V_113 -> V_139 + V_113 -> V_141 ;
V_128 -> V_138 = V_113 -> V_140 + V_113 -> V_142 ;
V_129 . V_134 = 0 ;
V_129 . y1 = 0 ;
V_129 . V_137 = V_123 -> V_143 . V_144 ;
V_129 . V_138 = V_123 -> V_143 . V_145 ;
V_13 = F_70 ( V_117 , V_96 , V_113 -> V_120 ,
V_41 , V_128 , & V_129 ,
V_113 -> V_146 ,
V_130 ,
V_132 ,
true , true , & V_126 ) ;
if ( V_13 )
return V_13 ;
if ( ! V_126 )
goto V_133;
V_125 -> V_19 = F_13 ( V_120 -> V_57 ) ;
if ( V_125 -> V_19 < 0 )
return V_125 -> V_19 ;
if ( F_15 ( V_120 -> V_57 ) && ( ( V_41 -> V_134 >> 16 ) % 2 ) )
return - V_38 ;
V_125 -> V_93 = true ;
return 0 ;
V_133:
V_125 -> V_93 = false ;
return 0 ;
}
static void F_71 ( struct V_116 * V_117 ,
struct V_118 * V_121 )
{
struct V_125 * V_125 = F_67 ( V_121 ) ;
struct V_111 * V_111 = F_66 ( V_117 ) ;
const struct V_51 * V_52 = V_111 -> V_14 ;
struct V_1 * V_1 = F_38 ( V_121 -> V_96 ) ;
if ( ! V_121 -> V_96 )
return;
F_56 ( & V_117 -> V_97 -> V_115 ) ;
V_111 -> V_93 = false ;
V_111 -> V_147 = 0 ;
F_58 ( & V_117 -> V_97 -> V_115 ) ;
F_43 ( & V_1 -> V_106 ) ;
F_49 ( V_1 , V_52 , V_93 , 0 ) ;
F_44 ( & V_1 -> V_106 ) ;
V_125 -> V_93 = false ;
}
static void F_72 ( struct V_116 * V_117 ,
struct V_118 * V_121 )
{
struct V_118 * V_113 = V_117 -> V_113 ;
struct V_95 * V_96 = V_113 -> V_96 ;
struct V_111 * V_111 = F_66 ( V_117 ) ;
struct V_125 * V_125 = F_67 ( V_113 ) ;
const struct V_51 * V_52 = V_111 -> V_14 ;
struct V_1 * V_1 = F_38 ( V_113 -> V_96 ) ;
struct V_124 * V_120 = V_113 -> V_120 ;
unsigned int V_148 , V_149 ;
unsigned int V_150 , V_151 ;
T_1 V_152 , V_153 , V_154 ;
struct V_127 * V_41 = & V_125 -> V_41 ;
struct V_127 * V_128 = & V_125 -> V_128 ;
struct V_155 * V_156 , * V_157 ;
struct V_158 * V_159 , * V_160 ;
unsigned long V_2 ;
T_3 V_161 ;
T_1 V_46 ;
bool V_162 ;
if ( F_32 ( ! V_96 ) )
return;
if ( F_32 ( ! V_1 -> V_91 ) )
return;
if ( ! V_125 -> V_93 ) {
F_71 ( V_117 , V_121 ) ;
return;
}
V_156 = F_73 ( V_120 , 0 ) ;
V_159 = F_74 ( V_156 ) ;
V_148 = F_75 ( V_41 ) >> 16 ;
V_149 = F_76 ( V_41 ) >> 16 ;
V_152 = ( V_149 - 1 ) << 16 | ( ( V_148 - 1 ) & 0xffff ) ;
V_153 = ( F_76 ( V_128 ) - 1 ) << 16 ;
V_153 |= ( F_75 ( V_128 ) - 1 ) & 0xffff ;
V_150 = V_128 -> V_134 + V_96 -> V_40 . V_163 - V_96 -> V_40 . V_164 ;
V_151 = V_128 -> y1 + V_96 -> V_40 . V_165 - V_96 -> V_40 . V_166 ;
V_154 = V_151 << 16 | ( V_150 & 0xffff ) ;
V_2 = ( V_41 -> V_134 >> 16 ) * F_77 ( V_120 -> V_57 , 0 ) ;
V_2 += ( V_41 -> y1 >> 16 ) * V_120 -> V_167 [ 0 ] ;
V_125 -> V_147 = V_159 -> V_161 + V_2 + V_120 -> V_168 [ 0 ] ;
F_56 ( & V_117 -> V_97 -> V_115 ) ;
V_111 -> V_93 = true ;
V_111 -> V_147 = V_125 -> V_147 ;
F_58 ( & V_117 -> V_97 -> V_115 ) ;
F_43 ( & V_1 -> V_106 ) ;
F_49 ( V_1 , V_52 , V_19 , V_125 -> V_19 ) ;
F_49 ( V_1 , V_52 , V_169 , V_120 -> V_167 [ 0 ] >> 2 ) ;
F_49 ( V_1 , V_52 , V_147 , V_125 -> V_147 ) ;
if ( F_15 ( V_120 -> V_57 ) ) {
int V_63 = F_24 ( V_120 -> V_57 ) ;
int V_64 = F_25 ( V_120 -> V_57 ) ;
int V_170 = F_77 ( V_120 -> V_57 , 1 ) ;
V_157 = F_73 ( V_120 , 1 ) ;
V_160 = F_74 ( V_157 ) ;
V_2 = ( V_41 -> V_134 >> 16 ) * V_170 / V_63 ;
V_2 += ( V_41 -> y1 >> 16 ) * V_120 -> V_167 [ 1 ] / V_64 ;
V_161 = V_160 -> V_161 + V_2 + V_120 -> V_168 [ 1 ] ;
F_49 ( V_1 , V_52 , V_171 , V_120 -> V_167 [ 1 ] >> 2 ) ;
F_49 ( V_1 , V_52 , V_172 , V_161 ) ;
}
if ( V_52 -> V_69 -> V_70 )
F_23 ( V_1 , V_52 , V_148 , V_149 ,
F_75 ( V_128 ) , F_76 ( V_128 ) ,
V_120 -> V_57 ) ;
F_49 ( V_1 , V_52 , V_152 , V_152 ) ;
F_49 ( V_1 , V_52 , V_153 , V_153 ) ;
F_49 ( V_1 , V_52 , V_154 , V_154 ) ;
V_162 = F_12 ( V_120 -> V_57 ) ;
F_49 ( V_1 , V_52 , V_162 , V_162 ) ;
if ( F_16 ( V_120 -> V_57 ) ) {
F_49 ( V_1 , V_52 , V_173 ,
F_78 ( V_174 ) ) ;
V_46 = F_79 ( 1 ) | F_80 ( V_175 ) |
F_81 ( V_176 ) |
F_82 ( V_177 ) |
F_83 ( V_178 ) |
F_84 ( V_179 ) ;
F_49 ( V_1 , V_52 , V_180 , V_46 ) ;
} else {
F_49 ( V_1 , V_52 , V_180 , F_79 ( 0 ) ) ;
}
F_49 ( V_1 , V_52 , V_93 , 1 ) ;
F_44 ( & V_1 -> V_106 ) ;
}
static void F_85 ( struct V_116 * V_117 )
{
struct V_125 * V_125 =
F_67 ( V_117 -> V_113 ) ;
if ( V_117 -> V_113 && V_117 -> V_113 -> V_120 )
F_64 ( V_117 -> V_113 -> V_120 ) ;
F_86 ( V_125 ) ;
V_125 = F_87 ( sizeof( * V_125 ) , V_181 ) ;
if ( ! V_125 )
return;
V_117 -> V_113 = & V_125 -> V_6 ;
V_117 -> V_113 -> V_117 = V_117 ;
}
static struct V_118 *
F_88 ( struct V_116 * V_117 )
{
struct V_125 * V_182 ;
struct V_125 * V_125 ;
if ( F_32 ( ! V_117 -> V_113 ) )
return NULL ;
V_182 = F_67 ( V_117 -> V_113 ) ;
V_125 = F_89 ( V_182 ,
sizeof( * V_125 ) , V_181 ) ;
if ( ! V_125 )
return NULL ;
F_90 ( V_117 ,
& V_125 -> V_6 ) ;
return & V_125 -> V_6 ;
}
static void F_91 ( struct V_116 * V_117 ,
struct V_118 * V_113 )
{
struct V_125 * V_183 = F_67 ( V_113 ) ;
F_92 ( V_113 ) ;
F_86 ( V_183 ) ;
}
static int F_93 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
unsigned long V_90 ;
if ( F_32 ( ! V_1 -> V_91 ) )
return - V_184 ;
F_33 ( & V_1 -> V_92 , V_90 ) ;
F_34 ( V_1 , V_93 , V_185 , 1 ) ;
F_35 ( & V_1 -> V_92 , V_90 ) ;
return 0 ;
}
static void F_94 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
unsigned long V_90 ;
if ( F_32 ( ! V_1 -> V_91 ) )
return;
F_33 ( & V_1 -> V_92 , V_90 ) ;
F_34 ( V_1 , V_93 , V_185 , 0 ) ;
F_35 ( & V_1 -> V_92 , V_90 ) ;
}
static void F_95 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
F_51 ( & V_1 -> V_186 ) ;
F_32 ( ! F_96 ( & V_1 -> V_186 , 100 ) ) ;
}
static bool F_97 ( struct V_95 * V_96 ,
const struct V_187 * V_40 ,
struct V_187 * V_143 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
V_143 -> clock =
F_98 ( V_1 -> V_99 , V_40 -> clock * 1000 ) / 1000 ;
return true ;
}
static void F_99 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
struct V_188 * V_189 = F_100 ( V_96 -> V_113 ) ;
struct V_187 * V_143 = & V_96 -> V_113 -> V_143 ;
T_4 V_190 = V_143 -> V_191 - V_143 -> V_164 ;
T_4 V_144 = V_143 -> V_144 ;
T_4 V_163 = V_143 -> V_163 ;
T_4 V_192 = V_143 -> V_163 - V_143 -> V_164 ;
T_4 V_193 = V_192 + V_144 ;
T_4 V_145 = V_143 -> V_145 ;
T_4 V_165 = V_143 -> V_165 ;
T_4 V_194 = V_143 -> V_195 - V_143 -> V_166 ;
T_4 V_196 = V_143 -> V_165 - V_143 -> V_166 ;
T_4 V_197 = V_196 + V_145 ;
T_1 V_46 ;
F_32 ( V_1 -> V_109 ) ;
F_37 ( V_96 ) ;
if ( F_101 ( V_1 -> V_99 ) ) {
F_51 ( & V_1 -> V_112 ) ;
F_31 ( V_1 ) ;
F_43 ( & V_1 -> V_106 ) ;
F_11 ( V_1 , V_107 , 1 ) ;
F_44 ( & V_1 -> V_106 ) ;
F_52 ( & V_1 -> V_112 ) ;
F_36 ( V_1 ) ;
}
V_46 = 0x8 ;
V_46 |= ( V_143 -> V_90 & V_198 ) ? 0 : 1 ;
V_46 |= ( V_143 -> V_90 & V_199 ) ? 0 : ( 1 << 1 ) ;
F_11 ( V_1 , V_200 , V_46 ) ;
switch ( V_189 -> V_201 ) {
case V_202 :
F_11 ( V_1 , V_203 , 1 ) ;
break;
case V_204 :
F_11 ( V_1 , V_205 , 1 ) ;
break;
case V_206 :
F_11 ( V_1 , V_207 , 1 ) ;
break;
case V_208 :
F_11 ( V_1 , V_209 , 1 ) ;
break;
default:
F_14 ( L_10 , V_189 -> V_201 ) ;
}
F_11 ( V_1 , V_210 , V_189 -> V_211 ) ;
F_11 ( V_1 , V_212 , ( V_163 << 16 ) | V_190 ) ;
V_46 = V_192 << 16 ;
V_46 |= V_193 ;
F_11 ( V_1 , V_213 , V_46 ) ;
F_11 ( V_1 , V_214 , V_46 ) ;
F_11 ( V_1 , V_215 , ( V_165 << 16 ) | V_194 ) ;
V_46 = V_196 << 16 ;
V_46 |= V_197 ;
F_11 ( V_1 , V_216 , V_46 ) ;
F_11 ( V_1 , V_217 , V_46 ) ;
F_102 ( V_1 -> V_99 , V_143 -> clock * 1000 ) ;
F_11 ( V_1 , V_107 , 0 ) ;
}
static void F_103 ( struct V_95 * V_96 ,
struct V_122 * V_218 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
if ( F_32 ( ! V_1 -> V_91 ) )
return;
F_43 ( & V_1 -> V_106 ) ;
F_10 ( V_1 ) ;
F_44 ( & V_1 -> V_106 ) ;
}
static void F_104 ( struct V_95 * V_96 ,
struct V_122 * V_218 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
F_56 ( & V_96 -> V_97 -> V_115 ) ;
if ( V_96 -> V_113 -> V_109 ) {
F_32 ( F_105 ( V_96 ) != 0 ) ;
F_32 ( V_1 -> V_109 ) ;
V_1 -> V_109 = V_96 -> V_113 -> V_109 ;
V_96 -> V_113 -> V_109 = NULL ;
}
F_58 ( & V_96 -> V_97 -> V_115 ) ;
}
static void F_106 ( struct V_95 * V_96 )
{
F_107 ( V_96 ) ;
}
static void F_108 ( struct V_95 * V_96 )
{
if ( V_96 -> V_113 )
F_109 ( V_96 -> V_113 ) ;
F_86 ( V_96 -> V_113 ) ;
V_96 -> V_113 = F_87 ( sizeof( struct V_188 ) , V_181 ) ;
if ( V_96 -> V_113 )
V_96 -> V_113 -> V_96 = V_96 ;
}
static struct V_122 * F_110 ( struct V_95 * V_96 )
{
struct V_188 * V_219 ;
V_219 = F_87 ( sizeof( * V_219 ) , V_181 ) ;
if ( ! V_219 )
return NULL ;
F_111 ( V_96 , & V_219 -> V_6 ) ;
return & V_219 -> V_6 ;
}
static void F_112 ( struct V_95 * V_96 ,
struct V_122 * V_113 )
{
struct V_188 * V_189 = F_100 ( V_113 ) ;
F_109 ( & V_189 -> V_6 ) ;
F_86 ( V_189 ) ;
}
static bool F_113 ( struct V_111 * V_111 )
{
T_3 V_147 ;
if ( ! V_111 -> V_93 )
return F_114 ( V_111 -> V_1 , V_111 -> V_14 , V_93 ) == 0 ;
V_147 = F_115 ( V_111 -> V_1 , V_111 -> V_14 ) ;
return V_147 == V_111 -> V_147 ;
}
static void F_116 ( struct V_1 * V_1 )
{
struct V_220 * V_221 = V_1 -> V_103 ;
struct V_95 * V_96 = & V_1 -> V_96 ;
unsigned long V_90 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_1 -> V_14 -> V_110 ; V_12 ++ ) {
if ( ! F_113 ( & V_1 -> V_52 [ V_12 ] ) )
return;
}
F_33 ( & V_221 -> V_115 , V_90 ) ;
if ( V_1 -> V_109 ) {
F_57 ( V_96 , V_1 -> V_109 ) ;
F_117 ( V_96 ) ;
V_1 -> V_109 = NULL ;
}
F_35 ( & V_221 -> V_115 , V_90 ) ;
if ( ! F_118 ( & V_1 -> V_186 ) )
F_119 ( & V_1 -> V_186 ) ;
}
static T_5 F_120 ( int V_108 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
struct V_95 * V_96 = & V_1 -> V_96 ;
T_1 V_222 ;
unsigned long V_90 ;
int V_13 = V_223 ;
F_33 ( & V_1 -> V_92 , V_90 ) ;
V_222 = F_121 ( V_1 , V_224 , V_225 ) ;
if ( V_222 )
F_34 ( V_1 , V_226 , V_222 , 1 ) ;
F_35 ( & V_1 -> V_92 , V_90 ) ;
if ( ! V_222 )
return V_223 ;
if ( V_222 & V_94 ) {
F_119 ( & V_1 -> V_112 ) ;
V_222 &= ~ V_94 ;
V_13 = V_227 ;
}
if ( V_222 & V_185 ) {
F_122 ( V_96 ) ;
F_116 ( V_1 ) ;
V_222 &= ~ V_185 ;
V_13 = V_227 ;
}
if ( V_222 )
F_14 ( L_11 , V_222 ) ;
return V_13 ;
}
static int F_123 ( struct V_1 * V_1 )
{
const struct V_228 * V_228 = V_1 -> V_14 ;
struct V_229 * V_97 = V_1 -> V_97 ;
struct V_220 * V_103 = V_1 -> V_103 ;
struct V_116 * V_230 = NULL , * V_231 = NULL , * V_117 , * V_232 ;
struct V_95 * V_96 = & V_1 -> V_96 ;
struct V_233 * V_234 ;
int V_13 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_228 -> V_110 ; V_12 ++ ) {
struct V_111 * V_111 = & V_1 -> V_52 [ V_12 ] ;
const struct V_51 * V_235 = V_111 -> V_14 ;
if ( V_235 -> type != V_236 &&
V_235 -> type != V_237 )
continue;
V_13 = F_124 ( V_1 -> V_103 , & V_111 -> V_6 ,
0 , & V_238 ,
V_235 -> V_69 -> V_239 ,
V_235 -> V_69 -> V_240 ,
V_235 -> type , NULL ) ;
if ( V_13 ) {
F_14 ( L_12 ) ;
goto V_241;
}
V_117 = & V_111 -> V_6 ;
F_125 ( V_117 , & V_242 ) ;
if ( V_117 -> type == V_236 )
V_230 = V_117 ;
else if ( V_117 -> type == V_237 )
V_231 = V_117 ;
}
V_13 = F_126 ( V_103 , V_96 , V_230 , V_231 ,
& V_243 , NULL ) ;
if ( V_13 )
goto V_241;
F_127 ( V_96 , & V_244 ) ;
for ( V_12 = 0 ; V_12 < V_228 -> V_110 ; V_12 ++ ) {
struct V_111 * V_111 = & V_1 -> V_52 [ V_12 ] ;
const struct V_51 * V_235 = V_111 -> V_14 ;
unsigned long V_245 = 1 << F_128 ( V_96 ) ;
if ( V_235 -> type != V_246 )
continue;
V_13 = F_124 ( V_1 -> V_103 , & V_111 -> V_6 ,
V_245 ,
& V_238 ,
V_235 -> V_69 -> V_239 ,
V_235 -> V_69 -> V_240 ,
V_235 -> type , NULL ) ;
if ( V_13 ) {
F_14 ( L_13 ) ;
goto V_247;
}
F_125 ( & V_111 -> V_6 , & V_242 ) ;
}
V_234 = F_129 ( V_97 -> V_248 , L_14 ) ;
if ( ! V_234 ) {
F_14 ( L_15 ,
V_97 -> V_248 -> V_249 ) ;
V_13 = - V_250 ;
goto V_247;
}
F_130 ( & V_1 -> V_112 ) ;
F_130 ( & V_1 -> V_186 ) ;
V_96 -> V_234 = V_234 ;
F_131 ( V_96 , & V_251 ) ;
return 0 ;
V_247:
F_107 ( V_96 ) ;
V_241:
F_132 (plane, tmp, &drm_dev->mode_config.plane_list,
head)
F_60 ( V_117 ) ;
return V_13 ;
}
static void F_133 ( struct V_1 * V_1 )
{
struct V_95 * V_96 = & V_1 -> V_96 ;
struct V_220 * V_103 = V_1 -> V_103 ;
struct V_116 * V_117 , * V_232 ;
F_134 ( V_96 ) ;
F_135 ( V_96 -> V_234 ) ;
F_132 (plane, tmp, &drm_dev->mode_config.plane_list,
head)
F_59 ( V_117 ) ;
F_107 ( V_96 ) ;
}
static int F_136 ( struct V_1 * V_1 )
{
const struct V_228 * V_228 = V_1 -> V_14 ;
const struct V_252 * V_253 = V_228 -> V_253 ;
struct V_254 * V_255 ;
int V_12 , V_13 ;
V_1 -> V_98 = F_137 ( V_1 -> V_97 , L_16 ) ;
if ( F_138 ( V_1 -> V_98 ) ) {
F_40 ( V_1 -> V_97 , L_17 ) ;
return F_139 ( V_1 -> V_98 ) ;
}
V_1 -> V_101 = F_137 ( V_1 -> V_97 , L_18 ) ;
if ( F_138 ( V_1 -> V_101 ) ) {
F_40 ( V_1 -> V_97 , L_19 ) ;
return F_139 ( V_1 -> V_101 ) ;
}
V_1 -> V_99 = F_137 ( V_1 -> V_97 , L_20 ) ;
if ( F_138 ( V_1 -> V_99 ) ) {
F_40 ( V_1 -> V_97 , L_21 ) ;
return F_139 ( V_1 -> V_99 ) ;
}
V_13 = F_140 ( V_1 -> V_99 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_22 ) ;
return V_13 ;
}
V_13 = F_141 ( V_1 -> V_98 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_23 ) ;
goto V_256;
}
V_13 = F_141 ( V_1 -> V_101 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_24 ) ;
goto V_100;
}
V_255 = F_142 ( V_1 -> V_97 , L_25 ) ;
if ( F_138 ( V_255 ) ) {
F_40 ( V_1 -> V_97 , L_26 ) ;
V_13 = F_139 ( V_255 ) ;
goto V_104;
}
F_143 ( V_255 ) ;
F_144 ( 10 , 20 ) ;
F_145 ( V_255 ) ;
memcpy ( V_1 -> V_5 , V_1 -> V_4 , V_1 -> V_105 ) ;
for ( V_12 = 0 ; V_12 < V_228 -> V_257 ; V_12 ++ )
F_1 ( V_1 , V_253 [ V_12 ] . V_2 , V_253 [ V_12 ] . V_258 ) ;
for ( V_12 = 0 ; V_12 < V_228 -> V_110 ; V_12 ++ ) {
const struct V_51 * V_52 = & V_228 -> V_52 [ V_12 ] ;
F_49 ( V_1 , V_52 , V_93 , 0 ) ;
}
F_10 ( V_1 ) ;
V_1 -> V_259 = F_142 ( V_1 -> V_97 , L_27 ) ;
if ( F_138 ( V_1 -> V_259 ) ) {
F_40 ( V_1 -> V_97 , L_28 ) ;
V_13 = F_139 ( V_1 -> V_259 ) ;
goto V_104;
}
F_143 ( V_1 -> V_259 ) ;
F_144 ( 10 , 20 ) ;
F_145 ( V_1 -> V_259 ) ;
F_47 ( V_1 -> V_98 ) ;
F_47 ( V_1 -> V_101 ) ;
V_1 -> V_91 = false ;
return 0 ;
V_104:
F_146 ( V_1 -> V_101 ) ;
V_100:
F_146 ( V_1 -> V_98 ) ;
V_256:
F_147 ( V_1 -> V_99 ) ;
return V_13 ;
}
static void F_148 ( struct V_1 * V_1 )
{
const struct V_228 * V_228 = V_1 -> V_14 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_228 -> V_110 ; V_12 ++ ) {
struct V_111 * V_111 = & V_1 -> V_52 [ V_12 ] ;
const struct V_51 * V_235 = & V_228 -> V_52 [ V_12 ] ;
V_111 -> V_14 = V_235 ;
V_111 -> V_1 = V_1 ;
}
}
static int F_149 ( struct V_229 * V_97 , struct V_229 * V_260 , void * V_14 )
{
struct V_261 * V_262 = F_150 ( V_97 ) ;
const struct V_228 * V_228 ;
struct V_220 * V_103 = V_14 ;
struct V_1 * V_1 ;
struct V_263 * V_264 ;
T_6 V_265 ;
int V_13 , V_108 ;
V_228 = F_151 ( V_97 ) ;
if ( ! V_228 )
return - V_266 ;
V_265 = sizeof( * V_1 ) + sizeof( * V_1 -> V_52 ) * V_228 -> V_110 ;
V_1 = F_152 ( V_97 , V_265 , V_181 ) ;
if ( ! V_1 )
return - V_267 ;
V_1 -> V_97 = V_97 ;
V_1 -> V_14 = V_228 ;
V_1 -> V_103 = V_103 ;
F_153 ( V_97 , V_1 ) ;
F_148 ( V_1 ) ;
V_264 = F_154 ( V_262 , V_268 , 0 ) ;
V_1 -> V_105 = F_155 ( V_264 ) ;
V_1 -> V_4 = F_156 ( V_97 , V_264 ) ;
if ( F_138 ( V_1 -> V_4 ) )
return F_139 ( V_1 -> V_4 ) ;
V_1 -> V_5 = F_152 ( V_97 , V_1 -> V_105 , V_181 ) ;
if ( ! V_1 -> V_5 )
return - V_267 ;
V_13 = F_136 ( V_1 ) ;
if ( V_13 < 0 ) {
F_40 ( & V_262 -> V_97 , L_29 , V_13 ) ;
return V_13 ;
}
V_108 = F_157 ( V_262 , 0 ) ;
if ( V_108 < 0 ) {
F_40 ( V_97 , L_30 ) ;
return V_108 ;
}
V_1 -> V_108 = ( unsigned int ) V_108 ;
F_158 ( & V_1 -> V_106 ) ;
F_158 ( & V_1 -> V_92 ) ;
F_159 ( & V_1 -> V_269 ) ;
V_13 = F_160 ( V_97 , V_1 -> V_108 , F_120 ,
V_270 , F_161 ( V_97 ) , V_1 ) ;
if ( V_13 )
return V_13 ;
F_53 ( V_1 -> V_108 ) ;
V_13 = F_123 ( V_1 ) ;
if ( V_13 )
return V_13 ;
F_162 ( & V_262 -> V_97 ) ;
return 0 ;
}
static void F_163 ( struct V_229 * V_97 , struct V_229 * V_260 , void * V_14 )
{
struct V_1 * V_1 = F_164 ( V_97 ) ;
F_165 ( V_97 ) ;
F_133 ( V_1 ) ;
}
