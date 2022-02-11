static int F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int * V_4 ,
unsigned int V_5 [] , struct V_6 * V_7 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = & V_9 -> V_12 . V_13 ;
const struct V_14 * V_15 = V_9 -> V_12 . V_16 ;
unsigned int V_17 , V_18 ;
V_17 = V_11 -> V_19 * V_11 -> V_20 ;
if ( V_15 == NULL )
return - V_21 ;
* V_3 = F_3 ( V_22 , * V_3 , V_23 ,
V_24 ) ;
if ( * V_4 ) {
if ( * V_4 != V_15 -> V_25 )
return - V_21 ;
for ( V_18 = 0 ; V_18 < * V_4 ; V_18 ++ )
if ( V_5 [ V_18 ] < ( V_17 * V_15 -> V_26 [ V_18 ] ) / 8 )
return - V_21 ;
return 0 ;
}
* V_4 = V_15 -> V_25 ;
for ( V_18 = 0 ; V_18 < V_15 -> V_25 ; V_18 ++ )
V_5 [ V_18 ] = ( V_17 * V_15 -> V_26 [ V_18 ] ) / 8 ;
return 0 ;
}
static inline struct V_27 * F_4 ( struct V_28 * V_29 )
{
return & F_5 ( V_29 ) -> V_9 . V_30 ;
}
static int F_6 ( struct V_1 * V_31 ,
unsigned int V_32 )
{
struct V_8 * V_9 = F_2 ( V_31 ) ;
struct V_28 * V_29 = F_7 ( V_9 ) ;
struct V_27 * V_33 = F_4 ( V_29 ) ;
struct V_34 * V_35 = & V_9 -> V_12 ;
int V_36 ;
if ( ! F_8 ( V_37 , & V_9 -> V_38 ) ||
F_8 ( V_39 , & V_9 -> V_38 ) )
return 0 ;
V_33 -> V_40 = V_41 ;
V_33 -> V_42 = V_43 ;
V_33 -> V_44 = V_29 -> V_45 +
V_46 ;
V_33 -> V_47 = V_35 -> V_48 ;
V_33 -> V_49 = V_35 -> V_50 ;
F_9 ( 2 , & V_35 -> V_51 . V_52 ,
L_1 ,
V_35 -> V_53 , V_35 -> V_16 -> V_25 ,
V_33 -> V_44 ) ;
F_10 () ;
F_11 ( V_29 , V_54 ) ;
F_12 ( V_29 , V_54 ) ;
V_36 = F_13 ( V_29 , false ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_14 ( & V_35 -> V_51 , V_55 , 1 ) ;
if ( V_36 < 0 )
return V_36 ;
F_15 ( V_39 , & V_9 -> V_38 ) ;
return V_36 ;
}
static void F_16 ( struct V_1 * V_31 )
{
struct V_8 * V_9 = F_2 ( V_31 ) ;
struct V_28 * V_29 = F_7 ( V_9 ) ;
struct V_27 * V_33 = F_4 ( V_29 ) ;
int V_36 ;
V_36 = F_14 ( & V_9 -> V_12 . V_51 , V_55 , 0 ) ;
if ( V_36 < 0 )
return;
V_33 -> V_40 = V_56 ;
V_33 -> V_42 = V_57 ;
V_33 -> V_47 = 0 ;
V_33 -> V_44 = 0 ;
V_33 -> V_49 = 0 ;
F_11 ( V_29 , V_54 ) ;
F_12 ( V_29 , V_54 ) ;
V_36 = F_13 ( V_29 , false ) ;
if ( V_36 < 0 )
F_17 ( & V_29 -> V_58 -> V_59 , L_2 , V_60 ) ;
F_18 ( V_29 , 0 ) ;
F_19 ( V_37 , & V_9 -> V_38 ) ;
F_19 ( V_39 , & V_9 -> V_38 ) ;
V_9 -> V_12 . V_53 = 0 ;
}
static int F_20 ( struct V_61 * V_62 )
{
struct V_8 * V_9 = F_2 ( V_62 -> V_1 ) ;
struct V_34 * V_35 = & V_9 -> V_12 ;
int V_18 ;
if ( V_35 -> V_16 == NULL )
return - V_21 ;
for ( V_18 = 0 ; V_18 < V_35 -> V_16 -> V_25 ; V_18 ++ ) {
unsigned long V_63 = V_35 -> V_13 . V_64 [ V_18 ] . V_65 ;
if ( F_21 ( V_62 , V_18 ) < V_63 ) {
F_22 ( & V_35 -> V_51 . V_52 ,
L_3 ,
F_21 ( V_62 , V_18 ) , V_63 ) ;
return - V_21 ;
}
F_23 ( V_62 , V_18 , V_63 ) ;
}
if ( F_8 ( V_37 , & V_9 -> V_38 ) ) {
T_1 V_66 = F_24 ( V_62 , 0 ) ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_35 -> V_53 ; V_18 ++ )
if ( V_35 -> V_67 [ V_18 ] -> V_66 [ 0 ] == V_66 )
return 0 ;
return - V_68 ;
}
return 0 ;
}
static void F_25 ( struct V_61 * V_62 )
{
struct V_69 * V_70 = F_26 ( V_62 ) ;
struct V_8 * V_9 = F_2 ( V_62 -> V_1 ) ;
struct V_34 * V_35 = & V_9 -> V_12 ;
struct V_28 * V_29 = F_7 ( V_9 ) ;
struct V_71 * V_72 = F_27 ( V_70 ) ;
unsigned long V_73 ;
unsigned int V_18 ;
if ( F_8 ( V_37 , & V_9 -> V_38 ) ) {
F_28 ( & V_29 -> V_74 , V_73 ) ;
V_35 -> V_50 |= F_29 ( V_72 -> V_75 ) ;
F_30 ( & V_29 -> V_74 , V_73 ) ;
} else {
unsigned int V_4 = V_35 -> V_16 -> V_25 ;
V_72 -> V_75 = V_35 -> V_53 ;
V_35 -> V_67 [ V_72 -> V_75 ] = V_72 ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
int V_76 = V_72 -> V_75 * V_4 + V_18 ;
V_72 -> V_66 [ V_18 ] = F_24 ( V_62 , V_18 ) ;
V_29 -> V_77 -> V_78 [ 32 + V_76 ] =
V_72 -> V_66 [ V_18 ] ;
F_9 ( 2 , & V_35 -> V_51 . V_52 ,
L_4 ,
V_76 , V_72 -> V_75 , V_18 , V_62 -> V_75 ,
& V_72 -> V_66 [ V_18 ] ) ;
}
if ( ++ V_35 -> V_53 < V_35 -> V_48 )
return;
V_35 -> V_50 = ( 1UL << V_35 -> V_53 ) - 1 ;
F_15 ( V_37 , & V_9 -> V_38 ) ;
}
if ( ! F_8 ( V_39 , & V_9 -> V_38 ) )
F_6 ( V_62 -> V_1 , 0 ) ;
}
void F_31 ( struct V_28 * V_29 )
{
struct V_34 * V_35 = & V_29 -> V_9 . V_12 ;
struct V_69 * V_70 ;
int V_76 ;
if ( ! F_8 ( V_39 , & V_29 -> V_9 . V_38 ) )
return;
V_76 = ( V_29 -> V_79 . args [ 1 ] - 1 ) % V_35 -> V_53 ;
V_70 = & V_35 -> V_67 [ V_76 ] -> V_62 ;
V_70 -> V_80 . V_81 = F_32 () ;
F_33 ( & V_70 -> V_80 , V_82 ) ;
V_35 -> V_50 &= ~ F_29 ( V_76 ) ;
F_18 ( V_29 , V_35 -> V_50 ) ;
}
static int F_34 ( struct V_83 * V_83 )
{
struct V_8 * V_9 = F_35 ( V_83 ) ;
struct V_84 * V_51 = & V_9 -> V_12 . V_51 ;
struct V_85 * V_86 = & V_51 -> V_52 . V_87 ;
int V_36 ;
if ( F_36 ( & V_9 -> V_88 ) )
return - V_89 ;
V_36 = F_37 ( V_83 ) ;
if ( V_36 < 0 )
goto V_90;
V_36 = F_38 ( & V_9 -> V_58 -> V_59 ) ;
if ( V_36 < 0 )
goto V_91;
if ( F_39 ( V_83 ) ) {
F_40 ( & V_86 -> V_92 . V_93 -> V_94 ) ;
V_36 = F_14 ( V_51 , V_95 , V_86 , true ) ;
if ( V_36 == 0 )
V_86 -> V_96 ++ ;
F_41 ( & V_86 -> V_92 . V_93 -> V_94 ) ;
}
if ( ! V_36 )
goto V_90;
V_91:
F_42 ( V_83 ) ;
V_90:
F_41 ( & V_9 -> V_88 ) ;
return V_36 ;
}
static int F_43 ( struct V_83 * V_83 )
{
struct V_8 * V_9 = F_35 ( V_83 ) ;
struct V_34 * V_97 = & V_9 -> V_12 ;
struct V_85 * V_87 = & V_97 -> V_51 . V_52 . V_87 ;
struct V_98 * V_93 = V_87 -> V_92 . V_93 ;
F_40 ( & V_9 -> V_88 ) ;
if ( F_39 ( V_83 ) && V_97 -> V_99 ) {
F_44 ( V_87 ) ;
V_97 -> V_99 = 0 ;
}
F_45 ( V_83 ) ;
if ( F_39 ( V_83 ) ) {
F_14 ( & V_97 -> V_51 , V_100 ) ;
F_40 ( & V_93 -> V_94 ) ;
V_87 -> V_96 -- ;
F_41 ( & V_93 -> V_94 ) ;
}
F_46 ( & V_9 -> V_58 -> V_59 ) ;
F_41 ( & V_9 -> V_88 ) ;
return 0 ;
}
static int F_47 ( struct V_83 * V_83 , void * V_101 ,
struct V_102 * V_103 )
{
struct V_8 * V_9 = F_35 ( V_83 ) ;
F_48 ( & V_9 -> V_58 -> V_59 , V_103 , V_104 ) ;
return 0 ;
}
static int F_49 ( struct V_83 * V_83 , void * V_101 ,
struct V_105 * V_106 )
{
const struct V_14 * V_15 ;
if ( V_106 -> V_75 >= V_107 )
return - V_21 ;
V_15 = F_50 ( NULL , NULL , V_106 -> V_75 ) ;
if ( F_51 ( V_15 == NULL ) )
return - V_21 ;
F_52 ( V_106 -> V_108 , V_15 -> V_109 , sizeof( V_106 -> V_108 ) ) ;
V_106 -> V_110 = V_15 -> V_111 ;
return 0 ;
}
static int F_53 ( struct V_83 * V_83 , void * V_112 ,
struct V_113 * V_106 )
{
struct V_8 * V_9 = F_35 ( V_83 ) ;
V_106 -> V_15 . V_114 = V_9 -> V_12 . V_13 ;
return 0 ;
}
static void F_54 ( struct V_8 * V_9 ,
struct V_10 * V_115 ,
const struct V_14 * * V_15 )
{
* V_15 = F_50 ( & V_115 -> V_110 , NULL , 2 ) ;
V_115 -> V_116 = V_117 ;
V_115 -> V_118 = V_119 ;
V_115 -> V_4 = ( * V_15 ) -> V_25 ;
V_115 -> V_110 = ( * V_15 ) -> V_111 ;
F_55 ( & V_115 -> V_19 , V_120 ,
V_121 , 3 ,
& V_115 -> V_20 , V_122 ,
V_123 , 0 , 0 ) ;
}
static int F_56 ( struct V_83 * V_83 , void * V_112 ,
struct V_113 * V_106 )
{
struct V_8 * V_9 = F_35 ( V_83 ) ;
F_54 ( V_9 , & V_106 -> V_15 . V_114 , NULL ) ;
return 0 ;
}
static int F_57 ( struct V_83 * V_83 , void * V_101 ,
struct V_113 * V_106 )
{
struct V_8 * V_9 = F_35 ( V_83 ) ;
struct V_28 * V_29 = F_7 ( V_9 ) ;
struct V_10 * V_115 = & V_106 -> V_15 . V_114 ;
const struct V_14 * V_124 = NULL ;
struct V_27 * V_33 = F_4 ( V_29 ) ;
F_54 ( V_9 , V_115 , & V_124 ) ;
if ( F_51 ( V_124 == NULL ) )
return - V_21 ;
V_33 -> V_16 = V_125 ;
V_33 -> V_126 = V_127 ;
V_33 -> V_128 = V_124 -> V_25 ;
V_33 -> V_129 = V_124 -> V_26 [ 0 ] ;
V_33 -> V_19 = V_115 -> V_19 ;
V_33 -> V_20 = V_115 -> V_20 ;
F_10 () ;
V_9 -> V_12 . V_16 = V_124 ;
V_9 -> V_12 . V_13 = * V_115 ;
return 0 ;
}
static int F_58 ( struct V_8 * V_9 )
{
struct V_130 * V_131 = & V_9 -> V_132 ;
struct V_133 V_134 , V_135 ;
struct V_136 * V_137 ;
int V_36 ;
while ( 1 ) {
V_137 = & V_131 -> V_87 . V_138 [ 0 ] ;
if ( ! ( V_137 -> V_73 & V_139 ) )
break;
V_134 . V_137 = V_137 -> V_75 ;
V_134 . V_140 = V_141 ;
V_36 = F_59 ( V_131 , V_137 , V_142 , NULL , & V_134 ) ;
if ( V_36 < 0 && V_36 != - V_143 )
return - V_144 ;
V_137 = F_60 ( V_137 ) ;
if ( ! V_137 || ! F_61 ( V_137 -> V_87 ) )
break;
V_131 = F_62 ( V_137 -> V_87 ) ;
V_135 . V_137 = V_137 -> V_75 ;
V_135 . V_140 = V_141 ;
V_36 = F_59 ( V_131 , V_137 , V_142 , NULL , & V_135 ) ;
if ( V_36 < 0 && V_36 != - V_143 )
return - V_144 ;
if ( V_135 . V_16 . V_19 != V_134 . V_16 . V_19 ||
V_135 . V_16 . V_20 != V_134 . V_16 . V_20 ||
V_135 . V_16 . V_145 != V_134 . V_16 . V_145 )
return - V_144 ;
}
return 0 ;
}
static int F_63 ( struct V_83 * V_83 , void * V_101 ,
enum V_146 type )
{
struct V_8 * V_9 = F_35 ( V_83 ) ;
struct V_84 * V_51 = & V_9 -> V_12 . V_51 ;
struct V_85 * V_86 = & V_51 -> V_52 . V_87 ;
int V_36 ;
V_36 = F_64 ( V_86 , & V_51 -> V_147 -> V_148 ) ;
if ( V_36 < 0 )
return V_36 ;
V_36 = F_58 ( V_9 ) ;
if ( V_36 < 0 )
goto V_149;
V_36 = F_65 ( V_83 , V_101 , type ) ;
if ( V_36 < 0 )
goto V_149;
V_9 -> V_12 . V_99 = 1 ;
return 0 ;
V_149:
F_44 ( V_86 ) ;
return V_36 ;
}
static int F_66 ( struct V_83 * V_83 , void * V_101 ,
enum V_146 type )
{
struct V_8 * V_9 = F_35 ( V_83 ) ;
struct V_34 * V_35 = & V_9 -> V_12 ;
int V_36 ;
V_36 = F_67 ( V_83 , V_101 , type ) ;
if ( V_36 < 0 )
return V_36 ;
F_44 ( & V_35 -> V_51 . V_52 . V_87 ) ;
V_35 -> V_99 = 0 ;
return 0 ;
}
static int F_68 ( struct V_83 * V_83 , void * V_101 ,
struct V_150 * V_151 )
{
struct V_8 * V_9 = F_35 ( V_83 ) ;
int V_36 ;
V_36 = F_69 ( V_83 , V_101 , V_151 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( V_151 -> V_32 && V_151 -> V_32 < V_23 ) {
V_151 -> V_32 = 0 ;
F_69 ( V_83 , V_101 , V_151 ) ;
V_36 = - V_152 ;
}
V_9 -> V_12 . V_48 = V_151 -> V_32 ;
return V_36 ;
}
int F_70 ( struct V_8 * V_9 ,
struct V_153 * V_154 ,
enum V_146 type )
{
struct V_1 * V_31 = & V_9 -> V_12 . V_155 ;
struct V_34 * V_156 ;
struct V_157 * V_52 ;
int V_36 ;
if ( type == V_158 )
V_156 = & V_9 -> V_12 ;
else
return - V_159 ;
F_71 ( & V_9 -> V_88 ) ;
F_72 ( & V_156 -> V_160 ) ;
F_72 ( & V_156 -> V_161 ) ;
V_156 -> V_16 = F_50 ( NULL , NULL , 0 ) ;
V_156 -> V_13 . V_19 = V_162 ;
V_156 -> V_13 . V_20 = V_163 ;
V_156 -> V_13 . V_110 = V_156 -> V_16 -> V_111 ;
V_156 -> V_13 . V_116 = V_117 ;
V_156 -> V_48 = 0 ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> type = type ;
V_31 -> V_164 = V_165 | V_166 ;
V_31 -> V_167 = & V_168 ;
V_31 -> V_169 = & V_170 ;
V_31 -> V_171 = sizeof( struct V_71 ) ;
V_31 -> V_172 = V_9 ;
V_31 -> V_173 = V_174 ;
V_31 -> V_175 = & V_9 -> V_88 ;
V_31 -> V_59 = & V_9 -> V_58 -> V_59 ;
V_36 = F_73 ( V_31 ) ;
if ( V_36 < 0 )
return V_36 ;
V_52 = & V_156 -> V_51 . V_52 ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
snprintf ( V_52 -> V_109 , sizeof( V_52 -> V_109 ) , L_5 ,
type == V_158 ?
L_6 : L_7 ) ;
V_52 -> V_176 = V_31 ;
V_52 -> V_177 = & V_178 ;
V_52 -> V_179 = & V_180 ;
V_52 -> V_154 = V_154 ;
V_52 -> V_181 = - 1 ;
V_52 -> V_182 = V_183 ;
V_52 -> V_175 = & V_9 -> V_88 ;
V_156 -> V_137 . V_73 = V_139 ;
V_36 = F_74 ( & V_52 -> V_87 , 1 , & V_156 -> V_137 ) ;
if ( V_36 < 0 )
return V_36 ;
F_75 ( V_52 , V_9 ) ;
V_36 = F_76 ( V_52 , V_184 , - 1 ) ;
if ( V_36 < 0 ) {
F_77 ( & V_52 -> V_87 ) ;
return V_36 ;
}
F_78 ( V_154 , L_8 ,
V_52 -> V_109 , F_79 ( V_52 ) ) ;
return 0 ;
}
void F_80 ( struct V_8 * V_9 ,
enum V_146 type )
{
struct V_84 * V_51 ;
if ( type == V_158 )
V_51 = & V_9 -> V_12 . V_51 ;
else
return;
F_40 ( & V_9 -> V_88 ) ;
if ( F_81 ( & V_51 -> V_52 ) ) {
F_82 ( & V_51 -> V_52 ) ;
F_77 ( & V_51 -> V_52 . V_87 ) ;
V_51 -> V_147 = NULL ;
}
F_41 ( & V_9 -> V_88 ) ;
}
