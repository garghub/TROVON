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
if ( F_13 ( V_26 ) && F_14 ( V_26 ) <= V_24 )
return false ;
return true ;
}
static T_3 F_15 ( struct V_1 * V_4 ,
struct V_25 * V_26 , bool V_28 )
{
struct V_29 V_30 ;
struct V_23 * V_31 ;
bool V_32 = false ;
int V_33 ;
T_3 V_34 = 0 ;
for ( V_33 = 0 ; V_33 < V_35 && ! V_28 ;
V_33 ++ ) {
if ( ! F_16 ( V_26 , sizeof( * V_31 ) * V_33 ) )
break;
V_31 = F_17 ( V_26 ) + V_33 ;
V_30 = F_18 ( V_31 ) ;
if ( F_19 ( V_30 . V_36 >= V_37 ) ) {
V_34 = F_20 ( V_30 . V_36 , V_34 ) ;
if ( V_32 )
break;
} else if ( V_30 . V_36 == V_38 ) {
V_32 = true ;
}
V_28 = V_30 . V_28 ;
if ( V_28 && F_16 ( V_26 , sizeof( * V_31 ) * V_33 +
sizeof( struct V_39 ) ) ) {
const struct V_39 * V_40 ;
V_40 = ( const struct V_39 * ) ( F_17 ( V_26 ) +
V_33 ) ;
if ( V_40 -> V_41 == 4 ) {
V_34 = F_21 ( F_22 ( V_40 -> V_42 ) ,
F_22 ( V_40 -> V_43 ) ,
V_40 -> V_44 , V_34 ) ;
} else if ( V_40 -> V_41 == 6 &&
F_16 ( V_26 , sizeof( * V_31 ) * V_33 +
sizeof( struct V_45 ) ) ) {
const struct V_45 * V_46 ;
V_46 = ( const struct V_45 * ) ( F_17 ( V_26 ) +
V_33 ) ;
V_34 = F_23 ( & V_46 -> V_42 , V_34 ) ;
V_34 = F_23 ( & V_46 -> V_43 , V_34 ) ;
V_34 = F_20 ( V_46 -> V_47 , V_34 ) ;
}
}
}
return V_34 ;
}
static struct V_14 * F_24 ( struct V_1 * V_4 ,
struct V_25 * V_26 , bool V_28 )
{
int V_48 = F_25 ( V_4 -> V_49 ) ;
T_3 V_34 = 0 ;
int V_20 = 0 ;
int V_50 = 0 ;
if ( V_4 -> V_18 == 1 )
goto V_51;
if ( V_48 <= 0 )
return NULL ;
V_34 = F_15 ( V_4 , V_26 , V_28 ) ;
V_20 = V_34 % V_48 ;
if ( V_48 == V_4 -> V_18 )
goto V_51;
F_26 (rt) {
if ( V_15 -> V_52 & ( V_53 | V_54 ) )
continue;
if ( V_50 == V_20 )
return V_15 ;
V_50 ++ ;
} F_27 ( V_4 ) ;
V_51:
return & V_4 -> V_17 [ V_20 ] ;
}
static bool F_28 ( struct V_1 * V_4 , struct V_25 * V_26 ,
struct V_29 V_30 )
{
enum V_55 V_56 ;
bool V_57 = false ;
if ( ! F_16 ( V_26 , 12 ) )
return false ;
V_56 = V_4 -> V_58 ;
if ( V_56 == V_59 )
V_56 = F_29 ( V_26 ) -> V_41 ;
switch ( V_56 ) {
case V_60 : {
struct V_39 * V_61 = F_29 ( V_26 ) ;
V_26 -> V_44 = F_30 ( V_62 ) ;
F_31 ( & V_61 -> V_63 ,
F_30 ( V_61 -> V_64 << 8 ) ,
F_30 ( V_30 . V_64 << 8 ) ) ;
V_61 -> V_64 = V_30 . V_64 ;
V_57 = true ;
break;
}
case V_65 : {
struct V_45 * V_66 = F_32 ( V_26 ) ;
V_26 -> V_44 = F_30 ( V_67 ) ;
V_66 -> V_68 = V_30 . V_64 ;
V_57 = true ;
break;
}
case V_59 :
break;
}
return V_57 ;
}
static int F_33 ( struct V_25 * V_26 , struct V_9 * V_10 ,
struct V_69 * V_70 , struct V_9 * V_71 )
{
struct V_2 * V_2 = F_34 ( V_10 ) ;
struct V_23 * V_31 ;
struct V_1 * V_4 ;
struct V_14 * V_15 ;
struct V_29 V_30 ;
struct V_9 * V_72 ;
struct V_8 * V_73 ;
unsigned int V_74 ;
unsigned int V_75 ;
unsigned int V_24 ;
int V_76 ;
V_73 = F_3 ( V_10 ) ;
if ( ! V_73 || ! V_73 -> V_77 )
goto V_78;
if ( V_26 -> V_79 != V_80 )
goto V_78;
if ( ( V_26 = F_35 ( V_26 , V_81 ) ) == NULL )
goto V_78;
if ( ! F_16 ( V_26 , sizeof( * V_31 ) ) )
goto V_78;
V_31 = F_17 ( V_26 ) ;
V_30 = F_18 ( V_31 ) ;
F_36 ( V_26 , sizeof( * V_31 ) ) ;
F_37 ( V_26 ) ;
F_38 ( V_26 ) ;
V_4 = F_1 ( V_2 , V_30 . V_36 ) ;
if ( ! V_4 )
goto V_78;
V_15 = F_24 ( V_4 , V_26 , V_30 . V_28 ) ;
if ( ! V_15 )
goto V_78;
V_72 = F_2 ( V_15 -> V_82 ) ;
if ( ! F_5 ( V_72 ) )
goto V_78;
if ( F_39 ( V_26 ) )
goto V_78;
F_40 ( V_26 ) ;
if ( V_30 . V_64 <= 1 )
goto V_78;
V_30 . V_64 -= 1 ;
V_75 = F_10 ( V_15 ) ;
V_24 = F_11 ( V_72 ) ;
if ( F_12 ( V_26 , V_24 - V_75 ) )
goto V_78;
V_74 = F_41 ( V_72 ) ;
if ( ! V_72 -> V_83 )
V_74 = 0 ;
if ( F_42 ( V_26 , V_74 + V_75 ) )
goto V_78;
V_26 -> V_10 = V_72 ;
V_26 -> V_44 = F_30 ( V_84 ) ;
if ( F_43 ( ! V_75 && V_30 . V_28 ) ) {
if ( ! F_28 ( V_4 , V_26 , V_30 ) )
goto V_78;
} else {
bool V_28 ;
int V_85 ;
F_44 ( V_26 , V_75 ) ;
F_37 ( V_26 ) ;
V_31 = F_17 ( V_26 ) ;
V_28 = V_30 . V_28 ;
for ( V_85 = V_15 -> V_22 - 1 ; V_85 >= 0 ; V_85 -- ) {
V_31 [ V_85 ] = F_45 ( V_15 -> V_86 [ V_85 ] ,
V_30 . V_64 , 0 , V_28 ) ;
V_28 = false ;
}
}
if ( V_15 -> V_87 == V_88 )
V_76 = F_46 ( V_89 , V_72 ,
V_72 -> V_90 , V_26 ) ;
else
V_76 = F_46 ( V_15 -> V_87 , V_72 ,
F_9 ( V_4 , V_15 ) , V_26 ) ;
if ( V_76 )
F_47 ( L_1 ,
V_91 , V_76 ) ;
return 0 ;
V_78:
F_48 ( V_26 ) ;
return V_92 ;
}
static struct V_1 * F_49 ( int V_93 , T_2 V_94 )
{
T_2 V_95 = F_50 ( V_94 , V_19 ) ;
struct V_1 * V_4 ;
V_4 = F_51 ( F_50 ( sizeof( * V_4 ) + V_93 * sizeof( * V_4 -> V_17 ) ,
V_19 ) +
V_93 * V_95 ,
V_96 ) ;
if ( V_4 ) {
V_4 -> V_18 = V_93 ;
V_4 -> V_49 = V_93 ;
V_4 -> V_21 = V_95 ;
}
return V_4 ;
}
static void F_52 ( struct V_1 * V_4 )
{
if ( V_4 )
F_53 ( V_4 , V_97 ) ;
}
static void F_54 ( struct V_2 * V_2 , unsigned V_3 ,
struct V_1 * V_98 , struct V_1 * V_99 ,
const struct V_100 * V_101 )
{
struct V_102 * V_103 = V_101 ? V_101 -> V_103 : NULL ;
unsigned V_104 = V_101 ? V_101 -> V_104 : 0 ;
int V_105 = V_99 ? V_106 : V_107 ;
struct V_1 * V_4 = V_99 ? V_99 : V_98 ;
unsigned V_108 = ( V_98 && V_99 ) ? V_109 : 0 ;
if ( V_4 && ( V_3 >= V_37 ) )
F_55 ( V_105 , V_3 , V_4 , V_103 , V_2 , V_104 , V_108 ) ;
}
static void F_56 ( struct V_2 * V_2 , unsigned V_3 ,
struct V_1 * V_99 ,
const struct V_100 * V_101 )
{
struct V_1 T_1 * * V_7 ;
struct V_1 * V_4 ;
F_57 () ;
V_7 = F_58 ( V_2 -> V_5 . V_7 ) ;
V_4 = F_58 ( V_7 [ V_3 ] ) ;
F_59 ( V_7 [ V_3 ] , V_99 ) ;
F_54 ( V_2 , V_3 , V_4 , V_99 , V_101 ) ;
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
return V_110 ;
}
static struct V_9 * F_61 ( struct V_2 * V_2 ,
const void * V_111 )
{
struct V_9 * V_10 ;
struct V_112 * V_4 ;
struct V_113 V_43 ;
memcpy ( & V_43 , V_111 , sizeof( struct V_113 ) ) ;
V_4 = F_62 ( V_2 , V_43 . V_114 , 0 , 0 , 0 ) ;
if ( F_63 ( V_4 ) )
return F_64 ( V_4 ) ;
V_10 = V_4 -> V_115 . V_10 ;
F_65 ( V_10 ) ;
F_66 ( V_4 ) ;
return V_10 ;
}
static struct V_9 * F_61 ( struct V_2 * V_2 ,
const void * V_111 )
{
return F_67 ( - V_116 ) ;
}
static struct V_9 * F_68 ( struct V_2 * V_2 ,
const void * V_111 )
{
struct V_9 * V_10 ;
struct V_117 * V_115 ;
struct V_118 V_119 ;
int V_76 ;
if ( ! V_120 )
return F_67 ( - V_116 ) ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
memcpy ( & V_119 . V_43 , V_111 , sizeof( struct V_121 ) ) ;
V_76 = V_120 -> V_122 ( V_2 , NULL , & V_115 , & V_119 ) ;
if ( V_76 )
return F_67 ( V_76 ) ;
V_10 = V_115 -> V_10 ;
F_65 ( V_10 ) ;
F_69 ( V_115 ) ;
return V_10 ;
}
static struct V_9 * F_68 ( struct V_2 * V_2 ,
const void * V_111 )
{
return F_67 ( - V_116 ) ;
}
static struct V_9 * F_70 ( struct V_2 * V_2 ,
struct V_1 * V_4 ,
struct V_14 * V_15 , int V_123 )
{
struct V_9 * V_10 = NULL ;
if ( ! V_123 ) {
switch ( V_15 -> V_87 ) {
case V_124 :
V_10 = F_61 ( V_2 , F_9 ( V_4 , V_15 ) ) ;
break;
case V_125 :
V_10 = F_68 ( V_2 , F_9 ( V_4 , V_15 ) ) ;
break;
case V_89 :
break;
}
} else {
V_10 = F_71 ( V_2 , V_123 ) ;
}
if ( ! V_10 )
return F_67 ( - V_126 ) ;
if ( F_63 ( V_10 ) )
return V_10 ;
F_72 ( V_10 ) ;
return V_10 ;
}
static int F_73 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_14 * V_15 , int V_123 )
{
struct V_9 * V_10 = NULL ;
int V_76 = - V_126 ;
V_10 = F_70 ( V_2 , V_4 , V_15 , V_123 ) ;
if ( F_63 ( V_10 ) ) {
V_76 = F_74 ( V_10 ) ;
V_10 = NULL ;
goto V_127;
}
V_76 = - V_128 ;
if ( ! F_3 ( V_10 ) )
goto V_127;
if ( ( V_15 -> V_87 == V_89 ) &&
( V_10 -> V_129 != V_15 -> V_130 ) )
goto V_127;
F_75 ( V_15 -> V_82 , V_10 ) ;
if ( ! ( V_10 -> V_12 & V_13 ) ) {
V_15 -> V_52 |= V_53 ;
} else {
unsigned int V_12 ;
V_12 = F_76 ( V_10 ) ;
if ( ! ( V_12 & ( V_131 | V_132 ) ) )
V_15 -> V_52 |= V_54 ;
}
return 0 ;
V_127:
return V_76 ;
}
static int F_77 ( struct V_133 * V_134 ,
struct V_1 * V_4 )
{
struct V_2 * V_2 = V_134 -> V_135 . V_136 ;
struct V_14 * V_15 = V_4 -> V_17 ;
int V_76 ;
int V_85 ;
if ( ! V_15 )
return - V_137 ;
V_76 = - V_128 ;
if ( V_134 -> V_138 > V_139 )
goto V_127;
V_15 -> V_22 = V_134 -> V_138 ;
for ( V_85 = 0 ; V_85 < V_15 -> V_22 ; V_85 ++ )
V_15 -> V_86 [ V_85 ] = V_134 -> V_140 [ V_85 ] ;
V_15 -> V_87 = V_134 -> V_141 ;
memcpy ( F_7 ( V_4 , V_15 ) , V_134 -> V_142 , V_134 -> V_143 ) ;
V_15 -> V_130 = V_134 -> V_143 ;
V_76 = F_73 ( V_2 , V_4 , V_15 , V_134 -> V_144 ) ;
if ( V_76 )
goto V_127;
if ( V_15 -> V_52 & ( V_53 | V_54 ) )
V_4 -> V_49 -- ;
return 0 ;
V_127:
return V_76 ;
}
static int F_78 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_14 * V_15 , int V_123 , struct V_145 * V_146 ,
struct V_145 * V_147 )
{
int V_76 = - V_137 ;
if ( ! V_15 )
goto V_127;
if ( V_147 ) {
V_76 = F_79 ( V_147 , V_139 ,
& V_15 -> V_22 , V_15 -> V_86 ) ;
if ( V_76 )
goto V_127;
}
if ( V_146 ) {
V_76 = F_80 ( V_146 , & V_15 -> V_130 , & V_15 -> V_87 ,
F_7 ( V_4 , V_15 ) ) ;
if ( V_76 )
goto V_127;
} else {
V_15 -> V_87 = V_88 ;
}
V_76 = F_73 ( V_2 , V_4 , V_15 , V_123 ) ;
if ( V_76 )
goto V_127;
return 0 ;
V_127:
return V_76 ;
}
static int F_81 ( struct V_148 * V_149 , int V_27 ,
T_2 V_150 , T_2 * V_151 )
{
int V_152 = 0 ;
int V_153 = V_27 ;
if ( ! V_149 ) {
* V_151 = V_150 ;
return 1 ;
}
* V_151 = 0 ;
while ( F_82 ( V_149 , V_153 ) ) {
struct V_145 * V_154 , * V_155 = F_83 ( V_149 ) ;
int V_156 ;
V_156 = F_84 ( V_149 ) ;
V_154 = F_85 ( V_155 , V_156 , V_157 ) ;
if ( V_154 && F_86 ( V_154 ) >=
F_87 ( struct V_158 , V_159 ) ) {
int V_160 = F_86 ( V_154 ) -
F_87 ( struct V_158 , V_159 ) ;
if ( V_160 <= V_161 )
* V_151 = F_88 ( V_162 , * V_151 ,
V_160 ) ;
}
V_152 ++ ;
V_149 = F_89 ( V_149 , & V_153 ) ;
}
return V_153 > 0 ? 0 : V_152 ;
}
static int F_90 ( struct V_133 * V_134 ,
struct V_1 * V_4 )
{
struct V_148 * V_149 = V_134 -> V_163 ;
struct V_145 * V_164 , * V_165 ;
int V_153 = V_134 -> V_166 ;
int V_152 = 0 ;
int V_76 = 0 ;
F_91 (rt) {
int V_156 ;
V_164 = NULL ;
V_165 = NULL ;
V_76 = - V_128 ;
if ( ! F_82 ( V_149 , V_153 ) )
goto V_127;
if ( V_149 -> V_167 || V_149 -> V_168 )
goto V_127;
V_156 = F_84 ( V_149 ) ;
if ( V_156 > 0 ) {
struct V_145 * V_155 = F_83 ( V_149 ) ;
V_164 = F_85 ( V_155 , V_156 , V_157 ) ;
V_165 = F_85 ( V_155 , V_156 , V_169 ) ;
}
V_76 = F_78 ( V_134 -> V_135 . V_136 , V_4 , V_15 ,
V_149 -> V_170 , V_164 , V_165 ) ;
if ( V_76 )
goto V_127;
if ( V_15 -> V_52 & ( V_53 | V_54 ) )
V_4 -> V_49 -- ;
V_149 = F_89 ( V_149 , & V_153 ) ;
V_152 ++ ;
} F_27 ( V_4 ) ;
V_4 -> V_18 = V_152 ;
return 0 ;
V_127:
return V_76 ;
}
static int F_92 ( struct V_133 * V_134 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = V_134 -> V_135 . V_136 ;
struct V_1 * V_4 , * V_98 ;
int V_76 = - V_128 ;
T_2 V_151 ;
unsigned V_3 ;
int V_152 ;
V_3 = V_134 -> V_171 ;
if ( ( V_3 == V_110 ) &&
( V_134 -> V_172 & V_173 ) ) {
V_3 = F_60 ( V_2 ) ;
}
if ( V_3 < V_37 )
goto V_127;
if ( V_3 >= V_2 -> V_5 . V_6 )
goto V_127;
V_76 = - V_174 ;
if ( V_134 -> V_172 & V_175 )
goto V_127;
V_76 = - V_176 ;
V_7 = F_58 ( V_2 -> V_5 . V_7 ) ;
V_98 = F_58 ( V_7 [ V_3 ] ) ;
if ( ( V_134 -> V_172 & V_177 ) && V_98 )
goto V_127;
V_76 = - V_176 ;
if ( ! ( V_134 -> V_172 & V_109 ) && V_98 )
goto V_127;
V_76 = - V_178 ;
if ( ! ( V_134 -> V_172 & V_173 ) && ! V_98 )
goto V_127;
V_76 = - V_128 ;
V_152 = F_81 ( V_134 -> V_163 , V_134 -> V_166 ,
V_134 -> V_143 , & V_151 ) ;
if ( V_152 == 0 )
goto V_127;
V_76 = - V_137 ;
V_4 = F_49 ( V_152 , V_151 ) ;
if ( ! V_4 )
goto V_127;
V_4 -> V_179 = V_134 -> V_180 ;
V_4 -> V_58 = V_134 -> V_181 ;
if ( V_134 -> V_163 )
V_76 = F_90 ( V_134 , V_4 ) ;
else
V_76 = F_77 ( V_134 , V_4 ) ;
if ( V_76 )
goto V_182;
F_56 ( V_2 , V_3 , V_4 , & V_134 -> V_135 ) ;
return 0 ;
V_182:
F_52 ( V_4 ) ;
V_127:
return V_76 ;
}
static int F_93 ( struct V_133 * V_134 )
{
struct V_2 * V_2 = V_134 -> V_135 . V_136 ;
unsigned V_3 ;
int V_76 = - V_128 ;
V_3 = V_134 -> V_171 ;
if ( V_3 < V_37 )
goto V_127;
if ( V_3 >= V_2 -> V_5 . V_6 )
goto V_127;
F_56 ( V_2 , V_3 , NULL , & V_134 -> V_135 ) ;
V_76 = 0 ;
V_127:
return V_76 ;
}
static int F_94 ( struct V_9 * V_10 ,
struct V_8 * V_73 )
{
char V_183 [ sizeof( L_2 ) + V_184 ] ;
struct V_185 * V_186 ;
int V_85 ;
V_186 = F_95 ( & V_187 , sizeof( V_187 ) , V_96 ) ;
if ( ! V_186 )
goto V_51;
for ( V_85 = 0 ; V_85 < F_96 ( V_187 ) ; V_85 ++ )
V_186 [ V_85 ] . V_188 = ( char * ) V_73 + ( V_189 ) V_186 [ V_85 ] . V_188 ;
snprintf ( V_183 , sizeof( V_183 ) , L_3 , V_10 -> V_190 ) ;
V_73 -> V_191 = F_97 ( F_34 ( V_10 ) , V_183 , V_186 ) ;
if ( ! V_73 -> V_191 )
goto free;
return 0 ;
free:
F_98 ( V_186 ) ;
V_51:
return - V_192 ;
}
static void F_99 ( struct V_8 * V_73 )
{
struct V_185 * V_186 ;
V_186 = V_73 -> V_191 -> V_193 ;
F_100 ( V_73 -> V_191 ) ;
F_98 ( V_186 ) ;
}
static struct V_8 * F_101 ( struct V_9 * V_10 )
{
struct V_8 * V_73 ;
int V_76 = - V_137 ;
F_57 () ;
V_73 = F_51 ( sizeof( * V_73 ) , V_96 ) ;
if ( ! V_73 )
return F_67 ( V_76 ) ;
V_76 = F_94 ( V_10 , V_73 ) ;
if ( V_76 )
goto free;
F_59 ( V_10 -> V_11 , V_73 ) ;
return V_73 ;
free:
F_98 ( V_73 ) ;
return F_67 ( V_76 ) ;
}
static void F_102 ( struct V_9 * V_10 , int V_105 )
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
if ( F_58 ( V_15 -> V_82 ) != V_10 )
continue;
switch ( V_105 ) {
case V_194 :
case V_195 :
V_15 -> V_52 |= V_53 ;
case V_196 :
V_15 -> V_52 |= V_54 ;
F_25 ( V_4 -> V_49 ) = V_4 -> V_49 - 1 ;
break;
}
if ( V_105 == V_195 )
F_75 ( V_15 -> V_82 , NULL ) ;
} F_27 ( V_4 ) ;
}
return;
}
static void F_103 ( struct V_9 * V_10 , unsigned int V_52 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = F_34 ( V_10 ) ;
unsigned V_3 ;
int V_48 ;
V_7 = F_58 ( V_2 -> V_5 . V_7 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_6 ; V_3 ++ ) {
struct V_1 * V_4 = F_58 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
V_48 = 0 ;
F_91 (rt) {
struct V_9 * V_82 =
F_58 ( V_15 -> V_82 ) ;
if ( ! ( V_15 -> V_52 & V_52 ) ) {
V_48 ++ ;
continue;
}
if ( V_82 != V_10 )
continue;
V_48 ++ ;
V_15 -> V_52 &= ~ V_52 ;
} F_27 ( V_4 ) ;
F_25 ( V_4 -> V_49 ) = V_48 ;
}
return;
}
static int F_104 ( struct V_197 * V_198 , unsigned long V_105 ,
void * V_199 )
{
struct V_9 * V_10 = F_105 ( V_199 ) ;
struct V_8 * V_73 ;
unsigned int V_12 ;
if ( V_105 == V_200 ) {
if ( ( V_10 -> type == V_201 ) ||
( V_10 -> type == V_202 ) ) {
V_73 = F_101 ( V_10 ) ;
if ( F_63 ( V_73 ) )
return F_106 ( F_74 ( V_73 ) ) ;
}
return V_203 ;
}
V_73 = F_3 ( V_10 ) ;
if ( ! V_73 )
return V_203 ;
switch ( V_105 ) {
case V_194 :
F_102 ( V_10 , V_105 ) ;
break;
case V_204 :
V_12 = F_76 ( V_10 ) ;
if ( V_12 & ( V_131 | V_132 ) )
F_103 ( V_10 , V_53 | V_54 ) ;
else
F_103 ( V_10 , V_53 ) ;
break;
case V_196 :
V_12 = F_76 ( V_10 ) ;
if ( V_12 & ( V_131 | V_132 ) )
F_103 ( V_10 , V_53 | V_54 ) ;
else
F_102 ( V_10 , V_105 ) ;
break;
case V_195 :
F_102 ( V_10 , V_105 ) ;
V_73 = F_3 ( V_10 ) ;
if ( V_73 ) {
F_99 ( V_73 ) ;
F_75 ( V_10 -> V_11 , NULL ) ;
F_53 ( V_73 , V_205 ) ;
}
break;
case V_206 :
V_73 = F_3 ( V_10 ) ;
if ( V_73 ) {
int V_76 ;
F_99 ( V_73 ) ;
V_76 = F_94 ( V_10 , V_73 ) ;
if ( V_76 )
return F_106 ( V_76 ) ;
}
break;
}
return V_203 ;
}
static int F_107 ( struct V_25 * V_26 ,
T_2 V_186 , const void * V_111 , int V_207 )
{
static const int V_208 [ V_209 + 1 ] = {
V_210 , V_211 , V_212 , V_213 ,
} ;
struct V_145 * V_154 ;
struct V_158 * V_146 ;
int V_214 = V_215 ;
V_154 = F_108 ( V_26 , V_157 , V_207 + 2 ) ;
if ( ! V_154 )
return - V_216 ;
if ( V_186 <= V_209 )
V_214 = V_208 [ V_186 ] ;
V_146 = F_109 ( V_154 ) ;
V_146 -> V_217 = V_214 ;
memcpy ( V_146 -> V_159 , V_111 , V_207 ) ;
return 0 ;
}
int F_110 ( struct V_25 * V_26 , int V_218 ,
T_2 V_219 , const T_3 V_36 [] )
{
struct V_145 * V_154 ;
struct V_23 * V_220 ;
bool V_28 ;
int V_85 ;
V_154 = F_108 ( V_26 , V_218 , V_219 * 4 ) ;
if ( ! V_154 )
return - V_216 ;
V_220 = F_109 ( V_154 ) ;
V_28 = true ;
for ( V_85 = V_219 - 1 ; V_85 >= 0 ; V_85 -- ) {
V_220 [ V_85 ] = F_45 ( V_36 [ V_85 ] , 0 , 0 , V_28 ) ;
V_28 = false ;
}
return 0 ;
}
int F_79 ( const struct V_145 * V_154 ,
T_3 V_221 , T_2 * V_219 , T_3 V_36 [] )
{
unsigned V_27 = F_86 ( V_154 ) ;
unsigned V_222 ;
struct V_23 * V_220 ;
bool V_28 ;
int V_85 ;
if ( V_27 & 3 )
return - V_128 ;
V_222 = V_27 / 4 ;
if ( V_222 > V_221 )
return - V_128 ;
V_220 = F_109 ( V_154 ) ;
V_28 = true ;
for ( V_85 = V_222 - 1 ; V_85 >= 0 ; V_85 -- , V_28 = false ) {
struct V_29 V_30 ;
V_30 = F_18 ( V_220 + V_85 ) ;
if ( ( V_30 . V_28 != V_28 ) || V_30 . V_64 || V_30 . V_223 )
return - V_128 ;
switch ( V_30 . V_36 ) {
case V_224 :
return - V_128 ;
}
V_36 [ V_85 ] = V_30 . V_36 ;
}
* V_219 = V_222 ;
return 0 ;
}
int F_80 ( const struct V_145 * V_154 , T_2 * V_160 ,
T_2 * V_225 , T_2 V_226 [] )
{
struct V_158 * V_146 = F_109 ( V_154 ) ;
int V_76 = - V_128 ;
int V_207 ;
if ( F_86 ( V_154 ) < F_87 ( struct V_158 , V_159 ) )
goto V_127;
V_207 = F_86 ( V_154 ) -
F_87 ( struct V_158 , V_159 ) ;
if ( V_207 > V_161 )
goto V_127;
switch ( V_146 -> V_217 ) {
case V_213 :
* V_225 = V_89 ;
break;
case V_210 :
* V_225 = V_124 ;
if ( V_207 != 4 )
goto V_127;
break;
case V_211 :
* V_225 = V_125 ;
if ( V_207 != 16 )
goto V_127;
break;
default:
goto V_127;
}
memcpy ( V_226 , V_146 -> V_159 , V_207 ) ;
* V_160 = V_207 ;
V_76 = 0 ;
V_127:
return V_76 ;
}
static int F_111 ( struct V_25 * V_26 , struct V_102 * V_103 ,
struct V_133 * V_134 )
{
struct V_227 * V_228 ;
struct V_145 * V_229 [ V_230 + 1 ] ;
int V_3 ;
int V_76 ;
V_76 = F_112 ( V_103 , sizeof( * V_228 ) , V_229 , V_230 , V_231 ) ;
if ( V_76 < 0 )
goto V_127;
V_76 = - V_128 ;
V_228 = F_113 ( V_103 ) ;
memset ( V_134 , 0 , sizeof( * V_134 ) ) ;
if ( V_228 -> V_232 != V_233 )
goto V_127;
if ( V_228 -> V_234 != 20 )
goto V_127;
if ( V_228 -> V_235 != 0 )
goto V_127;
if ( V_228 -> V_236 != 0 )
goto V_127;
if ( V_228 -> V_237 != V_238 )
goto V_127;
if ( V_228 -> V_239 != V_240 )
goto V_127;
if ( V_228 -> V_241 != V_242 )
goto V_127;
if ( V_228 -> V_243 != 0 )
goto V_127;
V_134 -> V_171 = V_110 ;
V_134 -> V_180 = V_228 -> V_244 ;
V_134 -> V_141 = V_88 ;
V_134 -> V_172 = V_103 -> V_245 ;
V_134 -> V_135 . V_104 = F_114 ( V_26 ) . V_104 ;
V_134 -> V_135 . V_103 = V_103 ;
V_134 -> V_135 . V_136 = F_115 ( V_26 -> V_246 ) ;
for ( V_3 = 0 ; V_3 <= V_230 ; V_3 ++ ) {
struct V_145 * V_154 = V_229 [ V_3 ] ;
if ( ! V_154 )
continue;
switch( V_3 ) {
case V_247 :
V_134 -> V_144 = F_116 ( V_154 ) ;
break;
case V_169 :
if ( F_79 ( V_154 , V_139 ,
& V_134 -> V_138 ,
V_134 -> V_140 ) )
goto V_127;
break;
case V_248 :
{
T_2 V_249 ;
if ( F_79 ( V_154 , 1 , & V_249 ,
& V_134 -> V_171 ) )
goto V_127;
if ( V_134 -> V_171 < V_37 )
goto V_127;
break;
}
case V_157 :
{
if ( F_80 ( V_154 , & V_134 -> V_143 ,
& V_134 -> V_141 , V_134 -> V_142 ) )
goto V_127;
break;
}
case V_250 :
{
V_134 -> V_163 = F_109 ( V_154 ) ;
V_134 -> V_166 = F_86 ( V_154 ) ;
break;
}
default:
goto V_127;
}
}
V_76 = 0 ;
V_127:
return V_76 ;
}
static int F_117 ( struct V_25 * V_26 , struct V_102 * V_103 )
{
struct V_133 V_134 ;
int V_76 ;
V_76 = F_111 ( V_26 , V_103 , & V_134 ) ;
if ( V_76 < 0 )
return V_76 ;
return F_93 ( & V_134 ) ;
}
static int F_118 ( struct V_25 * V_26 , struct V_102 * V_103 )
{
struct V_133 V_134 ;
int V_76 ;
V_76 = F_111 ( V_26 , V_103 , & V_134 ) ;
if ( V_76 < 0 )
return V_76 ;
return F_92 ( & V_134 ) ;
}
static int F_119 ( struct V_25 * V_26 , T_3 V_104 , T_3 V_251 , int V_105 ,
T_3 V_36 , struct V_1 * V_4 , int V_12 )
{
struct V_9 * V_10 ;
struct V_102 * V_103 ;
struct V_227 * V_228 ;
V_103 = F_120 ( V_26 , V_104 , V_251 , V_105 , sizeof( * V_228 ) , V_12 ) ;
if ( V_103 == NULL )
return - V_216 ;
V_228 = F_113 ( V_103 ) ;
V_228 -> V_232 = V_233 ;
V_228 -> V_234 = 20 ;
V_228 -> V_235 = 0 ;
V_228 -> V_236 = 0 ;
V_228 -> V_237 = V_238 ;
V_228 -> V_244 = V_4 -> V_179 ;
V_228 -> V_239 = V_240 ;
V_228 -> V_241 = V_242 ;
V_228 -> V_243 = 0 ;
if ( F_110 ( V_26 , V_248 , 1 , & V_36 ) )
goto V_252;
if ( V_4 -> V_18 == 1 ) {
const struct V_14 * V_15 = V_4 -> V_17 ;
if ( V_15 -> V_22 &&
F_110 ( V_26 , V_169 , V_15 -> V_22 ,
V_15 -> V_86 ) )
goto V_252;
if ( V_15 -> V_87 != V_88 &&
F_107 ( V_26 , V_15 -> V_87 , F_9 ( V_4 , V_15 ) ,
V_15 -> V_130 ) )
goto V_252;
V_10 = F_58 ( V_15 -> V_82 ) ;
if ( V_10 && F_121 ( V_26 , V_247 , V_10 -> V_253 ) )
goto V_252;
if ( V_15 -> V_52 & V_54 )
V_228 -> V_243 |= V_54 ;
if ( V_15 -> V_52 & V_53 )
V_228 -> V_243 |= V_53 ;
} else {
struct V_148 * V_149 ;
struct V_145 * V_254 ;
int V_255 = 0 ;
int V_256 = 0 ;
V_254 = F_122 ( V_26 , V_250 ) ;
if ( ! V_254 )
goto V_252;
F_26 (rt) {
V_149 = F_123 ( V_26 , sizeof( * V_149 ) ) ;
if ( ! V_149 )
goto V_252;
V_10 = F_58 ( V_15 -> V_82 ) ;
if ( V_10 )
V_149 -> V_170 = V_10 -> V_253 ;
if ( V_15 -> V_52 & V_54 ) {
V_149 -> V_168 |= V_54 ;
V_256 ++ ;
}
if ( V_15 -> V_52 & V_53 ) {
V_149 -> V_168 |= V_53 ;
V_255 ++ ;
}
if ( V_15 -> V_22 && F_110 ( V_26 , V_169 ,
V_15 -> V_22 ,
V_15 -> V_86 ) )
goto V_252;
if ( V_15 -> V_87 != V_88 &&
F_107 ( V_26 , V_15 -> V_87 ,
F_9 ( V_4 , V_15 ) ,
V_15 -> V_130 ) )
goto V_252;
V_149 -> V_257 = F_124 ( V_26 ) - ( void * ) V_149 ;
} F_27 ( V_4 ) ;
if ( V_256 == V_4 -> V_18 )
V_228 -> V_243 |= V_54 ;
if ( V_255 == V_4 -> V_18 )
V_228 -> V_243 |= V_53 ;
F_125 ( V_26 , V_254 ) ;
}
F_126 ( V_26 , V_103 ) ;
return 0 ;
V_252:
F_127 ( V_26 , V_103 ) ;
return - V_216 ;
}
static int F_128 ( struct V_25 * V_26 , struct V_258 * V_259 )
{
struct V_2 * V_2 = F_115 ( V_26 -> V_246 ) ;
struct V_1 T_1 * * V_7 ;
T_4 V_6 ;
unsigned int V_3 ;
F_57 () ;
V_3 = V_259 -> args [ 0 ] ;
if ( V_3 < V_37 )
V_3 = V_37 ;
V_7 = F_58 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for (; V_3 < V_6 ; V_3 ++ ) {
struct V_1 * V_4 ;
V_4 = F_58 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
if ( F_119 ( V_26 , F_114 ( V_259 -> V_26 ) . V_104 ,
V_259 -> V_103 -> V_260 , V_106 ,
V_3 , V_4 , V_261 ) < 0 )
break;
}
V_259 -> args [ 0 ] = V_3 ;
return V_26 -> V_27 ;
}
static inline T_4 F_129 ( struct V_1 * V_4 )
{
T_4 V_262 =
F_130 ( sizeof( struct V_227 ) )
+ F_131 ( 4 ) ;
if ( V_4 -> V_18 == 1 ) {
struct V_14 * V_15 = V_4 -> V_17 ;
if ( V_15 -> V_82 )
V_262 += F_131 ( 4 ) ;
if ( V_15 -> V_87 != V_88 )
V_262 += F_131 ( 2 + V_15 -> V_130 ) ;
if ( V_15 -> V_22 )
V_262 += F_131 ( V_15 -> V_22 * 4 ) ;
} else {
T_4 V_263 = 0 ;
F_26 (rt) {
V_263 += F_131 ( sizeof( struct V_148 ) ) ;
if ( V_15 -> V_87 != V_88 )
V_263 += F_131 ( 2 + V_15 -> V_130 ) ;
if ( V_15 -> V_22 )
V_263 += F_131 ( V_15 -> V_22 * 4 ) ;
} F_27 ( V_4 ) ;
V_262 += F_131 ( V_263 ) ;
}
return V_262 ;
}
static void F_55 ( int V_105 , T_3 V_36 , struct V_1 * V_4 ,
struct V_102 * V_103 , struct V_2 * V_2 , T_3 V_104 ,
unsigned int V_108 )
{
struct V_25 * V_26 ;
T_3 V_251 = V_103 ? V_103 -> V_260 : 0 ;
int V_76 = - V_192 ;
V_26 = F_132 ( F_129 ( V_4 ) , V_96 ) ;
if ( V_26 == NULL )
goto V_127;
V_76 = F_119 ( V_26 , V_104 , V_251 , V_105 , V_36 , V_4 , V_108 ) ;
if ( V_76 < 0 ) {
F_133 ( V_76 == - V_216 ) ;
F_48 ( V_26 ) ;
goto V_127;
}
F_134 ( V_26 , V_2 , V_104 , V_264 , V_103 , V_96 ) ;
return;
V_127:
if ( V_76 < 0 )
F_135 ( V_2 , V_264 , V_76 ) ;
}
static int F_136 ( struct V_2 * V_2 , T_4 V_265 )
{
T_4 V_266 = sizeof( struct V_1 * ) * V_265 ;
T_4 V_267 ;
T_4 V_268 ;
struct V_1 T_1 * * V_219 = NULL , * * V_98 ;
struct V_1 * V_269 = NULL , * V_270 = NULL ;
unsigned V_3 ;
if ( V_266 ) {
V_219 = F_51 ( V_266 , V_96 | V_271 | V_272 ) ;
if ( ! V_219 )
V_219 = F_137 ( V_266 ) ;
if ( ! V_219 )
goto V_273;
}
if ( V_265 > V_274 ) {
struct V_9 * V_275 = V_2 -> V_276 ;
V_269 = F_49 ( 1 , V_275 -> V_129 ) ;
if ( ! V_269 )
goto V_277;
F_75 ( V_269 -> V_17 -> V_82 , V_275 ) ;
V_269 -> V_179 = V_278 ;
V_269 -> V_58 = V_60 ;
V_269 -> V_17 -> V_87 = V_89 ;
V_269 -> V_17 -> V_130 = V_275 -> V_129 ;
memcpy ( F_7 ( V_269 , V_269 -> V_17 ) , V_275 -> V_90 ,
V_275 -> V_129 ) ;
}
if ( V_265 > V_279 ) {
struct V_9 * V_275 = V_2 -> V_276 ;
V_270 = F_49 ( 1 , V_275 -> V_129 ) ;
if ( ! V_270 )
goto V_280;
F_75 ( V_270 -> V_17 -> V_82 , V_275 ) ;
V_270 -> V_179 = V_278 ;
V_270 -> V_58 = V_65 ;
V_270 -> V_17 -> V_87 = V_89 ;
V_270 -> V_17 -> V_130 = V_275 -> V_129 ;
memcpy ( F_7 ( V_270 , V_270 -> V_17 ) , V_275 -> V_90 ,
V_275 -> V_129 ) ;
}
F_138 () ;
V_98 = F_58 ( V_2 -> V_5 . V_7 ) ;
V_267 = V_2 -> V_5 . V_6 ;
for ( V_3 = V_265 ; V_3 < V_267 ; V_3 ++ )
F_56 ( V_2 , V_3 , NULL , NULL ) ;
V_268 = V_266 ;
if ( V_267 < V_265 )
V_268 = V_267 * sizeof( struct V_1 * ) ;
memcpy ( V_219 , V_98 , V_268 ) ;
if ( ( V_267 <= V_279 ) &&
( V_265 > V_279 ) ) {
F_75 ( V_219 [ V_279 ] , V_270 ) ;
V_270 = NULL ;
}
if ( ( V_267 <= V_274 ) &&
( V_265 > V_274 ) ) {
F_75 ( V_219 [ V_274 ] , V_269 ) ;
V_269 = NULL ;
}
V_2 -> V_5 . V_6 = V_265 ;
F_59 ( V_2 -> V_5 . V_7 , V_219 ) ;
F_139 () ;
F_52 ( V_270 ) ;
F_52 ( V_269 ) ;
if ( V_98 ) {
F_140 () ;
F_141 ( V_98 ) ;
}
return 0 ;
V_280:
F_52 ( V_269 ) ;
V_277:
F_141 ( V_219 ) ;
V_273:
return - V_137 ;
}
static int F_142 ( struct V_185 * V_186 , int V_281 ,
void T_5 * V_282 , T_4 * V_283 , T_6 * V_284 )
{
struct V_2 * V_2 = V_186 -> V_188 ;
int V_6 = V_2 -> V_5 . V_6 ;
int V_285 ;
struct V_185 V_286 = {
. V_287 = V_186 -> V_287 ,
. V_188 = & V_6 ,
. V_288 = sizeof( int ) ,
. V_289 = V_186 -> V_289 ,
. V_290 = & V_291 ,
. V_292 = & V_293 ,
} ;
V_285 = F_143 ( & V_286 , V_281 , V_282 , V_283 , V_284 ) ;
if ( V_281 && V_285 == 0 )
V_285 = F_136 ( V_2 , V_6 ) ;
return V_285 ;
}
static int F_144 ( struct V_2 * V_2 )
{
struct V_185 * V_186 ;
V_2 -> V_5 . V_6 = 0 ;
V_2 -> V_5 . V_7 = NULL ;
V_186 = F_95 ( V_294 , sizeof( V_294 ) , V_96 ) ;
if ( V_186 == NULL )
return - V_137 ;
V_186 [ 0 ] . V_188 = V_2 ;
V_2 -> V_5 . V_295 = F_97 ( V_2 , L_4 , V_186 ) ;
if ( V_2 -> V_5 . V_295 == NULL ) {
F_98 ( V_186 ) ;
return - V_137 ;
}
return 0 ;
}
static void F_145 ( struct V_2 * V_2 )
{
struct V_1 T_1 * * V_7 ;
T_4 V_6 ;
struct V_185 * V_186 ;
unsigned int V_3 ;
V_186 = V_2 -> V_5 . V_295 -> V_193 ;
F_100 ( V_2 -> V_5 . V_295 ) ;
F_98 ( V_186 ) ;
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
int V_76 ;
F_147 ( sizeof( struct V_23 ) != 4 ) ;
V_76 = F_148 ( & V_296 ) ;
if ( V_76 )
goto V_51;
V_76 = F_149 ( & V_297 ) ;
if ( V_76 )
goto V_298;
F_150 ( & V_299 ) ;
F_151 ( V_300 , V_106 , F_118 , NULL , NULL ) ;
F_151 ( V_300 , V_107 , F_117 , NULL , NULL ) ;
F_151 ( V_300 , V_301 , NULL , F_128 , NULL ) ;
V_76 = 0 ;
V_51:
return V_76 ;
V_298:
F_152 ( & V_296 ) ;
goto V_51;
}
static void T_8 F_153 ( void )
{
F_154 ( V_300 ) ;
F_155 ( & V_299 ) ;
F_156 ( & V_297 ) ;
F_152 ( & V_296 ) ;
}
