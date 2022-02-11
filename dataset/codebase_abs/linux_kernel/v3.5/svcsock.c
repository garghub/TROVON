static void F_1 ( struct V_1 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
F_2 ( F_3 ( V_3 ) ) ;
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
unsigned int V_56 = V_57 ;
int V_58 ;
int V_59 = 0 ;
V_58 = V_42 -> V_59 ;
if ( V_58 == V_42 -> V_60 [ 0 ] . V_61 )
V_56 = 0 ;
V_59 = F_16 ( V_2 , V_44 , V_45 ,
V_42 -> V_60 [ 0 ] . V_61 , V_56 ) ;
if ( V_59 != V_42 -> V_60 [ 0 ] . V_61 )
goto V_62;
V_58 -= V_42 -> V_60 [ 0 ] . V_61 ;
if ( V_58 == 0 )
goto V_62;
V_49 = V_63 - V_52 < V_54 ? V_63 - V_52 : V_54 ;
while ( V_54 > 0 ) {
if ( V_58 == V_49 )
V_56 = 0 ;
V_48 = F_16 ( V_2 , * V_50 , V_52 , V_49 , V_56 ) ;
if ( V_48 > 0 )
V_59 += V_48 ;
if ( V_48 != V_49 )
goto V_62;
V_58 -= V_49 ;
V_54 -= V_49 ;
V_49 = V_63 < V_54 ? V_63 : V_54 ;
V_52 = 0 ;
V_50 ++ ;
}
if ( V_42 -> V_64 [ 0 ] . V_61 ) {
V_48 = F_16 ( V_2 , V_46 , V_47 ,
V_42 -> V_64 [ 0 ] . V_61 , 0 ) ;
if ( V_48 > 0 )
V_59 += V_48 ;
}
V_62:
return V_59 ;
}
static int F_17 ( struct V_9 * V_10 , struct V_41 * V_42 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_1 * V_2 = V_15 -> V_65 ;
union {
struct V_19 V_66 ;
long V_67 [ V_68 / sizeof( long ) ] ;
} V_69 ;
struct V_19 * V_20 = & V_69 . V_66 ;
int V_59 = 0 ;
unsigned long V_70 ;
unsigned long V_71 ;
F_18 (char buf[RPC_MAX_ADDRBUFLEN]) ;
if ( V_10 -> V_72 == V_73 ) {
struct V_74 V_75 = {
. V_76 = & V_10 -> V_77 ,
. V_78 = V_10 -> V_79 ,
. V_80 = V_20 ,
. V_81 = sizeof( V_69 ) ,
. V_82 = V_57 ,
} ;
F_10 ( V_10 , V_20 ) ;
if ( F_19 ( V_2 , & V_75 , 0 ) < 0 )
goto V_62;
}
V_70 = ( ( unsigned long ) V_42 -> V_64 [ 0 ] . V_83 ) & ( V_63 - 1 ) ;
V_71 = 0 ;
V_59 = F_15 ( V_2 , V_42 , V_10 -> V_84 [ 0 ] , V_71 ,
V_10 -> V_84 [ 0 ] , V_70 ) ;
V_62:
F_8 ( L_6 ,
V_15 , V_42 -> V_60 [ 0 ] . V_83 , V_42 -> V_60 [ 0 ] . V_61 ,
V_42 -> V_59 , V_59 , F_20 ( V_10 , V_85 , sizeof( V_85 ) ) ) ;
return V_59 ;
}
static int F_21 ( struct V_14 * V_15 , char * V_85 , int V_86 )
{
const struct V_2 * V_3 = V_15 -> V_18 ;
const char * V_87 = V_3 -> V_88 == V_73 ?
L_7 : L_8 ;
int V_59 ;
switch ( V_3 -> V_4 ) {
case V_89 :
V_59 = snprintf ( V_85 , V_86 , L_9 ,
V_87 ,
& F_22 ( V_3 ) -> V_90 ,
F_22 ( V_3 ) -> V_91 ) ;
break;
case V_92 :
V_59 = snprintf ( V_85 , V_86 , L_10 ,
V_87 ,
& F_23 ( V_3 ) -> V_93 ,
F_22 ( V_3 ) -> V_91 ) ;
break;
default:
V_59 = snprintf ( V_85 , V_86 , L_11 ,
V_3 -> V_4 ) ;
}
if ( V_59 >= V_86 ) {
* V_85 = '\0' ;
return - V_94 ;
}
return V_59 ;
}
int F_24 ( struct V_95 * V_96 , char * V_85 , const T_1 V_97 ,
const char * V_98 )
{
struct V_14 * V_15 , * V_99 = NULL ;
int V_59 = 0 ;
if ( ! V_96 )
return 0 ;
F_25 ( & V_96 -> V_100 ) ;
F_26 (svsk, &serv->sv_permsocks, sk_xprt.xpt_list) {
int V_101 = F_21 ( V_15 , V_85 + V_59 , V_97 - V_59 ) ;
if ( V_101 < 0 ) {
V_59 = V_101 ;
break;
}
if ( V_98 && strcmp ( V_98 , V_85 + V_59 ) == 0 ) {
V_99 = V_15 ;
F_27 ( & V_99 -> V_17 ) ;
} else
V_59 += V_101 ;
}
F_28 ( & V_96 -> V_100 ) ;
if ( V_99 ) {
F_29 ( & V_99 -> V_17 ) ;
F_30 ( & V_99 -> V_17 ) ;
} else if ( V_98 )
return - V_102 ;
return V_59 ;
}
static int F_31 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_65 ;
int V_103 , V_104 ;
V_104 = F_32 ( V_2 , V_105 , ( unsigned long ) & V_103 ) ;
return ( V_104 >= 0 ) ? V_103 : V_104 ;
}
static int F_33 ( struct V_9 * V_10 , struct V_106 * V_107 , int V_108 ,
int V_97 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_74 V_75 = {
. V_82 = V_109 ,
} ;
int V_59 ;
V_10 -> V_110 = 0 ;
V_59 = F_34 ( V_15 -> V_65 , & V_75 , V_107 , V_108 , V_97 ,
V_75 . V_82 ) ;
F_8 ( L_12 ,
V_15 , V_107 [ 0 ] . V_83 , V_107 [ 0 ] . V_61 , V_59 ) ;
return V_59 ;
}
static int F_35 ( struct V_9 * V_10 ,
struct V_106 * V_107 , int V_108 ,
int V_97 , unsigned int V_52 )
{
T_1 V_111 ;
void * V_112 ;
unsigned int V_113 ;
int V_114 ;
if ( V_52 == 0 )
return F_33 ( V_10 , V_107 , V_108 , V_97 ) ;
for ( V_113 = 0 ; V_113 < V_108 ; V_113 ++ ) {
if ( V_107 [ V_113 ] . V_61 > V_52 )
break;
V_52 -= V_107 [ V_113 ] . V_61 ;
}
V_111 = V_107 [ V_113 ] . V_61 ;
V_112 = V_107 [ V_113 ] . V_83 ;
V_107 [ V_113 ] . V_61 -= V_52 ;
V_107 [ V_113 ] . V_83 += V_52 ;
V_114 = F_33 ( V_10 , & V_107 [ V_113 ] , V_108 - V_113 , V_97 ) ;
V_107 [ V_113 ] . V_61 = V_111 ;
V_107 [ V_113 ] . V_83 = V_112 ;
return V_114 ;
}
static void F_36 ( struct V_1 * V_2 , unsigned int V_115 ,
unsigned int V_116 )
{
#if 0
mm_segment_t oldfs;
oldfs = get_fs(); set_fs(KERNEL_DS);
sock_setsockopt(sock, SOL_SOCKET, SO_SNDBUF,
(char*)&snd, sizeof(snd));
sock_setsockopt(sock, SOL_SOCKET, SO_RCVBUF,
(char*)&rcv, sizeof(rcv));
#else
F_37 ( V_2 -> V_3 ) ;
V_2 -> V_3 -> V_117 = V_115 * 2 ;
V_2 -> V_3 -> V_118 = V_116 * 2 ;
V_2 -> V_3 -> V_119 ( V_2 -> V_3 ) ;
F_38 ( V_2 -> V_3 ) ;
#endif
}
static void F_39 ( struct V_2 * V_3 , int V_120 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_121 ;
T_2 * V_122 = F_40 ( V_3 ) ;
if ( V_15 ) {
F_8 ( L_13 ,
V_15 , V_3 , V_120 ,
F_41 ( V_123 , & V_15 -> V_17 . V_124 ) ) ;
F_42 ( V_125 , & V_15 -> V_17 . V_124 ) ;
F_43 ( & V_15 -> V_17 ) ;
}
if ( V_122 && F_44 ( V_122 ) )
F_45 ( V_122 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) ( V_3 -> V_121 ) ;
T_2 * V_122 = F_40 ( V_3 ) ;
if ( V_15 ) {
F_8 ( L_14 ,
V_15 , V_3 , F_41 ( V_123 , & V_15 -> V_17 . V_124 ) ) ;
F_43 ( & V_15 -> V_17 ) ;
}
if ( V_122 && F_44 ( V_122 ) ) {
F_8 ( L_15 ,
V_15 ) ;
F_45 ( V_122 ) ;
}
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_126 ;
if ( F_48 ( V_3 ) >= F_49 ( V_3 ) && V_2 )
F_50 ( V_127 , & V_2 -> V_56 ) ;
F_46 ( V_3 ) ;
}
static int F_51 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = F_11 ( V_20 ) ;
struct V_128 * V_34 = F_12 ( V_10 ) ;
if ( V_20 -> V_25 != V_26 )
return 0 ;
V_34 -> V_129 = V_5 ;
V_34 -> V_30 . V_29 = V_22 -> V_28 . V_29 ;
return 1 ;
}
static int F_52 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
struct V_32 * V_22 = F_11 ( V_20 ) ;
struct V_33 * V_34 = F_14 ( V_10 ) ;
if ( V_20 -> V_25 != V_36 )
return 0 ;
V_34 -> V_130 = V_8 ;
V_34 -> V_40 = V_22 -> V_39 ;
V_34 -> V_38 = V_22 -> V_37 ;
return 1 ;
}
static int F_53 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
switch ( V_20 -> V_23 ) {
case V_24 :
return F_51 ( V_10 , V_20 ) ;
case V_35 :
return F_52 ( V_10 , V_20 ) ;
}
return 0 ;
}
static int F_54 ( struct V_9 * V_10 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_95 * V_96 = V_15 -> V_17 . V_131 ;
struct V_11 * V_12 ;
union {
struct V_19 V_66 ;
long V_67 [ V_68 / sizeof( long ) ] ;
} V_69 ;
struct V_19 * V_20 = & V_69 . V_66 ;
struct V_74 V_75 = {
. V_76 = F_55 ( V_10 ) ,
. V_80 = V_20 ,
. V_81 = sizeof( V_69 ) ,
. V_82 = V_109 ,
} ;
T_1 V_59 ;
int V_104 ;
if ( F_56 ( V_132 , & V_15 -> V_17 . V_124 ) )
F_36 ( V_15 -> V_65 ,
( V_96 -> V_133 + 3 ) * V_96 -> V_134 ,
( V_96 -> V_133 + 3 ) * V_96 -> V_134 ) ;
F_50 ( V_125 , & V_15 -> V_17 . V_124 ) ;
V_12 = NULL ;
V_104 = F_34 ( V_15 -> V_65 , & V_75 , NULL ,
0 , 0 , V_135 | V_109 ) ;
if ( V_104 >= 0 )
V_12 = F_57 ( V_15 -> V_18 , 0 , 1 , & V_104 ) ;
if ( V_12 == NULL ) {
if ( V_104 != - V_136 ) {
F_8 ( L_16 , - V_104 ) ;
F_42 ( V_125 , & V_15 -> V_17 . V_124 ) ;
}
return - V_136 ;
}
V_59 = F_58 ( F_55 ( V_10 ) ) ;
if ( V_59 == 0 )
return - V_137 ;
V_10 -> V_79 = V_59 ;
if ( V_12 -> V_138 . V_139 == 0 ) {
V_12 -> V_138 = F_59 () ;
}
V_15 -> V_18 -> V_140 = V_12 -> V_138 ;
F_42 ( V_125 , & V_15 -> V_17 . V_124 ) ;
V_59 = V_12 -> V_59 - sizeof( struct V_141 ) ;
V_10 -> V_142 . V_59 = V_59 ;
V_10 -> V_72 = V_73 ;
if ( ! F_53 ( V_10 , V_20 ) ) {
F_60 ( L_17 ,
V_20 -> V_23 , V_20 -> V_25 ) ;
F_9 ( V_15 -> V_18 , V_12 ) ;
return 0 ;
}
V_10 -> V_143 = F_58 ( F_61 ( V_10 ) ) ;
if ( F_62 ( V_12 ) ) {
F_63 () ;
if ( F_64 ( & V_10 -> V_142 , V_12 ) ) {
F_65 () ;
F_9 ( V_15 -> V_18 , V_12 ) ;
return 0 ;
}
F_65 () ;
F_9 ( V_15 -> V_18 , V_12 ) ;
} else {
V_10 -> V_142 . V_60 [ 0 ] . V_83 = V_12 -> V_144 +
sizeof( struct V_141 ) ;
V_10 -> V_142 . V_60 [ 0 ] . V_61 = V_59 ;
if ( F_66 ( V_12 ) ) {
F_9 ( V_15 -> V_18 , V_12 ) ;
return 0 ;
}
V_10 -> V_13 = V_12 ;
}
V_10 -> V_142 . V_53 = 0 ;
if ( V_59 <= V_10 -> V_142 . V_60 [ 0 ] . V_61 ) {
V_10 -> V_142 . V_60 [ 0 ] . V_61 = V_59 ;
V_10 -> V_142 . V_55 = 0 ;
V_10 -> V_84 = V_10 -> V_145 + 1 ;
} else {
V_10 -> V_142 . V_55 = V_59 - V_10 -> V_142 . V_60 [ 0 ] . V_61 ;
V_10 -> V_84 = V_10 -> V_145 + 1 +
F_67 ( V_10 -> V_142 . V_55 , V_63 ) ;
}
if ( V_96 -> V_146 )
V_96 -> V_146 -> V_147 ++ ;
return V_59 ;
}
static int
F_68 ( struct V_9 * V_10 )
{
int error ;
error = F_17 ( V_10 , & V_10 -> V_148 ) ;
if ( error == - V_149 )
error = F_17 ( V_10 , & V_10 -> V_148 ) ;
return error ;
}
static void F_69 ( struct V_9 * V_10 )
{
}
static int F_70 ( struct V_150 * V_151 )
{
struct V_14 * V_15 = F_7 ( V_151 , struct V_14 , V_17 ) ;
struct V_95 * V_96 = V_151 -> V_131 ;
unsigned long V_152 ;
F_42 ( V_127 , & V_15 -> V_65 -> V_56 ) ;
V_152 = F_71 ( & V_15 -> V_17 . V_153 ) + V_96 -> V_134 ;
if ( V_152 * 2 > F_72 ( V_15 -> V_18 ) )
return 0 ;
F_50 ( V_127 , & V_15 -> V_65 -> V_56 ) ;
return 1 ;
}
static struct V_150 * F_73 ( struct V_150 * V_151 )
{
F_5 () ;
return NULL ;
}
static struct V_150 * F_74 ( struct V_95 * V_96 ,
struct V_154 * V_154 ,
struct V_155 * V_156 , int V_157 ,
int V_56 )
{
return F_75 ( V_96 , V_73 , V_154 , V_156 , V_157 , V_56 ) ;
}
static void F_76 ( struct V_14 * V_15 , struct V_95 * V_96 )
{
int V_104 , V_158 , V_159 , V_160 = 1 ;
F_77 ( F_78 ( V_15 -> V_65 -> V_3 ) , & V_161 ,
& V_15 -> V_17 , V_96 ) ;
F_50 ( V_162 , & V_15 -> V_17 . V_124 ) ;
V_15 -> V_18 -> V_163 = F_39 ;
V_15 -> V_18 -> V_119 = F_46 ;
F_36 ( V_15 -> V_65 ,
3 * V_15 -> V_17 . V_131 -> V_134 ,
3 * V_15 -> V_17 . V_131 -> V_134 ) ;
F_42 ( V_125 , & V_15 -> V_17 . V_124 ) ;
F_42 ( V_132 , & V_15 -> V_17 . V_124 ) ;
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
V_104 = F_79 ( V_15 -> V_65 , V_158 , V_159 ,
( char * ) & V_160 , sizeof( V_160 ) ) ;
F_8 ( L_18 , V_104 ) ;
}
static void F_80 ( struct V_2 * V_3 , int V_165 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_121 ;
T_2 * V_122 ;
F_8 ( L_19 ,
V_3 , V_3 -> V_166 ) ;
if ( V_3 -> V_166 == V_167 ) {
if ( V_15 ) {
F_42 ( V_168 , & V_15 -> V_17 . V_124 ) ;
F_43 ( & V_15 -> V_17 ) ;
} else
F_81 ( L_20 , V_3 ) ;
}
V_122 = F_40 ( V_3 ) ;
if ( V_122 && F_44 ( V_122 ) )
F_82 ( V_122 ) ;
}
static void F_83 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_121 ;
T_2 * V_122 = F_40 ( V_3 ) ;
F_8 ( L_21 ,
V_3 , V_3 -> V_166 , V_3 -> V_121 ) ;
if ( ! V_15 )
F_81 ( L_20 , V_3 ) ;
else {
F_42 ( V_169 , & V_15 -> V_17 . V_124 ) ;
F_43 ( & V_15 -> V_17 ) ;
}
if ( V_122 && F_44 ( V_122 ) )
F_82 ( V_122 ) ;
}
static void F_84 ( struct V_2 * V_3 , int V_120 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_121 ;
T_2 * V_122 = F_40 ( V_3 ) ;
F_8 ( L_22 ,
V_3 , V_3 -> V_121 ) ;
if ( V_15 ) {
F_42 ( V_125 , & V_15 -> V_17 . V_124 ) ;
F_43 ( & V_15 -> V_17 ) ;
}
if ( V_122 && F_44 ( V_122 ) )
F_45 ( V_122 ) ;
}
static struct V_150 * F_85 ( struct V_150 * V_151 )
{
struct V_14 * V_15 = F_7 ( V_151 , struct V_14 , V_17 ) ;
struct V_170 V_171 ;
struct V_155 * sin = (struct V_155 * ) & V_171 ;
struct V_95 * V_96 = V_15 -> V_17 . V_131 ;
struct V_1 * V_2 = V_15 -> V_65 ;
struct V_1 * V_172 ;
struct V_14 * V_173 ;
int V_104 , V_58 ;
F_18 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_8 ( L_23 , V_15 , V_2 ) ;
if ( ! V_2 )
return NULL ;
F_50 ( V_168 , & V_15 -> V_17 . V_124 ) ;
V_104 = F_86 ( V_2 , & V_172 , V_174 ) ;
if ( V_104 < 0 ) {
if ( V_104 == - V_175 )
F_81 ( V_176 L_24 ,
V_96 -> V_177 ) ;
else if ( V_104 != - V_136 )
F_60 ( L_25 ,
V_96 -> V_177 , - V_104 ) ;
return NULL ;
}
F_42 ( V_168 , & V_15 -> V_17 . V_124 ) ;
V_104 = F_87 ( V_172 , sin , & V_58 ) ;
if ( V_104 < 0 ) {
F_60 ( L_26 ,
V_96 -> V_177 , - V_104 ) ;
goto V_178;
}
if ( ! F_88 ( sin ) ) {
F_8 ( V_176
L_27 ,
V_96 -> V_177 ,
F_89 ( sin , V_85 , sizeof( V_85 ) ) ) ;
}
F_8 ( L_28 , V_96 -> V_177 ,
F_89 ( sin , V_85 , sizeof( V_85 ) ) ) ;
V_172 -> V_3 -> V_179 = V_180 * 30 ;
if ( ! ( V_173 = F_90 ( V_96 , V_172 , & V_104 ,
( V_181 | V_182 ) ) ) )
goto V_178;
F_91 ( & V_173 -> V_17 , sin , V_58 ) ;
V_104 = F_92 ( V_172 , sin , & V_58 ) ;
if ( F_93 ( V_104 < 0 ) ) {
F_8 ( L_29 , - V_104 ) ;
V_58 = F_94 ( struct V_155 , V_183 ) ;
}
F_95 ( & V_173 -> V_17 , sin , V_58 ) ;
if ( V_96 -> V_146 )
V_96 -> V_146 -> V_184 ++ ;
return & V_173 -> V_17 ;
V_178:
F_96 ( V_172 ) ;
return NULL ;
}
static unsigned int F_97 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
unsigned int V_113 , V_59 , V_185 ;
if ( V_15 -> V_186 <= sizeof( V_187 ) )
return 0 ;
V_59 = V_15 -> V_186 - sizeof( V_187 ) ;
V_185 = ( V_59 + V_63 - 1 ) >> V_188 ;
for ( V_113 = 0 ; V_113 < V_185 ; V_113 ++ ) {
if ( V_10 -> V_145 [ V_113 ] != NULL )
F_98 ( V_10 -> V_145 [ V_113 ] ) ;
F_2 ( V_15 -> V_189 [ V_113 ] == NULL ) ;
V_10 -> V_145 [ V_113 ] = V_15 -> V_189 [ V_113 ] ;
V_15 -> V_189 [ V_113 ] = NULL ;
}
V_10 -> V_142 . V_60 [ 0 ] . V_83 = F_99 ( V_10 -> V_145 [ 0 ] ) ;
return V_59 ;
}
static void F_100 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
unsigned int V_113 , V_59 , V_185 ;
if ( V_15 -> V_186 <= sizeof( V_187 ) )
return;
V_59 = V_15 -> V_186 - sizeof( V_187 ) ;
V_185 = ( V_59 + V_63 - 1 ) >> V_188 ;
for ( V_113 = 0 ; V_113 < V_185 ; V_113 ++ ) {
V_15 -> V_189 [ V_113 ] = V_10 -> V_145 [ V_113 ] ;
V_10 -> V_145 [ V_113 ] = NULL ;
}
}
static void F_101 ( struct V_14 * V_15 )
{
unsigned int V_113 , V_59 , V_185 ;
if ( V_15 -> V_186 <= sizeof( V_187 ) )
goto V_62;
V_59 = V_15 -> V_186 - sizeof( V_187 ) ;
V_185 = ( V_59 + V_63 - 1 ) >> V_188 ;
for ( V_113 = 0 ; V_113 < V_185 ; V_113 ++ ) {
F_2 ( V_15 -> V_189 [ V_113 ] == NULL ) ;
F_98 ( V_15 -> V_189 [ V_113 ] ) ;
V_15 -> V_189 [ V_113 ] = NULL ;
}
V_62:
V_15 -> V_186 = 0 ;
}
static int F_102 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
struct V_95 * V_96 = V_15 -> V_17 . V_131 ;
unsigned int V_190 ;
int V_59 ;
F_50 ( V_125 , & V_15 -> V_17 . V_124 ) ;
if ( V_15 -> V_186 < sizeof( V_187 ) ) {
struct V_106 V_107 ;
V_190 = sizeof( V_187 ) - V_15 -> V_186 ;
V_107 . V_83 = ( ( char * ) & V_15 -> V_191 ) + V_15 -> V_186 ;
V_107 . V_61 = V_190 ;
if ( ( V_59 = F_33 ( V_10 , & V_107 , 1 , V_190 ) ) < 0 )
goto error;
V_15 -> V_186 += V_59 ;
if ( V_59 < V_190 ) {
F_8 ( L_30
L_31 , V_59 , V_190 ) ;
return - V_136 ;
}
V_15 -> V_191 = F_103 ( V_15 -> V_191 ) ;
if ( ! ( V_15 -> V_191 & V_192 ) ) {
F_104 ( L_32 ) ;
goto V_193;
}
V_15 -> V_191 &= V_194 ;
F_8 ( L_33 , V_15 -> V_191 ) ;
if ( V_15 -> V_191 > V_96 -> V_134 ) {
F_104 ( L_34 ,
( unsigned long ) V_15 -> V_191 ) ;
goto V_193;
}
}
if ( V_15 -> V_191 < 8 )
goto V_193;
V_59 = V_15 -> V_191 ;
return V_59 ;
error:
F_8 ( L_35 , V_59 ) ;
return V_59 ;
V_193:
F_42 ( V_169 , & V_15 -> V_17 . V_124 ) ;
return - V_136 ;
}
static int F_105 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
struct V_195 * V_196 = V_15 -> V_17 . V_197 ;
struct V_198 * V_199 = NULL ;
struct V_106 * V_200 , * V_201 ;
T_3 * V_202 = ( T_3 * ) V_10 -> V_142 . V_60 [ 0 ] . V_83 ;
T_3 V_203 ;
T_3 V_204 ;
V_203 = * V_202 ++ ;
V_204 = * V_202 ;
if ( V_196 )
V_199 = F_106 ( V_196 , V_203 ) ;
if ( ! V_199 ) {
F_81 ( V_205
L_36
L_37 ,
V_206 , F_103 ( V_204 ) ,
V_196 , V_203 ) ;
return - V_136 ;
}
memcpy ( & V_199 -> V_207 , & V_199 -> V_208 , sizeof( struct V_41 ) ) ;
V_201 = & V_199 -> V_207 . V_60 [ 0 ] ;
V_200 = & V_10 -> V_142 . V_60 [ 0 ] ;
if ( V_201 -> V_61 < V_200 -> V_61 )
return - V_136 ;
memcpy ( V_201 -> V_83 , V_200 -> V_83 , V_200 -> V_61 ) ;
F_107 ( V_199 -> V_209 , V_15 -> V_191 ) ;
V_10 -> V_142 . V_59 = 0 ;
return 0 ;
}
static int F_108 ( struct V_106 * V_210 , struct V_43 * * V_51 , int V_59 )
{
int V_113 = 0 ;
int V_211 = 0 ;
while ( V_211 < V_59 ) {
V_210 [ V_113 ] . V_83 = F_99 ( V_51 [ V_113 ] ) ;
V_210 [ V_113 ] . V_61 = V_63 ;
V_113 ++ ;
V_211 += V_63 ;
}
return V_113 ;
}
static int F_109 ( struct V_9 * V_10 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_95 * V_96 = V_15 -> V_17 . V_131 ;
int V_59 ;
struct V_106 * V_210 ;
unsigned int V_190 , V_52 ;
T_3 * V_202 ;
T_3 V_204 ;
int V_212 ;
F_8 ( L_38 ,
V_15 , F_41 ( V_125 , & V_15 -> V_17 . V_124 ) ,
F_41 ( V_168 , & V_15 -> V_17 . V_124 ) ,
F_41 ( V_169 , & V_15 -> V_17 . V_124 ) ) ;
V_59 = F_102 ( V_15 , V_10 ) ;
if ( V_59 < 0 )
goto error;
V_52 = F_97 ( V_15 , V_10 ) ;
V_190 = V_15 -> V_191 - V_52 ;
V_210 = V_10 -> V_213 ;
V_212 = F_108 ( & V_210 [ 0 ] , & V_10 -> V_145 [ 0 ] ,
V_15 -> V_191 ) ;
V_10 -> V_84 = & V_10 -> V_145 [ V_212 ] ;
V_59 = F_35 ( V_10 , V_210 , V_212 , V_190 , V_52 ) ;
if ( V_59 >= 0 )
V_15 -> V_186 += V_59 ;
if ( V_59 != V_190 ) {
if ( V_59 < 0 && V_59 != - V_136 )
goto V_214;
F_100 ( V_15 , V_10 ) ;
F_8 ( L_39 ,
V_15 -> V_186 , V_15 -> V_191 ) ;
goto V_215;
}
V_10 -> V_142 . V_59 = V_15 -> V_191 ;
V_10 -> V_142 . V_53 = 0 ;
if ( V_10 -> V_142 . V_59 <= V_10 -> V_142 . V_60 [ 0 ] . V_61 ) {
V_10 -> V_142 . V_60 [ 0 ] . V_61 = V_10 -> V_142 . V_59 ;
V_10 -> V_142 . V_55 = 0 ;
} else
V_10 -> V_142 . V_55 = V_10 -> V_142 . V_59 - V_10 -> V_142 . V_60 [ 0 ] . V_61 ;
V_10 -> V_13 = NULL ;
V_10 -> V_72 = V_216 ;
V_202 = ( T_3 * ) V_10 -> V_142 . V_60 [ 0 ] . V_83 ;
V_204 = V_202 [ 1 ] ;
if ( V_204 )
V_59 = F_105 ( V_15 , V_10 ) ;
V_15 -> V_191 = 0 ;
V_15 -> V_186 = 0 ;
if ( F_31 ( V_15 ) > sizeof( V_187 ) )
F_42 ( V_125 , & V_15 -> V_17 . V_124 ) ;
if ( V_59 < 0 )
goto error;
F_110 ( V_10 , & V_15 -> V_17 ) ;
if ( V_96 -> V_146 )
V_96 -> V_146 -> V_217 ++ ;
F_8 ( L_40 , V_10 -> V_142 . V_59 ) ;
return V_10 -> V_142 . V_59 ;
error:
if ( V_59 != - V_136 )
goto V_214;
F_8 ( L_41 ) ;
return - V_136 ;
V_214:
F_81 ( V_205 L_42 ,
V_15 -> V_17 . V_131 -> V_177 , - V_59 ) ;
F_42 ( V_169 , & V_15 -> V_17 . V_124 ) ;
V_215:
return - V_136 ;
}
static int F_111 ( struct V_9 * V_10 )
{
struct V_41 * V_218 = & V_10 -> V_148 ;
int V_219 ;
T_3 V_220 ;
V_220 = F_112 ( 0x80000000 | ( ( V_218 -> V_59 ) - 4 ) ) ;
memcpy ( V_218 -> V_60 [ 0 ] . V_83 , & V_220 , 4 ) ;
V_219 = F_17 ( V_10 , & V_10 -> V_148 ) ;
if ( V_219 != V_218 -> V_59 ) {
F_81 ( V_205
L_43
L_44 ,
V_10 -> V_16 -> V_131 -> V_177 ,
( V_219 < 0 ) ? L_45 : L_46 ,
V_219 , V_218 -> V_59 ) ;
F_42 ( V_169 , & V_10 -> V_16 -> V_124 ) ;
F_43 ( V_10 -> V_16 ) ;
V_219 = - V_136 ;
}
return V_219 ;
}
static void F_113 ( struct V_9 * V_10 )
{
struct V_106 * V_221 = & V_10 -> V_148 . V_60 [ 0 ] ;
F_114 ( V_221 , 0 ) ;
}
static int F_115 ( struct V_150 * V_151 )
{
struct V_14 * V_15 = F_7 ( V_151 , struct V_14 , V_17 ) ;
struct V_95 * V_96 = V_15 -> V_17 . V_131 ;
int V_152 ;
if ( F_41 ( V_222 , & V_151 -> V_124 ) )
return 1 ;
V_152 = F_71 ( & V_151 -> V_153 ) + V_96 -> V_134 ;
if ( F_48 ( V_15 -> V_18 ) >= V_152 )
return 1 ;
F_42 ( V_127 , & V_15 -> V_65 -> V_56 ) ;
return 0 ;
}
static struct V_150 * F_116 ( struct V_95 * V_96 ,
struct V_154 * V_154 ,
struct V_155 * V_156 , int V_157 ,
int V_56 )
{
return F_75 ( V_96 , V_216 , V_154 , V_156 , V_157 , V_56 ) ;
}
static struct V_150 * F_117 ( struct V_95 * V_96 ,
struct V_154 * V_154 ,
struct V_155 * V_156 , int V_157 ,
int V_56 )
{
return F_118 ( V_96 , V_216 , V_154 , V_156 , V_157 , V_56 ) ;
}
static void F_119 ( struct V_150 * V_151 )
{
}
static void F_120 ( void )
{
F_121 ( & V_223 ) ;
}
static void F_122 ( void )
{
F_123 ( & V_223 ) ;
}
static void F_120 ( void )
{
}
static void F_122 ( void )
{
}
void F_124 ( void )
{
F_121 ( & V_224 ) ;
F_121 ( & V_161 ) ;
F_120 () ;
}
void F_125 ( void )
{
F_123 ( & V_224 ) ;
F_123 ( & V_161 ) ;
F_122 () ;
}
static void F_126 ( struct V_14 * V_15 , struct V_95 * V_96 )
{
struct V_2 * V_3 = V_15 -> V_18 ;
F_77 ( F_78 ( V_15 -> V_65 -> V_3 ) , & V_224 ,
& V_15 -> V_17 , V_96 ) ;
F_42 ( V_162 , & V_15 -> V_17 . V_124 ) ;
if ( V_3 -> V_166 == V_167 ) {
F_8 ( L_47 ) ;
F_42 ( V_222 , & V_15 -> V_17 . V_124 ) ;
V_3 -> V_163 = F_80 ;
F_42 ( V_168 , & V_15 -> V_17 . V_124 ) ;
} else {
F_8 ( L_48 ) ;
V_3 -> V_225 = F_83 ;
V_3 -> V_163 = F_84 ;
V_3 -> V_119 = F_47 ;
V_15 -> V_191 = 0 ;
V_15 -> V_186 = 0 ;
memset ( & V_15 -> V_189 [ 0 ] , 0 , sizeof( V_15 -> V_189 ) ) ;
F_127 ( V_3 ) -> V_226 |= V_227 ;
F_42 ( V_125 , & V_15 -> V_17 . V_124 ) ;
if ( V_3 -> V_166 != V_228 )
F_42 ( V_169 , & V_15 -> V_17 . V_124 ) ;
}
}
void F_128 ( struct V_95 * V_96 )
{
struct V_14 * V_15 ;
F_25 ( & V_96 -> V_100 ) ;
F_26 (svsk, &serv->sv_permsocks, sk_xprt.xpt_list)
F_42 ( V_132 , & V_15 -> V_17 . V_124 ) ;
F_28 ( & V_96 -> V_100 ) ;
}
static struct V_14 * F_90 ( struct V_95 * V_96 ,
struct V_1 * V_2 ,
int * V_229 , int V_56 )
{
struct V_14 * V_15 ;
struct V_2 * V_230 ;
int V_231 = ! ( V_56 & V_181 ) ;
F_8 ( L_49 , V_2 ) ;
if ( ! ( V_15 = F_129 ( sizeof( * V_15 ) , V_232 ) ) ) {
* V_229 = - V_175 ;
return NULL ;
}
V_230 = V_2 -> V_3 ;
if ( * V_229 >= 0 && V_231 )
* V_229 = F_130 ( V_96 , F_78 ( V_2 -> V_3 ) , V_230 -> V_4 ,
V_230 -> V_88 ,
F_131 ( F_22 ( V_230 ) -> V_233 ) ) ;
if ( * V_229 < 0 ) {
F_132 ( V_15 ) ;
return NULL ;
}
V_230 -> V_121 = V_15 ;
V_15 -> V_65 = V_2 ;
V_15 -> V_18 = V_230 ;
V_15 -> V_234 = V_230 -> V_225 ;
V_15 -> V_235 = V_230 -> V_163 ;
V_15 -> V_236 = V_230 -> V_119 ;
if ( V_2 -> type == V_237 )
F_76 ( V_15 , V_96 ) ;
else {
F_36 ( V_15 -> V_65 , 4 * V_96 -> V_134 ,
4 * V_96 -> V_134 ) ;
F_126 ( V_15 , V_96 ) ;
}
F_8 ( L_50 ,
V_15 , V_15 -> V_18 ) ;
return V_15 ;
}
int F_133 ( struct V_95 * V_96 , const int V_238 , char * V_239 ,
const T_1 V_59 )
{
int V_104 = 0 ;
struct V_1 * V_240 = F_134 ( V_238 , & V_104 ) ;
struct V_14 * V_15 = NULL ;
if ( ! V_240 )
return V_104 ;
if ( ( V_240 -> V_3 -> V_4 != V_89 ) && ( V_240 -> V_3 -> V_4 != V_92 ) )
V_104 = - V_137 ;
else if ( V_240 -> V_3 -> V_88 != V_216 &&
V_240 -> V_3 -> V_88 != V_73 )
V_104 = - V_241 ;
else if ( V_240 -> V_242 > V_243 )
V_104 = - V_244 ;
else {
if ( ! F_135 ( V_245 ) )
V_104 = - V_102 ;
else
V_15 = F_90 ( V_96 , V_240 , & V_104 ,
V_246 ) ;
if ( V_15 ) {
struct V_170 V_171 ;
struct V_155 * sin = (struct V_155 * ) & V_171 ;
int V_157 ;
if ( F_92 ( V_15 -> V_65 , sin , & V_157 ) == 0 )
F_95 ( & V_15 -> V_17 , sin , V_157 ) ;
F_50 ( V_247 , & V_15 -> V_17 . V_124 ) ;
F_25 ( & V_96 -> V_100 ) ;
F_136 ( & V_15 -> V_17 . V_248 , & V_96 -> V_249 ) ;
F_28 ( & V_96 -> V_100 ) ;
F_137 ( & V_15 -> V_17 ) ;
V_104 = 0 ;
} else
F_138 ( V_245 ) ;
}
if ( V_104 ) {
F_139 ( V_240 ) ;
return V_104 ;
}
return F_21 ( V_15 , V_239 , V_59 ) ;
}
static struct V_150 * F_75 ( struct V_95 * V_96 ,
int V_250 ,
struct V_154 * V_154 ,
struct V_155 * sin , int V_59 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int error ;
int type ;
struct V_170 V_171 ;
struct V_155 * V_251 = (struct V_155 * ) & V_171 ;
int V_252 ;
int V_253 ;
int V_254 ;
F_18 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_8 ( L_51 ,
V_96 -> V_255 -> V_256 , V_250 ,
F_89 ( sin , V_85 , sizeof( V_85 ) ) ) ;
if ( V_250 != V_73 && V_250 != V_216 ) {
F_81 ( V_176 L_52
L_53 ) ;
return F_140 ( - V_257 ) ;
}
type = ( V_250 == V_73 ) ? V_237 : V_258 ;
switch ( sin -> V_259 ) {
case V_8 :
V_253 = V_92 ;
break;
case V_5 :
V_253 = V_89 ;
break;
default:
return F_140 ( - V_257 ) ;
}
error = F_141 ( V_154 , V_253 , type , V_250 , & V_2 , 1 ) ;
if ( error < 0 )
return F_140 ( error ) ;
F_1 ( V_2 ) ;
V_254 = 1 ;
if ( V_253 == V_92 )
F_79 ( V_2 , V_35 , V_260 ,
( char * ) & V_254 , sizeof( V_254 ) ) ;
if ( type == V_258 )
V_2 -> V_3 -> V_261 = V_262 ;
error = F_142 ( V_2 , sin , V_59 ) ;
if ( error < 0 )
goto V_263;
V_252 = V_59 ;
error = F_92 ( V_2 , V_251 , & V_252 ) ;
if ( error < 0 )
goto V_263;
if ( V_250 == V_216 ) {
if ( ( error = F_143 ( V_2 , 64 ) ) < 0 )
goto V_263;
}
if ( ( V_15 = F_90 ( V_96 , V_2 , & error , V_56 ) ) != NULL ) {
F_95 ( & V_15 -> V_17 , V_251 , V_252 ) ;
return (struct V_150 * ) V_15 ;
}
V_263:
F_8 ( L_54 , - error ) ;
F_96 ( V_2 ) ;
return F_140 ( error ) ;
}
static void F_144 ( struct V_150 * V_151 )
{
struct V_14 * V_15 = F_7 ( V_151 , struct V_14 , V_17 ) ;
struct V_2 * V_3 = V_15 -> V_18 ;
T_2 * V_122 ;
F_8 ( L_55 , V_15 ) ;
V_3 -> V_225 = V_15 -> V_234 ;
V_3 -> V_163 = V_15 -> V_235 ;
V_3 -> V_119 = V_15 -> V_236 ;
V_122 = F_40 ( V_3 ) ;
if ( V_122 && F_44 ( V_122 ) )
F_45 ( V_122 ) ;
}
static void F_145 ( struct V_150 * V_151 )
{
struct V_14 * V_15 = F_7 ( V_151 , struct V_14 , V_17 ) ;
F_8 ( L_56 , V_15 ) ;
F_144 ( V_151 ) ;
if ( ! F_41 ( V_222 , & V_151 -> V_124 ) ) {
F_101 ( V_15 ) ;
F_146 ( V_15 -> V_65 , V_264 ) ;
}
}
static void F_147 ( struct V_150 * V_151 )
{
struct V_14 * V_15 = F_7 ( V_151 , struct V_14 , V_17 ) ;
F_8 ( L_57 , V_15 ) ;
if ( V_15 -> V_65 -> V_265 )
F_139 ( V_15 -> V_65 ) ;
else
F_96 ( V_15 -> V_65 ) ;
F_132 ( V_15 ) ;
}
static struct V_150 * F_118 ( struct V_95 * V_96 ,
int V_250 ,
struct V_154 * V_154 ,
struct V_155 * sin , int V_59 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_150 * V_151 ;
if ( V_250 != V_216 ) {
F_81 ( V_176 L_58
L_59 ) ;
return F_140 ( - V_257 ) ;
}
V_15 = F_129 ( sizeof( * V_15 ) , V_232 ) ;
if ( ! V_15 )
return F_140 ( - V_175 ) ;
V_151 = & V_15 -> V_17 ;
F_77 ( V_154 , & V_223 , V_151 , V_96 ) ;
V_96 -> V_266 = V_151 ;
return V_151 ;
}
static void F_148 ( struct V_150 * V_151 )
{
if ( V_151 )
F_132 ( F_7 ( V_151 , struct V_14 , V_17 ) ) ;
}
