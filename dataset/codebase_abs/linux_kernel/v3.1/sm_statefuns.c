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
F_10 ( V_12 , V_195 ,
F_34 ( (struct V_9 * ) V_10 ) ) ;
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
if ( ! F_1 ( V_2 , sizeof( V_196 ) ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( V_197 ==
F_96 ( & V_10 -> V_40 . V_198 , & V_2 -> V_199 ) )
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
if ( ! F_1 ( V_2 , sizeof( V_196 ) ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( V_197 ==
F_96 ( & V_10 -> V_40 . V_198 , & V_2 -> V_199 ) )
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
if ( ! F_1 ( V_2 , sizeof( V_200 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
F_101 (err, chunk->chunk_hdr) {
if ( V_201 == V_181 -> V_159 )
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
V_202 = F_103 ( * ( V_210 * ) ( ( V_211 * ) V_181 + sizeof( V_158 ) ) ) ;
V_202 = ( V_202 * 2 ) / 1000 ;
V_203 . V_53 . type = V_212 ;
V_203 . V_53 . V_6 = F_72 ( sizeof( V_203 ) ) ;
V_203 . V_213 = F_104 ( V_202 ) ;
V_205 = (struct V_204 * ) & V_10 -> V_40 . V_198 ;
V_106 = F_105 ( V_10 , V_205 , V_18 , sizeof( V_203 ) ) ;
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
T_2 F_106 ( const struct V_7 * V_8 ,
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
F_96 ( & V_10 -> V_40 . V_198 , & V_2 -> V_199 ) )
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
if ( V_35 >= sizeof( struct V_220 ) + sizeof( struct V_150 ) ) {
V_158 * V_181 ;
F_101 ( V_181 , V_2 -> V_5 ) ;
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
if ( ! F_1 ( V_2 , sizeof( V_196 ) ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
V_35 = F_2 ( V_2 -> V_5 -> V_6 ) ;
if ( V_35 >= sizeof( struct V_220 ) + sizeof( struct V_150 ) )
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
V_224 , V_10 ,
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
T_12 error , int V_225 ,
const struct V_9 * V_10 ,
struct V_105 * V_66 )
{
F_69 ( L_5 ) ;
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
T_2 F_110 ( const struct V_7 * V_8 ,
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
V_227 = F_103 ( V_226 -> V_230 ) ;
if ( F_111 ( V_227 , V_10 -> V_231 ) ) {
F_69 ( L_6 , V_227 ) ;
F_69 ( L_7 , V_10 -> V_231 ) ;
return V_128 ;
}
if ( ! F_111 ( V_227 , V_10 -> V_232 ) )
return F_112 ( V_8 , V_10 , type , V_11 , V_12 ) ;
V_14 = F_113 ( V_10 , 0 , V_18 ) ;
if ( ! V_14 ) {
V_182 = V_47 ;
goto V_161;
}
F_10 ( V_12 , V_19 , F_11 ( V_14 ) ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_233 ) ) ;
V_182 = V_46 ;
if ( F_114 ( & V_10 -> V_234 ) ) {
V_182 = F_115 ( V_8 , V_10 , type ,
V_11 , V_12 ) ;
}
if ( V_47 == V_182 )
goto V_161;
F_10 ( V_12 , V_235 ,
F_116 ( V_2 -> V_48 . V_229 -> V_230 ) ) ;
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
T_13 * V_226 ;
T_14 V_227 ;
if ( ! F_38 ( V_2 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 ,
sizeof( struct V_228 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_226 = ( T_13 * ) V_2 -> V_51 -> V_52 ;
V_227 = F_103 ( V_226 -> V_230 ) ;
if ( F_111 ( V_227 , V_10 -> V_231 ) ) {
F_69 ( L_6 , V_227 ) ;
F_69 ( L_7 , V_10 -> V_231 ) ;
return V_128 ;
}
if ( ! F_111 ( V_227 , V_10 -> V_232 ) )
return F_112 ( V_8 , V_10 , type , V_11 , V_12 ) ;
F_10 ( V_12 , V_235 ,
F_116 ( V_226 -> V_230 ) ) ;
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
F_10 ( V_12 , V_236 , F_35 ( V_106 ) ) ;
F_10 ( V_12 , V_237 ,
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
V_239 = F_103 ( V_238 -> V_239 ) ;
if ( F_120 ( V_10 -> V_241 , V_239 ) ) {
F_10 ( V_12 ,
V_242 ,
F_121 ( V_239 ) ) ;
}
return V_46 ;
}
T_2 F_122 ( const struct V_7 * V_8 ,
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
F_121 ( F_103 ( V_243 -> V_239 ) ) ) ;
return V_46 ;
}
T_2 F_123 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
T_18 V_245 = F_124 () ;
int error ;
if ( ! F_38 ( V_2 , V_10 ) ) {
F_10 ( V_12 , V_246 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! F_1 ( V_2 , sizeof( V_247 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
error = F_125 ( V_10 , V_2 , V_12 ) ;
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
return F_126 ( V_8 , V_10 , V_2 , V_12 ,
( V_211 * ) V_2 -> V_48 . V_258 , sizeof( V_259 ) ) ;
default:
F_127 () ;
}
if ( V_2 -> V_5 -> V_260 & V_261 )
V_245 = F_128 () ;
if ( V_10 -> V_102 ) {
F_10 ( V_12 , V_237 ,
F_12 ( V_103 ) ) ;
}
if ( V_2 -> V_262 )
F_10 ( V_12 , V_263 , V_245 ) ;
return V_46 ;
V_254:
if ( V_2 -> V_262 )
F_10 ( V_12 , V_263 , F_128 () ) ;
return V_128 ;
V_251:
if ( V_2 -> V_262 )
F_10 ( V_12 , V_263 , V_245 ) ;
return V_128 ;
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
int error ;
if ( ! F_38 ( V_2 , V_10 ) ) {
F_10 ( V_12 , V_246 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! F_1 ( V_2 , sizeof( V_247 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
error = F_125 ( V_10 , V_2 , V_12 ) ;
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
return F_126 ( V_8 , V_10 , V_2 , V_12 ,
( V_211 * ) V_2 -> V_48 . V_258 , sizeof( V_259 ) ) ;
default:
F_127 () ;
}
if ( V_2 -> V_262 ) {
F_10 ( V_12 , V_264 , F_16 () ) ;
F_10 ( V_12 , V_263 , F_128 () ) ;
F_10 ( V_12 , V_237 ,
F_12 ( V_21 ) ) ;
}
V_256:
return V_46 ;
}
T_2 F_130 ( const struct V_7 * V_8 ,
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
V_265 = F_131 ( V_2 ) ;
if ( ! V_265 )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
V_2 -> V_48 . V_267 = V_265 ;
V_227 = F_103 ( V_265 -> V_230 ) ;
if ( F_111 ( V_227 , V_10 -> V_231 ) ) {
F_69 ( L_6 , V_227 ) ;
F_69 ( L_7 , V_10 -> V_231 ) ;
return V_128 ;
}
if ( ! F_111 ( V_227 , V_10 -> V_232 ) )
return F_112 ( V_8 , V_10 , type , V_11 , V_12 ) ;
F_10 ( V_12 , V_268 , F_132 ( V_265 ) ) ;
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
if ( ! F_1 ( V_2 , sizeof( V_200 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
F_101 ( V_181 , V_2 -> V_5 ) ;
if ( ( void * ) V_181 != ( void * ) V_2 -> V_221 )
return F_139 ( V_8 , V_10 , type , V_11 ,
( void * ) V_181 , V_12 ) ;
F_10 ( V_12 , V_269 ,
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
T_2 F_84 ( const struct V_7 * V_8 ,
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
F_101 (err, ch) {
if ( V_201 == V_181 -> V_159 ) {
V_275 = 1 ;
break;
}
}
}
V_273 = ( ( V_43 * ) V_272 ) + F_142 ( F_2 ( V_272 -> V_6 ) ) ;
if ( V_273 > F_143 ( V_51 ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_272 = ( V_16 * ) V_273 ;
} while ( V_273 < F_143 ( V_51 ) );
if ( V_274 )
return F_144 ( V_8 , V_10 , type , V_11 , V_12 ) ;
else if ( V_275 )
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
struct V_1 * V_279 ;
V_33 = F_133 ( V_10 , V_2 ) ;
if ( V_33 ) {
V_279 = F_141 ( V_10 , V_2 ) ;
if ( ! V_279 ) {
F_135 ( V_33 ) ;
return V_47 ;
}
if ( F_136 ( V_279 ) )
V_33 -> V_38 = F_103 ( V_2 -> V_37 -> V_38 ) ;
V_279 -> V_51 -> V_41 = V_8 -> V_40 . V_41 ;
F_137 ( V_33 , V_279 ) ;
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
return F_85 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_2 , sizeof( V_287 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_283 = ( T_20 * ) V_2 -> V_51 -> V_52 ;
V_285 = F_103 ( V_283 -> V_285 ) ;
V_284 = (union V_148 * ) V_283 -> V_288 ;
V_6 = F_2 ( V_284 -> V_289 . V_6 ) ;
if ( V_6 < sizeof( V_290 ) )
return F_139 ( V_8 , V_10 , type , V_11 ,
( void * ) V_284 , V_12 ) ;
if ( ! F_147 ( V_10 ,
( V_290 * ) ( ( void * ) V_284 + V_6 ) ,
( void * ) V_2 -> V_221 ,
& V_282 ) )
return F_139 ( V_8 , V_10 , type , V_11 ,
( void * ) V_282 , V_12 ) ;
if ( V_285 == V_10 -> V_96 . V_291 + 1 ) {
if ( ! V_2 -> V_292 )
F_148 ( V_10 ) ;
V_280 = F_149 ( (struct V_9 * )
V_10 , V_2 ) ;
if ( ! V_280 )
return V_47 ;
} else if ( V_285 < V_10 -> V_96 . V_291 + 1 ) {
V_280 = F_150 ( V_10 , V_283 -> V_285 ) ;
if ( ! V_280 )
return V_128 ;
V_280 -> V_66 = NULL ;
} else {
return V_128 ;
}
V_280 -> V_199 = V_2 -> V_293 ;
F_10 ( V_12 , V_58 , F_35 ( V_280 ) ) ;
return V_46 ;
}
T_2 F_151 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type , void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_280 = V_11 ;
struct V_1 * V_294 = V_10 -> V_295 ;
struct V_1 * abort ;
struct V_281 * V_282 = NULL ;
T_20 * V_296 ;
T_14 V_297 , V_298 ;
if ( ! F_38 ( V_280 , V_10 ) ) {
F_10 ( V_12 , V_246 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! V_286 && ! V_280 -> V_89 )
return F_85 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_280 , sizeof( V_287 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_296 = ( T_20 * ) V_280 -> V_51 -> V_52 ;
V_298 = F_103 ( V_296 -> V_285 ) ;
if ( ! F_147 ( V_10 ,
( V_290 * ) V_296 -> V_288 ,
( void * ) V_280 -> V_221 ,
& V_282 ) )
return F_139 ( V_8 , V_10 , type , V_11 ,
( void * ) V_282 , V_12 ) ;
if ( V_294 ) {
V_296 = ( T_20 * ) V_294 -> V_48 . V_296 ;
V_297 = F_103 ( V_296 -> V_285 ) ;
} else {
V_297 = V_10 -> V_291 - 1 ;
}
if ( F_152 ( V_298 , V_297 + 1 ) &&
! ( V_10 -> V_295 ) ) {
abort = F_134 ( V_10 , V_280 ,
sizeof( V_158 ) ) ;
if ( abort ) {
F_153 ( abort , V_299 , 0 ) ;
F_10 ( V_12 , V_58 ,
F_35 ( abort ) ) ;
}
F_10 ( V_12 , V_20 ,
F_12 ( V_188 ) ) ;
F_10 ( V_12 , V_162 , F_16 () ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_300 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_299 ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_223 ;
}
if ( ( V_298 == V_297 ) && V_10 -> V_295 ) {
F_10 ( V_12 , V_20 ,
F_12 ( V_188 ) ) ;
if ( ! F_154 ( (struct V_9 * ) V_10 ,
V_280 ) ) {
F_10 ( V_12 , V_301 ,
F_16 () ) ;
return V_46 ;
}
abort = F_134 ( V_10 , V_280 ,
sizeof( V_158 ) ) ;
if ( abort ) {
F_153 ( abort , V_302 , 0 ) ;
F_10 ( V_12 , V_58 ,
F_35 ( abort ) ) ;
}
F_10 ( V_12 , V_162 , F_16 () ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_300 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_299 ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_223 ;
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
struct V_303 * V_304 ;
struct V_305 * V_306 ;
T_1 V_35 ;
T_14 V_307 ;
if ( ! F_38 ( V_2 , V_10 ) ) {
F_10 ( V_12 , V_246 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_308 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_304 = (struct V_303 * ) V_2 -> V_51 -> V_52 ;
V_2 -> V_48 . V_304 = V_304 ;
V_35 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_35 -= sizeof( struct V_220 ) ;
F_26 ( V_2 -> V_51 , V_35 ) ;
V_307 = F_103 ( V_304 -> V_309 ) ;
F_69 ( L_8 , V_133 , V_307 ) ;
if ( F_156 ( & V_10 -> V_96 . V_310 , V_307 ) < 0 )
goto V_251;
F_157 (skip, chunk) {
if ( F_2 ( V_306 -> V_311 ) >= V_10 -> V_86 . V_94 )
goto V_251;
}
F_10 ( V_12 , V_312 , F_121 ( V_307 ) ) ;
if ( V_35 > sizeof( struct V_303 ) )
F_10 ( V_12 , V_313 ,
F_35 ( V_2 ) ) ;
if ( V_10 -> V_102 ) {
F_10 ( V_12 , V_237 ,
F_12 ( V_103 ) ) ;
}
F_10 ( V_12 , V_263 , F_124 () ) ;
return V_46 ;
V_251:
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
struct V_303 * V_304 ;
struct V_305 * V_306 ;
T_1 V_35 ;
T_14 V_307 ;
if ( ! F_38 ( V_2 , V_10 ) ) {
F_10 ( V_12 , V_246 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_308 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_304 = (struct V_303 * ) V_2 -> V_51 -> V_52 ;
V_2 -> V_48 . V_304 = V_304 ;
V_35 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_35 -= sizeof( struct V_220 ) ;
F_26 ( V_2 -> V_51 , V_35 ) ;
V_307 = F_103 ( V_304 -> V_309 ) ;
F_69 ( L_8 , V_133 , V_307 ) ;
if ( F_156 ( & V_10 -> V_96 . V_310 , V_307 ) < 0 )
goto V_314;
F_157 (skip, chunk) {
if ( F_2 ( V_306 -> V_311 ) >= V_10 -> V_86 . V_94 )
goto V_314;
}
F_10 ( V_12 , V_312 , F_121 ( V_307 ) ) ;
if ( V_35 > sizeof( struct V_303 ) )
F_10 ( V_12 , V_313 ,
F_35 ( V_2 ) ) ;
V_314:
F_10 ( V_12 , V_264 , F_16 () ) ;
F_10 ( V_12 , V_263 , F_128 () ) ;
F_10 ( V_12 , V_237 ,
F_12 ( V_21 ) ) ;
return V_46 ;
}
static T_7 F_50 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
struct V_1 * V_2 )
{
struct V_315 * V_316 ;
struct V_317 * V_318 ;
unsigned int V_319 ;
T_1 V_320 ;
V_43 * V_321 ;
V_43 * V_322 ;
V_316 = (struct V_315 * ) V_2 -> V_51 -> V_52 ;
V_2 -> V_48 . V_316 = V_316 ;
F_26 ( V_2 -> V_51 , sizeof( struct V_315 ) ) ;
if ( ! F_159 ( V_10 , V_316 -> V_323 ) )
return V_324 ;
V_320 = F_2 ( V_316 -> V_325 ) ;
if ( V_320 != V_10 -> V_326 && ! F_160 ( V_10 , V_320 ) )
return V_327 ;
V_319 = F_2 ( V_2 -> V_5 -> V_6 ) - sizeof( V_328 ) ;
V_318 = F_161 ( F_2 ( V_316 -> V_323 ) ) ;
if ( V_319 != V_318 -> V_329 )
return V_257 ;
V_322 = V_316 -> V_318 ;
F_26 ( V_2 -> V_51 , V_319 ) ;
V_321 = F_162 ( V_322 , V_319 , V_18 ) ;
if ( ! V_321 )
goto V_55;
memset ( V_322 , 0 , V_319 ) ;
F_163 ( V_10 , V_2 -> V_51 ,
(struct V_330 * ) V_2 -> V_5 ,
V_18 ) ;
if ( memcmp ( V_321 , V_322 , V_319 ) ) {
F_164 ( V_321 ) ;
return V_85 ;
}
F_164 ( V_321 ) ;
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
struct V_315 * V_316 ;
struct V_1 * V_2 = V_11 ;
struct V_1 * V_31 ;
T_7 error ;
if ( ! V_10 -> V_96 . V_331 )
return F_166 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_38 ( V_2 , V_10 ) ) {
F_10 ( V_12 , V_246 ,
F_16 () ) ;
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
}
if ( ! F_1 ( V_2 , sizeof( struct V_330 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
V_316 = (struct V_315 * ) V_2 -> V_51 -> V_52 ;
error = F_50 ( V_8 , V_10 , type , V_2 ) ;
switch ( error ) {
case V_324 :
V_31 = F_89 ( V_10 , V_2 ,
V_332 ,
& V_316 -> V_323 ,
sizeof( T_1 ) , 0 ) ;
if ( V_31 ) {
F_10 ( V_12 , V_58 ,
F_35 ( V_31 ) ) ;
}
case V_327 :
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
if ( V_10 -> V_326 != F_2 ( V_316 -> V_325 ) ) {
struct V_13 * V_14 ;
V_14 = F_167 ( V_10 , F_2 ( V_316 -> V_325 ) ,
V_333 , V_18 ) ;
if ( ! V_14 )
return - V_334 ;
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
struct V_1 * V_335 = V_11 ;
struct V_1 * V_31 ;
V_16 * V_283 ;
F_69 ( L_9 , type . V_2 ) ;
if ( ! F_38 ( V_335 , V_10 ) )
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
if ( ! F_1 ( V_335 , sizeof( V_16 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
switch ( type . V_2 & V_336 ) {
case V_337 :
return F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
break;
case V_338 :
V_283 = V_335 -> V_5 ;
V_31 = F_89 ( V_10 , V_335 ,
V_339 , V_283 ,
F_142 ( F_2 ( V_283 -> V_6 ) ) ,
0 ) ;
if ( V_31 ) {
F_10 ( V_12 , V_58 ,
F_35 ( V_31 ) ) ;
}
F_6 ( V_8 , V_10 , type , V_11 , V_12 ) ;
return V_46 ;
break;
case V_340 :
return V_128 ;
break;
case V_341 :
V_283 = V_335 -> V_5 ;
V_31 = F_89 ( V_10 , V_335 ,
V_339 , V_283 ,
F_142 ( F_2 ( V_283 -> V_6 ) ) ,
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
F_14 ( V_342 ) ;
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
return V_343 ;
}
static T_2 F_126 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
void * V_11 ,
T_4 * V_12 ,
const V_43 * V_344 ,
const T_8 V_119 )
{
struct V_32 * V_33 = NULL ;
struct V_1 * V_2 = V_11 ;
struct V_1 * abort = NULL ;
if ( F_39 ( V_63 , V_10 ) )
goto V_345;
abort = F_169 ( V_10 , V_2 , V_344 , V_119 ) ;
if ( ! abort )
goto V_55;
if ( V_10 ) {
if ( V_2 -> V_5 -> type == V_346 &&
! V_10 -> V_96 . V_347 . V_348 ) {
V_60 * V_349 ;
V_349 = ( V_60 * ) V_2 -> V_5 ;
if ( ! F_1 ( V_2 ,
sizeof( V_60 ) ) )
abort -> V_5 -> V_260 |= V_350 ;
else {
unsigned int V_351 ;
V_351 = F_103 ( V_349 -> V_49 . V_348 ) ;
F_10 ( V_12 , V_352 ,
F_121 ( V_351 ) ) ;
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
F_61 ( V_353 ) ) ;
} else {
F_10 ( V_12 , V_110 ,
F_60 ( V_300 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_353 ) ) ;
F_15 ( V_26 ) ;
}
} else {
V_33 = F_133 ( V_10 , V_2 ) ;
if ( ! V_33 )
goto V_354;
if ( F_136 ( abort ) )
V_33 -> V_38 = F_103 ( V_2 -> V_37 -> V_38 ) ;
abort -> V_51 -> V_41 = V_8 -> V_40 . V_41 ;
F_137 ( V_33 , abort ) ;
F_10 ( V_12 , V_44 ,
F_25 ( V_33 ) ) ;
F_14 ( V_45 ) ;
}
F_14 ( V_64 ) ;
V_345:
F_6 ( V_8 , V_10 , F_88 ( 0 ) , V_11 , V_12 ) ;
return V_223 ;
V_354:
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
static const char V_355 [] = L_11 ;
return F_126 ( V_8 , V_10 , V_11 , V_12 , V_355 ,
sizeof( V_355 ) ) ;
}
static T_2 F_139 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 , void * V_356 ,
T_4 * V_12 )
{
struct V_1 * V_2 = V_11 ;
struct V_281 * V_357 = V_356 ;
struct V_1 * abort = NULL ;
if ( F_39 ( V_63 , V_10 ) )
goto V_345;
abort = F_170 ( V_10 , V_2 , V_357 ) ;
if ( ! abort )
goto V_55;
F_10 ( V_12 , V_58 , F_35 ( abort ) ) ;
F_14 ( V_45 ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_300 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_353 ) ) ;
F_15 ( V_26 ) ;
F_14 ( V_64 ) ;
V_345:
F_6 ( V_8 , V_10 , F_88 ( 0 ) , V_11 , V_12 ) ;
return V_223 ;
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
static const char V_355 [] = L_12 ;
return F_126 ( V_8 , V_10 , V_11 , V_12 , V_355 ,
sizeof( V_355 ) ) ;
}
static T_2 F_7 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
static const char V_355 [] = L_13 ;
if ( ! V_10 )
return F_168 ( V_8 , V_10 , type , V_11 , V_12 ) ;
return F_126 ( V_8 , V_10 , V_11 , V_12 , V_355 ,
sizeof( V_355 ) ) ;
}
T_2 F_171 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_29 ;
struct V_9 * V_358 ;
F_10 ( V_12 , V_23 ,
F_13 ( V_170 ) ) ;
V_29 = F_105 ( V_10 , & V_10 -> V_40 . V_198 , V_18 , 0 ) ;
if ( ! V_29 )
goto V_55;
V_358 = (struct V_9 * ) V_10 ;
F_10 ( V_12 , V_57 , F_34 ( V_358 ) ) ;
F_10 ( V_12 , V_359 ,
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
struct V_360 * V_361 = V_11 ;
F_10 ( V_12 , V_362 , F_173 ( V_361 ) ) ;
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
F_13 ( V_363 ) ) ;
V_182 = V_46 ;
if ( F_114 ( & V_10 -> V_234 ) ) {
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
F_60 ( V_300 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_364 ) ) ;
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
F_10 ( V_12 , V_365 , F_60 ( - V_366 ) ) ;
return V_46 ;
}
T_2 F_178 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_10 ( V_12 , V_365 ,
F_60 ( - V_367 ) ) ;
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
F_10 ( V_12 , V_209 ,
F_61 ( V_364 ) ) ;
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
F_10 ( V_12 , V_368 , F_35 ( V_2 ) ) ;
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
F_69 ( L_14 , type . V_369 ) ;
return V_128 ;
}
T_2 F_189 (
const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_13 * V_370 ;
V_370 = F_190 ( V_10 , V_18 ) ;
if ( ! V_370 )
return V_47 ;
F_10 ( V_12 , V_19 , F_11 ( V_370 ) ) ;
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
F_10 ( V_12 , V_236 , F_35 ( V_106 ) ) ;
F_10 ( V_12 , V_70 ,
F_12 ( V_21 ) ) ;
F_10 ( V_12 , V_237 ,
F_12 ( V_22 ) ) ;
if ( V_10 -> V_102 )
F_10 ( V_12 , V_20 ,
F_12 ( V_103 ) ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_371 ) ) ;
F_10 ( V_12 , V_215 , F_16 () ) ;
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
if ( ! F_1 ( V_2 , sizeof( struct V_228 ) ) )
return F_8 ( V_8 , V_10 , type , V_11 ,
V_12 ) ;
}
V_106 = F_118 ( V_10 , V_2 ) ;
if ( ! V_106 )
goto V_55;
F_10 ( V_12 , V_236 , F_35 ( V_106 ) ) ;
F_10 ( V_12 , V_237 ,
F_12 ( V_21 ) ) ;
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
T_2 F_192 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_69 ( L_15 , type . V_373 ) ;
return V_128 ;
}
T_2 F_193 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_105 * V_66 = V_11 ;
F_14 ( V_374 ) ;
if ( V_10 -> V_108 >= V_10 -> V_109 ) {
if ( V_10 -> V_169 == V_363 ) {
F_10 ( V_12 , V_375 ,
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
F_10 ( V_12 , V_376 , F_58 ( V_66 ) ) ;
F_10 ( V_12 , V_377 , F_58 ( V_66 ) ) ;
return V_46 ;
}
T_2 F_194 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
F_14 ( V_378 ) ;
F_10 ( V_12 , V_263 , F_128 () ) ;
return V_46 ;
}
T_2 F_195 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_29 = NULL ;
struct V_204 * V_205 ;
int V_206 = V_10 -> V_207 + 1 ;
F_69 ( L_16 ) ;
F_14 ( V_379 ) ;
if ( V_206 <= V_10 -> V_208 ) {
V_205 = (struct V_204 * ) & V_10 -> V_40 . V_198 ;
V_29 = F_105 ( V_10 , V_205 , V_18 , 0 ) ;
if ( ! V_29 )
return V_47 ;
F_10 ( V_12 , V_359 ,
F_35 ( V_29 ) ) ;
F_10 ( V_12 , V_380 ,
F_12 ( V_69 ) ) ;
F_10 ( V_12 , V_58 , F_35 ( V_29 ) ) ;
} else {
F_69 ( L_17
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
T_2 F_196 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_29 = NULL ;
int V_206 = V_10 -> V_207 + 1 ;
F_69 ( L_19 ) ;
F_14 ( V_381 ) ;
if ( V_206 <= V_10 -> V_208 ) {
V_29 = F_197 ( V_10 , NULL ) ;
if ( ! V_29 )
return V_47 ;
F_10 ( V_12 , V_359 ,
F_35 ( V_29 ) ) ;
F_10 ( V_12 , V_382 ,
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
T_2 F_198 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
struct V_1 * V_106 = NULL ;
F_69 ( L_20 ) ;
F_14 ( V_383 ) ;
( (struct V_9 * ) V_10 ) -> V_384 ++ ;
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
case V_371 :
V_106 = F_191 ( V_10 , NULL ) ;
break;
case V_372 :
V_106 = F_118 ( V_10 , NULL ) ;
break;
default:
F_127 () ;
break;
}
if ( ! V_106 )
goto V_55;
if ( V_10 -> V_385 )
F_10 ( V_12 , V_376 ,
F_58 ( V_10 -> V_385 ) ) ;
F_10 ( V_12 , V_236 , F_35 ( V_106 ) ) ;
F_10 ( V_12 , V_237 ,
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
struct V_1 * V_2 = V_10 -> V_295 ;
struct V_105 * V_66 = V_2 -> V_66 ;
F_14 ( V_386 ) ;
if ( V_66 )
F_10 ( V_12 , V_376 ,
F_58 ( V_66 ) ) ;
F_10 ( V_12 , V_368 , F_35 ( V_2 ) ) ;
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
F_200 ( V_10 -> V_295 ) ;
F_10 ( V_12 , V_58 ,
F_35 ( V_10 -> V_295 ) ) ;
F_10 ( V_12 , V_237 ,
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
F_14 ( V_387 ) ;
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
F_14 ( V_388 ) ;
F_10 ( V_12 , V_23 ,
F_13 ( V_363 ) ) ;
V_182 = V_46 ;
if ( F_114 ( & V_10 -> V_234 ) ) {
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
return V_389 ;
}
T_2 F_204 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
const T_3 type ,
void * V_11 ,
T_4 * V_12 )
{
return V_390 ;
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
static struct V_391 * F_131 ( struct V_1 * V_2 )
{
struct V_391 * V_392 ;
unsigned int V_35 ;
T_1 V_393 ;
T_1 V_394 ;
V_392 = (struct V_391 * ) V_2 -> V_51 -> V_52 ;
V_393 = F_2 ( V_392 -> V_395 ) ;
V_394 = F_2 ( V_392 -> V_394 ) ;
V_35 = sizeof( struct V_391 ) ;
V_35 += ( V_393 + V_394 ) * sizeof( T_14 ) ;
if ( V_35 > V_2 -> V_51 -> V_35 )
return NULL ;
F_26 ( V_2 -> V_51 , V_35 ) ;
return V_392 ;
}
static struct V_32 * F_23 ( const struct V_7 * V_8 ,
const struct V_9 * V_10 ,
struct V_1 * V_2 ,
const void * V_344 ,
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
F_33 ( abort , V_119 , V_344 ) ;
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
T_1 V_396 ;
T_1 V_397 ;
T_14 V_38 ;
V_396 = F_2 ( V_2 -> V_37 -> V_199 ) ;
V_397 = F_2 ( V_2 -> V_37 -> V_293 ) ;
if ( V_10 ) {
switch( V_2 -> V_5 -> type ) {
case V_346 :
{
V_60 * V_349 ;
V_349 = ( V_60 * ) V_2 -> V_5 ;
V_38 = F_103 ( V_349 -> V_49 . V_348 ) ;
break;
}
default:
V_38 = V_10 -> V_96 . V_347 . V_348 ;
break;
}
} else {
switch( V_2 -> V_5 -> type ) {
case V_398 :
{
V_39 * V_146 ;
V_146 = ( V_39 * ) V_2 -> V_5 ;
V_38 = F_103 ( V_146 -> V_49 . V_348 ) ;
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
F_207 ( V_66 , (union V_123 * ) & V_2 -> V_199 ,
F_18 ( F_19 () ) ) ;
V_33 = F_208 ( & V_66 -> V_33 , V_66 , V_396 , V_397 ) ;
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
struct V_82 * V_399 ;
V_399 = V_2 -> V_48 . V_81 ;
V_33 -> V_38 = V_399 -> V_86 . V_174 ;
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
V_259 * V_258 ;
struct V_1 * V_181 ;
T_8 V_400 ;
T_21 V_401 ;
int V_402 ;
T_14 V_307 ;
struct V_403 * V_404 = (struct V_403 * ) & V_10 -> V_96 . V_310 ;
struct V_78 * V_41 = V_10 -> V_40 . V_41 ;
T_22 V_405 ;
T_22 V_406 ;
V_211 V_407 = 0 ;
V_258 = V_2 -> V_48 . V_258 = ( V_259 * ) V_2 -> V_51 -> V_52 ;
F_26 ( V_2 -> V_51 , sizeof( V_259 ) ) ;
V_307 = F_103 ( V_258 -> V_307 ) ;
F_69 ( L_23 , V_307 ) ;
if ( ! V_2 -> V_408 ) {
struct V_153 * V_154 ;
V_2 -> V_408 = 1 ;
V_154 = F_71 (
F_211 ( F_212 ( V_2 -> V_51 ) -> V_409 ) ) ;
if ( V_154 && V_154 -> V_410 ( V_2 -> V_51 ) && V_10 -> V_96 . V_411 ) {
F_10 ( V_12 , V_412 ,
F_121 ( V_307 ) ) ;
}
}
V_402 = F_156 ( & V_10 -> V_96 . V_310 , V_307 ) ;
if ( V_402 < 0 ) {
return V_248 ;
} else if ( V_402 > 0 ) {
F_10 ( V_12 , V_413 , F_121 ( V_307 ) ) ;
return V_252 ;
}
V_400 = F_2 ( V_2 -> V_5 -> V_6 ) ;
V_400 -= sizeof( V_247 ) ;
V_401 = V_414 ;
if ( ( V_400 >= V_10 -> V_175 ) && ( ! V_10 -> V_415 . V_416 ) ) {
F_10 ( V_12 , V_417 , F_16 () ) ;
}
if ( ( ! V_2 -> V_418 ) && ( ! V_10 -> V_175 || V_10 -> V_419 ||
( V_400 > V_10 -> V_175 + V_10 -> V_420 ) ) ) {
if ( F_213 ( V_404 ) &&
( F_214 ( V_404 ) + 1 ) == V_307 ) {
F_69 ( L_24 , V_307 ) ;
V_401 = V_421 ;
} else {
F_69 ( L_25
L_26 , V_307 , V_400 ,
V_10 -> V_175 ) ;
return V_253 ;
}
}
if ( * V_41 -> V_422 -> V_423 ) {
if ( F_213 ( V_404 ) &&
( F_214 ( V_404 ) + 1 ) == V_307 ) {
F_69 ( L_27 , V_307 ) ;
V_401 = V_421 ;
}
}
if ( F_3 ( 0 == V_400 ) ) {
V_181 = F_215 ( V_10 , V_2 , V_307 ) ;
if ( V_181 ) {
F_10 ( V_12 , V_58 ,
F_35 ( V_181 ) ) ;
}
F_10 ( V_12 , V_162 , F_16 () ) ;
F_10 ( V_12 , V_110 ,
F_60 ( V_300 ) ) ;
F_10 ( V_12 , V_112 ,
F_61 ( V_424 ) ) ;
F_14 ( V_64 ) ;
F_15 ( V_26 ) ;
return V_255 ;
}
V_2 -> V_418 = 1 ;
if ( V_2 -> V_5 -> V_260 & V_425 )
F_14 ( V_426 ) ;
else {
F_14 ( V_427 ) ;
V_407 = 1 ;
}
V_406 = F_2 ( V_258 -> V_311 ) ;
if ( V_406 >= V_10 -> V_86 . V_94 ) {
F_10 ( V_12 , V_428 , F_121 ( V_307 ) ) ;
V_181 = F_89 ( V_10 , V_2 , V_429 ,
& V_258 -> V_311 ,
sizeof( V_258 -> V_311 ) ,
sizeof( T_22 ) ) ;
if ( V_181 )
F_10 ( V_12 , V_58 ,
F_35 ( V_181 ) ) ;
return V_249 ;
}
V_405 = F_2 ( V_258 -> V_405 ) ;
if ( V_407 && F_216 ( V_405 , F_217 ( & V_10 -> V_430 -> V_431 , V_406 ) ) ) {
return V_257 ;
}
F_10 ( V_12 , V_401 , F_35 ( V_2 ) ) ;
return V_91 ;
}
