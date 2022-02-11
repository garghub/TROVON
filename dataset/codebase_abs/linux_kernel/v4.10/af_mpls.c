static struct V_1 * F_1 ( struct V_2 * V_2 , unsigned V_3 )
{
struct V_1 * V_4 = NULL ;
if ( V_3 < V_2 -> V_5 . V_6 ) {
struct V_1 T_1 * * V_7 =
F_2 ( V_2 -> V_5 . V_7 ) ;
V_4 = F_2 ( V_7 [ V_3 ] ) ;
}
return V_4 ;
}
static inline struct V_8 * F_3 ( const struct V_9 * V_10 )
{
return F_4 ( V_10 -> V_11 ) ;
}
bool F_5 ( const struct V_9 * V_10 )
{
return V_10 && ( V_10 -> V_12 & V_13 ) && F_6 ( V_10 ) ;
}
static T_2 * F_7 ( struct V_1 * V_4 , struct V_14 * V_15 )
{
T_2 * V_16 = F_8 ( ( T_2 * ) & V_4 -> V_17 [ V_4 -> V_18 ] , V_19 ) ;
int V_20 = V_15 - V_4 -> V_17 ;
return V_16 + V_4 -> V_21 * V_20 ;
}
static const T_2 * F_9 ( const struct V_1 * V_4 ,
const struct V_14 * V_15 )
{
return F_7 ( (struct V_1 * ) V_4 , (struct V_14 * ) V_15 ) ;
}
static unsigned int F_10 ( const struct V_14 * V_15 )
{
return V_15 -> V_22 * sizeof( struct V_23 ) ;
}
unsigned int F_11 ( const struct V_9 * V_10 )
{
return V_10 -> V_24 ;
}
bool F_12 ( const struct V_25 * V_26 , unsigned int V_24 )
{
if ( V_26 -> V_27 <= V_24 )
return false ;
if ( F_13 ( V_26 ) && F_14 ( V_26 , V_24 ) )
return false ;
return true ;
}
static T_3 F_15 ( struct V_1 * V_4 , struct V_25 * V_26 )
{
struct V_28 V_29 ;
unsigned int V_30 = 0 ;
struct V_23 * V_31 ;
bool V_32 = false ;
int V_33 ;
T_3 V_34 = 0 ;
for ( V_33 = 0 ; V_33 < V_35 ;
V_33 ++ ) {
V_30 += sizeof( * V_31 ) ;
if ( ! F_16 ( V_26 , V_30 ) )
break;
V_31 = F_17 ( V_26 ) + V_33 ;
V_29 = F_18 ( V_31 ) ;
if ( F_19 ( V_29 . V_36 >= V_37 ) ) {
V_34 = F_20 ( V_29 . V_36 , V_34 ) ;
if ( V_32 )
break;
} else if ( V_29 . V_36 == V_38 ) {
V_32 = true ;
}
if ( ! V_29 . V_39 )
continue;
if ( F_16 ( V_26 , V_30 + sizeof( struct V_40 ) ) ) {
const struct V_40 * V_41 ;
V_41 = ( const struct V_40 * ) ( V_31 + 1 ) ;
if ( V_41 -> V_42 == 4 ) {
V_34 = F_21 ( F_22 ( V_41 -> V_43 ) ,
F_22 ( V_41 -> V_44 ) ,
V_41 -> V_45 , V_34 ) ;
} else if ( V_41 -> V_42 == 6 &&
F_16 ( V_26 , V_30 +
sizeof( struct V_46 ) ) ) {
const struct V_46 * V_47 ;
V_47 = ( const struct V_46 * ) ( V_31 + 1 ) ;
V_34 = F_23 ( & V_47 -> V_43 , V_34 ) ;
V_34 = F_23 ( & V_47 -> V_44 , V_34 ) ;
V_34 = F_20 ( V_47 -> V_48 , V_34 ) ;
}
}
break;
}
return V_34 ;
}
static struct V_14 * F_24 ( struct V_1 * V_4 ,
struct V_25 * V_26 )
{
int V_49 = F_25 ( V_4 -> V_50 ) ;
T_3 V_34 = 0 ;
int V_20 = 0 ;
int V_51 = 0 ;
if ( V_4 -> V_18 == 1 )
goto V_52;
if ( V_49 <= 0 )
return NULL ;
V_34 = F_15 ( V_4 , V_26 ) ;
V_20 = V_34 % V_49 ;
if ( V_49 == V_4 -> V_18 )
goto V_52;
F_26 (rt) {
if ( V_15 -> V_53 & ( V_54 | V_55 ) )
continue;
if ( V_51 == V_20 )
return V_15 ;
V_51 ++ ;
} F_27 ( V_4 ) ;
V_52:
return & V_4 -> V_17 [ V_20 ] ;
}
static bool F_28 ( struct V_1 * V_4 , struct V_25 * V_26 ,
struct V_28 V_29 )
{
enum V_56 V_57 ;
bool V_58 = false ;
if ( ! F_16 ( V_26 , 12 ) )
return false ;
V_57 = V_4 -> V_59 ;
if ( V_57 == V_60 )
V_57 = F_29 ( V_26 ) -> V_42 ;
switch ( V_57 ) {
case V_61 : {
struct V_40 * V_62 = F_29 ( V_26 ) ;
V_26 -> V_45 = F_30 ( V_63 ) ;
F_31 ( & V_62 -> V_64 ,
F_30 ( V_62 -> V_65 << 8 ) ,
F_30 ( V_29 . V_65 << 8 ) ) ;
V_62 -> V_65 = V_29 . V_65 ;
V_58 = true ;
break;
}
case V_66 : {
struct V_46 * V_67 = F_32 ( V_26 ) ;
V_26 -> V_45 = F_30 ( V_68 ) ;
V_67 -> V_69 = V_29 . V_65 ;
V_58 = true ;
break;
}
case V_60 :
break;
}
return V_58 ;
}
static int F_33 ( struct V_25 * V_26 , struct V_9 * V_10 ,
struct V_70 * V_71 , struct V_9 * V_72 )
{
struct V_2 * V_2 = F_34 ( V_10 ) ;
struct V_23 * V_31 ;
struct V_1 * V_4 ;
struct V_14 * V_15 ;
struct V_28 V_29 ;
struct V_9 * V_73 ;
struct V_8 * V_74 ;
unsigned int V_75 ;
unsigned int V_76 ;
unsigned int V_24 ;
int V_77 ;
V_74 = F_3 ( V_10 ) ;
if ( ! V_74 || ! V_74 -> V_78 )
goto V_79;
if ( V_26 -> V_80 != V_81 )
goto V_79;
if ( ( V_26 = F_35 ( V_26 , V_82 ) ) == NULL )
goto V_79;
if ( ! F_16 ( V_26 , sizeof( * V_31 ) ) )
goto V_79;
V_31 = F_17 ( V_26 ) ;
V_29 = F_18 ( V_31 ) ;
V_4 = F_1 ( V_2 , V_29 . V_36 ) ;
if ( ! V_4 )
goto V_79;
V_15 = F_24 ( V_4 , V_26 ) ;
if ( ! V_15 )
goto V_79;
V_73 = F_2 ( V_15 -> V_83 ) ;
if ( ! F_5 ( V_73 ) )
goto V_79;
F_36 ( V_26 , sizeof( * V_31 ) ) ;
F_37 ( V_26 ) ;
F_38 ( V_26 ) ;
if ( F_39 ( V_26 ) )
goto V_79;
F_40 ( V_26 ) ;
if ( V_29 . V_65 <= 1 )
goto V_79;
V_29 . V_65 -= 1 ;
V_76 = F_10 ( V_15 ) ;
V_24 = F_11 ( V_73 ) ;
if ( F_12 ( V_26 , V_24 - V_76 ) )
goto V_79;
V_75 = F_41 ( V_73 ) ;
if ( ! V_73 -> V_84 )
V_75 = 0 ;
if ( F_42 ( V_26 , V_75 + V_76 ) )
goto V_79;
V_26 -> V_10 = V_73 ;
V_26 -> V_45 = F_30 ( V_85 ) ;
if ( F_43 ( ! V_76 && V_29 . V_39 ) ) {
if ( ! F_28 ( V_4 , V_26 , V_29 ) )
goto V_79;
} else {
bool V_39 ;
int V_86 ;
F_44 ( V_26 , V_76 ) ;
F_37 ( V_26 ) ;
V_31 = F_17 ( V_26 ) ;
V_39 = V_29 . V_39 ;
for ( V_86 = V_15 -> V_22 - 1 ; V_86 >= 0 ; V_86 -- ) {
V_31 [ V_86 ] = F_45 ( V_15 -> V_87 [ V_86 ] ,
V_29 . V_65 , 0 , V_39 ) ;
V_39 = false ;
}
}
if ( V_15 -> V_88 == V_89 )
V_77 = F_46 ( V_90 , V_73 ,
V_73 -> V_91 , V_26 ) ;
else
V_77 = F_46 ( V_15 -> V_88 , V_73 ,
F_9 ( V_4 , V_15 ) , V_26 ) ;
if ( V_77 )
F_47 ( L_1 ,
V_92 , V_77 ) ;
return 0 ;
V_79:
F_48 ( V_26 ) ;
return V_93 ;
}
static struct V_1 * F_49 ( int V_94 , T_2 V_95 )
{
T_2 V_96 = F_50 ( V_95 , V_19 ) ;
struct V_1 * V_4 ;
V_4 = F_51 ( F_50 ( sizeof( * V_4 ) + V_94 * sizeof( * V_4 -> V_17 ) ,
V_19 ) +
V_94 * V_96 ,
V_97 ) ;
if ( V_4 ) {
V_4 -> V_18 = V_94 ;
V_4 -> V_50 = V_94 ;
V_4 -> V_21 = V_96 ;
}
return V_4 ;
}
static void F_52 ( struct V_1 * V_4 )
{
if ( V_4 )
F_53 ( V_4 , V_98 ) ;
}
static void F_54 ( struct V_2 * V_2 , unsigned V_3 ,
struct V_1 * V_99 , struct V_1 * V_100 ,
const struct V_101 * V_102 )
{
struct V_103 * V_104 = V_102 ? V_102 -> V_104 : NULL ;
unsigned V_105 = V_102 ? V_102 -> V_105 : 0 ;
int V_106 = V_100 ? V_107 : V_108 ;
struct V_1 * V_4 = V_100 ? V_100 : V_99 ;
unsigned V_109 = ( V_99 && V_100 ) ? V_110 : 0 ;
if ( V_4 && ( V_3 >= V_37 ) )
F_55 ( V_106 , V_3 , V_4 , V_104 , V_2 , V_105 , V_109 ) ;
}
static void F_56 ( struct V_2 * V_2 , unsigned V_3 ,
struct V_1 * V_100 ,
const struct V_101 * V_102 )
{
struct V_1 T_1 * * V_7 ;
struct V_1 * V_4 ;
F_57 () ;
V_7 = F_58 ( V_2 -> V_5 . V_7 ) ;
V_4 = F_58 ( V_7 [ V_3 ] ) ;
F_59 ( V_7 [ V_3 ] , V_100 ) ;
F_54 ( V_2 , V_3 , V_4 , V_100 , V_102 ) ;
F_52 ( V_4 ) ;
}
static unsigned F_60 ( struct V_2 * V_2 )
{
struct V_1 T_1 * * V_7 ;
T_4 V_6 ;
unsigned V_3 ;
V_7 = F_58 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for ( V_3 = V_37 ; V_3 < V_6 ;
V_3 ++ ) {
if ( ! F_58 ( V_7 [ V_3 ] ) )
return V_3 ;
}
return V_111 ;
}
static struct V_9 * F_61 ( struct V_2 * V_2 ,
const void * V_112 )
{
struct V_9 * V_10 ;
struct V_113 * V_4 ;
struct V_114 V_44 ;
memcpy ( & V_44 , V_112 , sizeof( struct V_114 ) ) ;
V_4 = F_62 ( V_2 , V_44 . V_115 , 0 , 0 , 0 ) ;
if ( F_63 ( V_4 ) )
return F_64 ( V_4 ) ;
V_10 = V_4 -> V_116 . V_10 ;
F_65 ( V_10 ) ;
F_66 ( V_4 ) ;
return V_10 ;
}
static struct V_9 * F_61 ( struct V_2 * V_2 ,
const void * V_112 )
{
return F_67 ( - V_117 ) ;
}
static struct V_9 * F_68 ( struct V_2 * V_2 ,
const void * V_112 )
{
struct V_9 * V_10 ;
struct V_118 * V_116 ;
struct V_119 V_120 ;
int V_77 ;
if ( ! V_121 )
return F_67 ( - V_117 ) ;
memset ( & V_120 , 0 , sizeof( V_120 ) ) ;
memcpy ( & V_120 . V_44 , V_112 , sizeof( struct V_122 ) ) ;
V_77 = V_121 -> V_123 ( V_2 , NULL , & V_116 , & V_120 ) ;
if ( V_77 )
return F_67 ( V_77 ) ;
V_10 = V_116 -> V_10 ;
F_65 ( V_10 ) ;
F_69 ( V_116 ) ;
return V_10 ;
}
static struct V_9 * F_68 ( struct V_2 * V_2 ,
const void * V_112 )
{
return F_67 ( - V_117 ) ;
}
static struct V_9 * F_70 ( struct V_2 * V_2 ,
struct V_1 * V_4 ,
struct V_14 * V_15 , int V_124 )
{
struct V_9 * V_10 = NULL ;
if ( ! V_124 ) {
switch ( V_15 -> V_88 ) {
case V_125 :
V_10 = F_61 ( V_2 , F_9 ( V_4 , V_15 ) ) ;
break;
case V_126 :
V_10 = F_68 ( V_2 , F_9 ( V_4 , V_15 ) ) ;
break;
case V_90 :
break;
}
} else {
V_10 = F_71 ( V_2 , V_124 ) ;
}
if ( ! V_10 )
return F_67 ( - V_127 ) ;
if ( F_63 ( V_10 ) )
return V_10 ;
F_72 ( V_10 ) ;
return V_10 ;
}
static int F_73 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_14 * V_15 , int V_124 )
{
struct V_9 * V_10 = NULL ;
int V_77 = - V_127 ;
V_10 = F_70 ( V_2 , V_4 , V_15 , V_124 ) ;
if ( F_63 ( V_10 ) ) {
V_77 = F_74 ( V_10 ) ;
V_10 = NULL ;
goto V_128;
}
V_77 = - V_129 ;
if ( ! F_3 ( V_10 ) )
goto V_128;
if ( ( V_15 -> V_88 == V_90 ) &&
( V_10 -> V_130 != V_15 -> V_131 ) )
goto V_128;
F_75 ( V_15 -> V_83 , V_10 ) ;
if ( ! ( V_10 -> V_12 & V_13 ) ) {
V_15 -> V_53 |= V_54 ;
} else {
unsigned int V_12 ;
V_12 = F_76 ( V_10 ) ;
if ( ! ( V_12 & ( V_132 | V_133 ) ) )
V_15 -> V_53 |= V_55 ;
}
return 0 ;
V_128:
return V_77 ;
}
static int F_77 ( struct V_134 * V_135 ,
struct V_1 * V_4 )
{
struct V_2 * V_2 = V_135 -> V_136 . V_137 ;
struct V_14 * V_15 = V_4 -> V_17 ;
int V_77 ;
int V_86 ;
if ( ! V_15 )
return - V_138 ;
V_77 = - V_129 ;
if ( V_135 -> V_139 > V_140 )
goto V_128;
V_15 -> V_22 = V_135 -> V_139 ;
for ( V_86 = 0 ; V_86 < V_15 -> V_22 ; V_86 ++ )
V_15 -> V_87 [ V_86 ] = V_135 -> V_141 [ V_86 ] ;
V_15 -> V_88 = V_135 -> V_142 ;
memcpy ( F_7 ( V_4 , V_15 ) , V_135 -> V_143 , V_135 -> V_144 ) ;
V_15 -> V_131 = V_135 -> V_144 ;
V_77 = F_73 ( V_2 , V_4 , V_15 , V_135 -> V_145 ) ;
if ( V_77 )
goto V_128;
if ( V_15 -> V_53 & ( V_54 | V_55 ) )
V_4 -> V_50 -- ;
return 0 ;
V_128:
return V_77 ;
}
static int F_78 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_14 * V_15 , int V_124 , struct V_146 * V_147 ,
struct V_146 * V_148 )
{
int V_77 = - V_138 ;
if ( ! V_15 )
goto V_128;
if ( V_148 ) {
V_77 = F_79 ( V_148 , V_140 ,
& V_15 -> V_22 , V_15 -> V_87 ) ;
if ( V_77 )
goto V_128;
}
if ( V_147 ) {
V_77 = F_80 ( V_147 , & V_15 -> V_131 , & V_15 -> V_88 ,
F_7 ( V_4 , V_15 ) ) ;
if ( V_77 )
goto V_128;
} else {
V_15 -> V_88 = V_89 ;
}
V_77 = F_73 ( V_2 , V_4 , V_15 , V_124 ) ;
if ( V_77 )
goto V_128;
return 0 ;
V_128:
return V_77 ;
}
static int F_81 ( struct V_149 * V_150 , int V_27 ,
T_2 V_151 , T_2 * V_152 )
{
int V_153 = 0 ;
int V_154 = V_27 ;
if ( ! V_150 ) {
* V_152 = V_151 ;
return 1 ;
}
* V_152 = 0 ;
while ( F_82 ( V_150 , V_154 ) ) {
struct V_146 * V_155 , * V_156 = F_83 ( V_150 ) ;
int V_157 ;
V_157 = F_84 ( V_150 ) ;
V_155 = F_85 ( V_156 , V_157 , V_158 ) ;
if ( V_155 && F_86 ( V_155 ) >=
F_87 ( struct V_159 , V_160 ) ) {
int V_161 = F_86 ( V_155 ) -
F_87 ( struct V_159 , V_160 ) ;
if ( V_161 <= V_162 )
* V_152 = F_88 ( V_163 , * V_152 ,
V_161 ) ;
}
V_153 ++ ;
V_150 = F_89 ( V_150 , & V_154 ) ;
}
return V_154 > 0 ? 0 : V_153 ;
}
static int F_90 ( struct V_134 * V_135 ,
struct V_1 * V_4 )
{
struct V_149 * V_150 = V_135 -> V_164 ;
struct V_146 * V_165 , * V_166 ;
int V_154 = V_135 -> V_167 ;
int V_153 = 0 ;
int V_77 = 0 ;
F_91 (rt) {
int V_157 ;
V_165 = NULL ;
V_166 = NULL ;
V_77 = - V_129 ;
if ( ! F_82 ( V_150 , V_154 ) )
goto V_128;
if ( V_150 -> V_168 || V_150 -> V_169 )
goto V_128;
V_157 = F_84 ( V_150 ) ;
if ( V_157 > 0 ) {
struct V_146 * V_156 = F_83 ( V_150 ) ;
V_165 = F_85 ( V_156 , V_157 , V_158 ) ;
V_166 = F_85 ( V_156 , V_157 , V_170 ) ;
}
V_77 = F_78 ( V_135 -> V_136 . V_137 , V_4 , V_15 ,
V_150 -> V_171 , V_165 , V_166 ) ;
if ( V_77 )
goto V_128;
if ( V_15 -> V_53 & ( V_54 | V_55 ) )
V_4 -> V_50 -- ;
V_150 = F_89 ( V_150 , & V_154 ) ;
V_153 ++ ;
} F_27 ( V_4 ) ;
V_4 -> V_18 = V_153 ;
return 0 ;
V_128:
return V_77 ;
}
static int F_92 ( struct V_134 * V_135 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = V_135 -> V_136 . V_137 ;
struct V_1 * V_4 , * V_99 ;
int V_77 = - V_129 ;
T_2 V_152 ;
unsigned V_3 ;
int V_153 ;
V_3 = V_135 -> V_172 ;
if ( ( V_3 == V_111 ) &&
( V_135 -> V_173 & V_174 ) ) {
V_3 = F_60 ( V_2 ) ;
}
if ( V_3 < V_37 )
goto V_128;
if ( V_3 >= V_2 -> V_5 . V_6 )
goto V_128;
V_77 = - V_175 ;
if ( V_135 -> V_173 & V_176 )
goto V_128;
V_77 = - V_177 ;
V_7 = F_58 ( V_2 -> V_5 . V_7 ) ;
V_99 = F_58 ( V_7 [ V_3 ] ) ;
if ( ( V_135 -> V_173 & V_178 ) && V_99 )
goto V_128;
V_77 = - V_177 ;
if ( ! ( V_135 -> V_173 & V_110 ) && V_99 )
goto V_128;
V_77 = - V_179 ;
if ( ! ( V_135 -> V_173 & V_174 ) && ! V_99 )
goto V_128;
V_77 = - V_129 ;
V_153 = F_81 ( V_135 -> V_164 , V_135 -> V_167 ,
V_135 -> V_144 , & V_152 ) ;
if ( V_153 == 0 )
goto V_128;
V_77 = - V_138 ;
V_4 = F_49 ( V_153 , V_152 ) ;
if ( ! V_4 )
goto V_128;
V_4 -> V_180 = V_135 -> V_181 ;
V_4 -> V_59 = V_135 -> V_182 ;
if ( V_135 -> V_164 )
V_77 = F_90 ( V_135 , V_4 ) ;
else
V_77 = F_77 ( V_135 , V_4 ) ;
if ( V_77 )
goto V_183;
F_56 ( V_2 , V_3 , V_4 , & V_135 -> V_136 ) ;
return 0 ;
V_183:
F_52 ( V_4 ) ;
V_128:
return V_77 ;
}
static int F_93 ( struct V_134 * V_135 )
{
struct V_2 * V_2 = V_135 -> V_136 . V_137 ;
unsigned V_3 ;
int V_77 = - V_129 ;
V_3 = V_135 -> V_172 ;
if ( V_3 < V_37 )
goto V_128;
if ( V_3 >= V_2 -> V_5 . V_6 )
goto V_128;
F_56 ( V_2 , V_3 , NULL , & V_135 -> V_136 ) ;
V_77 = 0 ;
V_128:
return V_77 ;
}
static int F_94 ( struct V_9 * V_10 ,
struct V_8 * V_74 )
{
char V_184 [ sizeof( L_2 ) + V_185 ] ;
struct V_186 * V_187 ;
int V_86 ;
V_187 = F_95 ( & V_188 , sizeof( V_188 ) , V_97 ) ;
if ( ! V_187 )
goto V_52;
for ( V_86 = 0 ; V_86 < F_96 ( V_188 ) ; V_86 ++ )
V_187 [ V_86 ] . V_189 = ( char * ) V_74 + ( V_190 ) V_187 [ V_86 ] . V_189 ;
snprintf ( V_184 , sizeof( V_184 ) , L_3 , V_10 -> V_191 ) ;
V_74 -> V_192 = F_97 ( F_34 ( V_10 ) , V_184 , V_187 ) ;
if ( ! V_74 -> V_192 )
goto free;
return 0 ;
free:
F_98 ( V_187 ) ;
V_52:
return - V_193 ;
}
static void F_99 ( struct V_8 * V_74 )
{
struct V_186 * V_187 ;
V_187 = V_74 -> V_192 -> V_194 ;
F_100 ( V_74 -> V_192 ) ;
F_98 ( V_187 ) ;
}
static struct V_8 * F_101 ( struct V_9 * V_10 )
{
struct V_8 * V_74 ;
int V_77 = - V_138 ;
F_57 () ;
V_74 = F_51 ( sizeof( * V_74 ) , V_97 ) ;
if ( ! V_74 )
return F_67 ( V_77 ) ;
V_77 = F_94 ( V_10 , V_74 ) ;
if ( V_77 )
goto free;
F_59 ( V_10 -> V_11 , V_74 ) ;
return V_74 ;
free:
F_98 ( V_74 ) ;
return F_67 ( V_77 ) ;
}
static void F_102 ( struct V_9 * V_10 , int V_106 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = F_34 ( V_10 ) ;
unsigned V_3 ;
V_7 = F_58 ( V_2 -> V_5 . V_7 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_6 ; V_3 ++ ) {
struct V_1 * V_4 = F_58 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
F_91 (rt) {
if ( F_58 ( V_15 -> V_83 ) != V_10 )
continue;
switch ( V_106 ) {
case V_195 :
case V_196 :
V_15 -> V_53 |= V_54 ;
case V_197 :
V_15 -> V_53 |= V_55 ;
F_25 ( V_4 -> V_50 ) = V_4 -> V_50 - 1 ;
break;
}
if ( V_106 == V_196 )
F_75 ( V_15 -> V_83 , NULL ) ;
} F_27 ( V_4 ) ;
}
}
static void F_103 ( struct V_9 * V_10 , unsigned int V_53 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = F_34 ( V_10 ) ;
unsigned V_3 ;
int V_49 ;
V_7 = F_58 ( V_2 -> V_5 . V_7 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_6 ; V_3 ++ ) {
struct V_1 * V_4 = F_58 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
V_49 = 0 ;
F_91 (rt) {
struct V_9 * V_83 =
F_58 ( V_15 -> V_83 ) ;
if ( ! ( V_15 -> V_53 & V_53 ) ) {
V_49 ++ ;
continue;
}
if ( V_83 != V_10 )
continue;
V_49 ++ ;
V_15 -> V_53 &= ~ V_53 ;
} F_27 ( V_4 ) ;
F_25 ( V_4 -> V_50 ) = V_49 ;
}
}
static int F_104 ( struct V_198 * V_199 , unsigned long V_106 ,
void * V_200 )
{
struct V_9 * V_10 = F_105 ( V_200 ) ;
struct V_8 * V_74 ;
unsigned int V_12 ;
if ( V_106 == V_201 ) {
if ( V_10 -> type == V_202 ||
V_10 -> type == V_203 ||
V_10 -> type == V_204 ||
V_10 -> type == V_205 ||
V_10 -> type == V_206 ) {
V_74 = F_101 ( V_10 ) ;
if ( F_63 ( V_74 ) )
return F_106 ( F_74 ( V_74 ) ) ;
}
return V_207 ;
}
V_74 = F_3 ( V_10 ) ;
if ( ! V_74 )
return V_207 ;
switch ( V_106 ) {
case V_195 :
F_102 ( V_10 , V_106 ) ;
break;
case V_208 :
V_12 = F_76 ( V_10 ) ;
if ( V_12 & ( V_132 | V_133 ) )
F_103 ( V_10 , V_54 | V_55 ) ;
else
F_103 ( V_10 , V_54 ) ;
break;
case V_197 :
V_12 = F_76 ( V_10 ) ;
if ( V_12 & ( V_132 | V_133 ) )
F_103 ( V_10 , V_54 | V_55 ) ;
else
F_102 ( V_10 , V_106 ) ;
break;
case V_196 :
F_102 ( V_10 , V_106 ) ;
V_74 = F_3 ( V_10 ) ;
if ( V_74 ) {
F_99 ( V_74 ) ;
F_75 ( V_10 -> V_11 , NULL ) ;
F_53 ( V_74 , V_209 ) ;
}
break;
case V_210 :
V_74 = F_3 ( V_10 ) ;
if ( V_74 ) {
int V_77 ;
F_99 ( V_74 ) ;
V_77 = F_94 ( V_10 , V_74 ) ;
if ( V_77 )
return F_106 ( V_77 ) ;
}
break;
}
return V_207 ;
}
static int F_107 ( struct V_25 * V_26 ,
T_2 V_187 , const void * V_112 , int V_211 )
{
static const int V_212 [ V_213 + 1 ] = {
V_214 , V_215 , V_216 , V_217 ,
} ;
struct V_146 * V_155 ;
struct V_159 * V_147 ;
int V_218 = V_219 ;
V_155 = F_108 ( V_26 , V_158 , V_211 + 2 ) ;
if ( ! V_155 )
return - V_220 ;
if ( V_187 <= V_213 )
V_218 = V_212 [ V_187 ] ;
V_147 = F_109 ( V_155 ) ;
V_147 -> V_221 = V_218 ;
memcpy ( V_147 -> V_160 , V_112 , V_211 ) ;
return 0 ;
}
int F_110 ( struct V_25 * V_26 , int V_222 ,
T_2 V_223 , const T_3 V_36 [] )
{
struct V_146 * V_155 ;
struct V_23 * V_224 ;
bool V_39 ;
int V_86 ;
V_155 = F_108 ( V_26 , V_222 , V_223 * 4 ) ;
if ( ! V_155 )
return - V_220 ;
V_224 = F_109 ( V_155 ) ;
V_39 = true ;
for ( V_86 = V_223 - 1 ; V_86 >= 0 ; V_86 -- ) {
V_224 [ V_86 ] = F_45 ( V_36 [ V_86 ] , 0 , 0 , V_39 ) ;
V_39 = false ;
}
return 0 ;
}
int F_79 ( const struct V_146 * V_155 ,
T_3 V_225 , T_2 * V_223 , T_3 V_36 [] )
{
unsigned V_27 = F_86 ( V_155 ) ;
unsigned V_226 ;
struct V_23 * V_224 ;
bool V_39 ;
int V_86 ;
if ( V_27 & 3 )
return - V_129 ;
V_226 = V_27 / 4 ;
if ( V_226 > V_225 )
return - V_129 ;
V_224 = F_109 ( V_155 ) ;
V_39 = true ;
for ( V_86 = V_226 - 1 ; V_86 >= 0 ; V_86 -- , V_39 = false ) {
struct V_28 V_29 ;
V_29 = F_18 ( V_224 + V_86 ) ;
if ( ( V_29 . V_39 != V_39 ) || V_29 . V_65 || V_29 . V_227 )
return - V_129 ;
switch ( V_29 . V_36 ) {
case V_228 :
return - V_129 ;
}
V_36 [ V_86 ] = V_29 . V_36 ;
}
* V_223 = V_226 ;
return 0 ;
}
int F_80 ( const struct V_146 * V_155 , T_2 * V_161 ,
T_2 * V_229 , T_2 V_230 [] )
{
struct V_159 * V_147 = F_109 ( V_155 ) ;
int V_77 = - V_129 ;
int V_211 ;
if ( F_86 ( V_155 ) < F_87 ( struct V_159 , V_160 ) )
goto V_128;
V_211 = F_86 ( V_155 ) -
F_87 ( struct V_159 , V_160 ) ;
if ( V_211 > V_162 )
goto V_128;
switch ( V_147 -> V_221 ) {
case V_217 :
* V_229 = V_90 ;
break;
case V_214 :
* V_229 = V_125 ;
if ( V_211 != 4 )
goto V_128;
break;
case V_215 :
* V_229 = V_126 ;
if ( V_211 != 16 )
goto V_128;
break;
default:
goto V_128;
}
memcpy ( V_230 , V_147 -> V_160 , V_211 ) ;
* V_161 = V_211 ;
V_77 = 0 ;
V_128:
return V_77 ;
}
static int F_111 ( struct V_25 * V_26 , struct V_103 * V_104 ,
struct V_134 * V_135 )
{
struct V_231 * V_232 ;
struct V_146 * V_233 [ V_234 + 1 ] ;
int V_3 ;
int V_77 ;
V_77 = F_112 ( V_104 , sizeof( * V_232 ) , V_233 , V_234 , V_235 ) ;
if ( V_77 < 0 )
goto V_128;
V_77 = - V_129 ;
V_232 = F_113 ( V_104 ) ;
memset ( V_135 , 0 , sizeof( * V_135 ) ) ;
if ( V_232 -> V_236 != V_237 )
goto V_128;
if ( V_232 -> V_238 != 20 )
goto V_128;
if ( V_232 -> V_239 != 0 )
goto V_128;
if ( V_232 -> V_240 != 0 )
goto V_128;
if ( V_232 -> V_241 != V_242 )
goto V_128;
if ( V_232 -> V_243 != V_244 )
goto V_128;
if ( V_232 -> V_245 != V_246 )
goto V_128;
if ( V_232 -> V_247 != 0 )
goto V_128;
V_135 -> V_172 = V_111 ;
V_135 -> V_181 = V_232 -> V_248 ;
V_135 -> V_142 = V_89 ;
V_135 -> V_173 = V_104 -> V_249 ;
V_135 -> V_136 . V_105 = F_114 ( V_26 ) . V_105 ;
V_135 -> V_136 . V_104 = V_104 ;
V_135 -> V_136 . V_137 = F_115 ( V_26 -> V_250 ) ;
for ( V_3 = 0 ; V_3 <= V_234 ; V_3 ++ ) {
struct V_146 * V_155 = V_233 [ V_3 ] ;
if ( ! V_155 )
continue;
switch ( V_3 ) {
case V_251 :
V_135 -> V_145 = F_116 ( V_155 ) ;
break;
case V_170 :
if ( F_79 ( V_155 , V_140 ,
& V_135 -> V_139 ,
V_135 -> V_141 ) )
goto V_128;
break;
case V_252 :
{
T_2 V_253 ;
if ( F_79 ( V_155 , 1 , & V_253 ,
& V_135 -> V_172 ) )
goto V_128;
if ( V_135 -> V_172 < V_37 )
goto V_128;
break;
}
case V_158 :
{
if ( F_80 ( V_155 , & V_135 -> V_144 ,
& V_135 -> V_142 , V_135 -> V_143 ) )
goto V_128;
break;
}
case V_254 :
{
V_135 -> V_164 = F_109 ( V_155 ) ;
V_135 -> V_167 = F_86 ( V_155 ) ;
break;
}
default:
goto V_128;
}
}
V_77 = 0 ;
V_128:
return V_77 ;
}
static int F_117 ( struct V_25 * V_26 , struct V_103 * V_104 )
{
struct V_134 V_135 ;
int V_77 ;
V_77 = F_111 ( V_26 , V_104 , & V_135 ) ;
if ( V_77 < 0 )
return V_77 ;
return F_93 ( & V_135 ) ;
}
static int F_118 ( struct V_25 * V_26 , struct V_103 * V_104 )
{
struct V_134 V_135 ;
int V_77 ;
V_77 = F_111 ( V_26 , V_104 , & V_135 ) ;
if ( V_77 < 0 )
return V_77 ;
return F_92 ( & V_135 ) ;
}
static int F_119 ( struct V_25 * V_26 , T_3 V_105 , T_3 V_255 , int V_106 ,
T_3 V_36 , struct V_1 * V_4 , int V_12 )
{
struct V_9 * V_10 ;
struct V_103 * V_104 ;
struct V_231 * V_232 ;
V_104 = F_120 ( V_26 , V_105 , V_255 , V_106 , sizeof( * V_232 ) , V_12 ) ;
if ( V_104 == NULL )
return - V_220 ;
V_232 = F_113 ( V_104 ) ;
V_232 -> V_236 = V_237 ;
V_232 -> V_238 = 20 ;
V_232 -> V_239 = 0 ;
V_232 -> V_240 = 0 ;
V_232 -> V_241 = V_242 ;
V_232 -> V_248 = V_4 -> V_180 ;
V_232 -> V_243 = V_244 ;
V_232 -> V_245 = V_246 ;
V_232 -> V_247 = 0 ;
if ( F_110 ( V_26 , V_252 , 1 , & V_36 ) )
goto V_256;
if ( V_4 -> V_18 == 1 ) {
const struct V_14 * V_15 = V_4 -> V_17 ;
if ( V_15 -> V_22 &&
F_110 ( V_26 , V_170 , V_15 -> V_22 ,
V_15 -> V_87 ) )
goto V_256;
if ( V_15 -> V_88 != V_89 &&
F_107 ( V_26 , V_15 -> V_88 , F_9 ( V_4 , V_15 ) ,
V_15 -> V_131 ) )
goto V_256;
V_10 = F_58 ( V_15 -> V_83 ) ;
if ( V_10 && F_121 ( V_26 , V_251 , V_10 -> V_257 ) )
goto V_256;
if ( V_15 -> V_53 & V_55 )
V_232 -> V_247 |= V_55 ;
if ( V_15 -> V_53 & V_54 )
V_232 -> V_247 |= V_54 ;
} else {
struct V_149 * V_150 ;
struct V_146 * V_258 ;
int V_259 = 0 ;
int V_260 = 0 ;
V_258 = F_122 ( V_26 , V_254 ) ;
if ( ! V_258 )
goto V_256;
F_26 (rt) {
V_150 = F_123 ( V_26 , sizeof( * V_150 ) ) ;
if ( ! V_150 )
goto V_256;
V_10 = F_58 ( V_15 -> V_83 ) ;
if ( V_10 )
V_150 -> V_171 = V_10 -> V_257 ;
if ( V_15 -> V_53 & V_55 ) {
V_150 -> V_169 |= V_55 ;
V_260 ++ ;
}
if ( V_15 -> V_53 & V_54 ) {
V_150 -> V_169 |= V_54 ;
V_259 ++ ;
}
if ( V_15 -> V_22 && F_110 ( V_26 , V_170 ,
V_15 -> V_22 ,
V_15 -> V_87 ) )
goto V_256;
if ( V_15 -> V_88 != V_89 &&
F_107 ( V_26 , V_15 -> V_88 ,
F_9 ( V_4 , V_15 ) ,
V_15 -> V_131 ) )
goto V_256;
V_150 -> V_261 = F_124 ( V_26 ) - ( void * ) V_150 ;
} F_27 ( V_4 ) ;
if ( V_260 == V_4 -> V_18 )
V_232 -> V_247 |= V_55 ;
if ( V_259 == V_4 -> V_18 )
V_232 -> V_247 |= V_54 ;
F_125 ( V_26 , V_258 ) ;
}
F_126 ( V_26 , V_104 ) ;
return 0 ;
V_256:
F_127 ( V_26 , V_104 ) ;
return - V_220 ;
}
static int F_128 ( struct V_25 * V_26 , struct V_262 * V_263 )
{
struct V_2 * V_2 = F_115 ( V_26 -> V_250 ) ;
struct V_1 T_1 * * V_7 ;
T_4 V_6 ;
unsigned int V_3 ;
F_57 () ;
V_3 = V_263 -> args [ 0 ] ;
if ( V_3 < V_37 )
V_3 = V_37 ;
V_7 = F_58 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for (; V_3 < V_6 ; V_3 ++ ) {
struct V_1 * V_4 ;
V_4 = F_58 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
if ( F_119 ( V_26 , F_114 ( V_263 -> V_26 ) . V_105 ,
V_263 -> V_104 -> V_264 , V_107 ,
V_3 , V_4 , V_265 ) < 0 )
break;
}
V_263 -> args [ 0 ] = V_3 ;
return V_26 -> V_27 ;
}
static inline T_4 F_129 ( struct V_1 * V_4 )
{
T_4 V_266 =
F_130 ( sizeof( struct V_231 ) )
+ F_131 ( 4 ) ;
if ( V_4 -> V_18 == 1 ) {
struct V_14 * V_15 = V_4 -> V_17 ;
if ( V_15 -> V_83 )
V_266 += F_131 ( 4 ) ;
if ( V_15 -> V_88 != V_89 )
V_266 += F_131 ( 2 + V_15 -> V_131 ) ;
if ( V_15 -> V_22 )
V_266 += F_131 ( V_15 -> V_22 * 4 ) ;
} else {
T_4 V_267 = 0 ;
F_26 (rt) {
V_267 += F_131 ( sizeof( struct V_149 ) ) ;
if ( V_15 -> V_88 != V_89 )
V_267 += F_131 ( 2 + V_15 -> V_131 ) ;
if ( V_15 -> V_22 )
V_267 += F_131 ( V_15 -> V_22 * 4 ) ;
} F_27 ( V_4 ) ;
V_266 += F_131 ( V_267 ) ;
}
return V_266 ;
}
static void F_55 ( int V_106 , T_3 V_36 , struct V_1 * V_4 ,
struct V_103 * V_104 , struct V_2 * V_2 , T_3 V_105 ,
unsigned int V_109 )
{
struct V_25 * V_26 ;
T_3 V_255 = V_104 ? V_104 -> V_264 : 0 ;
int V_77 = - V_193 ;
V_26 = F_132 ( F_129 ( V_4 ) , V_97 ) ;
if ( V_26 == NULL )
goto V_128;
V_77 = F_119 ( V_26 , V_105 , V_255 , V_106 , V_36 , V_4 , V_109 ) ;
if ( V_77 < 0 ) {
F_133 ( V_77 == - V_220 ) ;
F_48 ( V_26 ) ;
goto V_128;
}
F_134 ( V_26 , V_2 , V_105 , V_268 , V_104 , V_97 ) ;
return;
V_128:
if ( V_77 < 0 )
F_135 ( V_2 , V_268 , V_77 ) ;
}
static int F_136 ( struct V_2 * V_2 , T_4 V_269 )
{
T_4 V_270 = sizeof( struct V_1 * ) * V_269 ;
T_4 V_271 ;
T_4 V_272 ;
struct V_1 T_1 * * V_223 = NULL , * * V_99 ;
struct V_1 * V_273 = NULL , * V_274 = NULL ;
unsigned V_3 ;
if ( V_270 ) {
V_223 = F_51 ( V_270 , V_97 | V_275 | V_276 ) ;
if ( ! V_223 )
V_223 = F_137 ( V_270 ) ;
if ( ! V_223 )
goto V_277;
}
if ( V_269 > V_278 ) {
struct V_9 * V_279 = V_2 -> V_280 ;
V_273 = F_49 ( 1 , V_279 -> V_130 ) ;
if ( ! V_273 )
goto V_281;
F_75 ( V_273 -> V_17 -> V_83 , V_279 ) ;
V_273 -> V_180 = V_282 ;
V_273 -> V_59 = V_61 ;
V_273 -> V_17 -> V_88 = V_90 ;
V_273 -> V_17 -> V_131 = V_279 -> V_130 ;
memcpy ( F_7 ( V_273 , V_273 -> V_17 ) , V_279 -> V_91 ,
V_279 -> V_130 ) ;
}
if ( V_269 > V_283 ) {
struct V_9 * V_279 = V_2 -> V_280 ;
V_274 = F_49 ( 1 , V_279 -> V_130 ) ;
if ( ! V_274 )
goto V_284;
F_75 ( V_274 -> V_17 -> V_83 , V_279 ) ;
V_274 -> V_180 = V_282 ;
V_274 -> V_59 = V_66 ;
V_274 -> V_17 -> V_88 = V_90 ;
V_274 -> V_17 -> V_131 = V_279 -> V_130 ;
memcpy ( F_7 ( V_274 , V_274 -> V_17 ) , V_279 -> V_91 ,
V_279 -> V_130 ) ;
}
F_138 () ;
V_99 = F_58 ( V_2 -> V_5 . V_7 ) ;
V_271 = V_2 -> V_5 . V_6 ;
for ( V_3 = V_269 ; V_3 < V_271 ; V_3 ++ )
F_56 ( V_2 , V_3 , NULL , NULL ) ;
V_272 = V_270 ;
if ( V_271 < V_269 )
V_272 = V_271 * sizeof( struct V_1 * ) ;
memcpy ( V_223 , V_99 , V_272 ) ;
if ( ( V_271 <= V_283 ) &&
( V_269 > V_283 ) ) {
F_75 ( V_223 [ V_283 ] , V_274 ) ;
V_274 = NULL ;
}
if ( ( V_271 <= V_278 ) &&
( V_269 > V_278 ) ) {
F_75 ( V_223 [ V_278 ] , V_273 ) ;
V_273 = NULL ;
}
V_2 -> V_5 . V_6 = V_269 ;
F_59 ( V_2 -> V_5 . V_7 , V_223 ) ;
F_139 () ;
F_52 ( V_274 ) ;
F_52 ( V_273 ) ;
if ( V_99 ) {
F_140 () ;
F_141 ( V_99 ) ;
}
return 0 ;
V_284:
F_52 ( V_273 ) ;
V_281:
F_141 ( V_223 ) ;
V_277:
return - V_138 ;
}
static int F_142 ( struct V_186 * V_187 , int V_285 ,
void T_5 * V_286 , T_4 * V_287 , T_6 * V_288 )
{
struct V_2 * V_2 = V_187 -> V_189 ;
int V_6 = V_2 -> V_5 . V_6 ;
int V_289 ;
struct V_186 V_290 = {
. V_291 = V_187 -> V_291 ,
. V_189 = & V_6 ,
. V_292 = sizeof( int ) ,
. V_293 = V_187 -> V_293 ,
. V_294 = & V_295 ,
. V_296 = & V_297 ,
} ;
V_289 = F_143 ( & V_290 , V_285 , V_286 , V_287 , V_288 ) ;
if ( V_285 && V_289 == 0 )
V_289 = F_136 ( V_2 , V_6 ) ;
return V_289 ;
}
static int F_144 ( struct V_2 * V_2 )
{
struct V_186 * V_187 ;
V_2 -> V_5 . V_6 = 0 ;
V_2 -> V_5 . V_7 = NULL ;
V_187 = F_95 ( V_298 , sizeof( V_298 ) , V_97 ) ;
if ( V_187 == NULL )
return - V_138 ;
V_187 [ 0 ] . V_189 = V_2 ;
V_2 -> V_5 . V_299 = F_97 ( V_2 , L_4 , V_187 ) ;
if ( V_2 -> V_5 . V_299 == NULL ) {
F_98 ( V_187 ) ;
return - V_138 ;
}
return 0 ;
}
static void F_145 ( struct V_2 * V_2 )
{
struct V_1 T_1 * * V_7 ;
T_4 V_6 ;
struct V_186 * V_187 ;
unsigned int V_3 ;
V_187 = V_2 -> V_5 . V_299 -> V_194 ;
F_100 ( V_2 -> V_5 . V_299 ) ;
F_98 ( V_187 ) ;
F_138 () ;
V_7 = F_58 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ ) {
struct V_1 * V_4 = F_58 ( V_7 [ V_3 ] ) ;
F_75 ( V_7 [ V_3 ] , NULL ) ;
F_52 ( V_4 ) ;
}
F_139 () ;
F_141 ( V_7 ) ;
}
static int T_7 F_146 ( void )
{
int V_77 ;
F_147 ( sizeof( struct V_23 ) != 4 ) ;
V_77 = F_148 ( & V_300 ) ;
if ( V_77 )
goto V_52;
V_77 = F_149 ( & V_301 ) ;
if ( V_77 )
goto V_302;
F_150 ( & V_303 ) ;
F_151 ( V_304 , V_107 , F_118 , NULL , NULL ) ;
F_151 ( V_304 , V_108 , F_117 , NULL , NULL ) ;
F_151 ( V_304 , V_305 , NULL , F_128 , NULL ) ;
V_77 = 0 ;
V_52:
return V_77 ;
V_302:
F_152 ( & V_300 ) ;
goto V_52;
}
static void T_8 F_153 ( void )
{
F_154 ( V_304 ) ;
F_155 ( & V_303 ) ;
F_156 ( & V_301 ) ;
F_152 ( & V_300 ) ;
}
