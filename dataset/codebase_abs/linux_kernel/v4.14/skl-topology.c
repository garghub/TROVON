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
T_1 V_34 = V_23 -> V_34 ;
struct V_35 * V_36 = & V_23 -> V_37 -> V_38 [ V_34 ] ;
if ( V_1 -> V_25 . V_39 + V_36 -> V_40 > V_1 -> V_25 . V_41 ) {
F_5 ( V_24 -> V_30 ,
L_1 , V_31 ,
V_23 -> V_15 . V_32 , V_23 -> V_15 . V_33 ) ;
F_5 ( V_24 -> V_30 ,
L_3 ,
V_1 -> V_25 . V_41 , V_1 -> V_25 . V_39 ) ;
return false ;
} else {
return true ;
}
}
static void F_8 ( struct V_1 * V_1 ,
struct V_22 * V_23 )
{
T_1 V_34 = V_23 -> V_34 ;
struct V_35 * V_36 = & V_23 -> V_37 -> V_38 [ V_34 ] ;
V_1 -> V_25 . V_39 += V_36 -> V_40 ;
}
static void
F_9 ( struct V_1 * V_1 , struct V_22 * V_23 )
{
T_1 V_34 = V_23 -> V_34 ;
struct V_35 * V_36 = & V_23 -> V_37 -> V_38 [ V_34 ] ;
V_36 = & V_23 -> V_37 -> V_38 [ V_34 ] ;
V_1 -> V_25 . V_39 -= V_36 -> V_40 ;
}
static void
F_10 ( struct V_1 * V_1 , struct V_22 * V_23 )
{
V_1 -> V_25 . V_26 -= V_23 -> V_27 -> V_28 ;
}
static void F_11 ( struct V_6 * V_24 ,
struct V_22 * V_42 )
{
struct V_43 * V_44 = & V_42 -> V_37 -> V_45 [ 0 ] ;
F_12 ( V_24 -> V_30 , L_4 ) ;
F_12 ( V_24 -> V_30 , L_5 ) ;
F_12 ( V_24 -> V_30 , L_6 , V_44 -> V_46 [ 0 ] . V_47 . V_48 ) ;
F_12 ( V_24 -> V_30 , L_7 , V_44 -> V_46 [ 0 ] . V_47 . V_49 ) ;
F_12 ( V_24 -> V_30 , L_8 , V_44 -> V_46 [ 0 ] . V_47 . V_50 ) ;
F_12 ( V_24 -> V_30 , L_9 ,
V_44 -> V_46 [ 0 ] . V_47 . V_51 ) ;
F_12 ( V_24 -> V_30 , L_10 ) ;
F_12 ( V_24 -> V_30 , L_6 , V_44 -> V_52 [ 0 ] . V_47 . V_48 ) ;
F_12 ( V_24 -> V_30 , L_7 , V_44 -> V_52 [ 0 ] . V_47 . V_49 ) ;
F_12 ( V_24 -> V_30 , L_9 ,
V_44 -> V_52 [ 0 ] . V_47 . V_51 ) ;
F_12 ( V_24 -> V_30 , L_8 , V_44 -> V_52 [ 0 ] . V_47 . V_50 ) ;
}
static void F_13 ( struct V_53 * V_47 , int V_54 )
{
int V_55 = 0xFFFFFFFF ;
int V_56 = 0 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_54 ; V_57 ++ ) {
V_55 &= ( ~ ( 0xF << ( 4 * V_57 ) ) | ( V_56 << ( 4 * V_57 ) ) ) ;
V_56 ++ ;
}
V_47 -> V_58 = V_55 ;
}
static void F_14 ( struct V_53 * V_47 ,
struct V_59 * V_60 , int V_61 )
{
if ( V_61 & V_62 )
V_47 -> V_49 = V_60 -> V_49 ;
if ( V_61 & V_63 ) {
V_47 -> V_48 = V_60 -> V_64 ;
F_13 ( V_47 , V_47 -> V_48 ) ;
}
if ( V_61 & V_65 ) {
V_47 -> V_51 = F_15 ( V_60 -> V_66 ) ;
switch ( V_47 -> V_51 ) {
case V_67 :
V_47 -> V_68 = V_47 -> V_51 ;
break;
default:
V_47 -> V_68 = V_69 ;
break;
}
}
}
static void F_16 ( struct V_22 * V_70 ,
struct V_59 * V_60 , bool V_71 )
{
int V_72 , V_73 ;
struct V_53 * V_74 , * V_75 ;
V_74 = & V_70 -> V_37 -> V_45 [ 0 ] . V_46 [ 0 ] . V_47 ;
V_75 = & V_70 -> V_37 -> V_45 [ 0 ] . V_52 [ 0 ] . V_47 ;
if ( V_60 -> V_76 == V_77 ) {
if ( V_71 ) {
V_72 = V_70 -> V_78 ;
V_73 = ( ~ V_70 -> V_79 ) &
V_70 -> V_78 ;
} else {
V_73 = V_70 -> V_78 ;
V_72 = ( ~ V_70 -> V_79 ) &
V_70 -> V_78 ;
}
} else {
if ( V_71 ) {
V_73 = V_70 -> V_78 ;
V_72 = ( ~ V_70 -> V_79 ) &
V_70 -> V_78 ;
} else {
V_72 = V_70 -> V_78 ;
V_73 = ( ~ V_70 -> V_79 ) &
V_70 -> V_78 ;
}
}
F_14 ( V_74 , V_60 , V_72 ) ;
F_14 ( V_75 , V_60 , V_73 ) ;
}
static void F_17 ( struct V_6 * V_24 ,
struct V_22 * V_42 )
{
int V_80 = 1 ;
struct V_53 * V_74 , * V_75 ;
struct V_35 * V_36 ;
V_36 = & V_42 -> V_37 -> V_38 [ 0 ] ;
V_74 = & V_42 -> V_37 -> V_45 [ 0 ] . V_46 [ 0 ] . V_47 ;
V_75 = & V_42 -> V_37 -> V_45 [ 0 ] . V_52 [ 0 ] . V_47 ;
if ( V_42 -> V_81 == V_82 )
V_80 = 5 ;
V_36 -> V_83 = F_18 ( V_74 -> V_49 , 1000 ) *
V_74 -> V_48 * ( V_74 -> V_68 >> 3 ) *
V_80 ;
V_36 -> V_84 = F_18 ( V_75 -> V_49 , 1000 ) *
V_75 -> V_48 * ( V_75 -> V_68 >> 3 ) *
V_80 ;
}
static T_1 F_19 ( int V_85 )
{
int V_86 ;
switch ( V_85 ) {
case V_87 :
V_86 = V_88 ;
break;
case V_89 :
V_86 = V_90 ;
break;
case V_91 :
V_86 = V_92 ;
break;
default:
V_86 = V_93 ;
break;
}
return V_86 ;
}
static int F_20 ( struct V_13 * V_14 ,
struct V_6 * V_24 )
{
struct V_22 * V_70 = V_14 -> V_94 ;
int V_95 , V_96 ;
T_2 V_64 , V_49 , V_66 ;
struct V_97 * V_98 ;
struct V_1 * V_1 = F_21 ( V_24 -> V_30 ) ;
T_1 V_85 = F_19 ( V_70 -> V_85 ) ;
int V_99 = V_70 -> V_99 ;
struct V_43 * V_100 = & V_70 -> V_37 -> V_45 [ V_99 ] ;
if ( V_70 -> V_101 . V_102 > 0 )
return 0 ;
F_12 ( V_24 -> V_30 , L_11 ) ;
switch ( V_70 -> V_85 ) {
case V_89 :
V_95 = V_103 ;
V_96 = V_104 ;
V_49 = V_100 -> V_46 [ 0 ] . V_47 . V_49 ;
V_66 = V_100 -> V_46 [ 0 ] . V_47 . V_68 ;
V_64 = V_100 -> V_46 [ 0 ] . V_47 . V_48 ;
break;
case V_91 :
V_95 = V_105 ;
if ( V_70 -> V_106 == V_107 ) {
V_96 = V_77 ;
V_49 = V_100 -> V_52 [ 0 ] . V_47 . V_49 ;
V_66 = V_100 -> V_52 [ 0 ] . V_47 . V_68 ;
V_64 = V_100 -> V_52 [ 0 ] . V_47 . V_48 ;
} else {
V_96 = V_104 ;
V_49 = V_100 -> V_46 [ 0 ] . V_47 . V_49 ;
V_66 = V_100 -> V_46 [ 0 ] . V_47 . V_68 ;
V_64 = V_100 -> V_46 [ 0 ] . V_47 . V_48 ;
}
break;
default:
return - V_108 ;
}
V_98 = F_22 ( V_1 , V_70 -> V_109 , V_95 ,
V_66 , V_64 , V_49 , V_96 , V_85 ) ;
if ( V_98 ) {
V_70 -> V_101 . V_102 = V_98 -> V_110 ;
V_70 -> V_101 . V_3 = ( T_2 * ) & V_98 -> V_3 ;
} else {
F_5 ( V_24 -> V_30 , L_12 ,
V_70 -> V_109 , V_95 , V_96 ) ;
F_5 ( V_24 -> V_30 , L_13 ,
V_64 , V_49 , V_66 ) ;
return - V_111 ;
}
return 0 ;
}
static void F_23 ( struct V_13 * V_14 ,
struct V_6 * V_24 )
{
struct V_22 * V_70 = V_14 -> V_94 ;
struct V_59 * V_60 = V_70 -> V_27 -> V_112 ;
int V_113 = V_70 -> V_27 -> V_114 ;
bool V_71 ;
if ( ! V_70 -> V_78 )
return;
F_12 ( V_24 -> V_30 , L_14 ,
V_14 -> V_115 ) ;
F_11 ( V_24 , V_70 ) ;
if ( V_113 == V_116 )
V_71 = true ;
else
V_71 = false ;
F_16 ( V_70 , V_60 , V_71 ) ;
F_17 ( V_24 , V_70 ) ;
F_12 ( V_24 -> V_30 , L_15 ,
V_14 -> V_115 ) ;
F_11 ( V_24 , V_70 ) ;
}
static int F_24 ( struct V_13 * V_14 ,
struct V_6 * V_24 )
{
int V_57 , V_86 ;
struct V_22 * V_23 = V_14 -> V_94 ;
const struct V_117 * V_118 ;
struct V_119 * V_120 ;
struct V_121 * V_122 ;
struct V_123 * V_124 ;
if ( V_23 -> V_101 . V_102 > 0 &&
V_23 -> V_101 . V_125 == V_126 ) {
V_124 = & V_23 -> V_101 ;
V_86 = F_25 ( V_24 , V_124 -> V_3 ,
V_124 -> V_102 ,
V_124 -> V_127 , V_23 ) ;
if ( V_86 < 0 )
return V_86 ;
}
for ( V_57 = 0 ; V_57 < V_14 -> V_128 ; V_57 ++ ) {
V_118 = & V_14 -> V_129 [ V_57 ] ;
if ( V_118 -> V_130 & V_131 ) {
V_120 = ( void * ) V_118 -> V_132 ;
V_122 = (struct V_121 * ) V_120 -> V_133 . V_134 ;
if ( V_122 -> V_125 == V_126 ) {
V_86 = F_25 ( V_24 ,
( T_2 * ) V_122 -> V_60 , V_122 -> V_110 ,
V_122 -> V_127 , V_23 ) ;
if ( V_86 < 0 )
return V_86 ;
}
}
}
return 0 ;
}
static int F_26 ( struct V_13 * V_14 )
{
const struct V_117 * V_118 ;
struct V_119 * V_120 ;
struct V_121 * V_122 ;
struct V_22 * V_23 = V_14 -> V_94 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_14 -> V_128 ; V_57 ++ ) {
V_118 = & V_14 -> V_129 [ V_57 ] ;
if ( V_118 -> V_130 & V_131 ) {
V_120 = (struct V_119 * ) V_118 -> V_132 ;
V_122 = (struct V_121 * ) V_120 -> V_133 . V_134 ;
if ( V_122 -> V_125 != V_135 )
continue;
V_23 -> V_101 . V_3 = ( T_2 * ) V_122 -> V_60 ;
V_23 -> V_101 . V_102 = V_122 -> V_110 ;
break;
}
}
return 0 ;
}
static int F_27 ( struct V_6 * V_24 , struct V_136 * V_27 ,
struct V_13 * V_14 , struct V_22 * V_42 )
{
switch ( V_42 -> V_85 ) {
case V_137 :
return F_28 ( V_24 -> V_30 , V_27 -> V_112 ) ;
case V_138 :
return F_29 ( V_24 -> V_30 , V_27 -> V_112 ) ;
}
return 0 ;
}
static int
F_30 ( struct V_1 * V_1 , struct V_136 * V_27 )
{
struct V_139 * V_140 ;
struct V_13 * V_14 ;
struct V_22 * V_23 ;
struct V_6 * V_24 = V_1 -> V_6 ;
T_1 V_141 ;
int V_86 = 0 ;
F_31 (w_module, &pipe->w_list, node) {
T_3 * V_142 ;
V_14 = V_140 -> V_14 ;
V_23 = V_14 -> V_94 ;
if ( V_23 -> V_15 . V_32 < 0 ) {
F_5 ( V_1 -> V_6 -> V_30 ,
L_16 ,
( T_3 * ) V_23 -> V_143 ) ;
return - V_111 ;
}
V_141 = V_23 -> V_27 -> V_144 ;
V_23 -> V_99 = V_23 -> V_145 [ V_141 ] . V_99 ;
V_23 -> V_34 = V_23 -> V_145 [ V_141 ] . V_34 ;
if ( ! F_7 ( V_1 , V_23 ) )
return - V_146 ;
if ( V_23 -> V_37 -> V_147 && V_24 -> V_148 -> V_149 . V_150 ) {
V_86 = V_24 -> V_148 -> V_149 . V_150 ( V_24 -> V_148 ,
V_23 -> V_15 . V_32 , V_23 -> V_143 ) ;
if ( V_86 < 0 )
return V_86 ;
V_23 -> V_151 = V_152 ;
}
V_86 = F_27 ( V_24 , V_27 , V_14 , V_23 ) ;
if ( V_86 < 0 )
return V_86 ;
F_20 ( V_14 , V_24 ) ;
F_23 ( V_14 , V_24 ) ;
V_142 = ( T_3 * ) V_23 -> V_143 ;
V_23 -> V_15 . V_153 = F_32 ( V_24 , V_142 ,
V_23 -> V_15 . V_33 ) ;
if ( V_23 -> V_15 . V_153 < 0 )
return V_86 ;
F_26 ( V_14 ) ;
V_86 = F_33 ( V_24 -> V_148 , V_23 -> V_154 ) ;
if ( V_86 < 0 ) {
F_5 ( V_24 -> V_30 , L_17 ,
V_23 -> V_154 , V_86 ) ;
return V_86 ;
}
V_86 = F_34 ( V_24 , V_23 ) ;
if ( V_86 < 0 ) {
F_35 ( V_24 , V_142 , & V_23 -> V_15 . V_153 ) ;
goto V_155;
}
F_8 ( V_1 , V_23 ) ;
V_86 = F_24 ( V_14 , V_24 ) ;
if ( V_86 < 0 )
goto V_155;
}
return 0 ;
V_155:
F_36 ( V_24 -> V_148 , V_23 -> V_154 ) ;
return V_86 ;
}
static int F_37 ( struct V_6 * V_24 ,
struct V_136 * V_27 )
{
int V_86 = 0 ;
struct V_139 * V_140 = NULL ;
struct V_22 * V_23 = NULL ;
F_31 (w_module, &pipe->w_list, node) {
T_3 * V_142 ;
V_23 = V_140 -> V_14 -> V_94 ;
V_142 = ( T_3 * ) V_23 -> V_143 ;
if ( V_23 -> V_37 -> V_147 && V_24 -> V_148 -> V_149 . V_156 &&
V_23 -> V_151 > V_157 ) {
V_86 = V_24 -> V_148 -> V_149 . V_156 ( V_24 -> V_148 ,
V_23 -> V_15 . V_32 ) ;
if ( V_86 < 0 )
return - V_111 ;
}
F_35 ( V_24 , V_142 , & V_23 -> V_15 . V_153 ) ;
V_86 = F_36 ( V_24 -> V_148 , V_23 -> V_154 ) ;
if ( V_86 < 0 ) {
F_5 ( V_24 -> V_30 , L_18 ,
V_23 -> V_154 , V_86 ) ;
}
}
return V_86 ;
}
static int
F_38 ( struct V_1 * V_1 , struct V_22 * V_23 )
{
struct V_6 * V_24 = V_1 -> V_6 ;
struct V_136 * V_27 = V_23 -> V_27 ;
struct V_59 * V_60 = V_27 -> V_112 ;
struct V_158 * V_159 = & V_27 -> V_160 [ 0 ] ;
struct V_161 * V_47 = NULL ;
bool V_74 = false ;
int V_57 ;
if ( V_27 -> V_162 == 0 ) {
V_27 -> V_144 = 0 ;
return 0 ;
}
if ( V_27 -> V_114 == V_163 ) {
F_12 ( V_24 -> V_30 , L_19 ) ;
V_27 -> V_144 = 0 ;
V_27 -> V_28 = V_159 -> V_164 ;
return 0 ;
}
if ( ( V_27 -> V_114 == V_116 &&
V_27 -> V_165 == V_77 ) ||
( V_27 -> V_114 == V_166 &&
V_27 -> V_165 == V_104 ) )
V_74 = true ;
for ( V_57 = 0 ; V_57 < V_27 -> V_162 ; V_57 ++ ) {
V_159 = & V_27 -> V_160 [ V_57 ] ;
if ( V_74 )
V_47 = & V_159 -> V_74 ;
else
V_47 = & V_159 -> V_75 ;
if ( F_39 ( V_60 -> V_64 , V_60 -> V_49 , V_60 -> V_66 ,
V_47 -> V_48 , V_47 -> V_167 , V_47 -> V_168 ) ) {
V_27 -> V_144 = V_57 ;
V_27 -> V_28 = V_159 -> V_164 ;
F_12 ( V_24 -> V_30 , L_20 , V_57 ) ;
return 0 ;
}
}
F_5 ( V_24 -> V_30 , L_21 ,
V_60 -> V_64 , V_60 -> V_49 , V_60 -> V_66 , V_27 -> V_169 ) ;
return - V_108 ;
}
static int F_40 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
int V_86 ;
struct V_22 * V_23 = V_14 -> V_94 ;
struct V_139 * V_140 ;
struct V_136 * V_170 = V_23 -> V_27 ;
struct V_22 * V_171 = NULL , * V_172 , * V_37 ;
struct V_6 * V_24 = V_1 -> V_6 ;
struct V_173 * V_174 ;
V_86 = F_38 ( V_1 , V_23 ) ;
if ( V_86 < 0 )
return V_86 ;
if ( ! F_7 ( V_1 , V_23 ) )
return - V_175 ;
if ( ! F_4 ( V_1 , V_23 ) )
return - V_146 ;
V_86 = F_41 ( V_24 , V_23 -> V_27 ) ;
if ( V_86 < 0 )
return V_86 ;
F_6 ( V_1 , V_23 ) ;
F_8 ( V_1 , V_23 ) ;
V_86 = F_30 ( V_1 , V_170 ) ;
if ( V_86 < 0 )
return V_86 ;
F_31 (w_module, &s_pipe->w_list, node) {
V_172 = V_140 -> V_14 -> V_94 ;
if ( V_171 == NULL ) {
V_171 = V_172 ;
continue;
}
V_86 = F_42 ( V_24 , V_171 , V_172 ) ;
if ( V_86 < 0 )
return V_86 ;
V_171 = V_172 ;
}
F_31 (w_module, &s_pipe->w_list, node) {
if ( F_43 ( & V_1 -> V_176 ) )
break;
F_31 (modules, &skl->bind_list, node) {
V_37 = V_140 -> V_14 -> V_94 ;
if ( V_174 -> V_177 == V_37 )
F_42 ( V_24 , V_174 -> V_178 ,
V_174 -> V_177 ) ;
}
}
return 0 ;
}
static int F_44 ( struct V_6 * V_24 , T_2 * V_60 ,
int V_110 , struct V_22 * V_42 )
{
int V_57 , V_153 ;
if ( V_42 -> V_81 == V_179 ) {
struct V_180 * V_181 =
(struct V_180 * ) V_60 ;
struct V_182 * V_183 = V_181 -> V_184 ;
for ( V_57 = 0 ; V_57 < V_181 -> V_185 ; V_57 ++ ) {
V_153 = F_45 ( V_24 , V_183 -> V_186 ,
V_183 -> V_187 ) ;
if ( V_153 < 0 )
return - V_108 ;
V_183 -> V_187 = V_153 ;
V_183 ++ ;
}
}
return 0 ;
}
static int F_46 ( struct V_13 * V_14 ,
struct V_22 * V_42 , struct V_6 * V_24 )
{
int V_57 , V_86 ;
struct V_22 * V_23 = V_14 -> V_94 ;
const struct V_117 * V_118 ;
struct V_119 * V_120 ;
struct V_121 * V_122 ;
struct V_123 * V_124 ;
T_2 * V_60 ;
for ( V_57 = 0 ; V_57 < V_42 -> V_37 -> V_188 ; V_57 ++ ) {
if ( V_42 -> V_189 [ V_57 ] . V_190 != V_191 )
return 0 ;
}
for ( V_57 = 0 ; V_57 < V_42 -> V_37 -> V_192 ; V_57 ++ ) {
if ( V_42 -> V_193 [ V_57 ] . V_190 != V_191 )
return 0 ;
}
if ( V_23 -> V_101 . V_102 > 0 &&
V_23 -> V_101 . V_125 == V_194 ) {
V_124 = & V_23 -> V_101 ;
V_86 = F_25 ( V_24 , V_124 -> V_3 ,
V_124 -> V_102 ,
V_124 -> V_127 , V_23 ) ;
if ( V_86 < 0 )
return V_86 ;
}
for ( V_57 = 0 ; V_57 < V_14 -> V_128 ; V_57 ++ ) {
V_118 = & V_14 -> V_129 [ V_57 ] ;
if ( V_118 -> V_130 & V_131 ) {
V_120 = ( void * ) V_118 -> V_132 ;
V_122 = (struct V_121 * ) V_120 -> V_133 . V_134 ;
if ( V_122 -> V_125 == V_194 ) {
V_60 = F_47 ( V_122 -> V_195 , V_196 ) ;
if ( ! V_60 )
return - V_146 ;
memcpy ( V_60 , V_122 -> V_60 , V_122 -> V_195 ) ;
F_44 ( V_24 , V_60 , V_122 -> V_195 ,
V_23 ) ;
V_86 = F_25 ( V_24 , V_60 ,
V_122 -> V_195 , V_122 -> V_127 , V_23 ) ;
F_48 ( V_60 ) ;
if ( V_86 < 0 )
return V_86 ;
}
}
}
return 0 ;
}
static int F_49 ( struct V_1 * V_1 ,
struct V_22 * V_178 , struct V_22 * V_177 )
{
struct V_173 * V_197 , * V_174 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_177 -> V_37 -> V_192 ; V_57 ++ ) {
struct V_198 * V_199 = & V_177 -> V_193 [ V_57 ] ;
if ( V_199 -> V_200 )
continue;
if ( ( V_199 -> V_15 . V_32 == V_178 -> V_15 . V_32 ) &&
( V_199 -> V_15 . V_33 == V_178 -> V_15 . V_33 ) ) {
if ( ! F_43 ( & V_1 -> V_176 ) ) {
F_31 (modules, &skl->bind_list, node) {
if ( V_174 -> V_178 == V_178 && V_174 -> V_177 == V_177 )
return 0 ;
}
}
V_197 = F_47 ( sizeof( * V_197 ) , V_196 ) ;
if ( ! V_197 )
return - V_146 ;
V_197 -> V_178 = V_178 ;
V_197 -> V_177 = V_177 ;
F_50 ( & V_197 -> V_201 , & V_1 -> V_176 ) ;
}
}
return 0 ;
}
static int F_51 ( struct V_13 * V_14 ,
struct V_1 * V_1 ,
struct V_13 * V_202 ,
struct V_22 * V_203 )
{
struct V_204 * V_205 ;
struct V_13 * V_206 = NULL , * V_207 = NULL ;
struct V_22 * V_208 ;
struct V_6 * V_24 = V_1 -> V_6 ;
int V_86 ;
F_52 (w, p) {
if ( ! V_205 -> V_209 )
continue;
F_12 ( V_24 -> V_30 , L_22 , V_31 , V_14 -> V_115 ) ;
F_12 ( V_24 -> V_30 , L_23 , V_31 , V_205 -> V_206 -> V_115 ) ;
V_207 = V_205 -> V_206 ;
if ( ! F_3 ( V_205 -> V_206 ) )
return F_51 ( V_205 -> V_206 , V_1 , V_202 , V_203 ) ;
if ( ( V_205 -> V_206 -> V_94 != NULL ) &&
F_3 ( V_205 -> V_206 ) ) {
V_206 = V_205 -> V_206 ;
V_208 = V_206 -> V_94 ;
if ( ( ( V_203 -> V_151 == V_210 )
&& ( V_208 -> V_151 == V_157 ) ) ) {
V_86 = F_49 ( V_1 ,
V_203 , V_208 ) ;
if ( V_86 < 0 )
return V_86 ;
}
if ( V_203 -> V_151 == V_157 ||
V_208 -> V_151 == V_157 )
continue;
V_86 = F_42 ( V_24 , V_203 , V_208 ) ;
if ( V_86 )
return V_86 ;
F_46 ( V_202 , V_203 , V_24 ) ;
F_46 ( V_206 , V_208 , V_24 ) ;
if ( V_208 -> V_27 -> V_211 != V_212 ) {
if ( V_208 -> V_27 -> V_114 !=
V_116 )
V_86 = F_53 ( V_24 ,
V_208 -> V_27 ) ;
if ( V_86 )
return V_86 ;
}
}
}
if ( ! V_206 && V_207 )
return F_51 ( V_207 , V_1 , V_202 , V_203 ) ;
return 0 ;
}
static int F_54 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
struct V_22 * V_203 ;
struct V_6 * V_24 = V_1 -> V_6 ;
int V_86 = 0 ;
V_203 = V_14 -> V_94 ;
V_86 = F_51 ( V_14 , V_1 , V_14 , V_203 ) ;
if ( V_86 )
return V_86 ;
if ( V_203 -> V_27 -> V_114 != V_116 )
return F_53 ( V_24 , V_203 -> V_27 ) ;
return 0 ;
}
static struct V_13 * F_55 (
struct V_13 * V_14 , struct V_1 * V_1 )
{
struct V_204 * V_205 ;
struct V_13 * V_202 = NULL ;
struct V_6 * V_24 = V_1 -> V_6 ;
F_56 (w, p) {
V_202 = V_205 -> V_213 ;
if ( ! V_205 -> V_209 )
continue;
F_12 ( V_24 -> V_30 , L_24 , V_14 -> V_115 ) ;
F_12 ( V_24 -> V_30 , L_25 , V_205 -> V_213 -> V_115 ) ;
if ( ( V_205 -> V_213 -> V_94 != NULL ) &&
F_3 ( V_205 -> V_213 ) ) {
return V_205 -> V_213 ;
}
}
if ( V_202 != NULL )
return F_55 ( V_202 , V_1 ) ;
return NULL ;
}
static int F_57 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
int V_86 = 0 ;
struct V_13 * V_213 , * V_206 ;
struct V_22 * V_203 , * V_208 ;
struct V_6 * V_24 = V_1 -> V_6 ;
int V_214 = 0 ;
V_206 = V_14 ;
V_208 = V_206 -> V_94 ;
V_213 = F_55 ( V_14 , V_1 ) ;
if ( V_213 != NULL ) {
V_203 = V_213 -> V_94 ;
V_208 = V_206 -> V_94 ;
V_214 = 1 ;
if ( V_203 -> V_27 -> V_211 != V_212 )
V_214 = 0 ;
}
if ( V_214 ) {
V_86 = F_42 ( V_24 , V_203 , V_208 ) ;
if ( V_86 )
return V_86 ;
F_46 ( V_213 , V_203 , V_24 ) ;
F_46 ( V_206 , V_208 , V_24 ) ;
if ( V_208 -> V_27 -> V_114 != V_116 )
V_86 = F_53 ( V_24 , V_208 -> V_27 ) ;
}
return V_86 ;
}
static int F_58 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
struct V_22 * V_203 , * V_208 ;
int V_86 = 0 , V_57 ;
struct V_6 * V_24 = V_1 -> V_6 ;
V_208 = V_14 -> V_94 ;
V_86 = F_59 ( V_24 , V_208 -> V_27 ) ;
if ( V_86 )
return V_86 ;
for ( V_57 = 0 ; V_57 < V_208 -> V_37 -> V_192 ; V_57 ++ ) {
if ( V_208 -> V_193 [ V_57 ] . V_190 == V_191 ) {
V_203 = V_208 -> V_193 [ V_57 ] . V_215 ;
if ( ! V_203 )
continue;
V_86 = F_60 ( V_24 ,
V_203 , V_208 ) ;
}
}
return V_86 ;
}
static int F_61 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
struct V_22 * V_23 = V_14 -> V_94 ;
struct V_139 * V_140 ;
struct V_22 * V_171 = NULL , * V_172 ;
struct V_6 * V_24 = V_1 -> V_6 ;
struct V_136 * V_170 = V_23 -> V_27 ;
struct V_173 * V_174 , * V_216 ;
if ( V_170 -> V_211 == V_217 )
return - V_108 ;
F_9 ( V_1 , V_23 ) ;
F_10 ( V_1 , V_23 ) ;
F_31 (w_module, &s_pipe->w_list, node) {
if ( F_43 ( & V_1 -> V_176 ) )
break;
V_171 = V_140 -> V_14 -> V_94 ;
F_62 (modules, tmp, &skl->bind_list, node) {
if ( V_174 -> V_177 == V_171 ) {
F_60 ( V_24 , V_174 -> V_178 ,
V_174 -> V_177 ) ;
}
if ( V_174 -> V_178 == V_171 ) {
F_63 ( & V_174 -> V_201 ) ;
V_174 -> V_178 = NULL ;
V_174 -> V_177 = NULL ;
F_48 ( V_174 ) ;
}
}
}
F_31 (w_module, &s_pipe->w_list, node) {
V_172 = V_140 -> V_14 -> V_94 ;
if ( V_23 -> V_151 >= V_210 )
F_9 ( V_1 , V_172 ) ;
if ( V_171 == NULL ) {
V_171 = V_172 ;
continue;
}
F_60 ( V_24 , V_171 , V_172 ) ;
V_171 = V_172 ;
}
F_64 ( V_24 , V_23 -> V_27 ) ;
F_31 (w_module, &s_pipe->w_list, node) {
V_171 = V_140 -> V_14 -> V_94 ;
V_171 -> V_151 = V_157 ;
}
return F_37 ( V_24 , V_170 ) ;
}
static int F_65 ( struct V_13 * V_14 ,
struct V_1 * V_1 )
{
struct V_22 * V_203 , * V_208 ;
int V_86 = 0 , V_57 ;
struct V_6 * V_24 = V_1 -> V_6 ;
V_203 = V_14 -> V_94 ;
V_86 = F_59 ( V_24 , V_203 -> V_27 ) ;
if ( V_86 )
return V_86 ;
for ( V_57 = 0 ; V_57 < V_203 -> V_37 -> V_188 ; V_57 ++ ) {
if ( V_203 -> V_189 [ V_57 ] . V_190 == V_191 ) {
V_208 = V_203 -> V_189 [ V_57 ] . V_215 ;
if ( ! V_208 )
continue;
V_86 = F_60 ( V_24 , V_203 ,
V_208 ) ;
}
}
return V_86 ;
}
static int F_66 ( struct V_13 * V_14 ,
struct V_218 * V_118 , int V_219 )
{
struct V_220 * V_221 = V_14 -> V_221 ;
struct V_1 * V_1 = F_21 ( V_221 -> V_30 ) ;
switch ( V_219 ) {
case V_222 :
return F_40 ( V_14 , V_1 ) ;
case V_223 :
return F_57 ( V_14 , V_1 ) ;
case V_224 :
return F_58 ( V_14 , V_1 ) ;
case V_225 :
return F_61 ( V_14 , V_1 ) ;
}
return 0 ;
}
static int F_67 ( struct V_13 * V_14 ,
struct V_218 * V_118 , int V_219 )
{
struct V_220 * V_221 = V_14 -> V_221 ;
struct V_1 * V_1 = F_21 ( V_221 -> V_30 ) ;
switch ( V_219 ) {
case V_222 :
return F_54 ( V_14 , V_1 ) ;
case V_225 :
return F_65 ( V_14 , V_1 ) ;
}
return 0 ;
}
static int F_68 ( struct V_218 * V_226 ,
unsigned int T_4 * V_227 , unsigned int V_110 )
{
struct V_119 * V_120 =
(struct V_119 * ) V_226 -> V_132 ;
struct V_121 * V_122 = (struct V_121 * ) V_120 -> V_133 . V_134 ;
struct V_13 * V_14 = F_69 ( V_226 ) ;
struct V_22 * V_23 = V_14 -> V_94 ;
struct V_1 * V_1 = F_21 ( V_14 -> V_221 -> V_30 ) ;
if ( V_14 -> V_228 )
F_70 ( V_1 -> V_6 , ( T_2 * ) V_122 -> V_60 ,
V_122 -> V_110 , V_122 -> V_127 , V_23 ) ;
V_110 -= 2 * sizeof( T_2 ) ;
if ( V_110 > V_122 -> V_195 )
V_110 = V_122 -> V_195 ;
if ( V_122 -> V_60 ) {
if ( F_71 ( V_227 , & V_122 -> V_127 , sizeof( T_2 ) ) )
return - V_229 ;
if ( F_71 ( V_227 + 1 , & V_110 , sizeof( T_2 ) ) )
return - V_229 ;
if ( F_71 ( V_227 + 2 , V_122 -> V_60 , V_110 ) )
return - V_229 ;
}
return 0 ;
}
static int F_72 ( struct V_218 * V_226 ,
const unsigned int T_4 * V_227 , unsigned int V_110 )
{
struct V_13 * V_14 = F_69 ( V_226 ) ;
struct V_22 * V_23 = V_14 -> V_94 ;
struct V_119 * V_120 =
(struct V_119 * ) V_226 -> V_132 ;
struct V_121 * V_230 = (struct V_121 * ) V_120 -> V_133 . V_134 ;
struct V_1 * V_1 = F_21 ( V_14 -> V_221 -> V_30 ) ;
if ( V_230 -> V_60 ) {
if ( V_110 > V_230 -> V_195 )
return - V_108 ;
V_230 -> V_110 = V_110 ;
if ( V_230 -> V_127 == V_231 ) {
if ( F_73 ( V_230 -> V_60 , V_227 , V_110 ) )
return - V_229 ;
} else {
if ( F_73 ( V_230 -> V_60 ,
V_227 + 2 , V_110 ) )
return - V_229 ;
}
if ( V_14 -> V_228 )
return F_25 ( V_1 -> V_6 ,
( T_2 * ) V_230 -> V_60 , V_230 -> V_110 ,
V_230 -> V_127 , V_23 ) ;
}
return 0 ;
}
static int F_74 ( struct V_218 * V_226 ,
struct V_232 * V_233 )
{
struct V_13 * V_14 = F_69 ( V_226 ) ;
struct V_22 * V_23 = V_14 -> V_94 ;
struct V_234 * V_235 = (struct V_234 * ) V_226 -> V_132 ;
T_2 V_236 = * ( ( T_2 * ) V_235 -> V_133 . V_134 ) ;
if ( V_23 -> V_237 == V_236 )
V_233 -> V_238 . V_239 . V_240 [ 0 ] =
V_23 -> V_241 ;
else
V_233 -> V_238 . V_239 . V_240 [ 0 ] = 0 ;
return 0 ;
}
static int F_75 ( struct V_22 * V_23 ,
struct V_242 * V_243 , struct V_244 * V_30 )
{
struct V_123 * V_124 = & V_23 -> V_101 ;
V_124 -> V_102 = sizeof( struct V_242 ) ;
V_124 -> V_125 = V_126 ;
V_124 -> V_127 = 0x00 ;
if ( ! V_124 -> V_3 ) {
V_124 -> V_3 = F_76 ( V_30 , V_124 -> V_102 , V_196 ) ;
if ( ! V_124 -> V_3 )
return - V_146 ;
}
V_243 -> V_245 = V_246 ;
V_243 -> V_247 = 0 ;
memcpy ( V_124 -> V_3 , V_243 , V_124 -> V_102 ) ;
return 0 ;
}
static int F_77 ( struct V_218 * V_226 ,
struct V_232 * V_233 )
{
struct V_13 * V_14 = F_69 ( V_226 ) ;
struct V_22 * V_23 = V_14 -> V_94 ;
struct V_242 V_243 = { 0 } ;
struct V_234 * V_235 = (struct V_234 * ) V_226 -> V_132 ;
T_2 V_236 = * ( ( T_2 * ) V_235 -> V_133 . V_134 ) ;
const int * V_248 ;
T_1 V_249 , V_250 , V_251 ;
V_23 -> V_237 = V_236 ;
V_23 -> V_241 = V_233 -> V_238 . V_239 . V_240 [ 0 ] ;
if ( V_23 -> V_241 == 0 )
return 0 ;
V_251 = V_23 -> V_241 - 1 ;
switch ( V_236 ) {
case V_252 :
if ( V_23 -> V_241 > F_78 ( V_253 ) )
return - V_108 ;
V_248 = & V_253 [ V_251 ] ;
break;
case V_254 :
if ( V_23 -> V_241 > F_78 ( V_255 ) )
return - V_108 ;
V_248 = V_255 [ V_251 ] ;
break;
case V_256 :
if ( V_23 -> V_241 > F_78 ( V_257 ) )
return - V_108 ;
V_248 = V_257 [ V_251 ] ;
break;
case V_258 :
if ( V_23 -> V_241 > F_78 ( V_259 ) )
return - V_108 ;
V_248 = V_259 [ V_251 ] ;
break;
default:
F_5 ( V_14 -> V_221 -> V_30 ,
L_26 ,
V_236 ) ;
return - V_108 ;
}
for ( V_250 = 0 ; V_250 < V_236 ; V_250 ++ ) {
V_249 = V_248 [ V_250 ] ;
V_243 . V_260 [ V_250 ] [ V_249 ] = V_261 ;
}
return F_75 ( V_23 , & V_243 , V_14 -> V_221 -> V_30 ) ;
}
static void F_79 ( struct V_22 * V_42 ,
struct V_59 * V_60 )
{
struct V_136 * V_27 = V_42 -> V_27 ;
if ( V_27 -> V_262 ) {
switch ( V_42 -> V_85 ) {
case V_138 :
V_27 -> V_112 -> V_263 = V_60 -> V_263 ;
V_27 -> V_112 -> V_264 = V_60 -> V_264 ;
V_27 -> V_112 -> V_265 = V_60 -> V_265 ;
break;
case V_137 :
V_27 -> V_112 -> V_266 = V_60 -> V_266 ;
V_27 -> V_112 -> V_267 = V_60 -> V_267 ;
break;
default:
break;
}
V_27 -> V_112 -> V_66 = V_60 -> V_66 ;
V_27 -> V_112 -> V_64 = V_60 -> V_64 ;
V_27 -> V_112 -> V_49 = V_60 -> V_49 ;
V_27 -> V_112 -> V_76 = V_60 -> V_76 ;
V_27 -> V_112 -> V_268 = V_60 -> V_268 ;
} else {
memcpy ( V_27 -> V_112 , V_60 , sizeof( * V_60 ) ) ;
}
}
int F_80 ( struct V_244 * V_30 ,
struct V_22 * V_23 ,
struct V_59 * V_60 )
{
struct V_35 * V_36 = & V_23 -> V_37 -> V_38 [ 0 ] ;
struct V_1 * V_1 = F_21 ( V_30 ) ;
struct V_53 * V_268 = NULL ;
T_1 V_141 = V_23 -> V_27 -> V_144 ;
F_79 ( V_23 , V_60 ) ;
V_23 -> V_99 = V_23 -> V_145 [ V_141 ] . V_99 ;
V_23 -> V_34 = V_23 -> V_145 [ V_141 ] . V_34 ;
if ( V_1 -> V_269 )
return 0 ;
if ( V_60 -> V_76 == V_77 )
V_268 = & V_23 -> V_37 -> V_45 [ 0 ] . V_46 [ 0 ] . V_47 ;
else
V_268 = & V_23 -> V_37 -> V_45 [ 0 ] . V_52 [ 0 ] . V_47 ;
V_268 -> V_49 = V_60 -> V_49 ;
V_268 -> V_48 = V_60 -> V_64 ;
V_268 -> V_51 = F_15 ( V_60 -> V_66 ) ;
switch ( V_268 -> V_51 ) {
case V_67 :
V_268 -> V_68 = V_268 -> V_51 ;
break;
case V_270 :
case V_69 :
V_268 -> V_68 = V_69 ;
break;
default:
F_5 ( V_30 , L_27 ,
V_268 -> V_51 ) ;
return - V_108 ;
}
if ( V_60 -> V_76 == V_77 ) {
V_36 -> V_83 = ( V_268 -> V_49 / 1000 ) *
( V_268 -> V_48 ) *
( V_268 -> V_68 >> 3 ) ;
} else {
V_36 -> V_84 = ( V_268 -> V_49 / 1000 ) *
( V_268 -> V_48 ) *
( V_268 -> V_68 >> 3 ) ;
}
return 0 ;
}
struct V_22 *
F_81 ( struct V_271 * V_272 , int V_76 )
{
struct V_13 * V_14 ;
struct V_204 * V_205 = NULL ;
if ( V_76 == V_77 ) {
V_14 = V_272 -> V_273 ;
F_52 (w, p) {
if ( V_205 -> V_209 && V_205 -> V_206 -> V_228 &&
! F_3 ( V_205 -> V_206 ) )
continue;
if ( V_205 -> V_206 -> V_94 ) {
F_12 ( V_272 -> V_30 , L_28 ,
V_205 -> V_206 -> V_115 ) ;
return V_205 -> V_206 -> V_94 ;
}
}
} else {
V_14 = V_272 -> V_274 ;
F_56 (w, p) {
if ( V_205 -> V_209 && V_205 -> V_213 -> V_228 &&
! F_3 ( V_205 -> V_213 ) )
continue;
if ( V_205 -> V_213 -> V_94 ) {
F_12 ( V_272 -> V_30 , L_28 ,
V_205 -> V_213 -> V_115 ) ;
return V_205 -> V_213 -> V_94 ;
}
}
}
return NULL ;
}
static struct V_22 * F_82 (
struct V_271 * V_272 , struct V_13 * V_14 )
{
struct V_204 * V_205 ;
struct V_22 * V_23 = NULL ;
F_56 (w, p) {
if ( V_14 -> V_275 [ V_276 ] > 0 ) {
if ( V_205 -> V_209 &&
( V_205 -> V_206 -> V_15 == V_19 ) &&
V_205 -> V_213 -> V_94 ) {
V_23 = V_205 -> V_213 -> V_94 ;
return V_23 ;
}
V_23 = F_82 ( V_272 , V_205 -> V_213 ) ;
if ( V_23 )
return V_23 ;
}
}
return V_23 ;
}
static struct V_22 * F_83 (
struct V_271 * V_272 , struct V_13 * V_14 )
{
struct V_204 * V_205 ;
struct V_22 * V_23 = NULL ;
F_52 (w, p) {
if ( V_14 -> V_275 [ V_277 ] > 0 ) {
if ( V_205 -> V_209 &&
( V_205 -> V_213 -> V_15 == V_18 ) &&
V_205 -> V_206 -> V_94 ) {
V_23 = V_205 -> V_206 -> V_94 ;
return V_23 ;
}
V_23 = F_83 ( V_272 , V_205 -> V_206 ) ;
if ( V_23 )
return V_23 ;
}
}
return V_23 ;
}
struct V_22 *
F_84 ( struct V_271 * V_272 , int V_76 )
{
struct V_13 * V_14 ;
struct V_22 * V_23 ;
if ( V_76 == V_77 ) {
V_14 = V_272 -> V_273 ;
V_23 = F_82 ( V_272 , V_14 ) ;
} else {
V_14 = V_272 -> V_274 ;
V_23 = F_83 ( V_272 , V_14 ) ;
}
return V_23 ;
}
static T_1 F_85 ( int V_85 )
{
int V_86 ;
switch ( V_85 ) {
case V_87 :
V_86 = V_105 ;
break;
case V_89 :
V_86 = V_103 ;
break;
case V_91 :
V_86 = V_105 ;
break;
case V_138 :
V_86 = V_278 ;
break;
default:
V_86 = V_279 ;
break;
}
return V_86 ;
}
static int F_86 ( struct V_271 * V_272 ,
struct V_22 * V_23 ,
struct V_59 * V_60 )
{
struct V_97 * V_98 ;
struct V_1 * V_1 = F_21 ( V_272 -> V_30 ) ;
int V_95 = F_85 ( V_23 -> V_85 ) ;
T_1 V_85 = F_19 ( V_23 -> V_85 ) ;
F_79 ( V_23 , V_60 ) ;
if ( V_95 == V_278 )
return 0 ;
V_98 = F_22 ( V_1 , V_23 -> V_109 , V_95 ,
V_60 -> V_66 , V_60 -> V_64 ,
V_60 -> V_49 , V_60 -> V_76 ,
V_85 ) ;
if ( V_98 ) {
V_23 -> V_101 . V_102 = V_98 -> V_110 ;
V_23 -> V_101 . V_3 = ( T_2 * ) & V_98 -> V_3 ;
} else {
F_5 ( V_272 -> V_30 , L_12 ,
V_23 -> V_109 , V_95 ,
V_60 -> V_76 ) ;
F_5 ( V_272 -> V_30 , L_13 ,
V_60 -> V_64 , V_60 -> V_49 , V_60 -> V_66 ) ;
return - V_108 ;
}
return 0 ;
}
static int F_87 ( struct V_271 * V_272 ,
struct V_13 * V_14 ,
struct V_59 * V_60 )
{
struct V_204 * V_205 ;
int V_86 = - V_111 ;
F_56 (w, p) {
if ( V_205 -> V_209 && F_3 ( V_205 -> V_213 ) &&
V_205 -> V_213 -> V_94 ) {
V_86 = F_86 ( V_272 ,
V_205 -> V_213 -> V_94 , V_60 ) ;
if ( V_86 < 0 )
return V_86 ;
} else {
V_86 = F_87 ( V_272 ,
V_205 -> V_213 , V_60 ) ;
if ( V_86 < 0 )
return V_86 ;
}
}
return V_86 ;
}
static int F_88 ( struct V_271 * V_272 ,
struct V_13 * V_14 , struct V_59 * V_60 )
{
struct V_204 * V_205 = NULL ;
int V_86 = - V_111 ;
F_52 (w, p) {
if ( V_205 -> V_209 && F_3 ( V_205 -> V_206 ) &&
V_205 -> V_206 -> V_94 ) {
V_86 = F_86 ( V_272 ,
V_205 -> V_206 -> V_94 , V_60 ) ;
if ( V_86 < 0 )
return V_86 ;
} else {
V_86 = F_88 (
V_272 , V_205 -> V_206 , V_60 ) ;
if ( V_86 < 0 )
return V_86 ;
}
}
return V_86 ;
}
int F_89 ( struct V_271 * V_272 ,
struct V_59 * V_60 )
{
struct V_13 * V_14 ;
if ( V_60 -> V_76 == V_77 ) {
V_14 = V_272 -> V_273 ;
return F_87 ( V_272 , V_14 , V_60 ) ;
} else {
V_14 = V_272 -> V_274 ;
return F_88 ( V_272 , V_14 , V_60 ) ;
}
return 0 ;
}
static int F_90 ( struct V_244 * V_30 ,
struct V_136 * V_27 , T_2 V_280 ,
T_2 V_281 , int V_282 , int V_96 )
{
struct V_161 * V_47 ;
struct V_158 * V_283 ;
switch ( V_96 ) {
case V_284 :
V_47 = & V_27 -> V_160 [ V_282 ] . V_74 ;
break;
case V_285 :
V_47 = & V_27 -> V_160 [ V_282 ] . V_75 ;
break;
default:
F_5 ( V_30 , L_29 , V_96 ) ;
return - V_108 ;
}
V_283 = & V_27 -> V_160 [ V_282 ] ;
switch ( V_280 ) {
case V_286 :
V_47 -> V_167 = V_281 ;
break;
case V_287 :
V_47 -> V_48 = V_281 ;
break;
case V_288 :
V_47 -> V_168 = V_281 ;
break;
case V_289 :
V_283 -> V_164 = V_281 ;
break;
default:
F_5 ( V_30 , L_30 , V_280 ) ;
return - V_108 ;
}
return 0 ;
}
static int F_91 ( struct V_244 * V_30 ,
struct V_136 * V_27 , T_2 V_280 ,
T_2 V_281 )
{
switch ( V_280 ) {
case V_290 :
V_27 -> V_114 = V_281 ;
break;
case V_291 :
V_27 -> V_292 = V_281 ;
break;
case V_293 :
V_27 -> V_28 = V_281 ;
break;
case V_294 :
V_27 -> V_295 = V_281 ;
break;
case V_296 :
V_27 -> V_165 = V_281 ;
break;
case V_297 :
V_27 -> V_162 = V_281 ;
break;
default:
F_5 ( V_30 , L_31 , V_280 ) ;
return - V_108 ;
}
return 0 ;
}
static int F_92 ( struct V_244 * V_30 ,
struct V_22 * V_23 , struct V_1 * V_1 ,
struct V_298 * V_299 )
{
struct V_300 * V_301 ;
struct V_136 * V_27 ;
struct V_59 * V_60 ;
F_31 (ppl, &skl->ppl_list, node) {
if ( V_301 -> V_27 -> V_169 == V_299 -> V_238 ) {
V_23 -> V_27 = V_301 -> V_27 ;
return - V_302 ;
}
}
V_301 = F_76 ( V_30 , sizeof( * V_301 ) , V_196 ) ;
if ( ! V_301 )
return - V_146 ;
V_27 = F_76 ( V_30 , sizeof( * V_27 ) , V_196 ) ;
if ( ! V_27 )
return - V_146 ;
V_60 = F_76 ( V_30 , sizeof( * V_60 ) , V_196 ) ;
if ( ! V_60 )
return - V_146 ;
V_27 -> V_112 = V_60 ;
V_27 -> V_169 = V_299 -> V_238 ;
F_93 ( & V_27 -> V_303 ) ;
V_301 -> V_27 = V_27 ;
F_50 ( & V_301 -> V_201 , & V_1 -> V_304 ) ;
V_23 -> V_27 = V_27 ;
V_23 -> V_27 -> V_211 = V_217 ;
return 0 ;
}
static int F_94 ( struct V_244 * V_30 , T_2 V_280 ,
struct V_198 * V_305 ,
int V_306 , T_2 V_238 )
{
switch ( V_280 ) {
case V_307 :
V_305 [ V_306 ] . V_15 . V_32 = V_238 ;
break;
case V_308 :
V_305 [ V_306 ] . V_15 . V_33 = V_238 ;
break;
default:
F_5 ( V_30 , L_32 , V_238 ) ;
return - V_108 ;
}
return 0 ;
}
static int F_95 ( struct V_244 * V_30 ,
struct V_22 * V_23 ,
struct V_298 * V_299 ,
int V_96 , int V_309 )
{
int V_86 ;
struct V_198 * V_305 ;
switch ( V_96 ) {
case V_284 :
V_305 = V_23 -> V_193 ;
break;
case V_285 :
V_305 = V_23 -> V_189 ;
break;
default:
F_5 ( V_30 , L_33 ) ;
return - V_108 ;
}
V_86 = F_94 ( V_30 , V_299 -> V_310 ,
V_305 , V_309 , V_299 -> V_238 ) ;
if ( V_86 < 0 )
return V_86 ;
V_305 [ V_309 ] . V_311 = false ;
V_305 [ V_309 ] . V_190 = V_312 ;
return 0 ;
}
static int F_96 ( struct V_244 * V_30 ,
struct V_53 * V_313 ,
T_2 V_280 , T_2 V_238 )
{
switch ( V_280 ) {
case V_314 :
V_313 -> V_48 = V_238 ;
break;
case V_315 :
V_313 -> V_49 = V_238 ;
break;
case V_316 :
V_313 -> V_68 = V_238 ;
break;
case V_317 :
V_313 -> V_51 = V_238 ;
break;
case V_318 :
V_313 -> V_50 = V_238 ;
break;
case V_319 :
V_313 -> V_320 = V_238 ;
break;
case V_321 :
V_313 -> V_322 = V_238 ;
break;
case V_323 :
V_313 -> V_58 = V_238 ;
break;
default:
F_5 ( V_30 , L_34 , V_280 ) ;
return - V_108 ;
}
return 0 ;
}
static int F_97 ( struct V_244 * V_30 ,
struct V_43 * V_47 ,
T_2 V_280 , T_2 V_324 , T_2 V_96 , int V_99 )
{
struct V_53 * V_313 ;
if ( ! V_47 )
return - V_108 ;
switch ( V_96 ) {
case V_284 :
V_313 = & V_47 -> V_46 [ V_99 ] . V_47 ;
break;
case V_285 :
V_313 = & V_47 -> V_52 [ V_99 ] . V_47 ;
break;
default:
F_5 ( V_30 , L_29 , V_96 ) ;
return - V_108 ;
}
return F_96 ( V_30 , V_313 , V_280 , V_324 ) ;
}
static int F_98 ( struct V_244 * V_30 , struct V_22 * V_23 ,
struct V_325 * V_326 )
{
if ( V_326 -> V_310 == V_327 )
memcpy ( & V_23 -> V_143 , & V_326 -> V_328 , 16 ) ;
else {
F_5 ( V_30 , L_35 , V_326 -> V_310 ) ;
return - V_108 ;
}
return 0 ;
}
static void F_99 (
struct V_198 * V_329 , T_2 V_309 , T_2 V_238 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_309 ; V_57 ++ )
V_329 [ V_57 ] . V_200 = V_238 ;
}
static int F_100 ( struct V_244 * V_30 ,
struct V_298 * V_299 ,
struct V_35 * V_36 , int V_330 , int V_96 )
{
struct V_331 * V_305 ;
switch ( V_96 ) {
case V_284 :
V_305 = & V_36 -> V_332 [ V_330 ] ;
break;
case V_285 :
V_305 = & V_36 -> V_333 [ V_330 ] ;
break;
default:
F_5 ( V_30 , L_36 , V_96 ) ;
return - V_108 ;
}
switch ( V_299 -> V_310 ) {
case V_334 :
V_305 -> V_306 = V_299 -> V_238 ;
break;
case V_335 :
V_305 -> V_336 = V_299 -> V_238 ;
break;
default:
F_5 ( V_30 , L_37 , V_299 -> V_310 ) ;
return - V_108 ;
}
return 0 ;
}
static int F_101 ( struct V_244 * V_30 ,
struct V_298 * V_299 ,
struct V_35 * V_36 ,
int V_330 , int V_96 )
{
int V_86 , V_337 = 0 ;
if ( ! V_36 )
return - V_108 ;
switch ( V_299 -> V_310 ) {
case V_338 :
V_36 -> V_40 = V_299 -> V_238 ;
break;
case V_339 :
V_36 -> V_340 = V_299 -> V_238 ;
break;
case V_341 :
V_36 -> V_342 = V_299 -> V_238 ;
break;
case V_343 :
V_36 -> V_344 = V_299 -> V_238 ;
break;
case V_345 :
V_36 -> V_84 = V_299 -> V_238 ;
break;
case V_346 :
V_36 -> V_83 = V_299 -> V_238 ;
break;
case V_347 :
V_36 -> V_40 = V_299 -> V_238 ;
break;
case V_334 :
case V_335 :
V_86 = F_100 ( V_30 , V_299 , V_36 ,
V_330 , V_96 ) ;
if ( V_86 < 0 )
return V_86 ;
break;
default:
F_5 ( V_30 , L_38 , V_299 -> V_310 ) ;
return - V_108 ;
}
V_337 ++ ;
return V_337 ;
}
static int F_102 ( struct V_244 * V_30 ,
struct V_298 * V_299 ,
struct V_1 * V_1 , struct V_22 * V_23 )
{
int V_337 = 0 ;
int V_86 ;
static int V_348 ;
static int V_306 , V_96 , V_282 ;
struct V_43 * V_44 = NULL ;
struct V_35 * V_36 = NULL ;
int V_34 = V_23 -> V_34 ;
int V_99 = V_23 -> V_99 ;
if ( V_1 -> V_269 == 0 ) {
V_36 = & V_23 -> V_37 -> V_38 [ V_34 ] ;
V_44 = & V_23 -> V_37 -> V_45 [ V_99 ] ;
}
if ( V_299 -> V_310 > V_349 )
return - V_108 ;
switch ( V_299 -> V_310 ) {
case V_350 :
V_23 -> V_37 -> V_192 = V_299 -> V_238 ;
break;
case V_351 :
V_23 -> V_37 -> V_188 = V_299 -> V_238 ;
break;
case V_352 :
if ( ! V_23 -> V_193 )
V_23 -> V_193 = F_76 ( V_30 , V_353 *
sizeof( * V_23 -> V_193 ) , V_196 ) ;
if ( ! V_23 -> V_193 )
return - V_146 ;
F_99 ( V_23 -> V_193 , V_353 ,
V_299 -> V_238 ) ;
break;
case V_354 :
if ( ! V_23 -> V_189 )
V_23 -> V_189 = F_76 ( V_30 , V_353 *
sizeof( * V_23 -> V_193 ) , V_196 ) ;
if ( ! V_23 -> V_189 )
return - V_146 ;
F_99 ( V_23 -> V_189 , V_355 ,
V_299 -> V_238 ) ;
break;
case V_356 :
V_23 -> V_357 = V_299 -> V_238 ;
break;
case V_358 :
V_23 -> V_154 = V_299 -> V_238 ;
case V_359 :
V_23 -> V_81 = V_299 -> V_238 ;
break;
case V_360 :
V_23 -> V_85 = V_299 -> V_238 ;
break;
case V_361 :
V_23 -> V_106 = V_299 -> V_238 ;
break;
case V_362 :
V_23 -> V_15 . V_33 =
V_299 -> V_238 ;
break;
case V_343 :
case V_347 :
case V_345 :
case V_346 :
V_86 = F_101 ( V_30 , V_299 , V_36 , V_96 , V_306 ) ;
if ( V_86 < 0 )
return V_86 ;
break;
case V_363 :
V_23 -> V_109 = V_299 -> V_238 ;
break;
case V_364 :
V_23 -> V_78 = V_299 -> V_238 ;
break;
case V_365 :
V_23 -> V_79 = V_299 -> V_238 ;
break;
case V_366 :
V_23 -> V_367 = V_299 -> V_238 ;
break;
case V_368 :
V_86 = F_92 ( V_30 ,
V_23 , V_1 , V_299 ) ;
if ( V_86 < 0 ) {
if ( V_86 == - V_302 ) {
V_348 = 1 ;
break;
}
return V_348 ;
}
break;
case V_369 :
V_282 = V_299 -> V_238 ;
break;
case V_290 :
case V_291 :
case V_293 :
case V_294 :
case V_296 :
case V_297 :
if ( V_348 ) {
V_86 = F_91 ( V_30 , V_23 -> V_27 ,
V_299 -> V_310 , V_299 -> V_238 ) ;
if ( V_86 < 0 )
return V_86 ;
}
break;
case V_289 :
case V_286 :
case V_287 :
case V_288 :
if ( V_23 -> V_27 -> V_162 ) {
V_86 = F_90 ( V_30 , V_23 -> V_27 ,
V_299 -> V_310 , V_299 -> V_238 ,
V_282 , V_96 ) ;
if ( V_86 < 0 )
return V_86 ;
}
break;
case V_370 :
V_23 -> V_145 [ V_282 ] . V_34 = V_299 -> V_238 ;
break;
case V_371 :
V_23 -> V_145 [ V_282 ] . V_99 = V_299 -> V_238 ;
break;
case V_372 :
V_96 = V_299 -> V_238 & V_373 ;
V_306 = ( V_299 -> V_238 &
V_374 ) >> 4 ;
break;
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
case V_319 :
case V_321 :
case V_323 :
V_86 = F_97 ( V_30 , V_44 , V_299 -> V_310 ,
V_299 -> V_238 , V_96 , V_306 ) ;
if ( V_86 < 0 )
return V_86 ;
break;
case V_307 :
case V_308 :
V_86 = F_95 ( V_30 ,
V_23 , V_299 , V_96 ,
V_306 ) ;
if ( V_86 < 0 )
return V_86 ;
break;
case V_375 :
V_23 -> V_101 . V_102 =
V_299 -> V_238 ;
break;
case V_376 :
V_23 -> V_101 . V_125 =
V_299 -> V_238 ;
break;
case V_377 :
V_23 -> V_101 . V_127 =
V_299 -> V_238 ;
break;
case V_378 :
V_23 -> V_379 =
V_299 -> V_238 ;
break;
case V_380 :
V_23 -> V_340 = V_299 -> V_238 ;
break;
case V_381 :
case V_382 :
case V_383 :
break;
default:
F_5 ( V_30 , L_39 ,
V_299 -> V_310 ) ;
return - V_108 ;
}
V_337 ++ ;
return V_337 ;
}
static int F_103 ( struct V_244 * V_30 ,
char * V_384 , struct V_1 * V_1 ,
struct V_22 * V_23 , int V_385 )
{
struct V_386 * V_387 ;
struct V_298 * V_299 ;
int V_337 = 0 , V_86 ;
int V_388 = 0 , V_389 = 0 ;
if ( V_385 <= 0 )
return - V_108 ;
while ( V_389 < V_385 ) {
V_387 = (struct V_386 * ) ( V_384 + V_388 ) ;
V_388 += V_387 -> V_110 ;
switch ( V_387 -> type ) {
case V_390 :
F_104 ( V_30 , L_40 ) ;
continue;
case V_391 :
V_86 = F_98 ( V_30 , V_23 , V_387 -> V_328 ) ;
if ( V_86 < 0 )
return V_86 ;
V_389 += sizeof( * V_387 -> V_328 ) ;
continue;
default:
V_299 = V_387 -> V_238 ;
V_337 = 0 ;
break;
}
while ( V_337 <= ( V_387 -> V_392 - 1 ) ) {
V_86 = F_102 ( V_30 , V_299 ,
V_1 , V_23 ) ;
if ( V_86 < 0 )
return V_86 ;
V_337 = V_337 + V_86 ;
V_299 ++ ;
}
V_389 += V_337 * sizeof( * V_299 ) ;
}
return V_388 ;
}
static int F_105 ( struct V_244 * V_30 ,
struct V_386 * V_387 )
{
struct V_298 * V_299 ;
V_299 = V_387 -> V_238 ;
switch ( V_299 -> V_310 ) {
case V_393 :
case V_394 :
case V_395 :
return V_299 -> V_238 ;
default:
F_5 ( V_30 , L_41 , V_299 -> V_310 ) ;
break;
}
return - V_108 ;
}
static int F_106 ( struct V_396 * V_397 ,
struct V_1 * V_1 , struct V_244 * V_30 ,
struct V_22 * V_23 )
{
struct V_386 * V_387 ;
int V_398 , V_385 = 0 , V_399 , V_388 = 0 ;
char * V_227 ;
int V_86 ;
V_387 = (struct V_386 * ) V_397 -> V_94 . V_227 ;
V_86 = F_105 ( V_30 , V_387 ) ;
if ( V_86 < 0 )
return V_86 ;
V_398 = V_86 ;
V_388 += V_387 -> V_110 ;
while ( V_398 > 0 ) {
V_387 = (struct V_386 * )
( V_397 -> V_94 . V_227 + V_388 ) ;
V_86 = F_105 ( V_30 , V_387 ) ;
if ( V_86 < 0 )
return V_86 ;
V_399 = V_86 ;
V_388 += V_387 -> V_110 ;
V_387 = (struct V_386 * )
( V_397 -> V_94 . V_227 + V_388 ) ;
V_86 = F_105 ( V_30 , V_387 ) ;
if ( V_86 < 0 )
return V_86 ;
V_385 = V_86 ;
V_388 += V_387 -> V_110 ;
V_387 = (struct V_386 * )
( V_397 -> V_94 . V_227 + V_388 ) ;
V_227 = ( V_397 -> V_94 . V_227 + V_388 ) ;
if ( V_399 == V_400 ) {
V_86 = F_103 ( V_30 , V_227 ,
V_1 , V_23 , V_385 ) ;
if ( V_86 < 0 )
return V_86 ;
-- V_398 ;
} else {
if ( V_23 -> V_101 . V_102 > 0 )
memcpy ( V_23 -> V_101 . V_3 , V_227 ,
V_23 -> V_101 . V_102 ) ;
-- V_398 ;
V_86 = V_23 -> V_101 . V_102 ;
}
V_388 += V_86 ;
}
return 0 ;
}
static void F_107 ( struct V_401 * V_402 ,
struct V_13 * V_14 )
{
int V_57 ;
struct V_22 * V_23 ;
struct V_136 * V_27 ;
if ( ! strncmp ( V_14 -> V_221 -> V_403 -> V_115 , V_402 -> V_403 . V_115 ,
strlen ( V_402 -> V_403 . V_115 ) ) ) {
V_23 = V_14 -> V_94 ;
V_27 = V_23 -> V_27 ;
for ( V_57 = 0 ; V_57 < V_23 -> V_37 -> V_192 ; V_57 ++ ) {
V_23 -> V_193 [ V_57 ] . V_311 = false ;
V_23 -> V_193 [ V_57 ] . V_190 = V_312 ;
}
for ( V_57 = 0 ; V_57 < V_23 -> V_37 -> V_188 ; V_57 ++ ) {
V_23 -> V_189 [ V_57 ] . V_311 = false ;
V_23 -> V_189 [ V_57 ] . V_190 = V_312 ;
}
V_27 -> V_211 = V_217 ;
V_23 -> V_151 = V_157 ;
}
}
void F_108 ( struct V_1 * V_1 )
{
struct V_6 * V_24 = V_1 -> V_6 ;
struct V_401 * V_404 = V_1 -> V_402 ;
struct V_13 * V_14 ;
struct V_405 * V_406 ;
if ( V_404 == NULL )
return;
V_406 = V_404 -> V_403 . V_406 ;
if ( ! V_406 || ! V_406 -> V_407 )
return;
V_1 -> V_25 . V_26 = 0 ;
V_1 -> V_25 . V_39 = 0 ;
F_31 (w, &card->widgets, list) {
if ( F_3 ( V_14 ) && ( V_14 -> V_94 != NULL ) )
F_107 ( V_404 , V_14 ) ;
}
F_109 ( V_24 -> V_148 ) ;
}
static int F_110 ( struct V_408 * V_409 ,
struct V_13 * V_14 ,
struct V_396 * V_397 )
{
int V_86 ;
struct V_410 * V_411 = F_111 ( V_409 ) ;
struct V_1 * V_1 = F_112 ( V_411 ) ;
struct V_412 * V_413 = F_113 ( V_411 ) ;
struct V_22 * V_23 ;
if ( ! V_397 -> V_94 . V_110 )
goto V_414;
V_23 = F_76 ( V_413 -> V_30 , sizeof( * V_23 ) , V_196 ) ;
if ( ! V_23 )
return - V_146 ;
if ( V_1 -> V_269 == 0 ) {
V_23 -> V_37 = F_76 ( V_413 -> V_30 ,
sizeof( * V_23 -> V_37 ) , V_196 ) ;
if ( ! V_23 -> V_37 )
return - V_146 ;
}
V_14 -> V_94 = V_23 ;
V_23 -> V_15 . V_32 = - 1 ;
V_86 = F_106 ( V_397 , V_1 , V_413 -> V_30 , V_23 ) ;
if ( V_86 < 0 )
return V_86 ;
F_114 ( V_1 -> V_415 , V_14 , V_23 ) ;
V_414:
if ( V_397 -> V_416 == 0 ) {
F_12 ( V_413 -> V_30 , L_42 ) ;
return 0 ;
}
V_86 = F_115 ( V_14 , V_417 ,
F_78 ( V_417 ) ,
V_397 -> V_416 ) ;
if ( V_86 ) {
F_5 ( V_413 -> V_30 , L_43 ,
V_31 , V_397 -> V_416 ) ;
return - V_108 ;
}
return 0 ;
}
static int F_116 ( struct V_244 * V_30 , struct V_119 * V_418 ,
struct V_419 * V_122 )
{
struct V_121 * V_230 ;
struct V_420 * V_421 =
(struct V_420 * ) V_122 -> V_94 . V_227 ;
V_230 = F_76 ( V_30 , sizeof( * V_230 ) , V_196 ) ;
if ( ! V_230 )
return - V_146 ;
V_230 -> V_195 = V_421 -> V_195 ;
V_230 -> V_127 = V_421 -> V_127 ;
V_230 -> V_125 = V_421 -> V_125 ;
V_230 -> V_110 = V_421 -> V_195 ;
if ( V_230 -> V_195 ) {
V_230 -> V_60 = ( char * ) F_76 ( V_30 , V_230 -> V_195 , V_196 ) ;
if ( ! V_230 -> V_60 )
return - V_146 ;
memcpy ( V_230 -> V_60 , V_421 -> V_60 , V_230 -> V_195 ) ;
}
V_418 -> V_133 . V_134 = V_230 ;
return 0 ;
}
static int F_117 ( struct V_244 * V_30 , struct V_234 * V_422 ,
struct V_423 * V_235 )
{
void * V_227 ;
if ( V_235 -> V_94 . V_110 ) {
V_227 = F_76 ( V_30 , sizeof( V_235 -> V_94 . V_110 ) , V_196 ) ;
if ( ! V_227 )
return - V_146 ;
memcpy ( V_227 , V_235 -> V_94 . V_227 , V_235 -> V_94 . V_110 ) ;
V_422 -> V_133 . V_134 = V_227 ;
}
return 0 ;
}
static int F_118 ( struct V_408 * V_409 ,
struct V_117 * V_424 ,
struct V_425 * V_426 )
{
struct V_119 * V_120 ;
struct V_419 * V_427 ;
struct V_423 * V_428 ;
struct V_410 * V_411 = F_111 ( V_409 ) ;
struct V_412 * V_413 = F_113 ( V_411 ) ;
struct V_234 * V_422 ;
switch ( V_426 -> V_429 . V_430 ) {
case V_431 :
V_427 = F_119 ( V_426 ,
struct V_419 , V_426 ) ;
if ( V_424 -> V_130 & V_131 ) {
V_120 = (struct V_119 * ) V_424 -> V_132 ;
if ( V_427 -> V_94 . V_110 )
return F_116 (
V_413 -> V_30 , V_120 , V_427 ) ;
}
break;
case V_432 :
V_428 = F_119 ( V_426 ,
struct V_423 , V_426 ) ;
if ( V_424 -> V_130 & V_433 ) {
V_422 = (struct V_234 * ) V_424 -> V_132 ;
if ( V_428 -> V_94 . V_110 )
return F_117 ( V_413 -> V_30 , V_422 ,
V_428 ) ;
}
break;
default:
F_104 ( V_413 -> V_30 , L_44 ,
V_426 -> V_429 . V_434 , V_426 -> V_429 . V_435 , V_426 -> V_429 . V_430 ) ;
break;
}
return 0 ;
}
static int F_120 ( struct V_244 * V_30 ,
struct V_436 * V_437 ,
struct V_1 * V_1 )
{
int V_337 = 0 ;
static int V_438 ;
switch ( V_437 -> V_310 ) {
case V_439 :
if ( V_438 > V_1 -> V_6 -> V_440 - 1 ) {
V_438 = 0 ;
return - V_108 ;
}
strncpy ( V_1 -> V_6 -> V_441 [ V_438 ] . V_115 ,
V_437 -> string ,
F_78 ( V_1 -> V_6 -> V_441 [ V_438 ] . V_115 ) ) ;
V_438 ++ ;
break;
default:
F_5 ( V_30 , L_45 , V_437 -> V_310 ) ;
break;
}
V_337 ++ ;
return V_337 ;
}
static int F_121 ( struct V_244 * V_30 ,
struct V_386 * V_387 ,
struct V_1 * V_1 )
{
int V_337 = 0 , V_86 ;
struct V_436 * V_437 ;
V_437 = (struct V_436 * ) V_387 -> V_238 ;
while ( V_337 < V_387 -> V_392 ) {
V_86 = F_120 ( V_30 , V_437 , V_1 ) ;
V_437 ++ ;
if ( V_86 < 0 )
return V_86 ;
V_337 = V_337 + V_86 ;
}
return V_337 ;
}
static int F_122 ( struct V_244 * V_30 ,
struct V_43 * V_47 ,
struct V_298 * V_299 ,
T_2 V_96 , int V_99 )
{
struct V_442 * V_313 ;
struct V_53 * V_443 ;
int V_86 ;
if ( ! V_47 )
return - V_108 ;
switch ( V_96 ) {
case V_284 :
V_313 = & V_47 -> V_46 [ V_99 ] ;
break;
case V_285 :
V_313 = & V_47 -> V_52 [ V_99 ] ;
break;
default:
F_5 ( V_30 , L_29 , V_96 ) ;
return - V_108 ;
}
V_443 = & V_313 -> V_47 ;
switch ( V_299 -> V_310 ) {
case V_444 :
V_313 -> V_15 = V_299 -> V_238 ;
break;
default:
V_86 = F_96 ( V_30 , V_443 , V_299 -> V_310 ,
V_299 -> V_238 ) ;
if ( V_86 < 0 )
return V_86 ;
break;
}
return 0 ;
}
static int F_123 ( struct V_244 * V_30 ,
struct V_298 * V_299 ,
struct V_445 * V_446 )
{
if ( ! V_446 )
return - V_108 ;
switch ( V_299 -> V_310 ) {
case V_381 :
V_446 -> V_447 = V_299 -> V_238 ;
break;
case V_382 :
V_446 -> V_448 = V_299 -> V_238 ;
break;
case V_350 :
V_446 -> V_192 = V_299 -> V_238 ;
break;
case V_351 :
V_446 -> V_188 = V_299 -> V_238 ;
break;
case V_449 :
V_446 -> V_450 = V_299 -> V_238 ;
break;
case V_451 :
V_446 -> V_452 = V_299 -> V_238 ;
break;
default:
F_5 ( V_30 , L_46 , V_299 -> V_310 ) ;
return - V_108 ;
}
return 0 ;
}
static int F_124 ( struct V_244 * V_30 ,
struct V_298 * V_299 ,
struct V_1 * V_1 )
{
int V_337 = 0 , V_86 ;
static int V_453 , V_454 , V_455 , V_96 , V_330 ;
struct V_35 * V_36 = NULL ;
struct V_43 * V_47 = NULL ;
struct V_445 * V_446 = NULL ;
int V_57 ;
if ( V_1 -> V_174 ) {
V_446 = V_1 -> V_174 [ V_453 ] ;
V_36 = & V_446 -> V_38 [ V_454 ] ;
V_47 = & V_446 -> V_45 [ V_455 ] ;
}
switch ( V_299 -> V_310 ) {
case V_456 :
V_1 -> V_6 -> V_440 = V_299 -> V_238 ;
break;
case V_457 :
V_1 -> V_269 = V_299 -> V_238 ;
V_1 -> V_174 = F_125 ( V_30 , V_1 -> V_269 ,
sizeof( * V_1 -> V_174 ) , V_196 ) ;
if ( ! V_1 -> V_174 )
return - V_146 ;
for ( V_57 = 0 ; V_57 < V_1 -> V_269 ; V_57 ++ ) {
V_1 -> V_174 [ V_57 ] = F_76 ( V_30 ,
sizeof( struct V_445 ) , V_196 ) ;
if ( ! V_1 -> V_174 [ V_57 ] )
return - V_146 ;
}
break;
case V_458 :
V_453 = V_299 -> V_238 ;
break;
case V_381 :
case V_382 :
case V_350 :
case V_351 :
case V_449 :
case V_451 :
V_86 = F_123 ( V_30 , V_299 , V_446 ) ;
if ( V_86 < 0 )
return V_86 ;
break;
case V_372 :
V_96 = V_299 -> V_238 & V_373 ;
V_330 = ( V_299 -> V_238 & V_374 ) >> 4 ;
break;
case V_459 :
if ( ! V_36 )
return - V_108 ;
V_36 -> V_15 = V_299 -> V_238 ;
V_454 = V_299 -> V_238 ;
break;
case V_460 :
if ( ! V_47 )
return - V_108 ;
V_47 -> V_99 = V_299 -> V_238 ;
V_455 = V_299 -> V_238 ;
break;
case V_338 :
case V_339 :
case V_341 :
case V_343 :
case V_345 :
case V_346 :
case V_334 :
case V_335 :
V_86 = F_101 ( V_30 , V_299 , V_36 , V_330 , V_96 ) ;
if ( V_86 < 0 )
return V_86 ;
break;
case V_461 :
if ( ! V_47 )
return - V_108 ;
V_36 -> V_462 = V_299 -> V_238 ;
break;
case V_463 :
if ( ! V_47 )
return - V_108 ;
V_36 -> V_464 = V_299 -> V_238 ;
break;
case V_314 :
case V_315 :
case V_316 :
case V_317 :
case V_318 :
case V_319 :
case V_321 :
case V_323 :
case V_444 :
V_86 = F_122 ( V_30 , V_47 , V_299 ,
V_96 , V_330 ) ;
if ( V_86 < 0 )
return V_86 ;
break;
default:
F_5 ( V_30 , L_47 , V_299 -> V_310 ) ;
return - V_108 ;
}
V_337 ++ ;
return V_337 ;
}
static int F_126 ( struct V_244 * V_30 ,
struct V_1 * V_1 ,
struct V_325 * V_326 )
{
static int V_438 ;
struct V_445 * V_446 ;
if ( V_326 -> V_310 == V_327 ) {
V_446 = V_1 -> V_174 [ V_438 ] ;
memcpy ( & V_446 -> V_328 , & V_326 -> V_328 , sizeof( V_326 -> V_328 ) ) ;
V_438 ++ ;
} else {
F_5 ( V_30 , L_35 , V_326 -> V_310 ) ;
return - V_108 ;
}
return 0 ;
}
static int F_127 ( struct V_244 * V_30 ,
char * V_384 , struct V_1 * V_1 ,
int V_385 )
{
int V_337 = 0 , V_86 ;
int V_388 = 0 , V_389 = 0 ;
struct V_386 * V_387 ;
struct V_298 * V_299 ;
if ( V_385 <= 0 )
return - V_108 ;
while ( V_389 < V_385 ) {
V_387 = (struct V_386 * ) ( V_384 + V_388 ) ;
V_388 += V_387 -> V_110 ;
switch ( V_387 -> type ) {
case V_390 :
V_86 = F_121 ( V_30 , V_387 , V_1 ) ;
if ( V_86 < 0 )
return V_86 ;
V_337 = V_86 ;
V_389 += V_337 *
sizeof( struct V_436 ) ;
continue;
case V_391 :
V_86 = F_126 ( V_30 , V_1 , V_387 -> V_328 ) ;
if ( V_86 < 0 )
return V_86 ;
V_389 += sizeof( * V_387 -> V_328 ) ;
continue;
default:
V_299 = V_387 -> V_238 ;
V_337 = 0 ;
break;
}
while ( V_337 <= V_387 -> V_392 - 1 ) {
V_86 = F_124 ( V_30 ,
V_299 , V_1 ) ;
if ( V_86 < 0 )
return V_86 ;
V_337 = V_337 + V_86 ;
V_299 ++ ;
}
V_389 += ( V_337 * sizeof( * V_299 ) ) ;
V_337 = 0 ;
}
return V_388 ;
}
static int F_128 ( struct V_465 * V_466 ,
struct V_244 * V_30 , struct V_1 * V_1 )
{
struct V_386 * V_387 ;
int V_398 , V_385 = 0 , V_399 , V_388 = 0 ;
char * V_227 ;
int V_86 ;
V_387 = (struct V_386 * ) V_466 -> V_94 . V_227 ;
V_86 = F_105 ( V_30 , V_387 ) ;
if ( V_86 < 0 )
return V_86 ;
V_398 = V_86 ;
V_388 += V_387 -> V_110 ;
while ( V_398 > 0 ) {
V_387 = (struct V_386 * )
( V_466 -> V_94 . V_227 + V_388 ) ;
V_86 = F_105 ( V_30 , V_387 ) ;
if ( V_86 < 0 )
return V_86 ;
V_399 = V_86 ;
V_388 += V_387 -> V_110 ;
V_387 = (struct V_386 * )
( V_466 -> V_94 . V_227 + V_388 ) ;
V_86 = F_105 ( V_30 , V_387 ) ;
if ( V_86 < 0 )
return V_86 ;
V_385 = V_86 ;
V_388 += V_387 -> V_110 ;
V_387 = (struct V_386 * )
( V_466 -> V_94 . V_227 + V_388 ) ;
V_227 = ( V_466 -> V_94 . V_227 + V_388 ) ;
if ( V_399 == V_400 ) {
V_86 = F_127 ( V_30 , V_227 , V_1 ,
V_385 ) ;
if ( V_86 < 0 )
return V_86 ;
-- V_398 ;
} else {
return - V_108 ;
}
V_388 += V_86 ;
}
return 0 ;
}
static int F_129 ( struct V_408 * V_409 ,
struct V_465 * V_466 )
{
struct V_410 * V_411 = F_111 ( V_409 ) ;
struct V_412 * V_413 = F_113 ( V_411 ) ;
struct V_1 * V_1 = F_112 ( V_411 ) ;
if ( V_466 -> V_94 . V_110 == 0 )
return 0 ;
F_128 ( V_466 , V_413 -> V_30 , V_1 ) ;
if ( V_1 -> V_6 -> V_440 > V_467 ) {
F_5 ( V_413 -> V_30 , L_48 ,
V_1 -> V_6 -> V_440 ) ;
return - V_108 ;
}
return 0 ;
}
static int F_130 ( struct V_401 * V_402 )
{
struct V_13 * V_14 ;
struct V_22 * V_42 = NULL ;
struct V_139 * V_468 = NULL ;
struct V_136 * V_27 ;
F_31 (w, &platform->component.card->widgets, list) {
if ( F_3 ( V_14 ) && V_14 -> V_94 != NULL ) {
V_42 = V_14 -> V_94 ;
V_27 = V_42 -> V_27 ;
V_468 = F_76 ( V_402 -> V_30 ,
sizeof( * V_468 ) , V_196 ) ;
if ( ! V_468 )
return - V_146 ;
V_468 -> V_14 = V_14 ;
F_131 ( & V_468 -> V_201 , & V_27 -> V_303 ) ;
}
}
return 0 ;
}
static void F_132 ( struct V_1 * V_1 , struct V_136 * V_27 )
{
struct V_139 * V_140 ;
struct V_13 * V_14 ;
struct V_22 * V_23 ;
bool V_469 = false , V_470 = false ;
F_31 (w_module, &pipe->w_list, node) {
V_14 = V_140 -> V_14 ;
V_23 = V_14 -> V_94 ;
if ( V_23 -> V_85 == V_137 )
V_469 = true ;
else if ( V_23 -> V_85 != V_471 )
V_470 = true ;
}
if ( V_469 && V_470 )
V_27 -> V_262 = true ;
else
V_27 -> V_262 = false ;
}
int F_133 ( struct V_401 * V_402 , struct V_410 * V_411 )
{
int V_86 ;
const struct V_472 * V_473 ;
struct V_412 * V_413 = F_113 ( V_411 ) ;
struct V_1 * V_1 = F_112 ( V_411 ) ;
struct V_300 * V_301 ;
V_86 = F_134 ( & V_473 , V_1 -> V_474 , V_413 -> V_30 ) ;
if ( V_86 < 0 ) {
F_5 ( V_413 -> V_30 , L_49 ,
V_1 -> V_474 , V_86 ) ;
V_86 = F_134 ( & V_473 , L_50 , V_413 -> V_30 ) ;
if ( V_86 < 0 ) {
F_5 ( V_413 -> V_30 , L_51 ,
L_50 , V_86 ) ;
return V_86 ;
}
}
V_86 = F_135 ( & V_402 -> V_403 ,
& V_475 , V_473 , 0 ) ;
if ( V_86 < 0 ) {
F_5 ( V_413 -> V_30 , L_52 , V_86 ) ;
F_136 ( V_473 ) ;
return - V_108 ;
}
V_1 -> V_25 . V_41 = V_476 ;
V_1 -> V_25 . V_29 = V_477 ;
V_1 -> V_478 = V_473 ;
V_86 = F_130 ( V_402 ) ;
if ( V_86 < 0 )
return V_86 ;
F_31 (ppl, &skl->ppl_list, node)
F_132 ( V_1 , V_301 -> V_27 ) ;
return 0 ;
}
