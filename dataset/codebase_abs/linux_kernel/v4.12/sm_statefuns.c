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
if ( ! F_1 ( V_2 , sizeof( V_18 ) ) )
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
if ( ! F_1 ( V_2 , sizeof( V_43 ) ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( F_20 ( V_10 -> V_44 . V_45 , V_46 ) )
return F_19 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
V_33 = NULL ;
if ( ! F_21 ( V_8 , V_10 , V_12 , V_2 -> V_5 -> type ,
( V_43 * ) V_2 -> V_5 , V_2 ,
& V_33 ) ) {
if ( V_33 ) {
V_35 = F_22 ( V_8 , V_10 , V_12 , V_13 ,
( V_47 * ) ( V_33 -> V_5 ) +
sizeof( V_18 ) ,
F_2 ( V_33 -> V_5 -> V_6 ) -
sizeof( V_18 ) ) ;
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
V_2 -> V_52 . V_53 = ( V_54 * ) V_2 -> V_55 -> V_56 ;
V_2 -> V_57 . V_58 = F_25 ( V_2 -> V_55 , sizeof( V_54 ) ) ;
V_32 = F_26 ( V_10 , V_2 , V_20 ) ;
if ( ! V_32 )
goto V_59;
if ( F_27 ( V_32 ,
F_28 ( F_29 ( V_2 ) ) ,
V_20 ) < 0 )
goto V_60;
if ( ! F_30 ( V_32 , V_2 , F_29 ( V_2 ) ,
( V_43 * ) V_2 -> V_5 ,
V_20 ) )
goto V_60;
V_37 = 0 ;
if ( V_33 )
V_37 = F_2 ( V_33 -> V_5 -> V_6 ) -
sizeof( V_18 ) ;
V_31 = F_31 ( V_32 , V_2 , V_20 , V_37 ) ;
if ( ! V_31 )
goto V_60;
if ( V_33 ) {
V_36 = ( T_5 * )
( ( V_47 * ) ( V_33 -> V_5 ) +
sizeof( V_18 ) ) ;
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
V_43 * V_63 ;
struct V_1 * V_33 ;
struct V_34 * V_35 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! V_2 -> V_17 )
return F_7 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_64 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_2 -> V_52 . V_53 = ( V_54 * ) V_2 -> V_55 -> V_56 ;
V_33 = NULL ;
if ( ! F_21 ( V_8 , V_10 , V_12 , V_2 -> V_5 -> type ,
( V_43 * ) V_2 -> V_5 , V_2 ,
& V_33 ) ) {
T_6 error = V_65 ;
if ( V_33 ) {
V_35 = F_22 ( V_8 , V_10 , V_12 , V_13 ,
( V_47 * ) ( V_33 -> V_5 ) +
sizeof( V_18 ) ,
F_2 ( V_33 -> V_5 -> V_6 ) -
sizeof( V_18 ) ) ;
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
V_2 -> V_57 . V_58 = F_25 ( V_2 -> V_55 , sizeof( V_54 ) ) ;
V_63 = ( V_43 * ) V_2 -> V_5 ;
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
V_43 * V_79 ;
struct V_1 * V_31 ;
struct V_15 * V_16 , * V_80 = NULL ;
int error = 0 ;
struct V_1 * V_81 ;
struct V_82 * V_45 ;
if ( V_10 == F_18 ( V_8 -> V_38 . V_39 ) -> V_10 ) {
F_14 ( V_8 , V_40 ) ;
return F_19 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! F_1 ( V_2 , sizeof( V_18 ) ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
V_45 = V_10 -> V_44 . V_45 ;
if ( ! F_20 ( V_45 , V_83 ) ||
( F_42 ( V_45 , V_84 ) && F_43 ( V_45 ) ) )
return F_19 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
V_2 -> V_52 . V_85 =
(struct V_86 * ) V_2 -> V_55 -> V_56 ;
if ( ! F_44 ( V_2 -> V_55 , F_2 ( V_2 -> V_5 -> V_6 ) -
sizeof( V_18 ) ) )
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
V_93 . V_5 = ( V_18 * ) F_48 ( V_2 -> V_92 ,
sizeof( V_18 ) ) ;
F_25 ( V_2 -> V_92 , sizeof( V_18 ) ) ;
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
if ( ! F_1 ( V_2 , sizeof( V_18 ) ) )
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
T_8 * V_57 ;
struct V_1 * V_2 = V_13 ;
struct V_1 * V_112 ;
T_9 V_127 = 0 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_128 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_2 -> V_52 . V_129 = ( V_130 * ) V_2 -> V_55 -> V_56 ;
V_57 = ( T_8 * ) V_2 -> V_52 . V_129 ;
V_127 = F_2 ( V_2 -> V_5 -> V_6 ) - sizeof( V_18 ) ;
if ( F_2 ( V_57 -> V_6 ) > V_127 )
return F_63 ( V_8 , V_10 , V_12 , type , V_13 ,
V_57 , V_14 ) ;
if ( ! F_44 ( V_2 -> V_55 , V_127 ) )
goto V_59;
V_112 = F_64 ( V_12 , V_2 , V_57 , V_127 ) ;
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
union V_131 V_132 ;
struct V_111 * V_133 ;
T_10 * V_134 ;
unsigned long V_135 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_18 ) +
sizeof( T_10 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_134 = ( T_10 * ) V_2 -> V_55 -> V_56 ;
if ( F_2 ( V_134 -> V_57 . V_6 ) !=
sizeof( T_10 ) ) {
return V_136 ;
}
V_132 = V_134 -> V_137 ;
V_133 = F_66 ( V_12 , & V_132 ) ;
if ( F_3 ( ! V_133 ) ) {
if ( V_132 . V_138 . V_139 == V_140 ) {
F_67 ( L_1 ,
V_141 ,
V_12 ,
& V_132 . V_142 . V_143 ) ;
} else {
F_67 ( L_2 ,
V_141 ,
V_12 ,
& V_132 . V_144 . V_145 . V_146 ) ;
}
return V_136 ;
}
if ( V_134 -> V_147 != V_133 -> V_147 )
return V_136 ;
V_135 = V_133 -> V_148 + V_133 -> V_149 ;
if ( F_68 ( V_134 -> V_150 , V_151 ) ||
F_68 ( V_151 , V_134 -> V_150 + V_135 ) ) {
F_69 ( L_3
L_4 , V_141 , V_133 ) ;
return V_136 ;
}
F_10 ( V_14 , V_152 , F_56 ( V_133 ) ) ;
return V_50 ;
}
static int F_70 ( struct V_8 * V_8 , union V_131 * V_153 ,
struct V_1 * V_154 ,
T_4 * V_14 )
{
int V_37 ;
struct V_34 * V_155 ;
union V_156 * V_157 ;
struct V_158 * V_159 ;
struct V_9 * V_10 ;
char V_160 [ sizeof( struct V_158 ) + sizeof( union V_156 ) ] ;
struct V_161 * V_162 = F_71 ( V_153 -> V_144 . V_163 ) ;
V_159 = (struct V_158 * ) V_160 ;
V_157 = (union V_156 * ) V_159 -> V_164 ;
V_37 = V_162 -> V_165 ( V_153 , V_157 ) ;
V_37 += sizeof( V_166 ) ;
V_159 -> V_167 = V_168 ;
V_159 -> V_6 = F_72 ( V_37 ) ;
V_10 = F_18 ( V_8 -> V_38 . V_39 ) -> V_10 ;
V_155 = F_22 ( V_8 , V_10 , NULL , V_154 , V_159 , V_37 ) ;
if ( ! V_155 )
goto V_169;
F_10 ( V_14 , V_48 , F_24 ( V_155 ) ) ;
F_14 ( V_8 , V_49 ) ;
F_10 ( V_14 , V_170 , F_16 () ) ;
V_169:
return 0 ;
}
static bool F_73 ( const struct V_171 * V_172 ,
union V_131 * V_173 )
{
struct V_111 * V_174 ;
F_74 (addr, list, transports) {
if ( F_75 ( V_173 , & V_174 -> V_173 ) )
return true ;
}
return false ;
}
static int F_76 ( const struct V_11 * V_32 ,
const struct V_11 * V_12 ,
struct V_1 * V_154 ,
T_4 * V_14 )
{
struct V_8 * V_8 = F_77 ( V_32 -> V_44 . V_45 ) ;
struct V_111 * V_175 ;
int V_94 = 1 ;
F_74 (new_addr, &new_asoc->peer.transport_addr_list,
transports) {
if ( ! F_73 ( & V_12 -> V_96 . V_176 ,
& V_175 -> V_173 ) ) {
F_70 ( V_8 , & V_175 -> V_173 , V_154 ,
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
switch ( V_12 -> V_177 ) {
case V_178 :
V_32 -> V_90 . V_179 = V_12 -> V_90 . V_179 ;
V_32 -> V_90 . V_180 = V_12 -> V_90 . V_179 ;
V_32 -> V_90 . V_181 = 0 ;
break;
case V_76 :
V_32 -> V_90 . V_179 = V_12 -> V_90 . V_179 ;
V_32 -> V_90 . V_180 = V_12 -> V_90 . V_179 ;
V_32 -> V_90 . V_181 = V_12 -> V_90 . V_182 ;
break;
default:
V_32 -> V_90 . V_180 = V_12 -> V_90 . V_179 ;
V_32 -> V_90 . V_181 = V_12 -> V_90 . V_182 ;
break;
}
V_32 -> V_183 = V_12 -> V_183 ;
V_32 -> V_90 . V_100 = V_12 -> V_90 . V_100 ;
V_32 -> V_90 . V_101 = V_12 -> V_90 . V_101 ;
V_32 -> V_90 . V_184 = V_12 -> V_90 . V_184 ;
}
static char F_79 ( struct V_11 * V_32 ,
const struct V_11 * V_12 )
{
if ( ( V_12 -> V_90 . V_179 != V_32 -> V_90 . V_179 ) &&
( V_12 -> V_90 . V_182 != V_32 -> V_90 . V_182 ) &&
( V_12 -> V_90 . V_179 == V_32 -> V_90 . V_180 ) &&
( V_12 -> V_90 . V_182 == V_32 -> V_90 . V_181 ) )
return 'A' ;
if ( ( V_12 -> V_90 . V_179 == V_32 -> V_90 . V_179 ) &&
( ( V_12 -> V_90 . V_182 != V_32 -> V_90 . V_182 ) ||
( 0 == V_12 -> V_90 . V_182 ) ) ) {
return 'B' ;
}
if ( ( V_12 -> V_90 . V_179 == V_32 -> V_90 . V_179 ) &&
( V_12 -> V_90 . V_182 == V_32 -> V_90 . V_182 ) )
return 'D' ;
if ( ( V_12 -> V_90 . V_179 != V_32 -> V_90 . V_179 ) &&
( V_12 -> V_90 . V_182 == V_32 -> V_90 . V_182 ) &&
( 0 == V_32 -> V_90 . V_180 ) &&
( 0 == V_32 -> V_90 . V_181 ) )
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
T_2 V_185 ;
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
if ( ! F_1 ( V_2 , sizeof( V_43 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_2 -> V_52 . V_53 = ( V_54 * ) V_2 -> V_55 -> V_56 ;
V_2 -> V_57 . V_58 = F_25 ( V_2 -> V_55 , sizeof( V_54 ) ) ;
V_33 = NULL ;
if ( ! F_21 ( V_8 , V_10 , V_12 , V_2 -> V_5 -> type ,
( V_43 * ) V_2 -> V_5 , V_2 ,
& V_33 ) ) {
if ( V_33 ) {
V_35 = F_22 ( V_8 , V_10 , V_12 , V_13 ,
( V_47 * ) ( V_33 -> V_5 ) +
sizeof( V_18 ) ,
F_2 ( V_33 -> V_5 -> V_6 ) -
sizeof( V_18 ) ) ;
if ( V_35 ) {
F_10 ( V_14 , V_48 ,
F_24 ( V_35 ) ) ;
F_14 ( V_8 , V_49 ) ;
V_185 = V_50 ;
} else {
V_185 = V_51 ;
}
goto V_186;
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
( V_43 * ) V_2 -> V_5 ,
V_20 ) )
goto V_59;
if ( ! F_81 ( V_12 , V_187 ) ) {
if ( ! F_76 ( V_32 , V_12 , V_2 ,
V_14 ) ) {
V_185 = V_50 ;
goto V_188;
}
}
F_78 ( V_32 , V_12 ) ;
V_37 = 0 ;
if ( V_33 ) {
V_37 = F_2 ( V_33 -> V_5 -> V_6 ) -
sizeof( V_18 ) ;
}
V_31 = F_31 ( V_32 , V_2 , V_20 , V_37 ) ;
if ( ! V_31 )
goto V_59;
if ( V_33 ) {
V_36 = ( T_5 * )
( ( V_47 * ) ( V_33 -> V_5 ) +
sizeof( V_18 ) ) ;
F_32 ( V_31 , V_37 , V_36 ) ;
}
F_10 ( V_14 , V_61 , F_33 ( V_32 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
F_10 ( V_14 , V_29 , F_16 () ) ;
V_185 = V_50 ;
return V_185 ;
V_59:
V_185 = V_51 ;
V_188:
if ( V_32 )
F_35 ( V_32 ) ;
V_186:
if ( V_33 )
F_23 ( V_33 ) ;
return V_185 ;
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
V_43 * V_79 ;
struct V_15 * V_16 ;
struct V_1 * V_31 ;
struct V_1 * V_189 ;
T_2 V_190 ;
V_79 = & V_2 -> V_52 . V_85 -> V_90 . V_79 [ 0 ] ;
if ( ! F_30 ( V_32 , V_2 , F_29 ( V_2 ) , V_79 ,
V_20 ) )
goto V_59;
if ( ! F_76 ( V_32 , V_12 , V_2 , V_14 ) ) {
return V_50 ;
}
if ( F_81 ( V_12 , V_191 ) ) {
V_190 = F_88 ( V_8 , V_10 , V_12 ,
F_89 ( V_2 -> V_5 -> type ) ,
V_2 , V_14 ) ;
if ( V_51 == V_190 )
goto V_59;
V_189 = F_90 ( V_12 , V_2 ,
V_192 ,
NULL , 0 , 0 ) ;
if ( V_189 )
F_10 ( V_14 , V_62 ,
F_34 ( V_189 ) ) ;
return V_50 ;
}
F_10 ( V_14 , V_193 , F_16 () ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_194 ) ) ;
F_10 ( V_14 , V_195 , F_16 () ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_196 ) ) ;
F_10 ( V_14 , V_197 , F_16 () ) ;
V_31 = F_50 ( V_32 , V_2 ) ;
if ( ! V_31 )
goto V_59;
V_16 = F_9 ( V_12 , 0 , V_198 , 0 ,
V_32 -> V_90 . V_100 ,
V_32 -> V_90 . V_101 ,
NULL , V_20 ) ;
if ( ! V_16 )
goto V_102;
F_10 ( V_14 , V_199 , F_33 ( V_32 ) ) ;
F_10 ( V_14 , V_21 , F_11 ( V_16 ) ) ;
if ( F_81 ( V_12 , V_200 ) &&
( F_20 ( V_12 -> V_44 . V_45 , V_46 ) ||
F_91 ( V_12 -> V_44 . V_45 , V_201 ) ) ) {
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
V_43 * V_79 ;
struct V_1 * V_31 ;
V_79 = & V_2 -> V_52 . V_85 -> V_90 . V_79 [ 0 ] ;
if ( ! F_30 ( V_32 , V_2 , F_29 ( V_2 ) , V_79 ,
V_20 ) )
goto V_59;
F_10 ( V_14 , V_199 , F_33 ( V_32 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_105 ) ) ;
F_14 ( V_8 , V_28 ) ;
F_10 ( V_14 , V_107 , F_16 () ) ;
V_31 = F_50 ( V_32 , V_2 ) ;
if ( ! V_31 )
goto V_59;
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
F_10 ( V_14 , V_202 , F_94 ( V_99 ) ) ;
if ( V_12 -> V_96 . V_103 )
F_10 ( V_14 , V_203 , F_16 () ) ;
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
return V_136 ;
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
if ( V_12 -> V_177 < V_105 ) {
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
T_2 V_185 ;
struct V_1 * V_2 = V_13 ;
struct V_11 * V_32 ;
int error = 0 ;
char V_204 ;
struct V_1 * V_81 ;
if ( ! F_1 ( V_2 , sizeof( V_18 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_2 -> V_52 . V_85 = (struct V_86 * ) V_2 -> V_55 -> V_56 ;
if ( ! F_44 ( V_2 -> V_55 , F_2 ( V_2 -> V_5 -> V_6 ) -
sizeof( V_18 ) ) )
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
V_32 -> V_205 = 1 ;
V_204 = F_79 ( V_32 , V_12 ) ;
switch ( V_204 ) {
case 'A' :
V_185 = F_87 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
V_32 ) ;
break;
case 'B' :
V_185 = F_93 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
V_32 ) ;
break;
case 'C' :
V_185 = F_95 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
V_32 ) ;
break;
case 'D' :
V_185 = F_96 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
V_32 ) ;
break;
default:
V_185 = F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
break;
}
F_10 ( V_14 , V_206 , F_33 ( V_32 ) ) ;
F_10 ( V_14 , V_29 , F_16 () ) ;
F_10 ( V_14 , V_206 ,
F_33 ( (struct V_11 * ) V_12 ) ) ;
return V_185 ;
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
if ( ! F_1 ( V_2 , sizeof( V_207 ) ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( V_208 ==
F_99 ( & V_12 -> V_44 . V_209 , & V_2 -> V_210 ) )
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
if ( ! F_1 ( V_2 , sizeof( V_207 ) ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( V_208 ==
F_99 ( & V_12 -> V_44 . V_209 , & V_2 -> V_210 ) )
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
V_166 * V_189 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_211 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
F_104 (err, chunk->chunk_hdr) {
if ( V_212 == V_189 -> V_167 )
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
T_11 V_213 ;
T_12 V_214 ;
V_166 * V_189 ;
struct V_1 * V_112 ;
struct V_215 * V_216 ;
int V_217 = V_12 -> V_218 + 1 ;
if ( V_217 > V_12 -> V_219 ) {
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_220 ,
F_59 ( V_212 ) ) ;
return V_30 ;
}
V_189 = ( V_166 * ) ( V_2 -> V_55 -> V_56 ) ;
V_213 = F_106 ( * ( V_221 * ) ( ( V_222 * ) V_189 + sizeof( V_166 ) ) ) ;
V_213 = ( V_213 * 2 ) / 1000 ;
V_214 . V_57 . type = V_223 ;
V_214 . V_57 . V_6 = F_72 ( sizeof( V_214 ) ) ;
V_214 . V_224 = F_107 ( V_213 ) ;
V_216 = (struct V_215 * ) & V_12 -> V_44 . V_209 ;
V_112 = F_108 ( V_12 , V_216 , V_20 , sizeof( V_214 ) ) ;
if ( ! V_112 )
goto V_59;
F_32 ( V_112 , sizeof( V_214 ) , & V_214 ) ;
F_10 ( V_14 , V_225 , F_16 () ) ;
F_10 ( V_14 , V_193 , F_16 () ) ;
F_10 ( V_14 , V_226 , F_16 () ) ;
F_10 ( V_14 , V_227 , F_16 () ) ;
F_10 ( V_14 , V_228 ,
F_56 ( V_12 -> V_96 . V_229 ) ) ;
F_10 ( V_14 , V_230 , F_16 () ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_75 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_178 ) ) ;
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
if ( ! F_1 ( V_2 , sizeof( V_207 ) ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( V_208 ==
F_99 ( & V_12 -> V_44 . V_209 , & V_2 -> V_210 ) )
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
T_13 error = V_119 ;
V_37 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_37 >= sizeof( struct V_231 ) + sizeof( struct V_158 ) ) {
V_166 * V_189 ;
F_104 ( V_189 , V_2 -> V_5 ) ;
if ( ( void * ) V_189 != ( void * ) V_2 -> V_232 )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
error = ( ( V_166 * ) V_2 -> V_55 -> V_56 ) -> V_167 ;
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
T_13 error = V_119 ;
if ( ! F_5 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_207 ) ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
V_37 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_37 >= sizeof( struct V_231 ) + sizeof( struct V_158 ) )
error = ( ( V_166 * ) V_2 -> V_55 -> V_56 ) -> V_167 ;
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
T_13 error , int V_236 ,
const struct V_11 * V_12 ,
struct V_111 * V_70 )
{
F_69 ( L_5 , V_141 ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_26 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_73 ) ) ;
F_10 ( V_14 , V_116 , F_58 ( V_236 ) ) ;
F_10 ( V_14 , V_220 ,
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
T_14 * V_237 ;
T_2 V_190 ;
struct V_15 * V_16 ;
T_15 V_238 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 ,
sizeof( struct V_239 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_237 = ( T_14 * ) V_2 -> V_55 -> V_56 ;
F_25 ( V_2 -> V_55 , sizeof( T_14 ) ) ;
V_2 -> V_52 . V_240 = V_237 ;
V_238 = F_106 ( V_237 -> V_241 ) ;
if ( F_114 ( V_238 , V_12 -> V_242 ) ) {
F_69 ( L_6 , V_141 , V_238 ,
V_12 -> V_242 ) ;
return V_136 ;
}
if ( ! F_114 ( V_238 , V_12 -> V_243 ) )
return F_115 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
V_16 = F_116 ( V_12 , 0 , V_20 ) ;
if ( ! V_16 ) {
V_190 = V_51 ;
goto V_169;
}
F_10 ( V_14 , V_21 , F_11 ( V_16 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_244 ) ) ;
V_190 = V_50 ;
if ( F_117 ( & V_12 -> V_245 ) ) {
V_190 = F_118 ( V_8 , V_10 , V_12 , type ,
V_13 , V_14 ) ;
}
if ( V_51 == V_190 )
goto V_169;
F_10 ( V_14 , V_246 ,
F_119 ( V_2 -> V_52 . V_240 -> V_241 ) ) ;
V_169:
return V_190 ;
}
T_2 F_120 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
T_14 * V_237 ;
T_15 V_238 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 ,
sizeof( struct V_239 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_237 = ( T_14 * ) V_2 -> V_55 -> V_56 ;
V_238 = F_106 ( V_237 -> V_241 ) ;
if ( F_114 ( V_238 , V_12 -> V_242 ) ) {
F_69 ( L_6 , V_141 , V_238 ,
V_12 -> V_242 ) ;
return V_136 ;
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
if ( ! F_1 ( V_2 , sizeof( V_18 ) ) )
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
T_16 * V_249 ;
struct V_1 * V_2 = V_13 ;
T_11 V_250 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_251 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_249 = ( T_16 * ) V_2 -> V_55 -> V_56 ;
F_25 ( V_2 -> V_55 , sizeof( T_16 ) ) ;
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
T_17 * V_254 ;
struct V_1 * V_2 = V_13 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_251 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_254 = ( T_17 * ) V_2 -> V_55 -> V_56 ;
F_25 ( V_2 -> V_55 , sizeof( T_17 ) ) ;
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
T_18 V_256 = F_127 () ;
int error ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_257 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! F_1 ( V_2 , sizeof( V_258 ) ) )
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
( V_222 * ) V_2 -> V_52 . V_268 , sizeof( V_269 ) ) ;
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
return V_136 ;
V_262:
if ( V_2 -> V_272 )
F_10 ( V_14 , V_273 , V_256 ) ;
return V_136 ;
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
if ( ! F_1 ( V_2 , sizeof( V_258 ) ) )
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
( V_222 * ) V_2 -> V_52 . V_268 , sizeof( V_269 ) ) ;
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
T_19 * V_275 ;
T_15 V_238 ;
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
F_69 ( L_6 , V_141 , V_238 ,
V_12 -> V_242 ) ;
return V_136 ;
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
V_166 * V_189 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_211 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
F_104 ( V_189 , V_2 -> V_5 ) ;
if ( ( void * ) V_189 != ( void * ) V_2 -> V_232 )
return F_63 ( V_8 , V_10 , V_12 , type , V_13 ,
( void * ) V_189 , V_14 ) ;
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
if ( ! F_1 ( V_2 , sizeof( V_18 ) ) )
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
V_18 * V_282 ;
V_166 * V_189 ;
V_47 * V_283 ;
int V_284 = 0 ;
int V_285 = 0 ;
F_14 ( V_8 , V_40 ) ;
V_282 = ( V_18 * ) V_2 -> V_5 ;
do {
if ( F_2 ( V_282 -> V_6 ) < sizeof( V_18 ) )
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
if ( V_212 == V_189 -> V_167 ) {
V_285 = 1 ;
break;
}
}
}
V_282 = ( V_18 * ) V_283 ;
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
if ( ! F_1 ( V_2 , sizeof( V_18 ) ) )
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
if ( ! F_1 ( V_2 , sizeof( V_18 ) ) )
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
struct V_291 * V_292 = NULL ;
T_20 * V_293 ;
T_15 V_294 ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_257 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! V_8 -> V_38 . V_295 && ! V_2 -> V_93 )
return F_86 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_296 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_293 = ( T_20 * ) V_2 -> V_55 -> V_56 ;
V_294 = F_106 ( V_293 -> V_294 ) ;
if ( ! F_148 ( V_12 , V_2 , true , & V_292 ) )
return F_63 ( V_8 , V_10 , V_12 , type , V_13 ,
( void * ) V_292 , V_14 ) ;
if ( V_294 == V_12 -> V_96 . V_297 + 1 ) {
if ( ! V_2 -> V_298 )
F_149 ( V_12 ) ;
V_290 = F_150 ( (struct V_11 * )
V_12 , V_2 ) ;
if ( ! V_290 )
return V_51 ;
} else if ( V_294 < V_12 -> V_96 . V_297 + 1 ) {
V_290 = F_151 ( V_12 , V_293 -> V_294 ) ;
if ( ! V_290 )
return V_136 ;
V_290 -> V_70 = NULL ;
} else {
return V_136 ;
}
V_290 -> V_210 = V_2 -> V_299 ;
F_10 ( V_14 , V_62 , F_34 ( V_290 ) ) ;
if ( V_12 -> V_300 ) {
F_54 ( V_10 , V_12 , type , V_12 -> V_300 , V_14 ) ;
( (struct V_11 * ) V_12 ) -> V_300 = NULL ;
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
struct V_1 * V_301 = V_12 -> V_302 ;
struct V_1 * abort ;
struct V_291 * V_292 = NULL ;
T_20 * V_303 ;
T_15 V_304 , V_305 ;
if ( ! F_37 ( V_290 , V_12 ) ) {
F_10 ( V_14 , V_257 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! V_8 -> V_38 . V_295 && ! V_290 -> V_93 )
return F_86 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_290 , sizeof( V_296 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_303 = ( T_20 * ) V_290 -> V_55 -> V_56 ;
V_305 = F_106 ( V_303 -> V_294 ) ;
if ( ! F_148 ( V_12 , V_290 , false , & V_292 ) )
return F_63 ( V_8 , V_10 , V_12 , type , V_13 ,
( void * ) V_292 , V_14 ) ;
if ( V_301 ) {
V_303 = ( T_20 * ) V_301 -> V_52 . V_303 ;
V_304 = F_106 ( V_303 -> V_294 ) ;
} else {
V_304 = V_12 -> V_297 - 1 ;
}
if ( F_153 ( V_305 , V_304 + 1 ) &&
! ( V_12 -> V_302 ) ) {
abort = F_136 ( V_12 , V_290 ,
sizeof( V_166 ) ) ;
if ( abort ) {
F_154 ( abort , V_306 , 0 ) ;
F_10 ( V_14 , V_62 ,
F_34 ( abort ) ) ;
}
F_10 ( V_14 , V_22 ,
F_12 ( V_196 ) ) ;
F_10 ( V_14 , V_170 , F_16 () ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_307 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_306 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_234 ;
}
if ( ( V_305 == V_304 ) && V_12 -> V_302 ) {
F_10 ( V_14 , V_22 ,
F_12 ( V_196 ) ) ;
if ( ! F_155 ( (struct V_11 * ) V_12 ,
V_290 ) ) {
F_10 ( V_14 , V_308 ,
F_16 () ) ;
return V_50 ;
}
abort = F_136 ( V_12 , V_290 ,
sizeof( V_166 ) ) ;
if ( abort ) {
F_154 ( abort , V_309 , 0 ) ;
F_10 ( V_14 , V_62 ,
F_34 ( abort ) ) ;
}
F_10 ( V_14 , V_170 , F_16 () ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_307 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_306 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_234 ;
}
return V_136 ;
}
T_2 F_156 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type , void * V_13 ,
T_4 * V_14 )
{
struct V_291 * V_292 = NULL ;
struct V_1 * V_2 = V_13 ;
struct V_310 * V_293 ;
union V_311 V_312 ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_257 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! F_1 ( V_2 , sizeof( * V_293 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
if ( ! F_157 ( V_12 , V_2 , & V_292 ) )
return F_63 ( V_8 , V_10 , V_12 , type , V_13 ,
( void * ) V_292 , V_14 ) ;
V_293 = (struct V_310 * ) V_2 -> V_5 ;
F_158 (param, hdr, params) {
struct V_1 * V_112 = NULL ;
struct V_15 * V_16 = NULL ;
if ( V_312 . V_313 -> type == V_314 )
V_112 = F_159 (
(struct V_11 * ) V_12 , V_312 , & V_16 ) ;
else if ( V_312 . V_313 -> type == V_315 )
V_112 = F_160 (
(struct V_11 * ) V_12 , V_312 , & V_16 ) ;
else if ( V_312 . V_313 -> type == V_316 )
V_112 = F_161 (
(struct V_11 * ) V_12 , V_312 , & V_16 ) ;
else if ( V_312 . V_313 -> type == V_317 )
V_112 = F_162 (
(struct V_11 * ) V_12 , V_312 , & V_16 ) ;
else if ( V_312 . V_313 -> type == V_318 )
V_112 = F_163 (
(struct V_11 * ) V_12 , V_312 , & V_16 ) ;
else if ( V_312 . V_313 -> type == V_319 )
V_112 = F_164 (
(struct V_11 * ) V_12 , V_312 , & V_16 ) ;
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
struct V_320 * V_321 ;
struct V_322 * V_323 ;
T_1 V_37 ;
T_15 V_324 ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_257 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! V_12 -> V_96 . V_325 )
return F_166 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_326 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_321 = (struct V_320 * ) V_2 -> V_55 -> V_56 ;
V_2 -> V_52 . V_321 = V_321 ;
V_37 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_37 -= sizeof( struct V_231 ) ;
F_25 ( V_2 -> V_55 , V_37 ) ;
V_324 = F_106 ( V_321 -> V_327 ) ;
F_69 ( L_7 , V_141 , V_324 ) ;
if ( F_167 ( & V_12 -> V_96 . V_328 , V_324 ) < 0 )
goto V_262;
F_168 (skip, chunk) {
if ( F_2 ( V_323 -> V_329 ) >= V_12 -> V_329 -> V_330 )
goto V_262;
}
F_10 ( V_14 , V_331 , F_124 ( V_324 ) ) ;
if ( V_37 > sizeof( struct V_320 ) )
F_10 ( V_14 , V_332 ,
F_34 ( V_2 ) ) ;
if ( V_12 -> V_108 [ V_109 ] ) {
F_10 ( V_14 , V_248 ,
F_12 ( V_109 ) ) ;
}
F_10 ( V_14 , V_273 , F_127 () ) ;
return V_50 ;
V_262:
return V_136 ;
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
struct V_320 * V_321 ;
struct V_322 * V_323 ;
T_1 V_37 ;
T_15 V_324 ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_257 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! V_12 -> V_96 . V_325 )
return F_166 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_326 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_321 = (struct V_320 * ) V_2 -> V_55 -> V_56 ;
V_2 -> V_52 . V_321 = V_321 ;
V_37 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_37 -= sizeof( struct V_231 ) ;
F_25 ( V_2 -> V_55 , V_37 ) ;
V_324 = F_106 ( V_321 -> V_327 ) ;
F_69 ( L_7 , V_141 , V_324 ) ;
if ( F_167 ( & V_12 -> V_96 . V_328 , V_324 ) < 0 )
goto V_333;
F_168 (skip, chunk) {
if ( F_2 ( V_323 -> V_329 ) >= V_12 -> V_329 -> V_330 )
goto V_333;
}
F_10 ( V_14 , V_331 , F_124 ( V_324 ) ) ;
if ( V_37 > sizeof( struct V_320 ) )
F_10 ( V_14 , V_332 ,
F_34 ( V_2 ) ) ;
V_333:
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
struct V_334 * V_335 ;
struct V_336 * V_337 ;
unsigned int V_338 ;
T_1 V_339 ;
V_47 * V_340 ;
V_47 * V_341 ;
V_335 = (struct V_334 * ) V_2 -> V_55 -> V_56 ;
V_2 -> V_52 . V_335 = V_335 ;
F_25 ( V_2 -> V_55 , sizeof( struct V_334 ) ) ;
if ( ! F_170 ( V_12 , V_335 -> V_342 ) )
return V_343 ;
V_339 = F_2 ( V_335 -> V_344 ) ;
if ( V_339 != V_12 -> V_345 && ! F_171 ( V_12 , V_339 ) )
return V_346 ;
V_338 = F_2 ( V_2 -> V_5 -> V_6 ) - sizeof( V_347 ) ;
V_337 = F_172 ( F_2 ( V_335 -> V_342 ) ) ;
if ( V_338 != V_337 -> V_348 )
return V_267 ;
V_341 = V_335 -> V_337 ;
F_25 ( V_2 -> V_55 , V_338 ) ;
V_340 = F_173 ( V_341 , V_338 , V_20 ) ;
if ( ! V_340 )
goto V_59;
memset ( V_341 , 0 , V_338 ) ;
F_174 ( V_12 , V_2 -> V_55 ,
(struct V_349 * ) V_2 -> V_5 ,
V_20 ) ;
if ( memcmp ( V_340 , V_341 , V_338 ) ) {
F_175 ( V_340 ) ;
return V_89 ;
}
F_175 ( V_340 ) ;
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
struct V_334 * V_335 ;
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
if ( ! F_1 ( V_2 , sizeof( struct V_349 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_335 = (struct V_334 * ) V_2 -> V_55 -> V_56 ;
error = F_49 ( V_8 , V_10 , V_12 , type , V_2 ) ;
switch ( error ) {
case V_343 :
V_33 = F_90 ( V_12 , V_2 ,
V_350 ,
& V_335 -> V_342 ,
sizeof( T_1 ) , 0 ) ;
if ( V_33 ) {
F_10 ( V_14 , V_62 ,
F_34 ( V_33 ) ) ;
}
case V_346 :
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
if ( V_12 -> V_345 != F_2 ( V_335 -> V_344 ) ) {
struct V_15 * V_16 ;
V_16 = F_177 ( V_12 , F_2 ( V_335 -> V_344 ) ,
V_351 , V_20 ) ;
if ( ! V_16 )
return - V_352 ;
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
struct V_1 * V_353 = V_13 ;
struct V_1 * V_33 ;
V_18 * V_293 ;
F_69 ( L_8 , V_141 , type . V_2 ) ;
if ( ! F_37 ( V_353 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_353 , sizeof( V_18 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
switch ( type . V_2 & V_354 ) {
case V_355 :
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
case V_356 :
V_293 = V_353 -> V_5 ;
V_33 = F_90 ( V_12 , V_353 ,
V_357 , V_293 ,
F_143 ( F_2 ( V_293 -> V_6 ) ) ,
0 ) ;
if ( V_33 ) {
F_10 ( V_14 , V_62 ,
F_34 ( V_33 ) ) ;
}
F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
return V_50 ;
case V_358 :
return V_136 ;
case V_359 :
V_293 = V_353 -> V_5 ;
V_33 = F_90 ( V_12 , V_353 ,
V_357 , V_293 ,
F_143 ( F_2 ( V_293 -> V_6 ) ) ,
0 ) ;
if ( V_33 ) {
F_10 ( V_14 , V_62 ,
F_34 ( V_33 ) ) ;
}
return V_50 ;
default:
break;
}
return V_136 ;
}
T_2 F_86 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
if ( ! F_1 ( V_2 , sizeof( V_18 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
F_69 ( L_9 , V_141 , type . V_2 ) ;
return V_136 ;
}
T_2 F_6 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_14 ( V_8 , V_360 ) ;
F_10 ( V_14 , V_170 , F_16 () ) ;
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
if ( ! F_1 ( V_2 , sizeof( V_18 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
return V_361 ;
}
static T_2 F_129 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
void * V_13 ,
T_4 * V_14 ,
const V_47 * V_362 ,
const T_9 V_127 )
{
struct V_34 * V_35 = NULL ;
struct V_1 * V_2 = V_13 ;
struct V_1 * abort = NULL ;
if ( F_38 ( V_67 , V_12 ) )
goto V_363;
abort = F_179 ( V_12 , V_2 , V_362 , V_127 ) ;
if ( ! abort )
goto V_59;
if ( V_12 ) {
if ( V_2 -> V_5 -> type == V_364 &&
! V_12 -> V_96 . V_365 . V_366 ) {
V_64 * V_367 ;
V_367 = ( V_64 * ) V_2 -> V_5 ;
if ( ! F_1 ( V_2 ,
sizeof( V_64 ) ) )
abort -> V_5 -> V_270 |= V_368 ;
else {
unsigned int V_369 ;
V_369 = F_106 ( V_367 -> V_53 . V_366 ) ;
F_10 ( V_14 , V_370 ,
F_124 ( V_369 ) ) ;
}
}
F_10 ( V_14 , V_62 , F_34 ( abort ) ) ;
F_14 ( V_8 , V_49 ) ;
if ( V_12 -> V_177 <= V_76 ) {
F_10 ( V_14 , V_22 ,
F_12 ( V_73 ) ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_69 ) ) ;
F_10 ( V_14 , V_220 ,
F_59 ( V_371 ) ) ;
} else {
F_10 ( V_14 , V_116 ,
F_58 ( V_307 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_371 ) ) ;
F_15 ( V_8 , V_28 ) ;
}
} else {
V_35 = F_135 ( V_8 , V_12 , V_2 ) ;
if ( ! V_35 )
goto V_372;
if ( F_138 ( abort ) )
V_35 -> V_42 = F_106 ( V_2 -> V_41 -> V_42 ) ;
abort -> V_55 -> V_45 = V_10 -> V_44 . V_45 ;
F_139 ( V_35 , abort ) ;
F_10 ( V_14 , V_48 ,
F_24 ( V_35 ) ) ;
F_14 ( V_8 , V_49 ) ;
}
F_14 ( V_8 , V_68 ) ;
V_363:
F_6 ( V_8 , V_10 , V_12 , F_89 ( 0 ) , V_13 , V_14 ) ;
return V_234 ;
V_372:
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
static const char V_373 [] = L_10 ;
return F_129 ( V_8 , V_10 , V_12 , V_13 , V_14 , V_373 ,
sizeof( V_373 ) ) ;
}
static T_2 F_63 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 , void * V_374 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
struct V_291 * V_312 = V_374 ;
struct V_1 * abort = NULL ;
if ( F_38 ( V_67 , V_12 ) )
goto V_363;
abort = F_180 ( V_12 , V_2 , V_312 ) ;
if ( ! abort )
goto V_59;
F_10 ( V_14 , V_62 , F_34 ( abort ) ) ;
F_14 ( V_8 , V_49 ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_307 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_371 ) ) ;
F_15 ( V_8 , V_28 ) ;
F_14 ( V_8 , V_68 ) ;
V_363:
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
static const char V_373 [] = L_11 ;
return F_129 ( V_8 , V_10 , V_12 , V_13 , V_14 , V_373 ,
sizeof( V_373 ) ) ;
}
static T_2 F_7 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
static const char V_373 [] = L_12 ;
if ( ! V_12 )
return F_178 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
return F_129 ( V_8 , V_10 , V_12 , V_13 , V_14 , V_373 ,
sizeof( V_373 ) ) ;
}
T_2 F_181 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_31 ;
struct V_11 * V_375 ;
F_10 ( V_14 , V_25 ,
F_13 ( V_178 ) ) ;
V_31 = F_108 ( V_12 , & V_12 -> V_44 . V_209 , V_20 , 0 ) ;
if ( ! V_31 )
goto V_59;
F_10 ( V_14 , V_376 ,
F_34 ( V_31 ) ) ;
V_375 = (struct V_11 * ) V_12 ;
F_10 ( V_14 , V_61 , F_33 ( V_375 ) ) ;
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
struct V_377 * V_378 = V_13 ;
F_10 ( V_14 , V_379 , F_183 ( V_378 ) ) ;
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
int V_190 ;
F_10 ( V_14 , V_25 ,
F_13 ( V_380 ) ) ;
V_190 = V_50 ;
if ( F_117 ( & V_12 -> V_245 ) ) {
V_190 = F_92 ( V_8 , V_10 , V_12 , type ,
V_13 , V_14 ) ;
}
return V_190 ;
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
F_58 ( V_307 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_381 ) ) ;
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
F_10 ( V_14 , V_382 , F_58 ( - V_383 ) ) ;
return V_50 ;
}
T_2 F_187 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_10 ( V_14 , V_382 ,
F_58 ( - V_384 ) ) ;
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
F_10 ( V_14 , V_220 ,
F_59 ( V_381 ) ) ;
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
F_10 ( V_14 , V_385 , F_34 ( V_2 ) ) ;
F_10 ( V_14 , V_74 ,
F_12 ( V_196 ) ) ;
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
F_69 ( L_13 , V_141 ,
type . V_386 ) ;
return V_136 ;
}
T_2 F_199 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_15 * V_387 ;
V_387 = F_200 ( V_12 , V_20 ) ;
if ( ! V_387 )
return V_51 ;
F_10 ( V_14 , V_21 , F_11 ( V_387 ) ) ;
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
F_13 ( V_388 ) ) ;
F_10 ( V_14 , V_226 , F_16 () ) ;
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
F_13 ( V_389 ) ) ;
F_10 ( V_14 , V_226 , F_16 () ) ;
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
V_141 , type . V_390 ) ;
return V_136 ;
}
T_2 F_203 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_111 * V_70 = V_13 ;
F_14 ( V_8 , V_391 ) ;
if ( V_12 -> V_114 >= V_12 -> V_115 ) {
if ( V_12 -> V_96 . V_392 &&
V_12 -> V_177 == V_380 ) {
F_10 ( V_14 , V_393 ,
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
F_10 ( V_14 , V_394 , F_56 ( V_70 ) ) ;
return V_50 ;
}
T_2 F_204 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_14 ( V_8 , V_395 ) ;
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
struct V_215 * V_216 ;
int V_217 = V_12 -> V_218 + 1 ;
F_69 ( L_15 , V_141 ) ;
F_14 ( V_8 , V_396 ) ;
if ( V_217 <= V_12 -> V_219 ) {
V_216 = (struct V_215 * ) & V_12 -> V_44 . V_209 ;
V_31 = F_108 ( V_12 , V_216 , V_20 , 0 ) ;
if ( ! V_31 )
return V_51 ;
F_10 ( V_14 , V_376 ,
F_34 ( V_31 ) ) ;
F_10 ( V_14 , V_397 ,
F_12 ( V_73 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
} else {
F_69 ( L_16
L_17 , V_141 , V_217 ,
V_12 -> V_219 ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_220 ,
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
int V_217 = V_12 -> V_218 + 1 ;
F_69 ( L_18 , V_141 ) ;
F_14 ( V_8 , V_398 ) ;
if ( V_217 <= V_12 -> V_219 ) {
V_31 = F_207 ( V_12 , NULL ) ;
if ( ! V_31 )
return V_51 ;
F_10 ( V_14 , V_376 ,
F_34 ( V_31 ) ) ;
F_10 ( V_14 , V_399 ,
F_12 ( V_75 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
} else {
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_220 ,
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
F_69 ( L_19 , V_141 ) ;
F_14 ( V_8 , V_400 ) ;
( (struct V_11 * ) V_12 ) -> V_401 ++ ;
if ( V_12 -> V_114 >= V_12 -> V_115 ) {
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_119 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_30 ;
}
switch ( V_12 -> V_177 ) {
case V_388 :
V_112 = F_201 ( V_12 , NULL ) ;
break;
case V_389 :
V_112 = F_121 ( V_12 , NULL ) ;
break;
default:
F_130 () ;
break;
}
if ( ! V_112 )
goto V_59;
if ( V_12 -> V_402 )
F_10 ( V_14 , V_126 ,
F_56 ( V_12 -> V_402 ) ) ;
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
struct V_1 * V_2 = V_12 -> V_302 ;
struct V_111 * V_70 = V_2 -> V_70 ;
F_14 ( V_8 , V_403 ) ;
if ( V_70 )
F_10 ( V_14 , V_126 ,
F_56 ( V_70 ) ) ;
F_10 ( V_14 , V_385 , F_34 ( V_2 ) ) ;
if ( V_12 -> V_114 >= V_12 -> V_115 ) {
F_10 ( V_14 , V_22 ,
F_12 ( V_196 ) ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_119 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_234 ;
}
F_61 ( V_12 -> V_302 ) ;
F_10 ( V_14 , V_62 ,
F_34 ( V_12 -> V_302 ) ) ;
F_10 ( V_14 , V_248 ,
F_12 ( V_196 ) ) ;
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
F_69 ( L_20 , V_141 ) ;
F_14 ( V_8 , V_404 ) ;
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
int V_190 ;
F_14 ( V_8 , V_405 ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_380 ) ) ;
V_190 = V_50 ;
if ( F_117 ( & V_12 -> V_245 ) ) {
V_190 = F_92 ( V_8 , V_10 , V_12 , type ,
V_13 , V_14 ) ;
}
return V_190 ;
}
T_2 F_212 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return V_406 ;
}
T_2 F_213 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return V_407 ;
}
T_2 F_214 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_69 ( L_21 , V_141 , type . V_2 ) ;
return V_50 ;
}
static struct V_408 * F_134 ( struct V_1 * V_2 )
{
struct V_408 * V_409 ;
unsigned int V_37 ;
T_1 V_410 ;
T_1 V_411 ;
V_409 = (struct V_408 * ) V_2 -> V_55 -> V_56 ;
V_410 = F_2 ( V_409 -> V_412 ) ;
V_411 = F_2 ( V_409 -> V_411 ) ;
V_37 = sizeof( struct V_408 ) ;
V_37 += ( V_410 + V_411 ) * sizeof( T_15 ) ;
if ( V_37 > V_2 -> V_55 -> V_37 )
return NULL ;
F_25 ( V_2 -> V_55 , V_37 ) ;
return V_409 ;
}
static struct V_34 * F_22 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
struct V_1 * V_2 ,
const void * V_362 ,
T_9 V_127 )
{
struct V_34 * V_35 ;
struct V_1 * abort ;
V_35 = F_135 ( V_8 , V_12 , V_2 ) ;
if ( V_35 ) {
abort = F_136 ( V_12 , V_2 , V_127 ) ;
if ( ! abort ) {
F_137 ( V_35 ) ;
return NULL ;
}
if ( F_138 ( abort ) )
V_35 -> V_42 = F_106 ( V_2 -> V_41 -> V_42 ) ;
F_32 ( abort , V_127 , V_362 ) ;
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
T_1 V_413 ;
T_1 V_414 ;
T_15 V_42 ;
V_413 = F_2 ( V_2 -> V_41 -> V_210 ) ;
V_414 = F_2 ( V_2 -> V_41 -> V_299 ) ;
if ( V_12 ) {
switch ( V_2 -> V_5 -> type ) {
case V_364 :
{
V_64 * V_367 ;
V_367 = ( V_64 * ) V_2 -> V_5 ;
V_42 = F_106 ( V_367 -> V_53 . V_366 ) ;
break;
}
default:
V_42 = V_12 -> V_96 . V_365 . V_366 ;
break;
}
} else {
switch ( V_2 -> V_5 -> type ) {
case V_415 :
{
V_43 * V_154 ;
V_154 = ( V_43 * ) V_2 -> V_5 ;
V_42 = F_106 ( V_154 -> V_53 . V_366 ) ;
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
F_216 ( V_70 , (union V_131 * ) & V_2 -> V_210 ,
F_18 ( V_8 -> V_38 . V_39 ) ) ;
V_35 = & V_70 -> V_35 ;
F_217 ( V_35 , V_70 , V_413 , V_414 ) ;
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
struct V_86 * V_416 ;
V_416 = V_2 -> V_52 . V_85 ;
V_35 -> V_42 = V_416 -> V_90 . V_182 ;
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
V_269 * V_268 ;
struct V_1 * V_189 ;
T_9 V_417 ;
T_21 V_418 ;
int V_419 ;
T_15 V_324 ;
struct V_420 * V_421 = (struct V_420 * ) & V_12 -> V_96 . V_328 ;
struct V_82 * V_45 = V_12 -> V_44 . V_45 ;
struct V_8 * V_8 = F_77 ( V_45 ) ;
T_22 V_422 ;
T_22 V_423 ;
V_222 V_424 = 0 ;
V_268 = V_2 -> V_52 . V_268 = ( V_269 * ) V_2 -> V_55 -> V_56 ;
F_25 ( V_2 -> V_55 , sizeof( V_269 ) ) ;
V_324 = F_106 ( V_268 -> V_324 ) ;
F_69 ( L_7 , V_141 , V_324 ) ;
if ( V_12 -> V_96 . V_425 && ! V_2 -> V_426 ) {
struct V_161 * V_162 = F_220 ( V_2 -> V_55 ) -> V_162 ;
V_2 -> V_426 = 1 ;
if ( V_162 -> V_427 ( F_221 ( V_2 -> V_55 ) ) ) {
F_10 ( V_14 , V_428 ,
F_124 ( V_324 ) ) ;
}
}
V_419 = F_167 ( & V_12 -> V_96 . V_328 , V_324 ) ;
if ( V_419 < 0 ) {
if ( V_2 -> V_12 )
V_2 -> V_12 -> V_429 . V_430 ++ ;
return V_259 ;
} else if ( V_419 > 0 ) {
F_10 ( V_14 , V_431 , F_124 ( V_324 ) ) ;
return V_263 ;
}
V_417 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_417 -= sizeof( V_258 ) ;
V_418 = V_432 ;
if ( ( V_417 >= V_12 -> V_183 ) && ( ! V_12 -> V_433 . V_434 ) ) {
F_10 ( V_14 , V_435 , F_16 () ) ;
}
if ( ( ! V_2 -> V_436 ) && ( ! V_12 -> V_183 || V_12 -> V_437 ||
( V_417 > V_12 -> V_183 + V_12 -> V_438 ) ) ) {
if ( F_222 ( V_421 ) &&
( F_223 ( V_421 ) + 1 ) == V_324 ) {
F_69 ( L_22 , V_141 , V_324 ) ;
V_418 = V_439 ;
} else {
F_69 ( L_23 ,
V_141 , V_324 , V_417 , V_12 -> V_183 ) ;
return V_264 ;
}
}
if ( * V_45 -> V_440 -> V_441 ) {
if ( F_222 ( V_421 ) &&
( F_223 ( V_421 ) + 1 ) == V_324 ) {
F_69 ( L_24 ,
V_141 , V_324 ) ;
V_418 = V_439 ;
}
}
if ( F_3 ( 0 == V_417 ) ) {
V_189 = F_224 ( V_12 , V_2 , V_324 ) ;
if ( V_189 ) {
F_10 ( V_14 , V_62 ,
F_34 ( V_189 ) ) ;
}
F_10 ( V_14 , V_170 , F_16 () ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_307 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_442 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_266 ;
}
V_2 -> V_436 = 1 ;
if ( V_2 -> V_5 -> V_270 & V_443 ) {
F_14 ( V_8 , V_444 ) ;
if ( V_2 -> V_12 )
V_2 -> V_12 -> V_429 . V_445 ++ ;
} else {
F_14 ( V_8 , V_446 ) ;
if ( V_2 -> V_12 )
V_2 -> V_12 -> V_429 . V_447 ++ ;
V_424 = 1 ;
}
V_423 = F_2 ( V_268 -> V_329 ) ;
if ( V_423 >= V_12 -> V_329 -> V_330 ) {
F_10 ( V_14 , V_448 , F_124 ( V_324 ) ) ;
V_189 = F_90 ( V_12 , V_2 , V_449 ,
& V_268 -> V_329 ,
sizeof( V_268 -> V_329 ) ,
sizeof( T_22 ) ) ;
if ( V_189 )
F_10 ( V_14 , V_62 ,
F_34 ( V_189 ) ) ;
return V_260 ;
}
V_422 = F_2 ( V_268 -> V_422 ) ;
if ( V_424 && F_225 ( V_422 , F_226 ( V_12 -> V_329 , V_450 , V_423 ) ) )
return V_267 ;
F_10 ( V_14 , V_418 , F_34 ( V_2 ) ) ;
return V_98 ;
}
