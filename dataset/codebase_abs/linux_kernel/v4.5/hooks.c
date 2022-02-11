static int T_1 F_1 ( char * V_1 )
{
unsigned long V_2 ;
if ( ! F_2 ( V_1 , 0 , & V_2 ) )
V_3 = V_2 ? 1 : 0 ;
return 1 ;
}
static int T_1 F_3 ( char * V_1 )
{
unsigned long V_4 ;
if ( ! F_2 ( V_1 , 0 , & V_4 ) )
V_5 = V_4 ? 1 : 0 ;
return 1 ;
}
static int F_4 ( void )
{
return ( V_6 || F_5 ( & V_7 ) ) ;
}
static int F_6 ( void )
{
return ( V_6 || F_7 () || F_8 () ) ;
}
static int F_9 ( T_2 V_8 )
{
if ( V_8 == V_9 ) {
F_10 () ;
F_11 () ;
F_12 () ;
F_13 () ;
}
return 0 ;
}
static void F_14 ( void )
{
struct V_10 * V_10 = (struct V_10 * ) V_11 -> V_12 ;
struct V_13 * V_14 ;
V_14 = F_15 ( sizeof( struct V_13 ) , V_15 ) ;
if ( ! V_14 )
F_16 ( L_1 ) ;
V_14 -> V_16 = V_14 -> V_17 = V_18 ;
V_10 -> V_19 = V_14 ;
}
static inline T_2 F_17 ( const struct V_10 * V_10 )
{
const struct V_13 * V_14 ;
V_14 = V_10 -> V_19 ;
return V_14 -> V_17 ;
}
static inline T_2 F_18 ( const struct V_20 * V_21 )
{
T_2 V_17 ;
F_19 () ;
V_17 = F_17 ( F_20 ( V_21 ) ) ;
F_21 () ;
return V_17 ;
}
static inline T_2 F_22 ( void )
{
const struct V_13 * V_14 = F_23 () ;
return V_14 -> V_17 ;
}
static int F_24 ( struct V_22 * V_22 )
{
struct V_23 * V_24 ;
T_2 V_17 = F_22 () ;
V_24 = F_25 ( V_25 , V_26 ) ;
if ( ! V_24 )
return - V_27 ;
F_26 ( & V_24 -> V_28 ) ;
F_27 ( & V_24 -> V_29 ) ;
V_24 -> V_22 = V_22 ;
V_24 -> V_17 = V_30 ;
V_24 -> V_31 = V_32 ;
V_24 -> F_18 = V_17 ;
V_22 -> V_33 = V_24 ;
return 0 ;
}
static int F_28 ( struct V_22 * V_22 ,
struct V_34 * V_35 ,
bool V_36 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
F_29 ( V_36 ) ;
if ( V_24 -> V_37 == V_38 ) {
if ( ! V_36 )
return - V_39 ;
F_30 ( V_22 , V_35 ) ;
}
return 0 ;
}
static struct V_23 * F_31 ( struct V_22 * V_22 )
{
return V_22 -> V_33 ;
}
static struct V_23 * F_32 ( struct V_22 * V_22 , bool V_40 )
{
int error ;
error = F_28 ( V_22 , NULL , ! V_40 ) ;
if ( error )
return F_33 ( error ) ;
return V_22 -> V_33 ;
}
static struct V_23 * F_34 ( struct V_22 * V_22 )
{
F_28 ( V_22 , NULL , true ) ;
return V_22 -> V_33 ;
}
static struct V_23 * F_35 ( struct V_34 * V_34 )
{
struct V_22 * V_22 = F_36 ( V_34 ) ;
F_28 ( V_22 , V_34 , true ) ;
return V_22 -> V_33 ;
}
static void F_37 ( struct V_41 * V_42 )
{
struct V_23 * V_24 ;
V_24 = F_38 ( V_42 , struct V_23 , V_40 ) ;
F_39 ( V_25 , V_24 ) ;
}
static void F_40 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_43 * V_44 = V_22 -> V_45 -> V_46 ;
if ( ! F_41 ( & V_24 -> V_29 ) ) {
F_42 ( & V_44 -> V_47 ) ;
F_43 ( & V_24 -> V_29 ) ;
F_44 ( & V_44 -> V_47 ) ;
}
F_45 ( & V_24 -> V_40 , F_37 ) ;
}
static int F_46 ( struct V_48 * V_48 )
{
struct V_49 * V_50 ;
T_2 V_17 = F_22 () ;
V_50 = F_25 ( V_51 , V_15 ) ;
if ( ! V_50 )
return - V_27 ;
V_50 -> V_17 = V_17 ;
V_50 -> V_52 = V_17 ;
V_48 -> V_53 = V_50 ;
return 0 ;
}
static void F_47 ( struct V_48 * V_48 )
{
struct V_49 * V_50 = V_48 -> V_53 ;
V_48 -> V_53 = NULL ;
F_39 ( V_51 , V_50 ) ;
}
static int F_48 ( struct V_54 * V_55 )
{
struct V_43 * V_44 ;
V_44 = F_15 ( sizeof( struct V_43 ) , V_15 ) ;
if ( ! V_44 )
return - V_27 ;
F_26 ( & V_44 -> V_28 ) ;
F_27 ( & V_44 -> V_56 ) ;
F_49 ( & V_44 -> V_47 ) ;
V_44 -> V_55 = V_55 ;
V_44 -> V_17 = V_30 ;
V_44 -> V_57 = V_58 ;
V_44 -> V_59 = V_30 ;
V_55 -> V_46 = V_44 ;
return 0 ;
}
static void F_50 ( struct V_54 * V_55 )
{
struct V_43 * V_44 = V_55 -> V_46 ;
V_55 -> V_46 = NULL ;
F_51 ( V_44 ) ;
}
static inline int F_52 ( struct V_22 * V_22 )
{
return F_30 ( V_22 , NULL ) ;
}
static int F_53 ( T_2 V_17 ,
struct V_43 * V_44 ,
const struct V_10 * V_10 )
{
const struct V_13 * V_14 = V_10 -> V_19 ;
int V_60 ;
V_60 = F_54 ( V_14 -> V_17 , V_44 -> V_17 , V_61 ,
V_62 , NULL ) ;
if ( V_60 )
return V_60 ;
V_60 = F_54 ( V_14 -> V_17 , V_17 , V_61 ,
V_63 , NULL ) ;
return V_60 ;
}
static int F_55 ( T_2 V_17 ,
struct V_43 * V_44 ,
const struct V_10 * V_10 )
{
const struct V_13 * V_14 = V_10 -> V_19 ;
int V_60 ;
V_60 = F_54 ( V_14 -> V_17 , V_44 -> V_17 , V_61 ,
V_62 , NULL ) ;
if ( V_60 )
return V_60 ;
V_60 = F_54 ( V_17 , V_44 -> V_17 , V_61 ,
V_64 , NULL ) ;
return V_60 ;
}
static int F_56 ( struct V_54 * V_55 )
{
struct V_43 * V_44 = V_55 -> V_46 ;
return V_44 -> V_65 == V_66 ||
V_44 -> V_65 == V_67 ||
V_44 -> V_65 == V_68 ||
V_44 -> V_65 == V_69 ||
! strcmp ( V_55 -> V_70 -> V_71 , L_2 ) ||
! strcmp ( V_55 -> V_70 -> V_71 , L_3 ) ||
! strcmp ( V_55 -> V_70 -> V_71 , L_4 ) ||
! strcmp ( V_55 -> V_70 -> V_71 , L_5 ) ;
}
static int F_57 ( struct V_54 * V_55 )
{
struct V_43 * V_44 = V_55 -> V_46 ;
struct V_34 * V_72 = V_55 -> V_73 ;
struct V_22 * V_74 = F_36 ( V_72 ) ;
int V_60 = 0 ;
if ( V_44 -> V_65 == V_66 ) {
if ( ! V_74 -> V_75 -> V_76 ) {
F_58 ( V_77 L_6
L_7 , V_55 -> V_78 , V_55 -> V_70 -> V_71 ) ;
V_60 = - V_79 ;
goto V_80;
}
V_60 = V_74 -> V_75 -> V_76 ( V_72 , V_81 , NULL , 0 ) ;
if ( V_60 < 0 && V_60 != - V_82 ) {
if ( V_60 == - V_79 )
F_58 ( V_77 L_8
L_9 ,
V_55 -> V_78 , V_55 -> V_70 -> V_71 ) ;
else
F_58 ( V_77 L_8
L_10 , V_55 -> V_78 ,
V_55 -> V_70 -> V_71 , - V_60 ) ;
goto V_80;
}
}
if ( V_44 -> V_65 > F_59 ( V_83 ) )
F_58 ( V_84 L_11 ,
V_55 -> V_78 , V_55 -> V_70 -> V_71 ) ;
V_44 -> V_85 |= V_86 ;
if ( F_56 ( V_55 ) )
V_44 -> V_85 |= V_87 ;
V_60 = F_30 ( V_74 , V_72 ) ;
F_42 ( & V_44 -> V_47 ) ;
V_88:
if ( ! F_60 ( & V_44 -> V_56 ) ) {
struct V_23 * V_24 =
F_61 ( V_44 -> V_56 . V_89 ,
struct V_23 , V_29 ) ;
struct V_22 * V_22 = V_24 -> V_22 ;
F_43 ( & V_24 -> V_29 ) ;
F_44 ( & V_44 -> V_47 ) ;
V_22 = F_62 ( V_22 ) ;
if ( V_22 ) {
if ( ! F_63 ( V_22 ) )
F_52 ( V_22 ) ;
F_64 ( V_22 ) ;
}
F_42 ( & V_44 -> V_47 ) ;
goto V_88;
}
F_44 ( & V_44 -> V_47 ) ;
V_80:
return V_60 ;
}
static int F_65 ( const struct V_54 * V_55 ,
struct V_90 * V_91 )
{
int V_60 = 0 , V_92 ;
struct V_43 * V_44 = V_55 -> V_46 ;
char * V_93 = NULL ;
T_2 V_94 ;
char V_95 ;
F_66 ( V_91 ) ;
if ( ! ( V_44 -> V_85 & V_86 ) )
return - V_96 ;
if ( ! V_97 )
return - V_96 ;
F_67 ( V_98 >= ( 1 << V_99 ) ) ;
V_95 = V_44 -> V_85 & V_98 ;
for ( V_92 = 0 ; V_92 < V_99 ; V_92 ++ ) {
if ( V_95 & 0x01 )
V_91 -> V_100 ++ ;
V_95 >>= 1 ;
}
if ( V_44 -> V_85 & V_87 )
V_91 -> V_100 ++ ;
V_91 -> V_101 = F_68 ( V_91 -> V_100 , sizeof( char * ) , V_102 ) ;
if ( ! V_91 -> V_101 ) {
V_60 = - V_27 ;
goto V_103;
}
V_91 -> V_104 = F_68 ( V_91 -> V_100 , sizeof( int ) , V_102 ) ;
if ( ! V_91 -> V_104 ) {
V_60 = - V_27 ;
goto V_103;
}
V_92 = 0 ;
if ( V_44 -> V_85 & V_105 ) {
V_60 = F_69 ( V_44 -> V_17 , & V_93 , & V_94 ) ;
if ( V_60 )
goto V_103;
V_91 -> V_101 [ V_92 ] = V_93 ;
V_91 -> V_104 [ V_92 ++ ] = V_105 ;
}
if ( V_44 -> V_85 & V_106 ) {
V_60 = F_69 ( V_44 -> V_59 , & V_93 , & V_94 ) ;
if ( V_60 )
goto V_103;
V_91 -> V_101 [ V_92 ] = V_93 ;
V_91 -> V_104 [ V_92 ++ ] = V_106 ;
}
if ( V_44 -> V_85 & V_107 ) {
V_60 = F_69 ( V_44 -> V_57 , & V_93 , & V_94 ) ;
if ( V_60 )
goto V_103;
V_91 -> V_101 [ V_92 ] = V_93 ;
V_91 -> V_104 [ V_92 ++ ] = V_107 ;
}
if ( V_44 -> V_85 & V_108 ) {
struct V_34 * V_72 = V_44 -> V_55 -> V_73 ;
struct V_23 * V_24 = F_35 ( V_72 ) ;
V_60 = F_69 ( V_24 -> V_17 , & V_93 , & V_94 ) ;
if ( V_60 )
goto V_103;
V_91 -> V_101 [ V_92 ] = V_93 ;
V_91 -> V_104 [ V_92 ++ ] = V_108 ;
}
if ( V_44 -> V_85 & V_87 ) {
V_91 -> V_101 [ V_92 ] = NULL ;
V_91 -> V_104 [ V_92 ++ ] = V_87 ;
}
F_70 ( V_92 != V_91 -> V_100 ) ;
return 0 ;
V_103:
F_71 ( V_91 ) ;
return V_60 ;
}
static int F_72 ( struct V_43 * V_44 , char V_109 ,
T_2 V_110 , T_2 V_111 )
{
char V_112 = V_44 -> V_85 & V_98 ;
if ( V_44 -> V_85 & V_86 )
if ( ! ( V_44 -> V_85 & V_109 ) ||
( V_110 != V_111 ) )
return 1 ;
if ( ! ( V_44 -> V_85 & V_86 ) )
if ( V_112 & V_109 )
return 1 ;
return 0 ;
}
static int F_73 ( struct V_54 * V_55 ,
struct V_90 * V_91 ,
unsigned long V_113 ,
unsigned long * V_114 )
{
const struct V_10 * V_10 = F_74 () ;
int V_60 = 0 , V_92 ;
struct V_43 * V_44 = V_55 -> V_46 ;
const char * V_71 = V_55 -> V_70 -> V_71 ;
struct V_34 * V_72 = V_44 -> V_55 -> V_73 ;
struct V_23 * V_115 = F_35 ( V_72 ) ;
T_2 V_116 = 0 , V_117 = 0 , V_118 = 0 ;
T_2 V_119 = 0 ;
char * * V_120 = V_91 -> V_101 ;
int * V_85 = V_91 -> V_104 ;
int V_121 = V_91 -> V_100 ;
F_75 ( & V_44 -> V_28 ) ;
if ( ! V_97 ) {
if ( ! V_121 ) {
goto V_80;
}
V_60 = - V_96 ;
F_58 ( V_77 L_12
L_13 ) ;
goto V_80;
}
if ( V_113 && ! V_114 ) {
V_60 = - V_96 ;
goto V_80;
}
if ( ( V_44 -> V_85 & V_86 ) && ( V_55 -> V_70 -> V_122 & V_123 )
&& ( V_121 == 0 ) )
goto V_80;
for ( V_92 = 0 ; V_92 < V_121 ; V_92 ++ ) {
T_2 V_17 ;
if ( V_85 [ V_92 ] == V_87 )
continue;
V_60 = F_76 ( V_120 [ V_92 ] , & V_17 , V_15 ) ;
if ( V_60 ) {
F_58 ( V_77 L_14
L_15 ,
V_120 [ V_92 ] , V_55 -> V_78 , V_71 , V_60 ) ;
goto V_80;
}
switch ( V_85 [ V_92 ] ) {
case V_105 :
V_116 = V_17 ;
if ( F_72 ( V_44 , V_105 , V_44 -> V_17 ,
V_116 ) )
goto V_124;
V_44 -> V_85 |= V_105 ;
break;
case V_106 :
V_117 = V_17 ;
if ( F_72 ( V_44 , V_106 , V_44 -> V_59 ,
V_117 ) )
goto V_124;
V_44 -> V_85 |= V_106 ;
break;
case V_108 :
V_118 = V_17 ;
if ( F_72 ( V_44 , V_108 , V_115 -> V_17 ,
V_118 ) )
goto V_124;
V_44 -> V_85 |= V_108 ;
break;
case V_107 :
V_119 = V_17 ;
if ( F_72 ( V_44 , V_107 , V_44 -> V_57 ,
V_119 ) )
goto V_124;
V_44 -> V_85 |= V_107 ;
break;
default:
V_60 = - V_96 ;
goto V_80;
}
}
if ( V_44 -> V_85 & V_86 ) {
if ( ( V_44 -> V_85 & V_98 ) && ! V_121 )
goto V_124;
V_60 = 0 ;
goto V_80;
}
if ( strcmp ( V_55 -> V_70 -> V_71 , L_16 ) == 0 )
V_44 -> V_85 |= V_125 | V_126 ;
if ( ! strcmp ( V_55 -> V_70 -> V_71 , L_4 ) ||
! strcmp ( V_55 -> V_70 -> V_71 , L_2 ) ||
! strcmp ( V_55 -> V_70 -> V_71 , L_3 ) )
V_44 -> V_85 |= V_126 ;
if ( ! V_44 -> V_65 ) {
V_60 = F_77 ( V_55 ) ;
if ( V_60 ) {
F_58 ( V_77
L_17 ,
V_127 , V_55 -> V_70 -> V_71 , V_60 ) ;
goto V_80;
}
}
if ( V_116 ) {
V_60 = F_53 ( V_116 , V_44 , V_10 ) ;
if ( V_60 )
goto V_80;
V_44 -> V_17 = V_116 ;
}
if ( V_113 & V_128 && ! V_117 ) {
V_44 -> V_65 = V_69 ;
* V_114 |= V_128 ;
}
if ( V_117 ) {
if ( ! V_116 ) {
V_60 = F_53 ( V_117 , V_44 ,
V_10 ) ;
if ( V_60 )
goto V_80;
V_44 -> V_17 = V_117 ;
} else {
V_60 = F_55 ( V_117 , V_44 ,
V_10 ) ;
if ( V_60 )
goto V_80;
}
if ( ! V_118 )
V_118 = V_117 ;
V_44 -> V_59 = V_117 ;
V_44 -> V_65 = V_129 ;
}
if ( V_118 ) {
V_60 = F_55 ( V_118 , V_44 ,
V_10 ) ;
if ( V_60 )
goto V_80;
V_115 -> V_17 = V_118 ;
V_115 -> V_37 = V_130 ;
}
if ( V_119 ) {
if ( V_44 -> V_65 != V_66 &&
V_44 -> V_65 != V_69 ) {
V_60 = - V_96 ;
F_58 ( V_77 L_18
L_19 ) ;
goto V_80;
}
if ( V_119 != V_44 -> V_57 ) {
V_60 = F_55 ( V_119 ,
V_44 , V_10 ) ;
if ( V_60 )
goto V_80;
}
V_44 -> V_57 = V_119 ;
}
V_60 = F_57 ( V_55 ) ;
V_80:
F_78 ( & V_44 -> V_28 ) ;
return V_60 ;
V_124:
V_60 = - V_96 ;
F_58 ( V_77 L_20
L_21 , V_55 -> V_78 , V_71 ) ;
goto V_80;
}
static int F_79 ( const struct V_54 * V_131 ,
const struct V_54 * V_132 )
{
struct V_43 * V_133 = V_131 -> V_46 ;
struct V_43 * V_134 = V_132 -> V_46 ;
char V_135 = V_133 -> V_85 & V_98 ;
char V_136 = V_134 -> V_85 & V_98 ;
if ( V_135 != V_136 )
goto V_137;
if ( ( V_135 & V_105 ) && V_133 -> V_17 != V_134 -> V_17 )
goto V_137;
if ( ( V_135 & V_106 ) && V_133 -> V_59 != V_134 -> V_59 )
goto V_137;
if ( ( V_135 & V_107 ) && V_133 -> V_57 != V_134 -> V_57 )
goto V_137;
if ( V_135 & V_108 ) {
struct V_23 * V_138 = F_35 ( V_131 -> V_73 ) ;
struct V_23 * V_139 = F_35 ( V_132 -> V_73 ) ;
if ( V_138 -> V_17 != V_139 -> V_17 )
goto V_137;
}
return 0 ;
V_137:
F_58 ( V_77 L_22
L_23
L_24 , V_132 -> V_78 , V_132 -> V_70 -> V_71 ) ;
return - V_140 ;
}
static int F_80 ( const struct V_54 * V_131 ,
struct V_54 * V_132 )
{
const struct V_43 * V_141 = V_131 -> V_46 ;
struct V_43 * V_142 = V_132 -> V_46 ;
int V_143 = ( V_141 -> V_85 & V_105 ) ;
int V_144 = ( V_141 -> V_85 & V_106 ) ;
int V_145 = ( V_141 -> V_85 & V_108 ) ;
if ( ! V_97 )
return 0 ;
F_70 ( ! ( V_141 -> V_85 & V_86 ) ) ;
if ( V_142 -> V_85 & V_86 )
return F_79 ( V_131 , V_132 ) ;
F_75 ( & V_142 -> V_28 ) ;
V_142 -> V_85 = V_141 -> V_85 ;
V_142 -> V_17 = V_141 -> V_17 ;
V_142 -> V_57 = V_141 -> V_57 ;
V_142 -> V_65 = V_141 -> V_65 ;
if ( V_144 ) {
T_2 V_17 = V_141 -> V_59 ;
if ( ! V_143 )
V_142 -> V_17 = V_17 ;
if ( ! V_145 ) {
struct V_23 * V_146 = F_35 ( V_132 -> V_73 ) ;
V_146 -> V_17 = V_17 ;
}
V_142 -> V_59 = V_17 ;
}
if ( V_145 ) {
const struct V_23 * V_147 = F_35 ( V_131 -> V_73 ) ;
struct V_23 * V_146 = F_35 ( V_132 -> V_73 ) ;
V_146 -> V_17 = V_147 -> V_17 ;
}
F_57 ( V_132 ) ;
F_78 ( & V_142 -> V_28 ) ;
return 0 ;
}
static int F_81 ( char * V_148 ,
struct V_90 * V_91 )
{
char * V_149 ;
char * V_93 = NULL , * V_150 = NULL ;
char * V_151 = NULL , * V_152 = NULL ;
int V_60 , V_100 = 0 ;
V_91 -> V_100 = 0 ;
while ( ( V_149 = F_82 ( & V_148 , L_25 ) ) != NULL ) {
int V_153 ;
T_3 args [ V_154 ] ;
if ( ! * V_149 )
continue;
V_153 = F_83 ( V_149 , V_155 , args ) ;
switch ( V_153 ) {
case V_156 :
if ( V_93 || V_150 ) {
V_60 = - V_96 ;
F_58 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_157;
}
V_93 = F_84 ( & args [ 0 ] ) ;
if ( ! V_93 ) {
V_60 = - V_27 ;
goto V_157;
}
break;
case V_158 :
if ( V_151 ) {
V_60 = - V_96 ;
F_58 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_157;
}
V_151 = F_84 ( & args [ 0 ] ) ;
if ( ! V_151 ) {
V_60 = - V_27 ;
goto V_157;
}
break;
case V_159 :
if ( V_152 ) {
V_60 = - V_96 ;
F_58 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_157;
}
V_152 = F_84 ( & args [ 0 ] ) ;
if ( ! V_152 ) {
V_60 = - V_27 ;
goto V_157;
}
break;
case V_160 :
if ( V_93 || V_150 ) {
V_60 = - V_96 ;
F_58 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_157;
}
V_150 = F_84 ( & args [ 0 ] ) ;
if ( ! V_150 ) {
V_60 = - V_27 ;
goto V_157;
}
break;
case V_161 :
break;
default:
V_60 = - V_96 ;
F_58 ( V_77 L_26 ) ;
goto V_157;
}
}
V_60 = - V_27 ;
V_91 -> V_101 = F_68 ( V_99 , sizeof( char * ) , V_102 ) ;
if ( ! V_91 -> V_101 )
goto V_157;
V_91 -> V_104 = F_68 ( V_99 , sizeof( int ) , V_102 ) ;
if ( ! V_91 -> V_104 ) {
F_51 ( V_91 -> V_101 ) ;
goto V_157;
}
if ( V_151 ) {
V_91 -> V_101 [ V_100 ] = V_151 ;
V_91 -> V_104 [ V_100 ++ ] = V_105 ;
}
if ( V_93 ) {
V_91 -> V_101 [ V_100 ] = V_93 ;
V_91 -> V_104 [ V_100 ++ ] = V_106 ;
}
if ( V_152 ) {
V_91 -> V_101 [ V_100 ] = V_152 ;
V_91 -> V_104 [ V_100 ++ ] = V_108 ;
}
if ( V_150 ) {
V_91 -> V_101 [ V_100 ] = V_150 ;
V_91 -> V_104 [ V_100 ++ ] = V_107 ;
}
V_91 -> V_100 = V_100 ;
return 0 ;
V_157:
F_51 ( V_93 ) ;
F_51 ( V_150 ) ;
F_51 ( V_151 ) ;
F_51 ( V_152 ) ;
return V_60 ;
}
static int F_85 ( struct V_54 * V_55 , void * V_162 )
{
int V_60 = 0 ;
char * V_148 = V_162 ;
struct V_90 V_91 ;
F_66 ( & V_91 ) ;
if ( ! V_162 )
goto V_80;
F_70 ( V_55 -> V_70 -> V_122 & V_123 ) ;
V_60 = F_81 ( V_148 , & V_91 ) ;
if ( V_60 )
goto V_157;
V_80:
V_60 = F_73 ( V_55 , & V_91 , 0 , NULL ) ;
V_157:
F_71 ( & V_91 ) ;
return V_60 ;
}
static void F_86 ( struct V_163 * V_164 ,
struct V_90 * V_91 )
{
int V_92 ;
char * V_165 ;
for ( V_92 = 0 ; V_92 < V_91 -> V_100 ; V_92 ++ ) {
char * V_166 ;
if ( V_91 -> V_101 [ V_92 ] )
V_166 = strchr ( V_91 -> V_101 [ V_92 ] , ',' ) ;
else
V_166 = NULL ;
switch ( V_91 -> V_104 [ V_92 ] ) {
case V_106 :
V_165 = V_167 ;
break;
case V_105 :
V_165 = V_168 ;
break;
case V_108 :
V_165 = V_169 ;
break;
case V_107 :
V_165 = V_170 ;
break;
case V_87 :
F_87 ( V_164 , ',' ) ;
F_88 ( V_164 , V_171 ) ;
continue;
default:
F_89 () ;
return;
} ;
F_87 ( V_164 , ',' ) ;
F_88 ( V_164 , V_165 ) ;
if ( V_166 )
F_87 ( V_164 , '\"' ) ;
F_90 ( V_164 , V_91 -> V_101 [ V_92 ] , L_27 ) ;
if ( V_166 )
F_87 ( V_164 , '\"' ) ;
}
}
static int F_91 ( struct V_163 * V_164 , struct V_54 * V_55 )
{
struct V_90 V_91 ;
int V_60 ;
V_60 = F_65 ( V_55 , & V_91 ) ;
if ( V_60 ) {
if ( V_60 == - V_96 )
V_60 = 0 ;
return V_60 ;
}
F_86 ( V_164 , & V_91 ) ;
F_71 ( & V_91 ) ;
return V_60 ;
}
static inline T_4 F_92 ( T_5 V_172 )
{
switch ( V_172 & V_173 ) {
case V_174 :
return V_175 ;
case V_176 :
return V_177 ;
case V_178 :
return V_32 ;
case V_179 :
return V_180 ;
case V_181 :
return V_182 ;
case V_183 :
return V_184 ;
case V_185 :
return V_186 ;
}
return V_32 ;
}
static inline int F_93 ( int V_187 )
{
return ( V_187 == V_188 || V_187 == V_189 ) ;
}
static inline int F_94 ( int V_187 )
{
return ( V_187 == V_188 || V_187 == V_190 ) ;
}
static inline T_4 F_95 ( int V_191 , int type , int V_187 )
{
switch ( V_191 ) {
case V_192 :
switch ( type ) {
case V_193 :
case V_194 :
return V_195 ;
case V_196 :
return V_197 ;
}
break;
case V_198 :
case V_199 :
switch ( type ) {
case V_193 :
if ( F_93 ( V_187 ) )
return V_200 ;
else
return V_201 ;
case V_196 :
if ( F_94 ( V_187 ) )
return V_202 ;
else
return V_201 ;
case V_203 :
return V_204 ;
default:
return V_201 ;
}
break;
case V_205 :
switch ( V_187 ) {
case V_206 :
return V_207 ;
case V_208 :
return V_209 ;
case V_210 :
return V_211 ;
case V_212 :
return V_213 ;
case V_214 :
return V_215 ;
case V_216 :
return V_217 ;
case V_218 :
return V_219 ;
case V_220 :
return V_221 ;
case V_222 :
return V_223 ;
case V_224 :
return V_225 ;
case V_226 :
return V_227 ;
case V_228 :
return V_229 ;
case V_230 :
return V_231 ;
case V_232 :
return V_233 ;
case V_234 :
return V_235 ;
case V_236 :
return V_237 ;
default:
return V_238 ;
}
case V_239 :
return V_240 ;
case V_241 :
return V_242 ;
case V_243 :
return V_244 ;
}
return V_245 ;
}
static int F_96 ( struct V_34 * V_34 ,
T_4 V_246 ,
T_4 V_85 ,
T_2 * V_17 )
{
int V_60 ;
struct V_54 * V_55 = V_34 -> V_247 -> V_45 ;
char * V_248 , * V_249 ;
V_248 = ( char * ) F_97 ( V_15 ) ;
if ( ! V_248 )
return - V_27 ;
V_249 = F_98 ( V_34 , V_248 , V_250 ) ;
if ( F_99 ( V_249 ) )
V_60 = F_100 ( V_249 ) ;
else {
if ( V_85 & V_125 ) {
while ( V_249 [ 1 ] >= '0' && V_249 [ 1 ] <= '9' ) {
V_249 [ 1 ] = '/' ;
V_249 ++ ;
}
}
V_60 = F_101 ( V_55 -> V_70 -> V_71 , V_249 , V_246 , V_17 ) ;
}
F_102 ( ( unsigned long ) V_248 ) ;
return V_60 ;
}
static int F_30 ( struct V_22 * V_22 , struct V_34 * V_35 )
{
struct V_43 * V_44 = NULL ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 ;
struct V_34 * V_34 ;
#define F_103 255
char * V_93 = NULL ;
unsigned V_94 = 0 ;
int V_60 = 0 ;
if ( V_24 -> V_37 == V_130 )
goto V_80;
F_75 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_37 == V_130 )
goto V_251;
V_44 = V_22 -> V_45 -> V_46 ;
if ( ! ( V_44 -> V_85 & V_86 ) ) {
F_42 ( & V_44 -> V_47 ) ;
if ( F_60 ( & V_24 -> V_29 ) )
F_104 ( & V_24 -> V_29 , & V_44 -> V_56 ) ;
F_44 ( & V_44 -> V_47 ) ;
goto V_251;
}
switch ( V_44 -> V_65 ) {
case V_69 :
break;
case V_66 :
if ( ! V_22 -> V_75 -> V_76 ) {
V_24 -> V_17 = V_44 -> V_57 ;
break;
}
if ( V_35 ) {
V_34 = F_105 ( V_35 ) ;
} else {
V_34 = F_106 ( V_22 ) ;
}
if ( ! V_34 ) {
goto V_251;
}
V_94 = F_103 ;
V_93 = F_107 ( V_94 + 1 , V_26 ) ;
if ( ! V_93 ) {
V_60 = - V_27 ;
F_108 ( V_34 ) ;
goto V_251;
}
V_93 [ V_94 ] = '\0' ;
V_60 = V_22 -> V_75 -> V_76 ( V_34 , V_81 ,
V_93 , V_94 ) ;
if ( V_60 == - V_252 ) {
F_51 ( V_93 ) ;
V_60 = V_22 -> V_75 -> V_76 ( V_34 , V_81 ,
NULL , 0 ) ;
if ( V_60 < 0 ) {
F_108 ( V_34 ) ;
goto V_251;
}
V_94 = V_60 ;
V_93 = F_107 ( V_94 + 1 , V_26 ) ;
if ( ! V_93 ) {
V_60 = - V_27 ;
F_108 ( V_34 ) ;
goto V_251;
}
V_93 [ V_94 ] = '\0' ;
V_60 = V_22 -> V_75 -> V_76 ( V_34 ,
V_81 ,
V_93 , V_94 ) ;
}
F_108 ( V_34 ) ;
if ( V_60 < 0 ) {
if ( V_60 != - V_82 ) {
F_58 ( V_77 L_28
L_29 , V_127 ,
- V_60 , V_22 -> V_45 -> V_78 , V_22 -> V_253 ) ;
F_51 ( V_93 ) ;
goto V_251;
}
V_17 = V_44 -> V_57 ;
V_60 = 0 ;
} else {
V_60 = F_109 ( V_93 , V_60 , & V_17 ,
V_44 -> V_57 ,
V_26 ) ;
if ( V_60 ) {
char * V_254 = V_22 -> V_45 -> V_78 ;
unsigned long V_255 = V_22 -> V_253 ;
if ( V_60 == - V_96 ) {
if ( F_110 () )
F_58 ( V_256 L_30
L_31
L_32 , V_255 , V_254 , V_93 ) ;
} else {
F_58 ( V_77 L_33
L_34 ,
V_127 , V_93 , - V_60 , V_254 , V_255 ) ;
}
F_51 ( V_93 ) ;
V_60 = 0 ;
break;
}
}
F_51 ( V_93 ) ;
V_24 -> V_17 = V_17 ;
break;
case V_68 :
V_24 -> V_17 = V_24 -> F_18 ;
break;
case V_67 :
V_24 -> V_17 = V_44 -> V_17 ;
V_24 -> V_31 = F_92 ( V_22 -> V_257 ) ;
V_60 = F_111 ( V_24 -> F_18 , V_44 -> V_17 ,
V_24 -> V_31 , NULL , & V_17 ) ;
if ( V_60 )
goto V_251;
V_24 -> V_17 = V_17 ;
break;
case V_129 :
V_24 -> V_17 = V_44 -> V_59 ;
break;
default:
V_24 -> V_17 = V_44 -> V_17 ;
if ( ( V_44 -> V_85 & V_126 ) && ! F_112 ( V_22 -> V_257 ) ) {
if ( V_35 )
V_34 = F_105 ( V_35 ) ;
else
V_34 = F_106 ( V_22 ) ;
if ( ! V_34 )
goto V_251;
V_24 -> V_31 = F_92 ( V_22 -> V_257 ) ;
V_60 = F_96 ( V_34 , V_24 -> V_31 ,
V_44 -> V_85 , & V_17 ) ;
F_108 ( V_34 ) ;
if ( V_60 )
goto V_251;
V_24 -> V_17 = V_17 ;
}
break;
}
V_24 -> V_37 = V_130 ;
V_251:
F_78 ( & V_24 -> V_28 ) ;
V_80:
if ( V_24 -> V_31 == V_32 )
V_24 -> V_31 = F_92 ( V_22 -> V_257 ) ;
return V_60 ;
}
static inline T_2 F_113 ( int V_258 )
{
T_2 V_259 = 0 ;
switch ( V_258 ) {
case V_260 :
V_259 = V_261 ;
break;
case V_262 :
V_259 = V_263 ;
break;
case V_264 :
V_259 = V_265 ;
break;
default:
V_259 = V_266 ;
break;
}
return V_259 ;
}
static int F_114 ( const struct V_10 * V_267 ,
const struct V_10 * V_268 ,
T_2 V_269 )
{
T_2 V_270 = F_17 ( V_267 ) , V_271 = F_17 ( V_268 ) ;
return F_54 ( V_270 , V_271 , V_272 , V_269 , NULL ) ;
}
static int F_115 ( const struct V_20 * V_273 ,
const struct V_20 * V_274 ,
T_2 V_269 )
{
const struct V_13 * V_275 , * V_276 ;
T_2 V_277 , V_278 ;
F_19 () ;
V_275 = F_20 ( V_273 ) -> V_19 ; V_277 = V_275 -> V_17 ;
V_276 = F_20 ( V_274 ) -> V_19 ; V_278 = V_276 -> V_17 ;
F_21 () ;
return F_54 ( V_277 , V_278 , V_272 , V_269 , NULL ) ;
}
static int F_116 ( const struct V_20 * V_279 ,
T_2 V_269 )
{
T_2 V_17 , V_271 ;
V_17 = F_22 () ;
V_271 = F_18 ( V_279 ) ;
return F_54 ( V_17 , V_271 , V_272 , V_269 , NULL ) ;
}
static int F_117 ( const struct V_10 * V_10 ,
int V_280 , int V_281 )
{
struct V_282 V_283 ;
struct V_284 V_285 ;
T_4 V_31 ;
T_2 V_17 = F_17 ( V_10 ) ;
T_2 V_286 = F_118 ( V_280 ) ;
int V_60 ;
V_283 . type = V_287 ;
V_283 . V_288 . V_280 = V_280 ;
switch ( F_119 ( V_280 ) ) {
case 0 :
V_31 = V_289 ;
break;
case 1 :
V_31 = V_290 ;
break;
default:
F_58 ( V_84
L_35 , V_280 ) ;
F_89 () ;
return - V_96 ;
}
V_60 = F_120 ( V_17 , V_17 , V_31 , V_286 , 0 , & V_285 ) ;
if ( V_281 == V_291 ) {
int V_292 = F_121 ( V_17 , V_17 , V_31 , V_286 , & V_285 , V_60 , & V_283 , 0 ) ;
if ( V_292 )
return V_292 ;
}
return V_60 ;
}
static int F_122 ( struct V_20 * V_279 ,
T_2 V_269 )
{
T_2 V_17 = F_18 ( V_279 ) ;
return F_54 ( V_17 , V_18 ,
V_293 , V_269 , NULL ) ;
}
static int F_123 ( const struct V_10 * V_10 ,
struct V_22 * V_22 ,
T_2 V_269 ,
struct V_282 * V_294 )
{
struct V_23 * V_24 ;
T_2 V_17 ;
F_124 ( V_10 ) ;
if ( F_125 ( F_63 ( V_22 ) ) )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
return F_54 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_269 , V_294 ) ;
}
static inline int F_126 ( const struct V_10 * V_10 ,
struct V_34 * V_34 ,
T_2 V_286 )
{
struct V_22 * V_22 = F_36 ( V_34 ) ;
struct V_282 V_283 ;
V_283 . type = V_295 ;
V_283 . V_288 . V_34 = V_34 ;
F_28 ( V_22 , V_34 , true ) ;
return F_123 ( V_10 , V_22 , V_286 , & V_283 ) ;
}
static inline int F_127 ( const struct V_10 * V_10 ,
const struct V_249 * V_249 ,
T_2 V_286 )
{
struct V_22 * V_22 = F_36 ( V_249 -> V_34 ) ;
struct V_282 V_283 ;
V_283 . type = V_296 ;
V_283 . V_288 . V_249 = * V_249 ;
F_28 ( V_22 , V_249 -> V_34 , true ) ;
return F_123 ( V_10 , V_22 , V_286 , & V_283 ) ;
}
static inline int F_128 ( const struct V_10 * V_10 ,
struct V_48 * V_48 ,
T_2 V_286 )
{
struct V_282 V_283 ;
V_283 . type = V_296 ;
V_283 . V_288 . V_249 = V_48 -> V_297 ;
return F_123 ( V_10 , F_129 ( V_48 ) , V_286 , & V_283 ) ;
}
static int F_130 ( const struct V_10 * V_10 ,
struct V_48 * V_48 ,
T_2 V_286 )
{
struct V_49 * V_50 = V_48 -> V_53 ;
struct V_22 * V_22 = F_129 ( V_48 ) ;
struct V_282 V_283 ;
T_2 V_17 = F_17 ( V_10 ) ;
int V_60 ;
V_283 . type = V_296 ;
V_283 . V_288 . V_249 = V_48 -> V_297 ;
if ( V_17 != V_50 -> V_17 ) {
V_60 = F_54 ( V_17 , V_50 -> V_17 ,
V_298 ,
V_299 ,
& V_283 ) ;
if ( V_60 )
goto V_80;
}
V_60 = 0 ;
if ( V_286 )
V_60 = F_123 ( V_10 , V_22 , V_286 , & V_283 ) ;
V_80:
return V_60 ;
}
static int F_131 ( struct V_22 * V_300 ,
const struct V_301 * V_71 ,
T_4 V_246 ,
T_2 * V_302 )
{
const struct V_43 * V_44 = V_300 -> V_45 -> V_46 ;
const struct V_23 * V_303 = F_34 ( V_300 ) ;
const struct V_13 * V_14 = F_23 () ;
if ( ( V_44 -> V_85 & V_86 ) &&
( V_44 -> V_65 == V_129 ) ) {
* V_302 = V_44 -> V_59 ;
} else if ( ( V_44 -> V_85 & V_87 ) &&
V_14 -> V_304 ) {
* V_302 = V_14 -> V_304 ;
} else {
return F_111 ( V_14 -> V_17 , V_303 -> V_17 , V_246 ,
V_71 , V_302 ) ;
}
return 0 ;
}
static int F_132 ( struct V_22 * V_300 ,
struct V_34 * V_34 ,
T_4 V_246 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_303 ;
struct V_43 * V_44 ;
T_2 V_17 , V_305 ;
struct V_282 V_283 ;
int V_60 ;
V_303 = F_34 ( V_300 ) ;
V_44 = V_300 -> V_45 -> V_46 ;
V_17 = V_14 -> V_17 ;
V_283 . type = V_295 ;
V_283 . V_288 . V_34 = V_34 ;
V_60 = F_54 ( V_17 , V_303 -> V_17 , V_182 ,
V_306 | V_307 ,
& V_283 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_131 ( V_300 , & V_34 -> V_308 , V_246 ,
& V_305 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_54 ( V_17 , V_305 , V_246 , V_309 , & V_283 ) ;
if ( V_60 )
return V_60 ;
return F_54 ( V_305 , V_44 -> V_17 ,
V_61 ,
V_64 , & V_283 ) ;
}
static int F_133 ( T_2 V_310 ,
struct V_20 * V_311 )
{
T_2 V_17 = F_18 ( V_311 ) ;
return F_54 ( V_17 , V_310 , V_312 , V_313 , NULL ) ;
}
static int F_134 ( struct V_22 * V_300 ,
struct V_34 * V_34 ,
int V_314 )
{
struct V_23 * V_303 , * V_24 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
T_2 V_286 ;
int V_60 ;
V_303 = F_34 ( V_300 ) ;
V_24 = F_35 ( V_34 ) ;
V_283 . type = V_295 ;
V_283 . V_288 . V_34 = V_34 ;
V_286 = V_307 ;
V_286 |= ( V_314 ? V_315 : V_306 ) ;
V_60 = F_54 ( V_17 , V_303 -> V_17 , V_182 , V_286 , & V_283 ) ;
if ( V_60 )
return V_60 ;
switch ( V_314 ) {
case V_316 :
V_286 = V_317 ;
break;
case V_318 :
V_286 = V_319 ;
break;
case V_320 :
V_286 = V_321 ;
break;
default:
F_58 ( V_77 L_36 ,
V_127 , V_314 ) ;
return 0 ;
}
V_60 = F_54 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_286 , & V_283 ) ;
return V_60 ;
}
static inline int F_135 ( struct V_22 * V_322 ,
struct V_34 * V_323 ,
struct V_22 * V_324 ,
struct V_34 * V_325 )
{
struct V_23 * V_326 , * V_327 , * V_328 , * V_329 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
T_2 V_286 ;
int V_330 , V_331 ;
int V_60 ;
V_326 = F_34 ( V_322 ) ;
V_328 = F_35 ( V_323 ) ;
V_330 = F_136 ( V_323 ) ;
V_327 = F_34 ( V_324 ) ;
V_283 . type = V_295 ;
V_283 . V_288 . V_34 = V_323 ;
V_60 = F_54 ( V_17 , V_326 -> V_17 , V_182 ,
V_315 | V_307 , & V_283 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_54 ( V_17 , V_328 -> V_17 ,
V_328 -> V_31 , V_332 , & V_283 ) ;
if ( V_60 )
return V_60 ;
if ( V_330 && V_324 != V_322 ) {
V_60 = F_54 ( V_17 , V_328 -> V_17 ,
V_328 -> V_31 , V_333 , & V_283 ) ;
if ( V_60 )
return V_60 ;
}
V_283 . V_288 . V_34 = V_325 ;
V_286 = V_306 | V_307 ;
if ( F_137 ( V_325 ) )
V_286 |= V_315 ;
V_60 = F_54 ( V_17 , V_327 -> V_17 , V_182 , V_286 , & V_283 ) ;
if ( V_60 )
return V_60 ;
if ( F_137 ( V_325 ) ) {
V_329 = F_35 ( V_325 ) ;
V_331 = F_136 ( V_325 ) ;
V_60 = F_54 ( V_17 , V_329 -> V_17 ,
V_329 -> V_31 ,
( V_331 ? V_321 : V_319 ) , & V_283 ) ;
if ( V_60 )
return V_60 ;
}
return 0 ;
}
static int F_138 ( const struct V_10 * V_10 ,
struct V_54 * V_55 ,
T_2 V_269 ,
struct V_282 * V_283 )
{
struct V_43 * V_44 ;
T_2 V_17 = F_17 ( V_10 ) ;
V_44 = V_55 -> V_46 ;
return F_54 ( V_17 , V_44 -> V_17 , V_61 , V_269 , V_283 ) ;
}
static inline T_2 F_139 ( int V_172 , int V_334 )
{
T_2 V_286 = 0 ;
if ( ! F_140 ( V_172 ) ) {
if ( V_334 & V_335 )
V_286 |= V_336 ;
if ( V_334 & V_337 )
V_286 |= V_338 ;
if ( V_334 & V_339 )
V_286 |= V_340 ;
else if ( V_334 & V_341 )
V_286 |= V_342 ;
} else {
if ( V_334 & V_335 )
V_286 |= V_307 ;
if ( V_334 & V_341 )
V_286 |= V_343 ;
if ( V_334 & V_337 )
V_286 |= V_344 ;
}
return V_286 ;
}
static inline T_2 F_141 ( struct V_48 * V_48 )
{
T_2 V_286 = 0 ;
if ( V_48 -> V_345 & V_346 )
V_286 |= V_338 ;
if ( V_48 -> V_345 & V_347 ) {
if ( V_48 -> V_348 & V_349 )
V_286 |= V_340 ;
else
V_286 |= V_342 ;
}
if ( ! V_286 ) {
V_286 = V_350 ;
}
return V_286 ;
}
static inline T_2 F_142 ( struct V_48 * V_48 )
{
T_2 V_286 = F_141 ( V_48 ) ;
if ( V_351 )
V_286 |= V_352 ;
return V_286 ;
}
static int F_143 ( struct V_20 * V_353 )
{
T_2 V_354 = F_22 () ;
T_2 V_355 = F_18 ( V_353 ) ;
return F_54 ( V_354 , V_355 , V_356 ,
V_357 , NULL ) ;
}
static int F_144 ( struct V_20 * V_358 ,
struct V_20 * V_359 )
{
T_2 V_354 = F_22 () ;
T_2 V_360 = F_18 ( V_358 ) ;
T_2 V_361 = F_18 ( V_359 ) ;
int V_60 ;
if ( V_354 != V_360 ) {
V_60 = F_54 ( V_354 , V_360 , V_356 ,
V_362 , NULL ) ;
if ( V_60 )
return V_60 ;
}
return F_54 ( V_360 , V_361 , V_356 , V_363 ,
NULL ) ;
}
static int F_145 ( struct V_20 * V_358 ,
struct V_20 * V_359 )
{
T_2 V_360 = F_18 ( V_358 ) ;
T_2 V_361 = F_18 ( V_359 ) ;
return F_54 ( V_360 , V_361 , V_356 , V_364 ,
NULL ) ;
}
static int F_146 ( struct V_20 * V_358 ,
struct V_20 * V_359 ,
struct V_48 * V_48 )
{
T_2 V_17 = F_18 ( V_359 ) ;
struct V_49 * V_50 = V_48 -> V_53 ;
struct V_34 * V_34 = V_48 -> V_297 . V_34 ;
struct V_23 * V_24 = F_35 ( V_34 ) ;
struct V_282 V_283 ;
int V_60 ;
V_283 . type = V_296 ;
V_283 . V_288 . V_249 = V_48 -> V_297 ;
if ( V_17 != V_50 -> V_17 ) {
V_60 = F_54 ( V_17 , V_50 -> V_17 ,
V_298 ,
V_299 ,
& V_283 ) ;
if ( V_60 )
return V_60 ;
}
if ( F_125 ( F_63 ( F_36 ( V_34 ) ) ) )
return 0 ;
return F_54 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , F_141 ( V_48 ) ,
& V_283 ) ;
}
static int F_147 ( struct V_20 * V_365 ,
unsigned int V_172 )
{
if ( V_172 & V_366 ) {
T_2 V_17 = F_22 () ;
T_2 V_367 = F_18 ( V_365 ) ;
return F_54 ( V_17 , V_367 , V_32 , V_338 , NULL ) ;
}
return F_116 ( V_365 , V_368 ) ;
}
static int F_148 ( struct V_20 * V_369 )
{
return F_115 ( V_369 , V_11 , V_368 ) ;
}
static int F_149 ( struct V_20 * V_268 , T_6 * V_370 ,
T_6 * V_371 , T_6 * V_372 )
{
return F_116 ( V_268 , V_373 ) ;
}
static int F_150 ( struct V_10 * V_134 , const struct V_10 * V_133 ,
const T_6 * V_370 ,
const T_6 * V_371 ,
const T_6 * V_372 )
{
return F_114 ( V_133 , V_134 , V_374 ) ;
}
static int F_151 ( const struct V_10 * V_10 , struct V_375 * V_376 ,
int V_280 , int V_281 )
{
return F_117 ( V_10 , V_280 , V_281 ) ;
}
static int F_152 ( int V_377 , int type , int V_378 , struct V_54 * V_55 )
{
const struct V_10 * V_10 = F_74 () ;
int V_60 = 0 ;
if ( ! V_55 )
return 0 ;
switch ( V_377 ) {
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
V_60 = F_138 ( V_10 , V_55 , V_384 , NULL ) ;
break;
case V_385 :
case V_386 :
case V_387 :
V_60 = F_138 ( V_10 , V_55 , V_388 , NULL ) ;
break;
default:
V_60 = 0 ;
break;
}
return V_60 ;
}
static int F_153 ( struct V_34 * V_34 )
{
const struct V_10 * V_10 = F_74 () ;
return F_126 ( V_10 , V_34 , V_389 ) ;
}
static int F_154 ( int type )
{
int V_60 ;
switch ( type ) {
case V_390 :
case V_391 :
V_60 = F_122 ( V_11 , V_392 ) ;
break;
case V_393 :
case V_394 :
case V_395 :
V_60 = F_122 ( V_11 , V_396 ) ;
break;
case V_397 :
case V_398 :
case V_399 :
case V_400 :
case V_401 :
default:
V_60 = F_122 ( V_11 , V_402 ) ;
break;
}
return V_60 ;
}
static int F_155 ( struct V_403 * V_404 , long V_405 )
{
int V_60 , V_406 = 0 ;
V_60 = F_117 ( F_74 () , V_407 ,
V_408 ) ;
if ( V_60 == 0 )
V_406 = 1 ;
return V_406 ;
}
static int F_156 ( const struct V_409 * V_410 ,
const struct V_13 * V_411 ,
const struct V_13 * V_412 )
{
int V_413 = ( V_410 -> V_414 & V_415 ) ;
int V_416 = ( V_410 -> V_48 -> V_297 . V_417 -> V_112 & V_418 ) ;
int V_60 ;
if ( ! V_413 && ! V_416 )
return 0 ;
if ( V_412 -> V_17 == V_411 -> V_17 )
return 0 ;
V_60 = F_157 ( V_411 -> V_17 , V_412 -> V_17 ) ;
if ( V_60 ) {
if ( V_413 )
return - V_419 ;
else
return - V_420 ;
}
return 0 ;
}
static int F_158 ( struct V_409 * V_410 )
{
const struct V_13 * V_411 ;
struct V_13 * V_412 ;
struct V_23 * V_24 ;
struct V_282 V_283 ;
struct V_22 * V_22 = F_129 ( V_410 -> V_48 ) ;
int V_60 ;
if ( V_410 -> V_421 )
return 0 ;
V_411 = F_23 () ;
V_412 = V_410 -> V_10 -> V_19 ;
V_24 = F_34 ( V_22 ) ;
V_412 -> V_17 = V_411 -> V_17 ;
V_412 -> V_16 = V_411 -> V_17 ;
V_412 -> V_304 = 0 ;
V_412 -> V_422 = 0 ;
V_412 -> V_423 = 0 ;
if ( V_411 -> V_424 ) {
V_412 -> V_17 = V_411 -> V_424 ;
V_412 -> V_424 = 0 ;
V_60 = F_156 ( V_410 , V_411 , V_412 ) ;
if ( V_60 )
return V_60 ;
} else {
V_60 = F_111 ( V_411 -> V_17 , V_24 -> V_17 ,
V_272 , NULL ,
& V_412 -> V_17 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_156 ( V_410 , V_411 , V_412 ) ;
if ( V_60 )
V_412 -> V_17 = V_411 -> V_17 ;
}
V_283 . type = V_296 ;
V_283 . V_288 . V_249 = V_410 -> V_48 -> V_297 ;
if ( V_412 -> V_17 == V_411 -> V_17 ) {
V_60 = F_54 ( V_411 -> V_17 , V_24 -> V_17 ,
V_32 , V_425 , & V_283 ) ;
if ( V_60 )
return V_60 ;
} else {
V_60 = F_54 ( V_411 -> V_17 , V_412 -> V_17 ,
V_272 , V_426 , & V_283 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_54 ( V_412 -> V_17 , V_24 -> V_17 ,
V_32 , V_427 , & V_283 ) ;
if ( V_60 )
return V_60 ;
if ( V_410 -> V_414 & V_428 ) {
V_60 = F_54 ( V_411 -> V_17 , V_412 -> V_17 ,
V_272 , V_429 ,
NULL ) ;
if ( V_60 )
return - V_419 ;
}
if ( V_410 -> V_414 &
( V_430 | V_431 ) ) {
struct V_20 * V_432 ;
struct V_13 * V_433 ;
T_2 V_434 = 0 ;
F_19 () ;
V_432 = F_159 ( V_11 ) ;
if ( F_160 ( V_432 != NULL ) ) {
V_433 = F_20 ( V_432 ) -> V_19 ;
V_434 = V_433 -> V_17 ;
}
F_21 () ;
if ( V_434 != 0 ) {
V_60 = F_54 ( V_434 , V_412 -> V_17 ,
V_272 ,
V_368 , NULL ) ;
if ( V_60 )
return - V_419 ;
}
}
V_410 -> V_435 |= V_436 ;
}
return 0 ;
}
static int F_161 ( struct V_409 * V_410 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_17 , V_16 ;
int V_437 = 0 ;
V_17 = V_14 -> V_17 ;
V_16 = V_14 -> V_16 ;
if ( V_16 != V_17 ) {
V_437 = F_54 ( V_16 , V_17 ,
V_272 ,
V_438 , NULL ) ;
}
return ! ! V_437 ;
}
static int F_162 ( const void * V_149 , struct V_48 * V_48 , unsigned V_439 )
{
return F_130 ( V_149 , V_48 , F_141 ( V_48 ) ) ? V_439 + 1 : 0 ;
}
static inline void F_163 ( const struct V_10 * V_10 ,
struct V_440 * V_441 )
{
struct V_48 * V_48 , * V_442 = NULL ;
struct V_443 * V_444 ;
int V_445 = 0 ;
unsigned V_446 ;
V_444 = F_164 () ;
if ( V_444 ) {
F_42 ( & V_447 ) ;
if ( ! F_60 ( & V_444 -> V_448 ) ) {
struct V_449 * V_450 ;
V_450 = F_165 ( & V_444 -> V_448 ,
struct V_449 , V_29 ) ;
V_48 = V_450 -> V_48 ;
if ( F_128 ( V_10 , V_48 , V_338 | V_342 ) )
V_445 = 1 ;
}
F_44 ( & V_447 ) ;
F_166 ( V_444 ) ;
}
if ( V_445 )
F_167 () ;
V_446 = F_168 ( V_441 , 0 , F_162 , V_10 ) ;
if ( ! V_446 )
return;
V_442 = F_169 ( & V_451 , V_452 , V_10 ) ;
if ( F_99 ( V_442 ) )
V_442 = NULL ;
do {
F_170 ( V_446 - 1 , V_442 , 0 ) ;
} while ( ( V_446 = F_168 ( V_441 , V_446 , F_162 , V_10 ) ) != 0 );
if ( V_442 )
F_171 ( V_442 ) ;
}
static void F_172 ( struct V_409 * V_410 )
{
struct V_13 * V_412 ;
struct V_453 * V_454 , * V_455 ;
int V_60 , V_92 ;
V_412 = V_410 -> V_10 -> V_19 ;
if ( V_412 -> V_17 == V_412 -> V_16 )
return;
F_163 ( V_410 -> V_10 , V_11 -> V_441 ) ;
V_11 -> V_456 = 0 ;
V_60 = F_54 ( V_412 -> V_16 , V_412 -> V_17 , V_272 ,
V_457 , NULL ) ;
if ( V_60 ) {
F_173 ( V_11 ) ;
for ( V_92 = 0 ; V_92 < V_458 ; V_92 ++ ) {
V_454 = V_11 -> signal -> V_454 + V_92 ;
V_455 = V_459 . signal -> V_454 + V_92 ;
V_454 -> V_460 = F_174 ( V_454 -> V_461 , V_455 -> V_460 ) ;
}
F_175 ( V_11 ) ;
F_176 ( V_11 , V_453 ( V_462 ) ) ;
}
}
static void F_177 ( struct V_409 * V_410 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_463 V_464 ;
T_2 V_16 , V_17 ;
int V_60 , V_92 ;
V_16 = V_14 -> V_16 ;
V_17 = V_14 -> V_17 ;
if ( V_17 == V_16 )
return;
V_60 = F_54 ( V_16 , V_17 , V_272 , V_465 , NULL ) ;
if ( V_60 ) {
memset ( & V_464 , 0 , sizeof V_464 ) ;
for ( V_92 = 0 ; V_92 < 3 ; V_92 ++ )
F_178 ( V_92 , & V_464 , NULL ) ;
F_179 ( & V_11 -> V_466 -> V_467 ) ;
if ( ! F_180 ( V_11 ) ) {
F_181 ( & V_11 -> V_468 ) ;
F_181 ( & V_11 -> signal -> V_469 ) ;
F_182 ( V_11 , 1 ) ;
F_183 ( & V_11 -> V_470 ) ;
F_184 () ;
}
F_185 ( & V_11 -> V_466 -> V_467 ) ;
}
F_186 ( & V_471 ) ;
F_187 ( V_11 , V_11 -> V_472 ) ;
F_188 ( & V_471 ) ;
}
static int F_189 ( struct V_54 * V_55 )
{
return F_48 ( V_55 ) ;
}
static void F_190 ( struct V_54 * V_55 )
{
F_50 ( V_55 ) ;
}
static inline int F_191 ( char * V_165 , int V_473 , char * V_474 , int V_475 )
{
if ( V_473 > V_475 )
return 0 ;
return ! memcmp ( V_165 , V_474 , V_473 ) ;
}
static inline int F_192 ( char * V_474 , int V_94 )
{
return ( F_191 ( V_167 , sizeof( V_167 ) - 1 , V_474 , V_94 ) ||
F_191 ( V_168 , sizeof( V_168 ) - 1 , V_474 , V_94 ) ||
F_191 ( V_170 , sizeof( V_170 ) - 1 , V_474 , V_94 ) ||
F_191 ( V_169 , sizeof( V_169 ) - 1 , V_474 , V_94 ) ||
F_191 ( V_171 , sizeof( V_171 ) - 1 , V_474 , V_94 ) ) ;
}
static inline void F_193 ( char * * V_359 , char * V_358 , int * V_476 , int V_94 )
{
if ( ! * V_476 ) {
* * V_359 = ',' ;
* V_359 += 1 ;
} else
* V_476 = 0 ;
memcpy ( * V_359 , V_358 , V_94 ) ;
* V_359 += V_94 ;
}
static inline void F_194 ( char * * V_359 , char * V_358 , int * V_476 ,
int V_94 )
{
int V_477 = 0 ;
if ( ! * V_476 ) {
* * V_359 = '|' ;
* V_359 += 1 ;
} else
* V_476 = 0 ;
while ( V_477 < V_94 ) {
if ( * V_358 != '"' ) {
* * V_359 = * V_358 ;
* V_359 += 1 ;
}
V_358 += 1 ;
V_477 += 1 ;
}
}
static int F_195 ( char * V_478 , char * V_479 )
{
int V_480 , V_50 , V_60 = 0 ;
char * V_481 , * V_482 , * V_483 ;
char * V_484 , * V_485 , * V_486 ;
int V_487 = 0 ;
V_482 = V_478 ;
V_484 = V_479 ;
V_486 = ( char * ) F_196 ( V_15 ) ;
if ( ! V_486 ) {
V_60 = - V_27 ;
goto V_80;
}
V_485 = V_486 ;
V_480 = V_50 = 1 ;
V_481 = V_483 = V_478 ;
do {
if ( * V_483 == '"' )
V_487 = ! V_487 ;
if ( ( * V_483 == ',' && V_487 == 0 ) ||
* V_483 == '\0' ) {
int V_94 = V_483 - V_482 ;
if ( F_192 ( V_482 , V_94 ) )
F_194 ( & V_484 , V_482 , & V_50 , V_94 ) ;
else
F_193 ( & V_486 , V_482 , & V_480 , V_94 ) ;
V_482 = V_483 + 1 ;
}
} while ( * V_483 ++ );
strcpy ( V_481 , V_485 ) ;
F_102 ( ( unsigned long ) V_485 ) ;
V_80:
return V_60 ;
}
static int F_197 ( struct V_54 * V_55 , void * V_162 )
{
int V_60 , V_92 , * V_85 ;
struct V_90 V_91 ;
char * V_488 , * * V_120 ;
struct V_43 * V_44 = V_55 -> V_46 ;
if ( ! ( V_44 -> V_85 & V_86 ) )
return 0 ;
if ( ! V_162 )
return 0 ;
if ( V_55 -> V_70 -> V_122 & V_123 )
return 0 ;
F_66 ( & V_91 ) ;
V_488 = F_198 () ;
if ( ! V_488 )
return - V_27 ;
V_60 = F_195 ( V_162 , V_488 ) ;
if ( V_60 )
goto V_489;
V_60 = F_81 ( V_488 , & V_91 ) ;
if ( V_60 )
goto V_489;
V_120 = V_91 . V_101 ;
V_85 = V_91 . V_104 ;
for ( V_92 = 0 ; V_92 < V_91 . V_100 ; V_92 ++ ) {
T_2 V_17 ;
if ( V_85 [ V_92 ] == V_87 )
continue;
V_60 = F_76 ( V_120 [ V_92 ] , & V_17 , V_15 ) ;
if ( V_60 ) {
F_58 ( V_77 L_14
L_15 ,
V_120 [ V_92 ] , V_55 -> V_78 , V_55 -> V_70 -> V_71 , V_60 ) ;
goto V_490;
}
V_60 = - V_96 ;
switch ( V_85 [ V_92 ] ) {
case V_105 :
if ( F_72 ( V_44 , V_105 , V_44 -> V_17 , V_17 ) )
goto V_491;
break;
case V_106 :
if ( F_72 ( V_44 , V_106 , V_44 -> V_59 , V_17 ) )
goto V_491;
break;
case V_108 : {
struct V_23 * V_115 ;
V_115 = F_35 ( V_55 -> V_73 ) ;
if ( F_72 ( V_44 , V_108 , V_115 -> V_17 , V_17 ) )
goto V_491;
break;
}
case V_107 :
if ( F_72 ( V_44 , V_107 , V_44 -> V_57 , V_17 ) )
goto V_491;
break;
default:
goto V_490;
}
}
V_60 = 0 ;
V_490:
F_71 ( & V_91 ) ;
V_489:
F_199 ( V_488 ) ;
return V_60 ;
V_491:
F_58 ( V_77 L_37
L_38 , V_55 -> V_78 ,
V_55 -> V_70 -> V_71 ) ;
goto V_490;
}
static int F_200 ( struct V_54 * V_55 , int V_85 , void * V_162 )
{
const struct V_10 * V_10 = F_74 () ;
struct V_282 V_283 ;
int V_60 ;
V_60 = F_85 ( V_55 , V_162 ) ;
if ( V_60 )
return V_60 ;
if ( V_85 & V_492 )
return 0 ;
V_283 . type = V_295 ;
V_283 . V_288 . V_34 = V_55 -> V_73 ;
return F_138 ( V_10 , V_55 , V_493 , & V_283 ) ;
}
static int F_201 ( struct V_34 * V_34 )
{
const struct V_10 * V_10 = F_74 () ;
struct V_282 V_283 ;
V_283 . type = V_295 ;
V_283 . V_288 . V_34 = V_34 -> V_494 -> V_73 ;
return F_138 ( V_10 , V_34 -> V_494 , V_495 , & V_283 ) ;
}
static int F_202 ( const char * V_496 ,
struct V_249 * V_249 ,
const char * type ,
unsigned long V_85 ,
void * V_162 )
{
const struct V_10 * V_10 = F_74 () ;
if ( V_85 & V_497 )
return F_138 ( V_10 , V_249 -> V_34 -> V_494 ,
V_498 , NULL ) ;
else
return F_127 ( V_10 , V_249 , V_499 ) ;
}
static int F_203 ( struct V_500 * V_417 , int V_85 )
{
const struct V_10 * V_10 = F_74 () ;
return F_138 ( V_10 , V_417 -> V_501 ,
V_502 , NULL ) ;
}
static int F_204 ( struct V_22 * V_22 )
{
return F_24 ( V_22 ) ;
}
static void F_205 ( struct V_22 * V_22 )
{
F_40 ( V_22 ) ;
}
static int F_206 ( struct V_34 * V_34 , int V_172 ,
struct V_301 * V_71 , void * * V_311 ,
T_2 * V_503 )
{
T_2 V_305 ;
int V_60 ;
V_60 = F_131 ( V_247 ( V_34 -> V_504 ) , V_71 ,
F_92 ( V_172 ) ,
& V_305 ) ;
if ( V_60 )
return V_60 ;
return F_69 ( V_305 , ( char * * ) V_311 , V_503 ) ;
}
static int F_207 ( struct V_22 * V_22 , struct V_22 * V_300 ,
const struct V_301 * V_301 ,
const char * * V_71 ,
void * * V_505 , T_7 * V_94 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_43 * V_44 ;
T_2 V_17 , V_305 , V_506 ;
int V_60 ;
char * V_93 ;
V_44 = V_300 -> V_45 -> V_46 ;
V_17 = V_14 -> V_17 ;
V_305 = V_14 -> V_304 ;
V_60 = F_131 (
V_300 , V_301 ,
F_92 ( V_22 -> V_257 ) ,
& V_305 ) ;
if ( V_60 )
return V_60 ;
if ( V_44 -> V_85 & V_86 ) {
struct V_23 * V_24 = V_22 -> V_33 ;
V_24 -> V_31 = F_92 ( V_22 -> V_257 ) ;
V_24 -> V_17 = V_305 ;
V_24 -> V_37 = V_130 ;
}
if ( ! V_97 || ! ( V_44 -> V_85 & V_87 ) )
return - V_79 ;
if ( V_71 )
* V_71 = V_507 ;
if ( V_505 && V_94 ) {
V_60 = F_208 ( V_305 , & V_93 , & V_506 ) ;
if ( V_60 )
return V_60 ;
* V_505 = V_93 ;
* V_94 = V_506 ;
}
return 0 ;
}
static int F_209 ( struct V_22 * V_300 , struct V_34 * V_34 , T_5 V_172 )
{
return F_132 ( V_300 , V_34 , V_32 ) ;
}
static int F_210 ( struct V_34 * V_323 , struct V_22 * V_300 , struct V_34 * V_325 )
{
return F_134 ( V_300 , V_323 , V_316 ) ;
}
static int F_211 ( struct V_22 * V_300 , struct V_34 * V_34 )
{
return F_134 ( V_300 , V_34 , V_318 ) ;
}
static int F_212 ( struct V_22 * V_300 , struct V_34 * V_34 , const char * V_71 )
{
return F_132 ( V_300 , V_34 , V_177 ) ;
}
static int F_213 ( struct V_22 * V_300 , struct V_34 * V_34 , T_5 V_334 )
{
return F_132 ( V_300 , V_34 , V_182 ) ;
}
static int F_214 ( struct V_22 * V_300 , struct V_34 * V_34 )
{
return F_134 ( V_300 , V_34 , V_320 ) ;
}
static int F_215 ( struct V_22 * V_300 , struct V_34 * V_34 , T_5 V_172 , T_8 V_254 )
{
return F_132 ( V_300 , V_34 , F_92 ( V_172 ) ) ;
}
static int F_216 ( struct V_22 * V_508 , struct V_34 * V_323 ,
struct V_22 * V_509 , struct V_34 * V_325 )
{
return F_135 ( V_508 , V_323 , V_509 , V_325 ) ;
}
static int F_217 ( struct V_34 * V_34 )
{
const struct V_10 * V_10 = F_74 () ;
return F_126 ( V_10 , V_34 , V_338 ) ;
}
static int F_218 ( struct V_34 * V_34 , struct V_22 * V_22 ,
bool V_40 )
{
const struct V_10 * V_10 = F_74 () ;
struct V_282 V_283 ;
struct V_23 * V_24 ;
T_2 V_17 ;
F_124 ( V_10 ) ;
V_283 . type = V_295 ;
V_283 . V_288 . V_34 = V_34 ;
V_17 = F_17 ( V_10 ) ;
V_24 = F_32 ( V_22 , V_40 ) ;
if ( F_99 ( V_24 ) )
return F_100 ( V_24 ) ;
return F_219 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_338 , & V_283 ,
V_40 ? V_510 : 0 ) ;
}
static T_9 int F_220 ( struct V_22 * V_22 ,
T_2 V_269 , T_2 V_511 , T_2 V_512 ,
int V_513 ,
unsigned V_85 )
{
struct V_282 V_283 ;
struct V_23 * V_24 = V_22 -> V_33 ;
int V_60 ;
V_283 . type = V_514 ;
V_283 . V_288 . V_22 = V_22 ;
V_60 = F_221 ( F_22 () , V_24 -> V_17 , V_24 -> V_31 , V_269 ,
V_511 , V_512 , V_513 , & V_283 , V_85 ) ;
if ( V_60 )
return V_60 ;
return 0 ;
}
static int F_222 ( struct V_22 * V_22 , int V_334 )
{
const struct V_10 * V_10 = F_74 () ;
T_2 V_269 ;
bool V_515 ;
unsigned V_85 = V_334 & V_510 ;
struct V_23 * V_24 ;
T_2 V_17 ;
struct V_284 V_285 ;
int V_60 , V_292 ;
T_2 V_511 , V_512 ;
V_515 = V_334 & V_516 ;
V_334 &= ( V_337 | V_341 | V_335 | V_339 ) ;
if ( ! V_334 )
return 0 ;
F_124 ( V_10 ) ;
if ( F_125 ( F_63 ( V_22 ) ) )
return 0 ;
V_269 = F_139 ( V_22 -> V_257 , V_334 ) ;
V_17 = F_17 ( V_10 ) ;
V_24 = F_32 ( V_22 , V_85 & V_510 ) ;
if ( F_99 ( V_24 ) )
return F_100 ( V_24 ) ;
V_60 = F_120 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_269 , 0 , & V_285 ) ;
V_511 = F_223 ( V_269 , & V_285 , V_60 ,
V_515 ? V_517 : 0 ,
& V_512 ) ;
if ( F_160 ( ! V_511 ) )
return V_60 ;
V_292 = F_220 ( V_22 , V_269 , V_511 , V_512 , V_60 , V_85 ) ;
if ( V_292 )
return V_292 ;
return V_60 ;
}
static int F_224 ( struct V_34 * V_34 , struct V_518 * V_518 )
{
const struct V_10 * V_10 = F_74 () ;
unsigned int V_519 = V_518 -> V_519 ;
T_10 V_286 = V_342 ;
if ( V_519 & V_520 ) {
V_519 &= ~ ( V_521 | V_522 | V_523 |
V_520 ) ;
if ( ! V_519 )
return 0 ;
}
if ( V_519 & ( V_523 | V_524 | V_525 |
V_526 | V_527 | V_528 ) )
return F_126 ( V_10 , V_34 , V_529 ) ;
if ( V_351 && ( V_519 & V_530 )
&& ! ( V_519 & V_531 ) )
V_286 |= V_352 ;
return F_126 ( V_10 , V_34 , V_286 ) ;
}
static int F_225 ( const struct V_249 * V_249 )
{
return F_127 ( F_74 () , V_249 , V_532 ) ;
}
static int F_226 ( struct V_34 * V_34 , const char * V_71 )
{
const struct V_10 * V_10 = F_74 () ;
if ( ! strncmp ( V_71 , V_533 ,
sizeof V_533 - 1 ) ) {
if ( ! strcmp ( V_71 , V_534 ) ) {
if ( ! F_227 ( V_535 ) )
return - V_419 ;
} else if ( ! F_227 ( V_407 ) ) {
return - V_419 ;
}
}
return F_126 ( V_10 , V_34 , V_529 ) ;
}
static int F_228 ( struct V_34 * V_34 , const char * V_71 ,
const void * V_505 , T_7 V_536 , int V_85 )
{
struct V_22 * V_22 = F_36 ( V_34 ) ;
struct V_23 * V_24 = F_35 ( V_34 ) ;
struct V_43 * V_44 ;
struct V_282 V_283 ;
T_2 V_305 , V_17 = F_22 () ;
int V_60 = 0 ;
if ( strcmp ( V_71 , V_81 ) )
return F_226 ( V_34 , V_71 ) ;
V_44 = V_22 -> V_45 -> V_46 ;
if ( ! ( V_44 -> V_85 & V_87 ) )
return - V_79 ;
if ( ! F_229 ( V_22 ) )
return - V_419 ;
V_283 . type = V_295 ;
V_283 . V_288 . V_34 = V_34 ;
V_60 = F_54 ( V_17 , V_24 -> V_17 , V_24 -> V_31 ,
V_537 , & V_283 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_230 ( V_505 , V_536 , & V_305 , V_15 ) ;
if ( V_60 == - V_96 ) {
if ( ! F_227 ( V_538 ) ) {
struct V_539 * V_540 ;
T_7 V_541 ;
const char * V_1 ;
if ( V_505 ) {
V_1 = V_505 ;
if ( V_1 [ V_536 - 1 ] == '\0' )
V_541 = V_536 - 1 ;
else
V_541 = V_536 ;
} else {
V_1 = L_39 ;
V_541 = 0 ;
}
V_540 = F_231 ( V_11 -> V_542 , V_102 , V_543 ) ;
F_232 ( V_540 , L_40 ) ;
F_233 ( V_540 , V_505 , V_541 ) ;
F_234 ( V_540 ) ;
return V_60 ;
}
V_60 = F_235 ( V_505 , V_536 , & V_305 ) ;
}
if ( V_60 )
return V_60 ;
V_60 = F_54 ( V_17 , V_305 , V_24 -> V_31 ,
V_544 , & V_283 ) ;
if ( V_60 )
return V_60 ;
V_60 = F_236 ( V_24 -> V_17 , V_305 , V_17 ,
V_24 -> V_31 ) ;
if ( V_60 )
return V_60 ;
return F_54 ( V_305 ,
V_44 -> V_17 ,
V_61 ,
V_64 ,
& V_283 ) ;
}
static void F_237 ( struct V_34 * V_34 , const char * V_71 ,
const void * V_505 , T_7 V_536 ,
int V_85 )
{
struct V_22 * V_22 = F_36 ( V_34 ) ;
struct V_23 * V_24 = F_35 ( V_34 ) ;
T_2 V_305 ;
int V_60 ;
if ( strcmp ( V_71 , V_81 ) ) {
return;
}
V_60 = F_235 ( V_505 , V_536 , & V_305 ) ;
if ( V_60 ) {
F_58 ( V_84 L_41
L_42 ,
V_22 -> V_45 -> V_78 , V_22 -> V_253 , - V_60 ) ;
return;
}
V_24 -> V_31 = F_92 ( V_22 -> V_257 ) ;
V_24 -> V_17 = V_305 ;
V_24 -> V_37 = V_130 ;
return;
}
static int F_238 ( struct V_34 * V_34 , const char * V_71 )
{
const struct V_10 * V_10 = F_74 () ;
return F_126 ( V_10 , V_34 , V_532 ) ;
}
static int F_239 ( struct V_34 * V_34 )
{
const struct V_10 * V_10 = F_74 () ;
return F_126 ( V_10 , V_34 , V_532 ) ;
}
static int F_240 ( struct V_34 * V_34 , const char * V_71 )
{
if ( strcmp ( V_71 , V_81 ) )
return F_226 ( V_34 , V_71 ) ;
return - V_420 ;
}
static int F_241 ( struct V_22 * V_22 , const char * V_71 , void * * V_248 , bool V_545 )
{
T_2 V_536 ;
int error ;
char * V_93 = NULL ;
struct V_23 * V_24 = F_34 ( V_22 ) ;
if ( strcmp ( V_71 , V_507 ) )
return - V_79 ;
error = F_242 ( F_74 () , & V_546 , V_538 ,
V_408 ) ;
if ( ! error )
error = F_117 ( F_74 () , V_538 ,
V_408 ) ;
if ( ! error )
error = F_208 ( V_24 -> V_17 , & V_93 ,
& V_536 ) ;
else
error = F_69 ( V_24 -> V_17 , & V_93 , & V_536 ) ;
if ( error )
return error ;
error = V_536 ;
if ( V_545 ) {
* V_248 = V_93 ;
goto V_547;
}
F_51 ( V_93 ) ;
V_547:
return error ;
}
static int F_243 ( struct V_22 * V_22 , const char * V_71 ,
const void * V_505 , T_7 V_536 , int V_85 )
{
struct V_23 * V_24 = F_34 ( V_22 ) ;
T_2 V_305 ;
int V_60 ;
if ( strcmp ( V_71 , V_507 ) )
return - V_79 ;
if ( ! V_505 || ! V_536 )
return - V_420 ;
V_60 = F_230 ( V_505 , V_536 , & V_305 , V_15 ) ;
if ( V_60 )
return V_60 ;
V_24 -> V_31 = F_92 ( V_22 -> V_257 ) ;
V_24 -> V_17 = V_305 ;
V_24 -> V_37 = V_130 ;
return 0 ;
}
static int F_244 ( struct V_22 * V_22 , char * V_248 , T_7 V_548 )
{
const int V_94 = sizeof( V_81 ) ;
if ( V_248 && V_94 <= V_548 )
memcpy ( V_248 , V_81 , V_94 ) ;
return V_94 ;
}
static void F_245 ( struct V_22 * V_22 , T_2 * V_549 )
{
struct V_23 * V_24 = F_31 ( V_22 ) ;
* V_549 = V_24 -> V_17 ;
}
static int F_246 ( struct V_48 * V_48 , int V_334 )
{
const struct V_10 * V_10 = F_74 () ;
struct V_22 * V_22 = F_129 ( V_48 ) ;
if ( ( V_48 -> V_348 & V_349 ) && ( V_334 & V_341 ) )
V_334 |= V_339 ;
return F_130 ( V_10 , V_48 ,
F_139 ( V_22 -> V_257 , V_334 ) ) ;
}
static int F_247 ( struct V_48 * V_48 , int V_334 )
{
struct V_22 * V_22 = F_129 ( V_48 ) ;
struct V_49 * V_50 = V_48 -> V_53 ;
struct V_23 * V_24 ;
T_2 V_17 = F_22 () ;
if ( ! V_334 )
return 0 ;
V_24 = F_34 ( V_22 ) ;
if ( V_17 == V_50 -> V_17 && V_50 -> V_550 == V_24 -> V_17 &&
V_50 -> V_551 == F_248 () )
return 0 ;
return F_246 ( V_48 , V_334 ) ;
}
static int F_249 ( struct V_48 * V_48 )
{
return F_46 ( V_48 ) ;
}
static void F_250 ( struct V_48 * V_48 )
{
F_47 ( V_48 ) ;
}
static int F_251 ( const struct V_10 * V_10 , struct V_48 * V_48 ,
T_2 V_552 , T_4 V_553 )
{
struct V_282 V_283 ;
struct V_49 * V_50 = V_48 -> V_53 ;
struct V_22 * V_22 = F_129 ( V_48 ) ;
struct V_23 * V_24 = F_34 ( V_22 ) ;
struct V_554 V_555 ;
T_2 V_556 = F_17 ( V_10 ) ;
int V_60 ;
T_11 V_557 = V_553 >> 8 ;
T_11 V_558 = V_553 & 0xff ;
V_283 . type = V_559 ;
V_283 . V_288 . V_560 = & V_555 ;
V_283 . V_288 . V_560 -> V_553 = V_553 ;
V_283 . V_288 . V_560 -> V_249 = V_48 -> V_297 ;
if ( V_556 != V_50 -> V_17 ) {
V_60 = F_54 ( V_556 , V_50 -> V_17 ,
V_298 ,
V_299 ,
& V_283 ) ;
if ( V_60 )
goto V_80;
}
if ( F_125 ( F_63 ( V_22 ) ) )
return 0 ;
V_60 = F_252 ( V_556 , V_24 -> V_17 , V_24 -> V_31 ,
V_552 , V_557 , V_558 , & V_283 ) ;
V_80:
return V_60 ;
}
static int F_253 ( struct V_48 * V_48 , unsigned int V_553 ,
unsigned long V_561 )
{
const struct V_10 * V_10 = F_74 () ;
int error = 0 ;
switch ( V_553 ) {
case V_562 :
case V_563 :
case V_564 :
case V_565 :
case V_566 :
error = F_130 ( V_10 , V_48 , V_532 ) ;
break;
case V_567 :
case V_568 :
error = F_130 ( V_10 , V_48 , V_529 ) ;
break;
case V_569 :
case V_570 :
error = F_130 ( V_10 , V_48 , 0 ) ;
break;
case V_571 :
case V_572 :
error = F_117 ( V_10 , V_573 ,
V_291 ) ;
break;
default:
error = F_251 ( V_10 , V_48 , V_350 , ( T_4 ) V_553 ) ;
}
return error ;
}
static int F_254 ( struct V_48 * V_48 , unsigned long V_574 , int V_575 )
{
const struct V_10 * V_10 = F_74 () ;
int V_60 = 0 ;
if ( V_576 &&
( V_574 & V_577 ) && ( ! V_48 || F_63 ( F_129 ( V_48 ) ) ||
( ! V_575 && ( V_574 & V_578 ) ) ) ) {
V_60 = F_114 ( V_10 , V_10 , V_579 ) ;
if ( V_60 )
goto error;
}
if ( V_48 ) {
T_2 V_286 = V_338 ;
if ( V_575 && ( V_574 & V_578 ) )
V_286 |= V_342 ;
if ( V_574 & V_577 )
V_286 |= V_336 ;
return F_130 ( V_10 , V_48 , V_286 ) ;
}
error:
return V_60 ;
}
static int F_255 ( unsigned long V_580 )
{
int V_60 = 0 ;
if ( V_580 < V_581 ) {
T_2 V_17 = F_22 () ;
V_60 = F_54 ( V_17 , V_17 , V_582 ,
V_583 , NULL ) ;
}
return V_60 ;
}
static int F_256 ( struct V_48 * V_48 , unsigned long V_584 ,
unsigned long V_574 , unsigned long V_85 )
{
if ( V_585 )
V_574 = V_584 ;
return F_254 ( V_48 , V_574 ,
( V_85 & V_586 ) == V_587 ) ;
}
static int F_257 ( struct V_588 * V_589 ,
unsigned long V_584 ,
unsigned long V_574 )
{
const struct V_10 * V_10 = F_74 () ;
if ( V_585 )
V_574 = V_584 ;
if ( V_576 &&
( V_574 & V_577 ) && ! ( V_589 -> V_590 & V_591 ) ) {
int V_60 = 0 ;
if ( V_589 -> V_592 >= V_589 -> V_593 -> V_594 &&
V_589 -> V_595 <= V_589 -> V_593 -> V_596 ) {
V_60 = F_114 ( V_10 , V_10 , V_597 ) ;
} else if ( ! V_589 -> V_598 &&
V_589 -> V_592 <= V_589 -> V_593 -> V_599 &&
V_589 -> V_595 >= V_589 -> V_593 -> V_599 ) {
V_60 = F_116 ( V_11 , V_600 ) ;
} else if ( V_589 -> V_598 && V_589 -> V_601 ) {
V_60 = F_130 ( V_10 , V_589 -> V_598 , V_602 ) ;
}
if ( V_60 )
return V_60 ;
}
return F_254 ( V_589 -> V_598 , V_574 , V_589 -> V_590 & V_603 ) ;
}
static int F_258 ( struct V_48 * V_48 , unsigned int V_553 )
{
const struct V_10 * V_10 = F_74 () ;
return F_130 ( V_10 , V_48 , V_604 ) ;
}
static int F_259 ( struct V_48 * V_48 , unsigned int V_553 ,
unsigned long V_561 )
{
const struct V_10 * V_10 = F_74 () ;
int V_605 = 0 ;
switch ( V_553 ) {
case V_606 :
if ( ( V_48 -> V_348 & V_349 ) && ! ( V_561 & V_349 ) ) {
V_605 = F_130 ( V_10 , V_48 , V_342 ) ;
break;
}
case V_607 :
case V_608 :
case V_609 :
case V_610 :
case V_611 :
case V_612 :
V_605 = F_130 ( V_10 , V_48 , 0 ) ;
break;
case V_613 :
case V_614 :
case V_615 :
case V_616 :
case V_617 :
case V_618 :
#if V_619 == 32
case V_620 :
case V_621 :
case V_622 :
#endif
V_605 = F_130 ( V_10 , V_48 , V_604 ) ;
break;
}
return V_605 ;
}
static void F_260 ( struct V_48 * V_48 )
{
struct V_49 * V_50 ;
V_50 = V_48 -> V_53 ;
V_50 -> V_52 = F_22 () ;
}
static int F_261 ( struct V_20 * V_279 ,
struct V_623 * V_624 , int V_625 )
{
struct V_48 * V_48 ;
T_2 V_17 = F_18 ( V_279 ) ;
T_2 V_259 ;
struct V_49 * V_50 ;
V_48 = F_38 ( V_624 , struct V_48 , V_626 ) ;
V_50 = V_48 -> V_53 ;
if ( ! V_625 )
V_259 = F_113 ( V_627 ) ;
else
V_259 = F_113 ( V_625 ) ;
return F_54 ( V_50 -> V_52 , V_17 ,
V_272 , V_259 , NULL ) ;
}
static int F_262 ( struct V_48 * V_48 )
{
const struct V_10 * V_10 = F_74 () ;
return F_130 ( V_10 , V_48 , F_141 ( V_48 ) ) ;
}
static int F_263 ( struct V_48 * V_48 , const struct V_10 * V_10 )
{
struct V_49 * V_50 ;
struct V_23 * V_24 ;
V_50 = V_48 -> V_53 ;
V_24 = F_34 ( F_129 ( V_48 ) ) ;
V_50 -> V_550 = V_24 -> V_17 ;
V_50 -> V_551 = F_248 () ;
return F_128 ( V_10 , V_48 , F_142 ( V_48 ) ) ;
}
static int F_264 ( unsigned long V_628 )
{
return F_116 ( V_11 , V_629 ) ;
}
static int F_265 ( struct V_10 * V_10 , T_12 V_630 )
{
struct V_13 * V_14 ;
V_14 = F_15 ( sizeof( struct V_13 ) , V_630 ) ;
if ( ! V_14 )
return - V_27 ;
V_10 -> V_19 = V_14 ;
return 0 ;
}
static void F_266 ( struct V_10 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_19 ;
F_70 ( V_10 -> V_19 && ( unsigned long ) V_10 -> V_19 < V_250 ) ;
V_10 -> V_19 = ( void * ) 0x7UL ;
F_51 ( V_14 ) ;
}
static int F_267 ( struct V_10 * V_134 , const struct V_10 * V_133 ,
T_12 V_630 )
{
const struct V_13 * V_411 ;
struct V_13 * V_14 ;
V_411 = V_133 -> V_19 ;
V_14 = F_268 ( V_411 , sizeof( struct V_13 ) , V_630 ) ;
if ( ! V_14 )
return - V_27 ;
V_134 -> V_19 = V_14 ;
return 0 ;
}
static void F_269 ( struct V_10 * V_134 , const struct V_10 * V_133 )
{
const struct V_13 * V_411 = V_133 -> V_19 ;
struct V_13 * V_14 = V_134 -> V_19 ;
* V_14 = * V_411 ;
}
static int F_270 ( struct V_10 * V_134 , T_2 V_549 )
{
struct V_13 * V_14 = V_134 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_631 ;
V_631 = F_54 ( V_17 , V_549 ,
V_632 ,
V_633 ,
NULL ) ;
if ( V_631 == 0 ) {
V_14 -> V_17 = V_549 ;
V_14 -> V_304 = 0 ;
V_14 -> V_422 = 0 ;
V_14 -> V_423 = 0 ;
}
return V_631 ;
}
static int F_271 ( struct V_10 * V_134 , struct V_22 * V_22 )
{
struct V_23 * V_24 = F_34 ( V_22 ) ;
struct V_13 * V_14 = V_134 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_631 ;
V_631 = F_54 ( V_17 , V_24 -> V_17 ,
V_632 ,
V_634 ,
NULL ) ;
if ( V_631 == 0 )
V_14 -> V_304 = V_24 -> V_17 ;
return V_631 ;
}
static int F_272 ( char * V_635 )
{
T_2 V_17 ;
struct V_282 V_283 ;
V_17 = F_18 ( V_11 ) ;
V_283 . type = V_636 ;
V_283 . V_288 . V_635 = V_635 ;
return F_54 ( V_17 , V_18 , V_293 ,
V_637 , & V_283 ) ;
}
static int F_273 ( struct V_20 * V_149 , T_13 V_638 )
{
return F_116 ( V_149 , V_639 ) ;
}
static int F_274 ( struct V_20 * V_149 )
{
return F_116 ( V_149 , V_640 ) ;
}
static int F_275 ( struct V_20 * V_149 )
{
return F_116 ( V_149 , V_641 ) ;
}
static void F_276 ( struct V_20 * V_149 , T_2 * V_549 )
{
* V_549 = F_18 ( V_149 ) ;
}
static int F_277 ( struct V_20 * V_149 , int V_642 )
{
return F_116 ( V_149 , V_643 ) ;
}
static int F_278 ( struct V_20 * V_149 , int V_644 )
{
return F_116 ( V_149 , V_643 ) ;
}
static int F_279 ( struct V_20 * V_149 )
{
return F_116 ( V_149 , V_645 ) ;
}
static int F_280 ( struct V_20 * V_149 , unsigned int V_646 ,
struct V_453 * V_647 )
{
struct V_453 * V_648 = V_149 -> signal -> V_454 + V_646 ;
if ( V_648 -> V_461 != V_647 -> V_461 )
return F_116 ( V_149 , V_649 ) ;
return 0 ;
}
static int F_281 ( struct V_20 * V_149 )
{
return F_116 ( V_149 , V_643 ) ;
}
static int F_282 ( struct V_20 * V_149 )
{
return F_116 ( V_149 , V_645 ) ;
}
static int F_283 ( struct V_20 * V_149 )
{
return F_116 ( V_149 , V_643 ) ;
}
static int F_284 ( struct V_20 * V_149 , struct V_650 * V_651 ,
int V_258 , T_2 V_549 )
{
T_2 V_259 ;
int V_60 ;
if ( ! V_258 )
V_259 = V_652 ;
else
V_259 = F_113 ( V_258 ) ;
if ( V_549 )
V_60 = F_54 ( V_549 , F_18 ( V_149 ) ,
V_272 , V_259 , NULL ) ;
else
V_60 = F_116 ( V_149 , V_259 ) ;
return V_60 ;
}
static int F_285 ( struct V_20 * V_149 )
{
return F_115 ( V_149 , V_11 , V_261 ) ;
}
static void F_286 ( struct V_20 * V_149 ,
struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 = F_18 ( V_149 ) ;
V_24 -> V_17 = V_17 ;
V_24 -> V_37 = V_130 ;
}
static int F_287 ( struct V_653 * V_654 ,
struct V_282 * V_283 , T_11 * V_655 )
{
int V_656 , V_657 , V_631 = - V_96 ;
struct V_658 V_659 , * V_660 ;
V_656 = F_288 ( V_654 ) ;
V_660 = F_289 ( V_654 , V_656 , sizeof( V_659 ) , & V_659 ) ;
if ( V_660 == NULL )
goto V_80;
V_657 = V_660 -> V_661 * 4 ;
if ( V_657 < sizeof( V_659 ) )
goto V_80;
V_283 -> V_288 . V_662 -> V_663 . V_664 = V_660 -> V_664 ;
V_283 -> V_288 . V_662 -> V_663 . V_665 = V_660 -> V_665 ;
V_631 = 0 ;
if ( V_655 )
* V_655 = V_660 -> V_187 ;
switch ( V_660 -> V_187 ) {
case V_189 : {
struct V_666 V_667 , * V_668 ;
if ( F_290 ( V_660 -> V_669 ) & V_670 )
break;
V_656 += V_657 ;
V_668 = F_289 ( V_654 , V_656 , sizeof( V_667 ) , & V_667 ) ;
if ( V_668 == NULL )
break;
V_283 -> V_288 . V_662 -> V_671 = V_668 -> V_672 ;
V_283 -> V_288 . V_662 -> V_673 = V_668 -> V_674 ;
break;
}
case V_190 : {
struct V_675 V_676 , * V_677 ;
if ( F_290 ( V_660 -> V_669 ) & V_670 )
break;
V_656 += V_657 ;
V_677 = F_289 ( V_654 , V_656 , sizeof( V_676 ) , & V_676 ) ;
if ( V_677 == NULL )
break;
V_283 -> V_288 . V_662 -> V_671 = V_677 -> V_672 ;
V_283 -> V_288 . V_662 -> V_673 = V_677 -> V_674 ;
break;
}
case V_678 : {
struct V_679 V_680 , * V_681 ;
if ( F_290 ( V_660 -> V_669 ) & V_670 )
break;
V_656 += V_657 ;
V_681 = F_289 ( V_654 , V_656 , sizeof( V_680 ) , & V_680 ) ;
if ( V_681 == NULL )
break;
V_283 -> V_288 . V_662 -> V_671 = V_681 -> V_682 ;
V_283 -> V_288 . V_662 -> V_673 = V_681 -> V_683 ;
break;
}
default:
break;
}
V_80:
return V_631 ;
}
static int F_291 ( struct V_653 * V_654 ,
struct V_282 * V_283 , T_11 * V_655 )
{
T_11 V_684 ;
int V_631 = - V_96 , V_656 ;
struct V_685 V_686 , * V_687 ;
T_14 V_669 ;
V_656 = F_288 ( V_654 ) ;
V_687 = F_289 ( V_654 , V_656 , sizeof( V_686 ) , & V_686 ) ;
if ( V_687 == NULL )
goto V_80;
V_283 -> V_288 . V_662 -> V_688 . V_664 = V_687 -> V_664 ;
V_283 -> V_288 . V_662 -> V_688 . V_665 = V_687 -> V_665 ;
V_631 = 0 ;
V_684 = V_687 -> V_684 ;
V_656 += sizeof( V_686 ) ;
V_656 = F_292 ( V_654 , V_656 , & V_684 , & V_669 ) ;
if ( V_656 < 0 )
goto V_80;
if ( V_655 )
* V_655 = V_684 ;
switch ( V_684 ) {
case V_189 : {
struct V_666 V_667 , * V_668 ;
V_668 = F_289 ( V_654 , V_656 , sizeof( V_667 ) , & V_667 ) ;
if ( V_668 == NULL )
break;
V_283 -> V_288 . V_662 -> V_671 = V_668 -> V_672 ;
V_283 -> V_288 . V_662 -> V_673 = V_668 -> V_674 ;
break;
}
case V_190 : {
struct V_675 V_676 , * V_677 ;
V_677 = F_289 ( V_654 , V_656 , sizeof( V_676 ) , & V_676 ) ;
if ( V_677 == NULL )
break;
V_283 -> V_288 . V_662 -> V_671 = V_677 -> V_672 ;
V_283 -> V_288 . V_662 -> V_673 = V_677 -> V_674 ;
break;
}
case V_678 : {
struct V_679 V_680 , * V_681 ;
V_681 = F_289 ( V_654 , V_656 , sizeof( V_680 ) , & V_680 ) ;
if ( V_681 == NULL )
break;
V_283 -> V_288 . V_662 -> V_671 = V_681 -> V_682 ;
V_283 -> V_288 . V_662 -> V_673 = V_681 -> V_683 ;
break;
}
default:
break;
}
V_80:
return V_631 ;
}
static int F_293 ( struct V_653 * V_654 , struct V_282 * V_283 ,
char * * V_689 , int V_690 , T_11 * V_655 )
{
char * V_691 ;
int V_631 ;
switch ( V_283 -> V_288 . V_662 -> V_191 ) {
case V_198 :
V_631 = F_287 ( V_654 , V_283 , V_655 ) ;
if ( V_631 )
goto V_692;
V_691 = ( char * ) ( V_690 ? & V_283 -> V_288 . V_662 -> V_663 . V_664 :
& V_283 -> V_288 . V_662 -> V_663 . V_665 ) ;
goto V_693;
#if F_294 ( V_694 ) || F_294 ( V_695 )
case V_199 :
V_631 = F_291 ( V_654 , V_283 , V_655 ) ;
if ( V_631 )
goto V_692;
V_691 = ( char * ) ( V_690 ? & V_283 -> V_288 . V_662 -> V_688 . V_664 :
& V_283 -> V_288 . V_662 -> V_688 . V_665 ) ;
goto V_693;
#endif
default:
V_691 = NULL ;
goto V_693;
}
V_692:
F_58 ( V_77
L_43
L_44 ) ;
return V_631 ;
V_693:
if ( V_689 )
* V_689 = V_691 ;
return 0 ;
}
static int F_295 ( struct V_653 * V_654 , T_4 V_191 , T_2 * V_17 )
{
int V_605 ;
T_2 V_696 ;
T_2 V_697 ;
T_2 V_698 ;
V_605 = F_296 ( V_654 , & V_696 ) ;
if ( F_125 ( V_605 ) )
return - V_420 ;
V_605 = F_297 ( V_654 , V_191 , & V_698 , & V_697 ) ;
if ( F_125 ( V_605 ) )
return - V_420 ;
V_605 = F_298 ( V_697 , V_698 , V_696 , V_17 ) ;
if ( F_125 ( V_605 ) ) {
F_58 ( V_77
L_45
L_46 ) ;
return - V_420 ;
}
return 0 ;
}
static int F_299 ( T_2 V_699 , T_2 V_700 , T_2 * V_701 )
{
int V_605 = 0 ;
if ( V_700 != V_702 )
V_605 = F_300 ( V_699 , V_700 , V_701 ) ;
else
* V_701 = V_699 ;
return V_605 ;
}
static int F_301 ( const struct V_13 * V_14 ,
T_4 V_703 , T_2 * V_704 )
{
if ( V_14 -> V_423 > V_702 ) {
* V_704 = V_14 -> V_423 ;
return 0 ;
}
return F_111 ( V_14 -> V_17 , V_14 -> V_17 , V_703 , NULL ,
V_704 ) ;
}
static int F_302 ( struct V_20 * V_21 , struct V_705 * V_706 , T_2 V_269 )
{
struct V_707 * V_708 = V_706 -> V_709 ;
struct V_282 V_283 ;
struct V_710 V_662 = { 0 ,} ;
T_2 V_271 = F_18 ( V_21 ) ;
if ( V_708 -> V_17 == V_18 )
return 0 ;
V_283 . type = V_711 ;
V_283 . V_288 . V_662 = & V_662 ;
V_283 . V_288 . V_662 -> V_706 = V_706 ;
return F_54 ( V_271 , V_708 -> V_17 , V_708 -> V_31 , V_269 , & V_283 ) ;
}
static int F_303 ( int V_191 , int type ,
int V_187 , int V_712 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_305 ;
T_4 V_703 ;
int V_60 ;
if ( V_712 )
return 0 ;
V_703 = F_95 ( V_191 , type , V_187 ) ;
V_60 = F_301 ( V_14 , V_703 , & V_305 ) ;
if ( V_60 )
return V_60 ;
return F_54 ( V_14 -> V_17 , V_305 , V_703 , V_713 , NULL ) ;
}
static int F_304 ( struct V_714 * V_705 , int V_191 ,
int type , int V_187 , int V_712 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_24 = F_31 ( F_305 ( V_705 ) ) ;
struct V_707 * V_708 ;
int V_605 = 0 ;
V_24 -> V_31 = F_95 ( V_191 , type , V_187 ) ;
if ( V_712 )
V_24 -> V_17 = V_18 ;
else {
V_605 = F_301 ( V_14 , V_24 -> V_31 , & ( V_24 -> V_17 ) ) ;
if ( V_605 )
return V_605 ;
}
V_24 -> V_37 = V_130 ;
if ( V_705 -> V_706 ) {
V_708 = V_705 -> V_706 -> V_709 ;
V_708 -> V_17 = V_24 -> V_17 ;
V_708 -> V_31 = V_24 -> V_31 ;
V_605 = F_306 ( V_705 -> V_706 , V_191 ) ;
}
return V_605 ;
}
static int F_307 ( struct V_714 * V_705 , struct V_715 * V_716 , int V_717 )
{
struct V_705 * V_706 = V_705 -> V_706 ;
T_4 V_191 ;
int V_605 ;
V_605 = F_302 ( V_11 , V_706 , V_718 ) ;
if ( V_605 )
goto V_80;
V_191 = V_706 -> V_719 ;
if ( V_191 == V_198 || V_191 == V_199 ) {
char * V_691 ;
struct V_707 * V_708 = V_706 -> V_709 ;
struct V_282 V_283 ;
struct V_710 V_662 = { 0 ,} ;
struct V_720 * V_721 = NULL ;
struct V_722 * V_723 = NULL ;
unsigned short V_724 ;
T_2 V_17 , V_725 ;
if ( V_191 == V_198 ) {
V_721 = (struct V_720 * ) V_716 ;
V_724 = F_290 ( V_721 -> V_726 ) ;
V_691 = ( char * ) & V_721 -> V_727 . V_728 ;
} else {
V_723 = (struct V_722 * ) V_716 ;
V_724 = F_290 ( V_723 -> V_729 ) ;
V_691 = ( char * ) & V_723 -> V_730 . V_731 ;
}
if ( V_724 ) {
int V_732 , V_733 ;
F_308 ( F_309 ( V_706 ) , & V_732 , & V_733 ) ;
if ( V_724 < V_734 ( V_735, V_732 ) || V_724 > V_733 ) {
V_605 = F_310 ( V_706 -> V_736 ,
V_724 , & V_17 ) ;
if ( V_605 )
goto V_80;
V_283 . type = V_711 ;
V_283 . V_288 . V_662 = & V_662 ;
V_283 . V_288 . V_662 -> V_671 = F_311 ( V_724 ) ;
V_283 . V_288 . V_662 -> V_191 = V_191 ;
V_605 = F_54 ( V_708 -> V_17 , V_17 ,
V_708 -> V_31 ,
V_737 , & V_283 ) ;
if ( V_605 )
goto V_80;
}
}
switch ( V_708 -> V_31 ) {
case V_200 :
V_725 = V_738 ;
break;
case V_202 :
V_725 = V_739 ;
break;
case V_204 :
V_725 = V_740 ;
break;
default:
V_725 = V_741 ;
break;
}
V_605 = F_312 ( V_691 , V_191 , & V_17 ) ;
if ( V_605 )
goto V_80;
V_283 . type = V_711 ;
V_283 . V_288 . V_662 = & V_662 ;
V_283 . V_288 . V_662 -> V_671 = F_311 ( V_724 ) ;
V_283 . V_288 . V_662 -> V_191 = V_191 ;
if ( V_191 == V_198 )
V_283 . V_288 . V_662 -> V_663 . V_664 = V_721 -> V_727 . V_728 ;
else
V_283 . V_288 . V_662 -> V_688 . V_664 = V_723 -> V_730 ;
V_605 = F_54 ( V_708 -> V_17 , V_17 ,
V_708 -> V_31 , V_725 , & V_283 ) ;
if ( V_605 )
goto V_80;
}
V_80:
return V_605 ;
}
static int F_313 ( struct V_714 * V_705 , struct V_715 * V_716 , int V_717 )
{
struct V_705 * V_706 = V_705 -> V_706 ;
struct V_707 * V_708 = V_706 -> V_709 ;
int V_605 ;
V_605 = F_302 ( V_11 , V_706 , V_742 ) ;
if ( V_605 )
return V_605 ;
if ( V_708 -> V_31 == V_200 ||
V_708 -> V_31 == V_204 ) {
struct V_282 V_283 ;
struct V_710 V_662 = { 0 ,} ;
struct V_720 * V_721 = NULL ;
struct V_722 * V_723 = NULL ;
unsigned short V_724 ;
T_2 V_17 , V_259 ;
if ( V_706 -> V_719 == V_198 ) {
V_721 = (struct V_720 * ) V_716 ;
if ( V_717 < sizeof( struct V_720 ) )
return - V_96 ;
V_724 = F_290 ( V_721 -> V_726 ) ;
} else {
V_723 = (struct V_722 * ) V_716 ;
if ( V_717 < V_743 )
return - V_96 ;
V_724 = F_290 ( V_723 -> V_729 ) ;
}
V_605 = F_310 ( V_706 -> V_736 , V_724 , & V_17 ) ;
if ( V_605 )
goto V_80;
V_259 = ( V_708 -> V_31 == V_200 ) ?
V_744 : V_745 ;
V_283 . type = V_711 ;
V_283 . V_288 . V_662 = & V_662 ;
V_283 . V_288 . V_662 -> V_673 = F_311 ( V_724 ) ;
V_283 . V_288 . V_662 -> V_191 = V_706 -> V_719 ;
V_605 = F_54 ( V_708 -> V_17 , V_17 , V_708 -> V_31 , V_259 , & V_283 ) ;
if ( V_605 )
goto V_80;
}
V_605 = F_314 ( V_706 , V_716 ) ;
V_80:
return V_605 ;
}
static int F_315 ( struct V_714 * V_705 , int V_746 )
{
return F_302 ( V_11 , V_705 -> V_706 , V_747 ) ;
}
static int F_316 ( struct V_714 * V_705 , struct V_714 * V_748 )
{
int V_605 ;
struct V_23 * V_24 ;
struct V_23 * V_146 ;
V_605 = F_302 ( V_11 , V_705 -> V_706 , V_749 ) ;
if ( V_605 )
return V_605 ;
V_146 = F_31 ( F_305 ( V_748 ) ) ;
V_24 = F_31 ( F_305 ( V_705 ) ) ;
V_146 -> V_31 = V_24 -> V_31 ;
V_146 -> V_17 = V_24 -> V_17 ;
V_146 -> V_37 = V_130 ;
return 0 ;
}
static int F_317 ( struct V_714 * V_705 , struct V_750 * V_751 ,
int V_536 )
{
return F_302 ( V_11 , V_705 -> V_706 , V_752 ) ;
}
static int F_318 ( struct V_714 * V_705 , struct V_750 * V_751 ,
int V_536 , int V_85 )
{
return F_302 ( V_11 , V_705 -> V_706 , V_753 ) ;
}
static int F_319 ( struct V_714 * V_705 )
{
return F_302 ( V_11 , V_705 -> V_706 , V_754 ) ;
}
static int F_320 ( struct V_714 * V_705 )
{
return F_302 ( V_11 , V_705 -> V_706 , V_754 ) ;
}
static int F_321 ( struct V_714 * V_705 , int V_755 , int V_756 )
{
int V_605 ;
V_605 = F_302 ( V_11 , V_705 -> V_706 , V_757 ) ;
if ( V_605 )
return V_605 ;
return F_322 ( V_705 , V_755 , V_756 ) ;
}
static int F_323 ( struct V_714 * V_705 , int V_755 ,
int V_756 )
{
return F_302 ( V_11 , V_705 -> V_706 , V_758 ) ;
}
static int F_324 ( struct V_714 * V_705 , int V_759 )
{
return F_302 ( V_11 , V_705 -> V_706 , V_760 ) ;
}
static int F_325 ( struct V_705 * V_705 ,
struct V_705 * V_761 ,
struct V_705 * V_762 )
{
struct V_707 * V_763 = V_705 -> V_709 ;
struct V_707 * V_764 = V_761 -> V_709 ;
struct V_707 * V_765 = V_762 -> V_709 ;
struct V_282 V_283 ;
struct V_710 V_662 = { 0 ,} ;
int V_605 ;
V_283 . type = V_711 ;
V_283 . V_288 . V_662 = & V_662 ;
V_283 . V_288 . V_662 -> V_706 = V_761 ;
V_605 = F_54 ( V_763 -> V_17 , V_764 -> V_17 ,
V_764 -> V_31 ,
V_766 , & V_283 ) ;
if ( V_605 )
return V_605 ;
V_765 -> V_767 = V_763 -> V_17 ;
V_605 = F_300 ( V_764 -> V_17 , V_763 -> V_17 ,
& V_765 -> V_17 ) ;
if ( V_605 )
return V_605 ;
V_763 -> V_767 = V_765 -> V_17 ;
return 0 ;
}
static int F_326 ( struct V_714 * V_705 ,
struct V_714 * V_761 )
{
struct V_707 * V_768 = V_705 -> V_706 -> V_709 ;
struct V_707 * V_769 = V_761 -> V_706 -> V_709 ;
struct V_282 V_283 ;
struct V_710 V_662 = { 0 ,} ;
V_283 . type = V_711 ;
V_283 . V_288 . V_662 = & V_662 ;
V_283 . V_288 . V_662 -> V_706 = V_761 -> V_706 ;
return F_54 ( V_768 -> V_17 , V_769 -> V_17 , V_769 -> V_31 , V_770 ,
& V_283 ) ;
}
static int F_327 ( struct V_662 * V_376 , int V_771 ,
char * V_691 , T_4 V_191 , T_2 V_767 ,
struct V_282 * V_283 )
{
int V_605 ;
T_2 V_772 ;
T_2 V_773 ;
V_605 = F_328 ( V_376 , V_771 , & V_772 ) ;
if ( V_605 )
return V_605 ;
V_605 = F_54 ( V_767 , V_772 ,
V_774 , V_775 , V_283 ) ;
if ( V_605 )
return V_605 ;
V_605 = F_312 ( V_691 , V_191 , & V_773 ) ;
if ( V_605 )
return V_605 ;
return F_54 ( V_767 , V_773 ,
V_776 , V_777 , V_283 ) ;
}
static int F_329 ( struct V_705 * V_706 , struct V_653 * V_654 ,
T_4 V_191 )
{
int V_605 = 0 ;
struct V_707 * V_708 = V_706 -> V_709 ;
T_2 V_699 = V_708 -> V_17 ;
struct V_282 V_283 ;
struct V_710 V_662 = { 0 ,} ;
char * V_691 ;
V_283 . type = V_711 ;
V_283 . V_288 . V_662 = & V_662 ;
V_283 . V_288 . V_662 -> V_778 = V_654 -> V_779 ;
V_283 . V_288 . V_662 -> V_191 = V_191 ;
V_605 = F_293 ( V_654 , & V_283 , & V_691 , 1 , NULL ) ;
if ( V_605 )
return V_605 ;
if ( F_4 () ) {
V_605 = F_54 ( V_699 , V_654 -> V_780 , V_781 ,
V_782 , & V_283 ) ;
if ( V_605 )
return V_605 ;
}
V_605 = F_330 ( V_708 , V_654 , V_191 , & V_283 ) ;
if ( V_605 )
return V_605 ;
V_605 = F_331 ( V_708 -> V_17 , V_654 , & V_283 ) ;
return V_605 ;
}
static int F_332 ( struct V_705 * V_706 , struct V_653 * V_654 )
{
int V_605 ;
struct V_707 * V_708 = V_706 -> V_709 ;
T_4 V_191 = V_706 -> V_719 ;
T_2 V_699 = V_708 -> V_17 ;
struct V_282 V_283 ;
struct V_710 V_662 = { 0 ,} ;
char * V_691 ;
T_11 V_783 ;
T_11 V_784 ;
if ( V_191 != V_198 && V_191 != V_199 )
return 0 ;
if ( V_191 == V_199 && V_654 -> V_187 == F_311 ( V_785 ) )
V_191 = V_198 ;
if ( ! V_786 )
return F_329 ( V_706 , V_654 , V_191 ) ;
V_783 = F_4 () ;
V_784 = F_6 () ;
if ( ! V_783 && ! V_784 )
return 0 ;
V_283 . type = V_711 ;
V_283 . V_288 . V_662 = & V_662 ;
V_283 . V_288 . V_662 -> V_778 = V_654 -> V_779 ;
V_283 . V_288 . V_662 -> V_191 = V_191 ;
V_605 = F_293 ( V_654 , & V_283 , & V_691 , 1 , NULL ) ;
if ( V_605 )
return V_605 ;
if ( V_784 ) {
T_2 V_767 ;
V_605 = F_295 ( V_654 , V_191 , & V_767 ) ;
if ( V_605 )
return V_605 ;
V_605 = F_327 ( F_309 ( V_706 ) , V_654 -> V_779 ,
V_691 , V_191 , V_767 , & V_283 ) ;
if ( V_605 ) {
F_333 ( V_654 , V_605 , 0 ) ;
return V_605 ;
}
V_605 = F_54 ( V_699 , V_767 , V_787 ,
V_788 , & V_283 ) ;
if ( V_605 ) {
F_333 ( V_654 , V_605 , 0 ) ;
return V_605 ;
}
}
if ( V_783 ) {
V_605 = F_54 ( V_699 , V_654 -> V_780 , V_781 ,
V_782 , & V_283 ) ;
if ( V_605 )
return V_605 ;
}
return V_605 ;
}
static int F_334 ( struct V_714 * V_705 , char T_15 * V_789 ,
int T_15 * V_790 , unsigned V_94 )
{
int V_605 = 0 ;
char * V_791 ;
T_2 V_792 ;
struct V_707 * V_708 = V_705 -> V_706 -> V_709 ;
T_2 V_767 = V_702 ;
if ( V_708 -> V_31 == V_195 ||
V_708 -> V_31 == V_200 )
V_767 = V_708 -> V_767 ;
if ( V_767 == V_702 )
return - V_793 ;
V_605 = F_69 ( V_767 , & V_791 , & V_792 ) ;
if ( V_605 )
return V_605 ;
if ( V_792 > V_94 ) {
V_605 = - V_252 ;
goto V_794;
}
if ( F_335 ( V_789 , V_791 , V_792 ) )
V_605 = - V_795 ;
V_794:
if ( F_336 ( V_792 , V_790 ) )
V_605 = - V_795 ;
F_51 ( V_791 ) ;
return V_605 ;
}
static int F_337 ( struct V_714 * V_705 , struct V_653 * V_654 , T_2 * V_549 )
{
T_2 V_796 = V_702 ;
T_4 V_191 ;
if ( V_654 && V_654 -> V_187 == F_311 ( V_785 ) )
V_191 = V_198 ;
else if ( V_654 && V_654 -> V_187 == F_311 ( V_797 ) )
V_191 = V_199 ;
else if ( V_705 )
V_191 = V_705 -> V_706 -> V_719 ;
else
goto V_80;
if ( V_705 && V_191 == V_192 )
F_245 ( F_305 ( V_705 ) , & V_796 ) ;
else if ( V_654 )
F_295 ( V_654 , V_191 , & V_796 ) ;
V_80:
* V_549 = V_796 ;
if ( V_796 == V_702 )
return - V_96 ;
return 0 ;
}
static int F_338 ( struct V_705 * V_706 , int V_191 , T_12 V_798 )
{
struct V_707 * V_708 ;
V_708 = F_15 ( sizeof( * V_708 ) , V_798 ) ;
if ( ! V_708 )
return - V_27 ;
V_708 -> V_767 = V_30 ;
V_708 -> V_17 = V_30 ;
V_708 -> V_31 = V_245 ;
F_339 ( V_708 ) ;
V_706 -> V_709 = V_708 ;
return 0 ;
}
static void F_340 ( struct V_705 * V_706 )
{
struct V_707 * V_708 = V_706 -> V_709 ;
V_706 -> V_709 = NULL ;
F_341 ( V_708 ) ;
F_51 ( V_708 ) ;
}
static void F_342 ( const struct V_705 * V_706 , struct V_705 * V_762 )
{
struct V_707 * V_708 = V_706 -> V_709 ;
struct V_707 * V_799 = V_762 -> V_709 ;
V_799 -> V_17 = V_708 -> V_17 ;
V_799 -> V_767 = V_708 -> V_767 ;
V_799 -> V_31 = V_708 -> V_31 ;
F_339 ( V_799 ) ;
}
static void F_343 ( struct V_705 * V_706 , T_2 * V_549 )
{
if ( ! V_706 )
* V_549 = V_800 ;
else {
struct V_707 * V_708 = V_706 -> V_709 ;
* V_549 = V_708 -> V_17 ;
}
}
static void F_344 ( struct V_705 * V_706 , struct V_714 * V_369 )
{
struct V_23 * V_24 =
F_31 ( F_305 ( V_369 ) ) ;
struct V_707 * V_708 = V_706 -> V_709 ;
if ( V_706 -> V_719 == V_198 || V_706 -> V_719 == V_199 ||
V_706 -> V_719 == V_192 )
V_24 -> V_17 = V_708 -> V_17 ;
V_708 -> V_31 = V_24 -> V_31 ;
}
static int F_345 ( struct V_705 * V_706 , struct V_653 * V_654 ,
struct V_801 * V_802 )
{
struct V_707 * V_708 = V_706 -> V_709 ;
int V_605 ;
T_4 V_191 = V_802 -> V_803 -> V_191 ;
T_2 V_804 ;
T_2 V_805 ;
V_605 = F_295 ( V_654 , V_191 , & V_805 ) ;
if ( V_605 )
return V_605 ;
V_605 = F_299 ( V_708 -> V_17 , V_805 , & V_804 ) ;
if ( V_605 )
return V_605 ;
V_802 -> V_549 = V_804 ;
V_802 -> V_796 = V_805 ;
return F_346 ( V_802 , V_191 ) ;
}
static void F_347 ( struct V_705 * V_762 ,
const struct V_801 * V_802 )
{
struct V_707 * V_799 = V_762 -> V_709 ;
V_799 -> V_17 = V_802 -> V_549 ;
V_799 -> V_767 = V_802 -> V_796 ;
F_348 ( V_762 , V_802 -> V_803 -> V_191 ) ;
}
static void F_349 ( struct V_705 * V_706 , struct V_653 * V_654 )
{
T_4 V_191 = V_706 -> V_719 ;
struct V_707 * V_708 = V_706 -> V_709 ;
if ( V_191 == V_199 && V_654 -> V_187 == F_311 ( V_785 ) )
V_191 = V_198 ;
F_295 ( V_654 , V_191 , & V_708 -> V_767 ) ;
}
static int F_350 ( T_2 V_17 )
{
const struct V_13 * V_806 ;
T_2 V_271 ;
V_806 = F_23 () ;
V_271 = V_806 -> V_17 ;
return F_54 ( V_271 , V_17 , V_781 , V_807 , NULL ) ;
}
static void F_351 ( void )
{
F_352 ( & V_7 ) ;
}
static void F_353 ( void )
{
F_354 ( & V_7 ) ;
}
static void F_355 ( const struct V_801 * V_802 ,
struct V_808 * V_809 )
{
V_809 -> V_810 = V_802 -> V_549 ;
}
static int F_356 ( void * * V_19 )
{
struct V_811 * V_812 ;
V_812 = F_15 ( sizeof( * V_812 ) , V_15 ) ;
if ( ! V_812 )
return - V_27 ;
V_812 -> V_17 = F_22 () ;
* V_19 = V_812 ;
return 0 ;
}
static void F_357 ( void * V_19 )
{
F_51 ( V_19 ) ;
}
static int F_358 ( void )
{
T_2 V_17 = F_22 () ;
return F_54 ( V_17 , V_17 , V_813 , V_814 ,
NULL ) ;
}
static int F_359 ( void * V_19 )
{
struct V_811 * V_812 = V_19 ;
return F_54 ( F_22 () , V_812 -> V_17 , V_813 ,
V_815 , NULL ) ;
}
static int F_360 ( struct V_705 * V_706 , void * V_19 )
{
struct V_811 * V_812 = V_19 ;
struct V_707 * V_708 = V_706 -> V_709 ;
V_708 -> V_17 = V_812 -> V_17 ;
V_708 -> V_31 = V_813 ;
return 0 ;
}
static int F_361 ( void * V_19 )
{
struct V_811 * V_812 = V_19 ;
T_2 V_17 = F_22 () ;
int V_605 ;
V_605 = F_54 ( V_17 , V_812 -> V_17 , V_813 ,
V_816 , NULL ) ;
if ( V_605 )
return V_605 ;
V_605 = F_54 ( V_17 , V_17 , V_813 ,
V_817 , NULL ) ;
if ( V_605 )
return V_605 ;
V_812 -> V_17 = V_17 ;
return 0 ;
}
static int F_362 ( struct V_705 * V_706 , struct V_653 * V_654 )
{
int V_605 = 0 ;
T_2 V_259 ;
struct V_818 * V_819 ;
struct V_707 * V_708 = V_706 -> V_709 ;
if ( V_654 -> V_94 < V_820 ) {
V_605 = - V_96 ;
goto V_80;
}
V_819 = F_363 ( V_654 ) ;
V_605 = F_364 ( V_708 -> V_31 , V_819 -> V_821 , & V_259 ) ;
if ( V_605 ) {
if ( V_605 == - V_96 ) {
F_365 ( L_47
L_48
L_49 ,
V_706 -> V_736 , V_819 -> V_821 ,
V_822 [ V_708 -> V_31 - 1 ] . V_71 ,
F_366 ( V_11 ) , V_11 -> V_823 ) ;
if ( ! V_3 || F_367 () )
V_605 = 0 ;
}
if ( V_605 == - V_824 )
V_605 = 0 ;
goto V_80;
}
V_605 = F_302 ( V_11 , V_706 , V_259 ) ;
V_80:
return V_605 ;
}
static unsigned int F_368 ( struct V_653 * V_654 ,
const struct V_825 * V_826 ,
T_4 V_191 )
{
int V_605 ;
char * V_691 ;
T_2 V_767 ;
struct V_282 V_283 ;
struct V_710 V_662 = { 0 ,} ;
T_11 V_783 ;
T_11 V_827 ;
T_11 V_784 ;
if ( ! V_786 )
return V_828 ;
V_783 = F_4 () ;
V_827 = F_7 () ;
V_784 = F_6 () ;
if ( ! V_783 && ! V_784 )
return V_828 ;
if ( F_295 ( V_654 , V_191 , & V_767 ) != 0 )
return V_829 ;
V_283 . type = V_711 ;
V_283 . V_288 . V_662 = & V_662 ;
V_283 . V_288 . V_662 -> V_778 = V_826 -> V_771 ;
V_283 . V_288 . V_662 -> V_191 = V_191 ;
if ( F_293 ( V_654 , & V_283 , & V_691 , 1 , NULL ) != 0 )
return V_829 ;
if ( V_784 ) {
V_605 = F_327 ( F_369 ( V_826 ) , V_826 -> V_771 ,
V_691 , V_191 , V_767 , & V_283 ) ;
if ( V_605 ) {
F_333 ( V_654 , V_605 , 1 ) ;
return V_829 ;
}
}
if ( V_783 )
if ( F_54 ( V_767 , V_654 -> V_780 ,
V_781 , V_830 , & V_283 ) )
return V_829 ;
if ( V_827 )
if ( F_370 ( V_654 , V_191 , V_767 ) != 0 )
return V_829 ;
return V_828 ;
}
static unsigned int F_371 ( void * V_831 ,
struct V_653 * V_654 ,
const struct V_832 * V_833 )
{
return F_368 ( V_654 , V_833 -> V_834 , V_198 ) ;
}
static unsigned int F_372 ( void * V_831 ,
struct V_653 * V_654 ,
const struct V_832 * V_833 )
{
return F_368 ( V_654 , V_833 -> V_834 , V_199 ) ;
}
static unsigned int F_373 ( struct V_653 * V_654 ,
T_4 V_191 )
{
struct V_705 * V_706 ;
T_2 V_17 ;
if ( ! F_7 () )
return V_828 ;
V_706 = V_654 -> V_706 ;
if ( V_706 ) {
struct V_707 * V_708 ;
if ( F_374 ( V_706 ) )
return V_828 ;
V_708 = V_706 -> V_709 ;
V_17 = V_708 -> V_17 ;
} else
V_17 = V_18 ;
if ( F_370 ( V_654 , V_191 , V_17 ) != 0 )
return V_829 ;
return V_828 ;
}
static unsigned int F_375 ( void * V_831 ,
struct V_653 * V_654 ,
const struct V_832 * V_833 )
{
return F_373 ( V_654 , V_198 ) ;
}
static unsigned int F_376 ( struct V_653 * V_654 ,
int V_771 ,
T_4 V_191 )
{
struct V_705 * V_706 = F_377 ( V_654 ) ;
struct V_707 * V_708 ;
struct V_282 V_283 ;
struct V_710 V_662 = { 0 ,} ;
char * V_691 ;
T_11 V_655 ;
if ( V_706 == NULL )
return V_828 ;
V_708 = V_706 -> V_709 ;
V_283 . type = V_711 ;
V_283 . V_288 . V_662 = & V_662 ;
V_283 . V_288 . V_662 -> V_778 = V_771 ;
V_283 . V_288 . V_662 -> V_191 = V_191 ;
if ( F_293 ( V_654 , & V_283 , & V_691 , 0 , & V_655 ) )
return V_829 ;
if ( F_4 () )
if ( F_54 ( V_708 -> V_17 , V_654 -> V_780 ,
V_781 , V_835 , & V_283 ) )
return F_378 ( - V_836 ) ;
if ( F_379 ( V_708 -> V_17 , V_654 , & V_283 , V_655 ) )
return F_378 ( - V_836 ) ;
return V_828 ;
}
static unsigned int F_380 ( struct V_653 * V_654 ,
const struct V_825 * V_837 ,
T_4 V_191 )
{
T_2 V_838 ;
T_2 V_767 ;
int V_771 = V_837 -> V_771 ;
struct V_705 * V_706 ;
struct V_282 V_283 ;
struct V_710 V_662 = { 0 ,} ;
char * V_691 ;
T_11 V_783 ;
T_11 V_784 ;
if ( ! V_786 )
return F_376 ( V_654 , V_771 , V_191 ) ;
V_783 = F_4 () ;
V_784 = F_6 () ;
if ( ! V_783 && ! V_784 )
return V_828 ;
V_706 = F_377 ( V_654 ) ;
#ifdef F_381
if ( F_382 ( V_654 ) != NULL && F_382 ( V_654 ) -> V_839 != NULL &&
! ( V_706 && F_374 ( V_706 ) ) )
return V_828 ;
#endif
if ( V_706 == NULL ) {
if ( V_654 -> V_779 ) {
V_838 = V_840 ;
if ( F_295 ( V_654 , V_191 , & V_767 ) )
return V_829 ;
} else {
V_838 = V_835 ;
V_767 = V_18 ;
}
} else if ( F_374 ( V_706 ) ) {
T_2 V_700 ;
struct V_707 * V_708 ;
V_708 = V_706 -> V_709 ;
if ( F_295 ( V_654 , V_191 , & V_700 ) )
return V_829 ;
if ( V_700 == V_702 ) {
switch ( V_191 ) {
case V_198 :
if ( F_383 ( V_654 ) -> V_85 & V_841 )
return V_828 ;
break;
case V_199 :
if ( F_384 ( V_654 ) -> V_85 & V_842 )
return V_828 ;
break;
default:
return F_378 ( - V_836 ) ;
}
}
if ( F_299 ( V_708 -> V_17 , V_700 , & V_767 ) )
return V_829 ;
V_838 = V_835 ;
} else {
struct V_707 * V_708 = V_706 -> V_709 ;
V_767 = V_708 -> V_17 ;
V_838 = V_835 ;
}
V_283 . type = V_711 ;
V_283 . V_288 . V_662 = & V_662 ;
V_283 . V_288 . V_662 -> V_778 = V_771 ;
V_283 . V_288 . V_662 -> V_191 = V_191 ;
if ( F_293 ( V_654 , & V_283 , & V_691 , 0 , NULL ) )
return V_829 ;
if ( V_783 )
if ( F_54 ( V_767 , V_654 -> V_780 ,
V_781 , V_838 , & V_283 ) )
return F_378 ( - V_836 ) ;
if ( V_784 ) {
T_2 V_772 ;
T_2 V_773 ;
if ( F_328 ( F_369 ( V_837 ) , V_771 , & V_772 ) )
return V_829 ;
if ( F_54 ( V_767 , V_772 ,
V_774 , V_843 , & V_283 ) )
return F_378 ( - V_836 ) ;
if ( F_312 ( V_691 , V_191 , & V_773 ) )
return V_829 ;
if ( F_54 ( V_767 , V_773 ,
V_776 , V_844 , & V_283 ) )
return F_378 ( - V_836 ) ;
}
return V_828 ;
}
static unsigned int F_385 ( void * V_831 ,
struct V_653 * V_654 ,
const struct V_832 * V_833 )
{
return F_380 ( V_654 , V_833 -> V_80 , V_198 ) ;
}
static unsigned int F_386 ( void * V_831 ,
struct V_653 * V_654 ,
const struct V_832 * V_833 )
{
return F_380 ( V_654 , V_833 -> V_80 , V_199 ) ;
}
static int F_387 ( struct V_705 * V_706 , struct V_653 * V_654 )
{
return F_362 ( V_706 , V_654 ) ;
}
static int F_388 ( struct V_20 * V_21 ,
struct V_845 * V_259 ,
T_4 V_31 )
{
struct V_846 * V_24 ;
T_2 V_17 ;
V_24 = F_15 ( sizeof( struct V_846 ) , V_15 ) ;
if ( ! V_24 )
return - V_27 ;
V_17 = F_18 ( V_21 ) ;
V_24 -> V_31 = V_31 ;
V_24 -> V_17 = V_17 ;
V_259 -> V_19 = V_24 ;
return 0 ;
}
static void F_389 ( struct V_845 * V_259 )
{
struct V_846 * V_24 = V_259 -> V_19 ;
V_259 -> V_19 = NULL ;
F_51 ( V_24 ) ;
}
static int F_390 ( struct V_847 * V_751 )
{
struct V_848 * V_849 ;
V_849 = F_15 ( sizeof( struct V_848 ) , V_15 ) ;
if ( ! V_849 )
return - V_27 ;
V_849 -> V_17 = V_30 ;
V_751 -> V_19 = V_849 ;
return 0 ;
}
static void F_391 ( struct V_847 * V_751 )
{
struct V_848 * V_849 = V_751 -> V_19 ;
V_751 -> V_19 = NULL ;
F_51 ( V_849 ) ;
}
static int F_392 ( struct V_845 * V_850 ,
T_2 V_269 )
{
struct V_846 * V_24 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
V_24 = V_850 -> V_19 ;
V_283 . type = V_851 ;
V_283 . V_288 . V_852 = V_850 -> V_853 ;
return F_54 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_269 , & V_283 ) ;
}
static int F_393 ( struct V_847 * V_751 )
{
return F_390 ( V_751 ) ;
}
static void F_394 ( struct V_847 * V_751 )
{
F_391 ( V_751 ) ;
}
static int F_395 ( struct V_854 * V_855 )
{
struct V_846 * V_24 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
int V_60 ;
V_60 = F_388 ( V_11 , & V_855 -> V_856 , V_857 ) ;
if ( V_60 )
return V_60 ;
V_24 = V_855 -> V_856 . V_19 ;
V_283 . type = V_851 ;
V_283 . V_288 . V_852 = V_855 -> V_856 . V_853 ;
V_60 = F_54 ( V_17 , V_24 -> V_17 , V_857 ,
V_858 , & V_283 ) ;
if ( V_60 ) {
F_389 ( & V_855 -> V_856 ) ;
return V_60 ;
}
return 0 ;
}
static void F_396 ( struct V_854 * V_855 )
{
F_389 ( & V_855 -> V_856 ) ;
}
static int F_397 ( struct V_854 * V_855 , int V_859 )
{
struct V_846 * V_24 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
V_24 = V_855 -> V_856 . V_19 ;
V_283 . type = V_851 ;
V_283 . V_288 . V_852 = V_855 -> V_856 . V_853 ;
return F_54 ( V_17 , V_24 -> V_17 , V_857 ,
V_860 , & V_283 ) ;
}
static int F_398 ( struct V_854 * V_855 , int V_553 )
{
int V_605 ;
int V_269 ;
switch ( V_553 ) {
case V_861 :
case V_862 :
return F_122 ( V_11 , V_863 ) ;
case V_864 :
case V_865 :
V_269 = V_866 | V_860 ;
break;
case V_867 :
V_269 = V_868 ;
break;
case V_869 :
V_269 = V_870 ;
break;
default:
return 0 ;
}
V_605 = F_392 ( & V_855 -> V_856 , V_269 ) ;
return V_605 ;
}
static int F_399 ( struct V_854 * V_855 , struct V_847 * V_751 , int V_859 )
{
struct V_846 * V_24 ;
struct V_848 * V_849 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
int V_60 ;
V_24 = V_855 -> V_856 . V_19 ;
V_849 = V_751 -> V_19 ;
if ( V_849 -> V_17 == V_30 ) {
V_60 = F_111 ( V_17 , V_24 -> V_17 , V_871 ,
NULL , & V_849 -> V_17 ) ;
if ( V_60 )
return V_60 ;
}
V_283 . type = V_851 ;
V_283 . V_288 . V_852 = V_855 -> V_856 . V_853 ;
V_60 = F_54 ( V_17 , V_24 -> V_17 , V_857 ,
V_872 , & V_283 ) ;
if ( ! V_60 )
V_60 = F_54 ( V_17 , V_849 -> V_17 , V_871 ,
V_873 , & V_283 ) ;
if ( ! V_60 )
V_60 = F_54 ( V_849 -> V_17 , V_24 -> V_17 , V_857 ,
V_874 , & V_283 ) ;
return V_60 ;
}
static int F_400 ( struct V_854 * V_855 , struct V_847 * V_751 ,
struct V_20 * V_268 ,
long type , int V_172 )
{
struct V_846 * V_24 ;
struct V_848 * V_849 ;
struct V_282 V_283 ;
T_2 V_17 = F_18 ( V_268 ) ;
int V_60 ;
V_24 = V_855 -> V_856 . V_19 ;
V_849 = V_751 -> V_19 ;
V_283 . type = V_851 ;
V_283 . V_288 . V_852 = V_855 -> V_856 . V_853 ;
V_60 = F_54 ( V_17 , V_24 -> V_17 ,
V_857 , V_875 , & V_283 ) ;
if ( ! V_60 )
V_60 = F_54 ( V_17 , V_849 -> V_17 ,
V_871 , V_876 , & V_283 ) ;
return V_60 ;
}
static int F_401 ( struct V_877 * V_878 )
{
struct V_846 * V_24 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
int V_60 ;
V_60 = F_388 ( V_11 , & V_878 -> V_879 , V_880 ) ;
if ( V_60 )
return V_60 ;
V_24 = V_878 -> V_879 . V_19 ;
V_283 . type = V_851 ;
V_283 . V_288 . V_852 = V_878 -> V_879 . V_853 ;
V_60 = F_54 ( V_17 , V_24 -> V_17 , V_880 ,
V_881 , & V_283 ) ;
if ( V_60 ) {
F_389 ( & V_878 -> V_879 ) ;
return V_60 ;
}
return 0 ;
}
static void F_402 ( struct V_877 * V_878 )
{
F_389 ( & V_878 -> V_879 ) ;
}
static int F_403 ( struct V_877 * V_878 , int V_882 )
{
struct V_846 * V_24 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
V_24 = V_878 -> V_879 . V_19 ;
V_283 . type = V_851 ;
V_283 . V_288 . V_852 = V_878 -> V_879 . V_853 ;
return F_54 ( V_17 , V_24 -> V_17 , V_880 ,
V_883 , & V_283 ) ;
}
static int F_404 ( struct V_877 * V_878 , int V_553 )
{
int V_269 ;
int V_605 ;
switch ( V_553 ) {
case V_861 :
case V_884 :
return F_122 ( V_11 , V_863 ) ;
case V_864 :
case V_885 :
V_269 = V_886 | V_883 ;
break;
case V_867 :
V_269 = V_887 ;
break;
case V_888 :
case V_889 :
V_269 = V_890 ;
break;
case V_869 :
V_269 = V_891 ;
break;
default:
return 0 ;
}
V_605 = F_392 ( & V_878 -> V_879 , V_269 ) ;
return V_605 ;
}
static int F_405 ( struct V_877 * V_878 ,
char T_15 * V_892 , int V_882 )
{
T_2 V_269 ;
if ( V_882 & V_893 )
V_269 = V_894 ;
else
V_269 = V_894 | V_895 ;
return F_392 ( & V_878 -> V_879 , V_269 ) ;
}
static int F_406 ( struct V_896 * V_897 )
{
struct V_846 * V_24 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
int V_60 ;
V_60 = F_388 ( V_11 , & V_897 -> V_898 , V_899 ) ;
if ( V_60 )
return V_60 ;
V_24 = V_897 -> V_898 . V_19 ;
V_283 . type = V_851 ;
V_283 . V_288 . V_852 = V_897 -> V_898 . V_853 ;
V_60 = F_54 ( V_17 , V_24 -> V_17 , V_899 ,
V_900 , & V_283 ) ;
if ( V_60 ) {
F_389 ( & V_897 -> V_898 ) ;
return V_60 ;
}
return 0 ;
}
static void F_407 ( struct V_896 * V_897 )
{
F_389 ( & V_897 -> V_898 ) ;
}
static int F_408 ( struct V_896 * V_897 , int V_901 )
{
struct V_846 * V_24 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
V_24 = V_897 -> V_898 . V_19 ;
V_283 . type = V_851 ;
V_283 . V_288 . V_852 = V_897 -> V_898 . V_853 ;
return F_54 ( V_17 , V_24 -> V_17 , V_899 ,
V_902 , & V_283 ) ;
}
static int F_409 ( struct V_896 * V_897 , int V_553 )
{
int V_605 ;
T_2 V_269 ;
switch ( V_553 ) {
case V_861 :
case V_903 :
return F_122 ( V_11 , V_863 ) ;
case V_904 :
case V_905 :
case V_906 :
V_269 = V_907 ;
break;
case V_908 :
case V_909 :
V_269 = V_910 ;
break;
case V_911 :
case V_912 :
V_269 = V_913 ;
break;
case V_869 :
V_269 = V_914 ;
break;
case V_867 :
V_269 = V_915 ;
break;
case V_864 :
case V_916 :
V_269 = V_907 | V_902 ;
break;
default:
return 0 ;
}
V_605 = F_392 ( & V_897 -> V_898 , V_269 ) ;
return V_605 ;
}
static int F_410 ( struct V_896 * V_897 ,
struct V_917 * V_918 , unsigned V_919 , int V_920 )
{
T_2 V_269 ;
if ( V_920 )
V_269 = V_910 | V_913 ;
else
V_269 = V_910 ;
return F_392 ( & V_897 -> V_898 , V_269 ) ;
}
static int F_411 ( struct V_845 * V_921 , short V_109 )
{
T_2 V_286 = 0 ;
V_286 = 0 ;
if ( V_109 & V_922 )
V_286 |= V_923 ;
if ( V_109 & V_924 )
V_286 |= V_925 ;
if ( V_286 == 0 )
return 0 ;
return F_392 ( V_921 , V_286 ) ;
}
static void F_412 ( struct V_845 * V_921 , T_2 * V_549 )
{
struct V_846 * V_24 = V_921 -> V_19 ;
* V_549 = V_24 -> V_17 ;
}
static void F_413 ( struct V_34 * V_34 , struct V_22 * V_22 )
{
if ( V_22 )
F_30 ( V_22 , V_34 ) ;
}
static int F_414 ( struct V_20 * V_149 ,
char * V_71 , char * * V_505 )
{
const struct V_13 * V_806 ;
T_2 V_17 ;
int error ;
unsigned V_94 ;
if ( V_11 != V_149 ) {
error = F_116 ( V_149 , V_926 ) ;
if ( error )
return error ;
}
F_19 () ;
V_806 = F_20 ( V_149 ) -> V_19 ;
if ( ! strcmp ( V_71 , L_50 ) )
V_17 = V_806 -> V_17 ;
else if ( ! strcmp ( V_71 , L_51 ) )
V_17 = V_806 -> V_16 ;
else if ( ! strcmp ( V_71 , L_52 ) )
V_17 = V_806 -> V_424 ;
else if ( ! strcmp ( V_71 , L_53 ) )
V_17 = V_806 -> V_304 ;
else if ( ! strcmp ( V_71 , L_54 ) )
V_17 = V_806 -> V_422 ;
else if ( ! strcmp ( V_71 , L_55 ) )
V_17 = V_806 -> V_423 ;
else
goto V_927;
F_21 () ;
if ( ! V_17 )
return 0 ;
error = F_69 ( V_17 , V_505 , & V_94 ) ;
if ( error )
return error ;
return V_94 ;
V_927:
F_21 () ;
return - V_96 ;
}
static int F_415 ( struct V_20 * V_149 ,
char * V_71 , void * V_505 , T_7 V_536 )
{
struct V_13 * V_14 ;
struct V_20 * V_432 ;
struct V_10 * V_134 ;
T_2 V_17 = 0 , V_434 ;
int error ;
char * V_1 = V_505 ;
if ( V_11 != V_149 ) {
return - V_420 ;
}
if ( ! strcmp ( V_71 , L_52 ) )
error = F_116 ( V_149 , V_928 ) ;
else if ( ! strcmp ( V_71 , L_53 ) )
error = F_116 ( V_149 , V_929 ) ;
else if ( ! strcmp ( V_71 , L_54 ) )
error = F_116 ( V_149 , V_930 ) ;
else if ( ! strcmp ( V_71 , L_55 ) )
error = F_116 ( V_149 , V_931 ) ;
else if ( ! strcmp ( V_71 , L_50 ) )
error = F_116 ( V_149 , V_932 ) ;
else
error = - V_96 ;
if ( error )
return error ;
if ( V_536 && V_1 [ 1 ] && V_1 [ 1 ] != '\n' ) {
if ( V_1 [ V_536 - 1 ] == '\n' ) {
V_1 [ V_536 - 1 ] = 0 ;
V_536 -- ;
}
error = F_230 ( V_505 , V_536 , & V_17 , V_15 ) ;
if ( error == - V_96 && ! strcmp ( V_71 , L_53 ) ) {
if ( ! F_227 ( V_538 ) ) {
struct V_539 * V_540 ;
T_7 V_541 ;
if ( V_1 [ V_536 - 1 ] == '\0' )
V_541 = V_536 - 1 ;
else
V_541 = V_536 ;
V_540 = F_231 ( V_11 -> V_542 , V_102 , V_543 ) ;
F_232 ( V_540 , L_56 ) ;
F_233 ( V_540 , V_505 , V_541 ) ;
F_234 ( V_540 ) ;
return error ;
}
error = F_235 ( V_505 , V_536 ,
& V_17 ) ;
}
if ( error )
return error ;
}
V_134 = F_416 () ;
if ( ! V_134 )
return - V_27 ;
V_14 = V_134 -> V_19 ;
if ( ! strcmp ( V_71 , L_52 ) ) {
V_14 -> V_424 = V_17 ;
} else if ( ! strcmp ( V_71 , L_53 ) ) {
V_14 -> V_304 = V_17 ;
} else if ( ! strcmp ( V_71 , L_54 ) ) {
error = F_133 ( V_17 , V_149 ) ;
if ( error )
goto V_933;
V_14 -> V_422 = V_17 ;
} else if ( ! strcmp ( V_71 , L_55 ) ) {
V_14 -> V_423 = V_17 ;
} else if ( ! strcmp ( V_71 , L_50 ) ) {
error = - V_96 ;
if ( V_17 == 0 )
goto V_933;
error = - V_419 ;
if ( ! F_417 () ) {
error = F_157 ( V_14 -> V_17 , V_17 ) ;
if ( error )
goto V_933;
}
error = F_54 ( V_14 -> V_17 , V_17 , V_272 ,
V_934 , NULL ) ;
if ( error )
goto V_933;
V_434 = 0 ;
F_19 () ;
V_432 = F_159 ( V_149 ) ;
if ( V_432 )
V_434 = F_18 ( V_432 ) ;
F_21 () ;
if ( V_432 ) {
error = F_54 ( V_434 , V_17 , V_272 ,
V_368 , NULL ) ;
if ( error )
goto V_933;
}
V_14 -> V_17 = V_17 ;
} else {
error = - V_96 ;
goto V_933;
}
F_418 ( V_134 ) ;
return V_536 ;
V_933:
F_419 ( V_134 ) ;
return error ;
}
static int F_420 ( const char * V_71 )
{
return ( strcmp ( V_71 , V_507 ) == 0 ) ;
}
static int F_421 ( T_2 V_549 , char * * V_488 , T_2 * V_935 )
{
return F_69 ( V_549 , V_488 , V_935 ) ;
}
static int F_422 ( const char * V_488 , T_2 V_935 , T_2 * V_549 )
{
return F_230 ( V_488 , V_935 , V_549 , V_15 ) ;
}
static void F_423 ( char * V_488 , T_2 V_935 )
{
F_51 ( V_488 ) ;
}
static void F_424 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
F_75 ( & V_24 -> V_28 ) ;
V_24 -> V_37 = V_38 ;
F_78 ( & V_24 -> V_28 ) ;
}
static int F_425 ( struct V_22 * V_22 , void * V_311 , T_2 V_503 )
{
return F_243 ( V_22 , V_507 , V_311 , V_503 , 0 ) ;
}
static int F_426 ( struct V_34 * V_34 , void * V_311 , T_2 V_503 )
{
return F_427 ( V_34 , V_81 , V_311 , V_503 , 0 ) ;
}
static int F_428 ( struct V_22 * V_22 , void * * V_311 , T_2 * V_503 )
{
int V_94 = 0 ;
V_94 = F_241 ( V_22 , V_507 ,
V_311 , true ) ;
if ( V_94 < 0 )
return V_94 ;
* V_503 = V_94 ;
return 0 ;
}
static int F_429 ( struct V_853 * V_936 , const struct V_10 * V_10 ,
unsigned long V_85 )
{
const struct V_13 * V_14 ;
struct V_937 * V_938 ;
V_938 = F_15 ( sizeof( struct V_937 ) , V_15 ) ;
if ( ! V_938 )
return - V_27 ;
V_14 = V_10 -> V_19 ;
if ( V_14 -> V_422 )
V_938 -> V_17 = V_14 -> V_422 ;
else
V_938 -> V_17 = V_14 -> V_17 ;
V_936 -> V_19 = V_938 ;
return 0 ;
}
static void F_430 ( struct V_853 * V_936 )
{
struct V_937 * V_938 = V_936 -> V_19 ;
V_936 -> V_19 = NULL ;
F_51 ( V_938 ) ;
}
static int F_431 ( T_16 V_939 ,
const struct V_10 * V_10 ,
unsigned V_259 )
{
struct V_853 * V_853 ;
struct V_937 * V_938 ;
T_2 V_17 ;
if ( V_259 == 0 )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_853 = F_432 ( V_939 ) ;
V_938 = V_853 -> V_19 ;
return F_54 ( V_17 , V_938 -> V_17 , V_312 , V_259 , NULL ) ;
}
static int F_433 ( struct V_853 * V_853 , char * * V_940 )
{
struct V_937 * V_938 = V_853 -> V_19 ;
char * V_93 = NULL ;
unsigned V_94 ;
int V_60 ;
V_60 = F_69 ( V_938 -> V_17 , & V_93 , & V_94 ) ;
if ( ! V_60 )
V_60 = V_94 ;
* V_940 = V_93 ;
return V_60 ;
}
static T_1 int F_434 ( void )
{
if ( ! F_435 ( L_57 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_58 ( V_941 L_58 ) ;
return 0 ;
}
F_58 ( V_941 L_59 ) ;
F_14 () ;
V_576 = ! ( V_942 & V_591 ) ;
V_25 = F_436 ( L_60 ,
sizeof( struct V_23 ) ,
0 , V_943 , NULL ) ;
V_51 = F_436 ( L_61 ,
sizeof( struct V_49 ) ,
0 , V_943 , NULL ) ;
F_437 () ;
F_438 ( V_944 , F_59 ( V_944 ) ) ;
if ( F_439 ( F_9 , V_9 ) )
F_16 ( L_62 ) ;
if ( V_3 )
F_58 ( V_945 L_63 ) ;
else
F_58 ( V_945 L_64 ) ;
return 0 ;
}
static void F_440 ( struct V_54 * V_55 , void * V_946 )
{
F_85 ( V_55 , NULL ) ;
}
void F_441 ( void )
{
F_58 ( V_945 L_65 ) ;
F_58 ( V_945 L_66 ) ;
F_442 ( F_440 , NULL ) ;
}
static int T_1 F_443 ( void )
{
int V_605 ;
if ( ! V_5 )
return 0 ;
F_58 ( V_945 L_67 ) ;
V_605 = F_444 ( V_947 , F_59 ( V_947 ) ) ;
if ( V_605 )
F_16 ( L_68 , V_605 ) ;
return 0 ;
}
static void F_445 ( void )
{
F_58 ( V_945 L_69 ) ;
F_446 ( V_947 , F_59 ( V_947 ) ) ;
}
int F_447 ( void )
{
if ( V_97 ) {
return - V_96 ;
}
if ( V_948 ) {
return - V_96 ;
}
F_58 ( V_941 L_70 ) ;
V_948 = 1 ;
V_5 = 0 ;
F_448 ( V_944 , F_59 ( V_944 ) ) ;
F_449 () ;
F_445 () ;
F_450 () ;
return 0 ;
}
