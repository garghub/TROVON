static void F_1 ( struct V_1 * V_2 )
{
struct V_2 * V_3 = V_2 -> V_3 ;
F_2 ( F_3 ( V_3 ) ) ;
if ( F_3 ( V_3 ) )
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
static bool F_35 ( T_2 * V_114 )
{
if ( ! V_114 )
return false ;
return F_36 ( V_114 ) ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_115 ;
T_2 * V_114 = F_38 ( V_3 ) ;
if ( V_15 ) {
F_8 ( L_13 ,
V_15 , V_3 ,
F_39 ( V_116 , & V_15 -> V_17 . V_104 ) ) ;
F_27 ( V_103 , & V_15 -> V_17 . V_104 ) ;
F_40 ( & V_15 -> V_17 ) ;
}
if ( F_35 ( V_114 ) )
F_41 ( V_114 ) ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) ( V_3 -> V_115 ) ;
T_2 * V_114 = F_38 ( V_3 ) ;
if ( V_15 ) {
F_8 ( L_14 ,
V_15 , V_3 , F_39 ( V_116 , & V_15 -> V_17 . V_104 ) ) ;
F_40 ( & V_15 -> V_17 ) ;
}
if ( F_35 ( V_114 ) ) {
F_8 ( L_15 ,
V_15 ) ;
F_41 ( V_114 ) ;
}
}
static int F_43 ( struct V_117 * V_118 )
{
struct V_14 * V_15 = F_7 ( V_118 , struct V_14 , V_17 ) ;
struct V_119 * V_120 = V_15 -> V_17 . V_121 ;
int V_122 ;
if ( F_39 ( V_123 , & V_118 -> V_104 ) )
return 1 ;
V_122 = F_44 ( & V_118 -> V_124 ) + V_120 -> V_125 ;
if ( F_45 ( V_15 -> V_18 ) >= V_122 ||
( F_46 ( V_15 -> V_18 ) == 0 &&
F_44 ( & V_118 -> V_124 ) == 0 ) )
return 1 ;
F_27 ( V_126 , & V_15 -> V_66 -> V_56 ) ;
return 0 ;
}
static void F_47 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) ( V_3 -> V_115 ) ;
struct V_1 * V_2 = V_3 -> V_127 ;
if ( ! F_48 ( V_3 ) || ! V_2 )
return;
if ( ! V_15 || F_43 ( & V_15 -> V_17 ) )
F_25 ( V_126 , & V_2 -> V_56 ) ;
F_42 ( V_3 ) ;
}
static void F_49 ( struct V_117 * V_118 )
{
struct V_14 * V_15 = F_7 ( V_118 , struct V_14 , V_17 ) ;
if ( F_43 ( V_118 ) )
F_25 ( V_126 , & V_15 -> V_66 -> V_56 ) ;
}
static int F_50 ( struct V_9 * V_10 ,
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
static int F_51 ( struct V_9 * V_10 ,
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
static int F_52 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
switch ( V_20 -> V_23 ) {
case V_24 :
return F_50 ( V_10 , V_20 ) ;
case V_35 :
return F_51 ( V_10 , V_20 ) ;
}
return 0 ;
}
static int F_53 ( struct V_9 * V_10 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_119 * V_120 = V_15 -> V_17 . V_121 ;
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
int V_131 ;
if ( F_54 ( V_132 , & V_15 -> V_17 . V_104 ) )
F_29 ( V_15 -> V_66 ,
( V_120 -> V_133 + 3 ) * V_120 -> V_125 ,
( V_120 -> V_133 + 3 ) * V_120 -> V_125 ) ;
F_25 ( V_103 , & V_15 -> V_17 . V_104 ) ;
V_12 = NULL ;
V_131 = F_26 ( V_15 -> V_66 , & V_76 , NULL ,
0 , 0 , V_134 | V_101 ) ;
if ( V_131 >= 0 )
V_12 = F_55 ( V_15 -> V_18 , 0 , 1 , & V_131 ) ;
if ( V_12 == NULL ) {
if ( V_131 != - V_135 ) {
F_8 ( L_16 , - V_131 ) ;
F_27 ( V_103 , & V_15 -> V_17 . V_104 ) ;
}
return 0 ;
}
V_60 = F_56 ( F_34 ( V_10 ) ) ;
V_10 -> V_80 = V_60 ;
if ( V_12 -> V_136 . V_137 == 0 ) {
V_12 -> V_136 = F_57 () ;
}
V_15 -> V_18 -> V_138 = V_12 -> V_136 ;
F_27 ( V_103 , & V_15 -> V_17 . V_104 ) ;
V_60 = V_12 -> V_60 - sizeof( struct V_139 ) ;
V_10 -> V_140 . V_60 = V_60 ;
V_10 -> V_73 = V_74 ;
if ( ! F_52 ( V_10 , V_20 ) ) {
F_58 ( L_17 ,
V_20 -> V_23 , V_20 -> V_25 ) ;
goto V_141;
}
V_10 -> V_142 = F_56 ( F_59 ( V_10 ) ) ;
if ( F_60 ( V_12 ) ) {
F_61 () ;
if ( F_62 ( & V_10 -> V_140 , V_12 ) ) {
F_63 () ;
goto V_141;
}
F_63 () ;
F_9 ( V_15 -> V_18 , V_12 ) ;
} else {
V_10 -> V_140 . V_61 [ 0 ] . V_84 = V_12 -> V_143 +
sizeof( struct V_139 ) ;
V_10 -> V_140 . V_61 [ 0 ] . V_62 = V_60 ;
if ( F_64 ( V_12 ) )
goto V_141;
V_10 -> V_13 = V_12 ;
}
V_10 -> V_140 . V_53 = 0 ;
if ( V_60 <= V_10 -> V_140 . V_61 [ 0 ] . V_62 ) {
V_10 -> V_140 . V_61 [ 0 ] . V_62 = V_60 ;
V_10 -> V_140 . V_55 = 0 ;
V_10 -> V_85 = V_10 -> V_144 + 1 ;
} else {
V_10 -> V_140 . V_55 = V_60 - V_10 -> V_140 . V_61 [ 0 ] . V_62 ;
V_10 -> V_85 = V_10 -> V_144 + 1 +
F_65 ( V_10 -> V_140 . V_55 , V_64 ) ;
}
V_10 -> V_145 = V_10 -> V_85 + 1 ;
if ( V_120 -> V_146 )
V_120 -> V_146 -> V_147 ++ ;
return V_60 ;
V_141:
F_66 ( V_12 , F_53 ) ;
F_9 ( V_15 -> V_18 , V_12 ) ;
return 0 ;
}
static int
F_67 ( struct V_9 * V_10 )
{
int error ;
error = F_17 ( V_10 , & V_10 -> V_148 ) ;
if ( error == - V_149 )
error = F_17 ( V_10 , & V_10 -> V_148 ) ;
return error ;
}
static void F_68 ( struct V_9 * V_10 )
{
}
static int F_69 ( struct V_117 * V_118 )
{
struct V_14 * V_15 = F_7 ( V_118 , struct V_14 , V_17 ) ;
struct V_119 * V_120 = V_118 -> V_121 ;
unsigned long V_122 ;
F_27 ( V_126 , & V_15 -> V_66 -> V_56 ) ;
V_122 = F_44 ( & V_15 -> V_17 . V_124 ) + V_120 -> V_125 ;
if ( V_122 * 2 > F_70 ( V_15 -> V_18 ) )
return 0 ;
F_25 ( V_126 , & V_15 -> V_66 -> V_56 ) ;
return 1 ;
}
static struct V_117 * F_71 ( struct V_117 * V_118 )
{
F_5 () ;
return NULL ;
}
static struct V_117 * F_72 ( struct V_119 * V_120 ,
struct V_150 * V_150 ,
struct V_151 * V_152 , int V_153 ,
int V_56 )
{
return F_73 ( V_120 , V_74 , V_150 , V_152 , V_153 , V_56 ) ;
}
static void F_74 ( struct V_14 * V_15 , struct V_119 * V_120 )
{
int V_131 , V_154 , V_155 , V_156 = 1 ;
F_75 ( F_76 ( V_15 -> V_66 -> V_3 ) , & V_157 ,
& V_15 -> V_17 , V_120 ) ;
F_25 ( V_158 , & V_15 -> V_17 . V_104 ) ;
V_15 -> V_18 -> V_159 = F_37 ;
V_15 -> V_18 -> V_113 = F_42 ;
F_29 ( V_15 -> V_66 ,
3 * V_15 -> V_17 . V_121 -> V_125 ,
3 * V_15 -> V_17 . V_121 -> V_125 ) ;
F_27 ( V_103 , & V_15 -> V_17 . V_104 ) ;
F_27 ( V_132 , & V_15 -> V_17 . V_104 ) ;
switch ( V_15 -> V_18 -> V_4 ) {
case V_5 :
V_154 = V_24 ;
V_155 = V_26 ;
break;
case V_8 :
V_154 = V_35 ;
V_155 = V_160 ;
break;
default:
F_5 () ;
}
V_131 = F_77 ( V_15 -> V_66 , V_154 , V_155 ,
( char * ) & V_156 , sizeof( V_156 ) ) ;
F_8 ( L_18 , V_131 ) ;
}
static void F_78 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_115 ;
T_2 * V_114 ;
F_8 ( L_19 ,
V_3 , V_3 -> V_161 ) ;
if ( V_3 -> V_161 == V_162 ) {
if ( V_15 ) {
F_27 ( V_163 , & V_15 -> V_17 . V_104 ) ;
F_40 ( & V_15 -> V_17 ) ;
} else
F_79 ( L_20 , V_3 ) ;
}
V_114 = F_38 ( V_3 ) ;
if ( F_35 ( V_114 ) )
F_80 ( V_114 ) ;
}
static void F_81 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_115 ;
T_2 * V_114 = F_38 ( V_3 ) ;
F_8 ( L_21 ,
V_3 , V_3 -> V_161 , V_3 -> V_115 ) ;
if ( ! V_15 )
F_79 ( L_20 , V_3 ) ;
else {
F_27 ( V_164 , & V_15 -> V_17 . V_104 ) ;
F_40 ( & V_15 -> V_17 ) ;
}
if ( F_35 ( V_114 ) )
F_80 ( V_114 ) ;
}
static void F_82 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_115 ;
T_2 * V_114 = F_38 ( V_3 ) ;
F_8 ( L_22 ,
V_3 , V_3 -> V_115 ) ;
if ( V_15 ) {
F_27 ( V_103 , & V_15 -> V_17 . V_104 ) ;
F_40 ( & V_15 -> V_17 ) ;
}
if ( F_35 ( V_114 ) )
F_41 ( V_114 ) ;
}
static struct V_117 * F_83 ( struct V_117 * V_118 )
{
struct V_14 * V_15 = F_7 ( V_118 , struct V_14 , V_17 ) ;
struct V_165 V_166 ;
struct V_151 * sin = (struct V_151 * ) & V_166 ;
struct V_119 * V_120 = V_15 -> V_17 . V_121 ;
struct V_1 * V_2 = V_15 -> V_66 ;
struct V_1 * V_167 ;
struct V_14 * V_168 ;
int V_131 , V_59 ;
F_18 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_8 ( L_23 , V_15 , V_2 ) ;
if ( ! V_2 )
return NULL ;
F_25 ( V_163 , & V_15 -> V_17 . V_104 ) ;
V_131 = F_84 ( V_2 , & V_167 , V_169 ) ;
if ( V_131 < 0 ) {
if ( V_131 == - V_170 )
F_79 ( V_171 L_24 ,
V_120 -> V_172 ) ;
else if ( V_131 != - V_135 )
F_58 ( L_25 ,
V_120 -> V_172 , - V_131 ) ;
return NULL ;
}
F_27 ( V_163 , & V_15 -> V_17 . V_104 ) ;
V_131 = F_85 ( V_167 , sin , & V_59 ) ;
if ( V_131 < 0 ) {
F_58 ( L_26 ,
V_120 -> V_172 , - V_131 ) ;
goto V_173;
}
if ( ! F_33 ( sin ) ) {
F_8 ( L_27 ,
V_120 -> V_172 ,
F_86 ( sin , V_86 , sizeof( V_86 ) ) ) ;
}
F_8 ( L_28 , V_120 -> V_172 ,
F_86 ( sin , V_86 , sizeof( V_86 ) ) ) ;
V_167 -> V_3 -> V_174 = V_175 * 30 ;
V_168 = F_87 ( V_120 , V_167 ,
( V_176 | V_177 ) ) ;
if ( F_88 ( V_168 ) )
goto V_173;
F_89 ( & V_168 -> V_17 , sin , V_59 ) ;
V_131 = F_90 ( V_167 , sin , & V_59 ) ;
if ( F_91 ( V_131 < 0 ) ) {
F_8 ( L_29 , - V_131 ) ;
V_59 = F_92 ( struct V_151 , V_178 ) ;
}
F_93 ( & V_168 -> V_17 , sin , V_59 ) ;
if ( F_94 ( V_167 -> V_3 ) )
F_27 ( V_179 , & V_168 -> V_17 . V_104 ) ;
else
F_25 ( V_179 , & V_168 -> V_17 . V_104 ) ;
if ( V_120 -> V_146 )
V_120 -> V_146 -> V_180 ++ ;
return & V_168 -> V_17 ;
V_173:
F_95 ( V_167 ) ;
return NULL ;
}
static unsigned int F_96 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
unsigned int V_107 , V_60 , V_181 ;
if ( V_15 -> V_182 == 0 )
return 0 ;
V_60 = V_15 -> V_182 ;
V_181 = ( V_60 + V_64 - 1 ) >> V_183 ;
for ( V_107 = 0 ; V_107 < V_181 ; V_107 ++ ) {
if ( V_10 -> V_144 [ V_107 ] != NULL )
F_97 ( V_10 -> V_144 [ V_107 ] ) ;
F_98 ( V_15 -> V_184 [ V_107 ] == NULL ) ;
V_10 -> V_144 [ V_107 ] = V_15 -> V_184 [ V_107 ] ;
V_15 -> V_184 [ V_107 ] = NULL ;
}
V_10 -> V_140 . V_61 [ 0 ] . V_84 = F_99 ( V_10 -> V_144 [ 0 ] ) ;
return V_60 ;
}
static void F_100 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
unsigned int V_107 , V_60 , V_181 ;
if ( V_15 -> V_182 == 0 )
return;
V_60 = V_15 -> V_182 ;
V_181 = ( V_60 + V_64 - 1 ) >> V_183 ;
for ( V_107 = 0 ; V_107 < V_181 ; V_107 ++ ) {
V_15 -> V_184 [ V_107 ] = V_10 -> V_144 [ V_107 ] ;
V_10 -> V_144 [ V_107 ] = NULL ;
}
}
static void F_101 ( struct V_14 * V_15 )
{
unsigned int V_107 , V_60 , V_181 ;
if ( V_15 -> V_182 == 0 )
goto V_63;
V_60 = V_15 -> V_182 ;
V_181 = ( V_60 + V_64 - 1 ) >> V_183 ;
for ( V_107 = 0 ; V_107 < V_181 ; V_107 ++ ) {
if ( V_15 -> V_184 [ V_107 ] == NULL ) {
F_2 ( 1 ) ;
continue;
}
F_97 ( V_15 -> V_184 [ V_107 ] ) ;
V_15 -> V_184 [ V_107 ] = NULL ;
}
V_63:
V_15 -> V_185 = 0 ;
V_15 -> V_182 = 0 ;
}
static int F_102 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
struct V_119 * V_120 = V_15 -> V_17 . V_121 ;
unsigned int V_186 ;
int V_60 ;
if ( V_15 -> V_185 < sizeof( V_187 ) ) {
struct V_97 V_98 ;
V_186 = sizeof( V_187 ) - V_15 -> V_185 ;
V_98 . V_84 = ( ( char * ) & V_15 -> V_188 ) + V_15 -> V_185 ;
V_98 . V_62 = V_186 ;
if ( ( V_60 = F_24 ( V_10 , & V_98 , 1 , V_186 ) ) < 0 )
goto error;
V_15 -> V_185 += V_60 ;
if ( V_60 < V_186 ) {
F_8 ( L_30
L_31 , V_60 , V_186 ) ;
return - V_135 ;
}
F_8 ( L_32 , F_103 ( V_15 ) ) ;
if ( F_103 ( V_15 ) + V_15 -> V_182 >
V_120 -> V_125 ) {
F_104 ( L_33 ,
F_103 ( V_15 ) ) ;
goto V_189;
}
}
return F_103 ( V_15 ) ;
error:
F_8 ( L_34 , V_60 ) ;
return V_60 ;
V_189:
F_27 ( V_164 , & V_15 -> V_17 . V_104 ) ;
return - V_135 ;
}
static int F_105 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
struct V_190 * V_191 = V_15 -> V_17 . V_192 ;
struct V_193 * V_194 = NULL ;
struct V_97 * V_195 , * V_196 ;
T_3 * V_197 = ( T_3 * ) V_10 -> V_140 . V_61 [ 0 ] . V_84 ;
T_3 V_198 ;
T_3 V_199 ;
V_198 = * V_197 ++ ;
V_199 = * V_197 ;
if ( ! V_191 )
return - V_135 ;
F_106 ( & V_191 -> V_200 ) ;
V_194 = F_107 ( V_191 , V_198 ) ;
if ( ! V_194 )
goto V_201;
memcpy ( & V_194 -> V_202 , & V_194 -> V_203 , sizeof( struct V_41 ) ) ;
V_196 = & V_194 -> V_202 . V_61 [ 0 ] ;
V_195 = & V_10 -> V_140 . V_61 [ 0 ] ;
if ( V_196 -> V_62 < V_195 -> V_62 )
goto V_204;
memcpy ( V_196 -> V_84 , V_195 -> V_84 , V_195 -> V_62 ) ;
F_108 ( V_194 -> V_205 , V_10 -> V_140 . V_60 ) ;
V_10 -> V_140 . V_60 = 0 ;
F_109 ( & V_191 -> V_200 ) ;
return 0 ;
V_201:
F_79 ( V_206
L_35
L_36 ,
V_207 , F_110 ( V_199 ) ,
V_191 , F_110 ( V_198 ) ) ;
V_204:
F_109 ( & V_191 -> V_200 ) ;
return - V_135 ;
}
static int F_111 ( struct V_97 * V_208 , struct V_43 * * V_51 , int V_60 )
{
int V_107 = 0 ;
int V_209 = 0 ;
while ( V_209 < V_60 ) {
V_208 [ V_107 ] . V_84 = F_99 ( V_51 [ V_107 ] ) ;
V_208 [ V_107 ] . V_62 = V_64 ;
V_107 ++ ;
V_209 += V_64 ;
}
return V_107 ;
}
static void F_112 ( struct V_14 * V_15 )
{
F_8 ( L_37 ,
F_113 ( V_15 ) ? L_38 : L_39 ,
F_103 ( V_15 ) ) ;
V_15 -> V_185 = 0 ;
V_15 -> V_188 = 0 ;
}
static int F_114 ( struct V_9 * V_10 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_119 * V_120 = V_15 -> V_17 . V_121 ;
int V_60 ;
struct V_97 * V_208 ;
unsigned int V_186 , V_52 ;
T_3 * V_197 ;
T_3 V_199 ;
int V_210 ;
F_8 ( L_40 ,
V_15 , F_39 ( V_103 , & V_15 -> V_17 . V_104 ) ,
F_39 ( V_163 , & V_15 -> V_17 . V_104 ) ,
F_39 ( V_164 , & V_15 -> V_17 . V_104 ) ) ;
V_60 = F_102 ( V_15 , V_10 ) ;
if ( V_60 < 0 )
goto error;
V_52 = F_96 ( V_15 , V_10 ) ;
V_186 = F_103 ( V_15 ) - ( V_15 -> V_185 - sizeof( V_187 ) ) ;
V_208 = V_10 -> V_211 ;
V_210 = F_111 ( & V_208 [ 0 ] , & V_10 -> V_144 [ 0 ] ,
V_15 -> V_182 + V_186 ) ;
V_10 -> V_85 = & V_10 -> V_144 [ V_210 ] ;
V_10 -> V_145 = V_10 -> V_85 + 1 ;
V_60 = F_28 ( V_10 , V_208 , V_210 , V_186 , V_52 ) ;
if ( V_60 >= 0 ) {
V_15 -> V_185 += V_60 ;
V_15 -> V_182 += V_60 ;
}
if ( V_60 != V_186 || ! F_113 ( V_15 ) ) {
F_100 ( V_15 , V_10 ) ;
if ( V_60 < 0 && V_60 != - V_135 )
goto V_189;
if ( V_60 == V_186 )
F_112 ( V_15 ) ;
else
F_8 ( L_41 ,
( int ) ( V_15 -> V_185 - sizeof( V_187 ) ) ,
F_103 ( V_15 ) ) ;
goto V_212;
}
if ( V_15 -> V_182 < 8 ) {
V_15 -> V_182 = 0 ;
goto V_189;
}
V_10 -> V_140 . V_60 = V_15 -> V_182 ;
V_10 -> V_140 . V_53 = 0 ;
if ( V_10 -> V_140 . V_60 <= V_10 -> V_140 . V_61 [ 0 ] . V_62 ) {
V_10 -> V_140 . V_61 [ 0 ] . V_62 = V_10 -> V_140 . V_60 ;
V_10 -> V_140 . V_55 = 0 ;
} else
V_10 -> V_140 . V_55 = V_10 -> V_140 . V_60 - V_10 -> V_140 . V_61 [ 0 ] . V_62 ;
V_10 -> V_13 = NULL ;
V_10 -> V_73 = V_213 ;
if ( F_39 ( V_179 , & V_15 -> V_17 . V_104 ) )
F_27 ( V_214 , & V_10 -> V_215 ) ;
else
F_25 ( V_214 , & V_10 -> V_215 ) ;
V_197 = ( T_3 * ) V_10 -> V_140 . V_61 [ 0 ] . V_84 ;
V_199 = V_197 [ 1 ] ;
if ( V_199 )
V_60 = F_105 ( V_15 , V_10 ) ;
V_15 -> V_182 = 0 ;
F_112 ( V_15 ) ;
if ( V_60 < 0 )
goto error;
F_115 ( V_10 , & V_15 -> V_17 ) ;
if ( V_120 -> V_146 )
V_120 -> V_146 -> V_216 ++ ;
return V_10 -> V_140 . V_60 ;
error:
if ( V_60 != - V_135 )
goto V_189;
F_8 ( L_42 ) ;
return 0 ;
V_189:
F_79 ( V_206 L_43 ,
V_15 -> V_17 . V_121 -> V_172 , - V_60 ) ;
F_27 ( V_164 , & V_15 -> V_17 . V_104 ) ;
V_212:
return 0 ;
}
static int F_116 ( struct V_9 * V_10 )
{
struct V_41 * V_217 = & V_10 -> V_148 ;
int V_218 ;
T_3 V_219 ;
V_219 = F_117 ( 0x80000000 | ( ( V_217 -> V_60 ) - 4 ) ) ;
memcpy ( V_217 -> V_61 [ 0 ] . V_84 , & V_219 , 4 ) ;
V_218 = F_17 ( V_10 , & V_10 -> V_148 ) ;
if ( V_218 != V_217 -> V_60 ) {
F_79 ( V_206
L_44
L_45 ,
V_10 -> V_16 -> V_121 -> V_172 ,
( V_218 < 0 ) ? L_46 : L_47 ,
V_218 , V_217 -> V_60 ) ;
F_27 ( V_164 , & V_10 -> V_16 -> V_104 ) ;
F_40 ( V_10 -> V_16 ) ;
V_218 = - V_135 ;
}
return V_218 ;
}
static void F_118 ( struct V_9 * V_10 )
{
struct V_97 * V_220 = & V_10 -> V_148 . V_61 [ 0 ] ;
F_119 ( V_220 , 0 ) ;
}
static struct V_117 * F_120 ( struct V_119 * V_120 ,
struct V_150 * V_150 ,
struct V_151 * V_152 , int V_153 ,
int V_56 )
{
return F_73 ( V_120 , V_213 , V_150 , V_152 , V_153 , V_56 ) ;
}
static struct V_117 * F_121 ( struct V_119 * V_120 ,
struct V_150 * V_150 ,
struct V_151 * V_152 , int V_153 ,
int V_56 )
{
return F_122 ( V_120 , V_213 , V_150 , V_152 , V_153 , V_56 ) ;
}
static void F_123 ( struct V_117 * V_118 )
{
}
static void F_124 ( void )
{
F_125 ( & V_221 ) ;
}
static void F_126 ( void )
{
F_127 ( & V_221 ) ;
}
static void F_124 ( void )
{
}
static void F_126 ( void )
{
}
void F_128 ( void )
{
F_125 ( & V_222 ) ;
F_125 ( & V_157 ) ;
F_124 () ;
}
void F_129 ( void )
{
F_127 ( & V_222 ) ;
F_127 ( & V_157 ) ;
F_126 () ;
}
static void F_130 ( struct V_14 * V_15 , struct V_119 * V_120 )
{
struct V_2 * V_3 = V_15 -> V_18 ;
F_75 ( F_76 ( V_15 -> V_66 -> V_3 ) , & V_222 ,
& V_15 -> V_17 , V_120 ) ;
F_27 ( V_158 , & V_15 -> V_17 . V_104 ) ;
if ( V_3 -> V_161 == V_162 ) {
F_8 ( L_48 ) ;
F_27 ( V_123 , & V_15 -> V_17 . V_104 ) ;
V_3 -> V_159 = F_78 ;
F_27 ( V_163 , & V_15 -> V_17 . V_104 ) ;
} else {
F_8 ( L_49 ) ;
V_3 -> V_223 = F_81 ;
V_3 -> V_159 = F_82 ;
V_3 -> V_113 = F_47 ;
V_15 -> V_188 = 0 ;
V_15 -> V_185 = 0 ;
V_15 -> V_182 = 0 ;
memset ( & V_15 -> V_184 [ 0 ] , 0 , sizeof( V_15 -> V_184 ) ) ;
F_131 ( V_3 ) -> V_224 |= V_225 ;
F_27 ( V_103 , & V_15 -> V_17 . V_104 ) ;
if ( V_3 -> V_161 != V_226 )
F_27 ( V_164 , & V_15 -> V_17 . V_104 ) ;
}
}
void F_132 ( struct V_119 * V_120 )
{
struct V_14 * V_15 ;
F_106 ( & V_120 -> V_227 ) ;
F_133 (svsk, &serv->sv_permsocks, sk_xprt.xpt_list)
F_27 ( V_132 , & V_15 -> V_17 . V_104 ) ;
F_109 ( & V_120 -> V_227 ) ;
}
static struct V_14 * F_87 ( struct V_119 * V_120 ,
struct V_1 * V_2 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_2 * V_228 ;
int V_229 = ! ( V_56 & V_176 ) ;
int V_131 = 0 ;
F_8 ( L_50 , V_2 ) ;
V_15 = F_134 ( sizeof( * V_15 ) , V_230 ) ;
if ( ! V_15 )
return F_135 ( - V_170 ) ;
V_228 = V_2 -> V_3 ;
if ( V_229 )
V_131 = F_136 ( V_120 , F_76 ( V_2 -> V_3 ) , V_228 -> V_4 ,
V_228 -> V_89 ,
F_137 ( F_22 ( V_228 ) -> V_231 ) ) ;
if ( V_131 < 0 ) {
F_138 ( V_15 ) ;
return F_135 ( V_131 ) ;
}
V_228 -> V_115 = V_15 ;
V_15 -> V_66 = V_2 ;
V_15 -> V_18 = V_228 ;
V_15 -> V_232 = V_228 -> V_223 ;
V_15 -> V_233 = V_228 -> V_159 ;
V_15 -> V_234 = V_228 -> V_113 ;
if ( V_2 -> type == V_235 )
F_74 ( V_15 , V_120 ) ;
else {
F_29 ( V_15 -> V_66 , 4 * V_120 -> V_125 ,
4 * V_120 -> V_125 ) ;
F_130 ( V_15 , V_120 ) ;
}
F_8 ( L_51 ,
V_15 , V_15 -> V_18 ) ;
return V_15 ;
}
bool F_139 ( struct V_150 * V_150 , int V_236 )
{
int V_131 ;
struct V_1 * V_2 = F_140 ( V_236 , & V_131 ) ;
bool V_108 = false ;
if ( ! V_2 )
goto V_63;
if ( F_76 ( V_2 -> V_3 ) != V_150 )
V_108 = true ;
F_141 ( V_2 ) ;
V_63:
return V_108 ;
}
int F_142 ( struct V_119 * V_120 , const int V_236 , char * V_237 ,
const T_1 V_60 )
{
int V_131 = 0 ;
struct V_1 * V_238 = F_140 ( V_236 , & V_131 ) ;
struct V_14 * V_15 = NULL ;
struct V_165 V_166 ;
struct V_151 * sin = (struct V_151 * ) & V_166 ;
int V_153 ;
if ( ! V_238 )
return V_131 ;
V_131 = - V_239 ;
if ( ( V_238 -> V_3 -> V_4 != V_90 ) && ( V_238 -> V_3 -> V_4 != V_94 ) )
goto V_63;
V_131 = - V_240 ;
if ( V_238 -> V_3 -> V_89 != V_213 &&
V_238 -> V_3 -> V_89 != V_74 )
goto V_63;
V_131 = - V_241 ;
if ( V_238 -> V_242 > V_243 )
goto V_63;
V_131 = - V_244 ;
if ( ! F_143 ( V_245 ) )
goto V_63;
V_15 = F_87 ( V_120 , V_238 , V_246 ) ;
if ( F_88 ( V_15 ) ) {
F_144 ( V_245 ) ;
V_131 = F_145 ( V_15 ) ;
goto V_63;
}
if ( F_90 ( V_15 -> V_66 , sin , & V_153 ) == 0 )
F_93 ( & V_15 -> V_17 , sin , V_153 ) ;
F_146 ( V_120 , & V_15 -> V_17 ) ;
return F_21 ( V_15 , V_237 , V_60 ) ;
V_63:
F_141 ( V_238 ) ;
return V_131 ;
}
static struct V_117 * F_73 ( struct V_119 * V_120 ,
int V_247 ,
struct V_150 * V_150 ,
struct V_151 * sin , int V_60 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int error ;
int type ;
struct V_165 V_166 ;
struct V_151 * V_248 = (struct V_151 * ) & V_166 ;
int V_249 ;
int V_250 ;
int V_251 ;
F_18 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_8 ( L_52 ,
V_120 -> V_252 -> V_253 , V_247 ,
F_86 ( sin , V_86 , sizeof( V_86 ) ) ) ;
if ( V_247 != V_74 && V_247 != V_213 ) {
F_79 ( V_171 L_53
L_54 ) ;
return F_135 ( - V_254 ) ;
}
type = ( V_247 == V_74 ) ? V_235 : V_255 ;
switch ( sin -> V_256 ) {
case V_8 :
V_250 = V_94 ;
break;
case V_5 :
V_250 = V_90 ;
break;
default:
return F_135 ( - V_254 ) ;
}
error = F_147 ( V_150 , V_250 , type , V_247 , & V_2 , 1 ) ;
if ( error < 0 )
return F_135 ( error ) ;
F_1 ( V_2 ) ;
V_251 = 1 ;
if ( V_250 == V_94 )
F_77 ( V_2 , V_35 , V_257 ,
( char * ) & V_251 , sizeof( V_251 ) ) ;
if ( type == V_255 )
V_2 -> V_3 -> V_258 = V_259 ;
error = F_148 ( V_2 , sin , V_60 ) ;
if ( error < 0 )
goto V_260;
V_249 = V_60 ;
error = F_90 ( V_2 , V_248 , & V_249 ) ;
if ( error < 0 )
goto V_260;
if ( V_247 == V_213 ) {
if ( ( error = F_149 ( V_2 , 64 ) ) < 0 )
goto V_260;
}
V_15 = F_87 ( V_120 , V_2 , V_56 ) ;
if ( F_88 ( V_15 ) ) {
error = F_145 ( V_15 ) ;
goto V_260;
}
F_93 ( & V_15 -> V_17 , V_248 , V_249 ) ;
return (struct V_117 * ) V_15 ;
V_260:
F_8 ( L_55 , - error ) ;
F_95 ( V_2 ) ;
return F_135 ( error ) ;
}
static void F_150 ( struct V_117 * V_118 )
{
struct V_14 * V_15 = F_7 ( V_118 , struct V_14 , V_17 ) ;
struct V_2 * V_3 = V_15 -> V_18 ;
T_2 * V_114 ;
F_8 ( L_56 , V_15 ) ;
V_3 -> V_223 = V_15 -> V_232 ;
V_3 -> V_159 = V_15 -> V_233 ;
V_3 -> V_113 = V_15 -> V_234 ;
V_114 = F_38 ( V_3 ) ;
if ( F_35 ( V_114 ) )
F_41 ( V_114 ) ;
}
static void F_151 ( struct V_117 * V_118 )
{
struct V_14 * V_15 = F_7 ( V_118 , struct V_14 , V_17 ) ;
F_8 ( L_57 , V_15 ) ;
F_150 ( V_118 ) ;
if ( ! F_39 ( V_123 , & V_118 -> V_104 ) ) {
F_101 ( V_15 ) ;
F_152 ( V_15 -> V_66 , V_261 ) ;
}
}
static void F_153 ( struct V_117 * V_118 )
{
struct V_14 * V_15 = F_7 ( V_118 , struct V_14 , V_17 ) ;
F_8 ( L_58 , V_15 ) ;
if ( V_15 -> V_66 -> V_262 )
F_141 ( V_15 -> V_66 ) ;
else
F_95 ( V_15 -> V_66 ) ;
F_138 ( V_15 ) ;
}
static struct V_117 * F_122 ( struct V_119 * V_120 ,
int V_247 ,
struct V_150 * V_150 ,
struct V_151 * sin , int V_60 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_117 * V_118 ;
if ( V_247 != V_213 ) {
F_79 ( V_171 L_59
L_60 ) ;
return F_135 ( - V_254 ) ;
}
V_15 = F_134 ( sizeof( * V_15 ) , V_230 ) ;
if ( ! V_15 )
return F_135 ( - V_170 ) ;
V_118 = & V_15 -> V_17 ;
F_75 ( V_150 , & V_221 , V_118 , V_120 ) ;
V_120 -> V_263 = V_118 ;
return V_118 ;
}
static void F_154 ( struct V_117 * V_118 )
{
if ( V_118 )
F_138 ( F_7 ( V_118 , struct V_14 , V_17 ) ) ;
}
