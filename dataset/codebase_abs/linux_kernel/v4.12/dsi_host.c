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
V_32 = F_13 ( V_29 ) ;
if ( V_32 ) {
F_11 ( L_5 , V_33 ) ;
goto V_35;
}
V_32 = F_14 ( V_31 ) ;
if ( V_32 ) {
F_11 ( L_6 , V_33 ) ;
goto V_36;
}
V_32 = F_1 ( V_19 -> V_21 , & V_2 , & V_3 ) ;
if ( V_32 ) {
F_11 ( L_7 , V_33 ) ;
goto V_37;
}
V_24 = F_15 ( V_2 , V_3 ) ;
F_16 ( L_8 , V_33 , V_2 , V_3 ) ;
V_37:
F_17 ( V_31 ) ;
V_36:
F_18 ( V_29 ) ;
V_35:
F_19 ( V_31 ) ;
V_34:
F_20 ( V_29 ) ;
exit:
return V_24 ;
}
static inline struct V_18 * F_21 ( struct V_38 * V_39 )
{
return F_22 ( V_39 , struct V_18 , V_1 ) ;
}
static void F_23 ( struct V_18 * V_19 )
{
struct V_40 * V_41 = V_19 -> V_42 ;
const struct V_43 * V_44 = V_19 -> V_24 -> V_45 -> V_46 . V_44 ;
int V_47 = V_19 -> V_24 -> V_45 -> V_46 . V_47 ;
int V_48 ;
F_16 ( L_9 ) ;
for ( V_48 = V_47 - 1 ; V_48 >= 0 ; V_48 -- )
if ( V_44 [ V_48 ] . V_49 >= 0 )
F_24 ( V_41 [ V_48 ] . V_50 ,
V_44 [ V_48 ] . V_49 ) ;
F_25 ( V_47 , V_41 ) ;
}
static int F_26 ( struct V_18 * V_19 )
{
struct V_40 * V_41 = V_19 -> V_42 ;
const struct V_43 * V_44 = V_19 -> V_24 -> V_45 -> V_46 . V_44 ;
int V_47 = V_19 -> V_24 -> V_45 -> V_46 . V_47 ;
int V_32 , V_48 ;
F_16 ( L_9 ) ;
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ ) {
if ( V_44 [ V_48 ] . V_51 >= 0 ) {
V_32 = F_24 ( V_41 [ V_48 ] . V_50 ,
V_44 [ V_48 ] . V_51 ) ;
if ( V_32 < 0 ) {
F_11 ( L_10 ,
V_48 , V_32 ) ;
goto V_52;
}
}
}
V_32 = F_27 ( V_47 , V_41 ) ;
if ( V_32 < 0 ) {
F_11 ( L_11 , V_32 ) ;
goto V_52;
}
return 0 ;
V_52:
for ( V_48 -- ; V_48 >= 0 ; V_48 -- )
F_24 ( V_41 [ V_48 ] . V_50 , V_44 [ V_48 ] . V_49 ) ;
return V_32 ;
}
static int F_28 ( struct V_18 * V_19 )
{
struct V_40 * V_41 = V_19 -> V_42 ;
const struct V_43 * V_44 = V_19 -> V_24 -> V_45 -> V_46 . V_44 ;
int V_47 = V_19 -> V_24 -> V_45 -> V_46 . V_47 ;
int V_48 , V_32 ;
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ )
V_41 [ V_48 ] . V_53 = V_44 [ V_48 ] . V_54 ;
V_32 = F_29 ( & V_19 -> V_27 -> V_26 , V_47 , V_41 ) ;
if ( V_32 < 0 ) {
F_11 ( L_12 ,
V_33 , V_32 ) ;
return V_32 ;
}
return 0 ;
}
static int F_30 ( struct V_18 * V_19 )
{
struct V_25 * V_26 = & V_19 -> V_27 -> V_26 ;
const struct V_23 * V_24 = V_19 -> V_24 ;
const struct V_55 * V_45 = V_24 -> V_45 ;
int V_48 , V_32 = 0 ;
for ( V_48 = 0 ; V_48 < V_45 -> V_56 ; V_48 ++ ) {
V_19 -> V_57 [ V_48 ] = F_31 ( V_26 ,
V_45 -> V_58 [ V_48 ] ) ;
if ( F_10 ( V_19 -> V_57 [ V_48 ] ) ) {
V_32 = F_32 ( V_19 -> V_57 [ V_48 ] ) ;
F_11 ( L_13 ,
V_33 , V_45 -> V_58 [ V_48 ] , V_32 ) ;
goto exit;
}
}
V_19 -> V_59 = F_31 ( V_26 , L_14 ) ;
if ( F_10 ( V_19 -> V_59 ) ) {
V_32 = F_32 ( V_19 -> V_59 ) ;
F_11 ( L_15 ,
V_33 , V_32 ) ;
V_19 -> V_59 = NULL ;
goto exit;
}
V_19 -> V_60 = F_31 ( V_26 , L_16 ) ;
if ( F_10 ( V_19 -> V_60 ) ) {
V_32 = F_32 ( V_19 -> V_60 ) ;
F_11 ( L_17 ,
V_33 , V_32 ) ;
V_19 -> V_60 = NULL ;
goto exit;
}
V_19 -> V_61 = F_31 ( V_26 , L_18 ) ;
if ( F_10 ( V_19 -> V_61 ) ) {
V_32 = F_32 ( V_19 -> V_61 ) ;
F_11 ( L_19 ,
V_33 , V_32 ) ;
V_19 -> V_61 = NULL ;
goto exit;
}
V_19 -> V_62 = F_33 ( V_19 -> V_59 ) ;
if ( ! V_19 -> V_62 ) {
V_32 = - V_63 ;
F_11 ( L_20 , V_33 , V_32 ) ;
goto exit;
}
V_19 -> V_64 = F_33 ( V_19 -> V_60 ) ;
if ( ! V_19 -> V_64 ) {
V_32 = - V_63 ;
F_11 ( L_21 , V_33 , V_32 ) ;
goto exit;
}
if ( V_24 -> V_2 == V_8 ) {
V_19 -> V_65 = F_31 ( V_26 , L_22 ) ;
if ( F_10 ( V_19 -> V_65 ) ) {
V_32 = F_32 ( V_19 -> V_65 ) ;
F_11 ( L_23 ,
V_33 , V_32 ) ;
V_19 -> V_65 = NULL ;
goto exit;
}
V_19 -> V_66 = F_33 ( V_19 -> V_61 ) ;
if ( ! V_19 -> V_66 ) {
V_32 = - V_63 ;
F_11 ( L_24 ,
V_33 , V_32 ) ;
goto exit;
}
V_19 -> V_67 = F_33 ( V_19 -> V_65 ) ;
if ( ! V_19 -> V_67 ) {
V_32 = - V_63 ;
F_11 ( L_25 ,
V_33 , V_32 ) ;
}
}
exit:
return V_32 ;
}
static int F_34 ( struct V_18 * V_19 )
{
const struct V_55 * V_45 = V_19 -> V_24 -> V_45 ;
int V_48 , V_32 ;
F_16 ( L_26 , V_19 -> V_68 ) ;
for ( V_48 = 0 ; V_48 < V_45 -> V_56 ; V_48 ++ ) {
V_32 = F_14 ( V_19 -> V_57 [ V_48 ] ) ;
if ( V_32 ) {
F_11 ( L_27 ,
V_33 , V_48 , V_32 ) ;
goto V_69;
}
}
return 0 ;
V_69:
for (; V_48 > 0 ; V_48 -- )
F_17 ( V_19 -> V_57 [ V_48 ] ) ;
return V_32 ;
}
static void F_35 ( struct V_18 * V_19 )
{
const struct V_55 * V_45 = V_19 -> V_24 -> V_45 ;
int V_48 ;
F_16 ( L_9 ) ;
for ( V_48 = V_45 -> V_56 - 1 ; V_48 >= 0 ; V_48 -- )
F_17 ( V_19 -> V_57 [ V_48 ] ) ;
}
static int F_36 ( struct V_18 * V_19 )
{
int V_32 ;
F_16 ( L_28 ,
V_19 -> V_70 -> clock , V_19 -> V_71 ) ;
V_32 = F_37 ( V_19 -> V_59 , V_19 -> V_71 ) ;
if ( V_32 ) {
F_11 ( L_29 , V_33 , V_32 ) ;
goto error;
}
V_32 = F_37 ( V_19 -> V_60 , V_19 -> V_70 -> clock * 1000 ) ;
if ( V_32 ) {
F_11 ( L_30 , V_33 , V_32 ) ;
goto error;
}
V_32 = F_14 ( V_19 -> V_61 ) ;
if ( V_32 ) {
F_11 ( L_31 , V_33 ) ;
goto error;
}
V_32 = F_14 ( V_19 -> V_59 ) ;
if ( V_32 ) {
F_11 ( L_32 , V_33 ) ;
goto V_72;
}
V_32 = F_14 ( V_19 -> V_60 ) ;
if ( V_32 ) {
F_11 ( L_33 , V_33 ) ;
goto V_73;
}
return 0 ;
V_73:
F_17 ( V_19 -> V_59 ) ;
V_72:
F_17 ( V_19 -> V_61 ) ;
error:
return V_32 ;
}
static int F_38 ( struct V_18 * V_19 )
{
int V_32 ;
F_16 ( L_34 ,
V_19 -> V_70 -> clock , V_19 -> V_71 ,
V_19 -> V_74 , V_19 -> V_75 ) ;
V_32 = F_37 ( V_19 -> V_59 , V_19 -> V_71 ) ;
if ( V_32 ) {
F_11 ( L_29 , V_33 , V_32 ) ;
goto error;
}
V_32 = F_37 ( V_19 -> V_61 , V_19 -> V_74 ) ;
if ( V_32 ) {
F_11 ( L_35 , V_33 , V_32 ) ;
goto error;
}
V_32 = F_37 ( V_19 -> V_65 , V_19 -> V_75 ) ;
if ( V_32 ) {
F_11 ( L_36 , V_33 , V_32 ) ;
goto error;
}
V_32 = F_37 ( V_19 -> V_60 , V_19 -> V_70 -> clock * 1000 ) ;
if ( V_32 ) {
F_11 ( L_30 , V_33 , V_32 ) ;
goto error;
}
V_32 = F_14 ( V_19 -> V_59 ) ;
if ( V_32 ) {
F_11 ( L_32 , V_33 ) ;
goto error;
}
V_32 = F_14 ( V_19 -> V_61 ) ;
if ( V_32 ) {
F_11 ( L_31 , V_33 ) ;
goto V_76;
}
V_32 = F_14 ( V_19 -> V_65 ) ;
if ( V_32 ) {
F_11 ( L_37 , V_33 ) ;
goto V_77;
}
V_32 = F_14 ( V_19 -> V_60 ) ;
if ( V_32 ) {
F_11 ( L_33 , V_33 ) ;
goto V_73;
}
return 0 ;
V_73:
F_17 ( V_19 -> V_65 ) ;
V_77:
F_17 ( V_19 -> V_61 ) ;
V_76:
F_17 ( V_19 -> V_59 ) ;
error:
return V_32 ;
}
static int F_39 ( struct V_18 * V_19 )
{
const struct V_23 * V_24 = V_19 -> V_24 ;
if ( V_24 -> V_2 == V_10 )
return F_36 ( V_19 ) ;
else
return F_38 ( V_19 ) ;
}
static void F_40 ( struct V_18 * V_19 )
{
const struct V_23 * V_24 = V_19 -> V_24 ;
if ( V_24 -> V_2 == V_10 ) {
F_17 ( V_19 -> V_61 ) ;
F_17 ( V_19 -> V_60 ) ;
F_17 ( V_19 -> V_59 ) ;
} else {
F_17 ( V_19 -> V_60 ) ;
F_17 ( V_19 -> V_65 ) ;
F_17 ( V_19 -> V_61 ) ;
F_17 ( V_19 -> V_59 ) ;
}
}
static int F_41 ( struct V_18 * V_19 , bool V_78 )
{
int V_32 = 0 ;
F_42 ( & V_19 -> V_79 ) ;
if ( V_78 ) {
V_32 = F_34 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_38 ,
V_33 , V_32 ) ;
goto V_80;
}
V_32 = F_39 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_39 ,
V_33 , V_32 ) ;
F_35 ( V_19 ) ;
goto V_80;
}
} else {
F_40 ( V_19 ) ;
F_35 ( V_19 ) ;
}
V_80:
F_43 ( & V_19 -> V_79 ) ;
return V_32 ;
}
static int F_44 ( struct V_18 * V_19 )
{
struct V_81 * V_70 = V_19 -> V_70 ;
const struct V_23 * V_24 = V_19 -> V_24 ;
T_3 V_82 = V_19 -> V_82 ;
T_2 V_83 = F_4 ( V_19 -> V_84 ) ;
T_2 V_85 ;
if ( ! V_70 ) {
F_11 ( L_40 , V_33 ) ;
return - V_5 ;
}
V_85 = V_70 -> clock * 1000 ;
if ( V_82 > 0 ) {
V_19 -> V_71 = ( V_85 * V_83 ) / ( 8 * V_82 ) ;
} else {
F_11 ( L_41 , V_33 ) ;
V_19 -> V_71 = ( V_85 * V_83 ) / 8 ;
}
F_16 ( L_42 , V_85 , V_19 -> V_71 ) ;
V_19 -> V_74 = F_45 ( V_19 -> V_61 ) ;
if ( V_24 -> V_2 == V_8 ) {
unsigned int V_86 , V_87 ;
unsigned long V_88 ;
V_19 -> V_75 = ( V_85 * V_83 ) / 8 ;
V_88 = V_19 -> V_71 / 1000000 ;
for ( V_86 = 20 ; V_86 >= 5 ; V_86 -- ) {
V_87 = F_46 ( V_88 , V_86 ) ;
if ( V_87 >= 1 && V_87 <= 16 )
break;
}
if ( V_86 < 5 )
return - V_5 ;
V_19 -> V_74 = V_19 -> V_71 / V_87 ;
F_16 ( L_43 , V_19 -> V_74 ,
V_19 -> V_75 ) ;
}
return 0 ;
}
static void F_47 ( struct V_18 * V_19 , T_2 V_89 , int V_78 )
{
T_2 V_90 ;
unsigned long V_91 ;
F_48 ( & V_19 -> V_92 , V_91 ) ;
V_90 = F_5 ( V_19 , V_93 ) ;
if ( V_78 )
V_90 |= V_89 ;
else
V_90 &= ~ V_89 ;
F_16 ( L_44 , V_90 , V_78 ) ;
F_6 ( V_19 , V_93 , V_90 ) ;
F_49 ( & V_19 -> V_92 , V_91 ) ;
}
static inline enum V_94 F_50 ( const T_2 V_95 )
{
if ( V_95 & V_96 )
return V_97 ;
else if ( V_95 & V_98 )
return V_99 ;
return V_100 ;
}
static inline enum V_101 F_51 (
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
static inline enum V_107 F_52 (
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
static void F_53 ( struct V_18 * V_19 , bool V_78 ,
struct V_110 * V_111 )
{
T_2 V_91 = V_19 -> V_95 ;
enum V_12 V_102 = V_19 -> V_84 ;
const struct V_23 * V_24 = V_19 -> V_24 ;
T_2 V_22 = 0 ;
if ( ! V_78 ) {
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
V_22 |= F_54 ( F_50 ( V_91 ) ) ;
V_22 |= F_55 ( F_51 ( V_102 ) ) ;
V_22 |= F_56 ( V_19 -> V_124 ) ;
F_6 ( V_19 , V_125 , V_22 ) ;
V_22 = F_57 ( V_126 ) ;
F_6 ( V_19 , V_127 , 0 ) ;
} else {
V_22 = F_58 ( V_126 ) ;
V_22 |= F_59 ( F_52 ( V_102 ) ) ;
F_6 ( V_19 , V_128 , V_22 ) ;
V_22 = F_60 ( V_129 ) |
F_61 (
V_130 ) ;
V_22 |= V_131 ;
F_6 ( V_19 , V_132 , V_22 ) ;
}
F_6 ( V_19 , V_133 ,
V_134 |
V_135 ) ;
V_22 = 0 ;
V_22 |= V_136 ;
V_22 |= F_62 ( V_137 ) ;
V_22 |= F_63 ( V_138 ) ;
V_22 |= F_64 ( V_19 -> V_124 ) ;
if ( ( V_24 -> V_2 == V_10 ) &&
( V_24 -> V_3 >= V_139 ) )
V_22 |= V_140 ;
F_6 ( V_19 , V_141 , V_22 ) ;
V_22 = F_65 ( V_111 -> V_142 ) |
F_66 ( V_111 -> V_143 ) ;
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
F_47 ( V_19 , V_153 , 1 ) ;
F_6 ( V_19 , V_154 , V_155 ) ;
V_22 = V_156 ;
F_16 ( L_45 , V_19 -> V_82 ) ;
V_22 |= ( ( V_157 << V_19 -> V_82 ) - V_157 ) ;
F_6 ( V_19 , V_158 ,
F_67 ( V_19 -> V_159 ) ) ;
if ( ! ( V_91 & V_160 ) )
F_6 ( V_19 , V_161 ,
V_162 ) ;
V_22 |= V_163 ;
F_6 ( V_19 , V_112 , V_22 ) ;
}
static void F_68 ( struct V_18 * V_19 )
{
struct V_81 * V_70 = V_19 -> V_70 ;
T_2 V_164 = 0 , V_165 = 0 ;
T_2 V_166 = V_70 -> V_167 ;
T_2 V_168 = V_70 -> V_169 ;
T_2 V_170 = V_70 -> V_171 - V_70 -> V_172 ;
T_2 V_173 = V_70 -> V_174 - V_70 -> V_175 ;
T_2 V_176 = V_166 - V_70 -> V_172 ;
T_2 V_177 = V_176 + V_70 -> V_178 ;
T_2 va_start = V_168 - V_70 -> V_175 ;
T_2 va_end = va_start + V_70 -> V_179 ;
T_2 V_180 ;
F_16 ( L_9 ) ;
if ( V_19 -> V_95 & V_113 ) {
F_6 ( V_19 , V_181 ,
F_69 ( V_176 ) |
F_70 ( V_177 ) ) ;
F_6 ( V_19 , V_182 ,
F_71 ( va_start ) |
F_72 ( va_end ) ) ;
F_6 ( V_19 , V_183 ,
F_73 ( V_166 - 1 ) |
F_74 ( V_168 - 1 ) ) ;
F_6 ( V_19 , V_184 ,
F_75 ( V_164 ) |
F_76 ( V_170 ) ) ;
F_6 ( V_19 , V_185 , 0 ) ;
F_6 ( V_19 , V_186 ,
F_77 ( V_165 ) |
F_78 ( V_173 ) ) ;
} else {
V_180 = V_70 -> V_178 * F_4 ( V_19 -> V_84 ) / 8 + 1 ;
F_6 ( V_19 , V_187 ,
F_79 ( V_180 ) |
F_80 (
V_19 -> V_124 ) |
F_81 (
V_188 ) ) ;
F_6 ( V_19 , V_189 ,
F_82 ( V_70 -> V_178 ) |
F_83 ( V_70 -> V_179 ) ) ;
}
}
static void F_84 ( struct V_18 * V_19 )
{
F_6 ( V_19 , V_154 , V_155 ) ;
F_85 () ;
F_6 ( V_19 , V_190 , 1 ) ;
F_85 () ;
F_6 ( V_19 , V_190 , 0 ) ;
}
static void F_86 ( struct V_18 * V_19 ,
bool V_191 , bool V_78 )
{
T_2 V_192 ;
V_192 = F_5 ( V_19 , V_112 ) ;
if ( ! V_78 ) {
V_192 &= ~ ( V_163 | V_193 |
V_194 ) ;
F_47 ( V_19 , V_195 |
V_196 , 0 ) ;
} else {
if ( V_191 ) {
V_192 |= V_193 ;
} else {
V_192 |= V_194 ;
F_47 ( V_19 , V_195 , 1 ) ;
}
V_192 |= V_163 ;
}
F_6 ( V_19 , V_112 , V_192 ) ;
}
static void F_87 ( int V_70 , struct V_18 * V_19 )
{
T_2 V_22 ;
V_22 = F_5 ( V_19 , V_133 ) ;
if ( V_70 == 0 )
V_22 &= ~ V_135 ;
else
V_22 |= V_135 ;
F_6 ( V_19 , V_133 , V_22 ) ;
}
static void F_88 ( struct V_18 * V_19 )
{
F_47 ( V_19 , V_196 , 1 ) ;
F_89 ( & V_19 -> V_197 ) ;
F_90 ( & V_19 -> V_197 ,
F_91 ( 70 ) ) ;
F_47 ( V_19 , V_196 , 0 ) ;
}
static void F_92 ( struct V_18 * V_19 )
{
if ( ! ( V_19 -> V_95 & V_113 ) )
return;
if ( V_19 -> V_198 ) {
F_88 ( V_19 ) ;
F_93 ( 2000 , 4000 ) ;
}
}
static int F_94 ( struct V_18 * V_19 , int V_199 )
{
struct V_200 * V_26 = V_19 -> V_26 ;
const struct V_23 * V_24 = V_19 -> V_24 ;
int V_32 ;
T_4 V_201 ;
if ( V_24 -> V_2 == V_10 ) {
F_42 ( & V_26 -> V_202 ) ;
V_19 -> V_203 = F_95 ( V_26 , V_199 , V_204 ) ;
if ( F_10 ( V_19 -> V_203 ) ) {
V_32 = F_32 ( V_19 -> V_203 ) ;
F_11 ( L_46 ,
V_33 , V_32 ) ;
V_19 -> V_203 = NULL ;
F_43 ( & V_26 -> V_202 ) ;
return V_32 ;
}
V_32 = F_96 ( V_19 -> V_203 , 0 , & V_201 ) ;
F_43 ( & V_26 -> V_202 ) ;
if ( V_32 ) {
F_11 ( L_47 , V_33 , V_32 ) ;
return V_32 ;
}
if ( V_201 & 0x07 ) {
F_11 ( L_48 , V_33 ) ;
return - V_5 ;
}
V_19 -> V_205 = V_19 -> V_203 -> V_199 ;
} else {
V_19 -> V_206 = F_97 ( V_26 -> V_26 , V_199 ,
& V_19 -> V_207 , V_208 ) ;
if ( ! V_19 -> V_206 ) {
V_32 = - V_209 ;
F_11 ( L_49 ,
V_33 , V_32 ) ;
return V_32 ;
}
V_19 -> V_205 = V_199 ;
}
return 0 ;
}
static void F_98 ( struct V_18 * V_19 )
{
struct V_200 * V_26 = V_19 -> V_26 ;
if ( V_19 -> V_203 ) {
F_99 ( V_19 -> V_203 , 0 ) ;
F_42 ( & V_26 -> V_202 ) ;
F_100 ( V_19 -> V_203 ) ;
V_19 -> V_203 = NULL ;
F_43 ( & V_26 -> V_202 ) ;
}
if ( V_19 -> V_206 )
F_101 ( V_26 -> V_26 , V_19 -> V_205 , V_19 -> V_206 ,
V_19 -> V_207 ) ;
}
static int F_102 ( struct V_18 * V_19 ,
const struct V_210 * V_211 )
{
const struct V_23 * V_24 = V_19 -> V_24 ;
struct V_212 V_213 ;
int V_214 ;
int V_32 ;
T_3 * V_22 ;
V_32 = F_103 ( & V_213 , V_211 ) ;
if ( V_32 ) {
F_11 ( L_50 , V_33 , V_32 ) ;
return V_32 ;
}
V_214 = ( V_213 . V_199 + 3 ) & ( ~ 0x3 ) ;
if ( V_214 > V_19 -> V_205 ) {
F_11 ( L_51 , V_33 ) ;
return - V_5 ;
}
if ( V_24 -> V_2 == V_10 ) {
V_22 = F_104 ( V_19 -> V_203 ) ;
if ( F_10 ( V_22 ) ) {
V_32 = F_32 ( V_22 ) ;
F_11 ( L_52 , V_33 , V_32 ) ;
return V_32 ;
}
} else {
V_22 = V_19 -> V_206 ;
}
V_22 [ 0 ] = V_213 . V_215 [ 1 ] ;
V_22 [ 1 ] = V_213 . V_215 [ 2 ] ;
V_22 [ 2 ] = V_213 . V_215 [ 0 ] ;
V_22 [ 3 ] = F_105 ( 7 ) ;
if ( F_106 ( V_211 -> type ) )
V_22 [ 3 ] |= F_105 ( 6 ) ;
if ( V_211 -> V_216 && V_211 -> V_217 )
V_22 [ 3 ] |= F_105 ( 5 ) ;
if ( V_213 . V_218 && V_213 . V_219 )
memcpy ( V_22 + 4 , V_213 . V_218 , V_213 . V_219 ) ;
if ( V_213 . V_199 < V_214 )
memset ( V_22 + V_213 . V_199 , 0xff , V_214 - V_213 . V_199 ) ;
if ( V_24 -> V_2 == V_10 )
F_107 ( V_19 -> V_203 ) ;
return V_214 ;
}
static int F_108 ( T_3 * V_220 , const struct V_210 * V_211 )
{
T_3 * V_22 = V_211 -> V_216 ;
if ( V_22 && ( V_211 -> V_217 >= 1 ) ) {
* V_22 = V_220 [ 1 ] ;
return 1 ;
} else {
F_11 ( L_53 ,
V_33 , V_211 -> V_217 ) ;
return - V_5 ;
}
}
static int F_109 ( T_3 * V_220 , const struct V_210 * V_211 )
{
T_3 * V_22 = V_211 -> V_216 ;
if ( V_22 && ( V_211 -> V_217 >= 2 ) ) {
V_22 [ 0 ] = V_220 [ 1 ] ;
V_22 [ 1 ] = V_220 [ 2 ] ;
return 2 ;
} else {
F_11 ( L_53 ,
V_33 , V_211 -> V_217 ) ;
return - V_5 ;
}
}
static int F_110 ( T_3 * V_220 , const struct V_210 * V_211 )
{
if ( V_211 -> V_216 && V_211 -> V_217 )
memcpy ( V_211 -> V_216 , V_220 + 4 , V_211 -> V_217 ) ;
return V_211 -> V_217 ;
}
static int F_111 ( struct V_18 * V_19 , int V_214 )
{
const struct V_23 * V_24 = V_19 -> V_24 ;
int V_32 ;
T_4 V_221 ;
bool V_222 ;
if ( V_24 -> V_2 == V_10 ) {
V_32 = F_112 ( V_19 -> V_203 , 0 , & V_221 ) ;
if ( V_32 ) {
F_11 ( L_54 , V_33 , V_32 ) ;
return V_32 ;
}
} else {
V_221 = V_19 -> V_207 ;
}
F_89 ( & V_19 -> V_223 ) ;
F_92 ( V_19 ) ;
V_222 = F_113 (
V_19 -> V_68 , V_221 , V_214 ) ;
if ( V_222 ) {
V_32 = F_90 ( & V_19 -> V_223 ,
F_91 ( 200 ) ) ;
F_16 ( L_55 , V_32 ) ;
if ( V_32 == 0 )
V_32 = - V_224 ;
else
V_32 = V_214 ;
} else
V_32 = V_214 ;
return V_32 ;
}
static int F_114 ( struct V_18 * V_19 ,
T_3 * V_220 , int V_225 , int V_226 )
{
T_2 * V_227 , * V_228 , V_22 ;
int V_48 , V_229 = 0 , V_230 ;
T_2 V_231 ;
T_3 V_20 [ 16 ] ;
int V_232 = 0 ;
int V_233 = V_220 - V_19 -> V_216 ;
V_227 = ( T_2 * ) V_220 ;
V_228 = ( T_2 * ) V_20 ;
V_230 = ( V_225 + 3 ) >> 2 ;
if ( V_230 > 4 )
V_230 = 4 ;
if ( V_225 == 4 )
V_231 = 4 ;
else
V_231 = V_226 + 6 ;
if ( V_231 > 16 ) {
int V_234 ;
V_234 = V_231 - 16 ;
V_232 = V_233 - V_234 ;
}
for ( V_48 = V_230 - 1 ; V_48 >= 0 ; V_48 -- ) {
V_22 = F_5 ( V_19 , F_115 ( V_48 ) ) ;
* V_228 ++ = F_116 ( V_22 ) ;
F_16 ( L_56 , V_22 , F_116 ( V_22 ) ) ;
}
for ( V_48 = V_232 ; V_48 < 16 ; V_48 ++ )
V_220 [ V_229 ++ ] = V_20 [ V_48 ] ;
return V_229 ;
}
static int F_117 ( struct V_18 * V_19 ,
const struct V_210 * V_211 )
{
int V_214 , V_32 ;
int V_235 = V_19 -> V_70 -> V_178 *
F_4 ( V_19 -> V_84 ) / 8 ;
V_214 = F_102 ( V_19 , V_211 ) ;
if ( ! V_214 ) {
F_11 ( L_57 ,
V_33 , V_211 -> type ) ;
return - V_5 ;
}
if ( ( V_19 -> V_95 & V_113 ) && ( V_214 > V_235 ) ) {
F_11 ( L_58 ,
V_33 , V_214 ) ;
return - V_5 ;
}
V_32 = F_111 ( V_19 , V_214 ) ;
if ( V_32 < V_214 ) {
F_11 ( L_59 ,
V_33 , V_211 -> type , ( * ( T_3 * ) ( V_211 -> V_206 ) ) , V_214 ) ;
return - V_236 ;
}
return V_214 ;
}
static void F_118 ( struct V_18 * V_19 )
{
T_2 V_237 , V_238 ;
V_237 = F_5 ( V_19 , V_112 ) ;
V_238 = V_237 ;
V_238 &= ~ V_163 ;
F_6 ( V_19 , V_112 , V_238 ) ;
F_85 () ;
F_6 ( V_19 , V_154 , V_155 ) ;
F_85 () ;
F_6 ( V_19 , V_190 , 1 ) ;
F_85 () ;
F_6 ( V_19 , V_190 , 0 ) ;
F_85 () ;
F_6 ( V_19 , V_112 , V_237 ) ;
F_85 () ;
}
static void F_119 ( struct V_239 * V_240 )
{
struct V_18 * V_19 =
F_22 ( V_240 , struct V_18 , V_241 ) ;
F_120 ( V_19 -> V_26 ) ;
}
static void F_121 ( struct V_239 * V_240 )
{
struct V_18 * V_19 =
F_22 ( V_240 , struct V_18 , V_242 ) ;
T_2 V_243 = V_19 -> V_244 ;
F_122 ( L_60 , V_33 , V_243 ) ;
if ( V_243 & V_245 )
F_118 ( V_19 ) ;
V_19 -> V_244 = 0 ;
F_47 ( V_19 , V_153 , 1 ) ;
}
static void F_123 ( struct V_18 * V_19 )
{
T_2 V_243 ;
V_243 = F_5 ( V_19 , V_246 ) ;
if ( V_243 ) {
F_6 ( V_19 , V_246 , V_243 ) ;
F_6 ( V_19 , V_246 , 0 ) ;
V_19 -> V_244 |= V_247 ;
}
}
static void F_124 ( struct V_18 * V_19 )
{
T_2 V_243 ;
V_243 = F_5 ( V_19 , V_248 ) ;
if ( V_243 ) {
F_6 ( V_19 , V_248 , V_243 ) ;
V_19 -> V_244 |= V_249 ;
}
}
static void F_125 ( struct V_18 * V_19 )
{
T_2 V_243 ;
V_243 = F_5 ( V_19 , V_250 ) ;
if ( V_243 & ( V_251 |
V_252 |
V_253 |
V_254 |
V_255 ) ) {
F_6 ( V_19 , V_250 , V_243 ) ;
V_19 -> V_244 |= V_256 ;
}
}
static void F_126 ( struct V_18 * V_19 )
{
T_2 V_243 ;
V_243 = F_5 ( V_19 , V_257 ) ;
if ( V_243 ) {
F_6 ( V_19 , V_257 , V_243 ) ;
V_19 -> V_244 |= V_258 ;
if ( V_243 & V_259 )
V_19 -> V_244 |=
V_245 ;
}
}
static void F_127 ( struct V_18 * V_19 )
{
T_2 V_243 ;
V_243 = F_5 ( V_19 , V_260 ) ;
if ( V_243 & V_261 ) {
F_6 ( V_19 , V_260 , V_243 ) ;
V_19 -> V_244 |=
V_262 ;
}
}
static void F_128 ( struct V_18 * V_19 )
{
T_2 V_243 ;
V_243 = F_5 ( V_19 , V_263 ) ;
if ( V_243 & V_264 ) {
F_6 ( V_19 , V_263 , V_243 ) ;
V_19 -> V_244 |= V_265 ;
}
}
static void F_129 ( struct V_18 * V_19 )
{
F_47 ( V_19 , V_153 , 0 ) ;
F_128 ( V_19 ) ;
F_126 ( V_19 ) ;
F_123 ( V_19 ) ;
F_124 ( V_19 ) ;
F_127 ( V_19 ) ;
F_125 ( V_19 ) ;
F_130 ( V_19 -> V_266 , & V_19 -> V_242 ) ;
}
static T_5 F_131 ( int V_267 , void * V_268 )
{
struct V_18 * V_19 = V_268 ;
T_2 V_269 ;
unsigned long V_91 ;
if ( ! V_19 -> V_21 )
return V_270 ;
F_48 ( & V_19 -> V_92 , V_91 ) ;
V_269 = F_5 ( V_19 , V_93 ) ;
F_6 ( V_19 , V_93 , V_269 ) ;
F_49 ( & V_19 -> V_92 , V_91 ) ;
F_16 ( L_61 , V_269 , V_19 -> V_68 ) ;
if ( V_269 & V_271 )
F_129 ( V_19 ) ;
if ( V_269 & V_272 )
F_132 ( & V_19 -> V_197 ) ;
if ( V_269 & V_273 )
F_132 ( & V_19 -> V_223 ) ;
return V_270 ;
}
static int F_133 ( struct V_18 * V_19 ,
struct V_25 * V_274 )
{
V_19 -> V_275 = F_134 ( V_274 ,
L_62 ,
V_276 ) ;
if ( F_10 ( V_19 -> V_275 ) ) {
F_16 ( L_63 ,
F_32 ( V_19 -> V_275 ) ) ;
return F_32 ( V_19 -> V_275 ) ;
}
V_19 -> V_277 = F_134 ( V_274 , L_64 ,
V_278 ) ;
if ( F_10 ( V_19 -> V_277 ) ) {
F_16 ( L_65 , F_32 ( V_19 -> V_277 ) ) ;
return F_32 ( V_19 -> V_277 ) ;
}
return 0 ;
}
static int F_135 ( struct V_38 * V_39 ,
struct V_279 * V_280 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
int V_32 ;
if ( V_280 -> V_82 > V_19 -> V_281 )
return - V_5 ;
V_19 -> V_124 = V_280 -> V_124 ;
V_19 -> V_82 = V_280 -> V_82 ;
V_19 -> V_84 = V_280 -> V_84 ;
V_19 -> V_95 = V_280 -> V_95 ;
F_136 ( V_19 -> V_68 , V_280 -> V_95 ) ;
V_32 = F_133 ( V_19 , & V_280 -> V_26 ) ;
if ( V_32 )
return V_32 ;
F_16 ( L_26 , V_19 -> V_68 ) ;
if ( V_19 -> V_26 )
F_130 ( V_19 -> V_266 , & V_19 -> V_241 ) ;
return 0 ;
}
static int F_137 ( struct V_38 * V_39 ,
struct V_279 * V_280 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
V_19 -> V_282 = NULL ;
F_16 ( L_26 , V_19 -> V_68 ) ;
if ( V_19 -> V_26 )
F_130 ( V_19 -> V_266 , & V_19 -> V_241 ) ;
return 0 ;
}
static T_6 F_138 ( struct V_38 * V_39 ,
const struct V_210 * V_211 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
int V_32 ;
if ( ! V_211 || ! V_19 -> V_198 )
return - V_5 ;
F_42 ( & V_19 -> V_283 ) ;
V_32 = F_139 ( V_19 -> V_68 , V_211 ) ;
F_43 ( & V_19 -> V_283 ) ;
return V_32 ;
}
static int F_140 ( struct V_18 * V_19 ,
struct V_282 * V_284 )
{
struct V_25 * V_26 = & V_19 -> V_27 -> V_26 ;
struct V_285 * V_286 ;
T_2 V_287 [ 4 ] ;
int V_32 , V_48 , V_214 , V_288 ;
V_286 = F_141 ( V_284 , L_66 , & V_214 ) ;
if ( ! V_286 ) {
F_142 ( V_26 ,
L_67 ) ;
return 0 ;
}
V_288 = V_214 / sizeof( T_2 ) ;
if ( V_288 < 1 || V_288 > 4 ) {
F_143 ( V_26 , L_68 ) ;
return - V_5 ;
}
V_19 -> V_281 = V_288 ;
V_32 = F_144 ( V_284 , L_66 , V_287 ,
V_288 ) ;
if ( V_32 ) {
F_143 ( V_26 , L_69 ) ;
return V_32 ;
}
for ( V_48 = 0 ; V_48 < F_145 ( V_289 ) ; V_48 ++ ) {
const int * V_290 = V_289 [ V_48 ] ;
int V_229 ;
for ( V_229 = 0 ; V_229 < V_288 ; V_229 ++ ) {
if ( V_287 [ V_229 ] < 0 || V_287 [ V_229 ] > 3 )
F_143 ( V_26 , L_70 ,
V_287 [ V_229 ] ) ;
if ( V_290 [ V_287 [ V_229 ] ] != V_229 )
break;
}
if ( V_229 == V_288 ) {
V_19 -> V_159 = V_48 ;
return 0 ;
}
}
return - V_5 ;
}
static int F_146 ( struct V_18 * V_19 )
{
struct V_25 * V_26 = & V_19 -> V_27 -> V_26 ;
struct V_282 * V_291 = V_26 -> V_292 ;
struct V_282 * V_293 , * V_282 ;
int V_32 = 0 ;
V_293 = F_147 ( V_291 , 1 , - 1 ) ;
if ( ! V_293 ) {
F_142 ( V_26 , L_71 , V_33 ) ;
return 0 ;
}
V_32 = F_140 ( V_19 , V_293 ) ;
if ( V_32 ) {
F_143 ( V_26 , L_72 ,
V_33 , V_32 ) ;
goto V_69;
}
V_282 = F_148 ( V_291 , 1 , 0 ) ;
if ( ! V_282 ) {
F_142 ( V_26 , L_73 , V_33 ) ;
goto V_69;
}
V_19 -> V_282 = V_282 ;
if ( F_149 ( V_291 , L_74 ) ) {
V_19 -> V_294 = F_150 ( V_291 ,
L_74 ) ;
if ( F_10 ( V_19 -> V_294 ) ) {
F_143 ( V_26 , L_75 ,
V_33 ) ;
V_32 = F_32 ( V_19 -> V_294 ) ;
}
}
F_151 ( V_282 ) ;
V_69:
F_151 ( V_293 ) ;
return V_32 ;
}
static int F_152 ( struct V_18 * V_19 )
{
struct V_295 * V_27 = V_19 -> V_27 ;
const struct V_55 * V_45 = V_19 -> V_24 -> V_45 ;
struct V_296 * V_297 ;
int V_48 ;
V_297 = F_153 ( V_27 , V_298 , L_76 ) ;
if ( ! V_297 )
return - V_5 ;
for ( V_48 = 0 ; V_48 < V_45 -> V_299 ; V_48 ++ ) {
if ( V_45 -> V_300 [ V_48 ] == V_297 -> V_301 )
return V_48 ;
}
return - V_5 ;
}
int F_154 ( struct V_302 * V_302 )
{
struct V_18 * V_19 = NULL ;
struct V_295 * V_27 = V_302 -> V_27 ;
int V_32 ;
V_19 = F_155 ( & V_27 -> V_26 , sizeof( * V_19 ) , V_208 ) ;
if ( ! V_19 ) {
F_11 ( L_77 ,
V_33 ) ;
V_32 = - V_209 ;
goto V_52;
}
V_19 -> V_27 = V_27 ;
V_32 = F_146 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_78 , V_33 ) ;
goto V_52;
}
V_19 -> V_21 = F_156 ( V_27 , L_76 , L_79 ) ;
if ( F_10 ( V_19 -> V_21 ) ) {
F_11 ( L_80 , V_33 ) ;
V_32 = F_32 ( V_19 -> V_21 ) ;
goto V_52;
}
V_19 -> V_24 = F_8 ( V_19 ) ;
if ( ! V_19 -> V_24 ) {
V_32 = - V_5 ;
F_11 ( L_81 , V_33 ) ;
goto V_52;
}
V_19 -> V_68 = F_152 ( V_19 ) ;
if ( V_19 -> V_68 < 0 ) {
V_32 = V_19 -> V_68 ;
F_11 ( L_82 , V_33 ) ;
goto V_52;
}
V_19 -> V_21 += V_19 -> V_24 -> V_45 -> V_303 ;
V_32 = F_28 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_83 , V_33 ) ;
goto V_52;
}
V_32 = F_30 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_84 , V_33 ) ;
goto V_52;
}
V_19 -> V_216 = F_155 ( & V_27 -> V_26 , V_304 , V_208 ) ;
if ( ! V_19 -> V_216 ) {
V_32 = - V_209 ;
F_11 ( L_85 , V_33 ) ;
goto V_52;
}
F_157 ( & V_19 -> V_223 ) ;
F_157 ( & V_19 -> V_197 ) ;
F_158 ( & V_19 -> V_305 ) ;
F_158 ( & V_19 -> V_283 ) ;
F_158 ( & V_19 -> V_79 ) ;
F_159 ( & V_19 -> V_92 ) ;
V_19 -> V_266 = F_160 ( L_86 , 0 ) ;
F_161 ( & V_19 -> V_242 , F_121 ) ;
F_161 ( & V_19 -> V_241 , F_119 ) ;
V_302 -> V_39 = & V_19 -> V_1 ;
V_302 -> V_68 = V_19 -> V_68 ;
F_16 ( L_87 , V_19 -> V_68 ) ;
return 0 ;
V_52:
return V_32 ;
}
void F_162 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_16 ( L_9 ) ;
F_98 ( V_19 ) ;
if ( V_19 -> V_266 ) {
F_163 ( V_19 -> V_266 ) ;
F_164 ( V_19 -> V_266 ) ;
V_19 -> V_266 = NULL ;
}
F_165 ( & V_19 -> V_79 ) ;
F_165 ( & V_19 -> V_283 ) ;
F_165 ( & V_19 -> V_305 ) ;
}
int F_166 ( struct V_38 * V_39 ,
struct V_200 * V_26 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
struct V_295 * V_27 = V_19 -> V_27 ;
int V_32 ;
V_19 -> V_267 = F_167 ( V_27 -> V_26 . V_292 , 0 ) ;
if ( V_19 -> V_267 < 0 ) {
V_32 = V_19 -> V_267 ;
F_143 ( V_26 -> V_26 , L_88 , V_32 ) ;
return V_32 ;
}
V_32 = F_168 ( & V_27 -> V_26 , V_19 -> V_267 ,
F_131 , V_306 | V_307 ,
L_89 , V_19 ) ;
if ( V_32 < 0 ) {
F_143 ( & V_27 -> V_26 , L_90 ,
V_19 -> V_267 , V_32 ) ;
return V_32 ;
}
V_19 -> V_26 = V_26 ;
V_32 = F_94 ( V_19 , V_304 ) ;
if ( V_32 ) {
F_11 ( L_91 , V_33 , V_32 ) ;
return V_32 ;
}
return 0 ;
}
int F_169 ( struct V_38 * V_39 , bool V_308 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
int V_32 ;
if ( ! V_19 -> V_309 ) {
V_39 -> V_26 = & V_19 -> V_27 -> V_26 ;
V_39 -> V_310 = & V_311 ;
V_32 = F_170 ( V_39 ) ;
if ( V_32 )
return V_32 ;
V_19 -> V_309 = true ;
if ( V_308 && V_19 -> V_282 ) {
if ( ! F_171 ( V_19 -> V_282 ) )
if ( ! F_172 ( V_19 -> V_282 ) )
return - V_312 ;
}
}
return 0 ;
}
void F_173 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
if ( V_19 -> V_309 ) {
F_174 ( V_39 ) ;
V_39 -> V_26 = NULL ;
V_39 -> V_310 = NULL ;
V_19 -> V_309 = false ;
}
}
int F_175 ( struct V_38 * V_39 ,
const struct V_210 * V_211 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_41 ( V_19 , 1 ) ;
if ( ! ( V_211 -> V_91 & V_313 ) )
F_87 ( 0 , V_19 ) ;
V_19 -> V_314 = F_5 ( V_19 , V_112 ) ;
F_6 ( V_19 , V_112 ,
V_19 -> V_314 |
V_194 |
V_163 ) ;
F_47 ( V_19 , V_315 , 1 ) ;
return 0 ;
}
void F_176 ( struct V_38 * V_39 ,
const struct V_210 * V_211 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_47 ( V_19 , V_315 , 0 ) ;
F_6 ( V_19 , V_112 , V_19 -> V_314 ) ;
if ( ! ( V_211 -> V_91 & V_313 ) )
F_87 ( 1 , V_19 ) ;
F_41 ( V_19 , 0 ) ;
}
int F_177 ( struct V_38 * V_39 ,
const struct V_210 * V_211 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
return F_117 ( V_19 , V_211 ) ;
}
int F_178 ( struct V_38 * V_39 ,
const struct V_210 * V_211 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
const struct V_23 * V_24 = V_19 -> V_24 ;
int V_316 , V_225 , V_317 , V_318 ;
int V_319 , V_320 , V_226 , V_32 = 0 ;
char V_321 ;
int V_322 = V_211 -> V_217 ;
T_3 * V_220 ;
if ( V_322 <= 2 ) {
V_319 = 1 ;
V_226 = V_322 ;
V_225 = 4 ;
} else {
V_319 = 0 ;
V_316 = 10 ;
if ( V_322 < V_316 )
V_226 = V_322 ;
else
V_226 = V_316 ;
V_225 = V_316 + 6 ;
}
V_220 = V_19 -> V_216 ;
V_318 = 0 ;
while ( ! V_318 ) {
T_3 V_323 [ 2 ] = { V_226 & 0xff , V_226 >> 8 } ;
struct V_210 V_324 = {
. V_124 = V_211 -> V_124 ,
. type = V_325 ,
. V_326 = 2 ,
. V_206 = V_323 ,
} ;
F_16 ( L_92 ,
V_322 , V_226 , V_225 ) ;
V_32 = F_117 ( V_19 , & V_324 ) ;
if ( V_32 < 2 ) {
F_11 ( L_93 ,
V_33 , V_32 ) ;
return - V_5 ;
}
if ( ( V_24 -> V_2 == V_10 ) &&
( V_24 -> V_3 >= V_327 ) ) {
F_6 ( V_19 , V_328 ,
V_329 ) ;
F_85 () ;
F_6 ( V_19 , V_328 , 0 ) ;
F_85 () ;
}
V_32 = F_117 ( V_19 , V_211 ) ;
if ( V_32 < V_211 -> V_326 ) {
F_11 ( L_94 , V_33 , V_32 ) ;
return V_32 ;
}
V_317 = F_114 ( V_19 , V_220 , V_225 , V_226 ) ;
if ( V_317 <= 0 )
return 0 ;
if ( V_319 )
break;
if ( V_322 <= V_316 ) {
V_320 = V_316 - V_322 ;
V_318 = 1 ;
} else {
V_320 = 0 ;
V_322 -= V_316 ;
}
if ( ! V_318 ) {
V_317 -= 2 ;
V_317 -= V_320 ;
V_220 += V_317 ;
V_316 = 14 ;
if ( V_322 < V_316 )
V_226 += V_322 ;
else
V_226 += V_316 ;
F_16 ( L_95 , V_220 , V_317 , V_320 ) ;
}
}
if ( V_226 < 10 && ! V_319 )
V_220 = V_19 -> V_216 + ( 10 - V_322 ) ;
else
V_220 = V_19 -> V_216 ;
V_321 = V_220 [ 0 ] ;
switch ( V_321 ) {
case V_330 :
F_11 ( L_96 , V_33 ) ;
V_32 = 0 ;
break;
case V_331 :
case V_332 :
V_32 = F_108 ( V_220 , V_211 ) ;
break;
case V_333 :
case V_334 :
V_32 = F_109 ( V_220 , V_211 ) ;
break;
case V_335 :
case V_336 :
V_32 = F_110 ( V_220 , V_211 ) ;
break;
default:
F_179 ( L_97 , V_33 ) ;
V_32 = 0 ;
}
return V_32 ;
}
void F_180 ( struct V_38 * V_39 , T_2 V_221 ,
T_2 V_214 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_6 ( V_19 , V_337 , V_221 ) ;
F_6 ( V_19 , V_338 , V_214 ) ;
F_6 ( V_19 , V_339 , 1 ) ;
F_85 () ;
}
int F_181 ( struct V_38 * V_39 ,
struct V_340 * V_341 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
const struct V_23 * V_24 = V_19 -> V_24 ;
struct V_30 * V_342 , * V_343 ;
int V_32 ;
V_32 = F_182 ( V_341 ,
& V_342 , & V_343 ) ;
if ( V_32 ) {
F_183 ( L_98 ,
V_33 ) ;
return 0 ;
}
V_32 = F_184 ( V_19 -> V_62 , V_342 ) ;
if ( V_32 ) {
F_11 ( L_99 ,
V_33 , V_32 ) ;
goto exit;
}
V_32 = F_184 ( V_19 -> V_64 , V_343 ) ;
if ( V_32 ) {
F_11 ( L_100 ,
V_33 , V_32 ) ;
goto exit;
}
if ( V_24 -> V_2 == V_8 ) {
V_32 = F_184 ( V_19 -> V_67 , V_343 ) ;
if ( V_32 ) {
F_11 ( L_101 ,
V_33 , V_32 ) ;
goto exit;
}
V_32 = F_184 ( V_19 -> V_66 , V_342 ) ;
if ( V_32 ) {
F_11 ( L_102 ,
V_33 , V_32 ) ;
goto exit;
}
}
exit:
return V_32 ;
}
void F_185 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_16 ( L_9 ) ;
F_6 ( V_19 , V_344 , V_345 ) ;
F_85 () ;
F_186 ( 1000 ) ;
F_6 ( V_19 , V_344 , 0 ) ;
F_186 ( 100 ) ;
}
void F_187 ( struct V_38 * V_39 ,
struct V_346 * V_347 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
V_347 -> V_348 = V_19 -> V_71 * 8 ;
V_347 -> V_349 = V_19 -> V_74 ;
}
int F_188 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_86 ( V_19 ,
! ! ( V_19 -> V_95 & V_113 ) , true ) ;
return 0 ;
}
int F_189 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_86 ( V_19 ,
! ! ( V_19 -> V_95 & V_113 ) , false ) ;
F_84 ( V_19 ) ;
return 0 ;
}
static void F_190 ( struct V_18 * V_19 , bool V_78 )
{
enum V_350 V_351 ;
if ( ! V_19 -> V_294 )
return;
V_351 = V_78 ? V_352 : V_353 ;
F_191 ( V_19 -> V_294 , V_354 ,
V_355 ,
F_192 ( V_351 ) ) ;
}
int F_193 ( struct V_38 * V_39 ,
struct V_110 * V_111 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
int V_32 = 0 ;
F_42 ( & V_19 -> V_305 ) ;
if ( V_19 -> V_198 ) {
F_16 ( L_103 ) ;
goto V_80;
}
F_190 ( V_19 , true ) ;
V_32 = F_26 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_104 ,
V_33 , V_32 ) ;
goto V_80;
}
V_32 = F_41 ( V_19 , 1 ) ;
if ( V_32 ) {
F_11 ( L_105 , V_33 , V_32 ) ;
goto V_356;
}
V_32 = F_194 ( & V_19 -> V_27 -> V_26 ) ;
if ( V_32 ) {
F_11 ( L_106 ,
V_33 , V_32 ) ;
goto V_357;
}
F_68 ( V_19 ) ;
F_84 ( V_19 ) ;
F_53 ( V_19 , true , V_111 ) ;
if ( V_19 -> V_275 )
F_195 ( V_19 -> V_275 , 1 ) ;
V_19 -> V_198 = true ;
F_43 ( & V_19 -> V_305 ) ;
return 0 ;
V_357:
F_41 ( V_19 , 0 ) ;
V_356:
F_23 ( V_19 ) ;
V_80:
F_43 ( & V_19 -> V_305 ) ;
return V_32 ;
}
int F_196 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_42 ( & V_19 -> V_305 ) ;
if ( ! V_19 -> V_198 ) {
F_16 ( L_107 ) ;
goto V_80;
}
F_53 ( V_19 , false , NULL ) ;
if ( V_19 -> V_275 )
F_195 ( V_19 -> V_275 , 0 ) ;
F_197 ( & V_19 -> V_27 -> V_26 ) ;
F_41 ( V_19 , 0 ) ;
F_23 ( V_19 ) ;
F_190 ( V_19 , false ) ;
F_16 ( L_108 ) ;
V_19 -> V_198 = false ;
V_80:
F_43 ( & V_19 -> V_305 ) ;
return 0 ;
}
int F_198 ( struct V_38 * V_39 ,
struct V_81 * V_70 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
int V_32 ;
if ( V_19 -> V_70 ) {
F_199 ( V_19 -> V_26 , V_19 -> V_70 ) ;
V_19 -> V_70 = NULL ;
}
V_19 -> V_70 = F_200 ( V_19 -> V_26 , V_70 ) ;
if ( ! V_19 -> V_70 ) {
F_11 ( L_109 , V_33 ) ;
return - V_209 ;
}
V_32 = F_44 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_110 , V_33 , V_32 ) ;
return V_32 ;
}
return 0 ;
}
struct V_358 * F_201 ( struct V_38 * V_39 ,
unsigned long * V_359 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
struct V_358 * V_360 ;
V_360 = F_171 ( V_19 -> V_282 ) ;
if ( V_359 )
* V_359 = V_19 -> V_95 ;
return V_360 ;
}
struct V_361 * F_202 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
return F_172 ( V_19 -> V_282 ) ;
}
