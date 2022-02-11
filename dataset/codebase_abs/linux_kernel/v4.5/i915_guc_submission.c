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
V_2 -> V_6 . V_13 += 1 ;
V_2 -> V_6 . V_14 = V_7 [ 0 ] ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
F_9 ( F_3 ( V_9 ) , V_7 [ V_9 ] ) ;
F_10 ( F_3 ( V_9 - 1 ) ) ;
F_9 ( V_15 , V_16 ) ;
V_10 = F_11 ( F_1 ( V_2 , & V_3 ) , 10 ) ;
if ( V_3 != V_17 ) {
if ( V_10 != - V_18 )
V_10 = - V_19 ;
F_12 ( L_1
L_2 ,
V_7 [ 0 ] , V_10 , V_3 ,
F_2 ( F_3 ( 15 ) ) ) ;
V_2 -> V_6 . V_20 += 1 ;
V_2 -> V_6 . V_21 = V_10 ;
}
V_2 -> V_6 . V_22 = V_3 ;
F_13 ( V_2 , V_12 ) ;
return V_10 ;
}
static int F_14 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_25 ;
V_7 [ 1 ] = V_24 -> V_26 ;
return F_5 ( V_6 , V_7 , 2 ) ;
}
static int F_15 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_27 ;
V_7 [ 1 ] = V_24 -> V_26 ;
return F_5 ( V_6 , V_7 , 2 ) ;
}
static int F_16 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_28 * V_29 = V_2 -> V_29 ;
T_1 V_7 [ 2 ] ;
V_7 [ 0 ] = V_30 ;
if ( ! F_17 ( V_2 -> V_29 ) ||
F_18 ( V_29 , 0 , V_31 ) ||
( F_19 ( V_29 ) && F_20 ( V_29 , 0 , V_32 ) ) ||
( F_21 ( V_29 ) && F_20 ( V_29 , 0 , V_32 ) ) )
V_7 [ 1 ] = 0 ;
else
V_7 [ 1 ] = V_33 | V_34 ;
return F_5 ( V_6 , V_7 , F_22 ( V_7 ) ) ;
}
static void F_23 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
struct V_35 * V_36 ;
void * V_37 ;
V_37 = F_24 ( F_25 ( V_24 -> V_38 , 0 ) ) ;
V_36 = V_37 + V_24 -> V_39 ;
V_36 -> V_40 = 1 ;
V_36 -> V_41 = 0 ;
F_26 ( V_37 ) ;
}
static int F_27 ( struct V_23 * V_42 )
{
struct V_43 * V_44 ;
union V_45 V_46 , V_47 , V_48 ;
union V_45 * V_49 ;
void * V_37 ;
int V_50 = 2 , V_10 = - V_51 ;
V_37 = F_24 ( F_25 ( V_42 -> V_38 , 0 ) ) ;
V_44 = V_37 + V_42 -> V_52 ;
V_44 -> V_53 = V_42 -> V_54 ;
V_46 . V_40 = V_55 ;
V_46 . V_41 = V_42 -> V_41 ;
V_47 . V_40 = V_55 ;
V_47 . V_41 = V_42 -> V_41 + 1 ;
if ( V_47 . V_41 == 0 )
V_47 . V_41 = 1 ;
V_49 = V_37 + V_42 -> V_39 ;
while ( V_50 -- ) {
V_48 . V_56 = F_28 ( ( V_57 * ) V_49 ,
V_46 . V_56 , V_47 . V_56 ) ;
if ( V_48 . V_56 == V_46 . V_56 ) {
V_42 -> V_41 = V_47 . V_41 ;
V_10 = 0 ;
break;
}
if ( V_48 . V_40 == V_58 )
break;
F_12 ( L_3 ,
V_46 . V_41 , V_48 . V_41 ) ;
V_46 . V_41 = V_48 . V_41 ;
V_47 . V_41 = V_48 . V_41 + 1 ;
if ( V_47 . V_41 == 0 )
V_47 . V_41 = 1 ;
}
F_26 ( V_37 ) ;
return V_10 ;
}
static void F_29 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_35 * V_36 ;
void * V_37 ;
T_2 V_59 = F_30 ( V_24 -> V_60 ) ;
int V_61 ;
V_37 = F_24 ( F_25 ( V_24 -> V_38 , 0 ) ) ;
V_36 = V_37 + V_24 -> V_39 ;
V_36 -> V_40 = 0 ;
F_26 ( V_37 ) ;
F_9 ( V_59 , F_2 ( V_59 ) & ~ V_62 ) ;
V_61 = F_2 ( V_59 ) ;
F_7 ( ( V_61 & V_62 ) != 0 ) ;
F_9 ( F_31 ( V_24 -> V_60 ) , 0 ) ;
F_9 ( V_59 , 0 ) ;
}
static T_3 F_32 ( struct V_5 * V_6 )
{
const T_3 V_63 = F_33 () ;
T_3 V_64 ;
V_64 = F_34 ( V_6 -> V_65 ) ;
V_6 -> V_65 += V_63 ;
F_35 ( L_4 ,
V_64 , V_6 -> V_65 , V_63 ) ;
return V_64 ;
}
static T_4 F_36 ( struct V_5 * V_6 , T_3 V_66 )
{
const bool V_67 = ( V_66 <= V_68 ) ;
const T_4 V_69 = V_70 / 2 ;
const T_4 V_71 = V_67 ? V_69 : 0 ;
const T_4 V_72 = V_71 + V_69 ;
T_4 V_73 ;
V_73 = F_37 ( V_6 -> V_74 , V_72 , V_71 ) ;
if ( V_73 == V_72 )
V_73 = V_75 ;
else
F_38 ( V_6 -> V_74 , V_73 , 1 ) ;
F_35 ( L_5 ,
V_67 ? L_6 : L_7 , V_73 ) ;
return V_73 ;
}
static void F_39 ( struct V_5 * V_6 , T_4 V_73 )
{
F_40 ( V_6 -> V_74 , V_73 , 1 ) ;
}
static void F_41 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
struct V_43 * V_44 ;
void * V_37 ;
V_37 = F_24 ( F_25 ( V_24 -> V_38 , 0 ) ) ;
V_44 = V_37 + V_24 -> V_52 ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> V_76 = 0 ;
V_44 -> V_77 = 0 ;
V_44 -> V_78 = V_24 -> V_26 ;
V_44 -> V_79 = V_24 -> V_80 ;
V_44 -> V_81 = V_82 ;
V_44 -> V_66 = V_24 -> V_66 ;
F_26 ( V_37 ) ;
}
static void F_42 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
struct V_83 * V_84 = V_24 -> V_85 ;
struct V_86 V_44 ;
struct V_87 * V_88 ;
int V_9 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_89 = V_90 | V_91 ;
V_44 . V_78 = V_24 -> V_26 ;
V_44 . V_66 = V_24 -> V_66 ;
V_44 . V_92 = V_24 -> V_60 ;
for ( V_9 = 0 ; V_9 < V_93 ; V_9 ++ ) {
struct V_94 * V_95 = & V_44 . V_95 [ V_9 ] ;
struct V_96 * V_97 = V_84 -> V_98 [ V_9 ] . V_97 ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
T_5 V_103 ;
V_102 = V_84 -> V_98 [ V_9 ] . V_104 ;
if ( ! V_102 )
break;
V_100 = V_97 -> V_100 ;
V_103 = F_43 ( V_84 , V_100 ) ;
V_95 -> V_105 = ( T_1 ) V_103 ;
V_95 -> V_106 = F_44 ( V_102 ) +
V_107 * V_108 ;
V_95 -> V_78 = ( V_24 -> V_26 << V_109 ) |
( V_100 -> V_73 << V_110 ) ;
V_102 = V_97 -> V_102 ;
V_95 -> V_111 = F_44 ( V_102 ) ;
V_95 -> V_112 = V_95 -> V_111 + V_102 -> V_37 . V_113 - 1 ;
V_95 -> V_114 = V_95 -> V_111 ;
V_95 -> V_115 = 0 ;
V_44 . V_116 |= ( 1 << V_100 -> V_73 ) ;
}
F_7 ( V_44 . V_116 == 0 ) ;
V_44 . V_117 = 0 ;
V_44 . V_118 = V_24 -> V_39 +
F_44 ( V_24 -> V_38 ) ;
V_44 . V_119 = V_24 -> V_39 +
F_45 ( V_24 -> V_38 -> V_120 -> V_121 ) ;
V_44 . V_122 = V_24 -> V_52 +
F_44 ( V_24 -> V_38 ) ;
V_44 . V_123 = V_24 -> V_124 +
F_44 ( V_24 -> V_38 ) ;
V_44 . V_80 = V_24 -> V_80 ;
V_44 . V_125 = ( V_126 ) V_24 ;
V_88 = V_6 -> V_127 -> V_120 ;
F_46 ( V_88 -> V_121 , V_88 -> V_128 , & V_44 , sizeof( V_44 ) ,
sizeof( V_44 ) * V_24 -> V_26 ) ;
}
static void F_47 ( struct V_5 * V_6 ,
struct V_23 * V_24 )
{
struct V_86 V_44 ;
struct V_87 * V_88 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_88 = V_6 -> V_127 -> V_120 ;
F_46 ( V_88 -> V_121 , V_88 -> V_128 , & V_44 , sizeof( V_44 ) ,
sizeof( V_44 ) * V_24 -> V_26 ) ;
}
static int F_48 ( struct V_23 * V_42 , T_1 * V_64 )
{
struct V_43 * V_44 ;
void * V_37 ;
T_1 V_113 = sizeof( struct V_129 ) ;
int V_10 = - V_18 , V_130 = 200 ;
V_37 = F_24 ( F_25 ( V_42 -> V_38 , 0 ) ) ;
V_44 = V_37 + V_42 -> V_52 ;
while ( V_130 -- > 0 ) {
if ( F_49 ( V_42 -> V_54 , V_44 -> V_131 , V_42 -> V_80 ) >= V_113 ) {
* V_64 = V_42 -> V_54 ;
V_42 -> V_54 += V_113 ;
V_42 -> V_54 &= V_42 -> V_80 - 1 ;
V_130 = 0 ;
V_10 = 0 ;
}
if ( V_130 )
F_50 ( 1000 , 2000 ) ;
} ;
F_26 ( V_37 ) ;
return V_10 ;
}
static int F_51 ( struct V_23 * V_42 ,
struct V_132 * V_133 )
{
enum V_134 V_135 = V_133 -> V_100 -> V_73 ;
struct V_129 * V_136 ;
void * V_37 ;
T_1 V_53 , V_137 , V_138 = 0 ;
int V_10 ;
V_10 = F_48 ( V_42 , & V_138 ) ;
if ( V_10 )
return V_10 ;
F_7 ( sizeof( struct V_129 ) != 16 ) ;
F_7 ( V_138 & 3 ) ;
V_37 = F_24 ( F_25 ( V_42 -> V_38 ,
( V_138 + V_139 ) >> V_140 ) ) ;
V_138 &= V_108 - 1 ;
V_136 = (struct V_129 * ) ( ( char * ) V_37 + V_138 ) ;
V_137 = sizeof( struct V_129 ) / sizeof( T_1 ) - 1 ;
V_136 -> V_141 = V_142 |
( V_137 << V_143 ) |
( V_135 << V_144 ) |
V_145 ;
V_136 -> V_105 = ( T_1 ) F_43 ( V_133 -> V_84 , V_133 -> V_100 ) ;
V_53 = V_133 -> V_97 -> V_53 >> 3 ;
V_136 -> V_146 = V_53 << V_147 ;
V_136 -> V_148 = 0 ;
F_26 ( V_37 ) ;
return 0 ;
}
static void F_52 ( struct V_132 * V_133 )
{
enum V_134 V_135 = V_133 -> V_100 -> V_73 ;
struct V_101 * V_149 = V_133 -> V_84 -> V_98 [ V_135 ] . V_104 ;
struct V_101 * V_150 = V_133 -> V_97 -> V_102 ;
struct V_151 * V_151 ;
T_3 * V_152 ;
F_53 ( ! V_149 ) ;
F_7 ( ! F_54 ( V_149 ) ) ;
F_7 ( ! F_54 ( V_150 ) ) ;
V_151 = F_55 ( V_149 , V_107 ) ;
V_152 = F_24 ( V_151 ) ;
V_152 [ V_153 + 1 ] = F_44 ( V_150 ) ;
F_26 ( V_152 ) ;
}
int F_56 ( struct V_23 * V_24 ,
struct V_132 * V_133 )
{
struct V_5 * V_6 = V_24 -> V_6 ;
enum V_134 V_135 = V_133 -> V_100 -> V_73 ;
int V_154 , V_155 ;
F_52 ( V_133 ) ;
V_154 = F_51 ( V_24 , V_133 ) ;
if ( V_154 == 0 )
V_155 = F_27 ( V_24 ) ;
V_24 -> V_156 [ V_135 ] += 1 ;
if ( V_154 ) {
V_24 -> V_157 += 1 ;
V_24 -> V_158 = V_154 ;
} else if ( V_155 ) {
V_24 -> V_159 += 1 ;
V_24 -> V_158 = V_154 = V_155 ;
} else {
V_24 -> V_158 = 0 ;
}
V_6 -> V_156 [ V_135 ] += 1 ;
V_6 -> V_160 [ V_135 ] = V_133 -> V_161 ;
return V_154 ;
}
static struct V_101 * F_57 ( struct V_28 * V_29 ,
T_1 V_113 )
{
struct V_1 * V_2 = V_29 -> V_162 ;
struct V_101 * V_102 ;
V_102 = F_58 ( V_29 , V_113 ) ;
if ( ! V_102 )
return NULL ;
if ( F_59 ( V_102 ) ) {
F_60 ( & V_102 -> V_37 ) ;
return NULL ;
}
if ( F_61 ( V_102 , V_108 ,
V_163 | V_164 ) ) {
F_60 ( & V_102 -> V_37 ) ;
return NULL ;
}
F_9 ( V_165 , V_166 ) ;
return V_102 ;
}
static void F_62 ( struct V_101 * V_102 )
{
if ( ! V_102 )
return;
if ( F_54 ( V_102 ) )
F_63 ( V_102 ) ;
F_60 ( & V_102 -> V_37 ) ;
}
static void F_64 ( struct V_28 * V_29 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = V_29 -> V_162 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_24 )
return;
if ( V_24 -> V_60 != V_75 ) {
F_29 ( V_6 , V_24 ) ;
F_15 ( V_6 , V_24 ) ;
F_39 ( V_6 , V_24 -> V_60 ) ;
}
F_62 ( V_24 -> V_38 ) ;
if ( V_24 -> V_26 != V_167 ) {
F_47 ( V_6 , V_24 ) ;
F_65 ( & V_6 -> V_168 , V_24 -> V_26 ) ;
}
F_66 ( V_24 ) ;
}
static struct V_23 * F_67 ( struct V_28 * V_29 ,
T_3 V_66 ,
struct V_83 * V_84 )
{
struct V_23 * V_24 ;
struct V_1 * V_2 = V_29 -> V_162 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_101 * V_102 ;
V_24 = F_68 ( sizeof( * V_24 ) , V_169 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_60 = V_75 ;
V_24 -> V_66 = V_66 ;
V_24 -> V_85 = V_84 ;
V_24 -> V_6 = V_6 ;
V_24 -> V_26 = ( T_3 ) F_69 ( & V_6 -> V_168 , 0 ,
V_170 , V_169 ) ;
if ( V_24 -> V_26 >= V_170 ) {
V_24 -> V_26 = V_167 ;
goto V_171;
}
V_102 = F_57 ( V_29 , V_139 + V_172 ) ;
if ( ! V_102 )
goto V_171;
V_24 -> V_38 = V_102 ;
V_24 -> V_124 = V_139 ;
V_24 -> V_80 = V_172 ;
V_24 -> V_39 = F_32 ( V_6 ) ;
if ( V_24 -> V_39 >= ( V_139 / 2 ) )
V_24 -> V_52 = 0 ;
else
V_24 -> V_52 = ( V_139 / 2 ) ;
V_24 -> V_60 = F_36 ( V_6 , V_24 -> V_66 ) ;
if ( V_24 -> V_60 == V_75 )
goto V_171;
F_41 ( V_6 , V_24 ) ;
F_42 ( V_6 , V_24 ) ;
F_23 ( V_6 , V_24 ) ;
if ( F_14 ( V_6 , V_24 ) )
goto V_171;
F_35 ( L_8 ,
V_66 , V_24 , V_24 -> V_26 , V_24 -> V_60 ) ;
return V_24 ;
V_171:
F_12 ( L_9 , V_66 ) ;
F_64 ( V_29 , V_24 ) ;
return NULL ;
}
static void F_70 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_6 ( V_6 ) ;
struct V_101 * V_102 ;
unsigned long V_64 ;
T_3 V_113 , V_173 ;
if ( V_174 . V_175 < V_176 )
return;
if ( V_174 . V_175 > V_177 )
V_174 . V_175 = V_177 ;
V_113 = ( 1 + V_178 + 1 +
V_179 + 1 +
V_180 + 1 ) << V_140 ;
V_102 = V_6 -> V_181 ;
if ( ! V_102 ) {
V_102 = F_57 ( V_2 -> V_29 , V_113 ) ;
if ( ! V_102 ) {
V_174 . V_175 = - 1 ;
return;
}
V_6 -> V_181 = V_102 ;
}
V_173 = V_182 | V_183 |
( V_178 << V_184 ) |
( V_179 << V_185 ) |
( V_180 << V_186 ) ;
V_64 = F_44 ( V_102 ) >> V_140 ;
V_6 -> V_187 = ( V_64 << V_188 ) | V_173 ;
}
int F_71 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_162 ;
const T_6 V_189 = sizeof( struct V_86 ) ;
const T_6 V_190 = V_170 * V_189 ;
const T_6 V_191 = F_72 ( V_190 , V_108 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( ! V_174 . V_192 )
return 0 ;
if ( V_6 -> V_127 )
return 0 ;
V_6 -> V_127 = F_57 ( V_2 -> V_29 , V_191 ) ;
if ( ! V_6 -> V_127 )
return - V_193 ;
F_73 ( & V_6 -> V_168 ) ;
F_70 ( V_6 ) ;
return 0 ;
}
int F_74 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_162 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_83 * V_84 = V_2 -> V_100 [ V_194 ] . V_195 ;
struct V_23 * V_24 ;
V_24 = F_67 ( V_29 , V_196 , V_84 ) ;
if ( ! V_24 ) {
F_12 ( L_10 ) ;
return - V_193 ;
}
V_6 -> V_197 = V_24 ;
F_16 ( V_6 , V_24 ) ;
return 0 ;
}
void F_75 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_162 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_64 ( V_29 , V_6 -> V_197 ) ;
V_6 -> V_197 = NULL ;
}
void F_76 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_162 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_62 ( V_2 -> V_6 . V_181 ) ;
V_6 -> V_181 = NULL ;
if ( V_6 -> V_127 )
F_77 ( & V_6 -> V_168 ) ;
F_62 ( V_6 -> V_127 ) ;
V_6 -> V_127 = NULL ;
}
int F_78 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_162 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_83 * V_84 ;
T_1 V_7 [ 3 ] ;
if ( ! V_174 . V_192 )
return 0 ;
V_84 = V_2 -> V_100 [ V_194 ] . V_195 ;
V_7 [ 0 ] = V_198 ;
V_7 [ 1 ] = V_199 ;
V_7 [ 2 ] = F_44 ( V_84 -> V_98 [ V_194 ] . V_104 ) ;
return F_5 ( V_6 , V_7 , F_22 ( V_7 ) ) ;
}
int F_79 ( struct V_28 * V_29 )
{
struct V_1 * V_2 = V_29 -> V_162 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_83 * V_84 ;
T_1 V_7 [ 3 ] ;
if ( ! V_174 . V_192 )
return 0 ;
V_84 = V_2 -> V_100 [ V_194 ] . V_195 ;
V_7 [ 0 ] = V_200 ;
V_7 [ 1 ] = V_201 ;
V_7 [ 2 ] = F_44 ( V_84 -> V_98 [ V_194 ] . V_104 ) ;
return F_5 ( V_6 , V_7 , F_22 ( V_7 ) ) ;
}
