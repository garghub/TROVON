static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( F_4 ( V_6 ) ,
struct V_1 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_4 . V_4 . V_8 ;
struct V_9 * V_9 = F_6 ( V_1 -> V_4 . V_4 . V_10 ) ;
struct V_11 * V_12 = V_8 -> V_13 ;
T_1 V_14 , V_15 , V_16 ;
if ( F_7 ( V_8 ) ) {
V_14 = V_17 ;
V_15 = V_18 ;
V_16 = V_19 ;
} else {
V_14 = V_20 ;
V_15 = V_21 ;
V_16 = V_22 ;
}
F_8 ( V_15 , F_9 ( V_15 ) | V_23 ) ;
if ( V_1 -> V_24 ) {
F_10 ( L_1 ,
V_1 -> V_25 ,
V_1 -> V_26 ) ;
F_8 ( V_27 , V_1 -> V_26 ) ;
F_8 ( V_28 , V_1 -> V_25 ) ;
V_1 -> V_24 = false ;
}
F_8 ( V_14 , F_9 ( V_14 ) | V_29 ) ;
F_11 ( V_15 ) ;
if ( F_12 ( ( F_9 ( V_16 ) & V_30 ) != 0 , 1000 ) )
F_13 ( L_2 ) ;
F_14 ( V_8 , V_9 -> V_31 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_4 . V_4 . V_8 ;
struct V_11 * V_12 = V_8 -> V_13 ;
T_1 V_14 , V_15 , V_16 ;
if ( F_7 ( V_8 ) ) {
V_14 = V_17 ;
V_15 = V_18 ;
V_16 = V_19 ;
} else {
V_14 = V_20 ;
V_15 = V_21 ;
V_16 = V_22 ;
}
F_16 ( V_8 ) ;
F_8 ( V_14 , F_9 ( V_14 ) & ~ V_29 ) ;
if ( F_12 ( ( F_9 ( V_16 ) & V_30 ) == 0 , 1000 ) )
F_13 ( L_3 ) ;
if ( V_1 -> V_25 ) {
F_8 ( V_28 , 0 ) ;
V_1 -> V_24 = true ;
}
F_8 ( V_15 , F_9 ( V_15 ) & ~ V_23 ) ;
F_11 ( V_15 ) ;
}
static void F_17 ( struct V_2 * V_3 , int V_32 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_32 == V_33 )
F_5 ( V_1 ) ;
else
F_15 ( V_1 ) ;
}
static int F_18 ( struct V_5 * V_6 ,
struct V_34 * V_32 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_34 * V_35 = V_1 -> V_35 ;
if ( V_32 -> V_36 > V_35 -> V_36 )
return V_37 ;
if ( V_32 -> V_38 > V_35 -> V_38 )
return V_37 ;
return V_39 ;
}
static void
F_19 ( struct V_34 * V_32 ,
int V_40 )
{
T_1 V_41 , V_42 , V_43 , V_44 ;
V_44 = V_32 -> V_45 - V_32 -> V_46 ;
V_43 = V_32 -> V_47 - V_32 -> V_48 ;
V_42 = ( V_43 - V_44 + 1 ) / 2 ;
V_41 = ( V_32 -> V_36 - V_40 + 1 ) / 2 ;
V_41 += V_41 & 1 ;
V_32 -> V_49 = V_40 ;
V_32 -> V_48 = V_40 + V_41 ;
V_32 -> V_47 = V_32 -> V_48 + V_43 ;
V_32 -> V_46 = V_32 -> V_48 + V_42 ;
V_32 -> V_45 = V_32 -> V_46 + V_44 ;
V_32 -> V_50 |= V_51 ;
}
static void
F_20 ( struct V_34 * V_32 ,
int V_52 )
{
T_1 V_41 , V_42 , V_43 , V_44 ;
V_44 = V_32 -> V_53 - V_32 -> V_54 ;
V_43 = V_32 -> V_55 - V_32 -> V_56 ;
V_42 = ( V_43 - V_44 + 1 ) / 2 ;
V_41 = ( V_32 -> V_38 - V_52 + 1 ) / 2 ;
V_32 -> V_57 = V_52 ;
V_32 -> V_56 = V_52 + V_41 ;
V_32 -> V_55 = V_32 -> V_56 + V_43 ;
V_32 -> V_54 = V_32 -> V_56 + V_42 ;
V_32 -> V_53 = V_32 -> V_54 + V_44 ;
V_32 -> V_50 |= V_51 ;
}
static inline T_1 F_21 ( T_1 V_58 , T_1 V_59 )
{
#define F_22 12
#define F_23 (1 << ACCURACY)
T_1 V_60 = V_58 * F_23 / V_59 ;
return ( F_23 * V_60 + F_23 / 2 ) / F_23 ;
}
static bool F_24 ( struct V_2 * V_3 ,
const struct V_34 * V_32 ,
struct V_34 * V_61 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_11 * V_12 = V_8 -> V_13 ;
struct V_9 * V_9 = F_6 ( V_3 -> V_10 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_62 * V_63 ;
T_1 V_25 = 0 , V_26 = 0 , V_41 = 0 ;
int V_31 ;
if ( F_25 ( V_8 ) -> V_64 < 4 && V_9 -> V_31 == 0 ) {
F_13 ( L_4 ) ;
return false ;
}
F_26 (dev, encoder->crtc, tmp_encoder) {
if ( & V_63 -> V_4 != V_3 ) {
F_13 ( L_5
L_6 ) ;
return false ;
}
}
F_27 ( V_1 -> V_35 , V_61 ) ;
if ( F_7 ( V_8 ) ) {
F_28 ( V_8 , V_1 -> V_65 ,
V_32 , V_61 ) ;
return true ;
}
if ( V_61 -> V_36 == V_32 -> V_36 &&
V_61 -> V_38 == V_32 -> V_38 )
goto V_66;
if ( F_25 ( V_8 ) -> V_64 >= 4 )
V_25 |= ( ( V_9 -> V_31 << V_67 ) |
V_68 ) ;
F_29 (pipe)
F_8 ( F_30 ( V_31 ) , 0 ) ;
F_31 ( V_61 , 0 ) ;
switch ( V_1 -> V_65 ) {
case V_69 :
F_19 ( V_61 , V_32 -> V_36 ) ;
F_20 ( V_61 , V_32 -> V_38 ) ;
V_41 = V_70 ;
break;
case V_71 :
if ( F_25 ( V_8 ) -> V_64 >= 4 ) {
T_1 V_72 = V_61 -> V_36 * V_32 -> V_38 ;
T_1 V_73 = V_32 -> V_36 * V_61 -> V_38 ;
if ( V_72 > V_73 )
V_25 |= V_74 | V_75 ;
else if ( V_72 < V_73 )
V_25 |= V_74 | V_76 ;
else if ( V_61 -> V_36 != V_32 -> V_36 )
V_25 |= V_74 | V_77 ;
} else {
T_1 V_72 = V_61 -> V_36 * V_32 -> V_38 ;
T_1 V_73 = V_32 -> V_36 * V_61 -> V_38 ;
if ( V_72 > V_73 ) {
F_19 ( V_61 , V_73 / V_32 -> V_38 ) ;
V_41 = V_70 ;
if ( V_32 -> V_38 != V_61 -> V_38 ) {
T_1 V_78 = F_21 ( V_32 -> V_38 , V_61 -> V_38 ) ;
V_26 |= ( V_78 << V_79 |
V_78 << V_80 ) ;
V_25 |= ( V_74 |
V_81 |
V_82 ) ;
}
} else if ( V_72 < V_73 ) {
F_20 ( V_61 , V_72 / V_32 -> V_36 ) ;
V_41 = V_70 ;
if ( V_32 -> V_36 != V_61 -> V_36 ) {
T_1 V_78 = F_21 ( V_32 -> V_36 , V_61 -> V_36 ) ;
V_26 |= ( V_78 << V_79 |
V_78 << V_80 ) ;
V_25 |= ( V_74 |
V_81 |
V_82 ) ;
}
} else
V_25 |= ( V_74 |
V_83 | V_84 |
V_81 |
V_82 ) ;
}
break;
case V_85 :
if ( V_32 -> V_38 != V_61 -> V_38 ||
V_32 -> V_36 != V_61 -> V_36 ) {
V_25 |= V_74 ;
if ( F_25 ( V_8 ) -> V_64 >= 4 )
V_25 |= V_77 ;
else
V_25 |= ( V_83 |
V_81 |
V_84 |
V_82 ) ;
}
break;
default:
break;
}
V_66:
if ( ( V_25 & V_74 ) == 0 ) {
V_25 = 0 ;
V_26 = 0 ;
}
if ( F_25 ( V_8 ) -> V_64 < 4 && V_12 -> V_86 )
V_25 |= V_87 ;
if ( V_25 != V_1 -> V_25 ||
V_26 != V_1 -> V_26 ) {
V_1 -> V_25 = V_25 ;
V_1 -> V_26 = V_26 ;
V_1 -> V_24 = true ;
}
V_12 -> V_88 = V_41 ;
return true ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_15 ( V_1 ) ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_5 ( V_1 ) ;
}
static void F_34 ( struct V_2 * V_3 ,
struct V_34 * V_32 ,
struct V_34 * V_61 )
{
}
static enum V_89
F_35 ( struct V_5 * V_6 , bool V_90 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
enum V_89 V_91 ;
V_91 = F_36 ( V_8 ) ;
if ( V_91 != V_92 )
return V_91 ;
return V_93 ;
}
static int F_37 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_34 * V_32 ;
if ( V_1 -> V_94 )
return F_38 ( V_6 , V_1 -> V_94 ) ;
V_32 = F_39 ( V_8 , V_1 -> V_35 ) ;
if ( V_32 == NULL )
return 0 ;
F_40 ( V_6 , V_32 ) ;
return 1 ;
}
static int F_41 ( const struct V_95 * V_96 )
{
F_42 ( L_7 , V_96 -> V_97 ) ;
return 1 ;
}
static int F_43 ( struct V_98 * V_99 , unsigned long V_100 ,
void * V_101 )
{
struct V_11 * V_12 =
F_2 ( V_99 , struct V_11 , V_102 ) ;
struct V_7 * V_8 = V_12 -> V_8 ;
struct V_5 * V_6 = V_12 -> V_103 ;
if ( V_8 -> V_104 != V_105 )
return V_106 ;
if ( V_6 )
V_6 -> V_91 = V_6 -> V_107 -> V_108 ( V_6 ,
false ) ;
if ( F_44 ( V_109 ) )
return V_106 ;
if ( ! F_45 () ) {
V_12 -> V_110 = 1 ;
return V_106 ;
}
if ( ! V_12 -> V_110 )
return V_106 ;
V_12 -> V_110 = 0 ;
F_46 ( & V_8 -> V_111 . V_112 ) ;
F_47 ( V_8 ) ;
F_48 ( & V_8 -> V_111 . V_112 ) ;
return V_106 ;
}
static void F_49 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_11 * V_12 = V_8 -> V_13 ;
F_50 ( V_8 ) ;
if ( V_12 -> V_102 . V_113 )
F_51 ( & V_12 -> V_102 ) ;
F_52 ( V_6 ) ;
F_53 ( V_6 ) ;
F_54 ( V_6 ) ;
}
static int F_55 ( struct V_5 * V_6 ,
struct V_114 * V_115 ,
T_2 V_116 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_115 == V_8 -> V_111 . V_117 ) {
struct V_118 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
if ( V_116 == V_119 ) {
F_10 ( L_8 ) ;
return - V_120 ;
}
if ( V_1 -> V_65 == V_116 ) {
return 0 ;
}
V_1 -> V_65 = V_116 ;
if ( V_10 && V_10 -> V_121 ) {
F_56 ( V_10 , & V_10 -> V_32 ,
V_10 -> V_122 , V_10 -> V_123 , V_10 -> V_124 ) ;
}
}
return 0 ;
}
static int T_3 F_57 ( const struct V_95 * V_96 )
{
F_42 ( L_9 , V_96 -> V_97 ) ;
return 1 ;
}
static void F_58 ( struct V_7 * V_8 ,
struct V_34 * V_35 ,
struct V_5 * V_6 )
{
struct V_11 * V_12 = V_8 -> V_13 ;
struct V_34 * V_125 ;
int V_126 ;
V_126 = V_35 -> clock ;
F_59 (scan, &connector->probed_modes, head) {
if ( V_125 -> V_36 == V_35 -> V_36 &&
V_125 -> V_127 == V_35 -> V_127 &&
V_125 -> V_128 == V_35 -> V_128 &&
V_125 -> V_129 == V_35 -> V_129 &&
V_125 -> V_38 == V_35 -> V_38 &&
V_125 -> V_130 == V_35 -> V_130 &&
V_125 -> V_131 == V_35 -> V_131 &&
V_125 -> V_132 == V_35 -> V_132 ) {
if ( V_125 -> clock < V_126 ) {
V_126 = V_125 -> clock ;
}
}
}
if ( V_126 < V_35 -> clock && V_133 ) {
V_12 -> V_134 = 1 ;
V_12 -> V_135 = V_126 ;
F_10 ( L_10
L_11 ,
V_35 -> clock , V_126 ) ;
}
}
static bool F_60 ( struct V_7 * V_8 ,
T_4 * V_136 )
{
struct V_11 * V_12 = V_8 -> V_13 ;
int V_137 ;
if ( ! V_12 -> V_138 )
return true ;
for ( V_137 = 0 ; V_137 < V_12 -> V_138 ; V_137 ++ ) {
struct V_139 * V_140 = V_12 -> V_141 + V_137 ;
if ( V_140 -> V_142 != V_143 &&
V_140 -> V_142 != V_144 )
continue;
if ( F_61 ( V_140 -> V_136 ) )
* V_136 = V_140 -> V_136 ;
if ( V_140 -> V_145 )
return true ;
if ( V_12 -> V_146 . V_147 )
return true ;
}
return false ;
}
static bool F_62 ( struct V_7 * V_8 )
{
if ( F_7 ( V_8 ) )
return true ;
return F_63 ( V_8 ) && ! F_64 ( V_8 ) ;
}
bool F_65 ( struct V_7 * V_8 )
{
struct V_11 * V_12 = V_8 -> V_13 ;
struct V_1 * V_1 ;
struct V_62 * V_62 ;
struct V_148 * V_148 ;
struct V_5 * V_6 ;
struct V_2 * V_3 ;
struct V_34 * V_125 ;
struct V_118 * V_10 ;
T_1 V_149 ;
int V_31 ;
T_4 V_150 ;
if ( ! F_62 ( V_8 ) )
return false ;
if ( F_44 ( V_151 ) )
return false ;
V_150 = V_152 ;
if ( ! F_60 ( V_8 , & V_150 ) ) {
F_10 ( L_12 ) ;
return false ;
}
if ( F_7 ( V_8 ) ) {
if ( ( F_9 ( V_18 ) & V_153 ) == 0 )
return false ;
if ( V_12 -> V_154 . V_155 ) {
F_10 ( L_13 ) ;
return false ;
}
}
V_1 = F_66 ( sizeof( struct V_1 ) , V_156 ) ;
if ( ! V_1 ) {
return false ;
}
V_148 = F_66 ( sizeof( struct V_148 ) , V_156 ) ;
if ( ! V_148 ) {
F_54 ( V_1 ) ;
return false ;
}
if ( ! F_7 ( V_8 ) ) {
V_1 -> V_25 = F_9 ( V_28 ) ;
}
V_62 = & V_1 -> V_4 ;
V_3 = & V_62 -> V_4 ;
V_6 = & V_148 -> V_4 ;
F_67 ( V_8 , & V_148 -> V_4 , & V_157 ,
V_158 ) ;
F_68 ( V_8 , & V_62 -> V_4 , & V_159 ,
V_160 ) ;
F_69 ( V_148 , V_62 ) ;
V_62 -> type = V_161 ;
V_62 -> V_162 = ( 1 << V_163 ) ;
if ( F_7 ( V_8 ) )
V_62 -> V_164 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
else if ( F_70 ( V_8 ) )
V_62 -> V_164 = ( 1 << 0 ) | ( 1 << 1 ) ;
else
V_62 -> V_164 = ( 1 << 1 ) ;
F_71 ( V_3 , & V_165 ) ;
F_72 ( V_6 , & V_166 ) ;
V_6 -> V_167 . V_168 = V_169 ;
V_6 -> V_170 = false ;
V_6 -> V_171 = false ;
F_73 ( V_8 ) ;
F_74 ( & V_148 -> V_4 ,
V_8 -> V_111 . V_117 ,
V_71 ) ;
V_1 -> V_65 = V_71 ;
V_1 -> V_94 = F_75 ( V_6 ,
F_76 ( V_12 ,
V_150 ) ) ;
if ( V_1 -> V_94 ) {
if ( F_38 ( V_6 ,
V_1 -> V_94 ) ) {
F_77 ( V_6 ,
V_1 -> V_94 ) ;
} else {
F_54 ( V_1 -> V_94 ) ;
V_1 -> V_94 = NULL ;
}
}
if ( ! V_1 -> V_94 ) {
V_6 -> V_167 . V_172 = 0 ;
V_6 -> V_167 . V_173 = 200 ;
V_6 -> V_167 . V_174 = 0 ;
V_6 -> V_167 . V_175 = 200 ;
}
F_59 (scan, &connector->probed_modes, head) {
if ( V_125 -> type & V_176 ) {
V_1 -> V_35 =
F_39 ( V_8 , V_125 ) ;
F_58 ( V_8 ,
V_1 -> V_35 ,
V_6 ) ;
goto V_66;
}
}
if ( V_12 -> V_177 ) {
V_1 -> V_35 =
F_39 ( V_8 , V_12 -> V_177 ) ;
if ( V_1 -> V_35 ) {
V_1 -> V_35 -> type |=
V_176 ;
goto V_66;
}
}
if ( F_7 ( V_8 ) )
goto V_178;
V_149 = F_9 ( V_21 ) ;
V_31 = ( V_149 & V_179 ) ? 1 : 0 ;
V_10 = F_78 ( V_8 , V_31 ) ;
if ( V_10 && ( V_149 & V_23 ) ) {
V_1 -> V_35 = F_79 ( V_8 , V_10 ) ;
if ( V_1 -> V_35 ) {
V_1 -> V_35 -> type |=
V_176 ;
goto V_66;
}
}
if ( ! V_1 -> V_35 )
goto V_178;
V_66:
if ( F_7 ( V_8 ) ) {
F_8 ( V_17 ,
F_9 ( V_17 ) | V_180 ) ;
} else {
F_8 ( V_20 ,
F_9 ( V_20 ) | V_180 ) ;
}
V_12 -> V_102 . V_113 = F_43 ;
if ( F_80 ( & V_12 -> V_102 ) ) {
F_10 ( L_14 ) ;
V_12 -> V_102 . V_113 = NULL ;
}
V_12 -> V_103 = V_6 ;
F_81 ( V_6 ) ;
F_82 ( V_8 ) ;
return true ;
V_178:
F_10 ( L_15 ) ;
F_53 ( V_6 ) ;
F_83 ( V_3 ) ;
F_54 ( V_1 ) ;
F_54 ( V_148 ) ;
return false ;
}
