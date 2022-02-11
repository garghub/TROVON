static int F_1 ( const void T_1 * V_1 , T_2 * V_2 , T_2 * V_3 )
{
T_2 V_4 ;
if ( ! V_2 || ! V_3 )
return - V_5 ;
V_4 = F_2 ( V_1 + V_6 ) ;
if ( V_4 ) {
V_4 = F_3 ( V_4 , V_7 ) ;
if ( V_4 <= V_8 ) {
* V_2 = V_4 ;
* V_3 = 0 ;
return 0 ;
} else {
return - V_5 ;
}
} else {
V_4 = F_2 ( V_1 + V_9 + V_6 ) ;
V_4 = F_3 ( V_4 , V_7 ) ;
if ( V_4 == V_10 ) {
* V_2 = V_4 ;
* V_3 = F_2 ( V_1 + V_11 ) ;
return 0 ;
} else {
return - V_5 ;
}
}
}
static T_2 F_4 ( const enum V_12 V_13 )
{
switch ( V_13 ) {
case V_14 : return 16 ;
case V_15 : return 18 ;
case V_16 :
case V_17 :
default: return 24 ;
}
}
static inline T_2 F_5 ( struct V_18 * V_19 , T_2 V_20 )
{
return F_2 ( V_19 -> V_21 + V_20 ) ;
}
static inline void F_6 ( struct V_18 * V_19 , T_2 V_20 , T_2 V_22 )
{
F_7 ( V_22 , V_19 -> V_21 + V_20 ) ;
}
static const struct V_23 * F_8 (
struct V_18 * V_19 )
{
const struct V_23 * V_24 = NULL ;
struct V_25 * V_26 = & V_19 -> V_27 -> V_26 ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
int V_32 ;
T_2 V_2 = 0 , V_3 = 0 ;
V_29 = F_9 ( V_26 , L_1 ) ;
if ( F_10 ( V_29 ) ) {
F_11 ( L_2 , V_33 ) ;
goto exit;
}
V_31 = F_12 ( V_26 , L_3 ) ;
if ( F_10 ( V_31 ) ) {
F_11 ( L_4 , V_33 ) ;
goto V_34;
}
F_13 ( V_26 ) ;
V_32 = F_14 ( V_29 ) ;
if ( V_32 ) {
F_11 ( L_5 , V_33 ) ;
goto V_35;
}
V_32 = F_15 ( V_31 ) ;
if ( V_32 ) {
F_11 ( L_6 , V_33 ) ;
goto V_36;
}
V_32 = F_1 ( V_19 -> V_21 , & V_2 , & V_3 ) ;
if ( V_32 ) {
F_11 ( L_7 , V_33 ) ;
goto V_37;
}
V_24 = F_16 ( V_2 , V_3 ) ;
F_17 ( L_8 , V_33 , V_2 , V_3 ) ;
V_37:
F_18 ( V_31 ) ;
V_36:
F_19 ( V_29 ) ;
F_20 ( V_26 ) ;
V_35:
F_21 ( V_31 ) ;
V_34:
F_22 ( V_29 ) ;
exit:
return V_24 ;
}
static inline struct V_18 * F_23 ( struct V_38 * V_39 )
{
return F_24 ( V_39 , struct V_18 , V_1 ) ;
}
static void F_25 ( struct V_18 * V_19 )
{
struct V_40 * V_41 = V_19 -> V_42 ;
const struct V_43 * V_44 = V_19 -> V_24 -> V_45 -> V_46 . V_44 ;
int V_47 = V_19 -> V_24 -> V_45 -> V_46 . V_47 ;
int V_48 ;
F_17 ( L_9 ) ;
for ( V_48 = V_47 - 1 ; V_48 >= 0 ; V_48 -- )
if ( V_44 [ V_48 ] . V_49 >= 0 )
F_26 ( V_41 [ V_48 ] . V_50 ,
V_44 [ V_48 ] . V_49 ) ;
F_27 ( V_47 , V_41 ) ;
}
static int F_28 ( struct V_18 * V_19 )
{
struct V_40 * V_41 = V_19 -> V_42 ;
const struct V_43 * V_44 = V_19 -> V_24 -> V_45 -> V_46 . V_44 ;
int V_47 = V_19 -> V_24 -> V_45 -> V_46 . V_47 ;
int V_32 , V_48 ;
F_17 ( L_9 ) ;
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ ) {
if ( V_44 [ V_48 ] . V_51 >= 0 ) {
V_32 = F_26 ( V_41 [ V_48 ] . V_50 ,
V_44 [ V_48 ] . V_51 ) ;
if ( V_32 < 0 ) {
F_11 ( L_10 ,
V_48 , V_32 ) ;
goto V_52;
}
}
}
V_32 = F_29 ( V_47 , V_41 ) ;
if ( V_32 < 0 ) {
F_11 ( L_11 , V_32 ) ;
goto V_52;
}
return 0 ;
V_52:
for ( V_48 -- ; V_48 >= 0 ; V_48 -- )
F_26 ( V_41 [ V_48 ] . V_50 , V_44 [ V_48 ] . V_49 ) ;
return V_32 ;
}
static int F_30 ( struct V_18 * V_19 )
{
struct V_40 * V_41 = V_19 -> V_42 ;
const struct V_43 * V_44 = V_19 -> V_24 -> V_45 -> V_46 . V_44 ;
int V_47 = V_19 -> V_24 -> V_45 -> V_46 . V_47 ;
int V_48 , V_32 ;
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ )
V_41 [ V_48 ] . V_53 = V_44 [ V_48 ] . V_54 ;
V_32 = F_31 ( & V_19 -> V_27 -> V_26 , V_47 , V_41 ) ;
if ( V_32 < 0 ) {
F_11 ( L_12 ,
V_33 , V_32 ) ;
return V_32 ;
}
return 0 ;
}
static int F_32 ( struct V_18 * V_19 )
{
struct V_25 * V_26 = & V_19 -> V_27 -> V_26 ;
const struct V_23 * V_24 = V_19 -> V_24 ;
const struct V_55 * V_45 = V_24 -> V_45 ;
int V_48 , V_32 = 0 ;
for ( V_48 = 0 ; V_48 < V_45 -> V_56 ; V_48 ++ ) {
V_19 -> V_57 [ V_48 ] = F_33 ( V_26 ,
V_45 -> V_58 [ V_48 ] ) ;
if ( F_10 ( V_19 -> V_57 [ V_48 ] ) ) {
V_32 = F_34 ( V_19 -> V_57 [ V_48 ] ) ;
F_11 ( L_13 ,
V_33 , V_45 -> V_58 [ V_48 ] , V_32 ) ;
goto exit;
}
}
V_19 -> V_59 = F_33 ( V_26 , L_14 ) ;
if ( F_10 ( V_19 -> V_59 ) ) {
V_32 = F_34 ( V_19 -> V_59 ) ;
F_11 ( L_15 ,
V_33 , V_32 ) ;
V_19 -> V_59 = NULL ;
goto exit;
}
V_19 -> V_60 = F_33 ( V_26 , L_16 ) ;
if ( F_10 ( V_19 -> V_60 ) ) {
V_32 = F_34 ( V_19 -> V_60 ) ;
F_11 ( L_17 ,
V_33 , V_32 ) ;
V_19 -> V_60 = NULL ;
goto exit;
}
V_19 -> V_61 = F_33 ( V_26 , L_18 ) ;
if ( F_10 ( V_19 -> V_61 ) ) {
V_32 = F_34 ( V_19 -> V_61 ) ;
F_11 ( L_19 ,
V_33 , V_32 ) ;
V_19 -> V_61 = NULL ;
goto exit;
}
V_19 -> V_62 = F_35 ( V_19 -> V_59 ) ;
if ( ! V_19 -> V_62 ) {
V_32 = - V_63 ;
F_11 ( L_20 , V_33 , V_32 ) ;
goto exit;
}
V_19 -> V_64 = F_35 ( V_19 -> V_60 ) ;
if ( ! V_19 -> V_64 ) {
V_32 = - V_63 ;
F_11 ( L_21 , V_33 , V_32 ) ;
goto exit;
}
if ( V_24 -> V_2 == V_8 ) {
V_19 -> V_65 = F_33 ( V_26 , L_22 ) ;
if ( F_10 ( V_19 -> V_65 ) ) {
V_32 = F_34 ( V_19 -> V_65 ) ;
F_11 ( L_23 ,
V_33 , V_32 ) ;
V_19 -> V_65 = NULL ;
goto exit;
}
V_19 -> V_66 = F_35 ( V_19 -> V_61 ) ;
if ( ! V_19 -> V_66 ) {
V_32 = - V_63 ;
F_11 ( L_24 ,
V_33 , V_32 ) ;
goto exit;
}
V_19 -> V_67 = F_35 ( V_19 -> V_65 ) ;
if ( ! V_19 -> V_67 ) {
V_32 = - V_63 ;
F_11 ( L_25 ,
V_33 , V_32 ) ;
}
}
exit:
return V_32 ;
}
static int F_36 ( struct V_18 * V_19 )
{
const struct V_55 * V_45 = V_19 -> V_24 -> V_45 ;
int V_48 , V_32 ;
F_17 ( L_26 , V_19 -> V_68 ) ;
for ( V_48 = 0 ; V_48 < V_45 -> V_56 ; V_48 ++ ) {
V_32 = F_15 ( V_19 -> V_57 [ V_48 ] ) ;
if ( V_32 ) {
F_11 ( L_27 ,
V_33 , V_48 , V_32 ) ;
goto V_69;
}
}
return 0 ;
V_69:
for (; V_48 > 0 ; V_48 -- )
F_18 ( V_19 -> V_57 [ V_48 ] ) ;
return V_32 ;
}
static void F_37 ( struct V_18 * V_19 )
{
const struct V_55 * V_45 = V_19 -> V_24 -> V_45 ;
int V_48 ;
F_17 ( L_9 ) ;
for ( V_48 = V_45 -> V_56 - 1 ; V_48 >= 0 ; V_48 -- )
F_18 ( V_19 -> V_57 [ V_48 ] ) ;
}
int F_38 ( struct V_25 * V_26 )
{
struct V_70 * V_27 = F_39 ( V_26 ) ;
struct V_71 * V_71 = F_40 ( V_27 ) ;
struct V_38 * V_39 = V_71 -> V_39 ;
struct V_18 * V_19 = F_23 ( V_39 ) ;
if ( ! V_19 -> V_24 )
return 0 ;
F_37 ( V_19 ) ;
return 0 ;
}
int F_41 ( struct V_25 * V_26 )
{
struct V_70 * V_27 = F_39 ( V_26 ) ;
struct V_71 * V_71 = F_40 ( V_27 ) ;
struct V_38 * V_39 = V_71 -> V_39 ;
struct V_18 * V_19 = F_23 ( V_39 ) ;
if ( ! V_19 -> V_24 )
return 0 ;
return F_36 ( V_19 ) ;
}
static int F_42 ( struct V_18 * V_19 )
{
int V_32 ;
F_17 ( L_28 ,
V_19 -> V_72 -> clock , V_19 -> V_73 ) ;
V_32 = F_43 ( V_19 -> V_59 , V_19 -> V_73 ) ;
if ( V_32 ) {
F_11 ( L_29 , V_33 , V_32 ) ;
goto error;
}
V_32 = F_43 ( V_19 -> V_60 , V_19 -> V_72 -> clock * 1000 ) ;
if ( V_32 ) {
F_11 ( L_30 , V_33 , V_32 ) ;
goto error;
}
V_32 = F_15 ( V_19 -> V_61 ) ;
if ( V_32 ) {
F_11 ( L_31 , V_33 ) ;
goto error;
}
V_32 = F_15 ( V_19 -> V_59 ) ;
if ( V_32 ) {
F_11 ( L_32 , V_33 ) ;
goto V_74;
}
V_32 = F_15 ( V_19 -> V_60 ) ;
if ( V_32 ) {
F_11 ( L_33 , V_33 ) ;
goto V_75;
}
return 0 ;
V_75:
F_18 ( V_19 -> V_59 ) ;
V_74:
F_18 ( V_19 -> V_61 ) ;
error:
return V_32 ;
}
static int F_44 ( struct V_18 * V_19 )
{
int V_32 ;
F_17 ( L_34 ,
V_19 -> V_72 -> clock , V_19 -> V_73 ,
V_19 -> V_76 , V_19 -> V_77 ) ;
V_32 = F_43 ( V_19 -> V_59 , V_19 -> V_73 ) ;
if ( V_32 ) {
F_11 ( L_29 , V_33 , V_32 ) ;
goto error;
}
V_32 = F_43 ( V_19 -> V_61 , V_19 -> V_76 ) ;
if ( V_32 ) {
F_11 ( L_35 , V_33 , V_32 ) ;
goto error;
}
V_32 = F_43 ( V_19 -> V_65 , V_19 -> V_77 ) ;
if ( V_32 ) {
F_11 ( L_36 , V_33 , V_32 ) ;
goto error;
}
V_32 = F_43 ( V_19 -> V_60 , V_19 -> V_72 -> clock * 1000 ) ;
if ( V_32 ) {
F_11 ( L_30 , V_33 , V_32 ) ;
goto error;
}
V_32 = F_15 ( V_19 -> V_59 ) ;
if ( V_32 ) {
F_11 ( L_32 , V_33 ) ;
goto error;
}
V_32 = F_15 ( V_19 -> V_61 ) ;
if ( V_32 ) {
F_11 ( L_31 , V_33 ) ;
goto V_78;
}
V_32 = F_15 ( V_19 -> V_65 ) ;
if ( V_32 ) {
F_11 ( L_37 , V_33 ) ;
goto V_79;
}
V_32 = F_15 ( V_19 -> V_60 ) ;
if ( V_32 ) {
F_11 ( L_33 , V_33 ) ;
goto V_75;
}
return 0 ;
V_75:
F_18 ( V_19 -> V_65 ) ;
V_79:
F_18 ( V_19 -> V_61 ) ;
V_78:
F_18 ( V_19 -> V_59 ) ;
error:
return V_32 ;
}
static int F_45 ( struct V_18 * V_19 )
{
const struct V_23 * V_24 = V_19 -> V_24 ;
if ( V_24 -> V_2 == V_10 )
return F_42 ( V_19 ) ;
else
return F_44 ( V_19 ) ;
}
static void F_46 ( struct V_18 * V_19 )
{
const struct V_23 * V_24 = V_19 -> V_24 ;
if ( V_24 -> V_2 == V_10 ) {
F_18 ( V_19 -> V_61 ) ;
F_18 ( V_19 -> V_60 ) ;
F_18 ( V_19 -> V_59 ) ;
} else {
F_18 ( V_19 -> V_60 ) ;
F_18 ( V_19 -> V_65 ) ;
F_18 ( V_19 -> V_61 ) ;
F_18 ( V_19 -> V_59 ) ;
}
}
static int F_47 ( struct V_18 * V_19 )
{
struct V_80 * V_72 = V_19 -> V_72 ;
const struct V_23 * V_24 = V_19 -> V_24 ;
T_3 V_81 = V_19 -> V_81 ;
T_2 V_82 = F_4 ( V_19 -> V_83 ) ;
T_2 V_84 ;
if ( ! V_72 ) {
F_11 ( L_38 , V_33 ) ;
return - V_5 ;
}
V_84 = V_72 -> clock * 1000 ;
if ( V_81 > 0 ) {
V_19 -> V_73 = ( V_84 * V_82 ) / ( 8 * V_81 ) ;
} else {
F_11 ( L_39 , V_33 ) ;
V_19 -> V_73 = ( V_84 * V_82 ) / 8 ;
}
F_17 ( L_40 , V_84 , V_19 -> V_73 ) ;
V_19 -> V_76 = F_48 ( V_19 -> V_61 ) ;
if ( V_24 -> V_2 == V_8 ) {
unsigned int V_85 , V_86 ;
unsigned long V_87 ;
V_19 -> V_77 = ( V_84 * V_82 ) / 8 ;
V_87 = V_19 -> V_73 / 1000000 ;
for ( V_85 = 20 ; V_85 >= 5 ; V_85 -- ) {
V_86 = F_49 ( V_87 , V_85 ) ;
if ( V_86 >= 1 && V_86 <= 16 )
break;
}
if ( V_85 < 5 )
return - V_5 ;
V_19 -> V_76 = V_19 -> V_73 / V_86 ;
F_17 ( L_41 , V_19 -> V_76 ,
V_19 -> V_77 ) ;
}
return 0 ;
}
static void F_50 ( struct V_18 * V_19 , T_2 V_88 , int V_89 )
{
T_2 V_90 ;
unsigned long V_91 ;
F_51 ( & V_19 -> V_92 , V_91 ) ;
V_90 = F_5 ( V_19 , V_93 ) ;
if ( V_89 )
V_90 |= V_88 ;
else
V_90 &= ~ V_88 ;
F_17 ( L_42 , V_90 , V_89 ) ;
F_6 ( V_19 , V_93 , V_90 ) ;
F_52 ( & V_19 -> V_92 , V_91 ) ;
}
static inline enum V_94 F_53 ( const T_2 V_95 )
{
if ( V_95 & V_96 )
return V_97 ;
else if ( V_95 & V_98 )
return V_99 ;
return V_100 ;
}
static inline enum V_101 F_54 (
const enum V_12 V_102 )
{
switch ( V_102 ) {
case V_17 : return V_103 ;
case V_16 : return V_104 ;
case V_15 : return V_105 ;
case V_14 : return V_106 ;
default: return V_103 ;
}
}
static inline enum V_107 F_55 (
const enum V_12 V_102 )
{
switch ( V_102 ) {
case V_17 : return V_108 ;
case V_15 :
case V_16 : return V_105 ;
case V_14 : return V_109 ;
default: return V_108 ;
}
}
static void F_56 ( struct V_18 * V_19 , bool V_89 ,
struct V_110 * V_111 )
{
T_2 V_91 = V_19 -> V_95 ;
enum V_12 V_102 = V_19 -> V_83 ;
const struct V_23 * V_24 = V_19 -> V_24 ;
T_2 V_22 = 0 ;
if ( ! V_89 ) {
F_6 ( V_19 , V_112 , 0 ) ;
return;
}
if ( V_91 & V_113 ) {
if ( V_91 & V_114 )
V_22 |= V_115 ;
if ( V_91 & V_116 )
V_22 |= V_117 ;
if ( V_91 & V_118 )
V_22 |= V_119 ;
if ( V_91 & V_120 )
V_22 |= V_121 ;
V_22 |= V_122 |
V_123 ;
V_22 |= F_57 ( F_53 ( V_91 ) ) ;
V_22 |= F_58 ( F_54 ( V_102 ) ) ;
V_22 |= F_59 ( V_19 -> V_124 ) ;
F_6 ( V_19 , V_125 , V_22 ) ;
V_22 = F_60 ( V_126 ) ;
F_6 ( V_19 , V_127 , 0 ) ;
} else {
V_22 = F_61 ( V_126 ) ;
V_22 |= F_62 ( F_55 ( V_102 ) ) ;
F_6 ( V_19 , V_128 , V_22 ) ;
V_22 = F_63 ( V_129 ) |
F_64 (
V_130 ) ;
V_22 |= V_131 ;
F_6 ( V_19 , V_132 , V_22 ) ;
}
F_6 ( V_19 , V_133 ,
V_134 |
V_135 ) ;
V_22 = 0 ;
V_22 |= V_136 ;
V_22 |= F_65 ( V_137 ) ;
V_22 |= F_66 ( V_138 ) ;
V_22 |= F_67 ( V_19 -> V_124 ) ;
if ( ( V_24 -> V_2 == V_10 ) &&
( V_24 -> V_3 >= V_139 ) )
V_22 |= V_140 ;
F_6 ( V_19 , V_141 , V_22 ) ;
V_22 = F_68 ( V_111 -> V_142 ) |
F_69 ( V_111 -> V_143 ) ;
F_6 ( V_19 , V_144 , V_22 ) ;
if ( ( V_24 -> V_2 == V_10 ) &&
( V_24 -> V_3 > V_145 ) &&
V_111 -> V_146 )
F_6 ( V_19 , V_147 ,
V_148 ) ;
V_22 = 0 ;
if ( ! ( V_91 & V_149 ) )
V_22 |= V_150 ;
F_6 ( V_19 , V_151 , V_22 ) ;
F_6 ( V_19 , V_152 , 0x13ff3fe0 ) ;
F_50 ( V_19 , V_153 , 1 ) ;
F_6 ( V_19 , V_154 , V_155 ) ;
V_22 = V_156 ;
F_17 ( L_43 , V_19 -> V_81 ) ;
V_22 |= ( ( V_157 << V_19 -> V_81 ) - V_157 ) ;
F_6 ( V_19 , V_158 ,
F_70 ( V_19 -> V_159 ) ) ;
if ( ! ( V_91 & V_160 ) )
F_6 ( V_19 , V_161 ,
V_162 ) ;
V_22 |= V_163 ;
F_6 ( V_19 , V_112 , V_22 ) ;
}
static void F_71 ( struct V_18 * V_19 )
{
struct V_80 * V_72 = V_19 -> V_72 ;
T_2 V_164 = 0 , V_165 = 0 ;
T_2 V_166 = V_72 -> V_167 ;
T_2 V_168 = V_72 -> V_169 ;
T_2 V_170 = V_72 -> V_171 - V_72 -> V_172 ;
T_2 V_173 = V_72 -> V_174 - V_72 -> V_175 ;
T_2 V_176 = V_166 - V_72 -> V_172 ;
T_2 V_177 = V_176 + V_72 -> V_178 ;
T_2 va_start = V_168 - V_72 -> V_175 ;
T_2 va_end = va_start + V_72 -> V_179 ;
T_2 V_180 ;
F_17 ( L_9 ) ;
if ( V_19 -> V_95 & V_113 ) {
F_6 ( V_19 , V_181 ,
F_72 ( V_176 ) |
F_73 ( V_177 ) ) ;
F_6 ( V_19 , V_182 ,
F_74 ( va_start ) |
F_75 ( va_end ) ) ;
F_6 ( V_19 , V_183 ,
F_76 ( V_166 - 1 ) |
F_77 ( V_168 - 1 ) ) ;
F_6 ( V_19 , V_184 ,
F_78 ( V_164 ) |
F_79 ( V_170 ) ) ;
F_6 ( V_19 , V_185 , 0 ) ;
F_6 ( V_19 , V_186 ,
F_80 ( V_165 ) |
F_81 ( V_173 ) ) ;
} else {
V_180 = V_72 -> V_178 * F_4 ( V_19 -> V_83 ) / 8 + 1 ;
F_6 ( V_19 , V_187 ,
F_82 ( V_180 ) |
F_83 (
V_19 -> V_124 ) |
F_84 (
V_188 ) ) ;
F_6 ( V_19 , V_189 ,
F_85 ( V_72 -> V_178 ) |
F_86 ( V_72 -> V_179 ) ) ;
}
}
static void F_87 ( struct V_18 * V_19 )
{
F_6 ( V_19 , V_154 , V_155 ) ;
F_88 () ;
F_6 ( V_19 , V_190 , 1 ) ;
F_88 () ;
F_6 ( V_19 , V_190 , 0 ) ;
}
static void F_89 ( struct V_18 * V_19 ,
bool V_191 , bool V_89 )
{
T_2 V_192 ;
V_192 = F_5 ( V_19 , V_112 ) ;
if ( ! V_89 ) {
V_192 &= ~ ( V_163 | V_193 |
V_194 ) ;
F_50 ( V_19 , V_195 |
V_196 , 0 ) ;
} else {
if ( V_191 ) {
V_192 |= V_193 ;
} else {
V_192 |= V_194 ;
F_50 ( V_19 , V_195 , 1 ) ;
}
V_192 |= V_163 ;
}
F_6 ( V_19 , V_112 , V_192 ) ;
}
static void F_90 ( int V_72 , struct V_18 * V_19 )
{
T_2 V_22 ;
V_22 = F_5 ( V_19 , V_133 ) ;
if ( V_72 == 0 )
V_22 &= ~ V_135 ;
else
V_22 |= V_135 ;
F_6 ( V_19 , V_133 , V_22 ) ;
}
static void F_91 ( struct V_18 * V_19 )
{
F_50 ( V_19 , V_196 , 1 ) ;
F_92 ( & V_19 -> V_197 ) ;
F_93 ( & V_19 -> V_197 ,
F_94 ( 70 ) ) ;
F_50 ( V_19 , V_196 , 0 ) ;
}
static void F_95 ( struct V_18 * V_19 )
{
if ( ! ( V_19 -> V_95 & V_113 ) )
return;
if ( V_19 -> V_198 ) {
F_91 ( V_19 ) ;
F_96 ( 2000 , 4000 ) ;
}
}
static int F_97 ( struct V_18 * V_19 , int V_199 )
{
struct V_200 * V_26 = V_19 -> V_26 ;
struct V_201 * V_202 = V_26 -> V_203 ;
const struct V_23 * V_24 = V_19 -> V_24 ;
int V_32 ;
T_4 V_204 ;
if ( V_24 -> V_2 == V_10 ) {
V_19 -> V_205 = F_98 ( V_26 , V_199 , V_206 ) ;
if ( F_10 ( V_19 -> V_205 ) ) {
V_32 = F_34 ( V_19 -> V_205 ) ;
F_11 ( L_44 ,
V_33 , V_32 ) ;
V_19 -> V_205 = NULL ;
return V_32 ;
}
V_32 = F_99 ( V_19 -> V_205 ,
V_202 -> V_207 -> V_208 , & V_204 ) ;
F_100 ( & V_26 -> V_209 ) ;
if ( V_32 ) {
F_11 ( L_45 , V_33 , V_32 ) ;
return V_32 ;
}
if ( V_204 & 0x07 ) {
F_11 ( L_46 , V_33 ) ;
return - V_5 ;
}
V_19 -> V_210 = V_19 -> V_205 -> V_199 ;
} else {
V_19 -> V_211 = F_101 ( V_26 -> V_26 , V_199 ,
& V_19 -> V_212 , V_213 ) ;
if ( ! V_19 -> V_211 ) {
V_32 = - V_214 ;
F_11 ( L_47 ,
V_33 , V_32 ) ;
return V_32 ;
}
V_19 -> V_210 = V_199 ;
}
return 0 ;
}
static void F_102 ( struct V_18 * V_19 )
{
struct V_200 * V_26 = V_19 -> V_26 ;
if ( V_19 -> V_205 ) {
F_103 ( V_19 -> V_205 , 0 ) ;
F_104 ( & V_26 -> V_209 ) ;
F_105 ( V_19 -> V_205 ) ;
V_19 -> V_205 = NULL ;
F_100 ( & V_26 -> V_209 ) ;
}
if ( V_19 -> V_211 )
F_106 ( V_26 -> V_26 , V_19 -> V_210 , V_19 -> V_211 ,
V_19 -> V_212 ) ;
}
static int F_107 ( struct V_18 * V_19 ,
const struct V_215 * V_216 )
{
const struct V_23 * V_24 = V_19 -> V_24 ;
struct V_217 V_218 ;
int V_219 ;
int V_32 ;
T_3 * V_22 ;
V_32 = F_108 ( & V_218 , V_216 ) ;
if ( V_32 ) {
F_11 ( L_48 , V_33 , V_32 ) ;
return V_32 ;
}
V_219 = ( V_218 . V_199 + 3 ) & ( ~ 0x3 ) ;
if ( V_219 > V_19 -> V_210 ) {
F_11 ( L_49 , V_33 ) ;
return - V_5 ;
}
if ( V_24 -> V_2 == V_10 ) {
V_22 = F_109 ( V_19 -> V_205 ) ;
if ( F_10 ( V_22 ) ) {
V_32 = F_34 ( V_22 ) ;
F_11 ( L_50 , V_33 , V_32 ) ;
return V_32 ;
}
} else {
V_22 = V_19 -> V_211 ;
}
V_22 [ 0 ] = V_218 . V_220 [ 1 ] ;
V_22 [ 1 ] = V_218 . V_220 [ 2 ] ;
V_22 [ 2 ] = V_218 . V_220 [ 0 ] ;
V_22 [ 3 ] = F_110 ( 7 ) ;
if ( F_111 ( V_216 -> type ) )
V_22 [ 3 ] |= F_110 ( 6 ) ;
if ( V_216 -> V_221 && V_216 -> V_222 )
V_22 [ 3 ] |= F_110 ( 5 ) ;
if ( V_218 . V_223 && V_218 . V_224 )
memcpy ( V_22 + 4 , V_218 . V_223 , V_218 . V_224 ) ;
if ( V_218 . V_199 < V_219 )
memset ( V_22 + V_218 . V_199 , 0xff , V_219 - V_218 . V_199 ) ;
if ( V_24 -> V_2 == V_10 )
F_112 ( V_19 -> V_205 ) ;
return V_219 ;
}
static int F_113 ( T_3 * V_225 , const struct V_215 * V_216 )
{
T_3 * V_22 = V_216 -> V_221 ;
if ( V_22 && ( V_216 -> V_222 >= 1 ) ) {
* V_22 = V_225 [ 1 ] ;
return 1 ;
} else {
F_11 ( L_51 ,
V_33 , V_216 -> V_222 ) ;
return - V_5 ;
}
}
static int F_114 ( T_3 * V_225 , const struct V_215 * V_216 )
{
T_3 * V_22 = V_216 -> V_221 ;
if ( V_22 && ( V_216 -> V_222 >= 2 ) ) {
V_22 [ 0 ] = V_225 [ 1 ] ;
V_22 [ 1 ] = V_225 [ 2 ] ;
return 2 ;
} else {
F_11 ( L_51 ,
V_33 , V_216 -> V_222 ) ;
return - V_5 ;
}
}
static int F_115 ( T_3 * V_225 , const struct V_215 * V_216 )
{
if ( V_216 -> V_221 && V_216 -> V_222 )
memcpy ( V_216 -> V_221 , V_225 + 4 , V_216 -> V_222 ) ;
return V_216 -> V_222 ;
}
static int F_116 ( struct V_18 * V_19 , int V_219 )
{
const struct V_23 * V_24 = V_19 -> V_24 ;
struct V_200 * V_26 = V_19 -> V_26 ;
struct V_201 * V_202 = V_26 -> V_203 ;
int V_32 ;
T_4 V_226 ;
bool V_227 ;
if ( V_24 -> V_2 == V_10 ) {
V_32 = F_99 ( V_19 -> V_205 ,
V_202 -> V_207 -> V_208 , & V_226 ) ;
if ( V_32 ) {
F_11 ( L_52 , V_33 , V_32 ) ;
return V_32 ;
}
} else {
V_226 = V_19 -> V_212 ;
}
F_92 ( & V_19 -> V_228 ) ;
F_95 ( V_19 ) ;
V_227 = F_117 (
V_19 -> V_68 , V_226 , V_219 ) ;
if ( V_227 ) {
V_32 = F_93 ( & V_19 -> V_228 ,
F_94 ( 200 ) ) ;
F_17 ( L_53 , V_32 ) ;
if ( V_32 == 0 )
V_32 = - V_229 ;
else
V_32 = V_219 ;
} else
V_32 = V_219 ;
return V_32 ;
}
static int F_118 ( struct V_18 * V_19 ,
T_3 * V_225 , int V_230 , int V_231 )
{
T_2 * V_232 , * V_233 , V_22 ;
int V_48 , V_234 = 0 , V_235 ;
T_2 V_236 ;
T_3 V_20 [ 16 ] ;
int V_237 = 0 ;
int V_238 = V_225 - V_19 -> V_221 ;
V_232 = ( T_2 * ) V_225 ;
V_233 = ( T_2 * ) V_20 ;
V_235 = ( V_230 + 3 ) >> 2 ;
if ( V_235 > 4 )
V_235 = 4 ;
if ( V_230 == 4 )
V_236 = 4 ;
else
V_236 = V_231 + 6 ;
if ( V_236 > 16 ) {
int V_239 ;
V_239 = V_236 - 16 ;
V_237 = V_238 - V_239 ;
}
for ( V_48 = V_235 - 1 ; V_48 >= 0 ; V_48 -- ) {
V_22 = F_5 ( V_19 , F_119 ( V_48 ) ) ;
* V_233 ++ = F_120 ( V_22 ) ;
F_17 ( L_54 , V_22 , F_120 ( V_22 ) ) ;
}
for ( V_48 = V_237 ; V_48 < 16 ; V_48 ++ )
V_225 [ V_234 ++ ] = V_20 [ V_48 ] ;
return V_234 ;
}
static int F_121 ( struct V_18 * V_19 ,
const struct V_215 * V_216 )
{
int V_219 , V_32 ;
int V_240 = V_19 -> V_72 -> V_178 *
F_4 ( V_19 -> V_83 ) / 8 ;
V_219 = F_107 ( V_19 , V_216 ) ;
if ( ! V_219 ) {
F_11 ( L_55 ,
V_33 , V_216 -> type ) ;
return - V_5 ;
}
if ( ( V_19 -> V_95 & V_113 ) && ( V_219 > V_240 ) ) {
F_11 ( L_56 ,
V_33 , V_219 ) ;
return - V_5 ;
}
V_32 = F_116 ( V_19 , V_219 ) ;
if ( V_32 < V_219 ) {
F_11 ( L_57 ,
V_33 , V_216 -> type , ( * ( T_3 * ) ( V_216 -> V_211 ) ) , V_219 ) ;
return - V_241 ;
}
return V_219 ;
}
static void F_122 ( struct V_18 * V_19 )
{
T_2 V_242 , V_243 ;
V_242 = F_5 ( V_19 , V_112 ) ;
V_243 = V_242 ;
V_243 &= ~ V_163 ;
F_6 ( V_19 , V_112 , V_243 ) ;
F_88 () ;
F_6 ( V_19 , V_154 , V_155 ) ;
F_88 () ;
F_6 ( V_19 , V_190 , 1 ) ;
F_88 () ;
F_6 ( V_19 , V_190 , 0 ) ;
F_88 () ;
F_6 ( V_19 , V_112 , V_242 ) ;
F_88 () ;
}
static void F_123 ( struct V_244 * V_245 )
{
struct V_18 * V_19 =
F_24 ( V_245 , struct V_18 , V_246 ) ;
F_124 ( V_19 -> V_26 ) ;
}
static void F_125 ( struct V_244 * V_245 )
{
struct V_18 * V_19 =
F_24 ( V_245 , struct V_18 , V_247 ) ;
T_2 V_248 = V_19 -> V_249 ;
F_126 ( L_58 , V_33 , V_248 ) ;
if ( V_248 & V_250 )
F_122 ( V_19 ) ;
V_19 -> V_249 = 0 ;
F_50 ( V_19 , V_153 , 1 ) ;
}
static void F_127 ( struct V_18 * V_19 )
{
T_2 V_248 ;
V_248 = F_5 ( V_19 , V_251 ) ;
if ( V_248 ) {
F_6 ( V_19 , V_251 , V_248 ) ;
F_6 ( V_19 , V_251 , 0 ) ;
V_19 -> V_249 |= V_252 ;
}
}
static void F_128 ( struct V_18 * V_19 )
{
T_2 V_248 ;
V_248 = F_5 ( V_19 , V_253 ) ;
if ( V_248 ) {
F_6 ( V_19 , V_253 , V_248 ) ;
V_19 -> V_249 |= V_254 ;
}
}
static void F_129 ( struct V_18 * V_19 )
{
T_2 V_248 ;
V_248 = F_5 ( V_19 , V_255 ) ;
if ( V_248 & ( V_256 |
V_257 |
V_258 |
V_259 |
V_260 ) ) {
F_6 ( V_19 , V_255 , V_248 ) ;
V_19 -> V_249 |= V_261 ;
}
}
static void F_130 ( struct V_18 * V_19 )
{
T_2 V_248 ;
V_248 = F_5 ( V_19 , V_262 ) ;
if ( V_248 ) {
F_6 ( V_19 , V_262 , V_248 ) ;
V_19 -> V_249 |= V_263 ;
if ( V_248 & V_264 )
V_19 -> V_249 |=
V_250 ;
}
}
static void F_131 ( struct V_18 * V_19 )
{
T_2 V_248 ;
V_248 = F_5 ( V_19 , V_265 ) ;
if ( V_248 & V_266 ) {
F_6 ( V_19 , V_265 , V_248 ) ;
V_19 -> V_249 |=
V_267 ;
}
}
static void F_132 ( struct V_18 * V_19 )
{
T_2 V_248 ;
V_248 = F_5 ( V_19 , V_268 ) ;
if ( V_248 & V_269 ) {
F_6 ( V_19 , V_268 , V_248 ) ;
V_19 -> V_249 |= V_270 ;
}
}
static void F_133 ( struct V_18 * V_19 )
{
F_50 ( V_19 , V_153 , 0 ) ;
F_132 ( V_19 ) ;
F_130 ( V_19 ) ;
F_127 ( V_19 ) ;
F_128 ( V_19 ) ;
F_131 ( V_19 ) ;
F_129 ( V_19 ) ;
F_134 ( V_19 -> V_271 , & V_19 -> V_247 ) ;
}
static T_5 F_135 ( int V_272 , void * V_273 )
{
struct V_18 * V_19 = V_273 ;
T_2 V_274 ;
unsigned long V_91 ;
if ( ! V_19 -> V_21 )
return V_275 ;
F_51 ( & V_19 -> V_92 , V_91 ) ;
V_274 = F_5 ( V_19 , V_93 ) ;
F_6 ( V_19 , V_93 , V_274 ) ;
F_52 ( & V_19 -> V_92 , V_91 ) ;
F_17 ( L_59 , V_274 , V_19 -> V_68 ) ;
if ( V_274 & V_276 )
F_133 ( V_19 ) ;
if ( V_274 & V_277 )
F_136 ( & V_19 -> V_197 ) ;
if ( V_274 & V_278 )
F_136 ( & V_19 -> V_228 ) ;
return V_275 ;
}
static int F_137 ( struct V_18 * V_19 ,
struct V_25 * V_279 )
{
V_19 -> V_280 = F_138 ( V_279 ,
L_60 ,
V_281 ) ;
if ( F_10 ( V_19 -> V_280 ) ) {
F_17 ( L_61 ,
F_34 ( V_19 -> V_280 ) ) ;
return F_34 ( V_19 -> V_280 ) ;
}
V_19 -> V_282 = F_138 ( V_279 , L_62 ,
V_283 ) ;
if ( F_10 ( V_19 -> V_282 ) ) {
F_17 ( L_63 , F_34 ( V_19 -> V_282 ) ) ;
return F_34 ( V_19 -> V_282 ) ;
}
return 0 ;
}
static int F_139 ( struct V_38 * V_39 ,
struct V_284 * V_285 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
int V_32 ;
if ( V_285 -> V_81 > V_19 -> V_286 )
return - V_5 ;
V_19 -> V_124 = V_285 -> V_124 ;
V_19 -> V_81 = V_285 -> V_81 ;
V_19 -> V_83 = V_285 -> V_83 ;
V_19 -> V_95 = V_285 -> V_95 ;
F_140 ( V_19 -> V_68 , V_285 -> V_95 ) ;
V_32 = F_137 ( V_19 , & V_285 -> V_26 ) ;
if ( V_32 )
return V_32 ;
F_17 ( L_26 , V_19 -> V_68 ) ;
if ( V_19 -> V_26 )
F_134 ( V_19 -> V_271 , & V_19 -> V_246 ) ;
return 0 ;
}
static int F_141 ( struct V_38 * V_39 ,
struct V_284 * V_285 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
V_19 -> V_287 = NULL ;
F_17 ( L_26 , V_19 -> V_68 ) ;
if ( V_19 -> V_26 )
F_134 ( V_19 -> V_271 , & V_19 -> V_246 ) ;
return 0 ;
}
static T_6 F_142 ( struct V_38 * V_39 ,
const struct V_215 * V_216 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
int V_32 ;
if ( ! V_216 || ! V_19 -> V_198 )
return - V_5 ;
F_104 ( & V_19 -> V_288 ) ;
V_32 = F_143 ( V_19 -> V_68 , V_216 ) ;
F_100 ( & V_19 -> V_288 ) ;
return V_32 ;
}
static int F_144 ( struct V_18 * V_19 ,
struct V_287 * V_289 )
{
struct V_25 * V_26 = & V_19 -> V_27 -> V_26 ;
struct V_290 * V_291 ;
T_2 V_292 [ 4 ] ;
int V_32 , V_48 , V_219 , V_293 ;
V_291 = F_145 ( V_289 , L_64 , & V_219 ) ;
if ( ! V_291 ) {
F_146 ( V_26 ,
L_65 ) ;
return 0 ;
}
V_293 = V_219 / sizeof( T_2 ) ;
if ( V_293 < 1 || V_293 > 4 ) {
F_147 ( V_26 , L_66 ) ;
return - V_5 ;
}
V_19 -> V_286 = V_293 ;
V_32 = F_148 ( V_289 , L_64 , V_292 ,
V_293 ) ;
if ( V_32 ) {
F_147 ( V_26 , L_67 ) ;
return V_32 ;
}
for ( V_48 = 0 ; V_48 < F_149 ( V_294 ) ; V_48 ++ ) {
const int * V_295 = V_294 [ V_48 ] ;
int V_234 ;
for ( V_234 = 0 ; V_234 < V_293 ; V_234 ++ ) {
if ( V_292 [ V_234 ] < 0 || V_292 [ V_234 ] > 3 )
F_147 ( V_26 , L_68 ,
V_292 [ V_234 ] ) ;
if ( V_295 [ V_292 [ V_234 ] ] != V_234 )
break;
}
if ( V_234 == V_293 ) {
V_19 -> V_159 = V_48 ;
return 0 ;
}
}
return - V_5 ;
}
static int F_150 ( struct V_18 * V_19 )
{
struct V_25 * V_26 = & V_19 -> V_27 -> V_26 ;
struct V_287 * V_296 = V_26 -> V_297 ;
struct V_287 * V_298 , * V_287 ;
int V_32 = 0 ;
V_298 = F_151 ( V_296 , 1 , - 1 ) ;
if ( ! V_298 ) {
F_146 ( V_26 , L_69 , V_33 ) ;
return 0 ;
}
V_32 = F_144 ( V_19 , V_298 ) ;
if ( V_32 ) {
F_147 ( V_26 , L_70 ,
V_33 , V_32 ) ;
goto V_69;
}
V_287 = F_152 ( V_296 , 1 , 0 ) ;
if ( ! V_287 ) {
F_146 ( V_26 , L_71 , V_33 ) ;
goto V_69;
}
V_19 -> V_287 = V_287 ;
if ( F_153 ( V_296 , L_72 ) ) {
V_19 -> V_299 = F_154 ( V_296 ,
L_72 ) ;
if ( F_10 ( V_19 -> V_299 ) ) {
F_147 ( V_26 , L_73 ,
V_33 ) ;
V_32 = F_34 ( V_19 -> V_299 ) ;
}
}
F_155 ( V_287 ) ;
V_69:
F_155 ( V_298 ) ;
return V_32 ;
}
static int F_156 ( struct V_18 * V_19 )
{
struct V_70 * V_27 = V_19 -> V_27 ;
const struct V_55 * V_45 = V_19 -> V_24 -> V_45 ;
struct V_300 * V_301 ;
int V_48 ;
V_301 = F_157 ( V_27 , V_302 , L_74 ) ;
if ( ! V_301 )
return - V_5 ;
for ( V_48 = 0 ; V_48 < V_45 -> V_303 ; V_48 ++ ) {
if ( V_45 -> V_304 [ V_48 ] == V_301 -> V_305 )
return V_48 ;
}
return - V_5 ;
}
int F_158 ( struct V_71 * V_71 )
{
struct V_18 * V_19 = NULL ;
struct V_70 * V_27 = V_71 -> V_27 ;
int V_32 ;
V_19 = F_159 ( & V_27 -> V_26 , sizeof( * V_19 ) , V_213 ) ;
if ( ! V_19 ) {
F_11 ( L_75 ,
V_33 ) ;
V_32 = - V_214 ;
goto V_52;
}
V_19 -> V_27 = V_27 ;
V_71 -> V_39 = & V_19 -> V_1 ;
V_32 = F_150 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_76 , V_33 ) ;
goto V_52;
}
V_19 -> V_21 = F_160 ( V_27 , L_74 , L_77 ) ;
if ( F_10 ( V_19 -> V_21 ) ) {
F_11 ( L_78 , V_33 ) ;
V_32 = F_34 ( V_19 -> V_21 ) ;
goto V_52;
}
F_161 ( & V_27 -> V_26 ) ;
V_19 -> V_24 = F_8 ( V_19 ) ;
if ( ! V_19 -> V_24 ) {
V_32 = - V_5 ;
F_11 ( L_79 , V_33 ) ;
goto V_52;
}
V_19 -> V_68 = F_156 ( V_19 ) ;
if ( V_19 -> V_68 < 0 ) {
V_32 = V_19 -> V_68 ;
F_11 ( L_80 , V_33 ) ;
goto V_52;
}
V_19 -> V_21 += V_19 -> V_24 -> V_45 -> V_306 ;
V_32 = F_30 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_81 , V_33 ) ;
goto V_52;
}
V_32 = F_32 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_82 , V_33 ) ;
goto V_52;
}
V_19 -> V_221 = F_159 ( & V_27 -> V_26 , V_307 , V_213 ) ;
if ( ! V_19 -> V_221 ) {
V_32 = - V_214 ;
F_11 ( L_83 , V_33 ) ;
goto V_52;
}
F_162 ( & V_19 -> V_228 ) ;
F_162 ( & V_19 -> V_197 ) ;
F_163 ( & V_19 -> V_308 ) ;
F_163 ( & V_19 -> V_288 ) ;
F_164 ( & V_19 -> V_92 ) ;
V_19 -> V_271 = F_165 ( L_84 , 0 ) ;
F_166 ( & V_19 -> V_247 , F_125 ) ;
F_166 ( & V_19 -> V_246 , F_123 ) ;
V_71 -> V_68 = V_19 -> V_68 ;
F_17 ( L_85 , V_19 -> V_68 ) ;
return 0 ;
V_52:
return V_32 ;
}
void F_167 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
F_17 ( L_9 ) ;
F_102 ( V_19 ) ;
if ( V_19 -> V_271 ) {
F_168 ( V_19 -> V_271 ) ;
F_169 ( V_19 -> V_271 ) ;
V_19 -> V_271 = NULL ;
}
F_170 ( & V_19 -> V_288 ) ;
F_170 ( & V_19 -> V_308 ) ;
F_171 ( & V_19 -> V_27 -> V_26 ) ;
}
int F_172 ( struct V_38 * V_39 ,
struct V_200 * V_26 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
struct V_70 * V_27 = V_19 -> V_27 ;
int V_32 ;
V_19 -> V_272 = F_173 ( V_27 -> V_26 . V_297 , 0 ) ;
if ( V_19 -> V_272 < 0 ) {
V_32 = V_19 -> V_272 ;
F_147 ( V_26 -> V_26 , L_86 , V_32 ) ;
return V_32 ;
}
V_32 = F_174 ( & V_27 -> V_26 , V_19 -> V_272 ,
F_135 , V_309 | V_310 ,
L_87 , V_19 ) ;
if ( V_32 < 0 ) {
F_147 ( & V_27 -> V_26 , L_88 ,
V_19 -> V_272 , V_32 ) ;
return V_32 ;
}
V_19 -> V_26 = V_26 ;
V_32 = F_97 ( V_19 , V_307 ) ;
if ( V_32 ) {
F_11 ( L_89 , V_33 , V_32 ) ;
return V_32 ;
}
return 0 ;
}
int F_175 ( struct V_38 * V_39 , bool V_311 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
int V_32 ;
if ( ! V_19 -> V_312 ) {
V_39 -> V_26 = & V_19 -> V_27 -> V_26 ;
V_39 -> V_313 = & V_314 ;
V_32 = F_176 ( V_39 ) ;
if ( V_32 )
return V_32 ;
V_19 -> V_312 = true ;
if ( V_311 && V_19 -> V_287 ) {
if ( ! F_177 ( V_19 -> V_287 ) )
if ( ! F_178 ( V_19 -> V_287 ) )
return - V_315 ;
}
}
return 0 ;
}
void F_179 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
if ( V_19 -> V_312 ) {
F_180 ( V_39 ) ;
V_39 -> V_26 = NULL ;
V_39 -> V_313 = NULL ;
V_19 -> V_312 = false ;
}
}
int F_181 ( struct V_38 * V_39 ,
const struct V_215 * V_216 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
F_13 ( & V_19 -> V_27 -> V_26 ) ;
F_45 ( V_19 ) ;
if ( ! ( V_216 -> V_91 & V_316 ) )
F_90 ( 0 , V_19 ) ;
V_19 -> V_317 = F_5 ( V_19 , V_112 ) ;
F_6 ( V_19 , V_112 ,
V_19 -> V_317 |
V_194 |
V_163 ) ;
F_50 ( V_19 , V_318 , 1 ) ;
return 0 ;
}
void F_182 ( struct V_38 * V_39 ,
const struct V_215 * V_216 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
F_50 ( V_19 , V_318 , 0 ) ;
F_6 ( V_19 , V_112 , V_19 -> V_317 ) ;
if ( ! ( V_216 -> V_91 & V_316 ) )
F_90 ( 1 , V_19 ) ;
F_46 ( V_19 ) ;
F_183 ( & V_19 -> V_27 -> V_26 ) ;
}
int F_184 ( struct V_38 * V_39 ,
const struct V_215 * V_216 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
return F_121 ( V_19 , V_216 ) ;
}
int F_185 ( struct V_38 * V_39 ,
const struct V_215 * V_216 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
const struct V_23 * V_24 = V_19 -> V_24 ;
int V_319 , V_230 , V_320 , V_321 ;
int V_322 , V_323 , V_231 , V_32 = 0 ;
char V_324 ;
int V_325 = V_216 -> V_222 ;
T_3 * V_225 ;
if ( V_325 <= 2 ) {
V_322 = 1 ;
V_231 = V_325 ;
V_230 = 4 ;
} else {
V_322 = 0 ;
V_319 = 10 ;
if ( V_325 < V_319 )
V_231 = V_325 ;
else
V_231 = V_319 ;
V_230 = V_319 + 6 ;
}
V_225 = V_19 -> V_221 ;
V_321 = 0 ;
while ( ! V_321 ) {
T_3 V_326 [ 2 ] = { V_231 & 0xff , V_231 >> 8 } ;
struct V_215 V_327 = {
. V_124 = V_216 -> V_124 ,
. type = V_328 ,
. V_329 = 2 ,
. V_211 = V_326 ,
} ;
F_17 ( L_90 ,
V_325 , V_231 , V_230 ) ;
V_32 = F_121 ( V_19 , & V_327 ) ;
if ( V_32 < 2 ) {
F_11 ( L_91 ,
V_33 , V_32 ) ;
return - V_5 ;
}
if ( ( V_24 -> V_2 == V_10 ) &&
( V_24 -> V_3 >= V_330 ) ) {
F_6 ( V_19 , V_331 ,
V_332 ) ;
F_88 () ;
F_6 ( V_19 , V_331 , 0 ) ;
F_88 () ;
}
V_32 = F_121 ( V_19 , V_216 ) ;
if ( V_32 < V_216 -> V_329 ) {
F_11 ( L_92 , V_33 , V_32 ) ;
return V_32 ;
}
V_320 = F_118 ( V_19 , V_225 , V_230 , V_231 ) ;
if ( V_320 <= 0 )
return 0 ;
if ( V_322 )
break;
if ( V_325 <= V_319 ) {
V_323 = V_319 - V_325 ;
V_321 = 1 ;
} else {
V_323 = 0 ;
V_325 -= V_319 ;
}
if ( ! V_321 ) {
V_320 -= 2 ;
V_320 -= V_323 ;
V_225 += V_320 ;
V_319 = 14 ;
if ( V_325 < V_319 )
V_231 += V_325 ;
else
V_231 += V_319 ;
F_17 ( L_93 , V_225 , V_320 , V_323 ) ;
}
}
if ( V_231 < 10 && ! V_322 )
V_225 = V_19 -> V_221 + ( 10 - V_325 ) ;
else
V_225 = V_19 -> V_221 ;
V_324 = V_225 [ 0 ] ;
switch ( V_324 ) {
case V_333 :
F_11 ( L_94 , V_33 ) ;
V_32 = 0 ;
break;
case V_334 :
case V_335 :
V_32 = F_113 ( V_225 , V_216 ) ;
break;
case V_336 :
case V_337 :
V_32 = F_114 ( V_225 , V_216 ) ;
break;
case V_338 :
case V_339 :
V_32 = F_115 ( V_225 , V_216 ) ;
break;
default:
F_186 ( L_95 , V_33 ) ;
V_32 = 0 ;
}
return V_32 ;
}
void F_187 ( struct V_38 * V_39 , T_2 V_226 ,
T_2 V_219 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
F_6 ( V_19 , V_340 , V_226 ) ;
F_6 ( V_19 , V_341 , V_219 ) ;
F_6 ( V_19 , V_342 , 1 ) ;
F_88 () ;
}
int F_188 ( struct V_38 * V_39 ,
struct V_343 * V_344 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
const struct V_23 * V_24 = V_19 -> V_24 ;
struct V_30 * V_345 , * V_346 ;
int V_32 ;
V_32 = F_189 ( V_344 ,
& V_345 , & V_346 ) ;
if ( V_32 ) {
F_190 ( L_96 ,
V_33 ) ;
return 0 ;
}
V_32 = F_191 ( V_19 -> V_62 , V_345 ) ;
if ( V_32 ) {
F_11 ( L_97 ,
V_33 , V_32 ) ;
goto exit;
}
V_32 = F_191 ( V_19 -> V_64 , V_346 ) ;
if ( V_32 ) {
F_11 ( L_98 ,
V_33 , V_32 ) ;
goto exit;
}
if ( V_24 -> V_2 == V_8 ) {
V_32 = F_191 ( V_19 -> V_67 , V_346 ) ;
if ( V_32 ) {
F_11 ( L_99 ,
V_33 , V_32 ) ;
goto exit;
}
V_32 = F_191 ( V_19 -> V_66 , V_345 ) ;
if ( V_32 ) {
F_11 ( L_100 ,
V_33 , V_32 ) ;
goto exit;
}
}
exit:
return V_32 ;
}
void F_192 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
F_17 ( L_9 ) ;
F_6 ( V_19 , V_347 , V_348 ) ;
F_88 () ;
F_193 ( 1000 ) ;
F_6 ( V_19 , V_347 , 0 ) ;
F_193 ( 100 ) ;
}
void F_194 ( struct V_38 * V_39 ,
struct V_349 * V_350 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
int V_32 ;
V_32 = F_47 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_101 , V_33 , V_32 ) ;
return;
}
V_350 -> V_351 = V_19 -> V_73 * 8 ;
V_350 -> V_352 = V_19 -> V_76 ;
}
int F_195 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
F_89 ( V_19 ,
! ! ( V_19 -> V_95 & V_113 ) , true ) ;
return 0 ;
}
int F_196 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
F_89 ( V_19 ,
! ! ( V_19 -> V_95 & V_113 ) , false ) ;
F_87 ( V_19 ) ;
return 0 ;
}
static void F_197 ( struct V_18 * V_19 , bool V_89 )
{
enum V_353 V_354 ;
if ( ! V_19 -> V_299 )
return;
V_354 = V_89 ? V_355 : V_356 ;
F_198 ( V_19 -> V_299 , V_357 ,
V_358 ,
F_199 ( V_354 ) ) ;
}
int F_200 ( struct V_38 * V_39 ,
struct V_110 * V_111 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
int V_32 = 0 ;
F_104 ( & V_19 -> V_308 ) ;
if ( V_19 -> V_198 ) {
F_17 ( L_102 ) ;
goto V_359;
}
F_197 ( V_19 , true ) ;
V_32 = F_28 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_103 ,
V_33 , V_32 ) ;
goto V_359;
}
F_13 ( & V_19 -> V_27 -> V_26 ) ;
V_32 = F_45 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_104 ,
V_33 , V_32 ) ;
goto V_360;
}
V_32 = F_201 ( & V_19 -> V_27 -> V_26 ) ;
if ( V_32 ) {
F_11 ( L_105 ,
V_33 , V_32 ) ;
goto V_361;
}
F_71 ( V_19 ) ;
F_87 ( V_19 ) ;
F_56 ( V_19 , true , V_111 ) ;
if ( V_19 -> V_280 )
F_202 ( V_19 -> V_280 , 1 ) ;
V_19 -> V_198 = true ;
F_100 ( & V_19 -> V_308 ) ;
return 0 ;
V_361:
F_46 ( V_19 ) ;
F_183 ( & V_19 -> V_27 -> V_26 ) ;
V_360:
F_25 ( V_19 ) ;
V_359:
F_100 ( & V_19 -> V_308 ) ;
return V_32 ;
}
int F_203 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
F_104 ( & V_19 -> V_308 ) ;
if ( ! V_19 -> V_198 ) {
F_17 ( L_106 ) ;
goto V_359;
}
F_56 ( V_19 , false , NULL ) ;
if ( V_19 -> V_280 )
F_202 ( V_19 -> V_280 , 0 ) ;
F_204 ( & V_19 -> V_27 -> V_26 ) ;
F_46 ( V_19 ) ;
F_183 ( & V_19 -> V_27 -> V_26 ) ;
F_25 ( V_19 ) ;
F_197 ( V_19 , false ) ;
F_17 ( L_107 ) ;
V_19 -> V_198 = false ;
V_359:
F_100 ( & V_19 -> V_308 ) ;
return 0 ;
}
int F_205 ( struct V_38 * V_39 ,
struct V_80 * V_72 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
if ( V_19 -> V_72 ) {
F_206 ( V_19 -> V_26 , V_19 -> V_72 ) ;
V_19 -> V_72 = NULL ;
}
V_19 -> V_72 = F_207 ( V_19 -> V_26 , V_72 ) ;
if ( ! V_19 -> V_72 ) {
F_11 ( L_108 , V_33 ) ;
return - V_214 ;
}
return 0 ;
}
struct V_362 * F_208 ( struct V_38 * V_39 ,
unsigned long * V_363 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
struct V_362 * V_364 ;
V_364 = F_177 ( V_19 -> V_287 ) ;
if ( V_363 )
* V_363 = V_19 -> V_95 ;
return V_364 ;
}
struct V_365 * F_209 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_23 ( V_39 ) ;
return F_178 ( V_19 -> V_287 ) ;
}
