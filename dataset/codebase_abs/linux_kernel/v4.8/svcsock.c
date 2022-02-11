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
static void F_10 ( struct V_9 * V_10 , struct V_19 * V_20 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
switch ( V_15 -> V_18 -> V_4 ) {
case V_5 : {
struct V_21 * V_22 = F_11 ( V_20 ) ;
V_20 -> V_23 = V_24 ;
V_20 -> V_25 = V_26 ;
V_22 -> V_27 = 0 ;
V_22 -> V_28 . V_29 =
F_12 ( V_10 ) -> V_30 . V_29 ;
V_20 -> V_31 = F_13 ( sizeof( * V_22 ) ) ;
}
break;
case V_8 : {
struct V_32 * V_22 = F_11 ( V_20 ) ;
struct V_33 * V_34 = F_14 ( V_10 ) ;
V_20 -> V_23 = V_35 ;
V_20 -> V_25 = V_36 ;
V_22 -> V_37 = V_34 -> V_38 ;
V_22 -> V_39 = V_34 -> V_40 ;
V_20 -> V_31 = F_13 ( sizeof( * V_22 ) ) ;
}
break;
}
}
int F_15 ( struct V_1 * V_2 , struct V_41 * V_42 ,
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
V_60 = F_16 ( V_2 , V_44 , V_45 ,
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
V_48 = F_16 ( V_2 , * V_50 , V_52 , V_49 , V_56 ) ;
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
V_48 = F_16 ( V_2 , V_46 , V_47 ,
V_42 -> V_65 [ 0 ] . V_62 , 0 ) ;
if ( V_48 > 0 )
V_60 += V_48 ;
}
V_63:
return V_60 ;
}
static int F_17 ( struct V_9 * V_10 , struct V_41 * V_42 )
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
F_18 (char buf[RPC_MAX_ADDRBUFLEN]) ;
if ( V_10 -> V_73 == V_74 ) {
struct V_75 V_76 = {
. V_77 = & V_10 -> V_78 ,
. V_79 = V_10 -> V_80 ,
. V_81 = V_20 ,
. V_82 = sizeof( V_70 ) ,
. V_83 = V_57 ,
} ;
F_10 ( V_10 , V_20 ) ;
if ( F_19 ( V_2 , & V_76 ) < 0 )
goto V_63;
}
V_71 = ( ( unsigned long ) V_42 -> V_65 [ 0 ] . V_84 ) & ( V_64 - 1 ) ;
V_72 = 0 ;
V_60 = F_15 ( V_2 , V_42 , V_10 -> V_85 [ 0 ] , V_72 ,
V_10 -> V_85 [ 0 ] , V_71 ) ;
V_63:
F_8 ( L_6 ,
V_15 , V_42 -> V_61 [ 0 ] . V_84 , V_42 -> V_61 [ 0 ] . V_62 ,
V_42 -> V_60 , V_60 , F_20 ( V_10 , V_86 , sizeof( V_86 ) ) ) ;
return V_60 ;
}
static int F_21 ( struct V_14 * V_15 , char * V_86 , int V_87 )
{
const struct V_2 * V_3 = V_15 -> V_18 ;
const char * V_88 = V_3 -> V_89 == V_74 ?
L_7 : L_8 ;
int V_60 ;
switch ( V_3 -> V_4 ) {
case V_90 :
V_60 = snprintf ( V_86 , V_87 , L_9 ,
V_88 ,
& F_22 ( V_3 ) -> V_91 ,
F_22 ( V_3 ) -> V_92 ) ;
break;
#if F_23 ( V_93 )
case V_94 :
V_60 = snprintf ( V_86 , V_87 , L_10 ,
V_88 ,
& V_3 -> V_95 ,
F_22 ( V_3 ) -> V_92 ) ;
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
static int F_24 ( struct V_9 * V_10 , struct V_97 * V_98 , int V_99 ,
int V_100 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_75 V_76 = {
. V_83 = V_101 ,
} ;
int V_60 ;
V_10 -> V_102 = 0 ;
F_25 ( V_103 , & V_15 -> V_17 . V_104 ) ;
V_60 = F_26 ( V_15 -> V_66 , & V_76 , V_98 , V_99 , V_100 ,
V_76 . V_83 ) ;
if ( V_60 == V_100 )
F_27 ( V_103 , & V_15 -> V_17 . V_104 ) ;
F_8 ( L_12 ,
V_15 , V_98 [ 0 ] . V_84 , V_98 [ 0 ] . V_62 , V_60 ) ;
return V_60 ;
}
static int F_28 ( struct V_9 * V_10 ,
struct V_97 * V_98 , int V_99 ,
int V_100 , unsigned int V_52 )
{
T_1 V_105 ;
void * V_106 ;
unsigned int V_107 ;
int V_108 ;
if ( V_52 == 0 )
return F_24 ( V_10 , V_98 , V_99 , V_100 ) ;
for ( V_107 = 0 ; V_107 < V_99 ; V_107 ++ ) {
if ( V_98 [ V_107 ] . V_62 > V_52 )
break;
V_52 -= V_98 [ V_107 ] . V_62 ;
}
V_105 = V_98 [ V_107 ] . V_62 ;
V_106 = V_98 [ V_107 ] . V_84 ;
V_98 [ V_107 ] . V_62 -= V_52 ;
V_98 [ V_107 ] . V_84 += V_52 ;
V_108 = F_24 ( V_10 , & V_98 [ V_107 ] , V_99 - V_107 , V_100 ) ;
V_98 [ V_107 ] . V_62 = V_105 ;
V_98 [ V_107 ] . V_84 = V_106 ;
return V_108 ;
}
static void F_29 ( struct V_1 * V_2 , unsigned int V_109 ,
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
F_30 ( V_2 -> V_3 ) ;
V_2 -> V_3 -> V_111 = V_109 * 2 ;
V_2 -> V_3 -> V_112 = V_110 * 2 ;
V_2 -> V_3 -> V_113 ( V_2 -> V_3 ) ;
F_31 ( V_2 -> V_3 ) ;
#endif
}
static int F_32 ( struct V_9 * V_10 )
{
return F_33 ( F_34 ( V_10 ) ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_114 ;
if ( V_15 ) {
F_8 ( L_13 ,
V_15 , V_3 ,
F_36 ( V_115 , & V_15 -> V_17 . V_104 ) ) ;
V_15 -> V_116 ( V_3 ) ;
if ( ! F_37 ( V_103 , & V_15 -> V_17 . V_104 ) )
F_38 ( & V_15 -> V_17 ) ;
}
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) ( V_3 -> V_114 ) ;
if ( V_15 ) {
F_8 ( L_14 ,
V_15 , V_3 , F_36 ( V_115 , & V_15 -> V_17 . V_104 ) ) ;
V_15 -> V_117 ( V_3 ) ;
F_38 ( & V_15 -> V_17 ) ;
}
}
static int F_40 ( struct V_118 * V_119 )
{
struct V_14 * V_15 = F_7 ( V_119 , struct V_14 , V_17 ) ;
if ( F_36 ( V_120 , & V_119 -> V_104 ) )
return 1 ;
return ! F_36 ( V_121 , & V_15 -> V_66 -> V_56 ) ;
}
static int F_41 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = F_11 ( V_20 ) ;
struct V_122 * V_34 = F_12 ( V_10 ) ;
if ( V_20 -> V_25 != V_26 )
return 0 ;
V_34 -> V_123 = V_5 ;
V_34 -> V_30 . V_29 = V_22 -> V_28 . V_29 ;
return 1 ;
}
static int F_42 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
struct V_32 * V_22 = F_11 ( V_20 ) ;
struct V_33 * V_34 = F_14 ( V_10 ) ;
if ( V_20 -> V_25 != V_36 )
return 0 ;
V_34 -> V_124 = V_8 ;
V_34 -> V_40 = V_22 -> V_39 ;
V_34 -> V_38 = V_22 -> V_37 ;
return 1 ;
}
static int F_43 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
switch ( V_20 -> V_23 ) {
case V_24 :
return F_41 ( V_10 , V_20 ) ;
case V_35 :
return F_42 ( V_10 , V_20 ) ;
}
return 0 ;
}
static int F_44 ( struct V_9 * V_10 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_125 * V_126 = V_15 -> V_17 . V_127 ;
struct V_11 * V_12 ;
union {
struct V_19 V_67 ;
long V_68 [ V_69 / sizeof( long ) ] ;
} V_70 ;
struct V_19 * V_20 = & V_70 . V_67 ;
struct V_75 V_76 = {
. V_77 = F_34 ( V_10 ) ,
. V_81 = V_20 ,
. V_82 = sizeof( V_70 ) ,
. V_83 = V_101 ,
} ;
T_1 V_60 ;
int V_128 ;
if ( F_45 ( V_129 , & V_15 -> V_17 . V_104 ) )
F_29 ( V_15 -> V_66 ,
( V_126 -> V_130 + 3 ) * V_126 -> V_131 ,
( V_126 -> V_130 + 3 ) * V_126 -> V_131 ) ;
F_25 ( V_103 , & V_15 -> V_17 . V_104 ) ;
V_12 = NULL ;
V_128 = F_26 ( V_15 -> V_66 , & V_76 , NULL ,
0 , 0 , V_132 | V_101 ) ;
if ( V_128 >= 0 )
V_12 = F_46 ( V_15 -> V_18 , 0 , 1 , & V_128 ) ;
if ( V_12 == NULL ) {
if ( V_128 != - V_133 ) {
F_8 ( L_15 , - V_128 ) ;
F_27 ( V_103 , & V_15 -> V_17 . V_104 ) ;
}
return 0 ;
}
V_60 = F_47 ( F_34 ( V_10 ) ) ;
V_10 -> V_80 = V_60 ;
if ( V_12 -> V_134 . V_135 == 0 ) {
V_12 -> V_134 = F_48 () ;
}
V_15 -> V_18 -> V_136 = V_12 -> V_134 ;
F_27 ( V_103 , & V_15 -> V_17 . V_104 ) ;
V_60 = V_12 -> V_60 ;
V_10 -> V_137 . V_60 = V_60 ;
V_10 -> V_73 = V_74 ;
if ( ! F_43 ( V_10 , V_20 ) ) {
F_49 ( L_16 ,
V_20 -> V_23 , V_20 -> V_25 ) ;
goto V_138;
}
V_10 -> V_139 = F_47 ( F_50 ( V_10 ) ) ;
if ( F_51 ( V_12 ) ) {
F_52 () ;
if ( F_53 ( & V_10 -> V_137 , V_12 ) ) {
F_54 () ;
goto V_138;
}
F_54 () ;
F_9 ( V_15 -> V_18 , V_12 ) ;
} else {
V_10 -> V_137 . V_61 [ 0 ] . V_84 = V_12 -> V_140 ;
V_10 -> V_137 . V_61 [ 0 ] . V_62 = V_60 ;
if ( F_55 ( V_12 ) )
goto V_138;
V_10 -> V_13 = V_12 ;
}
V_10 -> V_137 . V_53 = 0 ;
if ( V_60 <= V_10 -> V_137 . V_61 [ 0 ] . V_62 ) {
V_10 -> V_137 . V_61 [ 0 ] . V_62 = V_60 ;
V_10 -> V_137 . V_55 = 0 ;
V_10 -> V_85 = V_10 -> V_141 + 1 ;
} else {
V_10 -> V_137 . V_55 = V_60 - V_10 -> V_137 . V_61 [ 0 ] . V_62 ;
V_10 -> V_85 = V_10 -> V_141 + 1 +
F_56 ( V_10 -> V_137 . V_55 , V_64 ) ;
}
V_10 -> V_142 = V_10 -> V_85 + 1 ;
if ( V_126 -> V_143 )
V_126 -> V_143 -> V_144 ++ ;
return V_60 ;
V_138:
F_57 ( V_12 , F_44 ) ;
F_9 ( V_15 -> V_18 , V_12 ) ;
return 0 ;
}
static int
F_58 ( struct V_9 * V_10 )
{
int error ;
error = F_17 ( V_10 , & V_10 -> V_145 ) ;
if ( error == - V_146 )
error = F_17 ( V_10 , & V_10 -> V_145 ) ;
return error ;
}
static void F_59 ( struct V_9 * V_10 )
{
}
static int F_60 ( struct V_118 * V_119 )
{
struct V_14 * V_15 = F_7 ( V_119 , struct V_14 , V_17 ) ;
struct V_125 * V_126 = V_119 -> V_127 ;
unsigned long V_147 ;
F_27 ( V_121 , & V_15 -> V_66 -> V_56 ) ;
V_147 = F_61 ( & V_15 -> V_17 . V_148 ) + V_126 -> V_131 ;
if ( V_147 * 2 > F_62 ( V_15 -> V_18 ) )
return 0 ;
F_25 ( V_121 , & V_15 -> V_66 -> V_56 ) ;
return 1 ;
}
static struct V_118 * F_63 ( struct V_118 * V_119 )
{
F_5 () ;
return NULL ;
}
static struct V_118 * F_64 ( struct V_125 * V_126 ,
struct V_149 * V_149 ,
struct V_150 * V_151 , int V_152 ,
int V_56 )
{
return F_65 ( V_126 , V_74 , V_149 , V_151 , V_152 , V_56 ) ;
}
static void F_66 ( struct V_14 * V_15 , struct V_125 * V_126 )
{
int V_128 , V_153 , V_154 , V_155 = 1 ;
F_67 ( F_68 ( V_15 -> V_66 -> V_3 ) , & V_156 ,
& V_15 -> V_17 , V_126 ) ;
F_25 ( V_157 , & V_15 -> V_17 . V_104 ) ;
V_15 -> V_18 -> V_158 = F_35 ;
V_15 -> V_18 -> V_113 = F_39 ;
F_29 ( V_15 -> V_66 ,
3 * V_15 -> V_17 . V_127 -> V_131 ,
3 * V_15 -> V_17 . V_127 -> V_131 ) ;
F_27 ( V_103 , & V_15 -> V_17 . V_104 ) ;
F_27 ( V_129 , & V_15 -> V_17 . V_104 ) ;
switch ( V_15 -> V_18 -> V_4 ) {
case V_5 :
V_153 = V_24 ;
V_154 = V_26 ;
break;
case V_8 :
V_153 = V_35 ;
V_154 = V_159 ;
break;
default:
F_5 () ;
}
V_128 = F_69 ( V_15 -> V_66 , V_153 , V_154 ,
( char * ) & V_155 , sizeof( V_155 ) ) ;
F_8 ( L_17 , V_128 ) ;
}
static void F_70 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_114 ;
F_8 ( L_18 ,
V_3 , V_3 -> V_160 ) ;
if ( V_15 )
V_15 -> V_116 ( V_3 ) ;
if ( V_3 -> V_160 == V_161 ) {
if ( V_15 ) {
F_27 ( V_162 , & V_15 -> V_17 . V_104 ) ;
F_38 ( & V_15 -> V_17 ) ;
} else
F_71 ( L_19 , V_3 ) ;
}
}
static void F_72 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_114 ;
F_8 ( L_20 ,
V_3 , V_3 -> V_160 , V_3 -> V_114 ) ;
if ( ! V_15 )
F_71 ( L_19 , V_3 ) ;
else {
V_15 -> V_163 ( V_3 ) ;
if ( V_3 -> V_160 != V_164 ) {
F_27 ( V_165 , & V_15 -> V_17 . V_104 ) ;
F_38 ( & V_15 -> V_17 ) ;
}
}
}
static struct V_118 * F_73 ( struct V_118 * V_119 )
{
struct V_14 * V_15 = F_7 ( V_119 , struct V_14 , V_17 ) ;
struct V_166 V_167 ;
struct V_150 * sin = (struct V_150 * ) & V_167 ;
struct V_125 * V_126 = V_15 -> V_17 . V_127 ;
struct V_1 * V_2 = V_15 -> V_66 ;
struct V_1 * V_168 ;
struct V_14 * V_169 ;
int V_128 , V_59 ;
F_18 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_8 ( L_21 , V_15 , V_2 ) ;
if ( ! V_2 )
return NULL ;
F_25 ( V_162 , & V_15 -> V_17 . V_104 ) ;
V_128 = F_74 ( V_2 , & V_168 , V_170 ) ;
if ( V_128 < 0 ) {
if ( V_128 == - V_171 )
F_71 ( V_172 L_22 ,
V_126 -> V_173 ) ;
else if ( V_128 != - V_133 )
F_49 ( L_23 ,
V_126 -> V_173 , - V_128 ) ;
return NULL ;
}
F_27 ( V_162 , & V_15 -> V_17 . V_104 ) ;
V_128 = F_75 ( V_168 , sin , & V_59 ) ;
if ( V_128 < 0 ) {
F_49 ( L_24 ,
V_126 -> V_173 , - V_128 ) ;
goto V_174;
}
if ( ! F_33 ( sin ) ) {
F_8 ( L_25 ,
V_126 -> V_173 ,
F_76 ( sin , V_86 , sizeof( V_86 ) ) ) ;
}
F_8 ( L_26 , V_126 -> V_173 ,
F_76 ( sin , V_86 , sizeof( V_86 ) ) ) ;
V_168 -> V_3 -> V_175 = V_15 -> V_163 ;
V_168 -> V_3 -> V_158 = V_15 -> V_116 ;
V_168 -> V_3 -> V_113 = V_15 -> V_117 ;
V_168 -> V_3 -> V_176 = V_177 * 30 ;
V_169 = F_77 ( V_126 , V_168 ,
( V_178 | V_179 ) ) ;
if ( F_78 ( V_169 ) )
goto V_174;
F_79 ( & V_169 -> V_17 , sin , V_59 ) ;
V_128 = F_80 ( V_168 , sin , & V_59 ) ;
if ( F_81 ( V_128 < 0 ) ) {
F_8 ( L_27 , - V_128 ) ;
V_59 = F_82 ( struct V_150 , V_180 ) ;
}
F_83 ( & V_169 -> V_17 , sin , V_59 ) ;
if ( F_84 ( V_168 -> V_3 ) )
F_27 ( V_181 , & V_169 -> V_17 . V_104 ) ;
else
F_25 ( V_181 , & V_169 -> V_17 . V_104 ) ;
if ( V_126 -> V_143 )
V_126 -> V_143 -> V_182 ++ ;
return & V_169 -> V_17 ;
V_174:
F_85 ( V_168 ) ;
return NULL ;
}
static unsigned int F_86 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
unsigned int V_107 , V_60 , V_183 ;
if ( V_15 -> V_184 == 0 )
return 0 ;
V_60 = V_15 -> V_184 ;
V_183 = ( V_60 + V_64 - 1 ) >> V_185 ;
for ( V_107 = 0 ; V_107 < V_183 ; V_107 ++ ) {
if ( V_10 -> V_141 [ V_107 ] != NULL )
F_87 ( V_10 -> V_141 [ V_107 ] ) ;
F_88 ( V_15 -> V_186 [ V_107 ] == NULL ) ;
V_10 -> V_141 [ V_107 ] = V_15 -> V_186 [ V_107 ] ;
V_15 -> V_186 [ V_107 ] = NULL ;
}
V_10 -> V_137 . V_61 [ 0 ] . V_84 = F_89 ( V_10 -> V_141 [ 0 ] ) ;
return V_60 ;
}
static void F_90 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
unsigned int V_107 , V_60 , V_183 ;
if ( V_15 -> V_184 == 0 )
return;
V_60 = V_15 -> V_184 ;
V_183 = ( V_60 + V_64 - 1 ) >> V_185 ;
for ( V_107 = 0 ; V_107 < V_183 ; V_107 ++ ) {
V_15 -> V_186 [ V_107 ] = V_10 -> V_141 [ V_107 ] ;
V_10 -> V_141 [ V_107 ] = NULL ;
}
}
static void F_91 ( struct V_14 * V_15 )
{
unsigned int V_107 , V_60 , V_183 ;
if ( V_15 -> V_184 == 0 )
goto V_63;
V_60 = V_15 -> V_184 ;
V_183 = ( V_60 + V_64 - 1 ) >> V_185 ;
for ( V_107 = 0 ; V_107 < V_183 ; V_107 ++ ) {
if ( V_15 -> V_186 [ V_107 ] == NULL ) {
F_2 ( 1 ) ;
continue;
}
F_87 ( V_15 -> V_186 [ V_107 ] ) ;
V_15 -> V_186 [ V_107 ] = NULL ;
}
V_63:
V_15 -> V_187 = 0 ;
V_15 -> V_184 = 0 ;
}
static int F_92 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
struct V_125 * V_126 = V_15 -> V_17 . V_127 ;
unsigned int V_188 ;
int V_60 ;
if ( V_15 -> V_187 < sizeof( V_189 ) ) {
struct V_97 V_98 ;
V_188 = sizeof( V_189 ) - V_15 -> V_187 ;
V_98 . V_84 = ( ( char * ) & V_15 -> V_190 ) + V_15 -> V_187 ;
V_98 . V_62 = V_188 ;
if ( ( V_60 = F_24 ( V_10 , & V_98 , 1 , V_188 ) ) < 0 )
goto error;
V_15 -> V_187 += V_60 ;
if ( V_60 < V_188 ) {
F_8 ( L_28
L_29 , V_60 , V_188 ) ;
return - V_133 ;
}
F_8 ( L_30 , F_93 ( V_15 ) ) ;
if ( F_93 ( V_15 ) + V_15 -> V_184 >
V_126 -> V_131 ) {
F_94 ( L_31 ,
F_93 ( V_15 ) ) ;
goto V_191;
}
}
return F_93 ( V_15 ) ;
error:
F_8 ( L_32 , V_60 ) ;
return V_60 ;
V_191:
F_27 ( V_165 , & V_15 -> V_17 . V_104 ) ;
return - V_133 ;
}
static int F_95 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
struct V_192 * V_193 = V_15 -> V_17 . V_194 ;
struct V_195 * V_196 = NULL ;
struct V_97 * V_197 , * V_198 ;
T_2 * V_199 = ( T_2 * ) V_10 -> V_137 . V_61 [ 0 ] . V_84 ;
T_2 V_200 ;
T_2 V_201 ;
V_200 = * V_199 ++ ;
V_201 = * V_199 ;
if ( ! V_193 )
return - V_133 ;
F_96 ( & V_193 -> V_202 ) ;
V_196 = F_97 ( V_193 , V_200 ) ;
if ( ! V_196 )
goto V_203;
memcpy ( & V_196 -> V_204 , & V_196 -> V_205 , sizeof( struct V_41 ) ) ;
V_198 = & V_196 -> V_204 . V_61 [ 0 ] ;
V_197 = & V_10 -> V_137 . V_61 [ 0 ] ;
if ( V_198 -> V_62 < V_197 -> V_62 )
goto V_206;
memcpy ( V_198 -> V_84 , V_197 -> V_84 , V_197 -> V_62 ) ;
F_98 ( V_196 -> V_207 , V_10 -> V_137 . V_60 ) ;
V_10 -> V_137 . V_60 = 0 ;
F_99 ( & V_193 -> V_202 ) ;
return 0 ;
V_203:
F_71 ( V_208
L_33
L_34 ,
V_209 , F_100 ( V_201 ) ,
V_193 , F_100 ( V_200 ) ) ;
V_206:
F_99 ( & V_193 -> V_202 ) ;
return - V_133 ;
}
static int F_101 ( struct V_97 * V_210 , struct V_43 * * V_51 , int V_60 )
{
int V_107 = 0 ;
int V_211 = 0 ;
while ( V_211 < V_60 ) {
V_210 [ V_107 ] . V_84 = F_89 ( V_51 [ V_107 ] ) ;
V_210 [ V_107 ] . V_62 = V_64 ;
V_107 ++ ;
V_211 += V_64 ;
}
return V_107 ;
}
static void F_102 ( struct V_14 * V_15 )
{
F_8 ( L_35 ,
F_103 ( V_15 ) ? L_36 : L_37 ,
F_93 ( V_15 ) ) ;
V_15 -> V_187 = 0 ;
V_15 -> V_190 = 0 ;
}
static int F_104 ( struct V_9 * V_10 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_125 * V_126 = V_15 -> V_17 . V_127 ;
int V_60 ;
struct V_97 * V_210 ;
unsigned int V_188 , V_52 ;
T_2 * V_199 ;
T_2 V_201 ;
int V_212 ;
F_8 ( L_38 ,
V_15 , F_36 ( V_103 , & V_15 -> V_17 . V_104 ) ,
F_36 ( V_162 , & V_15 -> V_17 . V_104 ) ,
F_36 ( V_165 , & V_15 -> V_17 . V_104 ) ) ;
V_60 = F_92 ( V_15 , V_10 ) ;
if ( V_60 < 0 )
goto error;
V_52 = F_86 ( V_15 , V_10 ) ;
V_188 = F_93 ( V_15 ) - ( V_15 -> V_187 - sizeof( V_189 ) ) ;
V_210 = V_10 -> V_213 ;
V_212 = F_101 ( & V_210 [ 0 ] , & V_10 -> V_141 [ 0 ] ,
V_15 -> V_184 + V_188 ) ;
V_10 -> V_85 = & V_10 -> V_141 [ V_212 ] ;
V_10 -> V_142 = V_10 -> V_85 + 1 ;
V_60 = F_28 ( V_10 , V_210 , V_212 , V_188 , V_52 ) ;
if ( V_60 >= 0 ) {
V_15 -> V_187 += V_60 ;
V_15 -> V_184 += V_60 ;
}
if ( V_60 != V_188 || ! F_103 ( V_15 ) ) {
F_90 ( V_15 , V_10 ) ;
if ( V_60 < 0 && V_60 != - V_133 )
goto V_191;
if ( V_60 == V_188 )
F_102 ( V_15 ) ;
else
F_8 ( L_39 ,
( int ) ( V_15 -> V_187 - sizeof( V_189 ) ) ,
F_93 ( V_15 ) ) ;
goto V_214;
}
if ( V_15 -> V_184 < 8 ) {
V_15 -> V_184 = 0 ;
goto V_191;
}
V_10 -> V_137 . V_60 = V_15 -> V_184 ;
V_10 -> V_137 . V_53 = 0 ;
if ( V_10 -> V_137 . V_60 <= V_10 -> V_137 . V_61 [ 0 ] . V_62 ) {
V_10 -> V_137 . V_61 [ 0 ] . V_62 = V_10 -> V_137 . V_60 ;
V_10 -> V_137 . V_55 = 0 ;
} else
V_10 -> V_137 . V_55 = V_10 -> V_137 . V_60 - V_10 -> V_137 . V_61 [ 0 ] . V_62 ;
V_10 -> V_13 = NULL ;
V_10 -> V_73 = V_215 ;
if ( F_36 ( V_181 , & V_15 -> V_17 . V_104 ) )
F_27 ( V_216 , & V_10 -> V_217 ) ;
else
F_25 ( V_216 , & V_10 -> V_217 ) ;
V_199 = ( T_2 * ) V_10 -> V_137 . V_61 [ 0 ] . V_84 ;
V_201 = V_199 [ 1 ] ;
if ( V_201 )
V_60 = F_95 ( V_15 , V_10 ) ;
V_15 -> V_184 = 0 ;
F_102 ( V_15 ) ;
if ( V_60 < 0 )
goto error;
F_105 ( V_10 , & V_15 -> V_17 ) ;
if ( V_126 -> V_143 )
V_126 -> V_143 -> V_218 ++ ;
return V_10 -> V_137 . V_60 ;
error:
if ( V_60 != - V_133 )
goto V_191;
F_8 ( L_40 ) ;
return 0 ;
V_191:
F_71 ( V_208 L_41 ,
V_15 -> V_17 . V_127 -> V_173 , - V_60 ) ;
F_27 ( V_165 , & V_15 -> V_17 . V_104 ) ;
V_214:
return 0 ;
}
static int F_106 ( struct V_9 * V_10 )
{
struct V_41 * V_219 = & V_10 -> V_145 ;
int V_220 ;
T_2 V_221 ;
V_221 = F_107 ( 0x80000000 | ( ( V_219 -> V_60 ) - 4 ) ) ;
memcpy ( V_219 -> V_61 [ 0 ] . V_84 , & V_221 , 4 ) ;
V_220 = F_17 ( V_10 , & V_10 -> V_145 ) ;
if ( V_220 != V_219 -> V_60 ) {
F_71 ( V_208
L_42
L_43 ,
V_10 -> V_16 -> V_127 -> V_173 ,
( V_220 < 0 ) ? L_44 : L_45 ,
V_220 , V_219 -> V_60 ) ;
F_27 ( V_165 , & V_10 -> V_16 -> V_104 ) ;
F_38 ( V_10 -> V_16 ) ;
V_220 = - V_133 ;
}
return V_220 ;
}
static void F_108 ( struct V_9 * V_10 )
{
struct V_97 * V_222 = & V_10 -> V_145 . V_61 [ 0 ] ;
F_109 ( V_222 , 0 ) ;
}
static struct V_118 * F_110 ( struct V_125 * V_126 ,
struct V_149 * V_149 ,
struct V_150 * V_151 , int V_152 ,
int V_56 )
{
return F_65 ( V_126 , V_215 , V_149 , V_151 , V_152 , V_56 ) ;
}
static struct V_118 * F_111 ( struct V_125 * V_126 ,
struct V_149 * V_149 ,
struct V_150 * V_151 , int V_152 ,
int V_56 )
{
return F_112 ( V_126 , V_215 , V_149 , V_151 , V_152 , V_56 ) ;
}
static void F_113 ( struct V_118 * V_119 )
{
}
static void F_114 ( void )
{
F_115 ( & V_223 ) ;
}
static void F_116 ( void )
{
F_117 ( & V_223 ) ;
}
static void F_114 ( void )
{
}
static void F_116 ( void )
{
}
void F_118 ( void )
{
F_115 ( & V_224 ) ;
F_115 ( & V_156 ) ;
F_114 () ;
}
void F_119 ( void )
{
F_117 ( & V_224 ) ;
F_117 ( & V_156 ) ;
F_116 () ;
}
static void F_120 ( struct V_14 * V_15 , struct V_125 * V_126 )
{
struct V_2 * V_3 = V_15 -> V_18 ;
F_67 ( F_68 ( V_15 -> V_66 -> V_3 ) , & V_224 ,
& V_15 -> V_17 , V_126 ) ;
F_27 ( V_157 , & V_15 -> V_17 . V_104 ) ;
if ( V_3 -> V_160 == V_161 ) {
F_8 ( L_46 ) ;
F_27 ( V_120 , & V_15 -> V_17 . V_104 ) ;
V_3 -> V_158 = F_70 ;
F_27 ( V_162 , & V_15 -> V_17 . V_104 ) ;
} else {
F_8 ( L_47 ) ;
V_3 -> V_175 = F_72 ;
V_3 -> V_158 = F_35 ;
V_3 -> V_113 = F_39 ;
V_15 -> V_190 = 0 ;
V_15 -> V_187 = 0 ;
V_15 -> V_184 = 0 ;
memset ( & V_15 -> V_186 [ 0 ] , 0 , sizeof( V_15 -> V_186 ) ) ;
F_121 ( V_3 ) -> V_225 |= V_226 ;
F_27 ( V_103 , & V_15 -> V_17 . V_104 ) ;
switch ( V_3 -> V_160 ) {
case V_227 :
case V_164 :
break;
default:
F_27 ( V_165 , & V_15 -> V_17 . V_104 ) ;
}
}
}
void F_122 ( struct V_125 * V_126 )
{
struct V_14 * V_15 ;
F_96 ( & V_126 -> V_228 ) ;
F_123 (svsk, &serv->sv_permsocks, sk_xprt.xpt_list)
F_27 ( V_129 , & V_15 -> V_17 . V_104 ) ;
F_99 ( & V_126 -> V_228 ) ;
}
static struct V_14 * F_77 ( struct V_125 * V_126 ,
struct V_1 * V_2 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_2 * V_229 ;
int V_230 = ! ( V_56 & V_178 ) ;
int V_128 = 0 ;
F_8 ( L_48 , V_2 ) ;
V_15 = F_124 ( sizeof( * V_15 ) , V_231 ) ;
if ( ! V_15 )
return F_125 ( - V_171 ) ;
V_229 = V_2 -> V_3 ;
if ( V_230 )
V_128 = F_126 ( V_126 , F_68 ( V_2 -> V_3 ) , V_229 -> V_4 ,
V_229 -> V_89 ,
F_127 ( F_22 ( V_229 ) -> V_232 ) ) ;
if ( V_128 < 0 ) {
F_128 ( V_15 ) ;
return F_125 ( V_128 ) ;
}
V_229 -> V_114 = V_15 ;
V_15 -> V_66 = V_2 ;
V_15 -> V_18 = V_229 ;
V_15 -> V_163 = V_229 -> V_175 ;
V_15 -> V_116 = V_229 -> V_158 ;
V_15 -> V_117 = V_229 -> V_113 ;
if ( V_2 -> type == V_233 )
F_66 ( V_15 , V_126 ) ;
else
F_120 ( V_15 , V_126 ) ;
F_8 ( L_49
L_50 ,
V_15 , V_15 -> V_18 ,
F_36 ( V_120 , & V_15 -> V_17 . V_104 ) ,
F_36 ( V_165 , & V_15 -> V_17 . V_104 ) ) ;
return V_15 ;
}
bool F_129 ( struct V_149 * V_149 , int V_234 )
{
int V_128 ;
struct V_1 * V_2 = F_130 ( V_234 , & V_128 ) ;
bool V_108 = false ;
if ( ! V_2 )
goto V_63;
if ( F_68 ( V_2 -> V_3 ) != V_149 )
V_108 = true ;
F_131 ( V_2 ) ;
V_63:
return V_108 ;
}
int F_132 ( struct V_125 * V_126 , const int V_234 , char * V_235 ,
const T_1 V_60 )
{
int V_128 = 0 ;
struct V_1 * V_236 = F_130 ( V_234 , & V_128 ) ;
struct V_14 * V_15 = NULL ;
struct V_166 V_167 ;
struct V_150 * sin = (struct V_150 * ) & V_167 ;
int V_152 ;
if ( ! V_236 )
return V_128 ;
V_128 = - V_237 ;
if ( ( V_236 -> V_3 -> V_4 != V_90 ) && ( V_236 -> V_3 -> V_4 != V_94 ) )
goto V_63;
V_128 = - V_238 ;
if ( V_236 -> V_3 -> V_89 != V_215 &&
V_236 -> V_3 -> V_89 != V_74 )
goto V_63;
V_128 = - V_239 ;
if ( V_236 -> V_240 > V_241 )
goto V_63;
V_128 = - V_242 ;
if ( ! F_133 ( V_243 ) )
goto V_63;
V_15 = F_77 ( V_126 , V_236 , V_244 ) ;
if ( F_78 ( V_15 ) ) {
F_134 ( V_243 ) ;
V_128 = F_135 ( V_15 ) ;
goto V_63;
}
if ( F_80 ( V_15 -> V_66 , sin , & V_152 ) == 0 )
F_83 ( & V_15 -> V_17 , sin , V_152 ) ;
F_136 ( V_126 , & V_15 -> V_17 ) ;
return F_21 ( V_15 , V_235 , V_60 ) ;
V_63:
F_131 ( V_236 ) ;
return V_128 ;
}
static struct V_118 * F_65 ( struct V_125 * V_126 ,
int V_245 ,
struct V_149 * V_149 ,
struct V_150 * sin , int V_60 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int error ;
int type ;
struct V_166 V_167 ;
struct V_150 * V_246 = (struct V_150 * ) & V_167 ;
int V_247 ;
int V_248 ;
int V_249 ;
F_18 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_8 ( L_51 ,
V_126 -> V_250 -> V_251 , V_245 ,
F_76 ( sin , V_86 , sizeof( V_86 ) ) ) ;
if ( V_245 != V_74 && V_245 != V_215 ) {
F_71 ( V_172 L_52
L_53 ) ;
return F_125 ( - V_252 ) ;
}
type = ( V_245 == V_74 ) ? V_233 : V_253 ;
switch ( sin -> V_254 ) {
case V_8 :
V_248 = V_94 ;
break;
case V_5 :
V_248 = V_90 ;
break;
default:
return F_125 ( - V_252 ) ;
}
error = F_137 ( V_149 , V_248 , type , V_245 , & V_2 , 1 ) ;
if ( error < 0 )
return F_125 ( error ) ;
F_1 ( V_2 ) ;
V_249 = 1 ;
if ( V_248 == V_94 )
F_69 ( V_2 , V_35 , V_255 ,
( char * ) & V_249 , sizeof( V_249 ) ) ;
if ( type == V_253 )
V_2 -> V_3 -> V_256 = V_257 ;
error = F_138 ( V_2 , sin , V_60 ) ;
if ( error < 0 )
goto V_258;
V_247 = V_60 ;
error = F_80 ( V_2 , V_246 , & V_247 ) ;
if ( error < 0 )
goto V_258;
if ( V_245 == V_215 ) {
if ( ( error = F_139 ( V_2 , 64 ) ) < 0 )
goto V_258;
}
V_15 = F_77 ( V_126 , V_2 , V_56 ) ;
if ( F_78 ( V_15 ) ) {
error = F_135 ( V_15 ) ;
goto V_258;
}
F_83 ( & V_15 -> V_17 , V_246 , V_247 ) ;
return (struct V_118 * ) V_15 ;
V_258:
F_8 ( L_54 , - error ) ;
F_85 ( V_2 ) ;
return F_125 ( error ) ;
}
static void F_140 ( struct V_118 * V_119 )
{
struct V_14 * V_15 = F_7 ( V_119 , struct V_14 , V_17 ) ;
struct V_2 * V_3 = V_15 -> V_18 ;
F_8 ( L_55 , V_15 ) ;
F_30 ( V_3 ) ;
V_3 -> V_175 = V_15 -> V_163 ;
V_3 -> V_158 = V_15 -> V_116 ;
V_3 -> V_113 = V_15 -> V_117 ;
V_3 -> V_114 = NULL ;
F_31 ( V_3 ) ;
}
static void F_141 ( struct V_118 * V_119 )
{
struct V_14 * V_15 = F_7 ( V_119 , struct V_14 , V_17 ) ;
F_8 ( L_56 , V_15 ) ;
F_140 ( V_119 ) ;
if ( ! F_36 ( V_120 , & V_119 -> V_104 ) ) {
F_91 ( V_15 ) ;
F_142 ( V_15 -> V_66 , V_259 ) ;
}
}
static void F_143 ( struct V_118 * V_119 )
{
struct V_14 * V_15 = F_7 ( V_119 , struct V_14 , V_17 ) ;
F_8 ( L_57 , V_15 ) ;
if ( V_15 -> V_66 -> V_260 )
F_131 ( V_15 -> V_66 ) ;
else
F_85 ( V_15 -> V_66 ) ;
F_128 ( V_15 ) ;
}
static struct V_118 * F_112 ( struct V_125 * V_126 ,
int V_245 ,
struct V_149 * V_149 ,
struct V_150 * sin , int V_60 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_118 * V_119 ;
if ( V_245 != V_215 ) {
F_71 ( V_172 L_58
L_59 ) ;
return F_125 ( - V_252 ) ;
}
V_15 = F_124 ( sizeof( * V_15 ) , V_231 ) ;
if ( ! V_15 )
return F_125 ( - V_171 ) ;
V_119 = & V_15 -> V_17 ;
F_67 ( V_149 , & V_223 , V_119 , V_126 ) ;
V_126 -> V_261 = V_119 ;
return V_119 ;
}
static void F_144 ( struct V_118 * V_119 )
{
if ( V_119 )
F_128 ( F_7 ( V_119 , struct V_14 , V_17 ) ) ;
}
