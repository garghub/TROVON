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
F_45 ( V_2 , V_11 ) ;
}
}
static void F_46 ( T_2 * V_14 ,
struct V_1 * V_2 ,
unsigned int error )
{
struct V_83 * V_84 ;
V_84 = F_47 ( V_2 , 0 , V_85 ,
( V_86 ) error , 0 , 0 , NULL ,
V_50 ) ;
if ( V_84 )
F_11 ( V_14 , V_87 ,
F_48 ( V_84 ) ) ;
F_11 ( V_14 , V_88 ,
F_49 ( V_89 ) ) ;
V_2 -> V_90 . error = error ;
F_11 ( V_14 , V_91 , F_50 () ) ;
}
static void F_51 ( T_2 * V_14 ,
struct V_1 * V_2 ,
T_4 V_92 ,
T_5 V_93 ,
struct V_6 * V_7 ,
unsigned int error )
{
struct V_83 * V_84 ;
struct V_6 * abort ;
F_52 ( & V_2 -> V_94 , V_50 ) ;
if ( V_92 == V_95 && V_93 . V_7 == V_96 )
V_84 = F_47 ( V_2 , 0 , V_97 ,
( V_86 ) error , 0 , 0 , V_7 ,
V_50 ) ;
else
V_84 = F_47 ( V_2 , 0 , V_97 ,
( V_86 ) error , 0 , 0 , NULL ,
V_50 ) ;
if ( V_84 )
F_11 ( V_14 , V_87 ,
F_48 ( V_84 ) ) ;
if ( V_2 -> V_67 >= V_2 -> V_98 ) {
abort = F_53 ( V_2 , V_7 ) ;
if ( abort )
F_11 ( V_14 , V_34 ,
F_14 ( abort ) ) ;
}
F_11 ( V_14 , V_88 ,
F_49 ( V_89 ) ) ;
V_2 -> V_90 . error = error ;
F_11 ( V_14 , V_91 , F_50 () ) ;
}
static int F_54 ( T_2 * V_14 ,
struct V_1 * V_2 ,
struct V_6 * V_7 ,
T_6 * V_99 ,
T_7 V_100 )
{
int error ;
if ( ! F_55 ( V_2 , V_7 , F_56 ( V_7 ) , V_99 , V_100 ) )
error = - V_36 ;
else
error = 0 ;
return error ;
}
static void F_57 ( T_2 * V_101 ,
struct V_1 * V_2 )
{
struct V_10 * V_102 ;
F_58 (t, &asoc->peer.transport_addr_list, transports) {
if ( ! F_20 ( & V_102 -> V_61 , F_59 ( V_102 ) ) )
F_21 ( V_102 ) ;
}
}
static void F_60 ( T_2 * V_101 ,
struct V_1 * V_2 )
{
struct V_10 * V_102 ;
F_58 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_61 ( & V_102 -> V_61 ) )
F_25 ( V_102 ) ;
}
}
static void F_62 ( T_2 * V_101 ,
struct V_1 * V_2 )
{
struct V_10 * V_102 ;
F_58 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_63 ( & V_102 -> V_41 ) &&
F_61 ( & V_102 -> V_41 ) ) {
F_25 ( V_102 ) ;
}
}
}
static void F_41 ( T_2 * V_101 ,
struct V_10 * V_102 )
{
if ( ! F_20 ( & V_102 -> V_61 , F_59 ( V_102 ) ) )
F_21 ( V_102 ) ;
}
static void F_64 ( T_2 * V_101 ,
struct V_1 * V_2 ,
struct V_10 * V_102 ,
struct V_6 * V_7 )
{
T_8 * V_103 ;
int V_104 = 0 ;
V_102 -> V_69 = 0 ;
if ( V_102 -> V_2 -> V_48 != V_105 )
V_102 -> V_2 -> V_67 = 0 ;
V_102 -> V_70 = 0 ;
if ( ( V_102 -> V_48 == V_68 ) || ( V_102 -> V_48 == V_71 ) ) {
V_104 = 1 ;
F_40 ( V_2 , V_102 , V_106 ,
V_107 ) ;
}
if ( V_102 -> V_48 == V_72 )
F_40 ( V_2 , V_102 , V_106 ,
V_107 ) ;
if ( V_102 -> V_108 == 0 )
V_102 -> V_108 = 1 ;
V_103 = ( T_8 * ) V_7 -> V_109 -> V_54 ;
F_65 ( V_102 , ( V_42 - V_103 -> V_110 ) ) ;
if ( ! F_20 ( & V_102 -> V_61 , F_59 ( V_102 ) ) )
F_21 ( V_102 ) ;
if ( V_104 && V_2 -> V_19 . V_111 == 1 )
F_66 ( V_102 ) ;
}
static int F_67 ( T_2 * V_101 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_112 = 0 ;
if ( F_68 ( & V_2 -> V_90 , V_7 ) ) {
struct V_37 * V_37 = F_16 ( V_2 -> V_38 . V_39 ) ;
V_112 = F_22 ( V_37 , V_64 ,
F_37 ( V_113 ) ,
V_2 -> V_48 , V_2 -> V_49 , V_2 , NULL ,
V_50 ) ;
}
return V_112 ;
}
static void F_69 ( T_2 * V_101 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_10 * V_102 ;
if ( V_7 -> V_11 )
V_102 = V_7 -> V_11 ;
else {
V_102 = F_70 ( V_2 ,
V_2 -> V_114 ) ;
V_7 -> V_11 = V_102 ;
}
V_2 -> V_114 = V_102 ;
V_2 -> V_27 [ V_57 ] = V_102 -> V_81 ;
}
static void F_71 ( T_2 * V_101 ,
struct V_1 * V_2 ,
T_9 V_48 )
{
struct V_115 * V_39 = V_2 -> V_38 . V_39 ;
V_2 -> V_48 = V_48 ;
F_19 ( L_5 ,
V_2 , V_116 [ V_48 ] ) ;
if ( F_72 ( V_39 , V_117 ) ) {
if ( F_73 ( V_2 , V_118 ) && F_74 ( V_39 , V_119 ) )
V_39 -> V_120 = V_121 ;
if ( F_73 ( V_2 , V_122 ) &&
F_74 ( V_39 , V_118 ) )
V_39 -> V_123 |= V_124 ;
}
if ( F_73 ( V_2 , V_125 ) ) {
V_2 -> V_27 [ V_56 ] =
V_2 -> V_126 ;
V_2 -> V_27 [ V_55 ] =
V_2 -> V_126 ;
}
if ( F_73 ( V_2 , V_118 ) ||
F_73 ( V_2 , V_119 ) ||
F_73 ( V_2 , V_122 ) ) {
if ( F_75 ( & V_2 -> V_127 ) )
F_76 ( & V_2 -> V_127 ) ;
if ( ! F_72 ( V_39 , V_128 ) )
V_39 -> V_129 ( V_39 ) ;
}
}
static void F_77 ( T_2 * V_101 ,
struct V_1 * V_2 )
{
struct V_115 * V_39 = V_2 -> V_38 . V_39 ;
if ( F_72 ( V_39 , V_117 ) && F_74 ( V_39 , V_130 ) &&
( ! V_2 -> V_131 ) && ( V_39 -> V_123 != V_132 ) )
return;
F_78 ( V_2 ) ;
F_79 ( V_2 ) ;
}
static void F_80 ( T_2 * V_101 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_10 * V_102 ;
V_102 = F_70 ( V_2 , V_7 -> V_11 ) ;
V_2 -> V_27 [ V_58 ] = V_102 -> V_81 ;
V_7 -> V_11 = V_102 ;
}
static void F_81 ( T_2 * V_101 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_133 * V_134 ;
struct V_83 * V_135 ;
while ( V_7 -> V_136 > V_7 -> V_109 -> V_54 ) {
V_134 = (struct V_133 * ) ( V_7 -> V_109 -> V_54 ) ;
V_135 = F_82 ( V_2 , V_7 , 0 ,
V_50 ) ;
if ( ! V_135 )
return;
F_83 ( & V_2 -> V_94 , V_135 ) ;
switch ( V_134 -> V_137 ) {
case V_138 :
{
T_10 * V_139 ;
V_139 = ( T_10 * ) V_134 -> V_140 ;
switch ( V_139 -> type ) {
case V_141 :
if ( V_2 -> V_19 . V_142 == 0 )
break;
V_2 -> V_19 . V_142 = 0 ;
F_11 ( V_101 , V_35 ,
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
static void F_84 ( struct V_143 * V_94 ,
struct V_6 * V_7 )
{
struct V_144 * V_145 ;
F_85 (skip, chunk) {
F_86 ( V_94 , F_43 ( V_145 -> V_146 ) , F_43 ( V_145 -> V_147 ) ) ;
}
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_10 * V_102 ;
struct V_148 * V_149 ;
struct V_148 * V_131 ;
F_88 (pos, temp, &asoc->peer.transport_addr_list) {
V_102 = F_89 ( V_149 , struct V_10 , V_150 ) ;
if ( ! F_90 ( & V_102 -> V_76 ,
& V_2 -> V_19 . V_151 ) ) {
F_91 ( V_2 , & V_102 -> V_76 ) ;
}
}
}
static void F_92 ( struct V_1 * V_2 , int error )
{
struct V_115 * V_39 = V_2 -> V_38 . V_39 ;
if ( ! F_72 ( V_39 , V_128 ) )
V_39 -> V_51 = error ;
}
static void F_93 ( T_2 * V_14 ,
struct V_1 * V_2 ,
T_11 V_48 )
{
struct V_83 * V_135 ;
V_135 = F_47 ( V_2 , 0 , V_48 , 0 ,
V_2 -> V_152 . V_153 ,
V_2 -> V_152 . V_154 ,
NULL , V_50 ) ;
if ( V_135 )
F_83 ( & V_2 -> V_94 , V_135 ) ;
}
static void F_94 ( T_2 * V_14 ,
struct V_1 * V_2 )
{
struct V_83 * V_135 ;
V_135 = F_95 ( V_2 , V_50 ) ;
if ( V_135 )
F_83 ( & V_2 -> V_94 , V_135 ) ;
}
static void F_96 ( struct V_1 * V_2 ,
T_3 V_155 ,
char * V_156 )
{
struct V_10 * V_102 ;
V_102 = V_2 -> V_157 ;
V_2 -> V_158 ++ ;
if ( V_102 -> V_159 > ( V_2 -> V_160 + 1 ) ) {
V_2 -> V_27 [ V_155 ] *= 2 ;
if ( V_2 -> V_27 [ V_155 ] > V_2 -> V_161 ) {
V_2 -> V_27 [ V_155 ] = V_2 -> V_161 ;
}
V_2 -> V_160 ++ ;
F_19 (
L_6
L_7
L_8
L_9 ,
V_156 ,
V_2 -> V_158 ,
V_2 -> V_160 ,
V_2 -> V_27 [ V_155 ] ) ;
}
}
static int F_97 ( struct V_1 * V_2 ,
struct V_162 * V_163 )
{
struct V_6 * V_7 ;
int error = 0 ;
F_58 (chunk, &msg->chunks, frag_list) {
error = F_98 ( & V_2 -> V_90 , V_7 ) ;
if ( error )
break;
}
return error ;
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_37 * V_37 = F_16 ( V_2 -> V_38 . V_39 ) ;
if ( ! F_100 ( & V_2 -> V_164 ) ) {
struct V_148 * V_165 = V_2 -> V_164 . V_166 ;
struct V_6 * V_167 = F_89 ( V_165 ,
struct V_6 , V_168 ) ;
F_101 ( V_165 ) ;
F_102 ( V_167 ) ;
if ( F_103 ( V_37 , V_2 , V_167 ) )
F_104 ( V_167 ) ;
else
V_2 -> V_169 = V_167 ;
}
}
int F_22 ( struct V_37 * V_37 , T_4 V_92 , T_5 V_93 ,
T_9 V_48 ,
struct V_170 * V_49 ,
struct V_1 * V_2 ,
void * V_171 ,
T_7 V_100 )
{
T_2 V_14 ;
const T_12 * V_172 ;
T_13 V_173 ;
int error = 0 ;
typedef const char * (F_105)( T_5 );
static F_105 * V_174 [] = {
NULL , V_175 , V_176 , V_177 , V_178 ,
} ;
F_105 * T_14 V_179 ( ( V_180 ) ) = V_174 [ V_92 ] ;
V_172 = F_106 ( V_37 , V_92 , V_48 , V_93 ) ;
F_107 ( & V_14 ) ;
V_181 ;
V_173 = (* V_172 -> V_182 )( V_37 , V_49 , V_2 , V_93 , V_171 , & V_14 ) ;
V_183 ;
error = F_108 ( V_92 , V_93 , V_48 ,
V_49 , V_2 , V_171 , V_173 ,
& V_14 , V_100 ) ;
V_184 ;
return error ;
}
static int F_108 ( T_4 V_92 , T_5 V_93 ,
T_9 V_48 ,
struct V_170 * V_49 ,
struct V_1 * V_2 ,
void * V_171 ,
T_13 V_173 ,
T_2 * V_14 ,
T_7 V_100 )
{
int error ;
if ( 0 != ( error = F_109 ( V_92 , V_93 , V_48 ,
V_49 , V_2 ,
V_171 , V_173 ,
V_14 , V_100 ) ) )
goto V_185;
switch ( V_173 ) {
case V_186 :
F_19 ( L_10
L_11 ,
V_48 , V_92 , V_93 . V_7 ) ;
break;
case V_187 :
error = - V_36 ;
break;
case V_188 :
break;
case V_189 :
case V_190 :
break;
case V_191 :
F_110 ( L_12 ,
V_48 , V_93 . V_7 ) ;
break;
case V_192 :
F_111 ( L_13 ,
V_48 , V_92 , V_93 . V_7 ) ;
break;
case V_193 :
F_112 ( L_14 ,
V_48 , V_92 , V_93 . V_7 ) ;
F_113 () ;
break;
default:
F_112 ( L_15 ,
V_173 , V_48 , V_92 , V_93 . V_7 ) ;
F_113 () ;
break;
}
V_185:
return error ;
}
static int F_109 ( T_4 V_92 ,
T_5 V_93 ,
T_9 V_48 ,
struct V_170 * V_49 ,
struct V_1 * V_2 ,
void * V_171 ,
T_13 V_173 ,
T_2 * V_14 ,
T_7 V_100 )
{
int error = 0 ;
int V_13 ;
T_15 * V_194 ;
struct V_6 * V_195 ;
struct V_6 * V_7 = NULL ;
struct V_196 * V_197 ;
struct V_198 * V_155 ;
unsigned long V_199 ;
struct V_10 * V_102 ;
struct V_200 V_201 ;
int V_202 = 0 ;
if ( V_46 != V_92 )
V_7 = V_171 ;
while ( NULL != ( V_194 = F_114 ( V_14 ) ) ) {
switch ( V_194 -> V_203 ) {
case V_204 :
break;
case V_205 :
if ( V_202 ) {
F_115 ( & V_2 -> V_90 ) ;
V_202 = 0 ;
}
V_2 = V_194 -> V_206 . V_2 ;
F_116 ( V_49 , V_2 ) ;
F_117 ( V_2 ) ;
break;
case V_207 :
F_118 ( V_2 , V_194 -> V_206 . V_2 ) ;
break;
case V_208 :
F_119 ( & V_2 -> V_90 ) ;
break;
case V_91 :
if ( V_202 ) {
F_115 ( & V_2 -> V_90 ) ;
V_202 = 0 ;
}
F_77 ( V_14 , V_2 ) ;
V_2 = NULL ;
break;
case V_88 :
F_71 ( V_14 , V_2 , V_194 -> V_206 . V_48 ) ;
break;
case V_209 :
error = F_120 ( & V_2 -> V_19 . V_24 ,
V_194 -> V_206 . V_210 , NULL ) ;
break;
case V_211 :
F_121 ( & V_2 -> V_19 . V_24 , V_194 -> V_206 . V_210 ) ;
F_122 ( & V_2 -> V_94 , V_194 -> V_206 . V_210 ) ;
F_52 ( & V_2 -> V_94 , V_50 ) ;
break;
case V_212 :
F_84 ( & V_2 -> V_94 , V_194 -> V_206 . V_7 ) ;
break;
case V_213 :
V_13 = V_194 -> V_206 . V_214 ;
error = F_8 ( V_2 , V_13 , V_14 ) ;
break;
case V_215 :
error = F_67 ( V_14 , V_2 ,
V_194 -> V_206 . V_7 ) ;
break;
case V_216 :
V_195 = F_123 ( V_2 , V_7 , V_50 ,
0 ) ;
if ( ! V_195 )
goto V_33;
F_11 ( V_14 , V_34 ,
F_14 ( V_195 ) ) ;
break;
case V_217 :
error = F_54 ( V_14 , V_2 , V_7 ,
V_194 -> V_206 . V_218 , V_100 ) ;
break;
case V_219 :
V_195 = F_124 ( V_2 , V_7 ) ;
if ( ! V_195 ) {
if ( V_194 -> V_206 . V_7 )
F_104 ( V_194 -> V_206 . V_7 ) ;
goto V_33;
}
F_11 ( V_14 , V_34 ,
F_14 ( V_195 ) ) ;
if ( V_194 -> V_206 . V_7 )
F_11 ( V_14 , V_34 ,
F_14 ( V_194 -> V_206 . V_7 ) ) ;
if ( V_195 -> V_11 ) {
V_195 -> V_11 -> V_159 ++ ;
V_2 -> V_157 = V_195 -> V_11 ;
}
if ( ( V_2 -> V_19 . V_220 !=
V_2 -> V_19 . V_221 ) &&
( V_2 -> V_158 > 0 ) ) {
F_11 ( V_14 ,
V_222 ,
F_50 () ) ;
}
break;
case V_223 :
V_2 -> V_67 = 0 ;
V_195 = F_125 ( V_2 , V_7 ) ;
if ( ! V_195 )
goto V_33;
F_11 ( V_14 , V_34 ,
F_14 ( V_195 ) ) ;
break;
case V_224 :
F_19 ( L_16 ,
L_17 , V_194 -> V_206 . V_7 ,
L_18 , & V_2 -> V_94 ) ;
F_126 ( & V_2 -> V_94 , V_194 -> V_206 . V_7 ,
V_50 ) ;
break;
case V_87 :
F_19 ( L_16 ,
L_19 , V_194 -> V_206 . V_225 ,
L_18 , & V_2 -> V_94 ) ;
F_83 ( & V_2 -> V_94 , V_194 -> V_206 . V_225 ) ;
break;
case V_34 :
if ( ! V_2 -> V_90 . V_226 ) {
F_127 ( & V_2 -> V_90 ) ;
V_202 = 1 ;
}
error = F_98 ( & V_2 -> V_90 , V_194 -> V_206 . V_7 ) ;
break;
case V_227 :
V_197 = V_194 -> V_206 . V_197 ;
F_128 ( V_197 ) ;
F_129 ( V_197 ) ;
break;
case V_228 :
F_130 ( & V_2 -> V_90 , V_194 -> V_206 . V_11 ,
V_229 ) ;
break;
case V_230 :
F_130 ( & V_2 -> V_90 , V_194 -> V_206 . V_11 ,
V_231 ) ;
break;
case V_232 :
F_1 ( V_2 , V_194 -> V_206 . V_210 ) ;
break;
case V_233 :
V_195 = F_2 ( V_2 , V_194 -> V_206 . V_210 ,
V_7 ) ;
if ( V_195 )
F_11 ( V_14 , V_34 ,
F_14 ( V_195 ) ) ;
break;
case V_234 :
F_7 ( V_2 , V_194 -> V_206 . V_210 ) ;
break;
case V_235 :
F_69 ( V_14 , V_2 , V_194 -> V_206 . V_7 ) ;
break;
case V_236 :
V_155 = & V_2 -> V_53 [ V_194 -> V_206 . V_237 ] ;
if ( F_63 ( V_155 ) )
break;
case V_238 :
V_155 = & V_2 -> V_53 [ V_194 -> V_206 . V_237 ] ;
V_199 = V_2 -> V_27 [ V_194 -> V_206 . V_237 ] ;
F_131 ( ! V_199 ) ;
V_155 -> V_239 = V_42 + V_199 ;
F_27 ( V_2 ) ;
F_132 ( V_155 ) ;
break;
case V_30 :
V_155 = & V_2 -> V_53 [ V_194 -> V_206 . V_237 ] ;
V_199 = V_2 -> V_27 [ V_194 -> V_206 . V_237 ] ;
if ( ! F_20 ( V_155 , V_42 + V_199 ) )
F_27 ( V_2 ) ;
break;
case V_35 :
V_155 = & V_2 -> V_53 [ V_194 -> V_206 . V_237 ] ;
if ( F_63 ( V_155 ) && F_61 ( V_155 ) )
F_28 ( V_2 ) ;
break;
case V_240 :
V_7 = V_194 -> V_206 . V_7 ;
V_102 = F_70 ( V_2 ,
V_2 -> V_157 ) ;
V_2 -> V_157 = V_102 ;
V_7 -> V_11 = V_102 ;
V_102 -> V_159 ++ ;
F_133 ( V_2 , V_102 ) ;
break;
case V_241 :
F_96 ( V_2 ,
V_56 ,
L_20 ) ;
F_11 ( V_14 , V_30 ,
F_12 ( V_56 ) ) ;
break;
case V_242 :
F_96 ( V_2 ,
V_55 ,
L_21 ) ;
F_58 (t, &asoc->peer.transport_addr_list,
transports) {
F_134 ( & V_2 -> V_90 , V_102 ,
V_229 ) ;
}
F_11 ( V_14 ,
V_30 ,
F_12 ( V_55 ) ) ;
break;
case V_243 :
F_46 ( V_14 , V_2 , V_194 -> V_206 . V_112 ) ;
break;
case V_244 :
F_51 ( V_14 , V_2 , V_92 ,
V_93 , V_7 , V_194 -> V_206 . V_112 ) ;
break;
case V_245 :
V_2 -> V_158 ++ ;
break;
case V_246 :
V_2 -> V_158 = 0 ;
V_2 -> V_160 = 0 ;
F_58 (t, &asoc->peer.transport_addr_list,
transports) {
V_102 -> V_159 = 0 ;
}
break;
case V_247 :
F_135 ( & V_2 -> V_19 . V_24 ,
V_194 -> V_206 . V_210 ) ;
break;
case V_248 :
F_19 ( L_22 ) ;
break;
case V_249 :
F_39 ( V_14 , V_2 ,
V_194 -> V_206 . V_11 , 0 ) ;
break;
case V_250 :
V_102 = V_194 -> V_206 . V_11 ;
F_5 ( V_102 , V_251 ) ;
break;
case V_252 :
V_102 = V_194 -> V_206 . V_11 ;
F_39 ( V_14 , V_2 ,
V_102 , 1 ) ;
V_102 -> V_70 = 1 ;
break;
case V_253 :
V_102 = V_194 -> V_206 . V_11 ;
F_64 ( V_14 , V_2 , V_102 , V_7 ) ;
break;
case V_254 :
F_57 ( V_14 , V_2 ) ;
break;
case V_255 :
V_102 = V_194 -> V_206 . V_11 ;
F_41 ( V_14 , V_102 ) ;
break;
case V_256 :
F_60 ( V_14 , V_2 ) ;
break;
case V_257 :
error = V_194 -> V_206 . error ;
break;
case V_258 :
V_201 . V_259 = V_194 -> V_206 . V_260 ;
V_201 . V_31 = V_2 -> V_19 . V_32 +
V_2 -> V_90 . V_261 ;
V_201 . V_262 = 0 ;
V_201 . V_263 = 0 ;
V_7 -> V_264 . V_265 = & V_201 ;
F_11 ( V_14 , V_215 ,
F_14 ( V_7 ) ) ;
break;
case V_266 :
V_7 -> V_267 = 1 ;
if ( V_2 ) {
F_115 ( & V_2 -> V_90 ) ;
V_202 = 0 ;
}
break;
case V_268 :
V_102 = V_194 -> V_206 . V_11 ;
V_102 -> V_108 = 1 ;
break;
case V_269 :
F_136 ( & V_2 -> V_94 , V_50 ) ;
break;
case V_270 :
F_137 ( & V_2 -> V_94 , V_194 -> V_206 . V_7 ,
V_50 ) ;
break;
case V_271 :
F_80 ( V_14 , V_2 , V_194 -> V_206 . V_7 ) ;
break;
case V_272 :
F_81 ( V_14 , V_2 , V_7 ) ;
break;
case V_273 :
V_2 -> V_19 . V_274 . V_275 = 0 ;
break;
case V_276 :
F_87 ( V_2 ) ;
break;
case V_277 :
F_62 ( V_14 , V_2 ) ;
break;
case V_222 :
V_102 = V_2 -> V_19 . V_220 ;
V_2 -> V_19 . V_220 = V_2 -> V_19 . V_221 ;
error = F_115 ( & V_2 -> V_90 ) ;
V_202 = 0 ;
V_2 -> V_19 . V_220 = V_102 ;
break;
case V_278 :
F_92 ( V_2 , V_194 -> V_206 . error ) ;
break;
case V_279 :
F_93 ( V_14 , V_2 ,
V_194 -> V_206 . T_11 ) ;
break;
case V_280 :
F_94 ( V_14 , V_2 ) ;
break;
case V_281 :
error = F_138 ( V_2 ,
V_50 ) ;
break;
case V_282 :
V_2 -> V_19 . V_274 . V_275 = V_194 -> V_206 . V_210 ;
break;
case V_283 :
if ( ! V_2 -> V_90 . V_226 ) {
F_127 ( & V_2 -> V_90 ) ;
V_202 = 1 ;
}
error = F_97 ( V_2 , V_194 -> V_206 . V_163 ) ;
break;
case V_284 :
F_99 ( V_2 ) ;
break;
case V_285 :
F_139 ( V_2 ) ;
break;
case V_286 :
V_2 = V_194 -> V_206 . V_2 ;
break;
default:
F_111 ( L_23 ,
V_194 -> V_203 ) ;
break;
}
if ( error )
break;
}
V_287:
if ( V_2 && V_95 == V_92 && V_7 ) {
if ( V_7 -> V_288 || V_7 -> V_289 )
error = F_115 ( & V_2 -> V_90 ) ;
} else if ( V_202 )
error = F_115 ( & V_2 -> V_90 ) ;
return error ;
V_33:
error = - V_36 ;
goto V_287;
}
