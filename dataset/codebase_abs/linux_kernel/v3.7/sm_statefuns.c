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
if ( ! F_21 ( V_7 , V_11 , V_2 -> V_5 -> type ,
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
if ( ! F_21 ( V_7 , V_11 , V_2 -> V_5 -> type ,
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
V_92 . V_54 = V_2 -> V_91 ;
V_92 . V_11 = V_2 -> V_11 ;
V_92 . V_40 = V_2 -> V_40 ;
V_92 . V_5 = ( V_17 * ) F_48 ( V_2 -> V_91 ,
sizeof( V_17 ) ) ;
F_25 ( V_2 -> V_91 , sizeof( V_17 ) ) ;
V_92 . V_69 = V_2 -> V_69 ;
V_93 = F_49 ( V_7 , V_9 , V_31 , type , & V_92 ) ;
F_50 ( V_2 -> V_91 ) ;
if ( V_93 != V_94 ) {
F_35 ( V_31 ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
}
V_30 = F_51 ( V_31 , V_2 ) ;
if ( ! V_30 )
goto V_59;
V_15 = F_9 ( V_31 , 0 , V_95 , 0 ,
V_31 -> V_89 . V_96 ,
V_31 -> V_89 . V_97 ,
NULL , V_19 ) ;
if ( ! V_15 )
goto V_98;
if ( V_31 -> V_99 . V_100 ) {
V_79 = F_52 ( V_31 ,
V_19 ) ;
if ( ! V_79 )
goto V_101;
}
F_10 ( V_13 , V_60 , F_33 ( V_31 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_102 ) ) ;
F_14 ( V_7 , V_27 ) ;
F_14 ( V_7 , V_103 ) ;
F_10 ( V_13 , V_104 , F_16 () ) ;
if ( V_31 -> V_105 )
F_10 ( V_13 , V_73 ,
F_12 ( V_106 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_30 ) ) ;
F_10 ( V_13 , V_20 , F_11 ( V_15 ) ) ;
if ( V_79 )
F_10 ( V_13 , V_20 ,
F_11 ( V_79 ) ) ;
return V_49 ;
V_101:
F_53 ( V_15 ) ;
V_98:
F_23 ( V_30 ) ;
V_59:
F_35 ( V_31 ) ;
V_58:
return V_50 ;
}
T_2 F_54 ( struct V_7 * V_7 ,
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
F_13 ( V_102 ) ) ;
F_14 ( V_7 , V_27 ) ;
F_14 ( V_7 , V_107 ) ;
F_10 ( V_13 , V_104 , F_16 () ) ;
if ( V_11 -> V_105 )
F_10 ( V_13 , V_73 ,
F_12 ( V_106 ) ) ;
V_15 = F_9 ( V_11 , 0 , V_95 ,
0 , V_11 -> V_89 . V_96 ,
V_11 -> V_89 . V_97 ,
NULL , V_19 ) ;
if ( ! V_15 )
goto V_58;
F_10 ( V_13 , V_20 , F_11 ( V_15 ) ) ;
if ( V_11 -> V_99 . V_100 ) {
V_15 = F_52 ( V_11 , V_19 ) ;
if ( ! V_15 )
goto V_58;
F_10 ( V_13 , V_20 ,
F_11 ( V_15 ) ) ;
}
return V_49 ;
V_58:
return V_50 ;
}
static T_2 F_55 ( const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_108 * V_69 = (struct V_108 * ) V_12 ;
struct V_1 * V_109 ;
V_109 = F_56 ( V_11 , V_69 ) ;
if ( ! V_109 )
return V_50 ;
F_10 ( V_13 , V_110 ,
F_57 ( V_69 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_109 ) ) ;
return V_49 ;
}
T_2 F_58 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_108 * V_69 = (struct V_108 * ) V_12 ;
if ( V_11 -> V_111 >= V_11 -> V_112 ) {
F_10 ( V_13 , V_113 ,
F_59 ( V_114 ) ) ;
F_10 ( V_13 , V_115 ,
F_60 ( V_116 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_29 ;
}
if ( V_69 -> V_117 & V_118 ) {
if ( V_50 ==
F_55 ( V_9 , V_11 , type , V_12 ,
V_13 ) )
return V_50 ;
F_10 ( V_13 , V_119 ,
F_57 ( V_69 ) ) ;
}
F_10 ( V_13 , V_120 ,
F_57 ( V_69 ) ) ;
F_10 ( V_13 , V_121 ,
F_57 ( V_69 ) ) ;
return V_49 ;
}
T_2 F_61 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
struct V_1 * V_109 ;
T_8 V_122 = 0 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_123 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_2 -> V_51 . V_124 = ( V_125 * ) V_2 -> V_54 -> V_55 ;
V_122 = F_2 ( V_2 -> V_5 -> V_6 ) - sizeof( V_17 ) ;
if ( ! F_44 ( V_2 -> V_54 , V_122 ) )
goto V_58;
V_109 = F_62 ( V_11 , V_2 ,
V_2 -> V_51 . V_124 , V_122 ) ;
if ( ! V_109 )
goto V_58;
F_10 ( V_13 , V_61 , F_34 ( V_109 ) ) ;
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
union V_126 V_127 ;
struct V_108 * V_128 ;
T_9 * V_129 ;
unsigned long V_130 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_17 ) +
sizeof( T_9 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_129 = ( T_9 * ) V_2 -> V_54 -> V_55 ;
if ( F_2 ( V_129 -> V_56 . V_6 ) !=
sizeof( T_9 ) ) {
return V_131 ;
}
V_127 = V_129 -> V_132 ;
V_128 = F_64 ( V_11 , & V_127 ) ;
if ( F_3 ( ! V_128 ) ) {
if ( V_127 . V_133 . V_134 == V_135 ) {
F_65 ( L_1 ,
V_136 ,
V_11 ,
& V_127 . V_137 . V_138 ) ;
} else {
F_65 ( L_2 ,
V_136 ,
V_11 ,
& V_127 . V_139 . V_140 . V_141 ) ;
}
return V_131 ;
}
if ( V_129 -> V_142 != V_128 -> V_142 )
return V_131 ;
V_130 = V_128 -> V_143 + V_128 -> V_144 ;
if ( F_66 ( V_129 -> V_145 , V_146 ) ||
F_66 ( V_146 , V_129 -> V_145 + V_130 ) ) {
F_67 ( L_3
L_4 ,
V_136 , V_128 ) ;
return V_131 ;
}
F_10 ( V_13 , V_147 , F_57 ( V_128 ) ) ;
return V_49 ;
}
static int F_68 ( struct V_7 * V_7 , union V_126 * V_148 ,
struct V_1 * V_149 ,
T_4 * V_13 )
{
int V_36 ;
struct V_33 * V_150 ;
union V_151 * V_152 ;
struct V_153 * V_154 ;
struct V_8 * V_9 ;
char V_155 [ sizeof( struct V_153 ) + sizeof( union V_151 ) ] ;
struct V_156 * V_157 = F_69 ( V_148 -> V_139 . V_158 ) ;
V_154 = (struct V_153 * ) V_155 ;
V_152 = (union V_151 * ) V_154 -> V_159 ;
V_36 = V_157 -> V_160 ( V_148 , V_152 ) ;
V_36 += sizeof( V_161 ) ;
V_154 -> V_162 = V_163 ;
V_154 -> V_6 = F_70 ( V_36 ) ;
V_9 = F_18 ( V_7 -> V_37 . V_38 ) -> V_9 ;
V_150 = F_22 ( V_7 , V_9 , NULL , V_149 , V_154 , V_36 ) ;
if ( ! V_150 )
goto V_164;
F_10 ( V_13 , V_47 , F_24 ( V_150 ) ) ;
F_14 ( V_7 , V_48 ) ;
F_10 ( V_13 , V_165 , F_16 () ) ;
V_164:
return 0 ;
}
static bool F_71 ( const struct V_166 * V_167 ,
union V_126 * V_168 )
{
struct V_108 * V_169 ;
F_72 (addr, list, transports) {
if ( F_73 ( V_168 , & V_169 -> V_168 ) )
return true ;
}
return false ;
}
static int F_74 ( const struct V_10 * V_31 ,
const struct V_10 * V_11 ,
struct V_1 * V_149 ,
T_4 * V_13 )
{
struct V_7 * V_7 = F_75 ( V_31 -> V_43 . V_44 ) ;
struct V_108 * V_170 ;
int V_93 = 1 ;
F_72 (new_addr, &new_asoc->peer.transport_addr_list,
transports) {
if ( ! F_71 ( & V_11 -> V_99 . V_171 ,
& V_170 -> V_168 ) ) {
F_68 ( V_7 , & V_170 -> V_168 , V_149 ,
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
switch ( V_11 -> V_172 ) {
case V_173 :
V_31 -> V_89 . V_174 = V_11 -> V_89 . V_174 ;
V_31 -> V_89 . V_175 = V_11 -> V_89 . V_174 ;
V_31 -> V_89 . V_176 = 0 ;
break;
case V_75 :
V_31 -> V_89 . V_174 = V_11 -> V_89 . V_174 ;
V_31 -> V_89 . V_175 = V_11 -> V_89 . V_174 ;
V_31 -> V_89 . V_176 = V_11 -> V_89 . V_177 ;
break;
default:
V_31 -> V_89 . V_175 = V_11 -> V_89 . V_174 ;
V_31 -> V_89 . V_176 = V_11 -> V_89 . V_177 ;
break;
}
V_31 -> V_178 = V_11 -> V_178 ;
V_31 -> V_89 . V_96 = V_11 -> V_89 . V_96 ;
V_31 -> V_89 . V_97 = V_11 -> V_89 . V_97 ;
V_31 -> V_89 . V_179 = V_11 -> V_89 . V_179 ;
}
static char F_77 ( struct V_10 * V_31 ,
const struct V_10 * V_11 )
{
if ( ( V_11 -> V_89 . V_174 != V_31 -> V_89 . V_174 ) &&
( V_11 -> V_89 . V_177 != V_31 -> V_89 . V_177 ) &&
( V_11 -> V_89 . V_174 == V_31 -> V_89 . V_175 ) &&
( V_11 -> V_89 . V_177 == V_31 -> V_89 . V_176 ) )
return 'A' ;
if ( ( V_11 -> V_89 . V_174 == V_31 -> V_89 . V_174 ) &&
( ( V_11 -> V_89 . V_177 != V_31 -> V_89 . V_177 ) ||
( 0 == V_11 -> V_89 . V_177 ) ) ) {
return 'B' ;
}
if ( ( V_11 -> V_89 . V_174 == V_31 -> V_89 . V_174 ) &&
( V_11 -> V_89 . V_177 == V_31 -> V_89 . V_177 ) )
return 'D' ;
if ( ( V_11 -> V_89 . V_174 != V_31 -> V_89 . V_174 ) &&
( V_11 -> V_89 . V_177 == V_31 -> V_89 . V_177 ) &&
( 0 == V_31 -> V_89 . V_175 ) &&
( 0 == V_31 -> V_89 . V_176 ) )
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
T_2 V_180 ;
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
if ( ! F_21 ( V_7 , V_11 , V_2 -> V_5 -> type ,
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
V_180 = V_49 ;
} else {
V_180 = V_50 ;
}
goto V_181;
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
if ( ! F_79 ( V_11 , V_182 ) ) {
if ( ! F_74 ( V_31 , V_11 , V_2 ,
V_13 ) ) {
V_180 = V_49 ;
goto V_183;
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
V_180 = V_49 ;
return V_180 ;
V_58:
V_180 = V_50 ;
V_183:
if ( V_31 )
F_35 ( V_31 ) ;
V_181:
if ( V_32 )
F_23 ( V_32 ) ;
return V_180 ;
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
struct V_1 * V_184 ;
T_2 V_185 ;
V_78 = & V_2 -> V_51 . V_84 -> V_89 . V_78 [ 0 ] ;
if ( ! F_30 ( V_31 , V_2 , F_29 ( V_2 ) , V_78 ,
V_19 ) )
goto V_58;
if ( ! F_74 ( V_31 , V_11 , V_2 , V_13 ) ) {
return V_49 ;
}
if ( F_79 ( V_11 , V_186 ) ) {
V_185 = F_86 ( V_7 , V_9 , V_11 ,
F_87 ( V_2 -> V_5 -> type ) ,
V_2 , V_13 ) ;
if ( V_50 == V_185 )
goto V_58;
V_184 = F_88 ( V_11 , V_2 ,
V_187 ,
NULL , 0 , 0 ) ;
if ( V_184 )
F_10 ( V_13 , V_61 ,
F_34 ( V_184 ) ) ;
return V_49 ;
}
F_10 ( V_13 , V_188 , F_16 () ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_189 ) ) ;
F_10 ( V_13 , V_190 , F_16 () ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_191 ) ) ;
F_10 ( V_13 , V_192 , F_16 () ) ;
V_30 = F_51 ( V_31 , V_2 ) ;
if ( ! V_30 )
goto V_58;
V_15 = F_9 ( V_11 , 0 , V_193 , 0 ,
V_31 -> V_89 . V_96 ,
V_31 -> V_89 . V_97 ,
NULL , V_19 ) ;
if ( ! V_15 )
goto V_98;
F_10 ( V_13 , V_194 , F_33 ( V_31 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_30 ) ) ;
F_10 ( V_13 , V_20 , F_11 ( V_15 ) ) ;
return V_49 ;
V_98:
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
F_10 ( V_13 , V_194 , F_33 ( V_31 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_102 ) ) ;
F_14 ( V_7 , V_27 ) ;
F_10 ( V_13 , V_104 , F_16 () ) ;
V_30 = F_51 ( V_31 , V_2 ) ;
if ( ! V_30 )
goto V_58;
F_10 ( V_13 , V_61 , F_34 ( V_30 ) ) ;
F_10 ( V_13 , V_195 , F_90 ( V_95 ) ) ;
if ( V_11 -> V_99 . V_100 )
F_10 ( V_13 , V_196 , F_16 () ) ;
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
return V_131 ;
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
if ( V_11 -> V_172 < V_102 ) {
F_10 ( V_13 , V_21 ,
F_12 ( V_74 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_102 ) ) ;
F_14 ( V_7 , V_27 ) ;
F_10 ( V_13 , V_104 ,
F_16 () ) ;
V_15 = F_9 ( V_11 , 0 ,
V_95 , 0 ,
V_11 -> V_89 . V_96 ,
V_11 -> V_89 . V_97 ,
NULL , V_19 ) ;
if ( ! V_15 )
goto V_58;
if ( V_11 -> V_99 . V_100 ) {
V_79 = F_52 ( V_11 ,
V_19 ) ;
if ( ! V_79 )
goto V_58;
}
}
V_30 = F_51 ( V_31 , V_2 ) ;
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
F_53 ( V_79 ) ;
if ( V_15 )
F_53 ( V_15 ) ;
return V_50 ;
}
T_2 F_93 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
T_2 V_180 ;
struct V_1 * V_2 = V_12 ;
struct V_10 * V_31 ;
int error = 0 ;
char V_197 ;
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
V_197 = F_77 ( V_31 , V_11 ) ;
switch ( V_197 ) {
case 'A' :
V_180 = F_85 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
V_31 ) ;
break;
case 'B' :
V_180 = F_89 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
V_31 ) ;
break;
case 'C' :
V_180 = F_91 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
V_31 ) ;
break;
case 'D' :
V_180 = F_92 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
V_31 ) ;
break;
default:
V_180 = F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
break;
}
F_10 ( V_13 , V_60 , F_33 ( V_31 ) ) ;
F_10 ( V_13 , V_28 , F_16 () ) ;
F_10 ( V_13 , V_198 ,
F_33 ( (struct V_10 * ) V_11 ) ) ;
return V_180 ;
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
if ( ! F_1 ( V_2 , sizeof( V_199 ) ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( V_200 ==
F_95 ( & V_11 -> V_43 . V_201 , & V_2 -> V_202 ) )
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
if ( ! F_1 ( V_2 , sizeof( V_199 ) ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( V_200 ==
F_95 ( & V_11 -> V_43 . V_201 , & V_2 -> V_202 ) )
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
V_161 * V_184 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_203 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
F_100 (err, chunk->chunk_hdr) {
if ( V_204 == V_184 -> V_162 )
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
T_10 V_205 ;
T_11 V_206 ;
V_161 * V_184 ;
struct V_1 * V_109 ;
struct V_207 * V_208 ;
int V_209 = V_11 -> V_210 + 1 ;
if ( V_209 > V_11 -> V_211 ) {
F_10 ( V_13 , V_113 ,
F_59 ( V_114 ) ) ;
F_10 ( V_13 , V_212 ,
F_60 ( V_204 ) ) ;
return V_29 ;
}
V_184 = ( V_161 * ) ( V_2 -> V_54 -> V_55 ) ;
V_205 = F_102 ( * ( V_213 * ) ( ( V_214 * ) V_184 + sizeof( V_161 ) ) ) ;
V_205 = ( V_205 * 2 ) / 1000 ;
V_206 . V_56 . type = V_215 ;
V_206 . V_56 . V_6 = F_70 ( sizeof( V_206 ) ) ;
V_206 . V_216 = F_103 ( V_205 ) ;
V_208 = (struct V_207 * ) & V_11 -> V_43 . V_201 ;
V_109 = F_104 ( V_11 , V_208 , V_19 , sizeof( V_206 ) ) ;
if ( ! V_109 )
goto V_58;
F_32 ( V_109 , sizeof( V_206 ) , & V_206 ) ;
F_10 ( V_13 , V_217 , F_16 () ) ;
F_10 ( V_13 , V_188 , F_16 () ) ;
F_10 ( V_13 , V_218 , F_16 () ) ;
F_10 ( V_13 , V_219 , F_16 () ) ;
F_10 ( V_13 , V_220 ,
F_57 ( V_11 -> V_99 . V_221 ) ) ;
F_10 ( V_13 , V_222 , F_16 () ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_74 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_173 ) ) ;
F_10 ( V_13 , V_73 ,
F_12 ( V_72 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_109 ) ) ;
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
if ( ! F_1 ( V_2 , sizeof( V_199 ) ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( V_200 ==
F_95 ( & V_11 -> V_43 . V_201 , & V_2 -> V_202 ) )
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
T_12 error = V_116 ;
V_36 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_36 >= sizeof( struct V_223 ) + sizeof( struct V_153 ) ) {
V_161 * V_184 ;
F_100 ( V_184 , V_2 -> V_5 ) ;
if ( ( void * ) V_184 != ( void * ) V_2 -> V_224 )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
error = ( ( V_161 * ) V_2 -> V_54 -> V_55 ) -> V_162 ;
}
F_10 ( V_13 , V_113 , F_59 ( V_225 ) ) ;
F_10 ( V_13 , V_115 , F_60 ( error ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_226 ;
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
T_12 error = V_116 ;
if ( ! F_5 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_199 ) ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
V_36 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_36 >= sizeof( struct V_223 ) + sizeof( struct V_153 ) )
error = ( ( V_161 * ) V_2 -> V_54 -> V_55 ) -> V_162 ;
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
return F_39 ( V_7 , V_13 , V_116 ,
V_227 , V_11 ,
(struct V_108 * ) V_12 ) ;
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
T_12 error , int V_228 ,
const struct V_10 * V_11 ,
struct V_108 * V_69 )
{
F_67 ( L_5 ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_25 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_72 ) ) ;
F_10 ( V_13 , V_113 , F_59 ( V_228 ) ) ;
F_10 ( V_13 , V_212 ,
F_60 ( error ) ) ;
return V_226 ;
}
T_2 F_109 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
T_13 * V_229 ;
T_2 V_185 ;
struct V_14 * V_15 ;
T_14 V_230 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 ,
sizeof( struct V_231 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_229 = ( T_13 * ) V_2 -> V_54 -> V_55 ;
F_25 ( V_2 -> V_54 , sizeof( T_13 ) ) ;
V_2 -> V_51 . V_232 = V_229 ;
V_230 = F_102 ( V_229 -> V_233 ) ;
if ( F_110 ( V_230 , V_11 -> V_234 ) ) {
F_67 ( L_6 , V_230 ) ;
F_67 ( L_7 , V_11 -> V_234 ) ;
return V_131 ;
}
if ( ! F_110 ( V_230 , V_11 -> V_235 ) )
return F_111 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
V_15 = F_112 ( V_11 , 0 , V_19 ) ;
if ( ! V_15 ) {
V_185 = V_50 ;
goto V_164;
}
F_10 ( V_13 , V_20 , F_11 ( V_15 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_236 ) ) ;
V_185 = V_49 ;
if ( F_113 ( & V_11 -> V_237 ) ) {
V_185 = F_114 ( V_7 , V_9 , V_11 , type ,
V_12 , V_13 ) ;
}
if ( V_50 == V_185 )
goto V_164;
F_10 ( V_13 , V_238 ,
F_115 ( V_2 -> V_51 . V_232 -> V_233 ) ) ;
V_164:
return V_185 ;
}
T_2 F_116 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
T_13 * V_229 ;
T_14 V_230 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 ,
sizeof( struct V_231 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_229 = ( T_13 * ) V_2 -> V_54 -> V_55 ;
V_230 = F_102 ( V_229 -> V_233 ) ;
if ( F_110 ( V_230 , V_11 -> V_234 ) ) {
F_67 ( L_6 , V_230 ) ;
F_67 ( L_7 , V_11 -> V_234 ) ;
return V_131 ;
}
if ( ! F_110 ( V_230 , V_11 -> V_235 ) )
return F_111 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
F_10 ( V_13 , V_238 ,
F_115 ( V_229 -> V_233 ) ) ;
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
struct V_1 * V_109 ;
if ( ! F_1 ( V_2 , sizeof( V_17 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_109 = F_117 ( V_11 , V_2 ) ;
if ( NULL == V_109 )
goto V_58;
F_10 ( V_13 , V_239 , F_34 ( V_109 ) ) ;
F_10 ( V_13 , V_240 ,
F_12 ( V_22 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_109 ) ) ;
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
T_15 * V_241 ;
struct V_1 * V_2 = V_12 ;
T_16 V_242 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_243 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_241 = ( T_15 * ) V_2 -> V_54 -> V_55 ;
F_25 ( V_2 -> V_54 , sizeof( T_15 ) ) ;
V_242 = F_102 ( V_241 -> V_242 ) ;
if ( F_119 ( V_11 -> V_244 , V_242 ) ) {
F_10 ( V_13 ,
V_245 ,
F_120 ( V_242 ) ) ;
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
T_17 * V_246 ;
struct V_1 * V_2 = V_12 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_243 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_246 = ( T_17 * ) V_2 -> V_54 -> V_55 ;
F_25 ( V_2 -> V_54 , sizeof( T_17 ) ) ;
F_10 ( V_13 , V_247 ,
F_120 ( F_102 ( V_246 -> V_242 ) ) ) ;
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
T_18 V_248 = F_123 () ;
int error ;
if ( ! F_37 ( V_2 , V_11 ) ) {
F_10 ( V_13 , V_249 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! F_1 ( V_2 , sizeof( V_250 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
error = F_124 ( V_11 , V_2 , V_13 ) ;
switch ( error ) {
case V_94 :
break;
case V_251 :
case V_252 :
F_14 ( V_7 , V_253 ) ;
goto V_254;
case V_255 :
case V_256 :
F_14 ( V_7 , V_253 ) ;
goto V_257;
case V_258 :
goto V_259;
case V_260 :
return F_125 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
( V_214 * ) V_2 -> V_51 . V_261 , sizeof( V_262 ) ) ;
default:
F_126 () ;
}
if ( V_2 -> V_5 -> V_263 & V_264 )
V_248 = F_127 () ;
if ( V_11 -> V_105 ) {
F_10 ( V_13 , V_240 ,
F_12 ( V_106 ) ) ;
}
if ( V_2 -> V_265 )
F_10 ( V_13 , V_266 , V_248 ) ;
return V_49 ;
V_257:
if ( V_2 -> V_265 )
F_10 ( V_13 , V_266 , F_127 () ) ;
return V_131 ;
V_254:
if ( V_2 -> V_265 )
F_10 ( V_13 , V_266 , V_248 ) ;
return V_131 ;
V_259:
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
F_10 ( V_13 , V_249 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! F_1 ( V_2 , sizeof( V_250 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
error = F_124 ( V_11 , V_2 , V_13 ) ;
switch ( error ) {
case V_94 :
case V_251 :
case V_255 :
case V_256 :
case V_252 :
break;
case V_258 :
goto V_259;
case V_260 :
return F_125 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
( V_214 * ) V_2 -> V_51 . V_261 , sizeof( V_262 ) ) ;
default:
F_126 () ;
}
if ( V_2 -> V_265 ) {
F_10 ( V_13 , V_267 , F_16 () ) ;
F_10 ( V_13 , V_266 , F_127 () ) ;
F_10 ( V_13 , V_240 ,
F_12 ( V_22 ) ) ;
}
V_259:
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
T_19 * V_268 ;
T_14 V_230 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_269 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_268 = F_130 ( V_2 ) ;
if ( ! V_268 )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
V_2 -> V_51 . V_270 = V_268 ;
V_230 = F_102 ( V_268 -> V_233 ) ;
if ( F_110 ( V_230 , V_11 -> V_234 ) ) {
F_67 ( L_6 , V_230 ) ;
F_67 ( L_7 , V_11 -> V_234 ) ;
return V_131 ;
}
if ( ! F_110 ( V_230 , V_11 -> V_235 ) )
return F_111 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
F_10 ( V_13 , V_271 , F_34 ( V_2 ) ) ;
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
V_161 * V_184 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_203 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
F_100 ( V_184 , V_2 -> V_5 ) ;
if ( ( void * ) V_184 != ( void * ) V_2 -> V_224 )
return F_137 ( V_7 , V_9 , V_11 , type , V_12 ,
( void * ) V_184 , V_13 ) ;
F_10 ( V_13 , V_272 ,
F_34 ( V_2 ) ) ;
return V_49 ;
}
T_2 F_138 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
struct V_1 * V_109 ;
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
V_109 = F_139 ( V_11 , V_2 ) ;
if ( ! V_109 )
goto V_273;
F_10 ( V_13 , V_20 , F_11 ( V_15 ) ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_22 ) ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_23 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_25 ) ) ;
F_14 ( V_7 , V_26 ) ;
F_15 ( V_7 , V_27 ) ;
F_10 ( V_13 , V_61 , F_34 ( V_109 ) ) ;
F_10 ( V_13 , V_28 , F_16 () ) ;
return V_29 ;
V_273:
F_53 ( V_15 ) ;
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
struct V_274 * V_54 = V_2 -> V_54 ;
V_17 * V_275 ;
V_161 * V_184 ;
V_46 * V_276 ;
int V_277 = 0 ;
int V_278 = 0 ;
F_14 ( V_7 , V_39 ) ;
V_275 = ( V_17 * ) V_2 -> V_5 ;
do {
if ( F_2 ( V_275 -> V_6 ) < sizeof( V_17 ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
if ( V_279 == V_275 -> type )
V_277 = 1 ;
if ( V_66 == V_275 -> type )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( V_280 == V_275 -> type )
V_278 = 1 ;
if ( V_281 == V_275 -> type ) {
F_100 (err, ch) {
if ( V_204 == V_184 -> V_162 ) {
V_278 = 1 ;
break;
}
}
}
V_276 = ( ( V_46 * ) V_275 ) + F_140 ( F_2 ( V_275 -> V_6 ) ) ;
if ( V_276 > F_141 ( V_54 ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_275 = ( V_17 * ) V_276 ;
} while ( V_276 < F_141 ( V_54 ) );
if ( V_277 )
return F_142 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
else if ( V_278 )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
else
return F_19 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
static T_2 F_142 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_33 * V_34 = NULL ;
struct V_1 * V_2 = V_12 ;
struct V_1 * V_282 ;
V_34 = F_131 ( V_7 , V_11 , V_2 ) ;
if ( V_34 ) {
V_282 = F_139 ( V_11 , V_2 ) ;
if ( ! V_282 ) {
F_133 ( V_34 ) ;
return V_50 ;
}
if ( F_134 ( V_282 ) )
V_34 -> V_41 = F_102 ( V_2 -> V_40 -> V_41 ) ;
V_282 -> V_54 -> V_44 = V_9 -> V_43 . V_44 ;
F_135 ( V_34 , V_282 ) ;
F_10 ( V_13 , V_47 ,
F_24 ( V_34 ) ) ;
F_14 ( V_7 , V_48 ) ;
if ( ! F_1 ( V_2 , sizeof( V_17 ) ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
return V_50 ;
}
T_2 F_143 ( struct V_7 * V_7 ,
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
return F_142 ( V_7 , V_9 , NULL , type , V_12 , V_13 ) ;
}
T_2 F_144 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type , void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
struct V_1 * V_283 = NULL ;
struct V_284 * V_285 = NULL ;
T_20 * V_286 ;
union V_151 * V_287 ;
T_14 V_288 ;
int V_6 ;
if ( ! F_37 ( V_2 , V_11 ) ) {
F_10 ( V_13 , V_249 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! V_7 -> V_37 . V_289 && ! V_2 -> V_92 )
return F_84 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_290 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_286 = ( T_20 * ) V_2 -> V_54 -> V_55 ;
V_288 = F_102 ( V_286 -> V_288 ) ;
V_287 = (union V_151 * ) V_286 -> V_291 ;
V_6 = F_2 ( V_287 -> V_292 . V_6 ) ;
if ( V_6 < sizeof( V_293 ) )
return F_137 ( V_7 , V_9 , V_11 , type , V_12 ,
( void * ) V_287 , V_13 ) ;
if ( ! F_145 ( V_11 ,
( V_293 * ) ( ( void * ) V_287 + V_6 ) ,
( void * ) V_2 -> V_224 ,
& V_285 ) )
return F_137 ( V_7 , V_9 , V_11 , type , V_12 ,
( void * ) V_285 , V_13 ) ;
if ( V_288 == V_11 -> V_99 . V_294 + 1 ) {
if ( ! V_2 -> V_295 )
F_146 ( V_11 ) ;
V_283 = F_147 ( (struct V_10 * )
V_11 , V_2 ) ;
if ( ! V_283 )
return V_50 ;
} else if ( V_288 < V_11 -> V_99 . V_294 + 1 ) {
V_283 = F_148 ( V_11 , V_286 -> V_288 ) ;
if ( ! V_283 )
return V_131 ;
V_283 -> V_69 = NULL ;
} else {
return V_131 ;
}
V_283 -> V_202 = V_2 -> V_296 ;
F_10 ( V_13 , V_61 , F_34 ( V_283 ) ) ;
if ( V_11 -> V_297 ) {
F_55 ( V_9 , V_11 , type , V_11 -> V_297 ,
V_13 ) ;
( (struct V_10 * ) V_11 ) -> V_297 = NULL ;
}
return V_49 ;
}
T_2 F_149 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type , void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_283 = V_12 ;
struct V_1 * V_298 = V_11 -> V_299 ;
struct V_1 * abort ;
struct V_284 * V_285 = NULL ;
T_20 * V_300 ;
T_14 V_301 , V_302 ;
if ( ! F_37 ( V_283 , V_11 ) ) {
F_10 ( V_13 , V_249 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! V_7 -> V_37 . V_289 && ! V_283 -> V_92 )
return F_84 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_283 , sizeof( V_290 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_300 = ( T_20 * ) V_283 -> V_54 -> V_55 ;
V_302 = F_102 ( V_300 -> V_288 ) ;
if ( ! F_145 ( V_11 ,
( V_293 * ) V_300 -> V_291 ,
( void * ) V_283 -> V_224 ,
& V_285 ) )
return F_137 ( V_7 , V_9 , V_11 , type , V_12 ,
( void * ) V_285 , V_13 ) ;
if ( V_298 ) {
V_300 = ( T_20 * ) V_298 -> V_51 . V_300 ;
V_301 = F_102 ( V_300 -> V_288 ) ;
} else {
V_301 = V_11 -> V_294 - 1 ;
}
if ( F_150 ( V_302 , V_301 + 1 ) &&
! ( V_11 -> V_299 ) ) {
abort = F_132 ( V_11 , V_283 ,
sizeof( V_161 ) ) ;
if ( abort ) {
F_151 ( abort , V_303 , 0 ) ;
F_10 ( V_13 , V_61 ,
F_34 ( abort ) ) ;
}
F_10 ( V_13 , V_21 ,
F_12 ( V_191 ) ) ;
F_10 ( V_13 , V_165 , F_16 () ) ;
F_10 ( V_13 , V_113 ,
F_59 ( V_304 ) ) ;
F_10 ( V_13 , V_115 ,
F_60 ( V_303 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_226 ;
}
if ( ( V_302 == V_301 ) && V_11 -> V_299 ) {
F_10 ( V_13 , V_21 ,
F_12 ( V_191 ) ) ;
if ( ! F_152 ( (struct V_10 * ) V_11 ,
V_283 ) ) {
F_10 ( V_13 , V_305 ,
F_16 () ) ;
return V_49 ;
}
abort = F_132 ( V_11 , V_283 ,
sizeof( V_161 ) ) ;
if ( abort ) {
F_151 ( abort , V_306 , 0 ) ;
F_10 ( V_13 , V_61 ,
F_34 ( abort ) ) ;
}
F_10 ( V_13 , V_165 , F_16 () ) ;
F_10 ( V_13 , V_113 ,
F_59 ( V_304 ) ) ;
F_10 ( V_13 , V_115 ,
F_60 ( V_303 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_226 ;
}
return V_131 ;
}
T_2 F_153 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
struct V_307 * V_308 ;
struct V_309 * V_310 ;
T_1 V_36 ;
T_14 V_311 ;
if ( ! F_37 ( V_2 , V_11 ) ) {
F_10 ( V_13 , V_249 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_312 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_308 = (struct V_307 * ) V_2 -> V_54 -> V_55 ;
V_2 -> V_51 . V_308 = V_308 ;
V_36 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_36 -= sizeof( struct V_223 ) ;
F_25 ( V_2 -> V_54 , V_36 ) ;
V_311 = F_102 ( V_308 -> V_313 ) ;
F_67 ( L_8 , V_136 , V_311 ) ;
if ( F_154 ( & V_11 -> V_99 . V_314 , V_311 ) < 0 )
goto V_254;
F_155 (skip, chunk) {
if ( F_2 ( V_310 -> V_315 ) >= V_11 -> V_89 . V_97 )
goto V_254;
}
F_10 ( V_13 , V_316 , F_120 ( V_311 ) ) ;
if ( V_36 > sizeof( struct V_307 ) )
F_10 ( V_13 , V_317 ,
F_34 ( V_2 ) ) ;
if ( V_11 -> V_105 ) {
F_10 ( V_13 , V_240 ,
F_12 ( V_106 ) ) ;
}
F_10 ( V_13 , V_266 , F_123 () ) ;
return V_49 ;
V_254:
return V_131 ;
}
T_2 F_156 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
struct V_307 * V_308 ;
struct V_309 * V_310 ;
T_1 V_36 ;
T_14 V_311 ;
if ( ! F_37 ( V_2 , V_11 ) ) {
F_10 ( V_13 , V_249 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_312 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_308 = (struct V_307 * ) V_2 -> V_54 -> V_55 ;
V_2 -> V_51 . V_308 = V_308 ;
V_36 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_36 -= sizeof( struct V_223 ) ;
F_25 ( V_2 -> V_54 , V_36 ) ;
V_311 = F_102 ( V_308 -> V_313 ) ;
F_67 ( L_8 , V_136 , V_311 ) ;
if ( F_154 ( & V_11 -> V_99 . V_314 , V_311 ) < 0 )
goto V_318;
F_155 (skip, chunk) {
if ( F_2 ( V_310 -> V_315 ) >= V_11 -> V_89 . V_97 )
goto V_318;
}
F_10 ( V_13 , V_316 , F_120 ( V_311 ) ) ;
if ( V_36 > sizeof( struct V_307 ) )
F_10 ( V_13 , V_317 ,
F_34 ( V_2 ) ) ;
V_318:
F_10 ( V_13 , V_267 , F_16 () ) ;
F_10 ( V_13 , V_266 , F_127 () ) ;
F_10 ( V_13 , V_240 ,
F_12 ( V_22 ) ) ;
return V_49 ;
}
static T_7 F_49 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
struct V_1 * V_2 )
{
struct V_319 * V_320 ;
struct V_321 * V_322 ;
unsigned int V_323 ;
T_1 V_324 ;
V_46 * V_325 ;
V_46 * V_326 ;
V_320 = (struct V_319 * ) V_2 -> V_54 -> V_55 ;
V_2 -> V_51 . V_320 = V_320 ;
F_25 ( V_2 -> V_54 , sizeof( struct V_319 ) ) ;
if ( ! F_157 ( V_11 , V_320 -> V_327 ) )
return V_328 ;
V_324 = F_2 ( V_320 -> V_329 ) ;
if ( V_324 != V_11 -> V_330 && ! F_158 ( V_11 , V_324 ) )
return V_331 ;
V_323 = F_2 ( V_2 -> V_5 -> V_6 ) - sizeof( V_332 ) ;
V_322 = F_159 ( F_2 ( V_320 -> V_327 ) ) ;
if ( V_323 != V_322 -> V_333 )
return V_260 ;
V_326 = V_320 -> V_322 ;
F_25 ( V_2 -> V_54 , V_323 ) ;
V_325 = F_160 ( V_326 , V_323 , V_19 ) ;
if ( ! V_325 )
goto V_58;
memset ( V_326 , 0 , V_323 ) ;
F_161 ( V_11 , V_2 -> V_54 ,
(struct V_334 * ) V_2 -> V_5 ,
V_19 ) ;
if ( memcmp ( V_325 , V_326 , V_323 ) ) {
F_162 ( V_325 ) ;
return V_88 ;
}
F_162 ( V_325 ) ;
V_2 -> V_92 = 1 ;
return V_94 ;
V_58:
return V_86 ;
}
T_2 F_163 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_319 * V_320 ;
struct V_1 * V_2 = V_12 ;
struct V_1 * V_32 ;
T_7 error ;
if ( ! V_11 -> V_99 . V_335 )
return F_164 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_37 ( V_2 , V_11 ) ) {
F_10 ( V_13 , V_249 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_334 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_320 = (struct V_319 * ) V_2 -> V_54 -> V_55 ;
error = F_49 ( V_7 , V_9 , V_11 , type , V_2 ) ;
switch ( error ) {
case V_328 :
V_32 = F_88 ( V_11 , V_2 ,
V_336 ,
& V_320 -> V_327 ,
sizeof( T_1 ) , 0 ) ;
if ( V_32 ) {
F_10 ( V_13 , V_61 ,
F_34 ( V_32 ) ) ;
}
case V_331 :
case V_88 :
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
case V_260 :
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
case V_86 :
return V_50 ;
default:
break;
}
if ( V_11 -> V_330 != F_2 ( V_320 -> V_329 ) ) {
struct V_14 * V_15 ;
V_15 = F_165 ( V_11 , F_2 ( V_320 -> V_329 ) ,
V_337 , V_19 ) ;
if ( ! V_15 )
return - V_338 ;
F_10 ( V_13 , V_20 ,
F_11 ( V_15 ) ) ;
}
return V_49 ;
}
T_2 F_164 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_339 = V_12 ;
struct V_1 * V_32 ;
V_17 * V_286 ;
F_67 ( L_9 , type . V_2 ) ;
if ( ! F_37 ( V_339 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_339 , sizeof( V_17 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
switch ( type . V_2 & V_340 ) {
case V_341 :
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
break;
case V_342 :
V_286 = V_339 -> V_5 ;
V_32 = F_88 ( V_11 , V_339 ,
V_343 , V_286 ,
F_140 ( F_2 ( V_286 -> V_6 ) ) ,
0 ) ;
if ( V_32 ) {
F_10 ( V_13 , V_61 ,
F_34 ( V_32 ) ) ;
}
F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
return V_49 ;
break;
case V_344 :
return V_131 ;
break;
case V_345 :
V_286 = V_339 -> V_5 ;
V_32 = F_88 ( V_11 , V_339 ,
V_343 , V_286 ,
F_140 ( F_2 ( V_286 -> V_6 ) ) ,
0 ) ;
if ( V_32 ) {
F_10 ( V_13 , V_61 ,
F_34 ( V_32 ) ) ;
}
return V_49 ;
break;
default:
break;
}
return V_131 ;
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
F_67 ( L_10 , type . V_2 ) ;
return V_131 ;
}
T_2 F_6 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_14 ( V_7 , V_346 ) ;
F_10 ( V_13 , V_165 , F_16 () ) ;
return V_49 ;
}
T_2 F_166 ( struct V_7 * V_7 ,
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
const T_8 V_122 )
{
struct V_33 * V_34 = NULL ;
struct V_1 * V_2 = V_12 ;
struct V_1 * abort = NULL ;
if ( F_38 ( V_66 , V_11 ) )
goto V_349;
abort = F_167 ( V_11 , V_2 , V_348 , V_122 ) ;
if ( ! abort )
goto V_58;
if ( V_11 ) {
if ( V_2 -> V_5 -> type == V_350 &&
! V_11 -> V_99 . V_351 . V_352 ) {
V_63 * V_353 ;
V_353 = ( V_63 * ) V_2 -> V_5 ;
if ( ! F_1 ( V_2 ,
sizeof( V_63 ) ) )
abort -> V_5 -> V_263 |= V_354 ;
else {
unsigned int V_355 ;
V_355 = F_102 ( V_353 -> V_52 . V_352 ) ;
F_10 ( V_13 , V_356 ,
F_120 ( V_355 ) ) ;
}
}
F_10 ( V_13 , V_61 , F_34 ( abort ) ) ;
F_14 ( V_7 , V_48 ) ;
if ( V_11 -> V_172 <= V_75 ) {
F_10 ( V_13 , V_21 ,
F_12 ( V_72 ) ) ;
F_10 ( V_13 , V_113 ,
F_59 ( V_68 ) ) ;
F_10 ( V_13 , V_212 ,
F_60 ( V_357 ) ) ;
} else {
F_10 ( V_13 , V_113 ,
F_59 ( V_304 ) ) ;
F_10 ( V_13 , V_115 ,
F_60 ( V_357 ) ) ;
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
return V_226 ;
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
static const char V_359 [] = L_11 ;
return F_125 ( V_7 , V_9 , V_11 , V_12 , V_13 , V_359 ,
sizeof( V_359 ) ) ;
}
static T_2 F_137 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 , void * V_360 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
struct V_284 * V_361 = V_360 ;
struct V_1 * abort = NULL ;
if ( F_38 ( V_66 , V_11 ) )
goto V_349;
abort = F_168 ( V_11 , V_2 , V_361 ) ;
if ( ! abort )
goto V_58;
F_10 ( V_13 , V_61 , F_34 ( abort ) ) ;
F_14 ( V_7 , V_48 ) ;
F_10 ( V_13 , V_113 ,
F_59 ( V_304 ) ) ;
F_10 ( V_13 , V_115 ,
F_60 ( V_357 ) ) ;
F_15 ( V_7 , V_27 ) ;
F_14 ( V_7 , V_67 ) ;
V_349:
F_6 ( V_7 , V_9 , V_11 , F_87 ( 0 ) , V_12 , V_13 ) ;
return V_226 ;
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
static const char V_359 [] = L_12 ;
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
static const char V_359 [] = L_13 ;
if ( ! V_11 )
return F_166 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
return F_125 ( V_7 , V_9 , V_11 , V_12 , V_13 , V_359 ,
sizeof( V_359 ) ) ;
}
T_2 F_169 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_30 ;
struct V_10 * V_362 ;
F_10 ( V_13 , V_24 ,
F_13 ( V_173 ) ) ;
V_30 = F_104 ( V_11 , & V_11 -> V_43 . V_201 , V_19 , 0 ) ;
if ( ! V_30 )
goto V_58;
V_362 = (struct V_10 * ) V_11 ;
F_10 ( V_13 , V_60 , F_33 ( V_362 ) ) ;
F_10 ( V_13 , V_363 ,
F_34 ( V_30 ) ) ;
F_10 ( V_13 , V_73 ,
F_12 ( V_72 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_30 ) ) ;
return V_49 ;
V_58:
return V_50 ;
}
T_2 F_170 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_364 * V_365 = V_12 ;
F_10 ( V_13 , V_366 , F_171 ( V_365 ) ) ;
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
int V_185 ;
F_10 ( V_13 , V_24 ,
F_13 ( V_367 ) ) ;
V_185 = V_49 ;
if ( F_113 ( & V_11 -> V_237 ) ) {
V_185 = F_173 ( V_7 , V_9 , V_11 , type ,
V_12 , V_13 ) ;
}
return V_185 ;
}
T_2 F_174 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * abort = V_12 ;
T_2 V_180 ;
V_180 = V_49 ;
F_10 ( V_13 , V_61 , F_34 ( abort ) ) ;
F_10 ( V_13 , V_113 ,
F_59 ( V_304 ) ) ;
F_10 ( V_13 , V_115 ,
F_60 ( V_368 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_180 ;
}
T_2 F_175 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_10 ( V_13 , V_369 , F_59 ( - V_370 ) ) ;
return V_49 ;
}
T_2 F_176 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_10 ( V_13 , V_369 ,
F_59 ( - V_371 ) ) ;
return V_49 ;
}
T_2 F_177 (
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
T_2 F_178 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 , T_4 * V_13 )
{
return F_177 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_179 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * abort = V_12 ;
T_2 V_180 ;
F_10 ( V_13 , V_21 ,
F_12 ( V_72 ) ) ;
V_180 = V_49 ;
F_10 ( V_13 , V_61 , F_34 ( abort ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_25 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_10 ( V_13 , V_113 ,
F_59 ( V_68 ) ) ;
F_10 ( V_13 , V_212 ,
F_60 ( V_368 ) ) ;
return V_180 ;
}
T_2 F_180 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
return F_179 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
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
F_12 ( V_23 ) ) ;
return F_174 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_182 (
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
return F_174 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_183 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
return F_182 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_184 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
if ( V_50 == F_55 ( V_9 , V_11 , type ,
(struct V_108 * ) V_12 , V_13 ) )
return V_50 ;
F_10 ( V_13 , V_119 ,
F_57 ( V_12 ) ) ;
return V_49 ;
}
T_2 F_185 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
F_10 ( V_13 , V_372 , F_34 ( V_2 ) ) ;
F_10 ( V_13 , V_73 ,
F_12 ( V_191 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_2 ) ) ;
return V_49 ;
}
T_2 F_186 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_67 ( L_14 , type . V_373 ) ;
return V_131 ;
}
T_2 F_187 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_14 * V_374 ;
V_374 = F_188 ( V_11 , V_19 ) ;
if ( ! V_374 )
return V_50 ;
F_10 ( V_13 , V_20 , F_11 ( V_374 ) ) ;
return V_49 ;
}
T_2 F_173 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_109 ;
V_109 = F_189 ( V_11 , NULL ) ;
if ( ! V_109 )
goto V_58;
F_10 ( V_13 , V_239 , F_34 ( V_109 ) ) ;
F_10 ( V_13 , V_73 ,
F_12 ( V_22 ) ) ;
F_10 ( V_13 , V_240 ,
F_12 ( V_23 ) ) ;
if ( V_11 -> V_105 )
F_10 ( V_13 , V_21 ,
F_12 ( V_106 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_375 ) ) ;
F_10 ( V_13 , V_218 , F_16 () ) ;
F_10 ( V_13 , V_61 , F_34 ( V_109 ) ) ;
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
struct V_1 * V_109 ;
if ( V_2 ) {
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_231 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
}
V_109 = F_117 ( V_11 , V_2 ) ;
if ( ! V_109 )
goto V_58;
F_10 ( V_13 , V_239 , F_34 ( V_109 ) ) ;
F_10 ( V_13 , V_240 ,
F_12 ( V_22 ) ) ;
if ( V_11 -> V_105 )
F_10 ( V_13 , V_21 ,
F_12 ( V_106 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_376 ) ) ;
F_10 ( V_13 , V_218 , F_16 () ) ;
F_10 ( V_13 , V_61 , F_34 ( V_109 ) ) ;
return V_49 ;
V_58:
return V_50 ;
}
T_2 F_190 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_67 ( L_15 , type . V_377 ) ;
return V_131 ;
}
T_2 F_191 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_108 * V_69 = V_12 ;
F_14 ( V_7 , V_378 ) ;
if ( V_11 -> V_111 >= V_11 -> V_112 ) {
if ( V_11 -> V_172 == V_367 ) {
F_10 ( V_13 , V_379 ,
F_12 ( V_23 ) ) ;
} else {
F_10 ( V_13 , V_113 ,
F_59 ( V_114 ) ) ;
F_10 ( V_13 , V_115 ,
F_60 ( V_116 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_29 ;
}
}
F_10 ( V_13 , V_380 , F_57 ( V_69 ) ) ;
F_10 ( V_13 , V_381 , F_57 ( V_69 ) ) ;
return V_49 ;
}
T_2 F_192 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_14 ( V_7 , V_382 ) ;
F_10 ( V_13 , V_266 , F_127 () ) ;
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
struct V_207 * V_208 ;
int V_209 = V_11 -> V_210 + 1 ;
F_67 ( L_16 ) ;
F_14 ( V_7 , V_383 ) ;
if ( V_209 <= V_11 -> V_211 ) {
V_208 = (struct V_207 * ) & V_11 -> V_43 . V_201 ;
V_30 = F_104 ( V_11 , V_208 , V_19 , 0 ) ;
if ( ! V_30 )
return V_50 ;
F_10 ( V_13 , V_363 ,
F_34 ( V_30 ) ) ;
F_10 ( V_13 , V_384 ,
F_12 ( V_72 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_30 ) ) ;
} else {
F_67 ( L_17
L_18 ,
V_209 , V_11 -> V_211 ) ;
F_10 ( V_13 , V_113 ,
F_59 ( V_114 ) ) ;
F_10 ( V_13 , V_212 ,
F_60 ( V_116 ) ) ;
return V_29 ;
}
return V_49 ;
}
T_2 F_194 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_30 = NULL ;
int V_209 = V_11 -> V_210 + 1 ;
F_67 ( L_19 ) ;
F_14 ( V_7 , V_385 ) ;
if ( V_209 <= V_11 -> V_211 ) {
V_30 = F_195 ( V_11 , NULL ) ;
if ( ! V_30 )
return V_50 ;
F_10 ( V_13 , V_363 ,
F_34 ( V_30 ) ) ;
F_10 ( V_13 , V_386 ,
F_12 ( V_74 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_30 ) ) ;
} else {
F_10 ( V_13 , V_113 ,
F_59 ( V_114 ) ) ;
F_10 ( V_13 , V_212 ,
F_60 ( V_116 ) ) ;
return V_29 ;
}
return V_49 ;
}
T_2 F_196 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_109 = NULL ;
F_67 ( L_20 ) ;
F_14 ( V_7 , V_387 ) ;
( (struct V_10 * ) V_11 ) -> V_388 ++ ;
if ( V_11 -> V_111 >= V_11 -> V_112 ) {
F_10 ( V_13 , V_113 ,
F_59 ( V_114 ) ) ;
F_10 ( V_13 , V_115 ,
F_60 ( V_116 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_29 ;
}
switch ( V_11 -> V_172 ) {
case V_375 :
V_109 = F_189 ( V_11 , NULL ) ;
break;
case V_376 :
V_109 = F_117 ( V_11 , NULL ) ;
break;
default:
F_126 () ;
break;
}
if ( ! V_109 )
goto V_58;
if ( V_11 -> V_389 )
F_10 ( V_13 , V_380 ,
F_57 ( V_11 -> V_389 ) ) ;
F_10 ( V_13 , V_239 , F_34 ( V_109 ) ) ;
F_10 ( V_13 , V_240 ,
F_12 ( V_22 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_109 ) ) ;
return V_49 ;
V_58:
return V_50 ;
}
T_2 F_197 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_11 -> V_299 ;
struct V_108 * V_69 = V_2 -> V_69 ;
F_14 ( V_7 , V_390 ) ;
if ( V_69 )
F_10 ( V_13 , V_380 ,
F_57 ( V_69 ) ) ;
F_10 ( V_13 , V_372 , F_34 ( V_2 ) ) ;
if ( V_11 -> V_111 >= V_11 -> V_112 ) {
F_10 ( V_13 , V_21 ,
F_12 ( V_191 ) ) ;
F_10 ( V_13 , V_113 ,
F_59 ( V_114 ) ) ;
F_10 ( V_13 , V_115 ,
F_60 ( V_116 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_226 ;
}
F_198 ( V_11 -> V_299 ) ;
F_10 ( V_13 , V_61 ,
F_34 ( V_11 -> V_299 ) ) ;
F_10 ( V_13 , V_240 ,
F_12 ( V_191 ) ) ;
return V_49 ;
}
T_2 F_199 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_109 = NULL ;
F_67 ( L_21 ) ;
F_14 ( V_7 , V_391 ) ;
V_109 = F_132 ( V_11 , NULL , 0 ) ;
if ( ! V_109 )
goto V_58;
F_10 ( V_13 , V_61 , F_34 ( V_109 ) ) ;
F_10 ( V_13 , V_113 ,
F_59 ( V_114 ) ) ;
F_10 ( V_13 , V_115 ,
F_60 ( V_116 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_29 ;
V_58:
return V_50 ;
}
T_2 F_200 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
int V_185 ;
F_14 ( V_7 , V_392 ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_367 ) ) ;
V_185 = V_49 ;
if ( F_113 ( & V_11 -> V_237 ) ) {
V_185 = F_173 ( V_7 , V_9 , V_11 , type ,
V_12 , V_13 ) ;
}
return V_185 ;
}
T_2 F_201 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
return V_393 ;
}
T_2 F_202 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
return V_394 ;
}
T_2 F_203 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_67 ( L_22 , type . V_2 ) ;
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
V_36 += ( V_397 + V_398 ) * sizeof( T_14 ) ;
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
T_8 V_122 )
{
struct V_33 * V_34 ;
struct V_1 * abort ;
V_34 = F_131 ( V_7 , V_11 , V_2 ) ;
if ( V_34 ) {
abort = F_132 ( V_11 , V_2 , V_122 ) ;
if ( ! abort ) {
F_133 ( V_34 ) ;
return NULL ;
}
if ( F_134 ( abort ) )
V_34 -> V_41 = F_102 ( V_2 -> V_40 -> V_41 ) ;
F_32 ( abort , V_122 , V_348 ) ;
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
struct V_108 * V_69 ;
T_1 V_400 ;
T_1 V_401 ;
T_14 V_41 ;
V_400 = F_2 ( V_2 -> V_40 -> V_202 ) ;
V_401 = F_2 ( V_2 -> V_40 -> V_296 ) ;
if ( V_11 ) {
switch( V_2 -> V_5 -> type ) {
case V_350 :
{
V_63 * V_353 ;
V_353 = ( V_63 * ) V_2 -> V_5 ;
V_41 = F_102 ( V_353 -> V_52 . V_352 ) ;
break;
}
default:
V_41 = V_11 -> V_99 . V_351 . V_352 ;
break;
}
} else {
switch( V_2 -> V_5 -> type ) {
case V_402 :
{
V_42 * V_149 ;
V_149 = ( V_42 * ) V_2 -> V_5 ;
V_41 = F_102 ( V_149 -> V_52 . V_352 ) ;
break;
}
default:
V_41 = F_102 ( V_2 -> V_40 -> V_41 ) ;
break;
}
}
V_69 = F_204 ( V_7 , F_29 ( V_2 ) , V_19 ) ;
if ( ! V_69 )
goto V_58;
F_205 ( V_69 , (union V_126 * ) & V_2 -> V_202 ,
F_18 ( V_7 -> V_37 . V_38 ) ) ;
V_34 = F_206 ( & V_69 -> V_34 , V_69 , V_400 , V_401 ) ;
V_34 = F_207 ( V_34 , V_41 , 0 ) ;
return V_34 ;
V_58:
return NULL ;
}
void F_133 ( struct V_33 * V_34 )
{
F_208 ( V_34 -> V_69 ) ;
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
V_34 -> V_41 = V_403 -> V_89 . V_177 ;
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
V_262 * V_261 ;
struct V_1 * V_184 ;
T_8 V_404 ;
T_21 V_405 ;
int V_406 ;
T_14 V_311 ;
struct V_407 * V_408 = (struct V_407 * ) & V_11 -> V_99 . V_314 ;
struct V_81 * V_44 = V_11 -> V_43 . V_44 ;
struct V_7 * V_7 = F_75 ( V_44 ) ;
T_22 V_409 ;
T_22 V_410 ;
V_214 V_411 = 0 ;
V_261 = V_2 -> V_51 . V_261 = ( V_262 * ) V_2 -> V_54 -> V_55 ;
F_25 ( V_2 -> V_54 , sizeof( V_262 ) ) ;
V_311 = F_102 ( V_261 -> V_311 ) ;
F_67 ( L_23 , V_311 ) ;
if ( ! V_2 -> V_412 ) {
struct V_156 * V_157 ;
V_2 -> V_412 = 1 ;
V_157 = F_69 (
F_209 ( F_210 ( V_2 -> V_54 ) -> V_413 ) ) ;
if ( V_157 && V_157 -> V_414 ( V_2 -> V_54 ) && V_11 -> V_99 . V_415 ) {
F_10 ( V_13 , V_416 ,
F_120 ( V_311 ) ) ;
}
}
V_406 = F_154 ( & V_11 -> V_99 . V_314 , V_311 ) ;
if ( V_406 < 0 ) {
return V_251 ;
} else if ( V_406 > 0 ) {
F_10 ( V_13 , V_417 , F_120 ( V_311 ) ) ;
return V_255 ;
}
V_404 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_404 -= sizeof( V_250 ) ;
V_405 = V_418 ;
if ( ( V_404 >= V_11 -> V_178 ) && ( ! V_11 -> V_419 . V_420 ) ) {
F_10 ( V_13 , V_421 , F_16 () ) ;
}
if ( ( ! V_2 -> V_422 ) && ( ! V_11 -> V_178 || V_11 -> V_423 ||
( V_404 > V_11 -> V_178 + V_11 -> V_424 ) ) ) {
if ( F_211 ( V_408 ) &&
( F_212 ( V_408 ) + 1 ) == V_311 ) {
F_67 ( L_24 , V_311 ) ;
V_405 = V_425 ;
} else {
F_67 ( L_25
L_26 , V_311 , V_404 ,
V_11 -> V_178 ) ;
return V_256 ;
}
}
if ( * V_44 -> V_426 -> V_427 ) {
if ( F_211 ( V_408 ) &&
( F_212 ( V_408 ) + 1 ) == V_311 ) {
F_67 ( L_27 , V_311 ) ;
V_405 = V_425 ;
}
}
if ( F_3 ( 0 == V_404 ) ) {
V_184 = F_213 ( V_11 , V_2 , V_311 ) ;
if ( V_184 ) {
F_10 ( V_13 , V_61 ,
F_34 ( V_184 ) ) ;
}
F_10 ( V_13 , V_165 , F_16 () ) ;
F_10 ( V_13 , V_113 ,
F_59 ( V_304 ) ) ;
F_10 ( V_13 , V_115 ,
F_60 ( V_428 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_258 ;
}
V_2 -> V_422 = 1 ;
if ( V_2 -> V_5 -> V_263 & V_429 )
F_14 ( V_7 , V_430 ) ;
else {
F_14 ( V_7 , V_431 ) ;
V_411 = 1 ;
}
V_410 = F_2 ( V_261 -> V_315 ) ;
if ( V_410 >= V_11 -> V_89 . V_97 ) {
F_10 ( V_13 , V_432 , F_120 ( V_311 ) ) ;
V_184 = F_88 ( V_11 , V_2 , V_433 ,
& V_261 -> V_315 ,
sizeof( V_261 -> V_315 ) ,
sizeof( T_22 ) ) ;
if ( V_184 )
F_10 ( V_13 , V_61 ,
F_34 ( V_184 ) ) ;
return V_252 ;
}
V_409 = F_2 ( V_261 -> V_409 ) ;
if ( V_411 && F_214 ( V_409 , F_215 ( & V_11 -> V_434 -> V_435 , V_410 ) ) ) {
return V_260 ;
}
F_10 ( V_13 , V_405 , F_34 ( V_2 ) ) ;
return V_94 ;
}
