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
case V_20 :
case V_15 :
return true ;
default:
return false ;
}
}
static void F_14 ( struct V_1 * V_1 )
{
unsigned long V_33 ;
if ( F_15 ( ! V_1 -> V_34 ) )
return;
F_16 ( & V_1 -> V_35 , V_33 ) ;
F_7 ( V_1 , V_36 , V_37 ,
F_17 ( 1 ) ) ;
F_18 ( & V_1 -> V_35 , V_33 ) ;
}
static void F_19 ( struct V_1 * V_1 )
{
unsigned long V_33 ;
if ( F_15 ( ! V_1 -> V_34 ) )
return;
F_16 ( & V_1 -> V_35 , V_33 ) ;
F_7 ( V_1 , V_36 , V_37 ,
F_17 ( 0 ) ) ;
F_18 ( & V_1 -> V_35 , V_33 ) ;
}
static void F_20 ( struct V_38 * V_39 )
{
struct V_1 * V_1 = F_21 ( V_39 ) ;
int V_40 ;
if ( V_1 -> V_34 )
return;
V_40 = F_22 ( V_1 -> V_41 ) ;
if ( V_40 < 0 ) {
F_23 ( V_1 -> V_41 , L_2 , V_40 ) ;
return;
}
V_40 = F_24 ( V_1 -> V_42 ) ;
if ( V_40 < 0 ) {
F_23 ( V_1 -> V_41 , L_3 , V_40 ) ;
return;
}
V_40 = F_24 ( V_1 -> V_43 ) ;
if ( V_40 < 0 ) {
F_23 ( V_1 -> V_41 , L_4 , V_40 ) ;
goto V_44;
}
V_40 = F_24 ( V_1 -> V_45 ) ;
if ( V_40 < 0 ) {
F_23 ( V_1 -> V_41 , L_5 , V_40 ) ;
goto V_46;
}
V_40 = F_25 ( V_1 -> V_47 , V_1 -> V_41 ) ;
if ( V_40 ) {
F_23 ( V_1 -> V_41 , L_6 , V_40 ) ;
goto V_48;
}
V_1 -> V_34 = true ;
F_26 ( & V_1 -> V_49 ) ;
F_27 ( V_1 , V_50 , 0 ) ;
F_28 ( & V_1 -> V_49 ) ;
F_29 ( V_1 -> V_51 ) ;
F_30 ( V_1 -> V_47 , V_1 -> V_52 ) ;
return;
V_48:
F_31 ( V_1 -> V_45 ) ;
V_46:
F_31 ( V_1 -> V_43 ) ;
V_44:
F_31 ( V_1 -> V_42 ) ;
}
static void F_32 ( struct V_38 * V_39 )
{
struct V_1 * V_1 = F_21 ( V_39 ) ;
if ( ! V_1 -> V_34 )
return;
F_33 ( V_39 -> V_41 , V_1 -> V_52 ) ;
F_34 ( & V_1 -> V_53 ) ;
F_14 ( V_1 ) ;
F_26 ( & V_1 -> V_49 ) ;
F_27 ( V_1 , V_50 , 1 ) ;
F_28 ( & V_1 -> V_49 ) ;
F_35 ( & V_1 -> V_53 ) ;
F_19 ( V_1 ) ;
F_36 ( V_1 -> V_51 ) ;
V_1 -> V_34 = false ;
F_37 ( V_1 -> V_47 , V_1 -> V_41 ) ;
F_31 ( V_1 -> V_43 ) ;
F_31 ( V_1 -> V_45 ) ;
F_31 ( V_1 -> V_42 ) ;
F_38 ( V_1 -> V_41 ) ;
}
static struct V_54 * F_39 ( struct V_55 * V_55 )
{
struct V_56 * V_57 ;
struct V_56 * V_58 = V_55 -> V_58 ;
if ( F_40 ( & V_55 -> V_59 ) )
return V_58 ? V_58 -> V_60 : NULL ;
V_57 = F_41 ( & V_55 -> V_59 , struct V_56 , V_61 ) ;
return V_57 ? V_57 -> V_60 : NULL ;
}
static int F_42 ( struct V_55 * V_55 ,
struct V_54 * V_60 , T_2 V_62 ,
struct V_63 * V_64 )
{
struct V_56 * V_65 ;
V_65 = F_43 ( sizeof( * V_65 ) , V_66 ) ;
if ( ! V_65 )
return - V_67 ;
V_65 -> V_60 = V_60 ;
V_65 -> V_62 = V_62 ;
V_65 -> V_64 = V_64 ;
F_44 ( & V_65 -> V_61 , & V_55 -> V_59 ) ;
return 0 ;
}
static int F_45 ( struct V_68 * V_69 ,
struct V_38 * V_39 ,
struct V_54 * V_60 , int V_70 ,
int V_71 , unsigned int V_72 ,
unsigned int V_73 , T_1 V_74 ,
T_1 V_75 , T_1 V_76 ,
T_1 V_77 ,
struct V_63 * V_64 )
{
struct V_55 * V_55 = F_46 ( V_69 ) ;
const struct V_78 * V_79 = V_55 -> V_80 ;
struct V_1 * V_1 = F_21 ( V_39 ) ;
struct V_81 * V_82 ;
struct V_83 * V_84 ;
unsigned long V_2 ;
unsigned int V_85 ;
unsigned int V_86 ;
unsigned int V_87 ;
unsigned int V_88 ;
unsigned int V_89 ;
T_2 V_62 ;
enum V_18 V_13 ;
T_1 V_90 ;
bool V_91 ;
bool V_92 ;
bool V_93 ;
int V_40 ;
struct V_94 V_95 = {
. V_96 = V_70 ,
. y1 = V_71 ,
. V_97 = V_70 + V_72 ,
. V_98 = V_71 + V_73 ,
} ;
struct V_94 V_99 = {
. V_96 = V_74 ,
. y1 = V_75 ,
. V_97 = V_74 + V_76 ,
. V_98 = V_75 + V_77 ,
} ;
const struct V_94 V_100 = {
. V_97 = V_39 -> V_101 . V_102 ,
. V_98 = V_39 -> V_101 . V_103 ,
} ;
bool V_104 = V_69 -> type != V_105 ;
V_40 = F_47 ( V_69 , V_39 , V_60 ,
& V_99 , & V_95 , & V_100 ,
V_106 ,
V_106 ,
V_104 , false , & V_93 ) ;
if ( V_40 )
return V_40 ;
if ( ! V_93 )
return 0 ;
V_91 = F_13 ( V_60 -> V_107 ) ;
V_92 = F_10 ( V_60 -> V_107 ) ;
V_13 = F_11 ( V_60 -> V_107 ) ;
if ( V_13 < 0 )
return V_13 ;
V_82 = F_48 ( V_60 , 0 ) ;
if ( ! V_82 ) {
F_12 ( L_7 ) ;
return - V_32 ;
}
V_84 = F_49 ( V_82 ) ;
V_85 = ( V_99 . V_97 - V_99 . V_96 ) >> 16 ;
V_86 = ( V_99 . V_98 - V_99 . y1 ) >> 16 ;
V_70 = F_50 ( 0 , V_70 ) ;
V_71 = F_50 ( 0 , V_71 ) ;
V_87 = V_70 + V_39 -> V_101 . V_108 - V_39 -> V_101 . V_109 ;
V_88 = V_71 + V_39 -> V_101 . V_110 - V_39 -> V_101 . V_111 ;
V_2 = ( V_99 . V_96 >> 16 ) * ( V_60 -> V_112 >> 3 ) ;
V_2 += ( V_99 . y1 >> 16 ) * V_60 -> V_113 [ 0 ] ;
V_62 = V_84 -> V_114 + V_2 ;
V_89 = V_60 -> V_113 [ 0 ] / ( V_60 -> V_112 >> 3 ) ;
F_51 ( & V_1 -> V_115 ) ;
if ( V_60 != F_39 ( V_55 ) ) {
V_40 = F_52 ( V_69 -> V_41 , V_1 -> V_52 ) ;
if ( V_40 ) {
F_12 ( L_8 , V_40 ) ;
F_53 ( & V_1 -> V_115 ) ;
return V_40 ;
}
F_54 ( V_60 ) ;
V_40 = F_42 ( V_55 , V_60 , V_62 , V_64 ) ;
if ( V_40 ) {
F_55 ( V_69 -> V_41 , V_1 -> V_52 ) ;
F_53 ( & V_1 -> V_115 ) ;
return V_40 ;
}
V_1 -> V_116 = true ;
}
F_53 ( & V_1 -> V_115 ) ;
F_26 ( & V_1 -> V_49 ) ;
F_56 ( V_1 , V_79 , V_13 , V_13 ) ;
F_56 ( V_1 , V_79 , V_117 , V_89 ) ;
F_56 ( V_1 , V_79 , V_62 , V_62 ) ;
V_90 = ( V_86 - 1 ) << 16 ;
V_90 |= ( V_85 - 1 ) & 0xffff ;
F_56 ( V_1 , V_79 , V_118 , V_90 ) ;
F_56 ( V_1 , V_79 , V_119 , V_90 ) ;
V_90 = ( V_88 - 1 ) << 16 ;
V_90 |= ( V_87 - 1 ) & 0xffff ;
F_56 ( V_1 , V_79 , V_120 , V_90 ) ;
F_56 ( V_1 , V_79 , V_92 , V_92 ) ;
if ( V_91 ) {
F_56 ( V_1 , V_79 , V_121 ,
F_57 ( V_122 ) ) ;
V_90 = F_58 ( 1 ) | F_59 ( V_123 ) |
F_60 ( V_124 ) |
F_61 ( V_125 ) |
F_62 ( V_126 ) |
F_63 ( V_127 ) ;
F_56 ( V_1 , V_79 , V_128 , V_90 ) ;
} else {
F_56 ( V_1 , V_79 , V_128 , F_58 ( 0 ) ) ;
}
F_56 ( V_1 , V_79 , V_129 , 1 ) ;
F_6 ( V_1 ) ;
F_28 ( & V_1 -> V_49 ) ;
return 0 ;
}
static int F_64 ( struct V_68 * V_69 , struct V_38 * V_39 ,
struct V_54 * V_60 , int V_70 , int V_71 ,
unsigned int V_72 , unsigned int V_73 ,
T_1 V_74 , T_1 V_75 , T_1 V_76 ,
T_1 V_77 )
{
return F_45 ( V_69 , V_39 , V_60 , V_70 , V_71 , V_72 ,
V_73 , V_74 , V_75 , V_76 , V_77 ,
NULL ) ;
}
static int F_65 ( struct V_38 * V_39 ,
struct V_63 * V_64 )
{
unsigned int V_72 , V_73 ;
V_72 = V_39 -> V_130 -> V_60 -> V_131 - V_39 -> V_132 ;
V_73 = V_39 -> V_130 -> V_60 -> V_133 - V_39 -> V_134 ;
return F_45 ( V_39 -> V_130 , V_39 , V_39 -> V_130 -> V_60 ,
0 , 0 , V_72 , V_73 , V_39 -> V_132 << 16 ,
V_39 -> V_134 << 16 , V_72 << 16 ,
V_73 << 16 , V_64 ) ;
}
static int F_66 ( struct V_68 * V_69 )
{
struct V_55 * V_55 = F_46 ( V_69 ) ;
const struct V_78 * V_79 = V_55 -> V_80 ;
struct V_1 * V_1 ;
int V_40 ;
if ( ! V_69 -> V_39 )
return 0 ;
V_1 = F_21 ( V_69 -> V_39 ) ;
V_40 = F_52 ( V_69 -> V_41 , V_1 -> V_52 ) ;
if ( V_40 ) {
F_12 ( L_8 , V_40 ) ;
return V_40 ;
}
F_51 ( & V_1 -> V_115 ) ;
V_40 = F_42 ( V_55 , NULL , 0 , NULL ) ;
if ( V_40 ) {
F_55 ( V_69 -> V_41 , V_1 -> V_52 ) ;
F_53 ( & V_1 -> V_115 ) ;
return V_40 ;
}
V_1 -> V_116 = true ;
F_53 ( & V_1 -> V_115 ) ;
F_26 ( & V_1 -> V_49 ) ;
F_56 ( V_1 , V_79 , V_129 , 0 ) ;
F_6 ( V_1 ) ;
F_28 ( & V_1 -> V_49 ) ;
return 0 ;
}
static void F_67 ( struct V_68 * V_69 )
{
F_66 ( V_69 ) ;
F_68 ( V_69 ) ;
}
int F_69 ( struct V_38 * V_39 ,
int V_135 ,
int V_136 )
{
struct V_1 * V_1 = F_21 ( V_39 ) ;
V_1 -> V_135 = V_135 ;
V_1 -> V_137 = V_136 ;
return 0 ;
}
static int F_70 ( struct V_38 * V_39 )
{
struct V_1 * V_1 = F_21 ( V_39 ) ;
unsigned long V_33 ;
if ( ! V_1 -> V_34 )
return - V_138 ;
F_16 ( & V_1 -> V_35 , V_33 ) ;
F_7 ( V_1 , V_36 , V_139 , F_71 ( 1 ) ) ;
F_18 ( & V_1 -> V_35 , V_33 ) ;
return 0 ;
}
static void F_72 ( struct V_38 * V_39 )
{
struct V_1 * V_1 = F_21 ( V_39 ) ;
unsigned long V_33 ;
if ( ! V_1 -> V_34 )
return;
F_16 ( & V_1 -> V_35 , V_33 ) ;
F_7 ( V_1 , V_36 , V_139 , F_71 ( 0 ) ) ;
F_18 ( & V_1 -> V_35 , V_33 ) ;
}
static void F_73 ( struct V_38 * V_39 , int V_101 )
{
F_74 ( L_9 , V_39 -> V_6 . V_140 , V_101 ) ;
switch ( V_101 ) {
case V_141 :
F_20 ( V_39 ) ;
break;
case V_142 :
case V_143 :
case V_144 :
F_32 ( V_39 ) ;
break;
default:
F_74 ( L_10 , V_101 ) ;
break;
}
}
static void F_75 ( struct V_38 * V_39 )
{
F_73 ( V_39 , V_141 ) ;
}
static bool F_76 ( struct V_38 * V_39 ,
const struct V_145 * V_101 ,
struct V_145 * V_146 )
{
if ( V_146 -> V_108 == 0 || V_146 -> V_110 == 0 )
return false ;
return true ;
}
static int F_77 ( struct V_38 * V_39 , int V_132 , int V_134 ,
struct V_54 * V_147 )
{
int V_40 ;
V_39 -> V_132 = V_132 ;
V_39 -> V_134 = V_134 ;
V_40 = F_65 ( V_39 , NULL ) ;
if ( V_40 < 0 ) {
F_12 ( L_11 ) ;
return V_40 ;
}
return 0 ;
}
static int F_78 ( struct V_38 * V_39 ,
struct V_145 * V_101 ,
struct V_145 * V_146 ,
int V_132 , int V_134 , struct V_54 * V_60 )
{
struct V_1 * V_1 = F_21 ( V_39 ) ;
T_3 V_148 = V_146 -> V_149 - V_146 -> V_109 ;
T_3 V_102 = V_146 -> V_102 ;
T_3 V_108 = V_146 -> V_108 ;
T_3 V_150 = V_146 -> V_108 - V_146 -> V_109 ;
T_3 V_151 = V_150 + V_102 ;
T_3 V_103 = V_146 -> V_103 ;
T_3 V_110 = V_146 -> V_110 ;
T_3 V_152 = V_146 -> V_153 - V_146 -> V_111 ;
T_3 V_154 = V_146 -> V_110 - V_146 -> V_111 ;
T_3 V_155 = V_154 + V_103 ;
int V_40 , V_156 ;
T_1 V_90 ;
F_31 ( V_1 -> V_43 ) ;
switch ( V_1 -> V_135 ) {
case V_157 :
F_27 ( V_1 , V_158 , 1 ) ;
break;
case V_159 :
F_27 ( V_1 , V_160 , 1 ) ;
break;
case V_161 :
F_27 ( V_1 , V_162 , 1 ) ;
break;
default:
F_12 ( L_12 ,
V_1 -> V_135 ) ;
V_40 = - V_32 ;
goto V_163;
} ;
F_27 ( V_1 , V_136 , V_1 -> V_137 ) ;
V_90 = 0x8 ;
V_90 |= ( V_146 -> V_33 & V_164 ) ? 0 : 1 ;
V_90 |= ( V_146 -> V_33 & V_165 ) ? 0 : ( 1 << 1 ) ;
F_27 ( V_1 , V_166 , V_90 ) ;
F_27 ( V_1 , V_167 , ( V_108 << 16 ) | V_148 ) ;
V_90 = V_150 << 16 ;
V_90 |= V_151 ;
F_27 ( V_1 , V_168 , V_90 ) ;
F_27 ( V_1 , V_169 , V_90 ) ;
F_27 ( V_1 , V_170 , ( V_110 << 16 ) | V_152 ) ;
V_90 = V_154 << 16 ;
V_90 |= V_155 ;
F_27 ( V_1 , V_171 , V_90 ) ;
F_27 ( V_1 , V_172 , V_90 ) ;
V_40 = F_77 ( V_39 , V_132 , V_134 , V_60 ) ;
if ( V_40 )
goto V_163;
F_79 ( V_1 -> V_173 ) ;
F_80 ( 10 , 20 ) ;
F_81 ( V_1 -> V_173 ) ;
F_82 ( V_1 -> V_43 , V_146 -> clock * 1000 ) ;
V_163:
V_156 = F_24 ( V_1 -> V_43 ) ;
if ( V_156 < 0 ) {
F_23 ( V_1 -> V_41 , L_4 , V_156 ) ;
return V_156 ;
}
return V_40 ;
}
static void F_83 ( struct V_38 * V_39 )
{
}
static int F_84 ( struct V_38 * V_39 ,
struct V_54 * V_60 ,
struct V_63 * V_64 ,
T_1 V_174 )
{
struct V_1 * V_1 = F_21 ( V_39 ) ;
struct V_54 * V_147 = V_39 -> V_130 -> V_60 ;
int V_40 ;
if ( ! V_1 -> V_34 ) {
F_85 ( L_13 ) ;
return 0 ;
}
V_39 -> V_130 -> V_60 = V_60 ;
V_40 = F_65 ( V_39 , V_64 ) ;
if ( V_40 )
V_39 -> V_130 -> V_60 = V_147 ;
return V_40 ;
}
static void F_86 ( struct V_55 * V_55 ,
struct V_56 * V_65 )
{
struct V_1 * V_1 = V_55 -> V_1 ;
struct V_38 * V_39 = & V_1 -> V_39 ;
struct V_175 * V_176 = V_39 -> V_41 ;
unsigned long V_33 ;
if ( V_65 -> V_64 ) {
F_16 ( & V_176 -> V_177 , V_33 ) ;
F_87 ( V_176 , - 1 , V_65 -> V_64 ) ;
F_18 ( & V_176 -> V_177 , V_33 ) ;
}
F_88 ( & V_65 -> V_61 ) ;
F_55 ( V_39 -> V_41 , V_1 -> V_52 ) ;
}
static void F_89 ( struct V_38 * V_39 )
{
F_90 ( V_39 ) ;
}
static bool F_91 ( struct V_55 * V_55 ,
struct V_56 * V_65 )
{
bool V_58 = false ;
if ( V_65 -> V_60 ) {
T_2 V_62 ;
V_62 = F_92 ( V_55 -> V_1 , V_55 -> V_80 ) ;
V_58 = ( V_62 == V_65 -> V_62 ) ;
} else {
bool V_178 ;
V_178 = F_93 ( V_55 -> V_1 , V_55 -> V_80 , V_129 ) ;
V_58 = ( V_178 == 0 ) ;
}
return V_58 ;
}
static void F_94 ( struct V_56 * V_65 )
{
struct V_54 * V_60 = V_65 -> V_60 ;
if ( V_60 )
F_95 ( V_60 ) ;
F_96 ( V_65 ) ;
}
static void F_97 ( struct V_55 * V_55 )
{
struct V_56 * V_65 , * V_179 , * V_180 = NULL ;
F_98 (state, &vop_win->pending, head)
if ( F_91 ( V_55 , V_65 ) ) {
V_180 = V_65 ;
break;
}
if ( ! V_180 )
return;
F_99 (state, n, &vop_win->pending, head) {
if ( V_65 == V_180 )
break;
F_86 ( V_55 , V_65 ) ;
F_94 ( V_65 ) ;
}
F_86 ( V_55 , V_180 ) ;
if ( V_55 -> V_58 )
F_94 ( V_55 -> V_58 ) ;
V_55 -> V_58 = V_180 ;
}
static bool F_100 ( struct V_55 * V_55 )
{
return ! F_40 ( & V_55 -> V_59 ) ;
}
static T_4 F_101 ( int V_51 , void * V_80 )
{
struct V_1 * V_1 = V_80 ;
const struct V_181 * V_181 = V_1 -> V_80 ;
unsigned int V_182 ;
F_51 ( & V_1 -> V_115 ) ;
if ( ! V_1 -> V_116 )
goto V_183;
V_1 -> V_116 = false ;
for ( V_182 = 0 ; V_182 < V_181 -> V_184 ; V_182 ++ ) {
struct V_55 * V_55 = & V_1 -> V_79 [ V_182 ] ;
F_97 ( V_55 ) ;
if ( F_100 ( V_55 ) )
V_1 -> V_116 = true ;
}
V_183:
F_53 ( & V_1 -> V_115 ) ;
return V_185 ;
}
static T_4 F_102 ( int V_51 , void * V_80 )
{
struct V_1 * V_1 = V_80 ;
T_1 V_186 , V_187 ;
unsigned long V_33 ;
int V_40 = V_188 ;
F_16 ( & V_1 -> V_35 , V_33 ) ;
V_186 = F_3 ( V_1 , V_36 ) ;
V_187 = V_186 & V_189 ;
if ( V_187 )
F_1 ( V_1 , V_36 ,
V_186 | ( V_187 << V_190 ) ) ;
F_18 ( & V_1 -> V_35 , V_33 ) ;
if ( ! V_187 )
return V_188 ;
if ( V_187 & V_191 ) {
F_103 ( & V_1 -> V_53 ) ;
V_187 &= ~ V_191 ;
V_40 = V_185 ;
}
if ( V_187 & V_192 ) {
F_104 ( V_1 -> V_47 , V_1 -> V_52 ) ;
V_187 &= ~ V_192 ;
V_40 = ( V_1 -> V_116 ) ? V_193 : V_185 ;
}
if ( V_187 )
F_12 ( L_14 , V_187 ) ;
return V_40 ;
}
static int F_105 ( struct V_1 * V_1 )
{
const struct V_181 * V_181 = V_1 -> V_80 ;
struct V_194 * V_41 = V_1 -> V_41 ;
struct V_175 * V_47 = V_1 -> V_47 ;
struct V_68 * V_130 = NULL , * V_195 = NULL , * V_69 ;
struct V_38 * V_39 = & V_1 -> V_39 ;
struct V_196 * V_197 ;
int V_40 ;
int V_182 ;
for ( V_182 = 0 ; V_182 < V_181 -> V_184 ; V_182 ++ ) {
struct V_55 * V_55 = & V_1 -> V_79 [ V_182 ] ;
const struct V_78 * V_198 = V_55 -> V_80 ;
if ( V_198 -> type != V_105 &&
V_198 -> type != V_199 )
continue;
V_40 = F_106 ( V_1 -> V_47 , & V_55 -> V_6 ,
0 , & V_200 ,
V_198 -> V_201 -> V_202 ,
V_198 -> V_201 -> V_203 ,
V_198 -> type ) ;
if ( V_40 ) {
F_12 ( L_15 ) ;
goto V_204;
}
V_69 = & V_55 -> V_6 ;
if ( V_69 -> type == V_105 )
V_130 = V_69 ;
else if ( V_69 -> type == V_199 )
V_195 = V_69 ;
}
V_40 = F_107 ( V_47 , V_39 , V_130 , V_195 ,
& V_205 ) ;
if ( V_40 )
return V_40 ;
F_108 ( V_39 , & V_206 ) ;
for ( V_182 = 0 ; V_182 < V_181 -> V_184 ; V_182 ++ ) {
struct V_55 * V_55 = & V_1 -> V_79 [ V_182 ] ;
const struct V_78 * V_198 = V_55 -> V_80 ;
unsigned long V_207 = 1 << F_109 ( V_39 ) ;
if ( V_198 -> type != V_208 )
continue;
V_40 = F_106 ( V_1 -> V_47 , & V_55 -> V_6 ,
V_207 ,
& V_200 ,
V_198 -> V_201 -> V_202 ,
V_198 -> V_201 -> V_203 ,
V_198 -> type ) ;
if ( V_40 ) {
F_12 ( L_16 ) ;
goto V_209;
}
}
V_197 = F_110 ( V_41 -> V_210 , L_17 ) ;
if ( ! V_197 ) {
F_12 ( L_18 ,
V_41 -> V_210 -> V_211 ) ;
goto V_209;
}
F_111 ( & V_1 -> V_53 ) ;
V_39 -> V_197 = V_197 ;
V_1 -> V_52 = F_109 ( V_39 ) ;
F_112 ( V_47 , & V_212 , V_1 -> V_52 ) ;
return 0 ;
V_209:
F_90 ( V_39 ) ;
V_204:
F_98 (plane, &drm_dev->mode_config.plane_list, head)
F_68 ( V_69 ) ;
return V_40 ;
}
static void F_113 ( struct V_1 * V_1 )
{
struct V_38 * V_39 = & V_1 -> V_39 ;
F_114 ( V_1 -> V_47 , V_1 -> V_52 ) ;
F_115 ( V_39 -> V_197 ) ;
F_90 ( V_39 ) ;
}
static int F_116 ( struct V_1 * V_1 )
{
const struct V_181 * V_181 = V_1 -> V_80 ;
const struct V_213 * V_214 = V_181 -> V_214 ;
struct V_215 * V_216 ;
int V_182 , V_40 ;
V_1 -> V_42 = F_117 ( V_1 -> V_41 , L_19 ) ;
if ( F_118 ( V_1 -> V_42 ) ) {
F_23 ( V_1 -> V_41 , L_20 ) ;
return F_119 ( V_1 -> V_42 ) ;
}
V_1 -> V_45 = F_117 ( V_1 -> V_41 , L_21 ) ;
if ( F_118 ( V_1 -> V_45 ) ) {
F_23 ( V_1 -> V_41 , L_22 ) ;
return F_119 ( V_1 -> V_45 ) ;
}
V_1 -> V_43 = F_117 ( V_1 -> V_41 , L_23 ) ;
if ( F_118 ( V_1 -> V_43 ) ) {
F_23 ( V_1 -> V_41 , L_24 ) ;
return F_119 ( V_1 -> V_43 ) ;
}
V_40 = F_120 ( V_1 -> V_42 ) ;
if ( V_40 < 0 ) {
F_23 ( V_1 -> V_41 , L_25 ) ;
return V_40 ;
}
V_40 = F_120 ( V_1 -> V_43 ) ;
if ( V_40 < 0 ) {
F_23 ( V_1 -> V_41 , L_26 ) ;
goto V_217;
}
V_40 = F_120 ( V_1 -> V_45 ) ;
if ( V_40 < 0 ) {
F_23 ( V_1 -> V_41 , L_27 ) ;
goto V_218;
}
V_40 = F_24 ( V_1 -> V_42 ) ;
if ( V_40 < 0 ) {
F_23 ( V_1 -> V_41 , L_27 ) ;
goto V_219;
}
V_216 = F_121 ( V_1 -> V_41 , L_28 ) ;
if ( F_118 ( V_216 ) ) {
F_23 ( V_1 -> V_41 , L_29 ) ;
V_40 = F_119 ( V_216 ) ;
goto V_44;
}
F_79 ( V_216 ) ;
F_80 ( 10 , 20 ) ;
F_81 ( V_216 ) ;
memcpy ( V_1 -> V_5 , V_1 -> V_4 , V_1 -> V_220 ) ;
for ( V_182 = 0 ; V_182 < V_181 -> V_221 ; V_182 ++ )
F_1 ( V_1 , V_214 [ V_182 ] . V_2 , V_214 [ V_182 ] . V_222 ) ;
for ( V_182 = 0 ; V_182 < V_181 -> V_184 ; V_182 ++ ) {
const struct V_78 * V_79 = & V_181 -> V_79 [ V_182 ] ;
F_56 ( V_1 , V_79 , V_129 , 0 ) ;
}
F_6 ( V_1 ) ;
V_1 -> V_173 = F_121 ( V_1 -> V_41 , L_30 ) ;
if ( F_118 ( V_1 -> V_173 ) ) {
F_23 ( V_1 -> V_41 , L_31 ) ;
V_40 = F_119 ( V_1 -> V_173 ) ;
goto V_219;
}
F_79 ( V_1 -> V_173 ) ;
F_80 ( 10 , 20 ) ;
F_81 ( V_1 -> V_173 ) ;
F_31 ( V_1 -> V_42 ) ;
V_1 -> V_34 = false ;
return 0 ;
V_44:
F_31 ( V_1 -> V_42 ) ;
V_219:
F_122 ( V_1 -> V_45 ) ;
V_218:
F_122 ( V_1 -> V_43 ) ;
V_217:
F_122 ( V_1 -> V_42 ) ;
return V_40 ;
}
static void F_123 ( struct V_1 * V_1 )
{
const struct V_181 * V_181 = V_1 -> V_80 ;
unsigned int V_182 ;
for ( V_182 = 0 ; V_182 < V_181 -> V_184 ; V_182 ++ ) {
struct V_55 * V_55 = & V_1 -> V_79 [ V_182 ] ;
const struct V_78 * V_198 = & V_181 -> V_79 [ V_182 ] ;
V_55 -> V_80 = V_198 ;
V_55 -> V_1 = V_1 ;
F_124 ( & V_55 -> V_59 ) ;
}
}
static int F_125 ( struct V_194 * V_41 , struct V_194 * V_223 , void * V_80 )
{
struct V_224 * V_225 = F_126 ( V_41 ) ;
const struct V_226 * V_227 ;
const struct V_181 * V_181 ;
struct V_175 * V_47 = V_80 ;
struct V_1 * V_1 ;
struct V_228 * V_229 ;
T_5 V_230 ;
int V_40 , V_51 ;
V_227 = F_127 ( V_231 , V_41 ) ;
V_181 = V_227 -> V_80 ;
if ( ! V_181 )
return - V_232 ;
V_230 = sizeof( * V_1 ) + sizeof( * V_1 -> V_79 ) * V_181 -> V_184 ;
V_1 = F_128 ( V_41 , V_230 , V_66 ) ;
if ( ! V_1 )
return - V_67 ;
V_1 -> V_41 = V_41 ;
V_1 -> V_80 = V_181 ;
V_1 -> V_47 = V_47 ;
F_129 ( V_41 , V_1 ) ;
F_123 ( V_1 ) ;
V_229 = F_130 ( V_225 , V_233 , 0 ) ;
V_1 -> V_220 = F_131 ( V_229 ) ;
V_1 -> V_4 = F_132 ( V_41 , V_229 ) ;
if ( F_118 ( V_1 -> V_4 ) )
return F_119 ( V_1 -> V_4 ) ;
V_1 -> V_5 = F_128 ( V_41 , V_1 -> V_220 , V_66 ) ;
if ( ! V_1 -> V_5 )
return - V_67 ;
V_40 = F_116 ( V_1 ) ;
if ( V_40 < 0 ) {
F_23 ( & V_225 -> V_41 , L_32 , V_40 ) ;
return V_40 ;
}
V_51 = F_133 ( V_225 , 0 ) ;
if ( V_51 < 0 ) {
F_23 ( V_41 , L_33 ) ;
return V_51 ;
}
V_1 -> V_51 = ( unsigned int ) V_51 ;
F_134 ( & V_1 -> V_49 ) ;
F_134 ( & V_1 -> V_35 ) ;
F_135 ( & V_1 -> V_115 ) ;
V_40 = F_136 ( V_41 , V_1 -> V_51 , F_102 , F_101 ,
V_234 , F_137 ( V_41 ) , V_1 ) ;
if ( V_40 )
return V_40 ;
F_36 ( V_1 -> V_51 ) ;
V_40 = F_105 ( V_1 ) ;
if ( V_40 )
return V_40 ;
F_138 ( & V_225 -> V_41 ) ;
return 0 ;
}
static void F_139 ( struct V_194 * V_41 , struct V_194 * V_223 , void * V_80 )
{
struct V_1 * V_1 = F_140 ( V_41 ) ;
F_141 ( V_41 ) ;
F_113 ( V_1 ) ;
}
static int F_142 ( struct V_224 * V_225 )
{
struct V_194 * V_41 = & V_225 -> V_41 ;
if ( ! V_41 -> V_210 ) {
F_23 ( V_41 , L_34 ) ;
return - V_232 ;
}
return F_143 ( V_41 , & V_235 ) ;
}
static int F_144 ( struct V_224 * V_225 )
{
F_145 ( & V_225 -> V_41 , & V_235 ) ;
return 0 ;
}
