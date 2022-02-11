static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( L_1 , V_6 , V_4 -> V_7 ) ;
F_4 ( V_4 -> V_7 ) ;
F_5 ( V_4 ) ;
}
static struct V_3 * F_6 ( const struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_7 ( V_9 -> V_12 , V_9 -> V_13 , V_11 ) ;
if ( ! V_2 )
return NULL ;
V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
return V_4 ;
}
static struct V_3 *
F_8 ( const struct V_8 * V_9 ,
const struct V_10 * V_11 , struct V_14 * V_7 ,
T_1 V_15 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_9 ( sizeof( * V_4 ) , V_15 ) ;
struct V_3 * V_16 ;
if ( ! V_4 ) {
F_3 ( L_2 , V_6 , V_7 ) ;
return NULL ;
}
F_3 ( L_3 , V_6 , V_7 ) ;
F_10 ( & V_4 -> V_5 ,
V_9 -> V_12 ,
V_9 -> V_13 ,
V_11 ) ;
V_4 -> V_7 = V_7 ;
V_2 = F_11 ( & V_4 -> V_5 ) ;
V_16 = F_2 ( V_2 , struct V_3 , V_5 ) ;
if ( V_16 != V_4 ) {
F_3 ( L_4 , V_6 , V_16 -> V_7 ) ;
F_1 ( & V_4 -> V_5 ) ;
V_4 = V_16 ;
}
return V_4 ;
}
static inline struct V_17 *
F_12 ( struct V_18 * V_19 )
{
return F_2 ( V_19 , struct V_17 , V_19 ) ;
}
static struct V_3 * F_13 ( struct V_20 * V_21 ,
struct V_17 * V_22 , unsigned V_23 ,
T_1 V_15 )
{
struct V_24 * V_25 ;
struct V_10 * V_11 ;
struct V_3 * V_26 ;
struct V_14 * V_7 ;
struct V_27 V_28 ;
int V_29 ;
V_11 = & V_22 -> V_30 [ V_23 ] . V_31 . V_32 ;
V_26 = F_6 ( F_14 ( V_21 -> V_33 ) , V_11 ) ;
if ( V_26 )
return V_26 ;
V_29 = F_15 ( V_21 , V_11 , & V_25 , V_15 ) ;
if ( F_16 ( V_29 ) ) {
F_3 ( L_5 ,
V_6 , F_17 ( V_11 ) , F_18 ( V_11 ) , V_29 ) ;
return F_19 ( V_29 ) ;
}
V_28 . V_34 = V_25 -> V_35 . V_36 ;
if ( V_28 . V_34 > sizeof( V_28 . V_37 ) ) {
V_29 = - V_38 ;
goto V_39;
} else if ( V_28 . V_34 )
memcpy ( V_28 . V_37 , V_25 -> V_35 . V_40 ,
V_28 . V_34 ) ;
V_28 . V_41 = V_25 -> V_42 . V_36 ;
V_28 . V_43 = ( V_44 * ) V_25 -> V_42 . V_40 ;
if ( ! V_28 . V_41 && ! V_28 . V_34 ) {
F_3 ( L_6 ,
V_6 ) ;
V_29 = - V_45 ;
goto V_39;
}
V_7 = F_20 ( & V_28 ) ;
if ( F_16 ( F_21 ( V_7 ) ) ) {
V_29 = F_22 ( V_7 ) ;
F_3 ( L_7 , V_6 , V_29 ) ;
goto V_39;
}
V_26 = F_8 ( F_14 ( V_21 -> V_33 ) , V_11 , V_7 ,
V_15 ) ;
V_39:
F_3 ( L_8 , V_6 , V_29 ) ;
F_23 ( V_25 ) ;
return V_29 ? F_19 ( V_29 ) : V_26 ;
}
static int F_24 ( struct V_20 * V_21 ,
struct V_17 * V_22 ,
T_1 V_15 )
{
unsigned V_46 ;
int V_29 ;
for ( V_46 = 0 ; V_46 < V_22 -> V_47 ; V_46 ++ ) {
struct V_3 * V_26 ;
V_26 = F_13 ( V_21 , V_22 , V_46 , V_15 ) ;
if ( F_16 ( F_21 ( V_26 ) ) ) {
V_29 = F_22 ( V_26 ) ;
goto V_39;
}
V_22 -> V_48 [ V_46 ] = V_26 ;
}
V_29 = 0 ;
V_39:
F_3 ( L_8 , V_6 , V_29 ) ;
return V_29 ;
}
static int F_25 ( struct V_49 * V_50 )
{
struct V_51 * V_52 = & V_50 -> V_53 ;
T_2 V_54 ;
T_3 V_55 ;
if ( V_52 -> V_56 != V_57 ) {
F_26 ( V_58 L_9 ) ;
return - V_59 ;
}
if ( 0 != ( V_52 -> V_60 % ( V_52 -> V_61 + 1 ) ) ) {
F_26 ( V_58 L_10 ,
V_52 -> V_60 , V_52 -> V_61 ) ;
return - V_38 ;
}
if ( V_52 -> V_62 )
V_55 = V_52 -> V_62 ;
else
V_55 = V_52 -> V_60 /
( V_52 -> V_61 + 1 ) ;
V_54 = ( T_2 ) V_52 -> V_63 * V_55 ;
if ( V_54 >= ( 1ULL << 32 ) ) {
F_26 ( V_58 L_11
L_12 , F_27 ( V_54 ) ) ;
return - V_59 ;
}
if ( 0 != ( V_52 -> V_63 & ~ V_64 ) ) {
F_26 ( V_58 L_13
L_14 ,
F_27 ( V_52 -> V_63 ) , V_65 ) ;
return - V_59 ;
}
return 0 ;
}
static void F_28 ( struct V_66 * V_67 ,
struct V_66 * V_68 ,
struct V_69 * V_70 )
{
F_29 ( V_68 -> V_71 . V_72 > sizeof( V_70 -> V_73 ) ) ;
F_29 ( V_68 -> V_74 . V_72 > sizeof( V_70 -> V_75 ) ) ;
* V_67 = * V_68 ;
memcpy ( V_70 -> V_73 , V_68 -> V_71 . V_76 ,
sizeof( V_70 -> V_73 ) ) ;
V_67 -> V_71 . V_76 = V_70 -> V_73 ;
memcpy ( V_70 -> V_75 , V_68 -> V_74 . V_76 ,
sizeof( V_70 -> V_75 ) ) ;
V_67 -> V_74 . V_76 = V_70 -> V_75 ;
}
int F_30 ( struct V_18 * * V_77 ,
struct V_20 * V_21 ,
struct V_78 * V_79 ,
struct V_80 * V_81 ,
T_1 V_15 )
{
struct V_17 * V_22 ;
struct V_82 V_83 ;
struct V_49 V_50 ;
struct V_66 * V_67 , V_68 ;
struct V_69 * V_70 ;
int V_29 ;
V_29 = F_31 ( & V_50 , & V_83 , V_81 ) ;
if ( F_16 ( V_29 ) )
return V_29 ;
V_29 = F_25 ( & V_50 ) ;
if ( F_16 ( V_29 ) )
return V_29 ;
V_22 = F_9 ( sizeof( * V_22 ) +
sizeof( V_22 -> V_48 [ 0 ] ) * V_50 . V_84 +
sizeof( * V_22 -> V_30 ) * V_50 . V_84 +
sizeof( struct V_69 ) * V_50 . V_84 ,
V_15 ) ;
if ( ! V_22 )
return - V_85 ;
V_22 -> V_30 = ( void * ) ( V_22 -> V_48 + V_50 . V_84 ) ;
V_67 = V_22 -> V_30 ;
V_70 = ( void * ) ( V_67 + V_50 . V_84 ) ;
while ( F_32 ( & V_68 , & V_83 , V_81 , & V_29 ) )
F_28 ( V_67 ++ , & V_68 , V_70 ++ ) ;
if ( F_16 ( V_29 ) )
goto V_29;
V_22 -> V_47 = V_50 . V_84 ;
V_22 -> V_86 = V_50 . V_87 ;
V_29 = F_24 ( V_21 , V_22 , V_15 ) ;
if ( V_29 )
goto V_29;
V_22 -> V_88 = V_50 . V_53 . V_61 + 1 ;
V_22 -> V_89 = V_50 . V_53 . V_63 ;
if ( V_50 . V_53 . V_62 ) {
V_22 -> V_55 = V_50 . V_53 . V_62 ;
V_22 -> V_90 = V_50 . V_53 . V_91 ;
V_22 -> V_92 = V_50 . V_53 . V_60 /
V_22 -> V_88 /
V_22 -> V_55 ;
} else {
V_22 -> V_55 = V_50 . V_53 . V_60 /
V_22 -> V_88 ;
V_22 -> V_90 = - 1 ;
V_22 -> V_92 = 1 ;
}
V_22 -> V_93 = ( V_94 * V_65 -
V_22 -> V_89 ) *
V_22 -> V_55 ;
* V_77 = & V_22 -> V_19 ;
return 0 ;
V_29:
F_5 ( V_22 ) ;
F_3 ( L_15 , V_6 , V_29 ) ;
* V_77 = NULL ;
return V_29 ;
}
void F_33 ( struct V_18 * V_19 )
{
int V_46 ;
struct V_17 * V_22 = F_12 ( V_19 ) ;
for ( V_46 = 0 ; V_46 < V_22 -> V_47 ; V_46 ++ ) {
if ( ! V_22 -> V_48 [ V_46 ] )
break;
F_34 ( & V_22 -> V_48 [ V_46 ] -> V_5 ) ;
}
F_5 ( V_22 ) ;
}
int F_35 ( struct V_18 * V_19 ,
struct V_95 * * V_77 ,
T_1 V_15 )
{
struct V_17 * V_22 = F_12 ( V_19 ) ;
struct V_96 * V_97 ;
const unsigned V_98 = sizeof( * V_97 ) +
V_22 -> V_47 * sizeof( V_97 -> V_99 [ 0 ] ) ;
const unsigned V_100 = V_22 -> V_47 *
sizeof( V_97 -> V_101 . V_102 [ 0 ] ) ;
V_97 = F_9 ( V_98 + V_100 , V_15 ) ;
if ( F_16 ( ! V_97 ) )
return - V_85 ;
V_97 -> V_50 = V_22 ;
V_97 -> V_101 . V_102 = ( ( void * ) V_97 ) + V_98 ;
V_97 -> V_101 . V_47 = V_22 -> V_47 ;
* V_77 = & V_97 -> V_101 ;
return 0 ;
}
void F_36 ( struct V_95 * V_101 )
{
struct V_96 * V_97 = F_2 ( V_101 , struct V_96 ,
V_101 ) ;
F_5 ( V_97 ) ;
}
enum V_103 F_37 ( enum V_104 V_105 )
{
switch ( V_105 ) {
case V_106 :
return (enum V_103 ) 0 ;
case V_107 :
F_38 ( 1 ) ;
return 0 ;
case V_108 :
return V_109 ;
case V_110 :
return V_111 ;
case V_112 :
return V_113 ;
case V_114 :
return V_115 ;
case V_116 :
return V_117 ;
case V_118 :
return V_119 ;
default:
F_29 ( 1 ) ;
case V_120 :
return V_121 ;
}
}
static void F_39 ( struct V_122 * V_122 )
{
struct V_123 * V_124 ;
unsigned V_46 ;
F_40 (bv, bio, i, 0 ) {
unsigned V_125 = V_124 -> V_126 ;
if ( F_41 ( V_65 == V_125 ) )
F_42 ( V_124 -> V_127 ) ;
else
F_43 ( V_124 -> V_127 , V_124 -> V_128 , V_125 ) ;
}
}
static int F_44 ( struct V_96 * V_97 , bool V_129 )
{
enum V_104 V_105 = V_106 ;
int V_130 = 0 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < V_97 -> V_131 ; V_46 ++ ) {
struct V_132 V_133 ;
struct V_134 * V_135 = V_97 -> V_99 [ V_46 ] . V_135 ;
int V_136 ;
if ( ! V_135 )
continue;
V_136 = F_45 ( V_135 , & V_133 ) ;
if ( F_41 ( ! V_136 ) )
continue;
if ( V_107 == V_133 . V_137 ) {
F_38 ( V_129 ) ;
F_39 ( V_97 -> V_99 [ V_46 ] . V_122 ) ;
F_3 ( L_16
L_17 , V_6 ,
F_27 ( V_97 -> V_99 [ V_46 ] . V_138 ) ,
V_97 -> V_99 [ V_46 ] . V_139 ) ;
continue;
}
F_46 ( & V_97 -> V_101 , V_46 ,
& V_97 -> V_50 -> V_30 [ V_46 ] . V_31 ,
F_37 ( V_133 . V_137 ) ,
V_97 -> V_99 [ V_46 ] . V_138 ,
V_97 -> V_99 [ V_46 ] . V_139 ,
V_129 ) ;
if ( V_133 . V_137 >= V_105 ) {
V_105 = V_133 . V_137 ;
V_130 = V_136 ;
}
}
return V_130 ;
}
static void F_47 ( struct V_96 * V_97 )
{
unsigned V_46 ;
for ( V_46 = 0 ; V_46 < V_97 -> V_131 ; V_46 ++ ) {
struct V_140 * V_99 = & V_97 -> V_99 [ V_46 ] ;
if ( V_99 -> V_135 ) {
F_48 ( V_99 -> V_135 ) ;
V_99 -> V_135 = NULL ;
}
if ( V_99 -> V_122 ) {
F_49 ( V_99 -> V_122 ) ;
V_99 -> V_122 = NULL ;
}
}
}
struct V_14 * F_50 ( struct V_96 * V_97 , unsigned V_141 )
{
unsigned V_142 = V_97 -> V_50 -> V_86 ;
unsigned V_143 = V_142 + V_97 -> V_50 -> V_47 ;
F_38 ( V_141 < V_142 || V_143 <= V_141 ) ;
return V_97 -> V_50 -> V_48 [ V_141 - V_142 ] -> V_7 ;
}
static void F_51 ( struct V_96 * V_97 , T_2 V_144 ,
struct V_145 * V_146 )
{
T_3 V_89 = V_97 -> V_50 -> V_89 ;
T_3 V_55 = V_97 -> V_50 -> V_55 ;
T_2 V_90 = V_97 -> V_50 -> V_90 ;
T_3 V_147 = V_89 * V_55 ;
T_2 V_148 = V_147 * V_90 ;
T_2 V_149 = V_148 * V_97 -> V_50 -> V_92 ;
T_2 V_150 = F_52 ( V_144 , V_149 ) ;
T_2 V_151 = V_144 - V_150 * V_149 ;
T_3 V_152 = F_52 ( V_151 , V_148 ) ;
T_2 V_153 = V_151 - V_152 * V_148 ;
T_3 V_154 = F_53 ( V_153 , V_147 ) ;
F_54 ( V_144 , V_89 , & V_146 -> V_155 ) ;
V_146 -> V_156 = V_146 -> V_155 + ( V_154 * V_89 ) +
( V_150 * V_90 * V_89 ) ;
V_146 -> V_141 = ( T_3 ) ( V_153 - ( V_154 * V_147 ) ) / V_89 + V_152 * V_55 ;
V_146 -> V_141 *= V_97 -> V_50 -> V_88 ;
V_146 -> V_157 = V_148 - V_153 ;
}
static int F_55 ( struct V_96 * V_97 , unsigned * V_158 ,
unsigned V_159 , struct V_140 * V_99 , int V_36 ,
T_1 V_15 )
{
unsigned V_160 = * V_158 ;
int V_161 = V_36 ;
struct V_162 * V_163 =
F_56 ( F_50 ( V_97 , V_99 -> V_141 ) ) ;
if ( V_99 -> V_122 == NULL ) {
unsigned V_164 = V_97 -> V_50 -> V_55 *
( V_97 -> V_50 -> V_89 / V_65 ) ;
unsigned V_165 = ( V_97 -> V_101 . V_166 + V_164 ) /
V_97 -> V_50 -> V_55 ;
if ( V_94 < V_165 )
V_165 = V_94 ;
V_99 -> V_122 = F_57 ( V_15 , V_165 ) ;
if ( F_16 ( ! V_99 -> V_122 ) ) {
F_3 ( L_18 , V_165 ) ;
return - V_85 ;
}
}
while ( V_161 > 0 ) {
unsigned V_167 = F_58 ( unsigned , V_65 - V_159 , V_161 ) ;
unsigned V_168 ;
F_38 ( V_97 -> V_101 . V_166 <= V_160 ) ;
V_161 -= V_167 ;
V_168 = F_59 ( V_163 , V_99 -> V_122 ,
V_97 -> V_101 . V_169 [ V_160 ] , V_167 , V_159 ) ;
if ( F_16 ( V_167 != V_168 ) )
return - V_85 ;
V_159 = 0 ;
++ V_160 ;
}
F_38 ( V_161 ) ;
V_99 -> V_139 += V_36 ;
* V_158 = V_160 ;
return 0 ;
}
static int F_60 ( struct V_96 * V_97 , T_2 V_139 ,
struct V_145 * V_146 , unsigned * V_170 ,
T_1 V_15 )
{
unsigned V_89 = V_97 -> V_50 -> V_89 ;
unsigned V_88 = V_97 -> V_50 -> V_88 ;
unsigned V_171 = V_97 -> V_50 -> V_55 * V_88 ;
unsigned V_141 = V_146 -> V_141 ;
unsigned V_172 = V_141 - ( V_141 % V_171 ) ;
unsigned V_173 = V_97 -> V_131 ? V_97 -> V_131 - V_88 : 0 ;
unsigned V_158 = * V_170 ;
int V_136 = 0 ;
while ( V_139 ) {
struct V_140 * V_99 = & V_97 -> V_99 [ V_141 - V_172 ] ;
unsigned V_161 , V_174 = 0 ;
if ( ! V_99 -> V_139 ) {
V_99 -> V_141 = V_141 ;
if ( V_141 < V_146 -> V_141 ) {
V_99 -> V_138 = V_146 -> V_156 + V_89 -
V_146 -> V_155 ;
V_161 = V_89 ;
} else if ( V_141 == V_146 -> V_141 ) {
V_99 -> V_138 = V_146 -> V_156 ;
V_161 = V_89 - V_146 -> V_155 ;
V_174 = V_146 -> V_155 & ~ V_64 ;
F_38 ( V_174 &&
( V_174 != V_97 -> V_101 . V_159 ) ) ;
} else {
V_99 -> V_138 = V_146 -> V_156 - V_146 -> V_155 ;
V_161 = V_89 ;
}
if ( V_173 < V_141 - V_172 )
V_173 = V_141 - V_172 ;
} else {
V_161 = V_89 ;
}
if ( V_161 >= V_139 )
V_161 = V_139 ;
V_136 = F_55 ( V_97 , & V_158 , V_174 , V_99 ,
V_161 , V_15 ) ;
if ( F_16 ( V_136 ) )
goto V_39;
V_141 += V_88 ;
V_141 = ( V_141 % V_171 ) + V_172 ;
V_139 -= V_161 ;
V_97 -> V_139 += V_161 ;
}
V_39:
V_97 -> V_131 = V_173 + V_88 ;
* V_170 = V_158 ;
return V_136 ;
}
static int F_61 ( struct V_96 * V_97 , T_1 V_15 )
{
T_2 V_139 = V_97 -> V_101 . V_175 ;
T_2 V_138 = V_97 -> V_101 . V_138 ;
struct V_145 V_146 ;
unsigned V_170 = 0 ;
int V_136 = 0 ;
while ( V_139 ) {
F_51 ( V_97 , V_138 , & V_146 ) ;
if ( V_139 < V_146 . V_157 )
V_146 . V_157 = V_139 ;
V_136 = F_60 ( V_97 , V_146 . V_157 , & V_146 , & V_170 , V_15 ) ;
if ( F_16 ( V_136 ) )
goto V_39;
V_138 += V_146 . V_157 ;
V_139 -= V_146 . V_157 ;
}
V_39:
if ( ! V_97 -> V_139 )
return V_136 ;
return 0 ;
}
static T_4 F_62 ( struct V_96 * V_97 )
{
struct V_176 * V_177 = V_97 -> V_178 ;
F_63 ( V_177 ) ;
return 0 ;
}
static void F_64 ( struct V_179 * V_179 )
{
struct V_96 * V_97 = F_2 ( V_179 , struct V_96 , V_179 ) ;
V_97 -> V_180 ( V_97 ) ;
}
static void F_65 ( struct V_134 * V_135 , void * V_181 )
{
struct V_96 * V_97 = V_181 ;
F_66 ( & V_97 -> V_179 , F_64 ) ;
}
static T_4 F_67 ( struct V_96 * V_97 )
{
F_68 ( V_182 ) ;
T_4 V_183 = 0 ;
unsigned V_46 ;
T_5 V_184 = V_97 -> V_180 ;
bool V_185 = V_97 -> V_101 . V_185 ;
if ( V_185 ) {
V_97 -> V_180 = F_62 ;
V_97 -> V_178 = & V_182 ;
}
F_69 ( & V_97 -> V_179 ) ;
for ( V_46 = 0 ; V_46 < V_97 -> V_131 ; V_46 ++ ) {
struct V_134 * V_135 = V_97 -> V_99 [ V_46 ] . V_135 ;
if ( ! V_135 )
continue;
F_70 ( & V_97 -> V_179 ) ;
F_71 ( V_135 , F_65 , V_97 ) ;
}
F_66 ( & V_97 -> V_179 , F_64 ) ;
if ( V_185 ) {
F_72 ( & V_182 ) ;
V_183 = V_184 ( V_97 ) ;
}
return V_183 ;
}
static T_4 F_73 ( struct V_96 * V_97 )
{
T_4 V_183 ;
int V_136 = F_44 ( V_97 , false ) ;
F_47 ( V_97 ) ;
if ( F_41 ( ! V_136 ) )
V_183 = V_97 -> V_139 ;
else
V_183 = V_136 ;
F_74 ( & V_97 -> V_101 , V_183 , V_97 -> V_101 . V_185 ) ;
return V_183 ;
}
static int F_75 ( struct V_96 * V_97 , unsigned V_67 )
{
struct V_134 * V_135 = NULL ;
struct V_140 * V_99 = & V_97 -> V_99 [ V_67 ] ;
unsigned V_141 = V_99 -> V_141 ;
struct V_66 * V_76 =
& V_97 -> V_50 -> V_30 [ V_67 ] ;
struct V_186 V_187 = {
. V_188 = V_76 -> V_31 . V_189 ,
. V_190 = V_76 -> V_31 . V_191 ,
} ;
int V_136 ;
V_135 = F_76 ( F_50 ( V_97 , V_141 ) , V_192 ) ;
if ( F_16 ( ! V_135 ) ) {
V_136 = - V_85 ;
goto V_29;
}
V_99 -> V_135 = V_135 ;
F_77 ( V_135 , & V_187 , V_99 -> V_138 , V_99 -> V_122 , V_99 -> V_139 ) ;
V_136 = F_78 ( V_135 , 0 , V_76 -> V_74 . V_76 , NULL ) ;
if ( V_136 ) {
F_3 ( L_19 ,
V_6 , V_136 ) ;
goto V_29;
}
F_3 ( L_20 ,
V_6 , V_67 , V_141 , V_187 . V_190 , F_27 ( V_99 -> V_138 ) ,
V_99 -> V_139 ) ;
V_29:
return V_136 ;
}
static T_4 F_79 ( struct V_96 * V_97 )
{
unsigned V_46 ;
int V_136 ;
for ( V_46 = 0 ; V_46 < V_97 -> V_131 ; V_46 += V_97 -> V_50 -> V_88 ) {
if ( ! V_97 -> V_99 [ V_46 ] . V_139 )
continue;
V_136 = F_75 ( V_97 , V_46 ) ;
if ( F_16 ( V_136 ) )
goto V_29;
}
V_97 -> V_180 = F_73 ;
return F_67 ( V_97 ) ;
V_29:
F_47 ( V_97 ) ;
return V_136 ;
}
T_4 F_80 ( struct V_95 * V_101 )
{
struct V_96 * V_97 = F_2 ( V_101 , struct V_96 ,
V_101 ) ;
int V_136 ;
V_136 = F_61 ( V_97 , V_192 ) ;
if ( F_16 ( V_136 ) )
return V_136 ;
return F_79 ( V_97 ) ;
}
static T_4 F_81 ( struct V_96 * V_97 )
{
T_4 V_183 ;
int V_136 = F_44 ( V_97 , true ) ;
F_47 ( V_97 ) ;
if ( F_41 ( ! V_136 ) ) {
V_97 -> V_101 . V_193 = V_194 ;
V_183 = V_97 -> V_139 ;
} else {
V_183 = V_136 ;
}
F_82 ( & V_97 -> V_101 , V_183 , V_97 -> V_101 . V_185 ) ;
return V_183 ;
}
static int F_83 ( struct V_96 * V_97 , unsigned V_67 )
{
struct V_140 * V_195 = & V_97 -> V_99 [ V_67 ] ;
unsigned V_141 = V_97 -> V_99 [ V_67 ] . V_141 ;
unsigned V_196 = V_67 + V_97 -> V_50 -> V_88 ;
int V_136 ;
for (; V_67 < V_196 ; ++ V_67 , ++ V_141 ) {
struct V_134 * V_135 = NULL ;
struct V_66 * V_76 =
& V_97 -> V_50 -> V_30 [ V_67 ] ;
struct V_186 V_187 = {
. V_188 = V_76 -> V_31 . V_189 ,
. V_190 = V_76 -> V_31 . V_191 ,
} ;
struct V_140 * V_99 = & V_97 -> V_99 [ V_67 ] ;
struct V_122 * V_122 ;
V_135 = F_76 ( F_50 ( V_97 , V_141 ) , V_197 ) ;
if ( F_16 ( ! V_135 ) ) {
V_136 = - V_85 ;
goto V_29;
}
V_99 -> V_135 = V_135 ;
if ( V_99 != V_195 ) {
V_122 = F_57 ( V_197 ,
V_195 -> V_122 -> V_198 ) ;
if ( F_16 ( ! V_122 ) ) {
F_3 ( L_18 ,
V_195 -> V_122 -> V_198 ) ;
V_136 = - V_85 ;
goto V_29;
}
F_84 ( V_122 , V_195 -> V_122 ) ;
V_122 -> V_199 = NULL ;
V_122 -> V_200 = NULL ;
V_99 -> V_122 = V_122 ;
V_99 -> V_141 = V_141 ;
V_99 -> V_139 = V_195 -> V_139 ;
V_99 -> V_138 = V_195 -> V_138 ;
} else {
V_122 = V_195 -> V_122 ;
V_122 -> V_201 |= V_202 ;
}
F_85 ( V_135 , & V_187 , V_99 -> V_138 , V_122 , V_99 -> V_139 ) ;
V_136 = F_78 ( V_135 , 0 , V_76 -> V_74 . V_76 , NULL ) ;
if ( V_136 ) {
F_3 ( L_19 ,
V_6 , V_136 ) ;
goto V_29;
}
F_3 ( L_20 ,
V_6 , V_67 , V_141 , V_187 . V_190 , F_27 ( V_99 -> V_138 ) ,
V_99 -> V_139 ) ;
}
V_29:
return V_136 ;
}
static T_4 F_86 ( struct V_96 * V_97 )
{
unsigned V_46 ;
int V_136 ;
for ( V_46 = 0 ; V_46 < V_97 -> V_131 ; V_46 += V_97 -> V_50 -> V_88 ) {
if ( ! V_97 -> V_99 [ V_46 ] . V_139 )
continue;
V_136 = F_83 ( V_97 , V_46 ) ;
if ( F_16 ( V_136 ) )
goto V_29;
}
V_97 -> V_180 = F_81 ;
return F_67 ( V_97 ) ;
V_29:
F_47 ( V_97 ) ;
return V_136 ;
}
T_4 F_87 ( struct V_95 * V_101 , bool V_203 )
{
struct V_96 * V_97 = F_2 ( V_101 , struct V_96 ,
V_101 ) ;
int V_136 ;
V_136 = F_61 ( V_97 , V_197 ) ;
if ( F_16 ( V_136 ) )
return V_136 ;
return F_86 ( V_97 ) ;
}
static bool F_88 ( struct V_204 * V_205 ,
struct V_206 * V_207 , struct V_206 * V_208 )
{
if ( ! F_89 ( V_205 , V_207 , V_208 ) )
return false ;
return V_205 -> V_209 + V_208 -> V_210 <=
F_12 ( V_205 -> V_211 ) -> V_93 ;
}
static int T_6
F_90 ( void )
{
int V_136 = F_91 ( & V_212 ) ;
if ( V_136 )
F_26 ( V_213
L_21 ,
V_6 , V_136 ) ;
else
F_26 ( V_213 L_22 ,
V_6 ) ;
return V_136 ;
}
static void T_7
F_92 ( void )
{
F_93 ( & V_212 ) ;
F_26 ( V_213 L_23 ,
V_6 ) ;
}
