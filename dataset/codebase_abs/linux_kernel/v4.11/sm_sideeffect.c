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
T_7 * V_107 ,
T_8 V_108 )
{
int error ;
if ( ! F_55 ( V_2 , V_7 , F_56 ( V_7 ) , V_107 , V_108 ) )
error = - V_37 ;
else
error = 0 ;
return error ;
}
static void F_57 ( T_2 * V_109 ,
struct V_1 * V_2 )
{
struct V_10 * V_110 ;
F_58 (t, &asoc->peer.transport_addr_list, transports)
F_43 ( V_110 ) ;
}
static void F_59 ( T_2 * V_109 ,
struct V_1 * V_2 )
{
struct V_10 * V_110 ;
F_58 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_60 ( & V_110 -> V_65 ) )
F_25 ( V_110 ) ;
}
}
static void F_61 ( T_2 * V_109 ,
struct V_1 * V_2 )
{
struct V_10 * V_110 ;
F_58 (t, &asoc->peer.transport_addr_list,
transports) {
if ( F_60 ( & V_110 -> V_43 ) )
F_25 ( V_110 ) ;
}
}
static void F_62 ( T_2 * V_109 ,
struct V_1 * V_2 ,
struct V_10 * V_110 ,
struct V_6 * V_7 )
{
T_9 * V_111 ;
int V_112 = 0 ;
V_110 -> V_76 = 0 ;
if ( V_110 -> V_2 -> V_49 < V_113 )
V_110 -> V_2 -> V_74 = 0 ;
V_110 -> V_77 = 0 ;
if ( ( V_110 -> V_49 == V_75 ) || ( V_110 -> V_49 == V_78 ) ) {
V_112 = 1 ;
F_42 ( V_2 , V_110 , V_114 ,
V_115 ) ;
}
if ( V_110 -> V_49 == V_116 )
F_42 ( V_2 , V_110 , V_114 ,
V_115 ) ;
if ( V_110 -> V_117 )
F_63 ( V_110 ) ;
if ( V_110 -> V_118 == 0 )
V_110 -> V_118 = 1 ;
V_111 = ( T_9 * ) V_7 -> V_119 -> V_56 ;
F_64 ( V_110 , ( V_44 - V_111 -> V_120 ) ) ;
F_43 ( V_110 ) ;
if ( V_112 && V_2 -> V_19 . V_121 == 1 )
F_65 ( V_110 ) ;
}
static int F_66 ( T_2 * V_109 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_122 = 0 ;
if ( F_67 ( & V_2 -> V_98 , V_7 ) ) {
struct V_41 * V_41 = F_16 ( V_2 -> V_40 . V_39 ) ;
V_122 = F_22 ( V_41 , V_69 ,
F_38 ( V_123 ) ,
V_2 -> V_49 , V_2 -> V_50 , V_2 , NULL ,
V_51 ) ;
}
return V_122 ;
}
static void F_68 ( T_2 * V_109 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_10 * V_110 ;
if ( V_7 -> V_11 )
V_110 = V_7 -> V_11 ;
else {
V_110 = F_69 ( V_2 ,
V_2 -> V_124 ) ;
V_7 -> V_11 = V_110 ;
}
V_2 -> V_124 = V_110 ;
V_2 -> V_27 [ V_59 ] = V_110 -> V_89 ;
}
static void F_70 ( T_2 * V_109 ,
struct V_1 * V_2 ,
T_10 V_49 )
{
struct V_38 * V_39 = V_2 -> V_40 . V_39 ;
V_2 -> V_49 = V_49 ;
F_19 ( L_4 , V_42 , V_2 , V_125 [ V_49 ] ) ;
if ( F_71 ( V_39 , V_126 ) ) {
if ( F_72 ( V_2 , V_127 ) && F_73 ( V_39 , V_128 ) )
V_39 -> V_129 = V_130 ;
if ( F_72 ( V_2 , V_131 ) &&
F_73 ( V_39 , V_127 ) ) {
V_39 -> V_129 = V_132 ;
V_39 -> V_133 |= V_134 ;
}
}
if ( F_72 ( V_2 , V_135 ) ) {
V_2 -> V_27 [ V_58 ] =
V_2 -> V_136 ;
V_2 -> V_27 [ V_57 ] =
V_2 -> V_136 ;
}
if ( F_72 ( V_2 , V_127 ) ||
F_72 ( V_2 , V_128 ) ||
F_72 ( V_2 , V_131 ) ) {
if ( F_74 ( & V_2 -> V_137 ) )
F_75 ( & V_2 -> V_137 ) ;
if ( ! F_71 ( V_39 , V_138 ) )
V_39 -> V_139 ( V_39 ) ;
}
if ( F_72 ( V_2 , V_140 ) &&
! F_76 ( & V_2 -> V_98 ) )
F_77 ( & V_2 -> V_98 , V_51 ) ;
}
static void F_78 ( T_2 * V_109 ,
struct V_1 * V_2 )
{
struct V_38 * V_39 = V_2 -> V_40 . V_39 ;
if ( F_71 ( V_39 , V_126 ) && F_73 ( V_39 , V_141 ) &&
( ! V_2 -> V_142 ) && ( V_39 -> V_133 != V_143 ) )
return;
F_79 ( V_2 ) ;
}
static void F_80 ( T_2 * V_109 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_10 * V_110 ;
V_110 = F_69 ( V_2 , V_7 -> V_11 ) ;
V_2 -> V_27 [ V_60 ] = V_110 -> V_89 ;
V_7 -> V_11 = V_110 ;
}
static void F_81 ( T_2 * V_109 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_144 * V_145 ;
struct V_91 * V_146 ;
while ( V_7 -> V_147 > V_7 -> V_119 -> V_56 ) {
V_145 = (struct V_144 * ) ( V_7 -> V_119 -> V_56 ) ;
V_146 = F_82 ( V_2 , V_7 , 0 ,
V_51 ) ;
if ( ! V_146 )
return;
F_83 ( & V_2 -> V_102 , V_146 ) ;
switch ( V_145 -> V_148 ) {
case V_149 :
{
T_11 * V_150 ;
V_150 = ( T_11 * ) V_145 -> V_151 ;
switch ( V_150 -> type ) {
case V_152 :
if ( V_2 -> V_19 . V_153 == 0 )
break;
V_2 -> V_19 . V_153 = 0 ;
F_11 ( V_109 , V_36 ,
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
static void F_84 ( struct V_154 * V_102 ,
struct V_6 * V_7 )
{
struct V_155 * V_156 ;
F_85 (skip, chunk) {
F_86 ( V_102 , F_87 ( V_156 -> V_157 ) , F_87 ( V_156 -> V_158 ) ) ;
}
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_10 * V_110 ;
struct V_159 * V_160 ;
struct V_159 * V_142 ;
F_89 (pos, temp, &asoc->peer.transport_addr_list) {
V_110 = F_90 ( V_160 , struct V_10 , V_161 ) ;
if ( ! F_91 ( & V_110 -> V_85 ,
& V_2 -> V_19 . V_162 ) ) {
F_92 ( V_2 , V_110 ) ;
}
}
}
static void F_93 ( struct V_1 * V_2 , int error )
{
struct V_38 * V_39 = V_2 -> V_40 . V_39 ;
if ( ! F_71 ( V_39 , V_138 ) )
V_39 -> V_52 = error ;
}
static void F_94 ( T_2 * V_14 ,
struct V_1 * V_2 ,
T_12 V_49 )
{
struct V_91 * V_146 ;
V_146 = F_47 ( V_2 , 0 , V_49 , 0 ,
V_2 -> V_163 . V_164 ,
V_2 -> V_163 . V_165 ,
NULL , V_51 ) ;
if ( V_146 )
F_83 ( & V_2 -> V_102 , V_146 ) ;
}
static void F_95 ( T_2 * V_14 ,
struct V_1 * V_2 )
{
struct V_91 * V_146 ;
V_146 = F_96 ( V_2 , V_51 ) ;
if ( V_146 )
F_83 ( & V_2 -> V_102 , V_146 ) ;
}
static void F_97 ( struct V_1 * V_2 ,
T_3 V_166 ,
char * V_167 )
{
struct V_10 * V_110 ;
V_110 = V_2 -> V_168 ;
V_2 -> V_169 ++ ;
if ( V_110 -> V_170 > ( V_2 -> V_171 + 1 ) ) {
V_2 -> V_27 [ V_166 ] *= 2 ;
if ( V_2 -> V_27 [ V_166 ] > V_2 -> V_172 ) {
V_2 -> V_27 [ V_166 ] = V_2 -> V_172 ;
}
V_2 -> V_171 ++ ;
F_19 ( L_5
L_6 , V_42 , V_167 ,
V_2 -> V_169 , V_2 -> V_171 ,
V_2 -> V_27 [ V_166 ] ) ;
}
}
static void F_98 ( struct V_1 * V_2 ,
struct V_173 * V_174 , T_8 V_108 )
{
struct V_6 * V_7 ;
F_58 (chunk, &msg->chunks, frag_list)
F_99 ( & V_2 -> V_98 , V_7 , V_108 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_41 * V_41 = F_16 ( V_2 -> V_40 . V_39 ) ;
if ( ! F_101 ( & V_2 -> V_175 ) ) {
struct V_159 * V_176 = V_2 -> V_175 . V_177 ;
struct V_6 * V_178 = F_90 ( V_176 ,
struct V_6 , V_179 ) ;
F_102 ( V_176 ) ;
F_103 ( V_178 ) ;
if ( F_104 ( V_41 , V_2 , V_178 ) )
F_105 ( V_178 ) ;
else
V_2 -> V_180 = V_178 ;
}
}
int F_22 ( struct V_41 * V_41 , T_5 V_100 , T_6 V_101 ,
T_10 V_49 ,
struct V_181 * V_50 ,
struct V_1 * V_2 ,
void * V_182 ,
T_8 V_108 )
{
T_2 V_14 ;
const T_13 * V_183 ;
T_14 V_184 ;
int error = 0 ;
typedef const char * (F_106)( T_6 );
static F_106 * V_185 [] = {
NULL , V_186 , V_187 , V_188 , V_189 ,
} ;
F_106 * T_15 V_190 ( ( V_191 ) ) = V_185 [ V_100 ] ;
V_183 = F_107 ( V_41 , V_100 , V_49 , V_101 ) ;
F_108 ( & V_14 ) ;
F_109 () ;
V_184 = V_183 -> V_192 ( V_41 , V_50 , V_2 , V_101 , V_182 , & V_14 ) ;
F_110 () ;
error = F_111 ( V_100 , V_101 , V_49 ,
V_50 , & V_2 , V_182 , V_184 ,
& V_14 , V_108 ) ;
F_112 () ;
return error ;
}
static int F_111 ( T_5 V_100 , T_6 V_101 ,
T_10 V_49 ,
struct V_181 * V_50 ,
struct V_1 * * V_2 ,
void * V_182 ,
T_14 V_184 ,
T_2 * V_14 ,
T_8 V_108 )
{
int error ;
if ( 0 != ( error = F_113 ( V_100 , V_101 , V_49 ,
V_50 , * V_2 ,
V_182 , V_184 ,
V_14 , V_108 ) ) )
goto V_193;
switch ( V_184 ) {
case V_194 :
F_19 ( L_7
L_8 , V_42 , V_49 ,
V_100 , V_101 . V_7 ) ;
break;
case V_195 :
error = - V_37 ;
break;
case V_196 :
case V_197 :
* V_2 = NULL ;
break;
case V_198 :
break;
case V_199 :
F_114 ( L_9 ,
V_49 , V_101 . V_7 ) ;
break;
case V_200 :
F_115 ( L_10 ,
V_49 , V_100 , V_101 . V_7 ) ;
break;
case V_201 :
F_116 ( L_11 ,
V_49 , V_100 , V_101 . V_7 ) ;
F_117 () ;
break;
default:
F_116 ( L_12 ,
V_184 , V_49 , V_100 , V_101 . V_7 ) ;
F_117 () ;
break;
}
V_193:
return error ;
}
static int F_113 ( T_5 V_100 ,
T_6 V_101 ,
T_10 V_49 ,
struct V_181 * V_50 ,
struct V_1 * V_2 ,
void * V_182 ,
T_14 V_184 ,
T_2 * V_14 ,
T_8 V_108 )
{
struct V_38 * V_39 = V_50 -> V_40 . V_39 ;
struct V_202 * V_203 = F_118 ( V_39 ) ;
int error = 0 ;
int V_13 ;
T_16 * V_204 ;
struct V_6 * V_205 ;
struct V_6 * V_7 = NULL ;
struct V_206 * V_207 ;
struct V_208 * V_166 ;
unsigned long V_64 ;
struct V_10 * V_110 ;
struct V_209 V_210 ;
int V_211 = 0 ;
if ( V_47 != V_100 )
V_7 = V_182 ;
while ( NULL != ( V_204 = F_119 ( V_14 ) ) ) {
switch ( V_204 -> V_212 ) {
case V_213 :
break;
case V_214 :
if ( V_211 ) {
F_77 ( & V_2 -> V_98 , V_108 ) ;
V_211 = 0 ;
}
V_2 = V_204 -> V_215 . V_2 ;
F_120 ( V_2 -> V_19 . V_216 == NULL ) ;
F_121 ( V_50 , V_2 ) ;
break;
case V_217 :
F_122 ( V_2 , V_204 -> V_215 . V_2 ) ;
break;
case V_218 :
F_123 ( & V_2 -> V_98 ) ;
break;
case V_99 :
if ( V_211 ) {
F_77 ( & V_2 -> V_98 , V_108 ) ;
V_211 = 0 ;
}
F_78 ( V_14 , V_2 ) ;
V_2 = NULL ;
break;
case V_96 :
F_70 ( V_14 , V_2 , V_204 -> V_215 . V_49 ) ;
break;
case V_219 :
error = F_124 ( & V_2 -> V_19 . V_24 ,
V_204 -> V_215 . T_4 , NULL ) ;
break;
case V_220 :
F_125 ( & V_2 -> V_19 . V_24 , V_204 -> V_215 . T_4 ) ;
F_126 ( & V_2 -> V_102 , V_204 -> V_215 . T_4 ) ;
F_52 ( & V_2 -> V_102 , V_51 ) ;
break;
case V_221 :
F_84 ( & V_2 -> V_102 , V_204 -> V_215 . V_7 ) ;
break;
case V_222 :
V_13 = V_204 -> V_215 . V_223 ;
error = F_8 ( V_2 , V_13 , V_14 ) ;
break;
case V_224 :
error = F_66 ( V_14 , V_2 ,
V_204 -> V_215 . V_7 ) ;
break;
case V_225 :
V_205 = F_127 ( V_2 , V_7 , V_51 ,
0 ) ;
if ( ! V_205 )
goto V_34;
F_11 ( V_14 , V_35 ,
F_14 ( V_205 ) ) ;
break;
case V_226 :
error = F_54 ( V_14 , V_2 , V_7 ,
V_204 -> V_215 . V_227 , V_108 ) ;
break;
case V_228 :
V_205 = F_128 ( V_2 , V_7 ) ;
if ( ! V_205 ) {
if ( V_204 -> V_215 . V_7 )
F_105 ( V_204 -> V_215 . V_7 ) ;
goto V_34;
}
F_11 ( V_14 , V_35 ,
F_14 ( V_205 ) ) ;
if ( V_204 -> V_215 . V_7 )
F_11 ( V_14 , V_35 ,
F_14 ( V_204 -> V_215 . V_7 ) ) ;
if ( V_205 -> V_11 ) {
V_205 -> V_11 -> V_170 ++ ;
V_2 -> V_168 = V_205 -> V_11 ;
}
if ( ( V_2 -> V_19 . V_229 !=
V_2 -> V_19 . V_216 ) &&
( V_2 -> V_169 > 0 ) ) {
F_11 ( V_14 ,
V_230 ,
F_50 () ) ;
}
break;
case V_231 :
V_2 -> V_74 = 0 ;
V_205 = F_129 ( V_2 , V_7 ) ;
if ( ! V_205 )
goto V_34;
F_11 ( V_14 , V_35 ,
F_14 ( V_205 ) ) ;
break;
case V_232 :
F_19 ( L_13 ,
V_42 , V_204 -> V_215 . V_7 , & V_2 -> V_102 ) ;
F_130 ( & V_2 -> V_102 , V_204 -> V_215 . V_7 ,
V_51 ) ;
break;
case V_95 :
F_19 ( L_14 ,
V_42 , V_204 -> V_215 . V_233 , & V_2 -> V_102 ) ;
F_83 ( & V_2 -> V_102 , V_204 -> V_215 . V_233 ) ;
break;
case V_35 :
if ( ! V_2 -> V_98 . V_234 ) {
F_131 ( & V_2 -> V_98 ) ;
V_211 = 1 ;
}
F_99 ( & V_2 -> V_98 , V_204 -> V_215 . V_7 , V_108 ) ;
break;
case V_235 :
V_207 = V_204 -> V_215 . V_207 ;
F_132 ( V_207 , V_108 ) ;
F_133 ( V_207 ) ;
break;
case V_236 :
F_134 ( & V_2 -> V_98 , V_204 -> V_215 . V_11 ,
V_237 ) ;
break;
case V_238 :
F_134 ( & V_2 -> V_98 , V_204 -> V_215 . V_11 ,
V_239 ) ;
break;
case V_240 :
F_1 ( V_2 , V_204 -> V_215 . T_4 ) ;
break;
case V_241 :
V_205 = F_2 ( V_2 , V_204 -> V_215 . T_4 ,
V_7 ) ;
if ( V_205 )
F_11 ( V_14 , V_35 ,
F_14 ( V_205 ) ) ;
break;
case V_242 :
F_7 ( V_2 , V_204 -> V_215 . T_4 ) ;
break;
case V_243 :
F_68 ( V_14 , V_2 , V_204 -> V_215 . V_7 ) ;
break;
case V_244 :
V_166 = & V_2 -> V_54 [ V_204 -> V_215 . V_245 ] ;
if ( F_135 ( V_166 ) )
break;
case V_246 :
V_166 = & V_2 -> V_54 [ V_204 -> V_215 . V_245 ] ;
V_64 = V_2 -> V_27 [ V_204 -> V_215 . V_245 ] ;
F_120 ( ! V_64 ) ;
V_166 -> V_247 = V_44 + V_64 ;
F_27 ( V_2 ) ;
F_136 ( V_166 ) ;
break;
case V_30 :
V_166 = & V_2 -> V_54 [ V_204 -> V_215 . V_245 ] ;
V_64 = V_2 -> V_27 [ V_204 -> V_215 . V_245 ] ;
if ( ! F_20 ( V_166 , V_44 + V_64 ) )
F_27 ( V_2 ) ;
break;
case V_36 :
V_166 = & V_2 -> V_54 [ V_204 -> V_215 . V_245 ] ;
if ( F_60 ( V_166 ) )
F_28 ( V_2 ) ;
break;
case V_248 :
V_7 = V_204 -> V_215 . V_7 ;
V_110 = F_69 ( V_2 ,
V_2 -> V_168 ) ;
V_2 -> V_168 = V_110 ;
V_7 -> V_11 = V_110 ;
V_110 -> V_170 ++ ;
F_137 ( V_2 , V_110 ) ;
break;
case V_249 :
F_97 ( V_2 ,
V_58 ,
L_15 ) ;
F_11 ( V_14 , V_30 ,
F_12 ( V_58 ) ) ;
break;
case V_250 :
F_97 ( V_2 ,
V_57 ,
L_16 ) ;
F_58 (t, &asoc->peer.transport_addr_list,
transports) {
F_138 ( & V_2 -> V_98 , V_110 ,
V_237 ) ;
}
F_11 ( V_14 ,
V_30 ,
F_12 ( V_57 ) ) ;
break;
case V_251 :
F_46 ( V_14 , V_2 , V_204 -> V_215 . V_122 ) ;
break;
case V_252 :
F_51 ( V_14 , V_2 , V_100 ,
V_101 , V_7 , V_204 -> V_215 . V_122 ) ;
break;
case V_253 :
V_2 -> V_169 ++ ;
break;
case V_254 :
V_2 -> V_169 = 0 ;
V_2 -> V_171 = 0 ;
F_58 (t, &asoc->peer.transport_addr_list,
transports) {
V_110 -> V_170 = 0 ;
}
break;
case V_255 :
F_139 ( & V_2 -> V_19 . V_24 ,
V_204 -> V_215 . T_4 ) ;
break;
case V_256 :
F_19 ( L_17 , V_42 ) ;
break;
case V_257 :
F_41 ( V_14 , V_2 ,
V_204 -> V_215 . V_11 , 0 ) ;
break;
case V_258 :
V_110 = V_204 -> V_215 . V_11 ;
F_5 ( V_110 , V_259 ) ;
break;
case V_260 :
V_110 = V_204 -> V_215 . V_11 ;
F_41 ( V_14 , V_2 ,
V_110 , 1 ) ;
V_110 -> V_77 = 1 ;
break;
case V_261 :
V_110 = V_204 -> V_215 . V_11 ;
F_62 ( V_14 , V_2 , V_110 , V_7 ) ;
break;
case V_262 :
F_57 ( V_14 , V_2 ) ;
break;
case V_263 :
V_110 = V_204 -> V_215 . V_11 ;
F_43 ( V_110 ) ;
break;
case V_264 :
F_59 ( V_14 , V_2 ) ;
break;
case V_265 :
error = V_204 -> V_215 . error ;
break;
case V_266 :
V_210 . V_267 = V_204 -> V_215 . V_268 ;
V_210 . V_32 = V_2 -> V_19 . V_33 +
V_2 -> V_98 . V_269 ;
V_210 . V_270 = 0 ;
V_210 . V_271 = 0 ;
V_7 -> V_272 . V_273 = & V_210 ;
F_11 ( V_14 , V_224 ,
F_14 ( V_7 ) ) ;
break;
case V_274 :
V_7 -> V_275 = 1 ;
if ( V_2 ) {
F_77 ( & V_2 -> V_98 , V_108 ) ;
V_211 = 0 ;
}
break;
case V_276 :
V_110 = V_204 -> V_215 . V_11 ;
V_110 -> V_118 = 1 ;
break;
case V_277 :
F_140 ( & V_2 -> V_102 , V_51 ) ;
break;
case V_278 :
F_141 ( & V_2 -> V_102 , V_204 -> V_215 . V_7 ,
V_51 ) ;
break;
case V_279 :
F_80 ( V_14 , V_2 , V_204 -> V_215 . V_7 ) ;
break;
case V_280 :
F_81 ( V_14 , V_2 , V_7 ) ;
break;
case V_281 :
V_2 -> V_19 . V_282 . V_283 = 0 ;
break;
case V_284 :
F_88 ( V_2 ) ;
break;
case V_285 :
F_61 ( V_14 , V_2 ) ;
break;
case V_230 :
V_110 = V_2 -> V_19 . V_229 ;
V_2 -> V_19 . V_229 = V_2 -> V_19 . V_216 ;
F_77 ( & V_2 -> V_98 , V_108 ) ;
V_211 = 0 ;
V_2 -> V_19 . V_229 = V_110 ;
break;
case V_286 :
F_93 ( V_2 , V_204 -> V_215 . error ) ;
break;
case V_287 :
F_94 ( V_14 , V_2 ,
V_204 -> V_215 . T_12 ) ;
break;
case V_288 :
F_95 ( V_14 , V_2 ) ;
break;
case V_289 :
error = F_142 ( V_2 ,
V_51 ) ;
break;
case V_290 :
V_2 -> V_19 . V_282 . V_283 = V_204 -> V_215 . T_4 ;
break;
case V_291 :
if ( ! V_2 -> V_98 . V_234 ) {
F_131 ( & V_2 -> V_98 ) ;
V_211 = 1 ;
}
F_98 ( V_2 , V_204 -> V_215 . V_174 , V_108 ) ;
break;
case V_292 :
F_100 ( V_2 ) ;
break;
case V_293 :
F_143 ( V_2 ) ;
break;
case V_294 :
V_2 = V_204 -> V_215 . V_2 ;
break;
default:
F_115 ( L_18 ,
V_204 -> V_212 ) ;
break;
}
if ( error )
break;
}
V_295:
if ( V_2 && V_103 == V_100 && V_7 ) {
if ( V_7 -> V_296 || V_7 -> V_297 )
F_77 ( & V_2 -> V_98 , V_108 ) ;
} else if ( V_211 )
F_77 ( & V_2 -> V_98 , V_108 ) ;
if ( V_203 -> V_298 )
V_203 -> V_298 = 0 ;
return error ;
V_34:
error = - V_37 ;
goto V_295;
}
