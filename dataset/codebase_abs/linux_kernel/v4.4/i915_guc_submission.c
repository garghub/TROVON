static inline bool F_1 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
T_1 V_4 = F_2 ( F_3 ( 0 ) ) ;
* V_3 = V_4 ;
return F_4 ( V_4 ) ;
}
static int F_5 ( struct V_5 * V_6 , T_1 * V_7 , T_1 V_8 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
T_1 V_3 ;
int V_9 ;
int V_10 ;
if ( F_7 ( V_8 < 1 || V_8 > 15 ) )
return - V_11 ;
F_8 ( V_2 , V_12 ) ;
F_9 ( & V_2 -> V_6 . V_13 ) ;
V_2 -> V_6 . V_14 += 1 ;
V_2 -> V_6 . V_15 = V_7 [ 0 ] ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
F_10 ( F_3 ( V_9 ) , V_7 [ V_9 ] ) ;
F_11 ( F_3 ( V_9 - 1 ) ) ;
F_10 ( V_16 , V_17 ) ;
V_10 = F_12 ( F_1 ( V_2 , & V_3 ) , 10 ) ;
if ( V_3 != V_18 ) {
if ( V_10 != - V_19 )
V_10 = - V_20 ;
F_13 ( L_1
L_2 ,
V_7 [ 0 ] , V_10 , V_3 ,
F_2 ( F_3 ( 15 ) ) ) ;
V_2 -> V_6 . V_21 += 1 ;
V_2 -> V_6 . V_22 = V_10 ;
}
V_2 -> V_6 . V_23 = V_3 ;
F_14 ( & V_2 -> V_6 . V_13 ) ;
F_15 ( V_2 , V_12 ) ;
return V_10 ;
}
static int F_16 ( struct V_5 * V_6 ,
struct V_24 * V_25 )
{
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_26 ;
V_7 [ 1 ] = V_25 -> V_27 ;
return F_5 ( V_6 , V_7 , 2 ) ;
}
static int F_17 ( struct V_5 * V_6 ,
struct V_24 * V_25 )
{
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_28 ;
V_7 [ 1 ] = V_25 -> V_27 ;
return F_5 ( V_6 , V_7 , 2 ) ;
}
static int F_18 ( struct V_5 * V_6 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_29 * V_30 = V_2 -> V_30 ;
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_31 ;
if ( ! F_19 ( V_2 -> V_30 ) ||
( F_20 ( V_30 ) && ( F_21 ( V_30 ) < V_32 ) ) ||
( F_22 ( V_30 ) && ( F_21 ( V_30 ) <= V_33 ) ) ||
( F_23 ( V_30 ) && ( F_21 ( V_30 ) <= V_33 ) ) )
V_7 [ 1 ] = 0 ;
else
V_7 [ 1 ] = V_34 | V_35 ;
return F_5 ( V_6 , V_7 , F_24 ( V_7 ) ) ;
}
static void F_25 ( struct V_5 * V_6 ,
struct V_24 * V_25 )
{
struct V_36 * V_37 ;
void * V_38 ;
V_38 = F_26 ( F_27 ( V_25 -> V_39 , 0 ) ) ;
V_37 = V_38 + V_25 -> V_40 ;
V_37 -> V_41 = 1 ;
V_37 -> V_42 = 0 ;
F_28 ( V_38 ) ;
}
static int F_29 ( struct V_24 * V_43 )
{
struct V_44 * V_45 ;
union V_46 V_47 , V_48 , V_49 ;
union V_46 * V_50 ;
void * V_38 ;
int V_51 = 2 , V_10 = - V_52 ;
V_38 = F_26 ( F_27 ( V_43 -> V_39 , 0 ) ) ;
V_45 = V_38 + V_43 -> V_53 ;
V_45 -> V_54 = V_43 -> V_55 ;
V_47 . V_41 = V_56 ;
V_47 . V_42 = V_43 -> V_42 ;
V_48 . V_41 = V_56 ;
V_48 . V_42 = V_43 -> V_42 + 1 ;
if ( V_48 . V_42 == 0 )
V_48 . V_42 = 1 ;
V_50 = V_38 + V_43 -> V_40 ;
while ( V_51 -- ) {
V_49 . V_57 = F_30 ( ( V_58 * ) V_50 ,
V_47 . V_57 , V_48 . V_57 ) ;
if ( V_49 . V_57 == V_47 . V_57 ) {
V_43 -> V_42 = V_48 . V_42 ;
V_10 = 0 ;
break;
}
if ( V_49 . V_41 == V_59 )
break;
F_13 ( L_3 ,
V_47 . V_42 , V_49 . V_42 ) ;
V_47 . V_42 = V_49 . V_42 ;
V_48 . V_42 = V_49 . V_42 + 1 ;
if ( V_48 . V_42 == 0 )
V_48 . V_42 = 1 ;
}
F_28 ( V_38 ) ;
return V_10 ;
}
static void F_31 ( struct V_5 * V_6 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_36 * V_37 ;
void * V_38 ;
int V_60 = F_32 ( V_25 -> V_61 ) ;
int V_62 ;
V_38 = F_26 ( F_27 ( V_25 -> V_39 , 0 ) ) ;
V_37 = V_38 + V_25 -> V_40 ;
V_37 -> V_41 = 0 ;
F_28 ( V_38 ) ;
F_10 ( V_60 , F_2 ( V_60 ) & ~ V_63 ) ;
V_62 = F_2 ( V_60 ) ;
F_7 ( ( V_62 & V_63 ) != 0 ) ;
F_10 ( F_33 ( V_25 -> V_61 ) , 0 ) ;
F_10 ( V_60 , 0 ) ;
}
static T_2 F_34 ( struct V_5 * V_6 )
{
const T_2 V_64 = F_35 () ;
T_2 V_65 ;
F_9 ( & V_6 -> V_13 ) ;
V_65 = F_36 ( V_6 -> V_66 ) ;
V_6 -> V_66 += V_64 ;
F_14 ( & V_6 -> V_13 ) ;
F_37 ( L_4 ,
V_65 , V_6 -> V_66 , V_64 ) ;
return V_65 ;
}
static T_3 F_38 ( struct V_5 * V_6 , T_2 V_67 )
{
const bool V_68 = ( V_67 <= V_69 ) ;
const T_3 V_70 = V_71 / 2 ;
const T_3 V_72 = V_68 ? V_70 : 0 ;
const T_3 V_73 = V_72 + V_70 ;
T_3 V_74 ;
F_9 ( & V_6 -> V_13 ) ;
V_74 = F_39 ( V_6 -> V_75 , V_73 , V_72 ) ;
if ( V_74 == V_73 )
V_74 = V_76 ;
else
F_40 ( V_6 -> V_75 , V_74 , 1 ) ;
F_14 ( & V_6 -> V_13 ) ;
F_37 ( L_5 ,
V_68 ? L_6 : L_7 , V_74 ) ;
return V_74 ;
}
static void F_41 ( struct V_5 * V_6 , T_3 V_74 )
{
F_9 ( & V_6 -> V_13 ) ;
F_42 ( V_6 -> V_75 , V_74 , 1 ) ;
F_14 ( & V_6 -> V_13 ) ;
}
static void F_43 ( struct V_5 * V_6 ,
struct V_24 * V_25 )
{
struct V_44 * V_45 ;
void * V_38 ;
V_38 = F_26 ( F_27 ( V_25 -> V_39 , 0 ) ) ;
V_45 = V_38 + V_25 -> V_53 ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_77 = 0 ;
V_45 -> V_78 = 0 ;
V_45 -> V_79 = V_25 -> V_27 ;
V_45 -> V_80 = V_25 -> V_81 ;
V_45 -> V_82 = V_83 ;
V_45 -> V_67 = V_25 -> V_67 ;
F_28 ( V_38 ) ;
}
static void F_44 ( struct V_5 * V_6 ,
struct V_24 * V_25 )
{
struct V_84 * V_85 = V_25 -> V_86 ;
struct V_87 V_45 ;
struct V_88 * V_89 ;
int V_9 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_90 = V_91 | V_92 ;
V_45 . V_79 = V_25 -> V_27 ;
V_45 . V_67 = V_25 -> V_67 ;
V_45 . V_93 = V_25 -> V_61 ;
for ( V_9 = 0 ; V_9 < V_94 ; V_9 ++ ) {
struct V_95 * V_96 = & V_45 . V_96 [ V_9 ] ;
struct V_97 * V_98 = V_85 -> V_99 [ V_9 ] . V_98 ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
T_4 V_104 ;
V_103 = V_85 -> V_99 [ V_9 ] . V_105 ;
if ( ! V_103 )
break;
V_101 = V_98 -> V_101 ;
V_104 = F_45 ( V_85 , V_101 ) ;
V_96 -> V_106 = ( T_1 ) V_104 ;
V_96 -> V_107 = F_46 ( V_103 ) +
V_108 * V_109 ;
V_96 -> V_79 = ( V_25 -> V_27 << V_110 ) |
( V_101 -> V_74 << V_111 ) ;
V_103 = V_98 -> V_103 ;
V_96 -> V_112 = F_46 ( V_103 ) ;
V_96 -> V_113 = V_96 -> V_112 + V_103 -> V_38 . V_114 - 1 ;
V_96 -> V_115 = V_96 -> V_112 ;
V_96 -> V_116 = 0 ;
V_45 . V_117 |= ( 1 << V_101 -> V_74 ) ;
}
F_7 ( V_45 . V_117 == 0 ) ;
V_45 . V_118 = 0 ;
V_45 . V_119 = V_25 -> V_40 +
F_46 ( V_25 -> V_39 ) ;
V_45 . V_120 = V_25 -> V_40 +
F_47 ( V_25 -> V_39 -> V_121 -> V_122 ) ;
V_45 . V_123 = V_25 -> V_53 +
F_46 ( V_25 -> V_39 ) ;
V_45 . V_124 = V_25 -> V_125 +
F_46 ( V_25 -> V_39 ) ;
V_45 . V_81 = V_25 -> V_81 ;
V_45 . V_126 = ( V_127 ) V_25 ;
V_89 = V_6 -> V_128 -> V_121 ;
F_48 ( V_89 -> V_122 , V_89 -> V_129 , & V_45 , sizeof( V_45 ) ,
sizeof( V_45 ) * V_25 -> V_27 ) ;
}
static void F_49 ( struct V_5 * V_6 ,
struct V_24 * V_25 )
{
struct V_87 V_45 ;
struct V_88 * V_89 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_89 = V_6 -> V_128 -> V_121 ;
F_48 ( V_89 -> V_122 , V_89 -> V_129 , & V_45 , sizeof( V_45 ) ,
sizeof( V_45 ) * V_25 -> V_27 ) ;
}
static int F_50 ( struct V_24 * V_43 , T_1 * V_65 )
{
struct V_44 * V_45 ;
void * V_38 ;
T_1 V_114 = sizeof( struct V_130 ) ;
int V_10 = 0 , V_131 = 200 ;
V_38 = F_26 ( F_27 ( V_43 -> V_39 , 0 ) ) ;
V_45 = V_38 + V_43 -> V_53 ;
while ( V_131 -- > 0 ) {
V_10 = F_12 ( F_51 ( V_43 -> V_55 , V_45 -> V_132 ,
V_43 -> V_81 ) >= V_114 , 1 ) ;
if ( ! V_10 ) {
* V_65 = V_43 -> V_55 ;
V_43 -> V_55 += V_114 ;
V_43 -> V_55 &= V_43 -> V_81 - 1 ;
V_131 = 0 ;
}
} ;
F_28 ( V_38 ) ;
return V_10 ;
}
static int F_52 ( struct V_24 * V_43 ,
struct V_133 * V_134 )
{
enum V_135 V_136 = V_134 -> V_101 -> V_74 ;
struct V_130 * V_137 ;
void * V_38 ;
T_1 V_54 , V_138 , V_139 = 0 ;
int V_10 ;
V_10 = F_50 ( V_43 , & V_139 ) ;
if ( V_10 )
return V_10 ;
F_7 ( sizeof( struct V_130 ) != 16 ) ;
F_7 ( V_139 & 3 ) ;
V_38 = F_26 ( F_27 ( V_43 -> V_39 ,
( V_139 + V_140 ) >> V_141 ) ) ;
V_139 &= V_109 - 1 ;
V_137 = (struct V_130 * ) ( ( char * ) V_38 + V_139 ) ;
V_138 = sizeof( struct V_130 ) / sizeof( T_1 ) - 1 ;
V_137 -> V_142 = V_143 |
( V_138 << V_144 ) |
( V_136 << V_145 ) |
V_146 ;
V_137 -> V_106 = ( T_1 ) F_45 ( V_134 -> V_85 , V_134 -> V_101 ) ;
V_54 = V_134 -> V_98 -> V_54 >> 3 ;
V_137 -> V_147 = V_54 << V_148 ;
V_137 -> V_149 = 0 ;
F_28 ( V_38 ) ;
return 0 ;
}
static void F_53 ( struct V_133 * V_134 )
{
enum V_135 V_136 = V_134 -> V_101 -> V_74 ;
struct V_102 * V_150 = V_134 -> V_85 -> V_99 [ V_136 ] . V_105 ;
struct V_102 * V_151 = V_134 -> V_98 -> V_103 ;
struct V_152 * V_152 ;
T_2 * V_153 ;
F_54 ( ! V_150 ) ;
F_7 ( ! F_55 ( V_150 ) ) ;
F_7 ( ! F_55 ( V_151 ) ) ;
V_152 = F_27 ( V_150 , V_108 ) ;
V_153 = F_26 ( V_152 ) ;
V_153 [ V_154 + 1 ] = F_46 ( V_151 ) ;
F_28 ( V_153 ) ;
}
int F_56 ( struct V_24 * V_25 ,
struct V_133 * V_134 )
{
struct V_5 * V_6 = V_25 -> V_6 ;
enum V_135 V_136 = V_134 -> V_101 -> V_74 ;
unsigned long V_155 ;
int V_156 , V_157 ;
F_53 ( V_134 ) ;
F_57 ( & V_25 -> V_158 , V_155 ) ;
V_156 = F_52 ( V_25 , V_134 ) ;
if ( V_156 == 0 )
V_157 = F_29 ( V_25 ) ;
V_25 -> V_159 [ V_136 ] += 1 ;
if ( V_156 ) {
V_25 -> V_160 += 1 ;
V_25 -> V_161 = V_156 ;
} else if ( V_157 ) {
V_25 -> V_162 += 1 ;
V_25 -> V_161 = V_156 = V_157 ;
} else {
V_25 -> V_161 = 0 ;
}
F_58 ( & V_25 -> V_158 , V_155 ) ;
F_9 ( & V_6 -> V_13 ) ;
V_6 -> V_159 [ V_136 ] += 1 ;
V_6 -> V_163 [ V_136 ] = V_134 -> V_164 ;
F_14 ( & V_6 -> V_13 ) ;
return V_156 ;
}
static struct V_102 * F_59 ( struct V_29 * V_30 ,
T_1 V_114 )
{
struct V_1 * V_2 = V_30 -> V_165 ;
struct V_102 * V_103 ;
V_103 = F_60 ( V_30 , V_114 ) ;
if ( ! V_103 )
return NULL ;
if ( F_61 ( V_103 ) ) {
F_62 ( & V_103 -> V_38 ) ;
return NULL ;
}
if ( F_63 ( V_103 , V_109 ,
V_166 | V_167 ) ) {
F_62 ( & V_103 -> V_38 ) ;
return NULL ;
}
F_10 ( V_168 , V_169 ) ;
return V_103 ;
}
static void F_64 ( struct V_102 * V_103 )
{
if ( ! V_103 )
return;
if ( F_55 ( V_103 ) )
F_65 ( V_103 ) ;
F_62 ( & V_103 -> V_38 ) ;
}
static void F_66 ( struct V_29 * V_30 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 = V_30 -> V_165 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_25 )
return;
if ( V_25 -> V_61 != V_76 ) {
F_31 ( V_6 , V_25 ) ;
F_17 ( V_6 , V_25 ) ;
F_41 ( V_6 , V_25 -> V_61 ) ;
}
F_64 ( V_25 -> V_39 ) ;
if ( V_25 -> V_27 != V_170 ) {
F_49 ( V_6 , V_25 ) ;
F_67 ( & V_6 -> V_171 , V_25 -> V_27 ) ;
}
F_68 ( V_25 ) ;
}
static struct V_24 * F_69 ( struct V_29 * V_30 ,
T_2 V_67 ,
struct V_84 * V_85 )
{
struct V_24 * V_25 ;
struct V_1 * V_2 = V_30 -> V_165 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_102 * V_103 ;
V_25 = F_70 ( sizeof( * V_25 ) , V_172 ) ;
if ( ! V_25 )
return NULL ;
V_25 -> V_61 = V_76 ;
V_25 -> V_67 = V_67 ;
V_25 -> V_86 = V_85 ;
V_25 -> V_6 = V_6 ;
V_25 -> V_27 = ( T_2 ) F_71 ( & V_6 -> V_171 , 0 ,
V_173 , V_172 ) ;
if ( V_25 -> V_27 >= V_173 ) {
V_25 -> V_27 = V_170 ;
goto V_174;
}
V_103 = F_59 ( V_30 , V_140 + V_175 ) ;
if ( ! V_103 )
goto V_174;
V_25 -> V_39 = V_103 ;
V_25 -> V_125 = V_140 ;
V_25 -> V_81 = V_175 ;
F_72 ( & V_25 -> V_158 ) ;
V_25 -> V_40 = F_34 ( V_6 ) ;
if ( V_25 -> V_40 >= ( V_140 / 2 ) )
V_25 -> V_53 = 0 ;
else
V_25 -> V_53 = ( V_140 / 2 ) ;
V_25 -> V_61 = F_38 ( V_6 , V_25 -> V_67 ) ;
if ( V_25 -> V_61 == V_76 )
goto V_174;
F_43 ( V_6 , V_25 ) ;
F_44 ( V_6 , V_25 ) ;
F_25 ( V_6 , V_25 ) ;
if ( F_16 ( V_6 , V_25 ) )
goto V_174;
F_37 ( L_8 ,
V_67 , V_25 , V_25 -> V_27 , V_25 -> V_61 ) ;
return V_25 ;
V_174:
F_13 ( L_9 , V_67 ) ;
F_66 ( V_30 , V_25 ) ;
return NULL ;
}
static void F_73 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_102 * V_103 ;
unsigned long V_65 ;
T_2 V_114 , V_155 ;
if ( V_176 . V_177 < V_178 )
return;
if ( V_176 . V_177 > V_179 )
V_176 . V_177 = V_179 ;
V_114 = ( 1 + V_180 + 1 +
V_181 + 1 +
V_182 + 1 ) << V_141 ;
V_103 = V_6 -> V_183 ;
if ( ! V_103 ) {
V_103 = F_59 ( V_2 -> V_30 , V_114 ) ;
if ( ! V_103 ) {
V_176 . V_177 = - 1 ;
return;
}
V_6 -> V_183 = V_103 ;
}
V_155 = V_184 | V_185 |
( V_180 << V_186 ) |
( V_181 << V_187 ) |
( V_182 << V_188 ) ;
V_65 = F_46 ( V_103 ) >> V_141 ;
V_6 -> V_189 = ( V_65 << V_190 ) | V_155 ;
}
int F_74 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_165 ;
const T_5 V_191 = sizeof( struct V_87 ) ;
const T_5 V_192 = V_173 * V_191 ;
const T_5 V_193 = F_75 ( V_192 , V_109 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_176 . V_194 )
return 0 ;
if ( V_6 -> V_128 )
return 0 ;
V_6 -> V_128 = F_59 ( V_2 -> V_30 , V_193 ) ;
if ( ! V_6 -> V_128 )
return - V_195 ;
F_72 ( & V_2 -> V_6 . V_13 ) ;
F_76 ( & V_6 -> V_171 ) ;
F_73 ( V_6 ) ;
return 0 ;
}
int F_77 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_165 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_84 * V_85 = V_2 -> V_101 [ V_196 ] . V_197 ;
struct V_24 * V_25 ;
V_25 = F_69 ( V_30 , V_198 , V_85 ) ;
if ( ! V_25 ) {
F_13 ( L_10 ) ;
return - V_195 ;
}
V_6 -> V_199 = V_25 ;
F_18 ( V_6 , V_25 ) ;
return 0 ;
}
void F_78 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_165 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_66 ( V_30 , V_6 -> V_199 ) ;
V_6 -> V_199 = NULL ;
}
void F_79 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_165 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_64 ( V_2 -> V_6 . V_183 ) ;
V_6 -> V_183 = NULL ;
if ( V_6 -> V_128 )
F_80 ( & V_6 -> V_171 ) ;
F_64 ( V_6 -> V_128 ) ;
V_6 -> V_128 = NULL ;
}
int F_81 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_165 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_84 * V_85 ;
T_1 V_7 [ 3 ] ;
if ( ! V_176 . V_194 )
return 0 ;
V_85 = V_2 -> V_101 [ V_196 ] . V_197 ;
V_7 [ 0 ] = V_200 ;
V_7 [ 1 ] = V_201 ;
V_7 [ 2 ] = F_46 ( V_85 -> V_99 [ V_196 ] . V_105 ) ;
return F_5 ( V_6 , V_7 , F_24 ( V_7 ) ) ;
}
int F_82 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_165 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_84 * V_85 ;
T_1 V_7 [ 3 ] ;
if ( ! V_176 . V_194 )
return 0 ;
V_85 = V_2 -> V_101 [ V_196 ] . V_197 ;
V_7 [ 0 ] = V_202 ;
V_7 [ 1 ] = V_203 ;
V_7 [ 2 ] = F_46 ( V_85 -> V_99 [ V_196 ] . V_105 ) ;
return F_5 ( V_6 , V_7 , F_24 ( V_7 ) ) ;
}
