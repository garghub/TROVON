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
return V_13 == - V_18 ? - V_14 : V_13 ;
if ( V_9 -> V_19 -> V_20 -> V_21 != V_11 . V_22 . V_23 ||
V_9 -> V_19 -> V_22 . V_24 != V_11 . V_22 . V_24 ||
V_9 -> V_19 -> V_22 . V_25 != V_11 . V_22 . V_25 )
return - V_14 ;
return 0 ;
}
static int F_7 ( struct V_8 * V_9 ,
struct V_26 * V_27 ,
const struct V_28 * * V_20 )
{
static const T_1 V_29 [] [ 2 ] = {
{ V_30 , V_31 } ,
{ V_32 , V_33 } ,
{ V_34 , V_35 } ,
{ V_36 , V_37 } ,
} ;
const struct V_28 * V_38 ;
unsigned int V_25 = V_27 -> V_25 ;
unsigned int V_24 = V_27 -> V_24 ;
unsigned int V_39 ;
for ( V_39 = 0 ; V_39 < F_8 ( V_29 ) ; ++ V_39 ) {
if ( V_29 [ V_39 ] [ 0 ] == V_27 -> V_40 ) {
V_27 -> V_40 = V_29 [ V_39 ] [ 1 ] ;
break;
}
}
V_38 = F_9 ( V_9 -> V_41 , V_27 -> V_40 ) ;
if ( V_38 == NULL )
V_38 = F_9 ( V_9 -> V_41 , V_42 ) ;
V_27 -> V_40 = V_38 -> V_43 ;
V_27 -> V_44 = V_45 ;
V_27 -> V_46 = V_47 ;
if ( V_38 -> V_43 == V_48 ||
V_38 -> V_43 == V_49 )
V_27 -> V_50 = V_51 ;
memset ( V_27 -> V_52 , 0 , sizeof( V_27 -> V_52 ) ) ;
V_25 = F_10 ( V_25 , V_38 -> V_53 ) ;
V_24 = F_10 ( V_24 , V_38 -> V_54 ) ;
V_27 -> V_25 = F_11 ( V_25 , V_55 , V_56 ) ;
V_27 -> V_24 = F_11 ( V_24 , V_57 ,
V_58 ) ;
for ( V_39 = 0 ; V_39 < F_12 ( V_38 -> V_59 , 2U ) ; ++ V_39 ) {
unsigned int V_53 = V_39 > 0 ? V_38 -> V_53 : 1 ;
unsigned int V_54 = V_39 > 0 ? V_38 -> V_54 : 1 ;
unsigned int V_60 = 128 ;
unsigned int V_61 ;
V_61 = F_13 (unsigned int, pix->plane_fmt[i].bytesperline,
pix->width / hsub * info->bpp[i] / 8 ,
round_down(65535U, align)) ;
V_27 -> V_62 [ V_39 ] . V_63 = F_14 ( V_61 , V_60 ) ;
V_27 -> V_62 [ V_39 ] . V_64 = V_27 -> V_62 [ V_39 ] . V_63
* V_27 -> V_24 / V_54 ;
}
if ( V_38 -> V_59 == 3 ) {
V_27 -> V_62 [ 2 ] . V_63 = V_27 -> V_62 [ 1 ] . V_63 ;
V_27 -> V_62 [ 2 ] . V_64 = V_27 -> V_62 [ 1 ] . V_64 ;
}
V_27 -> V_65 = V_38 -> V_59 ;
if ( V_20 )
* V_20 = V_38 ;
return 0 ;
}
static void F_15 ( struct V_66 * V_67 ,
struct V_68 * V_69 ,
unsigned int V_70 ,
unsigned int V_7 )
{
const struct V_71 * V_22 ;
struct V_72 V_73 ;
unsigned int V_74 ;
V_22 = F_16 ( & V_67 -> V_75 -> V_6 ,
V_67 -> V_75 -> V_6 . V_76 ,
V_77 ) ;
if ( V_67 -> V_78 <= 1 ) {
V_73 . V_79 = 0 ;
V_73 . V_25 = V_22 -> V_25 ;
F_17 ( V_67 , V_69 , V_7 ,
& V_73 ) ;
return;
}
V_73 . V_79 = V_7 * V_70 ;
V_73 . V_25 = V_70 ;
V_74 = V_22 -> V_25 % V_70 ;
if ( V_74 ) {
unsigned int V_78 = V_67 -> V_78 - 1 ;
if ( V_74 < V_70 / 2 ) {
if ( V_7 == V_78 - 1 ) {
V_73 . V_25 = V_70 / 2 ;
} else if ( V_7 == V_78 ) {
V_73 . V_25 = ( V_70 / 2 ) + V_74 ;
V_73 . V_79 -= V_70 / 2 ;
}
} else if ( V_7 == V_78 ) {
V_73 . V_25 = V_74 ;
}
}
F_17 ( V_67 , V_69 , V_7 , & V_73 ) ;
}
static int F_18 ( struct V_66 * V_67 )
{
struct V_80 * V_41 = V_67 -> V_75 -> V_6 . V_41 ;
const struct V_71 * V_22 ;
struct V_81 * V_6 ;
unsigned int V_70 ;
unsigned int V_39 ;
V_22 = F_16 ( & V_67 -> V_75 -> V_6 ,
V_67 -> V_75 -> V_6 . V_76 ,
V_77 ) ;
V_70 = V_22 -> V_25 ;
if ( V_41 -> V_38 -> V_82 == 3 ) {
F_19 (entity, &pipe->entities, list_pipe) {
unsigned int V_83 ;
if ( ! V_6 -> V_84 -> V_85 )
continue;
V_83 = V_6 -> V_84 -> V_85 ( V_6 , V_67 ) ;
if ( V_83 )
V_70 = F_12 ( V_70 , V_83 ) ;
}
}
V_67 -> V_78 = F_20 ( V_22 -> V_25 , V_70 ) ;
V_67 -> V_86 = F_21 ( V_67 -> V_78 , sizeof( * V_67 -> V_86 ) ,
V_87 ) ;
if ( ! V_67 -> V_86 )
return - V_88 ;
for ( V_39 = 0 ; V_39 < V_67 -> V_78 ; ++ V_39 )
F_15 ( V_67 , & V_67 -> V_86 [ V_39 ] ,
V_70 , V_39 ) ;
return 0 ;
}
static struct V_89 *
F_22 ( struct V_8 * V_9 )
{
struct V_66 * V_67 = V_9 -> V_19 -> V_67 ;
struct V_89 * V_90 = NULL ;
struct V_89 * V_91 ;
unsigned long V_92 ;
unsigned int V_39 ;
F_23 ( & V_9 -> V_93 , V_92 ) ;
if ( F_24 ( & V_9 -> V_94 ) ) {
F_25 ( & V_9 -> V_93 , V_92 ) ;
return NULL ;
}
V_91 = F_26 ( & V_9 -> V_94 ,
struct V_89 , V_95 ) ;
if ( V_67 -> V_96 && F_27 ( & V_9 -> V_94 ) ) {
F_25 ( & V_9 -> V_93 , V_92 ) ;
return V_91 ;
}
F_28 ( & V_91 -> V_95 ) ;
if ( ! F_24 ( & V_9 -> V_94 ) )
V_90 = F_26 ( & V_9 -> V_94 ,
struct V_89 , V_95 ) ;
F_25 ( & V_9 -> V_93 , V_92 ) ;
V_91 -> V_97 . V_98 = V_67 -> V_98 ;
V_91 -> V_97 . V_99 . V_100 = F_29 () ;
for ( V_39 = 0 ; V_39 < V_91 -> V_97 . V_99 . V_65 ; ++ V_39 )
F_30 ( & V_91 -> V_97 . V_99 , V_39 ,
F_31 ( & V_91 -> V_97 . V_99 , V_39 ) ) ;
F_32 ( & V_91 -> V_97 . V_99 , V_101 ) ;
return V_90 ;
}
static void F_33 ( struct V_66 * V_67 ,
struct V_102 * V_19 )
{
struct V_8 * V_9 = V_19 -> V_9 ;
struct V_89 * V_97 ;
V_97 = F_22 ( V_9 ) ;
if ( V_97 == NULL )
return;
V_9 -> V_19 -> V_103 = V_97 -> V_103 ;
V_67 -> V_104 |= 1 << V_9 -> V_105 ;
}
static void F_34 ( struct V_66 * V_67 ,
struct V_106 * V_107 ,
unsigned int V_69 )
{
struct V_81 * V_6 ;
V_67 -> V_69 = & V_67 -> V_86 [ V_69 ] ;
F_19 (entity, &pipe->entities, list_pipe) {
if ( V_6 -> V_84 -> V_108 )
V_6 -> V_84 -> V_108 ( V_6 , V_67 , V_107 ,
V_109 ) ;
}
}
static void F_35 ( struct V_66 * V_67 )
{
struct V_80 * V_41 = V_67 -> V_75 -> V_6 . V_41 ;
struct V_81 * V_6 ;
unsigned int V_69 ;
if ( ! V_67 -> V_107 )
V_67 -> V_107 = F_36 ( V_67 -> V_75 -> V_110 ) ;
F_19 (entity, &pipe->entities, list_pipe) {
if ( V_6 -> V_84 -> V_108 )
V_6 -> V_84 -> V_108 ( V_6 , V_67 , V_67 -> V_107 ,
V_111 ) ;
}
F_34 ( V_67 , V_67 -> V_107 , 0 ) ;
for ( V_69 = 1 ; V_69 < V_67 -> V_78 ; ++ V_69 ) {
struct V_106 * V_107 ;
V_107 = F_36 ( V_67 -> V_75 -> V_110 ) ;
if ( ! V_107 ) {
F_37 ( V_41 -> V_112 , L_1 ) ;
break;
}
F_34 ( V_67 , V_107 , V_69 ) ;
F_38 ( V_67 -> V_107 , V_107 ) ;
}
F_39 ( V_67 -> V_107 ) ;
V_67 -> V_107 = NULL ;
F_40 ( V_67 ) ;
}
static void F_41 ( struct V_66 * V_67 ,
bool V_113 )
{
struct V_80 * V_41 = V_67 -> V_75 -> V_6 . V_41 ;
enum V_114 V_115 ;
unsigned long V_92 ;
unsigned int V_39 ;
F_42 ( ! V_113 ) ;
F_23 ( & V_67 -> V_93 , V_92 ) ;
for ( V_39 = 0 ; V_39 < V_41 -> V_38 -> V_116 ; ++ V_39 ) {
if ( ! V_67 -> V_117 [ V_39 ] )
continue;
F_33 ( V_67 , V_67 -> V_117 [ V_39 ] ) ;
}
F_33 ( V_67 , V_67 -> V_75 ) ;
V_115 = V_67 -> V_115 ;
V_67 -> V_115 = V_118 ;
if ( V_115 == V_119 )
F_43 ( & V_67 -> V_120 ) ;
else if ( F_44 ( V_67 ) )
F_35 ( V_67 ) ;
F_25 ( & V_67 -> V_93 , V_92 ) ;
}
static int F_45 ( struct V_66 * V_67 ,
struct V_102 * V_121 ,
struct V_102 * V_75 )
{
struct V_122 V_123 ;
struct V_81 * V_6 ;
struct V_2 * V_4 ;
struct V_124 * V_125 = NULL ;
int V_13 ;
V_13 = F_46 ( & V_123 , & V_121 -> V_6 . V_41 -> V_126 ) ;
if ( V_13 < 0 )
return V_13 ;
V_4 = F_47 ( & V_121 -> V_6 . V_127 [ V_128 ] ) ;
while ( 1 ) {
if ( V_4 == NULL ) {
V_13 = - V_129 ;
goto V_130;
}
if ( ! F_3 ( V_4 -> V_6 ) ) {
V_13 = - V_129 ;
goto V_130;
}
V_6 = F_48 (
F_4 ( V_4 -> V_6 ) ) ;
if ( V_6 -> type == V_131 ||
V_6 -> type == V_132 ) {
if ( V_125 ) {
V_13 = - V_129 ;
goto V_130;
}
V_125 = F_49 ( & V_6 -> V_12 ) ;
V_125 -> V_117 [ V_4 -> V_7 ] . V_133 = V_121 ;
V_121 -> V_134 = V_4 -> V_7 ;
}
if ( V_6 -> type == V_135 )
break;
if ( F_50 ( & V_123 ,
& V_6 -> V_12 . V_6 ) ) {
V_13 = - V_129 ;
goto V_130;
}
if ( V_6 -> type == V_136 ) {
if ( V_67 -> V_137 ) {
V_13 = - V_129 ;
goto V_130;
}
V_67 -> V_137 = V_6 ;
V_67 -> V_138 = V_125 ? & V_125 -> V_6 : & V_121 -> V_6 ;
}
V_4 = & V_6 -> V_127 [ V_6 -> V_139 ] ;
V_4 = F_47 ( V_4 ) ;
}
if ( V_6 != & V_75 -> V_6 )
V_13 = - V_129 ;
V_130:
F_51 ( & V_123 ) ;
return V_13 ;
}
static int F_52 ( struct V_66 * V_67 ,
struct V_8 * V_9 )
{
struct V_140 V_141 ;
struct V_142 * V_6 = & V_9 -> V_9 . V_6 ;
struct V_143 * V_144 = V_6 -> V_145 . V_144 ;
unsigned int V_39 ;
int V_13 ;
V_13 = F_53 ( & V_141 , V_144 ) ;
if ( V_13 )
return V_13 ;
F_54 ( & V_141 , V_6 ) ;
while ( ( V_6 = F_55 ( & V_141 ) ) ) {
struct V_1 * V_12 ;
struct V_102 * V_19 ;
struct V_81 * V_146 ;
if ( ! F_3 ( V_6 ) )
continue;
V_12 = F_4 ( V_6 ) ;
V_146 = F_48 ( V_12 ) ;
F_56 ( & V_146 -> V_147 , & V_67 -> V_148 ) ;
switch ( V_146 -> type ) {
case V_149 :
V_19 = F_57 ( V_12 ) ;
V_67 -> V_117 [ V_19 -> V_6 . V_7 ] = V_19 ;
V_19 -> V_9 -> V_105 = ++ V_67 -> V_150 ;
V_19 -> V_67 = V_67 ;
break;
case V_135 :
V_19 = F_57 ( V_12 ) ;
V_67 -> V_75 = V_19 ;
V_19 -> V_9 -> V_105 = 0 ;
V_19 -> V_67 = V_67 ;
break;
case V_151 :
V_67 -> V_96 = V_146 ;
break;
case V_131 :
case V_132 :
V_67 -> V_125 = V_146 ;
break;
case V_152 :
V_67 -> V_153 = V_146 ;
F_58 ( V_12 ) -> V_154 . V_67 = V_67 ;
break;
case V_155 :
V_67 -> V_156 = V_146 ;
F_59 ( V_12 ) -> V_154 . V_67 = V_67 ;
break;
default:
break;
}
}
F_60 ( & V_141 ) ;
if ( V_67 -> V_150 == 0 || ! V_67 -> V_75 )
return - V_129 ;
for ( V_39 = 0 ; V_39 < V_9 -> V_41 -> V_38 -> V_116 ; ++ V_39 ) {
if ( ! V_67 -> V_117 [ V_39 ] )
continue;
V_13 = F_45 ( V_67 , V_67 -> V_117 [ V_39 ] ,
V_67 -> V_75 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static int F_61 ( struct V_66 * V_67 ,
struct V_8 * V_9 )
{
F_62 ( V_67 ) ;
V_67 -> V_157 = F_41 ;
return F_52 ( V_67 , V_9 ) ;
}
static struct V_66 * F_63 ( struct V_8 * V_9 )
{
struct V_66 * V_67 ;
int V_13 ;
if ( ! V_9 -> V_19 -> V_67 ) {
V_67 = F_64 ( sizeof( * V_67 ) , V_87 ) ;
if ( ! V_67 )
return F_65 ( - V_88 ) ;
V_13 = F_61 ( V_67 , V_9 ) ;
if ( V_13 < 0 ) {
F_66 ( V_67 ) ;
F_67 ( V_67 ) ;
return F_65 ( V_13 ) ;
}
} else {
V_67 = V_9 -> V_19 -> V_67 ;
F_68 ( & V_67 -> V_158 ) ;
}
return V_67 ;
}
static void F_69 ( struct V_158 * V_158 )
{
struct V_66 * V_67 = F_70 ( V_158 , F_71 ( * V_67 ) , V_158 ) ;
F_66 ( V_67 ) ;
F_67 ( V_67 ) ;
}
static void F_72 ( struct V_66 * V_67 )
{
struct V_143 * V_144 = & V_67 -> V_75 -> V_6 . V_41 -> V_126 ;
F_73 ( & V_144 -> V_159 ) ;
F_74 ( & V_67 -> V_158 , F_69 ) ;
F_75 ( & V_144 -> V_159 ) ;
}
static int
F_76 ( struct V_160 * V_161 ,
unsigned int * V_162 , unsigned int * V_163 ,
unsigned int V_164 [] , struct V_165 * V_166 [] )
{
struct V_8 * V_9 = F_77 ( V_161 ) ;
const struct V_26 * V_22 = & V_9 -> V_19 -> V_22 ;
unsigned int V_39 ;
if ( * V_163 ) {
if ( * V_163 != V_22 -> V_65 )
return - V_14 ;
for ( V_39 = 0 ; V_39 < * V_163 ; V_39 ++ )
if ( V_164 [ V_39 ] < V_22 -> V_62 [ V_39 ] . V_64 )
return - V_14 ;
return 0 ;
}
* V_163 = V_22 -> V_65 ;
for ( V_39 = 0 ; V_39 < V_22 -> V_65 ; ++ V_39 )
V_164 [ V_39 ] = V_22 -> V_62 [ V_39 ] . V_64 ;
return 0 ;
}
static int F_78 ( struct V_167 * V_168 )
{
struct V_169 * V_170 = F_79 ( V_168 ) ;
struct V_8 * V_9 = F_77 ( V_168 -> V_160 ) ;
struct V_89 * V_97 = F_80 ( V_170 ) ;
const struct V_26 * V_22 = & V_9 -> V_19 -> V_22 ;
unsigned int V_39 ;
if ( V_168 -> V_65 < V_22 -> V_65 )
return - V_14 ;
for ( V_39 = 0 ; V_39 < V_168 -> V_65 ; ++ V_39 ) {
V_97 -> V_103 . V_171 [ V_39 ] = F_81 ( V_168 , V_39 ) ;
if ( F_31 ( V_168 , V_39 ) < V_22 -> V_62 [ V_39 ] . V_64 )
return - V_14 ;
}
for ( ; V_39 < 3 ; ++ V_39 )
V_97 -> V_103 . V_171 [ V_39 ] = 0 ;
return 0 ;
}
static void F_82 ( struct V_167 * V_168 )
{
struct V_169 * V_170 = F_79 ( V_168 ) ;
struct V_8 * V_9 = F_77 ( V_168 -> V_160 ) ;
struct V_66 * V_67 = V_9 -> V_19 -> V_67 ;
struct V_89 * V_97 = F_80 ( V_170 ) ;
unsigned long V_92 ;
bool V_172 ;
F_23 ( & V_9 -> V_93 , V_92 ) ;
V_172 = F_24 ( & V_9 -> V_94 ) ;
F_56 ( & V_97 -> V_95 , & V_9 -> V_94 ) ;
F_25 ( & V_9 -> V_93 , V_92 ) ;
if ( ! V_172 )
return;
F_23 ( & V_67 -> V_93 , V_92 ) ;
V_9 -> V_19 -> V_103 = V_97 -> V_103 ;
V_67 -> V_104 |= 1 << V_9 -> V_105 ;
if ( F_83 ( & V_9 -> V_95 ) &&
F_44 ( V_67 ) )
F_35 ( V_67 ) ;
F_25 ( & V_67 -> V_93 , V_92 ) ;
}
static int F_84 ( struct V_66 * V_67 )
{
struct V_81 * V_6 ;
int V_13 ;
V_13 = F_18 ( V_67 ) ;
if ( V_13 < 0 )
return V_13 ;
V_67 -> V_107 = F_36 ( V_67 -> V_75 -> V_110 ) ;
if ( ! V_67 -> V_107 )
return - V_88 ;
if ( V_67 -> V_137 ) {
struct V_173 * V_137 = F_85 ( & V_67 -> V_137 -> V_12 ) ;
if ( V_67 -> V_138 -> type == V_131 ||
V_67 -> V_138 -> type == V_132 ) {
V_137 -> V_174 = false ;
} else {
struct V_102 * V_133 =
F_57 ( & V_67 -> V_138 -> V_12 ) ;
V_137 -> V_174 = V_133 -> V_20 -> V_175 ;
}
}
F_19 (entity, &pipe->entities, list_pipe) {
F_86 ( V_6 , V_67 , V_67 -> V_107 ) ;
if ( V_6 -> V_84 -> V_108 )
V_6 -> V_84 -> V_108 ( V_6 , V_67 , V_67 -> V_107 ,
V_176 ) ;
}
return 0 ;
}
static void F_87 ( struct V_66 * V_67 )
{
struct V_8 * V_9 = V_67 -> V_75 -> V_9 ;
struct V_89 * V_177 ;
unsigned long V_92 ;
F_23 ( & V_9 -> V_93 , V_92 ) ;
F_19 (buffer, &video->irqqueue, queue)
F_32 ( & V_177 -> V_97 . V_99 , V_178 ) ;
F_88 ( & V_9 -> V_94 ) ;
F_25 ( & V_9 -> V_93 , V_92 ) ;
F_73 ( & V_67 -> V_179 ) ;
F_67 ( V_67 -> V_86 ) ;
V_67 -> V_86 = NULL ;
F_75 ( & V_67 -> V_179 ) ;
}
static int F_89 ( struct V_160 * V_161 , unsigned int V_180 )
{
struct V_8 * V_9 = F_77 ( V_161 ) ;
struct V_66 * V_67 = V_9 -> V_19 -> V_67 ;
bool V_181 = false ;
unsigned long V_92 ;
int V_13 ;
F_73 ( & V_67 -> V_179 ) ;
if ( V_67 -> V_182 == V_67 -> V_150 ) {
V_13 = F_84 ( V_67 ) ;
if ( V_13 < 0 ) {
F_75 ( & V_67 -> V_179 ) ;
F_87 ( V_67 ) ;
return V_13 ;
}
V_181 = true ;
}
V_67 -> V_182 ++ ;
F_75 ( & V_67 -> V_179 ) ;
if ( ! V_181 )
return 0 ;
F_23 ( & V_67 -> V_93 , V_92 ) ;
if ( F_44 ( V_67 ) )
F_35 ( V_67 ) ;
F_25 ( & V_67 -> V_93 , V_92 ) ;
return 0 ;
}
static void F_90 ( struct V_160 * V_161 )
{
struct V_8 * V_9 = F_77 ( V_161 ) ;
struct V_66 * V_67 = V_9 -> V_19 -> V_67 ;
unsigned long V_92 ;
int V_13 ;
F_23 ( & V_9 -> V_93 , V_92 ) ;
V_67 -> V_104 &= ~ ( 1 << V_9 -> V_105 ) ;
F_25 ( & V_9 -> V_93 , V_92 ) ;
F_73 ( & V_67 -> V_179 ) ;
if ( -- V_67 -> V_182 == V_67 -> V_150 ) {
V_13 = F_91 ( V_67 ) ;
if ( V_13 == - V_183 )
F_37 ( V_9 -> V_41 -> V_112 , L_2 ) ;
F_92 ( V_67 -> V_107 ) ;
V_67 -> V_107 = NULL ;
}
F_75 ( & V_67 -> V_179 ) ;
F_93 ( & V_9 -> V_9 . V_6 ) ;
F_87 ( V_67 ) ;
F_72 ( V_67 ) ;
}
static int
F_94 ( struct V_184 * V_184 , void * V_185 , struct V_186 * V_187 )
{
struct V_188 * V_189 = V_184 -> V_190 ;
struct V_8 * V_9 = F_95 ( V_189 -> V_191 ) ;
V_187 -> V_192 = V_193 | V_194
| V_195
| V_196 ;
if ( V_9 -> type == V_197 )
V_187 -> V_198 = V_195
| V_194 ;
else
V_187 -> V_198 = V_196
| V_194 ;
F_96 ( V_187 -> V_199 , L_3 , sizeof( V_187 -> V_199 ) ) ;
F_96 ( V_187 -> V_200 , V_9 -> V_9 . V_201 , sizeof( V_187 -> V_200 ) ) ;
snprintf ( V_187 -> V_202 , sizeof( V_187 -> V_202 ) , L_4 ,
F_97 ( V_9 -> V_41 -> V_112 ) ) ;
return 0 ;
}
static int
F_98 ( struct V_184 * V_184 , void * V_185 , struct V_203 * V_22 )
{
struct V_188 * V_189 = V_184 -> V_190 ;
struct V_8 * V_9 = F_95 ( V_189 -> V_191 ) ;
if ( V_22 -> type != V_9 -> V_95 . type )
return - V_14 ;
F_73 ( & V_9 -> V_179 ) ;
V_22 -> V_11 . V_204 = V_9 -> V_19 -> V_22 ;
F_75 ( & V_9 -> V_179 ) ;
return 0 ;
}
static int
F_99 ( struct V_184 * V_184 , void * V_185 , struct V_203 * V_22 )
{
struct V_188 * V_189 = V_184 -> V_190 ;
struct V_8 * V_9 = F_95 ( V_189 -> V_191 ) ;
if ( V_22 -> type != V_9 -> V_95 . type )
return - V_14 ;
return F_7 ( V_9 , & V_22 -> V_11 . V_204 , NULL ) ;
}
static int
F_100 ( struct V_184 * V_184 , void * V_185 , struct V_203 * V_22 )
{
struct V_188 * V_189 = V_184 -> V_190 ;
struct V_8 * V_9 = F_95 ( V_189 -> V_191 ) ;
const struct V_28 * V_38 ;
int V_13 ;
if ( V_22 -> type != V_9 -> V_95 . type )
return - V_14 ;
V_13 = F_7 ( V_9 , & V_22 -> V_11 . V_204 , & V_38 ) ;
if ( V_13 < 0 )
return V_13 ;
F_73 ( & V_9 -> V_179 ) ;
if ( F_101 ( & V_9 -> V_95 ) ) {
V_13 = - V_205 ;
goto V_91;
}
V_9 -> V_19 -> V_22 = V_22 -> V_11 . V_204 ;
V_9 -> V_19 -> V_20 = V_38 ;
V_91:
F_75 ( & V_9 -> V_179 ) ;
return V_13 ;
}
static int
F_102 ( struct V_184 * V_184 , void * V_185 , enum V_206 type )
{
struct V_188 * V_189 = V_184 -> V_190 ;
struct V_8 * V_9 = F_95 ( V_189 -> V_191 ) ;
struct V_143 * V_144 = & V_9 -> V_41 -> V_126 ;
struct V_66 * V_67 ;
int V_13 ;
if ( V_9 -> V_95 . V_207 && V_9 -> V_95 . V_207 != V_184 -> V_190 )
return - V_205 ;
F_73 ( & V_144 -> V_159 ) ;
V_67 = F_63 ( V_9 ) ;
if ( F_103 ( V_67 ) ) {
F_75 ( & V_144 -> V_159 ) ;
return F_104 ( V_67 ) ;
}
V_13 = F_105 ( & V_9 -> V_9 . V_6 , & V_67 -> V_67 ) ;
if ( V_13 < 0 ) {
F_75 ( & V_144 -> V_159 ) ;
goto V_208;
}
F_75 ( & V_144 -> V_159 ) ;
V_13 = F_5 ( V_9 ) ;
if ( V_13 < 0 )
goto V_209;
V_13 = F_106 ( & V_9 -> V_95 , type ) ;
if ( V_13 < 0 )
goto V_209;
return 0 ;
V_209:
F_93 ( & V_9 -> V_9 . V_6 ) ;
V_208:
F_72 ( V_67 ) ;
return V_13 ;
}
static int F_107 ( struct V_184 * V_184 )
{
struct V_8 * V_9 = F_108 ( V_184 ) ;
struct V_188 * V_189 ;
int V_13 = 0 ;
V_189 = F_64 ( sizeof( * V_189 ) , V_87 ) ;
if ( V_189 == NULL )
return - V_88 ;
F_109 ( V_189 , & V_9 -> V_9 ) ;
F_110 ( V_189 ) ;
V_184 -> V_190 = V_189 ;
V_13 = F_111 ( V_9 -> V_41 ) ;
if ( V_13 < 0 ) {
F_112 ( V_189 ) ;
F_113 ( V_189 ) ;
F_67 ( V_189 ) ;
}
return V_13 ;
}
static int F_114 ( struct V_184 * V_184 )
{
struct V_8 * V_9 = F_108 ( V_184 ) ;
struct V_188 * V_189 = V_184 -> V_190 ;
F_73 ( & V_9 -> V_179 ) ;
if ( V_9 -> V_95 . V_207 == V_189 ) {
F_115 ( & V_9 -> V_95 ) ;
V_9 -> V_95 . V_207 = NULL ;
}
F_75 ( & V_9 -> V_179 ) ;
F_116 ( V_9 -> V_41 ) ;
F_117 ( V_184 ) ;
V_184 -> V_190 = NULL ;
return 0 ;
}
struct V_8 * F_118 ( struct V_80 * V_41 ,
struct V_102 * V_19 )
{
struct V_8 * V_9 ;
const char * V_210 ;
int V_13 ;
V_9 = F_119 ( V_41 -> V_112 , sizeof( * V_9 ) , V_87 ) ;
if ( ! V_9 )
return F_65 ( - V_88 ) ;
V_19 -> V_9 = V_9 ;
V_9 -> V_41 = V_41 ;
V_9 -> V_19 = V_19 ;
if ( V_19 -> V_6 . type == V_149 ) {
V_210 = L_5 ;
V_9 -> type = V_211 ;
V_9 -> V_4 . V_92 = V_212 ;
V_9 -> V_9 . V_213 = V_214 ;
} else {
V_210 = L_6 ;
V_9 -> type = V_197 ;
V_9 -> V_4 . V_92 = V_215 ;
V_9 -> V_9 . V_213 = V_216 ;
}
F_120 ( & V_9 -> V_179 ) ;
F_121 ( & V_9 -> V_93 ) ;
F_88 ( & V_9 -> V_94 ) ;
V_13 = F_122 ( & V_9 -> V_9 . V_6 , 1 , & V_9 -> V_4 ) ;
if ( V_13 < 0 )
return F_65 ( V_13 ) ;
V_19 -> V_22 . V_40 = V_42 ;
V_19 -> V_22 . V_25 = V_217 ;
V_19 -> V_22 . V_24 = V_218 ;
F_7 ( V_9 , & V_19 -> V_22 , & V_19 -> V_20 ) ;
V_9 -> V_9 . V_219 = & V_9 -> V_41 -> V_219 ;
V_9 -> V_9 . V_220 = & V_221 ;
snprintf ( V_9 -> V_9 . V_201 , sizeof( V_9 -> V_9 . V_201 ) , L_7 ,
V_19 -> V_6 . V_12 . V_201 , V_210 ) ;
V_9 -> V_9 . V_222 = V_223 ;
V_9 -> V_9 . V_224 = V_225 ;
V_9 -> V_9 . V_226 = & V_227 ;
F_123 ( & V_9 -> V_9 , V_9 ) ;
V_9 -> V_95 . type = V_9 -> type ;
V_9 -> V_95 . V_228 = V_229 | V_230 | V_231 ;
V_9 -> V_95 . V_179 = & V_9 -> V_179 ;
V_9 -> V_95 . V_232 = V_9 ;
V_9 -> V_95 . V_233 = sizeof( struct V_89 ) ;
V_9 -> V_95 . V_84 = & V_234 ;
V_9 -> V_95 . V_235 = & V_236 ;
V_9 -> V_95 . V_237 = V_238 ;
V_9 -> V_95 . V_112 = V_9 -> V_41 -> V_239 ;
V_13 = F_124 ( & V_9 -> V_95 ) ;
if ( V_13 < 0 ) {
F_37 ( V_9 -> V_41 -> V_112 , L_8 ) ;
goto error;
}
V_9 -> V_9 . V_95 = & V_9 -> V_95 ;
V_13 = F_125 ( & V_9 -> V_9 , V_223 , - 1 ) ;
if ( V_13 < 0 ) {
F_37 ( V_9 -> V_41 -> V_112 , L_9 ) ;
goto error;
}
return V_9 ;
error:
F_126 ( V_9 ) ;
return F_65 ( V_13 ) ;
}
void F_126 ( struct V_8 * V_9 )
{
if ( F_127 ( & V_9 -> V_9 ) )
F_128 ( & V_9 -> V_9 ) ;
F_129 ( & V_9 -> V_9 . V_6 ) ;
}
