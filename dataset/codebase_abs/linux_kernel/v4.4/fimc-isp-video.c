static int F_1 ( struct V_1 * V_2 ,
const void * V_3 ,
unsigned int * V_4 , unsigned int * V_5 ,
unsigned int V_6 [] , void * V_7 [] )
{
const struct V_8 * V_9 = V_3 ;
struct V_10 * V_11 = F_2 ( V_2 ) ;
struct V_12 * V_13 = & V_11 -> V_14 . V_15 ;
const struct V_12 * V_16 = NULL ;
const struct V_17 * V_18 ;
unsigned int V_19 , V_20 ;
if ( V_9 ) {
V_16 = & V_9 -> V_18 . V_21 ;
V_18 = F_3 ( & V_16 -> V_22 , NULL , - 1 ) ;
V_19 = V_16 -> V_23 * V_16 -> V_24 ;
} else {
V_18 = V_11 -> V_14 . V_25 ;
V_19 = V_13 -> V_23 * V_13 -> V_24 ;
}
if ( V_18 == NULL )
return - V_26 ;
* V_4 = F_4 ( V_27 , * V_4 , V_28 ,
V_29 ) ;
* V_5 = V_18 -> V_30 ;
for ( V_20 = 0 ; V_20 < V_18 -> V_30 ; V_20 ++ ) {
unsigned int V_31 = ( V_19 * V_18 -> V_32 [ V_20 ] ) / 8 ;
if ( V_16 )
V_6 [ V_20 ] = F_5 ( V_31 , V_16 -> V_33 [ V_20 ] . V_34 ) ;
else
V_6 [ V_20 ] = V_31 ;
V_7 [ V_20 ] = V_11 -> V_35 ;
}
return 0 ;
}
static inline struct V_36 * F_6 ( struct V_37 * V_38 )
{
return & F_7 ( V_38 ) -> V_11 . V_39 ;
}
static int F_8 ( struct V_1 * V_40 ,
unsigned int V_41 )
{
struct V_10 * V_11 = F_2 ( V_40 ) ;
struct V_37 * V_38 = F_9 ( V_11 ) ;
struct V_36 * V_42 = F_6 ( V_38 ) ;
struct V_43 * V_44 = & V_11 -> V_14 ;
int V_45 ;
if ( ! F_10 ( V_46 , & V_11 -> V_47 ) ||
F_10 ( V_48 , & V_11 -> V_47 ) )
return 0 ;
V_42 -> V_49 = V_50 ;
V_42 -> V_51 = V_52 ;
V_42 -> V_53 = V_38 -> V_54 +
V_55 ;
V_42 -> V_56 = V_44 -> V_57 ;
V_42 -> V_58 = V_44 -> V_59 ;
F_11 ( 2 , & V_44 -> V_60 . V_61 ,
L_1 ,
V_44 -> V_62 , V_44 -> V_25 -> V_30 ,
V_42 -> V_53 ) ;
F_12 () ;
F_13 ( V_38 , V_63 ) ;
F_14 ( V_38 , V_63 ) ;
V_45 = F_15 ( V_38 , false ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_16 ( & V_44 -> V_60 , V_64 , 1 ) ;
if ( V_45 < 0 )
return V_45 ;
F_17 ( V_48 , & V_11 -> V_47 ) ;
return V_45 ;
}
static void F_18 ( struct V_1 * V_40 )
{
struct V_10 * V_11 = F_2 ( V_40 ) ;
struct V_37 * V_38 = F_9 ( V_11 ) ;
struct V_36 * V_42 = F_6 ( V_38 ) ;
int V_45 ;
V_45 = F_16 ( & V_11 -> V_14 . V_60 , V_64 , 0 ) ;
if ( V_45 < 0 )
return;
V_42 -> V_49 = V_65 ;
V_42 -> V_51 = V_66 ;
V_42 -> V_56 = 0 ;
V_42 -> V_53 = 0 ;
V_42 -> V_58 = 0 ;
F_13 ( V_38 , V_63 ) ;
F_14 ( V_38 , V_63 ) ;
V_45 = F_15 ( V_38 , false ) ;
if ( V_45 < 0 )
F_19 ( & V_38 -> V_67 -> V_68 , L_2 , V_69 ) ;
F_20 ( V_38 , 0 ) ;
F_21 ( V_46 , & V_11 -> V_47 ) ;
F_21 ( V_48 , & V_11 -> V_47 ) ;
V_11 -> V_14 . V_62 = 0 ;
}
static int F_22 ( struct V_70 * V_71 )
{
struct V_10 * V_11 = F_2 ( V_71 -> V_1 ) ;
struct V_43 * V_44 = & V_11 -> V_14 ;
int V_20 ;
if ( V_44 -> V_25 == NULL )
return - V_26 ;
for ( V_20 = 0 ; V_20 < V_44 -> V_25 -> V_30 ; V_20 ++ ) {
unsigned long V_31 = V_44 -> V_15 . V_33 [ V_20 ] . V_34 ;
if ( F_23 ( V_71 , V_20 ) < V_31 ) {
F_24 ( & V_44 -> V_60 . V_61 ,
L_3 ,
F_23 ( V_71 , V_20 ) , V_31 ) ;
return - V_26 ;
}
F_25 ( V_71 , V_20 , V_31 ) ;
}
if ( F_10 ( V_46 , & V_11 -> V_47 ) ) {
T_1 V_72 = F_26 ( V_71 , 0 ) ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_44 -> V_62 ; V_20 ++ )
if ( V_44 -> V_73 [ V_20 ] -> V_72 [ 0 ] == V_72 )
return 0 ;
return - V_74 ;
}
return 0 ;
}
static void F_27 ( struct V_70 * V_71 )
{
struct V_75 * V_76 = F_28 ( V_71 ) ;
struct V_10 * V_11 = F_2 ( V_71 -> V_1 ) ;
struct V_43 * V_44 = & V_11 -> V_14 ;
struct V_37 * V_38 = F_9 ( V_11 ) ;
struct V_77 * V_78 = F_29 ( V_76 ) ;
unsigned long V_79 ;
unsigned int V_20 ;
if ( F_10 ( V_46 , & V_11 -> V_47 ) ) {
F_30 ( & V_38 -> V_80 , V_79 ) ;
V_44 -> V_59 |= F_31 ( V_78 -> V_81 ) ;
F_32 ( & V_38 -> V_80 , V_79 ) ;
} else {
unsigned int V_5 = V_44 -> V_25 -> V_30 ;
V_78 -> V_81 = V_44 -> V_62 ;
V_44 -> V_73 [ V_78 -> V_81 ] = V_78 ;
for ( V_20 = 0 ; V_20 < V_5 ; V_20 ++ ) {
int V_82 = V_78 -> V_81 * V_5 + V_20 ;
V_78 -> V_72 [ V_20 ] = F_26 ( V_71 , V_20 ) ;
V_38 -> V_83 -> V_84 [ 32 + V_82 ] =
V_78 -> V_72 [ V_20 ] ;
F_11 ( 2 , & V_44 -> V_60 . V_61 ,
L_4 ,
& V_82 , V_78 -> V_81 , V_20 , V_71 -> V_81 ,
& V_78 -> V_72 [ V_20 ] ) ;
}
if ( ++ V_44 -> V_62 < V_44 -> V_57 )
return;
V_44 -> V_59 = ( 1UL << V_44 -> V_62 ) - 1 ;
F_17 ( V_46 , & V_11 -> V_47 ) ;
}
if ( ! F_10 ( V_48 , & V_11 -> V_47 ) )
F_8 ( V_71 -> V_1 , 0 ) ;
}
void F_33 ( struct V_37 * V_38 )
{
struct V_43 * V_44 = & V_38 -> V_11 . V_14 ;
struct V_75 * V_76 ;
int V_82 ;
if ( ! F_10 ( V_48 , & V_38 -> V_11 . V_47 ) )
return;
V_82 = ( V_38 -> V_85 . args [ 1 ] - 1 ) % V_44 -> V_62 ;
V_76 = & V_44 -> V_73 [ V_82 ] -> V_71 ;
F_34 ( & V_76 -> V_86 ) ;
F_35 ( & V_76 -> V_87 , V_88 ) ;
V_44 -> V_59 &= ~ F_31 ( V_82 ) ;
F_20 ( V_38 , V_44 -> V_59 ) ;
}
static int F_36 ( struct V_89 * V_89 )
{
struct V_10 * V_11 = F_37 ( V_89 ) ;
struct V_90 * V_60 = & V_11 -> V_14 . V_60 ;
struct V_91 * V_92 = & V_60 -> V_61 . V_93 ;
int V_45 ;
if ( F_38 ( & V_11 -> V_94 ) )
return - V_95 ;
V_45 = F_39 ( V_89 ) ;
if ( V_45 < 0 )
goto V_96;
V_45 = F_40 ( & V_11 -> V_67 -> V_68 ) ;
if ( V_45 < 0 )
goto V_97;
if ( F_41 ( V_89 ) ) {
F_42 ( & V_92 -> V_98 -> V_99 ) ;
V_45 = F_16 ( V_60 , V_100 , V_92 , true ) ;
if ( V_45 == 0 )
V_92 -> V_101 ++ ;
F_43 ( & V_92 -> V_98 -> V_99 ) ;
}
if ( ! V_45 )
goto V_96;
V_97:
F_44 ( V_89 ) ;
V_96:
F_43 ( & V_11 -> V_94 ) ;
return V_45 ;
}
static int F_45 ( struct V_89 * V_89 )
{
struct V_10 * V_11 = F_37 ( V_89 ) ;
struct V_43 * V_102 = & V_11 -> V_14 ;
struct V_91 * V_93 = & V_102 -> V_60 . V_61 . V_93 ;
struct V_103 * V_104 = V_93 -> V_98 ;
F_42 ( & V_11 -> V_94 ) ;
if ( F_41 ( V_89 ) && V_102 -> V_105 ) {
F_46 ( V_93 ) ;
V_102 -> V_105 = 0 ;
}
F_47 ( V_89 ) ;
if ( F_41 ( V_89 ) ) {
F_16 ( & V_102 -> V_60 , V_106 ) ;
F_42 ( & V_104 -> V_99 ) ;
V_93 -> V_101 -- ;
F_43 ( & V_104 -> V_99 ) ;
}
F_48 ( & V_11 -> V_67 -> V_68 ) ;
F_43 ( & V_11 -> V_94 ) ;
return 0 ;
}
static int F_49 ( struct V_89 * V_89 , void * V_107 ,
struct V_108 * V_109 )
{
struct V_10 * V_11 = F_37 ( V_89 ) ;
F_50 ( & V_11 -> V_67 -> V_68 , V_109 , V_110 ) ;
return 0 ;
}
static int F_51 ( struct V_89 * V_89 , void * V_107 ,
struct V_111 * V_112 )
{
const struct V_17 * V_18 ;
if ( V_112 -> V_81 >= V_113 )
return - V_26 ;
V_18 = F_3 ( NULL , NULL , V_112 -> V_81 ) ;
if ( F_52 ( V_18 == NULL ) )
return - V_26 ;
F_53 ( V_112 -> V_114 , V_18 -> V_115 , sizeof( V_112 -> V_114 ) ) ;
V_112 -> V_22 = V_18 -> V_116 ;
return 0 ;
}
static int F_54 ( struct V_89 * V_89 , void * V_117 ,
struct V_8 * V_112 )
{
struct V_10 * V_11 = F_37 ( V_89 ) ;
V_112 -> V_18 . V_21 = V_11 -> V_14 . V_15 ;
return 0 ;
}
static void F_55 ( struct V_10 * V_11 ,
struct V_12 * V_16 ,
const struct V_17 * * V_18 )
{
* V_18 = F_3 ( & V_16 -> V_22 , NULL , 2 ) ;
V_16 -> V_118 = V_119 ;
V_16 -> V_120 = V_121 ;
V_16 -> V_5 = ( * V_18 ) -> V_30 ;
V_16 -> V_22 = ( * V_18 ) -> V_116 ;
F_56 ( & V_16 -> V_23 , V_122 ,
V_123 , 3 ,
& V_16 -> V_24 , V_124 ,
V_125 , 0 , 0 ) ;
}
static int F_57 ( struct V_89 * V_89 , void * V_117 ,
struct V_8 * V_112 )
{
struct V_10 * V_11 = F_37 ( V_89 ) ;
F_55 ( V_11 , & V_112 -> V_18 . V_21 , NULL ) ;
return 0 ;
}
static int F_58 ( struct V_89 * V_89 , void * V_107 ,
struct V_8 * V_112 )
{
struct V_10 * V_11 = F_37 ( V_89 ) ;
struct V_37 * V_38 = F_9 ( V_11 ) ;
struct V_12 * V_16 = & V_112 -> V_18 . V_21 ;
const struct V_17 * V_126 = NULL ;
struct V_36 * V_42 = F_6 ( V_38 ) ;
F_55 ( V_11 , V_16 , & V_126 ) ;
if ( F_52 ( V_126 == NULL ) )
return - V_26 ;
V_42 -> V_25 = V_127 ;
V_42 -> V_128 = V_129 ;
V_42 -> V_130 = V_126 -> V_30 ;
V_42 -> V_131 = V_126 -> V_32 [ 0 ] ;
V_42 -> V_23 = V_16 -> V_23 ;
V_42 -> V_24 = V_16 -> V_24 ;
F_12 () ;
V_11 -> V_14 . V_25 = V_126 ;
V_11 -> V_14 . V_15 = * V_16 ;
return 0 ;
}
static int F_59 ( struct V_10 * V_11 )
{
struct V_132 * V_133 = & V_11 -> V_134 ;
struct V_135 V_136 , V_137 ;
struct V_138 * V_139 ;
int V_45 ;
while ( 1 ) {
V_139 = & V_133 -> V_93 . V_140 [ 0 ] ;
if ( ! ( V_139 -> V_79 & V_141 ) )
break;
V_136 . V_139 = V_139 -> V_81 ;
V_136 . V_142 = V_143 ;
V_45 = F_60 ( V_133 , V_139 , V_144 , NULL , & V_136 ) ;
if ( V_45 < 0 && V_45 != - V_145 )
return - V_146 ;
V_139 = F_61 ( V_139 ) ;
if ( V_139 == NULL ||
F_62 ( V_139 -> V_93 ) != V_147 )
break;
V_133 = F_63 ( V_139 -> V_93 ) ;
V_137 . V_139 = V_139 -> V_81 ;
V_137 . V_142 = V_143 ;
V_45 = F_60 ( V_133 , V_139 , V_144 , NULL , & V_137 ) ;
if ( V_45 < 0 && V_45 != - V_145 )
return - V_146 ;
if ( V_137 . V_25 . V_23 != V_136 . V_25 . V_23 ||
V_137 . V_25 . V_24 != V_136 . V_25 . V_24 ||
V_137 . V_25 . V_148 != V_136 . V_25 . V_148 )
return - V_146 ;
}
return 0 ;
}
static int F_64 ( struct V_89 * V_89 , void * V_107 ,
enum V_149 type )
{
struct V_10 * V_11 = F_37 ( V_89 ) ;
struct V_90 * V_60 = & V_11 -> V_14 . V_60 ;
struct V_91 * V_92 = & V_60 -> V_61 . V_93 ;
int V_45 ;
V_45 = F_65 ( V_92 , & V_60 -> V_150 -> V_151 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_59 ( V_11 ) ;
if ( V_45 < 0 )
goto V_152;
V_45 = F_66 ( V_89 , V_107 , type ) ;
if ( V_45 < 0 )
goto V_152;
V_11 -> V_14 . V_105 = 1 ;
return 0 ;
V_152:
F_46 ( V_92 ) ;
return V_45 ;
}
static int F_67 ( struct V_89 * V_89 , void * V_107 ,
enum V_149 type )
{
struct V_10 * V_11 = F_37 ( V_89 ) ;
struct V_43 * V_44 = & V_11 -> V_14 ;
int V_45 ;
V_45 = F_68 ( V_89 , V_107 , type ) ;
if ( V_45 < 0 )
return V_45 ;
F_46 ( & V_44 -> V_60 . V_61 . V_93 ) ;
V_44 -> V_105 = 0 ;
return 0 ;
}
static int F_69 ( struct V_89 * V_89 , void * V_107 ,
struct V_153 * V_154 )
{
struct V_10 * V_11 = F_37 ( V_89 ) ;
int V_45 ;
V_45 = F_70 ( V_89 , V_107 , V_154 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_154 -> V_41 && V_154 -> V_41 < V_28 ) {
V_154 -> V_41 = 0 ;
F_70 ( V_89 , V_107 , V_154 ) ;
V_45 = - V_155 ;
}
V_11 -> V_14 . V_57 = V_154 -> V_41 ;
return V_45 ;
}
int F_71 ( struct V_10 * V_11 ,
struct V_156 * V_157 ,
enum V_149 type )
{
struct V_1 * V_40 = & V_11 -> V_14 . V_158 ;
struct V_43 * V_159 ;
struct V_160 * V_61 ;
int V_45 ;
if ( type == V_161 )
V_159 = & V_11 -> V_14 ;
else
return - V_162 ;
F_72 ( & V_11 -> V_94 ) ;
F_73 ( & V_159 -> V_163 ) ;
F_73 ( & V_159 -> V_164 ) ;
V_159 -> V_25 = F_3 ( NULL , NULL , 0 ) ;
V_159 -> V_15 . V_23 = V_165 ;
V_159 -> V_15 . V_24 = V_166 ;
V_159 -> V_15 . V_22 = V_159 -> V_25 -> V_116 ;
V_159 -> V_15 . V_118 = V_119 ;
V_159 -> V_57 = 0 ;
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
V_40 -> type = type ;
V_40 -> V_167 = V_168 | V_169 ;
V_40 -> V_170 = & V_171 ;
V_40 -> V_172 = & V_173 ;
V_40 -> V_174 = sizeof( struct V_77 ) ;
V_40 -> V_175 = V_11 ;
V_40 -> V_176 = V_177 ;
V_40 -> V_178 = & V_11 -> V_94 ;
V_45 = F_74 ( V_40 ) ;
if ( V_45 < 0 )
return V_45 ;
V_61 = & V_159 -> V_60 . V_61 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
snprintf ( V_61 -> V_115 , sizeof( V_61 -> V_115 ) , L_5 ,
type == V_161 ?
L_6 : L_7 ) ;
V_61 -> V_179 = V_40 ;
V_61 -> V_180 = & V_181 ;
V_61 -> V_182 = & V_183 ;
V_61 -> V_157 = V_157 ;
V_61 -> V_184 = - 1 ;
V_61 -> V_185 = V_186 ;
V_61 -> V_178 = & V_11 -> V_94 ;
V_159 -> V_139 . V_79 = V_141 ;
V_45 = F_75 ( & V_61 -> V_93 , 1 , & V_159 -> V_139 , 0 ) ;
if ( V_45 < 0 )
return V_45 ;
F_76 ( V_61 , V_11 ) ;
V_45 = F_77 ( V_61 , V_187 , - 1 ) ;
if ( V_45 < 0 ) {
F_78 ( & V_61 -> V_93 ) ;
return V_45 ;
}
F_79 ( V_157 , L_8 ,
V_61 -> V_115 , F_80 ( V_61 ) ) ;
return 0 ;
}
void F_81 ( struct V_10 * V_11 ,
enum V_149 type )
{
struct V_90 * V_60 ;
if ( type == V_161 )
V_60 = & V_11 -> V_14 . V_60 ;
else
return;
F_42 ( & V_11 -> V_94 ) ;
if ( F_82 ( & V_60 -> V_61 ) ) {
F_83 ( & V_60 -> V_61 ) ;
F_78 ( & V_60 -> V_61 . V_93 ) ;
V_60 -> V_150 = NULL ;
}
F_43 ( & V_11 -> V_94 ) ;
}
