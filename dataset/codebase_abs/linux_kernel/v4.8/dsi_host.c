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
static void F_47 ( struct V_18 * V_19 )
{
F_16 ( L_9 ) ;
F_6 ( V_19 , V_89 , V_90 ) ;
F_48 () ;
F_49 ( 1000 ) ;
F_6 ( V_19 , V_89 , 0 ) ;
F_49 ( 100 ) ;
}
static void F_50 ( struct V_18 * V_19 , T_2 V_91 , int V_78 )
{
T_2 V_92 ;
unsigned long V_93 ;
F_51 ( & V_19 -> V_94 , V_93 ) ;
V_92 = F_5 ( V_19 , V_95 ) ;
if ( V_78 )
V_92 |= V_91 ;
else
V_92 &= ~ V_91 ;
F_16 ( L_44 , V_92 , V_78 ) ;
F_6 ( V_19 , V_95 , V_92 ) ;
F_52 ( & V_19 -> V_94 , V_93 ) ;
}
static inline enum V_96 F_53 ( const T_2 V_97 )
{
if ( V_97 & V_98 )
return V_99 ;
else if ( V_97 & V_100 )
return V_101 ;
return V_102 ;
}
static inline enum V_103 F_54 (
const enum V_12 V_104 )
{
switch ( V_104 ) {
case V_17 : return V_105 ;
case V_16 : return V_106 ;
case V_15 : return V_107 ;
case V_14 : return V_108 ;
default: return V_105 ;
}
}
static inline enum V_109 F_55 (
const enum V_12 V_104 )
{
switch ( V_104 ) {
case V_17 : return V_110 ;
case V_15 :
case V_16 : return V_107 ;
case V_14 : return V_111 ;
default: return V_110 ;
}
}
static void F_56 ( struct V_18 * V_19 , bool V_78 ,
T_2 V_112 , T_2 V_113 )
{
T_2 V_93 = V_19 -> V_97 ;
enum V_12 V_104 = V_19 -> V_84 ;
const struct V_23 * V_24 = V_19 -> V_24 ;
T_2 V_22 = 0 ;
if ( ! V_78 ) {
F_6 ( V_19 , V_114 , 0 ) ;
return;
}
if ( V_93 & V_115 ) {
if ( V_93 & V_116 )
V_22 |= V_117 ;
if ( V_93 & V_118 )
V_22 |= V_119 ;
if ( V_93 & V_120 )
V_22 |= V_121 ;
if ( V_93 & V_122 )
V_22 |= V_123 ;
V_22 |= V_124 |
V_125 ;
V_22 |= F_57 ( F_53 ( V_93 ) ) ;
V_22 |= F_58 ( F_54 ( V_104 ) ) ;
V_22 |= F_59 ( V_19 -> V_126 ) ;
F_6 ( V_19 , V_127 , V_22 ) ;
V_22 = F_60 ( V_128 ) ;
F_6 ( V_19 , V_129 , 0 ) ;
} else {
V_22 = F_61 ( V_128 ) ;
V_22 |= F_62 ( F_55 ( V_104 ) ) ;
F_6 ( V_19 , V_130 , V_22 ) ;
V_22 = F_63 ( V_131 ) |
F_64 (
V_132 ) ;
V_22 |= V_133 ;
F_6 ( V_19 , V_134 , V_22 ) ;
}
F_6 ( V_19 , V_135 ,
V_136 |
V_137 ) ;
V_22 = 0 ;
V_22 |= V_138 ;
V_22 |= F_65 ( V_139 ) ;
V_22 |= F_66 ( V_140 ) ;
V_22 |= F_67 ( V_19 -> V_126 ) ;
if ( ( V_24 -> V_2 == V_10 ) &&
( V_24 -> V_3 >= V_141 ) )
V_22 |= V_142 ;
F_6 ( V_19 , V_143 , V_22 ) ;
V_22 = F_68 ( V_113 ) |
F_69 ( V_112 ) ;
F_6 ( V_19 , V_144 , V_22 ) ;
V_22 = 0 ;
if ( ! ( V_93 & V_145 ) )
V_22 |= V_146 ;
F_6 ( V_19 , V_147 , V_22 ) ;
F_6 ( V_19 , V_148 , 0x13ff3fe0 ) ;
F_50 ( V_19 , V_149 , 1 ) ;
F_6 ( V_19 , V_150 , V_151 ) ;
V_22 = V_152 ;
F_16 ( L_45 , V_19 -> V_82 ) ;
V_22 |= ( ( V_153 << V_19 -> V_82 ) - V_153 ) ;
F_6 ( V_19 , V_154 ,
F_70 ( V_19 -> V_155 ) ) ;
if ( ! ( V_93 & V_156 ) )
F_6 ( V_19 , V_157 ,
V_158 ) ;
V_22 |= V_159 ;
F_6 ( V_19 , V_114 , V_22 ) ;
}
static void F_71 ( struct V_18 * V_19 )
{
struct V_81 * V_70 = V_19 -> V_70 ;
T_2 V_160 = 0 , V_161 = 0 ;
T_2 V_162 = V_70 -> V_163 ;
T_2 V_164 = V_70 -> V_165 ;
T_2 V_166 = V_70 -> V_167 - V_70 -> V_168 ;
T_2 V_169 = V_70 -> V_170 - V_70 -> V_171 ;
T_2 V_172 = V_162 - V_70 -> V_168 ;
T_2 V_173 = V_172 + V_70 -> V_174 ;
T_2 va_start = V_164 - V_70 -> V_171 ;
T_2 va_end = va_start + V_70 -> V_175 ;
T_2 V_176 ;
F_16 ( L_9 ) ;
if ( V_19 -> V_97 & V_115 ) {
F_6 ( V_19 , V_177 ,
F_72 ( V_172 ) |
F_73 ( V_173 ) ) ;
F_6 ( V_19 , V_178 ,
F_74 ( va_start ) |
F_75 ( va_end ) ) ;
F_6 ( V_19 , V_179 ,
F_76 ( V_162 - 1 ) |
F_77 ( V_164 - 1 ) ) ;
F_6 ( V_19 , V_180 ,
F_78 ( V_160 ) |
F_79 ( V_166 ) ) ;
F_6 ( V_19 , V_181 , 0 ) ;
F_6 ( V_19 , V_182 ,
F_80 ( V_161 ) |
F_81 ( V_169 ) ) ;
} else {
V_176 = V_70 -> V_174 * F_4 ( V_19 -> V_84 ) / 8 + 1 ;
F_6 ( V_19 , V_183 ,
F_82 ( V_176 ) |
F_83 (
V_19 -> V_126 ) |
F_84 (
V_184 ) ) ;
F_6 ( V_19 , V_185 ,
F_85 ( V_70 -> V_174 ) |
F_86 ( V_70 -> V_175 ) ) ;
}
}
static void F_87 ( struct V_18 * V_19 )
{
F_6 ( V_19 , V_150 , V_151 ) ;
F_48 () ;
F_6 ( V_19 , V_186 , 1 ) ;
F_48 () ;
F_6 ( V_19 , V_186 , 0 ) ;
}
static void F_88 ( struct V_18 * V_19 ,
bool V_187 , bool V_78 )
{
T_2 V_188 ;
V_188 = F_5 ( V_19 , V_114 ) ;
if ( ! V_78 ) {
V_188 &= ~ ( V_159 | V_189 |
V_190 ) ;
F_50 ( V_19 , V_191 |
V_192 , 0 ) ;
} else {
if ( V_187 ) {
V_188 |= V_189 ;
} else {
V_188 |= V_190 ;
F_50 ( V_19 , V_191 , 1 ) ;
}
V_188 |= V_159 ;
}
F_6 ( V_19 , V_114 , V_188 ) ;
}
static void F_89 ( int V_70 , struct V_18 * V_19 )
{
T_2 V_22 ;
V_22 = F_5 ( V_19 , V_135 ) ;
if ( V_70 == 0 )
V_22 &= ~ V_137 ;
else
V_22 |= V_137 ;
F_6 ( V_19 , V_135 , V_22 ) ;
}
static void F_90 ( struct V_18 * V_19 )
{
F_50 ( V_19 , V_192 , 1 ) ;
F_91 ( & V_19 -> V_193 ) ;
F_92 ( & V_19 -> V_193 ,
F_93 ( 70 ) ) ;
F_50 ( V_19 , V_192 , 0 ) ;
}
static void F_94 ( struct V_18 * V_19 )
{
if ( ! ( V_19 -> V_97 & V_115 ) )
return;
if ( V_19 -> V_194 ) {
F_90 ( V_19 ) ;
F_95 ( 2000 , 4000 ) ;
}
}
static int F_96 ( struct V_18 * V_19 , int V_195 )
{
struct V_196 * V_26 = V_19 -> V_26 ;
const struct V_23 * V_24 = V_19 -> V_24 ;
int V_32 ;
T_2 V_197 ;
if ( V_24 -> V_2 == V_10 ) {
F_42 ( & V_26 -> V_198 ) ;
V_19 -> V_199 = F_97 ( V_26 , V_195 , V_200 ) ;
if ( F_10 ( V_19 -> V_199 ) ) {
V_32 = F_32 ( V_19 -> V_199 ) ;
F_11 ( L_46 ,
V_33 , V_32 ) ;
V_19 -> V_199 = NULL ;
F_43 ( & V_26 -> V_198 ) ;
return V_32 ;
}
V_32 = F_98 ( V_19 -> V_199 , 0 , & V_197 ) ;
F_43 ( & V_26 -> V_198 ) ;
if ( V_32 ) {
F_11 ( L_47 , V_33 , V_32 ) ;
return V_32 ;
}
if ( V_197 & 0x07 ) {
F_11 ( L_48 , V_33 ) ;
return - V_5 ;
}
V_19 -> V_201 = V_19 -> V_199 -> V_195 ;
} else {
V_19 -> V_202 = F_99 ( V_26 -> V_26 , V_195 ,
& V_19 -> V_203 , V_204 ) ;
if ( ! V_19 -> V_202 ) {
V_32 = - V_205 ;
F_11 ( L_49 ,
V_33 , V_32 ) ;
return V_32 ;
}
V_19 -> V_201 = V_195 ;
}
return 0 ;
}
static void F_100 ( struct V_18 * V_19 )
{
struct V_196 * V_26 = V_19 -> V_26 ;
if ( V_19 -> V_199 ) {
F_101 ( V_19 -> V_199 , 0 ) ;
F_42 ( & V_26 -> V_198 ) ;
F_102 ( V_19 -> V_199 ) ;
V_19 -> V_199 = NULL ;
F_43 ( & V_26 -> V_198 ) ;
}
if ( V_19 -> V_202 )
F_103 ( V_26 -> V_26 , V_19 -> V_201 , V_19 -> V_202 ,
V_19 -> V_203 ) ;
}
static int F_104 ( struct V_18 * V_19 ,
const struct V_206 * V_207 )
{
const struct V_23 * V_24 = V_19 -> V_24 ;
struct V_208 V_209 ;
int V_210 ;
int V_32 ;
T_3 * V_22 ;
V_32 = F_105 ( & V_209 , V_207 ) ;
if ( V_32 ) {
F_11 ( L_50 , V_33 , V_32 ) ;
return V_32 ;
}
V_210 = ( V_209 . V_195 + 3 ) & ( ~ 0x3 ) ;
if ( V_210 > V_19 -> V_201 ) {
F_11 ( L_51 , V_33 ) ;
return - V_5 ;
}
if ( V_24 -> V_2 == V_10 ) {
V_22 = F_106 ( V_19 -> V_199 ) ;
if ( F_10 ( V_22 ) ) {
V_32 = F_32 ( V_22 ) ;
F_11 ( L_52 , V_33 , V_32 ) ;
return V_32 ;
}
} else {
V_22 = V_19 -> V_202 ;
}
V_22 [ 0 ] = V_209 . V_211 [ 1 ] ;
V_22 [ 1 ] = V_209 . V_211 [ 2 ] ;
V_22 [ 2 ] = V_209 . V_211 [ 0 ] ;
V_22 [ 3 ] = F_107 ( 7 ) ;
if ( F_108 ( V_207 -> type ) )
V_22 [ 3 ] |= F_107 ( 6 ) ;
if ( V_207 -> V_212 && V_207 -> V_213 )
V_22 [ 3 ] |= F_107 ( 5 ) ;
if ( V_209 . V_214 && V_209 . V_215 )
memcpy ( V_22 + 4 , V_209 . V_214 , V_209 . V_215 ) ;
if ( V_209 . V_195 < V_210 )
memset ( V_22 + V_209 . V_195 , 0xff , V_210 - V_209 . V_195 ) ;
if ( V_24 -> V_2 == V_10 )
F_109 ( V_19 -> V_199 ) ;
return V_210 ;
}
static int F_110 ( T_3 * V_216 , const struct V_206 * V_207 )
{
T_3 * V_22 = V_207 -> V_212 ;
if ( V_22 && ( V_207 -> V_213 >= 1 ) ) {
* V_22 = V_216 [ 1 ] ;
return 1 ;
} else {
F_11 ( L_53 ,
V_33 , V_207 -> V_213 ) ;
return - V_5 ;
}
}
static int F_111 ( T_3 * V_216 , const struct V_206 * V_207 )
{
T_3 * V_22 = V_207 -> V_212 ;
if ( V_22 && ( V_207 -> V_213 >= 2 ) ) {
V_22 [ 0 ] = V_216 [ 1 ] ;
V_22 [ 1 ] = V_216 [ 2 ] ;
return 2 ;
} else {
F_11 ( L_53 ,
V_33 , V_207 -> V_213 ) ;
return - V_5 ;
}
}
static int F_112 ( T_3 * V_216 , const struct V_206 * V_207 )
{
if ( V_207 -> V_212 && V_207 -> V_213 )
memcpy ( V_207 -> V_212 , V_216 + 4 , V_207 -> V_213 ) ;
return V_207 -> V_213 ;
}
static int F_113 ( struct V_18 * V_19 , int V_210 )
{
const struct V_23 * V_24 = V_19 -> V_24 ;
int V_32 ;
T_2 V_217 ;
bool V_218 ;
if ( V_24 -> V_2 == V_10 ) {
V_32 = F_114 ( V_19 -> V_199 , 0 , & V_217 ) ;
if ( V_32 ) {
F_11 ( L_54 , V_33 , V_32 ) ;
return V_32 ;
}
} else {
V_217 = V_19 -> V_203 ;
}
F_91 ( & V_19 -> V_219 ) ;
F_94 ( V_19 ) ;
V_218 = F_115 (
V_19 -> V_68 , V_217 , V_210 ) ;
if ( V_218 ) {
V_32 = F_92 ( & V_19 -> V_219 ,
F_93 ( 200 ) ) ;
F_16 ( L_55 , V_32 ) ;
if ( V_32 == 0 )
V_32 = - V_220 ;
else
V_32 = V_210 ;
} else
V_32 = V_210 ;
return V_32 ;
}
static int F_116 ( struct V_18 * V_19 ,
T_3 * V_216 , int V_221 , int V_222 )
{
T_2 * V_223 , * V_224 , V_22 ;
int V_48 , V_225 = 0 , V_226 ;
T_2 V_227 ;
T_3 V_20 [ 16 ] ;
int V_228 = 0 ;
int V_229 = V_216 - V_19 -> V_212 ;
V_223 = ( T_2 * ) V_216 ;
V_224 = ( T_2 * ) V_20 ;
V_226 = ( V_221 + 3 ) >> 2 ;
if ( V_226 > 4 )
V_226 = 4 ;
if ( V_221 == 4 )
V_227 = 4 ;
else
V_227 = V_222 + 6 ;
if ( V_227 > 16 ) {
int V_230 ;
V_230 = V_227 - 16 ;
V_228 = V_229 - V_230 ;
}
for ( V_48 = V_226 - 1 ; V_48 >= 0 ; V_48 -- ) {
V_22 = F_5 ( V_19 , F_117 ( V_48 ) ) ;
* V_224 ++ = F_118 ( V_22 ) ;
F_16 ( L_56 , V_22 , F_118 ( V_22 ) ) ;
}
for ( V_48 = V_228 ; V_48 < 16 ; V_48 ++ )
V_216 [ V_225 ++ ] = V_20 [ V_48 ] ;
return V_225 ;
}
static int F_119 ( struct V_18 * V_19 ,
const struct V_206 * V_207 )
{
int V_210 , V_32 ;
int V_231 = V_19 -> V_70 -> V_174 *
F_4 ( V_19 -> V_84 ) / 8 ;
V_210 = F_104 ( V_19 , V_207 ) ;
if ( ! V_210 ) {
F_11 ( L_57 ,
V_33 , V_207 -> type ) ;
return - V_5 ;
}
if ( ( V_19 -> V_97 & V_115 ) && ( V_210 > V_231 ) ) {
F_11 ( L_58 ,
V_33 , V_210 ) ;
return - V_5 ;
}
V_32 = F_113 ( V_19 , V_210 ) ;
if ( V_32 < V_210 ) {
F_11 ( L_59 ,
V_33 , V_207 -> type , ( * ( T_3 * ) ( V_207 -> V_202 ) ) , V_210 ) ;
return - V_232 ;
}
return V_210 ;
}
static void F_120 ( struct V_18 * V_19 )
{
T_2 V_233 , V_234 ;
V_233 = F_5 ( V_19 , V_114 ) ;
V_234 = V_233 ;
V_234 &= ~ V_159 ;
F_6 ( V_19 , V_114 , V_234 ) ;
F_48 () ;
F_6 ( V_19 , V_150 , V_151 ) ;
F_48 () ;
F_6 ( V_19 , V_186 , 1 ) ;
F_48 () ;
F_6 ( V_19 , V_186 , 0 ) ;
F_48 () ;
F_6 ( V_19 , V_114 , V_233 ) ;
F_48 () ;
}
static void F_121 ( struct V_235 * V_236 )
{
struct V_18 * V_19 =
F_22 ( V_236 , struct V_18 , V_237 ) ;
T_2 V_238 = V_19 -> V_239 ;
F_122 ( L_60 , V_33 , V_238 ) ;
if ( V_238 & V_240 )
F_120 ( V_19 ) ;
V_19 -> V_239 = 0 ;
F_50 ( V_19 , V_149 , 1 ) ;
}
static void F_123 ( struct V_18 * V_19 )
{
T_2 V_238 ;
V_238 = F_5 ( V_19 , V_241 ) ;
if ( V_238 ) {
F_6 ( V_19 , V_241 , V_238 ) ;
F_6 ( V_19 , V_241 , 0 ) ;
V_19 -> V_239 |= V_242 ;
}
}
static void F_124 ( struct V_18 * V_19 )
{
T_2 V_238 ;
V_238 = F_5 ( V_19 , V_243 ) ;
if ( V_238 ) {
F_6 ( V_19 , V_243 , V_238 ) ;
V_19 -> V_239 |= V_244 ;
}
}
static void F_125 ( struct V_18 * V_19 )
{
T_2 V_238 ;
V_238 = F_5 ( V_19 , V_245 ) ;
if ( V_238 & ( V_246 |
V_247 |
V_248 |
V_249 |
V_250 ) ) {
F_6 ( V_19 , V_245 , V_238 ) ;
V_19 -> V_239 |= V_251 ;
}
}
static void F_126 ( struct V_18 * V_19 )
{
T_2 V_238 ;
V_238 = F_5 ( V_19 , V_252 ) ;
if ( V_238 ) {
F_6 ( V_19 , V_252 , V_238 ) ;
V_19 -> V_239 |= V_253 ;
if ( V_238 & V_254 )
V_19 -> V_239 |=
V_240 ;
}
}
static void F_127 ( struct V_18 * V_19 )
{
T_2 V_238 ;
V_238 = F_5 ( V_19 , V_255 ) ;
if ( V_238 & V_256 ) {
F_6 ( V_19 , V_255 , V_238 ) ;
V_19 -> V_239 |=
V_257 ;
}
}
static void F_128 ( struct V_18 * V_19 )
{
T_2 V_238 ;
V_238 = F_5 ( V_19 , V_258 ) ;
if ( V_238 & V_259 ) {
F_6 ( V_19 , V_258 , V_238 ) ;
V_19 -> V_239 |= V_260 ;
}
}
static void F_129 ( struct V_18 * V_19 )
{
F_50 ( V_19 , V_149 , 0 ) ;
F_128 ( V_19 ) ;
F_126 ( V_19 ) ;
F_123 ( V_19 ) ;
F_124 ( V_19 ) ;
F_127 ( V_19 ) ;
F_125 ( V_19 ) ;
F_130 ( V_19 -> V_261 , & V_19 -> V_237 ) ;
}
static T_4 F_131 ( int V_262 , void * V_263 )
{
struct V_18 * V_19 = V_263 ;
T_2 V_264 ;
unsigned long V_93 ;
if ( ! V_19 -> V_21 )
return V_265 ;
F_51 ( & V_19 -> V_94 , V_93 ) ;
V_264 = F_5 ( V_19 , V_95 ) ;
F_6 ( V_19 , V_95 , V_264 ) ;
F_52 ( & V_19 -> V_94 , V_93 ) ;
F_16 ( L_61 , V_264 , V_19 -> V_68 ) ;
if ( V_264 & V_266 )
F_129 ( V_19 ) ;
if ( V_264 & V_267 )
F_132 ( & V_19 -> V_193 ) ;
if ( V_264 & V_268 )
F_132 ( & V_19 -> V_219 ) ;
return V_265 ;
}
static int F_133 ( struct V_18 * V_19 ,
struct V_25 * V_269 )
{
V_19 -> V_270 = F_134 ( V_269 ,
L_62 ,
V_271 ) ;
if ( F_10 ( V_19 -> V_270 ) ) {
F_16 ( L_63 ,
F_32 ( V_19 -> V_270 ) ) ;
return F_32 ( V_19 -> V_270 ) ;
}
V_19 -> V_272 = F_134 ( V_269 , L_64 ,
V_273 ) ;
if ( F_10 ( V_19 -> V_272 ) ) {
F_16 ( L_65 , F_32 ( V_19 -> V_272 ) ) ;
return F_32 ( V_19 -> V_272 ) ;
}
return 0 ;
}
static int F_135 ( struct V_38 * V_39 ,
struct V_274 * V_275 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
int V_32 ;
if ( V_275 -> V_82 > V_19 -> V_276 )
return - V_5 ;
V_19 -> V_126 = V_275 -> V_126 ;
V_19 -> V_82 = V_275 -> V_82 ;
V_19 -> V_84 = V_275 -> V_84 ;
V_19 -> V_97 = V_275 -> V_97 ;
V_32 = F_133 ( V_19 , & V_275 -> V_26 ) ;
if ( V_32 )
return V_32 ;
F_16 ( L_26 , V_19 -> V_68 ) ;
if ( V_19 -> V_26 )
F_136 ( V_19 -> V_26 ) ;
return 0 ;
}
static int F_137 ( struct V_38 * V_39 ,
struct V_274 * V_275 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
V_19 -> V_277 = NULL ;
F_16 ( L_26 , V_19 -> V_68 ) ;
if ( V_19 -> V_26 )
F_136 ( V_19 -> V_26 ) ;
return 0 ;
}
static T_5 F_138 ( struct V_38 * V_39 ,
const struct V_206 * V_207 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
int V_32 ;
if ( ! V_207 || ! V_19 -> V_194 )
return - V_5 ;
F_42 ( & V_19 -> V_278 ) ;
V_32 = F_139 ( V_19 -> V_68 , V_207 ) ;
F_43 ( & V_19 -> V_278 ) ;
return V_32 ;
}
static int F_140 ( struct V_18 * V_19 ,
struct V_277 * V_279 )
{
struct V_25 * V_26 = & V_19 -> V_27 -> V_26 ;
struct V_280 * V_281 ;
T_2 V_282 [ 4 ] ;
int V_32 , V_48 , V_210 , V_283 ;
V_281 = F_141 ( V_279 , L_66 , & V_210 ) ;
if ( ! V_281 ) {
F_142 ( V_26 , L_67 ) ;
return - V_5 ;
}
V_283 = V_210 / sizeof( T_2 ) ;
if ( V_283 < 1 || V_283 > 4 ) {
F_143 ( V_26 , L_68 ) ;
return - V_5 ;
}
V_19 -> V_276 = V_283 ;
V_32 = F_144 ( V_279 , L_66 , V_282 ,
V_283 ) ;
if ( V_32 ) {
F_143 ( V_26 , L_69 ) ;
return V_32 ;
}
for ( V_48 = 0 ; V_48 < F_145 ( V_284 ) ; V_48 ++ ) {
const int * V_285 = V_284 [ V_48 ] ;
int V_225 ;
for ( V_225 = 0 ; V_225 < V_283 ; V_225 ++ ) {
if ( V_282 [ V_225 ] < 0 || V_282 [ V_225 ] > 3 )
F_143 ( V_26 , L_70 ,
V_282 [ V_225 ] ) ;
if ( V_285 [ V_282 [ V_225 ] ] != V_225 )
break;
}
if ( V_225 == V_283 ) {
V_19 -> V_155 = V_48 ;
return 0 ;
}
}
return - V_5 ;
}
static int F_146 ( struct V_18 * V_19 )
{
struct V_25 * V_26 = & V_19 -> V_27 -> V_26 ;
struct V_277 * V_286 = V_26 -> V_287 ;
struct V_277 * V_288 , * V_277 ;
int V_32 ;
V_288 = F_147 ( V_286 , 1 , - 1 ) ;
if ( ! V_288 ) {
F_142 ( V_26 , L_71 , V_33 ) ;
return 0 ;
}
V_32 = F_140 ( V_19 , V_288 ) ;
if ( V_32 ) {
F_143 ( V_26 , L_72 ,
V_33 , V_32 ) ;
goto V_69;
}
V_277 = F_148 ( V_288 ) ;
if ( ! V_277 ) {
F_143 ( V_26 , L_73 , V_33 ) ;
V_32 = - V_63 ;
goto V_69;
}
V_19 -> V_277 = V_277 ;
if ( F_149 ( V_286 , L_74 ) ) {
V_19 -> V_289 = F_150 ( V_286 ,
L_74 ) ;
if ( F_10 ( V_19 -> V_289 ) ) {
F_143 ( V_26 , L_75 ,
V_33 ) ;
V_32 = F_32 ( V_19 -> V_289 ) ;
}
}
F_151 ( V_277 ) ;
V_69:
F_151 ( V_288 ) ;
return V_32 ;
}
static int F_152 ( struct V_18 * V_19 )
{
struct V_290 * V_27 = V_19 -> V_27 ;
const struct V_55 * V_45 = V_19 -> V_24 -> V_45 ;
struct V_291 * V_292 ;
int V_48 ;
V_292 = F_153 ( V_27 , V_293 , L_76 ) ;
if ( ! V_292 )
return - V_5 ;
for ( V_48 = 0 ; V_48 < V_45 -> V_294 ; V_48 ++ ) {
if ( V_45 -> V_295 [ V_48 ] == V_292 -> V_296 )
return V_48 ;
}
return - V_5 ;
}
int F_154 ( struct V_297 * V_297 )
{
struct V_18 * V_19 = NULL ;
struct V_290 * V_27 = V_297 -> V_27 ;
int V_32 ;
V_19 = F_155 ( & V_27 -> V_26 , sizeof( * V_19 ) , V_204 ) ;
if ( ! V_19 ) {
F_11 ( L_77 ,
V_33 ) ;
V_32 = - V_205 ;
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
V_19 -> V_21 += V_19 -> V_24 -> V_45 -> V_298 ;
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
V_19 -> V_212 = F_155 ( & V_27 -> V_26 , V_299 , V_204 ) ;
if ( ! V_19 -> V_212 ) {
F_11 ( L_85 , V_33 ) ;
goto V_52;
}
F_157 ( & V_19 -> V_219 ) ;
F_157 ( & V_19 -> V_193 ) ;
F_158 ( & V_19 -> V_300 ) ;
F_158 ( & V_19 -> V_278 ) ;
F_158 ( & V_19 -> V_79 ) ;
F_159 ( & V_19 -> V_94 ) ;
V_19 -> V_261 = F_160 ( L_86 , 0 ) ;
F_161 ( & V_19 -> V_237 , F_121 ) ;
V_297 -> V_39 = & V_19 -> V_1 ;
V_297 -> V_68 = V_19 -> V_68 ;
F_16 ( L_87 , V_19 -> V_68 ) ;
return 0 ;
V_52:
return V_32 ;
}
void F_162 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_16 ( L_9 ) ;
F_100 ( V_19 ) ;
if ( V_19 -> V_261 ) {
F_163 ( V_19 -> V_261 ) ;
F_164 ( V_19 -> V_261 ) ;
V_19 -> V_261 = NULL ;
}
F_165 ( & V_19 -> V_79 ) ;
F_165 ( & V_19 -> V_278 ) ;
F_165 ( & V_19 -> V_300 ) ;
}
int F_166 ( struct V_38 * V_39 ,
struct V_196 * V_26 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
struct V_290 * V_27 = V_19 -> V_27 ;
int V_32 ;
V_19 -> V_262 = F_167 ( V_27 -> V_26 . V_287 , 0 ) ;
if ( V_19 -> V_262 < 0 ) {
V_32 = V_19 -> V_262 ;
F_143 ( V_26 -> V_26 , L_88 , V_32 ) ;
return V_32 ;
}
V_32 = F_168 ( & V_27 -> V_26 , V_19 -> V_262 ,
F_131 , V_301 | V_302 ,
L_89 , V_19 ) ;
if ( V_32 < 0 ) {
F_143 ( & V_27 -> V_26 , L_90 ,
V_19 -> V_262 , V_32 ) ;
return V_32 ;
}
V_19 -> V_26 = V_26 ;
V_32 = F_96 ( V_19 , V_299 ) ;
if ( V_32 ) {
F_11 ( L_91 , V_33 , V_32 ) ;
return V_32 ;
}
return 0 ;
}
int F_169 ( struct V_38 * V_39 , bool V_303 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
int V_32 ;
if ( ! V_19 -> V_304 ) {
V_39 -> V_26 = & V_19 -> V_27 -> V_26 ;
V_39 -> V_305 = & V_306 ;
V_32 = F_170 ( V_39 ) ;
if ( V_32 )
return V_32 ;
V_19 -> V_304 = true ;
if ( V_303 && V_19 -> V_277 ) {
if ( ! F_171 ( V_19 -> V_277 ) )
if ( ! F_172 ( V_19 -> V_277 ) )
return - V_307 ;
}
}
return 0 ;
}
void F_173 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
if ( V_19 -> V_304 ) {
F_174 ( V_39 ) ;
V_39 -> V_26 = NULL ;
V_39 -> V_305 = NULL ;
V_19 -> V_304 = false ;
}
}
int F_175 ( struct V_38 * V_39 ,
const struct V_206 * V_207 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_41 ( V_19 , 1 ) ;
if ( ! ( V_207 -> V_93 & V_308 ) )
F_89 ( 0 , V_19 ) ;
V_19 -> V_309 = F_5 ( V_19 , V_114 ) ;
F_6 ( V_19 , V_114 ,
V_19 -> V_309 |
V_190 |
V_159 ) ;
F_50 ( V_19 , V_310 , 1 ) ;
return 0 ;
}
void F_176 ( struct V_38 * V_39 ,
const struct V_206 * V_207 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_50 ( V_19 , V_310 , 0 ) ;
F_6 ( V_19 , V_114 , V_19 -> V_309 ) ;
if ( ! ( V_207 -> V_93 & V_308 ) )
F_89 ( 1 , V_19 ) ;
F_41 ( V_19 , 0 ) ;
}
int F_177 ( struct V_38 * V_39 ,
const struct V_206 * V_207 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
return F_119 ( V_19 , V_207 ) ;
}
int F_178 ( struct V_38 * V_39 ,
const struct V_206 * V_207 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
const struct V_23 * V_24 = V_19 -> V_24 ;
int V_311 , V_221 , V_312 , V_313 ;
int V_314 , V_315 , V_222 , V_32 = 0 ;
char V_316 ;
int V_317 = V_207 -> V_213 ;
T_3 * V_216 ;
if ( V_317 <= 2 ) {
V_314 = 1 ;
V_222 = V_317 ;
V_221 = 4 ;
} else {
V_314 = 0 ;
V_311 = 10 ;
if ( V_317 < V_311 )
V_222 = V_317 ;
else
V_222 = V_311 ;
V_221 = V_311 + 6 ;
}
V_216 = V_19 -> V_212 ;
V_313 = 0 ;
while ( ! V_313 ) {
T_3 V_318 [ 2 ] = { V_222 & 0xff , V_222 >> 8 } ;
struct V_206 V_319 = {
. V_126 = V_207 -> V_126 ,
. type = V_320 ,
. V_321 = 2 ,
. V_202 = V_318 ,
} ;
F_16 ( L_92 ,
V_317 , V_222 , V_221 ) ;
V_32 = F_119 ( V_19 , & V_319 ) ;
if ( V_32 < 2 ) {
F_11 ( L_93 ,
V_33 , V_32 ) ;
return - V_5 ;
}
if ( ( V_24 -> V_2 == V_10 ) &&
( V_24 -> V_3 >= V_322 ) ) {
F_6 ( V_19 , V_323 ,
V_324 ) ;
F_48 () ;
F_6 ( V_19 , V_323 , 0 ) ;
F_48 () ;
}
V_32 = F_119 ( V_19 , V_207 ) ;
if ( V_32 < V_207 -> V_321 ) {
F_11 ( L_94 , V_33 , V_32 ) ;
return V_32 ;
}
V_312 = F_116 ( V_19 , V_216 , V_221 , V_222 ) ;
if ( V_312 <= 0 )
return 0 ;
if ( V_314 )
break;
if ( V_317 <= V_311 ) {
V_315 = V_311 - V_317 ;
V_313 = 1 ;
} else {
V_315 = 0 ;
V_317 -= V_311 ;
}
if ( ! V_313 ) {
V_312 -= 2 ;
V_312 -= V_315 ;
V_216 += V_312 ;
V_311 = 14 ;
if ( V_317 < V_311 )
V_222 += V_317 ;
else
V_222 += V_311 ;
F_16 ( L_95 , V_216 , V_312 , V_315 ) ;
}
}
if ( V_222 < 10 && ! V_314 )
V_216 = V_19 -> V_212 + ( 10 - V_317 ) ;
else
V_216 = V_19 -> V_212 ;
V_316 = V_216 [ 0 ] ;
switch ( V_316 ) {
case V_325 :
F_11 ( L_96 , V_33 ) ;
V_32 = 0 ;
break;
case V_326 :
case V_327 :
V_32 = F_110 ( V_216 , V_207 ) ;
break;
case V_328 :
case V_329 :
V_32 = F_111 ( V_216 , V_207 ) ;
break;
case V_330 :
case V_331 :
V_32 = F_112 ( V_216 , V_207 ) ;
break;
default:
F_179 ( L_97 , V_33 ) ;
V_32 = 0 ;
}
return V_32 ;
}
void F_180 ( struct V_38 * V_39 , T_2 V_217 ,
T_2 V_210 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_6 ( V_19 , V_332 , V_217 ) ;
F_6 ( V_19 , V_333 , V_210 ) ;
F_6 ( V_19 , V_334 , 1 ) ;
F_48 () ;
}
int F_181 ( struct V_38 * V_39 ,
struct V_335 * V_336 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
const struct V_23 * V_24 = V_19 -> V_24 ;
struct V_30 * V_337 , * V_338 ;
int V_32 ;
V_32 = F_182 ( V_336 ,
& V_337 , & V_338 ) ;
if ( V_32 ) {
F_183 ( L_98 ,
V_33 ) ;
return 0 ;
}
V_32 = F_184 ( V_19 -> V_62 , V_337 ) ;
if ( V_32 ) {
F_11 ( L_99 ,
V_33 , V_32 ) ;
goto exit;
}
V_32 = F_184 ( V_19 -> V_64 , V_338 ) ;
if ( V_32 ) {
F_11 ( L_100 ,
V_33 , V_32 ) ;
goto exit;
}
if ( V_24 -> V_2 == V_8 ) {
V_32 = F_184 ( V_19 -> V_67 , V_338 ) ;
if ( V_32 ) {
F_11 ( L_101 ,
V_33 , V_32 ) ;
goto exit;
}
V_32 = F_184 ( V_19 -> V_66 , V_337 ) ;
if ( V_32 ) {
F_11 ( L_102 ,
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
F_88 ( V_19 ,
! ! ( V_19 -> V_97 & V_115 ) , true ) ;
return 0 ;
}
int F_186 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_88 ( V_19 ,
! ! ( V_19 -> V_97 & V_115 ) , false ) ;
F_87 ( V_19 ) ;
return 0 ;
}
static void F_187 ( struct V_18 * V_19 , bool V_78 )
{
enum V_339 V_340 ;
if ( ! V_19 -> V_289 )
return;
V_340 = V_78 ? V_341 : V_342 ;
F_188 ( V_19 -> V_289 , V_343 ,
V_344 ,
F_189 ( V_340 ) ) ;
}
int F_190 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
T_2 V_112 = 0 , V_113 = 0 ;
int V_32 = 0 ;
F_42 ( & V_19 -> V_300 ) ;
if ( V_19 -> V_194 ) {
F_16 ( L_103 ) ;
goto V_80;
}
F_187 ( V_19 , true ) ;
V_32 = F_44 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_104 , V_33 , V_32 ) ;
goto V_80;
}
V_32 = F_26 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_105 ,
V_33 , V_32 ) ;
goto V_80;
}
V_32 = F_34 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_106 , V_33 , V_32 ) ;
goto V_345;
}
F_47 ( V_19 ) ;
V_32 = F_191 ( V_19 -> V_68 ,
V_19 -> V_71 * 8 ,
V_19 -> V_74 ,
& V_112 , & V_113 ) ;
F_35 ( V_19 ) ;
if ( V_32 ) {
F_11 ( L_107 , V_33 , V_32 ) ;
goto V_345;
}
V_32 = F_41 ( V_19 , 1 ) ;
if ( V_32 ) {
F_11 ( L_108 , V_33 , V_32 ) ;
goto V_345;
}
V_32 = F_192 ( & V_19 -> V_27 -> V_26 ) ;
if ( V_32 ) {
F_11 ( L_109 ,
V_33 , V_32 ) ;
goto V_346;
}
F_71 ( V_19 ) ;
F_87 ( V_19 ) ;
F_56 ( V_19 , true , V_112 , V_113 ) ;
if ( V_19 -> V_270 )
F_193 ( V_19 -> V_270 , 1 ) ;
V_19 -> V_194 = true ;
F_43 ( & V_19 -> V_300 ) ;
return 0 ;
V_346:
F_41 ( V_19 , 0 ) ;
V_345:
F_23 ( V_19 ) ;
V_80:
F_43 ( & V_19 -> V_300 ) ;
return V_32 ;
}
int F_194 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
F_42 ( & V_19 -> V_300 ) ;
if ( ! V_19 -> V_194 ) {
F_16 ( L_110 ) ;
goto V_80;
}
F_56 ( V_19 , false , 0 , 0 ) ;
if ( V_19 -> V_270 )
F_193 ( V_19 -> V_270 , 0 ) ;
F_195 ( & V_19 -> V_27 -> V_26 ) ;
F_196 ( V_19 -> V_68 ) ;
F_41 ( V_19 , 0 ) ;
F_23 ( V_19 ) ;
F_187 ( V_19 , false ) ;
F_16 ( L_111 ) ;
V_19 -> V_194 = false ;
V_80:
F_43 ( & V_19 -> V_300 ) ;
return 0 ;
}
int F_197 ( struct V_38 * V_39 ,
struct V_81 * V_70 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
if ( V_19 -> V_70 ) {
F_198 ( V_19 -> V_26 , V_19 -> V_70 ) ;
V_19 -> V_70 = NULL ;
}
V_19 -> V_70 = F_199 ( V_19 -> V_26 , V_70 ) ;
if ( ! V_19 -> V_70 ) {
F_11 ( L_112 , V_33 ) ;
return - V_205 ;
}
return 0 ;
}
struct V_347 * F_200 ( struct V_38 * V_39 ,
unsigned long * V_348 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
struct V_347 * V_349 ;
V_349 = F_171 ( V_19 -> V_277 ) ;
if ( V_348 )
* V_348 = V_19 -> V_97 ;
return V_349 ;
}
struct V_350 * F_201 ( struct V_38 * V_39 )
{
struct V_18 * V_19 = F_21 ( V_39 ) ;
return F_172 ( V_19 -> V_277 ) ;
}
