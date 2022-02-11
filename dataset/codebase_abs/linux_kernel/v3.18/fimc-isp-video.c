static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int * V_5 , unsigned int * V_6 ,
unsigned int V_7 [] , void * V_8 [] )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
struct V_11 * V_12 = & V_10 -> V_13 . V_14 ;
const struct V_11 * V_15 = NULL ;
const struct V_16 * V_17 ;
unsigned int V_18 , V_19 ;
if ( V_4 ) {
V_15 = & V_4 -> V_17 . V_20 ;
V_17 = F_3 ( & V_15 -> V_21 , NULL , - 1 ) ;
V_18 = V_15 -> V_22 * V_15 -> V_23 ;
} else {
V_17 = V_10 -> V_13 . V_24 ;
V_18 = V_12 -> V_22 * V_12 -> V_23 ;
}
if ( V_17 == NULL )
return - V_25 ;
* V_5 = F_4 ( V_26 , * V_5 , V_27 ,
V_28 ) ;
* V_6 = V_17 -> V_29 ;
for ( V_19 = 0 ; V_19 < V_17 -> V_29 ; V_19 ++ ) {
unsigned int V_30 = ( V_18 * V_17 -> V_31 [ V_19 ] ) / 8 ;
if ( V_15 )
V_7 [ V_19 ] = F_5 ( V_30 , V_15 -> V_32 [ V_19 ] . V_33 ) ;
else
V_7 [ V_19 ] = V_30 ;
V_8 [ V_19 ] = V_10 -> V_34 ;
}
return 0 ;
}
static inline struct V_35 * F_6 ( struct V_36 * V_37 )
{
return & F_7 ( V_37 ) -> V_10 . V_38 ;
}
static int F_8 ( struct V_1 * V_39 ,
unsigned int V_40 )
{
struct V_9 * V_10 = F_2 ( V_39 ) ;
struct V_36 * V_37 = F_9 ( V_10 ) ;
struct V_35 * V_41 = F_6 ( V_37 ) ;
struct V_42 * V_43 = & V_10 -> V_13 ;
int V_44 ;
if ( ! F_10 ( V_45 , & V_10 -> V_46 ) ||
F_10 ( V_47 , & V_10 -> V_46 ) )
return 0 ;
V_41 -> V_48 = V_49 ;
V_41 -> V_50 = V_51 ;
V_41 -> V_52 = V_37 -> V_53 +
V_54 ;
V_41 -> V_55 = V_43 -> V_56 ;
V_41 -> V_57 = V_43 -> V_58 ;
F_11 ( 2 , & V_43 -> V_59 . V_60 ,
L_1 ,
V_43 -> V_61 , V_43 -> V_24 -> V_29 ,
V_41 -> V_52 ) ;
F_12 () ;
F_13 ( V_37 , V_62 ) ;
F_14 ( V_37 , V_62 ) ;
V_44 = F_15 ( V_37 , false ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_16 ( & V_43 -> V_59 , V_63 , 1 ) ;
if ( V_44 < 0 )
return V_44 ;
F_17 ( V_47 , & V_10 -> V_46 ) ;
return V_44 ;
}
static void F_18 ( struct V_1 * V_39 )
{
struct V_9 * V_10 = F_2 ( V_39 ) ;
struct V_36 * V_37 = F_9 ( V_10 ) ;
struct V_35 * V_41 = F_6 ( V_37 ) ;
int V_44 ;
V_44 = F_16 ( & V_10 -> V_13 . V_59 , V_63 , 0 ) ;
if ( V_44 < 0 )
return;
V_41 -> V_48 = V_64 ;
V_41 -> V_50 = V_65 ;
V_41 -> V_55 = 0 ;
V_41 -> V_52 = 0 ;
V_41 -> V_57 = 0 ;
F_13 ( V_37 , V_62 ) ;
F_14 ( V_37 , V_62 ) ;
V_44 = F_15 ( V_37 , false ) ;
if ( V_44 < 0 )
F_19 ( & V_37 -> V_66 -> V_67 , L_2 , V_68 ) ;
F_20 ( V_37 , 0 ) ;
F_21 ( V_45 , & V_10 -> V_46 ) ;
F_21 ( V_47 , & V_10 -> V_46 ) ;
V_10 -> V_13 . V_61 = 0 ;
}
static int F_22 ( struct V_69 * V_70 )
{
struct V_9 * V_10 = F_2 ( V_70 -> V_1 ) ;
struct V_42 * V_43 = & V_10 -> V_13 ;
int V_19 ;
if ( V_43 -> V_24 == NULL )
return - V_25 ;
for ( V_19 = 0 ; V_19 < V_43 -> V_24 -> V_29 ; V_19 ++ ) {
unsigned long V_30 = V_43 -> V_14 . V_32 [ V_19 ] . V_33 ;
if ( F_23 ( V_70 , V_19 ) < V_30 ) {
F_24 ( & V_43 -> V_59 . V_60 ,
L_3 ,
F_23 ( V_70 , V_19 ) , V_30 ) ;
return - V_25 ;
}
F_25 ( V_70 , V_19 , V_30 ) ;
}
if ( F_10 ( V_45 , & V_10 -> V_46 ) ) {
T_1 V_71 = F_26 ( V_70 , 0 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_43 -> V_61 ; V_19 ++ )
if ( V_43 -> V_72 [ V_19 ] -> V_71 [ 0 ] == V_71 )
return 0 ;
return - V_73 ;
}
return 0 ;
}
static void F_27 ( struct V_69 * V_70 )
{
struct V_9 * V_10 = F_2 ( V_70 -> V_1 ) ;
struct V_42 * V_43 = & V_10 -> V_13 ;
struct V_36 * V_37 = F_9 ( V_10 ) ;
struct V_74 * V_75 = F_28 ( V_70 ) ;
unsigned long V_76 ;
unsigned int V_19 ;
if ( F_10 ( V_45 , & V_10 -> V_46 ) ) {
F_29 ( & V_37 -> V_77 , V_76 ) ;
V_43 -> V_58 |= F_30 ( V_75 -> V_78 ) ;
F_31 ( & V_37 -> V_77 , V_76 ) ;
} else {
unsigned int V_6 = V_43 -> V_24 -> V_29 ;
V_75 -> V_78 = V_43 -> V_61 ;
V_43 -> V_72 [ V_75 -> V_78 ] = V_75 ;
for ( V_19 = 0 ; V_19 < V_6 ; V_19 ++ ) {
int V_79 = V_75 -> V_78 * V_6 + V_19 ;
V_75 -> V_71 [ V_19 ] = F_26 ( V_70 , V_19 ) ;
V_37 -> V_80 -> V_81 [ 32 + V_79 ] =
V_75 -> V_71 [ V_19 ] ;
F_11 ( 2 , & V_43 -> V_59 . V_60 ,
L_4 ,
& V_79 , V_75 -> V_78 , V_19 , V_70 -> V_82 . V_78 ,
& V_75 -> V_71 [ V_19 ] ) ;
}
if ( ++ V_43 -> V_61 < V_43 -> V_56 )
return;
V_43 -> V_58 = ( 1UL << V_43 -> V_61 ) - 1 ;
F_17 ( V_45 , & V_10 -> V_46 ) ;
}
if ( ! F_10 ( V_47 , & V_10 -> V_46 ) )
F_8 ( V_70 -> V_1 , 0 ) ;
}
void F_32 ( struct V_36 * V_37 )
{
struct V_42 * V_43 = & V_37 -> V_10 . V_13 ;
struct V_69 * V_70 ;
int V_79 ;
if ( ! F_10 ( V_47 , & V_37 -> V_10 . V_46 ) )
return;
V_79 = ( V_37 -> V_83 . args [ 1 ] - 1 ) % V_43 -> V_61 ;
V_70 = & V_43 -> V_72 [ V_79 ] -> V_70 ;
F_33 ( & V_70 -> V_82 . V_84 ) ;
F_34 ( V_70 , V_85 ) ;
V_43 -> V_58 &= ~ F_30 ( V_79 ) ;
F_20 ( V_37 , V_43 -> V_58 ) ;
}
static int F_35 ( struct V_86 * V_86 )
{
struct V_9 * V_10 = F_36 ( V_86 ) ;
struct V_87 * V_59 = & V_10 -> V_13 . V_59 ;
struct V_88 * V_89 = & V_59 -> V_60 . V_90 ;
int V_44 ;
if ( F_37 ( & V_10 -> V_91 ) )
return - V_92 ;
V_44 = F_38 ( V_86 ) ;
if ( V_44 < 0 )
goto V_93;
V_44 = F_39 ( & V_10 -> V_66 -> V_67 ) ;
if ( V_44 < 0 )
goto V_94;
if ( F_40 ( V_86 ) ) {
F_41 ( & V_89 -> V_95 -> V_96 ) ;
V_44 = F_16 ( V_59 , V_97 , V_89 , true ) ;
if ( V_44 == 0 )
V_89 -> V_98 ++ ;
F_42 ( & V_89 -> V_95 -> V_96 ) ;
}
if ( ! V_44 )
goto V_93;
V_94:
F_43 ( V_86 ) ;
V_93:
F_42 ( & V_10 -> V_91 ) ;
return V_44 ;
}
static int F_44 ( struct V_86 * V_86 )
{
struct V_9 * V_10 = F_36 ( V_86 ) ;
struct V_42 * V_99 = & V_10 -> V_13 ;
struct V_88 * V_90 = & V_99 -> V_59 . V_60 . V_90 ;
struct V_100 * V_101 = V_90 -> V_95 ;
F_41 ( & V_10 -> V_91 ) ;
if ( F_40 ( V_86 ) && V_99 -> V_102 ) {
F_45 ( V_90 ) ;
V_99 -> V_102 = 0 ;
}
F_46 ( V_86 ) ;
if ( F_40 ( V_86 ) ) {
F_16 ( & V_99 -> V_59 , V_103 ) ;
F_41 ( & V_101 -> V_96 ) ;
V_90 -> V_98 -- ;
F_42 ( & V_101 -> V_96 ) ;
}
F_47 ( & V_10 -> V_66 -> V_67 ) ;
F_42 ( & V_10 -> V_91 ) ;
return 0 ;
}
static int F_48 ( struct V_86 * V_86 , void * V_104 ,
struct V_105 * V_106 )
{
struct V_9 * V_10 = F_36 ( V_86 ) ;
F_49 ( & V_10 -> V_66 -> V_67 , V_106 , V_107 ) ;
return 0 ;
}
static int F_50 ( struct V_86 * V_86 , void * V_104 ,
struct V_108 * V_109 )
{
const struct V_16 * V_17 ;
if ( V_109 -> V_78 >= V_110 )
return - V_25 ;
V_17 = F_3 ( NULL , NULL , V_109 -> V_78 ) ;
if ( F_51 ( V_17 == NULL ) )
return - V_25 ;
F_52 ( V_109 -> V_111 , V_17 -> V_112 , sizeof( V_109 -> V_111 ) ) ;
V_109 -> V_21 = V_17 -> V_113 ;
return 0 ;
}
static int F_53 ( struct V_86 * V_86 , void * V_114 ,
struct V_3 * V_109 )
{
struct V_9 * V_10 = F_36 ( V_86 ) ;
V_109 -> V_17 . V_20 = V_10 -> V_13 . V_14 ;
return 0 ;
}
static void F_54 ( struct V_9 * V_10 ,
struct V_11 * V_15 ,
const struct V_16 * * V_17 )
{
* V_17 = F_3 ( & V_15 -> V_21 , NULL , 2 ) ;
V_15 -> V_115 = V_116 ;
V_15 -> V_117 = V_118 ;
V_15 -> V_6 = ( * V_17 ) -> V_29 ;
V_15 -> V_21 = ( * V_17 ) -> V_113 ;
F_55 ( & V_15 -> V_22 , V_119 ,
V_120 , 3 ,
& V_15 -> V_23 , V_121 ,
V_122 , 0 , 0 ) ;
}
static int F_56 ( struct V_86 * V_86 , void * V_114 ,
struct V_3 * V_109 )
{
struct V_9 * V_10 = F_36 ( V_86 ) ;
F_54 ( V_10 , & V_109 -> V_17 . V_20 , NULL ) ;
return 0 ;
}
static int F_57 ( struct V_86 * V_86 , void * V_104 ,
struct V_3 * V_109 )
{
struct V_9 * V_10 = F_36 ( V_86 ) ;
struct V_36 * V_37 = F_9 ( V_10 ) ;
struct V_11 * V_15 = & V_109 -> V_17 . V_20 ;
const struct V_16 * V_123 = NULL ;
struct V_35 * V_41 = F_6 ( V_37 ) ;
F_54 ( V_10 , V_15 , & V_123 ) ;
if ( F_51 ( V_123 == NULL ) )
return - V_25 ;
V_41 -> V_24 = V_124 ;
V_41 -> V_125 = V_126 ;
V_41 -> V_127 = V_123 -> V_29 ;
V_41 -> V_128 = V_123 -> V_31 [ 0 ] ;
V_41 -> V_22 = V_15 -> V_22 ;
V_41 -> V_23 = V_15 -> V_23 ;
F_12 () ;
V_10 -> V_13 . V_24 = V_123 ;
V_10 -> V_13 . V_14 = * V_15 ;
return 0 ;
}
static int F_58 ( struct V_9 * V_10 )
{
struct V_129 * V_130 = & V_10 -> V_131 ;
struct V_132 V_133 , V_134 ;
struct V_135 * V_136 ;
int V_44 ;
while ( 1 ) {
V_136 = & V_130 -> V_90 . V_137 [ 0 ] ;
if ( ! ( V_136 -> V_76 & V_138 ) )
break;
V_133 . V_136 = V_136 -> V_78 ;
V_133 . V_139 = V_140 ;
V_44 = F_59 ( V_130 , V_136 , V_141 , NULL , & V_133 ) ;
if ( V_44 < 0 && V_44 != - V_142 )
return - V_143 ;
V_136 = F_60 ( V_136 ) ;
if ( V_136 == NULL ||
F_61 ( V_136 -> V_90 ) != V_144 )
break;
V_130 = F_62 ( V_136 -> V_90 ) ;
V_134 . V_136 = V_136 -> V_78 ;
V_134 . V_139 = V_140 ;
V_44 = F_59 ( V_130 , V_136 , V_141 , NULL , & V_134 ) ;
if ( V_44 < 0 && V_44 != - V_142 )
return - V_143 ;
if ( V_134 . V_24 . V_22 != V_133 . V_24 . V_22 ||
V_134 . V_24 . V_23 != V_133 . V_24 . V_23 ||
V_134 . V_24 . V_145 != V_133 . V_24 . V_145 )
return - V_143 ;
}
return 0 ;
}
static int F_63 ( struct V_86 * V_86 , void * V_104 ,
enum V_146 type )
{
struct V_9 * V_10 = F_36 ( V_86 ) ;
struct V_87 * V_59 = & V_10 -> V_13 . V_59 ;
struct V_88 * V_89 = & V_59 -> V_60 . V_90 ;
int V_44 ;
V_44 = F_64 ( V_89 , & V_59 -> V_147 -> V_148 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_58 ( V_10 ) ;
if ( V_44 < 0 )
goto V_149;
V_44 = F_65 ( V_86 , V_104 , type ) ;
if ( V_44 < 0 )
goto V_149;
V_10 -> V_13 . V_102 = 1 ;
return 0 ;
V_149:
F_45 ( V_89 ) ;
return V_44 ;
}
static int F_66 ( struct V_86 * V_86 , void * V_104 ,
enum V_146 type )
{
struct V_9 * V_10 = F_36 ( V_86 ) ;
struct V_42 * V_43 = & V_10 -> V_13 ;
int V_44 ;
V_44 = F_67 ( V_86 , V_104 , type ) ;
if ( V_44 < 0 )
return V_44 ;
F_45 ( & V_43 -> V_59 . V_60 . V_90 ) ;
V_43 -> V_102 = 0 ;
return 0 ;
}
static int F_68 ( struct V_86 * V_86 , void * V_104 ,
struct V_150 * V_151 )
{
struct V_9 * V_10 = F_36 ( V_86 ) ;
int V_44 ;
V_44 = F_69 ( V_86 , V_104 , V_151 ) ;
if ( V_44 < 0 )
return V_44 ;
if ( V_151 -> V_40 && V_151 -> V_40 < V_27 ) {
V_151 -> V_40 = 0 ;
F_69 ( V_86 , V_104 , V_151 ) ;
V_44 = - V_152 ;
}
V_10 -> V_13 . V_56 = V_151 -> V_40 ;
return V_44 ;
}
int F_70 ( struct V_9 * V_10 ,
struct V_153 * V_154 ,
enum V_146 type )
{
struct V_1 * V_39 = & V_10 -> V_13 . V_155 ;
struct V_42 * V_156 ;
struct V_157 * V_60 ;
int V_44 ;
if ( type == V_158 )
V_156 = & V_10 -> V_13 ;
else
return - V_159 ;
F_71 ( & V_10 -> V_91 ) ;
F_72 ( & V_156 -> V_160 ) ;
F_72 ( & V_156 -> V_161 ) ;
V_156 -> V_24 = F_3 ( NULL , NULL , 0 ) ;
V_156 -> V_14 . V_22 = V_162 ;
V_156 -> V_14 . V_23 = V_163 ;
V_156 -> V_14 . V_21 = V_156 -> V_24 -> V_113 ;
V_156 -> V_14 . V_115 = V_116 ;
V_156 -> V_56 = 0 ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_39 -> type = type ;
V_39 -> V_164 = V_165 | V_166 ;
V_39 -> V_167 = & V_168 ;
V_39 -> V_169 = & V_170 ;
V_39 -> V_171 = sizeof( struct V_74 ) ;
V_39 -> V_172 = V_10 ;
V_39 -> V_173 = V_174 ;
V_39 -> V_175 = & V_10 -> V_91 ;
V_44 = F_73 ( V_39 ) ;
if ( V_44 < 0 )
return V_44 ;
V_60 = & V_156 -> V_59 . V_60 ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
snprintf ( V_60 -> V_112 , sizeof( V_60 -> V_112 ) , L_5 ,
type == V_158 ?
L_6 : L_7 ) ;
V_60 -> V_176 = V_39 ;
V_60 -> V_177 = & V_178 ;
V_60 -> V_179 = & V_180 ;
V_60 -> V_154 = V_154 ;
V_60 -> V_181 = - 1 ;
V_60 -> V_182 = V_183 ;
V_60 -> V_175 = & V_10 -> V_91 ;
V_156 -> V_136 . V_76 = V_138 ;
V_44 = F_74 ( & V_60 -> V_90 , 1 , & V_156 -> V_136 , 0 ) ;
if ( V_44 < 0 )
return V_44 ;
F_75 ( V_60 , V_10 ) ;
V_44 = F_76 ( V_60 , V_184 , - 1 ) ;
if ( V_44 < 0 ) {
F_77 ( & V_60 -> V_90 ) ;
return V_44 ;
}
F_78 ( V_154 , L_8 ,
V_60 -> V_112 , F_79 ( V_60 ) ) ;
return 0 ;
}
void F_80 ( struct V_9 * V_10 ,
enum V_146 type )
{
struct V_87 * V_59 ;
if ( type == V_158 )
V_59 = & V_10 -> V_13 . V_59 ;
else
return;
F_41 ( & V_10 -> V_91 ) ;
if ( F_81 ( & V_59 -> V_60 ) ) {
F_82 ( & V_59 -> V_60 ) ;
F_77 ( & V_59 -> V_60 . V_90 ) ;
V_59 -> V_147 = NULL ;
}
F_42 ( & V_10 -> V_91 ) ;
}
