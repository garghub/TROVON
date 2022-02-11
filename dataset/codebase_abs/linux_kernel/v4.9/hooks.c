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
if ( ! ( V_75 -> V_76 & V_77 ) ) {
F_59 ( V_78 L_6
L_7 , V_56 -> V_79 , V_56 -> V_71 -> V_72 ) ;
V_61 = - V_80 ;
goto V_81;
}
V_61 = F_60 ( V_73 , V_75 , V_82 , NULL , 0 ) ;
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
if ( V_45 -> V_66 > F_61 ( V_84 ) )
F_59 ( V_85 L_11 ,
V_56 -> V_79 , V_56 -> V_71 -> V_72 ) ;
V_45 -> V_86 |= V_87 ;
if ( F_57 ( V_56 ) )
V_45 -> V_86 |= V_88 ;
V_61 = F_30 ( V_75 , V_73 ) ;
F_43 ( & V_45 -> V_48 ) ;
V_89:
if ( ! F_62 ( & V_45 -> V_57 ) ) {
struct V_23 * V_24 =
F_63 ( V_45 -> V_57 . V_90 ,
struct V_23 , V_29 ) ;
struct V_22 * V_22 = V_24 -> V_22 ;
F_44 ( & V_24 -> V_29 ) ;
F_45 ( & V_45 -> V_48 ) ;
V_22 = F_64 ( V_22 ) ;
if ( V_22 ) {
if ( ! F_65 ( V_22 ) )
F_53 ( V_22 ) ;
F_66 ( V_22 ) ;
}
F_43 ( & V_45 -> V_48 ) ;
goto V_89;
}
F_45 ( & V_45 -> V_48 ) ;
V_81:
return V_61 ;
}
static int F_67 ( const struct V_55 * V_56 ,
struct V_91 * V_92 )
{
int V_61 = 0 , V_93 ;
struct V_44 * V_45 = V_56 -> V_47 ;
char * V_94 = NULL ;
T_2 V_95 ;
char V_96 ;
F_68 ( V_92 ) ;
if ( ! ( V_45 -> V_86 & V_87 ) )
return - V_97 ;
if ( ! V_37 )
return - V_97 ;
F_69 ( V_98 >= ( 1 << V_99 ) ) ;
V_96 = V_45 -> V_86 & V_98 ;
for ( V_93 = 0 ; V_93 < V_99 ; V_93 ++ ) {
if ( V_96 & 0x01 )
V_92 -> V_100 ++ ;
V_96 >>= 1 ;
}
if ( V_45 -> V_86 & V_88 )
V_92 -> V_100 ++ ;
V_92 -> V_101 = F_70 ( V_92 -> V_100 , sizeof( char * ) , V_102 ) ;
if ( ! V_92 -> V_101 ) {
V_61 = - V_27 ;
goto V_103;
}
V_92 -> V_104 = F_70 ( V_92 -> V_100 , sizeof( int ) , V_102 ) ;
if ( ! V_92 -> V_104 ) {
V_61 = - V_27 ;
goto V_103;
}
V_93 = 0 ;
if ( V_45 -> V_86 & V_105 ) {
V_61 = F_71 ( V_45 -> V_17 , & V_94 , & V_95 ) ;
if ( V_61 )
goto V_103;
V_92 -> V_101 [ V_93 ] = V_94 ;
V_92 -> V_104 [ V_93 ++ ] = V_105 ;
}
if ( V_45 -> V_86 & V_106 ) {
V_61 = F_71 ( V_45 -> V_60 , & V_94 , & V_95 ) ;
if ( V_61 )
goto V_103;
V_92 -> V_101 [ V_93 ] = V_94 ;
V_92 -> V_104 [ V_93 ++ ] = V_106 ;
}
if ( V_45 -> V_86 & V_107 ) {
V_61 = F_71 ( V_45 -> V_58 , & V_94 , & V_95 ) ;
if ( V_61 )
goto V_103;
V_92 -> V_101 [ V_93 ] = V_94 ;
V_92 -> V_104 [ V_93 ++ ] = V_107 ;
}
if ( V_45 -> V_86 & V_108 ) {
struct V_34 * V_73 = V_45 -> V_56 -> V_74 ;
struct V_23 * V_24 = F_37 ( V_73 ) ;
V_61 = F_71 ( V_24 -> V_17 , & V_94 , & V_95 ) ;
if ( V_61 )
goto V_103;
V_92 -> V_101 [ V_93 ] = V_94 ;
V_92 -> V_104 [ V_93 ++ ] = V_108 ;
}
if ( V_45 -> V_86 & V_88 ) {
V_92 -> V_101 [ V_93 ] = NULL ;
V_92 -> V_104 [ V_93 ++ ] = V_88 ;
}
F_72 ( V_93 != V_92 -> V_100 ) ;
return 0 ;
V_103:
F_73 ( V_92 ) ;
return V_61 ;
}
static int F_74 ( struct V_44 * V_45 , char V_109 ,
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
static int F_75 ( struct V_55 * V_56 ,
struct V_91 * V_92 ,
unsigned long V_113 ,
unsigned long * V_114 )
{
const struct V_10 * V_10 = F_76 () ;
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
F_77 ( & V_45 -> V_28 ) ;
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
V_61 = F_78 ( V_120 [ V_93 ] , & V_17 , V_15 ) ;
if ( V_61 ) {
F_59 ( V_78 L_14
L_15 ,
V_120 [ V_93 ] , V_56 -> V_79 , V_72 , V_61 ) ;
goto V_81;
}
switch ( V_86 [ V_93 ] ) {
case V_105 :
V_116 = V_17 ;
if ( F_74 ( V_45 , V_105 , V_45 -> V_17 ,
V_116 ) )
goto V_124;
V_45 -> V_86 |= V_105 ;
break;
case V_106 :
V_117 = V_17 ;
if ( F_74 ( V_45 , V_106 , V_45 -> V_60 ,
V_117 ) )
goto V_124;
V_45 -> V_86 |= V_106 ;
break;
case V_108 :
V_118 = V_17 ;
if ( F_74 ( V_45 , V_108 , V_115 -> V_17 ,
V_118 ) )
goto V_124;
V_45 -> V_86 |= V_108 ;
break;
case V_107 :
V_119 = V_17 ;
if ( F_74 ( V_45 , V_107 , V_45 -> V_58 ,
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
V_61 = F_79 ( V_56 ) ;
if ( V_61 ) {
F_59 ( V_78
L_17 ,
V_127 , V_56 -> V_71 -> V_72 , V_61 ) ;
goto V_81;
}
}
if ( V_56 -> V_128 != & V_129 ) {
if ( V_117 || V_116 || V_118 ||
V_119 ) {
V_61 = - V_130 ;
goto V_81;
}
if ( V_45 -> V_66 == V_67 ) {
V_45 -> V_66 = V_131 ;
V_61 = F_80 ( F_22 () , F_22 () ,
V_32 , NULL ,
& V_45 -> V_60 ) ;
if ( V_61 )
goto V_81;
}
goto V_132;
}
if ( V_116 ) {
V_61 = F_54 ( V_116 , V_45 , V_10 ) ;
if ( V_61 )
goto V_81;
V_45 -> V_17 = V_116 ;
}
if ( V_113 & V_133 && ! V_117 ) {
V_45 -> V_66 = V_70 ;
* V_114 |= V_133 ;
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
V_45 -> V_66 = V_131 ;
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
V_132:
V_61 = F_58 ( V_56 ) ;
V_81:
F_81 ( & V_45 -> V_28 ) ;
return V_61 ;
V_124:
V_61 = - V_97 ;
F_59 ( V_78 L_20
L_21 , V_56 -> V_79 , V_72 ) ;
goto V_81;
}
static int F_82 ( const struct V_55 * V_134 ,
const struct V_55 * V_135 )
{
struct V_44 * V_136 = V_134 -> V_47 ;
struct V_44 * V_137 = V_135 -> V_47 ;
char V_138 = V_136 -> V_86 & V_98 ;
char V_139 = V_137 -> V_86 & V_98 ;
if ( V_138 != V_139 )
goto V_140;
if ( ( V_138 & V_105 ) && V_136 -> V_17 != V_137 -> V_17 )
goto V_140;
if ( ( V_138 & V_106 ) && V_136 -> V_60 != V_137 -> V_60 )
goto V_140;
if ( ( V_138 & V_107 ) && V_136 -> V_58 != V_137 -> V_58 )
goto V_140;
if ( V_138 & V_108 ) {
struct V_23 * V_141 = F_37 ( V_134 -> V_74 ) ;
struct V_23 * V_142 = F_37 ( V_135 -> V_74 ) ;
if ( V_141 -> V_17 != V_142 -> V_17 )
goto V_140;
}
return 0 ;
V_140:
F_59 ( V_78 L_22
L_23
L_24 , V_135 -> V_79 , V_135 -> V_71 -> V_72 ) ;
return - V_143 ;
}
static int F_83 ( const struct V_55 * V_134 ,
struct V_55 * V_135 )
{
const struct V_44 * V_144 = V_134 -> V_47 ;
struct V_44 * V_145 = V_135 -> V_47 ;
int V_146 = ( V_144 -> V_86 & V_105 ) ;
int V_147 = ( V_144 -> V_86 & V_106 ) ;
int V_148 = ( V_144 -> V_86 & V_108 ) ;
if ( ! V_37 )
return 0 ;
F_72 ( ! ( V_144 -> V_86 & V_87 ) ) ;
if ( V_145 -> V_86 & V_87 )
return F_82 ( V_134 , V_135 ) ;
F_77 ( & V_145 -> V_28 ) ;
V_145 -> V_86 = V_144 -> V_86 ;
V_145 -> V_17 = V_144 -> V_17 ;
V_145 -> V_58 = V_144 -> V_58 ;
V_145 -> V_66 = V_144 -> V_66 ;
if ( V_147 ) {
T_2 V_17 = V_144 -> V_60 ;
if ( ! V_146 )
V_145 -> V_17 = V_17 ;
if ( ! V_148 ) {
struct V_23 * V_149 = F_37 ( V_135 -> V_74 ) ;
V_149 -> V_17 = V_17 ;
}
V_145 -> V_60 = V_17 ;
}
if ( V_148 ) {
const struct V_23 * V_150 = F_37 ( V_134 -> V_74 ) ;
struct V_23 * V_149 = F_37 ( V_135 -> V_74 ) ;
V_149 -> V_17 = V_150 -> V_17 ;
}
F_58 ( V_135 ) ;
F_81 ( & V_145 -> V_28 ) ;
return 0 ;
}
static int F_84 ( char * V_151 ,
struct V_91 * V_92 )
{
char * V_152 ;
char * V_94 = NULL , * V_153 = NULL ;
char * V_154 = NULL , * V_155 = NULL ;
int V_61 , V_100 = 0 ;
V_92 -> V_100 = 0 ;
while ( ( V_152 = F_85 ( & V_151 , L_25 ) ) != NULL ) {
int V_156 ;
T_3 args [ V_157 ] ;
if ( ! * V_152 )
continue;
V_156 = F_86 ( V_152 , V_158 , args ) ;
switch ( V_156 ) {
case V_159 :
if ( V_94 || V_153 ) {
V_61 = - V_97 ;
F_59 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_160;
}
V_94 = F_87 ( & args [ 0 ] ) ;
if ( ! V_94 ) {
V_61 = - V_27 ;
goto V_160;
}
break;
case V_161 :
if ( V_154 ) {
V_61 = - V_97 ;
F_59 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_160;
}
V_154 = F_87 ( & args [ 0 ] ) ;
if ( ! V_154 ) {
V_61 = - V_27 ;
goto V_160;
}
break;
case V_162 :
if ( V_155 ) {
V_61 = - V_97 ;
F_59 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_160;
}
V_155 = F_87 ( & args [ 0 ] ) ;
if ( ! V_155 ) {
V_61 = - V_27 ;
goto V_160;
}
break;
case V_163 :
if ( V_94 || V_153 ) {
V_61 = - V_97 ;
F_59 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_160;
}
V_153 = F_87 ( & args [ 0 ] ) ;
if ( ! V_153 ) {
V_61 = - V_27 ;
goto V_160;
}
break;
case V_164 :
break;
default:
V_61 = - V_97 ;
F_59 ( V_78 L_26 ) ;
goto V_160;
}
}
V_61 = - V_27 ;
V_92 -> V_101 = F_70 ( V_99 , sizeof( char * ) , V_102 ) ;
if ( ! V_92 -> V_101 )
goto V_160;
V_92 -> V_104 = F_70 ( V_99 , sizeof( int ) , V_102 ) ;
if ( ! V_92 -> V_104 ) {
F_52 ( V_92 -> V_101 ) ;
goto V_160;
}
if ( V_154 ) {
V_92 -> V_101 [ V_100 ] = V_154 ;
V_92 -> V_104 [ V_100 ++ ] = V_105 ;
}
if ( V_94 ) {
V_92 -> V_101 [ V_100 ] = V_94 ;
V_92 -> V_104 [ V_100 ++ ] = V_106 ;
}
if ( V_155 ) {
V_92 -> V_101 [ V_100 ] = V_155 ;
V_92 -> V_104 [ V_100 ++ ] = V_108 ;
}
if ( V_153 ) {
V_92 -> V_101 [ V_100 ] = V_153 ;
V_92 -> V_104 [ V_100 ++ ] = V_107 ;
}
V_92 -> V_100 = V_100 ;
return 0 ;
V_160:
F_52 ( V_94 ) ;
F_52 ( V_153 ) ;
F_52 ( V_154 ) ;
F_52 ( V_155 ) ;
return V_61 ;
}
static int F_88 ( struct V_55 * V_56 , void * V_165 )
{
int V_61 = 0 ;
char * V_151 = V_165 ;
struct V_91 V_92 ;
F_68 ( & V_92 ) ;
if ( ! V_165 )
goto V_81;
F_72 ( V_56 -> V_71 -> V_122 & V_123 ) ;
V_61 = F_84 ( V_151 , & V_92 ) ;
if ( V_61 )
goto V_160;
V_81:
V_61 = F_75 ( V_56 , & V_92 , 0 , NULL ) ;
V_160:
F_73 ( & V_92 ) ;
return V_61 ;
}
static void F_89 ( struct V_166 * V_167 ,
struct V_91 * V_92 )
{
int V_93 ;
char * V_168 ;
for ( V_93 = 0 ; V_93 < V_92 -> V_100 ; V_93 ++ ) {
char * V_169 ;
if ( V_92 -> V_101 [ V_93 ] )
V_169 = strchr ( V_92 -> V_101 [ V_93 ] , ',' ) ;
else
V_169 = NULL ;
switch ( V_92 -> V_104 [ V_93 ] ) {
case V_106 :
V_168 = V_170 ;
break;
case V_105 :
V_168 = V_171 ;
break;
case V_108 :
V_168 = V_172 ;
break;
case V_107 :
V_168 = V_173 ;
break;
case V_88 :
F_90 ( V_167 , ',' ) ;
F_91 ( V_167 , V_174 ) ;
continue;
default:
F_92 () ;
return;
} ;
F_90 ( V_167 , ',' ) ;
F_91 ( V_167 , V_168 ) ;
if ( V_169 )
F_90 ( V_167 , '\"' ) ;
F_93 ( V_167 , V_92 -> V_101 [ V_93 ] , L_27 ) ;
if ( V_169 )
F_90 ( V_167 , '\"' ) ;
}
}
static int F_94 ( struct V_166 * V_167 , struct V_55 * V_56 )
{
struct V_91 V_92 ;
int V_61 ;
V_61 = F_67 ( V_56 , & V_92 ) ;
if ( V_61 ) {
if ( V_61 == - V_97 )
V_61 = 0 ;
return V_61 ;
}
F_89 ( V_167 , & V_92 ) ;
F_73 ( & V_92 ) ;
return V_61 ;
}
static inline T_4 F_95 ( T_5 V_175 )
{
switch ( V_175 & V_176 ) {
case V_177 :
return V_178 ;
case V_179 :
return V_180 ;
case V_181 :
return V_32 ;
case V_182 :
return V_183 ;
case V_184 :
return V_185 ;
case V_186 :
return V_187 ;
case V_188 :
return V_189 ;
}
return V_32 ;
}
static inline int F_96 ( int V_190 )
{
return ( V_190 == V_191 || V_190 == V_192 ) ;
}
static inline int F_97 ( int V_190 )
{
return ( V_190 == V_191 || V_190 == V_193 ) ;
}
static inline T_4 F_98 ( int V_194 , int type , int V_190 )
{
switch ( V_194 ) {
case V_195 :
switch ( type ) {
case V_196 :
case V_197 :
return V_198 ;
case V_199 :
return V_200 ;
}
break;
case V_201 :
case V_202 :
switch ( type ) {
case V_196 :
if ( F_96 ( V_190 ) )
return V_203 ;
else
return V_204 ;
case V_199 :
if ( F_97 ( V_190 ) )
return V_205 ;
else
return V_204 ;
case V_206 :
return V_207 ;
default:
return V_204 ;
}
break;
case V_208 :
switch ( V_190 ) {
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
case V_237 :
return V_238 ;
case V_239 :
return V_240 ;
default:
return V_241 ;
}
case V_242 :
return V_243 ;
case V_244 :
return V_245 ;
case V_246 :
return V_247 ;
}
return V_248 ;
}
static int F_99 ( struct V_34 * V_34 ,
T_4 V_249 ,
T_4 V_86 ,
T_2 * V_17 )
{
int V_61 ;
struct V_55 * V_56 = V_34 -> V_250 ;
char * V_251 , * V_252 ;
V_251 = ( char * ) F_100 ( V_15 ) ;
if ( ! V_251 )
return - V_27 ;
V_252 = F_101 ( V_34 , V_251 , V_253 ) ;
if ( F_102 ( V_252 ) )
V_61 = F_103 ( V_252 ) ;
else {
if ( V_86 & V_125 ) {
while ( V_252 [ 1 ] >= '0' && V_252 [ 1 ] <= '9' ) {
V_252 [ 1 ] = '/' ;
V_252 ++ ;
}
}
V_61 = F_104 ( V_56 -> V_71 -> V_72 , V_252 , V_249 , V_17 ) ;
}
F_105 ( ( unsigned long ) V_251 ) ;
return V_61 ;
}
static int F_30 ( struct V_22 * V_22 , struct V_34 * V_35 )
{
struct V_44 * V_45 = NULL ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 ;
struct V_34 * V_34 ;
#define F_106 255
char * V_94 = NULL ;
unsigned V_95 = 0 ;
int V_61 = 0 ;
if ( V_24 -> V_38 == V_39 )
goto V_81;
F_77 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_38 == V_39 )
goto V_254;
V_45 = V_22 -> V_46 -> V_47 ;
if ( ! ( V_45 -> V_86 & V_87 ) ) {
F_43 ( & V_45 -> V_48 ) ;
if ( F_62 ( & V_24 -> V_29 ) )
F_107 ( & V_24 -> V_29 , & V_45 -> V_57 ) ;
F_45 ( & V_45 -> V_48 ) ;
goto V_254;
}
switch ( V_45 -> V_66 ) {
case V_70 :
break;
case V_67 :
if ( ! ( V_22 -> V_76 & V_77 ) ) {
V_24 -> V_17 = V_45 -> V_58 ;
break;
}
if ( V_35 ) {
V_34 = F_108 ( V_35 ) ;
} else {
V_34 = F_109 ( V_22 ) ;
}
if ( ! V_34 ) {
goto V_254;
}
V_95 = F_106 ;
V_94 = F_110 ( V_95 + 1 , V_26 ) ;
if ( ! V_94 ) {
V_61 = - V_27 ;
F_111 ( V_34 ) ;
goto V_254;
}
V_94 [ V_95 ] = '\0' ;
V_61 = F_60 ( V_34 , V_22 , V_82 , V_94 , V_95 ) ;
if ( V_61 == - V_255 ) {
F_52 ( V_94 ) ;
V_61 = F_60 ( V_34 , V_22 , V_82 , NULL , 0 ) ;
if ( V_61 < 0 ) {
F_111 ( V_34 ) ;
goto V_254;
}
V_95 = V_61 ;
V_94 = F_110 ( V_95 + 1 , V_26 ) ;
if ( ! V_94 ) {
V_61 = - V_27 ;
F_111 ( V_34 ) ;
goto V_254;
}
V_94 [ V_95 ] = '\0' ;
V_61 = F_60 ( V_34 , V_22 , V_82 , V_94 , V_95 ) ;
}
F_111 ( V_34 ) ;
if ( V_61 < 0 ) {
if ( V_61 != - V_83 ) {
F_59 ( V_78 L_28
L_29 , V_127 ,
- V_61 , V_22 -> V_46 -> V_79 , V_22 -> V_256 ) ;
F_52 ( V_94 ) ;
goto V_254;
}
V_17 = V_45 -> V_58 ;
V_61 = 0 ;
} else {
V_61 = F_112 ( V_94 , V_61 , & V_17 ,
V_45 -> V_58 ,
V_26 ) ;
if ( V_61 ) {
char * V_257 = V_22 -> V_46 -> V_79 ;
unsigned long V_258 = V_22 -> V_256 ;
if ( V_61 == - V_97 ) {
if ( F_113 () )
F_59 ( V_259 L_30
L_31
L_32 , V_258 , V_257 , V_94 ) ;
} else {
F_59 ( V_78 L_33
L_34 ,
V_127 , V_94 , - V_61 , V_257 , V_258 ) ;
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
V_24 -> V_31 = F_95 ( V_22 -> V_260 ) ;
V_61 = F_80 ( V_24 -> F_18 , V_45 -> V_17 ,
V_24 -> V_31 , NULL , & V_17 ) ;
if ( V_61 )
goto V_254;
V_24 -> V_17 = V_17 ;
break;
case V_131 :
V_24 -> V_17 = V_45 -> V_60 ;
break;
default:
V_24 -> V_17 = V_45 -> V_17 ;
if ( ( V_45 -> V_86 & V_126 ) && ! F_114 ( V_22 -> V_260 ) ) {
if ( V_35 )
V_34 = F_108 ( V_35 ) ;
else
V_34 = F_109 ( V_22 ) ;
if ( ! V_34 )
goto V_254;
V_24 -> V_31 = F_95 ( V_22 -> V_260 ) ;
V_61 = F_99 ( V_34 , V_24 -> V_31 ,
V_45 -> V_86 , & V_17 ) ;
F_111 ( V_34 ) ;
if ( V_61 )
goto V_254;
V_24 -> V_17 = V_17 ;
}
break;
}
V_24 -> V_38 = V_39 ;
V_254:
F_81 ( & V_24 -> V_28 ) ;
V_81:
if ( V_24 -> V_31 == V_32 )
V_24 -> V_31 = F_95 ( V_22 -> V_260 ) ;
return V_61 ;
}
static inline T_2 F_115 ( int V_261 )
{
T_2 V_262 = 0 ;
switch ( V_261 ) {
case V_263 :
V_262 = V_264 ;
break;
case V_265 :
V_262 = V_266 ;
break;
case V_267 :
V_262 = V_268 ;
break;
default:
V_262 = V_269 ;
break;
}
return V_262 ;
}
static int F_116 ( const struct V_10 * V_270 ,
const struct V_10 * V_271 ,
T_2 V_272 )
{
T_2 V_273 = F_17 ( V_270 ) , V_274 = F_17 ( V_271 ) ;
return F_55 ( V_273 , V_274 , V_275 , V_272 , NULL ) ;
}
static int F_117 ( const struct V_20 * V_276 ,
const struct V_20 * V_277 ,
T_2 V_272 )
{
const struct V_13 * V_278 , * V_279 ;
T_2 V_280 , V_281 ;
F_19 () ;
V_278 = F_20 ( V_276 ) -> V_19 ; V_280 = V_278 -> V_17 ;
V_279 = F_20 ( V_277 ) -> V_19 ; V_281 = V_279 -> V_17 ;
F_21 () ;
return F_55 ( V_280 , V_281 , V_275 , V_272 , NULL ) ;
}
static int F_118 ( const struct V_20 * V_282 ,
T_2 V_272 )
{
T_2 V_17 , V_274 ;
V_17 = F_22 () ;
V_274 = F_18 ( V_282 ) ;
return F_55 ( V_17 , V_274 , V_275 , V_272 , NULL ) ;
}
static int F_119 ( const struct V_10 * V_10 ,
int V_283 , int V_284 , bool V_285 )
{
struct V_286 V_287 ;
struct V_288 V_289 ;
T_4 V_31 ;
T_2 V_17 = F_17 ( V_10 ) ;
T_2 V_290 = F_120 ( V_283 ) ;
int V_61 ;
V_287 . type = V_291 ;
V_287 . V_292 . V_283 = V_283 ;
switch ( F_121 ( V_283 ) ) {
case 0 :
V_31 = V_285 ? V_293 : V_294 ;
break;
case 1 :
V_31 = V_285 ? V_295 : V_296 ;
break;
default:
F_59 ( V_85
L_35 , V_283 ) ;
F_92 () ;
return - V_97 ;
}
V_61 = F_122 ( V_17 , V_17 , V_31 , V_290 , 0 , & V_289 ) ;
if ( V_284 == V_297 ) {
int V_298 = F_123 ( V_17 , V_17 , V_31 , V_290 , & V_289 , V_61 , & V_287 , 0 ) ;
if ( V_298 )
return V_298 ;
}
return V_61 ;
}
static int F_124 ( struct V_20 * V_282 ,
T_2 V_272 )
{
T_2 V_17 = F_18 ( V_282 ) ;
return F_55 ( V_17 , V_18 ,
V_299 , V_272 , NULL ) ;
}
static int F_125 ( const struct V_10 * V_10 ,
struct V_22 * V_22 ,
T_2 V_272 ,
struct V_286 * V_300 )
{
struct V_23 * V_24 ;
T_2 V_17 ;
F_126 ( V_10 ) ;
if ( F_127 ( F_65 ( V_22 ) ) )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
return F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_272 , V_300 ) ;
}
static inline int F_128 ( const struct V_10 * V_10 ,
struct V_34 * V_34 ,
T_2 V_290 )
{
struct V_22 * V_22 = F_36 ( V_34 ) ;
struct V_286 V_287 ;
V_287 . type = V_301 ;
V_287 . V_292 . V_34 = V_34 ;
F_28 ( V_22 , V_34 , true ) ;
return F_125 ( V_10 , V_22 , V_290 , & V_287 ) ;
}
static inline int F_129 ( const struct V_10 * V_10 ,
const struct V_252 * V_252 ,
T_2 V_290 )
{
struct V_22 * V_22 = F_36 ( V_252 -> V_34 ) ;
struct V_286 V_287 ;
V_287 . type = V_302 ;
V_287 . V_292 . V_252 = * V_252 ;
F_28 ( V_22 , V_252 -> V_34 , true ) ;
return F_125 ( V_10 , V_22 , V_290 , & V_287 ) ;
}
static inline int F_130 ( const struct V_10 * V_10 ,
struct V_49 * V_49 ,
T_2 V_290 )
{
struct V_286 V_287 ;
V_287 . type = V_303 ;
V_287 . V_292 . V_49 = V_49 ;
return F_125 ( V_10 , F_131 ( V_49 ) , V_290 , & V_287 ) ;
}
static int F_132 ( const struct V_10 * V_10 ,
struct V_49 * V_49 ,
T_2 V_290 )
{
struct V_50 * V_51 = V_49 -> V_54 ;
struct V_22 * V_22 = F_131 ( V_49 ) ;
struct V_286 V_287 ;
T_2 V_17 = F_17 ( V_10 ) ;
int V_61 ;
V_287 . type = V_303 ;
V_287 . V_292 . V_49 = V_49 ;
if ( V_17 != V_51 -> V_17 ) {
V_61 = F_55 ( V_17 , V_51 -> V_17 ,
V_304 ,
V_305 ,
& V_287 ) ;
if ( V_61 )
goto V_81;
}
V_61 = 0 ;
if ( V_290 )
V_61 = F_125 ( V_10 , V_22 , V_290 , & V_287 ) ;
V_81:
return V_61 ;
}
static int
F_133 ( const struct V_13 * V_14 ,
struct V_22 * V_306 ,
const struct V_307 * V_72 , T_4 V_249 ,
T_2 * V_308 )
{
const struct V_44 * V_45 = V_306 -> V_46 -> V_47 ;
if ( ( V_45 -> V_86 & V_87 ) &&
( V_45 -> V_66 == V_131 ) ) {
* V_308 = V_45 -> V_60 ;
} else if ( ( V_45 -> V_86 & V_88 ) &&
V_14 -> V_309 ) {
* V_308 = V_14 -> V_309 ;
} else {
const struct V_23 * V_310 = F_34 ( V_306 ) ;
return F_80 ( V_14 -> V_17 , V_310 -> V_17 , V_249 ,
V_72 , V_308 ) ;
}
return 0 ;
}
static int F_134 ( struct V_22 * V_306 ,
struct V_34 * V_34 ,
T_4 V_249 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_310 ;
struct V_44 * V_45 ;
T_2 V_17 , V_311 ;
struct V_286 V_287 ;
int V_61 ;
V_310 = F_34 ( V_306 ) ;
V_45 = V_306 -> V_46 -> V_47 ;
V_17 = V_14 -> V_17 ;
V_287 . type = V_301 ;
V_287 . V_292 . V_34 = V_34 ;
V_61 = F_55 ( V_17 , V_310 -> V_17 , V_185 ,
V_312 | V_313 ,
& V_287 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_133 ( F_23 () , V_306 ,
& V_34 -> V_314 , V_249 , & V_311 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_55 ( V_17 , V_311 , V_249 , V_315 , & V_287 ) ;
if ( V_61 )
return V_61 ;
return F_55 ( V_311 , V_45 -> V_17 ,
V_62 ,
V_65 , & V_287 ) ;
}
static int F_135 ( T_2 V_316 ,
struct V_20 * V_317 )
{
T_2 V_17 = F_18 ( V_317 ) ;
return F_55 ( V_17 , V_316 , V_318 , V_319 , NULL ) ;
}
static int F_136 ( struct V_22 * V_306 ,
struct V_34 * V_34 ,
int V_320 )
{
struct V_23 * V_310 , * V_24 ;
struct V_286 V_287 ;
T_2 V_17 = F_22 () ;
T_2 V_290 ;
int V_61 ;
V_310 = F_34 ( V_306 ) ;
V_24 = F_37 ( V_34 ) ;
V_287 . type = V_301 ;
V_287 . V_292 . V_34 = V_34 ;
V_290 = V_313 ;
V_290 |= ( V_320 ? V_321 : V_312 ) ;
V_61 = F_55 ( V_17 , V_310 -> V_17 , V_185 , V_290 , & V_287 ) ;
if ( V_61 )
return V_61 ;
switch ( V_320 ) {
case V_322 :
V_290 = V_323 ;
break;
case V_324 :
V_290 = V_325 ;
break;
case V_326 :
V_290 = V_327 ;
break;
default:
F_59 ( V_78 L_36 ,
V_127 , V_320 ) ;
return 0 ;
}
V_61 = F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_290 , & V_287 ) ;
return V_61 ;
}
static inline int F_137 ( struct V_22 * V_328 ,
struct V_34 * V_329 ,
struct V_22 * V_330 ,
struct V_34 * V_331 )
{
struct V_23 * V_332 , * V_333 , * V_334 , * V_335 ;
struct V_286 V_287 ;
T_2 V_17 = F_22 () ;
T_2 V_290 ;
int V_336 , V_337 ;
int V_61 ;
V_332 = F_34 ( V_328 ) ;
V_334 = F_37 ( V_329 ) ;
V_336 = F_138 ( V_329 ) ;
V_333 = F_34 ( V_330 ) ;
V_287 . type = V_301 ;
V_287 . V_292 . V_34 = V_329 ;
V_61 = F_55 ( V_17 , V_332 -> V_17 , V_185 ,
V_321 | V_313 , & V_287 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_55 ( V_17 , V_334 -> V_17 ,
V_334 -> V_31 , V_338 , & V_287 ) ;
if ( V_61 )
return V_61 ;
if ( V_336 && V_330 != V_328 ) {
V_61 = F_55 ( V_17 , V_334 -> V_17 ,
V_334 -> V_31 , V_339 , & V_287 ) ;
if ( V_61 )
return V_61 ;
}
V_287 . V_292 . V_34 = V_331 ;
V_290 = V_312 | V_313 ;
if ( F_139 ( V_331 ) )
V_290 |= V_321 ;
V_61 = F_55 ( V_17 , V_333 -> V_17 , V_185 , V_290 , & V_287 ) ;
if ( V_61 )
return V_61 ;
if ( F_139 ( V_331 ) ) {
V_335 = F_37 ( V_331 ) ;
V_337 = F_138 ( V_331 ) ;
V_61 = F_55 ( V_17 , V_335 -> V_17 ,
V_335 -> V_31 ,
( V_337 ? V_327 : V_325 ) , & V_287 ) ;
if ( V_61 )
return V_61 ;
}
return 0 ;
}
static int F_140 ( const struct V_10 * V_10 ,
struct V_55 * V_56 ,
T_2 V_272 ,
struct V_286 * V_287 )
{
struct V_44 * V_45 ;
T_2 V_17 = F_17 ( V_10 ) ;
V_45 = V_56 -> V_47 ;
return F_55 ( V_17 , V_45 -> V_17 , V_62 , V_272 , V_287 ) ;
}
static inline T_2 F_141 ( int V_175 , int V_340 )
{
T_2 V_290 = 0 ;
if ( ! F_142 ( V_175 ) ) {
if ( V_340 & V_341 )
V_290 |= V_342 ;
if ( V_340 & V_343 )
V_290 |= V_344 ;
if ( V_340 & V_345 )
V_290 |= V_346 ;
else if ( V_340 & V_347 )
V_290 |= V_348 ;
} else {
if ( V_340 & V_341 )
V_290 |= V_313 ;
if ( V_340 & V_347 )
V_290 |= V_349 ;
if ( V_340 & V_343 )
V_290 |= V_350 ;
}
return V_290 ;
}
static inline T_2 F_143 ( struct V_49 * V_49 )
{
T_2 V_290 = 0 ;
if ( V_49 -> V_351 & V_352 )
V_290 |= V_344 ;
if ( V_49 -> V_351 & V_353 ) {
if ( V_49 -> V_354 & V_355 )
V_290 |= V_346 ;
else
V_290 |= V_348 ;
}
if ( ! V_290 ) {
V_290 = V_356 ;
}
return V_290 ;
}
static inline T_2 F_144 ( struct V_49 * V_49 )
{
T_2 V_290 = F_143 ( V_49 ) ;
if ( V_357 )
V_290 |= V_358 ;
return V_290 ;
}
static int F_145 ( struct V_20 * V_359 )
{
T_2 V_360 = F_22 () ;
T_2 V_361 = F_18 ( V_359 ) ;
return F_55 ( V_360 , V_361 , V_362 ,
V_363 , NULL ) ;
}
static int F_146 ( struct V_20 * V_364 ,
struct V_20 * V_365 )
{
T_2 V_360 = F_22 () ;
T_2 V_366 = F_18 ( V_364 ) ;
T_2 V_367 = F_18 ( V_365 ) ;
int V_61 ;
if ( V_360 != V_366 ) {
V_61 = F_55 ( V_360 , V_366 , V_362 ,
V_368 , NULL ) ;
if ( V_61 )
return V_61 ;
}
return F_55 ( V_366 , V_367 , V_362 , V_369 ,
NULL ) ;
}
static int F_147 ( struct V_20 * V_364 ,
struct V_20 * V_365 )
{
T_2 V_366 = F_18 ( V_364 ) ;
T_2 V_367 = F_18 ( V_365 ) ;
return F_55 ( V_366 , V_367 , V_362 , V_370 ,
NULL ) ;
}
static int F_148 ( struct V_20 * V_364 ,
struct V_20 * V_365 ,
struct V_49 * V_49 )
{
T_2 V_17 = F_18 ( V_365 ) ;
struct V_50 * V_51 = V_49 -> V_54 ;
struct V_34 * V_34 = V_49 -> V_371 . V_34 ;
struct V_23 * V_24 ;
struct V_286 V_287 ;
int V_61 ;
V_287 . type = V_302 ;
V_287 . V_292 . V_252 = V_49 -> V_371 ;
if ( V_17 != V_51 -> V_17 ) {
V_61 = F_55 ( V_17 , V_51 -> V_17 ,
V_304 ,
V_305 ,
& V_287 ) ;
if ( V_61 )
return V_61 ;
}
if ( F_127 ( F_65 ( F_36 ( V_34 ) ) ) )
return 0 ;
V_24 = F_37 ( V_34 ) ;
return F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , F_143 ( V_49 ) ,
& V_287 ) ;
}
static int F_149 ( struct V_20 * V_372 ,
unsigned int V_175 )
{
if ( V_175 & V_373 ) {
T_2 V_17 = F_22 () ;
T_2 V_374 = F_18 ( V_372 ) ;
return F_55 ( V_17 , V_374 , V_32 , V_344 , NULL ) ;
}
return F_118 ( V_372 , V_375 ) ;
}
static int F_150 ( struct V_20 * V_376 )
{
return F_117 ( V_376 , V_11 , V_375 ) ;
}
static int F_151 ( struct V_20 * V_271 , T_6 * V_377 ,
T_6 * V_378 , T_6 * V_379 )
{
return F_118 ( V_271 , V_380 ) ;
}
static int F_152 ( struct V_10 * V_137 , const struct V_10 * V_136 ,
const T_6 * V_377 ,
const T_6 * V_378 ,
const T_6 * V_379 )
{
return F_116 ( V_136 , V_137 , V_381 ) ;
}
static int F_153 ( const struct V_10 * V_10 , struct V_382 * V_383 ,
int V_283 , int V_284 )
{
return F_119 ( V_10 , V_283 , V_284 , V_383 == & V_129 ) ;
}
static int F_154 ( int V_384 , int type , int V_385 , struct V_55 * V_56 )
{
const struct V_10 * V_10 = F_76 () ;
int V_61 = 0 ;
if ( ! V_56 )
return 0 ;
switch ( V_384 ) {
case V_386 :
case V_387 :
case V_388 :
case V_389 :
case V_390 :
V_61 = F_140 ( V_10 , V_56 , V_391 , NULL ) ;
break;
case V_392 :
case V_393 :
case V_394 :
V_61 = F_140 ( V_10 , V_56 , V_395 , NULL ) ;
break;
default:
V_61 = 0 ;
break;
}
return V_61 ;
}
static int F_155 ( struct V_34 * V_34 )
{
const struct V_10 * V_10 = F_76 () ;
return F_128 ( V_10 , V_34 , V_396 ) ;
}
static int F_156 ( int type )
{
int V_61 ;
switch ( type ) {
case V_397 :
case V_398 :
V_61 = F_124 ( V_11 , V_399 ) ;
break;
case V_400 :
case V_401 :
case V_402 :
V_61 = F_124 ( V_11 , V_403 ) ;
break;
case V_404 :
case V_405 :
case V_406 :
case V_407 :
case V_408 :
default:
V_61 = F_124 ( V_11 , V_409 ) ;
break;
}
return V_61 ;
}
static int F_157 ( struct V_410 * V_411 , long V_412 )
{
int V_61 , V_413 = 0 ;
V_61 = F_119 ( F_76 () , V_414 ,
V_415 , true ) ;
if ( V_61 == 0 )
V_413 = 1 ;
return V_413 ;
}
static T_2 F_158 ( struct V_20 * V_21 )
{
T_2 V_17 = 0 ;
struct V_20 * V_416 ;
F_19 () ;
V_416 = F_159 ( V_21 ) ;
if ( V_416 )
V_17 = F_18 ( V_416 ) ;
F_21 () ;
return V_17 ;
}
static int F_160 ( const struct V_417 * V_418 ,
const struct V_13 * V_419 ,
const struct V_13 * V_420 )
{
int V_421 = ( V_418 -> V_422 & V_423 ) ;
int V_424 = ! F_161 ( V_418 -> V_49 -> V_371 . V_425 ) ;
int V_61 ;
if ( ! V_421 && ! V_424 )
return 0 ;
if ( V_420 -> V_17 == V_419 -> V_17 )
return 0 ;
V_61 = F_162 ( V_419 -> V_17 , V_420 -> V_17 ) ;
if ( V_61 ) {
if ( V_421 )
return - V_426 ;
else
return - V_130 ;
}
return 0 ;
}
static int F_163 ( struct V_417 * V_418 )
{
const struct V_13 * V_419 ;
struct V_13 * V_420 ;
struct V_23 * V_24 ;
struct V_286 V_287 ;
struct V_22 * V_22 = F_131 ( V_418 -> V_49 ) ;
int V_61 ;
if ( V_418 -> V_427 )
return 0 ;
V_419 = F_23 () ;
V_420 = V_418 -> V_10 -> V_19 ;
V_24 = F_34 ( V_22 ) ;
V_420 -> V_17 = V_419 -> V_17 ;
V_420 -> V_16 = V_419 -> V_17 ;
V_420 -> V_309 = 0 ;
V_420 -> V_428 = 0 ;
V_420 -> V_429 = 0 ;
if ( V_419 -> V_430 ) {
V_420 -> V_17 = V_419 -> V_430 ;
V_420 -> V_430 = 0 ;
V_61 = F_160 ( V_418 , V_419 , V_420 ) ;
if ( V_61 )
return V_61 ;
} else {
V_61 = F_80 ( V_419 -> V_17 , V_24 -> V_17 ,
V_275 , NULL ,
& V_420 -> V_17 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_160 ( V_418 , V_419 , V_420 ) ;
if ( V_61 )
V_420 -> V_17 = V_419 -> V_17 ;
}
V_287 . type = V_303 ;
V_287 . V_292 . V_49 = V_418 -> V_49 ;
if ( V_420 -> V_17 == V_419 -> V_17 ) {
V_61 = F_55 ( V_419 -> V_17 , V_24 -> V_17 ,
V_32 , V_431 , & V_287 ) ;
if ( V_61 )
return V_61 ;
} else {
V_61 = F_55 ( V_419 -> V_17 , V_420 -> V_17 ,
V_275 , V_432 , & V_287 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_55 ( V_420 -> V_17 , V_24 -> V_17 ,
V_32 , V_433 , & V_287 ) ;
if ( V_61 )
return V_61 ;
if ( V_418 -> V_422 & V_434 ) {
V_61 = F_55 ( V_419 -> V_17 , V_420 -> V_17 ,
V_275 , V_435 ,
NULL ) ;
if ( V_61 )
return - V_426 ;
}
if ( V_418 -> V_422 &
( V_436 | V_437 ) ) {
T_2 V_438 = F_158 ( V_11 ) ;
if ( V_438 != 0 ) {
V_61 = F_55 ( V_438 , V_420 -> V_17 ,
V_275 ,
V_375 , NULL ) ;
if ( V_61 )
return - V_426 ;
}
}
V_418 -> V_439 |= V_440 ;
}
return 0 ;
}
static int F_164 ( struct V_417 * V_418 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_17 , V_16 ;
int V_441 = 0 ;
V_17 = V_14 -> V_17 ;
V_16 = V_14 -> V_16 ;
if ( V_16 != V_17 ) {
V_441 = F_55 ( V_16 , V_17 ,
V_275 ,
V_442 , NULL ) ;
}
return ! ! V_441 ;
}
static int F_165 ( const void * V_152 , struct V_49 * V_49 , unsigned V_443 )
{
return F_132 ( V_152 , V_49 , F_143 ( V_49 ) ) ? V_443 + 1 : 0 ;
}
static inline void F_166 ( const struct V_10 * V_10 ,
struct V_444 * V_445 )
{
struct V_49 * V_49 , * V_446 = NULL ;
struct V_447 * V_448 ;
int V_449 = 0 ;
unsigned V_450 ;
V_448 = F_167 () ;
if ( V_448 ) {
F_43 ( & V_448 -> V_451 ) ;
if ( ! F_62 ( & V_448 -> V_452 ) ) {
struct V_453 * V_454 ;
V_454 = F_168 ( & V_448 -> V_452 ,
struct V_453 , V_29 ) ;
V_49 = V_454 -> V_49 ;
if ( F_130 ( V_10 , V_49 , V_344 | V_348 ) )
V_449 = 1 ;
}
F_45 ( & V_448 -> V_451 ) ;
F_169 ( V_448 ) ;
}
if ( V_449 )
F_170 () ;
V_450 = F_171 ( V_445 , 0 , F_165 , V_10 ) ;
if ( ! V_450 )
return;
V_446 = F_172 ( & V_455 , V_456 , V_10 ) ;
if ( F_102 ( V_446 ) )
V_446 = NULL ;
do {
F_173 ( V_450 - 1 , V_446 , 0 ) ;
} while ( ( V_450 = F_171 ( V_445 , V_450 , F_165 , V_10 ) ) != 0 );
if ( V_446 )
F_174 ( V_446 ) ;
}
static void F_175 ( struct V_417 * V_418 )
{
struct V_13 * V_420 ;
struct V_457 * V_458 , * V_459 ;
int V_61 , V_93 ;
V_420 = V_418 -> V_10 -> V_19 ;
if ( V_420 -> V_17 == V_420 -> V_16 )
return;
F_166 ( V_418 -> V_10 , V_11 -> V_445 ) ;
V_11 -> V_460 = 0 ;
V_61 = F_55 ( V_420 -> V_16 , V_420 -> V_17 , V_275 ,
V_461 , NULL ) ;
if ( V_61 ) {
F_176 ( V_11 ) ;
for ( V_93 = 0 ; V_93 < V_462 ; V_93 ++ ) {
V_458 = V_11 -> signal -> V_458 + V_93 ;
V_459 = V_463 . signal -> V_458 + V_93 ;
V_458 -> V_464 = F_177 ( V_458 -> V_465 , V_459 -> V_464 ) ;
}
F_178 ( V_11 ) ;
F_179 ( V_11 , V_457 ( V_466 ) ) ;
}
}
static void F_180 ( struct V_417 * V_418 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_467 V_468 ;
T_2 V_16 , V_17 ;
int V_61 , V_93 ;
V_16 = V_14 -> V_16 ;
V_17 = V_14 -> V_17 ;
if ( V_17 == V_16 )
return;
V_61 = F_55 ( V_16 , V_17 , V_275 , V_469 , NULL ) ;
if ( V_61 ) {
memset ( & V_468 , 0 , sizeof V_468 ) ;
for ( V_93 = 0 ; V_93 < 3 ; V_93 ++ )
F_181 ( V_93 , & V_468 , NULL ) ;
F_182 ( & V_11 -> V_470 -> V_471 ) ;
if ( ! F_183 ( V_11 ) ) {
F_184 ( & V_11 -> V_472 ) ;
F_184 ( & V_11 -> signal -> V_473 ) ;
F_185 ( V_11 , 1 ) ;
F_186 ( & V_11 -> V_474 ) ;
F_187 () ;
}
F_188 ( & V_11 -> V_470 -> V_471 ) ;
}
F_189 ( & V_475 ) ;
F_190 ( V_11 , V_11 -> V_476 ) ;
F_191 ( & V_475 ) ;
}
static int F_192 ( struct V_55 * V_56 )
{
return F_49 ( V_56 ) ;
}
static void F_193 ( struct V_55 * V_56 )
{
F_51 ( V_56 ) ;
}
static inline int F_194 ( char * V_168 , int V_477 , char * V_478 , int V_479 )
{
if ( V_477 > V_479 )
return 0 ;
return ! memcmp ( V_168 , V_478 , V_477 ) ;
}
static inline int F_195 ( char * V_478 , int V_95 )
{
return ( F_194 ( V_170 , sizeof( V_170 ) - 1 , V_478 , V_95 ) ||
F_194 ( V_171 , sizeof( V_171 ) - 1 , V_478 , V_95 ) ||
F_194 ( V_173 , sizeof( V_173 ) - 1 , V_478 , V_95 ) ||
F_194 ( V_172 , sizeof( V_172 ) - 1 , V_478 , V_95 ) ||
F_194 ( V_174 , sizeof( V_174 ) - 1 , V_478 , V_95 ) ) ;
}
static inline void F_196 ( char * * V_365 , char * V_364 , int * V_480 , int V_95 )
{
if ( ! * V_480 ) {
* * V_365 = ',' ;
* V_365 += 1 ;
} else
* V_480 = 0 ;
memcpy ( * V_365 , V_364 , V_95 ) ;
* V_365 += V_95 ;
}
static inline void F_197 ( char * * V_365 , char * V_364 , int * V_480 ,
int V_95 )
{
int V_481 = 0 ;
if ( ! * V_480 ) {
* * V_365 = '|' ;
* V_365 += 1 ;
} else
* V_480 = 0 ;
while ( V_481 < V_95 ) {
if ( * V_364 != '"' ) {
* * V_365 = * V_364 ;
* V_365 += 1 ;
}
V_364 += 1 ;
V_481 += 1 ;
}
}
static int F_198 ( char * V_482 , char * V_483 )
{
int V_484 , V_51 , V_61 = 0 ;
char * V_485 , * V_486 , * V_487 ;
char * V_488 , * V_489 , * V_490 ;
int V_491 = 0 ;
V_486 = V_482 ;
V_488 = V_483 ;
V_490 = ( char * ) F_199 ( V_15 ) ;
if ( ! V_490 ) {
V_61 = - V_27 ;
goto V_81;
}
V_489 = V_490 ;
V_484 = V_51 = 1 ;
V_485 = V_487 = V_482 ;
do {
if ( * V_487 == '"' )
V_491 = ! V_491 ;
if ( ( * V_487 == ',' && V_491 == 0 ) ||
* V_487 == '\0' ) {
int V_95 = V_487 - V_486 ;
if ( F_195 ( V_486 , V_95 ) )
F_197 ( & V_488 , V_486 , & V_51 , V_95 ) ;
else
F_196 ( & V_490 , V_486 , & V_484 , V_95 ) ;
V_486 = V_487 + 1 ;
}
} while ( * V_487 ++ );
strcpy ( V_485 , V_489 ) ;
F_105 ( ( unsigned long ) V_489 ) ;
V_81:
return V_61 ;
}
static int F_200 ( struct V_55 * V_56 , void * V_165 )
{
int V_61 , V_93 , * V_86 ;
struct V_91 V_92 ;
char * V_492 , * * V_120 ;
struct V_44 * V_45 = V_56 -> V_47 ;
if ( ! ( V_45 -> V_86 & V_87 ) )
return 0 ;
if ( ! V_165 )
return 0 ;
if ( V_56 -> V_71 -> V_122 & V_123 )
return 0 ;
F_68 ( & V_92 ) ;
V_492 = F_201 () ;
if ( ! V_492 )
return - V_27 ;
V_61 = F_198 ( V_165 , V_492 ) ;
if ( V_61 )
goto V_493;
V_61 = F_84 ( V_492 , & V_92 ) ;
if ( V_61 )
goto V_493;
V_120 = V_92 . V_101 ;
V_86 = V_92 . V_104 ;
for ( V_93 = 0 ; V_93 < V_92 . V_100 ; V_93 ++ ) {
T_2 V_17 ;
if ( V_86 [ V_93 ] == V_88 )
continue;
V_61 = F_78 ( V_120 [ V_93 ] , & V_17 , V_15 ) ;
if ( V_61 ) {
F_59 ( V_78 L_14
L_15 ,
V_120 [ V_93 ] , V_56 -> V_79 , V_56 -> V_71 -> V_72 , V_61 ) ;
goto V_494;
}
V_61 = - V_97 ;
switch ( V_86 [ V_93 ] ) {
case V_105 :
if ( F_74 ( V_45 , V_105 , V_45 -> V_17 , V_17 ) )
goto V_495;
break;
case V_106 :
if ( F_74 ( V_45 , V_106 , V_45 -> V_60 , V_17 ) )
goto V_495;
break;
case V_108 : {
struct V_23 * V_115 ;
V_115 = F_37 ( V_56 -> V_74 ) ;
if ( F_74 ( V_45 , V_108 , V_115 -> V_17 , V_17 ) )
goto V_495;
break;
}
case V_107 :
if ( F_74 ( V_45 , V_107 , V_45 -> V_58 , V_17 ) )
goto V_495;
break;
default:
goto V_494;
}
}
V_61 = 0 ;
V_494:
F_73 ( & V_92 ) ;
V_493:
F_202 ( V_492 ) ;
return V_61 ;
V_495:
F_59 ( V_78 L_37
L_38 , V_56 -> V_79 ,
V_56 -> V_71 -> V_72 ) ;
goto V_494;
}
static int F_203 ( struct V_55 * V_56 , int V_86 , void * V_165 )
{
const struct V_10 * V_10 = F_76 () ;
struct V_286 V_287 ;
int V_61 ;
V_61 = F_88 ( V_56 , V_165 ) ;
if ( V_61 )
return V_61 ;
if ( V_86 & V_496 )
return 0 ;
V_287 . type = V_301 ;
V_287 . V_292 . V_34 = V_56 -> V_74 ;
return F_140 ( V_10 , V_56 , V_497 , & V_287 ) ;
}
static int F_204 ( struct V_34 * V_34 )
{
const struct V_10 * V_10 = F_76 () ;
struct V_286 V_287 ;
V_287 . type = V_301 ;
V_287 . V_292 . V_34 = V_34 -> V_250 -> V_74 ;
return F_140 ( V_10 , V_34 -> V_250 , V_498 , & V_287 ) ;
}
static int F_205 ( const char * V_499 ,
const struct V_252 * V_252 ,
const char * type ,
unsigned long V_86 ,
void * V_165 )
{
const struct V_10 * V_10 = F_76 () ;
if ( V_86 & V_500 )
return F_140 ( V_10 , V_252 -> V_34 -> V_250 ,
V_501 , NULL ) ;
else
return F_129 ( V_10 , V_252 , V_502 ) ;
}
static int F_206 ( struct V_503 * V_425 , int V_86 )
{
const struct V_10 * V_10 = F_76 () ;
return F_140 ( V_10 , V_425 -> V_504 ,
V_505 , NULL ) ;
}
static int F_207 ( struct V_22 * V_22 )
{
return F_24 ( V_22 ) ;
}
static void F_208 ( struct V_22 * V_22 )
{
F_41 ( V_22 ) ;
}
static int F_209 ( struct V_34 * V_34 , int V_175 ,
const struct V_307 * V_72 , void * * V_317 ,
T_2 * V_506 )
{
T_2 V_311 ;
int V_61 ;
V_61 = F_133 ( F_23 () ,
F_210 ( V_34 -> V_507 ) , V_72 ,
F_95 ( V_175 ) ,
& V_311 ) ;
if ( V_61 )
return V_61 ;
return F_71 ( V_311 , ( char * * ) V_317 , V_506 ) ;
}
static int F_211 ( struct V_34 * V_34 , int V_175 ,
struct V_307 * V_72 ,
const struct V_10 * V_136 ,
struct V_10 * V_137 )
{
T_2 V_311 ;
int V_61 ;
struct V_13 * V_14 ;
V_61 = F_133 ( V_136 -> V_19 ,
F_210 ( V_34 -> V_507 ) , V_72 ,
F_95 ( V_175 ) ,
& V_311 ) ;
if ( V_61 )
return V_61 ;
V_14 = V_137 -> V_19 ;
V_14 -> V_309 = V_311 ;
return 0 ;
}
static int F_212 ( struct V_22 * V_22 , struct V_22 * V_306 ,
const struct V_307 * V_307 ,
const char * * V_72 ,
void * * V_508 , T_7 * V_95 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_44 * V_45 ;
T_2 V_17 , V_311 , V_509 ;
int V_61 ;
char * V_94 ;
V_45 = V_306 -> V_46 -> V_47 ;
V_17 = V_14 -> V_17 ;
V_311 = V_14 -> V_309 ;
V_61 = F_133 ( F_23 () ,
V_306 , V_307 ,
F_95 ( V_22 -> V_260 ) ,
& V_311 ) ;
if ( V_61 )
return V_61 ;
if ( V_45 -> V_86 & V_87 ) {
struct V_23 * V_24 = V_22 -> V_33 ;
V_24 -> V_31 = F_95 ( V_22 -> V_260 ) ;
V_24 -> V_17 = V_311 ;
V_24 -> V_38 = V_39 ;
}
if ( ! V_37 || ! ( V_45 -> V_86 & V_88 ) )
return - V_80 ;
if ( V_72 )
* V_72 = V_510 ;
if ( V_508 && V_95 ) {
V_61 = F_213 ( V_311 , & V_94 , & V_509 ) ;
if ( V_61 )
return V_61 ;
* V_508 = V_94 ;
* V_95 = V_509 ;
}
return 0 ;
}
static int F_214 ( struct V_22 * V_306 , struct V_34 * V_34 , T_5 V_175 )
{
return F_134 ( V_306 , V_34 , V_32 ) ;
}
static int F_215 ( struct V_34 * V_329 , struct V_22 * V_306 , struct V_34 * V_331 )
{
return F_136 ( V_306 , V_329 , V_322 ) ;
}
static int F_216 ( struct V_22 * V_306 , struct V_34 * V_34 )
{
return F_136 ( V_306 , V_34 , V_324 ) ;
}
static int F_217 ( struct V_22 * V_306 , struct V_34 * V_34 , const char * V_72 )
{
return F_134 ( V_306 , V_34 , V_180 ) ;
}
static int F_218 ( struct V_22 * V_306 , struct V_34 * V_34 , T_5 V_340 )
{
return F_134 ( V_306 , V_34 , V_185 ) ;
}
static int F_219 ( struct V_22 * V_306 , struct V_34 * V_34 )
{
return F_136 ( V_306 , V_34 , V_326 ) ;
}
static int F_220 ( struct V_22 * V_306 , struct V_34 * V_34 , T_5 V_175 , T_8 V_257 )
{
return F_134 ( V_306 , V_34 , F_95 ( V_175 ) ) ;
}
static int F_221 ( struct V_22 * V_511 , struct V_34 * V_329 ,
struct V_22 * V_512 , struct V_34 * V_331 )
{
return F_137 ( V_511 , V_329 , V_512 , V_331 ) ;
}
static int F_222 ( struct V_34 * V_34 )
{
const struct V_10 * V_10 = F_76 () ;
return F_128 ( V_10 , V_34 , V_344 ) ;
}
static int F_223 ( struct V_34 * V_34 , struct V_22 * V_22 ,
bool V_41 )
{
const struct V_10 * V_10 = F_76 () ;
struct V_286 V_287 ;
struct V_23 * V_24 ;
T_2 V_17 ;
F_126 ( V_10 ) ;
V_287 . type = V_301 ;
V_287 . V_292 . V_34 = V_34 ;
V_17 = F_17 ( V_10 ) ;
V_24 = F_32 ( V_22 , V_41 ) ;
if ( F_102 ( V_24 ) )
return F_103 ( V_24 ) ;
return F_224 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_344 , & V_287 ,
V_41 ? V_513 : 0 ) ;
}
static T_9 int F_225 ( struct V_22 * V_22 ,
T_2 V_272 , T_2 V_514 , T_2 V_515 ,
int V_516 ,
unsigned V_86 )
{
struct V_286 V_287 ;
struct V_23 * V_24 = V_22 -> V_33 ;
int V_61 ;
V_287 . type = V_517 ;
V_287 . V_292 . V_22 = V_22 ;
V_61 = F_226 ( F_22 () , V_24 -> V_17 , V_24 -> V_31 , V_272 ,
V_514 , V_515 , V_516 , & V_287 , V_86 ) ;
if ( V_61 )
return V_61 ;
return 0 ;
}
static int F_227 ( struct V_22 * V_22 , int V_340 )
{
const struct V_10 * V_10 = F_76 () ;
T_2 V_272 ;
bool V_518 ;
unsigned V_86 = V_340 & V_513 ;
struct V_23 * V_24 ;
T_2 V_17 ;
struct V_288 V_289 ;
int V_61 , V_298 ;
T_2 V_514 , V_515 ;
V_518 = V_340 & V_519 ;
V_340 &= ( V_343 | V_347 | V_341 | V_345 ) ;
if ( ! V_340 )
return 0 ;
F_126 ( V_10 ) ;
if ( F_127 ( F_65 ( V_22 ) ) )
return 0 ;
V_272 = F_141 ( V_22 -> V_260 , V_340 ) ;
V_17 = F_17 ( V_10 ) ;
V_24 = F_32 ( V_22 , V_86 & V_513 ) ;
if ( F_102 ( V_24 ) )
return F_103 ( V_24 ) ;
V_61 = F_122 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_272 , 0 , & V_289 ) ;
V_514 = F_228 ( V_272 , & V_289 , V_61 ,
V_518 ? V_520 : 0 ,
& V_515 ) ;
if ( F_229 ( ! V_514 ) )
return V_61 ;
V_298 = F_225 ( V_22 , V_272 , V_514 , V_515 , V_61 , V_86 ) ;
if ( V_298 )
return V_298 ;
return V_61 ;
}
static int F_230 ( struct V_34 * V_34 , struct V_521 * V_521 )
{
const struct V_10 * V_10 = F_76 () ;
unsigned int V_522 = V_521 -> V_522 ;
T_10 V_290 = V_348 ;
if ( V_522 & V_523 ) {
V_522 &= ~ ( V_524 | V_525 | V_526 |
V_523 ) ;
if ( ! V_522 )
return 0 ;
}
if ( V_522 & ( V_526 | V_527 | V_528 |
V_529 | V_530 | V_531 ) )
return F_128 ( V_10 , V_34 , V_532 ) ;
if ( V_357 && ( V_522 & V_533 )
&& ! ( V_522 & V_534 ) )
V_290 |= V_358 ;
return F_128 ( V_10 , V_34 , V_290 ) ;
}
static int F_231 ( const struct V_252 * V_252 )
{
return F_129 ( F_76 () , V_252 , V_535 ) ;
}
static int F_232 ( struct V_34 * V_34 , const char * V_72 )
{
const struct V_10 * V_10 = F_76 () ;
if ( ! strncmp ( V_72 , V_536 ,
sizeof V_536 - 1 ) ) {
if ( ! strcmp ( V_72 , V_537 ) ) {
if ( ! F_233 ( V_538 ) )
return - V_426 ;
} else if ( ! F_233 ( V_414 ) ) {
return - V_426 ;
}
}
return F_128 ( V_10 , V_34 , V_532 ) ;
}
static int F_234 ( struct V_34 * V_34 , const char * V_72 ,
const void * V_508 , T_7 V_539 , int V_86 )
{
struct V_22 * V_22 = F_36 ( V_34 ) ;
struct V_23 * V_24 ;
struct V_44 * V_45 ;
struct V_286 V_287 ;
T_2 V_311 , V_17 = F_22 () ;
int V_61 = 0 ;
if ( strcmp ( V_72 , V_82 ) )
return F_232 ( V_34 , V_72 ) ;
V_45 = V_22 -> V_46 -> V_47 ;
if ( ! ( V_45 -> V_86 & V_88 ) )
return - V_80 ;
if ( ! F_235 ( V_22 ) )
return - V_426 ;
V_287 . type = V_301 ;
V_287 . V_292 . V_34 = V_34 ;
V_24 = F_37 ( V_34 ) ;
V_61 = F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 ,
V_540 , & V_287 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_236 ( V_508 , V_539 , & V_311 , V_15 ) ;
if ( V_61 == - V_97 ) {
if ( ! F_233 ( V_541 ) ) {
struct V_542 * V_543 ;
T_7 V_544 ;
const char * V_1 ;
if ( V_508 ) {
V_1 = V_508 ;
if ( V_1 [ V_539 - 1 ] == '\0' )
V_544 = V_539 - 1 ;
else
V_544 = V_539 ;
} else {
V_1 = L_39 ;
V_544 = 0 ;
}
V_543 = F_237 ( V_11 -> V_545 , V_102 , V_546 ) ;
F_238 ( V_543 , L_40 ) ;
F_239 ( V_543 , V_508 , V_544 ) ;
F_240 ( V_543 ) ;
return V_61 ;
}
V_61 = F_241 ( V_508 , V_539 , & V_311 ) ;
}
if ( V_61 )
return V_61 ;
V_61 = F_55 ( V_17 , V_311 , V_24 -> V_31 ,
V_547 , & V_287 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_242 ( V_24 -> V_17 , V_311 , V_17 ,
V_24 -> V_31 ) ;
if ( V_61 )
return V_61 ;
return F_55 ( V_311 ,
V_45 -> V_17 ,
V_62 ,
V_65 ,
& V_287 ) ;
}
static void F_243 ( struct V_34 * V_34 , const char * V_72 ,
const void * V_508 , T_7 V_539 ,
int V_86 )
{
struct V_22 * V_22 = F_36 ( V_34 ) ;
struct V_23 * V_24 ;
T_2 V_311 ;
int V_61 ;
if ( strcmp ( V_72 , V_82 ) ) {
return;
}
V_61 = F_241 ( V_508 , V_539 , & V_311 ) ;
if ( V_61 ) {
F_59 ( V_85 L_41
L_42 ,
V_22 -> V_46 -> V_79 , V_22 -> V_256 , - V_61 ) ;
return;
}
V_24 = F_37 ( V_34 ) ;
V_24 -> V_31 = F_95 ( V_22 -> V_260 ) ;
V_24 -> V_17 = V_311 ;
V_24 -> V_38 = V_39 ;
return;
}
static int F_244 ( struct V_34 * V_34 , const char * V_72 )
{
const struct V_10 * V_10 = F_76 () ;
return F_128 ( V_10 , V_34 , V_535 ) ;
}
static int F_245 ( struct V_34 * V_34 )
{
const struct V_10 * V_10 = F_76 () ;
return F_128 ( V_10 , V_34 , V_535 ) ;
}
static int F_246 ( struct V_34 * V_34 , const char * V_72 )
{
if ( strcmp ( V_72 , V_82 ) )
return F_232 ( V_34 , V_72 ) ;
return - V_130 ;
}
static int F_247 ( struct V_22 * V_22 , const char * V_72 , void * * V_251 , bool V_548 )
{
T_2 V_539 ;
int error ;
char * V_94 = NULL ;
struct V_23 * V_24 ;
if ( strcmp ( V_72 , V_510 ) )
return - V_80 ;
error = F_248 ( F_76 () , & V_129 , V_541 ,
V_415 ) ;
if ( ! error )
error = F_119 ( F_76 () , V_541 ,
V_415 , true ) ;
V_24 = F_34 ( V_22 ) ;
if ( ! error )
error = F_213 ( V_24 -> V_17 , & V_94 ,
& V_539 ) ;
else
error = F_71 ( V_24 -> V_17 , & V_94 , & V_539 ) ;
if ( error )
return error ;
error = V_539 ;
if ( V_548 ) {
* V_251 = V_94 ;
goto V_549;
}
F_52 ( V_94 ) ;
V_549:
return error ;
}
static int F_249 ( struct V_22 * V_22 , const char * V_72 ,
const void * V_508 , T_7 V_539 , int V_86 )
{
struct V_23 * V_24 = F_31 ( V_22 ) ;
T_2 V_311 ;
int V_61 ;
if ( strcmp ( V_72 , V_510 ) )
return - V_80 ;
if ( ! V_508 || ! V_539 )
return - V_130 ;
V_61 = F_236 ( V_508 , V_539 , & V_311 , V_15 ) ;
if ( V_61 )
return V_61 ;
V_24 -> V_31 = F_95 ( V_22 -> V_260 ) ;
V_24 -> V_17 = V_311 ;
V_24 -> V_38 = V_39 ;
return 0 ;
}
static int F_250 ( struct V_22 * V_22 , char * V_251 , T_7 V_550 )
{
const int V_95 = sizeof( V_82 ) ;
if ( V_251 && V_95 <= V_550 )
memcpy ( V_251 , V_82 , V_95 ) ;
return V_95 ;
}
static void F_251 ( struct V_22 * V_22 , T_2 * V_551 )
{
struct V_23 * V_24 = F_31 ( V_22 ) ;
* V_551 = V_24 -> V_17 ;
}
static int F_252 ( struct V_34 * V_552 , struct V_10 * * V_137 )
{
T_2 V_17 ;
struct V_13 * V_14 ;
struct V_10 * V_553 = * V_137 ;
if ( V_553 == NULL ) {
V_553 = F_253 () ;
if ( ! V_553 )
return - V_27 ;
}
V_14 = V_553 -> V_19 ;
F_251 ( F_210 ( V_552 ) , & V_17 ) ;
V_14 -> V_309 = V_17 ;
* V_137 = V_553 ;
return 0 ;
}
static int F_254 ( const char * V_72 )
{
if ( strcmp ( V_72 , V_82 ) == 0 )
return 1 ;
return - V_80 ;
}
static int F_255 ( struct V_49 * V_49 , int V_340 )
{
const struct V_10 * V_10 = F_76 () ;
struct V_22 * V_22 = F_131 ( V_49 ) ;
if ( ( V_49 -> V_354 & V_355 ) && ( V_340 & V_347 ) )
V_340 |= V_345 ;
return F_132 ( V_10 , V_49 ,
F_141 ( V_22 -> V_260 , V_340 ) ) ;
}
static int F_256 ( struct V_49 * V_49 , int V_340 )
{
struct V_22 * V_22 = F_131 ( V_49 ) ;
struct V_50 * V_51 = V_49 -> V_54 ;
struct V_23 * V_24 ;
T_2 V_17 = F_22 () ;
if ( ! V_340 )
return 0 ;
V_24 = F_34 ( V_22 ) ;
if ( V_17 == V_51 -> V_17 && V_51 -> V_554 == V_24 -> V_17 &&
V_51 -> V_555 == F_257 () )
return 0 ;
return F_255 ( V_49 , V_340 ) ;
}
static int F_258 ( struct V_49 * V_49 )
{
return F_47 ( V_49 ) ;
}
static void F_259 ( struct V_49 * V_49 )
{
F_48 ( V_49 ) ;
}
static int F_260 ( const struct V_10 * V_10 , struct V_49 * V_49 ,
T_2 V_556 , T_4 V_557 )
{
struct V_286 V_287 ;
struct V_50 * V_51 = V_49 -> V_54 ;
struct V_22 * V_22 = F_131 ( V_49 ) ;
struct V_23 * V_24 ;
struct V_558 V_559 ;
T_2 V_560 = F_17 ( V_10 ) ;
int V_61 ;
T_11 V_561 = V_557 >> 8 ;
T_11 V_562 = V_557 & 0xff ;
V_287 . type = V_563 ;
V_287 . V_292 . V_564 = & V_559 ;
V_287 . V_292 . V_564 -> V_557 = V_557 ;
V_287 . V_292 . V_564 -> V_252 = V_49 -> V_371 ;
if ( V_560 != V_51 -> V_17 ) {
V_61 = F_55 ( V_560 , V_51 -> V_17 ,
V_304 ,
V_305 ,
& V_287 ) ;
if ( V_61 )
goto V_81;
}
if ( F_127 ( F_65 ( V_22 ) ) )
return 0 ;
V_24 = F_34 ( V_22 ) ;
V_61 = F_261 ( V_560 , V_24 -> V_17 , V_24 -> V_31 ,
V_556 , V_561 , V_562 , & V_287 ) ;
V_81:
return V_61 ;
}
static int F_262 ( struct V_49 * V_49 , unsigned int V_557 ,
unsigned long V_565 )
{
const struct V_10 * V_10 = F_76 () ;
int error = 0 ;
switch ( V_557 ) {
case V_566 :
case V_567 :
case V_568 :
case V_569 :
case V_570 :
error = F_132 ( V_10 , V_49 , V_535 ) ;
break;
case V_571 :
case V_572 :
error = F_132 ( V_10 , V_49 , V_532 ) ;
break;
case V_573 :
case V_574 :
error = F_132 ( V_10 , V_49 , 0 ) ;
break;
case V_575 :
case V_576 :
error = F_119 ( V_10 , V_577 ,
V_297 , true ) ;
break;
default:
error = F_260 ( V_10 , V_49 , V_356 , ( T_4 ) V_557 ) ;
}
return error ;
}
static int F_263 ( struct V_49 * V_49 , unsigned long V_578 , int V_579 )
{
const struct V_10 * V_10 = F_76 () ;
int V_61 = 0 ;
if ( V_580 &&
( V_578 & V_581 ) && ( ! V_49 || F_65 ( F_131 ( V_49 ) ) ||
( ! V_579 && ( V_578 & V_582 ) ) ) ) {
V_61 = F_116 ( V_10 , V_10 , V_583 ) ;
if ( V_61 )
goto error;
}
if ( V_49 ) {
T_2 V_290 = V_344 ;
if ( V_579 && ( V_578 & V_582 ) )
V_290 |= V_348 ;
if ( V_578 & V_581 )
V_290 |= V_342 ;
return F_132 ( V_10 , V_49 , V_290 ) ;
}
error:
return V_61 ;
}
static int F_264 ( unsigned long V_584 )
{
int V_61 = 0 ;
if ( V_584 < V_585 ) {
T_2 V_17 = F_22 () ;
V_61 = F_55 ( V_17 , V_17 , V_586 ,
V_587 , NULL ) ;
}
return V_61 ;
}
static int F_265 ( struct V_49 * V_49 , unsigned long V_588 ,
unsigned long V_578 , unsigned long V_86 )
{
if ( V_589 )
V_578 = V_588 ;
return F_263 ( V_49 , V_578 ,
( V_86 & V_590 ) == V_591 ) ;
}
static int F_266 ( struct V_592 * V_593 ,
unsigned long V_588 ,
unsigned long V_578 )
{
const struct V_10 * V_10 = F_76 () ;
if ( V_589 )
V_578 = V_588 ;
if ( V_580 &&
( V_578 & V_581 ) && ! ( V_593 -> V_594 & V_595 ) ) {
int V_61 = 0 ;
if ( V_593 -> V_596 >= V_593 -> V_597 -> V_598 &&
V_593 -> V_599 <= V_593 -> V_597 -> V_600 ) {
V_61 = F_116 ( V_10 , V_10 , V_601 ) ;
} else if ( ! V_593 -> V_602 &&
( ( V_593 -> V_596 <= V_593 -> V_597 -> V_603 &&
V_593 -> V_599 >= V_593 -> V_597 -> V_603 ) ||
F_267 ( V_593 ) ) ) {
V_61 = F_118 ( V_11 , V_604 ) ;
} else if ( V_593 -> V_602 && V_593 -> V_605 ) {
V_61 = F_132 ( V_10 , V_593 -> V_602 , V_606 ) ;
}
if ( V_61 )
return V_61 ;
}
return F_263 ( V_593 -> V_602 , V_578 , V_593 -> V_594 & V_607 ) ;
}
static int F_268 ( struct V_49 * V_49 , unsigned int V_557 )
{
const struct V_10 * V_10 = F_76 () ;
return F_132 ( V_10 , V_49 , V_608 ) ;
}
static int F_269 ( struct V_49 * V_49 , unsigned int V_557 ,
unsigned long V_565 )
{
const struct V_10 * V_10 = F_76 () ;
int V_609 = 0 ;
switch ( V_557 ) {
case V_610 :
if ( ( V_49 -> V_354 & V_355 ) && ! ( V_565 & V_355 ) ) {
V_609 = F_132 ( V_10 , V_49 , V_348 ) ;
break;
}
case V_611 :
case V_612 :
case V_613 :
case V_614 :
case V_615 :
case V_616 :
V_609 = F_132 ( V_10 , V_49 , 0 ) ;
break;
case V_617 :
case V_618 :
case V_619 :
case V_620 :
case V_621 :
case V_622 :
#if V_623 == 32
case V_624 :
case V_625 :
case V_626 :
#endif
V_609 = F_132 ( V_10 , V_49 , V_608 ) ;
break;
}
return V_609 ;
}
static void F_270 ( struct V_49 * V_49 )
{
struct V_50 * V_51 ;
V_51 = V_49 -> V_54 ;
V_51 -> V_53 = F_22 () ;
}
static int F_271 ( struct V_20 * V_282 ,
struct V_627 * V_628 , int V_629 )
{
struct V_49 * V_49 ;
T_2 V_17 = F_18 ( V_282 ) ;
T_2 V_262 ;
struct V_50 * V_51 ;
V_49 = F_39 ( V_628 , struct V_49 , V_630 ) ;
V_51 = V_49 -> V_54 ;
if ( ! V_629 )
V_262 = F_115 ( V_631 ) ;
else
V_262 = F_115 ( V_629 ) ;
return F_55 ( V_51 -> V_53 , V_17 ,
V_275 , V_262 , NULL ) ;
}
static int F_272 ( struct V_49 * V_49 )
{
const struct V_10 * V_10 = F_76 () ;
return F_132 ( V_10 , V_49 , F_143 ( V_49 ) ) ;
}
static int F_273 ( struct V_49 * V_49 , const struct V_10 * V_10 )
{
struct V_50 * V_51 ;
struct V_23 * V_24 ;
V_51 = V_49 -> V_54 ;
V_24 = F_34 ( F_131 ( V_49 ) ) ;
V_51 -> V_554 = V_24 -> V_17 ;
V_51 -> V_555 = F_257 () ;
return F_130 ( V_10 , V_49 , F_144 ( V_49 ) ) ;
}
static int F_274 ( unsigned long V_632 )
{
return F_118 ( V_11 , V_633 ) ;
}
static int F_275 ( struct V_10 * V_10 , T_12 V_634 )
{
struct V_13 * V_14 ;
V_14 = F_15 ( sizeof( struct V_13 ) , V_634 ) ;
if ( ! V_14 )
return - V_27 ;
V_10 -> V_19 = V_14 ;
return 0 ;
}
static void F_276 ( struct V_10 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_19 ;
F_72 ( V_10 -> V_19 && ( unsigned long ) V_10 -> V_19 < V_253 ) ;
V_10 -> V_19 = ( void * ) 0x7UL ;
F_52 ( V_14 ) ;
}
static int F_277 ( struct V_10 * V_137 , const struct V_10 * V_136 ,
T_12 V_634 )
{
const struct V_13 * V_419 ;
struct V_13 * V_14 ;
V_419 = V_136 -> V_19 ;
V_14 = F_278 ( V_419 , sizeof( struct V_13 ) , V_634 ) ;
if ( ! V_14 )
return - V_27 ;
V_137 -> V_19 = V_14 ;
return 0 ;
}
static void F_279 ( struct V_10 * V_137 , const struct V_10 * V_136 )
{
const struct V_13 * V_419 = V_136 -> V_19 ;
struct V_13 * V_14 = V_137 -> V_19 ;
* V_14 = * V_419 ;
}
static int F_280 ( struct V_10 * V_137 , T_2 V_551 )
{
struct V_13 * V_14 = V_137 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_635 ;
V_635 = F_55 ( V_17 , V_551 ,
V_636 ,
V_637 ,
NULL ) ;
if ( V_635 == 0 ) {
V_14 -> V_17 = V_551 ;
V_14 -> V_309 = 0 ;
V_14 -> V_428 = 0 ;
V_14 -> V_429 = 0 ;
}
return V_635 ;
}
static int F_281 ( struct V_10 * V_137 , struct V_22 * V_22 )
{
struct V_23 * V_24 = F_34 ( V_22 ) ;
struct V_13 * V_14 = V_137 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_635 ;
V_635 = F_55 ( V_17 , V_24 -> V_17 ,
V_636 ,
V_638 ,
NULL ) ;
if ( V_635 == 0 )
V_14 -> V_309 = V_24 -> V_17 ;
return V_635 ;
}
static int F_282 ( char * V_639 )
{
T_2 V_17 ;
struct V_286 V_287 ;
V_17 = F_18 ( V_11 ) ;
V_287 . type = V_640 ;
V_287 . V_292 . V_639 = V_639 ;
return F_55 ( V_17 , V_18 , V_299 ,
V_641 , & V_287 ) ;
}
static int F_283 ( struct V_49 * V_49 )
{
struct V_286 V_287 ;
struct V_23 * V_24 ;
struct V_50 * V_51 ;
T_2 V_17 = F_22 () ;
int V_61 ;
if ( V_49 == NULL )
return F_55 ( V_17 , V_17 , V_299 ,
V_642 , NULL ) ;
V_287 . type = V_303 ;
V_287 . V_292 . V_49 = V_49 ;
V_51 = V_49 -> V_54 ;
if ( V_17 != V_51 -> V_17 ) {
V_61 = F_55 ( V_17 , V_51 -> V_17 , V_304 , V_305 , & V_287 ) ;
if ( V_61 )
return V_61 ;
}
V_24 = F_34 ( F_131 ( V_49 ) ) ;
return F_55 ( V_17 , V_24 -> V_17 , V_299 ,
V_642 , & V_287 ) ;
}
static int F_284 ( struct V_49 * V_49 ,
enum V_643 V_385 )
{
int V_61 = 0 ;
switch ( V_385 ) {
case V_644 :
V_61 = F_283 ( V_49 ) ;
break;
default:
break;
}
return V_61 ;
}
static int F_285 ( struct V_20 * V_152 , T_13 V_645 )
{
return F_118 ( V_152 , V_646 ) ;
}
static int F_286 ( struct V_20 * V_152 )
{
return F_118 ( V_152 , V_647 ) ;
}
static int F_287 ( struct V_20 * V_152 )
{
return F_118 ( V_152 , V_648 ) ;
}
static void F_288 ( struct V_20 * V_152 , T_2 * V_551 )
{
* V_551 = F_18 ( V_152 ) ;
}
static int F_289 ( struct V_20 * V_152 , int V_649 )
{
return F_118 ( V_152 , V_650 ) ;
}
static int F_290 ( struct V_20 * V_152 , int V_651 )
{
return F_118 ( V_152 , V_650 ) ;
}
static int F_291 ( struct V_20 * V_152 )
{
return F_118 ( V_152 , V_652 ) ;
}
static int F_292 ( struct V_20 * V_152 , unsigned int V_653 ,
struct V_457 * V_654 )
{
struct V_457 * V_655 = V_152 -> signal -> V_458 + V_653 ;
if ( V_655 -> V_465 != V_654 -> V_465 )
return F_118 ( V_152 , V_656 ) ;
return 0 ;
}
static int F_293 ( struct V_20 * V_152 )
{
return F_118 ( V_152 , V_650 ) ;
}
static int F_294 ( struct V_20 * V_152 )
{
return F_118 ( V_152 , V_652 ) ;
}
static int F_295 ( struct V_20 * V_152 )
{
return F_118 ( V_152 , V_650 ) ;
}
static int F_296 ( struct V_20 * V_152 , struct V_657 * V_658 ,
int V_261 , T_2 V_551 )
{
T_2 V_262 ;
int V_61 ;
if ( ! V_261 )
V_262 = V_659 ;
else
V_262 = F_115 ( V_261 ) ;
if ( V_551 )
V_61 = F_55 ( V_551 , F_18 ( V_152 ) ,
V_275 , V_262 , NULL ) ;
else
V_61 = F_118 ( V_152 , V_262 ) ;
return V_61 ;
}
static int F_297 ( struct V_20 * V_152 )
{
return F_117 ( V_152 , V_11 , V_264 ) ;
}
static void F_298 ( struct V_20 * V_152 ,
struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 = F_18 ( V_152 ) ;
V_24 -> V_17 = V_17 ;
V_24 -> V_38 = V_39 ;
}
static int F_299 ( struct V_660 * V_661 ,
struct V_286 * V_287 , T_11 * V_662 )
{
int V_663 , V_664 , V_635 = - V_97 ;
struct V_665 V_666 , * V_667 ;
V_663 = F_300 ( V_661 ) ;
V_667 = F_301 ( V_661 , V_663 , sizeof( V_666 ) , & V_666 ) ;
if ( V_667 == NULL )
goto V_81;
V_664 = V_667 -> V_668 * 4 ;
if ( V_664 < sizeof( V_666 ) )
goto V_81;
V_287 -> V_292 . V_669 -> V_670 . V_671 = V_667 -> V_671 ;
V_287 -> V_292 . V_669 -> V_670 . V_672 = V_667 -> V_672 ;
V_635 = 0 ;
if ( V_662 )
* V_662 = V_667 -> V_190 ;
switch ( V_667 -> V_190 ) {
case V_192 : {
struct V_673 V_674 , * V_675 ;
if ( F_302 ( V_667 -> V_676 ) & V_677 )
break;
V_663 += V_664 ;
V_675 = F_301 ( V_661 , V_663 , sizeof( V_674 ) , & V_674 ) ;
if ( V_675 == NULL )
break;
V_287 -> V_292 . V_669 -> V_678 = V_675 -> V_679 ;
V_287 -> V_292 . V_669 -> V_680 = V_675 -> V_681 ;
break;
}
case V_193 : {
struct V_682 V_683 , * V_684 ;
if ( F_302 ( V_667 -> V_676 ) & V_677 )
break;
V_663 += V_664 ;
V_684 = F_301 ( V_661 , V_663 , sizeof( V_683 ) , & V_683 ) ;
if ( V_684 == NULL )
break;
V_287 -> V_292 . V_669 -> V_678 = V_684 -> V_679 ;
V_287 -> V_292 . V_669 -> V_680 = V_684 -> V_681 ;
break;
}
case V_685 : {
struct V_686 V_687 , * V_688 ;
if ( F_302 ( V_667 -> V_676 ) & V_677 )
break;
V_663 += V_664 ;
V_688 = F_301 ( V_661 , V_663 , sizeof( V_687 ) , & V_687 ) ;
if ( V_688 == NULL )
break;
V_287 -> V_292 . V_669 -> V_678 = V_688 -> V_689 ;
V_287 -> V_292 . V_669 -> V_680 = V_688 -> V_690 ;
break;
}
default:
break;
}
V_81:
return V_635 ;
}
static int F_303 ( struct V_660 * V_661 ,
struct V_286 * V_287 , T_11 * V_662 )
{
T_11 V_691 ;
int V_635 = - V_97 , V_663 ;
struct V_692 V_693 , * V_694 ;
T_14 V_676 ;
V_663 = F_300 ( V_661 ) ;
V_694 = F_301 ( V_661 , V_663 , sizeof( V_693 ) , & V_693 ) ;
if ( V_694 == NULL )
goto V_81;
V_287 -> V_292 . V_669 -> V_695 . V_671 = V_694 -> V_671 ;
V_287 -> V_292 . V_669 -> V_695 . V_672 = V_694 -> V_672 ;
V_635 = 0 ;
V_691 = V_694 -> V_691 ;
V_663 += sizeof( V_693 ) ;
V_663 = F_304 ( V_661 , V_663 , & V_691 , & V_676 ) ;
if ( V_663 < 0 )
goto V_81;
if ( V_662 )
* V_662 = V_691 ;
switch ( V_691 ) {
case V_192 : {
struct V_673 V_674 , * V_675 ;
V_675 = F_301 ( V_661 , V_663 , sizeof( V_674 ) , & V_674 ) ;
if ( V_675 == NULL )
break;
V_287 -> V_292 . V_669 -> V_678 = V_675 -> V_679 ;
V_287 -> V_292 . V_669 -> V_680 = V_675 -> V_681 ;
break;
}
case V_193 : {
struct V_682 V_683 , * V_684 ;
V_684 = F_301 ( V_661 , V_663 , sizeof( V_683 ) , & V_683 ) ;
if ( V_684 == NULL )
break;
V_287 -> V_292 . V_669 -> V_678 = V_684 -> V_679 ;
V_287 -> V_292 . V_669 -> V_680 = V_684 -> V_681 ;
break;
}
case V_685 : {
struct V_686 V_687 , * V_688 ;
V_688 = F_301 ( V_661 , V_663 , sizeof( V_687 ) , & V_687 ) ;
if ( V_688 == NULL )
break;
V_287 -> V_292 . V_669 -> V_678 = V_688 -> V_689 ;
V_287 -> V_292 . V_669 -> V_680 = V_688 -> V_690 ;
break;
}
default:
break;
}
V_81:
return V_635 ;
}
static int F_305 ( struct V_660 * V_661 , struct V_286 * V_287 ,
char * * V_696 , int V_552 , T_11 * V_662 )
{
char * V_697 ;
int V_635 ;
switch ( V_287 -> V_292 . V_669 -> V_194 ) {
case V_201 :
V_635 = F_299 ( V_661 , V_287 , V_662 ) ;
if ( V_635 )
goto V_698;
V_697 = ( char * ) ( V_552 ? & V_287 -> V_292 . V_669 -> V_670 . V_671 :
& V_287 -> V_292 . V_669 -> V_670 . V_672 ) ;
goto V_699;
#if F_306 ( V_700 )
case V_202 :
V_635 = F_303 ( V_661 , V_287 , V_662 ) ;
if ( V_635 )
goto V_698;
V_697 = ( char * ) ( V_552 ? & V_287 -> V_292 . V_669 -> V_695 . V_671 :
& V_287 -> V_292 . V_669 -> V_695 . V_672 ) ;
goto V_699;
#endif
default:
V_697 = NULL ;
goto V_699;
}
V_698:
F_59 ( V_78
L_43
L_44 ) ;
return V_635 ;
V_699:
if ( V_696 )
* V_696 = V_697 ;
return 0 ;
}
static int F_307 ( struct V_660 * V_661 , T_4 V_194 , T_2 * V_17 )
{
int V_609 ;
T_2 V_701 ;
T_2 V_702 ;
T_2 V_703 ;
V_609 = F_308 ( V_661 , & V_701 ) ;
if ( F_127 ( V_609 ) )
return - V_130 ;
V_609 = F_309 ( V_661 , V_194 , & V_703 , & V_702 ) ;
if ( F_127 ( V_609 ) )
return - V_130 ;
V_609 = F_310 ( V_702 , V_703 , V_701 , V_17 ) ;
if ( F_127 ( V_609 ) ) {
F_59 ( V_78
L_45
L_46 ) ;
return - V_130 ;
}
return 0 ;
}
static int F_311 ( T_2 V_704 , T_2 V_705 , T_2 * V_706 )
{
int V_609 = 0 ;
if ( V_705 != V_707 )
V_609 = F_312 ( V_704 , V_705 , V_706 ) ;
else
* V_706 = V_704 ;
return V_609 ;
}
static int F_313 ( const struct V_13 * V_14 ,
T_4 V_708 , T_2 * V_709 )
{
if ( V_14 -> V_429 > V_707 ) {
* V_709 = V_14 -> V_429 ;
return 0 ;
}
return F_80 ( V_14 -> V_17 , V_14 -> V_17 , V_708 , NULL ,
V_709 ) ;
}
static int F_314 ( struct V_20 * V_21 , struct V_710 * V_711 , T_2 V_272 )
{
struct V_712 * V_713 = V_711 -> V_714 ;
struct V_286 V_287 ;
struct V_715 V_669 = { 0 ,} ;
T_2 V_274 = F_18 ( V_21 ) ;
if ( V_713 -> V_17 == V_18 )
return 0 ;
V_287 . type = V_716 ;
V_287 . V_292 . V_669 = & V_669 ;
V_287 . V_292 . V_669 -> V_711 = V_711 ;
return F_55 ( V_274 , V_713 -> V_17 , V_713 -> V_31 , V_272 , & V_287 ) ;
}
static int F_315 ( int V_194 , int type ,
int V_190 , int V_717 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_311 ;
T_4 V_708 ;
int V_61 ;
if ( V_717 )
return 0 ;
V_708 = F_98 ( V_194 , type , V_190 ) ;
V_61 = F_313 ( V_14 , V_708 , & V_311 ) ;
if ( V_61 )
return V_61 ;
return F_55 ( V_14 -> V_17 , V_311 , V_708 , V_718 , NULL ) ;
}
static int F_316 ( struct V_719 * V_710 , int V_194 ,
int type , int V_190 , int V_717 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_24 = F_31 ( F_317 ( V_710 ) ) ;
struct V_712 * V_713 ;
int V_609 = 0 ;
V_24 -> V_31 = F_98 ( V_194 , type , V_190 ) ;
if ( V_717 )
V_24 -> V_17 = V_18 ;
else {
V_609 = F_313 ( V_14 , V_24 -> V_31 , & ( V_24 -> V_17 ) ) ;
if ( V_609 )
return V_609 ;
}
V_24 -> V_38 = V_39 ;
if ( V_710 -> V_711 ) {
V_713 = V_710 -> V_711 -> V_714 ;
V_713 -> V_17 = V_24 -> V_17 ;
V_713 -> V_31 = V_24 -> V_31 ;
V_609 = F_318 ( V_710 -> V_711 , V_194 ) ;
}
return V_609 ;
}
static int F_319 ( struct V_719 * V_710 , struct V_720 * V_721 , int V_722 )
{
struct V_710 * V_711 = V_710 -> V_711 ;
T_4 V_194 ;
int V_609 ;
V_609 = F_314 ( V_11 , V_711 , V_723 ) ;
if ( V_609 )
goto V_81;
V_194 = V_711 -> V_724 ;
if ( V_194 == V_201 || V_194 == V_202 ) {
char * V_697 ;
struct V_712 * V_713 = V_711 -> V_714 ;
struct V_286 V_287 ;
struct V_715 V_669 = { 0 ,} ;
struct V_725 * V_726 = NULL ;
struct V_727 * V_728 = NULL ;
unsigned short V_729 ;
T_2 V_17 , V_730 ;
if ( V_194 == V_201 ) {
V_726 = (struct V_725 * ) V_721 ;
V_729 = F_302 ( V_726 -> V_731 ) ;
V_697 = ( char * ) & V_726 -> V_732 . V_733 ;
} else {
V_728 = (struct V_727 * ) V_721 ;
V_729 = F_302 ( V_728 -> V_734 ) ;
V_697 = ( char * ) & V_728 -> V_735 . V_736 ;
}
if ( V_729 ) {
int V_737 , V_738 ;
F_320 ( F_321 ( V_711 ) , & V_737 , & V_738 ) ;
if ( V_729 < V_739 ( V_740, V_737 ) || V_729 > V_738 ) {
V_609 = F_322 ( V_711 -> V_741 ,
V_729 , & V_17 ) ;
if ( V_609 )
goto V_81;
V_287 . type = V_716 ;
V_287 . V_292 . V_669 = & V_669 ;
V_287 . V_292 . V_669 -> V_678 = F_323 ( V_729 ) ;
V_287 . V_292 . V_669 -> V_194 = V_194 ;
V_609 = F_55 ( V_713 -> V_17 , V_17 ,
V_713 -> V_31 ,
V_742 , & V_287 ) ;
if ( V_609 )
goto V_81;
}
}
switch ( V_713 -> V_31 ) {
case V_203 :
V_730 = V_743 ;
break;
case V_205 :
V_730 = V_744 ;
break;
case V_207 :
V_730 = V_745 ;
break;
default:
V_730 = V_746 ;
break;
}
V_609 = F_324 ( V_697 , V_194 , & V_17 ) ;
if ( V_609 )
goto V_81;
V_287 . type = V_716 ;
V_287 . V_292 . V_669 = & V_669 ;
V_287 . V_292 . V_669 -> V_678 = F_323 ( V_729 ) ;
V_287 . V_292 . V_669 -> V_194 = V_194 ;
if ( V_194 == V_201 )
V_287 . V_292 . V_669 -> V_670 . V_671 = V_726 -> V_732 . V_733 ;
else
V_287 . V_292 . V_669 -> V_695 . V_671 = V_728 -> V_735 ;
V_609 = F_55 ( V_713 -> V_17 , V_17 ,
V_713 -> V_31 , V_730 , & V_287 ) ;
if ( V_609 )
goto V_81;
}
V_81:
return V_609 ;
}
static int F_325 ( struct V_719 * V_710 , struct V_720 * V_721 , int V_722 )
{
struct V_710 * V_711 = V_710 -> V_711 ;
struct V_712 * V_713 = V_711 -> V_714 ;
int V_609 ;
V_609 = F_314 ( V_11 , V_711 , V_747 ) ;
if ( V_609 )
return V_609 ;
if ( V_713 -> V_31 == V_203 ||
V_713 -> V_31 == V_207 ) {
struct V_286 V_287 ;
struct V_715 V_669 = { 0 ,} ;
struct V_725 * V_726 = NULL ;
struct V_727 * V_728 = NULL ;
unsigned short V_729 ;
T_2 V_17 , V_262 ;
if ( V_711 -> V_724 == V_201 ) {
V_726 = (struct V_725 * ) V_721 ;
if ( V_722 < sizeof( struct V_725 ) )
return - V_97 ;
V_729 = F_302 ( V_726 -> V_731 ) ;
} else {
V_728 = (struct V_727 * ) V_721 ;
if ( V_722 < V_748 )
return - V_97 ;
V_729 = F_302 ( V_728 -> V_734 ) ;
}
V_609 = F_322 ( V_711 -> V_741 , V_729 , & V_17 ) ;
if ( V_609 )
goto V_81;
V_262 = ( V_713 -> V_31 == V_203 ) ?
V_749 : V_750 ;
V_287 . type = V_716 ;
V_287 . V_292 . V_669 = & V_669 ;
V_287 . V_292 . V_669 -> V_680 = F_323 ( V_729 ) ;
V_287 . V_292 . V_669 -> V_194 = V_711 -> V_724 ;
V_609 = F_55 ( V_713 -> V_17 , V_17 , V_713 -> V_31 , V_262 , & V_287 ) ;
if ( V_609 )
goto V_81;
}
V_609 = F_326 ( V_711 , V_721 ) ;
V_81:
return V_609 ;
}
static int F_327 ( struct V_719 * V_710 , int V_751 )
{
return F_314 ( V_11 , V_710 -> V_711 , V_752 ) ;
}
static int F_328 ( struct V_719 * V_710 , struct V_719 * V_753 )
{
int V_609 ;
struct V_23 * V_24 ;
struct V_23 * V_149 ;
V_609 = F_314 ( V_11 , V_710 -> V_711 , V_754 ) ;
if ( V_609 )
return V_609 ;
V_149 = F_31 ( F_317 ( V_753 ) ) ;
V_24 = F_31 ( F_317 ( V_710 ) ) ;
V_149 -> V_31 = V_24 -> V_31 ;
V_149 -> V_17 = V_24 -> V_17 ;
V_149 -> V_38 = V_39 ;
return 0 ;
}
static int F_329 ( struct V_719 * V_710 , struct V_755 * V_756 ,
int V_539 )
{
return F_314 ( V_11 , V_710 -> V_711 , V_757 ) ;
}
static int F_330 ( struct V_719 * V_710 , struct V_755 * V_756 ,
int V_539 , int V_86 )
{
return F_314 ( V_11 , V_710 -> V_711 , V_758 ) ;
}
static int F_331 ( struct V_719 * V_710 )
{
return F_314 ( V_11 , V_710 -> V_711 , V_759 ) ;
}
static int F_332 ( struct V_719 * V_710 )
{
return F_314 ( V_11 , V_710 -> V_711 , V_759 ) ;
}
static int F_333 ( struct V_719 * V_710 , int V_760 , int V_761 )
{
int V_609 ;
V_609 = F_314 ( V_11 , V_710 -> V_711 , V_762 ) ;
if ( V_609 )
return V_609 ;
return F_334 ( V_710 , V_760 , V_761 ) ;
}
static int F_335 ( struct V_719 * V_710 , int V_760 ,
int V_761 )
{
return F_314 ( V_11 , V_710 -> V_711 , V_763 ) ;
}
static int F_336 ( struct V_719 * V_710 , int V_764 )
{
return F_314 ( V_11 , V_710 -> V_711 , V_765 ) ;
}
static int F_337 ( struct V_710 * V_710 ,
struct V_710 * V_766 ,
struct V_710 * V_767 )
{
struct V_712 * V_768 = V_710 -> V_714 ;
struct V_712 * V_769 = V_766 -> V_714 ;
struct V_712 * V_770 = V_767 -> V_714 ;
struct V_286 V_287 ;
struct V_715 V_669 = { 0 ,} ;
int V_609 ;
V_287 . type = V_716 ;
V_287 . V_292 . V_669 = & V_669 ;
V_287 . V_292 . V_669 -> V_711 = V_766 ;
V_609 = F_55 ( V_768 -> V_17 , V_769 -> V_17 ,
V_769 -> V_31 ,
V_771 , & V_287 ) ;
if ( V_609 )
return V_609 ;
V_770 -> V_772 = V_768 -> V_17 ;
V_609 = F_312 ( V_769 -> V_17 , V_768 -> V_17 ,
& V_770 -> V_17 ) ;
if ( V_609 )
return V_609 ;
V_768 -> V_772 = V_770 -> V_17 ;
return 0 ;
}
static int F_338 ( struct V_719 * V_710 ,
struct V_719 * V_766 )
{
struct V_712 * V_773 = V_710 -> V_711 -> V_714 ;
struct V_712 * V_774 = V_766 -> V_711 -> V_714 ;
struct V_286 V_287 ;
struct V_715 V_669 = { 0 ,} ;
V_287 . type = V_716 ;
V_287 . V_292 . V_669 = & V_669 ;
V_287 . V_292 . V_669 -> V_711 = V_766 -> V_711 ;
return F_55 ( V_773 -> V_17 , V_774 -> V_17 , V_774 -> V_31 , V_775 ,
& V_287 ) ;
}
static int F_339 ( struct V_669 * V_383 , int V_776 ,
char * V_697 , T_4 V_194 , T_2 V_772 ,
struct V_286 * V_287 )
{
int V_609 ;
T_2 V_777 ;
T_2 V_778 ;
V_609 = F_340 ( V_383 , V_776 , & V_777 ) ;
if ( V_609 )
return V_609 ;
V_609 = F_55 ( V_772 , V_777 ,
V_779 , V_780 , V_287 ) ;
if ( V_609 )
return V_609 ;
V_609 = F_324 ( V_697 , V_194 , & V_778 ) ;
if ( V_609 )
return V_609 ;
return F_55 ( V_772 , V_778 ,
V_781 , V_782 , V_287 ) ;
}
static int F_341 ( struct V_710 * V_711 , struct V_660 * V_661 ,
T_4 V_194 )
{
int V_609 = 0 ;
struct V_712 * V_713 = V_711 -> V_714 ;
T_2 V_704 = V_713 -> V_17 ;
struct V_286 V_287 ;
struct V_715 V_669 = { 0 ,} ;
char * V_697 ;
V_287 . type = V_716 ;
V_287 . V_292 . V_669 = & V_669 ;
V_287 . V_292 . V_669 -> V_783 = V_661 -> V_784 ;
V_287 . V_292 . V_669 -> V_194 = V_194 ;
V_609 = F_305 ( V_661 , & V_287 , & V_697 , 1 , NULL ) ;
if ( V_609 )
return V_609 ;
if ( F_4 () ) {
V_609 = F_55 ( V_704 , V_661 -> V_785 , V_786 ,
V_787 , & V_287 ) ;
if ( V_609 )
return V_609 ;
}
V_609 = F_342 ( V_713 , V_661 , V_194 , & V_287 ) ;
if ( V_609 )
return V_609 ;
V_609 = F_343 ( V_713 -> V_17 , V_661 , & V_287 ) ;
return V_609 ;
}
static int F_344 ( struct V_710 * V_711 , struct V_660 * V_661 )
{
int V_609 ;
struct V_712 * V_713 = V_711 -> V_714 ;
T_4 V_194 = V_711 -> V_724 ;
T_2 V_704 = V_713 -> V_17 ;
struct V_286 V_287 ;
struct V_715 V_669 = { 0 ,} ;
char * V_697 ;
T_11 V_788 ;
T_11 V_789 ;
if ( V_194 != V_201 && V_194 != V_202 )
return 0 ;
if ( V_194 == V_202 && V_661 -> V_190 == F_323 ( V_790 ) )
V_194 = V_201 ;
if ( ! V_791 )
return F_341 ( V_711 , V_661 , V_194 ) ;
V_788 = F_4 () ;
V_789 = F_6 () ;
if ( ! V_788 && ! V_789 )
return 0 ;
V_287 . type = V_716 ;
V_287 . V_292 . V_669 = & V_669 ;
V_287 . V_292 . V_669 -> V_783 = V_661 -> V_784 ;
V_287 . V_292 . V_669 -> V_194 = V_194 ;
V_609 = F_305 ( V_661 , & V_287 , & V_697 , 1 , NULL ) ;
if ( V_609 )
return V_609 ;
if ( V_789 ) {
T_2 V_772 ;
V_609 = F_307 ( V_661 , V_194 , & V_772 ) ;
if ( V_609 )
return V_609 ;
V_609 = F_339 ( F_321 ( V_711 ) , V_661 -> V_784 ,
V_697 , V_194 , V_772 , & V_287 ) ;
if ( V_609 ) {
F_345 ( V_661 , V_194 , V_609 , 0 ) ;
return V_609 ;
}
V_609 = F_55 ( V_704 , V_772 , V_792 ,
V_793 , & V_287 ) ;
if ( V_609 ) {
F_345 ( V_661 , V_194 , V_609 , 0 ) ;
return V_609 ;
}
}
if ( V_788 ) {
V_609 = F_55 ( V_704 , V_661 -> V_785 , V_786 ,
V_787 , & V_287 ) ;
if ( V_609 )
return V_609 ;
}
return V_609 ;
}
static int F_346 ( struct V_719 * V_710 , char T_15 * V_794 ,
int T_15 * V_795 , unsigned V_95 )
{
int V_609 = 0 ;
char * V_796 ;
T_2 V_797 ;
struct V_712 * V_713 = V_710 -> V_711 -> V_714 ;
T_2 V_772 = V_707 ;
if ( V_713 -> V_31 == V_198 ||
V_713 -> V_31 == V_203 )
V_772 = V_713 -> V_772 ;
if ( V_772 == V_707 )
return - V_798 ;
V_609 = F_71 ( V_772 , & V_796 , & V_797 ) ;
if ( V_609 )
return V_609 ;
if ( V_797 > V_95 ) {
V_609 = - V_255 ;
goto V_799;
}
if ( F_347 ( V_794 , V_796 , V_797 ) )
V_609 = - V_800 ;
V_799:
if ( F_348 ( V_797 , V_795 ) )
V_609 = - V_800 ;
F_52 ( V_796 ) ;
return V_609 ;
}
static int F_349 ( struct V_719 * V_710 , struct V_660 * V_661 , T_2 * V_551 )
{
T_2 V_801 = V_707 ;
T_4 V_194 ;
struct V_23 * V_24 ;
if ( V_661 && V_661 -> V_190 == F_323 ( V_790 ) )
V_194 = V_201 ;
else if ( V_661 && V_661 -> V_190 == F_323 ( V_802 ) )
V_194 = V_202 ;
else if ( V_710 )
V_194 = V_710 -> V_711 -> V_724 ;
else
goto V_81;
if ( V_710 && V_194 == V_195 ) {
V_24 = F_31 ( F_317 ( V_710 ) ) ;
V_801 = V_24 -> V_17 ;
} else if ( V_661 )
F_307 ( V_661 , V_194 , & V_801 ) ;
V_81:
* V_551 = V_801 ;
if ( V_801 == V_707 )
return - V_97 ;
return 0 ;
}
static int F_350 ( struct V_710 * V_711 , int V_194 , T_12 V_803 )
{
struct V_712 * V_713 ;
V_713 = F_15 ( sizeof( * V_713 ) , V_803 ) ;
if ( ! V_713 )
return - V_27 ;
V_713 -> V_772 = V_30 ;
V_713 -> V_17 = V_30 ;
V_713 -> V_31 = V_248 ;
F_351 ( V_713 ) ;
V_711 -> V_714 = V_713 ;
return 0 ;
}
static void F_352 ( struct V_710 * V_711 )
{
struct V_712 * V_713 = V_711 -> V_714 ;
V_711 -> V_714 = NULL ;
F_353 ( V_713 ) ;
F_52 ( V_713 ) ;
}
static void F_354 ( const struct V_710 * V_711 , struct V_710 * V_767 )
{
struct V_712 * V_713 = V_711 -> V_714 ;
struct V_712 * V_804 = V_767 -> V_714 ;
V_804 -> V_17 = V_713 -> V_17 ;
V_804 -> V_772 = V_713 -> V_772 ;
V_804 -> V_31 = V_713 -> V_31 ;
F_351 ( V_804 ) ;
}
static void F_355 ( struct V_710 * V_711 , T_2 * V_551 )
{
if ( ! V_711 )
* V_551 = V_805 ;
else {
struct V_712 * V_713 = V_711 -> V_714 ;
* V_551 = V_713 -> V_17 ;
}
}
static void F_356 ( struct V_710 * V_711 , struct V_719 * V_376 )
{
struct V_23 * V_24 =
F_31 ( F_317 ( V_376 ) ) ;
struct V_712 * V_713 = V_711 -> V_714 ;
if ( V_711 -> V_724 == V_201 || V_711 -> V_724 == V_202 ||
V_711 -> V_724 == V_195 )
V_24 -> V_17 = V_713 -> V_17 ;
V_713 -> V_31 = V_24 -> V_31 ;
}
static int F_357 ( struct V_710 * V_711 , struct V_660 * V_661 ,
struct V_806 * V_807 )
{
struct V_712 * V_713 = V_711 -> V_714 ;
int V_609 ;
T_4 V_194 = V_807 -> V_808 -> V_194 ;
T_2 V_809 ;
T_2 V_810 ;
V_609 = F_307 ( V_661 , V_194 , & V_810 ) ;
if ( V_609 )
return V_609 ;
V_609 = F_311 ( V_713 -> V_17 , V_810 , & V_809 ) ;
if ( V_609 )
return V_609 ;
V_807 -> V_551 = V_809 ;
V_807 -> V_801 = V_810 ;
return F_358 ( V_807 , V_194 ) ;
}
static void F_359 ( struct V_710 * V_767 ,
const struct V_806 * V_807 )
{
struct V_712 * V_804 = V_767 -> V_714 ;
V_804 -> V_17 = V_807 -> V_551 ;
V_804 -> V_772 = V_807 -> V_801 ;
F_360 ( V_767 , V_807 -> V_808 -> V_194 ) ;
}
static void F_361 ( struct V_710 * V_711 , struct V_660 * V_661 )
{
T_4 V_194 = V_711 -> V_724 ;
struct V_712 * V_713 = V_711 -> V_714 ;
if ( V_194 == V_202 && V_661 -> V_190 == F_323 ( V_790 ) )
V_194 = V_201 ;
F_307 ( V_661 , V_194 , & V_713 -> V_772 ) ;
}
static int F_362 ( T_2 V_17 )
{
const struct V_13 * V_811 ;
T_2 V_274 ;
V_811 = F_23 () ;
V_274 = V_811 -> V_17 ;
return F_55 ( V_274 , V_17 , V_786 , V_812 , NULL ) ;
}
static void F_363 ( void )
{
F_364 ( & V_7 ) ;
}
static void F_365 ( void )
{
F_366 ( & V_7 ) ;
}
static void F_367 ( const struct V_806 * V_807 ,
struct V_813 * V_814 )
{
V_814 -> V_815 = V_807 -> V_551 ;
}
static int F_368 ( void * * V_19 )
{
struct V_816 * V_817 ;
V_817 = F_15 ( sizeof( * V_817 ) , V_15 ) ;
if ( ! V_817 )
return - V_27 ;
V_817 -> V_17 = F_22 () ;
* V_19 = V_817 ;
return 0 ;
}
static void F_369 ( void * V_19 )
{
F_52 ( V_19 ) ;
}
static int F_370 ( void )
{
T_2 V_17 = F_22 () ;
return F_55 ( V_17 , V_17 , V_818 , V_819 ,
NULL ) ;
}
static int F_371 ( void * V_19 )
{
struct V_816 * V_817 = V_19 ;
return F_55 ( F_22 () , V_817 -> V_17 , V_818 ,
V_820 , NULL ) ;
}
static int F_372 ( struct V_710 * V_711 , void * V_19 )
{
struct V_816 * V_817 = V_19 ;
struct V_712 * V_713 = V_711 -> V_714 ;
V_713 -> V_17 = V_817 -> V_17 ;
V_713 -> V_31 = V_818 ;
return 0 ;
}
static int F_373 ( void * V_19 )
{
struct V_816 * V_817 = V_19 ;
T_2 V_17 = F_22 () ;
int V_609 ;
V_609 = F_55 ( V_17 , V_817 -> V_17 , V_818 ,
V_821 , NULL ) ;
if ( V_609 )
return V_609 ;
V_609 = F_55 ( V_17 , V_17 , V_818 ,
V_822 , NULL ) ;
if ( V_609 )
return V_609 ;
V_817 -> V_17 = V_17 ;
return 0 ;
}
static int F_374 ( struct V_710 * V_711 , struct V_660 * V_661 )
{
int V_609 = 0 ;
T_2 V_262 ;
struct V_823 * V_824 ;
struct V_712 * V_713 = V_711 -> V_714 ;
if ( V_661 -> V_95 < V_825 ) {
V_609 = - V_97 ;
goto V_81;
}
V_824 = F_375 ( V_661 ) ;
V_609 = F_376 ( V_713 -> V_31 , V_824 -> V_826 , & V_262 ) ;
if ( V_609 ) {
if ( V_609 == - V_97 ) {
F_377 ( L_47
L_48
L_49 ,
V_711 -> V_741 , V_824 -> V_826 ,
V_827 [ V_713 -> V_31 - 1 ] . V_72 ,
F_378 ( V_11 ) , V_11 -> V_828 ) ;
if ( ! V_3 || F_379 () )
V_609 = 0 ;
}
if ( V_609 == - V_829 )
V_609 = 0 ;
goto V_81;
}
V_609 = F_314 ( V_11 , V_711 , V_262 ) ;
V_81:
return V_609 ;
}
static unsigned int F_380 ( struct V_660 * V_661 ,
const struct V_830 * V_831 ,
T_4 V_194 )
{
int V_609 ;
char * V_697 ;
T_2 V_772 ;
struct V_286 V_287 ;
struct V_715 V_669 = { 0 ,} ;
T_11 V_788 ;
T_11 V_832 ;
T_11 V_789 ;
if ( ! V_791 )
return V_833 ;
V_788 = F_4 () ;
V_832 = F_7 () ;
V_789 = F_6 () ;
if ( ! V_788 && ! V_789 )
return V_833 ;
if ( F_307 ( V_661 , V_194 , & V_772 ) != 0 )
return V_834 ;
V_287 . type = V_716 ;
V_287 . V_292 . V_669 = & V_669 ;
V_287 . V_292 . V_669 -> V_783 = V_831 -> V_776 ;
V_287 . V_292 . V_669 -> V_194 = V_194 ;
if ( F_305 ( V_661 , & V_287 , & V_697 , 1 , NULL ) != 0 )
return V_834 ;
if ( V_789 ) {
V_609 = F_339 ( F_381 ( V_831 ) , V_831 -> V_776 ,
V_697 , V_194 , V_772 , & V_287 ) ;
if ( V_609 ) {
F_345 ( V_661 , V_194 , V_609 , 1 ) ;
return V_834 ;
}
}
if ( V_788 )
if ( F_55 ( V_772 , V_661 -> V_785 ,
V_786 , V_835 , & V_287 ) )
return V_834 ;
if ( V_832 )
if ( F_382 ( V_661 , V_194 , V_772 ) != 0 )
return V_834 ;
return V_833 ;
}
static unsigned int F_383 ( void * V_836 ,
struct V_660 * V_661 ,
const struct V_837 * V_838 )
{
return F_380 ( V_661 , V_838 -> V_839 , V_201 ) ;
}
static unsigned int F_384 ( void * V_836 ,
struct V_660 * V_661 ,
const struct V_837 * V_838 )
{
return F_380 ( V_661 , V_838 -> V_839 , V_202 ) ;
}
static unsigned int F_385 ( struct V_660 * V_661 ,
T_4 V_194 )
{
struct V_710 * V_711 ;
T_2 V_17 ;
if ( ! F_7 () )
return V_833 ;
V_711 = V_661 -> V_711 ;
if ( V_711 ) {
struct V_712 * V_713 ;
if ( F_386 ( V_711 ) )
return V_833 ;
V_713 = V_711 -> V_714 ;
V_17 = V_713 -> V_17 ;
} else
V_17 = V_18 ;
if ( F_382 ( V_661 , V_194 , V_17 ) != 0 )
return V_834 ;
return V_833 ;
}
static unsigned int F_387 ( void * V_836 ,
struct V_660 * V_661 ,
const struct V_837 * V_838 )
{
return F_385 ( V_661 , V_201 ) ;
}
static unsigned int F_388 ( void * V_836 ,
struct V_660 * V_661 ,
const struct V_837 * V_838 )
{
return F_385 ( V_661 , V_202 ) ;
}
static unsigned int F_389 ( struct V_660 * V_661 ,
int V_776 ,
T_4 V_194 )
{
struct V_710 * V_711 = F_390 ( V_661 ) ;
struct V_712 * V_713 ;
struct V_286 V_287 ;
struct V_715 V_669 = { 0 ,} ;
char * V_697 ;
T_11 V_662 ;
if ( V_711 == NULL )
return V_833 ;
V_713 = V_711 -> V_714 ;
V_287 . type = V_716 ;
V_287 . V_292 . V_669 = & V_669 ;
V_287 . V_292 . V_669 -> V_783 = V_776 ;
V_287 . V_292 . V_669 -> V_194 = V_194 ;
if ( F_305 ( V_661 , & V_287 , & V_697 , 0 , & V_662 ) )
return V_834 ;
if ( F_4 () )
if ( F_55 ( V_713 -> V_17 , V_661 -> V_785 ,
V_786 , V_840 , & V_287 ) )
return F_391 ( - V_841 ) ;
if ( F_392 ( V_713 -> V_17 , V_661 , & V_287 , V_662 ) )
return F_391 ( - V_841 ) ;
return V_833 ;
}
static unsigned int F_393 ( struct V_660 * V_661 ,
const struct V_830 * V_842 ,
T_4 V_194 )
{
T_2 V_843 ;
T_2 V_772 ;
int V_776 = V_842 -> V_776 ;
struct V_710 * V_711 ;
struct V_286 V_287 ;
struct V_715 V_669 = { 0 ,} ;
char * V_697 ;
T_11 V_788 ;
T_11 V_789 ;
if ( ! V_791 )
return F_389 ( V_661 , V_776 , V_194 ) ;
V_788 = F_4 () ;
V_789 = F_6 () ;
if ( ! V_788 && ! V_789 )
return V_833 ;
V_711 = F_390 ( V_661 ) ;
#ifdef F_394
if ( F_395 ( V_661 ) != NULL && F_395 ( V_661 ) -> V_844 != NULL &&
! ( V_711 && F_386 ( V_711 ) ) )
return V_833 ;
#endif
if ( V_711 == NULL ) {
if ( V_661 -> V_784 ) {
V_843 = V_845 ;
if ( F_307 ( V_661 , V_194 , & V_772 ) )
return V_834 ;
} else {
V_843 = V_840 ;
V_772 = V_18 ;
}
} else if ( F_386 ( V_711 ) ) {
T_2 V_705 ;
struct V_712 * V_713 ;
V_713 = V_711 -> V_714 ;
if ( F_307 ( V_661 , V_194 , & V_705 ) )
return V_834 ;
if ( V_705 == V_707 ) {
switch ( V_194 ) {
case V_201 :
if ( F_396 ( V_661 ) -> V_86 & V_846 )
return V_833 ;
break;
case V_202 :
if ( F_397 ( V_661 ) -> V_86 & V_847 )
return V_833 ;
break;
default:
return F_391 ( - V_841 ) ;
}
}
if ( F_311 ( V_713 -> V_17 , V_705 , & V_772 ) )
return V_834 ;
V_843 = V_840 ;
} else {
struct V_712 * V_713 = V_711 -> V_714 ;
V_772 = V_713 -> V_17 ;
V_843 = V_840 ;
}
V_287 . type = V_716 ;
V_287 . V_292 . V_669 = & V_669 ;
V_287 . V_292 . V_669 -> V_783 = V_776 ;
V_287 . V_292 . V_669 -> V_194 = V_194 ;
if ( F_305 ( V_661 , & V_287 , & V_697 , 0 , NULL ) )
return V_834 ;
if ( V_788 )
if ( F_55 ( V_772 , V_661 -> V_785 ,
V_786 , V_843 , & V_287 ) )
return F_391 ( - V_841 ) ;
if ( V_789 ) {
T_2 V_777 ;
T_2 V_778 ;
if ( F_340 ( F_381 ( V_842 ) , V_776 , & V_777 ) )
return V_834 ;
if ( F_55 ( V_772 , V_777 ,
V_779 , V_848 , & V_287 ) )
return F_391 ( - V_841 ) ;
if ( F_324 ( V_697 , V_194 , & V_778 ) )
return V_834 ;
if ( F_55 ( V_772 , V_778 ,
V_781 , V_849 , & V_287 ) )
return F_391 ( - V_841 ) ;
}
return V_833 ;
}
static unsigned int F_398 ( void * V_836 ,
struct V_660 * V_661 ,
const struct V_837 * V_838 )
{
return F_393 ( V_661 , V_838 -> V_81 , V_201 ) ;
}
static unsigned int F_399 ( void * V_836 ,
struct V_660 * V_661 ,
const struct V_837 * V_838 )
{
return F_393 ( V_661 , V_838 -> V_81 , V_202 ) ;
}
static int F_400 ( struct V_710 * V_711 , struct V_660 * V_661 )
{
return F_374 ( V_711 , V_661 ) ;
}
static int F_401 ( struct V_20 * V_21 ,
struct V_850 * V_262 ,
T_4 V_31 )
{
struct V_851 * V_24 ;
T_2 V_17 ;
V_24 = F_15 ( sizeof( struct V_851 ) , V_15 ) ;
if ( ! V_24 )
return - V_27 ;
V_17 = F_18 ( V_21 ) ;
V_24 -> V_31 = V_31 ;
V_24 -> V_17 = V_17 ;
V_262 -> V_19 = V_24 ;
return 0 ;
}
static void F_402 ( struct V_850 * V_262 )
{
struct V_851 * V_24 = V_262 -> V_19 ;
V_262 -> V_19 = NULL ;
F_52 ( V_24 ) ;
}
static int F_403 ( struct V_852 * V_756 )
{
struct V_853 * V_854 ;
V_854 = F_15 ( sizeof( struct V_853 ) , V_15 ) ;
if ( ! V_854 )
return - V_27 ;
V_854 -> V_17 = V_30 ;
V_756 -> V_19 = V_854 ;
return 0 ;
}
static void F_404 ( struct V_852 * V_756 )
{
struct V_853 * V_854 = V_756 -> V_19 ;
V_756 -> V_19 = NULL ;
F_52 ( V_854 ) ;
}
static int F_405 ( struct V_850 * V_855 ,
T_2 V_272 )
{
struct V_851 * V_24 ;
struct V_286 V_287 ;
T_2 V_17 = F_22 () ;
V_24 = V_855 -> V_19 ;
V_287 . type = V_856 ;
V_287 . V_292 . V_857 = V_855 -> V_858 ;
return F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_272 , & V_287 ) ;
}
static int F_406 ( struct V_852 * V_756 )
{
return F_403 ( V_756 ) ;
}
static void F_407 ( struct V_852 * V_756 )
{
F_404 ( V_756 ) ;
}
static int F_408 ( struct V_859 * V_860 )
{
struct V_851 * V_24 ;
struct V_286 V_287 ;
T_2 V_17 = F_22 () ;
int V_61 ;
V_61 = F_401 ( V_11 , & V_860 -> V_861 , V_862 ) ;
if ( V_61 )
return V_61 ;
V_24 = V_860 -> V_861 . V_19 ;
V_287 . type = V_856 ;
V_287 . V_292 . V_857 = V_860 -> V_861 . V_858 ;
V_61 = F_55 ( V_17 , V_24 -> V_17 , V_862 ,
V_863 , & V_287 ) ;
if ( V_61 ) {
F_402 ( & V_860 -> V_861 ) ;
return V_61 ;
}
return 0 ;
}
static void F_409 ( struct V_859 * V_860 )
{
F_402 ( & V_860 -> V_861 ) ;
}
static int F_410 ( struct V_859 * V_860 , int V_864 )
{
struct V_851 * V_24 ;
struct V_286 V_287 ;
T_2 V_17 = F_22 () ;
V_24 = V_860 -> V_861 . V_19 ;
V_287 . type = V_856 ;
V_287 . V_292 . V_857 = V_860 -> V_861 . V_858 ;
return F_55 ( V_17 , V_24 -> V_17 , V_862 ,
V_865 , & V_287 ) ;
}
static int F_411 ( struct V_859 * V_860 , int V_557 )
{
int V_609 ;
int V_272 ;
switch ( V_557 ) {
case V_866 :
case V_867 :
return F_124 ( V_11 , V_868 ) ;
case V_869 :
case V_870 :
V_272 = V_871 | V_865 ;
break;
case V_872 :
V_272 = V_873 ;
break;
case V_874 :
V_272 = V_875 ;
break;
default:
return 0 ;
}
V_609 = F_405 ( & V_860 -> V_861 , V_272 ) ;
return V_609 ;
}
static int F_412 ( struct V_859 * V_860 , struct V_852 * V_756 , int V_864 )
{
struct V_851 * V_24 ;
struct V_853 * V_854 ;
struct V_286 V_287 ;
T_2 V_17 = F_22 () ;
int V_61 ;
V_24 = V_860 -> V_861 . V_19 ;
V_854 = V_756 -> V_19 ;
if ( V_854 -> V_17 == V_30 ) {
V_61 = F_80 ( V_17 , V_24 -> V_17 , V_876 ,
NULL , & V_854 -> V_17 ) ;
if ( V_61 )
return V_61 ;
}
V_287 . type = V_856 ;
V_287 . V_292 . V_857 = V_860 -> V_861 . V_858 ;
V_61 = F_55 ( V_17 , V_24 -> V_17 , V_862 ,
V_877 , & V_287 ) ;
if ( ! V_61 )
V_61 = F_55 ( V_17 , V_854 -> V_17 , V_876 ,
V_878 , & V_287 ) ;
if ( ! V_61 )
V_61 = F_55 ( V_854 -> V_17 , V_24 -> V_17 , V_862 ,
V_879 , & V_287 ) ;
return V_61 ;
}
static int F_413 ( struct V_859 * V_860 , struct V_852 * V_756 ,
struct V_20 * V_271 ,
long type , int V_175 )
{
struct V_851 * V_24 ;
struct V_853 * V_854 ;
struct V_286 V_287 ;
T_2 V_17 = F_18 ( V_271 ) ;
int V_61 ;
V_24 = V_860 -> V_861 . V_19 ;
V_854 = V_756 -> V_19 ;
V_287 . type = V_856 ;
V_287 . V_292 . V_857 = V_860 -> V_861 . V_858 ;
V_61 = F_55 ( V_17 , V_24 -> V_17 ,
V_862 , V_880 , & V_287 ) ;
if ( ! V_61 )
V_61 = F_55 ( V_17 , V_854 -> V_17 ,
V_876 , V_881 , & V_287 ) ;
return V_61 ;
}
static int F_414 ( struct V_882 * V_883 )
{
struct V_851 * V_24 ;
struct V_286 V_287 ;
T_2 V_17 = F_22 () ;
int V_61 ;
V_61 = F_401 ( V_11 , & V_883 -> V_884 , V_885 ) ;
if ( V_61 )
return V_61 ;
V_24 = V_883 -> V_884 . V_19 ;
V_287 . type = V_856 ;
V_287 . V_292 . V_857 = V_883 -> V_884 . V_858 ;
V_61 = F_55 ( V_17 , V_24 -> V_17 , V_885 ,
V_886 , & V_287 ) ;
if ( V_61 ) {
F_402 ( & V_883 -> V_884 ) ;
return V_61 ;
}
return 0 ;
}
static void F_415 ( struct V_882 * V_883 )
{
F_402 ( & V_883 -> V_884 ) ;
}
static int F_416 ( struct V_882 * V_883 , int V_887 )
{
struct V_851 * V_24 ;
struct V_286 V_287 ;
T_2 V_17 = F_22 () ;
V_24 = V_883 -> V_884 . V_19 ;
V_287 . type = V_856 ;
V_287 . V_292 . V_857 = V_883 -> V_884 . V_858 ;
return F_55 ( V_17 , V_24 -> V_17 , V_885 ,
V_888 , & V_287 ) ;
}
static int F_417 ( struct V_882 * V_883 , int V_557 )
{
int V_272 ;
int V_609 ;
switch ( V_557 ) {
case V_866 :
case V_889 :
return F_124 ( V_11 , V_868 ) ;
case V_869 :
case V_890 :
V_272 = V_891 | V_888 ;
break;
case V_872 :
V_272 = V_892 ;
break;
case V_893 :
case V_894 :
V_272 = V_895 ;
break;
case V_874 :
V_272 = V_896 ;
break;
default:
return 0 ;
}
V_609 = F_405 ( & V_883 -> V_884 , V_272 ) ;
return V_609 ;
}
static int F_418 ( struct V_882 * V_883 ,
char T_15 * V_897 , int V_887 )
{
T_2 V_272 ;
if ( V_887 & V_898 )
V_272 = V_899 ;
else
V_272 = V_899 | V_900 ;
return F_405 ( & V_883 -> V_884 , V_272 ) ;
}
static int F_419 ( struct V_901 * V_902 )
{
struct V_851 * V_24 ;
struct V_286 V_287 ;
T_2 V_17 = F_22 () ;
int V_61 ;
V_61 = F_401 ( V_11 , & V_902 -> V_903 , V_904 ) ;
if ( V_61 )
return V_61 ;
V_24 = V_902 -> V_903 . V_19 ;
V_287 . type = V_856 ;
V_287 . V_292 . V_857 = V_902 -> V_903 . V_858 ;
V_61 = F_55 ( V_17 , V_24 -> V_17 , V_904 ,
V_905 , & V_287 ) ;
if ( V_61 ) {
F_402 ( & V_902 -> V_903 ) ;
return V_61 ;
}
return 0 ;
}
static void F_420 ( struct V_901 * V_902 )
{
F_402 ( & V_902 -> V_903 ) ;
}
static int F_421 ( struct V_901 * V_902 , int V_906 )
{
struct V_851 * V_24 ;
struct V_286 V_287 ;
T_2 V_17 = F_22 () ;
V_24 = V_902 -> V_903 . V_19 ;
V_287 . type = V_856 ;
V_287 . V_292 . V_857 = V_902 -> V_903 . V_858 ;
return F_55 ( V_17 , V_24 -> V_17 , V_904 ,
V_907 , & V_287 ) ;
}
static int F_422 ( struct V_901 * V_902 , int V_557 )
{
int V_609 ;
T_2 V_272 ;
switch ( V_557 ) {
case V_866 :
case V_908 :
return F_124 ( V_11 , V_868 ) ;
case V_909 :
case V_910 :
case V_911 :
V_272 = V_912 ;
break;
case V_913 :
case V_914 :
V_272 = V_915 ;
break;
case V_916 :
case V_917 :
V_272 = V_918 ;
break;
case V_874 :
V_272 = V_919 ;
break;
case V_872 :
V_272 = V_920 ;
break;
case V_869 :
case V_921 :
V_272 = V_912 | V_907 ;
break;
default:
return 0 ;
}
V_609 = F_405 ( & V_902 -> V_903 , V_272 ) ;
return V_609 ;
}
static int F_423 ( struct V_901 * V_902 ,
struct V_922 * V_923 , unsigned V_924 , int V_925 )
{
T_2 V_272 ;
if ( V_925 )
V_272 = V_915 | V_918 ;
else
V_272 = V_915 ;
return F_405 ( & V_902 -> V_903 , V_272 ) ;
}
static int F_424 ( struct V_850 * V_926 , short V_109 )
{
T_2 V_290 = 0 ;
V_290 = 0 ;
if ( V_109 & V_927 )
V_290 |= V_928 ;
if ( V_109 & V_929 )
V_290 |= V_930 ;
if ( V_290 == 0 )
return 0 ;
return F_405 ( V_926 , V_290 ) ;
}
static void F_425 ( struct V_850 * V_926 , T_2 * V_551 )
{
struct V_851 * V_24 = V_926 -> V_19 ;
* V_551 = V_24 -> V_17 ;
}
static void F_426 ( struct V_34 * V_34 , struct V_22 * V_22 )
{
if ( V_22 )
F_30 ( V_22 , V_34 ) ;
}
static int F_427 ( struct V_20 * V_152 ,
char * V_72 , char * * V_508 )
{
const struct V_13 * V_811 ;
T_2 V_17 ;
int error ;
unsigned V_95 ;
if ( V_11 != V_152 ) {
error = F_118 ( V_152 , V_931 ) ;
if ( error )
return error ;
}
F_19 () ;
V_811 = F_20 ( V_152 ) -> V_19 ;
if ( ! strcmp ( V_72 , L_50 ) )
V_17 = V_811 -> V_17 ;
else if ( ! strcmp ( V_72 , L_51 ) )
V_17 = V_811 -> V_16 ;
else if ( ! strcmp ( V_72 , L_52 ) )
V_17 = V_811 -> V_430 ;
else if ( ! strcmp ( V_72 , L_53 ) )
V_17 = V_811 -> V_309 ;
else if ( ! strcmp ( V_72 , L_54 ) )
V_17 = V_811 -> V_428 ;
else if ( ! strcmp ( V_72 , L_55 ) )
V_17 = V_811 -> V_429 ;
else
goto V_932;
F_21 () ;
if ( ! V_17 )
return 0 ;
error = F_71 ( V_17 , V_508 , & V_95 ) ;
if ( error )
return error ;
return V_95 ;
V_932:
F_21 () ;
return - V_97 ;
}
static int F_428 ( struct V_20 * V_152 ,
char * V_72 , void * V_508 , T_7 V_539 )
{
struct V_13 * V_14 ;
struct V_10 * V_137 ;
T_2 V_17 = 0 , V_438 ;
int error ;
char * V_1 = V_508 ;
if ( V_11 != V_152 ) {
return - V_130 ;
}
if ( ! strcmp ( V_72 , L_52 ) )
error = F_118 ( V_152 , V_933 ) ;
else if ( ! strcmp ( V_72 , L_53 ) )
error = F_118 ( V_152 , V_934 ) ;
else if ( ! strcmp ( V_72 , L_54 ) )
error = F_118 ( V_152 , V_935 ) ;
else if ( ! strcmp ( V_72 , L_55 ) )
error = F_118 ( V_152 , V_936 ) ;
else if ( ! strcmp ( V_72 , L_50 ) )
error = F_118 ( V_152 , V_937 ) ;
else
error = - V_97 ;
if ( error )
return error ;
if ( V_539 && V_1 [ 1 ] && V_1 [ 1 ] != '\n' ) {
if ( V_1 [ V_539 - 1 ] == '\n' ) {
V_1 [ V_539 - 1 ] = 0 ;
V_539 -- ;
}
error = F_236 ( V_508 , V_539 , & V_17 , V_15 ) ;
if ( error == - V_97 && ! strcmp ( V_72 , L_53 ) ) {
if ( ! F_233 ( V_541 ) ) {
struct V_542 * V_543 ;
T_7 V_544 ;
if ( V_1 [ V_539 - 1 ] == '\0' )
V_544 = V_539 - 1 ;
else
V_544 = V_539 ;
V_543 = F_237 ( V_11 -> V_545 , V_102 , V_546 ) ;
F_238 ( V_543 , L_56 ) ;
F_239 ( V_543 , V_508 , V_544 ) ;
F_240 ( V_543 ) ;
return error ;
}
error = F_241 ( V_508 , V_539 ,
& V_17 ) ;
}
if ( error )
return error ;
}
V_137 = F_253 () ;
if ( ! V_137 )
return - V_27 ;
V_14 = V_137 -> V_19 ;
if ( ! strcmp ( V_72 , L_52 ) ) {
V_14 -> V_430 = V_17 ;
} else if ( ! strcmp ( V_72 , L_53 ) ) {
V_14 -> V_309 = V_17 ;
} else if ( ! strcmp ( V_72 , L_54 ) ) {
error = F_135 ( V_17 , V_152 ) ;
if ( error )
goto V_938;
V_14 -> V_428 = V_17 ;
} else if ( ! strcmp ( V_72 , L_55 ) ) {
V_14 -> V_429 = V_17 ;
} else if ( ! strcmp ( V_72 , L_50 ) ) {
error = - V_97 ;
if ( V_17 == 0 )
goto V_938;
error = - V_426 ;
if ( ! F_429 () ) {
error = F_162 ( V_14 -> V_17 , V_17 ) ;
if ( error )
goto V_938;
}
error = F_55 ( V_14 -> V_17 , V_17 , V_275 ,
V_939 , NULL ) ;
if ( error )
goto V_938;
V_438 = F_158 ( V_152 ) ;
if ( V_438 != 0 ) {
error = F_55 ( V_438 , V_17 , V_275 ,
V_375 , NULL ) ;
if ( error )
goto V_938;
}
V_14 -> V_17 = V_17 ;
} else {
error = - V_97 ;
goto V_938;
}
F_430 ( V_137 ) ;
return V_539 ;
V_938:
F_431 ( V_137 ) ;
return error ;
}
static int F_432 ( const char * V_72 )
{
return ( strcmp ( V_72 , V_510 ) == 0 ) ;
}
static int F_433 ( T_2 V_551 , char * * V_492 , T_2 * V_940 )
{
return F_71 ( V_551 , V_492 , V_940 ) ;
}
static int F_434 ( const char * V_492 , T_2 V_940 , T_2 * V_551 )
{
return F_236 ( V_492 , V_940 , V_551 , V_15 ) ;
}
static void F_435 ( char * V_492 , T_2 V_940 )
{
F_52 ( V_492 ) ;
}
static void F_436 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
F_77 ( & V_24 -> V_28 ) ;
V_24 -> V_38 = V_941 ;
F_81 ( & V_24 -> V_28 ) ;
}
static int F_437 ( struct V_22 * V_22 , void * V_317 , T_2 V_506 )
{
return F_249 ( V_22 , V_510 , V_317 , V_506 , 0 ) ;
}
static int F_438 ( struct V_34 * V_34 , void * V_317 , T_2 V_506 )
{
return F_439 ( V_34 , V_82 , V_317 , V_506 , 0 ) ;
}
static int F_440 ( struct V_22 * V_22 , void * * V_317 , T_2 * V_506 )
{
int V_95 = 0 ;
V_95 = F_247 ( V_22 , V_510 ,
V_317 , true ) ;
if ( V_95 < 0 )
return V_95 ;
* V_506 = V_95 ;
return 0 ;
}
static int F_441 ( struct V_858 * V_942 , const struct V_10 * V_10 ,
unsigned long V_86 )
{
const struct V_13 * V_14 ;
struct V_943 * V_944 ;
V_944 = F_15 ( sizeof( struct V_943 ) , V_15 ) ;
if ( ! V_944 )
return - V_27 ;
V_14 = V_10 -> V_19 ;
if ( V_14 -> V_428 )
V_944 -> V_17 = V_14 -> V_428 ;
else
V_944 -> V_17 = V_14 -> V_17 ;
V_942 -> V_19 = V_944 ;
return 0 ;
}
static void F_442 ( struct V_858 * V_942 )
{
struct V_943 * V_944 = V_942 -> V_19 ;
V_942 -> V_19 = NULL ;
F_52 ( V_944 ) ;
}
static int F_443 ( T_16 V_945 ,
const struct V_10 * V_10 ,
unsigned V_262 )
{
struct V_858 * V_858 ;
struct V_943 * V_944 ;
T_2 V_17 ;
if ( V_262 == 0 )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_858 = F_444 ( V_945 ) ;
V_944 = V_858 -> V_19 ;
return F_55 ( V_17 , V_944 -> V_17 , V_318 , V_262 , NULL ) ;
}
static int F_445 ( struct V_858 * V_858 , char * * V_946 )
{
struct V_943 * V_944 = V_858 -> V_19 ;
char * V_94 = NULL ;
unsigned V_95 ;
int V_61 ;
V_61 = F_71 ( V_944 -> V_17 , & V_94 , & V_95 ) ;
if ( ! V_61 )
V_61 = V_95 ;
* V_946 = V_94 ;
return V_61 ;
}
static T_1 int F_446 ( void )
{
if ( ! F_447 ( L_57 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_59 ( V_947 L_58 ) ;
return 0 ;
}
F_59 ( V_947 L_59 ) ;
F_14 () ;
V_580 = ! ( V_948 & V_595 ) ;
V_25 = F_448 ( L_60 ,
sizeof( struct V_23 ) ,
0 , V_949 , NULL ) ;
V_52 = F_448 ( L_61 ,
sizeof( struct V_50 ) ,
0 , V_949 , NULL ) ;
F_449 () ;
F_450 ( V_950 , F_61 ( V_950 ) ) ;
if ( F_451 ( F_9 , V_9 ) )
F_16 ( L_62 ) ;
if ( V_3 )
F_59 ( V_951 L_63 ) ;
else
F_59 ( V_951 L_64 ) ;
return 0 ;
}
static void F_452 ( struct V_55 * V_56 , void * V_952 )
{
F_88 ( V_56 , NULL ) ;
}
void F_453 ( void )
{
F_59 ( V_951 L_65 ) ;
F_59 ( V_951 L_66 ) ;
F_454 ( F_452 , NULL ) ;
}
static int T_1 F_455 ( void )
{
int V_609 ;
if ( ! V_5 )
return 0 ;
F_59 ( V_951 L_67 ) ;
V_609 = F_456 ( V_953 , F_61 ( V_953 ) ) ;
if ( V_609 )
F_16 ( L_68 , V_609 ) ;
return 0 ;
}
static void F_457 ( void )
{
F_59 ( V_951 L_69 ) ;
F_458 ( V_953 , F_61 ( V_953 ) ) ;
}
int F_459 ( void )
{
if ( V_37 ) {
return - V_97 ;
}
if ( V_954 ) {
return - V_97 ;
}
F_59 ( V_947 L_70 ) ;
V_954 = 1 ;
V_5 = 0 ;
F_460 ( V_950 , F_61 ( V_950 ) ) ;
F_461 () ;
F_457 () ;
F_462 () ;
return 0 ;
}
