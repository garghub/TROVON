static inline bool F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( F_3 ( V_2 -> V_7 ) )
return false ;
if ( F_3 ( V_4 < V_3 ) )
return false ;
return true ;
}
enum V_8 F_4 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 , struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
struct V_18 * V_19 ;
if ( ! F_5 ( V_2 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! V_2 -> V_20 )
return F_7 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_21 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_19 = F_9 ( V_13 , 0 , V_22 ,
0 , 0 , 0 , NULL , V_23 ) ;
if ( V_19 )
F_10 ( V_17 , V_24 ,
F_11 ( V_19 ) ) ;
F_10 ( V_17 , V_25 ,
F_12 ( V_26 ) ) ;
F_10 ( V_17 , V_25 ,
F_12 ( V_27 ) ) ;
F_10 ( V_17 , V_28 ,
F_13 ( V_29 ) ) ;
F_14 ( V_9 , V_30 ) ;
F_15 ( V_9 , V_31 ) ;
F_10 ( V_17 , V_32 , F_16 () ) ;
return V_33 ;
}
enum V_8 F_17 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 , * V_34 , * V_35 ;
struct V_36 * V_37 ;
struct V_12 * V_38 ;
struct V_39 * V_40 ;
int V_41 ;
if ( ! V_2 -> V_20 )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( V_11 == F_18 ( V_9 -> V_42 . V_43 ) -> V_11 ) {
F_14 ( V_9 , V_44 ) ;
return F_19 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
if ( V_2 -> V_45 -> V_46 != 0 )
return F_19 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_47 ) ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( F_20 ( V_11 -> V_48 . V_49 , V_50 ) )
return F_19 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
V_35 = NULL ;
if ( ! F_21 ( V_9 , V_11 , V_13 , V_2 -> V_5 -> type ,
(struct V_47 * ) V_2 -> V_5 , V_2 ,
& V_35 ) ) {
if ( V_35 ) {
V_40 = F_22 ( V_9 , V_11 , V_13 , V_15 ,
( V_51 * ) ( V_35 -> V_5 ) +
sizeof( struct V_21 ) ,
F_2 ( V_35 -> V_5 -> V_6 ) -
sizeof( struct V_21 ) ) ;
F_23 ( V_35 ) ;
if ( V_40 ) {
F_10 ( V_17 , V_52 ,
F_24 ( V_40 ) ) ;
F_14 ( V_9 , V_53 ) ;
return V_54 ;
} else {
return V_55 ;
}
} else {
return F_19 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
}
}
V_2 -> V_56 . V_57 = (struct V_58 * ) V_2 -> V_59 -> V_60 ;
V_2 -> V_61 . V_62 = F_25 ( V_2 -> V_59 , sizeof( struct V_58 ) ) ;
V_38 = F_26 ( V_11 , V_2 , V_23 ) ;
if ( ! V_38 )
goto V_63;
if ( F_27 ( V_38 ,
F_28 ( F_29 ( V_2 ) ) ,
V_23 ) < 0 )
goto V_64;
if ( ! F_30 ( V_38 , V_2 , F_29 ( V_2 ) ,
(struct V_47 * ) V_2 -> V_5 ,
V_23 ) )
goto V_64;
V_41 = 0 ;
if ( V_35 )
V_41 = F_2 ( V_35 -> V_5 -> V_6 ) -
sizeof( struct V_21 ) ;
V_34 = F_31 ( V_38 , V_2 , V_23 , V_41 ) ;
if ( ! V_34 )
goto V_64;
if ( V_35 ) {
V_37 = (struct V_36 * )
( ( V_51 * ) ( V_35 -> V_5 ) +
sizeof( struct V_21 ) ) ;
F_32 ( V_34 , V_41 , V_37 ) ;
F_23 ( V_35 ) ;
}
F_10 ( V_17 , V_65 , F_33 ( V_38 ) ) ;
F_10 ( V_17 , V_66 , F_34 ( V_34 ) ) ;
F_10 ( V_17 , V_32 , F_16 () ) ;
return V_33 ;
V_64:
F_35 ( V_38 ) ;
V_63:
if ( V_35 )
F_23 ( V_35 ) ;
return V_55 ;
}
enum V_8 F_36 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_47 * V_67 ;
struct V_1 * V_2 = V_15 ;
struct V_1 * V_35 ;
struct V_39 * V_40 ;
if ( ! F_37 ( V_2 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! V_2 -> V_20 )
return F_7 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_68 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_2 -> V_56 . V_57 = (struct V_58 * ) V_2 -> V_59 -> V_60 ;
V_35 = NULL ;
if ( ! F_21 ( V_9 , V_11 , V_13 , V_2 -> V_5 -> type ,
(struct V_47 * ) V_2 -> V_5 , V_2 ,
& V_35 ) ) {
enum V_69 error = V_70 ;
if ( V_35 ) {
V_40 = F_22 ( V_9 , V_11 , V_13 , V_15 ,
( V_51 * ) ( V_35 -> V_5 ) +
sizeof( struct V_21 ) ,
F_2 ( V_35 -> V_5 -> V_6 ) -
sizeof( struct V_21 ) ) ;
F_23 ( V_35 ) ;
if ( V_40 ) {
F_10 ( V_17 , V_52 ,
F_24 ( V_40 ) ) ;
F_14 ( V_9 , V_53 ) ;
error = V_71 ;
}
}
if ( F_38 ( V_72 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
F_14 ( V_9 , V_73 ) ;
return F_39 ( V_9 , V_17 , error , V_74 ,
V_13 , V_2 -> V_75 ) ;
}
V_2 -> V_61 . V_62 = F_25 ( V_2 -> V_59 , sizeof( struct V_58 ) ) ;
V_67 = (struct V_47 * ) V_2 -> V_5 ;
F_10 ( V_17 , V_76 ,
F_40 ( V_67 ) ) ;
F_10 ( V_17 , V_77 , F_16 () ) ;
F_10 ( V_17 , V_25 ,
F_12 ( V_78 ) ) ;
F_10 ( V_17 , V_79 ,
F_12 ( V_80 ) ) ;
F_10 ( V_17 , V_28 ,
F_13 ( V_81 ) ) ;
F_10 ( V_17 , V_82 , F_16 () ) ;
F_10 ( V_17 , V_83 ,
F_34 ( V_35 ) ) ;
return V_54 ;
}
enum V_8 F_41 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 , * V_84 = NULL ;
struct V_12 * V_38 ;
struct V_47 * V_85 ;
struct V_1 * V_2 = V_15 ;
struct V_1 * V_86 ;
struct V_1 * V_34 ;
struct V_87 * V_49 ;
int error = 0 ;
if ( V_11 == F_18 ( V_9 -> V_42 . V_43 ) -> V_11 ) {
F_14 ( V_9 , V_44 ) ;
return F_19 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_21 ) ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
V_49 = V_11 -> V_48 . V_49 ;
if ( ! F_20 ( V_49 , V_88 ) ||
( F_42 ( V_49 , V_89 ) && F_43 ( V_49 ) ) )
return F_19 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
V_2 -> V_56 . V_90 =
(struct V_91 * ) V_2 -> V_59 -> V_60 ;
if ( ! F_44 ( V_2 -> V_59 , F_2 ( V_2 -> V_5 -> V_6 ) -
sizeof( struct V_21 ) ) )
goto V_63;
V_38 = F_45 ( V_11 , V_13 , V_2 , V_23 , & error ,
& V_86 ) ;
if ( ! V_38 ) {
switch ( error ) {
case - V_92 :
goto V_63;
case - V_93 :
F_46 ( V_9 , V_11 , V_13 , V_2 , V_17 ,
V_86 ) ;
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
case - V_94 :
default:
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
}
V_85 = & V_2 -> V_56 . V_90 -> V_95 . V_85 [ 0 ] ;
if ( ! F_30 ( V_38 , V_2 ,
& V_2 -> V_56 . V_90 -> V_95 . V_96 ,
V_85 , V_23 ) )
goto V_64;
error = F_47 ( V_38 , V_23 ) ;
if ( error )
goto V_64;
if ( V_2 -> V_97 ) {
struct V_1 V_98 ;
enum V_99 V_100 ;
if ( ! V_9 -> V_42 . V_101 || ! V_38 -> V_102 . V_103 ) {
F_35 ( V_38 ) ;
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
V_98 . V_59 = V_2 -> V_97 ;
V_98 . V_13 = V_2 -> V_13 ;
V_98 . V_45 = V_2 -> V_45 ;
V_98 . V_5 = (struct V_21 * )
F_48 ( V_2 -> V_97 ,
sizeof( struct V_21 ) ) ;
F_25 ( V_2 -> V_97 , sizeof( struct V_21 ) ) ;
V_98 . V_75 = V_2 -> V_75 ;
V_100 = F_49 ( V_9 , V_11 , V_38 , type , & V_98 ) ;
if ( V_100 != V_104 ) {
F_35 ( V_38 ) ;
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
}
V_34 = F_50 ( V_38 , V_2 ) ;
if ( ! V_34 )
goto V_64;
V_19 = F_9 ( V_38 , 0 , V_105 , 0 ,
V_38 -> V_95 . V_106 ,
V_38 -> V_95 . V_107 ,
NULL , V_23 ) ;
if ( ! V_19 )
goto V_108;
if ( V_38 -> V_102 . V_109 ) {
V_84 = F_51 ( V_38 ,
V_23 ) ;
if ( ! V_84 )
goto V_110;
}
F_10 ( V_17 , V_65 , F_33 ( V_38 ) ) ;
F_10 ( V_17 , V_28 ,
F_13 ( V_111 ) ) ;
F_14 ( V_9 , V_31 ) ;
F_14 ( V_9 , V_112 ) ;
F_10 ( V_17 , V_113 , F_16 () ) ;
if ( V_38 -> V_114 [ V_115 ] )
F_10 ( V_17 , V_79 ,
F_12 ( V_115 ) ) ;
F_10 ( V_17 , V_66 , F_34 ( V_34 ) ) ;
F_10 ( V_17 , V_24 , F_11 ( V_19 ) ) ;
if ( V_84 )
F_10 ( V_17 , V_24 ,
F_11 ( V_84 ) ) ;
return V_54 ;
V_110:
F_52 ( V_19 ) ;
V_108:
F_23 ( V_34 ) ;
V_64:
F_35 ( V_38 ) ;
V_63:
return V_55 ;
}
enum V_8 F_53 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
struct V_18 * V_19 ;
if ( ! F_37 ( V_2 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_21 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
F_10 ( V_17 , V_77 , F_16 () ) ;
F_10 ( V_17 , V_25 ,
F_12 ( V_80 ) ) ;
F_10 ( V_17 , V_28 ,
F_13 ( V_111 ) ) ;
F_14 ( V_9 , V_31 ) ;
F_14 ( V_9 , V_116 ) ;
F_10 ( V_17 , V_113 , F_16 () ) ;
if ( V_13 -> V_114 [ V_115 ] )
F_10 ( V_17 , V_79 ,
F_12 ( V_115 ) ) ;
V_19 = F_9 ( V_13 , 0 , V_105 ,
0 , V_13 -> V_95 . V_106 ,
V_13 -> V_95 . V_107 ,
NULL , V_23 ) ;
if ( ! V_19 )
goto V_63;
F_10 ( V_17 , V_24 , F_11 ( V_19 ) ) ;
if ( V_13 -> V_102 . V_109 ) {
V_19 = F_51 ( V_13 , V_23 ) ;
if ( ! V_19 )
goto V_63;
F_10 ( V_17 , V_24 ,
F_11 ( V_19 ) ) ;
}
return V_54 ;
V_63:
return V_55 ;
}
static enum V_8 F_54 (
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_117 * V_75 = (struct V_117 * ) V_15 ;
struct V_1 * V_118 ;
V_118 = F_55 ( V_13 , V_75 ) ;
if ( ! V_118 )
return V_55 ;
F_10 ( V_17 , V_119 ,
F_56 ( V_75 ) ) ;
F_10 ( V_17 , V_66 , F_34 ( V_118 ) ) ;
return V_54 ;
}
enum V_8 F_57 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_117 * V_75 = (struct V_117 * ) V_15 ;
if ( V_13 -> V_120 >= V_13 -> V_121 ) {
F_10 ( V_17 , V_122 ,
F_58 ( V_123 ) ) ;
F_10 ( V_17 , V_124 ,
F_59 ( V_125 ) ) ;
F_14 ( V_9 , V_73 ) ;
F_15 ( V_9 , V_31 ) ;
return V_33 ;
}
if ( V_75 -> V_126 & V_127 ) {
if ( V_55 ==
F_54 ( V_11 , V_13 , type , V_15 ,
V_17 ) )
return V_55 ;
F_10 ( V_17 , V_128 ,
F_56 ( V_75 ) ) ;
}
F_10 ( V_17 , V_129 ,
F_56 ( V_75 ) ) ;
F_10 ( V_17 , V_130 ,
F_56 ( V_75 ) ) ;
return V_54 ;
}
enum V_8 F_60 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_117 * V_75 = V_15 ;
if ( V_13 -> V_120 >= V_13 -> V_121 ) {
F_10 ( V_17 , V_122 ,
F_58 ( V_123 ) ) ;
F_10 ( V_17 , V_124 ,
F_59 ( V_125 ) ) ;
F_14 ( V_9 , V_73 ) ;
F_15 ( V_9 , V_31 ) ;
return V_33 ;
}
F_61 ( V_13 -> V_131 ) ;
F_10 ( V_17 , V_66 ,
F_34 ( V_13 -> V_131 ) ) ;
F_10 ( V_17 , V_132 , F_56 ( V_75 ) ) ;
return V_54 ;
}
enum V_8 F_62 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 , struct V_16 * V_17 )
{
struct V_133 * V_61 ;
struct V_1 * V_2 = V_15 ;
struct V_1 * V_118 ;
T_2 V_134 = 0 ;
if ( ! F_37 ( V_2 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 ,
sizeof( struct V_135 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_2 -> V_56 . V_136 = (struct V_137 * ) V_2 -> V_59 -> V_60 ;
V_61 = (struct V_133 * ) V_2 -> V_56 . V_136 ;
V_134 = F_2 ( V_2 -> V_5 -> V_6 ) - sizeof( struct V_21 ) ;
if ( F_2 ( V_61 -> V_6 ) > V_134 )
return F_63 ( V_9 , V_11 , V_13 , type , V_15 ,
V_61 , V_17 ) ;
if ( ! F_44 ( V_2 -> V_59 , V_134 ) )
goto V_63;
V_118 = F_64 ( V_13 , V_2 , V_61 , V_134 ) ;
if ( ! V_118 )
goto V_63;
F_10 ( V_17 , V_66 , F_34 ( V_118 ) ) ;
return V_54 ;
V_63:
return V_55 ;
}
enum V_8 F_65 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_138 * V_139 ;
struct V_1 * V_2 = V_15 ;
struct V_117 * V_140 ;
unsigned long V_141 ;
union V_142 V_143 ;
if ( ! F_37 ( V_2 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_21 ) +
sizeof( * V_139 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_139 = (struct V_138 * ) V_2 -> V_59 -> V_60 ;
if ( F_2 ( V_139 -> V_61 . V_6 ) != sizeof( * V_139 ) )
return V_144 ;
V_143 = V_139 -> V_145 ;
V_140 = F_66 ( V_13 , & V_143 ) ;
if ( F_3 ( ! V_140 ) ) {
if ( V_143 . V_146 . V_147 == V_148 ) {
F_67 ( L_1 ,
V_149 ,
V_13 ,
& V_143 . V_150 . V_151 ) ;
} else {
F_67 ( L_2 ,
V_149 ,
V_13 ,
& V_143 . V_152 . V_153 . V_154 ) ;
}
return V_144 ;
}
if ( V_139 -> V_155 != V_140 -> V_155 )
return V_144 ;
V_141 = V_140 -> V_156 + V_140 -> V_157 ;
if ( F_68 ( V_139 -> V_158 , V_159 ) ||
F_68 ( V_159 , V_139 -> V_158 + V_141 ) ) {
F_69 ( L_3
L_4 , V_149 , V_140 ) ;
return V_144 ;
}
F_10 ( V_17 , V_160 , F_56 ( V_140 ) ) ;
return V_54 ;
}
static int F_70 ( struct V_9 * V_9 , union V_142 * V_161 ,
struct V_1 * V_162 ,
struct V_16 * V_17 )
{
struct V_163 * V_164 = F_71 ( V_161 -> V_152 . V_165 ) ;
union V_166 * V_167 ;
struct V_168 * V_169 ;
char V_170 [ sizeof( * V_169 ) + sizeof( * V_167 ) ] ;
struct V_10 * V_11 ;
struct V_39 * V_171 ;
int V_41 ;
V_169 = (struct V_168 * ) V_170 ;
V_167 = (union V_166 * ) V_169 -> V_172 ;
V_41 = V_164 -> V_173 ( V_161 , V_167 ) ;
V_41 += sizeof( * V_169 ) ;
V_169 -> V_174 = V_175 ;
V_169 -> V_6 = F_72 ( V_41 ) ;
V_11 = F_18 ( V_9 -> V_42 . V_43 ) -> V_11 ;
V_171 = F_22 ( V_9 , V_11 , NULL , V_162 , V_169 , V_41 ) ;
if ( ! V_171 )
goto V_176;
F_10 ( V_17 , V_52 , F_24 ( V_171 ) ) ;
F_14 ( V_9 , V_53 ) ;
F_10 ( V_17 , V_177 , F_16 () ) ;
V_176:
return 0 ;
}
static bool F_73 ( const struct V_178 * V_179 ,
union V_142 * V_180 )
{
struct V_117 * V_181 ;
F_74 (addr, list, transports) {
if ( F_75 ( V_180 , & V_181 -> V_180 ) )
return true ;
}
return false ;
}
static int F_76 ( const struct V_12 * V_38 ,
const struct V_12 * V_13 ,
struct V_1 * V_162 ,
struct V_16 * V_17 )
{
struct V_9 * V_9 = F_77 ( V_38 -> V_48 . V_49 ) ;
struct V_117 * V_182 ;
int V_100 = 1 ;
F_74 (new_addr, &new_asoc->peer.transport_addr_list,
transports) {
if ( ! F_73 ( & V_13 -> V_102 . V_183 ,
& V_182 -> V_180 ) ) {
F_70 ( V_9 , & V_182 -> V_180 , V_162 ,
V_17 ) ;
V_100 = 0 ;
break;
}
}
return V_100 ;
}
static void F_78 ( struct V_12 * V_38 ,
const struct V_12 * V_13 )
{
switch ( V_13 -> V_184 ) {
case V_185 :
V_38 -> V_95 . V_186 = V_13 -> V_95 . V_186 ;
V_38 -> V_95 . V_187 = V_13 -> V_95 . V_186 ;
V_38 -> V_95 . V_188 = 0 ;
break;
case V_81 :
V_38 -> V_95 . V_186 = V_13 -> V_95 . V_186 ;
V_38 -> V_95 . V_187 = V_13 -> V_95 . V_186 ;
V_38 -> V_95 . V_188 = V_13 -> V_95 . V_189 ;
break;
default:
V_38 -> V_95 . V_187 = V_13 -> V_95 . V_186 ;
V_38 -> V_95 . V_188 = V_13 -> V_95 . V_189 ;
break;
}
V_38 -> V_190 = V_13 -> V_190 ;
V_38 -> V_95 . V_106 = V_13 -> V_95 . V_106 ;
V_38 -> V_95 . V_107 = V_13 -> V_95 . V_107 ;
V_38 -> V_95 . V_191 = V_13 -> V_95 . V_191 ;
}
static char F_79 ( struct V_12 * V_38 ,
const struct V_12 * V_13 )
{
if ( ( V_13 -> V_95 . V_186 != V_38 -> V_95 . V_186 ) &&
( V_13 -> V_95 . V_189 != V_38 -> V_95 . V_189 ) &&
( V_13 -> V_95 . V_186 == V_38 -> V_95 . V_187 ) &&
( V_13 -> V_95 . V_189 == V_38 -> V_95 . V_188 ) )
return 'A' ;
if ( ( V_13 -> V_95 . V_186 == V_38 -> V_95 . V_186 ) &&
( ( V_13 -> V_95 . V_189 != V_38 -> V_95 . V_189 ) ||
( 0 == V_13 -> V_95 . V_189 ) ) ) {
return 'B' ;
}
if ( ( V_13 -> V_95 . V_186 == V_38 -> V_95 . V_186 ) &&
( V_13 -> V_95 . V_189 == V_38 -> V_95 . V_189 ) )
return 'D' ;
if ( ( V_13 -> V_95 . V_186 != V_38 -> V_95 . V_186 ) &&
( V_13 -> V_95 . V_189 == V_38 -> V_95 . V_189 ) &&
( 0 == V_38 -> V_95 . V_187 ) &&
( 0 == V_38 -> V_95 . V_188 ) )
return 'C' ;
return 'E' ;
}
static enum V_8 F_80 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 , * V_34 , * V_35 ;
struct V_36 * V_37 ;
struct V_12 * V_38 ;
enum V_8 V_192 ;
struct V_39 * V_40 ;
int V_41 ;
if ( ! V_2 -> V_20 )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( V_2 -> V_45 -> V_46 != 0 )
return F_19 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_47 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_2 -> V_56 . V_57 = (struct V_58 * ) V_2 -> V_59 -> V_60 ;
V_2 -> V_61 . V_62 = F_25 ( V_2 -> V_59 , sizeof( struct V_58 ) ) ;
V_35 = NULL ;
if ( ! F_21 ( V_9 , V_11 , V_13 , V_2 -> V_5 -> type ,
(struct V_47 * ) V_2 -> V_5 , V_2 ,
& V_35 ) ) {
if ( V_35 ) {
V_40 = F_22 ( V_9 , V_11 , V_13 , V_15 ,
( V_51 * ) ( V_35 -> V_5 ) +
sizeof( struct V_21 ) ,
F_2 ( V_35 -> V_5 -> V_6 ) -
sizeof( struct V_21 ) ) ;
if ( V_40 ) {
F_10 ( V_17 , V_52 ,
F_24 ( V_40 ) ) ;
F_14 ( V_9 , V_53 ) ;
V_192 = V_54 ;
} else {
V_192 = V_55 ;
}
goto V_193;
} else {
return F_19 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
}
}
V_38 = F_26 ( V_11 , V_2 , V_23 ) ;
if ( ! V_38 )
goto V_63;
if ( F_27 ( V_38 ,
F_28 ( F_29 ( V_2 ) ) , V_23 ) < 0 )
goto V_63;
if ( ! F_30 ( V_38 , V_2 , F_29 ( V_2 ) ,
(struct V_47 * ) V_2 -> V_5 ,
V_23 ) )
goto V_63;
if ( ! F_81 ( V_13 , V_194 ) ) {
if ( ! F_76 ( V_38 , V_13 , V_2 ,
V_17 ) ) {
V_192 = V_54 ;
goto V_195;
}
}
F_78 ( V_38 , V_13 ) ;
V_41 = 0 ;
if ( V_35 ) {
V_41 = F_2 ( V_35 -> V_5 -> V_6 ) -
sizeof( struct V_21 ) ;
}
V_34 = F_31 ( V_38 , V_2 , V_23 , V_41 ) ;
if ( ! V_34 )
goto V_63;
if ( V_35 ) {
V_37 = (struct V_36 * )
( ( V_51 * ) ( V_35 -> V_5 ) +
sizeof( struct V_21 ) ) ;
F_32 ( V_34 , V_41 , V_37 ) ;
}
F_10 ( V_17 , V_65 , F_33 ( V_38 ) ) ;
F_10 ( V_17 , V_66 , F_34 ( V_34 ) ) ;
F_10 ( V_17 , V_32 , F_16 () ) ;
V_192 = V_54 ;
return V_192 ;
V_63:
V_192 = V_55 ;
V_195:
if ( V_38 )
F_35 ( V_38 ) ;
V_193:
if ( V_35 )
F_23 ( V_35 ) ;
return V_192 ;
}
enum V_8 F_82 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
return F_80 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
enum V_8 F_83 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
return F_80 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
enum V_8 F_84 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
if ( V_11 == F_18 ( V_9 -> V_42 . V_43 ) -> V_11 )
return F_85 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
else
return F_86 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
static enum V_8 F_87 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_12 * V_38 )
{
struct V_47 * V_85 ;
enum V_8 V_196 ;
struct V_18 * V_19 ;
struct V_1 * V_34 ;
struct V_1 * V_197 ;
V_85 = & V_2 -> V_56 . V_90 -> V_95 . V_85 [ 0 ] ;
if ( ! F_30 ( V_38 , V_2 , F_29 ( V_2 ) , V_85 ,
V_23 ) )
goto V_63;
if ( ! F_76 ( V_38 , V_13 , V_2 , V_17 ) ) {
return V_54 ;
}
if ( F_81 ( V_13 , V_198 ) ) {
V_196 = F_88 ( V_9 , V_11 , V_13 ,
F_89 ( V_2 -> V_5 -> type ) ,
V_2 , V_17 ) ;
if ( V_55 == V_196 )
goto V_63;
V_197 = F_90 ( V_13 , V_2 ,
V_199 ,
NULL , 0 , 0 ) ;
if ( V_197 )
F_10 ( V_17 , V_66 ,
F_34 ( V_197 ) ) ;
return V_54 ;
}
F_10 ( V_17 , V_200 , F_16 () ) ;
F_10 ( V_17 , V_25 ,
F_12 ( V_201 ) ) ;
F_10 ( V_17 , V_202 , F_16 () ) ;
F_10 ( V_17 , V_25 ,
F_12 ( V_203 ) ) ;
F_10 ( V_17 , V_204 , F_16 () ) ;
V_34 = F_50 ( V_38 , V_2 ) ;
if ( ! V_34 )
goto V_63;
V_19 = F_9 ( V_13 , 0 , V_205 , 0 ,
V_38 -> V_95 . V_106 ,
V_38 -> V_95 . V_107 ,
NULL , V_23 ) ;
if ( ! V_19 )
goto V_108;
F_10 ( V_17 , V_206 , F_33 ( V_38 ) ) ;
F_10 ( V_17 , V_24 , F_11 ( V_19 ) ) ;
if ( F_81 ( V_13 , V_207 ) &&
( F_20 ( V_13 -> V_48 . V_49 , V_50 ) ||
F_91 ( V_13 -> V_48 . V_49 , V_208 ) ) ) {
F_10 ( V_17 , V_66 , F_34 ( V_34 ) ) ;
return F_92 ( V_9 , V_11 , V_13 ,
F_89 ( 0 ) , NULL ,
V_17 ) ;
} else {
F_10 ( V_17 , V_28 ,
F_13 ( V_111 ) ) ;
F_10 ( V_17 , V_66 , F_34 ( V_34 ) ) ;
}
return V_54 ;
V_108:
F_23 ( V_34 ) ;
V_63:
return V_55 ;
}
static enum V_8 F_93 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_12 * V_38 )
{
struct V_47 * V_85 ;
struct V_1 * V_34 ;
V_85 = & V_2 -> V_56 . V_90 -> V_95 . V_85 [ 0 ] ;
if ( ! F_30 ( V_38 , V_2 , F_29 ( V_2 ) , V_85 ,
V_23 ) )
goto V_63;
F_10 ( V_17 , V_206 , F_33 ( V_38 ) ) ;
F_10 ( V_17 , V_28 ,
F_13 ( V_111 ) ) ;
F_14 ( V_9 , V_31 ) ;
F_10 ( V_17 , V_113 , F_16 () ) ;
V_34 = F_50 ( V_38 , V_2 ) ;
if ( ! V_34 )
goto V_63;
F_10 ( V_17 , V_66 , F_34 ( V_34 ) ) ;
F_10 ( V_17 , V_209 , F_94 ( V_105 ) ) ;
if ( V_13 -> V_102 . V_109 )
F_10 ( V_17 , V_210 , F_16 () ) ;
return V_54 ;
V_63:
return V_55 ;
}
static enum V_8 F_95 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_12 * V_38 )
{
return V_144 ;
}
static enum V_8 F_96 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_12 * V_38 )
{
struct V_18 * V_19 = NULL , * V_84 = NULL ;
struct V_1 * V_34 ;
if ( V_13 -> V_184 < V_111 ) {
F_10 ( V_17 , V_25 ,
F_12 ( V_80 ) ) ;
F_10 ( V_17 , V_28 ,
F_13 ( V_111 ) ) ;
F_14 ( V_9 , V_31 ) ;
F_10 ( V_17 , V_113 ,
F_16 () ) ;
V_19 = F_9 ( V_13 , 0 ,
V_105 , 0 ,
V_13 -> V_95 . V_106 ,
V_13 -> V_95 . V_107 ,
NULL , V_23 ) ;
if ( ! V_19 )
goto V_63;
if ( V_13 -> V_102 . V_109 ) {
V_84 = F_51 ( V_13 ,
V_23 ) ;
if ( ! V_84 )
goto V_63;
}
}
V_34 = F_50 ( V_38 , V_2 ) ;
if ( ! V_34 )
goto V_63;
F_10 ( V_17 , V_66 , F_34 ( V_34 ) ) ;
if ( V_19 )
F_10 ( V_17 , V_24 ,
F_11 ( V_19 ) ) ;
if ( V_84 )
F_10 ( V_17 , V_24 ,
F_11 ( V_84 ) ) ;
return V_54 ;
V_63:
if ( V_84 )
F_52 ( V_84 ) ;
if ( V_19 )
F_52 ( V_19 ) ;
return V_55 ;
}
enum V_8 F_97 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_12 * V_38 ;
struct V_1 * V_2 = V_15 ;
enum V_8 V_192 ;
struct V_1 * V_86 ;
int error = 0 ;
char V_211 ;
if ( ! F_1 ( V_2 , sizeof( struct V_21 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_2 -> V_56 . V_90 = (struct V_91 * ) V_2 -> V_59 -> V_60 ;
if ( ! F_44 ( V_2 -> V_59 , F_2 ( V_2 -> V_5 -> V_6 ) -
sizeof( struct V_21 ) ) )
goto V_63;
V_38 = F_45 ( V_11 , V_13 , V_2 , V_23 , & error ,
& V_86 ) ;
if ( ! V_38 ) {
switch ( error ) {
case - V_92 :
goto V_63;
case - V_93 :
F_46 ( V_9 , V_11 , V_13 , V_2 , V_17 ,
V_86 ) ;
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
case - V_94 :
default:
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
}
V_38 -> V_212 = 1 ;
V_211 = F_79 ( V_38 , V_13 ) ;
switch ( V_211 ) {
case 'A' :
V_192 = F_87 ( V_9 , V_11 , V_13 , V_2 , V_17 ,
V_38 ) ;
break;
case 'B' :
V_192 = F_93 ( V_9 , V_11 , V_13 , V_2 , V_17 ,
V_38 ) ;
break;
case 'C' :
V_192 = F_95 ( V_9 , V_11 , V_13 , V_2 , V_17 ,
V_38 ) ;
break;
case 'D' :
V_192 = F_96 ( V_9 , V_11 , V_13 , V_2 , V_17 ,
V_38 ) ;
break;
default:
V_192 = F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
break;
}
F_10 ( V_17 , V_213 , F_33 ( V_38 ) ) ;
F_10 ( V_17 , V_32 , F_16 () ) ;
F_10 ( V_17 , V_213 ,
F_33 ( (struct V_12 * ) V_13 ) ) ;
return V_192 ;
V_63:
return V_55 ;
}
enum V_8 F_98 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
if ( ! F_5 ( V_2 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_214 ) ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( V_215 ==
F_99 ( & V_13 -> V_48 . V_216 , & V_2 -> V_217 ) )
return F_86 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
return F_100 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
enum V_8 F_101 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
if ( ! F_5 ( V_2 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_214 ) ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( V_215 ==
F_99 ( & V_13 -> V_48 . V_216 , & V_2 -> V_217 ) )
return F_86 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
F_10 ( V_17 , V_25 ,
F_12 ( V_26 ) ) ;
F_10 ( V_17 , V_25 ,
F_12 ( V_27 ) ) ;
return F_100 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
enum V_8 F_102 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
return F_101 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
enum V_8 F_103 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
struct V_168 * V_197 ;
if ( ! F_37 ( V_2 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_218 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
F_104 (err, chunk->chunk_hdr) {
if ( V_219 == V_197 -> V_174 )
return F_105 ( V_9 , V_11 , V_13 , type ,
V_15 , V_17 ) ;
}
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
static enum V_8 F_105 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
int V_220 = V_13 -> V_221 + 1 ;
struct V_1 * V_2 = V_15 , * V_118 ;
struct V_222 V_223 ;
struct V_224 * V_225 ;
struct V_168 * V_197 ;
T_3 V_226 ;
if ( V_220 > V_13 -> V_227 ) {
F_10 ( V_17 , V_122 ,
F_58 ( V_123 ) ) ;
F_10 ( V_17 , V_228 ,
F_59 ( V_219 ) ) ;
return V_33 ;
}
V_197 = (struct V_168 * ) ( V_2 -> V_59 -> V_60 ) ;
V_226 = F_106 ( * ( V_229 * ) ( ( V_230 * ) V_197 + sizeof( * V_197 ) ) ) ;
V_226 = ( V_226 * 2 ) / 1000 ;
V_223 . V_61 . type = V_231 ;
V_223 . V_61 . V_6 = F_72 ( sizeof( V_223 ) ) ;
V_223 . V_232 = F_107 ( V_226 ) ;
V_225 = (struct V_224 * ) & V_13 -> V_48 . V_216 ;
V_118 = F_108 ( V_13 , V_225 , V_23 , sizeof( V_223 ) ) ;
if ( ! V_118 )
goto V_63;
F_32 ( V_118 , sizeof( V_223 ) , & V_223 ) ;
F_10 ( V_17 , V_233 , F_16 () ) ;
F_10 ( V_17 , V_200 , F_16 () ) ;
F_10 ( V_17 , V_234 , F_16 () ) ;
F_10 ( V_17 , V_235 , F_16 () ) ;
F_10 ( V_17 , V_236 ,
F_56 ( V_13 -> V_102 . V_237 ) ) ;
F_10 ( V_17 , V_238 , F_16 () ) ;
F_10 ( V_17 , V_25 ,
F_12 ( V_80 ) ) ;
F_10 ( V_17 , V_28 ,
F_13 ( V_185 ) ) ;
F_10 ( V_17 , V_79 ,
F_12 ( V_78 ) ) ;
F_10 ( V_17 , V_66 , F_34 ( V_118 ) ) ;
return V_54 ;
V_63:
return V_55 ;
}
enum V_8 F_109 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
if ( ! F_5 ( V_2 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_214 ) ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( V_215 ==
F_99 ( & V_13 -> V_48 . V_216 , & V_2 -> V_217 ) )
return F_86 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
return F_100 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
static enum V_8 F_100 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
T_4 error = V_125 ;
struct V_1 * V_2 = V_15 ;
unsigned int V_41 ;
V_41 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_41 >= sizeof( struct V_21 ) + sizeof( struct V_168 ) ) {
struct V_168 * V_197 ;
F_104 ( V_197 , V_2 -> V_5 ) ;
if ( ( void * ) V_197 != ( void * ) V_2 -> V_239 )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
error = ( (struct V_168 * ) V_2 -> V_59 -> V_60 ) -> V_174 ;
}
F_10 ( V_17 , V_122 , F_58 ( V_240 ) ) ;
F_10 ( V_17 , V_124 , F_59 ( error ) ) ;
F_14 ( V_9 , V_73 ) ;
F_15 ( V_9 , V_31 ) ;
return V_241 ;
}
enum V_8 F_110 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
T_4 error = V_125 ;
struct V_1 * V_2 = V_15 ;
unsigned int V_41 ;
if ( ! F_5 ( V_2 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_214 ) ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
V_41 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_41 >= sizeof( struct V_21 ) + sizeof( struct V_168 ) )
error = ( (struct V_168 * ) V_2 -> V_59 -> V_60 ) -> V_174 ;
return F_39 ( V_9 , V_17 , error , V_74 , V_13 ,
V_2 -> V_75 ) ;
}
enum V_8 F_111 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
return F_39 ( V_9 , V_17 , V_125 ,
V_242 , V_13 ,
(struct V_117 * ) V_15 ) ;
}
enum V_8 F_112 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
return F_110 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
static enum V_8 F_39 (
struct V_9 * V_9 ,
struct V_16 * V_17 ,
T_4 error , int V_243 ,
const struct V_12 * V_13 ,
struct V_117 * V_75 )
{
F_69 ( L_5 , V_149 ) ;
F_10 ( V_17 , V_28 ,
F_13 ( V_29 ) ) ;
F_14 ( V_9 , V_73 ) ;
F_10 ( V_17 , V_25 ,
F_12 ( V_78 ) ) ;
F_10 ( V_17 , V_122 , F_58 ( V_243 ) ) ;
F_10 ( V_17 , V_228 ,
F_59 ( error ) ) ;
return V_241 ;
}
enum V_8 F_113 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
enum V_8 V_196 ;
struct V_1 * V_2 = V_15 ;
struct V_244 * V_245 ;
struct V_18 * V_19 ;
T_5 V_246 ;
if ( ! F_37 ( V_2 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_247 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_245 = (struct V_244 * ) V_2 -> V_59 -> V_60 ;
F_25 ( V_2 -> V_59 , sizeof( * V_245 ) ) ;
V_2 -> V_56 . V_248 = V_245 ;
V_246 = F_106 ( V_245 -> V_249 ) ;
if ( F_114 ( V_246 , V_13 -> V_250 ) ) {
F_69 ( L_6 , V_149 , V_246 ,
V_13 -> V_250 ) ;
return V_144 ;
}
if ( ! F_114 ( V_246 , V_13 -> V_251 ) )
return F_115 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
V_19 = F_116 ( V_13 , 0 , V_23 ) ;
if ( ! V_19 ) {
V_196 = V_55 ;
goto V_176;
}
F_10 ( V_17 , V_24 , F_11 ( V_19 ) ) ;
F_10 ( V_17 , V_28 ,
F_13 ( V_252 ) ) ;
V_196 = V_54 ;
if ( F_117 ( & V_13 -> V_253 ) ) {
V_196 = F_118 ( V_9 , V_11 , V_13 , type ,
V_15 , V_17 ) ;
}
if ( V_55 == V_196 )
goto V_176;
F_10 ( V_17 , V_254 ,
F_119 ( V_2 -> V_56 . V_248 -> V_249 ) ) ;
V_176:
return V_196 ;
}
enum V_8 F_120 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
struct V_244 * V_245 ;
T_5 V_246 ;
if ( ! F_37 ( V_2 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_247 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_245 = (struct V_244 * ) V_2 -> V_59 -> V_60 ;
V_246 = F_106 ( V_245 -> V_249 ) ;
if ( F_114 ( V_246 , V_13 -> V_250 ) ) {
F_69 ( L_6 , V_149 , V_246 ,
V_13 -> V_250 ) ;
return V_144 ;
}
if ( ! F_114 ( V_246 , V_13 -> V_251 ) )
return F_115 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
F_10 ( V_17 , V_254 ,
F_119 ( V_245 -> V_249 ) ) ;
return V_54 ;
}
enum V_8 F_88 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
struct V_1 * V_118 ;
if ( ! F_1 ( V_2 , sizeof( struct V_21 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_118 = F_121 ( V_13 , V_2 ) ;
if ( NULL == V_118 )
goto V_63;
F_10 ( V_17 , V_255 , F_34 ( V_118 ) ) ;
F_10 ( V_17 , V_256 ,
F_12 ( V_26 ) ) ;
F_10 ( V_17 , V_66 , F_34 ( V_118 ) ) ;
return V_54 ;
V_63:
return V_55 ;
}
enum V_8 F_122 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
struct V_257 * V_258 ;
T_3 V_259 ;
if ( ! F_37 ( V_2 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_260 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_258 = (struct V_257 * ) V_2 -> V_59 -> V_60 ;
F_25 ( V_2 -> V_59 , sizeof( * V_258 ) ) ;
V_259 = F_106 ( V_258 -> V_259 ) ;
if ( F_123 ( V_13 -> V_261 , V_259 ) ) {
F_10 ( V_17 ,
V_262 ,
F_124 ( V_259 ) ) ;
}
return V_54 ;
}
enum V_8 F_125 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 , struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
struct V_263 * V_264 ;
if ( ! F_37 ( V_2 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_260 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_264 = (struct V_263 * ) V_2 -> V_59 -> V_60 ;
F_25 ( V_2 -> V_59 , sizeof( * V_264 ) ) ;
F_10 ( V_17 , V_265 ,
F_124 ( F_106 ( V_264 -> V_259 ) ) ) ;
return V_54 ;
}
enum V_8 F_126 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
union V_266 V_267 = F_127 () ;
struct V_1 * V_2 = V_15 ;
int error ;
if ( ! F_37 ( V_2 , V_13 ) ) {
F_10 ( V_17 , V_268 ,
F_16 () ) ;
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_269 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
error = F_128 ( V_13 , V_2 , V_17 ) ;
switch ( error ) {
case V_104 :
break;
case V_270 :
case V_271 :
F_14 ( V_9 , V_272 ) ;
goto V_273;
case V_274 :
case V_275 :
F_14 ( V_9 , V_272 ) ;
goto V_276;
case V_277 :
return V_241 ;
case V_278 :
return F_129 ( V_9 , V_11 , V_13 , V_2 , V_17 ,
( V_230 * ) V_2 -> V_56 . V_279 ,
sizeof( struct V_280 ) ) ;
default:
F_130 () ;
}
if ( V_2 -> V_5 -> V_281 & V_282 )
V_267 = F_131 () ;
if ( V_13 -> V_114 [ V_115 ] ) {
F_10 ( V_17 , V_256 ,
F_12 ( V_115 ) ) ;
}
if ( V_2 -> V_283 )
F_10 ( V_17 , V_284 , V_267 ) ;
return V_54 ;
V_276:
if ( V_2 -> V_283 )
F_10 ( V_17 , V_284 , F_131 () ) ;
return V_144 ;
V_273:
if ( V_2 -> V_283 )
F_10 ( V_17 , V_284 , V_267 ) ;
return V_144 ;
}
enum V_8 F_132 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
int error ;
if ( ! F_37 ( V_2 , V_13 ) ) {
F_10 ( V_17 , V_268 ,
F_16 () ) ;
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_269 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
error = F_128 ( V_13 , V_2 , V_17 ) ;
switch ( error ) {
case V_104 :
case V_270 :
case V_274 :
case V_275 :
case V_271 :
break;
case V_277 :
return V_241 ;
case V_278 :
return F_129 ( V_9 , V_11 , V_13 , V_2 , V_17 ,
( V_230 * ) V_2 -> V_56 . V_279 ,
sizeof( struct V_280 ) ) ;
default:
F_130 () ;
}
if ( V_2 -> V_283 ) {
F_10 ( V_17 , V_285 , F_16 () ) ;
F_10 ( V_17 , V_284 , F_131 () ) ;
F_10 ( V_17 , V_256 ,
F_12 ( V_26 ) ) ;
}
return V_54 ;
}
enum V_8 F_133 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
struct V_286 * V_287 ;
T_5 V_246 ;
if ( ! F_37 ( V_2 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_288 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_287 = F_134 ( V_2 ) ;
if ( ! V_287 )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
V_2 -> V_56 . V_289 = V_287 ;
V_246 = F_106 ( V_287 -> V_249 ) ;
if ( F_114 ( V_246 , V_13 -> V_250 ) ) {
F_69 ( L_6 , V_149 , V_246 ,
V_13 -> V_250 ) ;
return V_144 ;
}
if ( ! F_114 ( V_246 , V_13 -> V_251 ) )
return F_115 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
F_10 ( V_17 , V_290 , F_34 ( V_2 ) ) ;
return V_54 ;
}
static enum V_8 F_19 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_39 * V_40 = NULL ;
struct V_1 * V_2 = V_15 ;
struct V_1 * abort ;
V_40 = F_135 ( V_9 , V_13 , V_2 ) ;
if ( ! V_40 )
return V_55 ;
abort = F_136 ( V_13 , V_2 , 0 ) ;
if ( ! abort ) {
F_137 ( V_40 ) ;
return V_55 ;
}
if ( F_138 ( abort ) )
V_40 -> V_46 = F_106 ( V_2 -> V_45 -> V_46 ) ;
abort -> V_59 -> V_49 = V_11 -> V_48 . V_49 ;
F_139 ( V_40 , abort ) ;
F_10 ( V_17 , V_52 ,
F_24 ( V_40 ) ) ;
F_14 ( V_9 , V_53 ) ;
F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
return V_54 ;
}
enum V_8 F_140 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
struct V_168 * V_197 ;
if ( ! F_37 ( V_2 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_218 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
F_104 ( V_197 , V_2 -> V_5 ) ;
if ( ( void * ) V_197 != ( void * ) V_2 -> V_239 )
return F_63 ( V_9 , V_11 , V_13 , type , V_15 ,
( void * ) V_197 , V_17 ) ;
F_10 ( V_17 , V_291 ,
F_34 ( V_2 ) ) ;
return V_54 ;
}
enum V_8 F_141 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
struct V_1 * V_118 ;
struct V_18 * V_19 ;
if ( ! F_37 ( V_2 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_21 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_19 = F_9 ( V_13 , 0 , V_22 ,
0 , 0 , 0 , NULL , V_23 ) ;
if ( ! V_19 )
goto V_63;
V_118 = F_142 ( V_13 , V_2 ) ;
if ( ! V_118 )
goto V_292;
F_10 ( V_17 , V_24 , F_11 ( V_19 ) ) ;
F_10 ( V_17 , V_25 ,
F_12 ( V_26 ) ) ;
F_10 ( V_17 , V_25 ,
F_12 ( V_27 ) ) ;
F_10 ( V_17 , V_28 ,
F_13 ( V_29 ) ) ;
F_14 ( V_9 , V_30 ) ;
F_15 ( V_9 , V_31 ) ;
F_10 ( V_17 , V_66 , F_34 ( V_118 ) ) ;
F_10 ( V_17 , V_32 , F_16 () ) ;
return V_33 ;
V_292:
F_52 ( V_19 ) ;
V_63:
return V_55 ;
}
enum V_8 F_85 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 , struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
struct V_293 * V_59 = V_2 -> V_59 ;
struct V_21 * V_294 ;
struct V_168 * V_197 ;
int V_295 = 0 ;
int V_296 = 0 ;
V_51 * V_297 ;
F_14 ( V_9 , V_44 ) ;
V_294 = (struct V_21 * ) V_2 -> V_5 ;
do {
if ( F_2 ( V_294 -> V_6 ) < sizeof( * V_294 ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_297 = ( ( V_51 * ) V_294 ) + F_143 ( F_2 ( V_294 -> V_6 ) ) ;
if ( V_297 > F_144 ( V_59 ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
if ( V_298 == V_294 -> type )
V_296 = 1 ;
if ( V_72 == V_294 -> type )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( V_299 == V_294 -> type )
V_295 = 1 ;
if ( V_300 == V_294 -> type ) {
F_104 (err, ch) {
if ( V_219 == V_197 -> V_174 ) {
V_295 = 1 ;
break;
}
}
}
V_294 = (struct V_21 * ) V_297 ;
} while ( V_297 < F_144 ( V_59 ) );
if ( V_296 )
return F_145 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
else if ( V_295 )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
else
return F_19 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
static enum V_8 F_145 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_39 * V_40 = NULL ;
struct V_1 * V_2 = V_15 ;
struct V_1 * V_301 ;
V_40 = F_135 ( V_9 , V_13 , V_2 ) ;
if ( ! V_40 )
return V_55 ;
V_301 = F_142 ( V_13 , V_2 ) ;
if ( ! V_301 ) {
F_137 ( V_40 ) ;
return V_55 ;
}
if ( F_138 ( V_301 ) )
V_40 -> V_46 = F_106 ( V_2 -> V_45 -> V_46 ) ;
V_301 -> V_59 -> V_49 = V_11 -> V_48 . V_49 ;
F_139 ( V_40 , V_301 ) ;
F_10 ( V_17 , V_52 ,
F_24 ( V_40 ) ) ;
F_14 ( V_9 , V_53 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_21 ) ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
enum V_8 F_146 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
if ( ! F_1 ( V_2 , sizeof( struct V_21 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
F_14 ( V_9 , V_44 ) ;
return F_145 ( V_9 , V_11 , NULL , type , V_15 , V_17 ) ;
}
enum V_8 F_147 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_133 * V_302 = NULL ;
struct V_1 * V_303 = NULL ;
struct V_1 * V_2 = V_15 ;
struct V_304 * V_305 ;
T_5 V_306 ;
if ( ! F_37 ( V_2 , V_13 ) ) {
F_10 ( V_17 , V_268 ,
F_16 () ) ;
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
if ( ! V_9 -> V_42 . V_307 && ! V_2 -> V_98 )
return F_86 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_308 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_305 = (struct V_304 * ) V_2 -> V_59 -> V_60 ;
V_306 = F_106 ( V_305 -> V_306 ) ;
if ( ! F_148 ( V_13 , V_2 , true , & V_302 ) )
return F_63 ( V_9 , V_11 , V_13 , type , V_15 ,
( void * ) V_302 , V_17 ) ;
if ( V_306 == V_13 -> V_102 . V_309 + 1 ) {
if ( ! V_2 -> V_310 )
F_149 ( V_13 ) ;
V_303 = F_150 ( (struct V_12 * )
V_13 , V_2 ) ;
if ( ! V_303 )
return V_55 ;
} else if ( V_306 < V_13 -> V_102 . V_309 + 1 ) {
V_303 = F_151 ( V_13 , V_305 -> V_306 ) ;
if ( ! V_303 )
return V_144 ;
V_303 -> V_75 = NULL ;
} else {
return V_144 ;
}
V_303 -> V_217 = V_2 -> V_311 ;
F_10 ( V_17 , V_66 , F_34 ( V_303 ) ) ;
if ( V_13 -> V_312 ) {
F_54 ( V_11 , V_13 , type , V_13 -> V_312 , V_17 ) ;
( (struct V_12 * ) V_13 ) -> V_312 = NULL ;
}
return V_54 ;
}
enum V_8 F_152 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_313 = V_13 -> V_314 ;
struct V_133 * V_302 = NULL ;
struct V_1 * V_303 = V_15 ;
struct V_304 * V_315 ;
T_5 V_316 , V_317 ;
struct V_1 * abort ;
if ( ! F_37 ( V_303 , V_13 ) ) {
F_10 ( V_17 , V_268 ,
F_16 () ) ;
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
if ( ! V_9 -> V_42 . V_307 && ! V_303 -> V_98 )
return F_86 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
if ( ! F_1 ( V_303 ,
sizeof( struct V_308 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_315 = (struct V_304 * ) V_303 -> V_59 -> V_60 ;
V_317 = F_106 ( V_315 -> V_306 ) ;
if ( ! F_148 ( V_13 , V_303 , false , & V_302 ) )
return F_63 ( V_9 , V_11 , V_13 , type , V_15 ,
( void * ) V_302 , V_17 ) ;
if ( V_313 ) {
V_315 = (struct V_304 * ) V_313 -> V_56 . V_315 ;
V_316 = F_106 ( V_315 -> V_306 ) ;
} else {
V_316 = V_13 -> V_309 - 1 ;
}
if ( F_153 ( V_317 , V_316 + 1 ) &&
! ( V_13 -> V_314 ) ) {
abort = F_136 ( V_13 , V_303 ,
sizeof( struct V_168 ) ) ;
if ( abort ) {
F_154 ( abort , V_318 , 0 ) ;
F_10 ( V_17 , V_66 ,
F_34 ( abort ) ) ;
}
F_10 ( V_17 , V_25 ,
F_12 ( V_203 ) ) ;
F_10 ( V_17 , V_177 , F_16 () ) ;
F_10 ( V_17 , V_122 ,
F_58 ( V_319 ) ) ;
F_10 ( V_17 , V_124 ,
F_59 ( V_318 ) ) ;
F_14 ( V_9 , V_73 ) ;
F_15 ( V_9 , V_31 ) ;
return V_241 ;
}
if ( ( V_317 == V_316 ) && V_13 -> V_314 ) {
F_10 ( V_17 , V_25 ,
F_12 ( V_203 ) ) ;
if ( ! F_155 ( (struct V_12 * ) V_13 ,
V_303 ) ) {
F_10 ( V_17 , V_320 ,
F_16 () ) ;
return V_54 ;
}
abort = F_136 ( V_13 , V_303 ,
sizeof( struct V_168 ) ) ;
if ( abort ) {
F_154 ( abort , V_321 , 0 ) ;
F_10 ( V_17 , V_66 ,
F_34 ( abort ) ) ;
}
F_10 ( V_17 , V_177 , F_16 () ) ;
F_10 ( V_17 , V_122 ,
F_58 ( V_319 ) ) ;
F_10 ( V_17 , V_124 ,
F_59 ( V_318 ) ) ;
F_14 ( V_9 , V_73 ) ;
F_15 ( V_9 , V_31 ) ;
return V_241 ;
}
return V_144 ;
}
enum V_8 F_156 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_133 * V_302 = NULL ;
struct V_1 * V_2 = V_15 ;
struct V_322 * V_305 ;
union V_323 V_324 ;
if ( ! F_37 ( V_2 , V_13 ) ) {
F_10 ( V_17 , V_268 ,
F_16 () ) ;
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
if ( ! F_1 ( V_2 , sizeof( * V_305 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
if ( ! F_157 ( V_13 , V_2 , & V_302 ) )
return F_63 ( V_9 , V_11 , V_13 , type , V_15 ,
( void * ) V_302 , V_17 ) ;
V_305 = (struct V_322 * ) V_2 -> V_5 ;
F_158 (param, hdr, params) {
struct V_1 * V_118 = NULL ;
struct V_18 * V_19 = NULL ;
if ( V_324 . V_325 -> type == V_326 )
V_118 = F_159 (
(struct V_12 * ) V_13 , V_324 , & V_19 ) ;
else if ( V_324 . V_325 -> type == V_327 )
V_118 = F_160 (
(struct V_12 * ) V_13 , V_324 , & V_19 ) ;
else if ( V_324 . V_325 -> type == V_328 )
V_118 = F_161 (
(struct V_12 * ) V_13 , V_324 , & V_19 ) ;
else if ( V_324 . V_325 -> type == V_329 )
V_118 = F_162 (
(struct V_12 * ) V_13 , V_324 , & V_19 ) ;
else if ( V_324 . V_325 -> type == V_330 )
V_118 = F_163 (
(struct V_12 * ) V_13 , V_324 , & V_19 ) ;
else if ( V_324 . V_325 -> type == V_331 )
V_118 = F_164 (
(struct V_12 * ) V_13 , V_324 , & V_19 ) ;
if ( V_19 )
F_10 ( V_17 , V_24 ,
F_11 ( V_19 ) ) ;
if ( V_118 )
F_10 ( V_17 , V_66 ,
F_34 ( V_118 ) ) ;
}
return V_54 ;
}
enum V_8 F_165 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_332 * V_333 ;
struct V_1 * V_2 = V_15 ;
struct V_334 * V_335 ;
T_1 V_41 ;
T_5 V_336 ;
if ( ! F_37 ( V_2 , V_13 ) ) {
F_10 ( V_17 , V_268 ,
F_16 () ) ;
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
if ( ! V_13 -> V_102 . V_337 )
return F_166 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_338 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_333 = (struct V_332 * ) V_2 -> V_59 -> V_60 ;
V_2 -> V_56 . V_333 = V_333 ;
V_41 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_41 -= sizeof( struct V_21 ) ;
F_25 ( V_2 -> V_59 , V_41 ) ;
V_336 = F_106 ( V_333 -> V_339 ) ;
F_69 ( L_7 , V_149 , V_336 ) ;
if ( F_167 ( & V_13 -> V_102 . V_340 , V_336 ) < 0 )
goto V_273;
F_168 (skip, chunk) {
if ( F_2 ( V_335 -> V_341 ) >= V_13 -> V_341 . V_342 )
goto V_273;
}
F_10 ( V_17 , V_343 , F_124 ( V_336 ) ) ;
if ( V_41 > sizeof( struct V_332 ) )
F_10 ( V_17 , V_344 ,
F_34 ( V_2 ) ) ;
if ( V_13 -> V_114 [ V_115 ] ) {
F_10 ( V_17 , V_256 ,
F_12 ( V_115 ) ) ;
}
F_10 ( V_17 , V_284 , F_127 () ) ;
return V_54 ;
V_273:
return V_144 ;
}
enum V_8 F_169 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_332 * V_333 ;
struct V_1 * V_2 = V_15 ;
struct V_334 * V_335 ;
T_1 V_41 ;
T_5 V_336 ;
if ( ! F_37 ( V_2 , V_13 ) ) {
F_10 ( V_17 , V_268 ,
F_16 () ) ;
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
if ( ! V_13 -> V_102 . V_337 )
return F_166 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_338 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_333 = (struct V_332 * ) V_2 -> V_59 -> V_60 ;
V_2 -> V_56 . V_333 = V_333 ;
V_41 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_41 -= sizeof( struct V_21 ) ;
F_25 ( V_2 -> V_59 , V_41 ) ;
V_336 = F_106 ( V_333 -> V_339 ) ;
F_69 ( L_7 , V_149 , V_336 ) ;
if ( F_167 ( & V_13 -> V_102 . V_340 , V_336 ) < 0 )
goto V_345;
F_168 (skip, chunk) {
if ( F_2 ( V_335 -> V_341 ) >= V_13 -> V_341 . V_342 )
goto V_345;
}
F_10 ( V_17 , V_343 , F_124 ( V_336 ) ) ;
if ( V_41 > sizeof( struct V_332 ) )
F_10 ( V_17 , V_344 ,
F_34 ( V_2 ) ) ;
V_345:
F_10 ( V_17 , V_285 , F_16 () ) ;
F_10 ( V_17 , V_284 , F_131 () ) ;
F_10 ( V_17 , V_256 ,
F_12 ( V_26 ) ) ;
return V_54 ;
}
static enum V_99 F_49 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
struct V_1 * V_2 )
{
struct V_346 * V_347 ;
V_51 * V_348 , * V_349 ;
struct V_350 * V_351 ;
unsigned int V_352 ;
T_1 V_353 ;
V_347 = (struct V_346 * ) V_2 -> V_59 -> V_60 ;
V_2 -> V_56 . V_347 = V_347 ;
F_25 ( V_2 -> V_59 , sizeof( * V_347 ) ) ;
if ( ! F_170 ( V_13 , V_347 -> V_354 ) )
return V_355 ;
V_353 = F_2 ( V_347 -> V_356 ) ;
if ( V_353 != V_13 -> V_357 && ! F_171 ( V_13 , V_353 ) )
return V_358 ;
V_352 = F_2 ( V_2 -> V_5 -> V_6 ) -
sizeof( struct V_359 ) ;
V_351 = F_172 ( F_2 ( V_347 -> V_354 ) ) ;
if ( V_352 != V_351 -> V_360 )
return V_278 ;
V_349 = V_347 -> V_351 ;
F_25 ( V_2 -> V_59 , V_352 ) ;
V_348 = F_173 ( V_349 , V_352 , V_23 ) ;
if ( ! V_348 )
goto V_63;
memset ( V_349 , 0 , V_352 ) ;
F_174 ( V_13 , V_2 -> V_59 ,
(struct V_359 * ) V_2 -> V_5 ,
V_23 ) ;
if ( memcmp ( V_348 , V_349 , V_352 ) ) {
F_175 ( V_348 ) ;
return V_94 ;
}
F_175 ( V_348 ) ;
V_2 -> V_98 = 1 ;
return V_104 ;
V_63:
return V_92 ;
}
enum V_8 F_176 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 , struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
struct V_346 * V_347 ;
struct V_1 * V_35 ;
enum V_99 error ;
if ( ! V_13 -> V_102 . V_103 )
return F_166 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_37 ( V_2 , V_13 ) ) {
F_10 ( V_17 , V_268 ,
F_16 () ) ;
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_359 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
V_347 = (struct V_346 * ) V_2 -> V_59 -> V_60 ;
error = F_49 ( V_9 , V_11 , V_13 , type , V_2 ) ;
switch ( error ) {
case V_355 :
V_35 = F_90 ( V_13 , V_2 ,
V_361 ,
& V_347 -> V_354 ,
sizeof( T_1 ) , 0 ) ;
if ( V_35 ) {
F_10 ( V_17 , V_66 ,
F_34 ( V_35 ) ) ;
}
case V_358 :
case V_94 :
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
case V_278 :
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
case V_92 :
return V_55 ;
default:
break;
}
if ( V_13 -> V_357 != F_2 ( V_347 -> V_356 ) ) {
struct V_18 * V_19 ;
V_19 = F_177 ( V_13 , F_2 ( V_347 -> V_356 ) ,
V_362 , V_23 ) ;
if ( ! V_19 )
return - V_363 ;
F_10 ( V_17 , V_24 ,
F_11 ( V_19 ) ) ;
}
return V_54 ;
}
enum V_8 F_166 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_364 = V_15 ;
struct V_1 * V_35 ;
struct V_21 * V_305 ;
F_69 ( L_8 , V_149 , type . V_2 ) ;
if ( ! F_37 ( V_364 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
if ( ! F_1 ( V_364 , sizeof( * V_305 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
switch ( type . V_2 & V_365 ) {
case V_366 :
return F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
case V_367 :
V_305 = V_364 -> V_5 ;
V_35 = F_90 ( V_13 , V_364 ,
V_368 , V_305 ,
F_143 ( F_2 ( V_305 -> V_6 ) ) ,
0 ) ;
if ( V_35 ) {
F_10 ( V_17 , V_66 ,
F_34 ( V_35 ) ) ;
}
F_6 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
return V_54 ;
case V_369 :
return V_144 ;
case V_370 :
V_305 = V_364 -> V_5 ;
V_35 = F_90 ( V_13 , V_364 ,
V_368 , V_305 ,
F_143 ( F_2 ( V_305 -> V_6 ) ) ,
0 ) ;
if ( V_35 ) {
F_10 ( V_17 , V_66 ,
F_34 ( V_35 ) ) ;
}
return V_54 ;
default:
break;
}
return V_144 ;
}
enum V_8 F_86 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
if ( ! F_1 ( V_2 , sizeof( struct V_21 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
F_69 ( L_9 , V_149 , type . V_2 ) ;
return V_144 ;
}
enum V_8 F_6 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 , struct V_16 * V_17 )
{
F_14 ( V_9 , V_371 ) ;
F_10 ( V_17 , V_177 , F_16 () ) ;
return V_54 ;
}
enum V_8 F_178 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
if ( ! F_1 ( V_2 , sizeof( struct V_21 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
return V_372 ;
}
static enum V_8 F_129 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
void * V_15 ,
struct V_16 * V_17 ,
const V_51 * V_373 ,
const T_2 V_134 )
{
struct V_39 * V_40 = NULL ;
struct V_1 * V_2 = V_15 ;
struct V_1 * abort = NULL ;
if ( F_38 ( V_72 , V_13 ) )
goto V_374;
abort = F_179 ( V_13 , V_2 , V_373 , V_134 ) ;
if ( ! abort )
goto V_63;
if ( V_13 ) {
if ( V_2 -> V_5 -> type == V_375 &&
! V_13 -> V_102 . V_376 . V_377 ) {
struct V_68 * V_378 ;
V_378 = (struct V_68 * ) V_2 -> V_5 ;
if ( ! F_1 ( V_2 , sizeof( * V_378 ) ) )
abort -> V_5 -> V_281 |= V_379 ;
else {
unsigned int V_380 ;
V_380 = F_106 ( V_378 -> V_57 . V_377 ) ;
F_10 ( V_17 , V_381 ,
F_124 ( V_380 ) ) ;
}
}
F_10 ( V_17 , V_66 , F_34 ( abort ) ) ;
F_14 ( V_9 , V_53 ) ;
if ( V_13 -> V_184 <= V_81 ) {
F_10 ( V_17 , V_25 ,
F_12 ( V_78 ) ) ;
F_10 ( V_17 , V_122 ,
F_58 ( V_74 ) ) ;
F_10 ( V_17 , V_228 ,
F_59 ( V_382 ) ) ;
} else {
F_10 ( V_17 , V_122 ,
F_58 ( V_319 ) ) ;
F_10 ( V_17 , V_124 ,
F_59 ( V_382 ) ) ;
F_15 ( V_9 , V_31 ) ;
}
} else {
V_40 = F_135 ( V_9 , V_13 , V_2 ) ;
if ( ! V_40 )
goto V_383;
if ( F_138 ( abort ) )
V_40 -> V_46 = F_106 ( V_2 -> V_45 -> V_46 ) ;
abort -> V_59 -> V_49 = V_11 -> V_48 . V_49 ;
F_139 ( V_40 , abort ) ;
F_10 ( V_17 , V_52 ,
F_24 ( V_40 ) ) ;
F_14 ( V_9 , V_53 ) ;
}
F_14 ( V_9 , V_73 ) ;
V_374:
F_6 ( V_9 , V_11 , V_13 , F_89 ( 0 ) , V_15 , V_17 ) ;
return V_241 ;
V_383:
F_23 ( abort ) ;
V_63:
return V_55 ;
}
static enum V_8 F_8 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
static const char V_384 [] = L_10 ;
return F_129 ( V_9 , V_11 , V_13 , V_15 , V_17 , V_384 ,
sizeof( V_384 ) ) ;
}
static enum V_8 F_63 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 , void * V_385 ,
struct V_16 * V_17 )
{
struct V_133 * V_324 = V_385 ;
struct V_1 * abort = NULL ;
struct V_1 * V_2 = V_15 ;
if ( F_38 ( V_72 , V_13 ) )
goto V_374;
abort = F_180 ( V_13 , V_2 , V_324 ) ;
if ( ! abort )
goto V_63;
F_10 ( V_17 , V_66 , F_34 ( abort ) ) ;
F_14 ( V_9 , V_53 ) ;
F_10 ( V_17 , V_122 ,
F_58 ( V_319 ) ) ;
F_10 ( V_17 , V_124 ,
F_59 ( V_382 ) ) ;
F_15 ( V_9 , V_31 ) ;
F_14 ( V_9 , V_73 ) ;
V_374:
F_6 ( V_9 , V_11 , V_13 , F_89 ( 0 ) , V_15 , V_17 ) ;
return V_241 ;
V_63:
return V_55 ;
}
static enum V_8 F_115 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
static const char V_384 [] = L_11 ;
return F_129 ( V_9 , V_11 , V_13 , V_15 , V_17 , V_384 ,
sizeof( V_384 ) ) ;
}
static enum V_8 F_7 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
static const char V_384 [] = L_12 ;
if ( ! V_13 )
return F_178 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
return F_129 ( V_9 , V_11 , V_13 , V_15 , V_17 , V_384 ,
sizeof( V_384 ) ) ;
}
enum V_8 F_181 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_12 * V_386 ;
struct V_1 * V_34 ;
F_10 ( V_17 , V_28 ,
F_13 ( V_185 ) ) ;
V_34 = F_108 ( V_13 , & V_13 -> V_48 . V_216 , V_23 , 0 ) ;
if ( ! V_34 )
goto V_63;
F_10 ( V_17 , V_387 ,
F_34 ( V_34 ) ) ;
V_386 = (struct V_12 * ) V_13 ;
F_10 ( V_17 , V_65 , F_33 ( V_386 ) ) ;
F_10 ( V_17 , V_79 ,
F_12 ( V_78 ) ) ;
F_10 ( V_17 , V_66 , F_34 ( V_34 ) ) ;
return V_54 ;
V_63:
return V_55 ;
}
enum V_8 F_182 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_388 * V_389 = V_15 ;
F_10 ( V_17 , V_390 , F_183 ( V_389 ) ) ;
return V_54 ;
}
enum V_8 F_184 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
enum V_8 V_196 ;
F_10 ( V_17 , V_28 ,
F_13 ( V_391 ) ) ;
V_196 = V_54 ;
if ( F_117 ( & V_13 -> V_253 ) ) {
V_196 = F_92 ( V_9 , V_11 , V_13 , type ,
V_15 , V_17 ) ;
}
return V_196 ;
}
enum V_8 F_185 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * abort = V_15 ;
if ( abort )
F_10 ( V_17 , V_66 , F_34 ( abort ) ) ;
F_10 ( V_17 , V_122 ,
F_58 ( V_319 ) ) ;
F_10 ( V_17 , V_124 ,
F_59 ( V_392 ) ) ;
F_14 ( V_9 , V_73 ) ;
F_15 ( V_9 , V_31 ) ;
return V_241 ;
}
enum V_8 F_186 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
F_10 ( V_17 , V_393 , F_58 ( - V_394 ) ) ;
return V_54 ;
}
enum V_8 F_187 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
F_10 ( V_17 , V_393 ,
F_58 ( - V_395 ) ) ;
return V_54 ;
}
enum V_8 F_188 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
F_10 ( V_17 , V_25 ,
F_12 ( V_78 ) ) ;
F_10 ( V_17 , V_28 ,
F_13 ( V_29 ) ) ;
F_14 ( V_9 , V_30 ) ;
F_10 ( V_17 , V_32 , F_16 () ) ;
return V_33 ;
}
enum V_8 F_189 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
return F_188 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
enum V_8 F_190 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * abort = V_15 ;
F_10 ( V_17 , V_25 ,
F_12 ( V_78 ) ) ;
if ( abort )
F_10 ( V_17 , V_66 , F_34 ( abort ) ) ;
F_10 ( V_17 , V_28 ,
F_13 ( V_29 ) ) ;
F_14 ( V_9 , V_73 ) ;
F_10 ( V_17 , V_122 ,
F_58 ( V_74 ) ) ;
F_10 ( V_17 , V_228 ,
F_59 ( V_392 ) ) ;
return V_241 ;
}
enum V_8 F_191 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
return F_190 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
enum V_8 F_192 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
F_10 ( V_17 , V_25 ,
F_12 ( V_27 ) ) ;
return F_185 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
enum V_8 F_193 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
F_10 ( V_17 , V_25 ,
F_12 ( V_26 ) ) ;
F_10 ( V_17 , V_25 ,
F_12 ( V_27 ) ) ;
return F_185 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
enum V_8 F_194 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
return F_193 ( V_9 , V_11 , V_13 , type , V_15 , V_17 ) ;
}
enum V_8 F_195 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
if ( V_55 == F_54 ( V_11 , V_13 , type ,
(struct V_117 * ) V_15 , V_17 ) )
return V_55 ;
F_10 ( V_17 , V_128 ,
F_56 ( V_15 ) ) ;
return V_54 ;
}
enum V_8 F_196 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
F_10 ( V_17 , V_396 , F_34 ( V_2 ) ) ;
F_10 ( V_17 , V_79 ,
F_12 ( V_203 ) ) ;
F_10 ( V_17 , V_66 , F_34 ( V_2 ) ) ;
return V_54 ;
}
enum V_8 F_197 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
F_10 ( V_17 , V_66 , F_34 ( V_2 ) ) ;
return V_54 ;
}
enum V_8 F_198 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
F_69 ( L_13 , V_149 ,
type . V_397 ) ;
return V_144 ;
}
enum V_8 F_199 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_18 * V_398 ;
V_398 = F_200 ( V_13 , V_23 ) ;
if ( ! V_398 )
return V_55 ;
F_10 ( V_17 , V_24 , F_11 ( V_398 ) ) ;
return V_54 ;
}
enum V_8 F_92 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_118 ;
V_118 = F_201 ( V_13 , NULL ) ;
if ( ! V_118 )
goto V_63;
F_10 ( V_17 , V_255 , F_34 ( V_118 ) ) ;
F_10 ( V_17 , V_79 ,
F_12 ( V_26 ) ) ;
F_10 ( V_17 , V_256 ,
F_12 ( V_27 ) ) ;
if ( V_13 -> V_114 [ V_115 ] )
F_10 ( V_17 , V_25 ,
F_12 ( V_115 ) ) ;
F_10 ( V_17 , V_28 ,
F_13 ( V_399 ) ) ;
F_10 ( V_17 , V_234 , F_16 () ) ;
F_10 ( V_17 , V_66 , F_34 ( V_118 ) ) ;
return V_54 ;
V_63:
return V_55 ;
}
enum V_8 F_118 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 ;
struct V_1 * V_118 ;
if ( V_2 ) {
if ( ! F_37 ( V_2 , V_13 ) )
return F_6 ( V_9 , V_11 , V_13 , type , V_15 ,
V_17 ) ;
if ( ! F_1 (
V_2 , sizeof( struct V_247 ) ) )
return F_8 ( V_9 , V_11 , V_13 , type ,
V_15 , V_17 ) ;
}
V_118 = F_121 ( V_13 , V_2 ) ;
if ( ! V_118 )
goto V_63;
F_10 ( V_17 , V_255 , F_34 ( V_118 ) ) ;
F_10 ( V_17 , V_256 ,
F_12 ( V_26 ) ) ;
if ( V_13 -> V_114 [ V_115 ] )
F_10 ( V_17 , V_25 ,
F_12 ( V_115 ) ) ;
F_10 ( V_17 , V_28 ,
F_13 ( V_400 ) ) ;
F_10 ( V_17 , V_234 , F_16 () ) ;
F_10 ( V_17 , V_66 , F_34 ( V_118 ) ) ;
return V_54 ;
V_63:
return V_55 ;
}
enum V_8 F_202 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
F_69 ( L_14 ,
V_149 , type . V_401 ) ;
return V_144 ;
}
enum V_8 F_203 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_117 * V_75 = V_15 ;
F_14 ( V_9 , V_402 ) ;
if ( V_13 -> V_120 >= V_13 -> V_121 ) {
if ( V_13 -> V_102 . V_403 &&
V_13 -> V_184 == V_391 ) {
F_10 ( V_17 , V_404 ,
F_12 ( V_27 ) ) ;
} else {
F_10 ( V_17 , V_122 ,
F_58 ( V_123 ) ) ;
F_10 ( V_17 , V_124 ,
F_59 ( V_125 ) ) ;
F_14 ( V_9 , V_73 ) ;
F_15 ( V_9 , V_31 ) ;
return V_33 ;
}
}
F_10 ( V_17 , V_132 , F_56 ( V_75 ) ) ;
F_10 ( V_17 , V_405 , F_56 ( V_75 ) ) ;
return V_54 ;
}
enum V_8 F_204 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
F_14 ( V_9 , V_406 ) ;
F_10 ( V_17 , V_284 , F_131 () ) ;
return V_54 ;
}
enum V_8 F_205 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
int V_220 = V_13 -> V_221 + 1 ;
struct V_1 * V_34 = NULL ;
struct V_224 * V_225 ;
F_69 ( L_15 , V_149 ) ;
F_14 ( V_9 , V_407 ) ;
if ( V_220 <= V_13 -> V_227 ) {
V_225 = (struct V_224 * ) & V_13 -> V_48 . V_216 ;
V_34 = F_108 ( V_13 , V_225 , V_23 , 0 ) ;
if ( ! V_34 )
return V_55 ;
F_10 ( V_17 , V_387 ,
F_34 ( V_34 ) ) ;
F_10 ( V_17 , V_408 ,
F_12 ( V_78 ) ) ;
F_10 ( V_17 , V_66 , F_34 ( V_34 ) ) ;
} else {
F_69 ( L_16
L_17 , V_149 , V_220 ,
V_13 -> V_227 ) ;
F_10 ( V_17 , V_122 ,
F_58 ( V_123 ) ) ;
F_10 ( V_17 , V_228 ,
F_59 ( V_125 ) ) ;
return V_33 ;
}
return V_54 ;
}
enum V_8 F_206 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
int V_220 = V_13 -> V_221 + 1 ;
struct V_1 * V_34 = NULL ;
F_69 ( L_18 , V_149 ) ;
F_14 ( V_9 , V_409 ) ;
if ( V_220 <= V_13 -> V_227 ) {
V_34 = F_207 ( V_13 , NULL ) ;
if ( ! V_34 )
return V_55 ;
F_10 ( V_17 , V_387 ,
F_34 ( V_34 ) ) ;
F_10 ( V_17 , V_410 ,
F_12 ( V_80 ) ) ;
F_10 ( V_17 , V_66 , F_34 ( V_34 ) ) ;
} else {
F_10 ( V_17 , V_122 ,
F_58 ( V_123 ) ) ;
F_10 ( V_17 , V_228 ,
F_59 ( V_125 ) ) ;
return V_33 ;
}
return V_54 ;
}
enum V_8 F_208 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_118 = NULL ;
F_69 ( L_19 , V_149 ) ;
F_14 ( V_9 , V_411 ) ;
( (struct V_12 * ) V_13 ) -> V_412 ++ ;
if ( V_13 -> V_120 >= V_13 -> V_121 ) {
F_10 ( V_17 , V_122 ,
F_58 ( V_123 ) ) ;
F_10 ( V_17 , V_124 ,
F_59 ( V_125 ) ) ;
F_14 ( V_9 , V_73 ) ;
F_15 ( V_9 , V_31 ) ;
return V_33 ;
}
switch ( V_13 -> V_184 ) {
case V_399 :
V_118 = F_201 ( V_13 , NULL ) ;
break;
case V_400 :
V_118 = F_121 ( V_13 , NULL ) ;
break;
default:
F_130 () ;
break;
}
if ( ! V_118 )
goto V_63;
if ( V_13 -> V_413 )
F_10 ( V_17 , V_132 ,
F_56 ( V_13 -> V_413 ) ) ;
F_10 ( V_17 , V_255 , F_34 ( V_118 ) ) ;
F_10 ( V_17 , V_256 ,
F_12 ( V_26 ) ) ;
F_10 ( V_17 , V_66 , F_34 ( V_118 ) ) ;
return V_54 ;
V_63:
return V_55 ;
}
enum V_8 F_209 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 = V_13 -> V_314 ;
struct V_117 * V_75 = V_2 -> V_75 ;
F_14 ( V_9 , V_414 ) ;
if ( V_75 )
F_10 ( V_17 , V_132 ,
F_56 ( V_75 ) ) ;
F_10 ( V_17 , V_396 , F_34 ( V_2 ) ) ;
if ( V_13 -> V_120 >= V_13 -> V_121 ) {
F_10 ( V_17 , V_25 ,
F_12 ( V_203 ) ) ;
F_10 ( V_17 , V_122 ,
F_58 ( V_123 ) ) ;
F_10 ( V_17 , V_124 ,
F_59 ( V_125 ) ) ;
F_14 ( V_9 , V_73 ) ;
F_15 ( V_9 , V_31 ) ;
return V_241 ;
}
F_61 ( V_13 -> V_314 ) ;
F_10 ( V_17 , V_66 ,
F_34 ( V_13 -> V_314 ) ) ;
F_10 ( V_17 , V_256 ,
F_12 ( V_203 ) ) ;
return V_54 ;
}
enum V_8 F_210 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
struct V_1 * V_118 = NULL ;
F_69 ( L_20 , V_149 ) ;
F_14 ( V_9 , V_415 ) ;
V_118 = F_136 ( V_13 , NULL , 0 ) ;
if ( ! V_118 )
goto V_63;
F_10 ( V_17 , V_66 , F_34 ( V_118 ) ) ;
F_10 ( V_17 , V_122 ,
F_58 ( V_123 ) ) ;
F_10 ( V_17 , V_124 ,
F_59 ( V_125 ) ) ;
F_14 ( V_9 , V_73 ) ;
F_15 ( V_9 , V_31 ) ;
return V_33 ;
V_63:
return V_55 ;
}
enum V_8 F_211 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
enum V_8 V_196 ;
F_14 ( V_9 , V_416 ) ;
F_10 ( V_17 , V_28 ,
F_13 ( V_391 ) ) ;
V_196 = V_54 ;
if ( F_117 ( & V_13 -> V_253 ) ) {
V_196 = F_92 ( V_9 , V_11 , V_13 , type ,
V_15 , V_17 ) ;
}
return V_196 ;
}
enum V_8 F_212 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 , struct V_16 * V_17 )
{
return V_417 ;
}
enum V_8 F_213 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 , struct V_16 * V_17 )
{
return V_418 ;
}
enum V_8 F_214 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const union V_14 type ,
void * V_15 ,
struct V_16 * V_17 )
{
F_69 ( L_21 , V_149 , type . V_2 ) ;
return V_54 ;
}
static struct V_286 * F_134 ( struct V_1 * V_2 )
{
struct V_286 * V_419 ;
T_1 V_420 ;
unsigned int V_41 ;
T_1 V_421 ;
V_419 = (struct V_286 * ) V_2 -> V_59 -> V_60 ;
V_421 = F_2 ( V_419 -> V_422 ) ;
V_420 = F_2 ( V_419 -> V_420 ) ;
V_41 = sizeof( struct V_286 ) ;
V_41 += ( V_421 + V_420 ) * sizeof( T_5 ) ;
if ( V_41 > V_2 -> V_59 -> V_41 )
return NULL ;
F_25 ( V_2 -> V_59 , V_41 ) ;
return V_419 ;
}
static struct V_39 * F_22 (
struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
struct V_1 * V_2 ,
const void * V_373 , T_2 V_134 )
{
struct V_39 * V_40 ;
struct V_1 * abort ;
V_40 = F_135 ( V_9 , V_13 , V_2 ) ;
if ( V_40 ) {
abort = F_136 ( V_13 , V_2 , V_134 ) ;
if ( ! abort ) {
F_137 ( V_40 ) ;
return NULL ;
}
if ( F_138 ( abort ) )
V_40 -> V_46 = F_106 ( V_2 -> V_45 -> V_46 ) ;
F_32 ( abort , V_134 , V_373 ) ;
abort -> V_59 -> V_49 = V_11 -> V_48 . V_49 ;
F_139 ( V_40 , abort ) ;
}
return V_40 ;
}
static struct V_39 * F_135 (
struct V_9 * V_9 ,
const struct V_12 * V_13 ,
const struct V_1 * V_2 )
{
struct V_117 * V_75 ;
struct V_39 * V_40 ;
T_1 V_423 , V_424 ;
T_5 V_46 ;
V_423 = F_2 ( V_2 -> V_45 -> V_217 ) ;
V_424 = F_2 ( V_2 -> V_45 -> V_311 ) ;
if ( V_13 ) {
switch ( V_2 -> V_5 -> type ) {
case V_375 :
{
struct V_68 * V_378 ;
V_378 = (struct V_68 * ) V_2 -> V_5 ;
V_46 = F_106 ( V_378 -> V_57 . V_377 ) ;
break;
}
default:
V_46 = V_13 -> V_102 . V_376 . V_377 ;
break;
}
} else {
switch ( V_2 -> V_5 -> type ) {
case V_425 :
{
struct V_47 * V_162 ;
V_162 = (struct V_47 * ) V_2 -> V_5 ;
V_46 = F_106 ( V_162 -> V_57 . V_377 ) ;
break;
}
default:
V_46 = F_106 ( V_2 -> V_45 -> V_46 ) ;
break;
}
}
V_75 = F_215 ( V_9 , F_29 ( V_2 ) , V_23 ) ;
if ( ! V_75 )
goto V_63;
F_216 ( V_75 , (union V_142 * ) & V_2 -> V_217 ,
F_18 ( V_9 -> V_42 . V_43 ) ) ;
V_40 = & V_75 -> V_40 ;
F_217 ( V_40 , V_75 , V_423 , V_424 ) ;
F_218 ( V_40 , V_46 , 0 ) ;
return V_40 ;
V_63:
return NULL ;
}
void F_137 ( struct V_39 * V_40 )
{
F_219 ( V_40 -> V_75 ) ;
}
static void F_46 ( struct V_9 * V_9 ,
const struct V_10 * V_11 ,
const struct V_12 * V_13 ,
const struct V_1 * V_2 ,
struct V_16 * V_17 ,
struct V_1 * V_35 )
{
struct V_39 * V_40 ;
if ( V_35 ) {
V_40 = F_135 ( V_9 , V_13 , V_2 ) ;
if ( V_40 ) {
struct V_91 * V_426 ;
V_426 = V_2 -> V_56 . V_90 ;
V_40 -> V_46 = V_426 -> V_95 . V_189 ;
V_35 -> V_59 -> V_49 = V_11 -> V_48 . V_49 ;
F_139 ( V_40 , V_35 ) ;
F_10 ( V_17 , V_52 ,
F_24 ( V_40 ) ) ;
F_14 ( V_9 , V_53 ) ;
} else
F_23 ( V_35 ) ;
}
}
static int F_128 ( const struct V_12 * V_13 ,
struct V_1 * V_2 ,
struct V_16 * V_17 )
{
struct V_427 * V_428 = (struct V_427 * ) & V_13 -> V_102 . V_340 ;
struct V_87 * V_49 = V_13 -> V_48 . V_49 ;
struct V_9 * V_9 = F_77 ( V_49 ) ;
struct V_280 * V_279 ;
struct V_1 * V_197 ;
enum V_429 V_430 ;
T_2 V_431 ;
V_230 V_432 = 0 ;
T_6 V_433 , V_434 ;
T_5 V_336 ;
int V_435 ;
V_279 = (struct V_280 * ) V_2 -> V_59 -> V_60 ;
V_2 -> V_56 . V_279 = V_279 ;
F_25 ( V_2 -> V_59 , sizeof( * V_279 ) ) ;
V_336 = F_106 ( V_279 -> V_336 ) ;
F_69 ( L_7 , V_149 , V_336 ) ;
if ( V_13 -> V_102 . V_436 && ! V_2 -> V_437 ) {
struct V_163 * V_164 = F_220 ( V_2 -> V_59 ) -> V_164 ;
V_2 -> V_437 = 1 ;
if ( V_164 -> V_438 ( F_221 ( V_2 -> V_59 ) ) ) {
F_10 ( V_17 , V_439 ,
F_124 ( V_336 ) ) ;
}
}
V_435 = F_167 ( & V_13 -> V_102 . V_340 , V_336 ) ;
if ( V_435 < 0 ) {
if ( V_2 -> V_13 )
V_2 -> V_13 -> V_440 . V_441 ++ ;
return V_270 ;
} else if ( V_435 > 0 ) {
F_10 ( V_17 , V_442 , F_124 ( V_336 ) ) ;
return V_274 ;
}
V_431 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_431 -= sizeof( struct V_269 ) ;
V_430 = V_443 ;
if ( ( V_431 >= V_13 -> V_190 ) && ( ! V_13 -> V_444 . V_445 ) ) {
F_10 ( V_17 , V_446 , F_16 () ) ;
}
if ( ( ! V_2 -> V_447 ) && ( ! V_13 -> V_190 || V_13 -> V_448 ||
( V_431 > V_13 -> V_190 + V_13 -> V_449 ) ) ) {
if ( F_222 ( V_428 ) &&
( F_223 ( V_428 ) + 1 ) == V_336 ) {
F_69 ( L_22 , V_149 , V_336 ) ;
V_430 = V_450 ;
} else {
F_69 ( L_23 ,
V_149 , V_336 , V_431 , V_13 -> V_190 ) ;
return V_275 ;
}
}
if ( * V_49 -> V_451 -> V_452 ) {
if ( F_222 ( V_428 ) &&
( F_223 ( V_428 ) + 1 ) == V_336 ) {
F_69 ( L_24 ,
V_149 , V_336 ) ;
V_430 = V_450 ;
}
}
if ( F_3 ( 0 == V_431 ) ) {
V_197 = F_224 ( V_13 , V_2 , V_336 ) ;
if ( V_197 ) {
F_10 ( V_17 , V_66 ,
F_34 ( V_197 ) ) ;
}
F_10 ( V_17 , V_177 , F_16 () ) ;
F_10 ( V_17 , V_122 ,
F_58 ( V_319 ) ) ;
F_10 ( V_17 , V_124 ,
F_59 ( V_453 ) ) ;
F_14 ( V_9 , V_73 ) ;
F_15 ( V_9 , V_31 ) ;
return V_277 ;
}
V_2 -> V_447 = 1 ;
if ( V_2 -> V_5 -> V_281 & V_454 ) {
F_14 ( V_9 , V_455 ) ;
if ( V_2 -> V_13 )
V_2 -> V_13 -> V_440 . V_456 ++ ;
} else {
F_14 ( V_9 , V_457 ) ;
if ( V_2 -> V_13 )
V_2 -> V_13 -> V_440 . V_458 ++ ;
V_432 = 1 ;
}
V_434 = F_2 ( V_279 -> V_341 ) ;
if ( V_434 >= V_13 -> V_341 . V_342 ) {
F_10 ( V_17 , V_459 , F_124 ( V_336 ) ) ;
V_197 = F_90 ( V_13 , V_2 , V_460 ,
& V_279 -> V_341 ,
sizeof( V_279 -> V_341 ) ,
sizeof( T_6 ) ) ;
if ( V_197 )
F_10 ( V_17 , V_66 ,
F_34 ( V_197 ) ) ;
return V_271 ;
}
V_433 = F_2 ( V_279 -> V_433 ) ;
if ( V_432 && F_225 ( V_433 , F_226 ( & V_13 -> V_341 , V_461 , V_434 ) ) )
return V_278 ;
F_10 ( V_17 , V_430 , F_34 ( V_2 ) ) ;
return V_104 ;
}
