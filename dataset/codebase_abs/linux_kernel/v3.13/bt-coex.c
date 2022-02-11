int F_1 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_3 -> V_4 . V_5 & V_6 ) )
return 0 ;
return F_2 ( V_2 , V_7 , V_8 ,
sizeof( struct V_9 ) ,
& V_10 ) ;
}
static enum V_11
F_3 ( struct V_1 * V_2 , const struct V_12 * V_13 )
{
struct V_14 * V_15 ;
enum V_11 V_16 ;
T_1 V_17 ;
F_4 () ;
V_15 = F_5 ( V_13 -> V_15 ) ;
if ( ! V_15 ||
V_15 -> V_18 . V_19 -> V_20 != V_21 ) {
F_6 () ;
return V_22 ;
}
V_16 = V_23 ;
if ( V_2 -> V_24 -> V_25 ) {
F_6 () ;
return V_16 ;
}
V_17 = * ( ( T_1 * ) V_15 -> V_26 ) ;
if ( V_2 -> V_27 . V_28 == V_17 )
V_16 = F_7 ( V_2 -> V_29 . V_30 ) ;
else if ( V_2 -> V_27 . V_31 == V_17 )
V_16 = F_7 ( V_2 -> V_29 . V_32 ) ;
F_6 () ;
return V_16 ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_33 * V_34 ;
struct V_35 V_36 = {
. V_37 = V_38 ,
. V_39 = { sizeof( * V_34 ) , } ,
. V_40 = { V_41 , } ,
. V_5 = V_8 ,
} ;
int V_16 ;
T_2 V_5 ;
if ( ! ( V_2 -> V_3 -> V_4 . V_5 & V_6 ) )
return 0 ;
V_34 = F_9 ( sizeof( * V_34 ) , V_42 ) ;
if ( ! V_34 )
return - V_43 ;
V_36 . V_44 [ 0 ] = V_34 ;
V_34 -> V_45 = 5 ;
V_34 -> V_46 = V_47 ,
V_34 -> V_48 = V_49 . V_50 ,
V_34 -> V_51 = 15 ,
V_34 -> V_52 = 15 ,
V_5 = V_49 . V_53 ?
V_54 : V_55 ;
V_5 |= V_56 | V_57 | V_58 ;
V_34 -> V_5 = F_10 ( V_5 ) ;
V_34 -> V_59 = F_10 ( V_60 |
V_61 |
V_62 |
V_63 |
V_64 |
V_65 |
V_66 |
V_67 |
V_68 |
V_69 |
V_70 |
V_71 |
V_72 |
V_73 |
V_74 |
V_75 ) ;
if ( V_2 -> V_24 -> V_25 )
memcpy ( & V_34 -> V_76 , V_77 ,
sizeof( V_77 ) ) ;
else
memcpy ( & V_34 -> V_76 , V_78 ,
sizeof( V_78 ) ) ;
memcpy ( & V_34 -> V_79 , V_80 ,
sizeof( V_80 ) ) ;
memcpy ( & V_34 -> V_81 , V_82 ,
sizeof( V_82 ) ) ;
V_34 -> V_83 =
F_10 ( V_84 [ V_85 ] ) ;
V_34 -> V_86 =
F_10 ( V_87 [ V_85 ] ) ;
memset ( & V_2 -> V_29 , 0 , sizeof( V_2 -> V_29 ) ) ;
memset ( & V_2 -> V_27 , 0 , sizeof( V_2 -> V_27 ) ) ;
V_16 = F_11 ( V_2 , & V_36 ) ;
F_12 ( V_34 ) ;
return V_16 ;
}
static int F_13 ( struct V_1 * V_2 ,
bool V_88 )
{
enum V_89 V_90 ;
struct V_33 * V_34 ;
struct V_91 * V_92 = & V_2 -> V_29 ;
struct V_35 V_36 = {
. V_37 = V_38 ,
. V_44 [ 0 ] = & V_34 ,
. V_39 = { sizeof( * V_34 ) , } ,
. V_40 = { V_41 , } ,
. V_5 = V_8 ,
} ;
int V_16 = 0 ;
F_14 ( & V_2 -> V_93 ) ;
if ( V_88 ) {
V_90 = V_94 ;
} else {
if ( F_15 ( V_92 , 3 , V_95 ) ||
F_15 ( V_92 , 3 , V_96 ) ||
F_15 ( V_92 , 3 , V_97 ) )
V_90 = V_98 ;
else
V_90 = V_85 ;
}
F_16 ( V_2 ,
L_1 ,
V_90 ,
F_15 ( V_92 , 3 , V_95 ) ? L_2 : L_3 ,
F_15 ( V_92 , 3 , V_96 ) ? L_2 : L_3 ,
F_15 ( V_92 , 3 , V_97 ) ? L_2 : L_3 ) ;
if ( V_90 == V_2 -> V_90 )
return 0 ;
V_2 -> V_90 = V_90 ;
V_34 = F_9 ( sizeof( * V_34 ) , V_42 ) ;
if ( ! V_34 )
return - V_43 ;
V_36 . V_44 [ 0 ] = V_34 ;
V_34 -> V_5 = F_10 ( V_54 ) ;
V_34 -> V_83 = F_10 ( V_84 [ V_90 ] ) ;
V_34 -> V_86 = F_10 ( V_87 [ V_90 ] ) ;
V_34 -> V_59 |= F_10 ( V_60 |
V_64 |
V_65 ) ;
F_16 ( V_2 , L_4 ,
V_84 [ V_90 ] ,
V_87 [ V_90 ] ) ;
V_16 = F_11 ( V_2 , & V_36 ) ;
F_12 ( V_34 ) ;
return V_16 ;
}
static int F_17 ( struct V_1 * V_2 , T_3 V_99 ,
bool V_100 )
{
struct V_33 * V_34 ;
struct V_35 V_36 = {
. V_37 = V_38 ,
. V_39 = { sizeof( * V_34 ) , } ,
. V_40 = { V_101 , } ,
. V_5 = V_102 ,
} ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
int V_16 ;
if ( V_99 == V_107 )
return 0 ;
V_104 = F_18 ( V_2 -> V_108 [ V_99 ] ,
F_19 ( & V_2 -> V_93 ) ) ;
if ( F_20 ( V_104 ) )
return 0 ;
V_106 = ( void * ) V_104 -> V_26 ;
if ( V_106 -> V_109 == V_100 )
return 0 ;
V_34 = F_9 ( sizeof( * V_34 ) , V_110 ) ;
if ( ! V_34 )
return - V_43 ;
V_36 . V_44 [ 0 ] = V_34 ;
V_34 -> V_5 = F_10 ( V_54 ) ;
V_34 -> V_59 =
F_10 ( V_60 | V_66 ) ;
V_34 -> V_111 = V_99 ;
if ( V_100 )
V_34 -> V_111 |= V_112 ;
F_16 ( V_2 , L_5 ,
V_100 ? L_6 : L_7 , V_99 ) ;
V_106 -> V_109 = V_100 ;
V_16 = F_11 ( V_2 , & V_36 ) ;
F_12 ( V_34 ) ;
return V_16 ;
}
static inline
void F_21 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
bool V_100 , int V_113 )
{
struct V_114 * V_115 = F_22 ( V_13 ) ;
V_115 -> V_116 . V_117 = V_113 ;
V_115 -> V_116 . V_118 =
V_100 ? V_119 : 0 ;
V_115 -> V_116 . V_120 =
V_100 ? V_121 : 0 ;
}
static void F_23 ( void * V_122 , T_3 * V_123 ,
struct V_12 * V_13 )
{
struct V_114 * V_115 = F_22 ( V_13 ) ;
struct V_124 * V_44 = V_122 ;
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_14 * V_15 ;
enum V_125 V_126 ;
int V_127 ;
F_14 ( & V_2 -> V_93 ) ;
if ( V_13 -> type != V_128 &&
V_13 -> type != V_129 )
return;
V_126 = V_130 ;
V_15 = F_5 ( V_13 -> V_15 ) ;
if ( ( ! V_15 ||
V_15 -> V_18 . V_19 -> V_20 != V_21 ) ) {
if ( V_13 -> type == V_128 && V_13 -> V_131 . V_132 )
F_24 ( V_2 , V_13 , V_133 ,
V_126 ) ;
F_21 ( V_2 , V_13 , false , 0 ) ;
return;
}
if ( V_13 -> type == V_129 ) {
if ( ! V_115 -> V_134 )
return;
V_44 -> V_88 = false ;
if ( V_15 == V_44 -> V_135 )
return;
V_44 -> V_136 = V_44 -> V_135 ;
V_44 -> V_135 = V_15 ;
return;
}
V_44 -> V_137 ++ ;
if ( ! V_13 -> V_131 . V_132 )
return;
if ( ! V_44 -> V_135 || V_44 -> V_135 == V_15 )
V_44 -> V_135 = V_15 ;
else if ( ! V_44 -> V_136 )
V_44 -> V_136 = V_15 ;
if ( F_7 ( V_44 -> V_92 -> V_138 ) >= V_139 )
V_126 = V_140 ;
else if ( F_7 ( V_44 -> V_92 -> V_138 ) >=
V_141 )
V_126 = V_142 ;
F_16 ( V_44 -> V_2 ,
L_8 ,
V_115 -> V_37 , V_44 -> V_92 -> V_143 ,
V_44 -> V_92 -> V_138 , V_126 ) ;
F_24 ( V_2 , V_13 , V_133 , V_126 ) ;
if ( F_3 ( V_2 , V_13 ) == V_22 ||
V_2 -> V_24 -> V_25 ) {
V_44 -> V_88 = false ;
F_21 ( V_2 , V_13 , false , 0 ) ;
return;
}
if ( ! V_44 -> V_92 -> V_143 ) {
if ( F_17 ( V_2 , V_115 -> V_144 , false ) )
F_25 ( V_2 , L_9 ) ;
V_44 -> V_88 = false ;
F_21 ( V_2 , V_13 , false , 0 ) ;
return;
}
V_127 = V_115 -> V_116 . V_145 ;
if ( ! V_127 )
V_127 = - 100 ;
if ( V_127 > V_119 ) {
if ( F_17 ( V_2 , V_115 -> V_144 , true ) )
F_25 ( V_2 , L_9 ) ;
} else if ( V_127 < V_121 ) {
if ( F_17 ( V_2 , V_115 -> V_144 , false ) )
F_25 ( V_2 , L_9 ) ;
V_44 -> V_88 = false ;
}
F_21 ( V_2 , V_13 , true , V_127 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_124 V_44 = {
. V_2 = V_2 ,
. V_92 = & V_2 -> V_29 ,
. V_88 = true ,
} ;
struct V_146 V_36 = {} ;
T_3 V_147 ;
F_4 () ;
F_27 (
V_2 -> V_148 , V_149 ,
F_23 , & V_44 ) ;
if ( V_44 . V_135 ) {
struct V_14 * V_19 = V_44 . V_135 ;
if ( F_28 ( ! V_19 -> V_18 . V_19 ) ) {
F_6 () ;
return;
}
if ( V_19 -> V_18 . V_150 < V_151 ) {
V_147 = 0 ;
V_36 . V_152 = 0 ;
} else {
V_36 . V_152 = 1 ;
if ( V_19 -> V_18 . V_153 >
V_19 -> V_18 . V_19 -> V_154 )
V_147 = 2 ;
else
V_147 = 1 ;
}
V_36 . V_155 =
V_156 [ V_19 -> V_18 . V_19 -> V_157 ] [ V_147 ] ;
V_36 . V_28 = * ( ( T_1 * ) V_44 . V_135 -> V_26 ) ;
}
if ( V_44 . V_136 ) {
struct V_14 * V_19 = V_44 . V_136 ;
if ( F_28 ( ! V_44 . V_136 -> V_18 . V_19 ) ) {
F_6 () ;
return;
}
if ( V_19 -> V_18 . V_150 < V_151 ) {
V_147 = 0 ;
V_36 . V_158 = 0 ;
} else {
V_36 . V_158 = 1 ;
if ( V_19 -> V_18 . V_153 >
V_19 -> V_18 . V_19 -> V_154 )
V_147 = 2 ;
else
V_147 = 1 ;
}
V_36 . V_159 =
V_156 [ V_19 -> V_18 . V_19 -> V_157 ] [ V_147 ] ;
V_36 . V_31 = * ( ( T_1 * ) V_44 . V_136 -> V_26 ) ;
}
F_6 () ;
if ( memcmp ( & V_36 , & V_2 -> V_27 , sizeof( V_36 ) ) ) {
if ( F_2 ( V_2 , V_160 , V_8 ,
sizeof( V_36 ) , & V_36 ) )
F_25 ( V_2 , L_10 ) ;
memcpy ( & V_2 -> V_27 , & V_36 , sizeof( V_36 ) ) ;
}
V_44 . V_88 = V_44 . V_88 && V_44 . V_137 ;
if ( F_13 ( V_2 , V_44 . V_88 ) )
F_25 ( V_2 , L_11 ) ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_161 * V_162 ,
struct V_163 * V_164 )
{
struct V_165 * V_166 = F_30 ( V_162 ) ;
struct V_91 * V_92 = ( void * ) V_166 -> V_44 ;
F_16 ( V_2 , L_12 ) ;
F_16 ( V_2 , L_13 ,
V_92 -> V_143 ? L_14 : L_15 ) ;
F_16 ( V_2 , L_16 , V_92 -> V_167 ) ;
F_16 ( V_2 , L_17 , V_92 -> V_168 ) ;
F_16 ( V_2 , L_18 ,
F_7 ( V_92 -> V_30 ) ) ;
F_16 ( V_2 , L_19 ,
F_7 ( V_92 -> V_32 ) ) ;
F_16 ( V_2 , L_20 ,
F_7 ( V_92 -> V_138 ) ) ;
F_16 ( V_2 , L_21 ,
V_92 -> V_169 ) ;
memcpy ( & V_2 -> V_29 , V_92 , sizeof( V_2 -> V_29 ) ) ;
F_26 ( V_2 ) ;
return 0 ;
}
static void F_31 ( void * V_122 , T_3 * V_123 ,
struct V_12 * V_13 )
{
struct V_114 * V_115 = ( void * ) V_13 -> V_26 ;
struct V_124 * V_44 = V_122 ;
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
struct V_14 * V_15 ;
F_4 () ;
V_15 = F_5 ( V_13 -> V_15 ) ;
if ( ! V_15 ||
V_15 -> V_18 . V_19 -> V_20 != V_21 ) {
F_6 () ;
return;
}
F_6 () ;
if ( V_13 -> type != V_128 ||
V_115 -> V_144 == V_107 )
return;
V_104 = F_18 ( V_2 -> V_108 [ V_115 -> V_144 ] ,
F_19 ( & V_2 -> V_93 ) ) ;
if ( F_20 ( V_104 ) )
return;
V_106 = ( void * ) V_104 -> V_26 ;
V_44 -> V_137 ++ ;
if ( ! V_106 -> V_109 )
V_44 -> V_88 = false ;
}
void F_32 ( struct V_1 * V_2 , struct V_12 * V_13 ,
enum V_170 V_171 )
{
struct V_114 * V_115 = ( void * ) V_13 -> V_26 ;
struct V_124 V_44 = {
. V_2 = V_2 ,
. V_88 = true ,
} ;
int V_16 ;
F_14 ( & V_2 -> V_93 ) ;
if ( F_33 ( V_115 -> V_144 == V_107 ) )
return;
if ( ! V_2 -> V_29 . V_143 )
return;
F_16 ( V_2 , L_22 , V_13 -> V_131 . V_172 ,
V_171 == V_173 ? L_23 : L_24 ) ;
if ( V_171 == V_174 || V_2 -> V_24 -> V_25 ||
F_3 ( V_2 , V_13 ) == V_22 )
V_16 = F_17 ( V_2 , V_115 -> V_144 ,
false ) ;
else
V_16 = F_17 ( V_2 , V_115 -> V_144 , true ) ;
if ( V_16 )
F_25 ( V_2 , L_25 ) ;
F_27 (
V_2 -> V_148 , V_149 ,
F_31 , & V_44 ) ;
V_44 . V_88 = V_44 . V_88 && V_44 . V_137 ;
if ( F_13 ( V_2 , V_44 . V_88 ) )
F_25 ( V_2 , L_11 ) ;
}
T_1 F_34 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
struct V_105 * V_106 = ( void * ) V_104 -> V_26 ;
enum V_11 V_175 ;
if ( F_7 ( V_2 -> V_29 . V_138 ) <
V_141 )
return V_176 ;
V_175 = F_3 ( V_2 , V_106 -> V_13 ) ;
if ( V_175 == V_22 )
return V_176 ;
return V_177 ;
}
bool F_35 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
struct V_105 * V_106 = ( void * ) V_104 -> V_26 ;
if ( F_7 ( V_2 -> V_29 . V_138 ) <
V_139 )
return true ;
return F_3 ( V_2 , V_106 -> V_13 ) == V_178 ;
}
void F_36 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_3 -> V_4 . V_5 & V_6 ) )
return;
F_26 ( V_2 ) ;
}
