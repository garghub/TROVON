static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 ;
if ( F_4 ( V_6 , V_10 , V_7 ) )
return - V_11 ;
V_9 = F_5 ( V_6 , V_10 , V_12 ) ;
if ( V_9 == NULL ) {
F_6 ( L_1 ,
F_7 ( V_6 , V_10 ) ) ;
return - V_11 ;
}
if ( V_9 -> V_13 != V_14 &&
V_9 -> V_13 != V_15 ) {
F_6 ( L_2 , V_9 -> V_13 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_8 ( struct V_16 * V_17 ,
T_1 V_18 ,
struct V_19 * V_20 )
{
if ( V_18 == V_21 )
return 0 ;
memset ( V_20 -> V_22 , 0 , sizeof( V_20 -> V_22 ) ) ;
return F_9 ( V_17 , V_18 , V_20 -> V_22 ,
sizeof( V_20 -> V_22 ) ) ;
}
static int F_10 ( struct V_16 * V_17 ,
T_1 V_18 ,
struct V_19 * V_23 )
{
struct V_19 V_24 ;
int V_25 ;
if ( V_18 == V_21 )
return 0 ;
memset ( & V_24 . V_22 , 0 , sizeof( V_24 . V_22 ) ) ;
V_25 = F_9 ( V_17 , V_18 , V_24 . V_22 ,
sizeof( V_24 . V_22 ) ) ;
if ( V_25 )
return V_25 ;
if ( memcmp ( V_23 -> V_22 , V_24 . V_22 , sizeof( V_23 -> V_22 ) ) )
return - V_26 ;
return 0 ;
}
static void F_11 ( struct V_16 * V_17 )
{
char * V_27 ;
unsigned int V_28 , V_29 ;
for ( V_29 = 0 ; V_29 < V_17 -> V_30 ; V_29 ++ ) {
if ( V_17 -> V_31 [ V_29 ] . V_32 == 0 )
continue;
V_27 = F_12 ( V_17 -> V_31 [ V_29 ] . V_33 ) ;
V_28 = V_17 -> V_31 [ V_29 ] . V_34 & ~ V_35 ;
V_27 [ V_28 ] ^= 0x1 ;
F_13 ( V_17 -> V_31 [ V_29 ] . V_33 ) ;
return;
}
}
static
int F_14 ( struct V_36 * V_37 )
{
F_15 () ;
return 0 ;
}
static
int F_16 ( struct V_36 * V_37 )
{
return 0 ;
}
static
int F_17 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_5 * V_6 = V_39 -> V_40 ;
struct V_41 * V_42 ;
V_6 -> V_43 = V_39 -> V_44 . V_45 ;
V_42 = F_5 ( V_6 , V_46 , 0 ) ;
V_42 -> V_47 = 0 ;
V_42 -> V_48 = 0 ;
V_42 -> V_49 = V_37 -> V_50 -> V_51 ;
V_42 -> V_52 = V_39 -> V_44 . V_53 . V_54 . V_18 ;
if ( V_39 -> V_55 )
V_42 -> V_48 |= V_56 ;
if ( V_39 -> V_57 )
V_42 -> V_48 |= V_58 ;
V_39 -> V_59 = F_18 ( V_6 -> V_60 ,
V_6 -> V_61 ) ;
return 0 ;
}
static
int F_19 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_5 * V_6 = V_39 -> V_62 ;
struct V_41 * V_42 ;
T_2 V_63 ;
int V_7 ;
if ( V_6 -> V_60 != V_64 ) {
F_6 ( L_3 , V_6 -> V_60 ) ;
return - V_11 ;
}
V_7 = F_20 ( V_39 ) ;
V_42 = F_5 ( V_6 , V_46 , sizeof( * V_42 ) ) ;
if ( V_42 == NULL ) {
F_6 ( L_4 ) ;
return - V_11 ;
}
if ( V_42 -> V_47 != 0 ) {
F_6 ( L_5 ) ;
return - V_11 ;
}
if ( V_42 -> V_48 & V_56 ) {
F_6 ( L_6 ) ;
return - V_11 ;
}
if ( V_42 -> V_52 != V_39 -> V_44 . V_53 . V_54 . V_18 ) {
F_6 ( L_7 , V_42 -> V_52 ,
V_39 -> V_44 . V_53 . V_54 . V_18 ) ;
return - V_11 ;
}
if ( F_21 ( V_39 -> V_65 ) ) {
unsigned int V_66 = 4 ;
F_22 ( V_67 ,
F_5 ( V_6 , V_68 , 0 ) ,
F_7 ( V_6 , V_68 ) ,
NULL , 0 , ( unsigned char * ) & V_63 , & V_66 ) ;
if ( V_63 != V_6 -> V_69 ) {
F_23 ( V_70 ,
L_8 ,
F_24 ( V_63 ) , V_6 -> V_69 ) ;
return - V_71 ;
}
} else {
if ( ! V_39 -> V_65 &&
! F_25 ( V_39 -> V_57 == 1 ,
V_42 -> V_48 & V_58 ) ) {
F_6 ( L_9 ,
V_39 -> V_57 ? L_10 : L_11 ) ;
return - V_11 ;
}
if ( V_42 -> V_48 & V_58 ) {
if ( F_3 ( V_6 , V_7 ) )
return - V_11 ;
}
}
V_39 -> V_72 = F_5 ( V_6 , V_68 , 0 ) ;
V_39 -> V_73 = F_7 ( V_6 , V_68 ) ;
return 0 ;
}
static
int F_26 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
struct V_16 * V_17 )
{
struct V_8 * V_9 ;
struct V_19 * V_20 ;
int V_25 ;
F_27 ( V_39 -> V_57 ) ;
F_27 ( V_39 -> V_40 -> V_60 == V_64 ) ;
V_9 = F_5 ( V_39 -> V_40 , V_10 , 0 ) ;
V_20 = (struct V_19 * ) V_9 -> V_74 ;
V_9 -> V_75 = 0 ;
V_9 -> V_76 = 0 ;
V_9 -> V_77 = V_78 ;
V_9 -> V_13 = F_28 ( V_39 -> V_44 . V_45 ) ;
if ( V_9 -> V_13 == V_14 )
return 0 ;
if ( V_39 -> V_79 )
return 0 ;
V_25 = F_8 ( V_17 , V_39 -> V_44 . V_53 . V_54 . V_18 ,
V_20 ) ;
if ( V_25 ) {
F_6 ( L_12 , V_25 ) ;
} else {
if ( F_29 ( V_80 ) &&
V_39 -> V_44 . V_53 . V_54 . V_18 != V_21 )
V_20 -> V_22 [ 0 ] ^= 0x1 ;
}
return V_25 ;
}
static
int F_30 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
struct V_16 * V_17 )
{
struct V_8 * V_81 ;
struct V_19 * V_24 ;
int V_25 ;
int V_29 , V_82 ;
F_27 ( V_39 -> V_57 ) ;
F_27 ( V_39 -> V_40 -> V_60 == V_64 ) ;
F_27 ( V_39 -> V_62 -> V_60 == V_64 ) ;
V_81 = F_5 ( V_39 -> V_62 , V_10 , 0 ) ;
V_24 = (struct V_19 * ) V_81 -> V_74 ;
if ( V_39 -> V_83 ) {
if ( V_81 -> V_76 & V_84 )
return - V_85 ;
return 0 ;
}
for ( V_29 = 0 , V_82 = 0 ; V_29 < V_17 -> V_30 ; V_29 ++ ) {
if ( V_17 -> V_31 [ V_29 ] . V_32 + V_82 > V_17 -> V_86 ) {
V_17 -> V_31 [ V_29 ] . V_32 =
V_17 -> V_86 - V_82 ;
}
V_82 += V_17 -> V_31 [ V_29 ] . V_32 ;
}
V_25 = F_10 ( V_17 , V_39 -> V_44 . V_53 . V_54 . V_18 ,
V_24 ) ;
if ( V_25 )
F_6 ( L_13 , V_25 ) ;
return V_25 ;
}
static
struct V_36 * F_31 ( struct V_1 * V_87 )
{
struct V_36 * V_37 , * V_88 ;
F_32 ( V_88 ) ;
F_33 ( & V_87 -> V_89 ) ;
V_37 = V_87 -> V_90 ;
if ( V_37 ) {
F_34 ( & V_37 -> V_91 ) ;
if ( V_88 )
F_35 ( V_88 ) ;
} else if ( V_88 ) {
V_37 = V_88 ;
F_36 ( & V_37 -> V_91 , 1 ) ;
V_37 -> V_50 = & V_87 -> V_4 ;
V_37 -> V_92 = & V_93 ;
V_37 -> V_94 = 0 ;
V_37 -> V_95 = V_96 | V_97 ;
V_37 -> V_98 . V_99 = 0 ;
F_37 ( & V_37 -> V_100 ) ;
F_38 ( & V_37 -> V_101 ) ;
F_38 ( & V_37 -> V_102 ) ;
V_87 -> V_90 = V_37 ;
F_34 ( & V_87 -> V_4 . V_103 ) ;
F_34 ( & V_87 -> V_4 . V_104 ) ;
F_34 ( & V_37 -> V_91 ) ;
}
F_39 ( & V_87 -> V_89 ) ;
return V_37 ;
}
static
void F_40 ( struct V_2 * V_3 )
{
struct V_1 * V_87 = F_1 ( V_3 ) ;
F_27 ( V_3 -> V_105 == & V_106 ) ;
F_27 ( V_3 -> V_107 ) ;
F_27 ( F_41 ( & V_3 -> V_104 ) == 0 ) ;
F_27 ( F_41 ( & V_3 -> V_103 ) == 0 ) ;
F_27 ( V_87 -> V_90 == NULL ) ;
F_42 ( V_3 -> V_107 ) ;
F_35 ( V_87 ) ;
}
static
void F_43 ( struct V_2 * V_3 )
{
V_3 -> V_108 = 1 ;
}
static
struct V_2 * F_44 ( struct V_109 * V_110 ,
struct V_111 * V_112 ,
struct V_113 * V_114 )
{
struct V_1 * V_87 ;
struct V_2 * V_3 ;
struct V_36 * V_37 ;
F_27 ( F_45 ( V_114 -> V_45 ) == V_115 ) ;
F_32 ( V_87 ) ;
if ( V_87 == NULL )
return NULL ;
F_46 ( & V_87 -> V_89 ) ;
V_87 -> V_90 = NULL ;
V_3 = & V_87 -> V_4 ;
V_3 -> V_105 = & V_106 ;
F_36 ( & V_3 -> V_104 , 0 ) ;
F_36 ( & V_3 -> V_103 , 0 ) ;
V_3 -> V_116 = F_47 () ;
V_3 -> V_107 = F_48 ( V_110 ) ;
V_3 -> V_117 = * V_114 ;
F_37 ( & V_3 -> V_118 ) ;
F_38 ( & V_3 -> V_119 ) ;
V_3 -> V_120 = 0 ;
V_3 -> V_121 = 0 ;
if ( V_112 ) {
V_37 = F_31 ( V_87 ) ;
if ( V_37 == NULL ) {
F_40 ( V_3 ) ;
return NULL ;
}
F_49 ( V_37 , 1 ) ;
}
return V_3 ;
}
static
struct V_36 * F_50 ( struct V_2 * V_3 ,
struct V_122 * V_123 ,
int V_124 , int V_125 )
{
struct V_1 * V_87 = F_1 ( V_3 ) ;
struct V_36 * V_37 ;
F_51 ( & V_87 -> V_89 ) ;
V_37 = V_87 -> V_90 ;
if ( V_37 )
F_34 ( & V_37 -> V_91 ) ;
F_52 ( & V_87 -> V_89 ) ;
if ( F_21 ( V_37 == NULL ) )
V_37 = F_31 ( V_87 ) ;
return V_37 ;
}
static
void F_53 ( struct V_2 * V_3 ,
struct V_36 * V_37 , int V_126 )
{
F_27 ( F_41 ( & V_3 -> V_104 ) > 0 ) ;
F_27 ( F_41 ( & V_3 -> V_103 ) > 0 ) ;
F_27 ( F_41 ( & V_37 -> V_91 ) == 0 ) ;
F_27 ( V_37 -> V_50 == V_3 ) ;
F_35 ( V_37 ) ;
F_54 ( & V_3 -> V_103 ) ;
F_55 ( V_3 ) ;
}
static
int F_56 ( struct V_2 * V_3 ,
T_3 V_127 , int V_128 , int V_129 )
{
struct V_1 * V_87 = F_1 ( V_3 ) ;
struct V_36 * V_37 ;
if ( V_127 != - 1 )
return 0 ;
F_33 ( & V_87 -> V_89 ) ;
V_37 = V_87 -> V_90 ;
V_87 -> V_90 = NULL ;
F_39 ( & V_87 -> V_89 ) ;
if ( V_37 )
F_49 ( V_37 , 1 ) ;
return 0 ;
}
static
int F_57 ( struct V_2 * V_3 ,
struct V_38 * V_39 ,
int V_130 )
{
T_2 V_131 [ V_64 ] = { 0 , } ;
int V_132 ;
V_131 [ V_46 ] = sizeof( struct V_41 ) ;
V_131 [ V_68 ] = V_130 ;
if ( V_39 -> V_55 )
V_131 [ V_133 ] = F_58 () ;
if ( V_39 -> V_57 ) {
F_27 ( V_39 -> V_79 || V_39 -> V_83 ) ;
V_131 [ V_10 ] = V_12 ;
}
V_132 = F_18 ( V_64 , V_131 ) ;
if ( ! V_39 -> V_40 ) {
F_27 ( ! V_39 -> V_134 ) ;
V_132 = F_59 ( V_132 ) ;
F_60 ( V_39 -> V_40 , V_132 ) ;
if ( ! V_39 -> V_40 )
return - V_135 ;
V_39 -> V_136 = V_132 ;
} else {
F_27 ( V_39 -> V_134 ) ;
F_27 ( V_39 -> V_136 >= V_132 ) ;
memset ( V_39 -> V_40 , 0 , V_132 ) ;
}
F_61 ( V_39 -> V_40 , V_64 , V_131 , NULL ) ;
V_39 -> V_137 = F_5 ( V_39 -> V_40 , V_68 , 0 ) ;
if ( V_39 -> V_55 )
F_62 ( V_39 -> V_40 , V_133 ) ;
return 0 ;
}
static
void F_63 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
if ( ! V_39 -> V_134 ) {
F_64 ( V_39 -> V_40 , V_39 -> V_136 ) ;
V_39 -> V_40 = NULL ;
V_39 -> V_136 = 0 ;
}
}
static
int F_65 ( struct V_2 * V_3 ,
struct V_38 * V_39 ,
int V_130 )
{
T_2 V_131 [ V_64 ] = { 0 , } ;
int V_132 ;
V_131 [ V_46 ] = sizeof( struct V_41 ) ;
V_131 [ V_68 ] = V_130 ;
if ( V_39 -> V_57 ) {
F_27 ( V_39 -> V_79 || V_39 -> V_83 ) ;
V_131 [ V_10 ] = V_12 ;
}
V_132 = F_18 ( V_64 , V_131 ) ;
V_132 += V_138 ;
V_132 = F_59 ( V_132 ) ;
F_60 ( V_39 -> V_139 , V_132 ) ;
if ( ! V_39 -> V_139 )
return - V_135 ;
V_39 -> V_140 = V_132 ;
return 0 ;
}
static
void F_66 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
F_64 ( V_39 -> V_139 , V_39 -> V_140 ) ;
V_39 -> V_139 = NULL ;
V_39 -> V_140 = 0 ;
}
static
int F_67 ( struct V_2 * V_3 ,
struct V_38 * V_39 ,
int V_141 , int V_142 )
{
struct V_5 * V_143 ;
int V_144 ;
int V_145 , V_146 ;
F_27 ( V_39 -> V_40 ) ;
F_27 ( V_39 -> V_136 >= V_39 -> V_147 ) ;
F_27 ( F_5 ( V_39 -> V_40 , V_68 , 0 ) ==
V_39 -> V_137 ) ;
V_144 = V_39 -> V_137 -> V_61 [ V_141 ] ;
V_39 -> V_137 -> V_61 [ V_141 ] = V_142 ;
V_145 = F_18 ( V_39 -> V_137 -> V_60 ,
V_39 -> V_137 -> V_61 ) ;
V_39 -> V_137 -> V_61 [ V_141 ] = V_144 ;
V_144 = V_39 -> V_40 -> V_61 [ V_68 ] ;
V_39 -> V_40 -> V_61 [ V_68 ] = V_145 ;
V_146 = F_18 ( V_39 -> V_40 -> V_60 ,
V_39 -> V_40 -> V_61 ) ;
V_39 -> V_40 -> V_61 [ V_68 ] = V_144 ;
F_27 ( ! V_39 -> V_134 || V_39 -> V_136 >= V_146 ) ;
if ( V_39 -> V_136 < V_146 ) {
V_146 = F_59 ( V_146 ) ;
F_60 ( V_143 , V_146 ) ;
if ( V_143 == NULL )
return - V_135 ;
memcpy ( V_143 , V_39 -> V_40 , V_39 -> V_136 ) ;
F_64 ( V_39 -> V_40 , V_39 -> V_136 ) ;
V_39 -> V_40 = V_143 ;
V_39 -> V_136 = V_146 ;
V_39 -> V_137 = F_5 ( V_39 -> V_40 ,
V_68 , 0 ) ;
}
F_68 ( V_39 -> V_40 , V_68 ,
V_145 ) ;
F_68 ( V_39 -> V_137 , V_141 , V_142 ) ;
V_39 -> V_147 = V_145 ;
return 0 ;
}
static
int F_69 ( struct V_38 * V_39 )
{
struct V_5 * V_6 = V_39 -> V_40 ;
struct V_41 * V_42 ;
int V_7 ;
F_27 ( F_45 ( V_39 -> V_44 . V_45 ) ==
V_115 ) ;
if ( F_70 ( V_39 -> V_44 . V_45 ) !=
F_70 ( V_148 ) ||
F_71 ( V_39 -> V_44 . V_45 ) !=
F_71 ( V_148 ) ) {
F_6 ( L_14 , V_39 -> V_44 . V_45 ) ;
return V_149 ;
}
if ( V_6 -> V_60 < V_64 ) {
F_6 ( L_15 , V_6 -> V_60 ) ;
return V_149 ;
}
V_7 = F_72 ( V_39 ) ;
V_42 = F_5 ( V_6 , V_46 , sizeof( * V_42 ) ) ;
if ( V_42 == NULL ) {
F_6 ( L_4 ) ;
return - V_11 ;
}
if ( V_42 -> V_47 != 0 ) {
F_6 ( L_5 ) ;
return - V_11 ;
}
if ( V_42 -> V_52 >= V_150 ) {
F_6 ( L_16 , V_42 -> V_52 ) ;
return - V_11 ;
}
V_39 -> V_151 = V_42 -> V_49 ;
V_39 -> V_44 . V_53 . V_54 . V_18 = V_42 -> V_52 ;
if ( V_42 -> V_48 & V_56 ) {
if ( F_73 ( V_6 , V_133 ,
V_7 ) ) {
F_6 ( L_17 ) ;
return V_149 ;
}
V_39 -> V_55 = 1 ;
V_39 -> V_152 = F_5 ( V_6 , V_133 , 0 ) ;
}
if ( V_42 -> V_48 & V_58 ) {
if ( F_3 ( V_6 , V_7 ) )
return V_149 ;
V_39 -> V_57 = 1 ;
}
V_39 -> V_137 = F_5 ( V_6 , V_68 , 0 ) ;
V_39 -> V_147 = V_6 -> V_61 [ V_68 ] ;
V_39 -> V_153 = & V_154 ;
F_34 ( & V_39 -> V_153 -> V_155 ) ;
return V_156 ;
}
static
int F_74 ( struct V_38 * V_39 , int V_130 )
{
struct V_157 * V_158 ;
T_2 V_131 [ V_64 ] = { 0 , } ;
int V_159 = sizeof( * V_158 ) ;
F_27 ( V_130 % 8 == 0 ) ;
V_131 [ V_46 ] = sizeof( struct V_41 ) ;
V_131 [ V_68 ] = V_130 ;
if ( V_39 -> V_57 && ( V_39 -> V_79 || V_39 -> V_83 ) )
V_131 [ V_10 ] = V_12 ;
V_159 += F_18 ( V_64 , V_131 ) ;
V_158 = V_39 -> V_160 ;
if ( V_158 ) {
F_27 ( V_158 -> V_159 >= V_159 ) ;
} else {
F_60 ( V_158 , V_159 ) ;
if ( V_158 == NULL )
return - V_135 ;
V_158 -> V_159 = V_159 ;
}
V_158 -> V_161 = V_39 -> V_153 ;
F_34 ( & V_39 -> V_153 -> V_155 ) ;
V_158 -> V_162 = (struct V_5 * ) ( V_158 + 1 ) ;
V_158 -> V_163 = V_159 - sizeof( * V_158 ) ;
F_61 ( V_158 -> V_162 , V_64 , V_131 , NULL ) ;
V_158 -> V_164 = F_75 ( V_158 -> V_162 , V_68 , 0 ) ;
V_39 -> V_160 = V_158 ;
return 0 ;
}
static
void F_76 ( struct V_157 * V_158 )
{
F_27 ( F_41 ( & V_158 -> V_161 -> V_155 ) > 1 ) ;
F_54 ( & V_158 -> V_161 -> V_155 ) ;
if ( ! V_158 -> V_165 )
F_64 ( V_158 , V_158 -> V_159 ) ;
}
static
int F_77 ( struct V_38 * V_39 )
{
struct V_157 * V_158 = V_39 -> V_160 ;
struct V_166 * V_6 = V_158 -> V_162 ;
struct V_41 * V_42 ;
int V_167 ;
F_27 ( V_158 ) ;
F_27 ( V_6 ) ;
if ( V_39 -> V_73 != V_6 -> V_61 [ V_68 ] )
V_167 = F_78 ( V_6 , V_68 ,
V_39 -> V_73 , 1 ) ;
else
V_167 = F_18 ( V_6 -> V_60 , V_6 -> V_61 ) ;
V_6 -> V_43 = V_39 -> V_44 . V_45 ;
V_42 = F_5 ( V_6 , V_46 , 0 ) ;
V_42 -> V_47 = 0 ;
V_42 -> V_48 = 0 ;
V_42 -> V_52 = V_39 -> V_44 . V_53 . V_54 . V_18 ;
if ( V_39 -> V_57 )
V_42 -> V_48 |= V_58 ;
V_158 -> V_168 = V_167 ;
if ( F_79 ( V_39 -> V_169 ) ) {
if ( F_80 ( V_39 -> V_137 ) & V_170 )
V_39 -> V_171 = V_138 ;
else
V_39 -> V_171 = 0 ;
} else {
unsigned int V_66 = 4 ;
F_22 ( V_67 ,
F_5 ( V_6 , V_68 , 0 ) ,
F_7 ( V_6 , V_68 ) ,
NULL , 0 , ( unsigned char * ) & V_6 -> V_69 , & V_66 ) ;
V_39 -> V_171 = 0 ;
}
return 0 ;
}
static
int F_81 ( struct V_38 * V_39 ,
struct V_16 * V_17 )
{
struct V_157 * V_158 = V_39 -> V_160 ;
struct V_8 * V_172 , * V_81 ;
struct V_19 * V_23 ;
int V_25 ;
F_27 ( V_39 -> V_83 ) ;
F_27 ( V_39 -> V_57 ) ;
V_172 = F_5 ( V_39 -> V_40 , V_10 , 0 ) ;
V_23 = (struct V_19 * ) V_172 -> V_74 ;
V_81 = F_5 ( V_158 -> V_162 , V_10 , 0 ) ;
V_81 -> V_75 = 0 ;
V_81 -> V_77 = V_78 ;
V_81 -> V_13 = V_172 -> V_13 ;
V_81 -> V_76 = 0 ;
if ( V_172 -> V_13 == V_14 )
return 0 ;
V_25 = F_10 ( V_17 , V_39 -> V_44 . V_53 . V_54 . V_18 ,
V_23 ) ;
if ( V_25 ) {
V_81 -> V_76 |= V_84 ;
F_6 ( L_18 , V_25 ) ;
}
return V_25 ;
}
static
int F_82 ( struct V_38 * V_39 ,
struct V_16 * V_17 )
{
struct V_157 * V_158 = V_39 -> V_160 ;
struct V_8 * V_172 , * V_81 ;
struct V_19 * V_24 ;
int V_25 ;
F_27 ( V_39 -> V_79 ) ;
F_27 ( V_39 -> V_57 ) ;
V_172 = F_5 ( V_39 -> V_40 , V_10 , 0 ) ;
V_81 = F_5 ( V_158 -> V_162 , V_10 , 0 ) ;
V_24 = (struct V_19 * ) V_81 -> V_74 ;
V_81 -> V_75 = 0 ;
V_81 -> V_77 = V_78 ;
V_81 -> V_13 = V_172 -> V_13 ;
V_81 -> V_76 = 0 ;
if ( V_172 -> V_13 == V_14 )
return 0 ;
V_25 = F_8 ( V_17 , V_39 -> V_44 . V_53 . V_54 . V_18 ,
V_24 ) ;
if ( V_25 ) {
F_6 ( L_19
L_20 , V_25 ) ;
} else {
if ( F_29 ( V_173 ) )
F_11 ( V_17 ) ;
}
return V_25 ;
}
int F_83 ( void )
{
T_2 V_131 [ V_64 ] = { 0 , } ;
int V_25 ;
V_131 [ V_68 ] = F_84 () ;
V_138 = F_18 ( V_64 , V_131 ) ;
V_25 = F_85 ( & V_106 ) ;
if ( V_25 )
F_6 ( L_21 , V_25 ) ;
return V_25 ;
}
void F_86 ( void )
{
int V_25 ;
V_25 = F_87 ( & V_106 ) ;
if ( V_25 )
F_6 ( L_22 , V_25 ) ;
}
