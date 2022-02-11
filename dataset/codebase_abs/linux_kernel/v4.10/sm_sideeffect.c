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
T_1 V_31 = V_2 -> V_32 ;
V_2 -> V_32 = V_2 -> V_33 ;
V_17 = F_13 ( V_2 ) ;
if ( ! V_17 ) {
V_2 -> V_32 = V_31 ;
goto V_34;
}
V_2 -> V_19 . V_23 = 0 ;
V_2 -> V_19 . V_25 = 0 ;
F_11 ( V_14 , V_35 , F_14 ( V_17 ) ) ;
F_11 ( V_14 , V_36 ,
F_12 ( V_28 ) ) ;
}
return error ;
V_34:
error = - V_37 ;
return error ;
}
void F_15 ( unsigned long V_19 )
{
int error ;
struct V_10 * V_11 = (struct V_10 * ) V_19 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_38 * V_39 = V_2 -> V_40 . V_39 ;
struct V_41 * V_41 = F_16 ( V_39 ) ;
F_17 ( V_39 ) ;
if ( F_18 ( V_39 ) ) {
F_19 ( L_1 , V_42 ) ;
if ( ! F_20 ( & V_11 -> V_43 , V_44 + ( V_45 / 20 ) ) )
F_21 ( V_11 ) ;
goto V_46;
}
error = F_22 ( V_41 , V_47 ,
F_23 ( V_48 ) ,
V_2 -> V_49 ,
V_2 -> V_50 , V_2 ,
V_11 , V_51 ) ;
if ( error )
V_39 -> V_52 = - error ;
V_46:
F_24 ( V_39 ) ;
F_25 ( V_11 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
T_3 V_53 )
{
struct V_38 * V_39 = V_2 -> V_40 . V_39 ;
struct V_41 * V_41 = F_16 ( V_39 ) ;
int error = 0 ;
F_17 ( V_39 ) ;
if ( F_18 ( V_39 ) ) {
F_19 ( L_2 , V_42 ,
V_53 ) ;
if ( ! F_20 ( & V_2 -> V_54 [ V_53 ] , V_44 + ( V_45 / 20 ) ) )
F_27 ( V_2 ) ;
goto V_46;
}
if ( V_2 -> V_40 . V_55 )
goto V_46;
error = F_22 ( V_41 , V_47 ,
F_23 ( V_53 ) ,
V_2 -> V_49 , V_2 -> V_50 , V_2 ,
( void * ) V_53 , V_51 ) ;
if ( error )
V_39 -> V_52 = - error ;
V_46:
F_24 ( V_39 ) ;
F_28 ( V_2 ) ;
}
static void F_29 ( unsigned long V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
F_26 ( V_2 , V_57 ) ;
}
static void F_30 ( unsigned long V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
F_26 ( V_2 , V_58 ) ;
}
static void F_31 ( unsigned long V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
F_26 ( V_2 , V_59 ) ;
}
static void F_32 ( unsigned long V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
F_26 ( V_2 , V_60 ) ;
}
static void F_33 ( unsigned long V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
F_26 ( V_2 ,
V_61 ) ;
}
static void F_34 ( unsigned long V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
F_26 ( V_2 , V_62 ) ;
}
void F_35 ( unsigned long V_56 )
{
int error = 0 ;
struct V_10 * V_11 = (struct V_10 * ) V_56 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_38 * V_39 = V_2 -> V_40 . V_39 ;
struct V_41 * V_41 = F_16 ( V_39 ) ;
T_4 V_63 , V_64 ;
F_17 ( V_39 ) ;
if ( F_18 ( V_39 ) ) {
F_19 ( L_1 , V_42 ) ;
if ( ! F_20 ( & V_11 -> V_65 , V_44 + ( V_45 / 20 ) ) )
F_21 ( V_11 ) ;
goto V_46;
}
V_63 = V_44 - V_11 -> V_66 ;
V_64 = F_36 ( V_11 ) ;
if ( V_63 < V_64 ) {
V_63 = V_64 - V_63 ;
if ( ! F_20 ( & V_11 -> V_65 , V_44 + V_63 ) )
F_21 ( V_11 ) ;
goto V_46;
}
error = F_22 ( V_41 , V_47 ,
F_23 ( V_67 ) ,
V_2 -> V_49 , V_2 -> V_50 , V_2 ,
V_11 , V_51 ) ;
if ( error )
V_39 -> V_52 = - error ;
V_46:
F_24 ( V_39 ) ;
F_25 ( V_11 ) ;
}
void F_37 ( unsigned long V_56 )
{
struct V_10 * V_11 = (struct V_10 * ) V_56 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_38 * V_39 = V_2 -> V_40 . V_39 ;
struct V_41 * V_41 = F_16 ( V_39 ) ;
F_17 ( V_39 ) ;
if ( F_18 ( V_39 ) ) {
F_19 ( L_1 , V_42 ) ;
if ( ! F_20 ( & V_11 -> V_68 ,
V_44 + ( V_45 / 20 ) ) )
F_27 ( V_2 ) ;
goto V_46;
}
if ( V_2 -> V_40 . V_55 )
goto V_46;
F_22 ( V_41 , V_69 ,
F_38 ( V_70 ) ,
V_2 -> V_49 , V_2 -> V_50 , V_2 , V_11 , V_51 ) ;
V_46:
F_24 ( V_39 ) ;
F_28 ( V_2 ) ;
}
static void F_39 ( unsigned long V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
F_26 ( V_2 , V_28 ) ;
}
static void F_40 ( T_2 * V_14 ,
struct V_1 * V_2 ,
struct V_10 * V_11 ,
int V_71 )
{
struct V_41 * V_41 = F_16 ( V_2 -> V_40 . V_39 ) ;
if ( ! V_71 ) {
V_2 -> V_72 ++ ;
if ( V_11 -> V_49 != V_73 )
V_11 -> V_74 ++ ;
} else if ( V_11 -> V_75 ) {
if ( V_11 -> V_49 != V_76 )
V_2 -> V_72 ++ ;
if ( V_11 -> V_49 != V_73 )
V_11 -> V_74 ++ ;
}
if ( V_41 -> V_77 . V_78 &&
( V_11 -> V_49 == V_79 ) &&
( V_2 -> V_80 < V_11 -> V_81 ) &&
( V_11 -> V_74 > V_2 -> V_80 ) ) {
F_41 ( V_2 , V_11 ,
V_82 ,
0 ) ;
F_42 ( V_11 ) ;
}
if ( V_11 -> V_49 != V_73 &&
( V_11 -> V_74 > V_11 -> V_81 ) ) {
F_19 ( L_3 ,
V_42 , V_2 , & V_11 -> V_83 . V_84 ) ;
F_41 ( V_2 , V_11 ,
V_85 ,
V_86 ) ;
}
if ( ! V_71 || V_11 -> V_75 ) {
V_11 -> V_87 = F_43 ( ( V_11 -> V_87 * 2 ) , V_11 -> V_2 -> V_88 ) ;
F_44 ( V_2 , V_11 ) ;
}
}
static void F_45 ( T_2 * V_14 ,
struct V_1 * V_2 ,
unsigned int error )
{
struct V_89 * V_90 ;
V_90 = F_46 ( V_2 , 0 , V_91 ,
( V_92 ) error , 0 , 0 , NULL ,
V_51 ) ;
if ( V_90 )
F_11 ( V_14 , V_93 ,
F_47 ( V_90 ) ) ;
F_11 ( V_14 , V_94 ,
F_48 ( V_95 ) ) ;
V_2 -> V_96 . error = error ;
F_11 ( V_14 , V_97 , F_49 () ) ;
}
static void F_50 ( T_2 * V_14 ,
struct V_1 * V_2 ,
T_5 V_98 ,
T_6 V_99 ,
struct V_6 * V_7 ,
unsigned int error )
{
struct V_89 * V_90 ;
struct V_6 * abort ;
F_51 ( & V_2 -> V_100 , V_51 ) ;
if ( V_98 == V_101 && V_99 . V_7 == V_102 )
V_90 = F_46 ( V_2 , 0 , V_103 ,
( V_92 ) error , 0 , 0 , V_7 ,
V_51 ) ;
else
V_90 = F_46 ( V_2 , 0 , V_103 ,
( V_92 ) error , 0 , 0 , NULL ,
V_51 ) ;
if ( V_90 )
F_11 ( V_14 , V_93 ,
F_47 ( V_90 ) ) ;
if ( V_2 -> V_72 >= V_2 -> V_104 ) {
abort = F_52 ( V_2 , V_7 ) ;
if ( abort )
F_11 ( V_14 , V_35 ,
F_14 ( abort ) ) ;
}
F_11 ( V_14 , V_94 ,
F_48 ( V_95 ) ) ;
V_2 -> V_96 . error = error ;
F_11 ( V_14 , V_97 , F_49 () ) ;
}
static int F_53 ( T_2 * V_14 ,
struct V_1 * V_2 ,
struct V_6 * V_7 ,
T_7 * V_105 ,
T_8 V_106 )
{
int error ;
if ( ! F_54 ( V_2 , V_7 , F_55 ( V_7 ) , V_105 , V_106 ) )
error = - V_37 ;
else
error = 0 ;
return error ;
}
static void F_56 ( T_2 * V_107 ,
struct V_1 * V_2 )
{
struct V_10 * V_108 ;
F_57 (t, &asoc->peer.transport_addr_list, transports)
F_42 ( V_108 ) ;
}
static void F_58 ( T_2 * V_107 ,
struct V_1 * V_2 )
{
struct V_10 * V_108 ;
F_57 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_59 ( & V_108 -> V_65 ) )
F_25 ( V_108 ) ;
}
}
static void F_60 ( T_2 * V_107 ,
struct V_1 * V_2 )
{
struct V_10 * V_108 ;
F_57 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_59 ( & V_108 -> V_43 ) )
F_25 ( V_108 ) ;
}
}
static void F_61 ( T_2 * V_107 ,
struct V_1 * V_2 ,
struct V_10 * V_108 ,
struct V_6 * V_7 )
{
T_9 * V_109 ;
int V_110 = 0 ;
V_108 -> V_74 = 0 ;
if ( V_108 -> V_2 -> V_49 < V_111 )
V_108 -> V_2 -> V_72 = 0 ;
V_108 -> V_75 = 0 ;
if ( ( V_108 -> V_49 == V_73 ) || ( V_108 -> V_49 == V_76 ) ) {
V_110 = 1 ;
F_41 ( V_2 , V_108 , V_112 ,
V_113 ) ;
}
if ( V_108 -> V_49 == V_114 )
F_41 ( V_2 , V_108 , V_112 ,
V_113 ) ;
if ( V_108 -> V_115 )
F_62 ( V_108 -> V_115 ) ;
if ( V_108 -> V_116 == 0 )
V_108 -> V_116 = 1 ;
V_109 = ( T_9 * ) V_7 -> V_117 -> V_56 ;
F_63 ( V_108 , ( V_44 - V_109 -> V_118 ) ) ;
F_42 ( V_108 ) ;
if ( V_110 && V_2 -> V_19 . V_119 == 1 )
F_64 ( V_108 ) ;
}
static int F_65 ( T_2 * V_107 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_120 = 0 ;
if ( F_66 ( & V_2 -> V_96 , V_7 ) ) {
struct V_41 * V_41 = F_16 ( V_2 -> V_40 . V_39 ) ;
V_120 = F_22 ( V_41 , V_69 ,
F_38 ( V_121 ) ,
V_2 -> V_49 , V_2 -> V_50 , V_2 , NULL ,
V_51 ) ;
}
return V_120 ;
}
static void F_67 ( T_2 * V_107 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_10 * V_108 ;
if ( V_7 -> V_11 )
V_108 = V_7 -> V_11 ;
else {
V_108 = F_68 ( V_2 ,
V_2 -> V_122 ) ;
V_7 -> V_11 = V_108 ;
}
V_2 -> V_122 = V_108 ;
V_2 -> V_27 [ V_59 ] = V_108 -> V_87 ;
}
static void F_69 ( T_2 * V_107 ,
struct V_1 * V_2 ,
T_10 V_49 )
{
struct V_38 * V_39 = V_2 -> V_40 . V_39 ;
V_2 -> V_49 = V_49 ;
F_19 ( L_4 , V_42 , V_2 , V_123 [ V_49 ] ) ;
if ( F_70 ( V_39 , V_124 ) ) {
if ( F_71 ( V_2 , V_125 ) && F_72 ( V_39 , V_126 ) )
V_39 -> V_127 = V_128 ;
if ( F_71 ( V_2 , V_129 ) &&
F_72 ( V_39 , V_125 ) ) {
V_39 -> V_127 = V_130 ;
V_39 -> V_131 |= V_132 ;
}
}
if ( F_71 ( V_2 , V_133 ) ) {
V_2 -> V_27 [ V_58 ] =
V_2 -> V_134 ;
V_2 -> V_27 [ V_57 ] =
V_2 -> V_134 ;
}
if ( F_71 ( V_2 , V_125 ) ||
F_71 ( V_2 , V_126 ) ||
F_71 ( V_2 , V_129 ) ) {
if ( F_73 ( & V_2 -> V_135 ) )
F_74 ( & V_2 -> V_135 ) ;
if ( ! F_70 ( V_39 , V_136 ) )
V_39 -> V_137 ( V_39 ) ;
}
}
static void F_75 ( T_2 * V_107 ,
struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 . V_39 ;
if ( F_70 ( V_39 , V_124 ) && F_72 ( V_39 , V_138 ) &&
( ! V_2 -> V_139 ) && ( V_39 -> V_131 != V_140 ) )
return;
F_76 ( V_2 ) ;
}
static void F_77 ( T_2 * V_107 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_10 * V_108 ;
V_108 = F_68 ( V_2 , V_7 -> V_11 ) ;
V_2 -> V_27 [ V_60 ] = V_108 -> V_87 ;
V_7 -> V_11 = V_108 ;
}
static void F_78 ( T_2 * V_107 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_141 * V_142 ;
struct V_89 * V_143 ;
while ( V_7 -> V_144 > V_7 -> V_117 -> V_56 ) {
V_142 = (struct V_141 * ) ( V_7 -> V_117 -> V_56 ) ;
V_143 = F_79 ( V_2 , V_7 , 0 ,
V_51 ) ;
if ( ! V_143 )
return;
F_80 ( & V_2 -> V_100 , V_143 ) ;
switch ( V_142 -> V_145 ) {
case V_146 :
{
T_11 * V_147 ;
V_147 = ( T_11 * ) V_142 -> V_148 ;
switch ( V_147 -> type ) {
case V_149 :
if ( V_2 -> V_19 . V_150 == 0 )
break;
V_2 -> V_19 . V_150 = 0 ;
F_11 ( V_107 , V_36 ,
F_12 ( V_60 ) ) ;
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
static void F_81 ( struct V_151 * V_100 ,
struct V_6 * V_7 )
{
struct V_152 * V_153 ;
F_82 (skip, chunk) {
F_83 ( V_100 , F_84 ( V_153 -> V_154 ) , F_84 ( V_153 -> V_155 ) ) ;
}
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_10 * V_108 ;
struct V_156 * V_157 ;
struct V_156 * V_139 ;
F_86 (pos, temp, &asoc->peer.transport_addr_list) {
V_108 = F_87 ( V_157 , struct V_10 , V_158 ) ;
if ( ! F_88 ( & V_108 -> V_83 ,
& V_2 -> V_19 . V_159 ) ) {
F_89 ( V_2 , V_108 ) ;
}
}
}
static void F_90 ( struct V_1 * V_2 , int error )
{
struct V_38 * V_39 = V_2 -> V_40 . V_39 ;
if ( ! F_70 ( V_39 , V_136 ) )
V_39 -> V_52 = error ;
}
static void F_91 ( T_2 * V_14 ,
struct V_1 * V_2 ,
T_12 V_49 )
{
struct V_89 * V_143 ;
V_143 = F_46 ( V_2 , 0 , V_49 , 0 ,
V_2 -> V_160 . V_161 ,
V_2 -> V_160 . V_162 ,
NULL , V_51 ) ;
if ( V_143 )
F_80 ( & V_2 -> V_100 , V_143 ) ;
}
static void F_92 ( T_2 * V_14 ,
struct V_1 * V_2 )
{
struct V_89 * V_143 ;
V_143 = F_93 ( V_2 , V_51 ) ;
if ( V_143 )
F_80 ( & V_2 -> V_100 , V_143 ) ;
}
static void F_94 ( struct V_1 * V_2 ,
T_3 V_163 ,
char * V_164 )
{
struct V_10 * V_108 ;
V_108 = V_2 -> V_165 ;
V_2 -> V_166 ++ ;
if ( V_108 -> V_167 > ( V_2 -> V_168 + 1 ) ) {
V_2 -> V_27 [ V_163 ] *= 2 ;
if ( V_2 -> V_27 [ V_163 ] > V_2 -> V_169 ) {
V_2 -> V_27 [ V_163 ] = V_2 -> V_169 ;
}
V_2 -> V_168 ++ ;
F_19 ( L_5
L_6 , V_42 , V_164 ,
V_2 -> V_166 , V_2 -> V_168 ,
V_2 -> V_27 [ V_163 ] ) ;
}
}
static void F_95 ( struct V_1 * V_2 ,
struct V_170 * V_171 , T_8 V_106 )
{
struct V_6 * V_7 ;
F_57 (chunk, &msg->chunks, frag_list)
F_96 ( & V_2 -> V_96 , V_7 , V_106 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_41 * V_41 = F_16 ( V_2 -> V_40 . V_39 ) ;
if ( ! F_98 ( & V_2 -> V_172 ) ) {
struct V_156 * V_173 = V_2 -> V_172 . V_174 ;
struct V_6 * V_175 = F_87 ( V_173 ,
struct V_6 , V_176 ) ;
F_99 ( V_173 ) ;
F_100 ( V_175 ) ;
if ( F_101 ( V_41 , V_2 , V_175 ) )
F_102 ( V_175 ) ;
else
V_2 -> V_177 = V_175 ;
}
}
int F_22 ( struct V_41 * V_41 , T_5 V_98 , T_6 V_99 ,
T_10 V_49 ,
struct V_178 * V_50 ,
struct V_1 * V_2 ,
void * V_179 ,
T_8 V_106 )
{
T_2 V_14 ;
const T_13 * V_180 ;
T_14 V_181 ;
int error = 0 ;
typedef const char * (F_103)( T_6 );
static F_103 * V_182 [] = {
NULL , V_183 , V_184 , V_185 , V_186 ,
} ;
F_103 * T_15 V_187 ( ( V_188 ) ) = V_182 [ V_98 ] ;
V_180 = F_104 ( V_41 , V_98 , V_49 , V_99 ) ;
F_105 ( & V_14 ) ;
F_106 () ;
V_181 = V_180 -> V_189 ( V_41 , V_50 , V_2 , V_99 , V_179 , & V_14 ) ;
F_107 () ;
error = F_108 ( V_98 , V_99 , V_49 ,
V_50 , & V_2 , V_179 , V_181 ,
& V_14 , V_106 ) ;
F_109 () ;
return error ;
}
static int F_108 ( T_5 V_98 , T_6 V_99 ,
T_10 V_49 ,
struct V_178 * V_50 ,
struct V_1 * * V_2 ,
void * V_179 ,
T_14 V_181 ,
T_2 * V_14 ,
T_8 V_106 )
{
int error ;
if ( 0 != ( error = F_110 ( V_98 , V_99 , V_49 ,
V_50 , * V_2 ,
V_179 , V_181 ,
V_14 , V_106 ) ) )
goto V_190;
switch ( V_181 ) {
case V_191 :
F_19 ( L_7
L_8 , V_42 , V_49 ,
V_98 , V_99 . V_7 ) ;
break;
case V_192 :
error = - V_37 ;
break;
case V_193 :
case V_194 :
* V_2 = NULL ;
break;
case V_195 :
break;
case V_196 :
F_111 ( L_9 ,
V_49 , V_99 . V_7 ) ;
break;
case V_197 :
F_112 ( L_10 ,
V_49 , V_98 , V_99 . V_7 ) ;
break;
case V_198 :
F_113 ( L_11 ,
V_49 , V_98 , V_99 . V_7 ) ;
F_114 () ;
break;
default:
F_113 ( L_12 ,
V_181 , V_49 , V_98 , V_99 . V_7 ) ;
F_114 () ;
break;
}
V_190:
return error ;
}
static int F_110 ( T_5 V_98 ,
T_6 V_99 ,
T_10 V_49 ,
struct V_178 * V_50 ,
struct V_1 * V_2 ,
void * V_179 ,
T_14 V_181 ,
T_2 * V_14 ,
T_8 V_106 )
{
struct V_38 * V_39 = V_50 -> V_40 . V_39 ;
struct V_199 * V_200 = F_115 ( V_39 ) ;
int error = 0 ;
int V_13 ;
T_16 * V_201 ;
struct V_6 * V_202 ;
struct V_6 * V_7 = NULL ;
struct V_203 * V_204 ;
struct V_205 * V_163 ;
unsigned long V_64 ;
struct V_10 * V_108 ;
struct V_206 V_207 ;
int V_208 = 0 ;
if ( V_47 != V_98 )
V_7 = V_179 ;
while ( NULL != ( V_201 = F_116 ( V_14 ) ) ) {
switch ( V_201 -> V_209 ) {
case V_210 :
break;
case V_211 :
if ( V_208 ) {
F_117 ( & V_2 -> V_96 , V_106 ) ;
V_208 = 0 ;
}
V_2 = V_201 -> V_212 . V_2 ;
F_118 ( V_2 -> V_19 . V_213 == NULL ) ;
F_119 ( V_50 , V_2 ) ;
break;
case V_214 :
F_120 ( V_2 , V_201 -> V_212 . V_2 ) ;
break;
case V_215 :
F_121 ( & V_2 -> V_96 ) ;
break;
case V_97 :
if ( V_208 ) {
F_117 ( & V_2 -> V_96 , V_106 ) ;
V_208 = 0 ;
}
F_75 ( V_14 , V_2 ) ;
V_2 = NULL ;
break;
case V_94 :
F_69 ( V_14 , V_2 , V_201 -> V_212 . V_49 ) ;
break;
case V_216 :
error = F_122 ( & V_2 -> V_19 . V_24 ,
V_201 -> V_212 . T_4 , NULL ) ;
break;
case V_217 :
F_123 ( & V_2 -> V_19 . V_24 , V_201 -> V_212 . T_4 ) ;
F_124 ( & V_2 -> V_100 , V_201 -> V_212 . T_4 ) ;
F_51 ( & V_2 -> V_100 , V_51 ) ;
break;
case V_218 :
F_81 ( & V_2 -> V_100 , V_201 -> V_212 . V_7 ) ;
break;
case V_219 :
V_13 = V_201 -> V_212 . V_220 ;
error = F_8 ( V_2 , V_13 , V_14 ) ;
break;
case V_221 :
error = F_65 ( V_14 , V_2 ,
V_201 -> V_212 . V_7 ) ;
break;
case V_222 :
V_202 = F_125 ( V_2 , V_7 , V_51 ,
0 ) ;
if ( ! V_202 )
goto V_34;
F_11 ( V_14 , V_35 ,
F_14 ( V_202 ) ) ;
break;
case V_223 :
error = F_53 ( V_14 , V_2 , V_7 ,
V_201 -> V_212 . V_224 , V_106 ) ;
break;
case V_225 :
V_202 = F_126 ( V_2 , V_7 ) ;
if ( ! V_202 ) {
if ( V_201 -> V_212 . V_7 )
F_102 ( V_201 -> V_212 . V_7 ) ;
goto V_34;
}
F_11 ( V_14 , V_35 ,
F_14 ( V_202 ) ) ;
if ( V_201 -> V_212 . V_7 )
F_11 ( V_14 , V_35 ,
F_14 ( V_201 -> V_212 . V_7 ) ) ;
if ( V_202 -> V_11 ) {
V_202 -> V_11 -> V_167 ++ ;
V_2 -> V_165 = V_202 -> V_11 ;
}
if ( ( V_2 -> V_19 . V_226 !=
V_2 -> V_19 . V_213 ) &&
( V_2 -> V_166 > 0 ) ) {
F_11 ( V_14 ,
V_227 ,
F_49 () ) ;
}
break;
case V_228 :
V_2 -> V_72 = 0 ;
V_202 = F_127 ( V_2 , V_7 ) ;
if ( ! V_202 )
goto V_34;
F_11 ( V_14 , V_35 ,
F_14 ( V_202 ) ) ;
break;
case V_229 :
F_19 ( L_13 ,
V_42 , V_201 -> V_212 . V_7 , & V_2 -> V_100 ) ;
F_128 ( & V_2 -> V_100 , V_201 -> V_212 . V_7 ,
V_51 ) ;
break;
case V_93 :
F_19 ( L_14 ,
V_42 , V_201 -> V_212 . V_230 , & V_2 -> V_100 ) ;
F_80 ( & V_2 -> V_100 , V_201 -> V_212 . V_230 ) ;
break;
case V_35 :
if ( ! V_2 -> V_96 . V_231 ) {
F_129 ( & V_2 -> V_96 ) ;
V_208 = 1 ;
}
F_96 ( & V_2 -> V_96 , V_201 -> V_212 . V_7 , V_106 ) ;
break;
case V_232 :
V_204 = V_201 -> V_212 . V_204 ;
F_130 ( V_204 , V_106 ) ;
F_131 ( V_204 ) ;
break;
case V_233 :
F_132 ( & V_2 -> V_96 , V_201 -> V_212 . V_11 ,
V_234 ) ;
break;
case V_235 :
F_132 ( & V_2 -> V_96 , V_201 -> V_212 . V_11 ,
V_236 ) ;
break;
case V_237 :
F_1 ( V_2 , V_201 -> V_212 . T_4 ) ;
break;
case V_238 :
V_202 = F_2 ( V_2 , V_201 -> V_212 . T_4 ,
V_7 ) ;
if ( V_202 )
F_11 ( V_14 , V_35 ,
F_14 ( V_202 ) ) ;
break;
case V_239 :
F_7 ( V_2 , V_201 -> V_212 . T_4 ) ;
break;
case V_240 :
F_67 ( V_14 , V_2 , V_201 -> V_212 . V_7 ) ;
break;
case V_241 :
V_163 = & V_2 -> V_54 [ V_201 -> V_212 . V_242 ] ;
if ( F_133 ( V_163 ) )
break;
case V_243 :
V_163 = & V_2 -> V_54 [ V_201 -> V_212 . V_242 ] ;
V_64 = V_2 -> V_27 [ V_201 -> V_212 . V_242 ] ;
F_118 ( ! V_64 ) ;
V_163 -> V_244 = V_44 + V_64 ;
F_27 ( V_2 ) ;
F_134 ( V_163 ) ;
break;
case V_30 :
V_163 = & V_2 -> V_54 [ V_201 -> V_212 . V_242 ] ;
V_64 = V_2 -> V_27 [ V_201 -> V_212 . V_242 ] ;
if ( ! F_20 ( V_163 , V_44 + V_64 ) )
F_27 ( V_2 ) ;
break;
case V_36 :
V_163 = & V_2 -> V_54 [ V_201 -> V_212 . V_242 ] ;
if ( F_59 ( V_163 ) )
F_28 ( V_2 ) ;
break;
case V_245 :
V_7 = V_201 -> V_212 . V_7 ;
V_108 = F_68 ( V_2 ,
V_2 -> V_165 ) ;
V_2 -> V_165 = V_108 ;
V_7 -> V_11 = V_108 ;
V_108 -> V_167 ++ ;
F_135 ( V_2 , V_108 ) ;
break;
case V_246 :
F_94 ( V_2 ,
V_58 ,
L_15 ) ;
F_11 ( V_14 , V_30 ,
F_12 ( V_58 ) ) ;
break;
case V_247 :
F_94 ( V_2 ,
V_57 ,
L_16 ) ;
F_57 (t, &asoc->peer.transport_addr_list,
transports) {
F_136 ( & V_2 -> V_96 , V_108 ,
V_234 ) ;
}
F_11 ( V_14 ,
V_30 ,
F_12 ( V_57 ) ) ;
break;
case V_248 :
F_45 ( V_14 , V_2 , V_201 -> V_212 . V_120 ) ;
break;
case V_249 :
F_50 ( V_14 , V_2 , V_98 ,
V_99 , V_7 , V_201 -> V_212 . V_120 ) ;
break;
case V_250 :
V_2 -> V_166 ++ ;
break;
case V_251 :
V_2 -> V_166 = 0 ;
V_2 -> V_168 = 0 ;
F_57 (t, &asoc->peer.transport_addr_list,
transports) {
V_108 -> V_167 = 0 ;
}
break;
case V_252 :
F_137 ( & V_2 -> V_19 . V_24 ,
V_201 -> V_212 . T_4 ) ;
break;
case V_253 :
F_19 ( L_17 , V_42 ) ;
break;
case V_254 :
F_40 ( V_14 , V_2 ,
V_201 -> V_212 . V_11 , 0 ) ;
break;
case V_255 :
V_108 = V_201 -> V_212 . V_11 ;
F_5 ( V_108 , V_256 ) ;
break;
case V_257 :
V_108 = V_201 -> V_212 . V_11 ;
F_40 ( V_14 , V_2 ,
V_108 , 1 ) ;
V_108 -> V_75 = 1 ;
break;
case V_258 :
V_108 = V_201 -> V_212 . V_11 ;
F_61 ( V_14 , V_2 , V_108 , V_7 ) ;
break;
case V_259 :
F_56 ( V_14 , V_2 ) ;
break;
case V_260 :
V_108 = V_201 -> V_212 . V_11 ;
F_42 ( V_108 ) ;
break;
case V_261 :
F_58 ( V_14 , V_2 ) ;
break;
case V_262 :
error = V_201 -> V_212 . error ;
break;
case V_263 :
V_207 . V_264 = V_201 -> V_212 . V_265 ;
V_207 . V_32 = V_2 -> V_19 . V_33 +
V_2 -> V_96 . V_266 ;
V_207 . V_267 = 0 ;
V_207 . V_268 = 0 ;
V_7 -> V_269 . V_270 = & V_207 ;
F_11 ( V_14 , V_221 ,
F_14 ( V_7 ) ) ;
break;
case V_271 :
V_7 -> V_272 = 1 ;
if ( V_2 ) {
F_117 ( & V_2 -> V_96 , V_106 ) ;
V_208 = 0 ;
}
break;
case V_273 :
V_108 = V_201 -> V_212 . V_11 ;
V_108 -> V_116 = 1 ;
break;
case V_274 :
F_138 ( & V_2 -> V_100 , V_51 ) ;
break;
case V_275 :
F_139 ( & V_2 -> V_100 , V_201 -> V_212 . V_7 ,
V_51 ) ;
break;
case V_276 :
F_77 ( V_14 , V_2 , V_201 -> V_212 . V_7 ) ;
break;
case V_277 :
F_78 ( V_14 , V_2 , V_7 ) ;
break;
case V_278 :
V_2 -> V_19 . V_279 . V_280 = 0 ;
break;
case V_281 :
F_85 ( V_2 ) ;
break;
case V_282 :
F_60 ( V_14 , V_2 ) ;
break;
case V_227 :
V_108 = V_2 -> V_19 . V_226 ;
V_2 -> V_19 . V_226 = V_2 -> V_19 . V_213 ;
F_117 ( & V_2 -> V_96 , V_106 ) ;
V_208 = 0 ;
V_2 -> V_19 . V_226 = V_108 ;
break;
case V_283 :
F_90 ( V_2 , V_201 -> V_212 . error ) ;
break;
case V_284 :
F_91 ( V_14 , V_2 ,
V_201 -> V_212 . T_12 ) ;
break;
case V_285 :
F_92 ( V_14 , V_2 ) ;
break;
case V_286 :
error = F_140 ( V_2 ,
V_51 ) ;
break;
case V_287 :
V_2 -> V_19 . V_279 . V_280 = V_201 -> V_212 . T_4 ;
break;
case V_288 :
if ( ! V_2 -> V_96 . V_231 ) {
F_129 ( & V_2 -> V_96 ) ;
V_208 = 1 ;
}
F_95 ( V_2 , V_201 -> V_212 . V_171 , V_106 ) ;
break;
case V_289 :
F_97 ( V_2 ) ;
break;
case V_290 :
F_141 ( V_2 ) ;
break;
case V_291 :
V_2 = V_201 -> V_212 . V_2 ;
break;
default:
F_112 ( L_18 ,
V_201 -> V_209 ) ;
break;
}
if ( error )
break;
}
V_292:
if ( V_2 && V_101 == V_98 && V_7 ) {
if ( V_7 -> V_293 || V_7 -> V_294 )
F_117 ( & V_2 -> V_96 , V_106 ) ;
} else if ( V_208 )
F_117 ( & V_2 -> V_96 , V_106 ) ;
if ( V_200 -> V_295 )
V_200 -> V_295 = 0 ;
return error ;
V_34:
error = - V_37 ;
goto V_292;
}
