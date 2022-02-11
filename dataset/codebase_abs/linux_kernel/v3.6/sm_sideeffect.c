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
static void F_38 ( T_2 * V_14 ,
struct V_1 * V_2 ,
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
if ( ( V_11 -> V_47 != V_71 ) &&
( V_2 -> V_72 < V_11 -> V_73 ) &&
( V_11 -> V_68 > V_2 -> V_72 ) ) {
F_39 ( V_2 , V_11 ,
V_74 ,
0 ) ;
F_40 ( V_14 , V_11 ) ;
}
if ( V_11 -> V_47 != V_67 &&
( V_11 -> V_68 > V_11 -> V_73 ) ) {
F_41 ( L_3 ,
L_4 ,
V_2 ,
( & V_11 -> V_75 ) ,
F_42 ( V_11 -> V_75 . V_76 . V_77 ) ) ;
F_39 ( V_2 , V_11 ,
V_78 ,
V_79 ) ;
}
if ( ! V_65 || V_11 -> V_69 ) {
V_11 -> V_80 = F_43 ( ( V_11 -> V_80 * 2 ) , V_11 -> V_2 -> V_81 ) ;
}
}
static void F_44 ( T_2 * V_14 ,
struct V_1 * V_2 ,
unsigned int error )
{
struct V_82 * V_83 ;
V_83 = F_45 ( V_2 , 0 , V_84 ,
( V_85 ) error , 0 , 0 , NULL ,
V_49 ) ;
if ( V_83 )
F_11 ( V_14 , V_86 ,
F_46 ( V_83 ) ) ;
F_11 ( V_14 , V_87 ,
F_47 ( V_88 ) ) ;
V_2 -> V_89 . error = error ;
F_11 ( V_14 , V_90 , F_48 () ) ;
}
static void F_49 ( T_2 * V_14 ,
struct V_1 * V_2 ,
T_4 V_91 ,
T_5 V_92 ,
struct V_6 * V_7 ,
unsigned int error )
{
struct V_82 * V_83 ;
F_50 ( & V_2 -> V_93 , V_49 ) ;
if ( V_91 == V_94 && V_92 . V_7 == V_95 )
V_83 = F_45 ( V_2 , 0 , V_96 ,
( V_85 ) error , 0 , 0 , V_7 ,
V_49 ) ;
else
V_83 = F_45 ( V_2 , 0 , V_96 ,
( V_85 ) error , 0 , 0 , NULL ,
V_49 ) ;
if ( V_83 )
F_11 ( V_14 , V_86 ,
F_46 ( V_83 ) ) ;
F_11 ( V_14 , V_87 ,
F_47 ( V_88 ) ) ;
V_2 -> V_89 . error = error ;
F_11 ( V_14 , V_90 , F_48 () ) ;
}
static int F_51 ( T_2 * V_14 ,
struct V_1 * V_2 ,
struct V_6 * V_7 ,
T_6 * V_97 ,
T_7 V_98 )
{
int error ;
if ( ! F_52 ( V_2 , V_7 , F_53 ( V_7 ) , V_97 , V_98 ) )
error = - V_36 ;
else
error = 0 ;
return error ;
}
static void F_54 ( T_2 * V_99 ,
struct V_1 * V_2 )
{
struct V_10 * V_100 ;
F_55 (t, &asoc->peer.transport_addr_list, transports) {
if ( ! F_19 ( & V_100 -> V_60 , F_56 ( V_100 ) ) )
F_20 ( V_100 ) ;
}
}
static void F_57 ( T_2 * V_99 ,
struct V_1 * V_2 )
{
struct V_10 * V_100 ;
F_55 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_58 ( & V_100 -> V_60 ) )
F_24 ( V_100 ) ;
}
}
static void F_59 ( T_2 * V_99 ,
struct V_1 * V_2 )
{
struct V_10 * V_100 ;
F_55 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_60 ( & V_100 -> V_40 ) &&
F_58 ( & V_100 -> V_40 ) ) {
F_24 ( V_100 ) ;
}
}
}
static void F_40 ( T_2 * V_99 ,
struct V_10 * V_100 )
{
if ( ! F_19 ( & V_100 -> V_60 , F_56 ( V_100 ) ) )
F_20 ( V_100 ) ;
}
static void F_61 ( T_2 * V_99 ,
struct V_1 * V_2 ,
struct V_10 * V_100 ,
struct V_6 * V_7 )
{
T_8 * V_101 ;
int V_102 = 0 ;
V_100 -> V_68 = 0 ;
if ( V_100 -> V_2 -> V_47 != V_103 )
V_100 -> V_2 -> V_66 = 0 ;
V_100 -> V_69 = 0 ;
if ( ( V_100 -> V_47 == V_67 ) || ( V_100 -> V_47 == V_70 ) ) {
V_102 = 1 ;
F_39 ( V_2 , V_100 , V_104 ,
V_105 ) ;
}
if ( V_100 -> V_47 == V_71 )
F_39 ( V_2 , V_100 , V_104 ,
V_105 ) ;
if ( V_100 -> V_106 == 0 )
V_100 -> V_106 = 1 ;
V_101 = ( T_8 * ) V_7 -> V_107 -> V_53 ;
F_62 ( V_100 , ( V_41 - V_101 -> V_108 ) ) ;
if ( ! F_19 ( & V_100 -> V_60 , F_56 ( V_100 ) ) )
F_20 ( V_100 ) ;
if ( V_102 && V_2 -> V_19 . V_109 == 1 )
F_63 ( V_100 ) ;
}
static int F_64 ( T_2 * V_99 ,
struct V_1 * V_2 ,
struct V_110 * V_111 )
{
int V_112 = 0 ;
if ( F_65 ( & V_2 -> V_89 , V_111 ) ) {
V_112 = F_21 ( V_63 ,
F_36 ( V_113 ) ,
V_2 -> V_47 , V_2 -> V_48 , V_2 , NULL ,
V_49 ) ;
}
return V_112 ;
}
static void F_66 ( T_2 * V_99 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_10 * V_100 ;
if ( V_7 -> V_11 )
V_100 = V_7 -> V_11 ;
else {
V_100 = F_67 ( V_2 ,
V_2 -> V_114 ) ;
V_7 -> V_11 = V_100 ;
}
V_2 -> V_114 = V_100 ;
V_2 -> V_27 [ V_56 ] = V_100 -> V_80 ;
}
static void F_68 ( T_2 * V_99 ,
struct V_1 * V_2 ,
T_9 V_47 )
{
struct V_115 * V_38 = V_2 -> V_37 . V_38 ;
V_2 -> V_47 = V_47 ;
F_18 ( L_5 ,
V_2 , V_116 [ V_47 ] ) ;
if ( F_69 ( V_38 , V_117 ) ) {
if ( F_70 ( V_2 , V_118 ) && F_71 ( V_38 , V_119 ) )
V_38 -> V_120 = V_121 ;
if ( F_70 ( V_2 , V_122 ) &&
F_71 ( V_38 , V_118 ) )
V_38 -> V_123 |= V_124 ;
}
if ( F_70 ( V_2 , V_125 ) ) {
V_2 -> V_27 [ V_55 ] =
V_2 -> V_126 ;
V_2 -> V_27 [ V_54 ] =
V_2 -> V_126 ;
}
if ( F_70 ( V_2 , V_118 ) ||
F_70 ( V_2 , V_119 ) ||
F_70 ( V_2 , V_122 ) ) {
if ( F_72 ( & V_2 -> V_127 ) )
F_73 ( & V_2 -> V_127 ) ;
if ( ! F_69 ( V_38 , V_128 ) )
V_38 -> V_129 ( V_38 ) ;
}
}
static void F_74 ( T_2 * V_99 ,
struct V_1 * V_2 )
{
struct V_115 * V_38 = V_2 -> V_37 . V_38 ;
if ( F_69 ( V_38 , V_117 ) && F_71 ( V_38 , V_130 ) &&
( ! V_2 -> V_131 ) && ( V_38 -> V_123 != V_132 ) )
return;
F_75 ( V_2 ) ;
F_76 ( V_2 ) ;
}
static void F_77 ( T_2 * V_99 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_10 * V_100 ;
V_100 = F_67 ( V_2 , V_7 -> V_11 ) ;
V_2 -> V_27 [ V_57 ] = V_100 -> V_80 ;
V_7 -> V_11 = V_100 ;
}
static void F_78 ( T_2 * V_99 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_133 * V_134 ;
struct V_82 * V_135 ;
while ( V_7 -> V_136 > V_7 -> V_107 -> V_53 ) {
V_134 = (struct V_133 * ) ( V_7 -> V_107 -> V_53 ) ;
V_135 = F_79 ( V_2 , V_7 , 0 ,
V_49 ) ;
if ( ! V_135 )
return;
F_80 ( & V_2 -> V_93 , V_135 ) ;
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
F_11 ( V_99 , V_35 ,
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
static void F_81 ( struct V_143 * V_93 ,
struct V_6 * V_7 )
{
struct V_144 * V_145 ;
F_82 (skip, chunk) {
F_83 ( V_93 , F_42 ( V_145 -> V_146 ) , F_42 ( V_145 -> V_147 ) ) ;
}
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_10 * V_100 ;
struct V_148 * V_149 ;
struct V_148 * V_131 ;
F_85 (pos, temp, &asoc->peer.transport_addr_list) {
V_100 = F_86 ( V_149 , struct V_10 , V_150 ) ;
if ( ! F_87 ( & V_100 -> V_75 ,
& V_2 -> V_19 . V_151 ) ) {
F_88 ( V_2 , & V_100 -> V_75 ) ;
}
}
}
static void F_89 ( struct V_1 * V_2 , int error )
{
struct V_115 * V_38 = V_2 -> V_37 . V_38 ;
if ( ! F_69 ( V_38 , V_128 ) )
V_38 -> V_50 = error ;
}
static void F_90 ( T_2 * V_14 ,
struct V_1 * V_2 ,
T_11 V_47 )
{
struct V_82 * V_135 ;
V_135 = F_45 ( V_2 , 0 , V_47 , 0 ,
V_2 -> V_152 . V_153 ,
V_2 -> V_152 . V_154 ,
NULL , V_49 ) ;
if ( V_135 )
F_80 ( & V_2 -> V_93 , V_135 ) ;
}
static void F_91 ( T_2 * V_14 ,
struct V_1 * V_2 )
{
struct V_82 * V_135 ;
V_135 = F_92 ( V_2 , V_49 ) ;
if ( V_135 )
F_80 ( & V_2 -> V_93 , V_135 ) ;
}
static void F_93 ( struct V_1 * V_2 ,
T_3 V_155 ,
char * V_156 )
{
struct V_10 * V_100 ;
V_100 = V_2 -> V_157 ;
V_2 -> V_158 ++ ;
if ( V_100 -> V_159 > ( V_2 -> V_160 + 1 ) ) {
V_2 -> V_27 [ V_155 ] *= 2 ;
if ( V_2 -> V_27 [ V_155 ] > V_2 -> V_161 ) {
V_2 -> V_27 [ V_155 ] = V_2 -> V_161 ;
}
V_2 -> V_160 ++ ;
F_18 (
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
static int F_94 ( struct V_1 * V_2 ,
struct V_162 * V_163 )
{
struct V_6 * V_7 ;
int error = 0 ;
F_55 (chunk, &msg->chunks, frag_list) {
error = F_95 ( & V_2 -> V_89 , V_7 ) ;
if ( error )
break;
}
return error ;
}
static void F_96 ( struct V_1 * V_2 )
{
if ( ! F_97 ( & V_2 -> V_164 ) ) {
struct V_148 * V_165 = V_2 -> V_164 . V_166 ;
struct V_6 * V_167 = F_86 ( V_165 ,
struct V_6 , V_168 ) ;
F_98 ( V_165 ) ;
F_99 ( V_167 ) ;
if ( F_100 ( V_2 , V_167 ) )
F_101 ( V_167 ) ;
else
V_2 -> V_169 = V_167 ;
}
}
int F_21 ( T_4 V_91 , T_5 V_92 ,
T_9 V_47 ,
struct V_170 * V_48 ,
struct V_1 * V_2 ,
void * V_171 ,
T_7 V_98 )
{
T_2 V_14 ;
const T_12 * V_172 ;
T_13 V_173 ;
int error = 0 ;
typedef const char * (F_102)( T_5 );
static F_102 * V_174 [] = {
NULL , V_175 , V_176 , V_177 , V_178 ,
} ;
F_102 * T_14 V_179 ( ( V_180 ) ) = V_174 [ V_91 ] ;
V_172 = F_103 ( V_91 , V_47 , V_92 ) ;
F_104 ( & V_14 ) ;
V_181 ;
V_173 = (* V_172 -> V_182 )( V_48 , V_2 , V_92 , V_171 , & V_14 ) ;
V_183 ;
error = F_105 ( V_91 , V_92 , V_47 ,
V_48 , V_2 , V_171 , V_173 ,
& V_14 , V_98 ) ;
V_184 ;
return error ;
}
static int F_105 ( T_4 V_91 , T_5 V_92 ,
T_9 V_47 ,
struct V_170 * V_48 ,
struct V_1 * V_2 ,
void * V_171 ,
T_13 V_173 ,
T_2 * V_14 ,
T_7 V_98 )
{
int error ;
if ( 0 != ( error = F_106 ( V_91 , V_92 , V_47 ,
V_48 , V_2 ,
V_171 , V_173 ,
V_14 , V_98 ) ) )
goto V_185;
switch ( V_173 ) {
case V_186 :
F_18 ( L_10
L_11 ,
V_47 , V_91 , V_92 . V_7 ) ;
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
F_107 ( L_12 ,
V_47 , V_92 . V_7 ) ;
break;
case V_192 :
F_108 ( L_13 ,
V_47 , V_91 , V_92 . V_7 ) ;
break;
case V_193 :
F_109 ( L_14 ,
V_47 , V_91 , V_92 . V_7 ) ;
F_110 () ;
break;
default:
F_109 ( L_15 ,
V_173 , V_47 , V_91 , V_92 . V_7 ) ;
F_110 () ;
break;
}
V_185:
return error ;
}
static int F_106 ( T_4 V_91 ,
T_5 V_92 ,
T_9 V_47 ,
struct V_170 * V_48 ,
struct V_1 * V_2 ,
void * V_171 ,
T_13 V_173 ,
T_2 * V_14 ,
T_7 V_98 )
{
int error = 0 ;
int V_13 ;
T_15 * V_194 ;
struct V_6 * V_195 ;
struct V_6 * V_7 = NULL ;
struct V_196 * V_197 ;
struct V_198 * V_155 ;
unsigned long V_199 ;
struct V_10 * V_100 ;
struct V_110 V_111 ;
int V_200 = 0 ;
if ( V_45 != V_91 )
V_7 = V_171 ;
while ( NULL != ( V_194 = F_111 ( V_14 ) ) ) {
switch ( V_194 -> V_201 ) {
case V_202 :
break;
case V_203 :
if ( V_200 ) {
F_112 ( & V_2 -> V_89 ) ;
V_200 = 0 ;
}
V_2 = V_194 -> V_204 . V_205 ;
F_113 ( V_48 , V_2 ) ;
F_114 ( V_2 ) ;
break;
case V_206 :
F_115 ( V_2 , V_194 -> V_204 . V_205 ) ;
break;
case V_207 :
F_116 ( & V_2 -> V_89 ) ;
break;
case V_90 :
if ( V_200 ) {
F_112 ( & V_2 -> V_89 ) ;
V_200 = 0 ;
}
F_74 ( V_14 , V_2 ) ;
V_2 = NULL ;
break;
case V_87 :
F_68 ( V_14 , V_2 , V_194 -> V_204 . V_47 ) ;
break;
case V_208 :
error = F_117 ( & V_2 -> V_19 . V_24 ,
V_194 -> V_204 . V_209 , NULL ) ;
break;
case V_210 :
F_118 ( & V_2 -> V_19 . V_24 , V_194 -> V_204 . V_209 ) ;
F_119 ( & V_2 -> V_93 , V_194 -> V_204 . V_209 ) ;
F_50 ( & V_2 -> V_93 , V_49 ) ;
break;
case V_211 :
F_81 ( & V_2 -> V_93 , V_194 -> V_204 . V_205 ) ;
break;
case V_212 :
V_13 = V_194 -> V_204 . V_213 ;
error = F_8 ( V_2 , V_13 , V_14 ) ;
break;
case V_214 :
error = F_64 ( V_14 , V_2 ,
V_194 -> V_204 . V_205 ) ;
break;
case V_215 :
V_195 = F_120 ( V_2 , V_7 , V_49 ,
0 ) ;
if ( ! V_195 )
goto V_33;
F_11 ( V_14 , V_34 ,
F_14 ( V_195 ) ) ;
break;
case V_216 :
error = F_51 ( V_14 , V_2 , V_7 ,
V_194 -> V_204 . V_205 , V_98 ) ;
break;
case V_217 :
V_195 = F_121 ( V_2 , V_7 ) ;
if ( ! V_195 ) {
if ( V_194 -> V_204 . V_205 )
F_101 ( V_194 -> V_204 . V_205 ) ;
goto V_33;
}
F_11 ( V_14 , V_34 ,
F_14 ( V_195 ) ) ;
if ( V_194 -> V_204 . V_205 )
F_11 ( V_14 , V_34 ,
F_14 ( V_194 -> V_204 . V_205 ) ) ;
if ( V_195 -> V_11 ) {
V_195 -> V_11 -> V_159 ++ ;
V_2 -> V_157 = V_195 -> V_11 ;
}
if ( ( V_2 -> V_19 . V_218 !=
V_2 -> V_19 . V_219 ) &&
( V_2 -> V_158 > 0 ) ) {
F_11 ( V_14 ,
V_220 ,
F_48 () ) ;
}
break;
case V_221 :
V_2 -> V_66 = 0 ;
V_195 = F_122 ( V_2 , V_7 ) ;
if ( ! V_195 )
goto V_33;
F_11 ( V_14 , V_34 ,
F_14 ( V_195 ) ) ;
break;
case V_222 :
F_18 ( L_16 ,
L_17 , V_194 -> V_204 . V_205 ,
L_18 , & V_2 -> V_93 ) ;
F_123 ( & V_2 -> V_93 , V_194 -> V_204 . V_205 ,
V_49 ) ;
break;
case V_86 :
F_18 ( L_16 ,
L_19 , V_194 -> V_204 . V_205 ,
L_18 , & V_2 -> V_93 ) ;
F_80 ( & V_2 -> V_93 , V_194 -> V_204 . V_205 ) ;
break;
case V_34 :
if ( ! V_2 -> V_89 . V_223 ) {
F_124 ( & V_2 -> V_89 ) ;
V_200 = 1 ;
}
error = F_95 ( & V_2 -> V_89 , V_194 -> V_204 . V_205 ) ;
break;
case V_224 :
V_197 = V_194 -> V_204 . V_205 ;
F_125 ( V_197 ) ;
F_126 ( V_197 ) ;
break;
case V_225 :
F_127 ( & V_2 -> V_89 , V_194 -> V_204 . V_11 ,
V_226 ) ;
break;
case V_227 :
F_127 ( & V_2 -> V_89 , V_194 -> V_204 . V_11 ,
V_228 ) ;
break;
case V_229 :
F_1 ( V_2 , V_194 -> V_204 . V_209 ) ;
break;
case V_230 :
V_195 = F_2 ( V_2 , V_194 -> V_204 . V_209 ,
V_7 ) ;
if ( V_195 )
F_11 ( V_14 , V_34 ,
F_14 ( V_195 ) ) ;
break;
case V_231 :
F_7 ( V_2 , V_194 -> V_204 . V_209 ) ;
break;
case V_232 :
F_66 ( V_14 , V_2 , V_194 -> V_204 . V_205 ) ;
break;
case V_233 :
V_155 = & V_2 -> V_52 [ V_194 -> V_204 . V_234 ] ;
if ( F_60 ( V_155 ) )
break;
case V_235 :
V_155 = & V_2 -> V_52 [ V_194 -> V_204 . V_234 ] ;
V_199 = V_2 -> V_27 [ V_194 -> V_204 . V_234 ] ;
F_128 ( ! V_199 ) ;
V_155 -> V_236 = V_41 + V_199 ;
F_26 ( V_2 ) ;
F_129 ( V_155 ) ;
break;
case V_30 :
V_155 = & V_2 -> V_52 [ V_194 -> V_204 . V_234 ] ;
V_199 = V_2 -> V_27 [ V_194 -> V_204 . V_234 ] ;
if ( ! F_19 ( V_155 , V_41 + V_199 ) )
F_26 ( V_2 ) ;
break;
case V_35 :
V_155 = & V_2 -> V_52 [ V_194 -> V_204 . V_234 ] ;
if ( F_60 ( V_155 ) && F_58 ( V_155 ) )
F_27 ( V_2 ) ;
break;
case V_237 :
V_7 = V_194 -> V_204 . V_205 ;
V_100 = F_67 ( V_2 ,
V_2 -> V_157 ) ;
V_2 -> V_157 = V_100 ;
V_7 -> V_11 = V_100 ;
V_100 -> V_159 ++ ;
F_130 ( V_2 , V_100 ) ;
break;
case V_238 :
F_93 ( V_2 ,
V_55 ,
L_20 ) ;
F_11 ( V_14 , V_30 ,
F_12 ( V_55 ) ) ;
break;
case V_239 :
F_93 ( V_2 ,
V_54 ,
L_21 ) ;
F_55 (t, &asoc->peer.transport_addr_list,
transports) {
F_131 ( & V_2 -> V_89 , V_100 ,
V_226 ) ;
}
F_11 ( V_14 ,
V_30 ,
F_12 ( V_54 ) ) ;
break;
case V_240 :
F_44 ( V_14 , V_2 , V_194 -> V_204 . V_112 ) ;
break;
case V_241 :
F_49 ( V_14 , V_2 , V_91 ,
V_92 , V_7 , V_194 -> V_204 . V_112 ) ;
break;
case V_242 :
V_2 -> V_158 ++ ;
break;
case V_243 :
V_2 -> V_158 = 0 ;
V_2 -> V_160 = 0 ;
F_55 (t, &asoc->peer.transport_addr_list,
transports) {
V_100 -> V_159 = 0 ;
}
break;
case V_244 :
F_132 ( & V_2 -> V_19 . V_24 ,
V_194 -> V_204 . V_209 ) ;
break;
case V_245 :
F_18 ( L_22 ) ;
break;
case V_246 :
F_38 ( V_14 , V_2 ,
V_194 -> V_204 . V_11 , 0 ) ;
break;
case V_247 :
V_100 = V_194 -> V_204 . V_11 ;
F_5 ( V_100 , V_248 ) ;
break;
case V_249 :
V_100 = V_194 -> V_204 . V_11 ;
F_38 ( V_14 , V_2 ,
V_100 , 1 ) ;
V_100 -> V_69 = 1 ;
break;
case V_250 :
V_100 = V_194 -> V_204 . V_11 ;
F_61 ( V_14 , V_2 , V_100 , V_7 ) ;
break;
case V_251 :
F_54 ( V_14 , V_2 ) ;
break;
case V_252 :
V_100 = V_194 -> V_204 . V_11 ;
F_40 ( V_14 , V_100 ) ;
break;
case V_253 :
F_57 ( V_14 , V_2 ) ;
break;
case V_254 :
error = V_194 -> V_204 . error ;
break;
case V_255 :
V_111 . V_256 = V_194 -> V_204 . V_257 ;
V_111 . V_31 = V_2 -> V_19 . V_32 +
V_2 -> V_89 . V_258 ;
V_111 . V_259 = 0 ;
V_111 . V_260 = 0 ;
F_11 ( V_14 , V_214 ,
F_133 ( & V_111 ) ) ;
break;
case V_261 :
V_7 -> V_262 = 1 ;
if ( V_2 ) {
F_112 ( & V_2 -> V_89 ) ;
V_200 = 0 ;
}
break;
case V_263 :
V_100 = V_194 -> V_204 . V_11 ;
V_100 -> V_106 = 1 ;
break;
case V_264 :
F_134 ( & V_2 -> V_93 , V_194 -> V_204 . V_205 ,
V_49 ) ;
break;
case V_265 :
F_135 ( & V_2 -> V_93 , V_194 -> V_204 . V_205 ,
V_49 ) ;
break;
case V_266 :
F_77 ( V_14 , V_2 , V_194 -> V_204 . V_205 ) ;
break;
case V_267 :
F_78 ( V_14 , V_2 , V_7 ) ;
break;
case V_268 :
V_2 -> V_19 . V_269 . V_270 = 0 ;
break;
case V_271 :
F_84 ( V_2 ) ;
break;
case V_272 :
F_59 ( V_14 , V_2 ) ;
break;
case V_220 :
V_100 = V_2 -> V_19 . V_218 ;
V_2 -> V_19 . V_218 = V_2 -> V_19 . V_219 ;
error = F_112 ( & V_2 -> V_89 ) ;
V_200 = 0 ;
V_2 -> V_19 . V_218 = V_100 ;
break;
case V_273 :
F_89 ( V_2 , V_194 -> V_204 . error ) ;
break;
case V_274 :
F_90 ( V_14 , V_2 ,
V_194 -> V_204 . T_11 ) ;
break;
case V_275 :
F_91 ( V_14 , V_2 ) ;
break;
case V_276 :
error = F_136 ( V_2 ,
V_49 ) ;
break;
case V_277 :
V_2 -> V_19 . V_269 . V_270 = V_194 -> V_204 . V_209 ;
break;
case V_278 :
if ( ! V_2 -> V_89 . V_223 ) {
F_124 ( & V_2 -> V_89 ) ;
V_200 = 1 ;
}
error = F_94 ( V_2 , V_194 -> V_204 . V_163 ) ;
break;
case V_279 :
F_96 ( V_2 ) ;
break;
case V_280 :
F_137 ( V_2 ) ;
break;
case V_281 :
V_2 = V_194 -> V_204 . V_2 ;
break;
default:
F_108 ( L_23 ,
V_194 -> V_201 , V_194 -> V_204 . V_205 ) ;
break;
}
if ( error )
break;
}
V_282:
if ( V_2 && V_94 == V_91 && V_7 ) {
if ( V_7 -> V_283 || V_7 -> V_284 )
error = F_112 ( & V_2 -> V_89 ) ;
} else if ( V_200 )
error = F_112 ( & V_2 -> V_89 ) ;
return error ;
V_33:
error = - V_36 ;
goto V_282;
}
