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
static struct V_14 * F_15 ( struct V_1 * V_4 ,
struct V_25 * V_26 , bool V_28 )
{
struct V_29 V_30 ;
struct V_23 * V_31 ;
bool V_32 = false ;
int V_33 ;
int V_20 = 0 ;
T_3 V_34 = 0 ;
if ( V_4 -> V_18 == 1 )
goto V_35;
for ( V_33 = 0 ; V_33 < V_36 && ! V_28 ;
V_33 ++ ) {
if ( ! F_16 ( V_26 , sizeof( * V_31 ) * V_33 ) )
break;
V_31 = F_17 ( V_26 ) + V_33 ;
V_30 = F_18 ( V_31 ) ;
if ( F_19 ( V_30 . V_37 >= V_38 ) ) {
V_34 = F_20 ( V_30 . V_37 , V_34 ) ;
if ( V_32 )
break;
} else if ( V_30 . V_37 == V_39 ) {
V_32 = true ;
}
V_28 = V_30 . V_28 ;
if ( V_28 && F_16 ( V_26 , sizeof( * V_31 ) * V_33 +
sizeof( struct V_40 ) ) ) {
const struct V_40 * V_41 ;
V_41 = ( const struct V_40 * ) ( F_17 ( V_26 ) +
V_33 ) ;
if ( V_41 -> V_42 == 4 ) {
V_34 = F_21 ( F_22 ( V_41 -> V_43 ) ,
F_22 ( V_41 -> V_44 ) ,
V_41 -> V_45 , V_34 ) ;
} else if ( V_41 -> V_42 == 6 &&
F_16 ( V_26 , sizeof( * V_31 ) * V_33 +
sizeof( struct V_46 ) ) ) {
const struct V_46 * V_47 ;
V_47 = ( const struct V_46 * ) ( F_17 ( V_26 ) +
V_33 ) ;
V_34 = F_23 ( & V_47 -> V_43 , V_34 ) ;
V_34 = F_23 ( & V_47 -> V_44 , V_34 ) ;
V_34 = F_20 ( V_47 -> V_48 , V_34 ) ;
}
}
}
V_20 = V_34 % V_4 -> V_18 ;
V_35:
return & V_4 -> V_17 [ V_20 ] ;
}
static bool F_24 ( struct V_1 * V_4 , struct V_25 * V_26 ,
struct V_29 V_30 )
{
enum V_49 V_50 ;
bool V_51 = false ;
if ( ! F_16 ( V_26 , 12 ) )
return false ;
V_50 = V_4 -> V_52 ;
if ( V_50 == V_53 )
V_50 = F_25 ( V_26 ) -> V_42 ;
switch ( V_50 ) {
case V_54 : {
struct V_40 * V_55 = F_25 ( V_26 ) ;
V_26 -> V_45 = F_26 ( V_56 ) ;
F_27 ( & V_55 -> V_57 ,
F_26 ( V_55 -> V_58 << 8 ) ,
F_26 ( V_30 . V_58 << 8 ) ) ;
V_55 -> V_58 = V_30 . V_58 ;
V_51 = true ;
break;
}
case V_59 : {
struct V_46 * V_60 = F_28 ( V_26 ) ;
V_26 -> V_45 = F_26 ( V_61 ) ;
V_60 -> V_62 = V_30 . V_58 ;
V_51 = true ;
break;
}
case V_53 :
break;
}
return V_51 ;
}
static int F_29 ( struct V_25 * V_26 , struct V_9 * V_10 ,
struct V_63 * V_64 , struct V_9 * V_65 )
{
struct V_2 * V_2 = F_30 ( V_10 ) ;
struct V_23 * V_31 ;
struct V_1 * V_4 ;
struct V_14 * V_15 ;
struct V_29 V_30 ;
struct V_9 * V_66 ;
struct V_8 * V_67 ;
unsigned int V_68 ;
unsigned int V_69 ;
unsigned int V_24 ;
int V_70 ;
V_67 = F_3 ( V_10 ) ;
if ( ! V_67 || ! V_67 -> V_71 )
goto V_72;
if ( V_26 -> V_73 != V_74 )
goto V_72;
if ( ( V_26 = F_31 ( V_26 , V_75 ) ) == NULL )
goto V_72;
if ( ! F_16 ( V_26 , sizeof( * V_31 ) ) )
goto V_72;
V_31 = F_17 ( V_26 ) ;
V_30 = F_18 ( V_31 ) ;
F_32 ( V_26 , sizeof( * V_31 ) ) ;
F_33 ( V_26 ) ;
F_34 ( V_26 ) ;
V_4 = F_1 ( V_2 , V_30 . V_37 ) ;
if ( ! V_4 )
goto V_72;
V_15 = F_15 ( V_4 , V_26 , V_30 . V_28 ) ;
if ( ! V_15 )
goto V_72;
V_66 = F_2 ( V_15 -> V_76 ) ;
if ( ! F_5 ( V_66 ) )
goto V_72;
if ( F_35 ( V_26 ) )
goto V_72;
F_36 ( V_26 ) ;
if ( V_30 . V_58 <= 1 )
goto V_72;
V_30 . V_58 -= 1 ;
V_69 = F_10 ( V_15 ) ;
V_24 = F_11 ( V_66 ) ;
if ( F_12 ( V_26 , V_24 - V_69 ) )
goto V_72;
V_68 = F_37 ( V_66 ) ;
if ( ! V_66 -> V_77 )
V_68 = 0 ;
if ( F_38 ( V_26 , V_68 + V_69 ) )
goto V_72;
V_26 -> V_10 = V_66 ;
V_26 -> V_45 = F_26 ( V_78 ) ;
if ( F_39 ( ! V_69 && V_30 . V_28 ) ) {
if ( ! F_24 ( V_4 , V_26 , V_30 ) )
goto V_72;
} else {
bool V_28 ;
int V_79 ;
F_40 ( V_26 , V_69 ) ;
F_33 ( V_26 ) ;
V_31 = F_17 ( V_26 ) ;
V_28 = V_30 . V_28 ;
for ( V_79 = V_15 -> V_22 - 1 ; V_79 >= 0 ; V_79 -- ) {
V_31 [ V_79 ] = F_41 ( V_15 -> V_80 [ V_79 ] ,
V_30 . V_58 , 0 , V_28 ) ;
V_28 = false ;
}
}
if ( V_15 -> V_81 == V_82 )
V_70 = F_42 ( V_83 , V_66 ,
V_66 -> V_84 , V_26 ) ;
else
V_70 = F_42 ( V_15 -> V_81 , V_66 ,
F_9 ( V_4 , V_15 ) , V_26 ) ;
if ( V_70 )
F_43 ( L_1 ,
V_85 , V_70 ) ;
return 0 ;
V_72:
F_44 ( V_26 ) ;
return V_86 ;
}
static struct V_1 * F_45 ( int V_87 , T_2 V_88 )
{
T_2 V_89 = F_46 ( V_88 , V_19 ) ;
struct V_1 * V_4 ;
V_4 = F_47 ( F_46 ( sizeof( * V_4 ) + V_87 * sizeof( * V_4 -> V_17 ) ,
V_19 ) +
V_87 * V_89 ,
V_90 ) ;
if ( V_4 ) {
V_4 -> V_18 = V_87 ;
V_4 -> V_21 = V_89 ;
}
return V_4 ;
}
static void F_48 ( struct V_1 * V_4 )
{
if ( V_4 )
F_49 ( V_4 , V_91 ) ;
}
static void F_50 ( struct V_2 * V_2 , unsigned V_3 ,
struct V_1 * V_92 , struct V_1 * V_93 ,
const struct V_94 * V_95 )
{
struct V_96 * V_97 = V_95 ? V_95 -> V_97 : NULL ;
unsigned V_98 = V_95 ? V_95 -> V_98 : 0 ;
int V_99 = V_93 ? V_100 : V_101 ;
struct V_1 * V_4 = V_93 ? V_93 : V_92 ;
unsigned V_102 = ( V_92 && V_93 ) ? V_103 : 0 ;
if ( V_4 && ( V_3 >= V_38 ) )
F_51 ( V_99 , V_3 , V_4 , V_97 , V_2 , V_98 , V_102 ) ;
}
static void F_52 ( struct V_2 * V_2 , unsigned V_3 ,
struct V_1 * V_93 ,
const struct V_94 * V_95 )
{
struct V_1 T_1 * * V_7 ;
struct V_1 * V_4 ;
F_53 () ;
V_7 = F_54 ( V_2 -> V_5 . V_7 ) ;
V_4 = F_54 ( V_7 [ V_3 ] ) ;
F_55 ( V_7 [ V_3 ] , V_93 ) ;
F_50 ( V_2 , V_3 , V_4 , V_93 , V_95 ) ;
F_48 ( V_4 ) ;
}
static unsigned F_56 ( struct V_2 * V_2 )
{
struct V_1 T_1 * * V_7 ;
T_4 V_6 ;
unsigned V_3 ;
V_7 = F_54 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for ( V_3 = V_38 ; V_3 < V_6 ;
V_3 ++ ) {
if ( ! F_54 ( V_7 [ V_3 ] ) )
return V_3 ;
}
return V_104 ;
}
static struct V_9 * F_57 ( struct V_2 * V_2 ,
const void * V_105 )
{
struct V_9 * V_10 ;
struct V_106 * V_4 ;
struct V_107 V_44 ;
memcpy ( & V_44 , V_105 , sizeof( struct V_107 ) ) ;
V_4 = F_58 ( V_2 , V_44 . V_108 , 0 , 0 , 0 ) ;
if ( F_59 ( V_4 ) )
return F_60 ( V_4 ) ;
V_10 = V_4 -> V_109 . V_10 ;
F_61 ( V_10 ) ;
F_62 ( V_4 ) ;
return V_10 ;
}
static struct V_9 * F_57 ( struct V_2 * V_2 ,
const void * V_105 )
{
return F_63 ( - V_110 ) ;
}
static struct V_9 * F_64 ( struct V_2 * V_2 ,
const void * V_105 )
{
struct V_9 * V_10 ;
struct V_111 * V_109 ;
struct V_112 V_113 ;
int V_70 ;
if ( ! V_114 )
return F_63 ( - V_110 ) ;
memset ( & V_113 , 0 , sizeof( V_113 ) ) ;
memcpy ( & V_113 . V_44 , V_105 , sizeof( struct V_115 ) ) ;
V_70 = V_114 -> V_116 ( V_2 , NULL , & V_109 , & V_113 ) ;
if ( V_70 )
return F_63 ( V_70 ) ;
V_10 = V_109 -> V_10 ;
F_61 ( V_10 ) ;
F_65 ( V_109 ) ;
return V_10 ;
}
static struct V_9 * F_64 ( struct V_2 * V_2 ,
const void * V_105 )
{
return F_63 ( - V_110 ) ;
}
static struct V_9 * F_66 ( struct V_2 * V_2 ,
struct V_1 * V_4 ,
struct V_14 * V_15 , int V_117 )
{
struct V_9 * V_10 = NULL ;
if ( ! V_117 ) {
switch ( V_15 -> V_81 ) {
case V_118 :
V_10 = F_57 ( V_2 , F_9 ( V_4 , V_15 ) ) ;
break;
case V_119 :
V_10 = F_64 ( V_2 , F_9 ( V_4 , V_15 ) ) ;
break;
case V_83 :
break;
}
} else {
V_10 = F_67 ( V_2 , V_117 ) ;
}
if ( ! V_10 )
return F_63 ( - V_120 ) ;
F_68 ( V_10 ) ;
return V_10 ;
}
static int F_69 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_14 * V_15 , int V_117 )
{
struct V_9 * V_10 = NULL ;
int V_70 = - V_120 ;
V_10 = F_66 ( V_2 , V_4 , V_15 , V_117 ) ;
if ( F_59 ( V_10 ) ) {
V_70 = F_70 ( V_10 ) ;
V_10 = NULL ;
goto V_121;
}
V_70 = - V_122 ;
if ( ! F_3 ( V_10 ) )
goto V_121;
if ( ( V_15 -> V_81 == V_83 ) &&
( V_10 -> V_123 != V_15 -> V_124 ) )
goto V_121;
F_71 ( V_15 -> V_76 , V_10 ) ;
return 0 ;
V_121:
return V_70 ;
}
static int F_72 ( struct V_125 * V_126 ,
struct V_1 * V_4 )
{
struct V_2 * V_2 = V_126 -> V_127 . V_128 ;
struct V_14 * V_15 = V_4 -> V_17 ;
int V_70 ;
int V_79 ;
if ( ! V_15 )
return - V_129 ;
V_70 = - V_122 ;
if ( V_126 -> V_130 > V_131 )
goto V_121;
V_15 -> V_22 = V_126 -> V_130 ;
for ( V_79 = 0 ; V_79 < V_15 -> V_22 ; V_79 ++ )
V_15 -> V_80 [ V_79 ] = V_126 -> V_132 [ V_79 ] ;
V_15 -> V_81 = V_126 -> V_133 ;
memcpy ( F_7 ( V_4 , V_15 ) , V_126 -> V_134 , V_126 -> V_135 ) ;
V_15 -> V_124 = V_126 -> V_135 ;
V_70 = F_69 ( V_2 , V_4 , V_15 , V_126 -> V_136 ) ;
if ( V_70 )
goto V_121;
return 0 ;
V_121:
return V_70 ;
}
static int F_73 ( struct V_2 * V_2 , struct V_1 * V_4 ,
struct V_14 * V_15 , int V_117 ,
struct V_137 * V_138 , struct V_137 * V_139 )
{
int V_70 = - V_129 ;
if ( ! V_15 )
goto V_121;
if ( V_139 ) {
V_70 = F_74 ( V_139 , V_131 ,
& V_15 -> V_22 , V_15 -> V_80 ) ;
if ( V_70 )
goto V_121;
}
if ( V_138 ) {
V_70 = F_75 ( V_138 , & V_15 -> V_124 , & V_15 -> V_81 ,
F_7 ( V_4 , V_15 ) ) ;
if ( V_70 )
goto V_121;
} else {
V_15 -> V_81 = V_82 ;
}
V_70 = F_69 ( V_2 , V_4 , V_15 , V_117 ) ;
if ( V_70 )
goto V_121;
return 0 ;
V_121:
return V_70 ;
}
static int F_76 ( struct V_140 * V_141 , int V_27 ,
T_2 V_142 , T_2 * V_143 )
{
int V_144 = 0 ;
int V_145 = V_27 ;
if ( ! V_141 ) {
* V_143 = V_142 ;
return 1 ;
}
* V_143 = 0 ;
while ( F_77 ( V_141 , V_145 ) ) {
struct V_137 * V_146 , * V_147 = F_78 ( V_141 ) ;
int V_148 ;
V_148 = F_79 ( V_141 ) ;
V_146 = F_80 ( V_147 , V_148 , V_149 ) ;
if ( V_146 && F_81 ( V_146 ) >=
F_82 ( struct V_150 , V_151 ) ) {
int V_152 = F_81 ( V_146 ) -
F_82 ( struct V_150 , V_151 ) ;
if ( V_152 <= V_153 )
* V_143 = F_83 ( V_154 , * V_143 ,
V_152 ) ;
}
V_144 ++ ;
V_141 = F_84 ( V_141 , & V_145 ) ;
}
return V_145 > 0 ? 0 : V_144 ;
}
static int F_85 ( struct V_125 * V_126 ,
struct V_1 * V_4 )
{
struct V_140 * V_141 = V_126 -> V_155 ;
struct V_137 * V_156 , * V_157 ;
int V_145 = V_126 -> V_158 ;
int V_144 = 0 ;
int V_70 = 0 ;
F_86 (rt) {
int V_148 ;
V_156 = NULL ;
V_157 = NULL ;
V_70 = - V_122 ;
if ( ! F_77 ( V_141 , V_145 ) )
goto V_121;
if ( V_141 -> V_159 || V_141 -> V_160 )
goto V_121;
V_148 = F_79 ( V_141 ) ;
if ( V_148 > 0 ) {
struct V_137 * V_147 = F_78 ( V_141 ) ;
V_156 = F_80 ( V_147 , V_148 , V_149 ) ;
V_157 = F_80 ( V_147 , V_148 , V_161 ) ;
}
V_70 = F_73 ( V_126 -> V_127 . V_128 , V_4 , V_15 ,
V_141 -> V_162 , V_156 ,
V_157 ) ;
if ( V_70 )
goto V_121;
V_141 = F_84 ( V_141 , & V_145 ) ;
V_144 ++ ;
} F_87 ( V_4 ) ;
V_4 -> V_18 = V_144 ;
return 0 ;
V_121:
return V_70 ;
}
static int F_88 ( struct V_125 * V_126 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = V_126 -> V_127 . V_128 ;
struct V_1 * V_4 , * V_92 ;
int V_70 = - V_122 ;
T_2 V_143 ;
unsigned V_3 ;
int V_144 ;
V_3 = V_126 -> V_163 ;
if ( ( V_3 == V_104 ) &&
( V_126 -> V_164 & V_165 ) ) {
V_3 = F_56 ( V_2 ) ;
}
if ( V_3 < V_38 )
goto V_121;
if ( V_3 >= V_2 -> V_5 . V_6 )
goto V_121;
V_70 = - V_166 ;
if ( V_126 -> V_164 & V_167 )
goto V_121;
V_70 = - V_168 ;
V_7 = F_54 ( V_2 -> V_5 . V_7 ) ;
V_92 = F_54 ( V_7 [ V_3 ] ) ;
if ( ( V_126 -> V_164 & V_169 ) && V_92 )
goto V_121;
V_70 = - V_168 ;
if ( ! ( V_126 -> V_164 & V_103 ) && V_92 )
goto V_121;
V_70 = - V_170 ;
if ( ! ( V_126 -> V_164 & V_165 ) && ! V_92 )
goto V_121;
V_70 = - V_122 ;
V_144 = F_76 ( V_126 -> V_155 , V_126 -> V_158 ,
V_126 -> V_135 , & V_143 ) ;
if ( V_144 == 0 )
goto V_121;
V_70 = - V_129 ;
V_4 = F_45 ( V_144 , V_143 ) ;
if ( ! V_4 )
goto V_121;
V_4 -> V_171 = V_126 -> V_172 ;
V_4 -> V_52 = V_126 -> V_173 ;
if ( V_126 -> V_155 )
V_70 = F_85 ( V_126 , V_4 ) ;
else
V_70 = F_72 ( V_126 , V_4 ) ;
if ( V_70 )
goto V_174;
F_52 ( V_2 , V_3 , V_4 , & V_126 -> V_127 ) ;
return 0 ;
V_174:
F_48 ( V_4 ) ;
V_121:
return V_70 ;
}
static int F_89 ( struct V_125 * V_126 )
{
struct V_2 * V_2 = V_126 -> V_127 . V_128 ;
unsigned V_3 ;
int V_70 = - V_122 ;
V_3 = V_126 -> V_163 ;
if ( V_3 < V_38 )
goto V_121;
if ( V_3 >= V_2 -> V_5 . V_6 )
goto V_121;
F_52 ( V_2 , V_3 , NULL , & V_126 -> V_127 ) ;
V_70 = 0 ;
V_121:
return V_70 ;
}
static int F_90 ( struct V_9 * V_10 ,
struct V_8 * V_67 )
{
char V_175 [ sizeof( L_2 ) + V_176 ] ;
struct V_177 * V_178 ;
int V_79 ;
V_178 = F_91 ( & V_179 , sizeof( V_179 ) , V_90 ) ;
if ( ! V_178 )
goto V_35;
for ( V_79 = 0 ; V_79 < F_92 ( V_179 ) ; V_79 ++ )
V_178 [ V_79 ] . V_180 = ( char * ) V_67 + ( V_181 ) V_178 [ V_79 ] . V_180 ;
snprintf ( V_175 , sizeof( V_175 ) , L_3 , V_10 -> V_182 ) ;
V_67 -> V_183 = F_93 ( F_30 ( V_10 ) , V_175 , V_178 ) ;
if ( ! V_67 -> V_183 )
goto free;
return 0 ;
free:
F_94 ( V_178 ) ;
V_35:
return - V_184 ;
}
static void F_95 ( struct V_8 * V_67 )
{
struct V_177 * V_178 ;
V_178 = V_67 -> V_183 -> V_185 ;
F_96 ( V_67 -> V_183 ) ;
F_94 ( V_178 ) ;
}
static struct V_8 * F_97 ( struct V_9 * V_10 )
{
struct V_8 * V_67 ;
int V_70 = - V_129 ;
F_53 () ;
V_67 = F_47 ( sizeof( * V_67 ) , V_90 ) ;
if ( ! V_67 )
return F_63 ( V_70 ) ;
V_70 = F_90 ( V_10 , V_67 ) ;
if ( V_70 )
goto free;
F_55 ( V_10 -> V_11 , V_67 ) ;
return V_67 ;
free:
F_94 ( V_67 ) ;
return F_63 ( V_70 ) ;
}
static void F_98 ( struct V_9 * V_10 )
{
struct V_1 T_1 * * V_7 ;
struct V_2 * V_2 = F_30 ( V_10 ) ;
struct V_8 * V_67 ;
unsigned V_3 ;
V_7 = F_54 ( V_2 -> V_5 . V_7 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 . V_6 ; V_3 ++ ) {
struct V_1 * V_4 = F_54 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
F_99 (rt) {
if ( F_54 ( V_15 -> V_76 ) != V_10 )
continue;
V_15 -> V_76 = NULL ;
} F_87 ( V_4 ) ;
}
V_67 = F_3 ( V_10 ) ;
if ( ! V_67 )
return;
F_95 ( V_67 ) ;
F_71 ( V_10 -> V_11 , NULL ) ;
F_49 ( V_67 , V_186 ) ;
}
static int F_100 ( struct V_187 * V_188 , unsigned long V_99 ,
void * V_189 )
{
struct V_9 * V_10 = F_101 ( V_189 ) ;
struct V_8 * V_67 ;
switch( V_99 ) {
case V_190 :
if ( ( V_10 -> type == V_191 ) ||
( V_10 -> type == V_192 ) ) {
V_67 = F_97 ( V_10 ) ;
if ( F_59 ( V_67 ) )
return F_102 ( F_70 ( V_67 ) ) ;
}
break;
case V_193 :
F_98 ( V_10 ) ;
break;
case V_194 :
V_67 = F_3 ( V_10 ) ;
if ( V_67 ) {
int V_70 ;
F_95 ( V_67 ) ;
V_70 = F_90 ( V_10 , V_67 ) ;
if ( V_70 )
return F_102 ( V_70 ) ;
}
break;
}
return V_195 ;
}
static int F_103 ( struct V_25 * V_26 ,
T_2 V_178 , const void * V_105 , int V_196 )
{
static const int V_197 [ V_198 + 1 ] = {
V_199 , V_200 , V_201 , V_202 ,
} ;
struct V_137 * V_146 ;
struct V_150 * V_138 ;
int V_203 = V_204 ;
V_146 = F_104 ( V_26 , V_149 , V_196 + 2 ) ;
if ( ! V_146 )
return - V_205 ;
if ( V_178 <= V_198 )
V_203 = V_197 [ V_178 ] ;
V_138 = F_105 ( V_146 ) ;
V_138 -> V_206 = V_203 ;
memcpy ( V_138 -> V_151 , V_105 , V_196 ) ;
return 0 ;
}
int F_106 ( struct V_25 * V_26 , int V_207 ,
T_2 V_208 , const T_3 V_37 [] )
{
struct V_137 * V_146 ;
struct V_23 * V_209 ;
bool V_28 ;
int V_79 ;
V_146 = F_104 ( V_26 , V_207 , V_208 * 4 ) ;
if ( ! V_146 )
return - V_205 ;
V_209 = F_105 ( V_146 ) ;
V_28 = true ;
for ( V_79 = V_208 - 1 ; V_79 >= 0 ; V_79 -- ) {
V_209 [ V_79 ] = F_41 ( V_37 [ V_79 ] , 0 , 0 , V_28 ) ;
V_28 = false ;
}
return 0 ;
}
int F_74 ( const struct V_137 * V_146 ,
T_3 V_210 , T_2 * V_208 , T_3 V_37 [] )
{
unsigned V_27 = F_81 ( V_146 ) ;
unsigned V_211 ;
struct V_23 * V_209 ;
bool V_28 ;
int V_79 ;
if ( V_27 & 3 )
return - V_122 ;
V_211 = V_27 / 4 ;
if ( V_211 > V_210 )
return - V_122 ;
V_209 = F_105 ( V_146 ) ;
V_28 = true ;
for ( V_79 = V_211 - 1 ; V_79 >= 0 ; V_79 -- , V_28 = false ) {
struct V_29 V_30 ;
V_30 = F_18 ( V_209 + V_79 ) ;
if ( ( V_30 . V_28 != V_28 ) || V_30 . V_58 || V_30 . V_212 )
return - V_122 ;
switch ( V_30 . V_37 ) {
case V_213 :
return - V_122 ;
}
V_37 [ V_79 ] = V_30 . V_37 ;
}
* V_208 = V_211 ;
return 0 ;
}
int F_75 ( const struct V_137 * V_146 , T_2 * V_152 ,
T_2 * V_214 , T_2 V_215 [] )
{
struct V_150 * V_138 = F_105 ( V_146 ) ;
int V_70 = - V_122 ;
int V_196 ;
if ( F_81 ( V_146 ) < F_82 ( struct V_150 , V_151 ) )
goto V_121;
V_196 = F_81 ( V_146 ) -
F_82 ( struct V_150 , V_151 ) ;
if ( V_196 > V_153 )
goto V_121;
switch ( V_138 -> V_206 ) {
case V_202 :
* V_214 = V_83 ;
break;
case V_199 :
* V_214 = V_118 ;
if ( V_196 != 4 )
goto V_121;
break;
case V_200 :
* V_214 = V_119 ;
if ( V_196 != 16 )
goto V_121;
break;
default:
goto V_121;
}
memcpy ( V_215 , V_138 -> V_151 , V_196 ) ;
* V_152 = V_196 ;
V_70 = 0 ;
V_121:
return V_70 ;
}
static int F_107 ( struct V_25 * V_26 , struct V_96 * V_97 ,
struct V_125 * V_126 )
{
struct V_216 * V_217 ;
struct V_137 * V_218 [ V_219 + 1 ] ;
int V_3 ;
int V_70 ;
V_70 = F_108 ( V_97 , sizeof( * V_217 ) , V_218 , V_219 , V_220 ) ;
if ( V_70 < 0 )
goto V_121;
V_70 = - V_122 ;
V_217 = F_109 ( V_97 ) ;
memset ( V_126 , 0 , sizeof( * V_126 ) ) ;
if ( V_217 -> V_221 != V_222 )
goto V_121;
if ( V_217 -> V_223 != 20 )
goto V_121;
if ( V_217 -> V_224 != 0 )
goto V_121;
if ( V_217 -> V_225 != 0 )
goto V_121;
if ( V_217 -> V_226 != V_227 )
goto V_121;
if ( V_217 -> V_228 != V_229 )
goto V_121;
if ( V_217 -> V_230 != V_231 )
goto V_121;
if ( V_217 -> V_232 != 0 )
goto V_121;
V_126 -> V_163 = V_104 ;
V_126 -> V_172 = V_217 -> V_233 ;
V_126 -> V_133 = V_82 ;
V_126 -> V_164 = V_97 -> V_234 ;
V_126 -> V_127 . V_98 = F_110 ( V_26 ) . V_98 ;
V_126 -> V_127 . V_97 = V_97 ;
V_126 -> V_127 . V_128 = F_111 ( V_26 -> V_235 ) ;
for ( V_3 = 0 ; V_3 <= V_219 ; V_3 ++ ) {
struct V_137 * V_146 = V_218 [ V_3 ] ;
if ( ! V_146 )
continue;
switch( V_3 ) {
case V_236 :
V_126 -> V_136 = F_112 ( V_146 ) ;
break;
case V_161 :
if ( F_74 ( V_146 , V_131 ,
& V_126 -> V_130 ,
V_126 -> V_132 ) )
goto V_121;
break;
case V_237 :
{
T_2 V_238 ;
if ( F_74 ( V_146 , 1 , & V_238 ,
& V_126 -> V_163 ) )
goto V_121;
if ( V_126 -> V_163 < V_38 )
goto V_121;
break;
}
case V_149 :
{
if ( F_75 ( V_146 , & V_126 -> V_135 ,
& V_126 -> V_133 , V_126 -> V_134 ) )
goto V_121;
break;
}
case V_239 :
{
V_126 -> V_155 = F_105 ( V_146 ) ;
V_126 -> V_158 = F_81 ( V_146 ) ;
break;
}
default:
goto V_121;
}
}
V_70 = 0 ;
V_121:
return V_70 ;
}
static int F_113 ( struct V_25 * V_26 , struct V_96 * V_97 )
{
struct V_125 V_126 ;
int V_70 ;
V_70 = F_107 ( V_26 , V_97 , & V_126 ) ;
if ( V_70 < 0 )
return V_70 ;
return F_89 ( & V_126 ) ;
}
static int F_114 ( struct V_25 * V_26 , struct V_96 * V_97 )
{
struct V_125 V_126 ;
int V_70 ;
V_70 = F_107 ( V_26 , V_97 , & V_126 ) ;
if ( V_70 < 0 )
return V_70 ;
return F_88 ( & V_126 ) ;
}
static int F_115 ( struct V_25 * V_26 , T_3 V_98 , T_3 V_240 , int V_99 ,
T_3 V_37 , struct V_1 * V_4 , int V_12 )
{
struct V_9 * V_10 ;
struct V_96 * V_97 ;
struct V_216 * V_217 ;
V_97 = F_116 ( V_26 , V_98 , V_240 , V_99 , sizeof( * V_217 ) , V_12 ) ;
if ( V_97 == NULL )
return - V_205 ;
V_217 = F_109 ( V_97 ) ;
V_217 -> V_221 = V_222 ;
V_217 -> V_223 = 20 ;
V_217 -> V_224 = 0 ;
V_217 -> V_225 = 0 ;
V_217 -> V_226 = V_227 ;
V_217 -> V_233 = V_4 -> V_171 ;
V_217 -> V_228 = V_229 ;
V_217 -> V_230 = V_231 ;
V_217 -> V_232 = 0 ;
if ( F_106 ( V_26 , V_237 , 1 , & V_37 ) )
goto V_241;
if ( V_4 -> V_18 == 1 ) {
const struct V_14 * V_15 = V_4 -> V_17 ;
if ( V_15 -> V_22 &&
F_106 ( V_26 , V_161 , V_15 -> V_22 ,
V_15 -> V_80 ) )
goto V_241;
if ( V_15 -> V_81 != V_82 &&
F_103 ( V_26 , V_15 -> V_81 , F_9 ( V_4 , V_15 ) ,
V_15 -> V_124 ) )
goto V_241;
V_10 = F_54 ( V_15 -> V_76 ) ;
if ( V_10 && F_117 ( V_26 , V_236 , V_10 -> V_242 ) )
goto V_241;
} else {
struct V_140 * V_141 ;
struct V_137 * V_243 ;
V_243 = F_118 ( V_26 , V_239 ) ;
if ( ! V_243 )
goto V_241;
F_99 (rt) {
V_141 = F_119 ( V_26 , sizeof( * V_141 ) ) ;
if ( ! V_141 )
goto V_241;
V_10 = F_54 ( V_15 -> V_76 ) ;
if ( V_10 )
V_141 -> V_162 = V_10 -> V_242 ;
if ( V_15 -> V_22 && F_106 ( V_26 , V_161 ,
V_15 -> V_22 ,
V_15 -> V_80 ) )
goto V_241;
if ( V_15 -> V_81 != V_82 &&
F_103 ( V_26 , V_15 -> V_81 ,
F_9 ( V_4 , V_15 ) ,
V_15 -> V_124 ) )
goto V_241;
V_141 -> V_244 = F_120 ( V_26 ) - ( void * ) V_141 ;
} F_87 ( V_4 ) ;
F_121 ( V_26 , V_243 ) ;
}
F_122 ( V_26 , V_97 ) ;
return 0 ;
V_241:
F_123 ( V_26 , V_97 ) ;
return - V_205 ;
}
static int F_124 ( struct V_25 * V_26 , struct V_245 * V_246 )
{
struct V_2 * V_2 = F_111 ( V_26 -> V_235 ) ;
struct V_1 T_1 * * V_7 ;
T_4 V_6 ;
unsigned int V_3 ;
F_53 () ;
V_3 = V_246 -> args [ 0 ] ;
if ( V_3 < V_38 )
V_3 = V_38 ;
V_7 = F_54 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for (; V_3 < V_6 ; V_3 ++ ) {
struct V_1 * V_4 ;
V_4 = F_54 ( V_7 [ V_3 ] ) ;
if ( ! V_4 )
continue;
if ( F_115 ( V_26 , F_110 ( V_246 -> V_26 ) . V_98 ,
V_246 -> V_97 -> V_247 , V_100 ,
V_3 , V_4 , V_248 ) < 0 )
break;
}
V_246 -> args [ 0 ] = V_3 ;
return V_26 -> V_27 ;
}
static inline T_4 F_125 ( struct V_1 * V_4 )
{
T_4 V_249 =
F_126 ( sizeof( struct V_216 ) )
+ F_127 ( 4 ) ;
if ( V_4 -> V_18 == 1 ) {
struct V_14 * V_15 = V_4 -> V_17 ;
if ( V_15 -> V_76 )
V_249 += F_127 ( 4 ) ;
if ( V_15 -> V_81 != V_82 )
V_249 += F_127 ( 2 + V_15 -> V_124 ) ;
if ( V_15 -> V_22 )
V_249 += F_127 ( V_15 -> V_22 * 4 ) ;
} else {
T_4 V_250 = 0 ;
F_99 (rt) {
V_250 += F_127 ( sizeof( struct V_140 ) ) ;
if ( V_15 -> V_81 != V_82 )
V_250 += F_127 ( 2 + V_15 -> V_124 ) ;
if ( V_15 -> V_22 )
V_250 += F_127 ( V_15 -> V_22 * 4 ) ;
} F_87 ( V_4 ) ;
V_249 += F_127 ( V_250 ) ;
}
return V_249 ;
}
static void F_51 ( int V_99 , T_3 V_37 , struct V_1 * V_4 ,
struct V_96 * V_97 , struct V_2 * V_2 , T_3 V_98 ,
unsigned int V_102 )
{
struct V_25 * V_26 ;
T_3 V_240 = V_97 ? V_97 -> V_247 : 0 ;
int V_70 = - V_184 ;
V_26 = F_128 ( F_125 ( V_4 ) , V_90 ) ;
if ( V_26 == NULL )
goto V_121;
V_70 = F_115 ( V_26 , V_98 , V_240 , V_99 , V_37 , V_4 , V_102 ) ;
if ( V_70 < 0 ) {
F_129 ( V_70 == - V_205 ) ;
F_44 ( V_26 ) ;
goto V_121;
}
F_130 ( V_26 , V_2 , V_98 , V_251 , V_97 , V_90 ) ;
return;
V_121:
if ( V_70 < 0 )
F_131 ( V_2 , V_251 , V_70 ) ;
}
static int F_132 ( struct V_2 * V_2 , T_4 V_252 )
{
T_4 V_253 = sizeof( struct V_1 * ) * V_252 ;
T_4 V_254 ;
T_4 V_255 ;
struct V_1 T_1 * * V_208 = NULL , * * V_92 ;
struct V_1 * V_256 = NULL , * V_257 = NULL ;
unsigned V_3 ;
if ( V_253 ) {
V_208 = F_47 ( V_253 , V_90 | V_258 | V_259 ) ;
if ( ! V_208 )
V_208 = F_133 ( V_253 ) ;
if ( ! V_208 )
goto V_260;
}
if ( V_252 > V_261 ) {
struct V_9 * V_262 = V_2 -> V_263 ;
V_256 = F_45 ( 1 , V_262 -> V_123 ) ;
if ( ! V_256 )
goto V_264;
F_71 ( V_256 -> V_17 -> V_76 , V_262 ) ;
V_256 -> V_171 = V_265 ;
V_256 -> V_52 = V_54 ;
V_256 -> V_17 -> V_81 = V_83 ;
V_256 -> V_17 -> V_124 = V_262 -> V_123 ;
memcpy ( F_7 ( V_256 , V_256 -> V_17 ) , V_262 -> V_84 ,
V_262 -> V_123 ) ;
}
if ( V_252 > V_266 ) {
struct V_9 * V_262 = V_2 -> V_263 ;
V_257 = F_45 ( 1 , V_262 -> V_123 ) ;
if ( ! V_257 )
goto V_267;
F_71 ( V_257 -> V_17 -> V_76 , V_262 ) ;
V_257 -> V_171 = V_265 ;
V_257 -> V_52 = V_59 ;
V_257 -> V_17 -> V_81 = V_83 ;
V_257 -> V_17 -> V_124 = V_262 -> V_123 ;
memcpy ( F_7 ( V_257 , V_257 -> V_17 ) , V_262 -> V_84 ,
V_262 -> V_123 ) ;
}
F_134 () ;
V_92 = F_54 ( V_2 -> V_5 . V_7 ) ;
V_254 = V_2 -> V_5 . V_6 ;
for ( V_3 = V_252 ; V_3 < V_254 ; V_3 ++ )
F_52 ( V_2 , V_3 , NULL , NULL ) ;
V_255 = V_253 ;
if ( V_254 < V_252 )
V_255 = V_254 * sizeof( struct V_1 * ) ;
memcpy ( V_208 , V_92 , V_255 ) ;
if ( ( V_254 <= V_266 ) &&
( V_252 > V_266 ) ) {
F_71 ( V_208 [ V_266 ] , V_257 ) ;
V_257 = NULL ;
}
if ( ( V_254 <= V_261 ) &&
( V_252 > V_261 ) ) {
F_71 ( V_208 [ V_261 ] , V_256 ) ;
V_256 = NULL ;
}
V_2 -> V_5 . V_6 = V_252 ;
F_55 ( V_2 -> V_5 . V_7 , V_208 ) ;
F_135 () ;
F_48 ( V_257 ) ;
F_48 ( V_256 ) ;
if ( V_92 ) {
F_136 () ;
F_137 ( V_92 ) ;
}
return 0 ;
V_267:
F_48 ( V_256 ) ;
V_264:
F_137 ( V_208 ) ;
V_260:
return - V_129 ;
}
static int F_138 ( struct V_177 * V_178 , int V_268 ,
void T_5 * V_269 , T_4 * V_270 , T_6 * V_271 )
{
struct V_2 * V_2 = V_178 -> V_180 ;
int V_6 = V_2 -> V_5 . V_6 ;
int V_272 ;
struct V_177 V_273 = {
. V_274 = V_178 -> V_274 ,
. V_180 = & V_6 ,
. V_275 = sizeof( int ) ,
. V_276 = V_178 -> V_276 ,
. V_277 = & V_278 ,
. V_279 = & V_280 ,
} ;
V_272 = F_139 ( & V_273 , V_268 , V_269 , V_270 , V_271 ) ;
if ( V_268 && V_272 == 0 )
V_272 = F_132 ( V_2 , V_6 ) ;
return V_272 ;
}
static int F_140 ( struct V_2 * V_2 )
{
struct V_177 * V_178 ;
V_2 -> V_5 . V_6 = 0 ;
V_2 -> V_5 . V_7 = NULL ;
V_178 = F_91 ( V_281 , sizeof( V_281 ) , V_90 ) ;
if ( V_178 == NULL )
return - V_129 ;
V_178 [ 0 ] . V_180 = V_2 ;
V_2 -> V_5 . V_282 = F_93 ( V_2 , L_4 , V_178 ) ;
if ( V_2 -> V_5 . V_282 == NULL ) {
F_94 ( V_178 ) ;
return - V_129 ;
}
return 0 ;
}
static void F_141 ( struct V_2 * V_2 )
{
struct V_1 T_1 * * V_7 ;
T_4 V_6 ;
struct V_177 * V_178 ;
unsigned int V_3 ;
V_178 = V_2 -> V_5 . V_282 -> V_185 ;
F_96 ( V_2 -> V_5 . V_282 ) ;
F_94 ( V_178 ) ;
F_134 () ;
V_7 = F_54 ( V_2 -> V_5 . V_7 ) ;
V_6 = V_2 -> V_5 . V_6 ;
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ ) {
struct V_1 * V_4 = F_54 ( V_7 [ V_3 ] ) ;
F_71 ( V_7 [ V_3 ] , NULL ) ;
F_48 ( V_4 ) ;
}
F_135 () ;
F_137 ( V_7 ) ;
}
static int T_7 F_142 ( void )
{
int V_70 ;
F_143 ( sizeof( struct V_23 ) != 4 ) ;
V_70 = F_144 ( & V_283 ) ;
if ( V_70 )
goto V_35;
V_70 = F_145 ( & V_284 ) ;
if ( V_70 )
goto V_285;
F_146 ( & V_286 ) ;
F_147 ( V_287 , V_100 , F_114 , NULL , NULL ) ;
F_147 ( V_287 , V_101 , F_113 , NULL , NULL ) ;
F_147 ( V_287 , V_288 , NULL , F_124 , NULL ) ;
V_70 = 0 ;
V_35:
return V_70 ;
V_285:
F_148 ( & V_283 ) ;
goto V_35;
}
static void T_8 F_149 ( void )
{
F_150 ( V_287 ) ;
F_151 ( & V_286 ) ;
F_152 ( & V_284 ) ;
F_148 ( & V_283 ) ;
}
