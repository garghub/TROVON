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
V_22 -> V_28 . V_29 = V_10 -> V_30 . V_31 . V_29 ;
V_20 -> V_32 = F_12 ( sizeof( * V_22 ) ) ;
}
break;
case V_8 : {
struct V_33 * V_22 = F_11 ( V_20 ) ;
V_20 -> V_23 = V_34 ;
V_20 -> V_25 = V_35 ;
V_22 -> V_36 = 0 ;
F_13 ( & V_22 -> V_37 ,
& V_10 -> V_30 . V_38 ) ;
V_20 -> V_32 = F_12 ( sizeof( * V_22 ) ) ;
}
break;
}
}
int F_14 ( struct V_1 * V_2 , struct V_39 * V_40 ,
struct V_41 * V_42 , unsigned long V_43 ,
struct V_41 * V_44 , unsigned long V_45 )
{
int V_46 ;
int V_47 ;
struct V_41 * * V_48 = V_40 -> V_49 ;
T_1 V_50 = V_40 -> V_51 ;
unsigned int V_52 = V_40 -> V_53 ;
unsigned int V_54 = V_55 ;
int V_56 ;
int V_57 = 0 ;
V_56 = V_40 -> V_57 ;
if ( V_56 == V_40 -> V_58 [ 0 ] . V_59 )
V_54 = 0 ;
V_57 = F_15 ( V_2 , V_42 , V_43 ,
V_40 -> V_58 [ 0 ] . V_59 , V_54 ) ;
if ( V_57 != V_40 -> V_58 [ 0 ] . V_59 )
goto V_60;
V_56 -= V_40 -> V_58 [ 0 ] . V_59 ;
if ( V_56 == 0 )
goto V_60;
V_47 = V_61 - V_50 < V_52 ? V_61 - V_50 : V_52 ;
while ( V_52 > 0 ) {
if ( V_56 == V_47 )
V_54 = 0 ;
V_46 = F_15 ( V_2 , * V_48 , V_50 , V_47 , V_54 ) ;
if ( V_46 > 0 )
V_57 += V_46 ;
if ( V_46 != V_47 )
goto V_60;
V_56 -= V_47 ;
V_52 -= V_47 ;
V_47 = V_61 < V_52 ? V_61 : V_52 ;
V_50 = 0 ;
V_48 ++ ;
}
if ( V_40 -> V_62 [ 0 ] . V_59 ) {
V_46 = F_15 ( V_2 , V_44 , V_45 ,
V_40 -> V_62 [ 0 ] . V_59 , 0 ) ;
if ( V_46 > 0 )
V_57 += V_46 ;
}
V_60:
return V_57 ;
}
static int F_16 ( struct V_9 * V_10 , struct V_39 * V_40 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_1 * V_2 = V_15 -> V_63 ;
union {
struct V_19 V_64 ;
long V_65 [ V_66 / sizeof( long ) ] ;
} V_67 ;
struct V_19 * V_20 = & V_67 . V_64 ;
int V_57 = 0 ;
unsigned long V_68 ;
unsigned long V_69 ;
F_17 (char buf[RPC_MAX_ADDRBUFLEN]) ;
if ( V_10 -> V_70 == V_71 ) {
struct V_72 V_73 = {
. V_74 = & V_10 -> V_75 ,
. V_76 = V_10 -> V_77 ,
. V_78 = V_20 ,
. V_79 = sizeof( V_67 ) ,
. V_80 = V_55 ,
} ;
F_10 ( V_10 , V_20 ) ;
if ( F_18 ( V_2 , & V_73 , 0 ) < 0 )
goto V_60;
}
V_68 = ( ( unsigned long ) V_40 -> V_62 [ 0 ] . V_81 ) & ( V_61 - 1 ) ;
V_69 = 0 ;
V_57 = F_14 ( V_2 , V_40 , V_10 -> V_82 [ 0 ] , V_69 ,
V_10 -> V_82 [ 0 ] , V_68 ) ;
V_60:
F_8 ( L_6 ,
V_15 , V_40 -> V_58 [ 0 ] . V_81 , V_40 -> V_58 [ 0 ] . V_59 ,
V_40 -> V_57 , V_57 , F_19 ( V_10 , V_83 , sizeof( V_83 ) ) ) ;
return V_57 ;
}
static int F_20 ( struct V_14 * V_15 , char * V_83 , int V_84 )
{
const struct V_2 * V_3 = V_15 -> V_18 ;
const char * V_85 = V_3 -> V_86 == V_71 ?
L_7 : L_8 ;
int V_57 ;
switch ( V_3 -> V_4 ) {
case V_87 :
V_57 = snprintf ( V_83 , V_84 , L_9 ,
V_85 ,
& F_21 ( V_3 ) -> V_88 ,
F_21 ( V_3 ) -> V_89 ) ;
break;
case V_90 :
V_57 = snprintf ( V_83 , V_84 , L_10 ,
V_85 ,
& F_22 ( V_3 ) -> V_91 ,
F_21 ( V_3 ) -> V_89 ) ;
break;
default:
V_57 = snprintf ( V_83 , V_84 , L_11 ,
V_3 -> V_4 ) ;
}
if ( V_57 >= V_84 ) {
* V_83 = '\0' ;
return - V_92 ;
}
return V_57 ;
}
int F_23 ( struct V_93 * V_94 , char * V_83 , const T_1 V_95 ,
const char * V_96 )
{
struct V_14 * V_15 , * V_97 = NULL ;
int V_57 = 0 ;
if ( ! V_94 )
return 0 ;
F_24 ( & V_94 -> V_98 ) ;
F_25 (svsk, &serv->sv_permsocks, sk_xprt.xpt_list) {
int V_99 = F_20 ( V_15 , V_83 + V_57 , V_95 - V_57 ) ;
if ( V_99 < 0 ) {
V_57 = V_99 ;
break;
}
if ( V_96 && strcmp ( V_96 , V_83 + V_57 ) == 0 ) {
V_97 = V_15 ;
F_26 ( & V_97 -> V_17 ) ;
} else
V_57 += V_99 ;
}
F_27 ( & V_94 -> V_98 ) ;
if ( V_97 ) {
F_28 ( & V_97 -> V_17 ) ;
F_29 ( & V_97 -> V_17 ) ;
} else if ( V_96 )
return - V_100 ;
return V_57 ;
}
static int F_30 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_63 ;
int V_101 , V_102 ;
V_102 = F_31 ( V_2 , V_103 , ( unsigned long ) & V_101 ) ;
return ( V_102 >= 0 ) ? V_101 : V_102 ;
}
static int F_32 ( struct V_9 * V_10 , struct V_104 * V_105 , int V_106 ,
int V_95 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_72 V_73 = {
. V_80 = V_107 ,
} ;
int V_57 ;
V_10 -> V_108 = 0 ;
V_57 = F_33 ( V_15 -> V_63 , & V_73 , V_105 , V_106 , V_95 ,
V_73 . V_80 ) ;
F_8 ( L_12 ,
V_15 , V_105 [ 0 ] . V_81 , V_105 [ 0 ] . V_59 , V_57 ) ;
return V_57 ;
}
static int F_34 ( struct V_9 * V_10 ,
struct V_104 * V_105 , int V_106 ,
int V_95 , unsigned int V_50 )
{
T_1 V_109 ;
void T_2 * V_110 ;
unsigned int V_111 ;
int V_112 ;
if ( V_50 == 0 )
return F_32 ( V_10 , V_105 , V_106 , V_95 ) ;
for ( V_111 = 0 ; V_111 < V_106 ; V_111 ++ ) {
if ( V_105 [ V_111 ] . V_59 > V_50 )
break;
V_50 -= V_105 [ V_111 ] . V_59 ;
}
V_109 = V_105 [ V_111 ] . V_59 ;
V_110 = V_105 [ V_111 ] . V_81 ;
V_105 [ V_111 ] . V_59 -= V_50 ;
V_105 [ V_111 ] . V_81 += V_50 ;
V_112 = F_32 ( V_10 , & V_105 [ V_111 ] , V_106 - V_111 , V_95 ) ;
V_105 [ V_111 ] . V_59 = V_109 ;
V_105 [ V_111 ] . V_81 = V_110 ;
return V_112 ;
}
static void F_35 ( struct V_1 * V_2 , unsigned int V_113 ,
unsigned int V_114 )
{
#if 0
mm_segment_t oldfs;
oldfs = get_fs(); set_fs(KERNEL_DS);
sock_setsockopt(sock, SOL_SOCKET, SO_SNDBUF,
(char*)&snd, sizeof(snd));
sock_setsockopt(sock, SOL_SOCKET, SO_RCVBUF,
(char*)&rcv, sizeof(rcv));
#else
F_36 ( V_2 -> V_3 ) ;
V_2 -> V_3 -> V_115 = V_113 * 2 ;
V_2 -> V_3 -> V_116 = V_114 * 2 ;
V_2 -> V_3 -> V_117 ( V_2 -> V_3 ) ;
F_37 ( V_2 -> V_3 ) ;
#endif
}
static void F_38 ( struct V_2 * V_3 , int V_118 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_119 ;
T_3 * V_120 = F_39 ( V_3 ) ;
if ( V_15 ) {
F_8 ( L_13 ,
V_15 , V_3 , V_118 ,
F_40 ( V_121 , & V_15 -> V_17 . V_122 ) ) ;
F_41 ( V_123 , & V_15 -> V_17 . V_122 ) ;
F_42 ( & V_15 -> V_17 ) ;
}
if ( V_120 && F_43 ( V_120 ) )
F_44 ( V_120 ) ;
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) ( V_3 -> V_119 ) ;
T_3 * V_120 = F_39 ( V_3 ) ;
if ( V_15 ) {
F_8 ( L_14 ,
V_15 , V_3 , F_40 ( V_121 , & V_15 -> V_17 . V_122 ) ) ;
F_42 ( & V_15 -> V_17 ) ;
}
if ( V_120 && F_43 ( V_120 ) ) {
F_8 ( L_15 ,
V_15 ) ;
F_44 ( V_120 ) ;
}
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_124 ;
if ( F_47 ( V_3 ) >= F_48 ( V_3 ) && V_2 )
F_49 ( V_125 , & V_2 -> V_54 ) ;
F_45 ( V_3 ) ;
}
static int F_50 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = F_11 ( V_20 ) ;
if ( V_20 -> V_25 != V_26 )
return 0 ;
V_10 -> V_30 . V_31 . V_29 = V_22 -> V_28 . V_29 ;
return 1 ;
}
static int F_51 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
struct V_33 * V_22 = F_11 ( V_20 ) ;
if ( V_20 -> V_25 != V_35 )
return 0 ;
F_13 ( & V_10 -> V_30 . V_38 , & V_22 -> V_37 ) ;
return 1 ;
}
static int F_52 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
switch ( V_20 -> V_23 ) {
case V_24 :
return F_50 ( V_10 , V_20 ) ;
case V_34 :
return F_51 ( V_10 , V_20 ) ;
}
return 0 ;
}
static int F_53 ( struct V_9 * V_10 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_93 * V_94 = V_15 -> V_17 . V_126 ;
struct V_11 * V_12 ;
union {
struct V_19 V_64 ;
long V_65 [ V_66 / sizeof( long ) ] ;
} V_67 ;
struct V_19 * V_20 = & V_67 . V_64 ;
struct V_72 V_73 = {
. V_74 = F_54 ( V_10 ) ,
. V_78 = V_20 ,
. V_79 = sizeof( V_67 ) ,
. V_80 = V_107 ,
} ;
T_1 V_57 ;
int V_102 ;
if ( F_55 ( V_127 , & V_15 -> V_17 . V_122 ) )
F_35 ( V_15 -> V_63 ,
( V_94 -> V_128 + 3 ) * V_94 -> V_129 ,
( V_94 -> V_128 + 3 ) * V_94 -> V_129 ) ;
F_49 ( V_123 , & V_15 -> V_17 . V_122 ) ;
V_12 = NULL ;
V_102 = F_33 ( V_15 -> V_63 , & V_73 , NULL ,
0 , 0 , V_130 | V_107 ) ;
if ( V_102 >= 0 )
V_12 = F_56 ( V_15 -> V_18 , 0 , 1 , & V_102 ) ;
if ( V_12 == NULL ) {
if ( V_102 != - V_131 ) {
F_8 ( L_16 , - V_102 ) ;
F_41 ( V_123 , & V_15 -> V_17 . V_122 ) ;
}
return - V_131 ;
}
V_57 = F_57 ( F_54 ( V_10 ) ) ;
if ( V_57 == 0 )
return - V_132 ;
V_10 -> V_77 = V_57 ;
if ( V_12 -> V_133 . V_134 == 0 ) {
V_12 -> V_133 = F_58 () ;
}
V_15 -> V_18 -> V_135 = V_12 -> V_133 ;
F_41 ( V_123 , & V_15 -> V_17 . V_122 ) ;
V_57 = V_12 -> V_57 - sizeof( struct V_136 ) ;
V_10 -> V_137 . V_57 = V_57 ;
V_10 -> V_70 = V_71 ;
if ( ! F_52 ( V_10 , V_20 ) ) {
if ( F_59 () )
F_60 ( V_138
L_17
L_18 ,
V_20 -> V_23 , V_20 -> V_25 ) ;
F_9 ( V_15 -> V_18 , V_12 ) ;
return 0 ;
}
if ( F_61 ( V_12 ) ) {
F_62 () ;
if ( F_63 ( & V_10 -> V_137 , V_12 ) ) {
F_64 () ;
F_9 ( V_15 -> V_18 , V_12 ) ;
return 0 ;
}
F_64 () ;
F_9 ( V_15 -> V_18 , V_12 ) ;
} else {
V_10 -> V_137 . V_58 [ 0 ] . V_81 = V_12 -> V_139 +
sizeof( struct V_136 ) ;
V_10 -> V_137 . V_58 [ 0 ] . V_59 = V_57 ;
if ( F_65 ( V_12 ) ) {
F_9 ( V_15 -> V_18 , V_12 ) ;
return 0 ;
}
V_10 -> V_13 = V_12 ;
}
V_10 -> V_137 . V_51 = 0 ;
if ( V_57 <= V_10 -> V_137 . V_58 [ 0 ] . V_59 ) {
V_10 -> V_137 . V_58 [ 0 ] . V_59 = V_57 ;
V_10 -> V_137 . V_53 = 0 ;
V_10 -> V_82 = V_10 -> V_140 + 1 ;
} else {
V_10 -> V_137 . V_53 = V_57 - V_10 -> V_137 . V_58 [ 0 ] . V_59 ;
V_10 -> V_82 = V_10 -> V_140 + 1 +
F_66 ( V_10 -> V_137 . V_53 , V_61 ) ;
}
if ( V_94 -> V_141 )
V_94 -> V_141 -> V_142 ++ ;
return V_57 ;
}
static int
F_67 ( struct V_9 * V_10 )
{
int error ;
error = F_16 ( V_10 , & V_10 -> V_143 ) ;
if ( error == - V_144 )
error = F_16 ( V_10 , & V_10 -> V_143 ) ;
return error ;
}
static void F_68 ( struct V_9 * V_10 )
{
}
static int F_69 ( struct V_145 * V_146 )
{
struct V_14 * V_15 = F_7 ( V_146 , struct V_14 , V_17 ) ;
struct V_93 * V_94 = V_146 -> V_126 ;
unsigned long V_147 ;
F_41 ( V_125 , & V_15 -> V_63 -> V_54 ) ;
V_147 = F_70 ( & V_15 -> V_17 . V_148 ) + V_94 -> V_129 ;
if ( V_147 * 2 > F_71 ( V_15 -> V_18 ) )
return 0 ;
F_49 ( V_125 , & V_15 -> V_63 -> V_54 ) ;
return 1 ;
}
static struct V_145 * F_72 ( struct V_145 * V_146 )
{
F_5 () ;
return NULL ;
}
static struct V_145 * F_73 ( struct V_93 * V_94 ,
struct V_149 * V_149 ,
struct V_150 * V_151 , int V_152 ,
int V_54 )
{
return F_74 ( V_94 , V_71 , V_149 , V_151 , V_152 , V_54 ) ;
}
static void F_75 ( struct V_14 * V_15 , struct V_93 * V_94 )
{
int V_102 , V_153 , V_154 , V_155 = 1 ;
F_76 ( & V_156 , & V_15 -> V_17 , V_94 ) ;
F_49 ( V_157 , & V_15 -> V_17 . V_122 ) ;
V_15 -> V_18 -> V_158 = F_38 ;
V_15 -> V_18 -> V_117 = F_45 ;
F_35 ( V_15 -> V_63 ,
3 * V_15 -> V_17 . V_126 -> V_129 ,
3 * V_15 -> V_17 . V_126 -> V_129 ) ;
F_41 ( V_123 , & V_15 -> V_17 . V_122 ) ;
F_41 ( V_127 , & V_15 -> V_17 . V_122 ) ;
switch ( V_15 -> V_18 -> V_4 ) {
case V_5 :
V_153 = V_24 ;
V_154 = V_26 ;
break;
case V_8 :
V_153 = V_34 ;
V_154 = V_159 ;
break;
default:
F_5 () ;
}
V_102 = F_77 ( V_15 -> V_63 , V_153 , V_154 ,
( char * ) & V_155 , sizeof( V_155 ) ) ;
F_8 ( L_19 , V_102 ) ;
}
static void F_78 ( struct V_2 * V_3 , int V_160 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_119 ;
T_3 * V_120 ;
F_8 ( L_20 ,
V_3 , V_3 -> V_161 ) ;
if ( V_3 -> V_161 == V_162 ) {
if ( V_15 ) {
F_41 ( V_163 , & V_15 -> V_17 . V_122 ) ;
F_42 ( & V_15 -> V_17 ) ;
} else
F_60 ( L_21 , V_3 ) ;
}
V_120 = F_39 ( V_3 ) ;
if ( V_120 && F_43 ( V_120 ) )
F_79 ( V_120 ) ;
}
static void F_80 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_119 ;
T_3 * V_120 = F_39 ( V_3 ) ;
F_8 ( L_22 ,
V_3 , V_3 -> V_161 , V_3 -> V_119 ) ;
if ( ! V_15 )
F_60 ( L_21 , V_3 ) ;
else {
F_41 ( V_164 , & V_15 -> V_17 . V_122 ) ;
F_42 ( & V_15 -> V_17 ) ;
}
if ( V_120 && F_43 ( V_120 ) )
F_79 ( V_120 ) ;
}
static void F_81 ( struct V_2 * V_3 , int V_118 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_119 ;
T_3 * V_120 = F_39 ( V_3 ) ;
F_8 ( L_23 ,
V_3 , V_3 -> V_119 ) ;
if ( V_15 ) {
F_41 ( V_123 , & V_15 -> V_17 . V_122 ) ;
F_42 ( & V_15 -> V_17 ) ;
}
if ( V_120 && F_43 ( V_120 ) )
F_44 ( V_120 ) ;
}
static struct V_145 * F_82 ( struct V_145 * V_146 )
{
struct V_14 * V_15 = F_7 ( V_146 , struct V_14 , V_17 ) ;
struct V_165 V_31 ;
struct V_150 * sin = (struct V_150 * ) & V_31 ;
struct V_93 * V_94 = V_15 -> V_17 . V_126 ;
struct V_1 * V_2 = V_15 -> V_63 ;
struct V_1 * V_166 ;
struct V_14 * V_167 ;
int V_102 , V_56 ;
F_17 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_8 ( L_24 , V_15 , V_2 ) ;
if ( ! V_2 )
return NULL ;
F_49 ( V_163 , & V_15 -> V_17 . V_122 ) ;
V_102 = F_83 ( V_2 , & V_166 , V_168 ) ;
if ( V_102 < 0 ) {
if ( V_102 == - V_169 )
F_60 ( V_138 L_25 ,
V_94 -> V_170 ) ;
else if ( V_102 != - V_131 && F_59 () )
F_60 ( V_138 L_26 ,
V_94 -> V_170 , - V_102 ) ;
return NULL ;
}
F_41 ( V_163 , & V_15 -> V_17 . V_122 ) ;
V_102 = F_84 ( V_166 , sin , & V_56 ) ;
if ( V_102 < 0 ) {
if ( F_59 () )
F_60 ( V_138 L_27 ,
V_94 -> V_170 , - V_102 ) ;
goto V_171;
}
if ( ! F_85 ( sin ) ) {
F_8 ( V_138
L_28 ,
V_94 -> V_170 ,
F_86 ( sin , V_83 , sizeof( V_83 ) ) ) ;
}
F_8 ( L_29 , V_94 -> V_170 ,
F_86 ( sin , V_83 , sizeof( V_83 ) ) ) ;
V_166 -> V_3 -> V_172 = V_173 * 30 ;
if ( ! ( V_167 = F_87 ( V_94 , V_166 , & V_102 ,
( V_174 | V_175 ) ) ) )
goto V_171;
F_88 ( & V_167 -> V_17 , sin , V_56 ) ;
V_102 = F_89 ( V_166 , sin , & V_56 ) ;
if ( F_90 ( V_102 < 0 ) ) {
F_8 ( L_30 , - V_102 ) ;
V_56 = F_91 ( struct V_150 , V_176 ) ;
}
F_92 ( & V_167 -> V_17 , sin , V_56 ) ;
if ( V_94 -> V_141 )
V_94 -> V_141 -> V_177 ++ ;
return & V_167 -> V_17 ;
V_171:
F_93 ( V_166 ) ;
return NULL ;
}
static unsigned int F_94 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
unsigned int V_111 , V_57 , V_178 ;
if ( V_15 -> V_179 <= sizeof( V_180 ) )
return 0 ;
V_57 = V_15 -> V_179 - sizeof( V_180 ) ;
V_178 = ( V_57 + V_61 - 1 ) >> V_181 ;
for ( V_111 = 0 ; V_111 < V_178 ; V_111 ++ ) {
if ( V_10 -> V_140 [ V_111 ] != NULL )
F_95 ( V_10 -> V_140 [ V_111 ] ) ;
F_2 ( V_15 -> V_182 [ V_111 ] == NULL ) ;
V_10 -> V_140 [ V_111 ] = V_15 -> V_182 [ V_111 ] ;
V_15 -> V_182 [ V_111 ] = NULL ;
}
V_10 -> V_137 . V_58 [ 0 ] . V_81 = F_96 ( V_10 -> V_140 [ 0 ] ) ;
return V_57 ;
}
static void F_97 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
unsigned int V_111 , V_57 , V_178 ;
if ( V_15 -> V_179 <= sizeof( V_180 ) )
return;
V_57 = V_15 -> V_179 - sizeof( V_180 ) ;
V_178 = ( V_57 + V_61 - 1 ) >> V_181 ;
for ( V_111 = 0 ; V_111 < V_178 ; V_111 ++ ) {
V_15 -> V_182 [ V_111 ] = V_10 -> V_140 [ V_111 ] ;
V_10 -> V_140 [ V_111 ] = NULL ;
}
}
static void F_98 ( struct V_14 * V_15 )
{
unsigned int V_111 , V_57 , V_178 ;
if ( V_15 -> V_179 <= sizeof( V_180 ) )
goto V_60;
V_57 = V_15 -> V_179 - sizeof( V_180 ) ;
V_178 = ( V_57 + V_61 - 1 ) >> V_181 ;
for ( V_111 = 0 ; V_111 < V_178 ; V_111 ++ ) {
F_2 ( V_15 -> V_182 [ V_111 ] == NULL ) ;
F_95 ( V_15 -> V_182 [ V_111 ] ) ;
V_15 -> V_182 [ V_111 ] = NULL ;
}
V_60:
V_15 -> V_179 = 0 ;
}
static int F_99 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
struct V_93 * V_94 = V_15 -> V_17 . V_126 ;
unsigned int V_183 ;
int V_57 ;
F_49 ( V_123 , & V_15 -> V_17 . V_122 ) ;
if ( V_15 -> V_179 < sizeof( V_180 ) ) {
struct V_104 V_105 ;
V_183 = sizeof( V_180 ) - V_15 -> V_179 ;
V_105 . V_81 = ( ( char * ) & V_15 -> V_184 ) + V_15 -> V_179 ;
V_105 . V_59 = V_183 ;
if ( ( V_57 = F_32 ( V_10 , & V_105 , 1 , V_183 ) ) < 0 )
goto error;
V_15 -> V_179 += V_57 ;
if ( V_57 < V_183 ) {
F_8 ( L_31
L_32 , V_57 , V_183 ) ;
return - V_131 ;
}
V_15 -> V_184 = F_100 ( V_15 -> V_184 ) ;
if ( ! ( V_15 -> V_184 & V_185 ) ) {
if ( F_59 () )
F_60 ( V_186 L_33
L_34 ) ;
goto V_187;
}
V_15 -> V_184 &= V_188 ;
F_8 ( L_35 , V_15 -> V_184 ) ;
if ( V_15 -> V_184 > V_94 -> V_129 ) {
if ( F_59 () )
F_60 ( V_186 L_36
L_37 ,
( unsigned long ) V_15 -> V_184 ) ;
goto V_187;
}
}
if ( V_15 -> V_184 < 8 )
goto V_187;
V_57 = V_15 -> V_184 ;
return V_57 ;
error:
F_8 ( L_38 , V_57 ) ;
return V_57 ;
V_187:
F_41 ( V_164 , & V_15 -> V_17 . V_122 ) ;
return - V_131 ;
}
static int F_101 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
struct V_189 * V_190 = V_15 -> V_17 . V_191 ;
struct V_192 * V_193 = NULL ;
struct V_104 * V_194 , * V_195 ;
T_4 * V_196 = ( T_4 * ) V_10 -> V_137 . V_58 [ 0 ] . V_81 ;
T_4 V_197 ;
T_4 V_198 ;
V_197 = * V_196 ++ ;
V_198 = * V_196 ;
if ( V_190 )
V_193 = F_102 ( V_190 , V_197 ) ;
if ( ! V_193 ) {
F_60 ( V_186
L_39
L_40 ,
V_199 , F_100 ( V_198 ) ,
V_190 , V_197 ) ;
return - V_131 ;
}
memcpy ( & V_193 -> V_200 , & V_193 -> V_201 , sizeof( struct V_39 ) ) ;
V_195 = & V_193 -> V_200 . V_58 [ 0 ] ;
V_194 = & V_10 -> V_137 . V_58 [ 0 ] ;
if ( V_195 -> V_59 < V_194 -> V_59 )
return - V_131 ;
memcpy ( V_195 -> V_81 , V_194 -> V_81 , V_194 -> V_59 ) ;
F_103 ( V_193 -> V_202 , V_15 -> V_184 ) ;
V_10 -> V_137 . V_57 = 0 ;
return 0 ;
}
static int F_104 ( struct V_104 * V_203 , struct V_41 * * V_49 , int V_57 )
{
int V_111 = 0 ;
int V_204 = 0 ;
while ( V_204 < V_57 ) {
V_203 [ V_111 ] . V_81 = F_96 ( V_49 [ V_111 ] ) ;
V_203 [ V_111 ] . V_59 = V_61 ;
V_111 ++ ;
V_204 += V_61 ;
}
return V_111 ;
}
static int F_105 ( struct V_9 * V_10 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_93 * V_94 = V_15 -> V_17 . V_126 ;
int V_57 ;
struct V_104 * V_203 ;
unsigned int V_183 , V_50 ;
T_4 * V_196 ;
T_4 V_198 ;
int V_205 ;
F_8 ( L_41 ,
V_15 , F_40 ( V_123 , & V_15 -> V_17 . V_122 ) ,
F_40 ( V_163 , & V_15 -> V_17 . V_122 ) ,
F_40 ( V_164 , & V_15 -> V_17 . V_122 ) ) ;
V_57 = F_99 ( V_15 , V_10 ) ;
if ( V_57 < 0 )
goto error;
V_50 = F_94 ( V_15 , V_10 ) ;
V_183 = V_15 -> V_184 - V_50 ;
V_203 = V_10 -> V_206 ;
V_205 = F_104 ( & V_203 [ 0 ] , & V_10 -> V_140 [ 0 ] ,
V_15 -> V_184 ) ;
V_10 -> V_82 = & V_10 -> V_140 [ V_205 ] ;
V_57 = F_34 ( V_10 , V_203 , V_205 , V_183 , V_50 ) ;
if ( V_57 >= 0 )
V_15 -> V_179 += V_57 ;
if ( V_57 != V_183 ) {
if ( V_57 < 0 && V_57 != - V_131 )
goto V_207;
F_97 ( V_15 , V_10 ) ;
F_8 ( L_42 ,
V_15 -> V_179 , V_15 -> V_184 ) ;
goto V_208;
}
V_10 -> V_137 . V_57 = V_15 -> V_184 ;
V_10 -> V_137 . V_51 = 0 ;
if ( V_10 -> V_137 . V_57 <= V_10 -> V_137 . V_58 [ 0 ] . V_59 ) {
V_10 -> V_137 . V_58 [ 0 ] . V_59 = V_10 -> V_137 . V_57 ;
V_10 -> V_137 . V_53 = 0 ;
} else
V_10 -> V_137 . V_53 = V_10 -> V_137 . V_57 - V_10 -> V_137 . V_58 [ 0 ] . V_59 ;
V_10 -> V_13 = NULL ;
V_10 -> V_70 = V_209 ;
V_196 = ( T_4 * ) V_10 -> V_137 . V_58 [ 0 ] . V_81 ;
V_198 = V_196 [ 1 ] ;
if ( V_198 )
V_57 = F_101 ( V_15 , V_10 ) ;
V_15 -> V_184 = 0 ;
V_15 -> V_179 = 0 ;
if ( F_30 ( V_15 ) > sizeof( V_180 ) )
F_41 ( V_123 , & V_15 -> V_17 . V_122 ) ;
if ( V_57 < 0 )
goto error;
F_106 ( V_10 , & V_15 -> V_17 ) ;
if ( V_94 -> V_141 )
V_94 -> V_141 -> V_210 ++ ;
F_8 ( L_43 , V_10 -> V_137 . V_57 ) ;
return V_10 -> V_137 . V_57 ;
error:
if ( V_57 != - V_131 )
goto V_207;
F_8 ( L_44 ) ;
return - V_131 ;
V_207:
F_60 ( V_186 L_45 ,
V_15 -> V_17 . V_126 -> V_170 , - V_57 ) ;
F_41 ( V_164 , & V_15 -> V_17 . V_122 ) ;
V_208:
return - V_131 ;
}
static int F_107 ( struct V_9 * V_10 )
{
struct V_39 * V_211 = & V_10 -> V_143 ;
int V_212 ;
T_4 V_213 ;
V_213 = F_108 ( 0x80000000 | ( ( V_211 -> V_57 ) - 4 ) ) ;
memcpy ( V_211 -> V_58 [ 0 ] . V_81 , & V_213 , 4 ) ;
V_212 = F_16 ( V_10 , & V_10 -> V_143 ) ;
if ( V_212 != V_211 -> V_57 ) {
F_60 ( V_186
L_46
L_47 ,
V_10 -> V_16 -> V_126 -> V_170 ,
( V_212 < 0 ) ? L_48 : L_49 ,
V_212 , V_211 -> V_57 ) ;
F_41 ( V_164 , & V_10 -> V_16 -> V_122 ) ;
F_42 ( V_10 -> V_16 ) ;
V_212 = - V_131 ;
}
return V_212 ;
}
static void F_109 ( struct V_9 * V_10 )
{
struct V_104 * V_214 = & V_10 -> V_143 . V_58 [ 0 ] ;
F_110 ( V_214 , 0 ) ;
}
static int F_111 ( struct V_145 * V_146 )
{
struct V_14 * V_15 = F_7 ( V_146 , struct V_14 , V_17 ) ;
struct V_93 * V_94 = V_15 -> V_17 . V_126 ;
int V_147 ;
if ( F_40 ( V_215 , & V_146 -> V_122 ) )
return 1 ;
V_147 = F_70 ( & V_146 -> V_148 ) + V_94 -> V_129 ;
if ( F_47 ( V_15 -> V_18 ) >= V_147 )
return 1 ;
F_41 ( V_125 , & V_15 -> V_63 -> V_54 ) ;
return 0 ;
}
static struct V_145 * F_112 ( struct V_93 * V_94 ,
struct V_149 * V_149 ,
struct V_150 * V_151 , int V_152 ,
int V_54 )
{
return F_74 ( V_94 , V_209 , V_149 , V_151 , V_152 , V_54 ) ;
}
static struct V_145 * F_113 ( struct V_93 * V_94 ,
struct V_149 * V_149 ,
struct V_150 * V_151 , int V_152 ,
int V_54 )
{
return F_114 ( V_94 , V_209 , V_149 , V_151 , V_152 , V_54 ) ;
}
static void F_115 ( struct V_145 * V_146 )
{
}
static void F_116 ( void )
{
F_117 ( & V_216 ) ;
}
static void F_118 ( void )
{
F_119 ( & V_216 ) ;
}
static void F_116 ( void )
{
}
static void F_118 ( void )
{
}
void F_120 ( void )
{
F_117 ( & V_217 ) ;
F_117 ( & V_156 ) ;
F_116 () ;
}
void F_121 ( void )
{
F_119 ( & V_217 ) ;
F_119 ( & V_156 ) ;
F_118 () ;
}
static void F_122 ( struct V_14 * V_15 , struct V_93 * V_94 )
{
struct V_2 * V_3 = V_15 -> V_18 ;
F_76 ( & V_217 , & V_15 -> V_17 , V_94 ) ;
F_41 ( V_157 , & V_15 -> V_17 . V_122 ) ;
if ( V_3 -> V_161 == V_162 ) {
F_8 ( L_50 ) ;
F_41 ( V_215 , & V_15 -> V_17 . V_122 ) ;
V_3 -> V_158 = F_78 ;
F_41 ( V_163 , & V_15 -> V_17 . V_122 ) ;
} else {
F_8 ( L_51 ) ;
V_3 -> V_218 = F_80 ;
V_3 -> V_158 = F_81 ;
V_3 -> V_117 = F_46 ;
V_15 -> V_184 = 0 ;
V_15 -> V_179 = 0 ;
memset ( & V_15 -> V_182 [ 0 ] , 0 , sizeof( V_15 -> V_182 ) ) ;
F_123 ( V_3 ) -> V_219 |= V_220 ;
F_41 ( V_123 , & V_15 -> V_17 . V_122 ) ;
if ( V_3 -> V_161 != V_221 )
F_41 ( V_164 , & V_15 -> V_17 . V_122 ) ;
}
}
void F_124 ( struct V_93 * V_94 )
{
struct V_14 * V_15 ;
F_24 ( & V_94 -> V_98 ) ;
F_25 (svsk, &serv->sv_permsocks, sk_xprt.xpt_list)
F_41 ( V_127 , & V_15 -> V_17 . V_122 ) ;
F_25 (svsk, &serv->sv_tempsocks, sk_xprt.xpt_list)
F_41 ( V_127 , & V_15 -> V_17 . V_122 ) ;
F_27 ( & V_94 -> V_98 ) ;
}
static struct V_14 * F_87 ( struct V_93 * V_94 ,
struct V_1 * V_2 ,
int * V_222 , int V_54 )
{
struct V_14 * V_15 ;
struct V_2 * V_223 ;
int V_224 = ! ( V_54 & V_174 ) ;
F_8 ( L_52 , V_2 ) ;
if ( ! ( V_15 = F_125 ( sizeof( * V_15 ) , V_225 ) ) ) {
* V_222 = - V_169 ;
return NULL ;
}
V_223 = V_2 -> V_3 ;
if ( * V_222 >= 0 && V_224 )
* V_222 = F_126 ( V_94 , V_223 -> V_4 , V_223 -> V_86 ,
F_127 ( F_21 ( V_223 ) -> V_226 ) ) ;
if ( * V_222 < 0 ) {
F_128 ( V_15 ) ;
return NULL ;
}
V_223 -> V_119 = V_15 ;
V_15 -> V_63 = V_2 ;
V_15 -> V_18 = V_223 ;
V_15 -> V_227 = V_223 -> V_218 ;
V_15 -> V_228 = V_223 -> V_158 ;
V_15 -> V_229 = V_223 -> V_117 ;
if ( V_2 -> type == V_230 )
F_75 ( V_15 , V_94 ) ;
else {
F_35 ( V_15 -> V_63 , 4 * V_94 -> V_129 ,
4 * V_94 -> V_129 ) ;
F_122 ( V_15 , V_94 ) ;
}
F_8 ( L_53 ,
V_15 , V_15 -> V_18 ) ;
return V_15 ;
}
int F_129 ( struct V_93 * V_94 , const int V_231 , char * V_232 ,
const T_1 V_57 )
{
int V_102 = 0 ;
struct V_1 * V_233 = F_130 ( V_231 , & V_102 ) ;
struct V_14 * V_15 = NULL ;
if ( ! V_233 )
return V_102 ;
if ( ( V_233 -> V_3 -> V_4 != V_87 ) && ( V_233 -> V_3 -> V_4 != V_90 ) )
V_102 = - V_132 ;
else if ( V_233 -> V_3 -> V_86 != V_209 &&
V_233 -> V_3 -> V_86 != V_71 )
V_102 = - V_234 ;
else if ( V_233 -> V_235 > V_236 )
V_102 = - V_237 ;
else {
if ( ! F_131 ( V_238 ) )
V_102 = - V_100 ;
else
V_15 = F_87 ( V_94 , V_233 , & V_102 ,
V_239 ) ;
if ( V_15 ) {
struct V_165 V_31 ;
struct V_150 * sin = (struct V_150 * ) & V_31 ;
int V_152 ;
if ( F_89 ( V_15 -> V_63 , sin , & V_152 ) == 0 )
F_92 ( & V_15 -> V_17 , sin , V_152 ) ;
F_49 ( V_240 , & V_15 -> V_17 . V_122 ) ;
F_24 ( & V_94 -> V_98 ) ;
F_132 ( & V_15 -> V_17 . V_241 , & V_94 -> V_242 ) ;
F_27 ( & V_94 -> V_98 ) ;
F_133 ( & V_15 -> V_17 ) ;
V_102 = 0 ;
} else
F_134 ( V_238 ) ;
}
if ( V_102 ) {
F_135 ( V_233 ) ;
return V_102 ;
}
return F_20 ( V_15 , V_232 , V_57 ) ;
}
static struct V_145 * F_74 ( struct V_93 * V_94 ,
int V_243 ,
struct V_149 * V_149 ,
struct V_150 * sin , int V_57 ,
int V_54 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int error ;
int type ;
struct V_165 V_31 ;
struct V_150 * V_244 = (struct V_150 * ) & V_31 ;
int V_245 ;
int V_246 ;
int V_247 ;
F_17 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_8 ( L_54 ,
V_94 -> V_248 -> V_249 , V_243 ,
F_86 ( sin , V_83 , sizeof( V_83 ) ) ) ;
if ( V_243 != V_71 && V_243 != V_209 ) {
F_60 ( V_138 L_55
L_56 ) ;
return F_136 ( - V_250 ) ;
}
type = ( V_243 == V_71 ) ? V_230 : V_251 ;
switch ( sin -> V_252 ) {
case V_8 :
V_246 = V_90 ;
break;
case V_5 :
V_246 = V_87 ;
break;
default:
return F_136 ( - V_250 ) ;
}
error = F_137 ( V_149 , V_246 , type , V_243 , & V_2 , 1 ) ;
if ( error < 0 )
return F_136 ( error ) ;
F_1 ( V_2 ) ;
V_247 = 1 ;
if ( V_246 == V_90 )
F_77 ( V_2 , V_34 , V_253 ,
( char * ) & V_247 , sizeof( V_247 ) ) ;
if ( type == V_251 )
V_2 -> V_3 -> V_254 = 1 ;
error = F_138 ( V_2 , sin , V_57 ) ;
if ( error < 0 )
goto V_255;
V_245 = V_57 ;
error = F_89 ( V_2 , V_244 , & V_245 ) ;
if ( error < 0 )
goto V_255;
if ( V_243 == V_209 ) {
if ( ( error = F_139 ( V_2 , 64 ) ) < 0 )
goto V_255;
}
if ( ( V_15 = F_87 ( V_94 , V_2 , & error , V_54 ) ) != NULL ) {
F_92 ( & V_15 -> V_17 , V_244 , V_245 ) ;
return (struct V_145 * ) V_15 ;
}
V_255:
F_8 ( L_57 , - error ) ;
F_93 ( V_2 ) ;
return F_136 ( error ) ;
}
static void F_140 ( struct V_145 * V_146 )
{
struct V_14 * V_15 = F_7 ( V_146 , struct V_14 , V_17 ) ;
struct V_2 * V_3 = V_15 -> V_18 ;
T_3 * V_120 ;
F_8 ( L_58 , V_15 ) ;
V_3 -> V_218 = V_15 -> V_227 ;
V_3 -> V_158 = V_15 -> V_228 ;
V_3 -> V_117 = V_15 -> V_229 ;
V_120 = F_39 ( V_3 ) ;
if ( V_120 && F_43 ( V_120 ) )
F_44 ( V_120 ) ;
}
static void F_141 ( struct V_145 * V_146 )
{
struct V_14 * V_15 = F_7 ( V_146 , struct V_14 , V_17 ) ;
F_8 ( L_59 , V_15 ) ;
F_140 ( V_146 ) ;
if ( ! F_40 ( V_215 , & V_146 -> V_122 ) ) {
F_98 ( V_15 ) ;
F_142 ( V_15 -> V_63 , V_256 ) ;
}
}
static void F_143 ( struct V_145 * V_146 )
{
struct V_14 * V_15 = F_7 ( V_146 , struct V_14 , V_17 ) ;
F_8 ( L_60 , V_15 ) ;
if ( V_15 -> V_63 -> V_257 )
F_135 ( V_15 -> V_63 ) ;
else
F_93 ( V_15 -> V_63 ) ;
F_128 ( V_15 ) ;
}
static struct V_145 * F_114 ( struct V_93 * V_94 ,
int V_243 ,
struct V_149 * V_149 ,
struct V_150 * sin , int V_57 ,
int V_54 )
{
struct V_14 * V_15 ;
struct V_145 * V_146 ;
if ( V_243 != V_209 ) {
F_60 ( V_138 L_61
L_62 ) ;
return F_136 ( - V_250 ) ;
}
V_15 = F_125 ( sizeof( * V_15 ) , V_225 ) ;
if ( ! V_15 )
return F_136 ( - V_169 ) ;
V_146 = & V_15 -> V_17 ;
F_76 ( & V_216 , V_146 , V_94 ) ;
V_94 -> V_258 = V_146 ;
return V_146 ;
}
static void F_144 ( struct V_145 * V_146 )
{
if ( V_146 )
F_128 ( F_7 ( V_146 , struct V_14 , V_17 ) ) ;
}
