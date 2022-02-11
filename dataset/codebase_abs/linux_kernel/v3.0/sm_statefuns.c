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
if ( F_66 () )
F_67 ( L_1 ,
V_133 ,
V_10 ,
& V_124 . V_134 . V_135 ) ;
} else {
if ( F_66 () )
F_67 ( L_2 ,
V_133 ,
V_10 ,
& V_124 . V_136 . V_137 . V_138 ) ;
}
return V_128 ;
}
if ( V_126 -> V_139 != V_125 -> V_139 )
return V_128 ;
V_127 = V_125 -> V_140 + V_125 -> V_141 ;
if ( F_68 ( V_126 -> V_142 , V_143 ) ||
F_68 ( V_143 , V_126 -> V_142 + V_127 ) ) {
F_69 ( L_3
L_4 ,
V_133 , V_125 ) ;
return V_128 ;
}
F_10 ( V_12 , V_144 , F_58 ( V_125 ) ) ;
return V_46 ;
}
static int F_70 ( union V_123 * V_145 ,
struct V_1 * V_146 ,
T_4 * V_12 )
{
int V_35 ;
struct V_32 * V_147 ;
union V_148 * V_149 ;
struct V_150 * V_151 ;
struct V_7 * V_8 ;
char V_152 [ sizeof( struct V_150 ) + sizeof( union V_148 ) ] ;
struct V_153 * V_154 = F_71 ( V_145 -> V_136 . V_155 ) ;
V_151 = (struct V_150 * ) V_152 ;
V_149 = (union V_148 * ) V_151 -> V_156 ;
V_35 = V_154 -> V_157 ( V_145 , V_149 ) ;
V_35 += sizeof( V_158 ) ;
V_151 -> V_159 = V_160 ;
V_151 -> V_6 = F_72 ( V_35 ) ;
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
static bool F_73 ( const struct V_163 * V_164 ,
union V_123 * V_165 )
{
struct V_105 * V_166 ;
F_74 (addr, list, transports) {
if ( F_75 ( V_165 , & V_166 -> V_165 ) )
return true ;
}
return false ;
}
static int F_76 ( const struct V_9 * V_30 ,
const struct V_9 * V_10 ,
struct V_1 * V_146 ,
T_4 * V_12 )
{
struct V_105 * V_167 ;
int V_90 = 1 ;
F_74 (new_addr, &new_asoc->peer.transport_addr_list,
transports) {
if ( ! F_73 ( & V_10 -> V_96 . V_168 ,
& V_167 -> V_165 ) ) {
F_70 ( & V_167 -> V_165 , V_146 ,
V_12 ) ;
V_90 = 0 ;
break;
}
}
return V_90 ;
}
static void F_77 ( struct V_9 * V_30 ,
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
static char F_78 ( struct V_9 * V_30 ,
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
static T_2 F_79 (
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
if ( ! F_80 ( V_10 , V_179 ) ) {
if ( ! F_76 ( V_30 , V_10 , V_2 ,
V_12 ) ) {
V_177 = V_46 ;
goto V_180;
}
}
F_77 ( V_30 , V_10 ) ;
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
T_2 F_81 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return F_79 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_82 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return F_79 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_83 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 , T_4 * V_12 )
{
if ( V_8 == F_18 ( ( F_19 () ) ) -> V_8 )
return F_84 ( V_8 , V_10 , type , V_11 , V_12 ) ;
else
return F_85 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
static T_2 F_86 ( const struct V_7 * V_8 ,
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
if ( ! F_76 ( V_30 , V_10 , V_2 , V_12 ) ) {
return V_46 ;
}
if ( F_80 ( V_10 , V_183 ) ) {
V_182 = F_87 ( V_8 , V_10 ,
F_88 ( V_2 -> V_5 -> type ) ,
V_2 , V_12 ) ;
if ( V_47 == V_182 )
goto V_55;
V_181 = F_89 ( V_10 , V_2 ,
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
static T_2 F_90 ( const struct V_7 * V_8 ,
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
F_10 ( V_12 , V_192 , F_91 ( V_92 ) ) ;
if ( V_10 -> V_96 . V_97 )
F_10 ( V_12 , V_193 , F_16 () ) ;
return V_46 ;
V_55:
return V_47 ;
}
static T_2 F_92 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
struct V_1 * V_2 ,
T_4 * V_12 ,
struct V_9 * V_30 )
{
return V_128 ;
}
static T_2 F_93 ( const struct V_7 * V_8 ,
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
T_2 F_94 ( const struct V_7 * V_8 ,
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
V_194 = F_78 ( V_30 , V_10 ) ;
switch ( V_194 ) {
case 'A' :
V_177 = F_86 ( V_8 , V_10 , V_2 , V_12 ,
V_30 ) ;
break;
case 'B' :
V_177 = F_90 ( V_8 , V_10 , V_2 , V_12 ,
V_30 ) ;
break;
case 'C' :
V_177 = F_92 ( V_8 , V_10 , V_2 , V_12 ,
V_30 ) ;
break;
case 'D' :
V_177 = F_93 ( V_8 , V_10 , V_2 , V_12 ,
V_30 ) ;
break;
default:
V_177 = F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
break;
}
F_10 ( V_12 , V_57 , F_34 ( V_30 ) ) ;
F_10 ( V_12 , V_27 , F_16 () ) ;
return V_177 ;
V_55:
return V_47 ;
}
T_2 F_95 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
if ( ! F_5 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_195 ) ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( V_196 ==
F_96 ( & V_10 -> V_40 . V_197 , & V_2 -> V_198 ) )
return F_85 ( V_8 , V_10 , type , V_11 , V_12 ) ;
return F_97 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_98 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
if ( ! F_5 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_195 ) ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( V_196 ==
F_96 ( & V_10 -> V_40 . V_197 , & V_2 -> V_198 ) )
return F_85 ( V_8 , V_10 , type , V_11 , V_12 ) ;
F_10 ( V_12 , V_20 ,
F_12 ( V_21 ) ) ;
F_10 ( V_12 , V_20 ,
F_12 ( V_22 ) ) ;
return F_97 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_99 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return F_98 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_100 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
V_158 * V_181 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_199 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
F_101 (err, chunk->chunk_hdr) {
if ( V_200 == V_181 -> V_159 )
return F_102 ( V_8 , V_10 , type ,
V_11 , V_12 ) ;
}
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
static T_2 F_102 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
T_10 V_201 ;
T_11 V_202 ;
V_158 * V_181 ;
struct V_1 * V_106 ;
struct V_203 * V_204 ;
int V_205 = V_10 -> V_206 + 1 ;
if ( V_205 > V_10 -> V_207 ) {
F_10 ( V_12 , V_110 ,
F_60 ( V_111 ) ) ;
F_10 ( V_12 , V_208 ,
F_61 ( V_200 ) ) ;
return V_28 ;
}
V_181 = ( V_158 * ) ( V_2 -> V_51 -> V_52 ) ;
V_201 = F_103 ( * ( V_209 * ) ( ( V_210 * ) V_181 + sizeof( V_158 ) ) ) ;
V_201 = ( V_201 * 2 ) / 1000 ;
V_202 . V_53 . type = V_211 ;
V_202 . V_53 . V_6 = F_72 ( sizeof( V_202 ) ) ;
V_202 . V_212 = F_104 ( V_201 ) ;
V_204 = (struct V_203 * ) & V_10 -> V_40 . V_197 ;
V_106 = F_105 ( V_10 , V_204 , V_18 , sizeof( V_202 ) ) ;
if ( ! V_106 )
goto V_55;
F_33 ( V_106 , sizeof( V_202 ) , & V_202 ) ;
F_10 ( V_12 , V_213 , F_16 () ) ;
F_10 ( V_12 , V_185 , F_16 () ) ;
F_10 ( V_12 , V_214 , F_16 () ) ;
F_10 ( V_12 , V_215 , F_16 () ) ;
F_10 ( V_12 , V_216 ,
F_58 ( V_10 -> V_96 . V_217 ) ) ;
F_10 ( V_12 , V_218 , F_16 () ) ;
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
T_2 F_106 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
if ( ! F_5 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_195 ) ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( V_196 ==
F_96 ( & V_10 -> V_40 . V_197 , & V_2 -> V_198 ) )
return F_85 ( V_8 , V_10 , type , V_11 , V_12 ) ;
return F_97 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
static T_2 F_97 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
unsigned V_35 ;
T_12 error = V_113 ;
V_35 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_35 >= sizeof( struct V_219 ) + sizeof( struct V_150 ) ) {
V_158 * V_181 ;
F_101 ( V_181 , V_2 -> V_5 ) ;
if ( ( void * ) V_181 != ( void * ) V_2 -> V_220 )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
error = ( ( V_158 * ) V_2 -> V_51 -> V_52 ) -> V_159 ;
}
F_10 ( V_12 , V_110 , F_60 ( V_221 ) ) ;
F_10 ( V_12 , V_112 , F_61 ( error ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_222 ;
}
T_2 F_107 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
unsigned V_35 ;
T_12 error = V_113 ;
if ( ! F_5 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_195 ) ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
V_35 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_35 >= sizeof( struct V_219 ) + sizeof( struct V_150 ) )
error = ( ( V_158 * ) V_2 -> V_51 -> V_52 ) -> V_159 ;
return F_40 ( V_12 , error , V_65 , V_10 ,
V_2 -> V_66 ) ;
}
T_2 F_108 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return F_40 ( V_12 , V_113 ,
V_223 , V_10 ,
(struct V_105 * ) V_11 ) ;
}
T_2 F_109 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return F_107 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
static T_2 F_40 ( T_4 * V_12 ,
T_12 error , int V_224 ,
const struct V_9 * V_10 ,
struct V_105 * V_66 )
{
F_69 ( L_5 ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_24 ) ) ;
F_14 ( V_64 ) ;
F_10 ( V_12 , V_20 ,
F_12 ( V_69 ) ) ;
F_10 ( V_12 , V_110 , F_60 ( V_224 ) ) ;
F_10 ( V_12 , V_208 ,
F_61 ( error ) ) ;
return V_222 ;
}
T_2 F_110 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
T_13 * V_225 ;
T_2 V_182 ;
struct V_13 * V_14 ;
T_14 V_226 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 ,
sizeof( struct V_227 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_225 = ( T_13 * ) V_2 -> V_51 -> V_52 ;
F_26 ( V_2 -> V_51 , sizeof( T_13 ) ) ;
V_2 -> V_48 . V_228 = V_225 ;
V_226 = F_103 ( V_225 -> V_229 ) ;
if ( F_111 ( V_226 , V_10 -> V_230 ) ) {
F_69 ( L_6 , V_226 ) ;
F_69 ( L_7 , V_10 -> V_230 ) ;
return V_128 ;
}
if ( ! F_111 ( V_226 , V_10 -> V_231 ) )
return F_112 ( V_8 , V_10 , type , V_11 , V_12 ) ;
V_14 = F_113 ( V_10 , 0 , V_18 ) ;
if ( ! V_14 ) {
V_182 = V_47 ;
goto V_161;
}
F_10 ( V_12 , V_19 , F_11 ( V_14 ) ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_232 ) ) ;
V_182 = V_46 ;
if ( F_114 ( & V_10 -> V_233 ) ) {
V_182 = F_115 ( V_8 , V_10 , type ,
V_11 , V_12 ) ;
}
if ( V_47 == V_182 )
goto V_161;
F_10 ( V_12 , V_234 ,
F_116 ( V_2 -> V_48 . V_228 -> V_229 ) ) ;
V_161:
return V_182 ;
}
T_2 F_117 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
T_13 * V_225 ;
T_14 V_226 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 ,
sizeof( struct V_227 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_225 = ( T_13 * ) V_2 -> V_51 -> V_52 ;
V_226 = F_103 ( V_225 -> V_229 ) ;
if ( F_111 ( V_226 , V_10 -> V_230 ) ) {
F_69 ( L_6 , V_226 ) ;
F_69 ( L_7 , V_10 -> V_230 ) ;
return V_128 ;
}
if ( ! F_111 ( V_226 , V_10 -> V_231 ) )
return F_112 ( V_8 , V_10 , type , V_11 , V_12 ) ;
F_10 ( V_12 , V_234 ,
F_116 ( V_225 -> V_229 ) ) ;
return V_46 ;
}
T_2 F_87 ( const struct V_7 * V_8 ,
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
V_106 = F_118 ( V_10 , V_2 ) ;
if ( NULL == V_106 )
goto V_55;
F_10 ( V_12 , V_235 , F_35 ( V_106 ) ) ;
F_10 ( V_12 , V_236 ,
F_12 ( V_21 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_106 ) ) ;
return V_46 ;
V_55:
return V_47 ;
}
T_2 F_119 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
T_15 * V_237 ;
struct V_1 * V_2 = V_11 ;
T_16 V_238 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_239 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_237 = ( T_15 * ) V_2 -> V_51 -> V_52 ;
F_26 ( V_2 -> V_51 , sizeof( T_15 ) ) ;
V_238 = F_103 ( V_237 -> V_238 ) ;
if ( F_120 ( V_10 -> V_240 , V_238 ) ) {
F_10 ( V_12 ,
V_241 ,
F_121 ( V_238 ) ) ;
}
return V_46 ;
}
T_2 F_122 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
T_17 * V_242 ;
struct V_1 * V_2 = V_11 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_239 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_242 = ( T_17 * ) V_2 -> V_51 -> V_52 ;
F_26 ( V_2 -> V_51 , sizeof( T_17 ) ) ;
F_10 ( V_12 , V_243 ,
F_121 ( F_103 ( V_242 -> V_238 ) ) ) ;
return V_46 ;
}
T_2 F_123 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
T_18 V_244 = F_124 () ;
int error ;
if ( ! F_38 ( V_2 , V_10 ) ) {
F_10 ( V_12 , V_245 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! F_1 ( V_2 , sizeof( V_246 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
error = F_125 ( V_10 , V_2 , V_12 ) ;
switch ( error ) {
case V_91 :
break;
case V_247 :
case V_248 :
F_14 ( V_249 ) ;
goto V_250;
case V_251 :
case V_252 :
F_14 ( V_249 ) ;
goto V_253;
case V_254 :
goto V_255;
case V_256 :
return F_126 ( V_8 , V_10 , V_2 , V_12 ,
( V_210 * ) V_2 -> V_48 . V_257 , sizeof( V_258 ) ) ;
default:
F_127 () ;
}
if ( V_2 -> V_5 -> V_259 & V_260 )
V_244 = F_128 () ;
if ( V_10 -> V_102 ) {
F_10 ( V_12 , V_236 ,
F_12 ( V_103 ) ) ;
}
if ( V_2 -> V_261 )
F_10 ( V_12 , V_262 , V_244 ) ;
return V_46 ;
V_253:
if ( V_2 -> V_261 )
F_10 ( V_12 , V_262 , F_128 () ) ;
return V_128 ;
V_250:
if ( V_2 -> V_261 )
F_10 ( V_12 , V_262 , V_244 ) ;
return V_128 ;
V_255:
return V_46 ;
}
T_2 F_129 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
int error ;
if ( ! F_38 ( V_2 , V_10 ) ) {
F_10 ( V_12 , V_245 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! F_1 ( V_2 , sizeof( V_246 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
error = F_125 ( V_10 , V_2 , V_12 ) ;
switch ( error ) {
case V_91 :
case V_247 :
case V_251 :
case V_252 :
case V_248 :
break;
case V_254 :
goto V_255;
case V_256 :
return F_126 ( V_8 , V_10 , V_2 , V_12 ,
( V_210 * ) V_2 -> V_48 . V_257 , sizeof( V_258 ) ) ;
default:
F_127 () ;
}
if ( V_2 -> V_261 ) {
F_10 ( V_12 , V_263 , F_16 () ) ;
F_10 ( V_12 , V_262 , F_128 () ) ;
F_10 ( V_12 , V_236 ,
F_12 ( V_21 ) ) ;
}
V_255:
return V_46 ;
}
T_2 F_130 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
T_19 * V_264 ;
T_14 V_226 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_265 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_264 = F_131 ( V_2 ) ;
if ( ! V_264 )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
V_2 -> V_48 . V_266 = V_264 ;
V_226 = F_103 ( V_264 -> V_229 ) ;
if ( F_111 ( V_226 , V_10 -> V_230 ) ) {
F_69 ( L_6 , V_226 ) ;
F_69 ( L_7 , V_10 -> V_230 ) ;
return V_128 ;
}
if ( ! F_111 ( V_226 , V_10 -> V_231 ) )
return F_112 ( V_8 , V_10 , type , V_11 , V_12 ) ;
F_10 ( V_12 , V_267 , F_132 ( V_264 ) ) ;
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
V_33 = F_133 ( V_10 , V_2 ) ;
if ( V_33 ) {
abort = F_134 ( V_10 , V_2 , 0 ) ;
if ( ! abort ) {
F_135 ( V_33 ) ;
return V_47 ;
}
if ( F_136 ( abort ) )
V_33 -> V_38 = F_103 ( V_2 -> V_37 -> V_38 ) ;
abort -> V_51 -> V_41 = V_8 -> V_40 . V_41 ;
F_137 ( V_33 , abort ) ;
F_10 ( V_12 , V_44 ,
F_25 ( V_33 ) ) ;
F_14 ( V_45 ) ;
F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
return V_46 ;
}
return V_47 ;
}
T_2 F_138 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
V_158 * V_181 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_199 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
F_101 ( V_181 , V_2 -> V_5 ) ;
if ( ( void * ) V_181 != ( void * ) V_2 -> V_220 )
return F_139 ( V_8 , V_10 , type , V_11 ,
( void * ) V_181 , V_12 ) ;
F_10 ( V_12 , V_268 ,
F_35 ( V_2 ) ) ;
return V_46 ;
}
T_2 F_140 ( const struct V_7 * V_8 ,
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
V_106 = F_141 ( V_10 , V_2 ) ;
if ( ! V_106 )
goto V_269;
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
V_269:
F_54 ( V_14 ) ;
V_55:
return V_47 ;
}
T_2 F_84 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
struct V_270 * V_51 = V_2 -> V_51 ;
V_16 * V_271 ;
V_158 * V_181 ;
V_43 * V_272 ;
int V_273 = 0 ;
int V_274 = 0 ;
F_14 ( V_36 ) ;
V_271 = ( V_16 * ) V_2 -> V_5 ;
do {
if ( F_2 ( V_271 -> V_6 ) < sizeof( V_16 ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
if ( V_275 == V_271 -> type )
V_273 = 1 ;
if ( V_63 == V_271 -> type )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( V_276 == V_271 -> type )
V_274 = 1 ;
if ( V_277 == V_271 -> type ) {
F_101 (err, ch) {
if ( V_200 == V_181 -> V_159 ) {
V_274 = 1 ;
break;
}
}
}
V_272 = ( ( V_43 * ) V_271 ) + F_142 ( F_2 ( V_271 -> V_6 ) ) ;
if ( V_272 > F_143 ( V_51 ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_271 = ( V_16 * ) V_272 ;
} while ( V_272 < F_143 ( V_51 ) );
if ( V_273 )
return F_144 ( V_8 , V_10 , type , V_11 , V_12 ) ;
else if ( V_274 )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
else
return F_20 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
static T_2 F_144 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_32 * V_33 = NULL ;
struct V_1 * V_2 = V_11 ;
struct V_1 * V_278 ;
V_33 = F_133 ( V_10 , V_2 ) ;
if ( V_33 ) {
V_278 = F_141 ( V_10 , V_2 ) ;
if ( ! V_278 ) {
F_135 ( V_33 ) ;
return V_47 ;
}
if ( F_136 ( V_278 ) )
V_33 -> V_38 = F_103 ( V_2 -> V_37 -> V_38 ) ;
V_278 -> V_51 -> V_41 = V_8 -> V_40 . V_41 ;
F_137 ( V_33 , V_278 ) ;
F_10 ( V_12 , V_44 ,
F_25 ( V_33 ) ) ;
F_14 ( V_45 ) ;
if ( ! F_1 ( V_2 , sizeof( V_16 ) ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
return V_47 ;
}
T_2 F_145 ( const struct V_7 * V_8 ,
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
return F_144 ( V_8 , NULL , type , V_11 , V_12 ) ;
}
T_2 F_146 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type , void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
struct V_1 * V_279 = NULL ;
struct V_280 * V_281 = NULL ;
T_20 * V_282 ;
union V_148 * V_283 ;
T_14 V_284 ;
int V_6 ;
if ( ! F_38 ( V_2 , V_10 ) ) {
F_10 ( V_12 , V_245 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! V_285 && ! V_2 -> V_89 )
return F_85 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_286 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_282 = ( T_20 * ) V_2 -> V_51 -> V_52 ;
V_284 = F_103 ( V_282 -> V_284 ) ;
V_283 = (union V_148 * ) V_282 -> V_287 ;
V_6 = F_2 ( V_283 -> V_288 . V_6 ) ;
if ( V_6 < sizeof( V_289 ) )
return F_139 ( V_8 , V_10 , type , V_11 ,
( void * ) V_283 , V_12 ) ;
if ( ! F_147 ( V_10 ,
( V_289 * ) ( ( void * ) V_283 + V_6 ) ,
( void * ) V_2 -> V_220 ,
& V_281 ) )
return F_139 ( V_8 , V_10 , type , V_11 ,
( void * ) V_281 , V_12 ) ;
if ( V_284 == V_10 -> V_96 . V_290 + 1 ) {
if ( ! V_2 -> V_291 )
F_148 ( V_10 ) ;
V_279 = F_149 ( (struct V_9 * )
V_10 , V_2 ) ;
if ( ! V_279 )
return V_47 ;
} else if ( V_284 < V_10 -> V_96 . V_290 + 1 ) {
V_279 = F_150 ( V_10 , V_282 -> V_284 ) ;
if ( ! V_279 )
return V_128 ;
V_279 -> V_66 = NULL ;
} else {
return V_128 ;
}
V_279 -> V_198 = V_2 -> V_292 ;
F_10 ( V_12 , V_58 , F_35 ( V_279 ) ) ;
return V_46 ;
}
T_2 F_151 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type , void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_279 = V_11 ;
struct V_1 * V_293 = V_10 -> V_294 ;
struct V_1 * abort ;
struct V_280 * V_281 = NULL ;
T_20 * V_295 ;
T_14 V_296 , V_297 ;
if ( ! F_38 ( V_279 , V_10 ) ) {
F_10 ( V_12 , V_245 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! V_285 && ! V_279 -> V_89 )
return F_85 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_279 , sizeof( V_286 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_295 = ( T_20 * ) V_279 -> V_51 -> V_52 ;
V_297 = F_103 ( V_295 -> V_284 ) ;
if ( ! F_147 ( V_10 ,
( V_289 * ) V_295 -> V_287 ,
( void * ) V_279 -> V_220 ,
& V_281 ) )
return F_139 ( V_8 , V_10 , type , V_11 ,
( void * ) V_281 , V_12 ) ;
if ( V_293 ) {
V_295 = ( T_20 * ) V_293 -> V_48 . V_295 ;
V_296 = F_103 ( V_295 -> V_284 ) ;
} else {
V_296 = V_10 -> V_290 - 1 ;
}
if ( F_152 ( V_297 , V_296 + 1 ) &&
! ( V_10 -> V_294 ) ) {
abort = F_134 ( V_10 , V_279 ,
sizeof( V_158 ) ) ;
if ( abort ) {
F_153 ( abort , V_298 , 0 ) ;
F_10 ( V_12 , V_58 ,
F_35 ( abort ) ) ;
}
F_10 ( V_12 , V_20 ,
F_12 ( V_188 ) ) ;
F_10 ( V_12 , V_162 , F_16 () ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_299 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_298 ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_222 ;
}
if ( ( V_297 == V_296 ) && V_10 -> V_294 ) {
F_10 ( V_12 , V_20 ,
F_12 ( V_188 ) ) ;
if ( ! F_154 ( (struct V_9 * ) V_10 ,
V_279 ) ) {
F_10 ( V_12 , V_300 ,
F_16 () ) ;
return V_46 ;
}
abort = F_134 ( V_10 , V_279 ,
sizeof( V_158 ) ) ;
if ( abort ) {
F_153 ( abort , V_301 , 0 ) ;
F_10 ( V_12 , V_58 ,
F_35 ( abort ) ) ;
}
F_10 ( V_12 , V_162 , F_16 () ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_299 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_298 ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_222 ;
}
return V_128 ;
}
T_2 F_155 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
struct V_302 * V_303 ;
struct V_304 * V_305 ;
T_1 V_35 ;
T_14 V_306 ;
if ( ! F_38 ( V_2 , V_10 ) ) {
F_10 ( V_12 , V_245 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_307 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_303 = (struct V_302 * ) V_2 -> V_51 -> V_52 ;
V_2 -> V_48 . V_303 = V_303 ;
V_35 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_35 -= sizeof( struct V_219 ) ;
F_26 ( V_2 -> V_51 , V_35 ) ;
V_306 = F_103 ( V_303 -> V_308 ) ;
F_69 ( L_8 , V_133 , V_306 ) ;
if ( F_156 ( & V_10 -> V_96 . V_309 , V_306 ) < 0 )
goto V_250;
F_157 (skip, chunk) {
if ( F_2 ( V_305 -> V_310 ) >= V_10 -> V_86 . V_94 )
goto V_250;
}
F_10 ( V_12 , V_311 , F_121 ( V_306 ) ) ;
if ( V_35 > sizeof( struct V_302 ) )
F_10 ( V_12 , V_312 ,
F_35 ( V_2 ) ) ;
if ( V_10 -> V_102 ) {
F_10 ( V_12 , V_236 ,
F_12 ( V_103 ) ) ;
}
F_10 ( V_12 , V_262 , F_124 () ) ;
return V_46 ;
V_250:
return V_128 ;
}
T_2 F_158 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
struct V_302 * V_303 ;
struct V_304 * V_305 ;
T_1 V_35 ;
T_14 V_306 ;
if ( ! F_38 ( V_2 , V_10 ) ) {
F_10 ( V_12 , V_245 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_307 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_303 = (struct V_302 * ) V_2 -> V_51 -> V_52 ;
V_2 -> V_48 . V_303 = V_303 ;
V_35 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_35 -= sizeof( struct V_219 ) ;
F_26 ( V_2 -> V_51 , V_35 ) ;
V_306 = F_103 ( V_303 -> V_308 ) ;
F_69 ( L_8 , V_133 , V_306 ) ;
if ( F_156 ( & V_10 -> V_96 . V_309 , V_306 ) < 0 )
goto V_313;
F_157 (skip, chunk) {
if ( F_2 ( V_305 -> V_310 ) >= V_10 -> V_86 . V_94 )
goto V_313;
}
F_10 ( V_12 , V_311 , F_121 ( V_306 ) ) ;
if ( V_35 > sizeof( struct V_302 ) )
F_10 ( V_12 , V_312 ,
F_35 ( V_2 ) ) ;
V_313:
F_10 ( V_12 , V_263 , F_16 () ) ;
F_10 ( V_12 , V_262 , F_128 () ) ;
F_10 ( V_12 , V_236 ,
F_12 ( V_21 ) ) ;
return V_46 ;
}
static T_7 F_50 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
struct V_1 * V_2 )
{
struct V_314 * V_315 ;
struct V_316 * V_317 ;
unsigned int V_318 ;
T_1 V_319 ;
V_43 * V_320 ;
V_43 * V_321 ;
V_315 = (struct V_314 * ) V_2 -> V_51 -> V_52 ;
V_2 -> V_48 . V_315 = V_315 ;
F_26 ( V_2 -> V_51 , sizeof( struct V_314 ) ) ;
if ( ! F_159 ( V_10 , V_315 -> V_322 ) )
return V_323 ;
V_319 = F_2 ( V_315 -> V_324 ) ;
if ( V_319 != V_10 -> V_325 && ! F_160 ( V_10 , V_319 ) )
return V_326 ;
V_318 = F_2 ( V_2 -> V_5 -> V_6 ) - sizeof( V_327 ) ;
V_317 = F_161 ( F_2 ( V_315 -> V_322 ) ) ;
if ( V_318 != V_317 -> V_328 )
return V_256 ;
V_321 = V_315 -> V_317 ;
F_26 ( V_2 -> V_51 , V_318 ) ;
V_320 = F_162 ( V_321 , V_318 , V_18 ) ;
if ( ! V_320 )
goto V_55;
memset ( V_321 , 0 , V_318 ) ;
F_163 ( V_10 , V_2 -> V_51 ,
(struct V_329 * ) V_2 -> V_5 ,
V_18 ) ;
if ( memcmp ( V_320 , V_321 , V_318 ) ) {
F_164 ( V_320 ) ;
return V_85 ;
}
F_164 ( V_320 ) ;
V_2 -> V_89 = 1 ;
return V_91 ;
V_55:
return V_83 ;
}
T_2 F_165 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_314 * V_315 ;
struct V_1 * V_2 = V_11 ;
struct V_1 * V_31 ;
T_7 error ;
if ( ! V_10 -> V_96 . V_330 )
return F_166 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_38 ( V_2 , V_10 ) ) {
F_10 ( V_12 , V_245 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_329 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_315 = (struct V_314 * ) V_2 -> V_51 -> V_52 ;
error = F_50 ( V_8 , V_10 , type , V_2 ) ;
switch ( error ) {
case V_323 :
V_31 = F_89 ( V_10 , V_2 ,
V_331 ,
& V_315 -> V_322 ,
sizeof( T_1 ) , 0 ) ;
if ( V_31 ) {
F_10 ( V_12 , V_58 ,
F_35 ( V_31 ) ) ;
}
case V_326 :
case V_85 :
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
break;
case V_256 :
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
break;
case V_83 :
return V_47 ;
default:
break;
}
if ( V_10 -> V_325 != F_2 ( V_315 -> V_324 ) ) {
struct V_13 * V_14 ;
V_14 = F_167 ( V_10 , F_2 ( V_315 -> V_324 ) ,
V_332 , V_18 ) ;
if ( ! V_14 )
return - V_333 ;
F_10 ( V_12 , V_19 ,
F_11 ( V_14 ) ) ;
}
return V_46 ;
}
T_2 F_166 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_334 = V_11 ;
struct V_1 * V_31 ;
V_16 * V_282 ;
F_69 ( L_9 , type . V_2 ) ;
if ( ! F_38 ( V_334 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_334 , sizeof( V_16 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
switch ( type . V_2 & V_335 ) {
case V_336 :
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
break;
case V_337 :
V_282 = V_334 -> V_5 ;
V_31 = F_89 ( V_10 , V_334 ,
V_338 , V_282 ,
F_142 ( F_2 ( V_282 -> V_6 ) ) ,
0 ) ;
if ( V_31 ) {
F_10 ( V_12 , V_58 ,
F_35 ( V_31 ) ) ;
}
F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
return V_46 ;
break;
case V_339 :
return V_128 ;
break;
case V_340 :
V_282 = V_334 -> V_5 ;
V_31 = F_89 ( V_10 , V_334 ,
V_338 , V_282 ,
F_142 ( F_2 ( V_282 -> V_6 ) ) ,
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
T_2 F_85 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
if ( ! F_1 ( V_2 , sizeof( V_16 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
F_69 ( L_10 , type . V_2 ) ;
return V_128 ;
}
T_2 F_6 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_14 ( V_341 ) ;
F_10 ( V_12 , V_162 , F_16 () ) ;
return V_46 ;
}
T_2 F_168 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
if ( ! F_1 ( V_2 , sizeof( V_16 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
return V_342 ;
}
static T_2 F_126 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
void * V_11 ,
T_4 * V_12 ,
const V_43 * V_343 ,
const T_8 V_119 )
{
struct V_32 * V_33 = NULL ;
struct V_1 * V_2 = V_11 ;
struct V_1 * abort = NULL ;
if ( F_39 ( V_63 , V_10 ) )
goto V_344;
abort = F_169 ( V_10 , V_2 , V_343 , V_119 ) ;
if ( ! abort )
goto V_55;
if ( V_10 ) {
if ( V_2 -> V_5 -> type == V_345 &&
! V_10 -> V_96 . V_346 . V_347 ) {
V_60 * V_348 ;
V_348 = ( V_60 * ) V_2 -> V_5 ;
if ( ! F_1 ( V_2 ,
sizeof( V_60 ) ) )
abort -> V_5 -> V_259 |= V_349 ;
else {
unsigned int V_350 ;
V_350 = F_103 ( V_348 -> V_49 . V_347 ) ;
F_10 ( V_12 , V_351 ,
F_121 ( V_350 ) ) ;
}
}
F_10 ( V_12 , V_58 , F_35 ( abort ) ) ;
F_14 ( V_45 ) ;
if ( V_10 -> V_169 <= V_72 ) {
F_10 ( V_12 , V_20 ,
F_12 ( V_69 ) ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_65 ) ) ;
F_10 ( V_12 , V_208 ,
F_61 ( V_352 ) ) ;
} else {
F_10 ( V_12 , V_110 ,
F_60 ( V_299 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_352 ) ) ;
F_15 ( V_26 ) ;
}
} else {
V_33 = F_133 ( V_10 , V_2 ) ;
if ( ! V_33 )
goto V_353;
if ( F_136 ( abort ) )
V_33 -> V_38 = F_103 ( V_2 -> V_37 -> V_38 ) ;
abort -> V_51 -> V_41 = V_8 -> V_40 . V_41 ;
F_137 ( V_33 , abort ) ;
F_10 ( V_12 , V_44 ,
F_25 ( V_33 ) ) ;
F_14 ( V_45 ) ;
}
F_14 ( V_64 ) ;
V_344:
F_6 ( V_8 , V_10 , F_88 ( 0 ) , V_11 , V_12 ) ;
return V_222 ;
V_353:
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
static const char V_354 [] = L_11 ;
return F_126 ( V_8 , V_10 , V_11 , V_12 , V_354 ,
sizeof( V_354 ) ) ;
}
static T_2 F_139 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 , void * V_355 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
struct V_280 * V_356 = V_355 ;
struct V_1 * abort = NULL ;
if ( F_39 ( V_63 , V_10 ) )
goto V_344;
abort = F_170 ( V_10 , V_2 , V_356 ) ;
if ( ! abort )
goto V_55;
F_10 ( V_12 , V_58 , F_35 ( abort ) ) ;
F_14 ( V_45 ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_299 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_352 ) ) ;
F_15 ( V_26 ) ;
F_14 ( V_64 ) ;
V_344:
F_6 ( V_8 , V_10 , F_88 ( 0 ) , V_11 , V_12 ) ;
return V_222 ;
V_55:
return V_47 ;
}
static T_2 F_112 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
static const char V_354 [] = L_12 ;
return F_126 ( V_8 , V_10 , V_11 , V_12 , V_354 ,
sizeof( V_354 ) ) ;
}
static T_2 F_7 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
static const char V_354 [] = L_13 ;
if ( ! V_10 )
return F_168 ( V_8 , V_10 , type , V_11 , V_12 ) ;
return F_126 ( V_8 , V_10 , V_11 , V_12 , V_354 ,
sizeof( V_354 ) ) ;
}
T_2 F_171 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_29 ;
struct V_9 * V_357 ;
F_10 ( V_12 , V_23 ,
F_13 ( V_170 ) ) ;
V_29 = F_105 ( V_10 , & V_10 -> V_40 . V_197 , V_18 , 0 ) ;
if ( ! V_29 )
goto V_55;
V_357 = (struct V_9 * ) V_10 ;
F_10 ( V_12 , V_57 , F_34 ( V_357 ) ) ;
F_10 ( V_12 , V_358 ,
F_35 ( V_29 ) ) ;
F_10 ( V_12 , V_70 ,
F_12 ( V_69 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_29 ) ) ;
return V_46 ;
V_55:
return V_47 ;
}
T_2 F_172 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_359 * V_360 = V_11 ;
F_10 ( V_12 , V_361 , F_173 ( V_360 ) ) ;
return V_46 ;
}
T_2 F_174 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
int V_182 ;
F_10 ( V_12 , V_23 ,
F_13 ( V_362 ) ) ;
V_182 = V_46 ;
if ( F_114 ( & V_10 -> V_233 ) ) {
V_182 = F_175 ( V_8 , V_10 , type ,
V_11 , V_12 ) ;
}
return V_182 ;
}
T_2 F_176 (
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
F_60 ( V_299 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_363 ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_177 ;
}
T_2 F_177 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_10 ( V_12 , V_364 , F_60 ( - V_365 ) ) ;
return V_46 ;
}
T_2 F_178 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_10 ( V_12 , V_364 ,
F_60 ( - V_366 ) ) ;
return V_46 ;
}
T_2 F_179 (
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
T_2 F_180 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 , T_4 * V_12 )
{
return F_179 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_181 (
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
F_10 ( V_12 , V_208 ,
F_61 ( V_363 ) ) ;
return V_177 ;
}
T_2 F_182 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return F_181 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_183 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_10 ( V_12 , V_20 ,
F_12 ( V_22 ) ) ;
return F_176 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_184 (
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
return F_176 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_185 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return F_184 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
T_2 F_186 (
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
T_2 F_187 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
F_10 ( V_12 , V_367 , F_35 ( V_2 ) ) ;
F_10 ( V_12 , V_70 ,
F_12 ( V_188 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_2 ) ) ;
return V_46 ;
}
T_2 F_188 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_69 ( L_14 , type . V_368 ) ;
return V_128 ;
}
T_2 F_189 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_13 * V_369 ;
V_369 = F_190 ( V_10 , V_18 ) ;
if ( ! V_369 )
return V_47 ;
F_10 ( V_12 , V_19 , F_11 ( V_369 ) ) ;
return V_46 ;
}
T_2 F_175 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_106 ;
V_106 = F_191 ( V_10 , NULL ) ;
if ( ! V_106 )
goto V_55;
F_10 ( V_12 , V_235 , F_35 ( V_106 ) ) ;
F_10 ( V_12 , V_70 ,
F_12 ( V_21 ) ) ;
F_10 ( V_12 , V_236 ,
F_12 ( V_22 ) ) ;
if ( V_10 -> V_102 )
F_10 ( V_12 , V_20 ,
F_12 ( V_103 ) ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_370 ) ) ;
F_10 ( V_12 , V_214 , F_16 () ) ;
F_10 ( V_12 , V_58 , F_35 ( V_106 ) ) ;
return V_46 ;
V_55:
return V_47 ;
}
T_2 F_115 (
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
if ( ! F_1 ( V_2 , sizeof( struct V_227 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
}
V_106 = F_118 ( V_10 , V_2 ) ;
if ( ! V_106 )
goto V_55;
F_10 ( V_12 , V_235 , F_35 ( V_106 ) ) ;
F_10 ( V_12 , V_236 ,
F_12 ( V_21 ) ) ;
if ( V_10 -> V_102 )
F_10 ( V_12 , V_20 ,
F_12 ( V_103 ) ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_371 ) ) ;
F_10 ( V_12 , V_214 , F_16 () ) ;
F_10 ( V_12 , V_58 , F_35 ( V_106 ) ) ;
return V_46 ;
V_55:
return V_47 ;
}
T_2 F_192 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_69 ( L_15 , type . V_372 ) ;
return V_128 ;
}
T_2 F_193 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_105 * V_66 = V_11 ;
F_14 ( V_373 ) ;
if ( V_10 -> V_108 >= V_10 -> V_109 ) {
if ( V_10 -> V_169 == V_362 ) {
F_10 ( V_12 , V_374 ,
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
F_10 ( V_12 , V_375 , F_58 ( V_66 ) ) ;
F_10 ( V_12 , V_376 , F_58 ( V_66 ) ) ;
return V_46 ;
}
T_2 F_194 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_14 ( V_377 ) ;
F_10 ( V_12 , V_262 , F_128 () ) ;
return V_46 ;
}
T_2 F_195 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_29 = NULL ;
struct V_203 * V_204 ;
int V_205 = V_10 -> V_206 + 1 ;
F_69 ( L_16 ) ;
F_14 ( V_378 ) ;
if ( V_205 <= V_10 -> V_207 ) {
V_204 = (struct V_203 * ) & V_10 -> V_40 . V_197 ;
V_29 = F_105 ( V_10 , V_204 , V_18 , 0 ) ;
if ( ! V_29 )
return V_47 ;
F_10 ( V_12 , V_358 ,
F_35 ( V_29 ) ) ;
F_10 ( V_12 , V_379 ,
F_12 ( V_69 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_29 ) ) ;
} else {
F_69 ( L_17
L_18 ,
V_205 , V_10 -> V_207 ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_111 ) ) ;
F_10 ( V_12 , V_208 ,
F_61 ( V_113 ) ) ;
return V_28 ;
}
return V_46 ;
}
T_2 F_196 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_29 = NULL ;
int V_205 = V_10 -> V_206 + 1 ;
F_69 ( L_19 ) ;
F_14 ( V_380 ) ;
if ( V_205 <= V_10 -> V_207 ) {
V_29 = F_197 ( V_10 , NULL ) ;
if ( ! V_29 )
return V_47 ;
F_10 ( V_12 , V_358 ,
F_35 ( V_29 ) ) ;
F_10 ( V_12 , V_381 ,
F_12 ( V_71 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_29 ) ) ;
} else {
F_10 ( V_12 , V_110 ,
F_60 ( V_111 ) ) ;
F_10 ( V_12 , V_208 ,
F_61 ( V_113 ) ) ;
return V_28 ;
}
return V_46 ;
}
T_2 F_198 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_106 = NULL ;
F_69 ( L_20 ) ;
F_14 ( V_382 ) ;
( (struct V_9 * ) V_10 ) -> V_383 ++ ;
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
case V_370 :
V_106 = F_191 ( V_10 , NULL ) ;
break;
case V_371 :
V_106 = F_118 ( V_10 , NULL ) ;
break;
default:
F_127 () ;
break;
}
if ( ! V_106 )
goto V_55;
if ( V_10 -> V_384 )
F_10 ( V_12 , V_375 ,
F_58 ( V_10 -> V_384 ) ) ;
F_10 ( V_12 , V_235 , F_35 ( V_106 ) ) ;
F_10 ( V_12 , V_236 ,
F_12 ( V_21 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_106 ) ) ;
return V_46 ;
V_55:
return V_47 ;
}
T_2 F_199 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_10 -> V_294 ;
struct V_105 * V_66 = V_2 -> V_66 ;
F_14 ( V_385 ) ;
if ( V_66 )
F_10 ( V_12 , V_375 ,
F_58 ( V_66 ) ) ;
F_10 ( V_12 , V_367 , F_35 ( V_2 ) ) ;
if ( V_10 -> V_108 >= V_10 -> V_109 ) {
F_10 ( V_12 , V_20 ,
F_12 ( V_188 ) ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_111 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_113 ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_222 ;
}
F_200 ( V_10 -> V_294 ) ;
F_10 ( V_12 , V_58 ,
F_35 ( V_10 -> V_294 ) ) ;
F_10 ( V_12 , V_236 ,
F_12 ( V_188 ) ) ;
return V_46 ;
}
T_2 F_201 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_106 = NULL ;
F_69 ( L_21 ) ;
F_14 ( V_386 ) ;
V_106 = F_134 ( V_10 , NULL , 0 ) ;
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
T_2 F_202 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
int V_182 ;
F_14 ( V_387 ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_362 ) ) ;
V_182 = V_46 ;
if ( F_114 ( & V_10 -> V_233 ) ) {
V_182 = F_175 ( V_8 , V_10 , type ,
V_11 , V_12 ) ;
}
return V_182 ;
}
T_2 F_203 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return V_388 ;
}
T_2 F_204 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return V_389 ;
}
T_2 F_205 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_69 ( L_22 , type . V_2 ) ;
return V_46 ;
}
static struct V_390 * F_131 ( struct V_1 * V_2 )
{
struct V_390 * V_391 ;
unsigned int V_35 ;
T_1 V_392 ;
T_1 V_393 ;
V_391 = (struct V_390 * ) V_2 -> V_51 -> V_52 ;
V_392 = F_2 ( V_391 -> V_394 ) ;
V_393 = F_2 ( V_391 -> V_393 ) ;
V_35 = sizeof( struct V_390 ) ;
V_35 += ( V_392 + V_393 ) * sizeof( T_14 ) ;
if ( V_35 > V_2 -> V_51 -> V_35 )
return NULL ;
F_26 ( V_2 -> V_51 , V_35 ) ;
return V_391 ;
}
static struct V_32 * F_23 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
struct V_1 * V_2 ,
const void * V_343 ,
T_8 V_119 )
{
struct V_32 * V_33 ;
struct V_1 * abort ;
V_33 = F_133 ( V_10 , V_2 ) ;
if ( V_33 ) {
abort = F_134 ( V_10 , V_2 , V_119 ) ;
if ( ! abort ) {
F_135 ( V_33 ) ;
return NULL ;
}
if ( F_136 ( abort ) )
V_33 -> V_38 = F_103 ( V_2 -> V_37 -> V_38 ) ;
F_33 ( abort , V_119 , V_343 ) ;
abort -> V_51 -> V_41 = V_8 -> V_40 . V_41 ;
F_137 ( V_33 , abort ) ;
}
return V_33 ;
}
static struct V_32 * F_133 ( const struct V_9 * V_10 ,
const struct V_1 * V_2 )
{
struct V_32 * V_33 ;
struct V_105 * V_66 ;
T_1 V_395 ;
T_1 V_396 ;
T_14 V_38 ;
V_395 = F_2 ( V_2 -> V_37 -> V_198 ) ;
V_396 = F_2 ( V_2 -> V_37 -> V_292 ) ;
if ( V_10 ) {
switch( V_2 -> V_5 -> type ) {
case V_345 :
{
V_60 * V_348 ;
V_348 = ( V_60 * ) V_2 -> V_5 ;
V_38 = F_103 ( V_348 -> V_49 . V_347 ) ;
break;
}
default:
V_38 = V_10 -> V_96 . V_346 . V_347 ;
break;
}
} else {
switch( V_2 -> V_5 -> type ) {
case V_397 :
{
V_39 * V_146 ;
V_146 = ( V_39 * ) V_2 -> V_5 ;
V_38 = F_103 ( V_146 -> V_49 . V_347 ) ;
break;
}
default:
V_38 = F_103 ( V_2 -> V_37 -> V_38 ) ;
break;
}
}
V_66 = F_206 ( F_30 ( V_2 ) , V_18 ) ;
if ( ! V_66 )
goto V_55;
F_207 ( V_66 , (union V_123 * ) & V_2 -> V_198 ,
F_18 ( F_19 () ) ) ;
V_33 = F_208 ( & V_66 -> V_33 , V_66 , V_395 , V_396 ) ;
V_33 = F_209 ( V_33 , V_38 , 0 ) ;
return V_33 ;
V_55:
return NULL ;
}
void F_135 ( struct V_32 * V_33 )
{
F_210 ( V_33 -> V_66 ) ;
}
static void F_47 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const struct V_1 * V_2 ,
T_4 * V_12 ,
struct V_1 * V_31 )
{
struct V_32 * V_33 ;
if ( V_31 ) {
V_33 = F_133 ( V_10 , V_2 ) ;
if ( V_33 ) {
struct V_82 * V_398 ;
V_398 = V_2 -> V_48 . V_81 ;
V_33 -> V_38 = V_398 -> V_86 . V_174 ;
V_31 -> V_51 -> V_41 = V_8 -> V_40 . V_41 ;
F_137 ( V_33 , V_31 ) ;
F_10 ( V_12 , V_44 ,
F_25 ( V_33 ) ) ;
F_14 ( V_45 ) ;
} else
F_24 ( V_31 ) ;
}
}
static int F_125 ( const struct V_9 * V_10 ,
struct V_1 * V_2 ,
T_4 * V_12 )
{
V_258 * V_257 ;
struct V_1 * V_181 ;
T_8 V_399 ;
T_21 V_400 ;
int V_401 ;
T_14 V_306 ;
struct V_402 * V_403 = (struct V_402 * ) & V_10 -> V_96 . V_309 ;
struct V_78 * V_41 = V_10 -> V_40 . V_41 ;
T_22 V_404 ;
T_22 V_405 ;
V_210 V_406 = 0 ;
V_257 = V_2 -> V_48 . V_257 = ( V_258 * ) V_2 -> V_51 -> V_52 ;
F_26 ( V_2 -> V_51 , sizeof( V_258 ) ) ;
V_306 = F_103 ( V_257 -> V_306 ) ;
F_69 ( L_23 , V_306 ) ;
if ( ! V_2 -> V_407 ) {
struct V_153 * V_154 ;
V_2 -> V_407 = 1 ;
V_154 = F_71 (
F_211 ( F_212 ( V_2 -> V_51 ) -> V_408 ) ) ;
if ( V_154 && V_154 -> V_409 ( V_2 -> V_51 ) && V_10 -> V_96 . V_410 ) {
F_10 ( V_12 , V_411 ,
F_121 ( V_306 ) ) ;
}
}
V_401 = F_156 ( & V_10 -> V_96 . V_309 , V_306 ) ;
if ( V_401 < 0 ) {
return V_247 ;
} else if ( V_401 > 0 ) {
F_10 ( V_12 , V_412 , F_121 ( V_306 ) ) ;
return V_251 ;
}
V_399 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_399 -= sizeof( V_246 ) ;
V_400 = V_413 ;
if ( ( V_399 >= V_10 -> V_175 ) && ( ! V_10 -> V_414 . V_415 ) ) {
F_10 ( V_12 , V_416 , F_16 () ) ;
}
if ( ( ! V_2 -> V_417 ) && ( ! V_10 -> V_175 || V_10 -> V_418 ||
( V_399 > V_10 -> V_175 + V_10 -> V_419 ) ) ) {
if ( F_213 ( V_403 ) &&
( F_214 ( V_403 ) + 1 ) == V_306 ) {
F_69 ( L_24 , V_306 ) ;
V_400 = V_420 ;
} else {
F_69 ( L_25
L_26 , V_306 , V_399 ,
V_10 -> V_175 ) ;
return V_252 ;
}
}
if ( * V_41 -> V_421 -> V_422 ) {
if ( F_213 ( V_403 ) &&
( F_214 ( V_403 ) + 1 ) == V_306 ) {
F_69 ( L_27 , V_306 ) ;
V_400 = V_420 ;
}
}
if ( F_3 ( 0 == V_399 ) ) {
V_181 = F_215 ( V_10 , V_2 , V_306 ) ;
if ( V_181 ) {
F_10 ( V_12 , V_58 ,
F_35 ( V_181 ) ) ;
}
F_10 ( V_12 , V_162 , F_16 () ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_299 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_423 ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_254 ;
}
V_2 -> V_417 = 1 ;
if ( V_2 -> V_5 -> V_259 & V_424 )
F_14 ( V_425 ) ;
else {
F_14 ( V_426 ) ;
V_406 = 1 ;
}
V_405 = F_2 ( V_257 -> V_310 ) ;
if ( V_405 >= V_10 -> V_86 . V_94 ) {
F_10 ( V_12 , V_427 , F_121 ( V_306 ) ) ;
V_181 = F_89 ( V_10 , V_2 , V_428 ,
& V_257 -> V_310 ,
sizeof( V_257 -> V_310 ) ,
sizeof( T_22 ) ) ;
if ( V_181 )
F_10 ( V_12 , V_58 ,
F_35 ( V_181 ) ) ;
return V_248 ;
}
V_404 = F_2 ( V_257 -> V_404 ) ;
if ( V_406 && F_216 ( V_404 , F_217 ( & V_10 -> V_429 -> V_430 , V_405 ) ) ) {
return V_256 ;
}
F_10 ( V_12 , V_400 , F_35 ( V_2 ) ) ;
return V_91 ;
}
