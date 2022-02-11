static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 * V_4 )
{
struct V_2 * V_5 ;
V_5 = F_2 ( V_3 ) ;
if ( ! V_5 || ! F_3 ( V_5 -> V_6 ) )
return NULL ;
if ( V_4 )
* V_4 = V_5 -> V_7 ;
return F_4 ( V_5 -> V_6 ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_10 V_11 ;
struct V_1 * V_12 ;
int V_13 ;
V_12 = F_1 ( & V_9 -> V_4 , & V_11 . V_4 ) ;
if ( V_12 == NULL )
return - V_14 ;
V_11 . V_15 = V_16 ;
V_13 = F_6 ( V_12 , V_4 , V_17 , NULL , & V_11 ) ;
if ( V_13 < 0 )
return V_13 == - V_18 ? - V_19 : V_13 ;
if ( V_9 -> V_20 -> V_21 != V_11 . V_22 . V_21 ||
V_9 -> V_22 . V_23 != V_11 . V_22 . V_23 ||
V_9 -> V_22 . V_24 != V_11 . V_22 . V_24 ||
V_9 -> V_22 . V_25 != V_11 . V_22 . V_25 )
return - V_19 ;
return 0 ;
}
static int F_7 ( struct V_26 * V_27 , bool V_28 )
{
struct V_8 * V_9 = V_27 -> V_29 ;
struct V_30 * V_6 ;
struct V_2 * V_4 ;
struct V_1 * V_12 ;
int V_13 ;
V_6 = & V_9 -> V_31 . V_6 ;
while ( 1 ) {
V_4 = & V_6 -> V_32 [ 0 ] ;
if ( ! ( V_4 -> V_33 & V_34 ) )
break;
V_4 = F_2 ( V_4 ) ;
if ( ! V_4 || ! F_3 ( V_4 -> V_6 ) )
break;
V_6 = V_4 -> V_6 ;
V_12 = F_4 ( V_6 ) ;
V_13 = F_6 ( V_12 , V_31 , V_35 , V_28 ) ;
if ( V_28 && V_13 < 0 && V_13 != - V_18 )
return V_13 ;
}
return 0 ;
}
static int F_8 ( struct V_26 * V_27 , bool V_36 )
{
int V_13 = 0 ;
F_9 ( & V_27 -> V_37 ) ;
if ( V_36 ) {
if ( V_27 -> V_38 == V_27 -> V_39 - 1 ) {
V_13 = F_7 ( V_27 , true ) ;
if ( V_13 < 0 )
goto V_40;
}
V_27 -> V_38 ++ ;
} else {
if ( -- V_27 -> V_38 == 0 )
F_7 ( V_27 , false ) ;
}
V_40:
F_10 ( & V_27 -> V_37 ) ;
return V_13 ;
}
static int F_11 ( struct V_26 * V_27 ,
struct V_8 * V_28 )
{
struct V_41 V_42 ;
struct V_30 * V_6 = & V_28 -> V_31 . V_6 ;
struct V_43 * V_44 = V_6 -> V_45 . V_44 ;
unsigned int V_46 = 0 ;
unsigned int V_47 = 0 ;
int V_13 ;
F_9 ( & V_44 -> V_48 ) ;
V_13 = F_12 ( & V_42 , V_6 -> V_45 . V_44 ) ;
if ( V_13 ) {
F_10 ( & V_44 -> V_48 ) ;
return V_13 ;
}
F_13 ( & V_42 , V_6 ) ;
while ( ( V_6 = F_14 ( & V_42 ) ) ) {
struct V_8 * V_9 ;
if ( V_6 -> V_49 != V_50 )
continue;
V_9 = F_15 ( F_16 ( V_6 ) ) ;
if ( V_9 -> V_4 . V_33 & V_34 ) {
V_27 -> V_29 = V_9 ;
V_47 ++ ;
} else {
V_46 ++ ;
}
}
F_10 ( & V_44 -> V_48 ) ;
F_17 ( & V_42 ) ;
if ( V_47 != 1 || V_46 > 1 )
return - V_14 ;
V_27 -> V_39 = V_46 + V_47 ;
return 0 ;
}
static void F_18 ( struct V_26 * V_27 )
{
V_27 -> V_39 = 0 ;
V_27 -> V_29 = NULL ;
}
static void F_19 ( struct V_26 * V_27 )
{
F_9 ( & V_27 -> V_37 ) ;
if ( -- V_27 -> V_51 == 0 )
F_18 ( V_27 ) ;
F_10 ( & V_27 -> V_37 ) ;
}
static int F_20 ( struct V_26 * V_27 ,
struct V_8 * V_9 )
{
int V_13 ;
F_9 ( & V_27 -> V_37 ) ;
if ( V_27 -> V_51 == 0 ) {
V_13 = F_11 ( V_27 , V_9 ) ;
if ( V_13 < 0 ) {
F_18 ( V_27 ) ;
goto V_40;
}
}
V_27 -> V_51 ++ ;
V_13 = 0 ;
V_40:
F_10 ( & V_27 -> V_37 ) ;
return V_13 ;
}
static void F_21 ( void * V_52 )
{
struct V_53 * V_54 = V_52 ;
struct V_8 * V_9 = V_54 -> V_9 ;
F_22 ( & V_9 -> V_55 ) ;
F_23 ( & V_54 -> V_56 ) ;
F_24 ( & V_9 -> V_55 ) ;
V_54 -> V_54 . V_57 = V_58 ;
V_54 -> V_54 . V_59 = V_9 -> V_59 ++ ;
V_54 -> V_54 . V_60 . V_61 = F_25 () ;
F_26 ( & V_54 -> V_54 . V_60 , 0 , V_9 -> V_22 . V_62 ) ;
F_27 ( & V_54 -> V_54 . V_60 , V_63 ) ;
}
static int
F_28 ( struct V_64 * V_65 ,
unsigned int * V_66 , unsigned int * V_67 ,
unsigned int V_68 [] , struct V_69 * V_70 [] )
{
struct V_8 * V_9 = F_29 ( V_65 ) ;
if ( * V_67 )
return V_68 [ 0 ] < V_9 -> V_22 . V_62 ? - V_19 : 0 ;
* V_67 = 1 ;
V_68 [ 0 ] = V_9 -> V_22 . V_62 ;
return 0 ;
}
static int F_30 ( struct V_71 * V_72 )
{
struct V_73 * V_74 = F_31 ( V_72 ) ;
struct V_8 * V_9 = F_29 ( V_72 -> V_64 ) ;
struct V_53 * V_54 = F_32 ( V_74 ) ;
V_54 -> V_9 = V_9 ;
return 0 ;
}
static void F_33 ( struct V_71 * V_72 )
{
struct V_73 * V_74 = F_31 ( V_72 ) ;
struct V_8 * V_9 = F_29 ( V_72 -> V_64 ) ;
struct V_53 * V_54 = F_32 ( V_74 ) ;
struct V_75 * V_76 ;
T_2 V_77 = F_34 ( V_72 , 0 ) ;
T_1 V_33 ;
if ( V_9 -> V_56 . type == V_78 ) {
V_33 = V_79 | V_80 ;
V_9 -> V_81 . V_82 = V_83 ;
V_9 -> V_81 . V_84 = false ;
V_9 -> V_81 . V_85 = true ;
V_9 -> V_81 . V_86 = V_77 ;
} else {
V_33 = V_79 | V_80 ;
V_9 -> V_81 . V_82 = V_87 ;
V_9 -> V_81 . V_84 = true ;
V_9 -> V_81 . V_85 = false ;
V_9 -> V_81 . V_88 = V_77 ;
}
V_9 -> V_81 . V_89 = 1 ;
V_9 -> V_90 [ 0 ] . V_91 = V_9 -> V_22 . V_24 * V_9 -> V_20 -> V_92 ;
V_9 -> V_90 [ 0 ] . V_93 = V_9 -> V_22 . V_94 - V_9 -> V_90 [ 0 ] . V_91 ;
V_9 -> V_81 . V_95 = V_9 -> V_22 . V_23 ;
V_76 = F_35 ( V_9 -> V_9 , & V_9 -> V_81 , V_33 ) ;
if ( ! V_76 ) {
F_36 ( V_9 -> V_96 -> V_97 , L_1 ) ;
F_27 ( & V_54 -> V_54 . V_60 , V_98 ) ;
return;
}
V_76 -> V_99 = F_21 ;
V_76 -> V_100 = V_54 ;
F_37 ( & V_9 -> V_55 ) ;
F_38 ( & V_54 -> V_56 , & V_9 -> V_101 ) ;
F_39 ( & V_9 -> V_55 ) ;
F_40 ( V_76 ) ;
if ( F_41 ( & V_9 -> V_56 ) )
F_42 ( V_9 -> V_9 ) ;
}
static int F_43 ( struct V_64 * V_65 , unsigned int V_102 )
{
struct V_8 * V_9 = F_29 ( V_65 ) ;
struct V_53 * V_54 , * V_103 ;
struct V_26 * V_27 ;
int V_13 ;
V_9 -> V_59 = 0 ;
V_27 = V_9 -> V_31 . V_6 . V_27
? F_44 ( & V_9 -> V_31 . V_6 ) : & V_9 -> V_27 ;
V_13 = F_45 ( & V_9 -> V_31 . V_6 , & V_27 -> V_27 ) ;
if ( V_13 < 0 )
goto error;
V_13 = F_5 ( V_9 ) ;
if ( V_13 < 0 )
goto V_104;
V_13 = F_20 ( V_27 , V_9 ) ;
if ( V_13 < 0 )
goto V_104;
F_42 ( V_9 -> V_9 ) ;
F_8 ( V_27 , true ) ;
return 0 ;
V_104:
F_46 ( & V_9 -> V_31 . V_6 ) ;
error:
F_37 ( & V_9 -> V_55 ) ;
F_47 (buf, nbuf, &dma->queued_bufs, queue) {
F_27 ( & V_54 -> V_54 . V_60 , V_105 ) ;
F_23 ( & V_54 -> V_56 ) ;
}
F_39 ( & V_9 -> V_55 ) ;
return V_13 ;
}
static void F_48 ( struct V_64 * V_65 )
{
struct V_8 * V_9 = F_29 ( V_65 ) ;
struct V_26 * V_27 = F_44 ( & V_9 -> V_31 . V_6 ) ;
struct V_53 * V_54 , * V_103 ;
F_8 ( V_27 , false ) ;
F_49 ( V_9 -> V_9 ) ;
F_19 ( V_27 ) ;
F_46 ( & V_9 -> V_31 . V_6 ) ;
F_37 ( & V_9 -> V_55 ) ;
F_47 (buf, nbuf, &dma->queued_bufs, queue) {
F_27 ( & V_54 -> V_54 . V_60 , V_98 ) ;
F_23 ( & V_54 -> V_56 ) ;
}
F_39 ( & V_9 -> V_55 ) ;
}
static int
F_50 ( struct V_106 * V_106 , void * V_107 , struct V_108 * V_109 )
{
struct V_110 * V_111 = V_106 -> V_112 ;
struct V_8 * V_9 = F_15 ( V_111 -> V_113 ) ;
V_109 -> V_114 = V_115 | V_116
| V_9 -> V_96 -> V_117 ;
if ( V_9 -> V_56 . type == V_78 )
V_109 -> V_118 = V_119 | V_116 ;
else
V_109 -> V_118 = V_120 | V_116 ;
F_51 ( V_109 -> V_121 , L_2 , sizeof( V_109 -> V_121 ) ) ;
F_51 ( V_109 -> V_122 , V_9 -> V_31 . V_123 , sizeof( V_109 -> V_122 ) ) ;
snprintf ( V_109 -> V_124 , sizeof( V_109 -> V_124 ) , L_3 ,
V_9 -> V_96 -> V_97 -> V_125 -> V_123 , V_9 -> V_126 ) ;
return 0 ;
}
static int
F_52 ( struct V_106 * V_106 , void * V_107 , struct V_127 * V_128 )
{
struct V_110 * V_111 = V_106 -> V_112 ;
struct V_8 * V_9 = F_15 ( V_111 -> V_113 ) ;
if ( V_128 -> V_7 > 0 )
return - V_19 ;
V_128 -> V_129 = V_9 -> V_22 . V_129 ;
F_51 ( V_128 -> V_130 , V_9 -> V_20 -> V_130 ,
sizeof( V_128 -> V_130 ) ) ;
return 0 ;
}
static int
F_53 ( struct V_106 * V_106 , void * V_107 , struct V_131 * V_22 )
{
struct V_110 * V_111 = V_106 -> V_112 ;
struct V_8 * V_9 = F_15 ( V_111 -> V_113 ) ;
V_22 -> V_11 . V_132 = V_9 -> V_22 ;
return 0 ;
}
static void
F_54 ( struct V_8 * V_9 , struct V_133 * V_132 ,
const struct V_134 * * V_20 )
{
const struct V_134 * V_135 ;
unsigned int V_136 ;
unsigned int V_137 ;
unsigned int V_138 ;
unsigned int V_139 ;
unsigned int V_24 ;
unsigned int V_140 ;
unsigned int V_141 ;
V_135 = F_55 ( V_132 -> V_129 ) ;
if ( F_56 ( V_135 ) )
V_135 = F_55 ( V_142 ) ;
V_132 -> V_129 = V_135 -> V_143 ;
V_132 -> V_57 = V_58 ;
V_140 = F_57 ( V_9 -> V_140 , V_135 -> V_92 ) ;
V_136 = F_58 ( V_144 , V_140 ) ;
V_137 = F_59 ( V_145 , V_140 ) ;
V_24 = F_59 ( V_132 -> V_24 * V_135 -> V_92 , V_140 ) ;
V_132 -> V_24 = F_60 ( V_24 , V_136 , V_137 ) / V_135 -> V_92 ;
V_132 -> V_23 = F_60 ( V_132 -> V_23 , V_146 ,
V_147 ) ;
V_138 = V_132 -> V_24 * V_135 -> V_92 ;
V_139 = F_59 ( V_145 , V_9 -> V_140 ) ;
V_141 = F_59 ( V_132 -> V_94 , V_9 -> V_140 ) ;
V_132 -> V_94 = F_60 ( V_141 , V_138 , V_139 ) ;
V_132 -> V_62 = V_132 -> V_94 * V_132 -> V_23 ;
if ( V_20 )
* V_20 = V_135 ;
}
static int
F_61 ( struct V_106 * V_106 , void * V_107 , struct V_131 * V_22 )
{
struct V_110 * V_111 = V_106 -> V_112 ;
struct V_8 * V_9 = F_15 ( V_111 -> V_113 ) ;
F_54 ( V_9 , & V_22 -> V_11 . V_132 , NULL ) ;
return 0 ;
}
static int
F_62 ( struct V_106 * V_106 , void * V_107 , struct V_131 * V_22 )
{
struct V_110 * V_111 = V_106 -> V_112 ;
struct V_8 * V_9 = F_15 ( V_111 -> V_113 ) ;
const struct V_134 * V_135 ;
F_54 ( V_9 , & V_22 -> V_11 . V_132 , & V_135 ) ;
if ( F_63 ( & V_9 -> V_56 ) )
return - V_148 ;
V_9 -> V_22 = V_22 -> V_11 . V_132 ;
V_9 -> V_20 = V_135 ;
return 0 ;
}
int F_64 ( struct V_149 * V_96 , struct V_8 * V_9 ,
enum V_150 type , unsigned int V_126 )
{
char V_123 [ 16 ] ;
int V_13 ;
V_9 -> V_96 = V_96 ;
V_9 -> V_126 = V_126 ;
F_65 ( & V_9 -> V_37 ) ;
F_65 ( & V_9 -> V_27 . V_37 ) ;
F_66 ( & V_9 -> V_101 ) ;
F_67 ( & V_9 -> V_55 ) ;
V_9 -> V_20 = F_55 ( V_142 ) ;
V_9 -> V_22 . V_129 = V_9 -> V_20 -> V_143 ;
V_9 -> V_22 . V_25 = V_151 ;
V_9 -> V_22 . V_57 = V_58 ;
V_9 -> V_22 . V_24 = V_152 ;
V_9 -> V_22 . V_23 = V_153 ;
V_9 -> V_22 . V_94 = V_9 -> V_22 . V_24 * V_9 -> V_20 -> V_92 ;
V_9 -> V_22 . V_62 = V_9 -> V_22 . V_94 * V_9 -> V_22 . V_23 ;
V_9 -> V_4 . V_33 = type == V_78
? V_34 : V_154 ;
V_13 = F_68 ( & V_9 -> V_31 . V_6 , 1 , & V_9 -> V_4 ) ;
if ( V_13 < 0 )
goto error;
V_9 -> V_31 . V_155 = & V_156 ;
V_9 -> V_31 . V_157 = & V_96 -> V_157 ;
V_9 -> V_31 . V_56 = & V_9 -> V_56 ;
snprintf ( V_9 -> V_31 . V_123 , sizeof( V_9 -> V_31 . V_123 ) , L_4 ,
V_96 -> V_97 -> V_125 -> V_123 ,
type == V_78 ? L_5 : L_6 ,
V_126 ) ;
V_9 -> V_31 . V_158 = V_159 ;
V_9 -> V_31 . V_160 = type == V_78
? V_161 : V_162 ;
V_9 -> V_31 . V_163 = V_164 ;
V_9 -> V_31 . V_165 = & V_166 ;
V_9 -> V_31 . V_37 = & V_9 -> V_37 ;
F_69 ( & V_9 -> V_31 , V_9 ) ;
V_9 -> V_56 . type = type ;
V_9 -> V_56 . V_167 = V_168 | V_169 | V_170 ;
V_9 -> V_56 . V_37 = & V_9 -> V_37 ;
V_9 -> V_56 . V_171 = V_9 ;
V_9 -> V_56 . V_172 = sizeof( struct V_53 ) ;
V_9 -> V_56 . V_173 = & V_174 ;
V_9 -> V_56 . V_175 = & V_176 ;
V_9 -> V_56 . V_177 = V_178
| V_179 ;
V_9 -> V_56 . V_97 = V_9 -> V_96 -> V_97 ;
V_13 = F_70 ( & V_9 -> V_56 ) ;
if ( V_13 < 0 ) {
F_36 ( V_9 -> V_96 -> V_97 , L_7 ) ;
goto error;
}
snprintf ( V_123 , sizeof( V_123 ) , L_8 , V_126 ) ;
V_9 -> V_9 = F_71 ( V_9 -> V_96 -> V_97 , V_123 ) ;
if ( V_9 -> V_9 == NULL ) {
F_36 ( V_9 -> V_96 -> V_97 , L_9 ) ;
V_13 = - V_180 ;
goto error;
}
V_9 -> V_140 = 1 << V_9 -> V_9 -> V_69 -> V_181 ;
V_13 = F_72 ( & V_9 -> V_31 , V_159 , - 1 ) ;
if ( V_13 < 0 ) {
F_36 ( V_9 -> V_96 -> V_97 , L_10 ) ;
goto error;
}
return 0 ;
error:
F_73 ( V_9 ) ;
return V_13 ;
}
void F_73 ( struct V_8 * V_9 )
{
if ( F_74 ( & V_9 -> V_31 ) )
F_75 ( & V_9 -> V_31 ) ;
if ( V_9 -> V_9 )
F_76 ( V_9 -> V_9 ) ;
F_77 ( & V_9 -> V_31 . V_6 ) ;
F_78 ( & V_9 -> V_37 ) ;
F_78 ( & V_9 -> V_27 . V_37 ) ;
}
