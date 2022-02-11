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
struct V_14 * V_15 )
{
struct V_10 * V_16 = V_2 -> V_17 . V_18 ;
T_1 V_19 , V_20 ;
struct V_6 * V_21 ;
int error = 0 ;
if ( V_13 ||
( ! V_16 && ( V_2 -> V_22 & V_23 ) ) ||
( V_16 && ( V_16 -> V_22 & V_23 ) ) )
V_2 -> V_17 . V_24 = 1 ;
V_19 = F_9 ( & V_2 -> V_17 . V_25 ) ;
V_20 = F_10 ( & V_2 -> V_17 . V_25 ) ;
if ( V_20 != V_19 )
V_2 -> V_17 . V_24 = 1 ;
if ( ! V_2 -> V_17 . V_24 ) {
V_2 -> V_17 . V_26 ++ ;
if ( V_16 ) {
if ( V_2 -> V_17 . V_26 >= V_16 -> V_27 - 1 )
V_2 -> V_17 . V_24 = 1 ;
V_2 -> V_28 [ V_29 ] =
V_16 -> V_30 ;
} else {
if ( V_2 -> V_17 . V_26 >= V_2 -> V_27 - 1 )
V_2 -> V_17 . V_24 = 1 ;
V_2 -> V_28 [ V_29 ] =
V_2 -> V_30 ;
}
F_11 ( V_15 , V_31 ,
F_12 ( V_29 ) ) ;
} else {
T_1 V_32 = V_2 -> V_33 ;
V_2 -> V_33 = V_2 -> V_34 ;
V_21 = F_13 ( V_2 ) ;
if ( ! V_21 ) {
V_2 -> V_33 = V_32 ;
goto V_35;
}
V_2 -> V_17 . V_24 = 0 ;
V_2 -> V_17 . V_26 = 0 ;
F_11 ( V_15 , V_36 , F_14 ( V_21 ) ) ;
F_11 ( V_15 , V_37 ,
F_12 ( V_29 ) ) ;
}
return error ;
V_35:
error = - V_38 ;
return error ;
}
void F_15 ( unsigned long V_17 )
{
struct V_10 * V_11 = (struct V_10 * ) V_17 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_39 * V_40 = V_2 -> V_41 . V_40 ;
struct V_42 * V_42 = F_16 ( V_40 ) ;
int error ;
F_17 ( V_40 ) ;
if ( F_18 ( V_40 ) ) {
F_19 ( L_1 , V_43 ) ;
if ( ! F_20 ( & V_11 -> V_44 , V_45 + ( V_46 / 20 ) ) )
F_21 ( V_11 ) ;
goto V_47;
}
error = F_22 ( V_42 , V_48 ,
F_23 ( V_49 ) ,
V_2 -> V_50 ,
V_2 -> V_51 , V_2 ,
V_11 , V_52 ) ;
if ( error )
V_40 -> V_53 = - error ;
V_47:
F_24 ( V_40 ) ;
F_25 ( V_11 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
enum V_54 V_55 )
{
struct V_39 * V_40 = V_2 -> V_41 . V_40 ;
struct V_42 * V_42 = F_16 ( V_40 ) ;
int error = 0 ;
F_17 ( V_40 ) ;
if ( F_18 ( V_40 ) ) {
F_19 ( L_2 , V_43 ,
V_55 ) ;
if ( ! F_20 ( & V_2 -> V_56 [ V_55 ] , V_45 + ( V_46 / 20 ) ) )
F_27 ( V_2 ) ;
goto V_47;
}
if ( V_2 -> V_41 . V_57 )
goto V_47;
error = F_22 ( V_42 , V_48 ,
F_23 ( V_55 ) ,
V_2 -> V_50 , V_2 -> V_51 , V_2 ,
( void * ) V_55 , V_52 ) ;
if ( error )
V_40 -> V_53 = - error ;
V_47:
F_24 ( V_40 ) ;
F_28 ( V_2 ) ;
}
static void F_29 ( unsigned long V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_58 ;
F_26 ( V_2 , V_59 ) ;
}
static void F_30 ( unsigned long V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_58 ;
F_26 ( V_2 , V_60 ) ;
}
static void F_31 ( unsigned long V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_58 ;
F_26 ( V_2 , V_61 ) ;
}
static void F_32 ( unsigned long V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_58 ;
F_26 ( V_2 , V_62 ) ;
}
static void F_33 ( unsigned long V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_58 ;
F_26 ( V_2 ,
V_63 ) ;
}
static void F_34 ( unsigned long V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_58 ;
F_26 ( V_2 , V_64 ) ;
}
void F_35 ( unsigned long V_58 )
{
struct V_10 * V_11 = (struct V_10 * ) V_58 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_39 * V_40 = V_2 -> V_41 . V_40 ;
struct V_42 * V_42 = F_16 ( V_40 ) ;
T_2 V_65 , V_66 ;
int error = 0 ;
F_17 ( V_40 ) ;
if ( F_18 ( V_40 ) ) {
F_19 ( L_1 , V_43 ) ;
if ( ! F_20 ( & V_11 -> V_67 , V_45 + ( V_46 / 20 ) ) )
F_21 ( V_11 ) ;
goto V_47;
}
V_65 = V_45 - V_11 -> V_68 ;
V_66 = F_36 ( V_11 ) ;
if ( V_65 < V_66 ) {
V_65 = V_66 - V_65 ;
if ( ! F_20 ( & V_11 -> V_67 , V_45 + V_65 ) )
F_21 ( V_11 ) ;
goto V_47;
}
error = F_22 ( V_42 , V_48 ,
F_23 ( V_69 ) ,
V_2 -> V_50 , V_2 -> V_51 , V_2 ,
V_11 , V_52 ) ;
if ( error )
V_40 -> V_53 = - error ;
V_47:
F_24 ( V_40 ) ;
F_25 ( V_11 ) ;
}
void F_37 ( unsigned long V_58 )
{
struct V_10 * V_11 = (struct V_10 * ) V_58 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_39 * V_40 = V_2 -> V_41 . V_40 ;
struct V_42 * V_42 = F_16 ( V_40 ) ;
F_17 ( V_40 ) ;
if ( F_18 ( V_40 ) ) {
F_19 ( L_1 , V_43 ) ;
if ( ! F_20 ( & V_11 -> V_70 ,
V_45 + ( V_46 / 20 ) ) )
F_27 ( V_2 ) ;
goto V_47;
}
if ( V_2 -> V_41 . V_57 )
goto V_47;
F_22 ( V_42 , V_71 ,
F_38 ( V_72 ) ,
V_2 -> V_50 , V_2 -> V_51 , V_2 , V_11 , V_52 ) ;
V_47:
F_24 ( V_40 ) ;
F_28 ( V_2 ) ;
}
void F_39 ( unsigned long V_58 )
{
struct V_10 * V_11 = (struct V_10 * ) V_58 ;
struct V_1 * V_2 = V_11 -> V_2 ;
struct V_39 * V_40 = V_2 -> V_41 . V_40 ;
struct V_42 * V_42 = F_16 ( V_40 ) ;
int error = 0 ;
F_17 ( V_40 ) ;
if ( F_18 ( V_40 ) ) {
F_19 ( L_1 , V_43 ) ;
if ( ! F_20 ( & V_11 -> V_73 , V_45 + ( V_46 / 20 ) ) )
F_21 ( V_11 ) ;
goto V_47;
}
error = F_22 ( V_42 , V_48 ,
F_23 ( V_74 ) ,
V_2 -> V_50 , V_2 -> V_51 , V_2 ,
V_11 , V_52 ) ;
if ( error )
V_40 -> V_53 = - error ;
V_47:
F_24 ( V_40 ) ;
F_25 ( V_11 ) ;
}
static void F_40 ( unsigned long V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_58 ;
F_26 ( V_2 , V_29 ) ;
}
static void F_41 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_10 * V_11 ,
int V_75 )
{
struct V_42 * V_42 = F_16 ( V_2 -> V_41 . V_40 ) ;
if ( ! V_75 ) {
V_2 -> V_76 ++ ;
if ( V_11 -> V_50 != V_77 )
V_11 -> V_78 ++ ;
} else if ( V_11 -> V_79 ) {
if ( V_11 -> V_50 != V_80 )
V_2 -> V_76 ++ ;
if ( V_11 -> V_50 != V_77 )
V_11 -> V_78 ++ ;
}
if ( V_42 -> V_81 . V_82 &&
( V_11 -> V_50 == V_83 ) &&
( V_2 -> V_84 < V_11 -> V_85 ) &&
( V_11 -> V_78 > V_2 -> V_84 ) ) {
F_42 ( V_2 , V_11 ,
V_86 ,
0 ) ;
F_43 ( V_11 ) ;
}
if ( V_11 -> V_50 != V_77 &&
( V_11 -> V_78 > V_11 -> V_85 ) ) {
F_19 ( L_3 ,
V_43 , V_2 , & V_11 -> V_87 . V_88 ) ;
F_42 ( V_2 , V_11 ,
V_89 ,
V_90 ) ;
}
if ( ! V_75 || V_11 -> V_79 ) {
V_11 -> V_91 = F_44 ( ( V_11 -> V_91 * 2 ) , V_11 -> V_2 -> V_92 ) ;
F_45 ( V_2 , V_11 ) ;
}
}
static void F_46 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
unsigned int error )
{
struct V_93 * V_94 ;
V_94 = F_47 ( V_2 , 0 , V_95 ,
( V_96 ) error , 0 , 0 , NULL ,
V_52 ) ;
if ( V_94 )
F_11 ( V_15 , V_97 ,
F_48 ( V_94 ) ) ;
F_11 ( V_15 , V_98 ,
F_49 ( V_99 ) ) ;
V_2 -> V_100 . error = error ;
F_11 ( V_15 , V_101 , F_50 () ) ;
}
static void F_51 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
enum V_102 V_103 ,
union V_104 V_105 ,
struct V_6 * V_7 ,
unsigned int error )
{
struct V_93 * V_94 ;
struct V_6 * abort ;
F_52 ( & V_2 -> V_106 , V_52 ) ;
if ( V_103 == V_107 && V_105 . V_7 == V_108 )
V_94 = F_47 ( V_2 , 0 , V_109 ,
( V_96 ) error , 0 , 0 , V_7 ,
V_52 ) ;
else
V_94 = F_47 ( V_2 , 0 , V_109 ,
( V_96 ) error , 0 , 0 , NULL ,
V_52 ) ;
if ( V_94 )
F_11 ( V_15 , V_97 ,
F_48 ( V_94 ) ) ;
if ( V_2 -> V_76 >= V_2 -> V_110 ) {
abort = F_53 ( V_2 , V_7 ) ;
if ( abort )
F_11 ( V_15 , V_36 ,
F_14 ( abort ) ) ;
}
F_11 ( V_15 , V_98 ,
F_49 ( V_99 ) ) ;
V_2 -> V_100 . error = error ;
F_11 ( V_15 , V_101 , F_50 () ) ;
}
static int F_54 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_111 * V_112 ,
T_3 V_113 )
{
int error ;
if ( ! F_55 ( V_2 , V_7 , F_56 ( V_7 ) , V_112 , V_113 ) )
error = - V_38 ;
else
error = 0 ;
return error ;
}
static void F_57 ( struct V_14 * V_114 ,
struct V_1 * V_2 )
{
struct V_10 * V_115 ;
F_58 (t, &asoc->peer.transport_addr_list, transports)
F_43 ( V_115 ) ;
}
static void F_59 ( struct V_14 * V_114 ,
struct V_1 * V_2 )
{
struct V_10 * V_115 ;
F_58 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_60 ( & V_115 -> V_67 ) )
F_25 ( V_115 ) ;
}
}
static void F_61 ( struct V_14 * V_114 ,
struct V_1 * V_2 )
{
struct V_10 * V_115 ;
F_58 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_60 ( & V_115 -> V_44 ) )
F_25 ( V_115 ) ;
}
}
static void F_62 ( struct V_14 * V_114 ,
struct V_1 * V_2 ,
struct V_10 * V_115 ,
struct V_6 * V_7 )
{
struct V_116 * V_117 ;
int V_118 = 0 ;
V_115 -> V_78 = 0 ;
if ( V_115 -> V_2 -> V_50 < V_119 )
V_115 -> V_2 -> V_76 = 0 ;
V_115 -> V_79 = 0 ;
if ( ( V_115 -> V_50 == V_77 ) || ( V_115 -> V_50 == V_80 ) ) {
V_118 = 1 ;
F_42 ( V_2 , V_115 , V_120 ,
V_121 ) ;
}
if ( V_115 -> V_50 == V_122 )
F_42 ( V_2 , V_115 , V_120 ,
V_121 ) ;
if ( V_115 -> V_123 )
F_63 ( V_115 ) ;
if ( V_115 -> V_124 == 0 )
V_115 -> V_124 = 1 ;
V_117 = (struct V_116 * ) V_7 -> V_125 -> V_58 ;
F_64 ( V_115 , ( V_45 - V_117 -> V_126 ) ) ;
F_43 ( V_115 ) ;
if ( V_118 && V_2 -> V_17 . V_127 == 1 )
F_65 ( V_115 ) ;
}
static int F_66 ( struct V_14 * V_114 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_128 = 0 ;
if ( F_67 ( & V_2 -> V_100 , V_7 ) ) {
struct V_42 * V_42 = F_16 ( V_2 -> V_41 . V_40 ) ;
V_128 = F_22 ( V_42 , V_71 ,
F_38 ( V_129 ) ,
V_2 -> V_50 , V_2 -> V_51 , V_2 , NULL ,
V_52 ) ;
}
return V_128 ;
}
static void F_68 ( struct V_14 * V_114 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_10 * V_115 ;
if ( V_7 -> V_11 )
V_115 = V_7 -> V_11 ;
else {
V_115 = F_69 ( V_2 ,
V_2 -> V_130 ) ;
V_7 -> V_11 = V_115 ;
}
V_2 -> V_130 = V_115 ;
V_2 -> V_28 [ V_61 ] = V_115 -> V_91 ;
}
static void F_70 ( struct V_14 * V_114 ,
struct V_1 * V_2 ,
struct V_1 * V_131 )
{
struct V_42 * V_42 = F_16 ( V_2 -> V_41 . V_40 ) ;
struct V_6 * abort ;
if ( ! F_71 ( V_2 , V_131 ) )
return;
abort = F_72 ( V_2 , NULL , sizeof( struct V_132 ) ) ;
if ( abort ) {
F_73 ( abort , V_133 , 0 ) ;
F_11 ( V_114 , V_36 , F_14 ( abort ) ) ;
}
F_11 ( V_114 , V_134 , F_74 ( V_135 ) ) ;
F_11 ( V_114 , V_136 ,
F_75 ( V_133 ) ) ;
F_76 ( V_42 , V_137 ) ;
F_77 ( V_42 , V_138 ) ;
}
static void F_78 ( struct V_14 * V_114 ,
struct V_1 * V_2 ,
enum V_139 V_50 )
{
struct V_39 * V_40 = V_2 -> V_41 . V_40 ;
V_2 -> V_50 = V_50 ;
F_19 ( L_4 , V_43 , V_2 , V_140 [ V_50 ] ) ;
if ( F_79 ( V_40 , V_141 ) ) {
if ( V_139 ( V_2 , V_142 ) && F_80 ( V_40 , V_143 ) )
V_40 -> V_144 = V_145 ;
if ( V_139 ( V_2 , V_146 ) &&
F_80 ( V_40 , V_142 ) ) {
V_40 -> V_144 = V_147 ;
V_40 -> V_148 |= V_149 ;
}
}
if ( V_139 ( V_2 , V_150 ) ) {
V_2 -> V_28 [ V_60 ] =
V_2 -> V_151 ;
V_2 -> V_28 [ V_59 ] =
V_2 -> V_151 ;
}
if ( V_139 ( V_2 , V_142 ) ||
V_139 ( V_2 , V_143 ) ||
V_139 ( V_2 , V_146 ) ) {
if ( F_81 ( & V_2 -> V_152 ) )
F_82 ( & V_2 -> V_152 ) ;
if ( ! F_79 ( V_40 , V_153 ) )
V_40 -> V_154 ( V_40 ) ;
}
if ( V_139 ( V_2 , V_155 ) &&
! F_83 ( & V_2 -> V_100 ) )
F_84 ( & V_2 -> V_100 , V_52 ) ;
}
static void F_85 ( struct V_14 * V_114 ,
struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_41 . V_40 ;
if ( F_79 ( V_40 , V_141 ) && F_80 ( V_40 , V_156 ) &&
( ! V_2 -> V_157 ) && ( V_40 -> V_148 != V_158 ) )
return;
F_86 ( V_2 ) ;
}
static void F_87 ( struct V_14 * V_114 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_10 * V_115 ;
V_115 = F_69 ( V_2 , V_7 -> V_11 ) ;
V_2 -> V_28 [ V_62 ] = V_115 -> V_91 ;
V_7 -> V_11 = V_115 ;
}
static void F_88 ( struct V_14 * V_114 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_132 * V_159 ;
struct V_93 * V_160 ;
while ( V_7 -> V_161 > V_7 -> V_125 -> V_58 ) {
V_159 = (struct V_132 * ) ( V_7 -> V_125 -> V_58 ) ;
V_160 = F_89 ( V_2 , V_7 , 0 ,
V_52 ) ;
if ( ! V_160 )
return;
F_90 ( & V_2 -> V_106 , V_160 ) ;
switch ( V_159 -> V_162 ) {
case V_163 :
{
struct V_164 * V_165 ;
V_165 = (struct V_164 * )
V_159 -> V_166 ;
switch ( V_165 -> type ) {
case V_167 :
if ( V_2 -> V_17 . V_168 == 0 )
break;
V_2 -> V_17 . V_168 = 0 ;
F_11 ( V_114 , V_37 ,
F_12 ( V_62 ) ) ;
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
static void F_91 ( struct V_169 * V_106 ,
struct V_6 * V_7 )
{
struct V_170 * V_171 ;
F_92 (skip, chunk) {
F_93 ( V_106 , F_94 ( V_171 -> V_172 ) , F_94 ( V_171 -> V_173 ) ) ;
}
}
static void F_95 ( struct V_1 * V_2 )
{
struct V_10 * V_115 ;
struct V_174 * V_157 ;
struct V_174 * V_175 ;
F_96 (pos, temp, &asoc->peer.transport_addr_list) {
V_115 = F_97 ( V_175 , struct V_10 , V_176 ) ;
if ( ! F_98 ( & V_115 -> V_87 ,
& V_2 -> V_17 . V_177 ) ) {
F_99 ( V_2 , V_115 ) ;
}
}
}
static void F_100 ( struct V_1 * V_2 , int error )
{
struct V_39 * V_40 = V_2 -> V_41 . V_40 ;
if ( ! F_79 ( V_40 , V_153 ) )
V_40 -> V_53 = error ;
}
static void F_101 ( struct V_14 * V_15 ,
struct V_1 * V_2 ,
T_4 V_50 )
{
struct V_93 * V_160 ;
V_160 = F_47 ( V_2 , 0 , V_50 , 0 ,
V_2 -> V_178 . V_179 ,
V_2 -> V_178 . V_180 ,
NULL , V_52 ) ;
if ( V_160 )
F_90 ( & V_2 -> V_106 , V_160 ) ;
}
static void F_102 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_93 * V_160 ;
V_160 = F_103 ( V_2 , V_52 ) ;
if ( V_160 )
F_90 ( & V_2 -> V_106 , V_160 ) ;
}
static void F_104 ( struct V_1 * V_2 ,
enum V_54 V_181 ,
char * V_182 )
{
struct V_10 * V_115 ;
V_115 = V_2 -> V_183 ;
V_2 -> V_184 ++ ;
if ( V_115 -> V_185 > ( V_2 -> V_186 + 1 ) ) {
V_2 -> V_28 [ V_181 ] *= 2 ;
if ( V_2 -> V_28 [ V_181 ] > V_2 -> V_187 ) {
V_2 -> V_28 [ V_181 ] = V_2 -> V_187 ;
}
V_2 -> V_186 ++ ;
F_19 ( L_5
L_6 , V_43 , V_182 ,
V_2 -> V_184 , V_2 -> V_186 ,
V_2 -> V_28 [ V_181 ] ) ;
}
}
static void F_105 ( struct V_1 * V_2 ,
struct V_188 * V_189 , T_3 V_113 )
{
struct V_6 * V_7 ;
F_58 (chunk, &msg->chunks, frag_list)
F_106 ( & V_2 -> V_100 , V_7 , V_113 ) ;
}
static void F_107 ( struct V_1 * V_2 )
{
struct V_42 * V_42 = F_16 ( V_2 -> V_41 . V_40 ) ;
if ( ! F_108 ( & V_2 -> V_190 ) ) {
struct V_174 * V_191 = V_2 -> V_190 . V_192 ;
struct V_6 * V_193 = F_97 ( V_191 ,
struct V_6 , V_194 ) ;
F_109 ( V_191 ) ;
F_110 ( V_193 ) ;
if ( F_111 ( V_42 , V_2 , V_193 ) )
F_112 ( V_193 ) ;
else
V_2 -> V_195 = V_193 ;
}
}
int F_22 ( struct V_42 * V_42 , enum V_102 V_103 ,
union V_104 V_105 , enum V_139 V_50 ,
struct V_196 * V_51 , struct V_1 * V_2 ,
void * V_197 , T_3 V_113 )
{
typedef const char * (F_113)( union V_104 );
static F_113 * V_198 [] = {
NULL , V_199 , V_200 , V_201 , V_202 ,
} ;
F_113 * T_5 V_203 ( ( V_204 ) ) = V_198 [ V_103 ] ;
const struct V_205 * V_206 ;
struct V_14 V_15 ;
enum V_207 V_208 ;
int error = 0 ;
V_206 = F_114 ( V_42 , V_103 , V_50 , V_105 ) ;
F_115 ( & V_15 ) ;
F_116 () ;
V_208 = V_206 -> V_209 ( V_42 , V_51 , V_2 , V_105 , V_197 , & V_15 ) ;
F_117 () ;
error = F_118 ( V_103 , V_105 , V_50 ,
V_51 , & V_2 , V_197 , V_208 ,
& V_15 , V_113 ) ;
F_119 () ;
return error ;
}
static int F_118 ( enum V_102 V_103 ,
union V_104 V_105 ,
enum V_139 V_50 ,
struct V_196 * V_51 ,
struct V_1 * * V_2 ,
void * V_197 ,
enum V_207 V_208 ,
struct V_14 * V_15 ,
T_3 V_113 )
{
int error ;
if ( 0 != ( error = F_120 ( V_103 , V_105 , V_50 ,
V_51 , * V_2 ,
V_197 , V_208 ,
V_15 , V_113 ) ) )
goto V_210;
switch ( V_208 ) {
case V_211 :
F_19 ( L_7
L_8 , V_43 , V_50 ,
V_103 , V_105 . V_7 ) ;
break;
case V_212 :
error = - V_38 ;
break;
case V_213 :
case V_214 :
* V_2 = NULL ;
break;
case V_215 :
break;
case V_216 :
F_121 ( L_9 ,
V_50 , V_105 . V_7 ) ;
break;
case V_217 :
F_122 ( L_10 ,
V_50 , V_103 , V_105 . V_7 ) ;
break;
case V_218 :
F_123 ( L_11 ,
V_50 , V_103 , V_105 . V_7 ) ;
F_124 () ;
break;
default:
F_123 ( L_12 ,
V_208 , V_50 , V_103 , V_105 . V_7 ) ;
F_124 () ;
break;
}
V_210:
return error ;
}
static int F_120 ( enum V_102 V_103 ,
union V_104 V_105 ,
enum V_139 V_50 ,
struct V_196 * V_51 ,
struct V_1 * V_2 ,
void * V_197 ,
enum V_207 V_208 ,
struct V_14 * V_15 ,
T_3 V_113 )
{
struct V_219 * V_220 = F_125 ( V_51 -> V_41 . V_40 ) ;
struct V_6 * V_7 = NULL , * V_221 ;
struct V_222 * V_223 ;
struct V_224 V_225 ;
struct V_226 * V_181 ;
struct V_10 * V_115 ;
unsigned long V_66 ;
struct V_227 * V_228 ;
int V_229 = 0 ;
int error = 0 ;
int V_13 ;
if ( V_48 != V_103 )
V_7 = V_197 ;
while ( NULL != ( V_228 = F_126 ( V_15 ) ) ) {
switch ( V_228 -> V_230 ) {
case V_231 :
break;
case V_232 :
if ( V_229 ) {
F_84 ( & V_2 -> V_100 , V_113 ) ;
V_229 = 0 ;
}
V_2 = V_228 -> V_233 . V_2 ;
F_127 ( V_2 -> V_17 . V_234 == NULL ) ;
F_128 ( V_51 , V_2 ) ;
break;
case V_235 :
F_70 ( V_15 , V_2 , V_228 -> V_233 . V_2 ) ;
break;
case V_236 :
F_129 ( & V_2 -> V_100 ) ;
break;
case V_101 :
if ( V_229 ) {
F_84 ( & V_2 -> V_100 , V_113 ) ;
V_229 = 0 ;
}
F_85 ( V_15 , V_2 ) ;
V_2 = NULL ;
break;
case V_98 :
F_78 ( V_15 , V_2 , V_228 -> V_233 . V_50 ) ;
break;
case V_237 :
error = F_130 ( & V_2 -> V_17 . V_25 ,
V_228 -> V_233 . T_2 , NULL ) ;
break;
case V_238 :
F_131 ( & V_2 -> V_17 . V_25 , V_228 -> V_233 . T_2 ) ;
F_132 ( & V_2 -> V_106 , V_228 -> V_233 . T_2 ) ;
F_52 ( & V_2 -> V_106 , V_52 ) ;
break;
case V_239 :
F_91 ( & V_2 -> V_106 , V_228 -> V_233 . V_7 ) ;
break;
case V_240 :
V_13 = V_228 -> V_233 . V_241 ;
error = F_8 ( V_2 , V_13 , V_15 ) ;
break;
case V_242 :
error = F_66 ( V_15 , V_2 ,
V_228 -> V_233 . V_7 ) ;
break;
case V_243 :
V_221 = F_133 ( V_2 , V_7 , V_52 ,
0 ) ;
if ( ! V_221 )
goto V_35;
F_11 ( V_15 , V_36 ,
F_14 ( V_221 ) ) ;
break;
case V_244 :
error = F_54 ( V_15 , V_2 , V_7 ,
V_228 -> V_233 . V_245 , V_113 ) ;
break;
case V_246 :
V_221 = F_134 ( V_2 , V_7 ) ;
if ( ! V_221 ) {
if ( V_228 -> V_233 . V_7 )
F_112 ( V_228 -> V_233 . V_7 ) ;
goto V_35;
}
F_11 ( V_15 , V_36 ,
F_14 ( V_221 ) ) ;
if ( V_228 -> V_233 . V_7 )
F_11 ( V_15 , V_36 ,
F_14 ( V_228 -> V_233 . V_7 ) ) ;
if ( V_221 -> V_11 ) {
V_221 -> V_11 -> V_185 ++ ;
V_2 -> V_183 = V_221 -> V_11 ;
}
if ( ( V_2 -> V_17 . V_247 !=
V_2 -> V_17 . V_234 ) &&
( V_2 -> V_184 > 0 ) ) {
F_11 ( V_15 ,
V_248 ,
F_50 () ) ;
}
break;
case V_249 :
V_2 -> V_76 = 0 ;
V_221 = F_135 ( V_2 , V_7 ) ;
if ( ! V_221 )
goto V_35;
F_11 ( V_15 , V_36 ,
F_14 ( V_221 ) ) ;
break;
case V_250 :
F_19 ( L_13 ,
V_43 , V_228 -> V_233 . V_7 , & V_2 -> V_106 ) ;
F_136 ( & V_2 -> V_106 , V_228 -> V_233 . V_7 ,
V_52 ) ;
break;
case V_97 :
F_19 ( L_14 ,
V_43 , V_228 -> V_233 . V_251 , & V_2 -> V_106 ) ;
F_90 ( & V_2 -> V_106 , V_228 -> V_233 . V_251 ) ;
break;
case V_36 :
if ( ! V_2 -> V_100 . V_252 ) {
F_137 ( & V_2 -> V_100 ) ;
V_229 = 1 ;
}
F_106 ( & V_2 -> V_100 , V_228 -> V_233 . V_7 , V_113 ) ;
break;
case V_253 :
V_223 = V_228 -> V_233 . V_223 ;
F_138 ( V_223 , V_113 ) ;
F_139 ( V_223 ) ;
break;
case V_254 :
F_140 ( & V_2 -> V_100 , V_228 -> V_233 . V_11 ,
V_255 ) ;
break;
case V_256 :
F_140 ( & V_2 -> V_100 , V_228 -> V_233 . V_11 ,
V_257 ) ;
break;
case V_258 :
F_1 ( V_2 , V_228 -> V_233 . T_2 ) ;
break;
case V_259 :
V_221 = F_2 ( V_2 , V_228 -> V_233 . T_2 ,
V_7 ) ;
if ( V_221 )
F_11 ( V_15 , V_36 ,
F_14 ( V_221 ) ) ;
break;
case V_260 :
F_7 ( V_2 , V_228 -> V_233 . T_2 ) ;
break;
case V_261 :
F_68 ( V_15 , V_2 , V_228 -> V_233 . V_7 ) ;
break;
case V_262 :
V_181 = & V_2 -> V_56 [ V_228 -> V_233 . V_263 ] ;
if ( F_141 ( V_181 ) )
break;
case V_264 :
V_181 = & V_2 -> V_56 [ V_228 -> V_233 . V_263 ] ;
V_66 = V_2 -> V_28 [ V_228 -> V_233 . V_263 ] ;
F_127 ( ! V_66 ) ;
V_181 -> V_265 = V_45 + V_66 ;
F_27 ( V_2 ) ;
F_142 ( V_181 ) ;
break;
case V_31 :
V_181 = & V_2 -> V_56 [ V_228 -> V_233 . V_263 ] ;
V_66 = V_2 -> V_28 [ V_228 -> V_233 . V_263 ] ;
if ( ! F_20 ( V_181 , V_45 + V_66 ) )
F_27 ( V_2 ) ;
break;
case V_37 :
V_181 = & V_2 -> V_56 [ V_228 -> V_233 . V_263 ] ;
if ( F_60 ( V_181 ) )
F_28 ( V_2 ) ;
break;
case V_266 :
V_7 = V_228 -> V_233 . V_7 ;
V_115 = F_69 ( V_2 ,
V_2 -> V_183 ) ;
V_2 -> V_183 = V_115 ;
V_7 -> V_11 = V_115 ;
V_115 -> V_185 ++ ;
F_143 ( V_2 , V_115 ) ;
break;
case V_267 :
F_104 ( V_2 ,
V_60 ,
L_15 ) ;
F_11 ( V_15 , V_31 ,
F_12 ( V_60 ) ) ;
break;
case V_268 :
F_104 ( V_2 ,
V_59 ,
L_16 ) ;
F_58 (t, &asoc->peer.transport_addr_list,
transports) {
F_144 ( & V_2 -> V_100 , V_115 ,
V_255 ) ;
}
F_11 ( V_15 ,
V_31 ,
F_12 ( V_59 ) ) ;
break;
case V_269 :
F_46 ( V_15 , V_2 , V_228 -> V_233 . T_2 ) ;
break;
case V_136 :
F_51 ( V_15 , V_2 , V_103 ,
V_105 , V_7 , V_228 -> V_233 . T_2 ) ;
break;
case V_270 :
V_2 -> V_184 ++ ;
break;
case V_271 :
V_2 -> V_184 = 0 ;
V_2 -> V_186 = 0 ;
F_58 (t, &asoc->peer.transport_addr_list,
transports) {
V_115 -> V_185 = 0 ;
}
break;
case V_272 :
F_145 ( & V_2 -> V_17 . V_25 ,
V_228 -> V_233 . T_2 ) ;
break;
case V_273 :
F_19 ( L_17 , V_43 ) ;
break;
case V_274 :
F_41 ( V_15 , V_2 ,
V_228 -> V_233 . V_11 , 0 ) ;
break;
case V_275 :
V_115 = V_228 -> V_233 . V_11 ;
F_5 ( V_115 , V_276 ) ;
break;
case V_277 :
V_115 = V_228 -> V_233 . V_11 ;
F_41 ( V_15 , V_2 ,
V_115 , 1 ) ;
V_115 -> V_79 = 1 ;
break;
case V_278 :
V_115 = V_228 -> V_233 . V_11 ;
F_62 ( V_15 , V_2 , V_115 , V_7 ) ;
break;
case V_279 :
F_57 ( V_15 , V_2 ) ;
break;
case V_280 :
V_115 = V_228 -> V_233 . V_11 ;
F_43 ( V_115 ) ;
break;
case V_281 :
F_59 ( V_15 , V_2 ) ;
break;
case V_282 :
error = V_228 -> V_233 . error ;
break;
case V_283 :
V_225 . V_284 = V_228 -> V_233 . V_285 ;
V_225 . V_33 = F_146 ( V_2 -> V_17 . V_34 +
V_2 -> V_100 . V_286 ) ;
V_225 . V_287 = 0 ;
V_225 . V_288 = 0 ;
V_7 -> V_289 . V_290 = & V_225 ;
F_11 ( V_15 , V_242 ,
F_14 ( V_7 ) ) ;
break;
case V_291 :
V_7 -> V_292 = 1 ;
if ( V_2 ) {
F_84 ( & V_2 -> V_100 , V_113 ) ;
V_229 = 0 ;
}
break;
case V_293 :
V_115 = V_228 -> V_233 . V_11 ;
V_115 -> V_124 = 1 ;
break;
case V_294 :
F_147 ( & V_2 -> V_106 , V_52 ) ;
break;
case V_295 :
F_148 ( & V_2 -> V_106 , V_228 -> V_233 . V_7 ,
V_52 ) ;
break;
case V_296 :
F_87 ( V_15 , V_2 , V_228 -> V_233 . V_7 ) ;
break;
case V_297 :
F_88 ( V_15 , V_2 , V_7 ) ;
break;
case V_298 :
V_2 -> V_17 . V_299 . V_300 = 0 ;
break;
case V_301 :
F_95 ( V_2 ) ;
break;
case V_302 :
F_61 ( V_15 , V_2 ) ;
break;
case V_248 :
V_115 = V_2 -> V_17 . V_247 ;
V_2 -> V_17 . V_247 = V_2 -> V_17 . V_234 ;
F_84 ( & V_2 -> V_100 , V_113 ) ;
V_229 = 0 ;
V_2 -> V_17 . V_247 = V_115 ;
break;
case V_134 :
F_100 ( V_2 , V_228 -> V_233 . error ) ;
break;
case V_303 :
F_101 ( V_15 , V_2 ,
V_228 -> V_233 . T_4 ) ;
break;
case V_304 :
F_102 ( V_15 , V_2 ) ;
break;
case V_305 :
error = F_149 ( V_2 ,
V_52 ) ;
break;
case V_306 :
V_2 -> V_17 . V_299 . V_300 = V_228 -> V_233 . T_2 ;
break;
case V_307 :
if ( ! V_2 -> V_100 . V_252 ) {
F_137 ( & V_2 -> V_100 ) ;
V_229 = 1 ;
}
F_105 ( V_2 , V_228 -> V_233 . V_189 , V_113 ) ;
break;
case V_308 :
F_107 ( V_2 ) ;
break;
case V_309 :
F_150 ( V_2 ) ;
break;
case V_310 :
if ( V_2 && V_229 ) {
F_84 ( & V_2 -> V_100 , V_113 ) ;
V_229 = 0 ;
}
V_2 = V_228 -> V_233 . V_2 ;
break;
default:
F_122 ( L_18 ,
V_228 -> V_230 ) ;
break;
}
if ( error )
break;
}
V_311:
if ( V_2 && V_107 == V_103 && V_7 ) {
if ( V_7 -> V_312 || V_7 -> V_313 )
F_84 ( & V_2 -> V_100 , V_113 ) ;
} else if ( V_229 )
F_84 ( & V_2 -> V_100 , V_113 ) ;
if ( V_220 -> V_314 )
V_220 -> V_314 = 0 ;
return error ;
V_35:
error = - V_38 ;
goto V_311;
}
