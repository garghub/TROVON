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
T_8 * V_56 ;
struct V_1 * V_2 = V_12 ;
struct V_1 * V_109 ;
T_9 V_122 = 0 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_123 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_2 -> V_51 . V_124 = ( V_125 * ) V_2 -> V_54 -> V_55 ;
V_56 = ( T_8 * ) V_2 -> V_51 . V_124 ;
V_122 = F_2 ( V_2 -> V_5 -> V_6 ) - sizeof( V_17 ) ;
if ( F_2 ( V_56 -> V_6 ) > V_122 )
return F_62 ( V_7 , V_9 , V_11 , type , V_12 ,
V_56 , V_13 ) ;
if ( ! F_44 ( V_2 -> V_54 , V_122 ) )
goto V_58;
V_109 = F_63 ( V_11 , V_2 , V_56 , V_122 ) ;
if ( ! V_109 )
goto V_58;
F_10 ( V_13 , V_61 , F_34 ( V_109 ) ) ;
return V_49 ;
V_58:
return V_50 ;
}
T_2 F_64 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
union V_126 V_127 ;
struct V_108 * V_128 ;
T_10 * V_129 ;
unsigned long V_130 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_17 ) +
sizeof( T_10 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_129 = ( T_10 * ) V_2 -> V_54 -> V_55 ;
if ( F_2 ( V_129 -> V_56 . V_6 ) !=
sizeof( T_10 ) ) {
return V_131 ;
}
V_127 = V_129 -> V_132 ;
V_128 = F_65 ( V_11 , & V_127 ) ;
if ( F_3 ( ! V_128 ) ) {
if ( V_127 . V_133 . V_134 == V_135 ) {
F_66 ( L_1 ,
V_136 ,
V_11 ,
& V_127 . V_137 . V_138 ) ;
} else {
F_66 ( L_2 ,
V_136 ,
V_11 ,
& V_127 . V_139 . V_140 . V_141 ) ;
}
return V_131 ;
}
if ( V_129 -> V_142 != V_128 -> V_142 )
return V_131 ;
V_130 = V_128 -> V_143 + V_128 -> V_144 ;
if ( F_67 ( V_129 -> V_145 , V_146 ) ||
F_67 ( V_146 , V_129 -> V_145 + V_130 ) ) {
F_68 ( L_3
L_4 , V_136 , V_128 ) ;
return V_131 ;
}
F_10 ( V_13 , V_147 , F_57 ( V_128 ) ) ;
return V_49 ;
}
static int F_69 ( struct V_7 * V_7 , union V_126 * V_148 ,
struct V_1 * V_149 ,
T_4 * V_13 )
{
int V_36 ;
struct V_33 * V_150 ;
union V_151 * V_152 ;
struct V_153 * V_154 ;
struct V_8 * V_9 ;
char V_155 [ sizeof( struct V_153 ) + sizeof( union V_151 ) ] ;
struct V_156 * V_157 = F_70 ( V_148 -> V_139 . V_158 ) ;
V_154 = (struct V_153 * ) V_155 ;
V_152 = (union V_151 * ) V_154 -> V_159 ;
V_36 = V_157 -> V_160 ( V_148 , V_152 ) ;
V_36 += sizeof( V_161 ) ;
V_154 -> V_162 = V_163 ;
V_154 -> V_6 = F_71 ( V_36 ) ;
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
static bool F_72 ( const struct V_166 * V_167 ,
union V_126 * V_168 )
{
struct V_108 * V_169 ;
F_73 (addr, list, transports) {
if ( F_74 ( V_168 , & V_169 -> V_168 ) )
return true ;
}
return false ;
}
static int F_75 ( const struct V_10 * V_31 ,
const struct V_10 * V_11 ,
struct V_1 * V_149 ,
T_4 * V_13 )
{
struct V_7 * V_7 = F_76 ( V_31 -> V_43 . V_44 ) ;
struct V_108 * V_170 ;
int V_93 = 1 ;
F_73 (new_addr, &new_asoc->peer.transport_addr_list,
transports) {
if ( ! F_72 ( & V_11 -> V_99 . V_171 ,
& V_170 -> V_168 ) ) {
F_69 ( V_7 , & V_170 -> V_168 , V_149 ,
V_13 ) ;
V_93 = 0 ;
break;
}
}
return V_93 ;
}
static void F_77 ( struct V_10 * V_31 ,
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
static char F_78 ( struct V_10 * V_31 ,
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
static T_2 F_79 (
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
if ( ! F_80 ( V_11 , V_182 ) ) {
if ( ! F_75 ( V_31 , V_11 , V_2 ,
V_13 ) ) {
V_180 = V_49 ;
goto V_183;
}
}
F_77 ( V_31 , V_11 ) ;
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
T_2 F_81 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
return F_79 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_82 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
return F_79 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_83 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 , T_4 * V_13 )
{
if ( V_9 == F_18 ( V_7 -> V_37 . V_38 ) -> V_9 )
return F_84 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
else
return F_85 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
static T_2 F_86 ( struct V_7 * V_7 ,
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
if ( ! F_75 ( V_31 , V_11 , V_2 , V_13 ) ) {
return V_49 ;
}
if ( F_80 ( V_11 , V_186 ) ) {
V_185 = F_87 ( V_7 , V_9 , V_11 ,
F_88 ( V_2 -> V_5 -> type ) ,
V_2 , V_13 ) ;
if ( V_50 == V_185 )
goto V_58;
V_184 = F_89 ( V_11 , V_2 ,
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
F_10 ( V_13 , V_20 , F_11 ( V_15 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_102 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_30 ) ) ;
return V_49 ;
V_98:
F_23 ( V_30 ) ;
V_58:
return V_50 ;
}
static T_2 F_90 ( struct V_7 * V_7 ,
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
F_10 ( V_13 , V_195 , F_91 ( V_95 ) ) ;
if ( V_11 -> V_99 . V_100 )
F_10 ( V_13 , V_196 , F_16 () ) ;
return V_49 ;
V_58:
return V_50 ;
}
static T_2 F_92 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
struct V_1 * V_2 ,
T_4 * V_13 ,
struct V_10 * V_31 )
{
return V_131 ;
}
static T_2 F_93 ( struct V_7 * V_7 ,
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
T_2 F_94 ( struct V_7 * V_7 ,
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
V_197 = F_78 ( V_31 , V_11 ) ;
switch ( V_197 ) {
case 'A' :
V_180 = F_86 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
V_31 ) ;
break;
case 'B' :
V_180 = F_90 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
V_31 ) ;
break;
case 'C' :
V_180 = F_92 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
V_31 ) ;
break;
case 'D' :
V_180 = F_93 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
V_31 ) ;
break;
default:
V_180 = F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
break;
}
F_10 ( V_13 , V_198 , F_33 ( V_31 ) ) ;
F_10 ( V_13 , V_28 , F_16 () ) ;
F_10 ( V_13 , V_198 ,
F_33 ( (struct V_10 * ) V_11 ) ) ;
return V_180 ;
V_58:
return V_50 ;
}
T_2 F_95 (
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
F_96 ( & V_11 -> V_43 . V_201 , & V_2 -> V_202 ) )
return F_85 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
return F_97 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_98 ( struct V_7 * V_7 ,
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
F_96 ( & V_11 -> V_43 . V_201 , & V_2 -> V_202 ) )
return F_85 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_22 ) ) ;
F_10 ( V_13 , V_21 ,
F_12 ( V_23 ) ) ;
return F_97 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_99 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
return F_98 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
T_2 F_100 ( struct V_7 * V_7 ,
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
F_101 (err, chunk->chunk_hdr) {
if ( V_204 == V_184 -> V_162 )
return F_102 ( V_7 , V_9 , V_11 , type ,
V_12 , V_13 ) ;
}
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
static T_2 F_102 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
T_11 V_205 ;
T_12 V_206 ;
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
V_205 = F_103 ( * ( V_213 * ) ( ( V_214 * ) V_184 + sizeof( V_161 ) ) ) ;
V_205 = ( V_205 * 2 ) / 1000 ;
V_206 . V_56 . type = V_215 ;
V_206 . V_56 . V_6 = F_71 ( sizeof( V_206 ) ) ;
V_206 . V_216 = F_104 ( V_205 ) ;
V_208 = (struct V_207 * ) & V_11 -> V_43 . V_201 ;
V_109 = F_105 ( V_11 , V_208 , V_19 , sizeof( V_206 ) ) ;
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
T_2 F_106 ( struct V_7 * V_7 ,
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
F_96 ( & V_11 -> V_43 . V_201 , & V_2 -> V_202 ) )
return F_85 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
return F_97 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
static T_2 F_97 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
unsigned int V_36 ;
T_13 error = V_116 ;
V_36 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_36 >= sizeof( struct V_223 ) + sizeof( struct V_153 ) ) {
V_161 * V_184 ;
F_101 ( V_184 , V_2 -> V_5 ) ;
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
T_2 F_107 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
unsigned int V_36 ;
T_13 error = V_116 ;
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
T_2 F_108 ( struct V_7 * V_7 ,
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
T_2 F_109 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
return F_107 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
static T_2 F_39 ( struct V_7 * V_7 ,
T_4 * V_13 ,
T_13 error , int V_228 ,
const struct V_10 * V_11 ,
struct V_108 * V_69 )
{
F_68 ( L_5 , V_136 ) ;
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
T_2 F_110 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
T_14 * V_229 ;
T_2 V_185 ;
struct V_14 * V_15 ;
T_15 V_230 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 ,
sizeof( struct V_231 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_229 = ( T_14 * ) V_2 -> V_54 -> V_55 ;
F_25 ( V_2 -> V_54 , sizeof( T_14 ) ) ;
V_2 -> V_51 . V_232 = V_229 ;
V_230 = F_103 ( V_229 -> V_233 ) ;
if ( F_111 ( V_230 , V_11 -> V_234 ) ) {
F_68 ( L_6 , V_136 , V_230 ,
V_11 -> V_234 ) ;
return V_131 ;
}
if ( ! F_111 ( V_230 , V_11 -> V_235 ) )
return F_112 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
V_15 = F_113 ( V_11 , 0 , V_19 ) ;
if ( ! V_15 ) {
V_185 = V_50 ;
goto V_164;
}
F_10 ( V_13 , V_20 , F_11 ( V_15 ) ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_236 ) ) ;
V_185 = V_49 ;
if ( F_114 ( & V_11 -> V_237 ) ) {
V_185 = F_115 ( V_7 , V_9 , V_11 , type ,
V_12 , V_13 ) ;
}
if ( V_50 == V_185 )
goto V_164;
F_10 ( V_13 , V_238 ,
F_116 ( V_2 -> V_51 . V_232 -> V_233 ) ) ;
V_164:
return V_185 ;
}
T_2 F_117 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
T_14 * V_229 ;
T_15 V_230 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 ,
sizeof( struct V_231 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_229 = ( T_14 * ) V_2 -> V_54 -> V_55 ;
V_230 = F_103 ( V_229 -> V_233 ) ;
if ( F_111 ( V_230 , V_11 -> V_234 ) ) {
F_68 ( L_6 , V_136 , V_230 ,
V_11 -> V_234 ) ;
return V_131 ;
}
if ( ! F_111 ( V_230 , V_11 -> V_235 ) )
return F_112 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
F_10 ( V_13 , V_238 ,
F_116 ( V_229 -> V_233 ) ) ;
return V_49 ;
}
T_2 F_87 ( struct V_7 * V_7 ,
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
V_109 = F_118 ( V_11 , V_2 ) ;
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
T_2 F_119 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
T_16 * V_241 ;
struct V_1 * V_2 = V_12 ;
T_17 V_242 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_243 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_241 = ( T_16 * ) V_2 -> V_54 -> V_55 ;
F_25 ( V_2 -> V_54 , sizeof( T_16 ) ) ;
V_242 = F_103 ( V_241 -> V_242 ) ;
if ( F_120 ( V_11 -> V_244 , V_242 ) ) {
F_10 ( V_13 ,
V_245 ,
F_121 ( V_242 ) ) ;
}
return V_49 ;
}
T_2 F_122 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
T_18 * V_246 ;
struct V_1 * V_2 = V_12 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_243 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_246 = ( T_18 * ) V_2 -> V_54 -> V_55 ;
F_25 ( V_2 -> V_54 , sizeof( T_18 ) ) ;
F_10 ( V_13 , V_247 ,
F_121 ( F_103 ( V_246 -> V_242 ) ) ) ;
return V_49 ;
}
T_2 F_123 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
T_19 V_248 = F_124 () ;
int error ;
if ( ! F_37 ( V_2 , V_11 ) ) {
F_10 ( V_13 , V_249 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! F_1 ( V_2 , sizeof( V_250 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
error = F_125 ( V_11 , V_2 , V_13 ) ;
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
return F_126 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
( V_214 * ) V_2 -> V_51 . V_261 , sizeof( V_262 ) ) ;
default:
F_127 () ;
}
if ( V_2 -> V_5 -> V_263 & V_264 )
V_248 = F_128 () ;
if ( V_11 -> V_105 ) {
F_10 ( V_13 , V_240 ,
F_12 ( V_106 ) ) ;
}
if ( V_2 -> V_265 )
F_10 ( V_13 , V_266 , V_248 ) ;
return V_49 ;
V_257:
if ( V_2 -> V_265 )
F_10 ( V_13 , V_266 , F_128 () ) ;
return V_131 ;
V_254:
if ( V_2 -> V_265 )
F_10 ( V_13 , V_266 , V_248 ) ;
return V_131 ;
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
int error ;
if ( ! F_37 ( V_2 , V_11 ) ) {
F_10 ( V_13 , V_249 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! F_1 ( V_2 , sizeof( V_250 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
error = F_125 ( V_11 , V_2 , V_13 ) ;
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
return F_126 ( V_7 , V_9 , V_11 , V_2 , V_13 ,
( V_214 * ) V_2 -> V_51 . V_261 , sizeof( V_262 ) ) ;
default:
F_127 () ;
}
if ( V_2 -> V_265 ) {
F_10 ( V_13 , V_267 , F_16 () ) ;
F_10 ( V_13 , V_266 , F_128 () ) ;
F_10 ( V_13 , V_240 ,
F_12 ( V_22 ) ) ;
}
V_259:
return V_49 ;
}
T_2 F_130 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
T_20 * V_268 ;
T_15 V_230 ;
if ( ! F_37 ( V_2 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_269 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_268 = F_131 ( V_2 ) ;
if ( ! V_268 )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
V_2 -> V_51 . V_270 = V_268 ;
V_230 = F_103 ( V_268 -> V_233 ) ;
if ( F_111 ( V_230 , V_11 -> V_234 ) ) {
F_68 ( L_6 , V_136 , V_230 ,
V_11 -> V_234 ) ;
return V_131 ;
}
if ( ! F_111 ( V_230 , V_11 -> V_235 ) )
return F_112 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
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
V_34 = F_132 ( V_7 , V_11 , V_2 ) ;
if ( V_34 ) {
abort = F_133 ( V_11 , V_2 , 0 ) ;
if ( ! abort ) {
F_134 ( V_34 ) ;
return V_50 ;
}
if ( F_135 ( abort ) )
V_34 -> V_41 = F_103 ( V_2 -> V_40 -> V_41 ) ;
abort -> V_54 -> V_44 = V_9 -> V_43 . V_44 ;
F_136 ( V_34 , abort ) ;
F_10 ( V_13 , V_47 ,
F_24 ( V_34 ) ) ;
F_14 ( V_7 , V_48 ) ;
F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
return V_49 ;
}
return V_50 ;
}
T_2 F_137 ( struct V_7 * V_7 ,
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
F_101 ( V_184 , V_2 -> V_5 ) ;
if ( ( void * ) V_184 != ( void * ) V_2 -> V_224 )
return F_62 ( V_7 , V_9 , V_11 , type , V_12 ,
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
T_2 F_84 ( struct V_7 * V_7 ,
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
F_101 (err, ch) {
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
V_34 = F_132 ( V_7 , V_11 , V_2 ) ;
if ( V_34 ) {
V_282 = F_139 ( V_11 , V_2 ) ;
if ( ! V_282 ) {
F_134 ( V_34 ) ;
return V_50 ;
}
if ( F_135 ( V_282 ) )
V_34 -> V_41 = F_103 ( V_2 -> V_40 -> V_41 ) ;
V_282 -> V_54 -> V_44 = V_9 -> V_43 . V_44 ;
F_136 ( V_34 , V_282 ) ;
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
T_21 * V_286 ;
union V_151 * V_287 ;
T_15 V_288 ;
int V_6 ;
if ( ! F_37 ( V_2 , V_11 ) ) {
F_10 ( V_13 , V_249 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! V_7 -> V_37 . V_289 && ! V_2 -> V_92 )
return F_85 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_2 , sizeof( V_290 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_286 = ( T_21 * ) V_2 -> V_54 -> V_55 ;
V_288 = F_103 ( V_286 -> V_288 ) ;
V_287 = (union V_151 * ) V_286 -> V_291 ;
V_6 = F_2 ( V_287 -> V_292 . V_6 ) ;
if ( V_6 < sizeof( T_8 ) )
return F_62 ( V_7 , V_9 , V_11 , type , V_12 ,
( void * ) V_287 , V_13 ) ;
if ( ! F_145 ( V_11 ,
( T_8 * ) ( ( void * ) V_287 + V_6 ) ,
( void * ) V_2 -> V_224 ,
& V_285 ) )
return F_62 ( V_7 , V_9 , V_11 , type , V_12 ,
( void * ) V_285 , V_13 ) ;
if ( V_288 == V_11 -> V_99 . V_293 + 1 ) {
if ( ! V_2 -> V_294 )
F_146 ( V_11 ) ;
V_283 = F_147 ( (struct V_10 * )
V_11 , V_2 ) ;
if ( ! V_283 )
return V_50 ;
} else if ( V_288 < V_11 -> V_99 . V_293 + 1 ) {
V_283 = F_148 ( V_11 , V_286 -> V_288 ) ;
if ( ! V_283 )
return V_131 ;
V_283 -> V_69 = NULL ;
} else {
return V_131 ;
}
V_283 -> V_202 = V_2 -> V_295 ;
F_10 ( V_13 , V_61 , F_34 ( V_283 ) ) ;
if ( V_11 -> V_296 ) {
F_55 ( V_9 , V_11 , type , V_11 -> V_296 ,
V_13 ) ;
( (struct V_10 * ) V_11 ) -> V_296 = NULL ;
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
struct V_1 * V_297 = V_11 -> V_298 ;
struct V_1 * abort ;
struct V_284 * V_285 = NULL ;
T_21 * V_299 ;
T_15 V_300 , V_301 ;
if ( ! F_37 ( V_283 , V_11 ) ) {
F_10 ( V_13 , V_249 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! V_7 -> V_37 . V_289 && ! V_283 -> V_92 )
return F_85 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_283 , sizeof( V_290 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_299 = ( T_21 * ) V_283 -> V_54 -> V_55 ;
V_301 = F_103 ( V_299 -> V_288 ) ;
if ( ! F_145 ( V_11 ,
( T_8 * ) V_299 -> V_291 ,
( void * ) V_283 -> V_224 ,
& V_285 ) )
return F_62 ( V_7 , V_9 , V_11 , type , V_12 ,
( void * ) V_285 , V_13 ) ;
if ( V_297 ) {
V_299 = ( T_21 * ) V_297 -> V_51 . V_299 ;
V_300 = F_103 ( V_299 -> V_288 ) ;
} else {
V_300 = V_11 -> V_293 - 1 ;
}
if ( F_150 ( V_301 , V_300 + 1 ) &&
! ( V_11 -> V_298 ) ) {
abort = F_133 ( V_11 , V_283 ,
sizeof( V_161 ) ) ;
if ( abort ) {
F_151 ( abort , V_302 , 0 ) ;
F_10 ( V_13 , V_61 ,
F_34 ( abort ) ) ;
}
F_10 ( V_13 , V_21 ,
F_12 ( V_191 ) ) ;
F_10 ( V_13 , V_165 , F_16 () ) ;
F_10 ( V_13 , V_113 ,
F_59 ( V_303 ) ) ;
F_10 ( V_13 , V_115 ,
F_60 ( V_302 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_226 ;
}
if ( ( V_301 == V_300 ) && V_11 -> V_298 ) {
F_10 ( V_13 , V_21 ,
F_12 ( V_191 ) ) ;
if ( ! F_152 ( (struct V_10 * ) V_11 ,
V_283 ) ) {
F_10 ( V_13 , V_304 ,
F_16 () ) ;
return V_49 ;
}
abort = F_133 ( V_11 , V_283 ,
sizeof( V_161 ) ) ;
if ( abort ) {
F_151 ( abort , V_305 , 0 ) ;
F_10 ( V_13 , V_61 ,
F_34 ( abort ) ) ;
}
F_10 ( V_13 , V_165 , F_16 () ) ;
F_10 ( V_13 , V_113 ,
F_59 ( V_303 ) ) ;
F_10 ( V_13 , V_115 ,
F_60 ( V_302 ) ) ;
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
struct V_306 * V_307 ;
struct V_308 * V_309 ;
T_1 V_36 ;
T_15 V_310 ;
if ( ! F_37 ( V_2 , V_11 ) ) {
F_10 ( V_13 , V_249 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_311 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_307 = (struct V_306 * ) V_2 -> V_54 -> V_55 ;
V_2 -> V_51 . V_307 = V_307 ;
V_36 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_36 -= sizeof( struct V_223 ) ;
F_25 ( V_2 -> V_54 , V_36 ) ;
V_310 = F_103 ( V_307 -> V_312 ) ;
F_68 ( L_7 , V_136 , V_310 ) ;
if ( F_154 ( & V_11 -> V_99 . V_313 , V_310 ) < 0 )
goto V_254;
F_155 (skip, chunk) {
if ( F_2 ( V_309 -> V_314 ) >= V_11 -> V_89 . V_97 )
goto V_254;
}
F_10 ( V_13 , V_315 , F_121 ( V_310 ) ) ;
if ( V_36 > sizeof( struct V_306 ) )
F_10 ( V_13 , V_316 ,
F_34 ( V_2 ) ) ;
if ( V_11 -> V_105 ) {
F_10 ( V_13 , V_240 ,
F_12 ( V_106 ) ) ;
}
F_10 ( V_13 , V_266 , F_124 () ) ;
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
struct V_306 * V_307 ;
struct V_308 * V_309 ;
T_1 V_36 ;
T_15 V_310 ;
if ( ! F_37 ( V_2 , V_11 ) ) {
F_10 ( V_13 , V_249 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_311 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_307 = (struct V_306 * ) V_2 -> V_54 -> V_55 ;
V_2 -> V_51 . V_307 = V_307 ;
V_36 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_36 -= sizeof( struct V_223 ) ;
F_25 ( V_2 -> V_54 , V_36 ) ;
V_310 = F_103 ( V_307 -> V_312 ) ;
F_68 ( L_7 , V_136 , V_310 ) ;
if ( F_154 ( & V_11 -> V_99 . V_313 , V_310 ) < 0 )
goto V_317;
F_155 (skip, chunk) {
if ( F_2 ( V_309 -> V_314 ) >= V_11 -> V_89 . V_97 )
goto V_317;
}
F_10 ( V_13 , V_315 , F_121 ( V_310 ) ) ;
if ( V_36 > sizeof( struct V_306 ) )
F_10 ( V_13 , V_316 ,
F_34 ( V_2 ) ) ;
V_317:
F_10 ( V_13 , V_267 , F_16 () ) ;
F_10 ( V_13 , V_266 , F_128 () ) ;
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
struct V_318 * V_319 ;
struct V_320 * V_321 ;
unsigned int V_322 ;
T_1 V_323 ;
V_46 * V_324 ;
V_46 * V_325 ;
V_319 = (struct V_318 * ) V_2 -> V_54 -> V_55 ;
V_2 -> V_51 . V_319 = V_319 ;
F_25 ( V_2 -> V_54 , sizeof( struct V_318 ) ) ;
if ( ! F_157 ( V_11 , V_319 -> V_326 ) )
return V_327 ;
V_323 = F_2 ( V_319 -> V_328 ) ;
if ( V_323 != V_11 -> V_329 && ! F_158 ( V_11 , V_323 ) )
return V_330 ;
V_322 = F_2 ( V_2 -> V_5 -> V_6 ) - sizeof( V_331 ) ;
V_321 = F_159 ( F_2 ( V_319 -> V_326 ) ) ;
if ( V_322 != V_321 -> V_332 )
return V_260 ;
V_325 = V_319 -> V_321 ;
F_25 ( V_2 -> V_54 , V_322 ) ;
V_324 = F_160 ( V_325 , V_322 , V_19 ) ;
if ( ! V_324 )
goto V_58;
memset ( V_325 , 0 , V_322 ) ;
F_161 ( V_11 , V_2 -> V_54 ,
(struct V_333 * ) V_2 -> V_5 ,
V_19 ) ;
if ( memcmp ( V_324 , V_325 , V_322 ) ) {
F_162 ( V_324 ) ;
return V_88 ;
}
F_162 ( V_324 ) ;
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
struct V_318 * V_319 ;
struct V_1 * V_2 = V_12 ;
struct V_1 * V_32 ;
T_7 error ;
if ( ! V_11 -> V_99 . V_334 )
return F_164 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_37 ( V_2 , V_11 ) ) {
F_10 ( V_13 , V_249 ,
F_16 () ) ;
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_333 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
V_319 = (struct V_318 * ) V_2 -> V_54 -> V_55 ;
error = F_49 ( V_7 , V_9 , V_11 , type , V_2 ) ;
switch ( error ) {
case V_327 :
V_32 = F_89 ( V_11 , V_2 ,
V_335 ,
& V_319 -> V_326 ,
sizeof( T_1 ) , 0 ) ;
if ( V_32 ) {
F_10 ( V_13 , V_61 ,
F_34 ( V_32 ) ) ;
}
case V_330 :
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
if ( V_11 -> V_329 != F_2 ( V_319 -> V_328 ) ) {
struct V_14 * V_15 ;
V_15 = F_165 ( V_11 , F_2 ( V_319 -> V_328 ) ,
V_336 , V_19 ) ;
if ( ! V_15 )
return - V_337 ;
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
struct V_1 * V_338 = V_12 ;
struct V_1 * V_32 ;
V_17 * V_286 ;
F_68 ( L_8 , V_136 , type . V_2 ) ;
if ( ! F_37 ( V_338 , V_11 ) )
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
if ( ! F_1 ( V_338 , sizeof( V_17 ) ) )
return F_8 ( V_7 , V_9 , V_11 , type , V_12 ,
V_13 ) ;
switch ( type . V_2 & V_339 ) {
case V_340 :
return F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
break;
case V_341 :
V_286 = V_338 -> V_5 ;
V_32 = F_89 ( V_11 , V_338 ,
V_342 , V_286 ,
F_140 ( F_2 ( V_286 -> V_6 ) ) ,
0 ) ;
if ( V_32 ) {
F_10 ( V_13 , V_61 ,
F_34 ( V_32 ) ) ;
}
F_6 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
return V_49 ;
break;
case V_343 :
return V_131 ;
break;
case V_344 :
V_286 = V_338 -> V_5 ;
V_32 = F_89 ( V_11 , V_338 ,
V_342 , V_286 ,
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
T_2 F_85 ( struct V_7 * V_7 ,
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
F_68 ( L_9 , V_136 , type . V_2 ) ;
return V_131 ;
}
T_2 F_6 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_14 ( V_7 , V_345 ) ;
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
return V_346 ;
}
static T_2 F_126 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
void * V_12 ,
T_4 * V_13 ,
const V_46 * V_347 ,
const T_9 V_122 )
{
struct V_33 * V_34 = NULL ;
struct V_1 * V_2 = V_12 ;
struct V_1 * abort = NULL ;
if ( F_38 ( V_66 , V_11 ) )
goto V_348;
abort = F_167 ( V_11 , V_2 , V_347 , V_122 ) ;
if ( ! abort )
goto V_58;
if ( V_11 ) {
if ( V_2 -> V_5 -> type == V_349 &&
! V_11 -> V_99 . V_350 . V_351 ) {
V_63 * V_352 ;
V_352 = ( V_63 * ) V_2 -> V_5 ;
if ( ! F_1 ( V_2 ,
sizeof( V_63 ) ) )
abort -> V_5 -> V_263 |= V_353 ;
else {
unsigned int V_354 ;
V_354 = F_103 ( V_352 -> V_52 . V_351 ) ;
F_10 ( V_13 , V_355 ,
F_121 ( V_354 ) ) ;
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
F_60 ( V_356 ) ) ;
} else {
F_10 ( V_13 , V_113 ,
F_59 ( V_303 ) ) ;
F_10 ( V_13 , V_115 ,
F_60 ( V_356 ) ) ;
F_15 ( V_7 , V_27 ) ;
}
} else {
V_34 = F_132 ( V_7 , V_11 , V_2 ) ;
if ( ! V_34 )
goto V_357;
if ( F_135 ( abort ) )
V_34 -> V_41 = F_103 ( V_2 -> V_40 -> V_41 ) ;
abort -> V_54 -> V_44 = V_9 -> V_43 . V_44 ;
F_136 ( V_34 , abort ) ;
F_10 ( V_13 , V_47 ,
F_24 ( V_34 ) ) ;
F_14 ( V_7 , V_48 ) ;
}
F_14 ( V_7 , V_67 ) ;
V_348:
F_6 ( V_7 , V_9 , V_11 , F_88 ( 0 ) , V_12 , V_13 ) ;
return V_226 ;
V_357:
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
static const char V_358 [] = L_10 ;
return F_126 ( V_7 , V_9 , V_11 , V_12 , V_13 , V_358 ,
sizeof( V_358 ) ) ;
}
static T_2 F_62 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 , void * V_359 ,
T_4 * V_13 )
{
struct V_1 * V_2 = V_12 ;
struct V_284 * V_360 = V_359 ;
struct V_1 * abort = NULL ;
if ( F_38 ( V_66 , V_11 ) )
goto V_348;
abort = F_168 ( V_11 , V_2 , V_360 ) ;
if ( ! abort )
goto V_58;
F_10 ( V_13 , V_61 , F_34 ( abort ) ) ;
F_14 ( V_7 , V_48 ) ;
F_10 ( V_13 , V_113 ,
F_59 ( V_303 ) ) ;
F_10 ( V_13 , V_115 ,
F_60 ( V_356 ) ) ;
F_15 ( V_7 , V_27 ) ;
F_14 ( V_7 , V_67 ) ;
V_348:
F_6 ( V_7 , V_9 , V_11 , F_88 ( 0 ) , V_12 , V_13 ) ;
return V_226 ;
V_58:
return V_50 ;
}
static T_2 F_112 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
static const char V_358 [] = L_11 ;
return F_126 ( V_7 , V_9 , V_11 , V_12 , V_13 , V_358 ,
sizeof( V_358 ) ) ;
}
static T_2 F_7 (
struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
static const char V_358 [] = L_12 ;
if ( ! V_11 )
return F_166 ( V_7 , V_9 , V_11 , type , V_12 , V_13 ) ;
return F_126 ( V_7 , V_9 , V_11 , V_12 , V_13 , V_358 ,
sizeof( V_358 ) ) ;
}
T_2 F_169 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
struct V_1 * V_30 ;
struct V_10 * V_361 ;
F_10 ( V_13 , V_24 ,
F_13 ( V_173 ) ) ;
V_30 = F_105 ( V_11 , & V_11 -> V_43 . V_201 , V_19 , 0 ) ;
if ( ! V_30 )
goto V_58;
F_10 ( V_13 , V_362 ,
F_34 ( V_30 ) ) ;
V_361 = (struct V_10 * ) V_11 ;
F_10 ( V_13 , V_60 , F_33 ( V_361 ) ) ;
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
struct V_363 * V_364 = V_12 ;
F_10 ( V_13 , V_365 , F_171 ( V_364 ) ) ;
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
F_13 ( V_366 ) ) ;
V_185 = V_49 ;
if ( F_114 ( & V_11 -> V_237 ) ) {
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
F_59 ( V_303 ) ) ;
F_10 ( V_13 , V_115 ,
F_60 ( V_367 ) ) ;
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
F_10 ( V_13 , V_368 , F_59 ( - V_369 ) ) ;
return V_49 ;
}
T_2 F_176 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_10 ( V_13 , V_368 ,
F_59 ( - V_370 ) ) ;
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
F_60 ( V_367 ) ) ;
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
F_10 ( V_13 , V_371 , F_34 ( V_2 ) ) ;
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
F_68 ( L_13 , V_136 ,
type . V_372 ) ;
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
struct V_14 * V_373 ;
V_373 = F_188 ( V_11 , V_19 ) ;
if ( ! V_373 )
return V_50 ;
F_10 ( V_13 , V_20 , F_11 ( V_373 ) ) ;
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
F_13 ( V_374 ) ) ;
F_10 ( V_13 , V_218 , F_16 () ) ;
F_10 ( V_13 , V_61 , F_34 ( V_109 ) ) ;
return V_49 ;
V_58:
return V_50 ;
}
T_2 F_115 (
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
V_109 = F_118 ( V_11 , V_2 ) ;
if ( ! V_109 )
goto V_58;
F_10 ( V_13 , V_239 , F_34 ( V_109 ) ) ;
F_10 ( V_13 , V_240 ,
F_12 ( V_22 ) ) ;
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
T_2 F_190 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_68 ( L_14 ,
V_136 , type . V_376 ) ;
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
F_14 ( V_7 , V_377 ) ;
if ( V_11 -> V_111 >= V_11 -> V_112 ) {
if ( V_11 -> V_172 == V_366 ) {
F_10 ( V_13 , V_378 ,
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
F_10 ( V_13 , V_379 , F_57 ( V_69 ) ) ;
F_10 ( V_13 , V_380 , F_57 ( V_69 ) ) ;
return V_49 ;
}
T_2 F_192 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_14 ( V_7 , V_381 ) ;
F_10 ( V_13 , V_266 , F_128 () ) ;
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
F_68 ( L_15 , V_136 ) ;
F_14 ( V_7 , V_382 ) ;
if ( V_209 <= V_11 -> V_211 ) {
V_208 = (struct V_207 * ) & V_11 -> V_43 . V_201 ;
V_30 = F_105 ( V_11 , V_208 , V_19 , 0 ) ;
if ( ! V_30 )
return V_50 ;
F_10 ( V_13 , V_362 ,
F_34 ( V_30 ) ) ;
F_10 ( V_13 , V_383 ,
F_12 ( V_72 ) ) ;
F_10 ( V_13 , V_61 , F_34 ( V_30 ) ) ;
} else {
F_68 ( L_16
L_17 , V_136 , V_209 ,
V_11 -> V_211 ) ;
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
F_68 ( L_18 , V_136 ) ;
F_14 ( V_7 , V_384 ) ;
if ( V_209 <= V_11 -> V_211 ) {
V_30 = F_195 ( V_11 , NULL ) ;
if ( ! V_30 )
return V_50 ;
F_10 ( V_13 , V_362 ,
F_34 ( V_30 ) ) ;
F_10 ( V_13 , V_385 ,
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
F_68 ( L_19 , V_136 ) ;
F_14 ( V_7 , V_386 ) ;
( (struct V_10 * ) V_11 ) -> V_387 ++ ;
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
case V_374 :
V_109 = F_189 ( V_11 , NULL ) ;
break;
case V_375 :
V_109 = F_118 ( V_11 , NULL ) ;
break;
default:
F_127 () ;
break;
}
if ( ! V_109 )
goto V_58;
if ( V_11 -> V_388 )
F_10 ( V_13 , V_379 ,
F_57 ( V_11 -> V_388 ) ) ;
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
struct V_1 * V_2 = V_11 -> V_298 ;
struct V_108 * V_69 = V_2 -> V_69 ;
F_14 ( V_7 , V_389 ) ;
if ( V_69 )
F_10 ( V_13 , V_379 ,
F_57 ( V_69 ) ) ;
F_10 ( V_13 , V_371 , F_34 ( V_2 ) ) ;
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
F_198 ( V_11 -> V_298 ) ;
F_10 ( V_13 , V_61 ,
F_34 ( V_11 -> V_298 ) ) ;
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
F_68 ( L_20 , V_136 ) ;
F_14 ( V_7 , V_390 ) ;
V_109 = F_133 ( V_11 , NULL , 0 ) ;
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
F_14 ( V_7 , V_391 ) ;
F_10 ( V_13 , V_24 ,
F_13 ( V_366 ) ) ;
V_185 = V_49 ;
if ( F_114 ( & V_11 -> V_237 ) ) {
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
return V_392 ;
}
T_2 F_202 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
return V_393 ;
}
T_2 F_203 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
const T_3 type ,
void * V_12 ,
T_4 * V_13 )
{
F_68 ( L_21 , V_136 , type . V_2 ) ;
return V_49 ;
}
static struct V_394 * F_131 ( struct V_1 * V_2 )
{
struct V_394 * V_395 ;
unsigned int V_36 ;
T_1 V_396 ;
T_1 V_397 ;
V_395 = (struct V_394 * ) V_2 -> V_54 -> V_55 ;
V_396 = F_2 ( V_395 -> V_398 ) ;
V_397 = F_2 ( V_395 -> V_397 ) ;
V_36 = sizeof( struct V_394 ) ;
V_36 += ( V_396 + V_397 ) * sizeof( T_15 ) ;
if ( V_36 > V_2 -> V_54 -> V_36 )
return NULL ;
F_25 ( V_2 -> V_54 , V_36 ) ;
return V_395 ;
}
static struct V_33 * F_22 ( struct V_7 * V_7 ,
const struct V_8 * V_9 ,
const struct V_10 * V_11 ,
struct V_1 * V_2 ,
const void * V_347 ,
T_9 V_122 )
{
struct V_33 * V_34 ;
struct V_1 * abort ;
V_34 = F_132 ( V_7 , V_11 , V_2 ) ;
if ( V_34 ) {
abort = F_133 ( V_11 , V_2 , V_122 ) ;
if ( ! abort ) {
F_134 ( V_34 ) ;
return NULL ;
}
if ( F_135 ( abort ) )
V_34 -> V_41 = F_103 ( V_2 -> V_40 -> V_41 ) ;
F_32 ( abort , V_122 , V_347 ) ;
abort -> V_54 -> V_44 = V_9 -> V_43 . V_44 ;
F_136 ( V_34 , abort ) ;
}
return V_34 ;
}
static struct V_33 * F_132 ( struct V_7 * V_7 ,
const struct V_10 * V_11 ,
const struct V_1 * V_2 )
{
struct V_33 * V_34 ;
struct V_108 * V_69 ;
T_1 V_399 ;
T_1 V_400 ;
T_15 V_41 ;
V_399 = F_2 ( V_2 -> V_40 -> V_202 ) ;
V_400 = F_2 ( V_2 -> V_40 -> V_295 ) ;
if ( V_11 ) {
switch( V_2 -> V_5 -> type ) {
case V_349 :
{
V_63 * V_352 ;
V_352 = ( V_63 * ) V_2 -> V_5 ;
V_41 = F_103 ( V_352 -> V_52 . V_351 ) ;
break;
}
default:
V_41 = V_11 -> V_99 . V_350 . V_351 ;
break;
}
} else {
switch( V_2 -> V_5 -> type ) {
case V_401 :
{
V_42 * V_149 ;
V_149 = ( V_42 * ) V_2 -> V_5 ;
V_41 = F_103 ( V_149 -> V_52 . V_351 ) ;
break;
}
default:
V_41 = F_103 ( V_2 -> V_40 -> V_41 ) ;
break;
}
}
V_69 = F_204 ( V_7 , F_29 ( V_2 ) , V_19 ) ;
if ( ! V_69 )
goto V_58;
F_205 ( V_69 , (union V_126 * ) & V_2 -> V_202 ,
F_18 ( V_7 -> V_37 . V_38 ) ) ;
V_34 = F_206 ( & V_69 -> V_34 , V_69 , V_399 , V_400 ) ;
V_34 = F_207 ( V_34 , V_41 , 0 ) ;
return V_34 ;
V_58:
return NULL ;
}
void F_134 ( struct V_33 * V_34 )
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
V_34 = F_132 ( V_7 , V_11 , V_2 ) ;
if ( V_34 ) {
struct V_85 * V_402 ;
V_402 = V_2 -> V_51 . V_84 ;
V_34 -> V_41 = V_402 -> V_89 . V_177 ;
V_32 -> V_54 -> V_44 = V_9 -> V_43 . V_44 ;
F_136 ( V_34 , V_32 ) ;
F_10 ( V_13 , V_47 ,
F_24 ( V_34 ) ) ;
F_14 ( V_7 , V_48 ) ;
} else
F_23 ( V_32 ) ;
}
}
static int F_125 ( const struct V_10 * V_11 ,
struct V_1 * V_2 ,
T_4 * V_13 )
{
V_262 * V_261 ;
struct V_1 * V_184 ;
T_9 V_403 ;
T_22 V_404 ;
int V_405 ;
T_15 V_310 ;
struct V_406 * V_407 = (struct V_406 * ) & V_11 -> V_99 . V_313 ;
struct V_81 * V_44 = V_11 -> V_43 . V_44 ;
struct V_7 * V_7 = F_76 ( V_44 ) ;
T_23 V_408 ;
T_23 V_409 ;
V_214 V_410 = 0 ;
V_261 = V_2 -> V_51 . V_261 = ( V_262 * ) V_2 -> V_54 -> V_55 ;
F_25 ( V_2 -> V_54 , sizeof( V_262 ) ) ;
V_310 = F_103 ( V_261 -> V_310 ) ;
F_68 ( L_7 , V_136 , V_310 ) ;
if ( ! V_2 -> V_411 ) {
struct V_156 * V_157 ;
V_2 -> V_411 = 1 ;
V_157 = F_70 (
F_209 ( F_210 ( V_2 -> V_54 ) -> V_412 ) ) ;
if ( V_157 && V_157 -> V_413 ( V_2 -> V_54 ) && V_11 -> V_99 . V_414 ) {
F_10 ( V_13 , V_415 ,
F_121 ( V_310 ) ) ;
}
}
V_405 = F_154 ( & V_11 -> V_99 . V_313 , V_310 ) ;
if ( V_405 < 0 ) {
if ( V_2 -> V_11 )
V_2 -> V_11 -> V_416 . V_417 ++ ;
return V_251 ;
} else if ( V_405 > 0 ) {
F_10 ( V_13 , V_418 , F_121 ( V_310 ) ) ;
return V_255 ;
}
V_403 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_403 -= sizeof( V_250 ) ;
V_404 = V_419 ;
if ( ( V_403 >= V_11 -> V_178 ) && ( ! V_11 -> V_420 . V_421 ) ) {
F_10 ( V_13 , V_422 , F_16 () ) ;
}
if ( ( ! V_2 -> V_423 ) && ( ! V_11 -> V_178 || V_11 -> V_424 ||
( V_403 > V_11 -> V_178 + V_11 -> V_425 ) ) ) {
if ( F_211 ( V_407 ) &&
( F_212 ( V_407 ) + 1 ) == V_310 ) {
F_68 ( L_22 , V_136 , V_310 ) ;
V_404 = V_426 ;
} else {
F_68 ( L_23 ,
V_136 , V_310 , V_403 , V_11 -> V_178 ) ;
return V_256 ;
}
}
if ( * V_44 -> V_427 -> V_428 ) {
if ( F_211 ( V_407 ) &&
( F_212 ( V_407 ) + 1 ) == V_310 ) {
F_68 ( L_24 ,
V_136 , V_310 ) ;
V_404 = V_426 ;
}
}
if ( F_3 ( 0 == V_403 ) ) {
V_184 = F_213 ( V_11 , V_2 , V_310 ) ;
if ( V_184 ) {
F_10 ( V_13 , V_61 ,
F_34 ( V_184 ) ) ;
}
F_10 ( V_13 , V_165 , F_16 () ) ;
F_10 ( V_13 , V_113 ,
F_59 ( V_303 ) ) ;
F_10 ( V_13 , V_115 ,
F_60 ( V_429 ) ) ;
F_14 ( V_7 , V_67 ) ;
F_15 ( V_7 , V_27 ) ;
return V_258 ;
}
V_2 -> V_423 = 1 ;
if ( V_2 -> V_5 -> V_263 & V_430 ) {
F_14 ( V_7 , V_431 ) ;
if ( V_2 -> V_11 )
V_2 -> V_11 -> V_416 . V_432 ++ ;
} else {
F_14 ( V_7 , V_433 ) ;
if ( V_2 -> V_11 )
V_2 -> V_11 -> V_416 . V_434 ++ ;
V_410 = 1 ;
}
V_409 = F_2 ( V_261 -> V_314 ) ;
if ( V_409 >= V_11 -> V_89 . V_97 ) {
F_10 ( V_13 , V_435 , F_121 ( V_310 ) ) ;
V_184 = F_89 ( V_11 , V_2 , V_436 ,
& V_261 -> V_314 ,
sizeof( V_261 -> V_314 ) ,
sizeof( T_23 ) ) ;
if ( V_184 )
F_10 ( V_13 , V_61 ,
F_34 ( V_184 ) ) ;
return V_252 ;
}
V_408 = F_2 ( V_261 -> V_408 ) ;
if ( V_410 && F_214 ( V_408 , F_215 ( & V_11 -> V_437 -> V_438 , V_409 ) ) ) {
return V_260 ;
}
F_10 ( V_13 , V_404 , F_34 ( V_2 ) ) ;
return V_94 ;
}
