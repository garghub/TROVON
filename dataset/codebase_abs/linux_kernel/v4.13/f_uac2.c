static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_5 ) ;
}
static inline
struct V_6 * F_3 ( struct V_4 * V_7 )
{
return F_2 ( V_7 -> V_5 . V_8 , struct V_6 , V_9 ) ;
}
static void F_4 ( const struct V_6 * V_10 ,
struct V_11 * V_12 ,
unsigned int V_13 , bool V_14 )
{
int V_15 , V_16 , V_17 ;
T_1 V_18 ;
if ( V_14 ) {
V_15 = V_10 -> V_19 ;
V_16 = V_10 -> V_20 ;
V_17 = V_10 -> V_21 ;
} else {
V_15 = V_10 -> V_22 ;
V_16 = V_10 -> V_23 ;
V_17 = V_10 -> V_24 ;
}
V_18 = F_5 ( V_15 ) * V_17 *
F_6 ( V_16 , V_13 / ( 1 << ( V_12 -> V_25 - 1 ) ) ) ;
V_12 -> V_26 = F_7 ( F_8 ( T_1 , V_18 ,
F_9 ( V_12 -> V_26 ) ) ) ;
}
static int
F_10 ( struct V_27 * V_28 , struct V_2 * V_29 )
{
struct V_1 * V_30 = F_1 ( V_29 ) ;
struct V_4 * V_7 = F_11 ( V_29 ) ;
struct V_31 * V_32 = V_28 -> V_32 ;
struct V_33 * V_34 = V_32 -> V_34 ;
struct V_35 * V_36 = & V_34 -> V_36 ;
struct V_6 * V_10 ;
struct V_37 * V_38 ;
int V_39 ;
V_10 = F_2 ( V_29 -> V_8 , struct V_6 , V_9 ) ;
V_38 = F_12 ( V_32 , V_40 , F_13 ( V_41 ) ) ;
if ( F_14 ( V_38 ) )
return F_15 ( V_38 ) ;
V_42 . V_43 = V_38 [ V_44 ] . V_45 ;
V_46 . V_47 = V_38 [ V_48 ] . V_45 ;
V_49 . V_50 = V_38 [ V_51 ] . V_45 ;
V_52 . V_50 = V_38 [ V_53 ] . V_45 ;
V_54 . V_55 = V_38 [ V_56 ] . V_45 ;
V_57 . V_55 = V_38 [ V_58 ] . V_45 ;
V_59 . V_55 = V_38 [ V_60 ] . V_45 ;
V_61 . V_55 = V_38 [ V_62 ] . V_45 ;
V_63 . V_47 = V_38 [ V_64 ] . V_45 ;
V_65 . V_47 = V_38 [ V_66 ] . V_45 ;
V_67 . V_47 = V_38 [ V_68 ] . V_45 ;
V_69 . V_47 = V_38 [ V_70 ] . V_45 ;
V_54 . V_71 = F_5 ( V_10 -> V_22 ) ;
V_54 . V_72 = F_16 ( V_10 -> V_22 ) ;
V_57 . V_71 = F_5 ( V_10 -> V_19 ) ;
V_57 . V_72 = F_16 ( V_10 -> V_19 ) ;
V_73 . V_71 = F_5 ( V_10 -> V_22 ) ;
V_73 . V_72 = F_16 ( V_10 -> V_22 ) ;
V_74 . V_71 = F_5 ( V_10 -> V_19 ) ;
V_74 . V_72 = F_16 ( V_10 -> V_19 ) ;
V_75 . V_76 = V_10 -> V_24 ;
V_75 . V_77 = V_10 -> V_24 * 8 ;
V_78 . V_76 = V_10 -> V_21 ;
V_78 . V_77 = V_10 -> V_21 * 8 ;
snprintf ( V_79 , sizeof( V_79 ) , L_1 , V_10 -> V_20 ) ;
snprintf ( V_80 , sizeof( V_80 ) , L_1 , V_10 -> V_23 ) ;
V_39 = F_17 ( V_28 , V_29 ) ;
if ( V_39 < 0 ) {
F_18 ( V_36 , L_2 , V_81 , __LINE__ ) ;
return V_39 ;
}
V_46 . V_82 = V_39 ;
V_30 -> V_83 = V_39 ;
V_30 -> V_84 = 0 ;
V_39 = F_17 ( V_28 , V_29 ) ;
if ( V_39 < 0 ) {
F_18 ( V_36 , L_2 , V_81 , __LINE__ ) ;
return V_39 ;
}
V_63 . V_82 = V_39 ;
V_65 . V_82 = V_39 ;
V_30 -> V_85 = V_39 ;
V_30 -> V_86 = 0 ;
V_39 = F_17 ( V_28 , V_29 ) ;
if ( V_39 < 0 ) {
F_18 ( V_36 , L_2 , V_81 , __LINE__ ) ;
return V_39 ;
}
V_67 . V_82 = V_39 ;
V_69 . V_82 = V_39 ;
V_30 -> V_87 = V_39 ;
V_30 -> V_88 = 0 ;
F_4 ( V_10 , & V_89 , 1000 , true ) ;
F_4 ( V_10 , & V_90 , 1000 , false ) ;
F_4 ( V_10 , & V_91 , 8000 , true ) ;
F_4 ( V_10 , & V_92 , 8000 , false ) ;
V_7 -> V_93 = F_19 ( V_34 , & V_90 ) ;
if ( ! V_7 -> V_93 ) {
F_18 ( V_36 , L_2 , V_81 , __LINE__ ) ;
return V_39 ;
}
V_7 -> V_94 = F_19 ( V_34 , & V_89 ) ;
if ( ! V_7 -> V_94 ) {
F_18 ( V_36 , L_2 , V_81 , __LINE__ ) ;
return V_39 ;
}
V_7 -> V_95 = F_20 ( T_1 ,
F_9 ( V_89 . V_26 ) ,
F_9 ( V_91 . V_26 ) ) ;
V_7 -> V_96 = F_20 ( T_1 ,
F_9 ( V_90 . V_26 ) ,
F_9 ( V_92 . V_26 ) ) ;
V_92 . V_97 = V_90 . V_97 ;
V_91 . V_97 = V_89 . V_97 ;
V_39 = F_21 ( V_29 , V_98 , V_99 , NULL ,
NULL ) ;
if ( V_39 )
return V_39 ;
V_7 -> V_34 = V_34 ;
V_7 -> V_100 . V_19 = V_10 -> V_19 ;
V_7 -> V_100 . V_20 = V_10 -> V_20 ;
V_7 -> V_100 . V_21 = V_10 -> V_21 ;
V_7 -> V_100 . V_22 = V_10 -> V_22 ;
V_7 -> V_100 . V_23 = V_10 -> V_23 ;
V_7 -> V_100 . V_24 = V_10 -> V_24 ;
V_7 -> V_100 . V_101 = V_10 -> V_101 ;
V_39 = F_22 ( V_7 , L_3 , L_4 ) ;
if ( V_39 )
goto V_102;
return 0 ;
V_102:
F_23 ( V_29 ) ;
V_7 -> V_34 = NULL ;
return V_39 ;
}
static int
F_24 ( struct V_2 * V_29 , unsigned V_103 , unsigned V_104 )
{
struct V_31 * V_32 = V_29 -> V_105 -> V_32 ;
struct V_1 * V_30 = F_1 ( V_29 ) ;
struct V_33 * V_34 = V_32 -> V_34 ;
struct V_35 * V_36 = & V_34 -> V_36 ;
int V_39 = 0 ;
if ( V_104 > 1 ) {
F_18 ( V_36 , L_2 , V_81 , __LINE__ ) ;
return - V_106 ;
}
if ( V_103 == V_30 -> V_83 ) {
if ( V_104 ) {
F_18 ( V_36 , L_2 , V_81 , __LINE__ ) ;
return - V_106 ;
}
return 0 ;
}
if ( V_103 == V_30 -> V_85 ) {
V_30 -> V_86 = V_104 ;
if ( V_104 )
V_39 = F_25 ( & V_30 -> V_4 ) ;
else
F_26 ( & V_30 -> V_4 ) ;
} else if ( V_103 == V_30 -> V_87 ) {
V_30 -> V_88 = V_104 ;
if ( V_104 )
V_39 = F_27 ( & V_30 -> V_4 ) ;
else
F_28 ( & V_30 -> V_4 ) ;
} else {
F_18 ( V_36 , L_2 , V_81 , __LINE__ ) ;
return - V_106 ;
}
return V_39 ;
}
static int
F_29 ( struct V_2 * V_29 , unsigned V_103 )
{
struct V_1 * V_30 = F_1 ( V_29 ) ;
struct V_4 * V_7 = F_11 ( V_29 ) ;
if ( V_103 == V_30 -> V_83 )
return V_30 -> V_84 ;
else if ( V_103 == V_30 -> V_85 )
return V_30 -> V_86 ;
else if ( V_103 == V_30 -> V_87 )
return V_30 -> V_88 ;
else
F_18 ( & V_7 -> V_34 -> V_36 ,
L_5 ,
V_81 , __LINE__ , V_103 ) ;
return - V_106 ;
}
static void
F_30 ( struct V_2 * V_29 )
{
struct V_1 * V_30 = F_1 ( V_29 ) ;
V_30 -> V_88 = 0 ;
V_30 -> V_86 = 0 ;
F_26 ( & V_30 -> V_4 ) ;
F_28 ( & V_30 -> V_4 ) ;
}
static int
F_31 ( struct V_2 * V_29 , const struct V_107 * V_108 )
{
struct V_109 * V_110 = V_29 -> V_105 -> V_32 -> V_110 ;
struct V_4 * V_7 = F_11 ( V_29 ) ;
struct V_6 * V_111 ;
T_1 V_112 = F_9 ( V_108 -> V_113 ) ;
T_1 V_114 = F_9 ( V_108 -> V_115 ) ;
T_1 V_116 = F_9 ( V_108 -> V_117 ) ;
T_2 V_118 = ( V_114 >> 8 ) & 0xff ;
T_2 V_119 = V_116 >> 8 ;
int V_120 = - V_121 ;
int V_20 , V_23 ;
V_111 = F_3 ( V_7 ) ;
V_20 = V_111 -> V_20 ;
V_23 = V_111 -> V_23 ;
if ( V_119 == V_122 ) {
struct V_123 V_124 ;
memset ( & V_124 , 0 , sizeof( struct V_123 ) ) ;
if ( V_118 == V_125 )
V_124 . V_126 = V_20 ;
else if ( V_118 == V_127 )
V_124 . V_126 = V_23 ;
V_120 = F_8 ( unsigned , V_112 , sizeof V_124 ) ;
memcpy ( V_110 -> V_128 , & V_124 , V_120 ) ;
} else if ( V_119 == V_129 ) {
* ( T_2 * ) V_110 -> V_128 = 1 ;
V_120 = F_8 ( unsigned , V_112 , 1 ) ;
} else {
F_18 ( & V_7 -> V_34 -> V_36 ,
L_6 ,
V_81 , __LINE__ , V_119 ) ;
}
return V_120 ;
}
static int
F_32 ( struct V_2 * V_29 , const struct V_107 * V_108 )
{
struct V_109 * V_110 = V_29 -> V_105 -> V_32 -> V_110 ;
struct V_4 * V_7 = F_11 ( V_29 ) ;
struct V_6 * V_111 ;
T_1 V_112 = F_9 ( V_108 -> V_113 ) ;
T_1 V_114 = F_9 ( V_108 -> V_115 ) ;
T_1 V_116 = F_9 ( V_108 -> V_117 ) ;
T_2 V_118 = ( V_114 >> 8 ) & 0xff ;
T_2 V_119 = V_116 >> 8 ;
struct V_130 V_131 ;
int V_120 = - V_121 ;
int V_20 , V_23 ;
V_111 = F_3 ( V_7 ) ;
V_20 = V_111 -> V_20 ;
V_23 = V_111 -> V_23 ;
if ( V_119 == V_122 ) {
if ( V_118 == V_125 )
V_131 . V_132 = V_20 ;
else if ( V_118 == V_127 )
V_131 . V_132 = V_23 ;
else
return - V_121 ;
V_131 . V_133 = V_131 . V_132 ;
V_131 . V_134 = 0 ;
V_131 . V_135 = 1 ;
V_120 = F_8 ( unsigned , V_112 , sizeof V_131 ) ;
memcpy ( V_110 -> V_128 , & V_131 , V_120 ) ;
} else {
F_18 ( & V_7 -> V_34 -> V_36 ,
L_6 ,
V_81 , __LINE__ , V_119 ) ;
}
return V_120 ;
}
static int
F_33 ( struct V_2 * V_29 , const struct V_107 * V_108 )
{
if ( V_108 -> V_136 == V_137 )
return F_31 ( V_29 , V_108 ) ;
else if ( V_108 -> V_136 == V_138 )
return F_32 ( V_29 , V_108 ) ;
else
return - V_121 ;
}
static int
F_34 ( struct V_2 * V_29 , const struct V_107 * V_108 )
{
T_1 V_112 = F_9 ( V_108 -> V_113 ) ;
T_1 V_116 = F_9 ( V_108 -> V_117 ) ;
T_2 V_119 = V_116 >> 8 ;
if ( V_119 == V_122 )
return V_112 ;
return - V_121 ;
}
static int
F_35 ( struct V_2 * V_29 , const struct V_107 * V_108 )
{
struct V_1 * V_30 = F_1 ( V_29 ) ;
struct V_4 * V_7 = F_11 ( V_29 ) ;
T_1 V_114 = F_9 ( V_108 -> V_115 ) ;
T_2 V_103 = V_114 & 0xff ;
if ( V_103 != V_30 -> V_83 ) {
F_18 ( & V_7 -> V_34 -> V_36 ,
L_2 , V_81 , __LINE__ ) ;
return - V_121 ;
}
if ( V_108 -> V_139 & V_140 )
return F_33 ( V_29 , V_108 ) ;
else if ( V_108 -> V_136 == V_137 )
return F_34 ( V_29 , V_108 ) ;
return - V_121 ;
}
static int
F_36 ( struct V_2 * V_29 , const struct V_107 * V_108 )
{
struct V_31 * V_32 = V_29 -> V_105 -> V_32 ;
struct V_4 * V_7 = F_11 ( V_29 ) ;
struct V_109 * V_110 = V_32 -> V_110 ;
T_1 V_112 = F_9 ( V_108 -> V_113 ) ;
int V_120 = - V_121 ;
if ( ( V_108 -> V_139 & V_141 ) != V_142 )
return - V_121 ;
if ( ( V_108 -> V_139 & V_143 ) == V_144 )
V_120 = F_35 ( V_29 , V_108 ) ;
else
F_18 ( & V_7 -> V_34 -> V_36 , L_2 ,
V_81 , __LINE__ ) ;
if ( V_120 >= 0 ) {
V_110 -> V_145 = V_120 ;
V_110 -> V_146 = V_120 < V_112 ;
V_120 = F_37 ( V_32 -> V_34 -> V_147 , V_110 , V_148 ) ;
if ( V_120 < 0 ) {
F_18 ( & V_7 -> V_34 -> V_36 ,
L_2 , V_81 , __LINE__ ) ;
V_110 -> V_149 = 0 ;
}
}
return V_120 ;
}
static inline struct V_6 * F_38 ( struct V_150 * V_151 )
{
return F_2 ( F_39 ( V_151 ) , struct V_6 ,
V_9 . V_152 ) ;
}
static void F_40 ( struct V_150 * V_151 )
{
struct V_6 * V_111 = F_38 ( V_151 ) ;
F_41 ( & V_111 -> V_9 ) ;
}
static void F_42 ( struct V_153 * V_3 )
{
struct V_6 * V_111 ;
V_111 = F_2 ( V_3 , struct V_6 , V_9 ) ;
F_43 ( V_111 ) ;
}
static struct V_153 * F_44 ( void )
{
struct V_6 * V_111 ;
V_111 = F_45 ( sizeof( * V_111 ) , V_154 ) ;
if ( ! V_111 )
return F_46 ( - V_155 ) ;
F_47 ( & V_111 -> V_156 ) ;
V_111 -> V_9 . V_157 = F_42 ;
F_48 ( & V_111 -> V_9 . V_152 , L_7 ,
& V_158 ) ;
V_111 -> V_19 = V_159 ;
V_111 -> V_20 = V_160 ;
V_111 -> V_21 = V_161 ;
V_111 -> V_22 = V_162 ;
V_111 -> V_23 = V_163 ;
V_111 -> V_24 = V_164 ;
V_111 -> V_101 = V_165 ;
return & V_111 -> V_9 ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_4 * V_7 ;
struct V_6 * V_111 ;
V_7 = F_11 ( V_3 ) ;
V_111 = F_2 ( V_3 -> V_8 , struct V_6 , V_9 ) ;
F_43 ( V_7 ) ;
F_50 ( & V_111 -> V_156 ) ;
-- V_111 -> V_166 ;
F_51 ( & V_111 -> V_156 ) ;
}
static void F_52 ( struct V_27 * V_124 , struct V_2 * V_3 )
{
struct V_4 * V_7 = F_11 ( V_3 ) ;
F_53 ( V_7 ) ;
F_23 ( V_3 ) ;
V_7 -> V_34 = NULL ;
}
static struct V_2 * F_54 ( struct V_153 * V_8 )
{
struct V_1 * V_30 ;
struct V_6 * V_111 ;
V_30 = F_45 ( sizeof( * V_30 ) , V_154 ) ;
if ( V_30 == NULL )
return F_46 ( - V_155 ) ;
V_111 = F_2 ( V_8 , struct V_6 , V_9 ) ;
F_50 ( & V_111 -> V_156 ) ;
++ V_111 -> V_166 ;
F_51 ( & V_111 -> V_156 ) ;
V_30 -> V_4 . V_5 . V_167 = L_8 ;
V_30 -> V_4 . V_5 . V_168 = F_10 ;
V_30 -> V_4 . V_5 . V_169 = F_52 ;
V_30 -> V_4 . V_5 . V_170 = F_24 ;
V_30 -> V_4 . V_5 . V_171 = F_29 ;
V_30 -> V_4 . V_5 . V_172 = F_30 ;
V_30 -> V_4 . V_5 . V_173 = F_36 ;
V_30 -> V_4 . V_5 . V_174 = F_49 ;
return & V_30 -> V_4 . V_5 ;
}
