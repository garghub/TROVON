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
static int F_24 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_65 ;
int V_96 , V_97 ;
V_97 = F_25 ( V_2 , V_98 , ( unsigned long ) & V_96 ) ;
return ( V_97 >= 0 ) ? V_96 : V_97 ;
}
static int F_26 ( struct V_9 * V_10 , struct V_99 * V_100 , int V_101 ,
int V_102 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_74 V_75 = {
. V_82 = V_103 ,
} ;
int V_59 ;
V_10 -> V_104 = 0 ;
V_59 = F_27 ( V_15 -> V_65 , & V_75 , V_100 , V_101 , V_102 ,
V_75 . V_82 ) ;
F_8 ( L_12 ,
V_15 , V_100 [ 0 ] . V_83 , V_100 [ 0 ] . V_61 , V_59 ) ;
return V_59 ;
}
static int F_28 ( struct V_9 * V_10 ,
struct V_99 * V_100 , int V_101 ,
int V_102 , unsigned int V_52 )
{
T_1 V_105 ;
void * V_106 ;
unsigned int V_107 ;
int V_108 ;
if ( V_52 == 0 )
return F_26 ( V_10 , V_100 , V_101 , V_102 ) ;
for ( V_107 = 0 ; V_107 < V_101 ; V_107 ++ ) {
if ( V_100 [ V_107 ] . V_61 > V_52 )
break;
V_52 -= V_100 [ V_107 ] . V_61 ;
}
V_105 = V_100 [ V_107 ] . V_61 ;
V_106 = V_100 [ V_107 ] . V_83 ;
V_100 [ V_107 ] . V_61 -= V_52 ;
V_100 [ V_107 ] . V_83 += V_52 ;
V_108 = F_26 ( V_10 , & V_100 [ V_107 ] , V_101 - V_107 , V_102 ) ;
V_100 [ V_107 ] . V_61 = V_105 ;
V_100 [ V_107 ] . V_83 = V_106 ;
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
T_2 * V_115 = F_36 ( V_3 ) ;
if ( V_15 ) {
F_8 ( L_13 ,
V_15 , V_3 ,
F_37 ( V_116 , & V_15 -> V_17 . V_117 ) ) ;
F_38 ( V_118 , & V_15 -> V_17 . V_117 ) ;
F_39 ( & V_15 -> V_17 ) ;
}
if ( V_115 && F_40 ( V_115 ) )
F_41 ( V_115 ) ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) ( V_3 -> V_114 ) ;
T_2 * V_115 = F_36 ( V_3 ) ;
if ( V_15 ) {
F_8 ( L_14 ,
V_15 , V_3 , F_37 ( V_116 , & V_15 -> V_17 . V_117 ) ) ;
F_39 ( & V_15 -> V_17 ) ;
}
if ( V_115 && F_40 ( V_115 ) ) {
F_8 ( L_15 ,
V_15 ) ;
F_41 ( V_115 ) ;
}
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_119 ;
if ( F_44 ( V_3 ) && V_2 )
F_45 ( V_120 , & V_2 -> V_56 ) ;
F_42 ( V_3 ) ;
}
static int F_46 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = F_11 ( V_20 ) ;
struct V_121 * V_34 = F_12 ( V_10 ) ;
if ( V_20 -> V_25 != V_26 )
return 0 ;
V_34 -> V_122 = V_5 ;
V_34 -> V_30 . V_29 = V_22 -> V_28 . V_29 ;
return 1 ;
}
static int F_47 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
struct V_32 * V_22 = F_11 ( V_20 ) ;
struct V_33 * V_34 = F_14 ( V_10 ) ;
if ( V_20 -> V_25 != V_36 )
return 0 ;
V_34 -> V_123 = V_8 ;
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
struct V_124 * V_125 = V_15 -> V_17 . V_126 ;
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
. V_82 = V_103 ,
} ;
T_1 V_59 ;
int V_97 ;
if ( F_50 ( V_127 , & V_15 -> V_17 . V_117 ) )
F_29 ( V_15 -> V_65 ,
( V_125 -> V_128 + 3 ) * V_125 -> V_129 ,
( V_125 -> V_128 + 3 ) * V_125 -> V_129 ) ;
F_45 ( V_118 , & V_15 -> V_17 . V_117 ) ;
V_12 = NULL ;
V_97 = F_27 ( V_15 -> V_65 , & V_75 , NULL ,
0 , 0 , V_130 | V_103 ) ;
if ( V_97 >= 0 )
V_12 = F_51 ( V_15 -> V_18 , 0 , 1 , & V_97 ) ;
if ( V_12 == NULL ) {
if ( V_97 != - V_131 ) {
F_8 ( L_16 , - V_97 ) ;
F_38 ( V_118 , & V_15 -> V_17 . V_117 ) ;
}
return 0 ;
}
V_59 = F_52 ( F_34 ( V_10 ) ) ;
V_10 -> V_79 = V_59 ;
if ( V_12 -> V_132 . V_133 == 0 ) {
V_12 -> V_132 = F_53 () ;
}
V_15 -> V_18 -> V_134 = V_12 -> V_132 ;
F_38 ( V_118 , & V_15 -> V_17 . V_117 ) ;
V_59 = V_12 -> V_59 - sizeof( struct V_135 ) ;
V_10 -> V_136 . V_59 = V_59 ;
V_10 -> V_72 = V_73 ;
if ( ! F_48 ( V_10 , V_20 ) ) {
F_54 ( L_17 ,
V_20 -> V_23 , V_20 -> V_25 ) ;
goto V_137;
}
V_10 -> V_138 = F_52 ( F_55 ( V_10 ) ) ;
if ( F_56 ( V_12 ) ) {
F_57 () ;
if ( F_58 ( & V_10 -> V_136 , V_12 ) ) {
F_59 () ;
goto V_137;
}
F_59 () ;
F_9 ( V_15 -> V_18 , V_12 ) ;
} else {
V_10 -> V_136 . V_60 [ 0 ] . V_83 = V_12 -> V_139 +
sizeof( struct V_135 ) ;
V_10 -> V_136 . V_60 [ 0 ] . V_61 = V_59 ;
if ( F_60 ( V_12 ) )
goto V_137;
V_10 -> V_13 = V_12 ;
}
V_10 -> V_136 . V_53 = 0 ;
if ( V_59 <= V_10 -> V_136 . V_60 [ 0 ] . V_61 ) {
V_10 -> V_136 . V_60 [ 0 ] . V_61 = V_59 ;
V_10 -> V_136 . V_55 = 0 ;
V_10 -> V_84 = V_10 -> V_140 + 1 ;
} else {
V_10 -> V_136 . V_55 = V_59 - V_10 -> V_136 . V_60 [ 0 ] . V_61 ;
V_10 -> V_84 = V_10 -> V_140 + 1 +
F_61 ( V_10 -> V_136 . V_55 , V_63 ) ;
}
V_10 -> V_141 = V_10 -> V_84 + 1 ;
if ( V_125 -> V_142 )
V_125 -> V_142 -> V_143 ++ ;
return V_59 ;
V_137:
F_62 ( V_12 , F_49 ) ;
F_9 ( V_15 -> V_18 , V_12 ) ;
return 0 ;
}
static int
F_63 ( struct V_9 * V_10 )
{
int error ;
error = F_17 ( V_10 , & V_10 -> V_144 ) ;
if ( error == - V_145 )
error = F_17 ( V_10 , & V_10 -> V_144 ) ;
return error ;
}
static void F_64 ( struct V_9 * V_10 )
{
}
static int F_65 ( struct V_146 * V_147 )
{
struct V_14 * V_15 = F_7 ( V_147 , struct V_14 , V_17 ) ;
struct V_124 * V_125 = V_147 -> V_126 ;
unsigned long V_148 ;
F_38 ( V_120 , & V_15 -> V_65 -> V_56 ) ;
V_148 = F_66 ( & V_15 -> V_17 . V_149 ) + V_125 -> V_129 ;
if ( V_148 * 2 > F_67 ( V_15 -> V_18 ) )
return 0 ;
F_45 ( V_120 , & V_15 -> V_65 -> V_56 ) ;
return 1 ;
}
static struct V_146 * F_68 ( struct V_146 * V_147 )
{
F_5 () ;
return NULL ;
}
static struct V_146 * F_69 ( struct V_124 * V_125 ,
struct V_150 * V_150 ,
struct V_151 * V_152 , int V_153 ,
int V_56 )
{
return F_70 ( V_125 , V_73 , V_150 , V_152 , V_153 , V_56 ) ;
}
static void F_71 ( struct V_14 * V_15 , struct V_124 * V_125 )
{
int V_97 , V_154 , V_155 , V_156 = 1 ;
F_72 ( F_73 ( V_15 -> V_65 -> V_3 ) , & V_157 ,
& V_15 -> V_17 , V_125 ) ;
F_45 ( V_158 , & V_15 -> V_17 . V_117 ) ;
V_15 -> V_18 -> V_159 = F_35 ;
V_15 -> V_18 -> V_113 = F_42 ;
F_29 ( V_15 -> V_65 ,
3 * V_15 -> V_17 . V_126 -> V_129 ,
3 * V_15 -> V_17 . V_126 -> V_129 ) ;
F_38 ( V_118 , & V_15 -> V_17 . V_117 ) ;
F_38 ( V_127 , & V_15 -> V_17 . V_117 ) ;
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
V_97 = F_74 ( V_15 -> V_65 , V_154 , V_155 ,
( char * ) & V_156 , sizeof( V_156 ) ) ;
F_8 ( L_18 , V_97 ) ;
}
static void F_75 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_114 ;
T_2 * V_115 ;
F_8 ( L_19 ,
V_3 , V_3 -> V_161 ) ;
if ( V_3 -> V_161 == V_162 ) {
if ( V_15 ) {
F_38 ( V_163 , & V_15 -> V_17 . V_117 ) ;
F_39 ( & V_15 -> V_17 ) ;
} else
F_76 ( L_20 , V_3 ) ;
}
V_115 = F_36 ( V_3 ) ;
if ( V_115 && F_40 ( V_115 ) )
F_77 ( V_115 ) ;
}
static void F_78 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_114 ;
T_2 * V_115 = F_36 ( V_3 ) ;
F_8 ( L_21 ,
V_3 , V_3 -> V_161 , V_3 -> V_114 ) ;
if ( ! V_15 )
F_76 ( L_20 , V_3 ) ;
else {
F_38 ( V_164 , & V_15 -> V_17 . V_117 ) ;
F_39 ( & V_15 -> V_17 ) ;
}
if ( V_115 && F_40 ( V_115 ) )
F_77 ( V_115 ) ;
}
static void F_79 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_114 ;
T_2 * V_115 = F_36 ( V_3 ) ;
F_8 ( L_22 ,
V_3 , V_3 -> V_114 ) ;
if ( V_15 ) {
F_38 ( V_118 , & V_15 -> V_17 . V_117 ) ;
F_39 ( & V_15 -> V_17 ) ;
}
if ( V_115 && F_40 ( V_115 ) )
F_41 ( V_115 ) ;
}
static struct V_146 * F_80 ( struct V_146 * V_147 )
{
struct V_14 * V_15 = F_7 ( V_147 , struct V_14 , V_17 ) ;
struct V_165 V_166 ;
struct V_151 * sin = (struct V_151 * ) & V_166 ;
struct V_124 * V_125 = V_15 -> V_17 . V_126 ;
struct V_1 * V_2 = V_15 -> V_65 ;
struct V_1 * V_167 ;
struct V_14 * V_168 ;
int V_97 , V_58 ;
F_18 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_8 ( L_23 , V_15 , V_2 ) ;
if ( ! V_2 )
return NULL ;
F_45 ( V_163 , & V_15 -> V_17 . V_117 ) ;
V_97 = F_81 ( V_2 , & V_167 , V_169 ) ;
if ( V_97 < 0 ) {
if ( V_97 == - V_170 )
F_76 ( V_171 L_24 ,
V_125 -> V_172 ) ;
else if ( V_97 != - V_131 )
F_54 ( L_25 ,
V_125 -> V_172 , - V_97 ) ;
return NULL ;
}
F_38 ( V_163 , & V_15 -> V_17 . V_117 ) ;
V_97 = F_82 ( V_167 , sin , & V_58 ) ;
if ( V_97 < 0 ) {
F_54 ( L_26 ,
V_125 -> V_172 , - V_97 ) ;
goto V_173;
}
if ( ! F_33 ( sin ) ) {
F_8 ( L_27 ,
V_125 -> V_172 ,
F_83 ( sin , V_85 , sizeof( V_85 ) ) ) ;
}
F_8 ( L_28 , V_125 -> V_172 ,
F_83 ( sin , V_85 , sizeof( V_85 ) ) ) ;
V_167 -> V_3 -> V_174 = V_175 * 30 ;
V_168 = F_84 ( V_125 , V_167 ,
( V_176 | V_177 ) ) ;
if ( F_85 ( V_168 ) )
goto V_173;
F_86 ( & V_168 -> V_17 , sin , V_58 ) ;
V_97 = F_87 ( V_167 , sin , & V_58 ) ;
if ( F_88 ( V_97 < 0 ) ) {
F_8 ( L_29 , - V_97 ) ;
V_58 = F_89 ( struct V_151 , V_178 ) ;
}
F_90 ( & V_168 -> V_17 , sin , V_58 ) ;
if ( F_91 ( V_167 -> V_3 ) )
F_38 ( V_179 , & V_168 -> V_17 . V_117 ) ;
else
F_45 ( V_179 , & V_168 -> V_17 . V_117 ) ;
if ( V_125 -> V_142 )
V_125 -> V_142 -> V_180 ++ ;
return & V_168 -> V_17 ;
V_173:
F_92 ( V_167 ) ;
return NULL ;
}
static unsigned int F_93 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
unsigned int V_107 , V_59 , V_181 ;
if ( V_15 -> V_182 == 0 )
return 0 ;
V_59 = V_15 -> V_182 ;
V_181 = ( V_59 + V_63 - 1 ) >> V_183 ;
for ( V_107 = 0 ; V_107 < V_181 ; V_107 ++ ) {
if ( V_10 -> V_140 [ V_107 ] != NULL )
F_94 ( V_10 -> V_140 [ V_107 ] ) ;
F_95 ( V_15 -> V_184 [ V_107 ] == NULL ) ;
V_10 -> V_140 [ V_107 ] = V_15 -> V_184 [ V_107 ] ;
V_15 -> V_184 [ V_107 ] = NULL ;
}
V_10 -> V_136 . V_60 [ 0 ] . V_83 = F_96 ( V_10 -> V_140 [ 0 ] ) ;
return V_59 ;
}
static void F_97 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
unsigned int V_107 , V_59 , V_181 ;
if ( V_15 -> V_182 == 0 )
return;
V_59 = V_15 -> V_182 ;
V_181 = ( V_59 + V_63 - 1 ) >> V_183 ;
for ( V_107 = 0 ; V_107 < V_181 ; V_107 ++ ) {
V_15 -> V_184 [ V_107 ] = V_10 -> V_140 [ V_107 ] ;
V_10 -> V_140 [ V_107 ] = NULL ;
}
}
static void F_98 ( struct V_14 * V_15 )
{
unsigned int V_107 , V_59 , V_181 ;
if ( V_15 -> V_182 == 0 )
goto V_62;
V_59 = V_15 -> V_182 ;
V_181 = ( V_59 + V_63 - 1 ) >> V_183 ;
for ( V_107 = 0 ; V_107 < V_181 ; V_107 ++ ) {
if ( V_15 -> V_184 [ V_107 ] == NULL ) {
F_2 ( 1 ) ;
continue;
}
F_94 ( V_15 -> V_184 [ V_107 ] ) ;
V_15 -> V_184 [ V_107 ] = NULL ;
}
V_62:
V_15 -> V_185 = 0 ;
V_15 -> V_182 = 0 ;
}
static int F_99 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
struct V_124 * V_125 = V_15 -> V_17 . V_126 ;
unsigned int V_186 ;
int V_59 ;
F_45 ( V_118 , & V_15 -> V_17 . V_117 ) ;
if ( V_15 -> V_185 < sizeof( V_187 ) ) {
struct V_99 V_100 ;
V_186 = sizeof( V_187 ) - V_15 -> V_185 ;
V_100 . V_83 = ( ( char * ) & V_15 -> V_188 ) + V_15 -> V_185 ;
V_100 . V_61 = V_186 ;
if ( ( V_59 = F_26 ( V_10 , & V_100 , 1 , V_186 ) ) < 0 )
goto error;
V_15 -> V_185 += V_59 ;
if ( V_59 < V_186 ) {
F_8 ( L_30
L_31 , V_59 , V_186 ) ;
return - V_131 ;
}
F_8 ( L_32 , F_100 ( V_15 ) ) ;
if ( F_100 ( V_15 ) + V_15 -> V_182 >
V_125 -> V_129 ) {
F_101 ( L_33 ,
F_100 ( V_15 ) ) ;
goto V_189;
}
}
return F_100 ( V_15 ) ;
error:
F_8 ( L_34 , V_59 ) ;
return V_59 ;
V_189:
F_38 ( V_164 , & V_15 -> V_17 . V_117 ) ;
return - V_131 ;
}
static int F_102 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
struct V_190 * V_191 = V_15 -> V_17 . V_192 ;
struct V_193 * V_194 = NULL ;
struct V_99 * V_195 , * V_196 ;
T_3 * V_197 = ( T_3 * ) V_10 -> V_136 . V_60 [ 0 ] . V_83 ;
T_3 V_198 ;
T_3 V_199 ;
V_198 = * V_197 ++ ;
V_199 = * V_197 ;
if ( V_191 )
V_194 = F_103 ( V_191 , V_198 ) ;
if ( ! V_194 ) {
F_76 ( V_200
L_35
L_36 ,
V_201 , F_104 ( V_199 ) ,
V_191 , V_198 ) ;
return - V_131 ;
}
memcpy ( & V_194 -> V_202 , & V_194 -> V_203 , sizeof( struct V_41 ) ) ;
V_196 = & V_194 -> V_202 . V_60 [ 0 ] ;
V_195 = & V_10 -> V_136 . V_60 [ 0 ] ;
if ( V_196 -> V_61 < V_195 -> V_61 )
return - V_131 ;
memcpy ( V_196 -> V_83 , V_195 -> V_83 , V_195 -> V_61 ) ;
F_105 ( V_194 -> V_204 , V_10 -> V_136 . V_59 ) ;
V_10 -> V_136 . V_59 = 0 ;
return 0 ;
}
static int F_106 ( struct V_99 * V_205 , struct V_43 * * V_51 , int V_59 )
{
int V_107 = 0 ;
int V_206 = 0 ;
while ( V_206 < V_59 ) {
V_205 [ V_107 ] . V_83 = F_96 ( V_51 [ V_107 ] ) ;
V_205 [ V_107 ] . V_61 = V_63 ;
V_107 ++ ;
V_206 += V_63 ;
}
return V_107 ;
}
static void F_107 ( struct V_14 * V_15 )
{
if ( F_24 ( V_15 ) > sizeof( V_187 ) )
F_38 ( V_118 , & V_15 -> V_17 . V_117 ) ;
F_8 ( L_37 ,
F_108 ( V_15 ) ? L_38 : L_39 ,
F_100 ( V_15 ) ) ;
V_15 -> V_185 = 0 ;
V_15 -> V_188 = 0 ;
}
static int F_109 ( struct V_9 * V_10 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_124 * V_125 = V_15 -> V_17 . V_126 ;
int V_59 ;
struct V_99 * V_205 ;
unsigned int V_186 , V_52 ;
T_3 * V_197 ;
T_3 V_199 ;
int V_207 ;
F_8 ( L_40 ,
V_15 , F_37 ( V_118 , & V_15 -> V_17 . V_117 ) ,
F_37 ( V_163 , & V_15 -> V_17 . V_117 ) ,
F_37 ( V_164 , & V_15 -> V_17 . V_117 ) ) ;
V_59 = F_99 ( V_15 , V_10 ) ;
if ( V_59 < 0 )
goto error;
V_52 = F_93 ( V_15 , V_10 ) ;
V_186 = F_100 ( V_15 ) - ( V_15 -> V_185 - sizeof( V_187 ) ) ;
V_205 = V_10 -> V_208 ;
V_207 = F_106 ( & V_205 [ 0 ] , & V_10 -> V_140 [ 0 ] ,
V_15 -> V_182 + V_186 ) ;
V_10 -> V_84 = & V_10 -> V_140 [ V_207 ] ;
V_10 -> V_141 = V_10 -> V_84 + 1 ;
V_59 = F_28 ( V_10 , V_205 , V_207 , V_186 , V_52 ) ;
if ( V_59 >= 0 ) {
V_15 -> V_185 += V_59 ;
V_15 -> V_182 += V_59 ;
}
if ( V_59 != V_186 || ! F_108 ( V_15 ) ) {
F_97 ( V_15 , V_10 ) ;
if ( V_59 < 0 && V_59 != - V_131 )
goto V_189;
if ( V_59 == V_186 )
F_107 ( V_15 ) ;
else
F_8 ( L_41 ,
( int ) ( V_15 -> V_185 - sizeof( V_187 ) ) ,
F_100 ( V_15 ) ) ;
goto V_209;
}
if ( V_15 -> V_182 < 8 ) {
V_15 -> V_182 = 0 ;
goto V_189;
}
V_10 -> V_136 . V_59 = V_15 -> V_182 ;
V_10 -> V_136 . V_53 = 0 ;
if ( V_10 -> V_136 . V_59 <= V_10 -> V_136 . V_60 [ 0 ] . V_61 ) {
V_10 -> V_136 . V_60 [ 0 ] . V_61 = V_10 -> V_136 . V_59 ;
V_10 -> V_136 . V_55 = 0 ;
} else
V_10 -> V_136 . V_55 = V_10 -> V_136 . V_59 - V_10 -> V_136 . V_60 [ 0 ] . V_61 ;
V_10 -> V_13 = NULL ;
V_10 -> V_72 = V_210 ;
V_10 -> V_211 = ! ! F_37 ( V_179 , & V_15 -> V_17 . V_117 ) ;
V_197 = ( T_3 * ) V_10 -> V_136 . V_60 [ 0 ] . V_83 ;
V_199 = V_197 [ 1 ] ;
if ( V_199 )
V_59 = F_102 ( V_15 , V_10 ) ;
V_15 -> V_182 = 0 ;
F_107 ( V_15 ) ;
if ( V_59 < 0 )
goto error;
F_110 ( V_10 , & V_15 -> V_17 ) ;
if ( V_125 -> V_142 )
V_125 -> V_142 -> V_212 ++ ;
return V_10 -> V_136 . V_59 ;
error:
if ( V_59 != - V_131 )
goto V_189;
F_8 ( L_42 ) ;
return 0 ;
V_189:
F_76 ( V_200 L_43 ,
V_15 -> V_17 . V_126 -> V_172 , - V_59 ) ;
F_38 ( V_164 , & V_15 -> V_17 . V_117 ) ;
V_209:
return 0 ;
}
static int F_111 ( struct V_9 * V_10 )
{
struct V_41 * V_213 = & V_10 -> V_144 ;
int V_214 ;
T_3 V_215 ;
V_215 = F_112 ( 0x80000000 | ( ( V_213 -> V_59 ) - 4 ) ) ;
memcpy ( V_213 -> V_60 [ 0 ] . V_83 , & V_215 , 4 ) ;
V_214 = F_17 ( V_10 , & V_10 -> V_144 ) ;
if ( V_214 != V_213 -> V_59 ) {
F_76 ( V_200
L_44
L_45 ,
V_10 -> V_16 -> V_126 -> V_172 ,
( V_214 < 0 ) ? L_46 : L_47 ,
V_214 , V_213 -> V_59 ) ;
F_38 ( V_164 , & V_10 -> V_16 -> V_117 ) ;
F_39 ( V_10 -> V_16 ) ;
V_214 = - V_131 ;
}
return V_214 ;
}
static void F_113 ( struct V_9 * V_10 )
{
struct V_99 * V_216 = & V_10 -> V_144 . V_60 [ 0 ] ;
F_114 ( V_216 , 0 ) ;
}
static int F_115 ( struct V_146 * V_147 )
{
struct V_14 * V_15 = F_7 ( V_147 , struct V_14 , V_17 ) ;
struct V_124 * V_125 = V_15 -> V_17 . V_126 ;
int V_148 ;
if ( F_37 ( V_217 , & V_147 -> V_117 ) )
return 1 ;
V_148 = F_66 ( & V_147 -> V_149 ) + V_125 -> V_129 ;
if ( F_116 ( V_15 -> V_18 ) >= V_148 ||
( F_117 ( V_15 -> V_18 ) == 0 &&
F_66 ( & V_147 -> V_149 ) == 0 ) )
return 1 ;
F_38 ( V_120 , & V_15 -> V_65 -> V_56 ) ;
return 0 ;
}
static struct V_146 * F_118 ( struct V_124 * V_125 ,
struct V_150 * V_150 ,
struct V_151 * V_152 , int V_153 ,
int V_56 )
{
return F_70 ( V_125 , V_210 , V_150 , V_152 , V_153 , V_56 ) ;
}
static struct V_146 * F_119 ( struct V_124 * V_125 ,
struct V_150 * V_150 ,
struct V_151 * V_152 , int V_153 ,
int V_56 )
{
return F_120 ( V_125 , V_210 , V_150 , V_152 , V_153 , V_56 ) ;
}
static void F_121 ( struct V_146 * V_147 )
{
}
static void F_122 ( void )
{
F_123 ( & V_218 ) ;
}
static void F_124 ( void )
{
F_125 ( & V_218 ) ;
}
static void F_122 ( void )
{
}
static void F_124 ( void )
{
}
void F_126 ( void )
{
F_123 ( & V_219 ) ;
F_123 ( & V_157 ) ;
F_122 () ;
}
void F_127 ( void )
{
F_125 ( & V_219 ) ;
F_125 ( & V_157 ) ;
F_124 () ;
}
static void F_128 ( struct V_14 * V_15 , struct V_124 * V_125 )
{
struct V_2 * V_3 = V_15 -> V_18 ;
F_72 ( F_73 ( V_15 -> V_65 -> V_3 ) , & V_219 ,
& V_15 -> V_17 , V_125 ) ;
F_38 ( V_158 , & V_15 -> V_17 . V_117 ) ;
if ( V_3 -> V_161 == V_162 ) {
F_8 ( L_48 ) ;
F_38 ( V_217 , & V_15 -> V_17 . V_117 ) ;
V_3 -> V_159 = F_75 ;
F_38 ( V_163 , & V_15 -> V_17 . V_117 ) ;
} else {
F_8 ( L_49 ) ;
V_3 -> V_220 = F_78 ;
V_3 -> V_159 = F_79 ;
V_3 -> V_113 = F_43 ;
V_15 -> V_188 = 0 ;
V_15 -> V_185 = 0 ;
V_15 -> V_182 = 0 ;
memset ( & V_15 -> V_184 [ 0 ] , 0 , sizeof( V_15 -> V_184 ) ) ;
F_129 ( V_3 ) -> V_221 |= V_222 ;
F_38 ( V_118 , & V_15 -> V_17 . V_117 ) ;
if ( V_3 -> V_161 != V_223 )
F_38 ( V_164 , & V_15 -> V_17 . V_117 ) ;
}
}
void F_130 ( struct V_124 * V_125 )
{
struct V_14 * V_15 ;
F_131 ( & V_125 -> V_224 ) ;
F_132 (svsk, &serv->sv_permsocks, sk_xprt.xpt_list)
F_38 ( V_127 , & V_15 -> V_17 . V_117 ) ;
F_133 ( & V_125 -> V_224 ) ;
}
static struct V_14 * F_84 ( struct V_124 * V_125 ,
struct V_1 * V_2 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_2 * V_225 ;
int V_226 = ! ( V_56 & V_176 ) ;
int V_97 = 0 ;
F_8 ( L_50 , V_2 ) ;
V_15 = F_134 ( sizeof( * V_15 ) , V_227 ) ;
if ( ! V_15 )
return F_135 ( - V_170 ) ;
V_225 = V_2 -> V_3 ;
if ( V_226 )
V_97 = F_136 ( V_125 , F_73 ( V_2 -> V_3 ) , V_225 -> V_4 ,
V_225 -> V_88 ,
F_137 ( F_22 ( V_225 ) -> V_228 ) ) ;
if ( V_97 < 0 ) {
F_138 ( V_15 ) ;
return F_135 ( V_97 ) ;
}
V_225 -> V_114 = V_15 ;
V_15 -> V_65 = V_2 ;
V_15 -> V_18 = V_225 ;
V_15 -> V_229 = V_225 -> V_220 ;
V_15 -> V_230 = V_225 -> V_159 ;
V_15 -> V_231 = V_225 -> V_113 ;
if ( V_2 -> type == V_232 )
F_71 ( V_15 , V_125 ) ;
else {
F_29 ( V_15 -> V_65 , 4 * V_125 -> V_129 ,
4 * V_125 -> V_129 ) ;
F_128 ( V_15 , V_125 ) ;
}
F_8 ( L_51 ,
V_15 , V_15 -> V_18 ) ;
return V_15 ;
}
bool F_139 ( struct V_150 * V_150 , int V_233 )
{
int V_97 ;
struct V_1 * V_2 = F_140 ( V_233 , & V_97 ) ;
bool V_108 = false ;
if ( ! V_2 )
goto V_62;
if ( F_73 ( V_2 -> V_3 ) != V_150 )
V_108 = true ;
F_141 ( V_2 ) ;
V_62:
return V_108 ;
}
int F_142 ( struct V_124 * V_125 , const int V_233 , char * V_234 ,
const T_1 V_59 )
{
int V_97 = 0 ;
struct V_1 * V_235 = F_140 ( V_233 , & V_97 ) ;
struct V_14 * V_15 = NULL ;
struct V_165 V_166 ;
struct V_151 * sin = (struct V_151 * ) & V_166 ;
int V_153 ;
if ( ! V_235 )
return V_97 ;
V_97 = - V_236 ;
if ( ( V_235 -> V_3 -> V_4 != V_89 ) && ( V_235 -> V_3 -> V_4 != V_93 ) )
goto V_62;
V_97 = - V_237 ;
if ( V_235 -> V_3 -> V_88 != V_210 &&
V_235 -> V_3 -> V_88 != V_73 )
goto V_62;
V_97 = - V_238 ;
if ( V_235 -> V_239 > V_240 )
goto V_62;
V_97 = - V_241 ;
if ( ! F_143 ( V_242 ) )
goto V_62;
V_15 = F_84 ( V_125 , V_235 , V_243 ) ;
if ( F_85 ( V_15 ) ) {
F_144 ( V_242 ) ;
V_97 = F_145 ( V_15 ) ;
goto V_62;
}
if ( F_87 ( V_15 -> V_65 , sin , & V_153 ) == 0 )
F_90 ( & V_15 -> V_17 , sin , V_153 ) ;
F_146 ( V_125 , & V_15 -> V_17 ) ;
return F_21 ( V_15 , V_234 , V_59 ) ;
V_62:
F_141 ( V_235 ) ;
return V_97 ;
}
static struct V_146 * F_70 ( struct V_124 * V_125 ,
int V_244 ,
struct V_150 * V_150 ,
struct V_151 * sin , int V_59 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int error ;
int type ;
struct V_165 V_166 ;
struct V_151 * V_245 = (struct V_151 * ) & V_166 ;
int V_246 ;
int V_247 ;
int V_248 ;
F_18 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_8 ( L_52 ,
V_125 -> V_249 -> V_250 , V_244 ,
F_83 ( sin , V_85 , sizeof( V_85 ) ) ) ;
if ( V_244 != V_73 && V_244 != V_210 ) {
F_76 ( V_171 L_53
L_54 ) ;
return F_135 ( - V_251 ) ;
}
type = ( V_244 == V_73 ) ? V_232 : V_252 ;
switch ( sin -> V_253 ) {
case V_8 :
V_247 = V_93 ;
break;
case V_5 :
V_247 = V_89 ;
break;
default:
return F_135 ( - V_251 ) ;
}
error = F_147 ( V_150 , V_247 , type , V_244 , & V_2 , 1 ) ;
if ( error < 0 )
return F_135 ( error ) ;
F_1 ( V_2 ) ;
V_248 = 1 ;
if ( V_247 == V_93 )
F_74 ( V_2 , V_35 , V_254 ,
( char * ) & V_248 , sizeof( V_248 ) ) ;
if ( type == V_252 )
V_2 -> V_3 -> V_255 = V_256 ;
error = F_148 ( V_2 , sin , V_59 ) ;
if ( error < 0 )
goto V_257;
V_246 = V_59 ;
error = F_87 ( V_2 , V_245 , & V_246 ) ;
if ( error < 0 )
goto V_257;
if ( V_244 == V_210 ) {
if ( ( error = F_149 ( V_2 , 64 ) ) < 0 )
goto V_257;
}
V_15 = F_84 ( V_125 , V_2 , V_56 ) ;
if ( F_85 ( V_15 ) ) {
error = F_145 ( V_15 ) ;
goto V_257;
}
F_90 ( & V_15 -> V_17 , V_245 , V_246 ) ;
return (struct V_146 * ) V_15 ;
V_257:
F_8 ( L_55 , - error ) ;
F_92 ( V_2 ) ;
return F_135 ( error ) ;
}
static void F_150 ( struct V_146 * V_147 )
{
struct V_14 * V_15 = F_7 ( V_147 , struct V_14 , V_17 ) ;
struct V_2 * V_3 = V_15 -> V_18 ;
T_2 * V_115 ;
F_8 ( L_56 , V_15 ) ;
V_3 -> V_220 = V_15 -> V_229 ;
V_3 -> V_159 = V_15 -> V_230 ;
V_3 -> V_113 = V_15 -> V_231 ;
V_115 = F_36 ( V_3 ) ;
if ( V_115 && F_40 ( V_115 ) )
F_41 ( V_115 ) ;
}
static void F_151 ( struct V_146 * V_147 )
{
struct V_14 * V_15 = F_7 ( V_147 , struct V_14 , V_17 ) ;
F_8 ( L_57 , V_15 ) ;
F_150 ( V_147 ) ;
if ( ! F_37 ( V_217 , & V_147 -> V_117 ) ) {
F_98 ( V_15 ) ;
F_152 ( V_15 -> V_65 , V_258 ) ;
}
}
static void F_153 ( struct V_146 * V_147 )
{
struct V_14 * V_15 = F_7 ( V_147 , struct V_14 , V_17 ) ;
F_8 ( L_58 , V_15 ) ;
if ( V_15 -> V_65 -> V_259 )
F_141 ( V_15 -> V_65 ) ;
else
F_92 ( V_15 -> V_65 ) ;
F_138 ( V_15 ) ;
}
static struct V_146 * F_120 ( struct V_124 * V_125 ,
int V_244 ,
struct V_150 * V_150 ,
struct V_151 * sin , int V_59 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_146 * V_147 ;
if ( V_244 != V_210 ) {
F_76 ( V_171 L_59
L_60 ) ;
return F_135 ( - V_251 ) ;
}
V_15 = F_134 ( sizeof( * V_15 ) , V_227 ) ;
if ( ! V_15 )
return F_135 ( - V_170 ) ;
V_147 = & V_15 -> V_17 ;
F_72 ( V_150 , & V_218 , V_147 , V_125 ) ;
V_125 -> V_260 = V_147 ;
return V_147 ;
}
static void F_154 ( struct V_146 * V_147 )
{
if ( V_147 )
F_138 ( F_7 ( V_147 , struct V_14 , V_17 ) ) ;
}
