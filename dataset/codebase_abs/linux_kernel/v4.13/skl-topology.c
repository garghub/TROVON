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
V_37 = & V_36 -> V_37 [ 0 ] ;
V_42 = & V_36 -> V_42 [ 0 ] ;
if ( V_36 -> V_70 == V_71 )
V_69 = 5 ;
V_36 -> V_72 = F_18 ( V_37 -> V_39 , 1000 ) *
V_37 -> V_38 * ( V_37 -> V_59 >> 3 ) *
V_69 ;
V_36 -> V_73 = F_18 ( V_42 -> V_39 , 1000 ) *
V_42 -> V_38 * ( V_42 -> V_59 >> 3 ) *
V_69 ;
}
static T_1 F_19 ( int V_74 )
{
int V_75 ;
switch ( V_74 ) {
case V_76 :
V_75 = V_77 ;
break;
case V_78 :
V_75 = V_79 ;
break;
case V_80 :
V_75 = V_81 ;
break;
default:
V_75 = V_82 ;
break;
}
return V_75 ;
}
static int F_20 ( struct V_13 * V_14 ,
struct V_6 * V_24 )
{
struct V_22 * V_61 = V_14 -> V_83 ;
int V_84 , V_85 ;
T_2 V_55 , V_39 , V_57 ;
struct V_86 * V_87 ;
struct V_1 * V_1 = F_21 ( V_24 -> V_30 ) ;
T_1 V_74 = F_19 ( V_61 -> V_74 ) ;
if ( V_61 -> V_88 . V_89 > 0 )
return 0 ;
F_12 ( V_24 -> V_30 , L_11 ) ;
switch ( V_61 -> V_74 ) {
case V_78 :
V_84 = V_90 ;
V_85 = V_91 ;
V_39 = V_61 -> V_37 [ 0 ] . V_39 ;
V_57 = V_61 -> V_37 [ 0 ] . V_59 ;
V_55 = V_61 -> V_37 [ 0 ] . V_38 ;
break;
case V_80 :
V_84 = V_92 ;
if ( V_61 -> V_93 == V_94 ) {
V_85 = V_66 ;
V_39 = V_61 -> V_42 [ 0 ] . V_39 ;
V_57 = V_61 -> V_42 [ 0 ] . V_59 ;
V_55 = V_61 -> V_42 [ 0 ] . V_38 ;
} else {
V_85 = V_91 ;
V_39 = V_61 -> V_37 [ 0 ] . V_39 ;
V_57 = V_61 -> V_37 [ 0 ] . V_59 ;
V_55 = V_61 -> V_37 [ 0 ] . V_38 ;
}
break;
default:
return - V_95 ;
}
V_87 = F_22 ( V_1 , V_61 -> V_96 , V_84 ,
V_57 , V_55 , V_39 , V_85 , V_74 ) ;
if ( V_87 ) {
V_61 -> V_88 . V_89 = V_87 -> V_97 ;
V_61 -> V_88 . V_3 = ( T_2 * ) & V_87 -> V_3 ;
} else {
F_5 ( V_24 -> V_30 , L_12 ,
V_61 -> V_96 , V_84 , V_85 ) ;
F_5 ( V_24 -> V_30 , L_13 ,
V_55 , V_39 , V_57 ) ;
return - V_98 ;
}
return 0 ;
}
static void F_23 ( struct V_13 * V_14 ,
struct V_6 * V_24 )
{
struct V_22 * V_61 = V_14 -> V_83 ;
struct V_50 * V_51 = V_61 -> V_27 -> V_99 ;
int V_100 = V_61 -> V_27 -> V_101 ;
bool V_62 ;
if ( ! V_61 -> V_67 )
return;
F_12 ( V_24 -> V_30 , L_14 ,
V_14 -> V_102 ) ;
F_11 ( V_24 , V_61 ) ;
if ( V_100 == V_103 )
V_62 = true ;
else
V_62 = false ;
F_16 ( V_61 , V_51 , V_62 ) ;
F_17 ( V_24 , V_61 ) ;
F_12 ( V_24 -> V_30 , L_15 ,
V_14 -> V_102 ) ;
F_11 ( V_24 , V_61 ) ;
}
static int F_24 ( struct V_13 * V_14 ,
struct V_6 * V_24 )
{
int V_48 , V_75 ;
struct V_22 * V_23 = V_14 -> V_83 ;
const struct V_104 * V_105 ;
struct V_106 * V_107 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
if ( V_23 -> V_88 . V_89 > 0 &&
V_23 -> V_88 . V_112 == V_113 ) {
V_111 = & V_23 -> V_88 ;
V_75 = F_25 ( V_24 , V_111 -> V_3 ,
V_111 -> V_89 ,
V_111 -> V_114 , V_23 ) ;
if ( V_75 < 0 )
return V_75 ;
}
for ( V_48 = 0 ; V_48 < V_14 -> V_115 ; V_48 ++ ) {
V_105 = & V_14 -> V_116 [ V_48 ] ;
if ( V_105 -> V_117 & V_118 ) {
V_107 = ( void * ) V_105 -> V_119 ;
V_109 = (struct V_108 * ) V_107 -> V_120 . V_121 ;
if ( V_109 -> V_112 == V_113 ) {
V_75 = F_25 ( V_24 ,
( T_2 * ) V_109 -> V_51 , V_109 -> V_97 ,
V_109 -> V_114 , V_23 ) ;
if ( V_75 < 0 )
return V_75 ;
}
}
}
return 0 ;
}
static int F_26 ( struct V_13 * V_14 )
{
const struct V_104 * V_105 ;
struct V_106 * V_107 ;
struct V_108 * V_109 ;
struct V_22 * V_23 = V_14 -> V_83 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_14 -> V_115 ; V_48 ++ ) {
V_105 = & V_14 -> V_116 [ V_48 ] ;
if ( V_105 -> V_117 & V_118 ) {
V_107 = (struct V_106 * ) V_105 -> V_119 ;
V_109 = (struct V_108 * ) V_107 -> V_120 . V_121 ;
if ( V_109 -> V_112 != V_122 )
continue;
V_23 -> V_88 . V_3 = ( T_2 * ) V_109 -> V_51 ;
V_23 -> V_88 . V_89 = V_109 -> V_97 ;
break;
}
}
return 0 ;
}
static int F_27 ( struct V_6 * V_24 , struct V_123 * V_27 ,
struct V_13 * V_14 , struct V_22 * V_36 )
{
switch ( V_36 -> V_74 ) {
case V_124 :
return F_28 ( V_24 -> V_30 , V_27 -> V_99 ) ;
case V_125 :
return F_29 ( V_24 -> V_30 , V_27 -> V_99 ) ;
}
return 0 ;
}
static int
F_30 ( struct V_1 * V_1 , struct V_123 * V_27 )
{
struct V_126 * V_127 ;
struct V_13 * V_14 ;
struct V_22 * V_23 ;
struct V_6 * V_24 = V_1 -> V_6 ;
int V_75 = 0 ;
F_31 (w_module, &pipe->w_list, node) {
T_3 * V_128 ;
V_14 = V_127 -> V_14 ;
V_23 = V_14 -> V_83 ;
if ( V_23 -> V_15 . V_32 < 0 ) {
F_5 ( V_1 -> V_6 -> V_30 ,
L_16 ,
( T_3 * ) V_23 -> V_129 ) ;
return - V_98 ;
}
if ( ! F_7 ( V_1 , V_23 ) )
return - V_130 ;
if ( V_23 -> V_131 && V_24 -> V_132 -> V_133 . V_134 ) {
V_75 = V_24 -> V_132 -> V_133 . V_134 ( V_24 -> V_132 ,
V_23 -> V_15 . V_32 , V_23 -> V_129 ) ;
if ( V_75 < 0 )
return V_75 ;
V_23 -> V_135 = V_136 ;
}
V_75 = F_27 ( V_24 , V_27 , V_14 , V_23 ) ;
if ( V_75 < 0 )
return V_75 ;
F_20 ( V_14 , V_24 ) ;
F_23 ( V_14 , V_24 ) ;
V_128 = ( T_3 * ) V_23 -> V_129 ;
V_23 -> V_15 . V_137 = F_32 ( V_24 , V_128 ,
V_23 -> V_15 . V_33 ) ;
if ( V_23 -> V_15 . V_137 < 0 )
return V_75 ;
F_26 ( V_14 ) ;
V_75 = F_33 ( V_24 , V_23 ) ;
if ( V_75 < 0 ) {
F_34 ( V_24 , V_128 , & V_23 -> V_15 . V_137 ) ;
return V_75 ;
}
F_8 ( V_1 , V_23 ) ;
V_75 = F_24 ( V_14 , V_24 ) ;
if ( V_75 < 0 )
return V_75 ;
}
return 0 ;
}
static int F_35 ( struct V_6 * V_24 ,
struct V_123 * V_27 )
{
int V_75 ;
struct V_126 * V_127 = NULL ;
struct V_22 * V_23 = NULL ;
F_31 (w_module, &pipe->w_list, node) {
T_3 * V_128 ;
V_23 = V_127 -> V_14 -> V_83 ;
V_128 = ( T_3 * ) V_23 -> V_129 ;
if ( V_23 -> V_131 && V_24 -> V_132 -> V_133 . V_138 &&
V_23 -> V_135 > V_139 ) {
V_75 = V_24 -> V_132 -> V_133 . V_138 ( V_24 -> V_132 ,
V_23 -> V_15 . V_32 ) ;
if ( V_75 < 0 )
return - V_98 ;
}
F_34 ( V_24 , V_128 , & V_23 -> V_15 . V_137 ) ;
}
return 0 ;
}
static int F_36 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
int V_75 ;
struct V_22 * V_23 = V_14 -> V_83 ;
struct V_126 * V_127 ;
struct V_123 * V_140 = V_23 -> V_27 ;
struct V_22 * V_141 = NULL , * V_142 , * V_143 ;
struct V_6 * V_24 = V_1 -> V_6 ;
struct V_144 * V_145 ;
if ( ! F_7 ( V_1 , V_23 ) )
return - V_146 ;
if ( ! F_4 ( V_1 , V_23 ) )
return - V_130 ;
V_75 = F_37 ( V_24 , V_23 -> V_27 ) ;
if ( V_75 < 0 )
return V_75 ;
F_6 ( V_1 , V_23 ) ;
F_8 ( V_1 , V_23 ) ;
V_75 = F_30 ( V_1 , V_140 ) ;
if ( V_75 < 0 )
return V_75 ;
F_31 (w_module, &s_pipe->w_list, node) {
V_142 = V_127 -> V_14 -> V_83 ;
if ( V_141 == NULL ) {
V_141 = V_142 ;
continue;
}
V_75 = F_38 ( V_24 , V_141 , V_142 ) ;
if ( V_75 < 0 )
return V_75 ;
V_141 = V_142 ;
}
F_31 (w_module, &s_pipe->w_list, node) {
if ( F_39 ( & V_1 -> V_147 ) )
break;
F_31 (modules, &skl->bind_list, node) {
V_143 = V_127 -> V_14 -> V_83 ;
if ( V_145 -> V_148 == V_143 )
F_38 ( V_24 , V_145 -> V_149 ,
V_145 -> V_148 ) ;
}
}
return 0 ;
}
static int F_40 ( struct V_6 * V_24 , T_2 * V_51 ,
int V_97 , struct V_22 * V_36 )
{
int V_48 , V_137 ;
if ( V_36 -> V_70 == V_150 ) {
struct V_151 * V_152 =
(struct V_151 * ) V_51 ;
struct V_153 * V_154 = V_152 -> V_155 ;
for ( V_48 = 0 ; V_48 < V_152 -> V_156 ; V_48 ++ ) {
V_137 = F_41 ( V_24 , V_154 -> V_157 ,
V_154 -> V_158 ) ;
if ( V_137 < 0 )
return - V_95 ;
V_154 -> V_158 = V_137 ;
V_154 ++ ;
}
}
return 0 ;
}
static int F_42 ( struct V_13 * V_14 ,
struct V_22 * V_36 , struct V_6 * V_24 )
{
int V_48 , V_75 ;
struct V_22 * V_23 = V_14 -> V_83 ;
const struct V_104 * V_105 ;
struct V_106 * V_107 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
T_2 * V_51 ;
for ( V_48 = 0 ; V_48 < V_36 -> V_159 ; V_48 ++ ) {
if ( V_36 -> V_160 [ V_48 ] . V_161 != V_162 )
return 0 ;
}
for ( V_48 = 0 ; V_48 < V_36 -> V_163 ; V_48 ++ ) {
if ( V_36 -> V_164 [ V_48 ] . V_161 != V_162 )
return 0 ;
}
if ( V_23 -> V_88 . V_89 > 0 &&
V_23 -> V_88 . V_112 == V_165 ) {
V_111 = & V_23 -> V_88 ;
V_75 = F_25 ( V_24 , V_111 -> V_3 ,
V_111 -> V_89 ,
V_111 -> V_114 , V_23 ) ;
if ( V_75 < 0 )
return V_75 ;
}
for ( V_48 = 0 ; V_48 < V_14 -> V_115 ; V_48 ++ ) {
V_105 = & V_14 -> V_116 [ V_48 ] ;
if ( V_105 -> V_117 & V_118 ) {
V_107 = ( void * ) V_105 -> V_119 ;
V_109 = (struct V_108 * ) V_107 -> V_120 . V_121 ;
if ( V_109 -> V_112 == V_165 ) {
V_51 = F_43 ( V_109 -> V_166 , V_167 ) ;
if ( ! V_51 )
return - V_130 ;
memcpy ( V_51 , V_109 -> V_51 , V_109 -> V_166 ) ;
F_40 ( V_24 , V_51 , V_109 -> V_166 ,
V_23 ) ;
V_75 = F_25 ( V_24 , V_51 ,
V_109 -> V_166 , V_109 -> V_114 , V_23 ) ;
F_44 ( V_51 ) ;
if ( V_75 < 0 )
return V_75 ;
}
}
}
return 0 ;
}
static int F_45 ( struct V_1 * V_1 ,
struct V_22 * V_149 , struct V_22 * V_148 )
{
struct V_144 * V_168 , * V_145 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_148 -> V_163 ; V_48 ++ ) {
struct V_169 * V_170 = & V_148 -> V_164 [ V_48 ] ;
if ( V_170 -> V_171 )
continue;
if ( ( V_170 -> V_15 . V_32 == V_149 -> V_15 . V_32 ) &&
( V_170 -> V_15 . V_33 == V_149 -> V_15 . V_33 ) ) {
if ( ! F_39 ( & V_1 -> V_147 ) ) {
F_31 (modules, &skl->bind_list, node) {
if ( V_145 -> V_149 == V_149 && V_145 -> V_148 == V_148 )
return 0 ;
}
}
V_168 = F_43 ( sizeof( * V_168 ) , V_167 ) ;
if ( ! V_168 )
return - V_130 ;
V_168 -> V_149 = V_149 ;
V_168 -> V_148 = V_148 ;
F_46 ( & V_168 -> V_172 , & V_1 -> V_147 ) ;
}
}
return 0 ;
}
static int F_47 ( struct V_13 * V_14 ,
struct V_1 * V_1 ,
struct V_13 * V_173 ,
struct V_22 * V_174 )
{
struct V_175 * V_176 ;
struct V_13 * V_177 = NULL , * V_178 = NULL ;
struct V_22 * V_179 ;
struct V_6 * V_24 = V_1 -> V_6 ;
int V_75 ;
F_48 (w, p) {
if ( ! V_176 -> V_180 )
continue;
F_12 ( V_24 -> V_30 , L_17 , V_31 , V_14 -> V_102 ) ;
F_12 ( V_24 -> V_30 , L_18 , V_31 , V_176 -> V_177 -> V_102 ) ;
V_178 = V_176 -> V_177 ;
if ( ! F_3 ( V_176 -> V_177 ) )
return F_47 ( V_176 -> V_177 , V_1 , V_173 , V_174 ) ;
if ( ( V_176 -> V_177 -> V_83 != NULL ) &&
F_3 ( V_176 -> V_177 ) ) {
V_177 = V_176 -> V_177 ;
V_179 = V_177 -> V_83 ;
if ( ( ( V_174 -> V_135 == V_181 )
&& ( V_179 -> V_135 == V_139 ) ) ) {
V_75 = F_45 ( V_1 ,
V_174 , V_179 ) ;
if ( V_75 < 0 )
return V_75 ;
}
if ( V_174 -> V_135 == V_139 ||
V_179 -> V_135 == V_139 )
continue;
V_75 = F_38 ( V_24 , V_174 , V_179 ) ;
if ( V_75 )
return V_75 ;
F_42 ( V_173 , V_174 , V_24 ) ;
F_42 ( V_177 , V_179 , V_24 ) ;
if ( V_179 -> V_27 -> V_182 != V_183 ) {
if ( V_179 -> V_27 -> V_101 !=
V_103 )
V_75 = F_49 ( V_24 ,
V_179 -> V_27 ) ;
if ( V_75 )
return V_75 ;
}
}
}
if ( ! V_177 )
return F_47 ( V_178 , V_1 , V_173 , V_174 ) ;
return 0 ;
}
static int F_50 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
struct V_22 * V_174 ;
struct V_6 * V_24 = V_1 -> V_6 ;
int V_75 = 0 ;
V_174 = V_14 -> V_83 ;
V_75 = F_47 ( V_14 , V_1 , V_14 , V_174 ) ;
if ( V_75 )
return V_75 ;
if ( V_174 -> V_27 -> V_101 != V_103 )
return F_49 ( V_24 , V_174 -> V_27 ) ;
return 0 ;
}
static struct V_13 * F_51 (
struct V_13 * V_14 , struct V_1 * V_1 )
{
struct V_175 * V_176 ;
struct V_13 * V_173 = NULL ;
struct V_6 * V_24 = V_1 -> V_6 ;
F_52 (w, p) {
V_173 = V_176 -> V_184 ;
if ( ! V_176 -> V_180 )
continue;
F_12 ( V_24 -> V_30 , L_19 , V_14 -> V_102 ) ;
F_12 ( V_24 -> V_30 , L_20 , V_176 -> V_184 -> V_102 ) ;
if ( ( V_176 -> V_184 -> V_83 != NULL ) &&
F_3 ( V_176 -> V_184 ) ) {
return V_176 -> V_184 ;
}
}
if ( V_173 != NULL )
return F_51 ( V_173 , V_1 ) ;
return NULL ;
}
static int F_53 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
int V_75 = 0 ;
struct V_13 * V_184 , * V_177 ;
struct V_22 * V_174 , * V_179 ;
struct V_6 * V_24 = V_1 -> V_6 ;
int V_185 = 0 ;
V_177 = V_14 ;
V_179 = V_177 -> V_83 ;
V_184 = F_51 ( V_14 , V_1 ) ;
if ( V_184 != NULL ) {
V_174 = V_184 -> V_83 ;
V_179 = V_177 -> V_83 ;
V_185 = 1 ;
if ( V_174 -> V_27 -> V_182 != V_183 )
V_185 = 0 ;
}
if ( V_185 ) {
V_75 = F_38 ( V_24 , V_174 , V_179 ) ;
if ( V_75 )
return V_75 ;
F_42 ( V_184 , V_174 , V_24 ) ;
F_42 ( V_177 , V_179 , V_24 ) ;
if ( V_179 -> V_27 -> V_101 != V_103 )
V_75 = F_49 ( V_24 , V_179 -> V_27 ) ;
}
return V_75 ;
}
static int F_54 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
struct V_22 * V_174 , * V_179 ;
int V_75 = 0 , V_48 ;
struct V_6 * V_24 = V_1 -> V_6 ;
V_179 = V_14 -> V_83 ;
V_75 = F_55 ( V_24 , V_179 -> V_27 ) ;
if ( V_75 )
return V_75 ;
for ( V_48 = 0 ; V_48 < V_179 -> V_163 ; V_48 ++ ) {
if ( V_179 -> V_164 [ V_48 ] . V_161 == V_162 ) {
V_174 = V_179 -> V_164 [ V_48 ] . V_186 ;
if ( ! V_174 )
continue;
V_75 = F_56 ( V_24 ,
V_174 , V_179 ) ;
}
}
return V_75 ;
}
static int F_57 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
struct V_22 * V_23 = V_14 -> V_83 ;
struct V_126 * V_127 ;
struct V_22 * V_141 = NULL , * V_142 ;
struct V_6 * V_24 = V_1 -> V_6 ;
struct V_123 * V_140 = V_23 -> V_27 ;
struct V_144 * V_145 , * V_187 ;
if ( V_140 -> V_182 == V_188 )
return - V_95 ;
F_9 ( V_1 , V_23 ) ;
F_10 ( V_1 , V_23 ) ;
F_31 (w_module, &s_pipe->w_list, node) {
if ( F_39 ( & V_1 -> V_147 ) )
break;
V_141 = V_127 -> V_14 -> V_83 ;
F_58 (modules, tmp, &skl->bind_list, node) {
if ( V_145 -> V_148 == V_141 ) {
F_56 ( V_24 , V_145 -> V_149 ,
V_145 -> V_148 ) ;
}
if ( V_145 -> V_149 == V_141 ) {
F_59 ( & V_145 -> V_172 ) ;
V_145 -> V_149 = NULL ;
V_145 -> V_148 = NULL ;
F_44 ( V_145 ) ;
}
}
}
F_31 (w_module, &s_pipe->w_list, node) {
V_142 = V_127 -> V_14 -> V_83 ;
if ( V_23 -> V_135 >= V_181 )
F_9 ( V_1 , V_142 ) ;
if ( V_141 == NULL ) {
V_141 = V_142 ;
continue;
}
F_56 ( V_24 , V_141 , V_142 ) ;
V_141 = V_142 ;
}
F_60 ( V_24 , V_23 -> V_27 ) ;
F_31 (w_module, &s_pipe->w_list, node) {
V_141 = V_127 -> V_14 -> V_83 ;
V_141 -> V_135 = V_139 ;
}
return F_35 ( V_24 , V_140 ) ;
}
static int F_61 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
struct V_22 * V_174 , * V_179 ;
int V_75 = 0 , V_48 ;
struct V_6 * V_24 = V_1 -> V_6 ;
V_174 = V_14 -> V_83 ;
V_75 = F_55 ( V_24 , V_174 -> V_27 ) ;
if ( V_75 )
return V_75 ;
for ( V_48 = 0 ; V_48 < V_174 -> V_159 ; V_48 ++ ) {
if ( V_174 -> V_160 [ V_48 ] . V_161 == V_162 ) {
V_179 = V_174 -> V_160 [ V_48 ] . V_186 ;
if ( ! V_179 )
continue;
V_75 = F_56 ( V_24 , V_174 ,
V_179 ) ;
}
}
return V_75 ;
}
static int F_62 ( struct V_13 * V_14 ,
struct V_189 * V_105 , int V_190 )
{
struct V_191 * V_192 = V_14 -> V_192 ;
struct V_1 * V_1 = F_21 ( V_192 -> V_30 ) ;
switch ( V_190 ) {
case V_193 :
return F_36 ( V_14 , V_1 ) ;
case V_194 :
return F_53 ( V_14 , V_1 ) ;
case V_195 :
return F_54 ( V_14 , V_1 ) ;
case V_196 :
return F_57 ( V_14 , V_1 ) ;
}
return 0 ;
}
static int F_63 ( struct V_13 * V_14 ,
struct V_189 * V_105 , int V_190 )
{
struct V_191 * V_192 = V_14 -> V_192 ;
struct V_1 * V_1 = F_21 ( V_192 -> V_30 ) ;
switch ( V_190 ) {
case V_193 :
return F_50 ( V_14 , V_1 ) ;
case V_196 :
return F_61 ( V_14 , V_1 ) ;
}
return 0 ;
}
static int F_64 ( struct V_189 * V_197 ,
unsigned int T_4 * V_198 , unsigned int V_97 )
{
struct V_106 * V_107 =
(struct V_106 * ) V_197 -> V_119 ;
struct V_108 * V_109 = (struct V_108 * ) V_107 -> V_120 . V_121 ;
struct V_13 * V_14 = F_65 ( V_197 ) ;
struct V_22 * V_23 = V_14 -> V_83 ;
struct V_1 * V_1 = F_21 ( V_14 -> V_192 -> V_30 ) ;
if ( V_14 -> V_199 )
F_66 ( V_1 -> V_6 , ( T_2 * ) V_109 -> V_51 ,
V_109 -> V_97 , V_109 -> V_114 , V_23 ) ;
V_97 -= 2 * sizeof( T_2 ) ;
if ( V_97 > V_109 -> V_166 )
V_97 = V_109 -> V_166 ;
if ( V_109 -> V_51 ) {
if ( F_67 ( V_198 , & V_109 -> V_114 , sizeof( T_2 ) ) )
return - V_200 ;
if ( F_67 ( V_198 + 1 , & V_97 , sizeof( T_2 ) ) )
return - V_200 ;
if ( F_67 ( V_198 + 2 , V_109 -> V_51 , V_97 ) )
return - V_200 ;
}
return 0 ;
}
static int F_68 ( struct V_189 * V_197 ,
const unsigned int T_4 * V_198 , unsigned int V_97 )
{
struct V_13 * V_14 = F_65 ( V_197 ) ;
struct V_22 * V_23 = V_14 -> V_83 ;
struct V_106 * V_107 =
(struct V_106 * ) V_197 -> V_119 ;
struct V_108 * V_201 = (struct V_108 * ) V_107 -> V_120 . V_121 ;
struct V_1 * V_1 = F_21 ( V_14 -> V_192 -> V_30 ) ;
if ( V_201 -> V_51 ) {
if ( V_97 > V_201 -> V_166 )
return - V_95 ;
V_201 -> V_97 = V_97 ;
if ( V_201 -> V_114 == V_202 ) {
if ( F_69 ( V_201 -> V_51 , V_198 , V_97 ) )
return - V_200 ;
} else {
if ( F_69 ( V_201 -> V_51 ,
V_198 + 2 , V_97 ) )
return - V_200 ;
}
if ( V_14 -> V_199 )
return F_25 ( V_1 -> V_6 ,
( T_2 * ) V_201 -> V_51 , V_201 -> V_97 ,
V_201 -> V_114 , V_23 ) ;
}
return 0 ;
}
static int F_70 ( struct V_189 * V_197 ,
struct V_203 * V_204 )
{
struct V_13 * V_14 = F_65 ( V_197 ) ;
struct V_22 * V_23 = V_14 -> V_83 ;
struct V_205 * V_206 = (struct V_205 * ) V_197 -> V_119 ;
T_2 V_207 = * ( ( T_2 * ) V_206 -> V_120 . V_121 ) ;
if ( V_23 -> V_208 == V_207 )
V_204 -> V_209 . V_210 . V_211 [ 0 ] =
V_23 -> V_212 ;
else
V_204 -> V_209 . V_210 . V_211 [ 0 ] = 0 ;
return 0 ;
}
static int F_71 ( struct V_22 * V_23 ,
struct V_213 * V_214 , struct V_215 * V_30 )
{
struct V_110 * V_111 = & V_23 -> V_88 ;
V_111 -> V_89 = sizeof( struct V_213 ) ;
V_111 -> V_112 = V_113 ;
V_111 -> V_114 = 0x00 ;
if ( ! V_111 -> V_3 ) {
V_111 -> V_3 = F_72 ( V_30 , V_111 -> V_89 , V_167 ) ;
if ( ! V_111 -> V_3 )
return - V_130 ;
}
V_214 -> V_216 = V_217 ;
V_214 -> V_218 = 0 ;
memcpy ( V_111 -> V_3 , V_214 , V_111 -> V_89 ) ;
return 0 ;
}
static int F_73 ( struct V_189 * V_197 ,
struct V_203 * V_204 )
{
struct V_13 * V_14 = F_65 ( V_197 ) ;
struct V_22 * V_23 = V_14 -> V_83 ;
struct V_213 V_214 = { 0 } ;
struct V_205 * V_206 = (struct V_205 * ) V_197 -> V_119 ;
T_2 V_207 = * ( ( T_2 * ) V_206 -> V_120 . V_121 ) ;
const int * V_219 ;
T_1 V_220 , V_221 , V_222 ;
V_23 -> V_208 = V_207 ;
V_23 -> V_212 = V_204 -> V_209 . V_210 . V_211 [ 0 ] ;
if ( V_23 -> V_212 == 0 )
return 0 ;
V_222 = V_23 -> V_212 - 1 ;
switch ( V_207 ) {
case V_223 :
if ( V_23 -> V_212 > F_74 ( V_224 ) )
return - V_95 ;
V_219 = & V_224 [ V_222 ] ;
break;
case V_225 :
if ( V_23 -> V_212 > F_74 ( V_226 ) )
return - V_95 ;
V_219 = V_226 [ V_222 ] ;
break;
case V_227 :
if ( V_23 -> V_212 > F_74 ( V_228 ) )
return - V_95 ;
V_219 = V_228 [ V_222 ] ;
break;
case V_229 :
if ( V_23 -> V_212 > F_74 ( V_230 ) )
return - V_95 ;
V_219 = V_230 [ V_222 ] ;
break;
default:
F_5 ( V_14 -> V_192 -> V_30 ,
L_21 ,
V_207 ) ;
return - V_95 ;
}
for ( V_221 = 0 ; V_221 < V_207 ; V_221 ++ ) {
V_220 = V_219 [ V_221 ] ;
V_214 . V_231 [ V_221 ] [ V_220 ] = V_232 ;
}
return F_71 ( V_23 , & V_214 , V_14 -> V_192 -> V_30 ) ;
}
static void F_75 ( struct V_22 * V_36 ,
struct V_50 * V_51 )
{
struct V_123 * V_27 = V_36 -> V_27 ;
if ( V_27 -> V_233 ) {
switch ( V_36 -> V_74 ) {
case V_125 :
V_27 -> V_99 -> V_234 = V_51 -> V_234 ;
V_27 -> V_99 -> V_235 = V_51 -> V_235 ;
V_27 -> V_99 -> V_236 = V_51 -> V_236 ;
break;
case V_124 :
V_27 -> V_99 -> V_237 = V_51 -> V_237 ;
V_27 -> V_99 -> V_238 = V_51 -> V_238 ;
break;
default:
break;
}
V_27 -> V_99 -> V_57 = V_51 -> V_57 ;
V_27 -> V_99 -> V_55 = V_51 -> V_55 ;
V_27 -> V_99 -> V_39 = V_51 -> V_39 ;
V_27 -> V_99 -> V_65 = V_51 -> V_65 ;
V_27 -> V_99 -> V_239 = V_51 -> V_239 ;
} else {
memcpy ( V_27 -> V_99 , V_51 , sizeof( * V_51 ) ) ;
}
}
int F_76 ( struct V_215 * V_30 ,
struct V_22 * V_23 ,
struct V_50 * V_51 )
{
struct V_43 * V_239 = NULL ;
F_75 ( V_23 , V_51 ) ;
if ( V_51 -> V_65 == V_66 )
V_239 = & V_23 -> V_37 [ 0 ] ;
else
V_239 = & V_23 -> V_42 [ 0 ] ;
V_239 -> V_39 = V_51 -> V_39 ;
V_239 -> V_38 = V_51 -> V_55 ;
V_239 -> V_41 = F_15 ( V_51 -> V_57 ) ;
switch ( V_239 -> V_41 ) {
case V_58 :
V_239 -> V_59 = V_239 -> V_41 ;
break;
case V_240 :
case V_60 :
V_239 -> V_59 = V_60 ;
break;
default:
F_5 ( V_30 , L_22 ,
V_239 -> V_41 ) ;
return - V_95 ;
}
if ( V_51 -> V_65 == V_66 ) {
V_23 -> V_72 = ( V_239 -> V_39 / 1000 ) *
( V_239 -> V_38 ) *
( V_239 -> V_59 >> 3 ) ;
} else {
V_23 -> V_73 = ( V_239 -> V_39 / 1000 ) *
( V_239 -> V_38 ) *
( V_239 -> V_59 >> 3 ) ;
}
return 0 ;
}
struct V_22 *
F_77 ( struct V_241 * V_242 , int V_65 )
{
struct V_13 * V_14 ;
struct V_175 * V_176 = NULL ;
if ( V_65 == V_66 ) {
V_14 = V_242 -> V_243 ;
F_48 (w, p) {
if ( V_176 -> V_180 && V_176 -> V_177 -> V_199 &&
! F_3 ( V_176 -> V_177 ) )
continue;
if ( V_176 -> V_177 -> V_83 ) {
F_12 ( V_242 -> V_30 , L_23 ,
V_176 -> V_177 -> V_102 ) ;
return V_176 -> V_177 -> V_83 ;
}
}
} else {
V_14 = V_242 -> V_244 ;
F_52 (w, p) {
if ( V_176 -> V_180 && V_176 -> V_184 -> V_199 &&
! F_3 ( V_176 -> V_184 ) )
continue;
if ( V_176 -> V_184 -> V_83 ) {
F_12 ( V_242 -> V_30 , L_23 ,
V_176 -> V_184 -> V_102 ) ;
return V_176 -> V_184 -> V_83 ;
}
}
}
return NULL ;
}
static struct V_22 * F_78 (
struct V_241 * V_242 , struct V_13 * V_14 )
{
struct V_175 * V_176 ;
struct V_22 * V_23 = NULL ;
F_52 (w, p) {
if ( V_14 -> V_245 [ V_246 ] > 0 ) {
if ( V_176 -> V_180 &&
( V_176 -> V_177 -> V_15 == V_19 ) &&
V_176 -> V_184 -> V_83 ) {
V_23 = V_176 -> V_184 -> V_83 ;
return V_23 ;
}
V_23 = F_78 ( V_242 , V_176 -> V_184 ) ;
if ( V_23 )
return V_23 ;
}
}
return V_23 ;
}
static struct V_22 * F_79 (
struct V_241 * V_242 , struct V_13 * V_14 )
{
struct V_175 * V_176 ;
struct V_22 * V_23 = NULL ;
F_48 (w, p) {
if ( V_14 -> V_245 [ V_247 ] > 0 ) {
if ( V_176 -> V_180 &&
( V_176 -> V_184 -> V_15 == V_18 ) &&
V_176 -> V_177 -> V_83 ) {
V_23 = V_176 -> V_177 -> V_83 ;
return V_23 ;
}
V_23 = F_79 ( V_242 , V_176 -> V_177 ) ;
if ( V_23 )
return V_23 ;
}
}
return V_23 ;
}
struct V_22 *
F_80 ( struct V_241 * V_242 , int V_65 )
{
struct V_13 * V_14 ;
struct V_22 * V_23 ;
if ( V_65 == V_66 ) {
V_14 = V_242 -> V_243 ;
V_23 = F_78 ( V_242 , V_14 ) ;
} else {
V_14 = V_242 -> V_244 ;
V_23 = F_79 ( V_242 , V_14 ) ;
}
return V_23 ;
}
static T_1 F_81 ( int V_74 )
{
int V_75 ;
switch ( V_74 ) {
case V_76 :
V_75 = V_92 ;
break;
case V_78 :
V_75 = V_90 ;
break;
case V_80 :
V_75 = V_92 ;
break;
case V_125 :
V_75 = V_248 ;
break;
default:
V_75 = V_249 ;
break;
}
return V_75 ;
}
static int F_82 ( struct V_241 * V_242 ,
struct V_22 * V_23 ,
struct V_50 * V_51 )
{
struct V_86 * V_87 ;
struct V_1 * V_1 = F_21 ( V_242 -> V_30 ) ;
int V_84 = F_81 ( V_23 -> V_74 ) ;
T_1 V_74 = F_19 ( V_23 -> V_74 ) ;
F_75 ( V_23 , V_51 ) ;
if ( V_84 == V_248 )
return 0 ;
V_87 = F_22 ( V_1 , V_23 -> V_96 , V_84 ,
V_51 -> V_57 , V_51 -> V_55 ,
V_51 -> V_39 , V_51 -> V_65 ,
V_74 ) ;
if ( V_87 ) {
V_23 -> V_88 . V_89 = V_87 -> V_97 ;
V_23 -> V_88 . V_3 = ( T_2 * ) & V_87 -> V_3 ;
} else {
F_5 ( V_242 -> V_30 , L_12 ,
V_23 -> V_96 , V_84 ,
V_51 -> V_65 ) ;
F_5 ( V_242 -> V_30 , L_13 ,
V_51 -> V_55 , V_51 -> V_39 , V_51 -> V_57 ) ;
return - V_95 ;
}
return 0 ;
}
static int F_83 ( struct V_241 * V_242 ,
struct V_13 * V_14 ,
struct V_50 * V_51 )
{
struct V_175 * V_176 ;
int V_75 = - V_98 ;
F_52 (w, p) {
if ( V_176 -> V_180 && F_3 ( V_176 -> V_184 ) &&
V_176 -> V_184 -> V_83 ) {
V_75 = F_82 ( V_242 ,
V_176 -> V_184 -> V_83 , V_51 ) ;
if ( V_75 < 0 )
return V_75 ;
} else {
V_75 = F_83 ( V_242 ,
V_176 -> V_184 , V_51 ) ;
if ( V_75 < 0 )
return V_75 ;
}
}
return V_75 ;
}
static int F_84 ( struct V_241 * V_242 ,
struct V_13 * V_14 , struct V_50 * V_51 )
{
struct V_175 * V_176 = NULL ;
int V_75 = - V_98 ;
F_48 (w, p) {
if ( V_176 -> V_180 && F_3 ( V_176 -> V_177 ) &&
V_176 -> V_177 -> V_83 ) {
V_75 = F_82 ( V_242 ,
V_176 -> V_177 -> V_83 , V_51 ) ;
if ( V_75 < 0 )
return V_75 ;
} else {
V_75 = F_84 (
V_242 , V_176 -> V_177 , V_51 ) ;
if ( V_75 < 0 )
return V_75 ;
}
}
return V_75 ;
}
int F_85 ( struct V_241 * V_242 ,
struct V_50 * V_51 )
{
struct V_13 * V_14 ;
if ( V_51 -> V_65 == V_66 ) {
V_14 = V_242 -> V_243 ;
return F_83 ( V_242 , V_14 , V_51 ) ;
} else {
V_14 = V_242 -> V_244 ;
return F_84 ( V_242 , V_14 , V_51 ) ;
}
return 0 ;
}
static int F_86 ( struct V_215 * V_30 ,
struct V_123 * V_27 , T_2 V_250 ,
T_2 V_251 )
{
switch ( V_250 ) {
case V_252 :
V_27 -> V_101 = V_251 ;
break;
case V_253 :
V_27 -> V_254 = V_251 ;
break;
case V_255 :
V_27 -> V_28 = V_251 ;
break;
case V_256 :
V_27 -> V_257 = V_251 ;
break;
default:
F_5 ( V_30 , L_24 , V_250 ) ;
return - V_95 ;
}
return 0 ;
}
static int F_87 ( struct V_215 * V_30 ,
struct V_22 * V_23 , struct V_1 * V_1 ,
struct V_258 * V_259 )
{
struct V_260 * V_261 ;
struct V_123 * V_27 ;
struct V_50 * V_51 ;
F_31 (ppl, &skl->ppl_list, node) {
if ( V_261 -> V_27 -> V_262 == V_259 -> V_209 ) {
V_23 -> V_27 = V_261 -> V_27 ;
return - V_263 ;
}
}
V_261 = F_72 ( V_30 , sizeof( * V_261 ) , V_167 ) ;
if ( ! V_261 )
return - V_130 ;
V_27 = F_72 ( V_30 , sizeof( * V_27 ) , V_167 ) ;
if ( ! V_27 )
return - V_130 ;
V_51 = F_72 ( V_30 , sizeof( * V_51 ) , V_167 ) ;
if ( ! V_51 )
return - V_130 ;
V_27 -> V_99 = V_51 ;
V_27 -> V_262 = V_259 -> V_209 ;
F_88 ( & V_27 -> V_264 ) ;
V_261 -> V_27 = V_27 ;
F_46 ( & V_261 -> V_172 , & V_1 -> V_265 ) ;
V_23 -> V_27 = V_27 ;
V_23 -> V_27 -> V_182 = V_188 ;
return 0 ;
}
static int F_89 ( struct V_215 * V_30 , T_2 V_250 ,
struct V_169 * V_266 ,
int V_267 , T_2 V_209 )
{
switch ( V_250 ) {
case V_268 :
V_266 [ V_267 ] . V_15 . V_32 = V_209 ;
break;
case V_269 :
V_266 [ V_267 ] . V_15 . V_33 = V_209 ;
break;
default:
F_5 ( V_30 , L_25 , V_209 ) ;
return - V_95 ;
}
return 0 ;
}
static int F_90 ( struct V_215 * V_30 ,
struct V_22 * V_23 ,
struct V_258 * V_259 ,
int V_85 , int V_270 )
{
int V_75 ;
struct V_169 * V_266 ;
switch ( V_85 ) {
case V_271 :
V_266 = V_23 -> V_164 ;
break;
case V_272 :
V_266 = V_23 -> V_160 ;
break;
default:
F_5 ( V_30 , L_26 ) ;
return - V_95 ;
}
V_75 = F_89 ( V_30 , V_259 -> V_273 ,
V_266 , V_270 , V_259 -> V_209 ) ;
if ( V_75 < 0 )
return V_75 ;
V_266 [ V_270 ] . V_274 = false ;
V_266 [ V_270 ] . V_161 = V_275 ;
return 0 ;
}
static int F_91 ( struct V_215 * V_30 ,
struct V_22 * V_23 , T_2 V_250 ,
T_2 V_209 , T_2 V_85 , T_2 V_270 )
{
struct V_43 * V_276 ;
switch ( V_85 ) {
case V_271 :
V_276 = V_23 -> V_37 ;
V_276 += V_270 ;
break;
case V_272 :
V_276 = V_23 -> V_42 ;
V_276 += V_270 ;
break;
default:
F_5 ( V_30 , L_26 ) ;
return - V_95 ;
}
switch ( V_250 ) {
case V_277 :
V_276 -> V_38 = V_209 ;
break;
case V_278 :
V_276 -> V_39 = V_209 ;
break;
case V_279 :
V_276 -> V_59 = V_209 ;
break;
case V_280 :
V_276 -> V_41 = V_209 ;
break;
case V_281 :
V_276 -> V_40 = V_209 ;
break;
case V_282 :
V_276 -> V_283 = V_209 ;
break;
case V_284 :
V_276 -> V_285 = V_209 ;
break;
case V_286 :
V_276 -> V_49 = V_209 ;
break;
default:
F_5 ( V_30 , L_27 , V_250 ) ;
return - V_95 ;
}
return 0 ;
}
static int F_92 ( struct V_215 * V_30 , struct V_22 * V_23 ,
struct V_287 * V_288 )
{
if ( V_288 -> V_273 == V_289 )
memcpy ( & V_23 -> V_129 , & V_288 -> V_290 , 16 ) ;
else {
F_5 ( V_30 , L_28 , V_288 -> V_273 ) ;
return - V_95 ;
}
return 0 ;
}
static void F_93 (
struct V_169 * V_291 , T_2 V_270 , T_2 V_209 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_270 ; V_48 ++ )
V_291 [ V_48 ] . V_171 = V_209 ;
}
static int F_94 ( struct V_215 * V_30 ,
struct V_258 * V_259 ,
struct V_1 * V_1 , struct V_22 * V_23 )
{
int V_292 = 0 ;
int V_75 ;
static int V_293 ;
static int V_267 , V_85 ;
if ( V_259 -> V_273 > V_294 )
return - V_95 ;
switch ( V_259 -> V_273 ) {
case V_295 :
V_23 -> V_163 = V_259 -> V_209 ;
V_23 -> V_164 = F_72 ( V_30 , V_23 -> V_163 *
sizeof( * V_23 -> V_164 ) ,
V_167 ) ;
if ( ! V_23 -> V_164 )
return - V_130 ;
break;
case V_296 :
V_23 -> V_159 = V_259 -> V_209 ;
V_23 -> V_160 = F_72 ( V_30 , V_23 -> V_159 *
sizeof( * V_23 -> V_160 ) ,
V_167 ) ;
if ( ! V_23 -> V_160 )
return - V_130 ;
break;
case V_297 :
if ( ! V_23 -> V_164 )
return - V_130 ;
F_93 ( V_23 -> V_164 ,
V_23 -> V_163 , V_259 -> V_209 ) ;
break;
case V_298 :
if ( ! V_23 -> V_160 )
return - V_130 ;
F_93 ( V_23 -> V_160 ,
V_23 -> V_159 , V_259 -> V_209 ) ;
break;
case V_299 :
V_23 -> V_300 = V_259 -> V_209 ;
break;
case V_301 :
V_23 -> V_302 = V_259 -> V_209 ;
case V_303 :
V_23 -> V_70 = V_259 -> V_209 ;
break;
case V_304 :
V_23 -> V_74 = V_259 -> V_209 ;
break;
case V_305 :
V_23 -> V_93 = V_259 -> V_209 ;
break;
case V_306 :
V_23 -> V_15 . V_33 =
V_259 -> V_209 ;
break;
case V_307 :
V_23 -> V_308 = V_259 -> V_209 ;
break;
case V_309 :
V_23 -> V_34 = V_259 -> V_209 ;
break;
case V_310 :
V_23 -> V_73 = V_259 -> V_209 ;
break;
case V_311 :
V_23 -> V_72 = V_259 -> V_209 ;
break;
case V_312 :
V_23 -> V_96 = V_259 -> V_209 ;
break;
case V_313 :
V_23 -> V_67 = V_259 -> V_209 ;
break;
case V_314 :
V_23 -> V_68 = V_259 -> V_209 ;
break;
case V_315 :
V_23 -> V_316 = V_259 -> V_209 ;
break;
case V_317 :
V_75 = F_87 ( V_30 ,
V_23 , V_1 , V_259 ) ;
if ( V_75 < 0 ) {
if ( V_75 == - V_263 ) {
V_293 = 1 ;
break;
}
return V_293 ;
}
break;
case V_252 :
case V_253 :
case V_255 :
case V_256 :
if ( V_293 ) {
V_75 = F_86 ( V_30 , V_23 -> V_27 ,
V_259 -> V_273 , V_259 -> V_209 ) ;
if ( V_75 < 0 )
return V_75 ;
}
break;
case V_318 :
V_85 = V_259 -> V_209 & V_319 ;
V_267 = ( V_259 -> V_209 &
V_320 ) >> 4 ;
break;
case V_277 :
case V_278 :
case V_279 :
case V_280 :
case V_281 :
case V_282 :
case V_284 :
case V_286 :
V_75 = F_91 ( V_30 , V_23 , V_259 -> V_273 ,
V_259 -> V_209 , V_85 , V_267 ) ;
if ( V_75 < 0 )
return V_75 ;
break;
case V_268 :
case V_269 :
V_75 = F_90 ( V_30 ,
V_23 , V_259 , V_85 ,
V_267 ) ;
if ( V_75 < 0 )
return V_75 ;
break;
case V_321 :
V_23 -> V_88 . V_89 =
V_259 -> V_209 ;
break;
case V_322 :
V_23 -> V_88 . V_112 =
V_259 -> V_209 ;
break;
case V_323 :
V_23 -> V_88 . V_114 =
V_259 -> V_209 ;
break;
case V_324 :
V_23 -> V_325 =
V_259 -> V_209 ;
break;
case V_326 :
V_23 -> V_327 = V_259 -> V_209 ;
break;
case V_328 :
case V_329 :
case V_330 :
break;
default:
F_5 ( V_30 , L_29 ,
V_259 -> V_273 ) ;
return - V_95 ;
}
V_292 ++ ;
return V_292 ;
}
static int F_95 ( struct V_215 * V_30 ,
char * V_331 , struct V_1 * V_1 ,
struct V_22 * V_23 , int V_332 )
{
struct V_333 * V_334 ;
struct V_258 * V_259 ;
int V_292 = 0 , V_75 ;
int V_335 = 0 , V_336 = 0 ;
if ( V_332 <= 0 )
return - V_95 ;
while ( V_336 < V_332 ) {
V_334 = (struct V_333 * ) ( V_331 + V_335 ) ;
V_335 += V_334 -> V_97 ;
switch ( V_334 -> type ) {
case V_337 :
F_96 ( V_30 , L_30 ) ;
continue;
case V_338 :
V_75 = F_92 ( V_30 , V_23 , V_334 -> V_290 ) ;
if ( V_75 < 0 )
return V_75 ;
V_336 += sizeof( * V_334 -> V_290 ) ;
continue;
default:
V_259 = V_334 -> V_209 ;
V_292 = 0 ;
break;
}
while ( V_292 <= ( V_334 -> V_339 - 1 ) ) {
V_75 = F_94 ( V_30 , V_259 ,
V_1 , V_23 ) ;
if ( V_75 < 0 )
return V_75 ;
V_292 = V_292 + V_75 ;
V_259 ++ ;
}
V_336 += V_292 * sizeof( * V_259 ) ;
}
return V_335 ;
}
static int F_97 ( struct V_215 * V_30 ,
struct V_333 * V_334 )
{
struct V_258 * V_259 ;
V_259 = V_334 -> V_209 ;
switch ( V_259 -> V_273 ) {
case V_340 :
case V_341 :
case V_342 :
return V_259 -> V_209 ;
default:
F_5 ( V_30 , L_31 , V_259 -> V_273 ) ;
break;
}
return - V_95 ;
}
static int F_98 ( struct V_343 * V_344 ,
struct V_1 * V_1 , struct V_215 * V_30 ,
struct V_22 * V_23 )
{
struct V_333 * V_334 ;
int V_345 , V_332 = 0 , V_346 , V_335 = 0 ;
char * V_198 ;
int V_75 ;
V_334 = (struct V_333 * ) V_344 -> V_83 . V_198 ;
V_75 = F_97 ( V_30 , V_334 ) ;
if ( V_75 < 0 )
return V_75 ;
V_345 = V_75 ;
V_335 += V_334 -> V_97 ;
while ( V_345 > 0 ) {
V_334 = (struct V_333 * )
( V_344 -> V_83 . V_198 + V_335 ) ;
V_75 = F_97 ( V_30 , V_334 ) ;
if ( V_75 < 0 )
return V_75 ;
V_346 = V_75 ;
V_335 += V_334 -> V_97 ;
V_334 = (struct V_333 * )
( V_344 -> V_83 . V_198 + V_335 ) ;
V_75 = F_97 ( V_30 , V_334 ) ;
if ( V_75 < 0 )
return V_75 ;
V_332 = V_75 ;
V_335 += V_334 -> V_97 ;
V_334 = (struct V_333 * )
( V_344 -> V_83 . V_198 + V_335 ) ;
V_198 = ( V_344 -> V_83 . V_198 + V_335 ) ;
if ( V_346 == V_347 ) {
V_75 = F_95 ( V_30 , V_198 ,
V_1 , V_23 , V_332 ) ;
if ( V_75 < 0 )
return V_75 ;
-- V_345 ;
} else {
if ( V_23 -> V_88 . V_89 > 0 )
memcpy ( V_23 -> V_88 . V_3 , V_198 ,
V_23 -> V_88 . V_89 ) ;
-- V_345 ;
V_75 = V_23 -> V_88 . V_89 ;
}
V_335 += V_75 ;
}
return 0 ;
}
static void F_99 ( struct V_348 * V_349 ,
struct V_13 * V_14 )
{
int V_48 ;
struct V_22 * V_23 ;
struct V_123 * V_27 ;
if ( ! strncmp ( V_14 -> V_192 -> V_350 -> V_102 , V_349 -> V_350 . V_102 ,
strlen ( V_349 -> V_350 . V_102 ) ) ) {
V_23 = V_14 -> V_83 ;
V_27 = V_23 -> V_27 ;
for ( V_48 = 0 ; V_48 < V_23 -> V_163 ; V_48 ++ ) {
V_23 -> V_164 [ V_48 ] . V_274 = false ;
V_23 -> V_164 [ V_48 ] . V_161 = V_275 ;
}
for ( V_48 = 0 ; V_48 < V_23 -> V_159 ; V_48 ++ ) {
V_23 -> V_160 [ V_48 ] . V_274 = false ;
V_23 -> V_160 [ V_48 ] . V_161 = V_275 ;
}
V_27 -> V_182 = V_188 ;
V_23 -> V_135 = V_139 ;
}
}
void F_100 ( struct V_1 * V_1 )
{
struct V_6 * V_24 = V_1 -> V_6 ;
struct V_348 * V_351 = V_1 -> V_349 ;
struct V_13 * V_14 ;
struct V_352 * V_353 ;
if ( V_351 == NULL )
return;
V_353 = V_351 -> V_350 . V_353 ;
if ( ! V_353 || ! V_353 -> V_354 )
return;
V_1 -> V_25 . V_26 = 0 ;
V_1 -> V_25 . V_34 = 0 ;
F_31 (w, &card->widgets, list) {
if ( F_3 ( V_14 ) && ( V_14 -> V_83 != NULL ) )
F_99 ( V_351 , V_14 ) ;
}
F_101 ( V_24 -> V_132 ) ;
}
static int F_102 ( struct V_355 * V_356 ,
struct V_13 * V_14 ,
struct V_343 * V_344 )
{
int V_75 ;
struct V_357 * V_358 = F_103 ( V_356 ) ;
struct V_1 * V_1 = F_104 ( V_358 ) ;
struct V_359 * V_360 = F_105 ( V_358 ) ;
struct V_22 * V_23 ;
if ( ! V_344 -> V_83 . V_97 )
goto V_361;
V_23 = F_72 ( V_360 -> V_30 , sizeof( * V_23 ) , V_167 ) ;
if ( ! V_23 )
return - V_130 ;
V_14 -> V_83 = V_23 ;
V_23 -> V_15 . V_32 = - 1 ;
V_75 = F_98 ( V_344 , V_1 , V_360 -> V_30 , V_23 ) ;
if ( V_75 < 0 )
return V_75 ;
F_106 ( V_1 -> V_362 , V_14 , V_23 ) ;
V_361:
if ( V_344 -> V_363 == 0 ) {
F_12 ( V_360 -> V_30 , L_32 ) ;
return 0 ;
}
V_75 = F_107 ( V_14 , V_364 ,
F_74 ( V_364 ) ,
V_344 -> V_363 ) ;
if ( V_75 ) {
F_5 ( V_360 -> V_30 , L_33 ,
V_31 , V_344 -> V_363 ) ;
return - V_95 ;
}
return 0 ;
}
static int F_108 ( struct V_215 * V_30 , struct V_106 * V_365 ,
struct V_366 * V_109 )
{
struct V_108 * V_201 ;
struct V_367 * V_368 =
(struct V_367 * ) V_109 -> V_83 . V_198 ;
V_201 = F_72 ( V_30 , sizeof( * V_201 ) , V_167 ) ;
if ( ! V_201 )
return - V_130 ;
V_201 -> V_166 = V_368 -> V_166 ;
V_201 -> V_114 = V_368 -> V_114 ;
V_201 -> V_112 = V_368 -> V_112 ;
V_201 -> V_97 = V_368 -> V_166 ;
if ( V_201 -> V_166 ) {
V_201 -> V_51 = ( char * ) F_72 ( V_30 , V_201 -> V_166 , V_167 ) ;
if ( ! V_201 -> V_51 )
return - V_130 ;
memcpy ( V_201 -> V_51 , V_368 -> V_51 , V_201 -> V_166 ) ;
}
V_365 -> V_120 . V_121 = V_201 ;
return 0 ;
}
static int F_109 ( struct V_215 * V_30 , struct V_205 * V_369 ,
struct V_370 * V_206 )
{
void * V_198 ;
if ( V_206 -> V_83 . V_97 ) {
V_198 = F_72 ( V_30 , sizeof( V_206 -> V_83 . V_97 ) , V_167 ) ;
if ( ! V_198 )
return - V_130 ;
memcpy ( V_198 , V_206 -> V_83 . V_198 , V_206 -> V_83 . V_97 ) ;
V_369 -> V_120 . V_121 = V_198 ;
}
return 0 ;
}
static int F_110 ( struct V_355 * V_356 ,
struct V_104 * V_371 ,
struct V_372 * V_373 )
{
struct V_106 * V_107 ;
struct V_366 * V_374 ;
struct V_370 * V_375 ;
struct V_357 * V_358 = F_103 ( V_356 ) ;
struct V_359 * V_360 = F_105 ( V_358 ) ;
struct V_205 * V_369 ;
switch ( V_373 -> V_376 . V_377 ) {
case V_378 :
V_374 = F_111 ( V_373 ,
struct V_366 , V_373 ) ;
if ( V_371 -> V_117 & V_118 ) {
V_107 = (struct V_106 * ) V_371 -> V_119 ;
if ( V_374 -> V_83 . V_97 )
return F_108 (
V_360 -> V_30 , V_107 , V_374 ) ;
}
break;
case V_379 :
V_375 = F_111 ( V_373 ,
struct V_370 , V_373 ) ;
if ( V_371 -> V_117 & V_380 ) {
V_369 = (struct V_205 * ) V_371 -> V_119 ;
if ( V_375 -> V_83 . V_97 )
return F_109 ( V_360 -> V_30 , V_369 ,
V_375 ) ;
}
break;
default:
F_96 ( V_360 -> V_30 , L_34 ,
V_373 -> V_376 . V_381 , V_373 -> V_376 . V_382 , V_373 -> V_376 . V_377 ) ;
break;
}
return 0 ;
}
static int F_112 ( struct V_215 * V_30 ,
struct V_383 * V_384 ,
struct V_1 * V_1 )
{
int V_292 = 0 ;
static int V_385 ;
switch ( V_384 -> V_273 ) {
case V_386 :
if ( V_385 > V_1 -> V_6 -> V_387 - 1 ) {
V_385 = 0 ;
return - V_95 ;
}
strncpy ( V_1 -> V_6 -> V_388 [ V_385 ] . V_102 ,
V_384 -> string ,
F_74 ( V_1 -> V_6 -> V_388 [ V_385 ] . V_102 ) ) ;
V_385 ++ ;
V_292 ++ ;
break;
default:
F_5 ( V_30 , L_35 , V_384 -> V_273 ) ;
break;
}
return V_292 ;
}
static int F_113 ( struct V_215 * V_30 ,
struct V_333 * V_334 ,
struct V_1 * V_1 )
{
int V_292 = 0 , V_75 ;
struct V_383 * V_384 ;
V_384 = (struct V_383 * ) V_334 -> V_209 ;
while ( V_292 < V_334 -> V_339 ) {
V_75 = F_112 ( V_30 , V_384 , V_1 ) ;
V_384 ++ ;
if ( V_75 < 0 )
return V_75 ;
V_292 = V_292 + V_75 ;
}
return V_292 ;
}
static int F_114 ( struct V_215 * V_30 ,
struct V_258 * V_259 ,
struct V_1 * V_1 )
{
int V_292 = 0 ;
switch ( V_259 -> V_273 ) {
case V_389 :
V_1 -> V_6 -> V_387 = V_259 -> V_209 ;
V_292 ++ ;
break;
default:
F_5 ( V_30 , L_36 , V_259 -> V_273 ) ;
return - V_95 ;
}
return V_292 ;
}
static int F_115 ( struct V_215 * V_30 ,
char * V_331 , struct V_1 * V_1 ,
int V_332 )
{
int V_292 = 0 , V_75 ;
int V_335 = 0 , V_336 = 0 ;
struct V_333 * V_334 ;
struct V_258 * V_259 ;
if ( V_332 <= 0 )
return - V_95 ;
while ( V_336 < V_332 ) {
V_334 = (struct V_333 * ) ( V_331 + V_335 ) ;
V_335 += V_334 -> V_97 ;
switch ( V_334 -> type ) {
case V_337 :
V_75 = F_113 ( V_30 , V_334 , V_1 ) ;
if ( V_75 < 0 )
return V_75 ;
V_292 = V_75 ;
V_336 += V_292 *
sizeof( struct V_383 ) ;
continue;
case V_338 :
F_96 ( V_30 , L_37 ) ;
continue;
default:
V_259 = V_334 -> V_209 ;
V_292 = 0 ;
break;
}
while ( V_292 <= V_334 -> V_339 - 1 ) {
V_75 = F_114 ( V_30 ,
V_259 , V_1 ) ;
if ( V_75 < 0 )
return V_75 ;
V_292 = V_292 + V_75 ;
V_259 ++ ;
V_336 += V_292 *
sizeof( struct V_258 ) ;
break;
}
V_292 = 0 ;
}
return 0 ;
}
static int F_116 ( struct V_390 * V_391 ,
struct V_215 * V_30 , struct V_1 * V_1 )
{
struct V_333 * V_334 ;
int V_345 , V_332 = 0 , V_346 , V_335 = 0 ;
char * V_198 ;
int V_75 ;
V_334 = (struct V_333 * ) V_391 -> V_83 . V_198 ;
V_75 = F_97 ( V_30 , V_334 ) ;
if ( V_75 < 0 )
return V_75 ;
V_345 = V_75 ;
V_335 += V_334 -> V_97 ;
V_334 = (struct V_333 * )
( V_391 -> V_83 . V_198 + V_335 ) ;
while ( V_345 > 0 ) {
V_75 = F_97 ( V_30 , V_334 ) ;
if ( V_75 < 0 )
return V_75 ;
V_346 = V_75 ;
V_335 += V_334 -> V_97 ;
V_334 = (struct V_333 * )
( V_391 -> V_83 . V_198 + V_335 ) ;
V_75 = F_97 ( V_30 , V_334 ) ;
if ( V_75 < 0 )
return V_75 ;
V_332 = V_75 ;
V_335 += V_334 -> V_97 ;
V_334 = (struct V_333 * )
( V_391 -> V_83 . V_198 + V_335 ) ;
V_198 = ( V_391 -> V_83 . V_198 + V_335 ) ;
if ( V_346 == V_347 ) {
V_75 = F_115 ( V_30 , V_198 , V_1 ,
V_332 ) ;
if ( V_75 < 0 )
return V_75 ;
-- V_345 ;
} else {
return - V_95 ;
}
}
return 0 ;
}
static int F_117 ( struct V_355 * V_356 ,
struct V_390 * V_391 )
{
struct V_357 * V_358 = F_103 ( V_356 ) ;
struct V_359 * V_360 = F_105 ( V_358 ) ;
struct V_1 * V_1 = F_104 ( V_358 ) ;
if ( V_391 -> V_83 . V_97 == 0 )
return 0 ;
F_116 ( V_391 , V_360 -> V_30 , V_1 ) ;
if ( V_1 -> V_6 -> V_387 > V_392 ) {
F_5 ( V_360 -> V_30 , L_38 ,
V_1 -> V_6 -> V_387 ) ;
return - V_95 ;
}
return 0 ;
}
static int F_118 ( struct V_348 * V_349 )
{
struct V_13 * V_14 ;
struct V_22 * V_36 = NULL ;
struct V_126 * V_393 = NULL ;
struct V_123 * V_27 ;
F_31 (w, &platform->component.card->widgets, list) {
if ( F_3 ( V_14 ) && V_14 -> V_83 != NULL ) {
V_36 = V_14 -> V_83 ;
V_27 = V_36 -> V_27 ;
V_393 = F_72 ( V_349 -> V_30 ,
sizeof( * V_393 ) , V_167 ) ;
if ( ! V_393 )
return - V_130 ;
V_393 -> V_14 = V_14 ;
F_119 ( & V_393 -> V_172 , & V_27 -> V_264 ) ;
}
}
return 0 ;
}
static void F_120 ( struct V_1 * V_1 , struct V_123 * V_27 )
{
struct V_126 * V_127 ;
struct V_13 * V_14 ;
struct V_22 * V_23 ;
bool V_394 = false , V_395 = false ;
F_31 (w_module, &pipe->w_list, node) {
V_14 = V_127 -> V_14 ;
V_23 = V_14 -> V_83 ;
if ( V_23 -> V_74 == V_124 )
V_394 = true ;
else if ( V_23 -> V_74 != V_396 )
V_395 = true ;
}
if ( V_394 && V_395 )
V_27 -> V_233 = true ;
else
V_27 -> V_233 = false ;
}
int F_121 ( struct V_348 * V_349 , struct V_357 * V_358 )
{
int V_75 ;
const struct V_397 * V_398 ;
struct V_359 * V_360 = F_105 ( V_358 ) ;
struct V_1 * V_1 = F_104 ( V_358 ) ;
struct V_260 * V_261 ;
V_75 = F_122 ( & V_398 , V_1 -> V_399 , V_360 -> V_30 ) ;
if ( V_75 < 0 ) {
F_5 ( V_360 -> V_30 , L_39 ,
V_1 -> V_399 , V_75 ) ;
V_75 = F_122 ( & V_398 , L_40 , V_360 -> V_30 ) ;
if ( V_75 < 0 ) {
F_5 ( V_360 -> V_30 , L_41 ,
L_40 , V_75 ) ;
return V_75 ;
}
}
V_75 = F_123 ( & V_349 -> V_350 ,
& V_400 , V_398 , 0 ) ;
if ( V_75 < 0 ) {
F_5 ( V_360 -> V_30 , L_42 , V_75 ) ;
F_124 ( V_398 ) ;
return - V_95 ;
}
V_1 -> V_25 . V_35 = V_401 ;
V_1 -> V_25 . V_29 = V_402 ;
V_1 -> V_403 = V_398 ;
V_75 = F_118 ( V_349 ) ;
if ( V_75 < 0 )
return V_75 ;
F_31 (ppl, &skl->ppl_list, node)
F_120 ( V_1 , V_261 -> V_27 ) ;
return 0 ;
}
