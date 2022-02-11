bool F_1 ( void )
{
return V_1 &&
( ! F_2 () ||
F_3 ( & V_2 ) > 0 ) ;
}
static int F_4 ( struct V_3 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_6 ;
V_6 = F_5 ( sizeof( struct V_6 ) , V_7 ) ;
if ( V_6 == NULL )
return - V_8 ;
V_6 -> V_9 = V_10 ;
F_6 ( & V_6 -> V_11 ) ;
V_5 -> V_12 = V_6 ;
return 0 ;
}
static int F_7 ( struct V_3 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_6 = V_5 -> V_12 ;
if ( V_6 -> V_9 == V_13 ) {
F_8 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
F_9 ( & V_2 ) ;
}
V_6 -> V_9 = V_10 ;
F_10 ( V_6 ) ;
V_5 -> V_12 = NULL ;
return 0 ;
}
static unsigned int F_11 ( struct V_4 * V_5 , T_1 * V_15 )
{
struct V_6 * V_6 = V_5 -> V_12 ;
struct V_16 * V_14 = V_6 -> V_14 ;
unsigned int V_17 = 0 ;
if ( V_6 -> V_9 == V_13 ) {
if ( V_15 )
F_12 ( V_5 , & V_14 -> V_18 . V_19 ,
V_15 ) ;
F_13 ( & V_14 -> V_11 ) ;
if ( V_14 -> V_20 > 0 ||
F_14 (
V_14 -> V_21 ) > 0 ) {
V_17 = V_22 ;
}
F_15 ( & V_14 -> V_11 ) ;
}
return V_17 ;
}
static int F_16 ( void T_2 * V_23 ,
T_3 * V_24 ,
struct V_25 * V_26 ,
int * V_27 )
{
T_4 V_28 = 0 ;
struct V_29 * V_30 ;
if ( V_26 )
V_28 = F_14 ( V_26 ) ;
if ( V_28 * sizeof( * V_30 ) > * V_24 )
return V_31 ;
* V_24 = V_28 * sizeof( * V_30 ) ;
if ( * V_24 )
* V_27 = F_17 ( V_23 ,
F_18
( V_26 ) , * V_24 ) ;
return V_32 ;
}
static int F_19 ( struct V_16 * V_14 ,
unsigned long V_33 )
{
struct V_34 * V_34 ;
int V_27 ;
if ( V_14 -> V_35 ) {
F_20 ( L_1 , V_36 ) ;
return V_37 ;
}
F_21 ( sizeof( bool ) != sizeof( V_38 ) ) ;
if ( ! F_22 ( V_39 , ( void T_2 * ) V_33 , sizeof( V_38 ) ) )
return V_40 ;
F_23 ( & V_41 -> V_42 -> V_43 ) ;
V_27 = F_24 ( V_41 , V_41 -> V_42 ,
F_25 ( V_33 ) ,
1 , 1 , 0 , & V_34 , NULL ) ;
F_26 ( & V_41 -> V_42 -> V_43 ) ;
if ( V_27 != 1 )
return V_40 ;
V_14 -> V_44 = F_27 ( V_34 ) + ( V_33 & ( V_45 - 1 ) ) ;
F_28 ( V_14 ) ;
return V_32 ;
}
static int F_29 ( struct V_6 * V_6 ,
unsigned int V_46 , void T_2 * V_47 )
{
if ( V_46 == V_48 ) {
int T_2 * V_49 = V_47 ;
if ( F_30 ( V_6 -> V_50 , V_49 ) )
return - V_51 ;
}
if ( V_6 -> V_50 > 0 &&
V_6 -> V_50 < V_52 ) {
return V_6 -> V_50 ;
}
return V_53 ;
}
static int F_31 ( struct V_6 * V_6 ,
const char * V_54 ,
void T_2 * V_47 )
{
struct V_55 V_56 ;
const struct V_57 * V_57 ;
int V_27 ;
if ( F_32 ( & V_56 , V_47 , sizeof( V_56 ) ) ) {
F_33 ( L_2 ) ;
return - V_51 ;
}
F_34 ( & V_6 -> V_11 ) ;
if ( V_6 -> V_9 != V_10 ) {
F_33 ( L_3 ) ;
V_27 = - V_58 ;
goto V_59;
}
if ( V_56 . V_60 & ~ V_61 ) {
F_33 ( L_4 ) ;
V_27 = - V_58 ;
goto V_59;
}
V_57 = F_35 () ;
V_6 -> V_14 = F_36 ( V_56 . V_62 ,
V_56 . V_60 , 0 ,
V_6 -> V_50 ,
V_57 ) ;
F_37 ( V_57 ) ;
if ( F_38 ( V_6 -> V_14 ) ) {
V_27 = F_39 ( V_6 -> V_14 ) ;
F_33 ( L_5 ) ;
goto V_59;
}
V_56 . V_62 = F_40 ( V_6 -> V_14 ) ;
if ( F_17 ( V_47 , & V_56 , sizeof( V_56 ) ) ) {
F_8 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
F_33 ( L_6 ) ;
V_27 = - V_51 ;
goto V_59;
}
V_6 -> V_9 = V_13 ;
F_41 ( & V_2 ) ;
V_27 = 0 ;
V_59:
F_42 ( & V_6 -> V_11 ) ;
return V_27 ;
}
static int F_43 ( struct V_6 * V_6 ,
const char * V_54 ,
void T_2 * V_47 )
{
struct V_63 V_64 ;
struct V_65 * V_66 = NULL ;
T_4 V_62 ;
if ( V_6 -> V_9 != V_13 ) {
F_33 ( L_7 ) ;
return - V_58 ;
}
if ( F_32 ( & V_64 , V_47 , sizeof( V_64 ) ) )
return - V_51 ;
if ( V_64 . V_67 > V_68 ) {
F_33 ( L_8 ,
V_64 . V_67 ) ;
return - V_58 ;
}
if ( V_64 . V_67 < sizeof( * V_66 ) ) {
F_33 ( L_9 ,
V_64 . V_67 ) ;
return - V_58 ;
}
V_66 = F_44 ( V_64 . V_67 , V_7 ) ;
if ( ! V_66 ) {
F_33 (
L_10 ) ;
return - V_8 ;
}
if ( F_32 ( V_66 , ( void T_2 * ) ( V_69 ) V_64 . V_70 ,
V_64 . V_67 ) ) {
F_33 ( L_11 ) ;
F_10 ( V_66 ) ;
return - V_51 ;
}
F_20 ( L_12 ,
V_66 -> V_71 . V_14 , V_66 -> V_71 . V_72 ,
V_66 -> V_73 . V_14 , V_66 -> V_73 . V_72 ,
( unsigned long long ) V_66 -> V_74 ) ;
V_62 = F_40 ( V_6 -> V_14 ) ;
V_64 . V_75 = F_45 ( V_62 , V_66 , true ) ;
F_10 ( V_66 ) ;
return F_17 ( V_47 , & V_64 , sizeof( V_64 ) ) ? - V_51 : 0 ;
}
static int F_46 ( struct V_6 * V_6 ,
const char * V_54 ,
void T_2 * V_47 )
{
struct V_63 V_76 ;
struct V_65 * V_66 = NULL ;
int V_27 ;
T_5 V_77 ;
if ( V_6 -> V_9 != V_13 ) {
F_33 ( L_7 ) ;
return - V_58 ;
}
if ( F_32 ( & V_76 , V_47 , sizeof( V_76 ) ) )
return - V_51 ;
V_77 = V_76 . V_67 ;
V_76 . V_75 = F_47 ( V_6 -> V_14 ,
& V_77 , & V_66 ) ;
if ( V_76 . V_75 >= V_32 ) {
void T_2 * V_78 = ( void T_2 * ) ( V_69 ) V_76 . V_70 ;
V_27 = F_17 ( V_78 , V_66 , F_48 ( V_66 ) ) ;
F_10 ( V_66 ) ;
if ( V_27 != 0 )
return - V_51 ;
}
return F_17 ( V_47 , & V_76 , sizeof( V_76 ) ) ? - V_51 : 0 ;
}
static int F_49 ( struct V_6 * V_6 ,
const char * V_54 ,
void T_2 * V_47 )
{
struct V_29 V_79 ;
int V_80 ;
int T_2 * V_81 ;
T_4 V_62 ;
if ( V_6 -> V_9 != V_13 ) {
F_33 ( L_7 ) ;
return - V_58 ;
}
V_62 = F_40 ( V_6 -> V_14 ) ;
if ( V_6 -> V_50 < V_82 ) {
struct V_83 V_84 ;
struct V_83 T_2 * V_85 = V_47 ;
if ( F_32 ( & V_84 , V_47 , sizeof( V_84 ) ) )
return - V_51 ;
V_79 = V_84 . V_79 ;
V_81 = & V_85 -> V_75 ;
V_80 = F_50 ( V_84 . V_79 ,
V_84 . V_86 ,
V_84 . V_60 ,
V_87 ,
V_84 . V_88 ,
V_84 . V_89 ,
NULL ,
V_6 -> V_14 ) ;
if ( V_80 == V_32 )
V_80 = V_90 ;
} else {
struct V_91 V_84 ;
struct V_91 T_2 * V_85 = V_47 ;
struct V_92 V_93 ;
if ( F_32 ( & V_84 , V_47 , sizeof( V_84 ) ) )
return - V_51 ;
V_79 = V_84 . V_79 ;
V_81 = & V_85 -> V_75 ;
V_93 . V_94 = V_84 . V_95 ;
V_93 . V_67 = V_84 . V_96 ;
V_80 = F_50 ( V_84 . V_79 ,
V_84 . V_86 ,
V_84 . V_60 ,
V_87 ,
V_84 . V_88 ,
V_84 . V_89 ,
& V_93 ,
V_6 -> V_14 ) ;
}
if ( F_51 ( V_80 , V_81 ) ) {
if ( V_80 >= V_32 ) {
V_80 = F_52 ( V_79 ,
V_6 -> V_14 ) ;
}
return - V_51 ;
}
return 0 ;
}
static int F_53 ( struct V_6 * V_6 ,
const char * V_54 ,
void T_2 * V_47 )
{
struct V_97 V_98 ;
struct V_97 T_2 * V_85 = V_47 ;
T_6 V_75 ;
if ( V_6 -> V_9 != V_13 ) {
F_33 ( L_7 ) ;
return - V_58 ;
}
if ( V_6 -> V_50 < V_82 ) {
F_33 ( L_13 ) ;
return - V_58 ;
}
if ( F_32 ( & V_98 , V_47 , sizeof( V_98 ) ) )
return - V_51 ;
if ( V_98 . V_99 ) {
V_75 = F_54 ( V_98 . V_79 ,
V_6 -> V_14 ,
V_98 . V_99 ) ;
} else {
V_75 = F_55 ( V_98 . V_79 ,
V_6 -> V_14 , 0 ) ;
}
return F_51 ( V_75 , & V_85 -> V_75 ) ? - V_51 : 0 ;
}
static int F_56 ( struct V_6 * V_6 ,
const char * V_54 ,
void T_2 * V_47 )
{
struct V_100 V_101 ;
struct V_100 T_2 * V_85 = V_47 ;
T_6 V_75 ;
if ( V_6 -> V_50 < V_52 ||
V_6 -> V_50 >= V_82 ) {
F_33 ( L_14 ,
V_6 -> V_50 ) ;
return - V_58 ;
}
if ( V_6 -> V_9 != V_13 ) {
F_33 ( L_7 ) ;
return - V_58 ;
}
if ( F_32 ( & V_101 , V_47 , sizeof( * V_85 ) ) )
return - V_51 ;
if ( F_51 ( V_32 , & V_85 -> V_75 ) ) {
return - V_51 ;
}
V_75 = F_57 ( V_101 . V_79 ,
V_101 . V_102 ,
V_101 . V_103 ,
V_6 -> V_14 ) ;
if ( V_75 < V_32 ) {
if ( F_51 ( V_75 , & V_85 -> V_75 ) ) {
return - V_51 ;
}
}
return 0 ;
}
static int F_58 ( struct V_6 * V_6 ,
const char * V_54 ,
void T_2 * V_47 )
{
struct V_104 V_105 ;
struct V_104 T_2 * V_85 = V_47 ;
T_6 V_75 ;
if ( V_6 -> V_9 != V_13 ) {
F_33 ( L_7 ) ;
return - V_58 ;
}
if ( F_32 ( & V_105 , V_47 , sizeof( V_105 ) ) )
return - V_51 ;
V_75 = F_52 ( V_105 . V_79 ,
V_6 -> V_14 ) ;
if ( V_75 == V_32 &&
V_6 -> V_50 < V_82 ) {
V_75 = V_106 ;
}
return F_51 ( V_75 , & V_85 -> V_75 ) ? - V_51 : 0 ;
}
static int F_59 ( struct V_6 * V_6 ,
const char * V_54 ,
void T_2 * V_47 )
{
struct V_107 V_108 ;
struct V_107 T_2 * V_85 = V_47 ;
T_6 V_75 ;
T_4 V_62 ;
if ( V_6 -> V_9 != V_13 ) {
F_33 ( L_7 ) ;
return - V_58 ;
}
if ( F_32 ( & V_108 , V_47 , sizeof( V_108 ) ) )
return - V_51 ;
V_62 = F_40 ( V_6 -> V_14 ) ;
V_75 = F_60 ( V_62 , V_108 . V_109 ) ;
return F_51 ( V_75 , & V_85 -> V_75 ) ? - V_51 : 0 ;
}
static int F_61 ( struct V_6 * V_6 ,
const char * V_54 ,
void T_2 * V_47 )
{
struct V_107 V_108 ;
struct V_107 T_2 * V_85 = V_47 ;
T_4 V_62 ;
int V_75 ;
if ( V_6 -> V_9 != V_13 ) {
F_33 ( L_7 ) ;
return - V_58 ;
}
if ( F_32 ( & V_108 , V_47 , sizeof( V_108 ) ) )
return - V_51 ;
V_62 = F_40 ( V_6 -> V_14 ) ;
V_75 = F_62 ( V_62 ,
V_108 . V_109 ) ;
return F_51 ( V_75 , & V_85 -> V_75 ) ? - V_51 : 0 ;
}
static int F_63 ( struct V_6 * V_6 ,
const char * V_54 ,
void T_2 * V_47 )
{
struct V_110 V_111 ;
T_4 V_62 ;
void * V_112 ;
int V_27 ;
if ( V_6 -> V_9 != V_13 ) {
F_33 ( L_7 ) ;
return - V_58 ;
}
if ( F_32 ( & V_111 , V_47 , sizeof( V_111 ) ) )
return - V_51 ;
V_62 = F_40 ( V_6 -> V_14 ) ;
V_111 . V_75 = F_64 ( V_62 , V_111 . V_113 ,
& V_111 . V_114 , & V_112 ) ;
if ( V_111 . V_75 == V_32 && V_111 . V_114 ) {
void T_2 * V_78 = ( void T_2 * ) ( V_69 ) V_111 . V_112 ;
V_27 = F_17 ( V_78 , V_112 , V_111 . V_114 ) ;
F_10 ( V_112 ) ;
if ( V_27 )
return - V_51 ;
}
return F_17 ( V_47 , & V_111 , sizeof( V_111 ) ) ? - V_51 : 0 ;
}
static int F_65 ( struct V_6 * V_6 ,
const char * V_54 ,
void T_2 * V_47 )
{
struct V_110 V_115 ;
T_4 V_62 ;
void * V_112 ;
int V_27 ;
if ( V_6 -> V_9 != V_13 ) {
F_33 ( L_7 ) ;
return - V_58 ;
}
if ( F_32 ( & V_115 , V_47 , sizeof( V_115 ) ) )
return - V_51 ;
V_112 = F_44 ( V_115 . V_114 , V_7 ) ;
if ( ! V_112 ) {
F_33 (
L_15 ,
V_115 . V_113 ) ;
return - V_8 ;
}
if ( F_32 ( V_112 , ( void T_2 * ) ( V_69 ) V_115 . V_112 ,
V_115 . V_114 ) ) {
V_27 = - V_51 ;
goto V_59;
}
V_62 = F_40 ( V_6 -> V_14 ) ;
V_115 . V_75 = F_66 ( V_62 , V_115 . V_113 ,
V_115 . V_114 , V_112 ) ;
V_27 = F_17 ( V_47 , & V_115 , sizeof( V_115 ) ) ? - V_51 : 0 ;
V_59:
F_10 ( V_112 ) ;
return V_27 ;
}
static int F_67 ( struct V_6 * V_6 ,
const char * V_54 ,
void T_2 * V_47 )
{
T_4 T_2 * V_116 = V_47 ;
return F_51 ( V_117 , V_116 ) ? - V_51 : 0 ;
}
static int F_68 ( struct V_6 * V_6 ,
const char * V_54 ,
void T_2 * V_47 )
{
struct V_118 V_119 ;
if ( V_6 -> V_9 != V_13 ) {
F_33 ( L_7 ) ;
return - V_58 ;
}
if ( F_32 ( & V_119 , V_47 , sizeof( V_119 ) ) )
return - V_51 ;
if ( V_119 . V_120 ) {
V_119 . V_75 =
F_19 ( V_6 -> V_14 ,
V_119 . V_120 ) ;
} else {
F_69 ( V_6 -> V_14 ) ;
V_119 . V_75 = V_32 ;
}
return F_17 ( V_47 , & V_119 , sizeof( V_119 ) ) ?
- V_51 : 0 ;
}
static int F_70 ( struct V_6 * V_6 ,
const char * V_54 ,
void T_2 * V_47 )
{
struct V_121 V_85 ;
T_4 V_62 ;
if ( V_6 -> V_50 < V_122 ) {
F_33 ( L_16 ) ;
return - V_58 ;
}
if ( V_6 -> V_9 != V_13 ) {
F_33 ( L_7 ) ;
return - V_58 ;
}
if ( F_32 ( & V_85 , V_47 , sizeof( V_85 ) ) )
return - V_51 ;
V_62 = F_40 ( V_6 -> V_14 ) ;
switch ( V_85 . V_123 ) {
case V_124 :
if ( V_85 . V_72 == V_125 ) {
T_4 V_60 = V_87 ;
V_85 . V_75 = F_71 ( V_62 , V_85 . V_79 ,
V_60 ) ;
} else {
V_85 . V_75 = V_126 ;
}
break;
case V_127 :
V_85 . V_75 = F_72 ( V_62 , V_85 . V_79 ) ;
break;
case V_128 :
V_85 . V_75 = F_73 ( V_62 , V_85 . V_79 ) ;
break;
default:
F_33 ( L_17 ,
V_85 . V_123 ) ;
V_85 . V_75 = V_129 ;
}
return F_17 ( V_47 , & V_85 , sizeof( V_85 ) ) ? - V_51 : 0 ;
}
static int F_74 ( struct V_6 * V_6 ,
const char * V_54 ,
void T_2 * V_47 )
{
struct V_130 V_85 ;
struct V_25 * V_131 ;
struct V_25 * V_132 ;
void T_2 * V_78 ;
T_4 V_62 ;
int V_27 = 0 ;
if ( V_6 -> V_9 != V_13 ) {
F_33 ( L_7 ) ;
return - V_58 ;
}
if ( V_6 -> V_50 < V_122 ) {
F_33 ( L_18 ) ;
return - V_58 ;
}
if ( F_32 ( & V_85 , V_47 , sizeof( V_85 ) ) )
return - V_51 ;
if ( ( V_85 . V_133 && ! V_85 . V_134 ) ||
( V_85 . V_135 && ! V_85 . V_136 ) ) {
return - V_58 ;
}
V_62 = F_40 ( V_6 -> V_14 ) ;
V_85 . V_75 = F_75 ( V_62 ,
& V_131 , & V_132 ) ;
if ( V_85 . V_75 != V_32 )
return F_17 ( V_47 , & V_85 , sizeof( V_85 ) ) ? - V_51 : 0 ;
V_78 = ( void T_2 * ) ( V_69 ) V_85 . V_134 ;
V_85 . V_75 = F_16 ( V_78 , & V_85 . V_133 ,
V_131 , & V_27 ) ;
if ( V_85 . V_75 == V_32 && ! V_27 ) {
V_78 = ( void T_2 * ) ( V_69 ) V_85 . V_136 ;
V_85 . V_75 = F_16 ( V_78 ,
& V_85 . V_135 ,
V_132 , & V_27 ) ;
}
if ( ! V_27 && F_17 ( V_47 , & V_85 , sizeof( V_85 ) ) )
V_27 = - V_51 ;
F_76 ( V_62 ,
V_131 , V_132 ,
V_85 . V_75 == V_32 && ! V_27 ) ;
return V_27 ;
}
static long F_77 ( struct V_4 * V_5 ,
unsigned int V_137 , unsigned long V_138 )
{
#define F_78 ( V_54 , T_7 ) do { \
char *name = __stringify(IOCTL_VMCI_ ## ioctl_name); \
return vmci_host_do_ ## ioctl_fn( \
vmci_host_dev, name, uptr); \
} while (0)
struct V_6 * V_6 = V_5 -> V_12 ;
void T_2 * V_47 = ( void T_2 * ) V_138 ;
switch ( V_137 ) {
case V_139 :
F_78 ( V_140 , V_141 ) ;
case V_142 :
F_78 ( V_143 , V_144 ) ;
case V_145 :
F_78 ( V_146 , V_147 ) ;
case V_148 :
F_78 ( V_149 , V_150 ) ;
case V_151 :
F_78 ( V_152 , V_153 ) ;
case V_154 :
F_78 ( V_155 , V_156 ) ;
case V_157 :
F_78 ( V_158 , V_159 ) ;
case V_160 :
F_78 ( V_161 , V_162 ) ;
case V_163 :
F_78 ( V_164 , V_165 ) ;
case V_166 :
F_78 ( V_167 , V_168 ) ;
case V_169 :
F_78 ( V_170 , V_171 ) ;
case V_172 :
F_78 ( V_173 , V_174 ) ;
case V_175 :
F_78 ( V_176 , V_177 ) ;
case V_178 :
F_78 ( V_179 , V_180 ) ;
case V_181 :
F_78 ( V_182 , V_183 ) ;
case V_184 :
case V_48 :
return F_29 ( V_6 , V_137 , V_47 ) ;
default:
F_20 ( L_19 , V_36 , V_137 ) ;
return - V_58 ;
}
#undef F_78
}
int T_8 F_79 ( void )
{
int error ;
V_18 = F_36 ( V_117 ,
V_185 ,
- 1 , V_53 , NULL ) ;
if ( F_38 ( V_18 ) ) {
error = F_39 ( V_18 ) ;
F_80 ( L_20 ,
error ) ;
return error ;
}
error = F_81 ( & V_186 ) ;
if ( error ) {
F_80 ( L_21 ,
V_186 . V_187 ,
V_188 , V_186 . V_189 ,
error ) ;
F_80 ( L_22 ) ;
F_8 ( V_18 ) ;
return error ;
}
F_82 ( L_23 ,
V_186 . V_187 , V_188 , V_186 . V_189 ) ;
V_1 = true ;
return 0 ;
}
void T_9 F_83 ( void )
{
int error ;
V_1 = false ;
error = F_84 ( & V_186 ) ;
if ( error )
F_80 ( L_24 , error ) ;
F_8 ( V_18 ) ;
F_85 () ;
F_86 ( L_25 ) ;
}
