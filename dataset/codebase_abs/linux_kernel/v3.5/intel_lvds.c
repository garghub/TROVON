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
struct V_9 * V_10 = V_8 -> V_11 ;
T_1 V_12 , V_13 , V_14 ;
if ( F_6 ( V_8 ) ) {
V_12 = V_15 ;
V_13 = V_16 ;
V_14 = V_17 ;
} else {
V_12 = V_18 ;
V_13 = V_19 ;
V_14 = V_20 ;
}
F_7 ( V_13 , F_8 ( V_13 ) | V_21 ) ;
if ( V_1 -> V_22 ) {
F_9 ( L_1 ,
V_1 -> V_23 ,
V_1 -> V_24 ) ;
F_7 ( V_25 , V_1 -> V_24 ) ;
F_7 ( V_26 , V_1 -> V_23 ) ;
V_1 -> V_22 = false ;
}
F_7 ( V_12 , F_8 ( V_12 ) | V_27 ) ;
F_10 ( V_13 ) ;
if ( F_11 ( ( F_8 ( V_14 ) & V_28 ) != 0 , 1000 ) )
F_12 ( L_2 ) ;
F_13 ( V_8 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_4 . V_4 . V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
T_1 V_12 , V_13 , V_14 ;
if ( F_6 ( V_8 ) ) {
V_12 = V_15 ;
V_13 = V_16 ;
V_14 = V_17 ;
} else {
V_12 = V_18 ;
V_13 = V_19 ;
V_14 = V_20 ;
}
F_15 ( V_8 ) ;
F_7 ( V_12 , F_8 ( V_12 ) & ~ V_27 ) ;
if ( F_11 ( ( F_8 ( V_14 ) & V_28 ) == 0 , 1000 ) )
F_12 ( L_3 ) ;
if ( V_1 -> V_23 ) {
F_7 ( V_26 , 0 ) ;
V_1 -> V_22 = true ;
}
F_7 ( V_13 , F_8 ( V_13 ) & ~ V_21 ) ;
F_10 ( V_13 ) ;
}
static void F_16 ( struct V_2 * V_3 , int V_29 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_29 == V_30 )
F_5 ( V_1 ) ;
else
F_14 ( V_1 ) ;
}
static int F_17 ( struct V_5 * V_6 ,
struct V_31 * V_29 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_31 * V_32 = V_1 -> V_32 ;
if ( V_29 -> V_33 > V_32 -> V_33 )
return V_34 ;
if ( V_29 -> V_35 > V_32 -> V_35 )
return V_34 ;
return V_36 ;
}
static void
F_18 ( struct V_31 * V_29 ,
int V_37 )
{
T_1 V_38 , V_39 , V_40 , V_41 ;
V_41 = V_29 -> V_42 - V_29 -> V_43 ;
V_40 = V_29 -> V_44 - V_29 -> V_45 ;
V_39 = ( V_40 - V_41 + 1 ) / 2 ;
V_38 = ( V_29 -> V_33 - V_37 + 1 ) / 2 ;
V_38 += V_38 & 1 ;
V_29 -> V_46 = V_37 ;
V_29 -> V_45 = V_37 + V_38 ;
V_29 -> V_44 = V_29 -> V_45 + V_40 ;
V_29 -> V_43 = V_29 -> V_45 + V_39 ;
V_29 -> V_42 = V_29 -> V_43 + V_41 ;
V_29 -> V_47 |= V_48 ;
}
static void
F_19 ( struct V_31 * V_29 ,
int V_49 )
{
T_1 V_38 , V_39 , V_40 , V_41 ;
V_41 = V_29 -> V_50 - V_29 -> V_51 ;
V_40 = V_29 -> V_52 - V_29 -> V_53 ;
V_39 = ( V_40 - V_41 + 1 ) / 2 ;
V_38 = ( V_29 -> V_35 - V_49 + 1 ) / 2 ;
V_29 -> V_54 = V_49 ;
V_29 -> V_53 = V_49 + V_38 ;
V_29 -> V_52 = V_29 -> V_53 + V_40 ;
V_29 -> V_51 = V_29 -> V_53 + V_39 ;
V_29 -> V_50 = V_29 -> V_51 + V_41 ;
V_29 -> V_47 |= V_48 ;
}
static inline T_1 F_20 ( T_1 V_55 , T_1 V_56 )
{
#define F_21 12
#define F_22 (1 << ACCURACY)
T_1 V_57 = V_55 * F_22 / V_56 ;
return ( F_22 * V_57 + F_22 / 2 ) / F_22 ;
}
static bool F_23 ( struct V_2 * V_3 ,
struct V_31 * V_29 ,
struct V_31 * V_58 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_59 * V_59 = F_24 ( V_3 -> V_60 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_2 * V_61 ;
T_1 V_23 = 0 , V_24 = 0 , V_38 = 0 ;
int V_62 ;
if ( F_25 ( V_8 ) -> V_63 < 4 && V_59 -> V_62 == 0 ) {
F_12 ( L_4 ) ;
return false ;
}
F_26 (tmp_encoder, &dev->mode_config.encoder_list, head) {
if ( V_61 != V_3 && V_61 -> V_60 == V_3 -> V_60 ) {
F_12 ( L_5
L_6 ) ;
return false ;
}
}
F_27 ( V_1 -> V_32 , V_58 ) ;
if ( F_6 ( V_8 ) ) {
F_28 ( V_8 , V_1 -> V_64 ,
V_29 , V_58 ) ;
return true ;
}
if ( V_58 -> V_33 == V_29 -> V_33 &&
V_58 -> V_35 == V_29 -> V_35 )
goto V_65;
if ( F_25 ( V_8 ) -> V_63 >= 4 )
V_23 |= ( ( V_59 -> V_62 << V_66 ) |
V_67 ) ;
F_29 (pipe)
F_7 ( F_30 ( V_62 ) , 0 ) ;
F_31 ( V_58 , 0 ) ;
switch ( V_1 -> V_64 ) {
case V_68 :
F_18 ( V_58 , V_29 -> V_33 ) ;
F_19 ( V_58 , V_29 -> V_35 ) ;
V_38 = V_69 ;
break;
case V_70 :
if ( F_25 ( V_8 ) -> V_63 >= 4 ) {
T_1 V_71 = V_58 -> V_33 * V_29 -> V_35 ;
T_1 V_72 = V_29 -> V_33 * V_58 -> V_35 ;
if ( V_71 > V_72 )
V_23 |= V_73 | V_74 ;
else if ( V_71 < V_72 )
V_23 |= V_73 | V_75 ;
else if ( V_58 -> V_33 != V_29 -> V_33 )
V_23 |= V_73 | V_76 ;
} else {
T_1 V_71 = V_58 -> V_33 * V_29 -> V_35 ;
T_1 V_72 = V_29 -> V_33 * V_58 -> V_35 ;
if ( V_71 > V_72 ) {
F_18 ( V_58 , V_72 / V_29 -> V_35 ) ;
V_38 = V_69 ;
if ( V_29 -> V_35 != V_58 -> V_35 ) {
T_1 V_77 = F_20 ( V_29 -> V_35 , V_58 -> V_35 ) ;
V_24 |= ( V_77 << V_78 |
V_77 << V_79 ) ;
V_23 |= ( V_73 |
V_80 |
V_81 ) ;
}
} else if ( V_71 < V_72 ) {
F_19 ( V_58 , V_71 / V_29 -> V_33 ) ;
V_38 = V_69 ;
if ( V_29 -> V_33 != V_58 -> V_33 ) {
T_1 V_77 = F_20 ( V_29 -> V_33 , V_58 -> V_33 ) ;
V_24 |= ( V_77 << V_78 |
V_77 << V_79 ) ;
V_23 |= ( V_73 |
V_80 |
V_81 ) ;
}
} else
V_23 |= ( V_73 |
V_82 | V_83 |
V_80 |
V_81 ) ;
}
break;
case V_84 :
if ( V_29 -> V_35 != V_58 -> V_35 ||
V_29 -> V_33 != V_58 -> V_33 ) {
V_23 |= V_73 ;
if ( F_25 ( V_8 ) -> V_63 >= 4 )
V_23 |= V_76 ;
else
V_23 |= ( V_82 |
V_80 |
V_83 |
V_81 ) ;
}
break;
default:
break;
}
V_65:
if ( ( V_23 & V_73 ) == 0 ) {
V_23 = 0 ;
V_24 = 0 ;
}
if ( F_25 ( V_8 ) -> V_63 < 4 && V_10 -> V_85 )
V_23 |= V_86 ;
if ( V_23 != V_1 -> V_23 ||
V_24 != V_1 -> V_24 ) {
V_1 -> V_23 = V_23 ;
V_1 -> V_24 = V_24 ;
V_1 -> V_22 = true ;
}
V_10 -> V_87 = V_38 ;
return true ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! F_6 ( V_3 -> V_8 ) && V_1 -> V_22 )
F_14 ( V_1 ) ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_5 ( V_1 ) ;
}
static void F_34 ( struct V_2 * V_3 ,
struct V_31 * V_29 ,
struct V_31 * V_58 )
{
}
static enum V_88
F_35 ( struct V_5 * V_6 , bool V_89 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
enum V_88 V_90 ;
V_90 = F_36 ( V_8 ) ;
if ( V_90 != V_91 )
return V_90 ;
return V_92 ;
}
static int F_37 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_31 * V_29 ;
if ( V_1 -> V_93 )
return F_38 ( V_6 , V_1 -> V_93 ) ;
V_29 = F_39 ( V_8 , V_1 -> V_32 ) ;
if ( V_29 == NULL )
return 0 ;
F_40 ( V_6 , V_29 ) ;
return 1 ;
}
static int F_41 ( const struct V_94 * V_95 )
{
F_42 ( L_7 , V_95 -> V_96 ) ;
return 1 ;
}
static int F_43 ( struct V_97 * V_98 , unsigned long V_99 ,
void * V_100 )
{
struct V_9 * V_10 =
F_2 ( V_98 , struct V_9 , V_101 ) ;
struct V_7 * V_8 = V_10 -> V_8 ;
struct V_5 * V_6 = V_10 -> V_102 ;
if ( V_8 -> V_103 != V_104 )
return V_105 ;
if ( V_6 )
V_6 -> V_90 = V_6 -> V_106 -> V_107 ( V_6 ,
false ) ;
if ( F_44 ( V_108 ) )
return V_105 ;
if ( ! F_45 () ) {
V_10 -> V_109 = 1 ;
return V_105 ;
}
if ( ! V_10 -> V_109 )
return V_105 ;
V_10 -> V_109 = 0 ;
F_46 ( & V_8 -> V_110 . V_111 ) ;
F_47 ( V_8 ) ;
F_48 ( & V_8 -> V_110 . V_111 ) ;
return V_105 ;
}
static void F_49 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
F_50 ( V_8 ) ;
if ( V_10 -> V_101 . V_112 )
F_51 ( & V_10 -> V_101 ) ;
F_52 ( V_6 ) ;
F_53 ( V_6 ) ;
F_54 ( V_6 ) ;
}
static int F_55 ( struct V_5 * V_6 ,
struct V_113 * V_114 ,
T_2 V_115 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_114 == V_8 -> V_110 . V_116 ) {
struct V_117 * V_60 = V_1 -> V_4 . V_4 . V_60 ;
if ( V_115 == V_118 ) {
F_9 ( L_8 ) ;
return - V_119 ;
}
if ( V_1 -> V_64 == V_115 ) {
return 0 ;
}
V_1 -> V_64 = V_115 ;
if ( V_60 && V_60 -> V_120 ) {
F_56 ( V_60 , & V_60 -> V_29 ,
V_60 -> V_121 , V_60 -> V_122 , V_60 -> V_123 ) ;
}
}
return 0 ;
}
static int T_3 F_57 ( const struct V_94 * V_95 )
{
F_42 ( L_9 , V_95 -> V_96 ) ;
return 1 ;
}
static void F_58 ( struct V_7 * V_8 ,
struct V_31 * V_32 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_31 * V_124 ;
int V_125 ;
V_125 = V_32 -> clock ;
F_26 (scan, &connector->probed_modes, head) {
if ( V_124 -> V_33 == V_32 -> V_33 &&
V_124 -> V_126 == V_32 -> V_126 &&
V_124 -> V_127 == V_32 -> V_127 &&
V_124 -> V_128 == V_32 -> V_128 &&
V_124 -> V_35 == V_32 -> V_35 &&
V_124 -> V_129 == V_32 -> V_129 &&
V_124 -> V_130 == V_32 -> V_130 &&
V_124 -> V_131 == V_32 -> V_131 ) {
if ( V_124 -> clock < V_125 ) {
V_125 = V_124 -> clock ;
}
}
}
if ( V_125 < V_32 -> clock && V_132 ) {
V_10 -> V_133 = 1 ;
V_10 -> V_134 = V_125 ;
F_9 ( L_10
L_11 ,
V_32 -> clock , V_125 ) ;
}
}
static bool F_59 ( struct V_7 * V_8 ,
T_4 * V_135 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
int V_136 ;
if ( ! V_10 -> V_137 )
return true ;
for ( V_136 = 0 ; V_136 < V_10 -> V_137 ; V_136 ++ ) {
struct V_138 * V_139 = V_10 -> V_140 + V_136 ;
if ( V_139 -> V_141 != V_142 &&
V_139 -> V_141 != V_143 )
continue;
if ( F_60 ( V_139 -> V_135 ) )
* V_135 = V_139 -> V_135 ;
if ( V_139 -> V_144 )
return true ;
if ( V_10 -> V_145 . V_146 )
return true ;
}
return false ;
}
static bool F_61 ( struct V_7 * V_8 )
{
if ( F_6 ( V_8 ) )
return true ;
return F_62 ( V_8 ) && ! F_63 ( V_8 ) ;
}
bool F_64 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_1 ;
struct V_147 * V_147 ;
struct V_148 * V_148 ;
struct V_5 * V_6 ;
struct V_2 * V_3 ;
struct V_31 * V_124 ;
struct V_117 * V_60 ;
T_1 V_149 ;
int V_62 ;
T_4 V_150 ;
if ( ! F_61 ( V_8 ) )
return false ;
if ( F_44 ( V_151 ) )
return false ;
V_150 = V_152 ;
if ( ! F_59 ( V_8 , & V_150 ) ) {
F_9 ( L_12 ) ;
return false ;
}
if ( F_6 ( V_8 ) ) {
if ( ( F_8 ( V_16 ) & V_153 ) == 0 )
return false ;
if ( V_10 -> V_154 . V_155 ) {
F_9 ( L_13 ) ;
return false ;
}
}
V_1 = F_65 ( sizeof( struct V_1 ) , V_156 ) ;
if ( ! V_1 ) {
return false ;
}
V_148 = F_65 ( sizeof( struct V_148 ) , V_156 ) ;
if ( ! V_148 ) {
F_54 ( V_1 ) ;
return false ;
}
if ( ! F_6 ( V_8 ) ) {
V_1 -> V_23 = F_8 ( V_26 ) ;
}
V_147 = & V_1 -> V_4 ;
V_3 = & V_147 -> V_4 ;
V_6 = & V_148 -> V_4 ;
F_66 ( V_8 , & V_148 -> V_4 , & V_157 ,
V_158 ) ;
F_67 ( V_8 , & V_147 -> V_4 , & V_159 ,
V_160 ) ;
F_68 ( V_148 , V_147 ) ;
V_147 -> type = V_161 ;
V_147 -> V_162 = ( 1 << V_163 ) ;
if ( F_6 ( V_8 ) )
V_147 -> V_164 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
else
V_147 -> V_164 = ( 1 << 1 ) ;
F_69 ( V_3 , & V_165 ) ;
F_70 ( V_6 , & V_166 ) ;
V_6 -> V_167 . V_168 = V_169 ;
V_6 -> V_170 = false ;
V_6 -> V_171 = false ;
F_71 ( V_8 ) ;
F_72 ( & V_148 -> V_4 ,
V_8 -> V_110 . V_116 ,
V_70 ) ;
V_1 -> V_64 = V_70 ;
V_1 -> V_93 = F_73 ( V_6 ,
F_74 ( V_10 ,
V_150 ) ) ;
if ( V_1 -> V_93 ) {
if ( F_38 ( V_6 ,
V_1 -> V_93 ) ) {
F_75 ( V_6 ,
V_1 -> V_93 ) ;
} else {
F_54 ( V_1 -> V_93 ) ;
V_1 -> V_93 = NULL ;
}
}
if ( ! V_1 -> V_93 ) {
V_6 -> V_167 . V_172 = 0 ;
V_6 -> V_167 . V_173 = 200 ;
V_6 -> V_167 . V_174 = 0 ;
V_6 -> V_167 . V_175 = 200 ;
}
F_26 (scan, &connector->probed_modes, head) {
if ( V_124 -> type & V_176 ) {
V_1 -> V_32 =
F_39 ( V_8 , V_124 ) ;
F_58 ( V_8 ,
V_1 -> V_32 ,
V_6 ) ;
goto V_65;
}
}
if ( V_10 -> V_177 ) {
V_1 -> V_32 =
F_39 ( V_8 , V_10 -> V_177 ) ;
if ( V_1 -> V_32 ) {
V_1 -> V_32 -> type |=
V_176 ;
goto V_65;
}
}
if ( F_6 ( V_8 ) )
goto V_178;
V_149 = F_8 ( V_19 ) ;
V_62 = ( V_149 & V_179 ) ? 1 : 0 ;
V_60 = F_76 ( V_8 , V_62 ) ;
if ( V_60 && ( V_149 & V_21 ) ) {
V_1 -> V_32 = F_77 ( V_8 , V_60 ) ;
if ( V_1 -> V_32 ) {
V_1 -> V_32 -> type |=
V_176 ;
goto V_65;
}
}
if ( ! V_1 -> V_32 )
goto V_178;
V_65:
if ( F_6 ( V_8 ) ) {
T_1 V_180 ;
V_62 = ( F_8 ( V_16 ) & V_179 ) ? 1 : 0 ;
V_180 = F_8 ( V_181 ) ;
if ( V_62 == 0 && ( V_180 & V_182 ) )
F_7 ( V_181 , V_180 & ~ V_183 ) ;
if ( V_62 )
V_180 |= V_182 ;
else
V_180 &= ~ V_182 ;
F_7 ( V_181 , V_180 | V_183 ) ;
V_180 = F_8 ( V_184 ) ;
V_180 |= V_185 ;
F_7 ( V_184 , V_180 ) ;
F_7 ( V_15 ,
F_8 ( V_15 ) | V_186 ) ;
} else {
F_7 ( V_18 ,
F_8 ( V_18 ) | V_186 ) ;
}
V_10 -> V_101 . V_112 = F_43 ;
if ( F_78 ( & V_10 -> V_101 ) ) {
F_9 ( L_14 ) ;
V_10 -> V_101 . V_112 = NULL ;
}
V_10 -> V_102 = V_6 ;
F_79 ( V_6 ) ;
F_80 ( V_8 ) ;
return true ;
V_178:
F_9 ( L_15 ) ;
F_53 ( V_6 ) ;
F_81 ( V_3 ) ;
F_54 ( V_1 ) ;
F_54 ( V_148 ) ;
return false ;
}
