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
int V_12 ;
if ( ! V_1 -> V_91 )
return;
for ( V_12 = 0 ; V_12 < V_1 -> V_14 -> V_109 ; V_12 ++ ) {
struct V_110 * V_110 = & V_1 -> V_52 [ V_12 ] ;
const struct V_51 * V_52 = V_110 -> V_14 ;
F_43 ( & V_1 -> V_106 ) ;
F_49 ( V_1 , V_52 , V_93 , 0 ) ;
F_44 ( & V_1 -> V_106 ) ;
}
F_50 ( V_96 ) ;
F_51 ( & V_1 -> V_111 ) ;
F_31 ( V_1 ) ;
F_43 ( & V_1 -> V_106 ) ;
F_11 ( V_1 , V_107 , 1 ) ;
F_44 ( & V_1 -> V_106 ) ;
F_52 ( & V_1 -> V_111 ) ;
F_36 ( V_1 ) ;
F_53 ( V_1 -> V_108 ) ;
V_1 -> V_91 = false ;
F_54 ( V_1 -> V_103 , V_1 -> V_97 ) ;
F_47 ( V_1 -> V_99 ) ;
F_47 ( V_1 -> V_101 ) ;
F_47 ( V_1 -> V_98 ) ;
F_55 ( V_1 -> V_97 ) ;
}
static void F_56 ( struct V_112 * V_113 )
{
F_57 ( V_113 ) ;
}
static int F_58 ( struct V_112 * V_113 ,
struct V_114 * V_115 )
{
struct V_95 * V_96 = V_115 -> V_96 ;
struct V_116 * V_117 ;
struct V_118 * V_119 = V_115 -> V_119 ;
struct V_110 * V_110 = F_59 ( V_113 ) ;
struct V_120 * V_120 = F_60 ( V_115 ) ;
const struct V_51 * V_52 = V_110 -> V_14 ;
bool V_121 ;
int V_13 ;
struct V_122 * V_123 = & V_120 -> V_123 ;
struct V_122 * V_41 = & V_120 -> V_41 ;
struct V_122 V_124 ;
int V_125 = V_52 -> V_69 -> V_70 ? F_61 ( 1 , 8 ) :
V_126 ;
int V_127 = V_52 -> V_69 -> V_70 ? F_61 ( 8 , 1 ) :
V_126 ;
if ( ! V_96 || ! V_119 )
goto V_128;
V_117 = F_62 ( V_115 -> V_115 , V_96 ) ;
if ( F_32 ( ! V_117 ) )
return - V_38 ;
V_41 -> V_129 = V_115 -> V_130 ;
V_41 -> y1 = V_115 -> V_131 ;
V_41 -> V_132 = V_115 -> V_130 + V_115 -> V_53 ;
V_41 -> V_133 = V_115 -> V_131 + V_115 -> V_54 ;
V_123 -> V_129 = V_115 -> V_134 ;
V_123 -> y1 = V_115 -> V_135 ;
V_123 -> V_132 = V_115 -> V_134 + V_115 -> V_136 ;
V_123 -> V_133 = V_115 -> V_135 + V_115 -> V_137 ;
V_124 . V_129 = 0 ;
V_124 . y1 = 0 ;
V_124 . V_132 = V_117 -> V_138 . V_139 ;
V_124 . V_133 = V_117 -> V_138 . V_140 ;
V_13 = F_63 ( V_113 , V_96 , V_115 -> V_119 ,
V_41 , V_123 , & V_124 ,
V_125 ,
V_127 ,
true , true , & V_121 ) ;
if ( V_13 )
return V_13 ;
if ( ! V_121 )
goto V_128;
V_120 -> V_19 = F_13 ( V_119 -> V_57 ) ;
if ( V_120 -> V_19 < 0 )
return V_120 -> V_19 ;
if ( F_15 ( V_119 -> V_57 ) && ( ( V_41 -> V_129 >> 16 ) % 2 ) )
return - V_38 ;
V_120 -> V_93 = true ;
return 0 ;
V_128:
V_120 -> V_93 = false ;
return 0 ;
}
static void F_64 ( struct V_112 * V_113 ,
struct V_114 * V_141 )
{
struct V_120 * V_120 = F_60 ( V_141 ) ;
struct V_110 * V_110 = F_59 ( V_113 ) ;
const struct V_51 * V_52 = V_110 -> V_14 ;
struct V_1 * V_1 = F_38 ( V_141 -> V_96 ) ;
if ( ! V_141 -> V_96 )
return;
F_43 ( & V_1 -> V_106 ) ;
F_49 ( V_1 , V_52 , V_93 , 0 ) ;
F_44 ( & V_1 -> V_106 ) ;
V_120 -> V_93 = false ;
}
static void F_65 ( struct V_112 * V_113 ,
struct V_114 * V_141 )
{
struct V_114 * V_115 = V_113 -> V_115 ;
struct V_95 * V_96 = V_115 -> V_96 ;
struct V_110 * V_110 = F_59 ( V_113 ) ;
struct V_120 * V_120 = F_60 ( V_115 ) ;
const struct V_51 * V_52 = V_110 -> V_14 ;
struct V_1 * V_1 = F_38 ( V_115 -> V_96 ) ;
struct V_118 * V_119 = V_115 -> V_119 ;
unsigned int V_142 , V_143 ;
unsigned int V_144 , V_145 ;
T_1 V_146 , V_147 , V_148 ;
struct V_122 * V_41 = & V_120 -> V_41 ;
struct V_122 * V_123 = & V_120 -> V_123 ;
struct V_149 * V_150 , * V_151 ;
struct V_152 * V_153 , * V_154 ;
unsigned long V_2 ;
T_3 V_155 ;
T_1 V_46 ;
bool V_156 ;
if ( ! V_96 )
return;
if ( F_32 ( ! V_1 -> V_91 ) )
return;
if ( ! V_120 -> V_93 ) {
F_64 ( V_113 , V_141 ) ;
return;
}
V_150 = F_66 ( V_119 , 0 ) ;
V_153 = F_67 ( V_150 ) ;
V_142 = F_68 ( V_41 ) >> 16 ;
V_143 = F_69 ( V_41 ) >> 16 ;
V_146 = ( V_143 - 1 ) << 16 | ( ( V_142 - 1 ) & 0xffff ) ;
V_147 = ( F_69 ( V_123 ) - 1 ) << 16 ;
V_147 |= ( F_68 ( V_123 ) - 1 ) & 0xffff ;
V_144 = V_123 -> V_129 + V_96 -> V_40 . V_157 - V_96 -> V_40 . V_158 ;
V_145 = V_123 -> y1 + V_96 -> V_40 . V_159 - V_96 -> V_40 . V_160 ;
V_148 = V_145 << 16 | ( V_144 & 0xffff ) ;
V_2 = ( V_41 -> V_129 >> 16 ) * F_70 ( V_119 -> V_57 , 0 ) ;
V_2 += ( V_41 -> y1 >> 16 ) * V_119 -> V_161 [ 0 ] ;
V_120 -> V_162 = V_153 -> V_155 + V_2 + V_119 -> V_163 [ 0 ] ;
F_43 ( & V_1 -> V_106 ) ;
F_49 ( V_1 , V_52 , V_19 , V_120 -> V_19 ) ;
F_49 ( V_1 , V_52 , V_164 , V_119 -> V_161 [ 0 ] >> 2 ) ;
F_49 ( V_1 , V_52 , V_162 , V_120 -> V_162 ) ;
if ( F_15 ( V_119 -> V_57 ) ) {
int V_63 = F_24 ( V_119 -> V_57 ) ;
int V_64 = F_25 ( V_119 -> V_57 ) ;
int V_165 = F_70 ( V_119 -> V_57 , 1 ) ;
V_151 = F_66 ( V_119 , 1 ) ;
V_154 = F_67 ( V_151 ) ;
V_2 = ( V_41 -> V_129 >> 16 ) * V_165 / V_63 ;
V_2 += ( V_41 -> y1 >> 16 ) * V_119 -> V_161 [ 1 ] / V_64 ;
V_155 = V_154 -> V_155 + V_2 + V_119 -> V_163 [ 1 ] ;
F_49 ( V_1 , V_52 , V_166 , V_119 -> V_161 [ 1 ] >> 2 ) ;
F_49 ( V_1 , V_52 , V_167 , V_155 ) ;
}
if ( V_52 -> V_69 -> V_70 )
F_23 ( V_1 , V_52 , V_142 , V_143 ,
F_68 ( V_123 ) , F_69 ( V_123 ) ,
V_119 -> V_57 ) ;
F_49 ( V_1 , V_52 , V_146 , V_146 ) ;
F_49 ( V_1 , V_52 , V_147 , V_147 ) ;
F_49 ( V_1 , V_52 , V_148 , V_148 ) ;
V_156 = F_12 ( V_119 -> V_57 ) ;
F_49 ( V_1 , V_52 , V_156 , V_156 ) ;
if ( F_16 ( V_119 -> V_57 ) ) {
F_49 ( V_1 , V_52 , V_168 ,
F_71 ( V_169 ) ) ;
V_46 = F_72 ( 1 ) | F_73 ( V_170 ) |
F_74 ( V_171 ) |
F_75 ( V_172 ) |
F_76 ( V_173 ) |
F_77 ( V_174 ) ;
F_49 ( V_1 , V_52 , V_175 , V_46 ) ;
} else {
F_49 ( V_1 , V_52 , V_175 , F_72 ( 0 ) ) ;
}
F_49 ( V_1 , V_52 , V_93 , 1 ) ;
F_44 ( & V_1 -> V_106 ) ;
}
void F_78 ( struct V_112 * V_113 )
{
struct V_120 * V_120 =
F_60 ( V_113 -> V_115 ) ;
if ( V_113 -> V_115 && V_113 -> V_115 -> V_119 )
F_79 ( V_113 -> V_115 -> V_119 ) ;
F_80 ( V_120 ) ;
V_120 = F_81 ( sizeof( * V_120 ) , V_176 ) ;
if ( ! V_120 )
return;
V_113 -> V_115 = & V_120 -> V_6 ;
V_113 -> V_115 -> V_113 = V_113 ;
}
struct V_114 *
F_82 ( struct V_112 * V_113 )
{
struct V_120 * V_177 ;
struct V_120 * V_120 ;
if ( F_32 ( ! V_113 -> V_115 ) )
return NULL ;
V_177 = F_60 ( V_113 -> V_115 ) ;
V_120 = F_83 ( V_177 ,
sizeof( * V_120 ) , V_176 ) ;
if ( ! V_120 )
return NULL ;
F_84 ( V_113 ,
& V_120 -> V_6 ) ;
return & V_120 -> V_6 ;
}
static void F_85 ( struct V_112 * V_113 ,
struct V_114 * V_115 )
{
struct V_120 * V_178 = F_60 ( V_115 ) ;
F_86 ( V_113 , V_115 ) ;
F_80 ( V_178 ) ;
}
int F_87 ( struct V_95 * V_96 ,
int V_179 ,
int V_180 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
if ( F_32 ( ! V_1 -> V_91 ) )
return - V_38 ;
switch ( V_179 ) {
case V_181 :
F_11 ( V_1 , V_182 , 1 ) ;
break;
case V_183 :
F_11 ( V_1 , V_184 , 1 ) ;
break;
case V_185 :
F_11 ( V_1 , V_186 , 1 ) ;
break;
case V_187 :
F_11 ( V_1 , V_188 , 1 ) ;
break;
default:
F_14 ( L_10 , V_179 ) ;
return - V_38 ;
} ;
F_11 ( V_1 , V_180 , V_180 ) ;
return 0 ;
}
static int F_88 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
unsigned long V_90 ;
if ( F_32 ( ! V_1 -> V_91 ) )
return - V_189 ;
F_33 ( & V_1 -> V_92 , V_90 ) ;
F_34 ( V_1 , V_93 , V_190 , 1 ) ;
F_35 ( & V_1 -> V_92 , V_90 ) ;
return 0 ;
}
static void F_89 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
unsigned long V_90 ;
if ( F_32 ( ! V_1 -> V_91 ) )
return;
F_33 ( & V_1 -> V_92 , V_90 ) ;
F_34 ( V_1 , V_93 , V_190 , 0 ) ;
F_35 ( & V_1 -> V_92 , V_90 ) ;
}
static void F_90 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
F_51 ( & V_1 -> V_191 ) ;
F_32 ( ! F_91 ( & V_1 -> V_191 , 100 ) ) ;
}
static void F_92 ( struct V_95 * V_96 ,
struct V_192 * V_193 )
{
struct V_194 * V_195 = V_96 -> V_97 ;
struct V_1 * V_1 = F_38 ( V_96 ) ;
struct V_196 * V_197 ;
unsigned long V_90 ;
F_33 ( & V_195 -> V_198 , V_90 ) ;
V_197 = V_1 -> V_199 ;
if ( V_197 && V_197 -> V_6 . V_193 == V_193 ) {
V_1 -> V_199 = NULL ;
V_197 -> V_6 . V_200 ( & V_197 -> V_6 ) ;
V_193 -> V_201 += sizeof( V_197 -> V_199 ) ;
}
F_35 ( & V_195 -> V_198 , V_90 ) ;
}
static bool F_93 ( struct V_95 * V_96 ,
const struct V_202 * V_40 ,
struct V_202 * V_138 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
V_138 -> clock =
F_94 ( V_1 -> V_99 , V_40 -> clock * 1000 ) / 1000 ;
return true ;
}
static void F_95 ( struct V_95 * V_96 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
struct V_202 * V_138 = & V_96 -> V_115 -> V_138 ;
T_4 V_203 = V_138 -> V_204 - V_138 -> V_158 ;
T_4 V_139 = V_138 -> V_139 ;
T_4 V_157 = V_138 -> V_157 ;
T_4 V_205 = V_138 -> V_157 - V_138 -> V_158 ;
T_4 V_206 = V_205 + V_139 ;
T_4 V_140 = V_138 -> V_140 ;
T_4 V_159 = V_138 -> V_159 ;
T_4 V_207 = V_138 -> V_208 - V_138 -> V_160 ;
T_4 V_209 = V_138 -> V_159 - V_138 -> V_160 ;
T_4 V_210 = V_209 + V_140 ;
T_1 V_46 ;
F_37 ( V_96 ) ;
if ( F_96 ( V_1 -> V_99 ) ) {
F_51 ( & V_1 -> V_111 ) ;
F_31 ( V_1 ) ;
F_43 ( & V_1 -> V_106 ) ;
F_11 ( V_1 , V_107 , 1 ) ;
F_44 ( & V_1 -> V_106 ) ;
F_52 ( & V_1 -> V_111 ) ;
F_36 ( V_1 ) ;
}
V_46 = 0x8 ;
V_46 |= ( V_138 -> V_90 & V_211 ) ? 0 : 1 ;
V_46 |= ( V_138 -> V_90 & V_212 ) ? 0 : ( 1 << 1 ) ;
F_11 ( V_1 , V_213 , V_46 ) ;
F_11 ( V_1 , V_214 , ( V_157 << 16 ) | V_203 ) ;
V_46 = V_205 << 16 ;
V_46 |= V_206 ;
F_11 ( V_1 , V_215 , V_46 ) ;
F_11 ( V_1 , V_216 , V_46 ) ;
F_11 ( V_1 , V_217 , ( V_159 << 16 ) | V_207 ) ;
V_46 = V_209 << 16 ;
V_46 |= V_210 ;
F_11 ( V_1 , V_218 , V_46 ) ;
F_11 ( V_1 , V_219 , V_46 ) ;
F_97 ( V_1 -> V_99 , V_138 -> clock * 1000 ) ;
F_11 ( V_1 , V_107 , 0 ) ;
}
static void F_98 ( struct V_95 * V_96 ,
struct V_116 * V_220 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
if ( F_32 ( ! V_1 -> V_91 ) )
return;
F_43 ( & V_1 -> V_106 ) ;
F_10 ( V_1 ) ;
F_44 ( & V_1 -> V_106 ) ;
}
static void F_99 ( struct V_95 * V_96 ,
struct V_116 * V_220 )
{
struct V_1 * V_1 = F_38 ( V_96 ) ;
if ( V_96 -> V_115 -> V_199 ) {
F_32 ( F_100 ( V_96 ) != 0 ) ;
V_1 -> V_199 = V_96 -> V_115 -> V_199 ;
V_96 -> V_115 -> V_199 = NULL ;
}
}
static void F_101 ( struct V_95 * V_96 )
{
F_102 ( V_96 ) ;
}
static bool F_103 ( struct V_110 * V_110 )
{
struct V_112 * V_113 = & V_110 -> V_6 ;
struct V_120 * V_115 = F_60 ( V_113 -> V_115 ) ;
T_3 V_162 ;
if ( ! V_115 -> V_93 )
return F_104 ( V_110 -> V_1 , V_110 -> V_14 , V_93 ) == 0 ;
V_162 = F_105 ( V_110 -> V_1 , V_110 -> V_14 ) ;
return V_162 == V_115 -> V_162 ;
}
static void F_106 ( struct V_1 * V_1 )
{
struct V_194 * V_195 = V_1 -> V_103 ;
struct V_95 * V_96 = & V_1 -> V_96 ;
unsigned long V_90 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_1 -> V_14 -> V_109 ; V_12 ++ ) {
if ( ! F_103 ( & V_1 -> V_52 [ V_12 ] ) )
return;
}
if ( V_1 -> V_199 ) {
F_33 ( & V_195 -> V_198 , V_90 ) ;
F_107 ( V_96 , V_1 -> V_199 ) ;
F_108 ( V_96 ) ;
V_1 -> V_199 = NULL ;
F_35 ( & V_195 -> V_198 , V_90 ) ;
}
if ( ! F_109 ( & V_1 -> V_191 ) )
F_110 ( & V_1 -> V_191 ) ;
}
static T_5 F_111 ( int V_108 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
struct V_95 * V_96 = & V_1 -> V_96 ;
T_1 V_221 ;
unsigned long V_90 ;
int V_13 = V_222 ;
F_33 ( & V_1 -> V_92 , V_90 ) ;
V_221 = F_112 ( V_1 , V_223 , V_224 ) ;
if ( V_221 )
F_34 ( V_1 , V_225 , V_221 , 1 ) ;
F_35 ( & V_1 -> V_92 , V_90 ) ;
if ( ! V_221 )
return V_222 ;
if ( V_221 & V_94 ) {
F_110 ( & V_1 -> V_111 ) ;
V_221 &= ~ V_94 ;
V_13 = V_226 ;
}
if ( V_221 & V_190 ) {
F_113 ( V_96 ) ;
F_106 ( V_1 ) ;
V_221 &= ~ V_190 ;
V_13 = V_226 ;
}
if ( V_221 )
F_14 ( L_11 , V_221 ) ;
return V_13 ;
}
static int F_114 ( struct V_1 * V_1 )
{
const struct V_227 * V_227 = V_1 -> V_14 ;
struct V_228 * V_97 = V_1 -> V_97 ;
struct V_194 * V_103 = V_1 -> V_103 ;
struct V_112 * V_229 = NULL , * V_230 = NULL , * V_113 , * V_231 ;
struct V_95 * V_96 = & V_1 -> V_96 ;
struct V_232 * V_233 ;
int V_13 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_227 -> V_109 ; V_12 ++ ) {
struct V_110 * V_110 = & V_1 -> V_52 [ V_12 ] ;
const struct V_51 * V_234 = V_110 -> V_14 ;
if ( V_234 -> type != V_235 &&
V_234 -> type != V_236 )
continue;
V_13 = F_115 ( V_1 -> V_103 , & V_110 -> V_6 ,
0 , & V_237 ,
V_234 -> V_69 -> V_238 ,
V_234 -> V_69 -> V_239 ,
V_234 -> type , NULL ) ;
if ( V_13 ) {
F_14 ( L_12 ) ;
goto V_240;
}
V_113 = & V_110 -> V_6 ;
F_116 ( V_113 , & V_241 ) ;
if ( V_113 -> type == V_235 )
V_229 = V_113 ;
else if ( V_113 -> type == V_236 )
V_230 = V_113 ;
}
V_13 = F_117 ( V_103 , V_96 , V_229 , V_230 ,
& V_242 , NULL ) ;
if ( V_13 )
goto V_240;
F_118 ( V_96 , & V_243 ) ;
for ( V_12 = 0 ; V_12 < V_227 -> V_109 ; V_12 ++ ) {
struct V_110 * V_110 = & V_1 -> V_52 [ V_12 ] ;
const struct V_51 * V_234 = V_110 -> V_14 ;
unsigned long V_244 = 1 << F_119 ( V_96 ) ;
if ( V_234 -> type != V_245 )
continue;
V_13 = F_115 ( V_1 -> V_103 , & V_110 -> V_6 ,
V_244 ,
& V_237 ,
V_234 -> V_69 -> V_238 ,
V_234 -> V_69 -> V_239 ,
V_234 -> type , NULL ) ;
if ( V_13 ) {
F_14 ( L_13 ) ;
goto V_246;
}
F_116 ( & V_110 -> V_6 , & V_241 ) ;
}
V_233 = F_120 ( V_97 -> V_247 , L_14 ) ;
if ( ! V_233 ) {
F_14 ( L_15 ,
V_97 -> V_247 -> V_248 ) ;
V_13 = - V_249 ;
goto V_246;
}
F_121 ( & V_1 -> V_111 ) ;
F_121 ( & V_1 -> V_191 ) ;
V_96 -> V_233 = V_233 ;
F_122 ( V_96 , & V_250 ) ;
return 0 ;
V_246:
F_102 ( V_96 ) ;
V_240:
F_123 (plane, tmp, &drm_dev->mode_config.plane_list,
head)
F_57 ( V_113 ) ;
return V_13 ;
}
static void F_124 ( struct V_1 * V_1 )
{
struct V_95 * V_96 = & V_1 -> V_96 ;
struct V_194 * V_103 = V_1 -> V_103 ;
struct V_112 * V_113 , * V_231 ;
F_125 ( V_96 ) ;
F_126 ( V_96 -> V_233 ) ;
F_123 (plane, tmp, &drm_dev->mode_config.plane_list,
head)
F_56 ( V_113 ) ;
F_102 ( V_96 ) ;
}
static int F_127 ( struct V_1 * V_1 )
{
const struct V_227 * V_227 = V_1 -> V_14 ;
const struct V_251 * V_252 = V_227 -> V_252 ;
struct V_253 * V_254 ;
int V_12 , V_13 ;
V_1 -> V_98 = F_128 ( V_1 -> V_97 , L_16 ) ;
if ( F_129 ( V_1 -> V_98 ) ) {
F_40 ( V_1 -> V_97 , L_17 ) ;
return F_130 ( V_1 -> V_98 ) ;
}
V_1 -> V_101 = F_128 ( V_1 -> V_97 , L_18 ) ;
if ( F_129 ( V_1 -> V_101 ) ) {
F_40 ( V_1 -> V_97 , L_19 ) ;
return F_130 ( V_1 -> V_101 ) ;
}
V_1 -> V_99 = F_128 ( V_1 -> V_97 , L_20 ) ;
if ( F_129 ( V_1 -> V_99 ) ) {
F_40 ( V_1 -> V_97 , L_21 ) ;
return F_130 ( V_1 -> V_99 ) ;
}
V_13 = F_131 ( V_1 -> V_99 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_22 ) ;
return V_13 ;
}
V_13 = F_132 ( V_1 -> V_98 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_23 ) ;
goto V_255;
}
V_13 = F_132 ( V_1 -> V_101 ) ;
if ( V_13 < 0 ) {
F_40 ( V_1 -> V_97 , L_24 ) ;
goto V_100;
}
V_254 = F_133 ( V_1 -> V_97 , L_25 ) ;
if ( F_129 ( V_254 ) ) {
F_40 ( V_1 -> V_97 , L_26 ) ;
V_13 = F_130 ( V_254 ) ;
goto V_104;
}
F_134 ( V_254 ) ;
F_135 ( 10 , 20 ) ;
F_136 ( V_254 ) ;
memcpy ( V_1 -> V_5 , V_1 -> V_4 , V_1 -> V_105 ) ;
for ( V_12 = 0 ; V_12 < V_227 -> V_256 ; V_12 ++ )
F_1 ( V_1 , V_252 [ V_12 ] . V_2 , V_252 [ V_12 ] . V_257 ) ;
for ( V_12 = 0 ; V_12 < V_227 -> V_109 ; V_12 ++ ) {
const struct V_51 * V_52 = & V_227 -> V_52 [ V_12 ] ;
F_49 ( V_1 , V_52 , V_93 , 0 ) ;
}
F_10 ( V_1 ) ;
V_1 -> V_258 = F_133 ( V_1 -> V_97 , L_27 ) ;
if ( F_129 ( V_1 -> V_258 ) ) {
F_40 ( V_1 -> V_97 , L_28 ) ;
V_13 = F_130 ( V_1 -> V_258 ) ;
goto V_104;
}
F_134 ( V_1 -> V_258 ) ;
F_135 ( 10 , 20 ) ;
F_136 ( V_1 -> V_258 ) ;
F_47 ( V_1 -> V_98 ) ;
F_47 ( V_1 -> V_101 ) ;
V_1 -> V_91 = false ;
return 0 ;
V_104:
F_137 ( V_1 -> V_101 ) ;
V_100:
F_137 ( V_1 -> V_98 ) ;
V_255:
F_138 ( V_1 -> V_99 ) ;
return V_13 ;
}
static void F_139 ( struct V_1 * V_1 )
{
const struct V_227 * V_227 = V_1 -> V_14 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_227 -> V_109 ; V_12 ++ ) {
struct V_110 * V_110 = & V_1 -> V_52 [ V_12 ] ;
const struct V_51 * V_234 = & V_227 -> V_52 [ V_12 ] ;
V_110 -> V_14 = V_234 ;
V_110 -> V_1 = V_1 ;
}
}
static int F_140 ( struct V_228 * V_97 , struct V_228 * V_259 , void * V_14 )
{
struct V_260 * V_261 = F_141 ( V_97 ) ;
const struct V_227 * V_227 ;
struct V_194 * V_103 = V_14 ;
struct V_1 * V_1 ;
struct V_262 * V_263 ;
T_6 V_264 ;
int V_13 , V_108 ;
V_227 = F_142 ( V_97 ) ;
if ( ! V_227 )
return - V_265 ;
V_264 = sizeof( * V_1 ) + sizeof( * V_1 -> V_52 ) * V_227 -> V_109 ;
V_1 = F_143 ( V_97 , V_264 , V_176 ) ;
if ( ! V_1 )
return - V_266 ;
V_1 -> V_97 = V_97 ;
V_1 -> V_14 = V_227 ;
V_1 -> V_103 = V_103 ;
F_144 ( V_97 , V_1 ) ;
F_139 ( V_1 ) ;
V_263 = F_145 ( V_261 , V_267 , 0 ) ;
V_1 -> V_105 = F_146 ( V_263 ) ;
V_1 -> V_4 = F_147 ( V_97 , V_263 ) ;
if ( F_129 ( V_1 -> V_4 ) )
return F_130 ( V_1 -> V_4 ) ;
V_1 -> V_5 = F_143 ( V_97 , V_1 -> V_105 , V_176 ) ;
if ( ! V_1 -> V_5 )
return - V_266 ;
V_13 = F_127 ( V_1 ) ;
if ( V_13 < 0 ) {
F_40 ( & V_261 -> V_97 , L_29 , V_13 ) ;
return V_13 ;
}
V_108 = F_148 ( V_261 , 0 ) ;
if ( V_108 < 0 ) {
F_40 ( V_97 , L_30 ) ;
return V_108 ;
}
V_1 -> V_108 = ( unsigned int ) V_108 ;
F_149 ( & V_1 -> V_106 ) ;
F_149 ( & V_1 -> V_92 ) ;
F_150 ( & V_1 -> V_268 ) ;
V_13 = F_151 ( V_97 , V_1 -> V_108 , F_111 ,
V_269 , F_152 ( V_97 ) , V_1 ) ;
if ( V_13 )
return V_13 ;
F_53 ( V_1 -> V_108 ) ;
V_13 = F_114 ( V_1 ) ;
if ( V_13 )
return V_13 ;
F_153 ( & V_261 -> V_97 ) ;
return 0 ;
}
static void F_154 ( struct V_228 * V_97 , struct V_228 * V_259 , void * V_14 )
{
struct V_1 * V_1 = F_155 ( V_97 ) ;
F_156 ( V_97 ) ;
F_124 ( V_1 ) ;
}
