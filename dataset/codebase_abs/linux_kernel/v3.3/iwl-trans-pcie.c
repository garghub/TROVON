static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_2 ) -> V_8 ;
memset ( & V_4 -> V_6 , 0 , sizeof( V_4 -> V_6 ) ) ;
F_4 ( & V_6 -> V_9 ) ;
if ( F_5 ( V_6 -> V_10 || V_6 -> V_11 ) )
return - V_12 ;
V_6 -> V_10 = F_6 ( V_8 , sizeof( V_13 ) * V_14 ,
& V_6 -> V_15 , V_16 ) ;
if ( ! V_6 -> V_10 )
goto V_17;
V_6 -> V_11 = F_6 ( V_8 , sizeof( * V_6 -> V_11 ) ,
& V_6 -> V_18 , V_16 ) ;
if ( ! V_6 -> V_11 )
goto V_19;
return 0 ;
V_19:
F_7 ( V_8 , sizeof( V_13 ) * V_14 ,
V_6 -> V_10 , V_6 -> V_15 ) ;
memset ( & V_6 -> V_15 , 0 , sizeof( V_6 -> V_15 ) ) ;
V_6 -> V_10 = NULL ;
V_17:
return - V_20 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 + V_14 ; V_21 ++ ) {
if ( V_6 -> V_23 [ V_21 ] . V_24 != NULL ) {
F_9 ( F_3 ( V_2 ) -> V_8 , V_6 -> V_23 [ V_21 ] . V_25 ,
V_26 << F_10 ( V_2 ) . V_27 ,
V_28 ) ;
F_11 ( V_6 -> V_23 [ V_21 ] . V_24 ,
F_10 ( V_2 ) . V_27 ) ;
V_6 -> V_23 [ V_21 ] . V_24 = NULL ;
}
F_12 ( & V_6 -> V_23 [ V_21 ] . V_29 , & V_6 -> V_30 ) ;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_1 V_31 ;
const T_1 V_32 = V_33 ;
T_1 V_34 = V_35 ;
if ( V_36 . V_37 )
V_31 = V_38 ;
else
V_31 = V_39 ;
F_14 ( F_3 ( V_2 ) , V_40 , 0 ) ;
F_14 ( F_3 ( V_2 ) , V_41 , 0 ) ;
F_14 ( F_3 ( V_2 ) , V_42 ,
( T_1 ) ( V_6 -> V_15 >> 8 ) ) ;
F_14 ( F_3 ( V_2 ) , V_43 ,
V_6 -> V_18 >> 4 ) ;
F_14 ( F_3 ( V_2 ) , V_40 ,
V_44 |
V_45 |
V_46 |
V_47 |
V_31 |
( V_34 << V_48 ) |
( V_32 << V_49 ) ) ;
F_15 ( F_3 ( V_2 ) , V_50 , V_51 ) ;
}
static int F_16 ( struct V_1 * V_2 )
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
F_17 ( & V_6 -> V_9 , V_53 ) ;
F_18 ( & V_6 -> V_54 ) ;
F_18 ( & V_6 -> V_30 ) ;
F_8 ( V_2 ) ;
for ( V_21 = 0 ; V_21 < V_14 ; V_21 ++ )
V_6 -> V_55 [ V_21 ] = NULL ;
V_6 -> V_56 = V_6 -> V_57 = 0 ;
V_6 -> V_58 = 0 ;
V_6 -> V_59 = 0 ;
F_19 ( & V_6 -> V_9 , V_53 ) ;
F_20 ( V_2 ) ;
F_13 ( V_2 , V_6 ) ;
F_17 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
V_6 -> V_61 = 1 ;
F_21 ( V_2 , V_6 ) ;
F_19 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
unsigned long V_53 ;
if ( ! V_6 -> V_10 ) {
F_23 ( V_2 , L_1 ) ;
return;
}
F_17 ( & V_6 -> V_9 , V_53 ) ;
F_8 ( V_2 ) ;
F_19 ( & V_6 -> V_9 , V_53 ) ;
F_7 ( F_3 ( V_2 ) -> V_8 , sizeof( V_13 ) * V_14 ,
V_6 -> V_10 , V_6 -> V_15 ) ;
memset ( & V_6 -> V_15 , 0 , sizeof( V_6 -> V_15 ) ) ;
V_6 -> V_10 = NULL ;
if ( V_6 -> V_11 )
F_7 ( F_3 ( V_2 ) -> V_8 ,
sizeof( struct V_62 ) ,
V_6 -> V_11 , V_6 -> V_18 ) ;
else
F_23 ( V_2 , L_2 ) ;
memset ( & V_6 -> V_18 , 0 , sizeof( V_6 -> V_18 ) ) ;
V_6 -> V_11 = NULL ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_14 ( F_3 ( V_2 ) , V_40 , 0 ) ;
return F_25 ( F_3 ( V_2 ) , V_63 ,
V_64 , 1000 ) ;
}
static inline int F_26 ( struct V_1 * V_2 ,
struct V_65 * V_66 , T_2 V_67 )
{
if ( F_5 ( V_66 -> V_68 ) )
return - V_12 ;
V_66 -> V_68 = F_27 ( F_3 ( V_2 ) -> V_8 , V_67 ,
& V_66 -> V_69 , V_16 ) ;
if ( ! V_66 -> V_68 )
return - V_20 ;
V_66 -> V_67 = V_67 ;
return 0 ;
}
static inline void F_28 ( struct V_1 * V_2 ,
struct V_65 * V_66 )
{
if ( F_29 ( ! V_66 -> V_68 ) )
return;
F_7 ( F_3 ( V_2 ) -> V_8 , V_66 -> V_67 , V_66 -> V_68 , V_66 -> V_69 ) ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_70 * V_71 , int V_72 ,
T_1 V_73 )
{
T_2 V_74 = sizeof( struct V_75 ) * V_76 ;
int V_21 ;
if ( F_5 ( V_71 -> V_77 || V_71 -> V_78 || V_71 -> V_79 || V_71 -> V_80 ) )
return - V_12 ;
V_71 -> V_81 . V_82 = V_72 ;
V_71 -> V_77 = F_31 ( V_72 , sizeof( V_71 -> V_77 [ 0 ] ) , V_16 ) ;
V_71 -> V_78 = F_31 ( V_72 , sizeof( V_71 -> V_78 [ 0 ] ) , V_16 ) ;
if ( ! V_71 -> V_77 || ! V_71 -> V_78 )
goto error;
if ( V_73 == V_2 -> V_60 -> V_83 )
for ( V_21 = 0 ; V_21 < V_72 ; V_21 ++ ) {
V_71 -> V_78 [ V_21 ] = F_32 ( sizeof( struct V_84 ) ,
V_16 ) ;
if ( ! V_71 -> V_78 [ V_21 ] )
goto error;
}
if ( V_73 != V_2 -> V_60 -> V_83 ) {
V_71 -> V_79 = F_31 ( V_76 , sizeof( V_71 -> V_79 [ 0 ] ) ,
V_16 ) ;
if ( ! V_71 -> V_79 ) {
F_33 ( V_2 , L_3
L_4 ) ;
goto error;
}
} else {
V_71 -> V_79 = NULL ;
}
V_71 -> V_80 = F_27 ( F_3 ( V_2 ) -> V_8 , V_74 ,
& V_71 -> V_81 . V_85 , V_16 ) ;
if ( ! V_71 -> V_80 ) {
F_33 ( V_2 , L_5 , V_74 ) ;
goto error;
}
V_71 -> V_81 . V_86 = V_73 ;
return 0 ;
error:
F_34 ( V_71 -> V_79 ) ;
V_71 -> V_79 = NULL ;
if ( V_71 -> V_78 && V_73 == V_2 -> V_60 -> V_83 )
for ( V_21 = 0 ; V_21 < V_72 ; V_21 ++ )
F_34 ( V_71 -> V_78 [ V_21 ] ) ;
F_34 ( V_71 -> V_77 ) ;
F_34 ( V_71 -> V_78 ) ;
V_71 -> V_77 = NULL ;
V_71 -> V_78 = NULL ;
return - V_20 ;
}
static int F_35 ( struct V_1 * V_2 , struct V_70 * V_71 ,
int V_72 , T_1 V_73 )
{
int V_87 ;
V_71 -> V_61 = 0 ;
memset ( V_71 -> V_77 , 0 , sizeof( V_71 -> V_77 [ 0 ] ) * V_72 ) ;
if ( V_73 < 4 )
F_36 ( V_71 , V_73 , V_73 ) ;
F_37 ( V_76 & ( V_76 - 1 ) ) ;
V_87 = F_38 ( & V_71 -> V_81 , V_76 , V_72 ,
V_73 ) ;
if ( V_87 )
return V_87 ;
F_14 ( F_3 ( V_2 ) , F_39 ( V_73 ) ,
V_71 -> V_81 . V_85 >> 8 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 , int V_73 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 = & V_4 -> V_71 [ V_73 ] ;
struct V_88 * V_81 = & V_71 -> V_81 ;
enum V_89 V_90 ;
unsigned long V_53 ;
T_3 * V_9 ;
if ( ! V_81 -> V_91 )
return;
if ( V_73 == V_2 -> V_60 -> V_83 ) {
V_90 = V_92 ;
V_9 = & V_2 -> V_93 ;
} else {
V_90 = V_94 ;
V_9 = & V_2 -> V_60 -> V_95 ;
}
F_17 ( V_9 , V_53 ) ;
while ( V_81 -> V_96 != V_81 -> V_97 ) {
F_41 ( V_2 , V_71 , F_42 ( V_81 , V_81 -> V_97 ) ,
V_90 ) ;
V_81 -> V_97 = F_43 ( V_81 -> V_97 , V_81 -> V_91 ) ;
}
F_19 ( V_9 , V_53 ) ;
}
static void F_44 ( struct V_1 * V_2 , int V_73 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 = & V_4 -> V_71 [ V_73 ] ;
struct V_7 * V_8 = F_3 ( V_2 ) -> V_8 ;
int V_21 ;
if ( F_5 ( ! V_71 ) )
return;
F_40 ( V_2 , V_73 ) ;
if ( V_73 == V_2 -> V_60 -> V_83 )
for ( V_21 = 0 ; V_21 < V_71 -> V_81 . V_82 ; V_21 ++ )
F_34 ( V_71 -> V_78 [ V_21 ] ) ;
if ( V_71 -> V_81 . V_91 ) {
F_7 ( V_8 , sizeof( struct V_75 ) *
V_71 -> V_81 . V_91 , V_71 -> V_80 , V_71 -> V_81 . V_85 ) ;
memset ( & V_71 -> V_81 . V_85 , 0 , sizeof( V_71 -> V_81 . V_85 ) ) ;
}
F_34 ( V_71 -> V_79 ) ;
V_71 -> V_79 = NULL ;
F_34 ( V_71 -> V_78 ) ;
F_34 ( V_71 -> V_77 ) ;
V_71 -> V_78 = NULL ;
V_71 -> V_77 = NULL ;
memset ( V_71 , 0 , sizeof( * V_71 ) ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_73 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_71 ) {
for ( V_73 = 0 ;
V_73 < F_10 ( V_2 ) . V_98 ; V_73 ++ )
F_44 ( V_2 , V_73 ) ;
}
F_34 ( V_4 -> V_71 ) ;
V_4 -> V_71 = NULL ;
F_28 ( V_2 , & V_4 -> V_99 ) ;
F_28 ( V_2 , & V_4 -> V_100 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_87 ;
int V_73 , V_72 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_4 V_101 = F_10 ( V_2 ) . V_98 *
sizeof( struct V_102 ) ;
if ( F_5 ( V_4 -> V_71 ) ) {
V_87 = - V_12 ;
goto error;
}
V_87 = F_26 ( V_2 , & V_4 -> V_100 ,
V_101 ) ;
if ( V_87 ) {
F_33 ( V_2 , L_6 ) ;
goto error;
}
V_87 = F_26 ( V_2 , & V_4 -> V_99 , V_103 ) ;
if ( V_87 ) {
F_33 ( V_2 , L_7 ) ;
goto error;
}
V_4 -> V_71 = F_31 ( F_10 ( V_2 ) . V_98 ,
sizeof( struct V_70 ) , V_16 ) ;
if ( ! V_4 -> V_71 ) {
F_33 ( V_2 , L_8 ) ;
V_87 = V_20 ;
goto error;
}
for ( V_73 = 0 ; V_73 < F_10 ( V_2 ) . V_98 ; V_73 ++ ) {
V_72 = ( V_73 == V_2 -> V_60 -> V_83 ) ?
V_104 : V_105 ;
V_87 = F_30 ( V_2 , & V_4 -> V_71 [ V_73 ] ,
V_72 , V_73 ) ;
if ( V_87 ) {
F_33 ( V_2 , L_9 , V_73 ) ;
goto error;
}
}
return 0 ;
error:
F_45 ( V_2 ) ;
return V_87 ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_87 ;
int V_73 , V_72 ;
unsigned long V_53 ;
bool V_106 = false ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_71 ) {
V_87 = F_46 ( V_2 ) ;
if ( V_87 )
goto error;
V_106 = true ;
}
F_17 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
F_48 ( F_3 ( V_2 ) , V_107 , 0 ) ;
F_14 ( F_3 ( V_2 ) , V_108 ,
V_4 -> V_99 . V_69 >> 4 ) ;
F_19 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
for ( V_73 = 0 ; V_73 < F_10 ( V_2 ) . V_98 ; V_73 ++ ) {
V_72 = ( V_73 == V_2 -> V_60 -> V_83 ) ?
V_104 : V_105 ;
V_87 = F_35 ( V_2 , & V_4 -> V_71 [ V_73 ] ,
V_72 , V_73 ) ;
if ( V_87 ) {
F_33 ( V_2 , L_10 , V_73 ) ;
goto error;
}
}
return 0 ;
error:
if ( V_106 )
F_45 ( V_2 ) ;
return V_87 ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_50 ( F_3 ( V_2 ) , V_109 ,
V_110 ,
~ V_111 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
unsigned long V_53 ;
F_17 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
F_52 ( F_53 ( V_2 ) ) ;
F_15 ( F_3 ( V_2 ) , V_50 ,
V_112 ) ;
F_19 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
F_49 ( V_2 ) ;
F_54 ( F_53 ( V_2 ) ) ;
F_16 ( V_2 ) ;
if ( F_47 ( V_2 ) )
return - V_20 ;
if ( F_10 ( V_2 ) . V_113 ) {
F_55 ( F_3 ( V_2 ) , V_114 ,
0x800FFFFF ) ;
}
F_56 ( V_115 , & V_2 -> V_60 -> V_116 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
int V_87 ;
F_55 ( F_3 ( V_2 ) , V_117 ,
V_118 ) ;
V_87 = F_58 ( F_3 ( V_2 ) , V_117 ,
V_118 ,
V_118 ,
V_119 ) ;
F_23 ( V_2 , L_11 , V_87 < 0 ? L_12 : L_13 ) ;
return V_87 ;
}
static int F_59 ( struct V_1 * V_2 )
{
int V_87 ;
F_23 ( V_2 , L_14 ) ;
V_87 = F_57 ( V_2 ) ;
if ( V_87 >= 0 )
return 0 ;
F_55 ( F_3 ( V_2 ) , V_117 ,
V_120 ) ;
V_87 = F_58 ( F_3 ( V_2 ) , V_117 ,
~ V_121 ,
V_121 , 150000 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 = F_57 ( V_2 ) ;
if ( V_87 >= 0 )
return 0 ;
return V_87 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_87 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
V_2 -> V_60 -> V_122 = V_123 ;
V_4 -> V_124 [ V_125 ] = V_126 ;
V_4 -> V_124 [ V_127 ] = V_128 ;
V_4 -> V_129 [ V_125 ] = V_130 ;
V_4 -> V_129 [ V_127 ] = V_131 ;
V_4 -> V_132 [ V_125 ] = 0 ;
V_4 -> V_132 [ V_127 ] = V_133 ;
if ( ( F_10 ( V_2 ) . V_134 & V_135 ) &&
F_59 ( V_2 ) ) {
F_61 ( V_2 , L_15 ) ;
return - V_136 ;
}
if ( F_62 ( F_3 ( V_2 ) , V_137 ) &
V_138 )
F_63 ( V_139 , & V_2 -> V_60 -> V_116 ) ;
else
F_56 ( V_139 , & V_2 -> V_60 -> V_116 ) ;
if ( F_64 ( V_2 -> V_60 ) ) {
F_65 ( F_53 ( V_2 ) , true ) ;
F_66 ( V_2 ) ;
return - V_140 ;
}
F_67 ( F_3 ( V_2 ) , V_141 , 0xFFFFFFFF ) ;
V_87 = F_51 ( V_2 ) ;
if ( V_87 ) {
F_33 ( V_2 , L_16 ) ;
return V_87 ;
}
F_67 ( F_3 ( V_2 ) , V_142 , V_143 ) ;
F_67 ( F_3 ( V_2 ) , V_142 ,
V_144 ) ;
F_67 ( F_3 ( V_2 ) , V_141 , 0xFFFFFFFF ) ;
F_66 ( V_2 ) ;
F_67 ( F_3 ( V_2 ) , V_142 , V_143 ) ;
F_67 ( F_3 ( V_2 ) , V_142 , V_143 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 , T_1 V_145 )
{
F_48 ( F_3 ( V_2 ) , V_107 , V_145 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
const struct V_146 * V_147 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
T_1 V_148 ;
unsigned long V_53 ;
int V_21 , V_149 ;
T_1 V_150 ;
F_17 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
V_4 -> V_151 =
F_70 ( F_3 ( V_2 ) , V_152 ) ;
V_148 = V_4 -> V_151 + V_153 ;
for (; V_148 < V_4 -> V_151 + V_154 ;
V_148 += 4 )
F_71 ( F_3 ( V_2 ) , V_148 , 0 ) ;
for (; V_148 < V_4 -> V_151 + V_155 ;
V_148 += 4 )
F_71 ( F_3 ( V_2 ) , V_148 , 0 ) ;
for (; V_148 < V_4 -> V_151 +
F_72 ( F_10 ( V_2 ) . V_98 ) ;
V_148 += 4 )
F_71 ( F_3 ( V_2 ) , V_148 , 0 ) ;
F_48 ( F_3 ( V_2 ) , V_156 ,
V_4 -> V_100 . V_69 >> 10 ) ;
for ( V_149 = 0 ; V_149 < V_157 ; V_149 ++ )
F_14 ( F_3 ( V_2 ) , F_73 ( V_149 ) ,
V_158 |
V_159 ) ;
V_150 = F_74 ( F_3 ( V_2 ) , V_160 ) ;
F_14 ( F_3 ( V_2 ) , V_160 ,
V_150 | V_161 ) ;
F_48 ( F_3 ( V_2 ) , V_162 ,
F_75 ( V_2 ) ) ;
F_48 ( F_3 ( V_2 ) , V_163 , 0 ) ;
for ( V_21 = 0 ; V_21 < F_10 ( V_2 ) . V_98 ; V_21 ++ ) {
F_48 ( F_3 ( V_2 ) , F_76 ( V_21 ) , 0 ) ;
F_14 ( F_3 ( V_2 ) , V_164 , 0 | ( V_21 << 8 ) ) ;
F_71 ( F_3 ( V_2 ) , V_4 -> V_151 +
F_77 ( V_21 ) , 0 ) ;
F_71 ( F_3 ( V_2 ) , V_4 -> V_151 +
F_77 ( V_21 ) +
sizeof( T_1 ) ,
( ( V_165 <<
V_166 ) &
V_167 ) |
( ( V_168 <<
V_169 ) &
V_170 ) ) ;
}
F_48 ( F_3 ( V_2 ) , V_171 ,
F_78 ( 0 , F_10 ( V_2 ) . V_98 ) ) ;
F_68 ( V_2 , F_78 ( 0 , 7 ) ) ;
if ( V_2 -> V_60 -> V_172 != F_79 ( V_125 ) )
V_147 = V_173 ;
else
V_147 = V_174 ;
F_80 ( V_2 , V_2 -> V_60 -> V_83 , 0 ) ;
memset ( & V_4 -> V_175 [ 0 ] , 0 ,
sizeof( V_4 -> V_175 ) ) ;
for ( V_21 = 0 ; V_21 < 4 ; V_21 ++ )
F_81 ( & V_4 -> V_176 [ V_21 ] , 0 ) ;
V_4 -> V_177 = 0 ;
F_37 ( F_82 ( V_174 ) <
V_178 ) ;
F_37 ( F_82 ( V_173 ) <
V_178 ) ;
for ( V_21 = 0 ; V_21 < V_178 ; V_21 ++ ) {
int V_179 = V_147 [ V_21 ] . V_179 ;
int V_180 = V_147 [ V_21 ] . V_180 ;
F_83 ( V_4 , V_21 ) ;
if ( V_179 == V_181 )
continue;
if ( V_180 != V_182 )
F_36 ( & V_4 -> V_71 [ V_21 ] , V_180 , V_21 ) ;
F_84 ( V_2 , & V_4 -> V_71 [ V_21 ] ,
V_179 , 0 ) ;
}
F_19 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
F_85 ( F_3 ( V_2 ) , V_183 ,
V_184 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
int V_185 , V_73 ;
unsigned long V_53 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_17 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
F_68 ( V_2 , 0 ) ;
for ( V_185 = 0 ; V_185 < V_157 ; V_185 ++ ) {
F_14 ( F_3 ( V_2 ) ,
F_73 ( V_185 ) , 0x0 ) ;
if ( F_25 ( F_3 ( V_2 ) , V_186 ,
F_87 ( V_185 ) ,
1000 ) )
F_33 ( V_2 , L_17
L_18 , V_185 ,
F_74 ( F_3 ( V_2 ) ,
V_186 ) ) ;
}
F_19 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
if ( ! V_4 -> V_71 ) {
F_61 ( V_2 , L_19 ) ;
return 0 ;
}
for ( V_73 = 0 ; V_73 < F_10 ( V_2 ) . V_98 ; V_73 ++ )
F_40 ( V_2 , V_73 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 )
{
unsigned long V_53 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_17 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
F_89 ( V_2 ) ;
F_19 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
F_90 ( V_2 ) ;
if ( F_91 ( V_187 , & V_2 -> V_60 -> V_116 ) ) {
F_86 ( V_2 ) ;
F_24 ( V_2 ) ;
F_48 ( F_3 ( V_2 ) , V_188 ,
V_189 ) ;
F_92 ( 5 ) ;
}
F_93 ( F_3 ( V_2 ) , V_137 ,
V_190 ) ;
F_94 ( F_53 ( V_2 ) ) ;
F_17 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
F_89 ( V_2 ) ;
F_19 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
F_95 ( F_3 ( V_2 ) -> V_191 ) ;
F_96 ( & V_4 -> V_192 ) ;
F_67 ( F_3 ( V_2 ) , V_193 , V_194 ) ;
}
static int F_97 ( struct V_1 * V_2 , struct V_195 * V_196 ,
struct V_84 * V_197 , enum V_198 V_199 ,
T_5 V_200 , T_5 V_201 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_202 * V_203 = (struct V_202 * ) V_196 -> V_204 ;
struct V_205 * V_206 = F_98 ( V_196 ) ;
struct V_207 * V_208 = (struct V_207 * ) V_197 -> V_209 ;
struct V_210 * V_211 ;
struct V_70 * V_71 ;
struct V_88 * V_81 ;
T_6 V_212 = 0 ;
T_6 V_213 ;
T_6 V_214 ;
T_4 V_215 , V_216 , V_217 ;
T_5 V_218 = 0 ;
T_5 V_73 ;
bool V_219 = false ;
T_7 V_220 = V_203 -> V_221 ;
T_5 V_222 = F_99 ( V_220 ) ;
T_4 T_8 V_223 ;
if ( V_206 -> V_53 & V_224 ) {
V_73 = V_4 -> V_132 [ V_199 ] ;
V_203 -> V_221 |=
F_100 ( V_225 ) ;
} else if ( V_206 -> V_53 & V_226 )
V_73 = V_227 ;
else
V_73 =
V_4 -> V_124 [ V_199 ] [ F_101 ( V_196 ) ] ;
if ( V_206 -> V_53 & V_228 ) {
F_5 ( V_201 >= V_229 ) ;
V_73 = V_4 -> V_230 [ V_200 ] [ V_201 ] ;
V_219 = true ;
}
V_71 = & V_4 -> V_71 [ V_73 ] ;
V_81 = & V_71 -> V_81 ;
#ifdef F_102
V_223 = F_103 ( F_104 ( V_203 -> V_231 ) ) ;
F_105 ( V_219 && ( ( V_223 & 0xff ) != V_81 -> V_96 ) ,
L_20 ,
V_73 , V_223 , V_81 -> V_96 ) ;
#endif
V_71 -> V_79 [ V_81 -> V_96 ] = V_196 ;
V_71 -> V_78 [ V_81 -> V_96 ] = V_197 ;
V_197 -> V_203 . V_78 = V_232 ;
V_197 -> V_203 . V_233 = F_100 ( ( T_4 ) ( F_106 ( V_73 ) |
F_107 ( V_81 -> V_96 ) ) ) ;
V_211 = & V_71 -> V_77 [ V_81 -> V_96 ] ;
V_215 = sizeof( struct V_207 ) +
sizeof( struct V_234 ) + V_222 ;
V_216 = ( V_215 + 3 ) & ~ 3 ;
if ( V_216 != V_215 )
V_208 -> V_235 |= V_236 ;
V_213 = F_108 ( F_3 ( V_2 ) -> V_8 ,
& V_197 -> V_203 , V_216 ,
V_92 ) ;
if ( F_29 ( F_109 ( F_3 ( V_2 ) -> V_8 , V_213 ) ) )
return - 1 ;
F_110 ( V_211 , V_237 , V_213 ) ;
F_111 ( V_211 , V_215 , V_216 ) ;
if ( ! F_112 ( V_220 ) ) {
V_71 -> V_61 = 1 ;
} else {
V_218 = 1 ;
V_71 -> V_61 = 0 ;
}
V_217 = V_196 -> V_215 - V_222 ;
if ( V_217 > 0 ) {
V_212 = F_108 ( F_3 ( V_2 ) -> V_8 , V_196 -> V_204 + V_222 ,
V_217 , V_94 ) ;
if ( F_29 ( F_109 ( F_3 ( V_2 ) -> V_8 , V_212 ) ) ) {
F_113 ( F_3 ( V_2 ) -> V_8 ,
F_114 ( V_211 , V_237 ) ,
F_115 ( V_211 , V_215 ) ,
V_92 ) ;
return - 1 ;
}
}
F_116 ( V_2 , V_71 , V_213 , V_216 , 1 ) ;
if ( V_217 > 0 )
F_116 ( V_2 , V_71 , V_212 ,
V_217 , 0 ) ;
V_214 = V_213 + sizeof( struct V_234 ) +
F_117 ( struct V_207 , V_238 ) ;
F_118 ( F_3 ( V_2 ) -> V_8 , V_213 , V_216 ,
V_92 ) ;
V_208 -> V_239 = F_119 ( V_214 ) ;
V_208 -> V_240 = F_120 ( V_214 ) ;
F_121 ( V_2 , L_21 ,
F_104 ( V_197 -> V_203 . V_233 ) ) ;
F_121 ( V_2 , L_22 , F_122 ( V_208 -> V_235 ) ) ;
F_123 ( V_2 , V_241 , ( T_5 * ) V_208 , sizeof( * V_208 ) ) ;
F_123 ( V_2 , V_241 , ( T_5 * ) V_208 -> V_203 , V_222 ) ;
F_124 ( V_2 , V_71 , F_104 ( V_208 -> V_215 ) ) ;
F_125 ( F_3 ( V_2 ) -> V_8 , V_213 , V_216 ,
V_92 ) ;
F_126 ( F_53 ( V_2 ) ,
& ( (struct V_75 * ) V_71 -> V_80 ) [ V_71 -> V_81 . V_96 ] ,
sizeof( struct V_75 ) ,
& V_197 -> V_203 , V_216 ,
V_196 -> V_204 + V_222 , V_217 ) ;
V_81 -> V_96 = F_43 ( V_81 -> V_96 , V_81 -> V_91 ) ;
F_127 ( V_2 , V_71 ) ;
if ( F_128 ( V_81 ) < V_81 -> V_242 ) {
if ( V_218 ) {
V_71 -> V_61 = 1 ;
F_127 ( V_2 , V_71 ) ;
} else {
F_129 ( V_2 , V_71 , L_23 ) ;
}
}
return 0 ;
}
static void F_130 ( struct V_1 * V_2 )
{
F_67 ( F_3 ( V_2 ) , V_193 , 0 ) ;
}
static int F_131 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
int V_52 ;
V_4 -> V_243 = V_244 ;
F_132 ( & V_4 -> V_192 , ( void (*) ( unsigned long ) )
V_245 , ( unsigned long ) V_2 ) ;
F_133 ( V_2 ) ;
V_52 = F_134 ( F_3 ( V_2 ) -> V_191 , V_246 , V_247 ,
V_248 , V_2 ) ;
if ( V_52 ) {
F_33 ( V_2 , L_24 , F_3 ( V_2 ) -> V_191 ) ;
F_135 ( V_2 ) ;
return V_52 ;
}
F_136 ( & V_4 -> V_249 , V_250 ) ;
return 0 ;
}
static int F_137 ( struct V_1 * V_2 , int V_200 , int V_201 ,
int V_73 , int V_251 , T_1 V_116 ,
struct V_252 * V_79 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 = & V_4 -> V_71 [ V_73 ] ;
int V_253 = V_251 & ( V_71 -> V_81 . V_91 - 1 ) ;
int V_254 = 0 ;
V_71 -> V_255 = V_256 ;
if ( F_29 ( V_73 >= V_178 &&
V_201 != V_257 &&
V_73 != V_4 -> V_230 [ V_200 ] [ V_201 ] ) ) {
F_138 ( V_2 , L_25
L_26 , V_73 ,
V_4 -> V_230 [ V_200 ] [ V_201 ] ) ;
return 1 ;
}
if ( V_71 -> V_81 . V_97 != V_253 ) {
F_139 ( V_2 , L_27 ,
V_73 , F_140 ( V_71 ) , V_71 -> V_81 . V_97 ,
V_253 , V_251 ) ;
V_254 = F_141 ( V_2 , V_73 , V_253 , V_79 ) ;
if ( F_128 ( & V_71 -> V_81 ) > V_71 -> V_81 . V_258 &&
( ! V_71 -> V_259 ||
V_116 != V_260 ) )
F_142 ( V_2 , V_71 , L_28 ) ;
}
return 0 ;
}
static void F_143 ( struct V_1 * V_2 )
{
F_144 ( V_2 ) ;
F_45 ( V_2 ) ;
F_22 ( V_2 ) ;
F_145 ( F_3 ( V_2 ) -> V_191 , V_2 ) ;
F_135 ( V_2 ) ;
V_2 -> V_60 -> V_2 = NULL ;
F_34 ( V_2 ) ;
}
static int F_146 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_60 -> V_261 ) {
F_94 ( F_53 ( V_2 ) ) ;
} else {
F_89 ( V_2 ) ;
F_93 ( F_3 ( V_2 ) , V_137 ,
V_190 ) ;
}
return 0 ;
}
static int F_147 ( struct V_1 * V_2 )
{
bool V_262 = false ;
F_66 ( V_2 ) ;
if ( ! ( F_62 ( F_3 ( V_2 ) , V_137 ) &
V_138 ) )
V_262 = true ;
if ( V_262 )
F_56 ( V_139 , & V_2 -> V_60 -> V_116 ) ;
else
F_63 ( V_139 , & V_2 -> V_60 -> V_116 ) ;
F_65 ( F_53 ( V_2 ) , V_262 ) ;
return 0 ;
}
static void F_148 ( struct V_1 * V_2 ,
enum V_198 V_199 ,
const char * V_263 )
{
T_5 V_180 , V_73 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
for ( V_180 = 0 ; V_180 < V_264 ; V_180 ++ ) {
V_73 = V_4 -> V_124 [ V_199 ] [ V_180 ] ;
F_138 ( V_2 , L_29 ,
V_180 ,
( F_149 ( & V_4 -> V_176 [ V_180 ] ) > 0 )
? L_30 : L_31 ) ;
F_142 ( V_2 , & V_4 -> V_71 [ V_73 ] , V_263 ) ;
}
}
static struct V_1 * F_150 ( struct V_265 * V_60 )
{
struct V_1 * V_1 = F_151 ( sizeof( struct V_1 ) +
sizeof( struct V_3 ) ,
V_16 ) ;
if ( V_1 ) {
struct V_3 * V_4 =
F_2 ( V_1 ) ;
V_1 -> V_266 = & V_267 ;
V_1 -> V_60 = V_60 ;
V_4 -> V_2 = V_1 ;
F_4 ( & V_1 -> V_93 ) ;
}
return V_1 ;
}
static void F_152 ( struct V_1 * V_2 , int V_73 ,
const char * V_263 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_129 ( V_2 , & V_4 -> V_71 [ V_73 ] , V_263 ) ;
}
static int F_153 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 ;
struct V_88 * V_81 ;
int V_268 ;
unsigned long V_269 = V_256 ;
int V_87 = 0 ;
for ( V_268 = 0 ; V_268 < F_10 ( V_2 ) . V_98 ; V_268 ++ ) {
if ( V_268 == V_2 -> V_60 -> V_83 )
continue;
V_71 = & V_4 -> V_71 [ V_268 ] ;
V_81 = & V_71 -> V_81 ;
while ( V_81 -> V_97 != V_81 -> V_96 && ! F_154 ( V_256 ,
V_269 + F_155 ( V_270 ) ) )
F_156 ( 1 ) ;
if ( V_81 -> V_97 != V_81 -> V_96 ) {
F_33 ( V_2 , L_32 ) ;
V_87 = - V_271 ;
break;
}
}
return V_87 ;
}
static int F_157 ( struct V_1 * V_2 , int V_268 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 = & V_4 -> V_71 [ V_268 ] ;
struct V_88 * V_81 = & V_71 -> V_81 ;
unsigned long V_272 ;
if ( V_81 -> V_97 == V_81 -> V_96 ) {
V_71 -> V_255 = V_256 ;
return 0 ;
}
V_272 = V_71 -> V_255 +
F_155 ( F_10 ( V_2 ) . V_273 ) ;
if ( F_154 ( V_256 , V_272 ) ) {
F_33 ( V_2 , L_33 , V_81 -> V_86 ,
F_10 ( V_2 ) . V_273 ) ;
F_33 ( V_2 , L_34 ,
V_81 -> V_97 , V_81 -> V_96 ) ;
F_33 ( V_2 , L_35 ,
F_70 ( F_3 ( V_2 ) , F_76 ( V_268 ) )
& ( V_76 - 1 ) ,
F_70 ( F_3 ( V_2 ) , F_158 ( V_268 ) ) ) ;
return 1 ;
}
return 0 ;
}
static const char * F_159 ( int V_78 )
{
switch ( V_78 ) {
F_160 ( V_43 ) ;
F_160 ( V_42 ) ;
F_160 ( V_274 ) ;
F_160 ( V_40 ) ;
F_160 ( V_275 ) ;
F_160 ( V_63 ) ;
F_160 ( V_276 ) ;
F_160 ( V_186 ) ;
F_160 ( V_277 ) ;
default:
return L_36 ;
}
}
int F_161 ( struct V_1 * V_2 , char * * V_278 , bool V_279 )
{
int V_21 ;
#ifdef F_102
int V_280 = 0 ;
T_2 V_281 = 0 ;
#endif
static const T_1 V_282 [] = {
V_43 ,
V_42 ,
V_274 ,
V_40 ,
V_275 ,
V_63 ,
V_276 ,
V_186 ,
V_277
} ;
#ifdef F_102
if ( V_279 ) {
V_281 = F_82 ( V_282 ) * 48 + 40 ;
* V_278 = F_32 ( V_281 , V_16 ) ;
if ( ! * V_278 )
return - V_20 ;
V_280 += F_162 ( * V_278 + V_280 , V_281 - V_280 ,
L_37 ) ;
for ( V_21 = 0 ; V_21 < F_82 ( V_282 ) ; V_21 ++ ) {
V_280 += F_162 ( * V_278 + V_280 , V_281 - V_280 ,
L_38 ,
F_159 ( V_282 [ V_21 ] ) ,
F_74 ( F_3 ( V_2 ) , V_282 [ V_21 ] ) ) ;
}
return V_280 ;
}
#endif
F_33 ( V_2 , L_37 ) ;
for ( V_21 = 0 ; V_21 < F_82 ( V_282 ) ; V_21 ++ ) {
F_33 ( V_2 , L_38 ,
F_159 ( V_282 [ V_21 ] ) ,
F_74 ( F_3 ( V_2 ) , V_282 [ V_21 ] ) ) ;
}
return 0 ;
}
static const char * F_163 ( int V_78 )
{
switch ( V_78 ) {
F_160 ( V_117 ) ;
F_160 ( V_50 ) ;
F_160 ( V_141 ) ;
F_160 ( V_283 ) ;
F_160 ( V_284 ) ;
F_160 ( V_285 ) ;
F_160 ( V_193 ) ;
F_160 ( V_137 ) ;
F_160 ( V_286 ) ;
F_160 ( V_287 ) ;
F_160 ( V_288 ) ;
F_160 ( V_289 ) ;
F_160 ( V_290 ) ;
F_160 ( V_291 ) ;
F_160 ( V_292 ) ;
F_160 ( V_293 ) ;
F_160 ( V_294 ) ;
F_160 ( V_295 ) ;
F_160 ( V_296 ) ;
F_160 ( V_297 ) ;
F_160 ( V_298 ) ;
F_160 ( V_299 ) ;
F_160 ( V_300 ) ;
default:
return L_36 ;
}
}
void F_164 ( struct V_1 * V_2 )
{
int V_21 ;
static const T_1 V_301 [] = {
V_117 ,
V_50 ,
V_141 ,
V_283 ,
V_284 ,
V_285 ,
V_193 ,
V_137 ,
V_286 ,
V_287 ,
V_288 ,
V_289 ,
V_290 ,
V_291 ,
V_292 ,
V_293 ,
V_294 ,
V_295 ,
V_296 ,
V_297 ,
V_298 ,
V_299 ,
V_300
} ;
F_33 ( V_2 , L_39 ) ;
F_33 ( V_2 , L_40
L_41 ) ;
for ( V_21 = 0 ; V_21 < F_82 ( V_301 ) ; V_21 ++ ) {
F_33 ( V_2 , L_42 ,
F_163 ( V_301 [ V_21 ] ) ,
F_62 ( F_3 ( V_2 ) , V_301 [ V_21 ] ) ) ;
}
}
static int F_165 ( struct V_302 * V_302 , struct V_303 * V_303 )
{
V_303 -> V_304 = V_302 -> V_305 ;
return 0 ;
}
static T_9 F_166 ( struct V_303 * V_303 ,
char T_10 * V_306 ,
T_2 V_307 , T_11 * V_308 )
{
struct V_1 * V_2 = V_303 -> V_304 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 ;
struct V_88 * V_81 ;
char * V_278 ;
int V_280 = 0 ;
int V_268 ;
int V_87 ;
const T_2 V_281 = sizeof( char ) * 64 * F_10 ( V_2 ) . V_98 ;
if ( ! V_4 -> V_71 ) {
F_33 ( V_2 , L_43 ) ;
return - V_309 ;
}
V_278 = F_151 ( V_281 , V_16 ) ;
if ( ! V_278 )
return - V_20 ;
for ( V_268 = 0 ; V_268 < F_10 ( V_2 ) . V_98 ; V_268 ++ ) {
V_71 = & V_4 -> V_71 [ V_268 ] ;
V_81 = & V_71 -> V_81 ;
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 ,
L_44
L_45 ,
V_268 , V_81 -> V_97 , V_81 -> V_96 ,
! ! F_91 ( V_268 , V_4 -> V_175 ) ,
V_71 -> V_310 , V_71 -> V_310 & 3 ,
( V_71 -> V_310 >> 2 ) & 0x1f ) ;
if ( V_268 >= 4 )
continue;
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 ,
L_46 ,
F_149 ( & V_4 -> V_176 [ V_268 ] ) ) ;
}
V_87 = F_167 ( V_306 , V_307 , V_308 , V_278 , V_280 ) ;
F_34 ( V_278 ) ;
return V_87 ;
}
static T_9 F_168 ( struct V_303 * V_303 ,
char T_10 * V_306 ,
T_2 V_307 , T_11 * V_308 ) {
struct V_1 * V_2 = V_303 -> V_304 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
char V_278 [ 256 ] ;
int V_280 = 0 ;
const T_2 V_281 = sizeof( V_278 ) ;
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 , L_47 ,
V_6 -> V_56 ) ;
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 , L_48 ,
V_6 -> V_57 ) ;
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 , L_49 ,
V_6 -> V_59 ) ;
if ( V_6 -> V_11 ) {
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 , L_50 ,
F_104 ( V_6 -> V_11 -> V_311 ) & 0x0FFF ) ;
} else {
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 ,
L_51 ) ;
}
return F_167 ( V_306 , V_307 , V_308 , V_278 , V_280 ) ;
}
static T_9 F_169 ( struct V_303 * V_303 ,
char T_10 * V_306 ,
T_2 V_307 , T_11 * V_308 )
{
struct V_1 * V_2 = V_303 -> V_304 ;
char * V_278 ;
int V_280 = 0 ;
T_9 V_87 = - V_20 ;
V_87 = V_280 = F_170 ( V_2 , true , & V_278 , true ) ;
if ( V_278 ) {
V_87 = F_167 ( V_306 , V_307 , V_308 , V_278 , V_280 ) ;
F_34 ( V_278 ) ;
}
return V_87 ;
}
static T_9 F_171 ( struct V_303 * V_303 ,
const char T_10 * V_306 ,
T_2 V_307 , T_11 * V_308 )
{
struct V_1 * V_2 = V_303 -> V_304 ;
T_1 V_312 ;
char V_278 [ 8 ] ;
int V_313 ;
memset ( V_278 , 0 , sizeof( V_278 ) ) ;
V_313 = F_172 ( V_307 , sizeof( V_278 ) - 1 ) ;
if ( F_173 ( V_278 , V_306 , V_313 ) )
return - V_314 ;
if ( sscanf ( V_278 , L_52 , & V_312 ) != 1 )
return - V_314 ;
if ( V_312 == 1 )
F_170 ( V_2 , true , NULL , false ) ;
return V_307 ;
}
static T_9 F_174 ( struct V_303 * V_303 ,
char T_10 * V_306 ,
T_2 V_307 , T_11 * V_308 ) {
struct V_1 * V_2 = V_303 -> V_304 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_315 * V_316 = & V_4 -> V_316 ;
int V_280 = 0 ;
char * V_278 ;
int V_281 = 24 * 64 ;
T_9 V_87 ;
V_278 = F_151 ( V_281 , V_16 ) ;
if ( ! V_278 ) {
F_33 ( V_2 , L_53 ) ;
return - V_20 ;
}
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 ,
L_54 ) ;
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 , L_55 ,
V_316 -> V_317 ) ;
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 , L_56 ,
V_316 -> V_318 ) ;
if ( V_316 -> V_318 || V_316 -> V_317 ) {
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 ,
L_57 ,
V_316 -> V_319 ) ;
}
#ifdef F_102
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 , L_58 ,
V_316 -> V_320 ) ;
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 , L_59 ,
V_316 -> V_321 ) ;
#endif
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 ,
L_60 , V_316 -> V_322 ) ;
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 , L_61 ,
V_316 -> V_323 ) ;
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 , L_62 ,
V_316 -> V_324 ) ;
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 ,
L_63 , V_316 -> V_325 ) ;
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 , L_64 ,
V_316 -> V_326 ) ;
V_280 += F_162 ( V_278 + V_280 , V_281 - V_280 , L_65 ,
V_316 -> V_327 ) ;
V_87 = F_167 ( V_306 , V_307 , V_308 , V_278 , V_280 ) ;
F_34 ( V_278 ) ;
return V_87 ;
}
static T_9 F_175 ( struct V_303 * V_303 ,
const char T_10 * V_306 ,
T_2 V_307 , T_11 * V_308 )
{
struct V_1 * V_2 = V_303 -> V_304 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_315 * V_316 = & V_4 -> V_316 ;
char V_278 [ 8 ] ;
int V_313 ;
T_1 V_328 ;
memset ( V_278 , 0 , sizeof( V_278 ) ) ;
V_313 = F_172 ( V_307 , sizeof( V_278 ) - 1 ) ;
if ( F_173 ( V_278 , V_306 , V_313 ) )
return - V_314 ;
if ( sscanf ( V_278 , L_66 , & V_328 ) != 1 )
return - V_314 ;
if ( V_328 == 0 )
memset ( V_316 , 0 , sizeof( * V_316 ) ) ;
return V_307 ;
}
static T_9 F_176 ( struct V_303 * V_303 ,
const char T_10 * V_306 ,
T_2 V_307 , T_11 * V_308 )
{
struct V_1 * V_2 = V_303 -> V_304 ;
char V_278 [ 8 ] ;
int V_313 ;
int V_329 ;
memset ( V_278 , 0 , sizeof( V_278 ) ) ;
V_313 = F_172 ( V_307 , sizeof( V_278 ) - 1 ) ;
if ( F_173 ( V_278 , V_306 , V_313 ) )
return - V_314 ;
if ( sscanf ( V_278 , L_52 , & V_329 ) != 1 )
return - V_314 ;
F_164 ( V_2 ) ;
return V_307 ;
}
static T_9 F_177 ( struct V_303 * V_303 ,
char T_10 * V_306 ,
T_2 V_307 , T_11 * V_308 )
{
struct V_1 * V_2 = V_303 -> V_304 ;
char * V_278 ;
int V_280 = 0 ;
T_9 V_87 = - V_314 ;
V_87 = V_280 = F_161 ( V_2 , & V_278 , true ) ;
if ( V_278 ) {
V_87 = F_167 ( V_306 ,
V_307 , V_308 , V_278 , V_280 ) ;
F_34 ( V_278 ) ;
}
return V_87 ;
}
static int F_178 ( struct V_1 * V_2 ,
struct V_330 * V_331 )
{
F_179 ( V_332 , V_331 , V_333 ) ;
F_179 ( V_334 , V_331 , V_333 ) ;
F_179 ( V_335 , V_331 , V_336 | V_333 ) ;
F_179 ( V_337 , V_331 , V_336 | V_333 ) ;
F_179 ( V_329 , V_331 , V_336 ) ;
F_179 ( V_338 , V_331 , V_333 ) ;
return 0 ;
}
static int F_178 ( struct V_1 * V_2 ,
struct V_330 * V_331 )
{ return 0 ; }
