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
F_11 ( & V_25 -> V_71 ) ;
F_12 ( & V_25 -> V_50 ) ;
F_32 ( & V_25 -> V_72 ) ;
V_25 -> V_10 . V_7 = & V_64 -> V_7 ;
V_25 -> V_24 = V_64 -> V_24 ;
V_25 -> V_64 = V_64 ;
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
struct V_8 * V_73 =
F_2 ( V_50 , struct V_8 , V_50 ) ;
struct V_4 * V_64 =
F_3 ( V_73 -> V_10 . V_7 ) ;
unsigned long V_26 ;
F_21 ( V_73 -> V_10 . V_58 != V_65 ) ;
F_21 ( ! F_22 ( & V_73 -> V_70 ) ) ;
F_14 ( & V_61 , V_26 ) ;
F_23 ( & V_73 -> V_49 ) ;
F_16 ( & V_61 , V_26 ) ;
V_64 -> V_51 -> V_30 ( & V_73 -> V_10 ) ;
F_18 ( & V_64 -> V_52 , V_73 -> V_10 . V_60 ) ;
F_19 ( V_73 ) ;
F_26 ( V_64 ) ;
}
static void
F_34 ( struct V_8 * V_73 )
{
F_27 ( & V_73 -> V_50 , F_33 ) ;
}
static int
F_35 ( struct V_8 * V_73 )
{
return F_29 ( & V_73 -> V_50 ) ;
}
static int
F_36 ( struct V_8 * V_73 )
{
struct V_11 * V_74 ;
unsigned long V_26 ;
V_75:
F_14 ( & V_73 -> V_72 , V_26 ) ;
F_37 (lsop, &rport->ls_req_list, lsreq_list) {
if ( ! ( V_74 -> V_26 & V_76 ) ) {
V_74 -> V_26 |= V_76 ;
F_16 ( & V_73 -> V_72 , V_26 ) ;
V_73 -> V_64 -> V_51 -> V_32 ( & V_73 -> V_64 -> V_7 ,
& V_73 -> V_10 ,
& V_74 -> V_14 ) ;
goto V_75;
}
}
F_16 ( & V_73 -> V_72 , V_26 ) ;
return 0 ;
}
int
F_38 ( struct V_9 * V_6 )
{
struct V_8 * V_73 = F_4 ( V_6 ) ;
struct V_1 * V_3 ;
unsigned long V_26 ;
if ( ! V_6 )
return - V_38 ;
F_14 ( & V_73 -> V_72 , V_26 ) ;
if ( V_6 -> V_58 != V_59 ) {
F_16 ( & V_73 -> V_72 , V_26 ) ;
return - V_38 ;
}
V_6 -> V_58 = V_65 ;
F_37 (ctrl, &rport->ctrl_list, ctrl_list)
F_39 ( V_3 ) ;
F_16 ( & V_73 -> V_72 , V_26 ) ;
F_36 ( V_73 ) ;
F_34 ( V_73 ) ;
return 0 ;
}
static inline T_1
F_40 ( struct V_23 * V_24 , void * V_77 , T_2 V_78 ,
enum V_79 V_80 )
{
return V_24 ? F_41 ( V_24 , V_77 , V_78 , V_80 ) : ( T_1 ) 0L ;
}
static inline int
F_42 ( struct V_23 * V_24 , T_1 V_81 )
{
return V_24 ? F_43 ( V_24 , V_81 ) : 0 ;
}
static inline void
F_44 ( struct V_23 * V_24 , T_1 V_82 , T_2 V_78 ,
enum V_79 V_80 )
{
if ( V_24 )
F_45 ( V_24 , V_82 , V_78 , V_80 ) ;
}
static inline void
F_46 ( struct V_23 * V_24 , T_1 V_82 , T_2 V_78 ,
enum V_79 V_80 )
{
if ( V_24 )
F_47 ( V_24 , V_82 , V_78 , V_80 ) ;
}
static inline void
F_48 ( struct V_23 * V_24 , T_1 V_82 , T_2 V_78 ,
enum V_79 V_80 )
{
if ( V_24 )
F_49 ( V_24 , V_82 , V_78 , V_80 ) ;
}
static int
F_50 ( struct V_83 * V_84 , int V_85 )
{
struct V_83 * V_86 ;
int V_87 ;
F_21 ( V_85 == 0 || V_84 [ 0 ] . V_88 == 0 ) ;
F_51 (sg, s, nents, i) {
V_86 -> V_89 = 0L ;
#ifdef F_52
V_86 -> V_90 = V_86 -> V_88 ;
#endif
}
return V_85 ;
}
static inline int
F_53 ( struct V_23 * V_24 , struct V_83 * V_84 , int V_85 ,
enum V_79 V_80 )
{
return V_24 ? F_54 ( V_24 , V_84 , V_85 , V_80 ) : F_50 ( V_84 , V_85 ) ;
}
static inline void
F_55 ( struct V_23 * V_24 , struct V_83 * V_84 , int V_85 ,
enum V_79 V_80 )
{
if ( V_24 )
F_56 ( V_24 , V_84 , V_85 , V_80 ) ;
}
static void
F_57 ( struct V_11 * V_74 )
{
struct V_8 * V_73 = V_74 -> V_73 ;
struct V_12 * V_13 = & V_74 -> V_14 ;
unsigned long V_26 ;
F_14 ( & V_73 -> V_72 , V_26 ) ;
if ( ! V_74 -> V_91 ) {
F_16 ( & V_73 -> V_72 , V_26 ) ;
return;
}
F_23 ( & V_74 -> V_92 ) ;
V_74 -> V_91 = false ;
F_16 ( & V_73 -> V_72 , V_26 ) ;
F_44 ( V_73 -> V_24 , V_13 -> V_93 ,
( V_13 -> V_94 + V_13 -> V_95 ) ,
V_96 ) ;
F_34 ( V_73 ) ;
}
static int
F_58 ( struct V_8 * V_73 ,
struct V_11 * V_74 ,
void (* F_59)( struct V_12 * V_97 , int V_98 ) )
{
struct V_12 * V_13 = & V_74 -> V_14 ;
unsigned long V_26 ;
int V_27 = 0 ;
if ( V_73 -> V_10 . V_58 != V_59 )
return - V_99 ;
if ( ! F_35 ( V_73 ) )
return - V_67 ;
V_13 -> F_59 = F_59 ;
V_74 -> V_73 = V_73 ;
V_74 -> V_91 = false ;
F_11 ( & V_74 -> V_92 ) ;
F_60 ( & V_74 -> V_100 ) ;
V_13 -> V_93 = F_40 ( V_73 -> V_24 , V_13 -> V_101 ,
V_13 -> V_94 + V_13 -> V_95 ,
V_96 ) ;
if ( F_42 ( V_73 -> V_24 , V_13 -> V_93 ) ) {
V_27 = - V_102 ;
goto V_103;
}
V_13 -> V_104 = V_13 -> V_93 + V_13 -> V_94 ;
F_14 ( & V_73 -> V_72 , V_26 ) ;
F_15 ( & V_74 -> V_92 , & V_73 -> V_71 ) ;
V_74 -> V_91 = true ;
F_16 ( & V_73 -> V_72 , V_26 ) ;
V_27 = V_73 -> V_64 -> V_51 -> V_14 ( & V_73 -> V_64 -> V_7 ,
& V_73 -> V_10 , V_13 ) ;
if ( V_27 )
goto V_105;
return 0 ;
V_105:
V_74 -> V_106 = V_27 ;
F_14 ( & V_73 -> V_72 , V_26 ) ;
V_74 -> V_91 = false ;
F_23 ( & V_74 -> V_92 ) ;
F_16 ( & V_73 -> V_72 , V_26 ) ;
F_44 ( V_73 -> V_24 , V_13 -> V_93 ,
( V_13 -> V_94 + V_13 -> V_95 ) ,
V_96 ) ;
V_103:
F_34 ( V_73 ) ;
return V_27 ;
}
static void
F_61 ( struct V_12 * V_13 , int V_98 )
{
struct V_11 * V_74 = F_5 ( V_13 ) ;
V_74 -> V_106 = V_98 ;
F_62 ( & V_74 -> V_100 ) ;
}
static int
F_63 ( struct V_8 * V_73 , struct V_11 * V_74 )
{
struct V_12 * V_13 = & V_74 -> V_14 ;
struct V_107 * V_108 = V_13 -> V_109 ;
int V_27 ;
V_27 = F_58 ( V_73 , V_74 , F_61 ) ;
if ( ! V_27 ) {
F_64 ( & V_74 -> V_100 ) ;
F_57 ( V_74 ) ;
V_27 = V_74 -> V_106 ;
}
if ( V_27 )
return V_27 ;
if ( V_108 -> V_110 . V_111 == V_112 )
return - V_113 ;
return 0 ;
}
static int
F_65 ( struct V_8 * V_73 ,
struct V_11 * V_74 ,
void (* F_59)( struct V_12 * V_97 , int V_98 ) )
{
return F_58 ( V_73 , V_74 , F_59 ) ;
}
static int
F_66 ( struct V_1 * V_3 ,
struct V_114 * V_115 , T_3 V_116 , T_3 V_117 )
{
struct V_11 * V_74 ;
struct V_12 * V_13 ;
struct V_118 * V_119 ;
struct V_120 * V_121 ;
int V_27 , V_122 = 0 ;
V_74 = F_67 ( ( sizeof( * V_74 ) +
V_3 -> V_64 -> V_51 -> V_123 +
sizeof( * V_119 ) + sizeof( * V_121 ) ) , V_41 ) ;
if ( ! V_74 ) {
V_27 = - V_42 ;
goto V_124;
}
V_13 = & V_74 -> V_14 ;
V_13 -> V_53 = ( void * ) & V_74 [ 1 ] ;
V_119 = (struct V_118 * )
( V_13 -> V_53 + V_3 -> V_64 -> V_51 -> V_123 ) ;
V_121 = (struct V_120 * ) & V_119 [ 1 ] ;
V_119 -> V_110 . V_111 = V_125 ;
V_119 -> V_126 =
F_68 ( sizeof( struct V_127 ) ) ;
V_119 -> V_128 . V_129 =
F_68 ( V_130 ) ;
V_119 -> V_128 . V_131 =
F_69 (
sizeof( struct V_127 ) ) ;
V_119 -> V_128 . V_117 = F_70 ( V_117 ) ;
V_119 -> V_128 . V_132 = F_70 ( V_116 ) ;
V_119 -> V_128 . V_133 = F_70 ( 0xffff ) ;
memcpy ( & V_119 -> V_128 . V_134 , & V_3 -> V_3 . V_135 -> V_136 -> V_137 ,
F_71 ( T_2 , V_138 , sizeof( V_139 ) ) ) ;
strncpy ( V_119 -> V_128 . V_140 , V_3 -> V_3 . V_135 -> V_136 -> V_141 ,
F_72 ( V_142 , V_143 ) ) ;
strncpy ( V_119 -> V_128 . V_144 , V_3 -> V_3 . V_135 -> V_145 ,
F_72 ( V_146 , V_143 ) ) ;
V_74 -> V_115 = V_115 ;
V_13 -> V_101 = V_119 ;
V_13 -> V_94 = sizeof( * V_119 ) ;
V_13 -> V_109 = V_121 ;
V_13 -> V_95 = sizeof( * V_121 ) ;
V_13 -> V_147 = V_148 ;
V_27 = F_63 ( V_3 -> V_73 , V_74 ) ;
if ( V_27 )
goto V_149;
if ( V_121 -> V_150 . V_110 . V_111 != V_151 )
V_122 = V_152 ;
else if ( V_121 -> V_150 . V_126 !=
F_69 (
sizeof( struct V_120 ) ) )
V_122 = V_153 ;
else if ( V_121 -> V_150 . V_154 . V_129 !=
F_68 ( V_155 ) )
V_122 = V_156 ;
else if ( V_121 -> V_150 . V_154 . V_131 !=
F_69 ( sizeof( struct V_157 ) ) )
V_122 = V_158 ;
else if ( V_121 -> V_150 . V_154 . V_110 . V_111 != V_125 )
V_122 = V_159 ;
else if ( V_121 -> V_160 . V_129 !=
F_68 ( V_161 ) )
V_122 = V_162 ;
else if ( V_121 -> V_160 . V_131 !=
F_69 (
sizeof( struct V_163 ) ) )
V_122 = V_164 ;
else if ( V_121 -> V_165 . V_129 !=
F_68 ( V_166 ) )
V_122 = V_167 ;
else if ( V_121 -> V_165 . V_131 !=
F_69 ( sizeof( struct V_168 ) ) )
V_122 = V_169 ;
if ( V_122 ) {
V_27 = - V_170 ;
F_73 ( V_3 -> V_24 ,
L_1 ,
V_115 -> V_171 , V_172 [ V_122 ] ) ;
} else {
V_3 -> V_173 =
F_74 ( V_121 -> V_160 . V_173 ) ;
V_115 -> V_174 =
F_74 ( V_121 -> V_165 . V_174 ) ;
F_75 ( V_175 , & V_115 -> V_26 ) ;
}
V_149:
F_19 ( V_74 ) ;
V_124:
if ( V_27 )
F_73 ( V_3 -> V_24 ,
L_2 ,
V_115 -> V_171 , V_27 ) ;
return V_27 ;
}
static int
F_76 ( struct V_1 * V_3 , struct V_114 * V_115 ,
T_3 V_116 , T_3 V_117 )
{
struct V_11 * V_74 ;
struct V_12 * V_13 ;
struct V_176 * V_177 ;
struct V_178 * V_179 ;
int V_27 , V_122 = 0 ;
V_74 = F_67 ( ( sizeof( * V_74 ) +
V_3 -> V_64 -> V_51 -> V_123 +
sizeof( * V_177 ) + sizeof( * V_179 ) ) , V_41 ) ;
if ( ! V_74 ) {
V_27 = - V_42 ;
goto V_124;
}
V_13 = & V_74 -> V_14 ;
V_13 -> V_53 = ( void * ) & V_74 [ 1 ] ;
V_177 = (struct V_176 * )
( V_13 -> V_53 + V_3 -> V_64 -> V_51 -> V_123 ) ;
V_179 = (struct V_178 * ) & V_177 [ 1 ] ;
V_177 -> V_110 . V_111 = V_180 ;
V_177 -> V_126 = F_68 (
sizeof( struct V_163 ) +
sizeof( struct V_181 ) ) ;
V_177 -> V_160 . V_129 = F_68 ( V_161 ) ;
V_177 -> V_160 . V_131 =
F_69 (
sizeof( struct V_163 ) ) ;
V_177 -> V_160 . V_173 = F_77 ( V_3 -> V_173 ) ;
V_177 -> V_182 . V_129 =
F_68 ( V_183 ) ;
V_177 -> V_182 . V_131 =
F_69 (
sizeof( struct V_181 ) ) ;
V_177 -> V_182 . V_117 = F_70 ( V_117 ) ;
V_177 -> V_182 . V_184 = F_70 ( V_115 -> V_171 ) ;
V_177 -> V_182 . V_132 = F_70 ( V_116 ) ;
V_74 -> V_115 = V_115 ;
V_13 -> V_101 = V_177 ;
V_13 -> V_94 = sizeof( * V_177 ) ;
V_13 -> V_109 = V_179 ;
V_13 -> V_95 = sizeof( * V_179 ) ;
V_13 -> V_147 = V_148 ;
V_27 = F_63 ( V_3 -> V_73 , V_74 ) ;
if ( V_27 )
goto V_149;
if ( V_179 -> V_150 . V_110 . V_111 != V_151 )
V_122 = V_152 ;
else if ( V_179 -> V_150 . V_126 !=
F_69 ( sizeof( struct V_178 ) ) )
V_122 = V_185 ;
else if ( V_179 -> V_150 . V_154 . V_129 != F_68 ( V_155 ) )
V_122 = V_156 ;
else if ( V_179 -> V_150 . V_154 . V_131 !=
F_69 ( sizeof( struct V_157 ) ) )
V_122 = V_158 ;
else if ( V_179 -> V_150 . V_154 . V_110 . V_111 != V_180 )
V_122 = V_186 ;
else if ( V_179 -> V_165 . V_129 !=
F_68 ( V_166 ) )
V_122 = V_167 ;
else if ( V_179 -> V_165 . V_131 !=
F_69 ( sizeof( struct V_168 ) ) )
V_122 = V_169 ;
if ( V_122 ) {
V_27 = - V_170 ;
F_73 ( V_3 -> V_24 ,
L_1 ,
V_115 -> V_171 , V_172 [ V_122 ] ) ;
} else {
V_115 -> V_174 =
F_74 ( V_179 -> V_165 . V_174 ) ;
F_75 ( V_175 , & V_115 -> V_26 ) ;
}
V_149:
F_19 ( V_74 ) ;
V_124:
if ( V_27 )
F_73 ( V_3 -> V_24 ,
L_3 ,
V_115 -> V_171 , V_27 ) ;
return V_27 ;
}
static void
F_78 ( struct V_12 * V_13 , int V_98 )
{
struct V_11 * V_74 = F_5 ( V_13 ) ;
F_57 ( V_74 ) ;
F_19 ( V_74 ) ;
}
static void
F_79 ( struct V_1 * V_3 )
{
struct V_187 * V_188 ;
struct V_189 * V_190 ;
struct V_11 * V_74 ;
struct V_12 * V_13 ;
int V_27 ;
V_74 = F_67 ( ( sizeof( * V_74 ) +
V_3 -> V_64 -> V_51 -> V_123 +
sizeof( * V_188 ) + sizeof( * V_190 ) ) ,
V_41 ) ;
if ( ! V_74 )
return;
V_13 = & V_74 -> V_14 ;
V_13 -> V_53 = ( void * ) & V_74 [ 1 ] ;
V_188 = (struct V_187 * )
( V_13 -> V_53 + V_3 -> V_64 -> V_51 -> V_123 ) ;
V_190 = (struct V_189 * ) & V_188 [ 1 ] ;
V_188 -> V_110 . V_111 = V_191 ;
V_188 -> V_126 = F_68 (
sizeof( struct V_163 ) +
sizeof( struct V_192 ) ) ;
V_188 -> V_160 . V_129 = F_68 ( V_161 ) ;
V_188 -> V_160 . V_131 =
F_69 (
sizeof( struct V_163 ) ) ;
V_188 -> V_160 . V_173 = F_77 ( V_3 -> V_173 ) ;
V_188 -> V_193 . V_129 = F_68 (
V_194 ) ;
V_188 -> V_193 . V_131 =
F_69 (
sizeof( struct V_192 ) ) ;
V_188 -> V_193 . V_195 = V_196 ;
V_188 -> V_193 . V_137 = F_77 ( V_3 -> V_173 ) ;
V_13 -> V_101 = V_188 ;
V_13 -> V_94 = sizeof( * V_188 ) ;
V_13 -> V_109 = V_190 ;
V_13 -> V_95 = sizeof( * V_190 ) ;
V_13 -> V_147 = V_148 ;
V_27 = F_65 ( V_3 -> V_73 , V_74 ,
F_78 ) ;
if ( V_27 )
F_19 ( V_74 ) ;
V_3 -> V_173 = 0 ;
}
static int
F_80 ( void * V_197 , struct V_198 * V_199 )
{
struct V_15 * V_200 = F_81 ( V_199 ) ;
struct V_201 * V_202 = & V_200 -> V_203 ;
memset ( V_202 , 0 , sizeof( * V_202 ) ) ;
V_202 -> V_204 = V_205 ;
V_202 -> V_206 = V_207 ;
V_202 -> V_208 = F_70 ( sizeof( * V_202 ) / sizeof( V_209 ) ) ;
memset ( & V_200 -> V_210 , 0 , sizeof( V_200 -> V_210 ) ) ;
return 0 ;
}
static void
F_82 ( struct V_1 * V_3 ,
struct V_15 * V_200 )
{
F_44 ( V_3 -> V_64 -> V_24 , V_200 -> V_18 . V_104 ,
sizeof( V_200 -> V_210 ) , V_211 ) ;
F_44 ( V_3 -> V_64 -> V_24 , V_200 -> V_18 . V_212 ,
sizeof( V_200 -> V_203 ) , V_213 ) ;
F_83 ( & V_200 -> V_214 , V_215 ) ;
}
static void
F_84 ( struct V_216 * V_217 , struct V_198 * V_199 ,
unsigned int V_218 )
{
struct V_15 * V_200 = F_81 ( V_199 ) ;
return F_82 ( V_217 -> V_219 , V_200 ) ;
}
static int
F_85 ( struct V_1 * V_3 , struct V_15 * V_200 )
{
int V_214 ;
V_214 = F_86 ( & V_200 -> V_214 , V_220 ) ;
if ( V_214 != V_221 ) {
F_83 ( & V_200 -> V_214 , V_214 ) ;
return - V_222 ;
}
V_3 -> V_64 -> V_51 -> V_33 ( & V_3 -> V_64 -> V_7 ,
& V_3 -> V_73 -> V_10 ,
V_200 -> V_115 -> V_223 ,
& V_200 -> V_18 ) ;
return 0 ;
}
static void
F_87 ( struct V_1 * V_3 )
{
struct V_15 * V_224 = V_3 -> V_225 ;
unsigned long V_26 ;
int V_87 , V_27 ;
for ( V_87 = 0 ; V_87 < V_226 ; V_87 ++ , V_224 ++ ) {
if ( F_88 ( & V_224 -> V_214 ) != V_221 )
continue;
F_14 ( & V_3 -> V_72 , V_26 ) ;
if ( V_3 -> V_26 & V_227 ) {
V_3 -> V_228 ++ ;
V_224 -> V_26 |= V_76 ;
}
F_16 ( & V_3 -> V_72 , V_26 ) ;
V_27 = F_85 ( V_3 , V_224 ) ;
if ( V_27 ) {
F_14 ( & V_3 -> V_72 , V_26 ) ;
if ( V_3 -> V_26 & V_227 )
V_3 -> V_228 -- ;
V_224 -> V_26 &= ~ V_76 ;
F_16 ( & V_3 -> V_72 , V_26 ) ;
return;
}
}
}
static inline int
F_89 ( struct V_1 * V_3 ,
struct V_15 * V_200 )
{
unsigned long V_26 ;
bool V_229 = false ;
F_14 ( & V_3 -> V_72 , V_26 ) ;
if ( F_90 ( V_200 -> V_26 & V_76 ) ) {
if ( V_3 -> V_26 & V_227 )
V_3 -> V_228 -- ;
}
if ( V_200 -> V_26 & V_230 )
V_229 = true ;
else
V_200 -> V_26 |= V_231 ;
F_16 ( & V_3 -> V_72 , V_26 ) ;
return V_229 ;
}
static void
F_91 ( struct V_16 * V_97 )
{
struct V_15 * V_200 = F_6 ( V_97 ) ;
struct V_198 * V_199 = V_200 -> V_199 ;
struct V_16 * V_232 = & V_200 -> V_18 ;
struct V_1 * V_3 = V_200 -> V_3 ;
struct V_114 * V_115 = V_200 -> V_115 ;
struct V_233 * V_234 = & V_200 -> V_210 . V_234 ;
struct V_235 * V_236 = & V_200 -> V_203 . V_236 ;
T_4 V_98 = F_92 ( V_237 << 1 ) ;
union V_238 V_239 ;
bool V_229 , V_240 = true ;
F_46 ( V_3 -> V_64 -> V_24 , V_200 -> V_18 . V_104 ,
sizeof( V_200 -> V_210 ) , V_211 ) ;
if ( F_88 ( & V_200 -> V_214 ) == V_220 )
V_98 = F_92 ( ( V_241 | V_242 ) << 1 ) ;
else if ( V_232 -> V_98 )
V_98 = F_92 ( V_243 << 1 ) ;
if ( V_98 )
goto F_59;
switch ( V_232 -> V_244 ) {
case 0 :
case V_245 :
if ( V_232 -> V_246 !=
F_93 ( V_200 -> V_203 . V_247 ) ) {
V_98 = F_92 ( V_243 << 1 ) ;
goto F_59;
}
V_239 . V_248 = 0 ;
break;
case sizeof( struct V_249 ) :
if ( F_90 ( F_94 ( V_200 -> V_210 . V_208 ) !=
( V_232 -> V_244 / 4 ) ||
F_93 ( V_200 -> V_210 . V_250 ) !=
V_232 -> V_246 ||
V_200 -> V_210 . V_251 ||
V_236 -> V_252 . V_253 != V_234 -> V_253 ) ) {
V_98 = F_92 ( V_243 << 1 ) ;
goto F_59;
}
V_239 = V_234 -> V_239 ;
V_98 = V_234 -> V_98 ;
break;
default:
V_98 = F_92 ( V_243 << 1 ) ;
goto F_59;
}
V_240 = false ;
F_59:
if ( V_200 -> V_26 & V_254 ) {
F_95 ( & V_115 -> V_3 -> V_3 , V_98 , & V_239 ) ;
V_229 = F_89 ( V_3 , V_200 ) ;
F_83 ( & V_200 -> V_214 , V_255 ) ;
V_200 -> V_26 = V_254 ;
F_96 ( V_3 ) ;
goto V_256;
}
V_229 = F_89 ( V_3 , V_200 ) ;
if ( ! V_229 ) {
if ( F_90 ( V_200 -> V_26 & V_76 ) ) {
V_98 = F_92 ( V_241 << 1 ) ;
if ( F_97 ( V_199 -> V_257 ) )
V_98 |= F_92 ( V_242 << 1 ) ;
}
F_98 ( V_199 , V_98 , V_239 ) ;
} else
F_99 ( V_199 ) ;
V_256:
if ( V_240 )
F_100 ( V_3 , L_4 ) ;
}
static int
F_101 ( struct V_1 * V_3 ,
struct V_114 * V_115 , struct V_15 * V_200 ,
struct V_198 * V_199 , V_209 V_258 )
{
struct V_201 * V_202 = & V_200 -> V_203 ;
int V_27 = 0 ;
memset ( V_200 , 0 , sizeof( * V_200 ) ) ;
V_200 -> V_18 . V_259 = & V_200 -> V_203 ;
V_200 -> V_18 . V_260 = sizeof( V_200 -> V_203 ) ;
V_200 -> V_18 . V_109 = & V_200 -> V_210 ;
V_200 -> V_18 . V_95 = sizeof( V_200 -> V_210 ) ;
V_200 -> V_18 . F_59 = F_91 ;
V_200 -> V_18 . V_261 = (struct V_83 * ) & V_200 [ 1 ] ;
V_200 -> V_18 . V_53 = & V_200 -> V_18 . V_261 [ V_262 ] ;
V_200 -> V_3 = V_3 ;
V_200 -> V_115 = V_115 ;
V_200 -> V_199 = V_199 ;
V_200 -> V_258 = V_258 ;
V_202 -> V_204 = V_205 ;
V_202 -> V_206 = V_207 ;
V_202 -> V_208 = F_70 ( sizeof( * V_202 ) / sizeof( V_209 ) ) ;
V_200 -> V_18 . V_212 = F_40 ( V_3 -> V_64 -> V_24 ,
& V_200 -> V_203 , sizeof( V_200 -> V_203 ) , V_213 ) ;
if ( F_42 ( V_3 -> V_64 -> V_24 , V_200 -> V_18 . V_212 ) ) {
F_73 ( V_3 -> V_24 ,
L_5 ) ;
V_27 = V_102 ;
goto V_263;
}
V_200 -> V_18 . V_104 = F_40 ( V_3 -> V_64 -> V_24 ,
& V_200 -> V_210 , sizeof( V_200 -> V_210 ) ,
V_211 ) ;
if ( F_42 ( V_3 -> V_64 -> V_24 , V_200 -> V_18 . V_104 ) ) {
F_73 ( V_3 -> V_24 ,
L_6 ) ;
V_27 = V_102 ;
}
F_83 ( & V_200 -> V_214 , V_255 ) ;
V_263:
return V_27 ;
}
static int
F_102 ( struct V_216 * V_217 , struct V_198 * V_199 ,
unsigned int V_218 , unsigned int V_264 )
{
struct V_1 * V_3 = V_217 -> V_219 ;
struct V_15 * V_200 = F_81 ( V_199 ) ;
struct V_114 * V_115 = & V_3 -> V_265 [ V_218 + 1 ] ;
return F_101 ( V_3 , V_115 , V_200 , V_199 , V_115 -> V_266 ++ ) ;
}
static int
F_103 ( struct V_216 * V_217 , struct V_198 * V_199 ,
unsigned int V_218 , unsigned int V_264 )
{
struct V_1 * V_3 = V_217 -> V_219 ;
struct V_15 * V_200 = F_81 ( V_199 ) ;
struct V_114 * V_115 = & V_3 -> V_265 [ 0 ] ;
return F_101 ( V_3 , V_115 , V_200 , V_199 , V_115 -> V_266 ++ ) ;
}
static int
F_104 ( struct V_1 * V_3 )
{
struct V_15 * V_224 ;
struct V_201 * V_202 ;
struct V_235 * V_236 ;
void * V_53 ;
int V_87 , V_27 ;
V_224 = V_3 -> V_225 ;
for ( V_87 = 0 ; V_87 < V_226 ; V_87 ++ , V_224 ++ ) {
V_53 = F_67 ( V_3 -> V_64 -> V_51 -> V_267 ,
V_41 ) ;
if ( ! V_53 )
return - V_42 ;
V_202 = & V_224 -> V_203 ;
V_236 = & V_202 -> V_236 ;
V_27 = F_101 ( V_3 , & V_3 -> V_265 [ 0 ] ,
V_224 , (struct V_198 * ) NULL ,
( V_268 + V_87 ) ) ;
if ( V_27 ) {
F_19 ( V_53 ) ;
return V_27 ;
}
V_224 -> V_26 = V_254 ;
V_224 -> V_18 . V_261 = NULL ;
V_224 -> V_18 . V_53 = V_53 ;
memset ( V_236 , 0 , sizeof( * V_236 ) ) ;
V_236 -> V_252 . V_269 = V_270 ;
V_236 -> V_252 . V_253 = V_268 + V_87 ;
}
return 0 ;
}
static void
F_105 ( struct V_1 * V_3 )
{
struct V_15 * V_224 ;
int V_87 ;
V_224 = V_3 -> V_225 ;
for ( V_87 = 0 ; V_87 < V_226 ; V_87 ++ , V_224 ++ ) {
if ( ! V_224 -> V_18 . V_53 )
continue;
F_82 ( V_3 , V_224 ) ;
F_19 ( V_224 -> V_18 . V_53 ) ;
V_224 -> V_18 . V_53 = NULL ;
}
}
static inline void
F_106 ( struct V_271 * V_272 , struct V_1 * V_3 ,
unsigned int V_273 )
{
struct V_114 * V_115 = & V_3 -> V_265 [ V_273 ] ;
V_272 -> V_219 = V_115 ;
V_115 -> V_272 = V_272 ;
}
static int
F_107 ( struct V_271 * V_272 , void * V_197 ,
unsigned int V_218 )
{
struct V_1 * V_3 = V_197 ;
F_106 ( V_272 , V_3 , V_218 + 1 ) ;
return 0 ;
}
static int
F_108 ( struct V_271 * V_272 , void * V_197 ,
unsigned int V_218 )
{
struct V_1 * V_3 = V_197 ;
F_106 ( V_272 , V_3 , V_218 ) ;
return 0 ;
}
static void
F_109 ( struct V_1 * V_3 , int V_28 , T_2 V_274 )
{
struct V_114 * V_115 ;
V_115 = & V_3 -> V_265 [ V_28 ] ;
memset ( V_115 , 0 , sizeof( * V_115 ) ) ;
V_115 -> V_3 = V_3 ;
V_115 -> V_171 = V_28 ;
F_83 ( & V_115 -> V_275 , 1 ) ;
V_115 -> V_24 = V_3 -> V_24 ;
if ( V_28 > 0 )
V_115 -> V_276 = V_3 -> V_3 . V_277 * 16 ;
else
V_115 -> V_276 = sizeof( struct V_235 ) ;
V_115 -> V_274 = V_274 ;
}
static void
F_110 ( struct V_114 * V_115 )
{
if ( ! F_111 ( V_175 , & V_115 -> V_26 ) )
return;
V_115 -> V_174 = 0 ;
F_112 ( V_175 , & V_115 -> V_26 ) ;
}
static void
F_113 ( struct V_1 * V_3 ,
struct V_114 * V_115 , unsigned int V_273 )
{
if ( V_3 -> V_64 -> V_51 -> V_278 )
V_3 -> V_64 -> V_51 -> V_278 ( & V_3 -> V_64 -> V_7 , V_273 ,
V_115 -> V_223 ) ;
V_115 -> V_223 = NULL ;
}
static void
F_114 ( struct V_1 * V_3 )
{
int V_87 ;
for ( V_87 = 1 ; V_87 < V_3 -> V_279 ; V_87 ++ )
F_110 ( & V_3 -> V_265 [ V_87 ] ) ;
}
static int
F_115 ( struct V_1 * V_3 ,
struct V_114 * V_115 , unsigned int V_273 , T_3 V_116 )
{
int V_27 = 0 ;
V_115 -> V_223 = NULL ;
if ( V_3 -> V_64 -> V_51 -> V_280 )
V_27 = V_3 -> V_64 -> V_51 -> V_280 ( & V_3 -> V_64 -> V_7 ,
V_273 , V_116 , & V_115 -> V_223 ) ;
return V_27 ;
}
static void
F_116 ( struct V_1 * V_3 )
{
struct V_114 * V_115 = & V_3 -> V_265 [ V_3 -> V_279 - 1 ] ;
int V_87 ;
for ( V_87 = V_3 -> V_279 - 1 ; V_87 >= 1 ; V_87 -- , V_115 -- )
F_113 ( V_3 , V_115 , V_87 ) ;
}
static int
F_117 ( struct V_1 * V_3 , T_3 V_116 )
{
struct V_114 * V_115 = & V_3 -> V_265 [ 1 ] ;
int V_87 , V_27 ;
for ( V_87 = 1 ; V_87 < V_3 -> V_279 ; V_87 ++ , V_115 ++ ) {
V_27 = F_115 ( V_3 , V_115 , V_87 , V_116 ) ;
if ( V_27 )
goto V_281;
}
return 0 ;
V_281:
for (; V_87 >= 0 ; V_87 -- )
F_113 ( V_3 , & V_3 -> V_265 [ V_87 ] , V_87 ) ;
return V_27 ;
}
static int
F_118 ( struct V_1 * V_3 , T_3 V_116 )
{
int V_87 , V_27 = 0 ;
for ( V_87 = 1 ; V_87 < V_3 -> V_279 ; V_87 ++ ) {
V_27 = F_76 ( V_3 , & V_3 -> V_265 [ V_87 ] , V_116 ,
( V_116 / 5 ) ) ;
if ( V_27 )
break;
V_27 = F_119 ( & V_3 -> V_3 , V_87 ) ;
if ( V_27 )
break;
}
return V_27 ;
}
static void
F_120 ( struct V_1 * V_3 )
{
int V_87 ;
for ( V_87 = 1 ; V_87 < V_3 -> V_279 ; V_87 ++ )
F_109 ( V_3 , V_87 , V_3 -> V_3 . V_132 ) ;
}
static void
F_121 ( struct V_63 * V_50 )
{
struct V_1 * V_3 =
F_2 ( V_50 , struct V_1 , V_50 ) ;
unsigned long V_26 ;
if ( V_3 -> V_3 . V_282 ) {
F_122 ( V_3 -> V_3 . V_283 ) ;
F_123 ( & V_3 -> V_284 ) ;
}
F_14 ( & V_3 -> V_73 -> V_72 , V_26 ) ;
F_23 ( & V_3 -> V_70 ) ;
F_16 ( & V_3 -> V_73 -> V_72 , V_26 ) ;
F_122 ( V_3 -> V_3 . V_285 ) ;
F_123 ( & V_3 -> V_286 ) ;
F_19 ( V_3 -> V_265 ) ;
F_25 ( V_3 -> V_24 ) ;
F_34 ( V_3 -> V_73 ) ;
F_18 ( & V_287 , V_3 -> V_288 ) ;
if ( V_3 -> V_3 . V_135 )
F_124 ( V_3 -> V_3 . V_135 ) ;
F_19 ( V_3 ) ;
}
static void
F_96 ( struct V_1 * V_3 )
{
F_27 ( & V_3 -> V_50 , F_121 ) ;
}
static int
F_125 ( struct V_1 * V_3 )
{
return F_29 ( & V_3 -> V_50 ) ;
}
static void
F_126 ( struct V_2 * V_289 )
{
struct V_1 * V_3 = F_1 ( V_289 ) ;
F_21 ( V_289 != & V_3 -> V_3 ) ;
F_96 ( V_3 ) ;
}
static void
F_100 ( struct V_1 * V_3 , char * V_290 )
{
F_127 ( V_3 -> V_3 . V_23 ,
L_7 ,
V_3 -> V_288 , V_290 ) ;
F_127 ( V_3 -> V_3 . V_23 ,
L_8 , V_3 -> V_288 ) ;
if ( V_3 -> V_279 > 1 )
F_128 ( & V_3 -> V_3 ) ;
if ( ! F_129 ( & V_3 -> V_3 , V_291 ) ) {
F_73 ( V_3 -> V_3 . V_23 ,
L_9
L_10 , V_3 -> V_288 ) ;
return;
}
if ( ! F_130 ( V_292 , & V_3 -> V_293 ) )
F_73 ( V_3 -> V_3 . V_23 ,
L_11
L_12 , V_3 -> V_288 ) ;
}
static enum V_294
F_131 ( struct V_198 * V_199 , bool V_295 )
{
struct V_15 * V_200 = F_81 ( V_199 ) ;
struct V_1 * V_3 = V_200 -> V_3 ;
int V_27 ;
if ( V_295 )
return V_296 ;
V_27 = F_85 ( V_3 , V_200 ) ;
if ( V_27 )
return V_297 ;
F_100 ( V_3 , L_13 ) ;
return V_297 ;
}
static int
F_132 ( struct V_1 * V_3 , struct V_198 * V_199 ,
struct V_15 * V_200 )
{
struct V_16 * V_232 = & V_200 -> V_18 ;
enum V_79 V_80 ;
int V_27 ;
V_232 -> V_298 = 0 ;
if ( ! F_133 ( V_199 ) )
return 0 ;
V_232 -> V_299 . V_300 = V_232 -> V_261 ;
V_27 = F_134 ( & V_232 -> V_299 ,
F_135 ( V_199 ) , V_232 -> V_299 . V_300 ) ;
if ( V_27 )
return - V_42 ;
V_200 -> V_85 = F_136 ( V_199 -> V_257 , V_199 , V_232 -> V_299 . V_300 ) ;
F_21 ( V_200 -> V_85 > F_135 ( V_199 ) ) ;
V_80 = ( F_137 ( V_199 ) == V_301 ) ? V_213 : V_211 ;
V_232 -> V_298 = F_53 ( V_3 -> V_64 -> V_24 , V_232 -> V_299 . V_300 ,
V_200 -> V_85 , V_80 ) ;
if ( F_90 ( V_232 -> V_298 <= 0 ) ) {
F_138 ( & V_232 -> V_299 , true ) ;
V_232 -> V_298 = 0 ;
return - V_102 ;
}
return 0 ;
}
static void
F_139 ( struct V_1 * V_3 , struct V_198 * V_199 ,
struct V_15 * V_200 )
{
struct V_16 * V_232 = & V_200 -> V_18 ;
if ( ! V_232 -> V_298 )
return;
F_55 ( V_3 -> V_64 -> V_24 , V_232 -> V_299 . V_300 , V_200 -> V_85 ,
( ( F_137 ( V_199 ) == V_301 ) ?
V_213 : V_211 ) ) ;
F_140 ( V_199 ) ;
F_138 ( & V_232 -> V_299 , true ) ;
V_232 -> V_298 = 0 ;
}
static int
F_141 ( struct V_1 * V_3 , struct V_114 * V_115 ,
struct V_15 * V_200 , V_209 V_247 ,
enum V_302 V_303 )
{
struct V_201 * V_202 = & V_200 -> V_203 ;
struct V_235 * V_236 = & V_202 -> V_236 ;
V_209 V_275 ;
int V_27 ;
if ( V_3 -> V_73 -> V_10 . V_58 != V_59 )
return V_304 ;
if ( ! F_125 ( V_3 ) )
return V_304 ;
V_202 -> V_174 = F_77 ( V_115 -> V_174 ) ;
V_275 = F_142 ( & V_115 -> V_275 ) ;
V_202 -> V_275 = F_68 ( V_275 ) ;
V_202 -> V_247 = F_68 ( V_247 ) ;
switch ( V_303 ) {
case V_305 :
V_202 -> V_26 = V_306 ;
break;
case V_307 :
V_202 -> V_26 = V_308 ;
break;
case V_309 :
V_202 -> V_26 = 0 ;
break;
}
V_200 -> V_18 . V_310 = V_247 ;
V_200 -> V_18 . V_303 = V_303 ;
V_200 -> V_18 . V_246 = 0 ;
V_200 -> V_18 . V_244 = 0 ;
V_200 -> V_18 . V_98 = V_237 ;
V_200 -> V_18 . V_311 = F_92 ( V_115 -> V_171 ) ;
F_143 ( V_236 -> V_252 . V_312 ) ;
F_143 ( V_236 -> V_252 . V_313 . V_314 ) ;
F_143 ( V_236 -> V_252 . V_313 . V_315 ) ;
V_236 -> V_252 . V_26 |= V_316 ;
V_236 -> V_317 . V_313 . V_300 . type = V_318 ;
V_236 -> V_317 . V_313 . V_300 . V_88 = F_144 ( V_247 ) ;
V_236 -> V_317 . V_313 . V_300 . V_82 = 0 ;
if ( ! ( V_200 -> V_26 & V_254 ) ) {
V_27 = F_132 ( V_3 , V_200 -> V_199 , V_200 ) ;
if ( V_27 < 0 ) {
F_140 ( V_200 -> V_199 ) ;
F_96 ( V_3 ) ;
return ( V_27 == - V_42 || V_27 == - V_319 ) ?
V_320 : V_304 ;
}
}
F_48 ( V_3 -> V_64 -> V_24 , V_200 -> V_18 . V_212 ,
sizeof( V_200 -> V_203 ) , V_213 ) ;
F_83 ( & V_200 -> V_214 , V_221 ) ;
if ( ! ( V_200 -> V_26 & V_254 ) )
F_145 ( V_200 -> V_199 ) ;
V_27 = V_3 -> V_64 -> V_51 -> V_31 ( & V_3 -> V_64 -> V_7 ,
& V_3 -> V_73 -> V_10 ,
V_115 -> V_223 , & V_200 -> V_18 ) ;
if ( V_27 ) {
if ( V_200 -> V_199 ) {
F_139 ( V_3 , V_200 -> V_199 , V_200 ) ;
F_140 ( V_200 -> V_199 ) ;
}
F_96 ( V_3 ) ;
if ( V_27 != - V_321 )
return V_304 ;
if ( V_200 -> V_199 ) {
F_146 ( V_200 -> V_199 -> V_257 ) ;
F_147 ( V_115 -> V_272 , V_322 ) ;
}
return V_320 ;
}
return V_323 ;
}
static int
F_148 ( struct V_271 * V_272 ,
const struct V_324 * V_325 )
{
struct V_326 * V_327 = V_272 -> V_115 -> V_328 ;
struct V_114 * V_115 = V_272 -> V_219 ;
struct V_1 * V_3 = V_115 -> V_3 ;
struct V_198 * V_199 = V_325 -> V_199 ;
struct V_15 * V_200 = F_81 ( V_199 ) ;
struct V_201 * V_202 = & V_200 -> V_203 ;
struct V_235 * V_236 = & V_202 -> V_236 ;
enum V_302 V_303 ;
V_209 V_247 ;
int V_27 ;
V_27 = F_149 ( V_327 , V_199 , V_236 ) ;
if ( V_27 )
return V_27 ;
V_247 = F_133 ( V_199 ) ;
if ( V_247 )
V_303 = ( ( F_137 ( V_199 ) == V_301 ) ?
V_305 : V_307 ) ;
else
V_303 = V_309 ;
return F_141 ( V_3 , V_115 , V_200 , V_247 , V_303 ) ;
}
static struct V_329 *
F_150 ( struct V_114 * V_115 )
{
if ( V_115 -> V_171 == 0 )
return V_115 -> V_3 -> V_286 . V_330 [ V_115 -> V_171 ] ;
return V_115 -> V_3 -> V_284 . V_330 [ V_115 -> V_171 - 1 ] ;
}
static int
F_151 ( struct V_271 * V_272 , unsigned int V_331 )
{
struct V_114 * V_115 = V_272 -> V_219 ;
struct V_1 * V_3 = V_115 -> V_3 ;
struct V_198 * V_97 ;
struct V_15 * V_200 ;
V_97 = F_152 ( F_150 ( V_115 ) , V_331 ) ;
if ( ! V_97 )
return 0 ;
V_200 = F_81 ( V_97 ) ;
if ( ( F_88 ( & V_200 -> V_214 ) == V_221 ) &&
( V_3 -> V_64 -> V_51 -> V_332 ) )
V_3 -> V_64 -> V_51 -> V_332 ( & V_3 -> V_64 -> V_7 ,
V_115 -> V_223 ) ;
return ( ( F_88 ( & V_200 -> V_214 ) != V_221 ) ) ;
}
static void
F_153 ( struct V_2 * V_333 , int V_334 )
{
struct V_1 * V_3 = F_1 ( V_333 ) ;
struct V_15 * V_224 ;
unsigned long V_26 ;
bool V_335 = false ;
int V_27 ;
if ( V_334 > V_226 )
return;
F_14 ( & V_3 -> V_72 , V_26 ) ;
if ( V_3 -> V_26 & V_227 )
V_335 = true ;
F_16 ( & V_3 -> V_72 , V_26 ) ;
if ( V_335 )
return;
V_224 = & V_3 -> V_225 [ V_334 ] ;
V_27 = F_141 ( V_3 , V_224 -> V_115 , V_224 , 0 ,
V_309 ) ;
if ( V_27 )
F_73 ( V_3 -> V_3 . V_23 ,
L_14 , V_334 ) ;
}
static void
F_99 ( struct V_198 * V_199 )
{
struct V_15 * V_200 = F_81 ( V_199 ) ;
struct V_1 * V_3 = V_200 -> V_3 ;
F_83 ( & V_200 -> V_214 , V_255 ) ;
V_200 -> V_26 &= ~ ( V_76 | V_230 |
V_231 ) ;
F_140 ( V_199 ) ;
F_139 ( V_3 , V_199 , V_200 ) ;
F_154 ( V_199 ) ;
F_96 ( V_3 ) ;
}
static void
F_155 ( struct V_198 * V_199 )
{
struct V_15 * V_200 = F_81 ( V_199 ) ;
struct V_1 * V_3 = V_200 -> V_3 ;
unsigned long V_26 ;
bool V_336 = false ;
F_14 ( & V_3 -> V_72 , V_26 ) ;
if ( V_200 -> V_26 & V_231 )
V_336 = true ;
else
V_200 -> V_26 |= V_230 ;
F_16 ( & V_3 -> V_72 , V_26 ) ;
if ( V_336 )
F_99 ( V_199 ) ;
}
static void
F_156 ( struct V_198 * V_97 , void * V_197 , bool V_295 )
{
struct V_2 * V_289 = V_197 ;
struct V_1 * V_3 = F_1 ( V_289 ) ;
struct V_15 * V_200 = F_81 ( V_97 ) ;
unsigned long V_26 ;
int V_98 ;
if ( ! F_157 ( V_97 ) )
return;
F_14 ( & V_3 -> V_72 , V_26 ) ;
if ( V_3 -> V_26 & V_227 ) {
V_3 -> V_228 ++ ;
V_200 -> V_26 |= V_76 ;
}
F_16 ( & V_3 -> V_72 , V_26 ) ;
V_98 = F_85 ( V_3 , V_200 ) ;
if ( V_98 ) {
F_14 ( & V_3 -> V_72 , V_26 ) ;
if ( V_3 -> V_26 & V_227 )
V_3 -> V_228 -- ;
V_200 -> V_26 &= ~ V_76 ;
F_16 ( & V_3 -> V_72 , V_26 ) ;
return;
}
}
static int
F_158 ( struct V_1 * V_3 )
{
struct V_337 * V_135 = V_3 -> V_3 . V_135 ;
int V_27 ;
V_27 = F_159 ( & V_3 -> V_3 , & V_135 -> V_338 ) ;
if ( V_27 ) {
F_160 ( V_3 -> V_3 . V_23 ,
L_15 , V_27 ) ;
return V_27 ;
}
V_3 -> V_279 = V_135 -> V_338 + 1 ;
if ( ! V_135 -> V_338 )
return 0 ;
F_120 ( V_3 ) ;
memset ( & V_3 -> V_284 , 0 , sizeof( V_3 -> V_284 ) ) ;
V_3 -> V_284 . V_51 = & V_339 ;
V_3 -> V_284 . V_340 = V_3 -> V_3 . V_135 -> V_274 ;
V_3 -> V_284 . V_341 = 1 ;
V_3 -> V_284 . V_264 = V_342 ;
V_3 -> V_284 . V_26 = V_343 ;
V_3 -> V_284 . V_344 = sizeof( struct V_15 ) +
( V_262 *
sizeof( struct V_83 ) ) +
V_3 -> V_64 -> V_51 -> V_267 ;
V_3 -> V_284 . V_219 = V_3 ;
V_3 -> V_284 . V_345 = V_3 -> V_279 - 1 ;
V_3 -> V_284 . V_147 = V_346 ;
V_27 = F_161 ( & V_3 -> V_284 ) ;
if ( V_27 )
return V_27 ;
V_3 -> V_3 . V_282 = & V_3 -> V_284 ;
V_3 -> V_3 . V_283 = F_162 ( & V_3 -> V_284 ) ;
if ( F_163 ( V_3 -> V_3 . V_283 ) ) {
V_27 = F_164 ( V_3 -> V_3 . V_283 ) ;
goto V_347;
}
V_27 = F_117 ( V_3 , V_3 -> V_3 . V_135 -> V_274 ) ;
if ( V_27 )
goto V_348;
V_27 = F_118 ( V_3 , V_3 -> V_3 . V_135 -> V_274 ) ;
if ( V_27 )
goto V_349;
return 0 ;
V_349:
F_116 ( V_3 ) ;
V_348:
F_165 ( & V_3 -> V_3 ) ;
F_122 ( V_3 -> V_3 . V_283 ) ;
V_347:
F_123 ( & V_3 -> V_284 ) ;
F_114 ( V_3 ) ;
V_3 -> V_3 . V_282 = NULL ;
return V_27 ;
}
static int
F_166 ( struct V_1 * V_3 )
{
struct V_337 * V_135 = V_3 -> V_3 . V_135 ;
int V_27 ;
V_27 = F_159 ( & V_3 -> V_3 , & V_135 -> V_338 ) ;
if ( V_27 ) {
F_160 ( V_3 -> V_3 . V_23 ,
L_15 , V_27 ) ;
return V_27 ;
}
if ( V_3 -> V_279 == 1 )
return 0 ;
F_120 ( V_3 ) ;
V_27 = F_167 ( & V_3 -> V_284 ) ;
if ( V_27 )
goto V_350;
V_27 = F_117 ( V_3 , V_3 -> V_3 . V_135 -> V_274 ) ;
if ( V_27 )
goto V_350;
V_27 = F_118 ( V_3 , V_3 -> V_3 . V_135 -> V_274 ) ;
if ( V_27 )
goto V_349;
return 0 ;
V_349:
F_116 ( V_3 ) ;
V_350:
F_114 ( V_3 ) ;
return V_27 ;
}
static int
F_168 ( struct V_1 * V_3 )
{
struct V_337 * V_135 = V_3 -> V_3 . V_135 ;
V_209 V_351 ;
int V_27 ;
bool V_352 ;
++ V_3 -> V_3 . V_135 -> V_353 ;
F_109 ( V_3 , 0 , V_354 ) ;
V_27 = F_115 ( V_3 , & V_3 -> V_265 [ 0 ] , 0 ,
V_354 ) ;
if ( V_27 )
goto V_355;
V_27 = F_66 ( V_3 , & V_3 -> V_265 [ 0 ] ,
V_354 ,
( V_354 / 4 ) ) ;
if ( V_27 )
goto V_356;
if ( V_3 -> V_3 . V_214 != V_357 )
F_169 ( V_3 -> V_3 . V_285 , true ) ;
V_27 = F_170 ( & V_3 -> V_3 ) ;
if ( V_27 )
goto V_358;
V_27 = F_171 ( & V_3 -> V_3 , V_359 , & V_3 -> V_360 ) ;
if ( V_27 ) {
F_73 ( V_3 -> V_3 . V_23 ,
L_16 ) ;
goto V_358;
}
V_3 -> V_3 . V_132 =
F_71 ( int , F_172 ( V_3 -> V_360 ) + 1 , V_3 -> V_3 . V_132 ) ;
V_27 = F_173 ( & V_3 -> V_3 , V_3 -> V_360 ) ;
if ( V_27 )
goto V_358;
V_351 = F_71 ( V_209 , V_361 ,
V_3 -> V_64 -> V_51 -> V_35 ) ;
V_3 -> V_3 . V_362 = ( V_351 - 1 ) << ( V_363 - 9 ) ;
V_27 = F_174 ( & V_3 -> V_3 ) ;
if ( V_27 )
goto V_358;
if ( V_3 -> V_3 . V_364 ) {
F_73 ( V_3 -> V_3 . V_23 , L_17 ,
V_3 -> V_3 . V_364 ) ;
goto V_358;
}
F_175 ( & V_3 -> V_3 ) ;
if ( V_135 -> V_274 > V_3 -> V_3 . V_365 ) {
F_127 ( V_3 -> V_3 . V_23 ,
L_18
L_19 ,
V_135 -> V_274 , V_3 -> V_3 . V_365 ) ;
V_135 -> V_274 = V_3 -> V_3 . V_365 ;
}
V_27 = F_104 ( V_3 ) ;
if ( V_27 )
goto V_366;
if ( V_3 -> V_279 > 1 ) {
if ( V_3 -> V_3 . V_214 == V_357 )
V_27 = F_158 ( V_3 ) ;
else
V_27 = F_166 ( V_3 ) ;
if ( V_27 )
goto V_366;
}
V_352 = F_129 ( & V_3 -> V_3 , V_367 ) ;
F_143 ( ! V_352 ) ;
V_3 -> V_3 . V_135 -> V_353 = 0 ;
if ( V_3 -> V_279 > 1 ) {
F_176 ( & V_3 -> V_3 ) ;
F_177 ( & V_3 -> V_3 ) ;
F_178 ( & V_3 -> V_3 ) ;
}
return 0 ;
V_366:
F_105 ( V_3 ) ;
F_165 ( & V_3 -> V_3 ) ;
V_358:
F_79 ( V_3 ) ;
V_356:
F_113 ( V_3 , & V_3 -> V_265 [ 0 ] , 0 ) ;
V_355:
F_110 ( & V_3 -> V_265 [ 0 ] ) ;
return V_27 ;
}
static void
F_179 ( struct V_1 * V_3 )
{
unsigned long V_26 ;
F_165 ( & V_3 -> V_3 ) ;
F_14 ( & V_3 -> V_72 , V_26 ) ;
V_3 -> V_26 |= V_227 ;
V_3 -> V_228 = 0 ;
F_16 ( & V_3 -> V_72 , V_26 ) ;
if ( V_3 -> V_279 > 1 ) {
F_128 ( & V_3 -> V_3 ) ;
F_180 ( & V_3 -> V_284 ,
F_156 , & V_3 -> V_3 ) ;
}
F_146 ( V_3 -> V_3 . V_285 ) ;
F_180 ( & V_3 -> V_286 ,
F_156 , & V_3 -> V_3 ) ;
F_87 ( V_3 ) ;
F_14 ( & V_3 -> V_72 , V_26 ) ;
while ( V_3 -> V_228 ) {
F_16 ( & V_3 -> V_72 , V_26 ) ;
F_181 ( 1000 ) ;
F_14 ( & V_3 -> V_72 , V_26 ) ;
}
V_3 -> V_26 &= ~ V_227 ;
F_16 ( & V_3 -> V_72 , V_26 ) ;
F_105 ( V_3 ) ;
if ( V_3 -> V_173 )
F_79 ( V_3 ) ;
if ( V_3 -> V_3 . V_282 ) {
F_116 ( V_3 ) ;
F_114 ( V_3 ) ;
}
F_113 ( V_3 , & V_3 -> V_265 [ 0 ] , 0 ) ;
F_110 ( & V_3 -> V_265 [ 0 ] ) ;
}
static void
F_182 ( struct V_368 * V_369 )
{
struct V_1 * V_3 =
F_2 ( V_369 , struct V_1 , V_370 ) ;
F_183 ( & V_3 -> V_293 ) ;
F_184 ( & V_3 -> V_371 ) ;
F_179 ( V_3 ) ;
F_185 ( & V_3 -> V_3 ) ;
F_186 ( & V_3 -> V_3 ) ;
}
static bool
F_187 ( struct V_1 * V_3 )
{
if ( ! F_129 ( & V_3 -> V_3 , V_372 ) )
return true ;
if ( ! F_130 ( V_292 , & V_3 -> V_370 ) )
return true ;
return false ;
}
static int
F_39 ( struct V_1 * V_3 )
{
return F_187 ( V_3 ) ? - V_321 : 0 ;
}
static int
F_188 ( struct V_2 * V_289 )
{
struct V_1 * V_3 = F_1 ( V_289 ) ;
int V_27 ;
if ( ! F_29 ( & V_3 -> V_3 . V_63 ) )
return - V_321 ;
V_27 = F_39 ( V_3 ) ;
if ( ! V_27 )
F_189 ( V_292 ) ;
F_186 ( & V_3 -> V_3 ) ;
return V_27 ;
}
static void
F_190 ( struct V_1 * V_3 , int V_98 )
{
if ( V_3 -> V_3 . V_214 != V_291 ) {
F_143 ( V_3 -> V_3 . V_214 == V_357 ||
V_3 -> V_3 . V_214 == V_367 ) ;
return;
}
F_160 ( V_3 -> V_3 . V_23 ,
L_20 ,
V_3 -> V_288 , V_98 ) ;
if ( F_191 ( & V_3 -> V_3 ) ) {
F_160 ( V_3 -> V_3 . V_23 ,
L_21 ,
V_3 -> V_288 , V_3 -> V_3 . V_135 -> V_373 ) ;
F_192 ( V_292 , & V_3 -> V_371 ,
V_3 -> V_3 . V_135 -> V_373 * V_374 ) ;
} else {
F_127 ( V_3 -> V_3 . V_23 ,
L_22
L_23 ,
V_3 -> V_288 , V_3 -> V_3 . V_135 -> V_353 ) ;
F_21 ( F_187 ( V_3 ) ) ;
}
}
static void
F_193 ( struct V_368 * V_369 )
{
struct V_1 * V_3 =
F_2 ( V_369 , struct V_1 , V_293 ) ;
int V_27 ;
F_179 ( V_3 ) ;
V_27 = F_168 ( V_3 ) ;
if ( V_27 )
F_190 ( V_3 , V_27 ) ;
else
F_160 ( V_3 -> V_3 . V_23 ,
L_24 , V_3 -> V_288 ) ;
}
static int
F_194 ( struct V_2 * V_289 )
{
struct V_1 * V_3 = F_1 ( V_289 ) ;
F_160 ( V_3 -> V_3 . V_23 ,
L_25 , V_3 -> V_288 ) ;
if ( ! F_129 ( & V_3 -> V_3 , V_375 ) )
return - V_321 ;
if ( ! F_130 ( V_292 , & V_3 -> V_293 ) )
return - V_321 ;
F_195 ( & V_3 -> V_293 ) ;
return 0 ;
}
static void
F_196 ( struct V_368 * V_369 )
{
int V_27 ;
struct V_1 * V_3 =
F_2 ( F_197 ( V_369 ) ,
struct V_1 , V_371 ) ;
V_27 = F_168 ( V_3 ) ;
if ( V_27 )
F_190 ( V_3 , V_27 ) ;
else
F_160 ( V_3 -> V_3 . V_23 ,
L_26 ,
V_3 -> V_288 ) ;
}
static struct V_2 *
F_198 ( struct V_23 * V_24 , struct V_337 * V_135 ,
struct V_4 * V_64 , struct V_8 * V_73 )
{
struct V_1 * V_3 ;
unsigned long V_26 ;
int V_27 , V_28 ;
if ( ! ( V_73 -> V_10 . V_56 &
( V_376 | V_377 ) ) ) {
V_27 = - V_378 ;
goto V_379;
}
V_3 = F_67 ( sizeof( * V_3 ) , V_41 ) ;
if ( ! V_3 ) {
V_27 = - V_42 ;
goto V_379;
}
V_28 = F_9 ( & V_287 , 0 , 0 , V_41 ) ;
if ( V_28 < 0 ) {
V_27 = - V_44 ;
goto V_380;
}
V_3 -> V_3 . V_135 = V_135 ;
F_11 ( & V_3 -> V_70 ) ;
V_3 -> V_64 = V_64 ;
V_3 -> V_73 = V_73 ;
V_3 -> V_24 = V_64 -> V_24 ;
V_3 -> V_288 = V_28 ;
F_10 ( V_3 -> V_24 ) ;
F_12 ( & V_3 -> V_50 ) ;
F_199 ( & V_3 -> V_370 , F_182 ) ;
F_199 ( & V_3 -> V_293 , F_193 ) ;
F_200 ( & V_3 -> V_371 , F_196 ) ;
F_32 ( & V_3 -> V_72 ) ;
V_3 -> V_279 = F_71 (unsigned int,
opts->nr_io_queues,
lport->ops->max_hw_queues) ;
V_135 -> V_338 = V_3 -> V_279 ;
V_3 -> V_279 ++ ;
V_3 -> V_3 . V_132 = V_135 -> V_274 - 1 ;
V_3 -> V_3 . V_381 = V_135 -> V_381 ;
V_27 = - V_42 ;
V_3 -> V_265 = F_201 ( V_3 -> V_279 , sizeof( struct V_114 ) ,
V_41 ) ;
if ( ! V_3 -> V_265 )
goto V_382;
memset ( & V_3 -> V_286 , 0 , sizeof( V_3 -> V_286 ) ) ;
V_3 -> V_286 . V_51 = & V_383 ;
V_3 -> V_286 . V_340 = V_354 ;
V_3 -> V_286 . V_341 = 2 ;
V_3 -> V_286 . V_264 = V_342 ;
V_3 -> V_286 . V_344 = sizeof( struct V_15 ) +
( V_262 *
sizeof( struct V_83 ) ) +
V_3 -> V_64 -> V_51 -> V_267 ;
V_3 -> V_286 . V_219 = V_3 ;
V_3 -> V_286 . V_345 = 1 ;
V_3 -> V_286 . V_147 = V_384 ;
V_27 = F_161 ( & V_3 -> V_286 ) ;
if ( V_27 )
goto V_385;
V_3 -> V_3 . V_285 = F_162 ( & V_3 -> V_286 ) ;
if ( F_163 ( V_3 -> V_3 . V_285 ) ) {
V_27 = F_164 ( V_3 -> V_3 . V_285 ) ;
goto V_386;
}
V_27 = F_202 ( & V_3 -> V_3 , V_24 , & V_387 , 0 ) ;
if ( V_27 )
goto V_388;
F_14 ( & V_73 -> V_72 , V_26 ) ;
F_15 ( & V_3 -> V_70 , & V_73 -> V_70 ) ;
F_16 ( & V_73 -> V_72 , V_26 ) ;
V_27 = F_168 ( V_3 ) ;
if ( V_27 ) {
V_3 -> V_3 . V_135 = NULL ;
F_185 ( & V_3 -> V_3 ) ;
F_186 ( & V_3 -> V_3 ) ;
F_35 ( V_73 ) ;
if ( V_27 > 0 )
V_27 = - V_389 ;
return F_203 ( V_27 ) ;
}
F_204 ( & V_3 -> V_3 . V_63 ) ;
F_160 ( V_3 -> V_3 . V_23 ,
L_27 ,
V_3 -> V_288 , V_3 -> V_3 . V_135 -> V_145 ) ;
return & V_3 -> V_3 ;
V_388:
F_122 ( V_3 -> V_3 . V_285 ) ;
V_386:
F_123 ( & V_3 -> V_286 ) ;
V_385:
F_19 ( V_3 -> V_265 ) ;
V_382:
F_25 ( V_3 -> V_24 ) ;
F_18 ( & V_287 , V_3 -> V_288 ) ;
V_380:
F_19 ( V_3 ) ;
V_379:
return F_203 ( V_27 ) ;
}
static int
F_205 ( struct V_390 * V_391 , char * V_392 )
{
T_5 args [ V_393 ] ;
char * V_394 , * V_395 , * V_396 ;
int V_397 , V_27 = 0 ;
V_248 V_398 ;
V_394 = V_395 = F_206 ( V_392 , V_41 ) ;
if ( ! V_394 )
return - V_42 ;
while ( ( V_396 = F_207 ( & V_395 , L_28 ) ) != NULL ) {
if ( ! * V_396 )
continue;
V_397 = F_208 ( V_396 , V_399 , args ) ;
switch ( V_397 ) {
case V_400 :
if ( F_209 ( args , & V_398 ) ) {
V_27 = - V_38 ;
goto V_401;
}
V_391 -> V_402 = V_398 ;
break;
case V_403 :
if ( F_209 ( args , & V_398 ) ) {
V_27 = - V_38 ;
goto V_401;
}
V_391 -> V_404 = V_398 ;
break;
default:
F_210 ( L_29 ,
V_396 ) ;
V_27 = - V_38 ;
goto V_401;
}
}
V_401:
F_19 ( V_394 ) ;
return V_27 ;
}
static struct V_2 *
F_211 ( struct V_23 * V_24 , struct V_337 * V_135 )
{
struct V_4 * V_64 ;
struct V_8 * V_73 ;
struct V_2 * V_3 ;
struct V_390 V_405 = { 0L , 0L } ;
struct V_390 V_406 = { 0L , 0L } ;
unsigned long V_26 ;
int V_27 ;
V_27 = F_205 ( & V_406 , V_135 -> V_391 ) ;
if ( V_27 || ! V_406 . V_402 || ! V_406 . V_404 )
return F_203 ( - V_38 ) ;
V_27 = F_205 ( & V_405 , V_135 -> V_407 ) ;
if ( V_27 || ! V_405 . V_402 || ! V_405 . V_404 )
return F_203 ( - V_38 ) ;
F_14 ( & V_61 , V_26 ) ;
F_37 (lport, &nvme_fc_lport_list, port_list) {
if ( V_64 -> V_7 . V_54 != V_405 . V_402 ||
V_64 -> V_7 . V_55 != V_405 . V_404 )
continue;
F_37 (rport, &lport->endp_list, endp_list) {
if ( V_73 -> V_10 . V_54 != V_406 . V_402 ||
V_73 -> V_10 . V_55 != V_406 . V_404 )
continue;
if ( ! F_35 ( V_73 ) )
break;
F_16 ( & V_61 , V_26 ) ;
V_3 = F_198 ( V_24 , V_135 , V_64 , V_73 ) ;
if ( F_163 ( V_3 ) )
F_34 ( V_73 ) ;
return V_3 ;
}
}
F_16 ( & V_61 , V_26 ) ;
return F_203 ( - V_408 ) ;
}
static int T_6 F_212 ( void )
{
int V_27 ;
V_292 = F_213 ( L_30 ) ;
if ( ! V_292 )
return - V_42 ;
V_27 = F_214 ( & V_409 ) ;
if ( V_27 )
goto V_410;
return 0 ;
V_410:
F_215 ( V_292 ) ;
return V_27 ;
}
static void T_7 F_216 ( void )
{
if ( ! F_22 ( & V_62 ) )
F_210 ( L_31 , V_411 ) ;
F_217 ( & V_409 ) ;
F_215 ( V_292 ) ;
F_24 ( & V_43 ) ;
F_24 ( & V_287 ) ;
}
