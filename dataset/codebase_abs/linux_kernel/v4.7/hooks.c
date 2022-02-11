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
if ( V_37 && V_24 -> V_38 != V_39 ) {
if ( ! V_36 )
return - V_40 ;
F_30 ( V_22 , V_35 ) ;
}
return 0 ;
}
static struct V_23 * F_31 ( struct V_22 * V_22 )
{
return V_22 -> V_33 ;
}
static struct V_23 * F_32 ( struct V_22 * V_22 , bool V_41 )
{
int error ;
error = F_28 ( V_22 , NULL , ! V_41 ) ;
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
return V_22 -> V_33 ;
}
static struct V_23 * F_37 ( struct V_34 * V_34 )
{
struct V_22 * V_22 = F_36 ( V_34 ) ;
F_28 ( V_22 , V_34 , true ) ;
return V_22 -> V_33 ;
}
static void F_38 ( struct V_42 * V_43 )
{
struct V_23 * V_24 ;
V_24 = F_39 ( V_43 , struct V_23 , V_41 ) ;
F_40 ( V_25 , V_24 ) ;
}
static void F_41 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_44 * V_45 = V_22 -> V_46 -> V_47 ;
if ( ! F_42 ( & V_24 -> V_29 ) ) {
F_43 ( & V_45 -> V_48 ) ;
F_44 ( & V_24 -> V_29 ) ;
F_45 ( & V_45 -> V_48 ) ;
}
F_46 ( & V_24 -> V_41 , F_38 ) ;
}
static int F_47 ( struct V_49 * V_49 )
{
struct V_50 * V_51 ;
T_2 V_17 = F_22 () ;
V_51 = F_25 ( V_52 , V_15 ) ;
if ( ! V_51 )
return - V_27 ;
V_51 -> V_17 = V_17 ;
V_51 -> V_53 = V_17 ;
V_49 -> V_54 = V_51 ;
return 0 ;
}
static void F_48 ( struct V_49 * V_49 )
{
struct V_50 * V_51 = V_49 -> V_54 ;
V_49 -> V_54 = NULL ;
F_40 ( V_52 , V_51 ) ;
}
static int F_49 ( struct V_55 * V_56 )
{
struct V_44 * V_45 ;
V_45 = F_15 ( sizeof( struct V_44 ) , V_15 ) ;
if ( ! V_45 )
return - V_27 ;
F_26 ( & V_45 -> V_28 ) ;
F_27 ( & V_45 -> V_57 ) ;
F_50 ( & V_45 -> V_48 ) ;
V_45 -> V_56 = V_56 ;
V_45 -> V_17 = V_30 ;
V_45 -> V_58 = V_59 ;
V_45 -> V_60 = V_30 ;
V_56 -> V_47 = V_45 ;
return 0 ;
}
static void F_51 ( struct V_55 * V_56 )
{
struct V_44 * V_45 = V_56 -> V_47 ;
V_56 -> V_47 = NULL ;
F_52 ( V_45 ) ;
}
static inline int F_53 ( struct V_22 * V_22 )
{
return F_30 ( V_22 , NULL ) ;
}
static int F_54 ( T_2 V_17 ,
struct V_44 * V_45 ,
const struct V_10 * V_10 )
{
const struct V_13 * V_14 = V_10 -> V_19 ;
int V_61 ;
V_61 = F_55 ( V_14 -> V_17 , V_45 -> V_17 , V_62 ,
V_63 , NULL ) ;
if ( V_61 )
return V_61 ;
V_61 = F_55 ( V_14 -> V_17 , V_17 , V_62 ,
V_64 , NULL ) ;
return V_61 ;
}
static int F_56 ( T_2 V_17 ,
struct V_44 * V_45 ,
const struct V_10 * V_10 )
{
const struct V_13 * V_14 = V_10 -> V_19 ;
int V_61 ;
V_61 = F_55 ( V_14 -> V_17 , V_45 -> V_17 , V_62 ,
V_63 , NULL ) ;
if ( V_61 )
return V_61 ;
V_61 = F_55 ( V_17 , V_45 -> V_17 , V_62 ,
V_65 , NULL ) ;
return V_61 ;
}
static int F_57 ( struct V_55 * V_56 )
{
struct V_44 * V_45 = V_56 -> V_47 ;
return V_45 -> V_66 == V_67 ||
V_45 -> V_66 == V_68 ||
V_45 -> V_66 == V_69 ||
V_45 -> V_66 == V_70 ||
! strcmp ( V_56 -> V_71 -> V_72 , L_2 ) ||
! strcmp ( V_56 -> V_71 -> V_72 , L_3 ) ||
! strcmp ( V_56 -> V_71 -> V_72 , L_4 ) ||
! strcmp ( V_56 -> V_71 -> V_72 , L_5 ) ;
}
static int F_58 ( struct V_55 * V_56 )
{
struct V_44 * V_45 = V_56 -> V_47 ;
struct V_34 * V_73 = V_56 -> V_74 ;
struct V_22 * V_75 = F_36 ( V_73 ) ;
int V_61 = 0 ;
if ( V_45 -> V_66 == V_67 ) {
if ( ! V_75 -> V_76 -> V_77 ) {
F_59 ( V_78 L_6
L_7 , V_56 -> V_79 , V_56 -> V_71 -> V_72 ) ;
V_61 = - V_80 ;
goto V_81;
}
V_61 = V_75 -> V_76 -> V_77 ( V_73 , V_75 ,
V_82 , NULL , 0 ) ;
if ( V_61 < 0 && V_61 != - V_83 ) {
if ( V_61 == - V_80 )
F_59 ( V_78 L_8
L_9 ,
V_56 -> V_79 , V_56 -> V_71 -> V_72 ) ;
else
F_59 ( V_78 L_8
L_10 , V_56 -> V_79 ,
V_56 -> V_71 -> V_72 , - V_61 ) ;
goto V_81;
}
}
if ( V_45 -> V_66 > F_60 ( V_84 ) )
F_59 ( V_85 L_11 ,
V_56 -> V_79 , V_56 -> V_71 -> V_72 ) ;
V_45 -> V_86 |= V_87 ;
if ( F_57 ( V_56 ) )
V_45 -> V_86 |= V_88 ;
V_61 = F_30 ( V_75 , V_73 ) ;
F_43 ( & V_45 -> V_48 ) ;
V_89:
if ( ! F_61 ( & V_45 -> V_57 ) ) {
struct V_23 * V_24 =
F_62 ( V_45 -> V_57 . V_90 ,
struct V_23 , V_29 ) ;
struct V_22 * V_22 = V_24 -> V_22 ;
F_44 ( & V_24 -> V_29 ) ;
F_45 ( & V_45 -> V_48 ) ;
V_22 = F_63 ( V_22 ) ;
if ( V_22 ) {
if ( ! F_64 ( V_22 ) )
F_53 ( V_22 ) ;
F_65 ( V_22 ) ;
}
F_43 ( & V_45 -> V_48 ) ;
goto V_89;
}
F_45 ( & V_45 -> V_48 ) ;
V_81:
return V_61 ;
}
static int F_66 ( const struct V_55 * V_56 ,
struct V_91 * V_92 )
{
int V_61 = 0 , V_93 ;
struct V_44 * V_45 = V_56 -> V_47 ;
char * V_94 = NULL ;
T_2 V_95 ;
char V_96 ;
F_67 ( V_92 ) ;
if ( ! ( V_45 -> V_86 & V_87 ) )
return - V_97 ;
if ( ! V_37 )
return - V_97 ;
F_68 ( V_98 >= ( 1 << V_99 ) ) ;
V_96 = V_45 -> V_86 & V_98 ;
for ( V_93 = 0 ; V_93 < V_99 ; V_93 ++ ) {
if ( V_96 & 0x01 )
V_92 -> V_100 ++ ;
V_96 >>= 1 ;
}
if ( V_45 -> V_86 & V_88 )
V_92 -> V_100 ++ ;
V_92 -> V_101 = F_69 ( V_92 -> V_100 , sizeof( char * ) , V_102 ) ;
if ( ! V_92 -> V_101 ) {
V_61 = - V_27 ;
goto V_103;
}
V_92 -> V_104 = F_69 ( V_92 -> V_100 , sizeof( int ) , V_102 ) ;
if ( ! V_92 -> V_104 ) {
V_61 = - V_27 ;
goto V_103;
}
V_93 = 0 ;
if ( V_45 -> V_86 & V_105 ) {
V_61 = F_70 ( V_45 -> V_17 , & V_94 , & V_95 ) ;
if ( V_61 )
goto V_103;
V_92 -> V_101 [ V_93 ] = V_94 ;
V_92 -> V_104 [ V_93 ++ ] = V_105 ;
}
if ( V_45 -> V_86 & V_106 ) {
V_61 = F_70 ( V_45 -> V_60 , & V_94 , & V_95 ) ;
if ( V_61 )
goto V_103;
V_92 -> V_101 [ V_93 ] = V_94 ;
V_92 -> V_104 [ V_93 ++ ] = V_106 ;
}
if ( V_45 -> V_86 & V_107 ) {
V_61 = F_70 ( V_45 -> V_58 , & V_94 , & V_95 ) ;
if ( V_61 )
goto V_103;
V_92 -> V_101 [ V_93 ] = V_94 ;
V_92 -> V_104 [ V_93 ++ ] = V_107 ;
}
if ( V_45 -> V_86 & V_108 ) {
struct V_34 * V_73 = V_45 -> V_56 -> V_74 ;
struct V_23 * V_24 = F_37 ( V_73 ) ;
V_61 = F_70 ( V_24 -> V_17 , & V_94 , & V_95 ) ;
if ( V_61 )
goto V_103;
V_92 -> V_101 [ V_93 ] = V_94 ;
V_92 -> V_104 [ V_93 ++ ] = V_108 ;
}
if ( V_45 -> V_86 & V_88 ) {
V_92 -> V_101 [ V_93 ] = NULL ;
V_92 -> V_104 [ V_93 ++ ] = V_88 ;
}
F_71 ( V_93 != V_92 -> V_100 ) ;
return 0 ;
V_103:
F_72 ( V_92 ) ;
return V_61 ;
}
static int F_73 ( struct V_44 * V_45 , char V_109 ,
T_2 V_110 , T_2 V_111 )
{
char V_112 = V_45 -> V_86 & V_98 ;
if ( V_45 -> V_86 & V_87 )
if ( ! ( V_45 -> V_86 & V_109 ) ||
( V_110 != V_111 ) )
return 1 ;
if ( ! ( V_45 -> V_86 & V_87 ) )
if ( V_112 & V_109 )
return 1 ;
return 0 ;
}
static int F_74 ( struct V_55 * V_56 ,
struct V_91 * V_92 ,
unsigned long V_113 ,
unsigned long * V_114 )
{
const struct V_10 * V_10 = F_75 () ;
int V_61 = 0 , V_93 ;
struct V_44 * V_45 = V_56 -> V_47 ;
const char * V_72 = V_56 -> V_71 -> V_72 ;
struct V_34 * V_73 = V_45 -> V_56 -> V_74 ;
struct V_23 * V_115 ;
T_2 V_116 = 0 , V_117 = 0 , V_118 = 0 ;
T_2 V_119 = 0 ;
char * * V_120 = V_92 -> V_101 ;
int * V_86 = V_92 -> V_104 ;
int V_121 = V_92 -> V_100 ;
F_76 ( & V_45 -> V_28 ) ;
if ( ! V_37 ) {
if ( ! V_121 ) {
goto V_81;
}
V_61 = - V_97 ;
F_59 ( V_78 L_12
L_13 ) ;
goto V_81;
}
if ( V_113 && ! V_114 ) {
V_61 = - V_97 ;
goto V_81;
}
if ( ( V_45 -> V_86 & V_87 ) && ( V_56 -> V_71 -> V_122 & V_123 )
&& ( V_121 == 0 ) )
goto V_81;
V_115 = F_35 ( V_73 ) ;
for ( V_93 = 0 ; V_93 < V_121 ; V_93 ++ ) {
T_2 V_17 ;
if ( V_86 [ V_93 ] == V_88 )
continue;
V_61 = F_77 ( V_120 [ V_93 ] , & V_17 , V_15 ) ;
if ( V_61 ) {
F_59 ( V_78 L_14
L_15 ,
V_120 [ V_93 ] , V_56 -> V_79 , V_72 , V_61 ) ;
goto V_81;
}
switch ( V_86 [ V_93 ] ) {
case V_105 :
V_116 = V_17 ;
if ( F_73 ( V_45 , V_105 , V_45 -> V_17 ,
V_116 ) )
goto V_124;
V_45 -> V_86 |= V_105 ;
break;
case V_106 :
V_117 = V_17 ;
if ( F_73 ( V_45 , V_106 , V_45 -> V_60 ,
V_117 ) )
goto V_124;
V_45 -> V_86 |= V_106 ;
break;
case V_108 :
V_118 = V_17 ;
if ( F_73 ( V_45 , V_108 , V_115 -> V_17 ,
V_118 ) )
goto V_124;
V_45 -> V_86 |= V_108 ;
break;
case V_107 :
V_119 = V_17 ;
if ( F_73 ( V_45 , V_107 , V_45 -> V_58 ,
V_119 ) )
goto V_124;
V_45 -> V_86 |= V_107 ;
break;
default:
V_61 = - V_97 ;
goto V_81;
}
}
if ( V_45 -> V_86 & V_87 ) {
if ( ( V_45 -> V_86 & V_98 ) && ! V_121 )
goto V_124;
V_61 = 0 ;
goto V_81;
}
if ( strcmp ( V_56 -> V_71 -> V_72 , L_16 ) == 0 )
V_45 -> V_86 |= V_125 | V_126 ;
if ( ! strcmp ( V_56 -> V_71 -> V_72 , L_4 ) ||
! strcmp ( V_56 -> V_71 -> V_72 , L_2 ) ||
! strcmp ( V_56 -> V_71 -> V_72 , L_3 ) )
V_45 -> V_86 |= V_126 ;
if ( ! V_45 -> V_66 ) {
V_61 = F_78 ( V_56 ) ;
if ( V_61 ) {
F_59 ( V_78
L_17 ,
V_127 , V_56 -> V_71 -> V_72 , V_61 ) ;
goto V_81;
}
}
if ( V_116 ) {
V_61 = F_54 ( V_116 , V_45 , V_10 ) ;
if ( V_61 )
goto V_81;
V_45 -> V_17 = V_116 ;
}
if ( V_113 & V_128 && ! V_117 ) {
V_45 -> V_66 = V_70 ;
* V_114 |= V_128 ;
}
if ( V_117 ) {
if ( ! V_116 ) {
V_61 = F_54 ( V_117 , V_45 ,
V_10 ) ;
if ( V_61 )
goto V_81;
V_45 -> V_17 = V_117 ;
} else {
V_61 = F_56 ( V_117 , V_45 ,
V_10 ) ;
if ( V_61 )
goto V_81;
}
if ( ! V_118 )
V_118 = V_117 ;
V_45 -> V_60 = V_117 ;
V_45 -> V_66 = V_129 ;
}
if ( V_118 ) {
V_61 = F_56 ( V_118 , V_45 ,
V_10 ) ;
if ( V_61 )
goto V_81;
V_115 -> V_17 = V_118 ;
V_115 -> V_38 = V_39 ;
}
if ( V_119 ) {
if ( V_45 -> V_66 != V_67 &&
V_45 -> V_66 != V_70 ) {
V_61 = - V_97 ;
F_59 ( V_78 L_18
L_19 ) ;
goto V_81;
}
if ( V_119 != V_45 -> V_58 ) {
V_61 = F_56 ( V_119 ,
V_45 , V_10 ) ;
if ( V_61 )
goto V_81;
}
V_45 -> V_58 = V_119 ;
}
V_61 = F_58 ( V_56 ) ;
V_81:
F_79 ( & V_45 -> V_28 ) ;
return V_61 ;
V_124:
V_61 = - V_97 ;
F_59 ( V_78 L_20
L_21 , V_56 -> V_79 , V_72 ) ;
goto V_81;
}
static int F_80 ( const struct V_55 * V_130 ,
const struct V_55 * V_131 )
{
struct V_44 * V_132 = V_130 -> V_47 ;
struct V_44 * V_133 = V_131 -> V_47 ;
char V_134 = V_132 -> V_86 & V_98 ;
char V_135 = V_133 -> V_86 & V_98 ;
if ( V_134 != V_135 )
goto V_136;
if ( ( V_134 & V_105 ) && V_132 -> V_17 != V_133 -> V_17 )
goto V_136;
if ( ( V_134 & V_106 ) && V_132 -> V_60 != V_133 -> V_60 )
goto V_136;
if ( ( V_134 & V_107 ) && V_132 -> V_58 != V_133 -> V_58 )
goto V_136;
if ( V_134 & V_108 ) {
struct V_23 * V_137 = F_37 ( V_130 -> V_74 ) ;
struct V_23 * V_138 = F_37 ( V_131 -> V_74 ) ;
if ( V_137 -> V_17 != V_138 -> V_17 )
goto V_136;
}
return 0 ;
V_136:
F_59 ( V_78 L_22
L_23
L_24 , V_131 -> V_79 , V_131 -> V_71 -> V_72 ) ;
return - V_139 ;
}
static int F_81 ( const struct V_55 * V_130 ,
struct V_55 * V_131 )
{
const struct V_44 * V_140 = V_130 -> V_47 ;
struct V_44 * V_141 = V_131 -> V_47 ;
int V_142 = ( V_140 -> V_86 & V_105 ) ;
int V_143 = ( V_140 -> V_86 & V_106 ) ;
int V_144 = ( V_140 -> V_86 & V_108 ) ;
if ( ! V_37 )
return 0 ;
F_71 ( ! ( V_140 -> V_86 & V_87 ) ) ;
if ( V_141 -> V_86 & V_87 )
return F_80 ( V_130 , V_131 ) ;
F_76 ( & V_141 -> V_28 ) ;
V_141 -> V_86 = V_140 -> V_86 ;
V_141 -> V_17 = V_140 -> V_17 ;
V_141 -> V_58 = V_140 -> V_58 ;
V_141 -> V_66 = V_140 -> V_66 ;
if ( V_143 ) {
T_2 V_17 = V_140 -> V_60 ;
if ( ! V_142 )
V_141 -> V_17 = V_17 ;
if ( ! V_144 ) {
struct V_23 * V_145 = F_37 ( V_131 -> V_74 ) ;
V_145 -> V_17 = V_17 ;
}
V_141 -> V_60 = V_17 ;
}
if ( V_144 ) {
const struct V_23 * V_146 = F_37 ( V_130 -> V_74 ) ;
struct V_23 * V_145 = F_37 ( V_131 -> V_74 ) ;
V_145 -> V_17 = V_146 -> V_17 ;
}
F_58 ( V_131 ) ;
F_79 ( & V_141 -> V_28 ) ;
return 0 ;
}
static int F_82 ( char * V_147 ,
struct V_91 * V_92 )
{
char * V_148 ;
char * V_94 = NULL , * V_149 = NULL ;
char * V_150 = NULL , * V_151 = NULL ;
int V_61 , V_100 = 0 ;
V_92 -> V_100 = 0 ;
while ( ( V_148 = F_83 ( & V_147 , L_25 ) ) != NULL ) {
int V_152 ;
T_3 args [ V_153 ] ;
if ( ! * V_148 )
continue;
V_152 = F_84 ( V_148 , V_154 , args ) ;
switch ( V_152 ) {
case V_155 :
if ( V_94 || V_149 ) {
V_61 = - V_97 ;
F_59 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_156;
}
V_94 = F_85 ( & args [ 0 ] ) ;
if ( ! V_94 ) {
V_61 = - V_27 ;
goto V_156;
}
break;
case V_157 :
if ( V_150 ) {
V_61 = - V_97 ;
F_59 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_156;
}
V_150 = F_85 ( & args [ 0 ] ) ;
if ( ! V_150 ) {
V_61 = - V_27 ;
goto V_156;
}
break;
case V_158 :
if ( V_151 ) {
V_61 = - V_97 ;
F_59 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_156;
}
V_151 = F_85 ( & args [ 0 ] ) ;
if ( ! V_151 ) {
V_61 = - V_27 ;
goto V_156;
}
break;
case V_159 :
if ( V_94 || V_149 ) {
V_61 = - V_97 ;
F_59 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_156;
}
V_149 = F_85 ( & args [ 0 ] ) ;
if ( ! V_149 ) {
V_61 = - V_27 ;
goto V_156;
}
break;
case V_160 :
break;
default:
V_61 = - V_97 ;
F_59 ( V_78 L_26 ) ;
goto V_156;
}
}
V_61 = - V_27 ;
V_92 -> V_101 = F_69 ( V_99 , sizeof( char * ) , V_102 ) ;
if ( ! V_92 -> V_101 )
goto V_156;
V_92 -> V_104 = F_69 ( V_99 , sizeof( int ) , V_102 ) ;
if ( ! V_92 -> V_104 ) {
F_52 ( V_92 -> V_101 ) ;
goto V_156;
}
if ( V_150 ) {
V_92 -> V_101 [ V_100 ] = V_150 ;
V_92 -> V_104 [ V_100 ++ ] = V_105 ;
}
if ( V_94 ) {
V_92 -> V_101 [ V_100 ] = V_94 ;
V_92 -> V_104 [ V_100 ++ ] = V_106 ;
}
if ( V_151 ) {
V_92 -> V_101 [ V_100 ] = V_151 ;
V_92 -> V_104 [ V_100 ++ ] = V_108 ;
}
if ( V_149 ) {
V_92 -> V_101 [ V_100 ] = V_149 ;
V_92 -> V_104 [ V_100 ++ ] = V_107 ;
}
V_92 -> V_100 = V_100 ;
return 0 ;
V_156:
F_52 ( V_94 ) ;
F_52 ( V_149 ) ;
F_52 ( V_150 ) ;
F_52 ( V_151 ) ;
return V_61 ;
}
static int F_86 ( struct V_55 * V_56 , void * V_161 )
{
int V_61 = 0 ;
char * V_147 = V_161 ;
struct V_91 V_92 ;
F_67 ( & V_92 ) ;
if ( ! V_161 )
goto V_81;
F_71 ( V_56 -> V_71 -> V_122 & V_123 ) ;
V_61 = F_82 ( V_147 , & V_92 ) ;
if ( V_61 )
goto V_156;
V_81:
V_61 = F_74 ( V_56 , & V_92 , 0 , NULL ) ;
V_156:
F_72 ( & V_92 ) ;
return V_61 ;
}
static void F_87 ( struct V_162 * V_163 ,
struct V_91 * V_92 )
{
int V_93 ;
char * V_164 ;
for ( V_93 = 0 ; V_93 < V_92 -> V_100 ; V_93 ++ ) {
char * V_165 ;
if ( V_92 -> V_101 [ V_93 ] )
V_165 = strchr ( V_92 -> V_101 [ V_93 ] , ',' ) ;
else
V_165 = NULL ;
switch ( V_92 -> V_104 [ V_93 ] ) {
case V_106 :
V_164 = V_166 ;
break;
case V_105 :
V_164 = V_167 ;
break;
case V_108 :
V_164 = V_168 ;
break;
case V_107 :
V_164 = V_169 ;
break;
case V_88 :
F_88 ( V_163 , ',' ) ;
F_89 ( V_163 , V_170 ) ;
continue;
default:
F_90 () ;
return;
} ;
F_88 ( V_163 , ',' ) ;
F_89 ( V_163 , V_164 ) ;
if ( V_165 )
F_88 ( V_163 , '\"' ) ;
F_91 ( V_163 , V_92 -> V_101 [ V_93 ] , L_27 ) ;
if ( V_165 )
F_88 ( V_163 , '\"' ) ;
}
}
static int F_92 ( struct V_162 * V_163 , struct V_55 * V_56 )
{
struct V_91 V_92 ;
int V_61 ;
V_61 = F_66 ( V_56 , & V_92 ) ;
if ( V_61 ) {
if ( V_61 == - V_97 )
V_61 = 0 ;
return V_61 ;
}
F_87 ( V_163 , & V_92 ) ;
F_72 ( & V_92 ) ;
return V_61 ;
}
static inline T_4 F_93 ( T_5 V_171 )
{
switch ( V_171 & V_172 ) {
case V_173 :
return V_174 ;
case V_175 :
return V_176 ;
case V_177 :
return V_32 ;
case V_178 :
return V_179 ;
case V_180 :
return V_181 ;
case V_182 :
return V_183 ;
case V_184 :
return V_185 ;
}
return V_32 ;
}
static inline int F_94 ( int V_186 )
{
return ( V_186 == V_187 || V_186 == V_188 ) ;
}
static inline int F_95 ( int V_186 )
{
return ( V_186 == V_187 || V_186 == V_189 ) ;
}
static inline T_4 F_96 ( int V_190 , int type , int V_186 )
{
switch ( V_190 ) {
case V_191 :
switch ( type ) {
case V_192 :
case V_193 :
return V_194 ;
case V_195 :
return V_196 ;
}
break;
case V_197 :
case V_198 :
switch ( type ) {
case V_192 :
if ( F_94 ( V_186 ) )
return V_199 ;
else
return V_200 ;
case V_195 :
if ( F_95 ( V_186 ) )
return V_201 ;
else
return V_200 ;
case V_202 :
return V_203 ;
default:
return V_200 ;
}
break;
case V_204 :
switch ( V_186 ) {
case V_205 :
return V_206 ;
case V_207 :
return V_208 ;
case V_209 :
return V_210 ;
case V_211 :
return V_212 ;
case V_213 :
return V_214 ;
case V_215 :
return V_216 ;
case V_217 :
return V_218 ;
case V_219 :
return V_220 ;
case V_221 :
return V_222 ;
case V_223 :
return V_224 ;
case V_225 :
return V_226 ;
case V_227 :
return V_228 ;
case V_229 :
return V_230 ;
case V_231 :
return V_232 ;
case V_233 :
return V_234 ;
case V_235 :
return V_236 ;
default:
return V_237 ;
}
case V_238 :
return V_239 ;
case V_240 :
return V_241 ;
case V_242 :
return V_243 ;
}
return V_244 ;
}
static int F_97 ( struct V_34 * V_34 ,
T_4 V_245 ,
T_4 V_86 ,
T_2 * V_17 )
{
int V_61 ;
struct V_55 * V_56 = V_34 -> V_246 ;
char * V_247 , * V_248 ;
V_247 = ( char * ) F_98 ( V_15 ) ;
if ( ! V_247 )
return - V_27 ;
V_248 = F_99 ( V_34 , V_247 , V_249 ) ;
if ( F_100 ( V_248 ) )
V_61 = F_101 ( V_248 ) ;
else {
if ( V_86 & V_125 ) {
while ( V_248 [ 1 ] >= '0' && V_248 [ 1 ] <= '9' ) {
V_248 [ 1 ] = '/' ;
V_248 ++ ;
}
}
V_61 = F_102 ( V_56 -> V_71 -> V_72 , V_248 , V_245 , V_17 ) ;
}
F_103 ( ( unsigned long ) V_247 ) ;
return V_61 ;
}
static int F_30 ( struct V_22 * V_22 , struct V_34 * V_35 )
{
struct V_44 * V_45 = NULL ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 ;
struct V_34 * V_34 ;
#define F_104 255
char * V_94 = NULL ;
unsigned V_95 = 0 ;
int V_61 = 0 ;
if ( V_24 -> V_38 == V_39 )
goto V_81;
F_76 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_38 == V_39 )
goto V_250;
V_45 = V_22 -> V_46 -> V_47 ;
if ( ! ( V_45 -> V_86 & V_87 ) ) {
F_43 ( & V_45 -> V_48 ) ;
if ( F_61 ( & V_24 -> V_29 ) )
F_105 ( & V_24 -> V_29 , & V_45 -> V_57 ) ;
F_45 ( & V_45 -> V_48 ) ;
goto V_250;
}
switch ( V_45 -> V_66 ) {
case V_70 :
break;
case V_67 :
if ( ! V_22 -> V_76 -> V_77 ) {
V_24 -> V_17 = V_45 -> V_58 ;
break;
}
if ( V_35 ) {
V_34 = F_106 ( V_35 ) ;
} else {
V_34 = F_107 ( V_22 ) ;
}
if ( ! V_34 ) {
goto V_250;
}
V_95 = F_104 ;
V_94 = F_108 ( V_95 + 1 , V_26 ) ;
if ( ! V_94 ) {
V_61 = - V_27 ;
F_109 ( V_34 ) ;
goto V_250;
}
V_94 [ V_95 ] = '\0' ;
V_61 = V_22 -> V_76 -> V_77 ( V_34 , V_22 , V_82 ,
V_94 , V_95 ) ;
if ( V_61 == - V_251 ) {
F_52 ( V_94 ) ;
V_61 = V_22 -> V_76 -> V_77 ( V_34 , V_22 , V_82 ,
NULL , 0 ) ;
if ( V_61 < 0 ) {
F_109 ( V_34 ) ;
goto V_250;
}
V_95 = V_61 ;
V_94 = F_108 ( V_95 + 1 , V_26 ) ;
if ( ! V_94 ) {
V_61 = - V_27 ;
F_109 ( V_34 ) ;
goto V_250;
}
V_94 [ V_95 ] = '\0' ;
V_61 = V_22 -> V_76 -> V_77 ( V_34 , V_22 ,
V_82 ,
V_94 , V_95 ) ;
}
F_109 ( V_34 ) ;
if ( V_61 < 0 ) {
if ( V_61 != - V_83 ) {
F_59 ( V_78 L_28
L_29 , V_127 ,
- V_61 , V_22 -> V_46 -> V_79 , V_22 -> V_252 ) ;
F_52 ( V_94 ) ;
goto V_250;
}
V_17 = V_45 -> V_58 ;
V_61 = 0 ;
} else {
V_61 = F_110 ( V_94 , V_61 , & V_17 ,
V_45 -> V_58 ,
V_26 ) ;
if ( V_61 ) {
char * V_253 = V_22 -> V_46 -> V_79 ;
unsigned long V_254 = V_22 -> V_252 ;
if ( V_61 == - V_97 ) {
if ( F_111 () )
F_59 ( V_255 L_30
L_31
L_32 , V_254 , V_253 , V_94 ) ;
} else {
F_59 ( V_78 L_33
L_34 ,
V_127 , V_94 , - V_61 , V_253 , V_254 ) ;
}
F_52 ( V_94 ) ;
V_61 = 0 ;
break;
}
}
F_52 ( V_94 ) ;
V_24 -> V_17 = V_17 ;
break;
case V_69 :
V_24 -> V_17 = V_24 -> F_18 ;
break;
case V_68 :
V_24 -> V_17 = V_45 -> V_17 ;
V_24 -> V_31 = F_93 ( V_22 -> V_256 ) ;
V_61 = F_112 ( V_24 -> F_18 , V_45 -> V_17 ,
V_24 -> V_31 , NULL , & V_17 ) ;
if ( V_61 )
goto V_250;
V_24 -> V_17 = V_17 ;
break;
case V_129 :
V_24 -> V_17 = V_45 -> V_60 ;
break;
default:
V_24 -> V_17 = V_45 -> V_17 ;
if ( ( V_45 -> V_86 & V_126 ) && ! F_113 ( V_22 -> V_256 ) ) {
if ( V_35 )
V_34 = F_106 ( V_35 ) ;
else
V_34 = F_107 ( V_22 ) ;
if ( ! V_34 )
goto V_250;
V_24 -> V_31 = F_93 ( V_22 -> V_256 ) ;
V_61 = F_97 ( V_34 , V_24 -> V_31 ,
V_45 -> V_86 , & V_17 ) ;
F_109 ( V_34 ) ;
if ( V_61 )
goto V_250;
V_24 -> V_17 = V_17 ;
}
break;
}
V_24 -> V_38 = V_39 ;
V_250:
F_79 ( & V_24 -> V_28 ) ;
V_81:
if ( V_24 -> V_31 == V_32 )
V_24 -> V_31 = F_93 ( V_22 -> V_256 ) ;
return V_61 ;
}
static inline T_2 F_114 ( int V_257 )
{
T_2 V_258 = 0 ;
switch ( V_257 ) {
case V_259 :
V_258 = V_260 ;
break;
case V_261 :
V_258 = V_262 ;
break;
case V_263 :
V_258 = V_264 ;
break;
default:
V_258 = V_265 ;
break;
}
return V_258 ;
}
static int F_115 ( const struct V_10 * V_266 ,
const struct V_10 * V_267 ,
T_2 V_268 )
{
T_2 V_269 = F_17 ( V_266 ) , V_270 = F_17 ( V_267 ) ;
return F_55 ( V_269 , V_270 , V_271 , V_268 , NULL ) ;
}
static int F_116 ( const struct V_20 * V_272 ,
const struct V_20 * V_273 ,
T_2 V_268 )
{
const struct V_13 * V_274 , * V_275 ;
T_2 V_276 , V_277 ;
F_19 () ;
V_274 = F_20 ( V_272 ) -> V_19 ; V_276 = V_274 -> V_17 ;
V_275 = F_20 ( V_273 ) -> V_19 ; V_277 = V_275 -> V_17 ;
F_21 () ;
return F_55 ( V_276 , V_277 , V_271 , V_268 , NULL ) ;
}
static int F_117 ( const struct V_20 * V_278 ,
T_2 V_268 )
{
T_2 V_17 , V_270 ;
V_17 = F_22 () ;
V_270 = F_18 ( V_278 ) ;
return F_55 ( V_17 , V_270 , V_271 , V_268 , NULL ) ;
}
static int F_118 ( const struct V_10 * V_10 ,
int V_279 , int V_280 , bool V_281 )
{
struct V_282 V_283 ;
struct V_284 V_285 ;
T_4 V_31 ;
T_2 V_17 = F_17 ( V_10 ) ;
T_2 V_286 = F_119 ( V_279 ) ;
int V_61 ;
V_283 . type = V_287 ;
V_283 . V_288 . V_279 = V_279 ;
switch ( F_120 ( V_279 ) ) {
case 0 :
V_31 = V_281 ? V_289 : V_290 ;
break;
case 1 :
V_31 = V_281 ? V_291 : V_292 ;
break;
default:
F_59 ( V_85
L_35 , V_279 ) ;
F_90 () ;
return - V_97 ;
}
V_61 = F_121 ( V_17 , V_17 , V_31 , V_286 , 0 , & V_285 ) ;
if ( V_280 == V_293 ) {
int V_294 = F_122 ( V_17 , V_17 , V_31 , V_286 , & V_285 , V_61 , & V_283 , 0 ) ;
if ( V_294 )
return V_294 ;
}
return V_61 ;
}
static int F_123 ( struct V_20 * V_278 ,
T_2 V_268 )
{
T_2 V_17 = F_18 ( V_278 ) ;
return F_55 ( V_17 , V_18 ,
V_295 , V_268 , NULL ) ;
}
static int F_124 ( const struct V_10 * V_10 ,
struct V_22 * V_22 ,
T_2 V_268 ,
struct V_282 * V_296 )
{
struct V_23 * V_24 ;
T_2 V_17 ;
F_125 ( V_10 ) ;
if ( F_126 ( F_64 ( V_22 ) ) )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
return F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_268 , V_296 ) ;
}
static inline int F_127 ( const struct V_10 * V_10 ,
struct V_34 * V_34 ,
T_2 V_286 )
{
struct V_22 * V_22 = F_36 ( V_34 ) ;
struct V_282 V_283 ;
V_283 . type = V_297 ;
V_283 . V_288 . V_34 = V_34 ;
F_28 ( V_22 , V_34 , true ) ;
return F_124 ( V_10 , V_22 , V_286 , & V_283 ) ;
}
static inline int F_128 ( const struct V_10 * V_10 ,
const struct V_248 * V_248 ,
T_2 V_286 )
{
struct V_22 * V_22 = F_36 ( V_248 -> V_34 ) ;
struct V_282 V_283 ;
V_283 . type = V_298 ;
V_283 . V_288 . V_248 = * V_248 ;
F_28 ( V_22 , V_248 -> V_34 , true ) ;
return F_124 ( V_10 , V_22 , V_286 , & V_283 ) ;
}
static inline int F_129 ( const struct V_10 * V_10 ,
struct V_49 * V_49 ,
T_2 V_286 )
{
struct V_282 V_283 ;
V_283 . type = V_298 ;
V_283 . V_288 . V_248 = V_49 -> V_299 ;
return F_124 ( V_10 , F_130 ( V_49 ) , V_286 , & V_283 ) ;
}
static int F_131 ( const struct V_10 * V_10 ,
struct V_49 * V_49 ,
T_2 V_286 )
{
struct V_50 * V_51 = V_49 -> V_54 ;
struct V_22 * V_22 = F_130 ( V_49 ) ;
struct V_282 V_283 ;
T_2 V_17 = F_17 ( V_10 ) ;
int V_61 ;
V_283 . type = V_298 ;
V_283 . V_288 . V_248 = V_49 -> V_299 ;
if ( V_17 != V_51 -> V_17 ) {
V_61 = F_55 ( V_17 , V_51 -> V_17 ,
V_300 ,
V_301 ,
& V_283 ) ;
if ( V_61 )
goto V_81;
}
V_61 = 0 ;
if ( V_286 )
V_61 = F_124 ( V_10 , V_22 , V_286 , & V_283 ) ;
V_81:
return V_61 ;
}
static int F_132 ( struct V_22 * V_302 ,
const struct V_303 * V_72 ,
T_4 V_245 ,
T_2 * V_304 )
{
const struct V_44 * V_45 = V_302 -> V_46 -> V_47 ;
const struct V_13 * V_14 = F_23 () ;
if ( ( V_45 -> V_86 & V_87 ) &&
( V_45 -> V_66 == V_129 ) ) {
* V_304 = V_45 -> V_60 ;
} else if ( ( V_45 -> V_86 & V_88 ) &&
V_14 -> V_305 ) {
* V_304 = V_14 -> V_305 ;
} else {
const struct V_23 * V_306 = F_34 ( V_302 ) ;
return F_112 ( V_14 -> V_17 , V_306 -> V_17 , V_245 ,
V_72 , V_304 ) ;
}
return 0 ;
}
static int F_133 ( struct V_22 * V_302 ,
struct V_34 * V_34 ,
T_4 V_245 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_306 ;
struct V_44 * V_45 ;
T_2 V_17 , V_307 ;
struct V_282 V_283 ;
int V_61 ;
V_306 = F_34 ( V_302 ) ;
V_45 = V_302 -> V_46 -> V_47 ;
V_17 = V_14 -> V_17 ;
V_283 . type = V_297 ;
V_283 . V_288 . V_34 = V_34 ;
V_61 = F_55 ( V_17 , V_306 -> V_17 , V_181 ,
V_308 | V_309 ,
& V_283 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_132 ( V_302 , & V_34 -> V_310 , V_245 ,
& V_307 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_55 ( V_17 , V_307 , V_245 , V_311 , & V_283 ) ;
if ( V_61 )
return V_61 ;
return F_55 ( V_307 , V_45 -> V_17 ,
V_62 ,
V_65 , & V_283 ) ;
}
static int F_134 ( T_2 V_312 ,
struct V_20 * V_313 )
{
T_2 V_17 = F_18 ( V_313 ) ;
return F_55 ( V_17 , V_312 , V_314 , V_315 , NULL ) ;
}
static int F_135 ( struct V_22 * V_302 ,
struct V_34 * V_34 ,
int V_316 )
{
struct V_23 * V_306 , * V_24 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
T_2 V_286 ;
int V_61 ;
V_306 = F_34 ( V_302 ) ;
V_24 = F_37 ( V_34 ) ;
V_283 . type = V_297 ;
V_283 . V_288 . V_34 = V_34 ;
V_286 = V_309 ;
V_286 |= ( V_316 ? V_317 : V_308 ) ;
V_61 = F_55 ( V_17 , V_306 -> V_17 , V_181 , V_286 , & V_283 ) ;
if ( V_61 )
return V_61 ;
switch ( V_316 ) {
case V_318 :
V_286 = V_319 ;
break;
case V_320 :
V_286 = V_321 ;
break;
case V_322 :
V_286 = V_323 ;
break;
default:
F_59 ( V_78 L_36 ,
V_127 , V_316 ) ;
return 0 ;
}
V_61 = F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_286 , & V_283 ) ;
return V_61 ;
}
static inline int F_136 ( struct V_22 * V_324 ,
struct V_34 * V_325 ,
struct V_22 * V_326 ,
struct V_34 * V_327 )
{
struct V_23 * V_328 , * V_329 , * V_330 , * V_331 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
T_2 V_286 ;
int V_332 , V_333 ;
int V_61 ;
V_328 = F_34 ( V_324 ) ;
V_330 = F_37 ( V_325 ) ;
V_332 = F_137 ( V_325 ) ;
V_329 = F_34 ( V_326 ) ;
V_283 . type = V_297 ;
V_283 . V_288 . V_34 = V_325 ;
V_61 = F_55 ( V_17 , V_328 -> V_17 , V_181 ,
V_317 | V_309 , & V_283 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_55 ( V_17 , V_330 -> V_17 ,
V_330 -> V_31 , V_334 , & V_283 ) ;
if ( V_61 )
return V_61 ;
if ( V_332 && V_326 != V_324 ) {
V_61 = F_55 ( V_17 , V_330 -> V_17 ,
V_330 -> V_31 , V_335 , & V_283 ) ;
if ( V_61 )
return V_61 ;
}
V_283 . V_288 . V_34 = V_327 ;
V_286 = V_308 | V_309 ;
if ( F_138 ( V_327 ) )
V_286 |= V_317 ;
V_61 = F_55 ( V_17 , V_329 -> V_17 , V_181 , V_286 , & V_283 ) ;
if ( V_61 )
return V_61 ;
if ( F_138 ( V_327 ) ) {
V_331 = F_37 ( V_327 ) ;
V_333 = F_137 ( V_327 ) ;
V_61 = F_55 ( V_17 , V_331 -> V_17 ,
V_331 -> V_31 ,
( V_333 ? V_323 : V_321 ) , & V_283 ) ;
if ( V_61 )
return V_61 ;
}
return 0 ;
}
static int F_139 ( const struct V_10 * V_10 ,
struct V_55 * V_56 ,
T_2 V_268 ,
struct V_282 * V_283 )
{
struct V_44 * V_45 ;
T_2 V_17 = F_17 ( V_10 ) ;
V_45 = V_56 -> V_47 ;
return F_55 ( V_17 , V_45 -> V_17 , V_62 , V_268 , V_283 ) ;
}
static inline T_2 F_140 ( int V_171 , int V_336 )
{
T_2 V_286 = 0 ;
if ( ! F_141 ( V_171 ) ) {
if ( V_336 & V_337 )
V_286 |= V_338 ;
if ( V_336 & V_339 )
V_286 |= V_340 ;
if ( V_336 & V_341 )
V_286 |= V_342 ;
else if ( V_336 & V_343 )
V_286 |= V_344 ;
} else {
if ( V_336 & V_337 )
V_286 |= V_309 ;
if ( V_336 & V_343 )
V_286 |= V_345 ;
if ( V_336 & V_339 )
V_286 |= V_346 ;
}
return V_286 ;
}
static inline T_2 F_142 ( struct V_49 * V_49 )
{
T_2 V_286 = 0 ;
if ( V_49 -> V_347 & V_348 )
V_286 |= V_340 ;
if ( V_49 -> V_347 & V_349 ) {
if ( V_49 -> V_350 & V_351 )
V_286 |= V_342 ;
else
V_286 |= V_344 ;
}
if ( ! V_286 ) {
V_286 = V_352 ;
}
return V_286 ;
}
static inline T_2 F_143 ( struct V_49 * V_49 )
{
T_2 V_286 = F_142 ( V_49 ) ;
if ( V_353 )
V_286 |= V_354 ;
return V_286 ;
}
static int F_144 ( struct V_20 * V_355 )
{
T_2 V_356 = F_22 () ;
T_2 V_357 = F_18 ( V_355 ) ;
return F_55 ( V_356 , V_357 , V_358 ,
V_359 , NULL ) ;
}
static int F_145 ( struct V_20 * V_360 ,
struct V_20 * V_361 )
{
T_2 V_356 = F_22 () ;
T_2 V_362 = F_18 ( V_360 ) ;
T_2 V_363 = F_18 ( V_361 ) ;
int V_61 ;
if ( V_356 != V_362 ) {
V_61 = F_55 ( V_356 , V_362 , V_358 ,
V_364 , NULL ) ;
if ( V_61 )
return V_61 ;
}
return F_55 ( V_362 , V_363 , V_358 , V_365 ,
NULL ) ;
}
static int F_146 ( struct V_20 * V_360 ,
struct V_20 * V_361 )
{
T_2 V_362 = F_18 ( V_360 ) ;
T_2 V_363 = F_18 ( V_361 ) ;
return F_55 ( V_362 , V_363 , V_358 , V_366 ,
NULL ) ;
}
static int F_147 ( struct V_20 * V_360 ,
struct V_20 * V_361 ,
struct V_49 * V_49 )
{
T_2 V_17 = F_18 ( V_361 ) ;
struct V_50 * V_51 = V_49 -> V_54 ;
struct V_34 * V_34 = V_49 -> V_299 . V_34 ;
struct V_23 * V_24 ;
struct V_282 V_283 ;
int V_61 ;
V_283 . type = V_298 ;
V_283 . V_288 . V_248 = V_49 -> V_299 ;
if ( V_17 != V_51 -> V_17 ) {
V_61 = F_55 ( V_17 , V_51 -> V_17 ,
V_300 ,
V_301 ,
& V_283 ) ;
if ( V_61 )
return V_61 ;
}
if ( F_126 ( F_64 ( F_36 ( V_34 ) ) ) )
return 0 ;
V_24 = F_37 ( V_34 ) ;
return F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , F_142 ( V_49 ) ,
& V_283 ) ;
}
static int F_148 ( struct V_20 * V_367 ,
unsigned int V_171 )
{
if ( V_171 & V_368 ) {
T_2 V_17 = F_22 () ;
T_2 V_369 = F_18 ( V_367 ) ;
return F_55 ( V_17 , V_369 , V_32 , V_340 , NULL ) ;
}
return F_117 ( V_367 , V_370 ) ;
}
static int F_149 ( struct V_20 * V_371 )
{
return F_116 ( V_371 , V_11 , V_370 ) ;
}
static int F_150 ( struct V_20 * V_267 , T_6 * V_372 ,
T_6 * V_373 , T_6 * V_374 )
{
return F_117 ( V_267 , V_375 ) ;
}
static int F_151 ( struct V_10 * V_133 , const struct V_10 * V_132 ,
const T_6 * V_372 ,
const T_6 * V_373 ,
const T_6 * V_374 )
{
return F_115 ( V_132 , V_133 , V_376 ) ;
}
static int F_152 ( const struct V_10 * V_10 , struct V_377 * V_378 ,
int V_279 , int V_280 )
{
return F_118 ( V_10 , V_279 , V_280 , V_378 == & V_379 ) ;
}
static int F_153 ( int V_380 , int type , int V_381 , struct V_55 * V_56 )
{
const struct V_10 * V_10 = F_75 () ;
int V_61 = 0 ;
if ( ! V_56 )
return 0 ;
switch ( V_380 ) {
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
V_61 = F_139 ( V_10 , V_56 , V_387 , NULL ) ;
break;
case V_388 :
case V_389 :
case V_390 :
V_61 = F_139 ( V_10 , V_56 , V_391 , NULL ) ;
break;
default:
V_61 = 0 ;
break;
}
return V_61 ;
}
static int F_154 ( struct V_34 * V_34 )
{
const struct V_10 * V_10 = F_75 () ;
return F_127 ( V_10 , V_34 , V_392 ) ;
}
static int F_155 ( int type )
{
int V_61 ;
switch ( type ) {
case V_393 :
case V_394 :
V_61 = F_123 ( V_11 , V_395 ) ;
break;
case V_396 :
case V_397 :
case V_398 :
V_61 = F_123 ( V_11 , V_399 ) ;
break;
case V_400 :
case V_401 :
case V_402 :
case V_403 :
case V_404 :
default:
V_61 = F_123 ( V_11 , V_405 ) ;
break;
}
return V_61 ;
}
static int F_156 ( struct V_406 * V_407 , long V_408 )
{
int V_61 , V_409 = 0 ;
V_61 = F_118 ( F_75 () , V_410 ,
V_411 , true ) ;
if ( V_61 == 0 )
V_409 = 1 ;
return V_409 ;
}
static T_2 F_157 ( struct V_20 * V_21 )
{
T_2 V_17 = 0 ;
struct V_20 * V_412 ;
F_19 () ;
V_412 = F_158 ( V_21 ) ;
if ( V_412 )
V_17 = F_18 ( V_412 ) ;
F_21 () ;
return V_17 ;
}
static int F_159 ( const struct V_413 * V_414 ,
const struct V_13 * V_415 ,
const struct V_13 * V_416 )
{
int V_417 = ( V_414 -> V_418 & V_419 ) ;
int V_420 = ( V_414 -> V_49 -> V_299 . V_421 -> V_112 & V_422 ) ;
int V_61 ;
if ( ! V_417 && ! V_420 )
return 0 ;
if ( V_416 -> V_17 == V_415 -> V_17 )
return 0 ;
V_61 = F_160 ( V_415 -> V_17 , V_416 -> V_17 ) ;
if ( V_61 ) {
if ( V_417 )
return - V_423 ;
else
return - V_424 ;
}
return 0 ;
}
static int F_161 ( struct V_413 * V_414 )
{
const struct V_13 * V_415 ;
struct V_13 * V_416 ;
struct V_23 * V_24 ;
struct V_282 V_283 ;
struct V_22 * V_22 = F_130 ( V_414 -> V_49 ) ;
int V_61 ;
if ( V_414 -> V_425 )
return 0 ;
V_415 = F_23 () ;
V_416 = V_414 -> V_10 -> V_19 ;
V_24 = F_34 ( V_22 ) ;
V_416 -> V_17 = V_415 -> V_17 ;
V_416 -> V_16 = V_415 -> V_17 ;
V_416 -> V_305 = 0 ;
V_416 -> V_426 = 0 ;
V_416 -> V_427 = 0 ;
if ( V_415 -> V_428 ) {
V_416 -> V_17 = V_415 -> V_428 ;
V_416 -> V_428 = 0 ;
V_61 = F_159 ( V_414 , V_415 , V_416 ) ;
if ( V_61 )
return V_61 ;
} else {
V_61 = F_112 ( V_415 -> V_17 , V_24 -> V_17 ,
V_271 , NULL ,
& V_416 -> V_17 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_159 ( V_414 , V_415 , V_416 ) ;
if ( V_61 )
V_416 -> V_17 = V_415 -> V_17 ;
}
V_283 . type = V_298 ;
V_283 . V_288 . V_248 = V_414 -> V_49 -> V_299 ;
if ( V_416 -> V_17 == V_415 -> V_17 ) {
V_61 = F_55 ( V_415 -> V_17 , V_24 -> V_17 ,
V_32 , V_429 , & V_283 ) ;
if ( V_61 )
return V_61 ;
} else {
V_61 = F_55 ( V_415 -> V_17 , V_416 -> V_17 ,
V_271 , V_430 , & V_283 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_55 ( V_416 -> V_17 , V_24 -> V_17 ,
V_32 , V_431 , & V_283 ) ;
if ( V_61 )
return V_61 ;
if ( V_414 -> V_418 & V_432 ) {
V_61 = F_55 ( V_415 -> V_17 , V_416 -> V_17 ,
V_271 , V_433 ,
NULL ) ;
if ( V_61 )
return - V_423 ;
}
if ( V_414 -> V_418 &
( V_434 | V_435 ) ) {
T_2 V_436 = F_157 ( V_11 ) ;
if ( V_436 != 0 ) {
V_61 = F_55 ( V_436 , V_416 -> V_17 ,
V_271 ,
V_370 , NULL ) ;
if ( V_61 )
return - V_423 ;
}
}
V_414 -> V_437 |= V_438 ;
}
return 0 ;
}
static int F_162 ( struct V_413 * V_414 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_17 , V_16 ;
int V_439 = 0 ;
V_17 = V_14 -> V_17 ;
V_16 = V_14 -> V_16 ;
if ( V_16 != V_17 ) {
V_439 = F_55 ( V_16 , V_17 ,
V_271 ,
V_440 , NULL ) ;
}
return ! ! V_439 ;
}
static int F_163 ( const void * V_148 , struct V_49 * V_49 , unsigned V_441 )
{
return F_131 ( V_148 , V_49 , F_142 ( V_49 ) ) ? V_441 + 1 : 0 ;
}
static inline void F_164 ( const struct V_10 * V_10 ,
struct V_442 * V_443 )
{
struct V_49 * V_49 , * V_444 = NULL ;
struct V_445 * V_446 ;
int V_447 = 0 ;
unsigned V_448 ;
V_446 = F_165 () ;
if ( V_446 ) {
F_43 ( & V_446 -> V_449 ) ;
if ( ! F_61 ( & V_446 -> V_450 ) ) {
struct V_451 * V_452 ;
V_452 = F_166 ( & V_446 -> V_450 ,
struct V_451 , V_29 ) ;
V_49 = V_452 -> V_49 ;
if ( F_129 ( V_10 , V_49 , V_340 | V_344 ) )
V_447 = 1 ;
}
F_45 ( & V_446 -> V_449 ) ;
F_167 ( V_446 ) ;
}
if ( V_447 )
F_168 () ;
V_448 = F_169 ( V_443 , 0 , F_163 , V_10 ) ;
if ( ! V_448 )
return;
V_444 = F_170 ( & V_453 , V_454 , V_10 ) ;
if ( F_100 ( V_444 ) )
V_444 = NULL ;
do {
F_171 ( V_448 - 1 , V_444 , 0 ) ;
} while ( ( V_448 = F_169 ( V_443 , V_448 , F_163 , V_10 ) ) != 0 );
if ( V_444 )
F_172 ( V_444 ) ;
}
static void F_173 ( struct V_413 * V_414 )
{
struct V_13 * V_416 ;
struct V_455 * V_456 , * V_457 ;
int V_61 , V_93 ;
V_416 = V_414 -> V_10 -> V_19 ;
if ( V_416 -> V_17 == V_416 -> V_16 )
return;
F_164 ( V_414 -> V_10 , V_11 -> V_443 ) ;
V_11 -> V_458 = 0 ;
V_61 = F_55 ( V_416 -> V_16 , V_416 -> V_17 , V_271 ,
V_459 , NULL ) ;
if ( V_61 ) {
F_174 ( V_11 ) ;
for ( V_93 = 0 ; V_93 < V_460 ; V_93 ++ ) {
V_456 = V_11 -> signal -> V_456 + V_93 ;
V_457 = V_461 . signal -> V_456 + V_93 ;
V_456 -> V_462 = F_175 ( V_456 -> V_463 , V_457 -> V_462 ) ;
}
F_176 ( V_11 ) ;
F_177 ( V_11 , V_455 ( V_464 ) ) ;
}
}
static void F_178 ( struct V_413 * V_414 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_465 V_466 ;
T_2 V_16 , V_17 ;
int V_61 , V_93 ;
V_16 = V_14 -> V_16 ;
V_17 = V_14 -> V_17 ;
if ( V_17 == V_16 )
return;
V_61 = F_55 ( V_16 , V_17 , V_271 , V_467 , NULL ) ;
if ( V_61 ) {
memset ( & V_466 , 0 , sizeof V_466 ) ;
for ( V_93 = 0 ; V_93 < 3 ; V_93 ++ )
F_179 ( V_93 , & V_466 , NULL ) ;
F_180 ( & V_11 -> V_468 -> V_469 ) ;
if ( ! F_181 ( V_11 ) ) {
F_182 ( & V_11 -> V_470 ) ;
F_182 ( & V_11 -> signal -> V_471 ) ;
F_183 ( V_11 , 1 ) ;
F_184 ( & V_11 -> V_472 ) ;
F_185 () ;
}
F_186 ( & V_11 -> V_468 -> V_469 ) ;
}
F_187 ( & V_473 ) ;
F_188 ( V_11 , V_11 -> V_474 ) ;
F_189 ( & V_473 ) ;
}
static int F_190 ( struct V_55 * V_56 )
{
return F_49 ( V_56 ) ;
}
static void F_191 ( struct V_55 * V_56 )
{
F_51 ( V_56 ) ;
}
static inline int F_192 ( char * V_164 , int V_475 , char * V_476 , int V_477 )
{
if ( V_475 > V_477 )
return 0 ;
return ! memcmp ( V_164 , V_476 , V_475 ) ;
}
static inline int F_193 ( char * V_476 , int V_95 )
{
return ( F_192 ( V_166 , sizeof( V_166 ) - 1 , V_476 , V_95 ) ||
F_192 ( V_167 , sizeof( V_167 ) - 1 , V_476 , V_95 ) ||
F_192 ( V_169 , sizeof( V_169 ) - 1 , V_476 , V_95 ) ||
F_192 ( V_168 , sizeof( V_168 ) - 1 , V_476 , V_95 ) ||
F_192 ( V_170 , sizeof( V_170 ) - 1 , V_476 , V_95 ) ) ;
}
static inline void F_194 ( char * * V_361 , char * V_360 , int * V_478 , int V_95 )
{
if ( ! * V_478 ) {
* * V_361 = ',' ;
* V_361 += 1 ;
} else
* V_478 = 0 ;
memcpy ( * V_361 , V_360 , V_95 ) ;
* V_361 += V_95 ;
}
static inline void F_195 ( char * * V_361 , char * V_360 , int * V_478 ,
int V_95 )
{
int V_479 = 0 ;
if ( ! * V_478 ) {
* * V_361 = '|' ;
* V_361 += 1 ;
} else
* V_478 = 0 ;
while ( V_479 < V_95 ) {
if ( * V_360 != '"' ) {
* * V_361 = * V_360 ;
* V_361 += 1 ;
}
V_360 += 1 ;
V_479 += 1 ;
}
}
static int F_196 ( char * V_480 , char * V_481 )
{
int V_482 , V_51 , V_61 = 0 ;
char * V_483 , * V_484 , * V_485 ;
char * V_486 , * V_487 , * V_488 ;
int V_489 = 0 ;
V_484 = V_480 ;
V_486 = V_481 ;
V_488 = ( char * ) F_197 ( V_15 ) ;
if ( ! V_488 ) {
V_61 = - V_27 ;
goto V_81;
}
V_487 = V_488 ;
V_482 = V_51 = 1 ;
V_483 = V_485 = V_480 ;
do {
if ( * V_485 == '"' )
V_489 = ! V_489 ;
if ( ( * V_485 == ',' && V_489 == 0 ) ||
* V_485 == '\0' ) {
int V_95 = V_485 - V_484 ;
if ( F_193 ( V_484 , V_95 ) )
F_195 ( & V_486 , V_484 , & V_51 , V_95 ) ;
else
F_194 ( & V_488 , V_484 , & V_482 , V_95 ) ;
V_484 = V_485 + 1 ;
}
} while ( * V_485 ++ );
strcpy ( V_483 , V_487 ) ;
F_103 ( ( unsigned long ) V_487 ) ;
V_81:
return V_61 ;
}
static int F_198 ( struct V_55 * V_56 , void * V_161 )
{
int V_61 , V_93 , * V_86 ;
struct V_91 V_92 ;
char * V_490 , * * V_120 ;
struct V_44 * V_45 = V_56 -> V_47 ;
if ( ! ( V_45 -> V_86 & V_87 ) )
return 0 ;
if ( ! V_161 )
return 0 ;
if ( V_56 -> V_71 -> V_122 & V_123 )
return 0 ;
F_67 ( & V_92 ) ;
V_490 = F_199 () ;
if ( ! V_490 )
return - V_27 ;
V_61 = F_196 ( V_161 , V_490 ) ;
if ( V_61 )
goto V_491;
V_61 = F_82 ( V_490 , & V_92 ) ;
if ( V_61 )
goto V_491;
V_120 = V_92 . V_101 ;
V_86 = V_92 . V_104 ;
for ( V_93 = 0 ; V_93 < V_92 . V_100 ; V_93 ++ ) {
T_2 V_17 ;
if ( V_86 [ V_93 ] == V_88 )
continue;
V_61 = F_77 ( V_120 [ V_93 ] , & V_17 , V_15 ) ;
if ( V_61 ) {
F_59 ( V_78 L_14
L_15 ,
V_120 [ V_93 ] , V_56 -> V_79 , V_56 -> V_71 -> V_72 , V_61 ) ;
goto V_492;
}
V_61 = - V_97 ;
switch ( V_86 [ V_93 ] ) {
case V_105 :
if ( F_73 ( V_45 , V_105 , V_45 -> V_17 , V_17 ) )
goto V_493;
break;
case V_106 :
if ( F_73 ( V_45 , V_106 , V_45 -> V_60 , V_17 ) )
goto V_493;
break;
case V_108 : {
struct V_23 * V_115 ;
V_115 = F_37 ( V_56 -> V_74 ) ;
if ( F_73 ( V_45 , V_108 , V_115 -> V_17 , V_17 ) )
goto V_493;
break;
}
case V_107 :
if ( F_73 ( V_45 , V_107 , V_45 -> V_58 , V_17 ) )
goto V_493;
break;
default:
goto V_492;
}
}
V_61 = 0 ;
V_492:
F_72 ( & V_92 ) ;
V_491:
F_200 ( V_490 ) ;
return V_61 ;
V_493:
F_59 ( V_78 L_37
L_38 , V_56 -> V_79 ,
V_56 -> V_71 -> V_72 ) ;
goto V_492;
}
static int F_201 ( struct V_55 * V_56 , int V_86 , void * V_161 )
{
const struct V_10 * V_10 = F_75 () ;
struct V_282 V_283 ;
int V_61 ;
V_61 = F_86 ( V_56 , V_161 ) ;
if ( V_61 )
return V_61 ;
if ( V_86 & V_494 )
return 0 ;
V_283 . type = V_297 ;
V_283 . V_288 . V_34 = V_56 -> V_74 ;
return F_139 ( V_10 , V_56 , V_495 , & V_283 ) ;
}
static int F_202 ( struct V_34 * V_34 )
{
const struct V_10 * V_10 = F_75 () ;
struct V_282 V_283 ;
V_283 . type = V_297 ;
V_283 . V_288 . V_34 = V_34 -> V_246 -> V_74 ;
return F_139 ( V_10 , V_34 -> V_246 , V_496 , & V_283 ) ;
}
static int F_203 ( const char * V_497 ,
const struct V_248 * V_248 ,
const char * type ,
unsigned long V_86 ,
void * V_161 )
{
const struct V_10 * V_10 = F_75 () ;
if ( V_86 & V_498 )
return F_139 ( V_10 , V_248 -> V_34 -> V_246 ,
V_499 , NULL ) ;
else
return F_128 ( V_10 , V_248 , V_500 ) ;
}
static int F_204 ( struct V_501 * V_421 , int V_86 )
{
const struct V_10 * V_10 = F_75 () ;
return F_139 ( V_10 , V_421 -> V_502 ,
V_503 , NULL ) ;
}
static int F_205 ( struct V_22 * V_22 )
{
return F_24 ( V_22 ) ;
}
static void F_206 ( struct V_22 * V_22 )
{
F_41 ( V_22 ) ;
}
static int F_207 ( struct V_34 * V_34 , int V_171 ,
struct V_303 * V_72 , void * * V_313 ,
T_2 * V_504 )
{
T_2 V_307 ;
int V_61 ;
V_61 = F_132 ( F_208 ( V_34 -> V_505 ) , V_72 ,
F_93 ( V_171 ) ,
& V_307 ) ;
if ( V_61 )
return V_61 ;
return F_70 ( V_307 , ( char * * ) V_313 , V_504 ) ;
}
static int F_209 ( struct V_22 * V_22 , struct V_22 * V_302 ,
const struct V_303 * V_303 ,
const char * * V_72 ,
void * * V_506 , T_7 * V_95 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_44 * V_45 ;
T_2 V_17 , V_307 , V_507 ;
int V_61 ;
char * V_94 ;
V_45 = V_302 -> V_46 -> V_47 ;
V_17 = V_14 -> V_17 ;
V_307 = V_14 -> V_305 ;
V_61 = F_132 (
V_302 , V_303 ,
F_93 ( V_22 -> V_256 ) ,
& V_307 ) ;
if ( V_61 )
return V_61 ;
if ( V_45 -> V_86 & V_87 ) {
struct V_23 * V_24 = V_22 -> V_33 ;
V_24 -> V_31 = F_93 ( V_22 -> V_256 ) ;
V_24 -> V_17 = V_307 ;
V_24 -> V_38 = V_39 ;
}
if ( ! V_37 || ! ( V_45 -> V_86 & V_88 ) )
return - V_80 ;
if ( V_72 )
* V_72 = V_508 ;
if ( V_506 && V_95 ) {
V_61 = F_210 ( V_307 , & V_94 , & V_507 ) ;
if ( V_61 )
return V_61 ;
* V_506 = V_94 ;
* V_95 = V_507 ;
}
return 0 ;
}
static int F_211 ( struct V_22 * V_302 , struct V_34 * V_34 , T_5 V_171 )
{
return F_133 ( V_302 , V_34 , V_32 ) ;
}
static int F_212 ( struct V_34 * V_325 , struct V_22 * V_302 , struct V_34 * V_327 )
{
return F_135 ( V_302 , V_325 , V_318 ) ;
}
static int F_213 ( struct V_22 * V_302 , struct V_34 * V_34 )
{
return F_135 ( V_302 , V_34 , V_320 ) ;
}
static int F_214 ( struct V_22 * V_302 , struct V_34 * V_34 , const char * V_72 )
{
return F_133 ( V_302 , V_34 , V_176 ) ;
}
static int F_215 ( struct V_22 * V_302 , struct V_34 * V_34 , T_5 V_336 )
{
return F_133 ( V_302 , V_34 , V_181 ) ;
}
static int F_216 ( struct V_22 * V_302 , struct V_34 * V_34 )
{
return F_135 ( V_302 , V_34 , V_322 ) ;
}
static int F_217 ( struct V_22 * V_302 , struct V_34 * V_34 , T_5 V_171 , T_8 V_253 )
{
return F_133 ( V_302 , V_34 , F_93 ( V_171 ) ) ;
}
static int F_218 ( struct V_22 * V_509 , struct V_34 * V_325 ,
struct V_22 * V_510 , struct V_34 * V_327 )
{
return F_136 ( V_509 , V_325 , V_510 , V_327 ) ;
}
static int F_219 ( struct V_34 * V_34 )
{
const struct V_10 * V_10 = F_75 () ;
return F_127 ( V_10 , V_34 , V_340 ) ;
}
static int F_220 ( struct V_34 * V_34 , struct V_22 * V_22 ,
bool V_41 )
{
const struct V_10 * V_10 = F_75 () ;
struct V_282 V_283 ;
struct V_23 * V_24 ;
T_2 V_17 ;
F_125 ( V_10 ) ;
V_283 . type = V_297 ;
V_283 . V_288 . V_34 = V_34 ;
V_17 = F_17 ( V_10 ) ;
V_24 = F_32 ( V_22 , V_41 ) ;
if ( F_100 ( V_24 ) )
return F_101 ( V_24 ) ;
return F_221 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_340 , & V_283 ,
V_41 ? V_511 : 0 ) ;
}
static T_9 int F_222 ( struct V_22 * V_22 ,
T_2 V_268 , T_2 V_512 , T_2 V_513 ,
int V_514 ,
unsigned V_86 )
{
struct V_282 V_283 ;
struct V_23 * V_24 = V_22 -> V_33 ;
int V_61 ;
V_283 . type = V_515 ;
V_283 . V_288 . V_22 = V_22 ;
V_61 = F_223 ( F_22 () , V_24 -> V_17 , V_24 -> V_31 , V_268 ,
V_512 , V_513 , V_514 , & V_283 , V_86 ) ;
if ( V_61 )
return V_61 ;
return 0 ;
}
static int F_224 ( struct V_22 * V_22 , int V_336 )
{
const struct V_10 * V_10 = F_75 () ;
T_2 V_268 ;
bool V_516 ;
unsigned V_86 = V_336 & V_511 ;
struct V_23 * V_24 ;
T_2 V_17 ;
struct V_284 V_285 ;
int V_61 , V_294 ;
T_2 V_512 , V_513 ;
V_516 = V_336 & V_517 ;
V_336 &= ( V_339 | V_343 | V_337 | V_341 ) ;
if ( ! V_336 )
return 0 ;
F_125 ( V_10 ) ;
if ( F_126 ( F_64 ( V_22 ) ) )
return 0 ;
V_268 = F_140 ( V_22 -> V_256 , V_336 ) ;
V_17 = F_17 ( V_10 ) ;
V_24 = F_32 ( V_22 , V_86 & V_511 ) ;
if ( F_100 ( V_24 ) )
return F_101 ( V_24 ) ;
V_61 = F_121 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_268 , 0 , & V_285 ) ;
V_512 = F_225 ( V_268 , & V_285 , V_61 ,
V_516 ? V_518 : 0 ,
& V_513 ) ;
if ( F_226 ( ! V_512 ) )
return V_61 ;
V_294 = F_222 ( V_22 , V_268 , V_512 , V_513 , V_61 , V_86 ) ;
if ( V_294 )
return V_294 ;
return V_61 ;
}
static int F_227 ( struct V_34 * V_34 , struct V_519 * V_519 )
{
const struct V_10 * V_10 = F_75 () ;
unsigned int V_520 = V_519 -> V_520 ;
T_10 V_286 = V_344 ;
if ( V_520 & V_521 ) {
V_520 &= ~ ( V_522 | V_523 | V_524 |
V_521 ) ;
if ( ! V_520 )
return 0 ;
}
if ( V_520 & ( V_524 | V_525 | V_526 |
V_527 | V_528 | V_529 ) )
return F_127 ( V_10 , V_34 , V_530 ) ;
if ( V_353 && ( V_520 & V_531 )
&& ! ( V_520 & V_532 ) )
V_286 |= V_354 ;
return F_127 ( V_10 , V_34 , V_286 ) ;
}
static int F_228 ( const struct V_248 * V_248 )
{
return F_128 ( F_75 () , V_248 , V_533 ) ;
}
static int F_229 ( struct V_34 * V_34 , const char * V_72 )
{
const struct V_10 * V_10 = F_75 () ;
if ( ! strncmp ( V_72 , V_534 ,
sizeof V_534 - 1 ) ) {
if ( ! strcmp ( V_72 , V_535 ) ) {
if ( ! F_230 ( V_536 ) )
return - V_423 ;
} else if ( ! F_230 ( V_410 ) ) {
return - V_423 ;
}
}
return F_127 ( V_10 , V_34 , V_530 ) ;
}
static int F_231 ( struct V_34 * V_34 , const char * V_72 ,
const void * V_506 , T_7 V_537 , int V_86 )
{
struct V_22 * V_22 = F_36 ( V_34 ) ;
struct V_23 * V_24 ;
struct V_44 * V_45 ;
struct V_282 V_283 ;
T_2 V_307 , V_17 = F_22 () ;
int V_61 = 0 ;
if ( strcmp ( V_72 , V_82 ) )
return F_229 ( V_34 , V_72 ) ;
V_45 = V_22 -> V_46 -> V_47 ;
if ( ! ( V_45 -> V_86 & V_88 ) )
return - V_80 ;
if ( ! F_232 ( V_22 ) )
return - V_423 ;
V_283 . type = V_297 ;
V_283 . V_288 . V_34 = V_34 ;
V_24 = F_37 ( V_34 ) ;
V_61 = F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 ,
V_538 , & V_283 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_233 ( V_506 , V_537 , & V_307 , V_15 ) ;
if ( V_61 == - V_97 ) {
if ( ! F_230 ( V_539 ) ) {
struct V_540 * V_541 ;
T_7 V_542 ;
const char * V_1 ;
if ( V_506 ) {
V_1 = V_506 ;
if ( V_1 [ V_537 - 1 ] == '\0' )
V_542 = V_537 - 1 ;
else
V_542 = V_537 ;
} else {
V_1 = L_39 ;
V_542 = 0 ;
}
V_541 = F_234 ( V_11 -> V_543 , V_102 , V_544 ) ;
F_235 ( V_541 , L_40 ) ;
F_236 ( V_541 , V_506 , V_542 ) ;
F_237 ( V_541 ) ;
return V_61 ;
}
V_61 = F_238 ( V_506 , V_537 , & V_307 ) ;
}
if ( V_61 )
return V_61 ;
V_61 = F_55 ( V_17 , V_307 , V_24 -> V_31 ,
V_545 , & V_283 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_239 ( V_24 -> V_17 , V_307 , V_17 ,
V_24 -> V_31 ) ;
if ( V_61 )
return V_61 ;
return F_55 ( V_307 ,
V_45 -> V_17 ,
V_62 ,
V_65 ,
& V_283 ) ;
}
static void F_240 ( struct V_34 * V_34 , const char * V_72 ,
const void * V_506 , T_7 V_537 ,
int V_86 )
{
struct V_22 * V_22 = F_36 ( V_34 ) ;
struct V_23 * V_24 ;
T_2 V_307 ;
int V_61 ;
if ( strcmp ( V_72 , V_82 ) ) {
return;
}
V_61 = F_238 ( V_506 , V_537 , & V_307 ) ;
if ( V_61 ) {
F_59 ( V_85 L_41
L_42 ,
V_22 -> V_46 -> V_79 , V_22 -> V_252 , - V_61 ) ;
return;
}
V_24 = F_37 ( V_34 ) ;
V_24 -> V_31 = F_93 ( V_22 -> V_256 ) ;
V_24 -> V_17 = V_307 ;
V_24 -> V_38 = V_39 ;
return;
}
static int F_241 ( struct V_34 * V_34 , const char * V_72 )
{
const struct V_10 * V_10 = F_75 () ;
return F_127 ( V_10 , V_34 , V_533 ) ;
}
static int F_242 ( struct V_34 * V_34 )
{
const struct V_10 * V_10 = F_75 () ;
return F_127 ( V_10 , V_34 , V_533 ) ;
}
static int F_243 ( struct V_34 * V_34 , const char * V_72 )
{
if ( strcmp ( V_72 , V_82 ) )
return F_229 ( V_34 , V_72 ) ;
return - V_424 ;
}
static int F_244 ( struct V_22 * V_22 , const char * V_72 , void * * V_247 , bool V_546 )
{
T_2 V_537 ;
int error ;
char * V_94 = NULL ;
struct V_23 * V_24 ;
if ( strcmp ( V_72 , V_508 ) )
return - V_80 ;
error = F_245 ( F_75 () , & V_379 , V_539 ,
V_411 ) ;
if ( ! error )
error = F_118 ( F_75 () , V_539 ,
V_411 , true ) ;
V_24 = F_34 ( V_22 ) ;
if ( ! error )
error = F_210 ( V_24 -> V_17 , & V_94 ,
& V_537 ) ;
else
error = F_70 ( V_24 -> V_17 , & V_94 , & V_537 ) ;
if ( error )
return error ;
error = V_537 ;
if ( V_546 ) {
* V_247 = V_94 ;
goto V_547;
}
F_52 ( V_94 ) ;
V_547:
return error ;
}
static int F_246 ( struct V_22 * V_22 , const char * V_72 ,
const void * V_506 , T_7 V_537 , int V_86 )
{
struct V_23 * V_24 = F_31 ( V_22 ) ;
T_2 V_307 ;
int V_61 ;
if ( strcmp ( V_72 , V_508 ) )
return - V_80 ;
if ( ! V_506 || ! V_537 )
return - V_424 ;
V_61 = F_233 ( V_506 , V_537 , & V_307 , V_15 ) ;
if ( V_61 )
return V_61 ;
V_24 -> V_31 = F_93 ( V_22 -> V_256 ) ;
V_24 -> V_17 = V_307 ;
V_24 -> V_38 = V_39 ;
return 0 ;
}
static int F_247 ( struct V_22 * V_22 , char * V_247 , T_7 V_548 )
{
const int V_95 = sizeof( V_82 ) ;
if ( V_247 && V_95 <= V_548 )
memcpy ( V_247 , V_82 , V_95 ) ;
return V_95 ;
}
static void F_248 ( struct V_22 * V_22 , T_2 * V_549 )
{
struct V_23 * V_24 = F_31 ( V_22 ) ;
* V_549 = V_24 -> V_17 ;
}
static int F_249 ( struct V_49 * V_49 , int V_336 )
{
const struct V_10 * V_10 = F_75 () ;
struct V_22 * V_22 = F_130 ( V_49 ) ;
if ( ( V_49 -> V_350 & V_351 ) && ( V_336 & V_343 ) )
V_336 |= V_341 ;
return F_131 ( V_10 , V_49 ,
F_140 ( V_22 -> V_256 , V_336 ) ) ;
}
static int F_250 ( struct V_49 * V_49 , int V_336 )
{
struct V_22 * V_22 = F_130 ( V_49 ) ;
struct V_50 * V_51 = V_49 -> V_54 ;
struct V_23 * V_24 ;
T_2 V_17 = F_22 () ;
if ( ! V_336 )
return 0 ;
V_24 = F_34 ( V_22 ) ;
if ( V_17 == V_51 -> V_17 && V_51 -> V_550 == V_24 -> V_17 &&
V_51 -> V_551 == F_251 () )
return 0 ;
return F_249 ( V_49 , V_336 ) ;
}
static int F_252 ( struct V_49 * V_49 )
{
return F_47 ( V_49 ) ;
}
static void F_253 ( struct V_49 * V_49 )
{
F_48 ( V_49 ) ;
}
static int F_254 ( const struct V_10 * V_10 , struct V_49 * V_49 ,
T_2 V_552 , T_4 V_553 )
{
struct V_282 V_283 ;
struct V_50 * V_51 = V_49 -> V_54 ;
struct V_22 * V_22 = F_130 ( V_49 ) ;
struct V_23 * V_24 ;
struct V_554 V_555 ;
T_2 V_556 = F_17 ( V_10 ) ;
int V_61 ;
T_11 V_557 = V_553 >> 8 ;
T_11 V_558 = V_553 & 0xff ;
V_283 . type = V_559 ;
V_283 . V_288 . V_560 = & V_555 ;
V_283 . V_288 . V_560 -> V_553 = V_553 ;
V_283 . V_288 . V_560 -> V_248 = V_49 -> V_299 ;
if ( V_556 != V_51 -> V_17 ) {
V_61 = F_55 ( V_556 , V_51 -> V_17 ,
V_300 ,
V_301 ,
& V_283 ) ;
if ( V_61 )
goto V_81;
}
if ( F_126 ( F_64 ( V_22 ) ) )
return 0 ;
V_24 = F_34 ( V_22 ) ;
V_61 = F_255 ( V_556 , V_24 -> V_17 , V_24 -> V_31 ,
V_552 , V_557 , V_558 , & V_283 ) ;
V_81:
return V_61 ;
}
static int F_256 ( struct V_49 * V_49 , unsigned int V_553 ,
unsigned long V_561 )
{
const struct V_10 * V_10 = F_75 () ;
int error = 0 ;
switch ( V_553 ) {
case V_562 :
case V_563 :
case V_564 :
case V_565 :
case V_566 :
error = F_131 ( V_10 , V_49 , V_533 ) ;
break;
case V_567 :
case V_568 :
error = F_131 ( V_10 , V_49 , V_530 ) ;
break;
case V_569 :
case V_570 :
error = F_131 ( V_10 , V_49 , 0 ) ;
break;
case V_571 :
case V_572 :
error = F_118 ( V_10 , V_573 ,
V_293 , true ) ;
break;
default:
error = F_254 ( V_10 , V_49 , V_352 , ( T_4 ) V_553 ) ;
}
return error ;
}
static int F_257 ( struct V_49 * V_49 , unsigned long V_574 , int V_575 )
{
const struct V_10 * V_10 = F_75 () ;
int V_61 = 0 ;
if ( V_576 &&
( V_574 & V_577 ) && ( ! V_49 || F_64 ( F_130 ( V_49 ) ) ||
( ! V_575 && ( V_574 & V_578 ) ) ) ) {
V_61 = F_115 ( V_10 , V_10 , V_579 ) ;
if ( V_61 )
goto error;
}
if ( V_49 ) {
T_2 V_286 = V_340 ;
if ( V_575 && ( V_574 & V_578 ) )
V_286 |= V_344 ;
if ( V_574 & V_577 )
V_286 |= V_338 ;
return F_131 ( V_10 , V_49 , V_286 ) ;
}
error:
return V_61 ;
}
static int F_258 ( unsigned long V_580 )
{
int V_61 = 0 ;
if ( V_580 < V_581 ) {
T_2 V_17 = F_22 () ;
V_61 = F_55 ( V_17 , V_17 , V_582 ,
V_583 , NULL ) ;
}
return V_61 ;
}
static int F_259 ( struct V_49 * V_49 , unsigned long V_584 ,
unsigned long V_574 , unsigned long V_86 )
{
if ( V_585 )
V_574 = V_584 ;
return F_257 ( V_49 , V_574 ,
( V_86 & V_586 ) == V_587 ) ;
}
static int F_260 ( struct V_588 * V_589 ,
unsigned long V_584 ,
unsigned long V_574 )
{
const struct V_10 * V_10 = F_75 () ;
if ( V_585 )
V_574 = V_584 ;
if ( V_576 &&
( V_574 & V_577 ) && ! ( V_589 -> V_590 & V_591 ) ) {
int V_61 = 0 ;
if ( V_589 -> V_592 >= V_589 -> V_593 -> V_594 &&
V_589 -> V_595 <= V_589 -> V_593 -> V_596 ) {
V_61 = F_115 ( V_10 , V_10 , V_597 ) ;
} else if ( ! V_589 -> V_598 &&
( ( V_589 -> V_592 <= V_589 -> V_593 -> V_599 &&
V_589 -> V_595 >= V_589 -> V_593 -> V_599 ) ||
F_261 ( V_589 , V_11 ) ) ) {
V_61 = F_117 ( V_11 , V_600 ) ;
} else if ( V_589 -> V_598 && V_589 -> V_601 ) {
V_61 = F_131 ( V_10 , V_589 -> V_598 , V_602 ) ;
}
if ( V_61 )
return V_61 ;
}
return F_257 ( V_589 -> V_598 , V_574 , V_589 -> V_590 & V_603 ) ;
}
static int F_262 ( struct V_49 * V_49 , unsigned int V_553 )
{
const struct V_10 * V_10 = F_75 () ;
return F_131 ( V_10 , V_49 , V_604 ) ;
}
static int F_263 ( struct V_49 * V_49 , unsigned int V_553 ,
unsigned long V_561 )
{
const struct V_10 * V_10 = F_75 () ;
int V_605 = 0 ;
switch ( V_553 ) {
case V_606 :
if ( ( V_49 -> V_350 & V_351 ) && ! ( V_561 & V_351 ) ) {
V_605 = F_131 ( V_10 , V_49 , V_344 ) ;
break;
}
case V_607 :
case V_608 :
case V_609 :
case V_610 :
case V_611 :
case V_612 :
V_605 = F_131 ( V_10 , V_49 , 0 ) ;
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
V_605 = F_131 ( V_10 , V_49 , V_604 ) ;
break;
}
return V_605 ;
}
static void F_264 ( struct V_49 * V_49 )
{
struct V_50 * V_51 ;
V_51 = V_49 -> V_54 ;
V_51 -> V_53 = F_22 () ;
}
static int F_265 ( struct V_20 * V_278 ,
struct V_623 * V_624 , int V_625 )
{
struct V_49 * V_49 ;
T_2 V_17 = F_18 ( V_278 ) ;
T_2 V_258 ;
struct V_50 * V_51 ;
V_49 = F_39 ( V_624 , struct V_49 , V_626 ) ;
V_51 = V_49 -> V_54 ;
if ( ! V_625 )
V_258 = F_114 ( V_627 ) ;
else
V_258 = F_114 ( V_625 ) ;
return F_55 ( V_51 -> V_53 , V_17 ,
V_271 , V_258 , NULL ) ;
}
static int F_266 ( struct V_49 * V_49 )
{
const struct V_10 * V_10 = F_75 () ;
return F_131 ( V_10 , V_49 , F_142 ( V_49 ) ) ;
}
static int F_267 ( struct V_49 * V_49 , const struct V_10 * V_10 )
{
struct V_50 * V_51 ;
struct V_23 * V_24 ;
V_51 = V_49 -> V_54 ;
V_24 = F_34 ( F_130 ( V_49 ) ) ;
V_51 -> V_550 = V_24 -> V_17 ;
V_51 -> V_551 = F_251 () ;
return F_129 ( V_10 , V_49 , F_143 ( V_49 ) ) ;
}
static int F_268 ( unsigned long V_628 )
{
return F_117 ( V_11 , V_629 ) ;
}
static int F_269 ( struct V_10 * V_10 , T_12 V_630 )
{
struct V_13 * V_14 ;
V_14 = F_15 ( sizeof( struct V_13 ) , V_630 ) ;
if ( ! V_14 )
return - V_27 ;
V_10 -> V_19 = V_14 ;
return 0 ;
}
static void F_270 ( struct V_10 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_19 ;
F_71 ( V_10 -> V_19 && ( unsigned long ) V_10 -> V_19 < V_249 ) ;
V_10 -> V_19 = ( void * ) 0x7UL ;
F_52 ( V_14 ) ;
}
static int F_271 ( struct V_10 * V_133 , const struct V_10 * V_132 ,
T_12 V_630 )
{
const struct V_13 * V_415 ;
struct V_13 * V_14 ;
V_415 = V_132 -> V_19 ;
V_14 = F_272 ( V_415 , sizeof( struct V_13 ) , V_630 ) ;
if ( ! V_14 )
return - V_27 ;
V_133 -> V_19 = V_14 ;
return 0 ;
}
static void F_273 ( struct V_10 * V_133 , const struct V_10 * V_132 )
{
const struct V_13 * V_415 = V_132 -> V_19 ;
struct V_13 * V_14 = V_133 -> V_19 ;
* V_14 = * V_415 ;
}
static int F_274 ( struct V_10 * V_133 , T_2 V_549 )
{
struct V_13 * V_14 = V_133 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_631 ;
V_631 = F_55 ( V_17 , V_549 ,
V_632 ,
V_633 ,
NULL ) ;
if ( V_631 == 0 ) {
V_14 -> V_17 = V_549 ;
V_14 -> V_305 = 0 ;
V_14 -> V_426 = 0 ;
V_14 -> V_427 = 0 ;
}
return V_631 ;
}
static int F_275 ( struct V_10 * V_133 , struct V_22 * V_22 )
{
struct V_23 * V_24 = F_34 ( V_22 ) ;
struct V_13 * V_14 = V_133 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_631 ;
V_631 = F_55 ( V_17 , V_24 -> V_17 ,
V_632 ,
V_634 ,
NULL ) ;
if ( V_631 == 0 )
V_14 -> V_305 = V_24 -> V_17 ;
return V_631 ;
}
static int F_276 ( char * V_635 )
{
T_2 V_17 ;
struct V_282 V_283 ;
V_17 = F_18 ( V_11 ) ;
V_283 . type = V_636 ;
V_283 . V_288 . V_635 = V_635 ;
return F_55 ( V_17 , V_18 , V_295 ,
V_637 , & V_283 ) ;
}
static int F_277 ( struct V_49 * V_49 )
{
struct V_282 V_283 ;
struct V_23 * V_24 ;
struct V_50 * V_51 ;
T_2 V_17 = F_22 () ;
int V_61 ;
if ( V_49 == NULL )
return F_55 ( V_17 , V_17 , V_295 ,
V_638 , NULL ) ;
V_283 . type = V_298 ;
V_283 . V_288 . V_248 = V_49 -> V_299 ;
V_51 = V_49 -> V_54 ;
if ( V_17 != V_51 -> V_17 ) {
V_61 = F_55 ( V_17 , V_51 -> V_17 , V_300 , V_301 , & V_283 ) ;
if ( V_61 )
return V_61 ;
}
V_24 = F_34 ( F_130 ( V_49 ) ) ;
return F_55 ( V_17 , V_24 -> V_17 , V_295 ,
V_638 , & V_283 ) ;
}
static int F_278 ( struct V_49 * V_49 ,
enum V_639 V_381 )
{
int V_61 = 0 ;
switch ( V_381 ) {
case V_640 :
V_61 = F_277 ( V_49 ) ;
break;
default:
break;
}
return V_61 ;
}
static int F_279 ( struct V_20 * V_148 , T_13 V_641 )
{
return F_117 ( V_148 , V_642 ) ;
}
static int F_280 ( struct V_20 * V_148 )
{
return F_117 ( V_148 , V_643 ) ;
}
static int F_281 ( struct V_20 * V_148 )
{
return F_117 ( V_148 , V_644 ) ;
}
static void F_282 ( struct V_20 * V_148 , T_2 * V_549 )
{
* V_549 = F_18 ( V_148 ) ;
}
static int F_283 ( struct V_20 * V_148 , int V_645 )
{
return F_117 ( V_148 , V_646 ) ;
}
static int F_284 ( struct V_20 * V_148 , int V_647 )
{
return F_117 ( V_148 , V_646 ) ;
}
static int F_285 ( struct V_20 * V_148 )
{
return F_117 ( V_148 , V_648 ) ;
}
static int F_286 ( struct V_20 * V_148 , unsigned int V_649 ,
struct V_455 * V_650 )
{
struct V_455 * V_651 = V_148 -> signal -> V_456 + V_649 ;
if ( V_651 -> V_463 != V_650 -> V_463 )
return F_117 ( V_148 , V_652 ) ;
return 0 ;
}
static int F_287 ( struct V_20 * V_148 )
{
return F_117 ( V_148 , V_646 ) ;
}
static int F_288 ( struct V_20 * V_148 )
{
return F_117 ( V_148 , V_648 ) ;
}
static int F_289 ( struct V_20 * V_148 )
{
return F_117 ( V_148 , V_646 ) ;
}
static int F_290 ( struct V_20 * V_148 , struct V_653 * V_654 ,
int V_257 , T_2 V_549 )
{
T_2 V_258 ;
int V_61 ;
if ( ! V_257 )
V_258 = V_655 ;
else
V_258 = F_114 ( V_257 ) ;
if ( V_549 )
V_61 = F_55 ( V_549 , F_18 ( V_148 ) ,
V_271 , V_258 , NULL ) ;
else
V_61 = F_117 ( V_148 , V_258 ) ;
return V_61 ;
}
static int F_291 ( struct V_20 * V_148 )
{
return F_116 ( V_148 , V_11 , V_260 ) ;
}
static void F_292 ( struct V_20 * V_148 ,
struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 = F_18 ( V_148 ) ;
V_24 -> V_17 = V_17 ;
V_24 -> V_38 = V_39 ;
}
static int F_293 ( struct V_656 * V_657 ,
struct V_282 * V_283 , T_11 * V_658 )
{
int V_659 , V_660 , V_631 = - V_97 ;
struct V_661 V_662 , * V_663 ;
V_659 = F_294 ( V_657 ) ;
V_663 = F_295 ( V_657 , V_659 , sizeof( V_662 ) , & V_662 ) ;
if ( V_663 == NULL )
goto V_81;
V_660 = V_663 -> V_664 * 4 ;
if ( V_660 < sizeof( V_662 ) )
goto V_81;
V_283 -> V_288 . V_665 -> V_666 . V_667 = V_663 -> V_667 ;
V_283 -> V_288 . V_665 -> V_666 . V_668 = V_663 -> V_668 ;
V_631 = 0 ;
if ( V_658 )
* V_658 = V_663 -> V_186 ;
switch ( V_663 -> V_186 ) {
case V_188 : {
struct V_669 V_670 , * V_671 ;
if ( F_296 ( V_663 -> V_672 ) & V_673 )
break;
V_659 += V_660 ;
V_671 = F_295 ( V_657 , V_659 , sizeof( V_670 ) , & V_670 ) ;
if ( V_671 == NULL )
break;
V_283 -> V_288 . V_665 -> V_674 = V_671 -> V_675 ;
V_283 -> V_288 . V_665 -> V_676 = V_671 -> V_677 ;
break;
}
case V_189 : {
struct V_678 V_679 , * V_680 ;
if ( F_296 ( V_663 -> V_672 ) & V_673 )
break;
V_659 += V_660 ;
V_680 = F_295 ( V_657 , V_659 , sizeof( V_679 ) , & V_679 ) ;
if ( V_680 == NULL )
break;
V_283 -> V_288 . V_665 -> V_674 = V_680 -> V_675 ;
V_283 -> V_288 . V_665 -> V_676 = V_680 -> V_677 ;
break;
}
case V_681 : {
struct V_682 V_683 , * V_684 ;
if ( F_296 ( V_663 -> V_672 ) & V_673 )
break;
V_659 += V_660 ;
V_684 = F_295 ( V_657 , V_659 , sizeof( V_683 ) , & V_683 ) ;
if ( V_684 == NULL )
break;
V_283 -> V_288 . V_665 -> V_674 = V_684 -> V_685 ;
V_283 -> V_288 . V_665 -> V_676 = V_684 -> V_686 ;
break;
}
default:
break;
}
V_81:
return V_631 ;
}
static int F_297 ( struct V_656 * V_657 ,
struct V_282 * V_283 , T_11 * V_658 )
{
T_11 V_687 ;
int V_631 = - V_97 , V_659 ;
struct V_688 V_689 , * V_690 ;
T_14 V_672 ;
V_659 = F_294 ( V_657 ) ;
V_690 = F_295 ( V_657 , V_659 , sizeof( V_689 ) , & V_689 ) ;
if ( V_690 == NULL )
goto V_81;
V_283 -> V_288 . V_665 -> V_691 . V_667 = V_690 -> V_667 ;
V_283 -> V_288 . V_665 -> V_691 . V_668 = V_690 -> V_668 ;
V_631 = 0 ;
V_687 = V_690 -> V_687 ;
V_659 += sizeof( V_689 ) ;
V_659 = F_298 ( V_657 , V_659 , & V_687 , & V_672 ) ;
if ( V_659 < 0 )
goto V_81;
if ( V_658 )
* V_658 = V_687 ;
switch ( V_687 ) {
case V_188 : {
struct V_669 V_670 , * V_671 ;
V_671 = F_295 ( V_657 , V_659 , sizeof( V_670 ) , & V_670 ) ;
if ( V_671 == NULL )
break;
V_283 -> V_288 . V_665 -> V_674 = V_671 -> V_675 ;
V_283 -> V_288 . V_665 -> V_676 = V_671 -> V_677 ;
break;
}
case V_189 : {
struct V_678 V_679 , * V_680 ;
V_680 = F_295 ( V_657 , V_659 , sizeof( V_679 ) , & V_679 ) ;
if ( V_680 == NULL )
break;
V_283 -> V_288 . V_665 -> V_674 = V_680 -> V_675 ;
V_283 -> V_288 . V_665 -> V_676 = V_680 -> V_677 ;
break;
}
case V_681 : {
struct V_682 V_683 , * V_684 ;
V_684 = F_295 ( V_657 , V_659 , sizeof( V_683 ) , & V_683 ) ;
if ( V_684 == NULL )
break;
V_283 -> V_288 . V_665 -> V_674 = V_684 -> V_685 ;
V_283 -> V_288 . V_665 -> V_676 = V_684 -> V_686 ;
break;
}
default:
break;
}
V_81:
return V_631 ;
}
static int F_299 ( struct V_656 * V_657 , struct V_282 * V_283 ,
char * * V_692 , int V_693 , T_11 * V_658 )
{
char * V_694 ;
int V_631 ;
switch ( V_283 -> V_288 . V_665 -> V_190 ) {
case V_197 :
V_631 = F_293 ( V_657 , V_283 , V_658 ) ;
if ( V_631 )
goto V_695;
V_694 = ( char * ) ( V_693 ? & V_283 -> V_288 . V_665 -> V_666 . V_667 :
& V_283 -> V_288 . V_665 -> V_666 . V_668 ) ;
goto V_696;
#if F_300 ( V_697 ) || F_300 ( V_698 )
case V_198 :
V_631 = F_297 ( V_657 , V_283 , V_658 ) ;
if ( V_631 )
goto V_695;
V_694 = ( char * ) ( V_693 ? & V_283 -> V_288 . V_665 -> V_691 . V_667 :
& V_283 -> V_288 . V_665 -> V_691 . V_668 ) ;
goto V_696;
#endif
default:
V_694 = NULL ;
goto V_696;
}
V_695:
F_59 ( V_78
L_43
L_44 ) ;
return V_631 ;
V_696:
if ( V_692 )
* V_692 = V_694 ;
return 0 ;
}
static int F_301 ( struct V_656 * V_657 , T_4 V_190 , T_2 * V_17 )
{
int V_605 ;
T_2 V_699 ;
T_2 V_700 ;
T_2 V_701 ;
V_605 = F_302 ( V_657 , & V_699 ) ;
if ( F_126 ( V_605 ) )
return - V_424 ;
V_605 = F_303 ( V_657 , V_190 , & V_701 , & V_700 ) ;
if ( F_126 ( V_605 ) )
return - V_424 ;
V_605 = F_304 ( V_700 , V_701 , V_699 , V_17 ) ;
if ( F_126 ( V_605 ) ) {
F_59 ( V_78
L_45
L_46 ) ;
return - V_424 ;
}
return 0 ;
}
static int F_305 ( T_2 V_702 , T_2 V_703 , T_2 * V_704 )
{
int V_605 = 0 ;
if ( V_703 != V_705 )
V_605 = F_306 ( V_702 , V_703 , V_704 ) ;
else
* V_704 = V_702 ;
return V_605 ;
}
static int F_307 ( const struct V_13 * V_14 ,
T_4 V_706 , T_2 * V_707 )
{
if ( V_14 -> V_427 > V_705 ) {
* V_707 = V_14 -> V_427 ;
return 0 ;
}
return F_112 ( V_14 -> V_17 , V_14 -> V_17 , V_706 , NULL ,
V_707 ) ;
}
static int F_308 ( struct V_20 * V_21 , struct V_708 * V_709 , T_2 V_268 )
{
struct V_710 * V_711 = V_709 -> V_712 ;
struct V_282 V_283 ;
struct V_713 V_665 = { 0 ,} ;
T_2 V_270 = F_18 ( V_21 ) ;
if ( V_711 -> V_17 == V_18 )
return 0 ;
V_283 . type = V_714 ;
V_283 . V_288 . V_665 = & V_665 ;
V_283 . V_288 . V_665 -> V_709 = V_709 ;
return F_55 ( V_270 , V_711 -> V_17 , V_711 -> V_31 , V_268 , & V_283 ) ;
}
static int F_309 ( int V_190 , int type ,
int V_186 , int V_715 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_307 ;
T_4 V_706 ;
int V_61 ;
if ( V_715 )
return 0 ;
V_706 = F_96 ( V_190 , type , V_186 ) ;
V_61 = F_307 ( V_14 , V_706 , & V_307 ) ;
if ( V_61 )
return V_61 ;
return F_55 ( V_14 -> V_17 , V_307 , V_706 , V_716 , NULL ) ;
}
static int F_310 ( struct V_717 * V_708 , int V_190 ,
int type , int V_186 , int V_715 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_24 = F_31 ( F_311 ( V_708 ) ) ;
struct V_710 * V_711 ;
int V_605 = 0 ;
V_24 -> V_31 = F_96 ( V_190 , type , V_186 ) ;
if ( V_715 )
V_24 -> V_17 = V_18 ;
else {
V_605 = F_307 ( V_14 , V_24 -> V_31 , & ( V_24 -> V_17 ) ) ;
if ( V_605 )
return V_605 ;
}
V_24 -> V_38 = V_39 ;
if ( V_708 -> V_709 ) {
V_711 = V_708 -> V_709 -> V_712 ;
V_711 -> V_17 = V_24 -> V_17 ;
V_711 -> V_31 = V_24 -> V_31 ;
V_605 = F_312 ( V_708 -> V_709 , V_190 ) ;
}
return V_605 ;
}
static int F_313 ( struct V_717 * V_708 , struct V_718 * V_719 , int V_720 )
{
struct V_708 * V_709 = V_708 -> V_709 ;
T_4 V_190 ;
int V_605 ;
V_605 = F_308 ( V_11 , V_709 , V_721 ) ;
if ( V_605 )
goto V_81;
V_190 = V_709 -> V_722 ;
if ( V_190 == V_197 || V_190 == V_198 ) {
char * V_694 ;
struct V_710 * V_711 = V_709 -> V_712 ;
struct V_282 V_283 ;
struct V_713 V_665 = { 0 ,} ;
struct V_723 * V_724 = NULL ;
struct V_725 * V_726 = NULL ;
unsigned short V_727 ;
T_2 V_17 , V_728 ;
if ( V_190 == V_197 ) {
V_724 = (struct V_723 * ) V_719 ;
V_727 = F_296 ( V_724 -> V_729 ) ;
V_694 = ( char * ) & V_724 -> V_730 . V_731 ;
} else {
V_726 = (struct V_725 * ) V_719 ;
V_727 = F_296 ( V_726 -> V_732 ) ;
V_694 = ( char * ) & V_726 -> V_733 . V_734 ;
}
if ( V_727 ) {
int V_735 , V_736 ;
F_314 ( F_315 ( V_709 ) , & V_735 , & V_736 ) ;
if ( V_727 < V_737 ( V_738, V_735 ) || V_727 > V_736 ) {
V_605 = F_316 ( V_709 -> V_739 ,
V_727 , & V_17 ) ;
if ( V_605 )
goto V_81;
V_283 . type = V_714 ;
V_283 . V_288 . V_665 = & V_665 ;
V_283 . V_288 . V_665 -> V_674 = F_317 ( V_727 ) ;
V_283 . V_288 . V_665 -> V_190 = V_190 ;
V_605 = F_55 ( V_711 -> V_17 , V_17 ,
V_711 -> V_31 ,
V_740 , & V_283 ) ;
if ( V_605 )
goto V_81;
}
}
switch ( V_711 -> V_31 ) {
case V_199 :
V_728 = V_741 ;
break;
case V_201 :
V_728 = V_742 ;
break;
case V_203 :
V_728 = V_743 ;
break;
default:
V_728 = V_744 ;
break;
}
V_605 = F_318 ( V_694 , V_190 , & V_17 ) ;
if ( V_605 )
goto V_81;
V_283 . type = V_714 ;
V_283 . V_288 . V_665 = & V_665 ;
V_283 . V_288 . V_665 -> V_674 = F_317 ( V_727 ) ;
V_283 . V_288 . V_665 -> V_190 = V_190 ;
if ( V_190 == V_197 )
V_283 . V_288 . V_665 -> V_666 . V_667 = V_724 -> V_730 . V_731 ;
else
V_283 . V_288 . V_665 -> V_691 . V_667 = V_726 -> V_733 ;
V_605 = F_55 ( V_711 -> V_17 , V_17 ,
V_711 -> V_31 , V_728 , & V_283 ) ;
if ( V_605 )
goto V_81;
}
V_81:
return V_605 ;
}
static int F_319 ( struct V_717 * V_708 , struct V_718 * V_719 , int V_720 )
{
struct V_708 * V_709 = V_708 -> V_709 ;
struct V_710 * V_711 = V_709 -> V_712 ;
int V_605 ;
V_605 = F_308 ( V_11 , V_709 , V_745 ) ;
if ( V_605 )
return V_605 ;
if ( V_711 -> V_31 == V_199 ||
V_711 -> V_31 == V_203 ) {
struct V_282 V_283 ;
struct V_713 V_665 = { 0 ,} ;
struct V_723 * V_724 = NULL ;
struct V_725 * V_726 = NULL ;
unsigned short V_727 ;
T_2 V_17 , V_258 ;
if ( V_709 -> V_722 == V_197 ) {
V_724 = (struct V_723 * ) V_719 ;
if ( V_720 < sizeof( struct V_723 ) )
return - V_97 ;
V_727 = F_296 ( V_724 -> V_729 ) ;
} else {
V_726 = (struct V_725 * ) V_719 ;
if ( V_720 < V_746 )
return - V_97 ;
V_727 = F_296 ( V_726 -> V_732 ) ;
}
V_605 = F_316 ( V_709 -> V_739 , V_727 , & V_17 ) ;
if ( V_605 )
goto V_81;
V_258 = ( V_711 -> V_31 == V_199 ) ?
V_747 : V_748 ;
V_283 . type = V_714 ;
V_283 . V_288 . V_665 = & V_665 ;
V_283 . V_288 . V_665 -> V_676 = F_317 ( V_727 ) ;
V_283 . V_288 . V_665 -> V_190 = V_709 -> V_722 ;
V_605 = F_55 ( V_711 -> V_17 , V_17 , V_711 -> V_31 , V_258 , & V_283 ) ;
if ( V_605 )
goto V_81;
}
V_605 = F_320 ( V_709 , V_719 ) ;
V_81:
return V_605 ;
}
static int F_321 ( struct V_717 * V_708 , int V_749 )
{
return F_308 ( V_11 , V_708 -> V_709 , V_750 ) ;
}
static int F_322 ( struct V_717 * V_708 , struct V_717 * V_751 )
{
int V_605 ;
struct V_23 * V_24 ;
struct V_23 * V_145 ;
V_605 = F_308 ( V_11 , V_708 -> V_709 , V_752 ) ;
if ( V_605 )
return V_605 ;
V_145 = F_31 ( F_311 ( V_751 ) ) ;
V_24 = F_31 ( F_311 ( V_708 ) ) ;
V_145 -> V_31 = V_24 -> V_31 ;
V_145 -> V_17 = V_24 -> V_17 ;
V_145 -> V_38 = V_39 ;
return 0 ;
}
static int F_323 ( struct V_717 * V_708 , struct V_753 * V_754 ,
int V_537 )
{
return F_308 ( V_11 , V_708 -> V_709 , V_755 ) ;
}
static int F_324 ( struct V_717 * V_708 , struct V_753 * V_754 ,
int V_537 , int V_86 )
{
return F_308 ( V_11 , V_708 -> V_709 , V_756 ) ;
}
static int F_325 ( struct V_717 * V_708 )
{
return F_308 ( V_11 , V_708 -> V_709 , V_757 ) ;
}
static int F_326 ( struct V_717 * V_708 )
{
return F_308 ( V_11 , V_708 -> V_709 , V_757 ) ;
}
static int F_327 ( struct V_717 * V_708 , int V_758 , int V_759 )
{
int V_605 ;
V_605 = F_308 ( V_11 , V_708 -> V_709 , V_760 ) ;
if ( V_605 )
return V_605 ;
return F_328 ( V_708 , V_758 , V_759 ) ;
}
static int F_329 ( struct V_717 * V_708 , int V_758 ,
int V_759 )
{
return F_308 ( V_11 , V_708 -> V_709 , V_761 ) ;
}
static int F_330 ( struct V_717 * V_708 , int V_762 )
{
return F_308 ( V_11 , V_708 -> V_709 , V_763 ) ;
}
static int F_331 ( struct V_708 * V_708 ,
struct V_708 * V_764 ,
struct V_708 * V_765 )
{
struct V_710 * V_766 = V_708 -> V_712 ;
struct V_710 * V_767 = V_764 -> V_712 ;
struct V_710 * V_768 = V_765 -> V_712 ;
struct V_282 V_283 ;
struct V_713 V_665 = { 0 ,} ;
int V_605 ;
V_283 . type = V_714 ;
V_283 . V_288 . V_665 = & V_665 ;
V_283 . V_288 . V_665 -> V_709 = V_764 ;
V_605 = F_55 ( V_766 -> V_17 , V_767 -> V_17 ,
V_767 -> V_31 ,
V_769 , & V_283 ) ;
if ( V_605 )
return V_605 ;
V_768 -> V_770 = V_766 -> V_17 ;
V_605 = F_306 ( V_767 -> V_17 , V_766 -> V_17 ,
& V_768 -> V_17 ) ;
if ( V_605 )
return V_605 ;
V_766 -> V_770 = V_768 -> V_17 ;
return 0 ;
}
static int F_332 ( struct V_717 * V_708 ,
struct V_717 * V_764 )
{
struct V_710 * V_771 = V_708 -> V_709 -> V_712 ;
struct V_710 * V_772 = V_764 -> V_709 -> V_712 ;
struct V_282 V_283 ;
struct V_713 V_665 = { 0 ,} ;
V_283 . type = V_714 ;
V_283 . V_288 . V_665 = & V_665 ;
V_283 . V_288 . V_665 -> V_709 = V_764 -> V_709 ;
return F_55 ( V_771 -> V_17 , V_772 -> V_17 , V_772 -> V_31 , V_773 ,
& V_283 ) ;
}
static int F_333 ( struct V_665 * V_378 , int V_774 ,
char * V_694 , T_4 V_190 , T_2 V_770 ,
struct V_282 * V_283 )
{
int V_605 ;
T_2 V_775 ;
T_2 V_776 ;
V_605 = F_334 ( V_378 , V_774 , & V_775 ) ;
if ( V_605 )
return V_605 ;
V_605 = F_55 ( V_770 , V_775 ,
V_777 , V_778 , V_283 ) ;
if ( V_605 )
return V_605 ;
V_605 = F_318 ( V_694 , V_190 , & V_776 ) ;
if ( V_605 )
return V_605 ;
return F_55 ( V_770 , V_776 ,
V_779 , V_780 , V_283 ) ;
}
static int F_335 ( struct V_708 * V_709 , struct V_656 * V_657 ,
T_4 V_190 )
{
int V_605 = 0 ;
struct V_710 * V_711 = V_709 -> V_712 ;
T_2 V_702 = V_711 -> V_17 ;
struct V_282 V_283 ;
struct V_713 V_665 = { 0 ,} ;
char * V_694 ;
V_283 . type = V_714 ;
V_283 . V_288 . V_665 = & V_665 ;
V_283 . V_288 . V_665 -> V_781 = V_657 -> V_782 ;
V_283 . V_288 . V_665 -> V_190 = V_190 ;
V_605 = F_299 ( V_657 , & V_283 , & V_694 , 1 , NULL ) ;
if ( V_605 )
return V_605 ;
if ( F_4 () ) {
V_605 = F_55 ( V_702 , V_657 -> V_783 , V_784 ,
V_785 , & V_283 ) ;
if ( V_605 )
return V_605 ;
}
V_605 = F_336 ( V_711 , V_657 , V_190 , & V_283 ) ;
if ( V_605 )
return V_605 ;
V_605 = F_337 ( V_711 -> V_17 , V_657 , & V_283 ) ;
return V_605 ;
}
static int F_338 ( struct V_708 * V_709 , struct V_656 * V_657 )
{
int V_605 ;
struct V_710 * V_711 = V_709 -> V_712 ;
T_4 V_190 = V_709 -> V_722 ;
T_2 V_702 = V_711 -> V_17 ;
struct V_282 V_283 ;
struct V_713 V_665 = { 0 ,} ;
char * V_694 ;
T_11 V_786 ;
T_11 V_787 ;
if ( V_190 != V_197 && V_190 != V_198 )
return 0 ;
if ( V_190 == V_198 && V_657 -> V_186 == F_317 ( V_788 ) )
V_190 = V_197 ;
if ( ! V_789 )
return F_335 ( V_709 , V_657 , V_190 ) ;
V_786 = F_4 () ;
V_787 = F_6 () ;
if ( ! V_786 && ! V_787 )
return 0 ;
V_283 . type = V_714 ;
V_283 . V_288 . V_665 = & V_665 ;
V_283 . V_288 . V_665 -> V_781 = V_657 -> V_782 ;
V_283 . V_288 . V_665 -> V_190 = V_190 ;
V_605 = F_299 ( V_657 , & V_283 , & V_694 , 1 , NULL ) ;
if ( V_605 )
return V_605 ;
if ( V_787 ) {
T_2 V_770 ;
V_605 = F_301 ( V_657 , V_190 , & V_770 ) ;
if ( V_605 )
return V_605 ;
V_605 = F_333 ( F_315 ( V_709 ) , V_657 -> V_782 ,
V_694 , V_190 , V_770 , & V_283 ) ;
if ( V_605 ) {
F_339 ( V_657 , V_605 , 0 ) ;
return V_605 ;
}
V_605 = F_55 ( V_702 , V_770 , V_790 ,
V_791 , & V_283 ) ;
if ( V_605 ) {
F_339 ( V_657 , V_605 , 0 ) ;
return V_605 ;
}
}
if ( V_786 ) {
V_605 = F_55 ( V_702 , V_657 -> V_783 , V_784 ,
V_785 , & V_283 ) ;
if ( V_605 )
return V_605 ;
}
return V_605 ;
}
static int F_340 ( struct V_717 * V_708 , char T_15 * V_792 ,
int T_15 * V_793 , unsigned V_95 )
{
int V_605 = 0 ;
char * V_794 ;
T_2 V_795 ;
struct V_710 * V_711 = V_708 -> V_709 -> V_712 ;
T_2 V_770 = V_705 ;
if ( V_711 -> V_31 == V_194 ||
V_711 -> V_31 == V_199 )
V_770 = V_711 -> V_770 ;
if ( V_770 == V_705 )
return - V_796 ;
V_605 = F_70 ( V_770 , & V_794 , & V_795 ) ;
if ( V_605 )
return V_605 ;
if ( V_795 > V_95 ) {
V_605 = - V_251 ;
goto V_797;
}
if ( F_341 ( V_792 , V_794 , V_795 ) )
V_605 = - V_798 ;
V_797:
if ( F_342 ( V_795 , V_793 ) )
V_605 = - V_798 ;
F_52 ( V_794 ) ;
return V_605 ;
}
static int F_343 ( struct V_717 * V_708 , struct V_656 * V_657 , T_2 * V_549 )
{
T_2 V_799 = V_705 ;
T_4 V_190 ;
struct V_23 * V_24 ;
if ( V_657 && V_657 -> V_186 == F_317 ( V_788 ) )
V_190 = V_197 ;
else if ( V_657 && V_657 -> V_186 == F_317 ( V_800 ) )
V_190 = V_198 ;
else if ( V_708 )
V_190 = V_708 -> V_709 -> V_722 ;
else
goto V_81;
if ( V_708 && V_190 == V_191 ) {
V_24 = F_31 ( F_311 ( V_708 ) ) ;
V_799 = V_24 -> V_17 ;
} else if ( V_657 )
F_301 ( V_657 , V_190 , & V_799 ) ;
V_81:
* V_549 = V_799 ;
if ( V_799 == V_705 )
return - V_97 ;
return 0 ;
}
static int F_344 ( struct V_708 * V_709 , int V_190 , T_12 V_801 )
{
struct V_710 * V_711 ;
V_711 = F_15 ( sizeof( * V_711 ) , V_801 ) ;
if ( ! V_711 )
return - V_27 ;
V_711 -> V_770 = V_30 ;
V_711 -> V_17 = V_30 ;
V_711 -> V_31 = V_244 ;
F_345 ( V_711 ) ;
V_709 -> V_712 = V_711 ;
return 0 ;
}
static void F_346 ( struct V_708 * V_709 )
{
struct V_710 * V_711 = V_709 -> V_712 ;
V_709 -> V_712 = NULL ;
F_347 ( V_711 ) ;
F_52 ( V_711 ) ;
}
static void F_348 ( const struct V_708 * V_709 , struct V_708 * V_765 )
{
struct V_710 * V_711 = V_709 -> V_712 ;
struct V_710 * V_802 = V_765 -> V_712 ;
V_802 -> V_17 = V_711 -> V_17 ;
V_802 -> V_770 = V_711 -> V_770 ;
V_802 -> V_31 = V_711 -> V_31 ;
F_345 ( V_802 ) ;
}
static void F_349 ( struct V_708 * V_709 , T_2 * V_549 )
{
if ( ! V_709 )
* V_549 = V_803 ;
else {
struct V_710 * V_711 = V_709 -> V_712 ;
* V_549 = V_711 -> V_17 ;
}
}
static void F_350 ( struct V_708 * V_709 , struct V_717 * V_371 )
{
struct V_23 * V_24 =
F_31 ( F_311 ( V_371 ) ) ;
struct V_710 * V_711 = V_709 -> V_712 ;
if ( V_709 -> V_722 == V_197 || V_709 -> V_722 == V_198 ||
V_709 -> V_722 == V_191 )
V_24 -> V_17 = V_711 -> V_17 ;
V_711 -> V_31 = V_24 -> V_31 ;
}
static int F_351 ( struct V_708 * V_709 , struct V_656 * V_657 ,
struct V_804 * V_805 )
{
struct V_710 * V_711 = V_709 -> V_712 ;
int V_605 ;
T_4 V_190 = V_805 -> V_806 -> V_190 ;
T_2 V_807 ;
T_2 V_808 ;
V_605 = F_301 ( V_657 , V_190 , & V_808 ) ;
if ( V_605 )
return V_605 ;
V_605 = F_305 ( V_711 -> V_17 , V_808 , & V_807 ) ;
if ( V_605 )
return V_605 ;
V_805 -> V_549 = V_807 ;
V_805 -> V_799 = V_808 ;
return F_352 ( V_805 , V_190 ) ;
}
static void F_353 ( struct V_708 * V_765 ,
const struct V_804 * V_805 )
{
struct V_710 * V_802 = V_765 -> V_712 ;
V_802 -> V_17 = V_805 -> V_549 ;
V_802 -> V_770 = V_805 -> V_799 ;
F_354 ( V_765 , V_805 -> V_806 -> V_190 ) ;
}
static void F_355 ( struct V_708 * V_709 , struct V_656 * V_657 )
{
T_4 V_190 = V_709 -> V_722 ;
struct V_710 * V_711 = V_709 -> V_712 ;
if ( V_190 == V_198 && V_657 -> V_186 == F_317 ( V_788 ) )
V_190 = V_197 ;
F_301 ( V_657 , V_190 , & V_711 -> V_770 ) ;
}
static int F_356 ( T_2 V_17 )
{
const struct V_13 * V_809 ;
T_2 V_270 ;
V_809 = F_23 () ;
V_270 = V_809 -> V_17 ;
return F_55 ( V_270 , V_17 , V_784 , V_810 , NULL ) ;
}
static void F_357 ( void )
{
F_358 ( & V_7 ) ;
}
static void F_359 ( void )
{
F_360 ( & V_7 ) ;
}
static void F_361 ( const struct V_804 * V_805 ,
struct V_811 * V_812 )
{
V_812 -> V_813 = V_805 -> V_549 ;
}
static int F_362 ( void * * V_19 )
{
struct V_814 * V_815 ;
V_815 = F_15 ( sizeof( * V_815 ) , V_15 ) ;
if ( ! V_815 )
return - V_27 ;
V_815 -> V_17 = F_22 () ;
* V_19 = V_815 ;
return 0 ;
}
static void F_363 ( void * V_19 )
{
F_52 ( V_19 ) ;
}
static int F_364 ( void )
{
T_2 V_17 = F_22 () ;
return F_55 ( V_17 , V_17 , V_816 , V_817 ,
NULL ) ;
}
static int F_365 ( void * V_19 )
{
struct V_814 * V_815 = V_19 ;
return F_55 ( F_22 () , V_815 -> V_17 , V_816 ,
V_818 , NULL ) ;
}
static int F_366 ( struct V_708 * V_709 , void * V_19 )
{
struct V_814 * V_815 = V_19 ;
struct V_710 * V_711 = V_709 -> V_712 ;
V_711 -> V_17 = V_815 -> V_17 ;
V_711 -> V_31 = V_816 ;
return 0 ;
}
static int F_367 ( void * V_19 )
{
struct V_814 * V_815 = V_19 ;
T_2 V_17 = F_22 () ;
int V_605 ;
V_605 = F_55 ( V_17 , V_815 -> V_17 , V_816 ,
V_819 , NULL ) ;
if ( V_605 )
return V_605 ;
V_605 = F_55 ( V_17 , V_17 , V_816 ,
V_820 , NULL ) ;
if ( V_605 )
return V_605 ;
V_815 -> V_17 = V_17 ;
return 0 ;
}
static int F_368 ( struct V_708 * V_709 , struct V_656 * V_657 )
{
int V_605 = 0 ;
T_2 V_258 ;
struct V_821 * V_822 ;
struct V_710 * V_711 = V_709 -> V_712 ;
if ( V_657 -> V_95 < V_823 ) {
V_605 = - V_97 ;
goto V_81;
}
V_822 = F_369 ( V_657 ) ;
V_605 = F_370 ( V_711 -> V_31 , V_822 -> V_824 , & V_258 ) ;
if ( V_605 ) {
if ( V_605 == - V_97 ) {
F_371 ( L_47
L_48
L_49 ,
V_709 -> V_739 , V_822 -> V_824 ,
V_825 [ V_711 -> V_31 - 1 ] . V_72 ,
F_372 ( V_11 ) , V_11 -> V_826 ) ;
if ( ! V_3 || F_373 () )
V_605 = 0 ;
}
if ( V_605 == - V_827 )
V_605 = 0 ;
goto V_81;
}
V_605 = F_308 ( V_11 , V_709 , V_258 ) ;
V_81:
return V_605 ;
}
static unsigned int F_374 ( struct V_656 * V_657 ,
const struct V_828 * V_829 ,
T_4 V_190 )
{
int V_605 ;
char * V_694 ;
T_2 V_770 ;
struct V_282 V_283 ;
struct V_713 V_665 = { 0 ,} ;
T_11 V_786 ;
T_11 V_830 ;
T_11 V_787 ;
if ( ! V_789 )
return V_831 ;
V_786 = F_4 () ;
V_830 = F_7 () ;
V_787 = F_6 () ;
if ( ! V_786 && ! V_787 )
return V_831 ;
if ( F_301 ( V_657 , V_190 , & V_770 ) != 0 )
return V_832 ;
V_283 . type = V_714 ;
V_283 . V_288 . V_665 = & V_665 ;
V_283 . V_288 . V_665 -> V_781 = V_829 -> V_774 ;
V_283 . V_288 . V_665 -> V_190 = V_190 ;
if ( F_299 ( V_657 , & V_283 , & V_694 , 1 , NULL ) != 0 )
return V_832 ;
if ( V_787 ) {
V_605 = F_333 ( F_375 ( V_829 ) , V_829 -> V_774 ,
V_694 , V_190 , V_770 , & V_283 ) ;
if ( V_605 ) {
F_339 ( V_657 , V_605 , 1 ) ;
return V_832 ;
}
}
if ( V_786 )
if ( F_55 ( V_770 , V_657 -> V_783 ,
V_784 , V_833 , & V_283 ) )
return V_832 ;
if ( V_830 )
if ( F_376 ( V_657 , V_190 , V_770 ) != 0 )
return V_832 ;
return V_831 ;
}
static unsigned int F_377 ( void * V_834 ,
struct V_656 * V_657 ,
const struct V_835 * V_836 )
{
return F_374 ( V_657 , V_836 -> V_837 , V_197 ) ;
}
static unsigned int F_378 ( void * V_834 ,
struct V_656 * V_657 ,
const struct V_835 * V_836 )
{
return F_374 ( V_657 , V_836 -> V_837 , V_198 ) ;
}
static unsigned int F_379 ( struct V_656 * V_657 ,
T_4 V_190 )
{
struct V_708 * V_709 ;
T_2 V_17 ;
if ( ! F_7 () )
return V_831 ;
V_709 = V_657 -> V_709 ;
if ( V_709 ) {
struct V_710 * V_711 ;
if ( F_380 ( V_709 ) )
return V_831 ;
V_711 = V_709 -> V_712 ;
V_17 = V_711 -> V_17 ;
} else
V_17 = V_18 ;
if ( F_376 ( V_657 , V_190 , V_17 ) != 0 )
return V_832 ;
return V_831 ;
}
static unsigned int F_381 ( void * V_834 ,
struct V_656 * V_657 ,
const struct V_835 * V_836 )
{
return F_379 ( V_657 , V_197 ) ;
}
static unsigned int F_382 ( struct V_656 * V_657 ,
int V_774 ,
T_4 V_190 )
{
struct V_708 * V_709 = F_383 ( V_657 ) ;
struct V_710 * V_711 ;
struct V_282 V_283 ;
struct V_713 V_665 = { 0 ,} ;
char * V_694 ;
T_11 V_658 ;
if ( V_709 == NULL )
return V_831 ;
V_711 = V_709 -> V_712 ;
V_283 . type = V_714 ;
V_283 . V_288 . V_665 = & V_665 ;
V_283 . V_288 . V_665 -> V_781 = V_774 ;
V_283 . V_288 . V_665 -> V_190 = V_190 ;
if ( F_299 ( V_657 , & V_283 , & V_694 , 0 , & V_658 ) )
return V_832 ;
if ( F_4 () )
if ( F_55 ( V_711 -> V_17 , V_657 -> V_783 ,
V_784 , V_838 , & V_283 ) )
return F_384 ( - V_839 ) ;
if ( F_385 ( V_711 -> V_17 , V_657 , & V_283 , V_658 ) )
return F_384 ( - V_839 ) ;
return V_831 ;
}
static unsigned int F_386 ( struct V_656 * V_657 ,
const struct V_828 * V_840 ,
T_4 V_190 )
{
T_2 V_841 ;
T_2 V_770 ;
int V_774 = V_840 -> V_774 ;
struct V_708 * V_709 ;
struct V_282 V_283 ;
struct V_713 V_665 = { 0 ,} ;
char * V_694 ;
T_11 V_786 ;
T_11 V_787 ;
if ( ! V_789 )
return F_382 ( V_657 , V_774 , V_190 ) ;
V_786 = F_4 () ;
V_787 = F_6 () ;
if ( ! V_786 && ! V_787 )
return V_831 ;
V_709 = F_383 ( V_657 ) ;
#ifdef F_387
if ( F_388 ( V_657 ) != NULL && F_388 ( V_657 ) -> V_842 != NULL &&
! ( V_709 && F_380 ( V_709 ) ) )
return V_831 ;
#endif
if ( V_709 == NULL ) {
if ( V_657 -> V_782 ) {
V_841 = V_843 ;
if ( F_301 ( V_657 , V_190 , & V_770 ) )
return V_832 ;
} else {
V_841 = V_838 ;
V_770 = V_18 ;
}
} else if ( F_380 ( V_709 ) ) {
T_2 V_703 ;
struct V_710 * V_711 ;
V_711 = V_709 -> V_712 ;
if ( F_301 ( V_657 , V_190 , & V_703 ) )
return V_832 ;
if ( V_703 == V_705 ) {
switch ( V_190 ) {
case V_197 :
if ( F_389 ( V_657 ) -> V_86 & V_844 )
return V_831 ;
break;
case V_198 :
if ( F_390 ( V_657 ) -> V_86 & V_845 )
return V_831 ;
break;
default:
return F_384 ( - V_839 ) ;
}
}
if ( F_305 ( V_711 -> V_17 , V_703 , & V_770 ) )
return V_832 ;
V_841 = V_838 ;
} else {
struct V_710 * V_711 = V_709 -> V_712 ;
V_770 = V_711 -> V_17 ;
V_841 = V_838 ;
}
V_283 . type = V_714 ;
V_283 . V_288 . V_665 = & V_665 ;
V_283 . V_288 . V_665 -> V_781 = V_774 ;
V_283 . V_288 . V_665 -> V_190 = V_190 ;
if ( F_299 ( V_657 , & V_283 , & V_694 , 0 , NULL ) )
return V_832 ;
if ( V_786 )
if ( F_55 ( V_770 , V_657 -> V_783 ,
V_784 , V_841 , & V_283 ) )
return F_384 ( - V_839 ) ;
if ( V_787 ) {
T_2 V_775 ;
T_2 V_776 ;
if ( F_334 ( F_375 ( V_840 ) , V_774 , & V_775 ) )
return V_832 ;
if ( F_55 ( V_770 , V_775 ,
V_777 , V_846 , & V_283 ) )
return F_384 ( - V_839 ) ;
if ( F_318 ( V_694 , V_190 , & V_776 ) )
return V_832 ;
if ( F_55 ( V_770 , V_776 ,
V_779 , V_847 , & V_283 ) )
return F_384 ( - V_839 ) ;
}
return V_831 ;
}
static unsigned int F_391 ( void * V_834 ,
struct V_656 * V_657 ,
const struct V_835 * V_836 )
{
return F_386 ( V_657 , V_836 -> V_81 , V_197 ) ;
}
static unsigned int F_392 ( void * V_834 ,
struct V_656 * V_657 ,
const struct V_835 * V_836 )
{
return F_386 ( V_657 , V_836 -> V_81 , V_198 ) ;
}
static int F_393 ( struct V_708 * V_709 , struct V_656 * V_657 )
{
return F_368 ( V_709 , V_657 ) ;
}
static int F_394 ( struct V_20 * V_21 ,
struct V_848 * V_258 ,
T_4 V_31 )
{
struct V_849 * V_24 ;
T_2 V_17 ;
V_24 = F_15 ( sizeof( struct V_849 ) , V_15 ) ;
if ( ! V_24 )
return - V_27 ;
V_17 = F_18 ( V_21 ) ;
V_24 -> V_31 = V_31 ;
V_24 -> V_17 = V_17 ;
V_258 -> V_19 = V_24 ;
return 0 ;
}
static void F_395 ( struct V_848 * V_258 )
{
struct V_849 * V_24 = V_258 -> V_19 ;
V_258 -> V_19 = NULL ;
F_52 ( V_24 ) ;
}
static int F_396 ( struct V_850 * V_754 )
{
struct V_851 * V_852 ;
V_852 = F_15 ( sizeof( struct V_851 ) , V_15 ) ;
if ( ! V_852 )
return - V_27 ;
V_852 -> V_17 = V_30 ;
V_754 -> V_19 = V_852 ;
return 0 ;
}
static void F_397 ( struct V_850 * V_754 )
{
struct V_851 * V_852 = V_754 -> V_19 ;
V_754 -> V_19 = NULL ;
F_52 ( V_852 ) ;
}
static int F_398 ( struct V_848 * V_853 ,
T_2 V_268 )
{
struct V_849 * V_24 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
V_24 = V_853 -> V_19 ;
V_283 . type = V_854 ;
V_283 . V_288 . V_855 = V_853 -> V_856 ;
return F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_268 , & V_283 ) ;
}
static int F_399 ( struct V_850 * V_754 )
{
return F_396 ( V_754 ) ;
}
static void F_400 ( struct V_850 * V_754 )
{
F_397 ( V_754 ) ;
}
static int F_401 ( struct V_857 * V_858 )
{
struct V_849 * V_24 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
int V_61 ;
V_61 = F_394 ( V_11 , & V_858 -> V_859 , V_860 ) ;
if ( V_61 )
return V_61 ;
V_24 = V_858 -> V_859 . V_19 ;
V_283 . type = V_854 ;
V_283 . V_288 . V_855 = V_858 -> V_859 . V_856 ;
V_61 = F_55 ( V_17 , V_24 -> V_17 , V_860 ,
V_861 , & V_283 ) ;
if ( V_61 ) {
F_395 ( & V_858 -> V_859 ) ;
return V_61 ;
}
return 0 ;
}
static void F_402 ( struct V_857 * V_858 )
{
F_395 ( & V_858 -> V_859 ) ;
}
static int F_403 ( struct V_857 * V_858 , int V_862 )
{
struct V_849 * V_24 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
V_24 = V_858 -> V_859 . V_19 ;
V_283 . type = V_854 ;
V_283 . V_288 . V_855 = V_858 -> V_859 . V_856 ;
return F_55 ( V_17 , V_24 -> V_17 , V_860 ,
V_863 , & V_283 ) ;
}
static int F_404 ( struct V_857 * V_858 , int V_553 )
{
int V_605 ;
int V_268 ;
switch ( V_553 ) {
case V_864 :
case V_865 :
return F_123 ( V_11 , V_866 ) ;
case V_867 :
case V_868 :
V_268 = V_869 | V_863 ;
break;
case V_870 :
V_268 = V_871 ;
break;
case V_872 :
V_268 = V_873 ;
break;
default:
return 0 ;
}
V_605 = F_398 ( & V_858 -> V_859 , V_268 ) ;
return V_605 ;
}
static int F_405 ( struct V_857 * V_858 , struct V_850 * V_754 , int V_862 )
{
struct V_849 * V_24 ;
struct V_851 * V_852 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
int V_61 ;
V_24 = V_858 -> V_859 . V_19 ;
V_852 = V_754 -> V_19 ;
if ( V_852 -> V_17 == V_30 ) {
V_61 = F_112 ( V_17 , V_24 -> V_17 , V_874 ,
NULL , & V_852 -> V_17 ) ;
if ( V_61 )
return V_61 ;
}
V_283 . type = V_854 ;
V_283 . V_288 . V_855 = V_858 -> V_859 . V_856 ;
V_61 = F_55 ( V_17 , V_24 -> V_17 , V_860 ,
V_875 , & V_283 ) ;
if ( ! V_61 )
V_61 = F_55 ( V_17 , V_852 -> V_17 , V_874 ,
V_876 , & V_283 ) ;
if ( ! V_61 )
V_61 = F_55 ( V_852 -> V_17 , V_24 -> V_17 , V_860 ,
V_877 , & V_283 ) ;
return V_61 ;
}
static int F_406 ( struct V_857 * V_858 , struct V_850 * V_754 ,
struct V_20 * V_267 ,
long type , int V_171 )
{
struct V_849 * V_24 ;
struct V_851 * V_852 ;
struct V_282 V_283 ;
T_2 V_17 = F_18 ( V_267 ) ;
int V_61 ;
V_24 = V_858 -> V_859 . V_19 ;
V_852 = V_754 -> V_19 ;
V_283 . type = V_854 ;
V_283 . V_288 . V_855 = V_858 -> V_859 . V_856 ;
V_61 = F_55 ( V_17 , V_24 -> V_17 ,
V_860 , V_878 , & V_283 ) ;
if ( ! V_61 )
V_61 = F_55 ( V_17 , V_852 -> V_17 ,
V_874 , V_879 , & V_283 ) ;
return V_61 ;
}
static int F_407 ( struct V_880 * V_881 )
{
struct V_849 * V_24 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
int V_61 ;
V_61 = F_394 ( V_11 , & V_881 -> V_882 , V_883 ) ;
if ( V_61 )
return V_61 ;
V_24 = V_881 -> V_882 . V_19 ;
V_283 . type = V_854 ;
V_283 . V_288 . V_855 = V_881 -> V_882 . V_856 ;
V_61 = F_55 ( V_17 , V_24 -> V_17 , V_883 ,
V_884 , & V_283 ) ;
if ( V_61 ) {
F_395 ( & V_881 -> V_882 ) ;
return V_61 ;
}
return 0 ;
}
static void F_408 ( struct V_880 * V_881 )
{
F_395 ( & V_881 -> V_882 ) ;
}
static int F_409 ( struct V_880 * V_881 , int V_885 )
{
struct V_849 * V_24 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
V_24 = V_881 -> V_882 . V_19 ;
V_283 . type = V_854 ;
V_283 . V_288 . V_855 = V_881 -> V_882 . V_856 ;
return F_55 ( V_17 , V_24 -> V_17 , V_883 ,
V_886 , & V_283 ) ;
}
static int F_410 ( struct V_880 * V_881 , int V_553 )
{
int V_268 ;
int V_605 ;
switch ( V_553 ) {
case V_864 :
case V_887 :
return F_123 ( V_11 , V_866 ) ;
case V_867 :
case V_888 :
V_268 = V_889 | V_886 ;
break;
case V_870 :
V_268 = V_890 ;
break;
case V_891 :
case V_892 :
V_268 = V_893 ;
break;
case V_872 :
V_268 = V_894 ;
break;
default:
return 0 ;
}
V_605 = F_398 ( & V_881 -> V_882 , V_268 ) ;
return V_605 ;
}
static int F_411 ( struct V_880 * V_881 ,
char T_15 * V_895 , int V_885 )
{
T_2 V_268 ;
if ( V_885 & V_896 )
V_268 = V_897 ;
else
V_268 = V_897 | V_898 ;
return F_398 ( & V_881 -> V_882 , V_268 ) ;
}
static int F_412 ( struct V_899 * V_900 )
{
struct V_849 * V_24 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
int V_61 ;
V_61 = F_394 ( V_11 , & V_900 -> V_901 , V_902 ) ;
if ( V_61 )
return V_61 ;
V_24 = V_900 -> V_901 . V_19 ;
V_283 . type = V_854 ;
V_283 . V_288 . V_855 = V_900 -> V_901 . V_856 ;
V_61 = F_55 ( V_17 , V_24 -> V_17 , V_902 ,
V_903 , & V_283 ) ;
if ( V_61 ) {
F_395 ( & V_900 -> V_901 ) ;
return V_61 ;
}
return 0 ;
}
static void F_413 ( struct V_899 * V_900 )
{
F_395 ( & V_900 -> V_901 ) ;
}
static int F_414 ( struct V_899 * V_900 , int V_904 )
{
struct V_849 * V_24 ;
struct V_282 V_283 ;
T_2 V_17 = F_22 () ;
V_24 = V_900 -> V_901 . V_19 ;
V_283 . type = V_854 ;
V_283 . V_288 . V_855 = V_900 -> V_901 . V_856 ;
return F_55 ( V_17 , V_24 -> V_17 , V_902 ,
V_905 , & V_283 ) ;
}
static int F_415 ( struct V_899 * V_900 , int V_553 )
{
int V_605 ;
T_2 V_268 ;
switch ( V_553 ) {
case V_864 :
case V_906 :
return F_123 ( V_11 , V_866 ) ;
case V_907 :
case V_908 :
case V_909 :
V_268 = V_910 ;
break;
case V_911 :
case V_912 :
V_268 = V_913 ;
break;
case V_914 :
case V_915 :
V_268 = V_916 ;
break;
case V_872 :
V_268 = V_917 ;
break;
case V_870 :
V_268 = V_918 ;
break;
case V_867 :
case V_919 :
V_268 = V_910 | V_905 ;
break;
default:
return 0 ;
}
V_605 = F_398 ( & V_900 -> V_901 , V_268 ) ;
return V_605 ;
}
static int F_416 ( struct V_899 * V_900 ,
struct V_920 * V_921 , unsigned V_922 , int V_923 )
{
T_2 V_268 ;
if ( V_923 )
V_268 = V_913 | V_916 ;
else
V_268 = V_913 ;
return F_398 ( & V_900 -> V_901 , V_268 ) ;
}
static int F_417 ( struct V_848 * V_924 , short V_109 )
{
T_2 V_286 = 0 ;
V_286 = 0 ;
if ( V_109 & V_925 )
V_286 |= V_926 ;
if ( V_109 & V_927 )
V_286 |= V_928 ;
if ( V_286 == 0 )
return 0 ;
return F_398 ( V_924 , V_286 ) ;
}
static void F_418 ( struct V_848 * V_924 , T_2 * V_549 )
{
struct V_849 * V_24 = V_924 -> V_19 ;
* V_549 = V_24 -> V_17 ;
}
static void F_419 ( struct V_34 * V_34 , struct V_22 * V_22 )
{
if ( V_22 )
F_30 ( V_22 , V_34 ) ;
}
static int F_420 ( struct V_20 * V_148 ,
char * V_72 , char * * V_506 )
{
const struct V_13 * V_809 ;
T_2 V_17 ;
int error ;
unsigned V_95 ;
if ( V_11 != V_148 ) {
error = F_117 ( V_148 , V_929 ) ;
if ( error )
return error ;
}
F_19 () ;
V_809 = F_20 ( V_148 ) -> V_19 ;
if ( ! strcmp ( V_72 , L_50 ) )
V_17 = V_809 -> V_17 ;
else if ( ! strcmp ( V_72 , L_51 ) )
V_17 = V_809 -> V_16 ;
else if ( ! strcmp ( V_72 , L_52 ) )
V_17 = V_809 -> V_428 ;
else if ( ! strcmp ( V_72 , L_53 ) )
V_17 = V_809 -> V_305 ;
else if ( ! strcmp ( V_72 , L_54 ) )
V_17 = V_809 -> V_426 ;
else if ( ! strcmp ( V_72 , L_55 ) )
V_17 = V_809 -> V_427 ;
else
goto V_930;
F_21 () ;
if ( ! V_17 )
return 0 ;
error = F_70 ( V_17 , V_506 , & V_95 ) ;
if ( error )
return error ;
return V_95 ;
V_930:
F_21 () ;
return - V_97 ;
}
static int F_421 ( struct V_20 * V_148 ,
char * V_72 , void * V_506 , T_7 V_537 )
{
struct V_13 * V_14 ;
struct V_10 * V_133 ;
T_2 V_17 = 0 , V_436 ;
int error ;
char * V_1 = V_506 ;
if ( V_11 != V_148 ) {
return - V_424 ;
}
if ( ! strcmp ( V_72 , L_52 ) )
error = F_117 ( V_148 , V_931 ) ;
else if ( ! strcmp ( V_72 , L_53 ) )
error = F_117 ( V_148 , V_932 ) ;
else if ( ! strcmp ( V_72 , L_54 ) )
error = F_117 ( V_148 , V_933 ) ;
else if ( ! strcmp ( V_72 , L_55 ) )
error = F_117 ( V_148 , V_934 ) ;
else if ( ! strcmp ( V_72 , L_50 ) )
error = F_117 ( V_148 , V_935 ) ;
else
error = - V_97 ;
if ( error )
return error ;
if ( V_537 && V_1 [ 1 ] && V_1 [ 1 ] != '\n' ) {
if ( V_1 [ V_537 - 1 ] == '\n' ) {
V_1 [ V_537 - 1 ] = 0 ;
V_537 -- ;
}
error = F_233 ( V_506 , V_537 , & V_17 , V_15 ) ;
if ( error == - V_97 && ! strcmp ( V_72 , L_53 ) ) {
if ( ! F_230 ( V_539 ) ) {
struct V_540 * V_541 ;
T_7 V_542 ;
if ( V_1 [ V_537 - 1 ] == '\0' )
V_542 = V_537 - 1 ;
else
V_542 = V_537 ;
V_541 = F_234 ( V_11 -> V_543 , V_102 , V_544 ) ;
F_235 ( V_541 , L_56 ) ;
F_236 ( V_541 , V_506 , V_542 ) ;
F_237 ( V_541 ) ;
return error ;
}
error = F_238 ( V_506 , V_537 ,
& V_17 ) ;
}
if ( error )
return error ;
}
V_133 = F_422 () ;
if ( ! V_133 )
return - V_27 ;
V_14 = V_133 -> V_19 ;
if ( ! strcmp ( V_72 , L_52 ) ) {
V_14 -> V_428 = V_17 ;
} else if ( ! strcmp ( V_72 , L_53 ) ) {
V_14 -> V_305 = V_17 ;
} else if ( ! strcmp ( V_72 , L_54 ) ) {
error = F_134 ( V_17 , V_148 ) ;
if ( error )
goto V_936;
V_14 -> V_426 = V_17 ;
} else if ( ! strcmp ( V_72 , L_55 ) ) {
V_14 -> V_427 = V_17 ;
} else if ( ! strcmp ( V_72 , L_50 ) ) {
error = - V_97 ;
if ( V_17 == 0 )
goto V_936;
error = - V_423 ;
if ( ! F_423 () ) {
error = F_160 ( V_14 -> V_17 , V_17 ) ;
if ( error )
goto V_936;
}
error = F_55 ( V_14 -> V_17 , V_17 , V_271 ,
V_937 , NULL ) ;
if ( error )
goto V_936;
V_436 = F_157 ( V_148 ) ;
if ( V_436 != 0 ) {
error = F_55 ( V_436 , V_17 , V_271 ,
V_370 , NULL ) ;
if ( error )
goto V_936;
}
V_14 -> V_17 = V_17 ;
} else {
error = - V_97 ;
goto V_936;
}
F_424 ( V_133 ) ;
return V_537 ;
V_936:
F_425 ( V_133 ) ;
return error ;
}
static int F_426 ( const char * V_72 )
{
return ( strcmp ( V_72 , V_508 ) == 0 ) ;
}
static int F_427 ( T_2 V_549 , char * * V_490 , T_2 * V_938 )
{
return F_70 ( V_549 , V_490 , V_938 ) ;
}
static int F_428 ( const char * V_490 , T_2 V_938 , T_2 * V_549 )
{
return F_233 ( V_490 , V_938 , V_549 , V_15 ) ;
}
static void F_429 ( char * V_490 , T_2 V_938 )
{
F_52 ( V_490 ) ;
}
static void F_430 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
F_76 ( & V_24 -> V_28 ) ;
V_24 -> V_38 = V_939 ;
F_79 ( & V_24 -> V_28 ) ;
}
static int F_431 ( struct V_22 * V_22 , void * V_313 , T_2 V_504 )
{
return F_246 ( V_22 , V_508 , V_313 , V_504 , 0 ) ;
}
static int F_432 ( struct V_34 * V_34 , void * V_313 , T_2 V_504 )
{
return F_433 ( V_34 , V_82 , V_313 , V_504 , 0 ) ;
}
static int F_434 ( struct V_22 * V_22 , void * * V_313 , T_2 * V_504 )
{
int V_95 = 0 ;
V_95 = F_244 ( V_22 , V_508 ,
V_313 , true ) ;
if ( V_95 < 0 )
return V_95 ;
* V_504 = V_95 ;
return 0 ;
}
static int F_435 ( struct V_856 * V_940 , const struct V_10 * V_10 ,
unsigned long V_86 )
{
const struct V_13 * V_14 ;
struct V_941 * V_942 ;
V_942 = F_15 ( sizeof( struct V_941 ) , V_15 ) ;
if ( ! V_942 )
return - V_27 ;
V_14 = V_10 -> V_19 ;
if ( V_14 -> V_426 )
V_942 -> V_17 = V_14 -> V_426 ;
else
V_942 -> V_17 = V_14 -> V_17 ;
V_940 -> V_19 = V_942 ;
return 0 ;
}
static void F_436 ( struct V_856 * V_940 )
{
struct V_941 * V_942 = V_940 -> V_19 ;
V_940 -> V_19 = NULL ;
F_52 ( V_942 ) ;
}
static int F_437 ( T_16 V_943 ,
const struct V_10 * V_10 ,
unsigned V_258 )
{
struct V_856 * V_856 ;
struct V_941 * V_942 ;
T_2 V_17 ;
if ( V_258 == 0 )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_856 = F_438 ( V_943 ) ;
V_942 = V_856 -> V_19 ;
return F_55 ( V_17 , V_942 -> V_17 , V_314 , V_258 , NULL ) ;
}
static int F_439 ( struct V_856 * V_856 , char * * V_944 )
{
struct V_941 * V_942 = V_856 -> V_19 ;
char * V_94 = NULL ;
unsigned V_95 ;
int V_61 ;
V_61 = F_70 ( V_942 -> V_17 , & V_94 , & V_95 ) ;
if ( ! V_61 )
V_61 = V_95 ;
* V_944 = V_94 ;
return V_61 ;
}
static T_1 int F_440 ( void )
{
if ( ! F_441 ( L_57 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_59 ( V_945 L_58 ) ;
return 0 ;
}
F_59 ( V_945 L_59 ) ;
F_14 () ;
V_576 = ! ( V_946 & V_591 ) ;
V_25 = F_442 ( L_60 ,
sizeof( struct V_23 ) ,
0 , V_947 , NULL ) ;
V_52 = F_442 ( L_61 ,
sizeof( struct V_50 ) ,
0 , V_947 , NULL ) ;
F_443 () ;
F_444 ( V_948 , F_60 ( V_948 ) ) ;
if ( F_445 ( F_9 , V_9 ) )
F_16 ( L_62 ) ;
if ( V_3 )
F_59 ( V_949 L_63 ) ;
else
F_59 ( V_949 L_64 ) ;
return 0 ;
}
static void F_446 ( struct V_55 * V_56 , void * V_950 )
{
F_86 ( V_56 , NULL ) ;
}
void F_447 ( void )
{
F_59 ( V_949 L_65 ) ;
F_59 ( V_949 L_66 ) ;
F_448 ( F_446 , NULL ) ;
}
static int T_1 F_449 ( void )
{
int V_605 ;
if ( ! V_5 )
return 0 ;
F_59 ( V_949 L_67 ) ;
V_605 = F_450 ( V_951 , F_60 ( V_951 ) ) ;
if ( V_605 )
F_16 ( L_68 , V_605 ) ;
return 0 ;
}
static void F_451 ( void )
{
F_59 ( V_949 L_69 ) ;
F_452 ( V_951 , F_60 ( V_951 ) ) ;
}
int F_453 ( void )
{
if ( V_37 ) {
return - V_97 ;
}
if ( V_952 ) {
return - V_97 ;
}
F_59 ( V_945 L_70 ) ;
V_952 = 1 ;
V_5 = 0 ;
F_454 ( V_948 , F_60 ( V_948 ) ) ;
F_455 () ;
F_451 () ;
F_456 () ;
return 0 ;
}
