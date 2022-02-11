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
if ( V_2 -> V_3 . V_31 &&
V_7 -> V_64 && V_57 &&
! ( V_7 -> V_65 == 1 &&
V_2 -> V_3 . V_66 ) &&
V_7 -> V_64 != V_57 ) {
F_10 ( L_5 ) ;
return - V_60 ;
}
V_53 = & V_2 -> V_3 . V_53 ;
V_55 = & V_2 -> V_3 . V_55 ;
if ( V_51 -> V_62 == 0 || ! V_51 -> V_11 || ! V_51 -> V_59 ) {
V_41 = F_13 ( V_7 , V_2 ) ;
if ( F_9 ( V_41 != 0 ) )
return V_41 ;
V_53 -> V_55 = NULL ;
V_55 -> V_5 = NULL ;
V_5 -> V_67 -> V_59 = NULL ;
V_5 -> V_8 = 0 ;
V_5 -> V_9 = 0 ;
V_5 -> V_68 = false ;
F_25 ( V_7 , & V_2 -> V_3 ) ;
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
F_26 ( V_7 ) ;
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
V_5 -> V_67 -> V_59 = NULL ;
V_5 -> V_8 = 0 ;
V_5 -> V_9 = 0 ;
V_5 -> V_68 = false ;
return V_41 ;
}
F_27 ( V_7 , & V_2 -> V_3 , V_57 ) ;
V_53 -> V_55 = V_55 ;
V_55 -> V_5 = V_5 ;
V_5 -> V_11 = * V_11 ;
V_5 -> V_67 -> V_59 = V_59 ;
V_5 -> V_8 = V_51 -> V_8 ;
V_5 -> V_9 = V_51 -> V_9 ;
V_5 -> V_68 = true ;
return 0 ;
}
static int F_28 ( struct V_4 * V_5 ,
struct V_58 * V_59 ,
struct V_69 * V_70 ,
T_1 V_23 )
{
struct V_6 * V_7 = F_24 ( V_5 -> V_61 ) ;
struct V_58 * V_71 = V_5 -> V_67 -> V_59 ;
struct V_56 * V_57 = F_23 ( V_59 ) ;
struct V_72 * V_73 = NULL ;
struct V_74 V_75 ;
int V_41 ;
if ( ! F_29 ( V_7 , V_5 ) )
return - V_60 ;
V_5 -> V_67 -> V_59 = V_59 ;
V_75 . V_8 = V_5 -> V_8 ;
V_75 . V_9 = V_5 -> V_9 ;
V_75 . V_76 = V_5 -> V_11 . V_28 ;
V_75 . V_77 = V_5 -> V_11 . V_30 ;
if ( V_57 -> V_78 )
V_41 = F_30 ( V_7 , V_57 ,
NULL , & V_75 , 1 , 1 ,
true , & V_73 ) ;
else
V_41 = F_31 ( V_7 , V_57 ,
NULL , & V_75 , NULL ,
0 , 0 , 1 , 1 , & V_73 ) ;
if ( V_41 != 0 )
goto V_79;
if ( ! V_73 ) {
V_41 = - V_60 ;
goto V_79;
}
if ( V_70 ) {
struct V_80 * V_81 = V_70 -> V_3 . V_81 ;
V_41 = F_32 ( V_81 , V_73 ,
& V_70 -> V_3 ,
& V_70 -> V_70 . V_82 ,
& V_70 -> V_70 . V_83 ,
true ) ;
}
F_33 ( & V_73 ) ;
if ( F_34 ( V_5 ) -> V_31 )
F_35 ( V_7 , V_5 ) ;
return V_41 ;
V_79:
V_5 -> V_67 -> V_59 = V_71 ;
return V_41 ;
}
static void F_36 ( struct V_54 * V_55 )
{
F_1 ( F_37 ( V_55 ) ) ;
}
static void F_38 ( struct V_52 * V_53 )
{
F_1 ( F_39 ( V_53 ) ) ;
}
static int F_40 ( struct V_6 * V_7 , unsigned V_22 )
{
struct V_1 * V_2 ;
struct V_84 * V_61 = V_7 -> V_61 ;
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
V_2 -> V_3 . V_66 = false ;
V_2 -> V_3 . V_85 = ( V_22 == 0 ) ;
V_2 -> V_3 . V_86 = V_7 -> V_87 ;
V_2 -> V_3 . V_88 = V_7 -> V_89 ;
V_2 -> V_3 . V_90 = NULL ;
V_2 -> V_3 . V_31 = false ;
F_41 ( V_61 , V_53 , & V_91 ,
V_92 ) ;
V_53 -> V_93 = F_42 ( V_53 , true ) ;
F_43 ( V_61 , V_55 , & V_94 ,
V_95 , NULL ) ;
F_44 ( V_53 , V_55 ) ;
V_55 -> V_96 = ( 1 << V_22 ) ;
V_55 -> V_97 = 0 ;
( void ) F_45 ( V_53 ) ;
F_46 ( V_61 , V_5 , & V_98 ) ;
F_47 ( V_5 , 256 ) ;
F_48 ( & V_53 -> V_3 ,
V_61 -> V_99 . V_100 ,
1 ) ;
F_48 ( & V_53 -> V_3 ,
V_7 -> V_101 , 1 ) ;
F_48 ( & V_53 -> V_3 ,
V_61 -> V_99 . V_102 , 0 ) ;
F_48 ( & V_53 -> V_3 ,
V_61 -> V_99 . V_103 , 0 ) ;
if ( V_7 -> V_104 )
F_48
( & V_53 -> V_3 ,
V_7 -> V_104 ,
V_2 -> V_3 . V_31 ) ;
return 0 ;
}
int F_49 ( struct V_6 * V_7 )
{
struct V_84 * V_61 = V_7 -> V_61 ;
int V_105 , V_41 ;
if ( ! ( V_7 -> V_106 & V_107 ) ) {
F_50 ( L_7
L_8 ) ;
return - V_108 ;
}
V_41 = - V_18 ;
V_7 -> V_65 = 0 ;
V_7 -> V_64 = NULL ;
V_41 = F_51 ( V_61 , V_109 ) ;
if ( F_9 ( V_41 != 0 ) )
return V_41 ;
V_41 = F_52 ( V_61 ) ;
if ( F_9 ( V_41 != 0 ) )
goto V_110;
F_53 ( V_7 , false ) ;
for ( V_105 = 0 ; V_105 < V_109 ; ++ V_105 )
F_40 ( V_7 , V_105 ) ;
V_7 -> V_111 = V_112 ;
F_50 ( L_9 ) ;
return 0 ;
V_110:
F_54 ( V_61 ) ;
return V_41 ;
}
int F_55 ( struct V_6 * V_7 )
{
struct V_84 * V_61 = V_7 -> V_61 ;
F_54 ( V_61 ) ;
return 0 ;
}
static int F_56 ( struct V_6 * V_7 ,
struct V_56 * V_113 )
{
struct V_114 * V_115 =
F_57 ( V_113 , struct V_116 ,
V_3 ) -> V_17 ;
int V_117 = V_113 -> V_3 . V_117 ;
struct {
T_1 V_14 ;
T_5 V_42 ;
} * V_16 ;
if ( V_117 == 32 )
V_117 = 24 ;
V_16 = F_8 ( V_7 , sizeof( * V_16 ) ) ;
if ( ! V_16 ) {
F_10 ( L_10 ) ;
return - V_18 ;
}
V_16 -> V_14 = V_118 ;
V_16 -> V_42 . V_119 . V_120 = V_113 -> V_3 . V_121 ;
V_16 -> V_42 . V_119 . V_122 = V_117 ;
V_16 -> V_42 . V_119 . V_123 = 0 ;
V_16 -> V_42 . V_124 = V_113 -> V_3 . V_125 [ 0 ] ;
F_11 ( & V_115 -> V_3 , & V_16 -> V_42 . V_38 ) ;
F_12 ( V_7 , sizeof( * V_16 ) ) ;
return 0 ;
}
static void F_58 ( struct V_126 * V_127 )
{
struct V_128 * V_129 =
F_57 ( V_127 , F_59 ( * V_129 ) , V_3 ) ;
struct V_130 * V_16 = V_127 -> V_16 ;
T_6 V_131 = V_127 -> V_22 -> V_5 . V_8 - V_129 -> V_132 ;
T_6 V_133 = V_127 -> V_22 -> V_5 . V_9 - V_129 -> V_134 ;
T_2 V_135 = V_127 -> V_136 * sizeof( V_137 ) ;
V_137 * V_138 = ( V_137 * ) & V_16 [ 1 ] ;
int V_105 ;
if ( ! V_127 -> V_136 ) {
F_12 ( V_127 -> V_7 , 0 ) ;
return;
}
V_16 -> V_14 . V_21 = V_139 ;
V_16 -> V_14 . V_26 = sizeof( V_16 -> V_42 ) + V_135 ;
V_16 -> V_42 . V_140 . V_141 = V_129 -> V_141 ;
V_16 -> V_42 . V_140 . V_142 = V_129 -> V_142 ;
V_16 -> V_42 . V_140 . V_143 = V_129 -> V_143 ;
V_16 -> V_42 . V_140 . V_144 = V_129 -> V_144 ;
V_16 -> V_42 . V_145 . V_141 = V_129 -> V_141 + V_131 ;
V_16 -> V_42 . V_145 . V_142 = V_129 -> V_142 + V_131 ;
V_16 -> V_42 . V_145 . V_143 = V_129 -> V_143 + V_133 ;
V_16 -> V_42 . V_145 . V_144 = V_129 -> V_144 + V_133 ;
V_16 -> V_42 . V_146 . V_147 = V_129 -> V_147 ;
V_16 -> V_42 . V_148 = V_127 -> V_22 -> V_22 ;
for ( V_105 = 0 ; V_105 < V_127 -> V_136 ; ++ V_105 , ++ V_138 ) {
V_138 -> V_141 -= V_129 -> V_141 ;
V_138 -> V_142 -= V_129 -> V_141 ;
V_138 -> V_143 -= V_129 -> V_143 ;
V_138 -> V_144 -= V_129 -> V_143 ;
}
F_12 ( V_127 -> V_7 , V_135 + sizeof( * V_16 ) ) ;
V_129 -> V_141 = V_129 -> V_143 = V_149 ;
V_129 -> V_142 = V_129 -> V_144 = V_150 ;
}
static void F_60 ( struct V_126 * V_127 )
{
struct V_128 * V_129 =
F_57 ( V_127 , F_59 ( * V_129 ) , V_3 ) ;
struct V_130 * V_16 = V_127 -> V_16 ;
V_137 * V_138 = ( V_137 * ) & V_16 [ 1 ] ;
V_138 += V_127 -> V_136 ;
V_138 -> V_141 = V_127 -> V_151 ;
V_138 -> V_143 = V_127 -> V_152 ;
V_138 -> V_142 = V_127 -> V_153 ;
V_138 -> V_144 = V_127 -> V_154 ;
V_129 -> V_141 = F_61 ( T_6 , V_129 -> V_141 , V_127 -> V_151 ) ;
V_129 -> V_143 = F_61 ( T_6 , V_129 -> V_143 , V_127 -> V_152 ) ;
V_129 -> V_142 = F_62 ( T_6 , V_129 -> V_142 , V_127 -> V_153 ) ;
V_129 -> V_144 = F_62 ( T_6 , V_129 -> V_144 , V_127 -> V_154 ) ;
V_127 -> V_136 ++ ;
}
int F_31 ( struct V_6 * V_7 ,
struct V_56 * V_113 ,
struct V_155 * V_156 ,
struct V_74 * V_75 ,
struct V_157 * V_158 ,
T_6 V_159 ,
T_6 V_160 ,
unsigned V_161 , int V_162 ,
struct V_72 * * V_163 )
{
struct V_164 * V_165 =
F_57 ( V_113 , F_59 ( * V_165 ) , V_3 ) ;
struct V_128 V_129 ;
int V_41 ;
if ( ! V_158 )
V_158 = & V_165 -> V_166 -> V_167 ;
V_41 = F_63 ( V_158 , true ) ;
if ( V_41 )
return V_41 ;
V_129 . V_3 . V_168 = F_58 ;
V_129 . V_3 . V_169 = F_60 ;
V_129 . V_3 . V_7 = V_7 ;
V_129 . V_3 . V_170 = sizeof( struct V_130 ) +
sizeof( V_137 ) * V_161 ;
V_129 . V_147 = V_158 -> V_21 ;
V_129 . V_141 = V_129 . V_143 = V_149 ;
V_129 . V_142 = V_129 . V_144 = V_150 ;
V_129 . V_132 = V_159 ;
V_129 . V_134 = V_160 ;
V_41 = F_64 ( V_7 , V_113 , V_156 , V_75 ,
V_159 , V_160 , V_161 , V_162 ,
& V_129 . V_3 ) ;
F_65 ( V_158 , V_163 ) ;
return V_41 ;
}
static void F_66 ( struct V_126 * V_127 )
{
if ( ! V_127 -> V_136 ) {
F_12 ( V_127 -> V_7 , 0 ) ;
return;
}
F_12 ( V_127 -> V_7 ,
sizeof( struct V_171 ) *
V_127 -> V_136 ) ;
}
static void F_67 ( struct V_126 * V_127 )
{
struct V_171 * V_138 = V_127 -> V_16 ;
V_138 += V_127 -> V_136 ;
V_138 -> V_14 = V_172 ;
V_138 -> V_42 . V_148 = V_127 -> V_22 -> V_22 ;
V_138 -> V_42 . V_173 . V_8 = V_127 -> V_174 ;
V_138 -> V_42 . V_173 . V_9 = V_127 -> V_175 ;
V_138 -> V_42 . V_140 . V_141 = V_127 -> V_151 ;
V_138 -> V_42 . V_140 . V_143 = V_127 -> V_152 ;
V_138 -> V_42 . V_140 . V_142 = V_127 -> V_153 ;
V_138 -> V_42 . V_140 . V_144 = V_127 -> V_154 ;
V_127 -> V_136 ++ ;
}
int F_30 ( struct V_6 * V_7 ,
struct V_56 * V_113 ,
struct V_155 * V_156 ,
struct V_74 * V_75 ,
unsigned V_161 , int V_176 ,
bool V_177 ,
struct V_72 * * V_163 )
{
struct V_114 * V_115 =
F_57 ( V_113 , struct V_116 ,
V_3 ) -> V_17 ;
struct V_126 V_127 ;
int V_41 ;
V_41 = F_68 ( V_7 , V_115 , V_177 ,
false ) ;
if ( V_41 )
return V_41 ;
V_41 = F_56 ( V_7 , V_113 ) ;
if ( F_9 ( V_41 != 0 ) )
goto V_178;
V_127 . V_168 = F_66 ;
V_127 . V_169 = F_67 ;
V_127 . V_170 = sizeof( struct V_171 ) *
V_161 ;
V_41 = F_64 ( V_7 , V_113 , V_156 , V_75 ,
0 , 0 , V_161 , V_176 , & V_127 ) ;
F_69 ( V_7 , NULL , V_115 , V_163 , NULL ) ;
return V_41 ;
V_178:
F_70 ( V_115 ) ;
return V_41 ;
}
static void F_71 ( struct V_126 * V_127 )
{
if ( ! V_127 -> V_136 ) {
F_12 ( V_127 -> V_7 , 0 ) ;
return;
}
F_12 ( V_127 -> V_7 ,
sizeof( struct V_179 ) *
V_127 -> V_136 ) ;
}
static void F_72 ( struct V_126 * V_127 )
{
struct V_179 * V_138 = V_127 -> V_16 ;
V_138 += V_127 -> V_136 ;
V_138 -> V_14 = V_180 ;
V_138 -> V_42 . V_181 = V_127 -> V_22 -> V_22 ;
V_138 -> V_42 . V_182 . V_8 = V_127 -> V_174 ;
V_138 -> V_42 . V_182 . V_9 = V_127 -> V_175 ;
V_138 -> V_42 . V_145 . V_141 = V_127 -> V_151 ;
V_138 -> V_42 . V_145 . V_143 = V_127 -> V_152 ;
V_138 -> V_42 . V_145 . V_142 = V_127 -> V_153 ;
V_138 -> V_42 . V_145 . V_144 = V_127 -> V_154 ;
V_127 -> V_136 ++ ;
}
int F_73 ( struct V_6 * V_7 ,
struct V_80 * V_81 ,
struct V_56 * V_57 ,
struct V_183 T_7 * V_184 ,
struct V_74 * V_75 ,
T_1 V_161 )
{
struct V_114 * V_115 =
F_57 ( V_57 , struct V_116 , V_3 ) -> V_17 ;
struct V_126 V_127 ;
int V_41 ;
V_41 = F_68 ( V_7 , V_115 , true , false ) ;
if ( V_41 )
return V_41 ;
V_41 = F_56 ( V_7 , V_57 ) ;
if ( F_9 ( V_41 != 0 ) )
goto V_178;
V_127 . V_168 = F_71 ;
V_127 . V_169 = F_72 ;
V_127 . V_170 = sizeof( struct V_179 ) *
V_161 ;
V_41 = F_64 ( V_7 , V_57 , NULL , V_75 ,
0 , 0 , V_161 , 1 , & V_127 ) ;
F_69 ( V_7 , V_81 , V_115 , NULL ,
V_184 ) ;
return V_41 ;
V_178:
F_70 ( V_115 ) ;
return V_41 ;
}
