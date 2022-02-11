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
static int F_24 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_65 ;
int V_95 , V_96 ;
V_96 = F_25 ( V_2 , V_97 , ( unsigned long ) & V_95 ) ;
return ( V_96 >= 0 ) ? V_95 : V_96 ;
}
static int F_26 ( struct V_9 * V_10 , struct V_98 * V_99 , int V_100 ,
int V_101 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_74 V_75 = {
. V_82 = V_102 ,
} ;
int V_59 ;
V_10 -> V_103 = 0 ;
V_59 = F_27 ( V_15 -> V_65 , & V_75 , V_99 , V_100 , V_101 ,
V_75 . V_82 ) ;
F_8 ( L_12 ,
V_15 , V_99 [ 0 ] . V_83 , V_99 [ 0 ] . V_61 , V_59 ) ;
return V_59 ;
}
static int F_28 ( struct V_9 * V_10 ,
struct V_98 * V_99 , int V_100 ,
int V_101 , unsigned int V_52 )
{
T_1 V_104 ;
void * V_105 ;
unsigned int V_106 ;
int V_107 ;
if ( V_52 == 0 )
return F_26 ( V_10 , V_99 , V_100 , V_101 ) ;
for ( V_106 = 0 ; V_106 < V_100 ; V_106 ++ ) {
if ( V_99 [ V_106 ] . V_61 > V_52 )
break;
V_52 -= V_99 [ V_106 ] . V_61 ;
}
V_104 = V_99 [ V_106 ] . V_61 ;
V_105 = V_99 [ V_106 ] . V_83 ;
V_99 [ V_106 ] . V_61 -= V_52 ;
V_99 [ V_106 ] . V_83 += V_52 ;
V_107 = F_26 ( V_10 , & V_99 [ V_106 ] , V_100 - V_106 , V_101 ) ;
V_99 [ V_106 ] . V_61 = V_104 ;
V_99 [ V_106 ] . V_83 = V_105 ;
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
static void F_32 ( struct V_2 * V_3 , int V_113 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_114 ;
T_2 * V_115 = F_33 ( V_3 ) ;
if ( V_15 ) {
F_8 ( L_13 ,
V_15 , V_3 , V_113 ,
F_34 ( V_116 , & V_15 -> V_17 . V_117 ) ) ;
F_35 ( V_118 , & V_15 -> V_17 . V_117 ) ;
F_36 ( & V_15 -> V_17 ) ;
}
if ( V_115 && F_37 ( V_115 ) )
F_38 ( V_115 ) ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) ( V_3 -> V_114 ) ;
T_2 * V_115 = F_33 ( V_3 ) ;
if ( V_15 ) {
F_8 ( L_14 ,
V_15 , V_3 , F_34 ( V_116 , & V_15 -> V_17 . V_117 ) ) ;
F_36 ( & V_15 -> V_17 ) ;
}
if ( V_115 && F_37 ( V_115 ) ) {
F_8 ( L_15 ,
V_15 ) ;
F_38 ( V_115 ) ;
}
}
static void F_40 ( struct V_2 * V_3 )
{
struct V_1 * V_2 = V_3 -> V_119 ;
if ( F_41 ( V_3 ) >= F_42 ( V_3 ) && V_2 )
F_43 ( V_120 , & V_2 -> V_56 ) ;
F_39 ( V_3 ) ;
}
static int F_44 ( struct V_9 * V_10 ,
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
static int F_45 ( struct V_9 * V_10 ,
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
static int F_46 ( struct V_9 * V_10 ,
struct V_19 * V_20 )
{
switch ( V_20 -> V_23 ) {
case V_24 :
return F_44 ( V_10 , V_20 ) ;
case V_35 :
return F_45 ( V_10 , V_20 ) ;
}
return 0 ;
}
static int F_47 ( struct V_9 * V_10 )
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
. V_76 = F_48 ( V_10 ) ,
. V_80 = V_20 ,
. V_81 = sizeof( V_69 ) ,
. V_82 = V_102 ,
} ;
T_1 V_59 ;
int V_96 ;
if ( F_49 ( V_127 , & V_15 -> V_17 . V_117 ) )
F_29 ( V_15 -> V_65 ,
( V_125 -> V_128 + 3 ) * V_125 -> V_129 ,
( V_125 -> V_128 + 3 ) * V_125 -> V_129 ) ;
F_43 ( V_118 , & V_15 -> V_17 . V_117 ) ;
V_12 = NULL ;
V_96 = F_27 ( V_15 -> V_65 , & V_75 , NULL ,
0 , 0 , V_130 | V_102 ) ;
if ( V_96 >= 0 )
V_12 = F_50 ( V_15 -> V_18 , 0 , 1 , & V_96 ) ;
if ( V_12 == NULL ) {
if ( V_96 != - V_131 ) {
F_8 ( L_16 , - V_96 ) ;
F_35 ( V_118 , & V_15 -> V_17 . V_117 ) ;
}
return 0 ;
}
V_59 = F_51 ( F_48 ( V_10 ) ) ;
V_10 -> V_79 = V_59 ;
if ( V_12 -> V_132 . V_133 == 0 ) {
V_12 -> V_132 = F_52 () ;
}
V_15 -> V_18 -> V_134 = V_12 -> V_132 ;
F_35 ( V_118 , & V_15 -> V_17 . V_117 ) ;
V_59 = V_12 -> V_59 - sizeof( struct V_135 ) ;
V_10 -> V_136 . V_59 = V_59 ;
V_10 -> V_72 = V_73 ;
if ( ! F_46 ( V_10 , V_20 ) ) {
F_53 ( L_17 ,
V_20 -> V_23 , V_20 -> V_25 ) ;
goto V_137;
}
V_10 -> V_138 = F_51 ( F_54 ( V_10 ) ) ;
if ( F_55 ( V_12 ) ) {
F_56 () ;
if ( F_57 ( & V_10 -> V_136 , V_12 ) ) {
F_58 () ;
goto V_137;
}
F_58 () ;
F_9 ( V_15 -> V_18 , V_12 ) ;
} else {
V_10 -> V_136 . V_60 [ 0 ] . V_83 = V_12 -> V_139 +
sizeof( struct V_135 ) ;
V_10 -> V_136 . V_60 [ 0 ] . V_61 = V_59 ;
if ( F_59 ( V_12 ) )
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
F_60 ( V_10 -> V_136 . V_55 , V_63 ) ;
}
if ( V_125 -> V_141 )
V_125 -> V_141 -> V_142 ++ ;
return V_59 ;
V_137:
F_61 ( V_12 , F_47 ) ;
F_9 ( V_15 -> V_18 , V_12 ) ;
return 0 ;
}
static int
F_62 ( struct V_9 * V_10 )
{
int error ;
error = F_17 ( V_10 , & V_10 -> V_143 ) ;
if ( error == - V_144 )
error = F_17 ( V_10 , & V_10 -> V_143 ) ;
return error ;
}
static void F_63 ( struct V_9 * V_10 )
{
}
static int F_64 ( struct V_145 * V_146 )
{
struct V_14 * V_15 = F_7 ( V_146 , struct V_14 , V_17 ) ;
struct V_124 * V_125 = V_146 -> V_126 ;
unsigned long V_147 ;
F_35 ( V_120 , & V_15 -> V_65 -> V_56 ) ;
V_147 = F_65 ( & V_15 -> V_17 . V_148 ) + V_125 -> V_129 ;
if ( V_147 * 2 > F_66 ( V_15 -> V_18 ) )
return 0 ;
F_43 ( V_120 , & V_15 -> V_65 -> V_56 ) ;
return 1 ;
}
static struct V_145 * F_67 ( struct V_145 * V_146 )
{
F_5 () ;
return NULL ;
}
static struct V_145 * F_68 ( struct V_124 * V_125 ,
struct V_149 * V_149 ,
struct V_150 * V_151 , int V_152 ,
int V_56 )
{
return F_69 ( V_125 , V_73 , V_149 , V_151 , V_152 , V_56 ) ;
}
static void F_70 ( struct V_14 * V_15 , struct V_124 * V_125 )
{
int V_96 , V_153 , V_154 , V_155 = 1 ;
F_71 ( F_72 ( V_15 -> V_65 -> V_3 ) , & V_156 ,
& V_15 -> V_17 , V_125 ) ;
F_43 ( V_157 , & V_15 -> V_17 . V_117 ) ;
V_15 -> V_18 -> V_158 = F_32 ;
V_15 -> V_18 -> V_112 = F_39 ;
F_29 ( V_15 -> V_65 ,
3 * V_15 -> V_17 . V_126 -> V_129 ,
3 * V_15 -> V_17 . V_126 -> V_129 ) ;
F_35 ( V_118 , & V_15 -> V_17 . V_117 ) ;
F_35 ( V_127 , & V_15 -> V_17 . V_117 ) ;
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
V_96 = F_73 ( V_15 -> V_65 , V_153 , V_154 ,
( char * ) & V_155 , sizeof( V_155 ) ) ;
F_8 ( L_18 , V_96 ) ;
}
static void F_74 ( struct V_2 * V_3 , int V_160 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_114 ;
T_2 * V_115 ;
F_8 ( L_19 ,
V_3 , V_3 -> V_161 ) ;
if ( V_3 -> V_161 == V_162 ) {
if ( V_15 ) {
F_35 ( V_163 , & V_15 -> V_17 . V_117 ) ;
F_36 ( & V_15 -> V_17 ) ;
} else
F_75 ( L_20 , V_3 ) ;
}
V_115 = F_33 ( V_3 ) ;
if ( V_115 && F_37 ( V_115 ) )
F_76 ( V_115 ) ;
}
static void F_77 ( struct V_2 * V_3 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_114 ;
T_2 * V_115 = F_33 ( V_3 ) ;
F_8 ( L_21 ,
V_3 , V_3 -> V_161 , V_3 -> V_114 ) ;
if ( ! V_15 )
F_75 ( L_20 , V_3 ) ;
else {
F_35 ( V_164 , & V_15 -> V_17 . V_117 ) ;
F_36 ( & V_15 -> V_17 ) ;
}
if ( V_115 && F_37 ( V_115 ) )
F_76 ( V_115 ) ;
}
static void F_78 ( struct V_2 * V_3 , int V_113 )
{
struct V_14 * V_15 = (struct V_14 * ) V_3 -> V_114 ;
T_2 * V_115 = F_33 ( V_3 ) ;
F_8 ( L_22 ,
V_3 , V_3 -> V_114 ) ;
if ( V_15 ) {
F_35 ( V_118 , & V_15 -> V_17 . V_117 ) ;
F_36 ( & V_15 -> V_17 ) ;
}
if ( V_115 && F_37 ( V_115 ) )
F_38 ( V_115 ) ;
}
static struct V_145 * F_79 ( struct V_145 * V_146 )
{
struct V_14 * V_15 = F_7 ( V_146 , struct V_14 , V_17 ) ;
struct V_165 V_166 ;
struct V_150 * sin = (struct V_150 * ) & V_166 ;
struct V_124 * V_125 = V_15 -> V_17 . V_126 ;
struct V_1 * V_2 = V_15 -> V_65 ;
struct V_1 * V_167 ;
struct V_14 * V_168 ;
int V_96 , V_58 ;
F_18 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_8 ( L_23 , V_15 , V_2 ) ;
if ( ! V_2 )
return NULL ;
F_43 ( V_163 , & V_15 -> V_17 . V_117 ) ;
V_96 = F_80 ( V_2 , & V_167 , V_169 ) ;
if ( V_96 < 0 ) {
if ( V_96 == - V_170 )
F_75 ( V_171 L_24 ,
V_125 -> V_172 ) ;
else if ( V_96 != - V_131 )
F_53 ( L_25 ,
V_125 -> V_172 , - V_96 ) ;
return NULL ;
}
F_35 ( V_163 , & V_15 -> V_17 . V_117 ) ;
V_96 = F_81 ( V_167 , sin , & V_58 ) ;
if ( V_96 < 0 ) {
F_53 ( L_26 ,
V_125 -> V_172 , - V_96 ) ;
goto V_173;
}
if ( ! F_82 ( sin ) ) {
F_8 ( V_171
L_27 ,
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
V_96 = F_87 ( V_167 , sin , & V_58 ) ;
if ( F_88 ( V_96 < 0 ) ) {
F_8 ( L_29 , - V_96 ) ;
V_58 = F_89 ( struct V_150 , V_178 ) ;
}
F_90 ( & V_168 -> V_17 , sin , V_58 ) ;
if ( V_125 -> V_141 )
V_125 -> V_141 -> V_179 ++ ;
return & V_168 -> V_17 ;
V_173:
F_91 ( V_167 ) ;
return NULL ;
}
static unsigned int F_92 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
unsigned int V_106 , V_59 , V_180 ;
if ( V_15 -> V_181 <= sizeof( V_182 ) )
return 0 ;
V_59 = V_15 -> V_181 - sizeof( V_182 ) ;
V_180 = ( V_59 + V_63 - 1 ) >> V_183 ;
for ( V_106 = 0 ; V_106 < V_180 ; V_106 ++ ) {
if ( V_10 -> V_140 [ V_106 ] != NULL )
F_93 ( V_10 -> V_140 [ V_106 ] ) ;
F_2 ( V_15 -> V_184 [ V_106 ] == NULL ) ;
V_10 -> V_140 [ V_106 ] = V_15 -> V_184 [ V_106 ] ;
V_15 -> V_184 [ V_106 ] = NULL ;
}
V_10 -> V_136 . V_60 [ 0 ] . V_83 = F_94 ( V_10 -> V_140 [ 0 ] ) ;
return V_59 ;
}
static void F_95 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
unsigned int V_106 , V_59 , V_180 ;
if ( V_15 -> V_181 <= sizeof( V_182 ) )
return;
V_59 = V_15 -> V_181 - sizeof( V_182 ) ;
V_180 = ( V_59 + V_63 - 1 ) >> V_183 ;
for ( V_106 = 0 ; V_106 < V_180 ; V_106 ++ ) {
V_15 -> V_184 [ V_106 ] = V_10 -> V_140 [ V_106 ] ;
V_10 -> V_140 [ V_106 ] = NULL ;
}
}
static void F_96 ( struct V_14 * V_15 )
{
unsigned int V_106 , V_59 , V_180 ;
if ( V_15 -> V_181 <= sizeof( V_182 ) )
goto V_62;
V_59 = V_15 -> V_181 - sizeof( V_182 ) ;
V_180 = ( V_59 + V_63 - 1 ) >> V_183 ;
for ( V_106 = 0 ; V_106 < V_180 ; V_106 ++ ) {
F_2 ( V_15 -> V_184 [ V_106 ] == NULL ) ;
F_93 ( V_15 -> V_184 [ V_106 ] ) ;
V_15 -> V_184 [ V_106 ] = NULL ;
}
V_62:
V_15 -> V_181 = 0 ;
}
static int F_97 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
struct V_124 * V_125 = V_15 -> V_17 . V_126 ;
unsigned int V_185 ;
int V_59 ;
F_43 ( V_118 , & V_15 -> V_17 . V_117 ) ;
if ( V_15 -> V_181 < sizeof( V_182 ) ) {
struct V_98 V_99 ;
V_185 = sizeof( V_182 ) - V_15 -> V_181 ;
V_99 . V_83 = ( ( char * ) & V_15 -> V_186 ) + V_15 -> V_181 ;
V_99 . V_61 = V_185 ;
if ( ( V_59 = F_26 ( V_10 , & V_99 , 1 , V_185 ) ) < 0 )
goto error;
V_15 -> V_181 += V_59 ;
if ( V_59 < V_185 ) {
F_8 ( L_30
L_31 , V_59 , V_185 ) ;
return - V_131 ;
}
V_15 -> V_186 = F_98 ( V_15 -> V_186 ) ;
if ( ! ( V_15 -> V_186 & V_187 ) ) {
F_99 ( L_32 ) ;
goto V_188;
}
V_15 -> V_186 &= V_189 ;
F_8 ( L_33 , V_15 -> V_186 ) ;
if ( V_15 -> V_186 > V_125 -> V_129 ) {
F_99 ( L_34 ,
( unsigned long ) V_15 -> V_186 ) ;
goto V_188;
}
}
if ( V_15 -> V_186 < 8 )
goto V_188;
V_59 = V_15 -> V_186 ;
return V_59 ;
error:
F_8 ( L_35 , V_59 ) ;
return V_59 ;
V_188:
F_35 ( V_164 , & V_15 -> V_17 . V_117 ) ;
return - V_131 ;
}
static int F_100 ( struct V_14 * V_15 , struct V_9 * V_10 )
{
struct V_190 * V_191 = V_15 -> V_17 . V_192 ;
struct V_193 * V_194 = NULL ;
struct V_98 * V_195 , * V_196 ;
T_3 * V_197 = ( T_3 * ) V_10 -> V_136 . V_60 [ 0 ] . V_83 ;
T_3 V_198 ;
T_3 V_199 ;
V_198 = * V_197 ++ ;
V_199 = * V_197 ;
if ( V_191 )
V_194 = F_101 ( V_191 , V_198 ) ;
if ( ! V_194 ) {
F_75 ( V_200
L_36
L_37 ,
V_201 , F_98 ( V_199 ) ,
V_191 , V_198 ) ;
return - V_131 ;
}
memcpy ( & V_194 -> V_202 , & V_194 -> V_203 , sizeof( struct V_41 ) ) ;
V_196 = & V_194 -> V_202 . V_60 [ 0 ] ;
V_195 = & V_10 -> V_136 . V_60 [ 0 ] ;
if ( V_196 -> V_61 < V_195 -> V_61 )
return - V_131 ;
memcpy ( V_196 -> V_83 , V_195 -> V_83 , V_195 -> V_61 ) ;
F_102 ( V_194 -> V_204 , V_15 -> V_186 ) ;
V_10 -> V_136 . V_59 = 0 ;
return 0 ;
}
static int F_103 ( struct V_98 * V_205 , struct V_43 * * V_51 , int V_59 )
{
int V_106 = 0 ;
int V_206 = 0 ;
while ( V_206 < V_59 ) {
V_205 [ V_106 ] . V_83 = F_94 ( V_51 [ V_106 ] ) ;
V_205 [ V_106 ] . V_61 = V_63 ;
V_106 ++ ;
V_206 += V_63 ;
}
return V_106 ;
}
static int F_104 ( struct V_9 * V_10 )
{
struct V_14 * V_15 =
F_7 ( V_10 -> V_16 , struct V_14 , V_17 ) ;
struct V_124 * V_125 = V_15 -> V_17 . V_126 ;
int V_59 ;
struct V_98 * V_205 ;
unsigned int V_185 , V_52 ;
T_3 * V_197 ;
T_3 V_199 ;
int V_207 ;
F_8 ( L_38 ,
V_15 , F_34 ( V_118 , & V_15 -> V_17 . V_117 ) ,
F_34 ( V_163 , & V_15 -> V_17 . V_117 ) ,
F_34 ( V_164 , & V_15 -> V_17 . V_117 ) ) ;
V_59 = F_97 ( V_15 , V_10 ) ;
if ( V_59 < 0 )
goto error;
V_52 = F_92 ( V_15 , V_10 ) ;
V_185 = V_15 -> V_186 - V_52 ;
V_205 = V_10 -> V_208 ;
V_207 = F_103 ( & V_205 [ 0 ] , & V_10 -> V_140 [ 0 ] ,
V_15 -> V_186 ) ;
V_10 -> V_84 = & V_10 -> V_140 [ V_207 ] ;
V_59 = F_28 ( V_10 , V_205 , V_207 , V_185 , V_52 ) ;
if ( V_59 >= 0 )
V_15 -> V_181 += V_59 ;
if ( V_59 != V_185 ) {
F_95 ( V_15 , V_10 ) ;
if ( V_59 < 0 && V_59 != - V_131 )
goto V_209;
F_8 ( L_39 ,
V_15 -> V_181 , V_15 -> V_186 ) ;
goto V_210;
}
V_10 -> V_136 . V_59 = V_15 -> V_186 ;
V_10 -> V_136 . V_53 = 0 ;
if ( V_10 -> V_136 . V_59 <= V_10 -> V_136 . V_60 [ 0 ] . V_61 ) {
V_10 -> V_136 . V_60 [ 0 ] . V_61 = V_10 -> V_136 . V_59 ;
V_10 -> V_136 . V_55 = 0 ;
} else
V_10 -> V_136 . V_55 = V_10 -> V_136 . V_59 - V_10 -> V_136 . V_60 [ 0 ] . V_61 ;
V_10 -> V_13 = NULL ;
V_10 -> V_72 = V_211 ;
V_197 = ( T_3 * ) V_10 -> V_136 . V_60 [ 0 ] . V_83 ;
V_199 = V_197 [ 1 ] ;
if ( V_199 )
V_59 = F_100 ( V_15 , V_10 ) ;
V_15 -> V_186 = 0 ;
V_15 -> V_181 = 0 ;
if ( F_24 ( V_15 ) > sizeof( V_182 ) )
F_35 ( V_118 , & V_15 -> V_17 . V_117 ) ;
if ( V_59 < 0 )
goto error;
F_105 ( V_10 , & V_15 -> V_17 ) ;
if ( V_125 -> V_141 )
V_125 -> V_141 -> V_212 ++ ;
F_8 ( L_40 , V_10 -> V_136 . V_59 ) ;
return V_10 -> V_136 . V_59 ;
error:
if ( V_59 != - V_131 )
goto V_209;
F_8 ( L_41 ) ;
return 0 ;
V_209:
F_75 ( V_200 L_42 ,
V_15 -> V_17 . V_126 -> V_172 , - V_59 ) ;
F_35 ( V_164 , & V_15 -> V_17 . V_117 ) ;
V_210:
return 0 ;
}
static int F_106 ( struct V_9 * V_10 )
{
struct V_41 * V_213 = & V_10 -> V_143 ;
int V_214 ;
T_3 V_215 ;
V_215 = F_107 ( 0x80000000 | ( ( V_213 -> V_59 ) - 4 ) ) ;
memcpy ( V_213 -> V_60 [ 0 ] . V_83 , & V_215 , 4 ) ;
V_214 = F_17 ( V_10 , & V_10 -> V_143 ) ;
if ( V_214 != V_213 -> V_59 ) {
F_75 ( V_200
L_43
L_44 ,
V_10 -> V_16 -> V_126 -> V_172 ,
( V_214 < 0 ) ? L_45 : L_46 ,
V_214 , V_213 -> V_59 ) ;
F_35 ( V_164 , & V_10 -> V_16 -> V_117 ) ;
F_36 ( V_10 -> V_16 ) ;
V_214 = - V_131 ;
}
return V_214 ;
}
static void F_108 ( struct V_9 * V_10 )
{
struct V_98 * V_216 = & V_10 -> V_143 . V_60 [ 0 ] ;
F_109 ( V_216 , 0 ) ;
}
static int F_110 ( struct V_145 * V_146 )
{
struct V_14 * V_15 = F_7 ( V_146 , struct V_14 , V_17 ) ;
struct V_124 * V_125 = V_15 -> V_17 . V_126 ;
int V_147 ;
if ( F_34 ( V_217 , & V_146 -> V_117 ) )
return 1 ;
V_147 = F_65 ( & V_146 -> V_148 ) + V_125 -> V_129 ;
if ( F_41 ( V_15 -> V_18 ) >= V_147 )
return 1 ;
F_35 ( V_120 , & V_15 -> V_65 -> V_56 ) ;
return 0 ;
}
static struct V_145 * F_111 ( struct V_124 * V_125 ,
struct V_149 * V_149 ,
struct V_150 * V_151 , int V_152 ,
int V_56 )
{
return F_69 ( V_125 , V_211 , V_149 , V_151 , V_152 , V_56 ) ;
}
static struct V_145 * F_112 ( struct V_124 * V_125 ,
struct V_149 * V_149 ,
struct V_150 * V_151 , int V_152 ,
int V_56 )
{
return F_113 ( V_125 , V_211 , V_149 , V_151 , V_152 , V_56 ) ;
}
static void F_114 ( struct V_145 * V_146 )
{
}
static void F_115 ( void )
{
F_116 ( & V_218 ) ;
}
static void F_117 ( void )
{
F_118 ( & V_218 ) ;
}
static void F_115 ( void )
{
}
static void F_117 ( void )
{
}
void F_119 ( void )
{
F_116 ( & V_219 ) ;
F_116 ( & V_156 ) ;
F_115 () ;
}
void F_120 ( void )
{
F_118 ( & V_219 ) ;
F_118 ( & V_156 ) ;
F_117 () ;
}
static void F_121 ( struct V_14 * V_15 , struct V_124 * V_125 )
{
struct V_2 * V_3 = V_15 -> V_18 ;
F_71 ( F_72 ( V_15 -> V_65 -> V_3 ) , & V_219 ,
& V_15 -> V_17 , V_125 ) ;
F_35 ( V_157 , & V_15 -> V_17 . V_117 ) ;
if ( V_3 -> V_161 == V_162 ) {
F_8 ( L_47 ) ;
F_35 ( V_217 , & V_15 -> V_17 . V_117 ) ;
V_3 -> V_158 = F_74 ;
F_35 ( V_163 , & V_15 -> V_17 . V_117 ) ;
} else {
F_8 ( L_48 ) ;
V_3 -> V_220 = F_77 ;
V_3 -> V_158 = F_78 ;
V_3 -> V_112 = F_40 ;
V_15 -> V_186 = 0 ;
V_15 -> V_181 = 0 ;
memset ( & V_15 -> V_184 [ 0 ] , 0 , sizeof( V_15 -> V_184 ) ) ;
F_122 ( V_3 ) -> V_221 |= V_222 ;
F_35 ( V_118 , & V_15 -> V_17 . V_117 ) ;
if ( V_3 -> V_161 != V_223 )
F_35 ( V_164 , & V_15 -> V_17 . V_117 ) ;
}
}
void F_123 ( struct V_124 * V_125 )
{
struct V_14 * V_15 ;
F_124 ( & V_125 -> V_224 ) ;
F_125 (svsk, &serv->sv_permsocks, sk_xprt.xpt_list)
F_35 ( V_127 , & V_15 -> V_17 . V_117 ) ;
F_126 ( & V_125 -> V_224 ) ;
}
static struct V_14 * F_84 ( struct V_124 * V_125 ,
struct V_1 * V_2 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_2 * V_225 ;
int V_226 = ! ( V_56 & V_176 ) ;
int V_96 = 0 ;
F_8 ( L_49 , V_2 ) ;
V_15 = F_127 ( sizeof( * V_15 ) , V_227 ) ;
if ( ! V_15 )
return F_128 ( - V_170 ) ;
V_225 = V_2 -> V_3 ;
if ( V_226 )
V_96 = F_129 ( V_125 , F_72 ( V_2 -> V_3 ) , V_225 -> V_4 ,
V_225 -> V_88 ,
F_130 ( F_22 ( V_225 ) -> V_228 ) ) ;
if ( V_96 < 0 ) {
F_131 ( V_15 ) ;
return F_128 ( V_96 ) ;
}
V_225 -> V_114 = V_15 ;
V_15 -> V_65 = V_2 ;
V_15 -> V_18 = V_225 ;
V_15 -> V_229 = V_225 -> V_220 ;
V_15 -> V_230 = V_225 -> V_158 ;
V_15 -> V_231 = V_225 -> V_112 ;
if ( V_2 -> type == V_232 )
F_70 ( V_15 , V_125 ) ;
else {
F_29 ( V_15 -> V_65 , 4 * V_125 -> V_129 ,
4 * V_125 -> V_129 ) ;
F_121 ( V_15 , V_125 ) ;
}
F_8 ( L_50 ,
V_15 , V_15 -> V_18 ) ;
return V_15 ;
}
int F_132 ( struct V_124 * V_125 , const int V_233 , char * V_234 ,
const T_1 V_59 )
{
int V_96 = 0 ;
struct V_1 * V_235 = F_133 ( V_233 , & V_96 ) ;
struct V_14 * V_15 = NULL ;
struct V_165 V_166 ;
struct V_150 * sin = (struct V_150 * ) & V_166 ;
int V_152 ;
if ( ! V_235 )
return V_96 ;
V_96 = - V_236 ;
if ( ( V_235 -> V_3 -> V_4 != V_89 ) && ( V_235 -> V_3 -> V_4 != V_92 ) )
goto V_62;
V_96 = - V_237 ;
if ( V_235 -> V_3 -> V_88 != V_211 &&
V_235 -> V_3 -> V_88 != V_73 )
goto V_62;
V_96 = - V_238 ;
if ( V_235 -> V_239 > V_240 )
goto V_62;
V_96 = - V_241 ;
if ( ! F_134 ( V_242 ) )
goto V_62;
V_15 = F_84 ( V_125 , V_235 , V_243 ) ;
if ( F_85 ( V_15 ) ) {
F_135 ( V_242 ) ;
V_96 = F_136 ( V_15 ) ;
goto V_62;
}
if ( F_87 ( V_15 -> V_65 , sin , & V_152 ) == 0 )
F_90 ( & V_15 -> V_17 , sin , V_152 ) ;
F_137 ( V_125 , & V_15 -> V_17 ) ;
return F_21 ( V_15 , V_234 , V_59 ) ;
V_62:
F_138 ( V_235 ) ;
return V_96 ;
}
static struct V_145 * F_69 ( struct V_124 * V_125 ,
int V_244 ,
struct V_149 * V_149 ,
struct V_150 * sin , int V_59 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int error ;
int type ;
struct V_165 V_166 ;
struct V_150 * V_245 = (struct V_150 * ) & V_166 ;
int V_246 ;
int V_247 ;
int V_248 ;
F_18 (char buf[RPC_MAX_ADDRBUFLEN]) ;
F_8 ( L_51 ,
V_125 -> V_249 -> V_250 , V_244 ,
F_83 ( sin , V_85 , sizeof( V_85 ) ) ) ;
if ( V_244 != V_73 && V_244 != V_211 ) {
F_75 ( V_171 L_52
L_53 ) ;
return F_128 ( - V_251 ) ;
}
type = ( V_244 == V_73 ) ? V_232 : V_252 ;
switch ( sin -> V_253 ) {
case V_8 :
V_247 = V_92 ;
break;
case V_5 :
V_247 = V_89 ;
break;
default:
return F_128 ( - V_251 ) ;
}
error = F_139 ( V_149 , V_247 , type , V_244 , & V_2 , 1 ) ;
if ( error < 0 )
return F_128 ( error ) ;
F_1 ( V_2 ) ;
V_248 = 1 ;
if ( V_247 == V_92 )
F_73 ( V_2 , V_35 , V_254 ,
( char * ) & V_248 , sizeof( V_248 ) ) ;
if ( type == V_252 )
V_2 -> V_3 -> V_255 = V_256 ;
error = F_140 ( V_2 , sin , V_59 ) ;
if ( error < 0 )
goto V_257;
V_246 = V_59 ;
error = F_87 ( V_2 , V_245 , & V_246 ) ;
if ( error < 0 )
goto V_257;
if ( V_244 == V_211 ) {
if ( ( error = F_141 ( V_2 , 64 ) ) < 0 )
goto V_257;
}
V_15 = F_84 ( V_125 , V_2 , V_56 ) ;
if ( F_85 ( V_15 ) ) {
error = F_136 ( V_15 ) ;
goto V_257;
}
F_90 ( & V_15 -> V_17 , V_245 , V_246 ) ;
return (struct V_145 * ) V_15 ;
V_257:
F_8 ( L_54 , - error ) ;
F_91 ( V_2 ) ;
return F_128 ( error ) ;
}
static void F_142 ( struct V_145 * V_146 )
{
struct V_14 * V_15 = F_7 ( V_146 , struct V_14 , V_17 ) ;
struct V_2 * V_3 = V_15 -> V_18 ;
T_2 * V_115 ;
F_8 ( L_55 , V_15 ) ;
V_3 -> V_220 = V_15 -> V_229 ;
V_3 -> V_158 = V_15 -> V_230 ;
V_3 -> V_112 = V_15 -> V_231 ;
V_115 = F_33 ( V_3 ) ;
if ( V_115 && F_37 ( V_115 ) )
F_38 ( V_115 ) ;
}
static void F_143 ( struct V_145 * V_146 )
{
struct V_14 * V_15 = F_7 ( V_146 , struct V_14 , V_17 ) ;
F_8 ( L_56 , V_15 ) ;
F_142 ( V_146 ) ;
if ( ! F_34 ( V_217 , & V_146 -> V_117 ) ) {
F_96 ( V_15 ) ;
F_144 ( V_15 -> V_65 , V_258 ) ;
}
}
static void F_145 ( struct V_145 * V_146 )
{
struct V_14 * V_15 = F_7 ( V_146 , struct V_14 , V_17 ) ;
F_8 ( L_57 , V_15 ) ;
if ( V_15 -> V_65 -> V_259 )
F_138 ( V_15 -> V_65 ) ;
else
F_91 ( V_15 -> V_65 ) ;
F_131 ( V_15 ) ;
}
static struct V_145 * F_113 ( struct V_124 * V_125 ,
int V_244 ,
struct V_149 * V_149 ,
struct V_150 * sin , int V_59 ,
int V_56 )
{
struct V_14 * V_15 ;
struct V_145 * V_146 ;
if ( V_244 != V_211 ) {
F_75 ( V_171 L_58
L_59 ) ;
return F_128 ( - V_251 ) ;
}
V_15 = F_127 ( sizeof( * V_15 ) , V_227 ) ;
if ( ! V_15 )
return F_128 ( - V_170 ) ;
V_146 = & V_15 -> V_17 ;
F_71 ( V_149 , & V_218 , V_146 , V_125 ) ;
V_125 -> V_260 = V_146 ;
return V_146 ;
}
static void F_146 ( struct V_145 * V_146 )
{
if ( V_146 )
F_131 ( F_7 ( V_146 , struct V_14 , V_17 ) ) ;
}
