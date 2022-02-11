static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 *
F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_4 , V_7 ) ;
}
static inline struct V_8 *
F_4 ( struct V_9 * V_6 )
{
return F_2 ( V_6 , struct V_8 , V_10 ) ;
}
static inline struct V_11 *
F_5 ( struct V_12 * V_13 )
{
return F_2 ( V_13 , struct V_11 , V_14 ) ;
}
static inline struct V_15 *
F_6 ( struct V_16 * V_17 )
{
return F_2 ( V_17 , struct V_15 , V_18 ) ;
}
int
F_7 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_23 * V_24 ,
struct V_5 * * V_6 )
{
struct V_4 * V_25 ;
unsigned long V_26 ;
int V_27 , V_28 ;
if ( ! V_22 -> V_29 || ! V_22 -> V_30 ||
! V_22 -> V_14 || ! V_22 -> V_31 ||
! V_22 -> V_32 || ! V_22 -> V_33 ||
! V_22 -> V_34 || ! V_22 -> V_35 ||
! V_22 -> V_36 || ! V_22 -> V_37 ) {
V_27 = - V_38 ;
goto V_39;
}
V_25 = F_8 ( ( sizeof( * V_25 ) + V_22 -> V_40 ) ,
V_41 ) ;
if ( ! V_25 ) {
V_27 = - V_42 ;
goto V_39;
}
V_28 = F_9 ( & V_43 , 0 , 0 , V_41 ) ;
if ( V_28 < 0 ) {
V_27 = - V_44 ;
goto V_45;
}
if ( ! F_10 ( V_24 ) && V_24 ) {
V_27 = - V_46 ;
goto V_47;
}
F_11 ( & V_25 -> V_48 ) ;
F_11 ( & V_25 -> V_49 ) ;
F_12 ( & V_25 -> V_50 ) ;
V_25 -> V_51 = V_22 ;
V_25 -> V_24 = V_24 ;
F_13 ( & V_25 -> V_52 ) ;
V_25 -> V_7 . V_53 = & V_25 [ 1 ] ;
V_25 -> V_7 . V_54 = V_20 -> V_54 ;
V_25 -> V_7 . V_55 = V_20 -> V_55 ;
V_25 -> V_7 . V_56 = V_20 -> V_56 ;
V_25 -> V_7 . V_57 = V_20 -> V_57 ;
V_25 -> V_7 . V_58 = V_59 ;
V_25 -> V_7 . V_60 = V_28 ;
F_14 ( & V_61 , V_26 ) ;
F_15 ( & V_25 -> V_48 , & V_62 ) ;
F_16 ( & V_61 , V_26 ) ;
if ( V_24 )
F_17 ( V_24 , V_22 -> V_37 ) ;
* V_6 = & V_25 -> V_7 ;
return 0 ;
V_47:
F_18 ( & V_43 , V_28 ) ;
V_45:
F_19 ( V_25 ) ;
V_39:
* V_6 = NULL ;
return V_27 ;
}
static void
F_20 ( struct V_63 * V_50 )
{
struct V_4 * V_64 =
F_2 ( V_50 , struct V_4 , V_50 ) ;
unsigned long V_26 ;
F_21 ( V_64 -> V_7 . V_58 != V_65 ) ;
F_21 ( ! F_22 ( & V_64 -> V_49 ) ) ;
F_14 ( & V_61 , V_26 ) ;
F_23 ( & V_64 -> V_48 ) ;
F_16 ( & V_61 , V_26 ) ;
V_64 -> V_51 -> V_29 ( & V_64 -> V_7 ) ;
F_18 ( & V_43 , V_64 -> V_7 . V_60 ) ;
F_24 ( & V_64 -> V_52 ) ;
F_25 ( V_64 -> V_24 ) ;
F_19 ( V_64 ) ;
}
static void
F_26 ( struct V_4 * V_64 )
{
F_27 ( & V_64 -> V_50 , F_20 ) ;
}
static int
F_28 ( struct V_4 * V_64 )
{
return F_29 ( & V_64 -> V_50 ) ;
}
int
F_30 ( struct V_5 * V_6 )
{
struct V_4 * V_64 = F_3 ( V_6 ) ;
unsigned long V_26 ;
if ( ! V_6 )
return - V_38 ;
F_14 ( & V_61 , V_26 ) ;
if ( V_6 -> V_58 != V_59 ) {
F_16 ( & V_61 , V_26 ) ;
return - V_38 ;
}
V_6 -> V_58 = V_65 ;
F_16 ( & V_61 , V_26 ) ;
F_26 ( V_64 ) ;
return 0 ;
}
int
F_31 ( struct V_5 * V_7 ,
struct V_19 * V_20 ,
struct V_9 * * V_6 )
{
struct V_4 * V_64 = F_3 ( V_7 ) ;
struct V_8 * V_25 ;
unsigned long V_26 ;
int V_27 , V_28 ;
V_25 = F_8 ( ( sizeof( * V_25 ) + V_64 -> V_51 -> V_66 ) ,
V_41 ) ;
if ( ! V_25 ) {
V_27 = - V_42 ;
goto V_39;
}
if ( ! F_28 ( V_64 ) ) {
V_27 = - V_67 ;
goto V_68;
}
V_28 = F_9 ( & V_64 -> V_52 , 0 , 0 , V_41 ) ;
if ( V_28 < 0 ) {
V_27 = - V_44 ;
goto V_69;
}
F_11 ( & V_25 -> V_49 ) ;
F_11 ( & V_25 -> V_70 ) ;
F_12 ( & V_25 -> V_50 ) ;
F_32 ( & V_25 -> V_71 ) ;
V_25 -> V_10 . V_7 = & V_64 -> V_7 ;
V_25 -> V_10 . V_53 = & V_25 [ 1 ] ;
V_25 -> V_10 . V_56 = V_20 -> V_56 ;
V_25 -> V_10 . V_54 = V_20 -> V_54 ;
V_25 -> V_10 . V_55 = V_20 -> V_55 ;
V_25 -> V_10 . V_57 = V_20 -> V_57 ;
V_25 -> V_10 . V_58 = V_59 ;
V_25 -> V_10 . V_60 = V_28 ;
F_14 ( & V_61 , V_26 ) ;
F_15 ( & V_25 -> V_49 , & V_64 -> V_49 ) ;
F_16 ( & V_61 , V_26 ) ;
* V_6 = & V_25 -> V_10 ;
return 0 ;
V_69:
F_26 ( V_64 ) ;
V_68:
F_19 ( V_25 ) ;
V_39:
* V_6 = NULL ;
return V_27 ;
}
static void
F_33 ( struct V_63 * V_50 )
{
struct V_8 * V_72 =
F_2 ( V_50 , struct V_8 , V_50 ) ;
struct V_4 * V_64 =
F_3 ( V_72 -> V_10 . V_7 ) ;
unsigned long V_26 ;
F_21 ( V_72 -> V_10 . V_58 != V_65 ) ;
F_21 ( ! F_22 ( & V_72 -> V_70 ) ) ;
F_14 ( & V_61 , V_26 ) ;
F_23 ( & V_72 -> V_49 ) ;
F_16 ( & V_61 , V_26 ) ;
V_64 -> V_51 -> V_30 ( & V_72 -> V_10 ) ;
F_18 ( & V_64 -> V_52 , V_72 -> V_10 . V_60 ) ;
F_19 ( V_72 ) ;
F_26 ( V_64 ) ;
}
static void
F_34 ( struct V_8 * V_72 )
{
F_27 ( & V_72 -> V_50 , F_33 ) ;
}
static int
F_35 ( struct V_8 * V_72 )
{
return F_29 ( & V_72 -> V_50 ) ;
}
int
F_36 ( struct V_9 * V_6 )
{
struct V_8 * V_72 = F_4 ( V_6 ) ;
struct V_1 * V_3 ;
unsigned long V_26 ;
if ( ! V_6 )
return - V_38 ;
F_14 ( & V_72 -> V_71 , V_26 ) ;
if ( V_6 -> V_58 != V_59 ) {
F_16 ( & V_72 -> V_71 , V_26 ) ;
return - V_38 ;
}
V_6 -> V_58 = V_65 ;
F_37 (ctrl, &rport->ctrl_list, ctrl_list)
F_38 ( V_3 ) ;
F_16 ( & V_72 -> V_71 , V_26 ) ;
F_34 ( V_72 ) ;
return 0 ;
}
static inline T_1
F_39 ( struct V_23 * V_24 , void * V_73 , T_2 V_74 ,
enum V_75 V_76 )
{
return V_24 ? F_40 ( V_24 , V_73 , V_74 , V_76 ) : ( T_1 ) 0L ;
}
static inline int
F_41 ( struct V_23 * V_24 , T_1 V_77 )
{
return V_24 ? F_42 ( V_24 , V_77 ) : 0 ;
}
static inline void
F_43 ( struct V_23 * V_24 , T_1 V_78 , T_2 V_74 ,
enum V_75 V_76 )
{
if ( V_24 )
F_44 ( V_24 , V_78 , V_74 , V_76 ) ;
}
static inline void
F_45 ( struct V_23 * V_24 , T_1 V_78 , T_2 V_74 ,
enum V_75 V_76 )
{
if ( V_24 )
F_46 ( V_24 , V_78 , V_74 , V_76 ) ;
}
static inline void
F_47 ( struct V_23 * V_24 , T_1 V_78 , T_2 V_74 ,
enum V_75 V_76 )
{
if ( V_24 )
F_48 ( V_24 , V_78 , V_74 , V_76 ) ;
}
static int
F_49 ( struct V_79 * V_80 , int V_81 )
{
struct V_79 * V_82 ;
int V_83 ;
F_21 ( V_81 == 0 || V_80 [ 0 ] . V_84 == 0 ) ;
F_50 (sg, s, nents, i) {
V_82 -> V_85 = 0L ;
#ifdef F_51
V_82 -> V_86 = V_82 -> V_84 ;
#endif
}
return V_81 ;
}
static inline int
F_52 ( struct V_23 * V_24 , struct V_79 * V_80 , int V_81 ,
enum V_75 V_76 )
{
return V_24 ? F_53 ( V_24 , V_80 , V_81 , V_76 ) : F_49 ( V_80 , V_81 ) ;
}
static inline void
F_54 ( struct V_23 * V_24 , struct V_79 * V_80 , int V_81 ,
enum V_75 V_76 )
{
if ( V_24 )
F_55 ( V_24 , V_80 , V_81 , V_76 ) ;
}
static void
F_56 ( struct V_1 * V_3 ,
struct V_11 * V_87 )
{
struct V_12 * V_13 = & V_87 -> V_14 ;
unsigned long V_26 ;
F_14 ( & V_3 -> V_71 , V_26 ) ;
if ( ! V_87 -> V_88 ) {
F_16 ( & V_3 -> V_71 , V_26 ) ;
return;
}
F_23 ( & V_87 -> V_89 ) ;
V_87 -> V_88 = false ;
F_16 ( & V_3 -> V_71 , V_26 ) ;
F_43 ( V_3 -> V_24 , V_13 -> V_90 ,
( V_13 -> V_91 + V_13 -> V_92 ) ,
V_93 ) ;
F_57 ( V_3 ) ;
}
static int
F_58 ( struct V_1 * V_3 ,
struct V_11 * V_87 ,
void (* F_59)( struct V_12 * V_94 , int V_95 ) )
{
struct V_12 * V_13 = & V_87 -> V_14 ;
unsigned long V_26 ;
int V_27 ;
if ( ! F_60 ( V_3 ) )
return - V_67 ;
V_13 -> F_59 = F_59 ;
V_87 -> V_3 = V_3 ;
V_87 -> V_88 = false ;
F_11 ( & V_87 -> V_89 ) ;
F_61 ( & V_87 -> V_96 ) ;
V_13 -> V_90 = F_39 ( V_3 -> V_24 , V_13 -> V_97 ,
V_13 -> V_91 + V_13 -> V_92 ,
V_93 ) ;
if ( F_41 ( V_3 -> V_24 , V_13 -> V_90 ) ) {
F_57 ( V_3 ) ;
F_62 ( V_3 -> V_24 ,
L_1 ) ;
return - V_98 ;
}
V_13 -> V_99 = V_13 -> V_90 + V_13 -> V_91 ;
F_14 ( & V_3 -> V_71 , V_26 ) ;
F_15 ( & V_87 -> V_89 , & V_3 -> V_100 ) ;
V_87 -> V_88 = true ;
F_16 ( & V_3 -> V_71 , V_26 ) ;
V_27 = V_3 -> V_64 -> V_51 -> V_14 ( & V_3 -> V_64 -> V_7 ,
& V_3 -> V_72 -> V_10 , V_13 ) ;
if ( V_27 )
V_87 -> V_101 = V_27 ;
return V_27 ;
}
static void
F_63 ( struct V_12 * V_13 , int V_95 )
{
struct V_11 * V_87 = F_5 ( V_13 ) ;
V_87 -> V_101 = V_95 ;
F_64 ( & V_87 -> V_96 ) ;
}
static int
F_65 ( struct V_1 * V_3 , struct V_11 * V_87 )
{
struct V_12 * V_13 = & V_87 -> V_14 ;
struct V_102 * V_103 = V_13 -> V_104 ;
int V_27 ;
V_27 = F_58 ( V_3 , V_87 , F_63 ) ;
if ( ! V_27 )
F_66 ( & V_87 -> V_96 ) ;
F_56 ( V_3 , V_87 ) ;
if ( V_27 ) {
F_62 ( V_3 -> V_24 ,
L_2 , V_27 ) ;
return V_27 ;
}
if ( V_103 -> V_105 . V_106 == V_107 )
return - V_108 ;
return 0 ;
}
static void
F_67 ( struct V_1 * V_3 ,
struct V_11 * V_87 ,
void (* F_59)( struct V_12 * V_94 , int V_95 ) )
{
int V_27 ;
V_27 = F_58 ( V_3 , V_87 , F_59 ) ;
if ( V_27 )
F_59 ( & V_87 -> V_14 , V_27 ) ;
}
static int
F_68 ( struct V_1 * V_3 ,
struct V_109 * V_110 , T_3 V_111 , T_3 V_112 )
{
struct V_11 * V_87 ;
struct V_12 * V_13 ;
struct V_113 * V_114 ;
struct V_115 * V_116 ;
int V_27 , V_117 = 0 ;
V_87 = F_69 ( ( sizeof( * V_87 ) +
V_3 -> V_64 -> V_51 -> V_118 +
sizeof( * V_114 ) + sizeof( * V_116 ) ) , V_41 ) ;
if ( ! V_87 ) {
V_27 = - V_42 ;
goto V_119;
}
V_13 = & V_87 -> V_14 ;
V_13 -> V_53 = ( void * ) & V_87 [ 1 ] ;
V_114 = (struct V_113 * )
( V_13 -> V_53 + V_3 -> V_64 -> V_51 -> V_118 ) ;
V_116 = (struct V_115 * ) & V_114 [ 1 ] ;
V_114 -> V_105 . V_106 = V_120 ;
V_114 -> V_121 =
F_70 ( sizeof( struct V_122 ) ) ;
V_114 -> V_123 . V_124 =
F_70 ( V_125 ) ;
V_114 -> V_123 . V_126 =
F_71 (
sizeof( struct V_122 ) ) ;
V_114 -> V_123 . V_112 = F_72 ( V_112 ) ;
V_114 -> V_123 . V_127 = F_72 ( V_111 ) ;
V_114 -> V_123 . V_128 = F_72 ( 0xffff ) ;
memcpy ( & V_114 -> V_123 . V_129 , & V_3 -> V_3 . V_130 -> V_131 -> V_132 ,
F_73 ( T_2 , V_133 , sizeof( V_134 ) ) ) ;
strncpy ( V_114 -> V_123 . V_135 , V_3 -> V_3 . V_130 -> V_131 -> V_136 ,
F_74 ( V_137 , V_138 ) ) ;
strncpy ( V_114 -> V_123 . V_139 , V_3 -> V_3 . V_130 -> V_140 ,
F_74 ( V_141 , V_138 ) ) ;
V_87 -> V_110 = V_110 ;
V_13 -> V_97 = V_114 ;
V_13 -> V_91 = sizeof( * V_114 ) ;
V_13 -> V_104 = V_116 ;
V_13 -> V_92 = sizeof( * V_116 ) ;
V_13 -> V_142 = V_143 ;
V_27 = F_65 ( V_3 , V_87 ) ;
if ( V_27 )
goto V_144;
if ( V_116 -> V_145 . V_105 . V_106 != V_146 )
V_117 = V_147 ;
if ( V_116 -> V_145 . V_121 !=
F_71 (
sizeof( struct V_115 ) ) )
V_117 = V_148 ;
if ( V_116 -> V_145 . V_149 . V_124 != F_70 ( V_150 ) )
V_117 = V_151 ;
else if ( V_116 -> V_145 . V_149 . V_126 !=
F_71 ( sizeof( struct V_152 ) ) )
V_117 = V_153 ;
else if ( V_116 -> V_145 . V_149 . V_105 . V_106 != V_120 )
V_117 = V_154 ;
else if ( V_116 -> V_155 . V_124 !=
F_70 ( V_156 ) )
V_117 = V_157 ;
else if ( V_116 -> V_155 . V_126 !=
F_71 (
sizeof( struct V_158 ) ) )
V_117 = V_159 ;
else if ( V_116 -> V_160 . V_124 !=
F_70 ( V_161 ) )
V_117 = V_162 ;
else if ( V_116 -> V_160 . V_126 !=
F_71 ( sizeof( struct V_163 ) ) )
V_117 = V_164 ;
if ( V_117 ) {
V_27 = - V_165 ;
F_62 ( V_3 -> V_24 ,
L_3 ,
V_110 -> V_166 , V_167 [ V_117 ] ) ;
} else {
V_3 -> V_168 =
F_75 ( V_116 -> V_155 . V_168 ) ;
V_110 -> V_169 =
F_75 ( V_116 -> V_160 . V_169 ) ;
F_76 ( V_170 , & V_110 -> V_26 ) ;
}
V_144:
F_19 ( V_87 ) ;
V_119:
if ( V_27 )
F_62 ( V_3 -> V_24 ,
L_4 ,
V_110 -> V_166 , V_27 ) ;
return V_27 ;
}
static int
F_77 ( struct V_1 * V_3 , struct V_109 * V_110 ,
T_3 V_111 , T_3 V_112 )
{
struct V_11 * V_87 ;
struct V_12 * V_13 ;
struct V_171 * V_172 ;
struct V_173 * V_174 ;
int V_27 , V_117 = 0 ;
V_87 = F_69 ( ( sizeof( * V_87 ) +
V_3 -> V_64 -> V_51 -> V_118 +
sizeof( * V_172 ) + sizeof( * V_174 ) ) , V_41 ) ;
if ( ! V_87 ) {
V_27 = - V_42 ;
goto V_119;
}
V_13 = & V_87 -> V_14 ;
V_13 -> V_53 = ( void * ) & V_87 [ 1 ] ;
V_172 = (struct V_171 * )
( V_13 -> V_53 + V_3 -> V_64 -> V_51 -> V_118 ) ;
V_174 = (struct V_173 * ) & V_172 [ 1 ] ;
V_172 -> V_105 . V_106 = V_175 ;
V_172 -> V_121 = F_70 (
sizeof( struct V_158 ) +
sizeof( struct V_176 ) ) ;
V_172 -> V_155 . V_124 = F_70 ( V_156 ) ;
V_172 -> V_155 . V_126 =
F_71 (
sizeof( struct V_158 ) ) ;
V_172 -> V_155 . V_168 = F_78 ( V_3 -> V_168 ) ;
V_172 -> V_177 . V_124 =
F_70 ( V_178 ) ;
V_172 -> V_177 . V_126 =
F_71 (
sizeof( struct V_176 ) ) ;
V_172 -> V_177 . V_112 = F_72 ( V_112 ) ;
V_172 -> V_177 . V_179 = F_72 ( V_110 -> V_166 ) ;
V_172 -> V_177 . V_127 = F_72 ( V_111 ) ;
V_87 -> V_110 = V_110 ;
V_13 -> V_97 = V_172 ;
V_13 -> V_91 = sizeof( * V_172 ) ;
V_13 -> V_104 = V_174 ;
V_13 -> V_92 = sizeof( * V_174 ) ;
V_13 -> V_142 = V_143 ;
V_27 = F_65 ( V_3 , V_87 ) ;
if ( V_27 )
goto V_144;
if ( V_174 -> V_145 . V_105 . V_106 != V_146 )
V_117 = V_147 ;
if ( V_174 -> V_145 . V_121 !=
F_71 ( sizeof( struct V_173 ) ) )
V_117 = V_180 ;
if ( V_174 -> V_145 . V_149 . V_124 != F_70 ( V_150 ) )
V_117 = V_151 ;
else if ( V_174 -> V_145 . V_149 . V_126 !=
F_71 ( sizeof( struct V_152 ) ) )
V_117 = V_153 ;
else if ( V_174 -> V_145 . V_149 . V_105 . V_106 != V_175 )
V_117 = V_181 ;
else if ( V_174 -> V_160 . V_124 !=
F_70 ( V_161 ) )
V_117 = V_162 ;
else if ( V_174 -> V_160 . V_126 !=
F_71 ( sizeof( struct V_163 ) ) )
V_117 = V_164 ;
if ( V_117 ) {
V_27 = - V_165 ;
F_62 ( V_3 -> V_24 ,
L_3 ,
V_110 -> V_166 , V_167 [ V_117 ] ) ;
} else {
V_110 -> V_169 =
F_75 ( V_174 -> V_160 . V_169 ) ;
F_76 ( V_170 , & V_110 -> V_26 ) ;
}
V_144:
F_19 ( V_87 ) ;
V_119:
if ( V_27 )
F_62 ( V_3 -> V_24 ,
L_5 ,
V_110 -> V_166 , V_27 ) ;
return V_27 ;
}
static void
F_79 ( struct V_12 * V_13 , int V_95 )
{
struct V_11 * V_87 = F_5 ( V_13 ) ;
struct V_1 * V_3 = V_87 -> V_3 ;
F_56 ( V_3 , V_87 ) ;
if ( V_95 )
F_62 ( V_3 -> V_24 ,
L_6 ,
V_95 ) ;
F_19 ( V_87 ) ;
}
static void
F_80 ( struct V_1 * V_3 )
{
struct V_182 * V_183 ;
struct V_184 * V_185 ;
struct V_11 * V_87 ;
struct V_12 * V_13 ;
V_87 = F_69 ( ( sizeof( * V_87 ) +
V_3 -> V_64 -> V_51 -> V_118 +
sizeof( * V_183 ) + sizeof( * V_185 ) ) ,
V_41 ) ;
if ( ! V_87 )
return;
V_13 = & V_87 -> V_14 ;
V_13 -> V_53 = ( void * ) & V_87 [ 1 ] ;
V_183 = (struct V_182 * )
( V_13 -> V_53 + V_3 -> V_64 -> V_51 -> V_118 ) ;
V_185 = (struct V_184 * ) & V_183 [ 1 ] ;
V_183 -> V_105 . V_106 = V_186 ;
V_183 -> V_121 = F_70 (
sizeof( struct V_158 ) +
sizeof( struct V_187 ) ) ;
V_183 -> V_155 . V_124 = F_70 ( V_156 ) ;
V_183 -> V_155 . V_126 =
F_71 (
sizeof( struct V_158 ) ) ;
V_183 -> V_155 . V_168 = F_78 ( V_3 -> V_168 ) ;
V_183 -> V_188 . V_124 = F_70 (
V_189 ) ;
V_183 -> V_188 . V_126 =
F_71 (
sizeof( struct V_187 ) ) ;
V_183 -> V_188 . V_190 = V_191 ;
V_183 -> V_188 . V_132 = F_78 ( V_3 -> V_168 ) ;
V_13 -> V_97 = V_183 ;
V_13 -> V_91 = sizeof( * V_183 ) ;
V_13 -> V_104 = V_185 ;
V_13 -> V_92 = sizeof( * V_185 ) ;
V_13 -> V_142 = V_143 ;
F_67 ( V_3 , V_87 , F_79 ) ;
V_3 -> V_168 = 0 ;
}
static int
F_81 ( void * V_192 , struct V_193 * V_194 )
{
struct V_15 * V_195 = F_82 ( V_194 ) ;
struct V_196 * V_197 = & V_195 -> V_198 ;
memset ( V_197 , 0 , sizeof( * V_197 ) ) ;
V_197 -> V_199 = V_200 ;
V_197 -> V_201 = V_202 ;
V_197 -> V_203 = F_72 ( sizeof( * V_197 ) / sizeof( V_204 ) ) ;
memset ( & V_195 -> V_205 , 0 , sizeof( V_195 -> V_205 ) ) ;
return 0 ;
}
static void
F_83 ( struct V_1 * V_3 ,
struct V_15 * V_195 )
{
F_43 ( V_3 -> V_64 -> V_24 , V_195 -> V_18 . V_99 ,
sizeof( V_195 -> V_205 ) , V_206 ) ;
F_43 ( V_3 -> V_64 -> V_24 , V_195 -> V_18 . V_207 ,
sizeof( V_195 -> V_198 ) , V_208 ) ;
F_84 ( & V_195 -> V_209 , V_210 ) ;
}
static void
F_85 ( void * V_192 , struct V_193 * V_194 ,
unsigned int V_211 , unsigned int V_212 )
{
struct V_15 * V_195 = F_82 ( V_194 ) ;
return F_83 ( V_192 , V_195 ) ;
}
static void
F_86 ( struct V_1 * V_3 )
{
struct V_15 * V_213 = V_3 -> V_214 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < V_215 ; V_83 ++ , V_213 ++ ) {
if ( F_87 ( & V_213 -> V_209 ) == V_210 )
continue;
F_83 ( V_3 , V_213 ) ;
F_57 ( V_3 ) ;
}
}
void
F_88 ( struct V_16 * V_94 )
{
struct V_15 * V_195 = F_6 ( V_94 ) ;
struct V_193 * V_194 = V_195 -> V_194 ;
struct V_16 * V_216 = & V_195 -> V_18 ;
struct V_1 * V_3 = V_195 -> V_3 ;
struct V_109 * V_110 = V_195 -> V_110 ;
struct V_217 * V_218 = & V_195 -> V_205 . V_218 ;
T_3 V_95 ;
F_45 ( V_3 -> V_64 -> V_24 , V_195 -> V_18 . V_99 ,
sizeof( V_195 -> V_205 ) , V_206 ) ;
if ( F_87 ( & V_195 -> V_209 ) == V_219 )
V_95 = V_220 | V_221 ;
else
V_95 = V_216 -> V_95 ;
if ( V_95 )
goto F_59;
switch ( V_216 -> V_222 ) {
case 0 :
case V_223 :
if ( V_216 -> V_224 !=
F_89 ( V_195 -> V_198 . V_225 ) ) {
V_95 = - V_226 ;
goto F_59;
}
V_195 -> V_227 . V_228 . V_229 = 0 ;
break;
case sizeof( struct V_230 ) :
if ( F_90 ( F_91 ( V_195 -> V_205 . V_203 ) !=
( V_216 -> V_222 / 4 ) ||
F_89 ( V_195 -> V_205 . V_231 ) !=
V_216 -> V_224 ||
V_195 -> V_232 != F_92 ( V_218 -> V_233 ) ) ) {
V_95 = - V_226 ;
goto F_59;
}
V_195 -> V_227 . V_228 = V_218 -> V_228 ;
V_95 = F_92 ( V_218 -> V_95 ) >> 1 ;
break;
default:
V_95 = - V_226 ;
goto F_59;
}
F_59:
if ( ! V_110 -> V_166 && V_195 -> V_232 >= V_234 ) {
F_93 ( & V_110 -> V_3 -> V_3 , V_95 ,
& V_195 -> V_227 . V_228 ) ;
F_57 ( V_3 ) ;
return;
}
F_94 ( V_194 , V_95 ) ;
}
static int
F_95 ( struct V_1 * V_3 ,
struct V_109 * V_110 , struct V_15 * V_195 ,
struct V_193 * V_194 , V_204 V_232 )
{
struct V_196 * V_197 = & V_195 -> V_198 ;
int V_27 = 0 ;
memset ( V_195 , 0 , sizeof( * V_195 ) ) ;
V_195 -> V_18 . V_235 = & V_195 -> V_198 ;
V_195 -> V_18 . V_236 = sizeof( V_195 -> V_198 ) ;
V_195 -> V_18 . V_104 = & V_195 -> V_205 ;
V_195 -> V_18 . V_92 = sizeof( V_195 -> V_205 ) ;
V_195 -> V_18 . F_59 = F_88 ;
V_195 -> V_18 . V_237 = (struct V_79 * ) & V_195 [ 1 ] ;
V_195 -> V_18 . V_53 = & V_195 -> V_18 . V_237 [ V_238 ] ;
V_195 -> V_3 = V_3 ;
V_195 -> V_110 = V_110 ;
V_195 -> V_194 = V_194 ;
V_195 -> V_232 = V_232 ;
V_197 -> V_199 = V_200 ;
V_197 -> V_201 = V_202 ;
V_197 -> V_203 = F_72 ( sizeof( * V_197 ) / sizeof( V_204 ) ) ;
V_195 -> V_18 . V_207 = F_39 ( V_3 -> V_64 -> V_24 ,
& V_195 -> V_198 , sizeof( V_195 -> V_198 ) , V_208 ) ;
if ( F_41 ( V_3 -> V_64 -> V_24 , V_195 -> V_18 . V_207 ) ) {
F_62 ( V_3 -> V_24 ,
L_7 ) ;
V_27 = V_98 ;
goto V_239;
}
V_195 -> V_18 . V_99 = F_39 ( V_3 -> V_64 -> V_24 ,
& V_195 -> V_205 , sizeof( V_195 -> V_205 ) ,
V_206 ) ;
if ( F_41 ( V_3 -> V_64 -> V_24 , V_195 -> V_18 . V_99 ) ) {
F_62 ( V_3 -> V_24 ,
L_8 ) ;
V_27 = V_98 ;
}
F_84 ( & V_195 -> V_209 , V_240 ) ;
V_239:
return V_27 ;
}
static int
F_96 ( void * V_192 , struct V_193 * V_194 ,
unsigned int V_211 , unsigned int V_212 ,
unsigned int V_241 )
{
struct V_1 * V_3 = V_192 ;
struct V_15 * V_195 = F_82 ( V_194 ) ;
struct V_109 * V_110 = & V_3 -> V_242 [ V_211 + 1 ] ;
return F_95 ( V_3 , V_110 , V_195 , V_194 , V_110 -> V_243 ++ ) ;
}
static int
F_97 ( void * V_192 , struct V_193 * V_194 ,
unsigned int V_211 , unsigned int V_212 ,
unsigned int V_241 )
{
struct V_1 * V_3 = V_192 ;
struct V_15 * V_195 = F_82 ( V_194 ) ;
struct V_109 * V_110 = & V_3 -> V_242 [ 0 ] ;
return F_95 ( V_3 , V_110 , V_195 , V_194 , V_110 -> V_243 ++ ) ;
}
static int
F_98 ( struct V_1 * V_3 )
{
struct V_15 * V_213 ;
struct V_196 * V_197 ;
struct V_244 * V_245 ;
int V_83 , V_27 ;
V_213 = V_3 -> V_214 ;
for ( V_83 = 0 ; V_83 < V_215 ; V_83 ++ , V_213 ++ ) {
V_197 = & V_213 -> V_198 ;
V_245 = & V_197 -> V_245 ;
V_27 = F_95 ( V_3 , & V_3 -> V_242 [ 0 ] ,
V_213 , (struct V_193 * ) NULL ,
( V_234 + V_83 ) ) ;
if ( V_27 )
return V_27 ;
memset ( V_245 , 0 , sizeof( * V_245 ) ) ;
V_245 -> V_246 . V_247 = V_248 ;
V_245 -> V_246 . V_233 = V_234 + V_83 ;
}
return 0 ;
}
static inline void
F_99 ( struct V_249 * V_250 , struct V_1 * V_3 ,
unsigned int V_251 )
{
struct V_109 * V_110 = & V_3 -> V_242 [ V_251 ] ;
V_250 -> V_252 = V_110 ;
V_110 -> V_250 = V_250 ;
}
static int
F_100 ( struct V_249 * V_250 , void * V_192 ,
unsigned int V_211 )
{
struct V_1 * V_3 = V_192 ;
F_99 ( V_250 , V_3 , V_211 + 1 ) ;
return 0 ;
}
static int
F_101 ( struct V_249 * V_250 , void * V_192 ,
unsigned int V_211 )
{
struct V_1 * V_3 = V_192 ;
F_99 ( V_250 , V_3 , V_211 ) ;
return 0 ;
}
static void
F_102 ( struct V_1 * V_3 , int V_28 , T_2 V_253 )
{
struct V_109 * V_110 ;
V_110 = & V_3 -> V_242 [ V_28 ] ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_3 = V_3 ;
V_110 -> V_166 = V_28 ;
F_84 ( & V_110 -> V_254 , 1 ) ;
V_110 -> V_24 = V_3 -> V_24 ;
if ( V_28 > 0 )
V_110 -> V_255 = V_3 -> V_3 . V_256 * 16 ;
else
V_110 -> V_255 = sizeof( struct V_244 ) ;
V_110 -> V_253 = V_253 ;
}
static void
F_103 ( struct V_109 * V_110 )
{
if ( ! F_104 ( V_170 , & V_110 -> V_26 ) )
return;
V_110 -> V_169 = 0 ;
F_105 ( V_170 , & V_110 -> V_26 ) ;
}
static void
F_106 ( struct V_1 * V_3 ,
struct V_109 * V_110 , unsigned int V_251 )
{
if ( V_3 -> V_64 -> V_51 -> V_257 )
V_3 -> V_64 -> V_51 -> V_257 ( & V_3 -> V_64 -> V_7 , V_251 ,
V_110 -> V_258 ) ;
V_110 -> V_258 = NULL ;
}
static void
F_107 ( struct V_1 * V_3 )
{
F_106 ( V_3 , & V_3 -> V_242 [ 0 ] , 0 ) ;
F_108 ( V_3 -> V_3 . V_259 ) ;
F_109 ( & V_3 -> V_260 ) ;
F_103 ( & V_3 -> V_242 [ 0 ] ) ;
}
static void
F_110 ( struct V_1 * V_3 )
{
int V_83 ;
for ( V_83 = 1 ; V_83 < V_3 -> V_261 ; V_83 ++ )
F_103 ( & V_3 -> V_242 [ V_83 ] ) ;
}
static int
F_111 ( struct V_1 * V_3 ,
struct V_109 * V_110 , unsigned int V_251 , T_3 V_111 )
{
int V_27 = 0 ;
V_110 -> V_258 = NULL ;
if ( V_3 -> V_64 -> V_51 -> V_262 )
V_27 = V_3 -> V_64 -> V_51 -> V_262 ( & V_3 -> V_64 -> V_7 ,
V_251 , V_111 , & V_110 -> V_258 ) ;
return V_27 ;
}
static void
F_112 ( struct V_1 * V_3 )
{
struct V_109 * V_110 = & V_3 -> V_242 [ V_3 -> V_261 - 1 ] ;
int V_83 ;
for ( V_83 = V_3 -> V_261 - 1 ; V_83 >= 1 ; V_83 -- , V_110 -- )
F_106 ( V_3 , V_110 , V_83 ) ;
}
static int
F_113 ( struct V_1 * V_3 , T_3 V_111 )
{
struct V_109 * V_110 = & V_3 -> V_242 [ 1 ] ;
int V_83 , V_27 ;
for ( V_83 = 1 ; V_83 < V_3 -> V_261 ; V_83 ++ , V_110 ++ ) {
V_27 = F_111 ( V_3 , V_110 , V_83 , V_111 ) ;
if ( V_27 )
goto V_263;
}
return 0 ;
V_263:
for (; V_83 >= 0 ; V_83 -- )
F_106 ( V_3 , & V_3 -> V_242 [ V_83 ] , V_83 ) ;
return V_27 ;
}
static int
F_114 ( struct V_1 * V_3 , T_3 V_111 )
{
int V_83 , V_27 = 0 ;
for ( V_83 = 1 ; V_83 < V_3 -> V_261 ; V_83 ++ ) {
V_27 = F_77 ( V_3 , & V_3 -> V_242 [ V_83 ] , V_111 ,
( V_111 / 5 ) ) ;
if ( V_27 )
break;
V_27 = F_115 ( & V_3 -> V_3 , V_83 ) ;
if ( V_27 )
break;
}
return V_27 ;
}
static void
F_116 ( struct V_1 * V_3 )
{
int V_83 ;
for ( V_83 = 1 ; V_83 < V_3 -> V_261 ; V_83 ++ )
F_102 ( V_3 , V_83 , V_3 -> V_3 . V_127 ) ;
}
static void
F_117 ( struct V_63 * V_50 )
{
struct V_1 * V_3 =
F_2 ( V_50 , struct V_1 , V_50 ) ;
unsigned long V_26 ;
if ( V_3 -> V_209 != V_264 ) {
F_14 ( & V_3 -> V_72 -> V_71 , V_26 ) ;
F_23 ( & V_3 -> V_70 ) ;
F_16 ( & V_3 -> V_72 -> V_71 , V_26 ) ;
}
F_25 ( V_3 -> V_24 ) ;
F_34 ( V_3 -> V_72 ) ;
F_19 ( V_3 -> V_242 ) ;
F_18 ( & V_265 , V_3 -> V_266 ) ;
F_118 ( V_3 -> V_3 . V_130 ) ;
F_19 ( V_3 ) ;
}
static void
F_57 ( struct V_1 * V_3 )
{
F_27 ( & V_3 -> V_50 , F_117 ) ;
}
static int
F_60 ( struct V_1 * V_3 )
{
return F_29 ( & V_3 -> V_50 ) ;
}
static void
F_119 ( struct V_2 * V_267 )
{
struct V_1 * V_3 = F_1 ( V_267 ) ;
F_21 ( V_267 != & V_3 -> V_3 ) ;
if ( V_3 -> V_209 != V_264 ) {
F_80 ( V_3 ) ;
if ( V_3 -> V_3 . V_268 ) {
F_108 ( V_3 -> V_3 . V_269 ) ;
F_109 ( & V_3 -> V_270 ) ;
F_112 ( V_3 ) ;
F_110 ( V_3 ) ;
}
F_86 ( V_3 ) ;
F_107 ( V_3 ) ;
}
F_57 ( V_3 ) ;
}
static int
F_120 ( struct V_1 * V_3 , struct V_15 * V_195 )
{
int V_209 ;
V_209 = F_121 ( & V_195 -> V_209 , V_219 ) ;
if ( V_209 != V_271 ) {
F_84 ( & V_195 -> V_209 , V_209 ) ;
return - V_272 ;
}
V_3 -> V_64 -> V_51 -> V_33 ( & V_3 -> V_64 -> V_7 ,
& V_3 -> V_72 -> V_10 ,
V_195 -> V_110 -> V_258 ,
& V_195 -> V_18 ) ;
return 0 ;
}
enum V_273
F_122 ( struct V_193 * V_194 , bool V_274 )
{
struct V_15 * V_195 = F_82 ( V_194 ) ;
struct V_1 * V_3 = V_195 -> V_3 ;
int V_27 ;
if ( V_274 )
return V_275 ;
V_27 = F_120 ( V_3 , V_195 ) ;
if ( V_27 )
return V_276 ;
return V_276 ;
}
static int
F_123 ( struct V_1 * V_3 , struct V_193 * V_194 ,
struct V_15 * V_195 )
{
struct V_16 * V_216 = & V_195 -> V_18 ;
enum V_75 V_76 ;
int V_27 ;
V_216 -> V_277 = 0 ;
if ( ! F_124 ( V_194 ) )
return 0 ;
V_216 -> V_278 . V_279 = V_216 -> V_237 ;
V_27 = F_125 ( & V_216 -> V_278 ,
F_126 ( V_194 ) , V_216 -> V_278 . V_279 ) ;
if ( V_27 )
return - V_42 ;
V_195 -> V_81 = F_127 ( V_194 -> V_280 , V_194 , V_216 -> V_278 . V_279 ) ;
F_21 ( V_195 -> V_81 > F_126 ( V_194 ) ) ;
V_76 = ( F_128 ( V_194 ) == V_281 ) ? V_208 : V_206 ;
V_216 -> V_277 = F_52 ( V_3 -> V_64 -> V_24 , V_216 -> V_278 . V_279 ,
V_195 -> V_81 , V_76 ) ;
if ( F_90 ( V_216 -> V_277 <= 0 ) ) {
F_129 ( & V_216 -> V_278 , true ) ;
V_216 -> V_277 = 0 ;
return - V_98 ;
}
return 0 ;
}
static void
F_130 ( struct V_1 * V_3 , struct V_193 * V_194 ,
struct V_15 * V_195 )
{
struct V_16 * V_216 = & V_195 -> V_18 ;
if ( ! V_216 -> V_277 )
return;
F_54 ( V_3 -> V_64 -> V_24 , V_216 -> V_278 . V_279 , V_195 -> V_81 ,
( ( F_128 ( V_194 ) == V_281 ) ?
V_208 : V_206 ) ) ;
F_131 ( V_194 ) ;
F_129 ( & V_216 -> V_278 , true ) ;
V_216 -> V_277 = 0 ;
}
static int
F_132 ( struct V_1 * V_3 , struct V_109 * V_110 ,
struct V_15 * V_195 , V_204 V_225 ,
enum V_282 V_283 )
{
struct V_196 * V_197 = & V_195 -> V_198 ;
struct V_244 * V_245 = & V_197 -> V_245 ;
V_204 V_254 ;
int V_27 ;
if ( ! F_60 ( V_3 ) )
return V_284 ;
V_197 -> V_169 = F_78 ( V_110 -> V_169 ) ;
V_254 = F_133 ( & V_110 -> V_254 ) ;
V_197 -> V_254 = F_70 ( V_254 ) ;
V_197 -> V_225 = F_70 ( V_225 ) ;
switch ( V_283 ) {
case V_285 :
V_197 -> V_26 = V_286 ;
break;
case V_287 :
V_197 -> V_26 = V_288 ;
break;
case V_289 :
V_197 -> V_26 = 0 ;
break;
}
V_195 -> V_18 . V_290 = V_225 ;
V_195 -> V_18 . V_283 = V_283 ;
V_195 -> V_18 . V_224 = 0 ;
V_195 -> V_18 . V_222 = 0 ;
V_195 -> V_18 . V_95 = 0 ;
V_195 -> V_18 . V_291 = F_134 ( V_110 -> V_166 ) ;
F_135 ( V_245 -> V_246 . V_292 ) ;
F_135 ( V_245 -> V_246 . V_293 . V_294 ) ;
F_135 ( V_245 -> V_246 . V_293 . V_295 ) ;
V_245 -> V_246 . V_26 |= V_296 ;
V_245 -> V_297 . V_293 . V_279 . type = V_298 ;
V_245 -> V_297 . V_293 . V_279 . V_84 = F_136 ( V_225 ) ;
V_245 -> V_297 . V_293 . V_279 . V_78 = 0 ;
F_135 ( V_245 -> V_246 . V_233 != F_134 ( V_195 -> V_232 ) ) ;
if ( V_195 -> V_194 ) {
V_27 = F_123 ( V_3 , V_195 -> V_194 , V_195 ) ;
if ( V_27 < 0 ) {
F_62 ( V_110 -> V_3 -> V_3 . V_23 ,
L_9 , V_27 ) ;
F_131 ( V_195 -> V_194 ) ;
F_57 ( V_3 ) ;
return ( V_27 == - V_42 || V_27 == - V_299 ) ?
V_300 : V_284 ;
}
}
F_47 ( V_3 -> V_64 -> V_24 , V_195 -> V_18 . V_207 ,
sizeof( V_195 -> V_198 ) , V_208 ) ;
F_84 ( & V_195 -> V_209 , V_271 ) ;
if ( V_195 -> V_194 )
F_137 ( V_195 -> V_194 ) ;
V_27 = V_3 -> V_64 -> V_51 -> V_31 ( & V_3 -> V_64 -> V_7 ,
& V_3 -> V_72 -> V_10 ,
V_110 -> V_258 , & V_195 -> V_18 ) ;
if ( V_27 ) {
F_62 ( V_3 -> V_24 ,
L_10 , V_27 ) ;
if ( V_195 -> V_194 ) {
F_130 ( V_3 , V_195 -> V_194 , V_195 ) ;
F_131 ( V_195 -> V_194 ) ;
}
F_57 ( V_3 ) ;
if ( V_27 != - V_301 )
return V_284 ;
if ( V_195 -> V_194 ) {
F_138 ( V_195 -> V_194 -> V_280 ) ;
F_139 ( V_110 -> V_250 , V_302 ) ;
}
return V_300 ;
}
return V_303 ;
}
static int
F_140 ( struct V_249 * V_250 ,
const struct V_304 * V_305 )
{
struct V_306 * V_307 = V_250 -> V_110 -> V_308 ;
struct V_109 * V_110 = V_250 -> V_252 ;
struct V_1 * V_3 = V_110 -> V_3 ;
struct V_193 * V_194 = V_305 -> V_194 ;
struct V_15 * V_195 = F_82 ( V_194 ) ;
struct V_196 * V_197 = & V_195 -> V_198 ;
struct V_244 * V_245 = & V_197 -> V_245 ;
enum V_282 V_283 ;
V_204 V_225 ;
int V_27 ;
V_27 = F_141 ( V_307 , V_194 , V_245 ) ;
if ( V_27 )
return V_27 ;
V_225 = F_124 ( V_194 ) ;
if ( V_225 )
V_283 = ( ( F_128 ( V_194 ) == V_281 ) ?
V_285 : V_287 ) ;
else
V_283 = V_289 ;
return F_132 ( V_3 , V_110 , V_195 , V_225 , V_283 ) ;
}
static struct V_309 *
F_142 ( struct V_109 * V_110 )
{
if ( V_110 -> V_166 == 0 )
return V_110 -> V_3 -> V_260 . V_310 [ V_110 -> V_166 ] ;
return V_110 -> V_3 -> V_270 . V_310 [ V_110 -> V_166 - 1 ] ;
}
static int
F_143 ( struct V_249 * V_250 , unsigned int V_311 )
{
struct V_109 * V_110 = V_250 -> V_252 ;
struct V_1 * V_3 = V_110 -> V_3 ;
struct V_193 * V_94 ;
struct V_15 * V_195 ;
V_94 = F_144 ( F_142 ( V_110 ) , V_311 ) ;
if ( ! V_94 ) {
F_62 ( V_110 -> V_3 -> V_3 . V_23 ,
L_11 ,
V_311 , V_110 -> V_166 ) ;
return 0 ;
}
V_195 = F_82 ( V_94 ) ;
if ( ( F_87 ( & V_195 -> V_209 ) == V_271 ) &&
( V_3 -> V_64 -> V_51 -> V_312 ) )
V_3 -> V_64 -> V_51 -> V_312 ( & V_3 -> V_64 -> V_7 ,
V_110 -> V_258 ) ;
return ( ( F_87 ( & V_195 -> V_209 ) != V_271 ) ) ;
}
static void
F_145 ( struct V_2 * V_313 , int V_314 )
{
struct V_1 * V_3 = F_1 ( V_313 ) ;
struct V_15 * V_213 ;
int V_27 ;
if ( V_314 > V_215 )
return;
V_213 = & V_3 -> V_214 [ V_314 ] ;
V_27 = F_132 ( V_3 , V_213 -> V_110 , V_213 , 0 ,
V_289 ) ;
if ( V_27 )
F_62 ( V_3 -> V_3 . V_23 ,
L_12 , V_314 ) ;
}
static void
F_146 ( struct V_193 * V_194 )
{
struct V_15 * V_195 = F_82 ( V_194 ) ;
struct V_1 * V_3 = V_195 -> V_3 ;
int error = 0 , V_209 ;
V_209 = F_121 ( & V_195 -> V_209 , V_240 ) ;
F_131 ( V_194 ) ;
F_130 ( V_3 , V_194 , V_195 ) ;
if ( F_90 ( V_194 -> V_315 ) ) {
if ( F_147 ( V_194 , V_194 -> V_315 ) ) {
F_148 ( V_194 ) ;
return;
}
if ( F_149 ( V_194 ) )
error = V_194 -> V_315 ;
else
error = F_150 ( V_194 -> V_315 ) ;
}
F_57 ( V_3 ) ;
F_151 ( V_194 , error ) ;
}
static int
F_152 ( struct V_1 * V_3 )
{
V_204 V_316 ;
int error ;
F_102 ( V_3 , 0 , V_317 ) ;
error = F_68 ( V_3 , & V_3 -> V_242 [ 0 ] ,
V_317 ,
( V_317 / 4 ) ) ;
if ( error )
return error ;
memset ( & V_3 -> V_260 , 0 , sizeof( V_3 -> V_260 ) ) ;
V_3 -> V_260 . V_51 = & V_318 ;
V_3 -> V_260 . V_319 = V_317 ;
V_3 -> V_260 . V_320 = 2 ;
V_3 -> V_260 . V_241 = V_321 ;
V_3 -> V_260 . V_322 = sizeof( struct V_15 ) +
( V_238 *
sizeof( struct V_79 ) ) +
V_3 -> V_64 -> V_51 -> V_323 ;
V_3 -> V_260 . V_252 = V_3 ;
V_3 -> V_260 . V_324 = 1 ;
V_3 -> V_260 . V_142 = V_325 ;
error = F_153 ( & V_3 -> V_260 ) ;
if ( error )
goto V_326;
V_3 -> V_3 . V_259 = F_154 ( & V_3 -> V_260 ) ;
if ( F_155 ( V_3 -> V_3 . V_259 ) ) {
error = F_156 ( V_3 -> V_3 . V_259 ) ;
goto V_327;
}
error = F_111 ( V_3 , & V_3 -> V_242 [ 0 ] , 0 ,
V_317 ) ;
if ( error )
goto V_328;
error = F_157 ( & V_3 -> V_3 ) ;
if ( error )
goto V_329;
error = F_158 ( & V_3 -> V_3 , V_330 , & V_3 -> V_331 ) ;
if ( error ) {
F_62 ( V_3 -> V_3 . V_23 ,
L_13 ) ;
goto V_329;
}
V_3 -> V_3 . V_127 =
F_73 ( int , F_159 ( V_3 -> V_331 ) , V_3 -> V_3 . V_127 ) ;
error = F_160 ( & V_3 -> V_3 , V_3 -> V_331 ) ;
if ( error )
goto V_329;
V_316 = F_73 ( V_204 , V_332 ,
V_3 -> V_64 -> V_51 -> V_35 ) ;
V_3 -> V_3 . V_333 = ( V_316 - 1 ) << ( V_334 - 9 ) ;
error = F_161 ( & V_3 -> V_3 ) ;
if ( error )
goto V_329;
F_162 ( & V_3 -> V_3 ) ;
return 0 ;
V_329:
F_106 ( V_3 , & V_3 -> V_242 [ 0 ] , 0 ) ;
V_328:
F_108 ( V_3 -> V_3 . V_259 ) ;
V_327:
F_109 ( & V_3 -> V_260 ) ;
V_326:
F_103 ( & V_3 -> V_242 [ 0 ] ) ;
return error ;
}
static void
F_163 ( struct V_193 * V_94 , void * V_192 , bool V_274 )
{
struct V_2 * V_267 = V_192 ;
struct V_1 * V_3 = F_1 ( V_267 ) ;
struct V_15 * V_195 = F_82 ( V_94 ) ;
int V_95 ;
if ( ! F_164 ( V_94 ) )
return;
V_95 = F_120 ( V_3 , V_195 ) ;
if ( V_95 )
return;
}
static void
F_165 ( struct V_1 * V_3 )
{
if ( V_3 -> V_261 > 1 ) {
F_166 ( & V_3 -> V_3 ) ;
F_167 ( & V_3 -> V_270 ,
F_163 , & V_3 -> V_3 ) ;
}
if ( V_3 -> V_3 . V_209 == V_335 )
F_168 ( & V_3 -> V_3 ) ;
F_138 ( V_3 -> V_3 . V_259 ) ;
F_167 ( & V_3 -> V_260 ,
F_163 , & V_3 -> V_3 ) ;
}
static void
F_169 ( struct V_1 * V_3 )
{
F_170 ( & V_3 -> V_3 ) ;
F_165 ( V_3 ) ;
F_171 ( & V_3 -> V_3 ) ;
F_172 ( & V_3 -> V_3 ) ;
}
static void
F_173 ( struct V_336 * V_337 )
{
struct V_1 * V_3 =
F_2 ( V_337 , struct V_1 , V_338 ) ;
F_169 ( V_3 ) ;
}
static int
F_38 ( struct V_1 * V_3 )
{
if ( ! F_174 ( & V_3 -> V_3 , V_339 ) )
return - V_301 ;
if ( ! F_175 ( V_340 , & V_3 -> V_338 ) )
return - V_301 ;
return 0 ;
}
static int
F_176 ( struct V_2 * V_267 )
{
struct V_1 * V_3 = F_1 ( V_267 ) ;
struct V_8 * V_72 = V_3 -> V_72 ;
unsigned long V_26 ;
int V_27 ;
F_14 ( & V_72 -> V_71 , V_26 ) ;
V_27 = F_38 ( V_3 ) ;
F_16 ( & V_72 -> V_71 , V_26 ) ;
if ( V_27 )
return V_27 ;
F_177 ( & V_3 -> V_338 ) ;
return 0 ;
}
static int
F_178 ( struct V_2 * V_267 )
{
return - V_226 ;
}
static int
F_179 ( struct V_1 * V_3 )
{
struct V_341 * V_130 = V_3 -> V_3 . V_130 ;
int V_27 ;
V_27 = F_180 ( & V_3 -> V_3 , & V_130 -> V_342 ) ;
if ( V_27 ) {
F_181 ( V_3 -> V_3 . V_23 ,
L_14 , V_27 ) ;
return V_27 ;
}
V_3 -> V_261 = V_130 -> V_342 + 1 ;
if ( ! V_130 -> V_342 )
return 0 ;
F_181 ( V_3 -> V_3 . V_23 , L_15 ,
V_130 -> V_342 ) ;
F_116 ( V_3 ) ;
memset ( & V_3 -> V_270 , 0 , sizeof( V_3 -> V_270 ) ) ;
V_3 -> V_270 . V_51 = & V_343 ;
V_3 -> V_270 . V_319 = V_3 -> V_3 . V_130 -> V_253 ;
V_3 -> V_270 . V_320 = 1 ;
V_3 -> V_270 . V_241 = V_321 ;
V_3 -> V_270 . V_26 = V_344 ;
V_3 -> V_270 . V_322 = sizeof( struct V_15 ) +
( V_238 *
sizeof( struct V_79 ) ) +
V_3 -> V_64 -> V_51 -> V_323 ;
V_3 -> V_270 . V_252 = V_3 ;
V_3 -> V_270 . V_324 = V_3 -> V_261 - 1 ;
V_3 -> V_270 . V_142 = V_345 ;
V_27 = F_153 ( & V_3 -> V_270 ) ;
if ( V_27 )
return V_27 ;
V_3 -> V_3 . V_268 = & V_3 -> V_270 ;
V_3 -> V_3 . V_269 = F_154 ( & V_3 -> V_270 ) ;
if ( F_155 ( V_3 -> V_3 . V_269 ) ) {
V_27 = F_156 ( V_3 -> V_3 . V_269 ) ;
goto V_346;
}
V_27 = F_113 ( V_3 , V_3 -> V_3 . V_130 -> V_253 ) ;
if ( V_27 )
goto V_347;
V_27 = F_114 ( V_3 , V_3 -> V_3 . V_130 -> V_253 ) ;
if ( V_27 )
goto V_348;
return 0 ;
V_348:
F_112 ( V_3 ) ;
V_347:
F_170 ( & V_3 -> V_3 ) ;
F_108 ( V_3 -> V_3 . V_269 ) ;
V_346:
F_109 ( & V_3 -> V_270 ) ;
F_110 ( V_3 ) ;
V_3 -> V_3 . V_268 = NULL ;
return V_27 ;
}
static struct V_2 *
F_182 ( struct V_23 * V_24 , struct V_341 * V_130 ,
struct V_4 * V_64 , struct V_8 * V_72 )
{
struct V_1 * V_3 ;
unsigned long V_26 ;
int V_27 , V_28 ;
bool V_349 ;
V_3 = F_69 ( sizeof( * V_3 ) , V_41 ) ;
if ( ! V_3 ) {
V_27 = - V_42 ;
goto V_350;
}
V_28 = F_9 ( & V_265 , 0 , 0 , V_41 ) ;
if ( V_28 < 0 ) {
V_27 = - V_44 ;
goto V_351;
}
V_3 -> V_3 . V_130 = V_130 ;
F_11 ( & V_3 -> V_70 ) ;
F_11 ( & V_3 -> V_100 ) ;
V_3 -> V_64 = V_64 ;
V_3 -> V_72 = V_72 ;
V_3 -> V_24 = V_64 -> V_24 ;
V_3 -> V_209 = V_264 ;
V_3 -> V_266 = V_28 ;
V_27 = F_183 ( & V_3 -> V_3 , V_24 , & V_352 , 0 ) ;
if ( V_27 )
goto V_353;
F_10 ( V_3 -> V_24 ) ;
F_12 ( & V_3 -> V_50 ) ;
F_184 ( & V_3 -> V_338 , F_173 ) ;
F_32 ( & V_3 -> V_71 ) ;
V_3 -> V_261 = F_73 (unsigned int,
opts->nr_io_queues,
lport->ops->max_hw_queues) ;
V_130 -> V_342 = V_3 -> V_261 ;
V_3 -> V_261 ++ ;
V_3 -> V_3 . V_127 = V_130 -> V_253 - 1 ;
V_3 -> V_3 . V_354 = V_130 -> V_354 ;
V_27 = - V_42 ;
V_3 -> V_242 = F_185 ( V_3 -> V_261 , sizeof( struct V_109 ) ,
V_41 ) ;
if ( ! V_3 -> V_242 )
goto V_355;
V_27 = F_152 ( V_3 ) ;
if ( V_27 )
goto V_355;
if ( V_3 -> V_3 . V_356 ) {
F_62 ( V_3 -> V_3 . V_23 , L_16 ,
V_3 -> V_3 . V_356 ) ;
goto V_357;
}
if ( V_130 -> V_253 > V_3 -> V_3 . V_358 ) {
F_186 ( V_3 -> V_3 . V_23 ,
L_17
L_18 ,
V_130 -> V_253 , V_3 -> V_3 . V_358 ) ;
V_130 -> V_253 = V_3 -> V_3 . V_358 ;
}
V_27 = F_98 ( V_3 ) ;
if ( V_27 )
goto V_359;
if ( V_3 -> V_261 > 1 ) {
V_27 = F_179 ( V_3 ) ;
if ( V_27 )
goto V_359;
}
F_14 ( & V_3 -> V_71 , V_26 ) ;
V_3 -> V_209 = V_360 ;
F_16 ( & V_3 -> V_71 , V_26 ) ;
V_349 = F_174 ( & V_3 -> V_3 , V_335 ) ;
F_135 ( ! V_349 ) ;
F_181 ( V_3 -> V_3 . V_23 ,
L_19 ,
V_3 -> V_266 , V_3 -> V_3 . V_130 -> V_140 ) ;
F_187 ( & V_3 -> V_3 . V_63 ) ;
F_14 ( & V_72 -> V_71 , V_26 ) ;
F_15 ( & V_3 -> V_70 , & V_72 -> V_70 ) ;
F_16 ( & V_72 -> V_71 , V_26 ) ;
if ( V_130 -> V_342 ) {
F_188 ( & V_3 -> V_3 ) ;
F_189 ( & V_3 -> V_3 ) ;
}
return & V_3 -> V_3 ;
V_359:
F_86 ( V_3 ) ;
V_357:
F_80 ( V_3 ) ;
F_170 ( & V_3 -> V_3 ) ;
F_107 ( V_3 ) ;
V_355:
F_171 ( & V_3 -> V_3 ) ;
F_172 ( & V_3 -> V_3 ) ;
if ( V_27 > 0 )
V_27 = - V_226 ;
return F_190 ( V_27 ) ;
V_353:
F_18 ( & V_265 , V_3 -> V_266 ) ;
V_351:
F_19 ( V_3 ) ;
V_350:
F_34 ( V_72 ) ;
return F_190 ( V_27 ) ;
}
static int
F_191 ( struct V_361 * V_362 , char * V_363 )
{
T_4 args [ V_364 ] ;
char * V_365 , * V_366 , * V_367 ;
int V_368 , V_27 = 0 ;
V_229 V_369 ;
V_365 = V_366 = F_192 ( V_363 , V_41 ) ;
if ( ! V_365 )
return - V_42 ;
while ( ( V_367 = F_193 ( & V_366 , L_20 ) ) != NULL ) {
if ( ! * V_367 )
continue;
V_368 = F_194 ( V_367 , V_370 , args ) ;
switch ( V_368 ) {
case V_371 :
if ( F_195 ( args , & V_369 ) ) {
V_27 = - V_38 ;
goto V_372;
}
V_362 -> V_373 = V_369 ;
break;
case V_374 :
if ( F_195 ( args , & V_369 ) ) {
V_27 = - V_38 ;
goto V_372;
}
V_362 -> V_375 = V_369 ;
break;
default:
F_196 ( L_21 ,
V_367 ) ;
V_27 = - V_38 ;
goto V_372;
}
}
V_372:
F_19 ( V_365 ) ;
return V_27 ;
}
static struct V_2 *
F_197 ( struct V_23 * V_24 , struct V_341 * V_130 )
{
struct V_4 * V_64 ;
struct V_8 * V_72 ;
struct V_361 V_376 = { 0L , 0L } ;
struct V_361 V_377 = { 0L , 0L } ;
unsigned long V_26 ;
int V_27 ;
V_27 = F_191 ( & V_377 , V_130 -> V_362 ) ;
if ( V_27 || ! V_377 . V_373 || ! V_377 . V_375 )
return F_190 ( - V_38 ) ;
V_27 = F_191 ( & V_376 , V_130 -> V_378 ) ;
if ( V_27 || ! V_376 . V_373 || ! V_376 . V_375 )
return F_190 ( - V_38 ) ;
F_14 ( & V_61 , V_26 ) ;
F_37 (lport, &nvme_fc_lport_list, port_list) {
if ( V_64 -> V_7 . V_54 != V_376 . V_373 ||
V_64 -> V_7 . V_55 != V_376 . V_375 )
continue;
F_37 (rport, &lport->endp_list, endp_list) {
if ( V_72 -> V_10 . V_54 != V_377 . V_373 ||
V_72 -> V_10 . V_55 != V_377 . V_375 )
continue;
if ( ! F_35 ( V_72 ) )
break;
F_16 ( & V_61 , V_26 ) ;
return F_182 ( V_24 , V_130 , V_64 , V_72 ) ;
}
}
F_16 ( & V_61 , V_26 ) ;
return F_190 ( - V_379 ) ;
}
static int T_5 F_198 ( void )
{
V_340 = F_199 ( L_22 ) ;
if ( ! V_340 )
return - V_42 ;
return F_200 ( & V_380 ) ;
}
static void T_6 F_201 ( void )
{
if ( ! F_22 ( & V_62 ) )
F_196 ( L_23 , V_381 ) ;
F_202 ( & V_380 ) ;
F_203 ( V_340 ) ;
F_24 ( & V_43 ) ;
F_24 ( & V_265 ) ;
}
