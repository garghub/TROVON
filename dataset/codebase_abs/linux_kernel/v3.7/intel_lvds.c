static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( F_4 ( V_6 ) ,
struct V_1 , V_4 ) ;
}
static bool F_5 ( struct V_7 * V_3 ,
enum V_8 * V_8 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_14 , V_15 ;
if ( F_6 ( V_10 ) ) {
V_14 = V_16 ;
} else {
V_14 = V_17 ;
}
V_15 = F_7 ( V_14 ) ;
if ( ! ( V_15 & V_18 ) )
return false ;
if ( F_8 ( V_10 ) )
* V_8 = F_9 ( V_15 ) ;
else
* V_8 = F_10 ( V_15 ) ;
return true ;
}
static void F_11 ( struct V_7 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
struct V_19 * V_19 = F_12 ( V_3 -> V_4 . V_20 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_21 , V_14 , V_22 ;
if ( F_6 ( V_10 ) ) {
V_21 = V_23 ;
V_14 = V_16 ;
V_22 = V_24 ;
} else {
V_21 = V_25 ;
V_14 = V_17 ;
V_22 = V_26 ;
}
F_13 ( V_14 , F_7 ( V_14 ) | V_18 ) ;
if ( V_1 -> V_27 ) {
F_14 ( L_1 ,
V_1 -> V_28 ,
V_1 -> V_29 ) ;
F_13 ( V_30 , V_1 -> V_29 ) ;
F_13 ( V_31 , V_1 -> V_28 ) ;
V_1 -> V_27 = false ;
}
F_13 ( V_21 , F_7 ( V_21 ) | V_32 ) ;
F_15 ( V_14 ) ;
if ( F_16 ( ( F_7 ( V_22 ) & V_33 ) != 0 , 1000 ) )
F_17 ( L_2 ) ;
F_18 ( V_10 , V_19 -> V_8 ) ;
}
static void F_19 ( struct V_7 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_21 , V_14 , V_22 ;
if ( F_6 ( V_10 ) ) {
V_21 = V_23 ;
V_14 = V_16 ;
V_22 = V_24 ;
} else {
V_21 = V_25 ;
V_14 = V_17 ;
V_22 = V_26 ;
}
F_20 ( V_10 ) ;
F_13 ( V_21 , F_7 ( V_21 ) & ~ V_32 ) ;
if ( F_16 ( ( F_7 ( V_22 ) & V_33 ) == 0 , 1000 ) )
F_17 ( L_3 ) ;
if ( V_1 -> V_28 ) {
F_13 ( V_31 , 0 ) ;
V_1 -> V_27 = true ;
}
F_13 ( V_14 , F_7 ( V_14 ) & ~ V_18 ) ;
F_15 ( V_14 ) ;
}
static int F_21 ( struct V_5 * V_6 ,
struct V_34 * V_35 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_34 * V_36 = V_1 -> V_36 ;
if ( V_35 -> V_37 > V_36 -> V_37 )
return V_38 ;
if ( V_35 -> V_39 > V_36 -> V_39 )
return V_38 ;
return V_40 ;
}
static void
F_22 ( struct V_34 * V_35 ,
int V_41 )
{
T_1 V_42 , V_43 , V_44 , V_45 ;
V_45 = V_35 -> V_46 - V_35 -> V_47 ;
V_44 = V_35 -> V_48 - V_35 -> V_49 ;
V_43 = ( V_44 - V_45 + 1 ) / 2 ;
V_42 = ( V_35 -> V_37 - V_41 + 1 ) / 2 ;
V_42 += V_42 & 1 ;
V_35 -> V_50 = V_41 ;
V_35 -> V_49 = V_41 + V_42 ;
V_35 -> V_48 = V_35 -> V_49 + V_44 ;
V_35 -> V_47 = V_35 -> V_49 + V_43 ;
V_35 -> V_46 = V_35 -> V_47 + V_45 ;
V_35 -> V_51 |= V_52 ;
}
static void
F_23 ( struct V_34 * V_35 ,
int V_53 )
{
T_1 V_42 , V_43 , V_44 , V_45 ;
V_45 = V_35 -> V_54 - V_35 -> V_55 ;
V_44 = V_35 -> V_56 - V_35 -> V_57 ;
V_43 = ( V_44 - V_45 + 1 ) / 2 ;
V_42 = ( V_35 -> V_39 - V_53 + 1 ) / 2 ;
V_35 -> V_58 = V_53 ;
V_35 -> V_57 = V_53 + V_42 ;
V_35 -> V_56 = V_35 -> V_57 + V_44 ;
V_35 -> V_55 = V_35 -> V_57 + V_43 ;
V_35 -> V_54 = V_35 -> V_55 + V_45 ;
V_35 -> V_51 |= V_52 ;
}
static inline T_1 F_24 ( T_1 V_59 , T_1 V_60 )
{
#define F_25 12
#define F_26 (1 << ACCURACY)
T_1 V_61 = V_59 * F_26 / V_60 ;
return ( F_26 * V_61 + F_26 / 2 ) / F_26 ;
}
static bool F_27 ( struct V_2 * V_3 ,
const struct V_34 * V_35 ,
struct V_34 * V_62 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_19 * V_19 = V_1 -> V_4 . V_63 ;
T_1 V_28 = 0 , V_29 = 0 , V_42 = 0 ;
int V_8 ;
if ( F_28 ( V_10 ) -> V_64 < 4 && V_19 -> V_8 == 0 ) {
F_17 ( L_4 ) ;
return false ;
}
if ( F_29 ( & V_1 -> V_4 ) )
return false ;
F_30 ( V_1 -> V_36 , V_62 ) ;
if ( F_6 ( V_10 ) ) {
F_31 ( V_10 , V_1 -> V_65 ,
V_35 , V_62 ) ;
return true ;
}
if ( V_62 -> V_37 == V_35 -> V_37 &&
V_62 -> V_39 == V_35 -> V_39 )
goto V_66;
if ( F_28 ( V_10 ) -> V_64 >= 4 )
V_28 |= ( ( V_19 -> V_8 << V_67 ) |
V_68 ) ;
F_32 (pipe)
F_13 ( F_33 ( V_8 ) , 0 ) ;
F_34 ( V_62 , 0 ) ;
switch ( V_1 -> V_65 ) {
case V_69 :
F_22 ( V_62 , V_35 -> V_37 ) ;
F_23 ( V_62 , V_35 -> V_39 ) ;
V_42 = V_70 ;
break;
case V_71 :
if ( F_28 ( V_10 ) -> V_64 >= 4 ) {
T_1 V_72 = V_62 -> V_37 * V_35 -> V_39 ;
T_1 V_73 = V_35 -> V_37 * V_62 -> V_39 ;
if ( V_72 > V_73 )
V_28 |= V_74 | V_75 ;
else if ( V_72 < V_73 )
V_28 |= V_74 | V_76 ;
else if ( V_62 -> V_37 != V_35 -> V_37 )
V_28 |= V_74 | V_77 ;
} else {
T_1 V_72 = V_62 -> V_37 * V_35 -> V_39 ;
T_1 V_73 = V_35 -> V_37 * V_62 -> V_39 ;
if ( V_72 > V_73 ) {
F_22 ( V_62 , V_73 / V_35 -> V_39 ) ;
V_42 = V_70 ;
if ( V_35 -> V_39 != V_62 -> V_39 ) {
T_1 V_78 = F_24 ( V_35 -> V_39 , V_62 -> V_39 ) ;
V_29 |= ( V_78 << V_79 |
V_78 << V_80 ) ;
V_28 |= ( V_74 |
V_81 |
V_82 ) ;
}
} else if ( V_72 < V_73 ) {
F_23 ( V_62 , V_72 / V_35 -> V_37 ) ;
V_42 = V_70 ;
if ( V_35 -> V_37 != V_62 -> V_37 ) {
T_1 V_78 = F_24 ( V_35 -> V_37 , V_62 -> V_37 ) ;
V_29 |= ( V_78 << V_79 |
V_78 << V_80 ) ;
V_28 |= ( V_74 |
V_81 |
V_82 ) ;
}
} else
V_28 |= ( V_74 |
V_83 | V_84 |
V_81 |
V_82 ) ;
}
break;
case V_85 :
if ( V_35 -> V_39 != V_62 -> V_39 ||
V_35 -> V_37 != V_62 -> V_37 ) {
V_28 |= V_74 ;
if ( F_28 ( V_10 ) -> V_64 >= 4 )
V_28 |= V_77 ;
else
V_28 |= ( V_83 |
V_81 |
V_84 |
V_82 ) ;
}
break;
default:
break;
}
V_66:
if ( ( V_28 & V_74 ) == 0 ) {
V_28 = 0 ;
V_29 = 0 ;
}
if ( F_28 ( V_10 ) -> V_64 < 4 && V_12 -> V_86 )
V_28 |= V_87 ;
if ( V_28 != V_1 -> V_28 ||
V_29 != V_1 -> V_29 ) {
V_1 -> V_28 = V_28 ;
V_1 -> V_29 = V_29 ;
V_1 -> V_27 = true ;
}
V_12 -> V_88 = V_42 ;
return true ;
}
static void F_35 ( struct V_2 * V_3 ,
struct V_34 * V_35 ,
struct V_34 * V_62 )
{
}
static enum V_89
F_36 ( struct V_5 * V_6 , bool V_90 )
{
struct V_9 * V_10 = V_6 -> V_10 ;
enum V_89 V_91 ;
V_91 = F_37 ( V_10 ) ;
if ( V_91 != V_92 )
return V_91 ;
return V_93 ;
}
static int F_38 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_34 * V_35 ;
if ( V_1 -> V_94 )
return F_39 ( V_6 , V_1 -> V_94 ) ;
V_35 = F_40 ( V_10 , V_1 -> V_36 ) ;
if ( V_35 == NULL )
return 0 ;
F_41 ( V_6 , V_35 ) ;
return 1 ;
}
static int F_42 ( const struct V_95 * V_96 )
{
F_43 ( L_5 , V_96 -> V_97 ) ;
return 1 ;
}
static int F_44 ( struct V_98 * V_99 , unsigned long V_100 ,
void * V_101 )
{
struct V_11 * V_12 =
F_2 ( V_99 , struct V_11 , V_102 ) ;
struct V_9 * V_10 = V_12 -> V_10 ;
struct V_5 * V_6 = V_12 -> V_103 ;
if ( V_10 -> V_104 != V_105 )
return V_106 ;
if ( V_6 )
V_6 -> V_91 = V_6 -> V_107 -> V_108 ( V_6 ,
false ) ;
if ( F_45 ( V_109 ) )
return V_106 ;
if ( ! F_46 () ) {
V_12 -> V_110 = 1 ;
return V_106 ;
}
if ( ! V_12 -> V_110 )
return V_106 ;
V_12 -> V_110 = 0 ;
F_47 ( & V_10 -> V_111 . V_112 ) ;
F_48 ( V_10 ) ;
F_49 ( & V_10 -> V_111 . V_112 ) ;
return V_106 ;
}
static void F_50 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
F_51 ( V_10 ) ;
if ( V_12 -> V_102 . V_113 )
F_52 ( & V_12 -> V_102 ) ;
F_53 ( V_6 ) ;
F_54 ( V_6 ) ;
F_55 ( V_6 ) ;
}
static int F_56 ( struct V_5 * V_6 ,
struct V_114 * V_115 ,
T_2 V_116 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
if ( V_115 == V_10 -> V_111 . V_117 ) {
struct V_118 * V_20 = V_1 -> V_4 . V_4 . V_20 ;
if ( V_116 == V_119 ) {
F_14 ( L_6 ) ;
return - V_120 ;
}
if ( V_1 -> V_65 == V_116 ) {
return 0 ;
}
V_1 -> V_65 = V_116 ;
if ( V_20 && V_20 -> V_121 ) {
F_57 ( V_20 , & V_20 -> V_35 ,
V_20 -> V_122 , V_20 -> V_123 , V_20 -> V_124 ) ;
}
}
return 0 ;
}
static int T_3 F_58 ( const struct V_95 * V_96 )
{
F_43 ( L_7 , V_96 -> V_97 ) ;
return 1 ;
}
static void F_59 ( struct V_9 * V_10 ,
struct V_34 * V_36 ,
struct V_5 * V_6 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_34 * V_125 ;
int V_126 ;
V_126 = V_36 -> clock ;
F_60 (scan, &connector->probed_modes, head) {
if ( V_125 -> V_37 == V_36 -> V_37 &&
V_125 -> V_127 == V_36 -> V_127 &&
V_125 -> V_128 == V_36 -> V_128 &&
V_125 -> V_129 == V_36 -> V_129 &&
V_125 -> V_39 == V_36 -> V_39 &&
V_125 -> V_130 == V_36 -> V_130 &&
V_125 -> V_131 == V_36 -> V_131 &&
V_125 -> V_132 == V_36 -> V_132 ) {
if ( V_125 -> clock < V_126 ) {
V_126 = V_125 -> clock ;
}
}
}
if ( V_126 < V_36 -> clock && V_133 ) {
V_12 -> V_134 = 1 ;
V_12 -> V_135 = V_126 ;
F_14 ( L_8
L_9 ,
V_36 -> clock , V_126 ) ;
}
}
static bool F_61 ( struct V_9 * V_10 ,
T_4 * V_136 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
int V_137 ;
if ( ! V_12 -> V_138 )
return true ;
for ( V_137 = 0 ; V_137 < V_12 -> V_138 ; V_137 ++ ) {
struct V_139 * V_140 = V_12 -> V_141 + V_137 ;
if ( V_140 -> V_142 != V_143 &&
V_140 -> V_142 != V_144 )
continue;
if ( F_62 ( V_140 -> V_136 ) )
* V_136 = V_140 -> V_136 ;
if ( V_140 -> V_145 )
return true ;
if ( V_12 -> V_146 . V_147 )
return true ;
}
return false ;
}
static bool F_63 ( struct V_9 * V_10 )
{
if ( F_6 ( V_10 ) )
return true ;
return F_64 ( V_10 ) && ! F_65 ( V_10 ) ;
}
bool F_66 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 ;
struct V_7 * V_7 ;
struct V_148 * V_148 ;
struct V_5 * V_6 ;
struct V_2 * V_3 ;
struct V_34 * V_125 ;
struct V_118 * V_20 ;
T_1 V_149 ;
int V_8 ;
T_4 V_150 ;
if ( ! F_63 ( V_10 ) )
return false ;
if ( F_45 ( V_151 ) )
return false ;
V_150 = V_152 ;
if ( ! F_61 ( V_10 , & V_150 ) ) {
F_14 ( L_10 ) ;
return false ;
}
if ( F_6 ( V_10 ) ) {
if ( ( F_7 ( V_16 ) & V_153 ) == 0 )
return false ;
if ( V_12 -> V_154 . V_155 ) {
F_14 ( L_11 ) ;
return false ;
}
}
V_1 = F_67 ( sizeof( struct V_1 ) , V_156 ) ;
if ( ! V_1 ) {
return false ;
}
V_148 = F_67 ( sizeof( struct V_148 ) , V_156 ) ;
if ( ! V_148 ) {
F_55 ( V_1 ) ;
return false ;
}
if ( ! F_6 ( V_10 ) ) {
V_1 -> V_28 = F_7 ( V_31 ) ;
}
V_7 = & V_1 -> V_4 ;
V_3 = & V_7 -> V_4 ;
V_6 = & V_148 -> V_4 ;
F_68 ( V_10 , & V_148 -> V_4 , & V_157 ,
V_158 ) ;
F_69 ( V_10 , & V_7 -> V_4 , & V_159 ,
V_160 ) ;
V_7 -> V_161 = F_11 ;
V_7 -> V_162 = F_19 ;
V_7 -> V_163 = F_5 ;
V_148 -> V_163 = V_164 ;
F_70 ( V_148 , V_7 ) ;
V_7 -> type = V_165 ;
V_7 -> V_166 = false ;
if ( F_6 ( V_10 ) )
V_7 -> V_167 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
else if ( F_71 ( V_10 ) )
V_7 -> V_167 = ( 1 << 0 ) | ( 1 << 1 ) ;
else
V_7 -> V_167 = ( 1 << 1 ) ;
F_72 ( V_3 , & V_168 ) ;
F_73 ( V_6 , & V_169 ) ;
V_6 -> V_170 . V_171 = V_172 ;
V_6 -> V_173 = false ;
V_6 -> V_174 = false ;
F_74 ( V_10 ) ;
F_75 ( & V_148 -> V_4 ,
V_10 -> V_111 . V_117 ,
V_71 ) ;
V_1 -> V_65 = V_71 ;
V_1 -> V_94 = F_76 ( V_6 ,
F_77 ( V_12 ,
V_150 ) ) ;
if ( V_1 -> V_94 ) {
if ( F_39 ( V_6 ,
V_1 -> V_94 ) ) {
F_78 ( V_6 ,
V_1 -> V_94 ) ;
} else {
F_55 ( V_1 -> V_94 ) ;
V_1 -> V_94 = NULL ;
}
}
if ( ! V_1 -> V_94 ) {
V_6 -> V_170 . V_175 = 0 ;
V_6 -> V_170 . V_176 = 200 ;
V_6 -> V_170 . V_177 = 0 ;
V_6 -> V_170 . V_178 = 200 ;
}
F_60 (scan, &connector->probed_modes, head) {
if ( V_125 -> type & V_179 ) {
V_1 -> V_36 =
F_40 ( V_10 , V_125 ) ;
F_59 ( V_10 ,
V_1 -> V_36 ,
V_6 ) ;
goto V_66;
}
}
if ( V_12 -> V_180 ) {
V_1 -> V_36 =
F_40 ( V_10 , V_12 -> V_180 ) ;
if ( V_1 -> V_36 ) {
V_1 -> V_36 -> type |=
V_179 ;
goto V_66;
}
}
if ( F_6 ( V_10 ) )
goto V_181;
V_149 = F_7 ( V_17 ) ;
V_8 = ( V_149 & V_182 ) ? 1 : 0 ;
V_20 = F_79 ( V_10 , V_8 ) ;
if ( V_20 && ( V_149 & V_18 ) ) {
V_1 -> V_36 = F_80 ( V_10 , V_20 ) ;
if ( V_1 -> V_36 ) {
V_1 -> V_36 -> type |=
V_179 ;
goto V_66;
}
}
if ( ! V_1 -> V_36 )
goto V_181;
V_66:
if ( F_6 ( V_10 ) ) {
F_13 ( V_23 ,
F_7 ( V_23 ) | V_183 ) ;
} else {
F_13 ( V_25 ,
F_7 ( V_25 ) | V_183 ) ;
}
V_12 -> V_102 . V_113 = F_44 ;
if ( F_81 ( & V_12 -> V_102 ) ) {
F_14 ( L_12 ) ;
V_12 -> V_102 . V_113 = NULL ;
}
V_12 -> V_103 = V_6 ;
F_82 ( V_6 ) ;
F_83 ( V_10 ) ;
return true ;
V_181:
F_14 ( L_13 ) ;
F_54 ( V_6 ) ;
F_84 ( V_3 ) ;
F_55 ( V_1 ) ;
F_55 ( V_148 ) ;
return false ;
}
