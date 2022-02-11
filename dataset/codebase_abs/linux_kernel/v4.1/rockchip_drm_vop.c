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
static enum V_13 F_10 ( T_1 V_14 )
{
switch ( V_14 ) {
case V_15 :
case V_16 :
return V_17 ;
case V_18 :
return V_19 ;
case V_20 :
return V_21 ;
case V_22 :
return V_23 ;
case V_24 :
return V_25 ;
case V_26 :
return V_27 ;
default:
F_11 ( L_1 , V_14 ) ;
return - V_28 ;
}
}
static bool F_12 ( T_1 V_14 )
{
switch ( V_14 ) {
case V_16 :
return true ;
default:
return false ;
}
}
static void F_13 ( struct V_1 * V_1 )
{
unsigned long V_29 ;
if ( F_14 ( ! V_1 -> V_30 ) )
return;
F_15 ( & V_1 -> V_31 , V_29 ) ;
F_7 ( V_1 , V_32 , V_33 ,
F_16 ( 1 ) ) ;
F_17 ( & V_1 -> V_31 , V_29 ) ;
}
static void F_18 ( struct V_1 * V_1 )
{
unsigned long V_29 ;
if ( F_14 ( ! V_1 -> V_30 ) )
return;
F_15 ( & V_1 -> V_31 , V_29 ) ;
F_7 ( V_1 , V_32 , V_33 ,
F_16 ( 0 ) ) ;
F_17 ( & V_1 -> V_31 , V_29 ) ;
}
static void F_19 ( struct V_34 * V_35 )
{
struct V_1 * V_1 = F_20 ( V_35 ) ;
int V_36 ;
if ( V_1 -> V_30 )
return;
V_36 = F_21 ( V_1 -> V_37 ) ;
if ( V_36 < 0 ) {
F_22 ( V_1 -> V_37 , L_2 , V_36 ) ;
return;
}
V_36 = F_23 ( V_1 -> V_38 ) ;
if ( V_36 < 0 ) {
F_22 ( V_1 -> V_37 , L_3 , V_36 ) ;
return;
}
V_36 = F_23 ( V_1 -> V_39 ) ;
if ( V_36 < 0 ) {
F_22 ( V_1 -> V_37 , L_4 , V_36 ) ;
goto V_40;
}
V_36 = F_23 ( V_1 -> V_41 ) ;
if ( V_36 < 0 ) {
F_22 ( V_1 -> V_37 , L_5 , V_36 ) ;
goto V_42;
}
V_36 = F_24 ( V_1 -> V_43 , V_1 -> V_37 ) ;
if ( V_36 ) {
F_22 ( V_1 -> V_37 , L_6 , V_36 ) ;
goto V_44;
}
V_1 -> V_30 = true ;
F_25 ( & V_1 -> V_45 ) ;
F_26 ( V_1 , V_46 , 0 ) ;
F_27 ( & V_1 -> V_45 ) ;
F_28 ( V_1 -> V_47 ) ;
F_29 ( V_1 -> V_43 , V_1 -> V_48 ) ;
return;
V_44:
F_30 ( V_1 -> V_41 ) ;
V_42:
F_30 ( V_1 -> V_39 ) ;
V_40:
F_30 ( V_1 -> V_38 ) ;
}
static void F_31 ( struct V_34 * V_35 )
{
struct V_1 * V_1 = F_20 ( V_35 ) ;
if ( ! V_1 -> V_30 )
return;
F_32 ( V_35 -> V_37 , V_1 -> V_48 ) ;
F_33 ( & V_1 -> V_49 ) ;
F_13 ( V_1 ) ;
F_25 ( & V_1 -> V_45 ) ;
F_26 ( V_1 , V_46 , 1 ) ;
F_27 ( & V_1 -> V_45 ) ;
F_34 ( & V_1 -> V_49 ) ;
F_18 ( V_1 ) ;
F_35 ( V_1 -> V_47 ) ;
V_1 -> V_30 = false ;
F_36 ( V_1 -> V_43 , V_1 -> V_37 ) ;
F_30 ( V_1 -> V_39 ) ;
F_30 ( V_1 -> V_41 ) ;
F_30 ( V_1 -> V_38 ) ;
F_37 ( V_1 -> V_37 ) ;
}
static struct V_50 * F_38 ( struct V_51 * V_51 )
{
struct V_52 * V_53 ;
struct V_52 * V_54 = V_51 -> V_54 ;
if ( F_39 ( & V_51 -> V_55 ) )
return V_54 ? V_54 -> V_56 : NULL ;
V_53 = F_40 ( & V_51 -> V_55 , struct V_52 , V_57 ) ;
return V_53 ? V_53 -> V_56 : NULL ;
}
static int F_41 ( struct V_51 * V_51 ,
struct V_50 * V_56 , T_2 V_58 ,
struct V_59 * V_60 )
{
struct V_52 * V_61 ;
V_61 = F_42 ( sizeof( * V_61 ) , V_62 ) ;
if ( ! V_61 )
return - V_63 ;
V_61 -> V_56 = V_56 ;
V_61 -> V_58 = V_58 ;
V_61 -> V_60 = V_60 ;
F_43 ( & V_61 -> V_57 , & V_51 -> V_55 ) ;
return 0 ;
}
static int F_44 ( struct V_64 * V_65 ,
struct V_34 * V_35 ,
struct V_50 * V_56 , int V_66 ,
int V_67 , unsigned int V_68 ,
unsigned int V_69 , T_1 V_70 ,
T_1 V_71 , T_1 V_72 ,
T_1 V_73 ,
struct V_59 * V_60 )
{
struct V_51 * V_51 = F_45 ( V_65 ) ;
const struct V_74 * V_75 = V_51 -> V_76 ;
struct V_1 * V_1 = F_20 ( V_35 ) ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
unsigned long V_2 ;
unsigned int V_81 ;
unsigned int V_82 ;
unsigned int V_83 ;
unsigned int V_84 ;
unsigned int V_85 ;
T_2 V_58 ;
enum V_13 V_14 ;
T_1 V_86 ;
bool V_87 ;
bool V_88 ;
int V_36 ;
struct V_89 V_90 = {
. V_91 = V_66 ,
. y1 = V_67 ,
. V_92 = V_66 + V_68 ,
. V_93 = V_67 + V_69 ,
} ;
struct V_89 V_94 = {
. V_91 = V_70 ,
. y1 = V_71 ,
. V_92 = V_70 + V_72 ,
. V_93 = V_71 + V_73 ,
} ;
const struct V_89 V_95 = {
. V_92 = V_35 -> V_96 . V_97 ,
. V_93 = V_35 -> V_96 . V_98 ,
} ;
bool V_99 = V_65 -> type != V_100 ;
V_36 = F_46 ( V_65 , V_35 , V_56 ,
& V_94 , & V_90 , & V_95 ,
V_101 ,
V_101 ,
V_99 , false , & V_88 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_88 )
return 0 ;
V_87 = F_12 ( V_56 -> V_102 ) ;
V_14 = F_10 ( V_56 -> V_102 ) ;
if ( V_14 < 0 )
return V_14 ;
V_78 = F_47 ( V_56 , 0 ) ;
if ( ! V_78 ) {
F_11 ( L_7 ) ;
return - V_28 ;
}
V_80 = F_48 ( V_78 ) ;
V_81 = ( V_94 . V_92 - V_94 . V_91 ) >> 16 ;
V_82 = ( V_94 . V_93 - V_94 . y1 ) >> 16 ;
V_66 = F_49 ( 0 , V_66 ) ;
V_67 = F_49 ( 0 , V_67 ) ;
V_83 = V_66 + V_35 -> V_96 . V_103 - V_35 -> V_96 . V_104 ;
V_84 = V_67 + V_35 -> V_96 . V_105 - V_35 -> V_96 . V_106 ;
V_2 = ( V_94 . V_91 >> 16 ) * ( V_56 -> V_107 >> 3 ) ;
V_2 += ( V_94 . y1 >> 16 ) * V_56 -> V_108 [ 0 ] ;
V_58 = V_80 -> V_109 + V_2 ;
V_85 = V_56 -> V_108 [ 0 ] / ( V_56 -> V_107 >> 3 ) ;
F_50 ( & V_1 -> V_110 ) ;
if ( V_56 != F_38 ( V_51 ) ) {
V_36 = F_51 ( V_65 -> V_37 , V_1 -> V_48 ) ;
if ( V_36 ) {
F_11 ( L_8 , V_36 ) ;
F_52 ( & V_1 -> V_110 ) ;
return V_36 ;
}
F_53 ( V_56 ) ;
V_36 = F_41 ( V_51 , V_56 , V_58 , V_60 ) ;
if ( V_36 ) {
F_54 ( V_65 -> V_37 , V_1 -> V_48 ) ;
F_52 ( & V_1 -> V_110 ) ;
return V_36 ;
}
V_1 -> V_111 = true ;
}
F_52 ( & V_1 -> V_110 ) ;
F_25 ( & V_1 -> V_45 ) ;
F_55 ( V_1 , V_75 , V_14 , V_14 ) ;
F_55 ( V_1 , V_75 , V_112 , V_85 ) ;
F_55 ( V_1 , V_75 , V_58 , V_58 ) ;
V_86 = ( V_82 - 1 ) << 16 ;
V_86 |= ( V_81 - 1 ) & 0xffff ;
F_55 ( V_1 , V_75 , V_113 , V_86 ) ;
F_55 ( V_1 , V_75 , V_114 , V_86 ) ;
V_86 = ( V_84 - 1 ) << 16 ;
V_86 |= ( V_83 - 1 ) & 0xffff ;
F_55 ( V_1 , V_75 , V_115 , V_86 ) ;
if ( V_87 ) {
F_55 ( V_1 , V_75 , V_116 ,
F_56 ( V_117 ) ) ;
V_86 = F_57 ( 1 ) | F_58 ( V_118 ) |
F_59 ( V_119 ) |
F_60 ( V_120 ) |
F_61 ( V_121 ) |
F_62 ( V_122 ) ;
F_55 ( V_1 , V_75 , V_123 , V_86 ) ;
} else {
F_55 ( V_1 , V_75 , V_123 , F_57 ( 0 ) ) ;
}
F_55 ( V_1 , V_75 , V_124 , 1 ) ;
F_6 ( V_1 ) ;
F_27 ( & V_1 -> V_45 ) ;
return 0 ;
}
static int F_63 ( struct V_64 * V_65 , struct V_34 * V_35 ,
struct V_50 * V_56 , int V_66 , int V_67 ,
unsigned int V_68 , unsigned int V_69 ,
T_1 V_70 , T_1 V_71 , T_1 V_72 ,
T_1 V_73 )
{
return F_44 ( V_65 , V_35 , V_56 , V_66 , V_67 , V_68 ,
V_69 , V_70 , V_71 , V_72 , V_73 ,
NULL ) ;
}
static int F_64 ( struct V_34 * V_35 ,
struct V_59 * V_60 )
{
unsigned int V_68 , V_69 ;
V_68 = V_35 -> V_125 -> V_56 -> V_126 - V_35 -> V_127 ;
V_69 = V_35 -> V_125 -> V_56 -> V_128 - V_35 -> V_129 ;
return F_44 ( V_35 -> V_125 , V_35 , V_35 -> V_125 -> V_56 ,
0 , 0 , V_68 , V_69 , V_35 -> V_127 << 16 ,
V_35 -> V_129 << 16 , V_68 << 16 ,
V_69 << 16 , V_60 ) ;
}
static int F_65 ( struct V_64 * V_65 )
{
struct V_51 * V_51 = F_45 ( V_65 ) ;
const struct V_74 * V_75 = V_51 -> V_76 ;
struct V_1 * V_1 ;
int V_36 ;
if ( ! V_65 -> V_35 )
return 0 ;
V_1 = F_20 ( V_65 -> V_35 ) ;
V_36 = F_51 ( V_65 -> V_37 , V_1 -> V_48 ) ;
if ( V_36 ) {
F_11 ( L_8 , V_36 ) ;
return V_36 ;
}
F_50 ( & V_1 -> V_110 ) ;
V_36 = F_41 ( V_51 , NULL , 0 , NULL ) ;
if ( V_36 ) {
F_54 ( V_65 -> V_37 , V_1 -> V_48 ) ;
F_52 ( & V_1 -> V_110 ) ;
return V_36 ;
}
V_1 -> V_111 = true ;
F_52 ( & V_1 -> V_110 ) ;
F_25 ( & V_1 -> V_45 ) ;
F_55 ( V_1 , V_75 , V_124 , 0 ) ;
F_6 ( V_1 ) ;
F_27 ( & V_1 -> V_45 ) ;
return 0 ;
}
static void F_66 ( struct V_64 * V_65 )
{
F_65 ( V_65 ) ;
F_67 ( V_65 ) ;
}
int F_68 ( struct V_34 * V_35 ,
int V_130 ,
int V_131 )
{
struct V_1 * V_1 = F_20 ( V_35 ) ;
V_1 -> V_130 = V_130 ;
V_1 -> V_132 = V_131 ;
return 0 ;
}
static int F_69 ( struct V_34 * V_35 )
{
struct V_1 * V_1 = F_20 ( V_35 ) ;
unsigned long V_29 ;
if ( ! V_1 -> V_30 )
return - V_133 ;
F_15 ( & V_1 -> V_31 , V_29 ) ;
F_7 ( V_1 , V_32 , V_134 , F_70 ( 1 ) ) ;
F_17 ( & V_1 -> V_31 , V_29 ) ;
return 0 ;
}
static void F_71 ( struct V_34 * V_35 )
{
struct V_1 * V_1 = F_20 ( V_35 ) ;
unsigned long V_29 ;
if ( ! V_1 -> V_30 )
return;
F_15 ( & V_1 -> V_31 , V_29 ) ;
F_7 ( V_1 , V_32 , V_134 , F_70 ( 0 ) ) ;
F_17 ( & V_1 -> V_31 , V_29 ) ;
}
static void F_72 ( struct V_34 * V_35 , int V_96 )
{
F_73 ( L_9 , V_35 -> V_6 . V_135 , V_96 ) ;
switch ( V_96 ) {
case V_136 :
F_19 ( V_35 ) ;
break;
case V_137 :
case V_138 :
case V_139 :
F_31 ( V_35 ) ;
break;
default:
F_73 ( L_10 , V_96 ) ;
break;
}
}
static void F_74 ( struct V_34 * V_35 )
{
F_72 ( V_35 , V_136 ) ;
}
static bool F_75 ( struct V_34 * V_35 ,
const struct V_140 * V_96 ,
struct V_140 * V_141 )
{
if ( V_141 -> V_103 == 0 || V_141 -> V_105 == 0 )
return false ;
return true ;
}
static int F_76 ( struct V_34 * V_35 , int V_127 , int V_129 ,
struct V_50 * V_142 )
{
int V_36 ;
V_35 -> V_127 = V_127 ;
V_35 -> V_129 = V_129 ;
V_36 = F_64 ( V_35 , NULL ) ;
if ( V_36 < 0 ) {
F_11 ( L_11 ) ;
return V_36 ;
}
return 0 ;
}
static int F_77 ( struct V_34 * V_35 ,
struct V_140 * V_96 ,
struct V_140 * V_141 ,
int V_127 , int V_129 , struct V_50 * V_56 )
{
struct V_1 * V_1 = F_20 ( V_35 ) ;
T_3 V_143 = V_141 -> V_144 - V_141 -> V_104 ;
T_3 V_97 = V_141 -> V_97 ;
T_3 V_103 = V_141 -> V_103 ;
T_3 V_145 = V_141 -> V_103 - V_141 -> V_104 ;
T_3 V_146 = V_145 + V_97 ;
T_3 V_98 = V_141 -> V_98 ;
T_3 V_105 = V_141 -> V_105 ;
T_3 V_147 = V_141 -> V_148 - V_141 -> V_106 ;
T_3 V_149 = V_141 -> V_105 - V_141 -> V_106 ;
T_3 V_150 = V_149 + V_98 ;
int V_36 , V_151 ;
T_1 V_86 ;
F_30 ( V_1 -> V_39 ) ;
switch ( V_1 -> V_130 ) {
case V_152 :
F_26 ( V_1 , V_153 , 1 ) ;
break;
case V_154 :
F_26 ( V_1 , V_155 , 1 ) ;
break;
case V_156 :
F_26 ( V_1 , V_157 , 1 ) ;
break;
default:
F_11 ( L_12 ,
V_1 -> V_130 ) ;
V_36 = - V_28 ;
goto V_158;
} ;
F_26 ( V_1 , V_131 , V_1 -> V_132 ) ;
V_86 = 0x8 ;
V_86 |= ( V_141 -> V_29 & V_159 ) ? 0 : 1 ;
V_86 |= ( V_141 -> V_29 & V_160 ) ? 0 : ( 1 << 1 ) ;
F_26 ( V_1 , V_161 , V_86 ) ;
F_26 ( V_1 , V_162 , ( V_103 << 16 ) | V_143 ) ;
V_86 = V_145 << 16 ;
V_86 |= V_146 ;
F_26 ( V_1 , V_163 , V_86 ) ;
F_26 ( V_1 , V_164 , V_86 ) ;
F_26 ( V_1 , V_165 , ( V_105 << 16 ) | V_147 ) ;
V_86 = V_149 << 16 ;
V_86 |= V_150 ;
F_26 ( V_1 , V_166 , V_86 ) ;
F_26 ( V_1 , V_167 , V_86 ) ;
V_36 = F_76 ( V_35 , V_127 , V_129 , V_56 ) ;
if ( V_36 )
goto V_158;
F_78 ( V_1 -> V_168 ) ;
F_79 ( 10 , 20 ) ;
F_80 ( V_1 -> V_168 ) ;
F_81 ( V_1 -> V_39 , V_141 -> clock * 1000 ) ;
V_158:
V_151 = F_23 ( V_1 -> V_39 ) ;
if ( V_151 < 0 ) {
F_22 ( V_1 -> V_37 , L_4 , V_151 ) ;
return V_151 ;
}
return V_36 ;
}
static void F_82 ( struct V_34 * V_35 )
{
}
static int F_83 ( struct V_34 * V_35 ,
struct V_50 * V_56 ,
struct V_59 * V_60 ,
T_1 V_169 )
{
struct V_1 * V_1 = F_20 ( V_35 ) ;
struct V_50 * V_142 = V_35 -> V_125 -> V_56 ;
int V_36 ;
if ( ! V_1 -> V_30 ) {
F_84 ( L_13 ) ;
return 0 ;
}
V_35 -> V_125 -> V_56 = V_56 ;
V_36 = F_64 ( V_35 , V_60 ) ;
if ( V_36 )
V_35 -> V_125 -> V_56 = V_142 ;
return V_36 ;
}
static void F_85 ( struct V_51 * V_51 ,
struct V_52 * V_61 )
{
struct V_1 * V_1 = V_51 -> V_1 ;
struct V_34 * V_35 = & V_1 -> V_35 ;
struct V_170 * V_171 = V_35 -> V_37 ;
unsigned long V_29 ;
if ( V_61 -> V_60 ) {
F_15 ( & V_171 -> V_172 , V_29 ) ;
F_86 ( V_171 , - 1 , V_61 -> V_60 ) ;
F_17 ( & V_171 -> V_172 , V_29 ) ;
}
F_87 ( & V_61 -> V_57 ) ;
F_54 ( V_35 -> V_37 , V_1 -> V_48 ) ;
}
static void F_88 ( struct V_34 * V_35 )
{
F_89 ( V_35 ) ;
}
static bool F_90 ( struct V_51 * V_51 ,
struct V_52 * V_61 )
{
bool V_54 = false ;
if ( V_61 -> V_56 ) {
T_2 V_58 ;
V_58 = F_91 ( V_51 -> V_1 , V_51 -> V_76 ) ;
V_54 = ( V_58 == V_61 -> V_58 ) ;
} else {
bool V_173 ;
V_173 = F_92 ( V_51 -> V_1 , V_51 -> V_76 , V_124 ) ;
V_54 = ( V_173 == 0 ) ;
}
return V_54 ;
}
static void F_93 ( struct V_52 * V_61 )
{
struct V_50 * V_56 = V_61 -> V_56 ;
if ( V_56 )
F_94 ( V_56 ) ;
F_95 ( V_61 ) ;
}
static void F_96 ( struct V_51 * V_51 )
{
struct V_52 * V_61 , * V_174 , * V_175 = NULL ;
F_97 (state, &vop_win->pending, head)
if ( F_90 ( V_51 , V_61 ) ) {
V_175 = V_61 ;
break;
}
if ( ! V_175 )
return;
F_98 (state, n, &vop_win->pending, head) {
if ( V_61 == V_175 )
break;
F_85 ( V_51 , V_61 ) ;
F_93 ( V_61 ) ;
}
F_85 ( V_51 , V_175 ) ;
if ( V_51 -> V_54 )
F_93 ( V_51 -> V_54 ) ;
V_51 -> V_54 = V_175 ;
}
static bool F_99 ( struct V_51 * V_51 )
{
return ! F_39 ( & V_51 -> V_55 ) ;
}
static T_4 F_100 ( int V_47 , void * V_76 )
{
struct V_1 * V_1 = V_76 ;
const struct V_176 * V_176 = V_1 -> V_76 ;
unsigned int V_177 ;
F_50 ( & V_1 -> V_110 ) ;
if ( ! V_1 -> V_111 )
goto V_178;
V_1 -> V_111 = false ;
for ( V_177 = 0 ; V_177 < V_176 -> V_179 ; V_177 ++ ) {
struct V_51 * V_51 = & V_1 -> V_75 [ V_177 ] ;
F_96 ( V_51 ) ;
if ( F_99 ( V_51 ) )
V_1 -> V_111 = true ;
}
V_178:
F_52 ( & V_1 -> V_110 ) ;
return V_180 ;
}
static T_4 F_101 ( int V_47 , void * V_76 )
{
struct V_1 * V_1 = V_76 ;
T_1 V_181 , V_182 ;
unsigned long V_29 ;
int V_36 = V_183 ;
F_15 ( & V_1 -> V_31 , V_29 ) ;
V_181 = F_3 ( V_1 , V_32 ) ;
V_182 = V_181 & V_184 ;
if ( V_182 )
F_1 ( V_1 , V_32 ,
V_181 | ( V_182 << V_185 ) ) ;
F_17 ( & V_1 -> V_31 , V_29 ) ;
if ( ! V_182 )
return V_183 ;
if ( V_182 & V_186 ) {
F_102 ( & V_1 -> V_49 ) ;
V_182 &= ~ V_186 ;
V_36 = V_180 ;
}
if ( V_182 & V_187 ) {
F_103 ( V_1 -> V_43 , V_1 -> V_48 ) ;
V_182 &= ~ V_187 ;
V_36 = ( V_1 -> V_111 ) ? V_188 : V_180 ;
}
if ( V_182 )
F_11 ( L_14 , V_182 ) ;
return V_36 ;
}
static int F_104 ( struct V_1 * V_1 )
{
const struct V_176 * V_176 = V_1 -> V_76 ;
struct V_189 * V_37 = V_1 -> V_37 ;
struct V_170 * V_43 = V_1 -> V_43 ;
struct V_64 * V_125 = NULL , * V_190 = NULL , * V_65 ;
struct V_34 * V_35 = & V_1 -> V_35 ;
struct V_191 * V_192 ;
int V_36 ;
int V_177 ;
for ( V_177 = 0 ; V_177 < V_176 -> V_179 ; V_177 ++ ) {
struct V_51 * V_51 = & V_1 -> V_75 [ V_177 ] ;
const struct V_74 * V_193 = V_51 -> V_76 ;
if ( V_193 -> type != V_100 &&
V_193 -> type != V_194 )
continue;
V_36 = F_105 ( V_1 -> V_43 , & V_51 -> V_6 ,
0 , & V_195 ,
V_193 -> V_196 -> V_197 ,
V_193 -> V_196 -> V_198 ,
V_193 -> type ) ;
if ( V_36 ) {
F_11 ( L_15 ) ;
goto V_199;
}
V_65 = & V_51 -> V_6 ;
if ( V_65 -> type == V_100 )
V_125 = V_65 ;
else if ( V_65 -> type == V_194 )
V_190 = V_65 ;
}
V_36 = F_106 ( V_43 , V_35 , V_125 , V_190 ,
& V_200 ) ;
if ( V_36 )
return V_36 ;
F_107 ( V_35 , & V_201 ) ;
for ( V_177 = 0 ; V_177 < V_176 -> V_179 ; V_177 ++ ) {
struct V_51 * V_51 = & V_1 -> V_75 [ V_177 ] ;
const struct V_74 * V_193 = V_51 -> V_76 ;
unsigned long V_202 = 1 << F_108 ( V_35 ) ;
if ( V_193 -> type != V_203 )
continue;
V_36 = F_105 ( V_1 -> V_43 , & V_51 -> V_6 ,
V_202 ,
& V_195 ,
V_193 -> V_196 -> V_197 ,
V_193 -> V_196 -> V_198 ,
V_193 -> type ) ;
if ( V_36 ) {
F_11 ( L_16 ) ;
goto V_204;
}
}
V_192 = F_109 ( V_37 -> V_205 , L_17 ) ;
if ( ! V_192 ) {
F_11 ( L_18 ,
V_37 -> V_205 -> V_206 ) ;
goto V_204;
}
F_110 ( & V_1 -> V_49 ) ;
V_35 -> V_192 = V_192 ;
V_1 -> V_48 = F_108 ( V_35 ) ;
F_111 ( V_43 , & V_207 , V_1 -> V_48 ) ;
return 0 ;
V_204:
F_89 ( V_35 ) ;
V_199:
F_97 (plane, &drm_dev->mode_config.plane_list, head)
F_67 ( V_65 ) ;
return V_36 ;
}
static void F_112 ( struct V_1 * V_1 )
{
struct V_34 * V_35 = & V_1 -> V_35 ;
F_113 ( V_1 -> V_43 , V_1 -> V_48 ) ;
F_114 ( V_35 -> V_192 ) ;
F_89 ( V_35 ) ;
}
static int F_115 ( struct V_1 * V_1 )
{
const struct V_176 * V_176 = V_1 -> V_76 ;
const struct V_208 * V_209 = V_176 -> V_209 ;
struct V_210 * V_211 ;
int V_177 , V_36 ;
V_1 -> V_38 = F_116 ( V_1 -> V_37 , L_19 ) ;
if ( F_117 ( V_1 -> V_38 ) ) {
F_22 ( V_1 -> V_37 , L_20 ) ;
return F_118 ( V_1 -> V_38 ) ;
}
V_1 -> V_41 = F_116 ( V_1 -> V_37 , L_21 ) ;
if ( F_117 ( V_1 -> V_41 ) ) {
F_22 ( V_1 -> V_37 , L_22 ) ;
return F_118 ( V_1 -> V_41 ) ;
}
V_1 -> V_39 = F_116 ( V_1 -> V_37 , L_23 ) ;
if ( F_117 ( V_1 -> V_39 ) ) {
F_22 ( V_1 -> V_37 , L_24 ) ;
return F_118 ( V_1 -> V_39 ) ;
}
V_36 = F_119 ( V_1 -> V_38 ) ;
if ( V_36 < 0 ) {
F_22 ( V_1 -> V_37 , L_25 ) ;
return V_36 ;
}
V_36 = F_119 ( V_1 -> V_39 ) ;
if ( V_36 < 0 ) {
F_22 ( V_1 -> V_37 , L_26 ) ;
goto V_212;
}
V_36 = F_119 ( V_1 -> V_41 ) ;
if ( V_36 < 0 ) {
F_22 ( V_1 -> V_37 , L_27 ) ;
goto V_213;
}
V_36 = F_23 ( V_1 -> V_38 ) ;
if ( V_36 < 0 ) {
F_22 ( V_1 -> V_37 , L_27 ) ;
goto V_214;
}
V_211 = F_120 ( V_1 -> V_37 , L_28 ) ;
if ( F_117 ( V_211 ) ) {
F_22 ( V_1 -> V_37 , L_29 ) ;
V_36 = F_118 ( V_211 ) ;
goto V_40;
}
F_78 ( V_211 ) ;
F_79 ( 10 , 20 ) ;
F_80 ( V_211 ) ;
memcpy ( V_1 -> V_5 , V_1 -> V_4 , V_1 -> V_215 ) ;
for ( V_177 = 0 ; V_177 < V_176 -> V_216 ; V_177 ++ )
F_1 ( V_1 , V_209 [ V_177 ] . V_2 , V_209 [ V_177 ] . V_217 ) ;
for ( V_177 = 0 ; V_177 < V_176 -> V_179 ; V_177 ++ ) {
const struct V_74 * V_75 = & V_176 -> V_75 [ V_177 ] ;
F_55 ( V_1 , V_75 , V_124 , 0 ) ;
}
F_6 ( V_1 ) ;
V_1 -> V_168 = F_120 ( V_1 -> V_37 , L_30 ) ;
if ( F_117 ( V_1 -> V_168 ) ) {
F_22 ( V_1 -> V_37 , L_31 ) ;
V_36 = F_118 ( V_1 -> V_168 ) ;
goto V_214;
}
F_78 ( V_1 -> V_168 ) ;
F_79 ( 10 , 20 ) ;
F_80 ( V_1 -> V_168 ) ;
F_30 ( V_1 -> V_38 ) ;
V_1 -> V_30 = false ;
return 0 ;
V_40:
F_30 ( V_1 -> V_38 ) ;
V_214:
F_121 ( V_1 -> V_41 ) ;
V_213:
F_121 ( V_1 -> V_39 ) ;
V_212:
F_121 ( V_1 -> V_38 ) ;
return V_36 ;
}
static void F_122 ( struct V_1 * V_1 )
{
const struct V_176 * V_176 = V_1 -> V_76 ;
unsigned int V_177 ;
for ( V_177 = 0 ; V_177 < V_176 -> V_179 ; V_177 ++ ) {
struct V_51 * V_51 = & V_1 -> V_75 [ V_177 ] ;
const struct V_74 * V_193 = & V_176 -> V_75 [ V_177 ] ;
V_51 -> V_76 = V_193 ;
V_51 -> V_1 = V_1 ;
F_123 ( & V_51 -> V_55 ) ;
}
}
static int F_124 ( struct V_189 * V_37 , struct V_189 * V_218 , void * V_76 )
{
struct V_219 * V_220 = F_125 ( V_37 ) ;
const struct V_221 * V_222 ;
const struct V_176 * V_176 ;
struct V_170 * V_43 = V_76 ;
struct V_1 * V_1 ;
struct V_223 * V_224 ;
T_5 V_225 ;
int V_36 , V_47 ;
V_222 = F_126 ( V_226 , V_37 ) ;
V_176 = V_222 -> V_76 ;
if ( ! V_176 )
return - V_227 ;
V_225 = sizeof( * V_1 ) + sizeof( * V_1 -> V_75 ) * V_176 -> V_179 ;
V_1 = F_127 ( V_37 , V_225 , V_62 ) ;
if ( ! V_1 )
return - V_63 ;
V_1 -> V_37 = V_37 ;
V_1 -> V_76 = V_176 ;
V_1 -> V_43 = V_43 ;
F_128 ( V_37 , V_1 ) ;
F_122 ( V_1 ) ;
V_224 = F_129 ( V_220 , V_228 , 0 ) ;
V_1 -> V_215 = F_130 ( V_224 ) ;
V_1 -> V_4 = F_131 ( V_37 , V_224 ) ;
if ( F_117 ( V_1 -> V_4 ) )
return F_118 ( V_1 -> V_4 ) ;
V_1 -> V_5 = F_127 ( V_37 , V_1 -> V_215 , V_62 ) ;
if ( ! V_1 -> V_5 )
return - V_63 ;
V_36 = F_115 ( V_1 ) ;
if ( V_36 < 0 ) {
F_22 ( & V_220 -> V_37 , L_32 , V_36 ) ;
return V_36 ;
}
V_47 = F_132 ( V_220 , 0 ) ;
if ( V_47 < 0 ) {
F_22 ( V_37 , L_33 ) ;
return V_47 ;
}
V_1 -> V_47 = ( unsigned int ) V_47 ;
F_133 ( & V_1 -> V_45 ) ;
F_133 ( & V_1 -> V_31 ) ;
F_134 ( & V_1 -> V_110 ) ;
V_36 = F_135 ( V_37 , V_1 -> V_47 , F_101 , F_100 ,
V_229 , F_136 ( V_37 ) , V_1 ) ;
if ( V_36 )
return V_36 ;
F_35 ( V_1 -> V_47 ) ;
V_36 = F_104 ( V_1 ) ;
if ( V_36 )
return V_36 ;
F_137 ( & V_220 -> V_37 ) ;
return 0 ;
}
static void F_138 ( struct V_189 * V_37 , struct V_189 * V_218 , void * V_76 )
{
struct V_1 * V_1 = F_139 ( V_37 ) ;
F_140 ( V_37 ) ;
F_112 ( V_1 ) ;
}
static int F_141 ( struct V_219 * V_220 )
{
struct V_189 * V_37 = & V_220 -> V_37 ;
if ( ! V_37 -> V_205 ) {
F_22 ( V_37 , L_34 ) ;
return - V_227 ;
}
return F_142 ( V_37 , & V_230 ) ;
}
static int F_143 ( struct V_219 * V_220 )
{
F_144 ( & V_220 -> V_37 , & V_230 ) ;
return 0 ;
}
