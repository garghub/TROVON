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
F_16 ( V_2 -> V_37 . V_38 ) ;
if ( F_17 ( V_2 -> V_37 . V_38 ) ) {
F_18 ( L_1 , V_39 ) ;
if ( ! F_19 ( & V_11 -> V_40 , V_41 + ( V_42 / 20 ) ) )
F_20 ( V_11 ) ;
goto V_43;
}
if ( V_11 -> V_44 )
goto V_43;
error = F_21 ( V_45 ,
F_22 ( V_46 ) ,
V_2 -> V_47 ,
V_2 -> V_48 , V_2 ,
V_11 , V_49 ) ;
if ( error )
V_2 -> V_37 . V_38 -> V_50 = - error ;
V_43:
F_23 ( V_2 -> V_37 . V_38 ) ;
F_24 ( V_11 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
T_3 V_51 )
{
int error = 0 ;
F_16 ( V_2 -> V_37 . V_38 ) ;
if ( F_17 ( V_2 -> V_37 . V_38 ) ) {
F_18 ( L_2 ,
V_39 ,
V_51 ) ;
if ( ! F_19 ( & V_2 -> V_52 [ V_51 ] , V_41 + ( V_42 / 20 ) ) )
F_26 ( V_2 ) ;
goto V_43;
}
if ( V_2 -> V_37 . V_44 )
goto V_43;
error = F_21 ( V_45 ,
F_22 ( V_51 ) ,
V_2 -> V_47 , V_2 -> V_48 , V_2 ,
( void * ) V_51 , V_49 ) ;
if ( error )
V_2 -> V_37 . V_38 -> V_50 = - error ;
V_43:
F_23 ( V_2 -> V_37 . V_38 ) ;
F_27 ( V_2 ) ;
}
static void F_28 ( unsigned long V_53 )
{
struct V_1 * V_2 = (struct V_1 * ) V_53 ;
F_25 ( V_2 , V_54 ) ;
}
static void F_29 ( unsigned long V_53 )
{
struct V_1 * V_2 = (struct V_1 * ) V_53 ;
F_25 ( V_2 , V_55 ) ;
}
static void F_30 ( unsigned long V_53 )
{
struct V_1 * V_2 = (struct V_1 * ) V_53 ;
F_25 ( V_2 , V_56 ) ;
}
static void F_31 ( unsigned long V_53 )
{
struct V_1 * V_2 = (struct V_1 * ) V_53 ;
F_25 ( V_2 , V_57 ) ;
}
static void F_32 ( unsigned long V_53 )
{
struct V_1 * V_2 = (struct V_1 * ) V_53 ;
F_25 ( V_2 ,
V_58 ) ;
}
static void F_33 ( unsigned long V_53 )
{
struct V_1 * V_2 = (struct V_1 * ) V_53 ;
F_25 ( V_2 , V_59 ) ;
}
void F_34 ( unsigned long V_53 )
{
int error = 0 ;
struct V_10 * V_11 = (struct V_10 * ) V_53 ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_16 ( V_2 -> V_37 . V_38 ) ;
if ( F_17 ( V_2 -> V_37 . V_38 ) ) {
F_18 ( L_1 , V_39 ) ;
if ( ! F_19 ( & V_11 -> V_60 , V_41 + ( V_42 / 20 ) ) )
F_20 ( V_11 ) ;
goto V_43;
}
if ( V_11 -> V_44 )
goto V_43;
error = F_21 ( V_45 ,
F_22 ( V_61 ) ,
V_2 -> V_47 , V_2 -> V_48 , V_2 ,
V_11 , V_49 ) ;
if ( error )
V_2 -> V_37 . V_38 -> V_50 = - error ;
V_43:
F_23 ( V_2 -> V_37 . V_38 ) ;
F_24 ( V_11 ) ;
}
void F_35 ( unsigned long V_53 )
{
struct V_10 * V_11 = (struct V_10 * ) V_53 ;
struct V_1 * V_2 = V_11 -> V_2 ;
F_16 ( V_2 -> V_37 . V_38 ) ;
if ( F_17 ( V_2 -> V_37 . V_38 ) ) {
F_18 ( L_1 , V_39 ) ;
if ( ! F_19 ( & V_11 -> V_62 ,
V_41 + ( V_42 / 20 ) ) )
F_26 ( V_2 ) ;
goto V_43;
}
if ( V_2 -> V_37 . V_44 )
goto V_43;
F_21 ( V_63 ,
F_36 ( V_64 ) ,
V_2 -> V_47 , V_2 -> V_48 , V_2 , V_11 , V_49 ) ;
V_43:
F_23 ( V_2 -> V_37 . V_38 ) ;
F_27 ( V_2 ) ;
}
static void F_37 ( unsigned long V_53 )
{
struct V_1 * V_2 = (struct V_1 * ) V_53 ;
F_25 ( V_2 , V_28 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
int V_65 )
{
if ( ! V_65 ) {
V_2 -> V_66 ++ ;
if ( V_11 -> V_47 != V_67 )
V_11 -> V_68 ++ ;
} else if ( V_11 -> V_69 ) {
if ( V_11 -> V_47 != V_70 )
V_2 -> V_66 ++ ;
if ( V_11 -> V_47 != V_67 )
V_11 -> V_68 ++ ;
}
if ( V_11 -> V_47 != V_67 &&
( V_11 -> V_68 > V_11 -> V_71 ) ) {
F_39 ( L_3 ,
L_4 ,
V_2 ,
( & V_11 -> V_72 ) ,
F_40 ( V_11 -> V_72 . V_73 . V_74 ) ) ;
F_41 ( V_2 , V_11 ,
V_75 ,
V_76 ) ;
}
if ( ! V_65 || V_11 -> V_69 ) {
V_11 -> V_77 = F_42 ( ( V_11 -> V_77 * 2 ) , V_11 -> V_2 -> V_78 ) ;
}
}
static void F_43 ( T_2 * V_14 ,
struct V_1 * V_2 ,
unsigned error )
{
struct V_79 * V_80 ;
V_80 = F_44 ( V_2 , 0 , V_81 ,
( V_82 ) error , 0 , 0 , NULL ,
V_49 ) ;
if ( V_80 )
F_11 ( V_14 , V_83 ,
F_45 ( V_80 ) ) ;
F_11 ( V_14 , V_84 ,
F_46 ( V_85 ) ) ;
V_2 -> V_86 . error = error ;
F_11 ( V_14 , V_87 , F_47 () ) ;
}
static void F_48 ( T_2 * V_14 ,
struct V_1 * V_2 ,
T_4 V_88 ,
T_5 V_89 ,
struct V_6 * V_7 ,
unsigned error )
{
struct V_79 * V_80 ;
F_49 ( & V_2 -> V_90 , V_49 ) ;
if ( V_88 == V_91 && V_89 . V_7 == V_92 )
V_80 = F_44 ( V_2 , 0 , V_93 ,
( V_82 ) error , 0 , 0 , V_7 ,
V_49 ) ;
else
V_80 = F_44 ( V_2 , 0 , V_93 ,
( V_82 ) error , 0 , 0 , NULL ,
V_49 ) ;
if ( V_80 )
F_11 ( V_14 , V_83 ,
F_45 ( V_80 ) ) ;
F_11 ( V_14 , V_84 ,
F_46 ( V_85 ) ) ;
V_2 -> V_86 . error = error ;
F_11 ( V_14 , V_87 , F_47 () ) ;
}
static int F_50 ( T_2 * V_14 ,
struct V_1 * V_2 ,
struct V_6 * V_7 ,
T_6 * V_94 ,
T_7 V_95 )
{
int error ;
if ( ! F_51 ( V_2 , V_7 , F_52 ( V_7 ) , V_94 , V_95 ) )
error = - V_36 ;
else
error = 0 ;
return error ;
}
static void F_53 ( T_2 * V_96 ,
struct V_1 * V_2 )
{
struct V_10 * V_97 ;
F_54 (t, &asoc->peer.transport_addr_list, transports) {
if ( ! F_19 ( & V_97 -> V_60 , F_55 ( V_97 ) ) )
F_20 ( V_97 ) ;
}
}
static void F_56 ( T_2 * V_96 ,
struct V_1 * V_2 )
{
struct V_10 * V_97 ;
F_54 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_57 ( & V_97 -> V_60 ) )
F_24 ( V_97 ) ;
}
}
static void F_58 ( T_2 * V_96 ,
struct V_1 * V_2 )
{
struct V_10 * V_97 ;
F_54 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_59 ( & V_97 -> V_40 ) &&
F_57 ( & V_97 -> V_40 ) ) {
F_24 ( V_97 ) ;
}
}
}
static void F_60 ( T_2 * V_96 ,
struct V_10 * V_97 )
{
if ( ! F_19 ( & V_97 -> V_60 , F_55 ( V_97 ) ) )
F_20 ( V_97 ) ;
}
static void F_61 ( T_2 * V_96 ,
struct V_1 * V_2 ,
struct V_10 * V_97 ,
struct V_6 * V_7 )
{
T_8 * V_98 ;
int V_99 = 0 ;
V_97 -> V_68 = 0 ;
if ( V_97 -> V_2 -> V_47 != V_100 )
V_97 -> V_2 -> V_66 = 0 ;
V_97 -> V_69 = 0 ;
if ( ( V_97 -> V_47 == V_67 ) || ( V_97 -> V_47 == V_70 ) ) {
V_99 = 1 ;
F_41 ( V_2 , V_97 , V_101 ,
V_102 ) ;
}
if ( V_97 -> V_103 == 0 )
V_97 -> V_103 = 1 ;
V_98 = ( T_8 * ) V_7 -> V_104 -> V_53 ;
F_62 ( V_97 , ( V_41 - V_98 -> V_105 ) ) ;
if ( ! F_19 ( & V_97 -> V_60 , F_55 ( V_97 ) ) )
F_20 ( V_97 ) ;
if ( V_99 && V_2 -> V_19 . V_106 == 1 )
F_63 ( V_97 ) ;
}
static int F_64 ( T_2 * V_96 ,
struct V_1 * V_2 ,
struct V_107 * V_108 )
{
int V_109 = 0 ;
if ( F_65 ( & V_2 -> V_86 , V_108 ) ) {
V_109 = F_21 ( V_63 ,
F_36 ( V_110 ) ,
V_2 -> V_47 , V_2 -> V_48 , V_2 , NULL ,
V_49 ) ;
}
return V_109 ;
}
static void F_66 ( T_2 * V_96 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_10 * V_97 ;
if ( V_7 -> V_11 )
V_97 = V_7 -> V_11 ;
else {
V_97 = F_67 ( V_2 ,
V_2 -> V_111 ) ;
V_7 -> V_11 = V_97 ;
}
V_2 -> V_111 = V_97 ;
V_2 -> V_27 [ V_56 ] = V_97 -> V_77 ;
}
static void F_68 ( T_2 * V_96 ,
struct V_1 * V_2 ,
T_9 V_47 )
{
struct V_112 * V_38 = V_2 -> V_37 . V_38 ;
V_2 -> V_47 = V_47 ;
F_18 ( L_5 ,
V_2 , V_113 [ V_47 ] ) ;
if ( F_69 ( V_38 , V_114 ) ) {
if ( F_70 ( V_2 , V_115 ) && F_71 ( V_38 , V_116 ) )
V_38 -> V_117 = V_118 ;
if ( F_70 ( V_2 , V_119 ) &&
F_71 ( V_38 , V_115 ) )
V_38 -> V_120 |= V_121 ;
}
if ( F_70 ( V_2 , V_122 ) ) {
V_2 -> V_27 [ V_55 ] =
V_2 -> V_123 ;
V_2 -> V_27 [ V_54 ] =
V_2 -> V_123 ;
}
if ( F_70 ( V_2 , V_115 ) ||
F_70 ( V_2 , V_116 ) ||
F_70 ( V_2 , V_119 ) ) {
if ( F_72 ( & V_2 -> V_124 ) )
F_73 ( & V_2 -> V_124 ) ;
if ( ! F_69 ( V_38 , V_125 ) )
V_38 -> V_126 ( V_38 ) ;
}
}
static void F_74 ( T_2 * V_96 ,
struct V_1 * V_2 )
{
struct V_112 * V_38 = V_2 -> V_37 . V_38 ;
if ( F_69 ( V_38 , V_114 ) && F_71 ( V_38 , V_127 ) &&
( ! V_2 -> V_128 ) && ( V_38 -> V_120 != V_129 ) )
return;
F_75 ( V_2 ) ;
F_76 ( V_2 ) ;
}
static void F_77 ( T_2 * V_96 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_10 * V_97 ;
V_97 = F_67 ( V_2 , V_7 -> V_11 ) ;
V_2 -> V_27 [ V_57 ] = V_97 -> V_77 ;
V_7 -> V_11 = V_97 ;
}
static void F_78 ( T_2 * V_96 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_130 * V_131 ;
struct V_79 * V_132 ;
while ( V_7 -> V_133 > V_7 -> V_104 -> V_53 ) {
V_131 = (struct V_130 * ) ( V_7 -> V_104 -> V_53 ) ;
V_132 = F_79 ( V_2 , V_7 , 0 ,
V_49 ) ;
if ( ! V_132 )
return;
F_80 ( & V_2 -> V_90 , V_132 ) ;
switch ( V_131 -> V_134 ) {
case V_135 :
{
T_10 * V_136 ;
V_136 = ( T_10 * ) V_131 -> V_137 ;
switch ( V_136 -> type ) {
case V_138 :
if ( V_2 -> V_19 . V_139 == 0 )
break;
V_2 -> V_19 . V_139 = 0 ;
F_11 ( V_96 , V_35 ,
F_12 ( V_57 ) ) ;
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
static void F_81 ( struct V_140 * V_90 ,
struct V_6 * V_7 )
{
struct V_141 * V_142 ;
F_82 (skip, chunk) {
F_83 ( V_90 , F_40 ( V_142 -> V_143 ) , F_40 ( V_142 -> V_144 ) ) ;
}
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_10 * V_97 ;
struct V_145 * V_146 ;
struct V_145 * V_128 ;
F_85 (pos, temp, &asoc->peer.transport_addr_list) {
V_97 = F_86 ( V_146 , struct V_10 , V_147 ) ;
if ( ! F_87 ( & V_97 -> V_72 ,
& V_2 -> V_19 . V_148 ) ) {
F_88 ( V_2 , & V_97 -> V_72 ) ;
}
}
}
static void F_89 ( struct V_1 * V_2 , int error )
{
struct V_112 * V_38 = V_2 -> V_37 . V_38 ;
if ( ! F_69 ( V_38 , V_125 ) )
V_38 -> V_50 = error ;
}
static void F_90 ( T_2 * V_14 ,
struct V_1 * V_2 ,
T_11 V_47 )
{
struct V_79 * V_132 ;
V_132 = F_44 ( V_2 , 0 , V_47 , 0 ,
V_2 -> V_149 . V_150 ,
V_2 -> V_149 . V_151 ,
NULL , V_49 ) ;
if ( V_132 )
F_80 ( & V_2 -> V_90 , V_132 ) ;
}
static void F_91 ( T_2 * V_14 ,
struct V_1 * V_2 )
{
struct V_79 * V_132 ;
V_132 = F_92 ( V_2 , V_49 ) ;
if ( V_132 )
F_80 ( & V_2 -> V_90 , V_132 ) ;
}
static void F_93 ( struct V_1 * V_2 ,
T_3 V_152 ,
char * V_153 )
{
struct V_10 * V_97 ;
V_97 = V_2 -> V_154 ;
V_2 -> V_155 ++ ;
if ( V_97 -> V_156 > ( V_2 -> V_157 + 1 ) ) {
V_2 -> V_27 [ V_152 ] *= 2 ;
if ( V_2 -> V_27 [ V_152 ] > V_2 -> V_158 ) {
V_2 -> V_27 [ V_152 ] = V_2 -> V_158 ;
}
V_2 -> V_157 ++ ;
F_18 (
L_6
L_7
L_8
L_9 ,
V_153 ,
V_2 -> V_155 ,
V_2 -> V_157 ,
V_2 -> V_27 [ V_152 ] ) ;
}
}
static int F_94 ( struct V_1 * V_2 ,
struct V_159 * V_160 )
{
struct V_6 * V_7 ;
int error = 0 ;
F_54 (chunk, &msg->chunks, frag_list) {
error = F_95 ( & V_2 -> V_86 , V_7 ) ;
if ( error )
break;
}
return error ;
}
static void F_96 ( struct V_1 * V_2 )
{
if ( ! F_97 ( & V_2 -> V_161 ) ) {
struct V_145 * V_162 = V_2 -> V_161 . V_163 ;
struct V_6 * V_164 = F_86 ( V_162 ,
struct V_6 , V_165 ) ;
F_98 ( V_162 ) ;
F_99 ( V_164 ) ;
if ( F_100 ( V_2 , V_164 ) )
F_101 ( V_164 ) ;
else
V_2 -> V_166 = V_164 ;
}
}
int F_21 ( T_4 V_88 , T_5 V_89 ,
T_9 V_47 ,
struct V_167 * V_48 ,
struct V_1 * V_2 ,
void * V_168 ,
T_7 V_95 )
{
T_2 V_14 ;
const T_12 * V_169 ;
T_13 V_170 ;
int error = 0 ;
typedef const char * (F_102)( T_5 );
static F_102 * V_171 [] = {
NULL , V_172 , V_173 , V_174 , V_175 ,
} ;
F_102 * T_14 V_176 ( ( V_177 ) ) = V_171 [ V_88 ] ;
V_169 = F_103 ( V_88 , V_47 , V_89 ) ;
F_104 ( & V_14 ) ;
V_178 ;
V_170 = (* V_169 -> V_179 )( V_48 , V_2 , V_89 , V_168 , & V_14 ) ;
V_180 ;
error = F_105 ( V_88 , V_89 , V_47 ,
V_48 , V_2 , V_168 , V_170 ,
& V_14 , V_95 ) ;
V_181 ;
return error ;
}
static int F_105 ( T_4 V_88 , T_5 V_89 ,
T_9 V_47 ,
struct V_167 * V_48 ,
struct V_1 * V_2 ,
void * V_168 ,
T_13 V_170 ,
T_2 * V_14 ,
T_7 V_95 )
{
int error ;
if ( 0 != ( error = F_106 ( V_88 , V_89 , V_47 ,
V_48 , V_2 ,
V_168 , V_170 ,
V_14 , V_95 ) ) )
goto V_182;
switch ( V_170 ) {
case V_183 :
F_18 ( L_10
L_11 ,
V_47 , V_88 , V_89 . V_7 ) ;
break;
case V_184 :
error = - V_36 ;
break;
case V_185 :
break;
case V_186 :
case V_187 :
break;
case V_188 :
if ( F_107 () )
F_108 ( L_12 ,
V_47 , V_89 . V_7 ) ;
break;
case V_189 :
F_109 ( L_13 ,
V_47 , V_88 , V_89 . V_7 ) ;
break;
case V_190 :
F_108 ( L_14 ,
V_47 , V_88 , V_89 . V_7 ) ;
F_110 () ;
break;
default:
F_108 ( L_15 ,
V_170 , V_47 , V_88 , V_89 . V_7 ) ;
F_110 () ;
break;
}
V_182:
return error ;
}
static int F_106 ( T_4 V_88 ,
T_5 V_89 ,
T_9 V_47 ,
struct V_167 * V_48 ,
struct V_1 * V_2 ,
void * V_168 ,
T_13 V_170 ,
T_2 * V_14 ,
T_7 V_95 )
{
int error = 0 ;
int V_13 ;
T_15 * V_191 ;
struct V_6 * V_192 ;
struct V_6 * V_7 = NULL ;
struct V_193 * V_194 ;
struct V_195 * V_152 ;
unsigned long V_196 ;
struct V_10 * V_97 ;
struct V_107 V_108 ;
int V_197 = 0 ;
if ( V_45 != V_88 )
V_7 = V_168 ;
while ( NULL != ( V_191 = F_111 ( V_14 ) ) ) {
switch ( V_191 -> V_198 ) {
case V_199 :
break;
case V_200 :
if ( V_197 ) {
F_112 ( & V_2 -> V_86 ) ;
V_197 = 0 ;
}
V_2 = V_191 -> V_201 . V_202 ;
F_113 ( V_48 , V_2 ) ;
F_114 ( V_2 ) ;
break;
case V_203 :
F_115 ( V_2 , V_191 -> V_201 . V_202 ) ;
break;
case V_204 :
F_116 ( & V_2 -> V_86 ) ;
break;
case V_87 :
if ( V_197 ) {
F_112 ( & V_2 -> V_86 ) ;
V_197 = 0 ;
}
F_74 ( V_14 , V_2 ) ;
V_2 = NULL ;
break;
case V_84 :
F_68 ( V_14 , V_2 , V_191 -> V_201 . V_47 ) ;
break;
case V_205 :
error = F_117 ( & V_2 -> V_19 . V_24 ,
V_191 -> V_201 . V_206 ) ;
break;
case V_207 :
F_118 ( & V_2 -> V_19 . V_24 , V_191 -> V_201 . V_206 ) ;
F_119 ( & V_2 -> V_90 , V_191 -> V_201 . V_206 ) ;
F_49 ( & V_2 -> V_90 , V_49 ) ;
break;
case V_208 :
F_81 ( & V_2 -> V_90 , V_191 -> V_201 . V_202 ) ;
break;
case V_209 :
V_13 = V_191 -> V_201 . V_210 ;
error = F_8 ( V_2 , V_13 , V_14 ) ;
break;
case V_211 :
error = F_64 ( V_14 , V_2 ,
V_191 -> V_201 . V_202 ) ;
break;
case V_212 :
V_192 = F_120 ( V_2 , V_7 , V_49 ,
0 ) ;
if ( ! V_192 )
goto V_33;
F_11 ( V_14 , V_34 ,
F_14 ( V_192 ) ) ;
break;
case V_213 :
error = F_50 ( V_14 , V_2 , V_7 ,
V_191 -> V_201 . V_202 , V_95 ) ;
break;
case V_214 :
V_192 = F_121 ( V_2 , V_7 ) ;
if ( ! V_192 ) {
if ( V_191 -> V_201 . V_202 )
F_101 ( V_191 -> V_201 . V_202 ) ;
goto V_33;
}
F_11 ( V_14 , V_34 ,
F_14 ( V_192 ) ) ;
if ( V_191 -> V_201 . V_202 )
F_11 ( V_14 , V_34 ,
F_14 ( V_191 -> V_201 . V_202 ) ) ;
if ( V_192 -> V_11 ) {
V_192 -> V_11 -> V_156 ++ ;
V_2 -> V_154 = V_192 -> V_11 ;
}
if ( ( V_2 -> V_19 . V_215 !=
V_2 -> V_19 . V_216 ) &&
( V_2 -> V_155 > 0 ) ) {
F_11 ( V_14 ,
V_217 ,
F_47 () ) ;
}
break;
case V_218 :
V_2 -> V_66 = 0 ;
V_192 = F_122 ( V_2 , V_7 ) ;
if ( ! V_192 )
goto V_33;
F_11 ( V_14 , V_34 ,
F_14 ( V_192 ) ) ;
break;
case V_219 :
F_18 ( L_16 ,
L_17 , V_191 -> V_201 . V_202 ,
L_18 , & V_2 -> V_90 ) ;
F_123 ( & V_2 -> V_90 , V_191 -> V_201 . V_202 ,
V_49 ) ;
break;
case V_83 :
F_18 ( L_16 ,
L_19 , V_191 -> V_201 . V_202 ,
L_18 , & V_2 -> V_90 ) ;
F_80 ( & V_2 -> V_90 , V_191 -> V_201 . V_202 ) ;
break;
case V_34 :
if ( ! V_2 -> V_86 . V_220 ) {
F_124 ( & V_2 -> V_86 ) ;
V_197 = 1 ;
}
error = F_95 ( & V_2 -> V_86 , V_191 -> V_201 . V_202 ) ;
break;
case V_221 :
V_194 = V_191 -> V_201 . V_202 ;
F_125 ( V_194 ) ;
F_126 ( V_194 ) ;
break;
case V_222 :
F_127 ( & V_2 -> V_86 , V_191 -> V_201 . V_11 ,
V_223 ) ;
break;
case V_224 :
F_127 ( & V_2 -> V_86 , V_191 -> V_201 . V_11 ,
V_225 ) ;
break;
case V_226 :
F_1 ( V_2 , V_191 -> V_201 . V_206 ) ;
break;
case V_227 :
V_192 = F_2 ( V_2 , V_191 -> V_201 . V_206 ,
V_7 ) ;
if ( V_192 )
F_11 ( V_14 , V_34 ,
F_14 ( V_192 ) ) ;
break;
case V_228 :
F_7 ( V_2 , V_191 -> V_201 . V_206 ) ;
break;
case V_229 :
F_66 ( V_14 , V_2 , V_191 -> V_201 . V_202 ) ;
break;
case V_230 :
V_152 = & V_2 -> V_52 [ V_191 -> V_201 . V_231 ] ;
if ( F_59 ( V_152 ) )
break;
case V_232 :
V_152 = & V_2 -> V_52 [ V_191 -> V_201 . V_231 ] ;
V_196 = V_2 -> V_27 [ V_191 -> V_201 . V_231 ] ;
F_128 ( ! V_196 ) ;
V_152 -> V_233 = V_41 + V_196 ;
F_26 ( V_2 ) ;
F_129 ( V_152 ) ;
break;
case V_30 :
V_152 = & V_2 -> V_52 [ V_191 -> V_201 . V_231 ] ;
V_196 = V_2 -> V_27 [ V_191 -> V_201 . V_231 ] ;
if ( ! F_19 ( V_152 , V_41 + V_196 ) )
F_26 ( V_2 ) ;
break;
case V_35 :
V_152 = & V_2 -> V_52 [ V_191 -> V_201 . V_231 ] ;
if ( F_59 ( V_152 ) && F_57 ( V_152 ) )
F_27 ( V_2 ) ;
break;
case V_234 :
V_7 = V_191 -> V_201 . V_202 ;
V_97 = F_67 ( V_2 ,
V_2 -> V_154 ) ;
V_2 -> V_154 = V_97 ;
V_7 -> V_11 = V_97 ;
V_97 -> V_156 ++ ;
F_130 ( V_2 , V_97 ) ;
break;
case V_235 :
F_93 ( V_2 ,
V_55 ,
L_20 ) ;
F_11 ( V_14 , V_30 ,
F_12 ( V_55 ) ) ;
break;
case V_236 :
F_93 ( V_2 ,
V_54 ,
L_21 ) ;
F_54 (t, &asoc->peer.transport_addr_list,
transports) {
F_131 ( & V_2 -> V_86 , V_97 ,
V_223 ) ;
}
F_11 ( V_14 ,
V_30 ,
F_12 ( V_54 ) ) ;
break;
case V_237 :
F_43 ( V_14 , V_2 , V_191 -> V_201 . V_109 ) ;
break;
case V_238 :
F_48 ( V_14 , V_2 , V_88 ,
V_89 , V_7 , V_191 -> V_201 . V_109 ) ;
break;
case V_239 :
V_2 -> V_155 ++ ;
break;
case V_240 :
V_2 -> V_155 = 0 ;
V_2 -> V_157 = 0 ;
F_54 (t, &asoc->peer.transport_addr_list,
transports) {
V_97 -> V_156 = 0 ;
}
break;
case V_241 :
F_132 ( & V_2 -> V_19 . V_24 ,
V_191 -> V_201 . V_206 ) ;
break;
case V_242 :
F_18 ( L_22 ) ;
break;
case V_243 :
F_38 ( V_2 , V_191 -> V_201 . V_11 ,
0 ) ;
break;
case V_244 :
V_97 = V_191 -> V_201 . V_11 ;
F_5 ( V_97 , V_245 ) ;
break;
case V_246 :
V_97 = V_191 -> V_201 . V_11 ;
F_38 ( V_2 , V_97 , 1 ) ;
V_97 -> V_69 = 1 ;
break;
case V_247 :
V_97 = V_191 -> V_201 . V_11 ;
F_61 ( V_14 , V_2 , V_97 , V_7 ) ;
break;
case V_248 :
F_53 ( V_14 , V_2 ) ;
break;
case V_249 :
V_97 = V_191 -> V_201 . V_11 ;
F_60 ( V_14 , V_97 ) ;
break;
case V_250 :
F_56 ( V_14 , V_2 ) ;
break;
case V_251 :
error = V_191 -> V_201 . error ;
break;
case V_252 :
V_108 . V_253 = V_191 -> V_201 . V_254 ;
V_108 . V_31 = V_2 -> V_19 . V_32 +
V_2 -> V_86 . V_255 ;
V_108 . V_256 = 0 ;
V_108 . V_257 = 0 ;
F_11 ( V_14 , V_211 ,
F_133 ( & V_108 ) ) ;
break;
case V_258 :
V_7 -> V_259 = 1 ;
if ( V_2 ) {
F_112 ( & V_2 -> V_86 ) ;
V_197 = 0 ;
}
break;
case V_260 :
V_97 = V_191 -> V_201 . V_11 ;
V_97 -> V_103 = 1 ;
break;
case V_261 :
F_134 ( & V_2 -> V_90 , V_191 -> V_201 . V_202 ,
V_49 ) ;
break;
case V_262 :
F_135 ( & V_2 -> V_90 , V_191 -> V_201 . V_202 ,
V_49 ) ;
break;
case V_263 :
F_77 ( V_14 , V_2 , V_191 -> V_201 . V_202 ) ;
break;
case V_264 :
F_78 ( V_14 , V_2 , V_7 ) ;
break;
case V_265 :
V_2 -> V_19 . V_266 . V_267 = 0 ;
break;
case V_268 :
F_84 ( V_2 ) ;
break;
case V_269 :
F_58 ( V_14 , V_2 ) ;
break;
case V_217 :
V_97 = V_2 -> V_19 . V_215 ;
V_2 -> V_19 . V_215 = V_2 -> V_19 . V_216 ;
error = F_112 ( & V_2 -> V_86 ) ;
V_197 = 0 ;
V_2 -> V_19 . V_215 = V_97 ;
break;
case V_270 :
F_89 ( V_2 , V_191 -> V_201 . error ) ;
break;
case V_271 :
F_90 ( V_14 , V_2 ,
V_191 -> V_201 . T_11 ) ;
break;
case V_272 :
F_91 ( V_14 , V_2 ) ;
break;
case V_273 :
error = F_136 ( V_2 ,
V_49 ) ;
break;
case V_274 :
V_2 -> V_19 . V_266 . V_267 = V_191 -> V_201 . V_206 ;
break;
case V_275 :
if ( ! V_2 -> V_86 . V_220 ) {
F_124 ( & V_2 -> V_86 ) ;
V_197 = 1 ;
}
error = F_94 ( V_2 , V_191 -> V_201 . V_160 ) ;
break;
case V_276 :
F_96 ( V_2 ) ;
break;
case V_277 :
F_137 ( V_2 ) ;
break;
case V_278 :
V_2 = V_191 -> V_201 . V_2 ;
break;
default:
F_109 ( L_23 ,
V_191 -> V_198 , V_191 -> V_201 . V_202 ) ;
break;
}
if ( error )
break;
}
V_279:
if ( V_2 && V_91 == V_88 && V_7 ) {
if ( V_7 -> V_280 || V_7 -> V_281 )
error = F_112 ( & V_2 -> V_86 ) ;
} else if ( V_197 )
error = F_112 ( & V_2 -> V_86 ) ;
return error ;
V_33:
error = - V_36 ;
goto V_279;
}
