static inline int
F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( F_3 ( V_2 -> V_7 ) )
return 0 ;
if ( F_3 ( V_4 < V_3 ) )
return 0 ;
return 1 ;
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
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
T_8 * V_57 ;
struct V_1 * V_2 = V_13 ;
struct V_1 * V_112 ;
T_9 V_125 = 0 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_126 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_2 -> V_52 . V_127 = ( V_128 * ) V_2 -> V_55 -> V_56 ;
V_57 = ( T_8 * ) V_2 -> V_52 . V_127 ;
V_125 = F_2 ( V_2 -> V_5 -> V_6 ) - sizeof( V_18 ) ;
if ( F_2 ( V_57 -> V_6 ) > V_125 )
return F_61 ( V_8 , V_10 , V_12 , type , V_13 ,
V_57 , V_14 ) ;
if ( ! F_44 ( V_2 -> V_55 , V_125 ) )
goto V_59;
V_112 = F_62 ( V_12 , V_2 , V_57 , V_125 ) ;
if ( ! V_112 )
goto V_59;
F_10 ( V_14 , V_62 , F_34 ( V_112 ) ) ;
return V_50 ;
V_59:
return V_51 ;
}
T_2 F_63 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
union V_129 V_130 ;
struct V_111 * V_131 ;
T_10 * V_132 ;
unsigned long V_133 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_18 ) +
sizeof( T_10 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_132 = ( T_10 * ) V_2 -> V_55 -> V_56 ;
if ( F_2 ( V_132 -> V_57 . V_6 ) !=
sizeof( T_10 ) ) {
return V_134 ;
}
V_130 = V_132 -> V_135 ;
V_131 = F_64 ( V_12 , & V_130 ) ;
if ( F_3 ( ! V_131 ) ) {
if ( V_130 . V_136 . V_137 == V_138 ) {
F_65 ( L_1 ,
V_139 ,
V_12 ,
& V_130 . V_140 . V_141 ) ;
} else {
F_65 ( L_2 ,
V_139 ,
V_12 ,
& V_130 . V_142 . V_143 . V_144 ) ;
}
return V_134 ;
}
if ( V_132 -> V_145 != V_131 -> V_145 )
return V_134 ;
V_133 = V_131 -> V_146 + V_131 -> V_147 ;
if ( F_66 ( V_132 -> V_148 , V_149 ) ||
F_66 ( V_149 , V_132 -> V_148 + V_133 ) ) {
F_67 ( L_3
L_4 , V_139 , V_131 ) ;
return V_134 ;
}
F_10 ( V_14 , V_150 , F_56 ( V_131 ) ) ;
return V_50 ;
}
static int F_68 ( struct V_8 * V_8 , union V_129 * V_151 ,
struct V_1 * V_152 ,
T_4 * V_14 )
{
int V_37 ;
struct V_34 * V_153 ;
union V_154 * V_155 ;
struct V_156 * V_157 ;
struct V_9 * V_10 ;
char V_158 [ sizeof( struct V_156 ) + sizeof( union V_154 ) ] ;
struct V_159 * V_160 = F_69 ( V_151 -> V_142 . V_161 ) ;
V_157 = (struct V_156 * ) V_158 ;
V_155 = (union V_154 * ) V_157 -> V_162 ;
V_37 = V_160 -> V_163 ( V_151 , V_155 ) ;
V_37 += sizeof( V_164 ) ;
V_157 -> V_165 = V_166 ;
V_157 -> V_6 = F_70 ( V_37 ) ;
V_10 = F_18 ( V_8 -> V_38 . V_39 ) -> V_10 ;
V_153 = F_22 ( V_8 , V_10 , NULL , V_152 , V_157 , V_37 ) ;
if ( ! V_153 )
goto V_167;
F_10 ( V_14 , V_48 , F_24 ( V_153 ) ) ;
F_14 ( V_8 , V_49 ) ;
F_10 ( V_14 , V_168 , F_16 () ) ;
V_167:
return 0 ;
}
static bool F_71 ( const struct V_169 * V_170 ,
union V_129 * V_171 )
{
struct V_111 * V_172 ;
F_72 (addr, list, transports) {
if ( F_73 ( V_171 , & V_172 -> V_171 ) )
return true ;
}
return false ;
}
static int F_74 ( const struct V_11 * V_32 ,
const struct V_11 * V_12 ,
struct V_1 * V_152 ,
T_4 * V_14 )
{
struct V_8 * V_8 = F_75 ( V_32 -> V_44 . V_45 ) ;
struct V_111 * V_173 ;
int V_94 = 1 ;
F_72 (new_addr, &new_asoc->peer.transport_addr_list,
transports) {
if ( ! F_71 ( & V_12 -> V_96 . V_174 ,
& V_173 -> V_171 ) ) {
F_68 ( V_8 , & V_173 -> V_171 , V_152 ,
V_14 ) ;
V_94 = 0 ;
break;
}
}
return V_94 ;
}
static void F_76 ( struct V_11 * V_32 ,
const struct V_11 * V_12 )
{
switch ( V_12 -> V_175 ) {
case V_176 :
V_32 -> V_90 . V_177 = V_12 -> V_90 . V_177 ;
V_32 -> V_90 . V_178 = V_12 -> V_90 . V_177 ;
V_32 -> V_90 . V_179 = 0 ;
break;
case V_76 :
V_32 -> V_90 . V_177 = V_12 -> V_90 . V_177 ;
V_32 -> V_90 . V_178 = V_12 -> V_90 . V_177 ;
V_32 -> V_90 . V_179 = V_12 -> V_90 . V_180 ;
break;
default:
V_32 -> V_90 . V_178 = V_12 -> V_90 . V_177 ;
V_32 -> V_90 . V_179 = V_12 -> V_90 . V_180 ;
break;
}
V_32 -> V_181 = V_12 -> V_181 ;
V_32 -> V_90 . V_100 = V_12 -> V_90 . V_100 ;
V_32 -> V_90 . V_101 = V_12 -> V_90 . V_101 ;
V_32 -> V_90 . V_182 = V_12 -> V_90 . V_182 ;
}
static char F_77 ( struct V_11 * V_32 ,
const struct V_11 * V_12 )
{
if ( ( V_12 -> V_90 . V_177 != V_32 -> V_90 . V_177 ) &&
( V_12 -> V_90 . V_180 != V_32 -> V_90 . V_180 ) &&
( V_12 -> V_90 . V_177 == V_32 -> V_90 . V_178 ) &&
( V_12 -> V_90 . V_180 == V_32 -> V_90 . V_179 ) )
return 'A' ;
if ( ( V_12 -> V_90 . V_177 == V_32 -> V_90 . V_177 ) &&
( ( V_12 -> V_90 . V_180 != V_32 -> V_90 . V_180 ) ||
( 0 == V_12 -> V_90 . V_180 ) ) ) {
return 'B' ;
}
if ( ( V_12 -> V_90 . V_177 == V_32 -> V_90 . V_177 ) &&
( V_12 -> V_90 . V_180 == V_32 -> V_90 . V_180 ) )
return 'D' ;
if ( ( V_12 -> V_90 . V_177 != V_32 -> V_90 . V_177 ) &&
( V_12 -> V_90 . V_180 == V_32 -> V_90 . V_180 ) &&
( 0 == V_32 -> V_90 . V_178 ) &&
( 0 == V_32 -> V_90 . V_179 ) )
return 'C' ;
return 'E' ;
}
static T_2 F_78 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 , T_4 * V_14 )
{
T_2 V_183 ;
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
V_183 = V_50 ;
} else {
V_183 = V_51 ;
}
goto V_184;
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
if ( ! F_79 ( V_12 , V_185 ) ) {
if ( ! F_74 ( V_32 , V_12 , V_2 ,
V_14 ) ) {
V_183 = V_50 ;
goto V_186;
}
}
F_76 ( V_32 , V_12 ) ;
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
V_183 = V_50 ;
return V_183 ;
V_59:
V_183 = V_51 ;
V_186:
if ( V_32 )
F_35 ( V_32 ) ;
V_184:
if ( V_33 )
F_23 ( V_33 ) ;
return V_183 ;
}
T_2 F_80 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return F_78 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_81 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return F_78 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_82 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 , T_4 * V_14 )
{
if ( V_10 == F_18 ( V_8 -> V_38 . V_39 ) -> V_10 )
return F_83 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
else
return F_84 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
static T_2 F_85 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
struct V_1 * V_2 ,
T_4 * V_14 ,
struct V_11 * V_32 )
{
V_43 * V_79 ;
struct V_15 * V_16 ;
struct V_1 * V_31 ;
struct V_1 * V_187 ;
T_2 V_188 ;
V_79 = & V_2 -> V_52 . V_85 -> V_90 . V_79 [ 0 ] ;
if ( ! F_30 ( V_32 , V_2 , F_29 ( V_2 ) , V_79 ,
V_20 ) )
goto V_59;
if ( ! F_74 ( V_32 , V_12 , V_2 , V_14 ) ) {
return V_50 ;
}
if ( F_79 ( V_12 , V_189 ) ) {
V_188 = F_86 ( V_8 , V_10 , V_12 ,
F_87 ( V_2 -> V_5 -> type ) ,
V_2 , V_14 ) ;
if ( V_51 == V_188 )
goto V_59;
V_187 = F_88 ( V_12 , V_2 ,
V_190 ,
NULL , 0 , 0 ) ;
if ( V_187 )
F_10 ( V_14 , V_62 ,
F_34 ( V_187 ) ) ;
return V_50 ;
}
F_10 ( V_14 , V_191 , F_16 () ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_192 ) ) ;
F_10 ( V_14 , V_193 , F_16 () ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_194 ) ) ;
F_10 ( V_14 , V_195 , F_16 () ) ;
V_31 = F_50 ( V_32 , V_2 ) ;
if ( ! V_31 )
goto V_59;
V_16 = F_9 ( V_12 , 0 , V_196 , 0 ,
V_32 -> V_90 . V_100 ,
V_32 -> V_90 . V_101 ,
NULL , V_20 ) ;
if ( ! V_16 )
goto V_102;
F_10 ( V_14 , V_197 , F_33 ( V_32 ) ) ;
F_10 ( V_14 , V_21 , F_11 ( V_16 ) ) ;
if ( F_79 ( V_12 , V_198 ) &&
( F_20 ( V_12 -> V_44 . V_45 , V_46 ) ||
F_89 ( V_12 -> V_44 . V_45 , V_199 ) ) ) {
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
return F_90 ( V_8 , V_10 , V_12 ,
F_87 ( 0 ) , NULL ,
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
static T_2 F_91 ( struct V_8 * V_8 ,
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
F_10 ( V_14 , V_197 , F_33 ( V_32 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_105 ) ) ;
F_14 ( V_8 , V_28 ) ;
F_10 ( V_14 , V_107 , F_16 () ) ;
V_31 = F_50 ( V_32 , V_2 ) ;
if ( ! V_31 )
goto V_59;
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
F_10 ( V_14 , V_200 , F_92 ( V_99 ) ) ;
if ( V_12 -> V_96 . V_103 )
F_10 ( V_14 , V_201 , F_16 () ) ;
return V_50 ;
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
return V_134 ;
}
static T_2 F_94 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
struct V_1 * V_2 ,
T_4 * V_14 ,
struct V_11 * V_32 )
{
struct V_15 * V_16 = NULL , * V_80 = NULL ;
struct V_1 * V_31 ;
if ( V_12 -> V_175 < V_105 ) {
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
T_2 F_95 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
T_2 V_183 ;
struct V_1 * V_2 = V_13 ;
struct V_11 * V_32 ;
int error = 0 ;
char V_202 ;
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
V_202 = F_77 ( V_32 , V_12 ) ;
switch ( V_202 ) {
case 'A' :
V_183 = F_85 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
V_32 ) ;
break;
case 'B' :
V_183 = F_91 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
V_32 ) ;
break;
case 'C' :
V_183 = F_93 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
V_32 ) ;
break;
case 'D' :
V_183 = F_94 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
V_32 ) ;
break;
default:
V_183 = F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
break;
}
F_10 ( V_14 , V_203 , F_33 ( V_32 ) ) ;
F_10 ( V_14 , V_29 , F_16 () ) ;
F_10 ( V_14 , V_203 ,
F_33 ( (struct V_11 * ) V_12 ) ) ;
return V_183 ;
V_59:
return V_51 ;
}
T_2 F_96 (
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
if ( ! F_1 ( V_2 , sizeof( V_204 ) ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( V_205 ==
F_97 ( & V_12 -> V_44 . V_206 , & V_2 -> V_207 ) )
return F_84 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
return F_98 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_99 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
if ( ! F_5 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_204 ) ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( V_205 ==
F_97 ( & V_12 -> V_44 . V_206 , & V_2 -> V_207 ) )
return F_84 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_23 ) ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_24 ) ) ;
return F_98 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_100 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return F_99 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_101 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
V_164 * V_187 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_208 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
F_102 (err, chunk->chunk_hdr) {
if ( V_209 == V_187 -> V_165 )
return F_103 ( V_8 , V_10 , V_12 , type ,
V_13 , V_14 ) ;
}
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
static T_2 F_103 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
T_11 V_210 ;
T_12 V_211 ;
V_164 * V_187 ;
struct V_1 * V_112 ;
struct V_212 * V_213 ;
int V_214 = V_12 -> V_215 + 1 ;
if ( V_214 > V_12 -> V_216 ) {
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_217 ,
F_59 ( V_209 ) ) ;
return V_30 ;
}
V_187 = ( V_164 * ) ( V_2 -> V_55 -> V_56 ) ;
V_210 = F_104 ( * ( V_218 * ) ( ( V_219 * ) V_187 + sizeof( V_164 ) ) ) ;
V_210 = ( V_210 * 2 ) / 1000 ;
V_211 . V_57 . type = V_220 ;
V_211 . V_57 . V_6 = F_70 ( sizeof( V_211 ) ) ;
V_211 . V_221 = F_105 ( V_210 ) ;
V_213 = (struct V_212 * ) & V_12 -> V_44 . V_206 ;
V_112 = F_106 ( V_12 , V_213 , V_20 , sizeof( V_211 ) ) ;
if ( ! V_112 )
goto V_59;
F_32 ( V_112 , sizeof( V_211 ) , & V_211 ) ;
F_10 ( V_14 , V_222 , F_16 () ) ;
F_10 ( V_14 , V_191 , F_16 () ) ;
F_10 ( V_14 , V_223 , F_16 () ) ;
F_10 ( V_14 , V_224 , F_16 () ) ;
F_10 ( V_14 , V_225 ,
F_56 ( V_12 -> V_96 . V_226 ) ) ;
F_10 ( V_14 , V_227 , F_16 () ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_75 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_176 ) ) ;
F_10 ( V_14 , V_74 ,
F_12 ( V_73 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_112 ) ) ;
return V_50 ;
V_59:
return V_51 ;
}
T_2 F_107 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
if ( ! F_5 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_204 ) ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( V_205 ==
F_97 ( & V_12 -> V_44 . V_206 , & V_2 -> V_207 ) )
return F_84 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
return F_98 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
static T_2 F_98 ( struct V_8 * V_8 ,
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
if ( V_37 >= sizeof( struct V_228 ) + sizeof( struct V_156 ) ) {
V_164 * V_187 ;
F_102 ( V_187 , V_2 -> V_5 ) ;
if ( ( void * ) V_187 != ( void * ) V_2 -> V_229 )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
error = ( ( V_164 * ) V_2 -> V_55 -> V_56 ) -> V_165 ;
}
F_10 ( V_14 , V_116 , F_58 ( V_230 ) ) ;
F_10 ( V_14 , V_118 , F_59 ( error ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_231 ;
}
T_2 F_108 ( struct V_8 * V_8 ,
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
if ( ! F_1 ( V_2 , sizeof( V_204 ) ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
V_37 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_37 >= sizeof( struct V_228 ) + sizeof( struct V_156 ) )
error = ( ( V_164 * ) V_2 -> V_55 -> V_56 ) -> V_165 ;
return F_39 ( V_8 , V_14 , error , V_69 , V_12 ,
V_2 -> V_70 ) ;
}
T_2 F_109 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return F_39 ( V_8 , V_14 , V_119 ,
V_232 , V_12 ,
(struct V_111 * ) V_13 ) ;
}
T_2 F_110 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return F_108 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
static T_2 F_39 ( struct V_8 * V_8 ,
T_4 * V_14 ,
T_13 error , int V_233 ,
const struct V_11 * V_12 ,
struct V_111 * V_70 )
{
F_67 ( L_5 , V_139 ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_26 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_10 ( V_14 , V_22 ,
F_12 ( V_73 ) ) ;
F_10 ( V_14 , V_116 , F_58 ( V_233 ) ) ;
F_10 ( V_14 , V_217 ,
F_59 ( error ) ) ;
return V_231 ;
}
T_2 F_111 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
T_14 * V_234 ;
T_2 V_188 ;
struct V_15 * V_16 ;
T_15 V_235 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 ,
sizeof( struct V_236 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_234 = ( T_14 * ) V_2 -> V_55 -> V_56 ;
F_25 ( V_2 -> V_55 , sizeof( T_14 ) ) ;
V_2 -> V_52 . V_237 = V_234 ;
V_235 = F_104 ( V_234 -> V_238 ) ;
if ( F_112 ( V_235 , V_12 -> V_239 ) ) {
F_67 ( L_6 , V_139 , V_235 ,
V_12 -> V_239 ) ;
return V_134 ;
}
if ( ! F_112 ( V_235 , V_12 -> V_240 ) )
return F_113 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
V_16 = F_114 ( V_12 , 0 , V_20 ) ;
if ( ! V_16 ) {
V_188 = V_51 ;
goto V_167;
}
F_10 ( V_14 , V_21 , F_11 ( V_16 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_241 ) ) ;
V_188 = V_50 ;
if ( F_115 ( & V_12 -> V_242 ) ) {
V_188 = F_116 ( V_8 , V_10 , V_12 , type ,
V_13 , V_14 ) ;
}
if ( V_51 == V_188 )
goto V_167;
F_10 ( V_14 , V_243 ,
F_117 ( V_2 -> V_52 . V_237 -> V_238 ) ) ;
V_167:
return V_188 ;
}
T_2 F_118 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
T_14 * V_234 ;
T_15 V_235 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 ,
sizeof( struct V_236 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_234 = ( T_14 * ) V_2 -> V_55 -> V_56 ;
V_235 = F_104 ( V_234 -> V_238 ) ;
if ( F_112 ( V_235 , V_12 -> V_239 ) ) {
F_67 ( L_6 , V_139 , V_235 ,
V_12 -> V_239 ) ;
return V_134 ;
}
if ( ! F_112 ( V_235 , V_12 -> V_240 ) )
return F_113 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
F_10 ( V_14 , V_243 ,
F_117 ( V_234 -> V_238 ) ) ;
return V_50 ;
}
T_2 F_86 ( struct V_8 * V_8 ,
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
V_112 = F_119 ( V_12 , V_2 ) ;
if ( NULL == V_112 )
goto V_59;
F_10 ( V_14 , V_244 , F_34 ( V_112 ) ) ;
F_10 ( V_14 , V_245 ,
F_12 ( V_23 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_112 ) ) ;
return V_50 ;
V_59:
return V_51 ;
}
T_2 F_120 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
T_16 * V_246 ;
struct V_1 * V_2 = V_13 ;
T_11 V_247 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_248 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_246 = ( T_16 * ) V_2 -> V_55 -> V_56 ;
F_25 ( V_2 -> V_55 , sizeof( T_16 ) ) ;
V_247 = F_104 ( V_246 -> V_247 ) ;
if ( F_121 ( V_12 -> V_249 , V_247 ) ) {
F_10 ( V_14 ,
V_250 ,
F_122 ( V_247 ) ) ;
}
return V_50 ;
}
T_2 F_123 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
T_17 * V_251 ;
struct V_1 * V_2 = V_13 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_248 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_251 = ( T_17 * ) V_2 -> V_55 -> V_56 ;
F_25 ( V_2 -> V_55 , sizeof( T_17 ) ) ;
F_10 ( V_14 , V_252 ,
F_122 ( F_104 ( V_251 -> V_247 ) ) ) ;
return V_50 ;
}
T_2 F_124 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
T_18 V_253 = F_125 () ;
int error ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_254 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! F_1 ( V_2 , sizeof( V_255 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
error = F_126 ( V_12 , V_2 , V_14 ) ;
switch ( error ) {
case V_98 :
break;
case V_256 :
case V_257 :
F_14 ( V_8 , V_258 ) ;
goto V_259;
case V_260 :
case V_261 :
F_14 ( V_8 , V_258 ) ;
goto V_262;
case V_263 :
goto V_264;
case V_265 :
return F_127 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
( V_219 * ) V_2 -> V_52 . V_266 , sizeof( V_267 ) ) ;
default:
F_128 () ;
}
if ( V_2 -> V_5 -> V_268 & V_269 )
V_253 = F_129 () ;
if ( V_12 -> V_108 [ V_109 ] ) {
F_10 ( V_14 , V_245 ,
F_12 ( V_109 ) ) ;
}
if ( V_2 -> V_270 )
F_10 ( V_14 , V_271 , V_253 ) ;
return V_50 ;
V_262:
if ( V_2 -> V_270 )
F_10 ( V_14 , V_271 , F_129 () ) ;
return V_134 ;
V_259:
if ( V_2 -> V_270 )
F_10 ( V_14 , V_271 , V_253 ) ;
return V_134 ;
V_264:
return V_50 ;
}
T_2 F_130 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
int error ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_254 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! F_1 ( V_2 , sizeof( V_255 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
error = F_126 ( V_12 , V_2 , V_14 ) ;
switch ( error ) {
case V_98 :
case V_256 :
case V_260 :
case V_261 :
case V_257 :
break;
case V_263 :
goto V_264;
case V_265 :
return F_127 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
( V_219 * ) V_2 -> V_52 . V_266 , sizeof( V_267 ) ) ;
default:
F_128 () ;
}
if ( V_2 -> V_270 ) {
F_10 ( V_14 , V_272 , F_16 () ) ;
F_10 ( V_14 , V_271 , F_129 () ) ;
F_10 ( V_14 , V_245 ,
F_12 ( V_23 ) ) ;
}
V_264:
return V_50 ;
}
T_2 F_131 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
T_19 * V_273 ;
T_15 V_235 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_274 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_273 = F_132 ( V_2 ) ;
if ( ! V_273 )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
V_2 -> V_52 . V_275 = V_273 ;
V_235 = F_104 ( V_273 -> V_238 ) ;
if ( F_112 ( V_235 , V_12 -> V_239 ) ) {
F_67 ( L_6 , V_139 , V_235 ,
V_12 -> V_239 ) ;
return V_134 ;
}
if ( ! F_112 ( V_235 , V_12 -> V_240 ) )
return F_113 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
F_10 ( V_14 , V_276 , F_34 ( V_2 ) ) ;
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
V_35 = F_133 ( V_8 , V_12 , V_2 ) ;
if ( V_35 ) {
abort = F_134 ( V_12 , V_2 , 0 ) ;
if ( ! abort ) {
F_135 ( V_35 ) ;
return V_51 ;
}
if ( F_136 ( abort ) )
V_35 -> V_42 = F_104 ( V_2 -> V_41 -> V_42 ) ;
abort -> V_55 -> V_45 = V_10 -> V_44 . V_45 ;
F_137 ( V_35 , abort ) ;
F_10 ( V_14 , V_48 ,
F_24 ( V_35 ) ) ;
F_14 ( V_8 , V_49 ) ;
F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
return V_50 ;
}
return V_51 ;
}
T_2 F_138 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
V_164 * V_187 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_208 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
F_102 ( V_187 , V_2 -> V_5 ) ;
if ( ( void * ) V_187 != ( void * ) V_2 -> V_229 )
return F_61 ( V_8 , V_10 , V_12 , type , V_13 ,
( void * ) V_187 , V_14 ) ;
F_10 ( V_14 , V_277 ,
F_34 ( V_2 ) ) ;
return V_50 ;
}
T_2 F_139 ( struct V_8 * V_8 ,
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
V_112 = F_140 ( V_12 , V_2 ) ;
if ( ! V_112 )
goto V_278;
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
V_278:
F_52 ( V_16 ) ;
V_59:
return V_51 ;
}
T_2 F_83 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
struct V_279 * V_55 = V_2 -> V_55 ;
V_18 * V_280 ;
V_164 * V_187 ;
V_47 * V_281 ;
int V_282 = 0 ;
int V_283 = 0 ;
F_14 ( V_8 , V_40 ) ;
V_280 = ( V_18 * ) V_2 -> V_5 ;
do {
if ( F_2 ( V_280 -> V_6 ) < sizeof( V_18 ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
if ( V_284 == V_280 -> type )
V_282 = 1 ;
if ( V_67 == V_280 -> type )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( V_285 == V_280 -> type )
V_283 = 1 ;
if ( V_286 == V_280 -> type ) {
F_102 (err, ch) {
if ( V_209 == V_187 -> V_165 ) {
V_283 = 1 ;
break;
}
}
}
V_281 = ( ( V_47 * ) V_280 ) + F_141 ( F_2 ( V_280 -> V_6 ) ) ;
if ( V_281 > F_142 ( V_55 ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_280 = ( V_18 * ) V_281 ;
} while ( V_281 < F_142 ( V_55 ) );
if ( V_282 )
return F_143 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
else if ( V_283 )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
else
return F_19 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
static T_2 F_143 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_34 * V_35 = NULL ;
struct V_1 * V_2 = V_13 ;
struct V_1 * V_287 ;
V_35 = F_133 ( V_8 , V_12 , V_2 ) ;
if ( V_35 ) {
V_287 = F_140 ( V_12 , V_2 ) ;
if ( ! V_287 ) {
F_135 ( V_35 ) ;
return V_51 ;
}
if ( F_136 ( V_287 ) )
V_35 -> V_42 = F_104 ( V_2 -> V_41 -> V_42 ) ;
V_287 -> V_55 -> V_45 = V_10 -> V_44 . V_45 ;
F_137 ( V_35 , V_287 ) ;
F_10 ( V_14 , V_48 ,
F_24 ( V_35 ) ) ;
F_14 ( V_8 , V_49 ) ;
if ( ! F_1 ( V_2 , sizeof( V_18 ) ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
return V_51 ;
}
T_2 F_144 ( struct V_8 * V_8 ,
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
return F_143 ( V_8 , V_10 , NULL , type , V_13 , V_14 ) ;
}
T_2 F_145 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type , void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
struct V_1 * V_288 = NULL ;
struct V_289 * V_290 = NULL ;
T_20 * V_291 ;
T_15 V_292 ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_254 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! V_8 -> V_38 . V_293 && ! V_2 -> V_93 )
return F_84 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_294 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_291 = ( T_20 * ) V_2 -> V_55 -> V_56 ;
V_292 = F_104 ( V_291 -> V_292 ) ;
if ( ! F_146 ( V_12 , V_2 , true , & V_290 ) )
return F_61 ( V_8 , V_10 , V_12 , type , V_13 ,
( void * ) V_290 , V_14 ) ;
if ( V_292 == V_12 -> V_96 . V_295 + 1 ) {
if ( ! V_2 -> V_296 )
F_147 ( V_12 ) ;
V_288 = F_148 ( (struct V_11 * )
V_12 , V_2 ) ;
if ( ! V_288 )
return V_51 ;
} else if ( V_292 < V_12 -> V_96 . V_295 + 1 ) {
V_288 = F_149 ( V_12 , V_291 -> V_292 ) ;
if ( ! V_288 )
return V_134 ;
V_288 -> V_70 = NULL ;
} else {
return V_134 ;
}
V_288 -> V_207 = V_2 -> V_297 ;
F_10 ( V_14 , V_62 , F_34 ( V_288 ) ) ;
if ( V_12 -> V_298 ) {
F_54 ( V_10 , V_12 , type , V_12 -> V_298 , V_14 ) ;
( (struct V_11 * ) V_12 ) -> V_298 = NULL ;
}
return V_50 ;
}
T_2 F_150 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type , void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_288 = V_13 ;
struct V_1 * V_299 = V_12 -> V_300 ;
struct V_1 * abort ;
struct V_289 * V_290 = NULL ;
T_20 * V_301 ;
T_15 V_302 , V_303 ;
if ( ! F_37 ( V_288 , V_12 ) ) {
F_10 ( V_14 , V_254 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! V_8 -> V_38 . V_293 && ! V_288 -> V_93 )
return F_84 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_288 , sizeof( V_294 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_301 = ( T_20 * ) V_288 -> V_55 -> V_56 ;
V_303 = F_104 ( V_301 -> V_292 ) ;
if ( ! F_146 ( V_12 , V_288 , false , & V_290 ) )
return F_61 ( V_8 , V_10 , V_12 , type , V_13 ,
( void * ) V_290 , V_14 ) ;
if ( V_299 ) {
V_301 = ( T_20 * ) V_299 -> V_52 . V_301 ;
V_302 = F_104 ( V_301 -> V_292 ) ;
} else {
V_302 = V_12 -> V_295 - 1 ;
}
if ( F_151 ( V_303 , V_302 + 1 ) &&
! ( V_12 -> V_300 ) ) {
abort = F_134 ( V_12 , V_288 ,
sizeof( V_164 ) ) ;
if ( abort ) {
F_152 ( abort , V_304 , 0 ) ;
F_10 ( V_14 , V_62 ,
F_34 ( abort ) ) ;
}
F_10 ( V_14 , V_22 ,
F_12 ( V_194 ) ) ;
F_10 ( V_14 , V_168 , F_16 () ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_305 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_304 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_231 ;
}
if ( ( V_303 == V_302 ) && V_12 -> V_300 ) {
F_10 ( V_14 , V_22 ,
F_12 ( V_194 ) ) ;
if ( ! F_153 ( (struct V_11 * ) V_12 ,
V_288 ) ) {
F_10 ( V_14 , V_306 ,
F_16 () ) ;
return V_50 ;
}
abort = F_134 ( V_12 , V_288 ,
sizeof( V_164 ) ) ;
if ( abort ) {
F_152 ( abort , V_307 , 0 ) ;
F_10 ( V_14 , V_62 ,
F_34 ( abort ) ) ;
}
F_10 ( V_14 , V_168 , F_16 () ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_305 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_304 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_231 ;
}
return V_134 ;
}
T_2 F_154 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
struct V_308 * V_309 ;
struct V_310 * V_311 ;
T_1 V_37 ;
T_15 V_312 ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_254 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_313 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_309 = (struct V_308 * ) V_2 -> V_55 -> V_56 ;
V_2 -> V_52 . V_309 = V_309 ;
V_37 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_37 -= sizeof( struct V_228 ) ;
F_25 ( V_2 -> V_55 , V_37 ) ;
V_312 = F_104 ( V_309 -> V_314 ) ;
F_67 ( L_7 , V_139 , V_312 ) ;
if ( F_155 ( & V_12 -> V_96 . V_315 , V_312 ) < 0 )
goto V_259;
F_156 (skip, chunk) {
if ( F_2 ( V_311 -> V_316 ) >= V_12 -> V_90 . V_101 )
goto V_259;
}
F_10 ( V_14 , V_317 , F_122 ( V_312 ) ) ;
if ( V_37 > sizeof( struct V_308 ) )
F_10 ( V_14 , V_318 ,
F_34 ( V_2 ) ) ;
if ( V_12 -> V_108 [ V_109 ] ) {
F_10 ( V_14 , V_245 ,
F_12 ( V_109 ) ) ;
}
F_10 ( V_14 , V_271 , F_125 () ) ;
return V_50 ;
V_259:
return V_134 ;
}
T_2 F_157 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
struct V_308 * V_309 ;
struct V_310 * V_311 ;
T_1 V_37 ;
T_15 V_312 ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_254 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_313 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_309 = (struct V_308 * ) V_2 -> V_55 -> V_56 ;
V_2 -> V_52 . V_309 = V_309 ;
V_37 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_37 -= sizeof( struct V_228 ) ;
F_25 ( V_2 -> V_55 , V_37 ) ;
V_312 = F_104 ( V_309 -> V_314 ) ;
F_67 ( L_7 , V_139 , V_312 ) ;
if ( F_155 ( & V_12 -> V_96 . V_315 , V_312 ) < 0 )
goto V_319;
F_156 (skip, chunk) {
if ( F_2 ( V_311 -> V_316 ) >= V_12 -> V_90 . V_101 )
goto V_319;
}
F_10 ( V_14 , V_317 , F_122 ( V_312 ) ) ;
if ( V_37 > sizeof( struct V_308 ) )
F_10 ( V_14 , V_318 ,
F_34 ( V_2 ) ) ;
V_319:
F_10 ( V_14 , V_272 , F_16 () ) ;
F_10 ( V_14 , V_271 , F_129 () ) ;
F_10 ( V_14 , V_245 ,
F_12 ( V_23 ) ) ;
return V_50 ;
}
static T_7 F_49 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
struct V_1 * V_2 )
{
struct V_320 * V_321 ;
struct V_322 * V_323 ;
unsigned int V_324 ;
T_1 V_325 ;
V_47 * V_326 ;
V_47 * V_327 ;
V_321 = (struct V_320 * ) V_2 -> V_55 -> V_56 ;
V_2 -> V_52 . V_321 = V_321 ;
F_25 ( V_2 -> V_55 , sizeof( struct V_320 ) ) ;
if ( ! F_158 ( V_12 , V_321 -> V_328 ) )
return V_329 ;
V_325 = F_2 ( V_321 -> V_330 ) ;
if ( V_325 != V_12 -> V_331 && ! F_159 ( V_12 , V_325 ) )
return V_332 ;
V_324 = F_2 ( V_2 -> V_5 -> V_6 ) - sizeof( V_333 ) ;
V_323 = F_160 ( F_2 ( V_321 -> V_328 ) ) ;
if ( V_324 != V_323 -> V_334 )
return V_265 ;
V_327 = V_321 -> V_323 ;
F_25 ( V_2 -> V_55 , V_324 ) ;
V_326 = F_161 ( V_327 , V_324 , V_20 ) ;
if ( ! V_326 )
goto V_59;
memset ( V_327 , 0 , V_324 ) ;
F_162 ( V_12 , V_2 -> V_55 ,
(struct V_335 * ) V_2 -> V_5 ,
V_20 ) ;
if ( memcmp ( V_326 , V_327 , V_324 ) ) {
F_163 ( V_326 ) ;
return V_89 ;
}
F_163 ( V_326 ) ;
V_2 -> V_93 = 1 ;
return V_98 ;
V_59:
return V_87 ;
}
T_2 F_164 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_320 * V_321 ;
struct V_1 * V_2 = V_13 ;
struct V_1 * V_33 ;
T_7 error ;
if ( ! V_12 -> V_96 . V_97 )
return F_165 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_254 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_335 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_321 = (struct V_320 * ) V_2 -> V_55 -> V_56 ;
error = F_49 ( V_8 , V_10 , V_12 , type , V_2 ) ;
switch ( error ) {
case V_329 :
V_33 = F_88 ( V_12 , V_2 ,
V_336 ,
& V_321 -> V_328 ,
sizeof( T_1 ) , 0 ) ;
if ( V_33 ) {
F_10 ( V_14 , V_62 ,
F_34 ( V_33 ) ) ;
}
case V_332 :
case V_89 :
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
case V_265 :
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
case V_87 :
return V_51 ;
default:
break;
}
if ( V_12 -> V_331 != F_2 ( V_321 -> V_330 ) ) {
struct V_15 * V_16 ;
V_16 = F_166 ( V_12 , F_2 ( V_321 -> V_330 ) ,
V_337 , V_20 ) ;
if ( ! V_16 )
return - V_338 ;
F_10 ( V_14 , V_21 ,
F_11 ( V_16 ) ) ;
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
struct V_1 * V_339 = V_13 ;
struct V_1 * V_33 ;
V_18 * V_291 ;
F_67 ( L_8 , V_139 , type . V_2 ) ;
if ( ! F_37 ( V_339 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_339 , sizeof( V_18 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
switch ( type . V_2 & V_340 ) {
case V_341 :
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
case V_342 :
V_291 = V_339 -> V_5 ;
V_33 = F_88 ( V_12 , V_339 ,
V_343 , V_291 ,
F_141 ( F_2 ( V_291 -> V_6 ) ) ,
0 ) ;
if ( V_33 ) {
F_10 ( V_14 , V_62 ,
F_34 ( V_33 ) ) ;
}
F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
return V_50 ;
case V_344 :
return V_134 ;
case V_345 :
V_291 = V_339 -> V_5 ;
V_33 = F_88 ( V_12 , V_339 ,
V_343 , V_291 ,
F_141 ( F_2 ( V_291 -> V_6 ) ) ,
0 ) ;
if ( V_33 ) {
F_10 ( V_14 , V_62 ,
F_34 ( V_33 ) ) ;
}
return V_50 ;
default:
break;
}
return V_134 ;
}
T_2 F_84 ( struct V_8 * V_8 ,
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
F_67 ( L_9 , V_139 , type . V_2 ) ;
return V_134 ;
}
T_2 F_6 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_14 ( V_8 , V_346 ) ;
F_10 ( V_14 , V_168 , F_16 () ) ;
return V_50 ;
}
T_2 F_167 ( struct V_8 * V_8 ,
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
return V_347 ;
}
static T_2 F_127 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
void * V_13 ,
T_4 * V_14 ,
const V_47 * V_348 ,
const T_9 V_125 )
{
struct V_34 * V_35 = NULL ;
struct V_1 * V_2 = V_13 ;
struct V_1 * abort = NULL ;
if ( F_38 ( V_67 , V_12 ) )
goto V_349;
abort = F_168 ( V_12 , V_2 , V_348 , V_125 ) ;
if ( ! abort )
goto V_59;
if ( V_12 ) {
if ( V_2 -> V_5 -> type == V_350 &&
! V_12 -> V_96 . V_351 . V_352 ) {
V_64 * V_353 ;
V_353 = ( V_64 * ) V_2 -> V_5 ;
if ( ! F_1 ( V_2 ,
sizeof( V_64 ) ) )
abort -> V_5 -> V_268 |= V_354 ;
else {
unsigned int V_355 ;
V_355 = F_104 ( V_353 -> V_53 . V_352 ) ;
F_10 ( V_14 , V_356 ,
F_122 ( V_355 ) ) ;
}
}
F_10 ( V_14 , V_62 , F_34 ( abort ) ) ;
F_14 ( V_8 , V_49 ) ;
if ( V_12 -> V_175 <= V_76 ) {
F_10 ( V_14 , V_22 ,
F_12 ( V_73 ) ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_69 ) ) ;
F_10 ( V_14 , V_217 ,
F_59 ( V_357 ) ) ;
} else {
F_10 ( V_14 , V_116 ,
F_58 ( V_305 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_357 ) ) ;
F_15 ( V_8 , V_28 ) ;
}
} else {
V_35 = F_133 ( V_8 , V_12 , V_2 ) ;
if ( ! V_35 )
goto V_358;
if ( F_136 ( abort ) )
V_35 -> V_42 = F_104 ( V_2 -> V_41 -> V_42 ) ;
abort -> V_55 -> V_45 = V_10 -> V_44 . V_45 ;
F_137 ( V_35 , abort ) ;
F_10 ( V_14 , V_48 ,
F_24 ( V_35 ) ) ;
F_14 ( V_8 , V_49 ) ;
}
F_14 ( V_8 , V_68 ) ;
V_349:
F_6 ( V_8 , V_10 , V_12 , F_87 ( 0 ) , V_13 , V_14 ) ;
return V_231 ;
V_358:
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
static const char V_359 [] = L_10 ;
return F_127 ( V_8 , V_10 , V_12 , V_13 , V_14 , V_359 ,
sizeof( V_359 ) ) ;
}
static T_2 F_61 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 , void * V_360 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
struct V_289 * V_361 = V_360 ;
struct V_1 * abort = NULL ;
if ( F_38 ( V_67 , V_12 ) )
goto V_349;
abort = F_169 ( V_12 , V_2 , V_361 ) ;
if ( ! abort )
goto V_59;
F_10 ( V_14 , V_62 , F_34 ( abort ) ) ;
F_14 ( V_8 , V_49 ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_305 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_357 ) ) ;
F_15 ( V_8 , V_28 ) ;
F_14 ( V_8 , V_68 ) ;
V_349:
F_6 ( V_8 , V_10 , V_12 , F_87 ( 0 ) , V_13 , V_14 ) ;
return V_231 ;
V_59:
return V_51 ;
}
static T_2 F_113 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
static const char V_359 [] = L_11 ;
return F_127 ( V_8 , V_10 , V_12 , V_13 , V_14 , V_359 ,
sizeof( V_359 ) ) ;
}
static T_2 F_7 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
static const char V_359 [] = L_12 ;
if ( ! V_12 )
return F_167 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
return F_127 ( V_8 , V_10 , V_12 , V_13 , V_14 , V_359 ,
sizeof( V_359 ) ) ;
}
T_2 F_170 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_31 ;
struct V_11 * V_362 ;
F_10 ( V_14 , V_25 ,
F_13 ( V_176 ) ) ;
V_31 = F_106 ( V_12 , & V_12 -> V_44 . V_206 , V_20 , 0 ) ;
if ( ! V_31 )
goto V_59;
F_10 ( V_14 , V_363 ,
F_34 ( V_31 ) ) ;
V_362 = (struct V_11 * ) V_12 ;
F_10 ( V_14 , V_61 , F_33 ( V_362 ) ) ;
F_10 ( V_14 , V_74 ,
F_12 ( V_73 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
return V_50 ;
V_59:
return V_51 ;
}
T_2 F_171 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_364 * V_365 = V_13 ;
F_10 ( V_14 , V_366 , F_172 ( V_365 ) ) ;
return V_50 ;
}
T_2 F_173 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
int V_188 ;
F_10 ( V_14 , V_25 ,
F_13 ( V_367 ) ) ;
V_188 = V_50 ;
if ( F_115 ( & V_12 -> V_242 ) ) {
V_188 = F_90 ( V_8 , V_10 , V_12 , type ,
V_13 , V_14 ) ;
}
return V_188 ;
}
T_2 F_174 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * abort = V_13 ;
T_2 V_183 ;
V_183 = V_50 ;
if ( abort )
F_10 ( V_14 , V_62 , F_34 ( abort ) ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_305 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_368 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_183 ;
}
T_2 F_175 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_10 ( V_14 , V_369 , F_58 ( - V_370 ) ) ;
return V_50 ;
}
T_2 F_176 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_10 ( V_14 , V_369 ,
F_58 ( - V_371 ) ) ;
return V_50 ;
}
T_2 F_177 (
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
T_2 F_178 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 , T_4 * V_14 )
{
return F_177 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_179 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * abort = V_13 ;
T_2 V_183 ;
F_10 ( V_14 , V_22 ,
F_12 ( V_73 ) ) ;
V_183 = V_50 ;
if ( abort )
F_10 ( V_14 , V_62 , F_34 ( abort ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_26 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_69 ) ) ;
F_10 ( V_14 , V_217 ,
F_59 ( V_368 ) ) ;
return V_183 ;
}
T_2 F_180 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return F_179 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_181 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_10 ( V_14 , V_22 ,
F_12 ( V_24 ) ) ;
return F_174 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_182 (
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
return F_174 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_183 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return F_182 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
T_2 F_184 (
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
T_2 F_185 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
F_10 ( V_14 , V_372 , F_34 ( V_2 ) ) ;
F_10 ( V_14 , V_74 ,
F_12 ( V_194 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_2 ) ) ;
return V_50 ;
}
T_2 F_186 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_67 ( L_13 , V_139 ,
type . V_373 ) ;
return V_134 ;
}
T_2 F_187 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_15 * V_374 ;
V_374 = F_188 ( V_12 , V_20 ) ;
if ( ! V_374 )
return V_51 ;
F_10 ( V_14 , V_21 , F_11 ( V_374 ) ) ;
return V_50 ;
}
T_2 F_90 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_112 ;
V_112 = F_189 ( V_12 , NULL ) ;
if ( ! V_112 )
goto V_59;
F_10 ( V_14 , V_244 , F_34 ( V_112 ) ) ;
F_10 ( V_14 , V_74 ,
F_12 ( V_23 ) ) ;
F_10 ( V_14 , V_245 ,
F_12 ( V_24 ) ) ;
if ( V_12 -> V_108 [ V_109 ] )
F_10 ( V_14 , V_22 ,
F_12 ( V_109 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_375 ) ) ;
F_10 ( V_14 , V_223 , F_16 () ) ;
F_10 ( V_14 , V_62 , F_34 ( V_112 ) ) ;
return V_50 ;
V_59:
return V_51 ;
}
T_2 F_116 (
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
if ( ! F_1 ( V_2 , sizeof( struct V_236 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
}
V_112 = F_119 ( V_12 , V_2 ) ;
if ( ! V_112 )
goto V_59;
F_10 ( V_14 , V_244 , F_34 ( V_112 ) ) ;
F_10 ( V_14 , V_245 ,
F_12 ( V_23 ) ) ;
if ( V_12 -> V_108 [ V_109 ] )
F_10 ( V_14 , V_22 ,
F_12 ( V_109 ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_376 ) ) ;
F_10 ( V_14 , V_223 , F_16 () ) ;
F_10 ( V_14 , V_62 , F_34 ( V_112 ) ) ;
return V_50 ;
V_59:
return V_51 ;
}
T_2 F_190 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_67 ( L_14 ,
V_139 , type . V_377 ) ;
return V_134 ;
}
T_2 F_191 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_111 * V_70 = V_13 ;
F_14 ( V_8 , V_378 ) ;
if ( V_12 -> V_114 >= V_12 -> V_115 ) {
if ( V_12 -> V_96 . V_379 &&
V_12 -> V_175 == V_367 ) {
F_10 ( V_14 , V_380 ,
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
F_10 ( V_14 , V_381 , F_56 ( V_70 ) ) ;
F_10 ( V_14 , V_382 , F_56 ( V_70 ) ) ;
return V_50 ;
}
T_2 F_192 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_14 ( V_8 , V_383 ) ;
F_10 ( V_14 , V_271 , F_129 () ) ;
return V_50 ;
}
T_2 F_193 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_31 = NULL ;
struct V_212 * V_213 ;
int V_214 = V_12 -> V_215 + 1 ;
F_67 ( L_15 , V_139 ) ;
F_14 ( V_8 , V_384 ) ;
if ( V_214 <= V_12 -> V_216 ) {
V_213 = (struct V_212 * ) & V_12 -> V_44 . V_206 ;
V_31 = F_106 ( V_12 , V_213 , V_20 , 0 ) ;
if ( ! V_31 )
return V_51 ;
F_10 ( V_14 , V_363 ,
F_34 ( V_31 ) ) ;
F_10 ( V_14 , V_385 ,
F_12 ( V_73 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
} else {
F_67 ( L_16
L_17 , V_139 , V_214 ,
V_12 -> V_216 ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_217 ,
F_59 ( V_119 ) ) ;
return V_30 ;
}
return V_50 ;
}
T_2 F_194 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_31 = NULL ;
int V_214 = V_12 -> V_215 + 1 ;
F_67 ( L_18 , V_139 ) ;
F_14 ( V_8 , V_386 ) ;
if ( V_214 <= V_12 -> V_216 ) {
V_31 = F_195 ( V_12 , NULL ) ;
if ( ! V_31 )
return V_51 ;
F_10 ( V_14 , V_363 ,
F_34 ( V_31 ) ) ;
F_10 ( V_14 , V_387 ,
F_12 ( V_75 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_31 ) ) ;
} else {
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_217 ,
F_59 ( V_119 ) ) ;
return V_30 ;
}
return V_50 ;
}
T_2 F_196 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_112 = NULL ;
F_67 ( L_19 , V_139 ) ;
F_14 ( V_8 , V_388 ) ;
( (struct V_11 * ) V_12 ) -> V_389 ++ ;
if ( V_12 -> V_114 >= V_12 -> V_115 ) {
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_119 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_30 ;
}
switch ( V_12 -> V_175 ) {
case V_375 :
V_112 = F_189 ( V_12 , NULL ) ;
break;
case V_376 :
V_112 = F_119 ( V_12 , NULL ) ;
break;
default:
F_128 () ;
break;
}
if ( ! V_112 )
goto V_59;
if ( V_12 -> V_390 )
F_10 ( V_14 , V_381 ,
F_56 ( V_12 -> V_390 ) ) ;
F_10 ( V_14 , V_244 , F_34 ( V_112 ) ) ;
F_10 ( V_14 , V_245 ,
F_12 ( V_23 ) ) ;
F_10 ( V_14 , V_62 , F_34 ( V_112 ) ) ;
return V_50 ;
V_59:
return V_51 ;
}
T_2 F_197 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_12 -> V_300 ;
struct V_111 * V_70 = V_2 -> V_70 ;
F_14 ( V_8 , V_391 ) ;
if ( V_70 )
F_10 ( V_14 , V_381 ,
F_56 ( V_70 ) ) ;
F_10 ( V_14 , V_372 , F_34 ( V_2 ) ) ;
if ( V_12 -> V_114 >= V_12 -> V_115 ) {
F_10 ( V_14 , V_22 ,
F_12 ( V_194 ) ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_117 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_119 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_231 ;
}
F_198 ( V_12 -> V_300 ) ;
F_10 ( V_14 , V_62 ,
F_34 ( V_12 -> V_300 ) ) ;
F_10 ( V_14 , V_245 ,
F_12 ( V_194 ) ) ;
return V_50 ;
}
T_2 F_199 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_112 = NULL ;
F_67 ( L_20 , V_139 ) ;
F_14 ( V_8 , V_392 ) ;
V_112 = F_134 ( V_12 , NULL , 0 ) ;
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
T_2 F_200 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
int V_188 ;
F_14 ( V_8 , V_393 ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_367 ) ) ;
V_188 = V_50 ;
if ( F_115 ( & V_12 -> V_242 ) ) {
V_188 = F_90 ( V_8 , V_10 , V_12 , type ,
V_13 , V_14 ) ;
}
return V_188 ;
}
T_2 F_201 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return V_394 ;
}
T_2 F_202 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return V_395 ;
}
T_2 F_203 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_67 ( L_21 , V_139 , type . V_2 ) ;
return V_50 ;
}
static struct V_396 * F_132 ( struct V_1 * V_2 )
{
struct V_396 * V_397 ;
unsigned int V_37 ;
T_1 V_398 ;
T_1 V_399 ;
V_397 = (struct V_396 * ) V_2 -> V_55 -> V_56 ;
V_398 = F_2 ( V_397 -> V_400 ) ;
V_399 = F_2 ( V_397 -> V_399 ) ;
V_37 = sizeof( struct V_396 ) ;
V_37 += ( V_398 + V_399 ) * sizeof( T_15 ) ;
if ( V_37 > V_2 -> V_55 -> V_37 )
return NULL ;
F_25 ( V_2 -> V_55 , V_37 ) ;
return V_397 ;
}
static struct V_34 * F_22 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
struct V_1 * V_2 ,
const void * V_348 ,
T_9 V_125 )
{
struct V_34 * V_35 ;
struct V_1 * abort ;
V_35 = F_133 ( V_8 , V_12 , V_2 ) ;
if ( V_35 ) {
abort = F_134 ( V_12 , V_2 , V_125 ) ;
if ( ! abort ) {
F_135 ( V_35 ) ;
return NULL ;
}
if ( F_136 ( abort ) )
V_35 -> V_42 = F_104 ( V_2 -> V_41 -> V_42 ) ;
F_32 ( abort , V_125 , V_348 ) ;
abort -> V_55 -> V_45 = V_10 -> V_44 . V_45 ;
F_137 ( V_35 , abort ) ;
}
return V_35 ;
}
static struct V_34 * F_133 ( struct V_8 * V_8 ,
const struct V_11 * V_12 ,
const struct V_1 * V_2 )
{
struct V_34 * V_35 ;
struct V_111 * V_70 ;
T_1 V_401 ;
T_1 V_402 ;
T_15 V_42 ;
V_401 = F_2 ( V_2 -> V_41 -> V_207 ) ;
V_402 = F_2 ( V_2 -> V_41 -> V_297 ) ;
if ( V_12 ) {
switch ( V_2 -> V_5 -> type ) {
case V_350 :
{
V_64 * V_353 ;
V_353 = ( V_64 * ) V_2 -> V_5 ;
V_42 = F_104 ( V_353 -> V_53 . V_352 ) ;
break;
}
default:
V_42 = V_12 -> V_96 . V_351 . V_352 ;
break;
}
} else {
switch ( V_2 -> V_5 -> type ) {
case V_403 :
{
V_43 * V_152 ;
V_152 = ( V_43 * ) V_2 -> V_5 ;
V_42 = F_104 ( V_152 -> V_53 . V_352 ) ;
break;
}
default:
V_42 = F_104 ( V_2 -> V_41 -> V_42 ) ;
break;
}
}
V_70 = F_204 ( V_8 , F_29 ( V_2 ) , V_20 ) ;
if ( ! V_70 )
goto V_59;
F_205 ( V_70 , (union V_129 * ) & V_2 -> V_207 ,
F_18 ( V_8 -> V_38 . V_39 ) ) ;
V_35 = F_206 ( & V_70 -> V_35 , V_70 , V_401 , V_402 ) ;
V_35 = F_207 ( V_35 , V_42 , 0 ) ;
return V_35 ;
V_59:
return NULL ;
}
void F_135 ( struct V_34 * V_35 )
{
F_208 ( V_35 -> V_70 ) ;
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
V_35 = F_133 ( V_8 , V_12 , V_2 ) ;
if ( V_35 ) {
struct V_86 * V_404 ;
V_404 = V_2 -> V_52 . V_85 ;
V_35 -> V_42 = V_404 -> V_90 . V_180 ;
V_33 -> V_55 -> V_45 = V_10 -> V_44 . V_45 ;
F_137 ( V_35 , V_33 ) ;
F_10 ( V_14 , V_48 ,
F_24 ( V_35 ) ) ;
F_14 ( V_8 , V_49 ) ;
} else
F_23 ( V_33 ) ;
}
}
static int F_126 ( const struct V_11 * V_12 ,
struct V_1 * V_2 ,
T_4 * V_14 )
{
V_267 * V_266 ;
struct V_1 * V_187 ;
T_9 V_405 ;
T_21 V_406 ;
int V_407 ;
T_15 V_312 ;
struct V_408 * V_409 = (struct V_408 * ) & V_12 -> V_96 . V_315 ;
struct V_82 * V_45 = V_12 -> V_44 . V_45 ;
struct V_8 * V_8 = F_75 ( V_45 ) ;
T_22 V_410 ;
T_22 V_411 ;
V_219 V_412 = 0 ;
V_266 = V_2 -> V_52 . V_266 = ( V_267 * ) V_2 -> V_55 -> V_56 ;
F_25 ( V_2 -> V_55 , sizeof( V_267 ) ) ;
V_312 = F_104 ( V_266 -> V_312 ) ;
F_67 ( L_7 , V_139 , V_312 ) ;
if ( ! V_2 -> V_413 ) {
struct V_159 * V_160 ;
V_2 -> V_413 = 1 ;
V_160 = F_69 (
F_209 ( F_210 ( V_2 -> V_55 ) -> V_414 ) ) ;
if ( V_160 && V_160 -> V_415 ( V_2 -> V_55 ) && V_12 -> V_96 . V_416 ) {
F_10 ( V_14 , V_417 ,
F_122 ( V_312 ) ) ;
}
}
V_407 = F_155 ( & V_12 -> V_96 . V_315 , V_312 ) ;
if ( V_407 < 0 ) {
if ( V_2 -> V_12 )
V_2 -> V_12 -> V_418 . V_419 ++ ;
return V_256 ;
} else if ( V_407 > 0 ) {
F_10 ( V_14 , V_420 , F_122 ( V_312 ) ) ;
return V_260 ;
}
V_405 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_405 -= sizeof( V_255 ) ;
V_406 = V_421 ;
if ( ( V_405 >= V_12 -> V_181 ) && ( ! V_12 -> V_422 . V_423 ) ) {
F_10 ( V_14 , V_424 , F_16 () ) ;
}
if ( ( ! V_2 -> V_425 ) && ( ! V_12 -> V_181 || V_12 -> V_426 ||
( V_405 > V_12 -> V_181 + V_12 -> V_427 ) ) ) {
if ( F_211 ( V_409 ) &&
( F_212 ( V_409 ) + 1 ) == V_312 ) {
F_67 ( L_22 , V_139 , V_312 ) ;
V_406 = V_428 ;
} else {
F_67 ( L_23 ,
V_139 , V_312 , V_405 , V_12 -> V_181 ) ;
return V_261 ;
}
}
if ( * V_45 -> V_429 -> V_430 ) {
if ( F_211 ( V_409 ) &&
( F_212 ( V_409 ) + 1 ) == V_312 ) {
F_67 ( L_24 ,
V_139 , V_312 ) ;
V_406 = V_428 ;
}
}
if ( F_3 ( 0 == V_405 ) ) {
V_187 = F_213 ( V_12 , V_2 , V_312 ) ;
if ( V_187 ) {
F_10 ( V_14 , V_62 ,
F_34 ( V_187 ) ) ;
}
F_10 ( V_14 , V_168 , F_16 () ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_305 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_431 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_263 ;
}
V_2 -> V_425 = 1 ;
if ( V_2 -> V_5 -> V_268 & V_432 ) {
F_14 ( V_8 , V_433 ) ;
if ( V_2 -> V_12 )
V_2 -> V_12 -> V_418 . V_434 ++ ;
} else {
F_14 ( V_8 , V_435 ) ;
if ( V_2 -> V_12 )
V_2 -> V_12 -> V_418 . V_436 ++ ;
V_412 = 1 ;
}
V_411 = F_2 ( V_266 -> V_316 ) ;
if ( V_411 >= V_12 -> V_90 . V_101 ) {
F_10 ( V_14 , V_437 , F_122 ( V_312 ) ) ;
V_187 = F_88 ( V_12 , V_2 , V_438 ,
& V_266 -> V_316 ,
sizeof( V_266 -> V_316 ) ,
sizeof( T_22 ) ) ;
if ( V_187 )
F_10 ( V_14 , V_62 ,
F_34 ( V_187 ) ) ;
return V_257 ;
}
V_410 = F_2 ( V_266 -> V_410 ) ;
if ( V_412 && F_214 ( V_410 , F_215 ( & V_12 -> V_439 -> V_440 , V_411 ) ) ) {
return V_265 ;
}
F_10 ( V_14 , V_406 , F_34 ( V_2 ) ) ;
return V_98 ;
}
