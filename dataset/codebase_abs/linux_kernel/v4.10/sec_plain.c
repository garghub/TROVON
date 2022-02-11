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
if ( ! V_9 ) {
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
F_12 ( F_13 ( V_17 -> V_30 ) ) ;
for ( V_29 = 0 ; V_29 < V_17 -> V_31 ; V_29 ++ ) {
if ( ! F_14 ( V_17 , V_29 ) . V_32 )
continue;
V_27 = F_15 ( F_14 ( V_17 , V_29 ) . V_33 ) ;
V_28 = F_14 ( V_17 , V_29 ) . V_34 & ~ V_35 ;
V_27 [ V_28 ] ^= 0x1 ;
F_16 ( F_14 ( V_17 , V_29 ) . V_33 ) ;
return;
}
}
static
int F_17 ( struct V_36 * V_37 )
{
F_18 () ;
return 0 ;
}
static
int F_19 ( struct V_36 * V_37 )
{
return 0 ;
}
static
int F_20 ( struct V_36 * V_37 , struct V_38 * V_39 )
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
V_39 -> V_59 = F_21 ( V_6 -> V_60 ,
V_6 -> V_61 ) ;
return 0 ;
}
static
int F_22 ( struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_5 * V_6 = V_39 -> V_62 ;
struct V_41 * V_42 ;
T_2 V_63 ;
int V_7 ;
if ( V_6 -> V_60 != V_64 ) {
F_6 ( L_3 , V_6 -> V_60 ) ;
return - V_11 ;
}
V_7 = F_23 ( V_39 ) ;
V_42 = F_5 ( V_6 , V_46 , sizeof( * V_42 ) ) ;
if ( ! V_42 ) {
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
if ( F_24 ( V_39 -> V_65 ) ) {
unsigned int V_66 = 4 ;
F_25 ( V_67 ,
F_5 ( V_6 , V_68 ,
0 ) ,
F_7 ( V_6 ,
V_68 ) ,
NULL , 0 , ( unsigned char * ) & V_63 ,
& V_66 ) ;
if ( V_63 != V_6 -> V_69 ) {
F_26 ( V_70 ,
L_8 ,
F_27 ( V_63 ) , V_6 -> V_69 ) ;
return - V_71 ;
}
} else {
if ( ! V_39 -> V_65 &&
! F_28 ( V_39 -> V_57 == 1 ,
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
int F_29 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
struct V_16 * V_17 )
{
struct V_8 * V_9 ;
struct V_19 * V_20 ;
int V_25 ;
F_12 ( V_39 -> V_57 ) ;
F_12 ( V_39 -> V_40 -> V_60 == V_64 ) ;
V_9 = F_5 ( V_39 -> V_40 , V_10 , 0 ) ;
V_20 = (struct V_19 * ) V_9 -> V_74 ;
V_9 -> V_75 = 0 ;
V_9 -> V_76 = 0 ;
V_9 -> V_77 = V_78 ;
V_9 -> V_13 = F_30 ( V_39 -> V_44 . V_45 ) ;
if ( V_9 -> V_13 == V_14 )
return 0 ;
if ( V_39 -> V_79 )
return 0 ;
V_25 = F_8 ( V_17 , V_39 -> V_44 . V_53 . V_54 . V_18 ,
V_20 ) ;
if ( V_25 ) {
F_6 ( L_12 , V_25 ) ;
} else {
if ( F_31 ( V_80 ) &&
V_39 -> V_44 . V_53 . V_54 . V_18 != V_21 )
V_20 -> V_22 [ 0 ] ^= 0x1 ;
}
return V_25 ;
}
static
int F_32 ( struct V_36 * V_37 ,
struct V_38 * V_39 ,
struct V_16 * V_17 )
{
struct V_8 * V_81 ;
struct V_19 * V_24 ;
int V_25 ;
int V_29 , V_82 ;
F_12 ( V_39 -> V_57 ) ;
F_12 ( V_39 -> V_40 -> V_60 == V_64 ) ;
F_12 ( V_39 -> V_62 -> V_60 == V_64 ) ;
V_81 = F_5 ( V_39 -> V_62 , V_10 , 0 ) ;
V_24 = (struct V_19 * ) V_81 -> V_74 ;
if ( V_39 -> V_83 ) {
if ( V_81 -> V_76 & V_84 )
return - V_85 ;
return 0 ;
}
for ( V_29 = 0 , V_82 = 0 ; V_29 < V_17 -> V_31 ; V_29 ++ ) {
struct V_86 V_87 = F_14 ( V_17 , V_29 ) ;
if ( V_87 . V_32 + V_82 > V_17 -> V_88 )
V_87 . V_32 = V_17 -> V_88 - V_82 ;
V_82 += V_87 . V_32 ;
}
V_25 = F_10 ( V_17 , V_39 -> V_44 . V_53 . V_54 . V_18 ,
V_24 ) ;
if ( V_25 )
F_6 ( L_13 , V_25 ) ;
return V_25 ;
}
static
struct V_36 * F_33 ( struct V_1 * V_89 )
{
struct V_36 * V_37 , * V_90 ;
V_90 = F_34 ( sizeof( * V_90 ) , V_91 ) ;
F_35 ( & V_89 -> V_92 ) ;
V_37 = V_89 -> V_93 ;
if ( V_37 ) {
F_36 ( & V_37 -> V_94 ) ;
F_37 ( V_90 ) ;
} else if ( V_90 ) {
V_37 = V_90 ;
F_38 ( & V_37 -> V_94 , 1 ) ;
V_37 -> V_50 = & V_89 -> V_4 ;
V_37 -> V_95 = & V_96 ;
V_37 -> V_97 = 0 ;
V_37 -> V_98 = V_99 | V_100 ;
V_37 -> V_101 . V_102 = 0 ;
F_39 ( & V_37 -> V_103 ) ;
F_40 ( & V_37 -> V_104 ) ;
F_40 ( & V_37 -> V_105 ) ;
V_89 -> V_93 = V_37 ;
F_36 ( & V_89 -> V_4 . V_106 ) ;
F_36 ( & V_89 -> V_4 . V_107 ) ;
F_36 ( & V_37 -> V_94 ) ;
}
F_41 ( & V_89 -> V_92 ) ;
return V_37 ;
}
static
void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_89 = F_1 ( V_3 ) ;
F_12 ( V_3 -> V_108 == & V_109 ) ;
F_12 ( V_3 -> V_110 ) ;
F_12 ( F_43 ( & V_3 -> V_107 ) == 0 ) ;
F_12 ( F_43 ( & V_3 -> V_106 ) == 0 ) ;
F_12 ( ! V_89 -> V_93 ) ;
F_44 ( V_3 -> V_110 ) ;
F_37 ( V_89 ) ;
}
static
void F_45 ( struct V_2 * V_3 )
{
V_3 -> V_111 = 1 ;
}
static
struct V_2 * F_46 ( struct V_112 * V_113 ,
struct V_114 * V_115 ,
struct V_116 * V_117 )
{
struct V_1 * V_89 ;
struct V_2 * V_3 ;
struct V_36 * V_37 ;
F_12 ( F_47 ( V_117 -> V_45 ) == V_118 ) ;
V_89 = F_34 ( sizeof( * V_89 ) , V_91 ) ;
if ( ! V_89 )
return NULL ;
F_48 ( & V_89 -> V_92 ) ;
V_89 -> V_93 = NULL ;
V_3 = & V_89 -> V_4 ;
V_3 -> V_108 = & V_109 ;
F_38 ( & V_3 -> V_107 , 0 ) ;
F_38 ( & V_3 -> V_106 , 0 ) ;
V_3 -> V_119 = F_49 () ;
V_3 -> V_110 = F_50 ( V_113 ) ;
V_3 -> V_120 = * V_117 ;
F_39 ( & V_3 -> V_121 ) ;
F_40 ( & V_3 -> V_122 ) ;
V_3 -> V_123 = 0 ;
V_3 -> V_124 = 0 ;
if ( V_115 ) {
V_37 = F_33 ( V_89 ) ;
if ( ! V_37 ) {
F_42 ( V_3 ) ;
return NULL ;
}
F_51 ( V_37 , 1 ) ;
}
return V_3 ;
}
static
struct V_36 * F_52 ( struct V_2 * V_3 ,
struct V_125 * V_126 ,
int V_127 , int V_128 )
{
struct V_1 * V_89 = F_1 ( V_3 ) ;
struct V_36 * V_37 ;
F_53 ( & V_89 -> V_92 ) ;
V_37 = V_89 -> V_93 ;
if ( V_37 )
F_36 ( & V_37 -> V_94 ) ;
F_54 ( & V_89 -> V_92 ) ;
if ( F_24 ( ! V_37 ) )
V_37 = F_33 ( V_89 ) ;
return V_37 ;
}
static
void F_55 ( struct V_2 * V_3 ,
struct V_36 * V_37 , int V_129 )
{
F_12 ( F_43 ( & V_3 -> V_107 ) > 0 ) ;
F_12 ( F_43 ( & V_3 -> V_106 ) > 0 ) ;
F_12 ( F_43 ( & V_37 -> V_94 ) == 0 ) ;
F_12 ( V_37 -> V_50 == V_3 ) ;
F_37 ( V_37 ) ;
F_56 ( & V_3 -> V_106 ) ;
F_57 ( V_3 ) ;
}
static
int F_58 ( struct V_2 * V_3 ,
T_3 V_130 , int V_131 , int V_132 )
{
struct V_1 * V_89 = F_1 ( V_3 ) ;
struct V_36 * V_37 ;
if ( V_130 != - 1 )
return 0 ;
F_35 ( & V_89 -> V_92 ) ;
V_37 = V_89 -> V_93 ;
V_89 -> V_93 = NULL ;
F_41 ( & V_89 -> V_92 ) ;
if ( V_37 )
F_51 ( V_37 , 1 ) ;
return 0 ;
}
static
int F_59 ( struct V_2 * V_3 ,
struct V_38 * V_39 ,
int V_133 )
{
T_2 V_134 [ V_64 ] = { 0 , } ;
int V_135 ;
V_134 [ V_46 ] = sizeof( struct V_41 ) ;
V_134 [ V_68 ] = V_133 ;
if ( V_39 -> V_55 )
V_134 [ V_136 ] = F_60 () ;
if ( V_39 -> V_57 ) {
F_12 ( V_39 -> V_79 || V_39 -> V_83 ) ;
V_134 [ V_10 ] = V_12 ;
}
V_135 = F_21 ( V_64 , V_134 ) ;
if ( ! V_39 -> V_40 ) {
F_12 ( ! V_39 -> V_137 ) ;
V_135 = F_61 ( V_135 ) ;
V_39 -> V_40 = F_62 ( V_135 , V_91 ) ;
if ( ! V_39 -> V_40 )
return - V_138 ;
V_39 -> V_139 = V_135 ;
} else {
F_12 ( V_39 -> V_137 ) ;
F_12 ( V_39 -> V_139 >= V_135 ) ;
memset ( V_39 -> V_40 , 0 , V_135 ) ;
}
F_63 ( V_39 -> V_40 , V_64 , V_134 , NULL ) ;
V_39 -> V_140 = F_5 ( V_39 -> V_40 , V_68 , 0 ) ;
if ( V_39 -> V_55 ) {
int V_25 = F_64 ( V_39 -> V_40 ,
V_136 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static
void F_65 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
if ( ! V_39 -> V_137 ) {
F_66 ( V_39 -> V_40 ) ;
V_39 -> V_40 = NULL ;
V_39 -> V_139 = 0 ;
}
}
static
int F_67 ( struct V_2 * V_3 ,
struct V_38 * V_39 ,
int V_133 )
{
T_2 V_134 [ V_64 ] = { 0 , } ;
int V_135 ;
V_134 [ V_46 ] = sizeof( struct V_41 ) ;
V_134 [ V_68 ] = V_133 ;
if ( V_39 -> V_57 ) {
F_12 ( V_39 -> V_79 || V_39 -> V_83 ) ;
V_134 [ V_10 ] = V_12 ;
}
V_135 = F_21 ( V_64 , V_134 ) ;
V_135 += V_141 ;
V_135 = F_61 ( V_135 ) ;
V_39 -> V_142 = F_62 ( V_135 , V_91 ) ;
if ( ! V_39 -> V_142 )
return - V_138 ;
V_39 -> V_143 = V_135 ;
return 0 ;
}
static
void F_68 ( struct V_2 * V_3 ,
struct V_38 * V_39 )
{
F_66 ( V_39 -> V_142 ) ;
V_39 -> V_142 = NULL ;
V_39 -> V_143 = 0 ;
}
static
int F_69 ( struct V_2 * V_3 ,
struct V_38 * V_39 ,
int V_144 , int V_145 )
{
struct V_5 * V_146 ;
int V_147 ;
int V_148 , V_149 ;
F_12 ( V_39 -> V_40 ) ;
F_12 ( V_39 -> V_139 >= V_39 -> V_150 ) ;
F_12 ( F_5 ( V_39 -> V_40 , V_68 , 0 ) ==
V_39 -> V_140 ) ;
V_147 = V_39 -> V_140 -> V_61 [ V_144 ] ;
V_39 -> V_140 -> V_61 [ V_144 ] = V_145 ;
V_148 = F_21 ( V_39 -> V_140 -> V_60 ,
V_39 -> V_140 -> V_61 ) ;
V_39 -> V_140 -> V_61 [ V_144 ] = V_147 ;
V_147 = V_39 -> V_40 -> V_61 [ V_68 ] ;
V_39 -> V_40 -> V_61 [ V_68 ] = V_148 ;
V_149 = F_21 ( V_39 -> V_40 -> V_60 ,
V_39 -> V_40 -> V_61 ) ;
V_39 -> V_40 -> V_61 [ V_68 ] = V_147 ;
F_12 ( ! V_39 -> V_137 || V_39 -> V_139 >= V_149 ) ;
if ( V_39 -> V_139 < V_149 ) {
V_149 = F_61 ( V_149 ) ;
V_146 = F_62 ( V_149 , V_91 ) ;
if ( ! V_146 )
return - V_138 ;
if ( V_39 -> V_151 )
F_70 ( & V_39 -> V_151 -> V_152 ) ;
memcpy ( V_146 , V_39 -> V_40 , V_39 -> V_139 ) ;
F_66 ( V_39 -> V_40 ) ;
V_39 -> V_40 = V_146 ;
V_39 -> V_139 = V_149 ;
V_39 -> V_140 = F_5 ( V_39 -> V_40 ,
V_68 , 0 ) ;
if ( V_39 -> V_151 )
F_71 ( & V_39 -> V_151 -> V_152 ) ;
}
F_72 ( V_39 -> V_40 , V_68 ,
V_148 ) ;
F_72 ( V_39 -> V_140 , V_144 , V_145 ) ;
V_39 -> V_150 = V_148 ;
return 0 ;
}
static
int F_73 ( struct V_38 * V_39 )
{
struct V_5 * V_6 = V_39 -> V_40 ;
struct V_41 * V_42 ;
int V_7 ;
F_12 ( F_47 ( V_39 -> V_44 . V_45 ) ==
V_118 ) ;
if ( F_74 ( V_39 -> V_44 . V_45 ) !=
F_74 ( V_153 ) ||
F_75 ( V_39 -> V_44 . V_45 ) !=
F_75 ( V_153 ) ) {
F_6 ( L_14 , V_39 -> V_44 . V_45 ) ;
return V_154 ;
}
if ( V_6 -> V_60 < V_64 ) {
F_6 ( L_15 , V_6 -> V_60 ) ;
return V_154 ;
}
V_7 = F_76 ( V_39 ) ;
V_42 = F_5 ( V_6 , V_46 , sizeof( * V_42 ) ) ;
if ( ! V_42 ) {
F_6 ( L_4 ) ;
return - V_11 ;
}
if ( V_42 -> V_47 != 0 ) {
F_6 ( L_5 ) ;
return - V_11 ;
}
if ( V_42 -> V_52 >= V_155 ) {
F_6 ( L_16 , V_42 -> V_52 ) ;
return - V_11 ;
}
V_39 -> V_156 = V_42 -> V_49 ;
V_39 -> V_44 . V_53 . V_54 . V_18 = V_42 -> V_52 ;
if ( V_42 -> V_48 & V_56 ) {
if ( F_77 ( V_6 , V_136 ,
V_7 ) ) {
F_6 ( L_17 ) ;
return V_154 ;
}
V_39 -> V_55 = 1 ;
V_39 -> V_157 = F_5 ( V_6 , V_136 , 0 ) ;
}
if ( V_42 -> V_48 & V_58 ) {
if ( F_3 ( V_6 , V_7 ) )
return V_154 ;
V_39 -> V_57 = 1 ;
}
V_39 -> V_140 = F_5 ( V_6 , V_68 , 0 ) ;
V_39 -> V_150 = V_6 -> V_61 [ V_68 ] ;
V_39 -> V_158 = & V_159 ;
F_36 ( & V_39 -> V_158 -> V_160 ) ;
return V_161 ;
}
static
int F_78 ( struct V_38 * V_39 , int V_133 )
{
struct V_162 * V_163 ;
T_2 V_134 [ V_64 ] = { 0 , } ;
int V_164 = sizeof( * V_163 ) ;
F_12 ( V_133 % 8 == 0 ) ;
V_134 [ V_46 ] = sizeof( struct V_41 ) ;
V_134 [ V_68 ] = V_133 ;
if ( V_39 -> V_57 && ( V_39 -> V_79 || V_39 -> V_83 ) )
V_134 [ V_10 ] = V_12 ;
V_164 += F_21 ( V_64 , V_134 ) ;
V_163 = V_39 -> V_165 ;
if ( V_163 ) {
F_12 ( V_163 -> V_164 >= V_164 ) ;
} else {
V_163 = F_62 ( V_164 , V_91 ) ;
if ( ! V_163 )
return - V_138 ;
V_163 -> V_164 = V_164 ;
}
V_163 -> V_166 = V_39 -> V_158 ;
F_36 ( & V_39 -> V_158 -> V_160 ) ;
V_163 -> V_167 = (struct V_5 * ) ( V_163 + 1 ) ;
V_163 -> V_168 = V_164 - sizeof( * V_163 ) ;
F_63 ( V_163 -> V_167 , V_64 , V_134 , NULL ) ;
V_163 -> V_169 = F_79 ( V_163 -> V_167 , V_68 , 0 ) ;
V_39 -> V_165 = V_163 ;
return 0 ;
}
static
void F_80 ( struct V_162 * V_163 )
{
F_12 ( F_43 ( & V_163 -> V_166 -> V_160 ) > 1 ) ;
F_56 ( & V_163 -> V_166 -> V_160 ) ;
if ( ! V_163 -> V_170 )
F_66 ( V_163 ) ;
}
static
int F_81 ( struct V_38 * V_39 )
{
struct V_162 * V_163 = V_39 -> V_165 ;
struct V_171 * V_6 = V_163 -> V_167 ;
struct V_41 * V_42 ;
int V_172 ;
F_12 ( V_163 ) ;
F_12 ( V_6 ) ;
if ( V_39 -> V_73 != V_6 -> V_61 [ V_68 ] )
V_172 = F_82 ( V_6 , V_68 ,
V_39 -> V_73 , 1 ) ;
else
V_172 = F_21 ( V_6 -> V_60 , V_6 -> V_61 ) ;
V_6 -> V_43 = V_39 -> V_44 . V_45 ;
V_42 = F_5 ( V_6 , V_46 , 0 ) ;
V_42 -> V_47 = 0 ;
V_42 -> V_48 = 0 ;
V_42 -> V_52 = V_39 -> V_44 . V_53 . V_54 . V_18 ;
if ( V_39 -> V_57 )
V_42 -> V_48 |= V_58 ;
V_163 -> V_173 = V_172 ;
if ( F_83 ( V_39 -> V_174 ) ) {
if ( F_84 ( V_39 -> V_140 ) & V_175 )
V_39 -> V_176 = V_141 ;
else
V_39 -> V_176 = 0 ;
} else {
unsigned int V_66 = 4 ;
F_25 ( V_67 ,
F_5 ( V_6 , V_68 ,
0 ) ,
F_7 ( V_6 ,
V_68 ) ,
NULL , 0 , ( unsigned char * ) & V_6 -> V_69 ,
& V_66 ) ;
V_39 -> V_176 = 0 ;
}
return 0 ;
}
static
int F_85 ( struct V_38 * V_39 ,
struct V_16 * V_17 )
{
struct V_162 * V_163 = V_39 -> V_165 ;
struct V_8 * V_177 , * V_81 ;
struct V_19 * V_23 ;
int V_25 ;
F_12 ( V_39 -> V_83 ) ;
F_12 ( V_39 -> V_57 ) ;
V_177 = F_5 ( V_39 -> V_40 , V_10 , 0 ) ;
V_23 = (struct V_19 * ) V_177 -> V_74 ;
V_81 = F_5 ( V_163 -> V_167 , V_10 , 0 ) ;
V_81 -> V_75 = 0 ;
V_81 -> V_77 = V_78 ;
V_81 -> V_13 = V_177 -> V_13 ;
V_81 -> V_76 = 0 ;
if ( V_177 -> V_13 == V_14 )
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
int F_86 ( struct V_38 * V_39 ,
struct V_16 * V_17 )
{
struct V_162 * V_163 = V_39 -> V_165 ;
struct V_8 * V_177 , * V_81 ;
struct V_19 * V_24 ;
int V_25 ;
F_12 ( V_39 -> V_79 ) ;
F_12 ( V_39 -> V_57 ) ;
V_177 = F_5 ( V_39 -> V_40 , V_10 , 0 ) ;
V_81 = F_5 ( V_163 -> V_167 , V_10 , 0 ) ;
V_24 = (struct V_19 * ) V_81 -> V_74 ;
V_81 -> V_75 = 0 ;
V_81 -> V_77 = V_78 ;
V_81 -> V_13 = V_177 -> V_13 ;
V_81 -> V_76 = 0 ;
if ( V_177 -> V_13 == V_14 )
return 0 ;
V_25 = F_8 ( V_17 , V_39 -> V_44 . V_53 . V_54 . V_18 ,
V_24 ) ;
if ( V_25 ) {
F_6 ( L_19 ,
V_25 ) ;
} else {
if ( F_31 ( V_178 ) )
F_11 ( V_17 ) ;
}
return V_25 ;
}
int F_87 ( void )
{
T_2 V_134 [ V_64 ] = { 0 , } ;
int V_25 ;
V_134 [ V_68 ] = F_88 () ;
V_141 = F_21 ( V_64 , V_134 ) ;
V_25 = F_89 ( & V_109 ) ;
if ( V_25 )
F_6 ( L_20 , V_25 ) ;
return V_25 ;
}
void F_90 ( void )
{
int V_25 ;
V_25 = F_91 ( & V_109 ) ;
if ( V_25 )
F_6 ( L_21 , V_25 ) ;
}
