static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_4 * V_5 )
{
F_1 ( F_5 ( V_5 ) ) ;
}
static int F_6 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
T_1 V_8 , T_1 V_9 ,
struct V_10 * V_11 )
{
T_2 V_12 ;
struct {
struct {
T_1 V_13 ;
} V_14 ;
T_3 V_15 ;
} * V_16 ;
F_7 ( ! V_2 -> V_17 ) ;
V_12 = sizeof( * V_16 ) ;
V_16 = F_8 ( V_7 , V_12 ) ;
if ( F_9 ( V_16 == NULL ) ) {
F_10 ( L_1 ) ;
return - V_18 ;
}
memset ( V_16 , 0 , V_12 ) ;
V_16 -> V_14 . V_13 = V_19 ;
V_16 -> V_15 . V_20 = sizeof( T_3 ) ;
V_16 -> V_15 . V_21 = V_2 -> V_3 . V_22 ;
V_16 -> V_15 . V_23 = V_24 |
( V_2 -> V_3 . V_22 == 0 ? V_25 : 0 ) ;
V_16 -> V_15 . V_26 . V_27 = V_11 -> V_28 ;
V_16 -> V_15 . V_26 . V_29 = V_11 -> V_30 ;
if ( V_2 -> V_3 . V_31 ) {
V_16 -> V_15 . V_32 . V_8 = V_8 ;
V_16 -> V_15 . V_32 . V_9 = V_9 ;
} else {
V_16 -> V_15 . V_32 . V_8 = V_2 -> V_3 . V_33 ;
V_16 -> V_15 . V_32 . V_9 = V_2 -> V_3 . V_34 ;
}
V_2 -> V_3 . V_35 = V_16 -> V_15 . V_32 . V_8 ;
V_2 -> V_3 . V_36 = V_16 -> V_15 . V_32 . V_9 ;
F_11 ( & V_2 -> V_17 -> V_3 , & V_16 -> V_15 . V_37 . V_38 ) ;
V_16 -> V_15 . V_37 . V_39 = V_11 -> V_28 * 4 ;
F_12 ( V_7 , V_12 ) ;
V_2 -> V_40 = true ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
T_2 V_12 ;
int V_41 ;
struct {
struct {
T_1 V_13 ;
} V_14 ;
T_4 V_42 ;
} * V_16 ;
if ( F_9 ( ! V_2 -> V_40 ) )
return 0 ;
V_12 = sizeof( * V_16 ) ;
V_16 = F_8 ( V_7 , V_12 ) ;
if ( F_9 ( V_16 == NULL ) ) {
F_10 ( L_1 ) ;
return - V_18 ;
}
memset ( V_16 , 0 , V_12 ) ;
V_16 -> V_14 . V_13 = V_43 ;
V_16 -> V_42 . V_44 = V_2 -> V_3 . V_22 ;
F_12 ( V_7 , V_12 ) ;
V_41 = F_14 ( V_7 , false , true , 0 , false , 3 * V_45 ) ;
if ( F_9 ( V_41 != 0 ) )
F_10 ( L_2 ) ;
else
V_2 -> V_40 = false ;
return V_41 ;
}
static void F_15 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_17 ) ;
V_2 -> V_46 = 0 ;
}
static int F_17 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
unsigned long V_26 )
{
int V_41 ;
if ( V_2 -> V_46 == V_26 )
return 0 ;
if ( V_2 -> V_17 )
F_15 ( V_7 , V_2 ) ;
V_2 -> V_17 = F_18 ( sizeof( * V_2 -> V_17 ) , V_47 ) ;
if ( F_9 ( V_2 -> V_17 == NULL ) )
return - V_18 ;
F_19 ( V_7 ) ;
V_41 = F_20 ( V_7 , V_2 -> V_17 , V_26 ,
& V_48 ,
false , & V_49 ) ;
F_21 ( V_7 ) ;
if ( F_9 ( V_41 != 0 ) )
V_2 -> V_17 = NULL ;
else
V_2 -> V_46 = V_26 ;
return V_41 ;
}
static int F_22 ( struct V_50 * V_51 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_52 * V_53 ;
struct V_10 * V_11 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
struct V_4 * V_5 ;
int V_41 = 0 ;
if ( ! V_51 )
return - V_60 ;
if ( ! V_51 -> V_5 )
return - V_60 ;
V_5 = V_51 -> V_5 ;
V_2 = F_5 ( V_5 ) ;
V_57 = V_51 -> V_59 ? F_23 ( V_51 -> V_59 ) : NULL ;
V_7 = F_24 ( V_5 -> V_61 ) ;
if ( V_51 -> V_62 > 1 ) {
F_10 ( L_3 ) ;
return - V_60 ;
}
if ( V_51 -> V_62 == 1 &&
V_51 -> V_63 [ 0 ] != & V_2 -> V_3 . V_53 ) {
F_10 ( L_4 ,
V_51 -> V_63 [ 0 ] , & V_2 -> V_3 . V_53 ) ;
return - V_60 ;
}
F_25 ( & V_7 -> V_64 ) ;
if ( V_2 -> V_3 . V_31 &&
V_7 -> V_65 && V_57 &&
! ( V_7 -> V_66 == 1 &&
V_2 -> V_3 . V_67 ) &&
V_7 -> V_65 != V_57 ) {
F_26 ( & V_7 -> V_64 ) ;
F_10 ( L_5 ) ;
return - V_60 ;
}
F_26 ( & V_7 -> V_64 ) ;
V_53 = & V_2 -> V_3 . V_53 ;
V_55 = & V_2 -> V_3 . V_55 ;
if ( V_51 -> V_62 == 0 || ! V_51 -> V_11 || ! V_51 -> V_59 ) {
V_41 = F_13 ( V_7 , V_2 ) ;
if ( F_9 ( V_41 != 0 ) )
return V_41 ;
V_53 -> V_55 = NULL ;
V_55 -> V_5 = NULL ;
V_5 -> V_68 -> V_59 = NULL ;
V_5 -> V_8 = 0 ;
V_5 -> V_9 = 0 ;
V_5 -> V_69 = false ;
F_27 ( V_7 , & V_2 -> V_3 ) ;
F_15 ( V_7 , V_2 ) ;
return 0 ;
}
V_11 = V_51 -> V_11 ;
V_59 = V_51 -> V_59 ;
if ( V_51 -> V_8 + V_11 -> V_28 > V_59 -> V_27 ||
V_51 -> V_9 + V_11 -> V_30 > V_59 -> V_29 ) {
F_10 ( L_6 ) ;
return - V_60 ;
}
F_28 ( V_7 ) ;
if ( V_11 -> V_28 != V_5 -> V_11 . V_28 ||
V_11 -> V_30 != V_5 -> V_11 . V_30 ) {
V_41 = F_13 ( V_7 , V_2 ) ;
if ( F_9 ( V_41 != 0 ) )
return V_41 ;
F_15 ( V_7 , V_2 ) ;
}
if ( ! V_2 -> V_17 ) {
T_2 V_26 = V_11 -> V_28 * V_11 -> V_30 * 4 ;
V_41 = F_17 ( V_7 , V_2 , V_26 ) ;
if ( F_9 ( V_41 != 0 ) )
return V_41 ;
}
V_41 = F_6 ( V_7 , V_2 , V_51 -> V_8 , V_51 -> V_9 , V_11 ) ;
if ( F_9 ( V_41 != 0 ) ) {
if ( V_2 -> V_40 )
return V_41 ;
V_53 -> V_55 = NULL ;
V_55 -> V_5 = NULL ;
V_5 -> V_68 -> V_59 = NULL ;
V_5 -> V_8 = 0 ;
V_5 -> V_9 = 0 ;
V_5 -> V_69 = false ;
return V_41 ;
}
F_29 ( V_7 , & V_2 -> V_3 , V_57 ) ;
V_53 -> V_55 = V_55 ;
V_55 -> V_5 = V_5 ;
V_5 -> V_11 = * V_11 ;
V_5 -> V_68 -> V_59 = V_59 ;
V_5 -> V_8 = V_51 -> V_8 ;
V_5 -> V_9 = V_51 -> V_9 ;
V_5 -> V_69 = true ;
return 0 ;
}
static int F_30 ( struct V_4 * V_5 ,
struct V_58 * V_59 ,
struct V_70 * V_71 ,
T_1 V_23 )
{
struct V_6 * V_7 = F_24 ( V_5 -> V_61 ) ;
struct V_58 * V_72 = V_5 -> V_68 -> V_59 ;
struct V_56 * V_57 = F_23 ( V_59 ) ;
struct V_73 * V_74 = NULL ;
struct V_75 V_76 ;
int V_41 ;
if ( ! F_31 ( V_7 , V_5 ) )
return - V_60 ;
V_5 -> V_68 -> V_59 = V_59 ;
V_76 . V_8 = V_5 -> V_8 ;
V_76 . V_9 = V_5 -> V_9 ;
V_76 . V_77 = V_5 -> V_11 . V_28 ;
V_76 . V_78 = V_5 -> V_11 . V_30 ;
if ( V_57 -> V_79 )
V_41 = F_32 ( V_7 , V_57 ,
NULL , & V_76 , 1 , 1 ,
true , & V_74 ) ;
else
V_41 = F_33 ( V_7 , V_57 ,
NULL , & V_76 , NULL ,
0 , 0 , 1 , 1 , & V_74 ) ;
if ( V_41 != 0 )
goto V_80;
if ( ! V_74 ) {
V_41 = - V_60 ;
goto V_80;
}
if ( V_71 ) {
struct V_81 * V_82 = V_71 -> V_3 . V_82 ;
V_41 = F_34 ( V_82 , V_74 ,
& V_71 -> V_3 ,
& V_71 -> V_71 . V_83 ,
& V_71 -> V_71 . V_84 ,
true ) ;
}
F_35 ( & V_74 ) ;
if ( F_36 ( V_5 ) -> V_31 )
F_37 ( V_7 , V_5 ) ;
return V_41 ;
V_80:
V_5 -> V_68 -> V_59 = V_72 ;
return V_41 ;
}
static void F_38 ( struct V_54 * V_55 )
{
F_1 ( F_39 ( V_55 ) ) ;
}
static void F_40 ( struct V_52 * V_53 )
{
F_1 ( F_41 ( V_53 ) ) ;
}
static int F_42 ( struct V_6 * V_7 , unsigned V_22 )
{
struct V_1 * V_2 ;
struct V_85 * V_61 = V_7 -> V_61 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_4 * V_5 ;
V_2 = F_18 ( sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 )
return - V_18 ;
V_2 -> V_3 . V_22 = V_22 ;
V_5 = & V_2 -> V_3 . V_5 ;
V_55 = & V_2 -> V_3 . V_55 ;
V_53 = & V_2 -> V_3 . V_53 ;
V_2 -> V_3 . V_67 = false ;
V_2 -> V_3 . V_86 = ( V_22 == 0 ) ;
V_2 -> V_3 . V_87 = V_7 -> V_88 ;
V_2 -> V_3 . V_89 = V_7 -> V_90 ;
V_2 -> V_3 . V_91 = NULL ;
V_2 -> V_3 . V_31 = false ;
F_43 ( V_61 , V_53 , & V_92 ,
V_93 ) ;
V_53 -> V_94 = F_44 ( V_53 , true ) ;
F_45 ( V_61 , V_55 , & V_95 ,
V_96 , NULL ) ;
F_46 ( V_53 , V_55 ) ;
V_55 -> V_97 = ( 1 << V_22 ) ;
V_55 -> V_98 = 0 ;
( void ) F_47 ( V_53 ) ;
F_48 ( V_61 , V_5 , & V_99 ) ;
F_49 ( V_5 , 256 ) ;
F_50 ( & V_53 -> V_3 ,
V_61 -> V_100 . V_101 ,
1 ) ;
F_50 ( & V_53 -> V_3 ,
V_7 -> V_102 , 1 ) ;
F_50 ( & V_53 -> V_3 ,
V_61 -> V_100 . V_103 , 0 ) ;
F_50 ( & V_53 -> V_3 ,
V_61 -> V_100 . V_104 , 0 ) ;
if ( V_7 -> V_105 )
F_50
( & V_53 -> V_3 ,
V_7 -> V_105 ,
V_2 -> V_3 . V_31 ) ;
return 0 ;
}
int F_51 ( struct V_6 * V_7 )
{
struct V_85 * V_61 = V_7 -> V_61 ;
int V_106 , V_41 ;
if ( ! ( V_7 -> V_107 & V_108 ) ) {
F_52 ( L_7
L_8 ) ;
return - V_109 ;
}
V_41 = - V_18 ;
V_7 -> V_66 = 0 ;
V_7 -> V_65 = NULL ;
V_41 = F_53 ( V_61 , V_110 ) ;
if ( F_9 ( V_41 != 0 ) )
return V_41 ;
V_41 = F_54 ( V_61 ) ;
if ( F_9 ( V_41 != 0 ) )
goto V_111;
F_55 ( V_7 , false ) ;
for ( V_106 = 0 ; V_106 < V_110 ; ++ V_106 )
F_42 ( V_7 , V_106 ) ;
V_7 -> V_112 = V_113 ;
F_52 ( L_9 ) ;
return 0 ;
V_111:
F_56 ( V_61 ) ;
return V_41 ;
}
int F_57 ( struct V_6 * V_7 )
{
struct V_85 * V_61 = V_7 -> V_61 ;
F_56 ( V_61 ) ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 ,
struct V_56 * V_114 )
{
struct V_115 * V_116 =
F_59 ( V_114 , struct V_117 ,
V_3 ) -> V_17 ;
int V_118 = V_114 -> V_3 . V_118 ;
struct {
T_1 V_14 ;
T_5 V_42 ;
} * V_16 ;
if ( V_118 == 32 )
V_118 = 24 ;
V_16 = F_8 ( V_7 , sizeof( * V_16 ) ) ;
if ( ! V_16 ) {
F_10 ( L_10 ) ;
return - V_18 ;
}
V_16 -> V_14 = V_119 ;
V_16 -> V_42 . V_120 . V_121 = V_114 -> V_3 . V_122 ;
V_16 -> V_42 . V_120 . V_123 = V_118 ;
V_16 -> V_42 . V_120 . V_124 = 0 ;
V_16 -> V_42 . V_125 = V_114 -> V_3 . V_126 [ 0 ] ;
F_11 ( & V_116 -> V_3 , & V_16 -> V_42 . V_38 ) ;
F_12 ( V_7 , sizeof( * V_16 ) ) ;
return 0 ;
}
static void F_60 ( struct V_127 * V_128 )
{
struct V_129 * V_130 =
F_59 ( V_128 , F_61 ( * V_130 ) , V_3 ) ;
struct V_131 * V_16 = V_128 -> V_16 ;
T_6 V_132 = V_128 -> V_22 -> V_5 . V_8 - V_130 -> V_133 ;
T_6 V_134 = V_128 -> V_22 -> V_5 . V_9 - V_130 -> V_135 ;
T_2 V_136 = V_128 -> V_137 * sizeof( V_138 ) ;
V_138 * V_139 = ( V_138 * ) & V_16 [ 1 ] ;
int V_106 ;
if ( ! V_128 -> V_137 ) {
F_12 ( V_128 -> V_7 , 0 ) ;
return;
}
V_16 -> V_14 . V_21 = V_140 ;
V_16 -> V_14 . V_26 = sizeof( V_16 -> V_42 ) + V_136 ;
V_16 -> V_42 . V_141 . V_142 = V_130 -> V_142 ;
V_16 -> V_42 . V_141 . V_143 = V_130 -> V_143 ;
V_16 -> V_42 . V_141 . V_144 = V_130 -> V_144 ;
V_16 -> V_42 . V_141 . V_145 = V_130 -> V_145 ;
V_16 -> V_42 . V_146 . V_142 = V_130 -> V_142 + V_132 ;
V_16 -> V_42 . V_146 . V_143 = V_130 -> V_143 + V_132 ;
V_16 -> V_42 . V_146 . V_144 = V_130 -> V_144 + V_134 ;
V_16 -> V_42 . V_146 . V_145 = V_130 -> V_145 + V_134 ;
V_16 -> V_42 . V_147 . V_148 = V_130 -> V_148 ;
V_16 -> V_42 . V_149 = V_128 -> V_22 -> V_22 ;
for ( V_106 = 0 ; V_106 < V_128 -> V_137 ; ++ V_106 , ++ V_139 ) {
V_139 -> V_142 -= V_130 -> V_142 ;
V_139 -> V_143 -= V_130 -> V_142 ;
V_139 -> V_144 -= V_130 -> V_144 ;
V_139 -> V_145 -= V_130 -> V_144 ;
}
F_12 ( V_128 -> V_7 , V_136 + sizeof( * V_16 ) ) ;
V_130 -> V_142 = V_130 -> V_144 = V_150 ;
V_130 -> V_143 = V_130 -> V_145 = V_151 ;
}
static void F_62 ( struct V_127 * V_128 )
{
struct V_129 * V_130 =
F_59 ( V_128 , F_61 ( * V_130 ) , V_3 ) ;
struct V_131 * V_16 = V_128 -> V_16 ;
V_138 * V_139 = ( V_138 * ) & V_16 [ 1 ] ;
V_139 += V_128 -> V_137 ;
V_139 -> V_142 = V_128 -> V_152 ;
V_139 -> V_144 = V_128 -> V_153 ;
V_139 -> V_143 = V_128 -> V_154 ;
V_139 -> V_145 = V_128 -> V_155 ;
V_130 -> V_142 = F_63 ( T_6 , V_130 -> V_142 , V_128 -> V_152 ) ;
V_130 -> V_144 = F_63 ( T_6 , V_130 -> V_144 , V_128 -> V_153 ) ;
V_130 -> V_143 = F_64 ( T_6 , V_130 -> V_143 , V_128 -> V_154 ) ;
V_130 -> V_145 = F_64 ( T_6 , V_130 -> V_145 , V_128 -> V_155 ) ;
V_128 -> V_137 ++ ;
}
int F_33 ( struct V_6 * V_7 ,
struct V_56 * V_114 ,
struct V_156 * V_157 ,
struct V_75 * V_76 ,
struct V_158 * V_159 ,
T_6 V_160 ,
T_6 V_161 ,
unsigned V_162 , int V_163 ,
struct V_73 * * V_164 )
{
struct V_165 * V_166 =
F_59 ( V_114 , F_61 ( * V_166 ) , V_3 ) ;
struct V_129 V_130 ;
int V_41 ;
if ( ! V_159 )
V_159 = & V_166 -> V_167 -> V_168 ;
V_41 = F_65 ( V_159 , true ) ;
if ( V_41 )
return V_41 ;
V_130 . V_3 . V_169 = F_60 ;
V_130 . V_3 . V_170 = F_62 ;
V_130 . V_3 . V_7 = V_7 ;
V_130 . V_3 . V_171 = sizeof( struct V_131 ) +
sizeof( V_138 ) * V_162 ;
V_130 . V_148 = V_159 -> V_21 ;
V_130 . V_142 = V_130 . V_144 = V_150 ;
V_130 . V_143 = V_130 . V_145 = V_151 ;
V_130 . V_133 = V_160 ;
V_130 . V_135 = V_161 ;
V_41 = F_66 ( V_7 , V_114 , V_157 , V_76 ,
V_160 , V_161 , V_162 , V_163 ,
& V_130 . V_3 ) ;
F_67 ( V_159 , V_164 ) ;
return V_41 ;
}
static void F_68 ( struct V_127 * V_128 )
{
if ( ! V_128 -> V_137 ) {
F_12 ( V_128 -> V_7 , 0 ) ;
return;
}
F_12 ( V_128 -> V_7 ,
sizeof( struct V_172 ) *
V_128 -> V_137 ) ;
}
static void F_69 ( struct V_127 * V_128 )
{
struct V_172 * V_139 = V_128 -> V_16 ;
V_139 += V_128 -> V_137 ;
V_139 -> V_14 = V_173 ;
V_139 -> V_42 . V_149 = V_128 -> V_22 -> V_22 ;
V_139 -> V_42 . V_174 . V_8 = V_128 -> V_175 ;
V_139 -> V_42 . V_174 . V_9 = V_128 -> V_176 ;
V_139 -> V_42 . V_141 . V_142 = V_128 -> V_152 ;
V_139 -> V_42 . V_141 . V_144 = V_128 -> V_153 ;
V_139 -> V_42 . V_141 . V_143 = V_128 -> V_154 ;
V_139 -> V_42 . V_141 . V_145 = V_128 -> V_155 ;
V_128 -> V_137 ++ ;
}
int F_32 ( struct V_6 * V_7 ,
struct V_56 * V_114 ,
struct V_156 * V_157 ,
struct V_75 * V_76 ,
unsigned V_162 , int V_177 ,
bool V_178 ,
struct V_73 * * V_164 )
{
struct V_115 * V_116 =
F_59 ( V_114 , struct V_117 ,
V_3 ) -> V_17 ;
struct V_127 V_128 ;
int V_41 ;
V_41 = F_70 ( V_7 , V_116 , V_178 ,
false ) ;
if ( V_41 )
return V_41 ;
V_41 = F_58 ( V_7 , V_114 ) ;
if ( F_9 ( V_41 != 0 ) )
goto V_179;
V_128 . V_169 = F_68 ;
V_128 . V_170 = F_69 ;
V_128 . V_171 = sizeof( struct V_172 ) *
V_162 ;
V_41 = F_66 ( V_7 , V_114 , V_157 , V_76 ,
0 , 0 , V_162 , V_177 , & V_128 ) ;
F_71 ( V_7 , NULL , V_116 , V_164 , NULL ) ;
return V_41 ;
V_179:
F_72 ( V_116 ) ;
return V_41 ;
}
static void F_73 ( struct V_127 * V_128 )
{
if ( ! V_128 -> V_137 ) {
F_12 ( V_128 -> V_7 , 0 ) ;
return;
}
F_12 ( V_128 -> V_7 ,
sizeof( struct V_180 ) *
V_128 -> V_137 ) ;
}
static void F_74 ( struct V_127 * V_128 )
{
struct V_180 * V_139 = V_128 -> V_16 ;
V_139 += V_128 -> V_137 ;
V_139 -> V_14 = V_181 ;
V_139 -> V_42 . V_182 = V_128 -> V_22 -> V_22 ;
V_139 -> V_42 . V_183 . V_8 = V_128 -> V_175 ;
V_139 -> V_42 . V_183 . V_9 = V_128 -> V_176 ;
V_139 -> V_42 . V_146 . V_142 = V_128 -> V_152 ;
V_139 -> V_42 . V_146 . V_144 = V_128 -> V_153 ;
V_139 -> V_42 . V_146 . V_143 = V_128 -> V_154 ;
V_139 -> V_42 . V_146 . V_145 = V_128 -> V_155 ;
V_128 -> V_137 ++ ;
}
int F_75 ( struct V_6 * V_7 ,
struct V_81 * V_82 ,
struct V_56 * V_57 ,
struct V_184 T_7 * V_185 ,
struct V_75 * V_76 ,
T_1 V_162 )
{
struct V_115 * V_116 =
F_59 ( V_57 , struct V_117 , V_3 ) -> V_17 ;
struct V_127 V_128 ;
int V_41 ;
V_41 = F_70 ( V_7 , V_116 , true , false ) ;
if ( V_41 )
return V_41 ;
V_41 = F_58 ( V_7 , V_57 ) ;
if ( F_9 ( V_41 != 0 ) )
goto V_179;
V_128 . V_169 = F_73 ;
V_128 . V_170 = F_74 ;
V_128 . V_171 = sizeof( struct V_180 ) *
V_162 ;
V_41 = F_66 ( V_7 , V_57 , NULL , V_76 ,
0 , 0 , V_162 , 1 , & V_128 ) ;
F_71 ( V_7 , V_82 , V_116 , NULL ,
V_185 ) ;
return V_41 ;
V_179:
F_72 ( V_116 ) ;
return V_41 ;
}
