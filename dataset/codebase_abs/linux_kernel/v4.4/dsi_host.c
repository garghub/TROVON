static int F_1 ( const void T_1 * V_1 , T_2 * V_2 , T_2 * V_3 )
{
T_2 V_4 ;
T_2 V_5 ;
if ( ! V_2 || ! V_3 )
return - V_6 ;
V_5 = F_2 ( V_1 + V_7 ) ;
if ( V_5 == 0 ) {
V_4 = F_2 ( V_1 + V_8 ) ;
V_4 = F_3 ( V_4 , V_9 ) ;
if ( V_4 <= V_10 ) {
* V_2 = V_4 ;
* V_3 = 0 ;
return 0 ;
} else {
return - V_6 ;
}
} else {
V_4 = F_2 ( V_1 + V_11 + V_8 ) ;
V_4 = F_3 ( V_4 , V_9 ) ;
if ( V_4 == V_12 ) {
* V_2 = V_4 ;
* V_3 = V_5 ;
return 0 ;
} else {
return - V_6 ;
}
}
}
static T_2 F_4 ( const enum V_13 V_14 )
{
switch ( V_14 ) {
case V_15 : return 16 ;
case V_16 : return 18 ;
case V_17 :
case V_18 :
default: return 24 ;
}
}
static inline T_2 F_5 ( struct V_19 * V_20 , T_2 V_21 )
{
return F_2 ( V_20 -> V_22 + V_21 ) ;
}
static inline void F_6 ( struct V_19 * V_20 , T_2 V_21 , T_2 V_23 )
{
F_7 ( V_23 , V_20 -> V_22 + V_21 ) ;
}
static const struct V_24 * F_8 (
struct V_19 * V_20 )
{
const struct V_24 * V_25 = NULL ;
struct V_26 * V_27 ;
int V_28 ;
T_2 V_2 = 0 , V_3 = 0 ;
V_27 = F_9 ( & V_20 -> V_29 -> V_30 , L_1 ) ;
if ( F_10 ( V_27 ) ) {
F_11 ( L_2 , V_31 ) ;
goto exit;
}
V_28 = F_12 ( V_27 ) ;
if ( V_28 ) {
F_11 ( L_3 , V_31 ) ;
goto V_32;
}
V_28 = F_13 ( V_20 -> V_33 ) ;
if ( V_28 ) {
F_11 ( L_4 , V_31 ) ;
goto V_34;
}
V_28 = F_1 ( V_20 -> V_22 , & V_2 , & V_3 ) ;
if ( V_28 ) {
F_11 ( L_5 , V_31 ) ;
goto V_35;
}
V_25 = F_14 ( V_2 , V_3 ) ;
F_15 ( L_6 , V_31 , V_2 , V_3 ) ;
V_35:
F_16 ( V_20 -> V_33 ) ;
V_34:
F_17 ( V_27 ) ;
V_32:
F_18 ( V_27 ) ;
exit:
return V_25 ;
}
static inline struct V_19 * F_19 ( struct V_36 * V_37 )
{
return F_20 ( V_37 , struct V_19 , V_1 ) ;
}
static void F_21 ( struct V_19 * V_20 )
{
struct V_38 * V_39 = V_20 -> V_40 ;
const struct V_41 * V_42 = V_20 -> V_25 -> V_43 -> V_44 . V_42 ;
int V_45 = V_20 -> V_25 -> V_43 -> V_44 . V_45 ;
int V_46 ;
F_15 ( L_7 ) ;
for ( V_46 = V_45 - 1 ; V_46 >= 0 ; V_46 -- )
if ( V_42 [ V_46 ] . V_47 >= 0 )
F_22 ( V_39 [ V_46 ] . V_48 ,
V_42 [ V_46 ] . V_47 ) ;
F_23 ( V_45 , V_39 ) ;
}
static int F_24 ( struct V_19 * V_20 )
{
struct V_38 * V_39 = V_20 -> V_40 ;
const struct V_41 * V_42 = V_20 -> V_25 -> V_43 -> V_44 . V_42 ;
int V_45 = V_20 -> V_25 -> V_43 -> V_44 . V_45 ;
int V_28 , V_46 ;
F_15 ( L_7 ) ;
for ( V_46 = 0 ; V_46 < V_45 ; V_46 ++ ) {
if ( V_42 [ V_46 ] . V_49 >= 0 ) {
V_28 = F_22 ( V_39 [ V_46 ] . V_48 ,
V_42 [ V_46 ] . V_49 ) ;
if ( V_28 < 0 ) {
F_11 ( L_8 ,
V_46 , V_28 ) ;
goto V_50;
}
}
}
V_28 = F_25 ( V_45 , V_39 ) ;
if ( V_28 < 0 ) {
F_11 ( L_9 , V_28 ) ;
goto V_50;
}
return 0 ;
V_50:
for ( V_46 -- ; V_46 >= 0 ; V_46 -- )
F_22 ( V_39 [ V_46 ] . V_48 , V_42 [ V_46 ] . V_47 ) ;
return V_28 ;
}
static int F_26 ( struct V_19 * V_20 )
{
struct V_38 * V_39 = V_20 -> V_40 ;
const struct V_41 * V_42 = V_20 -> V_25 -> V_43 -> V_44 . V_42 ;
int V_45 = V_20 -> V_25 -> V_43 -> V_44 . V_45 ;
int V_46 , V_28 ;
for ( V_46 = 0 ; V_46 < V_45 ; V_46 ++ )
V_39 [ V_46 ] . V_51 = V_42 [ V_46 ] . V_52 ;
V_28 = F_27 ( & V_20 -> V_29 -> V_30 , V_45 , V_39 ) ;
if ( V_28 < 0 ) {
F_11 ( L_10 ,
V_31 , V_28 ) ;
return V_28 ;
}
for ( V_46 = 0 ; V_46 < V_45 ; V_46 ++ ) {
if ( F_28 ( V_39 [ V_46 ] . V_48 ) ) {
V_28 = F_29 ( V_39 [ V_46 ] . V_48 ,
V_42 [ V_46 ] . V_53 , V_42 [ V_46 ] . V_54 ) ;
if ( V_28 < 0 ) {
F_11 ( L_11 ,
V_46 , V_28 ) ;
return V_28 ;
}
}
}
return 0 ;
}
static int F_30 ( struct V_19 * V_20 )
{
struct V_55 * V_30 = & V_20 -> V_29 -> V_30 ;
int V_28 = 0 ;
V_20 -> V_56 = F_31 ( V_30 , L_12 ) ;
if ( F_10 ( V_20 -> V_56 ) ) {
V_28 = F_32 ( V_20 -> V_56 ) ;
F_11 ( L_13 ,
V_31 , V_28 ) ;
goto exit;
}
V_20 -> V_33 = F_31 ( V_30 , L_14 ) ;
if ( F_10 ( V_20 -> V_33 ) ) {
V_28 = F_32 ( V_20 -> V_33 ) ;
F_11 ( L_15 ,
V_31 , V_28 ) ;
goto exit;
}
V_20 -> V_57 = F_31 ( V_30 , L_16 ) ;
if ( F_10 ( V_20 -> V_57 ) ) {
V_28 = F_32 ( V_20 -> V_57 ) ;
F_11 ( L_17 ,
V_31 , V_28 ) ;
goto exit;
}
V_20 -> V_58 = F_31 ( V_30 , L_18 ) ;
if ( F_10 ( V_20 -> V_58 ) ) {
V_28 = F_32 ( V_20 -> V_58 ) ;
F_11 ( L_19 ,
V_31 , V_28 ) ;
goto exit;
}
V_20 -> V_59 = F_31 ( V_30 , L_20 ) ;
if ( F_10 ( V_20 -> V_59 ) ) {
V_28 = F_32 ( V_20 -> V_59 ) ;
F_11 ( L_21 ,
V_31 , V_28 ) ;
V_20 -> V_59 = NULL ;
goto exit;
}
V_20 -> V_60 = F_31 ( V_30 , L_22 ) ;
if ( F_10 ( V_20 -> V_60 ) ) {
V_28 = F_32 ( V_20 -> V_60 ) ;
F_11 ( L_23 ,
V_31 , V_28 ) ;
V_20 -> V_60 = NULL ;
goto exit;
}
V_20 -> V_61 = F_31 ( V_30 , L_24 ) ;
if ( F_10 ( V_20 -> V_61 ) ) {
V_28 = F_32 ( V_20 -> V_61 ) ;
F_11 ( L_25 ,
V_31 , V_28 ) ;
V_20 -> V_61 = NULL ;
goto exit;
}
V_20 -> V_62 = F_31 ( V_30 , L_26 ) ;
if ( F_10 ( V_20 -> V_62 ) ) {
V_28 = F_32 ( V_20 -> V_62 ) ;
F_11 ( L_27 , V_31 , V_28 ) ;
V_20 -> V_62 = NULL ;
goto exit;
}
V_20 -> V_63 = F_31 ( V_30 , L_28 ) ;
if ( F_10 ( V_20 -> V_63 ) ) {
V_28 = F_32 ( V_20 -> V_63 ) ;
F_11 ( L_29 , V_31 , V_28 ) ;
V_20 -> V_63 = NULL ;
goto exit;
}
exit:
return V_28 ;
}
static int F_33 ( struct V_19 * V_20 )
{
int V_28 ;
F_15 ( L_30 , V_20 -> V_64 ) ;
V_28 = F_13 ( V_20 -> V_56 ) ;
if ( V_28 ) {
F_11 ( L_31 ,
V_31 , V_28 ) ;
goto V_65;
}
V_28 = F_13 ( V_20 -> V_33 ) ;
if ( V_28 ) {
F_11 ( L_32 , V_31 , V_28 ) ;
goto V_66;
}
V_28 = F_13 ( V_20 -> V_57 ) ;
if ( V_28 ) {
F_11 ( L_32 , V_31 , V_28 ) ;
goto V_67;
}
V_28 = F_13 ( V_20 -> V_58 ) ;
if ( V_28 ) {
F_11 ( L_33 ,
V_31 , V_28 ) ;
goto V_68;
}
return 0 ;
V_68:
F_16 ( V_20 -> V_57 ) ;
V_67:
F_16 ( V_20 -> V_33 ) ;
V_66:
F_16 ( V_20 -> V_56 ) ;
V_65:
return V_28 ;
}
static void F_34 ( struct V_19 * V_20 )
{
F_15 ( L_7 ) ;
F_16 ( V_20 -> V_58 ) ;
F_16 ( V_20 -> V_57 ) ;
F_16 ( V_20 -> V_33 ) ;
F_16 ( V_20 -> V_56 ) ;
}
static int F_35 ( struct V_19 * V_20 )
{
int V_28 ;
F_15 ( L_34 ,
V_20 -> V_69 -> clock , V_20 -> V_70 ) ;
V_28 = F_36 ( V_20 -> V_59 , V_20 -> V_70 ) ;
if ( V_28 ) {
F_11 ( L_35 , V_31 , V_28 ) ;
goto error;
}
V_28 = F_36 ( V_20 -> V_60 , V_20 -> V_69 -> clock * 1000 ) ;
if ( V_28 ) {
F_11 ( L_36 , V_31 , V_28 ) ;
goto error;
}
V_28 = F_13 ( V_20 -> V_61 ) ;
if ( V_28 ) {
F_11 ( L_37 , V_31 ) ;
goto error;
}
V_28 = F_13 ( V_20 -> V_59 ) ;
if ( V_28 ) {
F_11 ( L_38 , V_31 ) ;
goto V_71;
}
V_28 = F_13 ( V_20 -> V_60 ) ;
if ( V_28 ) {
F_11 ( L_39 , V_31 ) ;
goto V_72;
}
return 0 ;
V_72:
F_16 ( V_20 -> V_59 ) ;
V_71:
F_16 ( V_20 -> V_61 ) ;
error:
return V_28 ;
}
static void F_37 ( struct V_19 * V_20 )
{
F_16 ( V_20 -> V_61 ) ;
F_16 ( V_20 -> V_60 ) ;
F_16 ( V_20 -> V_59 ) ;
}
static int F_38 ( struct V_19 * V_20 , bool V_73 )
{
int V_28 = 0 ;
F_39 ( & V_20 -> V_74 ) ;
if ( V_73 ) {
V_28 = F_33 ( V_20 ) ;
if ( V_28 ) {
F_11 ( L_40 ,
V_31 , V_28 ) ;
goto V_75;
}
V_28 = F_35 ( V_20 ) ;
if ( V_28 ) {
F_11 ( L_41 ,
V_31 , V_28 ) ;
F_34 ( V_20 ) ;
goto V_75;
}
} else {
F_37 ( V_20 ) ;
F_34 ( V_20 ) ;
}
V_75:
F_40 ( & V_20 -> V_74 ) ;
return V_28 ;
}
static int F_41 ( struct V_19 * V_20 )
{
struct V_76 * V_69 = V_20 -> V_69 ;
T_3 V_77 = V_20 -> V_77 ;
T_2 V_78 = F_4 ( V_20 -> V_79 ) ;
T_2 V_80 ;
if ( ! V_69 ) {
F_11 ( L_42 , V_31 ) ;
return - V_6 ;
}
V_80 = V_69 -> clock * 1000 ;
if ( V_77 > 0 ) {
V_20 -> V_70 = ( V_80 * V_78 ) / ( 8 * V_77 ) ;
} else {
F_11 ( L_43 , V_31 ) ;
V_20 -> V_70 = ( V_80 * V_78 ) / 8 ;
}
F_15 ( L_44 , V_80 , V_20 -> V_70 ) ;
return 0 ;
}
static void F_42 ( struct V_19 * V_20 )
{
F_15 ( L_7 ) ;
F_6 ( V_20 , V_81 , V_82 ) ;
F_43 () ;
F_44 ( 1000 ) ;
F_6 ( V_20 , V_81 , 0 ) ;
F_44 ( 100 ) ;
}
static void F_45 ( struct V_19 * V_20 , T_2 V_83 , int V_73 )
{
T_2 V_84 ;
unsigned long V_85 ;
F_46 ( & V_20 -> V_86 , V_85 ) ;
V_84 = F_5 ( V_20 , V_87 ) ;
if ( V_73 )
V_84 |= V_83 ;
else
V_84 &= ~ V_83 ;
F_15 ( L_45 , V_84 , V_73 ) ;
F_6 ( V_20 , V_87 , V_84 ) ;
F_47 ( & V_20 -> V_86 , V_85 ) ;
}
static inline enum V_88 F_48 ( const T_2 V_89 )
{
if ( V_89 & V_90 )
return V_91 ;
else if ( V_89 & V_92 )
return V_93 ;
return V_94 ;
}
static inline enum V_95 F_49 (
const enum V_13 V_96 )
{
switch ( V_96 ) {
case V_18 : return V_97 ;
case V_17 : return V_98 ;
case V_16 : return V_99 ;
case V_15 : return V_100 ;
default: return V_97 ;
}
}
static inline enum V_101 F_50 (
const enum V_13 V_96 )
{
switch ( V_96 ) {
case V_18 : return V_102 ;
case V_16 :
case V_17 : return V_99 ;
case V_15 : return V_103 ;
default: return V_102 ;
}
}
static void F_51 ( struct V_19 * V_20 , bool V_73 ,
T_2 V_104 , T_2 V_105 )
{
T_2 V_85 = V_20 -> V_89 ;
enum V_13 V_96 = V_20 -> V_79 ;
const struct V_24 * V_25 = V_20 -> V_25 ;
T_2 V_23 = 0 ;
if ( ! V_73 ) {
F_6 ( V_20 , V_106 , 0 ) ;
return;
}
if ( V_85 & V_107 ) {
if ( V_85 & V_108 )
V_23 |= V_109 ;
if ( V_85 & V_110 )
V_23 |= V_111 ;
if ( V_85 & V_112 )
V_23 |= V_113 ;
if ( V_85 & V_114 )
V_23 |= V_115 ;
V_23 |= V_116 |
V_117 ;
V_23 |= F_52 ( F_48 ( V_85 ) ) ;
V_23 |= F_53 ( F_49 ( V_96 ) ) ;
V_23 |= F_54 ( V_20 -> V_118 ) ;
F_6 ( V_20 , V_119 , V_23 ) ;
V_23 = F_55 ( V_120 ) ;
F_6 ( V_20 , V_121 , 0 ) ;
} else {
V_23 = F_56 ( V_120 ) ;
V_23 |= F_57 ( F_50 ( V_96 ) ) ;
F_6 ( V_20 , V_122 , V_23 ) ;
V_23 = F_58 ( V_123 ) |
F_59 (
V_124 ) ;
V_23 |= V_125 ;
F_6 ( V_20 , V_126 , V_23 ) ;
}
F_6 ( V_20 , V_127 ,
V_128 |
V_129 ) ;
V_23 = 0 ;
V_23 |= V_130 ;
V_23 |= F_60 ( V_131 ) ;
V_23 |= F_61 ( V_132 ) ;
V_23 |= F_62 ( V_20 -> V_118 ) ;
if ( ( V_25 -> V_2 == V_12 ) &&
( V_25 -> V_3 >= V_133 ) )
V_23 |= V_134 ;
F_6 ( V_20 , V_135 , V_23 ) ;
V_23 = F_63 ( V_105 ) |
F_64 ( V_104 ) ;
F_6 ( V_20 , V_136 , V_23 ) ;
V_23 = 0 ;
if ( ! ( V_85 & V_137 ) )
V_23 |= V_138 ;
F_6 ( V_20 , V_139 , V_23 ) ;
F_6 ( V_20 , V_140 , 0x13ff3fe0 ) ;
F_45 ( V_20 , V_141 , 1 ) ;
F_6 ( V_20 , V_142 , V_143 ) ;
V_23 = V_144 ;
F_15 ( L_46 , V_20 -> V_77 ) ;
if ( V_20 -> V_77 == 2 ) {
V_23 |= V_145 | V_146 ;
F_6 ( V_20 , V_147 ,
F_65 ( V_148 ) ) ;
} else {
V_23 |= V_149 | V_145 | V_146 |
V_150 ;
F_6 ( V_20 , V_147 ,
F_65 ( V_151 ) ) ;
}
if ( ! ( V_85 & V_152 ) )
F_6 ( V_20 , V_153 ,
V_154 ) ;
V_23 |= V_155 ;
F_6 ( V_20 , V_106 , V_23 ) ;
}
static void F_66 ( struct V_19 * V_20 )
{
struct V_76 * V_69 = V_20 -> V_69 ;
T_2 V_156 = 0 , V_157 = 0 ;
T_2 V_158 = V_69 -> V_159 ;
T_2 V_160 = V_69 -> V_161 ;
T_2 V_162 = V_69 -> V_163 - V_69 -> V_164 ;
T_2 V_165 = V_69 -> V_166 - V_69 -> V_167 ;
T_2 V_168 = V_158 - V_69 -> V_164 ;
T_2 V_169 = V_168 + V_69 -> V_170 ;
T_2 va_start = V_160 - V_69 -> V_167 ;
T_2 va_end = va_start + V_69 -> V_171 ;
T_2 V_172 ;
F_15 ( L_7 ) ;
if ( V_20 -> V_89 & V_107 ) {
F_6 ( V_20 , V_173 ,
F_67 ( V_168 ) |
F_68 ( V_169 ) ) ;
F_6 ( V_20 , V_174 ,
F_69 ( va_start ) |
F_70 ( va_end ) ) ;
F_6 ( V_20 , V_175 ,
F_71 ( V_158 - 1 ) |
F_72 ( V_160 - 1 ) ) ;
F_6 ( V_20 , V_176 ,
F_73 ( V_156 ) |
F_74 ( V_162 ) ) ;
F_6 ( V_20 , V_177 , 0 ) ;
F_6 ( V_20 , V_178 ,
F_75 ( V_157 ) |
F_76 ( V_165 ) ) ;
} else {
V_172 = V_69 -> V_170 * F_4 ( V_20 -> V_79 ) / 8 + 1 ;
F_6 ( V_20 , V_179 ,
F_77 ( V_172 ) |
F_78 (
V_20 -> V_118 ) |
F_79 (
V_180 ) ) ;
F_6 ( V_20 , V_181 ,
F_80 ( V_69 -> V_170 ) |
F_81 ( V_69 -> V_171 ) ) ;
}
}
static void F_82 ( struct V_19 * V_20 )
{
F_6 ( V_20 , V_142 , V_143 ) ;
F_43 () ;
F_6 ( V_20 , V_182 , 1 ) ;
F_43 () ;
F_6 ( V_20 , V_182 , 0 ) ;
}
static void F_83 ( struct V_19 * V_20 ,
bool V_183 , bool V_73 )
{
T_2 V_184 ;
V_184 = F_5 ( V_20 , V_106 ) ;
if ( ! V_73 ) {
V_184 &= ~ ( V_155 | V_185 |
V_186 ) ;
F_45 ( V_20 , V_187 |
V_188 , 0 ) ;
} else {
if ( V_183 ) {
V_184 |= V_185 ;
} else {
V_184 |= V_186 ;
F_45 ( V_20 , V_187 , 1 ) ;
}
V_184 |= V_155 ;
}
F_6 ( V_20 , V_106 , V_184 ) ;
}
static void F_84 ( int V_69 , struct V_19 * V_20 )
{
T_2 V_23 ;
V_23 = F_5 ( V_20 , V_127 ) ;
if ( V_69 == 0 )
V_23 &= ~ V_129 ;
else
V_23 |= V_129 ;
F_6 ( V_20 , V_127 , V_23 ) ;
}
static void F_85 ( struct V_19 * V_20 )
{
F_45 ( V_20 , V_188 , 1 ) ;
F_86 ( & V_20 -> V_189 ) ;
F_87 ( & V_20 -> V_189 ,
F_88 ( 70 ) ) ;
F_45 ( V_20 , V_188 , 0 ) ;
}
static void F_89 ( struct V_19 * V_20 )
{
if ( ! ( V_20 -> V_89 & V_107 ) )
return;
if ( V_20 -> V_190 ) {
F_85 ( V_20 ) ;
F_90 ( 2000 , 4000 ) ;
}
}
static int F_91 ( struct V_19 * V_20 , int V_191 )
{
struct V_192 * V_30 = V_20 -> V_30 ;
int V_28 ;
T_2 V_193 ;
F_39 ( & V_30 -> V_194 ) ;
V_20 -> V_195 = F_92 ( V_30 , V_191 , V_196 ) ;
if ( F_10 ( V_20 -> V_195 ) ) {
V_28 = F_32 ( V_20 -> V_195 ) ;
F_11 ( L_47 , V_31 , V_28 ) ;
V_20 -> V_195 = NULL ;
F_40 ( & V_30 -> V_194 ) ;
return V_28 ;
}
V_28 = F_93 ( V_20 -> V_195 , 0 , & V_193 ) ;
if ( V_28 ) {
F_11 ( L_48 , V_31 , V_28 ) ;
return V_28 ;
}
F_40 ( & V_30 -> V_194 ) ;
if ( V_193 & 0x07 ) {
F_11 ( L_49 , V_31 ) ;
return - V_6 ;
}
return 0 ;
}
static void F_94 ( struct V_19 * V_20 )
{
struct V_192 * V_30 = V_20 -> V_30 ;
if ( V_20 -> V_195 ) {
F_95 ( V_20 -> V_195 , 0 ) ;
F_39 ( & V_30 -> V_194 ) ;
F_96 ( V_20 -> V_195 ) ;
V_20 -> V_195 = NULL ;
F_40 ( & V_30 -> V_194 ) ;
}
}
static int F_97 ( struct V_197 * V_198 ,
const struct V_199 * V_200 )
{
struct V_201 V_202 ;
int V_203 ;
int V_28 ;
T_3 * V_23 ;
V_28 = F_98 ( & V_202 , V_200 ) ;
if ( V_28 ) {
F_11 ( L_50 , V_31 , V_28 ) ;
return V_28 ;
}
V_203 = ( V_202 . V_191 + 3 ) & ( ~ 0x3 ) ;
if ( V_203 > V_198 -> V_191 ) {
F_11 ( L_51 , V_31 ) ;
return - V_6 ;
}
V_23 = F_99 ( V_198 ) ;
if ( F_10 ( V_23 ) ) {
V_28 = F_32 ( V_23 ) ;
F_11 ( L_52 , V_31 , V_28 ) ;
return V_28 ;
}
V_23 [ 0 ] = V_202 . V_204 [ 1 ] ;
V_23 [ 1 ] = V_202 . V_204 [ 2 ] ;
V_23 [ 2 ] = V_202 . V_204 [ 0 ] ;
V_23 [ 3 ] = F_100 ( 7 ) ;
if ( F_101 ( V_200 -> type ) )
V_23 [ 3 ] |= F_100 ( 6 ) ;
if ( V_200 -> V_205 && V_200 -> V_206 )
V_23 [ 3 ] |= F_100 ( 5 ) ;
if ( V_202 . V_207 && V_202 . V_208 )
memcpy ( V_23 + 4 , V_202 . V_207 , V_202 . V_208 ) ;
if ( V_202 . V_191 < V_203 )
memset ( V_23 + V_202 . V_191 , 0xff , V_203 - V_202 . V_191 ) ;
return V_203 ;
}
static int F_102 ( T_3 * V_209 , const struct V_199 * V_200 )
{
T_3 * V_23 = V_200 -> V_205 ;
if ( V_23 && ( V_200 -> V_206 >= 1 ) ) {
* V_23 = V_209 [ 1 ] ;
return 1 ;
} else {
F_11 ( L_53 ,
V_31 , V_200 -> V_206 ) ;
return - V_6 ;
}
}
static int F_103 ( T_3 * V_209 , const struct V_199 * V_200 )
{
T_3 * V_23 = V_200 -> V_205 ;
if ( V_23 && ( V_200 -> V_206 >= 2 ) ) {
V_23 [ 0 ] = V_209 [ 1 ] ;
V_23 [ 1 ] = V_209 [ 2 ] ;
return 2 ;
} else {
F_11 ( L_53 ,
V_31 , V_200 -> V_206 ) ;
return - V_6 ;
}
}
static int F_104 ( T_3 * V_209 , const struct V_199 * V_200 )
{
if ( V_200 -> V_205 && V_200 -> V_206 )
memcpy ( V_200 -> V_205 , V_209 + 4 , V_200 -> V_206 ) ;
return V_200 -> V_206 ;
}
static int F_105 ( struct V_19 * V_20 , int V_203 )
{
int V_28 ;
T_2 V_193 ;
bool V_210 ;
V_28 = F_106 ( V_20 -> V_195 , 0 , & V_193 ) ;
if ( V_28 ) {
F_11 ( L_54 , V_31 , V_28 ) ;
return V_28 ;
}
F_86 ( & V_20 -> V_211 ) ;
F_89 ( V_20 ) ;
V_210 = F_107 (
V_20 -> V_64 , V_193 , V_203 ) ;
if ( V_210 ) {
V_28 = F_87 ( & V_20 -> V_211 ,
F_88 ( 200 ) ) ;
F_15 ( L_55 , V_28 ) ;
if ( V_28 == 0 )
V_28 = - V_212 ;
else
V_28 = V_203 ;
} else
V_28 = V_203 ;
return V_28 ;
}
static int F_108 ( struct V_19 * V_20 ,
T_3 * V_209 , int V_213 , int V_214 )
{
T_2 * V_215 , * V_216 , V_23 ;
int V_46 , V_217 = 0 , V_218 ;
T_2 V_219 ;
T_3 V_21 [ 16 ] ;
int V_220 = 0 ;
int V_221 = V_209 - V_20 -> V_205 ;
V_215 = ( T_2 * ) V_209 ;
V_216 = ( T_2 * ) V_21 ;
V_218 = ( V_213 + 3 ) >> 2 ;
if ( V_218 > 4 )
V_218 = 4 ;
if ( V_213 == 4 )
V_219 = 4 ;
else
V_219 = V_214 + 6 ;
if ( V_219 > 16 ) {
int V_222 ;
V_222 = V_219 - 16 ;
V_220 = V_221 - V_222 ;
}
for ( V_46 = V_218 - 1 ; V_46 >= 0 ; V_46 -- ) {
V_23 = F_5 ( V_20 , F_109 ( V_46 ) ) ;
* V_216 ++ = F_110 ( V_23 ) ;
F_15 ( L_56 , V_23 , F_110 ( V_23 ) ) ;
}
for ( V_46 = V_220 ; V_46 < 16 ; V_46 ++ )
V_209 [ V_217 ++ ] = V_21 [ V_46 ] ;
return V_217 ;
}
static int F_111 ( struct V_19 * V_20 ,
const struct V_199 * V_200 )
{
int V_203 , V_28 ;
int V_223 = V_20 -> V_69 -> V_170 *
F_4 ( V_20 -> V_79 ) / 8 ;
V_203 = F_97 ( V_20 -> V_195 , V_200 ) ;
if ( ! V_203 ) {
F_11 ( L_57 ,
V_31 , V_200 -> type ) ;
return - V_6 ;
}
if ( ( V_20 -> V_89 & V_107 ) && ( V_203 > V_223 ) ) {
F_11 ( L_58 ,
V_31 , V_203 ) ;
return - V_6 ;
}
V_28 = F_105 ( V_20 , V_203 ) ;
if ( V_28 < V_203 ) {
F_11 ( L_59 ,
V_31 , V_200 -> type , ( * ( T_3 * ) ( V_200 -> V_224 ) ) , V_203 ) ;
return - V_225 ;
}
return V_203 ;
}
static void F_112 ( struct V_19 * V_20 )
{
T_2 V_226 , V_227 ;
V_226 = F_5 ( V_20 , V_106 ) ;
V_227 = V_226 ;
V_227 &= ~ V_155 ;
F_6 ( V_20 , V_106 , V_227 ) ;
F_43 () ;
F_6 ( V_20 , V_142 , V_143 ) ;
F_43 () ;
F_6 ( V_20 , V_182 , 1 ) ;
F_43 () ;
F_6 ( V_20 , V_182 , 0 ) ;
F_43 () ;
F_6 ( V_20 , V_106 , V_226 ) ;
F_43 () ;
}
static void F_113 ( struct V_228 * V_229 )
{
struct V_19 * V_20 =
F_20 ( V_229 , struct V_19 , V_230 ) ;
T_2 V_231 = V_20 -> V_232 ;
F_114 ( L_60 , V_31 , V_231 ) ;
if ( V_231 & V_233 )
F_112 ( V_20 ) ;
V_20 -> V_232 = 0 ;
F_45 ( V_20 , V_141 , 1 ) ;
}
static void F_115 ( struct V_19 * V_20 )
{
T_2 V_231 ;
V_231 = F_5 ( V_20 , V_234 ) ;
if ( V_231 ) {
F_6 ( V_20 , V_234 , V_231 ) ;
F_6 ( V_20 , V_234 , 0 ) ;
V_20 -> V_232 |= V_235 ;
}
}
static void F_116 ( struct V_19 * V_20 )
{
T_2 V_231 ;
V_231 = F_5 ( V_20 , V_236 ) ;
if ( V_231 ) {
F_6 ( V_20 , V_236 , V_231 ) ;
V_20 -> V_232 |= V_237 ;
}
}
static void F_117 ( struct V_19 * V_20 )
{
T_2 V_231 ;
V_231 = F_5 ( V_20 , V_238 ) ;
if ( V_231 & ( V_239 |
V_240 |
V_241 |
V_242 |
V_243 ) ) {
F_6 ( V_20 , V_238 , V_231 ) ;
V_20 -> V_232 |= V_244 ;
}
}
static void F_118 ( struct V_19 * V_20 )
{
T_2 V_231 ;
V_231 = F_5 ( V_20 , V_245 ) ;
if ( V_231 ) {
F_6 ( V_20 , V_245 , V_231 ) ;
V_20 -> V_232 |= V_246 ;
if ( V_231 & V_247 )
V_20 -> V_232 |=
V_233 ;
}
}
static void F_119 ( struct V_19 * V_20 )
{
T_2 V_231 ;
V_231 = F_5 ( V_20 , V_248 ) ;
if ( V_231 & V_249 ) {
F_6 ( V_20 , V_248 , V_231 ) ;
V_20 -> V_232 |=
V_250 ;
}
}
static void F_120 ( struct V_19 * V_20 )
{
T_2 V_231 ;
V_231 = F_5 ( V_20 , V_251 ) ;
if ( V_231 & V_252 ) {
F_6 ( V_20 , V_251 , V_231 ) ;
V_20 -> V_232 |= V_253 ;
}
}
static void F_121 ( struct V_19 * V_20 )
{
F_45 ( V_20 , V_141 , 0 ) ;
F_120 ( V_20 ) ;
F_118 ( V_20 ) ;
F_115 ( V_20 ) ;
F_116 ( V_20 ) ;
F_119 ( V_20 ) ;
F_117 ( V_20 ) ;
F_122 ( V_20 -> V_254 , & V_20 -> V_230 ) ;
}
static T_4 F_123 ( int V_255 , void * V_256 )
{
struct V_19 * V_20 = V_256 ;
T_2 V_257 ;
unsigned long V_85 ;
if ( ! V_20 -> V_22 )
return V_258 ;
F_46 ( & V_20 -> V_86 , V_85 ) ;
V_257 = F_5 ( V_20 , V_87 ) ;
F_6 ( V_20 , V_87 , V_257 ) ;
F_47 ( & V_20 -> V_86 , V_85 ) ;
F_15 ( L_61 , V_257 , V_20 -> V_64 ) ;
if ( V_257 & V_259 )
F_121 ( V_20 ) ;
if ( V_257 & V_260 )
F_124 ( & V_20 -> V_189 ) ;
if ( V_257 & V_261 )
F_124 ( & V_20 -> V_211 ) ;
return V_258 ;
}
static int F_125 ( struct V_19 * V_20 ,
struct V_55 * V_262 )
{
V_20 -> V_263 = F_126 ( V_262 ,
L_62 ,
V_264 ) ;
if ( F_10 ( V_20 -> V_263 ) ) {
F_15 ( L_63 ,
F_32 ( V_20 -> V_263 ) ) ;
return F_32 ( V_20 -> V_263 ) ;
}
V_20 -> V_265 = F_126 ( V_262 , L_64 ,
V_266 ) ;
if ( F_10 ( V_20 -> V_265 ) ) {
F_15 ( L_65 , F_32 ( V_20 -> V_265 ) ) ;
return F_32 ( V_20 -> V_265 ) ;
}
return 0 ;
}
static int F_127 ( struct V_36 * V_37 ,
struct V_267 * V_268 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
int V_28 ;
V_20 -> V_118 = V_268 -> V_118 ;
V_20 -> V_77 = V_268 -> V_77 ;
V_20 -> V_79 = V_268 -> V_79 ;
V_20 -> V_89 = V_268 -> V_89 ;
F_128 ( V_268 -> V_30 . V_269 != V_20 -> V_270 ) ;
V_28 = F_125 ( V_20 , & V_268 -> V_30 ) ;
if ( V_28 )
return V_28 ;
F_15 ( L_30 , V_20 -> V_64 ) ;
if ( V_20 -> V_30 )
F_129 ( V_20 -> V_30 ) ;
return 0 ;
}
static int F_130 ( struct V_36 * V_37 ,
struct V_267 * V_268 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
V_20 -> V_270 = NULL ;
F_15 ( L_30 , V_20 -> V_64 ) ;
if ( V_20 -> V_30 )
F_129 ( V_20 -> V_30 ) ;
return 0 ;
}
static T_5 F_131 ( struct V_36 * V_37 ,
const struct V_199 * V_200 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
int V_28 ;
if ( ! V_200 || ! V_20 -> V_190 )
return - V_6 ;
F_39 ( & V_20 -> V_271 ) ;
V_28 = F_132 ( V_20 -> V_64 , V_200 ) ;
F_40 ( & V_20 -> V_271 ) ;
return V_28 ;
}
static int F_133 ( struct V_19 * V_20 )
{
struct V_55 * V_30 = & V_20 -> V_29 -> V_30 ;
struct V_270 * V_272 = V_30 -> V_269 ;
struct V_270 * V_273 , * V_270 ;
int V_28 ;
V_28 = F_134 ( V_272 , L_66 , & V_20 -> V_64 ) ;
if ( V_28 ) {
F_135 ( V_30 , L_67 ,
V_31 , V_28 ) ;
return V_28 ;
}
V_273 = F_136 ( V_272 , NULL ) ;
if ( ! V_273 ) {
F_137 ( V_30 , L_68 , V_31 ) ;
return 0 ;
}
V_270 = F_138 ( V_273 ) ;
if ( ! V_270 ) {
F_135 ( V_30 , L_69 , V_31 ) ;
F_139 ( V_273 ) ;
return - V_274 ;
}
F_139 ( V_273 ) ;
F_139 ( V_270 ) ;
V_20 -> V_270 = V_270 ;
return 0 ;
}
int F_140 ( struct V_275 * V_275 )
{
struct V_19 * V_20 = NULL ;
struct V_276 * V_29 = V_275 -> V_29 ;
int V_28 ;
V_20 = F_141 ( & V_29 -> V_30 , sizeof( * V_20 ) , V_277 ) ;
if ( ! V_20 ) {
F_11 ( L_70 ,
V_31 ) ;
V_28 = - V_278 ;
goto V_50;
}
V_20 -> V_29 = V_29 ;
V_28 = F_133 ( V_20 ) ;
if ( V_28 ) {
F_11 ( L_71 , V_31 ) ;
goto V_50;
}
V_28 = F_30 ( V_20 ) ;
if ( V_28 ) {
F_11 ( L_72 , V_31 ) ;
goto V_50;
}
V_20 -> V_22 = F_142 ( V_29 , L_73 , L_74 ) ;
if ( F_10 ( V_20 -> V_22 ) ) {
F_11 ( L_75 , V_31 ) ;
V_28 = F_32 ( V_20 -> V_22 ) ;
goto V_50;
}
V_20 -> V_25 = F_8 ( V_20 ) ;
if ( ! V_20 -> V_25 ) {
V_28 = - V_6 ;
F_11 ( L_76 , V_31 ) ;
goto V_50;
}
V_20 -> V_22 += V_20 -> V_25 -> V_43 -> V_279 ;
V_28 = F_26 ( V_20 ) ;
if ( V_28 ) {
F_11 ( L_77 , V_31 ) ;
goto V_50;
}
V_20 -> V_205 = F_141 ( & V_29 -> V_30 , V_280 , V_277 ) ;
if ( ! V_20 -> V_205 ) {
F_11 ( L_78 , V_31 ) ;
goto V_50;
}
F_143 ( & V_20 -> V_211 ) ;
F_143 ( & V_20 -> V_189 ) ;
F_144 ( & V_20 -> V_281 ) ;
F_144 ( & V_20 -> V_271 ) ;
F_144 ( & V_20 -> V_74 ) ;
F_145 ( & V_20 -> V_86 ) ;
V_20 -> V_254 = F_146 ( L_79 , 0 ) ;
F_147 ( & V_20 -> V_230 , F_113 ) ;
V_275 -> V_37 = & V_20 -> V_1 ;
V_275 -> V_64 = V_20 -> V_64 ;
F_15 ( L_80 , V_20 -> V_64 ) ;
return 0 ;
V_50:
return V_28 ;
}
void F_148 ( struct V_36 * V_37 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
F_15 ( L_7 ) ;
F_94 ( V_20 ) ;
if ( V_20 -> V_254 ) {
F_149 ( V_20 -> V_254 ) ;
F_150 ( V_20 -> V_254 ) ;
V_20 -> V_254 = NULL ;
}
F_151 ( & V_20 -> V_74 ) ;
F_151 ( & V_20 -> V_271 ) ;
F_151 ( & V_20 -> V_281 ) ;
}
int F_152 ( struct V_36 * V_37 ,
struct V_192 * V_30 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
struct V_276 * V_29 = V_20 -> V_29 ;
int V_28 ;
V_20 -> V_255 = F_153 ( V_29 -> V_30 . V_269 , 0 ) ;
if ( V_20 -> V_255 < 0 ) {
V_28 = V_20 -> V_255 ;
F_135 ( V_30 -> V_30 , L_81 , V_28 ) ;
return V_28 ;
}
V_28 = F_154 ( & V_29 -> V_30 , V_20 -> V_255 ,
F_123 , V_282 | V_283 ,
L_82 , V_20 ) ;
if ( V_28 < 0 ) {
F_135 ( & V_29 -> V_30 , L_83 ,
V_20 -> V_255 , V_28 ) ;
return V_28 ;
}
V_20 -> V_30 = V_30 ;
V_28 = F_91 ( V_20 , V_280 ) ;
if ( V_28 ) {
F_11 ( L_84 , V_31 , V_28 ) ;
return V_28 ;
}
return 0 ;
}
int F_155 ( struct V_36 * V_37 , bool V_284 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
int V_28 ;
if ( ! V_20 -> V_285 ) {
V_37 -> V_30 = & V_20 -> V_29 -> V_30 ;
V_37 -> V_286 = & V_287 ;
V_28 = F_156 ( V_37 ) ;
if ( V_28 )
return V_28 ;
V_20 -> V_285 = true ;
if ( V_284 && V_20 -> V_270 ) {
if ( ! F_157 ( V_20 -> V_270 ) )
if ( ! F_158 ( V_20 -> V_270 ) )
return - V_288 ;
}
}
return 0 ;
}
void F_159 ( struct V_36 * V_37 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
if ( V_20 -> V_285 ) {
F_160 ( V_37 ) ;
V_37 -> V_30 = NULL ;
V_37 -> V_286 = NULL ;
V_20 -> V_285 = false ;
}
}
int F_161 ( struct V_36 * V_37 ,
const struct V_199 * V_200 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
F_38 ( V_20 , 1 ) ;
if ( ! ( V_200 -> V_85 & V_289 ) )
F_84 ( 0 , V_20 ) ;
V_20 -> V_290 = F_5 ( V_20 , V_106 ) ;
F_6 ( V_20 , V_106 ,
V_20 -> V_290 |
V_186 |
V_155 ) ;
F_45 ( V_20 , V_291 , 1 ) ;
return 0 ;
}
void F_162 ( struct V_36 * V_37 ,
const struct V_199 * V_200 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
F_45 ( V_20 , V_291 , 0 ) ;
F_6 ( V_20 , V_106 , V_20 -> V_290 ) ;
if ( ! ( V_200 -> V_85 & V_289 ) )
F_84 ( 1 , V_20 ) ;
F_38 ( V_20 , 0 ) ;
}
int F_163 ( struct V_36 * V_37 ,
const struct V_199 * V_200 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
return F_111 ( V_20 , V_200 ) ;
}
int F_164 ( struct V_36 * V_37 ,
const struct V_199 * V_200 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
const struct V_24 * V_25 = V_20 -> V_25 ;
int V_292 , V_213 , V_293 , V_294 ;
int V_295 , V_296 , V_214 , V_28 = 0 ;
char V_297 ;
int V_298 = V_200 -> V_206 ;
T_3 * V_209 ;
if ( V_298 <= 2 ) {
V_295 = 1 ;
V_214 = V_298 ;
V_213 = 4 ;
} else {
V_295 = 0 ;
V_292 = 10 ;
if ( V_298 < V_292 )
V_214 = V_298 ;
else
V_214 = V_292 ;
V_213 = V_292 + 6 ;
}
V_209 = V_20 -> V_205 ;
V_294 = 0 ;
while ( ! V_294 ) {
T_3 V_299 [ 2 ] = { V_214 & 0xff , V_214 >> 8 } ;
struct V_199 V_300 = {
. V_118 = V_200 -> V_118 ,
. type = V_301 ,
. V_302 = 2 ,
. V_224 = V_299 ,
} ;
F_15 ( L_85 ,
V_298 , V_214 , V_213 ) ;
V_28 = F_111 ( V_20 , & V_300 ) ;
if ( V_28 < 2 ) {
F_11 ( L_86 ,
V_31 , V_28 ) ;
return - V_6 ;
}
if ( ( V_25 -> V_2 == V_12 ) &&
( V_25 -> V_3 >= V_303 ) ) {
F_6 ( V_20 , V_304 ,
V_305 ) ;
F_43 () ;
F_6 ( V_20 , V_304 , 0 ) ;
F_43 () ;
}
V_28 = F_111 ( V_20 , V_200 ) ;
if ( V_28 < V_200 -> V_302 ) {
F_11 ( L_87 , V_31 , V_28 ) ;
return V_28 ;
}
V_293 = F_108 ( V_20 , V_209 , V_213 , V_214 ) ;
if ( V_293 <= 0 )
return 0 ;
if ( V_295 )
break;
if ( V_298 <= V_292 ) {
V_296 = V_292 - V_298 ;
V_294 = 1 ;
} else {
V_296 = 0 ;
V_298 -= V_292 ;
}
if ( ! V_294 ) {
V_293 -= 2 ;
V_293 -= V_296 ;
V_209 += V_293 ;
V_292 = 14 ;
if ( V_298 < V_292 )
V_214 += V_298 ;
else
V_214 += V_292 ;
F_15 ( L_88 , V_209 , V_293 , V_296 ) ;
}
}
if ( V_214 < 10 && ! V_295 )
V_209 = V_20 -> V_205 + ( 10 - V_298 ) ;
else
V_209 = V_20 -> V_205 ;
V_297 = V_209 [ 0 ] ;
switch ( V_297 ) {
case V_306 :
F_11 ( L_89 , V_31 ) ;
V_28 = 0 ;
break;
case V_307 :
case V_308 :
V_28 = F_102 ( V_209 , V_200 ) ;
break;
case V_309 :
case V_310 :
V_28 = F_103 ( V_209 , V_200 ) ;
break;
case V_311 :
case V_312 :
V_28 = F_104 ( V_209 , V_200 ) ;
break;
default:
F_165 ( L_90 , V_31 ) ;
V_28 = 0 ;
}
return V_28 ;
}
void F_166 ( struct V_36 * V_37 , T_2 V_193 , T_2 V_203 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
F_6 ( V_20 , V_313 , V_193 ) ;
F_6 ( V_20 , V_314 , V_203 ) ;
F_6 ( V_20 , V_315 , 1 ) ;
F_43 () ;
}
int F_167 ( struct V_36 * V_37 ,
struct V_316 * V_317 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
struct V_318 * V_319 , * V_320 ;
int V_28 ;
V_28 = F_168 ( V_317 ,
& V_319 , & V_320 ) ;
if ( V_28 ) {
F_169 ( L_91 ,
V_31 ) ;
return 0 ;
}
V_28 = F_170 ( V_20 -> V_62 , V_319 ) ;
if ( V_28 ) {
F_11 ( L_92 ,
V_31 , V_28 ) ;
goto exit;
}
V_28 = F_170 ( V_20 -> V_63 , V_320 ) ;
if ( V_28 ) {
F_11 ( L_93 ,
V_31 , V_28 ) ;
goto exit;
}
exit:
return V_28 ;
}
int F_171 ( struct V_36 * V_37 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
F_83 ( V_20 ,
! ! ( V_20 -> V_89 & V_107 ) , true ) ;
return 0 ;
}
int F_172 ( struct V_36 * V_37 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
F_83 ( V_20 ,
! ! ( V_20 -> V_89 & V_107 ) , false ) ;
F_82 ( V_20 ) ;
return 0 ;
}
int F_173 ( struct V_36 * V_37 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
T_2 V_104 = 0 , V_105 = 0 ;
int V_28 = 0 ;
F_39 ( & V_20 -> V_281 ) ;
if ( V_20 -> V_190 ) {
F_15 ( L_94 ) ;
goto V_75;
}
V_28 = F_41 ( V_20 ) ;
if ( V_28 ) {
F_11 ( L_95 , V_31 , V_28 ) ;
goto V_75;
}
V_28 = F_24 ( V_20 ) ;
if ( V_28 ) {
F_11 ( L_96 ,
V_31 , V_28 ) ;
goto V_75;
}
V_28 = F_33 ( V_20 ) ;
if ( V_28 ) {
F_11 ( L_97 , V_31 , V_28 ) ;
goto V_321;
}
F_42 ( V_20 ) ;
V_28 = F_174 ( V_20 -> V_64 ,
V_20 -> V_70 * 8 ,
F_175 ( V_20 -> V_61 ) ,
& V_104 , & V_105 ) ;
F_34 ( V_20 ) ;
if ( V_28 ) {
F_11 ( L_98 , V_31 , V_28 ) ;
goto V_321;
}
V_28 = F_38 ( V_20 , 1 ) ;
if ( V_28 ) {
F_11 ( L_99 , V_31 , V_28 ) ;
goto V_321;
}
V_28 = F_176 ( & V_20 -> V_29 -> V_30 ) ;
if ( V_28 ) {
F_11 ( L_100 ,
V_31 , V_28 ) ;
goto V_322;
}
F_66 ( V_20 ) ;
F_82 ( V_20 ) ;
F_51 ( V_20 , true , V_104 , V_105 ) ;
if ( V_20 -> V_263 )
F_177 ( V_20 -> V_263 , 1 ) ;
V_20 -> V_190 = true ;
F_40 ( & V_20 -> V_281 ) ;
return 0 ;
V_322:
F_38 ( V_20 , 0 ) ;
V_321:
F_21 ( V_20 ) ;
V_75:
F_40 ( & V_20 -> V_281 ) ;
return V_28 ;
}
int F_178 ( struct V_36 * V_37 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
F_39 ( & V_20 -> V_281 ) ;
if ( ! V_20 -> V_190 ) {
F_15 ( L_101 ) ;
goto V_75;
}
F_51 ( V_20 , false , 0 , 0 ) ;
if ( V_20 -> V_263 )
F_177 ( V_20 -> V_263 , 0 ) ;
F_179 ( & V_20 -> V_29 -> V_30 ) ;
F_180 ( V_20 -> V_64 ) ;
F_38 ( V_20 , 0 ) ;
F_21 ( V_20 ) ;
F_15 ( L_102 ) ;
V_20 -> V_190 = false ;
V_75:
F_40 ( & V_20 -> V_281 ) ;
return 0 ;
}
int F_181 ( struct V_36 * V_37 ,
struct V_76 * V_69 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
if ( V_20 -> V_69 ) {
F_182 ( V_20 -> V_30 , V_20 -> V_69 ) ;
V_20 -> V_69 = NULL ;
}
V_20 -> V_69 = F_183 ( V_20 -> V_30 , V_69 ) ;
if ( F_10 ( V_20 -> V_69 ) ) {
F_11 ( L_103 , V_31 ) ;
return F_32 ( V_20 -> V_69 ) ;
}
return 0 ;
}
struct V_323 * F_184 ( struct V_36 * V_37 ,
unsigned long * V_324 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
struct V_323 * V_325 ;
V_325 = F_157 ( V_20 -> V_270 ) ;
if ( V_324 )
* V_324 = V_20 -> V_89 ;
return V_325 ;
}
struct V_326 * F_185 ( struct V_36 * V_37 )
{
struct V_19 * V_20 = F_19 ( V_37 ) ;
return F_158 ( V_20 -> V_270 ) ;
}
