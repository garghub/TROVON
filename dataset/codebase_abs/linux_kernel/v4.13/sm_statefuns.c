static inline bool
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( F_3 ( V_2 -> V_7 ) )
return false ;
if ( F_3 ( V_4 < V_3 ) )
return false ;
return true ;
}
T_2 F_4 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
struct V_15 * V_16 ;
if ( ! F_5 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! V_2 -> V_17 )
return F_7 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_18 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_16 = F_9 ( V_12 , 0 , V_19 ,
0 , 0 , 0 , NULL , V_20 ) ;
if ( V_16 )
F_10 ( V_14 , V_21 ,
F_11 ( V_16 ) ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_23 ) ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_24 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_26 ) ) ;
F_14 ( V_8 , V_27 ) ;
F_15 ( V_8 , V_28 ) ;
F_10 ( V_14 , V_29 , F_16 () ) ;
return V_30 ;
}
T_2 F_17 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
struct V_1 * V_31 ;
struct V_11 * V_32 ;
struct V_1 * V_33 ;
struct V_34 * V_35 ;
T_5 * V_36 ;
int V_37 ;
if ( ! V_2 -> V_17 )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( V_10 == F_18 ( V_8 -> V_38 . V_39 ) -> V_10 ) {
F_14 ( V_8 , V_40 ) ;
return F_19 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( V_2 -> V_41 -> V_42 != 0 )
return F_19 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_43 ) ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( F_20 ( V_10 -> V_44 . V_45 , V_46 ) )
return F_19 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
V_33 = NULL ;
if ( ! F_21 ( V_8 , V_10 , V_12 , V_2 -> V_5 -> type ,
(struct V_43 * ) V_2 -> V_5 , V_2 ,
& V_33 ) ) {
if ( V_33 ) {
V_35 = F_22 ( V_8 , V_10 , V_12 , V_13 ,
( V_47 * ) ( V_33 -> V_5 ) +
sizeof( struct V_18 ) ,
F_2 ( V_33 -> V_5 -> V_6 ) -
sizeof( struct V_18 ) ) ;
F_23 ( V_33 ) ;
if ( V_35 ) {
F_10 ( V_14 , V_48 ,
F_24 ( V_35 ) ) ;
F_14 ( V_8 , V_49 ) ;
return V_50 ;
} else {
return V_51 ;
}
} else {
return F_19 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
}
}
V_2 -> V_52 . V_53 = (struct V_54 * ) V_2 -> V_55 -> V_56 ;
V_2 -> V_57 . V_58 = F_25 ( V_2 -> V_55 , sizeof( struct V_54 ) ) ;
V_32 = F_26 ( V_10 , V_2 , V_20 ) ;
if ( ! V_32 )
goto V_59;
if ( F_27 ( V_32 ,
F_28 ( F_29 ( V_2 ) ) ,
V_20 ) < 0 )
goto V_60;
if ( ! F_30 ( V_32 , V_2 , F_29 ( V_2 ) ,
(struct V_43 * ) V_2 -> V_5 ,
V_20 ) )
goto V_60;
V_37 = 0 ;
if ( V_33 )
V_37 = F_2 ( V_33 -> V_5 -> V_6 ) -
sizeof( struct V_18 ) ;
V_31 = F_31 ( V_32 , V_2 , V_20 , V_37 ) ;
if ( ! V_31 )
goto V_60;
if ( V_33 ) {
V_36 = ( T_5 * )
( ( V_47 * ) ( V_33 -> V_5 ) +
sizeof( struct V_18 ) ) ;
F_32 ( V_31 , V_37 , V_36 ) ;
F_23 ( V_33 ) ;
}
F_10 ( V_14 , V_61 , F_33 ( V_32 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
F_10 ( V_14 , V_29 , F_16 () ) ;
return V_30 ;
V_60:
F_35 ( V_32 ) ;
V_59:
if ( V_33 )
F_23 ( V_33 ) ;
return V_51 ;
}
T_2 F_36 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
struct V_43 * V_63 ;
struct V_1 * V_33 ;
struct V_34 * V_35 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! V_2 -> V_17 )
return F_7 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_64 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_2 -> V_52 . V_53 = (struct V_54 * ) V_2 -> V_55 -> V_56 ;
V_33 = NULL ;
if ( ! F_21 ( V_8 , V_10 , V_12 , V_2 -> V_5 -> type ,
(struct V_43 * ) V_2 -> V_5 , V_2 ,
& V_33 ) ) {
T_6 error = V_65 ;
if ( V_33 ) {
V_35 = F_22 ( V_8 , V_10 , V_12 , V_13 ,
( V_47 * ) ( V_33 -> V_5 ) +
sizeof( struct V_18 ) ,
F_2 ( V_33 -> V_5 -> V_6 ) -
sizeof( struct V_18 ) ) ;
F_23 ( V_33 ) ;
if ( V_35 ) {
F_10 ( V_14 , V_48 ,
F_24 ( V_35 ) ) ;
F_14 ( V_8 , V_49 ) ;
error = V_66 ;
}
}
if ( F_38 ( V_67 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
F_14 ( V_8 , V_68 ) ;
return F_39 ( V_8 , V_14 , error , V_69 ,
V_12 , V_2 -> V_70 ) ;
}
V_2 -> V_57 . V_58 = F_25 ( V_2 -> V_55 , sizeof( struct V_54 ) ) ;
V_63 = (struct V_43 * ) V_2 -> V_5 ;
F_10 ( V_14 , V_71 ,
F_40 ( V_63 ) ) ;
F_10 ( V_14 , V_72 , F_16 () ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_73 ) ) ;
F_10 ( V_14 , V_74 ,
F_12 ( V_75 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_76 ) ) ;
F_10 ( V_14 , V_77 , F_16 () ) ;
F_10 ( V_14 , V_78 ,
F_34 ( V_33 ) ) ;
return V_50 ;
}
T_2 F_41 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type , void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
struct V_11 * V_32 ;
struct V_43 * V_79 ;
struct V_1 * V_31 ;
struct V_15 * V_16 , * V_80 = NULL ;
int error = 0 ;
struct V_1 * V_81 ;
struct V_82 * V_45 ;
if ( V_10 == F_18 ( V_8 -> V_38 . V_39 ) -> V_10 ) {
F_14 ( V_8 , V_40 ) ;
return F_19 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_18 ) ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
V_45 = V_10 -> V_44 . V_45 ;
if ( ! F_20 ( V_45 , V_83 ) ||
( F_42 ( V_45 , V_84 ) && F_43 ( V_45 ) ) )
return F_19 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
V_2 -> V_52 . V_85 =
(struct V_86 * ) V_2 -> V_55 -> V_56 ;
if ( ! F_44 ( V_2 -> V_55 , F_2 ( V_2 -> V_5 -> V_6 ) -
sizeof( struct V_18 ) ) )
goto V_59;
V_32 = F_45 ( V_10 , V_12 , V_2 , V_20 , & error ,
& V_81 ) ;
if ( ! V_32 ) {
switch ( error ) {
case - V_87 :
goto V_59;
case - V_88 :
F_46 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
V_81 ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
case - V_89 :
default:
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
}
V_79 = & V_2 -> V_52 . V_85 -> V_90 . V_79 [ 0 ] ;
if ( ! F_30 ( V_32 , V_2 ,
& V_2 -> V_52 . V_85 -> V_90 . V_91 ,
V_79 , V_20 ) )
goto V_60;
error = F_47 ( V_32 , V_20 ) ;
if ( error )
goto V_60;
if ( V_2 -> V_92 ) {
struct V_1 V_93 ;
T_7 V_94 ;
if ( ! V_8 -> V_38 . V_95 || ! V_32 -> V_96 . V_97 ) {
F_35 ( V_32 ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
V_93 . V_55 = V_2 -> V_92 ;
V_93 . V_12 = V_2 -> V_12 ;
V_93 . V_41 = V_2 -> V_41 ;
V_93 . V_5 = (struct V_18 * )
F_48 ( V_2 -> V_92 ,
sizeof( struct V_18 ) ) ;
F_25 ( V_2 -> V_92 , sizeof( struct V_18 ) ) ;
V_93 . V_70 = V_2 -> V_70 ;
V_94 = F_49 ( V_8 , V_10 , V_32 , type , & V_93 ) ;
if ( V_94 != V_98 ) {
F_35 ( V_32 ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
}
V_31 = F_50 ( V_32 , V_2 ) ;
if ( ! V_31 )
goto V_60;
V_16 = F_9 ( V_32 , 0 , V_99 , 0 ,
V_32 -> V_90 . V_100 ,
V_32 -> V_90 . V_101 ,
NULL , V_20 ) ;
if ( ! V_16 )
goto V_102;
if ( V_32 -> V_96 . V_103 ) {
V_80 = F_51 ( V_32 ,
V_20 ) ;
if ( ! V_80 )
goto V_104;
}
F_10 ( V_14 , V_61 , F_33 ( V_32 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_105 ) ) ;
F_14 ( V_8 , V_28 ) ;
F_14 ( V_8 , V_106 ) ;
F_10 ( V_14 , V_107 , F_16 () ) ;
if ( V_32 -> V_108 [ V_109 ] )
F_10 ( V_14 , V_74 ,
F_12 ( V_109 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
F_10 ( V_14 , V_21 , F_11 ( V_16 ) ) ;
if ( V_80 )
F_10 ( V_14 , V_21 ,
F_11 ( V_80 ) ) ;
return V_50 ;
V_104:
F_52 ( V_16 ) ;
V_102:
F_23 ( V_31 ) ;
V_60:
F_35 ( V_32 ) ;
V_59:
return V_51 ;
}
T_2 F_53 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type , void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
struct V_15 * V_16 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_18 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
F_10 ( V_14 , V_72 , F_16 () ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_75 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_105 ) ) ;
F_14 ( V_8 , V_28 ) ;
F_14 ( V_8 , V_110 ) ;
F_10 ( V_14 , V_107 , F_16 () ) ;
if ( V_12 -> V_108 [ V_109 ] )
F_10 ( V_14 , V_74 ,
F_12 ( V_109 ) ) ;
V_16 = F_9 ( V_12 , 0 , V_99 ,
0 , V_12 -> V_90 . V_100 ,
V_12 -> V_90 . V_101 ,
NULL , V_20 ) ;
if ( ! V_16 )
goto V_59;
F_10 ( V_14 , V_21 , F_11 ( V_16 ) ) ;
if ( V_12 -> V_96 . V_103 ) {
V_16 = F_51 ( V_12 , V_20 ) ;
if ( ! V_16 )
goto V_59;
F_10 ( V_14 , V_21 ,
F_11 ( V_16 ) ) ;
}
return V_50 ;
V_59:
return V_51 ;
}
static T_2 F_54 ( const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_111 * V_70 = (struct V_111 * ) V_13 ;
struct V_1 * V_112 ;
V_112 = F_55 ( V_12 , V_70 ) ;
if ( ! V_112 )
return V_51 ;
F_10 ( V_14 , V_113 ,
F_56 ( V_70 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_112 ) ) ;
return V_50 ;
}
T_2 F_57 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_111 * V_70 = (struct V_111 * ) V_13 ;
if ( V_12 -> V_114 >= V_12 -> V_115 ) {
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_119 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_30 ;
}
if ( V_70 -> V_120 & V_121 ) {
if ( V_51 ==
F_54 ( V_10 , V_12 , type , V_13 ,
V_14 ) )
return V_51 ;
F_10 ( V_14 , V_122 ,
F_56 ( V_70 ) ) ;
}
F_10 ( V_14 , V_123 ,
F_56 ( V_70 ) ) ;
F_10 ( V_14 , V_124 ,
F_56 ( V_70 ) ) ;
return V_50 ;
}
T_2 F_60 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type , void * V_13 ,
T_4 * V_14 )
{
struct V_111 * V_70 = V_13 ;
if ( V_12 -> V_114 >= V_12 -> V_115 ) {
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_119 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_30 ;
}
F_61 ( V_12 -> V_125 ) ;
F_10 ( V_14 , V_62 ,
F_34 ( V_12 -> V_125 ) ) ;
F_10 ( V_14 , V_126 , F_56 ( V_70 ) ) ;
return V_50 ;
}
T_2 F_62 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_127 * V_57 ;
struct V_1 * V_2 = V_13 ;
struct V_1 * V_112 ;
T_8 V_128 = 0 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_129 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_2 -> V_52 . V_130 = ( V_131 * ) V_2 -> V_55 -> V_56 ;
V_57 = (struct V_127 * ) V_2 -> V_52 . V_130 ;
V_128 = F_2 ( V_2 -> V_5 -> V_6 ) - sizeof( struct V_18 ) ;
if ( F_2 ( V_57 -> V_6 ) > V_128 )
return F_63 ( V_8 , V_10 , V_12 , type , V_13 ,
V_57 , V_14 ) ;
if ( ! F_44 ( V_2 -> V_55 , V_128 ) )
goto V_59;
V_112 = F_64 ( V_12 , V_2 , V_57 , V_128 ) ;
if ( ! V_112 )
goto V_59;
F_10 ( V_14 , V_62 , F_34 ( V_112 ) ) ;
return V_50 ;
V_59:
return V_51 ;
}
T_2 F_65 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
union V_132 V_133 ;
struct V_111 * V_134 ;
T_9 * V_135 ;
unsigned long V_136 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_18 ) +
sizeof( T_9 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_135 = ( T_9 * ) V_2 -> V_55 -> V_56 ;
if ( F_2 ( V_135 -> V_57 . V_6 ) !=
sizeof( T_9 ) ) {
return V_137 ;
}
V_133 = V_135 -> V_138 ;
V_134 = F_66 ( V_12 , & V_133 ) ;
if ( F_3 ( ! V_134 ) ) {
if ( V_133 . V_139 . V_140 == V_141 ) {
F_67 ( L_1 ,
V_142 ,
V_12 ,
& V_133 . V_143 . V_144 ) ;
} else {
F_67 ( L_2 ,
V_142 ,
V_12 ,
& V_133 . V_145 . V_146 . V_147 ) ;
}
return V_137 ;
}
if ( V_135 -> V_148 != V_134 -> V_148 )
return V_137 ;
V_136 = V_134 -> V_149 + V_134 -> V_150 ;
if ( F_68 ( V_135 -> V_151 , V_152 ) ||
F_68 ( V_152 , V_135 -> V_151 + V_136 ) ) {
F_69 ( L_3
L_4 , V_142 , V_134 ) ;
return V_137 ;
}
F_10 ( V_14 , V_153 , F_56 ( V_134 ) ) ;
return V_50 ;
}
static int F_70 ( struct V_8 * V_8 , union V_132 * V_154 ,
struct V_1 * V_155 ,
T_4 * V_14 )
{
int V_37 ;
struct V_34 * V_156 ;
union V_157 * V_158 ;
struct V_159 * V_160 ;
struct V_9 * V_10 ;
char V_161 [ sizeof( struct V_159 ) + sizeof( union V_157 ) ] ;
struct V_162 * V_163 = F_71 ( V_154 -> V_145 . V_164 ) ;
V_160 = (struct V_159 * ) V_161 ;
V_158 = (union V_157 * ) V_160 -> V_165 ;
V_37 = V_163 -> V_166 ( V_154 , V_158 ) ;
V_37 += sizeof( V_167 ) ;
V_160 -> V_168 = V_169 ;
V_160 -> V_6 = F_72 ( V_37 ) ;
V_10 = F_18 ( V_8 -> V_38 . V_39 ) -> V_10 ;
V_156 = F_22 ( V_8 , V_10 , NULL , V_155 , V_160 , V_37 ) ;
if ( ! V_156 )
goto V_170;
F_10 ( V_14 , V_48 , F_24 ( V_156 ) ) ;
F_14 ( V_8 , V_49 ) ;
F_10 ( V_14 , V_171 , F_16 () ) ;
V_170:
return 0 ;
}
static bool F_73 ( const struct V_172 * V_173 ,
union V_132 * V_174 )
{
struct V_111 * V_175 ;
F_74 (addr, list, transports) {
if ( F_75 ( V_174 , & V_175 -> V_174 ) )
return true ;
}
return false ;
}
static int F_76 ( const struct V_11 * V_32 ,
const struct V_11 * V_12 ,
struct V_1 * V_155 ,
T_4 * V_14 )
{
struct V_8 * V_8 = F_77 ( V_32 -> V_44 . V_45 ) ;
struct V_111 * V_176 ;
int V_94 = 1 ;
F_74 (new_addr, &new_asoc->peer.transport_addr_list,
transports) {
if ( ! F_73 ( & V_12 -> V_96 . V_177 ,
& V_176 -> V_174 ) ) {
F_70 ( V_8 , & V_176 -> V_174 , V_155 ,
V_14 ) ;
V_94 = 0 ;
break;
}
}
return V_94 ;
}
static void F_78 ( struct V_11 * V_32 ,
const struct V_11 * V_12 )
{
switch ( V_12 -> V_178 ) {
case V_179 :
V_32 -> V_90 . V_180 = V_12 -> V_90 . V_180 ;
V_32 -> V_90 . V_181 = V_12 -> V_90 . V_180 ;
V_32 -> V_90 . V_182 = 0 ;
break;
case V_76 :
V_32 -> V_90 . V_180 = V_12 -> V_90 . V_180 ;
V_32 -> V_90 . V_181 = V_12 -> V_90 . V_180 ;
V_32 -> V_90 . V_182 = V_12 -> V_90 . V_183 ;
break;
default:
V_32 -> V_90 . V_181 = V_12 -> V_90 . V_180 ;
V_32 -> V_90 . V_182 = V_12 -> V_90 . V_183 ;
break;
}
V_32 -> V_184 = V_12 -> V_184 ;
V_32 -> V_90 . V_100 = V_12 -> V_90 . V_100 ;
V_32 -> V_90 . V_101 = V_12 -> V_90 . V_101 ;
V_32 -> V_90 . V_185 = V_12 -> V_90 . V_185 ;
}
static char F_79 ( struct V_11 * V_32 ,
const struct V_11 * V_12 )
{
if ( ( V_12 -> V_90 . V_180 != V_32 -> V_90 . V_180 ) &&
( V_12 -> V_90 . V_183 != V_32 -> V_90 . V_183 ) &&
( V_12 -> V_90 . V_180 == V_32 -> V_90 . V_181 ) &&
( V_12 -> V_90 . V_183 == V_32 -> V_90 . V_182 ) )
return 'A' ;
if ( ( V_12 -> V_90 . V_180 == V_32 -> V_90 . V_180 ) &&
( ( V_12 -> V_90 . V_183 != V_32 -> V_90 . V_183 ) ||
( 0 == V_12 -> V_90 . V_183 ) ) ) {
return 'B' ;
}
if ( ( V_12 -> V_90 . V_180 == V_32 -> V_90 . V_180 ) &&
( V_12 -> V_90 . V_183 == V_32 -> V_90 . V_183 ) )
return 'D' ;
if ( ( V_12 -> V_90 . V_180 != V_32 -> V_90 . V_180 ) &&
( V_12 -> V_90 . V_183 == V_32 -> V_90 . V_183 ) &&
( 0 == V_32 -> V_90 . V_181 ) &&
( 0 == V_32 -> V_90 . V_182 ) )
return 'C' ;
return 'E' ;
}
static T_2 F_80 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 , T_4 * V_14 )
{
T_2 V_186 ;
struct V_1 * V_2 = V_13 ;
struct V_1 * V_31 ;
struct V_11 * V_32 ;
struct V_1 * V_33 ;
struct V_34 * V_35 ;
T_5 * V_36 ;
int V_37 ;
if ( ! V_2 -> V_17 )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( V_2 -> V_41 -> V_42 != 0 )
return F_19 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_43 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_2 -> V_52 . V_53 = (struct V_54 * ) V_2 -> V_55 -> V_56 ;
V_2 -> V_57 . V_58 = F_25 ( V_2 -> V_55 , sizeof( struct V_54 ) ) ;
V_33 = NULL ;
if ( ! F_21 ( V_8 , V_10 , V_12 , V_2 -> V_5 -> type ,
(struct V_43 * ) V_2 -> V_5 , V_2 ,
& V_33 ) ) {
if ( V_33 ) {
V_35 = F_22 ( V_8 , V_10 , V_12 , V_13 ,
( V_47 * ) ( V_33 -> V_5 ) +
sizeof( struct V_18 ) ,
F_2 ( V_33 -> V_5 -> V_6 ) -
sizeof( struct V_18 ) ) ;
if ( V_35 ) {
F_10 ( V_14 , V_48 ,
F_24 ( V_35 ) ) ;
F_14 ( V_8 , V_49 ) ;
V_186 = V_50 ;
} else {
V_186 = V_51 ;
}
goto V_187;
} else {
return F_19 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
}
}
V_32 = F_26 ( V_10 , V_2 , V_20 ) ;
if ( ! V_32 )
goto V_59;
if ( F_27 ( V_32 ,
F_28 ( F_29 ( V_2 ) ) , V_20 ) < 0 )
goto V_59;
if ( ! F_30 ( V_32 , V_2 , F_29 ( V_2 ) ,
(struct V_43 * ) V_2 -> V_5 ,
V_20 ) )
goto V_59;
if ( ! F_81 ( V_12 , V_188 ) ) {
if ( ! F_76 ( V_32 , V_12 , V_2 ,
V_14 ) ) {
V_186 = V_50 ;
goto V_189;
}
}
F_78 ( V_32 , V_12 ) ;
V_37 = 0 ;
if ( V_33 ) {
V_37 = F_2 ( V_33 -> V_5 -> V_6 ) -
sizeof( struct V_18 ) ;
}
V_31 = F_31 ( V_32 , V_2 , V_20 , V_37 ) ;
if ( ! V_31 )
goto V_59;
if ( V_33 ) {
V_36 = ( T_5 * )
( ( V_47 * ) ( V_33 -> V_5 ) +
sizeof( struct V_18 ) ) ;
F_32 ( V_31 , V_37 , V_36 ) ;
}
F_10 ( V_14 , V_61 , F_33 ( V_32 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
F_10 ( V_14 , V_29 , F_16 () ) ;
V_186 = V_50 ;
return V_186 ;
V_59:
V_186 = V_51 ;
V_189:
if ( V_32 )
F_35 ( V_32 ) ;
V_187:
if ( V_33 )
F_23 ( V_33 ) ;
return V_186 ;
}
T_2 F_82 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return F_80 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_83 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return F_80 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_84 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 , T_4 * V_14 )
{
if ( V_10 == F_18 ( V_8 -> V_38 . V_39 ) -> V_10 )
return F_85 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
else
return F_86 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
static T_2 F_87 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
struct V_1 * V_2 ,
T_4 * V_14 ,
struct V_11 * V_32 )
{
struct V_43 * V_79 ;
struct V_15 * V_16 ;
struct V_1 * V_31 ;
struct V_1 * V_190 ;
T_2 V_191 ;
V_79 = & V_2 -> V_52 . V_85 -> V_90 . V_79 [ 0 ] ;
if ( ! F_30 ( V_32 , V_2 , F_29 ( V_2 ) , V_79 ,
V_20 ) )
goto V_59;
if ( ! F_76 ( V_32 , V_12 , V_2 , V_14 ) ) {
return V_50 ;
}
if ( F_81 ( V_12 , V_192 ) ) {
V_191 = F_88 ( V_8 , V_10 , V_12 ,
F_89 ( V_2 -> V_5 -> type ) ,
V_2 , V_14 ) ;
if ( V_51 == V_191 )
goto V_59;
V_190 = F_90 ( V_12 , V_2 ,
V_193 ,
NULL , 0 , 0 ) ;
if ( V_190 )
F_10 ( V_14 , V_62 ,
F_34 ( V_190 ) ) ;
return V_50 ;
}
F_10 ( V_14 , V_194 , F_16 () ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_195 ) ) ;
F_10 ( V_14 , V_196 , F_16 () ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_197 ) ) ;
F_10 ( V_14 , V_198 , F_16 () ) ;
V_31 = F_50 ( V_32 , V_2 ) ;
if ( ! V_31 )
goto V_59;
V_16 = F_9 ( V_12 , 0 , V_199 , 0 ,
V_32 -> V_90 . V_100 ,
V_32 -> V_90 . V_101 ,
NULL , V_20 ) ;
if ( ! V_16 )
goto V_102;
F_10 ( V_14 , V_200 , F_33 ( V_32 ) ) ;
F_10 ( V_14 , V_21 , F_11 ( V_16 ) ) ;
if ( F_81 ( V_12 , V_201 ) &&
( F_20 ( V_12 -> V_44 . V_45 , V_46 ) ||
F_91 ( V_12 -> V_44 . V_45 , V_202 ) ) ) {
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
return F_92 ( V_8 , V_10 , V_12 ,
F_89 ( 0 ) , NULL ,
V_14 ) ;
} else {
F_10 ( V_14 , V_25 ,
F_13 ( V_105 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
}
return V_50 ;
V_102:
F_23 ( V_31 ) ;
V_59:
return V_51 ;
}
static T_2 F_93 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
struct V_1 * V_2 ,
T_4 * V_14 ,
struct V_11 * V_32 )
{
struct V_43 * V_79 ;
struct V_1 * V_31 ;
V_79 = & V_2 -> V_52 . V_85 -> V_90 . V_79 [ 0 ] ;
if ( ! F_30 ( V_32 , V_2 , F_29 ( V_2 ) , V_79 ,
V_20 ) )
goto V_59;
F_10 ( V_14 , V_200 , F_33 ( V_32 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_105 ) ) ;
F_14 ( V_8 , V_28 ) ;
F_10 ( V_14 , V_107 , F_16 () ) ;
V_31 = F_50 ( V_32 , V_2 ) ;
if ( ! V_31 )
goto V_59;
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
F_10 ( V_14 , V_203 , F_94 ( V_99 ) ) ;
if ( V_12 -> V_96 . V_103 )
F_10 ( V_14 , V_204 , F_16 () ) ;
return V_50 ;
V_59:
return V_51 ;
}
static T_2 F_95 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
struct V_1 * V_2 ,
T_4 * V_14 ,
struct V_11 * V_32 )
{
return V_137 ;
}
static T_2 F_96 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
struct V_1 * V_2 ,
T_4 * V_14 ,
struct V_11 * V_32 )
{
struct V_15 * V_16 = NULL , * V_80 = NULL ;
struct V_1 * V_31 ;
if ( V_12 -> V_178 < V_105 ) {
F_10 ( V_14 , V_22 ,
F_12 ( V_75 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_105 ) ) ;
F_14 ( V_8 , V_28 ) ;
F_10 ( V_14 , V_107 ,
F_16 () ) ;
V_16 = F_9 ( V_12 , 0 ,
V_99 , 0 ,
V_12 -> V_90 . V_100 ,
V_12 -> V_90 . V_101 ,
NULL , V_20 ) ;
if ( ! V_16 )
goto V_59;
if ( V_12 -> V_96 . V_103 ) {
V_80 = F_51 ( V_12 ,
V_20 ) ;
if ( ! V_80 )
goto V_59;
}
}
V_31 = F_50 ( V_32 , V_2 ) ;
if ( ! V_31 )
goto V_59;
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
if ( V_16 )
F_10 ( V_14 , V_21 ,
F_11 ( V_16 ) ) ;
if ( V_80 )
F_10 ( V_14 , V_21 ,
F_11 ( V_80 ) ) ;
return V_50 ;
V_59:
if ( V_80 )
F_52 ( V_80 ) ;
if ( V_16 )
F_52 ( V_16 ) ;
return V_51 ;
}
T_2 F_97 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
T_2 V_186 ;
struct V_1 * V_2 = V_13 ;
struct V_11 * V_32 ;
int error = 0 ;
char V_205 ;
struct V_1 * V_81 ;
if ( ! F_1 ( V_2 , sizeof( struct V_18 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_2 -> V_52 . V_85 = (struct V_86 * ) V_2 -> V_55 -> V_56 ;
if ( ! F_44 ( V_2 -> V_55 , F_2 ( V_2 -> V_5 -> V_6 ) -
sizeof( struct V_18 ) ) )
goto V_59;
V_32 = F_45 ( V_10 , V_12 , V_2 , V_20 , & error ,
& V_81 ) ;
if ( ! V_32 ) {
switch ( error ) {
case - V_87 :
goto V_59;
case - V_88 :
F_46 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
V_81 ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
case - V_89 :
default:
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
}
V_32 -> V_206 = 1 ;
V_205 = F_79 ( V_32 , V_12 ) ;
switch ( V_205 ) {
case 'A' :
V_186 = F_87 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
V_32 ) ;
break;
case 'B' :
V_186 = F_93 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
V_32 ) ;
break;
case 'C' :
V_186 = F_95 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
V_32 ) ;
break;
case 'D' :
V_186 = F_96 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
V_32 ) ;
break;
default:
V_186 = F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
break;
}
F_10 ( V_14 , V_207 , F_33 ( V_32 ) ) ;
F_10 ( V_14 , V_29 , F_16 () ) ;
F_10 ( V_14 , V_207 ,
F_33 ( (struct V_11 * ) V_12 ) ) ;
return V_186 ;
V_59:
return V_51 ;
}
T_2 F_98 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
if ( ! F_5 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_208 ) ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( V_209 ==
F_99 ( & V_12 -> V_44 . V_210 , & V_2 -> V_211 ) )
return F_86 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
return F_100 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_101 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
if ( ! F_5 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_208 ) ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( V_209 ==
F_99 ( & V_12 -> V_44 . V_210 , & V_2 -> V_211 ) )
return F_86 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_23 ) ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_24 ) ) ;
return F_100 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_102 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return F_101 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_103 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
V_167 * V_190 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_212 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
F_104 (err, chunk->chunk_hdr) {
if ( V_213 == V_190 -> V_168 )
return F_105 ( V_8 , V_10 , V_12 , type ,
V_13 , V_14 ) ;
}
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
static T_2 F_105 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
T_10 V_214 ;
T_11 V_215 ;
V_167 * V_190 ;
struct V_1 * V_112 ;
struct V_216 * V_217 ;
int V_218 = V_12 -> V_219 + 1 ;
if ( V_218 > V_12 -> V_220 ) {
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_221 ,
F_59 ( V_213 ) ) ;
return V_30 ;
}
V_190 = ( V_167 * ) ( V_2 -> V_55 -> V_56 ) ;
V_214 = F_106 ( * ( V_222 * ) ( ( V_223 * ) V_190 + sizeof( V_167 ) ) ) ;
V_214 = ( V_214 * 2 ) / 1000 ;
V_215 . V_57 . type = V_224 ;
V_215 . V_57 . V_6 = F_72 ( sizeof( V_215 ) ) ;
V_215 . V_225 = F_107 ( V_214 ) ;
V_217 = (struct V_216 * ) & V_12 -> V_44 . V_210 ;
V_112 = F_108 ( V_12 , V_217 , V_20 , sizeof( V_215 ) ) ;
if ( ! V_112 )
goto V_59;
F_32 ( V_112 , sizeof( V_215 ) , & V_215 ) ;
F_10 ( V_14 , V_226 , F_16 () ) ;
F_10 ( V_14 , V_194 , F_16 () ) ;
F_10 ( V_14 , V_227 , F_16 () ) ;
F_10 ( V_14 , V_228 , F_16 () ) ;
F_10 ( V_14 , V_229 ,
F_56 ( V_12 -> V_96 . V_230 ) ) ;
F_10 ( V_14 , V_231 , F_16 () ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_75 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_179 ) ) ;
F_10 ( V_14 , V_74 ,
F_12 ( V_73 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_112 ) ) ;
return V_50 ;
V_59:
return V_51 ;
}
T_2 F_109 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
if ( ! F_5 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_208 ) ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( V_209 ==
F_99 ( & V_12 -> V_44 . V_210 , & V_2 -> V_211 ) )
return F_86 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
return F_100 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
static T_2 F_100 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
unsigned int V_37 ;
T_12 error = V_119 ;
V_37 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_37 >= sizeof( struct V_18 ) + sizeof( struct V_159 ) ) {
V_167 * V_190 ;
F_104 ( V_190 , V_2 -> V_5 ) ;
if ( ( void * ) V_190 != ( void * ) V_2 -> V_232 )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
error = ( ( V_167 * ) V_2 -> V_55 -> V_56 ) -> V_168 ;
}
F_10 ( V_14 , V_116 , F_58 ( V_233 ) ) ;
F_10 ( V_14 , V_118 , F_59 ( error ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_234 ;
}
T_2 F_110 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
unsigned int V_37 ;
T_12 error = V_119 ;
if ( ! F_5 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_208 ) ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
V_37 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_37 >= sizeof( struct V_18 ) + sizeof( struct V_159 ) )
error = ( ( V_167 * ) V_2 -> V_55 -> V_56 ) -> V_168 ;
return F_39 ( V_8 , V_14 , error , V_69 , V_12 ,
V_2 -> V_70 ) ;
}
T_2 F_111 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return F_39 ( V_8 , V_14 , V_119 ,
V_235 , V_12 ,
(struct V_111 * ) V_13 ) ;
}
T_2 F_112 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return F_110 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
static T_2 F_39 ( struct V_8 * V_8 ,
T_4 * V_14 ,
T_12 error , int V_236 ,
const struct V_11 * V_12 ,
struct V_111 * V_70 )
{
F_69 ( L_5 , V_142 ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_26 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_73 ) ) ;
F_10 ( V_14 , V_116 , F_58 ( V_236 ) ) ;
F_10 ( V_14 , V_221 ,
F_59 ( error ) ) ;
return V_234 ;
}
T_2 F_113 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
T_13 * V_237 ;
T_2 V_191 ;
struct V_15 * V_16 ;
T_14 V_238 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 ,
sizeof( struct V_239 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_237 = ( T_13 * ) V_2 -> V_55 -> V_56 ;
F_25 ( V_2 -> V_55 , sizeof( T_13 ) ) ;
V_2 -> V_52 . V_240 = V_237 ;
V_238 = F_106 ( V_237 -> V_241 ) ;
if ( F_114 ( V_238 , V_12 -> V_242 ) ) {
F_69 ( L_6 , V_142 , V_238 ,
V_12 -> V_242 ) ;
return V_137 ;
}
if ( ! F_114 ( V_238 , V_12 -> V_243 ) )
return F_115 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
V_16 = F_116 ( V_12 , 0 , V_20 ) ;
if ( ! V_16 ) {
V_191 = V_51 ;
goto V_170;
}
F_10 ( V_14 , V_21 , F_11 ( V_16 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_244 ) ) ;
V_191 = V_50 ;
if ( F_117 ( & V_12 -> V_245 ) ) {
V_191 = F_118 ( V_8 , V_10 , V_12 , type ,
V_13 , V_14 ) ;
}
if ( V_51 == V_191 )
goto V_170;
F_10 ( V_14 , V_246 ,
F_119 ( V_2 -> V_52 . V_240 -> V_241 ) ) ;
V_170:
return V_191 ;
}
T_2 F_120 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
T_13 * V_237 ;
T_14 V_238 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 ,
sizeof( struct V_239 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_237 = ( T_13 * ) V_2 -> V_55 -> V_56 ;
V_238 = F_106 ( V_237 -> V_241 ) ;
if ( F_114 ( V_238 , V_12 -> V_242 ) ) {
F_69 ( L_6 , V_142 , V_238 ,
V_12 -> V_242 ) ;
return V_137 ;
}
if ( ! F_114 ( V_238 , V_12 -> V_243 ) )
return F_115 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
F_10 ( V_14 , V_246 ,
F_119 ( V_237 -> V_241 ) ) ;
return V_50 ;
}
T_2 F_88 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
struct V_1 * V_112 ;
if ( ! F_1 ( V_2 , sizeof( struct V_18 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_112 = F_121 ( V_12 , V_2 ) ;
if ( NULL == V_112 )
goto V_59;
F_10 ( V_14 , V_247 , F_34 ( V_112 ) ) ;
F_10 ( V_14 , V_248 ,
F_12 ( V_23 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_112 ) ) ;
return V_50 ;
V_59:
return V_51 ;
}
T_2 F_122 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
T_15 * V_249 ;
struct V_1 * V_2 = V_13 ;
T_10 V_250 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_251 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_249 = ( T_15 * ) V_2 -> V_55 -> V_56 ;
F_25 ( V_2 -> V_55 , sizeof( T_15 ) ) ;
V_250 = F_106 ( V_249 -> V_250 ) ;
if ( F_123 ( V_12 -> V_252 , V_250 ) ) {
F_10 ( V_14 ,
V_253 ,
F_124 ( V_250 ) ) ;
}
return V_50 ;
}
T_2 F_125 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
T_16 * V_254 ;
struct V_1 * V_2 = V_13 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_251 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_254 = ( T_16 * ) V_2 -> V_55 -> V_56 ;
F_25 ( V_2 -> V_55 , sizeof( T_16 ) ) ;
F_10 ( V_14 , V_255 ,
F_124 ( F_106 ( V_254 -> V_250 ) ) ) ;
return V_50 ;
}
T_2 F_126 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
T_17 V_256 = F_127 () ;
int error ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_257 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_258 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
error = F_128 ( V_12 , V_2 , V_14 ) ;
switch ( error ) {
case V_98 :
break;
case V_259 :
case V_260 :
F_14 ( V_8 , V_261 ) ;
goto V_262;
case V_263 :
case V_264 :
F_14 ( V_8 , V_261 ) ;
goto V_265;
case V_266 :
return V_234 ;
case V_267 :
return F_129 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
( V_223 * ) V_2 -> V_52 . V_268 ,
sizeof( struct V_269 ) ) ;
default:
F_130 () ;
}
if ( V_2 -> V_5 -> V_270 & V_271 )
V_256 = F_131 () ;
if ( V_12 -> V_108 [ V_109 ] ) {
F_10 ( V_14 , V_248 ,
F_12 ( V_109 ) ) ;
}
if ( V_2 -> V_272 )
F_10 ( V_14 , V_273 , V_256 ) ;
return V_50 ;
V_265:
if ( V_2 -> V_272 )
F_10 ( V_14 , V_273 , F_131 () ) ;
return V_137 ;
V_262:
if ( V_2 -> V_272 )
F_10 ( V_14 , V_273 , V_256 ) ;
return V_137 ;
}
T_2 F_132 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
int error ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_257 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_258 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
error = F_128 ( V_12 , V_2 , V_14 ) ;
switch ( error ) {
case V_98 :
case V_259 :
case V_263 :
case V_264 :
case V_260 :
break;
case V_266 :
return V_234 ;
case V_267 :
return F_129 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
( V_223 * ) V_2 -> V_52 . V_268 ,
sizeof( struct V_269 ) ) ;
default:
F_130 () ;
}
if ( V_2 -> V_272 ) {
F_10 ( V_14 , V_274 , F_16 () ) ;
F_10 ( V_14 , V_273 , F_131 () ) ;
F_10 ( V_14 , V_248 ,
F_12 ( V_23 ) ) ;
}
return V_50 ;
}
T_2 F_133 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
T_18 * V_275 ;
T_14 V_238 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_276 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_275 = F_134 ( V_2 ) ;
if ( ! V_275 )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
V_2 -> V_52 . V_277 = V_275 ;
V_238 = F_106 ( V_275 -> V_241 ) ;
if ( F_114 ( V_238 , V_12 -> V_242 ) ) {
F_69 ( L_6 , V_142 , V_238 ,
V_12 -> V_242 ) ;
return V_137 ;
}
if ( ! F_114 ( V_238 , V_12 -> V_243 ) )
return F_115 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
F_10 ( V_14 , V_278 , F_34 ( V_2 ) ) ;
return V_50 ;
}
static T_2 F_19 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_34 * V_35 = NULL ;
struct V_1 * V_2 = V_13 ;
struct V_1 * abort ;
V_35 = F_135 ( V_8 , V_12 , V_2 ) ;
if ( ! V_35 )
return V_51 ;
abort = F_136 ( V_12 , V_2 , 0 ) ;
if ( ! abort ) {
F_137 ( V_35 ) ;
return V_51 ;
}
if ( F_138 ( abort ) )
V_35 -> V_42 = F_106 ( V_2 -> V_41 -> V_42 ) ;
abort -> V_55 -> V_45 = V_10 -> V_44 . V_45 ;
F_139 ( V_35 , abort ) ;
F_10 ( V_14 , V_48 ,
F_24 ( V_35 ) ) ;
F_14 ( V_8 , V_49 ) ;
F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
return V_50 ;
}
T_2 F_140 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
V_167 * V_190 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_212 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
F_104 ( V_190 , V_2 -> V_5 ) ;
if ( ( void * ) V_190 != ( void * ) V_2 -> V_232 )
return F_63 ( V_8 , V_10 , V_12 , type , V_13 ,
( void * ) V_190 , V_14 ) ;
F_10 ( V_14 , V_279 ,
F_34 ( V_2 ) ) ;
return V_50 ;
}
T_2 F_141 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
struct V_1 * V_112 ;
struct V_15 * V_16 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_18 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_16 = F_9 ( V_12 , 0 , V_19 ,
0 , 0 , 0 , NULL , V_20 ) ;
if ( ! V_16 )
goto V_59;
V_112 = F_142 ( V_12 , V_2 ) ;
if ( ! V_112 )
goto V_280;
F_10 ( V_14 , V_21 , F_11 ( V_16 ) ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_23 ) ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_24 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_26 ) ) ;
F_14 ( V_8 , V_27 ) ;
F_15 ( V_8 , V_28 ) ;
F_10 ( V_14 , V_62 , F_34 ( V_112 ) ) ;
F_10 ( V_14 , V_29 , F_16 () ) ;
return V_30 ;
V_280:
F_52 ( V_16 ) ;
V_59:
return V_51 ;
}
T_2 F_85 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
struct V_281 * V_55 = V_2 -> V_55 ;
struct V_18 * V_282 ;
V_167 * V_190 ;
V_47 * V_283 ;
int V_284 = 0 ;
int V_285 = 0 ;
F_14 ( V_8 , V_40 ) ;
V_282 = (struct V_18 * ) V_2 -> V_5 ;
do {
if ( F_2 ( V_282 -> V_6 ) < sizeof( * V_282 ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_283 = ( ( V_47 * ) V_282 ) + F_143 ( F_2 ( V_282 -> V_6 ) ) ;
if ( V_283 > F_144 ( V_55 ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
if ( V_286 == V_282 -> type )
V_284 = 1 ;
if ( V_67 == V_282 -> type )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( V_287 == V_282 -> type )
V_285 = 1 ;
if ( V_288 == V_282 -> type ) {
F_104 (err, ch) {
if ( V_213 == V_190 -> V_168 ) {
V_285 = 1 ;
break;
}
}
}
V_282 = (struct V_18 * ) V_283 ;
} while ( V_283 < F_144 ( V_55 ) );
if ( V_284 )
return F_145 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
else if ( V_285 )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
else
return F_19 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
static T_2 F_145 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_34 * V_35 = NULL ;
struct V_1 * V_2 = V_13 ;
struct V_1 * V_289 ;
V_35 = F_135 ( V_8 , V_12 , V_2 ) ;
if ( ! V_35 )
return V_51 ;
V_289 = F_142 ( V_12 , V_2 ) ;
if ( ! V_289 ) {
F_137 ( V_35 ) ;
return V_51 ;
}
if ( F_138 ( V_289 ) )
V_35 -> V_42 = F_106 ( V_2 -> V_41 -> V_42 ) ;
V_289 -> V_55 -> V_45 = V_10 -> V_44 . V_45 ;
F_139 ( V_35 , V_289 ) ;
F_10 ( V_14 , V_48 ,
F_24 ( V_35 ) ) ;
F_14 ( V_8 , V_49 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_18 ) ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_146 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
if ( ! F_1 ( V_2 , sizeof( struct V_18 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
F_14 ( V_8 , V_40 ) ;
return F_145 ( V_8 , V_10 , NULL , type , V_13 , V_14 ) ;
}
T_2 F_147 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type , void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
struct V_1 * V_290 = NULL ;
struct V_127 * V_291 = NULL ;
T_19 * V_292 ;
T_14 V_293 ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_257 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! V_8 -> V_38 . V_294 && ! V_2 -> V_93 )
return F_86 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_295 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_292 = ( T_19 * ) V_2 -> V_55 -> V_56 ;
V_293 = F_106 ( V_292 -> V_293 ) ;
if ( ! F_148 ( V_12 , V_2 , true , & V_291 ) )
return F_63 ( V_8 , V_10 , V_12 , type , V_13 ,
( void * ) V_291 , V_14 ) ;
if ( V_293 == V_12 -> V_96 . V_296 + 1 ) {
if ( ! V_2 -> V_297 )
F_149 ( V_12 ) ;
V_290 = F_150 ( (struct V_11 * )
V_12 , V_2 ) ;
if ( ! V_290 )
return V_51 ;
} else if ( V_293 < V_12 -> V_96 . V_296 + 1 ) {
V_290 = F_151 ( V_12 , V_292 -> V_293 ) ;
if ( ! V_290 )
return V_137 ;
V_290 -> V_70 = NULL ;
} else {
return V_137 ;
}
V_290 -> V_211 = V_2 -> V_298 ;
F_10 ( V_14 , V_62 , F_34 ( V_290 ) ) ;
if ( V_12 -> V_299 ) {
F_54 ( V_10 , V_12 , type , V_12 -> V_299 , V_14 ) ;
( (struct V_11 * ) V_12 ) -> V_299 = NULL ;
}
return V_50 ;
}
T_2 F_152 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type , void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_290 = V_13 ;
struct V_1 * V_300 = V_12 -> V_301 ;
struct V_1 * abort ;
struct V_127 * V_291 = NULL ;
T_19 * V_302 ;
T_14 V_303 , V_304 ;
if ( ! F_37 ( V_290 , V_12 ) ) {
F_10 ( V_14 , V_257 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! V_8 -> V_38 . V_294 && ! V_290 -> V_93 )
return F_86 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_290 , sizeof( V_295 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_302 = ( T_19 * ) V_290 -> V_55 -> V_56 ;
V_304 = F_106 ( V_302 -> V_293 ) ;
if ( ! F_148 ( V_12 , V_290 , false , & V_291 ) )
return F_63 ( V_8 , V_10 , V_12 , type , V_13 ,
( void * ) V_291 , V_14 ) ;
if ( V_300 ) {
V_302 = ( T_19 * ) V_300 -> V_52 . V_302 ;
V_303 = F_106 ( V_302 -> V_293 ) ;
} else {
V_303 = V_12 -> V_296 - 1 ;
}
if ( F_153 ( V_304 , V_303 + 1 ) &&
! ( V_12 -> V_301 ) ) {
abort = F_136 ( V_12 , V_290 ,
sizeof( V_167 ) ) ;
if ( abort ) {
F_154 ( abort , V_305 , 0 ) ;
F_10 ( V_14 , V_62 ,
F_34 ( abort ) ) ;
}
F_10 ( V_14 , V_22 ,
F_12 ( V_197 ) ) ;
F_10 ( V_14 , V_171 , F_16 () ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_306 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_305 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_234 ;
}
if ( ( V_304 == V_303 ) && V_12 -> V_301 ) {
F_10 ( V_14 , V_22 ,
F_12 ( V_197 ) ) ;
if ( ! F_155 ( (struct V_11 * ) V_12 ,
V_290 ) ) {
F_10 ( V_14 , V_307 ,
F_16 () ) ;
return V_50 ;
}
abort = F_136 ( V_12 , V_290 ,
sizeof( V_167 ) ) ;
if ( abort ) {
F_154 ( abort , V_308 , 0 ) ;
F_10 ( V_14 , V_62 ,
F_34 ( abort ) ) ;
}
F_10 ( V_14 , V_171 , F_16 () ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_306 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_305 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_234 ;
}
return V_137 ;
}
T_2 F_156 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type , void * V_13 ,
T_4 * V_14 )
{
struct V_127 * V_291 = NULL ;
struct V_1 * V_2 = V_13 ;
struct V_309 * V_292 ;
union V_310 V_311 ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_257 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! F_1 ( V_2 , sizeof( * V_292 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
if ( ! F_157 ( V_12 , V_2 , & V_291 ) )
return F_63 ( V_8 , V_10 , V_12 , type , V_13 ,
( void * ) V_291 , V_14 ) ;
V_292 = (struct V_309 * ) V_2 -> V_5 ;
F_158 (param, hdr, params) {
struct V_1 * V_112 = NULL ;
struct V_15 * V_16 = NULL ;
if ( V_311 . V_312 -> type == V_313 )
V_112 = F_159 (
(struct V_11 * ) V_12 , V_311 , & V_16 ) ;
else if ( V_311 . V_312 -> type == V_314 )
V_112 = F_160 (
(struct V_11 * ) V_12 , V_311 , & V_16 ) ;
else if ( V_311 . V_312 -> type == V_315 )
V_112 = F_161 (
(struct V_11 * ) V_12 , V_311 , & V_16 ) ;
else if ( V_311 . V_312 -> type == V_316 )
V_112 = F_162 (
(struct V_11 * ) V_12 , V_311 , & V_16 ) ;
else if ( V_311 . V_312 -> type == V_317 )
V_112 = F_163 (
(struct V_11 * ) V_12 , V_311 , & V_16 ) ;
else if ( V_311 . V_312 -> type == V_318 )
V_112 = F_164 (
(struct V_11 * ) V_12 , V_311 , & V_16 ) ;
if ( V_16 )
F_10 ( V_14 , V_21 ,
F_11 ( V_16 ) ) ;
if ( V_112 )
F_10 ( V_14 , V_62 ,
F_34 ( V_112 ) ) ;
}
return V_50 ;
}
T_2 F_165 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
struct V_319 * V_320 ;
struct V_321 * V_322 ;
T_1 V_37 ;
T_14 V_323 ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_257 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! V_12 -> V_96 . V_324 )
return F_166 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_325 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_320 = (struct V_319 * ) V_2 -> V_55 -> V_56 ;
V_2 -> V_52 . V_320 = V_320 ;
V_37 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_37 -= sizeof( struct V_18 ) ;
F_25 ( V_2 -> V_55 , V_37 ) ;
V_323 = F_106 ( V_320 -> V_326 ) ;
F_69 ( L_7 , V_142 , V_323 ) ;
if ( F_167 ( & V_12 -> V_96 . V_327 , V_323 ) < 0 )
goto V_262;
F_168 (skip, chunk) {
if ( F_2 ( V_322 -> V_328 ) >= V_12 -> V_328 . V_329 )
goto V_262;
}
F_10 ( V_14 , V_330 , F_124 ( V_323 ) ) ;
if ( V_37 > sizeof( struct V_319 ) )
F_10 ( V_14 , V_331 ,
F_34 ( V_2 ) ) ;
if ( V_12 -> V_108 [ V_109 ] ) {
F_10 ( V_14 , V_248 ,
F_12 ( V_109 ) ) ;
}
F_10 ( V_14 , V_273 , F_127 () ) ;
return V_50 ;
V_262:
return V_137 ;
}
T_2 F_169 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
struct V_319 * V_320 ;
struct V_321 * V_322 ;
T_1 V_37 ;
T_14 V_323 ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_257 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! V_12 -> V_96 . V_324 )
return F_166 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_325 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_320 = (struct V_319 * ) V_2 -> V_55 -> V_56 ;
V_2 -> V_52 . V_320 = V_320 ;
V_37 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_37 -= sizeof( struct V_18 ) ;
F_25 ( V_2 -> V_55 , V_37 ) ;
V_323 = F_106 ( V_320 -> V_326 ) ;
F_69 ( L_7 , V_142 , V_323 ) ;
if ( F_167 ( & V_12 -> V_96 . V_327 , V_323 ) < 0 )
goto V_332;
F_168 (skip, chunk) {
if ( F_2 ( V_322 -> V_328 ) >= V_12 -> V_328 . V_329 )
goto V_332;
}
F_10 ( V_14 , V_330 , F_124 ( V_323 ) ) ;
if ( V_37 > sizeof( struct V_319 ) )
F_10 ( V_14 , V_331 ,
F_34 ( V_2 ) ) ;
V_332:
F_10 ( V_14 , V_274 , F_16 () ) ;
F_10 ( V_14 , V_273 , F_131 () ) ;
F_10 ( V_14 , V_248 ,
F_12 ( V_23 ) ) ;
return V_50 ;
}
static T_7 F_49 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
struct V_1 * V_2 )
{
struct V_333 * V_334 ;
struct V_335 * V_336 ;
unsigned int V_337 ;
T_1 V_338 ;
V_47 * V_339 ;
V_47 * V_340 ;
V_334 = (struct V_333 * ) V_2 -> V_55 -> V_56 ;
V_2 -> V_52 . V_334 = V_334 ;
F_25 ( V_2 -> V_55 , sizeof( struct V_333 ) ) ;
if ( ! F_170 ( V_12 , V_334 -> V_341 ) )
return V_342 ;
V_338 = F_2 ( V_334 -> V_343 ) ;
if ( V_338 != V_12 -> V_344 && ! F_171 ( V_12 , V_338 ) )
return V_345 ;
V_337 = F_2 ( V_2 -> V_5 -> V_6 ) - sizeof( V_346 ) ;
V_336 = F_172 ( F_2 ( V_334 -> V_341 ) ) ;
if ( V_337 != V_336 -> V_347 )
return V_267 ;
V_340 = V_334 -> V_336 ;
F_25 ( V_2 -> V_55 , V_337 ) ;
V_339 = F_173 ( V_340 , V_337 , V_20 ) ;
if ( ! V_339 )
goto V_59;
memset ( V_340 , 0 , V_337 ) ;
F_174 ( V_12 , V_2 -> V_55 ,
(struct V_348 * ) V_2 -> V_5 ,
V_20 ) ;
if ( memcmp ( V_339 , V_340 , V_337 ) ) {
F_175 ( V_339 ) ;
return V_89 ;
}
F_175 ( V_339 ) ;
V_2 -> V_93 = 1 ;
return V_98 ;
V_59:
return V_87 ;
}
T_2 F_176 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_333 * V_334 ;
struct V_1 * V_2 = V_13 ;
struct V_1 * V_33 ;
T_7 error ;
if ( ! V_12 -> V_96 . V_97 )
return F_166 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_257 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_348 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_334 = (struct V_333 * ) V_2 -> V_55 -> V_56 ;
error = F_49 ( V_8 , V_10 , V_12 , type , V_2 ) ;
switch ( error ) {
case V_342 :
V_33 = F_90 ( V_12 , V_2 ,
V_349 ,
& V_334 -> V_341 ,
sizeof( T_1 ) , 0 ) ;
if ( V_33 ) {
F_10 ( V_14 , V_62 ,
F_34 ( V_33 ) ) ;
}
case V_345 :
case V_89 :
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
case V_267 :
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
case V_87 :
return V_51 ;
default:
break;
}
if ( V_12 -> V_344 != F_2 ( V_334 -> V_343 ) ) {
struct V_15 * V_16 ;
V_16 = F_177 ( V_12 , F_2 ( V_334 -> V_343 ) ,
V_350 , V_20 ) ;
if ( ! V_16 )
return - V_351 ;
F_10 ( V_14 , V_21 ,
F_11 ( V_16 ) ) ;
}
return V_50 ;
}
T_2 F_166 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_352 = V_13 ;
struct V_1 * V_33 ;
struct V_18 * V_292 ;
F_69 ( L_8 , V_142 , type . V_2 ) ;
if ( ! F_37 ( V_352 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_352 , sizeof( * V_292 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
switch ( type . V_2 & V_353 ) {
case V_354 :
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
case V_355 :
V_292 = V_352 -> V_5 ;
V_33 = F_90 ( V_12 , V_352 ,
V_356 , V_292 ,
F_143 ( F_2 ( V_292 -> V_6 ) ) ,
0 ) ;
if ( V_33 ) {
F_10 ( V_14 , V_62 ,
F_34 ( V_33 ) ) ;
}
F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
return V_50 ;
case V_357 :
return V_137 ;
case V_358 :
V_292 = V_352 -> V_5 ;
V_33 = F_90 ( V_12 , V_352 ,
V_356 , V_292 ,
F_143 ( F_2 ( V_292 -> V_6 ) ) ,
0 ) ;
if ( V_33 ) {
F_10 ( V_14 , V_62 ,
F_34 ( V_33 ) ) ;
}
return V_50 ;
default:
break;
}
return V_137 ;
}
T_2 F_86 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
if ( ! F_1 ( V_2 , sizeof( struct V_18 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
F_69 ( L_9 , V_142 , type . V_2 ) ;
return V_137 ;
}
T_2 F_6 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_14 ( V_8 , V_359 ) ;
F_10 ( V_14 , V_171 , F_16 () ) ;
return V_50 ;
}
T_2 F_178 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
if ( ! F_1 ( V_2 , sizeof( struct V_18 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
return V_360 ;
}
static T_2 F_129 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
void * V_13 ,
T_4 * V_14 ,
const V_47 * V_361 ,
const T_8 V_128 )
{
struct V_34 * V_35 = NULL ;
struct V_1 * V_2 = V_13 ;
struct V_1 * abort = NULL ;
if ( F_38 ( V_67 , V_12 ) )
goto V_362;
abort = F_179 ( V_12 , V_2 , V_361 , V_128 ) ;
if ( ! abort )
goto V_59;
if ( V_12 ) {
if ( V_2 -> V_5 -> type == V_363 &&
! V_12 -> V_96 . V_364 . V_365 ) {
V_64 * V_366 ;
V_366 = ( V_64 * ) V_2 -> V_5 ;
if ( ! F_1 ( V_2 ,
sizeof( V_64 ) ) )
abort -> V_5 -> V_270 |= V_367 ;
else {
unsigned int V_368 ;
V_368 = F_106 ( V_366 -> V_53 . V_365 ) ;
F_10 ( V_14 , V_369 ,
F_124 ( V_368 ) ) ;
}
}
F_10 ( V_14 , V_62 , F_34 ( abort ) ) ;
F_14 ( V_8 , V_49 ) ;
if ( V_12 -> V_178 <= V_76 ) {
F_10 ( V_14 , V_22 ,
F_12 ( V_73 ) ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_69 ) ) ;
F_10 ( V_14 , V_221 ,
F_59 ( V_370 ) ) ;
} else {
F_10 ( V_14 , V_116 ,
F_58 ( V_306 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_370 ) ) ;
F_15 ( V_8 , V_28 ) ;
}
} else {
V_35 = F_135 ( V_8 , V_12 , V_2 ) ;
if ( ! V_35 )
goto V_371;
if ( F_138 ( abort ) )
V_35 -> V_42 = F_106 ( V_2 -> V_41 -> V_42 ) ;
abort -> V_55 -> V_45 = V_10 -> V_44 . V_45 ;
F_139 ( V_35 , abort ) ;
F_10 ( V_14 , V_48 ,
F_24 ( V_35 ) ) ;
F_14 ( V_8 , V_49 ) ;
}
F_14 ( V_8 , V_68 ) ;
V_362:
F_6 ( V_8 , V_10 , V_12 , F_89 ( 0 ) , V_13 , V_14 ) ;
return V_234 ;
V_371:
F_23 ( abort ) ;
V_59:
return V_51 ;
}
static T_2 F_8 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
static const char V_372 [] = L_10 ;
return F_129 ( V_8 , V_10 , V_12 , V_13 , V_14 , V_372 ,
sizeof( V_372 ) ) ;
}
static T_2 F_63 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 , void * V_373 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
struct V_127 * V_311 = V_373 ;
struct V_1 * abort = NULL ;
if ( F_38 ( V_67 , V_12 ) )
goto V_362;
abort = F_180 ( V_12 , V_2 , V_311 ) ;
if ( ! abort )
goto V_59;
F_10 ( V_14 , V_62 , F_34 ( abort ) ) ;
F_14 ( V_8 , V_49 ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_306 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_370 ) ) ;
F_15 ( V_8 , V_28 ) ;
F_14 ( V_8 , V_68 ) ;
V_362:
F_6 ( V_8 , V_10 , V_12 , F_89 ( 0 ) , V_13 , V_14 ) ;
return V_234 ;
V_59:
return V_51 ;
}
static T_2 F_115 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
static const char V_372 [] = L_11 ;
return F_129 ( V_8 , V_10 , V_12 , V_13 , V_14 , V_372 ,
sizeof( V_372 ) ) ;
}
static T_2 F_7 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
static const char V_372 [] = L_12 ;
if ( ! V_12 )
return F_178 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
return F_129 ( V_8 , V_10 , V_12 , V_13 , V_14 , V_372 ,
sizeof( V_372 ) ) ;
}
T_2 F_181 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_31 ;
struct V_11 * V_374 ;
F_10 ( V_14 , V_25 ,
F_13 ( V_179 ) ) ;
V_31 = F_108 ( V_12 , & V_12 -> V_44 . V_210 , V_20 , 0 ) ;
if ( ! V_31 )
goto V_59;
F_10 ( V_14 , V_375 ,
F_34 ( V_31 ) ) ;
V_374 = (struct V_11 * ) V_12 ;
F_10 ( V_14 , V_61 , F_33 ( V_374 ) ) ;
F_10 ( V_14 , V_74 ,
F_12 ( V_73 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
return V_50 ;
V_59:
return V_51 ;
}
T_2 F_182 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_376 * V_377 = V_13 ;
F_10 ( V_14 , V_378 , F_183 ( V_377 ) ) ;
return V_50 ;
}
T_2 F_184 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
int V_191 ;
F_10 ( V_14 , V_25 ,
F_13 ( V_379 ) ) ;
V_191 = V_50 ;
if ( F_117 ( & V_12 -> V_245 ) ) {
V_191 = F_92 ( V_8 , V_10 , V_12 , type ,
V_13 , V_14 ) ;
}
return V_191 ;
}
T_2 F_185 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * abort = V_13 ;
if ( abort )
F_10 ( V_14 , V_62 , F_34 ( abort ) ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_306 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_380 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_234 ;
}
T_2 F_186 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_10 ( V_14 , V_381 , F_58 ( - V_382 ) ) ;
return V_50 ;
}
T_2 F_187 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_10 ( V_14 , V_381 ,
F_58 ( - V_383 ) ) ;
return V_50 ;
}
T_2 F_188 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_10 ( V_14 , V_22 ,
F_12 ( V_73 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_26 ) ) ;
F_14 ( V_8 , V_27 ) ;
F_10 ( V_14 , V_29 , F_16 () ) ;
return V_30 ;
}
T_2 F_189 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 , T_4 * V_14 )
{
return F_188 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_190 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * abort = V_13 ;
F_10 ( V_14 , V_22 ,
F_12 ( V_73 ) ) ;
if ( abort )
F_10 ( V_14 , V_62 , F_34 ( abort ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_26 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_69 ) ) ;
F_10 ( V_14 , V_221 ,
F_59 ( V_380 ) ) ;
return V_234 ;
}
T_2 F_191 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return F_190 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_192 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_10 ( V_14 , V_22 ,
F_12 ( V_24 ) ) ;
return F_185 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_193 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_10 ( V_14 , V_22 ,
F_12 ( V_23 ) ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_24 ) ) ;
return F_185 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_194 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return F_193 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_195 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
if ( V_51 == F_54 ( V_10 , V_12 , type ,
(struct V_111 * ) V_13 , V_14 ) )
return V_51 ;
F_10 ( V_14 , V_122 ,
F_56 ( V_13 ) ) ;
return V_50 ;
}
T_2 F_196 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
F_10 ( V_14 , V_384 , F_34 ( V_2 ) ) ;
F_10 ( V_14 , V_74 ,
F_12 ( V_197 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_2 ) ) ;
return V_50 ;
}
T_2 F_197 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 , T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
F_10 ( V_14 , V_62 , F_34 ( V_2 ) ) ;
return V_50 ;
}
T_2 F_198 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_69 ( L_13 , V_142 ,
type . V_385 ) ;
return V_137 ;
}
T_2 F_199 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_15 * V_386 ;
V_386 = F_200 ( V_12 , V_20 ) ;
if ( ! V_386 )
return V_51 ;
F_10 ( V_14 , V_21 , F_11 ( V_386 ) ) ;
return V_50 ;
}
T_2 F_92 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_112 ;
V_112 = F_201 ( V_12 , NULL ) ;
if ( ! V_112 )
goto V_59;
F_10 ( V_14 , V_247 , F_34 ( V_112 ) ) ;
F_10 ( V_14 , V_74 ,
F_12 ( V_23 ) ) ;
F_10 ( V_14 , V_248 ,
F_12 ( V_24 ) ) ;
if ( V_12 -> V_108 [ V_109 ] )
F_10 ( V_14 , V_22 ,
F_12 ( V_109 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_387 ) ) ;
F_10 ( V_14 , V_227 , F_16 () ) ;
F_10 ( V_14 , V_62 , F_34 ( V_112 ) ) ;
return V_50 ;
V_59:
return V_51 ;
}
T_2 F_118 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 ;
struct V_1 * V_112 ;
if ( V_2 ) {
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_239 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
}
V_112 = F_121 ( V_12 , V_2 ) ;
if ( ! V_112 )
goto V_59;
F_10 ( V_14 , V_247 , F_34 ( V_112 ) ) ;
F_10 ( V_14 , V_248 ,
F_12 ( V_23 ) ) ;
if ( V_12 -> V_108 [ V_109 ] )
F_10 ( V_14 , V_22 ,
F_12 ( V_109 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_388 ) ) ;
F_10 ( V_14 , V_227 , F_16 () ) ;
F_10 ( V_14 , V_62 , F_34 ( V_112 ) ) ;
return V_50 ;
V_59:
return V_51 ;
}
T_2 F_202 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_69 ( L_14 ,
V_142 , type . V_389 ) ;
return V_137 ;
}
T_2 F_203 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_111 * V_70 = V_13 ;
F_14 ( V_8 , V_390 ) ;
if ( V_12 -> V_114 >= V_12 -> V_115 ) {
if ( V_12 -> V_96 . V_391 &&
V_12 -> V_178 == V_379 ) {
F_10 ( V_14 , V_392 ,
F_12 ( V_24 ) ) ;
} else {
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_119 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_30 ;
}
}
F_10 ( V_14 , V_126 , F_56 ( V_70 ) ) ;
F_10 ( V_14 , V_393 , F_56 ( V_70 ) ) ;
return V_50 ;
}
T_2 F_204 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_14 ( V_8 , V_394 ) ;
F_10 ( V_14 , V_273 , F_131 () ) ;
return V_50 ;
}
T_2 F_205 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_31 = NULL ;
struct V_216 * V_217 ;
int V_218 = V_12 -> V_219 + 1 ;
F_69 ( L_15 , V_142 ) ;
F_14 ( V_8 , V_395 ) ;
if ( V_218 <= V_12 -> V_220 ) {
V_217 = (struct V_216 * ) & V_12 -> V_44 . V_210 ;
V_31 = F_108 ( V_12 , V_217 , V_20 , 0 ) ;
if ( ! V_31 )
return V_51 ;
F_10 ( V_14 , V_375 ,
F_34 ( V_31 ) ) ;
F_10 ( V_14 , V_396 ,
F_12 ( V_73 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
} else {
F_69 ( L_16
L_17 , V_142 , V_218 ,
V_12 -> V_220 ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_221 ,
F_59 ( V_119 ) ) ;
return V_30 ;
}
return V_50 ;
}
T_2 F_206 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_31 = NULL ;
int V_218 = V_12 -> V_219 + 1 ;
F_69 ( L_18 , V_142 ) ;
F_14 ( V_8 , V_397 ) ;
if ( V_218 <= V_12 -> V_220 ) {
V_31 = F_207 ( V_12 , NULL ) ;
if ( ! V_31 )
return V_51 ;
F_10 ( V_14 , V_375 ,
F_34 ( V_31 ) ) ;
F_10 ( V_14 , V_398 ,
F_12 ( V_75 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
} else {
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_221 ,
F_59 ( V_119 ) ) ;
return V_30 ;
}
return V_50 ;
}
T_2 F_208 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_112 = NULL ;
F_69 ( L_19 , V_142 ) ;
F_14 ( V_8 , V_399 ) ;
( (struct V_11 * ) V_12 ) -> V_400 ++ ;
if ( V_12 -> V_114 >= V_12 -> V_115 ) {
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_119 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_30 ;
}
switch ( V_12 -> V_178 ) {
case V_387 :
V_112 = F_201 ( V_12 , NULL ) ;
break;
case V_388 :
V_112 = F_121 ( V_12 , NULL ) ;
break;
default:
F_130 () ;
break;
}
if ( ! V_112 )
goto V_59;
if ( V_12 -> V_401 )
F_10 ( V_14 , V_126 ,
F_56 ( V_12 -> V_401 ) ) ;
F_10 ( V_14 , V_247 , F_34 ( V_112 ) ) ;
F_10 ( V_14 , V_248 ,
F_12 ( V_23 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_112 ) ) ;
return V_50 ;
V_59:
return V_51 ;
}
T_2 F_209 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_12 -> V_301 ;
struct V_111 * V_70 = V_2 -> V_70 ;
F_14 ( V_8 , V_402 ) ;
if ( V_70 )
F_10 ( V_14 , V_126 ,
F_56 ( V_70 ) ) ;
F_10 ( V_14 , V_384 , F_34 ( V_2 ) ) ;
if ( V_12 -> V_114 >= V_12 -> V_115 ) {
F_10 ( V_14 , V_22 ,
F_12 ( V_197 ) ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_119 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_234 ;
}
F_61 ( V_12 -> V_301 ) ;
F_10 ( V_14 , V_62 ,
F_34 ( V_12 -> V_301 ) ) ;
F_10 ( V_14 , V_248 ,
F_12 ( V_197 ) ) ;
return V_50 ;
}
T_2 F_210 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_112 = NULL ;
F_69 ( L_20 , V_142 ) ;
F_14 ( V_8 , V_403 ) ;
V_112 = F_136 ( V_12 , NULL , 0 ) ;
if ( ! V_112 )
goto V_59;
F_10 ( V_14 , V_62 , F_34 ( V_112 ) ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_119 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_30 ;
V_59:
return V_51 ;
}
T_2 F_211 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
int V_191 ;
F_14 ( V_8 , V_404 ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_379 ) ) ;
V_191 = V_50 ;
if ( F_117 ( & V_12 -> V_245 ) ) {
V_191 = F_92 ( V_8 , V_10 , V_12 , type ,
V_13 , V_14 ) ;
}
return V_191 ;
}
T_2 F_212 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return V_405 ;
}
T_2 F_213 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return V_406 ;
}
T_2 F_214 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_69 ( L_21 , V_142 , type . V_2 ) ;
return V_50 ;
}
static struct V_407 * F_134 ( struct V_1 * V_2 )
{
struct V_407 * V_408 ;
unsigned int V_37 ;
T_1 V_409 ;
T_1 V_410 ;
V_408 = (struct V_407 * ) V_2 -> V_55 -> V_56 ;
V_409 = F_2 ( V_408 -> V_411 ) ;
V_410 = F_2 ( V_408 -> V_410 ) ;
V_37 = sizeof( struct V_407 ) ;
V_37 += ( V_409 + V_410 ) * sizeof( T_14 ) ;
if ( V_37 > V_2 -> V_55 -> V_37 )
return NULL ;
F_25 ( V_2 -> V_55 , V_37 ) ;
return V_408 ;
}
static struct V_34 * F_22 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
struct V_1 * V_2 ,
const void * V_361 ,
T_8 V_128 )
{
struct V_34 * V_35 ;
struct V_1 * abort ;
V_35 = F_135 ( V_8 , V_12 , V_2 ) ;
if ( V_35 ) {
abort = F_136 ( V_12 , V_2 , V_128 ) ;
if ( ! abort ) {
F_137 ( V_35 ) ;
return NULL ;
}
if ( F_138 ( abort ) )
V_35 -> V_42 = F_106 ( V_2 -> V_41 -> V_42 ) ;
F_32 ( abort , V_128 , V_361 ) ;
abort -> V_55 -> V_45 = V_10 -> V_44 . V_45 ;
F_139 ( V_35 , abort ) ;
}
return V_35 ;
}
static struct V_34 * F_135 ( struct V_8 * V_8 ,
const struct V_11 * V_12 ,
const struct V_1 * V_2 )
{
struct V_34 * V_35 ;
struct V_111 * V_70 ;
T_1 V_412 ;
T_1 V_413 ;
T_14 V_42 ;
V_412 = F_2 ( V_2 -> V_41 -> V_211 ) ;
V_413 = F_2 ( V_2 -> V_41 -> V_298 ) ;
if ( V_12 ) {
switch ( V_2 -> V_5 -> type ) {
case V_363 :
{
V_64 * V_366 ;
V_366 = ( V_64 * ) V_2 -> V_5 ;
V_42 = F_106 ( V_366 -> V_53 . V_365 ) ;
break;
}
default:
V_42 = V_12 -> V_96 . V_364 . V_365 ;
break;
}
} else {
switch ( V_2 -> V_5 -> type ) {
case V_414 :
{
struct V_43 * V_155 ;
V_155 = (struct V_43 * ) V_2 -> V_5 ;
V_42 = F_106 ( V_155 -> V_53 . V_365 ) ;
break;
}
default:
V_42 = F_106 ( V_2 -> V_41 -> V_42 ) ;
break;
}
}
V_70 = F_215 ( V_8 , F_29 ( V_2 ) , V_20 ) ;
if ( ! V_70 )
goto V_59;
F_216 ( V_70 , (union V_132 * ) & V_2 -> V_211 ,
F_18 ( V_8 -> V_38 . V_39 ) ) ;
V_35 = & V_70 -> V_35 ;
F_217 ( V_35 , V_70 , V_412 , V_413 ) ;
F_218 ( V_35 , V_42 , 0 ) ;
return V_35 ;
V_59:
return NULL ;
}
void F_137 ( struct V_34 * V_35 )
{
F_219 ( V_35 -> V_70 ) ;
}
static void F_46 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const struct V_1 * V_2 ,
T_4 * V_14 ,
struct V_1 * V_33 )
{
struct V_34 * V_35 ;
if ( V_33 ) {
V_35 = F_135 ( V_8 , V_12 , V_2 ) ;
if ( V_35 ) {
struct V_86 * V_415 ;
V_415 = V_2 -> V_52 . V_85 ;
V_35 -> V_42 = V_415 -> V_90 . V_183 ;
V_33 -> V_55 -> V_45 = V_10 -> V_44 . V_45 ;
F_139 ( V_35 , V_33 ) ;
F_10 ( V_14 , V_48 ,
F_24 ( V_35 ) ) ;
F_14 ( V_8 , V_49 ) ;
} else
F_23 ( V_33 ) ;
}
}
static int F_128 ( const struct V_11 * V_12 ,
struct V_1 * V_2 ,
T_4 * V_14 )
{
struct V_269 * V_268 ;
struct V_1 * V_190 ;
T_8 V_416 ;
T_20 V_417 ;
int V_418 ;
T_14 V_323 ;
struct V_419 * V_420 = (struct V_419 * ) & V_12 -> V_96 . V_327 ;
struct V_82 * V_45 = V_12 -> V_44 . V_45 ;
struct V_8 * V_8 = F_77 ( V_45 ) ;
T_21 V_421 ;
T_21 V_422 ;
V_223 V_423 = 0 ;
V_268 = (struct V_269 * ) V_2 -> V_55 -> V_56 ;
V_2 -> V_52 . V_268 = V_268 ;
F_25 ( V_2 -> V_55 , sizeof( * V_268 ) ) ;
V_323 = F_106 ( V_268 -> V_323 ) ;
F_69 ( L_7 , V_142 , V_323 ) ;
if ( V_12 -> V_96 . V_424 && ! V_2 -> V_425 ) {
struct V_162 * V_163 = F_220 ( V_2 -> V_55 ) -> V_163 ;
V_2 -> V_425 = 1 ;
if ( V_163 -> V_426 ( F_221 ( V_2 -> V_55 ) ) ) {
F_10 ( V_14 , V_427 ,
F_124 ( V_323 ) ) ;
}
}
V_418 = F_167 ( & V_12 -> V_96 . V_327 , V_323 ) ;
if ( V_418 < 0 ) {
if ( V_2 -> V_12 )
V_2 -> V_12 -> V_428 . V_429 ++ ;
return V_259 ;
} else if ( V_418 > 0 ) {
F_10 ( V_14 , V_430 , F_124 ( V_323 ) ) ;
return V_263 ;
}
V_416 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_416 -= sizeof( struct V_258 ) ;
V_417 = V_431 ;
if ( ( V_416 >= V_12 -> V_184 ) && ( ! V_12 -> V_432 . V_433 ) ) {
F_10 ( V_14 , V_434 , F_16 () ) ;
}
if ( ( ! V_2 -> V_435 ) && ( ! V_12 -> V_184 || V_12 -> V_436 ||
( V_416 > V_12 -> V_184 + V_12 -> V_437 ) ) ) {
if ( F_222 ( V_420 ) &&
( F_223 ( V_420 ) + 1 ) == V_323 ) {
F_69 ( L_22 , V_142 , V_323 ) ;
V_417 = V_438 ;
} else {
F_69 ( L_23 ,
V_142 , V_323 , V_416 , V_12 -> V_184 ) ;
return V_264 ;
}
}
if ( * V_45 -> V_439 -> V_440 ) {
if ( F_222 ( V_420 ) &&
( F_223 ( V_420 ) + 1 ) == V_323 ) {
F_69 ( L_24 ,
V_142 , V_323 ) ;
V_417 = V_438 ;
}
}
if ( F_3 ( 0 == V_416 ) ) {
V_190 = F_224 ( V_12 , V_2 , V_323 ) ;
if ( V_190 ) {
F_10 ( V_14 , V_62 ,
F_34 ( V_190 ) ) ;
}
F_10 ( V_14 , V_171 , F_16 () ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_306 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_441 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_266 ;
}
V_2 -> V_435 = 1 ;
if ( V_2 -> V_5 -> V_270 & V_442 ) {
F_14 ( V_8 , V_443 ) ;
if ( V_2 -> V_12 )
V_2 -> V_12 -> V_428 . V_444 ++ ;
} else {
F_14 ( V_8 , V_445 ) ;
if ( V_2 -> V_12 )
V_2 -> V_12 -> V_428 . V_446 ++ ;
V_423 = 1 ;
}
V_422 = F_2 ( V_268 -> V_328 ) ;
if ( V_422 >= V_12 -> V_328 . V_329 ) {
F_10 ( V_14 , V_447 , F_124 ( V_323 ) ) ;
V_190 = F_90 ( V_12 , V_2 , V_448 ,
& V_268 -> V_328 ,
sizeof( V_268 -> V_328 ) ,
sizeof( T_21 ) ) ;
if ( V_190 )
F_10 ( V_14 , V_62 ,
F_34 ( V_190 ) ) ;
return V_260 ;
}
V_421 = F_2 ( V_268 -> V_421 ) ;
if ( V_423 && F_225 ( V_421 , F_226 ( & V_12 -> V_328 , V_449 , V_422 ) ) )
return V_267 ;
F_10 ( V_14 , V_417 , F_34 ( V_2 ) ) ;
return V_98 ;
}
