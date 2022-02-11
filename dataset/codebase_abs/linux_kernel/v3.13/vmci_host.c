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
V_27 = F_23 ( F_24 ( V_33 ) , 1 , 1 , & V_34 ) ;
if ( V_27 != 1 )
return V_40 ;
V_14 -> V_41 = F_25 ( V_34 ) + ( V_33 & ( V_42 - 1 ) ) ;
F_26 ( V_14 ) ;
return V_32 ;
}
static int F_27 ( struct V_6 * V_6 ,
unsigned int V_43 , void T_2 * V_44 )
{
if ( V_43 == V_45 ) {
int T_2 * V_46 = V_44 ;
if ( F_28 ( V_6 -> V_47 , V_46 ) )
return - V_48 ;
}
if ( V_6 -> V_47 > 0 &&
V_6 -> V_47 < V_49 ) {
return V_6 -> V_47 ;
}
return V_50 ;
}
static int F_29 ( struct V_6 * V_6 ,
const char * V_51 ,
void T_2 * V_44 )
{
struct V_52 V_53 ;
const struct V_54 * V_54 ;
int V_27 ;
if ( F_30 ( & V_53 , V_44 , sizeof( V_53 ) ) ) {
F_31 ( L_2 ) ;
return - V_48 ;
}
F_32 ( & V_6 -> V_11 ) ;
if ( V_6 -> V_9 != V_10 ) {
F_31 ( L_3 ) ;
V_27 = - V_55 ;
goto V_56;
}
if ( V_53 . V_57 & ~ V_58 ) {
F_31 ( L_4 ) ;
V_27 = - V_55 ;
goto V_56;
}
V_54 = F_33 () ;
V_6 -> V_14 = F_34 ( V_53 . V_59 ,
V_53 . V_57 , 0 ,
V_6 -> V_47 ,
V_54 ) ;
F_35 ( V_54 ) ;
if ( F_36 ( V_6 -> V_14 ) ) {
V_27 = F_37 ( V_6 -> V_14 ) ;
F_31 ( L_5 ) ;
goto V_56;
}
V_53 . V_59 = F_38 ( V_6 -> V_14 ) ;
if ( F_17 ( V_44 , & V_53 , sizeof( V_53 ) ) ) {
F_8 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
F_31 ( L_6 ) ;
V_27 = - V_48 ;
goto V_56;
}
V_6 -> V_9 = V_13 ;
F_39 ( & V_2 ) ;
V_27 = 0 ;
V_56:
F_40 ( & V_6 -> V_11 ) ;
return V_27 ;
}
static int F_41 ( struct V_6 * V_6 ,
const char * V_51 ,
void T_2 * V_44 )
{
struct V_60 V_61 ;
struct V_62 * V_63 = NULL ;
T_4 V_59 ;
if ( V_6 -> V_9 != V_13 ) {
F_31 ( L_7 ) ;
return - V_55 ;
}
if ( F_30 ( & V_61 , V_44 , sizeof( V_61 ) ) )
return - V_48 ;
if ( V_61 . V_64 > V_65 ) {
F_31 ( L_8 ,
V_61 . V_64 ) ;
return - V_55 ;
}
if ( V_61 . V_64 < sizeof( * V_63 ) ) {
F_31 ( L_9 ,
V_61 . V_64 ) ;
return - V_55 ;
}
V_63 = F_42 ( V_61 . V_64 , V_7 ) ;
if ( ! V_63 ) {
F_31 (
L_10 ) ;
return - V_8 ;
}
if ( F_30 ( V_63 , ( void T_2 * ) ( V_66 ) V_61 . V_67 ,
V_61 . V_64 ) ) {
F_31 ( L_11 ) ;
F_10 ( V_63 ) ;
return - V_48 ;
}
F_20 ( L_12 ,
V_63 -> V_68 . V_14 , V_63 -> V_68 . V_69 ,
V_63 -> V_70 . V_14 , V_63 -> V_70 . V_69 ,
( unsigned long long ) V_63 -> V_71 ) ;
V_59 = F_38 ( V_6 -> V_14 ) ;
V_61 . V_72 = F_43 ( V_59 , V_63 , true ) ;
F_10 ( V_63 ) ;
return F_17 ( V_44 , & V_61 , sizeof( V_61 ) ) ? - V_48 : 0 ;
}
static int F_44 ( struct V_6 * V_6 ,
const char * V_51 ,
void T_2 * V_44 )
{
struct V_60 V_73 ;
struct V_62 * V_63 = NULL ;
int V_27 ;
T_5 V_74 ;
if ( V_6 -> V_9 != V_13 ) {
F_31 ( L_7 ) ;
return - V_55 ;
}
if ( F_30 ( & V_73 , V_44 , sizeof( V_73 ) ) )
return - V_48 ;
V_74 = V_73 . V_64 ;
V_73 . V_72 = F_45 ( V_6 -> V_14 ,
& V_74 , & V_63 ) ;
if ( V_73 . V_72 >= V_32 ) {
void T_2 * V_75 = ( void T_2 * ) ( V_66 ) V_73 . V_67 ;
V_27 = F_17 ( V_75 , V_63 , F_46 ( V_63 ) ) ;
F_10 ( V_63 ) ;
if ( V_27 != 0 )
return - V_48 ;
}
return F_17 ( V_44 , & V_73 , sizeof( V_73 ) ) ? - V_48 : 0 ;
}
static int F_47 ( struct V_6 * V_6 ,
const char * V_51 ,
void T_2 * V_44 )
{
struct V_29 V_76 ;
int V_77 ;
int T_2 * V_78 ;
T_4 V_59 ;
if ( V_6 -> V_9 != V_13 ) {
F_31 ( L_7 ) ;
return - V_55 ;
}
V_59 = F_38 ( V_6 -> V_14 ) ;
if ( V_6 -> V_47 < V_79 ) {
struct V_80 V_81 ;
struct V_80 T_2 * V_82 = V_44 ;
if ( F_30 ( & V_81 , V_44 , sizeof( V_81 ) ) )
return - V_48 ;
V_76 = V_81 . V_76 ;
V_78 = & V_82 -> V_72 ;
V_77 = F_48 ( V_81 . V_76 ,
V_81 . V_83 ,
V_81 . V_57 ,
V_84 ,
V_81 . V_85 ,
V_81 . V_86 ,
NULL ,
V_6 -> V_14 ) ;
if ( V_77 == V_32 )
V_77 = V_87 ;
} else {
struct V_88 V_81 ;
struct V_88 T_2 * V_82 = V_44 ;
struct V_89 V_90 ;
if ( F_30 ( & V_81 , V_44 , sizeof( V_81 ) ) )
return - V_48 ;
V_76 = V_81 . V_76 ;
V_78 = & V_82 -> V_72 ;
V_90 . V_91 = V_81 . V_92 ;
V_90 . V_64 = V_81 . V_93 ;
V_77 = F_48 ( V_81 . V_76 ,
V_81 . V_83 ,
V_81 . V_57 ,
V_84 ,
V_81 . V_85 ,
V_81 . V_86 ,
& V_90 ,
V_6 -> V_14 ) ;
}
if ( F_49 ( V_77 , V_78 ) ) {
if ( V_77 >= V_32 ) {
V_77 = F_50 ( V_76 ,
V_6 -> V_14 ) ;
}
return - V_48 ;
}
return 0 ;
}
static int F_51 ( struct V_6 * V_6 ,
const char * V_51 ,
void T_2 * V_44 )
{
struct V_94 V_95 ;
struct V_94 T_2 * V_82 = V_44 ;
T_6 V_72 ;
if ( V_6 -> V_9 != V_13 ) {
F_31 ( L_7 ) ;
return - V_55 ;
}
if ( V_6 -> V_47 < V_79 ) {
F_31 ( L_13 ) ;
return - V_55 ;
}
if ( F_30 ( & V_95 , V_44 , sizeof( V_95 ) ) )
return - V_48 ;
if ( V_95 . V_96 ) {
V_72 = F_52 ( V_95 . V_76 ,
V_6 -> V_14 ,
V_95 . V_96 ) ;
} else {
V_72 = F_53 ( V_95 . V_76 ,
V_6 -> V_14 , 0 ) ;
}
return F_49 ( V_72 , & V_82 -> V_72 ) ? - V_48 : 0 ;
}
static int F_54 ( struct V_6 * V_6 ,
const char * V_51 ,
void T_2 * V_44 )
{
struct V_97 V_98 ;
struct V_97 T_2 * V_82 = V_44 ;
T_6 V_72 ;
if ( V_6 -> V_47 < V_49 ||
V_6 -> V_47 >= V_79 ) {
F_31 ( L_14 ,
V_6 -> V_47 ) ;
return - V_55 ;
}
if ( V_6 -> V_9 != V_13 ) {
F_31 ( L_7 ) ;
return - V_55 ;
}
if ( F_30 ( & V_98 , V_44 , sizeof( * V_82 ) ) )
return - V_48 ;
if ( F_49 ( V_32 , & V_82 -> V_72 ) ) {
return - V_48 ;
}
V_72 = F_55 ( V_98 . V_76 ,
V_98 . V_99 ,
V_98 . V_100 ,
V_6 -> V_14 ) ;
if ( V_72 < V_32 ) {
if ( F_49 ( V_72 , & V_82 -> V_72 ) ) {
return - V_48 ;
}
}
return 0 ;
}
static int F_56 ( struct V_6 * V_6 ,
const char * V_51 ,
void T_2 * V_44 )
{
struct V_101 V_102 ;
struct V_101 T_2 * V_82 = V_44 ;
T_6 V_72 ;
if ( V_6 -> V_9 != V_13 ) {
F_31 ( L_7 ) ;
return - V_55 ;
}
if ( F_30 ( & V_102 , V_44 , sizeof( V_102 ) ) )
return - V_48 ;
V_72 = F_50 ( V_102 . V_76 ,
V_6 -> V_14 ) ;
if ( V_72 == V_32 &&
V_6 -> V_47 < V_79 ) {
V_72 = V_103 ;
}
return F_49 ( V_72 , & V_82 -> V_72 ) ? - V_48 : 0 ;
}
static int F_57 ( struct V_6 * V_6 ,
const char * V_51 ,
void T_2 * V_44 )
{
struct V_104 V_105 ;
struct V_104 T_2 * V_82 = V_44 ;
T_6 V_72 ;
T_4 V_59 ;
if ( V_6 -> V_9 != V_13 ) {
F_31 ( L_7 ) ;
return - V_55 ;
}
if ( F_30 ( & V_105 , V_44 , sizeof( V_105 ) ) )
return - V_48 ;
V_59 = F_38 ( V_6 -> V_14 ) ;
V_72 = F_58 ( V_59 , V_105 . V_106 ) ;
return F_49 ( V_72 , & V_82 -> V_72 ) ? - V_48 : 0 ;
}
static int F_59 ( struct V_6 * V_6 ,
const char * V_51 ,
void T_2 * V_44 )
{
struct V_104 V_105 ;
struct V_104 T_2 * V_82 = V_44 ;
T_4 V_59 ;
int V_72 ;
if ( V_6 -> V_9 != V_13 ) {
F_31 ( L_7 ) ;
return - V_55 ;
}
if ( F_30 ( & V_105 , V_44 , sizeof( V_105 ) ) )
return - V_48 ;
V_59 = F_38 ( V_6 -> V_14 ) ;
V_72 = F_60 ( V_59 ,
V_105 . V_106 ) ;
return F_49 ( V_72 , & V_82 -> V_72 ) ? - V_48 : 0 ;
}
static int F_61 ( struct V_6 * V_6 ,
const char * V_51 ,
void T_2 * V_44 )
{
struct V_107 V_108 ;
T_4 V_59 ;
void * V_109 ;
int V_27 ;
if ( V_6 -> V_9 != V_13 ) {
F_31 ( L_7 ) ;
return - V_55 ;
}
if ( F_30 ( & V_108 , V_44 , sizeof( V_108 ) ) )
return - V_48 ;
V_59 = F_38 ( V_6 -> V_14 ) ;
V_108 . V_72 = F_62 ( V_59 , V_108 . V_110 ,
& V_108 . V_111 , & V_109 ) ;
if ( V_108 . V_72 == V_32 && V_108 . V_111 ) {
void T_2 * V_75 = ( void T_2 * ) ( V_66 ) V_108 . V_109 ;
V_27 = F_17 ( V_75 , V_109 , V_108 . V_111 ) ;
F_10 ( V_109 ) ;
if ( V_27 )
return - V_48 ;
}
return F_17 ( V_44 , & V_108 , sizeof( V_108 ) ) ? - V_48 : 0 ;
}
static int F_63 ( struct V_6 * V_6 ,
const char * V_51 ,
void T_2 * V_44 )
{
struct V_107 V_112 ;
T_4 V_59 ;
void * V_109 ;
int V_27 ;
if ( V_6 -> V_9 != V_13 ) {
F_31 ( L_7 ) ;
return - V_55 ;
}
if ( F_30 ( & V_112 , V_44 , sizeof( V_112 ) ) )
return - V_48 ;
V_109 = F_42 ( V_112 . V_111 , V_7 ) ;
if ( ! V_109 ) {
F_31 (
L_15 ,
V_112 . V_110 ) ;
return - V_8 ;
}
if ( F_30 ( V_109 , ( void T_2 * ) ( V_66 ) V_112 . V_109 ,
V_112 . V_111 ) ) {
V_27 = - V_48 ;
goto V_56;
}
V_59 = F_38 ( V_6 -> V_14 ) ;
V_112 . V_72 = F_64 ( V_59 , V_112 . V_110 ,
V_112 . V_111 , V_109 ) ;
V_27 = F_17 ( V_44 , & V_112 , sizeof( V_112 ) ) ? - V_48 : 0 ;
V_56:
F_10 ( V_109 ) ;
return V_27 ;
}
static int F_65 ( struct V_6 * V_6 ,
const char * V_51 ,
void T_2 * V_44 )
{
T_4 T_2 * V_113 = V_44 ;
return F_49 ( V_114 , V_113 ) ? - V_48 : 0 ;
}
static int F_66 ( struct V_6 * V_6 ,
const char * V_51 ,
void T_2 * V_44 )
{
struct V_115 V_116 ;
if ( V_6 -> V_9 != V_13 ) {
F_31 ( L_7 ) ;
return - V_55 ;
}
if ( F_30 ( & V_116 , V_44 , sizeof( V_116 ) ) )
return - V_48 ;
if ( V_116 . V_117 ) {
V_116 . V_72 =
F_19 ( V_6 -> V_14 ,
V_116 . V_117 ) ;
} else {
F_67 ( V_6 -> V_14 ) ;
V_116 . V_72 = V_32 ;
}
return F_17 ( V_44 , & V_116 , sizeof( V_116 ) ) ?
- V_48 : 0 ;
}
static int F_68 ( struct V_6 * V_6 ,
const char * V_51 ,
void T_2 * V_44 )
{
struct V_118 V_82 ;
T_4 V_59 ;
if ( V_6 -> V_47 < V_119 ) {
F_31 ( L_16 ) ;
return - V_55 ;
}
if ( V_6 -> V_9 != V_13 ) {
F_31 ( L_7 ) ;
return - V_55 ;
}
if ( F_30 ( & V_82 , V_44 , sizeof( V_82 ) ) )
return - V_48 ;
V_59 = F_38 ( V_6 -> V_14 ) ;
switch ( V_82 . V_120 ) {
case V_121 :
if ( V_82 . V_69 == V_122 ) {
T_4 V_57 = V_84 ;
V_82 . V_72 = F_69 ( V_59 , V_82 . V_76 ,
V_57 ) ;
} else {
V_82 . V_72 = V_123 ;
}
break;
case V_124 :
V_82 . V_72 = F_70 ( V_59 , V_82 . V_76 ) ;
break;
case V_125 :
V_82 . V_72 = F_71 ( V_59 , V_82 . V_76 ) ;
break;
default:
F_31 ( L_17 ,
V_82 . V_120 ) ;
V_82 . V_72 = V_126 ;
}
return F_17 ( V_44 , & V_82 , sizeof( V_82 ) ) ? - V_48 : 0 ;
}
static int F_72 ( struct V_6 * V_6 ,
const char * V_51 ,
void T_2 * V_44 )
{
struct V_127 V_82 ;
struct V_25 * V_128 ;
struct V_25 * V_129 ;
void T_2 * V_75 ;
T_4 V_59 ;
int V_27 = 0 ;
if ( V_6 -> V_9 != V_13 ) {
F_31 ( L_7 ) ;
return - V_55 ;
}
if ( V_6 -> V_47 < V_119 ) {
F_31 ( L_18 ) ;
return - V_55 ;
}
if ( F_30 ( & V_82 , V_44 , sizeof( V_82 ) ) )
return - V_48 ;
if ( ( V_82 . V_130 && ! V_82 . V_131 ) ||
( V_82 . V_132 && ! V_82 . V_133 ) ) {
return - V_55 ;
}
V_59 = F_38 ( V_6 -> V_14 ) ;
V_82 . V_72 = F_73 ( V_59 ,
& V_128 , & V_129 ) ;
if ( V_82 . V_72 != V_32 )
return F_17 ( V_44 , & V_82 , sizeof( V_82 ) ) ? - V_48 : 0 ;
V_75 = ( void T_2 * ) ( V_66 ) V_82 . V_131 ;
V_82 . V_72 = F_16 ( V_75 , & V_82 . V_130 ,
V_128 , & V_27 ) ;
if ( V_82 . V_72 == V_32 && ! V_27 ) {
V_75 = ( void T_2 * ) ( V_66 ) V_82 . V_133 ;
V_82 . V_72 = F_16 ( V_75 ,
& V_82 . V_132 ,
V_129 , & V_27 ) ;
}
if ( ! V_27 && F_17 ( V_44 , & V_82 , sizeof( V_82 ) ) )
V_27 = - V_48 ;
F_74 ( V_59 ,
V_128 , V_129 ,
V_82 . V_72 == V_32 && ! V_27 ) ;
return V_27 ;
}
static long F_75 ( struct V_4 * V_5 ,
unsigned int V_134 , unsigned long V_135 )
{
#define F_76 ( V_51 , T_7 ) do { \
char *name = __stringify(IOCTL_VMCI_ ## ioctl_name); \
return vmci_host_do_ ## ioctl_fn( \
vmci_host_dev, name, uptr); \
} while (0)
struct V_6 * V_6 = V_5 -> V_12 ;
void T_2 * V_44 = ( void T_2 * ) V_135 ;
switch ( V_134 ) {
case V_136 :
F_76 ( V_137 , V_138 ) ;
case V_139 :
F_76 ( V_140 , V_141 ) ;
case V_142 :
F_76 ( V_143 , V_144 ) ;
case V_145 :
F_76 ( V_146 , V_147 ) ;
case V_148 :
F_76 ( V_149 , V_150 ) ;
case V_151 :
F_76 ( V_152 , V_153 ) ;
case V_154 :
F_76 ( V_155 , V_156 ) ;
case V_157 :
F_76 ( V_158 , V_159 ) ;
case V_160 :
F_76 ( V_161 , V_162 ) ;
case V_163 :
F_76 ( V_164 , V_165 ) ;
case V_166 :
F_76 ( V_167 , V_168 ) ;
case V_169 :
F_76 ( V_170 , V_171 ) ;
case V_172 :
F_76 ( V_173 , V_174 ) ;
case V_175 :
F_76 ( V_176 , V_177 ) ;
case V_178 :
F_76 ( V_179 , V_180 ) ;
case V_181 :
case V_45 :
return F_27 ( V_6 , V_134 , V_44 ) ;
default:
F_20 ( L_19 , V_36 , V_134 ) ;
return - V_55 ;
}
#undef F_76
}
int T_8 F_77 ( void )
{
int error ;
V_18 = F_34 ( V_114 ,
V_182 ,
- 1 , V_50 , NULL ) ;
if ( F_36 ( V_18 ) ) {
error = F_37 ( V_18 ) ;
F_78 ( L_20 ,
error ) ;
return error ;
}
error = F_79 ( & V_183 ) ;
if ( error ) {
F_78 ( L_21 ,
V_183 . V_184 ,
V_185 , V_183 . V_186 ,
error ) ;
F_78 ( L_22 ) ;
F_8 ( V_18 ) ;
return error ;
}
F_80 ( L_23 ,
V_183 . V_184 , V_185 , V_183 . V_186 ) ;
V_1 = true ;
return 0 ;
}
void T_9 F_81 ( void )
{
int error ;
V_1 = false ;
error = F_82 ( & V_183 ) ;
if ( error )
F_78 ( L_24 , error ) ;
F_8 ( V_18 ) ;
F_83 () ;
F_84 ( L_25 ) ;
}
