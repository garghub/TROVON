static inline void F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_1 -> V_4 + V_2 ) ;
V_1 -> V_5 [ V_2 >> 2 ] = V_3 ;
}
static inline T_1 F_3 ( struct V_1 * V_1 , T_1 V_2 )
{
return F_4 ( V_1 -> V_4 + V_2 ) ;
}
static inline T_1 F_5 ( struct V_1 * V_1 , T_1 V_6 ,
const struct V_7 * V_8 )
{
return ( F_3 ( V_1 , V_6 + V_8 -> V_2 ) >> V_8 -> V_9 ) & V_8 -> V_10 ;
}
static inline void F_6 ( struct V_1 * V_1 , T_1 V_2 ,
T_1 V_10 , T_1 V_3 )
{
if ( V_10 ) {
T_1 V_11 = V_1 -> V_5 [ V_2 >> 2 ] ;
V_11 = ( V_11 & ~ V_10 ) | V_3 ;
F_2 ( V_11 , V_1 -> V_4 + V_2 ) ;
V_1 -> V_5 [ V_2 >> 2 ] = V_11 ;
}
}
static inline void F_7 ( struct V_1 * V_1 , T_1 V_2 ,
T_1 V_10 , T_1 V_3 )
{
if ( V_10 ) {
T_1 V_11 = V_1 -> V_5 [ V_2 >> 2 ] ;
V_11 = ( V_11 & ~ V_10 ) | V_3 ;
F_8 ( V_11 , V_1 -> V_4 + V_2 ) ;
V_1 -> V_5 [ V_2 >> 2 ] = V_11 ;
}
}
static inline T_1 F_9 ( struct V_1 * V_1 ,
const struct V_7 * V_8 , int type )
{
T_1 V_12 , V_13 = 0 ;
T_1 V_4 = F_5 ( V_1 , 0 , V_8 ) ;
for ( V_12 = 0 ; V_12 < V_1 -> V_14 -> V_15 -> V_16 ; V_12 ++ ) {
if ( ( type & V_1 -> V_14 -> V_15 -> V_17 [ V_12 ] ) && ( V_4 & 1 << V_12 ) )
V_13 |= V_1 -> V_14 -> V_15 -> V_17 [ V_12 ] ;
}
return V_13 ;
}
static inline void F_10 ( struct V_1 * V_1 )
{
F_11 ( V_1 , V_18 , 1 ) ;
}
static bool F_12 ( T_1 V_19 )
{
switch ( V_19 ) {
case V_20 :
case V_21 :
case V_22 :
case V_23 :
return true ;
default:
return false ;
}
}
static enum V_24 F_13 ( T_1 V_19 )
{
switch ( V_19 ) {
case V_25 :
case V_26 :
case V_20 :
case V_21 :
return V_27 ;
case V_28 :
case V_22 :
return V_29 ;
case V_30 :
case V_23 :
return V_31 ;
case V_32 :
return V_33 ;
case V_34 :
return V_35 ;
case V_36 :
return V_37 ;
default:
F_14 ( L_1 , V_19 ) ;
return - V_38 ;
}
}
static bool F_15 ( T_1 V_19 )
{
switch ( V_19 ) {
case V_32 :
case V_34 :
case V_36 :
return true ;
default:
return false ;
}
}
static bool F_16 ( T_1 V_19 )
{
switch ( V_19 ) {
case V_26 :
case V_21 :
return true ;
default:
return false ;
}
}
static T_2 F_17 ( enum V_39 V_40 , T_1 V_41 ,
T_1 V_42 , bool V_43 ,
int V_44 , int * V_45 )
{
T_2 V_46 = 1 << V_47 ;
if ( V_43 ) {
if ( V_40 == V_48 )
V_46 = F_18 ( V_41 , V_42 ) ;
else if ( V_40 == V_49 )
V_46 = F_19 ( V_41 , V_42 ) ;
} else {
if ( V_40 == V_48 ) {
if ( V_44 == V_50 )
V_46 = F_20 ( V_41 , V_42 ) ;
else
V_46 = F_18 ( V_41 , V_42 ) ;
} else if ( V_40 == V_49 ) {
if ( V_45 ) {
* V_45 = F_21 ( V_41 , V_42 ) ;
V_46 = F_22 ( V_41 , V_42 ,
* V_45 ) ;
} else {
V_46 = F_19 ( V_41 , V_42 ) ;
}
}
}
return V_46 ;
}
static void F_23 ( struct V_1 * V_1 , const struct V_51 * V_52 ,
T_1 V_53 , T_1 V_54 , T_1 V_55 ,
T_1 V_56 , T_1 V_57 )
{
T_2 V_58 , V_59 ;
T_2 V_60 = V_61 ;
T_2 V_62 = V_61 ;
int V_63 = F_24 ( V_57 ) ;
int V_64 = F_25 ( V_57 ) ;
bool V_65 = F_15 ( V_57 ) ;
T_2 V_66 = V_53 / V_63 ;
T_2 V_67 = V_54 / V_64 ;
T_2 V_44 ;
T_2 V_68 ;
T_1 V_46 ;
int V_45 ;
if ( V_55 > 3840 ) {
F_14 ( L_2 ) ;
return;
}
if ( ! V_52 -> V_69 -> V_70 -> V_71 ) {
F_26 ( V_1 , V_52 , V_72 ,
F_27 ( V_53 , V_55 ) ) ;
F_26 ( V_1 , V_52 , V_73 ,
F_27 ( V_54 , V_56 ) ) ;
if ( V_65 ) {
F_26 ( V_1 , V_52 , V_74 ,
F_27 ( V_53 , V_55 ) ) ;
F_26 ( V_1 , V_52 , V_75 ,
F_27 ( V_54 , V_56 ) ) ;
}
return;
}
V_58 = F_28 ( V_53 , V_55 ) ;
V_59 = F_28 ( V_54 , V_56 ) ;
if ( V_65 ) {
V_60 = F_28 ( V_66 , V_55 ) ;
V_62 = F_28 ( V_67 , V_56 ) ;
if ( V_60 == V_49 )
V_68 = F_29 ( V_55 , true ) ;
else
V_68 = F_29 ( V_66 , true ) ;
} else {
if ( V_58 == V_49 )
V_68 = F_29 ( V_55 , false ) ;
else
V_68 = F_29 ( V_53 , false ) ;
}
F_30 ( V_1 , V_52 , V_68 , V_68 ) ;
if ( V_68 == V_76 ) {
if ( V_59 != V_61 ) {
F_14 ( L_3 ) ;
return;
}
if ( V_62 != V_61 ) {
F_14 ( L_4 ) ;
return;
}
V_44 = V_50 ;
} else if ( V_68 == V_77 ) {
V_44 = V_50 ;
} else {
V_44 = V_78 ;
}
V_46 = F_17 ( V_58 , V_53 , V_55 ,
true , 0 , NULL ) ;
F_26 ( V_1 , V_52 , V_72 , V_46 ) ;
V_46 = F_17 ( V_59 , V_54 , V_56 ,
false , V_44 , & V_45 ) ;
F_26 ( V_1 , V_52 , V_73 , V_46 ) ;
F_30 ( V_1 , V_52 , V_79 , V_45 == 4 ) ;
F_30 ( V_1 , V_52 , V_80 , V_45 == 2 ) ;
F_30 ( V_1 , V_52 , V_58 , V_58 ) ;
F_30 ( V_1 , V_52 , V_59 , V_59 ) ;
F_30 ( V_1 , V_52 , V_81 , V_82 ) ;
F_30 ( V_1 , V_52 , V_83 , V_82 ) ;
F_30 ( V_1 , V_52 , V_84 , V_44 ) ;
if ( V_65 ) {
V_46 = F_17 ( V_60 , V_66 ,
V_55 , true , 0 , NULL ) ;
F_26 ( V_1 , V_52 , V_74 , V_46 ) ;
V_46 = F_17 ( V_62 , V_67 ,
V_56 , false , V_44 , & V_45 ) ;
F_26 ( V_1 , V_52 , V_75 , V_46 ) ;
F_30 ( V_1 , V_52 , V_85 , V_45 == 4 ) ;
F_30 ( V_1 , V_52 , V_86 , V_45 == 2 ) ;
F_30 ( V_1 , V_52 , V_60 , V_60 ) ;
F_30 ( V_1 , V_52 , V_62 , V_62 ) ;
F_30 ( V_1 , V_52 , V_87 , V_82 ) ;
F_30 ( V_1 , V_52 , V_88 , V_82 ) ;
F_30 ( V_1 , V_52 , V_89 , V_44 ) ;
}
}
static void F_31 ( struct V_1 * V_1 )
{
unsigned long V_90 ;
if ( F_32 ( ! V_1 -> V_91 ) )
return;
F_33 ( & V_1 -> V_92 , V_90 ) ;
F_34 ( V_1 , V_93 , V_94 , 1 ) ;
F_35 ( & V_1 -> V_92 , V_90 ) ;
}
static void F_36 ( struct V_1 * V_1 )
{
unsigned long V_90 ;
if ( F_32 ( ! V_1 -> V_91 ) )
return;
F_33 ( & V_1 -> V_92 , V_90 ) ;
F_34 ( V_1 , V_93 , V_94 , 0 ) ;
F_35 ( & V_1 -> V_92 , V_90 ) ;
}
static void F_37 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
int V_13 ;
if ( V_1 -> V_91 )
return;
V_13 = F_39 ( V_1 -> V_97 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_5 , V_13 ) ;
return;
}
V_13 = F_41 ( V_1 -> V_98 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_6 , V_13 ) ;
return;
}
V_13 = F_41 ( V_1 -> V_99 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_7 , V_13 ) ;
goto V_100;
}
V_13 = F_41 ( V_1 -> V_101 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_8 , V_13 ) ;
goto V_102;
}
V_13 = F_42 ( V_1 -> V_103 , V_1 -> V_97 ) ;
if ( V_13 ) {
F_40 ( V_1 -> V_97 , L_9 , V_13 ) ;
goto V_104;
}
memcpy ( V_1 -> V_4 , V_1 -> V_5 , V_1 -> V_105 ) ;
V_1 -> V_91 = true ;
F_43 ( & V_1 -> V_106 ) ;
F_11 ( V_1 , V_107 , 0 ) ;
F_44 ( & V_1 -> V_106 ) ;
F_45 ( V_1 -> V_108 ) ;
F_46 ( V_96 ) ;
return;
V_104:
F_47 ( V_1 -> V_101 ) ;
V_102:
F_47 ( V_1 -> V_99 ) ;
V_100:
F_47 ( V_1 -> V_98 ) ;
}
static void F_48 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
if ( ! V_1 -> V_91 )
return;
F_49 ( V_96 ) ;
F_50 ( & V_1 -> V_109 ) ;
F_31 ( V_1 ) ;
F_43 ( & V_1 -> V_106 ) ;
F_11 ( V_1 , V_107 , 1 ) ;
F_44 ( & V_1 -> V_106 ) ;
F_51 ( & V_1 -> V_109 ) ;
F_36 ( V_1 ) ;
F_52 ( V_1 -> V_108 ) ;
V_1 -> V_91 = false ;
F_53 ( V_1 -> V_103 , V_1 -> V_97 ) ;
F_47 ( V_1 -> V_99 ) ;
F_47 ( V_1 -> V_101 ) ;
F_47 ( V_1 -> V_98 ) ;
F_54 ( V_1 -> V_97 ) ;
}
static void F_55 ( struct V_110 * V_111 )
{
F_56 ( V_111 ) ;
}
static int F_57 ( struct V_110 * V_111 ,
struct V_112 * V_113 )
{
struct V_95 * V_96 = V_113 -> V_96 ;
struct V_114 * V_115 = V_113 -> V_115 ;
struct V_116 * V_116 = F_58 ( V_111 ) ;
struct V_117 * V_117 = F_59 ( V_113 ) ;
const struct V_51 * V_52 = V_116 -> V_14 ;
bool V_118 ;
int V_13 ;
struct V_119 * V_120 = & V_117 -> V_120 ;
struct V_119 * V_41 = & V_117 -> V_41 ;
struct V_119 V_121 ;
int V_122 = V_52 -> V_69 -> V_70 ? F_60 ( 1 , 8 ) :
V_123 ;
int V_124 = V_52 -> V_69 -> V_70 ? F_60 ( 8 , 1 ) :
V_123 ;
V_96 = V_96 ? V_96 : V_111 -> V_113 -> V_96 ;
if ( ! V_96 || ! V_115 )
goto V_125;
V_41 -> V_126 = V_113 -> V_127 ;
V_41 -> y1 = V_113 -> V_128 ;
V_41 -> V_129 = V_113 -> V_127 + V_113 -> V_53 ;
V_41 -> V_130 = V_113 -> V_128 + V_113 -> V_54 ;
V_120 -> V_126 = V_113 -> V_131 ;
V_120 -> y1 = V_113 -> V_132 ;
V_120 -> V_129 = V_113 -> V_131 + V_113 -> V_133 ;
V_120 -> V_130 = V_113 -> V_132 + V_113 -> V_134 ;
V_121 . V_126 = 0 ;
V_121 . y1 = 0 ;
V_121 . V_129 = V_96 -> V_40 . V_135 ;
V_121 . V_130 = V_96 -> V_40 . V_136 ;
V_13 = F_61 ( V_111 , V_96 , V_113 -> V_115 ,
V_41 , V_120 , & V_121 ,
V_122 ,
V_124 ,
true , true , & V_118 ) ;
if ( V_13 )
return V_13 ;
if ( ! V_118 )
goto V_125;
V_117 -> V_19 = F_13 ( V_115 -> V_57 ) ;
if ( V_117 -> V_19 < 0 )
return V_117 -> V_19 ;
if ( F_15 ( V_115 -> V_57 ) && ( ( V_41 -> V_126 >> 16 ) % 2 ) )
return - V_38 ;
V_117 -> V_93 = true ;
return 0 ;
V_125:
V_117 -> V_93 = false ;
return 0 ;
}
static void F_62 ( struct V_110 * V_111 ,
struct V_112 * V_137 )
{
struct V_117 * V_117 = F_59 ( V_137 ) ;
struct V_116 * V_116 = F_58 ( V_111 ) ;
const struct V_51 * V_52 = V_116 -> V_14 ;
struct V_1 * V_1 = F_38 ( V_137 -> V_96 ) ;
if ( ! V_137 -> V_96 )
return;
F_43 ( & V_1 -> V_106 ) ;
F_63 ( V_1 , V_52 , V_93 , 0 ) ;
F_44 ( & V_1 -> V_106 ) ;
V_117 -> V_93 = false ;
}
static void F_64 ( struct V_110 * V_111 ,
struct V_112 * V_137 )
{
struct V_112 * V_113 = V_111 -> V_113 ;
struct V_95 * V_96 = V_113 -> V_96 ;
struct V_116 * V_116 = F_58 ( V_111 ) ;
struct V_117 * V_117 = F_59 ( V_113 ) ;
const struct V_51 * V_52 = V_116 -> V_14 ;
struct V_1 * V_1 = F_38 ( V_113 -> V_96 ) ;
struct V_114 * V_115 = V_113 -> V_115 ;
unsigned int V_138 , V_139 ;
unsigned int V_140 , V_141 ;
T_1 V_142 , V_143 , V_144 ;
struct V_119 * V_41 = & V_117 -> V_41 ;
struct V_119 * V_120 = & V_117 -> V_120 ;
struct V_145 * V_146 , * V_147 ;
struct V_148 * V_149 , * V_150 ;
unsigned long V_2 ;
T_3 V_151 ;
T_1 V_46 ;
bool V_152 ;
if ( ! V_96 )
return;
if ( F_32 ( ! V_1 -> V_91 ) )
return;
if ( ! V_117 -> V_93 ) {
F_62 ( V_111 , V_137 ) ;
return;
}
V_146 = F_65 ( V_115 , 0 ) ;
V_149 = F_66 ( V_146 ) ;
V_138 = F_67 ( V_41 ) >> 16 ;
V_139 = F_68 ( V_41 ) >> 16 ;
V_142 = ( V_139 - 1 ) << 16 | ( ( V_138 - 1 ) & 0xffff ) ;
V_143 = ( F_68 ( V_120 ) - 1 ) << 16 ;
V_143 |= ( F_67 ( V_120 ) - 1 ) & 0xffff ;
V_140 = V_120 -> V_126 + V_96 -> V_40 . V_153 - V_96 -> V_40 . V_154 ;
V_141 = V_120 -> y1 + V_96 -> V_40 . V_155 - V_96 -> V_40 . V_156 ;
V_144 = V_141 << 16 | ( V_140 & 0xffff ) ;
V_2 = ( V_41 -> V_126 >> 16 ) * F_69 ( V_115 -> V_57 , 0 ) ;
V_2 += ( V_41 -> y1 >> 16 ) * V_115 -> V_157 [ 0 ] ;
V_117 -> V_158 = V_149 -> V_151 + V_2 + V_115 -> V_159 [ 0 ] ;
F_43 ( & V_1 -> V_106 ) ;
F_63 ( V_1 , V_52 , V_19 , V_117 -> V_19 ) ;
F_63 ( V_1 , V_52 , V_160 , V_115 -> V_157 [ 0 ] >> 2 ) ;
F_63 ( V_1 , V_52 , V_158 , V_117 -> V_158 ) ;
if ( F_15 ( V_115 -> V_57 ) ) {
int V_63 = F_24 ( V_115 -> V_57 ) ;
int V_64 = F_25 ( V_115 -> V_57 ) ;
int V_161 = F_69 ( V_115 -> V_57 , 1 ) ;
V_147 = F_65 ( V_115 , 1 ) ;
V_150 = F_66 ( V_147 ) ;
V_2 = ( V_41 -> V_126 >> 16 ) * V_161 / V_63 ;
V_2 += ( V_41 -> y1 >> 16 ) * V_115 -> V_157 [ 1 ] / V_64 ;
V_151 = V_150 -> V_151 + V_2 + V_115 -> V_159 [ 1 ] ;
F_63 ( V_1 , V_52 , V_162 , V_115 -> V_157 [ 1 ] >> 2 ) ;
F_63 ( V_1 , V_52 , V_163 , V_151 ) ;
}
if ( V_52 -> V_69 -> V_70 )
F_23 ( V_1 , V_52 , V_138 , V_139 ,
F_67 ( V_120 ) , F_68 ( V_120 ) ,
V_115 -> V_57 ) ;
F_63 ( V_1 , V_52 , V_142 , V_142 ) ;
F_63 ( V_1 , V_52 , V_143 , V_143 ) ;
F_63 ( V_1 , V_52 , V_144 , V_144 ) ;
V_152 = F_12 ( V_115 -> V_57 ) ;
F_63 ( V_1 , V_52 , V_152 , V_152 ) ;
if ( F_16 ( V_115 -> V_57 ) ) {
F_63 ( V_1 , V_52 , V_164 ,
F_70 ( V_165 ) ) ;
V_46 = F_71 ( 1 ) | F_72 ( V_166 ) |
F_73 ( V_167 ) |
F_74 ( V_168 ) |
F_75 ( V_169 ) |
F_76 ( V_170 ) ;
F_63 ( V_1 , V_52 , V_171 , V_46 ) ;
} else {
F_63 ( V_1 , V_52 , V_171 , F_71 ( 0 ) ) ;
}
F_63 ( V_1 , V_52 , V_93 , 1 ) ;
F_44 ( & V_1 -> V_106 ) ;
}
void F_77 ( struct V_110 * V_111 )
{
struct V_117 * V_117 =
F_59 ( V_111 -> V_113 ) ;
if ( V_111 -> V_113 && V_111 -> V_113 -> V_115 )
F_78 ( V_111 -> V_113 -> V_115 ) ;
F_79 ( V_117 ) ;
V_117 = F_80 ( sizeof( * V_117 ) , V_172 ) ;
if ( ! V_117 )
return;
V_111 -> V_113 = & V_117 -> V_6 ;
V_111 -> V_113 -> V_111 = V_111 ;
}
struct V_112 *
F_81 ( struct V_110 * V_111 )
{
struct V_117 * V_173 ;
struct V_117 * V_117 ;
if ( F_32 ( ! V_111 -> V_113 ) )
return NULL ;
V_173 = F_59 ( V_111 -> V_113 ) ;
V_117 = F_82 ( V_173 ,
sizeof( * V_117 ) , V_172 ) ;
if ( ! V_117 )
return NULL ;
F_83 ( V_111 ,
& V_117 -> V_6 ) ;
return & V_117 -> V_6 ;
}
static void F_84 ( struct V_110 * V_111 ,
struct V_112 * V_113 )
{
struct V_117 * V_174 = F_59 ( V_113 ) ;
F_85 ( V_111 , V_113 ) ;
F_79 ( V_174 ) ;
}
int F_86 ( struct V_95 * V_96 ,
int V_175 ,
int V_176 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
if ( F_32 ( ! V_1 -> V_91 ) )
return - V_38 ;
switch ( V_175 ) {
case V_177 :
F_11 ( V_1 , V_178 , 1 ) ;
break;
case V_179 :
F_11 ( V_1 , V_180 , 1 ) ;
break;
case V_181 :
F_11 ( V_1 , V_182 , 1 ) ;
break;
case V_183 :
F_11 ( V_1 , V_184 , 1 ) ;
break;
default:
F_14 ( L_10 , V_175 ) ;
return - V_38 ;
} ;
F_11 ( V_1 , V_176 , V_176 ) ;
return 0 ;
}
static int F_87 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
unsigned long V_90 ;
if ( F_32 ( ! V_1 -> V_91 ) )
return - V_185 ;
F_33 ( & V_1 -> V_92 , V_90 ) ;
F_34 ( V_1 , V_93 , V_186 , 1 ) ;
F_35 ( & V_1 -> V_92 , V_90 ) ;
return 0 ;
}
static void F_88 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
unsigned long V_90 ;
if ( F_32 ( ! V_1 -> V_91 ) )
return;
F_33 ( & V_1 -> V_92 , V_90 ) ;
F_34 ( V_1 , V_93 , V_186 , 0 ) ;
F_35 ( & V_1 -> V_92 , V_90 ) ;
}
static void F_89 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
F_50 ( & V_1 -> V_187 ) ;
F_32 ( ! F_90 ( & V_1 -> V_187 , 100 ) ) ;
}
static bool F_91 ( struct V_95 * V_96 ,
const struct V_188 * V_40 ,
struct V_188 * V_189 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
if ( V_189 -> V_153 == 0 || V_189 -> V_155 == 0 )
return false ;
V_189 -> clock =
F_92 ( V_1 -> V_99 , V_40 -> clock * 1000 ) / 1000 ;
return true ;
}
static void F_93 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
struct V_188 * V_189 = & V_96 -> V_113 -> V_189 ;
T_4 V_190 = V_189 -> V_191 - V_189 -> V_154 ;
T_4 V_135 = V_189 -> V_135 ;
T_4 V_153 = V_189 -> V_153 ;
T_4 V_192 = V_189 -> V_153 - V_189 -> V_154 ;
T_4 V_193 = V_192 + V_135 ;
T_4 V_136 = V_189 -> V_136 ;
T_4 V_155 = V_189 -> V_155 ;
T_4 V_194 = V_189 -> V_195 - V_189 -> V_156 ;
T_4 V_196 = V_189 -> V_155 - V_189 -> V_156 ;
T_4 V_197 = V_196 + V_136 ;
T_1 V_46 ;
F_37 ( V_96 ) ;
if ( F_94 ( V_1 -> V_99 ) ) {
F_50 ( & V_1 -> V_109 ) ;
F_31 ( V_1 ) ;
F_43 ( & V_1 -> V_106 ) ;
F_11 ( V_1 , V_107 , 1 ) ;
F_44 ( & V_1 -> V_106 ) ;
F_51 ( & V_1 -> V_109 ) ;
F_36 ( V_1 ) ;
}
V_46 = 0x8 ;
V_46 |= ( V_189 -> V_90 & V_198 ) ? 0 : 1 ;
V_46 |= ( V_189 -> V_90 & V_199 ) ? 0 : ( 1 << 1 ) ;
F_11 ( V_1 , V_200 , V_46 ) ;
F_11 ( V_1 , V_201 , ( V_153 << 16 ) | V_190 ) ;
V_46 = V_192 << 16 ;
V_46 |= V_193 ;
F_11 ( V_1 , V_202 , V_46 ) ;
F_11 ( V_1 , V_203 , V_46 ) ;
F_11 ( V_1 , V_204 , ( V_155 << 16 ) | V_194 ) ;
V_46 = V_196 << 16 ;
V_46 |= V_197 ;
F_11 ( V_1 , V_205 , V_46 ) ;
F_11 ( V_1 , V_206 , V_46 ) ;
F_95 ( V_1 -> V_99 , V_189 -> clock * 1000 ) ;
F_11 ( V_1 , V_107 , 0 ) ;
}
static void F_96 ( struct V_95 * V_96 ,
struct V_207 * V_208 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
if ( F_32 ( ! V_1 -> V_91 ) )
return;
F_43 ( & V_1 -> V_106 ) ;
F_10 ( V_1 ) ;
F_44 ( & V_1 -> V_106 ) ;
}
static void F_97 ( struct V_95 * V_96 ,
struct V_207 * V_208 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
if ( V_96 -> V_113 -> V_209 ) {
F_32 ( F_98 ( V_96 ) != 0 ) ;
V_1 -> V_209 = V_96 -> V_113 -> V_209 ;
V_96 -> V_113 -> V_209 = NULL ;
}
}
static void F_99 ( struct V_95 * V_96 )
{
F_100 ( V_96 ) ;
}
static bool F_101 ( struct V_116 * V_116 )
{
struct V_110 * V_111 = & V_116 -> V_6 ;
struct V_117 * V_113 = F_59 ( V_111 -> V_113 ) ;
T_3 V_158 ;
if ( ! V_113 -> V_93 )
return F_102 ( V_116 -> V_1 , V_116 -> V_14 , V_93 ) == 0 ;
V_158 = F_103 ( V_116 -> V_1 , V_116 -> V_14 ) ;
return V_158 == V_113 -> V_158 ;
}
static void F_104 ( struct V_1 * V_1 )
{
struct V_210 * V_211 = V_1 -> V_103 ;
struct V_95 * V_96 = & V_1 -> V_96 ;
unsigned long V_90 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_1 -> V_14 -> V_212 ; V_12 ++ ) {
if ( ! F_101 ( & V_1 -> V_52 [ V_12 ] ) )
return;
}
if ( V_1 -> V_209 ) {
F_33 ( & V_211 -> V_213 , V_90 ) ;
F_105 ( V_96 , V_1 -> V_209 ) ;
F_106 ( V_96 ) ;
V_1 -> V_209 = NULL ;
F_35 ( & V_211 -> V_213 , V_90 ) ;
}
if ( ! F_107 ( & V_1 -> V_187 ) )
F_108 ( & V_1 -> V_187 ) ;
}
static T_5 F_109 ( int V_108 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
struct V_95 * V_96 = & V_1 -> V_96 ;
T_1 V_214 ;
unsigned long V_90 ;
int V_13 = V_215 ;
F_33 ( & V_1 -> V_92 , V_90 ) ;
V_214 = F_110 ( V_1 , V_216 , V_217 ) ;
if ( V_214 )
F_34 ( V_1 , V_218 , V_214 , 1 ) ;
F_35 ( & V_1 -> V_92 , V_90 ) ;
if ( ! V_214 )
return V_215 ;
if ( V_214 & V_94 ) {
F_108 ( & V_1 -> V_109 ) ;
V_214 &= ~ V_94 ;
V_13 = V_219 ;
}
if ( V_214 & V_186 ) {
F_111 ( V_96 ) ;
F_104 ( V_1 ) ;
V_214 &= ~ V_186 ;
V_13 = V_219 ;
}
if ( V_214 )
F_14 ( L_11 , V_214 ) ;
return V_13 ;
}
static int F_112 ( struct V_1 * V_1 )
{
const struct V_220 * V_220 = V_1 -> V_14 ;
struct V_221 * V_97 = V_1 -> V_97 ;
struct V_210 * V_103 = V_1 -> V_103 ;
struct V_110 * V_222 = NULL , * V_223 = NULL , * V_111 ;
struct V_95 * V_96 = & V_1 -> V_96 ;
struct V_224 * V_225 ;
int V_13 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_220 -> V_212 ; V_12 ++ ) {
struct V_116 * V_116 = & V_1 -> V_52 [ V_12 ] ;
const struct V_51 * V_226 = V_116 -> V_14 ;
if ( V_226 -> type != V_227 &&
V_226 -> type != V_228 )
continue;
V_13 = F_113 ( V_1 -> V_103 , & V_116 -> V_6 ,
0 , & V_229 ,
V_226 -> V_69 -> V_230 ,
V_226 -> V_69 -> V_231 ,
V_226 -> type , NULL ) ;
if ( V_13 ) {
F_14 ( L_12 ) ;
goto V_232;
}
V_111 = & V_116 -> V_6 ;
F_114 ( V_111 , & V_233 ) ;
if ( V_111 -> type == V_227 )
V_222 = V_111 ;
else if ( V_111 -> type == V_228 )
V_223 = V_111 ;
}
V_13 = F_115 ( V_103 , V_96 , V_222 , V_223 ,
& V_234 , NULL ) ;
if ( V_13 )
return V_13 ;
F_116 ( V_96 , & V_235 ) ;
for ( V_12 = 0 ; V_12 < V_220 -> V_212 ; V_12 ++ ) {
struct V_116 * V_116 = & V_1 -> V_52 [ V_12 ] ;
const struct V_51 * V_226 = V_116 -> V_14 ;
unsigned long V_236 = 1 << F_117 ( V_96 ) ;
if ( V_226 -> type != V_237 )
continue;
V_13 = F_113 ( V_1 -> V_103 , & V_116 -> V_6 ,
V_236 ,
& V_229 ,
V_226 -> V_69 -> V_230 ,
V_226 -> V_69 -> V_231 ,
V_226 -> type , NULL ) ;
if ( V_13 ) {
F_14 ( L_13 ) ;
goto V_238;
}
F_114 ( & V_116 -> V_6 , & V_233 ) ;
}
V_225 = F_118 ( V_97 -> V_239 , L_14 ) ;
if ( ! V_225 ) {
F_14 ( L_15 ,
V_97 -> V_239 -> V_240 ) ;
goto V_238;
}
F_119 ( & V_1 -> V_109 ) ;
F_119 ( & V_1 -> V_187 ) ;
V_96 -> V_225 = V_225 ;
F_120 ( V_96 , & V_241 ) ;
return 0 ;
V_238:
F_100 ( V_96 ) ;
V_232:
F_121 (plane, &drm_dev->mode_config.plane_list, head)
F_56 ( V_111 ) ;
return V_13 ;
}
static void F_122 ( struct V_1 * V_1 )
{
struct V_95 * V_96 = & V_1 -> V_96 ;
F_123 ( V_96 ) ;
F_124 ( V_96 -> V_225 ) ;
F_100 ( V_96 ) ;
}
static int F_125 ( struct V_1 * V_1 )
{
const struct V_220 * V_220 = V_1 -> V_14 ;
const struct V_242 * V_243 = V_220 -> V_243 ;
struct V_244 * V_245 ;
int V_12 , V_13 ;
V_1 -> V_98 = F_126 ( V_1 -> V_97 , L_16 ) ;
if ( F_127 ( V_1 -> V_98 ) ) {
F_40 ( V_1 -> V_97 , L_17 ) ;
return F_128 ( V_1 -> V_98 ) ;
}
V_1 -> V_101 = F_126 ( V_1 -> V_97 , L_18 ) ;
if ( F_127 ( V_1 -> V_101 ) ) {
F_40 ( V_1 -> V_97 , L_19 ) ;
return F_128 ( V_1 -> V_101 ) ;
}
V_1 -> V_99 = F_126 ( V_1 -> V_97 , L_20 ) ;
if ( F_127 ( V_1 -> V_99 ) ) {
F_40 ( V_1 -> V_97 , L_21 ) ;
return F_128 ( V_1 -> V_99 ) ;
}
V_13 = F_129 ( V_1 -> V_99 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_22 ) ;
return V_13 ;
}
V_13 = F_130 ( V_1 -> V_98 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_23 ) ;
goto V_246;
}
V_13 = F_130 ( V_1 -> V_101 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_24 ) ;
goto V_100;
}
V_245 = F_131 ( V_1 -> V_97 , L_25 ) ;
if ( F_127 ( V_245 ) ) {
F_40 ( V_1 -> V_97 , L_26 ) ;
V_13 = F_128 ( V_245 ) ;
goto V_104;
}
F_132 ( V_245 ) ;
F_133 ( 10 , 20 ) ;
F_134 ( V_245 ) ;
memcpy ( V_1 -> V_5 , V_1 -> V_4 , V_1 -> V_105 ) ;
for ( V_12 = 0 ; V_12 < V_220 -> V_247 ; V_12 ++ )
F_1 ( V_1 , V_243 [ V_12 ] . V_2 , V_243 [ V_12 ] . V_248 ) ;
for ( V_12 = 0 ; V_12 < V_220 -> V_212 ; V_12 ++ ) {
const struct V_51 * V_52 = & V_220 -> V_52 [ V_12 ] ;
F_63 ( V_1 , V_52 , V_93 , 0 ) ;
}
F_10 ( V_1 ) ;
V_1 -> V_249 = F_131 ( V_1 -> V_97 , L_27 ) ;
if ( F_127 ( V_1 -> V_249 ) ) {
F_40 ( V_1 -> V_97 , L_28 ) ;
V_13 = F_128 ( V_1 -> V_249 ) ;
goto V_104;
}
F_132 ( V_1 -> V_249 ) ;
F_133 ( 10 , 20 ) ;
F_134 ( V_1 -> V_249 ) ;
F_47 ( V_1 -> V_98 ) ;
F_47 ( V_1 -> V_101 ) ;
V_1 -> V_91 = false ;
return 0 ;
V_104:
F_135 ( V_1 -> V_101 ) ;
V_100:
F_135 ( V_1 -> V_98 ) ;
V_246:
F_136 ( V_1 -> V_99 ) ;
return V_13 ;
}
static void F_137 ( struct V_1 * V_1 )
{
const struct V_220 * V_220 = V_1 -> V_14 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_220 -> V_212 ; V_12 ++ ) {
struct V_116 * V_116 = & V_1 -> V_52 [ V_12 ] ;
const struct V_51 * V_226 = & V_220 -> V_52 [ V_12 ] ;
V_116 -> V_14 = V_226 ;
V_116 -> V_1 = V_1 ;
}
}
static int F_138 ( struct V_221 * V_97 , struct V_221 * V_250 , void * V_14 )
{
struct V_251 * V_252 = F_139 ( V_97 ) ;
const struct V_220 * V_220 ;
struct V_210 * V_103 = V_14 ;
struct V_1 * V_1 ;
struct V_253 * V_254 ;
T_6 V_255 ;
int V_13 , V_108 ;
V_220 = F_140 ( V_97 ) ;
if ( ! V_220 )
return - V_256 ;
V_255 = sizeof( * V_1 ) + sizeof( * V_1 -> V_52 ) * V_220 -> V_212 ;
V_1 = F_141 ( V_97 , V_255 , V_172 ) ;
if ( ! V_1 )
return - V_257 ;
V_1 -> V_97 = V_97 ;
V_1 -> V_14 = V_220 ;
V_1 -> V_103 = V_103 ;
F_142 ( V_97 , V_1 ) ;
F_137 ( V_1 ) ;
V_254 = F_143 ( V_252 , V_258 , 0 ) ;
V_1 -> V_105 = F_144 ( V_254 ) ;
V_1 -> V_4 = F_145 ( V_97 , V_254 ) ;
if ( F_127 ( V_1 -> V_4 ) )
return F_128 ( V_1 -> V_4 ) ;
V_1 -> V_5 = F_141 ( V_97 , V_1 -> V_105 , V_172 ) ;
if ( ! V_1 -> V_5 )
return - V_257 ;
V_13 = F_125 ( V_1 ) ;
if ( V_13 < 0 ) {
F_40 ( & V_252 -> V_97 , L_29 , V_13 ) ;
return V_13 ;
}
V_108 = F_146 ( V_252 , 0 ) ;
if ( V_108 < 0 ) {
F_40 ( V_97 , L_30 ) ;
return V_108 ;
}
V_1 -> V_108 = ( unsigned int ) V_108 ;
F_147 ( & V_1 -> V_106 ) ;
F_147 ( & V_1 -> V_92 ) ;
F_148 ( & V_1 -> V_259 ) ;
V_13 = F_149 ( V_97 , V_1 -> V_108 , F_109 ,
V_260 , F_150 ( V_97 ) , V_1 ) ;
if ( V_13 )
return V_13 ;
F_52 ( V_1 -> V_108 ) ;
V_13 = F_112 ( V_1 ) ;
if ( V_13 )
return V_13 ;
F_151 ( & V_252 -> V_97 ) ;
return 0 ;
}
static void F_152 ( struct V_221 * V_97 , struct V_221 * V_250 , void * V_14 )
{
struct V_1 * V_1 = F_153 ( V_97 ) ;
F_154 ( V_97 ) ;
F_122 ( V_1 ) ;
}
