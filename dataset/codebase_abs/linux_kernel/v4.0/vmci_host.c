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
int V_27 ;
if ( V_14 -> V_34 ) {
F_20 ( L_1 , V_35 ) ;
return V_36 ;
}
F_21 ( sizeof( bool ) != sizeof( V_37 ) ) ;
if ( ! F_22 ( V_38 , ( void T_2 * ) V_33 , sizeof( V_37 ) ) )
return V_39 ;
V_27 = F_23 ( V_33 , 1 , 1 , & V_14 -> V_34 ) ;
if ( V_27 != 1 ) {
V_14 -> V_34 = NULL ;
return V_39 ;
}
V_14 -> V_40 = F_24 ( V_14 -> V_34 ) + ( V_33 & ( V_41 - 1 ) ) ;
F_25 ( V_14 ) ;
return V_32 ;
}
static int F_26 ( struct V_6 * V_6 ,
unsigned int V_42 , void T_2 * V_43 )
{
if ( V_42 == V_44 ) {
int T_2 * V_45 = V_43 ;
if ( F_27 ( V_6 -> V_46 , V_45 ) )
return - V_47 ;
}
if ( V_6 -> V_46 > 0 &&
V_6 -> V_46 < V_48 ) {
return V_6 -> V_46 ;
}
return V_49 ;
}
static int F_28 ( struct V_6 * V_6 ,
const char * V_50 ,
void T_2 * V_43 )
{
struct V_51 V_52 ;
const struct V_53 * V_53 ;
int V_27 ;
if ( F_29 ( & V_52 , V_43 , sizeof( V_52 ) ) ) {
F_30 ( L_2 ) ;
return - V_47 ;
}
F_31 ( & V_6 -> V_11 ) ;
if ( V_6 -> V_9 != V_10 ) {
F_30 ( L_3 ) ;
V_27 = - V_54 ;
goto V_55;
}
if ( V_52 . V_56 & ~ V_57 ) {
F_30 ( L_4 ) ;
V_27 = - V_54 ;
goto V_55;
}
V_53 = F_32 () ;
V_6 -> V_14 = F_33 ( V_52 . V_58 ,
V_52 . V_56 , 0 ,
V_6 -> V_46 ,
V_53 ) ;
F_34 ( V_53 ) ;
if ( F_35 ( V_6 -> V_14 ) ) {
V_27 = F_36 ( V_6 -> V_14 ) ;
F_30 ( L_5 ) ;
goto V_55;
}
V_52 . V_58 = F_37 ( V_6 -> V_14 ) ;
if ( F_17 ( V_43 , & V_52 , sizeof( V_52 ) ) ) {
F_8 ( V_6 -> V_14 ) ;
V_6 -> V_14 = NULL ;
F_30 ( L_6 ) ;
V_27 = - V_47 ;
goto V_55;
}
V_6 -> V_9 = V_13 ;
F_38 ( & V_2 ) ;
V_27 = 0 ;
V_55:
F_39 ( & V_6 -> V_11 ) ;
return V_27 ;
}
static int F_40 ( struct V_6 * V_6 ,
const char * V_50 ,
void T_2 * V_43 )
{
struct V_59 V_60 ;
struct V_61 * V_62 = NULL ;
T_4 V_58 ;
if ( V_6 -> V_9 != V_13 ) {
F_30 ( L_7 ) ;
return - V_54 ;
}
if ( F_29 ( & V_60 , V_43 , sizeof( V_60 ) ) )
return - V_47 ;
if ( V_60 . V_63 > V_64 ) {
F_30 ( L_8 ,
V_60 . V_63 ) ;
return - V_54 ;
}
if ( V_60 . V_63 < sizeof( * V_62 ) ) {
F_30 ( L_9 ,
V_60 . V_63 ) ;
return - V_54 ;
}
V_62 = F_41 ( V_60 . V_63 , V_7 ) ;
if ( ! V_62 ) {
F_30 (
L_10 ) ;
return - V_8 ;
}
if ( F_29 ( V_62 , ( void T_2 * ) ( V_65 ) V_60 . V_66 ,
V_60 . V_63 ) ) {
F_30 ( L_11 ) ;
F_10 ( V_62 ) ;
return - V_47 ;
}
F_20 ( L_12 ,
V_62 -> V_67 . V_14 , V_62 -> V_67 . V_68 ,
V_62 -> V_69 . V_14 , V_62 -> V_69 . V_68 ,
( unsigned long long ) V_62 -> V_70 ) ;
V_58 = F_37 ( V_6 -> V_14 ) ;
V_60 . V_71 = F_42 ( V_58 , V_62 , true ) ;
F_10 ( V_62 ) ;
return F_17 ( V_43 , & V_60 , sizeof( V_60 ) ) ? - V_47 : 0 ;
}
static int F_43 ( struct V_6 * V_6 ,
const char * V_50 ,
void T_2 * V_43 )
{
struct V_59 V_72 ;
struct V_61 * V_62 = NULL ;
int V_27 ;
T_5 V_73 ;
if ( V_6 -> V_9 != V_13 ) {
F_30 ( L_7 ) ;
return - V_54 ;
}
if ( F_29 ( & V_72 , V_43 , sizeof( V_72 ) ) )
return - V_47 ;
V_73 = V_72 . V_63 ;
V_72 . V_71 = F_44 ( V_6 -> V_14 ,
& V_73 , & V_62 ) ;
if ( V_72 . V_71 >= V_32 ) {
void T_2 * V_74 = ( void T_2 * ) ( V_65 ) V_72 . V_66 ;
V_27 = F_17 ( V_74 , V_62 , F_45 ( V_62 ) ) ;
F_10 ( V_62 ) ;
if ( V_27 != 0 )
return - V_47 ;
}
return F_17 ( V_43 , & V_72 , sizeof( V_72 ) ) ? - V_47 : 0 ;
}
static int F_46 ( struct V_6 * V_6 ,
const char * V_50 ,
void T_2 * V_43 )
{
struct V_29 V_75 ;
int V_76 ;
int T_2 * V_77 ;
T_4 V_58 ;
if ( V_6 -> V_9 != V_13 ) {
F_30 ( L_7 ) ;
return - V_54 ;
}
V_58 = F_37 ( V_6 -> V_14 ) ;
if ( V_6 -> V_46 < V_78 ) {
struct V_79 V_80 ;
struct V_79 T_2 * V_81 = V_43 ;
if ( F_29 ( & V_80 , V_43 , sizeof( V_80 ) ) )
return - V_47 ;
V_75 = V_80 . V_75 ;
V_77 = & V_81 -> V_71 ;
V_76 = F_47 ( V_80 . V_75 ,
V_80 . V_82 ,
V_80 . V_56 ,
V_83 ,
V_80 . V_84 ,
V_80 . V_85 ,
NULL ,
V_6 -> V_14 ) ;
if ( V_76 == V_32 )
V_76 = V_86 ;
} else {
struct V_87 V_80 ;
struct V_87 T_2 * V_81 = V_43 ;
struct V_88 V_89 ;
if ( F_29 ( & V_80 , V_43 , sizeof( V_80 ) ) )
return - V_47 ;
V_75 = V_80 . V_75 ;
V_77 = & V_81 -> V_71 ;
V_89 . V_90 = V_80 . V_91 ;
V_89 . V_63 = V_80 . V_92 ;
V_76 = F_47 ( V_80 . V_75 ,
V_80 . V_82 ,
V_80 . V_56 ,
V_83 ,
V_80 . V_84 ,
V_80 . V_85 ,
& V_89 ,
V_6 -> V_14 ) ;
}
if ( F_48 ( V_76 , V_77 ) ) {
if ( V_76 >= V_32 ) {
V_76 = F_49 ( V_75 ,
V_6 -> V_14 ) ;
}
return - V_47 ;
}
return 0 ;
}
static int F_50 ( struct V_6 * V_6 ,
const char * V_50 ,
void T_2 * V_43 )
{
struct V_93 V_94 ;
struct V_93 T_2 * V_81 = V_43 ;
T_6 V_71 ;
if ( V_6 -> V_9 != V_13 ) {
F_30 ( L_7 ) ;
return - V_54 ;
}
if ( V_6 -> V_46 < V_78 ) {
F_30 ( L_13 ) ;
return - V_54 ;
}
if ( F_29 ( & V_94 , V_43 , sizeof( V_94 ) ) )
return - V_47 ;
if ( V_94 . V_95 ) {
V_71 = F_51 ( V_94 . V_75 ,
V_6 -> V_14 ,
V_94 . V_95 ) ;
} else {
V_71 = F_52 ( V_94 . V_75 ,
V_6 -> V_14 , 0 ) ;
}
return F_48 ( V_71 , & V_81 -> V_71 ) ? - V_47 : 0 ;
}
static int F_53 ( struct V_6 * V_6 ,
const char * V_50 ,
void T_2 * V_43 )
{
struct V_96 V_97 ;
struct V_96 T_2 * V_81 = V_43 ;
T_6 V_71 ;
if ( V_6 -> V_46 < V_48 ||
V_6 -> V_46 >= V_78 ) {
F_30 ( L_14 ,
V_6 -> V_46 ) ;
return - V_54 ;
}
if ( V_6 -> V_9 != V_13 ) {
F_30 ( L_7 ) ;
return - V_54 ;
}
if ( F_29 ( & V_97 , V_43 , sizeof( * V_81 ) ) )
return - V_47 ;
if ( F_48 ( V_32 , & V_81 -> V_71 ) ) {
return - V_47 ;
}
V_71 = F_54 ( V_97 . V_75 ,
V_97 . V_98 ,
V_97 . V_99 ,
V_6 -> V_14 ) ;
if ( V_71 < V_32 ) {
if ( F_48 ( V_71 , & V_81 -> V_71 ) ) {
return - V_47 ;
}
}
return 0 ;
}
static int F_55 ( struct V_6 * V_6 ,
const char * V_50 ,
void T_2 * V_43 )
{
struct V_100 V_101 ;
struct V_100 T_2 * V_81 = V_43 ;
T_6 V_71 ;
if ( V_6 -> V_9 != V_13 ) {
F_30 ( L_7 ) ;
return - V_54 ;
}
if ( F_29 ( & V_101 , V_43 , sizeof( V_101 ) ) )
return - V_47 ;
V_71 = F_49 ( V_101 . V_75 ,
V_6 -> V_14 ) ;
if ( V_71 == V_32 &&
V_6 -> V_46 < V_78 ) {
V_71 = V_102 ;
}
return F_48 ( V_71 , & V_81 -> V_71 ) ? - V_47 : 0 ;
}
static int F_56 ( struct V_6 * V_6 ,
const char * V_50 ,
void T_2 * V_43 )
{
struct V_103 V_104 ;
struct V_103 T_2 * V_81 = V_43 ;
T_6 V_71 ;
T_4 V_58 ;
if ( V_6 -> V_9 != V_13 ) {
F_30 ( L_7 ) ;
return - V_54 ;
}
if ( F_29 ( & V_104 , V_43 , sizeof( V_104 ) ) )
return - V_47 ;
V_58 = F_37 ( V_6 -> V_14 ) ;
V_71 = F_57 ( V_58 , V_104 . V_105 ) ;
return F_48 ( V_71 , & V_81 -> V_71 ) ? - V_47 : 0 ;
}
static int F_58 ( struct V_6 * V_6 ,
const char * V_50 ,
void T_2 * V_43 )
{
struct V_103 V_104 ;
struct V_103 T_2 * V_81 = V_43 ;
T_4 V_58 ;
int V_71 ;
if ( V_6 -> V_9 != V_13 ) {
F_30 ( L_7 ) ;
return - V_54 ;
}
if ( F_29 ( & V_104 , V_43 , sizeof( V_104 ) ) )
return - V_47 ;
V_58 = F_37 ( V_6 -> V_14 ) ;
V_71 = F_59 ( V_58 ,
V_104 . V_105 ) ;
return F_48 ( V_71 , & V_81 -> V_71 ) ? - V_47 : 0 ;
}
static int F_60 ( struct V_6 * V_6 ,
const char * V_50 ,
void T_2 * V_43 )
{
struct V_106 V_107 ;
T_4 V_58 ;
void * V_108 ;
int V_27 ;
if ( V_6 -> V_9 != V_13 ) {
F_30 ( L_7 ) ;
return - V_54 ;
}
if ( F_29 ( & V_107 , V_43 , sizeof( V_107 ) ) )
return - V_47 ;
V_58 = F_37 ( V_6 -> V_14 ) ;
V_107 . V_71 = F_61 ( V_58 , V_107 . V_109 ,
& V_107 . V_110 , & V_108 ) ;
if ( V_107 . V_71 == V_32 && V_107 . V_110 ) {
void T_2 * V_74 = ( void T_2 * ) ( V_65 ) V_107 . V_108 ;
V_27 = F_17 ( V_74 , V_108 , V_107 . V_110 ) ;
F_10 ( V_108 ) ;
if ( V_27 )
return - V_47 ;
}
return F_17 ( V_43 , & V_107 , sizeof( V_107 ) ) ? - V_47 : 0 ;
}
static int F_62 ( struct V_6 * V_6 ,
const char * V_50 ,
void T_2 * V_43 )
{
struct V_106 V_111 ;
T_4 V_58 ;
void * V_108 ;
int V_27 ;
if ( V_6 -> V_9 != V_13 ) {
F_30 ( L_7 ) ;
return - V_54 ;
}
if ( F_29 ( & V_111 , V_43 , sizeof( V_111 ) ) )
return - V_47 ;
V_108 = F_41 ( V_111 . V_110 , V_7 ) ;
if ( ! V_108 ) {
F_30 (
L_15 ,
V_111 . V_109 ) ;
return - V_8 ;
}
if ( F_29 ( V_108 , ( void T_2 * ) ( V_65 ) V_111 . V_108 ,
V_111 . V_110 ) ) {
V_27 = - V_47 ;
goto V_55;
}
V_58 = F_37 ( V_6 -> V_14 ) ;
V_111 . V_71 = F_63 ( V_58 , V_111 . V_109 ,
V_111 . V_110 , V_108 ) ;
V_27 = F_17 ( V_43 , & V_111 , sizeof( V_111 ) ) ? - V_47 : 0 ;
V_55:
F_10 ( V_108 ) ;
return V_27 ;
}
static int F_64 ( struct V_6 * V_6 ,
const char * V_50 ,
void T_2 * V_43 )
{
T_4 T_2 * V_112 = V_43 ;
return F_48 ( V_113 , V_112 ) ? - V_47 : 0 ;
}
static int F_65 ( struct V_6 * V_6 ,
const char * V_50 ,
void T_2 * V_43 )
{
struct V_114 V_115 ;
if ( V_6 -> V_9 != V_13 ) {
F_30 ( L_7 ) ;
return - V_54 ;
}
if ( F_29 ( & V_115 , V_43 , sizeof( V_115 ) ) )
return - V_47 ;
if ( V_115 . V_116 ) {
V_115 . V_71 =
F_19 ( V_6 -> V_14 ,
V_115 . V_116 ) ;
} else {
F_66 ( V_6 -> V_14 ) ;
V_115 . V_71 = V_32 ;
}
return F_17 ( V_43 , & V_115 , sizeof( V_115 ) ) ?
- V_47 : 0 ;
}
static int F_67 ( struct V_6 * V_6 ,
const char * V_50 ,
void T_2 * V_43 )
{
struct V_117 V_81 ;
T_4 V_58 ;
if ( V_6 -> V_46 < V_118 ) {
F_30 ( L_16 ) ;
return - V_54 ;
}
if ( V_6 -> V_9 != V_13 ) {
F_30 ( L_7 ) ;
return - V_54 ;
}
if ( F_29 ( & V_81 , V_43 , sizeof( V_81 ) ) )
return - V_47 ;
V_58 = F_37 ( V_6 -> V_14 ) ;
switch ( V_81 . V_119 ) {
case V_120 :
if ( V_81 . V_68 == V_121 ) {
T_4 V_56 = V_83 ;
V_81 . V_71 = F_68 ( V_58 , V_81 . V_75 ,
V_56 ) ;
} else {
V_81 . V_71 = V_122 ;
}
break;
case V_123 :
V_81 . V_71 = F_69 ( V_58 , V_81 . V_75 ) ;
break;
case V_124 :
V_81 . V_71 = F_70 ( V_58 , V_81 . V_75 ) ;
break;
default:
F_30 ( L_17 ,
V_81 . V_119 ) ;
V_81 . V_71 = V_125 ;
}
return F_17 ( V_43 , & V_81 , sizeof( V_81 ) ) ? - V_47 : 0 ;
}
static int F_71 ( struct V_6 * V_6 ,
const char * V_50 ,
void T_2 * V_43 )
{
struct V_126 V_81 ;
struct V_25 * V_127 ;
struct V_25 * V_128 ;
void T_2 * V_74 ;
T_4 V_58 ;
int V_27 = 0 ;
if ( V_6 -> V_9 != V_13 ) {
F_30 ( L_7 ) ;
return - V_54 ;
}
if ( V_6 -> V_46 < V_118 ) {
F_30 ( L_18 ) ;
return - V_54 ;
}
if ( F_29 ( & V_81 , V_43 , sizeof( V_81 ) ) )
return - V_47 ;
if ( ( V_81 . V_129 && ! V_81 . V_130 ) ||
( V_81 . V_131 && ! V_81 . V_132 ) ) {
return - V_54 ;
}
V_58 = F_37 ( V_6 -> V_14 ) ;
V_81 . V_71 = F_72 ( V_58 ,
& V_127 , & V_128 ) ;
if ( V_81 . V_71 != V_32 )
return F_17 ( V_43 , & V_81 , sizeof( V_81 ) ) ? - V_47 : 0 ;
V_74 = ( void T_2 * ) ( V_65 ) V_81 . V_130 ;
V_81 . V_71 = F_16 ( V_74 , & V_81 . V_129 ,
V_127 , & V_27 ) ;
if ( V_81 . V_71 == V_32 && ! V_27 ) {
V_74 = ( void T_2 * ) ( V_65 ) V_81 . V_132 ;
V_81 . V_71 = F_16 ( V_74 ,
& V_81 . V_131 ,
V_128 , & V_27 ) ;
}
if ( ! V_27 && F_17 ( V_43 , & V_81 , sizeof( V_81 ) ) )
V_27 = - V_47 ;
F_73 ( V_58 ,
V_127 , V_128 ,
V_81 . V_71 == V_32 && ! V_27 ) ;
return V_27 ;
}
static long F_74 ( struct V_4 * V_5 ,
unsigned int V_133 , unsigned long V_134 )
{
#define F_75 ( V_50 , T_7 ) do { \
char *name = __stringify(IOCTL_VMCI_ ## ioctl_name); \
return vmci_host_do_ ## ioctl_fn( \
vmci_host_dev, name, uptr); \
} while (0)
struct V_6 * V_6 = V_5 -> V_12 ;
void T_2 * V_43 = ( void T_2 * ) V_134 ;
switch ( V_133 ) {
case V_135 :
F_75 ( V_136 , V_137 ) ;
case V_138 :
F_75 ( V_139 , V_140 ) ;
case V_141 :
F_75 ( V_142 , V_143 ) ;
case V_144 :
F_75 ( V_145 , V_146 ) ;
case V_147 :
F_75 ( V_148 , V_149 ) ;
case V_150 :
F_75 ( V_151 , V_152 ) ;
case V_153 :
F_75 ( V_154 , V_155 ) ;
case V_156 :
F_75 ( V_157 , V_158 ) ;
case V_159 :
F_75 ( V_160 , V_161 ) ;
case V_162 :
F_75 ( V_163 , V_164 ) ;
case V_165 :
F_75 ( V_166 , V_167 ) ;
case V_168 :
F_75 ( V_169 , V_170 ) ;
case V_171 :
F_75 ( V_172 , V_173 ) ;
case V_174 :
F_75 ( V_175 , V_176 ) ;
case V_177 :
F_75 ( V_178 , V_179 ) ;
case V_180 :
case V_44 :
return F_26 ( V_6 , V_133 , V_43 ) ;
default:
F_20 ( L_19 , V_35 , V_133 ) ;
return - V_54 ;
}
#undef F_75
}
int T_8 F_76 ( void )
{
int error ;
V_18 = F_33 ( V_113 ,
V_181 ,
- 1 , V_49 , NULL ) ;
if ( F_35 ( V_18 ) ) {
error = F_36 ( V_18 ) ;
F_77 ( L_20 ,
error ) ;
return error ;
}
error = F_78 ( & V_182 ) ;
if ( error ) {
F_77 ( L_21 ,
V_182 . V_183 ,
V_184 , V_182 . V_185 ,
error ) ;
F_77 ( L_22 ) ;
F_8 ( V_18 ) ;
return error ;
}
F_79 ( L_23 ,
V_182 . V_183 , V_184 , V_182 . V_185 ) ;
V_1 = true ;
return 0 ;
}
void T_9 F_80 ( void )
{
int error ;
V_1 = false ;
error = F_81 ( & V_182 ) ;
if ( error )
F_77 ( L_24 , error ) ;
F_8 ( V_18 ) ;
F_82 () ;
F_83 ( L_25 ) ;
}
