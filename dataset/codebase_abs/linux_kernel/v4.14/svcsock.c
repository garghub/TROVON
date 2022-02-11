static void F_1 ( struct V_1 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
if ( F_2 ( ! F_3 ( V_3 ) ) )
return;
switch ( V_3 -> V_4 ) {
case V_5 :
F_4 ( V_3 , L_1 ,
& V_6 [ 0 ] ,
L_2 ,
& V_7 [ 0 ] ) ;
break;
case V_8 :
F_4 ( V_3 , L_3 ,
& V_6 [ 1 ] ,
L_4 ,
& V_7 [ 1 ] ) ;
break;
default:
F_5 () ;
}
}
static void F_1 ( struct V_1 * V_2 )
{
}
static void F_6 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_12 ) {
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
V_10 -> V_13 = NULL ;
F_8 ( L_5 , V_10 , V_12 ) ;
F_9 ( V_15 -> V_18 , V_12 ) ;
}
}
static void F_10 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
if ( V_12 ) {
V_10 -> V_13 = NULL ;
F_8 ( L_5 , V_10 , V_12 ) ;
F_11 ( V_12 ) ;
}
}
static void F_12 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
switch ( V_15 -> V_18 -> V_4 ) {
case V_5 : {
struct V_21 * V_22 = F_13 ( V_20 ) ;
V_20 -> V_23 = V_24 ;
V_20 -> V_25 = V_26 ;
V_22 -> V_27 = 0 ;
V_22 -> V_28 . V_29 =
F_14 ( V_10 ) -> V_30 . V_29 ;
V_20 -> V_31 = F_15 ( sizeof( * V_22 ) ) ;
}
break;
case V_8 : {
struct V_32 * V_22 = F_13 ( V_20 ) ;
struct V_33 * V_34 = F_16 ( V_10 ) ;
V_20 -> V_23 = V_35 ;
V_20 -> V_25 = V_36 ;
V_22 -> V_37 = V_34 -> V_38 ;
V_22 -> V_39 = V_34 -> V_40 ;
V_20 -> V_31 = F_15 ( sizeof( * V_22 ) ) ;
}
break;
}
}
int F_17 ( struct V_1 * V_2 , struct V_41 * V_42 ,
struct V_43 * V_44 , unsigned long V_45 ,
struct V_43 * V_46 , unsigned long V_47 )
{
int V_48 ;
int V_49 ;
struct V_43 * * V_50 = V_42 -> V_51 ;
T_1 V_52 = V_42 -> V_53 ;
unsigned int V_54 = V_42 -> V_55 ;
unsigned int V_56 = V_57 | V_58 ;
int V_59 ;
int V_60 = 0 ;
V_59 = V_42 -> V_60 ;
if ( V_59 == V_42 -> V_61 [ 0 ] . V_62 )
V_56 = 0 ;
V_60 = F_18 ( V_2 , V_44 , V_45 ,
V_42 -> V_61 [ 0 ] . V_62 , V_56 ) ;
if ( V_60 != V_42 -> V_61 [ 0 ] . V_62 )
goto V_63;
V_59 -= V_42 -> V_61 [ 0 ] . V_62 ;
if ( V_59 == 0 )
goto V_63;
V_49 = V_64 - V_52 < V_54 ? V_64 - V_52 : V_54 ;
while ( V_54 > 0 ) {
if ( V_59 == V_49 )
V_56 = 0 ;
V_48 = F_18 ( V_2 , * V_50 , V_52 , V_49 , V_56 ) ;
if ( V_48 > 0 )
V_60 += V_48 ;
if ( V_48 != V_49 )
goto V_63;
V_59 -= V_49 ;
V_54 -= V_49 ;
V_49 = V_64 < V_54 ? V_64 : V_54 ;
V_52 = 0 ;
V_50 ++ ;
}
if ( V_42 -> V_65 [ 0 ] . V_62 ) {
V_48 = F_18 ( V_2 , V_46 , V_47 ,
V_42 -> V_65 [ 0 ] . V_62 , 0 ) ;
if ( V_48 > 0 )
V_60 += V_48 ;
}
V_63:
return V_60 ;
}
static int F_19 ( struct V_9 * V_10 , struct V_41 * V_42 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_1 * V_2 = V_15 -> V_66 ;
union {
struct V_19 V_67 ;
long V_68 [ V_69 / sizeof( long ) ] ;
} V_70 ;
struct V_19 * V_20 = & V_70 . V_67 ;
int V_60 = 0 ;
unsigned long V_71 ;
unsigned long V_72 ;
F_20 (char buf[RPC_MAX_ADDRBUFLEN]) ;
if ( V_10 -> V_73 == V_74 ) {
struct V_75 V_76 = {
. V_77 = & V_10 -> V_78 ,
. V_79 = V_10 -> V_80 ,
. V_81 = V_20 ,
. V_82 = sizeof( V_70 ) ,
. V_83 = V_57 ,
} ;
F_12 ( V_10 , V_20 ) ;
if ( F_21 ( V_2 , & V_76 ) < 0 )
goto V_63;
}
V_71 = ( ( unsigned long ) V_42 -> V_65 [ 0 ] . V_84 ) & ( V_64 - 1 ) ;
V_72 = 0 ;
V_60 = F_17 ( V_2 , V_42 , V_10 -> V_85 [ 0 ] , V_72 ,
V_10 -> V_85 [ 0 ] , V_71 ) ;
V_63:
F_8 ( L_6 ,
V_15 , V_42 -> V_61 [ 0 ] . V_84 , V_42 -> V_61 [ 0 ] . V_62 ,
V_42 -> V_60 , V_60 , F_22 ( V_10 , V_86 , sizeof( V_86 ) ) ) ;
return V_60 ;
}
static int F_23 ( struct V_14 * V_15 , char * V_86 , int V_87 )
{
const struct V_2 * V_3 = V_15 -> V_18 ;
const char * V_88 = V_3 -> V_89 == V_74 ?
L_7 : L_8 ;
int V_60 ;
switch ( V_3 -> V_4 ) {
case V_90 :
V_60 = snprintf ( V_86 , V_87 , L_9 ,
V_88 ,
& F_24 ( V_3 ) -> V_91 ,
F_24 ( V_3 ) -> V_92 ) ;
break;
#if F_25 ( V_93 )
case V_94 :
V_60 = snprintf ( V_86 , V_87 , L_10 ,
V_88 ,
& V_3 -> V_95 ,
F_24 ( V_3 ) -> V_92 ) ;
break;
#endif
default:
V_60 = snprintf ( V_86 , V_87 , L_11 ,
V_3 -> V_4 ) ;
}
if ( V_60 >= V_87 ) {
* V_86 = '\0' ;
return - V_96 ;
}
return V_60 ;
}
static int F_26 ( struct V_9 * V_10 , struct V_97 * V_98 , int V_99 ,
int V_100 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_75 V_76 = {
. V_83 = V_101 ,
} ;
int V_60 ;
V_10 -> V_102 = 0 ;
F_27 ( V_103 , & V_15 -> V_17 . V_104 ) ;
V_60 = F_28 ( V_15 -> V_66 , & V_76 , V_98 , V_99 , V_100 ,
V_76 . V_83 ) ;
if ( V_60 == V_100 )
F_29 ( V_103 , & V_15 -> V_17 . V_104 ) ;
F_8 ( L_12 ,
V_15 , V_98 [ 0 ] . V_84 , V_98 [ 0 ] . V_62 , V_60 ) ;
return V_60 ;
}
static int F_30 ( struct V_9 * V_10 ,
struct V_97 * V_98 , int V_99 ,
int V_100 , unsigned int V_52 )
{
T_1 V_105 ;
void * V_106 ;
unsigned int V_107 ;
int V_108 ;
if ( V_52 == 0 )
return F_26 ( V_10 , V_98 , V_99 , V_100 ) ;
for ( V_107 = 0 ; V_107 < V_99 ; V_107 ++ ) {
if ( V_98 [ V_107 ] . V_62 > V_52 )
break;
V_52 -= V_98 [ V_107 ] . V_62 ;
}
V_105 = V_98 [ V_107 ] . V_62 ;
V_106 = V_98 [ V_107 ] . V_84 ;
V_98 [ V_107 ] . V_62 -= V_52 ;
V_98 [ V_107 ] . V_84 += V_52 ;
V_108 = F_26 ( V_10 , & V_98 [ V_107 ] , V_99 - V_107 , V_100 ) ;
V_98 [ V_107 ] . V_62 = V_105 ;
V_98 [ V_107 ] . V_84 = V_106 ;
return V_108 ;
}
static void F_31 ( struct V_1 * V_2 , unsigned int V_109 ,
unsigned int V_110 )
{
#if 0
mm_segment_t oldfs;
oldfs = get_fs(); set_fs(KERNEL_DS);
sock_setsockopt(sock, SOL_SOCKET, SO_SNDBUF,
(char*)&snd, sizeof(snd));
sock_setsockopt(sock, SOL_SOCKET, SO_RCVBUF,
(char*)&rcv, sizeof(rcv));
#else
F_32 ( V_2 -> V_3 ) ;
V_2 -> V_3 -> V_111 = V_109 * 2 ;
V_2 -> V_3 -> V_112 = V_110 * 2 ;
V_2 -> V_3 -> V_113 ( V_2 -> V_3 ) ;
F_33 ( V_2 -> V_3 ) ;
#endif
}
static int F_34 ( struct V_9 * V_10 )
{
return F_35 ( F_36 ( V_10 ) ) ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_114 ;
if ( V_15 ) {
F_8 ( L_13 ,
V_15 , V_3 ,
F_38 ( V_115 , & V_15 -> V_17 . V_104 ) ) ;
F_39 () ;
V_15 -> V_116 ( V_3 ) ;
if ( ! F_40 ( V_103 , & V_15 -> V_17 . V_104 ) )
F_41 ( & V_15 -> V_17 ) ;
}
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) ( V_3 -> V_114 ) ;
if ( V_15 ) {
F_8 ( L_14 ,
V_15 , V_3 , F_38 ( V_115 , & V_15 -> V_17 . V_104 ) ) ;
F_39 () ;
V_15 -> V_117 ( V_3 ) ;
F_41 ( & V_15 -> V_17 ) ;
}
}
static int F_43 ( struct V_118 * V_119 )
{
struct V_14 * V_15 = F_7 ( V_119 , struct V_14 , V_17 ) ;
if ( F_38 ( V_120 , & V_119 -> V_104 ) )
return 1 ;
return ! F_38 ( V_121 , & V_15 -> V_66 -> V_56 ) ;
}
static void F_44 ( struct V_118 * V_119 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
struct V_122 V_123 = {
. V_124 = 1 ,
. V_125 = 0 ,
} ;
V_15 = F_7 ( V_119 , struct V_14 , V_17 ) ;
V_2 = V_15 -> V_66 ;
F_45 ( V_2 , V_126 , V_127 ,
( char * ) & V_123 , sizeof( V_123 ) ) ;
}
static int F_46 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = F_13 ( V_20 ) ;
struct V_128 * V_34 = F_14 ( V_10 ) ;
if ( V_20 -> V_25 != V_26 )
return 0 ;
V_34 -> V_129 = V_5 ;
V_34 -> V_30 . V_29 = V_22 -> V_28 . V_29 ;
return 1 ;
}
static int F_47 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
struct V_32 * V_22 = F_13 ( V_20 ) ;
struct V_33 * V_34 = F_16 ( V_10 ) ;
if ( V_20 -> V_25 != V_36 )
return 0 ;
V_34 -> V_130 = V_8 ;
V_34 -> V_40 = V_22 -> V_39 ;
V_34 -> V_38 = V_22 -> V_37 ;
return 1 ;
}
static int F_48 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
switch ( V_20 -> V_23 ) {
case V_24 :
return F_46 ( V_10 , V_20 ) ;
case V_35 :
return F_47 ( V_10 , V_20 ) ;
}
return 0 ;
}
static int F_49 ( struct V_9 * V_10 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_131 * V_132 = V_15 -> V_17 . V_133 ;
struct V_11 * V_12 ;
union {
struct V_19 V_67 ;
long V_68 [ V_69 / sizeof( long ) ] ;
} V_70 ;
struct V_19 * V_20 = & V_70 . V_67 ;
struct V_75 V_76 = {
. V_77 = F_36 ( V_10 ) ,
. V_81 = V_20 ,
. V_82 = sizeof( V_70 ) ,
. V_83 = V_101 ,
} ;
T_1 V_60 ;
int V_134 ;
if ( F_50 ( V_135 , & V_15 -> V_17 . V_104 ) )
F_31 ( V_15 -> V_66 ,
( V_132 -> V_136 + 3 ) * V_132 -> V_137 ,
( V_132 -> V_136 + 3 ) * V_132 -> V_137 ) ;
F_27 ( V_103 , & V_15 -> V_17 . V_104 ) ;
V_12 = NULL ;
V_134 = F_28 ( V_15 -> V_66 , & V_76 , NULL ,
0 , 0 , V_138 | V_101 ) ;
if ( V_134 >= 0 )
V_12 = F_51 ( V_15 -> V_18 , 0 , 1 , & V_134 ) ;
if ( V_12 == NULL ) {
if ( V_134 != - V_139 ) {
F_8 ( L_15 , - V_134 ) ;
F_29 ( V_103 , & V_15 -> V_17 . V_104 ) ;
}
return 0 ;
}
V_60 = F_52 ( F_36 ( V_10 ) ) ;
V_10 -> V_80 = V_60 ;
if ( V_12 -> V_140 == 0 ) {
V_12 -> V_140 = F_53 () ;
}
V_15 -> V_18 -> V_141 = V_12 -> V_140 ;
F_29 ( V_103 , & V_15 -> V_17 . V_104 ) ;
V_60 = V_12 -> V_60 ;
V_10 -> V_142 . V_60 = V_60 ;
V_10 -> V_73 = V_74 ;
if ( ! F_48 ( V_10 , V_20 ) ) {
F_54 ( L_16 ,
V_20 -> V_23 , V_20 -> V_25 ) ;
goto V_143;
}
V_10 -> V_144 = F_52 ( F_55 ( V_10 ) ) ;
if ( F_56 ( V_12 ) ) {
F_57 () ;
if ( F_58 ( & V_10 -> V_142 , V_12 ) ) {
F_59 () ;
goto V_143;
}
F_59 () ;
F_11 ( V_12 ) ;
} else {
V_10 -> V_142 . V_61 [ 0 ] . V_84 = V_12 -> V_145 ;
V_10 -> V_142 . V_61 [ 0 ] . V_62 = V_60 ;
if ( F_60 ( V_12 ) )
goto V_143;
V_10 -> V_13 = V_12 ;
}
V_10 -> V_142 . V_53 = 0 ;
if ( V_60 <= V_10 -> V_142 . V_61 [ 0 ] . V_62 ) {
V_10 -> V_142 . V_61 [ 0 ] . V_62 = V_60 ;
V_10 -> V_142 . V_55 = 0 ;
V_10 -> V_85 = V_10 -> V_146 + 1 ;
} else {
V_10 -> V_142 . V_55 = V_60 - V_10 -> V_142 . V_61 [ 0 ] . V_62 ;
V_10 -> V_85 = V_10 -> V_146 + 1 +
F_61 ( V_10 -> V_142 . V_55 , V_64 ) ;
}
V_10 -> V_147 = V_10 -> V_85 + 1 ;
if ( V_132 -> V_148 )
V_132 -> V_148 -> V_149 ++ ;
return V_60 ;
V_143:
F_62 ( V_12 ) ;
return 0 ;
}
static int
F_63 ( struct V_9 * V_10 )
{
int error ;
error = F_19 ( V_10 , & V_10 -> V_150 ) ;
if ( error == - V_151 )
error = F_19 ( V_10 , & V_10 -> V_150 ) ;
return error ;
}
static void F_64 ( struct V_9 * V_10 )
{
}
static int F_65 ( struct V_118 * V_119 )
{
struct V_14 * V_15 = F_7 ( V_119 , struct V_14 , V_17 ) ;
struct V_131 * V_132 = V_119 -> V_133 ;
unsigned long V_152 ;
F_29 ( V_121 , & V_15 -> V_66 -> V_56 ) ;
V_152 = F_66 ( & V_15 -> V_17 . V_153 ) + V_132 -> V_137 ;
if ( V_152 * 2 > F_67 ( V_15 -> V_18 ) )
return 0 ;
F_27 ( V_121 , & V_15 -> V_66 -> V_56 ) ;
return 1 ;
}
static struct V_118 * F_68 ( struct V_118 * V_119 )
{
F_5 () ;
return NULL ;
}
static void F_69 ( struct V_118 * V_119 )
{
}
static struct V_118 * F_70 ( struct V_131 * V_132 ,
struct V_154 * V_154 ,
struct V_155 * V_156 , int V_157 ,
int V_56 )
{
return F_71 ( V_132 , V_74 , V_154 , V_156 , V_157 , V_56 ) ;
}
static void F_72 ( struct V_14 * V_15 , struct V_131 * V_132 )
{
int V_134 , V_158 , V_159 , V_160 = 1 ;
F_73 ( F_74 ( V_15 -> V_66 -> V_3 ) , & V_161 ,
& V_15 -> V_17 , V_132 ) ;
F_27 ( V_162 , & V_15 -> V_17 . V_104 ) ;
V_15 -> V_18 -> V_163 = F_37 ;
V_15 -> V_18 -> V_113 = F_42 ;
F_31 ( V_15 -> V_66 ,
3 * V_15 -> V_17 . V_133 -> V_137 ,
3 * V_15 -> V_17 . V_133 -> V_137 ) ;
F_29 ( V_103 , & V_15 -> V_17 . V_104 ) ;
F_29 ( V_135 , & V_15 -> V_17 . V_104 ) ;
switch ( V_15 -> V_18 -> V_4 ) {
case V_5 :
V_158 = V_24 ;
V_159 = V_26 ;
break;
case V_8 :
V_158 = V_35 ;
V_159 = V_164 ;
break;
default:
F_5 () ;
}
V_134 = F_45 ( V_15 -> V_66 , V_158 , V_159 ,
( char * ) & V_160 , sizeof( V_160 ) ) ;
F_8 ( L_17 , V_134 ) ;
}
static void F_75 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_114 ;
F_8 ( L_18 ,
V_3 , V_3 -> V_165 ) ;
if ( V_15 ) {
F_39 () ;
V_15 -> V_116 ( V_3 ) ;
}
if ( V_3 -> V_165 == V_166 ) {
if ( V_15 ) {
F_29 ( V_167 , & V_15 -> V_17 . V_104 ) ;
F_41 ( & V_15 -> V_17 ) ;
} else
F_76 ( L_19 , V_3 ) ;
}
}
static void F_77 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_114 ;
F_8 ( L_20 ,
V_3 , V_3 -> V_165 , V_3 -> V_114 ) ;
if ( ! V_15 )
F_76 ( L_19 , V_3 ) ;
else {
F_39 () ;
V_15 -> V_168 ( V_3 ) ;
if ( V_3 -> V_165 != V_169 ) {
F_29 ( V_170 , & V_15 -> V_17 . V_104 ) ;
F_41 ( & V_15 -> V_17 ) ;
}
}
}
static struct V_118 * F_78 ( struct V_118 * V_119 )
{
struct V_14 * V_15 = F_7 ( V_119 , struct V_14 , V_17 ) ;
struct V_171 V_172 ;
struct V_155 * sin = (struct V_155 * ) & V_172 ;
struct V_131 * V_132 = V_15 -> V_17 . V_133 ;
struct V_1 * V_2 = V_15 -> V_66 ;
struct V_1 * V_173 ;
struct V_14 * V_174 ;
int V_134 , V_59 ;
F_20 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_8 ( L_21 , V_15 , V_2 ) ;
if ( ! V_2 )
return NULL ;
F_27 ( V_167 , & V_15 -> V_17 . V_104 ) ;
V_134 = F_79 ( V_2 , & V_173 , V_175 ) ;
if ( V_134 < 0 ) {
if ( V_134 == - V_176 )
F_76 ( V_177 L_22 ,
V_132 -> V_178 ) ;
else if ( V_134 != - V_139 )
F_54 ( L_23 ,
V_132 -> V_178 , - V_134 ) ;
return NULL ;
}
F_29 ( V_167 , & V_15 -> V_17 . V_104 ) ;
V_134 = F_80 ( V_173 , sin , & V_59 ) ;
if ( V_134 < 0 ) {
F_54 ( L_24 ,
V_132 -> V_178 , - V_134 ) ;
goto V_179;
}
if ( ! F_35 ( sin ) ) {
F_8 ( L_25 ,
V_132 -> V_178 ,
F_81 ( sin , V_86 , sizeof( V_86 ) ) ) ;
}
F_8 ( L_26 , V_132 -> V_178 ,
F_81 ( sin , V_86 , sizeof( V_86 ) ) ) ;
V_173 -> V_3 -> V_180 = V_15 -> V_168 ;
V_173 -> V_3 -> V_163 = V_15 -> V_116 ;
V_173 -> V_3 -> V_113 = V_15 -> V_117 ;
V_173 -> V_3 -> V_181 = V_182 * 30 ;
V_174 = F_82 ( V_132 , V_173 ,
( V_183 | V_184 ) ) ;
if ( F_83 ( V_174 ) )
goto V_179;
F_84 ( & V_174 -> V_17 , sin , V_59 ) ;
V_134 = F_85 ( V_173 , sin , & V_59 ) ;
if ( F_86 ( V_134 < 0 ) ) {
F_8 ( L_27 , - V_134 ) ;
V_59 = F_87 ( struct V_155 , V_185 ) ;
}
F_88 ( & V_174 -> V_17 , sin , V_59 ) ;
if ( F_89 ( V_173 -> V_3 ) )
F_29 ( V_186 , & V_174 -> V_17 . V_104 ) ;
else
F_27 ( V_186 , & V_174 -> V_17 . V_104 ) ;
if ( V_132 -> V_148 )
V_132 -> V_148 -> V_187 ++ ;
return & V_174 -> V_17 ;
V_179:
F_90 ( V_173 ) ;
return NULL ;
}
static unsigned int F_91 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
unsigned int V_107 , V_60 , V_188 ;
if ( V_15 -> V_189 == 0 )
return 0 ;
V_60 = V_15 -> V_189 ;
V_188 = ( V_60 + V_64 - 1 ) >> V_190 ;
for ( V_107 = 0 ; V_107 < V_188 ; V_107 ++ ) {
if ( V_10 -> V_146 [ V_107 ] != NULL )
F_92 ( V_10 -> V_146 [ V_107 ] ) ;
F_93 ( V_15 -> V_191 [ V_107 ] == NULL ) ;
V_10 -> V_146 [ V_107 ] = V_15 -> V_191 [ V_107 ] ;
V_15 -> V_191 [ V_107 ] = NULL ;
}
V_10 -> V_142 . V_61 [ 0 ] . V_84 = F_94 ( V_10 -> V_146 [ 0 ] ) ;
return V_60 ;
}
static void F_95 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
unsigned int V_107 , V_60 , V_188 ;
if ( V_15 -> V_189 == 0 )
return;
V_60 = V_15 -> V_189 ;
V_188 = ( V_60 + V_64 - 1 ) >> V_190 ;
for ( V_107 = 0 ; V_107 < V_188 ; V_107 ++ ) {
V_15 -> V_191 [ V_107 ] = V_10 -> V_146 [ V_107 ] ;
V_10 -> V_146 [ V_107 ] = NULL ;
}
}
static void F_96 ( struct V_14 * V_15 )
{
unsigned int V_107 , V_60 , V_188 ;
if ( V_15 -> V_189 == 0 )
goto V_63;
V_60 = V_15 -> V_189 ;
V_188 = ( V_60 + V_64 - 1 ) >> V_190 ;
for ( V_107 = 0 ; V_107 < V_188 ; V_107 ++ ) {
if ( V_15 -> V_191 [ V_107 ] == NULL ) {
F_2 ( 1 ) ;
continue;
}
F_92 ( V_15 -> V_191 [ V_107 ] ) ;
V_15 -> V_191 [ V_107 ] = NULL ;
}
V_63:
V_15 -> V_192 = 0 ;
V_15 -> V_189 = 0 ;
}
static int F_97 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
struct V_131 * V_132 = V_15 -> V_17 . V_133 ;
unsigned int V_193 ;
int V_60 ;
if ( V_15 -> V_192 < sizeof( V_194 ) ) {
struct V_97 V_98 ;
V_193 = sizeof( V_194 ) - V_15 -> V_192 ;
V_98 . V_84 = ( ( char * ) & V_15 -> V_195 ) + V_15 -> V_192 ;
V_98 . V_62 = V_193 ;
if ( ( V_60 = F_26 ( V_10 , & V_98 , 1 , V_193 ) ) < 0 )
goto error;
V_15 -> V_192 += V_60 ;
if ( V_60 < V_193 ) {
F_8 ( L_28
L_29 , V_60 , V_193 ) ;
return - V_139 ;
}
F_8 ( L_30 , F_98 ( V_15 ) ) ;
if ( F_98 ( V_15 ) + V_15 -> V_189 >
V_132 -> V_137 ) {
F_99 ( L_31 ,
F_98 ( V_15 ) ) ;
goto V_196;
}
}
return F_98 ( V_15 ) ;
error:
F_8 ( L_32 , V_60 ) ;
return V_60 ;
V_196:
F_29 ( V_170 , & V_15 -> V_17 . V_104 ) ;
return - V_139 ;
}
static int F_100 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
struct V_197 * V_198 = V_15 -> V_17 . V_199 ;
struct V_200 * V_201 = NULL ;
struct V_97 * V_202 , * V_203 ;
T_2 * V_204 = ( T_2 * ) V_10 -> V_142 . V_61 [ 0 ] . V_84 ;
T_2 V_205 ;
T_2 V_206 ;
V_205 = * V_204 ++ ;
V_206 = * V_204 ;
if ( ! V_198 )
return - V_139 ;
F_101 ( & V_198 -> V_207 ) ;
V_201 = F_102 ( V_198 , V_205 ) ;
if ( ! V_201 )
goto V_208;
memcpy ( & V_201 -> V_209 , & V_201 -> V_210 , sizeof( struct V_41 ) ) ;
V_203 = & V_201 -> V_209 . V_61 [ 0 ] ;
V_202 = & V_10 -> V_142 . V_61 [ 0 ] ;
if ( V_203 -> V_62 < V_202 -> V_62 )
goto V_211;
memcpy ( V_203 -> V_84 , V_202 -> V_84 , V_202 -> V_62 ) ;
F_103 ( V_201 -> V_212 , V_10 -> V_142 . V_60 ) ;
V_10 -> V_142 . V_60 = 0 ;
F_104 ( & V_198 -> V_207 ) ;
return 0 ;
V_208:
F_76 ( V_213
L_33
L_34 ,
V_214 , F_105 ( V_206 ) ,
V_198 , F_105 ( V_205 ) ) ;
V_211:
F_104 ( & V_198 -> V_207 ) ;
return - V_139 ;
}
static int F_106 ( struct V_97 * V_215 , struct V_43 * * V_51 , int V_60 )
{
int V_107 = 0 ;
int V_216 = 0 ;
while ( V_216 < V_60 ) {
V_215 [ V_107 ] . V_84 = F_94 ( V_51 [ V_107 ] ) ;
V_215 [ V_107 ] . V_62 = V_64 ;
V_107 ++ ;
V_216 += V_64 ;
}
return V_107 ;
}
static void F_107 ( struct V_14 * V_15 )
{
F_8 ( L_35 ,
F_108 ( V_15 ) ? L_36 : L_37 ,
F_98 ( V_15 ) ) ;
V_15 -> V_192 = 0 ;
V_15 -> V_195 = 0 ;
}
static int F_109 ( struct V_9 * V_10 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_131 * V_132 = V_15 -> V_17 . V_133 ;
int V_60 ;
struct V_97 * V_215 ;
unsigned int V_193 , V_52 ;
T_2 * V_204 ;
T_2 V_206 ;
int V_217 ;
F_8 ( L_38 ,
V_15 , F_38 ( V_103 , & V_15 -> V_17 . V_104 ) ,
F_38 ( V_167 , & V_15 -> V_17 . V_104 ) ,
F_38 ( V_170 , & V_15 -> V_17 . V_104 ) ) ;
V_60 = F_97 ( V_15 , V_10 ) ;
if ( V_60 < 0 )
goto error;
V_52 = F_91 ( V_15 , V_10 ) ;
V_193 = F_98 ( V_15 ) - ( V_15 -> V_192 - sizeof( V_194 ) ) ;
V_215 = V_10 -> V_218 ;
V_217 = F_106 ( & V_215 [ 0 ] , & V_10 -> V_146 [ 0 ] ,
V_15 -> V_189 + V_193 ) ;
V_10 -> V_85 = & V_10 -> V_146 [ V_217 ] ;
V_10 -> V_147 = V_10 -> V_85 + 1 ;
V_60 = F_30 ( V_10 , V_215 , V_217 , V_193 , V_52 ) ;
if ( V_60 >= 0 ) {
V_15 -> V_192 += V_60 ;
V_15 -> V_189 += V_60 ;
}
if ( V_60 != V_193 || ! F_108 ( V_15 ) ) {
F_95 ( V_15 , V_10 ) ;
if ( V_60 < 0 && V_60 != - V_139 )
goto V_196;
if ( V_60 == V_193 )
F_107 ( V_15 ) ;
else
F_8 ( L_39 ,
( int ) ( V_15 -> V_192 - sizeof( V_194 ) ) ,
F_98 ( V_15 ) ) ;
goto V_219;
}
if ( V_15 -> V_189 < 8 ) {
V_15 -> V_189 = 0 ;
goto V_196;
}
V_10 -> V_142 . V_60 = V_15 -> V_189 ;
V_10 -> V_142 . V_53 = 0 ;
if ( V_10 -> V_142 . V_60 <= V_10 -> V_142 . V_61 [ 0 ] . V_62 ) {
V_10 -> V_142 . V_61 [ 0 ] . V_62 = V_10 -> V_142 . V_60 ;
V_10 -> V_142 . V_55 = 0 ;
} else
V_10 -> V_142 . V_55 = V_10 -> V_142 . V_60 - V_10 -> V_142 . V_61 [ 0 ] . V_62 ;
V_10 -> V_13 = NULL ;
V_10 -> V_73 = V_220 ;
if ( F_38 ( V_186 , & V_15 -> V_17 . V_104 ) )
F_29 ( V_221 , & V_10 -> V_222 ) ;
else
F_27 ( V_221 , & V_10 -> V_222 ) ;
V_204 = ( T_2 * ) V_10 -> V_142 . V_61 [ 0 ] . V_84 ;
V_206 = V_204 [ 1 ] ;
if ( V_206 )
V_60 = F_100 ( V_15 , V_10 ) ;
V_15 -> V_189 = 0 ;
F_107 ( V_15 ) ;
if ( V_60 < 0 )
goto error;
F_110 ( V_10 , & V_15 -> V_17 ) ;
if ( V_132 -> V_148 )
V_132 -> V_148 -> V_223 ++ ;
return V_10 -> V_142 . V_60 ;
error:
if ( V_60 != - V_139 )
goto V_196;
F_8 ( L_40 ) ;
return 0 ;
V_196:
F_76 ( V_213 L_41 ,
V_15 -> V_17 . V_133 -> V_178 , - V_60 ) ;
F_29 ( V_170 , & V_15 -> V_17 . V_104 ) ;
V_219:
return 0 ;
}
static int F_111 ( struct V_9 * V_10 )
{
struct V_41 * V_224 = & V_10 -> V_150 ;
int V_225 ;
T_2 V_226 ;
V_226 = F_112 ( 0x80000000 | ( ( V_224 -> V_60 ) - 4 ) ) ;
memcpy ( V_224 -> V_61 [ 0 ] . V_84 , & V_226 , 4 ) ;
V_225 = F_19 ( V_10 , & V_10 -> V_150 ) ;
if ( V_225 != V_224 -> V_60 ) {
F_76 ( V_213
L_42
L_43 ,
V_10 -> V_16 -> V_133 -> V_178 ,
( V_225 < 0 ) ? L_44 : L_45 ,
V_225 , V_224 -> V_60 ) ;
F_29 ( V_170 , & V_10 -> V_16 -> V_104 ) ;
F_41 ( V_10 -> V_16 ) ;
V_225 = - V_139 ;
}
return V_225 ;
}
static void F_113 ( struct V_9 * V_10 )
{
struct V_97 * V_227 = & V_10 -> V_150 . V_61 [ 0 ] ;
F_114 ( V_227 , 0 ) ;
}
static struct V_118 * F_115 ( struct V_131 * V_132 ,
struct V_154 * V_154 ,
struct V_155 * V_156 , int V_157 ,
int V_56 )
{
return F_71 ( V_132 , V_220 , V_154 , V_156 , V_157 , V_56 ) ;
}
static struct V_118 * F_116 ( struct V_131 * V_132 ,
struct V_154 * V_154 ,
struct V_155 * V_156 , int V_157 ,
int V_56 )
{
return F_117 ( V_132 , V_220 , V_154 , V_156 , V_157 , V_56 ) ;
}
static void F_118 ( struct V_118 * V_119 )
{
}
static void F_119 ( void )
{
F_120 ( & V_228 ) ;
}
static void F_121 ( void )
{
F_122 ( & V_228 ) ;
}
static void F_119 ( void )
{
}
static void F_121 ( void )
{
}
void F_123 ( void )
{
F_120 ( & V_229 ) ;
F_120 ( & V_161 ) ;
F_119 () ;
}
void F_124 ( void )
{
F_122 ( & V_229 ) ;
F_122 ( & V_161 ) ;
F_121 () ;
}
static void F_125 ( struct V_14 * V_15 , struct V_131 * V_132 )
{
struct V_2 * V_3 = V_15 -> V_18 ;
F_73 ( F_74 ( V_15 -> V_66 -> V_3 ) , & V_229 ,
& V_15 -> V_17 , V_132 ) ;
F_29 ( V_162 , & V_15 -> V_17 . V_104 ) ;
F_29 ( V_230 , & V_15 -> V_17 . V_104 ) ;
if ( V_3 -> V_165 == V_166 ) {
F_8 ( L_46 ) ;
F_29 ( V_120 , & V_15 -> V_17 . V_104 ) ;
V_3 -> V_163 = F_75 ;
F_29 ( V_167 , & V_15 -> V_17 . V_104 ) ;
} else {
F_8 ( L_47 ) ;
V_3 -> V_180 = F_77 ;
V_3 -> V_163 = F_37 ;
V_3 -> V_113 = F_42 ;
V_15 -> V_195 = 0 ;
V_15 -> V_192 = 0 ;
V_15 -> V_189 = 0 ;
memset ( & V_15 -> V_191 [ 0 ] , 0 , sizeof( V_15 -> V_191 ) ) ;
F_126 ( V_3 ) -> V_231 |= V_232 ;
F_29 ( V_103 , & V_15 -> V_17 . V_104 ) ;
switch ( V_3 -> V_165 ) {
case V_233 :
case V_169 :
break;
default:
F_29 ( V_170 , & V_15 -> V_17 . V_104 ) ;
}
}
}
void F_127 ( struct V_131 * V_132 )
{
struct V_14 * V_15 ;
F_128 ( & V_132 -> V_234 ) ;
F_129 (svsk, &serv->sv_permsocks, sk_xprt.xpt_list)
F_29 ( V_135 , & V_15 -> V_17 . V_104 ) ;
F_130 ( & V_132 -> V_234 ) ;
}
static struct V_14 * F_82 ( struct V_131 * V_132 ,
struct V_1 * V_2 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_2 * V_235 ;
int V_236 = ! ( V_56 & V_183 ) ;
int V_134 = 0 ;
F_8 ( L_48 , V_2 ) ;
V_15 = F_131 ( sizeof( * V_15 ) , V_237 ) ;
if ( ! V_15 )
return F_132 ( - V_176 ) ;
V_235 = V_2 -> V_3 ;
if ( V_236 )
V_134 = F_133 ( V_132 , F_74 ( V_2 -> V_3 ) , V_235 -> V_4 ,
V_235 -> V_89 ,
F_134 ( F_24 ( V_235 ) -> V_238 ) ) ;
if ( V_134 < 0 ) {
F_135 ( V_15 ) ;
return F_132 ( V_134 ) ;
}
V_15 -> V_66 = V_2 ;
V_15 -> V_18 = V_235 ;
V_15 -> V_168 = V_235 -> V_180 ;
V_15 -> V_116 = V_235 -> V_163 ;
V_15 -> V_117 = V_235 -> V_113 ;
F_136 () ;
V_235 -> V_114 = V_15 ;
if ( V_2 -> type == V_239 )
F_72 ( V_15 , V_132 ) ;
else
F_125 ( V_15 , V_132 ) ;
F_8 ( L_49
L_50 ,
V_15 , V_15 -> V_18 ,
F_38 ( V_120 , & V_15 -> V_17 . V_104 ) ,
F_38 ( V_170 , & V_15 -> V_17 . V_104 ) ) ;
return V_15 ;
}
bool F_137 ( struct V_154 * V_154 , int V_240 )
{
int V_134 ;
struct V_1 * V_2 = F_138 ( V_240 , & V_134 ) ;
bool V_108 = false ;
if ( ! V_2 )
goto V_63;
if ( F_74 ( V_2 -> V_3 ) != V_154 )
V_108 = true ;
F_139 ( V_2 ) ;
V_63:
return V_108 ;
}
int F_140 ( struct V_131 * V_132 , const int V_240 , char * V_241 ,
const T_1 V_60 )
{
int V_134 = 0 ;
struct V_1 * V_242 = F_138 ( V_240 , & V_134 ) ;
struct V_14 * V_15 = NULL ;
struct V_171 V_172 ;
struct V_155 * sin = (struct V_155 * ) & V_172 ;
int V_157 ;
if ( ! V_242 )
return V_134 ;
V_134 = - V_243 ;
if ( ( V_242 -> V_3 -> V_4 != V_90 ) && ( V_242 -> V_3 -> V_4 != V_94 ) )
goto V_63;
V_134 = - V_244 ;
if ( V_242 -> V_3 -> V_89 != V_220 &&
V_242 -> V_3 -> V_89 != V_74 )
goto V_63;
V_134 = - V_245 ;
if ( V_242 -> V_246 > V_247 )
goto V_63;
V_134 = - V_248 ;
if ( ! F_141 ( V_249 ) )
goto V_63;
V_15 = F_82 ( V_132 , V_242 , V_250 ) ;
if ( F_83 ( V_15 ) ) {
F_142 ( V_249 ) ;
V_134 = F_143 ( V_15 ) ;
goto V_63;
}
if ( F_85 ( V_15 -> V_66 , sin , & V_157 ) == 0 )
F_88 ( & V_15 -> V_17 , sin , V_157 ) ;
F_144 ( V_132 , & V_15 -> V_17 ) ;
return F_23 ( V_15 , V_241 , V_60 ) ;
V_63:
F_139 ( V_242 ) ;
return V_134 ;
}
static struct V_118 * F_71 ( struct V_131 * V_132 ,
int V_251 ,
struct V_154 * V_154 ,
struct V_155 * sin , int V_60 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int error ;
int type ;
struct V_171 V_172 ;
struct V_155 * V_252 = (struct V_155 * ) & V_172 ;
int V_253 ;
int V_254 ;
int V_255 ;
F_20 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_8 ( L_51 ,
V_132 -> V_256 -> V_257 , V_251 ,
F_81 ( sin , V_86 , sizeof( V_86 ) ) ) ;
if ( V_251 != V_74 && V_251 != V_220 ) {
F_76 ( V_177 L_52
L_53 ) ;
return F_132 ( - V_258 ) ;
}
type = ( V_251 == V_74 ) ? V_239 : V_259 ;
switch ( sin -> V_260 ) {
case V_8 :
V_254 = V_94 ;
break;
case V_5 :
V_254 = V_90 ;
break;
default:
return F_132 ( - V_258 ) ;
}
error = F_145 ( V_154 , V_254 , type , V_251 , & V_2 , 1 ) ;
if ( error < 0 )
return F_132 ( error ) ;
F_1 ( V_2 ) ;
V_255 = 1 ;
if ( V_254 == V_94 )
F_45 ( V_2 , V_35 , V_261 ,
( char * ) & V_255 , sizeof( V_255 ) ) ;
if ( type == V_259 )
V_2 -> V_3 -> V_262 = V_263 ;
error = F_146 ( V_2 , sin , V_60 ) ;
if ( error < 0 )
goto V_264;
V_253 = V_60 ;
error = F_85 ( V_2 , V_252 , & V_253 ) ;
if ( error < 0 )
goto V_264;
if ( V_251 == V_220 ) {
if ( ( error = F_147 ( V_2 , 64 ) ) < 0 )
goto V_264;
}
V_15 = F_82 ( V_132 , V_2 , V_56 ) ;
if ( F_83 ( V_15 ) ) {
error = F_143 ( V_15 ) ;
goto V_264;
}
F_88 ( & V_15 -> V_17 , V_252 , V_253 ) ;
return (struct V_118 * ) V_15 ;
V_264:
F_8 ( L_54 , - error ) ;
F_90 ( V_2 ) ;
return F_132 ( error ) ;
}
static void F_148 ( struct V_118 * V_119 )
{
struct V_14 * V_15 = F_7 ( V_119 , struct V_14 , V_17 ) ;
struct V_2 * V_3 = V_15 -> V_18 ;
F_8 ( L_55 , V_15 ) ;
F_32 ( V_3 ) ;
V_3 -> V_180 = V_15 -> V_168 ;
V_3 -> V_163 = V_15 -> V_116 ;
V_3 -> V_113 = V_15 -> V_117 ;
V_3 -> V_114 = NULL ;
F_33 ( V_3 ) ;
}
static void F_149 ( struct V_118 * V_119 )
{
struct V_14 * V_15 = F_7 ( V_119 , struct V_14 , V_17 ) ;
F_8 ( L_56 , V_15 ) ;
F_148 ( V_119 ) ;
if ( ! F_38 ( V_120 , & V_119 -> V_104 ) ) {
F_96 ( V_15 ) ;
F_150 ( V_15 -> V_66 , V_265 ) ;
}
}
static void F_151 ( struct V_118 * V_119 )
{
struct V_14 * V_15 = F_7 ( V_119 , struct V_14 , V_17 ) ;
F_8 ( L_57 , V_15 ) ;
if ( V_15 -> V_66 -> V_266 )
F_139 ( V_15 -> V_66 ) ;
else
F_90 ( V_15 -> V_66 ) ;
F_135 ( V_15 ) ;
}
static struct V_118 * F_117 ( struct V_131 * V_132 ,
int V_251 ,
struct V_154 * V_154 ,
struct V_155 * sin , int V_60 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_118 * V_119 ;
if ( V_251 != V_220 ) {
F_76 ( V_177 L_58
L_59 ) ;
return F_132 ( - V_258 ) ;
}
V_15 = F_131 ( sizeof( * V_15 ) , V_237 ) ;
if ( ! V_15 )
return F_132 ( - V_176 ) ;
V_119 = & V_15 -> V_17 ;
F_73 ( V_154 , & V_228 , V_119 , V_132 ) ;
F_29 ( V_230 , & V_15 -> V_17 . V_104 ) ;
V_132 -> V_267 = V_119 ;
return V_119 ;
}
static void F_152 ( struct V_118 * V_119 )
{
if ( V_119 )
F_135 ( F_7 ( V_119 , struct V_14 , V_17 ) ) ;
}
