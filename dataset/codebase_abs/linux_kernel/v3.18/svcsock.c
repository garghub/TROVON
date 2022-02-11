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
#if F_23 ( V_92 )
case V_93 :
V_59 = snprintf ( V_85 , V_86 , L_10 ,
V_87 ,
& V_3 -> V_94 ,
F_22 ( V_3 ) -> V_91 ) ;
break;
#endif
default:
V_59 = snprintf ( V_85 , V_86 , L_11 ,
V_3 -> V_4 ) ;
}
if ( V_59 >= V_86 ) {
* V_85 = '\0' ;
return - V_95 ;
}
return V_59 ;
}
static int F_24 ( struct V_9 * V_10 , struct V_96 * V_97 , int V_98 ,
int V_99 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_74 V_75 = {
. V_82 = V_100 ,
} ;
int V_59 ;
V_10 -> V_101 = 0 ;
F_25 ( V_102 , & V_15 -> V_17 . V_103 ) ;
V_59 = F_26 ( V_15 -> V_65 , & V_75 , V_97 , V_98 , V_99 ,
V_75 . V_82 ) ;
if ( V_59 == V_99 )
F_27 ( V_102 , & V_15 -> V_17 . V_103 ) ;
F_8 ( L_12 ,
V_15 , V_97 [ 0 ] . V_83 , V_97 [ 0 ] . V_61 , V_59 ) ;
return V_59 ;
}
static int F_28 ( struct V_9 * V_10 ,
struct V_96 * V_97 , int V_98 ,
int V_99 , unsigned int V_52 )
{
T_1 V_104 ;
void * V_105 ;
unsigned int V_106 ;
int V_107 ;
if ( V_52 == 0 )
return F_24 ( V_10 , V_97 , V_98 , V_99 ) ;
for ( V_106 = 0 ; V_106 < V_98 ; V_106 ++ ) {
if ( V_97 [ V_106 ] . V_61 > V_52 )
break;
V_52 -= V_97 [ V_106 ] . V_61 ;
}
V_104 = V_97 [ V_106 ] . V_61 ;
V_105 = V_97 [ V_106 ] . V_83 ;
V_97 [ V_106 ] . V_61 -= V_52 ;
V_97 [ V_106 ] . V_83 += V_52 ;
V_107 = F_24 ( V_10 , & V_97 [ V_106 ] , V_98 - V_106 , V_99 ) ;
V_97 [ V_106 ] . V_61 = V_104 ;
V_97 [ V_106 ] . V_83 = V_105 ;
return V_107 ;
}
static void F_29 ( struct V_1 * V_2 , unsigned int V_108 ,
unsigned int V_109 )
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
V_2 -> V_3 -> V_110 = V_108 * 2 ;
V_2 -> V_3 -> V_111 = V_109 * 2 ;
V_2 -> V_3 -> V_112 ( V_2 -> V_3 ) ;
F_31 ( V_2 -> V_3 ) ;
#endif
}
static int F_32 ( struct V_9 * V_10 )
{
return F_33 ( F_34 ( V_10 ) ) ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_113 ;
T_2 * V_114 = F_36 ( V_3 ) ;
if ( V_15 ) {
F_8 ( L_13 ,
V_15 , V_3 ,
F_37 ( V_115 , & V_15 -> V_17 . V_103 ) ) ;
F_27 ( V_102 , & V_15 -> V_17 . V_103 ) ;
F_38 ( & V_15 -> V_17 ) ;
}
if ( V_114 && F_39 ( V_114 ) )
F_40 ( V_114 ) ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) ( V_3 -> V_113 ) ;
T_2 * V_114 = F_36 ( V_3 ) ;
if ( V_15 ) {
F_8 ( L_14 ,
V_15 , V_3 , F_37 ( V_115 , & V_15 -> V_17 . V_103 ) ) ;
F_38 ( & V_15 -> V_17 ) ;
}
if ( V_114 && F_39 ( V_114 ) ) {
F_8 ( L_15 ,
V_15 ) ;
F_40 ( V_114 ) ;
}
}
static int F_42 ( struct V_116 * V_117 )
{
struct V_14 * V_15 = F_7 ( V_117 , struct V_14 , V_17 ) ;
struct V_118 * V_119 = V_15 -> V_17 . V_120 ;
int V_121 ;
if ( F_37 ( V_122 , & V_117 -> V_103 ) )
return 1 ;
V_121 = F_43 ( & V_117 -> V_123 ) + V_119 -> V_124 ;
if ( F_44 ( V_15 -> V_18 ) >= V_121 ||
( F_45 ( V_15 -> V_18 ) == 0 &&
F_43 ( & V_117 -> V_123 ) == 0 ) )
return 1 ;
F_27 ( V_125 , & V_15 -> V_65 -> V_56 ) ;
return 0 ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) ( V_3 -> V_113 ) ;
struct V_1 * V_2 = V_3 -> V_126 ;
if ( ! F_47 ( V_3 ) || ! V_2 )
return;
if ( ! V_15 || F_42 ( & V_15 -> V_17 ) )
F_25 ( V_125 , & V_2 -> V_56 ) ;
F_41 ( V_3 ) ;
}
static void F_48 ( struct V_116 * V_117 )
{
struct V_14 * V_15 = F_7 ( V_117 , struct V_14 , V_17 ) ;
if ( F_42 ( V_117 ) )
F_25 ( V_125 , & V_15 -> V_65 -> V_56 ) ;
}
static int F_49 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = F_11 ( V_20 ) ;
struct V_127 * V_34 = F_12 ( V_10 ) ;
if ( V_20 -> V_25 != V_26 )
return 0 ;
V_34 -> V_128 = V_5 ;
V_34 -> V_30 . V_29 = V_22 -> V_28 . V_29 ;
return 1 ;
}
static int F_50 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
struct V_32 * V_22 = F_11 ( V_20 ) ;
struct V_33 * V_34 = F_14 ( V_10 ) ;
if ( V_20 -> V_25 != V_36 )
return 0 ;
V_34 -> V_129 = V_8 ;
V_34 -> V_40 = V_22 -> V_39 ;
V_34 -> V_38 = V_22 -> V_37 ;
return 1 ;
}
static int F_51 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
switch ( V_20 -> V_23 ) {
case V_24 :
return F_49 ( V_10 , V_20 ) ;
case V_35 :
return F_50 ( V_10 , V_20 ) ;
}
return 0 ;
}
static int F_52 ( struct V_9 * V_10 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_118 * V_119 = V_15 -> V_17 . V_120 ;
struct V_11 * V_12 ;
union {
struct V_19 V_66 ;
long V_67 [ V_68 / sizeof( long ) ] ;
} V_69 ;
struct V_19 * V_20 = & V_69 . V_66 ;
struct V_74 V_75 = {
. V_76 = F_34 ( V_10 ) ,
. V_80 = V_20 ,
. V_81 = sizeof( V_69 ) ,
. V_82 = V_100 ,
} ;
T_1 V_59 ;
int V_130 ;
if ( F_53 ( V_131 , & V_15 -> V_17 . V_103 ) )
F_29 ( V_15 -> V_65 ,
( V_119 -> V_132 + 3 ) * V_119 -> V_124 ,
( V_119 -> V_132 + 3 ) * V_119 -> V_124 ) ;
F_25 ( V_102 , & V_15 -> V_17 . V_103 ) ;
V_12 = NULL ;
V_130 = F_26 ( V_15 -> V_65 , & V_75 , NULL ,
0 , 0 , V_133 | V_100 ) ;
if ( V_130 >= 0 )
V_12 = F_54 ( V_15 -> V_18 , 0 , 1 , & V_130 ) ;
if ( V_12 == NULL ) {
if ( V_130 != - V_134 ) {
F_8 ( L_16 , - V_130 ) ;
F_27 ( V_102 , & V_15 -> V_17 . V_103 ) ;
}
return 0 ;
}
V_59 = F_55 ( F_34 ( V_10 ) ) ;
V_10 -> V_79 = V_59 ;
if ( V_12 -> V_135 . V_136 == 0 ) {
V_12 -> V_135 = F_56 () ;
}
V_15 -> V_18 -> V_137 = V_12 -> V_135 ;
F_27 ( V_102 , & V_15 -> V_17 . V_103 ) ;
V_59 = V_12 -> V_59 - sizeof( struct V_138 ) ;
V_10 -> V_139 . V_59 = V_59 ;
V_10 -> V_72 = V_73 ;
if ( ! F_51 ( V_10 , V_20 ) ) {
F_57 ( L_17 ,
V_20 -> V_23 , V_20 -> V_25 ) ;
goto V_140;
}
V_10 -> V_141 = F_55 ( F_58 ( V_10 ) ) ;
if ( F_59 ( V_12 ) ) {
F_60 () ;
if ( F_61 ( & V_10 -> V_139 , V_12 ) ) {
F_62 () ;
goto V_140;
}
F_62 () ;
F_9 ( V_15 -> V_18 , V_12 ) ;
} else {
V_10 -> V_139 . V_60 [ 0 ] . V_83 = V_12 -> V_142 +
sizeof( struct V_138 ) ;
V_10 -> V_139 . V_60 [ 0 ] . V_61 = V_59 ;
if ( F_63 ( V_12 ) )
goto V_140;
V_10 -> V_13 = V_12 ;
}
V_10 -> V_139 . V_53 = 0 ;
if ( V_59 <= V_10 -> V_139 . V_60 [ 0 ] . V_61 ) {
V_10 -> V_139 . V_60 [ 0 ] . V_61 = V_59 ;
V_10 -> V_139 . V_55 = 0 ;
V_10 -> V_84 = V_10 -> V_143 + 1 ;
} else {
V_10 -> V_139 . V_55 = V_59 - V_10 -> V_139 . V_60 [ 0 ] . V_61 ;
V_10 -> V_84 = V_10 -> V_143 + 1 +
F_64 ( V_10 -> V_139 . V_55 , V_63 ) ;
}
V_10 -> V_144 = V_10 -> V_84 + 1 ;
if ( V_119 -> V_145 )
V_119 -> V_145 -> V_146 ++ ;
return V_59 ;
V_140:
F_65 ( V_12 , F_52 ) ;
F_9 ( V_15 -> V_18 , V_12 ) ;
return 0 ;
}
static int
F_66 ( struct V_9 * V_10 )
{
int error ;
error = F_17 ( V_10 , & V_10 -> V_147 ) ;
if ( error == - V_148 )
error = F_17 ( V_10 , & V_10 -> V_147 ) ;
return error ;
}
static void F_67 ( struct V_9 * V_10 )
{
}
static int F_68 ( struct V_116 * V_117 )
{
struct V_14 * V_15 = F_7 ( V_117 , struct V_14 , V_17 ) ;
struct V_118 * V_119 = V_117 -> V_120 ;
unsigned long V_121 ;
F_27 ( V_125 , & V_15 -> V_65 -> V_56 ) ;
V_121 = F_43 ( & V_15 -> V_17 . V_123 ) + V_119 -> V_124 ;
if ( V_121 * 2 > F_69 ( V_15 -> V_18 ) )
return 0 ;
F_25 ( V_125 , & V_15 -> V_65 -> V_56 ) ;
return 1 ;
}
static struct V_116 * F_70 ( struct V_116 * V_117 )
{
F_5 () ;
return NULL ;
}
static struct V_116 * F_71 ( struct V_118 * V_119 ,
struct V_149 * V_149 ,
struct V_150 * V_151 , int V_152 ,
int V_56 )
{
return F_72 ( V_119 , V_73 , V_149 , V_151 , V_152 , V_56 ) ;
}
static void F_73 ( struct V_14 * V_15 , struct V_118 * V_119 )
{
int V_130 , V_153 , V_154 , V_155 = 1 ;
F_74 ( F_75 ( V_15 -> V_65 -> V_3 ) , & V_156 ,
& V_15 -> V_17 , V_119 ) ;
F_25 ( V_157 , & V_15 -> V_17 . V_103 ) ;
V_15 -> V_18 -> V_158 = F_35 ;
V_15 -> V_18 -> V_112 = F_41 ;
F_29 ( V_15 -> V_65 ,
3 * V_15 -> V_17 . V_120 -> V_124 ,
3 * V_15 -> V_17 . V_120 -> V_124 ) ;
F_27 ( V_102 , & V_15 -> V_17 . V_103 ) ;
F_27 ( V_131 , & V_15 -> V_17 . V_103 ) ;
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
V_130 = F_76 ( V_15 -> V_65 , V_153 , V_154 ,
( char * ) & V_155 , sizeof( V_155 ) ) ;
F_8 ( L_18 , V_130 ) ;
}
static void F_77 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_113 ;
T_2 * V_114 ;
F_8 ( L_19 ,
V_3 , V_3 -> V_160 ) ;
if ( V_3 -> V_160 == V_161 ) {
if ( V_15 ) {
F_27 ( V_162 , & V_15 -> V_17 . V_103 ) ;
F_38 ( & V_15 -> V_17 ) ;
} else
F_78 ( L_20 , V_3 ) ;
}
V_114 = F_36 ( V_3 ) ;
if ( V_114 && F_39 ( V_114 ) )
F_79 ( V_114 ) ;
}
static void F_80 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_113 ;
T_2 * V_114 = F_36 ( V_3 ) ;
F_8 ( L_21 ,
V_3 , V_3 -> V_160 , V_3 -> V_113 ) ;
if ( ! V_15 )
F_78 ( L_20 , V_3 ) ;
else {
F_27 ( V_163 , & V_15 -> V_17 . V_103 ) ;
F_38 ( & V_15 -> V_17 ) ;
}
if ( V_114 && F_39 ( V_114 ) )
F_79 ( V_114 ) ;
}
static void F_81 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_113 ;
T_2 * V_114 = F_36 ( V_3 ) ;
F_8 ( L_22 ,
V_3 , V_3 -> V_113 ) ;
if ( V_15 ) {
F_27 ( V_102 , & V_15 -> V_17 . V_103 ) ;
F_38 ( & V_15 -> V_17 ) ;
}
if ( V_114 && F_39 ( V_114 ) )
F_40 ( V_114 ) ;
}
static struct V_116 * F_82 ( struct V_116 * V_117 )
{
struct V_14 * V_15 = F_7 ( V_117 , struct V_14 , V_17 ) ;
struct V_164 V_165 ;
struct V_150 * sin = (struct V_150 * ) & V_165 ;
struct V_118 * V_119 = V_15 -> V_17 . V_120 ;
struct V_1 * V_2 = V_15 -> V_65 ;
struct V_1 * V_166 ;
struct V_14 * V_167 ;
int V_130 , V_58 ;
F_18 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_8 ( L_23 , V_15 , V_2 ) ;
if ( ! V_2 )
return NULL ;
F_25 ( V_162 , & V_15 -> V_17 . V_103 ) ;
V_130 = F_83 ( V_2 , & V_166 , V_168 ) ;
if ( V_130 < 0 ) {
if ( V_130 == - V_169 )
F_78 ( V_170 L_24 ,
V_119 -> V_171 ) ;
else if ( V_130 != - V_134 )
F_57 ( L_25 ,
V_119 -> V_171 , - V_130 ) ;
return NULL ;
}
F_27 ( V_162 , & V_15 -> V_17 . V_103 ) ;
V_130 = F_84 ( V_166 , sin , & V_58 ) ;
if ( V_130 < 0 ) {
F_57 ( L_26 ,
V_119 -> V_171 , - V_130 ) ;
goto V_172;
}
if ( ! F_33 ( sin ) ) {
F_8 ( L_27 ,
V_119 -> V_171 ,
F_85 ( sin , V_85 , sizeof( V_85 ) ) ) ;
}
F_8 ( L_28 , V_119 -> V_171 ,
F_85 ( sin , V_85 , sizeof( V_85 ) ) ) ;
V_166 -> V_3 -> V_173 = V_174 * 30 ;
V_167 = F_86 ( V_119 , V_166 ,
( V_175 | V_176 ) ) ;
if ( F_87 ( V_167 ) )
goto V_172;
F_88 ( & V_167 -> V_17 , sin , V_58 ) ;
V_130 = F_89 ( V_166 , sin , & V_58 ) ;
if ( F_90 ( V_130 < 0 ) ) {
F_8 ( L_29 , - V_130 ) ;
V_58 = F_91 ( struct V_150 , V_177 ) ;
}
F_92 ( & V_167 -> V_17 , sin , V_58 ) ;
if ( F_93 ( V_166 -> V_3 ) )
F_27 ( V_178 , & V_167 -> V_17 . V_103 ) ;
else
F_25 ( V_178 , & V_167 -> V_17 . V_103 ) ;
if ( V_119 -> V_145 )
V_119 -> V_145 -> V_179 ++ ;
return & V_167 -> V_17 ;
V_172:
F_94 ( V_166 ) ;
return NULL ;
}
static unsigned int F_95 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
unsigned int V_106 , V_59 , V_180 ;
if ( V_15 -> V_181 == 0 )
return 0 ;
V_59 = V_15 -> V_181 ;
V_180 = ( V_59 + V_63 - 1 ) >> V_182 ;
for ( V_106 = 0 ; V_106 < V_180 ; V_106 ++ ) {
if ( V_10 -> V_143 [ V_106 ] != NULL )
F_96 ( V_10 -> V_143 [ V_106 ] ) ;
F_97 ( V_15 -> V_183 [ V_106 ] == NULL ) ;
V_10 -> V_143 [ V_106 ] = V_15 -> V_183 [ V_106 ] ;
V_15 -> V_183 [ V_106 ] = NULL ;
}
V_10 -> V_139 . V_60 [ 0 ] . V_83 = F_98 ( V_10 -> V_143 [ 0 ] ) ;
return V_59 ;
}
static void F_99 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
unsigned int V_106 , V_59 , V_180 ;
if ( V_15 -> V_181 == 0 )
return;
V_59 = V_15 -> V_181 ;
V_180 = ( V_59 + V_63 - 1 ) >> V_182 ;
for ( V_106 = 0 ; V_106 < V_180 ; V_106 ++ ) {
V_15 -> V_183 [ V_106 ] = V_10 -> V_143 [ V_106 ] ;
V_10 -> V_143 [ V_106 ] = NULL ;
}
}
static void F_100 ( struct V_14 * V_15 )
{
unsigned int V_106 , V_59 , V_180 ;
if ( V_15 -> V_181 == 0 )
goto V_62;
V_59 = V_15 -> V_181 ;
V_180 = ( V_59 + V_63 - 1 ) >> V_182 ;
for ( V_106 = 0 ; V_106 < V_180 ; V_106 ++ ) {
if ( V_15 -> V_183 [ V_106 ] == NULL ) {
F_2 ( 1 ) ;
continue;
}
F_96 ( V_15 -> V_183 [ V_106 ] ) ;
V_15 -> V_183 [ V_106 ] = NULL ;
}
V_62:
V_15 -> V_184 = 0 ;
V_15 -> V_181 = 0 ;
}
static int F_101 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
struct V_118 * V_119 = V_15 -> V_17 . V_120 ;
unsigned int V_185 ;
int V_59 ;
if ( V_15 -> V_184 < sizeof( V_186 ) ) {
struct V_96 V_97 ;
V_185 = sizeof( V_186 ) - V_15 -> V_184 ;
V_97 . V_83 = ( ( char * ) & V_15 -> V_187 ) + V_15 -> V_184 ;
V_97 . V_61 = V_185 ;
if ( ( V_59 = F_24 ( V_10 , & V_97 , 1 , V_185 ) ) < 0 )
goto error;
V_15 -> V_184 += V_59 ;
if ( V_59 < V_185 ) {
F_8 ( L_30
L_31 , V_59 , V_185 ) ;
return - V_134 ;
}
F_8 ( L_32 , F_102 ( V_15 ) ) ;
if ( F_102 ( V_15 ) + V_15 -> V_181 >
V_119 -> V_124 ) {
F_103 ( L_33 ,
F_102 ( V_15 ) ) ;
goto V_188;
}
}
return F_102 ( V_15 ) ;
error:
F_8 ( L_34 , V_59 ) ;
return V_59 ;
V_188:
F_27 ( V_163 , & V_15 -> V_17 . V_103 ) ;
return - V_134 ;
}
static int F_104 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
struct V_189 * V_190 = V_15 -> V_17 . V_191 ;
struct V_192 * V_193 = NULL ;
struct V_96 * V_194 , * V_195 ;
T_3 * V_196 = ( T_3 * ) V_10 -> V_139 . V_60 [ 0 ] . V_83 ;
T_3 V_197 ;
T_3 V_198 ;
V_197 = * V_196 ++ ;
V_198 = * V_196 ;
if ( ! V_190 )
return - V_134 ;
F_105 ( & V_190 -> V_199 ) ;
V_193 = F_106 ( V_190 , V_197 ) ;
if ( ! V_193 )
goto V_200;
memcpy ( & V_193 -> V_201 , & V_193 -> V_202 , sizeof( struct V_41 ) ) ;
V_195 = & V_193 -> V_201 . V_60 [ 0 ] ;
V_194 = & V_10 -> V_139 . V_60 [ 0 ] ;
if ( V_195 -> V_61 < V_194 -> V_61 )
goto V_203;
memcpy ( V_195 -> V_83 , V_194 -> V_83 , V_194 -> V_61 ) ;
F_107 ( V_193 -> V_204 , V_10 -> V_139 . V_59 ) ;
V_10 -> V_139 . V_59 = 0 ;
F_108 ( & V_190 -> V_199 ) ;
return 0 ;
V_200:
F_78 ( V_205
L_35
L_36 ,
V_206 , F_109 ( V_198 ) ,
V_190 , F_109 ( V_197 ) ) ;
V_203:
F_108 ( & V_190 -> V_199 ) ;
return - V_134 ;
}
static int F_110 ( struct V_96 * V_207 , struct V_43 * * V_51 , int V_59 )
{
int V_106 = 0 ;
int V_208 = 0 ;
while ( V_208 < V_59 ) {
V_207 [ V_106 ] . V_83 = F_98 ( V_51 [ V_106 ] ) ;
V_207 [ V_106 ] . V_61 = V_63 ;
V_106 ++ ;
V_208 += V_63 ;
}
return V_106 ;
}
static void F_111 ( struct V_14 * V_15 )
{
F_8 ( L_37 ,
F_112 ( V_15 ) ? L_38 : L_39 ,
F_102 ( V_15 ) ) ;
V_15 -> V_184 = 0 ;
V_15 -> V_187 = 0 ;
}
static int F_113 ( struct V_9 * V_10 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_118 * V_119 = V_15 -> V_17 . V_120 ;
int V_59 ;
struct V_96 * V_207 ;
unsigned int V_185 , V_52 ;
T_3 * V_196 ;
T_3 V_198 ;
int V_209 ;
F_8 ( L_40 ,
V_15 , F_37 ( V_102 , & V_15 -> V_17 . V_103 ) ,
F_37 ( V_162 , & V_15 -> V_17 . V_103 ) ,
F_37 ( V_163 , & V_15 -> V_17 . V_103 ) ) ;
V_59 = F_101 ( V_15 , V_10 ) ;
if ( V_59 < 0 )
goto error;
V_52 = F_95 ( V_15 , V_10 ) ;
V_185 = F_102 ( V_15 ) - ( V_15 -> V_184 - sizeof( V_186 ) ) ;
V_207 = V_10 -> V_210 ;
V_209 = F_110 ( & V_207 [ 0 ] , & V_10 -> V_143 [ 0 ] ,
V_15 -> V_181 + V_185 ) ;
V_10 -> V_84 = & V_10 -> V_143 [ V_209 ] ;
V_10 -> V_144 = V_10 -> V_84 + 1 ;
V_59 = F_28 ( V_10 , V_207 , V_209 , V_185 , V_52 ) ;
if ( V_59 >= 0 ) {
V_15 -> V_184 += V_59 ;
V_15 -> V_181 += V_59 ;
}
if ( V_59 != V_185 || ! F_112 ( V_15 ) ) {
F_99 ( V_15 , V_10 ) ;
if ( V_59 < 0 && V_59 != - V_134 )
goto V_188;
if ( V_59 == V_185 )
F_111 ( V_15 ) ;
else
F_8 ( L_41 ,
( int ) ( V_15 -> V_184 - sizeof( V_186 ) ) ,
F_102 ( V_15 ) ) ;
goto V_211;
}
if ( V_15 -> V_181 < 8 ) {
V_15 -> V_181 = 0 ;
goto V_188;
}
V_10 -> V_139 . V_59 = V_15 -> V_181 ;
V_10 -> V_139 . V_53 = 0 ;
if ( V_10 -> V_139 . V_59 <= V_10 -> V_139 . V_60 [ 0 ] . V_61 ) {
V_10 -> V_139 . V_60 [ 0 ] . V_61 = V_10 -> V_139 . V_59 ;
V_10 -> V_139 . V_55 = 0 ;
} else
V_10 -> V_139 . V_55 = V_10 -> V_139 . V_59 - V_10 -> V_139 . V_60 [ 0 ] . V_61 ;
V_10 -> V_13 = NULL ;
V_10 -> V_72 = V_212 ;
V_10 -> V_213 = ! ! F_37 ( V_178 , & V_15 -> V_17 . V_103 ) ;
V_196 = ( T_3 * ) V_10 -> V_139 . V_60 [ 0 ] . V_83 ;
V_198 = V_196 [ 1 ] ;
if ( V_198 )
V_59 = F_104 ( V_15 , V_10 ) ;
V_15 -> V_181 = 0 ;
F_111 ( V_15 ) ;
if ( V_59 < 0 )
goto error;
F_114 ( V_10 , & V_15 -> V_17 ) ;
if ( V_119 -> V_145 )
V_119 -> V_145 -> V_214 ++ ;
return V_10 -> V_139 . V_59 ;
error:
if ( V_59 != - V_134 )
goto V_188;
F_8 ( L_42 ) ;
return 0 ;
V_188:
F_78 ( V_205 L_43 ,
V_15 -> V_17 . V_120 -> V_171 , - V_59 ) ;
F_27 ( V_163 , & V_15 -> V_17 . V_103 ) ;
V_211:
return 0 ;
}
static int F_115 ( struct V_9 * V_10 )
{
struct V_41 * V_215 = & V_10 -> V_147 ;
int V_216 ;
T_3 V_217 ;
V_217 = F_116 ( 0x80000000 | ( ( V_215 -> V_59 ) - 4 ) ) ;
memcpy ( V_215 -> V_60 [ 0 ] . V_83 , & V_217 , 4 ) ;
V_216 = F_17 ( V_10 , & V_10 -> V_147 ) ;
if ( V_216 != V_215 -> V_59 ) {
F_78 ( V_205
L_44
L_45 ,
V_10 -> V_16 -> V_120 -> V_171 ,
( V_216 < 0 ) ? L_46 : L_47 ,
V_216 , V_215 -> V_59 ) ;
F_27 ( V_163 , & V_10 -> V_16 -> V_103 ) ;
F_38 ( V_10 -> V_16 ) ;
V_216 = - V_134 ;
}
return V_216 ;
}
static void F_117 ( struct V_9 * V_10 )
{
struct V_96 * V_218 = & V_10 -> V_147 . V_60 [ 0 ] ;
F_118 ( V_218 , 0 ) ;
}
static struct V_116 * F_119 ( struct V_118 * V_119 ,
struct V_149 * V_149 ,
struct V_150 * V_151 , int V_152 ,
int V_56 )
{
return F_72 ( V_119 , V_212 , V_149 , V_151 , V_152 , V_56 ) ;
}
static struct V_116 * F_120 ( struct V_118 * V_119 ,
struct V_149 * V_149 ,
struct V_150 * V_151 , int V_152 ,
int V_56 )
{
return F_121 ( V_119 , V_212 , V_149 , V_151 , V_152 , V_56 ) ;
}
static void F_122 ( struct V_116 * V_117 )
{
}
static void F_123 ( void )
{
F_124 ( & V_219 ) ;
}
static void F_125 ( void )
{
F_126 ( & V_219 ) ;
}
static void F_123 ( void )
{
}
static void F_125 ( void )
{
}
void F_127 ( void )
{
F_124 ( & V_220 ) ;
F_124 ( & V_156 ) ;
F_123 () ;
}
void F_128 ( void )
{
F_126 ( & V_220 ) ;
F_126 ( & V_156 ) ;
F_125 () ;
}
static void F_129 ( struct V_14 * V_15 , struct V_118 * V_119 )
{
struct V_2 * V_3 = V_15 -> V_18 ;
F_74 ( F_75 ( V_15 -> V_65 -> V_3 ) , & V_220 ,
& V_15 -> V_17 , V_119 ) ;
F_27 ( V_157 , & V_15 -> V_17 . V_103 ) ;
if ( V_3 -> V_160 == V_161 ) {
F_8 ( L_48 ) ;
F_27 ( V_122 , & V_15 -> V_17 . V_103 ) ;
V_3 -> V_158 = F_77 ;
F_27 ( V_162 , & V_15 -> V_17 . V_103 ) ;
} else {
F_8 ( L_49 ) ;
V_3 -> V_221 = F_80 ;
V_3 -> V_158 = F_81 ;
V_3 -> V_112 = F_46 ;
V_15 -> V_187 = 0 ;
V_15 -> V_184 = 0 ;
V_15 -> V_181 = 0 ;
memset ( & V_15 -> V_183 [ 0 ] , 0 , sizeof( V_15 -> V_183 ) ) ;
F_130 ( V_3 ) -> V_222 |= V_223 ;
F_27 ( V_102 , & V_15 -> V_17 . V_103 ) ;
if ( V_3 -> V_160 != V_224 )
F_27 ( V_163 , & V_15 -> V_17 . V_103 ) ;
}
}
void F_131 ( struct V_118 * V_119 )
{
struct V_14 * V_15 ;
F_105 ( & V_119 -> V_225 ) ;
F_132 (svsk, &serv->sv_permsocks, sk_xprt.xpt_list)
F_27 ( V_131 , & V_15 -> V_17 . V_103 ) ;
F_108 ( & V_119 -> V_225 ) ;
}
static struct V_14 * F_86 ( struct V_118 * V_119 ,
struct V_1 * V_2 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_2 * V_226 ;
int V_227 = ! ( V_56 & V_175 ) ;
int V_130 = 0 ;
F_8 ( L_50 , V_2 ) ;
V_15 = F_133 ( sizeof( * V_15 ) , V_228 ) ;
if ( ! V_15 )
return F_134 ( - V_169 ) ;
V_226 = V_2 -> V_3 ;
if ( V_227 )
V_130 = F_135 ( V_119 , F_75 ( V_2 -> V_3 ) , V_226 -> V_4 ,
V_226 -> V_88 ,
F_136 ( F_22 ( V_226 ) -> V_229 ) ) ;
if ( V_130 < 0 ) {
F_137 ( V_15 ) ;
return F_134 ( V_130 ) ;
}
V_226 -> V_113 = V_15 ;
V_15 -> V_65 = V_2 ;
V_15 -> V_18 = V_226 ;
V_15 -> V_230 = V_226 -> V_221 ;
V_15 -> V_231 = V_226 -> V_158 ;
V_15 -> V_232 = V_226 -> V_112 ;
if ( V_2 -> type == V_233 )
F_73 ( V_15 , V_119 ) ;
else {
F_29 ( V_15 -> V_65 , 4 * V_119 -> V_124 ,
4 * V_119 -> V_124 ) ;
F_129 ( V_15 , V_119 ) ;
}
F_8 ( L_51 ,
V_15 , V_15 -> V_18 ) ;
return V_15 ;
}
bool F_138 ( struct V_149 * V_149 , int V_234 )
{
int V_130 ;
struct V_1 * V_2 = F_139 ( V_234 , & V_130 ) ;
bool V_107 = false ;
if ( ! V_2 )
goto V_62;
if ( F_75 ( V_2 -> V_3 ) != V_149 )
V_107 = true ;
F_140 ( V_2 ) ;
V_62:
return V_107 ;
}
int F_141 ( struct V_118 * V_119 , const int V_234 , char * V_235 ,
const T_1 V_59 )
{
int V_130 = 0 ;
struct V_1 * V_236 = F_139 ( V_234 , & V_130 ) ;
struct V_14 * V_15 = NULL ;
struct V_164 V_165 ;
struct V_150 * sin = (struct V_150 * ) & V_165 ;
int V_152 ;
if ( ! V_236 )
return V_130 ;
V_130 = - V_237 ;
if ( ( V_236 -> V_3 -> V_4 != V_89 ) && ( V_236 -> V_3 -> V_4 != V_93 ) )
goto V_62;
V_130 = - V_238 ;
if ( V_236 -> V_3 -> V_88 != V_212 &&
V_236 -> V_3 -> V_88 != V_73 )
goto V_62;
V_130 = - V_239 ;
if ( V_236 -> V_240 > V_241 )
goto V_62;
V_130 = - V_242 ;
if ( ! F_142 ( V_243 ) )
goto V_62;
V_15 = F_86 ( V_119 , V_236 , V_244 ) ;
if ( F_87 ( V_15 ) ) {
F_143 ( V_243 ) ;
V_130 = F_144 ( V_15 ) ;
goto V_62;
}
if ( F_89 ( V_15 -> V_65 , sin , & V_152 ) == 0 )
F_92 ( & V_15 -> V_17 , sin , V_152 ) ;
F_145 ( V_119 , & V_15 -> V_17 ) ;
return F_21 ( V_15 , V_235 , V_59 ) ;
V_62:
F_140 ( V_236 ) ;
return V_130 ;
}
static struct V_116 * F_72 ( struct V_118 * V_119 ,
int V_245 ,
struct V_149 * V_149 ,
struct V_150 * sin , int V_59 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int error ;
int type ;
struct V_164 V_165 ;
struct V_150 * V_246 = (struct V_150 * ) & V_165 ;
int V_247 ;
int V_248 ;
int V_249 ;
F_18 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_8 ( L_52 ,
V_119 -> V_250 -> V_251 , V_245 ,
F_85 ( sin , V_85 , sizeof( V_85 ) ) ) ;
if ( V_245 != V_73 && V_245 != V_212 ) {
F_78 ( V_170 L_53
L_54 ) ;
return F_134 ( - V_252 ) ;
}
type = ( V_245 == V_73 ) ? V_233 : V_253 ;
switch ( sin -> V_254 ) {
case V_8 :
V_248 = V_93 ;
break;
case V_5 :
V_248 = V_89 ;
break;
default:
return F_134 ( - V_252 ) ;
}
error = F_146 ( V_149 , V_248 , type , V_245 , & V_2 , 1 ) ;
if ( error < 0 )
return F_134 ( error ) ;
F_1 ( V_2 ) ;
V_249 = 1 ;
if ( V_248 == V_93 )
F_76 ( V_2 , V_35 , V_255 ,
( char * ) & V_249 , sizeof( V_249 ) ) ;
if ( type == V_253 )
V_2 -> V_3 -> V_256 = V_257 ;
error = F_147 ( V_2 , sin , V_59 ) ;
if ( error < 0 )
goto V_258;
V_247 = V_59 ;
error = F_89 ( V_2 , V_246 , & V_247 ) ;
if ( error < 0 )
goto V_258;
if ( V_245 == V_212 ) {
if ( ( error = F_148 ( V_2 , 64 ) ) < 0 )
goto V_258;
}
V_15 = F_86 ( V_119 , V_2 , V_56 ) ;
if ( F_87 ( V_15 ) ) {
error = F_144 ( V_15 ) ;
goto V_258;
}
F_92 ( & V_15 -> V_17 , V_246 , V_247 ) ;
return (struct V_116 * ) V_15 ;
V_258:
F_8 ( L_55 , - error ) ;
F_94 ( V_2 ) ;
return F_134 ( error ) ;
}
static void F_149 ( struct V_116 * V_117 )
{
struct V_14 * V_15 = F_7 ( V_117 , struct V_14 , V_17 ) ;
struct V_2 * V_3 = V_15 -> V_18 ;
T_2 * V_114 ;
F_8 ( L_56 , V_15 ) ;
V_3 -> V_221 = V_15 -> V_230 ;
V_3 -> V_158 = V_15 -> V_231 ;
V_3 -> V_112 = V_15 -> V_232 ;
V_114 = F_36 ( V_3 ) ;
if ( V_114 && F_39 ( V_114 ) )
F_40 ( V_114 ) ;
}
static void F_150 ( struct V_116 * V_117 )
{
struct V_14 * V_15 = F_7 ( V_117 , struct V_14 , V_17 ) ;
F_8 ( L_57 , V_15 ) ;
F_149 ( V_117 ) ;
if ( ! F_37 ( V_122 , & V_117 -> V_103 ) ) {
F_100 ( V_15 ) ;
F_151 ( V_15 -> V_65 , V_259 ) ;
}
}
static void F_152 ( struct V_116 * V_117 )
{
struct V_14 * V_15 = F_7 ( V_117 , struct V_14 , V_17 ) ;
F_8 ( L_58 , V_15 ) ;
if ( V_15 -> V_65 -> V_260 )
F_140 ( V_15 -> V_65 ) ;
else
F_94 ( V_15 -> V_65 ) ;
F_137 ( V_15 ) ;
}
static struct V_116 * F_121 ( struct V_118 * V_119 ,
int V_245 ,
struct V_149 * V_149 ,
struct V_150 * sin , int V_59 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_116 * V_117 ;
if ( V_245 != V_212 ) {
F_78 ( V_170 L_59
L_60 ) ;
return F_134 ( - V_252 ) ;
}
V_15 = F_133 ( sizeof( * V_15 ) , V_228 ) ;
if ( ! V_15 )
return F_134 ( - V_169 ) ;
V_117 = & V_15 -> V_17 ;
F_74 ( V_149 , & V_219 , V_117 , V_119 ) ;
V_119 -> V_261 = V_117 ;
return V_117 ;
}
static void F_153 ( struct V_116 * V_117 )
{
if ( V_117 )
F_137 ( F_7 ( V_117 , struct V_14 , V_17 ) ) ;
}
