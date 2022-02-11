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
for ( V_48 = 0 ; V_48 < V_47 ; V_48 ++ ) {
if ( F_30 ( V_41 [ V_48 ] . V_50 ) ) {
V_32 = F_31 ( V_41 [ V_48 ] . V_50 ,
V_44 [ V_48 ] . V_55 , V_44 [ V_48 ] . V_56 ) ;
if ( V_32 < 0 ) {
F_11 ( L_13 ,
V_48 , V_32 ) ;
return V_32 ;
}
}
}
return 0 ;
}
static int F_32 ( struct V_18 * V_19 )
{
struct V_25 * V_26 = & V_19 -> V_27 -> V_26 ;
const struct V_23 * V_24 = V_19 -> V_24 ;
const struct V_57 * V_45 = V_24 -> V_45 ;
int V_48 , V_32 = 0 ;
for ( V_48 = 0 ; V_48 < V_45 -> V_58 ; V_48 ++ ) {
V_19 -> V_59 [ V_48 ] = F_33 ( V_26 ,
V_45 -> V_60 [ V_48 ] ) ;
if ( F_10 ( V_19 -> V_59 [ V_48 ] ) ) {
V_32 = F_34 ( V_19 -> V_59 [ V_48 ] ) ;
F_11 ( L_14 ,
V_33 , V_45 -> V_60 [ V_48 ] , V_32 ) ;
goto exit;
}
}
V_19 -> V_61 = F_33 ( V_26 , L_15 ) ;
if ( F_10 ( V_19 -> V_61 ) ) {
V_32 = F_34 ( V_19 -> V_61 ) ;
F_11 ( L_16 ,
V_33 , V_32 ) ;
V_19 -> V_61 = NULL ;
goto exit;
}
V_19 -> V_62 = F_33 ( V_26 , L_17 ) ;
if ( F_10 ( V_19 -> V_62 ) ) {
V_32 = F_34 ( V_19 -> V_62 ) ;
F_11 ( L_18 ,
V_33 , V_32 ) ;
V_19 -> V_62 = NULL ;
goto exit;
}
V_19 -> V_63 = F_33 ( V_26 , L_19 ) ;
if ( F_10 ( V_19 -> V_63 ) ) {
V_32 = F_34 ( V_19 -> V_63 ) ;
F_11 ( L_20 ,
V_33 , V_32 ) ;
V_19 -> V_63 = NULL ;
goto exit;
}
V_19 -> V_64 = F_35 ( V_19 -> V_61 ) ;
if ( ! V_19 -> V_64 ) {
V_32 = - V_65 ;
F_11 ( L_21 , V_33 , V_32 ) ;
goto exit;
}
V_19 -> V_66 = F_35 ( V_19 -> V_62 ) ;
if ( ! V_19 -> V_66 ) {
V_32 = - V_65 ;
F_11 ( L_22 , V_33 , V_32 ) ;
goto exit;
}
if ( V_24 -> V_2 == V_8 ) {
V_19 -> V_67 = F_33 ( V_26 , L_23 ) ;
if ( F_10 ( V_19 -> V_67 ) ) {
V_32 = F_34 ( V_19 -> V_67 ) ;
F_11 ( L_24 ,
V_33 , V_32 ) ;
V_19 -> V_67 = NULL ;
goto exit;
}
V_19 -> V_68 = F_35 ( V_19 -> V_63 ) ;
if ( ! V_19 -> V_68 ) {
V_32 = - V_65 ;
F_11 ( L_25 ,
V_33 , V_32 ) ;
goto exit;
}
V_19 -> V_69 = F_35 ( V_19 -> V_67 ) ;
if ( ! V_19 -> V_69 ) {
V_32 = - V_65 ;
F_11 ( L_26 ,
V_33 , V_32 ) ;
}
}
exit:
return V_32 ;
}
static int F_36 ( struct V_18 * V_19 )
{
const struct V_57 * V_45 = V_19 -> V_24 -> V_45 ;
int V_48 , V_32 ;
F_16 ( L_27 , V_19 -> V_70 ) ;
for ( V_48 = 0 ; V_48 < V_45 -> V_58 ; V_48 ++ ) {
V_32 = F_14 ( V_19 -> V_59 [ V_48 ] ) ;
if ( V_32 ) {
F_11 ( L_28 ,
V_33 , V_48 , V_32 ) ;
goto V_71;
}
}
return 0 ;
V_71:
for (; V_48 > 0 ; V_48 -- )
F_17 ( V_19 -> V_59 [ V_48 ] ) ;
return V_32 ;
}
static void F_37 ( struct V_18 * V_19 )
{
const struct V_57 * V_45 = V_19 -> V_24 -> V_45 ;
int V_48 ;
F_16 ( L_9 ) ;
for ( V_48 = V_45 -> V_58 - 1 ; V_48 >= 0 ; V_48 -- )
F_17 ( V_19 -> V_59 [ V_48 ] ) ;
}
static int F_38 ( struct V_18 * V_19 )
{
int V_32 ;
F_16 ( L_29 ,
V_19 -> V_72 -> clock , V_19 -> V_73 ) ;
V_32 = F_39 ( V_19 -> V_61 , V_19 -> V_73 ) ;
if ( V_32 ) {
F_11 ( L_30 , V_33 , V_32 ) ;
goto error;
}
V_32 = F_39 ( V_19 -> V_62 , V_19 -> V_72 -> clock * 1000 ) ;
if ( V_32 ) {
F_11 ( L_31 , V_33 , V_32 ) ;
goto error;
}
V_32 = F_14 ( V_19 -> V_63 ) ;
if ( V_32 ) {
F_11 ( L_32 , V_33 ) ;
goto error;
}
V_32 = F_14 ( V_19 -> V_61 ) ;
if ( V_32 ) {
F_11 ( L_33 , V_33 ) ;
goto V_74;
}
V_32 = F_14 ( V_19 -> V_62 ) ;
if ( V_32 ) {
F_11 ( L_34 , V_33 ) ;
goto V_75;
}
return 0 ;
V_75:
F_17 ( V_19 -> V_61 ) ;
V_74:
F_17 ( V_19 -> V_63 ) ;
error:
return V_32 ;
}
static int F_40 ( struct V_18 * V_19 )
{
int V_32 ;
F_16 ( L_35 ,
V_19 -> V_72 -> clock , V_19 -> V_73 ,
V_19 -> V_76 , V_19 -> V_77 ) ;
V_32 = F_39 ( V_19 -> V_61 , V_19 -> V_73 ) ;
if ( V_32 ) {
F_11 ( L_30 , V_33 , V_32 ) ;
goto error;
}
V_32 = F_39 ( V_19 -> V_63 , V_19 -> V_76 ) ;
if ( V_32 ) {
F_11 ( L_36 , V_33 , V_32 ) ;
goto error;
}
V_32 = F_39 ( V_19 -> V_67 , V_19 -> V_77 ) ;
if ( V_32 ) {
F_11 ( L_37 , V_33 , V_32 ) ;
goto error;
}
V_32 = F_39 ( V_19 -> V_62 , V_19 -> V_72 -> clock * 1000 ) ;
if ( V_32 ) {
F_11 ( L_31 , V_33 , V_32 ) ;
goto error;
}
V_32 = F_14 ( V_19 -> V_61 ) ;
if ( V_32 ) {
F_11 ( L_33 , V_33 ) ;
goto error;
}
V_32 = F_14 ( V_19 -> V_63 ) ;
if ( V_32 ) {
F_11 ( L_32 , V_33 ) ;
goto V_78;
}
V_32 = F_14 ( V_19 -> V_67 ) ;
if ( V_32 ) {
F_11 ( L_38 , V_33 ) ;
goto V_79;
}
V_32 = F_14 ( V_19 -> V_62 ) ;
if ( V_32 ) {
F_11 ( L_34 , V_33 ) ;
goto V_75;
}
return 0 ;
V_75:
F_17 ( V_19 -> V_67 ) ;
V_79:
F_17 ( V_19 -> V_63 ) ;
V_78:
F_17 ( V_19 -> V_61 ) ;
error:
return V_32 ;
}
static int F_41 ( struct V_18 * V_19 )
{
const struct V_23 * V_24 = V_19 -> V_24 ;
if ( V_24 -> V_2 == V_10 )
return F_38 ( V_19 ) ;
else
return F_40 ( V_19 ) ;
}
static void F_42 ( struct V_18 * V_19 )
{
const struct V_23 * V_24 = V_19 -> V_24 ;
if ( V_24 -> V_2 == V_10 ) {
F_17 ( V_19 -> V_63 ) ;
F_17 ( V_19 -> V_62 ) ;
F_17 ( V_19 -> V_61 ) ;
} else {
F_17 ( V_19 -> V_62 ) ;
F_17 ( V_19 -> V_67 ) ;
F_17 ( V_19 -> V_63 ) ;
F_17 ( V_19 -> V_61 ) ;
}
}
static int F_43 ( struct V_18 * V_19 , bool V_80 )
{
int V_32 = 0 ;
F_44 ( & V_19 -> V_81 ) ;
if ( V_80 ) {
V_32 = F_36 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_39 ,
V_33 , V_32 ) ;
goto V_82;
}
V_32 = F_41 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_40 ,
V_33 , V_32 ) ;
F_37 ( V_19 ) ;
goto V_82;
}
} else {
F_42 ( V_19 ) ;
F_37 ( V_19 ) ;
}
V_82:
F_45 ( & V_19 -> V_81 ) ;
return V_32 ;
}
static int F_46 ( struct V_18 * V_19 )
{
struct V_83 * V_72 = V_19 -> V_72 ;
const struct V_23 * V_24 = V_19 -> V_24 ;
T_3 V_84 = V_19 -> V_84 ;
T_2 V_85 = F_4 ( V_19 -> V_86 ) ;
T_2 V_87 ;
if ( ! V_72 ) {
F_11 ( L_41 , V_33 ) ;
return - V_5 ;
}
V_87 = V_72 -> clock * 1000 ;
if ( V_84 > 0 ) {
V_19 -> V_73 = ( V_87 * V_85 ) / ( 8 * V_84 ) ;
} else {
F_11 ( L_42 , V_33 ) ;
V_19 -> V_73 = ( V_87 * V_85 ) / 8 ;
}
F_16 ( L_43 , V_87 , V_19 -> V_73 ) ;
V_19 -> V_76 = F_47 ( V_19 -> V_63 ) ;
if ( V_24 -> V_2 == V_8 ) {
unsigned int V_88 , V_89 ;
unsigned long V_90 ;
V_19 -> V_77 = ( V_87 * V_85 ) / 8 ;
V_90 = V_19 -> V_73 / 1000000 ;
for ( V_88 = 20 ; V_88 >= 5 ; V_88 -- ) {
V_89 = F_48 ( V_90 , V_88 ) ;
if ( V_89 >= 1 && V_89 <= 16 )
break;
}
if ( V_88 < 5 )
return - V_5 ;
V_19 -> V_76 = V_19 -> V_73 / V_89 ;
F_16 ( L_44 , V_19 -> V_76 ,
V_19 -> V_77 ) ;
}
return 0 ;
}
static void F_49 ( struct V_18 * V_19 )
{
F_16 ( L_9 ) ;
F_6 ( V_19 , V_91 , V_92 ) ;
F_50 () ;
F_51 ( 1000 ) ;
F_6 ( V_19 , V_91 , 0 ) ;
F_51 ( 100 ) ;
}
static void F_52 ( struct V_18 * V_19 , T_2 V_93 , int V_80 )
{
T_2 V_94 ;
unsigned long V_95 ;
F_53 ( & V_19 -> V_96 , V_95 ) ;
V_94 = F_5 ( V_19 , V_97 ) ;
if ( V_80 )
V_94 |= V_93 ;
else
V_94 &= ~ V_93 ;
F_16 ( L_45 , V_94 , V_80 ) ;
F_6 ( V_19 , V_97 , V_94 ) ;
F_54 ( & V_19 -> V_96 , V_95 ) ;
}
static inline enum V_98 F_55 ( const T_2 V_99 )
{
if ( V_99 & V_100 )
return V_101 ;
else if ( V_99 & V_102 )
return V_103 ;
return V_104 ;
}
static inline enum V_105 F_56 (
const enum V_12 V_106 )
{
switch ( V_106 ) {
case V_17 : return V_107 ;
case V_16 : return V_108 ;
case V_15 : return V_109 ;
case V_14 : return V_110 ;
default: return V_107 ;
}
}
static inline enum V_111 F_57 (
const enum V_12 V_106 )
{
switch ( V_106 ) {
case V_17 : return V_112 ;
case V_15 :
case V_16 : return V_109 ;
case V_14 : return V_113 ;
default: return V_112 ;
}
}
static void F_58 ( struct V_18 * V_19 , bool V_80 ,
T_2 V_114 , T_2 V_115 )
{
T_2 V_95 = V_19 -> V_99 ;
enum V_12 V_106 = V_19 -> V_86 ;
const struct V_23 * V_24 = V_19 -> V_24 ;
T_2 V_22 = 0 ;
if ( ! V_80 ) {
F_6 ( V_19 , V_116 , 0 ) ;
return;
}
if ( V_95 & V_117 ) {
if ( V_95 & V_118 )
V_22 |= V_119 ;
if ( V_95 & V_120 )
V_22 |= V_121 ;
if ( V_95 & V_122 )
V_22 |= V_123 ;
if ( V_95 & V_124 )
V_22 |= V_125 ;
V_22 |= V_126 |
V_127 ;
V_22 |= F_59 ( F_55 ( V_95 ) ) ;
V_22 |= F_60 ( F_56 ( V_106 ) ) ;
V_22 |= F_61 ( V_19 -> V_128 ) ;
F_6 ( V_19 , V_129 , V_22 ) ;
V_22 = F_62 ( V_130 ) ;
F_6 ( V_19 , V_131 , 0 ) ;
} else {
V_22 = F_63 ( V_130 ) ;
V_22 |= F_64 ( F_57 ( V_106 ) ) ;
F_6 ( V_19 , V_132 , V_22 ) ;
V_22 = F_65 ( V_133 ) |
F_66 (
V_134 ) ;
V_22 |= V_135 ;
F_6 ( V_19 , V_136 , V_22 ) ;
}
F_6 ( V_19 , V_137 ,
V_138 |
V_139 ) ;
V_22 = 0 ;
V_22 |= V_140 ;
V_22 |= F_67 ( V_141 ) ;
V_22 |= F_68 ( V_142 ) ;
V_22 |= F_69 ( V_19 -> V_128 ) ;
if ( ( V_24 -> V_2 == V_10 ) &&
( V_24 -> V_3 >= V_143 ) )
V_22 |= V_144 ;
F_6 ( V_19 , V_145 , V_22 ) ;
V_22 = F_70 ( V_115 ) |
F_71 ( V_114 ) ;
F_6 ( V_19 , V_146 , V_22 ) ;
V_22 = 0 ;
if ( ! ( V_95 & V_147 ) )
V_22 |= V_148 ;
F_6 ( V_19 , V_149 , V_22 ) ;
F_6 ( V_19 , V_150 , 0x13ff3fe0 ) ;
F_52 ( V_19 , V_151 , 1 ) ;
F_6 ( V_19 , V_152 , V_153 ) ;
V_22 = V_154 ;
F_16 ( L_46 , V_19 -> V_84 ) ;
V_22 |= ( ( V_155 << V_19 -> V_84 ) - V_155 ) ;
F_6 ( V_19 , V_156 ,
F_72 ( V_19 -> V_157 ) ) ;
if ( ! ( V_95 & V_158 ) )
F_6 ( V_19 , V_159 ,
V_160 ) ;
V_22 |= V_161 ;
F_6 ( V_19 , V_116 , V_22 ) ;
}
static void F_73 ( struct V_18 * V_19 )
{
struct V_83 * V_72 = V_19 -> V_72 ;
T_2 V_162 = 0 , V_163 = 0 ;
T_2 V_164 = V_72 -> V_165 ;
T_2 V_166 = V_72 -> V_167 ;
T_2 V_168 = V_72 -> V_169 - V_72 -> V_170 ;
T_2 V_171 = V_72 -> V_172 - V_72 -> V_173 ;
T_2 V_174 = V_164 - V_72 -> V_170 ;
T_2 V_175 = V_174 + V_72 -> V_176 ;
T_2 va_start = V_166 - V_72 -> V_173 ;
T_2 va_end = va_start + V_72 -> V_177 ;
T_2 V_178 ;
F_16 ( L_9 ) ;
if ( V_19 -> V_99 & V_117 ) {
F_6 ( V_19 , V_179 ,
F_74 ( V_174 ) |
F_75 ( V_175 ) ) ;
F_6 ( V_19 , V_180 ,
F_76 ( va_start ) |
F_77 ( va_end ) ) ;
F_6 ( V_19 , V_181 ,
F_78 ( V_164 - 1 ) |
F_79 ( V_166 - 1 ) ) ;
F_6 ( V_19 , V_182 ,
F_80 ( V_162 ) |
F_81 ( V_168 ) ) ;
F_6 ( V_19 , V_183 , 0 ) ;
F_6 ( V_19 , V_184 ,
F_82 ( V_163 ) |
F_83 ( V_171 ) ) ;
} else {
V_178 = V_72 -> V_176 * F_4 ( V_19 -> V_86 ) / 8 + 1 ;
F_6 ( V_19 , V_185 ,
F_84 ( V_178 ) |
F_85 (
V_19 -> V_128 ) |
F_86 (
V_186 ) ) ;
F_6 ( V_19 , V_187 ,
F_87 ( V_72 -> V_176 ) |
F_88 ( V_72 -> V_177 ) ) ;
}
}
static void F_89 ( struct V_18 * V_19 )
{
F_6 ( V_19 , V_152 , V_153 ) ;
F_50 () ;
F_6 ( V_19 , V_188 , 1 ) ;
F_50 () ;
F_6 ( V_19 , V_188 , 0 ) ;
}
static void F_90 ( struct V_18 * V_19 ,
bool V_189 , bool V_80 )
{
T_2 V_190 ;
V_190 = F_5 ( V_19 , V_116 ) ;
if ( ! V_80 ) {
V_190 &= ~ ( V_161 | V_191 |
V_192 ) ;
F_52 ( V_19 , V_193 |
V_194 , 0 ) ;
} else {
if ( V_189 ) {
V_190 |= V_191 ;
} else {
V_190 |= V_192 ;
F_52 ( V_19 , V_193 , 1 ) ;
}
V_190 |= V_161 ;
}
F_6 ( V_19 , V_116 , V_190 ) ;
}
static void F_91 ( int V_72 , struct V_18 * V_19 )
{
T_2 V_22 ;
V_22 = F_5 ( V_19 , V_137 ) ;
if ( V_72 == 0 )
V_22 &= ~ V_139 ;
else
V_22 |= V_139 ;
F_6 ( V_19 , V_137 , V_22 ) ;
}
static void F_92 ( struct V_18 * V_19 )
{
F_52 ( V_19 , V_194 , 1 ) ;
F_93 ( & V_19 -> V_195 ) ;
F_94 ( & V_19 -> V_195 ,
F_95 ( 70 ) ) ;
F_52 ( V_19 , V_194 , 0 ) ;
}
static void F_96 ( struct V_18 * V_19 )
{
if ( ! ( V_19 -> V_99 & V_117 ) )
return;
if ( V_19 -> V_196 ) {
F_92 ( V_19 ) ;
F_97 ( 2000 , 4000 ) ;
}
}
static int F_98 ( struct V_18 * V_19 , int V_197 )
{
struct V_198 * V_26 = V_19 -> V_26 ;
const struct V_23 * V_24 = V_19 -> V_24 ;
int V_32 ;
T_2 V_199 ;
if ( V_24 -> V_2 == V_10 ) {
F_44 ( & V_26 -> V_200 ) ;
V_19 -> V_201 = F_99 ( V_26 , V_197 , V_202 ) ;
if ( F_10 ( V_19 -> V_201 ) ) {
V_32 = F_34 ( V_19 -> V_201 ) ;
F_11 ( L_47 ,
V_33 , V_32 ) ;
V_19 -> V_201 = NULL ;
F_45 ( & V_26 -> V_200 ) ;
return V_32 ;
}
V_32 = F_100 ( V_19 -> V_201 , 0 , & V_199 ) ;
F_45 ( & V_26 -> V_200 ) ;
if ( V_32 ) {
F_11 ( L_48 , V_33 , V_32 ) ;
return V_32 ;
}
if ( V_199 & 0x07 ) {
F_11 ( L_49 , V_33 ) ;
return - V_5 ;
}
V_19 -> V_203 = V_19 -> V_201 -> V_197 ;
} else {
V_19 -> V_204 = F_101 ( V_26 -> V_26 , V_197 ,
& V_19 -> V_205 , V_206 ) ;
if ( ! V_19 -> V_204 ) {
V_32 = - V_207 ;
F_11 ( L_50 ,
V_33 , V_32 ) ;
return V_32 ;
}
V_19 -> V_203 = V_197 ;
}
return 0 ;
}
static void F_102 ( struct V_18 * V_19 )
{
struct V_198 * V_26 = V_19 -> V_26 ;
if ( V_19 -> V_201 ) {
F_103 ( V_19 -> V_201 , 0 ) ;
F_44 ( & V_26 -> V_200 ) ;
F_104 ( V_19 -> V_201 ) ;
V_19 -> V_201 = NULL ;
F_45 ( & V_26 -> V_200 ) ;
}
if ( V_19 -> V_204 )
F_105 ( V_26 -> V_26 , V_19 -> V_203 , V_19 -> V_204 ,
V_19 -> V_205 ) ;
}
static int F_106 ( struct V_18 * V_19 ,
const struct V_208 * V_209 )
{
const struct V_23 * V_24 = V_19 -> V_24 ;
struct V_210 V_211 ;
int V_212 ;
int V_32 ;
T_3 * V_22 ;
V_32 = F_107 ( & V_211 , V_209 ) ;
if ( V_32 ) {
F_11 ( L_51 , V_33 , V_32 ) ;
return V_32 ;
}
V_212 = ( V_211 . V_197 + 3 ) & ( ~ 0x3 ) ;
if ( V_212 > V_19 -> V_203 ) {
F_11 ( L_52 , V_33 ) ;
return - V_5 ;
}
if ( V_24 -> V_2 == V_10 ) {
V_22 = F_108 ( V_19 -> V_201 ) ;
if ( F_10 ( V_22 ) ) {
V_32 = F_34 ( V_22 ) ;
F_11 ( L_53 , V_33 , V_32 ) ;
return V_32 ;
}
} else {
V_22 = V_19 -> V_204 ;
}
V_22 [ 0 ] = V_211 . V_213 [ 1 ] ;
V_22 [ 1 ] = V_211 . V_213 [ 2 ] ;
V_22 [ 2 ] = V_211 . V_213 [ 0 ] ;
V_22 [ 3 ] = F_109 ( 7 ) ;
if ( F_110 ( V_209 -> type ) )
V_22 [ 3 ] |= F_109 ( 6 ) ;
if ( V_209 -> V_214 && V_209 -> V_215 )
V_22 [ 3 ] |= F_109 ( 5 ) ;
if ( V_211 . V_216 && V_211 . V_217 )
memcpy ( V_22 + 4 , V_211 . V_216 , V_211 . V_217 ) ;
if ( V_211 . V_197 < V_212 )
memset ( V_22 + V_211 . V_197 , 0xff , V_212 - V_211 . V_197 ) ;
return V_212 ;
}
static int F_111 ( T_3 * V_218 , const struct V_208 * V_209 )
{
T_3 * V_22 = V_209 -> V_214 ;
if ( V_22 && ( V_209 -> V_215 >= 1 ) ) {
* V_22 = V_218 [ 1 ] ;
return 1 ;
} else {
F_11 ( L_54 ,
V_33 , V_209 -> V_215 ) ;
return - V_5 ;
}
}
static int F_112 ( T_3 * V_218 , const struct V_208 * V_209 )
{
T_3 * V_22 = V_209 -> V_214 ;
if ( V_22 && ( V_209 -> V_215 >= 2 ) ) {
V_22 [ 0 ] = V_218 [ 1 ] ;
V_22 [ 1 ] = V_218 [ 2 ] ;
return 2 ;
} else {
F_11 ( L_54 ,
V_33 , V_209 -> V_215 ) ;
return - V_5 ;
}
}
static int F_113 ( T_3 * V_218 , const struct V_208 * V_209 )
{
if ( V_209 -> V_214 && V_209 -> V_215 )
memcpy ( V_209 -> V_214 , V_218 + 4 , V_209 -> V_215 ) ;
return V_209 -> V_215 ;
}
static int F_114 ( struct V_18 * V_19 , int V_212 )
{
const struct V_23 * V_24 = V_19 -> V_24 ;
int V_32 ;
T_2 V_219 ;
bool V_220 ;
if ( V_24 -> V_2 == V_10 ) {
V_32 = F_115 ( V_19 -> V_201 , 0 , & V_219 ) ;
if ( V_32 ) {
F_11 ( L_55 , V_33 , V_32 ) ;
return V_32 ;
}
} else {
V_219 = V_19 -> V_205 ;
}
F_93 ( & V_19 -> V_221 ) ;
F_96 ( V_19 ) ;
V_220 = F_116 (
V_19 -> V_70 , V_219 , V_212 ) ;
if ( V_220 ) {
V_32 = F_94 ( & V_19 -> V_221 ,
F_95 ( 200 ) ) ;
F_16 ( L_56 , V_32 ) ;
if ( V_32 == 0 )
V_32 = - V_222 ;
else
V_32 = V_212 ;
} else
V_32 = V_212 ;
return V_32 ;
}
static int F_117 ( struct V_18 * V_19 ,
T_3 * V_218 , int V_223 , int V_224 )
{
T_2 * V_225 , * V_226 , V_22 ;
int V_48 , V_227 = 0 , V_228 ;
T_2 V_229 ;
T_3 V_20 [ 16 ] ;
int V_230 = 0 ;
int V_231 = V_218 - V_19 -> V_214 ;
V_225 = ( T_2 * ) V_218 ;
V_226 = ( T_2 * ) V_20 ;
V_228 = ( V_223 + 3 ) >> 2 ;
if ( V_228 > 4 )
V_228 = 4 ;
if ( V_223 == 4 )
V_229 = 4 ;
else
V_229 = V_224 + 6 ;
if ( V_229 > 16 ) {
int V_232 ;
V_232 = V_229 - 16 ;
V_230 = V_231 - V_232 ;
}
for ( V_48 = V_228 - 1 ; V_48 >= 0 ; V_48 -- ) {
V_22 = F_5 ( V_19 , F_118 ( V_48 ) ) ;
* V_226 ++ = F_119 ( V_22 ) ;
F_16 ( L_57 , V_22 , F_119 ( V_22 ) ) ;
}
for ( V_48 = V_230 ; V_48 < 16 ; V_48 ++ )
V_218 [ V_227 ++ ] = V_20 [ V_48 ] ;
return V_227 ;
}
static int F_120 ( struct V_18 * V_19 ,
const struct V_208 * V_209 )
{
int V_212 , V_32 ;
int V_233 = V_19 -> V_72 -> V_176 *
F_4 ( V_19 -> V_86 ) / 8 ;
V_212 = F_106 ( V_19 , V_209 ) ;
if ( ! V_212 ) {
F_11 ( L_58 ,
V_33 , V_209 -> type ) ;
return - V_5 ;
}
if ( ( V_19 -> V_99 & V_117 ) && ( V_212 > V_233 ) ) {
F_11 ( L_59 ,
V_33 , V_212 ) ;
return - V_5 ;
}
V_32 = F_114 ( V_19 , V_212 ) ;
if ( V_32 < V_212 ) {
F_11 ( L_60 ,
V_33 , V_209 -> type , ( * ( T_3 * ) ( V_209 -> V_204 ) ) , V_212 ) ;
return - V_234 ;
}
return V_212 ;
}
static void F_121 ( struct V_18 * V_19 )
{
T_2 V_235 , V_236 ;
V_235 = F_5 ( V_19 , V_116 ) ;
V_236 = V_235 ;
V_236 &= ~ V_161 ;
F_6 ( V_19 , V_116 , V_236 ) ;
F_50 () ;
F_6 ( V_19 , V_152 , V_153 ) ;
F_50 () ;
F_6 ( V_19 , V_188 , 1 ) ;
F_50 () ;
F_6 ( V_19 , V_188 , 0 ) ;
F_50 () ;
F_6 ( V_19 , V_116 , V_235 ) ;
F_50 () ;
}
static void F_122 ( struct V_237 * V_238 )
{
struct V_18 * V_19 =
F_22 ( V_238 , struct V_18 , V_239 ) ;
T_2 V_240 = V_19 -> V_241 ;
F_123 ( L_61 , V_33 , V_240 ) ;
if ( V_240 & V_242 )
F_121 ( V_19 ) ;
V_19 -> V_241 = 0 ;
F_52 ( V_19 , V_151 , 1 ) ;
}
static void F_124 ( struct V_18 * V_19 )
{
T_2 V_240 ;
V_240 = F_5 ( V_19 , V_243 ) ;
if ( V_240 ) {
F_6 ( V_19 , V_243 , V_240 ) ;
F_6 ( V_19 , V_243 , 0 ) ;
V_19 -> V_241 |= V_244 ;
}
}
static void F_125 ( struct V_18 * V_19 )
{
T_2 V_240 ;
V_240 = F_5 ( V_19 , V_245 ) ;
if ( V_240 ) {
F_6 ( V_19 , V_245 , V_240 ) ;
V_19 -> V_241 |= V_246 ;
}
}
static void F_126 ( struct V_18 * V_19 )
{
T_2 V_240 ;
V_240 = F_5 ( V_19 , V_247 ) ;
if ( V_240 & ( V_248 |
V_249 |
V_250 |
V_251 |
V_252 ) ) {
F_6 ( V_19 , V_247 , V_240 ) ;
V_19 -> V_241 |= V_253 ;
}
}
static void F_127 ( struct V_18 * V_19 )
{
T_2 V_240 ;
V_240 = F_5 ( V_19 , V_254 ) ;
if ( V_240 ) {
F_6 ( V_19 , V_254 , V_240 ) ;
V_19 -> V_241 |= V_255 ;
if ( V_240 & V_256 )
V_19 -> V_241 |=
V_242 ;
}
}
static void F_128 ( struct V_18 * V_19 )
{
T_2 V_240 ;
V_240 = F_5 ( V_19 , V_257 ) ;
if ( V_240 & V_258 ) {
F_6 ( V_19 , V_257 , V_240 ) ;
V_19 -> V_241 |=
V_259 ;
}
}
static void F_129 ( struct V_18 * V_19 )
{
T_2 V_240 ;
V_240 = F_5 ( V_19 , V_260 ) ;
if ( V_240 & V_261 ) {
F_6 ( V_19 , V_260 , V_240 ) ;
V_19 -> V_241 |= V_262 ;
}
}
static void F_130 ( struct V_18 * V_19 )
{
F_52 ( V_19 , V_151 , 0 ) ;
F_129 ( V_19 ) ;
F_127 ( V_19 ) ;
F_124 ( V_19 ) ;
F_125 ( V_19 ) ;
F_128 ( V_19 ) ;
F_126 ( V_19 ) ;
F_131 ( V_19 -> V_263 , & V_19 -> V_239 ) ;
}
static T_4 F_132 ( int V_264 , void * V_265 )
{
struct V_18 * V_19 = V_265 ;
T_2 V_266 ;
unsigned long V_95 ;
if ( ! V_19 -> V_21 )
return V_267 ;
F_53 ( & V_19 -> V_96 , V_95 ) ;
V_266 = F_5 ( V_19 , V_97 ) ;
F_6 ( V_19 , V_97 , V_266 ) ;
F_54 ( & V_19 -> V_96 , V_95 ) ;
F_16 ( L_62 , V_266 , V_19 -> V_70 ) ;
if ( V_266 & V_268 )
F_130 ( V_19 ) ;
if ( V_266 & V_269 )
F_133 ( & V_19 -> V_195 ) ;
if ( V_266 & V_270 )
F_133 ( & V_19 -> V_221 ) ;
return V_267 ;
}
static int F_134 ( struct V_18 * V_19 ,
struct V_25 * V_271 )
{
V_19 -> V_272 = F_135 ( V_271 ,
L_63 ,
V_273 ) ;
if ( F_10 ( V_19 -> V_272 ) ) {
F_16 ( L_64 ,
F_34 ( V_19 -> V_272 ) ) ;
return F_34 ( V_19 -> V_272 ) ;
}
V_19 -> V_274 = F_135 ( V_271 , L_65 ,
V_275 ) ;
if ( F_10 ( V_19 -> V_274 ) ) {
F_16 ( L_66 , F_34 ( V_19 -> V_274 ) ) ;
return F_34 ( V_19 -> V_274 ) ;
}
return 0 ;
}
static int F_136 ( struct V_38 * V_39 ,
struct V_276 * V_277 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
int V_32 ;
if ( V_277 -> V_84 > V_19 -> V_278 )
return - V_5 ;
V_19 -> V_128 = V_277 -> V_128 ;
V_19 -> V_84 = V_277 -> V_84 ;
V_19 -> V_86 = V_277 -> V_86 ;
V_19 -> V_99 = V_277 -> V_99 ;
V_32 = F_134 ( V_19 , & V_277 -> V_26 ) ;
if ( V_32 )
return V_32 ;
F_16 ( L_27 , V_19 -> V_70 ) ;
if ( V_19 -> V_26 )
F_137 ( V_19 -> V_26 ) ;
return 0 ;
}
static int F_138 ( struct V_38 * V_39 ,
struct V_276 * V_277 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
V_19 -> V_279 = NULL ;
F_16 ( L_27 , V_19 -> V_70 ) ;
if ( V_19 -> V_26 )
F_137 ( V_19 -> V_26 ) ;
return 0 ;
}
static T_5 F_139 ( struct V_38 * V_39 ,
const struct V_208 * V_209 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
int V_32 ;
if ( ! V_209 || ! V_19 -> V_196 )
return - V_5 ;
F_44 ( & V_19 -> V_280 ) ;
V_32 = F_140 ( V_19 -> V_70 , V_209 ) ;
F_45 ( & V_19 -> V_280 ) ;
return V_32 ;
}
static int F_141 ( struct V_18 * V_19 ,
struct V_279 * V_281 )
{
struct V_25 * V_26 = & V_19 -> V_27 -> V_26 ;
struct V_282 * V_283 ;
T_2 V_284 [ 4 ] ;
int V_32 , V_48 , V_212 , V_285 ;
V_283 = F_142 ( V_281 , L_67 , & V_212 ) ;
if ( ! V_283 ) {
F_143 ( V_26 , L_68 ) ;
return - V_5 ;
}
V_285 = V_212 / sizeof( T_2 ) ;
if ( V_285 < 1 || V_285 > 4 ) {
F_144 ( V_26 , L_69 ) ;
return - V_5 ;
}
V_19 -> V_278 = V_285 ;
V_32 = F_145 ( V_281 , L_67 , V_284 ,
V_285 ) ;
if ( V_32 ) {
F_144 ( V_26 , L_70 ) ;
return V_32 ;
}
for ( V_48 = 0 ; V_48 < F_146 ( V_286 ) ; V_48 ++ ) {
const int * V_287 = V_286 [ V_48 ] ;
int V_227 ;
for ( V_227 = 0 ; V_227 < V_285 ; V_227 ++ ) {
if ( V_287 [ V_227 ] != V_284 [ V_227 ] )
break;
}
if ( V_227 == V_285 ) {
V_19 -> V_157 = V_48 ;
return 0 ;
}
}
return - V_5 ;
}
static int F_147 ( struct V_18 * V_19 )
{
struct V_25 * V_26 = & V_19 -> V_27 -> V_26 ;
struct V_279 * V_288 = V_26 -> V_289 ;
struct V_279 * V_290 , * V_279 ;
int V_32 ;
V_32 = F_148 ( V_288 , L_71 , & V_19 -> V_70 ) ;
if ( V_32 ) {
F_144 ( V_26 , L_72 ,
V_33 , V_32 ) ;
return V_32 ;
}
V_290 = F_149 ( V_288 , NULL ) ;
if ( ! V_290 ) {
F_143 ( V_26 , L_73 , V_33 ) ;
return 0 ;
}
V_32 = F_141 ( V_19 , V_290 ) ;
if ( V_32 ) {
F_144 ( V_26 , L_74 ,
V_33 , V_32 ) ;
goto V_71;
}
V_279 = F_150 ( V_290 ) ;
if ( ! V_279 ) {
F_144 ( V_26 , L_75 , V_33 ) ;
V_32 = - V_65 ;
goto V_71;
}
V_19 -> V_279 = V_279 ;
if ( F_151 ( V_288 , L_76 ) ) {
V_19 -> V_291 = F_152 ( V_288 ,
L_76 ) ;
if ( F_10 ( V_19 -> V_291 ) ) {
F_144 ( V_26 , L_77 ,
V_33 ) ;
V_32 = F_34 ( V_19 -> V_291 ) ;
}
}
F_153 ( V_279 ) ;
V_71:
F_153 ( V_290 ) ;
return V_32 ;
}
int F_154 ( struct V_292 * V_292 )
{
struct V_18 * V_19 = NULL ;
struct V_293 * V_27 = V_292 -> V_27 ;
int V_32 ;
V_19 = F_155 ( & V_27 -> V_26 , sizeof( * V_19 ) , V_206 ) ;
if ( ! V_19 ) {
F_11 ( L_78 ,
V_33 ) ;
V_32 = - V_207 ;
goto V_52;
}
V_19 -> V_27 = V_27 ;
V_32 = F_147 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_79 , V_33 ) ;
goto V_52;
}
V_19 -> V_21 = F_156 ( V_27 , L_80 , L_81 ) ;
if ( F_10 ( V_19 -> V_21 ) ) {
F_11 ( L_82 , V_33 ) ;
V_32 = F_34 ( V_19 -> V_21 ) ;
goto V_52;
}
V_19 -> V_24 = F_8 ( V_19 ) ;
if ( ! V_19 -> V_24 ) {
V_32 = - V_5 ;
F_11 ( L_83 , V_33 ) ;
goto V_52;
}
V_19 -> V_21 += V_19 -> V_24 -> V_45 -> V_294 ;
V_32 = F_28 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_84 , V_33 ) ;
goto V_52;
}
V_32 = F_32 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_85 , V_33 ) ;
goto V_52;
}
V_19 -> V_214 = F_155 ( & V_27 -> V_26 , V_295 , V_206 ) ;
if ( ! V_19 -> V_214 ) {
F_11 ( L_86 , V_33 ) ;
goto V_52;
}
F_157 ( & V_19 -> V_221 ) ;
F_157 ( & V_19 -> V_195 ) ;
F_158 ( & V_19 -> V_296 ) ;
F_158 ( & V_19 -> V_280 ) ;
F_158 ( & V_19 -> V_81 ) ;
F_159 ( & V_19 -> V_96 ) ;
V_19 -> V_263 = F_160 ( L_87 , 0 ) ;
F_161 ( & V_19 -> V_239 , F_122 ) ;
V_292 -> V_39 = & V_19 -> V_1 ;
V_292 -> V_70 = V_19 -> V_70 ;
F_16 ( L_88 , V_19 -> V_70 ) ;
return 0 ;
V_52:
return V_32 ;
}
void F_162 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_16 ( L_9 ) ;
F_102 ( V_19 ) ;
if ( V_19 -> V_263 ) {
F_163 ( V_19 -> V_263 ) ;
F_164 ( V_19 -> V_263 ) ;
V_19 -> V_263 = NULL ;
}
F_165 ( & V_19 -> V_81 ) ;
F_165 ( & V_19 -> V_280 ) ;
F_165 ( & V_19 -> V_296 ) ;
}
int F_166 ( struct V_38 * V_39 ,
struct V_198 * V_26 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
struct V_293 * V_27 = V_19 -> V_27 ;
int V_32 ;
V_19 -> V_264 = F_167 ( V_27 -> V_26 . V_289 , 0 ) ;
if ( V_19 -> V_264 < 0 ) {
V_32 = V_19 -> V_264 ;
F_144 ( V_26 -> V_26 , L_89 , V_32 ) ;
return V_32 ;
}
V_32 = F_168 ( & V_27 -> V_26 , V_19 -> V_264 ,
F_132 , V_297 | V_298 ,
L_90 , V_19 ) ;
if ( V_32 < 0 ) {
F_144 ( & V_27 -> V_26 , L_91 ,
V_19 -> V_264 , V_32 ) ;
return V_32 ;
}
V_19 -> V_26 = V_26 ;
V_32 = F_98 ( V_19 , V_295 ) ;
if ( V_32 ) {
F_11 ( L_92 , V_33 , V_32 ) ;
return V_32 ;
}
return 0 ;
}
int F_169 ( struct V_38 * V_39 , bool V_299 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
int V_32 ;
if ( ! V_19 -> V_300 ) {
V_39 -> V_26 = & V_19 -> V_27 -> V_26 ;
V_39 -> V_301 = & V_302 ;
V_32 = F_170 ( V_39 ) ;
if ( V_32 )
return V_32 ;
V_19 -> V_300 = true ;
if ( V_299 && V_19 -> V_279 ) {
if ( ! F_171 ( V_19 -> V_279 ) )
if ( ! F_172 ( V_19 -> V_279 ) )
return - V_303 ;
}
}
return 0 ;
}
void F_173 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
if ( V_19 -> V_300 ) {
F_174 ( V_39 ) ;
V_39 -> V_26 = NULL ;
V_39 -> V_301 = NULL ;
V_19 -> V_300 = false ;
}
}
int F_175 ( struct V_38 * V_39 ,
const struct V_208 * V_209 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_43 ( V_19 , 1 ) ;
if ( ! ( V_209 -> V_95 & V_304 ) )
F_91 ( 0 , V_19 ) ;
V_19 -> V_305 = F_5 ( V_19 , V_116 ) ;
F_6 ( V_19 , V_116 ,
V_19 -> V_305 |
V_192 |
V_161 ) ;
F_52 ( V_19 , V_306 , 1 ) ;
return 0 ;
}
void F_176 ( struct V_38 * V_39 ,
const struct V_208 * V_209 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_52 ( V_19 , V_306 , 0 ) ;
F_6 ( V_19 , V_116 , V_19 -> V_305 ) ;
if ( ! ( V_209 -> V_95 & V_304 ) )
F_91 ( 1 , V_19 ) ;
F_43 ( V_19 , 0 ) ;
}
int F_177 ( struct V_38 * V_39 ,
const struct V_208 * V_209 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
return F_120 ( V_19 , V_209 ) ;
}
int F_178 ( struct V_38 * V_39 ,
const struct V_208 * V_209 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
const struct V_23 * V_24 = V_19 -> V_24 ;
int V_307 , V_223 , V_308 , V_309 ;
int V_310 , V_311 , V_224 , V_32 = 0 ;
char V_312 ;
int V_313 = V_209 -> V_215 ;
T_3 * V_218 ;
if ( V_313 <= 2 ) {
V_310 = 1 ;
V_224 = V_313 ;
V_223 = 4 ;
} else {
V_310 = 0 ;
V_307 = 10 ;
if ( V_313 < V_307 )
V_224 = V_313 ;
else
V_224 = V_307 ;
V_223 = V_307 + 6 ;
}
V_218 = V_19 -> V_214 ;
V_309 = 0 ;
while ( ! V_309 ) {
T_3 V_314 [ 2 ] = { V_224 & 0xff , V_224 >> 8 } ;
struct V_208 V_315 = {
. V_128 = V_209 -> V_128 ,
. type = V_316 ,
. V_317 = 2 ,
. V_204 = V_314 ,
} ;
F_16 ( L_93 ,
V_313 , V_224 , V_223 ) ;
V_32 = F_120 ( V_19 , & V_315 ) ;
if ( V_32 < 2 ) {
F_11 ( L_94 ,
V_33 , V_32 ) ;
return - V_5 ;
}
if ( ( V_24 -> V_2 == V_10 ) &&
( V_24 -> V_3 >= V_318 ) ) {
F_6 ( V_19 , V_319 ,
V_320 ) ;
F_50 () ;
F_6 ( V_19 , V_319 , 0 ) ;
F_50 () ;
}
V_32 = F_120 ( V_19 , V_209 ) ;
if ( V_32 < V_209 -> V_317 ) {
F_11 ( L_95 , V_33 , V_32 ) ;
return V_32 ;
}
V_308 = F_117 ( V_19 , V_218 , V_223 , V_224 ) ;
if ( V_308 <= 0 )
return 0 ;
if ( V_310 )
break;
if ( V_313 <= V_307 ) {
V_311 = V_307 - V_313 ;
V_309 = 1 ;
} else {
V_311 = 0 ;
V_313 -= V_307 ;
}
if ( ! V_309 ) {
V_308 -= 2 ;
V_308 -= V_311 ;
V_218 += V_308 ;
V_307 = 14 ;
if ( V_313 < V_307 )
V_224 += V_313 ;
else
V_224 += V_307 ;
F_16 ( L_96 , V_218 , V_308 , V_311 ) ;
}
}
if ( V_224 < 10 && ! V_310 )
V_218 = V_19 -> V_214 + ( 10 - V_313 ) ;
else
V_218 = V_19 -> V_214 ;
V_312 = V_218 [ 0 ] ;
switch ( V_312 ) {
case V_321 :
F_11 ( L_97 , V_33 ) ;
V_32 = 0 ;
break;
case V_322 :
case V_323 :
V_32 = F_111 ( V_218 , V_209 ) ;
break;
case V_324 :
case V_325 :
V_32 = F_112 ( V_218 , V_209 ) ;
break;
case V_326 :
case V_327 :
V_32 = F_113 ( V_218 , V_209 ) ;
break;
default:
F_179 ( L_98 , V_33 ) ;
V_32 = 0 ;
}
return V_32 ;
}
void F_180 ( struct V_38 * V_39 , T_2 V_219 ,
T_2 V_212 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_6 ( V_19 , V_328 , V_219 ) ;
F_6 ( V_19 , V_329 , V_212 ) ;
F_6 ( V_19 , V_330 , 1 ) ;
F_50 () ;
}
int F_181 ( struct V_38 * V_39 ,
struct V_331 * V_332 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
const struct V_23 * V_24 = V_19 -> V_24 ;
struct V_30 * V_333 , * V_334 ;
int V_32 ;
V_32 = F_182 ( V_332 ,
& V_333 , & V_334 ) ;
if ( V_32 ) {
F_183 ( L_99 ,
V_33 ) ;
return 0 ;
}
V_32 = F_184 ( V_19 -> V_64 , V_333 ) ;
if ( V_32 ) {
F_11 ( L_100 ,
V_33 , V_32 ) ;
goto exit;
}
V_32 = F_184 ( V_19 -> V_66 , V_334 ) ;
if ( V_32 ) {
F_11 ( L_101 ,
V_33 , V_32 ) ;
goto exit;
}
if ( V_24 -> V_2 == V_8 ) {
V_32 = F_184 ( V_19 -> V_69 , V_334 ) ;
if ( V_32 ) {
F_11 ( L_102 ,
V_33 , V_32 ) ;
goto exit;
}
V_32 = F_184 ( V_19 -> V_68 , V_333 ) ;
if ( V_32 ) {
F_11 ( L_103 ,
V_33 , V_32 ) ;
goto exit;
}
}
exit:
return V_32 ;
}
int F_185 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_90 ( V_19 ,
! ! ( V_19 -> V_99 & V_117 ) , true ) ;
return 0 ;
}
int F_186 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_90 ( V_19 ,
! ! ( V_19 -> V_99 & V_117 ) , false ) ;
F_89 ( V_19 ) ;
return 0 ;
}
static void F_187 ( struct V_18 * V_19 , bool V_80 )
{
enum V_335 V_336 ;
if ( ! V_19 -> V_291 )
return;
V_336 = V_80 ? V_337 : V_338 ;
F_188 ( V_19 -> V_291 , V_339 ,
V_340 ,
F_189 ( V_336 ) ) ;
}
int F_190 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
T_2 V_114 = 0 , V_115 = 0 ;
int V_32 = 0 ;
F_44 ( & V_19 -> V_296 ) ;
if ( V_19 -> V_196 ) {
F_16 ( L_104 ) ;
goto V_82;
}
F_187 ( V_19 , true ) ;
V_32 = F_46 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_105 , V_33 , V_32 ) ;
goto V_82;
}
V_32 = F_26 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_106 ,
V_33 , V_32 ) ;
goto V_82;
}
V_32 = F_36 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_107 , V_33 , V_32 ) ;
goto V_341;
}
F_49 ( V_19 ) ;
V_32 = F_191 ( V_19 -> V_70 ,
V_19 -> V_73 * 8 ,
V_19 -> V_76 ,
& V_114 , & V_115 ) ;
F_37 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_108 , V_33 , V_32 ) ;
goto V_341;
}
V_32 = F_43 ( V_19 , 1 ) ;
if ( V_32 ) {
F_11 ( L_109 , V_33 , V_32 ) ;
goto V_341;
}
V_32 = F_192 ( & V_19 -> V_27 -> V_26 ) ;
if ( V_32 ) {
F_11 ( L_110 ,
V_33 , V_32 ) ;
goto V_342;
}
F_73 ( V_19 ) ;
F_89 ( V_19 ) ;
F_58 ( V_19 , true , V_114 , V_115 ) ;
if ( V_19 -> V_272 )
F_193 ( V_19 -> V_272 , 1 ) ;
V_19 -> V_196 = true ;
F_45 ( & V_19 -> V_296 ) ;
return 0 ;
V_342:
F_43 ( V_19 , 0 ) ;
V_341:
F_23 ( V_19 ) ;
V_82:
F_45 ( & V_19 -> V_296 ) ;
return V_32 ;
}
int F_194 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_44 ( & V_19 -> V_296 ) ;
if ( ! V_19 -> V_196 ) {
F_16 ( L_111 ) ;
goto V_82;
}
F_58 ( V_19 , false , 0 , 0 ) ;
if ( V_19 -> V_272 )
F_193 ( V_19 -> V_272 , 0 ) ;
F_195 ( & V_19 -> V_27 -> V_26 ) ;
F_196 ( V_19 -> V_70 ) ;
F_43 ( V_19 , 0 ) ;
F_23 ( V_19 ) ;
F_187 ( V_19 , false ) ;
F_16 ( L_112 ) ;
V_19 -> V_196 = false ;
V_82:
F_45 ( & V_19 -> V_296 ) ;
return 0 ;
}
int F_197 ( struct V_38 * V_39 ,
struct V_83 * V_72 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
if ( V_19 -> V_72 ) {
F_198 ( V_19 -> V_26 , V_19 -> V_72 ) ;
V_19 -> V_72 = NULL ;
}
V_19 -> V_72 = F_199 ( V_19 -> V_26 , V_72 ) ;
if ( F_10 ( V_19 -> V_72 ) ) {
F_11 ( L_113 , V_33 ) ;
return F_34 ( V_19 -> V_72 ) ;
}
return 0 ;
}
struct V_343 * F_200 ( struct V_38 * V_39 ,
unsigned long * V_344 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
struct V_343 * V_345 ;
V_345 = F_171 ( V_19 -> V_279 ) ;
if ( V_344 )
* V_344 = V_19 -> V_99 ;
return V_345 ;
}
struct V_346 * F_201 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
return F_172 ( V_19 -> V_279 ) ;
}
