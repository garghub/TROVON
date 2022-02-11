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
V_38 = F_9 ( V_27 -> V_40 ) ;
if ( V_38 == NULL )
V_38 = F_9 ( V_41 ) ;
V_27 -> V_40 = V_38 -> V_42 ;
V_27 -> V_43 = V_44 ;
V_27 -> V_45 = V_46 ;
memset ( V_27 -> V_47 , 0 , sizeof( V_27 -> V_47 ) ) ;
V_25 = F_10 ( V_25 , V_38 -> V_48 ) ;
V_24 = F_10 ( V_24 , V_38 -> V_49 ) ;
V_27 -> V_25 = F_11 ( V_25 , V_50 , V_51 ) ;
V_27 -> V_24 = F_11 ( V_24 , V_52 ,
V_53 ) ;
for ( V_39 = 0 ; V_39 < F_12 ( V_38 -> V_54 , 2U ) ; ++ V_39 ) {
unsigned int V_48 = V_39 > 0 ? V_38 -> V_48 : 1 ;
unsigned int V_49 = V_39 > 0 ? V_38 -> V_49 : 1 ;
unsigned int V_55 = 128 ;
unsigned int V_56 ;
V_56 = F_13 (unsigned int, pix->plane_fmt[i].bytesperline,
pix->width / hsub * info->bpp[i] / 8 ,
round_down(65535U, align)) ;
V_27 -> V_57 [ V_39 ] . V_58 = F_14 ( V_56 , V_55 ) ;
V_27 -> V_57 [ V_39 ] . V_59 = V_27 -> V_57 [ V_39 ] . V_58
* V_27 -> V_24 / V_49 ;
}
if ( V_38 -> V_54 == 3 ) {
V_27 -> V_57 [ 2 ] . V_58 = V_27 -> V_57 [ 1 ] . V_58 ;
V_27 -> V_57 [ 2 ] . V_59 = V_27 -> V_57 [ 1 ] . V_59 ;
}
V_27 -> V_60 = V_38 -> V_54 ;
if ( V_20 )
* V_20 = V_38 ;
return 0 ;
}
static int F_15 ( struct V_61 * V_62 ,
struct V_63 * V_64 ,
struct V_63 * V_65 )
{
struct V_66 * V_6 ;
struct V_67 V_68 ;
struct V_2 * V_4 ;
int V_69 ;
bool V_70 = false ;
V_64 -> V_71 . V_72 = 0 ;
V_64 -> V_71 . V_73 = 0 ;
V_69 = F_16 (
& V_68 , V_64 -> V_6 . V_74 [ V_75 ] . V_76 . V_77 ) ;
if ( V_69 )
return V_69 ;
V_4 = F_2 ( & V_64 -> V_6 . V_74 [ V_75 ] ) ;
while ( 1 ) {
if ( V_4 == NULL ) {
V_69 = - V_78 ;
goto V_79;
}
if ( ! F_3 ( V_4 -> V_6 ) ) {
V_69 = - V_78 ;
goto V_79;
}
V_6 = F_17 (
F_4 ( V_4 -> V_6 ) ) ;
if ( V_6 -> type == V_80 ) {
struct V_81 * V_82 = F_18 ( & V_6 -> V_12 ) ;
struct V_83 * V_84 =
& V_82 -> V_85 [ V_4 -> V_7 ] . V_86 ;
V_82 -> V_85 [ V_4 -> V_7 ] . V_87 = V_64 ;
V_64 -> V_71 . V_72 = V_84 -> V_72 ;
V_64 -> V_71 . V_73 = V_84 -> V_73 ;
V_70 = true ;
}
if ( V_6 -> type == V_88 )
break;
if ( F_19 ( & V_68 ,
& V_6 -> V_12 . V_6 ) ) {
V_69 = - V_78 ;
goto V_79;
}
if ( V_6 -> type == V_89 ) {
if ( V_62 -> V_90 ) {
V_69 = - V_78 ;
goto V_79;
}
V_62 -> V_90 = V_6 ;
V_62 -> V_91 = V_70 ? V_62 -> V_82
: & V_64 -> V_6 ;
}
V_4 = & V_6 -> V_74 [ V_6 -> V_92 ] ;
V_4 = F_2 ( V_4 ) ;
}
if ( V_6 != & V_65 -> V_6 )
V_69 = - V_78 ;
V_79:
F_20 ( & V_68 ) ;
return V_69 ;
}
static int F_21 ( struct V_61 * V_62 ,
struct V_8 * V_9 )
{
struct V_93 V_94 ;
struct V_95 * V_6 = & V_9 -> V_9 . V_6 ;
struct V_96 * V_77 = V_6 -> V_76 . V_77 ;
unsigned int V_39 ;
int V_13 ;
F_22 ( & V_77 -> V_97 ) ;
V_13 = F_23 ( & V_94 , V_77 ) ;
if ( V_13 ) {
F_24 ( & V_77 -> V_97 ) ;
return V_13 ;
}
F_25 ( & V_94 , V_6 ) ;
while ( ( V_6 = F_26 ( & V_94 ) ) ) {
struct V_1 * V_12 ;
struct V_63 * V_19 ;
struct V_66 * V_98 ;
if ( ! F_3 ( V_6 ) )
continue;
V_12 = F_4 ( V_6 ) ;
V_98 = F_17 ( V_12 ) ;
F_27 ( & V_98 -> V_99 , & V_62 -> V_100 ) ;
if ( V_98 -> type == V_101 ) {
V_19 = F_28 ( V_12 ) ;
V_62 -> V_85 [ V_19 -> V_6 . V_7 ] = V_19 ;
V_19 -> V_9 -> V_102 = ++ V_62 -> V_103 ;
} else if ( V_98 -> type == V_88 ) {
V_19 = F_28 ( V_12 ) ;
V_62 -> V_65 = V_19 ;
V_19 -> V_9 -> V_102 = 0 ;
} else if ( V_98 -> type == V_104 ) {
V_62 -> V_105 = V_98 ;
} else if ( V_98 -> type == V_80 ) {
V_62 -> V_82 = V_98 ;
}
}
F_24 ( & V_77 -> V_97 ) ;
F_29 ( & V_94 ) ;
if ( V_62 -> V_103 == 0 || ! V_62 -> V_65 ) {
V_13 = - V_78 ;
goto error;
}
for ( V_39 = 0 ; V_39 < V_9 -> V_106 -> V_38 -> V_107 ; ++ V_39 ) {
if ( ! V_62 -> V_85 [ V_39 ] )
continue;
V_13 = F_15 ( V_62 , V_62 -> V_85 [ V_39 ] ,
V_62 -> V_65 ) ;
if ( V_13 < 0 )
goto error;
}
return 0 ;
error:
F_30 ( V_62 ) ;
return V_13 ;
}
static int F_31 ( struct V_61 * V_62 ,
struct V_8 * V_9 )
{
int V_13 ;
F_22 ( & V_62 -> V_108 ) ;
if ( V_62 -> V_109 == 0 ) {
V_13 = F_21 ( V_62 , V_9 ) ;
if ( V_13 < 0 )
goto V_110;
}
V_62 -> V_109 ++ ;
V_13 = 0 ;
V_110:
F_24 ( & V_62 -> V_108 ) ;
return V_13 ;
}
static void F_32 ( struct V_61 * V_62 )
{
F_22 ( & V_62 -> V_108 ) ;
if ( -- V_62 -> V_109 == 0 )
F_30 ( V_62 ) ;
F_24 ( & V_62 -> V_108 ) ;
}
static struct V_111 *
F_33 ( struct V_8 * V_9 )
{
struct V_61 * V_62 = F_34 ( & V_9 -> V_9 . V_6 ) ;
struct V_111 * V_112 = NULL ;
struct V_111 * V_110 ;
unsigned long V_113 ;
unsigned int V_39 ;
F_35 ( & V_9 -> V_114 , V_113 ) ;
if ( F_36 ( & V_9 -> V_115 ) ) {
F_37 ( & V_9 -> V_114 , V_113 ) ;
return NULL ;
}
V_110 = F_38 ( & V_9 -> V_115 ,
struct V_111 , V_116 ) ;
if ( V_62 -> V_105 && F_39 ( & V_9 -> V_115 ) ) {
F_37 ( & V_9 -> V_114 , V_113 ) ;
return V_110 ;
}
F_40 ( & V_110 -> V_116 ) ;
if ( ! F_36 ( & V_9 -> V_115 ) )
V_112 = F_38 ( & V_9 -> V_115 ,
struct V_111 , V_116 ) ;
F_37 ( & V_9 -> V_114 , V_113 ) ;
V_110 -> V_117 . V_118 = V_9 -> V_118 ++ ;
V_110 -> V_117 . V_119 . V_120 = F_41 () ;
for ( V_39 = 0 ; V_39 < V_110 -> V_117 . V_119 . V_60 ; ++ V_39 )
F_42 ( & V_110 -> V_117 . V_119 , V_39 ,
V_110 -> V_121 . V_122 [ V_39 ] ) ;
F_43 ( & V_110 -> V_117 . V_119 , V_123 ) ;
return V_112 ;
}
static void F_44 ( struct V_61 * V_62 ,
struct V_63 * V_19 )
{
struct V_8 * V_9 = V_19 -> V_9 ;
struct V_111 * V_117 ;
unsigned long V_113 ;
V_117 = F_33 ( V_9 ) ;
if ( V_117 == NULL )
return;
F_35 ( & V_62 -> V_114 , V_113 ) ;
V_9 -> V_19 -> V_124 -> V_125 ( V_9 -> V_19 , & V_117 -> V_121 ) ;
V_62 -> V_126 |= 1 << V_9 -> V_102 ;
F_37 ( & V_62 -> V_114 , V_113 ) ;
}
static void F_45 ( struct V_61 * V_62 )
{
struct V_127 * V_106 = V_62 -> V_65 -> V_6 . V_106 ;
unsigned int V_39 ;
for ( V_39 = 0 ; V_39 < V_106 -> V_38 -> V_107 ; ++ V_39 ) {
if ( ! V_62 -> V_85 [ V_39 ] )
continue;
F_44 ( V_62 , V_62 -> V_85 [ V_39 ] ) ;
}
if ( ! V_62 -> V_105 )
F_44 ( V_62 , V_62 -> V_65 ) ;
}
static int
F_46 ( struct V_128 * V_129 ,
unsigned int * V_130 , unsigned int * V_131 ,
unsigned int V_132 [] , void * V_133 [] )
{
struct V_8 * V_9 = F_47 ( V_129 ) ;
const struct V_26 * V_22 = & V_9 -> V_19 -> V_22 ;
unsigned int V_39 ;
if ( * V_131 ) {
if ( * V_131 != V_22 -> V_60 )
return - V_14 ;
for ( V_39 = 0 ; V_39 < * V_131 ; V_39 ++ ) {
if ( V_132 [ V_39 ] < V_22 -> V_57 [ V_39 ] . V_59 )
return - V_14 ;
V_133 [ V_39 ] = V_9 -> V_134 ;
}
return 0 ;
}
* V_131 = V_22 -> V_60 ;
for ( V_39 = 0 ; V_39 < V_22 -> V_60 ; ++ V_39 ) {
V_132 [ V_39 ] = V_22 -> V_57 [ V_39 ] . V_59 ;
V_133 [ V_39 ] = V_9 -> V_134 ;
}
return 0 ;
}
static int F_48 ( struct V_135 * V_136 )
{
struct V_137 * V_138 = F_49 ( V_136 ) ;
struct V_8 * V_9 = F_47 ( V_136 -> V_128 ) ;
struct V_111 * V_117 = F_50 ( V_138 ) ;
const struct V_26 * V_22 = & V_9 -> V_19 -> V_22 ;
unsigned int V_39 ;
if ( V_136 -> V_60 < V_22 -> V_60 )
return - V_14 ;
V_117 -> V_121 . V_60 = V_136 -> V_60 ;
for ( V_39 = 0 ; V_39 < V_136 -> V_60 ; ++ V_39 ) {
V_117 -> V_121 . V_139 [ V_39 ] = F_51 ( V_136 , V_39 ) ;
V_117 -> V_121 . V_122 [ V_39 ] = F_52 ( V_136 , V_39 ) ;
if ( V_117 -> V_121 . V_122 [ V_39 ] < V_22 -> V_57 [ V_39 ] . V_59 )
return - V_14 ;
}
return 0 ;
}
static void F_53 ( struct V_135 * V_136 )
{
struct V_137 * V_138 = F_49 ( V_136 ) ;
struct V_8 * V_9 = F_47 ( V_136 -> V_128 ) ;
struct V_61 * V_62 = F_34 ( & V_9 -> V_9 . V_6 ) ;
struct V_111 * V_117 = F_50 ( V_138 ) ;
unsigned long V_113 ;
bool V_140 ;
F_35 ( & V_9 -> V_114 , V_113 ) ;
V_140 = F_36 ( & V_9 -> V_115 ) ;
F_27 ( & V_117 -> V_116 , & V_9 -> V_115 ) ;
F_37 ( & V_9 -> V_114 , V_113 ) ;
if ( ! V_140 )
return;
F_35 ( & V_62 -> V_114 , V_113 ) ;
V_9 -> V_19 -> V_124 -> V_125 ( V_9 -> V_19 , & V_117 -> V_121 ) ;
V_62 -> V_126 |= 1 << V_9 -> V_102 ;
if ( F_54 ( & V_9 -> V_116 ) &&
F_55 ( V_62 ) )
F_56 ( V_62 ) ;
F_37 ( & V_62 -> V_114 , V_113 ) ;
}
static int F_57 ( struct V_128 * V_129 , unsigned int V_141 )
{
struct V_8 * V_9 = F_47 ( V_129 ) ;
struct V_61 * V_62 = F_34 ( & V_9 -> V_9 . V_6 ) ;
struct V_66 * V_6 ;
unsigned long V_113 ;
int V_13 ;
F_22 ( & V_62 -> V_108 ) ;
if ( V_62 -> V_142 == V_62 -> V_103 ) {
if ( V_62 -> V_90 ) {
struct V_143 * V_90 = F_58 ( & V_62 -> V_90 -> V_12 ) ;
if ( V_62 -> V_91 -> type == V_80 ) {
V_90 -> V_144 = false ;
} else {
struct V_63 * V_87 =
F_28 ( & V_62 -> V_91 -> V_12 ) ;
V_90 -> V_144 = V_87 -> V_20 -> V_145 ;
}
}
F_59 (entity, &pipe->entities, list_pipe) {
F_60 ( V_6 ) ;
V_13 = F_6 ( & V_6 -> V_12 , V_9 ,
V_146 , 1 ) ;
if ( V_13 < 0 ) {
F_24 ( & V_62 -> V_108 ) ;
return V_13 ;
}
}
}
V_62 -> V_142 ++ ;
F_24 ( & V_62 -> V_108 ) ;
F_35 ( & V_62 -> V_114 , V_113 ) ;
if ( F_55 ( V_62 ) )
F_56 ( V_62 ) ;
F_37 ( & V_62 -> V_114 , V_113 ) ;
return 0 ;
}
static void F_61 ( struct V_128 * V_129 )
{
struct V_8 * V_9 = F_47 ( V_129 ) ;
struct V_61 * V_62 = F_34 ( & V_9 -> V_9 . V_6 ) ;
struct V_111 * V_147 ;
unsigned long V_113 ;
int V_13 ;
F_22 ( & V_62 -> V_108 ) ;
if ( -- V_62 -> V_142 == 0 ) {
V_13 = F_62 ( V_62 ) ;
if ( V_13 == - V_148 )
F_63 ( V_9 -> V_106 -> V_149 , L_1 ) ;
}
F_24 ( & V_62 -> V_108 ) ;
F_32 ( V_62 ) ;
F_64 ( & V_9 -> V_9 . V_6 ) ;
F_35 ( & V_9 -> V_114 , V_113 ) ;
F_59 (buffer, &video->irqqueue, queue)
F_43 ( & V_147 -> V_117 . V_119 , V_150 ) ;
F_65 ( & V_9 -> V_115 ) ;
F_37 ( & V_9 -> V_114 , V_113 ) ;
}
static int
F_66 ( struct V_151 * V_151 , void * V_152 , struct V_153 * V_154 )
{
struct V_155 * V_156 = V_151 -> V_157 ;
struct V_8 * V_9 = F_67 ( V_156 -> V_158 ) ;
V_154 -> V_159 = V_160 | V_161
| V_162
| V_163 ;
if ( V_9 -> type == V_164 )
V_154 -> V_165 = V_162
| V_161 ;
else
V_154 -> V_165 = V_163
| V_161 ;
F_68 ( V_154 -> V_166 , L_2 , sizeof( V_154 -> V_166 ) ) ;
F_68 ( V_154 -> V_167 , V_9 -> V_9 . V_168 , sizeof( V_154 -> V_167 ) ) ;
snprintf ( V_154 -> V_169 , sizeof( V_154 -> V_169 ) , L_3 ,
F_69 ( V_9 -> V_106 -> V_149 ) ) ;
return 0 ;
}
static int
F_70 ( struct V_151 * V_151 , void * V_152 , struct V_170 * V_22 )
{
struct V_155 * V_156 = V_151 -> V_157 ;
struct V_8 * V_9 = F_67 ( V_156 -> V_158 ) ;
if ( V_22 -> type != V_9 -> V_116 . type )
return - V_14 ;
F_22 ( & V_9 -> V_108 ) ;
V_22 -> V_11 . V_171 = V_9 -> V_19 -> V_22 ;
F_24 ( & V_9 -> V_108 ) ;
return 0 ;
}
static int
F_71 ( struct V_151 * V_151 , void * V_152 , struct V_170 * V_22 )
{
struct V_155 * V_156 = V_151 -> V_157 ;
struct V_8 * V_9 = F_67 ( V_156 -> V_158 ) ;
if ( V_22 -> type != V_9 -> V_116 . type )
return - V_14 ;
return F_7 ( V_9 , & V_22 -> V_11 . V_171 , NULL ) ;
}
static int
F_72 ( struct V_151 * V_151 , void * V_152 , struct V_170 * V_22 )
{
struct V_155 * V_156 = V_151 -> V_157 ;
struct V_8 * V_9 = F_67 ( V_156 -> V_158 ) ;
const struct V_28 * V_38 ;
int V_13 ;
if ( V_22 -> type != V_9 -> V_116 . type )
return - V_14 ;
V_13 = F_7 ( V_9 , & V_22 -> V_11 . V_171 , & V_38 ) ;
if ( V_13 < 0 )
return V_13 ;
F_22 ( & V_9 -> V_108 ) ;
if ( F_73 ( & V_9 -> V_116 ) ) {
V_13 = - V_172 ;
goto V_110;
}
V_9 -> V_19 -> V_22 = V_22 -> V_11 . V_171 ;
V_9 -> V_19 -> V_20 = V_38 ;
V_110:
F_24 ( & V_9 -> V_108 ) ;
return V_13 ;
}
static int
F_74 ( struct V_151 * V_151 , void * V_152 , enum V_173 type )
{
struct V_155 * V_156 = V_151 -> V_157 ;
struct V_8 * V_9 = F_67 ( V_156 -> V_158 ) ;
struct V_61 * V_62 ;
int V_13 ;
if ( V_9 -> V_116 . V_174 && V_9 -> V_116 . V_174 != V_151 -> V_157 )
return - V_172 ;
V_9 -> V_118 = 0 ;
V_62 = V_9 -> V_9 . V_6 . V_62
? F_34 ( & V_9 -> V_9 . V_6 ) : & V_9 -> V_62 ;
V_13 = F_75 ( & V_9 -> V_9 . V_6 , & V_62 -> V_62 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_5 ( V_9 ) ;
if ( V_13 < 0 )
goto V_175;
V_13 = F_31 ( V_62 , V_9 ) ;
if ( V_13 < 0 )
goto V_175;
V_13 = F_76 ( & V_9 -> V_116 , type ) ;
if ( V_13 < 0 )
goto V_176;
return 0 ;
V_176:
F_32 ( V_62 ) ;
V_175:
F_64 ( & V_9 -> V_9 . V_6 ) ;
return V_13 ;
}
static int F_77 ( struct V_151 * V_151 )
{
struct V_8 * V_9 = F_78 ( V_151 ) ;
struct V_155 * V_156 ;
int V_13 = 0 ;
V_156 = F_79 ( sizeof( * V_156 ) , V_177 ) ;
if ( V_156 == NULL )
return - V_178 ;
F_80 ( V_156 , & V_9 -> V_9 ) ;
F_81 ( V_156 ) ;
V_151 -> V_157 = V_156 ;
V_13 = F_82 ( V_9 -> V_106 ) ;
if ( V_13 < 0 ) {
F_83 ( V_156 ) ;
F_84 ( V_156 ) ;
}
return V_13 ;
}
static int F_85 ( struct V_151 * V_151 )
{
struct V_8 * V_9 = F_78 ( V_151 ) ;
struct V_155 * V_156 = V_151 -> V_157 ;
F_22 ( & V_9 -> V_108 ) ;
if ( V_9 -> V_116 . V_174 == V_156 ) {
F_86 ( & V_9 -> V_116 ) ;
V_9 -> V_116 . V_174 = NULL ;
}
F_24 ( & V_9 -> V_108 ) ;
F_87 ( V_9 -> V_106 ) ;
F_88 ( V_151 ) ;
V_151 -> V_157 = NULL ;
return 0 ;
}
struct V_8 * F_89 ( struct V_127 * V_106 ,
struct V_63 * V_19 )
{
struct V_8 * V_9 ;
const char * V_179 ;
int V_13 ;
V_9 = F_90 ( V_106 -> V_149 , sizeof( * V_9 ) , V_177 ) ;
if ( ! V_9 )
return F_91 ( - V_178 ) ;
V_19 -> V_9 = V_9 ;
V_9 -> V_106 = V_106 ;
V_9 -> V_19 = V_19 ;
if ( V_19 -> V_6 . type == V_101 ) {
V_179 = L_4 ;
V_9 -> type = V_180 ;
V_9 -> V_4 . V_113 = V_181 ;
V_9 -> V_9 . V_182 = V_183 ;
} else {
V_179 = L_5 ;
V_9 -> type = V_164 ;
V_9 -> V_4 . V_113 = V_184 ;
V_9 -> V_9 . V_182 = V_185 ;
}
F_92 ( & V_9 -> V_108 ) ;
F_93 ( & V_9 -> V_114 ) ;
F_65 ( & V_9 -> V_115 ) ;
F_94 ( & V_9 -> V_62 ) ;
V_9 -> V_62 . V_186 = F_45 ;
V_13 = F_95 ( & V_9 -> V_9 . V_6 , 1 , & V_9 -> V_4 ) ;
if ( V_13 < 0 )
return F_91 ( V_13 ) ;
V_19 -> V_20 = F_9 ( V_41 ) ;
V_19 -> V_22 . V_40 = V_19 -> V_20 -> V_42 ;
V_19 -> V_22 . V_43 = V_44 ;
V_19 -> V_22 . V_45 = V_46 ;
V_19 -> V_22 . V_25 = V_187 ;
V_19 -> V_22 . V_24 = V_188 ;
V_19 -> V_22 . V_60 = 1 ;
V_19 -> V_22 . V_57 [ 0 ] . V_58 =
V_19 -> V_22 . V_25 * V_19 -> V_20 -> V_189 [ 0 ] / 8 ;
V_19 -> V_22 . V_57 [ 0 ] . V_59 =
V_19 -> V_22 . V_57 [ 0 ] . V_58 * V_19 -> V_22 . V_24 ;
V_9 -> V_9 . V_190 = & V_9 -> V_106 -> V_190 ;
V_9 -> V_9 . V_191 = & V_192 ;
snprintf ( V_9 -> V_9 . V_168 , sizeof( V_9 -> V_9 . V_168 ) , L_6 ,
V_19 -> V_6 . V_12 . V_168 , V_179 ) ;
V_9 -> V_9 . V_193 = V_194 ;
V_9 -> V_9 . V_195 = V_196 ;
V_9 -> V_9 . V_197 = & V_198 ;
F_96 ( & V_9 -> V_9 , V_9 ) ;
V_9 -> V_134 = F_97 ( V_9 -> V_106 -> V_149 ) ;
if ( F_98 ( V_9 -> V_134 ) ) {
V_13 = F_99 ( V_9 -> V_134 ) ;
goto error;
}
V_9 -> V_116 . type = V_9 -> type ;
V_9 -> V_116 . V_199 = V_200 | V_201 | V_202 ;
V_9 -> V_116 . V_108 = & V_9 -> V_108 ;
V_9 -> V_116 . V_203 = V_9 ;
V_9 -> V_116 . V_204 = sizeof( struct V_111 ) ;
V_9 -> V_116 . V_124 = & V_205 ;
V_9 -> V_116 . V_206 = & V_207 ;
V_9 -> V_116 . V_208 = V_209 ;
V_13 = F_100 ( & V_9 -> V_116 ) ;
if ( V_13 < 0 ) {
F_63 ( V_9 -> V_106 -> V_149 , L_7 ) ;
goto error;
}
V_9 -> V_9 . V_116 = & V_9 -> V_116 ;
V_13 = F_101 ( & V_9 -> V_9 , V_194 , - 1 ) ;
if ( V_13 < 0 ) {
F_63 ( V_9 -> V_106 -> V_149 , L_8 ) ;
goto error;
}
return V_9 ;
error:
F_102 ( V_9 -> V_134 ) ;
F_103 ( V_9 ) ;
return F_91 ( V_13 ) ;
}
void F_103 ( struct V_8 * V_9 )
{
if ( F_104 ( & V_9 -> V_9 ) )
F_105 ( & V_9 -> V_9 ) ;
F_102 ( V_9 -> V_134 ) ;
F_106 ( & V_9 -> V_9 . V_6 ) ;
}
