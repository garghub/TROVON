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
V_75 |
V_76 ) ;
if ( V_2 -> V_24 -> V_25 )
memcpy ( & V_34 -> V_77 , V_78 ,
sizeof( V_78 ) ) ;
else
memcpy ( & V_34 -> V_77 , V_79 ,
sizeof( V_79 ) ) ;
memcpy ( & V_34 -> V_80 , V_81 ,
sizeof( V_81 ) ) ;
memcpy ( & V_34 -> V_82 , V_83 ,
sizeof( V_83 ) ) ;
V_34 -> V_84 =
F_10 ( V_85 [ V_86 ] ) ;
V_34 -> V_87 =
F_10 ( V_88 [ V_86 ] ) ;
memset ( & V_2 -> V_29 , 0 , sizeof( V_2 -> V_29 ) ) ;
memset ( & V_2 -> V_27 , 0 , sizeof( V_2 -> V_27 ) ) ;
V_16 = F_11 ( V_2 , & V_36 ) ;
F_12 ( V_34 ) ;
return V_16 ;
}
static int F_13 ( struct V_1 * V_2 ,
bool V_89 )
{
enum V_90 V_91 ;
struct V_33 * V_34 ;
struct V_92 * V_93 = & V_2 -> V_29 ;
struct V_35 V_36 = {
. V_37 = V_38 ,
. V_44 [ 0 ] = & V_34 ,
. V_39 = { sizeof( * V_34 ) , } ,
. V_40 = { V_41 , } ,
. V_5 = V_8 ,
} ;
int V_16 = 0 ;
F_14 ( & V_2 -> V_94 ) ;
if ( V_89 ) {
V_91 = V_95 ;
} else {
if ( F_15 ( V_93 , 3 , V_96 ) ||
F_15 ( V_93 , 3 , V_97 ) ||
F_15 ( V_93 , 3 , V_98 ) )
V_91 = V_99 ;
else
V_91 = V_86 ;
}
F_16 ( V_2 ,
L_1 ,
V_91 ,
F_15 ( V_93 , 3 , V_96 ) ? L_2 : L_3 ,
F_15 ( V_93 , 3 , V_97 ) ? L_2 : L_3 ,
F_15 ( V_93 , 3 , V_98 ) ? L_2 : L_3 ) ;
if ( V_91 == V_2 -> V_91 )
return 0 ;
V_2 -> V_91 = V_91 ;
V_34 = F_9 ( sizeof( * V_34 ) , V_42 ) ;
if ( ! V_34 )
return - V_43 ;
V_36 . V_44 [ 0 ] = V_34 ;
V_34 -> V_5 = F_10 ( V_54 ) ;
V_34 -> V_84 = F_10 ( V_85 [ V_91 ] ) ;
V_34 -> V_87 = F_10 ( V_88 [ V_91 ] ) ;
V_34 -> V_59 |= F_10 ( V_60 |
V_64 |
V_65 ) ;
F_16 ( V_2 , L_4 ,
V_85 [ V_91 ] ,
V_88 [ V_91 ] ) ;
V_16 = F_11 ( V_2 , & V_36 ) ;
F_12 ( V_34 ) ;
return V_16 ;
}
static int F_17 ( struct V_1 * V_2 , T_3 V_100 ,
bool V_101 )
{
struct V_33 * V_34 ;
struct V_35 V_36 = {
. V_37 = V_38 ,
. V_39 = { sizeof( * V_34 ) , } ,
. V_40 = { V_102 , } ,
. V_5 = V_103 ,
} ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
int V_16 ;
if ( V_100 == V_108 )
return 0 ;
V_105 = F_18 ( V_2 -> V_109 [ V_100 ] ,
F_19 ( & V_2 -> V_94 ) ) ;
if ( F_20 ( V_105 ) )
return 0 ;
V_107 = F_21 ( V_105 ) ;
if ( V_107 -> V_110 == V_101 )
return 0 ;
V_34 = F_9 ( sizeof( * V_34 ) , V_111 ) ;
if ( ! V_34 )
return - V_43 ;
V_36 . V_44 [ 0 ] = V_34 ;
V_34 -> V_5 = F_10 ( V_54 ) ;
V_34 -> V_59 =
F_10 ( V_60 | V_66 ) ;
V_34 -> V_112 = V_100 ;
if ( V_101 )
V_34 -> V_112 |= V_113 ;
F_16 ( V_2 , L_5 ,
V_101 ? L_6 : L_7 , V_100 ) ;
V_107 -> V_110 = V_101 ;
V_16 = F_11 ( V_2 , & V_36 ) ;
F_12 ( V_34 ) ;
return V_16 ;
}
static inline
void F_22 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
bool V_101 , int V_114 )
{
struct V_115 * V_116 = F_23 ( V_13 ) ;
V_116 -> V_117 . V_118 = V_114 ;
V_116 -> V_117 . V_119 =
V_101 ? V_120 : 0 ;
V_116 -> V_117 . V_121 =
V_101 ? V_122 : 0 ;
}
static void F_24 ( void * V_123 , T_3 * V_124 ,
struct V_12 * V_13 )
{
struct V_115 * V_116 = F_23 ( V_13 ) ;
struct V_125 * V_44 = V_123 ;
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_14 * V_15 ;
enum V_126 V_127 ;
int V_128 ;
F_14 ( & V_2 -> V_94 ) ;
if ( V_13 -> type != V_129 &&
V_13 -> type != V_130 )
return;
V_127 = V_131 ;
V_15 = F_5 ( V_13 -> V_15 ) ;
if ( ( ! V_15 ||
V_15 -> V_18 . V_19 -> V_20 != V_21 ) ) {
if ( V_13 -> type == V_129 && V_13 -> V_132 . V_133 )
F_25 ( V_2 , V_13 , V_134 ,
V_127 ) ;
F_22 ( V_2 , V_13 , false , 0 ) ;
return;
}
if ( V_13 -> type == V_130 ) {
if ( ! V_116 -> V_135 )
return;
V_44 -> V_89 = false ;
if ( V_15 == V_44 -> V_136 )
return;
V_44 -> V_137 = V_44 -> V_136 ;
V_44 -> V_136 = V_15 ;
return;
}
V_44 -> V_138 ++ ;
if ( ! V_13 -> V_132 . V_133 )
return;
if ( ! V_44 -> V_136 || V_44 -> V_136 == V_15 )
V_44 -> V_136 = V_15 ;
else if ( ! V_44 -> V_137 )
V_44 -> V_137 = V_15 ;
if ( F_7 ( V_44 -> V_93 -> V_139 ) >= V_140 )
V_127 = V_141 ;
else if ( F_7 ( V_44 -> V_93 -> V_139 ) >=
V_142 )
V_127 = V_143 ;
F_16 ( V_44 -> V_2 ,
L_8 ,
V_116 -> V_37 , V_44 -> V_93 -> V_144 ,
V_44 -> V_93 -> V_139 , V_127 ) ;
F_25 ( V_2 , V_13 , V_134 , V_127 ) ;
if ( F_3 ( V_2 , V_13 ) == V_22 ||
V_2 -> V_24 -> V_25 ) {
V_44 -> V_89 = false ;
F_22 ( V_2 , V_13 , false , 0 ) ;
return;
}
if ( ! V_44 -> V_93 -> V_144 ) {
if ( F_17 ( V_2 , V_116 -> V_145 , false ) )
F_26 ( V_2 , L_9 ) ;
V_44 -> V_89 = false ;
F_22 ( V_2 , V_13 , false , 0 ) ;
return;
}
V_128 = V_116 -> V_117 . V_146 ;
if ( ! V_128 )
V_128 = - 100 ;
if ( V_128 > V_120 ) {
if ( F_17 ( V_2 , V_116 -> V_145 , true ) )
F_26 ( V_2 , L_9 ) ;
} else if ( V_128 < V_122 ) {
if ( F_17 ( V_2 , V_116 -> V_145 , false ) )
F_26 ( V_2 , L_9 ) ;
V_44 -> V_89 = false ;
}
F_22 ( V_2 , V_13 , true , V_128 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_125 V_44 = {
. V_2 = V_2 ,
. V_93 = & V_2 -> V_29 ,
. V_89 = true ,
} ;
struct V_147 V_36 = {} ;
T_3 V_148 ;
F_4 () ;
F_28 (
V_2 -> V_149 , V_150 ,
F_24 , & V_44 ) ;
if ( V_44 . V_136 ) {
struct V_14 * V_19 = V_44 . V_136 ;
if ( F_29 ( ! V_19 -> V_18 . V_19 ) ) {
F_6 () ;
return;
}
if ( V_19 -> V_18 . V_151 < V_152 ) {
V_148 = 0 ;
V_36 . V_153 = 0 ;
} else {
V_36 . V_153 = 1 ;
if ( V_19 -> V_18 . V_154 >
V_19 -> V_18 . V_19 -> V_155 )
V_148 = 2 ;
else
V_148 = 1 ;
}
V_36 . V_156 =
V_157 [ V_19 -> V_18 . V_19 -> V_158 ] [ V_148 ] ;
V_36 . V_28 = * ( ( T_1 * ) V_44 . V_136 -> V_26 ) ;
}
if ( V_44 . V_137 ) {
struct V_14 * V_19 = V_44 . V_137 ;
if ( F_29 ( ! V_44 . V_137 -> V_18 . V_19 ) ) {
F_6 () ;
return;
}
if ( V_19 -> V_18 . V_151 < V_152 ) {
V_148 = 0 ;
V_36 . V_159 = 0 ;
} else {
V_36 . V_159 = 1 ;
if ( V_19 -> V_18 . V_154 >
V_19 -> V_18 . V_19 -> V_155 )
V_148 = 2 ;
else
V_148 = 1 ;
}
V_36 . V_160 =
V_157 [ V_19 -> V_18 . V_19 -> V_158 ] [ V_148 ] ;
V_36 . V_31 = * ( ( T_1 * ) V_44 . V_137 -> V_26 ) ;
}
F_6 () ;
if ( memcmp ( & V_36 , & V_2 -> V_27 , sizeof( V_36 ) ) ) {
if ( F_2 ( V_2 , V_161 , V_8 ,
sizeof( V_36 ) , & V_36 ) )
F_26 ( V_2 , L_10 ) ;
memcpy ( & V_2 -> V_27 , & V_36 , sizeof( V_36 ) ) ;
}
V_44 . V_89 = V_44 . V_89 && V_44 . V_138 ;
if ( F_13 ( V_2 , V_44 . V_89 ) )
F_26 ( V_2 , L_11 ) ;
}
int F_30 ( struct V_1 * V_2 ,
struct V_162 * V_163 ,
struct V_164 * V_165 )
{
struct V_166 * V_167 = F_31 ( V_163 ) ;
struct V_92 * V_93 = ( void * ) V_167 -> V_44 ;
F_16 ( V_2 , L_12 ) ;
F_16 ( V_2 , L_13 ,
V_93 -> V_144 ? L_14 : L_15 ) ;
F_16 ( V_2 , L_16 , V_93 -> V_168 ) ;
F_16 ( V_2 , L_17 , V_93 -> V_169 ) ;
F_16 ( V_2 , L_18 ,
F_7 ( V_93 -> V_30 ) ) ;
F_16 ( V_2 , L_19 ,
F_7 ( V_93 -> V_32 ) ) ;
F_16 ( V_2 , L_20 ,
F_7 ( V_93 -> V_139 ) ) ;
F_16 ( V_2 , L_21 ,
V_93 -> V_170 ) ;
memcpy ( & V_2 -> V_29 , V_93 , sizeof( V_2 -> V_29 ) ) ;
F_27 ( V_2 ) ;
return 0 ;
}
static void F_32 ( void * V_123 , T_3 * V_124 ,
struct V_12 * V_13 )
{
struct V_115 * V_116 = ( void * ) V_13 -> V_26 ;
struct V_125 * V_44 = V_123 ;
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
struct V_14 * V_15 ;
F_4 () ;
V_15 = F_5 ( V_13 -> V_15 ) ;
if ( ! V_15 ||
V_15 -> V_18 . V_19 -> V_20 != V_21 ) {
F_6 () ;
return;
}
F_6 () ;
if ( V_13 -> type != V_129 ||
V_116 -> V_145 == V_108 )
return;
V_105 = F_18 ( V_2 -> V_109 [ V_116 -> V_145 ] ,
F_19 ( & V_2 -> V_94 ) ) ;
if ( F_20 ( V_105 ) )
return;
V_107 = F_21 ( V_105 ) ;
V_44 -> V_138 ++ ;
if ( ! V_107 -> V_110 )
V_44 -> V_89 = false ;
}
void F_33 ( struct V_1 * V_2 , struct V_12 * V_13 ,
enum V_171 V_172 )
{
struct V_115 * V_116 = ( void * ) V_13 -> V_26 ;
struct V_125 V_44 = {
. V_2 = V_2 ,
. V_89 = true ,
} ;
int V_16 ;
F_14 ( & V_2 -> V_94 ) ;
if ( V_116 -> V_145 == V_108 )
return;
if ( ! V_2 -> V_29 . V_144 )
return;
F_16 ( V_2 , L_22 , V_13 -> V_132 . V_173 ,
V_172 == V_174 ? L_23 : L_24 ) ;
if ( V_172 == V_175 || V_2 -> V_24 -> V_25 ||
F_3 ( V_2 , V_13 ) == V_22 )
V_16 = F_17 ( V_2 , V_116 -> V_145 ,
false ) ;
else
V_16 = F_17 ( V_2 , V_116 -> V_145 , true ) ;
if ( V_16 )
F_26 ( V_2 , L_25 ) ;
F_28 (
V_2 -> V_149 , V_150 ,
F_32 , & V_44 ) ;
V_44 . V_89 = V_44 . V_89 && V_44 . V_138 ;
if ( F_13 ( V_2 , V_44 . V_89 ) )
F_26 ( V_2 , L_11 ) ;
}
T_1 F_34 ( struct V_1 * V_2 ,
struct V_104 * V_105 )
{
struct V_106 * V_107 = F_21 ( V_105 ) ;
enum V_11 V_176 ;
if ( F_7 ( V_2 -> V_29 . V_139 ) <
V_140 )
return V_177 ;
V_176 = F_3 ( V_2 , V_107 -> V_13 ) ;
if ( V_176 == V_22 )
return V_177 ;
return V_178 ;
}
bool F_35 ( struct V_1 * V_2 ,
struct V_104 * V_105 )
{
struct V_106 * V_107 = F_21 ( V_105 ) ;
if ( F_7 ( V_2 -> V_29 . V_139 ) <
V_140 )
return true ;
return F_3 ( V_2 , V_107 -> V_13 ) == V_179 ;
}
void F_36 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_3 -> V_4 . V_5 & V_6 ) )
return;
F_27 ( V_2 ) ;
}
