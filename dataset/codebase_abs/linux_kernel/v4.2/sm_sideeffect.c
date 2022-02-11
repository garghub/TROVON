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
F_19 ( L_2 , V_40 ,
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
if ( ( V_11 -> V_48 == V_72 ) &&
( V_2 -> V_73 < V_11 -> V_74 ) &&
( V_11 -> V_69 > V_2 -> V_73 ) ) {
F_40 ( V_2 , V_11 ,
V_75 ,
0 ) ;
F_41 ( V_14 , V_11 ) ;
}
if ( V_11 -> V_48 != V_68 &&
( V_11 -> V_69 > V_11 -> V_74 ) ) {
F_19 ( L_3 ,
V_40 , V_2 , & V_11 -> V_76 . V_77 ) ;
F_40 ( V_2 , V_11 ,
V_78 ,
V_79 ) ;
}
if ( ! V_66 || V_11 -> V_70 ) {
V_11 -> V_80 = F_42 ( ( V_11 -> V_80 * 2 ) , V_11 -> V_2 -> V_81 ) ;
F_43 ( V_2 , V_11 ) ;
}
}
static void F_44 ( T_2 * V_14 ,
struct V_1 * V_2 ,
unsigned int error )
{
struct V_82 * V_83 ;
V_83 = F_45 ( V_2 , 0 , V_84 ,
( V_85 ) error , 0 , 0 , NULL ,
V_50 ) ;
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
struct V_6 * abort ;
F_50 ( & V_2 -> V_93 , V_50 ) ;
if ( V_91 == V_94 && V_92 . V_7 == V_95 )
V_83 = F_45 ( V_2 , 0 , V_96 ,
( V_85 ) error , 0 , 0 , V_7 ,
V_50 ) ;
else
V_83 = F_45 ( V_2 , 0 , V_96 ,
( V_85 ) error , 0 , 0 , NULL ,
V_50 ) ;
if ( V_83 )
F_11 ( V_14 , V_86 ,
F_46 ( V_83 ) ) ;
if ( V_2 -> V_67 >= V_2 -> V_97 ) {
abort = F_51 ( V_2 , V_7 ) ;
if ( abort )
F_11 ( V_14 , V_34 ,
F_14 ( abort ) ) ;
}
F_11 ( V_14 , V_87 ,
F_47 ( V_88 ) ) ;
V_2 -> V_89 . error = error ;
F_11 ( V_14 , V_90 , F_48 () ) ;
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
if ( F_59 ( & V_101 -> V_41 ) )
F_25 ( V_101 ) ;
}
}
static void F_41 ( T_2 * V_100 ,
struct V_10 * V_101 )
{
if ( ! F_20 ( & V_101 -> V_61 , F_57 ( V_101 ) ) )
F_21 ( V_101 ) ;
}
static void F_61 ( T_2 * V_100 ,
struct V_1 * V_2 ,
struct V_10 * V_101 ,
struct V_6 * V_7 )
{
T_8 * V_102 ;
int V_103 = 0 ;
V_101 -> V_69 = 0 ;
if ( V_101 -> V_2 -> V_48 < V_104 )
V_101 -> V_2 -> V_67 = 0 ;
V_101 -> V_70 = 0 ;
if ( ( V_101 -> V_48 == V_68 ) || ( V_101 -> V_48 == V_71 ) ) {
V_103 = 1 ;
F_40 ( V_2 , V_101 , V_105 ,
V_106 ) ;
}
if ( V_101 -> V_48 == V_107 )
F_40 ( V_2 , V_101 , V_105 ,
V_106 ) ;
if ( V_101 -> V_108 )
F_62 ( V_101 -> V_108 ) ;
if ( V_101 -> V_109 == 0 )
V_101 -> V_109 = 1 ;
V_102 = ( T_8 * ) V_7 -> V_110 -> V_54 ;
F_63 ( V_101 , ( V_42 - V_102 -> V_111 ) ) ;
if ( ! F_20 ( & V_101 -> V_61 , F_57 ( V_101 ) ) )
F_21 ( V_101 ) ;
if ( V_103 && V_2 -> V_19 . V_112 == 1 )
F_64 ( V_101 ) ;
}
static int F_65 ( T_2 * V_100 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
int V_113 = 0 ;
if ( F_66 ( & V_2 -> V_89 , V_7 ) ) {
struct V_37 * V_37 = F_16 ( V_2 -> V_38 . V_39 ) ;
V_113 = F_22 ( V_37 , V_64 ,
F_37 ( V_114 ) ,
V_2 -> V_48 , V_2 -> V_49 , V_2 , NULL ,
V_50 ) ;
}
return V_113 ;
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
V_2 -> V_115 ) ;
V_7 -> V_11 = V_101 ;
}
V_2 -> V_115 = V_101 ;
V_2 -> V_27 [ V_57 ] = V_101 -> V_80 ;
}
static void F_69 ( T_2 * V_100 ,
struct V_1 * V_2 ,
T_9 V_48 )
{
struct V_116 * V_39 = V_2 -> V_38 . V_39 ;
V_2 -> V_48 = V_48 ;
F_19 ( L_4 , V_40 , V_2 , V_117 [ V_48 ] ) ;
if ( F_70 ( V_39 , V_118 ) ) {
if ( F_71 ( V_2 , V_119 ) && F_72 ( V_39 , V_120 ) )
V_39 -> V_121 = V_122 ;
if ( F_71 ( V_2 , V_123 ) &&
F_72 ( V_39 , V_119 ) )
V_39 -> V_124 |= V_125 ;
}
if ( F_71 ( V_2 , V_126 ) ) {
V_2 -> V_27 [ V_56 ] =
V_2 -> V_127 ;
V_2 -> V_27 [ V_55 ] =
V_2 -> V_127 ;
}
if ( F_71 ( V_2 , V_119 ) ||
F_71 ( V_2 , V_120 ) ||
F_71 ( V_2 , V_123 ) ) {
if ( F_73 ( & V_2 -> V_128 ) )
F_74 ( & V_2 -> V_128 ) ;
if ( ! F_70 ( V_39 , V_129 ) )
V_39 -> V_130 ( V_39 ) ;
}
}
static void F_75 ( T_2 * V_100 ,
struct V_1 * V_2 )
{
struct V_116 * V_39 = V_2 -> V_38 . V_39 ;
if ( F_70 ( V_39 , V_118 ) && F_72 ( V_39 , V_131 ) &&
( ! V_2 -> V_132 ) && ( V_39 -> V_124 != V_133 ) )
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
V_2 -> V_27 [ V_58 ] = V_101 -> V_80 ;
V_7 -> V_11 = V_101 ;
}
static void F_79 ( T_2 * V_100 ,
struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_134 * V_135 ;
struct V_82 * V_136 ;
while ( V_7 -> V_137 > V_7 -> V_110 -> V_54 ) {
V_135 = (struct V_134 * ) ( V_7 -> V_110 -> V_54 ) ;
V_136 = F_80 ( V_2 , V_7 , 0 ,
V_50 ) ;
if ( ! V_136 )
return;
F_81 ( & V_2 -> V_93 , V_136 ) ;
switch ( V_135 -> V_138 ) {
case V_139 :
{
T_10 * V_140 ;
V_140 = ( T_10 * ) V_135 -> V_141 ;
switch ( V_140 -> type ) {
case V_142 :
if ( V_2 -> V_19 . V_143 == 0 )
break;
V_2 -> V_19 . V_143 = 0 ;
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
static void F_82 ( struct V_144 * V_93 ,
struct V_6 * V_7 )
{
struct V_145 * V_146 ;
F_83 (skip, chunk) {
F_84 ( V_93 , F_85 ( V_146 -> V_147 ) , F_85 ( V_146 -> V_148 ) ) ;
}
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_10 * V_101 ;
struct V_149 * V_150 ;
struct V_149 * V_132 ;
F_87 (pos, temp, &asoc->peer.transport_addr_list) {
V_101 = F_88 ( V_150 , struct V_10 , V_151 ) ;
if ( ! F_89 ( & V_101 -> V_76 ,
& V_2 -> V_19 . V_152 ) ) {
F_90 ( V_2 , & V_101 -> V_76 ) ;
}
}
}
static void F_91 ( struct V_1 * V_2 , int error )
{
struct V_116 * V_39 = V_2 -> V_38 . V_39 ;
if ( ! F_70 ( V_39 , V_129 ) )
V_39 -> V_51 = error ;
}
static void F_92 ( T_2 * V_14 ,
struct V_1 * V_2 ,
T_11 V_48 )
{
struct V_82 * V_136 ;
V_136 = F_45 ( V_2 , 0 , V_48 , 0 ,
V_2 -> V_153 . V_154 ,
V_2 -> V_153 . V_155 ,
NULL , V_50 ) ;
if ( V_136 )
F_81 ( & V_2 -> V_93 , V_136 ) ;
}
static void F_93 ( T_2 * V_14 ,
struct V_1 * V_2 )
{
struct V_82 * V_136 ;
V_136 = F_94 ( V_2 , V_50 ) ;
if ( V_136 )
F_81 ( & V_2 -> V_93 , V_136 ) ;
}
static void F_95 ( struct V_1 * V_2 ,
T_3 V_156 ,
char * V_157 )
{
struct V_10 * V_101 ;
V_101 = V_2 -> V_158 ;
V_2 -> V_159 ++ ;
if ( V_101 -> V_160 > ( V_2 -> V_161 + 1 ) ) {
V_2 -> V_27 [ V_156 ] *= 2 ;
if ( V_2 -> V_27 [ V_156 ] > V_2 -> V_162 ) {
V_2 -> V_27 [ V_156 ] = V_2 -> V_162 ;
}
V_2 -> V_161 ++ ;
F_19 ( L_5
L_6 , V_40 , V_157 ,
V_2 -> V_159 , V_2 -> V_161 ,
V_2 -> V_27 [ V_156 ] ) ;
}
}
static int F_96 ( struct V_1 * V_2 ,
struct V_163 * V_164 )
{
struct V_6 * V_7 ;
int error = 0 ;
F_56 (chunk, &msg->chunks, frag_list) {
error = F_97 ( & V_2 -> V_89 , V_7 ) ;
if ( error )
break;
}
return error ;
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_37 * V_37 = F_16 ( V_2 -> V_38 . V_39 ) ;
if ( ! F_99 ( & V_2 -> V_165 ) ) {
struct V_149 * V_166 = V_2 -> V_165 . V_167 ;
struct V_6 * V_168 = F_88 ( V_166 ,
struct V_6 , V_169 ) ;
F_100 ( V_166 ) ;
F_101 ( V_168 ) ;
if ( F_102 ( V_37 , V_2 , V_168 ) )
F_103 ( V_168 ) ;
else
V_2 -> V_170 = V_168 ;
}
}
int F_22 ( struct V_37 * V_37 , T_4 V_91 , T_5 V_92 ,
T_9 V_48 ,
struct V_171 * V_49 ,
struct V_1 * V_2 ,
void * V_172 ,
T_7 V_99 )
{
T_2 V_14 ;
const T_12 * V_173 ;
T_13 V_174 ;
int error = 0 ;
typedef const char * (F_104)( T_5 );
static F_104 * V_175 [] = {
NULL , V_176 , V_177 , V_178 , V_179 ,
} ;
F_104 * T_14 V_180 ( ( V_181 ) ) = V_175 [ V_91 ] ;
V_173 = F_105 ( V_37 , V_91 , V_48 , V_92 ) ;
F_106 ( & V_14 ) ;
F_107 () ;
V_174 = V_173 -> V_182 ( V_37 , V_49 , V_2 , V_92 , V_172 , & V_14 ) ;
F_108 () ;
error = F_109 ( V_91 , V_92 , V_48 ,
V_49 , V_2 , V_172 , V_174 ,
& V_14 , V_99 ) ;
F_110 () ;
return error ;
}
static int F_109 ( T_4 V_91 , T_5 V_92 ,
T_9 V_48 ,
struct V_171 * V_49 ,
struct V_1 * V_2 ,
void * V_172 ,
T_13 V_174 ,
T_2 * V_14 ,
T_7 V_99 )
{
int error ;
if ( 0 != ( error = F_111 ( V_91 , V_92 , V_48 ,
V_49 , V_2 ,
V_172 , V_174 ,
V_14 , V_99 ) ) )
goto V_183;
switch ( V_174 ) {
case V_184 :
F_19 ( L_7
L_8 , V_40 , V_48 ,
V_91 , V_92 . V_7 ) ;
break;
case V_185 :
error = - V_36 ;
break;
case V_186 :
break;
case V_187 :
case V_188 :
break;
case V_189 :
F_112 ( L_9 ,
V_48 , V_92 . V_7 ) ;
break;
case V_190 :
F_113 ( L_10 ,
V_48 , V_91 , V_92 . V_7 ) ;
break;
case V_191 :
F_114 ( L_11 ,
V_48 , V_91 , V_92 . V_7 ) ;
F_115 () ;
break;
default:
F_114 ( L_12 ,
V_174 , V_48 , V_91 , V_92 . V_7 ) ;
F_115 () ;
break;
}
V_183:
return error ;
}
static int F_111 ( T_4 V_91 ,
T_5 V_92 ,
T_9 V_48 ,
struct V_171 * V_49 ,
struct V_1 * V_2 ,
void * V_172 ,
T_13 V_174 ,
T_2 * V_14 ,
T_7 V_99 )
{
int error = 0 ;
int V_13 ;
T_15 * V_192 ;
struct V_6 * V_193 ;
struct V_6 * V_7 = NULL ;
struct V_194 * V_195 ;
struct V_196 * V_156 ;
unsigned long V_197 ;
struct V_10 * V_101 ;
struct V_198 V_199 ;
int V_200 = 0 ;
if ( V_46 != V_91 )
V_7 = V_172 ;
while ( NULL != ( V_192 = F_116 ( V_14 ) ) ) {
switch ( V_192 -> V_201 ) {
case V_202 :
break;
case V_203 :
if ( V_200 ) {
F_117 ( & V_2 -> V_89 ) ;
V_200 = 0 ;
}
V_2 = V_192 -> V_204 . V_2 ;
F_118 ( V_2 -> V_19 . V_205 == NULL ) ;
F_119 ( V_49 , V_2 ) ;
F_120 ( V_2 ) ;
break;
case V_206 :
F_121 ( V_2 , V_192 -> V_204 . V_2 ) ;
break;
case V_207 :
F_122 ( & V_2 -> V_89 ) ;
break;
case V_90 :
if ( V_200 ) {
F_117 ( & V_2 -> V_89 ) ;
V_200 = 0 ;
}
F_75 ( V_14 , V_2 ) ;
V_2 = NULL ;
break;
case V_87 :
F_69 ( V_14 , V_2 , V_192 -> V_204 . V_48 ) ;
break;
case V_208 :
error = F_123 ( & V_2 -> V_19 . V_24 ,
V_192 -> V_204 . V_209 , NULL ) ;
break;
case V_210 :
F_124 ( & V_2 -> V_19 . V_24 , V_192 -> V_204 . V_209 ) ;
F_125 ( & V_2 -> V_93 , V_192 -> V_204 . V_209 ) ;
F_50 ( & V_2 -> V_93 , V_50 ) ;
break;
case V_211 :
F_82 ( & V_2 -> V_93 , V_192 -> V_204 . V_7 ) ;
break;
case V_212 :
V_13 = V_192 -> V_204 . V_213 ;
error = F_8 ( V_2 , V_13 , V_14 ) ;
break;
case V_214 :
error = F_65 ( V_14 , V_2 ,
V_192 -> V_204 . V_7 ) ;
break;
case V_215 :
V_193 = F_126 ( V_2 , V_7 , V_50 ,
0 ) ;
if ( ! V_193 )
goto V_33;
F_11 ( V_14 , V_34 ,
F_14 ( V_193 ) ) ;
break;
case V_216 :
error = F_52 ( V_14 , V_2 , V_7 ,
V_192 -> V_204 . V_217 , V_99 ) ;
break;
case V_218 :
V_193 = F_127 ( V_2 , V_7 ) ;
if ( ! V_193 ) {
if ( V_192 -> V_204 . V_7 )
F_103 ( V_192 -> V_204 . V_7 ) ;
goto V_33;
}
F_11 ( V_14 , V_34 ,
F_14 ( V_193 ) ) ;
if ( V_192 -> V_204 . V_7 )
F_11 ( V_14 , V_34 ,
F_14 ( V_192 -> V_204 . V_7 ) ) ;
if ( V_193 -> V_11 ) {
V_193 -> V_11 -> V_160 ++ ;
V_2 -> V_158 = V_193 -> V_11 ;
}
if ( ( V_2 -> V_19 . V_219 !=
V_2 -> V_19 . V_205 ) &&
( V_2 -> V_159 > 0 ) ) {
F_11 ( V_14 ,
V_220 ,
F_48 () ) ;
}
break;
case V_221 :
V_2 -> V_67 = 0 ;
V_193 = F_128 ( V_2 , V_7 ) ;
if ( ! V_193 )
goto V_33;
F_11 ( V_14 , V_34 ,
F_14 ( V_193 ) ) ;
break;
case V_222 :
F_19 ( L_13 ,
V_40 , V_192 -> V_204 . V_7 , & V_2 -> V_93 ) ;
F_129 ( & V_2 -> V_93 , V_192 -> V_204 . V_7 ,
V_50 ) ;
break;
case V_86 :
F_19 ( L_14 ,
V_40 , V_192 -> V_204 . V_223 , & V_2 -> V_93 ) ;
F_81 ( & V_2 -> V_93 , V_192 -> V_204 . V_223 ) ;
break;
case V_34 :
if ( ! V_2 -> V_89 . V_224 ) {
F_130 ( & V_2 -> V_89 ) ;
V_200 = 1 ;
}
error = F_97 ( & V_2 -> V_89 , V_192 -> V_204 . V_7 ) ;
break;
case V_225 :
V_195 = V_192 -> V_204 . V_195 ;
F_131 ( V_195 ) ;
F_132 ( V_195 ) ;
break;
case V_226 :
F_133 ( & V_2 -> V_89 , V_192 -> V_204 . V_11 ,
V_227 ) ;
break;
case V_228 :
F_133 ( & V_2 -> V_89 , V_192 -> V_204 . V_11 ,
V_229 ) ;
break;
case V_230 :
F_1 ( V_2 , V_192 -> V_204 . V_209 ) ;
break;
case V_231 :
V_193 = F_2 ( V_2 , V_192 -> V_204 . V_209 ,
V_7 ) ;
if ( V_193 )
F_11 ( V_14 , V_34 ,
F_14 ( V_193 ) ) ;
break;
case V_232 :
F_7 ( V_2 , V_192 -> V_204 . V_209 ) ;
break;
case V_233 :
F_67 ( V_14 , V_2 , V_192 -> V_204 . V_7 ) ;
break;
case V_234 :
V_156 = & V_2 -> V_53 [ V_192 -> V_204 . V_235 ] ;
if ( F_134 ( V_156 ) )
break;
case V_236 :
V_156 = & V_2 -> V_53 [ V_192 -> V_204 . V_235 ] ;
V_197 = V_2 -> V_27 [ V_192 -> V_204 . V_235 ] ;
F_118 ( ! V_197 ) ;
V_156 -> V_237 = V_42 + V_197 ;
F_27 ( V_2 ) ;
F_135 ( V_156 ) ;
break;
case V_30 :
V_156 = & V_2 -> V_53 [ V_192 -> V_204 . V_235 ] ;
V_197 = V_2 -> V_27 [ V_192 -> V_204 . V_235 ] ;
if ( ! F_20 ( V_156 , V_42 + V_197 ) )
F_27 ( V_2 ) ;
break;
case V_35 :
V_156 = & V_2 -> V_53 [ V_192 -> V_204 . V_235 ] ;
if ( F_59 ( V_156 ) )
F_28 ( V_2 ) ;
break;
case V_238 :
V_7 = V_192 -> V_204 . V_7 ;
V_101 = F_68 ( V_2 ,
V_2 -> V_158 ) ;
V_2 -> V_158 = V_101 ;
V_7 -> V_11 = V_101 ;
V_101 -> V_160 ++ ;
F_136 ( V_2 , V_101 ) ;
break;
case V_239 :
F_95 ( V_2 ,
V_56 ,
L_15 ) ;
F_11 ( V_14 , V_30 ,
F_12 ( V_56 ) ) ;
break;
case V_240 :
F_95 ( V_2 ,
V_55 ,
L_16 ) ;
F_56 (t, &asoc->peer.transport_addr_list,
transports) {
F_137 ( & V_2 -> V_89 , V_101 ,
V_227 ) ;
}
F_11 ( V_14 ,
V_30 ,
F_12 ( V_55 ) ) ;
break;
case V_241 :
F_44 ( V_14 , V_2 , V_192 -> V_204 . V_113 ) ;
break;
case V_242 :
F_49 ( V_14 , V_2 , V_91 ,
V_92 , V_7 , V_192 -> V_204 . V_113 ) ;
break;
case V_243 :
V_2 -> V_159 ++ ;
break;
case V_244 :
V_2 -> V_159 = 0 ;
V_2 -> V_161 = 0 ;
F_56 (t, &asoc->peer.transport_addr_list,
transports) {
V_101 -> V_160 = 0 ;
}
break;
case V_245 :
F_138 ( & V_2 -> V_19 . V_24 ,
V_192 -> V_204 . V_209 ) ;
break;
case V_246 :
F_19 ( L_17 , V_40 ) ;
break;
case V_247 :
F_39 ( V_14 , V_2 ,
V_192 -> V_204 . V_11 , 0 ) ;
break;
case V_248 :
V_101 = V_192 -> V_204 . V_11 ;
F_5 ( V_101 , V_249 ) ;
break;
case V_250 :
V_101 = V_192 -> V_204 . V_11 ;
F_39 ( V_14 , V_2 ,
V_101 , 1 ) ;
V_101 -> V_70 = 1 ;
break;
case V_251 :
V_101 = V_192 -> V_204 . V_11 ;
F_61 ( V_14 , V_2 , V_101 , V_7 ) ;
break;
case V_252 :
F_55 ( V_14 , V_2 ) ;
break;
case V_253 :
V_101 = V_192 -> V_204 . V_11 ;
F_41 ( V_14 , V_101 ) ;
break;
case V_254 :
F_58 ( V_14 , V_2 ) ;
break;
case V_255 :
error = V_192 -> V_204 . error ;
break;
case V_256 :
V_199 . V_257 = V_192 -> V_204 . V_258 ;
V_199 . V_31 = V_2 -> V_19 . V_32 +
V_2 -> V_89 . V_259 ;
V_199 . V_260 = 0 ;
V_199 . V_261 = 0 ;
V_7 -> V_262 . V_263 = & V_199 ;
F_11 ( V_14 , V_214 ,
F_14 ( V_7 ) ) ;
break;
case V_264 :
V_7 -> V_265 = 1 ;
if ( V_2 ) {
F_117 ( & V_2 -> V_89 ) ;
V_200 = 0 ;
}
break;
case V_266 :
V_101 = V_192 -> V_204 . V_11 ;
V_101 -> V_109 = 1 ;
break;
case V_267 :
F_139 ( & V_2 -> V_93 , V_50 ) ;
break;
case V_268 :
F_140 ( & V_2 -> V_93 , V_192 -> V_204 . V_7 ,
V_50 ) ;
break;
case V_269 :
F_78 ( V_14 , V_2 , V_192 -> V_204 . V_7 ) ;
break;
case V_270 :
F_79 ( V_14 , V_2 , V_7 ) ;
break;
case V_271 :
V_2 -> V_19 . V_272 . V_273 = 0 ;
break;
case V_274 :
F_86 ( V_2 ) ;
break;
case V_275 :
F_60 ( V_14 , V_2 ) ;
break;
case V_220 :
V_101 = V_2 -> V_19 . V_219 ;
V_2 -> V_19 . V_219 = V_2 -> V_19 . V_205 ;
error = F_117 ( & V_2 -> V_89 ) ;
V_200 = 0 ;
V_2 -> V_19 . V_219 = V_101 ;
break;
case V_276 :
F_91 ( V_2 , V_192 -> V_204 . error ) ;
break;
case V_277 :
F_92 ( V_14 , V_2 ,
V_192 -> V_204 . T_11 ) ;
break;
case V_278 :
F_93 ( V_14 , V_2 ) ;
break;
case V_279 :
error = F_141 ( V_2 ,
V_50 ) ;
break;
case V_280 :
V_2 -> V_19 . V_272 . V_273 = V_192 -> V_204 . V_209 ;
break;
case V_281 :
if ( ! V_2 -> V_89 . V_224 ) {
F_130 ( & V_2 -> V_89 ) ;
V_200 = 1 ;
}
error = F_96 ( V_2 , V_192 -> V_204 . V_164 ) ;
break;
case V_282 :
F_98 ( V_2 ) ;
break;
case V_283 :
F_142 ( V_2 ) ;
break;
case V_284 :
V_2 = V_192 -> V_204 . V_2 ;
break;
default:
F_113 ( L_18 ,
V_192 -> V_201 ) ;
break;
}
if ( error )
break;
}
V_285:
if ( V_2 && V_94 == V_91 && V_7 ) {
if ( V_7 -> V_286 || V_7 -> V_287 )
error = F_117 ( & V_2 -> V_89 ) ;
} else if ( V_200 )
error = F_117 ( & V_2 -> V_89 ) ;
return error ;
V_33:
error = - V_36 ;
goto V_285;
}
