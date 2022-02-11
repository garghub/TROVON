const struct V_1 *
F_1 ( enum V_2 V_3 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; ++ V_4 ) {
if ( V_5 [ V_4 ] . V_3 == V_3 )
return & V_5 [ V_4 ] ;
}
return NULL ;
}
static bool F_3 ( enum V_2 V_6 ,
enum V_2 V_7 ,
unsigned int V_8 )
{
const struct V_1 * V_9 , * V_10 ;
if ( V_6 == V_7 )
return true ;
V_9 = F_1 ( V_6 ) ;
V_10 = F_1 ( V_7 ) ;
if ( ( V_9 -> V_11 == 0 ) || ( V_10 -> V_11 == 0 ) )
return false ;
if ( V_9 -> V_11 != V_10 -> V_11 )
return false ;
return V_9 -> V_12 - V_10 -> V_12 + V_8 <= 6 ;
}
static unsigned int F_4 ( const struct V_13 * V_14 ,
const struct V_15 * V_16 ,
struct V_17 * V_18 )
{
unsigned int V_19 = V_18 -> V_20 ;
unsigned int V_21 ;
unsigned int V_4 ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
V_18 -> V_22 = V_16 -> V_22 ;
V_18 -> V_23 = V_16 -> V_23 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; ++ V_4 ) {
if ( V_5 [ V_4 ] . V_3 == V_16 -> V_3 )
break;
}
if ( F_5 ( V_4 == F_2 ( V_5 ) ) )
return 0 ;
V_21 = V_18 -> V_22 * F_6 ( V_5 [ V_4 ] . V_12 , 8 ) / 8 ;
if ( V_14 -> V_24 )
V_19 = F_7 ( V_19 , V_21 , V_14 -> V_24 ) ;
else
V_19 = V_21 ;
if ( ! V_14 -> V_25 || V_19 != V_21 )
V_19 = F_6 ( V_19 , V_14 -> V_26 ) ;
V_18 -> V_27 = V_5 [ V_4 ] . V_27 ;
V_18 -> V_20 = V_19 ;
V_18 -> V_28 = V_18 -> V_20 * V_18 -> V_23 ;
V_18 -> V_29 = V_16 -> V_29 ;
V_18 -> V_30 = V_16 -> V_30 ;
return V_19 - V_21 ;
}
static void F_8 ( const struct V_17 * V_18 ,
struct V_15 * V_16 )
{
unsigned int V_4 ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_16 -> V_22 = V_18 -> V_22 ;
V_16 -> V_23 = V_18 -> V_23 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) - 1 ; ++ V_4 ) {
if ( V_5 [ V_4 ] . V_27 == V_18 -> V_27 )
break;
}
V_16 -> V_3 = V_5 [ V_4 ] . V_3 ;
V_16 -> V_29 = V_18 -> V_29 ;
V_16 -> V_30 = V_18 -> V_30 ;
}
static struct V_31 *
F_9 ( struct V_13 * V_14 , T_1 * V_32 )
{
struct V_33 * V_34 ;
V_34 = F_10 ( & V_14 -> V_32 ) ;
if ( V_34 == NULL ||
F_11 ( V_34 -> V_35 ) != V_36 )
return NULL ;
if ( V_32 )
* V_32 = V_34 -> V_37 ;
return F_12 ( V_34 -> V_35 ) ;
}
static struct V_13 *
F_13 ( struct V_13 * V_14 )
{
struct V_38 V_39 ;
struct V_40 * V_35 = & V_14 -> V_14 . V_35 ;
struct V_41 * V_42 = V_35 -> V_43 ;
struct V_13 * V_44 = NULL ;
F_14 ( & V_42 -> V_45 ) ;
F_15 ( & V_39 , V_35 ) ;
while ( ( V_35 = F_16 ( & V_39 ) ) ) {
if ( V_35 == & V_14 -> V_14 . V_35 )
continue;
if ( F_11 ( V_35 ) != V_46 )
continue;
V_44 = F_17 ( F_18 ( V_35 ) ) ;
if ( V_44 -> type != V_14 -> type )
break;
V_44 = NULL ;
}
F_19 ( & V_42 -> V_45 ) ;
return V_44 ;
}
static int F_20 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = V_48 -> V_51 -> V_50 ;
struct V_52 V_53 ;
struct V_52 V_54 ;
struct V_33 * V_32 ;
struct V_31 * V_55 ;
int V_56 ;
V_48 -> V_57 = V_48 -> V_58 ;
V_55 = F_9 ( V_48 -> V_51 , NULL ) ;
if ( V_55 == NULL )
return - V_59 ;
while ( 1 ) {
unsigned int V_60 ;
V_32 = & V_55 -> V_35 . V_61 [ 0 ] ;
if ( ! ( V_32 -> V_62 & V_63 ) )
break;
V_54 . V_32 = V_32 -> V_37 ;
V_54 . V_64 = V_65 ;
V_56 = F_21 ( V_55 , V_32 , V_66 , NULL , & V_54 ) ;
if ( V_56 < 0 && V_56 != - V_67 )
return - V_59 ;
if ( V_55 == & V_50 -> V_68 . V_55 )
F_22 ( & V_50 -> V_68 ,
& V_48 -> V_57 ) ;
if ( V_55 == & V_50 -> V_69 . V_55 && V_48 -> V_70 == NULL ) {
unsigned int V_71 = V_72 ;
F_23 ( & V_50 -> V_69 , & V_71 ) ;
if ( V_50 -> V_69 . V_73 . V_74 > V_71 )
return - V_75 ;
}
V_60 = V_55 == & V_50 -> V_69 . V_55 ;
V_32 = F_10 ( V_32 ) ;
if ( V_32 == NULL )
return - V_59 ;
if ( F_11 ( V_32 -> V_35 ) != V_36 )
break;
V_55 = F_12 ( V_32 -> V_35 ) ;
V_53 . V_32 = V_32 -> V_37 ;
V_53 . V_64 = V_65 ;
V_56 = F_21 ( V_55 , V_32 , V_66 , NULL , & V_53 ) ;
if ( V_56 < 0 && V_56 != - V_67 )
return - V_59 ;
if ( V_53 . V_76 . V_22 != V_54 . V_76 . V_22 ||
V_53 . V_76 . V_23 != V_54 . V_76 . V_23 )
return - V_59 ;
if ( V_60 ) {
unsigned int V_77 = 0 ;
if ( V_50 -> V_69 . V_70 == V_78 ) {
struct V_79 * V_80 =
& ( (struct V_81 * )
V_55 -> V_82 ) -> V_83 . V_84 ;
V_77 = V_80 -> V_85 * 2 ;
}
if ( ! F_3 ( V_53 . V_76 . V_3 ,
V_54 . V_76 . V_3 ,
V_77 ) )
return - V_59 ;
} else if ( V_53 . V_76 . V_3 != V_54 . V_76 . V_3 )
return - V_59 ;
}
return 0 ;
}
static int
F_24 ( struct V_13 * V_14 , struct V_86 * V_76 )
{
struct V_52 V_87 ;
struct V_31 * V_55 ;
T_1 V_32 ;
int V_56 ;
V_55 = F_9 ( V_14 , & V_32 ) ;
if ( V_55 == NULL )
return - V_88 ;
F_14 ( & V_14 -> V_89 ) ;
V_87 . V_32 = V_32 ;
V_87 . V_64 = V_65 ;
V_56 = F_21 ( V_55 , V_32 , V_66 , NULL , & V_87 ) ;
if ( V_56 == - V_67 )
V_56 = - V_88 ;
F_19 ( & V_14 -> V_89 ) ;
if ( V_56 )
return V_56 ;
V_76 -> type = V_14 -> type ;
return F_4 ( V_14 , & V_87 . V_76 , & V_76 -> V_87 . V_18 ) ;
}
static int
F_25 ( struct V_13 * V_14 , struct V_90 * V_91 )
{
struct V_86 V_76 ;
int V_56 ;
memcpy ( & V_76 , & V_91 -> V_76 , sizeof( V_76 ) ) ;
V_56 = F_24 ( V_14 , & V_76 ) ;
if ( V_56 < 0 )
return V_56 ;
if ( V_91 -> V_76 . V_87 . V_18 . V_27 != V_76 . V_87 . V_18 . V_27 ||
V_91 -> V_76 . V_87 . V_18 . V_23 != V_76 . V_87 . V_18 . V_23 ||
V_91 -> V_76 . V_87 . V_18 . V_22 != V_76 . V_87 . V_18 . V_22 ||
V_91 -> V_76 . V_87 . V_18 . V_20 != V_76 . V_87 . V_18 . V_20 ||
V_91 -> V_76 . V_87 . V_18 . V_28 != V_76 . V_87 . V_18 . V_28 )
return - V_88 ;
return V_56 ;
}
static T_2
F_26 ( struct V_49 * V_50 , const struct V_92 * V_93 , int V_94 )
{
struct V_95 * V_96 ;
T_1 V_97 ;
V_96 = F_27 ( sizeof( * V_96 ) , V_98 ) ;
if ( V_96 == NULL )
return - V_99 ;
V_96 -> V_100 = (struct V_92 * ) V_93 ;
V_96 -> V_101 = V_94 ;
V_96 -> V_102 = V_94 ;
V_97 = F_28 ( V_50 -> V_103 , V_50 -> V_104 , 0 , V_96 , V_105 ) ;
if ( F_29 ( V_97 ) )
F_30 ( V_96 ) ;
return V_97 ;
}
static void F_31 ( struct V_49 * V_50 , T_2 V_97 )
{
struct V_95 * V_96 ;
V_96 = F_32 ( V_50 -> V_103 , V_50 -> V_104 , ( T_1 ) V_97 ) ;
F_30 ( V_96 ) ;
}
static void F_33 ( struct V_106 * V_107 ,
unsigned int * V_108 , unsigned int * V_109 )
{
struct V_90 * V_91 =
F_34 ( V_107 , struct V_90 , V_107 ) ;
struct V_13 * V_14 = V_91 -> V_14 ;
* V_109 = V_91 -> V_76 . V_87 . V_18 . V_28 ;
if ( * V_109 == 0 )
return;
* V_108 = F_35 ( * V_108 , V_14 -> V_110 / F_36 ( * V_109 ) ) ;
}
static void F_37 ( struct V_111 * V_112 )
{
struct V_90 * V_91 = F_38 ( V_112 -> V_107 ) ;
struct V_113 * V_114 = F_39 ( V_112 ) ;
struct V_13 * V_14 = V_91 -> V_14 ;
if ( V_114 -> V_115 ) {
F_31 ( V_14 -> V_50 , V_114 -> V_115 ) ;
V_114 -> V_115 = 0 ;
}
}
static int F_40 ( struct V_111 * V_112 )
{
struct V_90 * V_91 = F_38 ( V_112 -> V_107 ) ;
struct V_113 * V_114 = F_39 ( V_112 ) ;
struct V_13 * V_14 = V_91 -> V_14 ;
unsigned long V_116 ;
V_116 = F_26 ( V_14 -> V_50 , V_112 -> V_93 , V_112 -> V_94 ) ;
if ( F_29 ( V_116 ) )
return - V_117 ;
if ( ! F_41 ( V_116 , 32 ) ) {
F_42 ( V_14 -> V_50 -> V_104 , L_1
L_2 ) ;
F_31 ( V_14 -> V_50 , V_114 -> V_115 ) ;
return - V_88 ;
}
V_112 -> V_118 . V_119 = V_91 -> V_76 . V_87 . V_18 . V_28 ;
V_114 -> V_115 = V_116 ;
return 0 ;
}
static void F_43 ( struct V_111 * V_112 )
{
struct V_90 * V_91 = F_38 ( V_112 -> V_107 ) ;
struct V_113 * V_114 = F_39 ( V_112 ) ;
struct V_13 * V_14 = V_91 -> V_14 ;
struct V_47 * V_48 = F_44 ( & V_14 -> V_14 . V_35 ) ;
enum V_120 V_121 ;
unsigned long V_62 ;
unsigned int V_122 ;
unsigned int V_123 ;
V_122 = F_45 ( & V_14 -> V_124 ) ;
F_46 ( & V_114 -> V_114 . V_125 , & V_14 -> V_124 ) ;
if ( V_122 ) {
if ( V_14 -> type == V_126 )
V_121 = V_127 ;
else
V_121 = V_128 ;
F_47 ( & V_48 -> V_129 , V_62 ) ;
V_48 -> V_121 |= V_121 ;
V_14 -> V_130 -> V_107 ( V_14 , V_114 ) ;
V_14 -> V_131 |= V_132 ;
V_123 = F_48 ( V_48 ) ;
if ( V_123 )
V_48 -> V_121 |= V_133 ;
F_49 ( & V_48 -> V_129 , V_62 ) ;
if ( V_123 )
F_50 ( V_48 ,
V_134 ) ;
}
}
struct V_113 * F_51 ( struct V_13 * V_14 )
{
struct V_47 * V_48 = F_44 ( & V_14 -> V_14 . V_35 ) ;
struct V_106 * V_107 = V_14 -> V_107 ;
enum V_120 V_121 ;
struct V_111 * V_112 ;
unsigned long V_62 ;
struct V_135 V_136 ;
F_47 ( & V_107 -> V_137 , V_62 ) ;
if ( F_5 ( F_45 ( & V_14 -> V_124 ) ) ) {
F_49 ( & V_107 -> V_137 , V_62 ) ;
return NULL ;
}
V_112 = F_52 ( & V_14 -> V_124 , struct V_111 ,
V_125 ) ;
F_53 ( & V_112 -> V_125 ) ;
F_49 ( & V_107 -> V_137 , V_62 ) ;
F_54 ( & V_136 ) ;
V_112 -> V_118 . V_138 . V_139 = V_136 . V_139 ;
V_112 -> V_118 . V_138 . V_140 = V_136 . V_141 / V_142 ;
if ( V_14 == V_48 -> V_51 && ! V_48 -> V_143 )
V_112 -> V_118 . V_144 = F_55 ( & V_48 -> V_145 ) ;
else
V_112 -> V_118 . V_144 = F_56 ( & V_48 -> V_145 ) ;
if ( V_107 -> type == V_126 && V_48 -> error ) {
V_112 -> V_121 = V_146 ;
V_48 -> error = false ;
} else {
V_112 -> V_121 = V_147 ;
}
F_57 ( & V_112 -> V_148 ) ;
if ( F_45 ( & V_14 -> V_124 ) ) {
if ( V_107 -> type == V_126 )
V_121 = V_127
| V_133 ;
else
V_121 = V_128
| V_133 ;
F_47 ( & V_48 -> V_129 , V_62 ) ;
V_48 -> V_121 &= ~ V_121 ;
if ( V_14 -> V_48 . V_149 == V_150 )
V_14 -> V_131 |= V_151 ;
F_49 ( & V_48 -> V_129 , V_62 ) ;
return NULL ;
}
if ( V_107 -> type == V_126 && V_48 -> V_70 != NULL ) {
F_47 ( & V_48 -> V_129 , V_62 ) ;
V_48 -> V_121 &= ~ V_133 ;
F_49 ( & V_48 -> V_129 , V_62 ) ;
}
V_112 = F_52 ( & V_14 -> V_124 , struct V_111 ,
V_125 ) ;
V_112 -> V_121 = V_152 ;
return F_39 ( V_112 ) ;
}
void F_58 ( struct V_13 * V_14 , int V_153 )
{
struct V_113 * V_112 = NULL ;
if ( V_153 && V_14 -> type == V_126 )
F_59 ( V_14 -> V_107 ) ;
if ( ! F_45 ( & V_14 -> V_124 ) ) {
V_112 = F_52 ( & V_14 -> V_124 ,
struct V_113 , V_114 . V_125 ) ;
V_14 -> V_130 -> V_107 ( V_14 , V_112 ) ;
V_14 -> V_131 |= V_132 ;
} else {
if ( V_153 )
V_14 -> V_131 |= V_151 ;
}
}
static int
F_60 ( struct V_154 * V_154 , void * V_155 , struct V_156 * V_157 )
{
struct V_13 * V_14 = F_61 ( V_154 ) ;
F_62 ( V_157 -> V_158 , V_159 , sizeof( V_157 -> V_158 ) ) ;
F_62 ( V_157 -> V_160 , V_14 -> V_14 . V_161 , sizeof( V_157 -> V_160 ) ) ;
F_62 ( V_157 -> V_162 , L_3 , sizeof( V_157 -> V_162 ) ) ;
if ( V_14 -> type == V_126 )
V_157 -> V_163 = V_164 | V_165 ;
else
V_157 -> V_163 = V_166 | V_165 ;
return 0 ;
}
static int
F_63 ( struct V_154 * V_154 , void * V_155 , struct V_86 * V_76 )
{
struct V_90 * V_91 = F_64 ( V_155 ) ;
struct V_13 * V_14 = F_61 ( V_154 ) ;
if ( V_76 -> type != V_14 -> type )
return - V_88 ;
F_14 ( & V_14 -> V_89 ) ;
* V_76 = V_91 -> V_76 ;
F_19 ( & V_14 -> V_89 ) ;
return 0 ;
}
static int
F_65 ( struct V_154 * V_154 , void * V_155 , struct V_86 * V_76 )
{
struct V_90 * V_91 = F_64 ( V_155 ) ;
struct V_13 * V_14 = F_61 ( V_154 ) ;
struct V_15 V_87 ;
if ( V_76 -> type != V_14 -> type )
return - V_88 ;
F_14 ( & V_14 -> V_89 ) ;
F_8 ( & V_76 -> V_87 . V_18 , & V_87 ) ;
F_4 ( V_14 , & V_87 , & V_76 -> V_87 . V_18 ) ;
V_91 -> V_76 = * V_76 ;
F_19 ( & V_14 -> V_89 ) ;
return 0 ;
}
static int
F_66 ( struct V_154 * V_154 , void * V_155 , struct V_86 * V_76 )
{
struct V_13 * V_14 = F_61 ( V_154 ) ;
struct V_52 V_87 ;
struct V_31 * V_55 ;
T_1 V_32 ;
int V_56 ;
if ( V_76 -> type != V_14 -> type )
return - V_88 ;
V_55 = F_9 ( V_14 , & V_32 ) ;
if ( V_55 == NULL )
return - V_88 ;
F_8 ( & V_76 -> V_87 . V_18 , & V_87 . V_76 ) ;
V_87 . V_32 = V_32 ;
V_87 . V_64 = V_65 ;
V_56 = F_21 ( V_55 , V_32 , V_66 , NULL , & V_87 ) ;
if ( V_56 )
return V_56 == - V_67 ? - V_88 : V_56 ;
F_4 ( V_14 , & V_87 . V_76 , & V_76 -> V_87 . V_18 ) ;
return 0 ;
}
static int
F_67 ( struct V_154 * V_154 , void * V_155 , struct V_167 * V_168 )
{
struct V_13 * V_14 = F_61 ( V_154 ) ;
struct V_31 * V_55 ;
int V_56 ;
V_55 = F_9 ( V_14 , NULL ) ;
if ( V_55 == NULL )
return - V_88 ;
F_14 ( & V_14 -> V_89 ) ;
V_56 = F_21 ( V_55 , V_14 , V_168 , V_168 ) ;
F_19 ( & V_14 -> V_89 ) ;
return V_56 == - V_67 ? - V_88 : V_56 ;
}
static int
F_68 ( struct V_154 * V_154 , void * V_155 , struct V_169 * V_170 )
{
struct V_13 * V_14 = F_61 ( V_154 ) ;
struct V_52 V_76 ;
struct V_31 * V_55 ;
T_1 V_32 ;
int V_56 ;
V_55 = F_9 ( V_14 , & V_32 ) ;
if ( V_55 == NULL )
return - V_88 ;
V_56 = F_21 ( V_55 , V_14 , V_171 , V_170 ) ;
if ( V_56 != - V_67 )
return V_56 ;
V_76 . V_32 = V_32 ;
V_76 . V_64 = V_65 ;
V_56 = F_21 ( V_55 , V_32 , V_66 , NULL , & V_76 ) ;
if ( V_56 < 0 )
return V_56 == - V_67 ? - V_88 : V_56 ;
V_170 -> V_172 . V_173 = 0 ;
V_170 -> V_172 . V_174 = 0 ;
V_170 -> V_172 . V_22 = V_76 . V_76 . V_22 ;
V_170 -> V_172 . V_23 = V_76 . V_76 . V_23 ;
return 0 ;
}
static int
F_69 ( struct V_154 * V_154 , void * V_155 , struct V_169 * V_170 )
{
struct V_13 * V_14 = F_61 ( V_154 ) ;
struct V_31 * V_55 ;
int V_56 ;
V_55 = F_9 ( V_14 , NULL ) ;
if ( V_55 == NULL )
return - V_88 ;
F_14 ( & V_14 -> V_89 ) ;
V_56 = F_21 ( V_55 , V_14 , V_175 , V_170 ) ;
F_19 ( & V_14 -> V_89 ) ;
return V_56 == - V_67 ? - V_88 : V_56 ;
}
static int
F_70 ( struct V_154 * V_154 , void * V_155 , struct V_176 * V_177 )
{
struct V_90 * V_91 = F_64 ( V_155 ) ;
struct V_13 * V_14 = F_61 ( V_154 ) ;
if ( V_14 -> type != V_178 ||
V_14 -> type != V_177 -> type )
return - V_88 ;
memset ( V_177 , 0 , sizeof( * V_177 ) ) ;
V_177 -> type = V_178 ;
V_177 -> V_179 . V_51 . V_180 = V_181 ;
V_177 -> V_179 . V_51 . V_182 = V_91 -> V_182 ;
return 0 ;
}
static int
F_71 ( struct V_154 * V_154 , void * V_155 , struct V_176 * V_177 )
{
struct V_90 * V_91 = F_64 ( V_155 ) ;
struct V_13 * V_14 = F_61 ( V_154 ) ;
if ( V_14 -> type != V_178 ||
V_14 -> type != V_177 -> type )
return - V_88 ;
if ( V_177 -> V_179 . V_51 . V_182 . V_183 == 0 )
V_177 -> V_179 . V_51 . V_182 . V_183 = 1 ;
V_91 -> V_182 = V_177 -> V_179 . V_51 . V_182 ;
return 0 ;
}
static int
F_72 ( struct V_154 * V_154 , void * V_155 , struct V_184 * V_185 )
{
struct V_90 * V_91 = F_64 ( V_155 ) ;
return F_73 ( & V_91 -> V_107 , V_185 ) ;
}
static int
F_74 ( struct V_154 * V_154 , void * V_155 , struct V_186 * V_187 )
{
struct V_90 * V_91 = F_64 ( V_155 ) ;
return F_75 ( & V_91 -> V_107 , V_187 ) ;
}
static int
F_76 ( struct V_154 * V_154 , void * V_155 , struct V_186 * V_187 )
{
struct V_90 * V_91 = F_64 ( V_155 ) ;
return F_77 ( & V_91 -> V_107 , V_187 ) ;
}
static int
F_78 ( struct V_154 * V_154 , void * V_155 , struct V_186 * V_187 )
{
struct V_90 * V_91 = F_64 ( V_155 ) ;
return F_79 ( & V_91 -> V_107 , V_187 ,
V_154 -> V_188 & V_189 ) ;
}
static int
F_80 ( struct V_154 * V_154 , void * V_155 , enum V_190 type )
{
struct V_90 * V_91 = F_64 ( V_155 ) ;
struct V_13 * V_14 = F_61 ( V_154 ) ;
enum V_120 V_121 ;
struct V_47 * V_48 ;
struct V_13 * V_44 ;
unsigned long V_62 ;
int V_56 ;
if ( type != V_14 -> type )
return - V_88 ;
F_14 ( & V_14 -> V_191 ) ;
if ( V_14 -> V_192 ) {
F_19 ( & V_14 -> V_191 ) ;
return - V_193 ;
}
V_48 = V_14 -> V_14 . V_35 . V_48
? F_44 ( & V_14 -> V_14 . V_35 ) : & V_14 -> V_48 ;
F_81 ( & V_14 -> V_14 . V_35 , & V_48 -> V_48 ) ;
V_56 = F_25 ( V_14 , V_91 ) ;
if ( V_56 < 0 )
goto error;
V_14 -> V_194 = V_56 ;
V_14 -> V_195 = V_91 -> V_76 . V_87 . V_18 . V_20 ;
V_44 = F_13 ( V_14 ) ;
if ( V_14 -> type == V_126 ) {
V_121 = V_196 | V_197 ;
V_48 -> V_70 = V_44 ;
V_48 -> V_51 = V_14 ;
} else {
if ( V_44 == NULL ) {
V_56 = - V_59 ;
goto error;
}
V_121 = V_198 | V_199 ;
V_48 -> V_70 = V_14 ;
V_48 -> V_51 = V_44 ;
}
if ( V_14 -> V_50 -> V_80 -> V_200 )
V_14 -> V_50 -> V_80 -> V_200 ( V_14 -> V_50 , true ) ;
V_48 -> V_58 = F_82 ( V_14 -> V_50 -> clock [ V_201 ] ) ;
V_56 = F_20 ( V_48 ) ;
if ( V_56 < 0 )
goto error;
V_48 -> error = false ;
F_47 ( & V_48 -> V_129 , V_62 ) ;
V_48 -> V_121 &= ~ V_133 ;
V_48 -> V_121 |= V_121 ;
F_49 ( & V_48 -> V_129 , V_62 ) ;
if ( V_14 -> type == V_178 )
V_48 -> V_202 = V_91 -> V_182 ;
V_14 -> V_107 = & V_91 -> V_107 ;
F_83 ( & V_14 -> V_124 ) ;
F_84 ( & V_48 -> V_145 , - 1 ) ;
V_56 = F_85 ( & V_91 -> V_107 ) ;
if ( V_56 < 0 )
goto error;
if ( V_48 -> V_70 == NULL ) {
V_56 = F_50 ( V_48 ,
V_150 ) ;
if ( V_56 < 0 )
goto error;
F_47 ( & V_14 -> V_107 -> V_137 , V_62 ) ;
if ( F_45 ( & V_14 -> V_124 ) )
V_14 -> V_131 |= V_151 ;
F_49 ( & V_14 -> V_107 -> V_137 , V_62 ) ;
}
error:
if ( V_56 < 0 ) {
F_86 ( & V_91 -> V_107 ) ;
if ( V_14 -> V_50 -> V_80 -> V_200 )
V_14 -> V_50 -> V_80 -> V_200 ( V_14 -> V_50 , false ) ;
F_87 ( & V_14 -> V_14 . V_35 ) ;
F_83 ( & V_14 -> V_124 ) ;
V_14 -> V_107 = NULL ;
}
if ( ! V_56 )
V_14 -> V_192 = 1 ;
F_19 ( & V_14 -> V_191 ) ;
return V_56 ;
}
static int
F_88 ( struct V_154 * V_154 , void * V_155 , enum V_190 type )
{
struct V_90 * V_91 = F_64 ( V_155 ) ;
struct V_13 * V_14 = F_61 ( V_154 ) ;
struct V_47 * V_48 = F_44 ( & V_14 -> V_14 . V_35 ) ;
enum V_120 V_121 ;
unsigned int V_192 ;
unsigned long V_62 ;
if ( type != V_14 -> type )
return - V_88 ;
F_14 ( & V_14 -> V_191 ) ;
F_14 ( & V_91 -> V_107 . V_129 ) ;
V_192 = V_91 -> V_107 . V_192 ;
F_19 ( & V_91 -> V_107 . V_129 ) ;
if ( ! V_192 )
goto V_203;
if ( V_14 -> type == V_126 )
V_121 = V_196
| V_127 ;
else
V_121 = V_198
| V_128 ;
F_47 ( & V_48 -> V_129 , V_62 ) ;
V_48 -> V_121 &= ~ V_121 ;
F_49 ( & V_48 -> V_129 , V_62 ) ;
F_50 ( V_48 , V_204 ) ;
F_86 ( & V_91 -> V_107 ) ;
V_14 -> V_107 = NULL ;
V_14 -> V_192 = 0 ;
if ( V_14 -> V_50 -> V_80 -> V_200 )
V_14 -> V_50 -> V_80 -> V_200 ( V_14 -> V_50 , false ) ;
F_87 ( & V_14 -> V_14 . V_35 ) ;
V_203:
F_19 ( & V_14 -> V_191 ) ;
return 0 ;
}
static int
F_89 ( struct V_154 * V_154 , void * V_155 , struct V_205 * V_70 )
{
if ( V_70 -> V_37 > 0 )
return - V_88 ;
F_62 ( V_70 -> V_161 , L_4 , sizeof( V_70 -> V_161 ) ) ;
V_70 -> type = V_206 ;
return 0 ;
}
static int
F_90 ( struct V_154 * V_154 , void * V_155 , unsigned int * V_70 )
{
* V_70 = 0 ;
return 0 ;
}
static int
F_91 ( struct V_154 * V_154 , void * V_155 , unsigned int V_70 )
{
return V_70 == 0 ? 0 : - V_88 ;
}
static int F_92 ( struct V_154 * V_154 )
{
struct V_13 * V_14 = F_61 ( V_154 ) ;
struct V_90 * V_207 ;
int V_56 = 0 ;
V_207 = F_93 ( sizeof( * V_207 ) , V_98 ) ;
if ( V_207 == NULL )
return - V_99 ;
F_94 ( & V_207 -> V_91 , & V_14 -> V_14 ) ;
F_95 ( & V_207 -> V_91 ) ;
if ( F_96 ( V_14 -> V_50 ) == NULL ) {
V_56 = - V_193 ;
goto V_203;
}
V_56 = F_97 ( & V_14 -> V_14 . V_35 , 1 ) ;
if ( V_56 < 0 ) {
F_98 ( V_14 -> V_50 ) ;
goto V_203;
}
F_99 ( & V_207 -> V_107 , V_14 -> type ,
& V_208 , V_14 -> V_50 -> V_104 ,
sizeof( struct V_113 ) ) ;
memset ( & V_207 -> V_76 , 0 , sizeof( V_207 -> V_76 ) ) ;
V_207 -> V_76 . type = V_14 -> type ;
V_207 -> V_182 . V_183 = 1 ;
V_207 -> V_14 = V_14 ;
V_154 -> V_209 = & V_207 -> V_91 ;
V_203:
if ( V_56 < 0 ) {
F_100 ( & V_207 -> V_91 ) ;
F_30 ( V_207 ) ;
}
return V_56 ;
}
static int F_101 ( struct V_154 * V_154 )
{
struct V_13 * V_14 = F_61 ( V_154 ) ;
struct V_210 * V_91 = V_154 -> V_209 ;
struct V_90 * V_207 = F_64 ( V_91 ) ;
F_88 ( V_154 , V_91 , V_14 -> type ) ;
F_14 ( & V_207 -> V_107 . V_129 ) ;
F_102 ( & V_207 -> V_107 ) ;
F_19 ( & V_207 -> V_107 . V_129 ) ;
F_97 ( & V_14 -> V_14 . V_35 , 0 ) ;
F_100 ( V_91 ) ;
F_30 ( V_207 ) ;
V_154 -> V_209 = NULL ;
F_98 ( V_14 -> V_50 ) ;
return 0 ;
}
static unsigned int F_103 ( struct V_154 * V_154 , T_3 * V_148 )
{
struct V_90 * V_91 = F_64 ( V_154 -> V_209 ) ;
struct V_106 * V_107 = & V_91 -> V_107 ;
return F_104 ( V_107 , V_154 , V_148 ) ;
}
static int F_105 ( struct V_154 * V_154 , struct V_211 * V_212 )
{
struct V_90 * V_91 = F_64 ( V_154 -> V_209 ) ;
return F_106 ( & V_91 -> V_107 , V_212 ) ;
}
int F_107 ( struct V_13 * V_14 , const char * V_161 )
{
const char * V_213 ;
int V_56 ;
switch ( V_14 -> type ) {
case V_126 :
V_213 = L_5 ;
V_14 -> V_32 . V_62 = V_63 ;
break;
case V_178 :
V_213 = L_6 ;
V_14 -> V_32 . V_62 = V_214 ;
break;
default:
return - V_88 ;
}
V_56 = F_108 ( & V_14 -> V_14 . V_35 , 1 , & V_14 -> V_32 , 0 ) ;
if ( V_56 < 0 )
return V_56 ;
F_109 ( & V_14 -> V_89 ) ;
F_84 ( & V_14 -> V_215 , 0 ) ;
F_110 ( & V_14 -> V_48 . V_129 ) ;
F_109 ( & V_14 -> V_191 ) ;
if ( V_14 -> V_130 == NULL )
V_14 -> V_130 = & V_216 ;
V_14 -> V_14 . V_217 = & V_218 ;
snprintf ( V_14 -> V_14 . V_161 , sizeof( V_14 -> V_14 . V_161 ) ,
L_7 , V_161 , V_213 ) ;
V_14 -> V_14 . V_219 = V_220 ;
V_14 -> V_14 . V_221 = V_222 ;
V_14 -> V_14 . V_223 = & V_224 ;
V_14 -> V_48 . V_149 = V_204 ;
F_111 ( & V_14 -> V_14 , V_14 ) ;
return 0 ;
}
void F_112 ( struct V_13 * V_14 )
{
F_113 ( & V_14 -> V_14 . V_35 ) ;
F_114 ( & V_14 -> V_191 ) ;
F_114 ( & V_14 -> V_89 ) ;
}
int F_115 ( struct V_13 * V_14 , struct V_225 * V_226 )
{
int V_56 ;
V_14 -> V_14 . V_227 = V_226 ;
V_56 = F_116 ( & V_14 -> V_14 , V_220 , - 1 ) ;
if ( V_56 < 0 )
F_117 ( V_228 L_8 ,
V_229 , V_56 ) ;
return V_56 ;
}
void F_118 ( struct V_13 * V_14 )
{
if ( F_119 ( & V_14 -> V_14 ) )
F_120 ( & V_14 -> V_14 ) ;
}
