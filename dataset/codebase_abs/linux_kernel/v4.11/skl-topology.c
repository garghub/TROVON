void F_1 ( struct V_1 * V_1 , enum V_2 V_3 )
{
struct V_4 * V_5 = & V_1 -> V_6 -> V_5 ;
switch ( V_3 ) {
case V_7 :
V_5 -> V_8 ++ ;
break;
case V_9 :
V_5 -> V_10 ++ ;
break;
case V_11 :
V_5 -> V_12 ++ ;
break;
}
}
void F_2 ( struct V_1 * V_1 , enum V_2 V_3 )
{
struct V_4 * V_5 = & V_1 -> V_6 -> V_5 ;
switch ( V_3 ) {
case V_7 :
V_5 -> V_8 -- ;
break;
case V_9 :
V_5 -> V_10 -- ;
break;
case V_11 :
V_5 -> V_12 -- ;
break;
}
}
static int F_3 ( struct V_13 * V_14 )
{
switch ( V_14 -> V_15 ) {
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
return false ;
default:
return true ;
}
}
static bool F_4 ( struct V_1 * V_1 ,
struct V_22 * V_23 )
{
struct V_6 * V_24 = V_1 -> V_6 ;
if ( V_1 -> V_25 . V_26 + V_23 -> V_27 -> V_28 >
V_1 -> V_25 . V_29 ) {
F_5 ( V_24 -> V_30 ,
L_1 , V_31 ,
V_23 -> V_15 . V_32 ,
V_23 -> V_15 . V_33 ) ;
F_5 ( V_24 -> V_30 ,
L_2 ,
V_1 -> V_25 . V_29 , V_1 -> V_25 . V_26 ) ;
return false ;
} else {
return true ;
}
}
static void F_6 ( struct V_1 * V_1 ,
struct V_22 * V_23 )
{
V_1 -> V_25 . V_26 += V_23 -> V_27 -> V_28 ;
}
static bool F_7 ( struct V_1 * V_1 ,
struct V_22 * V_23 )
{
struct V_6 * V_24 = V_1 -> V_6 ;
if ( V_1 -> V_25 . V_34 + V_23 -> V_34 > V_1 -> V_25 . V_35 ) {
F_5 ( V_24 -> V_30 ,
L_1 , V_31 ,
V_23 -> V_15 . V_32 , V_23 -> V_15 . V_33 ) ;
F_5 ( V_24 -> V_30 ,
L_3 ,
V_1 -> V_25 . V_35 , V_1 -> V_25 . V_34 ) ;
return false ;
} else {
return true ;
}
}
static void F_8 ( struct V_1 * V_1 ,
struct V_22 * V_23 )
{
V_1 -> V_25 . V_34 += V_23 -> V_34 ;
}
static void
F_9 ( struct V_1 * V_1 , struct V_22 * V_23 )
{
V_1 -> V_25 . V_34 -= V_23 -> V_34 ;
}
static void
F_10 ( struct V_1 * V_1 , struct V_22 * V_23 )
{
V_1 -> V_25 . V_26 -= V_23 -> V_27 -> V_28 ;
}
static void F_11 ( struct V_6 * V_24 ,
struct V_22 * V_36 )
{
F_12 ( V_24 -> V_30 , L_4 ) ;
F_12 ( V_24 -> V_30 , L_5 ) ;
F_12 ( V_24 -> V_30 , L_6 , V_36 -> V_37 [ 0 ] . V_38 ) ;
F_12 ( V_24 -> V_30 , L_7 , V_36 -> V_37 [ 0 ] . V_39 ) ;
F_12 ( V_24 -> V_30 , L_8 , V_36 -> V_37 [ 0 ] . V_40 ) ;
F_12 ( V_24 -> V_30 , L_9 , V_36 -> V_37 [ 0 ] . V_41 ) ;
F_12 ( V_24 -> V_30 , L_10 ) ;
F_12 ( V_24 -> V_30 , L_6 , V_36 -> V_42 [ 0 ] . V_38 ) ;
F_12 ( V_24 -> V_30 , L_7 , V_36 -> V_42 [ 0 ] . V_39 ) ;
F_12 ( V_24 -> V_30 , L_9 , V_36 -> V_42 [ 0 ] . V_41 ) ;
F_12 ( V_24 -> V_30 , L_8 , V_36 -> V_42 [ 0 ] . V_40 ) ;
}
static void F_13 ( struct V_43 * V_44 , int V_45 )
{
int V_46 = 0xFFFFFFFF ;
int V_47 = 0 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_45 ; V_48 ++ ) {
V_46 &= ( ~ ( 0xF << ( 4 * V_48 ) ) | ( V_47 << ( 4 * V_48 ) ) ) ;
V_47 ++ ;
}
V_44 -> V_49 = V_46 ;
}
static void F_14 ( struct V_43 * V_44 ,
struct V_50 * V_51 , int V_52 )
{
if ( V_52 & V_53 )
V_44 -> V_39 = V_51 -> V_39 ;
if ( V_52 & V_54 ) {
V_44 -> V_38 = V_51 -> V_55 ;
F_13 ( V_44 , V_44 -> V_38 ) ;
}
if ( V_52 & V_56 ) {
V_44 -> V_41 = F_15 ( V_51 -> V_57 ) ;
switch ( V_44 -> V_41 ) {
case V_58 :
V_44 -> V_59 = V_44 -> V_41 ;
break;
default:
V_44 -> V_59 = V_60 ;
break;
}
}
}
static void F_16 ( struct V_22 * V_61 ,
struct V_50 * V_51 , bool V_62 )
{
int V_63 , V_64 ;
struct V_43 * V_37 , * V_42 ;
V_37 = & V_61 -> V_37 [ 0 ] ;
V_42 = & V_61 -> V_42 [ 0 ] ;
if ( V_51 -> V_65 == V_66 ) {
if ( V_62 ) {
V_63 = V_61 -> V_67 ;
V_64 = ( ~ V_61 -> V_68 ) &
V_61 -> V_67 ;
} else {
V_64 = V_61 -> V_67 ;
V_63 = ( ~ V_61 -> V_68 ) &
V_61 -> V_67 ;
}
} else {
if ( V_62 ) {
V_64 = V_61 -> V_67 ;
V_63 = ( ~ V_61 -> V_68 ) &
V_61 -> V_67 ;
} else {
V_63 = V_61 -> V_67 ;
V_64 = ( ~ V_61 -> V_68 ) &
V_61 -> V_67 ;
}
}
F_14 ( V_37 , V_51 , V_63 ) ;
F_14 ( V_42 , V_51 , V_64 ) ;
}
static void F_17 ( struct V_6 * V_24 ,
struct V_22 * V_36 )
{
int V_69 = 1 ;
struct V_43 * V_37 , * V_42 ;
int V_70 , V_71 ;
V_37 = & V_36 -> V_37 [ 0 ] ;
V_42 = & V_36 -> V_42 [ 0 ] ;
if ( V_36 -> V_72 == V_73 )
V_69 = 5 ;
if ( V_37 -> V_39 % 1000 )
V_70 = ( V_37 -> V_39 / 1000 ) + 1 ;
else
V_70 = ( V_37 -> V_39 / 1000 ) ;
V_36 -> V_74 = V_70 * ( V_36 -> V_37 -> V_38 ) *
( V_36 -> V_37 -> V_59 >> 3 ) *
V_69 ;
if ( V_36 -> V_42 -> V_39 % 1000 )
V_71 = ( V_36 -> V_42 -> V_39 / 1000 ) + 1 ;
else
V_71 = ( V_36 -> V_42 -> V_39 / 1000 ) ;
V_36 -> V_75 = V_71 * ( V_36 -> V_42 -> V_38 ) *
( V_36 -> V_42 -> V_59 >> 3 ) *
V_69 ;
}
static T_1 F_18 ( int V_76 )
{
int V_77 ;
switch ( V_76 ) {
case V_78 :
V_77 = V_79 ;
break;
case V_80 :
V_77 = V_81 ;
break;
case V_82 :
V_77 = V_83 ;
break;
default:
V_77 = V_84 ;
break;
}
return V_77 ;
}
static int F_19 ( struct V_13 * V_14 ,
struct V_6 * V_24 )
{
struct V_22 * V_61 = V_14 -> V_85 ;
int V_86 , V_87 ;
T_2 V_55 , V_39 , V_57 ;
struct V_88 * V_89 ;
struct V_1 * V_1 = F_20 ( V_24 -> V_30 ) ;
T_1 V_76 = F_18 ( V_61 -> V_76 ) ;
if ( V_61 -> V_90 . V_91 > 0 )
return 0 ;
F_12 ( V_24 -> V_30 , L_11 ) ;
switch ( V_61 -> V_76 ) {
case V_80 :
V_86 = V_92 ;
V_87 = V_93 ;
V_39 = V_61 -> V_37 [ 0 ] . V_39 ;
V_57 = V_61 -> V_37 [ 0 ] . V_59 ;
V_55 = V_61 -> V_37 [ 0 ] . V_38 ;
break;
case V_82 :
V_86 = V_94 ;
if ( V_61 -> V_95 == V_96 ) {
V_87 = V_66 ;
V_39 = V_61 -> V_42 [ 0 ] . V_39 ;
V_57 = V_61 -> V_42 [ 0 ] . V_59 ;
V_55 = V_61 -> V_42 [ 0 ] . V_38 ;
} else {
V_87 = V_93 ;
V_39 = V_61 -> V_37 [ 0 ] . V_39 ;
V_57 = V_61 -> V_37 [ 0 ] . V_59 ;
V_55 = V_61 -> V_37 [ 0 ] . V_38 ;
}
break;
default:
return - V_97 ;
}
V_89 = F_21 ( V_1 , V_61 -> V_98 , V_86 ,
V_57 , V_55 , V_39 , V_87 , V_76 ) ;
if ( V_89 ) {
V_61 -> V_90 . V_91 = V_89 -> V_99 ;
V_61 -> V_90 . V_3 = ( T_2 * ) & V_89 -> V_3 ;
} else {
F_5 ( V_24 -> V_30 , L_12 ,
V_61 -> V_98 , V_86 , V_87 ) ;
F_5 ( V_24 -> V_30 , L_13 ,
V_55 , V_39 , V_57 ) ;
return - V_100 ;
}
return 0 ;
}
static void F_22 ( struct V_13 * V_14 ,
struct V_6 * V_24 )
{
struct V_22 * V_61 = V_14 -> V_85 ;
struct V_50 * V_51 = V_61 -> V_27 -> V_101 ;
int V_102 = V_61 -> V_27 -> V_103 ;
bool V_62 ;
if ( ! V_61 -> V_67 )
return;
F_12 ( V_24 -> V_30 , L_14 ,
V_14 -> V_104 ) ;
F_11 ( V_24 , V_61 ) ;
if ( V_102 == V_105 )
V_62 = true ;
else
V_62 = false ;
F_16 ( V_61 , V_51 , V_62 ) ;
F_17 ( V_24 , V_61 ) ;
F_12 ( V_24 -> V_30 , L_15 ,
V_14 -> V_104 ) ;
F_11 ( V_24 , V_61 ) ;
}
static int F_23 ( struct V_13 * V_14 ,
struct V_6 * V_24 )
{
int V_48 , V_77 ;
struct V_22 * V_23 = V_14 -> V_85 ;
const struct V_106 * V_107 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
if ( V_23 -> V_90 . V_91 > 0 &&
V_23 -> V_90 . V_114 == V_115 ) {
V_113 = & V_23 -> V_90 ;
V_77 = F_24 ( V_24 , V_113 -> V_3 ,
V_113 -> V_91 ,
V_113 -> V_116 , V_23 ) ;
if ( V_77 < 0 )
return V_77 ;
}
for ( V_48 = 0 ; V_48 < V_14 -> V_117 ; V_48 ++ ) {
V_107 = & V_14 -> V_118 [ V_48 ] ;
if ( V_107 -> V_119 & V_120 ) {
V_109 = ( void * ) V_107 -> V_121 ;
V_111 = (struct V_110 * ) V_109 -> V_122 . V_123 ;
if ( V_111 -> V_114 == V_115 ) {
V_77 = F_24 ( V_24 ,
( T_2 * ) V_111 -> V_51 , V_111 -> V_99 ,
V_111 -> V_116 , V_23 ) ;
if ( V_77 < 0 )
return V_77 ;
}
}
}
return 0 ;
}
static int F_25 ( struct V_13 * V_14 )
{
const struct V_106 * V_107 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
struct V_22 * V_23 = V_14 -> V_85 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_117 ; V_48 ++ ) {
V_107 = & V_14 -> V_118 [ V_48 ] ;
if ( V_107 -> V_119 & V_120 ) {
V_109 = (struct V_108 * ) V_107 -> V_121 ;
V_111 = (struct V_110 * ) V_109 -> V_122 . V_123 ;
if ( V_111 -> V_114 != V_124 )
continue;
V_23 -> V_90 . V_3 = ( T_2 * ) V_111 -> V_51 ;
V_23 -> V_90 . V_91 = V_111 -> V_99 ;
break;
}
}
return 0 ;
}
static int F_26 ( struct V_6 * V_24 , struct V_125 * V_27 ,
struct V_13 * V_14 , struct V_22 * V_36 )
{
switch ( V_36 -> V_76 ) {
case V_126 :
return F_27 ( V_24 -> V_30 , V_27 -> V_101 ) ;
case V_127 :
return F_28 ( V_24 -> V_30 , V_27 -> V_101 ) ;
}
return 0 ;
}
static int
F_29 ( struct V_1 * V_1 , struct V_125 * V_27 )
{
struct V_128 * V_129 ;
struct V_13 * V_14 ;
struct V_22 * V_23 ;
struct V_6 * V_24 = V_1 -> V_6 ;
int V_77 = 0 ;
F_30 (w_module, &pipe->w_list, node) {
V_14 = V_129 -> V_14 ;
V_23 = V_14 -> V_85 ;
if ( V_23 -> V_15 . V_32 < 0 ) {
F_5 ( V_1 -> V_6 -> V_30 ,
L_16 ,
( V_130 * ) V_23 -> V_131 ) ;
return - V_100 ;
}
if ( ! F_7 ( V_1 , V_23 ) )
return - V_132 ;
if ( V_23 -> V_133 && V_24 -> V_134 -> V_135 . V_136 ) {
V_77 = V_24 -> V_134 -> V_135 . V_136 ( V_24 -> V_134 ,
V_23 -> V_15 . V_32 , V_23 -> V_131 ) ;
if ( V_77 < 0 )
return V_77 ;
V_23 -> V_137 = V_138 ;
}
V_77 = F_26 ( V_24 , V_27 , V_14 , V_23 ) ;
if ( V_77 < 0 )
return V_77 ;
F_19 ( V_14 , V_24 ) ;
F_22 ( V_14 , V_24 ) ;
V_23 -> V_15 . V_139 = F_31 ( V_24 , V_23 ) ;
if ( V_23 -> V_15 . V_139 < 0 )
return V_77 ;
F_25 ( V_14 ) ;
V_77 = F_32 ( V_24 , V_23 ) ;
if ( V_77 < 0 ) {
F_33 ( V_24 , V_23 ) ;
return V_77 ;
}
F_8 ( V_1 , V_23 ) ;
V_77 = F_23 ( V_14 , V_24 ) ;
if ( V_77 < 0 )
return V_77 ;
}
return 0 ;
}
static int F_34 ( struct V_6 * V_24 ,
struct V_125 * V_27 )
{
int V_77 ;
struct V_128 * V_129 = NULL ;
struct V_22 * V_23 = NULL ;
F_30 (w_module, &pipe->w_list, node) {
V_23 = V_129 -> V_14 -> V_85 ;
if ( V_23 -> V_133 && V_24 -> V_134 -> V_135 . V_140 &&
V_23 -> V_137 > V_141 ) {
V_77 = V_24 -> V_134 -> V_135 . V_140 ( V_24 -> V_134 ,
V_23 -> V_15 . V_32 ) ;
if ( V_77 < 0 )
return - V_100 ;
}
F_33 ( V_24 , V_23 ) ;
}
return 0 ;
}
static int F_35 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
int V_77 ;
struct V_22 * V_23 = V_14 -> V_85 ;
struct V_128 * V_129 ;
struct V_125 * V_142 = V_23 -> V_27 ;
struct V_22 * V_143 = NULL , * V_144 ;
struct V_6 * V_24 = V_1 -> V_6 ;
if ( ! F_7 ( V_1 , V_23 ) )
return - V_145 ;
if ( ! F_4 ( V_1 , V_23 ) )
return - V_132 ;
V_77 = F_36 ( V_24 , V_23 -> V_27 ) ;
if ( V_77 < 0 )
return V_77 ;
F_6 ( V_1 , V_23 ) ;
F_8 ( V_1 , V_23 ) ;
V_77 = F_29 ( V_1 , V_142 ) ;
if ( V_77 < 0 )
return V_77 ;
F_30 (w_module, &s_pipe->w_list, node) {
V_144 = V_129 -> V_14 -> V_85 ;
if ( V_143 == NULL ) {
V_143 = V_144 ;
continue;
}
V_77 = F_37 ( V_24 , V_143 , V_144 ) ;
if ( V_77 < 0 )
return V_77 ;
V_143 = V_144 ;
}
return 0 ;
}
static int F_38 ( struct V_6 * V_24 ,
struct V_110 * V_146 )
{
struct V_147 * V_51 = (struct V_147 * ) V_146 -> V_51 ;
struct V_148 * V_149 ;
int V_48 , V_139 ;
V_149 = V_51 -> V_150 ;
for ( V_48 = 0 ; V_48 < V_51 -> V_151 ; V_48 ++ ) {
V_139 = F_39 ( V_24 ,
V_149 -> V_152 , V_149 -> V_153 ) ;
if ( V_139 < 0 )
return - V_97 ;
V_149 -> V_153 = V_139 ;
V_149 ++ ;
}
return 0 ;
}
static int F_40 ( struct V_13 * V_14 ,
struct V_22 * V_36 , struct V_6 * V_24 )
{
int V_48 , V_77 ;
struct V_22 * V_23 = V_14 -> V_85 ;
const struct V_106 * V_107 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
for ( V_48 = 0 ; V_48 < V_36 -> V_154 ; V_48 ++ ) {
if ( V_36 -> V_155 [ V_48 ] . V_156 != V_157 )
return 0 ;
}
for ( V_48 = 0 ; V_48 < V_36 -> V_158 ; V_48 ++ ) {
if ( V_36 -> V_159 [ V_48 ] . V_156 != V_157 )
return 0 ;
}
if ( V_23 -> V_90 . V_91 > 0 &&
V_23 -> V_90 . V_114 == V_160 ) {
V_113 = & V_23 -> V_90 ;
V_77 = F_24 ( V_24 , V_113 -> V_3 ,
V_113 -> V_91 ,
V_113 -> V_116 , V_23 ) ;
if ( V_77 < 0 )
return V_77 ;
}
for ( V_48 = 0 ; V_48 < V_14 -> V_117 ; V_48 ++ ) {
V_107 = & V_14 -> V_118 [ V_48 ] ;
if ( V_107 -> V_119 & V_120 ) {
V_109 = ( void * ) V_107 -> V_121 ;
V_111 = (struct V_110 * ) V_109 -> V_122 . V_123 ;
if ( V_111 -> V_114 == V_160 ) {
if ( V_23 -> V_72 == V_161 )
F_38 ( V_24 , V_111 ) ;
V_77 = F_24 ( V_24 ,
( T_2 * ) V_111 -> V_51 , V_111 -> V_162 ,
V_111 -> V_116 , V_23 ) ;
if ( V_77 < 0 )
return V_77 ;
}
}
}
return 0 ;
}
static int F_41 ( struct V_13 * V_14 ,
struct V_1 * V_1 ,
struct V_13 * V_163 ,
struct V_22 * V_164 )
{
struct V_165 * V_166 ;
struct V_13 * V_167 = NULL , * V_168 = NULL ;
struct V_22 * V_169 ;
struct V_6 * V_24 = V_1 -> V_6 ;
int V_77 ;
F_42 (w, p) {
if ( ! V_166 -> V_170 )
continue;
F_12 ( V_24 -> V_30 , L_17 , V_31 , V_14 -> V_104 ) ;
F_12 ( V_24 -> V_30 , L_18 , V_31 , V_166 -> V_167 -> V_104 ) ;
V_168 = V_166 -> V_167 ;
if ( ! F_3 ( V_166 -> V_167 ) )
return F_41 ( V_166 -> V_167 , V_1 , V_163 , V_164 ) ;
if ( ( V_166 -> V_167 -> V_85 != NULL ) &&
F_3 ( V_166 -> V_167 ) ) {
V_167 = V_166 -> V_167 ;
V_169 = V_167 -> V_85 ;
if ( V_164 -> V_137 == V_141 ||
V_169 -> V_137 == V_141 )
continue;
V_77 = F_37 ( V_24 , V_164 , V_169 ) ;
if ( V_77 )
return V_77 ;
F_40 ( V_163 , V_164 , V_24 ) ;
F_40 ( V_167 , V_169 , V_24 ) ;
if ( V_169 -> V_27 -> V_171 != V_172 ) {
if ( V_169 -> V_27 -> V_103 !=
V_105 )
V_77 = F_43 ( V_24 ,
V_169 -> V_27 ) ;
if ( V_77 )
return V_77 ;
}
}
}
if ( ! V_167 )
return F_41 ( V_168 , V_1 , V_163 , V_164 ) ;
return 0 ;
}
static int F_44 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
struct V_22 * V_164 ;
struct V_6 * V_24 = V_1 -> V_6 ;
int V_77 = 0 ;
V_164 = V_14 -> V_85 ;
V_77 = F_41 ( V_14 , V_1 , V_14 , V_164 ) ;
if ( V_77 )
return V_77 ;
if ( V_164 -> V_27 -> V_103 != V_105 )
return F_43 ( V_24 , V_164 -> V_27 ) ;
return 0 ;
}
static struct V_13 * F_45 (
struct V_13 * V_14 , struct V_1 * V_1 )
{
struct V_165 * V_166 ;
struct V_13 * V_163 = NULL ;
struct V_6 * V_24 = V_1 -> V_6 ;
F_46 (w, p) {
V_163 = V_166 -> V_173 ;
if ( ! V_166 -> V_170 )
continue;
F_12 ( V_24 -> V_30 , L_19 , V_14 -> V_104 ) ;
F_12 ( V_24 -> V_30 , L_20 , V_166 -> V_173 -> V_104 ) ;
if ( ( V_166 -> V_173 -> V_85 != NULL ) &&
F_3 ( V_166 -> V_173 ) ) {
return V_166 -> V_173 ;
}
}
if ( V_163 != NULL )
return F_45 ( V_163 , V_1 ) ;
return NULL ;
}
static int F_47 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
int V_77 = 0 ;
struct V_13 * V_173 , * V_167 ;
struct V_22 * V_164 , * V_169 ;
struct V_6 * V_24 = V_1 -> V_6 ;
int V_174 = 0 ;
V_167 = V_14 ;
V_169 = V_167 -> V_85 ;
V_173 = F_45 ( V_14 , V_1 ) ;
if ( V_173 != NULL ) {
V_164 = V_173 -> V_85 ;
V_169 = V_167 -> V_85 ;
V_174 = 1 ;
if ( V_164 -> V_27 -> V_171 != V_172 )
V_174 = 0 ;
}
if ( V_174 ) {
V_77 = F_37 ( V_24 , V_164 , V_169 ) ;
if ( V_77 )
return V_77 ;
F_40 ( V_173 , V_164 , V_24 ) ;
F_40 ( V_167 , V_169 , V_24 ) ;
if ( V_169 -> V_27 -> V_103 != V_105 )
V_77 = F_43 ( V_24 , V_169 -> V_27 ) ;
}
return V_77 ;
}
static int F_48 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
struct V_22 * V_164 , * V_169 ;
int V_77 = 0 , V_48 ;
struct V_6 * V_24 = V_1 -> V_6 ;
V_169 = V_14 -> V_85 ;
V_77 = F_49 ( V_24 , V_169 -> V_27 ) ;
if ( V_77 )
return V_77 ;
for ( V_48 = 0 ; V_48 < V_169 -> V_158 ; V_48 ++ ) {
if ( V_169 -> V_159 [ V_48 ] . V_156 == V_157 ) {
V_164 = V_169 -> V_159 [ V_48 ] . V_175 ;
if ( ! V_164 )
continue;
V_77 = F_49 ( V_24 , V_164 -> V_27 ) ;
if ( V_77 < 0 )
return V_77 ;
V_77 = F_50 ( V_24 ,
V_164 , V_169 ) ;
}
}
return V_77 ;
}
static int F_51 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
struct V_22 * V_23 = V_14 -> V_85 ;
struct V_128 * V_129 ;
struct V_22 * V_143 = NULL , * V_144 ;
struct V_6 * V_24 = V_1 -> V_6 ;
struct V_125 * V_142 = V_23 -> V_27 ;
if ( V_142 -> V_171 == V_176 )
return - V_97 ;
F_9 ( V_1 , V_23 ) ;
F_10 ( V_1 , V_23 ) ;
F_30 (w_module, &s_pipe->w_list, node) {
V_144 = V_129 -> V_14 -> V_85 ;
if ( V_23 -> V_137 >= V_177 )
F_9 ( V_1 , V_144 ) ;
if ( V_143 == NULL ) {
V_143 = V_144 ;
continue;
}
F_50 ( V_24 , V_143 , V_144 ) ;
V_143 = V_144 ;
}
F_52 ( V_24 , V_23 -> V_27 ) ;
return F_34 ( V_24 , V_142 ) ;
}
static int F_53 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
struct V_22 * V_164 , * V_169 ;
int V_77 = 0 , V_48 ;
struct V_6 * V_24 = V_1 -> V_6 ;
V_164 = V_14 -> V_85 ;
V_77 = F_49 ( V_24 , V_164 -> V_27 ) ;
if ( V_77 )
return V_77 ;
for ( V_48 = 0 ; V_48 < V_164 -> V_154 ; V_48 ++ ) {
if ( V_164 -> V_155 [ V_48 ] . V_156 == V_157 ) {
V_169 = V_164 -> V_155 [ V_48 ] . V_175 ;
if ( ! V_169 )
continue;
V_77 = F_50 ( V_24 , V_164 ,
V_169 ) ;
}
}
return V_77 ;
}
static int F_54 ( struct V_13 * V_14 ,
struct V_178 * V_107 , int V_179 )
{
struct V_180 * V_181 = V_14 -> V_181 ;
struct V_1 * V_1 = F_20 ( V_181 -> V_30 ) ;
switch ( V_179 ) {
case V_182 :
return F_35 ( V_14 , V_1 ) ;
case V_183 :
return F_47 ( V_14 , V_1 ) ;
case V_184 :
return F_48 ( V_14 , V_1 ) ;
case V_185 :
return F_51 ( V_14 , V_1 ) ;
}
return 0 ;
}
static int F_55 ( struct V_13 * V_14 ,
struct V_178 * V_107 , int V_179 )
{
struct V_180 * V_181 = V_14 -> V_181 ;
struct V_1 * V_1 = F_20 ( V_181 -> V_30 ) ;
switch ( V_179 ) {
case V_182 :
return F_35 ( V_14 , V_1 ) ;
case V_183 :
return F_47 ( V_14 , V_1 ) ;
case V_184 :
return F_48 ( V_14 , V_1 ) ;
case V_185 :
return F_51 ( V_14 , V_1 ) ;
}
return 0 ;
}
static int F_56 ( struct V_13 * V_14 ,
struct V_178 * V_107 , int V_179 )
{
struct V_180 * V_181 = V_14 -> V_181 ;
struct V_1 * V_1 = F_20 ( V_181 -> V_30 ) ;
switch ( V_179 ) {
case V_182 :
return F_44 ( V_14 , V_1 ) ;
case V_185 :
return F_53 ( V_14 , V_1 ) ;
}
return 0 ;
}
static int F_57 ( struct V_178 * V_186 ,
unsigned int T_3 * V_187 , unsigned int V_99 )
{
struct V_108 * V_109 =
(struct V_108 * ) V_186 -> V_121 ;
struct V_110 * V_111 = (struct V_110 * ) V_109 -> V_122 . V_123 ;
struct V_13 * V_14 = F_58 ( V_186 ) ;
struct V_22 * V_23 = V_14 -> V_85 ;
struct V_1 * V_1 = F_20 ( V_14 -> V_181 -> V_30 ) ;
if ( V_14 -> V_188 )
F_59 ( V_1 -> V_6 , ( T_2 * ) V_111 -> V_51 ,
V_111 -> V_99 , V_111 -> V_116 , V_23 ) ;
V_99 -= 2 * sizeof( T_2 ) ;
if ( V_99 > V_111 -> V_162 )
V_99 = V_111 -> V_162 ;
if ( V_111 -> V_51 ) {
if ( F_60 ( V_187 , & V_111 -> V_116 , sizeof( T_2 ) ) )
return - V_189 ;
if ( F_60 ( V_187 + 1 , & V_99 , sizeof( T_2 ) ) )
return - V_189 ;
if ( F_60 ( V_187 + 2 , V_111 -> V_51 , V_99 ) )
return - V_189 ;
}
return 0 ;
}
static int F_61 ( struct V_178 * V_186 ,
const unsigned int T_3 * V_187 , unsigned int V_99 )
{
struct V_13 * V_14 = F_58 ( V_186 ) ;
struct V_22 * V_23 = V_14 -> V_85 ;
struct V_108 * V_109 =
(struct V_108 * ) V_186 -> V_121 ;
struct V_110 * V_190 = (struct V_110 * ) V_109 -> V_122 . V_123 ;
struct V_1 * V_1 = F_20 ( V_14 -> V_181 -> V_30 ) ;
if ( V_190 -> V_51 ) {
if ( V_99 > V_190 -> V_162 )
return - V_97 ;
V_190 -> V_99 = V_99 ;
if ( V_190 -> V_116 == V_191 ) {
if ( F_62 ( V_190 -> V_51 , V_187 , V_99 ) )
return - V_189 ;
} else {
if ( F_62 ( V_190 -> V_51 ,
V_187 + 2 , V_99 ) )
return - V_189 ;
}
if ( V_14 -> V_188 )
return F_24 ( V_1 -> V_6 ,
( T_2 * ) V_190 -> V_51 , V_190 -> V_99 ,
V_190 -> V_116 , V_23 ) ;
}
return 0 ;
}
static void F_63 ( struct V_22 * V_36 ,
struct V_50 * V_51 )
{
struct V_125 * V_27 = V_36 -> V_27 ;
if ( V_27 -> V_192 ) {
switch ( V_36 -> V_76 ) {
case V_127 :
V_27 -> V_101 -> V_193 = V_51 -> V_193 ;
V_27 -> V_101 -> V_194 = V_51 -> V_194 ;
break;
case V_126 :
V_27 -> V_101 -> V_195 = V_51 -> V_195 ;
break;
default:
break;
}
V_27 -> V_101 -> V_57 = V_51 -> V_57 ;
V_27 -> V_101 -> V_55 = V_51 -> V_55 ;
V_27 -> V_101 -> V_39 = V_51 -> V_39 ;
V_27 -> V_101 -> V_65 = V_51 -> V_65 ;
V_27 -> V_101 -> V_196 = V_51 -> V_196 ;
} else {
memcpy ( V_27 -> V_101 , V_51 , sizeof( * V_51 ) ) ;
}
}
int F_64 ( struct V_197 * V_30 ,
struct V_22 * V_23 ,
struct V_50 * V_51 )
{
struct V_43 * V_196 = NULL ;
F_63 ( V_23 , V_51 ) ;
if ( V_51 -> V_65 == V_66 )
V_196 = & V_23 -> V_37 [ 0 ] ;
else
V_196 = & V_23 -> V_42 [ 0 ] ;
V_196 -> V_39 = V_51 -> V_39 ;
V_196 -> V_38 = V_51 -> V_55 ;
V_196 -> V_41 = F_15 ( V_51 -> V_57 ) ;
switch ( V_196 -> V_41 ) {
case V_58 :
V_196 -> V_59 = V_196 -> V_41 ;
break;
case V_198 :
case V_60 :
V_196 -> V_59 = V_60 ;
break;
default:
F_5 ( V_30 , L_21 ,
V_196 -> V_41 ) ;
return - V_97 ;
}
if ( V_51 -> V_65 == V_66 ) {
V_23 -> V_74 = ( V_196 -> V_39 / 1000 ) *
( V_196 -> V_38 ) *
( V_196 -> V_59 >> 3 ) ;
} else {
V_23 -> V_75 = ( V_196 -> V_39 / 1000 ) *
( V_196 -> V_38 ) *
( V_196 -> V_59 >> 3 ) ;
}
return 0 ;
}
struct V_22 *
F_65 ( struct V_199 * V_200 , int V_65 )
{
struct V_13 * V_14 ;
struct V_165 * V_166 = NULL ;
if ( V_65 == V_66 ) {
V_14 = V_200 -> V_201 ;
F_42 (w, p) {
if ( V_166 -> V_170 && V_166 -> V_167 -> V_188 &&
! F_3 ( V_166 -> V_167 ) )
continue;
if ( V_166 -> V_167 -> V_85 ) {
F_12 ( V_200 -> V_30 , L_22 ,
V_166 -> V_167 -> V_104 ) ;
return V_166 -> V_167 -> V_85 ;
}
}
} else {
V_14 = V_200 -> V_202 ;
F_46 (w, p) {
if ( V_166 -> V_170 && V_166 -> V_173 -> V_188 &&
! F_3 ( V_166 -> V_173 ) )
continue;
if ( V_166 -> V_173 -> V_85 ) {
F_12 ( V_200 -> V_30 , L_22 ,
V_166 -> V_173 -> V_104 ) ;
return V_166 -> V_173 -> V_85 ;
}
}
}
return NULL ;
}
static struct V_22 * F_66 (
struct V_199 * V_200 , struct V_13 * V_14 )
{
struct V_165 * V_166 ;
struct V_22 * V_23 = NULL ;
F_46 (w, p) {
if ( V_14 -> V_203 [ V_204 ] > 0 ) {
if ( V_166 -> V_170 &&
( V_166 -> V_167 -> V_15 == V_19 ) &&
V_166 -> V_173 -> V_85 ) {
V_23 = V_166 -> V_173 -> V_85 ;
return V_23 ;
}
V_23 = F_66 ( V_200 , V_166 -> V_173 ) ;
if ( V_23 )
return V_23 ;
}
}
return V_23 ;
}
static struct V_22 * F_67 (
struct V_199 * V_200 , struct V_13 * V_14 )
{
struct V_165 * V_166 ;
struct V_22 * V_23 = NULL ;
F_42 (w, p) {
if ( V_14 -> V_203 [ V_205 ] > 0 ) {
if ( V_166 -> V_170 &&
( V_166 -> V_173 -> V_15 == V_18 ) &&
V_166 -> V_167 -> V_85 ) {
V_23 = V_166 -> V_167 -> V_85 ;
return V_23 ;
}
V_23 = F_67 ( V_200 , V_166 -> V_167 ) ;
if ( V_23 )
return V_23 ;
}
}
return V_23 ;
}
struct V_22 *
F_68 ( struct V_199 * V_200 , int V_65 )
{
struct V_13 * V_14 ;
struct V_22 * V_23 ;
if ( V_65 == V_66 ) {
V_14 = V_200 -> V_201 ;
V_23 = F_66 ( V_200 , V_14 ) ;
} else {
V_14 = V_200 -> V_202 ;
V_23 = F_67 ( V_200 , V_14 ) ;
}
return V_23 ;
}
static T_1 F_69 ( int V_76 )
{
int V_77 ;
switch ( V_76 ) {
case V_78 :
V_77 = V_94 ;
break;
case V_80 :
V_77 = V_92 ;
break;
case V_82 :
V_77 = V_94 ;
break;
case V_127 :
V_77 = V_206 ;
break;
default:
V_77 = V_207 ;
break;
}
return V_77 ;
}
static int F_70 ( struct V_199 * V_200 ,
struct V_22 * V_23 ,
struct V_50 * V_51 )
{
struct V_88 * V_89 ;
struct V_1 * V_1 = F_20 ( V_200 -> V_30 ) ;
int V_86 = F_69 ( V_23 -> V_76 ) ;
T_1 V_76 = F_18 ( V_23 -> V_76 ) ;
F_63 ( V_23 , V_51 ) ;
if ( V_86 == V_206 )
return 0 ;
V_89 = F_21 ( V_1 , V_23 -> V_98 , V_86 ,
V_51 -> V_57 , V_51 -> V_55 ,
V_51 -> V_39 , V_51 -> V_65 ,
V_76 ) ;
if ( V_89 ) {
V_23 -> V_90 . V_91 = V_89 -> V_99 ;
V_23 -> V_90 . V_3 = ( T_2 * ) & V_89 -> V_3 ;
} else {
F_5 ( V_200 -> V_30 , L_12 ,
V_23 -> V_98 , V_86 ,
V_51 -> V_65 ) ;
F_5 ( V_200 -> V_30 , L_13 ,
V_51 -> V_55 , V_51 -> V_39 , V_51 -> V_57 ) ;
return - V_97 ;
}
return 0 ;
}
static int F_71 ( struct V_199 * V_200 ,
struct V_13 * V_14 ,
struct V_50 * V_51 )
{
struct V_165 * V_166 ;
int V_77 = - V_100 ;
F_46 (w, p) {
if ( V_166 -> V_170 && F_3 ( V_166 -> V_173 ) &&
V_166 -> V_173 -> V_85 ) {
V_77 = F_70 ( V_200 ,
V_166 -> V_173 -> V_85 , V_51 ) ;
if ( V_77 < 0 )
return V_77 ;
} else {
V_77 = F_71 ( V_200 ,
V_166 -> V_173 , V_51 ) ;
if ( V_77 < 0 )
return V_77 ;
}
}
return V_77 ;
}
static int F_72 ( struct V_199 * V_200 ,
struct V_13 * V_14 , struct V_50 * V_51 )
{
struct V_165 * V_166 = NULL ;
int V_77 = - V_100 ;
F_42 (w, p) {
if ( V_166 -> V_170 && F_3 ( V_166 -> V_167 ) &&
V_166 -> V_167 -> V_85 ) {
V_77 = F_70 ( V_200 ,
V_166 -> V_167 -> V_85 , V_51 ) ;
if ( V_77 < 0 )
return V_77 ;
} else {
V_77 = F_72 (
V_200 , V_166 -> V_167 , V_51 ) ;
if ( V_77 < 0 )
return V_77 ;
}
}
return V_77 ;
}
int F_73 ( struct V_199 * V_200 ,
struct V_50 * V_51 )
{
struct V_13 * V_14 ;
if ( V_51 -> V_65 == V_66 ) {
V_14 = V_200 -> V_201 ;
return F_71 ( V_200 , V_14 , V_51 ) ;
} else {
V_14 = V_200 -> V_202 ;
return F_72 ( V_200 , V_14 , V_51 ) ;
}
return 0 ;
}
static int F_74 ( struct V_197 * V_30 ,
struct V_125 * V_27 , T_2 V_208 ,
T_2 V_209 )
{
switch ( V_208 ) {
case V_210 :
V_27 -> V_103 = V_209 ;
break;
case V_211 :
V_27 -> V_212 = V_209 ;
break;
case V_213 :
V_27 -> V_28 = V_209 ;
break;
case V_214 :
V_27 -> V_215 = V_209 ;
break;
default:
F_5 ( V_30 , L_23 , V_208 ) ;
return - V_97 ;
}
return 0 ;
}
static int F_75 ( struct V_197 * V_30 ,
struct V_22 * V_23 , struct V_1 * V_1 ,
struct V_216 * V_217 )
{
struct V_218 * V_219 ;
struct V_125 * V_27 ;
struct V_50 * V_51 ;
F_30 (ppl, &skl->ppl_list, node) {
if ( V_219 -> V_27 -> V_220 == V_217 -> V_221 ) {
V_23 -> V_27 = V_219 -> V_27 ;
return V_222 ;
}
}
V_219 = F_76 ( V_30 , sizeof( * V_219 ) , V_223 ) ;
if ( ! V_219 )
return - V_132 ;
V_27 = F_76 ( V_30 , sizeof( * V_27 ) , V_223 ) ;
if ( ! V_27 )
return - V_132 ;
V_51 = F_76 ( V_30 , sizeof( * V_51 ) , V_223 ) ;
if ( ! V_51 )
return - V_132 ;
V_27 -> V_101 = V_51 ;
V_27 -> V_220 = V_217 -> V_221 ;
F_77 ( & V_27 -> V_224 ) ;
V_219 -> V_27 = V_27 ;
F_78 ( & V_219 -> V_225 , & V_1 -> V_226 ) ;
V_23 -> V_27 = V_27 ;
V_23 -> V_27 -> V_171 = V_176 ;
return 0 ;
}
static int F_79 ( struct V_197 * V_30 , T_2 V_208 ,
struct V_227 * V_228 ,
int V_229 , T_2 V_221 )
{
switch ( V_208 ) {
case V_230 :
V_228 [ V_229 ] . V_15 . V_32 = V_221 ;
break;
case V_231 :
V_228 [ V_229 ] . V_15 . V_33 = V_221 ;
break;
default:
F_5 ( V_30 , L_24 , V_221 ) ;
return - V_97 ;
}
return 0 ;
}
static int F_80 ( struct V_197 * V_30 ,
struct V_22 * V_23 ,
struct V_216 * V_217 ,
int V_87 , int V_232 )
{
int V_77 ;
struct V_227 * V_228 ;
switch ( V_87 ) {
case V_233 :
V_228 = V_23 -> V_159 ;
break;
case V_234 :
V_228 = V_23 -> V_155 ;
break;
default:
F_5 ( V_30 , L_25 ) ;
return - V_97 ;
}
V_77 = F_79 ( V_30 , V_217 -> V_235 ,
V_228 , V_232 , V_217 -> V_221 ) ;
if ( V_77 < 0 )
return V_77 ;
V_228 [ V_232 ] . V_236 = false ;
V_228 [ V_232 ] . V_156 = V_237 ;
return 0 ;
}
static int F_81 ( struct V_197 * V_30 ,
struct V_22 * V_23 , T_2 V_208 ,
T_2 V_221 , T_2 V_87 , T_2 V_232 )
{
struct V_43 * V_238 ;
switch ( V_87 ) {
case V_233 :
V_238 = V_23 -> V_37 ;
V_238 += V_232 ;
break;
case V_234 :
V_238 = V_23 -> V_42 ;
V_238 += V_232 ;
break;
default:
F_5 ( V_30 , L_25 ) ;
return - V_97 ;
}
switch ( V_208 ) {
case V_239 :
V_238 -> V_38 = V_221 ;
break;
case V_240 :
V_238 -> V_39 = V_221 ;
break;
case V_241 :
V_238 -> V_59 = V_221 ;
break;
case V_242 :
V_238 -> V_41 = V_221 ;
break;
case V_243 :
V_238 -> V_40 = V_221 ;
break;
case V_244 :
V_238 -> V_245 = V_221 ;
break;
case V_246 :
V_238 -> V_247 = V_221 ;
break;
case V_248 :
V_238 -> V_49 = V_221 ;
break;
default:
F_5 ( V_30 , L_26 , V_208 ) ;
return - V_97 ;
}
return 0 ;
}
static int F_82 ( struct V_197 * V_30 , struct V_22 * V_23 ,
struct V_249 * V_250 )
{
if ( V_250 -> V_235 == V_251 )
memcpy ( & V_23 -> V_131 , & V_250 -> V_252 , 16 ) ;
else {
F_5 ( V_30 , L_27 , V_250 -> V_235 ) ;
return - V_97 ;
}
return 0 ;
}
static void F_83 (
struct V_227 * V_253 , T_2 V_232 , T_2 V_221 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_232 ; V_48 ++ )
V_253 [ V_48 ] . V_254 = V_221 ;
}
static int F_84 ( struct V_197 * V_30 ,
struct V_216 * V_217 ,
struct V_1 * V_1 , struct V_22 * V_23 )
{
int V_255 = 0 ;
int V_77 ;
static int V_256 ;
static int V_229 , V_87 ;
if ( V_217 -> V_235 > V_257 )
return - V_97 ;
switch ( V_217 -> V_235 ) {
case V_258 :
V_23 -> V_158 = V_217 -> V_221 ;
V_23 -> V_159 = F_76 ( V_30 , V_23 -> V_158 *
sizeof( * V_23 -> V_159 ) ,
V_223 ) ;
if ( ! V_23 -> V_159 )
return - V_132 ;
break;
case V_259 :
V_23 -> V_154 = V_217 -> V_221 ;
V_23 -> V_155 = F_76 ( V_30 , V_23 -> V_154 *
sizeof( * V_23 -> V_155 ) ,
V_223 ) ;
if ( ! V_23 -> V_155 )
return - V_132 ;
break;
case V_260 :
if ( ! V_23 -> V_159 )
return - V_132 ;
F_83 ( V_23 -> V_159 ,
V_23 -> V_158 , V_217 -> V_221 ) ;
break;
case V_261 :
if ( ! V_23 -> V_155 )
return - V_132 ;
F_83 ( V_23 -> V_155 ,
V_23 -> V_154 , V_217 -> V_221 ) ;
break;
case V_262 :
V_23 -> V_263 = V_217 -> V_221 ;
break;
case V_264 :
V_23 -> V_265 = V_217 -> V_221 ;
case V_266 :
V_23 -> V_72 = V_217 -> V_221 ;
break;
case V_267 :
V_23 -> V_76 = V_217 -> V_221 ;
break;
case V_268 :
V_23 -> V_95 = V_217 -> V_221 ;
break;
case V_269 :
V_23 -> V_15 . V_33 =
V_217 -> V_221 ;
break;
case V_270 :
V_23 -> V_271 = V_217 -> V_221 ;
break;
case V_272 :
V_23 -> V_34 = V_217 -> V_221 ;
break;
case V_273 :
V_23 -> V_75 = V_217 -> V_221 ;
break;
case V_274 :
V_23 -> V_74 = V_217 -> V_221 ;
break;
case V_275 :
V_23 -> V_98 = V_217 -> V_221 ;
break;
case V_276 :
V_23 -> V_67 = V_217 -> V_221 ;
break;
case V_277 :
V_23 -> V_68 = V_217 -> V_221 ;
break;
case V_278 :
V_23 -> V_279 = V_217 -> V_221 ;
break;
case V_280 :
V_77 = F_75 ( V_30 ,
V_23 , V_1 , V_217 ) ;
if ( V_77 < 0 )
return V_256 ;
if ( V_77 == V_222 )
V_256 = 1 ;
break;
case V_210 :
case V_211 :
case V_213 :
case V_214 :
if ( V_256 ) {
V_77 = F_74 ( V_30 , V_23 -> V_27 ,
V_217 -> V_235 , V_217 -> V_221 ) ;
if ( V_77 < 0 )
return V_77 ;
}
break;
case V_281 :
V_87 = V_217 -> V_221 & V_282 ;
V_229 = ( V_217 -> V_221 &
V_283 ) >> 4 ;
break;
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
case V_244 :
case V_246 :
case V_248 :
V_77 = F_81 ( V_30 , V_23 , V_217 -> V_235 ,
V_217 -> V_221 , V_87 , V_229 ) ;
if ( V_77 < 0 )
return V_77 ;
break;
case V_230 :
case V_231 :
V_77 = F_80 ( V_30 ,
V_23 , V_217 , V_87 ,
V_229 ) ;
if ( V_77 < 0 )
return V_77 ;
break;
case V_284 :
V_23 -> V_90 . V_91 =
V_217 -> V_221 ;
break;
case V_285 :
V_23 -> V_286 =
V_217 -> V_221 ;
break;
case V_287 :
case V_288 :
case V_289 :
break;
default:
F_5 ( V_30 , L_28 ,
V_217 -> V_235 ) ;
return - V_97 ;
}
V_255 ++ ;
return V_255 ;
}
static int F_85 ( struct V_197 * V_30 ,
char * V_290 , struct V_1 * V_1 ,
struct V_22 * V_23 , int V_291 )
{
struct V_292 * V_293 ;
struct V_216 * V_217 ;
int V_255 = 0 , V_77 ;
int V_294 = 0 , V_295 = 0 ;
if ( V_291 <= 0 )
return - V_97 ;
while ( V_295 < V_291 ) {
V_293 = (struct V_292 * ) ( V_290 + V_294 ) ;
V_294 += V_293 -> V_99 ;
switch ( V_293 -> type ) {
case V_296 :
F_86 ( V_30 , L_29 ) ;
continue;
case V_297 :
V_77 = F_82 ( V_30 , V_23 , V_293 -> V_252 ) ;
if ( V_77 < 0 )
return V_77 ;
V_295 += sizeof( * V_293 -> V_252 ) ;
continue;
default:
V_217 = V_293 -> V_221 ;
V_255 = 0 ;
break;
}
while ( V_255 <= ( V_293 -> V_298 - 1 ) ) {
V_77 = F_84 ( V_30 , V_217 ,
V_1 , V_23 ) ;
if ( V_77 < 0 )
return V_77 ;
V_255 = V_255 + V_77 ;
V_217 ++ ;
}
V_295 += V_255 * sizeof( * V_217 ) ;
}
return 0 ;
}
static int F_87 ( struct V_197 * V_30 ,
struct V_292 * V_293 )
{
struct V_216 * V_217 ;
V_217 = V_293 -> V_221 ;
switch ( V_217 -> V_235 ) {
case V_299 :
case V_300 :
case V_301 :
return V_217 -> V_221 ;
default:
F_5 ( V_30 , L_30 , V_217 -> V_235 ) ;
break;
}
return - V_97 ;
}
static int F_88 ( struct V_302 * V_303 ,
struct V_1 * V_1 , struct V_197 * V_30 ,
struct V_22 * V_23 )
{
struct V_292 * V_293 ;
int V_304 , V_291 = 0 , V_305 , V_294 = 0 ;
char * V_187 ;
int V_77 ;
V_293 = (struct V_292 * ) V_303 -> V_85 . V_187 ;
V_77 = F_87 ( V_30 , V_293 ) ;
if ( V_77 < 0 )
return V_77 ;
V_304 = V_77 ;
V_294 += V_293 -> V_99 ;
V_293 = (struct V_292 * ) ( V_303 -> V_85 . V_187 + V_294 ) ;
while ( V_304 > 0 ) {
V_77 = F_87 ( V_30 , V_293 ) ;
if ( V_77 < 0 )
return V_77 ;
V_305 = V_77 ;
V_294 += V_293 -> V_99 ;
V_293 = (struct V_292 * )
( V_303 -> V_85 . V_187 + V_294 ) ;
V_77 = F_87 ( V_30 , V_293 ) ;
if ( V_77 < 0 )
return V_77 ;
V_291 = V_77 ;
V_294 += V_293 -> V_99 ;
V_293 = (struct V_292 * )
( V_303 -> V_85 . V_187 + V_294 ) ;
V_187 = ( V_303 -> V_85 . V_187 + V_294 ) ;
if ( V_305 == V_306 ) {
V_77 = F_85 ( V_30 , V_187 ,
V_1 , V_23 , V_291 ) ;
if ( V_77 < 0 )
return V_77 ;
-- V_304 ;
} else {
if ( V_23 -> V_90 . V_91 > 0 )
memcpy ( V_23 -> V_90 . V_3 , V_187 ,
V_23 -> V_90 . V_91 ) ;
-- V_304 ;
}
}
return 0 ;
}
static void F_89 ( struct V_307 * V_308 ,
struct V_13 * V_14 )
{
int V_48 ;
struct V_22 * V_23 ;
struct V_125 * V_27 ;
if ( ! strncmp ( V_14 -> V_181 -> V_309 -> V_104 , V_308 -> V_309 . V_104 ,
strlen ( V_308 -> V_309 . V_104 ) ) ) {
V_23 = V_14 -> V_85 ;
V_27 = V_23 -> V_27 ;
for ( V_48 = 0 ; V_48 < V_23 -> V_158 ; V_48 ++ ) {
V_23 -> V_159 [ V_48 ] . V_236 = false ;
V_23 -> V_159 [ V_48 ] . V_156 = V_237 ;
}
for ( V_48 = 0 ; V_48 < V_23 -> V_154 ; V_48 ++ ) {
V_23 -> V_155 [ V_48 ] . V_236 = false ;
V_23 -> V_155 [ V_48 ] . V_156 = V_237 ;
}
V_27 -> V_171 = V_176 ;
V_23 -> V_137 = V_141 ;
}
}
void F_90 ( struct V_1 * V_1 )
{
struct V_6 * V_24 = V_1 -> V_6 ;
struct V_307 * V_310 = V_1 -> V_308 ;
struct V_13 * V_14 ;
struct V_311 * V_312 ;
if ( V_310 == NULL )
return;
V_312 = V_310 -> V_309 . V_312 ;
if ( ! V_312 || ! V_312 -> V_313 )
return;
V_1 -> V_25 . V_26 = 0 ;
V_1 -> V_25 . V_34 = 0 ;
F_30 (w, &card->widgets, list) {
if ( F_3 ( V_14 ) && ( V_14 -> V_85 != NULL ) )
F_89 ( V_310 , V_14 ) ;
}
F_91 ( V_24 -> V_134 ) ;
}
static int F_92 ( struct V_314 * V_315 ,
struct V_13 * V_14 ,
struct V_302 * V_303 )
{
int V_77 ;
struct V_316 * V_317 = F_93 ( V_315 ) ;
struct V_1 * V_1 = F_94 ( V_317 ) ;
struct V_318 * V_319 = F_95 ( V_317 ) ;
struct V_22 * V_23 ;
if ( ! V_303 -> V_85 . V_99 )
goto V_320;
V_23 = F_76 ( V_319 -> V_30 , sizeof( * V_23 ) , V_223 ) ;
if ( ! V_23 )
return - V_132 ;
V_14 -> V_85 = V_23 ;
V_23 -> V_15 . V_32 = - 1 ;
V_77 = F_88 ( V_303 , V_1 , V_319 -> V_30 , V_23 ) ;
if ( V_77 < 0 )
return V_77 ;
V_320:
if ( V_303 -> V_321 == 0 ) {
F_12 ( V_319 -> V_30 , L_31 ) ;
return 0 ;
}
V_77 = F_96 ( V_14 , V_322 ,
F_97 ( V_322 ) ,
V_303 -> V_321 ) ;
if ( V_77 ) {
F_5 ( V_319 -> V_30 , L_32 ,
V_31 , V_303 -> V_321 ) ;
return - V_97 ;
}
return 0 ;
}
static int F_98 ( struct V_197 * V_30 , struct V_108 * V_323 ,
struct V_324 * V_111 )
{
struct V_110 * V_190 ;
struct V_325 * V_326 =
(struct V_325 * ) V_111 -> V_85 . V_187 ;
V_190 = F_76 ( V_30 , sizeof( * V_190 ) , V_223 ) ;
if ( ! V_190 )
return - V_132 ;
V_190 -> V_162 = V_326 -> V_162 ;
V_190 -> V_116 = V_326 -> V_116 ;
V_190 -> V_114 = V_326 -> V_114 ;
V_190 -> V_99 = V_326 -> V_162 ;
if ( V_190 -> V_162 ) {
V_190 -> V_51 = ( char * ) F_76 ( V_30 , V_190 -> V_162 , V_223 ) ;
if ( ! V_190 -> V_51 )
return - V_132 ;
memcpy ( V_190 -> V_51 , V_326 -> V_51 , V_190 -> V_162 ) ;
}
V_323 -> V_122 . V_123 = V_190 ;
return 0 ;
}
static int F_99 ( struct V_314 * V_315 ,
struct V_106 * V_327 ,
struct V_328 * V_329 )
{
struct V_108 * V_109 ;
struct V_324 * V_330 ;
struct V_316 * V_317 = F_93 ( V_315 ) ;
struct V_318 * V_319 = F_95 ( V_317 ) ;
switch ( V_329 -> V_331 . V_332 ) {
case V_333 :
V_330 = F_100 ( V_329 ,
struct V_324 , V_329 ) ;
if ( V_327 -> V_119 & V_120 ) {
V_109 = (struct V_108 * ) V_327 -> V_121 ;
if ( V_330 -> V_85 . V_99 )
return F_98 (
V_319 -> V_30 , V_109 , V_330 ) ;
}
break;
default:
F_86 ( V_319 -> V_30 , L_33 ,
V_329 -> V_331 . V_334 , V_329 -> V_331 . V_335 , V_329 -> V_331 . V_332 ) ;
break;
}
return 0 ;
}
static int F_101 ( struct V_197 * V_30 ,
struct V_336 * V_337 ,
struct V_1 * V_1 )
{
int V_255 = 0 ;
static int V_338 ;
switch ( V_337 -> V_235 ) {
case V_339 :
if ( V_338 > V_1 -> V_6 -> V_340 - 1 ) {
V_338 = 0 ;
return - V_97 ;
}
strncpy ( V_1 -> V_6 -> V_341 [ V_338 ] . V_104 ,
V_337 -> string ,
F_97 ( V_1 -> V_6 -> V_341 [ V_338 ] . V_104 ) ) ;
V_338 ++ ;
V_255 ++ ;
break;
default:
F_5 ( V_30 , L_34 , V_337 -> V_235 ) ;
break;
}
return V_255 ;
}
static int F_102 ( struct V_197 * V_30 ,
struct V_292 * V_293 ,
struct V_1 * V_1 )
{
int V_255 = 0 , V_77 ;
struct V_336 * V_337 ;
V_337 = (struct V_336 * ) V_293 -> V_221 ;
while ( V_255 < V_293 -> V_298 ) {
V_77 = F_101 ( V_30 , V_337 , V_1 ) ;
V_337 ++ ;
if ( V_77 < 0 )
return V_77 ;
V_255 = V_255 + V_77 ;
}
return V_255 ;
}
static int F_103 ( struct V_197 * V_30 ,
struct V_216 * V_217 ,
struct V_1 * V_1 )
{
int V_255 = 0 ;
switch ( V_217 -> V_235 ) {
case V_342 :
V_1 -> V_6 -> V_340 = V_217 -> V_221 ;
V_255 ++ ;
break;
default:
F_5 ( V_30 , L_35 , V_217 -> V_235 ) ;
return - V_97 ;
}
return V_255 ;
}
static int F_104 ( struct V_197 * V_30 ,
char * V_290 , struct V_1 * V_1 ,
int V_291 )
{
int V_255 = 0 , V_77 ;
int V_294 = 0 , V_295 = 0 ;
struct V_292 * V_293 ;
struct V_216 * V_217 ;
if ( V_291 <= 0 )
return - V_97 ;
while ( V_295 < V_291 ) {
V_293 = (struct V_292 * ) ( V_290 + V_294 ) ;
V_294 += V_293 -> V_99 ;
switch ( V_293 -> type ) {
case V_296 :
V_77 = F_102 ( V_30 , V_293 , V_1 ) ;
if ( V_77 < 0 )
return V_77 ;
V_255 += V_77 ;
V_295 += V_255 *
sizeof( struct V_336 ) ;
continue;
case V_297 :
F_86 ( V_30 , L_36 ) ;
continue;
default:
V_217 = V_293 -> V_221 ;
V_255 = 0 ;
break;
}
while ( V_255 <= V_293 -> V_298 - 1 ) {
V_77 = F_103 ( V_30 ,
V_217 , V_1 ) ;
if ( V_77 < 0 )
return V_77 ;
V_255 = V_255 + V_77 ;
V_217 ++ ;
V_295 += V_255 *
sizeof( struct V_216 ) ;
break;
}
V_255 = 0 ;
}
return 0 ;
}
static int F_105 ( struct V_343 * V_344 ,
struct V_197 * V_30 , struct V_1 * V_1 )
{
struct V_292 * V_293 ;
int V_304 , V_291 = 0 , V_305 , V_294 = 0 ;
char * V_187 ;
int V_77 ;
V_293 = (struct V_292 * ) V_344 -> V_85 . V_187 ;
V_77 = F_87 ( V_30 , V_293 ) ;
if ( V_77 < 0 )
return V_77 ;
V_304 = V_77 ;
V_294 += V_293 -> V_99 ;
V_293 = (struct V_292 * )
( V_344 -> V_85 . V_187 + V_294 ) ;
while ( V_304 > 0 ) {
V_77 = F_87 ( V_30 , V_293 ) ;
if ( V_77 < 0 )
return V_77 ;
V_305 = V_77 ;
V_294 += V_293 -> V_99 ;
V_293 = (struct V_292 * )
( V_344 -> V_85 . V_187 + V_294 ) ;
V_77 = F_87 ( V_30 , V_293 ) ;
if ( V_77 < 0 )
return V_77 ;
V_291 = V_77 ;
V_294 += V_293 -> V_99 ;
V_293 = (struct V_292 * )
( V_344 -> V_85 . V_187 + V_294 ) ;
V_187 = ( V_344 -> V_85 . V_187 + V_294 ) ;
if ( V_305 == V_306 ) {
V_77 = F_104 ( V_30 , V_187 , V_1 ,
V_291 ) ;
if ( V_77 < 0 )
return V_77 ;
-- V_304 ;
} else {
return - V_97 ;
}
}
return 0 ;
}
static int F_106 ( struct V_314 * V_315 ,
struct V_343 * V_344 )
{
struct V_316 * V_317 = F_93 ( V_315 ) ;
struct V_318 * V_319 = F_95 ( V_317 ) ;
struct V_1 * V_1 = F_94 ( V_317 ) ;
if ( V_344 -> V_85 . V_99 == 0 )
return 0 ;
F_105 ( V_344 , V_319 -> V_30 , V_1 ) ;
if ( V_1 -> V_6 -> V_340 > V_345 ) {
F_5 ( V_319 -> V_30 , L_37 ,
V_1 -> V_6 -> V_340 ) ;
return - V_97 ;
}
return 0 ;
}
static int F_107 ( struct V_307 * V_308 )
{
struct V_13 * V_14 ;
struct V_22 * V_36 = NULL ;
struct V_128 * V_346 = NULL ;
struct V_125 * V_27 ;
F_30 (w, &platform->component.card->widgets, list) {
if ( F_3 ( V_14 ) && V_14 -> V_85 != NULL ) {
V_36 = V_14 -> V_85 ;
V_27 = V_36 -> V_27 ;
V_346 = F_76 ( V_308 -> V_30 ,
sizeof( * V_346 ) , V_223 ) ;
if ( ! V_346 )
return - V_132 ;
V_346 -> V_14 = V_14 ;
F_108 ( & V_346 -> V_225 , & V_27 -> V_224 ) ;
}
}
return 0 ;
}
static void F_109 ( struct V_1 * V_1 , struct V_125 * V_27 )
{
struct V_128 * V_129 ;
struct V_13 * V_14 ;
struct V_22 * V_23 ;
bool V_347 = false , V_348 = false ;
F_30 (w_module, &pipe->w_list, node) {
V_14 = V_129 -> V_14 ;
V_23 = V_14 -> V_85 ;
if ( V_23 -> V_76 == V_126 )
V_347 = true ;
else if ( V_23 -> V_76 != V_349 )
V_348 = true ;
}
if ( V_347 && V_348 )
V_27 -> V_192 = true ;
else
V_27 -> V_192 = false ;
}
int F_110 ( struct V_307 * V_308 , struct V_316 * V_317 )
{
int V_77 ;
const struct V_350 * V_351 ;
struct V_318 * V_319 = F_95 ( V_317 ) ;
struct V_1 * V_1 = F_94 ( V_317 ) ;
struct V_218 * V_219 ;
V_77 = F_111 ( & V_351 , V_1 -> V_352 , V_319 -> V_30 ) ;
if ( V_77 < 0 ) {
F_5 ( V_319 -> V_30 , L_38 ,
V_1 -> V_352 , V_77 ) ;
V_77 = F_111 ( & V_351 , L_39 , V_319 -> V_30 ) ;
if ( V_77 < 0 ) {
F_5 ( V_319 -> V_30 , L_40 ,
L_39 , V_77 ) ;
return V_77 ;
}
}
V_77 = F_112 ( & V_308 -> V_309 ,
& V_353 , V_351 , 0 ) ;
if ( V_77 < 0 ) {
F_5 ( V_319 -> V_30 , L_41 , V_77 ) ;
F_113 ( V_351 ) ;
return - V_97 ;
}
V_1 -> V_25 . V_35 = V_354 ;
V_1 -> V_25 . V_29 = V_355 ;
V_1 -> V_356 = V_351 ;
V_77 = F_107 ( V_308 ) ;
if ( V_77 < 0 )
return V_77 ;
F_30 (ppl, &skl->ppl_list, node)
F_109 ( V_1 , V_219 -> V_27 ) ;
return 0 ;
}
