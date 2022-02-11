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
struct V_37 * V_38 = V_2 -> V_39 . V_38 ;
struct V_40 * V_40 = F_16 ( V_38 ) ;
F_17 ( V_38 ) ;
if ( F_18 ( V_38 ) ) {
F_19 ( L_1 , V_41 ) ;
if ( ! F_20 ( & V_11 -> V_42 , V_43 + ( V_44 / 20 ) ) )
F_21 ( V_11 ) ;
goto V_45;
}
error = F_22 ( V_40 , V_46 ,
F_23 ( V_47 ) ,
V_2 -> V_48 ,
V_2 -> V_49 , V_2 ,
V_11 , V_50 ) ;
if ( error )
V_38 -> V_51 = - error ;
V_45:
F_24 ( V_38 ) ;
F_25 ( V_11 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
T_3 V_52 )
{
struct V_37 * V_38 = V_2 -> V_39 . V_38 ;
struct V_40 * V_40 = F_16 ( V_38 ) ;
int error = 0 ;
F_17 ( V_38 ) ;
if ( F_18 ( V_38 ) ) {
F_19 ( L_2 , V_41 ,
V_52 ) ;
if ( ! F_20 ( & V_2 -> V_53 [ V_52 ] , V_43 + ( V_44 / 20 ) ) )
F_27 ( V_2 ) ;
goto V_45;
}
if ( V_2 -> V_39 . V_54 )
goto V_45;
error = F_22 ( V_40 , V_46 ,
F_23 ( V_52 ) ,
V_2 -> V_48 , V_2 -> V_49 , V_2 ,
( void * ) V_52 , V_50 ) ;
if ( error )
V_38 -> V_51 = - error ;
V_45:
F_24 ( V_38 ) ;
F_28 ( V_2 ) ;
}
static void F_29 ( unsigned long V_55 )
{
struct V_1 * V_2 = (struct V_1 * ) V_55 ;
F_26 ( V_2 , V_56 ) ;
}
static void F_30 ( unsigned long V_55 )
{
struct V_1 * V_2 = (struct V_1 * ) V_55 ;
F_26 ( V_2 , V_57 ) ;
}
static void F_31 ( unsigned long V_55 )
{
struct V_1 * V_2 = (struct V_1 * ) V_55 ;
F_26 ( V_2 , V_58 ) ;
}
static void F_32 ( unsigned long V_55 )
{
struct V_1 * V_2 = (struct V_1 * ) V_55 ;
F_26 ( V_2 , V_59 ) ;
}
static void F_33 ( unsigned long V_55 )
{
struct V_1 * V_2 = (struct V_1 * ) V_55 ;
F_26 ( V_2 ,
V_60 ) ;
}
static void F_34 ( unsigned long V_55 )
{
struct V_1 * V_2 = (struct V_1 * ) V_55 ;
F_26 ( V_2 , V_61 ) ;
}
void F_35 ( unsigned long V_55 )
{
int error = 0 ;
struct V_10 * V_11 = (struct V_10 * ) V_55 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_37 * V_38 = V_2 -> V_39 . V_38 ;
struct V_40 * V_40 = F_16 ( V_38 ) ;
F_17 ( V_38 ) ;
if ( F_18 ( V_38 ) ) {
F_19 ( L_1 , V_41 ) ;
if ( ! F_20 ( & V_11 -> V_62 , V_43 + ( V_44 / 20 ) ) )
F_21 ( V_11 ) ;
goto V_45;
}
error = F_22 ( V_40 , V_46 ,
F_23 ( V_63 ) ,
V_2 -> V_48 , V_2 -> V_49 , V_2 ,
V_11 , V_50 ) ;
if ( error )
V_38 -> V_51 = - error ;
V_45:
F_24 ( V_38 ) ;
F_25 ( V_11 ) ;
}
void F_36 ( unsigned long V_55 )
{
struct V_10 * V_11 = (struct V_10 * ) V_55 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_37 * V_38 = V_2 -> V_39 . V_38 ;
struct V_40 * V_40 = F_16 ( V_38 ) ;
F_17 ( V_38 ) ;
if ( F_18 ( V_38 ) ) {
F_19 ( L_1 , V_41 ) ;
if ( ! F_20 ( & V_11 -> V_64 ,
V_43 + ( V_44 / 20 ) ) )
F_27 ( V_2 ) ;
goto V_45;
}
if ( V_2 -> V_39 . V_54 )
goto V_45;
F_22 ( V_40 , V_65 ,
F_37 ( V_66 ) ,
V_2 -> V_48 , V_2 -> V_49 , V_2 , V_11 , V_50 ) ;
V_45:
F_24 ( V_38 ) ;
F_28 ( V_2 ) ;
}
static void F_38 ( unsigned long V_55 )
{
struct V_1 * V_2 = (struct V_1 * ) V_55 ;
F_26 ( V_2 , V_28 ) ;
}
static void F_39 ( T_2 * V_14 ,
struct V_1 * V_2 ,
struct V_10 * V_11 ,
int V_67 )
{
struct V_40 * V_40 = F_16 ( V_2 -> V_39 . V_38 ) ;
if ( ! V_67 ) {
V_2 -> V_68 ++ ;
if ( V_11 -> V_48 != V_69 )
V_11 -> V_70 ++ ;
} else if ( V_11 -> V_71 ) {
if ( V_11 -> V_48 != V_72 )
V_2 -> V_68 ++ ;
if ( V_11 -> V_48 != V_69 )
V_11 -> V_70 ++ ;
}
if ( V_40 -> V_73 . V_74 &&
( V_11 -> V_48 == V_75 ) &&
( V_2 -> V_76 < V_11 -> V_77 ) &&
( V_11 -> V_70 > V_2 -> V_76 ) ) {
F_40 ( V_2 , V_11 ,
V_78 ,
0 ) ;
F_41 ( V_14 , V_11 ) ;
}
if ( V_11 -> V_48 != V_69 &&
( V_11 -> V_70 > V_11 -> V_77 ) ) {
F_19 ( L_3 ,
V_41 , V_2 , & V_11 -> V_79 . V_80 ) ;
F_40 ( V_2 , V_11 ,
V_81 ,
V_82 ) ;
}
if ( ! V_67 || V_11 -> V_71 ) {
V_11 -> V_83 = F_42 ( ( V_11 -> V_83 * 2 ) , V_11 -> V_2 -> V_84 ) ;
F_43 ( V_2 , V_11 ) ;
}
}
static void F_44 ( T_2 * V_14 ,
struct V_1 * V_2 ,
unsigned int error )
{
struct V_85 * V_86 ;
V_86 = F_45 ( V_2 , 0 , V_87 ,
( V_88 ) error , 0 , 0 , NULL ,
V_50 ) ;
if ( V_86 )
F_11 ( V_14 , V_89 ,
F_46 ( V_86 ) ) ;
F_11 ( V_14 , V_90 ,
F_47 ( V_91 ) ) ;
V_2 -> V_92 . error = error ;
F_11 ( V_14 , V_93 , F_48 () ) ;
}
static void F_49 ( T_2 * V_14 ,
struct V_1 * V_2 ,
T_4 V_94 ,
T_5 V_95 ,
struct V_6 * V_7 ,
unsigned int error )
{
struct V_85 * V_86 ;
struct V_6 * abort ;
F_50 ( & V_2 -> V_96 , V_50 ) ;
if ( V_94 == V_97 && V_95 . V_7 == V_98 )
V_86 = F_45 ( V_2 , 0 , V_99 ,
( V_88 ) error , 0 , 0 , V_7 ,
V_50 ) ;
else
V_86 = F_45 ( V_2 , 0 , V_99 ,
( V_88 ) error , 0 , 0 , NULL ,
V_50 ) ;
if ( V_86 )
F_11 ( V_14 , V_89 ,
F_46 ( V_86 ) ) ;
if ( V_2 -> V_68 >= V_2 -> V_100 ) {
abort = F_51 ( V_2 , V_7 ) ;
if ( abort )
F_11 ( V_14 , V_34 ,
F_14 ( abort ) ) ;
}
F_11 ( V_14 , V_90 ,
F_47 ( V_91 ) ) ;
V_2 -> V_92 . error = error ;
F_11 ( V_14 , V_93 , F_48 () ) ;
}
static int F_52 ( T_2 * V_14 ,
struct V_1 * V_2 ,
struct V_6 * V_7 ,
T_6 * V_101 ,
T_7 V_102 )
{
int error ;
if ( ! F_53 ( V_2 , V_7 , F_54 ( V_7 ) , V_101 , V_102 ) )
error = - V_36 ;
else
error = 0 ;
return error ;
}
static void F_55 ( T_2 * V_103 ,
struct V_1 * V_2 )
{
struct V_10 * V_104 ;
F_56 (t, &asoc->peer.transport_addr_list, transports) {
if ( ! F_20 ( & V_104 -> V_62 , F_57 ( V_104 ) ) )
F_21 ( V_104 ) ;
}
}
static void F_58 ( T_2 * V_103 ,
struct V_1 * V_2 )
{
struct V_10 * V_104 ;
F_56 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_59 ( & V_104 -> V_62 ) )
F_25 ( V_104 ) ;
}
}
static void F_60 ( T_2 * V_103 ,
struct V_1 * V_2 )
{
struct V_10 * V_104 ;
F_56 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_59 ( & V_104 -> V_42 ) )
F_25 ( V_104 ) ;
}
}
static void F_41 ( T_2 * V_103 ,
struct V_10 * V_104 )
{
if ( ! F_20 ( & V_104 -> V_62 , F_57 ( V_104 ) ) )
F_21 ( V_104 ) ;
}
static void F_61 ( T_2 * V_103 ,
struct V_1 * V_2 ,
struct V_10 * V_104 ,
struct V_6 * V_7 )
{
T_8 * V_105 ;
int V_106 = 0 ;
V_104 -> V_70 = 0 ;
if ( V_104 -> V_2 -> V_48 < V_107 )
V_104 -> V_2 -> V_68 = 0 ;
V_104 -> V_71 = 0 ;
if ( ( V_104 -> V_48 == V_69 ) || ( V_104 -> V_48 == V_72 ) ) {
V_106 = 1 ;
F_40 ( V_2 , V_104 , V_108 ,
V_109 ) ;
}
if ( V_104 -> V_48 == V_110 )
F_40 ( V_2 , V_104 , V_108 ,
V_109 ) ;
if ( V_104 -> V_111 )
F_62 ( V_104 -> V_111 ) ;
if ( V_104 -> V_112 == 0 )
V_104 -> V_112 = 1 ;
V_105 = ( T_8 * ) V_7 -> V_113 -> V_55 ;
F_63 ( V_104 , ( V_43 - V_105 -> V_114 ) ) ;
if ( ! F_20 ( & V_104 -> V_62 , F_57 ( V_104 ) ) )
F_21 ( V_104 ) ;
if ( V_106 && V_2 -> V_19 . V_115 == 1 )
F_64 ( V_104 ) ;
}
static int F_65 ( T_2 * V_103 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_116 = 0 ;
if ( F_66 ( & V_2 -> V_92 , V_7 ) ) {
struct V_40 * V_40 = F_16 ( V_2 -> V_39 . V_38 ) ;
V_116 = F_22 ( V_40 , V_65 ,
F_37 ( V_117 ) ,
V_2 -> V_48 , V_2 -> V_49 , V_2 , NULL ,
V_50 ) ;
}
return V_116 ;
}
static void F_67 ( T_2 * V_103 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_10 * V_104 ;
if ( V_7 -> V_11 )
V_104 = V_7 -> V_11 ;
else {
V_104 = F_68 ( V_2 ,
V_2 -> V_118 ) ;
V_7 -> V_11 = V_104 ;
}
V_2 -> V_118 = V_104 ;
V_2 -> V_27 [ V_58 ] = V_104 -> V_83 ;
}
static void F_69 ( T_2 * V_103 ,
struct V_1 * V_2 ,
T_9 V_48 )
{
struct V_37 * V_38 = V_2 -> V_39 . V_38 ;
V_2 -> V_48 = V_48 ;
F_19 ( L_4 , V_41 , V_2 , V_119 [ V_48 ] ) ;
if ( F_70 ( V_38 , V_120 ) ) {
if ( F_71 ( V_2 , V_121 ) && F_72 ( V_38 , V_122 ) )
V_38 -> V_123 = V_124 ;
if ( F_71 ( V_2 , V_125 ) &&
F_72 ( V_38 , V_121 ) )
V_38 -> V_126 |= V_127 ;
}
if ( F_71 ( V_2 , V_128 ) ) {
V_2 -> V_27 [ V_57 ] =
V_2 -> V_129 ;
V_2 -> V_27 [ V_56 ] =
V_2 -> V_129 ;
}
if ( F_71 ( V_2 , V_121 ) ||
F_71 ( V_2 , V_122 ) ||
F_71 ( V_2 , V_125 ) ) {
if ( F_73 ( & V_2 -> V_130 ) )
F_74 ( & V_2 -> V_130 ) ;
if ( ! F_70 ( V_38 , V_131 ) )
V_38 -> V_132 ( V_38 ) ;
}
}
static void F_75 ( T_2 * V_103 ,
struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_39 . V_38 ;
if ( F_70 ( V_38 , V_120 ) && F_72 ( V_38 , V_133 ) &&
( ! V_2 -> V_134 ) && ( V_38 -> V_126 != V_135 ) )
return;
F_76 ( V_2 ) ;
}
static void F_77 ( T_2 * V_103 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_10 * V_104 ;
V_104 = F_68 ( V_2 , V_7 -> V_11 ) ;
V_2 -> V_27 [ V_59 ] = V_104 -> V_83 ;
V_7 -> V_11 = V_104 ;
}
static void F_78 ( T_2 * V_103 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_136 * V_137 ;
struct V_85 * V_138 ;
while ( V_7 -> V_139 > V_7 -> V_113 -> V_55 ) {
V_137 = (struct V_136 * ) ( V_7 -> V_113 -> V_55 ) ;
V_138 = F_79 ( V_2 , V_7 , 0 ,
V_50 ) ;
if ( ! V_138 )
return;
F_80 ( & V_2 -> V_96 , V_138 ) ;
switch ( V_137 -> V_140 ) {
case V_141 :
{
T_10 * V_142 ;
V_142 = ( T_10 * ) V_137 -> V_143 ;
switch ( V_142 -> type ) {
case V_144 :
if ( V_2 -> V_19 . V_145 == 0 )
break;
V_2 -> V_19 . V_145 = 0 ;
F_11 ( V_103 , V_35 ,
F_12 ( V_59 ) ) ;
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
static void F_81 ( struct V_146 * V_96 ,
struct V_6 * V_7 )
{
struct V_147 * V_148 ;
F_82 (skip, chunk) {
F_83 ( V_96 , F_84 ( V_148 -> V_149 ) , F_84 ( V_148 -> V_150 ) ) ;
}
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_10 * V_104 ;
struct V_151 * V_152 ;
struct V_151 * V_134 ;
F_86 (pos, temp, &asoc->peer.transport_addr_list) {
V_104 = F_87 ( V_152 , struct V_10 , V_153 ) ;
if ( ! F_88 ( & V_104 -> V_79 ,
& V_2 -> V_19 . V_154 ) ) {
F_89 ( V_2 , V_104 ) ;
}
}
}
static void F_90 ( struct V_1 * V_2 , int error )
{
struct V_37 * V_38 = V_2 -> V_39 . V_38 ;
if ( ! F_70 ( V_38 , V_131 ) )
V_38 -> V_51 = error ;
}
static void F_91 ( T_2 * V_14 ,
struct V_1 * V_2 ,
T_11 V_48 )
{
struct V_85 * V_138 ;
V_138 = F_45 ( V_2 , 0 , V_48 , 0 ,
V_2 -> V_155 . V_156 ,
V_2 -> V_155 . V_157 ,
NULL , V_50 ) ;
if ( V_138 )
F_80 ( & V_2 -> V_96 , V_138 ) ;
}
static void F_92 ( T_2 * V_14 ,
struct V_1 * V_2 )
{
struct V_85 * V_138 ;
V_138 = F_93 ( V_2 , V_50 ) ;
if ( V_138 )
F_80 ( & V_2 -> V_96 , V_138 ) ;
}
static void F_94 ( struct V_1 * V_2 ,
T_3 V_158 ,
char * V_159 )
{
struct V_10 * V_104 ;
V_104 = V_2 -> V_160 ;
V_2 -> V_161 ++ ;
if ( V_104 -> V_162 > ( V_2 -> V_163 + 1 ) ) {
V_2 -> V_27 [ V_158 ] *= 2 ;
if ( V_2 -> V_27 [ V_158 ] > V_2 -> V_164 ) {
V_2 -> V_27 [ V_158 ] = V_2 -> V_164 ;
}
V_2 -> V_163 ++ ;
F_19 ( L_5
L_6 , V_41 , V_159 ,
V_2 -> V_161 , V_2 -> V_163 ,
V_2 -> V_27 [ V_158 ] ) ;
}
}
static int F_95 ( struct V_1 * V_2 ,
struct V_165 * V_166 )
{
struct V_6 * V_7 ;
int error = 0 ;
F_56 (chunk, &msg->chunks, frag_list) {
error = F_96 ( & V_2 -> V_92 , V_7 ) ;
if ( error )
break;
}
return error ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_40 * V_40 = F_16 ( V_2 -> V_39 . V_38 ) ;
if ( ! F_98 ( & V_2 -> V_167 ) ) {
struct V_151 * V_168 = V_2 -> V_167 . V_169 ;
struct V_6 * V_170 = F_87 ( V_168 ,
struct V_6 , V_171 ) ;
F_99 ( V_168 ) ;
F_100 ( V_170 ) ;
if ( F_101 ( V_40 , V_2 , V_170 ) )
F_102 ( V_170 ) ;
else
V_2 -> V_172 = V_170 ;
}
}
int F_22 ( struct V_40 * V_40 , T_4 V_94 , T_5 V_95 ,
T_9 V_48 ,
struct V_173 * V_49 ,
struct V_1 * V_2 ,
void * V_174 ,
T_7 V_102 )
{
T_2 V_14 ;
const T_12 * V_175 ;
T_13 V_176 ;
int error = 0 ;
typedef const char * (F_103)( T_5 );
static F_103 * V_177 [] = {
NULL , V_178 , V_179 , V_180 , V_181 ,
} ;
F_103 * T_14 V_182 ( ( V_183 ) ) = V_177 [ V_94 ] ;
V_175 = F_104 ( V_40 , V_94 , V_48 , V_95 ) ;
F_105 ( & V_14 ) ;
F_106 () ;
V_176 = V_175 -> V_184 ( V_40 , V_49 , V_2 , V_95 , V_174 , & V_14 ) ;
F_107 () ;
error = F_108 ( V_94 , V_95 , V_48 ,
V_49 , & V_2 , V_174 , V_176 ,
& V_14 , V_102 ) ;
F_109 () ;
return error ;
}
static int F_108 ( T_4 V_94 , T_5 V_95 ,
T_9 V_48 ,
struct V_173 * V_49 ,
struct V_1 * * V_2 ,
void * V_174 ,
T_13 V_176 ,
T_2 * V_14 ,
T_7 V_102 )
{
int error ;
if ( 0 != ( error = F_110 ( V_94 , V_95 , V_48 ,
V_49 , * V_2 ,
V_174 , V_176 ,
V_14 , V_102 ) ) )
goto V_185;
switch ( V_176 ) {
case V_186 :
F_19 ( L_7
L_8 , V_41 , V_48 ,
V_94 , V_95 . V_7 ) ;
break;
case V_187 :
error = - V_36 ;
break;
case V_188 :
case V_189 :
* V_2 = NULL ;
break;
case V_190 :
break;
case V_191 :
F_111 ( L_9 ,
V_48 , V_95 . V_7 ) ;
break;
case V_192 :
F_112 ( L_10 ,
V_48 , V_94 , V_95 . V_7 ) ;
break;
case V_193 :
F_113 ( L_11 ,
V_48 , V_94 , V_95 . V_7 ) ;
F_114 () ;
break;
default:
F_113 ( L_12 ,
V_176 , V_48 , V_94 , V_95 . V_7 ) ;
F_114 () ;
break;
}
V_185:
return error ;
}
static int F_110 ( T_4 V_94 ,
T_5 V_95 ,
T_9 V_48 ,
struct V_173 * V_49 ,
struct V_1 * V_2 ,
void * V_174 ,
T_13 V_176 ,
T_2 * V_14 ,
T_7 V_102 )
{
int error = 0 ;
int V_13 ;
T_15 * V_194 ;
struct V_6 * V_195 ;
struct V_6 * V_7 = NULL ;
struct V_196 * V_197 ;
struct V_198 * V_158 ;
unsigned long V_199 ;
struct V_10 * V_104 ;
struct V_200 V_201 ;
int V_202 = 0 ;
if ( V_46 != V_94 )
V_7 = V_174 ;
while ( NULL != ( V_194 = F_115 ( V_14 ) ) ) {
switch ( V_194 -> V_203 ) {
case V_204 :
break;
case V_205 :
if ( V_202 ) {
F_116 ( & V_2 -> V_92 ) ;
V_202 = 0 ;
}
V_2 = V_194 -> V_206 . V_2 ;
F_117 ( V_2 -> V_19 . V_207 == NULL ) ;
F_118 ( V_49 , V_2 ) ;
break;
case V_208 :
F_119 ( V_2 , V_194 -> V_206 . V_2 ) ;
break;
case V_209 :
F_120 ( & V_2 -> V_92 ) ;
break;
case V_93 :
if ( V_202 ) {
F_116 ( & V_2 -> V_92 ) ;
V_202 = 0 ;
}
F_75 ( V_14 , V_2 ) ;
V_2 = NULL ;
break;
case V_90 :
F_69 ( V_14 , V_2 , V_194 -> V_206 . V_48 ) ;
break;
case V_210 :
error = F_121 ( & V_2 -> V_19 . V_24 ,
V_194 -> V_206 . V_211 , NULL ) ;
break;
case V_212 :
F_122 ( & V_2 -> V_19 . V_24 , V_194 -> V_206 . V_211 ) ;
F_123 ( & V_2 -> V_96 , V_194 -> V_206 . V_211 ) ;
F_50 ( & V_2 -> V_96 , V_50 ) ;
break;
case V_213 :
F_81 ( & V_2 -> V_96 , V_194 -> V_206 . V_7 ) ;
break;
case V_214 :
V_13 = V_194 -> V_206 . V_215 ;
error = F_8 ( V_2 , V_13 , V_14 ) ;
break;
case V_216 :
error = F_65 ( V_14 , V_2 ,
V_194 -> V_206 . V_7 ) ;
break;
case V_217 :
V_195 = F_124 ( V_2 , V_7 , V_50 ,
0 ) ;
if ( ! V_195 )
goto V_33;
F_11 ( V_14 , V_34 ,
F_14 ( V_195 ) ) ;
break;
case V_218 :
error = F_52 ( V_14 , V_2 , V_7 ,
V_194 -> V_206 . V_219 , V_102 ) ;
break;
case V_220 :
V_195 = F_125 ( V_2 , V_7 ) ;
if ( ! V_195 ) {
if ( V_194 -> V_206 . V_7 )
F_102 ( V_194 -> V_206 . V_7 ) ;
goto V_33;
}
F_11 ( V_14 , V_34 ,
F_14 ( V_195 ) ) ;
if ( V_194 -> V_206 . V_7 )
F_11 ( V_14 , V_34 ,
F_14 ( V_194 -> V_206 . V_7 ) ) ;
if ( V_195 -> V_11 ) {
V_195 -> V_11 -> V_162 ++ ;
V_2 -> V_160 = V_195 -> V_11 ;
}
if ( ( V_2 -> V_19 . V_221 !=
V_2 -> V_19 . V_207 ) &&
( V_2 -> V_161 > 0 ) ) {
F_11 ( V_14 ,
V_222 ,
F_48 () ) ;
}
break;
case V_223 :
V_2 -> V_68 = 0 ;
V_195 = F_126 ( V_2 , V_7 ) ;
if ( ! V_195 )
goto V_33;
F_11 ( V_14 , V_34 ,
F_14 ( V_195 ) ) ;
break;
case V_224 :
F_19 ( L_13 ,
V_41 , V_194 -> V_206 . V_7 , & V_2 -> V_96 ) ;
F_127 ( & V_2 -> V_96 , V_194 -> V_206 . V_7 ,
V_50 ) ;
break;
case V_89 :
F_19 ( L_14 ,
V_41 , V_194 -> V_206 . V_225 , & V_2 -> V_96 ) ;
F_80 ( & V_2 -> V_96 , V_194 -> V_206 . V_225 ) ;
break;
case V_34 :
if ( ! V_2 -> V_92 . V_226 ) {
F_128 ( & V_2 -> V_92 ) ;
V_202 = 1 ;
}
error = F_96 ( & V_2 -> V_92 , V_194 -> V_206 . V_7 ) ;
break;
case V_227 :
V_197 = V_194 -> V_206 . V_197 ;
F_129 ( V_197 ) ;
F_130 ( V_197 ) ;
break;
case V_228 :
F_131 ( & V_2 -> V_92 , V_194 -> V_206 . V_11 ,
V_229 ) ;
break;
case V_230 :
F_131 ( & V_2 -> V_92 , V_194 -> V_206 . V_11 ,
V_231 ) ;
break;
case V_232 :
F_1 ( V_2 , V_194 -> V_206 . V_211 ) ;
break;
case V_233 :
V_195 = F_2 ( V_2 , V_194 -> V_206 . V_211 ,
V_7 ) ;
if ( V_195 )
F_11 ( V_14 , V_34 ,
F_14 ( V_195 ) ) ;
break;
case V_234 :
F_7 ( V_2 , V_194 -> V_206 . V_211 ) ;
break;
case V_235 :
F_67 ( V_14 , V_2 , V_194 -> V_206 . V_7 ) ;
break;
case V_236 :
V_158 = & V_2 -> V_53 [ V_194 -> V_206 . V_237 ] ;
if ( F_132 ( V_158 ) )
break;
case V_238 :
V_158 = & V_2 -> V_53 [ V_194 -> V_206 . V_237 ] ;
V_199 = V_2 -> V_27 [ V_194 -> V_206 . V_237 ] ;
F_117 ( ! V_199 ) ;
V_158 -> V_239 = V_43 + V_199 ;
F_27 ( V_2 ) ;
F_133 ( V_158 ) ;
break;
case V_30 :
V_158 = & V_2 -> V_53 [ V_194 -> V_206 . V_237 ] ;
V_199 = V_2 -> V_27 [ V_194 -> V_206 . V_237 ] ;
if ( ! F_20 ( V_158 , V_43 + V_199 ) )
F_27 ( V_2 ) ;
break;
case V_35 :
V_158 = & V_2 -> V_53 [ V_194 -> V_206 . V_237 ] ;
if ( F_59 ( V_158 ) )
F_28 ( V_2 ) ;
break;
case V_240 :
V_7 = V_194 -> V_206 . V_7 ;
V_104 = F_68 ( V_2 ,
V_2 -> V_160 ) ;
V_2 -> V_160 = V_104 ;
V_7 -> V_11 = V_104 ;
V_104 -> V_162 ++ ;
F_134 ( V_2 , V_104 ) ;
break;
case V_241 :
F_94 ( V_2 ,
V_57 ,
L_15 ) ;
F_11 ( V_14 , V_30 ,
F_12 ( V_57 ) ) ;
break;
case V_242 :
F_94 ( V_2 ,
V_56 ,
L_16 ) ;
F_56 (t, &asoc->peer.transport_addr_list,
transports) {
F_135 ( & V_2 -> V_92 , V_104 ,
V_229 ) ;
}
F_11 ( V_14 ,
V_30 ,
F_12 ( V_56 ) ) ;
break;
case V_243 :
F_44 ( V_14 , V_2 , V_194 -> V_206 . V_116 ) ;
break;
case V_244 :
F_49 ( V_14 , V_2 , V_94 ,
V_95 , V_7 , V_194 -> V_206 . V_116 ) ;
break;
case V_245 :
V_2 -> V_161 ++ ;
break;
case V_246 :
V_2 -> V_161 = 0 ;
V_2 -> V_163 = 0 ;
F_56 (t, &asoc->peer.transport_addr_list,
transports) {
V_104 -> V_162 = 0 ;
}
break;
case V_247 :
F_136 ( & V_2 -> V_19 . V_24 ,
V_194 -> V_206 . V_211 ) ;
break;
case V_248 :
F_19 ( L_17 , V_41 ) ;
break;
case V_249 :
F_39 ( V_14 , V_2 ,
V_194 -> V_206 . V_11 , 0 ) ;
break;
case V_250 :
V_104 = V_194 -> V_206 . V_11 ;
F_5 ( V_104 , V_251 ) ;
break;
case V_252 :
V_104 = V_194 -> V_206 . V_11 ;
F_39 ( V_14 , V_2 ,
V_104 , 1 ) ;
V_104 -> V_71 = 1 ;
break;
case V_253 :
V_104 = V_194 -> V_206 . V_11 ;
F_61 ( V_14 , V_2 , V_104 , V_7 ) ;
break;
case V_254 :
F_55 ( V_14 , V_2 ) ;
break;
case V_255 :
V_104 = V_194 -> V_206 . V_11 ;
F_41 ( V_14 , V_104 ) ;
break;
case V_256 :
F_58 ( V_14 , V_2 ) ;
break;
case V_257 :
error = V_194 -> V_206 . error ;
break;
case V_258 :
V_201 . V_259 = V_194 -> V_206 . V_260 ;
V_201 . V_31 = V_2 -> V_19 . V_32 +
V_2 -> V_92 . V_261 ;
V_201 . V_262 = 0 ;
V_201 . V_263 = 0 ;
V_7 -> V_264 . V_265 = & V_201 ;
F_11 ( V_14 , V_216 ,
F_14 ( V_7 ) ) ;
break;
case V_266 :
V_7 -> V_267 = 1 ;
if ( V_2 ) {
F_116 ( & V_2 -> V_92 ) ;
V_202 = 0 ;
}
break;
case V_268 :
V_104 = V_194 -> V_206 . V_11 ;
V_104 -> V_112 = 1 ;
break;
case V_269 :
F_137 ( & V_2 -> V_96 , V_50 ) ;
break;
case V_270 :
F_138 ( & V_2 -> V_96 , V_194 -> V_206 . V_7 ,
V_50 ) ;
break;
case V_271 :
F_77 ( V_14 , V_2 , V_194 -> V_206 . V_7 ) ;
break;
case V_272 :
F_78 ( V_14 , V_2 , V_7 ) ;
break;
case V_273 :
V_2 -> V_19 . V_274 . V_275 = 0 ;
break;
case V_276 :
F_85 ( V_2 ) ;
break;
case V_277 :
F_60 ( V_14 , V_2 ) ;
break;
case V_222 :
V_104 = V_2 -> V_19 . V_221 ;
V_2 -> V_19 . V_221 = V_2 -> V_19 . V_207 ;
error = F_116 ( & V_2 -> V_92 ) ;
V_202 = 0 ;
V_2 -> V_19 . V_221 = V_104 ;
break;
case V_278 :
F_90 ( V_2 , V_194 -> V_206 . error ) ;
break;
case V_279 :
F_91 ( V_14 , V_2 ,
V_194 -> V_206 . T_11 ) ;
break;
case V_280 :
F_92 ( V_14 , V_2 ) ;
break;
case V_281 :
error = F_139 ( V_2 ,
V_50 ) ;
break;
case V_282 :
V_2 -> V_19 . V_274 . V_275 = V_194 -> V_206 . V_211 ;
break;
case V_283 :
if ( ! V_2 -> V_92 . V_226 ) {
F_128 ( & V_2 -> V_92 ) ;
V_202 = 1 ;
}
error = F_95 ( V_2 , V_194 -> V_206 . V_166 ) ;
break;
case V_284 :
F_97 ( V_2 ) ;
break;
case V_285 :
F_140 ( V_2 ) ;
break;
case V_286 :
V_2 = V_194 -> V_206 . V_2 ;
break;
default:
F_112 ( L_18 ,
V_194 -> V_203 ) ;
break;
}
if ( error )
break;
}
V_287:
if ( V_2 && V_97 == V_94 && V_7 ) {
if ( V_7 -> V_288 || V_7 -> V_289 )
error = F_116 ( & V_2 -> V_92 ) ;
} else if ( V_202 )
error = F_116 ( & V_2 -> V_92 ) ;
return error ;
V_33:
error = - V_36 ;
goto V_287;
}
