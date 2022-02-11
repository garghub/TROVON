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
memset ( V_6 -> V_10 , 0 , sizeof( V_13 ) * V_14 ) ;
V_6 -> V_11 = F_6 ( V_8 , sizeof( * V_6 -> V_11 ) ,
& V_6 -> V_18 , V_16 ) ;
if ( ! V_6 -> V_11 )
goto V_19;
memset ( V_6 -> V_11 , 0 , sizeof( * V_6 -> V_11 ) ) ;
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
V_66 -> V_68 = F_6 ( F_3 ( V_2 ) -> V_8 , V_67 ,
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
F_7 ( F_3 ( V_2 ) -> V_8 , V_66 -> V_67 , V_66 -> V_68 , V_66 -> V_69 ) ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_70 * V_71 , int V_72 ,
T_1 V_73 )
{
T_2 V_74 = sizeof( struct V_75 ) * V_76 ;
int V_21 ;
if ( F_5 ( V_71 -> V_77 || V_71 -> V_78 || V_71 -> V_79 || V_71 -> V_80 ) )
return - V_12 ;
V_71 -> V_81 . V_82 = V_72 ;
V_71 -> V_77 = F_30 ( V_72 , sizeof( V_71 -> V_77 [ 0 ] ) , V_16 ) ;
V_71 -> V_78 = F_30 ( V_72 , sizeof( V_71 -> V_78 [ 0 ] ) , V_16 ) ;
if ( ! V_71 -> V_77 || ! V_71 -> V_78 )
goto error;
if ( V_73 == V_2 -> V_60 -> V_83 )
for ( V_21 = 0 ; V_21 < V_72 ; V_21 ++ ) {
V_71 -> V_78 [ V_21 ] = F_31 ( sizeof( struct V_84 ) ,
V_16 ) ;
if ( ! V_71 -> V_78 [ V_21 ] )
goto error;
}
if ( V_73 != V_2 -> V_60 -> V_83 ) {
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
V_71 -> V_80 = F_6 ( F_3 ( V_2 ) -> V_8 , V_74 ,
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
if ( V_71 -> V_78 && V_73 == V_2 -> V_60 -> V_83 )
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
F_14 ( F_3 ( V_2 ) , F_38 ( V_73 ) ,
V_71 -> V_81 . V_85 >> 8 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 , int V_73 )
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
F_40 ( V_2 , V_71 , F_41 ( V_81 , V_81 -> V_97 ) ,
V_90 ) ;
V_81 -> V_97 = F_42 ( V_81 -> V_97 , V_81 -> V_91 ) ;
}
F_19 ( V_9 , V_53 ) ;
}
static void F_43 ( struct V_1 * V_2 , int V_73 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 = & V_4 -> V_71 [ V_73 ] ;
struct V_7 * V_8 = F_3 ( V_2 ) -> V_8 ;
int V_21 ;
if ( F_5 ( ! V_71 ) )
return;
F_39 ( V_2 , V_73 ) ;
if ( V_73 == V_2 -> V_60 -> V_83 )
for ( V_21 = 0 ; V_21 < V_71 -> V_81 . V_82 ; V_21 ++ )
F_33 ( V_71 -> V_78 [ V_21 ] ) ;
if ( V_71 -> V_81 . V_91 ) {
F_7 ( V_8 , sizeof( struct V_75 ) *
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
static void F_44 ( struct V_1 * V_2 )
{
int V_73 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_71 ) {
for ( V_73 = 0 ;
V_73 < F_10 ( V_2 ) . V_98 ; V_73 ++ )
F_43 ( V_2 , V_73 ) ;
}
F_33 ( V_4 -> V_71 ) ;
V_4 -> V_71 = NULL ;
F_27 ( V_2 , & V_4 -> V_99 ) ;
F_27 ( V_2 , & V_4 -> V_100 ) ;
}
static int F_45 ( struct V_1 * V_2 )
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
F_32 ( V_2 , L_6 ) ;
goto error;
}
V_87 = F_26 ( V_2 , & V_4 -> V_99 , V_103 ) ;
if ( V_87 ) {
F_32 ( V_2 , L_7 ) ;
goto error;
}
V_4 -> V_71 = F_30 ( F_10 ( V_2 ) . V_98 ,
sizeof( struct V_70 ) , V_16 ) ;
if ( ! V_4 -> V_71 ) {
F_32 ( V_2 , L_8 ) ;
V_87 = V_20 ;
goto error;
}
for ( V_73 = 0 ; V_73 < F_10 ( V_2 ) . V_98 ; V_73 ++ ) {
V_72 = ( V_73 == V_2 -> V_60 -> V_83 ) ?
V_104 : V_105 ;
V_87 = F_29 ( V_2 , & V_4 -> V_71 [ V_73 ] ,
V_72 , V_73 ) ;
if ( V_87 ) {
F_32 ( V_2 , L_9 , V_73 ) ;
goto error;
}
}
return 0 ;
error:
F_44 ( V_2 ) ;
return V_87 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_87 ;
int V_73 , V_72 ;
unsigned long V_53 ;
bool V_106 = false ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_71 ) {
V_87 = F_45 ( V_2 ) ;
if ( V_87 )
goto error;
V_106 = true ;
}
F_17 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
F_47 ( F_3 ( V_2 ) , V_107 , 0 ) ;
F_14 ( F_3 ( V_2 ) , V_108 ,
V_4 -> V_99 . V_69 >> 4 ) ;
F_19 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
for ( V_73 = 0 ; V_73 < F_10 ( V_2 ) . V_98 ; V_73 ++ ) {
V_72 = ( V_73 == V_2 -> V_60 -> V_83 ) ?
V_104 : V_105 ;
V_87 = F_34 ( V_2 , & V_4 -> V_71 [ V_73 ] ,
V_72 , V_73 ) ;
if ( V_87 ) {
F_32 ( V_2 , L_10 , V_73 ) ;
goto error;
}
}
return 0 ;
error:
if ( V_106 )
F_44 ( V_2 ) ;
return V_87 ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_49 ( F_3 ( V_2 ) , V_109 ,
V_110 ,
~ V_111 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
unsigned long V_53 ;
F_17 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
F_51 ( F_52 ( V_2 ) ) ;
F_15 ( F_3 ( V_2 ) , V_50 ,
V_112 ) ;
F_19 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
F_48 ( V_2 ) ;
F_53 ( F_52 ( V_2 ) ) ;
F_16 ( V_2 ) ;
if ( F_46 ( V_2 ) )
return - V_20 ;
if ( F_10 ( V_2 ) . V_113 ) {
F_54 ( F_3 ( V_2 ) , V_114 ,
0x800FFFFF ) ;
}
F_55 ( V_115 , & V_2 -> V_60 -> V_116 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_87 ;
F_54 ( F_3 ( V_2 ) , V_117 ,
V_118 ) ;
V_87 = F_57 ( F_3 ( V_2 ) , V_117 ,
V_118 ,
V_118 ,
V_119 ) ;
F_23 ( V_2 , L_11 , V_87 < 0 ? L_12 : L_13 ) ;
return V_87 ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_87 ;
F_23 ( V_2 , L_14 ) ;
V_87 = F_56 ( V_2 ) ;
if ( V_87 >= 0 )
return 0 ;
F_54 ( F_3 ( V_2 ) , V_117 ,
V_120 ) ;
V_87 = F_57 ( F_3 ( V_2 ) , V_117 ,
~ V_121 ,
V_121 , 150000 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 = F_56 ( V_2 ) ;
if ( V_87 >= 0 )
return 0 ;
return V_87 ;
}
static int F_59 ( struct V_1 * V_2 )
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
F_58 ( V_2 ) ) {
F_60 ( V_2 , L_15 ) ;
return - V_136 ;
}
if ( F_61 ( F_3 ( V_2 ) , V_137 ) &
V_138 )
F_62 ( V_139 , & V_2 -> V_60 -> V_116 ) ;
else
F_55 ( V_139 , & V_2 -> V_60 -> V_116 ) ;
if ( F_63 ( V_2 -> V_60 ) ) {
F_64 ( F_52 ( V_2 ) , true ) ;
F_65 ( V_2 ) ;
return - V_140 ;
}
F_66 ( F_3 ( V_2 ) , V_141 , 0xFFFFFFFF ) ;
V_87 = F_50 ( V_2 ) ;
if ( V_87 ) {
F_32 ( V_2 , L_16 ) ;
return V_87 ;
}
F_66 ( F_3 ( V_2 ) , V_142 , V_143 ) ;
F_66 ( F_3 ( V_2 ) , V_142 ,
V_144 ) ;
F_66 ( F_3 ( V_2 ) , V_141 , 0xFFFFFFFF ) ;
F_65 ( V_2 ) ;
F_66 ( F_3 ( V_2 ) , V_142 , V_143 ) ;
F_66 ( F_3 ( V_2 ) , V_142 , V_143 ) ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 , T_1 V_145 )
{
F_47 ( F_3 ( V_2 ) , V_107 , V_145 ) ;
}
static void F_68 ( struct V_1 * V_2 )
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
F_69 ( F_3 ( V_2 ) , V_152 ) ;
V_148 = V_4 -> V_151 + V_153 ;
for (; V_148 < V_4 -> V_151 + V_154 ;
V_148 += 4 )
F_70 ( F_3 ( V_2 ) , V_148 , 0 ) ;
for (; V_148 < V_4 -> V_151 + V_155 ;
V_148 += 4 )
F_70 ( F_3 ( V_2 ) , V_148 , 0 ) ;
for (; V_148 < V_4 -> V_151 +
F_71 ( F_10 ( V_2 ) . V_98 ) ;
V_148 += 4 )
F_70 ( F_3 ( V_2 ) , V_148 , 0 ) ;
F_47 ( F_3 ( V_2 ) , V_156 ,
V_4 -> V_100 . V_69 >> 10 ) ;
for ( V_149 = 0 ; V_149 < V_157 ; V_149 ++ )
F_14 ( F_3 ( V_2 ) , F_72 ( V_149 ) ,
V_158 |
V_159 ) ;
V_150 = F_73 ( F_3 ( V_2 ) , V_160 ) ;
F_14 ( F_3 ( V_2 ) , V_160 ,
V_150 | V_161 ) ;
F_47 ( F_3 ( V_2 ) , V_162 ,
F_74 ( V_2 ) ) ;
F_47 ( F_3 ( V_2 ) , V_163 , 0 ) ;
for ( V_21 = 0 ; V_21 < F_10 ( V_2 ) . V_98 ; V_21 ++ ) {
F_47 ( F_3 ( V_2 ) , F_75 ( V_21 ) , 0 ) ;
F_14 ( F_3 ( V_2 ) , V_164 , 0 | ( V_21 << 8 ) ) ;
F_70 ( F_3 ( V_2 ) , V_4 -> V_151 +
F_76 ( V_21 ) , 0 ) ;
F_70 ( F_3 ( V_2 ) , V_4 -> V_151 +
F_76 ( V_21 ) +
sizeof( T_1 ) ,
( ( V_165 <<
V_166 ) &
V_167 ) |
( ( V_168 <<
V_169 ) &
V_170 ) ) ;
}
F_47 ( F_3 ( V_2 ) , V_171 ,
F_77 ( 0 , F_10 ( V_2 ) . V_98 ) ) ;
F_67 ( V_2 , F_77 ( 0 , 7 ) ) ;
if ( V_2 -> V_60 -> V_172 != F_78 ( V_125 ) )
V_147 = V_173 ;
else
V_147 = V_174 ;
F_79 ( V_2 , V_2 -> V_60 -> V_83 , 0 ) ;
memset ( & V_4 -> V_175 [ 0 ] , 0 ,
sizeof( V_4 -> V_175 ) ) ;
for ( V_21 = 0 ; V_21 < 4 ; V_21 ++ )
F_80 ( & V_4 -> V_176 [ V_21 ] , 0 ) ;
V_4 -> V_177 = 0 ;
F_36 ( F_81 ( V_174 ) <
V_178 ) ;
F_36 ( F_81 ( V_173 ) <
V_178 ) ;
for ( V_21 = 0 ; V_21 < V_178 ; V_21 ++ ) {
int V_179 = V_147 [ V_21 ] . V_179 ;
int V_180 = V_147 [ V_21 ] . V_180 ;
F_82 ( V_4 , V_21 ) ;
if ( V_179 == V_181 )
continue;
if ( V_180 != V_182 )
F_35 ( & V_4 -> V_71 [ V_21 ] , V_180 , V_21 ) ;
F_83 ( V_2 , & V_4 -> V_71 [ V_21 ] ,
V_179 , 0 ) ;
}
F_19 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
F_84 ( F_3 ( V_2 ) , V_183 ,
V_184 ) ;
}
static int F_85 ( struct V_1 * V_2 )
{
int V_185 , V_73 ;
unsigned long V_53 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_17 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
F_67 ( V_2 , 0 ) ;
for ( V_185 = 0 ; V_185 < V_157 ; V_185 ++ ) {
F_14 ( F_3 ( V_2 ) ,
F_72 ( V_185 ) , 0x0 ) ;
if ( F_25 ( F_3 ( V_2 ) , V_186 ,
F_86 ( V_185 ) ,
1000 ) )
F_32 ( V_2 , L_17
L_18 , V_185 ,
F_73 ( F_3 ( V_2 ) ,
V_186 ) ) ;
}
F_19 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
if ( ! V_4 -> V_71 ) {
F_60 ( V_2 , L_19 ) ;
return 0 ;
}
for ( V_73 = 0 ; V_73 < F_10 ( V_2 ) . V_98 ; V_73 ++ )
F_39 ( V_2 , V_73 ) ;
return 0 ;
}
static void F_87 ( struct V_1 * V_2 )
{
unsigned long V_53 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_17 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
F_88 ( V_2 ) ;
F_19 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
F_89 ( V_2 ) ;
if ( F_90 ( V_187 , & V_2 -> V_60 -> V_116 ) ) {
F_85 ( V_2 ) ;
F_24 ( V_2 ) ;
F_47 ( F_3 ( V_2 ) , V_188 ,
V_189 ) ;
F_91 ( 5 ) ;
}
F_92 ( F_3 ( V_2 ) , V_137 ,
V_190 ) ;
F_93 ( F_52 ( V_2 ) ) ;
F_17 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
F_88 ( V_2 ) ;
F_19 ( & V_2 -> V_60 -> V_9 , V_53 ) ;
F_94 ( F_3 ( V_2 ) -> V_191 ) ;
F_95 ( & V_4 -> V_192 ) ;
F_66 ( F_3 ( V_2 ) , V_193 , V_194 ) ;
}
static int F_96 ( struct V_1 * V_2 , struct V_195 * V_196 ,
struct V_84 * V_197 , enum V_198 V_199 ,
T_5 V_200 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_201 * V_202 = (struct V_201 * ) V_196 -> V_203 ;
struct V_204 * V_205 = F_97 ( V_196 ) ;
struct V_206 * V_207 = (struct V_206 * ) V_197 -> V_208 ;
struct V_209 * V_210 ;
struct V_70 * V_71 ;
struct V_88 * V_81 ;
T_6 V_211 = 0 ;
T_6 V_212 ;
T_6 V_213 ;
T_4 V_214 , V_215 , V_216 ;
T_4 V_217 = 0 ;
T_5 V_218 = 0 ;
T_5 V_73 ;
T_5 V_219 = 0 ;
bool V_220 = false ;
T_7 V_221 = V_202 -> V_222 ;
T_5 V_223 = F_98 ( V_221 ) ;
if ( V_205 -> V_53 & V_224 ) {
V_73 = V_4 -> V_132 [ V_199 ] ;
V_202 -> V_222 |=
F_99 ( V_225 ) ;
} else if ( V_205 -> V_53 & V_226 )
V_73 = V_227 ;
else
V_73 =
V_4 -> V_124 [ V_199 ] [ F_100 ( V_196 ) ] ;
if ( F_101 ( V_221 ) && ! F_102 ( V_221 ) ) {
T_5 * V_228 = NULL ;
struct V_229 * V_230 ;
V_228 = F_103 ( V_202 ) ;
V_219 = V_228 [ 0 ] & V_231 ;
V_230 = & V_2 -> V_60 -> V_230 [ V_200 ] [ V_219 ] ;
if ( F_104 ( V_219 >= V_232 ) )
return - 1 ;
V_217 = V_230 -> V_217 ;
V_217 &= V_233 ;
V_202 -> V_234 = V_202 -> V_234 &
F_99 ( V_235 ) ;
V_202 -> V_234 |= F_99 ( V_217 ) ;
V_217 += 0x10 ;
if ( V_205 -> V_53 & V_236 ) {
F_104 ( V_230 -> V_237 . V_238 != V_239 ) ;
V_73 = V_230 -> V_237 . V_73 ;
V_220 = true ;
}
}
memcpy ( V_207 -> V_202 , V_202 , V_223 ) ;
V_71 = & V_4 -> V_71 [ V_73 ] ;
V_81 = & V_71 -> V_81 ;
V_71 -> V_79 [ V_81 -> V_96 ] = V_196 ;
V_71 -> V_78 [ V_81 -> V_96 ] = V_197 ;
V_197 -> V_202 . V_78 = V_240 ;
V_197 -> V_202 . V_241 = F_99 ( ( T_4 ) ( F_105 ( V_73 ) |
F_106 ( V_81 -> V_96 ) ) ) ;
V_210 = & V_71 -> V_77 [ V_81 -> V_96 ] ;
V_214 = sizeof( struct V_206 ) +
sizeof( struct V_242 ) + V_223 ;
V_215 = ( V_214 + 3 ) & ~ 3 ;
if ( V_215 != V_214 )
V_207 -> V_243 |= V_244 ;
V_212 = F_107 ( F_3 ( V_2 ) -> V_8 ,
& V_197 -> V_202 , V_215 ,
V_92 ) ;
if ( F_28 ( F_108 ( F_3 ( V_2 ) -> V_8 , V_212 ) ) )
return - 1 ;
F_109 ( V_210 , V_245 , V_212 ) ;
F_110 ( V_210 , V_214 , V_215 ) ;
if ( ! F_111 ( V_221 ) ) {
V_71 -> V_61 = 1 ;
} else {
V_218 = 1 ;
V_71 -> V_61 = 0 ;
}
V_216 = V_196 -> V_214 - V_223 ;
if ( V_216 > 0 ) {
V_211 = F_107 ( F_3 ( V_2 ) -> V_8 , V_196 -> V_203 + V_223 ,
V_216 , V_94 ) ;
if ( F_28 ( F_108 ( F_3 ( V_2 ) -> V_8 , V_211 ) ) ) {
F_112 ( F_3 ( V_2 ) -> V_8 ,
F_113 ( V_210 , V_245 ) ,
F_114 ( V_210 , V_214 ) ,
V_92 ) ;
return - 1 ;
}
}
F_115 ( V_2 , V_71 , V_212 , V_215 , 1 ) ;
if ( V_216 > 0 )
F_115 ( V_2 , V_71 , V_211 ,
V_216 , 0 ) ;
V_213 = V_212 + sizeof( struct V_242 ) +
F_116 ( struct V_206 , V_246 ) ;
F_117 ( F_3 ( V_2 ) -> V_8 , V_212 , V_215 ,
V_92 ) ;
V_207 -> V_247 = F_118 ( V_213 ) ;
V_207 -> V_248 = F_119 ( V_213 ) ;
F_120 ( V_2 , L_20 ,
F_121 ( V_197 -> V_202 . V_241 ) ) ;
F_120 ( V_2 , L_21 , F_122 ( V_207 -> V_243 ) ) ;
F_123 ( V_2 , V_249 , ( T_5 * ) V_207 , sizeof( * V_207 ) ) ;
F_123 ( V_2 , V_249 , ( T_5 * ) V_207 -> V_202 , V_223 ) ;
F_124 ( V_2 , V_71 , F_121 ( V_207 -> V_214 ) ) ;
F_125 ( F_3 ( V_2 ) -> V_8 , V_212 , V_215 ,
V_92 ) ;
F_126 ( F_52 ( V_2 ) ,
& ( (struct V_75 * ) V_71 -> V_80 ) [ V_71 -> V_81 . V_96 ] ,
sizeof( struct V_75 ) ,
& V_197 -> V_202 , V_215 ,
V_196 -> V_203 + V_223 , V_216 ) ;
V_81 -> V_96 = F_42 ( V_81 -> V_96 , V_81 -> V_91 ) ;
F_127 ( V_2 , V_71 ) ;
if ( F_101 ( V_221 ) && ! F_102 ( V_221 ) ) {
V_2 -> V_60 -> V_230 [ V_200 ] [ V_219 ] . V_250 ++ ;
if ( ! F_111 ( V_221 ) )
V_2 -> V_60 -> V_230 [ V_200 ] [ V_219 ] . V_217 =
V_217 ;
}
if ( F_128 ( V_81 ) < V_81 -> V_251 ) {
if ( V_218 ) {
V_71 -> V_61 = 1 ;
F_127 ( V_2 , V_71 ) ;
} else {
F_129 ( V_2 , V_71 ) ;
}
}
return 0 ;
}
static void F_130 ( struct V_1 * V_2 )
{
F_66 ( F_3 ( V_2 ) , V_193 , 0 ) ;
}
static int F_131 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
int V_52 ;
V_4 -> V_252 = V_253 ;
F_132 ( & V_4 -> V_192 , ( void (*) ( unsigned long ) )
V_254 , ( unsigned long ) V_2 ) ;
F_133 ( V_2 ) ;
V_52 = F_134 ( F_3 ( V_2 ) -> V_191 , V_255 , V_256 ,
V_257 , V_2 ) ;
if ( V_52 ) {
F_32 ( V_2 , L_22 , F_3 ( V_2 ) -> V_191 ) ;
F_135 ( V_2 ) ;
return V_52 ;
}
F_136 ( & V_4 -> V_258 , V_259 ) ;
return 0 ;
}
static int F_137 ( struct V_1 * V_2 ,
int V_200 , T_5 V_219 , int V_73 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_88 * V_81 = & V_4 -> V_71 [ V_73 ] . V_81 ;
struct V_229 * V_230 = & V_2 -> V_60 -> V_230 [ V_200 ] [ V_219 ] ;
F_138 ( & V_2 -> V_60 -> V_95 ) ;
switch ( V_2 -> V_60 -> V_230 [ V_200 ] [ V_219 ] . V_237 . V_238 ) {
case V_260 :
if ( ( V_73 == V_230 -> V_237 . V_73 ) &&
( V_81 -> V_97 == V_81 -> V_96 ) ) {
F_139 ( V_2 ,
L_23 ) ;
F_140 ( V_2 , V_73 ) ;
V_230 -> V_237 . V_238 = V_261 ;
F_141 ( F_52 ( V_2 ) ,
V_262 ,
V_200 , V_219 ) ;
F_142 ( V_2 , & V_4 -> V_71 [ V_73 ] ) ;
}
break;
case V_263 :
if ( V_230 -> V_250 == 0 ) {
F_139 ( V_2 ,
L_24 ) ;
V_230 -> V_237 . V_238 = V_239 ;
F_143 ( F_52 ( V_2 ) ,
V_262 ,
V_200 , V_219 ) ;
}
break;
default:
break;
}
return 0 ;
}
static void F_144 ( struct V_1 * V_2 ,
int V_200 , int V_219 , int V_264 )
{
F_138 ( & V_2 -> V_60 -> V_95 ) ;
if ( V_2 -> V_60 -> V_230 [ V_200 ] [ V_219 ] . V_250 >= V_264 )
V_2 -> V_60 -> V_230 [ V_200 ] [ V_219 ] . V_250 -= V_264 ;
else {
F_120 ( V_2 , L_25 ,
V_2 -> V_60 -> V_230 [ V_200 ] [ V_219 ] . V_250 ,
V_264 ) ;
V_2 -> V_60 -> V_230 [ V_200 ] [ V_219 ] . V_250 = 0 ;
}
}
static void F_145 ( struct V_1 * V_2 , int V_200 , int V_219 ,
int V_73 , int V_265 , T_1 V_116 ,
struct V_266 * V_79 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 = & V_4 -> V_71 [ V_73 ] ;
enum V_267 V_268 ;
int V_269 = V_265 & ( V_71 -> V_81 . V_91 - 1 ) ;
int V_264 = 0 ;
bool V_270 ;
V_71 -> V_271 = V_272 ;
if ( V_71 -> V_273 ) {
V_268 =
V_2 -> V_60 -> V_230 [ V_71 -> V_200 ] [ V_71 -> V_219 ] . V_237 . V_238 ;
V_270 = ( V_268 != V_260 ) ;
} else {
V_270 = ( V_116 != V_274 ) ;
}
if ( V_71 -> V_81 . V_97 != V_269 ) {
F_146 ( V_2 , L_26
L_27 ,
V_265 , V_269 , V_73 , V_71 -> V_275 ) ;
V_264 = F_147 ( V_2 , V_73 , V_269 , V_79 ) ;
if ( F_128 ( & V_71 -> V_81 ) > V_71 -> V_81 . V_276 && V_270 )
F_142 ( V_2 , V_71 ) ;
}
F_144 ( V_2 , V_200 , V_219 , V_264 ) ;
F_137 ( V_2 , V_200 , V_219 , V_73 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
F_44 ( V_2 ) ;
F_22 ( V_2 ) ;
F_149 ( F_3 ( V_2 ) -> V_191 , V_2 ) ;
F_135 ( V_2 ) ;
V_2 -> V_60 -> V_2 = NULL ;
F_33 ( V_2 ) ;
}
static int F_150 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_60 -> V_277 ) {
F_93 ( F_52 ( V_2 ) ) ;
} else {
F_88 ( V_2 ) ;
F_92 ( F_3 ( V_2 ) , V_137 ,
V_190 ) ;
}
return 0 ;
}
static int F_151 ( struct V_1 * V_2 )
{
bool V_278 = false ;
F_65 ( V_2 ) ;
if ( ! ( F_61 ( F_3 ( V_2 ) , V_137 ) &
V_138 ) )
V_278 = true ;
if ( V_278 )
F_55 ( V_139 , & V_2 -> V_60 -> V_116 ) ;
else
F_62 ( V_139 , & V_2 -> V_60 -> V_116 ) ;
F_64 ( F_52 ( V_2 ) , V_278 ) ;
return 0 ;
}
static void F_152 ( struct V_1 * V_2 ,
enum V_198 V_199 )
{
T_5 V_180 , V_73 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
for ( V_180 = 0 ; V_180 < V_279 ; V_180 ++ ) {
V_73 = V_4 -> V_124 [ V_199 ] [ V_180 ] ;
F_23 ( V_2 , L_28 ,
V_180 ,
( F_153 ( & V_4 -> V_176 [ V_180 ] ) > 0 )
? L_29 : L_30 ) ;
F_142 ( V_2 , & V_4 -> V_71 [ V_73 ] ) ;
}
}
static struct V_1 * F_154 ( struct V_280 * V_60 )
{
struct V_1 * V_1 = F_155 ( sizeof( struct V_1 ) +
sizeof( struct V_3 ) ,
V_16 ) ;
if ( V_1 ) {
struct V_3 * V_4 =
F_2 ( V_1 ) ;
V_1 -> V_281 = & V_282 ;
V_1 -> V_60 = V_60 ;
V_4 -> V_2 = V_1 ;
F_4 ( & V_1 -> V_93 ) ;
}
return V_1 ;
}
static void F_156 ( struct V_1 * V_2 , int V_73 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_129 ( V_2 , & V_4 -> V_71 [ V_73 ] ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 ;
struct V_88 * V_81 ;
int V_283 ;
unsigned long V_284 = V_272 ;
int V_87 = 0 ;
for ( V_283 = 0 ; V_283 < F_10 ( V_2 ) . V_98 ; V_283 ++ ) {
if ( V_283 == V_2 -> V_60 -> V_83 )
continue;
V_71 = & V_4 -> V_71 [ V_283 ] ;
V_81 = & V_71 -> V_81 ;
while ( V_81 -> V_97 != V_81 -> V_96 && ! F_158 ( V_272 ,
V_284 + F_159 ( V_285 ) ) )
F_160 ( 1 ) ;
if ( V_81 -> V_97 != V_81 -> V_96 ) {
F_32 ( V_2 , L_31 ) ;
V_87 = - V_286 ;
break;
}
}
return V_87 ;
}
static int F_161 ( struct V_1 * V_2 , int V_283 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 = & V_4 -> V_71 [ V_283 ] ;
struct V_88 * V_81 = & V_71 -> V_81 ;
unsigned long V_287 ;
if ( V_81 -> V_97 == V_81 -> V_96 ) {
V_71 -> V_271 = V_272 ;
return 0 ;
}
V_287 = V_71 -> V_271 +
F_159 ( F_10 ( V_2 ) . V_288 ) ;
if ( F_158 ( V_272 , V_287 ) ) {
F_32 ( V_2 , L_32 , V_81 -> V_86 ,
F_10 ( V_2 ) . V_288 ) ;
F_32 ( V_2 , L_33 ,
V_81 -> V_97 , V_81 -> V_96 ) ;
return 1 ;
}
return 0 ;
}
static const char * F_162 ( int V_78 )
{
switch ( V_78 ) {
F_163 ( V_43 ) ;
F_163 ( V_42 ) ;
F_163 ( V_289 ) ;
F_163 ( V_40 ) ;
F_163 ( V_290 ) ;
F_163 ( V_63 ) ;
F_163 ( V_291 ) ;
F_163 ( V_186 ) ;
F_163 ( V_292 ) ;
default:
return L_34 ;
}
}
int F_164 ( struct V_1 * V_2 , char * * V_293 , bool V_294 )
{
int V_21 ;
#ifdef F_165
int V_295 = 0 ;
T_2 V_296 = 0 ;
#endif
static const T_1 V_297 [] = {
V_43 ,
V_42 ,
V_289 ,
V_40 ,
V_290 ,
V_63 ,
V_291 ,
V_186 ,
V_292
} ;
#ifdef F_165
if ( V_294 ) {
V_296 = F_81 ( V_297 ) * 48 + 40 ;
* V_293 = F_31 ( V_296 , V_16 ) ;
if ( ! * V_293 )
return - V_20 ;
V_295 += F_166 ( * V_293 + V_295 , V_296 - V_295 ,
L_35 ) ;
for ( V_21 = 0 ; V_21 < F_81 ( V_297 ) ; V_21 ++ ) {
V_295 += F_166 ( * V_293 + V_295 , V_296 - V_295 ,
L_36 ,
F_162 ( V_297 [ V_21 ] ) ,
F_73 ( F_3 ( V_2 ) , V_297 [ V_21 ] ) ) ;
}
return V_295 ;
}
#endif
F_32 ( V_2 , L_35 ) ;
for ( V_21 = 0 ; V_21 < F_81 ( V_297 ) ; V_21 ++ ) {
F_32 ( V_2 , L_36 ,
F_162 ( V_297 [ V_21 ] ) ,
F_73 ( F_3 ( V_2 ) , V_297 [ V_21 ] ) ) ;
}
return 0 ;
}
static const char * F_167 ( int V_78 )
{
switch ( V_78 ) {
F_163 ( V_117 ) ;
F_163 ( V_50 ) ;
F_163 ( V_141 ) ;
F_163 ( V_298 ) ;
F_163 ( V_299 ) ;
F_163 ( V_300 ) ;
F_163 ( V_193 ) ;
F_163 ( V_137 ) ;
F_163 ( V_301 ) ;
F_163 ( V_302 ) ;
F_163 ( V_303 ) ;
F_163 ( V_304 ) ;
F_163 ( V_305 ) ;
F_163 ( V_306 ) ;
F_163 ( V_307 ) ;
F_163 ( V_308 ) ;
F_163 ( V_309 ) ;
F_163 ( V_310 ) ;
F_163 ( V_311 ) ;
F_163 ( V_312 ) ;
F_163 ( V_313 ) ;
F_163 ( V_314 ) ;
F_163 ( V_315 ) ;
default:
return L_34 ;
}
}
void F_168 ( struct V_1 * V_2 )
{
int V_21 ;
static const T_1 V_316 [] = {
V_117 ,
V_50 ,
V_141 ,
V_298 ,
V_299 ,
V_300 ,
V_193 ,
V_137 ,
V_301 ,
V_302 ,
V_303 ,
V_304 ,
V_305 ,
V_306 ,
V_307 ,
V_308 ,
V_309 ,
V_310 ,
V_311 ,
V_312 ,
V_313 ,
V_314 ,
V_315
} ;
F_32 ( V_2 , L_37 ) ;
F_32 ( V_2 , L_38
L_39 ) ;
for ( V_21 = 0 ; V_21 < F_81 ( V_316 ) ; V_21 ++ ) {
F_32 ( V_2 , L_40 ,
F_167 ( V_316 [ V_21 ] ) ,
F_61 ( F_3 ( V_2 ) , V_316 [ V_21 ] ) ) ;
}
}
static int F_169 ( struct V_317 * V_317 , struct V_318 * V_318 )
{
V_318 -> V_319 = V_317 -> V_320 ;
return 0 ;
}
static T_8 F_170 ( struct V_318 * V_318 ,
char T_9 * V_321 ,
T_2 V_322 , T_10 * V_323 )
{
struct V_1 * V_2 = V_318 -> V_319 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_70 * V_71 ;
struct V_88 * V_81 ;
char * V_293 ;
int V_295 = 0 ;
int V_283 ;
int V_87 ;
const T_2 V_296 = sizeof( char ) * 64 * F_10 ( V_2 ) . V_98 ;
if ( ! V_4 -> V_71 ) {
F_32 ( V_2 , L_41 ) ;
return - V_324 ;
}
V_293 = F_155 ( V_296 , V_16 ) ;
if ( ! V_293 )
return - V_20 ;
for ( V_283 = 0 ; V_283 < F_10 ( V_2 ) . V_98 ; V_283 ++ ) {
V_71 = & V_4 -> V_71 [ V_283 ] ;
V_81 = & V_71 -> V_81 ;
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 ,
L_42
L_43 ,
V_283 , V_81 -> V_97 , V_81 -> V_96 ,
! ! F_90 ( V_283 , V_4 -> V_175 ) ,
V_71 -> V_275 , V_71 -> V_275 & 3 ,
( V_71 -> V_275 >> 2 ) & 0x1f ) ;
if ( V_283 >= 4 )
continue;
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 ,
L_44 ,
F_153 ( & V_4 -> V_176 [ V_283 ] ) ) ;
}
V_87 = F_171 ( V_321 , V_322 , V_323 , V_293 , V_295 ) ;
F_33 ( V_293 ) ;
return V_87 ;
}
static T_8 F_172 ( struct V_318 * V_318 ,
char T_9 * V_321 ,
T_2 V_322 , T_10 * V_323 ) {
struct V_1 * V_2 = V_318 -> V_319 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
char V_293 [ 256 ] ;
int V_295 = 0 ;
const T_2 V_296 = sizeof( V_293 ) ;
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 , L_45 ,
V_6 -> V_56 ) ;
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 , L_46 ,
V_6 -> V_57 ) ;
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 , L_47 ,
V_6 -> V_59 ) ;
if ( V_6 -> V_11 ) {
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 , L_48 ,
F_121 ( V_6 -> V_11 -> V_325 ) & 0x0FFF ) ;
} else {
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 ,
L_49 ) ;
}
return F_171 ( V_321 , V_322 , V_323 , V_293 , V_295 ) ;
}
static T_8 F_173 ( struct V_318 * V_318 ,
char T_9 * V_321 ,
T_2 V_322 , T_10 * V_323 )
{
struct V_1 * V_2 = V_318 -> V_319 ;
char * V_293 ;
int V_295 = 0 ;
T_8 V_87 = - V_20 ;
V_87 = V_295 = F_174 ( V_2 , true , & V_293 , true ) ;
if ( V_293 ) {
V_87 = F_171 ( V_321 , V_322 , V_323 , V_293 , V_295 ) ;
F_33 ( V_293 ) ;
}
return V_87 ;
}
static T_8 F_175 ( struct V_318 * V_318 ,
const char T_9 * V_321 ,
T_2 V_322 , T_10 * V_323 )
{
struct V_1 * V_2 = V_318 -> V_319 ;
T_1 V_326 ;
char V_293 [ 8 ] ;
int V_327 ;
memset ( V_293 , 0 , sizeof( V_293 ) ) ;
V_327 = F_176 ( V_322 , sizeof( V_293 ) - 1 ) ;
if ( F_177 ( V_293 , V_321 , V_327 ) )
return - V_328 ;
if ( sscanf ( V_293 , L_50 , & V_326 ) != 1 )
return - V_328 ;
if ( V_326 == 1 )
F_174 ( V_2 , true , NULL , false ) ;
return V_322 ;
}
static T_8 F_178 ( struct V_318 * V_318 ,
char T_9 * V_321 ,
T_2 V_322 , T_10 * V_323 ) {
struct V_1 * V_2 = V_318 -> V_319 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_329 * V_330 = & V_4 -> V_330 ;
int V_295 = 0 ;
char * V_293 ;
int V_296 = 24 * 64 ;
T_8 V_87 ;
V_293 = F_155 ( V_296 , V_16 ) ;
if ( ! V_293 ) {
F_32 ( V_2 , L_51 ) ;
return - V_20 ;
}
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 ,
L_52 ) ;
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 , L_53 ,
V_330 -> V_331 ) ;
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 , L_54 ,
V_330 -> V_332 ) ;
if ( V_330 -> V_332 || V_330 -> V_331 ) {
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 ,
L_55 ,
V_330 -> V_333 ) ;
}
#ifdef F_165
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 , L_56 ,
V_330 -> V_334 ) ;
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 , L_57 ,
V_330 -> V_335 ) ;
#endif
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 ,
L_58 , V_330 -> V_336 ) ;
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 , L_59 ,
V_330 -> V_337 ) ;
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 , L_60 ,
V_330 -> V_338 ) ;
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 ,
L_61 , V_330 -> V_339 ) ;
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 , L_62 ,
V_330 -> V_340 ) ;
V_295 += F_166 ( V_293 + V_295 , V_296 - V_295 , L_63 ,
V_330 -> V_341 ) ;
V_87 = F_171 ( V_321 , V_322 , V_323 , V_293 , V_295 ) ;
F_33 ( V_293 ) ;
return V_87 ;
}
static T_8 F_179 ( struct V_318 * V_318 ,
const char T_9 * V_321 ,
T_2 V_322 , T_10 * V_323 )
{
struct V_1 * V_2 = V_318 -> V_319 ;
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_329 * V_330 = & V_4 -> V_330 ;
char V_293 [ 8 ] ;
int V_327 ;
T_1 V_342 ;
memset ( V_293 , 0 , sizeof( V_293 ) ) ;
V_327 = F_176 ( V_322 , sizeof( V_293 ) - 1 ) ;
if ( F_177 ( V_293 , V_321 , V_327 ) )
return - V_328 ;
if ( sscanf ( V_293 , L_64 , & V_342 ) != 1 )
return - V_328 ;
if ( V_342 == 0 )
memset ( V_330 , 0 , sizeof( * V_330 ) ) ;
return V_322 ;
}
static T_8 F_180 ( struct V_318 * V_318 ,
const char T_9 * V_321 ,
T_2 V_322 , T_10 * V_323 )
{
struct V_1 * V_2 = V_318 -> V_319 ;
char V_293 [ 8 ] ;
int V_327 ;
int V_343 ;
memset ( V_293 , 0 , sizeof( V_293 ) ) ;
V_327 = F_176 ( V_322 , sizeof( V_293 ) - 1 ) ;
if ( F_177 ( V_293 , V_321 , V_327 ) )
return - V_328 ;
if ( sscanf ( V_293 , L_50 , & V_343 ) != 1 )
return - V_328 ;
F_168 ( V_2 ) ;
return V_322 ;
}
static T_8 F_181 ( struct V_318 * V_318 ,
char T_9 * V_321 ,
T_2 V_322 , T_10 * V_323 )
{
struct V_1 * V_2 = V_318 -> V_319 ;
char * V_293 ;
int V_295 = 0 ;
T_8 V_87 = - V_328 ;
V_87 = V_295 = F_164 ( V_2 , & V_293 , true ) ;
if ( V_293 ) {
V_87 = F_171 ( V_321 ,
V_322 , V_323 , V_293 , V_295 ) ;
F_33 ( V_293 ) ;
}
return V_87 ;
}
static int F_182 ( struct V_1 * V_2 ,
struct V_344 * V_345 )
{
F_183 ( V_346 , V_345 , V_347 ) ;
F_183 ( V_348 , V_345 , V_347 ) ;
F_183 ( V_349 , V_345 , V_350 | V_347 ) ;
F_183 ( V_351 , V_345 , V_350 | V_347 ) ;
F_183 ( V_343 , V_345 , V_350 ) ;
F_183 ( V_352 , V_345 , V_347 ) ;
return 0 ;
}
static int F_182 ( struct V_1 * V_2 ,
struct V_344 * V_345 )
{ return 0 ; }
