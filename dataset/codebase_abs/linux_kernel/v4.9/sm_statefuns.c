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
return V_231 ;
case V_264 :
return F_127 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
( V_219 * ) V_2 -> V_52 . V_265 , sizeof( V_266 ) ) ;
default:
F_128 () ;
}
if ( V_2 -> V_5 -> V_267 & V_268 )
V_253 = F_129 () ;
if ( V_12 -> V_108 [ V_109 ] ) {
F_10 ( V_14 , V_245 ,
F_12 ( V_109 ) ) ;
}
if ( V_2 -> V_269 )
F_10 ( V_14 , V_270 , V_253 ) ;
return V_50 ;
V_262:
if ( V_2 -> V_269 )
F_10 ( V_14 , V_270 , F_129 () ) ;
return V_134 ;
V_259:
if ( V_2 -> V_269 )
F_10 ( V_14 , V_270 , V_253 ) ;
return V_134 ;
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
return V_231 ;
case V_264 :
return F_127 ( V_8 , V_10 , V_12 , V_2 , V_14 ,
( V_219 * ) V_2 -> V_52 . V_265 , sizeof( V_266 ) ) ;
default:
F_128 () ;
}
if ( V_2 -> V_269 ) {
F_10 ( V_14 , V_271 , F_16 () ) ;
F_10 ( V_14 , V_270 , F_129 () ) ;
F_10 ( V_14 , V_245 ,
F_12 ( V_23 ) ) ;
}
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
T_19 * V_272 ;
T_15 V_235 ;
if ( ! F_37 ( V_2 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_273 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_272 = F_132 ( V_2 ) ;
if ( ! V_272 )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
V_2 -> V_52 . V_274 = V_272 ;
V_235 = F_104 ( V_272 -> V_238 ) ;
if ( F_112 ( V_235 , V_12 -> V_239 ) ) {
F_67 ( L_6 , V_139 , V_235 ,
V_12 -> V_239 ) ;
return V_134 ;
}
if ( ! F_112 ( V_235 , V_12 -> V_240 ) )
return F_113 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
F_10 ( V_14 , V_275 , F_34 ( V_2 ) ) ;
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
F_10 ( V_14 , V_276 ,
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
goto V_277;
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
V_277:
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
struct V_278 * V_55 = V_2 -> V_55 ;
V_18 * V_279 ;
V_164 * V_187 ;
V_47 * V_280 ;
int V_281 = 0 ;
int V_282 = 0 ;
F_14 ( V_8 , V_40 ) ;
V_279 = ( V_18 * ) V_2 -> V_5 ;
do {
if ( F_2 ( V_279 -> V_6 ) < sizeof( V_18 ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_280 = ( ( V_47 * ) V_279 ) + F_141 ( F_2 ( V_279 -> V_6 ) ) ;
if ( V_280 > F_142 ( V_55 ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
if ( V_283 == V_279 -> type )
V_281 = 1 ;
if ( V_67 == V_279 -> type )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( V_284 == V_279 -> type )
V_282 = 1 ;
if ( V_285 == V_279 -> type ) {
F_102 (err, ch) {
if ( V_209 == V_187 -> V_165 ) {
V_282 = 1 ;
break;
}
}
}
V_279 = ( V_18 * ) V_280 ;
} while ( V_280 < F_142 ( V_55 ) );
if ( V_281 )
return F_143 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
else if ( V_282 )
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
struct V_1 * V_286 ;
V_35 = F_133 ( V_8 , V_12 , V_2 ) ;
if ( V_35 ) {
V_286 = F_140 ( V_12 , V_2 ) ;
if ( ! V_286 ) {
F_135 ( V_35 ) ;
return V_51 ;
}
if ( F_136 ( V_286 ) )
V_35 -> V_42 = F_104 ( V_2 -> V_41 -> V_42 ) ;
V_286 -> V_55 -> V_45 = V_10 -> V_44 . V_45 ;
F_137 ( V_35 , V_286 ) ;
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
struct V_1 * V_287 = NULL ;
struct V_288 * V_289 = NULL ;
T_20 * V_290 ;
T_15 V_291 ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_254 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! V_8 -> V_38 . V_292 && ! V_2 -> V_93 )
return F_84 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_2 , sizeof( V_293 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_290 = ( T_20 * ) V_2 -> V_55 -> V_56 ;
V_291 = F_104 ( V_290 -> V_291 ) ;
if ( ! F_146 ( V_12 , V_2 , true , & V_289 ) )
return F_61 ( V_8 , V_10 , V_12 , type , V_13 ,
( void * ) V_289 , V_14 ) ;
if ( V_291 == V_12 -> V_96 . V_294 + 1 ) {
if ( ! V_2 -> V_295 )
F_147 ( V_12 ) ;
V_287 = F_148 ( (struct V_11 * )
V_12 , V_2 ) ;
if ( ! V_287 )
return V_51 ;
} else if ( V_291 < V_12 -> V_96 . V_294 + 1 ) {
V_287 = F_149 ( V_12 , V_290 -> V_291 ) ;
if ( ! V_287 )
return V_134 ;
V_287 -> V_70 = NULL ;
} else {
return V_134 ;
}
V_287 -> V_207 = V_2 -> V_296 ;
F_10 ( V_14 , V_62 , F_34 ( V_287 ) ) ;
if ( V_12 -> V_297 ) {
F_54 ( V_10 , V_12 , type , V_12 -> V_297 , V_14 ) ;
( (struct V_11 * ) V_12 ) -> V_297 = NULL ;
}
return V_50 ;
}
T_2 F_150 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type , void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_287 = V_13 ;
struct V_1 * V_298 = V_12 -> V_299 ;
struct V_1 * abort ;
struct V_288 * V_289 = NULL ;
T_20 * V_300 ;
T_15 V_301 , V_302 ;
if ( ! F_37 ( V_287 , V_12 ) ) {
F_10 ( V_14 , V_254 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! V_8 -> V_38 . V_292 && ! V_287 -> V_93 )
return F_84 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_287 , sizeof( V_293 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_300 = ( T_20 * ) V_287 -> V_55 -> V_56 ;
V_302 = F_104 ( V_300 -> V_291 ) ;
if ( ! F_146 ( V_12 , V_287 , false , & V_289 ) )
return F_61 ( V_8 , V_10 , V_12 , type , V_13 ,
( void * ) V_289 , V_14 ) ;
if ( V_298 ) {
V_300 = ( T_20 * ) V_298 -> V_52 . V_300 ;
V_301 = F_104 ( V_300 -> V_291 ) ;
} else {
V_301 = V_12 -> V_294 - 1 ;
}
if ( F_151 ( V_302 , V_301 + 1 ) &&
! ( V_12 -> V_299 ) ) {
abort = F_134 ( V_12 , V_287 ,
sizeof( V_164 ) ) ;
if ( abort ) {
F_152 ( abort , V_303 , 0 ) ;
F_10 ( V_14 , V_62 ,
F_34 ( abort ) ) ;
}
F_10 ( V_14 , V_22 ,
F_12 ( V_194 ) ) ;
F_10 ( V_14 , V_168 , F_16 () ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_304 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_303 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_231 ;
}
if ( ( V_302 == V_301 ) && V_12 -> V_299 ) {
F_10 ( V_14 , V_22 ,
F_12 ( V_194 ) ) ;
if ( ! F_153 ( (struct V_11 * ) V_12 ,
V_287 ) ) {
F_10 ( V_14 , V_305 ,
F_16 () ) ;
return V_50 ;
}
abort = F_134 ( V_12 , V_287 ,
sizeof( V_164 ) ) ;
if ( abort ) {
F_152 ( abort , V_306 , 0 ) ;
F_10 ( V_14 , V_62 ,
F_34 ( abort ) ) ;
}
F_10 ( V_14 , V_168 , F_16 () ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_304 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_303 ) ) ;
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
struct V_307 * V_308 ;
struct V_309 * V_310 ;
T_1 V_37 ;
T_15 V_311 ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_254 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_312 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_308 = (struct V_307 * ) V_2 -> V_55 -> V_56 ;
V_2 -> V_52 . V_308 = V_308 ;
V_37 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_37 -= sizeof( struct V_228 ) ;
F_25 ( V_2 -> V_55 , V_37 ) ;
V_311 = F_104 ( V_308 -> V_313 ) ;
F_67 ( L_7 , V_139 , V_311 ) ;
if ( F_155 ( & V_12 -> V_96 . V_314 , V_311 ) < 0 )
goto V_259;
F_156 (skip, chunk) {
if ( F_2 ( V_310 -> V_315 ) >= V_12 -> V_90 . V_101 )
goto V_259;
}
F_10 ( V_14 , V_316 , F_122 ( V_311 ) ) ;
if ( V_37 > sizeof( struct V_307 ) )
F_10 ( V_14 , V_317 ,
F_34 ( V_2 ) ) ;
if ( V_12 -> V_108 [ V_109 ] ) {
F_10 ( V_14 , V_245 ,
F_12 ( V_109 ) ) ;
}
F_10 ( V_14 , V_270 , F_125 () ) ;
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
struct V_307 * V_308 ;
struct V_309 * V_310 ;
T_1 V_37 ;
T_15 V_311 ;
if ( ! F_37 ( V_2 , V_12 ) ) {
F_10 ( V_14 , V_254 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_312 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_308 = (struct V_307 * ) V_2 -> V_55 -> V_56 ;
V_2 -> V_52 . V_308 = V_308 ;
V_37 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_37 -= sizeof( struct V_228 ) ;
F_25 ( V_2 -> V_55 , V_37 ) ;
V_311 = F_104 ( V_308 -> V_313 ) ;
F_67 ( L_7 , V_139 , V_311 ) ;
if ( F_155 ( & V_12 -> V_96 . V_314 , V_311 ) < 0 )
goto V_318;
F_156 (skip, chunk) {
if ( F_2 ( V_310 -> V_315 ) >= V_12 -> V_90 . V_101 )
goto V_318;
}
F_10 ( V_14 , V_316 , F_122 ( V_311 ) ) ;
if ( V_37 > sizeof( struct V_307 ) )
F_10 ( V_14 , V_317 ,
F_34 ( V_2 ) ) ;
V_318:
F_10 ( V_14 , V_271 , F_16 () ) ;
F_10 ( V_14 , V_270 , F_129 () ) ;
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
struct V_319 * V_320 ;
struct V_321 * V_322 ;
unsigned int V_323 ;
T_1 V_324 ;
V_47 * V_325 ;
V_47 * V_326 ;
V_320 = (struct V_319 * ) V_2 -> V_55 -> V_56 ;
V_2 -> V_52 . V_320 = V_320 ;
F_25 ( V_2 -> V_55 , sizeof( struct V_319 ) ) ;
if ( ! F_158 ( V_12 , V_320 -> V_327 ) )
return V_328 ;
V_324 = F_2 ( V_320 -> V_329 ) ;
if ( V_324 != V_12 -> V_330 && ! F_159 ( V_12 , V_324 ) )
return V_331 ;
V_323 = F_2 ( V_2 -> V_5 -> V_6 ) - sizeof( V_332 ) ;
V_322 = F_160 ( F_2 ( V_320 -> V_327 ) ) ;
if ( V_323 != V_322 -> V_333 )
return V_264 ;
V_326 = V_320 -> V_322 ;
F_25 ( V_2 -> V_55 , V_323 ) ;
V_325 = F_161 ( V_326 , V_323 , V_20 ) ;
if ( ! V_325 )
goto V_59;
memset ( V_326 , 0 , V_323 ) ;
F_162 ( V_12 , V_2 -> V_55 ,
(struct V_334 * ) V_2 -> V_5 ,
V_20 ) ;
if ( memcmp ( V_325 , V_326 , V_323 ) ) {
F_163 ( V_325 ) ;
return V_89 ;
}
F_163 ( V_325 ) ;
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
struct V_319 * V_320 ;
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
if ( ! F_1 ( V_2 , sizeof( struct V_334 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
V_320 = (struct V_319 * ) V_2 -> V_55 -> V_56 ;
error = F_49 ( V_8 , V_10 , V_12 , type , V_2 ) ;
switch ( error ) {
case V_328 :
V_33 = F_88 ( V_12 , V_2 ,
V_335 ,
& V_320 -> V_327 ,
sizeof( T_1 ) , 0 ) ;
if ( V_33 ) {
F_10 ( V_14 , V_62 ,
F_34 ( V_33 ) ) ;
}
case V_331 :
case V_89 :
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
case V_264 :
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
case V_87 :
return V_51 ;
default:
break;
}
if ( V_12 -> V_330 != F_2 ( V_320 -> V_329 ) ) {
struct V_15 * V_16 ;
V_16 = F_166 ( V_12 , F_2 ( V_320 -> V_329 ) ,
V_336 , V_20 ) ;
if ( ! V_16 )
return - V_337 ;
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
struct V_1 * V_338 = V_13 ;
struct V_1 * V_33 ;
V_18 * V_290 ;
F_67 ( L_8 , V_139 , type . V_2 ) ;
if ( ! F_37 ( V_338 , V_12 ) )
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
if ( ! F_1 ( V_338 , sizeof( V_18 ) ) )
return F_8 ( V_8 , V_10 , V_12 , type , V_13 ,
V_14 ) ;
switch ( type . V_2 & V_339 ) {
case V_340 :
return F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
case V_341 :
V_290 = V_338 -> V_5 ;
V_33 = F_88 ( V_12 , V_338 ,
V_342 , V_290 ,
F_141 ( F_2 ( V_290 -> V_6 ) ) ,
0 ) ;
if ( V_33 ) {
F_10 ( V_14 , V_62 ,
F_34 ( V_33 ) ) ;
}
F_6 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
return V_50 ;
case V_343 :
return V_134 ;
case V_344 :
V_290 = V_338 -> V_5 ;
V_33 = F_88 ( V_12 , V_338 ,
V_342 , V_290 ,
F_141 ( F_2 ( V_290 -> V_6 ) ) ,
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
F_14 ( V_8 , V_345 ) ;
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
return V_346 ;
}
static T_2 F_127 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
void * V_13 ,
T_4 * V_14 ,
const V_47 * V_347 ,
const T_9 V_125 )
{
struct V_34 * V_35 = NULL ;
struct V_1 * V_2 = V_13 ;
struct V_1 * abort = NULL ;
if ( F_38 ( V_67 , V_12 ) )
goto V_348;
abort = F_168 ( V_12 , V_2 , V_347 , V_125 ) ;
if ( ! abort )
goto V_59;
if ( V_12 ) {
if ( V_2 -> V_5 -> type == V_349 &&
! V_12 -> V_96 . V_350 . V_351 ) {
V_64 * V_352 ;
V_352 = ( V_64 * ) V_2 -> V_5 ;
if ( ! F_1 ( V_2 ,
sizeof( V_64 ) ) )
abort -> V_5 -> V_267 |= V_353 ;
else {
unsigned int V_354 ;
V_354 = F_104 ( V_352 -> V_53 . V_351 ) ;
F_10 ( V_14 , V_355 ,
F_122 ( V_354 ) ) ;
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
F_59 ( V_356 ) ) ;
} else {
F_10 ( V_14 , V_116 ,
F_58 ( V_304 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_356 ) ) ;
F_15 ( V_8 , V_28 ) ;
}
} else {
V_35 = F_133 ( V_8 , V_12 , V_2 ) ;
if ( ! V_35 )
goto V_357;
if ( F_136 ( abort ) )
V_35 -> V_42 = F_104 ( V_2 -> V_41 -> V_42 ) ;
abort -> V_55 -> V_45 = V_10 -> V_44 . V_45 ;
F_137 ( V_35 , abort ) ;
F_10 ( V_14 , V_48 ,
F_24 ( V_35 ) ) ;
F_14 ( V_8 , V_49 ) ;
}
F_14 ( V_8 , V_68 ) ;
V_348:
F_6 ( V_8 , V_10 , V_12 , F_87 ( 0 ) , V_13 , V_14 ) ;
return V_231 ;
V_357:
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
static const char V_358 [] = L_10 ;
return F_127 ( V_8 , V_10 , V_12 , V_13 , V_14 , V_358 ,
sizeof( V_358 ) ) ;
}
static T_2 F_61 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 , void * V_359 ,
T_4 * V_14 )
{
struct V_1 * V_2 = V_13 ;
struct V_288 * V_360 = V_359 ;
struct V_1 * abort = NULL ;
if ( F_38 ( V_67 , V_12 ) )
goto V_348;
abort = F_169 ( V_12 , V_2 , V_360 ) ;
if ( ! abort )
goto V_59;
F_10 ( V_14 , V_62 , F_34 ( abort ) ) ;
F_14 ( V_8 , V_49 ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_304 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_356 ) ) ;
F_15 ( V_8 , V_28 ) ;
F_14 ( V_8 , V_68 ) ;
V_348:
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
static const char V_358 [] = L_11 ;
return F_127 ( V_8 , V_10 , V_12 , V_13 , V_14 , V_358 ,
sizeof( V_358 ) ) ;
}
static T_2 F_7 (
struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
static const char V_358 [] = L_12 ;
if ( ! V_12 )
return F_167 ( V_8 , V_10 , V_12 , type , V_13 , V_14 ) ;
return F_127 ( V_8 , V_10 , V_12 , V_13 , V_14 , V_358 ,
sizeof( V_358 ) ) ;
}
T_2 F_170 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
struct V_1 * V_31 ;
struct V_11 * V_361 ;
F_10 ( V_14 , V_25 ,
F_13 ( V_176 ) ) ;
V_31 = F_106 ( V_12 , & V_12 -> V_44 . V_206 , V_20 , 0 ) ;
if ( ! V_31 )
goto V_59;
F_10 ( V_14 , V_362 ,
F_34 ( V_31 ) ) ;
V_361 = (struct V_11 * ) V_12 ;
F_10 ( V_14 , V_61 , F_33 ( V_361 ) ) ;
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
struct V_363 * V_364 = V_13 ;
F_10 ( V_14 , V_365 , F_172 ( V_364 ) ) ;
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
F_13 ( V_366 ) ) ;
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
if ( abort )
F_10 ( V_14 , V_62 , F_34 ( abort ) ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_304 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_367 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_231 ;
}
T_2 F_175 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_10 ( V_14 , V_368 , F_58 ( - V_369 ) ) ;
return V_50 ;
}
T_2 F_176 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_10 ( V_14 , V_368 ,
F_58 ( - V_370 ) ) ;
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
F_10 ( V_14 , V_22 ,
F_12 ( V_73 ) ) ;
if ( abort )
F_10 ( V_14 , V_62 , F_34 ( abort ) ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_26 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_69 ) ) ;
F_10 ( V_14 , V_217 ,
F_59 ( V_367 ) ) ;
return V_231 ;
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
F_10 ( V_14 , V_371 , F_34 ( V_2 ) ) ;
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
type . V_372 ) ;
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
struct V_15 * V_373 ;
V_373 = F_188 ( V_12 , V_20 ) ;
if ( ! V_373 )
return V_51 ;
F_10 ( V_14 , V_21 , F_11 ( V_373 ) ) ;
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
F_13 ( V_374 ) ) ;
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
F_13 ( V_375 ) ) ;
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
V_139 , type . V_376 ) ;
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
F_14 ( V_8 , V_377 ) ;
if ( V_12 -> V_114 >= V_12 -> V_115 ) {
if ( V_12 -> V_96 . V_378 &&
V_12 -> V_175 == V_366 ) {
F_10 ( V_14 , V_379 ,
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
F_10 ( V_14 , V_380 , F_56 ( V_70 ) ) ;
F_10 ( V_14 , V_381 , F_56 ( V_70 ) ) ;
return V_50 ;
}
T_2 F_192 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
F_14 ( V_8 , V_382 ) ;
F_10 ( V_14 , V_270 , F_129 () ) ;
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
F_14 ( V_8 , V_383 ) ;
if ( V_214 <= V_12 -> V_216 ) {
V_213 = (struct V_212 * ) & V_12 -> V_44 . V_206 ;
V_31 = F_106 ( V_12 , V_213 , V_20 , 0 ) ;
if ( ! V_31 )
return V_51 ;
F_10 ( V_14 , V_362 ,
F_34 ( V_31 ) ) ;
F_10 ( V_14 , V_384 ,
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
F_14 ( V_8 , V_385 ) ;
if ( V_214 <= V_12 -> V_216 ) {
V_31 = F_195 ( V_12 , NULL ) ;
if ( ! V_31 )
return V_51 ;
F_10 ( V_14 , V_362 ,
F_34 ( V_31 ) ) ;
F_10 ( V_14 , V_386 ,
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
F_14 ( V_8 , V_387 ) ;
( (struct V_11 * ) V_12 ) -> V_388 ++ ;
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
case V_374 :
V_112 = F_189 ( V_12 , NULL ) ;
break;
case V_375 :
V_112 = F_119 ( V_12 , NULL ) ;
break;
default:
F_128 () ;
break;
}
if ( ! V_112 )
goto V_59;
if ( V_12 -> V_389 )
F_10 ( V_14 , V_380 ,
F_56 ( V_12 -> V_389 ) ) ;
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
struct V_1 * V_2 = V_12 -> V_299 ;
struct V_111 * V_70 = V_2 -> V_70 ;
F_14 ( V_8 , V_390 ) ;
if ( V_70 )
F_10 ( V_14 , V_380 ,
F_56 ( V_70 ) ) ;
F_10 ( V_14 , V_371 , F_34 ( V_2 ) ) ;
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
F_198 ( V_12 -> V_299 ) ;
F_10 ( V_14 , V_62 ,
F_34 ( V_12 -> V_299 ) ) ;
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
F_14 ( V_8 , V_391 ) ;
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
F_14 ( V_8 , V_392 ) ;
F_10 ( V_14 , V_25 ,
F_13 ( V_366 ) ) ;
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
return V_393 ;
}
T_2 F_202 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const T_3 type ,
void * V_13 ,
T_4 * V_14 )
{
return V_394 ;
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
static struct V_395 * F_132 ( struct V_1 * V_2 )
{
struct V_395 * V_396 ;
unsigned int V_37 ;
T_1 V_397 ;
T_1 V_398 ;
V_396 = (struct V_395 * ) V_2 -> V_55 -> V_56 ;
V_397 = F_2 ( V_396 -> V_399 ) ;
V_398 = F_2 ( V_396 -> V_398 ) ;
V_37 = sizeof( struct V_395 ) ;
V_37 += ( V_397 + V_398 ) * sizeof( T_15 ) ;
if ( V_37 > V_2 -> V_55 -> V_37 )
return NULL ;
F_25 ( V_2 -> V_55 , V_37 ) ;
return V_396 ;
}
static struct V_34 * F_22 ( struct V_8 * V_8 ,
const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
struct V_1 * V_2 ,
const void * V_347 ,
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
F_32 ( abort , V_125 , V_347 ) ;
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
T_1 V_400 ;
T_1 V_401 ;
T_15 V_42 ;
V_400 = F_2 ( V_2 -> V_41 -> V_207 ) ;
V_401 = F_2 ( V_2 -> V_41 -> V_296 ) ;
if ( V_12 ) {
switch ( V_2 -> V_5 -> type ) {
case V_349 :
{
V_64 * V_352 ;
V_352 = ( V_64 * ) V_2 -> V_5 ;
V_42 = F_104 ( V_352 -> V_53 . V_351 ) ;
break;
}
default:
V_42 = V_12 -> V_96 . V_350 . V_351 ;
break;
}
} else {
switch ( V_2 -> V_5 -> type ) {
case V_402 :
{
V_43 * V_152 ;
V_152 = ( V_43 * ) V_2 -> V_5 ;
V_42 = F_104 ( V_152 -> V_53 . V_351 ) ;
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
V_35 = F_206 ( & V_70 -> V_35 , V_70 , V_400 , V_401 ) ;
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
struct V_86 * V_403 ;
V_403 = V_2 -> V_52 . V_85 ;
V_35 -> V_42 = V_403 -> V_90 . V_180 ;
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
V_266 * V_265 ;
struct V_1 * V_187 ;
T_9 V_404 ;
T_21 V_405 ;
int V_406 ;
T_15 V_311 ;
struct V_407 * V_408 = (struct V_407 * ) & V_12 -> V_96 . V_314 ;
struct V_82 * V_45 = V_12 -> V_44 . V_45 ;
struct V_8 * V_8 = F_75 ( V_45 ) ;
T_22 V_409 ;
T_22 V_410 ;
V_219 V_411 = 0 ;
V_265 = V_2 -> V_52 . V_265 = ( V_266 * ) V_2 -> V_55 -> V_56 ;
F_25 ( V_2 -> V_55 , sizeof( V_266 ) ) ;
V_311 = F_104 ( V_265 -> V_311 ) ;
F_67 ( L_7 , V_139 , V_311 ) ;
if ( V_12 -> V_96 . V_412 && ! V_2 -> V_413 ) {
struct V_159 * V_160 = F_209 ( V_2 -> V_55 ) -> V_160 ;
V_2 -> V_413 = 1 ;
if ( V_160 -> V_414 ( F_210 ( V_2 -> V_55 ) ) ) {
F_10 ( V_14 , V_415 ,
F_122 ( V_311 ) ) ;
}
}
V_406 = F_155 ( & V_12 -> V_96 . V_314 , V_311 ) ;
if ( V_406 < 0 ) {
if ( V_2 -> V_12 )
V_2 -> V_12 -> V_416 . V_417 ++ ;
return V_256 ;
} else if ( V_406 > 0 ) {
F_10 ( V_14 , V_418 , F_122 ( V_311 ) ) ;
return V_260 ;
}
V_404 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_404 -= sizeof( V_255 ) ;
V_405 = V_419 ;
if ( ( V_404 >= V_12 -> V_181 ) && ( ! V_12 -> V_420 . V_421 ) ) {
F_10 ( V_14 , V_422 , F_16 () ) ;
}
if ( ( ! V_2 -> V_423 ) && ( ! V_12 -> V_181 || V_12 -> V_424 ||
( V_404 > V_12 -> V_181 + V_12 -> V_425 ) ) ) {
if ( F_211 ( V_408 ) &&
( F_212 ( V_408 ) + 1 ) == V_311 ) {
F_67 ( L_22 , V_139 , V_311 ) ;
V_405 = V_426 ;
} else {
F_67 ( L_23 ,
V_139 , V_311 , V_404 , V_12 -> V_181 ) ;
return V_261 ;
}
}
if ( * V_45 -> V_427 -> V_428 ) {
if ( F_211 ( V_408 ) &&
( F_212 ( V_408 ) + 1 ) == V_311 ) {
F_67 ( L_24 ,
V_139 , V_311 ) ;
V_405 = V_426 ;
}
}
if ( F_3 ( 0 == V_404 ) ) {
V_187 = F_213 ( V_12 , V_2 , V_311 ) ;
if ( V_187 ) {
F_10 ( V_14 , V_62 ,
F_34 ( V_187 ) ) ;
}
F_10 ( V_14 , V_168 , F_16 () ) ;
F_10 ( V_14 , V_116 ,
F_58 ( V_304 ) ) ;
F_10 ( V_14 , V_118 ,
F_59 ( V_429 ) ) ;
F_14 ( V_8 , V_68 ) ;
F_15 ( V_8 , V_28 ) ;
return V_263 ;
}
V_2 -> V_423 = 1 ;
if ( V_2 -> V_5 -> V_267 & V_430 ) {
F_14 ( V_8 , V_431 ) ;
if ( V_2 -> V_12 )
V_2 -> V_12 -> V_416 . V_432 ++ ;
} else {
F_14 ( V_8 , V_433 ) ;
if ( V_2 -> V_12 )
V_2 -> V_12 -> V_416 . V_434 ++ ;
V_411 = 1 ;
}
V_410 = F_2 ( V_265 -> V_315 ) ;
if ( V_410 >= V_12 -> V_90 . V_101 ) {
F_10 ( V_14 , V_435 , F_122 ( V_311 ) ) ;
V_187 = F_88 ( V_12 , V_2 , V_436 ,
& V_265 -> V_315 ,
sizeof( V_265 -> V_315 ) ,
sizeof( T_22 ) ) ;
if ( V_187 )
F_10 ( V_14 , V_62 ,
F_34 ( V_187 ) ) ;
return V_257 ;
}
V_409 = F_2 ( V_265 -> V_409 ) ;
if ( V_411 && F_214 ( V_409 , F_215 ( & V_12 -> V_437 -> V_438 , V_410 ) ) ) {
return V_264 ;
}
F_10 ( V_14 , V_405 , F_34 ( V_2 ) ) ;
return V_98 ;
}
