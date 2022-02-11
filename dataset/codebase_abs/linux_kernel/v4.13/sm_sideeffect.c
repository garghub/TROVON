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
void F_39 ( unsigned long V_56 )
{
struct V_10 * V_11 = (struct V_10 * ) V_56 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_38 * V_39 = V_2 -> V_40 . V_39 ;
struct V_41 * V_41 = F_16 ( V_39 ) ;
int error = 0 ;
F_17 ( V_39 ) ;
if ( F_18 ( V_39 ) ) {
F_19 ( L_1 , V_42 ) ;
if ( ! F_20 ( & V_11 -> V_71 , V_44 + ( V_45 / 20 ) ) )
F_21 ( V_11 ) ;
goto V_46;
}
error = F_22 ( V_41 , V_47 ,
F_23 ( V_72 ) ,
V_2 -> V_49 , V_2 -> V_50 , V_2 ,
V_11 , V_51 ) ;
if ( error )
V_39 -> V_52 = - error ;
V_46:
F_24 ( V_39 ) ;
F_25 ( V_11 ) ;
}
static void F_40 ( unsigned long V_56 )
{
struct V_1 * V_2 = (struct V_1 * ) V_56 ;
F_26 ( V_2 , V_28 ) ;
}
static void F_41 ( T_2 * V_14 ,
struct V_1 * V_2 ,
struct V_10 * V_11 ,
int V_73 )
{
struct V_41 * V_41 = F_16 ( V_2 -> V_40 . V_39 ) ;
if ( ! V_73 ) {
V_2 -> V_74 ++ ;
if ( V_11 -> V_49 != V_75 )
V_11 -> V_76 ++ ;
} else if ( V_11 -> V_77 ) {
if ( V_11 -> V_49 != V_78 )
V_2 -> V_74 ++ ;
if ( V_11 -> V_49 != V_75 )
V_11 -> V_76 ++ ;
}
if ( V_41 -> V_79 . V_80 &&
( V_11 -> V_49 == V_81 ) &&
( V_2 -> V_82 < V_11 -> V_83 ) &&
( V_11 -> V_76 > V_2 -> V_82 ) ) {
F_42 ( V_2 , V_11 ,
V_84 ,
0 ) ;
F_43 ( V_11 ) ;
}
if ( V_11 -> V_49 != V_75 &&
( V_11 -> V_76 > V_11 -> V_83 ) ) {
F_19 ( L_3 ,
V_42 , V_2 , & V_11 -> V_85 . V_86 ) ;
F_42 ( V_2 , V_11 ,
V_87 ,
V_88 ) ;
}
if ( ! V_73 || V_11 -> V_77 ) {
V_11 -> V_89 = F_44 ( ( V_11 -> V_89 * 2 ) , V_11 -> V_2 -> V_90 ) ;
F_45 ( V_2 , V_11 ) ;
}
}
static void F_46 ( T_2 * V_14 ,
struct V_1 * V_2 ,
unsigned int error )
{
struct V_91 * V_92 ;
V_92 = F_47 ( V_2 , 0 , V_93 ,
( V_94 ) error , 0 , 0 , NULL ,
V_51 ) ;
if ( V_92 )
F_11 ( V_14 , V_95 ,
F_48 ( V_92 ) ) ;
F_11 ( V_14 , V_96 ,
F_49 ( V_97 ) ) ;
V_2 -> V_98 . error = error ;
F_11 ( V_14 , V_99 , F_50 () ) ;
}
static void F_51 ( T_2 * V_14 ,
struct V_1 * V_2 ,
T_5 V_100 ,
T_6 V_101 ,
struct V_6 * V_7 ,
unsigned int error )
{
struct V_91 * V_92 ;
struct V_6 * abort ;
F_52 ( & V_2 -> V_102 , V_51 ) ;
if ( V_100 == V_103 && V_101 . V_7 == V_104 )
V_92 = F_47 ( V_2 , 0 , V_105 ,
( V_94 ) error , 0 , 0 , V_7 ,
V_51 ) ;
else
V_92 = F_47 ( V_2 , 0 , V_105 ,
( V_94 ) error , 0 , 0 , NULL ,
V_51 ) ;
if ( V_92 )
F_11 ( V_14 , V_95 ,
F_48 ( V_92 ) ) ;
if ( V_2 -> V_74 >= V_2 -> V_106 ) {
abort = F_53 ( V_2 , V_7 ) ;
if ( abort )
F_11 ( V_14 , V_35 ,
F_14 ( abort ) ) ;
}
F_11 ( V_14 , V_96 ,
F_49 ( V_97 ) ) ;
V_2 -> V_98 . error = error ;
F_11 ( V_14 , V_99 , F_50 () ) ;
}
static int F_54 ( T_2 * V_14 ,
struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_107 * V_108 ,
T_7 V_109 )
{
int error ;
if ( ! F_55 ( V_2 , V_7 , F_56 ( V_7 ) , V_108 , V_109 ) )
error = - V_37 ;
else
error = 0 ;
return error ;
}
static void F_57 ( T_2 * V_110 ,
struct V_1 * V_2 )
{
struct V_10 * V_111 ;
F_58 (t, &asoc->peer.transport_addr_list, transports)
F_43 ( V_111 ) ;
}
static void F_59 ( T_2 * V_110 ,
struct V_1 * V_2 )
{
struct V_10 * V_111 ;
F_58 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_60 ( & V_111 -> V_65 ) )
F_25 ( V_111 ) ;
}
}
static void F_61 ( T_2 * V_110 ,
struct V_1 * V_2 )
{
struct V_10 * V_111 ;
F_58 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_60 ( & V_111 -> V_43 ) )
F_25 ( V_111 ) ;
}
}
static void F_62 ( T_2 * V_110 ,
struct V_1 * V_2 ,
struct V_10 * V_111 ,
struct V_6 * V_7 )
{
T_8 * V_112 ;
int V_113 = 0 ;
V_111 -> V_76 = 0 ;
if ( V_111 -> V_2 -> V_49 < V_114 )
V_111 -> V_2 -> V_74 = 0 ;
V_111 -> V_77 = 0 ;
if ( ( V_111 -> V_49 == V_75 ) || ( V_111 -> V_49 == V_78 ) ) {
V_113 = 1 ;
F_42 ( V_2 , V_111 , V_115 ,
V_116 ) ;
}
if ( V_111 -> V_49 == V_117 )
F_42 ( V_2 , V_111 , V_115 ,
V_116 ) ;
if ( V_111 -> V_118 )
F_63 ( V_111 ) ;
if ( V_111 -> V_119 == 0 )
V_111 -> V_119 = 1 ;
V_112 = ( T_8 * ) V_7 -> V_120 -> V_56 ;
F_64 ( V_111 , ( V_44 - V_112 -> V_121 ) ) ;
F_43 ( V_111 ) ;
if ( V_113 && V_2 -> V_19 . V_122 == 1 )
F_65 ( V_111 ) ;
}
static int F_66 ( T_2 * V_110 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_123 = 0 ;
if ( F_67 ( & V_2 -> V_98 , V_7 ) ) {
struct V_41 * V_41 = F_16 ( V_2 -> V_40 . V_39 ) ;
V_123 = F_22 ( V_41 , V_69 ,
F_38 ( V_124 ) ,
V_2 -> V_49 , V_2 -> V_50 , V_2 , NULL ,
V_51 ) ;
}
return V_123 ;
}
static void F_68 ( T_2 * V_110 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_10 * V_111 ;
if ( V_7 -> V_11 )
V_111 = V_7 -> V_11 ;
else {
V_111 = F_69 ( V_2 ,
V_2 -> V_125 ) ;
V_7 -> V_11 = V_111 ;
}
V_2 -> V_125 = V_111 ;
V_2 -> V_27 [ V_59 ] = V_111 -> V_89 ;
}
static void F_70 ( T_2 * V_110 ,
struct V_1 * V_2 ,
struct V_1 * V_126 )
{
struct V_41 * V_41 = F_16 ( V_2 -> V_40 . V_39 ) ;
struct V_6 * abort ;
if ( ! F_71 ( V_2 , V_126 ) )
return;
abort = F_72 ( V_2 , NULL , sizeof( V_127 ) ) ;
if ( abort ) {
F_73 ( abort , V_128 , 0 ) ;
F_11 ( V_110 , V_35 , F_14 ( abort ) ) ;
}
F_11 ( V_110 , V_129 , F_74 ( V_130 ) ) ;
F_11 ( V_110 , V_131 ,
F_75 ( V_128 ) ) ;
F_76 ( V_41 , V_132 ) ;
F_77 ( V_41 , V_133 ) ;
}
static void F_78 ( T_2 * V_110 ,
struct V_1 * V_2 ,
T_9 V_49 )
{
struct V_38 * V_39 = V_2 -> V_40 . V_39 ;
V_2 -> V_49 = V_49 ;
F_19 ( L_4 , V_42 , V_2 , V_134 [ V_49 ] ) ;
if ( F_79 ( V_39 , V_135 ) ) {
if ( F_80 ( V_2 , V_136 ) && F_81 ( V_39 , V_137 ) )
V_39 -> V_138 = V_139 ;
if ( F_80 ( V_2 , V_140 ) &&
F_81 ( V_39 , V_136 ) ) {
V_39 -> V_138 = V_141 ;
V_39 -> V_142 |= V_143 ;
}
}
if ( F_80 ( V_2 , V_144 ) ) {
V_2 -> V_27 [ V_58 ] =
V_2 -> V_145 ;
V_2 -> V_27 [ V_57 ] =
V_2 -> V_145 ;
}
if ( F_80 ( V_2 , V_136 ) ||
F_80 ( V_2 , V_137 ) ||
F_80 ( V_2 , V_140 ) ) {
if ( F_82 ( & V_2 -> V_146 ) )
F_83 ( & V_2 -> V_146 ) ;
if ( ! F_79 ( V_39 , V_147 ) )
V_39 -> V_148 ( V_39 ) ;
}
if ( F_80 ( V_2 , V_149 ) &&
! F_84 ( & V_2 -> V_98 ) )
F_85 ( & V_2 -> V_98 , V_51 ) ;
}
static void F_86 ( T_2 * V_110 ,
struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 . V_39 ;
if ( F_79 ( V_39 , V_135 ) && F_81 ( V_39 , V_150 ) &&
( ! V_2 -> V_151 ) && ( V_39 -> V_142 != V_152 ) )
return;
F_87 ( V_2 ) ;
}
static void F_88 ( T_2 * V_110 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_10 * V_111 ;
V_111 = F_69 ( V_2 , V_7 -> V_11 ) ;
V_2 -> V_27 [ V_60 ] = V_111 -> V_89 ;
V_7 -> V_11 = V_111 ;
}
static void F_89 ( T_2 * V_110 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_153 * V_154 ;
struct V_91 * V_155 ;
while ( V_7 -> V_156 > V_7 -> V_120 -> V_56 ) {
V_154 = (struct V_153 * ) ( V_7 -> V_120 -> V_56 ) ;
V_155 = F_90 ( V_2 , V_7 , 0 ,
V_51 ) ;
if ( ! V_155 )
return;
F_91 ( & V_2 -> V_102 , V_155 ) ;
switch ( V_154 -> V_157 ) {
case V_158 :
{
struct V_159 * V_160 ;
V_160 = (struct V_159 * )
V_154 -> V_161 ;
switch ( V_160 -> type ) {
case V_162 :
if ( V_2 -> V_19 . V_163 == 0 )
break;
V_2 -> V_19 . V_163 = 0 ;
F_11 ( V_110 , V_36 ,
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
static void F_92 ( struct V_164 * V_102 ,
struct V_6 * V_7 )
{
struct V_165 * V_166 ;
F_93 (skip, chunk) {
F_94 ( V_102 , F_95 ( V_166 -> V_167 ) , F_95 ( V_166 -> V_168 ) ) ;
}
}
static void F_96 ( struct V_1 * V_2 )
{
struct V_10 * V_111 ;
struct V_169 * V_170 ;
struct V_169 * V_151 ;
F_97 (pos, temp, &asoc->peer.transport_addr_list) {
V_111 = F_98 ( V_170 , struct V_10 , V_171 ) ;
if ( ! F_99 ( & V_111 -> V_85 ,
& V_2 -> V_19 . V_172 ) ) {
F_100 ( V_2 , V_111 ) ;
}
}
}
static void F_101 ( struct V_1 * V_2 , int error )
{
struct V_38 * V_39 = V_2 -> V_40 . V_39 ;
if ( ! F_79 ( V_39 , V_147 ) )
V_39 -> V_52 = error ;
}
static void F_102 ( T_2 * V_14 ,
struct V_1 * V_2 ,
T_10 V_49 )
{
struct V_91 * V_155 ;
V_155 = F_47 ( V_2 , 0 , V_49 , 0 ,
V_2 -> V_173 . V_174 ,
V_2 -> V_173 . V_175 ,
NULL , V_51 ) ;
if ( V_155 )
F_91 ( & V_2 -> V_102 , V_155 ) ;
}
static void F_103 ( T_2 * V_14 ,
struct V_1 * V_2 )
{
struct V_91 * V_155 ;
V_155 = F_104 ( V_2 , V_51 ) ;
if ( V_155 )
F_91 ( & V_2 -> V_102 , V_155 ) ;
}
static void F_105 ( struct V_1 * V_2 ,
T_3 V_176 ,
char * V_177 )
{
struct V_10 * V_111 ;
V_111 = V_2 -> V_178 ;
V_2 -> V_179 ++ ;
if ( V_111 -> V_180 > ( V_2 -> V_181 + 1 ) ) {
V_2 -> V_27 [ V_176 ] *= 2 ;
if ( V_2 -> V_27 [ V_176 ] > V_2 -> V_182 ) {
V_2 -> V_27 [ V_176 ] = V_2 -> V_182 ;
}
V_2 -> V_181 ++ ;
F_19 ( L_5
L_6 , V_42 , V_177 ,
V_2 -> V_179 , V_2 -> V_181 ,
V_2 -> V_27 [ V_176 ] ) ;
}
}
static void F_106 ( struct V_1 * V_2 ,
struct V_183 * V_184 , T_7 V_109 )
{
struct V_6 * V_7 ;
F_58 (chunk, &msg->chunks, frag_list)
F_107 ( & V_2 -> V_98 , V_7 , V_109 ) ;
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_41 * V_41 = F_16 ( V_2 -> V_40 . V_39 ) ;
if ( ! F_109 ( & V_2 -> V_185 ) ) {
struct V_169 * V_186 = V_2 -> V_185 . V_187 ;
struct V_6 * V_188 = F_98 ( V_186 ,
struct V_6 , V_189 ) ;
F_110 ( V_186 ) ;
F_111 ( V_188 ) ;
if ( F_112 ( V_41 , V_2 , V_188 ) )
F_113 ( V_188 ) ;
else
V_2 -> V_190 = V_188 ;
}
}
int F_22 ( struct V_41 * V_41 , T_5 V_100 , T_6 V_101 ,
T_9 V_49 ,
struct V_191 * V_50 ,
struct V_1 * V_2 ,
void * V_192 ,
T_7 V_109 )
{
T_2 V_14 ;
const T_11 * V_193 ;
T_12 V_194 ;
int error = 0 ;
typedef const char * (F_114)( T_6 );
static F_114 * V_195 [] = {
NULL , V_196 , V_197 , V_198 , V_199 ,
} ;
F_114 * T_13 V_200 ( ( V_201 ) ) = V_195 [ V_100 ] ;
V_193 = F_115 ( V_41 , V_100 , V_49 , V_101 ) ;
F_116 ( & V_14 ) ;
F_117 () ;
V_194 = V_193 -> V_202 ( V_41 , V_50 , V_2 , V_101 , V_192 , & V_14 ) ;
F_118 () ;
error = F_119 ( V_100 , V_101 , V_49 ,
V_50 , & V_2 , V_192 , V_194 ,
& V_14 , V_109 ) ;
F_120 () ;
return error ;
}
static int F_119 ( T_5 V_100 , T_6 V_101 ,
T_9 V_49 ,
struct V_191 * V_50 ,
struct V_1 * * V_2 ,
void * V_192 ,
T_12 V_194 ,
T_2 * V_14 ,
T_7 V_109 )
{
int error ;
if ( 0 != ( error = F_121 ( V_100 , V_101 , V_49 ,
V_50 , * V_2 ,
V_192 , V_194 ,
V_14 , V_109 ) ) )
goto V_203;
switch ( V_194 ) {
case V_204 :
F_19 ( L_7
L_8 , V_42 , V_49 ,
V_100 , V_101 . V_7 ) ;
break;
case V_205 :
error = - V_37 ;
break;
case V_206 :
case V_207 :
* V_2 = NULL ;
break;
case V_208 :
break;
case V_209 :
F_122 ( L_9 ,
V_49 , V_101 . V_7 ) ;
break;
case V_210 :
F_123 ( L_10 ,
V_49 , V_100 , V_101 . V_7 ) ;
break;
case V_211 :
F_124 ( L_11 ,
V_49 , V_100 , V_101 . V_7 ) ;
F_125 () ;
break;
default:
F_124 ( L_12 ,
V_194 , V_49 , V_100 , V_101 . V_7 ) ;
F_125 () ;
break;
}
V_203:
return error ;
}
static int F_121 ( T_5 V_100 ,
T_6 V_101 ,
T_9 V_49 ,
struct V_191 * V_50 ,
struct V_1 * V_2 ,
void * V_192 ,
T_12 V_194 ,
T_2 * V_14 ,
T_7 V_109 )
{
struct V_38 * V_39 = V_50 -> V_40 . V_39 ;
struct V_212 * V_213 = F_126 ( V_39 ) ;
int error = 0 ;
int V_13 ;
T_14 * V_214 ;
struct V_6 * V_215 ;
struct V_6 * V_7 = NULL ;
struct V_216 * V_217 ;
struct V_218 * V_176 ;
unsigned long V_64 ;
struct V_10 * V_111 ;
struct V_219 V_220 ;
int V_221 = 0 ;
if ( V_47 != V_100 )
V_7 = V_192 ;
while ( NULL != ( V_214 = F_127 ( V_14 ) ) ) {
switch ( V_214 -> V_222 ) {
case V_223 :
break;
case V_224 :
if ( V_221 ) {
F_85 ( & V_2 -> V_98 , V_109 ) ;
V_221 = 0 ;
}
V_2 = V_214 -> V_225 . V_2 ;
F_128 ( V_2 -> V_19 . V_226 == NULL ) ;
F_129 ( V_50 , V_2 ) ;
break;
case V_227 :
F_70 ( V_14 , V_2 , V_214 -> V_225 . V_2 ) ;
break;
case V_228 :
F_130 ( & V_2 -> V_98 ) ;
break;
case V_99 :
if ( V_221 ) {
F_85 ( & V_2 -> V_98 , V_109 ) ;
V_221 = 0 ;
}
F_86 ( V_14 , V_2 ) ;
V_2 = NULL ;
break;
case V_96 :
F_78 ( V_14 , V_2 , V_214 -> V_225 . V_49 ) ;
break;
case V_229 :
error = F_131 ( & V_2 -> V_19 . V_24 ,
V_214 -> V_225 . T_4 , NULL ) ;
break;
case V_230 :
F_132 ( & V_2 -> V_19 . V_24 , V_214 -> V_225 . T_4 ) ;
F_133 ( & V_2 -> V_102 , V_214 -> V_225 . T_4 ) ;
F_52 ( & V_2 -> V_102 , V_51 ) ;
break;
case V_231 :
F_92 ( & V_2 -> V_102 , V_214 -> V_225 . V_7 ) ;
break;
case V_232 :
V_13 = V_214 -> V_225 . V_233 ;
error = F_8 ( V_2 , V_13 , V_14 ) ;
break;
case V_234 :
error = F_66 ( V_14 , V_2 ,
V_214 -> V_225 . V_7 ) ;
break;
case V_235 :
V_215 = F_134 ( V_2 , V_7 , V_51 ,
0 ) ;
if ( ! V_215 )
goto V_34;
F_11 ( V_14 , V_35 ,
F_14 ( V_215 ) ) ;
break;
case V_236 :
error = F_54 ( V_14 , V_2 , V_7 ,
V_214 -> V_225 . V_237 , V_109 ) ;
break;
case V_238 :
V_215 = F_135 ( V_2 , V_7 ) ;
if ( ! V_215 ) {
if ( V_214 -> V_225 . V_7 )
F_113 ( V_214 -> V_225 . V_7 ) ;
goto V_34;
}
F_11 ( V_14 , V_35 ,
F_14 ( V_215 ) ) ;
if ( V_214 -> V_225 . V_7 )
F_11 ( V_14 , V_35 ,
F_14 ( V_214 -> V_225 . V_7 ) ) ;
if ( V_215 -> V_11 ) {
V_215 -> V_11 -> V_180 ++ ;
V_2 -> V_178 = V_215 -> V_11 ;
}
if ( ( V_2 -> V_19 . V_239 !=
V_2 -> V_19 . V_226 ) &&
( V_2 -> V_179 > 0 ) ) {
F_11 ( V_14 ,
V_240 ,
F_50 () ) ;
}
break;
case V_241 :
V_2 -> V_74 = 0 ;
V_215 = F_136 ( V_2 , V_7 ) ;
if ( ! V_215 )
goto V_34;
F_11 ( V_14 , V_35 ,
F_14 ( V_215 ) ) ;
break;
case V_242 :
F_19 ( L_13 ,
V_42 , V_214 -> V_225 . V_7 , & V_2 -> V_102 ) ;
F_137 ( & V_2 -> V_102 , V_214 -> V_225 . V_7 ,
V_51 ) ;
break;
case V_95 :
F_19 ( L_14 ,
V_42 , V_214 -> V_225 . V_243 , & V_2 -> V_102 ) ;
F_91 ( & V_2 -> V_102 , V_214 -> V_225 . V_243 ) ;
break;
case V_35 :
if ( ! V_2 -> V_98 . V_244 ) {
F_138 ( & V_2 -> V_98 ) ;
V_221 = 1 ;
}
F_107 ( & V_2 -> V_98 , V_214 -> V_225 . V_7 , V_109 ) ;
break;
case V_245 :
V_217 = V_214 -> V_225 . V_217 ;
F_139 ( V_217 , V_109 ) ;
F_140 ( V_217 ) ;
break;
case V_246 :
F_141 ( & V_2 -> V_98 , V_214 -> V_225 . V_11 ,
V_247 ) ;
break;
case V_248 :
F_141 ( & V_2 -> V_98 , V_214 -> V_225 . V_11 ,
V_249 ) ;
break;
case V_250 :
F_1 ( V_2 , V_214 -> V_225 . T_4 ) ;
break;
case V_251 :
V_215 = F_2 ( V_2 , V_214 -> V_225 . T_4 ,
V_7 ) ;
if ( V_215 )
F_11 ( V_14 , V_35 ,
F_14 ( V_215 ) ) ;
break;
case V_252 :
F_7 ( V_2 , V_214 -> V_225 . T_4 ) ;
break;
case V_253 :
F_68 ( V_14 , V_2 , V_214 -> V_225 . V_7 ) ;
break;
case V_254 :
V_176 = & V_2 -> V_54 [ V_214 -> V_225 . V_255 ] ;
if ( F_142 ( V_176 ) )
break;
case V_256 :
V_176 = & V_2 -> V_54 [ V_214 -> V_225 . V_255 ] ;
V_64 = V_2 -> V_27 [ V_214 -> V_225 . V_255 ] ;
F_128 ( ! V_64 ) ;
V_176 -> V_257 = V_44 + V_64 ;
F_27 ( V_2 ) ;
F_143 ( V_176 ) ;
break;
case V_30 :
V_176 = & V_2 -> V_54 [ V_214 -> V_225 . V_255 ] ;
V_64 = V_2 -> V_27 [ V_214 -> V_225 . V_255 ] ;
if ( ! F_20 ( V_176 , V_44 + V_64 ) )
F_27 ( V_2 ) ;
break;
case V_36 :
V_176 = & V_2 -> V_54 [ V_214 -> V_225 . V_255 ] ;
if ( F_60 ( V_176 ) )
F_28 ( V_2 ) ;
break;
case V_258 :
V_7 = V_214 -> V_225 . V_7 ;
V_111 = F_69 ( V_2 ,
V_2 -> V_178 ) ;
V_2 -> V_178 = V_111 ;
V_7 -> V_11 = V_111 ;
V_111 -> V_180 ++ ;
F_144 ( V_2 , V_111 ) ;
break;
case V_259 :
F_105 ( V_2 ,
V_58 ,
L_15 ) ;
F_11 ( V_14 , V_30 ,
F_12 ( V_58 ) ) ;
break;
case V_260 :
F_105 ( V_2 ,
V_57 ,
L_16 ) ;
F_58 (t, &asoc->peer.transport_addr_list,
transports) {
F_145 ( & V_2 -> V_98 , V_111 ,
V_247 ) ;
}
F_11 ( V_14 ,
V_30 ,
F_12 ( V_57 ) ) ;
break;
case V_261 :
F_46 ( V_14 , V_2 , V_214 -> V_225 . V_123 ) ;
break;
case V_131 :
F_51 ( V_14 , V_2 , V_100 ,
V_101 , V_7 , V_214 -> V_225 . V_123 ) ;
break;
case V_262 :
V_2 -> V_179 ++ ;
break;
case V_263 :
V_2 -> V_179 = 0 ;
V_2 -> V_181 = 0 ;
F_58 (t, &asoc->peer.transport_addr_list,
transports) {
V_111 -> V_180 = 0 ;
}
break;
case V_264 :
F_146 ( & V_2 -> V_19 . V_24 ,
V_214 -> V_225 . T_4 ) ;
break;
case V_265 :
F_19 ( L_17 , V_42 ) ;
break;
case V_266 :
F_41 ( V_14 , V_2 ,
V_214 -> V_225 . V_11 , 0 ) ;
break;
case V_267 :
V_111 = V_214 -> V_225 . V_11 ;
F_5 ( V_111 , V_268 ) ;
break;
case V_269 :
V_111 = V_214 -> V_225 . V_11 ;
F_41 ( V_14 , V_2 ,
V_111 , 1 ) ;
V_111 -> V_77 = 1 ;
break;
case V_270 :
V_111 = V_214 -> V_225 . V_11 ;
F_62 ( V_14 , V_2 , V_111 , V_7 ) ;
break;
case V_271 :
F_57 ( V_14 , V_2 ) ;
break;
case V_272 :
V_111 = V_214 -> V_225 . V_11 ;
F_43 ( V_111 ) ;
break;
case V_273 :
F_59 ( V_14 , V_2 ) ;
break;
case V_274 :
error = V_214 -> V_225 . error ;
break;
case V_275 :
V_220 . V_276 = V_214 -> V_225 . V_277 ;
V_220 . V_32 = V_2 -> V_19 . V_33 +
V_2 -> V_98 . V_278 ;
V_220 . V_279 = 0 ;
V_220 . V_280 = 0 ;
V_7 -> V_281 . V_282 = & V_220 ;
F_11 ( V_14 , V_234 ,
F_14 ( V_7 ) ) ;
break;
case V_283 :
V_7 -> V_284 = 1 ;
if ( V_2 ) {
F_85 ( & V_2 -> V_98 , V_109 ) ;
V_221 = 0 ;
}
break;
case V_285 :
V_111 = V_214 -> V_225 . V_11 ;
V_111 -> V_119 = 1 ;
break;
case V_286 :
F_147 ( & V_2 -> V_102 , V_51 ) ;
break;
case V_287 :
F_148 ( & V_2 -> V_102 , V_214 -> V_225 . V_7 ,
V_51 ) ;
break;
case V_288 :
F_88 ( V_14 , V_2 , V_214 -> V_225 . V_7 ) ;
break;
case V_289 :
F_89 ( V_14 , V_2 , V_7 ) ;
break;
case V_290 :
V_2 -> V_19 . V_291 . V_292 = 0 ;
break;
case V_293 :
F_96 ( V_2 ) ;
break;
case V_294 :
F_61 ( V_14 , V_2 ) ;
break;
case V_240 :
V_111 = V_2 -> V_19 . V_239 ;
V_2 -> V_19 . V_239 = V_2 -> V_19 . V_226 ;
F_85 ( & V_2 -> V_98 , V_109 ) ;
V_221 = 0 ;
V_2 -> V_19 . V_239 = V_111 ;
break;
case V_129 :
F_101 ( V_2 , V_214 -> V_225 . error ) ;
break;
case V_295 :
F_102 ( V_14 , V_2 ,
V_214 -> V_225 . T_10 ) ;
break;
case V_296 :
F_103 ( V_14 , V_2 ) ;
break;
case V_297 :
error = F_149 ( V_2 ,
V_51 ) ;
break;
case V_298 :
V_2 -> V_19 . V_291 . V_292 = V_214 -> V_225 . T_4 ;
break;
case V_299 :
if ( ! V_2 -> V_98 . V_244 ) {
F_138 ( & V_2 -> V_98 ) ;
V_221 = 1 ;
}
F_106 ( V_2 , V_214 -> V_225 . V_184 , V_109 ) ;
break;
case V_300 :
F_108 ( V_2 ) ;
break;
case V_301 :
F_150 ( V_2 ) ;
break;
case V_302 :
if ( V_2 && V_221 ) {
F_85 ( & V_2 -> V_98 , V_109 ) ;
V_221 = 0 ;
}
V_2 = V_214 -> V_225 . V_2 ;
break;
default:
F_123 ( L_18 ,
V_214 -> V_222 ) ;
break;
}
if ( error )
break;
}
V_303:
if ( V_2 && V_103 == V_100 && V_7 ) {
if ( V_7 -> V_304 || V_7 -> V_305 )
F_85 ( & V_2 -> V_98 , V_109 ) ;
} else if ( V_221 )
F_85 ( & V_2 -> V_98 , V_109 ) ;
if ( V_213 -> V_306 )
V_213 -> V_306 = 0 ;
return error ;
V_34:
error = - V_37 ;
goto V_303;
}
