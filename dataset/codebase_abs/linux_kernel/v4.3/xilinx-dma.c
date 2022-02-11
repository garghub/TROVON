static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 * V_4 )
{
struct V_2 * V_5 ;
V_5 = F_2 ( V_3 ) ;
if ( V_5 == NULL ||
F_3 ( V_5 -> V_6 ) != V_7 )
return NULL ;
if ( V_4 )
* V_4 = V_5 -> V_8 ;
return F_4 ( V_5 -> V_6 ) ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_11 V_12 ;
struct V_1 * V_13 ;
int V_14 ;
V_13 = F_1 ( & V_10 -> V_4 , & V_12 . V_4 ) ;
if ( V_13 == NULL )
return - V_15 ;
V_12 . V_16 = V_17 ;
V_14 = F_6 ( V_13 , V_4 , V_18 , NULL , & V_12 ) ;
if ( V_14 < 0 )
return V_14 == - V_19 ? - V_20 : V_14 ;
if ( V_10 -> V_21 -> V_22 != V_12 . V_23 . V_22 ||
V_10 -> V_23 . V_24 != V_12 . V_23 . V_24 ||
V_10 -> V_23 . V_25 != V_12 . V_23 . V_25 ||
V_10 -> V_23 . V_26 != V_12 . V_23 . V_26 )
return - V_20 ;
return 0 ;
}
static int F_7 ( struct V_27 * V_28 , bool V_29 )
{
struct V_9 * V_10 = V_28 -> V_30 ;
struct V_31 * V_6 ;
struct V_2 * V_4 ;
struct V_1 * V_13 ;
int V_14 ;
V_6 = & V_10 -> V_32 . V_6 ;
while ( 1 ) {
V_4 = & V_6 -> V_33 [ 0 ] ;
if ( ! ( V_4 -> V_34 & V_35 ) )
break;
V_4 = F_2 ( V_4 ) ;
if ( V_4 == NULL ||
F_3 ( V_4 -> V_6 ) != V_7 )
break;
V_6 = V_4 -> V_6 ;
V_13 = F_4 ( V_6 ) ;
V_14 = F_6 ( V_13 , V_32 , V_36 , V_29 ) ;
if ( V_29 && V_14 < 0 && V_14 != - V_19 )
return V_14 ;
}
return 0 ;
}
static int F_8 ( struct V_27 * V_28 , bool V_37 )
{
int V_14 = 0 ;
F_9 ( & V_28 -> V_38 ) ;
if ( V_37 ) {
if ( V_28 -> V_39 == V_28 -> V_40 - 1 ) {
V_14 = F_7 ( V_28 , true ) ;
if ( V_14 < 0 )
goto V_41;
}
V_28 -> V_39 ++ ;
} else {
if ( -- V_28 -> V_39 == 0 )
F_7 ( V_28 , false ) ;
}
V_41:
F_10 ( & V_28 -> V_38 ) ;
return V_14 ;
}
static int F_11 ( struct V_27 * V_28 ,
struct V_9 * V_29 )
{
struct V_42 V_43 ;
struct V_31 * V_6 = & V_29 -> V_32 . V_6 ;
struct V_44 * V_45 = V_6 -> V_46 ;
unsigned int V_47 = 0 ;
unsigned int V_48 = 0 ;
F_9 ( & V_45 -> V_49 ) ;
F_12 ( & V_43 , V_6 ) ;
while ( ( V_6 = F_13 ( & V_43 ) ) ) {
struct V_9 * V_10 ;
if ( V_6 -> type != V_50 )
continue;
V_10 = F_14 ( F_15 ( V_6 ) ) ;
if ( V_10 -> V_4 . V_34 & V_35 ) {
V_28 -> V_30 = V_10 ;
V_48 ++ ;
} else {
V_47 ++ ;
}
}
F_10 ( & V_45 -> V_49 ) ;
if ( V_48 != 1 || V_47 > 1 )
return - V_15 ;
V_28 -> V_40 = V_47 + V_48 ;
return 0 ;
}
static void F_16 ( struct V_27 * V_28 )
{
V_28 -> V_40 = 0 ;
V_28 -> V_30 = NULL ;
}
static void F_17 ( struct V_27 * V_28 )
{
F_9 ( & V_28 -> V_38 ) ;
if ( -- V_28 -> V_51 == 0 )
F_16 ( V_28 ) ;
F_10 ( & V_28 -> V_38 ) ;
}
static int F_18 ( struct V_27 * V_28 ,
struct V_9 * V_10 )
{
int V_14 ;
F_9 ( & V_28 -> V_38 ) ;
if ( V_28 -> V_51 == 0 ) {
V_14 = F_11 ( V_28 , V_10 ) ;
if ( V_14 < 0 ) {
F_16 ( V_28 ) ;
goto V_41;
}
}
V_28 -> V_51 ++ ;
V_14 = 0 ;
V_41:
F_10 ( & V_28 -> V_38 ) ;
return V_14 ;
}
static void F_19 ( void * V_52 )
{
struct V_53 * V_54 = V_52 ;
struct V_9 * V_10 = V_54 -> V_10 ;
F_20 ( & V_10 -> V_55 ) ;
F_21 ( & V_54 -> V_56 ) ;
F_22 ( & V_10 -> V_55 ) ;
V_54 -> V_54 . V_57 . V_58 = V_59 ;
V_54 -> V_54 . V_57 . V_60 = V_10 -> V_60 ++ ;
F_23 ( & V_54 -> V_54 . V_57 . V_61 ) ;
F_24 ( & V_54 -> V_54 , 0 , V_10 -> V_23 . V_62 ) ;
F_25 ( & V_54 -> V_54 , V_63 ) ;
}
static int
F_26 ( struct V_64 * V_65 , const struct V_66 * V_12 ,
unsigned int * V_67 , unsigned int * V_68 ,
unsigned int V_69 [] , void * V_70 [] )
{
struct V_9 * V_10 = F_27 ( V_65 ) ;
if ( V_12 && V_12 -> V_12 . V_71 . V_62 < V_10 -> V_23 . V_62 )
return - V_20 ;
* V_68 = 1 ;
V_69 [ 0 ] = V_12 ? V_12 -> V_12 . V_71 . V_62 : V_10 -> V_23 . V_62 ;
V_70 [ 0 ] = V_10 -> V_72 ;
return 0 ;
}
static int F_28 ( struct V_73 * V_74 )
{
struct V_9 * V_10 = F_27 ( V_74 -> V_64 ) ;
struct V_53 * V_54 = F_29 ( V_74 ) ;
V_54 -> V_10 = V_10 ;
return 0 ;
}
static void F_30 ( struct V_73 * V_74 )
{
struct V_9 * V_10 = F_27 ( V_74 -> V_64 ) ;
struct V_53 * V_54 = F_29 ( V_74 ) ;
struct V_75 * V_76 ;
T_2 V_77 = F_31 ( V_74 , 0 ) ;
T_1 V_34 ;
if ( V_10 -> V_56 . type == V_78 ) {
V_34 = V_79 | V_80 ;
V_10 -> V_81 . V_82 = V_83 ;
V_10 -> V_81 . V_84 = false ;
V_10 -> V_81 . V_85 = true ;
V_10 -> V_81 . V_86 = V_77 ;
} else {
V_34 = V_79 | V_80 ;
V_10 -> V_81 . V_82 = V_87 ;
V_10 -> V_81 . V_84 = true ;
V_10 -> V_81 . V_85 = false ;
V_10 -> V_81 . V_88 = V_77 ;
}
V_10 -> V_81 . V_89 = 1 ;
V_10 -> V_90 [ 0 ] . V_91 = V_10 -> V_23 . V_25 * V_10 -> V_21 -> V_92 ;
V_10 -> V_90 [ 0 ] . V_93 = V_10 -> V_23 . V_94 - V_10 -> V_90 [ 0 ] . V_91 ;
V_10 -> V_81 . V_95 = V_10 -> V_23 . V_24 ;
V_76 = F_32 ( V_10 -> V_10 , & V_10 -> V_81 , V_34 ) ;
if ( ! V_76 ) {
F_33 ( V_10 -> V_96 -> V_97 , L_1 ) ;
F_25 ( & V_54 -> V_54 , V_98 ) ;
return;
}
V_76 -> V_99 = F_19 ;
V_76 -> V_100 = V_54 ;
F_34 ( & V_10 -> V_55 ) ;
F_35 ( & V_54 -> V_56 , & V_10 -> V_101 ) ;
F_36 ( & V_10 -> V_55 ) ;
F_37 ( V_76 ) ;
if ( F_38 ( & V_10 -> V_56 ) )
F_39 ( V_10 -> V_10 ) ;
}
static int F_40 ( struct V_64 * V_65 , unsigned int V_102 )
{
struct V_9 * V_10 = F_27 ( V_65 ) ;
struct V_53 * V_54 , * V_103 ;
struct V_27 * V_28 ;
int V_14 ;
V_10 -> V_60 = 0 ;
V_28 = V_10 -> V_32 . V_6 . V_28
? F_41 ( & V_10 -> V_32 . V_6 ) : & V_10 -> V_28 ;
V_14 = F_42 ( & V_10 -> V_32 . V_6 , & V_28 -> V_28 ) ;
if ( V_14 < 0 )
goto error;
V_14 = F_5 ( V_10 ) ;
if ( V_14 < 0 )
goto V_104;
V_14 = F_18 ( V_28 , V_10 ) ;
if ( V_14 < 0 )
goto V_104;
F_39 ( V_10 -> V_10 ) ;
F_8 ( V_28 , true ) ;
return 0 ;
V_104:
F_43 ( & V_10 -> V_32 . V_6 ) ;
error:
F_34 ( & V_10 -> V_55 ) ;
F_44 (buf, nbuf, &dma->queued_bufs, queue) {
F_25 ( & V_54 -> V_54 , V_105 ) ;
F_21 ( & V_54 -> V_56 ) ;
}
F_36 ( & V_10 -> V_55 ) ;
return V_14 ;
}
static void F_45 ( struct V_64 * V_65 )
{
struct V_9 * V_10 = F_27 ( V_65 ) ;
struct V_27 * V_28 = F_41 ( & V_10 -> V_32 . V_6 ) ;
struct V_53 * V_54 , * V_103 ;
F_8 ( V_28 , false ) ;
F_46 ( V_10 -> V_10 ) ;
F_17 ( V_28 ) ;
F_43 ( & V_10 -> V_32 . V_6 ) ;
F_34 ( & V_10 -> V_55 ) ;
F_44 (buf, nbuf, &dma->queued_bufs, queue) {
F_25 ( & V_54 -> V_54 , V_98 ) ;
F_21 ( & V_54 -> V_56 ) ;
}
F_36 ( & V_10 -> V_55 ) ;
}
static int
F_47 ( struct V_106 * V_106 , void * V_107 , struct V_108 * V_109 )
{
struct V_110 * V_111 = V_106 -> V_112 ;
struct V_9 * V_10 = F_14 ( V_111 -> V_113 ) ;
V_109 -> V_114 = V_115 | V_116
| V_10 -> V_96 -> V_117 ;
if ( V_10 -> V_56 . type == V_78 )
V_109 -> V_118 = V_119 | V_116 ;
else
V_109 -> V_118 = V_120 | V_116 ;
F_48 ( V_109 -> V_121 , L_2 , sizeof( V_109 -> V_121 ) ) ;
F_48 ( V_109 -> V_122 , V_10 -> V_32 . V_123 , sizeof( V_109 -> V_122 ) ) ;
snprintf ( V_109 -> V_124 , sizeof( V_109 -> V_124 ) , L_3 ,
V_10 -> V_96 -> V_97 -> V_125 -> V_123 , V_10 -> V_126 ) ;
return 0 ;
}
static int
F_49 ( struct V_106 * V_106 , void * V_107 , struct V_127 * V_128 )
{
struct V_110 * V_111 = V_106 -> V_112 ;
struct V_9 * V_10 = F_14 ( V_111 -> V_113 ) ;
if ( V_128 -> V_8 > 0 )
return - V_20 ;
V_128 -> V_129 = V_10 -> V_23 . V_129 ;
F_48 ( V_128 -> V_130 , V_10 -> V_21 -> V_130 ,
sizeof( V_128 -> V_130 ) ) ;
return 0 ;
}
static int
F_50 ( struct V_106 * V_106 , void * V_107 , struct V_66 * V_23 )
{
struct V_110 * V_111 = V_106 -> V_112 ;
struct V_9 * V_10 = F_14 ( V_111 -> V_113 ) ;
V_23 -> V_12 . V_71 = V_10 -> V_23 ;
return 0 ;
}
static void
F_51 ( struct V_9 * V_10 , struct V_131 * V_71 ,
const struct V_132 * * V_21 )
{
const struct V_132 * V_133 ;
unsigned int V_134 ;
unsigned int V_135 ;
unsigned int V_136 ;
unsigned int V_137 ;
unsigned int V_25 ;
unsigned int V_138 ;
unsigned int V_139 ;
V_133 = F_52 ( V_71 -> V_129 ) ;
if ( F_53 ( V_133 ) )
V_133 = F_52 ( V_140 ) ;
V_71 -> V_129 = V_133 -> V_141 ;
V_71 -> V_58 = V_59 ;
V_138 = F_54 ( V_10 -> V_138 , V_133 -> V_92 ) ;
V_134 = F_55 ( V_142 , V_138 ) ;
V_135 = F_56 ( V_143 , V_138 ) ;
V_25 = F_56 ( V_71 -> V_25 * V_133 -> V_92 , V_138 ) ;
V_71 -> V_25 = F_57 ( V_25 , V_134 , V_135 ) / V_133 -> V_92 ;
V_71 -> V_24 = F_57 ( V_71 -> V_24 , V_144 ,
V_145 ) ;
V_136 = V_71 -> V_25 * V_133 -> V_92 ;
V_137 = F_56 ( V_143 , V_10 -> V_138 ) ;
V_139 = F_56 ( V_71 -> V_94 , V_10 -> V_138 ) ;
V_71 -> V_94 = F_57 ( V_139 , V_136 , V_137 ) ;
V_71 -> V_62 = V_71 -> V_94 * V_71 -> V_24 ;
if ( V_21 )
* V_21 = V_133 ;
}
static int
F_58 ( struct V_106 * V_106 , void * V_107 , struct V_66 * V_23 )
{
struct V_110 * V_111 = V_106 -> V_112 ;
struct V_9 * V_10 = F_14 ( V_111 -> V_113 ) ;
F_51 ( V_10 , & V_23 -> V_12 . V_71 , NULL ) ;
return 0 ;
}
static int
F_59 ( struct V_106 * V_106 , void * V_107 , struct V_66 * V_23 )
{
struct V_110 * V_111 = V_106 -> V_112 ;
struct V_9 * V_10 = F_14 ( V_111 -> V_113 ) ;
const struct V_132 * V_133 ;
F_51 ( V_10 , & V_23 -> V_12 . V_71 , & V_133 ) ;
if ( F_60 ( & V_10 -> V_56 ) )
return - V_146 ;
V_10 -> V_23 = V_23 -> V_12 . V_71 ;
V_10 -> V_21 = V_133 ;
return 0 ;
}
int F_61 ( struct V_147 * V_96 , struct V_9 * V_10 ,
enum V_148 type , unsigned int V_126 )
{
char V_123 [ 16 ] ;
int V_14 ;
V_10 -> V_96 = V_96 ;
V_10 -> V_126 = V_126 ;
F_62 ( & V_10 -> V_38 ) ;
F_62 ( & V_10 -> V_28 . V_38 ) ;
F_63 ( & V_10 -> V_101 ) ;
F_64 ( & V_10 -> V_55 ) ;
V_10 -> V_21 = F_52 ( V_140 ) ;
V_10 -> V_23 . V_129 = V_10 -> V_21 -> V_141 ;
V_10 -> V_23 . V_26 = V_149 ;
V_10 -> V_23 . V_58 = V_59 ;
V_10 -> V_23 . V_25 = V_150 ;
V_10 -> V_23 . V_24 = V_151 ;
V_10 -> V_23 . V_94 = V_10 -> V_23 . V_25 * V_10 -> V_21 -> V_92 ;
V_10 -> V_23 . V_62 = V_10 -> V_23 . V_94 * V_10 -> V_23 . V_24 ;
V_10 -> V_4 . V_34 = type == V_78
? V_35 : V_152 ;
V_14 = F_65 ( & V_10 -> V_32 . V_6 , 1 , & V_10 -> V_4 , 0 ) ;
if ( V_14 < 0 )
goto error;
V_10 -> V_32 . V_153 = & V_154 ;
V_10 -> V_32 . V_155 = & V_96 -> V_155 ;
V_10 -> V_32 . V_56 = & V_10 -> V_56 ;
snprintf ( V_10 -> V_32 . V_123 , sizeof( V_10 -> V_32 . V_123 ) , L_4 ,
V_96 -> V_97 -> V_125 -> V_123 ,
type == V_78 ? L_5 : L_6 ,
V_126 ) ;
V_10 -> V_32 . V_156 = V_157 ;
V_10 -> V_32 . V_158 = type == V_78
? V_159 : V_160 ;
V_10 -> V_32 . V_161 = V_162 ;
V_10 -> V_32 . V_163 = & V_164 ;
V_10 -> V_32 . V_38 = & V_10 -> V_38 ;
F_66 ( & V_10 -> V_32 , V_10 ) ;
V_10 -> V_72 = F_67 ( V_10 -> V_96 -> V_97 ) ;
if ( F_53 ( V_10 -> V_72 ) ) {
V_14 = F_68 ( V_10 -> V_72 ) ;
goto error;
}
V_10 -> V_56 . type = type ;
V_10 -> V_56 . V_165 = V_166 | V_167 | V_168 ;
V_10 -> V_56 . V_38 = & V_10 -> V_38 ;
V_10 -> V_56 . V_169 = V_10 ;
V_10 -> V_56 . V_170 = sizeof( struct V_53 ) ;
V_10 -> V_56 . V_171 = & V_172 ;
V_10 -> V_56 . V_173 = & V_174 ;
V_10 -> V_56 . V_175 = V_176
| V_177 ;
V_14 = F_69 ( & V_10 -> V_56 ) ;
if ( V_14 < 0 ) {
F_33 ( V_10 -> V_96 -> V_97 , L_7 ) ;
goto error;
}
snprintf ( V_123 , sizeof( V_123 ) , L_8 , V_126 ) ;
V_10 -> V_10 = F_70 ( V_10 -> V_96 -> V_97 , V_123 ) ;
if ( V_10 -> V_10 == NULL ) {
F_33 ( V_10 -> V_96 -> V_97 , L_9 ) ;
V_14 = - V_178 ;
goto error;
}
V_10 -> V_138 = 1 << V_10 -> V_10 -> V_179 -> V_180 ;
V_14 = F_71 ( & V_10 -> V_32 , V_157 , - 1 ) ;
if ( V_14 < 0 ) {
F_33 ( V_10 -> V_96 -> V_97 , L_10 ) ;
goto error;
}
return 0 ;
error:
F_72 ( V_10 ) ;
return V_14 ;
}
void F_72 ( struct V_9 * V_10 )
{
if ( F_73 ( & V_10 -> V_32 ) )
F_74 ( & V_10 -> V_32 ) ;
if ( V_10 -> V_10 )
F_75 ( V_10 -> V_10 ) ;
if ( ! F_76 ( V_10 -> V_72 ) )
F_77 ( V_10 -> V_72 ) ;
F_78 ( & V_10 -> V_32 . V_6 ) ;
F_79 ( & V_10 -> V_38 ) ;
F_79 ( & V_10 -> V_28 . V_38 ) ;
}
