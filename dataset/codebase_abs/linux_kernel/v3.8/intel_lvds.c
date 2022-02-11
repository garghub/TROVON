static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_4 ) ;
}
static struct V_5 * F_3 ( struct V_6 * V_7 )
{
return F_2 ( V_7 , struct V_5 , V_4 . V_4 ) ;
}
static bool F_4 ( struct V_8 * V_3 ,
enum V_9 * V_9 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_1 V_15 , V_16 ;
if ( F_5 ( V_11 ) ) {
V_15 = V_17 ;
} else {
V_15 = V_18 ;
}
V_16 = F_6 ( V_15 ) ;
if ( ! ( V_16 & V_19 ) )
return false ;
if ( F_7 ( V_11 ) )
* V_9 = F_8 ( V_16 ) ;
else
* V_9 = F_9 ( V_16 ) ;
return true ;
}
static void F_10 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_20 = F_1 ( & V_3 -> V_4 ) ;
struct V_21 * V_21 = F_11 ( V_3 -> V_4 . V_22 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_1 V_23 , V_15 , V_24 ;
if ( F_5 ( V_11 ) ) {
V_23 = V_25 ;
V_15 = V_17 ;
V_24 = V_26 ;
} else {
V_23 = V_27 ;
V_15 = V_18 ;
V_24 = V_28 ;
}
F_12 ( V_15 , F_6 ( V_15 ) | V_19 ) ;
if ( V_20 -> V_29 ) {
F_13 ( L_1 ,
V_20 -> V_30 ,
V_20 -> V_31 ) ;
F_12 ( V_32 , V_20 -> V_31 ) ;
F_12 ( V_33 , V_20 -> V_30 ) ;
V_20 -> V_29 = false ;
}
F_12 ( V_23 , F_6 ( V_23 ) | V_34 ) ;
F_14 ( V_15 ) ;
if ( F_15 ( ( F_6 ( V_24 ) & V_35 ) != 0 , 1000 ) )
F_16 ( L_2 ) ;
F_17 ( V_11 , V_21 -> V_9 ) ;
}
static void F_18 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_20 = F_1 ( & V_3 -> V_4 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_1 V_23 , V_15 , V_24 ;
if ( F_5 ( V_11 ) ) {
V_23 = V_25 ;
V_15 = V_17 ;
V_24 = V_26 ;
} else {
V_23 = V_27 ;
V_15 = V_18 ;
V_24 = V_28 ;
}
F_19 ( V_11 ) ;
F_12 ( V_23 , F_6 ( V_23 ) & ~ V_34 ) ;
if ( F_15 ( ( F_6 ( V_24 ) & V_35 ) == 0 , 1000 ) )
F_16 ( L_3 ) ;
if ( V_20 -> V_30 ) {
F_12 ( V_33 , 0 ) ;
V_20 -> V_29 = true ;
}
F_12 ( V_15 , F_6 ( V_15 ) & ~ V_19 ) ;
F_14 ( V_15 ) ;
}
static int F_20 ( struct V_6 * V_7 ,
struct V_36 * V_37 )
{
struct V_38 * V_38 = F_21 ( V_7 ) ;
struct V_36 * V_39 = V_38 -> V_40 . V_39 ;
if ( V_37 -> V_41 > V_39 -> V_41 )
return V_42 ;
if ( V_37 -> V_43 > V_39 -> V_43 )
return V_42 ;
return V_44 ;
}
static void
F_22 ( struct V_36 * V_37 ,
int V_45 )
{
T_1 V_46 , V_47 , V_48 , V_49 ;
V_49 = V_37 -> V_50 - V_37 -> V_51 ;
V_48 = V_37 -> V_52 - V_37 -> V_53 ;
V_47 = ( V_48 - V_49 + 1 ) / 2 ;
V_46 = ( V_37 -> V_41 - V_45 + 1 ) / 2 ;
V_46 += V_46 & 1 ;
V_37 -> V_54 = V_45 ;
V_37 -> V_53 = V_45 + V_46 ;
V_37 -> V_52 = V_37 -> V_53 + V_48 ;
V_37 -> V_51 = V_37 -> V_53 + V_47 ;
V_37 -> V_50 = V_37 -> V_51 + V_49 ;
V_37 -> V_55 |= V_56 ;
}
static void
F_23 ( struct V_36 * V_37 ,
int V_57 )
{
T_1 V_46 , V_47 , V_48 , V_49 ;
V_49 = V_37 -> V_58 - V_37 -> V_59 ;
V_48 = V_37 -> V_60 - V_37 -> V_61 ;
V_47 = ( V_48 - V_49 + 1 ) / 2 ;
V_46 = ( V_37 -> V_43 - V_57 + 1 ) / 2 ;
V_37 -> V_62 = V_57 ;
V_37 -> V_61 = V_57 + V_46 ;
V_37 -> V_60 = V_37 -> V_61 + V_48 ;
V_37 -> V_59 = V_37 -> V_61 + V_47 ;
V_37 -> V_58 = V_37 -> V_59 + V_49 ;
V_37 -> V_55 |= V_56 ;
}
static inline T_1 F_24 ( T_1 V_63 , T_1 V_64 )
{
#define F_25 12
#define F_26 (1 << ACCURACY)
T_1 V_65 = V_63 * F_26 / V_64 ;
return ( F_26 * V_65 + F_26 / 2 ) / F_26 ;
}
static bool F_27 ( struct V_2 * V_3 ,
const struct V_36 * V_37 ,
struct V_36 * V_66 )
{
struct V_10 * V_11 = V_3 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_20 = F_1 ( V_3 ) ;
struct V_38 * V_38 =
& V_20 -> V_67 -> V_4 ;
struct V_21 * V_21 = V_20 -> V_4 . V_68 ;
T_1 V_30 = 0 , V_31 = 0 , V_46 = 0 ;
int V_9 ;
if ( F_28 ( V_11 ) -> V_69 < 4 && V_21 -> V_9 == 0 ) {
F_16 ( L_4 ) ;
return false ;
}
if ( F_29 ( & V_20 -> V_4 ) )
return false ;
F_30 ( V_38 -> V_40 . V_39 ,
V_66 ) ;
if ( F_5 ( V_11 ) ) {
F_31 ( V_11 ,
V_38 -> V_40 . V_70 ,
V_37 , V_66 ) ;
return true ;
}
if ( V_66 -> V_41 == V_37 -> V_41 &&
V_66 -> V_43 == V_37 -> V_43 )
goto V_71;
if ( F_28 ( V_11 ) -> V_69 >= 4 )
V_30 |= ( ( V_21 -> V_9 << V_72 ) |
V_73 ) ;
F_32 (pipe)
F_12 ( F_33 ( V_9 ) , 0 ) ;
F_34 ( V_66 , 0 ) ;
switch ( V_38 -> V_40 . V_70 ) {
case V_74 :
F_22 ( V_66 , V_37 -> V_41 ) ;
F_23 ( V_66 , V_37 -> V_43 ) ;
V_46 = V_75 ;
break;
case V_76 :
if ( F_28 ( V_11 ) -> V_69 >= 4 ) {
T_1 V_77 = V_66 -> V_41 * V_37 -> V_43 ;
T_1 V_78 = V_37 -> V_41 * V_66 -> V_43 ;
if ( V_77 > V_78 )
V_30 |= V_79 | V_80 ;
else if ( V_77 < V_78 )
V_30 |= V_79 | V_81 ;
else if ( V_66 -> V_41 != V_37 -> V_41 )
V_30 |= V_79 | V_82 ;
} else {
T_1 V_77 = V_66 -> V_41 * V_37 -> V_43 ;
T_1 V_78 = V_37 -> V_41 * V_66 -> V_43 ;
if ( V_77 > V_78 ) {
F_22 ( V_66 , V_78 / V_37 -> V_43 ) ;
V_46 = V_75 ;
if ( V_37 -> V_43 != V_66 -> V_43 ) {
T_1 V_83 = F_24 ( V_37 -> V_43 , V_66 -> V_43 ) ;
V_31 |= ( V_83 << V_84 |
V_83 << V_85 ) ;
V_30 |= ( V_79 |
V_86 |
V_87 ) ;
}
} else if ( V_77 < V_78 ) {
F_23 ( V_66 , V_77 / V_37 -> V_41 ) ;
V_46 = V_75 ;
if ( V_37 -> V_41 != V_66 -> V_41 ) {
T_1 V_83 = F_24 ( V_37 -> V_41 , V_66 -> V_41 ) ;
V_31 |= ( V_83 << V_84 |
V_83 << V_85 ) ;
V_30 |= ( V_79 |
V_86 |
V_87 ) ;
}
} else
V_30 |= ( V_79 |
V_88 | V_89 |
V_86 |
V_87 ) ;
}
break;
case V_90 :
if ( V_37 -> V_43 != V_66 -> V_43 ||
V_37 -> V_41 != V_66 -> V_41 ) {
V_30 |= V_79 ;
if ( F_28 ( V_11 ) -> V_69 >= 4 )
V_30 |= V_82 ;
else
V_30 |= ( V_88 |
V_86 |
V_89 |
V_87 ) ;
}
break;
default:
break;
}
V_71:
if ( ( V_30 & V_79 ) == 0 ) {
V_30 = 0 ;
V_31 = 0 ;
}
if ( F_28 ( V_11 ) -> V_69 < 4 && V_13 -> V_91 )
V_30 |= V_92 ;
if ( V_30 != V_20 -> V_30 ||
V_31 != V_20 -> V_31 ) {
V_20 -> V_30 = V_30 ;
V_20 -> V_31 = V_31 ;
V_20 -> V_29 = true ;
}
V_13 -> V_93 = V_46 ;
return true ;
}
static void F_35 ( struct V_2 * V_3 ,
struct V_36 * V_37 ,
struct V_36 * V_66 )
{
}
static enum V_94
F_36 ( struct V_6 * V_7 , bool V_95 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
enum V_94 V_96 ;
V_96 = F_37 ( V_11 ) ;
if ( V_96 != V_97 )
return V_96 ;
return V_98 ;
}
static int F_38 ( struct V_6 * V_7 )
{
struct V_5 * V_99 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_36 * V_37 ;
if ( ! F_39 ( V_99 -> V_4 . V_100 ) )
return F_40 ( V_7 , V_99 -> V_4 . V_100 ) ;
V_37 = F_41 ( V_11 , V_99 -> V_4 . V_40 . V_39 ) ;
if ( V_37 == NULL )
return 0 ;
F_42 ( V_7 , V_37 ) ;
return 1 ;
}
static int F_43 ( const struct V_101 * V_102 )
{
F_44 ( L_5 , V_102 -> V_103 ) ;
return 1 ;
}
static int F_45 ( struct V_104 * V_105 , unsigned long V_106 ,
void * V_107 )
{
struct V_5 * V_99 =
F_2 ( V_105 , struct V_5 , V_108 ) ;
struct V_6 * V_7 = & V_99 -> V_4 . V_4 ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_11 -> V_109 != V_110 )
return V_111 ;
V_7 -> V_96 = V_7 -> V_112 -> V_113 ( V_7 , false ) ;
if ( F_46 ( V_114 ) )
return V_111 ;
if ( ! F_47 () ) {
V_13 -> V_115 = 1 ;
return V_111 ;
}
if ( ! V_13 -> V_115 )
return V_111 ;
V_13 -> V_115 = 0 ;
F_48 ( & V_11 -> V_116 . V_117 ) ;
F_49 ( V_11 , true ) ;
F_50 ( & V_11 -> V_116 . V_117 ) ;
return V_111 ;
}
static void F_51 ( struct V_6 * V_7 )
{
struct V_5 * V_99 =
F_3 ( V_7 ) ;
if ( V_99 -> V_108 . V_118 )
F_52 ( & V_99 -> V_108 ) ;
if ( ! F_39 ( V_99 -> V_4 . V_100 ) )
F_53 ( V_99 -> V_4 . V_100 ) ;
F_54 ( V_7 -> V_11 ) ;
F_55 ( & V_99 -> V_4 . V_40 ) ;
F_56 ( V_7 ) ;
F_57 ( V_7 ) ;
F_53 ( V_7 ) ;
}
static int F_58 ( struct V_6 * V_7 ,
struct V_119 * V_120 ,
T_2 V_121 )
{
struct V_38 * V_38 = F_21 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
if ( V_120 == V_11 -> V_116 . V_122 ) {
struct V_123 * V_22 ;
if ( V_121 == V_124 ) {
F_13 ( L_6 ) ;
return - V_125 ;
}
if ( V_38 -> V_40 . V_70 == V_121 ) {
return 0 ;
}
V_38 -> V_40 . V_70 = V_121 ;
V_22 = F_59 ( V_7 ) -> V_4 . V_22 ;
if ( V_22 && V_22 -> V_126 ) {
F_60 ( V_22 , & V_22 -> V_37 ,
V_22 -> V_127 , V_22 -> V_128 , V_22 -> V_129 ) ;
}
}
return 0 ;
}
static int T_3 F_61 ( const struct V_101 * V_102 )
{
F_44 ( L_7 , V_102 -> V_103 ) ;
return 1 ;
}
static void F_62 ( struct V_10 * V_11 ,
struct V_36 * V_39 ,
struct V_6 * V_7 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_36 * V_130 ;
int V_131 ;
V_131 = V_39 -> clock ;
F_63 (scan, &connector->probed_modes, head) {
if ( V_130 -> V_41 == V_39 -> V_41 &&
V_130 -> V_132 == V_39 -> V_132 &&
V_130 -> V_133 == V_39 -> V_133 &&
V_130 -> V_134 == V_39 -> V_134 &&
V_130 -> V_43 == V_39 -> V_43 &&
V_130 -> V_135 == V_39 -> V_135 &&
V_130 -> V_136 == V_39 -> V_136 &&
V_130 -> V_137 == V_39 -> V_137 ) {
if ( V_130 -> clock < V_131 ) {
V_131 = V_130 -> clock ;
}
}
}
if ( V_131 < V_39 -> clock && V_138 ) {
V_13 -> V_139 = 1 ;
V_13 -> V_140 = V_131 ;
F_13 ( L_8
L_9 ,
V_39 -> clock , V_131 ) ;
}
}
static bool F_64 ( struct V_10 * V_11 ,
T_4 * V_141 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
int V_142 ;
if ( ! V_13 -> V_143 )
return true ;
for ( V_142 = 0 ; V_142 < V_13 -> V_143 ; V_142 ++ ) {
struct V_144 * V_145 = V_13 -> V_146 + V_142 ;
if ( V_145 -> V_147 != V_148 &&
V_145 -> V_147 != V_149 )
continue;
if ( F_65 ( V_145 -> V_141 ) )
* V_141 = V_145 -> V_141 ;
if ( V_145 -> V_150 )
return true ;
if ( V_13 -> V_151 . V_152 )
return true ;
}
return false ;
}
static bool F_66 ( struct V_10 * V_11 )
{
if ( F_5 ( V_11 ) )
return true ;
return F_67 ( V_11 ) && ! F_68 ( V_11 ) ;
}
bool F_69 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_20 ;
struct V_8 * V_8 ;
struct V_5 * V_99 ;
struct V_38 * V_38 ;
struct V_6 * V_7 ;
struct V_2 * V_3 ;
struct V_36 * V_130 ;
struct V_36 * V_39 = NULL ;
struct V_100 * V_100 ;
struct V_123 * V_22 ;
T_1 V_153 ;
int V_9 ;
T_4 V_154 ;
if ( ! F_66 ( V_11 ) )
return false ;
if ( F_46 ( V_155 ) )
return false ;
V_154 = V_156 ;
if ( ! F_64 ( V_11 , & V_154 ) ) {
F_13 ( L_10 ) ;
return false ;
}
if ( F_5 ( V_11 ) ) {
if ( ( F_6 ( V_17 ) & V_157 ) == 0 )
return false ;
if ( V_13 -> V_158 . V_159 ) {
F_13 ( L_11 ) ;
return false ;
}
}
V_20 = F_70 ( sizeof( struct V_1 ) , V_160 ) ;
if ( ! V_20 )
return false ;
V_99 = F_70 ( sizeof( struct V_5 ) , V_160 ) ;
if ( ! V_99 ) {
F_53 ( V_20 ) ;
return false ;
}
V_20 -> V_67 = V_99 ;
if ( ! F_5 ( V_11 ) ) {
V_20 -> V_30 = F_6 ( V_33 ) ;
}
V_8 = & V_20 -> V_4 ;
V_3 = & V_8 -> V_4 ;
V_38 = & V_99 -> V_4 ;
V_7 = & V_38 -> V_4 ;
F_71 ( V_11 , & V_38 -> V_4 , & V_161 ,
V_162 ) ;
F_72 ( V_11 , & V_8 -> V_4 , & V_163 ,
V_164 ) ;
V_8 -> V_165 = F_10 ;
V_8 -> V_166 = F_18 ;
V_8 -> V_167 = F_4 ;
V_38 -> V_167 = V_168 ;
F_73 ( V_38 , V_8 ) ;
V_8 -> type = V_169 ;
V_8 -> V_170 = false ;
if ( F_5 ( V_11 ) )
V_8 -> V_171 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
else if ( F_74 ( V_11 ) )
V_8 -> V_171 = ( 1 << 0 ) | ( 1 << 1 ) ;
else
V_8 -> V_171 = ( 1 << 1 ) ;
F_75 ( V_3 , & V_172 ) ;
F_76 ( V_7 , & V_173 ) ;
V_7 -> V_174 . V_175 = V_176 ;
V_7 -> V_177 = false ;
V_7 -> V_178 = false ;
F_77 ( V_11 ) ;
F_78 ( & V_7 -> V_4 ,
V_11 -> V_116 . V_122 ,
V_76 ) ;
V_38 -> V_40 . V_70 = V_76 ;
V_100 = F_79 ( V_7 , F_80 ( V_13 , V_154 ) ) ;
if ( V_100 ) {
if ( F_40 ( V_7 , V_100 ) ) {
F_81 ( V_7 ,
V_100 ) ;
} else {
F_53 ( V_100 ) ;
V_100 = F_82 ( - V_125 ) ;
}
} else {
V_100 = F_82 ( - V_179 ) ;
}
V_99 -> V_4 . V_100 = V_100 ;
if ( F_39 ( V_100 ) ) {
V_7 -> V_174 . V_180 = 0 ;
V_7 -> V_174 . V_181 = 200 ;
V_7 -> V_174 . V_182 = 0 ;
V_7 -> V_174 . V_183 = 200 ;
}
F_63 (scan, &connector->probed_modes, head) {
if ( V_130 -> type & V_184 ) {
F_13 ( L_12 ) ;
F_83 ( V_130 ) ;
V_39 = F_41 ( V_11 , V_130 ) ;
if ( V_39 ) {
F_62 ( V_11 , V_39 ,
V_7 ) ;
goto V_71;
}
}
}
if ( V_13 -> V_185 ) {
F_13 ( L_13 ) ;
F_83 ( V_13 -> V_185 ) ;
V_39 = F_41 ( V_11 , V_13 -> V_185 ) ;
if ( V_39 ) {
V_39 -> type |= V_184 ;
goto V_71;
}
}
if ( F_5 ( V_11 ) )
goto V_186;
V_153 = F_6 ( V_18 ) ;
V_9 = ( V_153 & V_187 ) ? 1 : 0 ;
V_22 = F_84 ( V_11 , V_9 ) ;
if ( V_22 && ( V_153 & V_19 ) ) {
V_39 = F_85 ( V_11 , V_22 ) ;
if ( V_39 ) {
F_13 ( L_14 ) ;
F_83 ( V_39 ) ;
V_39 -> type |= V_184 ;
goto V_71;
}
}
if ( ! V_39 )
goto V_186;
V_71:
if ( F_5 ( V_11 ) ) {
F_12 ( V_25 ,
F_6 ( V_25 ) | V_188 ) ;
} else {
F_12 ( V_27 ,
F_6 ( V_27 ) | V_188 ) ;
}
V_99 -> V_108 . V_118 = F_45 ;
if ( F_86 ( & V_99 -> V_108 ) ) {
F_13 ( L_15 ) ;
V_99 -> V_108 . V_118 = NULL ;
}
F_87 ( V_7 ) ;
F_88 ( & V_38 -> V_40 , V_39 ) ;
F_89 ( V_7 ) ;
return true ;
V_186:
F_13 ( L_16 ) ;
F_57 ( V_7 ) ;
F_90 ( V_3 ) ;
if ( V_39 )
F_91 ( V_11 , V_39 ) ;
F_53 ( V_20 ) ;
F_53 ( V_99 ) ;
return false ;
}
