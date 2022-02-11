static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_8 ;
memset ( & V_4 -> V_6 , 0 , sizeof( V_4 -> V_6 ) ) ;
F_3 ( & V_6 -> V_9 ) ;
if ( F_4 ( V_6 -> V_10 || V_6 -> V_11 ) )
return - V_12 ;
V_6 -> V_10 = F_5 ( V_8 , sizeof( V_13 ) * V_14 ,
& V_6 -> V_15 , V_16 ) ;
if ( ! V_6 -> V_10 )
goto V_17;
V_6 -> V_11 = F_5 ( V_8 , sizeof( * V_6 -> V_11 ) ,
& V_6 -> V_18 , V_16 ) ;
if ( ! V_6 -> V_11 )
goto V_19;
return 0 ;
V_19:
F_6 ( V_8 , sizeof( V_13 ) * V_14 ,
V_6 -> V_10 , V_6 -> V_15 ) ;
memset ( & V_6 -> V_15 , 0 , sizeof( V_6 -> V_15 ) ) ;
V_6 -> V_10 = NULL ;
V_17:
return - V_20 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 + V_14 ; V_21 ++ ) {
if ( V_6 -> V_23 [ V_21 ] . V_24 != NULL ) {
F_8 ( V_2 -> V_8 , V_6 -> V_23 [ V_21 ] . V_25 ,
V_26 << F_9 ( V_2 ) . V_27 ,
V_28 ) ;
F_10 ( V_6 -> V_23 [ V_21 ] . V_24 ,
F_9 ( V_2 ) . V_27 ) ;
V_6 -> V_23 [ V_21 ] . V_24 = NULL ;
}
F_11 ( & V_6 -> V_23 [ V_21 ] . V_29 , & V_6 -> V_30 ) ;
}
}
static void F_12 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_31 ;
const T_1 V_32 = V_33 ;
T_1 V_34 = V_35 ;
if ( V_36 . V_37 )
V_31 = V_38 ;
else
V_31 = V_39 ;
F_13 ( V_2 , V_40 , 0 ) ;
F_13 ( V_2 , V_41 , 0 ) ;
F_13 ( V_2 , V_42 ,
( T_1 ) ( V_6 -> V_15 >> 8 ) ) ;
F_13 ( V_2 , V_43 ,
V_6 -> V_18 >> 4 ) ;
F_13 ( V_2 , V_40 ,
V_44 |
V_45 |
V_46 |
V_47 |
V_31 |
( V_34 << V_48 ) |
( V_32 << V_49 ) ) ;
F_14 ( V_2 , V_50 , V_51 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_21 , V_52 ;
unsigned long V_53 ;
if ( ! V_6 -> V_10 ) {
V_52 = F_1 ( V_2 ) ;
if ( V_52 )
return V_52 ;
}
F_16 ( & V_6 -> V_9 , V_53 ) ;
F_17 ( & V_6 -> V_54 ) ;
F_17 ( & V_6 -> V_30 ) ;
F_7 ( V_2 ) ;
for ( V_21 = 0 ; V_21 < V_14 ; V_21 ++ )
V_6 -> V_55 [ V_21 ] = NULL ;
V_6 -> V_56 = V_6 -> V_57 = 0 ;
V_6 -> V_58 = 0 ;
V_6 -> V_59 = 0 ;
F_18 ( & V_6 -> V_9 , V_53 ) ;
F_19 ( V_2 ) ;
F_12 ( V_2 , V_6 ) ;
F_16 ( & V_4 -> V_60 , V_53 ) ;
V_6 -> V_61 = 1 ;
F_20 ( V_2 , V_6 ) ;
F_18 ( & V_4 -> V_60 , V_53 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
unsigned long V_53 ;
if ( ! V_6 -> V_10 ) {
F_22 ( V_2 , L_1 ) ;
return;
}
F_16 ( & V_6 -> V_9 , V_53 ) ;
F_7 ( V_2 ) ;
F_18 ( & V_6 -> V_9 , V_53 ) ;
F_6 ( V_2 -> V_8 , sizeof( V_13 ) * V_14 ,
V_6 -> V_10 , V_6 -> V_15 ) ;
memset ( & V_6 -> V_15 , 0 , sizeof( V_6 -> V_15 ) ) ;
V_6 -> V_10 = NULL ;
if ( V_6 -> V_11 )
F_6 ( V_2 -> V_8 ,
sizeof( struct V_62 ) ,
V_6 -> V_11 , V_6 -> V_18 ) ;
else
F_22 ( V_2 , L_2 ) ;
memset ( & V_6 -> V_18 , 0 , sizeof( V_6 -> V_18 ) ) ;
V_6 -> V_11 = NULL ;
}
static int F_23 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_40 , 0 ) ;
return F_24 ( V_2 , V_63 ,
V_64 , 1000 ) ;
}
static inline int F_25 ( struct V_1 * V_2 ,
struct V_65 * V_66 , T_2 V_67 )
{
if ( F_4 ( V_66 -> V_68 ) )
return - V_12 ;
V_66 -> V_68 = F_26 ( V_2 -> V_8 , V_67 ,
& V_66 -> V_69 , V_16 ) ;
if ( ! V_66 -> V_68 )
return - V_20 ;
V_66 -> V_67 = V_67 ;
return 0 ;
}
static inline void F_27 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
if ( F_28 ( ! V_66 -> V_68 ) )
return;
F_6 ( V_2 -> V_8 , V_66 -> V_67 , V_66 -> V_68 , V_66 -> V_69 ) ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_70 * V_71 , int V_72 ,
T_1 V_73 )
{
T_2 V_74 = sizeof( struct V_75 ) * V_76 ;
int V_21 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_4 ( V_71 -> V_77 || V_71 -> V_78 || V_71 -> V_79 || V_71 -> V_80 ) )
return - V_12 ;
V_71 -> V_81 . V_82 = V_72 ;
V_71 -> V_77 = F_30 ( V_72 , sizeof( V_71 -> V_77 [ 0 ] ) , V_16 ) ;
V_71 -> V_78 = F_30 ( V_72 , sizeof( V_71 -> V_78 [ 0 ] ) , V_16 ) ;
if ( ! V_71 -> V_77 || ! V_71 -> V_78 )
goto error;
if ( V_73 == V_4 -> V_83 )
for ( V_21 = 0 ; V_21 < V_72 ; V_21 ++ ) {
V_71 -> V_78 [ V_21 ] = F_31 ( sizeof( struct V_84 ) ,
V_16 ) ;
if ( ! V_71 -> V_78 [ V_21 ] )
goto error;
}
if ( V_73 != V_4 -> V_83 ) {
V_71 -> V_79 = F_30 ( V_76 , sizeof( V_71 -> V_79 [ 0 ] ) ,
V_16 ) ;
if ( ! V_71 -> V_79 ) {
F_32 ( V_2 , L_3
L_4 ) ;
goto error;
}
} else {
V_71 -> V_79 = NULL ;
}
V_71 -> V_80 = F_26 ( V_2 -> V_8 , V_74 ,
& V_71 -> V_81 . V_85 , V_16 ) ;
if ( ! V_71 -> V_80 ) {
F_32 ( V_2 , L_5 , V_74 ) ;
goto error;
}
V_71 -> V_81 . V_86 = V_73 ;
return 0 ;
error:
F_33 ( V_71 -> V_79 ) ;
V_71 -> V_79 = NULL ;
if ( V_71 -> V_78 && V_73 == V_4 -> V_83 )
for ( V_21 = 0 ; V_21 < V_72 ; V_21 ++ )
F_33 ( V_71 -> V_78 [ V_21 ] ) ;
F_33 ( V_71 -> V_77 ) ;
F_33 ( V_71 -> V_78 ) ;
V_71 -> V_77 = NULL ;
V_71 -> V_78 = NULL ;
return - V_20 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_70 * V_71 ,
int V_72 , T_1 V_73 )
{
int V_87 ;
V_71 -> V_61 = 0 ;
memset ( V_71 -> V_77 , 0 , sizeof( V_71 -> V_77 [ 0 ] ) * V_72 ) ;
if ( V_73 < 4 )
F_35 ( V_71 , V_73 , V_73 ) ;
F_36 ( V_76 & ( V_76 - 1 ) ) ;
V_87 = F_37 ( & V_71 -> V_81 , V_76 , V_72 ,
V_73 ) ;
if ( V_87 )
return V_87 ;
F_3 ( & V_71 -> V_9 ) ;
F_13 ( V_2 , F_38 ( V_73 ) ,
V_71 -> V_81 . V_85 >> 8 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 , int V_73 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 = & V_4 -> V_71 [ V_73 ] ;
struct V_88 * V_81 = & V_71 -> V_81 ;
enum V_89 V_90 ;
if ( ! V_81 -> V_91 )
return;
if ( V_73 == V_4 -> V_83 )
V_90 = V_92 ;
else
V_90 = V_93 ;
F_40 ( & V_71 -> V_9 ) ;
while ( V_81 -> V_94 != V_81 -> V_95 ) {
F_41 ( V_2 , V_71 , F_42 ( V_81 , V_81 -> V_95 ) ,
V_90 ) ;
V_81 -> V_95 = F_43 ( V_81 -> V_95 , V_81 -> V_91 ) ;
}
F_44 ( & V_71 -> V_9 ) ;
}
static void F_45 ( struct V_1 * V_2 , int V_73 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 = & V_4 -> V_71 [ V_73 ] ;
struct V_7 * V_8 = V_2 -> V_8 ;
int V_21 ;
if ( F_4 ( ! V_71 ) )
return;
F_39 ( V_2 , V_73 ) ;
if ( V_73 == V_4 -> V_83 )
for ( V_21 = 0 ; V_21 < V_71 -> V_81 . V_82 ; V_21 ++ )
F_33 ( V_71 -> V_78 [ V_21 ] ) ;
if ( V_71 -> V_81 . V_91 ) {
F_6 ( V_8 , sizeof( struct V_75 ) *
V_71 -> V_81 . V_91 , V_71 -> V_80 , V_71 -> V_81 . V_85 ) ;
memset ( & V_71 -> V_81 . V_85 , 0 , sizeof( V_71 -> V_81 . V_85 ) ) ;
}
F_33 ( V_71 -> V_79 ) ;
V_71 -> V_79 = NULL ;
F_33 ( V_71 -> V_78 ) ;
F_33 ( V_71 -> V_77 ) ;
V_71 -> V_78 = NULL ;
V_71 -> V_77 = NULL ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
int V_73 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_71 ) {
for ( V_73 = 0 ;
V_73 < F_47 ( V_2 ) -> V_96 -> V_97 ; V_73 ++ )
F_45 ( V_2 , V_73 ) ;
}
F_33 ( V_4 -> V_71 ) ;
V_4 -> V_71 = NULL ;
F_27 ( V_2 , & V_4 -> V_98 ) ;
F_27 ( V_2 , & V_4 -> V_99 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_87 ;
int V_73 , V_72 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_3 V_100 = F_47 ( V_2 ) -> V_96 -> V_97 *
sizeof( struct V_101 ) ;
if ( F_4 ( V_4 -> V_71 ) ) {
V_87 = - V_12 ;
goto error;
}
V_87 = F_25 ( V_2 , & V_4 -> V_99 ,
V_100 ) ;
if ( V_87 ) {
F_32 ( V_2 , L_6 ) ;
goto error;
}
V_87 = F_25 ( V_2 , & V_4 -> V_98 , V_102 ) ;
if ( V_87 ) {
F_32 ( V_2 , L_7 ) ;
goto error;
}
V_4 -> V_71 = F_30 ( F_47 ( V_2 ) -> V_96 -> V_97 ,
sizeof( struct V_70 ) , V_16 ) ;
if ( ! V_4 -> V_71 ) {
F_32 ( V_2 , L_8 ) ;
V_87 = V_20 ;
goto error;
}
for ( V_73 = 0 ; V_73 < F_47 ( V_2 ) -> V_96 -> V_97 ;
V_73 ++ ) {
V_72 = ( V_73 == V_4 -> V_83 ) ?
V_103 : V_104 ;
V_87 = F_29 ( V_2 , & V_4 -> V_71 [ V_73 ] ,
V_72 , V_73 ) ;
if ( V_87 ) {
F_32 ( V_2 , L_9 , V_73 ) ;
goto error;
}
}
return 0 ;
error:
F_46 ( V_2 ) ;
return V_87 ;
}
static int F_49 ( struct V_1 * V_2 )
{
int V_87 ;
int V_73 , V_72 ;
unsigned long V_53 ;
bool V_105 = false ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_71 ) {
V_87 = F_48 ( V_2 ) ;
if ( V_87 )
goto error;
V_105 = true ;
}
F_16 ( & V_4 -> V_60 , V_53 ) ;
F_50 ( V_2 , V_106 , 0 ) ;
F_13 ( V_2 , V_107 ,
V_4 -> V_98 . V_69 >> 4 ) ;
F_18 ( & V_4 -> V_60 , V_53 ) ;
for ( V_73 = 0 ; V_73 < F_47 ( V_2 ) -> V_96 -> V_97 ;
V_73 ++ ) {
V_72 = ( V_73 == V_4 -> V_83 ) ?
V_103 : V_104 ;
V_87 = F_34 ( V_2 , & V_4 -> V_71 [ V_73 ] ,
V_72 , V_73 ) ;
if ( V_87 ) {
F_32 ( V_2 , L_10 , V_73 ) ;
goto error;
}
}
return 0 ;
error:
if ( V_105 )
F_46 ( V_2 ) ;
return V_87 ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_52 ( V_2 , V_108 ,
V_109 ,
~ V_110 ) ;
}
static T_3 F_53 ( struct V_1 * V_2 )
{
int V_111 ;
T_3 V_112 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_113 * V_113 = V_4 -> V_113 ;
V_111 = F_54 ( V_113 ) ;
F_55 ( V_113 , V_111 + V_114 , & V_112 ) ;
return V_112 ;
}
static void F_56 ( struct V_1 * V_2 )
{
T_3 V_115 = F_53 ( V_2 ) ;
if ( ( V_115 & V_116 ) ==
V_116 ) {
F_57 ( V_2 , V_117 , V_118 ) ;
F_58 ( V_119 , V_2 -> V_8 ,
L_11 ) ;
} else {
F_59 ( V_2 , V_117 , V_118 ) ;
F_58 ( V_119 , V_2 -> V_8 ,
L_12 ) ;
}
V_2 -> V_120 = ! ( V_115 & V_121 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_87 = 0 ;
F_22 ( V_2 , L_13 ) ;
F_57 ( V_2 , V_122 ,
V_123 ) ;
F_57 ( V_2 , V_122 ,
V_124 ) ;
F_57 ( V_2 , V_125 , V_126 ) ;
F_57 ( V_2 , V_127 ,
V_128 ) ;
F_56 ( V_2 ) ;
if ( F_47 ( V_2 ) -> V_96 -> V_129 )
F_57 ( V_2 , V_130 ,
F_47 ( V_2 ) -> V_96 -> V_129 ) ;
F_57 ( V_2 , V_131 , V_132 ) ;
V_87 = F_61 ( V_2 , V_131 ,
V_133 ,
V_133 , 25000 ) ;
if ( V_87 < 0 ) {
F_22 ( V_2 , L_14 ) ;
goto V_134;
}
F_50 ( V_2 , V_135 , V_136 ) ;
F_62 ( 20 ) ;
F_63 ( V_2 , V_137 ,
V_138 ) ;
F_64 ( V_139 , & V_4 -> V_140 ) ;
V_134:
return V_87 ;
}
static int F_65 ( struct V_1 * V_2 )
{
int V_87 = 0 ;
F_57 ( V_2 , V_141 , V_142 ) ;
V_87 = F_61 ( V_2 , V_141 ,
V_143 ,
V_143 , 100 ) ;
if ( V_87 )
F_66 ( V_2 , L_15 ) ;
F_22 ( V_2 , L_16 ) ;
return V_87 ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_22 ( V_2 , L_17 ) ;
F_68 ( V_139 , & V_4 -> V_140 ) ;
F_65 ( V_2 ) ;
F_57 ( V_2 , V_141 , V_144 ) ;
F_62 ( 10 ) ;
F_59 ( V_2 , V_131 ,
V_132 ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_53 ;
F_16 ( & V_4 -> V_60 , V_53 ) ;
F_60 ( V_2 ) ;
F_14 ( V_2 , V_50 ,
V_145 ) ;
F_18 ( & V_4 -> V_60 , V_53 ) ;
F_51 ( V_2 ) ;
F_70 ( V_2 -> V_146 ) ;
#ifndef F_71
F_15 ( V_2 ) ;
#endif
if ( F_49 ( V_2 ) )
return - V_20 ;
if ( F_47 ( V_2 ) -> V_96 -> V_147 ) {
F_57 ( V_2 , V_148 ,
0x800FFFFF ) ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
int V_87 ;
F_57 ( V_2 , V_127 ,
V_149 ) ;
V_87 = F_61 ( V_2 , V_127 ,
V_149 ,
V_149 ,
V_150 ) ;
F_22 ( V_2 , L_18 , V_87 < 0 ? L_19 : L_20 ) ;
return V_87 ;
}
static int F_73 ( struct V_1 * V_2 )
{
int V_87 ;
F_22 ( V_2 , L_21 ) ;
V_87 = F_72 ( V_2 ) ;
if ( V_87 >= 0 )
return 0 ;
F_57 ( V_2 , V_127 ,
V_151 ) ;
V_87 = F_61 ( V_2 , V_127 ,
~ V_152 ,
V_152 , 150000 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 = F_72 ( V_2 ) ;
if ( V_87 >= 0 )
return 0 ;
return V_87 ;
}
static int F_74 ( struct V_1 * V_2 , T_4 V_153 ,
const struct V_154 * V_155 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_5 V_156 = V_155 -> V_157 ;
T_1 V_158 = V_155 -> V_159 ;
T_1 V_160 = V_155 -> V_161 ;
int V_87 ;
V_4 -> V_162 = false ;
F_13 ( V_2 ,
F_75 ( V_163 ) ,
V_164 ) ;
F_13 ( V_2 ,
F_76 ( V_163 ) , V_160 ) ;
F_13 ( V_2 ,
F_77 ( V_163 ) ,
V_156 & V_165 ) ;
F_13 ( V_2 ,
F_78 ( V_163 ) ,
( F_79 ( V_156 )
<< V_166 ) | V_158 ) ;
F_13 ( V_2 ,
F_80 ( V_163 ) ,
1 << V_167 |
1 << V_168 |
V_169 ) ;
F_13 ( V_2 ,
F_75 ( V_163 ) ,
V_170 |
V_171 |
V_172 ) ;
F_81 ( V_2 , L_22 ,
V_153 ) ;
V_87 = F_82 ( V_4 -> V_173 ,
V_4 -> V_162 , 5 * V_174 ) ;
if ( ! V_87 ) {
F_32 ( V_2 , L_23 ,
V_153 ) ;
return - V_175 ;
}
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
const struct V_176 * V_177 )
{
int V_87 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_178 ; V_21 ++ ) {
if ( ! V_177 -> V_179 [ V_21 ] . V_157 )
break;
V_87 = F_74 ( V_2 , V_21 , & V_177 -> V_179 [ V_21 ] ) ;
if ( V_87 )
return V_87 ;
}
F_84 ( V_2 , V_141 , 0 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 ,
const struct V_176 * V_180 )
{
int V_87 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
bool V_181 ;
V_4 -> V_182 [ V_183 ] = V_184 ;
V_4 -> V_182 [ V_185 ] = V_186 ;
V_4 -> V_187 [ V_183 ] = V_188 ;
V_4 -> V_187 [ V_185 ] = V_189 ;
V_4 -> V_190 [ V_183 ] = 0 ;
V_4 -> V_190 [ V_185 ] = V_191 ;
if ( F_73 ( V_2 ) ) {
F_66 ( V_2 , L_24 ) ;
return - V_192 ;
}
V_181 = ! ( F_86 ( V_2 , V_131 ) &
V_193 ) ;
F_87 ( V_2 -> V_146 , V_181 ) ;
if ( V_181 ) {
F_88 ( V_2 ) ;
return - V_194 ;
}
F_84 ( V_2 , V_195 , 0xFFFFFFFF ) ;
V_87 = F_69 ( V_2 ) ;
if ( V_87 ) {
F_32 ( V_2 , L_25 ) ;
return V_87 ;
}
F_84 ( V_2 , V_196 , V_197 ) ;
F_84 ( V_2 , V_196 ,
V_198 ) ;
F_84 ( V_2 , V_195 , 0xFFFFFFFF ) ;
F_89 ( V_2 ) ;
F_84 ( V_2 , V_196 , V_197 ) ;
F_84 ( V_2 , V_196 , V_197 ) ;
return F_83 ( V_2 , V_180 ) ;
}
static void F_90 ( struct V_1 * V_2 , T_1 V_199 )
{
struct V_3 T_6 * V_4 =
F_2 ( V_2 ) ;
F_91 ( & V_4 -> V_60 ) ;
F_50 ( V_2 , V_106 , V_199 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
const struct V_200 * V_201 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
T_1 V_202 ;
unsigned long V_53 ;
int V_21 , V_203 ;
T_1 V_204 ;
F_16 ( & V_4 -> V_60 , V_53 ) ;
V_4 -> V_205 =
F_93 ( V_2 , V_206 ) ;
V_202 = V_4 -> V_205 + V_207 ;
for (; V_202 < V_4 -> V_205 + V_208 ;
V_202 += 4 )
F_94 ( V_2 , V_202 , 0 ) ;
for (; V_202 < V_4 -> V_205 + V_209 ;
V_202 += 4 )
F_94 ( V_2 , V_202 , 0 ) ;
for (; V_202 < V_4 -> V_205 +
F_95 (
F_47 ( V_2 ) -> V_96 -> V_97 ) ;
V_202 += 4 )
F_94 ( V_2 , V_202 , 0 ) ;
F_50 ( V_2 , V_210 ,
V_4 -> V_99 . V_69 >> 10 ) ;
for ( V_203 = 0 ; V_203 < V_211 ; V_203 ++ )
F_13 ( V_2 , F_75 ( V_203 ) ,
V_170 |
V_212 ) ;
V_204 = F_96 ( V_2 , V_213 ) ;
F_13 ( V_2 , V_213 ,
V_204 | V_214 ) ;
F_50 ( V_2 , V_215 ,
F_97 ( V_2 , V_4 ) ) ;
F_50 ( V_2 , V_216 , 0 ) ;
for ( V_21 = 0 ; V_21 < F_47 ( V_2 ) -> V_96 -> V_97 ; V_21 ++ ) {
F_50 ( V_2 , F_98 ( V_21 ) , 0 ) ;
F_13 ( V_2 , V_217 , 0 | ( V_21 << 8 ) ) ;
F_94 ( V_2 , V_4 -> V_205 +
F_99 ( V_21 ) , 0 ) ;
F_94 ( V_2 , V_4 -> V_205 +
F_99 ( V_21 ) +
sizeof( T_1 ) ,
( ( V_218 <<
V_219 ) &
V_220 ) |
( ( V_221 <<
V_222 ) &
V_223 ) ) ;
}
F_50 ( V_2 , V_224 ,
F_100 ( 0 , F_47 ( V_2 ) -> V_96 -> V_97 ) ) ;
F_90 ( V_2 , F_100 ( 0 , 7 ) ) ;
if ( V_2 -> V_225 -> V_226 != F_101 ( V_183 ) )
V_201 = V_227 ;
else
V_201 = V_228 ;
F_102 ( V_2 , V_4 -> V_83 , 0 ) ;
memset ( & V_4 -> V_229 [ 0 ] , 0 ,
sizeof( V_4 -> V_229 ) ) ;
for ( V_21 = 0 ; V_21 < 4 ; V_21 ++ )
F_103 ( & V_4 -> V_230 [ V_21 ] , 0 ) ;
V_4 -> V_231 = 0 ;
F_36 ( F_104 ( V_228 ) <
V_232 ) ;
F_36 ( F_104 ( V_227 ) <
V_232 ) ;
for ( V_21 = 0 ; V_21 < V_232 ; V_21 ++ ) {
int V_233 = V_201 [ V_21 ] . V_233 ;
int V_234 = V_201 [ V_21 ] . V_234 ;
F_105 ( V_4 , V_21 ) ;
if ( V_233 == V_235 )
continue;
if ( V_234 != V_236 )
F_35 ( & V_4 -> V_71 [ V_21 ] , V_234 , V_21 ) ;
F_106 ( V_2 , & V_4 -> V_71 [ V_21 ] ,
V_233 , 0 ) ;
}
F_18 ( & V_4 -> V_60 , V_53 ) ;
F_107 ( V_2 , V_137 ,
V_138 ) ;
}
static void F_108 ( struct V_1 * V_2 )
{
F_109 ( V_2 ) ;
F_92 ( V_2 ) ;
}
static int F_110 ( struct V_1 * V_2 )
{
int V_237 , V_73 , V_87 ;
unsigned long V_53 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_16 ( & V_4 -> V_60 , V_53 ) ;
F_90 ( V_2 , 0 ) ;
for ( V_237 = 0 ; V_237 < V_211 ; V_237 ++ ) {
F_13 ( V_2 ,
F_75 ( V_237 ) , 0x0 ) ;
V_87 = F_24 ( V_2 , V_238 ,
F_111 ( V_237 ) ,
1000 ) ;
if ( V_87 < 0 )
F_32 ( V_2 , L_26
L_27 , V_237 ,
F_96 ( V_2 ,
V_238 ) ) ;
}
F_18 ( & V_4 -> V_60 , V_53 ) ;
if ( ! V_4 -> V_71 ) {
F_66 ( V_2 , L_28 ) ;
return 0 ;
}
for ( V_73 = 0 ; V_73 < F_47 ( V_2 ) -> V_96 -> V_97 ;
V_73 ++ )
F_39 ( V_2 , V_73 ) ;
return 0 ;
}
static void F_112 ( struct V_1 * V_2 )
{
unsigned long V_53 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_16 ( & V_4 -> V_60 , V_53 ) ;
F_113 ( V_2 ) ;
F_18 ( & V_4 -> V_60 , V_53 ) ;
F_114 ( V_2 ) ;
if ( F_115 ( V_139 , & V_4 -> V_140 ) ) {
F_110 ( V_2 ) ;
#ifndef F_71
F_23 ( V_2 ) ;
#endif
F_50 ( V_2 , V_239 ,
V_136 ) ;
F_62 ( 5 ) ;
}
F_59 ( V_2 , V_131 ,
V_240 ) ;
F_67 ( V_2 ) ;
F_16 ( & V_4 -> V_60 , V_53 ) ;
F_113 ( V_2 ) ;
F_18 ( & V_4 -> V_60 , V_53 ) ;
F_116 ( V_4 -> V_241 ) ;
F_117 ( & V_4 -> V_242 ) ;
F_118 ( & V_4 -> V_243 ) ;
F_84 ( V_2 , V_141 , V_244 ) ;
}
static void F_119 ( struct V_1 * V_2 )
{
F_84 ( V_2 , V_245 ,
V_246 ) ;
F_113 ( V_2 ) ;
F_59 ( V_2 , V_131 ,
V_240 ) ;
}
static int F_120 ( struct V_1 * V_2 , struct V_247 * V_248 ,
struct V_84 * V_249 , enum V_250 V_251 ,
T_4 V_252 , T_4 V_253 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_254 * V_255 = (struct V_254 * ) V_248 -> V_256 ;
struct V_257 * V_258 = F_121 ( V_248 ) ;
struct V_259 * V_260 = (struct V_259 * ) V_249 -> V_261 ;
struct V_262 * V_263 ;
struct V_70 * V_71 ;
struct V_88 * V_81 ;
T_5 V_264 = 0 ;
T_5 V_265 ;
T_5 V_266 ;
T_3 V_159 , V_267 , V_268 ;
T_4 V_269 = 0 ;
T_4 V_73 ;
bool V_270 = false ;
T_7 V_271 = V_255 -> V_272 ;
T_4 V_273 = F_122 ( V_271 ) ;
T_3 T_6 V_274 ;
if ( V_258 -> V_53 & V_275 ) {
V_73 = V_4 -> V_190 [ V_251 ] ;
V_255 -> V_272 |=
F_123 ( V_276 ) ;
} else if ( V_258 -> V_53 & V_277 )
V_73 = V_278 ;
else
V_73 =
V_4 -> V_182 [ V_251 ] [ F_124 ( V_248 ) ] ;
if ( V_258 -> V_53 & V_279 ) {
F_4 ( V_253 >= V_280 ) ;
V_73 = V_4 -> V_281 [ V_252 ] [ V_253 ] ;
V_270 = true ;
}
V_71 = & V_4 -> V_71 [ V_73 ] ;
V_81 = & V_71 -> V_81 ;
F_125 ( & V_71 -> V_9 ) ;
#ifdef F_126
V_274 = F_127 ( F_128 ( V_255 -> V_282 ) ) ;
F_129 ( V_270 && ( ( V_274 & 0xff ) != V_81 -> V_94 ) ,
L_29 ,
V_73 , V_274 , V_81 -> V_94 ) ;
#endif
V_71 -> V_79 [ V_81 -> V_94 ] = V_248 ;
V_71 -> V_78 [ V_81 -> V_94 ] = V_249 ;
V_249 -> V_255 . V_78 = V_283 ;
V_249 -> V_255 . V_284 = F_123 ( ( T_3 ) ( F_130 ( V_73 ) |
F_131 ( V_81 -> V_94 ) ) ) ;
V_263 = & V_71 -> V_77 [ V_81 -> V_94 ] ;
V_159 = sizeof( struct V_259 ) +
sizeof( struct V_285 ) + V_273 ;
V_267 = ( V_159 + 3 ) & ~ 3 ;
if ( V_267 != V_159 )
V_260 -> V_286 |= V_287 ;
V_265 = F_132 ( V_2 -> V_8 ,
& V_249 -> V_255 , V_267 ,
V_92 ) ;
if ( F_28 ( F_133 ( V_2 -> V_8 , V_265 ) ) )
goto V_288;
F_134 ( V_263 , V_289 , V_265 ) ;
F_135 ( V_263 , V_159 , V_267 ) ;
if ( ! F_136 ( V_271 ) ) {
V_71 -> V_61 = 1 ;
} else {
V_269 = 1 ;
V_71 -> V_61 = 0 ;
}
V_268 = V_248 -> V_159 - V_273 ;
if ( V_268 > 0 ) {
V_264 = F_132 ( V_2 -> V_8 , V_248 -> V_256 + V_273 ,
V_268 , V_93 ) ;
if ( F_28 ( F_133 ( V_2 -> V_8 , V_264 ) ) ) {
F_137 ( V_2 -> V_8 ,
F_138 ( V_263 , V_289 ) ,
F_139 ( V_263 , V_159 ) ,
V_92 ) ;
goto V_288;
}
}
F_140 ( V_2 , V_71 , V_265 , V_267 , 1 ) ;
if ( V_268 > 0 )
F_140 ( V_2 , V_71 , V_264 ,
V_268 , 0 ) ;
V_266 = V_265 + sizeof( struct V_285 ) +
F_141 ( struct V_259 , V_290 ) ;
F_142 ( V_2 -> V_8 , V_265 , V_267 ,
V_92 ) ;
V_260 -> V_291 = F_143 ( V_266 ) ;
V_260 -> V_292 = F_79 ( V_266 ) ;
F_144 ( V_2 , L_30 ,
F_128 ( V_249 -> V_255 . V_284 ) ) ;
F_144 ( V_2 , L_31 , F_145 ( V_260 -> V_286 ) ) ;
F_146 ( V_2 , V_71 , F_128 ( V_260 -> V_159 ) ) ;
F_147 ( V_2 -> V_8 , V_265 , V_267 ,
V_92 ) ;
F_148 ( V_2 -> V_8 ,
& ( (struct V_75 * ) V_71 -> V_80 ) [ V_71 -> V_81 . V_94 ] ,
sizeof( struct V_75 ) ,
& V_249 -> V_255 , V_267 ,
V_248 -> V_256 + V_273 , V_268 ) ;
V_81 -> V_94 = F_43 ( V_81 -> V_94 , V_81 -> V_91 ) ;
F_149 ( V_2 , V_71 ) ;
if ( F_150 ( V_81 ) < V_81 -> V_293 ) {
if ( V_269 ) {
V_71 -> V_61 = 1 ;
F_149 ( V_2 , V_71 ) ;
} else {
F_151 ( V_2 , V_71 ) ;
}
}
F_152 ( & V_71 -> V_9 ) ;
return 0 ;
V_288:
F_152 ( & V_71 -> V_9 ) ;
return - 1 ;
}
static int F_153 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
int V_52 ;
bool V_181 ;
V_4 -> V_294 = V_295 ;
if ( ! V_4 -> V_296 ) {
F_154 ( & V_4 -> V_242 , ( void (*) ( unsigned long ) )
V_297 , ( unsigned long ) V_2 ) ;
F_155 ( V_2 ) ;
V_52 = F_156 ( V_4 -> V_241 , V_298 , V_299 ,
V_300 , V_2 ) ;
if ( V_52 ) {
F_32 ( V_2 , L_32 ,
V_4 -> V_241 ) ;
goto error;
}
F_157 ( & V_4 -> V_243 , V_301 ) ;
V_4 -> V_296 = true ;
}
V_52 = F_73 ( V_2 ) ;
if ( V_52 ) {
F_32 ( V_2 , L_33 , V_52 ) ;
goto V_302;
}
F_60 ( V_2 ) ;
V_181 = ! ( F_86 ( V_2 , V_131 ) &
V_193 ) ;
F_87 ( V_2 -> V_146 , V_181 ) ;
return V_52 ;
V_302:
F_158 ( V_4 -> V_241 , V_2 ) ;
error:
F_159 ( V_2 ) ;
F_117 ( & V_4 -> V_242 ) ;
return V_52 ;
}
static void F_160 ( struct V_1 * V_2 )
{
F_67 ( V_2 ) ;
F_84 ( V_2 , V_195 , 0xFFFFFFFF ) ;
F_88 ( V_2 ) ;
}
static int F_161 ( struct V_1 * V_2 , int V_252 , int V_253 ,
int V_73 , int V_303 , struct V_304 * V_79 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 = & V_4 -> V_71 [ V_73 ] ;
int V_305 = V_303 & ( V_71 -> V_81 . V_91 - 1 ) ;
int V_306 = 0 ;
F_125 ( & V_71 -> V_9 ) ;
V_71 -> V_307 = V_308 ;
if ( F_28 ( V_73 >= V_232 &&
V_253 != V_309 &&
V_73 != V_4 -> V_281 [ V_252 ] [ V_253 ] ) ) {
F_162 ( V_2 , L_34
L_35 , V_73 ,
V_4 -> V_281 [ V_252 ] [ V_253 ] ) ;
F_152 ( & V_71 -> V_9 ) ;
return 1 ;
}
if ( V_71 -> V_81 . V_95 != V_305 ) {
F_163 ( V_2 , L_36 ,
V_73 , F_164 ( V_71 ) , V_71 -> V_81 . V_95 ,
V_305 , V_303 ) ;
V_306 = F_165 ( V_2 , V_73 , V_305 , V_79 ) ;
if ( F_150 ( & V_71 -> V_81 ) > V_71 -> V_81 . V_310 )
F_166 ( V_2 , V_71 ) ;
}
F_152 ( & V_71 -> V_9 ) ;
return 0 ;
}
static void F_167 ( struct V_1 * V_2 , T_1 V_311 , T_4 V_312 )
{
F_168 ( V_312 , F_2 ( V_2 ) -> V_313 + V_311 ) ;
}
static void F_169 ( struct V_1 * V_2 , T_1 V_311 , T_1 V_312 )
{
F_170 ( V_312 , F_2 ( V_2 ) -> V_313 + V_311 ) ;
}
static T_1 F_171 ( struct V_1 * V_2 , T_1 V_311 )
{
return F_172 ( F_2 ( V_2 ) -> V_313 + V_311 ) ;
}
static void F_173 ( struct V_1 * V_2 ,
const struct V_314 * V_315 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_83 = V_315 -> V_83 ;
if ( F_4 ( V_315 -> V_316 > V_317 ) )
V_4 -> V_316 = 0 ;
else
V_4 -> V_316 = V_315 -> V_316 ;
if ( V_4 -> V_316 )
memcpy ( V_4 -> V_318 , V_315 -> V_318 ,
V_4 -> V_316 * sizeof( T_4 ) ) ;
}
static void F_174 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
F_46 ( V_2 ) ;
#ifndef F_71
F_21 ( V_2 ) ;
#endif
if ( V_4 -> V_296 == true ) {
F_158 ( V_4 -> V_241 , V_2 ) ;
F_159 ( V_2 ) ;
}
F_175 ( V_4 -> V_113 ) ;
F_176 ( V_4 -> V_313 ) ;
F_177 ( V_4 -> V_113 ) ;
F_178 ( V_4 -> V_113 ) ;
V_2 -> V_225 -> V_2 = NULL ;
F_33 ( V_2 ) ;
}
static int F_179 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_180 ( struct V_1 * V_2 )
{
bool V_181 ;
V_181 = ! ( F_86 ( V_2 , V_131 ) &
V_193 ) ;
if ( V_181 )
F_88 ( V_2 ) ;
else
F_89 ( V_2 ) ;
F_87 ( V_2 -> V_146 , V_181 ) ;
return 0 ;
}
static int F_181 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 ;
struct V_88 * V_81 ;
int V_319 ;
unsigned long V_320 = V_308 ;
int V_87 = 0 ;
for ( V_319 = 0 ; V_319 < F_47 ( V_2 ) -> V_96 -> V_97 ; V_319 ++ ) {
if ( V_319 == V_4 -> V_83 )
continue;
V_71 = & V_4 -> V_71 [ V_319 ] ;
V_81 = & V_71 -> V_81 ;
while ( V_81 -> V_95 != V_81 -> V_94 && ! F_182 ( V_308 ,
V_320 + F_183 ( V_321 ) ) )
F_184 ( 1 ) ;
if ( V_81 -> V_95 != V_81 -> V_94 ) {
F_32 ( V_2 , L_37 ) ;
V_87 = - V_175 ;
break;
}
}
return V_87 ;
}
static int F_185 ( struct V_1 * V_2 , int V_319 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 = & V_4 -> V_71 [ V_319 ] ;
struct V_88 * V_81 = & V_71 -> V_81 ;
unsigned long V_322 ;
if ( V_81 -> V_95 == V_81 -> V_94 ) {
V_71 -> V_307 = V_308 ;
return 0 ;
}
V_322 = V_71 -> V_307 +
F_183 ( F_9 ( V_2 ) . V_323 ) ;
if ( F_182 ( V_308 , V_322 ) ) {
F_32 ( V_2 , L_38 , V_81 -> V_86 ,
F_9 ( V_2 ) . V_323 ) ;
F_32 ( V_2 , L_39 ,
V_81 -> V_95 , V_81 -> V_94 ) ;
F_32 ( V_2 , L_40 ,
F_93 ( V_2 , F_98 ( V_319 ) )
& ( V_76 - 1 ) ,
F_93 ( V_2 , F_186 ( V_319 ) ) ) ;
return 1 ;
}
return 0 ;
}
static const char * F_187 ( int V_78 )
{
switch ( V_78 ) {
F_188 ( V_43 ) ;
F_188 ( V_42 ) ;
F_188 ( V_324 ) ;
F_188 ( V_40 ) ;
F_188 ( V_325 ) ;
F_188 ( V_63 ) ;
F_188 ( V_326 ) ;
F_188 ( V_238 ) ;
F_188 ( V_327 ) ;
default:
return L_41 ;
}
}
int F_189 ( struct V_1 * V_2 , char * * V_328 , bool V_329 )
{
int V_21 ;
#ifdef F_126
int V_111 = 0 ;
T_2 V_330 = 0 ;
#endif
static const T_1 V_331 [] = {
V_43 ,
V_42 ,
V_324 ,
V_40 ,
V_325 ,
V_63 ,
V_326 ,
V_238 ,
V_327
} ;
#ifdef F_126
if ( V_329 ) {
V_330 = F_104 ( V_331 ) * 48 + 40 ;
* V_328 = F_31 ( V_330 , V_16 ) ;
if ( ! * V_328 )
return - V_20 ;
V_111 += F_190 ( * V_328 + V_111 , V_330 - V_111 ,
L_42 ) ;
for ( V_21 = 0 ; V_21 < F_104 ( V_331 ) ; V_21 ++ ) {
V_111 += F_190 ( * V_328 + V_111 , V_330 - V_111 ,
L_43 ,
F_187 ( V_331 [ V_21 ] ) ,
F_96 ( V_2 , V_331 [ V_21 ] ) ) ;
}
return V_111 ;
}
#endif
F_32 ( V_2 , L_42 ) ;
for ( V_21 = 0 ; V_21 < F_104 ( V_331 ) ; V_21 ++ ) {
F_32 ( V_2 , L_43 ,
F_187 ( V_331 [ V_21 ] ) ,
F_96 ( V_2 , V_331 [ V_21 ] ) ) ;
}
return 0 ;
}
static const char * F_191 ( int V_78 )
{
switch ( V_78 ) {
F_188 ( V_127 ) ;
F_188 ( V_50 ) ;
F_188 ( V_195 ) ;
F_188 ( V_332 ) ;
F_188 ( V_333 ) ;
F_188 ( V_334 ) ;
F_188 ( V_141 ) ;
F_188 ( V_131 ) ;
F_188 ( V_335 ) ;
F_188 ( V_336 ) ;
F_188 ( V_337 ) ;
F_188 ( V_338 ) ;
F_188 ( V_117 ) ;
F_188 ( V_339 ) ;
F_188 ( V_340 ) ;
F_188 ( V_341 ) ;
F_188 ( V_342 ) ;
F_188 ( V_343 ) ;
F_188 ( V_344 ) ;
F_188 ( V_122 ) ;
F_188 ( V_130 ) ;
F_188 ( V_345 ) ;
F_188 ( V_125 ) ;
default:
return L_41 ;
}
}
void F_192 ( struct V_1 * V_2 )
{
int V_21 ;
static const T_1 V_346 [] = {
V_127 ,
V_50 ,
V_195 ,
V_332 ,
V_333 ,
V_334 ,
V_141 ,
V_131 ,
V_335 ,
V_336 ,
V_337 ,
V_338 ,
V_117 ,
V_339 ,
V_340 ,
V_341 ,
V_342 ,
V_343 ,
V_344 ,
V_122 ,
V_130 ,
V_345 ,
V_125
} ;
F_32 ( V_2 , L_44 ) ;
F_32 ( V_2 , L_45
L_46 ) ;
for ( V_21 = 0 ; V_21 < F_104 ( V_346 ) ; V_21 ++ ) {
F_32 ( V_2 , L_47 ,
F_191 ( V_346 [ V_21 ] ) ,
F_86 ( V_2 , V_346 [ V_21 ] ) ) ;
}
}
static T_8 F_193 ( struct V_347 * V_347 ,
char T_9 * V_348 ,
T_2 V_349 , T_10 * V_350 )
{
struct V_1 * V_2 = V_347 -> V_351 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 ;
struct V_88 * V_81 ;
char * V_328 ;
int V_111 = 0 ;
int V_319 ;
int V_87 ;
T_2 V_330 ;
V_330 = sizeof( char ) * 64 * F_47 ( V_2 ) -> V_96 -> V_97 ;
if ( ! V_4 -> V_71 ) {
F_32 ( V_2 , L_48 ) ;
return - V_352 ;
}
V_328 = F_194 ( V_330 , V_16 ) ;
if ( ! V_328 )
return - V_20 ;
for ( V_319 = 0 ; V_319 < F_47 ( V_2 ) -> V_96 -> V_97 ; V_319 ++ ) {
V_71 = & V_4 -> V_71 [ V_319 ] ;
V_81 = & V_71 -> V_81 ;
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 ,
L_49
L_50 ,
V_319 , V_81 -> V_95 , V_81 -> V_94 ,
! ! F_115 ( V_319 , V_4 -> V_229 ) ,
V_71 -> V_353 , V_71 -> V_353 & 3 ,
( V_71 -> V_353 >> 2 ) & 0x1f ) ;
if ( V_319 >= 4 )
continue;
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 ,
L_51 ,
F_195 ( & V_4 -> V_230 [ V_319 ] ) ) ;
}
V_87 = F_196 ( V_348 , V_349 , V_350 , V_328 , V_111 ) ;
F_33 ( V_328 ) ;
return V_87 ;
}
static T_8 F_197 ( struct V_347 * V_347 ,
char T_9 * V_348 ,
T_2 V_349 , T_10 * V_350 ) {
struct V_1 * V_2 = V_347 -> V_351 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
char V_328 [ 256 ] ;
int V_111 = 0 ;
const T_2 V_330 = sizeof( V_328 ) ;
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 , L_52 ,
V_6 -> V_56 ) ;
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 , L_53 ,
V_6 -> V_57 ) ;
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 , L_54 ,
V_6 -> V_59 ) ;
if ( V_6 -> V_11 ) {
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 , L_55 ,
F_128 ( V_6 -> V_11 -> V_354 ) & 0x0FFF ) ;
} else {
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 ,
L_56 ) ;
}
return F_196 ( V_348 , V_349 , V_350 , V_328 , V_111 ) ;
}
static T_8 F_198 ( struct V_347 * V_347 ,
char T_9 * V_348 ,
T_2 V_349 , T_10 * V_350 )
{
struct V_1 * V_2 = V_347 -> V_351 ;
char * V_328 ;
int V_111 = 0 ;
T_8 V_87 = - V_20 ;
V_87 = V_111 = F_199 ( V_2 , true , & V_328 , true ) ;
if ( V_328 ) {
V_87 = F_196 ( V_348 , V_349 , V_350 , V_328 , V_111 ) ;
F_33 ( V_328 ) ;
}
return V_87 ;
}
static T_8 F_200 ( struct V_347 * V_347 ,
const char T_9 * V_348 ,
T_2 V_349 , T_10 * V_350 )
{
struct V_1 * V_2 = V_347 -> V_351 ;
T_1 V_355 ;
char V_328 [ 8 ] ;
int V_356 ;
memset ( V_328 , 0 , sizeof( V_328 ) ) ;
V_356 = F_201 ( V_349 , sizeof( V_328 ) - 1 ) ;
if ( F_202 ( V_328 , V_348 , V_356 ) )
return - V_357 ;
if ( sscanf ( V_328 , L_57 , & V_355 ) != 1 )
return - V_357 ;
if ( V_355 == 1 )
F_199 ( V_2 , true , NULL , false ) ;
return V_349 ;
}
static T_8 F_203 ( struct V_347 * V_347 ,
char T_9 * V_348 ,
T_2 V_349 , T_10 * V_350 ) {
struct V_1 * V_2 = V_347 -> V_351 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_358 * V_359 = & V_4 -> V_359 ;
int V_111 = 0 ;
char * V_328 ;
int V_330 = 24 * 64 ;
T_8 V_87 ;
V_328 = F_194 ( V_330 , V_16 ) ;
if ( ! V_328 ) {
F_32 ( V_2 , L_58 ) ;
return - V_20 ;
}
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 ,
L_59 ) ;
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 , L_60 ,
V_359 -> V_360 ) ;
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 , L_61 ,
V_359 -> V_361 ) ;
if ( V_359 -> V_361 || V_359 -> V_360 ) {
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 ,
L_62 ,
V_359 -> V_362 ) ;
}
#ifdef F_126
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 , L_63 ,
V_359 -> V_363 ) ;
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 , L_64 ,
V_359 -> V_364 ) ;
#endif
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 ,
L_65 , V_359 -> V_365 ) ;
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 , L_66 ,
V_359 -> V_366 ) ;
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 , L_67 ,
V_359 -> V_367 ) ;
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 ,
L_68 , V_359 -> V_368 ) ;
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 , L_69 ,
V_359 -> V_369 ) ;
V_111 += F_190 ( V_328 + V_111 , V_330 - V_111 , L_70 ,
V_359 -> V_370 ) ;
V_87 = F_196 ( V_348 , V_349 , V_350 , V_328 , V_111 ) ;
F_33 ( V_328 ) ;
return V_87 ;
}
static T_8 F_204 ( struct V_347 * V_347 ,
const char T_9 * V_348 ,
T_2 V_349 , T_10 * V_350 )
{
struct V_1 * V_2 = V_347 -> V_351 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_358 * V_359 = & V_4 -> V_359 ;
char V_328 [ 8 ] ;
int V_356 ;
T_1 V_371 ;
memset ( V_328 , 0 , sizeof( V_328 ) ) ;
V_356 = F_201 ( V_349 , sizeof( V_328 ) - 1 ) ;
if ( F_202 ( V_328 , V_348 , V_356 ) )
return - V_357 ;
if ( sscanf ( V_328 , L_71 , & V_371 ) != 1 )
return - V_357 ;
if ( V_371 == 0 )
memset ( V_359 , 0 , sizeof( * V_359 ) ) ;
return V_349 ;
}
static T_8 F_205 ( struct V_347 * V_347 ,
const char T_9 * V_348 ,
T_2 V_349 , T_10 * V_350 )
{
struct V_1 * V_2 = V_347 -> V_351 ;
char V_328 [ 8 ] ;
int V_356 ;
int V_372 ;
memset ( V_328 , 0 , sizeof( V_328 ) ) ;
V_356 = F_201 ( V_349 , sizeof( V_328 ) - 1 ) ;
if ( F_202 ( V_328 , V_348 , V_356 ) )
return - V_357 ;
if ( sscanf ( V_328 , L_57 , & V_372 ) != 1 )
return - V_357 ;
F_192 ( V_2 ) ;
return V_349 ;
}
static T_8 F_206 ( struct V_347 * V_347 ,
char T_9 * V_348 ,
T_2 V_349 , T_10 * V_350 )
{
struct V_1 * V_2 = V_347 -> V_351 ;
char * V_328 ;
int V_111 = 0 ;
T_8 V_87 = - V_357 ;
V_87 = V_111 = F_189 ( V_2 , & V_328 , true ) ;
if ( V_328 ) {
V_87 = F_196 ( V_348 ,
V_349 , V_350 , V_328 , V_111 ) ;
F_33 ( V_328 ) ;
}
return V_87 ;
}
static int F_207 ( struct V_1 * V_2 ,
struct V_373 * V_374 )
{
F_208 ( V_375 , V_374 , V_376 ) ;
F_208 ( V_377 , V_374 , V_376 ) ;
F_208 ( V_378 , V_374 , V_379 | V_376 ) ;
F_208 ( V_380 , V_374 , V_379 | V_376 ) ;
F_208 ( V_372 , V_374 , V_379 ) ;
F_208 ( V_381 , V_374 , V_376 ) ;
return 0 ;
}
static int F_207 ( struct V_1 * V_2 ,
struct V_373 * V_374 )
{ return 0 ; }
struct V_1 * F_209 ( struct V_382 * V_225 ,
struct V_113 * V_383 ,
const struct V_384 * V_385 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
T_3 V_386 ;
int V_52 ;
V_2 = F_194 ( sizeof( struct V_1 ) +
sizeof( struct V_3 ) , V_16 ) ;
if ( F_4 ( ! V_2 ) )
return NULL ;
V_4 = F_2 ( V_2 ) ;
V_2 -> V_387 = & V_388 ;
V_2 -> V_225 = V_225 ;
V_4 -> V_2 = V_2 ;
F_3 ( & V_4 -> V_60 ) ;
F_210 ( & V_4 -> V_173 ) ;
F_211 ( V_383 , V_389 | V_390 |
V_391 ) ;
if ( F_212 ( V_383 ) ) {
V_52 = - V_392 ;
goto V_393;
}
F_213 ( V_383 ) ;
V_52 = F_214 ( V_383 , F_215 ( 36 ) ) ;
if ( ! V_52 )
V_52 = F_216 ( V_383 , F_215 ( 36 ) ) ;
if ( V_52 ) {
V_52 = F_214 ( V_383 , F_215 ( 32 ) ) ;
if ( ! V_52 )
V_52 = F_216 ( V_383 ,
F_215 ( 32 ) ) ;
if ( V_52 ) {
F_58 ( V_394 , & V_383 -> V_8 ,
L_72 ) ;
goto V_395;
}
}
V_52 = F_217 ( V_383 , V_300 ) ;
if ( V_52 ) {
F_58 ( V_394 , & V_383 -> V_8 , L_73 ) ;
goto V_395;
}
V_4 -> V_313 = F_218 ( V_383 , 0 ) ;
if ( ! V_4 -> V_313 ) {
F_58 ( V_394 , & V_383 -> V_8 , L_74 ) ;
V_52 = - V_392 ;
goto V_396;
}
F_58 ( V_119 , & V_383 -> V_8 ,
L_75 ,
( unsigned long long ) F_219 ( V_383 , 0 ) ) ;
F_58 ( V_119 , & V_383 -> V_8 ,
L_76 , V_4 -> V_313 ) ;
F_58 ( V_119 , & V_383 -> V_8 ,
L_77 , V_383 -> V_397 ) ;
F_220 ( V_383 , V_398 , 0x00 ) ;
V_52 = F_221 ( V_383 ) ;
if ( V_52 )
F_58 ( V_394 , & V_383 -> V_8 ,
L_78 , V_52 ) ;
V_2 -> V_8 = & V_383 -> V_8 ;
V_4 -> V_241 = V_383 -> V_241 ;
V_4 -> V_113 = V_383 ;
V_2 -> V_399 = F_86 ( V_2 , V_335 ) ;
V_2 -> V_400 = ( V_383 -> V_7 << 16 ) + V_383 -> V_401 ;
snprintf ( V_2 -> V_402 , sizeof( V_2 -> V_402 ) ,
L_79 , V_383 -> V_7 , V_383 -> V_401 ) ;
F_55 ( V_383 , V_403 , & V_386 ) ;
if ( V_386 & V_404 ) {
V_386 &= ~ V_404 ;
F_222 ( V_383 , V_403 , V_386 ) ;
}
F_210 ( & V_2 -> V_405 ) ;
return V_2 ;
V_396:
F_177 ( V_383 ) ;
V_395:
F_178 ( V_383 ) ;
V_393:
F_33 ( V_2 ) ;
return NULL ;
}
