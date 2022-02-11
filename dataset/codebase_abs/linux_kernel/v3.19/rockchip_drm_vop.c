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
static void F_13 ( struct V_29 * V_30 )
{
struct V_1 * V_1 = F_14 ( V_30 ) ;
int V_31 ;
V_31 = F_15 ( V_1 -> V_32 ) ;
if ( V_31 < 0 ) {
F_16 ( V_1 -> V_33 , L_2 , V_31 ) ;
return;
}
V_31 = F_15 ( V_1 -> V_34 ) ;
if ( V_31 < 0 ) {
F_16 ( V_1 -> V_33 , L_3 , V_31 ) ;
goto V_35;
}
V_31 = F_15 ( V_1 -> V_36 ) ;
if ( V_31 < 0 ) {
F_16 ( V_1 -> V_33 , L_4 , V_31 ) ;
goto V_37;
}
V_31 = F_17 ( V_1 -> V_38 , V_1 -> V_33 ) ;
if ( V_31 ) {
F_16 ( V_1 -> V_33 , L_5 , V_31 ) ;
goto V_39;
}
F_18 ( & V_1 -> V_40 ) ;
F_19 ( V_1 , V_41 , 0 ) ;
F_20 ( & V_1 -> V_40 ) ;
F_21 ( V_1 -> V_42 ) ;
F_22 ( V_1 -> V_38 , V_1 -> V_43 ) ;
return;
V_39:
F_23 ( V_1 -> V_36 ) ;
V_37:
F_23 ( V_1 -> V_34 ) ;
V_35:
F_23 ( V_1 -> V_32 ) ;
}
static void F_24 ( struct V_29 * V_30 )
{
struct V_1 * V_1 = F_14 ( V_30 ) ;
F_25 ( V_30 -> V_33 , V_1 -> V_43 ) ;
F_26 ( V_1 -> V_42 ) ;
F_18 ( & V_1 -> V_40 ) ;
F_19 ( V_1 , V_41 , 1 ) ;
F_20 ( & V_1 -> V_40 ) ;
F_23 ( V_1 -> V_34 ) ;
F_27 ( V_1 -> V_38 , V_1 -> V_33 ) ;
F_23 ( V_1 -> V_36 ) ;
F_23 ( V_1 -> V_32 ) ;
}
static struct V_44 * F_28 ( struct V_45 * V_45 )
{
struct V_46 * V_47 ;
struct V_46 * V_48 = V_45 -> V_48 ;
if ( F_29 ( & V_45 -> V_49 ) )
return V_48 ? V_48 -> V_50 : NULL ;
V_47 = F_30 ( & V_45 -> V_49 , struct V_46 , V_51 ) ;
return V_47 ? V_47 -> V_50 : NULL ;
}
static int F_31 ( struct V_45 * V_45 ,
struct V_44 * V_50 , T_2 V_52 ,
struct V_53 * V_54 )
{
struct V_46 * V_55 ;
V_55 = F_32 ( sizeof( * V_55 ) , V_56 ) ;
if ( ! V_55 )
return - V_57 ;
V_55 -> V_50 = V_50 ;
V_55 -> V_52 = V_52 ;
V_55 -> V_54 = V_54 ;
F_33 ( & V_55 -> V_51 , & V_45 -> V_49 ) ;
return 0 ;
}
static int F_34 ( struct V_58 * V_59 ,
struct V_29 * V_30 ,
struct V_44 * V_50 , int V_60 ,
int V_61 , unsigned int V_62 ,
unsigned int V_63 , T_1 V_64 ,
T_1 V_65 , T_1 V_66 ,
T_1 V_67 ,
struct V_53 * V_54 )
{
struct V_45 * V_45 = F_35 ( V_59 ) ;
const struct V_68 * V_69 = V_45 -> V_70 ;
struct V_1 * V_1 = F_14 ( V_30 ) ;
struct V_71 * V_72 ;
struct V_73 * V_74 ;
unsigned long V_2 ;
unsigned int V_75 ;
unsigned int V_76 ;
unsigned int V_77 ;
unsigned int V_78 ;
unsigned int V_79 ;
T_2 V_52 ;
enum V_13 V_14 ;
T_1 V_80 ;
bool V_81 ;
bool V_82 ;
int V_31 ;
struct V_83 V_84 = {
. V_85 = V_60 ,
. y1 = V_61 ,
. V_86 = V_60 + V_62 ,
. V_87 = V_61 + V_63 ,
} ;
struct V_83 V_88 = {
. V_85 = V_64 ,
. y1 = V_65 ,
. V_86 = V_64 + V_66 ,
. V_87 = V_65 + V_67 ,
} ;
const struct V_83 V_89 = {
. V_86 = V_30 -> V_90 . V_91 ,
. V_87 = V_30 -> V_90 . V_92 ,
} ;
bool V_93 = V_59 -> type != V_94 ;
V_31 = F_36 ( V_59 , V_30 , V_50 ,
& V_88 , & V_84 , & V_89 ,
V_95 ,
V_95 ,
V_93 , false , & V_82 ) ;
if ( V_31 )
return V_31 ;
if ( ! V_82 )
return 0 ;
V_81 = F_12 ( V_50 -> V_96 ) ;
V_14 = F_10 ( V_50 -> V_96 ) ;
if ( V_14 < 0 )
return V_14 ;
V_72 = F_37 ( V_50 , 0 ) ;
if ( ! V_72 ) {
F_11 ( L_6 ) ;
return - V_28 ;
}
V_74 = F_38 ( V_72 ) ;
V_75 = ( V_88 . V_86 - V_88 . V_85 ) >> 16 ;
V_76 = ( V_88 . V_87 - V_88 . y1 ) >> 16 ;
V_60 = F_39 ( 0 , V_60 ) ;
V_61 = F_39 ( 0 , V_61 ) ;
V_77 = V_60 + V_30 -> V_90 . V_97 - V_30 -> V_90 . V_98 ;
V_78 = V_61 + V_30 -> V_90 . V_99 - V_30 -> V_90 . V_100 ;
V_2 = ( V_88 . V_85 >> 16 ) * ( V_50 -> V_101 >> 3 ) ;
V_2 += ( V_88 . y1 >> 16 ) * V_50 -> V_102 [ 0 ] ;
V_52 = V_74 -> V_103 + V_2 ;
V_79 = V_50 -> V_102 [ 0 ] / ( V_50 -> V_101 >> 3 ) ;
F_40 ( & V_1 -> V_104 ) ;
if ( V_50 != F_28 ( V_45 ) ) {
V_31 = F_41 ( V_59 -> V_33 , V_1 -> V_43 ) ;
if ( V_31 ) {
F_11 ( L_7 , V_31 ) ;
F_42 ( & V_1 -> V_104 ) ;
return V_31 ;
}
F_43 ( V_50 ) ;
V_31 = F_31 ( V_45 , V_50 , V_52 , V_54 ) ;
if ( V_31 ) {
F_44 ( V_59 -> V_33 , V_1 -> V_43 ) ;
F_42 ( & V_1 -> V_104 ) ;
return V_31 ;
}
V_1 -> V_105 = true ;
}
F_42 ( & V_1 -> V_104 ) ;
F_18 ( & V_1 -> V_40 ) ;
F_45 ( V_1 , V_69 , V_14 , V_14 ) ;
F_45 ( V_1 , V_69 , V_106 , V_79 ) ;
F_45 ( V_1 , V_69 , V_52 , V_52 ) ;
V_80 = ( V_76 - 1 ) << 16 ;
V_80 |= ( V_75 - 1 ) & 0xffff ;
F_45 ( V_1 , V_69 , V_107 , V_80 ) ;
F_45 ( V_1 , V_69 , V_108 , V_80 ) ;
V_80 = ( V_78 - 1 ) << 16 ;
V_80 |= ( V_77 - 1 ) & 0xffff ;
F_45 ( V_1 , V_69 , V_109 , V_80 ) ;
if ( V_81 ) {
F_45 ( V_1 , V_69 , V_110 ,
F_46 ( V_111 ) ) ;
V_80 = F_47 ( 1 ) | F_48 ( V_112 ) |
F_49 ( V_113 ) |
F_50 ( V_114 ) |
F_51 ( V_115 ) |
F_52 ( V_116 ) ;
F_45 ( V_1 , V_69 , V_117 , V_80 ) ;
} else {
F_45 ( V_1 , V_69 , V_117 , F_47 ( 0 ) ) ;
}
F_45 ( V_1 , V_69 , V_118 , 1 ) ;
F_6 ( V_1 ) ;
F_20 ( & V_1 -> V_40 ) ;
return 0 ;
}
static int F_53 ( struct V_58 * V_59 , struct V_29 * V_30 ,
struct V_44 * V_50 , int V_60 , int V_61 ,
unsigned int V_62 , unsigned int V_63 ,
T_1 V_64 , T_1 V_65 , T_1 V_66 ,
T_1 V_67 )
{
return F_34 ( V_59 , V_30 , V_50 , V_60 , V_61 , V_62 ,
V_63 , V_64 , V_65 , V_66 , V_67 ,
NULL ) ;
}
static int F_54 ( struct V_29 * V_30 ,
struct V_53 * V_54 )
{
unsigned int V_62 , V_63 ;
V_62 = V_30 -> V_119 -> V_50 -> V_120 - V_30 -> V_121 ;
V_63 = V_30 -> V_119 -> V_50 -> V_122 - V_30 -> V_123 ;
return F_34 ( V_30 -> V_119 , V_30 , V_30 -> V_119 -> V_50 ,
0 , 0 , V_62 , V_63 , V_30 -> V_121 << 16 ,
V_30 -> V_123 << 16 , V_62 << 16 ,
V_63 << 16 , V_54 ) ;
}
static int F_55 ( struct V_58 * V_59 )
{
struct V_45 * V_45 = F_35 ( V_59 ) ;
const struct V_68 * V_69 = V_45 -> V_70 ;
struct V_1 * V_1 ;
int V_31 ;
if ( ! V_59 -> V_30 )
return 0 ;
V_1 = F_14 ( V_59 -> V_30 ) ;
V_31 = F_41 ( V_59 -> V_33 , V_1 -> V_43 ) ;
if ( V_31 ) {
F_11 ( L_7 , V_31 ) ;
return V_31 ;
}
F_40 ( & V_1 -> V_104 ) ;
V_31 = F_31 ( V_45 , NULL , 0 , NULL ) ;
if ( V_31 ) {
F_44 ( V_59 -> V_33 , V_1 -> V_43 ) ;
F_42 ( & V_1 -> V_104 ) ;
return V_31 ;
}
V_1 -> V_105 = true ;
F_42 ( & V_1 -> V_104 ) ;
F_18 ( & V_1 -> V_40 ) ;
F_45 ( V_1 , V_69 , V_118 , 0 ) ;
F_6 ( V_1 ) ;
F_20 ( & V_1 -> V_40 ) ;
return 0 ;
}
static void F_56 ( struct V_58 * V_59 )
{
F_55 ( V_59 ) ;
F_57 ( V_59 ) ;
}
int F_58 ( struct V_29 * V_30 ,
int V_124 ,
int V_125 )
{
struct V_1 * V_1 = F_14 ( V_30 ) ;
V_1 -> V_124 = V_124 ;
V_1 -> V_126 = V_125 ;
return 0 ;
}
static int F_59 ( struct V_29 * V_30 )
{
struct V_1 * V_1 = F_14 ( V_30 ) ;
unsigned long V_127 ;
if ( V_1 -> V_128 != V_129 )
return - V_130 ;
F_60 ( & V_1 -> V_131 , V_127 ) ;
F_7 ( V_1 , V_132 , V_133 , F_61 ( 1 ) ) ;
F_62 ( & V_1 -> V_131 , V_127 ) ;
return 0 ;
}
static void F_63 ( struct V_29 * V_30 )
{
struct V_1 * V_1 = F_14 ( V_30 ) ;
unsigned long V_127 ;
if ( V_1 -> V_128 != V_129 )
return;
F_60 ( & V_1 -> V_131 , V_127 ) ;
F_7 ( V_1 , V_132 , V_133 , F_61 ( 0 ) ) ;
F_62 ( & V_1 -> V_131 , V_127 ) ;
}
static void F_64 ( struct V_29 * V_30 , int V_90 )
{
struct V_1 * V_1 = F_14 ( V_30 ) ;
F_65 ( L_8 , V_30 -> V_6 . V_134 , V_90 ) ;
if ( V_1 -> V_128 == V_90 ) {
F_65 ( L_9 ) ;
return;
}
switch ( V_90 ) {
case V_129 :
F_13 ( V_30 ) ;
break;
case V_135 :
case V_136 :
case V_137 :
F_24 ( V_30 ) ;
break;
default:
F_65 ( L_10 , V_90 ) ;
break;
}
V_1 -> V_128 = V_90 ;
}
static void F_66 ( struct V_29 * V_30 )
{
F_64 ( V_30 , V_129 ) ;
}
static bool F_67 ( struct V_29 * V_30 ,
const struct V_138 * V_90 ,
struct V_138 * V_139 )
{
if ( V_139 -> V_97 == 0 || V_139 -> V_99 == 0 )
return false ;
return true ;
}
static int F_68 ( struct V_29 * V_30 , int V_121 , int V_123 ,
struct V_44 * V_140 )
{
int V_31 ;
V_30 -> V_121 = V_121 ;
V_30 -> V_123 = V_123 ;
V_31 = F_54 ( V_30 , NULL ) ;
if ( V_31 < 0 ) {
F_11 ( L_11 ) ;
return V_31 ;
}
return 0 ;
}
static int F_69 ( struct V_29 * V_30 ,
struct V_138 * V_90 ,
struct V_138 * V_139 ,
int V_121 , int V_123 , struct V_44 * V_50 )
{
struct V_1 * V_1 = F_14 ( V_30 ) ;
T_3 V_141 = V_139 -> V_142 - V_139 -> V_98 ;
T_3 V_91 = V_139 -> V_91 ;
T_3 V_97 = V_139 -> V_97 ;
T_3 V_143 = V_139 -> V_97 - V_139 -> V_98 ;
T_3 V_144 = V_143 + V_91 ;
T_3 V_92 = V_139 -> V_92 ;
T_3 V_99 = V_139 -> V_99 ;
T_3 V_145 = V_139 -> V_146 - V_139 -> V_100 ;
T_3 V_147 = V_139 -> V_99 - V_139 -> V_100 ;
T_3 V_148 = V_147 + V_92 ;
int V_31 ;
T_1 V_80 ;
F_23 ( V_1 -> V_34 ) ;
switch ( V_1 -> V_124 ) {
case V_149 :
F_19 ( V_1 , V_150 , 1 ) ;
break;
case V_151 :
F_19 ( V_1 , V_152 , 1 ) ;
break;
case V_153 :
F_19 ( V_1 , V_154 , 1 ) ;
break;
default:
F_11 ( L_12 ,
V_1 -> V_124 ) ;
return - V_28 ;
} ;
F_19 ( V_1 , V_125 , V_1 -> V_126 ) ;
V_80 = 0x8 ;
V_80 |= ( V_139 -> V_127 & V_155 ) ? 1 : 0 ;
V_80 |= ( V_139 -> V_127 & V_156 ) ? ( 1 << 1 ) : 0 ;
F_19 ( V_1 , V_157 , V_80 ) ;
F_19 ( V_1 , V_158 , ( V_97 << 16 ) | V_141 ) ;
V_80 = V_143 << 16 ;
V_80 |= V_144 ;
F_19 ( V_1 , V_159 , V_80 ) ;
F_19 ( V_1 , V_160 , V_80 ) ;
F_19 ( V_1 , V_161 , ( V_99 << 16 ) | V_145 ) ;
V_80 = V_147 << 16 ;
V_80 |= V_148 ;
F_19 ( V_1 , V_162 , V_80 ) ;
F_19 ( V_1 , V_163 , V_80 ) ;
V_31 = F_68 ( V_30 , V_121 , V_123 , V_50 ) ;
if ( V_31 )
return V_31 ;
F_70 ( V_1 -> V_164 ) ;
F_71 ( 10 , 20 ) ;
F_72 ( V_1 -> V_164 ) ;
F_73 ( V_1 -> V_34 , V_139 -> clock * 1000 ) ;
V_31 = F_15 ( V_1 -> V_34 ) ;
if ( V_31 < 0 ) {
F_16 ( V_1 -> V_33 , L_3 , V_31 ) ;
return V_31 ;
}
return 0 ;
}
static void F_74 ( struct V_29 * V_30 )
{
}
static int F_75 ( struct V_29 * V_30 ,
struct V_44 * V_50 ,
struct V_53 * V_54 ,
T_1 V_165 )
{
struct V_1 * V_1 = F_14 ( V_30 ) ;
struct V_44 * V_140 = V_30 -> V_119 -> V_50 ;
int V_31 ;
if ( V_1 -> V_128 > V_129 ) {
F_76 ( L_13 , V_1 -> V_128 ) ;
return 0 ;
}
V_30 -> V_119 -> V_50 = V_50 ;
V_31 = F_54 ( V_30 , V_54 ) ;
if ( V_31 )
V_30 -> V_119 -> V_50 = V_140 ;
return V_31 ;
}
static void F_77 ( struct V_45 * V_45 ,
struct V_46 * V_55 )
{
struct V_1 * V_1 = V_45 -> V_1 ;
struct V_29 * V_30 = & V_1 -> V_30 ;
struct V_166 * V_167 = V_30 -> V_33 ;
unsigned long V_127 ;
if ( V_55 -> V_54 ) {
F_60 ( & V_167 -> V_168 , V_127 ) ;
F_78 ( V_167 , - 1 , V_55 -> V_54 ) ;
F_62 ( & V_167 -> V_168 , V_127 ) ;
}
F_79 ( & V_55 -> V_51 ) ;
F_44 ( V_30 -> V_33 , V_1 -> V_43 ) ;
}
static void F_80 ( struct V_29 * V_30 )
{
F_81 ( V_30 ) ;
}
static bool F_82 ( struct V_45 * V_45 ,
struct V_46 * V_55 )
{
bool V_48 = false ;
if ( V_55 -> V_50 ) {
T_2 V_52 ;
V_52 = F_83 ( V_45 -> V_1 , V_45 -> V_70 ) ;
V_48 = ( V_52 == V_55 -> V_52 ) ;
} else {
bool V_169 ;
V_169 = F_84 ( V_45 -> V_1 , V_45 -> V_70 , V_118 ) ;
V_48 = ( V_169 == 0 ) ;
}
return V_48 ;
}
static void F_85 ( struct V_46 * V_55 )
{
struct V_44 * V_50 = V_55 -> V_50 ;
if ( V_50 )
F_86 ( V_50 ) ;
F_87 ( V_55 ) ;
}
static void F_88 ( struct V_45 * V_45 )
{
struct V_46 * V_55 , * V_170 , * V_171 = NULL ;
F_89 (state, &vop_win->pending, head)
if ( F_82 ( V_45 , V_55 ) ) {
V_171 = V_55 ;
break;
}
if ( ! V_171 )
return;
F_90 (state, n, &vop_win->pending, head) {
if ( V_55 == V_171 )
break;
F_77 ( V_45 , V_55 ) ;
F_85 ( V_55 ) ;
}
F_77 ( V_45 , V_171 ) ;
if ( V_45 -> V_48 )
F_85 ( V_45 -> V_48 ) ;
V_45 -> V_48 = V_171 ;
}
static bool F_91 ( struct V_45 * V_45 )
{
return ! F_29 ( & V_45 -> V_49 ) ;
}
static T_4 F_92 ( int V_42 , void * V_70 )
{
struct V_1 * V_1 = V_70 ;
const struct V_172 * V_172 = V_1 -> V_70 ;
unsigned int V_173 ;
F_40 ( & V_1 -> V_104 ) ;
if ( ! V_1 -> V_105 )
goto V_174;
V_1 -> V_105 = false ;
for ( V_173 = 0 ; V_173 < V_172 -> V_175 ; V_173 ++ ) {
struct V_45 * V_45 = & V_1 -> V_69 [ V_173 ] ;
F_88 ( V_45 ) ;
if ( F_91 ( V_45 ) )
V_1 -> V_105 = true ;
}
V_174:
F_42 ( & V_1 -> V_104 ) ;
return V_176 ;
}
static T_4 F_93 ( int V_42 , void * V_70 )
{
struct V_1 * V_1 = V_70 ;
T_1 V_177 , V_178 ;
unsigned long V_127 ;
F_60 ( & V_1 -> V_131 , V_127 ) ;
V_177 = F_3 ( V_1 , V_132 ) ;
V_178 = V_177 & V_179 ;
if ( V_178 )
F_1 ( V_1 , V_132 ,
V_177 | ( V_178 << V_180 ) ) ;
F_62 ( & V_1 -> V_131 , V_127 ) ;
if ( ! V_178 )
return V_181 ;
if ( ! ( V_178 & V_182 ) ) {
F_11 ( L_14 , V_178 ) ;
return V_181 ;
}
F_94 ( V_1 -> V_38 , V_1 -> V_43 ) ;
return ( V_1 -> V_105 ) ? V_183 : V_176 ;
}
static int F_95 ( struct V_1 * V_1 )
{
const struct V_172 * V_172 = V_1 -> V_70 ;
struct V_184 * V_33 = V_1 -> V_33 ;
struct V_166 * V_38 = V_1 -> V_38 ;
struct V_58 * V_119 = NULL , * V_185 = NULL , * V_59 ;
struct V_29 * V_30 = & V_1 -> V_30 ;
struct V_186 * V_187 ;
int V_31 ;
int V_173 ;
for ( V_173 = 0 ; V_173 < V_172 -> V_175 ; V_173 ++ ) {
struct V_45 * V_45 = & V_1 -> V_69 [ V_173 ] ;
const struct V_68 * V_188 = V_45 -> V_70 ;
if ( V_188 -> type != V_94 &&
V_188 -> type != V_189 )
continue;
V_31 = F_96 ( V_1 -> V_38 , & V_45 -> V_6 ,
0 , & V_190 ,
V_188 -> V_191 -> V_192 ,
V_188 -> V_191 -> V_193 ,
V_188 -> type ) ;
if ( V_31 ) {
F_11 ( L_15 ) ;
goto V_194;
}
V_59 = & V_45 -> V_6 ;
if ( V_59 -> type == V_94 )
V_119 = V_59 ;
else if ( V_59 -> type == V_189 )
V_185 = V_59 ;
}
V_31 = F_97 ( V_38 , V_30 , V_119 , V_185 ,
& V_195 ) ;
if ( V_31 )
return V_31 ;
F_98 ( V_30 , & V_196 ) ;
for ( V_173 = 0 ; V_173 < V_172 -> V_175 ; V_173 ++ ) {
struct V_45 * V_45 = & V_1 -> V_69 [ V_173 ] ;
const struct V_68 * V_188 = V_45 -> V_70 ;
unsigned long V_197 = 1 << F_99 ( V_30 ) ;
if ( V_188 -> type != V_198 )
continue;
V_31 = F_96 ( V_1 -> V_38 , & V_45 -> V_6 ,
V_197 ,
& V_190 ,
V_188 -> V_191 -> V_192 ,
V_188 -> V_191 -> V_193 ,
V_188 -> type ) ;
if ( V_31 ) {
F_11 ( L_16 ) ;
goto V_199;
}
}
V_187 = F_100 ( V_33 -> V_200 , L_17 ) ;
if ( ! V_187 ) {
F_11 ( L_18 ,
V_33 -> V_200 -> V_201 ) ;
goto V_199;
}
V_30 -> V_187 = V_187 ;
V_1 -> V_43 = F_99 ( V_30 ) ;
F_101 ( V_38 , & V_202 , V_1 -> V_43 ) ;
return 0 ;
V_199:
F_81 ( V_30 ) ;
V_194:
F_89 (plane, &drm_dev->mode_config.plane_list, head)
F_57 ( V_59 ) ;
return V_31 ;
}
static void F_102 ( struct V_1 * V_1 )
{
struct V_29 * V_30 = & V_1 -> V_30 ;
F_103 ( V_1 -> V_38 , V_1 -> V_43 ) ;
F_104 ( V_30 -> V_187 ) ;
F_81 ( V_30 ) ;
}
static int F_105 ( struct V_1 * V_1 )
{
const struct V_172 * V_172 = V_1 -> V_70 ;
const struct V_203 * V_204 = V_172 -> V_204 ;
struct V_205 * V_206 ;
int V_173 , V_31 ;
V_1 -> V_32 = F_106 ( V_1 -> V_33 , L_19 ) ;
if ( F_107 ( V_1 -> V_32 ) ) {
F_16 ( V_1 -> V_33 , L_20 ) ;
return F_108 ( V_1 -> V_32 ) ;
}
V_1 -> V_36 = F_106 ( V_1 -> V_33 , L_21 ) ;
if ( F_107 ( V_1 -> V_36 ) ) {
F_16 ( V_1 -> V_33 , L_22 ) ;
return F_108 ( V_1 -> V_36 ) ;
}
V_1 -> V_34 = F_106 ( V_1 -> V_33 , L_23 ) ;
if ( F_107 ( V_1 -> V_34 ) ) {
F_16 ( V_1 -> V_33 , L_24 ) ;
return F_108 ( V_1 -> V_34 ) ;
}
V_31 = F_109 ( V_1 -> V_32 ) ;
if ( V_31 < 0 ) {
F_16 ( V_1 -> V_33 , L_25 ) ;
return V_31 ;
}
V_31 = F_109 ( V_1 -> V_34 ) ;
if ( V_31 < 0 ) {
F_16 ( V_1 -> V_33 , L_26 ) ;
goto V_207;
}
V_31 = F_109 ( V_1 -> V_36 ) ;
if ( V_31 < 0 ) {
F_16 ( V_1 -> V_33 , L_27 ) ;
goto V_208;
}
V_31 = F_15 ( V_1 -> V_32 ) ;
if ( V_31 < 0 ) {
F_16 ( V_1 -> V_33 , L_27 ) ;
goto V_209;
}
V_206 = F_110 ( V_1 -> V_33 , L_28 ) ;
if ( F_107 ( V_206 ) ) {
F_16 ( V_1 -> V_33 , L_29 ) ;
V_31 = F_108 ( V_206 ) ;
goto V_35;
}
F_70 ( V_206 ) ;
F_71 ( 10 , 20 ) ;
F_72 ( V_206 ) ;
memcpy ( V_1 -> V_5 , V_1 -> V_4 , V_1 -> V_210 ) ;
for ( V_173 = 0 ; V_173 < V_172 -> V_211 ; V_173 ++ )
F_1 ( V_1 , V_204 [ V_173 ] . V_2 , V_204 [ V_173 ] . V_212 ) ;
for ( V_173 = 0 ; V_173 < V_172 -> V_175 ; V_173 ++ ) {
const struct V_68 * V_69 = & V_172 -> V_69 [ V_173 ] ;
F_45 ( V_1 , V_69 , V_118 , 0 ) ;
}
F_6 ( V_1 ) ;
V_1 -> V_164 = F_110 ( V_1 -> V_33 , L_30 ) ;
if ( F_107 ( V_1 -> V_164 ) ) {
F_16 ( V_1 -> V_33 , L_31 ) ;
V_31 = F_108 ( V_1 -> V_164 ) ;
goto V_209;
}
F_70 ( V_1 -> V_164 ) ;
F_71 ( 10 , 20 ) ;
F_72 ( V_1 -> V_164 ) ;
F_23 ( V_1 -> V_32 ) ;
V_1 -> V_128 = V_137 ;
return 0 ;
V_35:
F_23 ( V_1 -> V_32 ) ;
V_209:
F_111 ( V_1 -> V_36 ) ;
V_208:
F_111 ( V_1 -> V_34 ) ;
V_207:
F_111 ( V_1 -> V_32 ) ;
return V_31 ;
}
static void F_112 ( struct V_1 * V_1 )
{
const struct V_172 * V_172 = V_1 -> V_70 ;
unsigned int V_173 ;
for ( V_173 = 0 ; V_173 < V_172 -> V_175 ; V_173 ++ ) {
struct V_45 * V_45 = & V_1 -> V_69 [ V_173 ] ;
const struct V_68 * V_188 = & V_172 -> V_69 [ V_173 ] ;
V_45 -> V_70 = V_188 ;
V_45 -> V_1 = V_1 ;
F_113 ( & V_45 -> V_49 ) ;
}
}
static int F_114 ( struct V_184 * V_33 , struct V_184 * V_213 , void * V_70 )
{
struct V_214 * V_215 = F_115 ( V_33 ) ;
const struct V_216 * V_217 ;
const struct V_172 * V_172 ;
struct V_166 * V_38 = V_70 ;
struct V_1 * V_1 ;
struct V_218 * V_219 ;
T_5 V_220 ;
int V_31 ;
V_217 = F_116 ( V_221 , V_33 ) ;
V_172 = V_217 -> V_70 ;
if ( ! V_172 )
return - V_222 ;
V_220 = sizeof( * V_1 ) + sizeof( * V_1 -> V_69 ) * V_172 -> V_175 ;
V_1 = F_117 ( V_33 , V_220 , V_56 ) ;
if ( ! V_1 )
return - V_57 ;
V_1 -> V_33 = V_33 ;
V_1 -> V_70 = V_172 ;
V_1 -> V_38 = V_38 ;
F_118 ( V_33 , V_1 ) ;
F_112 ( V_1 ) ;
V_219 = F_119 ( V_215 , V_223 , 0 ) ;
V_1 -> V_210 = F_120 ( V_219 ) ;
V_1 -> V_4 = F_121 ( V_33 , V_219 ) ;
if ( F_107 ( V_1 -> V_4 ) )
return F_108 ( V_1 -> V_4 ) ;
V_1 -> V_5 = F_117 ( V_33 , V_1 -> V_210 , V_56 ) ;
if ( ! V_1 -> V_5 )
return - V_57 ;
V_31 = F_105 ( V_1 ) ;
if ( V_31 < 0 ) {
F_16 ( & V_215 -> V_33 , L_32 , V_31 ) ;
return V_31 ;
}
V_1 -> V_42 = F_122 ( V_215 , 0 ) ;
if ( V_1 -> V_42 < 0 ) {
F_16 ( V_33 , L_33 ) ;
return V_1 -> V_42 ;
}
F_123 ( & V_1 -> V_40 ) ;
F_123 ( & V_1 -> V_131 ) ;
F_124 ( & V_1 -> V_104 ) ;
V_31 = F_125 ( V_33 , V_1 -> V_42 , F_93 , F_92 ,
V_224 , F_126 ( V_33 ) , V_1 ) ;
if ( V_31 )
return V_31 ;
F_26 ( V_1 -> V_42 ) ;
V_31 = F_95 ( V_1 ) ;
if ( V_31 )
return V_31 ;
F_127 ( & V_215 -> V_33 ) ;
return 0 ;
}
static void F_128 ( struct V_184 * V_33 , struct V_184 * V_213 , void * V_70 )
{
struct V_1 * V_1 = F_129 ( V_33 ) ;
F_130 ( V_33 ) ;
F_102 ( V_1 ) ;
}
static int F_131 ( struct V_214 * V_215 )
{
struct V_184 * V_33 = & V_215 -> V_33 ;
if ( ! V_33 -> V_200 ) {
F_16 ( V_33 , L_34 ) ;
return - V_222 ;
}
return F_132 ( V_33 , & V_225 ) ;
}
static int F_133 ( struct V_214 * V_215 )
{
F_134 ( & V_215 -> V_33 , & V_225 ) ;
return 0 ;
}
