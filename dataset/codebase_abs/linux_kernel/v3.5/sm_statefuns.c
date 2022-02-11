static inline int
F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( F_3 ( V_4 < V_3 ) )
return 0 ;
return 1 ;
}
T_2 F_4 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
struct V_13 * V_14 ;
if ( ! F_5 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! V_2 -> V_15 )
return F_7 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_16 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_14 = F_9 ( V_10 , 0 , V_17 ,
0 , 0 , 0 , NULL , V_18 ) ;
if ( V_14 )
F_10 ( V_12 , V_19 ,
F_11 ( V_14 ) ) ;
F_10 ( V_12 , V_20 ,
F_12 ( V_21 ) ) ;
F_10 ( V_12 , V_20 ,
F_12 ( V_22 ) ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_24 ) ) ;
F_14 ( V_25 ) ;
F_15 ( V_26 ) ;
F_10 ( V_12 , V_27 , F_16 () ) ;
return V_28 ;
}
T_2 F_17 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
struct V_1 * V_29 ;
struct V_9 * V_30 ;
struct V_1 * V_31 ;
struct V_32 * V_33 ;
T_5 * V_34 ;
int V_35 ;
if ( ! V_2 -> V_15 )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( V_8 == F_18 ( ( F_19 () ) ) -> V_8 ) {
F_14 ( V_36 ) ;
return F_20 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( V_2 -> V_37 -> V_38 != 0 )
return F_20 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_39 ) ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( F_21 ( V_8 -> V_40 . V_41 , V_42 ) )
return F_20 ( V_8 , V_10 , type , V_11 , V_12 ) ;
V_31 = NULL ;
if ( ! F_22 ( V_10 , V_2 -> V_5 -> type ,
( V_39 * ) V_2 -> V_5 , V_2 ,
& V_31 ) ) {
if ( V_31 ) {
V_33 = F_23 ( V_8 , V_10 , V_11 ,
( V_43 * ) ( V_31 -> V_5 ) +
sizeof( V_16 ) ,
F_2 ( V_31 -> V_5 -> V_6 ) -
sizeof( V_16 ) ) ;
F_24 ( V_31 ) ;
if ( V_33 ) {
F_10 ( V_12 , V_44 ,
F_25 ( V_33 ) ) ;
F_14 ( V_45 ) ;
return V_46 ;
} else {
return V_47 ;
}
} else {
return F_20 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
}
}
V_2 -> V_48 . V_49 = ( V_50 * ) V_2 -> V_51 -> V_52 ;
V_2 -> V_53 . V_54 = F_26 ( V_2 -> V_51 , sizeof( V_50 ) ) ;
V_30 = F_27 ( V_8 , V_2 , V_18 ) ;
if ( ! V_30 )
goto V_55;
if ( F_28 ( V_30 ,
F_29 ( F_30 ( V_2 ) ) ,
V_18 ) < 0 )
goto V_56;
if ( ! F_31 ( V_30 , V_2 , F_30 ( V_2 ) ,
( V_39 * ) V_2 -> V_5 ,
V_18 ) )
goto V_56;
V_35 = 0 ;
if ( V_31 )
V_35 = F_2 ( V_31 -> V_5 -> V_6 ) -
sizeof( V_16 ) ;
V_29 = F_32 ( V_30 , V_2 , V_18 , V_35 ) ;
if ( ! V_29 )
goto V_56;
if ( V_31 ) {
V_34 = ( T_5 * )
( ( V_43 * ) ( V_31 -> V_5 ) +
sizeof( V_16 ) ) ;
F_33 ( V_29 , V_35 , V_34 ) ;
F_24 ( V_31 ) ;
}
F_10 ( V_12 , V_57 , F_34 ( V_30 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_29 ) ) ;
F_10 ( V_12 , V_27 , F_16 () ) ;
return V_28 ;
V_56:
F_36 ( V_30 ) ;
V_55:
if ( V_31 )
F_24 ( V_31 ) ;
return V_47 ;
}
T_2 F_37 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
V_39 * V_59 ;
struct V_1 * V_31 ;
struct V_32 * V_33 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! V_2 -> V_15 )
return F_7 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_60 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_2 -> V_48 . V_49 = ( V_50 * ) V_2 -> V_51 -> V_52 ;
V_31 = NULL ;
if ( ! F_22 ( V_10 , V_2 -> V_5 -> type ,
( V_39 * ) V_2 -> V_5 , V_2 ,
& V_31 ) ) {
T_6 error = V_61 ;
if ( V_31 ) {
V_33 = F_23 ( V_8 , V_10 , V_11 ,
( V_43 * ) ( V_31 -> V_5 ) +
sizeof( V_16 ) ,
F_2 ( V_31 -> V_5 -> V_6 ) -
sizeof( V_16 ) ) ;
F_24 ( V_31 ) ;
if ( V_33 ) {
F_10 ( V_12 , V_44 ,
F_25 ( V_33 ) ) ;
F_14 ( V_45 ) ;
error = V_62 ;
}
}
if ( F_39 ( V_63 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
F_14 ( V_64 ) ;
return F_40 ( V_12 , error , V_65 ,
V_10 , V_2 -> V_66 ) ;
}
V_2 -> V_53 . V_54 = F_26 ( V_2 -> V_51 , sizeof( V_50 ) ) ;
V_59 = ( V_39 * ) V_2 -> V_5 ;
F_10 ( V_12 , V_67 ,
F_41 ( V_59 ) ) ;
F_10 ( V_12 , V_68 , F_16 () ) ;
F_10 ( V_12 , V_20 ,
F_12 ( V_69 ) ) ;
F_10 ( V_12 , V_70 ,
F_12 ( V_71 ) ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_72 ) ) ;
F_10 ( V_12 , V_73 , F_16 () ) ;
F_10 ( V_12 , V_74 ,
F_35 ( V_31 ) ) ;
return V_46 ;
}
T_2 F_42 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type , void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
struct V_9 * V_30 ;
V_39 * V_75 ;
struct V_1 * V_29 ;
struct V_13 * V_14 , * V_76 = NULL ;
int error = 0 ;
struct V_1 * V_77 ;
struct V_78 * V_41 ;
if ( V_8 == F_18 ( ( F_19 () ) ) -> V_8 ) {
F_14 ( V_36 ) ;
return F_20 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! F_1 ( V_2 , sizeof( V_16 ) ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
V_41 = V_8 -> V_40 . V_41 ;
if ( ! F_21 ( V_41 , V_79 ) ||
( F_43 ( V_41 , V_80 ) && F_44 ( V_41 ) ) )
return F_20 ( V_8 , V_10 , type , V_11 , V_12 ) ;
V_2 -> V_48 . V_81 =
(struct V_82 * ) V_2 -> V_51 -> V_52 ;
if ( ! F_45 ( V_2 -> V_51 , F_2 ( V_2 -> V_5 -> V_6 ) -
sizeof( V_16 ) ) )
goto V_55;
V_30 = F_46 ( V_8 , V_10 , V_2 , V_18 , & error ,
& V_77 ) ;
if ( ! V_30 ) {
switch ( error ) {
case - V_83 :
goto V_55;
case - V_84 :
F_47 ( V_8 , V_10 , V_2 , V_12 ,
V_77 ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
case - V_85 :
default:
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
}
V_75 = & V_2 -> V_48 . V_81 -> V_86 . V_75 [ 0 ] ;
if ( ! F_31 ( V_30 , V_2 ,
& V_2 -> V_48 . V_81 -> V_86 . V_87 ,
V_75 , V_18 ) )
goto V_56;
error = F_48 ( V_30 , V_18 ) ;
if ( error )
goto V_56;
if ( V_2 -> V_88 ) {
struct V_1 V_89 ;
T_7 V_90 ;
V_89 . V_51 = V_2 -> V_88 ;
V_89 . V_10 = V_2 -> V_10 ;
V_89 . V_37 = V_2 -> V_37 ;
V_89 . V_5 = ( V_16 * ) F_49 ( V_2 -> V_88 ,
sizeof( V_16 ) ) ;
F_26 ( V_2 -> V_88 , sizeof( V_16 ) ) ;
V_89 . V_66 = V_2 -> V_66 ;
V_90 = F_50 ( V_8 , V_30 , type , & V_89 ) ;
F_51 ( V_2 -> V_88 ) ;
if ( V_90 != V_91 ) {
F_36 ( V_30 ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
}
V_29 = F_52 ( V_30 , V_2 ) ;
if ( ! V_29 )
goto V_56;
V_14 = F_9 ( V_30 , 0 , V_92 , 0 ,
V_30 -> V_86 . V_93 ,
V_30 -> V_86 . V_94 ,
NULL , V_18 ) ;
if ( ! V_14 )
goto V_95;
if ( V_30 -> V_96 . V_97 ) {
V_76 = F_53 ( V_30 ,
V_18 ) ;
if ( ! V_76 )
goto V_98;
}
F_10 ( V_12 , V_57 , F_34 ( V_30 ) ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_99 ) ) ;
F_14 ( V_26 ) ;
F_14 ( V_100 ) ;
F_10 ( V_12 , V_101 , F_16 () ) ;
if ( V_30 -> V_102 )
F_10 ( V_12 , V_70 ,
F_12 ( V_103 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_29 ) ) ;
F_10 ( V_12 , V_19 , F_11 ( V_14 ) ) ;
if ( V_76 )
F_10 ( V_12 , V_19 ,
F_11 ( V_76 ) ) ;
return V_46 ;
V_98:
F_54 ( V_14 ) ;
V_95:
F_24 ( V_29 ) ;
V_56:
F_36 ( V_30 ) ;
V_55:
return V_47 ;
}
T_2 F_55 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type , void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
struct V_13 * V_14 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_16 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
F_10 ( V_12 , V_68 , F_16 () ) ;
F_10 ( V_12 , V_20 ,
F_12 ( V_71 ) ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_99 ) ) ;
F_14 ( V_26 ) ;
F_14 ( V_104 ) ;
F_10 ( V_12 , V_101 , F_16 () ) ;
if ( V_10 -> V_102 )
F_10 ( V_12 , V_70 ,
F_12 ( V_103 ) ) ;
V_14 = F_9 ( V_10 , 0 , V_92 ,
0 , V_10 -> V_86 . V_93 ,
V_10 -> V_86 . V_94 ,
NULL , V_18 ) ;
if ( ! V_14 )
goto V_55;
F_10 ( V_12 , V_19 , F_11 ( V_14 ) ) ;
if ( V_10 -> V_96 . V_97 ) {
V_14 = F_53 ( V_10 , V_18 ) ;
if ( ! V_14 )
goto V_55;
F_10 ( V_12 , V_19 ,
F_11 ( V_14 ) ) ;
}
return V_46 ;
V_55:
return V_47 ;
}
static T_2 F_56 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_105 * V_66 = (struct V_105 * ) V_11 ;
struct V_1 * V_106 ;
V_106 = F_57 ( V_10 , V_66 ) ;
if ( ! V_106 )
return V_47 ;
F_10 ( V_12 , V_107 ,
F_58 ( V_66 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_106 ) ) ;
return V_46 ;
}
T_2 F_59 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_105 * V_66 = (struct V_105 * ) V_11 ;
if ( V_10 -> V_108 >= V_10 -> V_109 ) {
F_10 ( V_12 , V_110 ,
F_60 ( V_111 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_113 ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_28 ;
}
if ( V_66 -> V_114 & V_115 ) {
if ( V_47 ==
F_56 ( V_8 , V_10 , type , V_11 ,
V_12 ) )
return V_47 ;
F_10 ( V_12 , V_116 ,
F_58 ( V_66 ) ) ;
}
F_10 ( V_12 , V_117 ,
F_58 ( V_66 ) ) ;
F_10 ( V_12 , V_118 ,
F_58 ( V_66 ) ) ;
return V_46 ;
}
T_2 F_62 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
struct V_1 * V_106 ;
T_8 V_119 = 0 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_120 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_2 -> V_48 . V_121 = ( V_122 * ) V_2 -> V_51 -> V_52 ;
V_119 = F_2 ( V_2 -> V_5 -> V_6 ) - sizeof( V_16 ) ;
if ( ! F_45 ( V_2 -> V_51 , V_119 ) )
goto V_55;
V_106 = F_63 ( V_10 , V_2 ,
V_2 -> V_48 . V_121 , V_119 ) ;
if ( ! V_106 )
goto V_55;
F_10 ( V_12 , V_58 , F_35 ( V_106 ) ) ;
return V_46 ;
V_55:
return V_47 ;
}
T_2 F_64 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
union V_123 V_124 ;
struct V_105 * V_125 ;
T_9 * V_126 ;
unsigned long V_127 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_16 ) +
sizeof( T_9 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_126 = ( T_9 * ) V_2 -> V_51 -> V_52 ;
if ( F_2 ( V_126 -> V_53 . V_6 ) !=
sizeof( T_9 ) ) {
return V_128 ;
}
V_124 = V_126 -> V_129 ;
V_125 = F_65 ( V_10 , & V_124 ) ;
if ( F_3 ( ! V_125 ) ) {
if ( V_124 . V_130 . V_131 == V_132 ) {
F_66 ( L_1 ,
V_133 ,
V_10 ,
& V_124 . V_134 . V_135 ) ;
} else {
F_66 ( L_2 ,
V_133 ,
V_10 ,
& V_124 . V_136 . V_137 . V_138 ) ;
}
return V_128 ;
}
if ( V_126 -> V_139 != V_125 -> V_139 )
return V_128 ;
V_127 = V_125 -> V_140 + V_125 -> V_141 ;
if ( F_67 ( V_126 -> V_142 , V_143 ) ||
F_67 ( V_143 , V_126 -> V_142 + V_127 ) ) {
F_68 ( L_3
L_4 ,
V_133 , V_125 ) ;
return V_128 ;
}
F_10 ( V_12 , V_144 , F_58 ( V_125 ) ) ;
return V_46 ;
}
static int F_69 ( union V_123 * V_145 ,
struct V_1 * V_146 ,
T_4 * V_12 )
{
int V_35 ;
struct V_32 * V_147 ;
union V_148 * V_149 ;
struct V_150 * V_151 ;
struct V_7 * V_8 ;
char V_152 [ sizeof( struct V_150 ) + sizeof( union V_148 ) ] ;
struct V_153 * V_154 = F_70 ( V_145 -> V_136 . V_155 ) ;
V_151 = (struct V_150 * ) V_152 ;
V_149 = (union V_148 * ) V_151 -> V_156 ;
V_35 = V_154 -> V_157 ( V_145 , V_149 ) ;
V_35 += sizeof( V_158 ) ;
V_151 -> V_159 = V_160 ;
V_151 -> V_6 = F_71 ( V_35 ) ;
V_8 = F_18 ( ( F_19 () ) ) -> V_8 ;
V_147 = F_23 ( V_8 , NULL , V_146 , V_151 , V_35 ) ;
if ( ! V_147 )
goto V_161;
F_10 ( V_12 , V_44 , F_25 ( V_147 ) ) ;
F_14 ( V_45 ) ;
F_10 ( V_12 , V_162 , F_16 () ) ;
V_161:
return 0 ;
}
static bool F_72 ( const struct V_163 * V_164 ,
union V_123 * V_165 )
{
struct V_105 * V_166 ;
F_73 (addr, list, transports) {
if ( F_74 ( V_165 , & V_166 -> V_165 ) )
return true ;
}
return false ;
}
static int F_75 ( const struct V_9 * V_30 ,
const struct V_9 * V_10 ,
struct V_1 * V_146 ,
T_4 * V_12 )
{
struct V_105 * V_167 ;
int V_90 = 1 ;
F_73 (new_addr, &new_asoc->peer.transport_addr_list,
transports) {
if ( ! F_72 ( & V_10 -> V_96 . V_168 ,
& V_167 -> V_165 ) ) {
F_69 ( & V_167 -> V_165 , V_146 ,
V_12 ) ;
V_90 = 0 ;
break;
}
}
return V_90 ;
}
static void F_76 ( struct V_9 * V_30 ,
const struct V_9 * V_10 )
{
switch ( V_10 -> V_169 ) {
case V_170 :
V_30 -> V_86 . V_171 = V_10 -> V_86 . V_171 ;
V_30 -> V_86 . V_172 = V_10 -> V_86 . V_171 ;
V_30 -> V_86 . V_173 = 0 ;
break;
case V_72 :
V_30 -> V_86 . V_171 = V_10 -> V_86 . V_171 ;
V_30 -> V_86 . V_172 = V_10 -> V_86 . V_171 ;
V_30 -> V_86 . V_173 = V_10 -> V_86 . V_174 ;
break;
default:
V_30 -> V_86 . V_172 = V_10 -> V_86 . V_171 ;
V_30 -> V_86 . V_173 = V_10 -> V_86 . V_174 ;
break;
}
V_30 -> V_175 = V_10 -> V_175 ;
V_30 -> V_86 . V_93 = V_10 -> V_86 . V_93 ;
V_30 -> V_86 . V_94 = V_10 -> V_86 . V_94 ;
V_30 -> V_86 . V_176 = V_10 -> V_86 . V_176 ;
}
static char F_77 ( struct V_9 * V_30 ,
const struct V_9 * V_10 )
{
if ( ( V_10 -> V_86 . V_171 != V_30 -> V_86 . V_171 ) &&
( V_10 -> V_86 . V_174 != V_30 -> V_86 . V_174 ) &&
( V_10 -> V_86 . V_171 == V_30 -> V_86 . V_172 ) &&
( V_10 -> V_86 . V_174 == V_30 -> V_86 . V_173 ) )
return 'A' ;
if ( ( V_10 -> V_86 . V_171 == V_30 -> V_86 . V_171 ) &&
( ( V_10 -> V_86 . V_174 != V_30 -> V_86 . V_174 ) ||
( 0 == V_10 -> V_86 . V_174 ) ) ) {
return 'B' ;
}
if ( ( V_10 -> V_86 . V_171 == V_30 -> V_86 . V_171 ) &&
( V_10 -> V_86 . V_174 == V_30 -> V_86 . V_174 ) )
return 'D' ;
if ( ( V_10 -> V_86 . V_171 != V_30 -> V_86 . V_171 ) &&
( V_10 -> V_86 . V_174 == V_30 -> V_86 . V_174 ) &&
( 0 == V_30 -> V_86 . V_172 ) &&
( 0 == V_30 -> V_86 . V_173 ) )
return 'C' ;
return 'E' ;
}
static T_2 F_78 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 , T_4 * V_12 )
{
T_2 V_177 ;
struct V_1 * V_2 = V_11 ;
struct V_1 * V_29 ;
struct V_9 * V_30 ;
struct V_1 * V_31 ;
struct V_32 * V_33 ;
T_5 * V_34 ;
int V_35 ;
if ( ! V_2 -> V_15 )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( V_2 -> V_37 -> V_38 != 0 )
return F_20 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_39 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_2 -> V_48 . V_49 = ( V_50 * ) V_2 -> V_51 -> V_52 ;
V_2 -> V_53 . V_54 = F_26 ( V_2 -> V_51 , sizeof( V_50 ) ) ;
V_31 = NULL ;
if ( ! F_22 ( V_10 , V_2 -> V_5 -> type ,
( V_39 * ) V_2 -> V_5 , V_2 ,
& V_31 ) ) {
if ( V_31 ) {
V_33 = F_23 ( V_8 , V_10 , V_11 ,
( V_43 * ) ( V_31 -> V_5 ) +
sizeof( V_16 ) ,
F_2 ( V_31 -> V_5 -> V_6 ) -
sizeof( V_16 ) ) ;
if ( V_33 ) {
F_10 ( V_12 , V_44 ,
F_25 ( V_33 ) ) ;
F_14 ( V_45 ) ;
V_177 = V_46 ;
} else {
V_177 = V_47 ;
}
goto V_178;
} else {
return F_20 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
}
}
V_30 = F_27 ( V_8 , V_2 , V_18 ) ;
if ( ! V_30 )
goto V_55;
if ( F_28 ( V_30 ,
F_29 ( F_30 ( V_2 ) ) , V_18 ) < 0 )
goto V_55;
if ( ! F_31 ( V_30 , V_2 , F_30 ( V_2 ) ,
( V_39 * ) V_2 -> V_5 ,
V_18 ) )
goto V_55;
if ( ! F_79 ( V_10 , V_179 ) ) {
if ( ! F_75 ( V_30 , V_10 , V_2 ,
V_12 ) ) {
V_177 = V_46 ;
goto V_180;
}
}
F_76 ( V_30 , V_10 ) ;
V_35 = 0 ;
if ( V_31 ) {
V_35 = F_2 ( V_31 -> V_5 -> V_6 ) -
sizeof( V_16 ) ;
}
V_29 = F_32 ( V_30 , V_2 , V_18 , V_35 ) ;
if ( ! V_29 )
goto V_55;
if ( V_31 ) {
V_34 = ( T_5 * )
( ( V_43 * ) ( V_31 -> V_5 ) +
sizeof( V_16 ) ) ;
F_33 ( V_29 , V_35 , V_34 ) ;
}
F_10 ( V_12 , V_57 , F_34 ( V_30 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_29 ) ) ;
F_10 ( V_12 , V_27 , F_16 () ) ;
V_177 = V_46 ;
return V_177 ;
V_55:
V_177 = V_47 ;
V_180:
if ( V_30 )
F_36 ( V_30 ) ;
V_178:
if ( V_31 )
F_24 ( V_31 ) ;
return V_177 ;
}
T_2 F_80 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return F_78 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_81 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return F_78 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_82 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 , T_4 * V_12 )
{
if ( V_8 == F_18 ( ( F_19 () ) ) -> V_8 )
return F_83 ( V_8 , V_10 , type , V_11 , V_12 ) ;
else
return F_84 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
static T_2 F_85 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
struct V_1 * V_2 ,
T_4 * V_12 ,
struct V_9 * V_30 )
{
V_39 * V_75 ;
struct V_13 * V_14 ;
struct V_1 * V_29 ;
struct V_1 * V_181 ;
T_2 V_182 ;
V_75 = & V_2 -> V_48 . V_81 -> V_86 . V_75 [ 0 ] ;
if ( ! F_31 ( V_30 , V_2 , F_30 ( V_2 ) , V_75 ,
V_18 ) )
goto V_55;
if ( ! F_75 ( V_30 , V_10 , V_2 , V_12 ) ) {
return V_46 ;
}
if ( F_79 ( V_10 , V_183 ) ) {
V_182 = F_86 ( V_8 , V_10 ,
F_87 ( V_2 -> V_5 -> type ) ,
V_2 , V_12 ) ;
if ( V_47 == V_182 )
goto V_55;
V_181 = F_88 ( V_10 , V_2 ,
V_184 ,
NULL , 0 , 0 ) ;
if ( V_181 )
F_10 ( V_12 , V_58 ,
F_35 ( V_181 ) ) ;
return V_46 ;
}
F_10 ( V_12 , V_185 , F_16 () ) ;
F_10 ( V_12 , V_20 ,
F_12 ( V_186 ) ) ;
F_10 ( V_12 , V_187 , F_16 () ) ;
F_10 ( V_12 , V_20 ,
F_12 ( V_188 ) ) ;
F_10 ( V_12 , V_189 , F_16 () ) ;
V_29 = F_52 ( V_30 , V_2 ) ;
if ( ! V_29 )
goto V_55;
V_14 = F_9 ( V_10 , 0 , V_190 , 0 ,
V_30 -> V_86 . V_93 ,
V_30 -> V_86 . V_94 ,
NULL , V_18 ) ;
if ( ! V_14 )
goto V_95;
F_10 ( V_12 , V_191 , F_34 ( V_30 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_29 ) ) ;
F_10 ( V_12 , V_19 , F_11 ( V_14 ) ) ;
return V_46 ;
V_95:
F_24 ( V_29 ) ;
V_55:
return V_47 ;
}
static T_2 F_89 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
struct V_1 * V_2 ,
T_4 * V_12 ,
struct V_9 * V_30 )
{
V_39 * V_75 ;
struct V_1 * V_29 ;
V_75 = & V_2 -> V_48 . V_81 -> V_86 . V_75 [ 0 ] ;
if ( ! F_31 ( V_30 , V_2 , F_30 ( V_2 ) , V_75 ,
V_18 ) )
goto V_55;
F_10 ( V_12 , V_191 , F_34 ( V_30 ) ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_99 ) ) ;
F_14 ( V_26 ) ;
F_10 ( V_12 , V_101 , F_16 () ) ;
V_29 = F_52 ( V_30 , V_2 ) ;
if ( ! V_29 )
goto V_55;
F_10 ( V_12 , V_58 , F_35 ( V_29 ) ) ;
F_10 ( V_12 , V_192 , F_90 ( V_92 ) ) ;
if ( V_10 -> V_96 . V_97 )
F_10 ( V_12 , V_193 , F_16 () ) ;
return V_46 ;
V_55:
return V_47 ;
}
static T_2 F_91 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
struct V_1 * V_2 ,
T_4 * V_12 ,
struct V_9 * V_30 )
{
return V_128 ;
}
static T_2 F_92 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
struct V_1 * V_2 ,
T_4 * V_12 ,
struct V_9 * V_30 )
{
struct V_13 * V_14 = NULL , * V_76 = NULL ;
struct V_1 * V_29 ;
if ( V_10 -> V_169 < V_99 ) {
F_10 ( V_12 , V_20 ,
F_12 ( V_71 ) ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_99 ) ) ;
F_14 ( V_26 ) ;
F_10 ( V_12 , V_101 ,
F_16 () ) ;
V_14 = F_9 ( V_10 , 0 ,
V_92 , 0 ,
V_10 -> V_86 . V_93 ,
V_10 -> V_86 . V_94 ,
NULL , V_18 ) ;
if ( ! V_14 )
goto V_55;
if ( V_10 -> V_96 . V_97 ) {
V_76 = F_53 ( V_10 ,
V_18 ) ;
if ( ! V_76 )
goto V_55;
}
}
V_29 = F_52 ( V_30 , V_2 ) ;
if ( ! V_29 )
goto V_55;
F_10 ( V_12 , V_58 , F_35 ( V_29 ) ) ;
if ( V_14 )
F_10 ( V_12 , V_19 ,
F_11 ( V_14 ) ) ;
if ( V_76 )
F_10 ( V_12 , V_19 ,
F_11 ( V_76 ) ) ;
return V_46 ;
V_55:
if ( V_76 )
F_54 ( V_76 ) ;
if ( V_14 )
F_54 ( V_14 ) ;
return V_47 ;
}
T_2 F_93 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
T_2 V_177 ;
struct V_1 * V_2 = V_11 ;
struct V_9 * V_30 ;
int error = 0 ;
char V_194 ;
struct V_1 * V_77 ;
if ( ! F_1 ( V_2 , sizeof( V_16 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_2 -> V_48 . V_81 = (struct V_82 * ) V_2 -> V_51 -> V_52 ;
if ( ! F_45 ( V_2 -> V_51 , F_2 ( V_2 -> V_5 -> V_6 ) -
sizeof( V_16 ) ) )
goto V_55;
V_30 = F_46 ( V_8 , V_10 , V_2 , V_18 , & error ,
& V_77 ) ;
if ( ! V_30 ) {
switch ( error ) {
case - V_83 :
goto V_55;
case - V_84 :
F_47 ( V_8 , V_10 , V_2 , V_12 ,
V_77 ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
case - V_85 :
default:
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
}
V_194 = F_77 ( V_30 , V_10 ) ;
switch ( V_194 ) {
case 'A' :
V_177 = F_85 ( V_8 , V_10 , V_2 , V_12 ,
V_30 ) ;
break;
case 'B' :
V_177 = F_89 ( V_8 , V_10 , V_2 , V_12 ,
V_30 ) ;
break;
case 'C' :
V_177 = F_91 ( V_8 , V_10 , V_2 , V_12 ,
V_30 ) ;
break;
case 'D' :
V_177 = F_92 ( V_8 , V_10 , V_2 , V_12 ,
V_30 ) ;
break;
default:
V_177 = F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
break;
}
F_10 ( V_12 , V_57 , F_34 ( V_30 ) ) ;
F_10 ( V_12 , V_27 , F_16 () ) ;
F_10 ( V_12 , V_195 ,
F_34 ( (struct V_9 * ) V_10 ) ) ;
return V_177 ;
V_55:
return V_47 ;
}
T_2 F_94 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
if ( ! F_5 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_196 ) ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( V_197 ==
F_95 ( & V_10 -> V_40 . V_198 , & V_2 -> V_199 ) )
return F_84 ( V_8 , V_10 , type , V_11 , V_12 ) ;
return F_96 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_97 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
if ( ! F_5 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_196 ) ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( V_197 ==
F_95 ( & V_10 -> V_40 . V_198 , & V_2 -> V_199 ) )
return F_84 ( V_8 , V_10 , type , V_11 , V_12 ) ;
F_10 ( V_12 , V_20 ,
F_12 ( V_21 ) ) ;
F_10 ( V_12 , V_20 ,
F_12 ( V_22 ) ) ;
return F_96 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_98 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return F_97 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_99 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
V_158 * V_181 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_200 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
F_100 (err, chunk->chunk_hdr) {
if ( V_201 == V_181 -> V_159 )
return F_101 ( V_8 , V_10 , type ,
V_11 , V_12 ) ;
}
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
static T_2 F_101 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
T_10 V_202 ;
T_11 V_203 ;
V_158 * V_181 ;
struct V_1 * V_106 ;
struct V_204 * V_205 ;
int V_206 = V_10 -> V_207 + 1 ;
if ( V_206 > V_10 -> V_208 ) {
F_10 ( V_12 , V_110 ,
F_60 ( V_111 ) ) ;
F_10 ( V_12 , V_209 ,
F_61 ( V_201 ) ) ;
return V_28 ;
}
V_181 = ( V_158 * ) ( V_2 -> V_51 -> V_52 ) ;
V_202 = F_102 ( * ( V_210 * ) ( ( V_211 * ) V_181 + sizeof( V_158 ) ) ) ;
V_202 = ( V_202 * 2 ) / 1000 ;
V_203 . V_53 . type = V_212 ;
V_203 . V_53 . V_6 = F_71 ( sizeof( V_203 ) ) ;
V_203 . V_213 = F_103 ( V_202 ) ;
V_205 = (struct V_204 * ) & V_10 -> V_40 . V_198 ;
V_106 = F_104 ( V_10 , V_205 , V_18 , sizeof( V_203 ) ) ;
if ( ! V_106 )
goto V_55;
F_33 ( V_106 , sizeof( V_203 ) , & V_203 ) ;
F_10 ( V_12 , V_214 , F_16 () ) ;
F_10 ( V_12 , V_185 , F_16 () ) ;
F_10 ( V_12 , V_215 , F_16 () ) ;
F_10 ( V_12 , V_216 , F_16 () ) ;
F_10 ( V_12 , V_217 ,
F_58 ( V_10 -> V_96 . V_218 ) ) ;
F_10 ( V_12 , V_219 , F_16 () ) ;
F_10 ( V_12 , V_20 ,
F_12 ( V_71 ) ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_170 ) ) ;
F_10 ( V_12 , V_70 ,
F_12 ( V_69 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_106 ) ) ;
return V_46 ;
V_55:
return V_47 ;
}
T_2 F_105 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
if ( ! F_5 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_196 ) ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( V_197 ==
F_95 ( & V_10 -> V_40 . V_198 , & V_2 -> V_199 ) )
return F_84 ( V_8 , V_10 , type , V_11 , V_12 ) ;
return F_96 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
static T_2 F_96 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
unsigned int V_35 ;
T_12 error = V_113 ;
V_35 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_35 >= sizeof( struct V_220 ) + sizeof( struct V_150 ) ) {
V_158 * V_181 ;
F_100 ( V_181 , V_2 -> V_5 ) ;
if ( ( void * ) V_181 != ( void * ) V_2 -> V_221 )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
error = ( ( V_158 * ) V_2 -> V_51 -> V_52 ) -> V_159 ;
}
F_10 ( V_12 , V_110 , F_60 ( V_222 ) ) ;
F_10 ( V_12 , V_112 , F_61 ( error ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_223 ;
}
T_2 F_106 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
unsigned int V_35 ;
T_12 error = V_113 ;
if ( ! F_5 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_196 ) ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
V_35 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_35 >= sizeof( struct V_220 ) + sizeof( struct V_150 ) )
error = ( ( V_158 * ) V_2 -> V_51 -> V_52 ) -> V_159 ;
return F_40 ( V_12 , error , V_65 , V_10 ,
V_2 -> V_66 ) ;
}
T_2 F_107 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return F_40 ( V_12 , V_113 ,
V_224 , V_10 ,
(struct V_105 * ) V_11 ) ;
}
T_2 F_108 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return F_106 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
static T_2 F_40 ( T_4 * V_12 ,
T_12 error , int V_225 ,
const struct V_9 * V_10 ,
struct V_105 * V_66 )
{
F_68 ( L_5 ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_24 ) ) ;
F_14 ( V_64 ) ;
F_10 ( V_12 , V_20 ,
F_12 ( V_69 ) ) ;
F_10 ( V_12 , V_110 , F_60 ( V_225 ) ) ;
F_10 ( V_12 , V_209 ,
F_61 ( error ) ) ;
return V_223 ;
}
T_2 F_109 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
T_13 * V_226 ;
T_2 V_182 ;
struct V_13 * V_14 ;
T_14 V_227 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 ,
sizeof( struct V_228 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_226 = ( T_13 * ) V_2 -> V_51 -> V_52 ;
F_26 ( V_2 -> V_51 , sizeof( T_13 ) ) ;
V_2 -> V_48 . V_229 = V_226 ;
V_227 = F_102 ( V_226 -> V_230 ) ;
if ( F_110 ( V_227 , V_10 -> V_231 ) ) {
F_68 ( L_6 , V_227 ) ;
F_68 ( L_7 , V_10 -> V_231 ) ;
return V_128 ;
}
if ( ! F_110 ( V_227 , V_10 -> V_232 ) )
return F_111 ( V_8 , V_10 , type , V_11 , V_12 ) ;
V_14 = F_112 ( V_10 , 0 , V_18 ) ;
if ( ! V_14 ) {
V_182 = V_47 ;
goto V_161;
}
F_10 ( V_12 , V_19 , F_11 ( V_14 ) ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_233 ) ) ;
V_182 = V_46 ;
if ( F_113 ( & V_10 -> V_234 ) ) {
V_182 = F_114 ( V_8 , V_10 , type ,
V_11 , V_12 ) ;
}
if ( V_47 == V_182 )
goto V_161;
F_10 ( V_12 , V_235 ,
F_115 ( V_2 -> V_48 . V_229 -> V_230 ) ) ;
V_161:
return V_182 ;
}
T_2 F_116 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
T_13 * V_226 ;
T_14 V_227 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 ,
sizeof( struct V_228 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_226 = ( T_13 * ) V_2 -> V_51 -> V_52 ;
V_227 = F_102 ( V_226 -> V_230 ) ;
if ( F_110 ( V_227 , V_10 -> V_231 ) ) {
F_68 ( L_6 , V_227 ) ;
F_68 ( L_7 , V_10 -> V_231 ) ;
return V_128 ;
}
if ( ! F_110 ( V_227 , V_10 -> V_232 ) )
return F_111 ( V_8 , V_10 , type , V_11 , V_12 ) ;
F_10 ( V_12 , V_235 ,
F_115 ( V_226 -> V_230 ) ) ;
return V_46 ;
}
T_2 F_86 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = (struct V_1 * ) V_11 ;
struct V_1 * V_106 ;
if ( ! F_1 ( V_2 , sizeof( V_16 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_106 = F_117 ( V_10 , V_2 ) ;
if ( NULL == V_106 )
goto V_55;
F_10 ( V_12 , V_236 , F_35 ( V_106 ) ) ;
F_10 ( V_12 , V_237 ,
F_12 ( V_21 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_106 ) ) ;
return V_46 ;
V_55:
return V_47 ;
}
T_2 F_118 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
T_15 * V_238 ;
struct V_1 * V_2 = V_11 ;
T_16 V_239 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_240 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_238 = ( T_15 * ) V_2 -> V_51 -> V_52 ;
F_26 ( V_2 -> V_51 , sizeof( T_15 ) ) ;
V_239 = F_102 ( V_238 -> V_239 ) ;
if ( F_119 ( V_10 -> V_241 , V_239 ) ) {
F_10 ( V_12 ,
V_242 ,
F_120 ( V_239 ) ) ;
}
return V_46 ;
}
T_2 F_121 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
T_17 * V_243 ;
struct V_1 * V_2 = V_11 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_240 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_243 = ( T_17 * ) V_2 -> V_51 -> V_52 ;
F_26 ( V_2 -> V_51 , sizeof( T_17 ) ) ;
F_10 ( V_12 , V_244 ,
F_120 ( F_102 ( V_243 -> V_239 ) ) ) ;
return V_46 ;
}
T_2 F_122 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
T_18 V_245 = F_123 () ;
int error ;
if ( ! F_38 ( V_2 , V_10 ) ) {
F_10 ( V_12 , V_246 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! F_1 ( V_2 , sizeof( V_247 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
error = F_124 ( V_10 , V_2 , V_12 ) ;
switch ( error ) {
case V_91 :
break;
case V_248 :
case V_249 :
F_14 ( V_250 ) ;
goto V_251;
case V_252 :
case V_253 :
F_14 ( V_250 ) ;
goto V_254;
case V_255 :
goto V_256;
case V_257 :
return F_125 ( V_8 , V_10 , V_2 , V_12 ,
( V_211 * ) V_2 -> V_48 . V_258 , sizeof( V_259 ) ) ;
default:
F_126 () ;
}
if ( V_2 -> V_5 -> V_260 & V_261 )
V_245 = F_127 () ;
if ( V_10 -> V_102 ) {
F_10 ( V_12 , V_237 ,
F_12 ( V_103 ) ) ;
}
if ( V_2 -> V_262 )
F_10 ( V_12 , V_263 , V_245 ) ;
return V_46 ;
V_254:
if ( V_2 -> V_262 )
F_10 ( V_12 , V_263 , F_127 () ) ;
return V_128 ;
V_251:
if ( V_2 -> V_262 )
F_10 ( V_12 , V_263 , V_245 ) ;
return V_128 ;
V_256:
return V_46 ;
}
T_2 F_128 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
int error ;
if ( ! F_38 ( V_2 , V_10 ) ) {
F_10 ( V_12 , V_246 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! F_1 ( V_2 , sizeof( V_247 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
error = F_124 ( V_10 , V_2 , V_12 ) ;
switch ( error ) {
case V_91 :
case V_248 :
case V_252 :
case V_253 :
case V_249 :
break;
case V_255 :
goto V_256;
case V_257 :
return F_125 ( V_8 , V_10 , V_2 , V_12 ,
( V_211 * ) V_2 -> V_48 . V_258 , sizeof( V_259 ) ) ;
default:
F_126 () ;
}
if ( V_2 -> V_262 ) {
F_10 ( V_12 , V_264 , F_16 () ) ;
F_10 ( V_12 , V_263 , F_127 () ) ;
F_10 ( V_12 , V_237 ,
F_12 ( V_21 ) ) ;
}
V_256:
return V_46 ;
}
T_2 F_129 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
T_19 * V_265 ;
T_14 V_227 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_266 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_265 = F_130 ( V_2 ) ;
if ( ! V_265 )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
V_2 -> V_48 . V_267 = V_265 ;
V_227 = F_102 ( V_265 -> V_230 ) ;
if ( F_110 ( V_227 , V_10 -> V_231 ) ) {
F_68 ( L_6 , V_227 ) ;
F_68 ( L_7 , V_10 -> V_231 ) ;
return V_128 ;
}
if ( ! F_110 ( V_227 , V_10 -> V_232 ) )
return F_111 ( V_8 , V_10 , type , V_11 , V_12 ) ;
F_10 ( V_12 , V_268 , F_131 ( V_265 ) ) ;
return V_46 ;
}
static T_2 F_20 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_32 * V_33 = NULL ;
struct V_1 * V_2 = V_11 ;
struct V_1 * abort ;
V_33 = F_132 ( V_10 , V_2 ) ;
if ( V_33 ) {
abort = F_133 ( V_10 , V_2 , 0 ) ;
if ( ! abort ) {
F_134 ( V_33 ) ;
return V_47 ;
}
if ( F_135 ( abort ) )
V_33 -> V_38 = F_102 ( V_2 -> V_37 -> V_38 ) ;
abort -> V_51 -> V_41 = V_8 -> V_40 . V_41 ;
F_136 ( V_33 , abort ) ;
F_10 ( V_12 , V_44 ,
F_25 ( V_33 ) ) ;
F_14 ( V_45 ) ;
F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
return V_46 ;
}
return V_47 ;
}
T_2 F_137 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
V_158 * V_181 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_200 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
F_100 ( V_181 , V_2 -> V_5 ) ;
if ( ( void * ) V_181 != ( void * ) V_2 -> V_221 )
return F_138 ( V_8 , V_10 , type , V_11 ,
( void * ) V_181 , V_12 ) ;
F_10 ( V_12 , V_269 ,
F_35 ( V_2 ) ) ;
return V_46 ;
}
T_2 F_139 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
struct V_1 * V_106 ;
struct V_13 * V_14 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_16 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_14 = F_9 ( V_10 , 0 , V_17 ,
0 , 0 , 0 , NULL , V_18 ) ;
if ( ! V_14 )
goto V_55;
V_106 = F_140 ( V_10 , V_2 ) ;
if ( ! V_106 )
goto V_270;
F_10 ( V_12 , V_19 , F_11 ( V_14 ) ) ;
F_10 ( V_12 , V_20 ,
F_12 ( V_21 ) ) ;
F_10 ( V_12 , V_20 ,
F_12 ( V_22 ) ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_24 ) ) ;
F_14 ( V_25 ) ;
F_15 ( V_26 ) ;
F_10 ( V_12 , V_58 , F_35 ( V_106 ) ) ;
F_10 ( V_12 , V_27 , F_16 () ) ;
return V_28 ;
V_270:
F_54 ( V_14 ) ;
V_55:
return V_47 ;
}
T_2 F_83 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
struct V_271 * V_51 = V_2 -> V_51 ;
V_16 * V_272 ;
V_158 * V_181 ;
V_43 * V_273 ;
int V_274 = 0 ;
int V_275 = 0 ;
F_14 ( V_36 ) ;
V_272 = ( V_16 * ) V_2 -> V_5 ;
do {
if ( F_2 ( V_272 -> V_6 ) < sizeof( V_16 ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
if ( V_276 == V_272 -> type )
V_274 = 1 ;
if ( V_63 == V_272 -> type )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( V_277 == V_272 -> type )
V_275 = 1 ;
if ( V_278 == V_272 -> type ) {
F_100 (err, ch) {
if ( V_201 == V_181 -> V_159 ) {
V_275 = 1 ;
break;
}
}
}
V_273 = ( ( V_43 * ) V_272 ) + F_141 ( F_2 ( V_272 -> V_6 ) ) ;
if ( V_273 > F_142 ( V_51 ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_272 = ( V_16 * ) V_273 ;
} while ( V_273 < F_142 ( V_51 ) );
if ( V_274 )
return F_143 ( V_8 , V_10 , type , V_11 , V_12 ) ;
else if ( V_275 )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
else
return F_20 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
static T_2 F_143 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_32 * V_33 = NULL ;
struct V_1 * V_2 = V_11 ;
struct V_1 * V_279 ;
V_33 = F_132 ( V_10 , V_2 ) ;
if ( V_33 ) {
V_279 = F_140 ( V_10 , V_2 ) ;
if ( ! V_279 ) {
F_134 ( V_33 ) ;
return V_47 ;
}
if ( F_135 ( V_279 ) )
V_33 -> V_38 = F_102 ( V_2 -> V_37 -> V_38 ) ;
V_279 -> V_51 -> V_41 = V_8 -> V_40 . V_41 ;
F_136 ( V_33 , V_279 ) ;
F_10 ( V_12 , V_44 ,
F_25 ( V_33 ) ) ;
F_14 ( V_45 ) ;
if ( ! F_1 ( V_2 , sizeof( V_16 ) ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
return V_47 ;
}
T_2 F_144 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
if ( ! F_1 ( V_2 , sizeof( V_16 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
F_14 ( V_36 ) ;
return F_143 ( V_8 , NULL , type , V_11 , V_12 ) ;
}
T_2 F_145 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type , void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
struct V_1 * V_280 = NULL ;
struct V_281 * V_282 = NULL ;
T_20 * V_283 ;
union V_148 * V_284 ;
T_14 V_285 ;
int V_6 ;
if ( ! F_38 ( V_2 , V_10 ) ) {
F_10 ( V_12 , V_246 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! V_286 && ! V_2 -> V_89 )
return F_84 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_287 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_283 = ( T_20 * ) V_2 -> V_51 -> V_52 ;
V_285 = F_102 ( V_283 -> V_285 ) ;
V_284 = (union V_148 * ) V_283 -> V_288 ;
V_6 = F_2 ( V_284 -> V_289 . V_6 ) ;
if ( V_6 < sizeof( V_290 ) )
return F_138 ( V_8 , V_10 , type , V_11 ,
( void * ) V_284 , V_12 ) ;
if ( ! F_146 ( V_10 ,
( V_290 * ) ( ( void * ) V_284 + V_6 ) ,
( void * ) V_2 -> V_221 ,
& V_282 ) )
return F_138 ( V_8 , V_10 , type , V_11 ,
( void * ) V_282 , V_12 ) ;
if ( V_285 == V_10 -> V_96 . V_291 + 1 ) {
if ( ! V_2 -> V_292 )
F_147 ( V_10 ) ;
V_280 = F_148 ( (struct V_9 * )
V_10 , V_2 ) ;
if ( ! V_280 )
return V_47 ;
} else if ( V_285 < V_10 -> V_96 . V_291 + 1 ) {
V_280 = F_149 ( V_10 , V_283 -> V_285 ) ;
if ( ! V_280 )
return V_128 ;
V_280 -> V_66 = NULL ;
} else {
return V_128 ;
}
V_280 -> V_199 = V_2 -> V_293 ;
F_10 ( V_12 , V_58 , F_35 ( V_280 ) ) ;
if ( V_10 -> V_294 ) {
F_56 ( V_8 , V_10 , type , V_10 -> V_294 ,
V_12 ) ;
( (struct V_9 * ) V_10 ) -> V_294 = NULL ;
}
return V_46 ;
}
T_2 F_150 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type , void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_280 = V_11 ;
struct V_1 * V_295 = V_10 -> V_296 ;
struct V_1 * abort ;
struct V_281 * V_282 = NULL ;
T_20 * V_297 ;
T_14 V_298 , V_299 ;
if ( ! F_38 ( V_280 , V_10 ) ) {
F_10 ( V_12 , V_246 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! V_286 && ! V_280 -> V_89 )
return F_84 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_280 , sizeof( V_287 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_297 = ( T_20 * ) V_280 -> V_51 -> V_52 ;
V_299 = F_102 ( V_297 -> V_285 ) ;
if ( ! F_146 ( V_10 ,
( V_290 * ) V_297 -> V_288 ,
( void * ) V_280 -> V_221 ,
& V_282 ) )
return F_138 ( V_8 , V_10 , type , V_11 ,
( void * ) V_282 , V_12 ) ;
if ( V_295 ) {
V_297 = ( T_20 * ) V_295 -> V_48 . V_297 ;
V_298 = F_102 ( V_297 -> V_285 ) ;
} else {
V_298 = V_10 -> V_291 - 1 ;
}
if ( F_151 ( V_299 , V_298 + 1 ) &&
! ( V_10 -> V_296 ) ) {
abort = F_133 ( V_10 , V_280 ,
sizeof( V_158 ) ) ;
if ( abort ) {
F_152 ( abort , V_300 , 0 ) ;
F_10 ( V_12 , V_58 ,
F_35 ( abort ) ) ;
}
F_10 ( V_12 , V_20 ,
F_12 ( V_188 ) ) ;
F_10 ( V_12 , V_162 , F_16 () ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_301 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_300 ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_223 ;
}
if ( ( V_299 == V_298 ) && V_10 -> V_296 ) {
F_10 ( V_12 , V_20 ,
F_12 ( V_188 ) ) ;
if ( ! F_153 ( (struct V_9 * ) V_10 ,
V_280 ) ) {
F_10 ( V_12 , V_302 ,
F_16 () ) ;
return V_46 ;
}
abort = F_133 ( V_10 , V_280 ,
sizeof( V_158 ) ) ;
if ( abort ) {
F_152 ( abort , V_303 , 0 ) ;
F_10 ( V_12 , V_58 ,
F_35 ( abort ) ) ;
}
F_10 ( V_12 , V_162 , F_16 () ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_301 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_300 ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_223 ;
}
return V_128 ;
}
T_2 F_154 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
struct V_304 * V_305 ;
struct V_306 * V_307 ;
T_1 V_35 ;
T_14 V_308 ;
if ( ! F_38 ( V_2 , V_10 ) ) {
F_10 ( V_12 , V_246 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_309 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_305 = (struct V_304 * ) V_2 -> V_51 -> V_52 ;
V_2 -> V_48 . V_305 = V_305 ;
V_35 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_35 -= sizeof( struct V_220 ) ;
F_26 ( V_2 -> V_51 , V_35 ) ;
V_308 = F_102 ( V_305 -> V_310 ) ;
F_68 ( L_8 , V_133 , V_308 ) ;
if ( F_155 ( & V_10 -> V_96 . V_311 , V_308 ) < 0 )
goto V_251;
F_156 (skip, chunk) {
if ( F_2 ( V_307 -> V_312 ) >= V_10 -> V_86 . V_94 )
goto V_251;
}
F_10 ( V_12 , V_313 , F_120 ( V_308 ) ) ;
if ( V_35 > sizeof( struct V_304 ) )
F_10 ( V_12 , V_314 ,
F_35 ( V_2 ) ) ;
if ( V_10 -> V_102 ) {
F_10 ( V_12 , V_237 ,
F_12 ( V_103 ) ) ;
}
F_10 ( V_12 , V_263 , F_123 () ) ;
return V_46 ;
V_251:
return V_128 ;
}
T_2 F_157 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
struct V_304 * V_305 ;
struct V_306 * V_307 ;
T_1 V_35 ;
T_14 V_308 ;
if ( ! F_38 ( V_2 , V_10 ) ) {
F_10 ( V_12 , V_246 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_309 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_305 = (struct V_304 * ) V_2 -> V_51 -> V_52 ;
V_2 -> V_48 . V_305 = V_305 ;
V_35 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_35 -= sizeof( struct V_220 ) ;
F_26 ( V_2 -> V_51 , V_35 ) ;
V_308 = F_102 ( V_305 -> V_310 ) ;
F_68 ( L_8 , V_133 , V_308 ) ;
if ( F_155 ( & V_10 -> V_96 . V_311 , V_308 ) < 0 )
goto V_315;
F_156 (skip, chunk) {
if ( F_2 ( V_307 -> V_312 ) >= V_10 -> V_86 . V_94 )
goto V_315;
}
F_10 ( V_12 , V_313 , F_120 ( V_308 ) ) ;
if ( V_35 > sizeof( struct V_304 ) )
F_10 ( V_12 , V_314 ,
F_35 ( V_2 ) ) ;
V_315:
F_10 ( V_12 , V_264 , F_16 () ) ;
F_10 ( V_12 , V_263 , F_127 () ) ;
F_10 ( V_12 , V_237 ,
F_12 ( V_21 ) ) ;
return V_46 ;
}
static T_7 F_50 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
struct V_1 * V_2 )
{
struct V_316 * V_317 ;
struct V_318 * V_319 ;
unsigned int V_320 ;
T_1 V_321 ;
V_43 * V_322 ;
V_43 * V_323 ;
V_317 = (struct V_316 * ) V_2 -> V_51 -> V_52 ;
V_2 -> V_48 . V_317 = V_317 ;
F_26 ( V_2 -> V_51 , sizeof( struct V_316 ) ) ;
if ( ! F_158 ( V_10 , V_317 -> V_324 ) )
return V_325 ;
V_321 = F_2 ( V_317 -> V_326 ) ;
if ( V_321 != V_10 -> V_327 && ! F_159 ( V_10 , V_321 ) )
return V_328 ;
V_320 = F_2 ( V_2 -> V_5 -> V_6 ) - sizeof( V_329 ) ;
V_319 = F_160 ( F_2 ( V_317 -> V_324 ) ) ;
if ( V_320 != V_319 -> V_330 )
return V_257 ;
V_323 = V_317 -> V_319 ;
F_26 ( V_2 -> V_51 , V_320 ) ;
V_322 = F_161 ( V_323 , V_320 , V_18 ) ;
if ( ! V_322 )
goto V_55;
memset ( V_323 , 0 , V_320 ) ;
F_162 ( V_10 , V_2 -> V_51 ,
(struct V_331 * ) V_2 -> V_5 ,
V_18 ) ;
if ( memcmp ( V_322 , V_323 , V_320 ) ) {
F_163 ( V_322 ) ;
return V_85 ;
}
F_163 ( V_322 ) ;
V_2 -> V_89 = 1 ;
return V_91 ;
V_55:
return V_83 ;
}
T_2 F_164 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_316 * V_317 ;
struct V_1 * V_2 = V_11 ;
struct V_1 * V_31 ;
T_7 error ;
if ( ! V_10 -> V_96 . V_332 )
return F_165 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_38 ( V_2 , V_10 ) ) {
F_10 ( V_12 , V_246 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_331 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_317 = (struct V_316 * ) V_2 -> V_51 -> V_52 ;
error = F_50 ( V_8 , V_10 , type , V_2 ) ;
switch ( error ) {
case V_325 :
V_31 = F_88 ( V_10 , V_2 ,
V_333 ,
& V_317 -> V_324 ,
sizeof( T_1 ) , 0 ) ;
if ( V_31 ) {
F_10 ( V_12 , V_58 ,
F_35 ( V_31 ) ) ;
}
case V_328 :
case V_85 :
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
case V_257 :
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
case V_83 :
return V_47 ;
default:
break;
}
if ( V_10 -> V_327 != F_2 ( V_317 -> V_326 ) ) {
struct V_13 * V_14 ;
V_14 = F_166 ( V_10 , F_2 ( V_317 -> V_326 ) ,
V_334 , V_18 ) ;
if ( ! V_14 )
return - V_335 ;
F_10 ( V_12 , V_19 ,
F_11 ( V_14 ) ) ;
}
return V_46 ;
}
T_2 F_165 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_336 = V_11 ;
struct V_1 * V_31 ;
V_16 * V_283 ;
F_68 ( L_9 , type . V_2 ) ;
if ( ! F_38 ( V_336 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_336 , sizeof( V_16 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
switch ( type . V_2 & V_337 ) {
case V_338 :
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
break;
case V_339 :
V_283 = V_336 -> V_5 ;
V_31 = F_88 ( V_10 , V_336 ,
V_340 , V_283 ,
F_141 ( F_2 ( V_283 -> V_6 ) ) ,
0 ) ;
if ( V_31 ) {
F_10 ( V_12 , V_58 ,
F_35 ( V_31 ) ) ;
}
F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
return V_46 ;
break;
case V_341 :
return V_128 ;
break;
case V_342 :
V_283 = V_336 -> V_5 ;
V_31 = F_88 ( V_10 , V_336 ,
V_340 , V_283 ,
F_141 ( F_2 ( V_283 -> V_6 ) ) ,
0 ) ;
if ( V_31 ) {
F_10 ( V_12 , V_58 ,
F_35 ( V_31 ) ) ;
}
return V_46 ;
break;
default:
break;
}
return V_128 ;
}
T_2 F_84 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
if ( ! F_1 ( V_2 , sizeof( V_16 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
F_68 ( L_10 , type . V_2 ) ;
return V_128 ;
}
T_2 F_6 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_14 ( V_343 ) ;
F_10 ( V_12 , V_162 , F_16 () ) ;
return V_46 ;
}
T_2 F_167 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
if ( ! F_1 ( V_2 , sizeof( V_16 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
return V_344 ;
}
static T_2 F_125 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
void * V_11 ,
T_4 * V_12 ,
const V_43 * V_345 ,
const T_8 V_119 )
{
struct V_32 * V_33 = NULL ;
struct V_1 * V_2 = V_11 ;
struct V_1 * abort = NULL ;
if ( F_39 ( V_63 , V_10 ) )
goto V_346;
abort = F_168 ( V_10 , V_2 , V_345 , V_119 ) ;
if ( ! abort )
goto V_55;
if ( V_10 ) {
if ( V_2 -> V_5 -> type == V_347 &&
! V_10 -> V_96 . V_348 . V_349 ) {
V_60 * V_350 ;
V_350 = ( V_60 * ) V_2 -> V_5 ;
if ( ! F_1 ( V_2 ,
sizeof( V_60 ) ) )
abort -> V_5 -> V_260 |= V_351 ;
else {
unsigned int V_352 ;
V_352 = F_102 ( V_350 -> V_49 . V_349 ) ;
F_10 ( V_12 , V_353 ,
F_120 ( V_352 ) ) ;
}
}
F_10 ( V_12 , V_58 , F_35 ( abort ) ) ;
F_14 ( V_45 ) ;
if ( V_10 -> V_169 <= V_72 ) {
F_10 ( V_12 , V_20 ,
F_12 ( V_69 ) ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_65 ) ) ;
F_10 ( V_12 , V_209 ,
F_61 ( V_354 ) ) ;
} else {
F_10 ( V_12 , V_110 ,
F_60 ( V_301 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_354 ) ) ;
F_15 ( V_26 ) ;
}
} else {
V_33 = F_132 ( V_10 , V_2 ) ;
if ( ! V_33 )
goto V_355;
if ( F_135 ( abort ) )
V_33 -> V_38 = F_102 ( V_2 -> V_37 -> V_38 ) ;
abort -> V_51 -> V_41 = V_8 -> V_40 . V_41 ;
F_136 ( V_33 , abort ) ;
F_10 ( V_12 , V_44 ,
F_25 ( V_33 ) ) ;
F_14 ( V_45 ) ;
}
F_14 ( V_64 ) ;
V_346:
F_6 ( V_8 , V_10 , F_87 ( 0 ) , V_11 , V_12 ) ;
return V_223 ;
V_355:
F_24 ( abort ) ;
V_55:
return V_47 ;
}
static T_2 F_8 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
static const char V_356 [] = L_11 ;
return F_125 ( V_8 , V_10 , V_11 , V_12 , V_356 ,
sizeof( V_356 ) ) ;
}
static T_2 F_138 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 , void * V_357 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
struct V_281 * V_358 = V_357 ;
struct V_1 * abort = NULL ;
if ( F_39 ( V_63 , V_10 ) )
goto V_346;
abort = F_169 ( V_10 , V_2 , V_358 ) ;
if ( ! abort )
goto V_55;
F_10 ( V_12 , V_58 , F_35 ( abort ) ) ;
F_14 ( V_45 ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_301 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_354 ) ) ;
F_15 ( V_26 ) ;
F_14 ( V_64 ) ;
V_346:
F_6 ( V_8 , V_10 , F_87 ( 0 ) , V_11 , V_12 ) ;
return V_223 ;
V_55:
return V_47 ;
}
static T_2 F_111 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
static const char V_356 [] = L_12 ;
return F_125 ( V_8 , V_10 , V_11 , V_12 , V_356 ,
sizeof( V_356 ) ) ;
}
static T_2 F_7 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
static const char V_356 [] = L_13 ;
if ( ! V_10 )
return F_167 ( V_8 , V_10 , type , V_11 , V_12 ) ;
return F_125 ( V_8 , V_10 , V_11 , V_12 , V_356 ,
sizeof( V_356 ) ) ;
}
T_2 F_170 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_29 ;
struct V_9 * V_359 ;
F_10 ( V_12 , V_23 ,
F_13 ( V_170 ) ) ;
V_29 = F_104 ( V_10 , & V_10 -> V_40 . V_198 , V_18 , 0 ) ;
if ( ! V_29 )
goto V_55;
V_359 = (struct V_9 * ) V_10 ;
F_10 ( V_12 , V_57 , F_34 ( V_359 ) ) ;
F_10 ( V_12 , V_360 ,
F_35 ( V_29 ) ) ;
F_10 ( V_12 , V_70 ,
F_12 ( V_69 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_29 ) ) ;
return V_46 ;
V_55:
return V_47 ;
}
T_2 F_171 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_361 * V_362 = V_11 ;
F_10 ( V_12 , V_363 , F_172 ( V_362 ) ) ;
return V_46 ;
}
T_2 F_173 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
int V_182 ;
F_10 ( V_12 , V_23 ,
F_13 ( V_364 ) ) ;
V_182 = V_46 ;
if ( F_113 ( & V_10 -> V_234 ) ) {
V_182 = F_174 ( V_8 , V_10 , type ,
V_11 , V_12 ) ;
}
return V_182 ;
}
T_2 F_175 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * abort = V_11 ;
T_2 V_177 ;
V_177 = V_46 ;
F_10 ( V_12 , V_58 , F_35 ( abort ) ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_301 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_365 ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_177 ;
}
T_2 F_176 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_10 ( V_12 , V_366 , F_60 ( - V_367 ) ) ;
return V_46 ;
}
T_2 F_177 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_10 ( V_12 , V_366 ,
F_60 ( - V_368 ) ) ;
return V_46 ;
}
T_2 F_178 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_10 ( V_12 , V_20 ,
F_12 ( V_69 ) ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_24 ) ) ;
F_14 ( V_25 ) ;
F_10 ( V_12 , V_27 , F_16 () ) ;
return V_28 ;
}
T_2 F_179 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 , T_4 * V_12 )
{
return F_178 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_180 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * abort = V_11 ;
T_2 V_177 ;
F_10 ( V_12 , V_20 ,
F_12 ( V_69 ) ) ;
V_177 = V_46 ;
F_10 ( V_12 , V_58 , F_35 ( abort ) ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_24 ) ) ;
F_14 ( V_64 ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_65 ) ) ;
F_10 ( V_12 , V_209 ,
F_61 ( V_365 ) ) ;
return V_177 ;
}
T_2 F_181 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return F_180 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_182 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_10 ( V_12 , V_20 ,
F_12 ( V_22 ) ) ;
return F_175 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_183 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_10 ( V_12 , V_20 ,
F_12 ( V_21 ) ) ;
F_10 ( V_12 , V_20 ,
F_12 ( V_22 ) ) ;
return F_175 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_184 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return F_183 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_185 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
if ( V_47 == F_56 ( V_8 , V_10 , type ,
(struct V_105 * ) V_11 , V_12 ) )
return V_47 ;
F_10 ( V_12 , V_116 ,
F_58 ( V_11 ) ) ;
return V_46 ;
}
T_2 F_186 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
F_10 ( V_12 , V_369 , F_35 ( V_2 ) ) ;
F_10 ( V_12 , V_70 ,
F_12 ( V_188 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_2 ) ) ;
return V_46 ;
}
T_2 F_187 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_68 ( L_14 , type . V_370 ) ;
return V_128 ;
}
T_2 F_188 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_13 * V_371 ;
V_371 = F_189 ( V_10 , V_18 ) ;
if ( ! V_371 )
return V_47 ;
F_10 ( V_12 , V_19 , F_11 ( V_371 ) ) ;
return V_46 ;
}
T_2 F_174 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_106 ;
V_106 = F_190 ( V_10 , NULL ) ;
if ( ! V_106 )
goto V_55;
F_10 ( V_12 , V_236 , F_35 ( V_106 ) ) ;
F_10 ( V_12 , V_70 ,
F_12 ( V_21 ) ) ;
F_10 ( V_12 , V_237 ,
F_12 ( V_22 ) ) ;
if ( V_10 -> V_102 )
F_10 ( V_12 , V_20 ,
F_12 ( V_103 ) ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_372 ) ) ;
F_10 ( V_12 , V_215 , F_16 () ) ;
F_10 ( V_12 , V_58 , F_35 ( V_106 ) ) ;
return V_46 ;
V_55:
return V_47 ;
}
T_2 F_114 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = (struct V_1 * ) V_11 ;
struct V_1 * V_106 ;
if ( V_2 ) {
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( struct V_228 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
}
V_106 = F_117 ( V_10 , V_2 ) ;
if ( ! V_106 )
goto V_55;
F_10 ( V_12 , V_236 , F_35 ( V_106 ) ) ;
F_10 ( V_12 , V_237 ,
F_12 ( V_21 ) ) ;
if ( V_10 -> V_102 )
F_10 ( V_12 , V_20 ,
F_12 ( V_103 ) ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_373 ) ) ;
F_10 ( V_12 , V_215 , F_16 () ) ;
F_10 ( V_12 , V_58 , F_35 ( V_106 ) ) ;
return V_46 ;
V_55:
return V_47 ;
}
T_2 F_191 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_68 ( L_15 , type . V_374 ) ;
return V_128 ;
}
T_2 F_192 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_105 * V_66 = V_11 ;
F_14 ( V_375 ) ;
if ( V_10 -> V_108 >= V_10 -> V_109 ) {
if ( V_10 -> V_169 == V_364 ) {
F_10 ( V_12 , V_376 ,
F_12 ( V_22 ) ) ;
} else {
F_10 ( V_12 , V_110 ,
F_60 ( V_111 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_113 ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_28 ;
}
}
F_10 ( V_12 , V_377 , F_58 ( V_66 ) ) ;
F_10 ( V_12 , V_378 , F_58 ( V_66 ) ) ;
return V_46 ;
}
T_2 F_193 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_14 ( V_379 ) ;
F_10 ( V_12 , V_263 , F_127 () ) ;
return V_46 ;
}
T_2 F_194 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_29 = NULL ;
struct V_204 * V_205 ;
int V_206 = V_10 -> V_207 + 1 ;
F_68 ( L_16 ) ;
F_14 ( V_380 ) ;
if ( V_206 <= V_10 -> V_208 ) {
V_205 = (struct V_204 * ) & V_10 -> V_40 . V_198 ;
V_29 = F_104 ( V_10 , V_205 , V_18 , 0 ) ;
if ( ! V_29 )
return V_47 ;
F_10 ( V_12 , V_360 ,
F_35 ( V_29 ) ) ;
F_10 ( V_12 , V_381 ,
F_12 ( V_69 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_29 ) ) ;
} else {
F_68 ( L_17
L_18 ,
V_206 , V_10 -> V_208 ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_111 ) ) ;
F_10 ( V_12 , V_209 ,
F_61 ( V_113 ) ) ;
return V_28 ;
}
return V_46 ;
}
T_2 F_195 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_29 = NULL ;
int V_206 = V_10 -> V_207 + 1 ;
F_68 ( L_19 ) ;
F_14 ( V_382 ) ;
if ( V_206 <= V_10 -> V_208 ) {
V_29 = F_196 ( V_10 , NULL ) ;
if ( ! V_29 )
return V_47 ;
F_10 ( V_12 , V_360 ,
F_35 ( V_29 ) ) ;
F_10 ( V_12 , V_383 ,
F_12 ( V_71 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_29 ) ) ;
} else {
F_10 ( V_12 , V_110 ,
F_60 ( V_111 ) ) ;
F_10 ( V_12 , V_209 ,
F_61 ( V_113 ) ) ;
return V_28 ;
}
return V_46 ;
}
T_2 F_197 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_106 = NULL ;
F_68 ( L_20 ) ;
F_14 ( V_384 ) ;
( (struct V_9 * ) V_10 ) -> V_385 ++ ;
if ( V_10 -> V_108 >= V_10 -> V_109 ) {
F_10 ( V_12 , V_110 ,
F_60 ( V_111 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_113 ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_28 ;
}
switch ( V_10 -> V_169 ) {
case V_372 :
V_106 = F_190 ( V_10 , NULL ) ;
break;
case V_373 :
V_106 = F_117 ( V_10 , NULL ) ;
break;
default:
F_126 () ;
break;
}
if ( ! V_106 )
goto V_55;
if ( V_10 -> V_386 )
F_10 ( V_12 , V_377 ,
F_58 ( V_10 -> V_386 ) ) ;
F_10 ( V_12 , V_236 , F_35 ( V_106 ) ) ;
F_10 ( V_12 , V_237 ,
F_12 ( V_21 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_106 ) ) ;
return V_46 ;
V_55:
return V_47 ;
}
T_2 F_198 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_10 -> V_296 ;
struct V_105 * V_66 = V_2 -> V_66 ;
F_14 ( V_387 ) ;
if ( V_66 )
F_10 ( V_12 , V_377 ,
F_58 ( V_66 ) ) ;
F_10 ( V_12 , V_369 , F_35 ( V_2 ) ) ;
if ( V_10 -> V_108 >= V_10 -> V_109 ) {
F_10 ( V_12 , V_20 ,
F_12 ( V_188 ) ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_111 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_113 ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_223 ;
}
F_199 ( V_10 -> V_296 ) ;
F_10 ( V_12 , V_58 ,
F_35 ( V_10 -> V_296 ) ) ;
F_10 ( V_12 , V_237 ,
F_12 ( V_188 ) ) ;
return V_46 ;
}
T_2 F_200 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_106 = NULL ;
F_68 ( L_21 ) ;
F_14 ( V_388 ) ;
V_106 = F_133 ( V_10 , NULL , 0 ) ;
if ( ! V_106 )
goto V_55;
F_10 ( V_12 , V_58 , F_35 ( V_106 ) ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_111 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_113 ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_28 ;
V_55:
return V_47 ;
}
T_2 F_201 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
int V_182 ;
F_14 ( V_389 ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_364 ) ) ;
V_182 = V_46 ;
if ( F_113 ( & V_10 -> V_234 ) ) {
V_182 = F_174 ( V_8 , V_10 , type ,
V_11 , V_12 ) ;
}
return V_182 ;
}
T_2 F_202 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return V_390 ;
}
T_2 F_203 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return V_391 ;
}
T_2 F_204 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_68 ( L_22 , type . V_2 ) ;
return V_46 ;
}
static struct V_392 * F_130 ( struct V_1 * V_2 )
{
struct V_392 * V_393 ;
unsigned int V_35 ;
T_1 V_394 ;
T_1 V_395 ;
V_393 = (struct V_392 * ) V_2 -> V_51 -> V_52 ;
V_394 = F_2 ( V_393 -> V_396 ) ;
V_395 = F_2 ( V_393 -> V_395 ) ;
V_35 = sizeof( struct V_392 ) ;
V_35 += ( V_394 + V_395 ) * sizeof( T_14 ) ;
if ( V_35 > V_2 -> V_51 -> V_35 )
return NULL ;
F_26 ( V_2 -> V_51 , V_35 ) ;
return V_393 ;
}
static struct V_32 * F_23 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
struct V_1 * V_2 ,
const void * V_345 ,
T_8 V_119 )
{
struct V_32 * V_33 ;
struct V_1 * abort ;
V_33 = F_132 ( V_10 , V_2 ) ;
if ( V_33 ) {
abort = F_133 ( V_10 , V_2 , V_119 ) ;
if ( ! abort ) {
F_134 ( V_33 ) ;
return NULL ;
}
if ( F_135 ( abort ) )
V_33 -> V_38 = F_102 ( V_2 -> V_37 -> V_38 ) ;
F_33 ( abort , V_119 , V_345 ) ;
abort -> V_51 -> V_41 = V_8 -> V_40 . V_41 ;
F_136 ( V_33 , abort ) ;
}
return V_33 ;
}
static struct V_32 * F_132 ( const struct V_9 * V_10 ,
const struct V_1 * V_2 )
{
struct V_32 * V_33 ;
struct V_105 * V_66 ;
T_1 V_397 ;
T_1 V_398 ;
T_14 V_38 ;
V_397 = F_2 ( V_2 -> V_37 -> V_199 ) ;
V_398 = F_2 ( V_2 -> V_37 -> V_293 ) ;
if ( V_10 ) {
switch( V_2 -> V_5 -> type ) {
case V_347 :
{
V_60 * V_350 ;
V_350 = ( V_60 * ) V_2 -> V_5 ;
V_38 = F_102 ( V_350 -> V_49 . V_349 ) ;
break;
}
default:
V_38 = V_10 -> V_96 . V_348 . V_349 ;
break;
}
} else {
switch( V_2 -> V_5 -> type ) {
case V_399 :
{
V_39 * V_146 ;
V_146 = ( V_39 * ) V_2 -> V_5 ;
V_38 = F_102 ( V_146 -> V_49 . V_349 ) ;
break;
}
default:
V_38 = F_102 ( V_2 -> V_37 -> V_38 ) ;
break;
}
}
V_66 = F_205 ( F_30 ( V_2 ) , V_18 ) ;
if ( ! V_66 )
goto V_55;
F_206 ( V_66 , (union V_123 * ) & V_2 -> V_199 ,
F_18 ( F_19 () ) ) ;
V_33 = F_207 ( & V_66 -> V_33 , V_66 , V_397 , V_398 ) ;
V_33 = F_208 ( V_33 , V_38 , 0 ) ;
return V_33 ;
V_55:
return NULL ;
}
void F_134 ( struct V_32 * V_33 )
{
F_209 ( V_33 -> V_66 ) ;
}
static void F_47 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const struct V_1 * V_2 ,
T_4 * V_12 ,
struct V_1 * V_31 )
{
struct V_32 * V_33 ;
if ( V_31 ) {
V_33 = F_132 ( V_10 , V_2 ) ;
if ( V_33 ) {
struct V_82 * V_400 ;
V_400 = V_2 -> V_48 . V_81 ;
V_33 -> V_38 = V_400 -> V_86 . V_174 ;
V_31 -> V_51 -> V_41 = V_8 -> V_40 . V_41 ;
F_136 ( V_33 , V_31 ) ;
F_10 ( V_12 , V_44 ,
F_25 ( V_33 ) ) ;
F_14 ( V_45 ) ;
} else
F_24 ( V_31 ) ;
}
}
static int F_124 ( const struct V_9 * V_10 ,
struct V_1 * V_2 ,
T_4 * V_12 )
{
V_259 * V_258 ;
struct V_1 * V_181 ;
T_8 V_401 ;
T_21 V_402 ;
int V_403 ;
T_14 V_308 ;
struct V_404 * V_405 = (struct V_404 * ) & V_10 -> V_96 . V_311 ;
struct V_78 * V_41 = V_10 -> V_40 . V_41 ;
T_22 V_406 ;
T_22 V_407 ;
V_211 V_408 = 0 ;
V_258 = V_2 -> V_48 . V_258 = ( V_259 * ) V_2 -> V_51 -> V_52 ;
F_26 ( V_2 -> V_51 , sizeof( V_259 ) ) ;
V_308 = F_102 ( V_258 -> V_308 ) ;
F_68 ( L_23 , V_308 ) ;
if ( ! V_2 -> V_409 ) {
struct V_153 * V_154 ;
V_2 -> V_409 = 1 ;
V_154 = F_70 (
F_210 ( F_211 ( V_2 -> V_51 ) -> V_410 ) ) ;
if ( V_154 && V_154 -> V_411 ( V_2 -> V_51 ) && V_10 -> V_96 . V_412 ) {
F_10 ( V_12 , V_413 ,
F_120 ( V_308 ) ) ;
}
}
V_403 = F_155 ( & V_10 -> V_96 . V_311 , V_308 ) ;
if ( V_403 < 0 ) {
return V_248 ;
} else if ( V_403 > 0 ) {
F_10 ( V_12 , V_414 , F_120 ( V_308 ) ) ;
return V_252 ;
}
V_401 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_401 -= sizeof( V_247 ) ;
V_402 = V_415 ;
if ( ( V_401 >= V_10 -> V_175 ) && ( ! V_10 -> V_416 . V_417 ) ) {
F_10 ( V_12 , V_418 , F_16 () ) ;
}
if ( ( ! V_2 -> V_419 ) && ( ! V_10 -> V_175 || V_10 -> V_420 ||
( V_401 > V_10 -> V_175 + V_10 -> V_421 ) ) ) {
if ( F_212 ( V_405 ) &&
( F_213 ( V_405 ) + 1 ) == V_308 ) {
F_68 ( L_24 , V_308 ) ;
V_402 = V_422 ;
} else {
F_68 ( L_25
L_26 , V_308 , V_401 ,
V_10 -> V_175 ) ;
return V_253 ;
}
}
if ( * V_41 -> V_423 -> V_424 ) {
if ( F_212 ( V_405 ) &&
( F_213 ( V_405 ) + 1 ) == V_308 ) {
F_68 ( L_27 , V_308 ) ;
V_402 = V_422 ;
}
}
if ( F_3 ( 0 == V_401 ) ) {
V_181 = F_214 ( V_10 , V_2 , V_308 ) ;
if ( V_181 ) {
F_10 ( V_12 , V_58 ,
F_35 ( V_181 ) ) ;
}
F_10 ( V_12 , V_162 , F_16 () ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_301 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_425 ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_255 ;
}
V_2 -> V_419 = 1 ;
if ( V_2 -> V_5 -> V_260 & V_426 )
F_14 ( V_427 ) ;
else {
F_14 ( V_428 ) ;
V_408 = 1 ;
}
V_407 = F_2 ( V_258 -> V_312 ) ;
if ( V_407 >= V_10 -> V_86 . V_94 ) {
F_10 ( V_12 , V_429 , F_120 ( V_308 ) ) ;
V_181 = F_88 ( V_10 , V_2 , V_430 ,
& V_258 -> V_312 ,
sizeof( V_258 -> V_312 ) ,
sizeof( T_22 ) ) ;
if ( V_181 )
F_10 ( V_12 , V_58 ,
F_35 ( V_181 ) ) ;
return V_249 ;
}
V_406 = F_2 ( V_258 -> V_406 ) ;
if ( V_408 && F_215 ( V_406 , F_216 ( & V_10 -> V_431 -> V_432 , V_407 ) ) ) {
return V_257 ;
}
F_10 ( V_12 , V_402 , F_35 ( V_2 ) ) ;
return V_91 ;
}
