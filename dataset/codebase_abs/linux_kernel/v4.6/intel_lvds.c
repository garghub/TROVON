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
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
enum V_16 V_17 ;
T_1 V_18 ;
bool V_19 ;
V_17 = F_5 ( V_3 ) ;
if ( ! F_6 ( V_13 , V_17 ) )
return false ;
V_19 = false ;
V_18 = F_7 ( V_15 -> V_20 ) ;
if ( ! ( V_18 & V_21 ) )
goto V_22;
if ( F_8 ( V_11 ) )
* V_9 = F_9 ( V_18 ) ;
else
* V_9 = F_10 ( V_18 ) ;
V_19 = true ;
V_22:
F_11 ( V_13 , V_17 ) ;
return V_19 ;
}
static void F_12 ( struct V_8 * V_3 ,
struct V_23 * V_24 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_18 , V_25 = 0 ;
int V_26 ;
V_18 = F_7 ( V_15 -> V_20 ) ;
if ( V_18 & V_27 )
V_25 |= V_28 ;
else
V_25 |= V_29 ;
if ( V_18 & V_30 )
V_25 |= V_31 ;
else
V_25 |= V_32 ;
V_24 -> V_4 . V_33 . V_25 |= V_25 ;
if ( F_13 ( V_11 ) -> V_34 < 5 )
V_24 -> V_35 . V_36 =
V_18 & V_37 ;
if ( F_13 ( V_11 ) -> V_34 < 4 ) {
V_18 = F_7 ( V_38 ) ;
V_24 -> V_35 . V_39 |= V_18 & V_40 ;
}
V_26 = V_24 -> V_41 ;
if ( F_14 ( V_13 -> V_11 ) )
F_15 ( V_24 , V_26 ) ;
V_24 -> V_4 . V_33 . V_42 = V_26 ;
}
static void F_16 ( struct V_8 * V_3 )
{
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_43 * V_44 = F_17 ( V_3 -> V_4 . V_44 ) ;
const struct V_45 * V_33 = & V_44 -> V_46 -> V_4 . V_33 ;
int V_9 = V_44 -> V_9 ;
T_1 V_47 ;
if ( F_14 ( V_11 ) ) {
F_18 ( V_13 , V_9 ) ;
F_19 ( V_13 ,
F_20 ( V_44 ) ) ;
} else {
F_21 ( V_13 , V_9 ) ;
}
V_47 = F_7 ( V_15 -> V_20 ) ;
V_47 |= V_21 | V_48 ;
if ( F_8 ( V_11 ) ) {
V_47 &= ~ V_49 ;
V_47 |= F_22 ( V_9 ) ;
} else {
if ( V_9 == 1 ) {
V_47 |= V_50 ;
} else {
V_47 &= ~ V_50 ;
}
}
V_47 &= ~ V_37 ;
V_47 |= V_44 -> V_46 -> V_35 . V_36 ;
if ( V_15 -> V_51 )
V_47 |= V_52 | V_53 ;
else
V_47 &= ~ ( V_52 | V_53 ) ;
V_47 &= ~ V_54 ;
V_47 |= V_15 -> V_55 ;
if ( F_13 ( V_11 ) -> V_34 == 4 ) {
if ( V_44 -> V_46 -> V_56 && V_44 -> V_46 -> V_57 == 18 )
V_47 |= V_58 ;
else
V_47 &= ~ V_58 ;
}
V_47 &= ~ ( V_27 | V_30 ) ;
if ( V_33 -> V_25 & V_28 )
V_47 |= V_27 ;
if ( V_33 -> V_25 & V_31 )
V_47 |= V_30 ;
F_23 ( V_15 -> V_20 , V_47 ) ;
}
static void F_24 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_59 * V_59 =
& V_15 -> V_60 -> V_4 ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_2 V_61 , V_62 ;
if ( F_14 ( V_11 ) ) {
V_61 = V_63 ;
V_62 = V_64 ;
} else {
V_61 = V_65 ;
V_62 = V_66 ;
}
F_23 ( V_15 -> V_20 , F_7 ( V_15 -> V_20 ) | V_21 ) ;
F_23 ( V_61 , F_7 ( V_61 ) | V_67 ) ;
F_25 ( V_15 -> V_20 ) ;
if ( F_26 ( ( F_7 ( V_62 ) & V_68 ) != 0 , 1000 ) )
F_27 ( L_1 ) ;
F_28 ( V_59 ) ;
}
static void F_29 ( struct V_8 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_4 . V_11 ;
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_12 * V_13 = V_11 -> V_14 ;
T_2 V_61 , V_62 ;
if ( F_14 ( V_11 ) ) {
V_61 = V_63 ;
V_62 = V_64 ;
} else {
V_61 = V_65 ;
V_62 = V_66 ;
}
F_23 ( V_61 , F_7 ( V_61 ) & ~ V_67 ) ;
if ( F_26 ( ( F_7 ( V_62 ) & V_68 ) == 0 , 1000 ) )
F_27 ( L_2 ) ;
F_23 ( V_15 -> V_20 , F_7 ( V_15 -> V_20 ) & ~ V_21 ) ;
F_25 ( V_15 -> V_20 ) ;
}
static void F_30 ( struct V_8 * V_3 )
{
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_59 * V_59 =
& V_15 -> V_60 -> V_4 ;
F_31 ( V_59 ) ;
F_29 ( V_3 ) ;
}
static void F_32 ( struct V_8 * V_3 )
{
struct V_1 * V_15 = F_1 ( & V_3 -> V_4 ) ;
struct V_59 * V_59 =
& V_15 -> V_60 -> V_4 ;
F_31 ( V_59 ) ;
}
static void F_33 ( struct V_8 * V_3 )
{
F_29 ( V_3 ) ;
}
static enum V_69
F_34 ( struct V_6 * V_7 ,
struct V_45 * V_70 )
{
struct V_59 * V_59 = F_35 ( V_7 ) ;
struct V_45 * V_71 = V_59 -> V_72 . V_71 ;
int V_73 = F_36 ( V_7 -> V_11 ) -> V_74 ;
if ( V_70 -> V_75 > V_71 -> V_75 )
return V_76 ;
if ( V_70 -> V_77 > V_71 -> V_77 )
return V_76 ;
if ( V_71 -> clock > V_73 )
return V_78 ;
return V_79 ;
}
static bool F_37 ( struct V_8 * V_8 ,
struct V_23 * V_24 )
{
struct V_10 * V_11 = V_8 -> V_4 . V_11 ;
struct V_1 * V_15 =
F_1 ( & V_8 -> V_4 ) ;
struct V_59 * V_59 =
& V_15 -> V_60 -> V_4 ;
struct V_45 * V_33 = & V_24 -> V_4 . V_33 ;
struct V_43 * V_43 = F_17 ( V_24 -> V_4 . V_44 ) ;
unsigned int V_80 ;
if ( F_13 ( V_11 ) -> V_34 < 4 && V_43 -> V_9 == 0 ) {
F_27 ( L_3 ) ;
return false ;
}
if ( V_15 -> V_55 == V_81 )
V_80 = 8 * 3 ;
else
V_80 = 6 * 3 ;
if ( V_80 != V_24 -> V_57 && ! V_24 -> V_82 ) {
F_38 ( L_4 ,
V_24 -> V_57 , V_80 ) ;
V_24 -> V_57 = V_80 ;
}
F_39 ( V_59 -> V_72 . V_71 ,
V_33 ) ;
if ( F_14 ( V_11 ) ) {
V_24 -> V_83 = true ;
F_40 ( V_43 , V_24 ,
V_59 -> V_72 . V_84 ) ;
} else {
F_41 ( V_43 , V_24 ,
V_59 -> V_72 . V_84 ) ;
}
return true ;
}
static enum V_85
F_42 ( struct V_6 * V_7 , bool V_86 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
enum V_85 V_87 ;
F_38 ( L_5 ,
V_7 -> V_4 . V_88 , V_7 -> V_89 ) ;
V_87 = F_43 ( V_11 ) ;
if ( V_87 != V_90 )
return V_87 ;
return V_91 ;
}
static int F_44 ( struct V_6 * V_7 )
{
struct V_5 * V_92 = F_3 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_45 * V_70 ;
if ( ! F_45 ( V_92 -> V_4 . V_93 ) )
return F_46 ( V_7 , V_92 -> V_4 . V_93 ) ;
V_70 = F_47 ( V_11 , V_92 -> V_4 . V_72 . V_71 ) ;
if ( V_70 == NULL )
return 0 ;
F_48 ( V_7 , V_70 ) ;
return 1 ;
}
static int F_49 ( const struct V_94 * V_88 )
{
F_50 ( L_6 , V_88 -> V_95 ) ;
return 1 ;
}
static int F_51 ( struct V_96 * V_97 , unsigned long V_98 ,
void * V_99 )
{
struct V_5 * V_92 =
F_2 ( V_97 , struct V_5 , V_100 ) ;
struct V_6 * V_7 = & V_92 -> V_4 . V_4 ;
struct V_10 * V_11 = V_7 -> V_11 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_11 -> V_101 != V_102 )
return V_103 ;
F_52 ( & V_13 -> V_104 ) ;
if ( V_13 -> V_105 == V_106 )
goto exit;
V_7 -> V_87 = V_7 -> V_107 -> V_108 ( V_7 , false ) ;
if ( F_53 ( V_109 ) )
goto exit;
if ( ! F_54 () ) {
V_13 -> V_105 = V_110 ;
goto exit;
}
if ( V_13 -> V_105 == V_111 )
goto exit;
if ( ! F_14 ( V_11 ) )
F_55 ( V_11 ) ;
V_13 -> V_105 = V_111 ;
exit:
F_56 ( & V_13 -> V_104 ) ;
return V_103 ;
}
static void F_57 ( struct V_6 * V_7 )
{
struct V_5 * V_92 =
F_3 ( V_7 ) ;
if ( V_92 -> V_100 . V_112 )
F_58 ( & V_92 -> V_100 ) ;
if ( ! F_45 ( V_92 -> V_4 . V_93 ) )
F_59 ( V_92 -> V_4 . V_93 ) ;
F_60 ( & V_92 -> V_4 . V_72 ) ;
F_61 ( V_7 ) ;
F_59 ( V_7 ) ;
}
static int F_62 ( struct V_6 * V_7 ,
struct V_113 * V_114 ,
T_3 V_115 )
{
struct V_59 * V_59 = F_35 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
if ( V_114 == V_11 -> V_116 . V_117 ) {
struct V_118 * V_44 ;
if ( V_115 == V_119 ) {
F_38 ( L_7 ) ;
return - V_120 ;
}
if ( V_59 -> V_72 . V_84 == V_115 ) {
return 0 ;
}
V_59 -> V_72 . V_84 = V_115 ;
V_44 = F_63 ( V_7 ) -> V_4 . V_44 ;
if ( V_44 && V_44 -> V_121 -> V_122 ) {
F_64 ( V_44 ) ;
}
}
return 0 ;
}
static int F_65 ( const struct V_94 * V_88 )
{
F_50 ( L_8 , V_88 -> V_95 ) ;
return 1 ;
}
static bool F_66 ( struct V_10 * V_11 ,
T_4 * V_123 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
int V_124 ;
if ( ! V_13 -> V_125 . V_126 )
return true ;
for ( V_124 = 0 ; V_124 < V_13 -> V_125 . V_126 ; V_124 ++ ) {
union V_127 * V_128 = V_13 -> V_125 . V_129 + V_124 ;
struct V_130 * V_131 = & V_128 -> V_132 ;
if ( V_131 -> V_133 != V_134 &&
V_131 -> V_133 != V_135 )
continue;
if ( F_67 ( V_13 , V_131 -> V_123 ) )
* V_123 = V_131 -> V_123 ;
if ( V_131 -> V_136 )
return true ;
if ( V_13 -> V_137 . V_125 )
return true ;
}
return false ;
}
static int F_68 ( const struct V_94 * V_88 )
{
F_50 ( L_9 , V_88 -> V_95 ) ;
return 1 ;
}
bool F_69 ( struct V_10 * V_11 )
{
struct V_8 * V_3 ;
struct V_1 * V_15 ;
F_70 (dev, encoder) {
if ( V_3 -> type == V_138 ) {
V_15 = F_1 ( & V_3 -> V_4 ) ;
return V_15 -> V_51 ;
}
}
return false ;
}
static bool F_71 ( struct V_1 * V_15 )
{
struct V_10 * V_11 = V_15 -> V_4 . V_4 . V_11 ;
unsigned int V_98 ;
struct V_12 * V_13 = V_11 -> V_14 ;
if ( V_139 . V_140 > 0 )
return V_139 . V_140 == 2 ;
if ( V_15 -> V_60 -> V_4 . V_72 . V_71 -> clock
> 112999 )
return true ;
if ( F_53 ( V_141 ) )
return true ;
V_98 = F_7 ( V_15 -> V_20 ) ;
if ( ! ( V_98 & ~ ( V_142 | V_143 ) ) )
V_98 = V_13 -> V_125 . V_144 ;
return ( V_98 & V_145 ) == V_53 ;
}
static bool F_72 ( struct V_10 * V_11 )
{
if ( F_73 ( V_11 ) || F_8 ( V_11 ) )
return true ;
if ( F_13 ( V_11 ) -> V_34 <= 4 && F_74 ( V_11 ) && ! F_75 ( V_11 ) )
return true ;
return false ;
}
void F_76 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 ;
struct V_1 * V_15 ;
struct V_8 * V_8 ;
struct V_5 * V_92 ;
struct V_59 * V_59 ;
struct V_6 * V_7 ;
struct V_2 * V_3 ;
struct V_45 * V_146 ;
struct V_45 * V_71 = NULL ;
struct V_45 * V_147 = NULL ;
struct V_93 * V_93 ;
struct V_118 * V_44 ;
T_2 V_148 ;
T_1 V_149 ;
int V_9 ;
T_4 V_150 ;
if ( F_14 ( V_11 ) ) {
F_23 ( V_63 ,
F_7 ( V_63 ) | V_151 ) ;
} else if ( F_13 ( V_13 ) -> V_34 < 5 ) {
F_23 ( V_65 ,
F_7 ( V_65 ) | V_151 ) ;
}
if ( ! F_72 ( V_11 ) )
return;
if ( F_53 ( V_152 ) )
return;
if ( F_14 ( V_11 ) )
V_148 = V_153 ;
else
V_148 = V_154 ;
V_149 = F_7 ( V_148 ) ;
if ( F_14 ( V_11 ) ) {
if ( ( V_149 & V_143 ) == 0 )
return;
if ( V_13 -> V_125 . V_155 ) {
F_38 ( L_10 ) ;
return;
}
}
V_150 = V_156 ;
if ( ! F_66 ( V_11 , & V_150 ) ) {
if ( ( V_149 & V_21 ) == 0 ) {
F_38 ( L_11 ) ;
return;
}
F_38 ( L_12 ) ;
}
if ( F_13 ( V_13 ) -> V_34 < 5 &&
F_7 ( V_157 ) == 0 && F_7 ( V_158 ) == 0 ) {
F_23 ( V_157 , 0x019007d0 ) ;
F_23 ( V_158 , 0x015e07d0 ) ;
F_38 ( L_13 ) ;
}
V_15 = F_77 ( sizeof( * V_15 ) , V_159 ) ;
if ( ! V_15 )
return;
V_92 = F_77 ( sizeof( * V_92 ) , V_159 ) ;
if ( ! V_92 ) {
F_59 ( V_15 ) ;
return;
}
if ( F_78 ( & V_92 -> V_4 ) < 0 ) {
F_59 ( V_92 ) ;
F_59 ( V_15 ) ;
return;
}
V_15 -> V_60 = V_92 ;
V_8 = & V_15 -> V_4 ;
V_3 = & V_8 -> V_4 ;
V_59 = & V_92 -> V_4 ;
V_7 = & V_59 -> V_4 ;
F_79 ( V_11 , & V_59 -> V_4 , & V_160 ,
V_161 ) ;
F_80 ( V_11 , & V_8 -> V_4 , & V_162 ,
V_163 , NULL ) ;
V_8 -> V_122 = F_24 ;
V_8 -> V_164 = F_16 ;
V_8 -> V_165 = F_37 ;
if ( F_14 ( V_13 ) ) {
V_8 -> V_166 = F_32 ;
V_8 -> V_167 = F_33 ;
} else {
V_8 -> V_166 = F_30 ;
}
V_8 -> V_168 = F_4 ;
V_8 -> V_169 = F_12 ;
V_59 -> V_168 = V_170 ;
V_59 -> V_171 = V_172 ;
F_81 ( V_59 , V_8 ) ;
V_8 -> type = V_138 ;
V_8 -> V_173 = 0 ;
if ( F_14 ( V_11 ) )
V_8 -> V_174 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
else if ( F_82 ( V_11 ) )
V_8 -> V_174 = ( 1 << 0 ) | ( 1 << 1 ) ;
else
V_8 -> V_174 = ( 1 << 1 ) ;
F_83 ( V_7 , & V_175 ) ;
V_7 -> V_176 . V_177 = V_178 ;
V_7 -> V_179 = false ;
V_7 -> V_180 = false ;
V_15 -> V_20 = V_148 ;
F_84 ( V_11 ) ;
F_85 ( & V_7 -> V_4 ,
V_11 -> V_116 . V_117 ,
V_181 ) ;
V_59 -> V_72 . V_84 = V_181 ;
F_52 ( & V_11 -> V_116 . V_182 ) ;
if ( F_86 () & V_183 )
V_93 = F_87 ( V_7 ,
F_88 ( V_13 , V_150 ) ) ;
else
V_93 = F_89 ( V_7 ,
F_88 ( V_13 , V_150 ) ) ;
if ( V_93 ) {
if ( F_46 ( V_7 , V_93 ) ) {
F_90 ( V_7 ,
V_93 ) ;
} else {
F_59 ( V_93 ) ;
V_93 = F_91 ( - V_120 ) ;
}
} else {
V_93 = F_91 ( - V_184 ) ;
}
V_92 -> V_4 . V_93 = V_93 ;
if ( F_45 ( V_93 ) ) {
V_7 -> V_176 . V_185 = 0 ;
V_7 -> V_176 . V_186 = 200 ;
V_7 -> V_176 . V_187 = 0 ;
V_7 -> V_176 . V_188 = 200 ;
}
F_92 (scan, &connector->probed_modes, head) {
if ( V_146 -> type & V_189 ) {
F_38 ( L_14 ) ;
F_93 ( V_146 ) ;
V_71 = F_47 ( V_11 , V_146 ) ;
if ( V_71 )
goto V_22;
}
}
if ( V_13 -> V_125 . V_190 ) {
F_38 ( L_15 ) ;
F_93 ( V_13 -> V_125 . V_190 ) ;
V_71 = F_47 ( V_11 , V_13 -> V_125 . V_190 ) ;
if ( V_71 ) {
V_71 -> type |= V_189 ;
goto V_22;
}
}
if ( F_14 ( V_11 ) )
goto V_191;
V_9 = ( V_149 & V_50 ) ? 1 : 0 ;
V_44 = F_94 ( V_11 , V_9 ) ;
if ( V_44 && ( V_149 & V_21 ) ) {
V_71 = F_95 ( V_11 , V_44 ) ;
if ( V_71 ) {
F_38 ( L_16 ) ;
F_93 ( V_71 ) ;
V_71 -> type |= V_189 ;
goto V_22;
}
}
if ( ! V_71 )
goto V_191;
V_22:
F_56 ( & V_11 -> V_116 . V_182 ) ;
F_96 ( & V_59 -> V_72 , V_71 , V_147 ) ;
V_15 -> V_51 = F_71 ( V_15 ) ;
F_38 ( L_17 ,
V_15 -> V_51 ? L_18 : L_19 ) ;
V_15 -> V_55 = V_149 & V_54 ;
V_92 -> V_100 . V_112 = F_51 ;
if ( F_97 ( & V_92 -> V_100 ) ) {
F_38 ( L_20 ) ;
V_92 -> V_100 . V_112 = NULL ;
}
F_98 ( V_7 ) ;
F_99 ( V_7 , V_192 ) ;
return;
V_191:
F_56 ( & V_11 -> V_116 . V_182 ) ;
F_38 ( L_21 ) ;
F_61 ( V_7 ) ;
F_100 ( V_3 ) ;
F_59 ( V_15 ) ;
F_59 ( V_92 ) ;
return;
}
