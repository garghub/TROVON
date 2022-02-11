static inline int
F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( F_3 ( V_4 < V_3 ) )
return 0 ;
return 1 ;
}
T_2 F_4 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
struct V_14 * V_15 ;
if ( ! F_5 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! V_2 -> V_16 )
return F_7 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_17 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_15 = F_9 ( V_11 , 0 , V_18 ,
0 , 0 , 0 , NULL , V_19 ) ;
if ( V_15 )
F_10 ( V_13 , V_20 ,
F_11 ( V_15 ) ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_22 ) ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_23 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_25 ) ) ;
F_14 ( V_7 , V_26 ) ;
F_15 ( V_7 , V_27 ) ;
F_10 ( V_13 , V_28 , F_16 () ) ;
return V_29 ;
}
T_2 F_17 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
struct V_1 * V_30 ;
struct V_10 * V_31 ;
struct V_1 * V_32 ;
struct V_33 * V_34 ;
T_5 * V_35 ;
int V_36 ;
if ( ! V_2 -> V_16 )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( V_9 == F_18 ( V_7 -> V_37 . V_38 ) -> V_9 ) {
F_14 ( V_7 , V_39 ) ;
return F_19 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( V_2 -> V_40 -> V_41 != 0 )
return F_19 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_42 ) ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( F_20 ( V_9 -> V_43 . V_44 , V_45 ) )
return F_19 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
V_32 = NULL ;
if ( ! F_21 ( V_7 , V_9 , V_11 , V_2 -> V_5 -> type ,
( V_42 * ) V_2 -> V_5 , V_2 ,
& V_32 ) ) {
if ( V_32 ) {
V_34 = F_22 ( V_7 , V_9 , V_11 , V_12 ,
( V_46 * ) ( V_32 -> V_5 ) +
sizeof( V_17 ) ,
F_2 ( V_32 -> V_5 -> V_6 ) -
sizeof( V_17 ) ) ;
F_23 ( V_32 ) ;
if ( V_34 ) {
F_10 ( V_13 , V_47 ,
F_24 ( V_34 ) ) ;
F_14 ( V_7 , V_48 ) ;
return V_49 ;
} else {
return V_50 ;
}
} else {
return F_19 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
}
}
V_2 -> V_51 . V_52 = ( V_53 * ) V_2 -> V_54 -> V_55 ;
V_2 -> V_56 . V_57 = F_25 ( V_2 -> V_54 , sizeof( V_53 ) ) ;
V_31 = F_26 ( V_9 , V_2 , V_19 ) ;
if ( ! V_31 )
goto V_58;
if ( F_27 ( V_31 ,
F_28 ( F_29 ( V_2 ) ) ,
V_19 ) < 0 )
goto V_59;
if ( ! F_30 ( V_31 , V_2 , F_29 ( V_2 ) ,
( V_42 * ) V_2 -> V_5 ,
V_19 ) )
goto V_59;
V_36 = 0 ;
if ( V_32 )
V_36 = F_2 ( V_32 -> V_5 -> V_6 ) -
sizeof( V_17 ) ;
V_30 = F_31 ( V_31 , V_2 , V_19 , V_36 ) ;
if ( ! V_30 )
goto V_59;
if ( V_32 ) {
V_35 = ( T_5 * )
( ( V_46 * ) ( V_32 -> V_5 ) +
sizeof( V_17 ) ) ;
F_32 ( V_30 , V_36 , V_35 ) ;
F_23 ( V_32 ) ;
}
F_10 ( V_13 , V_60 , F_33 ( V_31 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_30 ) ) ;
F_10 ( V_13 , V_28 , F_16 () ) ;
return V_29 ;
V_59:
F_35 ( V_31 ) ;
V_58:
if ( V_32 )
F_23 ( V_32 ) ;
return V_50 ;
}
T_2 F_36 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
V_42 * V_62 ;
struct V_1 * V_32 ;
struct V_33 * V_34 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! V_2 -> V_16 )
return F_7 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_63 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_2 -> V_51 . V_52 = ( V_53 * ) V_2 -> V_54 -> V_55 ;
V_32 = NULL ;
if ( ! F_21 ( V_7 , V_9 , V_11 , V_2 -> V_5 -> type ,
( V_42 * ) V_2 -> V_5 , V_2 ,
& V_32 ) ) {
T_6 error = V_64 ;
if ( V_32 ) {
V_34 = F_22 ( V_7 , V_9 , V_11 , V_12 ,
( V_46 * ) ( V_32 -> V_5 ) +
sizeof( V_17 ) ,
F_2 ( V_32 -> V_5 -> V_6 ) -
sizeof( V_17 ) ) ;
F_23 ( V_32 ) ;
if ( V_34 ) {
F_10 ( V_13 , V_47 ,
F_24 ( V_34 ) ) ;
F_14 ( V_7 , V_48 ) ;
error = V_65 ;
}
}
if ( F_38 ( V_66 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
F_14 ( V_7 , V_67 ) ;
return F_39 ( V_7 , V_13 , error , V_68 ,
V_11 , V_2 -> V_69 ) ;
}
V_2 -> V_56 . V_57 = F_25 ( V_2 -> V_54 , sizeof( V_53 ) ) ;
V_62 = ( V_42 * ) V_2 -> V_5 ;
F_10 ( V_13 , V_70 ,
F_40 ( V_62 ) ) ;
F_10 ( V_13 , V_71 , F_16 () ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_72 ) ) ;
F_10 ( V_13 , V_73 ,
F_12 ( V_74 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_75 ) ) ;
F_10 ( V_13 , V_76 , F_16 () ) ;
F_10 ( V_13 , V_77 ,
F_34 ( V_32 ) ) ;
return V_49 ;
}
T_2 F_41 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type , void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
struct V_10 * V_31 ;
V_42 * V_78 ;
struct V_1 * V_30 ;
struct V_14 * V_15 , * V_79 = NULL ;
int error = 0 ;
struct V_1 * V_80 ;
struct V_81 * V_44 ;
if ( V_9 == F_18 ( V_7 -> V_37 . V_38 ) -> V_9 ) {
F_14 ( V_7 , V_39 ) ;
return F_19 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! F_1 ( V_2 , sizeof( V_17 ) ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
V_44 = V_9 -> V_43 . V_44 ;
if ( ! F_20 ( V_44 , V_82 ) ||
( F_42 ( V_44 , V_83 ) && F_43 ( V_44 ) ) )
return F_19 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
V_2 -> V_51 . V_84 =
(struct V_85 * ) V_2 -> V_54 -> V_55 ;
if ( ! F_44 ( V_2 -> V_54 , F_2 ( V_2 -> V_5 -> V_6 ) -
sizeof( V_17 ) ) )
goto V_58;
V_31 = F_45 ( V_9 , V_11 , V_2 , V_19 , & error ,
& V_80 ) ;
if ( ! V_31 ) {
switch ( error ) {
case - V_86 :
goto V_58;
case - V_87 :
F_46 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
V_80 ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
case - V_88 :
default:
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
}
V_78 = & V_2 -> V_51 . V_84 -> V_89 . V_78 [ 0 ] ;
if ( ! F_30 ( V_31 , V_2 ,
& V_2 -> V_51 . V_84 -> V_89 . V_90 ,
V_78 , V_19 ) )
goto V_59;
error = F_47 ( V_31 , V_19 ) ;
if ( error )
goto V_59;
if ( V_2 -> V_91 ) {
struct V_1 V_92 ;
T_7 V_93 ;
if ( ! V_7 -> V_37 . V_94 || ! V_31 -> V_95 . V_96 ) {
F_35 ( V_31 ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
V_92 . V_54 = V_2 -> V_91 ;
V_92 . V_11 = V_2 -> V_11 ;
V_92 . V_40 = V_2 -> V_40 ;
V_92 . V_5 = ( V_17 * ) F_48 ( V_2 -> V_91 ,
sizeof( V_17 ) ) ;
F_25 ( V_2 -> V_91 , sizeof( V_17 ) ) ;
V_92 . V_69 = V_2 -> V_69 ;
V_93 = F_49 ( V_7 , V_9 , V_31 , type , & V_92 ) ;
if ( V_93 != V_97 ) {
F_35 ( V_31 ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
}
V_30 = F_50 ( V_31 , V_2 ) ;
if ( ! V_30 )
goto V_59;
V_15 = F_9 ( V_31 , 0 , V_98 , 0 ,
V_31 -> V_89 . V_99 ,
V_31 -> V_89 . V_100 ,
NULL , V_19 ) ;
if ( ! V_15 )
goto V_101;
if ( V_31 -> V_95 . V_102 ) {
V_79 = F_51 ( V_31 ,
V_19 ) ;
if ( ! V_79 )
goto V_103;
}
F_10 ( V_13 , V_60 , F_33 ( V_31 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_104 ) ) ;
F_14 ( V_7 , V_27 ) ;
F_14 ( V_7 , V_105 ) ;
F_10 ( V_13 , V_106 , F_16 () ) ;
if ( V_31 -> V_107 [ V_108 ] )
F_10 ( V_13 , V_73 ,
F_12 ( V_108 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_30 ) ) ;
F_10 ( V_13 , V_20 , F_11 ( V_15 ) ) ;
if ( V_79 )
F_10 ( V_13 , V_20 ,
F_11 ( V_79 ) ) ;
return V_49 ;
V_103:
F_52 ( V_15 ) ;
V_101:
F_23 ( V_30 ) ;
V_59:
F_35 ( V_31 ) ;
V_58:
return V_50 ;
}
T_2 F_53 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type , void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
struct V_14 * V_15 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_17 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
F_10 ( V_13 , V_71 , F_16 () ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_74 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_104 ) ) ;
F_14 ( V_7 , V_27 ) ;
F_14 ( V_7 , V_109 ) ;
F_10 ( V_13 , V_106 , F_16 () ) ;
if ( V_11 -> V_107 [ V_108 ] )
F_10 ( V_13 , V_73 ,
F_12 ( V_108 ) ) ;
V_15 = F_9 ( V_11 , 0 , V_98 ,
0 , V_11 -> V_89 . V_99 ,
V_11 -> V_89 . V_100 ,
NULL , V_19 ) ;
if ( ! V_15 )
goto V_58;
F_10 ( V_13 , V_20 , F_11 ( V_15 ) ) ;
if ( V_11 -> V_95 . V_102 ) {
V_15 = F_51 ( V_11 , V_19 ) ;
if ( ! V_15 )
goto V_58;
F_10 ( V_13 , V_20 ,
F_11 ( V_15 ) ) ;
}
return V_49 ;
V_58:
return V_50 ;
}
static T_2 F_54 ( const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_110 * V_69 = (struct V_110 * ) V_12 ;
struct V_1 * V_111 ;
V_111 = F_55 ( V_11 , V_69 ) ;
if ( ! V_111 )
return V_50 ;
F_10 ( V_13 , V_112 ,
F_56 ( V_69 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_111 ) ) ;
return V_49 ;
}
T_2 F_57 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_110 * V_69 = (struct V_110 * ) V_12 ;
if ( V_11 -> V_113 >= V_11 -> V_114 ) {
F_10 ( V_13 , V_115 ,
F_58 ( V_116 ) ) ;
F_10 ( V_13 , V_117 ,
F_59 ( V_118 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_29 ;
}
if ( V_69 -> V_119 & V_120 ) {
if ( V_50 ==
F_54 ( V_9 , V_11 , type , V_12 ,
V_13 ) )
return V_50 ;
F_10 ( V_13 , V_121 ,
F_56 ( V_69 ) ) ;
}
F_10 ( V_13 , V_122 ,
F_56 ( V_69 ) ) ;
F_10 ( V_13 , V_123 ,
F_56 ( V_69 ) ) ;
return V_49 ;
}
T_2 F_60 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
T_8 * V_56 ;
struct V_1 * V_2 = V_12 ;
struct V_1 * V_111 ;
T_9 V_124 = 0 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_125 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_2 -> V_51 . V_126 = ( V_127 * ) V_2 -> V_54 -> V_55 ;
V_56 = ( T_8 * ) V_2 -> V_51 . V_126 ;
V_124 = F_2 ( V_2 -> V_5 -> V_6 ) - sizeof( V_17 ) ;
if ( F_2 ( V_56 -> V_6 ) > V_124 )
return F_61 ( V_7 , V_9 , V_11 , type , V_12 ,
V_56 , V_13 ) ;
if ( ! F_44 ( V_2 -> V_54 , V_124 ) )
goto V_58;
V_111 = F_62 ( V_11 , V_2 , V_56 , V_124 ) ;
if ( ! V_111 )
goto V_58;
F_10 ( V_13 , V_61 , F_34 ( V_111 ) ) ;
return V_49 ;
V_58:
return V_50 ;
}
T_2 F_63 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
union V_128 V_129 ;
struct V_110 * V_130 ;
T_10 * V_131 ;
unsigned long V_132 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_17 ) +
sizeof( T_10 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_131 = ( T_10 * ) V_2 -> V_54 -> V_55 ;
if ( F_2 ( V_131 -> V_56 . V_6 ) !=
sizeof( T_10 ) ) {
return V_133 ;
}
V_129 = V_131 -> V_134 ;
V_130 = F_64 ( V_11 , & V_129 ) ;
if ( F_3 ( ! V_130 ) ) {
if ( V_129 . V_135 . V_136 == V_137 ) {
F_65 ( L_1 ,
V_138 ,
V_11 ,
& V_129 . V_139 . V_140 ) ;
} else {
F_65 ( L_2 ,
V_138 ,
V_11 ,
& V_129 . V_141 . V_142 . V_143 ) ;
}
return V_133 ;
}
if ( V_131 -> V_144 != V_130 -> V_144 )
return V_133 ;
V_132 = V_130 -> V_145 + V_130 -> V_146 ;
if ( F_66 ( V_131 -> V_147 , V_148 ) ||
F_66 ( V_148 , V_131 -> V_147 + V_132 ) ) {
F_67 ( L_3
L_4 , V_138 , V_130 ) ;
return V_133 ;
}
F_10 ( V_13 , V_149 , F_56 ( V_130 ) ) ;
return V_49 ;
}
static int F_68 ( struct V_7 * V_7 , union V_128 * V_150 ,
struct V_1 * V_151 ,
T_4 * V_13 )
{
int V_36 ;
struct V_33 * V_152 ;
union V_153 * V_154 ;
struct V_155 * V_156 ;
struct V_8 * V_9 ;
char V_157 [ sizeof( struct V_155 ) + sizeof( union V_153 ) ] ;
struct V_158 * V_159 = F_69 ( V_150 -> V_141 . V_160 ) ;
V_156 = (struct V_155 * ) V_157 ;
V_154 = (union V_153 * ) V_156 -> V_161 ;
V_36 = V_159 -> V_162 ( V_150 , V_154 ) ;
V_36 += sizeof( V_163 ) ;
V_156 -> V_164 = V_165 ;
V_156 -> V_6 = F_70 ( V_36 ) ;
V_9 = F_18 ( V_7 -> V_37 . V_38 ) -> V_9 ;
V_152 = F_22 ( V_7 , V_9 , NULL , V_151 , V_156 , V_36 ) ;
if ( ! V_152 )
goto V_166;
F_10 ( V_13 , V_47 , F_24 ( V_152 ) ) ;
F_14 ( V_7 , V_48 ) ;
F_10 ( V_13 , V_167 , F_16 () ) ;
V_166:
return 0 ;
}
static bool F_71 ( const struct V_168 * V_169 ,
union V_128 * V_170 )
{
struct V_110 * V_171 ;
F_72 (addr, list, transports) {
if ( F_73 ( V_170 , & V_171 -> V_170 ) )
return true ;
}
return false ;
}
static int F_74 ( const struct V_10 * V_31 ,
const struct V_10 * V_11 ,
struct V_1 * V_151 ,
T_4 * V_13 )
{
struct V_7 * V_7 = F_75 ( V_31 -> V_43 . V_44 ) ;
struct V_110 * V_172 ;
int V_93 = 1 ;
F_72 (new_addr, &new_asoc->peer.transport_addr_list,
transports) {
if ( ! F_71 ( & V_11 -> V_95 . V_173 ,
& V_172 -> V_170 ) ) {
F_68 ( V_7 , & V_172 -> V_170 , V_151 ,
V_13 ) ;
V_93 = 0 ;
break;
}
}
return V_93 ;
}
static void F_76 ( struct V_10 * V_31 ,
const struct V_10 * V_11 )
{
switch ( V_11 -> V_174 ) {
case V_175 :
V_31 -> V_89 . V_176 = V_11 -> V_89 . V_176 ;
V_31 -> V_89 . V_177 = V_11 -> V_89 . V_176 ;
V_31 -> V_89 . V_178 = 0 ;
break;
case V_75 :
V_31 -> V_89 . V_176 = V_11 -> V_89 . V_176 ;
V_31 -> V_89 . V_177 = V_11 -> V_89 . V_176 ;
V_31 -> V_89 . V_178 = V_11 -> V_89 . V_179 ;
break;
default:
V_31 -> V_89 . V_177 = V_11 -> V_89 . V_176 ;
V_31 -> V_89 . V_178 = V_11 -> V_89 . V_179 ;
break;
}
V_31 -> V_180 = V_11 -> V_180 ;
V_31 -> V_89 . V_99 = V_11 -> V_89 . V_99 ;
V_31 -> V_89 . V_100 = V_11 -> V_89 . V_100 ;
V_31 -> V_89 . V_181 = V_11 -> V_89 . V_181 ;
}
static char F_77 ( struct V_10 * V_31 ,
const struct V_10 * V_11 )
{
if ( ( V_11 -> V_89 . V_176 != V_31 -> V_89 . V_176 ) &&
( V_11 -> V_89 . V_179 != V_31 -> V_89 . V_179 ) &&
( V_11 -> V_89 . V_176 == V_31 -> V_89 . V_177 ) &&
( V_11 -> V_89 . V_179 == V_31 -> V_89 . V_178 ) )
return 'A' ;
if ( ( V_11 -> V_89 . V_176 == V_31 -> V_89 . V_176 ) &&
( ( V_11 -> V_89 . V_179 != V_31 -> V_89 . V_179 ) ||
( 0 == V_11 -> V_89 . V_179 ) ) ) {
return 'B' ;
}
if ( ( V_11 -> V_89 . V_176 == V_31 -> V_89 . V_176 ) &&
( V_11 -> V_89 . V_179 == V_31 -> V_89 . V_179 ) )
return 'D' ;
if ( ( V_11 -> V_89 . V_176 != V_31 -> V_89 . V_176 ) &&
( V_11 -> V_89 . V_179 == V_31 -> V_89 . V_179 ) &&
( 0 == V_31 -> V_89 . V_177 ) &&
( 0 == V_31 -> V_89 . V_178 ) )
return 'C' ;
return 'E' ;
}
static T_2 F_78 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 , T_4 * V_13 )
{
T_2 V_182 ;
struct V_1 * V_2 = V_12 ;
struct V_1 * V_30 ;
struct V_10 * V_31 ;
struct V_1 * V_32 ;
struct V_33 * V_34 ;
T_5 * V_35 ;
int V_36 ;
if ( ! V_2 -> V_16 )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( V_2 -> V_40 -> V_41 != 0 )
return F_19 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_42 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_2 -> V_51 . V_52 = ( V_53 * ) V_2 -> V_54 -> V_55 ;
V_2 -> V_56 . V_57 = F_25 ( V_2 -> V_54 , sizeof( V_53 ) ) ;
V_32 = NULL ;
if ( ! F_21 ( V_7 , V_9 , V_11 , V_2 -> V_5 -> type ,
( V_42 * ) V_2 -> V_5 , V_2 ,
& V_32 ) ) {
if ( V_32 ) {
V_34 = F_22 ( V_7 , V_9 , V_11 , V_12 ,
( V_46 * ) ( V_32 -> V_5 ) +
sizeof( V_17 ) ,
F_2 ( V_32 -> V_5 -> V_6 ) -
sizeof( V_17 ) ) ;
if ( V_34 ) {
F_10 ( V_13 , V_47 ,
F_24 ( V_34 ) ) ;
F_14 ( V_7 , V_48 ) ;
V_182 = V_49 ;
} else {
V_182 = V_50 ;
}
goto V_183;
} else {
return F_19 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
}
}
V_31 = F_26 ( V_9 , V_2 , V_19 ) ;
if ( ! V_31 )
goto V_58;
if ( F_27 ( V_31 ,
F_28 ( F_29 ( V_2 ) ) , V_19 ) < 0 )
goto V_58;
if ( ! F_30 ( V_31 , V_2 , F_29 ( V_2 ) ,
( V_42 * ) V_2 -> V_5 ,
V_19 ) )
goto V_58;
if ( ! F_79 ( V_11 , V_184 ) ) {
if ( ! F_74 ( V_31 , V_11 , V_2 ,
V_13 ) ) {
V_182 = V_49 ;
goto V_185;
}
}
F_76 ( V_31 , V_11 ) ;
V_36 = 0 ;
if ( V_32 ) {
V_36 = F_2 ( V_32 -> V_5 -> V_6 ) -
sizeof( V_17 ) ;
}
V_30 = F_31 ( V_31 , V_2 , V_19 , V_36 ) ;
if ( ! V_30 )
goto V_58;
if ( V_32 ) {
V_35 = ( T_5 * )
( ( V_46 * ) ( V_32 -> V_5 ) +
sizeof( V_17 ) ) ;
F_32 ( V_30 , V_36 , V_35 ) ;
}
F_10 ( V_13 , V_60 , F_33 ( V_31 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_30 ) ) ;
F_10 ( V_13 , V_28 , F_16 () ) ;
V_182 = V_49 ;
return V_182 ;
V_58:
V_182 = V_50 ;
V_185:
if ( V_31 )
F_35 ( V_31 ) ;
V_183:
if ( V_32 )
F_23 ( V_32 ) ;
return V_182 ;
}
T_2 F_80 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
return F_78 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_81 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
return F_78 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_82 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 , T_4 * V_13 )
{
if ( V_9 == F_18 ( V_7 -> V_37 . V_38 ) -> V_9 )
return F_83 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
else
return F_84 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
static T_2 F_85 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
struct V_1 * V_2 ,
T_4 * V_13 ,
struct V_10 * V_31 )
{
V_42 * V_78 ;
struct V_14 * V_15 ;
struct V_1 * V_30 ;
struct V_1 * V_186 ;
T_2 V_187 ;
V_78 = & V_2 -> V_51 . V_84 -> V_89 . V_78 [ 0 ] ;
if ( ! F_30 ( V_31 , V_2 , F_29 ( V_2 ) , V_78 ,
V_19 ) )
goto V_58;
if ( ! F_74 ( V_31 , V_11 , V_2 , V_13 ) ) {
return V_49 ;
}
if ( F_79 ( V_11 , V_188 ) ) {
V_187 = F_86 ( V_7 , V_9 , V_11 ,
F_87 ( V_2 -> V_5 -> type ) ,
V_2 , V_13 ) ;
if ( V_50 == V_187 )
goto V_58;
V_186 = F_88 ( V_11 , V_2 ,
V_189 ,
NULL , 0 , 0 ) ;
if ( V_186 )
F_10 ( V_13 , V_61 ,
F_34 ( V_186 ) ) ;
return V_49 ;
}
F_10 ( V_13 , V_190 , F_16 () ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_191 ) ) ;
F_10 ( V_13 , V_192 , F_16 () ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_193 ) ) ;
F_10 ( V_13 , V_194 , F_16 () ) ;
V_30 = F_50 ( V_31 , V_2 ) ;
if ( ! V_30 )
goto V_58;
V_15 = F_9 ( V_11 , 0 , V_195 , 0 ,
V_31 -> V_89 . V_99 ,
V_31 -> V_89 . V_100 ,
NULL , V_19 ) ;
if ( ! V_15 )
goto V_101;
F_10 ( V_13 , V_196 , F_33 ( V_31 ) ) ;
F_10 ( V_13 , V_20 , F_11 ( V_15 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_104 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_30 ) ) ;
return V_49 ;
V_101:
F_23 ( V_30 ) ;
V_58:
return V_50 ;
}
static T_2 F_89 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
struct V_1 * V_2 ,
T_4 * V_13 ,
struct V_10 * V_31 )
{
V_42 * V_78 ;
struct V_1 * V_30 ;
V_78 = & V_2 -> V_51 . V_84 -> V_89 . V_78 [ 0 ] ;
if ( ! F_30 ( V_31 , V_2 , F_29 ( V_2 ) , V_78 ,
V_19 ) )
goto V_58;
F_10 ( V_13 , V_196 , F_33 ( V_31 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_104 ) ) ;
F_14 ( V_7 , V_27 ) ;
F_10 ( V_13 , V_106 , F_16 () ) ;
V_30 = F_50 ( V_31 , V_2 ) ;
if ( ! V_30 )
goto V_58;
F_10 ( V_13 , V_61 , F_34 ( V_30 ) ) ;
F_10 ( V_13 , V_197 , F_90 ( V_98 ) ) ;
if ( V_11 -> V_95 . V_102 )
F_10 ( V_13 , V_198 , F_16 () ) ;
return V_49 ;
V_58:
return V_50 ;
}
static T_2 F_91 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
struct V_1 * V_2 ,
T_4 * V_13 ,
struct V_10 * V_31 )
{
return V_133 ;
}
static T_2 F_92 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
struct V_1 * V_2 ,
T_4 * V_13 ,
struct V_10 * V_31 )
{
struct V_14 * V_15 = NULL , * V_79 = NULL ;
struct V_1 * V_30 ;
if ( V_11 -> V_174 < V_104 ) {
F_10 ( V_13 , V_21 ,
F_12 ( V_74 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_104 ) ) ;
F_14 ( V_7 , V_27 ) ;
F_10 ( V_13 , V_106 ,
F_16 () ) ;
V_15 = F_9 ( V_11 , 0 ,
V_98 , 0 ,
V_11 -> V_89 . V_99 ,
V_11 -> V_89 . V_100 ,
NULL , V_19 ) ;
if ( ! V_15 )
goto V_58;
if ( V_11 -> V_95 . V_102 ) {
V_79 = F_51 ( V_11 ,
V_19 ) ;
if ( ! V_79 )
goto V_58;
}
}
V_30 = F_50 ( V_31 , V_2 ) ;
if ( ! V_30 )
goto V_58;
F_10 ( V_13 , V_61 , F_34 ( V_30 ) ) ;
if ( V_15 )
F_10 ( V_13 , V_20 ,
F_11 ( V_15 ) ) ;
if ( V_79 )
F_10 ( V_13 , V_20 ,
F_11 ( V_79 ) ) ;
return V_49 ;
V_58:
if ( V_79 )
F_52 ( V_79 ) ;
if ( V_15 )
F_52 ( V_15 ) ;
return V_50 ;
}
T_2 F_93 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
T_2 V_182 ;
struct V_1 * V_2 = V_12 ;
struct V_10 * V_31 ;
int error = 0 ;
char V_199 ;
struct V_1 * V_80 ;
if ( ! F_1 ( V_2 , sizeof( V_17 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_2 -> V_51 . V_84 = (struct V_85 * ) V_2 -> V_54 -> V_55 ;
if ( ! F_44 ( V_2 -> V_54 , F_2 ( V_2 -> V_5 -> V_6 ) -
sizeof( V_17 ) ) )
goto V_58;
V_31 = F_45 ( V_9 , V_11 , V_2 , V_19 , & error ,
& V_80 ) ;
if ( ! V_31 ) {
switch ( error ) {
case - V_86 :
goto V_58;
case - V_87 :
F_46 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
V_80 ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
case - V_88 :
default:
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
}
V_199 = F_77 ( V_31 , V_11 ) ;
switch ( V_199 ) {
case 'A' :
V_182 = F_85 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
V_31 ) ;
break;
case 'B' :
V_182 = F_89 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
V_31 ) ;
break;
case 'C' :
V_182 = F_91 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
V_31 ) ;
break;
case 'D' :
V_182 = F_92 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
V_31 ) ;
break;
default:
V_182 = F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
break;
}
F_10 ( V_13 , V_200 , F_33 ( V_31 ) ) ;
F_10 ( V_13 , V_28 , F_16 () ) ;
F_10 ( V_13 , V_200 ,
F_33 ( (struct V_10 * ) V_11 ) ) ;
return V_182 ;
V_58:
return V_50 ;
}
T_2 F_94 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
if ( ! F_5 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_201 ) ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( V_202 ==
F_95 ( & V_11 -> V_43 . V_203 , & V_2 -> V_204 ) )
return F_84 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
return F_96 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_97 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
if ( ! F_5 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_201 ) ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( V_202 ==
F_95 ( & V_11 -> V_43 . V_203 , & V_2 -> V_204 ) )
return F_84 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_22 ) ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_23 ) ) ;
return F_96 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_98 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
return F_97 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_99 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
V_163 * V_186 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_205 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
F_100 (err, chunk->chunk_hdr) {
if ( V_206 == V_186 -> V_164 )
return F_101 ( V_7 , V_9 , V_11 , type ,
V_12 , V_13 ) ;
}
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
static T_2 F_101 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
T_11 V_207 ;
T_12 V_208 ;
V_163 * V_186 ;
struct V_1 * V_111 ;
struct V_209 * V_210 ;
int V_211 = V_11 -> V_212 + 1 ;
if ( V_211 > V_11 -> V_213 ) {
F_10 ( V_13 , V_115 ,
F_58 ( V_116 ) ) ;
F_10 ( V_13 , V_214 ,
F_59 ( V_206 ) ) ;
return V_29 ;
}
V_186 = ( V_163 * ) ( V_2 -> V_54 -> V_55 ) ;
V_207 = F_102 ( * ( V_215 * ) ( ( V_216 * ) V_186 + sizeof( V_163 ) ) ) ;
V_207 = ( V_207 * 2 ) / 1000 ;
V_208 . V_56 . type = V_217 ;
V_208 . V_56 . V_6 = F_70 ( sizeof( V_208 ) ) ;
V_208 . V_218 = F_103 ( V_207 ) ;
V_210 = (struct V_209 * ) & V_11 -> V_43 . V_203 ;
V_111 = F_104 ( V_11 , V_210 , V_19 , sizeof( V_208 ) ) ;
if ( ! V_111 )
goto V_58;
F_32 ( V_111 , sizeof( V_208 ) , & V_208 ) ;
F_10 ( V_13 , V_219 , F_16 () ) ;
F_10 ( V_13 , V_190 , F_16 () ) ;
F_10 ( V_13 , V_220 , F_16 () ) ;
F_10 ( V_13 , V_221 , F_16 () ) ;
F_10 ( V_13 , V_222 ,
F_56 ( V_11 -> V_95 . V_223 ) ) ;
F_10 ( V_13 , V_224 , F_16 () ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_74 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_175 ) ) ;
F_10 ( V_13 , V_73 ,
F_12 ( V_72 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_111 ) ) ;
return V_49 ;
V_58:
return V_50 ;
}
T_2 F_105 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
if ( ! F_5 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_201 ) ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( V_202 ==
F_95 ( & V_11 -> V_43 . V_203 , & V_2 -> V_204 ) )
return F_84 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
return F_96 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
static T_2 F_96 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
unsigned int V_36 ;
T_13 error = V_118 ;
V_36 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_36 >= sizeof( struct V_225 ) + sizeof( struct V_155 ) ) {
V_163 * V_186 ;
F_100 ( V_186 , V_2 -> V_5 ) ;
if ( ( void * ) V_186 != ( void * ) V_2 -> V_226 )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
error = ( ( V_163 * ) V_2 -> V_54 -> V_55 ) -> V_164 ;
}
F_10 ( V_13 , V_115 , F_58 ( V_227 ) ) ;
F_10 ( V_13 , V_117 , F_59 ( error ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_228 ;
}
T_2 F_106 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
unsigned int V_36 ;
T_13 error = V_118 ;
if ( ! F_5 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_201 ) ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
V_36 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_36 >= sizeof( struct V_225 ) + sizeof( struct V_155 ) )
error = ( ( V_163 * ) V_2 -> V_54 -> V_55 ) -> V_164 ;
return F_39 ( V_7 , V_13 , error , V_68 , V_11 ,
V_2 -> V_69 ) ;
}
T_2 F_107 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
return F_39 ( V_7 , V_13 , V_118 ,
V_229 , V_11 ,
(struct V_110 * ) V_12 ) ;
}
T_2 F_108 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
return F_106 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
static T_2 F_39 ( struct V_7 * V_7 ,
T_4 * V_13 ,
T_13 error , int V_230 ,
const struct V_10 * V_11 ,
struct V_110 * V_69 )
{
F_67 ( L_5 , V_138 ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_25 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_72 ) ) ;
F_10 ( V_13 , V_115 , F_58 ( V_230 ) ) ;
F_10 ( V_13 , V_214 ,
F_59 ( error ) ) ;
return V_228 ;
}
T_2 F_109 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
T_14 * V_231 ;
T_2 V_187 ;
struct V_14 * V_15 ;
T_15 V_232 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 ,
sizeof( struct V_233 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_231 = ( T_14 * ) V_2 -> V_54 -> V_55 ;
F_25 ( V_2 -> V_54 , sizeof( T_14 ) ) ;
V_2 -> V_51 . V_234 = V_231 ;
V_232 = F_102 ( V_231 -> V_235 ) ;
if ( F_110 ( V_232 , V_11 -> V_236 ) ) {
F_67 ( L_6 , V_138 , V_232 ,
V_11 -> V_236 ) ;
return V_133 ;
}
if ( ! F_110 ( V_232 , V_11 -> V_237 ) )
return F_111 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
V_15 = F_112 ( V_11 , 0 , V_19 ) ;
if ( ! V_15 ) {
V_187 = V_50 ;
goto V_166;
}
F_10 ( V_13 , V_20 , F_11 ( V_15 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_238 ) ) ;
V_187 = V_49 ;
if ( F_113 ( & V_11 -> V_239 ) ) {
V_187 = F_114 ( V_7 , V_9 , V_11 , type ,
V_12 , V_13 ) ;
}
if ( V_50 == V_187 )
goto V_166;
F_10 ( V_13 , V_240 ,
F_115 ( V_2 -> V_51 . V_234 -> V_235 ) ) ;
V_166:
return V_187 ;
}
T_2 F_116 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
T_14 * V_231 ;
T_15 V_232 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 ,
sizeof( struct V_233 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_231 = ( T_14 * ) V_2 -> V_54 -> V_55 ;
V_232 = F_102 ( V_231 -> V_235 ) ;
if ( F_110 ( V_232 , V_11 -> V_236 ) ) {
F_67 ( L_6 , V_138 , V_232 ,
V_11 -> V_236 ) ;
return V_133 ;
}
if ( ! F_110 ( V_232 , V_11 -> V_237 ) )
return F_111 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
F_10 ( V_13 , V_240 ,
F_115 ( V_231 -> V_235 ) ) ;
return V_49 ;
}
T_2 F_86 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
struct V_1 * V_111 ;
if ( ! F_1 ( V_2 , sizeof( V_17 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_111 = F_117 ( V_11 , V_2 ) ;
if ( NULL == V_111 )
goto V_58;
F_10 ( V_13 , V_241 , F_34 ( V_111 ) ) ;
F_10 ( V_13 , V_242 ,
F_12 ( V_22 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_111 ) ) ;
return V_49 ;
V_58:
return V_50 ;
}
T_2 F_118 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
T_16 * V_243 ;
struct V_1 * V_2 = V_12 ;
T_17 V_244 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_245 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_243 = ( T_16 * ) V_2 -> V_54 -> V_55 ;
F_25 ( V_2 -> V_54 , sizeof( T_16 ) ) ;
V_244 = F_102 ( V_243 -> V_244 ) ;
if ( F_119 ( V_11 -> V_246 , V_244 ) ) {
F_10 ( V_13 ,
V_247 ,
F_120 ( V_244 ) ) ;
}
return V_49 ;
}
T_2 F_121 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
T_18 * V_248 ;
struct V_1 * V_2 = V_12 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_245 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_248 = ( T_18 * ) V_2 -> V_54 -> V_55 ;
F_25 ( V_2 -> V_54 , sizeof( T_18 ) ) ;
F_10 ( V_13 , V_249 ,
F_120 ( F_102 ( V_248 -> V_244 ) ) ) ;
return V_49 ;
}
T_2 F_122 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
T_19 V_250 = F_123 () ;
int error ;
if ( ! F_37 ( V_2 , V_11 ) ) {
F_10 ( V_13 , V_251 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! F_1 ( V_2 , sizeof( V_252 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
error = F_124 ( V_11 , V_2 , V_13 ) ;
switch ( error ) {
case V_97 :
break;
case V_253 :
case V_254 :
F_14 ( V_7 , V_255 ) ;
goto V_256;
case V_257 :
case V_258 :
F_14 ( V_7 , V_255 ) ;
goto V_259;
case V_260 :
goto V_261;
case V_262 :
return F_125 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
( V_216 * ) V_2 -> V_51 . V_263 , sizeof( V_264 ) ) ;
default:
F_126 () ;
}
if ( V_2 -> V_5 -> V_265 & V_266 )
V_250 = F_127 () ;
if ( V_11 -> V_107 [ V_108 ] ) {
F_10 ( V_13 , V_242 ,
F_12 ( V_108 ) ) ;
}
if ( V_2 -> V_267 )
F_10 ( V_13 , V_268 , V_250 ) ;
return V_49 ;
V_259:
if ( V_2 -> V_267 )
F_10 ( V_13 , V_268 , F_127 () ) ;
return V_133 ;
V_256:
if ( V_2 -> V_267 )
F_10 ( V_13 , V_268 , V_250 ) ;
return V_133 ;
V_261:
return V_49 ;
}
T_2 F_128 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
int error ;
if ( ! F_37 ( V_2 , V_11 ) ) {
F_10 ( V_13 , V_251 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! F_1 ( V_2 , sizeof( V_252 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
error = F_124 ( V_11 , V_2 , V_13 ) ;
switch ( error ) {
case V_97 :
case V_253 :
case V_257 :
case V_258 :
case V_254 :
break;
case V_260 :
goto V_261;
case V_262 :
return F_125 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
( V_216 * ) V_2 -> V_51 . V_263 , sizeof( V_264 ) ) ;
default:
F_126 () ;
}
if ( V_2 -> V_267 ) {
F_10 ( V_13 , V_269 , F_16 () ) ;
F_10 ( V_13 , V_268 , F_127 () ) ;
F_10 ( V_13 , V_242 ,
F_12 ( V_22 ) ) ;
}
V_261:
return V_49 ;
}
T_2 F_129 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
T_20 * V_270 ;
T_15 V_232 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_271 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_270 = F_130 ( V_2 ) ;
if ( ! V_270 )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
V_2 -> V_51 . V_272 = V_270 ;
V_232 = F_102 ( V_270 -> V_235 ) ;
if ( F_110 ( V_232 , V_11 -> V_236 ) ) {
F_67 ( L_6 , V_138 , V_232 ,
V_11 -> V_236 ) ;
return V_133 ;
}
if ( ! F_110 ( V_232 , V_11 -> V_237 ) )
return F_111 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
F_10 ( V_13 , V_273 , F_34 ( V_2 ) ) ;
return V_49 ;
}
static T_2 F_19 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_33 * V_34 = NULL ;
struct V_1 * V_2 = V_12 ;
struct V_1 * abort ;
V_34 = F_131 ( V_7 , V_11 , V_2 ) ;
if ( V_34 ) {
abort = F_132 ( V_11 , V_2 , 0 ) ;
if ( ! abort ) {
F_133 ( V_34 ) ;
return V_50 ;
}
if ( F_134 ( abort ) )
V_34 -> V_41 = F_102 ( V_2 -> V_40 -> V_41 ) ;
abort -> V_54 -> V_44 = V_9 -> V_43 . V_44 ;
F_135 ( V_34 , abort ) ;
F_10 ( V_13 , V_47 ,
F_24 ( V_34 ) ) ;
F_14 ( V_7 , V_48 ) ;
F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
return V_49 ;
}
return V_50 ;
}
T_2 F_136 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
V_163 * V_186 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_205 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
F_100 ( V_186 , V_2 -> V_5 ) ;
if ( ( void * ) V_186 != ( void * ) V_2 -> V_226 )
return F_61 ( V_7 , V_9 , V_11 , type , V_12 ,
( void * ) V_186 , V_13 ) ;
F_10 ( V_13 , V_274 ,
F_34 ( V_2 ) ) ;
return V_49 ;
}
T_2 F_137 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
struct V_1 * V_111 ;
struct V_14 * V_15 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_17 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_15 = F_9 ( V_11 , 0 , V_18 ,
0 , 0 , 0 , NULL , V_19 ) ;
if ( ! V_15 )
goto V_58;
V_111 = F_138 ( V_11 , V_2 ) ;
if ( ! V_111 )
goto V_275;
F_10 ( V_13 , V_20 , F_11 ( V_15 ) ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_22 ) ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_23 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_25 ) ) ;
F_14 ( V_7 , V_26 ) ;
F_15 ( V_7 , V_27 ) ;
F_10 ( V_13 , V_61 , F_34 ( V_111 ) ) ;
F_10 ( V_13 , V_28 , F_16 () ) ;
return V_29 ;
V_275:
F_52 ( V_15 ) ;
V_58:
return V_50 ;
}
T_2 F_83 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
struct V_276 * V_54 = V_2 -> V_54 ;
V_17 * V_277 ;
V_163 * V_186 ;
V_46 * V_278 ;
int V_279 = 0 ;
int V_280 = 0 ;
F_14 ( V_7 , V_39 ) ;
V_277 = ( V_17 * ) V_2 -> V_5 ;
do {
if ( F_2 ( V_277 -> V_6 ) < sizeof( V_17 ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
if ( V_281 == V_277 -> type )
V_279 = 1 ;
if ( V_66 == V_277 -> type )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( V_282 == V_277 -> type )
V_280 = 1 ;
if ( V_283 == V_277 -> type ) {
F_100 (err, ch) {
if ( V_206 == V_186 -> V_164 ) {
V_280 = 1 ;
break;
}
}
}
V_278 = ( ( V_46 * ) V_277 ) + F_139 ( F_2 ( V_277 -> V_6 ) ) ;
if ( V_278 > F_140 ( V_54 ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_277 = ( V_17 * ) V_278 ;
} while ( V_278 < F_140 ( V_54 ) );
if ( V_279 )
return F_141 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
else if ( V_280 )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
else
return F_19 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
static T_2 F_141 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_33 * V_34 = NULL ;
struct V_1 * V_2 = V_12 ;
struct V_1 * V_284 ;
V_34 = F_131 ( V_7 , V_11 , V_2 ) ;
if ( V_34 ) {
V_284 = F_138 ( V_11 , V_2 ) ;
if ( ! V_284 ) {
F_133 ( V_34 ) ;
return V_50 ;
}
if ( F_134 ( V_284 ) )
V_34 -> V_41 = F_102 ( V_2 -> V_40 -> V_41 ) ;
V_284 -> V_54 -> V_44 = V_9 -> V_43 . V_44 ;
F_135 ( V_34 , V_284 ) ;
F_10 ( V_13 , V_47 ,
F_24 ( V_34 ) ) ;
F_14 ( V_7 , V_48 ) ;
if ( ! F_1 ( V_2 , sizeof( V_17 ) ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
return V_50 ;
}
T_2 F_142 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
if ( ! F_1 ( V_2 , sizeof( V_17 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
F_14 ( V_7 , V_39 ) ;
return F_141 ( V_7 , V_9 , NULL , type , V_12 , V_13 ) ;
}
T_2 F_143 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type , void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
struct V_1 * V_285 = NULL ;
struct V_286 * V_287 = NULL ;
T_21 * V_288 ;
union V_153 * V_289 ;
T_15 V_290 ;
int V_6 ;
if ( ! F_37 ( V_2 , V_11 ) ) {
F_10 ( V_13 , V_251 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! V_7 -> V_37 . V_291 && ! V_2 -> V_92 )
return F_84 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_292 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_288 = ( T_21 * ) V_2 -> V_54 -> V_55 ;
V_290 = F_102 ( V_288 -> V_290 ) ;
V_289 = (union V_153 * ) V_288 -> V_293 ;
V_6 = F_2 ( V_289 -> V_294 . V_6 ) ;
if ( V_6 < sizeof( T_8 ) )
return F_61 ( V_7 , V_9 , V_11 , type , V_12 ,
( void * ) V_289 , V_13 ) ;
if ( ! F_144 ( V_11 ,
( T_8 * ) ( ( void * ) V_289 + V_6 ) ,
( void * ) V_2 -> V_226 ,
& V_287 ) )
return F_61 ( V_7 , V_9 , V_11 , type , V_12 ,
( void * ) V_287 , V_13 ) ;
if ( V_290 == V_11 -> V_95 . V_295 + 1 ) {
if ( ! V_2 -> V_296 )
F_145 ( V_11 ) ;
V_285 = F_146 ( (struct V_10 * )
V_11 , V_2 ) ;
if ( ! V_285 )
return V_50 ;
} else if ( V_290 < V_11 -> V_95 . V_295 + 1 ) {
V_285 = F_147 ( V_11 , V_288 -> V_290 ) ;
if ( ! V_285 )
return V_133 ;
V_285 -> V_69 = NULL ;
} else {
return V_133 ;
}
V_285 -> V_204 = V_2 -> V_297 ;
F_10 ( V_13 , V_61 , F_34 ( V_285 ) ) ;
if ( V_11 -> V_298 ) {
F_54 ( V_9 , V_11 , type , V_11 -> V_298 , V_13 ) ;
( (struct V_10 * ) V_11 ) -> V_298 = NULL ;
}
return V_49 ;
}
T_2 F_148 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type , void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_285 = V_12 ;
struct V_1 * V_299 = V_11 -> V_300 ;
struct V_1 * abort ;
struct V_286 * V_287 = NULL ;
T_21 * V_301 ;
T_15 V_302 , V_303 ;
if ( ! F_37 ( V_285 , V_11 ) ) {
F_10 ( V_13 , V_251 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! V_7 -> V_37 . V_291 && ! V_285 -> V_92 )
return F_84 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_285 , sizeof( V_292 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_301 = ( T_21 * ) V_285 -> V_54 -> V_55 ;
V_303 = F_102 ( V_301 -> V_290 ) ;
if ( ! F_144 ( V_11 ,
( T_8 * ) V_301 -> V_293 ,
( void * ) V_285 -> V_226 ,
& V_287 ) )
return F_61 ( V_7 , V_9 , V_11 , type , V_12 ,
( void * ) V_287 , V_13 ) ;
if ( V_299 ) {
V_301 = ( T_21 * ) V_299 -> V_51 . V_301 ;
V_302 = F_102 ( V_301 -> V_290 ) ;
} else {
V_302 = V_11 -> V_295 - 1 ;
}
if ( F_149 ( V_303 , V_302 + 1 ) &&
! ( V_11 -> V_300 ) ) {
abort = F_132 ( V_11 , V_285 ,
sizeof( V_163 ) ) ;
if ( abort ) {
F_150 ( abort , V_304 , 0 ) ;
F_10 ( V_13 , V_61 ,
F_34 ( abort ) ) ;
}
F_10 ( V_13 , V_21 ,
F_12 ( V_193 ) ) ;
F_10 ( V_13 , V_167 , F_16 () ) ;
F_10 ( V_13 , V_115 ,
F_58 ( V_305 ) ) ;
F_10 ( V_13 , V_117 ,
F_59 ( V_304 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_228 ;
}
if ( ( V_303 == V_302 ) && V_11 -> V_300 ) {
F_10 ( V_13 , V_21 ,
F_12 ( V_193 ) ) ;
if ( ! F_151 ( (struct V_10 * ) V_11 ,
V_285 ) ) {
F_10 ( V_13 , V_306 ,
F_16 () ) ;
return V_49 ;
}
abort = F_132 ( V_11 , V_285 ,
sizeof( V_163 ) ) ;
if ( abort ) {
F_150 ( abort , V_307 , 0 ) ;
F_10 ( V_13 , V_61 ,
F_34 ( abort ) ) ;
}
F_10 ( V_13 , V_167 , F_16 () ) ;
F_10 ( V_13 , V_115 ,
F_58 ( V_305 ) ) ;
F_10 ( V_13 , V_117 ,
F_59 ( V_304 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_228 ;
}
return V_133 ;
}
T_2 F_152 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
struct V_308 * V_309 ;
struct V_310 * V_311 ;
T_1 V_36 ;
T_15 V_312 ;
if ( ! F_37 ( V_2 , V_11 ) ) {
F_10 ( V_13 , V_251 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_313 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_309 = (struct V_308 * ) V_2 -> V_54 -> V_55 ;
V_2 -> V_51 . V_309 = V_309 ;
V_36 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_36 -= sizeof( struct V_225 ) ;
F_25 ( V_2 -> V_54 , V_36 ) ;
V_312 = F_102 ( V_309 -> V_314 ) ;
F_67 ( L_7 , V_138 , V_312 ) ;
if ( F_153 ( & V_11 -> V_95 . V_315 , V_312 ) < 0 )
goto V_256;
F_154 (skip, chunk) {
if ( F_2 ( V_311 -> V_316 ) >= V_11 -> V_89 . V_100 )
goto V_256;
}
F_10 ( V_13 , V_317 , F_120 ( V_312 ) ) ;
if ( V_36 > sizeof( struct V_308 ) )
F_10 ( V_13 , V_318 ,
F_34 ( V_2 ) ) ;
if ( V_11 -> V_107 [ V_108 ] ) {
F_10 ( V_13 , V_242 ,
F_12 ( V_108 ) ) ;
}
F_10 ( V_13 , V_268 , F_123 () ) ;
return V_49 ;
V_256:
return V_133 ;
}
T_2 F_155 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
struct V_308 * V_309 ;
struct V_310 * V_311 ;
T_1 V_36 ;
T_15 V_312 ;
if ( ! F_37 ( V_2 , V_11 ) ) {
F_10 ( V_13 , V_251 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_313 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_309 = (struct V_308 * ) V_2 -> V_54 -> V_55 ;
V_2 -> V_51 . V_309 = V_309 ;
V_36 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_36 -= sizeof( struct V_225 ) ;
F_25 ( V_2 -> V_54 , V_36 ) ;
V_312 = F_102 ( V_309 -> V_314 ) ;
F_67 ( L_7 , V_138 , V_312 ) ;
if ( F_153 ( & V_11 -> V_95 . V_315 , V_312 ) < 0 )
goto V_319;
F_154 (skip, chunk) {
if ( F_2 ( V_311 -> V_316 ) >= V_11 -> V_89 . V_100 )
goto V_319;
}
F_10 ( V_13 , V_317 , F_120 ( V_312 ) ) ;
if ( V_36 > sizeof( struct V_308 ) )
F_10 ( V_13 , V_318 ,
F_34 ( V_2 ) ) ;
V_319:
F_10 ( V_13 , V_269 , F_16 () ) ;
F_10 ( V_13 , V_268 , F_127 () ) ;
F_10 ( V_13 , V_242 ,
F_12 ( V_22 ) ) ;
return V_49 ;
}
static T_7 F_49 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
struct V_1 * V_2 )
{
struct V_320 * V_321 ;
struct V_322 * V_323 ;
unsigned int V_324 ;
T_1 V_325 ;
V_46 * V_326 ;
V_46 * V_327 ;
V_321 = (struct V_320 * ) V_2 -> V_54 -> V_55 ;
V_2 -> V_51 . V_321 = V_321 ;
F_25 ( V_2 -> V_54 , sizeof( struct V_320 ) ) ;
if ( ! F_156 ( V_11 , V_321 -> V_328 ) )
return V_329 ;
V_325 = F_2 ( V_321 -> V_330 ) ;
if ( V_325 != V_11 -> V_331 && ! F_157 ( V_11 , V_325 ) )
return V_332 ;
V_324 = F_2 ( V_2 -> V_5 -> V_6 ) - sizeof( V_333 ) ;
V_323 = F_158 ( F_2 ( V_321 -> V_328 ) ) ;
if ( V_324 != V_323 -> V_334 )
return V_262 ;
V_327 = V_321 -> V_323 ;
F_25 ( V_2 -> V_54 , V_324 ) ;
V_326 = F_159 ( V_327 , V_324 , V_19 ) ;
if ( ! V_326 )
goto V_58;
memset ( V_327 , 0 , V_324 ) ;
F_160 ( V_11 , V_2 -> V_54 ,
(struct V_335 * ) V_2 -> V_5 ,
V_19 ) ;
if ( memcmp ( V_326 , V_327 , V_324 ) ) {
F_161 ( V_326 ) ;
return V_88 ;
}
F_161 ( V_326 ) ;
V_2 -> V_92 = 1 ;
return V_97 ;
V_58:
return V_86 ;
}
T_2 F_162 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_320 * V_321 ;
struct V_1 * V_2 = V_12 ;
struct V_1 * V_32 ;
T_7 error ;
if ( ! V_11 -> V_95 . V_96 )
return F_163 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_37 ( V_2 , V_11 ) ) {
F_10 ( V_13 , V_251 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_335 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_321 = (struct V_320 * ) V_2 -> V_54 -> V_55 ;
error = F_49 ( V_7 , V_9 , V_11 , type , V_2 ) ;
switch ( error ) {
case V_329 :
V_32 = F_88 ( V_11 , V_2 ,
V_336 ,
& V_321 -> V_328 ,
sizeof( T_1 ) , 0 ) ;
if ( V_32 ) {
F_10 ( V_13 , V_61 ,
F_34 ( V_32 ) ) ;
}
case V_332 :
case V_88 :
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
case V_262 :
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
case V_86 :
return V_50 ;
default:
break;
}
if ( V_11 -> V_331 != F_2 ( V_321 -> V_330 ) ) {
struct V_14 * V_15 ;
V_15 = F_164 ( V_11 , F_2 ( V_321 -> V_330 ) ,
V_337 , V_19 ) ;
if ( ! V_15 )
return - V_338 ;
F_10 ( V_13 , V_20 ,
F_11 ( V_15 ) ) ;
}
return V_49 ;
}
T_2 F_163 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_339 = V_12 ;
struct V_1 * V_32 ;
V_17 * V_288 ;
F_67 ( L_8 , V_138 , type . V_2 ) ;
if ( ! F_37 ( V_339 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_339 , sizeof( V_17 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
switch ( type . V_2 & V_340 ) {
case V_341 :
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
case V_342 :
V_288 = V_339 -> V_5 ;
V_32 = F_88 ( V_11 , V_339 ,
V_343 , V_288 ,
F_139 ( F_2 ( V_288 -> V_6 ) ) ,
0 ) ;
if ( V_32 ) {
F_10 ( V_13 , V_61 ,
F_34 ( V_32 ) ) ;
}
F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
return V_49 ;
case V_344 :
return V_133 ;
case V_345 :
V_288 = V_339 -> V_5 ;
V_32 = F_88 ( V_11 , V_339 ,
V_343 , V_288 ,
F_139 ( F_2 ( V_288 -> V_6 ) ) ,
0 ) ;
if ( V_32 ) {
F_10 ( V_13 , V_61 ,
F_34 ( V_32 ) ) ;
}
return V_49 ;
default:
break;
}
return V_133 ;
}
T_2 F_84 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
if ( ! F_1 ( V_2 , sizeof( V_17 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
F_67 ( L_9 , V_138 , type . V_2 ) ;
return V_133 ;
}
T_2 F_6 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_14 ( V_7 , V_346 ) ;
F_10 ( V_13 , V_167 , F_16 () ) ;
return V_49 ;
}
T_2 F_165 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
if ( ! F_1 ( V_2 , sizeof( V_17 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
return V_347 ;
}
static T_2 F_125 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
void * V_12 ,
T_4 * V_13 ,
const V_46 * V_348 ,
const T_9 V_124 )
{
struct V_33 * V_34 = NULL ;
struct V_1 * V_2 = V_12 ;
struct V_1 * abort = NULL ;
if ( F_38 ( V_66 , V_11 ) )
goto V_349;
abort = F_166 ( V_11 , V_2 , V_348 , V_124 ) ;
if ( ! abort )
goto V_58;
if ( V_11 ) {
if ( V_2 -> V_5 -> type == V_350 &&
! V_11 -> V_95 . V_351 . V_352 ) {
V_63 * V_353 ;
V_353 = ( V_63 * ) V_2 -> V_5 ;
if ( ! F_1 ( V_2 ,
sizeof( V_63 ) ) )
abort -> V_5 -> V_265 |= V_354 ;
else {
unsigned int V_355 ;
V_355 = F_102 ( V_353 -> V_52 . V_352 ) ;
F_10 ( V_13 , V_356 ,
F_120 ( V_355 ) ) ;
}
}
F_10 ( V_13 , V_61 , F_34 ( abort ) ) ;
F_14 ( V_7 , V_48 ) ;
if ( V_11 -> V_174 <= V_75 ) {
F_10 ( V_13 , V_21 ,
F_12 ( V_72 ) ) ;
F_10 ( V_13 , V_115 ,
F_58 ( V_68 ) ) ;
F_10 ( V_13 , V_214 ,
F_59 ( V_357 ) ) ;
} else {
F_10 ( V_13 , V_115 ,
F_58 ( V_305 ) ) ;
F_10 ( V_13 , V_117 ,
F_59 ( V_357 ) ) ;
F_15 ( V_7 , V_27 ) ;
}
} else {
V_34 = F_131 ( V_7 , V_11 , V_2 ) ;
if ( ! V_34 )
goto V_358;
if ( F_134 ( abort ) )
V_34 -> V_41 = F_102 ( V_2 -> V_40 -> V_41 ) ;
abort -> V_54 -> V_44 = V_9 -> V_43 . V_44 ;
F_135 ( V_34 , abort ) ;
F_10 ( V_13 , V_47 ,
F_24 ( V_34 ) ) ;
F_14 ( V_7 , V_48 ) ;
}
F_14 ( V_7 , V_67 ) ;
V_349:
F_6 ( V_7 , V_9 , V_11 , F_87 ( 0 ) , V_12 , V_13 ) ;
return V_228 ;
V_358:
F_23 ( abort ) ;
V_58:
return V_50 ;
}
static T_2 F_8 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
static const char V_359 [] = L_10 ;
return F_125 ( V_7 , V_9 , V_11 , V_12 , V_13 , V_359 ,
sizeof( V_359 ) ) ;
}
static T_2 F_61 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 , void * V_360 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
struct V_286 * V_361 = V_360 ;
struct V_1 * abort = NULL ;
if ( F_38 ( V_66 , V_11 ) )
goto V_349;
abort = F_167 ( V_11 , V_2 , V_361 ) ;
if ( ! abort )
goto V_58;
F_10 ( V_13 , V_61 , F_34 ( abort ) ) ;
F_14 ( V_7 , V_48 ) ;
F_10 ( V_13 , V_115 ,
F_58 ( V_305 ) ) ;
F_10 ( V_13 , V_117 ,
F_59 ( V_357 ) ) ;
F_15 ( V_7 , V_27 ) ;
F_14 ( V_7 , V_67 ) ;
V_349:
F_6 ( V_7 , V_9 , V_11 , F_87 ( 0 ) , V_12 , V_13 ) ;
return V_228 ;
V_58:
return V_50 ;
}
static T_2 F_111 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
static const char V_359 [] = L_11 ;
return F_125 ( V_7 , V_9 , V_11 , V_12 , V_13 , V_359 ,
sizeof( V_359 ) ) ;
}
static T_2 F_7 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
static const char V_359 [] = L_12 ;
if ( ! V_11 )
return F_165 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
return F_125 ( V_7 , V_9 , V_11 , V_12 , V_13 , V_359 ,
sizeof( V_359 ) ) ;
}
T_2 F_168 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_30 ;
struct V_10 * V_362 ;
F_10 ( V_13 , V_24 ,
F_13 ( V_175 ) ) ;
V_30 = F_104 ( V_11 , & V_11 -> V_43 . V_203 , V_19 , 0 ) ;
if ( ! V_30 )
goto V_58;
F_10 ( V_13 , V_363 ,
F_34 ( V_30 ) ) ;
V_362 = (struct V_10 * ) V_11 ;
F_10 ( V_13 , V_60 , F_33 ( V_362 ) ) ;
F_10 ( V_13 , V_73 ,
F_12 ( V_72 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_30 ) ) ;
return V_49 ;
V_58:
return V_50 ;
}
T_2 F_169 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_364 * V_365 = V_12 ;
F_10 ( V_13 , V_366 , F_170 ( V_365 ) ) ;
return V_49 ;
}
T_2 F_171 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
int V_187 ;
F_10 ( V_13 , V_24 ,
F_13 ( V_367 ) ) ;
V_187 = V_49 ;
if ( F_113 ( & V_11 -> V_239 ) ) {
V_187 = F_172 ( V_7 , V_9 , V_11 , type ,
V_12 , V_13 ) ;
}
return V_187 ;
}
T_2 F_173 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * abort = V_12 ;
T_2 V_182 ;
V_182 = V_49 ;
F_10 ( V_13 , V_61 , F_34 ( abort ) ) ;
F_10 ( V_13 , V_115 ,
F_58 ( V_305 ) ) ;
F_10 ( V_13 , V_117 ,
F_59 ( V_368 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_182 ;
}
T_2 F_174 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_10 ( V_13 , V_369 , F_58 ( - V_370 ) ) ;
return V_49 ;
}
T_2 F_175 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_10 ( V_13 , V_369 ,
F_58 ( - V_371 ) ) ;
return V_49 ;
}
T_2 F_176 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_10 ( V_13 , V_21 ,
F_12 ( V_72 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_25 ) ) ;
F_14 ( V_7 , V_26 ) ;
F_10 ( V_13 , V_28 , F_16 () ) ;
return V_29 ;
}
T_2 F_177 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 , T_4 * V_13 )
{
return F_176 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_178 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * abort = V_12 ;
T_2 V_182 ;
F_10 ( V_13 , V_21 ,
F_12 ( V_72 ) ) ;
V_182 = V_49 ;
F_10 ( V_13 , V_61 , F_34 ( abort ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_25 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_10 ( V_13 , V_115 ,
F_58 ( V_68 ) ) ;
F_10 ( V_13 , V_214 ,
F_59 ( V_368 ) ) ;
return V_182 ;
}
T_2 F_179 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
return F_178 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_180 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_10 ( V_13 , V_21 ,
F_12 ( V_23 ) ) ;
return F_173 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_181 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_10 ( V_13 , V_21 ,
F_12 ( V_22 ) ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_23 ) ) ;
return F_173 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_182 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
return F_181 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_183 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
if ( V_50 == F_54 ( V_9 , V_11 , type ,
(struct V_110 * ) V_12 , V_13 ) )
return V_50 ;
F_10 ( V_13 , V_121 ,
F_56 ( V_12 ) ) ;
return V_49 ;
}
T_2 F_184 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
F_10 ( V_13 , V_372 , F_34 ( V_2 ) ) ;
F_10 ( V_13 , V_73 ,
F_12 ( V_193 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_2 ) ) ;
return V_49 ;
}
T_2 F_185 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_67 ( L_13 , V_138 ,
type . V_373 ) ;
return V_133 ;
}
T_2 F_186 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_14 * V_374 ;
V_374 = F_187 ( V_11 , V_19 ) ;
if ( ! V_374 )
return V_50 ;
F_10 ( V_13 , V_20 , F_11 ( V_374 ) ) ;
return V_49 ;
}
T_2 F_172 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_111 ;
V_111 = F_188 ( V_11 , NULL ) ;
if ( ! V_111 )
goto V_58;
F_10 ( V_13 , V_241 , F_34 ( V_111 ) ) ;
F_10 ( V_13 , V_73 ,
F_12 ( V_22 ) ) ;
F_10 ( V_13 , V_242 ,
F_12 ( V_23 ) ) ;
if ( V_11 -> V_107 [ V_108 ] )
F_10 ( V_13 , V_21 ,
F_12 ( V_108 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_375 ) ) ;
F_10 ( V_13 , V_220 , F_16 () ) ;
F_10 ( V_13 , V_61 , F_34 ( V_111 ) ) ;
return V_49 ;
V_58:
return V_50 ;
}
T_2 F_114 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
struct V_1 * V_111 ;
if ( V_2 ) {
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_233 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
}
V_111 = F_117 ( V_11 , V_2 ) ;
if ( ! V_111 )
goto V_58;
F_10 ( V_13 , V_241 , F_34 ( V_111 ) ) ;
F_10 ( V_13 , V_242 ,
F_12 ( V_22 ) ) ;
if ( V_11 -> V_107 [ V_108 ] )
F_10 ( V_13 , V_21 ,
F_12 ( V_108 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_376 ) ) ;
F_10 ( V_13 , V_220 , F_16 () ) ;
F_10 ( V_13 , V_61 , F_34 ( V_111 ) ) ;
return V_49 ;
V_58:
return V_50 ;
}
T_2 F_189 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_67 ( L_14 ,
V_138 , type . V_377 ) ;
return V_133 ;
}
T_2 F_190 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_110 * V_69 = V_12 ;
F_14 ( V_7 , V_378 ) ;
if ( V_11 -> V_113 >= V_11 -> V_114 ) {
if ( V_11 -> V_174 == V_367 ) {
F_10 ( V_13 , V_379 ,
F_12 ( V_23 ) ) ;
} else {
F_10 ( V_13 , V_115 ,
F_58 ( V_116 ) ) ;
F_10 ( V_13 , V_117 ,
F_59 ( V_118 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_29 ;
}
}
F_10 ( V_13 , V_380 , F_56 ( V_69 ) ) ;
F_10 ( V_13 , V_381 , F_56 ( V_69 ) ) ;
return V_49 ;
}
T_2 F_191 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_14 ( V_7 , V_382 ) ;
F_10 ( V_13 , V_268 , F_127 () ) ;
return V_49 ;
}
T_2 F_192 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_30 = NULL ;
struct V_209 * V_210 ;
int V_211 = V_11 -> V_212 + 1 ;
F_67 ( L_15 , V_138 ) ;
F_14 ( V_7 , V_383 ) ;
if ( V_211 <= V_11 -> V_213 ) {
V_210 = (struct V_209 * ) & V_11 -> V_43 . V_203 ;
V_30 = F_104 ( V_11 , V_210 , V_19 , 0 ) ;
if ( ! V_30 )
return V_50 ;
F_10 ( V_13 , V_363 ,
F_34 ( V_30 ) ) ;
F_10 ( V_13 , V_384 ,
F_12 ( V_72 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_30 ) ) ;
} else {
F_67 ( L_16
L_17 , V_138 , V_211 ,
V_11 -> V_213 ) ;
F_10 ( V_13 , V_115 ,
F_58 ( V_116 ) ) ;
F_10 ( V_13 , V_214 ,
F_59 ( V_118 ) ) ;
return V_29 ;
}
return V_49 ;
}
T_2 F_193 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_30 = NULL ;
int V_211 = V_11 -> V_212 + 1 ;
F_67 ( L_18 , V_138 ) ;
F_14 ( V_7 , V_385 ) ;
if ( V_211 <= V_11 -> V_213 ) {
V_30 = F_194 ( V_11 , NULL ) ;
if ( ! V_30 )
return V_50 ;
F_10 ( V_13 , V_363 ,
F_34 ( V_30 ) ) ;
F_10 ( V_13 , V_386 ,
F_12 ( V_74 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_30 ) ) ;
} else {
F_10 ( V_13 , V_115 ,
F_58 ( V_116 ) ) ;
F_10 ( V_13 , V_214 ,
F_59 ( V_118 ) ) ;
return V_29 ;
}
return V_49 ;
}
T_2 F_195 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_111 = NULL ;
F_67 ( L_19 , V_138 ) ;
F_14 ( V_7 , V_387 ) ;
( (struct V_10 * ) V_11 ) -> V_388 ++ ;
if ( V_11 -> V_113 >= V_11 -> V_114 ) {
F_10 ( V_13 , V_115 ,
F_58 ( V_116 ) ) ;
F_10 ( V_13 , V_117 ,
F_59 ( V_118 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_29 ;
}
switch ( V_11 -> V_174 ) {
case V_375 :
V_111 = F_188 ( V_11 , NULL ) ;
break;
case V_376 :
V_111 = F_117 ( V_11 , NULL ) ;
break;
default:
F_126 () ;
break;
}
if ( ! V_111 )
goto V_58;
if ( V_11 -> V_389 )
F_10 ( V_13 , V_380 ,
F_56 ( V_11 -> V_389 ) ) ;
F_10 ( V_13 , V_241 , F_34 ( V_111 ) ) ;
F_10 ( V_13 , V_242 ,
F_12 ( V_22 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_111 ) ) ;
return V_49 ;
V_58:
return V_50 ;
}
T_2 F_196 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_11 -> V_300 ;
struct V_110 * V_69 = V_2 -> V_69 ;
F_14 ( V_7 , V_390 ) ;
if ( V_69 )
F_10 ( V_13 , V_380 ,
F_56 ( V_69 ) ) ;
F_10 ( V_13 , V_372 , F_34 ( V_2 ) ) ;
if ( V_11 -> V_113 >= V_11 -> V_114 ) {
F_10 ( V_13 , V_21 ,
F_12 ( V_193 ) ) ;
F_10 ( V_13 , V_115 ,
F_58 ( V_116 ) ) ;
F_10 ( V_13 , V_117 ,
F_59 ( V_118 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_228 ;
}
F_197 ( V_11 -> V_300 ) ;
F_10 ( V_13 , V_61 ,
F_34 ( V_11 -> V_300 ) ) ;
F_10 ( V_13 , V_242 ,
F_12 ( V_193 ) ) ;
return V_49 ;
}
T_2 F_198 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_111 = NULL ;
F_67 ( L_20 , V_138 ) ;
F_14 ( V_7 , V_391 ) ;
V_111 = F_132 ( V_11 , NULL , 0 ) ;
if ( ! V_111 )
goto V_58;
F_10 ( V_13 , V_61 , F_34 ( V_111 ) ) ;
F_10 ( V_13 , V_115 ,
F_58 ( V_116 ) ) ;
F_10 ( V_13 , V_117 ,
F_59 ( V_118 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_29 ;
V_58:
return V_50 ;
}
T_2 F_199 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
int V_187 ;
F_14 ( V_7 , V_392 ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_367 ) ) ;
V_187 = V_49 ;
if ( F_113 ( & V_11 -> V_239 ) ) {
V_187 = F_172 ( V_7 , V_9 , V_11 , type ,
V_12 , V_13 ) ;
}
return V_187 ;
}
T_2 F_200 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
return V_393 ;
}
T_2 F_201 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
return V_394 ;
}
T_2 F_202 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_67 ( L_21 , V_138 , type . V_2 ) ;
return V_49 ;
}
static struct V_395 * F_130 ( struct V_1 * V_2 )
{
struct V_395 * V_396 ;
unsigned int V_36 ;
T_1 V_397 ;
T_1 V_398 ;
V_396 = (struct V_395 * ) V_2 -> V_54 -> V_55 ;
V_397 = F_2 ( V_396 -> V_399 ) ;
V_398 = F_2 ( V_396 -> V_398 ) ;
V_36 = sizeof( struct V_395 ) ;
V_36 += ( V_397 + V_398 ) * sizeof( T_15 ) ;
if ( V_36 > V_2 -> V_54 -> V_36 )
return NULL ;
F_25 ( V_2 -> V_54 , V_36 ) ;
return V_396 ;
}
static struct V_33 * F_22 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
struct V_1 * V_2 ,
const void * V_348 ,
T_9 V_124 )
{
struct V_33 * V_34 ;
struct V_1 * abort ;
V_34 = F_131 ( V_7 , V_11 , V_2 ) ;
if ( V_34 ) {
abort = F_132 ( V_11 , V_2 , V_124 ) ;
if ( ! abort ) {
F_133 ( V_34 ) ;
return NULL ;
}
if ( F_134 ( abort ) )
V_34 -> V_41 = F_102 ( V_2 -> V_40 -> V_41 ) ;
F_32 ( abort , V_124 , V_348 ) ;
abort -> V_54 -> V_44 = V_9 -> V_43 . V_44 ;
F_135 ( V_34 , abort ) ;
}
return V_34 ;
}
static struct V_33 * F_131 ( struct V_7 * V_7 ,
const struct V_10 * V_11 ,
const struct V_1 * V_2 )
{
struct V_33 * V_34 ;
struct V_110 * V_69 ;
T_1 V_400 ;
T_1 V_401 ;
T_15 V_41 ;
V_400 = F_2 ( V_2 -> V_40 -> V_204 ) ;
V_401 = F_2 ( V_2 -> V_40 -> V_297 ) ;
if ( V_11 ) {
switch ( V_2 -> V_5 -> type ) {
case V_350 :
{
V_63 * V_353 ;
V_353 = ( V_63 * ) V_2 -> V_5 ;
V_41 = F_102 ( V_353 -> V_52 . V_352 ) ;
break;
}
default:
V_41 = V_11 -> V_95 . V_351 . V_352 ;
break;
}
} else {
switch ( V_2 -> V_5 -> type ) {
case V_402 :
{
V_42 * V_151 ;
V_151 = ( V_42 * ) V_2 -> V_5 ;
V_41 = F_102 ( V_151 -> V_52 . V_352 ) ;
break;
}
default:
V_41 = F_102 ( V_2 -> V_40 -> V_41 ) ;
break;
}
}
V_69 = F_203 ( V_7 , F_29 ( V_2 ) , V_19 ) ;
if ( ! V_69 )
goto V_58;
F_204 ( V_69 , (union V_128 * ) & V_2 -> V_204 ,
F_18 ( V_7 -> V_37 . V_38 ) ) ;
V_34 = F_205 ( & V_69 -> V_34 , V_69 , V_400 , V_401 ) ;
V_34 = F_206 ( V_34 , V_41 , 0 ) ;
return V_34 ;
V_58:
return NULL ;
}
void F_133 ( struct V_33 * V_34 )
{
F_207 ( V_34 -> V_69 ) ;
}
static void F_46 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const struct V_1 * V_2 ,
T_4 * V_13 ,
struct V_1 * V_32 )
{
struct V_33 * V_34 ;
if ( V_32 ) {
V_34 = F_131 ( V_7 , V_11 , V_2 ) ;
if ( V_34 ) {
struct V_85 * V_403 ;
V_403 = V_2 -> V_51 . V_84 ;
V_34 -> V_41 = V_403 -> V_89 . V_179 ;
V_32 -> V_54 -> V_44 = V_9 -> V_43 . V_44 ;
F_135 ( V_34 , V_32 ) ;
F_10 ( V_13 , V_47 ,
F_24 ( V_34 ) ) ;
F_14 ( V_7 , V_48 ) ;
} else
F_23 ( V_32 ) ;
}
}
static int F_124 ( const struct V_10 * V_11 ,
struct V_1 * V_2 ,
T_4 * V_13 )
{
V_264 * V_263 ;
struct V_1 * V_186 ;
T_9 V_404 ;
T_22 V_405 ;
int V_406 ;
T_15 V_312 ;
struct V_407 * V_408 = (struct V_407 * ) & V_11 -> V_95 . V_315 ;
struct V_81 * V_44 = V_11 -> V_43 . V_44 ;
struct V_7 * V_7 = F_75 ( V_44 ) ;
T_23 V_409 ;
T_23 V_410 ;
V_216 V_411 = 0 ;
V_263 = V_2 -> V_51 . V_263 = ( V_264 * ) V_2 -> V_54 -> V_55 ;
F_25 ( V_2 -> V_54 , sizeof( V_264 ) ) ;
V_312 = F_102 ( V_263 -> V_312 ) ;
F_67 ( L_7 , V_138 , V_312 ) ;
if ( ! V_2 -> V_412 ) {
struct V_158 * V_159 ;
V_2 -> V_412 = 1 ;
V_159 = F_69 (
F_208 ( F_209 ( V_2 -> V_54 ) -> V_413 ) ) ;
if ( V_159 && V_159 -> V_414 ( V_2 -> V_54 ) && V_11 -> V_95 . V_415 ) {
F_10 ( V_13 , V_416 ,
F_120 ( V_312 ) ) ;
}
}
V_406 = F_153 ( & V_11 -> V_95 . V_315 , V_312 ) ;
if ( V_406 < 0 ) {
if ( V_2 -> V_11 )
V_2 -> V_11 -> V_417 . V_418 ++ ;
return V_253 ;
} else if ( V_406 > 0 ) {
F_10 ( V_13 , V_419 , F_120 ( V_312 ) ) ;
return V_257 ;
}
V_404 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_404 -= sizeof( V_252 ) ;
V_405 = V_420 ;
if ( ( V_404 >= V_11 -> V_180 ) && ( ! V_11 -> V_421 . V_422 ) ) {
F_10 ( V_13 , V_423 , F_16 () ) ;
}
if ( ( ! V_2 -> V_424 ) && ( ! V_11 -> V_180 || V_11 -> V_425 ||
( V_404 > V_11 -> V_180 + V_11 -> V_426 ) ) ) {
if ( F_210 ( V_408 ) &&
( F_211 ( V_408 ) + 1 ) == V_312 ) {
F_67 ( L_22 , V_138 , V_312 ) ;
V_405 = V_427 ;
} else {
F_67 ( L_23 ,
V_138 , V_312 , V_404 , V_11 -> V_180 ) ;
return V_258 ;
}
}
if ( * V_44 -> V_428 -> V_429 ) {
if ( F_210 ( V_408 ) &&
( F_211 ( V_408 ) + 1 ) == V_312 ) {
F_67 ( L_24 ,
V_138 , V_312 ) ;
V_405 = V_427 ;
}
}
if ( F_3 ( 0 == V_404 ) ) {
V_186 = F_212 ( V_11 , V_2 , V_312 ) ;
if ( V_186 ) {
F_10 ( V_13 , V_61 ,
F_34 ( V_186 ) ) ;
}
F_10 ( V_13 , V_167 , F_16 () ) ;
F_10 ( V_13 , V_115 ,
F_58 ( V_305 ) ) ;
F_10 ( V_13 , V_117 ,
F_59 ( V_430 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_260 ;
}
V_2 -> V_424 = 1 ;
if ( V_2 -> V_5 -> V_265 & V_431 ) {
F_14 ( V_7 , V_432 ) ;
if ( V_2 -> V_11 )
V_2 -> V_11 -> V_417 . V_433 ++ ;
} else {
F_14 ( V_7 , V_434 ) ;
if ( V_2 -> V_11 )
V_2 -> V_11 -> V_417 . V_435 ++ ;
V_411 = 1 ;
}
V_410 = F_2 ( V_263 -> V_316 ) ;
if ( V_410 >= V_11 -> V_89 . V_100 ) {
F_10 ( V_13 , V_436 , F_120 ( V_312 ) ) ;
V_186 = F_88 ( V_11 , V_2 , V_437 ,
& V_263 -> V_316 ,
sizeof( V_263 -> V_316 ) ,
sizeof( T_23 ) ) ;
if ( V_186 )
F_10 ( V_13 , V_61 ,
F_34 ( V_186 ) ) ;
return V_254 ;
}
V_409 = F_2 ( V_263 -> V_409 ) ;
if ( V_411 && F_213 ( V_409 , F_214 ( & V_11 -> V_438 -> V_439 , V_410 ) ) ) {
return V_262 ;
}
F_10 ( V_13 , V_405 , F_34 ( V_2 ) ) ;
return V_97 ;
}
