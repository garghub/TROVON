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
F_27 ( V_53 , V_55 ) ) ;
F_26 ( V_1 , V_52 , V_75 ,
F_27 ( V_54 , V_56 ) ) ;
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
if ( V_1 -> V_91 )
return;
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
if ( ! V_1 -> V_91 )
return;
for ( V_12 = 0 ; V_12 < V_1 -> V_14 -> V_109 ; V_12 ++ ) {
struct V_110 * V_110 = & V_1 -> V_52 [ V_12 ] ;
const struct V_51 * V_52 = V_110 -> V_14 ;
F_43 ( & V_1 -> V_106 ) ;
F_49 ( V_1 , V_52 , V_93 , 0 ) ;
F_44 ( & V_1 -> V_106 ) ;
}
F_50 ( V_96 ) ;
F_51 ( & V_1 -> V_111 ) ;
F_31 ( V_1 ) ;
F_43 ( & V_1 -> V_106 ) ;
F_11 ( V_1 , V_107 , 1 ) ;
F_44 ( & V_1 -> V_106 ) ;
F_52 ( & V_1 -> V_111 ) ;
F_36 ( V_1 ) ;
F_53 ( V_1 -> V_108 ) ;
V_1 -> V_91 = false ;
F_54 ( V_1 -> V_103 , V_1 -> V_97 ) ;
F_47 ( V_1 -> V_99 ) ;
F_47 ( V_1 -> V_101 ) ;
F_47 ( V_1 -> V_98 ) ;
F_55 ( V_1 -> V_97 ) ;
}
static void F_56 ( struct V_112 * V_113 )
{
F_57 ( V_113 ) ;
}
static int F_58 ( struct V_112 * V_113 ,
const struct V_114 * V_115 )
{
if ( V_113 -> V_116 -> V_117 )
F_59 ( V_113 -> V_116 -> V_117 ) ;
return 0 ;
}
static void F_60 ( struct V_112 * V_113 ,
const struct V_114 * V_118 )
{
if ( V_118 -> V_117 )
F_61 ( V_118 -> V_117 ) ;
}
static int F_62 ( struct V_112 * V_113 ,
struct V_114 * V_116 )
{
struct V_95 * V_96 = V_116 -> V_96 ;
struct V_119 * V_120 ;
struct V_121 * V_117 = V_116 -> V_117 ;
struct V_110 * V_110 = F_63 ( V_113 ) ;
struct V_122 * V_122 = F_64 ( V_116 ) ;
const struct V_51 * V_52 = V_110 -> V_14 ;
bool V_123 ;
int V_13 ;
struct V_124 * V_125 = & V_122 -> V_125 ;
struct V_124 * V_41 = & V_122 -> V_41 ;
struct V_124 V_126 ;
int V_127 = V_52 -> V_69 -> V_70 ? F_65 ( 1 , 8 ) :
V_128 ;
int V_129 = V_52 -> V_69 -> V_70 ? F_65 ( 8 , 1 ) :
V_128 ;
if ( ! V_96 || ! V_117 )
goto V_130;
V_120 = F_66 ( V_116 -> V_116 , V_96 ) ;
if ( F_32 ( ! V_120 ) )
return - V_38 ;
V_41 -> V_131 = V_116 -> V_132 ;
V_41 -> y1 = V_116 -> V_133 ;
V_41 -> V_134 = V_116 -> V_132 + V_116 -> V_53 ;
V_41 -> V_135 = V_116 -> V_133 + V_116 -> V_54 ;
V_125 -> V_131 = V_116 -> V_136 ;
V_125 -> y1 = V_116 -> V_137 ;
V_125 -> V_134 = V_116 -> V_136 + V_116 -> V_138 ;
V_125 -> V_135 = V_116 -> V_137 + V_116 -> V_139 ;
V_126 . V_131 = 0 ;
V_126 . y1 = 0 ;
V_126 . V_134 = V_120 -> V_140 . V_141 ;
V_126 . V_135 = V_120 -> V_140 . V_142 ;
V_13 = F_67 ( V_113 , V_96 , V_116 -> V_117 ,
V_41 , V_125 , & V_126 ,
V_127 ,
V_129 ,
true , true , & V_123 ) ;
if ( V_13 )
return V_13 ;
if ( ! V_123 )
goto V_130;
V_122 -> V_19 = F_13 ( V_117 -> V_57 ) ;
if ( V_122 -> V_19 < 0 )
return V_122 -> V_19 ;
if ( F_15 ( V_117 -> V_57 ) && ( ( V_41 -> V_131 >> 16 ) % 2 ) )
return - V_38 ;
V_122 -> V_93 = true ;
return 0 ;
V_130:
V_122 -> V_93 = false ;
return 0 ;
}
static void F_68 ( struct V_112 * V_113 ,
struct V_114 * V_118 )
{
struct V_122 * V_122 = F_64 ( V_118 ) ;
struct V_110 * V_110 = F_63 ( V_113 ) ;
const struct V_51 * V_52 = V_110 -> V_14 ;
struct V_1 * V_1 = F_38 ( V_118 -> V_96 ) ;
if ( ! V_118 -> V_96 )
return;
F_43 ( & V_1 -> V_106 ) ;
F_49 ( V_1 , V_52 , V_93 , 0 ) ;
F_44 ( & V_1 -> V_106 ) ;
V_122 -> V_93 = false ;
}
static void F_69 ( struct V_112 * V_113 ,
struct V_114 * V_118 )
{
struct V_114 * V_116 = V_113 -> V_116 ;
struct V_95 * V_96 = V_116 -> V_96 ;
struct V_110 * V_110 = F_63 ( V_113 ) ;
struct V_122 * V_122 = F_64 ( V_116 ) ;
const struct V_51 * V_52 = V_110 -> V_14 ;
struct V_1 * V_1 = F_38 ( V_116 -> V_96 ) ;
struct V_121 * V_117 = V_116 -> V_117 ;
unsigned int V_143 , V_144 ;
unsigned int V_145 , V_146 ;
T_1 V_147 , V_148 , V_149 ;
struct V_124 * V_41 = & V_122 -> V_41 ;
struct V_124 * V_125 = & V_122 -> V_125 ;
struct V_150 * V_151 , * V_152 ;
struct V_153 * V_154 , * V_155 ;
unsigned long V_2 ;
T_3 V_156 ;
T_1 V_46 ;
bool V_157 ;
if ( ! V_96 )
return;
if ( F_32 ( ! V_1 -> V_91 ) )
return;
if ( ! V_122 -> V_93 ) {
F_68 ( V_113 , V_118 ) ;
return;
}
V_151 = F_70 ( V_117 , 0 ) ;
V_154 = F_71 ( V_151 ) ;
V_143 = F_72 ( V_41 ) >> 16 ;
V_144 = F_73 ( V_41 ) >> 16 ;
V_147 = ( V_144 - 1 ) << 16 | ( ( V_143 - 1 ) & 0xffff ) ;
V_148 = ( F_73 ( V_125 ) - 1 ) << 16 ;
V_148 |= ( F_72 ( V_125 ) - 1 ) & 0xffff ;
V_145 = V_125 -> V_131 + V_96 -> V_40 . V_158 - V_96 -> V_40 . V_159 ;
V_146 = V_125 -> y1 + V_96 -> V_40 . V_160 - V_96 -> V_40 . V_161 ;
V_149 = V_146 << 16 | ( V_145 & 0xffff ) ;
V_2 = ( V_41 -> V_131 >> 16 ) * F_74 ( V_117 -> V_57 , 0 ) ;
V_2 += ( V_41 -> y1 >> 16 ) * V_117 -> V_162 [ 0 ] ;
V_122 -> V_163 = V_154 -> V_156 + V_2 + V_117 -> V_164 [ 0 ] ;
F_43 ( & V_1 -> V_106 ) ;
F_49 ( V_1 , V_52 , V_19 , V_122 -> V_19 ) ;
F_49 ( V_1 , V_52 , V_165 , V_117 -> V_162 [ 0 ] >> 2 ) ;
F_49 ( V_1 , V_52 , V_163 , V_122 -> V_163 ) ;
if ( F_15 ( V_117 -> V_57 ) ) {
int V_63 = F_24 ( V_117 -> V_57 ) ;
int V_64 = F_25 ( V_117 -> V_57 ) ;
int V_166 = F_74 ( V_117 -> V_57 , 1 ) ;
V_152 = F_70 ( V_117 , 1 ) ;
V_155 = F_71 ( V_152 ) ;
V_2 = ( V_41 -> V_131 >> 16 ) * V_166 / V_63 ;
V_2 += ( V_41 -> y1 >> 16 ) * V_117 -> V_162 [ 1 ] / V_64 ;
V_156 = V_155 -> V_156 + V_2 + V_117 -> V_164 [ 1 ] ;
F_49 ( V_1 , V_52 , V_167 , V_117 -> V_162 [ 1 ] >> 2 ) ;
F_49 ( V_1 , V_52 , V_168 , V_156 ) ;
}
if ( V_52 -> V_69 -> V_70 )
F_23 ( V_1 , V_52 , V_143 , V_144 ,
F_72 ( V_125 ) , F_73 ( V_125 ) ,
V_117 -> V_57 ) ;
F_49 ( V_1 , V_52 , V_147 , V_147 ) ;
F_49 ( V_1 , V_52 , V_148 , V_148 ) ;
F_49 ( V_1 , V_52 , V_149 , V_149 ) ;
V_157 = F_12 ( V_117 -> V_57 ) ;
F_49 ( V_1 , V_52 , V_157 , V_157 ) ;
if ( F_16 ( V_117 -> V_57 ) ) {
F_49 ( V_1 , V_52 , V_169 ,
F_75 ( V_170 ) ) ;
V_46 = F_76 ( 1 ) | F_77 ( V_171 ) |
F_78 ( V_172 ) |
F_79 ( V_173 ) |
F_80 ( V_174 ) |
F_81 ( V_175 ) ;
F_49 ( V_1 , V_52 , V_176 , V_46 ) ;
} else {
F_49 ( V_1 , V_52 , V_176 , F_76 ( 0 ) ) ;
}
F_49 ( V_1 , V_52 , V_93 , 1 ) ;
F_44 ( & V_1 -> V_106 ) ;
}
void F_82 ( struct V_112 * V_113 )
{
struct V_122 * V_122 =
F_64 ( V_113 -> V_116 ) ;
if ( V_113 -> V_116 && V_113 -> V_116 -> V_117 )
F_61 ( V_113 -> V_116 -> V_117 ) ;
F_83 ( V_122 ) ;
V_122 = F_84 ( sizeof( * V_122 ) , V_177 ) ;
if ( ! V_122 )
return;
V_113 -> V_116 = & V_122 -> V_6 ;
V_113 -> V_116 -> V_113 = V_113 ;
}
struct V_114 *
F_85 ( struct V_112 * V_113 )
{
struct V_122 * V_178 ;
struct V_122 * V_122 ;
if ( F_32 ( ! V_113 -> V_116 ) )
return NULL ;
V_178 = F_64 ( V_113 -> V_116 ) ;
V_122 = F_86 ( V_178 ,
sizeof( * V_122 ) , V_177 ) ;
if ( ! V_122 )
return NULL ;
F_87 ( V_113 ,
& V_122 -> V_6 ) ;
return & V_122 -> V_6 ;
}
static void F_88 ( struct V_112 * V_113 ,
struct V_114 * V_116 )
{
struct V_122 * V_179 = F_64 ( V_116 ) ;
F_89 ( V_116 ) ;
F_83 ( V_179 ) ;
}
static int F_90 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
unsigned long V_90 ;
if ( F_32 ( ! V_1 -> V_91 ) )
return - V_180 ;
F_33 ( & V_1 -> V_92 , V_90 ) ;
F_34 ( V_1 , V_93 , V_181 , 1 ) ;
F_35 ( & V_1 -> V_92 , V_90 ) ;
return 0 ;
}
static void F_91 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
unsigned long V_90 ;
if ( F_32 ( ! V_1 -> V_91 ) )
return;
F_33 ( & V_1 -> V_92 , V_90 ) ;
F_34 ( V_1 , V_93 , V_181 , 0 ) ;
F_35 ( & V_1 -> V_92 , V_90 ) ;
}
static void F_92 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
F_51 ( & V_1 -> V_182 ) ;
F_32 ( ! F_93 ( & V_1 -> V_182 , 100 ) ) ;
}
static void F_94 ( struct V_95 * V_96 ,
struct V_183 * V_184 )
{
struct V_185 * V_186 = V_96 -> V_97 ;
struct V_1 * V_1 = F_38 ( V_96 ) ;
struct V_187 * V_188 ;
unsigned long V_90 ;
F_33 ( & V_186 -> V_189 , V_90 ) ;
V_188 = V_1 -> V_190 ;
if ( V_188 && V_188 -> V_6 . V_184 == V_184 ) {
V_1 -> V_190 = NULL ;
V_188 -> V_6 . V_191 ( & V_188 -> V_6 ) ;
V_184 -> V_192 += sizeof( V_188 -> V_190 ) ;
}
F_35 ( & V_186 -> V_189 , V_90 ) ;
}
static bool F_95 ( struct V_95 * V_96 ,
const struct V_193 * V_40 ,
struct V_193 * V_140 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
V_140 -> clock =
F_96 ( V_1 -> V_99 , V_40 -> clock * 1000 ) / 1000 ;
return true ;
}
static void F_97 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
struct V_194 * V_195 = F_98 ( V_96 -> V_116 ) ;
struct V_193 * V_140 = & V_96 -> V_116 -> V_140 ;
T_4 V_196 = V_140 -> V_197 - V_140 -> V_159 ;
T_4 V_141 = V_140 -> V_141 ;
T_4 V_158 = V_140 -> V_158 ;
T_4 V_198 = V_140 -> V_158 - V_140 -> V_159 ;
T_4 V_199 = V_198 + V_141 ;
T_4 V_142 = V_140 -> V_142 ;
T_4 V_160 = V_140 -> V_160 ;
T_4 V_200 = V_140 -> V_201 - V_140 -> V_161 ;
T_4 V_202 = V_140 -> V_160 - V_140 -> V_161 ;
T_4 V_203 = V_202 + V_142 ;
T_1 V_46 ;
F_37 ( V_96 ) ;
if ( F_99 ( V_1 -> V_99 ) ) {
F_51 ( & V_1 -> V_111 ) ;
F_31 ( V_1 ) ;
F_43 ( & V_1 -> V_106 ) ;
F_11 ( V_1 , V_107 , 1 ) ;
F_44 ( & V_1 -> V_106 ) ;
F_52 ( & V_1 -> V_111 ) ;
F_36 ( V_1 ) ;
}
V_46 = 0x8 ;
V_46 |= ( V_140 -> V_90 & V_204 ) ? 0 : 1 ;
V_46 |= ( V_140 -> V_90 & V_205 ) ? 0 : ( 1 << 1 ) ;
F_11 ( V_1 , V_206 , V_46 ) ;
switch ( V_195 -> V_207 ) {
case V_208 :
F_11 ( V_1 , V_209 , 1 ) ;
break;
case V_210 :
F_11 ( V_1 , V_211 , 1 ) ;
break;
case V_212 :
F_11 ( V_1 , V_213 , 1 ) ;
break;
case V_214 :
F_11 ( V_1 , V_215 , 1 ) ;
break;
default:
F_14 ( L_10 , V_195 -> V_207 ) ;
}
F_11 ( V_1 , V_216 , V_195 -> V_217 ) ;
F_11 ( V_1 , V_218 , ( V_158 << 16 ) | V_196 ) ;
V_46 = V_198 << 16 ;
V_46 |= V_199 ;
F_11 ( V_1 , V_219 , V_46 ) ;
F_11 ( V_1 , V_220 , V_46 ) ;
F_11 ( V_1 , V_221 , ( V_160 << 16 ) | V_200 ) ;
V_46 = V_202 << 16 ;
V_46 |= V_203 ;
F_11 ( V_1 , V_222 , V_46 ) ;
F_11 ( V_1 , V_223 , V_46 ) ;
F_100 ( V_1 -> V_99 , V_140 -> clock * 1000 ) ;
F_11 ( V_1 , V_107 , 0 ) ;
}
static void F_101 ( struct V_95 * V_96 ,
struct V_119 * V_224 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
if ( F_32 ( ! V_1 -> V_91 ) )
return;
F_43 ( & V_1 -> V_106 ) ;
F_10 ( V_1 ) ;
F_44 ( & V_1 -> V_106 ) ;
}
static void F_102 ( struct V_95 * V_96 ,
struct V_119 * V_224 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
if ( V_96 -> V_116 -> V_190 ) {
F_32 ( F_103 ( V_96 ) != 0 ) ;
V_1 -> V_190 = V_96 -> V_116 -> V_190 ;
V_96 -> V_116 -> V_190 = NULL ;
}
}
static void F_104 ( struct V_95 * V_96 )
{
F_105 ( V_96 ) ;
}
static struct V_119 * F_106 ( struct V_95 * V_96 )
{
struct V_194 * V_225 ;
V_225 = F_84 ( sizeof( * V_225 ) , V_177 ) ;
if ( ! V_225 )
return NULL ;
F_107 ( V_96 , & V_225 -> V_6 ) ;
return & V_225 -> V_6 ;
}
static void F_108 ( struct V_95 * V_96 ,
struct V_119 * V_116 )
{
struct V_194 * V_195 = F_98 ( V_116 ) ;
F_109 ( & V_195 -> V_6 ) ;
F_83 ( V_195 ) ;
}
static bool F_110 ( struct V_110 * V_110 )
{
struct V_112 * V_113 = & V_110 -> V_6 ;
struct V_122 * V_116 = F_64 ( V_113 -> V_116 ) ;
T_3 V_163 ;
if ( ! V_116 -> V_93 )
return F_111 ( V_110 -> V_1 , V_110 -> V_14 , V_93 ) == 0 ;
V_163 = F_112 ( V_110 -> V_1 , V_110 -> V_14 ) ;
return V_163 == V_116 -> V_163 ;
}
static void F_113 ( struct V_1 * V_1 )
{
struct V_185 * V_186 = V_1 -> V_103 ;
struct V_95 * V_96 = & V_1 -> V_96 ;
unsigned long V_90 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_1 -> V_14 -> V_109 ; V_12 ++ ) {
if ( ! F_110 ( & V_1 -> V_52 [ V_12 ] ) )
return;
}
if ( V_1 -> V_190 ) {
F_33 ( & V_186 -> V_189 , V_90 ) ;
F_114 ( V_96 , V_1 -> V_190 ) ;
F_115 ( V_96 ) ;
V_1 -> V_190 = NULL ;
F_35 ( & V_186 -> V_189 , V_90 ) ;
}
if ( ! F_116 ( & V_1 -> V_182 ) )
F_117 ( & V_1 -> V_182 ) ;
}
static T_5 F_118 ( int V_108 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
struct V_95 * V_96 = & V_1 -> V_96 ;
T_1 V_226 ;
unsigned long V_90 ;
int V_13 = V_227 ;
F_33 ( & V_1 -> V_92 , V_90 ) ;
V_226 = F_119 ( V_1 , V_228 , V_229 ) ;
if ( V_226 )
F_34 ( V_1 , V_230 , V_226 , 1 ) ;
F_35 ( & V_1 -> V_92 , V_90 ) ;
if ( ! V_226 )
return V_227 ;
if ( V_226 & V_94 ) {
F_117 ( & V_1 -> V_111 ) ;
V_226 &= ~ V_94 ;
V_13 = V_231 ;
}
if ( V_226 & V_181 ) {
F_120 ( V_96 ) ;
F_113 ( V_1 ) ;
V_226 &= ~ V_181 ;
V_13 = V_231 ;
}
if ( V_226 )
F_14 ( L_11 , V_226 ) ;
return V_13 ;
}
static int F_121 ( struct V_1 * V_1 )
{
const struct V_232 * V_232 = V_1 -> V_14 ;
struct V_233 * V_97 = V_1 -> V_97 ;
struct V_185 * V_103 = V_1 -> V_103 ;
struct V_112 * V_234 = NULL , * V_235 = NULL , * V_113 , * V_236 ;
struct V_95 * V_96 = & V_1 -> V_96 ;
struct V_237 * V_238 ;
int V_13 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_232 -> V_109 ; V_12 ++ ) {
struct V_110 * V_110 = & V_1 -> V_52 [ V_12 ] ;
const struct V_51 * V_239 = V_110 -> V_14 ;
if ( V_239 -> type != V_240 &&
V_239 -> type != V_241 )
continue;
V_13 = F_122 ( V_1 -> V_103 , & V_110 -> V_6 ,
0 , & V_242 ,
V_239 -> V_69 -> V_243 ,
V_239 -> V_69 -> V_244 ,
V_239 -> type , NULL ) ;
if ( V_13 ) {
F_14 ( L_12 ) ;
goto V_245;
}
V_113 = & V_110 -> V_6 ;
F_123 ( V_113 , & V_246 ) ;
if ( V_113 -> type == V_240 )
V_234 = V_113 ;
else if ( V_113 -> type == V_241 )
V_235 = V_113 ;
}
V_13 = F_124 ( V_103 , V_96 , V_234 , V_235 ,
& V_247 , NULL ) ;
if ( V_13 )
goto V_245;
F_125 ( V_96 , & V_248 ) ;
for ( V_12 = 0 ; V_12 < V_232 -> V_109 ; V_12 ++ ) {
struct V_110 * V_110 = & V_1 -> V_52 [ V_12 ] ;
const struct V_51 * V_239 = V_110 -> V_14 ;
unsigned long V_249 = 1 << F_126 ( V_96 ) ;
if ( V_239 -> type != V_250 )
continue;
V_13 = F_122 ( V_1 -> V_103 , & V_110 -> V_6 ,
V_249 ,
& V_242 ,
V_239 -> V_69 -> V_243 ,
V_239 -> V_69 -> V_244 ,
V_239 -> type , NULL ) ;
if ( V_13 ) {
F_14 ( L_13 ) ;
goto V_251;
}
F_123 ( & V_110 -> V_6 , & V_246 ) ;
}
V_238 = F_127 ( V_97 -> V_252 , L_14 ) ;
if ( ! V_238 ) {
F_14 ( L_15 ,
V_97 -> V_252 -> V_253 ) ;
V_13 = - V_254 ;
goto V_251;
}
F_128 ( & V_1 -> V_111 ) ;
F_128 ( & V_1 -> V_182 ) ;
V_96 -> V_238 = V_238 ;
F_129 ( V_96 , & V_255 ) ;
return 0 ;
V_251:
F_105 ( V_96 ) ;
V_245:
F_130 (plane, tmp, &drm_dev->mode_config.plane_list,
head)
F_57 ( V_113 ) ;
return V_13 ;
}
static void F_131 ( struct V_1 * V_1 )
{
struct V_95 * V_96 = & V_1 -> V_96 ;
struct V_185 * V_103 = V_1 -> V_103 ;
struct V_112 * V_113 , * V_236 ;
F_132 ( V_96 ) ;
F_133 ( V_96 -> V_238 ) ;
F_130 (plane, tmp, &drm_dev->mode_config.plane_list,
head)
F_56 ( V_113 ) ;
F_105 ( V_96 ) ;
}
static int F_134 ( struct V_1 * V_1 )
{
const struct V_232 * V_232 = V_1 -> V_14 ;
const struct V_256 * V_257 = V_232 -> V_257 ;
struct V_258 * V_259 ;
int V_12 , V_13 ;
V_1 -> V_98 = F_135 ( V_1 -> V_97 , L_16 ) ;
if ( F_136 ( V_1 -> V_98 ) ) {
F_40 ( V_1 -> V_97 , L_17 ) ;
return F_137 ( V_1 -> V_98 ) ;
}
V_1 -> V_101 = F_135 ( V_1 -> V_97 , L_18 ) ;
if ( F_136 ( V_1 -> V_101 ) ) {
F_40 ( V_1 -> V_97 , L_19 ) ;
return F_137 ( V_1 -> V_101 ) ;
}
V_1 -> V_99 = F_135 ( V_1 -> V_97 , L_20 ) ;
if ( F_136 ( V_1 -> V_99 ) ) {
F_40 ( V_1 -> V_97 , L_21 ) ;
return F_137 ( V_1 -> V_99 ) ;
}
V_13 = F_138 ( V_1 -> V_99 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_22 ) ;
return V_13 ;
}
V_13 = F_139 ( V_1 -> V_98 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_23 ) ;
goto V_260;
}
V_13 = F_139 ( V_1 -> V_101 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_24 ) ;
goto V_100;
}
V_259 = F_140 ( V_1 -> V_97 , L_25 ) ;
if ( F_136 ( V_259 ) ) {
F_40 ( V_1 -> V_97 , L_26 ) ;
V_13 = F_137 ( V_259 ) ;
goto V_104;
}
F_141 ( V_259 ) ;
F_142 ( 10 , 20 ) ;
F_143 ( V_259 ) ;
memcpy ( V_1 -> V_5 , V_1 -> V_4 , V_1 -> V_105 ) ;
for ( V_12 = 0 ; V_12 < V_232 -> V_261 ; V_12 ++ )
F_1 ( V_1 , V_257 [ V_12 ] . V_2 , V_257 [ V_12 ] . V_262 ) ;
for ( V_12 = 0 ; V_12 < V_232 -> V_109 ; V_12 ++ ) {
const struct V_51 * V_52 = & V_232 -> V_52 [ V_12 ] ;
F_49 ( V_1 , V_52 , V_93 , 0 ) ;
}
F_10 ( V_1 ) ;
V_1 -> V_263 = F_140 ( V_1 -> V_97 , L_27 ) ;
if ( F_136 ( V_1 -> V_263 ) ) {
F_40 ( V_1 -> V_97 , L_28 ) ;
V_13 = F_137 ( V_1 -> V_263 ) ;
goto V_104;
}
F_141 ( V_1 -> V_263 ) ;
F_142 ( 10 , 20 ) ;
F_143 ( V_1 -> V_263 ) ;
F_47 ( V_1 -> V_98 ) ;
F_47 ( V_1 -> V_101 ) ;
V_1 -> V_91 = false ;
return 0 ;
V_104:
F_144 ( V_1 -> V_101 ) ;
V_100:
F_144 ( V_1 -> V_98 ) ;
V_260:
F_145 ( V_1 -> V_99 ) ;
return V_13 ;
}
static void F_146 ( struct V_1 * V_1 )
{
const struct V_232 * V_232 = V_1 -> V_14 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_232 -> V_109 ; V_12 ++ ) {
struct V_110 * V_110 = & V_1 -> V_52 [ V_12 ] ;
const struct V_51 * V_239 = & V_232 -> V_52 [ V_12 ] ;
V_110 -> V_14 = V_239 ;
V_110 -> V_1 = V_1 ;
}
}
static int F_147 ( struct V_233 * V_97 , struct V_233 * V_264 , void * V_14 )
{
struct V_265 * V_266 = F_148 ( V_97 ) ;
const struct V_232 * V_232 ;
struct V_185 * V_103 = V_14 ;
struct V_1 * V_1 ;
struct V_267 * V_268 ;
T_6 V_269 ;
int V_13 , V_108 ;
V_232 = F_149 ( V_97 ) ;
if ( ! V_232 )
return - V_270 ;
V_269 = sizeof( * V_1 ) + sizeof( * V_1 -> V_52 ) * V_232 -> V_109 ;
V_1 = F_150 ( V_97 , V_269 , V_177 ) ;
if ( ! V_1 )
return - V_271 ;
V_1 -> V_97 = V_97 ;
V_1 -> V_14 = V_232 ;
V_1 -> V_103 = V_103 ;
F_151 ( V_97 , V_1 ) ;
F_146 ( V_1 ) ;
V_268 = F_152 ( V_266 , V_272 , 0 ) ;
V_1 -> V_105 = F_153 ( V_268 ) ;
V_1 -> V_4 = F_154 ( V_97 , V_268 ) ;
if ( F_136 ( V_1 -> V_4 ) )
return F_137 ( V_1 -> V_4 ) ;
V_1 -> V_5 = F_150 ( V_97 , V_1 -> V_105 , V_177 ) ;
if ( ! V_1 -> V_5 )
return - V_271 ;
V_13 = F_134 ( V_1 ) ;
if ( V_13 < 0 ) {
F_40 ( & V_266 -> V_97 , L_29 , V_13 ) ;
return V_13 ;
}
V_108 = F_155 ( V_266 , 0 ) ;
if ( V_108 < 0 ) {
F_40 ( V_97 , L_30 ) ;
return V_108 ;
}
V_1 -> V_108 = ( unsigned int ) V_108 ;
F_156 ( & V_1 -> V_106 ) ;
F_156 ( & V_1 -> V_92 ) ;
F_157 ( & V_1 -> V_273 ) ;
V_13 = F_158 ( V_97 , V_1 -> V_108 , F_118 ,
V_274 , F_159 ( V_97 ) , V_1 ) ;
if ( V_13 )
return V_13 ;
F_53 ( V_1 -> V_108 ) ;
V_13 = F_121 ( V_1 ) ;
if ( V_13 )
return V_13 ;
F_160 ( & V_266 -> V_97 ) ;
return 0 ;
}
static void F_161 ( struct V_233 * V_97 , struct V_233 * V_264 , void * V_14 )
{
struct V_1 * V_1 = F_162 ( V_97 ) ;
F_163 ( V_97 ) ;
F_131 ( V_1 ) ;
}
