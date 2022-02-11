static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
V_2 -> V_4 = V_3 ;
V_2 -> V_5 = 1 ;
}
static struct V_6 * F_2 ( struct V_1 * V_2 ,
T_1 V_3 ,
struct V_6 * V_7 )
{
struct V_6 * V_8 ;
if ( F_3 ( V_2 -> V_9 , V_3 ) ) {
struct V_10 * V_11 ;
V_11 = F_4 ( V_2 , V_3 ) ;
if ( V_11 )
F_5 ( V_11 ,
V_12 ) ;
V_2 -> V_9 = V_3 ;
}
V_8 = F_6 ( V_2 , V_2 -> V_9 , V_7 ) ;
return V_8 ;
}
static void F_7 ( struct V_1 * V_2 ,
T_1 V_3 )
{
V_2 -> V_5 = 0 ;
}
static int F_8 ( struct V_1 * V_2 , int V_13 ,
T_2 * V_14 )
{
T_1 V_15 , V_16 ;
struct V_6 * V_17 ;
struct V_10 * V_18 = V_2 -> V_19 . V_20 ;
int error = 0 ;
if ( V_13 ||
( ! V_18 && ( V_2 -> V_21 & V_22 ) ) ||
( V_18 && ( V_18 -> V_21 & V_22 ) ) )
V_2 -> V_19 . V_23 = 1 ;
V_15 = F_9 ( & V_2 -> V_19 . V_24 ) ;
V_16 = F_10 ( & V_2 -> V_19 . V_24 ) ;
if ( V_16 != V_15 )
V_2 -> V_19 . V_23 = 1 ;
if ( ! V_2 -> V_19 . V_23 ) {
V_2 -> V_19 . V_25 ++ ;
if ( V_18 ) {
if ( V_2 -> V_19 . V_25 >= V_18 -> V_26 - 1 )
V_2 -> V_19 . V_23 = 1 ;
V_2 -> V_27 [ V_28 ] =
V_18 -> V_29 ;
} else {
if ( V_2 -> V_19 . V_25 >= V_2 -> V_26 - 1 )
V_2 -> V_19 . V_23 = 1 ;
V_2 -> V_27 [ V_28 ] =
V_2 -> V_29 ;
}
F_11 ( V_14 , V_30 ,
F_12 ( V_28 ) ) ;
} else {
V_2 -> V_31 = V_2 -> V_32 ;
V_17 = F_13 ( V_2 ) ;
if ( ! V_17 )
goto V_33;
V_2 -> V_19 . V_23 = 0 ;
V_2 -> V_19 . V_25 = 0 ;
F_11 ( V_14 , V_34 , F_14 ( V_17 ) ) ;
F_11 ( V_14 , V_35 ,
F_12 ( V_28 ) ) ;
}
return error ;
V_33:
error = - V_36 ;
return error ;
}
void F_15 ( unsigned long V_19 )
{
int error ;
struct V_10 * V_11 = (struct V_10 * ) V_19 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_37 * V_37 = F_16 ( V_2 -> V_38 . V_39 ) ;
F_17 ( V_2 -> V_38 . V_39 ) ;
if ( F_18 ( V_2 -> V_38 . V_39 ) ) {
F_19 ( L_1 , V_40 ) ;
if ( ! F_20 ( & V_11 -> V_41 , V_42 + ( V_43 / 20 ) ) )
F_21 ( V_11 ) ;
goto V_44;
}
if ( V_11 -> V_45 )
goto V_44;
error = F_22 ( V_37 , V_46 ,
F_23 ( V_47 ) ,
V_2 -> V_48 ,
V_2 -> V_49 , V_2 ,
V_11 , V_50 ) ;
if ( error )
V_2 -> V_38 . V_39 -> V_51 = - error ;
V_44:
F_24 ( V_2 -> V_38 . V_39 ) ;
F_25 ( V_11 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
T_3 V_52 )
{
struct V_37 * V_37 = F_16 ( V_2 -> V_38 . V_39 ) ;
int error = 0 ;
F_17 ( V_2 -> V_38 . V_39 ) ;
if ( F_18 ( V_2 -> V_38 . V_39 ) ) {
F_19 ( L_2 ,
V_40 ,
V_52 ) ;
if ( ! F_20 ( & V_2 -> V_53 [ V_52 ] , V_42 + ( V_43 / 20 ) ) )
F_27 ( V_2 ) ;
goto V_44;
}
if ( V_2 -> V_38 . V_45 )
goto V_44;
error = F_22 ( V_37 , V_46 ,
F_23 ( V_52 ) ,
V_2 -> V_48 , V_2 -> V_49 , V_2 ,
( void * ) V_52 , V_50 ) ;
if ( error )
V_2 -> V_38 . V_39 -> V_51 = - error ;
V_44:
F_24 ( V_2 -> V_38 . V_39 ) ;
F_28 ( V_2 ) ;
}
static void F_29 ( unsigned long V_54 )
{
struct V_1 * V_2 = (struct V_1 * ) V_54 ;
F_26 ( V_2 , V_55 ) ;
}
static void F_30 ( unsigned long V_54 )
{
struct V_1 * V_2 = (struct V_1 * ) V_54 ;
F_26 ( V_2 , V_56 ) ;
}
static void F_31 ( unsigned long V_54 )
{
struct V_1 * V_2 = (struct V_1 * ) V_54 ;
F_26 ( V_2 , V_57 ) ;
}
static void F_32 ( unsigned long V_54 )
{
struct V_1 * V_2 = (struct V_1 * ) V_54 ;
F_26 ( V_2 , V_58 ) ;
}
static void F_33 ( unsigned long V_54 )
{
struct V_1 * V_2 = (struct V_1 * ) V_54 ;
F_26 ( V_2 ,
V_59 ) ;
}
static void F_34 ( unsigned long V_54 )
{
struct V_1 * V_2 = (struct V_1 * ) V_54 ;
F_26 ( V_2 , V_60 ) ;
}
void F_35 ( unsigned long V_54 )
{
int error = 0 ;
struct V_10 * V_11 = (struct V_10 * ) V_54 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_37 * V_37 = F_16 ( V_2 -> V_38 . V_39 ) ;
F_17 ( V_2 -> V_38 . V_39 ) ;
if ( F_18 ( V_2 -> V_38 . V_39 ) ) {
F_19 ( L_1 , V_40 ) ;
if ( ! F_20 ( & V_11 -> V_61 , V_42 + ( V_43 / 20 ) ) )
F_21 ( V_11 ) ;
goto V_44;
}
if ( V_11 -> V_45 )
goto V_44;
error = F_22 ( V_37 , V_46 ,
F_23 ( V_62 ) ,
V_2 -> V_48 , V_2 -> V_49 , V_2 ,
V_11 , V_50 ) ;
if ( error )
V_2 -> V_38 . V_39 -> V_51 = - error ;
V_44:
F_24 ( V_2 -> V_38 . V_39 ) ;
F_25 ( V_11 ) ;
}
void F_36 ( unsigned long V_54 )
{
struct V_10 * V_11 = (struct V_10 * ) V_54 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_37 * V_37 = F_16 ( V_2 -> V_38 . V_39 ) ;
F_17 ( V_2 -> V_38 . V_39 ) ;
if ( F_18 ( V_2 -> V_38 . V_39 ) ) {
F_19 ( L_1 , V_40 ) ;
if ( ! F_20 ( & V_11 -> V_63 ,
V_42 + ( V_43 / 20 ) ) )
F_27 ( V_2 ) ;
goto V_44;
}
if ( V_2 -> V_38 . V_45 )
goto V_44;
F_22 ( V_37 , V_64 ,
F_37 ( V_65 ) ,
V_2 -> V_48 , V_2 -> V_49 , V_2 , V_11 , V_50 ) ;
V_44:
F_24 ( V_2 -> V_38 . V_39 ) ;
F_28 ( V_2 ) ;
}
static void F_38 ( unsigned long V_54 )
{
struct V_1 * V_2 = (struct V_1 * ) V_54 ;
F_26 ( V_2 , V_28 ) ;
}
static void F_39 ( T_2 * V_14 ,
struct V_1 * V_2 ,
struct V_10 * V_11 ,
int V_66 )
{
if ( ! V_66 ) {
V_2 -> V_67 ++ ;
if ( V_11 -> V_48 != V_68 )
V_11 -> V_69 ++ ;
} else if ( V_11 -> V_70 ) {
if ( V_11 -> V_48 != V_71 )
V_2 -> V_67 ++ ;
if ( V_11 -> V_48 != V_68 )
V_11 -> V_69 ++ ;
}
if ( ( V_11 -> V_48 != V_72 ) &&
( V_2 -> V_73 < V_11 -> V_74 ) &&
( V_11 -> V_69 > V_2 -> V_73 ) ) {
F_40 ( V_2 , V_11 ,
V_75 ,
0 ) ;
F_41 ( V_14 , V_11 ) ;
}
if ( V_11 -> V_48 != V_68 &&
( V_11 -> V_69 > V_11 -> V_74 ) ) {
F_42 ( L_3 ,
L_4 ,
V_2 ,
( & V_11 -> V_76 ) ,
F_43 ( V_11 -> V_76 . V_77 . V_78 ) ) ;
F_40 ( V_2 , V_11 ,
V_79 ,
V_80 ) ;
}
if ( ! V_66 || V_11 -> V_70 ) {
V_11 -> V_81 = F_44 ( ( V_11 -> V_81 * 2 ) , V_11 -> V_2 -> V_82 ) ;
}
}
static void F_45 ( T_2 * V_14 ,
struct V_1 * V_2 ,
unsigned int error )
{
struct V_83 * V_84 ;
V_84 = F_46 ( V_2 , 0 , V_85 ,
( V_86 ) error , 0 , 0 , NULL ,
V_50 ) ;
if ( V_84 )
F_11 ( V_14 , V_87 ,
F_47 ( V_84 ) ) ;
F_11 ( V_14 , V_88 ,
F_48 ( V_89 ) ) ;
V_2 -> V_90 . error = error ;
F_11 ( V_14 , V_91 , F_49 () ) ;
}
static void F_50 ( T_2 * V_14 ,
struct V_1 * V_2 ,
T_4 V_92 ,
T_5 V_93 ,
struct V_6 * V_7 ,
unsigned int error )
{
struct V_83 * V_84 ;
F_51 ( & V_2 -> V_94 , V_50 ) ;
if ( V_92 == V_95 && V_93 . V_7 == V_96 )
V_84 = F_46 ( V_2 , 0 , V_97 ,
( V_86 ) error , 0 , 0 , V_7 ,
V_50 ) ;
else
V_84 = F_46 ( V_2 , 0 , V_97 ,
( V_86 ) error , 0 , 0 , NULL ,
V_50 ) ;
if ( V_84 )
F_11 ( V_14 , V_87 ,
F_47 ( V_84 ) ) ;
F_11 ( V_14 , V_88 ,
F_48 ( V_89 ) ) ;
V_2 -> V_90 . error = error ;
F_11 ( V_14 , V_91 , F_49 () ) ;
}
static int F_52 ( T_2 * V_14 ,
struct V_1 * V_2 ,
struct V_6 * V_7 ,
T_6 * V_98 ,
T_7 V_99 )
{
int error ;
if ( ! F_53 ( V_2 , V_7 , F_54 ( V_7 ) , V_98 , V_99 ) )
error = - V_36 ;
else
error = 0 ;
return error ;
}
static void F_55 ( T_2 * V_100 ,
struct V_1 * V_2 )
{
struct V_10 * V_101 ;
F_56 (t, &asoc->peer.transport_addr_list, transports) {
if ( ! F_20 ( & V_101 -> V_61 , F_57 ( V_101 ) ) )
F_21 ( V_101 ) ;
}
}
static void F_58 ( T_2 * V_100 ,
struct V_1 * V_2 )
{
struct V_10 * V_101 ;
F_56 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_59 ( & V_101 -> V_61 ) )
F_25 ( V_101 ) ;
}
}
static void F_60 ( T_2 * V_100 ,
struct V_1 * V_2 )
{
struct V_10 * V_101 ;
F_56 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_61 ( & V_101 -> V_41 ) &&
F_59 ( & V_101 -> V_41 ) ) {
F_25 ( V_101 ) ;
}
}
}
static void F_41 ( T_2 * V_100 ,
struct V_10 * V_101 )
{
if ( ! F_20 ( & V_101 -> V_61 , F_57 ( V_101 ) ) )
F_21 ( V_101 ) ;
}
static void F_62 ( T_2 * V_100 ,
struct V_1 * V_2 ,
struct V_10 * V_101 ,
struct V_6 * V_7 )
{
T_8 * V_102 ;
int V_103 = 0 ;
V_101 -> V_69 = 0 ;
if ( V_101 -> V_2 -> V_48 != V_104 )
V_101 -> V_2 -> V_67 = 0 ;
V_101 -> V_70 = 0 ;
if ( ( V_101 -> V_48 == V_68 ) || ( V_101 -> V_48 == V_71 ) ) {
V_103 = 1 ;
F_40 ( V_2 , V_101 , V_105 ,
V_106 ) ;
}
if ( V_101 -> V_48 == V_72 )
F_40 ( V_2 , V_101 , V_105 ,
V_106 ) ;
if ( V_101 -> V_107 == 0 )
V_101 -> V_107 = 1 ;
V_102 = ( T_8 * ) V_7 -> V_108 -> V_54 ;
F_63 ( V_101 , ( V_42 - V_102 -> V_109 ) ) ;
if ( ! F_20 ( & V_101 -> V_61 , F_57 ( V_101 ) ) )
F_21 ( V_101 ) ;
if ( V_103 && V_2 -> V_19 . V_110 == 1 )
F_64 ( V_101 ) ;
}
static int F_65 ( T_2 * V_100 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_111 = 0 ;
if ( F_66 ( & V_2 -> V_90 , V_7 ) ) {
struct V_37 * V_37 = F_16 ( V_2 -> V_38 . V_39 ) ;
V_111 = F_22 ( V_37 , V_64 ,
F_37 ( V_112 ) ,
V_2 -> V_48 , V_2 -> V_49 , V_2 , NULL ,
V_50 ) ;
}
return V_111 ;
}
static void F_67 ( T_2 * V_100 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_10 * V_101 ;
if ( V_7 -> V_11 )
V_101 = V_7 -> V_11 ;
else {
V_101 = F_68 ( V_2 ,
V_2 -> V_113 ) ;
V_7 -> V_11 = V_101 ;
}
V_2 -> V_113 = V_101 ;
V_2 -> V_27 [ V_57 ] = V_101 -> V_81 ;
}
static void F_69 ( T_2 * V_100 ,
struct V_1 * V_2 ,
T_9 V_48 )
{
struct V_114 * V_39 = V_2 -> V_38 . V_39 ;
V_2 -> V_48 = V_48 ;
F_19 ( L_5 ,
V_2 , V_115 [ V_48 ] ) ;
if ( F_70 ( V_39 , V_116 ) ) {
if ( F_71 ( V_2 , V_117 ) && F_72 ( V_39 , V_118 ) )
V_39 -> V_119 = V_120 ;
if ( F_71 ( V_2 , V_121 ) &&
F_72 ( V_39 , V_117 ) )
V_39 -> V_122 |= V_123 ;
}
if ( F_71 ( V_2 , V_124 ) ) {
V_2 -> V_27 [ V_56 ] =
V_2 -> V_125 ;
V_2 -> V_27 [ V_55 ] =
V_2 -> V_125 ;
}
if ( F_71 ( V_2 , V_117 ) ||
F_71 ( V_2 , V_118 ) ||
F_71 ( V_2 , V_121 ) ) {
if ( F_73 ( & V_2 -> V_126 ) )
F_74 ( & V_2 -> V_126 ) ;
if ( ! F_70 ( V_39 , V_127 ) )
V_39 -> V_128 ( V_39 ) ;
}
}
static void F_75 ( T_2 * V_100 ,
struct V_1 * V_2 )
{
struct V_114 * V_39 = V_2 -> V_38 . V_39 ;
if ( F_70 ( V_39 , V_116 ) && F_72 ( V_39 , V_129 ) &&
( ! V_2 -> V_130 ) && ( V_39 -> V_122 != V_131 ) )
return;
F_76 ( V_2 ) ;
F_77 ( V_2 ) ;
}
static void F_78 ( T_2 * V_100 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_10 * V_101 ;
V_101 = F_68 ( V_2 , V_7 -> V_11 ) ;
V_2 -> V_27 [ V_58 ] = V_101 -> V_81 ;
V_7 -> V_11 = V_101 ;
}
static void F_79 ( T_2 * V_100 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_132 * V_133 ;
struct V_83 * V_134 ;
while ( V_7 -> V_135 > V_7 -> V_108 -> V_54 ) {
V_133 = (struct V_132 * ) ( V_7 -> V_108 -> V_54 ) ;
V_134 = F_80 ( V_2 , V_7 , 0 ,
V_50 ) ;
if ( ! V_134 )
return;
F_81 ( & V_2 -> V_94 , V_134 ) ;
switch ( V_133 -> V_136 ) {
case V_137 :
{
T_10 * V_138 ;
V_138 = ( T_10 * ) V_133 -> V_139 ;
switch ( V_138 -> type ) {
case V_140 :
if ( V_2 -> V_19 . V_141 == 0 )
break;
V_2 -> V_19 . V_141 = 0 ;
F_11 ( V_100 , V_35 ,
F_12 ( V_58 ) ) ;
break;
default:
break;
}
break;
}
default:
break;
}
}
}
static void F_82 ( struct V_142 * V_94 ,
struct V_6 * V_7 )
{
struct V_143 * V_144 ;
F_83 (skip, chunk) {
F_84 ( V_94 , F_43 ( V_144 -> V_145 ) , F_43 ( V_144 -> V_146 ) ) ;
}
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_10 * V_101 ;
struct V_147 * V_148 ;
struct V_147 * V_130 ;
F_86 (pos, temp, &asoc->peer.transport_addr_list) {
V_101 = F_87 ( V_148 , struct V_10 , V_149 ) ;
if ( ! F_88 ( & V_101 -> V_76 ,
& V_2 -> V_19 . V_150 ) ) {
F_89 ( V_2 , & V_101 -> V_76 ) ;
}
}
}
static void F_90 ( struct V_1 * V_2 , int error )
{
struct V_114 * V_39 = V_2 -> V_38 . V_39 ;
if ( ! F_70 ( V_39 , V_127 ) )
V_39 -> V_51 = error ;
}
static void F_91 ( T_2 * V_14 ,
struct V_1 * V_2 ,
T_11 V_48 )
{
struct V_83 * V_134 ;
V_134 = F_46 ( V_2 , 0 , V_48 , 0 ,
V_2 -> V_151 . V_152 ,
V_2 -> V_151 . V_153 ,
NULL , V_50 ) ;
if ( V_134 )
F_81 ( & V_2 -> V_94 , V_134 ) ;
}
static void F_92 ( T_2 * V_14 ,
struct V_1 * V_2 )
{
struct V_83 * V_134 ;
V_134 = F_93 ( V_2 , V_50 ) ;
if ( V_134 )
F_81 ( & V_2 -> V_94 , V_134 ) ;
}
static void F_94 ( struct V_1 * V_2 ,
T_3 V_154 ,
char * V_155 )
{
struct V_10 * V_101 ;
V_101 = V_2 -> V_156 ;
V_2 -> V_157 ++ ;
if ( V_101 -> V_158 > ( V_2 -> V_159 + 1 ) ) {
V_2 -> V_27 [ V_154 ] *= 2 ;
if ( V_2 -> V_27 [ V_154 ] > V_2 -> V_160 ) {
V_2 -> V_27 [ V_154 ] = V_2 -> V_160 ;
}
V_2 -> V_159 ++ ;
F_19 (
L_6
L_7
L_8
L_9 ,
V_155 ,
V_2 -> V_157 ,
V_2 -> V_159 ,
V_2 -> V_27 [ V_154 ] ) ;
}
}
static int F_95 ( struct V_1 * V_2 ,
struct V_161 * V_162 )
{
struct V_6 * V_7 ;
int error = 0 ;
F_56 (chunk, &msg->chunks, frag_list) {
error = F_96 ( & V_2 -> V_90 , V_7 ) ;
if ( error )
break;
}
return error ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_37 * V_37 = F_16 ( V_2 -> V_38 . V_39 ) ;
if ( ! F_98 ( & V_2 -> V_163 ) ) {
struct V_147 * V_164 = V_2 -> V_163 . V_165 ;
struct V_6 * V_166 = F_87 ( V_164 ,
struct V_6 , V_167 ) ;
F_99 ( V_164 ) ;
F_100 ( V_166 ) ;
if ( F_101 ( V_37 , V_2 , V_166 ) )
F_102 ( V_166 ) ;
else
V_2 -> V_168 = V_166 ;
}
}
int F_22 ( struct V_37 * V_37 , T_4 V_92 , T_5 V_93 ,
T_9 V_48 ,
struct V_169 * V_49 ,
struct V_1 * V_2 ,
void * V_170 ,
T_7 V_99 )
{
T_2 V_14 ;
const T_12 * V_171 ;
T_13 V_172 ;
int error = 0 ;
typedef const char * (F_103)( T_5 );
static F_103 * V_173 [] = {
NULL , V_174 , V_175 , V_176 , V_177 ,
} ;
F_103 * T_14 V_178 ( ( V_179 ) ) = V_173 [ V_92 ] ;
V_171 = F_104 ( V_37 , V_92 , V_48 , V_93 ) ;
F_105 ( & V_14 ) ;
V_180 ;
V_172 = (* V_171 -> V_181 )( V_37 , V_49 , V_2 , V_93 , V_170 , & V_14 ) ;
V_182 ;
error = F_106 ( V_92 , V_93 , V_48 ,
V_49 , V_2 , V_170 , V_172 ,
& V_14 , V_99 ) ;
V_183 ;
return error ;
}
static int F_106 ( T_4 V_92 , T_5 V_93 ,
T_9 V_48 ,
struct V_169 * V_49 ,
struct V_1 * V_2 ,
void * V_170 ,
T_13 V_172 ,
T_2 * V_14 ,
T_7 V_99 )
{
int error ;
if ( 0 != ( error = F_107 ( V_92 , V_93 , V_48 ,
V_49 , V_2 ,
V_170 , V_172 ,
V_14 , V_99 ) ) )
goto V_184;
switch ( V_172 ) {
case V_185 :
F_19 ( L_10
L_11 ,
V_48 , V_92 , V_93 . V_7 ) ;
break;
case V_186 :
error = - V_36 ;
break;
case V_187 :
break;
case V_188 :
case V_189 :
break;
case V_190 :
F_108 ( L_12 ,
V_48 , V_93 . V_7 ) ;
break;
case V_191 :
F_109 ( L_13 ,
V_48 , V_92 , V_93 . V_7 ) ;
break;
case V_192 :
F_110 ( L_14 ,
V_48 , V_92 , V_93 . V_7 ) ;
F_111 () ;
break;
default:
F_110 ( L_15 ,
V_172 , V_48 , V_92 , V_93 . V_7 ) ;
F_111 () ;
break;
}
V_184:
return error ;
}
static int F_107 ( T_4 V_92 ,
T_5 V_93 ,
T_9 V_48 ,
struct V_169 * V_49 ,
struct V_1 * V_2 ,
void * V_170 ,
T_13 V_172 ,
T_2 * V_14 ,
T_7 V_99 )
{
int error = 0 ;
int V_13 ;
T_15 * V_193 ;
struct V_6 * V_194 ;
struct V_6 * V_7 = NULL ;
struct V_195 * V_196 ;
struct V_197 * V_154 ;
unsigned long V_198 ;
struct V_10 * V_101 ;
struct V_199 V_200 ;
int V_201 = 0 ;
if ( V_46 != V_92 )
V_7 = V_170 ;
while ( NULL != ( V_193 = F_112 ( V_14 ) ) ) {
switch ( V_193 -> V_202 ) {
case V_203 :
break;
case V_204 :
if ( V_201 ) {
F_113 ( & V_2 -> V_90 ) ;
V_201 = 0 ;
}
V_2 = V_193 -> V_205 . V_206 ;
F_114 ( V_49 , V_2 ) ;
F_115 ( V_2 ) ;
break;
case V_207 :
F_116 ( V_2 , V_193 -> V_205 . V_206 ) ;
break;
case V_208 :
F_117 ( & V_2 -> V_90 ) ;
break;
case V_91 :
if ( V_201 ) {
F_113 ( & V_2 -> V_90 ) ;
V_201 = 0 ;
}
F_75 ( V_14 , V_2 ) ;
V_2 = NULL ;
break;
case V_88 :
F_69 ( V_14 , V_2 , V_193 -> V_205 . V_48 ) ;
break;
case V_209 :
error = F_118 ( & V_2 -> V_19 . V_24 ,
V_193 -> V_205 . V_210 , NULL ) ;
break;
case V_211 :
F_119 ( & V_2 -> V_19 . V_24 , V_193 -> V_205 . V_210 ) ;
F_120 ( & V_2 -> V_94 , V_193 -> V_205 . V_210 ) ;
F_51 ( & V_2 -> V_94 , V_50 ) ;
break;
case V_212 :
F_82 ( & V_2 -> V_94 , V_193 -> V_205 . V_206 ) ;
break;
case V_213 :
V_13 = V_193 -> V_205 . V_214 ;
error = F_8 ( V_2 , V_13 , V_14 ) ;
break;
case V_215 :
error = F_65 ( V_14 , V_2 ,
V_193 -> V_205 . V_206 ) ;
break;
case V_216 :
V_194 = F_121 ( V_2 , V_7 , V_50 ,
0 ) ;
if ( ! V_194 )
goto V_33;
F_11 ( V_14 , V_34 ,
F_14 ( V_194 ) ) ;
break;
case V_217 :
error = F_52 ( V_14 , V_2 , V_7 ,
V_193 -> V_205 . V_206 , V_99 ) ;
break;
case V_218 :
V_194 = F_122 ( V_2 , V_7 ) ;
if ( ! V_194 ) {
if ( V_193 -> V_205 . V_206 )
F_102 ( V_193 -> V_205 . V_206 ) ;
goto V_33;
}
F_11 ( V_14 , V_34 ,
F_14 ( V_194 ) ) ;
if ( V_193 -> V_205 . V_206 )
F_11 ( V_14 , V_34 ,
F_14 ( V_193 -> V_205 . V_206 ) ) ;
if ( V_194 -> V_11 ) {
V_194 -> V_11 -> V_158 ++ ;
V_2 -> V_156 = V_194 -> V_11 ;
}
if ( ( V_2 -> V_19 . V_219 !=
V_2 -> V_19 . V_220 ) &&
( V_2 -> V_157 > 0 ) ) {
F_11 ( V_14 ,
V_221 ,
F_49 () ) ;
}
break;
case V_222 :
V_2 -> V_67 = 0 ;
V_194 = F_123 ( V_2 , V_7 ) ;
if ( ! V_194 )
goto V_33;
F_11 ( V_14 , V_34 ,
F_14 ( V_194 ) ) ;
break;
case V_223 :
F_19 ( L_16 ,
L_17 , V_193 -> V_205 . V_206 ,
L_18 , & V_2 -> V_94 ) ;
F_124 ( & V_2 -> V_94 , V_193 -> V_205 . V_206 ,
V_50 ) ;
break;
case V_87 :
F_19 ( L_16 ,
L_19 , V_193 -> V_205 . V_206 ,
L_18 , & V_2 -> V_94 ) ;
F_81 ( & V_2 -> V_94 , V_193 -> V_205 . V_206 ) ;
break;
case V_34 :
if ( ! V_2 -> V_90 . V_224 ) {
F_125 ( & V_2 -> V_90 ) ;
V_201 = 1 ;
}
error = F_96 ( & V_2 -> V_90 , V_193 -> V_205 . V_206 ) ;
break;
case V_225 :
V_196 = V_193 -> V_205 . V_206 ;
F_126 ( V_196 ) ;
F_127 ( V_196 ) ;
break;
case V_226 :
F_128 ( & V_2 -> V_90 , V_193 -> V_205 . V_11 ,
V_227 ) ;
break;
case V_228 :
F_128 ( & V_2 -> V_90 , V_193 -> V_205 . V_11 ,
V_229 ) ;
break;
case V_230 :
F_1 ( V_2 , V_193 -> V_205 . V_210 ) ;
break;
case V_231 :
V_194 = F_2 ( V_2 , V_193 -> V_205 . V_210 ,
V_7 ) ;
if ( V_194 )
F_11 ( V_14 , V_34 ,
F_14 ( V_194 ) ) ;
break;
case V_232 :
F_7 ( V_2 , V_193 -> V_205 . V_210 ) ;
break;
case V_233 :
F_67 ( V_14 , V_2 , V_193 -> V_205 . V_206 ) ;
break;
case V_234 :
V_154 = & V_2 -> V_53 [ V_193 -> V_205 . V_235 ] ;
if ( F_61 ( V_154 ) )
break;
case V_236 :
V_154 = & V_2 -> V_53 [ V_193 -> V_205 . V_235 ] ;
V_198 = V_2 -> V_27 [ V_193 -> V_205 . V_235 ] ;
F_129 ( ! V_198 ) ;
V_154 -> V_237 = V_42 + V_198 ;
F_27 ( V_2 ) ;
F_130 ( V_154 ) ;
break;
case V_30 :
V_154 = & V_2 -> V_53 [ V_193 -> V_205 . V_235 ] ;
V_198 = V_2 -> V_27 [ V_193 -> V_205 . V_235 ] ;
if ( ! F_20 ( V_154 , V_42 + V_198 ) )
F_27 ( V_2 ) ;
break;
case V_35 :
V_154 = & V_2 -> V_53 [ V_193 -> V_205 . V_235 ] ;
if ( F_61 ( V_154 ) && F_59 ( V_154 ) )
F_28 ( V_2 ) ;
break;
case V_238 :
V_7 = V_193 -> V_205 . V_206 ;
V_101 = F_68 ( V_2 ,
V_2 -> V_156 ) ;
V_2 -> V_156 = V_101 ;
V_7 -> V_11 = V_101 ;
V_101 -> V_158 ++ ;
F_131 ( V_2 , V_101 ) ;
break;
case V_239 :
F_94 ( V_2 ,
V_56 ,
L_20 ) ;
F_11 ( V_14 , V_30 ,
F_12 ( V_56 ) ) ;
break;
case V_240 :
F_94 ( V_2 ,
V_55 ,
L_21 ) ;
F_56 (t, &asoc->peer.transport_addr_list,
transports) {
F_132 ( & V_2 -> V_90 , V_101 ,
V_227 ) ;
}
F_11 ( V_14 ,
V_30 ,
F_12 ( V_55 ) ) ;
break;
case V_241 :
F_45 ( V_14 , V_2 , V_193 -> V_205 . V_111 ) ;
break;
case V_242 :
F_50 ( V_14 , V_2 , V_92 ,
V_93 , V_7 , V_193 -> V_205 . V_111 ) ;
break;
case V_243 :
V_2 -> V_157 ++ ;
break;
case V_244 :
V_2 -> V_157 = 0 ;
V_2 -> V_159 = 0 ;
F_56 (t, &asoc->peer.transport_addr_list,
transports) {
V_101 -> V_158 = 0 ;
}
break;
case V_245 :
F_133 ( & V_2 -> V_19 . V_24 ,
V_193 -> V_205 . V_210 ) ;
break;
case V_246 :
F_19 ( L_22 ) ;
break;
case V_247 :
F_39 ( V_14 , V_2 ,
V_193 -> V_205 . V_11 , 0 ) ;
break;
case V_248 :
V_101 = V_193 -> V_205 . V_11 ;
F_5 ( V_101 , V_249 ) ;
break;
case V_250 :
V_101 = V_193 -> V_205 . V_11 ;
F_39 ( V_14 , V_2 ,
V_101 , 1 ) ;
V_101 -> V_70 = 1 ;
break;
case V_251 :
V_101 = V_193 -> V_205 . V_11 ;
F_62 ( V_14 , V_2 , V_101 , V_7 ) ;
break;
case V_252 :
F_55 ( V_14 , V_2 ) ;
break;
case V_253 :
V_101 = V_193 -> V_205 . V_11 ;
F_41 ( V_14 , V_101 ) ;
break;
case V_254 :
F_58 ( V_14 , V_2 ) ;
break;
case V_255 :
error = V_193 -> V_205 . error ;
break;
case V_256 :
V_200 . V_257 = V_193 -> V_205 . V_258 ;
V_200 . V_31 = V_2 -> V_19 . V_32 +
V_2 -> V_90 . V_259 ;
V_200 . V_260 = 0 ;
V_200 . V_261 = 0 ;
V_7 -> V_262 . V_263 = & V_200 ;
F_11 ( V_14 , V_215 ,
F_14 ( V_7 ) ) ;
break;
case V_264 :
V_7 -> V_265 = 1 ;
if ( V_2 ) {
F_113 ( & V_2 -> V_90 ) ;
V_201 = 0 ;
}
break;
case V_266 :
V_101 = V_193 -> V_205 . V_11 ;
V_101 -> V_107 = 1 ;
break;
case V_267 :
F_134 ( & V_2 -> V_94 , V_193 -> V_205 . V_206 ,
V_50 ) ;
break;
case V_268 :
F_135 ( & V_2 -> V_94 , V_193 -> V_205 . V_206 ,
V_50 ) ;
break;
case V_269 :
F_78 ( V_14 , V_2 , V_193 -> V_205 . V_206 ) ;
break;
case V_270 :
F_79 ( V_14 , V_2 , V_7 ) ;
break;
case V_271 :
V_2 -> V_19 . V_272 . V_273 = 0 ;
break;
case V_274 :
F_85 ( V_2 ) ;
break;
case V_275 :
F_60 ( V_14 , V_2 ) ;
break;
case V_221 :
V_101 = V_2 -> V_19 . V_219 ;
V_2 -> V_19 . V_219 = V_2 -> V_19 . V_220 ;
error = F_113 ( & V_2 -> V_90 ) ;
V_201 = 0 ;
V_2 -> V_19 . V_219 = V_101 ;
break;
case V_276 :
F_90 ( V_2 , V_193 -> V_205 . error ) ;
break;
case V_277 :
F_91 ( V_14 , V_2 ,
V_193 -> V_205 . T_11 ) ;
break;
case V_278 :
F_92 ( V_14 , V_2 ) ;
break;
case V_279 :
error = F_136 ( V_2 ,
V_50 ) ;
break;
case V_280 :
V_2 -> V_19 . V_272 . V_273 = V_193 -> V_205 . V_210 ;
break;
case V_281 :
if ( ! V_2 -> V_90 . V_224 ) {
F_125 ( & V_2 -> V_90 ) ;
V_201 = 1 ;
}
error = F_95 ( V_2 , V_193 -> V_205 . V_162 ) ;
break;
case V_282 :
F_97 ( V_2 ) ;
break;
case V_283 :
F_137 ( V_2 ) ;
break;
case V_284 :
V_2 = V_193 -> V_205 . V_2 ;
break;
default:
F_109 ( L_23 ,
V_193 -> V_202 , V_193 -> V_205 . V_206 ) ;
break;
}
if ( error )
break;
}
V_285:
if ( V_2 && V_95 == V_92 && V_7 ) {
if ( V_7 -> V_286 || V_7 -> V_287 )
error = F_113 ( & V_2 -> V_90 ) ;
} else if ( V_201 )
error = F_113 ( & V_2 -> V_90 ) ;
return error ;
V_33:
error = - V_36 ;
goto V_285;
}
