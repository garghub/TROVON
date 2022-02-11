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
T_1 V_12 , V_13 ;
if ( F_6 ( V_8 ) ) {
V_12 = V_14 ;
V_13 = V_15 ;
} else {
V_12 = V_16 ;
V_13 = V_17 ;
}
F_7 ( V_13 , F_8 ( V_13 ) | V_18 ) ;
if ( V_1 -> V_19 ) {
F_9 ( L_1 ,
V_1 -> V_20 ,
V_1 -> V_21 ) ;
if ( F_10 ( ( F_8 ( V_22 ) & V_23 ) == 0 , 1000 ) ) {
F_11 ( L_2 ) ;
} else {
F_7 ( V_24 , V_1 -> V_21 ) ;
F_7 ( V_25 , V_1 -> V_20 ) ;
V_1 -> V_19 = false ;
}
}
F_7 ( V_12 , F_8 ( V_12 ) | V_26 ) ;
F_12 ( V_13 ) ;
F_13 ( V_8 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_4 . V_4 . V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
T_1 V_12 , V_13 ;
if ( F_6 ( V_8 ) ) {
V_12 = V_14 ;
V_13 = V_15 ;
} else {
V_12 = V_16 ;
V_13 = V_17 ;
}
F_15 ( V_8 ) ;
F_7 ( V_12 , F_8 ( V_12 ) & ~ V_26 ) ;
if ( V_1 -> V_20 ) {
if ( F_10 ( ( F_8 ( V_22 ) & V_23 ) == 0 , 1000 ) )
F_11 ( L_2 ) ;
F_7 ( V_25 , 0 ) ;
V_1 -> V_19 = true ;
}
F_7 ( V_13 , F_8 ( V_13 ) & ~ V_18 ) ;
F_12 ( V_13 ) ;
}
static void F_16 ( struct V_2 * V_3 , int V_27 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_27 == V_28 )
F_5 ( V_1 ) ;
else
F_14 ( V_1 ) ;
}
static int F_17 ( struct V_5 * V_6 ,
struct V_29 * V_27 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_29 * V_30 = V_1 -> V_30 ;
if ( V_27 -> V_31 > V_30 -> V_31 )
return V_32 ;
if ( V_27 -> V_33 > V_30 -> V_33 )
return V_32 ;
return V_34 ;
}
static void
F_18 ( struct V_29 * V_27 ,
int V_35 )
{
T_1 V_36 , V_37 , V_38 , V_39 ;
V_39 = V_27 -> V_40 - V_27 -> V_41 ;
V_38 = V_27 -> V_42 - V_27 -> V_43 ;
V_37 = ( V_38 - V_39 + 1 ) / 2 ;
V_36 = ( V_27 -> V_31 - V_35 + 1 ) / 2 ;
V_36 += V_36 & 1 ;
V_27 -> V_44 = V_35 ;
V_27 -> V_43 = V_35 + V_36 ;
V_27 -> V_42 = V_27 -> V_43 + V_38 ;
V_27 -> V_41 = V_27 -> V_43 + V_37 ;
V_27 -> V_40 = V_27 -> V_41 + V_39 ;
}
static void
F_19 ( struct V_29 * V_27 ,
int V_45 )
{
T_1 V_36 , V_37 , V_38 , V_39 ;
V_39 = V_27 -> V_46 - V_27 -> V_47 ;
V_38 = V_27 -> V_48 - V_27 -> V_49 ;
V_37 = ( V_38 - V_39 + 1 ) / 2 ;
V_36 = ( V_27 -> V_33 - V_45 + 1 ) / 2 ;
V_27 -> V_50 = V_45 ;
V_27 -> V_49 = V_45 + V_36 ;
V_27 -> V_48 = V_27 -> V_49 + V_38 ;
V_27 -> V_47 = V_27 -> V_49 + V_37 ;
V_27 -> V_46 = V_27 -> V_47 + V_39 ;
}
static inline T_1 F_20 ( T_1 V_51 , T_1 V_52 )
{
#define F_21 12
#define F_22 (1 << ACCURACY)
T_1 V_53 = V_51 * F_22 / V_52 ;
return ( F_22 * V_53 + F_22 / 2 ) / F_22 ;
}
static bool F_23 ( struct V_2 * V_3 ,
struct V_29 * V_27 ,
struct V_29 * V_54 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_55 * V_55 = F_24 ( V_3 -> V_56 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_2 * V_57 ;
T_1 V_20 = 0 , V_21 = 0 , V_36 = 0 ;
int V_58 ;
if ( F_25 ( V_8 ) -> V_59 < 4 && V_55 -> V_58 == 0 ) {
F_11 ( L_3 ) ;
return false ;
}
F_26 (tmp_encoder, &dev->mode_config.encoder_list, head) {
if ( V_57 != V_3 && V_57 -> V_56 == V_3 -> V_56 ) {
F_11 ( L_4
L_5 ) ;
return false ;
}
}
F_27 ( V_1 -> V_30 , V_54 ) ;
if ( F_6 ( V_8 ) ) {
F_28 ( V_8 , V_1 -> V_60 ,
V_27 , V_54 ) ;
return true ;
}
if ( V_54 -> V_31 == V_27 -> V_31 &&
V_54 -> V_33 == V_27 -> V_33 )
goto V_61;
if ( F_25 ( V_8 ) -> V_59 >= 4 )
V_20 |= ( ( V_55 -> V_58 << V_62 ) |
V_63 ) ;
F_29 (pipe)
F_7 ( F_30 ( V_58 ) , 0 ) ;
switch ( V_1 -> V_60 ) {
case V_64 :
F_18 ( V_54 , V_27 -> V_31 ) ;
F_19 ( V_54 , V_27 -> V_33 ) ;
V_36 = V_65 ;
break;
case V_66 :
if ( F_25 ( V_8 ) -> V_59 >= 4 ) {
T_1 V_67 = V_54 -> V_31 * V_27 -> V_33 ;
T_1 V_68 = V_27 -> V_31 * V_54 -> V_33 ;
if ( V_67 > V_68 )
V_20 |= V_69 | V_70 ;
else if ( V_67 < V_68 )
V_20 |= V_69 | V_71 ;
else if ( V_54 -> V_31 != V_27 -> V_31 )
V_20 |= V_69 | V_72 ;
} else {
T_1 V_67 = V_54 -> V_31 * V_27 -> V_33 ;
T_1 V_68 = V_27 -> V_31 * V_54 -> V_33 ;
if ( V_67 > V_68 ) {
F_18 ( V_54 , V_68 / V_27 -> V_33 ) ;
V_36 = V_65 ;
if ( V_27 -> V_33 != V_54 -> V_33 ) {
T_1 V_73 = F_20 ( V_27 -> V_33 , V_54 -> V_33 ) ;
V_21 |= ( V_73 << V_74 |
V_73 << V_75 ) ;
V_20 |= ( V_69 |
V_76 |
V_77 ) ;
}
} else if ( V_67 < V_68 ) {
F_19 ( V_54 , V_67 / V_27 -> V_31 ) ;
V_36 = V_65 ;
if ( V_27 -> V_31 != V_54 -> V_31 ) {
T_1 V_73 = F_20 ( V_27 -> V_31 , V_54 -> V_31 ) ;
V_21 |= ( V_73 << V_74 |
V_73 << V_75 ) ;
V_20 |= ( V_69 |
V_76 |
V_77 ) ;
}
} else
V_20 |= ( V_69 |
V_78 | V_79 |
V_76 |
V_77 ) ;
}
break;
case V_80 :
if ( V_27 -> V_33 != V_54 -> V_33 ||
V_27 -> V_31 != V_54 -> V_31 ) {
V_20 |= V_69 ;
if ( F_25 ( V_8 ) -> V_59 >= 4 )
V_20 |= V_72 ;
else
V_20 |= ( V_78 |
V_76 |
V_79 |
V_77 ) ;
}
break;
default:
break;
}
V_61:
if ( ( V_20 & V_69 ) == 0 ) {
V_20 = 0 ;
V_21 = 0 ;
}
if ( F_25 ( V_8 ) -> V_59 < 4 && V_10 -> V_81 )
V_20 |= V_82 ;
if ( V_20 != V_1 -> V_20 ||
V_21 != V_1 -> V_21 ) {
V_1 -> V_20 = V_20 ;
V_1 -> V_21 = V_21 ;
V_1 -> V_19 = true ;
}
V_10 -> V_83 = V_36 ;
return true ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( F_6 ( V_8 ) ) {
F_7 ( V_14 ,
F_8 ( V_14 ) | V_84 ) ;
} else if ( V_1 -> V_19 ) {
F_7 ( V_16 ,
( F_8 ( V_16 ) | V_84 )
& ~ V_26 ) ;
} else {
F_7 ( V_16 ,
F_8 ( V_16 ) | V_84 ) ;
}
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( F_6 ( V_8 ) ) {
T_1 V_85 = F_8 ( V_14 ) ;
if ( ( V_85 & V_84 ) == V_84 )
F_7 ( V_14 , V_85 & 0x3 ) ;
} else {
T_1 V_85 = F_8 ( V_16 ) ;
if ( ( V_85 & V_84 ) == V_84 )
F_7 ( V_16 , V_85 & 0x3 ) ;
}
F_5 ( V_1 ) ;
}
static void F_33 ( struct V_2 * V_3 ,
struct V_29 * V_27 ,
struct V_29 * V_54 )
{
}
static enum V_86
F_34 ( struct V_5 * V_6 , bool V_87 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
enum V_86 V_88 ;
V_88 = F_35 ( V_8 ) ;
if ( V_88 != V_89 )
return V_88 ;
return V_90 ;
}
static int F_36 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_29 * V_27 ;
if ( V_1 -> V_91 )
return F_37 ( V_6 , V_1 -> V_91 ) ;
V_27 = F_38 ( V_8 , V_1 -> V_30 ) ;
if ( V_27 == NULL )
return 0 ;
F_39 ( V_6 , V_27 ) ;
return 1 ;
}
static int F_40 ( const struct V_92 * V_93 )
{
F_9 ( L_6 , V_93 -> V_94 ) ;
return 1 ;
}
static int F_41 ( struct V_95 * V_96 , unsigned long V_85 ,
void * V_97 )
{
struct V_9 * V_10 =
F_2 ( V_96 , struct V_9 , V_98 ) ;
struct V_7 * V_8 = V_10 -> V_8 ;
struct V_5 * V_6 = V_10 -> V_99 ;
if ( V_8 -> V_100 != V_101 )
return V_102 ;
if ( V_6 )
V_6 -> V_88 = V_6 -> V_103 -> V_104 ( V_6 ,
false ) ;
if ( F_42 ( V_105 ) )
return V_102 ;
if ( ! F_43 () ) {
V_10 -> V_106 = 1 ;
return V_102 ;
}
if ( ! V_10 -> V_106 )
return V_102 ;
V_10 -> V_106 = 0 ;
F_44 ( & V_8 -> V_107 . V_108 ) ;
F_45 ( V_8 ) ;
F_46 ( & V_8 -> V_107 . V_108 ) ;
return V_102 ;
}
static void F_47 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
if ( V_10 -> V_98 . V_109 )
F_48 ( & V_10 -> V_98 ) ;
F_49 ( V_6 ) ;
F_50 ( V_6 ) ;
F_51 ( V_6 ) ;
}
static int F_52 ( struct V_5 * V_6 ,
struct V_110 * V_111 ,
T_2 V_112 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_111 == V_8 -> V_107 . V_113 ) {
struct V_114 * V_56 = V_1 -> V_4 . V_4 . V_56 ;
if ( V_112 == V_115 ) {
F_9 ( L_7 ) ;
return - V_116 ;
}
if ( V_1 -> V_60 == V_112 ) {
return 0 ;
}
V_1 -> V_60 = V_112 ;
if ( V_56 && V_56 -> V_117 ) {
F_53 ( V_56 , & V_56 -> V_27 ,
V_56 -> V_118 , V_56 -> V_119 , V_56 -> V_120 ) ;
}
}
return 0 ;
}
static int T_3 F_54 ( const struct V_92 * V_93 )
{
F_9 ( L_8 , V_93 -> V_94 ) ;
return 1 ;
}
static void F_55 ( struct V_7 * V_8 ,
struct V_29 * V_30 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_29 * V_121 ;
int V_122 ;
V_122 = V_30 -> clock ;
F_26 (scan, &connector->probed_modes, head) {
if ( V_121 -> V_31 == V_30 -> V_31 &&
V_121 -> V_123 == V_30 -> V_123 &&
V_121 -> V_124 == V_30 -> V_124 &&
V_121 -> V_125 == V_30 -> V_125 &&
V_121 -> V_33 == V_30 -> V_33 &&
V_121 -> V_126 == V_30 -> V_126 &&
V_121 -> V_127 == V_30 -> V_127 &&
V_121 -> V_128 == V_30 -> V_128 ) {
if ( V_121 -> clock < V_122 ) {
V_122 = V_121 -> clock ;
}
}
}
if ( V_122 < V_30 -> clock && V_129 ) {
V_10 -> V_130 = 1 ;
V_10 -> V_131 = V_122 ;
F_9 ( L_9
L_10 ,
V_30 -> clock , V_122 ) ;
}
}
static bool F_56 ( struct V_7 * V_8 ,
T_4 * V_132 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
int V_133 ;
if ( ! V_10 -> V_134 )
return true ;
for ( V_133 = 0 ; V_133 < V_10 -> V_134 ; V_133 ++ ) {
struct V_135 * V_136 = V_10 -> V_137 + V_133 ;
if ( V_136 -> V_138 != V_139 &&
V_136 -> V_138 != V_140 )
continue;
if ( V_136 -> V_132 )
* V_132 = V_136 -> V_132 ;
if ( V_136 -> V_141 )
return true ;
if ( V_10 -> V_142 . V_143 )
return true ;
}
return false ;
}
bool F_57 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_1 ;
struct V_144 * V_144 ;
struct V_145 * V_145 ;
struct V_5 * V_6 ;
struct V_2 * V_3 ;
struct V_29 * V_121 ;
struct V_114 * V_56 ;
T_1 V_146 ;
int V_58 ;
T_4 V_147 ;
if ( F_42 ( V_148 ) )
return false ;
V_147 = V_149 ;
if ( ! F_56 ( V_8 , & V_147 ) ) {
F_9 ( L_11 ) ;
return false ;
}
if ( F_6 ( V_8 ) ) {
if ( ( F_8 ( V_15 ) & V_150 ) == 0 )
return false ;
if ( V_10 -> V_151 . V_152 ) {
F_9 ( L_12 ) ;
return false ;
}
}
V_1 = F_58 ( sizeof( struct V_1 ) , V_153 ) ;
if ( ! V_1 ) {
return false ;
}
V_145 = F_58 ( sizeof( struct V_145 ) , V_153 ) ;
if ( ! V_145 ) {
F_51 ( V_1 ) ;
return false ;
}
if ( ! F_6 ( V_8 ) ) {
V_1 -> V_20 = F_8 ( V_25 ) ;
}
V_144 = & V_1 -> V_4 ;
V_3 = & V_144 -> V_4 ;
V_6 = & V_145 -> V_4 ;
F_59 ( V_8 , & V_145 -> V_4 , & V_154 ,
V_155 ) ;
F_60 ( V_8 , & V_144 -> V_4 , & V_156 ,
V_157 ) ;
F_61 ( V_145 , V_144 ) ;
V_144 -> type = V_158 ;
V_144 -> V_159 = ( 1 << V_160 ) ;
V_144 -> V_161 = ( 1 << 1 ) ;
if ( F_25 ( V_8 ) -> V_59 >= 5 )
V_144 -> V_161 |= ( 1 << 0 ) ;
F_62 ( V_3 , & V_162 ) ;
F_63 ( V_6 , & V_163 ) ;
V_6 -> V_164 . V_165 = V_166 ;
V_6 -> V_167 = false ;
V_6 -> V_168 = false ;
F_64 ( V_8 ) ;
F_65 ( & V_145 -> V_4 ,
V_8 -> V_107 . V_113 ,
V_66 ) ;
V_1 -> V_60 = V_66 ;
V_1 -> V_91 = F_66 ( V_6 ,
& V_10 -> V_169 [ V_147 ] . V_170 ) ;
if ( V_1 -> V_91 ) {
if ( F_37 ( V_6 ,
V_1 -> V_91 ) ) {
F_67 ( V_6 ,
V_1 -> V_91 ) ;
} else {
F_51 ( V_1 -> V_91 ) ;
V_1 -> V_91 = NULL ;
}
}
if ( ! V_1 -> V_91 ) {
V_6 -> V_164 . V_171 = 0 ;
V_6 -> V_164 . V_172 = 200 ;
V_6 -> V_164 . V_173 = 0 ;
V_6 -> V_164 . V_174 = 200 ;
}
F_26 (scan, &connector->probed_modes, head) {
if ( V_121 -> type & V_175 ) {
V_1 -> V_30 =
F_38 ( V_8 , V_121 ) ;
F_55 ( V_8 ,
V_1 -> V_30 ,
V_6 ) ;
goto V_61;
}
}
if ( V_10 -> V_176 ) {
V_1 -> V_30 =
F_38 ( V_8 , V_10 -> V_176 ) ;
if ( V_1 -> V_30 ) {
V_1 -> V_30 -> type |=
V_175 ;
goto V_61;
}
}
if ( F_6 ( V_8 ) )
goto V_177;
V_146 = F_8 ( V_17 ) ;
V_58 = ( V_146 & V_178 ) ? 1 : 0 ;
V_56 = F_68 ( V_8 , V_58 ) ;
if ( V_56 && ( V_146 & V_18 ) ) {
V_1 -> V_30 = F_69 ( V_8 , V_56 ) ;
if ( V_1 -> V_30 ) {
V_1 -> V_30 -> type |=
V_175 ;
goto V_61;
}
}
if ( ! V_1 -> V_30 )
goto V_177;
V_61:
if ( F_6 ( V_8 ) ) {
T_1 V_179 ;
V_58 = ( F_8 ( V_15 ) & V_178 ) ? 1 : 0 ;
V_179 = F_8 ( V_180 ) ;
if ( V_58 == 0 && ( V_179 & V_181 ) )
F_7 ( V_180 , V_179 & ~ V_182 ) ;
if ( V_58 )
V_179 |= V_181 ;
else
V_179 &= ~ V_181 ;
F_7 ( V_180 , V_179 | V_182 ) ;
V_179 = F_8 ( V_183 ) ;
V_179 |= V_184 ;
F_7 ( V_183 , V_179 ) ;
}
V_10 -> V_98 . V_109 = F_41 ;
if ( F_70 ( & V_10 -> V_98 ) ) {
F_9 ( L_13 ) ;
V_10 -> V_98 . V_109 = NULL ;
}
V_10 -> V_99 = V_6 ;
F_71 ( V_6 ) ;
return true ;
V_177:
F_9 ( L_14 ) ;
F_50 ( V_6 ) ;
F_72 ( V_3 ) ;
F_51 ( V_1 ) ;
F_51 ( V_145 ) ;
return false ;
}
