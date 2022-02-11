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
if ( V_56 -> V_128 != & V_129 ) {
if ( V_117 || V_116 || V_118 ||
V_119 ) {
V_61 = - V_130 ;
goto V_81;
}
if ( V_45 -> V_66 == V_67 ) {
V_45 -> V_66 = V_131 ;
V_61 = F_79 ( F_22 () , F_22 () ,
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
F_80 ( & V_45 -> V_28 ) ;
return V_61 ;
V_124:
V_61 = - V_97 ;
F_59 ( V_78 L_20
L_21 , V_56 -> V_79 , V_72 ) ;
goto V_81;
}
static int F_81 ( const struct V_55 * V_134 ,
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
static int F_82 ( const struct V_55 * V_134 ,
struct V_55 * V_135 )
{
const struct V_44 * V_144 = V_134 -> V_47 ;
struct V_44 * V_145 = V_135 -> V_47 ;
int V_146 = ( V_144 -> V_86 & V_105 ) ;
int V_147 = ( V_144 -> V_86 & V_106 ) ;
int V_148 = ( V_144 -> V_86 & V_108 ) ;
if ( ! V_37 )
return 0 ;
F_71 ( ! ( V_144 -> V_86 & V_87 ) ) ;
if ( V_145 -> V_86 & V_87 )
return F_81 ( V_134 , V_135 ) ;
F_76 ( & V_145 -> V_28 ) ;
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
F_80 ( & V_145 -> V_28 ) ;
return 0 ;
}
static int F_83 ( char * V_151 ,
struct V_91 * V_92 )
{
char * V_152 ;
char * V_94 = NULL , * V_153 = NULL ;
char * V_154 = NULL , * V_155 = NULL ;
int V_61 , V_100 = 0 ;
V_92 -> V_100 = 0 ;
while ( ( V_152 = F_84 ( & V_151 , L_25 ) ) != NULL ) {
int V_156 ;
T_3 args [ V_157 ] ;
if ( ! * V_152 )
continue;
V_156 = F_85 ( V_152 , V_158 , args ) ;
switch ( V_156 ) {
case V_159 :
if ( V_94 || V_153 ) {
V_61 = - V_97 ;
F_59 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_160;
}
V_94 = F_86 ( & args [ 0 ] ) ;
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
V_154 = F_86 ( & args [ 0 ] ) ;
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
V_155 = F_86 ( & args [ 0 ] ) ;
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
V_153 = F_86 ( & args [ 0 ] ) ;
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
V_92 -> V_101 = F_69 ( V_99 , sizeof( char * ) , V_102 ) ;
if ( ! V_92 -> V_101 )
goto V_160;
V_92 -> V_104 = F_69 ( V_99 , sizeof( int ) , V_102 ) ;
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
static int F_87 ( struct V_55 * V_56 , void * V_165 )
{
int V_61 = 0 ;
char * V_151 = V_165 ;
struct V_91 V_92 ;
F_67 ( & V_92 ) ;
if ( ! V_165 )
goto V_81;
F_71 ( V_56 -> V_71 -> V_122 & V_123 ) ;
V_61 = F_83 ( V_151 , & V_92 ) ;
if ( V_61 )
goto V_160;
V_81:
V_61 = F_74 ( V_56 , & V_92 , 0 , NULL ) ;
V_160:
F_72 ( & V_92 ) ;
return V_61 ;
}
static void F_88 ( struct V_166 * V_167 ,
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
F_89 ( V_167 , ',' ) ;
F_90 ( V_167 , V_174 ) ;
continue;
default:
F_91 () ;
return;
} ;
F_89 ( V_167 , ',' ) ;
F_90 ( V_167 , V_168 ) ;
if ( V_169 )
F_89 ( V_167 , '\"' ) ;
F_92 ( V_167 , V_92 -> V_101 [ V_93 ] , L_27 ) ;
if ( V_169 )
F_89 ( V_167 , '\"' ) ;
}
}
static int F_93 ( struct V_166 * V_167 , struct V_55 * V_56 )
{
struct V_91 V_92 ;
int V_61 ;
V_61 = F_66 ( V_56 , & V_92 ) ;
if ( V_61 ) {
if ( V_61 == - V_97 )
V_61 = 0 ;
return V_61 ;
}
F_88 ( V_167 , & V_92 ) ;
F_72 ( & V_92 ) ;
return V_61 ;
}
static inline T_4 F_94 ( T_5 V_175 )
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
static inline int F_95 ( int V_190 )
{
return ( V_190 == V_191 || V_190 == V_192 ) ;
}
static inline int F_96 ( int V_190 )
{
return ( V_190 == V_191 || V_190 == V_193 ) ;
}
static inline T_4 F_97 ( int V_194 , int type , int V_190 )
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
if ( F_95 ( V_190 ) )
return V_203 ;
else
return V_204 ;
case V_199 :
if ( F_96 ( V_190 ) )
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
static int F_98 ( struct V_34 * V_34 ,
T_4 V_249 ,
T_4 V_86 ,
T_2 * V_17 )
{
int V_61 ;
struct V_55 * V_56 = V_34 -> V_250 ;
char * V_251 , * V_252 ;
V_251 = ( char * ) F_99 ( V_15 ) ;
if ( ! V_251 )
return - V_27 ;
V_252 = F_100 ( V_34 , V_251 , V_253 ) ;
if ( F_101 ( V_252 ) )
V_61 = F_102 ( V_252 ) ;
else {
if ( V_86 & V_125 ) {
while ( V_252 [ 1 ] >= '0' && V_252 [ 1 ] <= '9' ) {
V_252 [ 1 ] = '/' ;
V_252 ++ ;
}
}
V_61 = F_103 ( V_56 -> V_71 -> V_72 , V_252 , V_249 , V_17 ) ;
}
F_104 ( ( unsigned long ) V_251 ) ;
return V_61 ;
}
static int F_30 ( struct V_22 * V_22 , struct V_34 * V_35 )
{
struct V_44 * V_45 = NULL ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 ;
struct V_34 * V_34 ;
#define F_105 255
char * V_94 = NULL ;
unsigned V_95 = 0 ;
int V_61 = 0 ;
if ( V_24 -> V_38 == V_39 )
goto V_81;
F_76 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_38 == V_39 )
goto V_254;
V_45 = V_22 -> V_46 -> V_47 ;
if ( ! ( V_45 -> V_86 & V_87 ) ) {
F_43 ( & V_45 -> V_48 ) ;
if ( F_61 ( & V_24 -> V_29 ) )
F_106 ( & V_24 -> V_29 , & V_45 -> V_57 ) ;
F_45 ( & V_45 -> V_48 ) ;
goto V_254;
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
V_34 = F_107 ( V_35 ) ;
} else {
V_34 = F_108 ( V_22 ) ;
}
if ( ! V_34 ) {
goto V_254;
}
V_95 = F_105 ;
V_94 = F_109 ( V_95 + 1 , V_26 ) ;
if ( ! V_94 ) {
V_61 = - V_27 ;
F_110 ( V_34 ) ;
goto V_254;
}
V_94 [ V_95 ] = '\0' ;
V_61 = V_22 -> V_76 -> V_77 ( V_34 , V_22 , V_82 ,
V_94 , V_95 ) ;
if ( V_61 == - V_255 ) {
F_52 ( V_94 ) ;
V_61 = V_22 -> V_76 -> V_77 ( V_34 , V_22 , V_82 ,
NULL , 0 ) ;
if ( V_61 < 0 ) {
F_110 ( V_34 ) ;
goto V_254;
}
V_95 = V_61 ;
V_94 = F_109 ( V_95 + 1 , V_26 ) ;
if ( ! V_94 ) {
V_61 = - V_27 ;
F_110 ( V_34 ) ;
goto V_254;
}
V_94 [ V_95 ] = '\0' ;
V_61 = V_22 -> V_76 -> V_77 ( V_34 , V_22 ,
V_82 ,
V_94 , V_95 ) ;
}
F_110 ( V_34 ) ;
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
V_61 = F_111 ( V_94 , V_61 , & V_17 ,
V_45 -> V_58 ,
V_26 ) ;
if ( V_61 ) {
char * V_257 = V_22 -> V_46 -> V_79 ;
unsigned long V_258 = V_22 -> V_256 ;
if ( V_61 == - V_97 ) {
if ( F_112 () )
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
V_24 -> V_31 = F_94 ( V_22 -> V_260 ) ;
V_61 = F_79 ( V_24 -> F_18 , V_45 -> V_17 ,
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
if ( ( V_45 -> V_86 & V_126 ) && ! F_113 ( V_22 -> V_260 ) ) {
if ( V_35 )
V_34 = F_107 ( V_35 ) ;
else
V_34 = F_108 ( V_22 ) ;
if ( ! V_34 )
goto V_254;
V_24 -> V_31 = F_94 ( V_22 -> V_260 ) ;
V_61 = F_98 ( V_34 , V_24 -> V_31 ,
V_45 -> V_86 , & V_17 ) ;
F_110 ( V_34 ) ;
if ( V_61 )
goto V_254;
V_24 -> V_17 = V_17 ;
}
break;
}
V_24 -> V_38 = V_39 ;
V_254:
F_80 ( & V_24 -> V_28 ) ;
V_81:
if ( V_24 -> V_31 == V_32 )
V_24 -> V_31 = F_94 ( V_22 -> V_260 ) ;
return V_61 ;
}
static inline T_2 F_114 ( int V_261 )
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
static int F_115 ( const struct V_10 * V_270 ,
const struct V_10 * V_271 ,
T_2 V_272 )
{
T_2 V_273 = F_17 ( V_270 ) , V_274 = F_17 ( V_271 ) ;
return F_55 ( V_273 , V_274 , V_275 , V_272 , NULL ) ;
}
static int F_116 ( const struct V_20 * V_276 ,
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
static int F_117 ( const struct V_20 * V_282 ,
T_2 V_272 )
{
T_2 V_17 , V_274 ;
V_17 = F_22 () ;
V_274 = F_18 ( V_282 ) ;
return F_55 ( V_17 , V_274 , V_275 , V_272 , NULL ) ;
}
static int F_118 ( const struct V_10 * V_10 ,
int V_283 , int V_284 , bool V_285 )
{
struct V_286 V_287 ;
struct V_288 V_289 ;
T_4 V_31 ;
T_2 V_17 = F_17 ( V_10 ) ;
T_2 V_290 = F_119 ( V_283 ) ;
int V_61 ;
V_287 . type = V_291 ;
V_287 . V_292 . V_283 = V_283 ;
switch ( F_120 ( V_283 ) ) {
case 0 :
V_31 = V_285 ? V_293 : V_294 ;
break;
case 1 :
V_31 = V_285 ? V_295 : V_296 ;
break;
default:
F_59 ( V_85
L_35 , V_283 ) ;
F_91 () ;
return - V_97 ;
}
V_61 = F_121 ( V_17 , V_17 , V_31 , V_290 , 0 , & V_289 ) ;
if ( V_284 == V_297 ) {
int V_298 = F_122 ( V_17 , V_17 , V_31 , V_290 , & V_289 , V_61 , & V_287 , 0 ) ;
if ( V_298 )
return V_298 ;
}
return V_61 ;
}
static int F_123 ( struct V_20 * V_282 ,
T_2 V_272 )
{
T_2 V_17 = F_18 ( V_282 ) ;
return F_55 ( V_17 , V_18 ,
V_299 , V_272 , NULL ) ;
}
static int F_124 ( const struct V_10 * V_10 ,
struct V_22 * V_22 ,
T_2 V_272 ,
struct V_286 * V_300 )
{
struct V_23 * V_24 ;
T_2 V_17 ;
F_125 ( V_10 ) ;
if ( F_126 ( F_64 ( V_22 ) ) )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
return F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_272 , V_300 ) ;
}
static inline int F_127 ( const struct V_10 * V_10 ,
struct V_34 * V_34 ,
T_2 V_290 )
{
struct V_22 * V_22 = F_36 ( V_34 ) ;
struct V_286 V_287 ;
V_287 . type = V_301 ;
V_287 . V_292 . V_34 = V_34 ;
F_28 ( V_22 , V_34 , true ) ;
return F_124 ( V_10 , V_22 , V_290 , & V_287 ) ;
}
static inline int F_128 ( const struct V_10 * V_10 ,
const struct V_252 * V_252 ,
T_2 V_290 )
{
struct V_22 * V_22 = F_36 ( V_252 -> V_34 ) ;
struct V_286 V_287 ;
V_287 . type = V_302 ;
V_287 . V_292 . V_252 = * V_252 ;
F_28 ( V_22 , V_252 -> V_34 , true ) ;
return F_124 ( V_10 , V_22 , V_290 , & V_287 ) ;
}
static inline int F_129 ( const struct V_10 * V_10 ,
struct V_49 * V_49 ,
T_2 V_290 )
{
struct V_286 V_287 ;
V_287 . type = V_302 ;
V_287 . V_292 . V_252 = V_49 -> V_303 ;
return F_124 ( V_10 , F_130 ( V_49 ) , V_290 , & V_287 ) ;
}
static int F_131 ( const struct V_10 * V_10 ,
struct V_49 * V_49 ,
T_2 V_290 )
{
struct V_50 * V_51 = V_49 -> V_54 ;
struct V_22 * V_22 = F_130 ( V_49 ) ;
struct V_286 V_287 ;
T_2 V_17 = F_17 ( V_10 ) ;
int V_61 ;
V_287 . type = V_302 ;
V_287 . V_292 . V_252 = V_49 -> V_303 ;
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
V_61 = F_124 ( V_10 , V_22 , V_290 , & V_287 ) ;
V_81:
return V_61 ;
}
static int F_132 ( struct V_22 * V_306 ,
const struct V_307 * V_72 ,
T_4 V_249 ,
T_2 * V_308 )
{
const struct V_44 * V_45 = V_306 -> V_46 -> V_47 ;
const struct V_13 * V_14 = F_23 () ;
if ( ( V_45 -> V_86 & V_87 ) &&
( V_45 -> V_66 == V_131 ) ) {
* V_308 = V_45 -> V_60 ;
} else if ( ( V_45 -> V_86 & V_88 ) &&
V_14 -> V_309 ) {
* V_308 = V_14 -> V_309 ;
} else {
const struct V_23 * V_310 = F_34 ( V_306 ) ;
return F_79 ( V_14 -> V_17 , V_310 -> V_17 , V_249 ,
V_72 , V_308 ) ;
}
return 0 ;
}
static int F_133 ( struct V_22 * V_306 ,
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
V_61 = F_132 ( V_306 , & V_34 -> V_314 , V_249 ,
& V_311 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_55 ( V_17 , V_311 , V_249 , V_315 , & V_287 ) ;
if ( V_61 )
return V_61 ;
return F_55 ( V_311 , V_45 -> V_17 ,
V_62 ,
V_65 , & V_287 ) ;
}
static int F_134 ( T_2 V_316 ,
struct V_20 * V_317 )
{
T_2 V_17 = F_18 ( V_317 ) ;
return F_55 ( V_17 , V_316 , V_318 , V_319 , NULL ) ;
}
static int F_135 ( struct V_22 * V_306 ,
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
static inline int F_136 ( struct V_22 * V_328 ,
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
V_336 = F_137 ( V_329 ) ;
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
if ( F_138 ( V_331 ) )
V_290 |= V_321 ;
V_61 = F_55 ( V_17 , V_333 -> V_17 , V_185 , V_290 , & V_287 ) ;
if ( V_61 )
return V_61 ;
if ( F_138 ( V_331 ) ) {
V_335 = F_37 ( V_331 ) ;
V_337 = F_137 ( V_331 ) ;
V_61 = F_55 ( V_17 , V_335 -> V_17 ,
V_335 -> V_31 ,
( V_337 ? V_327 : V_325 ) , & V_287 ) ;
if ( V_61 )
return V_61 ;
}
return 0 ;
}
static int F_139 ( const struct V_10 * V_10 ,
struct V_55 * V_56 ,
T_2 V_272 ,
struct V_286 * V_287 )
{
struct V_44 * V_45 ;
T_2 V_17 = F_17 ( V_10 ) ;
V_45 = V_56 -> V_47 ;
return F_55 ( V_17 , V_45 -> V_17 , V_62 , V_272 , V_287 ) ;
}
static inline T_2 F_140 ( int V_175 , int V_340 )
{
T_2 V_290 = 0 ;
if ( ! F_141 ( V_175 ) ) {
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
static inline T_2 F_142 ( struct V_49 * V_49 )
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
static inline T_2 F_143 ( struct V_49 * V_49 )
{
T_2 V_290 = F_142 ( V_49 ) ;
if ( V_357 )
V_290 |= V_358 ;
return V_290 ;
}
static int F_144 ( struct V_20 * V_359 )
{
T_2 V_360 = F_22 () ;
T_2 V_361 = F_18 ( V_359 ) ;
return F_55 ( V_360 , V_361 , V_362 ,
V_363 , NULL ) ;
}
static int F_145 ( struct V_20 * V_364 ,
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
static int F_146 ( struct V_20 * V_364 ,
struct V_20 * V_365 )
{
T_2 V_366 = F_18 ( V_364 ) ;
T_2 V_367 = F_18 ( V_365 ) ;
return F_55 ( V_366 , V_367 , V_362 , V_370 ,
NULL ) ;
}
static int F_147 ( struct V_20 * V_364 ,
struct V_20 * V_365 ,
struct V_49 * V_49 )
{
T_2 V_17 = F_18 ( V_365 ) ;
struct V_50 * V_51 = V_49 -> V_54 ;
struct V_34 * V_34 = V_49 -> V_303 . V_34 ;
struct V_23 * V_24 ;
struct V_286 V_287 ;
int V_61 ;
V_287 . type = V_302 ;
V_287 . V_292 . V_252 = V_49 -> V_303 ;
if ( V_17 != V_51 -> V_17 ) {
V_61 = F_55 ( V_17 , V_51 -> V_17 ,
V_304 ,
V_305 ,
& V_287 ) ;
if ( V_61 )
return V_61 ;
}
if ( F_126 ( F_64 ( F_36 ( V_34 ) ) ) )
return 0 ;
V_24 = F_37 ( V_34 ) ;
return F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , F_142 ( V_49 ) ,
& V_287 ) ;
}
static int F_148 ( struct V_20 * V_371 ,
unsigned int V_175 )
{
if ( V_175 & V_372 ) {
T_2 V_17 = F_22 () ;
T_2 V_373 = F_18 ( V_371 ) ;
return F_55 ( V_17 , V_373 , V_32 , V_344 , NULL ) ;
}
return F_117 ( V_371 , V_374 ) ;
}
static int F_149 ( struct V_20 * V_375 )
{
return F_116 ( V_375 , V_11 , V_374 ) ;
}
static int F_150 ( struct V_20 * V_271 , T_6 * V_376 ,
T_6 * V_377 , T_6 * V_378 )
{
return F_117 ( V_271 , V_379 ) ;
}
static int F_151 ( struct V_10 * V_137 , const struct V_10 * V_136 ,
const T_6 * V_376 ,
const T_6 * V_377 ,
const T_6 * V_378 )
{
return F_115 ( V_136 , V_137 , V_380 ) ;
}
static int F_152 ( const struct V_10 * V_10 , struct V_381 * V_382 ,
int V_283 , int V_284 )
{
return F_118 ( V_10 , V_283 , V_284 , V_382 == & V_129 ) ;
}
static int F_153 ( int V_383 , int type , int V_384 , struct V_55 * V_56 )
{
const struct V_10 * V_10 = F_75 () ;
int V_61 = 0 ;
if ( ! V_56 )
return 0 ;
switch ( V_383 ) {
case V_385 :
case V_386 :
case V_387 :
case V_388 :
case V_389 :
V_61 = F_139 ( V_10 , V_56 , V_390 , NULL ) ;
break;
case V_391 :
case V_392 :
case V_393 :
V_61 = F_139 ( V_10 , V_56 , V_394 , NULL ) ;
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
return F_127 ( V_10 , V_34 , V_395 ) ;
}
static int F_155 ( int type )
{
int V_61 ;
switch ( type ) {
case V_396 :
case V_397 :
V_61 = F_123 ( V_11 , V_398 ) ;
break;
case V_399 :
case V_400 :
case V_401 :
V_61 = F_123 ( V_11 , V_402 ) ;
break;
case V_403 :
case V_404 :
case V_405 :
case V_406 :
case V_407 :
default:
V_61 = F_123 ( V_11 , V_408 ) ;
break;
}
return V_61 ;
}
static int F_156 ( struct V_409 * V_410 , long V_411 )
{
int V_61 , V_412 = 0 ;
V_61 = F_118 ( F_75 () , V_413 ,
V_414 , true ) ;
if ( V_61 == 0 )
V_412 = 1 ;
return V_412 ;
}
static T_2 F_157 ( struct V_20 * V_21 )
{
T_2 V_17 = 0 ;
struct V_20 * V_415 ;
F_19 () ;
V_415 = F_158 ( V_21 ) ;
if ( V_415 )
V_17 = F_18 ( V_415 ) ;
F_21 () ;
return V_17 ;
}
static int F_159 ( const struct V_416 * V_417 ,
const struct V_13 * V_418 ,
const struct V_13 * V_419 )
{
int V_420 = ( V_417 -> V_421 & V_422 ) ;
int V_423 = ! F_160 ( V_417 -> V_49 -> V_303 . V_424 ) ;
int V_61 ;
if ( ! V_420 && ! V_423 )
return 0 ;
if ( V_419 -> V_17 == V_418 -> V_17 )
return 0 ;
V_61 = F_161 ( V_418 -> V_17 , V_419 -> V_17 ) ;
if ( V_61 ) {
if ( V_420 )
return - V_425 ;
else
return - V_130 ;
}
return 0 ;
}
static int F_162 ( struct V_416 * V_417 )
{
const struct V_13 * V_418 ;
struct V_13 * V_419 ;
struct V_23 * V_24 ;
struct V_286 V_287 ;
struct V_22 * V_22 = F_130 ( V_417 -> V_49 ) ;
int V_61 ;
if ( V_417 -> V_426 )
return 0 ;
V_418 = F_23 () ;
V_419 = V_417 -> V_10 -> V_19 ;
V_24 = F_34 ( V_22 ) ;
V_419 -> V_17 = V_418 -> V_17 ;
V_419 -> V_16 = V_418 -> V_17 ;
V_419 -> V_309 = 0 ;
V_419 -> V_427 = 0 ;
V_419 -> V_428 = 0 ;
if ( V_418 -> V_429 ) {
V_419 -> V_17 = V_418 -> V_429 ;
V_419 -> V_429 = 0 ;
V_61 = F_159 ( V_417 , V_418 , V_419 ) ;
if ( V_61 )
return V_61 ;
} else {
V_61 = F_79 ( V_418 -> V_17 , V_24 -> V_17 ,
V_275 , NULL ,
& V_419 -> V_17 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_159 ( V_417 , V_418 , V_419 ) ;
if ( V_61 )
V_419 -> V_17 = V_418 -> V_17 ;
}
V_287 . type = V_302 ;
V_287 . V_292 . V_252 = V_417 -> V_49 -> V_303 ;
if ( V_419 -> V_17 == V_418 -> V_17 ) {
V_61 = F_55 ( V_418 -> V_17 , V_24 -> V_17 ,
V_32 , V_430 , & V_287 ) ;
if ( V_61 )
return V_61 ;
} else {
V_61 = F_55 ( V_418 -> V_17 , V_419 -> V_17 ,
V_275 , V_431 , & V_287 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_55 ( V_419 -> V_17 , V_24 -> V_17 ,
V_32 , V_432 , & V_287 ) ;
if ( V_61 )
return V_61 ;
if ( V_417 -> V_421 & V_433 ) {
V_61 = F_55 ( V_418 -> V_17 , V_419 -> V_17 ,
V_275 , V_434 ,
NULL ) ;
if ( V_61 )
return - V_425 ;
}
if ( V_417 -> V_421 &
( V_435 | V_436 ) ) {
T_2 V_437 = F_157 ( V_11 ) ;
if ( V_437 != 0 ) {
V_61 = F_55 ( V_437 , V_419 -> V_17 ,
V_275 ,
V_374 , NULL ) ;
if ( V_61 )
return - V_425 ;
}
}
V_417 -> V_438 |= V_439 ;
}
return 0 ;
}
static int F_163 ( struct V_416 * V_417 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_17 , V_16 ;
int V_440 = 0 ;
V_17 = V_14 -> V_17 ;
V_16 = V_14 -> V_16 ;
if ( V_16 != V_17 ) {
V_440 = F_55 ( V_16 , V_17 ,
V_275 ,
V_441 , NULL ) ;
}
return ! ! V_440 ;
}
static int F_164 ( const void * V_152 , struct V_49 * V_49 , unsigned V_442 )
{
return F_131 ( V_152 , V_49 , F_142 ( V_49 ) ) ? V_442 + 1 : 0 ;
}
static inline void F_165 ( const struct V_10 * V_10 ,
struct V_443 * V_444 )
{
struct V_49 * V_49 , * V_445 = NULL ;
struct V_446 * V_447 ;
int V_448 = 0 ;
unsigned V_449 ;
V_447 = F_166 () ;
if ( V_447 ) {
F_43 ( & V_447 -> V_450 ) ;
if ( ! F_61 ( & V_447 -> V_451 ) ) {
struct V_452 * V_453 ;
V_453 = F_167 ( & V_447 -> V_451 ,
struct V_452 , V_29 ) ;
V_49 = V_453 -> V_49 ;
if ( F_129 ( V_10 , V_49 , V_344 | V_348 ) )
V_448 = 1 ;
}
F_45 ( & V_447 -> V_450 ) ;
F_168 ( V_447 ) ;
}
if ( V_448 )
F_169 () ;
V_449 = F_170 ( V_444 , 0 , F_164 , V_10 ) ;
if ( ! V_449 )
return;
V_445 = F_171 ( & V_454 , V_455 , V_10 ) ;
if ( F_101 ( V_445 ) )
V_445 = NULL ;
do {
F_172 ( V_449 - 1 , V_445 , 0 ) ;
} while ( ( V_449 = F_170 ( V_444 , V_449 , F_164 , V_10 ) ) != 0 );
if ( V_445 )
F_173 ( V_445 ) ;
}
static void F_174 ( struct V_416 * V_417 )
{
struct V_13 * V_419 ;
struct V_456 * V_457 , * V_458 ;
int V_61 , V_93 ;
V_419 = V_417 -> V_10 -> V_19 ;
if ( V_419 -> V_17 == V_419 -> V_16 )
return;
F_165 ( V_417 -> V_10 , V_11 -> V_444 ) ;
V_11 -> V_459 = 0 ;
V_61 = F_55 ( V_419 -> V_16 , V_419 -> V_17 , V_275 ,
V_460 , NULL ) ;
if ( V_61 ) {
F_175 ( V_11 ) ;
for ( V_93 = 0 ; V_93 < V_461 ; V_93 ++ ) {
V_457 = V_11 -> signal -> V_457 + V_93 ;
V_458 = V_462 . signal -> V_457 + V_93 ;
V_457 -> V_463 = F_176 ( V_457 -> V_464 , V_458 -> V_463 ) ;
}
F_177 ( V_11 ) ;
F_178 ( V_11 , V_456 ( V_465 ) ) ;
}
}
static void F_179 ( struct V_416 * V_417 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_466 V_467 ;
T_2 V_16 , V_17 ;
int V_61 , V_93 ;
V_16 = V_14 -> V_16 ;
V_17 = V_14 -> V_17 ;
if ( V_17 == V_16 )
return;
V_61 = F_55 ( V_16 , V_17 , V_275 , V_468 , NULL ) ;
if ( V_61 ) {
memset ( & V_467 , 0 , sizeof V_467 ) ;
for ( V_93 = 0 ; V_93 < 3 ; V_93 ++ )
F_180 ( V_93 , & V_467 , NULL ) ;
F_181 ( & V_11 -> V_469 -> V_470 ) ;
if ( ! F_182 ( V_11 ) ) {
F_183 ( & V_11 -> V_471 ) ;
F_183 ( & V_11 -> signal -> V_472 ) ;
F_184 ( V_11 , 1 ) ;
F_185 ( & V_11 -> V_473 ) ;
F_186 () ;
}
F_187 ( & V_11 -> V_469 -> V_470 ) ;
}
F_188 ( & V_474 ) ;
F_189 ( V_11 , V_11 -> V_475 ) ;
F_190 ( & V_474 ) ;
}
static int F_191 ( struct V_55 * V_56 )
{
return F_49 ( V_56 ) ;
}
static void F_192 ( struct V_55 * V_56 )
{
F_51 ( V_56 ) ;
}
static inline int F_193 ( char * V_168 , int V_476 , char * V_477 , int V_478 )
{
if ( V_476 > V_478 )
return 0 ;
return ! memcmp ( V_168 , V_477 , V_476 ) ;
}
static inline int F_194 ( char * V_477 , int V_95 )
{
return ( F_193 ( V_170 , sizeof( V_170 ) - 1 , V_477 , V_95 ) ||
F_193 ( V_171 , sizeof( V_171 ) - 1 , V_477 , V_95 ) ||
F_193 ( V_173 , sizeof( V_173 ) - 1 , V_477 , V_95 ) ||
F_193 ( V_172 , sizeof( V_172 ) - 1 , V_477 , V_95 ) ||
F_193 ( V_174 , sizeof( V_174 ) - 1 , V_477 , V_95 ) ) ;
}
static inline void F_195 ( char * * V_365 , char * V_364 , int * V_479 , int V_95 )
{
if ( ! * V_479 ) {
* * V_365 = ',' ;
* V_365 += 1 ;
} else
* V_479 = 0 ;
memcpy ( * V_365 , V_364 , V_95 ) ;
* V_365 += V_95 ;
}
static inline void F_196 ( char * * V_365 , char * V_364 , int * V_479 ,
int V_95 )
{
int V_480 = 0 ;
if ( ! * V_479 ) {
* * V_365 = '|' ;
* V_365 += 1 ;
} else
* V_479 = 0 ;
while ( V_480 < V_95 ) {
if ( * V_364 != '"' ) {
* * V_365 = * V_364 ;
* V_365 += 1 ;
}
V_364 += 1 ;
V_480 += 1 ;
}
}
static int F_197 ( char * V_481 , char * V_482 )
{
int V_483 , V_51 , V_61 = 0 ;
char * V_484 , * V_485 , * V_486 ;
char * V_487 , * V_488 , * V_489 ;
int V_490 = 0 ;
V_485 = V_481 ;
V_487 = V_482 ;
V_489 = ( char * ) F_198 ( V_15 ) ;
if ( ! V_489 ) {
V_61 = - V_27 ;
goto V_81;
}
V_488 = V_489 ;
V_483 = V_51 = 1 ;
V_484 = V_486 = V_481 ;
do {
if ( * V_486 == '"' )
V_490 = ! V_490 ;
if ( ( * V_486 == ',' && V_490 == 0 ) ||
* V_486 == '\0' ) {
int V_95 = V_486 - V_485 ;
if ( F_194 ( V_485 , V_95 ) )
F_196 ( & V_487 , V_485 , & V_51 , V_95 ) ;
else
F_195 ( & V_489 , V_485 , & V_483 , V_95 ) ;
V_485 = V_486 + 1 ;
}
} while ( * V_486 ++ );
strcpy ( V_484 , V_488 ) ;
F_104 ( ( unsigned long ) V_488 ) ;
V_81:
return V_61 ;
}
static int F_199 ( struct V_55 * V_56 , void * V_165 )
{
int V_61 , V_93 , * V_86 ;
struct V_91 V_92 ;
char * V_491 , * * V_120 ;
struct V_44 * V_45 = V_56 -> V_47 ;
if ( ! ( V_45 -> V_86 & V_87 ) )
return 0 ;
if ( ! V_165 )
return 0 ;
if ( V_56 -> V_71 -> V_122 & V_123 )
return 0 ;
F_67 ( & V_92 ) ;
V_491 = F_200 () ;
if ( ! V_491 )
return - V_27 ;
V_61 = F_197 ( V_165 , V_491 ) ;
if ( V_61 )
goto V_492;
V_61 = F_83 ( V_491 , & V_92 ) ;
if ( V_61 )
goto V_492;
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
goto V_493;
}
V_61 = - V_97 ;
switch ( V_86 [ V_93 ] ) {
case V_105 :
if ( F_73 ( V_45 , V_105 , V_45 -> V_17 , V_17 ) )
goto V_494;
break;
case V_106 :
if ( F_73 ( V_45 , V_106 , V_45 -> V_60 , V_17 ) )
goto V_494;
break;
case V_108 : {
struct V_23 * V_115 ;
V_115 = F_37 ( V_56 -> V_74 ) ;
if ( F_73 ( V_45 , V_108 , V_115 -> V_17 , V_17 ) )
goto V_494;
break;
}
case V_107 :
if ( F_73 ( V_45 , V_107 , V_45 -> V_58 , V_17 ) )
goto V_494;
break;
default:
goto V_493;
}
}
V_61 = 0 ;
V_493:
F_72 ( & V_92 ) ;
V_492:
F_201 ( V_491 ) ;
return V_61 ;
V_494:
F_59 ( V_78 L_37
L_38 , V_56 -> V_79 ,
V_56 -> V_71 -> V_72 ) ;
goto V_493;
}
static int F_202 ( struct V_55 * V_56 , int V_86 , void * V_165 )
{
const struct V_10 * V_10 = F_75 () ;
struct V_286 V_287 ;
int V_61 ;
V_61 = F_87 ( V_56 , V_165 ) ;
if ( V_61 )
return V_61 ;
if ( V_86 & V_495 )
return 0 ;
V_287 . type = V_301 ;
V_287 . V_292 . V_34 = V_56 -> V_74 ;
return F_139 ( V_10 , V_56 , V_496 , & V_287 ) ;
}
static int F_203 ( struct V_34 * V_34 )
{
const struct V_10 * V_10 = F_75 () ;
struct V_286 V_287 ;
V_287 . type = V_301 ;
V_287 . V_292 . V_34 = V_34 -> V_250 -> V_74 ;
return F_139 ( V_10 , V_34 -> V_250 , V_497 , & V_287 ) ;
}
static int F_204 ( const char * V_498 ,
const struct V_252 * V_252 ,
const char * type ,
unsigned long V_86 ,
void * V_165 )
{
const struct V_10 * V_10 = F_75 () ;
if ( V_86 & V_499 )
return F_139 ( V_10 , V_252 -> V_34 -> V_250 ,
V_500 , NULL ) ;
else
return F_128 ( V_10 , V_252 , V_501 ) ;
}
static int F_205 ( struct V_502 * V_424 , int V_86 )
{
const struct V_10 * V_10 = F_75 () ;
return F_139 ( V_10 , V_424 -> V_503 ,
V_504 , NULL ) ;
}
static int F_206 ( struct V_22 * V_22 )
{
return F_24 ( V_22 ) ;
}
static void F_207 ( struct V_22 * V_22 )
{
F_41 ( V_22 ) ;
}
static int F_208 ( struct V_34 * V_34 , int V_175 ,
const struct V_307 * V_72 , void * * V_317 ,
T_2 * V_505 )
{
T_2 V_311 ;
int V_61 ;
V_61 = F_132 ( F_209 ( V_34 -> V_506 ) , V_72 ,
F_94 ( V_175 ) ,
& V_311 ) ;
if ( V_61 )
return V_61 ;
return F_70 ( V_311 , ( char * * ) V_317 , V_505 ) ;
}
static int F_210 ( struct V_22 * V_22 , struct V_22 * V_306 ,
const struct V_307 * V_307 ,
const char * * V_72 ,
void * * V_507 , T_7 * V_95 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_44 * V_45 ;
T_2 V_17 , V_311 , V_508 ;
int V_61 ;
char * V_94 ;
V_45 = V_306 -> V_46 -> V_47 ;
V_17 = V_14 -> V_17 ;
V_311 = V_14 -> V_309 ;
V_61 = F_132 (
V_306 , V_307 ,
F_94 ( V_22 -> V_260 ) ,
& V_311 ) ;
if ( V_61 )
return V_61 ;
if ( V_45 -> V_86 & V_87 ) {
struct V_23 * V_24 = V_22 -> V_33 ;
V_24 -> V_31 = F_94 ( V_22 -> V_260 ) ;
V_24 -> V_17 = V_311 ;
V_24 -> V_38 = V_39 ;
}
if ( ! V_37 || ! ( V_45 -> V_86 & V_88 ) )
return - V_80 ;
if ( V_72 )
* V_72 = V_509 ;
if ( V_507 && V_95 ) {
V_61 = F_211 ( V_311 , & V_94 , & V_508 ) ;
if ( V_61 )
return V_61 ;
* V_507 = V_94 ;
* V_95 = V_508 ;
}
return 0 ;
}
static int F_212 ( struct V_22 * V_306 , struct V_34 * V_34 , T_5 V_175 )
{
return F_133 ( V_306 , V_34 , V_32 ) ;
}
static int F_213 ( struct V_34 * V_329 , struct V_22 * V_306 , struct V_34 * V_331 )
{
return F_135 ( V_306 , V_329 , V_322 ) ;
}
static int F_214 ( struct V_22 * V_306 , struct V_34 * V_34 )
{
return F_135 ( V_306 , V_34 , V_324 ) ;
}
static int F_215 ( struct V_22 * V_306 , struct V_34 * V_34 , const char * V_72 )
{
return F_133 ( V_306 , V_34 , V_180 ) ;
}
static int F_216 ( struct V_22 * V_306 , struct V_34 * V_34 , T_5 V_340 )
{
return F_133 ( V_306 , V_34 , V_185 ) ;
}
static int F_217 ( struct V_22 * V_306 , struct V_34 * V_34 )
{
return F_135 ( V_306 , V_34 , V_326 ) ;
}
static int F_218 ( struct V_22 * V_306 , struct V_34 * V_34 , T_5 V_175 , T_8 V_257 )
{
return F_133 ( V_306 , V_34 , F_94 ( V_175 ) ) ;
}
static int F_219 ( struct V_22 * V_510 , struct V_34 * V_329 ,
struct V_22 * V_511 , struct V_34 * V_331 )
{
return F_136 ( V_510 , V_329 , V_511 , V_331 ) ;
}
static int F_220 ( struct V_34 * V_34 )
{
const struct V_10 * V_10 = F_75 () ;
return F_127 ( V_10 , V_34 , V_344 ) ;
}
static int F_221 ( struct V_34 * V_34 , struct V_22 * V_22 ,
bool V_41 )
{
const struct V_10 * V_10 = F_75 () ;
struct V_286 V_287 ;
struct V_23 * V_24 ;
T_2 V_17 ;
F_125 ( V_10 ) ;
V_287 . type = V_301 ;
V_287 . V_292 . V_34 = V_34 ;
V_17 = F_17 ( V_10 ) ;
V_24 = F_32 ( V_22 , V_41 ) ;
if ( F_101 ( V_24 ) )
return F_102 ( V_24 ) ;
return F_222 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_344 , & V_287 ,
V_41 ? V_512 : 0 ) ;
}
static T_9 int F_223 ( struct V_22 * V_22 ,
T_2 V_272 , T_2 V_513 , T_2 V_514 ,
int V_515 ,
unsigned V_86 )
{
struct V_286 V_287 ;
struct V_23 * V_24 = V_22 -> V_33 ;
int V_61 ;
V_287 . type = V_516 ;
V_287 . V_292 . V_22 = V_22 ;
V_61 = F_224 ( F_22 () , V_24 -> V_17 , V_24 -> V_31 , V_272 ,
V_513 , V_514 , V_515 , & V_287 , V_86 ) ;
if ( V_61 )
return V_61 ;
return 0 ;
}
static int F_225 ( struct V_22 * V_22 , int V_340 )
{
const struct V_10 * V_10 = F_75 () ;
T_2 V_272 ;
bool V_517 ;
unsigned V_86 = V_340 & V_512 ;
struct V_23 * V_24 ;
T_2 V_17 ;
struct V_288 V_289 ;
int V_61 , V_298 ;
T_2 V_513 , V_514 ;
V_517 = V_340 & V_518 ;
V_340 &= ( V_343 | V_347 | V_341 | V_345 ) ;
if ( ! V_340 )
return 0 ;
F_125 ( V_10 ) ;
if ( F_126 ( F_64 ( V_22 ) ) )
return 0 ;
V_272 = F_140 ( V_22 -> V_260 , V_340 ) ;
V_17 = F_17 ( V_10 ) ;
V_24 = F_32 ( V_22 , V_86 & V_512 ) ;
if ( F_101 ( V_24 ) )
return F_102 ( V_24 ) ;
V_61 = F_121 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_272 , 0 , & V_289 ) ;
V_513 = F_226 ( V_272 , & V_289 , V_61 ,
V_517 ? V_519 : 0 ,
& V_514 ) ;
if ( F_227 ( ! V_513 ) )
return V_61 ;
V_298 = F_223 ( V_22 , V_272 , V_513 , V_514 , V_61 , V_86 ) ;
if ( V_298 )
return V_298 ;
return V_61 ;
}
static int F_228 ( struct V_34 * V_34 , struct V_520 * V_520 )
{
const struct V_10 * V_10 = F_75 () ;
unsigned int V_521 = V_520 -> V_521 ;
T_10 V_290 = V_348 ;
if ( V_521 & V_522 ) {
V_521 &= ~ ( V_523 | V_524 | V_525 |
V_522 ) ;
if ( ! V_521 )
return 0 ;
}
if ( V_521 & ( V_525 | V_526 | V_527 |
V_528 | V_529 | V_530 ) )
return F_127 ( V_10 , V_34 , V_531 ) ;
if ( V_357 && ( V_521 & V_532 )
&& ! ( V_521 & V_533 ) )
V_290 |= V_358 ;
return F_127 ( V_10 , V_34 , V_290 ) ;
}
static int F_229 ( const struct V_252 * V_252 )
{
return F_128 ( F_75 () , V_252 , V_534 ) ;
}
static int F_230 ( struct V_34 * V_34 , const char * V_72 )
{
const struct V_10 * V_10 = F_75 () ;
if ( ! strncmp ( V_72 , V_535 ,
sizeof V_535 - 1 ) ) {
if ( ! strcmp ( V_72 , V_536 ) ) {
if ( ! F_231 ( V_537 ) )
return - V_425 ;
} else if ( ! F_231 ( V_413 ) ) {
return - V_425 ;
}
}
return F_127 ( V_10 , V_34 , V_531 ) ;
}
static int F_232 ( struct V_34 * V_34 , const char * V_72 ,
const void * V_507 , T_7 V_538 , int V_86 )
{
struct V_22 * V_22 = F_36 ( V_34 ) ;
struct V_23 * V_24 ;
struct V_44 * V_45 ;
struct V_286 V_287 ;
T_2 V_311 , V_17 = F_22 () ;
int V_61 = 0 ;
if ( strcmp ( V_72 , V_82 ) )
return F_230 ( V_34 , V_72 ) ;
V_45 = V_22 -> V_46 -> V_47 ;
if ( ! ( V_45 -> V_86 & V_88 ) )
return - V_80 ;
if ( ! F_233 ( V_22 ) )
return - V_425 ;
V_287 . type = V_301 ;
V_287 . V_292 . V_34 = V_34 ;
V_24 = F_37 ( V_34 ) ;
V_61 = F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 ,
V_539 , & V_287 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_234 ( V_507 , V_538 , & V_311 , V_15 ) ;
if ( V_61 == - V_97 ) {
if ( ! F_231 ( V_540 ) ) {
struct V_541 * V_542 ;
T_7 V_543 ;
const char * V_1 ;
if ( V_507 ) {
V_1 = V_507 ;
if ( V_1 [ V_538 - 1 ] == '\0' )
V_543 = V_538 - 1 ;
else
V_543 = V_538 ;
} else {
V_1 = L_39 ;
V_543 = 0 ;
}
V_542 = F_235 ( V_11 -> V_544 , V_102 , V_545 ) ;
F_236 ( V_542 , L_40 ) ;
F_237 ( V_542 , V_507 , V_543 ) ;
F_238 ( V_542 ) ;
return V_61 ;
}
V_61 = F_239 ( V_507 , V_538 , & V_311 ) ;
}
if ( V_61 )
return V_61 ;
V_61 = F_55 ( V_17 , V_311 , V_24 -> V_31 ,
V_546 , & V_287 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_240 ( V_24 -> V_17 , V_311 , V_17 ,
V_24 -> V_31 ) ;
if ( V_61 )
return V_61 ;
return F_55 ( V_311 ,
V_45 -> V_17 ,
V_62 ,
V_65 ,
& V_287 ) ;
}
static void F_241 ( struct V_34 * V_34 , const char * V_72 ,
const void * V_507 , T_7 V_538 ,
int V_86 )
{
struct V_22 * V_22 = F_36 ( V_34 ) ;
struct V_23 * V_24 ;
T_2 V_311 ;
int V_61 ;
if ( strcmp ( V_72 , V_82 ) ) {
return;
}
V_61 = F_239 ( V_507 , V_538 , & V_311 ) ;
if ( V_61 ) {
F_59 ( V_85 L_41
L_42 ,
V_22 -> V_46 -> V_79 , V_22 -> V_256 , - V_61 ) ;
return;
}
V_24 = F_37 ( V_34 ) ;
V_24 -> V_31 = F_94 ( V_22 -> V_260 ) ;
V_24 -> V_17 = V_311 ;
V_24 -> V_38 = V_39 ;
return;
}
static int F_242 ( struct V_34 * V_34 , const char * V_72 )
{
const struct V_10 * V_10 = F_75 () ;
return F_127 ( V_10 , V_34 , V_534 ) ;
}
static int F_243 ( struct V_34 * V_34 )
{
const struct V_10 * V_10 = F_75 () ;
return F_127 ( V_10 , V_34 , V_534 ) ;
}
static int F_244 ( struct V_34 * V_34 , const char * V_72 )
{
if ( strcmp ( V_72 , V_82 ) )
return F_230 ( V_34 , V_72 ) ;
return - V_130 ;
}
static int F_245 ( struct V_22 * V_22 , const char * V_72 , void * * V_251 , bool V_547 )
{
T_2 V_538 ;
int error ;
char * V_94 = NULL ;
struct V_23 * V_24 ;
if ( strcmp ( V_72 , V_509 ) )
return - V_80 ;
error = F_246 ( F_75 () , & V_129 , V_540 ,
V_414 ) ;
if ( ! error )
error = F_118 ( F_75 () , V_540 ,
V_414 , true ) ;
V_24 = F_34 ( V_22 ) ;
if ( ! error )
error = F_211 ( V_24 -> V_17 , & V_94 ,
& V_538 ) ;
else
error = F_70 ( V_24 -> V_17 , & V_94 , & V_538 ) ;
if ( error )
return error ;
error = V_538 ;
if ( V_547 ) {
* V_251 = V_94 ;
goto V_548;
}
F_52 ( V_94 ) ;
V_548:
return error ;
}
static int F_247 ( struct V_22 * V_22 , const char * V_72 ,
const void * V_507 , T_7 V_538 , int V_86 )
{
struct V_23 * V_24 = F_31 ( V_22 ) ;
T_2 V_311 ;
int V_61 ;
if ( strcmp ( V_72 , V_509 ) )
return - V_80 ;
if ( ! V_507 || ! V_538 )
return - V_130 ;
V_61 = F_234 ( V_507 , V_538 , & V_311 , V_15 ) ;
if ( V_61 )
return V_61 ;
V_24 -> V_31 = F_94 ( V_22 -> V_260 ) ;
V_24 -> V_17 = V_311 ;
V_24 -> V_38 = V_39 ;
return 0 ;
}
static int F_248 ( struct V_22 * V_22 , char * V_251 , T_7 V_549 )
{
const int V_95 = sizeof( V_82 ) ;
if ( V_251 && V_95 <= V_549 )
memcpy ( V_251 , V_82 , V_95 ) ;
return V_95 ;
}
static void F_249 ( struct V_22 * V_22 , T_2 * V_550 )
{
struct V_23 * V_24 = F_31 ( V_22 ) ;
* V_550 = V_24 -> V_17 ;
}
static int F_250 ( struct V_49 * V_49 , int V_340 )
{
const struct V_10 * V_10 = F_75 () ;
struct V_22 * V_22 = F_130 ( V_49 ) ;
if ( ( V_49 -> V_354 & V_355 ) && ( V_340 & V_347 ) )
V_340 |= V_345 ;
return F_131 ( V_10 , V_49 ,
F_140 ( V_22 -> V_260 , V_340 ) ) ;
}
static int F_251 ( struct V_49 * V_49 , int V_340 )
{
struct V_22 * V_22 = F_130 ( V_49 ) ;
struct V_50 * V_51 = V_49 -> V_54 ;
struct V_23 * V_24 ;
T_2 V_17 = F_22 () ;
if ( ! V_340 )
return 0 ;
V_24 = F_34 ( V_22 ) ;
if ( V_17 == V_51 -> V_17 && V_51 -> V_551 == V_24 -> V_17 &&
V_51 -> V_552 == F_252 () )
return 0 ;
return F_250 ( V_49 , V_340 ) ;
}
static int F_253 ( struct V_49 * V_49 )
{
return F_47 ( V_49 ) ;
}
static void F_254 ( struct V_49 * V_49 )
{
F_48 ( V_49 ) ;
}
static int F_255 ( const struct V_10 * V_10 , struct V_49 * V_49 ,
T_2 V_553 , T_4 V_554 )
{
struct V_286 V_287 ;
struct V_50 * V_51 = V_49 -> V_54 ;
struct V_22 * V_22 = F_130 ( V_49 ) ;
struct V_23 * V_24 ;
struct V_555 V_556 ;
T_2 V_557 = F_17 ( V_10 ) ;
int V_61 ;
T_11 V_558 = V_554 >> 8 ;
T_11 V_559 = V_554 & 0xff ;
V_287 . type = V_560 ;
V_287 . V_292 . V_561 = & V_556 ;
V_287 . V_292 . V_561 -> V_554 = V_554 ;
V_287 . V_292 . V_561 -> V_252 = V_49 -> V_303 ;
if ( V_557 != V_51 -> V_17 ) {
V_61 = F_55 ( V_557 , V_51 -> V_17 ,
V_304 ,
V_305 ,
& V_287 ) ;
if ( V_61 )
goto V_81;
}
if ( F_126 ( F_64 ( V_22 ) ) )
return 0 ;
V_24 = F_34 ( V_22 ) ;
V_61 = F_256 ( V_557 , V_24 -> V_17 , V_24 -> V_31 ,
V_553 , V_558 , V_559 , & V_287 ) ;
V_81:
return V_61 ;
}
static int F_257 ( struct V_49 * V_49 , unsigned int V_554 ,
unsigned long V_562 )
{
const struct V_10 * V_10 = F_75 () ;
int error = 0 ;
switch ( V_554 ) {
case V_563 :
case V_564 :
case V_565 :
case V_566 :
case V_567 :
error = F_131 ( V_10 , V_49 , V_534 ) ;
break;
case V_568 :
case V_569 :
error = F_131 ( V_10 , V_49 , V_531 ) ;
break;
case V_570 :
case V_571 :
error = F_131 ( V_10 , V_49 , 0 ) ;
break;
case V_572 :
case V_573 :
error = F_118 ( V_10 , V_574 ,
V_297 , true ) ;
break;
default:
error = F_255 ( V_10 , V_49 , V_356 , ( T_4 ) V_554 ) ;
}
return error ;
}
static int F_258 ( struct V_49 * V_49 , unsigned long V_575 , int V_576 )
{
const struct V_10 * V_10 = F_75 () ;
int V_61 = 0 ;
if ( V_577 &&
( V_575 & V_578 ) && ( ! V_49 || F_64 ( F_130 ( V_49 ) ) ||
( ! V_576 && ( V_575 & V_579 ) ) ) ) {
V_61 = F_115 ( V_10 , V_10 , V_580 ) ;
if ( V_61 )
goto error;
}
if ( V_49 ) {
T_2 V_290 = V_344 ;
if ( V_576 && ( V_575 & V_579 ) )
V_290 |= V_348 ;
if ( V_575 & V_578 )
V_290 |= V_342 ;
return F_131 ( V_10 , V_49 , V_290 ) ;
}
error:
return V_61 ;
}
static int F_259 ( unsigned long V_581 )
{
int V_61 = 0 ;
if ( V_581 < V_582 ) {
T_2 V_17 = F_22 () ;
V_61 = F_55 ( V_17 , V_17 , V_583 ,
V_584 , NULL ) ;
}
return V_61 ;
}
static int F_260 ( struct V_49 * V_49 , unsigned long V_585 ,
unsigned long V_575 , unsigned long V_86 )
{
if ( V_586 )
V_575 = V_585 ;
return F_258 ( V_49 , V_575 ,
( V_86 & V_587 ) == V_588 ) ;
}
static int F_261 ( struct V_589 * V_590 ,
unsigned long V_585 ,
unsigned long V_575 )
{
const struct V_10 * V_10 = F_75 () ;
if ( V_586 )
V_575 = V_585 ;
if ( V_577 &&
( V_575 & V_578 ) && ! ( V_590 -> V_591 & V_592 ) ) {
int V_61 = 0 ;
if ( V_590 -> V_593 >= V_590 -> V_594 -> V_595 &&
V_590 -> V_596 <= V_590 -> V_594 -> V_597 ) {
V_61 = F_115 ( V_10 , V_10 , V_598 ) ;
} else if ( ! V_590 -> V_599 &&
( ( V_590 -> V_593 <= V_590 -> V_594 -> V_600 &&
V_590 -> V_596 >= V_590 -> V_594 -> V_600 ) ||
F_262 ( V_590 , V_11 ) ) ) {
V_61 = F_117 ( V_11 , V_601 ) ;
} else if ( V_590 -> V_599 && V_590 -> V_602 ) {
V_61 = F_131 ( V_10 , V_590 -> V_599 , V_603 ) ;
}
if ( V_61 )
return V_61 ;
}
return F_258 ( V_590 -> V_599 , V_575 , V_590 -> V_591 & V_604 ) ;
}
static int F_263 ( struct V_49 * V_49 , unsigned int V_554 )
{
const struct V_10 * V_10 = F_75 () ;
return F_131 ( V_10 , V_49 , V_605 ) ;
}
static int F_264 ( struct V_49 * V_49 , unsigned int V_554 ,
unsigned long V_562 )
{
const struct V_10 * V_10 = F_75 () ;
int V_606 = 0 ;
switch ( V_554 ) {
case V_607 :
if ( ( V_49 -> V_354 & V_355 ) && ! ( V_562 & V_355 ) ) {
V_606 = F_131 ( V_10 , V_49 , V_348 ) ;
break;
}
case V_608 :
case V_609 :
case V_610 :
case V_611 :
case V_612 :
case V_613 :
V_606 = F_131 ( V_10 , V_49 , 0 ) ;
break;
case V_614 :
case V_615 :
case V_616 :
case V_617 :
case V_618 :
case V_619 :
#if V_620 == 32
case V_621 :
case V_622 :
case V_623 :
#endif
V_606 = F_131 ( V_10 , V_49 , V_605 ) ;
break;
}
return V_606 ;
}
static void F_265 ( struct V_49 * V_49 )
{
struct V_50 * V_51 ;
V_51 = V_49 -> V_54 ;
V_51 -> V_53 = F_22 () ;
}
static int F_266 ( struct V_20 * V_282 ,
struct V_624 * V_625 , int V_626 )
{
struct V_49 * V_49 ;
T_2 V_17 = F_18 ( V_282 ) ;
T_2 V_262 ;
struct V_50 * V_51 ;
V_49 = F_39 ( V_625 , struct V_49 , V_627 ) ;
V_51 = V_49 -> V_54 ;
if ( ! V_626 )
V_262 = F_114 ( V_628 ) ;
else
V_262 = F_114 ( V_626 ) ;
return F_55 ( V_51 -> V_53 , V_17 ,
V_275 , V_262 , NULL ) ;
}
static int F_267 ( struct V_49 * V_49 )
{
const struct V_10 * V_10 = F_75 () ;
return F_131 ( V_10 , V_49 , F_142 ( V_49 ) ) ;
}
static int F_268 ( struct V_49 * V_49 , const struct V_10 * V_10 )
{
struct V_50 * V_51 ;
struct V_23 * V_24 ;
V_51 = V_49 -> V_54 ;
V_24 = F_34 ( F_130 ( V_49 ) ) ;
V_51 -> V_551 = V_24 -> V_17 ;
V_51 -> V_552 = F_252 () ;
return F_129 ( V_10 , V_49 , F_143 ( V_49 ) ) ;
}
static int F_269 ( unsigned long V_629 )
{
return F_117 ( V_11 , V_630 ) ;
}
static int F_270 ( struct V_10 * V_10 , T_12 V_631 )
{
struct V_13 * V_14 ;
V_14 = F_15 ( sizeof( struct V_13 ) , V_631 ) ;
if ( ! V_14 )
return - V_27 ;
V_10 -> V_19 = V_14 ;
return 0 ;
}
static void F_271 ( struct V_10 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_19 ;
F_71 ( V_10 -> V_19 && ( unsigned long ) V_10 -> V_19 < V_253 ) ;
V_10 -> V_19 = ( void * ) 0x7UL ;
F_52 ( V_14 ) ;
}
static int F_272 ( struct V_10 * V_137 , const struct V_10 * V_136 ,
T_12 V_631 )
{
const struct V_13 * V_418 ;
struct V_13 * V_14 ;
V_418 = V_136 -> V_19 ;
V_14 = F_273 ( V_418 , sizeof( struct V_13 ) , V_631 ) ;
if ( ! V_14 )
return - V_27 ;
V_137 -> V_19 = V_14 ;
return 0 ;
}
static void F_274 ( struct V_10 * V_137 , const struct V_10 * V_136 )
{
const struct V_13 * V_418 = V_136 -> V_19 ;
struct V_13 * V_14 = V_137 -> V_19 ;
* V_14 = * V_418 ;
}
static int F_275 ( struct V_10 * V_137 , T_2 V_550 )
{
struct V_13 * V_14 = V_137 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_632 ;
V_632 = F_55 ( V_17 , V_550 ,
V_633 ,
V_634 ,
NULL ) ;
if ( V_632 == 0 ) {
V_14 -> V_17 = V_550 ;
V_14 -> V_309 = 0 ;
V_14 -> V_427 = 0 ;
V_14 -> V_428 = 0 ;
}
return V_632 ;
}
static int F_276 ( struct V_10 * V_137 , struct V_22 * V_22 )
{
struct V_23 * V_24 = F_34 ( V_22 ) ;
struct V_13 * V_14 = V_137 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_632 ;
V_632 = F_55 ( V_17 , V_24 -> V_17 ,
V_633 ,
V_635 ,
NULL ) ;
if ( V_632 == 0 )
V_14 -> V_309 = V_24 -> V_17 ;
return V_632 ;
}
static int F_277 ( char * V_636 )
{
T_2 V_17 ;
struct V_286 V_287 ;
V_17 = F_18 ( V_11 ) ;
V_287 . type = V_637 ;
V_287 . V_292 . V_636 = V_636 ;
return F_55 ( V_17 , V_18 , V_299 ,
V_638 , & V_287 ) ;
}
static int F_278 ( struct V_49 * V_49 )
{
struct V_286 V_287 ;
struct V_23 * V_24 ;
struct V_50 * V_51 ;
T_2 V_17 = F_22 () ;
int V_61 ;
if ( V_49 == NULL )
return F_55 ( V_17 , V_17 , V_299 ,
V_639 , NULL ) ;
V_287 . type = V_302 ;
V_287 . V_292 . V_252 = V_49 -> V_303 ;
V_51 = V_49 -> V_54 ;
if ( V_17 != V_51 -> V_17 ) {
V_61 = F_55 ( V_17 , V_51 -> V_17 , V_304 , V_305 , & V_287 ) ;
if ( V_61 )
return V_61 ;
}
V_24 = F_34 ( F_130 ( V_49 ) ) ;
return F_55 ( V_17 , V_24 -> V_17 , V_299 ,
V_639 , & V_287 ) ;
}
static int F_279 ( struct V_49 * V_49 ,
enum V_640 V_384 )
{
int V_61 = 0 ;
switch ( V_384 ) {
case V_641 :
V_61 = F_278 ( V_49 ) ;
break;
default:
break;
}
return V_61 ;
}
static int F_280 ( struct V_20 * V_152 , T_13 V_642 )
{
return F_117 ( V_152 , V_643 ) ;
}
static int F_281 ( struct V_20 * V_152 )
{
return F_117 ( V_152 , V_644 ) ;
}
static int F_282 ( struct V_20 * V_152 )
{
return F_117 ( V_152 , V_645 ) ;
}
static void F_283 ( struct V_20 * V_152 , T_2 * V_550 )
{
* V_550 = F_18 ( V_152 ) ;
}
static int F_284 ( struct V_20 * V_152 , int V_646 )
{
return F_117 ( V_152 , V_647 ) ;
}
static int F_285 ( struct V_20 * V_152 , int V_648 )
{
return F_117 ( V_152 , V_647 ) ;
}
static int F_286 ( struct V_20 * V_152 )
{
return F_117 ( V_152 , V_649 ) ;
}
static int F_287 ( struct V_20 * V_152 , unsigned int V_650 ,
struct V_456 * V_651 )
{
struct V_456 * V_652 = V_152 -> signal -> V_457 + V_650 ;
if ( V_652 -> V_464 != V_651 -> V_464 )
return F_117 ( V_152 , V_653 ) ;
return 0 ;
}
static int F_288 ( struct V_20 * V_152 )
{
return F_117 ( V_152 , V_647 ) ;
}
static int F_289 ( struct V_20 * V_152 )
{
return F_117 ( V_152 , V_649 ) ;
}
static int F_290 ( struct V_20 * V_152 )
{
return F_117 ( V_152 , V_647 ) ;
}
static int F_291 ( struct V_20 * V_152 , struct V_654 * V_655 ,
int V_261 , T_2 V_550 )
{
T_2 V_262 ;
int V_61 ;
if ( ! V_261 )
V_262 = V_656 ;
else
V_262 = F_114 ( V_261 ) ;
if ( V_550 )
V_61 = F_55 ( V_550 , F_18 ( V_152 ) ,
V_275 , V_262 , NULL ) ;
else
V_61 = F_117 ( V_152 , V_262 ) ;
return V_61 ;
}
static int F_292 ( struct V_20 * V_152 )
{
return F_116 ( V_152 , V_11 , V_264 ) ;
}
static void F_293 ( struct V_20 * V_152 ,
struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 = F_18 ( V_152 ) ;
V_24 -> V_17 = V_17 ;
V_24 -> V_38 = V_39 ;
}
static int F_294 ( struct V_657 * V_658 ,
struct V_286 * V_287 , T_11 * V_659 )
{
int V_660 , V_661 , V_632 = - V_97 ;
struct V_662 V_663 , * V_664 ;
V_660 = F_295 ( V_658 ) ;
V_664 = F_296 ( V_658 , V_660 , sizeof( V_663 ) , & V_663 ) ;
if ( V_664 == NULL )
goto V_81;
V_661 = V_664 -> V_665 * 4 ;
if ( V_661 < sizeof( V_663 ) )
goto V_81;
V_287 -> V_292 . V_666 -> V_667 . V_668 = V_664 -> V_668 ;
V_287 -> V_292 . V_666 -> V_667 . V_669 = V_664 -> V_669 ;
V_632 = 0 ;
if ( V_659 )
* V_659 = V_664 -> V_190 ;
switch ( V_664 -> V_190 ) {
case V_192 : {
struct V_670 V_671 , * V_672 ;
if ( F_297 ( V_664 -> V_673 ) & V_674 )
break;
V_660 += V_661 ;
V_672 = F_296 ( V_658 , V_660 , sizeof( V_671 ) , & V_671 ) ;
if ( V_672 == NULL )
break;
V_287 -> V_292 . V_666 -> V_675 = V_672 -> V_676 ;
V_287 -> V_292 . V_666 -> V_677 = V_672 -> V_678 ;
break;
}
case V_193 : {
struct V_679 V_680 , * V_681 ;
if ( F_297 ( V_664 -> V_673 ) & V_674 )
break;
V_660 += V_661 ;
V_681 = F_296 ( V_658 , V_660 , sizeof( V_680 ) , & V_680 ) ;
if ( V_681 == NULL )
break;
V_287 -> V_292 . V_666 -> V_675 = V_681 -> V_676 ;
V_287 -> V_292 . V_666 -> V_677 = V_681 -> V_678 ;
break;
}
case V_682 : {
struct V_683 V_684 , * V_685 ;
if ( F_297 ( V_664 -> V_673 ) & V_674 )
break;
V_660 += V_661 ;
V_685 = F_296 ( V_658 , V_660 , sizeof( V_684 ) , & V_684 ) ;
if ( V_685 == NULL )
break;
V_287 -> V_292 . V_666 -> V_675 = V_685 -> V_686 ;
V_287 -> V_292 . V_666 -> V_677 = V_685 -> V_687 ;
break;
}
default:
break;
}
V_81:
return V_632 ;
}
static int F_298 ( struct V_657 * V_658 ,
struct V_286 * V_287 , T_11 * V_659 )
{
T_11 V_688 ;
int V_632 = - V_97 , V_660 ;
struct V_689 V_690 , * V_691 ;
T_14 V_673 ;
V_660 = F_295 ( V_658 ) ;
V_691 = F_296 ( V_658 , V_660 , sizeof( V_690 ) , & V_690 ) ;
if ( V_691 == NULL )
goto V_81;
V_287 -> V_292 . V_666 -> V_692 . V_668 = V_691 -> V_668 ;
V_287 -> V_292 . V_666 -> V_692 . V_669 = V_691 -> V_669 ;
V_632 = 0 ;
V_688 = V_691 -> V_688 ;
V_660 += sizeof( V_690 ) ;
V_660 = F_299 ( V_658 , V_660 , & V_688 , & V_673 ) ;
if ( V_660 < 0 )
goto V_81;
if ( V_659 )
* V_659 = V_688 ;
switch ( V_688 ) {
case V_192 : {
struct V_670 V_671 , * V_672 ;
V_672 = F_296 ( V_658 , V_660 , sizeof( V_671 ) , & V_671 ) ;
if ( V_672 == NULL )
break;
V_287 -> V_292 . V_666 -> V_675 = V_672 -> V_676 ;
V_287 -> V_292 . V_666 -> V_677 = V_672 -> V_678 ;
break;
}
case V_193 : {
struct V_679 V_680 , * V_681 ;
V_681 = F_296 ( V_658 , V_660 , sizeof( V_680 ) , & V_680 ) ;
if ( V_681 == NULL )
break;
V_287 -> V_292 . V_666 -> V_675 = V_681 -> V_676 ;
V_287 -> V_292 . V_666 -> V_677 = V_681 -> V_678 ;
break;
}
case V_682 : {
struct V_683 V_684 , * V_685 ;
V_685 = F_296 ( V_658 , V_660 , sizeof( V_684 ) , & V_684 ) ;
if ( V_685 == NULL )
break;
V_287 -> V_292 . V_666 -> V_675 = V_685 -> V_686 ;
V_287 -> V_292 . V_666 -> V_677 = V_685 -> V_687 ;
break;
}
default:
break;
}
V_81:
return V_632 ;
}
static int F_300 ( struct V_657 * V_658 , struct V_286 * V_287 ,
char * * V_693 , int V_694 , T_11 * V_659 )
{
char * V_695 ;
int V_632 ;
switch ( V_287 -> V_292 . V_666 -> V_194 ) {
case V_201 :
V_632 = F_294 ( V_658 , V_287 , V_659 ) ;
if ( V_632 )
goto V_696;
V_695 = ( char * ) ( V_694 ? & V_287 -> V_292 . V_666 -> V_667 . V_668 :
& V_287 -> V_292 . V_666 -> V_667 . V_669 ) ;
goto V_697;
#if F_301 ( V_698 ) || F_301 ( V_699 )
case V_202 :
V_632 = F_298 ( V_658 , V_287 , V_659 ) ;
if ( V_632 )
goto V_696;
V_695 = ( char * ) ( V_694 ? & V_287 -> V_292 . V_666 -> V_692 . V_668 :
& V_287 -> V_292 . V_666 -> V_692 . V_669 ) ;
goto V_697;
#endif
default:
V_695 = NULL ;
goto V_697;
}
V_696:
F_59 ( V_78
L_43
L_44 ) ;
return V_632 ;
V_697:
if ( V_693 )
* V_693 = V_695 ;
return 0 ;
}
static int F_302 ( struct V_657 * V_658 , T_4 V_194 , T_2 * V_17 )
{
int V_606 ;
T_2 V_700 ;
T_2 V_701 ;
T_2 V_702 ;
V_606 = F_303 ( V_658 , & V_700 ) ;
if ( F_126 ( V_606 ) )
return - V_130 ;
V_606 = F_304 ( V_658 , V_194 , & V_702 , & V_701 ) ;
if ( F_126 ( V_606 ) )
return - V_130 ;
V_606 = F_305 ( V_701 , V_702 , V_700 , V_17 ) ;
if ( F_126 ( V_606 ) ) {
F_59 ( V_78
L_45
L_46 ) ;
return - V_130 ;
}
return 0 ;
}
static int F_306 ( T_2 V_703 , T_2 V_704 , T_2 * V_705 )
{
int V_606 = 0 ;
if ( V_704 != V_706 )
V_606 = F_307 ( V_703 , V_704 , V_705 ) ;
else
* V_705 = V_703 ;
return V_606 ;
}
static int F_308 ( const struct V_13 * V_14 ,
T_4 V_707 , T_2 * V_708 )
{
if ( V_14 -> V_428 > V_706 ) {
* V_708 = V_14 -> V_428 ;
return 0 ;
}
return F_79 ( V_14 -> V_17 , V_14 -> V_17 , V_707 , NULL ,
V_708 ) ;
}
static int F_309 ( struct V_20 * V_21 , struct V_709 * V_710 , T_2 V_272 )
{
struct V_711 * V_712 = V_710 -> V_713 ;
struct V_286 V_287 ;
struct V_714 V_666 = { 0 ,} ;
T_2 V_274 = F_18 ( V_21 ) ;
if ( V_712 -> V_17 == V_18 )
return 0 ;
V_287 . type = V_715 ;
V_287 . V_292 . V_666 = & V_666 ;
V_287 . V_292 . V_666 -> V_710 = V_710 ;
return F_55 ( V_274 , V_712 -> V_17 , V_712 -> V_31 , V_272 , & V_287 ) ;
}
static int F_310 ( int V_194 , int type ,
int V_190 , int V_716 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_311 ;
T_4 V_707 ;
int V_61 ;
if ( V_716 )
return 0 ;
V_707 = F_97 ( V_194 , type , V_190 ) ;
V_61 = F_308 ( V_14 , V_707 , & V_311 ) ;
if ( V_61 )
return V_61 ;
return F_55 ( V_14 -> V_17 , V_311 , V_707 , V_717 , NULL ) ;
}
static int F_311 ( struct V_718 * V_709 , int V_194 ,
int type , int V_190 , int V_716 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_24 = F_31 ( F_312 ( V_709 ) ) ;
struct V_711 * V_712 ;
int V_606 = 0 ;
V_24 -> V_31 = F_97 ( V_194 , type , V_190 ) ;
if ( V_716 )
V_24 -> V_17 = V_18 ;
else {
V_606 = F_308 ( V_14 , V_24 -> V_31 , & ( V_24 -> V_17 ) ) ;
if ( V_606 )
return V_606 ;
}
V_24 -> V_38 = V_39 ;
if ( V_709 -> V_710 ) {
V_712 = V_709 -> V_710 -> V_713 ;
V_712 -> V_17 = V_24 -> V_17 ;
V_712 -> V_31 = V_24 -> V_31 ;
V_606 = F_313 ( V_709 -> V_710 , V_194 ) ;
}
return V_606 ;
}
static int F_314 ( struct V_718 * V_709 , struct V_719 * V_720 , int V_721 )
{
struct V_709 * V_710 = V_709 -> V_710 ;
T_4 V_194 ;
int V_606 ;
V_606 = F_309 ( V_11 , V_710 , V_722 ) ;
if ( V_606 )
goto V_81;
V_194 = V_710 -> V_723 ;
if ( V_194 == V_201 || V_194 == V_202 ) {
char * V_695 ;
struct V_711 * V_712 = V_710 -> V_713 ;
struct V_286 V_287 ;
struct V_714 V_666 = { 0 ,} ;
struct V_724 * V_725 = NULL ;
struct V_726 * V_727 = NULL ;
unsigned short V_728 ;
T_2 V_17 , V_729 ;
if ( V_194 == V_201 ) {
V_725 = (struct V_724 * ) V_720 ;
V_728 = F_297 ( V_725 -> V_730 ) ;
V_695 = ( char * ) & V_725 -> V_731 . V_732 ;
} else {
V_727 = (struct V_726 * ) V_720 ;
V_728 = F_297 ( V_727 -> V_733 ) ;
V_695 = ( char * ) & V_727 -> V_734 . V_735 ;
}
if ( V_728 ) {
int V_736 , V_737 ;
F_315 ( F_316 ( V_710 ) , & V_736 , & V_737 ) ;
if ( V_728 < V_738 ( V_739, V_736 ) || V_728 > V_737 ) {
V_606 = F_317 ( V_710 -> V_740 ,
V_728 , & V_17 ) ;
if ( V_606 )
goto V_81;
V_287 . type = V_715 ;
V_287 . V_292 . V_666 = & V_666 ;
V_287 . V_292 . V_666 -> V_675 = F_318 ( V_728 ) ;
V_287 . V_292 . V_666 -> V_194 = V_194 ;
V_606 = F_55 ( V_712 -> V_17 , V_17 ,
V_712 -> V_31 ,
V_741 , & V_287 ) ;
if ( V_606 )
goto V_81;
}
}
switch ( V_712 -> V_31 ) {
case V_203 :
V_729 = V_742 ;
break;
case V_205 :
V_729 = V_743 ;
break;
case V_207 :
V_729 = V_744 ;
break;
default:
V_729 = V_745 ;
break;
}
V_606 = F_319 ( V_695 , V_194 , & V_17 ) ;
if ( V_606 )
goto V_81;
V_287 . type = V_715 ;
V_287 . V_292 . V_666 = & V_666 ;
V_287 . V_292 . V_666 -> V_675 = F_318 ( V_728 ) ;
V_287 . V_292 . V_666 -> V_194 = V_194 ;
if ( V_194 == V_201 )
V_287 . V_292 . V_666 -> V_667 . V_668 = V_725 -> V_731 . V_732 ;
else
V_287 . V_292 . V_666 -> V_692 . V_668 = V_727 -> V_734 ;
V_606 = F_55 ( V_712 -> V_17 , V_17 ,
V_712 -> V_31 , V_729 , & V_287 ) ;
if ( V_606 )
goto V_81;
}
V_81:
return V_606 ;
}
static int F_320 ( struct V_718 * V_709 , struct V_719 * V_720 , int V_721 )
{
struct V_709 * V_710 = V_709 -> V_710 ;
struct V_711 * V_712 = V_710 -> V_713 ;
int V_606 ;
V_606 = F_309 ( V_11 , V_710 , V_746 ) ;
if ( V_606 )
return V_606 ;
if ( V_712 -> V_31 == V_203 ||
V_712 -> V_31 == V_207 ) {
struct V_286 V_287 ;
struct V_714 V_666 = { 0 ,} ;
struct V_724 * V_725 = NULL ;
struct V_726 * V_727 = NULL ;
unsigned short V_728 ;
T_2 V_17 , V_262 ;
if ( V_710 -> V_723 == V_201 ) {
V_725 = (struct V_724 * ) V_720 ;
if ( V_721 < sizeof( struct V_724 ) )
return - V_97 ;
V_728 = F_297 ( V_725 -> V_730 ) ;
} else {
V_727 = (struct V_726 * ) V_720 ;
if ( V_721 < V_747 )
return - V_97 ;
V_728 = F_297 ( V_727 -> V_733 ) ;
}
V_606 = F_317 ( V_710 -> V_740 , V_728 , & V_17 ) ;
if ( V_606 )
goto V_81;
V_262 = ( V_712 -> V_31 == V_203 ) ?
V_748 : V_749 ;
V_287 . type = V_715 ;
V_287 . V_292 . V_666 = & V_666 ;
V_287 . V_292 . V_666 -> V_677 = F_318 ( V_728 ) ;
V_287 . V_292 . V_666 -> V_194 = V_710 -> V_723 ;
V_606 = F_55 ( V_712 -> V_17 , V_17 , V_712 -> V_31 , V_262 , & V_287 ) ;
if ( V_606 )
goto V_81;
}
V_606 = F_321 ( V_710 , V_720 ) ;
V_81:
return V_606 ;
}
static int F_322 ( struct V_718 * V_709 , int V_750 )
{
return F_309 ( V_11 , V_709 -> V_710 , V_751 ) ;
}
static int F_323 ( struct V_718 * V_709 , struct V_718 * V_752 )
{
int V_606 ;
struct V_23 * V_24 ;
struct V_23 * V_149 ;
V_606 = F_309 ( V_11 , V_709 -> V_710 , V_753 ) ;
if ( V_606 )
return V_606 ;
V_149 = F_31 ( F_312 ( V_752 ) ) ;
V_24 = F_31 ( F_312 ( V_709 ) ) ;
V_149 -> V_31 = V_24 -> V_31 ;
V_149 -> V_17 = V_24 -> V_17 ;
V_149 -> V_38 = V_39 ;
return 0 ;
}
static int F_324 ( struct V_718 * V_709 , struct V_754 * V_755 ,
int V_538 )
{
return F_309 ( V_11 , V_709 -> V_710 , V_756 ) ;
}
static int F_325 ( struct V_718 * V_709 , struct V_754 * V_755 ,
int V_538 , int V_86 )
{
return F_309 ( V_11 , V_709 -> V_710 , V_757 ) ;
}
static int F_326 ( struct V_718 * V_709 )
{
return F_309 ( V_11 , V_709 -> V_710 , V_758 ) ;
}
static int F_327 ( struct V_718 * V_709 )
{
return F_309 ( V_11 , V_709 -> V_710 , V_758 ) ;
}
static int F_328 ( struct V_718 * V_709 , int V_759 , int V_760 )
{
int V_606 ;
V_606 = F_309 ( V_11 , V_709 -> V_710 , V_761 ) ;
if ( V_606 )
return V_606 ;
return F_329 ( V_709 , V_759 , V_760 ) ;
}
static int F_330 ( struct V_718 * V_709 , int V_759 ,
int V_760 )
{
return F_309 ( V_11 , V_709 -> V_710 , V_762 ) ;
}
static int F_331 ( struct V_718 * V_709 , int V_763 )
{
return F_309 ( V_11 , V_709 -> V_710 , V_764 ) ;
}
static int F_332 ( struct V_709 * V_709 ,
struct V_709 * V_765 ,
struct V_709 * V_766 )
{
struct V_711 * V_767 = V_709 -> V_713 ;
struct V_711 * V_768 = V_765 -> V_713 ;
struct V_711 * V_769 = V_766 -> V_713 ;
struct V_286 V_287 ;
struct V_714 V_666 = { 0 ,} ;
int V_606 ;
V_287 . type = V_715 ;
V_287 . V_292 . V_666 = & V_666 ;
V_287 . V_292 . V_666 -> V_710 = V_765 ;
V_606 = F_55 ( V_767 -> V_17 , V_768 -> V_17 ,
V_768 -> V_31 ,
V_770 , & V_287 ) ;
if ( V_606 )
return V_606 ;
V_769 -> V_771 = V_767 -> V_17 ;
V_606 = F_307 ( V_768 -> V_17 , V_767 -> V_17 ,
& V_769 -> V_17 ) ;
if ( V_606 )
return V_606 ;
V_767 -> V_771 = V_769 -> V_17 ;
return 0 ;
}
static int F_333 ( struct V_718 * V_709 ,
struct V_718 * V_765 )
{
struct V_711 * V_772 = V_709 -> V_710 -> V_713 ;
struct V_711 * V_773 = V_765 -> V_710 -> V_713 ;
struct V_286 V_287 ;
struct V_714 V_666 = { 0 ,} ;
V_287 . type = V_715 ;
V_287 . V_292 . V_666 = & V_666 ;
V_287 . V_292 . V_666 -> V_710 = V_765 -> V_710 ;
return F_55 ( V_772 -> V_17 , V_773 -> V_17 , V_773 -> V_31 , V_774 ,
& V_287 ) ;
}
static int F_334 ( struct V_666 * V_382 , int V_775 ,
char * V_695 , T_4 V_194 , T_2 V_771 ,
struct V_286 * V_287 )
{
int V_606 ;
T_2 V_776 ;
T_2 V_777 ;
V_606 = F_335 ( V_382 , V_775 , & V_776 ) ;
if ( V_606 )
return V_606 ;
V_606 = F_55 ( V_771 , V_776 ,
V_778 , V_779 , V_287 ) ;
if ( V_606 )
return V_606 ;
V_606 = F_319 ( V_695 , V_194 , & V_777 ) ;
if ( V_606 )
return V_606 ;
return F_55 ( V_771 , V_777 ,
V_780 , V_781 , V_287 ) ;
}
static int F_336 ( struct V_709 * V_710 , struct V_657 * V_658 ,
T_4 V_194 )
{
int V_606 = 0 ;
struct V_711 * V_712 = V_710 -> V_713 ;
T_2 V_703 = V_712 -> V_17 ;
struct V_286 V_287 ;
struct V_714 V_666 = { 0 ,} ;
char * V_695 ;
V_287 . type = V_715 ;
V_287 . V_292 . V_666 = & V_666 ;
V_287 . V_292 . V_666 -> V_782 = V_658 -> V_783 ;
V_287 . V_292 . V_666 -> V_194 = V_194 ;
V_606 = F_300 ( V_658 , & V_287 , & V_695 , 1 , NULL ) ;
if ( V_606 )
return V_606 ;
if ( F_4 () ) {
V_606 = F_55 ( V_703 , V_658 -> V_784 , V_785 ,
V_786 , & V_287 ) ;
if ( V_606 )
return V_606 ;
}
V_606 = F_337 ( V_712 , V_658 , V_194 , & V_287 ) ;
if ( V_606 )
return V_606 ;
V_606 = F_338 ( V_712 -> V_17 , V_658 , & V_287 ) ;
return V_606 ;
}
static int F_339 ( struct V_709 * V_710 , struct V_657 * V_658 )
{
int V_606 ;
struct V_711 * V_712 = V_710 -> V_713 ;
T_4 V_194 = V_710 -> V_723 ;
T_2 V_703 = V_712 -> V_17 ;
struct V_286 V_287 ;
struct V_714 V_666 = { 0 ,} ;
char * V_695 ;
T_11 V_787 ;
T_11 V_788 ;
if ( V_194 != V_201 && V_194 != V_202 )
return 0 ;
if ( V_194 == V_202 && V_658 -> V_190 == F_318 ( V_789 ) )
V_194 = V_201 ;
if ( ! V_790 )
return F_336 ( V_710 , V_658 , V_194 ) ;
V_787 = F_4 () ;
V_788 = F_6 () ;
if ( ! V_787 && ! V_788 )
return 0 ;
V_287 . type = V_715 ;
V_287 . V_292 . V_666 = & V_666 ;
V_287 . V_292 . V_666 -> V_782 = V_658 -> V_783 ;
V_287 . V_292 . V_666 -> V_194 = V_194 ;
V_606 = F_300 ( V_658 , & V_287 , & V_695 , 1 , NULL ) ;
if ( V_606 )
return V_606 ;
if ( V_788 ) {
T_2 V_771 ;
V_606 = F_302 ( V_658 , V_194 , & V_771 ) ;
if ( V_606 )
return V_606 ;
V_606 = F_334 ( F_316 ( V_710 ) , V_658 -> V_783 ,
V_695 , V_194 , V_771 , & V_287 ) ;
if ( V_606 ) {
F_340 ( V_658 , V_194 , V_606 , 0 ) ;
return V_606 ;
}
V_606 = F_55 ( V_703 , V_771 , V_791 ,
V_792 , & V_287 ) ;
if ( V_606 ) {
F_340 ( V_658 , V_194 , V_606 , 0 ) ;
return V_606 ;
}
}
if ( V_787 ) {
V_606 = F_55 ( V_703 , V_658 -> V_784 , V_785 ,
V_786 , & V_287 ) ;
if ( V_606 )
return V_606 ;
}
return V_606 ;
}
static int F_341 ( struct V_718 * V_709 , char T_15 * V_793 ,
int T_15 * V_794 , unsigned V_95 )
{
int V_606 = 0 ;
char * V_795 ;
T_2 V_796 ;
struct V_711 * V_712 = V_709 -> V_710 -> V_713 ;
T_2 V_771 = V_706 ;
if ( V_712 -> V_31 == V_198 ||
V_712 -> V_31 == V_203 )
V_771 = V_712 -> V_771 ;
if ( V_771 == V_706 )
return - V_797 ;
V_606 = F_70 ( V_771 , & V_795 , & V_796 ) ;
if ( V_606 )
return V_606 ;
if ( V_796 > V_95 ) {
V_606 = - V_255 ;
goto V_798;
}
if ( F_342 ( V_793 , V_795 , V_796 ) )
V_606 = - V_799 ;
V_798:
if ( F_343 ( V_796 , V_794 ) )
V_606 = - V_799 ;
F_52 ( V_795 ) ;
return V_606 ;
}
static int F_344 ( struct V_718 * V_709 , struct V_657 * V_658 , T_2 * V_550 )
{
T_2 V_800 = V_706 ;
T_4 V_194 ;
struct V_23 * V_24 ;
if ( V_658 && V_658 -> V_190 == F_318 ( V_789 ) )
V_194 = V_201 ;
else if ( V_658 && V_658 -> V_190 == F_318 ( V_801 ) )
V_194 = V_202 ;
else if ( V_709 )
V_194 = V_709 -> V_710 -> V_723 ;
else
goto V_81;
if ( V_709 && V_194 == V_195 ) {
V_24 = F_31 ( F_312 ( V_709 ) ) ;
V_800 = V_24 -> V_17 ;
} else if ( V_658 )
F_302 ( V_658 , V_194 , & V_800 ) ;
V_81:
* V_550 = V_800 ;
if ( V_800 == V_706 )
return - V_97 ;
return 0 ;
}
static int F_345 ( struct V_709 * V_710 , int V_194 , T_12 V_802 )
{
struct V_711 * V_712 ;
V_712 = F_15 ( sizeof( * V_712 ) , V_802 ) ;
if ( ! V_712 )
return - V_27 ;
V_712 -> V_771 = V_30 ;
V_712 -> V_17 = V_30 ;
V_712 -> V_31 = V_248 ;
F_346 ( V_712 ) ;
V_710 -> V_713 = V_712 ;
return 0 ;
}
static void F_347 ( struct V_709 * V_710 )
{
struct V_711 * V_712 = V_710 -> V_713 ;
V_710 -> V_713 = NULL ;
F_348 ( V_712 ) ;
F_52 ( V_712 ) ;
}
static void F_349 ( const struct V_709 * V_710 , struct V_709 * V_766 )
{
struct V_711 * V_712 = V_710 -> V_713 ;
struct V_711 * V_803 = V_766 -> V_713 ;
V_803 -> V_17 = V_712 -> V_17 ;
V_803 -> V_771 = V_712 -> V_771 ;
V_803 -> V_31 = V_712 -> V_31 ;
F_346 ( V_803 ) ;
}
static void F_350 ( struct V_709 * V_710 , T_2 * V_550 )
{
if ( ! V_710 )
* V_550 = V_804 ;
else {
struct V_711 * V_712 = V_710 -> V_713 ;
* V_550 = V_712 -> V_17 ;
}
}
static void F_351 ( struct V_709 * V_710 , struct V_718 * V_375 )
{
struct V_23 * V_24 =
F_31 ( F_312 ( V_375 ) ) ;
struct V_711 * V_712 = V_710 -> V_713 ;
if ( V_710 -> V_723 == V_201 || V_710 -> V_723 == V_202 ||
V_710 -> V_723 == V_195 )
V_24 -> V_17 = V_712 -> V_17 ;
V_712 -> V_31 = V_24 -> V_31 ;
}
static int F_352 ( struct V_709 * V_710 , struct V_657 * V_658 ,
struct V_805 * V_806 )
{
struct V_711 * V_712 = V_710 -> V_713 ;
int V_606 ;
T_4 V_194 = V_806 -> V_807 -> V_194 ;
T_2 V_808 ;
T_2 V_809 ;
V_606 = F_302 ( V_658 , V_194 , & V_809 ) ;
if ( V_606 )
return V_606 ;
V_606 = F_306 ( V_712 -> V_17 , V_809 , & V_808 ) ;
if ( V_606 )
return V_606 ;
V_806 -> V_550 = V_808 ;
V_806 -> V_800 = V_809 ;
return F_353 ( V_806 , V_194 ) ;
}
static void F_354 ( struct V_709 * V_766 ,
const struct V_805 * V_806 )
{
struct V_711 * V_803 = V_766 -> V_713 ;
V_803 -> V_17 = V_806 -> V_550 ;
V_803 -> V_771 = V_806 -> V_800 ;
F_355 ( V_766 , V_806 -> V_807 -> V_194 ) ;
}
static void F_356 ( struct V_709 * V_710 , struct V_657 * V_658 )
{
T_4 V_194 = V_710 -> V_723 ;
struct V_711 * V_712 = V_710 -> V_713 ;
if ( V_194 == V_202 && V_658 -> V_190 == F_318 ( V_789 ) )
V_194 = V_201 ;
F_302 ( V_658 , V_194 , & V_712 -> V_771 ) ;
}
static int F_357 ( T_2 V_17 )
{
const struct V_13 * V_810 ;
T_2 V_274 ;
V_810 = F_23 () ;
V_274 = V_810 -> V_17 ;
return F_55 ( V_274 , V_17 , V_785 , V_811 , NULL ) ;
}
static void F_358 ( void )
{
F_359 ( & V_7 ) ;
}
static void F_360 ( void )
{
F_361 ( & V_7 ) ;
}
static void F_362 ( const struct V_805 * V_806 ,
struct V_812 * V_813 )
{
V_813 -> V_814 = V_806 -> V_550 ;
}
static int F_363 ( void * * V_19 )
{
struct V_815 * V_816 ;
V_816 = F_15 ( sizeof( * V_816 ) , V_15 ) ;
if ( ! V_816 )
return - V_27 ;
V_816 -> V_17 = F_22 () ;
* V_19 = V_816 ;
return 0 ;
}
static void F_364 ( void * V_19 )
{
F_52 ( V_19 ) ;
}
static int F_365 ( void )
{
T_2 V_17 = F_22 () ;
return F_55 ( V_17 , V_17 , V_817 , V_818 ,
NULL ) ;
}
static int F_366 ( void * V_19 )
{
struct V_815 * V_816 = V_19 ;
return F_55 ( F_22 () , V_816 -> V_17 , V_817 ,
V_819 , NULL ) ;
}
static int F_367 ( struct V_709 * V_710 , void * V_19 )
{
struct V_815 * V_816 = V_19 ;
struct V_711 * V_712 = V_710 -> V_713 ;
V_712 -> V_17 = V_816 -> V_17 ;
V_712 -> V_31 = V_817 ;
return 0 ;
}
static int F_368 ( void * V_19 )
{
struct V_815 * V_816 = V_19 ;
T_2 V_17 = F_22 () ;
int V_606 ;
V_606 = F_55 ( V_17 , V_816 -> V_17 , V_817 ,
V_820 , NULL ) ;
if ( V_606 )
return V_606 ;
V_606 = F_55 ( V_17 , V_17 , V_817 ,
V_821 , NULL ) ;
if ( V_606 )
return V_606 ;
V_816 -> V_17 = V_17 ;
return 0 ;
}
static int F_369 ( struct V_709 * V_710 , struct V_657 * V_658 )
{
int V_606 = 0 ;
T_2 V_262 ;
struct V_822 * V_823 ;
struct V_711 * V_712 = V_710 -> V_713 ;
if ( V_658 -> V_95 < V_824 ) {
V_606 = - V_97 ;
goto V_81;
}
V_823 = F_370 ( V_658 ) ;
V_606 = F_371 ( V_712 -> V_31 , V_823 -> V_825 , & V_262 ) ;
if ( V_606 ) {
if ( V_606 == - V_97 ) {
F_372 ( L_47
L_48
L_49 ,
V_710 -> V_740 , V_823 -> V_825 ,
V_826 [ V_712 -> V_31 - 1 ] . V_72 ,
F_373 ( V_11 ) , V_11 -> V_827 ) ;
if ( ! V_3 || F_374 () )
V_606 = 0 ;
}
if ( V_606 == - V_828 )
V_606 = 0 ;
goto V_81;
}
V_606 = F_309 ( V_11 , V_710 , V_262 ) ;
V_81:
return V_606 ;
}
static unsigned int F_375 ( struct V_657 * V_658 ,
const struct V_829 * V_830 ,
T_4 V_194 )
{
int V_606 ;
char * V_695 ;
T_2 V_771 ;
struct V_286 V_287 ;
struct V_714 V_666 = { 0 ,} ;
T_11 V_787 ;
T_11 V_831 ;
T_11 V_788 ;
if ( ! V_790 )
return V_832 ;
V_787 = F_4 () ;
V_831 = F_7 () ;
V_788 = F_6 () ;
if ( ! V_787 && ! V_788 )
return V_832 ;
if ( F_302 ( V_658 , V_194 , & V_771 ) != 0 )
return V_833 ;
V_287 . type = V_715 ;
V_287 . V_292 . V_666 = & V_666 ;
V_287 . V_292 . V_666 -> V_782 = V_830 -> V_775 ;
V_287 . V_292 . V_666 -> V_194 = V_194 ;
if ( F_300 ( V_658 , & V_287 , & V_695 , 1 , NULL ) != 0 )
return V_833 ;
if ( V_788 ) {
V_606 = F_334 ( F_376 ( V_830 ) , V_830 -> V_775 ,
V_695 , V_194 , V_771 , & V_287 ) ;
if ( V_606 ) {
F_340 ( V_658 , V_194 , V_606 , 1 ) ;
return V_833 ;
}
}
if ( V_787 )
if ( F_55 ( V_771 , V_658 -> V_784 ,
V_785 , V_834 , & V_287 ) )
return V_833 ;
if ( V_831 )
if ( F_377 ( V_658 , V_194 , V_771 ) != 0 )
return V_833 ;
return V_832 ;
}
static unsigned int F_378 ( void * V_835 ,
struct V_657 * V_658 ,
const struct V_836 * V_837 )
{
return F_375 ( V_658 , V_837 -> V_838 , V_201 ) ;
}
static unsigned int F_379 ( void * V_835 ,
struct V_657 * V_658 ,
const struct V_836 * V_837 )
{
return F_375 ( V_658 , V_837 -> V_838 , V_202 ) ;
}
static unsigned int F_380 ( struct V_657 * V_658 ,
T_4 V_194 )
{
struct V_709 * V_710 ;
T_2 V_17 ;
if ( ! F_7 () )
return V_832 ;
V_710 = V_658 -> V_710 ;
if ( V_710 ) {
struct V_711 * V_712 ;
if ( F_381 ( V_710 ) )
return V_832 ;
V_712 = V_710 -> V_713 ;
V_17 = V_712 -> V_17 ;
} else
V_17 = V_18 ;
if ( F_377 ( V_658 , V_194 , V_17 ) != 0 )
return V_833 ;
return V_832 ;
}
static unsigned int F_382 ( void * V_835 ,
struct V_657 * V_658 ,
const struct V_836 * V_837 )
{
return F_380 ( V_658 , V_201 ) ;
}
static unsigned int F_383 ( void * V_835 ,
struct V_657 * V_658 ,
const struct V_836 * V_837 )
{
return F_380 ( V_658 , V_202 ) ;
}
static unsigned int F_384 ( struct V_657 * V_658 ,
int V_775 ,
T_4 V_194 )
{
struct V_709 * V_710 = F_385 ( V_658 ) ;
struct V_711 * V_712 ;
struct V_286 V_287 ;
struct V_714 V_666 = { 0 ,} ;
char * V_695 ;
T_11 V_659 ;
if ( V_710 == NULL )
return V_832 ;
V_712 = V_710 -> V_713 ;
V_287 . type = V_715 ;
V_287 . V_292 . V_666 = & V_666 ;
V_287 . V_292 . V_666 -> V_782 = V_775 ;
V_287 . V_292 . V_666 -> V_194 = V_194 ;
if ( F_300 ( V_658 , & V_287 , & V_695 , 0 , & V_659 ) )
return V_833 ;
if ( F_4 () )
if ( F_55 ( V_712 -> V_17 , V_658 -> V_784 ,
V_785 , V_839 , & V_287 ) )
return F_386 ( - V_840 ) ;
if ( F_387 ( V_712 -> V_17 , V_658 , & V_287 , V_659 ) )
return F_386 ( - V_840 ) ;
return V_832 ;
}
static unsigned int F_388 ( struct V_657 * V_658 ,
const struct V_829 * V_841 ,
T_4 V_194 )
{
T_2 V_842 ;
T_2 V_771 ;
int V_775 = V_841 -> V_775 ;
struct V_709 * V_710 ;
struct V_286 V_287 ;
struct V_714 V_666 = { 0 ,} ;
char * V_695 ;
T_11 V_787 ;
T_11 V_788 ;
if ( ! V_790 )
return F_384 ( V_658 , V_775 , V_194 ) ;
V_787 = F_4 () ;
V_788 = F_6 () ;
if ( ! V_787 && ! V_788 )
return V_832 ;
V_710 = F_385 ( V_658 ) ;
#ifdef F_389
if ( F_390 ( V_658 ) != NULL && F_390 ( V_658 ) -> V_843 != NULL &&
! ( V_710 && F_381 ( V_710 ) ) )
return V_832 ;
#endif
if ( V_710 == NULL ) {
if ( V_658 -> V_783 ) {
V_842 = V_844 ;
if ( F_302 ( V_658 , V_194 , & V_771 ) )
return V_833 ;
} else {
V_842 = V_839 ;
V_771 = V_18 ;
}
} else if ( F_381 ( V_710 ) ) {
T_2 V_704 ;
struct V_711 * V_712 ;
V_712 = V_710 -> V_713 ;
if ( F_302 ( V_658 , V_194 , & V_704 ) )
return V_833 ;
if ( V_704 == V_706 ) {
switch ( V_194 ) {
case V_201 :
if ( F_391 ( V_658 ) -> V_86 & V_845 )
return V_832 ;
break;
case V_202 :
if ( F_392 ( V_658 ) -> V_86 & V_846 )
return V_832 ;
break;
default:
return F_386 ( - V_840 ) ;
}
}
if ( F_306 ( V_712 -> V_17 , V_704 , & V_771 ) )
return V_833 ;
V_842 = V_839 ;
} else {
struct V_711 * V_712 = V_710 -> V_713 ;
V_771 = V_712 -> V_17 ;
V_842 = V_839 ;
}
V_287 . type = V_715 ;
V_287 . V_292 . V_666 = & V_666 ;
V_287 . V_292 . V_666 -> V_782 = V_775 ;
V_287 . V_292 . V_666 -> V_194 = V_194 ;
if ( F_300 ( V_658 , & V_287 , & V_695 , 0 , NULL ) )
return V_833 ;
if ( V_787 )
if ( F_55 ( V_771 , V_658 -> V_784 ,
V_785 , V_842 , & V_287 ) )
return F_386 ( - V_840 ) ;
if ( V_788 ) {
T_2 V_776 ;
T_2 V_777 ;
if ( F_335 ( F_376 ( V_841 ) , V_775 , & V_776 ) )
return V_833 ;
if ( F_55 ( V_771 , V_776 ,
V_778 , V_847 , & V_287 ) )
return F_386 ( - V_840 ) ;
if ( F_319 ( V_695 , V_194 , & V_777 ) )
return V_833 ;
if ( F_55 ( V_771 , V_777 ,
V_780 , V_848 , & V_287 ) )
return F_386 ( - V_840 ) ;
}
return V_832 ;
}
static unsigned int F_393 ( void * V_835 ,
struct V_657 * V_658 ,
const struct V_836 * V_837 )
{
return F_388 ( V_658 , V_837 -> V_81 , V_201 ) ;
}
static unsigned int F_394 ( void * V_835 ,
struct V_657 * V_658 ,
const struct V_836 * V_837 )
{
return F_388 ( V_658 , V_837 -> V_81 , V_202 ) ;
}
static int F_395 ( struct V_709 * V_710 , struct V_657 * V_658 )
{
return F_369 ( V_710 , V_658 ) ;
}
static int F_396 ( struct V_20 * V_21 ,
struct V_849 * V_262 ,
T_4 V_31 )
{
struct V_850 * V_24 ;
T_2 V_17 ;
V_24 = F_15 ( sizeof( struct V_850 ) , V_15 ) ;
if ( ! V_24 )
return - V_27 ;
V_17 = F_18 ( V_21 ) ;
V_24 -> V_31 = V_31 ;
V_24 -> V_17 = V_17 ;
V_262 -> V_19 = V_24 ;
return 0 ;
}
static void F_397 ( struct V_849 * V_262 )
{
struct V_850 * V_24 = V_262 -> V_19 ;
V_262 -> V_19 = NULL ;
F_52 ( V_24 ) ;
}
static int F_398 ( struct V_851 * V_755 )
{
struct V_852 * V_853 ;
V_853 = F_15 ( sizeof( struct V_852 ) , V_15 ) ;
if ( ! V_853 )
return - V_27 ;
V_853 -> V_17 = V_30 ;
V_755 -> V_19 = V_853 ;
return 0 ;
}
static void F_399 ( struct V_851 * V_755 )
{
struct V_852 * V_853 = V_755 -> V_19 ;
V_755 -> V_19 = NULL ;
F_52 ( V_853 ) ;
}
static int F_400 ( struct V_849 * V_854 ,
T_2 V_272 )
{
struct V_850 * V_24 ;
struct V_286 V_287 ;
T_2 V_17 = F_22 () ;
V_24 = V_854 -> V_19 ;
V_287 . type = V_855 ;
V_287 . V_292 . V_856 = V_854 -> V_857 ;
return F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_272 , & V_287 ) ;
}
static int F_401 ( struct V_851 * V_755 )
{
return F_398 ( V_755 ) ;
}
static void F_402 ( struct V_851 * V_755 )
{
F_399 ( V_755 ) ;
}
static int F_403 ( struct V_858 * V_859 )
{
struct V_850 * V_24 ;
struct V_286 V_287 ;
T_2 V_17 = F_22 () ;
int V_61 ;
V_61 = F_396 ( V_11 , & V_859 -> V_860 , V_861 ) ;
if ( V_61 )
return V_61 ;
V_24 = V_859 -> V_860 . V_19 ;
V_287 . type = V_855 ;
V_287 . V_292 . V_856 = V_859 -> V_860 . V_857 ;
V_61 = F_55 ( V_17 , V_24 -> V_17 , V_861 ,
V_862 , & V_287 ) ;
if ( V_61 ) {
F_397 ( & V_859 -> V_860 ) ;
return V_61 ;
}
return 0 ;
}
static void F_404 ( struct V_858 * V_859 )
{
F_397 ( & V_859 -> V_860 ) ;
}
static int F_405 ( struct V_858 * V_859 , int V_863 )
{
struct V_850 * V_24 ;
struct V_286 V_287 ;
T_2 V_17 = F_22 () ;
V_24 = V_859 -> V_860 . V_19 ;
V_287 . type = V_855 ;
V_287 . V_292 . V_856 = V_859 -> V_860 . V_857 ;
return F_55 ( V_17 , V_24 -> V_17 , V_861 ,
V_864 , & V_287 ) ;
}
static int F_406 ( struct V_858 * V_859 , int V_554 )
{
int V_606 ;
int V_272 ;
switch ( V_554 ) {
case V_865 :
case V_866 :
return F_123 ( V_11 , V_867 ) ;
case V_868 :
case V_869 :
V_272 = V_870 | V_864 ;
break;
case V_871 :
V_272 = V_872 ;
break;
case V_873 :
V_272 = V_874 ;
break;
default:
return 0 ;
}
V_606 = F_400 ( & V_859 -> V_860 , V_272 ) ;
return V_606 ;
}
static int F_407 ( struct V_858 * V_859 , struct V_851 * V_755 , int V_863 )
{
struct V_850 * V_24 ;
struct V_852 * V_853 ;
struct V_286 V_287 ;
T_2 V_17 = F_22 () ;
int V_61 ;
V_24 = V_859 -> V_860 . V_19 ;
V_853 = V_755 -> V_19 ;
if ( V_853 -> V_17 == V_30 ) {
V_61 = F_79 ( V_17 , V_24 -> V_17 , V_875 ,
NULL , & V_853 -> V_17 ) ;
if ( V_61 )
return V_61 ;
}
V_287 . type = V_855 ;
V_287 . V_292 . V_856 = V_859 -> V_860 . V_857 ;
V_61 = F_55 ( V_17 , V_24 -> V_17 , V_861 ,
V_876 , & V_287 ) ;
if ( ! V_61 )
V_61 = F_55 ( V_17 , V_853 -> V_17 , V_875 ,
V_877 , & V_287 ) ;
if ( ! V_61 )
V_61 = F_55 ( V_853 -> V_17 , V_24 -> V_17 , V_861 ,
V_878 , & V_287 ) ;
return V_61 ;
}
static int F_408 ( struct V_858 * V_859 , struct V_851 * V_755 ,
struct V_20 * V_271 ,
long type , int V_175 )
{
struct V_850 * V_24 ;
struct V_852 * V_853 ;
struct V_286 V_287 ;
T_2 V_17 = F_18 ( V_271 ) ;
int V_61 ;
V_24 = V_859 -> V_860 . V_19 ;
V_853 = V_755 -> V_19 ;
V_287 . type = V_855 ;
V_287 . V_292 . V_856 = V_859 -> V_860 . V_857 ;
V_61 = F_55 ( V_17 , V_24 -> V_17 ,
V_861 , V_879 , & V_287 ) ;
if ( ! V_61 )
V_61 = F_55 ( V_17 , V_853 -> V_17 ,
V_875 , V_880 , & V_287 ) ;
return V_61 ;
}
static int F_409 ( struct V_881 * V_882 )
{
struct V_850 * V_24 ;
struct V_286 V_287 ;
T_2 V_17 = F_22 () ;
int V_61 ;
V_61 = F_396 ( V_11 , & V_882 -> V_883 , V_884 ) ;
if ( V_61 )
return V_61 ;
V_24 = V_882 -> V_883 . V_19 ;
V_287 . type = V_855 ;
V_287 . V_292 . V_856 = V_882 -> V_883 . V_857 ;
V_61 = F_55 ( V_17 , V_24 -> V_17 , V_884 ,
V_885 , & V_287 ) ;
if ( V_61 ) {
F_397 ( & V_882 -> V_883 ) ;
return V_61 ;
}
return 0 ;
}
static void F_410 ( struct V_881 * V_882 )
{
F_397 ( & V_882 -> V_883 ) ;
}
static int F_411 ( struct V_881 * V_882 , int V_886 )
{
struct V_850 * V_24 ;
struct V_286 V_287 ;
T_2 V_17 = F_22 () ;
V_24 = V_882 -> V_883 . V_19 ;
V_287 . type = V_855 ;
V_287 . V_292 . V_856 = V_882 -> V_883 . V_857 ;
return F_55 ( V_17 , V_24 -> V_17 , V_884 ,
V_887 , & V_287 ) ;
}
static int F_412 ( struct V_881 * V_882 , int V_554 )
{
int V_272 ;
int V_606 ;
switch ( V_554 ) {
case V_865 :
case V_888 :
return F_123 ( V_11 , V_867 ) ;
case V_868 :
case V_889 :
V_272 = V_890 | V_887 ;
break;
case V_871 :
V_272 = V_891 ;
break;
case V_892 :
case V_893 :
V_272 = V_894 ;
break;
case V_873 :
V_272 = V_895 ;
break;
default:
return 0 ;
}
V_606 = F_400 ( & V_882 -> V_883 , V_272 ) ;
return V_606 ;
}
static int F_413 ( struct V_881 * V_882 ,
char T_15 * V_896 , int V_886 )
{
T_2 V_272 ;
if ( V_886 & V_897 )
V_272 = V_898 ;
else
V_272 = V_898 | V_899 ;
return F_400 ( & V_882 -> V_883 , V_272 ) ;
}
static int F_414 ( struct V_900 * V_901 )
{
struct V_850 * V_24 ;
struct V_286 V_287 ;
T_2 V_17 = F_22 () ;
int V_61 ;
V_61 = F_396 ( V_11 , & V_901 -> V_902 , V_903 ) ;
if ( V_61 )
return V_61 ;
V_24 = V_901 -> V_902 . V_19 ;
V_287 . type = V_855 ;
V_287 . V_292 . V_856 = V_901 -> V_902 . V_857 ;
V_61 = F_55 ( V_17 , V_24 -> V_17 , V_903 ,
V_904 , & V_287 ) ;
if ( V_61 ) {
F_397 ( & V_901 -> V_902 ) ;
return V_61 ;
}
return 0 ;
}
static void F_415 ( struct V_900 * V_901 )
{
F_397 ( & V_901 -> V_902 ) ;
}
static int F_416 ( struct V_900 * V_901 , int V_905 )
{
struct V_850 * V_24 ;
struct V_286 V_287 ;
T_2 V_17 = F_22 () ;
V_24 = V_901 -> V_902 . V_19 ;
V_287 . type = V_855 ;
V_287 . V_292 . V_856 = V_901 -> V_902 . V_857 ;
return F_55 ( V_17 , V_24 -> V_17 , V_903 ,
V_906 , & V_287 ) ;
}
static int F_417 ( struct V_900 * V_901 , int V_554 )
{
int V_606 ;
T_2 V_272 ;
switch ( V_554 ) {
case V_865 :
case V_907 :
return F_123 ( V_11 , V_867 ) ;
case V_908 :
case V_909 :
case V_910 :
V_272 = V_911 ;
break;
case V_912 :
case V_913 :
V_272 = V_914 ;
break;
case V_915 :
case V_916 :
V_272 = V_917 ;
break;
case V_873 :
V_272 = V_918 ;
break;
case V_871 :
V_272 = V_919 ;
break;
case V_868 :
case V_920 :
V_272 = V_911 | V_906 ;
break;
default:
return 0 ;
}
V_606 = F_400 ( & V_901 -> V_902 , V_272 ) ;
return V_606 ;
}
static int F_418 ( struct V_900 * V_901 ,
struct V_921 * V_922 , unsigned V_923 , int V_924 )
{
T_2 V_272 ;
if ( V_924 )
V_272 = V_914 | V_917 ;
else
V_272 = V_914 ;
return F_400 ( & V_901 -> V_902 , V_272 ) ;
}
static int F_419 ( struct V_849 * V_925 , short V_109 )
{
T_2 V_290 = 0 ;
V_290 = 0 ;
if ( V_109 & V_926 )
V_290 |= V_927 ;
if ( V_109 & V_928 )
V_290 |= V_929 ;
if ( V_290 == 0 )
return 0 ;
return F_400 ( V_925 , V_290 ) ;
}
static void F_420 ( struct V_849 * V_925 , T_2 * V_550 )
{
struct V_850 * V_24 = V_925 -> V_19 ;
* V_550 = V_24 -> V_17 ;
}
static void F_421 ( struct V_34 * V_34 , struct V_22 * V_22 )
{
if ( V_22 )
F_30 ( V_22 , V_34 ) ;
}
static int F_422 ( struct V_20 * V_152 ,
char * V_72 , char * * V_507 )
{
const struct V_13 * V_810 ;
T_2 V_17 ;
int error ;
unsigned V_95 ;
if ( V_11 != V_152 ) {
error = F_117 ( V_152 , V_930 ) ;
if ( error )
return error ;
}
F_19 () ;
V_810 = F_20 ( V_152 ) -> V_19 ;
if ( ! strcmp ( V_72 , L_50 ) )
V_17 = V_810 -> V_17 ;
else if ( ! strcmp ( V_72 , L_51 ) )
V_17 = V_810 -> V_16 ;
else if ( ! strcmp ( V_72 , L_52 ) )
V_17 = V_810 -> V_429 ;
else if ( ! strcmp ( V_72 , L_53 ) )
V_17 = V_810 -> V_309 ;
else if ( ! strcmp ( V_72 , L_54 ) )
V_17 = V_810 -> V_427 ;
else if ( ! strcmp ( V_72 , L_55 ) )
V_17 = V_810 -> V_428 ;
else
goto V_931;
F_21 () ;
if ( ! V_17 )
return 0 ;
error = F_70 ( V_17 , V_507 , & V_95 ) ;
if ( error )
return error ;
return V_95 ;
V_931:
F_21 () ;
return - V_97 ;
}
static int F_423 ( struct V_20 * V_152 ,
char * V_72 , void * V_507 , T_7 V_538 )
{
struct V_13 * V_14 ;
struct V_10 * V_137 ;
T_2 V_17 = 0 , V_437 ;
int error ;
char * V_1 = V_507 ;
if ( V_11 != V_152 ) {
return - V_130 ;
}
if ( ! strcmp ( V_72 , L_52 ) )
error = F_117 ( V_152 , V_932 ) ;
else if ( ! strcmp ( V_72 , L_53 ) )
error = F_117 ( V_152 , V_933 ) ;
else if ( ! strcmp ( V_72 , L_54 ) )
error = F_117 ( V_152 , V_934 ) ;
else if ( ! strcmp ( V_72 , L_55 ) )
error = F_117 ( V_152 , V_935 ) ;
else if ( ! strcmp ( V_72 , L_50 ) )
error = F_117 ( V_152 , V_936 ) ;
else
error = - V_97 ;
if ( error )
return error ;
if ( V_538 && V_1 [ 1 ] && V_1 [ 1 ] != '\n' ) {
if ( V_1 [ V_538 - 1 ] == '\n' ) {
V_1 [ V_538 - 1 ] = 0 ;
V_538 -- ;
}
error = F_234 ( V_507 , V_538 , & V_17 , V_15 ) ;
if ( error == - V_97 && ! strcmp ( V_72 , L_53 ) ) {
if ( ! F_231 ( V_540 ) ) {
struct V_541 * V_542 ;
T_7 V_543 ;
if ( V_1 [ V_538 - 1 ] == '\0' )
V_543 = V_538 - 1 ;
else
V_543 = V_538 ;
V_542 = F_235 ( V_11 -> V_544 , V_102 , V_545 ) ;
F_236 ( V_542 , L_56 ) ;
F_237 ( V_542 , V_507 , V_543 ) ;
F_238 ( V_542 ) ;
return error ;
}
error = F_239 ( V_507 , V_538 ,
& V_17 ) ;
}
if ( error )
return error ;
}
V_137 = F_424 () ;
if ( ! V_137 )
return - V_27 ;
V_14 = V_137 -> V_19 ;
if ( ! strcmp ( V_72 , L_52 ) ) {
V_14 -> V_429 = V_17 ;
} else if ( ! strcmp ( V_72 , L_53 ) ) {
V_14 -> V_309 = V_17 ;
} else if ( ! strcmp ( V_72 , L_54 ) ) {
error = F_134 ( V_17 , V_152 ) ;
if ( error )
goto V_937;
V_14 -> V_427 = V_17 ;
} else if ( ! strcmp ( V_72 , L_55 ) ) {
V_14 -> V_428 = V_17 ;
} else if ( ! strcmp ( V_72 , L_50 ) ) {
error = - V_97 ;
if ( V_17 == 0 )
goto V_937;
error = - V_425 ;
if ( ! F_425 () ) {
error = F_161 ( V_14 -> V_17 , V_17 ) ;
if ( error )
goto V_937;
}
error = F_55 ( V_14 -> V_17 , V_17 , V_275 ,
V_938 , NULL ) ;
if ( error )
goto V_937;
V_437 = F_157 ( V_152 ) ;
if ( V_437 != 0 ) {
error = F_55 ( V_437 , V_17 , V_275 ,
V_374 , NULL ) ;
if ( error )
goto V_937;
}
V_14 -> V_17 = V_17 ;
} else {
error = - V_97 ;
goto V_937;
}
F_426 ( V_137 ) ;
return V_538 ;
V_937:
F_427 ( V_137 ) ;
return error ;
}
static int F_428 ( const char * V_72 )
{
return ( strcmp ( V_72 , V_509 ) == 0 ) ;
}
static int F_429 ( T_2 V_550 , char * * V_491 , T_2 * V_939 )
{
return F_70 ( V_550 , V_491 , V_939 ) ;
}
static int F_430 ( const char * V_491 , T_2 V_939 , T_2 * V_550 )
{
return F_234 ( V_491 , V_939 , V_550 , V_15 ) ;
}
static void F_431 ( char * V_491 , T_2 V_939 )
{
F_52 ( V_491 ) ;
}
static void F_432 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
F_76 ( & V_24 -> V_28 ) ;
V_24 -> V_38 = V_940 ;
F_80 ( & V_24 -> V_28 ) ;
}
static int F_433 ( struct V_22 * V_22 , void * V_317 , T_2 V_505 )
{
return F_247 ( V_22 , V_509 , V_317 , V_505 , 0 ) ;
}
static int F_434 ( struct V_34 * V_34 , void * V_317 , T_2 V_505 )
{
return F_435 ( V_34 , V_82 , V_317 , V_505 , 0 ) ;
}
static int F_436 ( struct V_22 * V_22 , void * * V_317 , T_2 * V_505 )
{
int V_95 = 0 ;
V_95 = F_245 ( V_22 , V_509 ,
V_317 , true ) ;
if ( V_95 < 0 )
return V_95 ;
* V_505 = V_95 ;
return 0 ;
}
static int F_437 ( struct V_857 * V_941 , const struct V_10 * V_10 ,
unsigned long V_86 )
{
const struct V_13 * V_14 ;
struct V_942 * V_943 ;
V_943 = F_15 ( sizeof( struct V_942 ) , V_15 ) ;
if ( ! V_943 )
return - V_27 ;
V_14 = V_10 -> V_19 ;
if ( V_14 -> V_427 )
V_943 -> V_17 = V_14 -> V_427 ;
else
V_943 -> V_17 = V_14 -> V_17 ;
V_941 -> V_19 = V_943 ;
return 0 ;
}
static void F_438 ( struct V_857 * V_941 )
{
struct V_942 * V_943 = V_941 -> V_19 ;
V_941 -> V_19 = NULL ;
F_52 ( V_943 ) ;
}
static int F_439 ( T_16 V_944 ,
const struct V_10 * V_10 ,
unsigned V_262 )
{
struct V_857 * V_857 ;
struct V_942 * V_943 ;
T_2 V_17 ;
if ( V_262 == 0 )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_857 = F_440 ( V_944 ) ;
V_943 = V_857 -> V_19 ;
return F_55 ( V_17 , V_943 -> V_17 , V_318 , V_262 , NULL ) ;
}
static int F_441 ( struct V_857 * V_857 , char * * V_945 )
{
struct V_942 * V_943 = V_857 -> V_19 ;
char * V_94 = NULL ;
unsigned V_95 ;
int V_61 ;
V_61 = F_70 ( V_943 -> V_17 , & V_94 , & V_95 ) ;
if ( ! V_61 )
V_61 = V_95 ;
* V_945 = V_94 ;
return V_61 ;
}
static T_1 int F_442 ( void )
{
if ( ! F_443 ( L_57 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_59 ( V_946 L_58 ) ;
return 0 ;
}
F_59 ( V_946 L_59 ) ;
F_14 () ;
V_577 = ! ( V_947 & V_592 ) ;
V_25 = F_444 ( L_60 ,
sizeof( struct V_23 ) ,
0 , V_948 , NULL ) ;
V_52 = F_444 ( L_61 ,
sizeof( struct V_50 ) ,
0 , V_948 , NULL ) ;
F_445 () ;
F_446 ( V_949 , F_60 ( V_949 ) ) ;
if ( F_447 ( F_9 , V_9 ) )
F_16 ( L_62 ) ;
if ( V_3 )
F_59 ( V_950 L_63 ) ;
else
F_59 ( V_950 L_64 ) ;
return 0 ;
}
static void F_448 ( struct V_55 * V_56 , void * V_951 )
{
F_87 ( V_56 , NULL ) ;
}
void F_449 ( void )
{
F_59 ( V_950 L_65 ) ;
F_59 ( V_950 L_66 ) ;
F_450 ( F_448 , NULL ) ;
}
static int T_1 F_451 ( void )
{
int V_606 ;
if ( ! V_5 )
return 0 ;
F_59 ( V_950 L_67 ) ;
V_606 = F_452 ( V_952 , F_60 ( V_952 ) ) ;
if ( V_606 )
F_16 ( L_68 , V_606 ) ;
return 0 ;
}
static void F_453 ( void )
{
F_59 ( V_950 L_69 ) ;
F_454 ( V_952 , F_60 ( V_952 ) ) ;
}
int F_455 ( void )
{
if ( V_37 ) {
return - V_97 ;
}
if ( V_953 ) {
return - V_97 ;
}
F_59 ( V_946 L_70 ) ;
V_953 = 1 ;
V_5 = 0 ;
F_456 ( V_949 , F_60 ( V_949 ) ) ;
F_457 () ;
F_453 () ;
F_458 () ;
return 0 ;
}
