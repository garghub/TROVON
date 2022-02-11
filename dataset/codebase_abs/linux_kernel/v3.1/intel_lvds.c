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
}
static void
F_19 ( struct V_31 * V_29 ,
int V_47 )
{
T_1 V_38 , V_39 , V_40 , V_41 ;
V_41 = V_29 -> V_48 - V_29 -> V_49 ;
V_40 = V_29 -> V_50 - V_29 -> V_51 ;
V_39 = ( V_40 - V_41 + 1 ) / 2 ;
V_38 = ( V_29 -> V_35 - V_47 + 1 ) / 2 ;
V_29 -> V_52 = V_47 ;
V_29 -> V_51 = V_47 + V_38 ;
V_29 -> V_50 = V_29 -> V_51 + V_40 ;
V_29 -> V_49 = V_29 -> V_51 + V_39 ;
V_29 -> V_48 = V_29 -> V_49 + V_41 ;
}
static inline T_1 F_20 ( T_1 V_53 , T_1 V_54 )
{
#define F_21 12
#define F_22 (1 << ACCURACY)
T_1 V_55 = V_53 * F_22 / V_54 ;
return ( F_22 * V_55 + F_22 / 2 ) / F_22 ;
}
static bool F_23 ( struct V_2 * V_3 ,
struct V_31 * V_29 ,
struct V_31 * V_56 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_57 * V_57 = F_24 ( V_3 -> V_58 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_2 * V_59 ;
T_1 V_23 = 0 , V_24 = 0 , V_38 = 0 ;
int V_60 ;
if ( F_25 ( V_8 ) -> V_61 < 4 && V_57 -> V_60 == 0 ) {
F_12 ( L_4 ) ;
return false ;
}
F_26 (tmp_encoder, &dev->mode_config.encoder_list, head) {
if ( V_59 != V_3 && V_59 -> V_58 == V_3 -> V_58 ) {
F_12 ( L_5
L_6 ) ;
return false ;
}
}
F_27 ( V_1 -> V_32 , V_56 ) ;
if ( F_6 ( V_8 ) ) {
F_28 ( V_8 , V_1 -> V_62 ,
V_29 , V_56 ) ;
return true ;
}
if ( V_56 -> V_33 == V_29 -> V_33 &&
V_56 -> V_35 == V_29 -> V_35 )
goto V_63;
if ( F_25 ( V_8 ) -> V_61 >= 4 )
V_23 |= ( ( V_57 -> V_60 << V_64 ) |
V_65 ) ;
F_29 (pipe)
F_7 ( F_30 ( V_60 ) , 0 ) ;
switch ( V_1 -> V_62 ) {
case V_66 :
F_18 ( V_56 , V_29 -> V_33 ) ;
F_19 ( V_56 , V_29 -> V_35 ) ;
V_38 = V_67 ;
break;
case V_68 :
if ( F_25 ( V_8 ) -> V_61 >= 4 ) {
T_1 V_69 = V_56 -> V_33 * V_29 -> V_35 ;
T_1 V_70 = V_29 -> V_33 * V_56 -> V_35 ;
if ( V_69 > V_70 )
V_23 |= V_71 | V_72 ;
else if ( V_69 < V_70 )
V_23 |= V_71 | V_73 ;
else if ( V_56 -> V_33 != V_29 -> V_33 )
V_23 |= V_71 | V_74 ;
} else {
T_1 V_69 = V_56 -> V_33 * V_29 -> V_35 ;
T_1 V_70 = V_29 -> V_33 * V_56 -> V_35 ;
if ( V_69 > V_70 ) {
F_18 ( V_56 , V_70 / V_29 -> V_35 ) ;
V_38 = V_67 ;
if ( V_29 -> V_35 != V_56 -> V_35 ) {
T_1 V_75 = F_20 ( V_29 -> V_35 , V_56 -> V_35 ) ;
V_24 |= ( V_75 << V_76 |
V_75 << V_77 ) ;
V_23 |= ( V_71 |
V_78 |
V_79 ) ;
}
} else if ( V_69 < V_70 ) {
F_19 ( V_56 , V_69 / V_29 -> V_33 ) ;
V_38 = V_67 ;
if ( V_29 -> V_33 != V_56 -> V_33 ) {
T_1 V_75 = F_20 ( V_29 -> V_33 , V_56 -> V_33 ) ;
V_24 |= ( V_75 << V_76 |
V_75 << V_77 ) ;
V_23 |= ( V_71 |
V_78 |
V_79 ) ;
}
} else
V_23 |= ( V_71 |
V_80 | V_81 |
V_78 |
V_79 ) ;
}
break;
case V_82 :
if ( V_29 -> V_35 != V_56 -> V_35 ||
V_29 -> V_33 != V_56 -> V_33 ) {
V_23 |= V_71 ;
if ( F_25 ( V_8 ) -> V_61 >= 4 )
V_23 |= V_74 ;
else
V_23 |= ( V_80 |
V_78 |
V_81 |
V_79 ) ;
}
break;
default:
break;
}
V_63:
if ( ( V_23 & V_71 ) == 0 ) {
V_23 = 0 ;
V_24 = 0 ;
}
if ( F_25 ( V_8 ) -> V_61 < 4 && V_10 -> V_83 )
V_23 |= V_84 ;
if ( V_23 != V_1 -> V_23 ||
V_24 != V_1 -> V_24 ) {
V_1 -> V_23 = V_23 ;
V_1 -> V_24 = V_24 ;
V_1 -> V_22 = true ;
}
V_10 -> V_85 = V_38 ;
return true ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( ! F_6 ( V_3 -> V_8 ) && V_1 -> V_22 )
F_14 ( V_1 ) ;
}
static void F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_5 ( V_1 ) ;
}
static void F_33 ( struct V_2 * V_3 ,
struct V_31 * V_29 ,
struct V_31 * V_56 )
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
struct V_31 * V_29 ;
if ( V_1 -> V_91 )
return F_37 ( V_6 , V_1 -> V_91 ) ;
V_29 = F_38 ( V_8 , V_1 -> V_32 ) ;
if ( V_29 == NULL )
return 0 ;
F_39 ( V_6 , V_29 ) ;
return 1 ;
}
static int F_40 ( const struct V_92 * V_93 )
{
F_9 ( L_7 , V_93 -> V_94 ) ;
return 1 ;
}
static int F_41 ( struct V_95 * V_96 , unsigned long V_97 ,
void * V_98 )
{
struct V_9 * V_10 =
F_2 ( V_96 , struct V_9 , V_99 ) ;
struct V_7 * V_8 = V_10 -> V_8 ;
struct V_5 * V_6 = V_10 -> V_100 ;
if ( V_8 -> V_101 != V_102 )
return V_103 ;
if ( V_6 )
V_6 -> V_88 = V_6 -> V_104 -> V_105 ( V_6 ,
false ) ;
if ( F_42 ( V_106 ) )
return V_103 ;
if ( ! F_43 () ) {
V_10 -> V_107 = 1 ;
return V_103 ;
}
if ( ! V_10 -> V_107 )
return V_103 ;
V_10 -> V_107 = 0 ;
F_44 ( & V_8 -> V_108 . V_109 ) ;
F_45 ( V_8 ) ;
F_46 ( & V_8 -> V_108 . V_109 ) ;
return V_103 ;
}
static void F_47 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_11 ;
F_48 ( V_8 ) ;
if ( V_10 -> V_99 . V_110 )
F_49 ( & V_10 -> V_99 ) ;
F_50 ( V_6 ) ;
F_51 ( V_6 ) ;
F_52 ( V_6 ) ;
}
static int F_53 ( struct V_5 * V_6 ,
struct V_111 * V_112 ,
T_2 V_113 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_112 == V_8 -> V_108 . V_114 ) {
struct V_115 * V_58 = V_1 -> V_4 . V_4 . V_58 ;
if ( V_113 == V_116 ) {
F_9 ( L_8 ) ;
return - V_117 ;
}
if ( V_1 -> V_62 == V_113 ) {
return 0 ;
}
V_1 -> V_62 = V_113 ;
if ( V_58 && V_58 -> V_118 ) {
F_54 ( V_58 , & V_58 -> V_29 ,
V_58 -> V_119 , V_58 -> V_120 , V_58 -> V_121 ) ;
}
}
return 0 ;
}
static int T_3 F_55 ( const struct V_92 * V_93 )
{
F_9 ( L_9 , V_93 -> V_94 ) ;
return 1 ;
}
static void F_56 ( struct V_7 * V_8 ,
struct V_31 * V_32 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_31 * V_122 ;
int V_123 ;
V_123 = V_32 -> clock ;
F_26 (scan, &connector->probed_modes, head) {
if ( V_122 -> V_33 == V_32 -> V_33 &&
V_122 -> V_124 == V_32 -> V_124 &&
V_122 -> V_125 == V_32 -> V_125 &&
V_122 -> V_126 == V_32 -> V_126 &&
V_122 -> V_35 == V_32 -> V_35 &&
V_122 -> V_127 == V_32 -> V_127 &&
V_122 -> V_128 == V_32 -> V_128 &&
V_122 -> V_129 == V_32 -> V_129 ) {
if ( V_122 -> clock < V_123 ) {
V_123 = V_122 -> clock ;
}
}
}
if ( V_123 < V_32 -> clock && V_130 ) {
V_10 -> V_131 = 1 ;
V_10 -> V_132 = V_123 ;
F_9 ( L_10
L_11 ,
V_32 -> clock , V_123 ) ;
}
}
static bool F_57 ( struct V_7 * V_8 ,
T_4 * V_133 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
int V_134 ;
if ( ! V_10 -> V_135 )
return true ;
for ( V_134 = 0 ; V_134 < V_10 -> V_135 ; V_134 ++ ) {
struct V_136 * V_137 = V_10 -> V_138 + V_134 ;
if ( V_137 -> V_139 != V_140 &&
V_137 -> V_139 != V_141 )
continue;
if ( V_137 -> V_133 )
* V_133 = V_137 -> V_133 ;
if ( V_137 -> V_142 )
return true ;
if ( V_10 -> V_143 . V_144 )
return true ;
}
return false ;
}
bool F_58 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_1 ;
struct V_145 * V_145 ;
struct V_146 * V_146 ;
struct V_5 * V_6 ;
struct V_2 * V_3 ;
struct V_31 * V_122 ;
struct V_115 * V_58 ;
T_1 V_147 ;
int V_60 ;
T_4 V_148 ;
if ( F_42 ( V_149 ) )
return false ;
V_148 = V_150 ;
if ( ! F_57 ( V_8 , & V_148 ) ) {
F_9 ( L_12 ) ;
return false ;
}
if ( F_6 ( V_8 ) ) {
if ( ( F_8 ( V_16 ) & V_151 ) == 0 )
return false ;
if ( V_10 -> V_152 . V_153 ) {
F_9 ( L_13 ) ;
return false ;
}
}
V_1 = F_59 ( sizeof( struct V_1 ) , V_154 ) ;
if ( ! V_1 ) {
return false ;
}
V_146 = F_59 ( sizeof( struct V_146 ) , V_154 ) ;
if ( ! V_146 ) {
F_52 ( V_1 ) ;
return false ;
}
if ( ! F_6 ( V_8 ) ) {
V_1 -> V_23 = F_8 ( V_26 ) ;
}
V_145 = & V_1 -> V_4 ;
V_3 = & V_145 -> V_4 ;
V_6 = & V_146 -> V_4 ;
F_60 ( V_8 , & V_146 -> V_4 , & V_155 ,
V_156 ) ;
F_61 ( V_8 , & V_145 -> V_4 , & V_157 ,
V_158 ) ;
F_62 ( V_146 , V_145 ) ;
V_145 -> type = V_159 ;
V_145 -> V_160 = ( 1 << V_161 ) ;
V_145 -> V_162 = ( 1 << 1 ) ;
if ( F_25 ( V_8 ) -> V_61 >= 5 )
V_145 -> V_162 |= ( 1 << 0 ) ;
F_63 ( V_3 , & V_163 ) ;
F_64 ( V_6 , & V_164 ) ;
V_6 -> V_165 . V_166 = V_167 ;
V_6 -> V_168 = false ;
V_6 -> V_169 = false ;
F_65 ( V_8 ) ;
F_66 ( & V_146 -> V_4 ,
V_8 -> V_108 . V_114 ,
V_68 ) ;
V_1 -> V_62 = V_68 ;
V_1 -> V_91 = F_67 ( V_6 ,
& V_10 -> V_170 [ V_148 ] . V_171 ) ;
if ( V_1 -> V_91 ) {
if ( F_37 ( V_6 ,
V_1 -> V_91 ) ) {
F_68 ( V_6 ,
V_1 -> V_91 ) ;
} else {
F_52 ( V_1 -> V_91 ) ;
V_1 -> V_91 = NULL ;
}
}
if ( ! V_1 -> V_91 ) {
V_6 -> V_165 . V_172 = 0 ;
V_6 -> V_165 . V_173 = 200 ;
V_6 -> V_165 . V_174 = 0 ;
V_6 -> V_165 . V_175 = 200 ;
}
F_26 (scan, &connector->probed_modes, head) {
if ( V_122 -> type & V_176 ) {
V_1 -> V_32 =
F_38 ( V_8 , V_122 ) ;
F_56 ( V_8 ,
V_1 -> V_32 ,
V_6 ) ;
goto V_63;
}
}
if ( V_10 -> V_177 ) {
V_1 -> V_32 =
F_38 ( V_8 , V_10 -> V_177 ) ;
if ( V_1 -> V_32 ) {
V_1 -> V_32 -> type |=
V_176 ;
goto V_63;
}
}
if ( F_6 ( V_8 ) )
goto V_178;
V_147 = F_8 ( V_19 ) ;
V_60 = ( V_147 & V_179 ) ? 1 : 0 ;
V_58 = F_69 ( V_8 , V_60 ) ;
if ( V_58 && ( V_147 & V_21 ) ) {
V_1 -> V_32 = F_70 ( V_8 , V_58 ) ;
if ( V_1 -> V_32 ) {
V_1 -> V_32 -> type |=
V_176 ;
goto V_63;
}
}
if ( ! V_1 -> V_32 )
goto V_178;
V_63:
if ( F_6 ( V_8 ) ) {
T_1 V_180 ;
V_60 = ( F_8 ( V_16 ) & V_179 ) ? 1 : 0 ;
V_180 = F_8 ( V_181 ) ;
if ( V_60 == 0 && ( V_180 & V_182 ) )
F_7 ( V_181 , V_180 & ~ V_183 ) ;
if ( V_60 )
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
V_10 -> V_99 . V_110 = F_41 ;
if ( F_71 ( & V_10 -> V_99 ) ) {
F_9 ( L_14 ) ;
V_10 -> V_99 . V_110 = NULL ;
}
V_10 -> V_100 = V_6 ;
F_72 ( V_6 ) ;
F_73 ( V_8 ) ;
return true ;
V_178:
F_9 ( L_15 ) ;
F_51 ( V_6 ) ;
F_74 ( V_3 ) ;
F_52 ( V_1 ) ;
F_52 ( V_146 ) ;
return false ;
}
