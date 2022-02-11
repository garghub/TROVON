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
V_88 = F_32 ( sizeof( * V_88 ) , V_89 ) ;
F_33 ( & V_87 -> V_90 ) ;
V_37 = V_87 -> V_91 ;
if ( V_37 ) {
F_34 ( & V_37 -> V_92 ) ;
F_35 ( V_88 ) ;
} else if ( V_88 ) {
V_37 = V_88 ;
F_36 ( & V_37 -> V_92 , 1 ) ;
V_37 -> V_50 = & V_87 -> V_4 ;
V_37 -> V_93 = & V_94 ;
V_37 -> V_95 = 0 ;
V_37 -> V_96 = V_97 | V_98 ;
V_37 -> V_99 . V_100 = 0 ;
F_37 ( & V_37 -> V_101 ) ;
F_38 ( & V_37 -> V_102 ) ;
F_38 ( & V_37 -> V_103 ) ;
V_87 -> V_91 = V_37 ;
F_34 ( & V_87 -> V_4 . V_104 ) ;
F_34 ( & V_87 -> V_4 . V_105 ) ;
F_34 ( & V_37 -> V_92 ) ;
}
F_39 ( & V_87 -> V_90 ) ;
return V_37 ;
}
static
void F_40 ( struct V_2 * V_3 )
{
struct V_1 * V_87 = F_1 ( V_3 ) ;
F_27 ( V_3 -> V_106 == & V_107 ) ;
F_27 ( V_3 -> V_108 ) ;
F_27 ( F_41 ( & V_3 -> V_105 ) == 0 ) ;
F_27 ( F_41 ( & V_3 -> V_104 ) == 0 ) ;
F_27 ( V_87 -> V_91 == NULL ) ;
F_42 ( V_3 -> V_108 ) ;
F_35 ( V_87 ) ;
}
static
void F_43 ( struct V_2 * V_3 )
{
V_3 -> V_109 = 1 ;
}
static
struct V_2 * F_44 ( struct V_110 * V_111 ,
struct V_112 * V_113 ,
struct V_114 * V_115 )
{
struct V_1 * V_87 ;
struct V_2 * V_3 ;
struct V_36 * V_37 ;
F_27 ( F_45 ( V_115 -> V_45 ) == V_116 ) ;
V_87 = F_32 ( sizeof( * V_87 ) , V_89 ) ;
if ( V_87 == NULL )
return NULL ;
F_46 ( & V_87 -> V_90 ) ;
V_87 -> V_91 = NULL ;
V_3 = & V_87 -> V_4 ;
V_3 -> V_106 = & V_107 ;
F_36 ( & V_3 -> V_105 , 0 ) ;
F_36 ( & V_3 -> V_104 , 0 ) ;
V_3 -> V_117 = F_47 () ;
V_3 -> V_108 = F_48 ( V_111 ) ;
V_3 -> V_118 = * V_115 ;
F_37 ( & V_3 -> V_119 ) ;
F_38 ( & V_3 -> V_120 ) ;
V_3 -> V_121 = 0 ;
V_3 -> V_122 = 0 ;
if ( V_113 ) {
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
struct V_123 * V_124 ,
int V_125 , int V_126 )
{
struct V_1 * V_87 = F_1 ( V_3 ) ;
struct V_36 * V_37 ;
F_51 ( & V_87 -> V_90 ) ;
V_37 = V_87 -> V_91 ;
if ( V_37 )
F_34 ( & V_37 -> V_92 ) ;
F_52 ( & V_87 -> V_90 ) ;
if ( F_21 ( V_37 == NULL ) )
V_37 = F_31 ( V_87 ) ;
return V_37 ;
}
static
void F_53 ( struct V_2 * V_3 ,
struct V_36 * V_37 , int V_127 )
{
F_27 ( F_41 ( & V_3 -> V_105 ) > 0 ) ;
F_27 ( F_41 ( & V_3 -> V_104 ) > 0 ) ;
F_27 ( F_41 ( & V_37 -> V_92 ) == 0 ) ;
F_27 ( V_37 -> V_50 == V_3 ) ;
F_35 ( V_37 ) ;
F_54 ( & V_3 -> V_104 ) ;
F_55 ( V_3 ) ;
}
static
int F_56 ( struct V_2 * V_3 ,
T_3 V_128 , int V_129 , int V_130 )
{
struct V_1 * V_87 = F_1 ( V_3 ) ;
struct V_36 * V_37 ;
if ( V_128 != - 1 )
return 0 ;
F_33 ( & V_87 -> V_90 ) ;
V_37 = V_87 -> V_91 ;
V_87 -> V_91 = NULL ;
F_39 ( & V_87 -> V_90 ) ;
if ( V_37 )
F_49 ( V_37 , 1 ) ;
return 0 ;
}
static
int F_57 ( struct V_2 * V_3 ,
struct V_38 * V_39 ,
int V_131 )
{
T_2 V_132 [ V_64 ] = { 0 , } ;
int V_133 ;
V_132 [ V_46 ] = sizeof( struct V_41 ) ;
V_132 [ V_68 ] = V_131 ;
if ( V_39 -> V_55 )
V_132 [ V_134 ] = F_58 () ;
if ( V_39 -> V_57 ) {
F_27 ( V_39 -> V_79 || V_39 -> V_83 ) ;
V_132 [ V_10 ] = V_12 ;
}
V_133 = F_18 ( V_64 , V_132 ) ;
if ( ! V_39 -> V_40 ) {
F_27 ( ! V_39 -> V_135 ) ;
V_133 = F_59 ( V_133 ) ;
V_39 -> V_40 = F_60 ( V_133 , V_89 ) ;
if ( ! V_39 -> V_40 )
return - V_136 ;
V_39 -> V_137 = V_133 ;
} else {
F_27 ( V_39 -> V_135 ) ;
F_27 ( V_39 -> V_137 >= V_133 ) ;
memset ( V_39 -> V_40 , 0 , V_133 ) ;
}
F_61 ( V_39 -> V_40 , V_64 , V_132 , NULL ) ;
V_39 -> V_138 = F_5 ( V_39 -> V_40 , V_68 , 0 ) ;
if ( V_39 -> V_55 )
F_62 ( V_39 -> V_40 , V_134 ) ;
return 0 ;
}
static
void F_63 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
if ( ! V_39 -> V_135 ) {
F_64 ( V_39 -> V_40 ) ;
V_39 -> V_40 = NULL ;
V_39 -> V_137 = 0 ;
}
}
static
int F_65 ( struct V_2 * V_3 ,
struct V_38 * V_39 ,
int V_131 )
{
T_2 V_132 [ V_64 ] = { 0 , } ;
int V_133 ;
V_132 [ V_46 ] = sizeof( struct V_41 ) ;
V_132 [ V_68 ] = V_131 ;
if ( V_39 -> V_57 ) {
F_27 ( V_39 -> V_79 || V_39 -> V_83 ) ;
V_132 [ V_10 ] = V_12 ;
}
V_133 = F_18 ( V_64 , V_132 ) ;
V_133 += V_139 ;
V_133 = F_59 ( V_133 ) ;
V_39 -> V_140 = F_60 ( V_133 , V_89 ) ;
if ( ! V_39 -> V_140 )
return - V_136 ;
V_39 -> V_141 = V_133 ;
return 0 ;
}
static
void F_66 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
F_64 ( V_39 -> V_140 ) ;
V_39 -> V_140 = NULL ;
V_39 -> V_141 = 0 ;
}
static
int F_67 ( struct V_2 * V_3 ,
struct V_38 * V_39 ,
int V_142 , int V_143 )
{
struct V_5 * V_144 ;
int V_145 ;
int V_146 , V_147 ;
F_27 ( V_39 -> V_40 ) ;
F_27 ( V_39 -> V_137 >= V_39 -> V_148 ) ;
F_27 ( F_5 ( V_39 -> V_40 , V_68 , 0 ) ==
V_39 -> V_138 ) ;
V_145 = V_39 -> V_138 -> V_61 [ V_142 ] ;
V_39 -> V_138 -> V_61 [ V_142 ] = V_143 ;
V_146 = F_18 ( V_39 -> V_138 -> V_60 ,
V_39 -> V_138 -> V_61 ) ;
V_39 -> V_138 -> V_61 [ V_142 ] = V_145 ;
V_145 = V_39 -> V_40 -> V_61 [ V_68 ] ;
V_39 -> V_40 -> V_61 [ V_68 ] = V_146 ;
V_147 = F_18 ( V_39 -> V_40 -> V_60 ,
V_39 -> V_40 -> V_61 ) ;
V_39 -> V_40 -> V_61 [ V_68 ] = V_145 ;
F_27 ( ! V_39 -> V_135 || V_39 -> V_137 >= V_147 ) ;
if ( V_39 -> V_137 < V_147 ) {
V_147 = F_59 ( V_147 ) ;
V_144 = F_60 ( V_147 , V_89 ) ;
if ( V_144 == NULL )
return - V_136 ;
if ( V_39 -> V_149 )
F_68 ( & V_39 -> V_149 -> V_150 ) ;
memcpy ( V_144 , V_39 -> V_40 , V_39 -> V_137 ) ;
F_64 ( V_39 -> V_40 ) ;
V_39 -> V_40 = V_144 ;
V_39 -> V_137 = V_147 ;
V_39 -> V_138 = F_5 ( V_39 -> V_40 ,
V_68 , 0 ) ;
if ( V_39 -> V_149 )
F_69 ( & V_39 -> V_149 -> V_150 ) ;
}
F_70 ( V_39 -> V_40 , V_68 ,
V_146 ) ;
F_70 ( V_39 -> V_138 , V_142 , V_143 ) ;
V_39 -> V_148 = V_146 ;
return 0 ;
}
static
int F_71 ( struct V_38 * V_39 )
{
struct V_5 * V_6 = V_39 -> V_40 ;
struct V_41 * V_42 ;
int V_7 ;
F_27 ( F_45 ( V_39 -> V_44 . V_45 ) ==
V_116 ) ;
if ( F_72 ( V_39 -> V_44 . V_45 ) !=
F_72 ( V_151 ) ||
F_73 ( V_39 -> V_44 . V_45 ) !=
F_73 ( V_151 ) ) {
F_6 ( L_14 , V_39 -> V_44 . V_45 ) ;
return V_152 ;
}
if ( V_6 -> V_60 < V_64 ) {
F_6 ( L_15 , V_6 -> V_60 ) ;
return V_152 ;
}
V_7 = F_74 ( V_39 ) ;
V_42 = F_5 ( V_6 , V_46 , sizeof( * V_42 ) ) ;
if ( V_42 == NULL ) {
F_6 ( L_4 ) ;
return - V_11 ;
}
if ( V_42 -> V_47 != 0 ) {
F_6 ( L_5 ) ;
return - V_11 ;
}
if ( V_42 -> V_52 >= V_153 ) {
F_6 ( L_16 , V_42 -> V_52 ) ;
return - V_11 ;
}
V_39 -> V_154 = V_42 -> V_49 ;
V_39 -> V_44 . V_53 . V_54 . V_18 = V_42 -> V_52 ;
if ( V_42 -> V_48 & V_56 ) {
if ( F_75 ( V_6 , V_134 ,
V_7 ) ) {
F_6 ( L_17 ) ;
return V_152 ;
}
V_39 -> V_55 = 1 ;
V_39 -> V_155 = F_5 ( V_6 , V_134 , 0 ) ;
}
if ( V_42 -> V_48 & V_58 ) {
if ( F_3 ( V_6 , V_7 ) )
return V_152 ;
V_39 -> V_57 = 1 ;
}
V_39 -> V_138 = F_5 ( V_6 , V_68 , 0 ) ;
V_39 -> V_148 = V_6 -> V_61 [ V_68 ] ;
V_39 -> V_156 = & V_157 ;
F_34 ( & V_39 -> V_156 -> V_158 ) ;
return V_159 ;
}
static
int F_76 ( struct V_38 * V_39 , int V_131 )
{
struct V_160 * V_161 ;
T_2 V_132 [ V_64 ] = { 0 , } ;
int V_162 = sizeof( * V_161 ) ;
F_27 ( V_131 % 8 == 0 ) ;
V_132 [ V_46 ] = sizeof( struct V_41 ) ;
V_132 [ V_68 ] = V_131 ;
if ( V_39 -> V_57 && ( V_39 -> V_79 || V_39 -> V_83 ) )
V_132 [ V_10 ] = V_12 ;
V_162 += F_18 ( V_64 , V_132 ) ;
V_161 = V_39 -> V_163 ;
if ( V_161 ) {
F_27 ( V_161 -> V_162 >= V_162 ) ;
} else {
V_161 = F_60 ( V_162 , V_89 ) ;
if ( V_161 == NULL )
return - V_136 ;
V_161 -> V_162 = V_162 ;
}
V_161 -> V_164 = V_39 -> V_156 ;
F_34 ( & V_39 -> V_156 -> V_158 ) ;
V_161 -> V_165 = (struct V_5 * ) ( V_161 + 1 ) ;
V_161 -> V_166 = V_162 - sizeof( * V_161 ) ;
F_61 ( V_161 -> V_165 , V_64 , V_132 , NULL ) ;
V_161 -> V_167 = F_77 ( V_161 -> V_165 , V_68 , 0 ) ;
V_39 -> V_163 = V_161 ;
return 0 ;
}
static
void F_78 ( struct V_160 * V_161 )
{
F_27 ( F_41 ( & V_161 -> V_164 -> V_158 ) > 1 ) ;
F_54 ( & V_161 -> V_164 -> V_158 ) ;
if ( ! V_161 -> V_168 )
F_64 ( V_161 ) ;
}
static
int F_79 ( struct V_38 * V_39 )
{
struct V_160 * V_161 = V_39 -> V_163 ;
struct V_169 * V_6 = V_161 -> V_165 ;
struct V_41 * V_42 ;
int V_170 ;
F_27 ( V_161 ) ;
F_27 ( V_6 ) ;
if ( V_39 -> V_73 != V_6 -> V_61 [ V_68 ] )
V_170 = F_80 ( V_6 , V_68 ,
V_39 -> V_73 , 1 ) ;
else
V_170 = F_18 ( V_6 -> V_60 , V_6 -> V_61 ) ;
V_6 -> V_43 = V_39 -> V_44 . V_45 ;
V_42 = F_5 ( V_6 , V_46 , 0 ) ;
V_42 -> V_47 = 0 ;
V_42 -> V_48 = 0 ;
V_42 -> V_52 = V_39 -> V_44 . V_53 . V_54 . V_18 ;
if ( V_39 -> V_57 )
V_42 -> V_48 |= V_58 ;
V_161 -> V_171 = V_170 ;
if ( F_81 ( V_39 -> V_172 ) ) {
if ( F_82 ( V_39 -> V_138 ) & V_173 )
V_39 -> V_174 = V_139 ;
else
V_39 -> V_174 = 0 ;
} else {
unsigned int V_66 = 4 ;
F_22 ( V_67 ,
F_5 ( V_6 , V_68 , 0 ) ,
F_7 ( V_6 , V_68 ) ,
NULL , 0 , ( unsigned char * ) & V_6 -> V_69 , & V_66 ) ;
V_39 -> V_174 = 0 ;
}
return 0 ;
}
static
int F_83 ( struct V_38 * V_39 ,
struct V_16 * V_17 )
{
struct V_160 * V_161 = V_39 -> V_163 ;
struct V_8 * V_175 , * V_81 ;
struct V_19 * V_23 ;
int V_25 ;
F_27 ( V_39 -> V_83 ) ;
F_27 ( V_39 -> V_57 ) ;
V_175 = F_5 ( V_39 -> V_40 , V_10 , 0 ) ;
V_23 = (struct V_19 * ) V_175 -> V_74 ;
V_81 = F_5 ( V_161 -> V_165 , V_10 , 0 ) ;
V_81 -> V_75 = 0 ;
V_81 -> V_77 = V_78 ;
V_81 -> V_13 = V_175 -> V_13 ;
V_81 -> V_76 = 0 ;
if ( V_175 -> V_13 == V_14 )
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
int F_84 ( struct V_38 * V_39 ,
struct V_16 * V_17 )
{
struct V_160 * V_161 = V_39 -> V_163 ;
struct V_8 * V_175 , * V_81 ;
struct V_19 * V_24 ;
int V_25 ;
F_27 ( V_39 -> V_79 ) ;
F_27 ( V_39 -> V_57 ) ;
V_175 = F_5 ( V_39 -> V_40 , V_10 , 0 ) ;
V_81 = F_5 ( V_161 -> V_165 , V_10 , 0 ) ;
V_24 = (struct V_19 * ) V_81 -> V_74 ;
V_81 -> V_75 = 0 ;
V_81 -> V_77 = V_78 ;
V_81 -> V_13 = V_175 -> V_13 ;
V_81 -> V_76 = 0 ;
if ( V_175 -> V_13 == V_14 )
return 0 ;
V_25 = F_8 ( V_17 , V_39 -> V_44 . V_53 . V_54 . V_18 ,
V_24 ) ;
if ( V_25 ) {
F_6 ( L_19 ,
V_25 ) ;
} else {
if ( F_29 ( V_176 ) )
F_11 ( V_17 ) ;
}
return V_25 ;
}
int F_85 ( void )
{
T_2 V_132 [ V_64 ] = { 0 , } ;
int V_25 ;
V_132 [ V_68 ] = F_86 () ;
V_139 = F_18 ( V_64 , V_132 ) ;
V_25 = F_87 ( & V_107 ) ;
if ( V_25 )
F_6 ( L_20 , V_25 ) ;
return V_25 ;
}
void F_88 ( void )
{
int V_25 ;
V_25 = F_89 ( & V_107 ) ;
if ( V_25 )
F_6 ( L_21 , V_25 ) ;
}
