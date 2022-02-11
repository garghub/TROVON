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
V_24 -> V_33 = V_34 ;
V_22 -> V_35 = V_24 ;
return 0 ;
}
static int F_28 ( struct V_22 * V_22 ,
struct V_36 * V_37 ,
bool V_38 )
{
struct V_23 * V_24 = V_22 -> V_35 ;
F_29 ( V_38 ) ;
if ( V_39 && V_24 -> V_33 != V_40 ) {
if ( ! V_38 )
return - V_41 ;
F_30 ( V_22 , V_37 ) ;
}
return 0 ;
}
static struct V_23 * F_31 ( struct V_22 * V_22 )
{
return V_22 -> V_35 ;
}
static struct V_23 * F_32 ( struct V_22 * V_22 , bool V_42 )
{
int error ;
error = F_28 ( V_22 , NULL , ! V_42 ) ;
if ( error )
return F_33 ( error ) ;
return V_22 -> V_35 ;
}
static struct V_23 * F_34 ( struct V_22 * V_22 )
{
F_28 ( V_22 , NULL , true ) ;
return V_22 -> V_35 ;
}
static struct V_23 * F_35 ( struct V_36 * V_36 )
{
struct V_22 * V_22 = F_36 ( V_36 ) ;
return V_22 -> V_35 ;
}
static struct V_23 * F_37 ( struct V_36 * V_36 )
{
struct V_22 * V_22 = F_36 ( V_36 ) ;
F_28 ( V_22 , V_36 , true ) ;
return V_22 -> V_35 ;
}
static void F_38 ( struct V_43 * V_44 )
{
struct V_23 * V_24 ;
V_24 = F_39 ( V_44 , struct V_23 , V_42 ) ;
F_40 ( V_25 , V_24 ) ;
}
static void F_41 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_35 ;
struct V_45 * V_46 = V_22 -> V_47 -> V_48 ;
if ( ! F_42 ( & V_24 -> V_29 ) ) {
F_43 ( & V_46 -> V_49 ) ;
F_44 ( & V_24 -> V_29 ) ;
F_45 ( & V_46 -> V_49 ) ;
}
F_46 ( & V_24 -> V_42 , F_38 ) ;
}
static int F_47 ( struct V_50 * V_50 )
{
struct V_51 * V_52 ;
T_2 V_17 = F_22 () ;
V_52 = F_25 ( V_53 , V_15 ) ;
if ( ! V_52 )
return - V_27 ;
V_52 -> V_17 = V_17 ;
V_52 -> V_54 = V_17 ;
V_50 -> V_55 = V_52 ;
return 0 ;
}
static void F_48 ( struct V_50 * V_50 )
{
struct V_51 * V_52 = V_50 -> V_55 ;
V_50 -> V_55 = NULL ;
F_40 ( V_53 , V_52 ) ;
}
static int F_49 ( struct V_56 * V_57 )
{
struct V_45 * V_46 ;
V_46 = F_15 ( sizeof( struct V_45 ) , V_15 ) ;
if ( ! V_46 )
return - V_27 ;
F_50 ( & V_46 -> V_28 ) ;
F_27 ( & V_46 -> V_58 ) ;
F_26 ( & V_46 -> V_49 ) ;
V_46 -> V_57 = V_57 ;
V_46 -> V_17 = V_30 ;
V_46 -> V_59 = V_60 ;
V_46 -> V_61 = V_30 ;
V_57 -> V_48 = V_46 ;
return 0 ;
}
static void F_51 ( struct V_56 * V_57 )
{
struct V_45 * V_46 = V_57 -> V_48 ;
V_57 -> V_48 = NULL ;
F_52 ( V_46 ) ;
}
static inline int F_53 ( struct V_22 * V_22 )
{
return F_30 ( V_22 , NULL ) ;
}
static int F_54 ( T_2 V_17 ,
struct V_45 * V_46 ,
const struct V_10 * V_10 )
{
const struct V_13 * V_14 = V_10 -> V_19 ;
int V_62 ;
V_62 = F_55 ( V_14 -> V_17 , V_46 -> V_17 , V_63 ,
V_64 , NULL ) ;
if ( V_62 )
return V_62 ;
V_62 = F_55 ( V_14 -> V_17 , V_17 , V_63 ,
V_65 , NULL ) ;
return V_62 ;
}
static int F_56 ( T_2 V_17 ,
struct V_45 * V_46 ,
const struct V_10 * V_10 )
{
const struct V_13 * V_14 = V_10 -> V_19 ;
int V_62 ;
V_62 = F_55 ( V_14 -> V_17 , V_46 -> V_17 , V_63 ,
V_64 , NULL ) ;
if ( V_62 )
return V_62 ;
V_62 = F_55 ( V_17 , V_46 -> V_17 , V_63 ,
V_66 , NULL ) ;
return V_62 ;
}
static int F_57 ( struct V_56 * V_57 )
{
struct V_45 * V_46 = V_57 -> V_48 ;
return V_46 -> V_67 == V_68 ||
V_46 -> V_67 == V_69 ||
V_46 -> V_67 == V_70 ||
V_46 -> V_67 == V_71 ||
! strcmp ( V_57 -> V_72 -> V_73 , L_2 ) ||
! strcmp ( V_57 -> V_72 -> V_73 , L_3 ) ||
! strcmp ( V_57 -> V_72 -> V_73 , L_4 ) ||
! strcmp ( V_57 -> V_72 -> V_73 , L_5 ) ;
}
static int F_58 ( struct V_56 * V_57 )
{
struct V_45 * V_46 = V_57 -> V_48 ;
struct V_36 * V_74 = V_57 -> V_75 ;
struct V_22 * V_76 = F_36 ( V_74 ) ;
int V_62 = 0 ;
if ( V_46 -> V_67 == V_68 ) {
if ( ! ( V_76 -> V_77 & V_78 ) ) {
F_59 ( V_79 L_6
L_7 , V_57 -> V_80 , V_57 -> V_72 -> V_73 ) ;
V_62 = - V_81 ;
goto V_82;
}
V_62 = F_60 ( V_74 , V_76 , V_83 , NULL , 0 ) ;
if ( V_62 < 0 && V_62 != - V_84 ) {
if ( V_62 == - V_81 )
F_59 ( V_79 L_8
L_9 ,
V_57 -> V_80 , V_57 -> V_72 -> V_73 ) ;
else
F_59 ( V_79 L_8
L_10 , V_57 -> V_80 ,
V_57 -> V_72 -> V_73 , - V_62 ) ;
goto V_82;
}
}
if ( V_46 -> V_67 > F_61 ( V_85 ) )
F_59 ( V_86 L_11 ,
V_57 -> V_80 , V_57 -> V_72 -> V_73 ) ;
V_46 -> V_87 |= V_88 ;
if ( F_57 ( V_57 ) )
V_46 -> V_87 |= V_89 ;
V_62 = F_30 ( V_76 , V_74 ) ;
F_43 ( & V_46 -> V_49 ) ;
V_90:
if ( ! F_62 ( & V_46 -> V_58 ) ) {
struct V_23 * V_24 =
F_63 ( V_46 -> V_58 . V_91 ,
struct V_23 , V_29 ) ;
struct V_22 * V_22 = V_24 -> V_22 ;
F_44 ( & V_24 -> V_29 ) ;
F_45 ( & V_46 -> V_49 ) ;
V_22 = F_64 ( V_22 ) ;
if ( V_22 ) {
if ( ! F_65 ( V_22 ) )
F_53 ( V_22 ) ;
F_66 ( V_22 ) ;
}
F_43 ( & V_46 -> V_49 ) ;
goto V_90;
}
F_45 ( & V_46 -> V_49 ) ;
V_82:
return V_62 ;
}
static int F_67 ( const struct V_56 * V_57 ,
struct V_92 * V_93 )
{
int V_62 = 0 , V_94 ;
struct V_45 * V_46 = V_57 -> V_48 ;
char * V_95 = NULL ;
T_2 V_96 ;
char V_97 ;
F_68 ( V_93 ) ;
if ( ! ( V_46 -> V_87 & V_88 ) )
return - V_98 ;
if ( ! V_39 )
return - V_98 ;
F_69 ( V_99 >= ( 1 << V_100 ) ) ;
V_97 = V_46 -> V_87 & V_99 ;
for ( V_94 = 0 ; V_94 < V_100 ; V_94 ++ ) {
if ( V_97 & 0x01 )
V_93 -> V_101 ++ ;
V_97 >>= 1 ;
}
if ( V_46 -> V_87 & V_89 )
V_93 -> V_101 ++ ;
V_93 -> V_102 = F_70 ( V_93 -> V_101 , sizeof( char * ) , V_103 ) ;
if ( ! V_93 -> V_102 ) {
V_62 = - V_27 ;
goto V_104;
}
V_93 -> V_105 = F_70 ( V_93 -> V_101 , sizeof( int ) , V_103 ) ;
if ( ! V_93 -> V_105 ) {
V_62 = - V_27 ;
goto V_104;
}
V_94 = 0 ;
if ( V_46 -> V_87 & V_106 ) {
V_62 = F_71 ( V_46 -> V_17 , & V_95 , & V_96 ) ;
if ( V_62 )
goto V_104;
V_93 -> V_102 [ V_94 ] = V_95 ;
V_93 -> V_105 [ V_94 ++ ] = V_106 ;
}
if ( V_46 -> V_87 & V_107 ) {
V_62 = F_71 ( V_46 -> V_61 , & V_95 , & V_96 ) ;
if ( V_62 )
goto V_104;
V_93 -> V_102 [ V_94 ] = V_95 ;
V_93 -> V_105 [ V_94 ++ ] = V_107 ;
}
if ( V_46 -> V_87 & V_108 ) {
V_62 = F_71 ( V_46 -> V_59 , & V_95 , & V_96 ) ;
if ( V_62 )
goto V_104;
V_93 -> V_102 [ V_94 ] = V_95 ;
V_93 -> V_105 [ V_94 ++ ] = V_108 ;
}
if ( V_46 -> V_87 & V_109 ) {
struct V_36 * V_74 = V_46 -> V_57 -> V_75 ;
struct V_23 * V_24 = F_37 ( V_74 ) ;
V_62 = F_71 ( V_24 -> V_17 , & V_95 , & V_96 ) ;
if ( V_62 )
goto V_104;
V_93 -> V_102 [ V_94 ] = V_95 ;
V_93 -> V_105 [ V_94 ++ ] = V_109 ;
}
if ( V_46 -> V_87 & V_89 ) {
V_93 -> V_102 [ V_94 ] = NULL ;
V_93 -> V_105 [ V_94 ++ ] = V_89 ;
}
F_72 ( V_94 != V_93 -> V_101 ) ;
return 0 ;
V_104:
F_73 ( V_93 ) ;
return V_62 ;
}
static int F_74 ( struct V_45 * V_46 , char V_110 ,
T_2 V_111 , T_2 V_112 )
{
char V_113 = V_46 -> V_87 & V_99 ;
if ( V_46 -> V_87 & V_88 )
if ( ! ( V_46 -> V_87 & V_110 ) ||
( V_111 != V_112 ) )
return 1 ;
if ( ! ( V_46 -> V_87 & V_88 ) )
if ( V_113 & V_110 )
return 1 ;
return 0 ;
}
static int F_75 ( struct V_56 * V_57 ,
struct V_92 * V_93 ,
unsigned long V_114 ,
unsigned long * V_115 )
{
const struct V_10 * V_10 = F_76 () ;
int V_62 = 0 , V_94 ;
struct V_45 * V_46 = V_57 -> V_48 ;
const char * V_73 = V_57 -> V_72 -> V_73 ;
struct V_36 * V_74 = V_46 -> V_57 -> V_75 ;
struct V_23 * V_116 ;
T_2 V_117 = 0 , V_118 = 0 , V_119 = 0 ;
T_2 V_120 = 0 ;
char * * V_121 = V_93 -> V_102 ;
int * V_87 = V_93 -> V_105 ;
int V_122 = V_93 -> V_101 ;
F_77 ( & V_46 -> V_28 ) ;
if ( ! V_39 ) {
if ( ! V_122 ) {
goto V_82;
}
V_62 = - V_98 ;
F_59 ( V_79 L_12
L_13 ) ;
goto V_82;
}
if ( V_114 && ! V_115 ) {
V_62 = - V_98 ;
goto V_82;
}
if ( ( V_46 -> V_87 & V_88 ) && ( V_57 -> V_72 -> V_123 & V_124 )
&& ( V_122 == 0 ) )
goto V_82;
V_116 = F_35 ( V_74 ) ;
for ( V_94 = 0 ; V_94 < V_122 ; V_94 ++ ) {
T_2 V_17 ;
if ( V_87 [ V_94 ] == V_89 )
continue;
V_62 = F_78 ( V_121 [ V_94 ] , & V_17 , V_15 ) ;
if ( V_62 ) {
F_59 ( V_79 L_14
L_15 ,
V_121 [ V_94 ] , V_57 -> V_80 , V_73 , V_62 ) ;
goto V_82;
}
switch ( V_87 [ V_94 ] ) {
case V_106 :
V_117 = V_17 ;
if ( F_74 ( V_46 , V_106 , V_46 -> V_17 ,
V_117 ) )
goto V_125;
V_46 -> V_87 |= V_106 ;
break;
case V_107 :
V_118 = V_17 ;
if ( F_74 ( V_46 , V_107 , V_46 -> V_61 ,
V_118 ) )
goto V_125;
V_46 -> V_87 |= V_107 ;
break;
case V_109 :
V_119 = V_17 ;
if ( F_74 ( V_46 , V_109 , V_116 -> V_17 ,
V_119 ) )
goto V_125;
V_46 -> V_87 |= V_109 ;
break;
case V_108 :
V_120 = V_17 ;
if ( F_74 ( V_46 , V_108 , V_46 -> V_59 ,
V_120 ) )
goto V_125;
V_46 -> V_87 |= V_108 ;
break;
default:
V_62 = - V_98 ;
goto V_82;
}
}
if ( V_46 -> V_87 & V_88 ) {
if ( ( V_46 -> V_87 & V_99 ) && ! V_122 )
goto V_125;
V_62 = 0 ;
goto V_82;
}
if ( strcmp ( V_57 -> V_72 -> V_73 , L_16 ) == 0 )
V_46 -> V_87 |= V_126 | V_127 ;
if ( ! strcmp ( V_57 -> V_72 -> V_73 , L_4 ) ||
! strcmp ( V_57 -> V_72 -> V_73 , L_2 ) ||
! strcmp ( V_57 -> V_72 -> V_73 , L_3 ) )
V_46 -> V_87 |= V_127 ;
if ( ! V_46 -> V_67 ) {
V_62 = F_79 ( V_57 ) ;
if ( V_62 ) {
F_59 ( V_79
L_17 ,
V_128 , V_57 -> V_72 -> V_73 , V_62 ) ;
goto V_82;
}
}
if ( V_57 -> V_129 != & V_130 ) {
if ( V_118 || V_117 || V_119 ||
V_120 ) {
V_62 = - V_131 ;
goto V_82;
}
if ( V_46 -> V_67 == V_68 ) {
V_46 -> V_67 = V_132 ;
V_62 = F_80 ( F_22 () , F_22 () ,
V_32 , NULL ,
& V_46 -> V_61 ) ;
if ( V_62 )
goto V_82;
}
goto V_133;
}
if ( V_117 ) {
V_62 = F_54 ( V_117 , V_46 , V_10 ) ;
if ( V_62 )
goto V_82;
V_46 -> V_17 = V_117 ;
}
if ( V_114 & V_134 && ! V_118 ) {
V_46 -> V_67 = V_71 ;
* V_115 |= V_134 ;
}
if ( V_118 ) {
if ( ! V_117 ) {
V_62 = F_54 ( V_118 , V_46 ,
V_10 ) ;
if ( V_62 )
goto V_82;
V_46 -> V_17 = V_118 ;
} else {
V_62 = F_56 ( V_118 , V_46 ,
V_10 ) ;
if ( V_62 )
goto V_82;
}
if ( ! V_119 )
V_119 = V_118 ;
V_46 -> V_61 = V_118 ;
V_46 -> V_67 = V_132 ;
}
if ( V_119 ) {
V_62 = F_56 ( V_119 , V_46 ,
V_10 ) ;
if ( V_62 )
goto V_82;
V_116 -> V_17 = V_119 ;
V_116 -> V_33 = V_40 ;
}
if ( V_120 ) {
if ( V_46 -> V_67 != V_68 &&
V_46 -> V_67 != V_71 ) {
V_62 = - V_98 ;
F_59 ( V_79 L_18
L_19 ) ;
goto V_82;
}
if ( V_120 != V_46 -> V_59 ) {
V_62 = F_56 ( V_120 ,
V_46 , V_10 ) ;
if ( V_62 )
goto V_82;
}
V_46 -> V_59 = V_120 ;
}
V_133:
V_62 = F_58 ( V_57 ) ;
V_82:
F_81 ( & V_46 -> V_28 ) ;
return V_62 ;
V_125:
V_62 = - V_98 ;
F_59 ( V_79 L_20
L_21 , V_57 -> V_80 , V_73 ) ;
goto V_82;
}
static int F_82 ( const struct V_56 * V_135 ,
const struct V_56 * V_136 )
{
struct V_45 * V_137 = V_135 -> V_48 ;
struct V_45 * V_138 = V_136 -> V_48 ;
char V_139 = V_137 -> V_87 & V_99 ;
char V_140 = V_138 -> V_87 & V_99 ;
if ( V_139 != V_140 )
goto V_141;
if ( ( V_139 & V_106 ) && V_137 -> V_17 != V_138 -> V_17 )
goto V_141;
if ( ( V_139 & V_107 ) && V_137 -> V_61 != V_138 -> V_61 )
goto V_141;
if ( ( V_139 & V_108 ) && V_137 -> V_59 != V_138 -> V_59 )
goto V_141;
if ( V_139 & V_109 ) {
struct V_23 * V_142 = F_37 ( V_135 -> V_75 ) ;
struct V_23 * V_143 = F_37 ( V_136 -> V_75 ) ;
if ( V_142 -> V_17 != V_143 -> V_17 )
goto V_141;
}
return 0 ;
V_141:
F_59 ( V_79 L_22
L_23
L_24 , V_136 -> V_80 , V_136 -> V_72 -> V_73 ) ;
return - V_144 ;
}
static int F_83 ( const struct V_56 * V_135 ,
struct V_56 * V_136 )
{
const struct V_45 * V_145 = V_135 -> V_48 ;
struct V_45 * V_146 = V_136 -> V_48 ;
int V_147 = ( V_145 -> V_87 & V_106 ) ;
int V_148 = ( V_145 -> V_87 & V_107 ) ;
int V_149 = ( V_145 -> V_87 & V_109 ) ;
if ( ! V_39 )
return 0 ;
F_72 ( ! ( V_145 -> V_87 & V_88 ) ) ;
if ( V_146 -> V_87 & V_88 )
return F_82 ( V_135 , V_136 ) ;
F_77 ( & V_146 -> V_28 ) ;
V_146 -> V_87 = V_145 -> V_87 ;
V_146 -> V_17 = V_145 -> V_17 ;
V_146 -> V_59 = V_145 -> V_59 ;
V_146 -> V_67 = V_145 -> V_67 ;
if ( V_148 ) {
T_2 V_17 = V_145 -> V_61 ;
if ( ! V_147 )
V_146 -> V_17 = V_17 ;
if ( ! V_149 ) {
struct V_23 * V_150 = F_37 ( V_136 -> V_75 ) ;
V_150 -> V_17 = V_17 ;
}
V_146 -> V_61 = V_17 ;
}
if ( V_149 ) {
const struct V_23 * V_151 = F_37 ( V_135 -> V_75 ) ;
struct V_23 * V_150 = F_37 ( V_136 -> V_75 ) ;
V_150 -> V_17 = V_151 -> V_17 ;
}
F_58 ( V_136 ) ;
F_81 ( & V_146 -> V_28 ) ;
return 0 ;
}
static int F_84 ( char * V_152 ,
struct V_92 * V_93 )
{
char * V_153 ;
char * V_95 = NULL , * V_154 = NULL ;
char * V_155 = NULL , * V_156 = NULL ;
int V_62 , V_101 = 0 ;
V_93 -> V_101 = 0 ;
while ( ( V_153 = F_85 ( & V_152 , L_25 ) ) != NULL ) {
int V_157 ;
T_3 args [ V_158 ] ;
if ( ! * V_153 )
continue;
V_157 = F_86 ( V_153 , V_159 , args ) ;
switch ( V_157 ) {
case V_160 :
if ( V_95 || V_154 ) {
V_62 = - V_98 ;
F_59 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_161;
}
V_95 = F_87 ( & args [ 0 ] ) ;
if ( ! V_95 ) {
V_62 = - V_27 ;
goto V_161;
}
break;
case V_162 :
if ( V_155 ) {
V_62 = - V_98 ;
F_59 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_161;
}
V_155 = F_87 ( & args [ 0 ] ) ;
if ( ! V_155 ) {
V_62 = - V_27 ;
goto V_161;
}
break;
case V_163 :
if ( V_156 ) {
V_62 = - V_98 ;
F_59 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_161;
}
V_156 = F_87 ( & args [ 0 ] ) ;
if ( ! V_156 ) {
V_62 = - V_27 ;
goto V_161;
}
break;
case V_164 :
if ( V_95 || V_154 ) {
V_62 = - V_98 ;
F_59 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_161;
}
V_154 = F_87 ( & args [ 0 ] ) ;
if ( ! V_154 ) {
V_62 = - V_27 ;
goto V_161;
}
break;
case V_165 :
break;
default:
V_62 = - V_98 ;
F_59 ( V_79 L_26 ) ;
goto V_161;
}
}
V_62 = - V_27 ;
V_93 -> V_102 = F_70 ( V_100 , sizeof( char * ) , V_15 ) ;
if ( ! V_93 -> V_102 )
goto V_161;
V_93 -> V_105 = F_70 ( V_100 , sizeof( int ) ,
V_15 ) ;
if ( ! V_93 -> V_105 ) {
F_52 ( V_93 -> V_102 ) ;
goto V_161;
}
if ( V_155 ) {
V_93 -> V_102 [ V_101 ] = V_155 ;
V_93 -> V_105 [ V_101 ++ ] = V_106 ;
}
if ( V_95 ) {
V_93 -> V_102 [ V_101 ] = V_95 ;
V_93 -> V_105 [ V_101 ++ ] = V_107 ;
}
if ( V_156 ) {
V_93 -> V_102 [ V_101 ] = V_156 ;
V_93 -> V_105 [ V_101 ++ ] = V_109 ;
}
if ( V_154 ) {
V_93 -> V_102 [ V_101 ] = V_154 ;
V_93 -> V_105 [ V_101 ++ ] = V_108 ;
}
V_93 -> V_101 = V_101 ;
return 0 ;
V_161:
F_52 ( V_95 ) ;
F_52 ( V_154 ) ;
F_52 ( V_155 ) ;
F_52 ( V_156 ) ;
return V_62 ;
}
static int F_88 ( struct V_56 * V_57 , void * V_166 )
{
int V_62 = 0 ;
char * V_152 = V_166 ;
struct V_92 V_93 ;
F_68 ( & V_93 ) ;
if ( ! V_166 )
goto V_82;
F_72 ( V_57 -> V_72 -> V_123 & V_124 ) ;
V_62 = F_84 ( V_152 , & V_93 ) ;
if ( V_62 )
goto V_161;
V_82:
V_62 = F_75 ( V_57 , & V_93 , 0 , NULL ) ;
V_161:
F_73 ( & V_93 ) ;
return V_62 ;
}
static void F_89 ( struct V_167 * V_168 ,
struct V_92 * V_93 )
{
int V_94 ;
char * V_169 ;
for ( V_94 = 0 ; V_94 < V_93 -> V_101 ; V_94 ++ ) {
char * V_170 ;
if ( V_93 -> V_102 [ V_94 ] )
V_170 = strchr ( V_93 -> V_102 [ V_94 ] , ',' ) ;
else
V_170 = NULL ;
switch ( V_93 -> V_105 [ V_94 ] ) {
case V_107 :
V_169 = V_171 ;
break;
case V_106 :
V_169 = V_172 ;
break;
case V_109 :
V_169 = V_173 ;
break;
case V_108 :
V_169 = V_174 ;
break;
case V_89 :
F_90 ( V_168 , ',' ) ;
F_91 ( V_168 , V_175 ) ;
continue;
default:
F_92 () ;
return;
} ;
F_90 ( V_168 , ',' ) ;
F_91 ( V_168 , V_169 ) ;
if ( V_170 )
F_90 ( V_168 , '\"' ) ;
F_93 ( V_168 , V_93 -> V_102 [ V_94 ] , L_27 ) ;
if ( V_170 )
F_90 ( V_168 , '\"' ) ;
}
}
static int F_94 ( struct V_167 * V_168 , struct V_56 * V_57 )
{
struct V_92 V_93 ;
int V_62 ;
V_62 = F_67 ( V_57 , & V_93 ) ;
if ( V_62 ) {
if ( V_62 == - V_98 )
V_62 = 0 ;
return V_62 ;
}
F_89 ( V_168 , & V_93 ) ;
F_73 ( & V_93 ) ;
return V_62 ;
}
static inline T_4 F_95 ( T_5 V_176 )
{
switch ( V_176 & V_177 ) {
case V_178 :
return V_179 ;
case V_180 :
return V_181 ;
case V_182 :
return V_32 ;
case V_183 :
return V_184 ;
case V_185 :
return V_186 ;
case V_187 :
return V_188 ;
case V_189 :
return V_190 ;
}
return V_32 ;
}
static inline int F_96 ( int V_191 )
{
return ( V_191 == V_192 || V_191 == V_193 ) ;
}
static inline int F_97 ( int V_191 )
{
return ( V_191 == V_192 || V_191 == V_194 ) ;
}
static inline T_4 F_98 ( int V_195 , int type , int V_191 )
{
switch ( V_195 ) {
case V_196 :
switch ( type ) {
case V_197 :
case V_198 :
return V_199 ;
case V_200 :
return V_201 ;
}
break;
case V_202 :
case V_203 :
switch ( type ) {
case V_197 :
if ( F_96 ( V_191 ) )
return V_204 ;
else
return V_205 ;
case V_200 :
if ( F_97 ( V_191 ) )
return V_206 ;
else
return V_205 ;
case V_207 :
return V_208 ;
default:
return V_205 ;
}
break;
case V_209 :
switch ( V_191 ) {
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
case V_238 :
return V_239 ;
case V_240 :
return V_241 ;
default:
return V_242 ;
}
case V_243 :
return V_244 ;
case V_245 :
return V_246 ;
case V_247 :
return V_248 ;
}
return V_249 ;
}
static int F_99 ( struct V_36 * V_36 ,
T_4 V_250 ,
T_4 V_87 ,
T_2 * V_17 )
{
int V_62 ;
struct V_56 * V_57 = V_36 -> V_251 ;
char * V_252 , * V_253 ;
V_252 = ( char * ) F_100 ( V_15 ) ;
if ( ! V_252 )
return - V_27 ;
V_253 = F_101 ( V_36 , V_252 , V_254 ) ;
if ( F_102 ( V_253 ) )
V_62 = F_103 ( V_253 ) ;
else {
if ( V_87 & V_126 ) {
while ( V_253 [ 1 ] >= '0' && V_253 [ 1 ] <= '9' ) {
V_253 [ 1 ] = '/' ;
V_253 ++ ;
}
}
V_62 = F_104 ( V_57 -> V_72 -> V_73 , V_253 , V_250 , V_17 ) ;
}
F_105 ( ( unsigned long ) V_252 ) ;
return V_62 ;
}
static int F_30 ( struct V_22 * V_22 , struct V_36 * V_37 )
{
struct V_45 * V_46 = NULL ;
struct V_23 * V_24 = V_22 -> V_35 ;
T_2 F_18 , V_17 = 0 ;
T_4 V_31 ;
struct V_36 * V_36 ;
#define F_106 255
char * V_95 = NULL ;
unsigned V_96 = 0 ;
int V_62 = 0 ;
if ( V_24 -> V_33 == V_40 )
return 0 ;
F_43 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_33 == V_40 )
goto V_255;
if ( V_24 -> V_31 == V_32 )
V_24 -> V_31 = F_95 ( V_22 -> V_256 ) ;
V_46 = V_22 -> V_47 -> V_48 ;
if ( ! ( V_46 -> V_87 & V_88 ) ) {
F_43 ( & V_46 -> V_49 ) ;
if ( F_62 ( & V_24 -> V_29 ) )
F_107 ( & V_24 -> V_29 , & V_46 -> V_58 ) ;
F_45 ( & V_46 -> V_49 ) ;
goto V_255;
}
V_31 = V_24 -> V_31 ;
F_18 = V_24 -> F_18 ;
V_17 = V_24 -> V_17 ;
V_24 -> V_33 = V_257 ;
F_45 ( & V_24 -> V_28 ) ;
switch ( V_46 -> V_67 ) {
case V_71 :
break;
case V_68 :
if ( ! ( V_22 -> V_77 & V_78 ) ) {
V_17 = V_46 -> V_59 ;
break;
}
if ( V_37 ) {
V_36 = F_108 ( V_37 ) ;
} else {
V_36 = F_109 ( V_22 ) ;
}
if ( ! V_36 ) {
goto V_82;
}
V_96 = F_106 ;
V_95 = F_110 ( V_96 + 1 , V_26 ) ;
if ( ! V_95 ) {
V_62 = - V_27 ;
F_111 ( V_36 ) ;
goto V_82;
}
V_95 [ V_96 ] = '\0' ;
V_62 = F_60 ( V_36 , V_22 , V_83 , V_95 , V_96 ) ;
if ( V_62 == - V_258 ) {
F_52 ( V_95 ) ;
V_62 = F_60 ( V_36 , V_22 , V_83 , NULL , 0 ) ;
if ( V_62 < 0 ) {
F_111 ( V_36 ) ;
goto V_82;
}
V_96 = V_62 ;
V_95 = F_110 ( V_96 + 1 , V_26 ) ;
if ( ! V_95 ) {
V_62 = - V_27 ;
F_111 ( V_36 ) ;
goto V_82;
}
V_95 [ V_96 ] = '\0' ;
V_62 = F_60 ( V_36 , V_22 , V_83 , V_95 , V_96 ) ;
}
F_111 ( V_36 ) ;
if ( V_62 < 0 ) {
if ( V_62 != - V_84 ) {
F_59 ( V_79 L_28
L_29 , V_128 ,
- V_62 , V_22 -> V_47 -> V_80 , V_22 -> V_259 ) ;
F_52 ( V_95 ) ;
goto V_82;
}
V_17 = V_46 -> V_59 ;
V_62 = 0 ;
} else {
V_62 = F_112 ( V_95 , V_62 , & V_17 ,
V_46 -> V_59 ,
V_26 ) ;
if ( V_62 ) {
char * V_260 = V_22 -> V_47 -> V_80 ;
unsigned long V_261 = V_22 -> V_259 ;
if ( V_62 == - V_98 ) {
if ( F_113 () )
F_59 ( V_262 L_30
L_31
L_32 , V_261 , V_260 , V_95 ) ;
} else {
F_59 ( V_79 L_33
L_34 ,
V_128 , V_95 , - V_62 , V_260 , V_261 ) ;
}
F_52 ( V_95 ) ;
V_62 = 0 ;
break;
}
}
F_52 ( V_95 ) ;
break;
case V_70 :
V_17 = F_18 ;
break;
case V_69 :
V_17 = V_46 -> V_17 ;
V_62 = F_80 ( F_18 , V_17 , V_31 , NULL , & V_17 ) ;
if ( V_62 )
goto V_82;
break;
case V_132 :
V_17 = V_46 -> V_61 ;
break;
default:
V_17 = V_46 -> V_17 ;
if ( ( V_46 -> V_87 & V_127 ) && ! F_114 ( V_22 -> V_256 ) ) {
if ( V_37 )
V_36 = F_108 ( V_37 ) ;
else
V_36 = F_109 ( V_22 ) ;
if ( ! V_36 )
goto V_82;
V_62 = F_99 ( V_36 , V_31 ,
V_46 -> V_87 , & V_17 ) ;
F_111 ( V_36 ) ;
if ( V_62 )
goto V_82;
}
break;
}
V_82:
F_43 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_33 == V_257 ) {
if ( ! V_17 || V_62 ) {
V_24 -> V_33 = V_34 ;
goto V_255;
}
V_24 -> V_33 = V_40 ;
V_24 -> V_17 = V_17 ;
}
V_255:
F_45 ( & V_24 -> V_28 ) ;
return V_62 ;
}
static inline T_2 F_115 ( int V_263 )
{
T_2 V_264 = 0 ;
switch ( V_263 ) {
case V_265 :
V_264 = V_266 ;
break;
case V_267 :
V_264 = V_268 ;
break;
case V_269 :
V_264 = V_270 ;
break;
default:
V_264 = V_271 ;
break;
}
return V_264 ;
}
static int F_116 ( const struct V_10 * V_272 ,
const struct V_10 * V_273 ,
T_2 V_274 )
{
T_2 V_275 = F_17 ( V_272 ) , V_276 = F_17 ( V_273 ) ;
return F_55 ( V_275 , V_276 , V_277 , V_274 , NULL ) ;
}
static int F_117 ( const struct V_20 * V_278 ,
const struct V_20 * V_279 ,
T_2 V_274 )
{
const struct V_13 * V_280 , * V_281 ;
T_2 V_282 , V_283 ;
F_19 () ;
V_280 = F_20 ( V_278 ) -> V_19 ; V_282 = V_280 -> V_17 ;
V_281 = F_20 ( V_279 ) -> V_19 ; V_283 = V_281 -> V_17 ;
F_21 () ;
return F_55 ( V_282 , V_283 , V_277 , V_274 , NULL ) ;
}
static int F_118 ( const struct V_20 * V_284 ,
T_2 V_274 )
{
T_2 V_17 , V_276 ;
V_17 = F_22 () ;
V_276 = F_18 ( V_284 ) ;
return F_55 ( V_17 , V_276 , V_277 , V_274 , NULL ) ;
}
static int F_119 ( const struct V_10 * V_10 ,
int V_285 , int V_286 , bool V_287 )
{
struct V_288 V_289 ;
struct V_290 V_291 ;
T_4 V_31 ;
T_2 V_17 = F_17 ( V_10 ) ;
T_2 V_292 = F_120 ( V_285 ) ;
int V_62 ;
V_289 . type = V_293 ;
V_289 . V_294 . V_285 = V_285 ;
switch ( F_121 ( V_285 ) ) {
case 0 :
V_31 = V_287 ? V_295 : V_296 ;
break;
case 1 :
V_31 = V_287 ? V_297 : V_298 ;
break;
default:
F_59 ( V_86
L_35 , V_285 ) ;
F_92 () ;
return - V_98 ;
}
V_62 = F_122 ( V_17 , V_17 , V_31 , V_292 , 0 , & V_291 ) ;
if ( V_286 == V_299 ) {
int V_300 = F_123 ( V_17 , V_17 , V_31 , V_292 , & V_291 , V_62 , & V_289 , 0 ) ;
if ( V_300 )
return V_300 ;
}
return V_62 ;
}
static int F_124 ( struct V_20 * V_284 ,
T_2 V_274 )
{
T_2 V_17 = F_18 ( V_284 ) ;
return F_55 ( V_17 , V_18 ,
V_301 , V_274 , NULL ) ;
}
static int F_125 ( const struct V_10 * V_10 ,
struct V_22 * V_22 ,
T_2 V_274 ,
struct V_288 * V_302 )
{
struct V_23 * V_24 ;
T_2 V_17 ;
F_126 ( V_10 ) ;
if ( F_127 ( F_65 ( V_22 ) ) )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_35 ;
return F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_274 , V_302 ) ;
}
static inline int F_128 ( const struct V_10 * V_10 ,
struct V_36 * V_36 ,
T_2 V_292 )
{
struct V_22 * V_22 = F_36 ( V_36 ) ;
struct V_288 V_289 ;
V_289 . type = V_303 ;
V_289 . V_294 . V_36 = V_36 ;
F_28 ( V_22 , V_36 , true ) ;
return F_125 ( V_10 , V_22 , V_292 , & V_289 ) ;
}
static inline int F_129 ( const struct V_10 * V_10 ,
const struct V_253 * V_253 ,
T_2 V_292 )
{
struct V_22 * V_22 = F_36 ( V_253 -> V_36 ) ;
struct V_288 V_289 ;
V_289 . type = V_304 ;
V_289 . V_294 . V_253 = * V_253 ;
F_28 ( V_22 , V_253 -> V_36 , true ) ;
return F_125 ( V_10 , V_22 , V_292 , & V_289 ) ;
}
static inline int F_130 ( const struct V_10 * V_10 ,
struct V_50 * V_50 ,
T_2 V_292 )
{
struct V_288 V_289 ;
V_289 . type = V_305 ;
V_289 . V_294 . V_50 = V_50 ;
return F_125 ( V_10 , F_131 ( V_50 ) , V_292 , & V_289 ) ;
}
static int F_132 ( const struct V_10 * V_10 ,
struct V_50 * V_50 ,
T_2 V_292 )
{
struct V_51 * V_52 = V_50 -> V_55 ;
struct V_22 * V_22 = F_131 ( V_50 ) ;
struct V_288 V_289 ;
T_2 V_17 = F_17 ( V_10 ) ;
int V_62 ;
V_289 . type = V_305 ;
V_289 . V_294 . V_50 = V_50 ;
if ( V_17 != V_52 -> V_17 ) {
V_62 = F_55 ( V_17 , V_52 -> V_17 ,
V_306 ,
V_307 ,
& V_289 ) ;
if ( V_62 )
goto V_82;
}
V_62 = 0 ;
if ( V_292 )
V_62 = F_125 ( V_10 , V_22 , V_292 , & V_289 ) ;
V_82:
return V_62 ;
}
static int
F_133 ( const struct V_13 * V_14 ,
struct V_22 * V_308 ,
const struct V_309 * V_73 , T_4 V_250 ,
T_2 * V_310 )
{
const struct V_45 * V_46 = V_308 -> V_47 -> V_48 ;
if ( ( V_46 -> V_87 & V_88 ) &&
( V_46 -> V_67 == V_132 ) ) {
* V_310 = V_46 -> V_61 ;
} else if ( ( V_46 -> V_87 & V_89 ) &&
V_14 -> V_311 ) {
* V_310 = V_14 -> V_311 ;
} else {
const struct V_23 * V_312 = F_34 ( V_308 ) ;
return F_80 ( V_14 -> V_17 , V_312 -> V_17 , V_250 ,
V_73 , V_310 ) ;
}
return 0 ;
}
static int F_134 ( struct V_22 * V_308 ,
struct V_36 * V_36 ,
T_4 V_250 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_312 ;
struct V_45 * V_46 ;
T_2 V_17 , V_313 ;
struct V_288 V_289 ;
int V_62 ;
V_312 = F_34 ( V_308 ) ;
V_46 = V_308 -> V_47 -> V_48 ;
V_17 = V_14 -> V_17 ;
V_289 . type = V_303 ;
V_289 . V_294 . V_36 = V_36 ;
V_62 = F_55 ( V_17 , V_312 -> V_17 , V_186 ,
V_314 | V_315 ,
& V_289 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_133 ( F_23 () , V_308 ,
& V_36 -> V_316 , V_250 , & V_313 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_55 ( V_17 , V_313 , V_250 , V_317 , & V_289 ) ;
if ( V_62 )
return V_62 ;
return F_55 ( V_313 , V_46 -> V_17 ,
V_63 ,
V_66 , & V_289 ) ;
}
static int F_135 ( T_2 V_318 ,
struct V_20 * V_319 )
{
T_2 V_17 = F_18 ( V_319 ) ;
return F_55 ( V_17 , V_318 , V_320 , V_321 , NULL ) ;
}
static int F_136 ( struct V_22 * V_308 ,
struct V_36 * V_36 ,
int V_322 )
{
struct V_23 * V_312 , * V_24 ;
struct V_288 V_289 ;
T_2 V_17 = F_22 () ;
T_2 V_292 ;
int V_62 ;
V_312 = F_34 ( V_308 ) ;
V_24 = F_37 ( V_36 ) ;
V_289 . type = V_303 ;
V_289 . V_294 . V_36 = V_36 ;
V_292 = V_315 ;
V_292 |= ( V_322 ? V_323 : V_314 ) ;
V_62 = F_55 ( V_17 , V_312 -> V_17 , V_186 , V_292 , & V_289 ) ;
if ( V_62 )
return V_62 ;
switch ( V_322 ) {
case V_324 :
V_292 = V_325 ;
break;
case V_326 :
V_292 = V_327 ;
break;
case V_328 :
V_292 = V_329 ;
break;
default:
F_59 ( V_79 L_36 ,
V_128 , V_322 ) ;
return 0 ;
}
V_62 = F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_292 , & V_289 ) ;
return V_62 ;
}
static inline int F_137 ( struct V_22 * V_330 ,
struct V_36 * V_331 ,
struct V_22 * V_332 ,
struct V_36 * V_333 )
{
struct V_23 * V_334 , * V_335 , * V_336 , * V_337 ;
struct V_288 V_289 ;
T_2 V_17 = F_22 () ;
T_2 V_292 ;
int V_338 , V_339 ;
int V_62 ;
V_334 = F_34 ( V_330 ) ;
V_336 = F_37 ( V_331 ) ;
V_338 = F_138 ( V_331 ) ;
V_335 = F_34 ( V_332 ) ;
V_289 . type = V_303 ;
V_289 . V_294 . V_36 = V_331 ;
V_62 = F_55 ( V_17 , V_334 -> V_17 , V_186 ,
V_323 | V_315 , & V_289 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_55 ( V_17 , V_336 -> V_17 ,
V_336 -> V_31 , V_340 , & V_289 ) ;
if ( V_62 )
return V_62 ;
if ( V_338 && V_332 != V_330 ) {
V_62 = F_55 ( V_17 , V_336 -> V_17 ,
V_336 -> V_31 , V_341 , & V_289 ) ;
if ( V_62 )
return V_62 ;
}
V_289 . V_294 . V_36 = V_333 ;
V_292 = V_314 | V_315 ;
if ( F_139 ( V_333 ) )
V_292 |= V_323 ;
V_62 = F_55 ( V_17 , V_335 -> V_17 , V_186 , V_292 , & V_289 ) ;
if ( V_62 )
return V_62 ;
if ( F_139 ( V_333 ) ) {
V_337 = F_37 ( V_333 ) ;
V_339 = F_138 ( V_333 ) ;
V_62 = F_55 ( V_17 , V_337 -> V_17 ,
V_337 -> V_31 ,
( V_339 ? V_329 : V_327 ) , & V_289 ) ;
if ( V_62 )
return V_62 ;
}
return 0 ;
}
static int F_140 ( const struct V_10 * V_10 ,
struct V_56 * V_57 ,
T_2 V_274 ,
struct V_288 * V_289 )
{
struct V_45 * V_46 ;
T_2 V_17 = F_17 ( V_10 ) ;
V_46 = V_57 -> V_48 ;
return F_55 ( V_17 , V_46 -> V_17 , V_63 , V_274 , V_289 ) ;
}
static inline T_2 F_141 ( int V_176 , int V_342 )
{
T_2 V_292 = 0 ;
if ( ! F_142 ( V_176 ) ) {
if ( V_342 & V_343 )
V_292 |= V_344 ;
if ( V_342 & V_345 )
V_292 |= V_346 ;
if ( V_342 & V_347 )
V_292 |= V_348 ;
else if ( V_342 & V_349 )
V_292 |= V_350 ;
} else {
if ( V_342 & V_343 )
V_292 |= V_315 ;
if ( V_342 & V_349 )
V_292 |= V_351 ;
if ( V_342 & V_345 )
V_292 |= V_352 ;
}
return V_292 ;
}
static inline T_2 F_143 ( struct V_50 * V_50 )
{
T_2 V_292 = 0 ;
if ( V_50 -> V_353 & V_354 )
V_292 |= V_346 ;
if ( V_50 -> V_353 & V_355 ) {
if ( V_50 -> V_356 & V_357 )
V_292 |= V_348 ;
else
V_292 |= V_350 ;
}
if ( ! V_292 ) {
V_292 = V_358 ;
}
return V_292 ;
}
static inline T_2 F_144 ( struct V_50 * V_50 )
{
T_2 V_292 = F_143 ( V_50 ) ;
if ( V_359 )
V_292 |= V_360 ;
return V_292 ;
}
static int F_145 ( struct V_20 * V_361 )
{
T_2 V_362 = F_22 () ;
T_2 V_363 = F_18 ( V_361 ) ;
return F_55 ( V_362 , V_363 , V_364 ,
V_365 , NULL ) ;
}
static int F_146 ( struct V_20 * V_366 ,
struct V_20 * V_367 )
{
T_2 V_362 = F_22 () ;
T_2 V_368 = F_18 ( V_366 ) ;
T_2 V_369 = F_18 ( V_367 ) ;
int V_62 ;
if ( V_362 != V_368 ) {
V_62 = F_55 ( V_362 , V_368 , V_364 ,
V_370 , NULL ) ;
if ( V_62 )
return V_62 ;
}
return F_55 ( V_368 , V_369 , V_364 , V_371 ,
NULL ) ;
}
static int F_147 ( struct V_20 * V_366 ,
struct V_20 * V_367 )
{
T_2 V_368 = F_18 ( V_366 ) ;
T_2 V_369 = F_18 ( V_367 ) ;
return F_55 ( V_368 , V_369 , V_364 , V_372 ,
NULL ) ;
}
static int F_148 ( struct V_20 * V_366 ,
struct V_20 * V_367 ,
struct V_50 * V_50 )
{
T_2 V_17 = F_18 ( V_367 ) ;
struct V_51 * V_52 = V_50 -> V_55 ;
struct V_36 * V_36 = V_50 -> V_373 . V_36 ;
struct V_23 * V_24 ;
struct V_288 V_289 ;
int V_62 ;
V_289 . type = V_304 ;
V_289 . V_294 . V_253 = V_50 -> V_373 ;
if ( V_17 != V_52 -> V_17 ) {
V_62 = F_55 ( V_17 , V_52 -> V_17 ,
V_306 ,
V_307 ,
& V_289 ) ;
if ( V_62 )
return V_62 ;
}
if ( F_127 ( F_65 ( F_36 ( V_36 ) ) ) )
return 0 ;
V_24 = F_37 ( V_36 ) ;
return F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , F_143 ( V_50 ) ,
& V_289 ) ;
}
static int F_149 ( struct V_20 * V_374 ,
unsigned int V_176 )
{
if ( V_176 & V_375 ) {
T_2 V_17 = F_22 () ;
T_2 V_376 = F_18 ( V_374 ) ;
return F_55 ( V_17 , V_376 , V_32 , V_346 , NULL ) ;
}
return F_118 ( V_374 , V_377 ) ;
}
static int F_150 ( struct V_20 * V_378 )
{
return F_117 ( V_378 , V_11 , V_377 ) ;
}
static int F_151 ( struct V_20 * V_273 , T_6 * V_379 ,
T_6 * V_380 , T_6 * V_381 )
{
return F_118 ( V_273 , V_382 ) ;
}
static int F_152 ( struct V_10 * V_138 , const struct V_10 * V_137 ,
const T_6 * V_379 ,
const T_6 * V_380 ,
const T_6 * V_381 )
{
return F_116 ( V_137 , V_138 , V_383 ) ;
}
static int F_153 ( const struct V_10 * V_10 , struct V_384 * V_385 ,
int V_285 , int V_286 )
{
return F_119 ( V_10 , V_285 , V_286 , V_385 == & V_130 ) ;
}
static int F_154 ( int V_386 , int type , int V_387 , struct V_56 * V_57 )
{
const struct V_10 * V_10 = F_76 () ;
int V_62 = 0 ;
if ( ! V_57 )
return 0 ;
switch ( V_386 ) {
case V_388 :
case V_389 :
case V_390 :
case V_391 :
case V_392 :
V_62 = F_140 ( V_10 , V_57 , V_393 , NULL ) ;
break;
case V_394 :
case V_395 :
case V_396 :
V_62 = F_140 ( V_10 , V_57 , V_397 , NULL ) ;
break;
default:
V_62 = 0 ;
break;
}
return V_62 ;
}
static int F_155 ( struct V_36 * V_36 )
{
const struct V_10 * V_10 = F_76 () ;
return F_128 ( V_10 , V_36 , V_398 ) ;
}
static int F_156 ( int type )
{
int V_62 ;
switch ( type ) {
case V_399 :
case V_400 :
V_62 = F_124 ( V_11 , V_401 ) ;
break;
case V_402 :
case V_403 :
case V_404 :
V_62 = F_124 ( V_11 , V_405 ) ;
break;
case V_406 :
case V_407 :
case V_408 :
case V_409 :
case V_410 :
default:
V_62 = F_124 ( V_11 , V_411 ) ;
break;
}
return V_62 ;
}
static int F_157 ( struct V_412 * V_413 , long V_414 )
{
int V_62 , V_415 = 0 ;
V_62 = F_119 ( F_76 () , V_416 ,
V_417 , true ) ;
if ( V_62 == 0 )
V_415 = 1 ;
return V_415 ;
}
static T_2 F_158 ( struct V_20 * V_21 )
{
T_2 V_17 = 0 ;
struct V_20 * V_418 ;
F_19 () ;
V_418 = F_159 ( V_21 ) ;
if ( V_418 )
V_17 = F_18 ( V_418 ) ;
F_21 () ;
return V_17 ;
}
static int F_160 ( const struct V_419 * V_420 ,
const struct V_13 * V_421 ,
const struct V_13 * V_422 )
{
int V_423 = ( V_420 -> V_424 & V_425 ) ;
int V_426 = ! F_161 ( V_420 -> V_50 -> V_373 . V_427 ) ;
int V_62 ;
if ( ! V_423 && ! V_426 )
return 0 ;
if ( V_422 -> V_17 == V_421 -> V_17 )
return 0 ;
V_62 = F_162 ( V_421 -> V_17 , V_422 -> V_17 ) ;
if ( V_62 ) {
if ( V_423 )
return - V_428 ;
else
return - V_131 ;
}
return 0 ;
}
static int F_163 ( struct V_419 * V_420 )
{
const struct V_13 * V_421 ;
struct V_13 * V_422 ;
struct V_23 * V_24 ;
struct V_288 V_289 ;
struct V_22 * V_22 = F_131 ( V_420 -> V_50 ) ;
int V_62 ;
if ( V_420 -> V_429 )
return 0 ;
V_421 = F_23 () ;
V_422 = V_420 -> V_10 -> V_19 ;
V_24 = F_34 ( V_22 ) ;
V_422 -> V_17 = V_421 -> V_17 ;
V_422 -> V_16 = V_421 -> V_17 ;
V_422 -> V_311 = 0 ;
V_422 -> V_430 = 0 ;
V_422 -> V_431 = 0 ;
if ( V_421 -> V_432 ) {
V_422 -> V_17 = V_421 -> V_432 ;
V_422 -> V_432 = 0 ;
V_62 = F_160 ( V_420 , V_421 , V_422 ) ;
if ( V_62 )
return V_62 ;
} else {
V_62 = F_80 ( V_421 -> V_17 , V_24 -> V_17 ,
V_277 , NULL ,
& V_422 -> V_17 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_160 ( V_420 , V_421 , V_422 ) ;
if ( V_62 )
V_422 -> V_17 = V_421 -> V_17 ;
}
V_289 . type = V_305 ;
V_289 . V_294 . V_50 = V_420 -> V_50 ;
if ( V_422 -> V_17 == V_421 -> V_17 ) {
V_62 = F_55 ( V_421 -> V_17 , V_24 -> V_17 ,
V_32 , V_433 , & V_289 ) ;
if ( V_62 )
return V_62 ;
} else {
V_62 = F_55 ( V_421 -> V_17 , V_422 -> V_17 ,
V_277 , V_434 , & V_289 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_55 ( V_422 -> V_17 , V_24 -> V_17 ,
V_32 , V_435 , & V_289 ) ;
if ( V_62 )
return V_62 ;
if ( V_420 -> V_424 & V_436 ) {
V_62 = F_55 ( V_421 -> V_17 , V_422 -> V_17 ,
V_277 , V_437 ,
NULL ) ;
if ( V_62 )
return - V_428 ;
}
if ( V_420 -> V_424 &
( V_438 | V_439 ) ) {
T_2 V_440 = F_158 ( V_11 ) ;
if ( V_440 != 0 ) {
V_62 = F_55 ( V_440 , V_422 -> V_17 ,
V_277 ,
V_377 , NULL ) ;
if ( V_62 )
return - V_428 ;
}
}
V_420 -> V_441 |= V_442 ;
}
return 0 ;
}
static int F_164 ( struct V_419 * V_420 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_17 , V_16 ;
int V_443 = 0 ;
V_17 = V_14 -> V_17 ;
V_16 = V_14 -> V_16 ;
if ( V_16 != V_17 ) {
V_443 = F_55 ( V_16 , V_17 ,
V_277 ,
V_444 , NULL ) ;
}
return ! ! V_443 ;
}
static int F_165 ( const void * V_153 , struct V_50 * V_50 , unsigned V_445 )
{
return F_132 ( V_153 , V_50 , F_143 ( V_50 ) ) ? V_445 + 1 : 0 ;
}
static inline void F_166 ( const struct V_10 * V_10 ,
struct V_446 * V_447 )
{
struct V_50 * V_50 , * V_448 = NULL ;
struct V_449 * V_450 ;
int V_451 = 0 ;
unsigned V_452 ;
V_450 = F_167 () ;
if ( V_450 ) {
F_43 ( & V_450 -> V_453 ) ;
if ( ! F_62 ( & V_450 -> V_454 ) ) {
struct V_455 * V_456 ;
V_456 = F_168 ( & V_450 -> V_454 ,
struct V_455 , V_29 ) ;
V_50 = V_456 -> V_50 ;
if ( F_130 ( V_10 , V_50 , V_346 | V_350 ) )
V_451 = 1 ;
}
F_45 ( & V_450 -> V_453 ) ;
F_169 ( V_450 ) ;
}
if ( V_451 )
F_170 () ;
V_452 = F_171 ( V_447 , 0 , F_165 , V_10 ) ;
if ( ! V_452 )
return;
V_448 = F_172 ( & V_457 , V_458 , V_10 ) ;
if ( F_102 ( V_448 ) )
V_448 = NULL ;
do {
F_173 ( V_452 - 1 , V_448 , 0 ) ;
} while ( ( V_452 = F_171 ( V_447 , V_452 , F_165 , V_10 ) ) != 0 );
if ( V_448 )
F_174 ( V_448 ) ;
}
static void F_175 ( struct V_419 * V_420 )
{
struct V_13 * V_422 ;
struct V_459 * V_460 , * V_461 ;
int V_62 , V_94 ;
V_422 = V_420 -> V_10 -> V_19 ;
if ( V_422 -> V_17 == V_422 -> V_16 )
return;
F_166 ( V_420 -> V_10 , V_11 -> V_447 ) ;
V_11 -> V_462 = 0 ;
V_62 = F_55 ( V_422 -> V_16 , V_422 -> V_17 , V_277 ,
V_463 , NULL ) ;
if ( V_62 ) {
F_176 ( V_11 ) ;
for ( V_94 = 0 ; V_94 < V_464 ; V_94 ++ ) {
V_460 = V_11 -> signal -> V_460 + V_94 ;
V_461 = V_465 . signal -> V_460 + V_94 ;
V_460 -> V_466 = F_177 ( V_460 -> V_467 , V_461 -> V_466 ) ;
}
F_178 ( V_11 ) ;
if ( F_179 ( V_468 ) )
F_180 ( V_11 , V_459 ( V_469 ) ) ;
}
}
static void F_181 ( struct V_419 * V_420 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_470 V_471 ;
T_2 V_16 , V_17 ;
int V_62 , V_94 ;
V_16 = V_14 -> V_16 ;
V_17 = V_14 -> V_17 ;
if ( V_17 == V_16 )
return;
V_62 = F_55 ( V_16 , V_17 , V_277 , V_472 , NULL ) ;
if ( V_62 ) {
if ( F_179 ( V_468 ) ) {
memset ( & V_471 , 0 , sizeof V_471 ) ;
for ( V_94 = 0 ; V_94 < 3 ; V_94 ++ )
F_182 ( V_94 , & V_471 , NULL ) ;
}
F_183 ( & V_11 -> V_473 -> V_474 ) ;
if ( ! F_184 ( V_11 ) ) {
F_185 ( & V_11 -> V_475 ) ;
F_185 ( & V_11 -> signal -> V_476 ) ;
F_186 ( V_11 , 1 ) ;
F_187 ( & V_11 -> V_477 ) ;
F_188 () ;
}
F_189 ( & V_11 -> V_473 -> V_474 ) ;
}
F_190 ( & V_478 ) ;
F_191 ( V_11 , V_11 -> V_479 ) ;
F_192 ( & V_478 ) ;
}
static int F_193 ( struct V_56 * V_57 )
{
return F_49 ( V_57 ) ;
}
static void F_194 ( struct V_56 * V_57 )
{
F_51 ( V_57 ) ;
}
static inline int F_195 ( char * V_169 , int V_480 , char * V_481 , int V_482 )
{
if ( V_480 > V_482 )
return 0 ;
return ! memcmp ( V_169 , V_481 , V_480 ) ;
}
static inline int F_196 ( char * V_481 , int V_96 )
{
return ( F_195 ( V_171 , sizeof( V_171 ) - 1 , V_481 , V_96 ) ||
F_195 ( V_172 , sizeof( V_172 ) - 1 , V_481 , V_96 ) ||
F_195 ( V_174 , sizeof( V_174 ) - 1 , V_481 , V_96 ) ||
F_195 ( V_173 , sizeof( V_173 ) - 1 , V_481 , V_96 ) ||
F_195 ( V_175 , sizeof( V_175 ) - 1 , V_481 , V_96 ) ) ;
}
static inline void F_197 ( char * * V_367 , char * V_366 , int * V_483 , int V_96 )
{
if ( ! * V_483 ) {
* * V_367 = ',' ;
* V_367 += 1 ;
} else
* V_483 = 0 ;
memcpy ( * V_367 , V_366 , V_96 ) ;
* V_367 += V_96 ;
}
static inline void F_198 ( char * * V_367 , char * V_366 , int * V_483 ,
int V_96 )
{
int V_484 = 0 ;
if ( ! * V_483 ) {
* * V_367 = '|' ;
* V_367 += 1 ;
} else
* V_483 = 0 ;
while ( V_484 < V_96 ) {
if ( * V_366 != '"' ) {
* * V_367 = * V_366 ;
* V_367 += 1 ;
}
V_366 += 1 ;
V_484 += 1 ;
}
}
static int F_199 ( char * V_485 , char * V_486 )
{
int V_487 , V_52 , V_62 = 0 ;
char * V_488 , * V_489 , * V_490 ;
char * V_491 , * V_492 , * V_493 ;
int V_494 = 0 ;
V_489 = V_485 ;
V_491 = V_486 ;
V_493 = ( char * ) F_200 ( V_15 ) ;
if ( ! V_493 ) {
V_62 = - V_27 ;
goto V_82;
}
V_492 = V_493 ;
V_487 = V_52 = 1 ;
V_488 = V_490 = V_485 ;
do {
if ( * V_490 == '"' )
V_494 = ! V_494 ;
if ( ( * V_490 == ',' && V_494 == 0 ) ||
* V_490 == '\0' ) {
int V_96 = V_490 - V_489 ;
if ( F_196 ( V_489 , V_96 ) )
F_198 ( & V_491 , V_489 , & V_52 , V_96 ) ;
else
F_197 ( & V_493 , V_489 , & V_487 , V_96 ) ;
V_489 = V_490 + 1 ;
}
} while ( * V_490 ++ );
strcpy ( V_488 , V_492 ) ;
F_105 ( ( unsigned long ) V_492 ) ;
V_82:
return V_62 ;
}
static int F_201 ( struct V_56 * V_57 , void * V_166 )
{
int V_62 , V_94 , * V_87 ;
struct V_92 V_93 ;
char * V_495 , * * V_121 ;
struct V_45 * V_46 = V_57 -> V_48 ;
if ( ! ( V_46 -> V_87 & V_88 ) )
return 0 ;
if ( ! V_166 )
return 0 ;
if ( V_57 -> V_72 -> V_123 & V_124 )
return 0 ;
F_68 ( & V_93 ) ;
V_495 = F_202 () ;
if ( ! V_495 )
return - V_27 ;
V_62 = F_199 ( V_166 , V_495 ) ;
if ( V_62 )
goto V_496;
V_62 = F_84 ( V_495 , & V_93 ) ;
if ( V_62 )
goto V_496;
V_121 = V_93 . V_102 ;
V_87 = V_93 . V_105 ;
for ( V_94 = 0 ; V_94 < V_93 . V_101 ; V_94 ++ ) {
T_2 V_17 ;
if ( V_87 [ V_94 ] == V_89 )
continue;
V_62 = F_78 ( V_121 [ V_94 ] , & V_17 , V_15 ) ;
if ( V_62 ) {
F_59 ( V_79 L_14
L_15 ,
V_121 [ V_94 ] , V_57 -> V_80 , V_57 -> V_72 -> V_73 , V_62 ) ;
goto V_497;
}
V_62 = - V_98 ;
switch ( V_87 [ V_94 ] ) {
case V_106 :
if ( F_74 ( V_46 , V_106 , V_46 -> V_17 , V_17 ) )
goto V_498;
break;
case V_107 :
if ( F_74 ( V_46 , V_107 , V_46 -> V_61 , V_17 ) )
goto V_498;
break;
case V_109 : {
struct V_23 * V_116 ;
V_116 = F_37 ( V_57 -> V_75 ) ;
if ( F_74 ( V_46 , V_109 , V_116 -> V_17 , V_17 ) )
goto V_498;
break;
}
case V_108 :
if ( F_74 ( V_46 , V_108 , V_46 -> V_59 , V_17 ) )
goto V_498;
break;
default:
goto V_497;
}
}
V_62 = 0 ;
V_497:
F_73 ( & V_93 ) ;
V_496:
F_203 ( V_495 ) ;
return V_62 ;
V_498:
F_59 ( V_79 L_37
L_38 , V_57 -> V_80 ,
V_57 -> V_72 -> V_73 ) ;
goto V_497;
}
static int F_204 ( struct V_56 * V_57 , int V_87 , void * V_166 )
{
const struct V_10 * V_10 = F_76 () ;
struct V_288 V_289 ;
int V_62 ;
V_62 = F_88 ( V_57 , V_166 ) ;
if ( V_62 )
return V_62 ;
if ( V_87 & V_499 )
return 0 ;
V_289 . type = V_303 ;
V_289 . V_294 . V_36 = V_57 -> V_75 ;
return F_140 ( V_10 , V_57 , V_500 , & V_289 ) ;
}
static int F_205 ( struct V_36 * V_36 )
{
const struct V_10 * V_10 = F_76 () ;
struct V_288 V_289 ;
V_289 . type = V_303 ;
V_289 . V_294 . V_36 = V_36 -> V_251 -> V_75 ;
return F_140 ( V_10 , V_36 -> V_251 , V_501 , & V_289 ) ;
}
static int F_206 ( const char * V_502 ,
const struct V_253 * V_253 ,
const char * type ,
unsigned long V_87 ,
void * V_166 )
{
const struct V_10 * V_10 = F_76 () ;
if ( V_87 & V_503 )
return F_140 ( V_10 , V_253 -> V_36 -> V_251 ,
V_504 , NULL ) ;
else
return F_129 ( V_10 , V_253 , V_505 ) ;
}
static int F_207 ( struct V_506 * V_427 , int V_87 )
{
const struct V_10 * V_10 = F_76 () ;
return F_140 ( V_10 , V_427 -> V_507 ,
V_508 , NULL ) ;
}
static int F_208 ( struct V_22 * V_22 )
{
return F_24 ( V_22 ) ;
}
static void F_209 ( struct V_22 * V_22 )
{
F_41 ( V_22 ) ;
}
static int F_210 ( struct V_36 * V_36 , int V_176 ,
const struct V_309 * V_73 , void * * V_319 ,
T_2 * V_509 )
{
T_2 V_313 ;
int V_62 ;
V_62 = F_133 ( F_23 () ,
F_211 ( V_36 -> V_510 ) , V_73 ,
F_95 ( V_176 ) ,
& V_313 ) ;
if ( V_62 )
return V_62 ;
return F_71 ( V_313 , ( char * * ) V_319 , V_509 ) ;
}
static int F_212 ( struct V_36 * V_36 , int V_176 ,
struct V_309 * V_73 ,
const struct V_10 * V_137 ,
struct V_10 * V_138 )
{
T_2 V_313 ;
int V_62 ;
struct V_13 * V_14 ;
V_62 = F_133 ( V_137 -> V_19 ,
F_211 ( V_36 -> V_510 ) , V_73 ,
F_95 ( V_176 ) ,
& V_313 ) ;
if ( V_62 )
return V_62 ;
V_14 = V_138 -> V_19 ;
V_14 -> V_311 = V_313 ;
return 0 ;
}
static int F_213 ( struct V_22 * V_22 , struct V_22 * V_308 ,
const struct V_309 * V_309 ,
const char * * V_73 ,
void * * V_511 , T_7 * V_96 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_45 * V_46 ;
T_2 V_17 , V_313 , V_512 ;
int V_62 ;
char * V_95 ;
V_46 = V_308 -> V_47 -> V_48 ;
V_17 = V_14 -> V_17 ;
V_313 = V_14 -> V_311 ;
V_62 = F_133 ( F_23 () ,
V_308 , V_309 ,
F_95 ( V_22 -> V_256 ) ,
& V_313 ) ;
if ( V_62 )
return V_62 ;
if ( V_46 -> V_87 & V_88 ) {
struct V_23 * V_24 = V_22 -> V_35 ;
V_24 -> V_31 = F_95 ( V_22 -> V_256 ) ;
V_24 -> V_17 = V_313 ;
V_24 -> V_33 = V_40 ;
}
if ( ! V_39 || ! ( V_46 -> V_87 & V_89 ) )
return - V_81 ;
if ( V_73 )
* V_73 = V_513 ;
if ( V_511 && V_96 ) {
V_62 = F_214 ( V_313 , & V_95 , & V_512 ) ;
if ( V_62 )
return V_62 ;
* V_511 = V_95 ;
* V_96 = V_512 ;
}
return 0 ;
}
static int F_215 ( struct V_22 * V_308 , struct V_36 * V_36 , T_5 V_176 )
{
return F_134 ( V_308 , V_36 , V_32 ) ;
}
static int F_216 ( struct V_36 * V_331 , struct V_22 * V_308 , struct V_36 * V_333 )
{
return F_136 ( V_308 , V_331 , V_324 ) ;
}
static int F_217 ( struct V_22 * V_308 , struct V_36 * V_36 )
{
return F_136 ( V_308 , V_36 , V_326 ) ;
}
static int F_218 ( struct V_22 * V_308 , struct V_36 * V_36 , const char * V_73 )
{
return F_134 ( V_308 , V_36 , V_181 ) ;
}
static int F_219 ( struct V_22 * V_308 , struct V_36 * V_36 , T_5 V_342 )
{
return F_134 ( V_308 , V_36 , V_186 ) ;
}
static int F_220 ( struct V_22 * V_308 , struct V_36 * V_36 )
{
return F_136 ( V_308 , V_36 , V_328 ) ;
}
static int F_221 ( struct V_22 * V_308 , struct V_36 * V_36 , T_5 V_176 , T_8 V_260 )
{
return F_134 ( V_308 , V_36 , F_95 ( V_176 ) ) ;
}
static int F_222 ( struct V_22 * V_514 , struct V_36 * V_331 ,
struct V_22 * V_515 , struct V_36 * V_333 )
{
return F_137 ( V_514 , V_331 , V_515 , V_333 ) ;
}
static int F_223 ( struct V_36 * V_36 )
{
const struct V_10 * V_10 = F_76 () ;
return F_128 ( V_10 , V_36 , V_346 ) ;
}
static int F_224 ( struct V_36 * V_36 , struct V_22 * V_22 ,
bool V_42 )
{
const struct V_10 * V_10 = F_76 () ;
struct V_288 V_289 ;
struct V_23 * V_24 ;
T_2 V_17 ;
F_126 ( V_10 ) ;
V_289 . type = V_303 ;
V_289 . V_294 . V_36 = V_36 ;
V_17 = F_17 ( V_10 ) ;
V_24 = F_32 ( V_22 , V_42 ) ;
if ( F_102 ( V_24 ) )
return F_103 ( V_24 ) ;
return F_225 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_346 , & V_289 ,
V_42 ? V_516 : 0 ) ;
}
static T_9 int F_226 ( struct V_22 * V_22 ,
T_2 V_274 , T_2 V_517 , T_2 V_518 ,
int V_519 ,
unsigned V_87 )
{
struct V_288 V_289 ;
struct V_23 * V_24 = V_22 -> V_35 ;
int V_62 ;
V_289 . type = V_520 ;
V_289 . V_294 . V_22 = V_22 ;
V_62 = F_227 ( F_22 () , V_24 -> V_17 , V_24 -> V_31 , V_274 ,
V_517 , V_518 , V_519 , & V_289 , V_87 ) ;
if ( V_62 )
return V_62 ;
return 0 ;
}
static int F_228 ( struct V_22 * V_22 , int V_342 )
{
const struct V_10 * V_10 = F_76 () ;
T_2 V_274 ;
bool V_521 ;
unsigned V_87 = V_342 & V_516 ;
struct V_23 * V_24 ;
T_2 V_17 ;
struct V_290 V_291 ;
int V_62 , V_300 ;
T_2 V_517 , V_518 ;
V_521 = V_342 & V_522 ;
V_342 &= ( V_345 | V_349 | V_343 | V_347 ) ;
if ( ! V_342 )
return 0 ;
F_126 ( V_10 ) ;
if ( F_127 ( F_65 ( V_22 ) ) )
return 0 ;
V_274 = F_141 ( V_22 -> V_256 , V_342 ) ;
V_17 = F_17 ( V_10 ) ;
V_24 = F_32 ( V_22 , V_87 & V_516 ) ;
if ( F_102 ( V_24 ) )
return F_103 ( V_24 ) ;
V_62 = F_122 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_274 , 0 , & V_291 ) ;
V_517 = F_229 ( V_274 , & V_291 , V_62 ,
V_521 ? V_523 : 0 ,
& V_518 ) ;
if ( F_230 ( ! V_517 ) )
return V_62 ;
V_300 = F_226 ( V_22 , V_274 , V_517 , V_518 , V_62 , V_87 ) ;
if ( V_300 )
return V_300 ;
return V_62 ;
}
static int F_231 ( struct V_36 * V_36 , struct V_524 * V_524 )
{
const struct V_10 * V_10 = F_76 () ;
unsigned int V_525 = V_524 -> V_525 ;
T_10 V_292 = V_350 ;
if ( V_525 & V_526 ) {
V_525 &= ~ ( V_527 | V_528 | V_529 |
V_526 ) ;
if ( ! V_525 )
return 0 ;
}
if ( V_525 & ( V_529 | V_530 | V_531 |
V_532 | V_533 | V_534 ) )
return F_128 ( V_10 , V_36 , V_535 ) ;
if ( V_359 && ( V_525 & V_536 )
&& ! ( V_525 & V_537 ) )
V_292 |= V_360 ;
return F_128 ( V_10 , V_36 , V_292 ) ;
}
static int F_232 ( const struct V_253 * V_253 )
{
return F_129 ( F_76 () , V_253 , V_538 ) ;
}
static int F_233 ( struct V_36 * V_36 , const char * V_73 )
{
const struct V_10 * V_10 = F_76 () ;
if ( ! strncmp ( V_73 , V_539 ,
sizeof V_539 - 1 ) ) {
if ( ! strcmp ( V_73 , V_540 ) ) {
if ( ! F_234 ( V_541 ) )
return - V_428 ;
} else if ( ! F_234 ( V_416 ) ) {
return - V_428 ;
}
}
return F_128 ( V_10 , V_36 , V_535 ) ;
}
static int F_235 ( struct V_36 * V_36 , const char * V_73 ,
const void * V_511 , T_7 V_542 , int V_87 )
{
struct V_22 * V_22 = F_36 ( V_36 ) ;
struct V_23 * V_24 ;
struct V_45 * V_46 ;
struct V_288 V_289 ;
T_2 V_313 , V_17 = F_22 () ;
int V_62 = 0 ;
if ( strcmp ( V_73 , V_83 ) )
return F_233 ( V_36 , V_73 ) ;
V_46 = V_22 -> V_47 -> V_48 ;
if ( ! ( V_46 -> V_87 & V_89 ) )
return - V_81 ;
if ( ! F_236 ( V_22 ) )
return - V_428 ;
V_289 . type = V_303 ;
V_289 . V_294 . V_36 = V_36 ;
V_24 = F_37 ( V_36 ) ;
V_62 = F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 ,
V_543 , & V_289 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_237 ( V_511 , V_542 , & V_313 , V_15 ) ;
if ( V_62 == - V_98 ) {
if ( ! F_234 ( V_544 ) ) {
struct V_545 * V_546 ;
T_7 V_547 ;
const char * V_1 ;
if ( V_511 ) {
V_1 = V_511 ;
if ( V_1 [ V_542 - 1 ] == '\0' )
V_547 = V_542 - 1 ;
else
V_547 = V_542 ;
} else {
V_1 = L_39 ;
V_547 = 0 ;
}
V_546 = F_238 ( V_11 -> V_548 , V_103 , V_549 ) ;
F_239 ( V_546 , L_40 ) ;
F_240 ( V_546 , V_511 , V_547 ) ;
F_241 ( V_546 ) ;
return V_62 ;
}
V_62 = F_242 ( V_511 , V_542 , & V_313 ) ;
}
if ( V_62 )
return V_62 ;
V_62 = F_55 ( V_17 , V_313 , V_24 -> V_31 ,
V_550 , & V_289 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_243 ( V_24 -> V_17 , V_313 , V_17 ,
V_24 -> V_31 ) ;
if ( V_62 )
return V_62 ;
return F_55 ( V_313 ,
V_46 -> V_17 ,
V_63 ,
V_66 ,
& V_289 ) ;
}
static void F_244 ( struct V_36 * V_36 , const char * V_73 ,
const void * V_511 , T_7 V_542 ,
int V_87 )
{
struct V_22 * V_22 = F_36 ( V_36 ) ;
struct V_23 * V_24 ;
T_2 V_313 ;
int V_62 ;
if ( strcmp ( V_73 , V_83 ) ) {
return;
}
V_62 = F_242 ( V_511 , V_542 , & V_313 ) ;
if ( V_62 ) {
F_59 ( V_86 L_41
L_42 ,
V_22 -> V_47 -> V_80 , V_22 -> V_259 , - V_62 ) ;
return;
}
V_24 = F_37 ( V_36 ) ;
F_43 ( & V_24 -> V_28 ) ;
V_24 -> V_31 = F_95 ( V_22 -> V_256 ) ;
V_24 -> V_17 = V_313 ;
V_24 -> V_33 = V_40 ;
F_45 ( & V_24 -> V_28 ) ;
return;
}
static int F_245 ( struct V_36 * V_36 , const char * V_73 )
{
const struct V_10 * V_10 = F_76 () ;
return F_128 ( V_10 , V_36 , V_538 ) ;
}
static int F_246 ( struct V_36 * V_36 )
{
const struct V_10 * V_10 = F_76 () ;
return F_128 ( V_10 , V_36 , V_538 ) ;
}
static int F_247 ( struct V_36 * V_36 , const char * V_73 )
{
if ( strcmp ( V_73 , V_83 ) )
return F_233 ( V_36 , V_73 ) ;
return - V_131 ;
}
static int F_248 ( struct V_22 * V_22 , const char * V_73 , void * * V_252 , bool V_551 )
{
T_2 V_542 ;
int error ;
char * V_95 = NULL ;
struct V_23 * V_24 ;
if ( strcmp ( V_73 , V_513 ) )
return - V_81 ;
error = F_249 ( F_76 () , & V_130 , V_544 ,
V_417 ) ;
if ( ! error )
error = F_119 ( F_76 () , V_544 ,
V_417 , true ) ;
V_24 = F_34 ( V_22 ) ;
if ( ! error )
error = F_214 ( V_24 -> V_17 , & V_95 ,
& V_542 ) ;
else
error = F_71 ( V_24 -> V_17 , & V_95 , & V_542 ) ;
if ( error )
return error ;
error = V_542 ;
if ( V_551 ) {
* V_252 = V_95 ;
goto V_552;
}
F_52 ( V_95 ) ;
V_552:
return error ;
}
static int F_250 ( struct V_22 * V_22 , const char * V_73 ,
const void * V_511 , T_7 V_542 , int V_87 )
{
struct V_23 * V_24 = F_31 ( V_22 ) ;
T_2 V_313 ;
int V_62 ;
if ( strcmp ( V_73 , V_513 ) )
return - V_81 ;
if ( ! V_511 || ! V_542 )
return - V_131 ;
V_62 = F_237 ( V_511 , V_542 , & V_313 , V_15 ) ;
if ( V_62 )
return V_62 ;
F_43 ( & V_24 -> V_28 ) ;
V_24 -> V_31 = F_95 ( V_22 -> V_256 ) ;
V_24 -> V_17 = V_313 ;
V_24 -> V_33 = V_40 ;
F_45 ( & V_24 -> V_28 ) ;
return 0 ;
}
static int F_251 ( struct V_22 * V_22 , char * V_252 , T_7 V_553 )
{
const int V_96 = sizeof( V_83 ) ;
if ( V_252 && V_96 <= V_553 )
memcpy ( V_252 , V_83 , V_96 ) ;
return V_96 ;
}
static void F_252 ( struct V_22 * V_22 , T_2 * V_554 )
{
struct V_23 * V_24 = F_31 ( V_22 ) ;
* V_554 = V_24 -> V_17 ;
}
static int F_253 ( struct V_36 * V_555 , struct V_10 * * V_138 )
{
T_2 V_17 ;
struct V_13 * V_14 ;
struct V_10 * V_556 = * V_138 ;
if ( V_556 == NULL ) {
V_556 = F_254 () ;
if ( ! V_556 )
return - V_27 ;
}
V_14 = V_556 -> V_19 ;
F_252 ( F_211 ( V_555 ) , & V_17 ) ;
V_14 -> V_311 = V_17 ;
* V_138 = V_556 ;
return 0 ;
}
static int F_255 ( const char * V_73 )
{
if ( strcmp ( V_73 , V_83 ) == 0 )
return 1 ;
return - V_81 ;
}
static int F_256 ( struct V_50 * V_50 , int V_342 )
{
const struct V_10 * V_10 = F_76 () ;
struct V_22 * V_22 = F_131 ( V_50 ) ;
if ( ( V_50 -> V_356 & V_357 ) && ( V_342 & V_349 ) )
V_342 |= V_347 ;
return F_132 ( V_10 , V_50 ,
F_141 ( V_22 -> V_256 , V_342 ) ) ;
}
static int F_257 ( struct V_50 * V_50 , int V_342 )
{
struct V_22 * V_22 = F_131 ( V_50 ) ;
struct V_51 * V_52 = V_50 -> V_55 ;
struct V_23 * V_24 ;
T_2 V_17 = F_22 () ;
if ( ! V_342 )
return 0 ;
V_24 = F_34 ( V_22 ) ;
if ( V_17 == V_52 -> V_17 && V_52 -> V_557 == V_24 -> V_17 &&
V_52 -> V_558 == F_258 () )
return 0 ;
return F_256 ( V_50 , V_342 ) ;
}
static int F_259 ( struct V_50 * V_50 )
{
return F_47 ( V_50 ) ;
}
static void F_260 ( struct V_50 * V_50 )
{
F_48 ( V_50 ) ;
}
static int F_261 ( const struct V_10 * V_10 , struct V_50 * V_50 ,
T_2 V_559 , T_4 V_560 )
{
struct V_288 V_289 ;
struct V_51 * V_52 = V_50 -> V_55 ;
struct V_22 * V_22 = F_131 ( V_50 ) ;
struct V_23 * V_24 ;
struct V_561 V_562 ;
T_2 V_563 = F_17 ( V_10 ) ;
int V_62 ;
T_11 V_564 = V_560 >> 8 ;
T_11 V_565 = V_560 & 0xff ;
V_289 . type = V_566 ;
V_289 . V_294 . V_567 = & V_562 ;
V_289 . V_294 . V_567 -> V_560 = V_560 ;
V_289 . V_294 . V_567 -> V_253 = V_50 -> V_373 ;
if ( V_563 != V_52 -> V_17 ) {
V_62 = F_55 ( V_563 , V_52 -> V_17 ,
V_306 ,
V_307 ,
& V_289 ) ;
if ( V_62 )
goto V_82;
}
if ( F_127 ( F_65 ( V_22 ) ) )
return 0 ;
V_24 = F_34 ( V_22 ) ;
V_62 = F_262 ( V_563 , V_24 -> V_17 , V_24 -> V_31 ,
V_559 , V_564 , V_565 , & V_289 ) ;
V_82:
return V_62 ;
}
static int F_263 ( struct V_50 * V_50 , unsigned int V_560 ,
unsigned long V_568 )
{
const struct V_10 * V_10 = F_76 () ;
int error = 0 ;
switch ( V_560 ) {
case V_569 :
case V_570 :
case V_571 :
case V_572 :
case V_573 :
error = F_132 ( V_10 , V_50 , V_538 ) ;
break;
case V_574 :
case V_575 :
error = F_132 ( V_10 , V_50 , V_535 ) ;
break;
case V_576 :
case V_577 :
error = F_132 ( V_10 , V_50 , 0 ) ;
break;
case V_578 :
case V_579 :
error = F_119 ( V_10 , V_580 ,
V_299 , true ) ;
break;
default:
error = F_261 ( V_10 , V_50 , V_358 , ( T_4 ) V_560 ) ;
}
return error ;
}
static int F_264 ( struct V_50 * V_50 , unsigned long V_581 , int V_582 )
{
const struct V_10 * V_10 = F_76 () ;
int V_62 = 0 ;
if ( V_583 &&
( V_581 & V_584 ) && ( ! V_50 || F_65 ( F_131 ( V_50 ) ) ||
( ! V_582 && ( V_581 & V_585 ) ) ) ) {
V_62 = F_116 ( V_10 , V_10 , V_586 ) ;
if ( V_62 )
goto error;
}
if ( V_50 ) {
T_2 V_292 = V_346 ;
if ( V_582 && ( V_581 & V_585 ) )
V_292 |= V_350 ;
if ( V_581 & V_584 )
V_292 |= V_344 ;
return F_132 ( V_10 , V_50 , V_292 ) ;
}
error:
return V_62 ;
}
static int F_265 ( unsigned long V_587 )
{
int V_62 = 0 ;
if ( V_587 < V_588 ) {
T_2 V_17 = F_22 () ;
V_62 = F_55 ( V_17 , V_17 , V_589 ,
V_590 , NULL ) ;
}
return V_62 ;
}
static int F_266 ( struct V_50 * V_50 , unsigned long V_591 ,
unsigned long V_581 , unsigned long V_87 )
{
if ( V_592 )
V_581 = V_591 ;
return F_264 ( V_50 , V_581 ,
( V_87 & V_593 ) == V_594 ) ;
}
static int F_267 ( struct V_595 * V_596 ,
unsigned long V_591 ,
unsigned long V_581 )
{
const struct V_10 * V_10 = F_76 () ;
if ( V_592 )
V_581 = V_591 ;
if ( V_583 &&
( V_581 & V_584 ) && ! ( V_596 -> V_597 & V_598 ) ) {
int V_62 = 0 ;
if ( V_596 -> V_599 >= V_596 -> V_600 -> V_601 &&
V_596 -> V_602 <= V_596 -> V_600 -> V_603 ) {
V_62 = F_116 ( V_10 , V_10 , V_604 ) ;
} else if ( ! V_596 -> V_605 &&
( ( V_596 -> V_599 <= V_596 -> V_600 -> V_606 &&
V_596 -> V_602 >= V_596 -> V_600 -> V_606 ) ||
F_268 ( V_596 ) ) ) {
V_62 = F_118 ( V_11 , V_607 ) ;
} else if ( V_596 -> V_605 && V_596 -> V_608 ) {
V_62 = F_132 ( V_10 , V_596 -> V_605 , V_609 ) ;
}
if ( V_62 )
return V_62 ;
}
return F_264 ( V_596 -> V_605 , V_581 , V_596 -> V_597 & V_610 ) ;
}
static int F_269 ( struct V_50 * V_50 , unsigned int V_560 )
{
const struct V_10 * V_10 = F_76 () ;
return F_132 ( V_10 , V_50 , V_611 ) ;
}
static int F_270 ( struct V_50 * V_50 , unsigned int V_560 ,
unsigned long V_568 )
{
const struct V_10 * V_10 = F_76 () ;
int V_612 = 0 ;
switch ( V_560 ) {
case V_613 :
if ( ( V_50 -> V_356 & V_357 ) && ! ( V_568 & V_357 ) ) {
V_612 = F_132 ( V_10 , V_50 , V_350 ) ;
break;
}
case V_614 :
case V_615 :
case V_616 :
case V_617 :
case V_618 :
case V_619 :
V_612 = F_132 ( V_10 , V_50 , 0 ) ;
break;
case V_620 :
case V_621 :
case V_622 :
case V_623 :
case V_624 :
case V_625 :
#if V_626 == 32
case V_627 :
case V_628 :
case V_629 :
#endif
V_612 = F_132 ( V_10 , V_50 , V_611 ) ;
break;
}
return V_612 ;
}
static void F_271 ( struct V_50 * V_50 )
{
struct V_51 * V_52 ;
V_52 = V_50 -> V_55 ;
V_52 -> V_54 = F_22 () ;
}
static int F_272 ( struct V_20 * V_284 ,
struct V_630 * V_631 , int V_632 )
{
struct V_50 * V_50 ;
T_2 V_17 = F_18 ( V_284 ) ;
T_2 V_264 ;
struct V_51 * V_52 ;
V_50 = F_39 ( V_631 , struct V_50 , V_633 ) ;
V_52 = V_50 -> V_55 ;
if ( ! V_632 )
V_264 = F_115 ( V_634 ) ;
else
V_264 = F_115 ( V_632 ) ;
return F_55 ( V_52 -> V_54 , V_17 ,
V_277 , V_264 , NULL ) ;
}
static int F_273 ( struct V_50 * V_50 )
{
const struct V_10 * V_10 = F_76 () ;
return F_132 ( V_10 , V_50 , F_143 ( V_50 ) ) ;
}
static int F_274 ( struct V_50 * V_50 , const struct V_10 * V_10 )
{
struct V_51 * V_52 ;
struct V_23 * V_24 ;
V_52 = V_50 -> V_55 ;
V_24 = F_34 ( F_131 ( V_50 ) ) ;
V_52 -> V_557 = V_24 -> V_17 ;
V_52 -> V_558 = F_258 () ;
return F_130 ( V_10 , V_50 , F_144 ( V_50 ) ) ;
}
static int F_275 ( unsigned long V_635 )
{
return F_118 ( V_11 , V_636 ) ;
}
static int F_276 ( struct V_10 * V_10 , T_12 V_637 )
{
struct V_13 * V_14 ;
V_14 = F_15 ( sizeof( struct V_13 ) , V_637 ) ;
if ( ! V_14 )
return - V_27 ;
V_10 -> V_19 = V_14 ;
return 0 ;
}
static void F_277 ( struct V_10 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_19 ;
F_72 ( V_10 -> V_19 && ( unsigned long ) V_10 -> V_19 < V_254 ) ;
V_10 -> V_19 = ( void * ) 0x7UL ;
F_52 ( V_14 ) ;
}
static int F_278 ( struct V_10 * V_138 , const struct V_10 * V_137 ,
T_12 V_637 )
{
const struct V_13 * V_421 ;
struct V_13 * V_14 ;
V_421 = V_137 -> V_19 ;
V_14 = F_279 ( V_421 , sizeof( struct V_13 ) , V_637 ) ;
if ( ! V_14 )
return - V_27 ;
V_138 -> V_19 = V_14 ;
return 0 ;
}
static void F_280 ( struct V_10 * V_138 , const struct V_10 * V_137 )
{
const struct V_13 * V_421 = V_137 -> V_19 ;
struct V_13 * V_14 = V_138 -> V_19 ;
* V_14 = * V_421 ;
}
static int F_281 ( struct V_10 * V_138 , T_2 V_554 )
{
struct V_13 * V_14 = V_138 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_638 ;
V_638 = F_55 ( V_17 , V_554 ,
V_639 ,
V_640 ,
NULL ) ;
if ( V_638 == 0 ) {
V_14 -> V_17 = V_554 ;
V_14 -> V_311 = 0 ;
V_14 -> V_430 = 0 ;
V_14 -> V_431 = 0 ;
}
return V_638 ;
}
static int F_282 ( struct V_10 * V_138 , struct V_22 * V_22 )
{
struct V_23 * V_24 = F_34 ( V_22 ) ;
struct V_13 * V_14 = V_138 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_638 ;
V_638 = F_55 ( V_17 , V_24 -> V_17 ,
V_639 ,
V_641 ,
NULL ) ;
if ( V_638 == 0 )
V_14 -> V_311 = V_24 -> V_17 ;
return V_638 ;
}
static int F_283 ( char * V_642 )
{
T_2 V_17 ;
struct V_288 V_289 ;
V_17 = F_18 ( V_11 ) ;
V_289 . type = V_643 ;
V_289 . V_294 . V_642 = V_642 ;
return F_55 ( V_17 , V_18 , V_301 ,
V_644 , & V_289 ) ;
}
static int F_284 ( struct V_50 * V_50 )
{
struct V_288 V_289 ;
struct V_23 * V_24 ;
struct V_51 * V_52 ;
T_2 V_17 = F_22 () ;
int V_62 ;
if ( V_50 == NULL )
return F_55 ( V_17 , V_17 , V_301 ,
V_645 , NULL ) ;
V_289 . type = V_305 ;
V_289 . V_294 . V_50 = V_50 ;
V_52 = V_50 -> V_55 ;
if ( V_17 != V_52 -> V_17 ) {
V_62 = F_55 ( V_17 , V_52 -> V_17 , V_306 , V_307 , & V_289 ) ;
if ( V_62 )
return V_62 ;
}
V_24 = F_34 ( F_131 ( V_50 ) ) ;
return F_55 ( V_17 , V_24 -> V_17 , V_301 ,
V_645 , & V_289 ) ;
}
static int F_285 ( struct V_50 * V_50 ,
enum V_646 V_387 )
{
int V_62 = 0 ;
switch ( V_387 ) {
case V_647 :
V_62 = F_284 ( V_50 ) ;
break;
default:
break;
}
return V_62 ;
}
static int F_286 ( struct V_20 * V_153 , T_13 V_648 )
{
return F_118 ( V_153 , V_649 ) ;
}
static int F_287 ( struct V_20 * V_153 )
{
return F_118 ( V_153 , V_650 ) ;
}
static int F_288 ( struct V_20 * V_153 )
{
return F_118 ( V_153 , V_651 ) ;
}
static void F_289 ( struct V_20 * V_153 , T_2 * V_554 )
{
* V_554 = F_18 ( V_153 ) ;
}
static int F_290 ( struct V_20 * V_153 , int V_652 )
{
return F_118 ( V_153 , V_653 ) ;
}
static int F_291 ( struct V_20 * V_153 , int V_654 )
{
return F_118 ( V_153 , V_653 ) ;
}
static int F_292 ( struct V_20 * V_153 )
{
return F_118 ( V_153 , V_655 ) ;
}
static int F_293 ( struct V_20 * V_153 , unsigned int V_656 ,
struct V_459 * V_657 )
{
struct V_459 * V_658 = V_153 -> signal -> V_460 + V_656 ;
if ( V_658 -> V_467 != V_657 -> V_467 )
return F_118 ( V_153 , V_659 ) ;
return 0 ;
}
static int F_294 ( struct V_20 * V_153 )
{
return F_118 ( V_153 , V_653 ) ;
}
static int F_295 ( struct V_20 * V_153 )
{
return F_118 ( V_153 , V_655 ) ;
}
static int F_296 ( struct V_20 * V_153 )
{
return F_118 ( V_153 , V_653 ) ;
}
static int F_297 ( struct V_20 * V_153 , struct V_660 * V_661 ,
int V_263 , T_2 V_554 )
{
T_2 V_264 ;
int V_62 ;
if ( ! V_263 )
V_264 = V_662 ;
else
V_264 = F_115 ( V_263 ) ;
if ( V_554 )
V_62 = F_55 ( V_554 , F_18 ( V_153 ) ,
V_277 , V_264 , NULL ) ;
else
V_62 = F_118 ( V_153 , V_264 ) ;
return V_62 ;
}
static int F_298 ( struct V_20 * V_153 )
{
return F_117 ( V_153 , V_11 , V_266 ) ;
}
static void F_299 ( struct V_20 * V_153 ,
struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_35 ;
T_2 V_17 = F_18 ( V_153 ) ;
F_43 ( & V_24 -> V_28 ) ;
V_24 -> V_31 = F_95 ( V_22 -> V_256 ) ;
V_24 -> V_17 = V_17 ;
V_24 -> V_33 = V_40 ;
F_45 ( & V_24 -> V_28 ) ;
}
static int F_300 ( struct V_663 * V_664 ,
struct V_288 * V_289 , T_11 * V_665 )
{
int V_666 , V_667 , V_638 = - V_98 ;
struct V_668 V_669 , * V_670 ;
V_666 = F_301 ( V_664 ) ;
V_670 = F_302 ( V_664 , V_666 , sizeof( V_669 ) , & V_669 ) ;
if ( V_670 == NULL )
goto V_82;
V_667 = V_670 -> V_671 * 4 ;
if ( V_667 < sizeof( V_669 ) )
goto V_82;
V_289 -> V_294 . V_672 -> V_673 . V_674 = V_670 -> V_674 ;
V_289 -> V_294 . V_672 -> V_673 . V_675 = V_670 -> V_675 ;
V_638 = 0 ;
if ( V_665 )
* V_665 = V_670 -> V_191 ;
switch ( V_670 -> V_191 ) {
case V_193 : {
struct V_676 V_677 , * V_678 ;
if ( F_303 ( V_670 -> V_679 ) & V_680 )
break;
V_666 += V_667 ;
V_678 = F_302 ( V_664 , V_666 , sizeof( V_677 ) , & V_677 ) ;
if ( V_678 == NULL )
break;
V_289 -> V_294 . V_672 -> V_681 = V_678 -> V_682 ;
V_289 -> V_294 . V_672 -> V_683 = V_678 -> V_684 ;
break;
}
case V_194 : {
struct V_685 V_686 , * V_687 ;
if ( F_303 ( V_670 -> V_679 ) & V_680 )
break;
V_666 += V_667 ;
V_687 = F_302 ( V_664 , V_666 , sizeof( V_686 ) , & V_686 ) ;
if ( V_687 == NULL )
break;
V_289 -> V_294 . V_672 -> V_681 = V_687 -> V_682 ;
V_289 -> V_294 . V_672 -> V_683 = V_687 -> V_684 ;
break;
}
case V_688 : {
struct V_689 V_690 , * V_691 ;
if ( F_303 ( V_670 -> V_679 ) & V_680 )
break;
V_666 += V_667 ;
V_691 = F_302 ( V_664 , V_666 , sizeof( V_690 ) , & V_690 ) ;
if ( V_691 == NULL )
break;
V_289 -> V_294 . V_672 -> V_681 = V_691 -> V_692 ;
V_289 -> V_294 . V_672 -> V_683 = V_691 -> V_693 ;
break;
}
default:
break;
}
V_82:
return V_638 ;
}
static int F_304 ( struct V_663 * V_664 ,
struct V_288 * V_289 , T_11 * V_665 )
{
T_11 V_694 ;
int V_638 = - V_98 , V_666 ;
struct V_695 V_696 , * V_697 ;
T_14 V_679 ;
V_666 = F_301 ( V_664 ) ;
V_697 = F_302 ( V_664 , V_666 , sizeof( V_696 ) , & V_696 ) ;
if ( V_697 == NULL )
goto V_82;
V_289 -> V_294 . V_672 -> V_698 . V_674 = V_697 -> V_674 ;
V_289 -> V_294 . V_672 -> V_698 . V_675 = V_697 -> V_675 ;
V_638 = 0 ;
V_694 = V_697 -> V_694 ;
V_666 += sizeof( V_696 ) ;
V_666 = F_305 ( V_664 , V_666 , & V_694 , & V_679 ) ;
if ( V_666 < 0 )
goto V_82;
if ( V_665 )
* V_665 = V_694 ;
switch ( V_694 ) {
case V_193 : {
struct V_676 V_677 , * V_678 ;
V_678 = F_302 ( V_664 , V_666 , sizeof( V_677 ) , & V_677 ) ;
if ( V_678 == NULL )
break;
V_289 -> V_294 . V_672 -> V_681 = V_678 -> V_682 ;
V_289 -> V_294 . V_672 -> V_683 = V_678 -> V_684 ;
break;
}
case V_194 : {
struct V_685 V_686 , * V_687 ;
V_687 = F_302 ( V_664 , V_666 , sizeof( V_686 ) , & V_686 ) ;
if ( V_687 == NULL )
break;
V_289 -> V_294 . V_672 -> V_681 = V_687 -> V_682 ;
V_289 -> V_294 . V_672 -> V_683 = V_687 -> V_684 ;
break;
}
case V_688 : {
struct V_689 V_690 , * V_691 ;
V_691 = F_302 ( V_664 , V_666 , sizeof( V_690 ) , & V_690 ) ;
if ( V_691 == NULL )
break;
V_289 -> V_294 . V_672 -> V_681 = V_691 -> V_692 ;
V_289 -> V_294 . V_672 -> V_683 = V_691 -> V_693 ;
break;
}
default:
break;
}
V_82:
return V_638 ;
}
static int F_306 ( struct V_663 * V_664 , struct V_288 * V_289 ,
char * * V_699 , int V_555 , T_11 * V_665 )
{
char * V_700 ;
int V_638 ;
switch ( V_289 -> V_294 . V_672 -> V_195 ) {
case V_202 :
V_638 = F_300 ( V_664 , V_289 , V_665 ) ;
if ( V_638 )
goto V_701;
V_700 = ( char * ) ( V_555 ? & V_289 -> V_294 . V_672 -> V_673 . V_674 :
& V_289 -> V_294 . V_672 -> V_673 . V_675 ) ;
goto V_702;
#if F_179 ( V_703 )
case V_203 :
V_638 = F_304 ( V_664 , V_289 , V_665 ) ;
if ( V_638 )
goto V_701;
V_700 = ( char * ) ( V_555 ? & V_289 -> V_294 . V_672 -> V_698 . V_674 :
& V_289 -> V_294 . V_672 -> V_698 . V_675 ) ;
goto V_702;
#endif
default:
V_700 = NULL ;
goto V_702;
}
V_701:
F_59 ( V_79
L_43
L_44 ) ;
return V_638 ;
V_702:
if ( V_699 )
* V_699 = V_700 ;
return 0 ;
}
static int F_307 ( struct V_663 * V_664 , T_4 V_195 , T_2 * V_17 )
{
int V_612 ;
T_2 V_704 ;
T_2 V_705 ;
T_2 V_706 ;
V_612 = F_308 ( V_664 , & V_704 ) ;
if ( F_127 ( V_612 ) )
return - V_131 ;
V_612 = F_309 ( V_664 , V_195 , & V_706 , & V_705 ) ;
if ( F_127 ( V_612 ) )
return - V_131 ;
V_612 = F_310 ( V_705 , V_706 , V_704 , V_17 ) ;
if ( F_127 ( V_612 ) ) {
F_59 ( V_79
L_45
L_46 ) ;
return - V_131 ;
}
return 0 ;
}
static int F_311 ( T_2 V_707 , T_2 V_708 , T_2 * V_709 )
{
int V_612 = 0 ;
if ( V_708 != V_710 )
V_612 = F_312 ( V_707 , V_708 , V_709 ) ;
else
* V_709 = V_707 ;
return V_612 ;
}
static int F_313 ( const struct V_13 * V_14 ,
T_4 V_711 , T_2 * V_712 )
{
if ( V_14 -> V_431 > V_710 ) {
* V_712 = V_14 -> V_431 ;
return 0 ;
}
return F_80 ( V_14 -> V_17 , V_14 -> V_17 , V_711 , NULL ,
V_712 ) ;
}
static int F_314 ( struct V_20 * V_21 , struct V_713 * V_714 , T_2 V_274 )
{
struct V_715 * V_716 = V_714 -> V_717 ;
struct V_288 V_289 ;
struct V_718 V_672 = { 0 ,} ;
T_2 V_276 = F_18 ( V_21 ) ;
if ( V_716 -> V_17 == V_18 )
return 0 ;
V_289 . type = V_719 ;
V_289 . V_294 . V_672 = & V_672 ;
V_289 . V_294 . V_672 -> V_714 = V_714 ;
return F_55 ( V_276 , V_716 -> V_17 , V_716 -> V_31 , V_274 , & V_289 ) ;
}
static int F_315 ( int V_195 , int type ,
int V_191 , int V_720 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_313 ;
T_4 V_711 ;
int V_62 ;
if ( V_720 )
return 0 ;
V_711 = F_98 ( V_195 , type , V_191 ) ;
V_62 = F_313 ( V_14 , V_711 , & V_313 ) ;
if ( V_62 )
return V_62 ;
return F_55 ( V_14 -> V_17 , V_313 , V_711 , V_721 , NULL ) ;
}
static int F_316 ( struct V_722 * V_713 , int V_195 ,
int type , int V_191 , int V_720 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_24 = F_31 ( F_317 ( V_713 ) ) ;
struct V_715 * V_716 ;
T_4 V_31 = F_98 ( V_195 , type , V_191 ) ;
T_2 V_17 = V_18 ;
int V_612 = 0 ;
if ( ! V_720 ) {
V_612 = F_313 ( V_14 , V_31 , & V_17 ) ;
if ( V_612 )
return V_612 ;
}
V_24 -> V_31 = V_31 ;
V_24 -> V_17 = V_17 ;
V_24 -> V_33 = V_40 ;
if ( V_713 -> V_714 ) {
V_716 = V_713 -> V_714 -> V_717 ;
V_716 -> V_31 = V_31 ;
V_716 -> V_17 = V_17 ;
V_612 = F_318 ( V_713 -> V_714 , V_195 ) ;
}
return V_612 ;
}
static int F_319 ( struct V_722 * V_713 , struct V_723 * V_724 , int V_725 )
{
struct V_713 * V_714 = V_713 -> V_714 ;
T_4 V_195 ;
int V_612 ;
V_612 = F_314 ( V_11 , V_714 , V_726 ) ;
if ( V_612 )
goto V_82;
V_195 = V_714 -> V_727 ;
if ( V_195 == V_202 || V_195 == V_203 ) {
char * V_700 ;
struct V_715 * V_716 = V_714 -> V_717 ;
struct V_288 V_289 ;
struct V_718 V_672 = { 0 ,} ;
struct V_728 * V_729 = NULL ;
struct V_730 * V_731 = NULL ;
unsigned short V_732 ;
T_2 V_17 , V_733 ;
if ( V_195 == V_202 ) {
V_729 = (struct V_728 * ) V_724 ;
V_732 = F_303 ( V_729 -> V_734 ) ;
V_700 = ( char * ) & V_729 -> V_735 . V_736 ;
} else {
V_731 = (struct V_730 * ) V_724 ;
V_732 = F_303 ( V_731 -> V_737 ) ;
V_700 = ( char * ) & V_731 -> V_738 . V_739 ;
}
if ( V_732 ) {
int V_740 , V_741 ;
F_320 ( F_321 ( V_714 ) , & V_740 , & V_741 ) ;
if ( V_732 < V_742 ( V_743, V_740 ) || V_732 > V_741 ) {
V_612 = F_322 ( V_714 -> V_744 ,
V_732 , & V_17 ) ;
if ( V_612 )
goto V_82;
V_289 . type = V_719 ;
V_289 . V_294 . V_672 = & V_672 ;
V_289 . V_294 . V_672 -> V_681 = F_323 ( V_732 ) ;
V_289 . V_294 . V_672 -> V_195 = V_195 ;
V_612 = F_55 ( V_716 -> V_17 , V_17 ,
V_716 -> V_31 ,
V_745 , & V_289 ) ;
if ( V_612 )
goto V_82;
}
}
switch ( V_716 -> V_31 ) {
case V_204 :
V_733 = V_746 ;
break;
case V_206 :
V_733 = V_747 ;
break;
case V_208 :
V_733 = V_748 ;
break;
default:
V_733 = V_749 ;
break;
}
V_612 = F_324 ( V_700 , V_195 , & V_17 ) ;
if ( V_612 )
goto V_82;
V_289 . type = V_719 ;
V_289 . V_294 . V_672 = & V_672 ;
V_289 . V_294 . V_672 -> V_681 = F_323 ( V_732 ) ;
V_289 . V_294 . V_672 -> V_195 = V_195 ;
if ( V_195 == V_202 )
V_289 . V_294 . V_672 -> V_673 . V_674 = V_729 -> V_735 . V_736 ;
else
V_289 . V_294 . V_672 -> V_698 . V_674 = V_731 -> V_738 ;
V_612 = F_55 ( V_716 -> V_17 , V_17 ,
V_716 -> V_31 , V_733 , & V_289 ) ;
if ( V_612 )
goto V_82;
}
V_82:
return V_612 ;
}
static int F_325 ( struct V_722 * V_713 , struct V_723 * V_724 , int V_725 )
{
struct V_713 * V_714 = V_713 -> V_714 ;
struct V_715 * V_716 = V_714 -> V_717 ;
int V_612 ;
V_612 = F_314 ( V_11 , V_714 , V_750 ) ;
if ( V_612 )
return V_612 ;
if ( V_716 -> V_31 == V_204 ||
V_716 -> V_31 == V_208 ) {
struct V_288 V_289 ;
struct V_718 V_672 = { 0 ,} ;
struct V_728 * V_729 = NULL ;
struct V_730 * V_731 = NULL ;
unsigned short V_732 ;
T_2 V_17 , V_264 ;
if ( V_714 -> V_727 == V_202 ) {
V_729 = (struct V_728 * ) V_724 ;
if ( V_725 < sizeof( struct V_728 ) )
return - V_98 ;
V_732 = F_303 ( V_729 -> V_734 ) ;
} else {
V_731 = (struct V_730 * ) V_724 ;
if ( V_725 < V_751 )
return - V_98 ;
V_732 = F_303 ( V_731 -> V_737 ) ;
}
V_612 = F_322 ( V_714 -> V_744 , V_732 , & V_17 ) ;
if ( V_612 )
goto V_82;
V_264 = ( V_716 -> V_31 == V_204 ) ?
V_752 : V_753 ;
V_289 . type = V_719 ;
V_289 . V_294 . V_672 = & V_672 ;
V_289 . V_294 . V_672 -> V_683 = F_323 ( V_732 ) ;
V_289 . V_294 . V_672 -> V_195 = V_714 -> V_727 ;
V_612 = F_55 ( V_716 -> V_17 , V_17 , V_716 -> V_31 , V_264 , & V_289 ) ;
if ( V_612 )
goto V_82;
}
V_612 = F_326 ( V_714 , V_724 ) ;
V_82:
return V_612 ;
}
static int F_327 ( struct V_722 * V_713 , int V_754 )
{
return F_314 ( V_11 , V_713 -> V_714 , V_755 ) ;
}
static int F_328 ( struct V_722 * V_713 , struct V_722 * V_756 )
{
int V_612 ;
struct V_23 * V_24 ;
struct V_23 * V_150 ;
T_4 V_31 ;
T_2 V_17 ;
V_612 = F_314 ( V_11 , V_713 -> V_714 , V_757 ) ;
if ( V_612 )
return V_612 ;
V_24 = F_31 ( F_317 ( V_713 ) ) ;
F_43 ( & V_24 -> V_28 ) ;
V_31 = V_24 -> V_31 ;
V_17 = V_24 -> V_17 ;
F_45 ( & V_24 -> V_28 ) ;
V_150 = F_31 ( F_317 ( V_756 ) ) ;
V_150 -> V_31 = V_31 ;
V_150 -> V_17 = V_17 ;
V_150 -> V_33 = V_40 ;
return 0 ;
}
static int F_329 ( struct V_722 * V_713 , struct V_758 * V_759 ,
int V_542 )
{
return F_314 ( V_11 , V_713 -> V_714 , V_760 ) ;
}
static int F_330 ( struct V_722 * V_713 , struct V_758 * V_759 ,
int V_542 , int V_87 )
{
return F_314 ( V_11 , V_713 -> V_714 , V_761 ) ;
}
static int F_331 ( struct V_722 * V_713 )
{
return F_314 ( V_11 , V_713 -> V_714 , V_762 ) ;
}
static int F_332 ( struct V_722 * V_713 )
{
return F_314 ( V_11 , V_713 -> V_714 , V_762 ) ;
}
static int F_333 ( struct V_722 * V_713 , int V_763 , int V_764 )
{
int V_612 ;
V_612 = F_314 ( V_11 , V_713 -> V_714 , V_765 ) ;
if ( V_612 )
return V_612 ;
return F_334 ( V_713 , V_763 , V_764 ) ;
}
static int F_335 ( struct V_722 * V_713 , int V_763 ,
int V_764 )
{
return F_314 ( V_11 , V_713 -> V_714 , V_766 ) ;
}
static int F_336 ( struct V_722 * V_713 , int V_767 )
{
return F_314 ( V_11 , V_713 -> V_714 , V_768 ) ;
}
static int F_337 ( struct V_713 * V_713 ,
struct V_713 * V_769 ,
struct V_713 * V_770 )
{
struct V_715 * V_771 = V_713 -> V_717 ;
struct V_715 * V_772 = V_769 -> V_717 ;
struct V_715 * V_773 = V_770 -> V_717 ;
struct V_288 V_289 ;
struct V_718 V_672 = { 0 ,} ;
int V_612 ;
V_289 . type = V_719 ;
V_289 . V_294 . V_672 = & V_672 ;
V_289 . V_294 . V_672 -> V_714 = V_769 ;
V_612 = F_55 ( V_771 -> V_17 , V_772 -> V_17 ,
V_772 -> V_31 ,
V_774 , & V_289 ) ;
if ( V_612 )
return V_612 ;
V_773 -> V_775 = V_771 -> V_17 ;
V_612 = F_312 ( V_772 -> V_17 , V_771 -> V_17 ,
& V_773 -> V_17 ) ;
if ( V_612 )
return V_612 ;
V_771 -> V_775 = V_773 -> V_17 ;
return 0 ;
}
static int F_338 ( struct V_722 * V_713 ,
struct V_722 * V_769 )
{
struct V_715 * V_776 = V_713 -> V_714 -> V_717 ;
struct V_715 * V_777 = V_769 -> V_714 -> V_717 ;
struct V_288 V_289 ;
struct V_718 V_672 = { 0 ,} ;
V_289 . type = V_719 ;
V_289 . V_294 . V_672 = & V_672 ;
V_289 . V_294 . V_672 -> V_714 = V_769 -> V_714 ;
return F_55 ( V_776 -> V_17 , V_777 -> V_17 , V_777 -> V_31 , V_778 ,
& V_289 ) ;
}
static int F_339 ( struct V_672 * V_385 , int V_779 ,
char * V_700 , T_4 V_195 , T_2 V_775 ,
struct V_288 * V_289 )
{
int V_612 ;
T_2 V_780 ;
T_2 V_781 ;
V_612 = F_340 ( V_385 , V_779 , & V_780 ) ;
if ( V_612 )
return V_612 ;
V_612 = F_55 ( V_775 , V_780 ,
V_782 , V_783 , V_289 ) ;
if ( V_612 )
return V_612 ;
V_612 = F_324 ( V_700 , V_195 , & V_781 ) ;
if ( V_612 )
return V_612 ;
return F_55 ( V_775 , V_781 ,
V_784 , V_785 , V_289 ) ;
}
static int F_341 ( struct V_713 * V_714 , struct V_663 * V_664 ,
T_4 V_195 )
{
int V_612 = 0 ;
struct V_715 * V_716 = V_714 -> V_717 ;
T_2 V_707 = V_716 -> V_17 ;
struct V_288 V_289 ;
struct V_718 V_672 = { 0 ,} ;
char * V_700 ;
V_289 . type = V_719 ;
V_289 . V_294 . V_672 = & V_672 ;
V_289 . V_294 . V_672 -> V_786 = V_664 -> V_787 ;
V_289 . V_294 . V_672 -> V_195 = V_195 ;
V_612 = F_306 ( V_664 , & V_289 , & V_700 , 1 , NULL ) ;
if ( V_612 )
return V_612 ;
if ( F_4 () ) {
V_612 = F_55 ( V_707 , V_664 -> V_788 , V_789 ,
V_790 , & V_289 ) ;
if ( V_612 )
return V_612 ;
}
V_612 = F_342 ( V_716 , V_664 , V_195 , & V_289 ) ;
if ( V_612 )
return V_612 ;
V_612 = F_343 ( V_716 -> V_17 , V_664 , & V_289 ) ;
return V_612 ;
}
static int F_344 ( struct V_713 * V_714 , struct V_663 * V_664 )
{
int V_612 ;
struct V_715 * V_716 = V_714 -> V_717 ;
T_4 V_195 = V_714 -> V_727 ;
T_2 V_707 = V_716 -> V_17 ;
struct V_288 V_289 ;
struct V_718 V_672 = { 0 ,} ;
char * V_700 ;
T_11 V_791 ;
T_11 V_792 ;
if ( V_195 != V_202 && V_195 != V_203 )
return 0 ;
if ( V_195 == V_203 && V_664 -> V_191 == F_323 ( V_793 ) )
V_195 = V_202 ;
if ( ! V_794 )
return F_341 ( V_714 , V_664 , V_195 ) ;
V_791 = F_4 () ;
V_792 = F_6 () ;
if ( ! V_791 && ! V_792 )
return 0 ;
V_289 . type = V_719 ;
V_289 . V_294 . V_672 = & V_672 ;
V_289 . V_294 . V_672 -> V_786 = V_664 -> V_787 ;
V_289 . V_294 . V_672 -> V_195 = V_195 ;
V_612 = F_306 ( V_664 , & V_289 , & V_700 , 1 , NULL ) ;
if ( V_612 )
return V_612 ;
if ( V_792 ) {
T_2 V_775 ;
V_612 = F_307 ( V_664 , V_195 , & V_775 ) ;
if ( V_612 )
return V_612 ;
V_612 = F_339 ( F_321 ( V_714 ) , V_664 -> V_787 ,
V_700 , V_195 , V_775 , & V_289 ) ;
if ( V_612 ) {
F_345 ( V_664 , V_195 , V_612 , 0 ) ;
return V_612 ;
}
V_612 = F_55 ( V_707 , V_775 , V_795 ,
V_796 , & V_289 ) ;
if ( V_612 ) {
F_345 ( V_664 , V_195 , V_612 , 0 ) ;
return V_612 ;
}
}
if ( V_791 ) {
V_612 = F_55 ( V_707 , V_664 -> V_788 , V_789 ,
V_790 , & V_289 ) ;
if ( V_612 )
return V_612 ;
}
return V_612 ;
}
static int F_346 ( struct V_722 * V_713 , char T_15 * V_797 ,
int T_15 * V_798 , unsigned V_96 )
{
int V_612 = 0 ;
char * V_799 ;
T_2 V_800 ;
struct V_715 * V_716 = V_713 -> V_714 -> V_717 ;
T_2 V_775 = V_710 ;
if ( V_716 -> V_31 == V_199 ||
V_716 -> V_31 == V_204 )
V_775 = V_716 -> V_775 ;
if ( V_775 == V_710 )
return - V_801 ;
V_612 = F_71 ( V_775 , & V_799 , & V_800 ) ;
if ( V_612 )
return V_612 ;
if ( V_800 > V_96 ) {
V_612 = - V_258 ;
goto V_802;
}
if ( F_347 ( V_797 , V_799 , V_800 ) )
V_612 = - V_803 ;
V_802:
if ( F_348 ( V_800 , V_798 ) )
V_612 = - V_803 ;
F_52 ( V_799 ) ;
return V_612 ;
}
static int F_349 ( struct V_722 * V_713 , struct V_663 * V_664 , T_2 * V_554 )
{
T_2 V_804 = V_710 ;
T_4 V_195 ;
struct V_23 * V_24 ;
if ( V_664 && V_664 -> V_191 == F_323 ( V_793 ) )
V_195 = V_202 ;
else if ( V_664 && V_664 -> V_191 == F_323 ( V_805 ) )
V_195 = V_203 ;
else if ( V_713 )
V_195 = V_713 -> V_714 -> V_727 ;
else
goto V_82;
if ( V_713 && V_195 == V_196 ) {
V_24 = F_31 ( F_317 ( V_713 ) ) ;
V_804 = V_24 -> V_17 ;
} else if ( V_664 )
F_307 ( V_664 , V_195 , & V_804 ) ;
V_82:
* V_554 = V_804 ;
if ( V_804 == V_710 )
return - V_98 ;
return 0 ;
}
static int F_350 ( struct V_713 * V_714 , int V_195 , T_12 V_806 )
{
struct V_715 * V_716 ;
V_716 = F_15 ( sizeof( * V_716 ) , V_806 ) ;
if ( ! V_716 )
return - V_27 ;
V_716 -> V_775 = V_30 ;
V_716 -> V_17 = V_30 ;
V_716 -> V_31 = V_249 ;
F_351 ( V_716 ) ;
V_714 -> V_717 = V_716 ;
return 0 ;
}
static void F_352 ( struct V_713 * V_714 )
{
struct V_715 * V_716 = V_714 -> V_717 ;
V_714 -> V_717 = NULL ;
F_353 ( V_716 ) ;
F_52 ( V_716 ) ;
}
static void F_354 ( const struct V_713 * V_714 , struct V_713 * V_770 )
{
struct V_715 * V_716 = V_714 -> V_717 ;
struct V_715 * V_807 = V_770 -> V_717 ;
V_807 -> V_17 = V_716 -> V_17 ;
V_807 -> V_775 = V_716 -> V_775 ;
V_807 -> V_31 = V_716 -> V_31 ;
F_351 ( V_807 ) ;
}
static void F_355 ( struct V_713 * V_714 , T_2 * V_554 )
{
if ( ! V_714 )
* V_554 = V_808 ;
else {
struct V_715 * V_716 = V_714 -> V_717 ;
* V_554 = V_716 -> V_17 ;
}
}
static void F_356 ( struct V_713 * V_714 , struct V_722 * V_378 )
{
struct V_23 * V_24 =
F_31 ( F_317 ( V_378 ) ) ;
struct V_715 * V_716 = V_714 -> V_717 ;
if ( V_714 -> V_727 == V_202 || V_714 -> V_727 == V_203 ||
V_714 -> V_727 == V_196 )
V_24 -> V_17 = V_716 -> V_17 ;
V_716 -> V_31 = V_24 -> V_31 ;
}
static int F_357 ( struct V_713 * V_714 , struct V_663 * V_664 ,
struct V_809 * V_810 )
{
struct V_715 * V_716 = V_714 -> V_717 ;
int V_612 ;
T_4 V_195 = V_810 -> V_811 -> V_195 ;
T_2 V_812 ;
T_2 V_813 ;
V_612 = F_307 ( V_664 , V_195 , & V_813 ) ;
if ( V_612 )
return V_612 ;
V_612 = F_311 ( V_716 -> V_17 , V_813 , & V_812 ) ;
if ( V_612 )
return V_612 ;
V_810 -> V_554 = V_812 ;
V_810 -> V_804 = V_813 ;
return F_358 ( V_810 , V_195 ) ;
}
static void F_359 ( struct V_713 * V_770 ,
const struct V_809 * V_810 )
{
struct V_715 * V_807 = V_770 -> V_717 ;
V_807 -> V_17 = V_810 -> V_554 ;
V_807 -> V_775 = V_810 -> V_804 ;
F_360 ( V_770 , V_810 -> V_811 -> V_195 ) ;
}
static void F_361 ( struct V_713 * V_714 , struct V_663 * V_664 )
{
T_4 V_195 = V_714 -> V_727 ;
struct V_715 * V_716 = V_714 -> V_717 ;
if ( V_195 == V_203 && V_664 -> V_191 == F_323 ( V_793 ) )
V_195 = V_202 ;
F_307 ( V_664 , V_195 , & V_716 -> V_775 ) ;
}
static int F_362 ( T_2 V_17 )
{
const struct V_13 * V_814 ;
T_2 V_276 ;
V_814 = F_23 () ;
V_276 = V_814 -> V_17 ;
return F_55 ( V_276 , V_17 , V_789 , V_815 , NULL ) ;
}
static void F_363 ( void )
{
F_364 ( & V_7 ) ;
}
static void F_365 ( void )
{
F_366 ( & V_7 ) ;
}
static void F_367 ( const struct V_809 * V_810 ,
struct V_816 * V_817 )
{
V_817 -> V_818 = V_810 -> V_554 ;
}
static int F_368 ( void * * V_19 )
{
struct V_819 * V_820 ;
V_820 = F_15 ( sizeof( * V_820 ) , V_15 ) ;
if ( ! V_820 )
return - V_27 ;
V_820 -> V_17 = F_22 () ;
* V_19 = V_820 ;
return 0 ;
}
static void F_369 ( void * V_19 )
{
F_52 ( V_19 ) ;
}
static int F_370 ( void )
{
T_2 V_17 = F_22 () ;
return F_55 ( V_17 , V_17 , V_821 , V_822 ,
NULL ) ;
}
static int F_371 ( void * V_19 )
{
struct V_819 * V_820 = V_19 ;
return F_55 ( F_22 () , V_820 -> V_17 , V_821 ,
V_823 , NULL ) ;
}
static int F_372 ( struct V_713 * V_714 , void * V_19 )
{
struct V_819 * V_820 = V_19 ;
struct V_715 * V_716 = V_714 -> V_717 ;
V_716 -> V_17 = V_820 -> V_17 ;
V_716 -> V_31 = V_821 ;
return 0 ;
}
static int F_373 ( void * V_19 )
{
struct V_819 * V_820 = V_19 ;
T_2 V_17 = F_22 () ;
int V_612 ;
V_612 = F_55 ( V_17 , V_820 -> V_17 , V_821 ,
V_824 , NULL ) ;
if ( V_612 )
return V_612 ;
V_612 = F_55 ( V_17 , V_17 , V_821 ,
V_825 , NULL ) ;
if ( V_612 )
return V_612 ;
V_820 -> V_17 = V_17 ;
return 0 ;
}
static int F_374 ( struct V_713 * V_714 , struct V_663 * V_664 )
{
int V_612 = 0 ;
T_2 V_264 ;
struct V_826 * V_827 ;
struct V_715 * V_716 = V_714 -> V_717 ;
if ( V_664 -> V_96 < V_828 ) {
V_612 = - V_98 ;
goto V_82;
}
V_827 = F_375 ( V_664 ) ;
V_612 = F_376 ( V_716 -> V_31 , V_827 -> V_829 , & V_264 ) ;
if ( V_612 ) {
if ( V_612 == - V_98 ) {
F_377 ( L_47
L_48
L_49 ,
V_714 -> V_744 , V_827 -> V_829 ,
V_830 [ V_716 -> V_31 - 1 ] . V_73 ,
F_378 ( V_11 ) , V_11 -> V_831 ) ;
if ( ! V_3 || F_379 () )
V_612 = 0 ;
}
if ( V_612 == - V_832 )
V_612 = 0 ;
goto V_82;
}
V_612 = F_314 ( V_11 , V_714 , V_264 ) ;
V_82:
return V_612 ;
}
static unsigned int F_380 ( struct V_663 * V_664 ,
const struct V_833 * V_834 ,
T_4 V_195 )
{
int V_612 ;
char * V_700 ;
T_2 V_775 ;
struct V_288 V_289 ;
struct V_718 V_672 = { 0 ,} ;
T_11 V_791 ;
T_11 V_835 ;
T_11 V_792 ;
if ( ! V_794 )
return V_836 ;
V_791 = F_4 () ;
V_835 = F_7 () ;
V_792 = F_6 () ;
if ( ! V_791 && ! V_792 )
return V_836 ;
if ( F_307 ( V_664 , V_195 , & V_775 ) != 0 )
return V_837 ;
V_289 . type = V_719 ;
V_289 . V_294 . V_672 = & V_672 ;
V_289 . V_294 . V_672 -> V_786 = V_834 -> V_779 ;
V_289 . V_294 . V_672 -> V_195 = V_195 ;
if ( F_306 ( V_664 , & V_289 , & V_700 , 1 , NULL ) != 0 )
return V_837 ;
if ( V_792 ) {
V_612 = F_339 ( F_381 ( V_834 ) , V_834 -> V_779 ,
V_700 , V_195 , V_775 , & V_289 ) ;
if ( V_612 ) {
F_345 ( V_664 , V_195 , V_612 , 1 ) ;
return V_837 ;
}
}
if ( V_791 )
if ( F_55 ( V_775 , V_664 -> V_788 ,
V_789 , V_838 , & V_289 ) )
return V_837 ;
if ( V_835 )
if ( F_382 ( V_664 , V_195 , V_775 ) != 0 )
return V_837 ;
return V_836 ;
}
static unsigned int F_383 ( void * V_839 ,
struct V_663 * V_664 ,
const struct V_840 * V_841 )
{
return F_380 ( V_664 , V_841 -> V_842 , V_202 ) ;
}
static unsigned int F_384 ( void * V_839 ,
struct V_663 * V_664 ,
const struct V_840 * V_841 )
{
return F_380 ( V_664 , V_841 -> V_842 , V_203 ) ;
}
static unsigned int F_385 ( struct V_663 * V_664 ,
T_4 V_195 )
{
struct V_713 * V_714 ;
T_2 V_17 ;
if ( ! F_7 () )
return V_836 ;
V_714 = V_664 -> V_714 ;
if ( V_714 ) {
struct V_715 * V_716 ;
if ( F_386 ( V_714 ) )
return V_836 ;
V_716 = V_714 -> V_717 ;
V_17 = V_716 -> V_17 ;
} else
V_17 = V_18 ;
if ( F_382 ( V_664 , V_195 , V_17 ) != 0 )
return V_837 ;
return V_836 ;
}
static unsigned int F_387 ( void * V_839 ,
struct V_663 * V_664 ,
const struct V_840 * V_841 )
{
return F_385 ( V_664 , V_202 ) ;
}
static unsigned int F_388 ( void * V_839 ,
struct V_663 * V_664 ,
const struct V_840 * V_841 )
{
return F_385 ( V_664 , V_203 ) ;
}
static unsigned int F_389 ( struct V_663 * V_664 ,
int V_779 ,
T_4 V_195 )
{
struct V_713 * V_714 = F_390 ( V_664 ) ;
struct V_715 * V_716 ;
struct V_288 V_289 ;
struct V_718 V_672 = { 0 ,} ;
char * V_700 ;
T_11 V_665 ;
if ( V_714 == NULL )
return V_836 ;
V_716 = V_714 -> V_717 ;
V_289 . type = V_719 ;
V_289 . V_294 . V_672 = & V_672 ;
V_289 . V_294 . V_672 -> V_786 = V_779 ;
V_289 . V_294 . V_672 -> V_195 = V_195 ;
if ( F_306 ( V_664 , & V_289 , & V_700 , 0 , & V_665 ) )
return V_837 ;
if ( F_4 () )
if ( F_55 ( V_716 -> V_17 , V_664 -> V_788 ,
V_789 , V_843 , & V_289 ) )
return F_391 ( - V_844 ) ;
if ( F_392 ( V_716 -> V_17 , V_664 , & V_289 , V_665 ) )
return F_391 ( - V_844 ) ;
return V_836 ;
}
static unsigned int F_393 ( struct V_663 * V_664 ,
const struct V_833 * V_845 ,
T_4 V_195 )
{
T_2 V_846 ;
T_2 V_775 ;
int V_779 = V_845 -> V_779 ;
struct V_713 * V_714 ;
struct V_288 V_289 ;
struct V_718 V_672 = { 0 ,} ;
char * V_700 ;
T_11 V_791 ;
T_11 V_792 ;
if ( ! V_794 )
return F_389 ( V_664 , V_779 , V_195 ) ;
V_791 = F_4 () ;
V_792 = F_6 () ;
if ( ! V_791 && ! V_792 )
return V_836 ;
V_714 = F_390 ( V_664 ) ;
#ifdef F_394
if ( F_395 ( V_664 ) != NULL && F_395 ( V_664 ) -> V_847 != NULL &&
! ( V_714 && F_386 ( V_714 ) ) )
return V_836 ;
#endif
if ( V_714 == NULL ) {
if ( V_664 -> V_787 ) {
V_846 = V_848 ;
if ( F_307 ( V_664 , V_195 , & V_775 ) )
return V_837 ;
} else {
V_846 = V_843 ;
V_775 = V_18 ;
}
} else if ( F_386 ( V_714 ) ) {
T_2 V_708 ;
struct V_715 * V_716 ;
V_716 = V_714 -> V_717 ;
if ( F_307 ( V_664 , V_195 , & V_708 ) )
return V_837 ;
if ( V_708 == V_710 ) {
switch ( V_195 ) {
case V_202 :
if ( F_396 ( V_664 ) -> V_87 & V_849 )
return V_836 ;
break;
case V_203 :
if ( F_397 ( V_664 ) -> V_87 & V_850 )
return V_836 ;
break;
default:
return F_391 ( - V_844 ) ;
}
}
if ( F_311 ( V_716 -> V_17 , V_708 , & V_775 ) )
return V_837 ;
V_846 = V_843 ;
} else {
struct V_715 * V_716 = V_714 -> V_717 ;
V_775 = V_716 -> V_17 ;
V_846 = V_843 ;
}
V_289 . type = V_719 ;
V_289 . V_294 . V_672 = & V_672 ;
V_289 . V_294 . V_672 -> V_786 = V_779 ;
V_289 . V_294 . V_672 -> V_195 = V_195 ;
if ( F_306 ( V_664 , & V_289 , & V_700 , 0 , NULL ) )
return V_837 ;
if ( V_791 )
if ( F_55 ( V_775 , V_664 -> V_788 ,
V_789 , V_846 , & V_289 ) )
return F_391 ( - V_844 ) ;
if ( V_792 ) {
T_2 V_780 ;
T_2 V_781 ;
if ( F_340 ( F_381 ( V_845 ) , V_779 , & V_780 ) )
return V_837 ;
if ( F_55 ( V_775 , V_780 ,
V_782 , V_851 , & V_289 ) )
return F_391 ( - V_844 ) ;
if ( F_324 ( V_700 , V_195 , & V_781 ) )
return V_837 ;
if ( F_55 ( V_775 , V_781 ,
V_784 , V_852 , & V_289 ) )
return F_391 ( - V_844 ) ;
}
return V_836 ;
}
static unsigned int F_398 ( void * V_839 ,
struct V_663 * V_664 ,
const struct V_840 * V_841 )
{
return F_393 ( V_664 , V_841 -> V_82 , V_202 ) ;
}
static unsigned int F_399 ( void * V_839 ,
struct V_663 * V_664 ,
const struct V_840 * V_841 )
{
return F_393 ( V_664 , V_841 -> V_82 , V_203 ) ;
}
static int F_400 ( struct V_713 * V_714 , struct V_663 * V_664 )
{
return F_374 ( V_714 , V_664 ) ;
}
static int F_401 ( struct V_20 * V_21 ,
struct V_853 * V_264 ,
T_4 V_31 )
{
struct V_854 * V_24 ;
T_2 V_17 ;
V_24 = F_15 ( sizeof( struct V_854 ) , V_15 ) ;
if ( ! V_24 )
return - V_27 ;
V_17 = F_18 ( V_21 ) ;
V_24 -> V_31 = V_31 ;
V_24 -> V_17 = V_17 ;
V_264 -> V_19 = V_24 ;
return 0 ;
}
static void F_402 ( struct V_853 * V_264 )
{
struct V_854 * V_24 = V_264 -> V_19 ;
V_264 -> V_19 = NULL ;
F_52 ( V_24 ) ;
}
static int F_403 ( struct V_855 * V_759 )
{
struct V_856 * V_857 ;
V_857 = F_15 ( sizeof( struct V_856 ) , V_15 ) ;
if ( ! V_857 )
return - V_27 ;
V_857 -> V_17 = V_30 ;
V_759 -> V_19 = V_857 ;
return 0 ;
}
static void F_404 ( struct V_855 * V_759 )
{
struct V_856 * V_857 = V_759 -> V_19 ;
V_759 -> V_19 = NULL ;
F_52 ( V_857 ) ;
}
static int F_405 ( struct V_853 * V_858 ,
T_2 V_274 )
{
struct V_854 * V_24 ;
struct V_288 V_289 ;
T_2 V_17 = F_22 () ;
V_24 = V_858 -> V_19 ;
V_289 . type = V_859 ;
V_289 . V_294 . V_860 = V_858 -> V_861 ;
return F_55 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_274 , & V_289 ) ;
}
static int F_406 ( struct V_855 * V_759 )
{
return F_403 ( V_759 ) ;
}
static void F_407 ( struct V_855 * V_759 )
{
F_404 ( V_759 ) ;
}
static int F_408 ( struct V_862 * V_863 )
{
struct V_854 * V_24 ;
struct V_288 V_289 ;
T_2 V_17 = F_22 () ;
int V_62 ;
V_62 = F_401 ( V_11 , & V_863 -> V_864 , V_865 ) ;
if ( V_62 )
return V_62 ;
V_24 = V_863 -> V_864 . V_19 ;
V_289 . type = V_859 ;
V_289 . V_294 . V_860 = V_863 -> V_864 . V_861 ;
V_62 = F_55 ( V_17 , V_24 -> V_17 , V_865 ,
V_866 , & V_289 ) ;
if ( V_62 ) {
F_402 ( & V_863 -> V_864 ) ;
return V_62 ;
}
return 0 ;
}
static void F_409 ( struct V_862 * V_863 )
{
F_402 ( & V_863 -> V_864 ) ;
}
static int F_410 ( struct V_862 * V_863 , int V_867 )
{
struct V_854 * V_24 ;
struct V_288 V_289 ;
T_2 V_17 = F_22 () ;
V_24 = V_863 -> V_864 . V_19 ;
V_289 . type = V_859 ;
V_289 . V_294 . V_860 = V_863 -> V_864 . V_861 ;
return F_55 ( V_17 , V_24 -> V_17 , V_865 ,
V_868 , & V_289 ) ;
}
static int F_411 ( struct V_862 * V_863 , int V_560 )
{
int V_612 ;
int V_274 ;
switch ( V_560 ) {
case V_869 :
case V_870 :
return F_124 ( V_11 , V_871 ) ;
case V_872 :
case V_873 :
V_274 = V_874 | V_868 ;
break;
case V_875 :
V_274 = V_876 ;
break;
case V_877 :
V_274 = V_878 ;
break;
default:
return 0 ;
}
V_612 = F_405 ( & V_863 -> V_864 , V_274 ) ;
return V_612 ;
}
static int F_412 ( struct V_862 * V_863 , struct V_855 * V_759 , int V_867 )
{
struct V_854 * V_24 ;
struct V_856 * V_857 ;
struct V_288 V_289 ;
T_2 V_17 = F_22 () ;
int V_62 ;
V_24 = V_863 -> V_864 . V_19 ;
V_857 = V_759 -> V_19 ;
if ( V_857 -> V_17 == V_30 ) {
V_62 = F_80 ( V_17 , V_24 -> V_17 , V_879 ,
NULL , & V_857 -> V_17 ) ;
if ( V_62 )
return V_62 ;
}
V_289 . type = V_859 ;
V_289 . V_294 . V_860 = V_863 -> V_864 . V_861 ;
V_62 = F_55 ( V_17 , V_24 -> V_17 , V_865 ,
V_880 , & V_289 ) ;
if ( ! V_62 )
V_62 = F_55 ( V_17 , V_857 -> V_17 , V_879 ,
V_881 , & V_289 ) ;
if ( ! V_62 )
V_62 = F_55 ( V_857 -> V_17 , V_24 -> V_17 , V_865 ,
V_882 , & V_289 ) ;
return V_62 ;
}
static int F_413 ( struct V_862 * V_863 , struct V_855 * V_759 ,
struct V_20 * V_273 ,
long type , int V_176 )
{
struct V_854 * V_24 ;
struct V_856 * V_857 ;
struct V_288 V_289 ;
T_2 V_17 = F_18 ( V_273 ) ;
int V_62 ;
V_24 = V_863 -> V_864 . V_19 ;
V_857 = V_759 -> V_19 ;
V_289 . type = V_859 ;
V_289 . V_294 . V_860 = V_863 -> V_864 . V_861 ;
V_62 = F_55 ( V_17 , V_24 -> V_17 ,
V_865 , V_883 , & V_289 ) ;
if ( ! V_62 )
V_62 = F_55 ( V_17 , V_857 -> V_17 ,
V_879 , V_884 , & V_289 ) ;
return V_62 ;
}
static int F_414 ( struct V_885 * V_886 )
{
struct V_854 * V_24 ;
struct V_288 V_289 ;
T_2 V_17 = F_22 () ;
int V_62 ;
V_62 = F_401 ( V_11 , & V_886 -> V_887 , V_888 ) ;
if ( V_62 )
return V_62 ;
V_24 = V_886 -> V_887 . V_19 ;
V_289 . type = V_859 ;
V_289 . V_294 . V_860 = V_886 -> V_887 . V_861 ;
V_62 = F_55 ( V_17 , V_24 -> V_17 , V_888 ,
V_889 , & V_289 ) ;
if ( V_62 ) {
F_402 ( & V_886 -> V_887 ) ;
return V_62 ;
}
return 0 ;
}
static void F_415 ( struct V_885 * V_886 )
{
F_402 ( & V_886 -> V_887 ) ;
}
static int F_416 ( struct V_885 * V_886 , int V_890 )
{
struct V_854 * V_24 ;
struct V_288 V_289 ;
T_2 V_17 = F_22 () ;
V_24 = V_886 -> V_887 . V_19 ;
V_289 . type = V_859 ;
V_289 . V_294 . V_860 = V_886 -> V_887 . V_861 ;
return F_55 ( V_17 , V_24 -> V_17 , V_888 ,
V_891 , & V_289 ) ;
}
static int F_417 ( struct V_885 * V_886 , int V_560 )
{
int V_274 ;
int V_612 ;
switch ( V_560 ) {
case V_869 :
case V_892 :
return F_124 ( V_11 , V_871 ) ;
case V_872 :
case V_893 :
V_274 = V_894 | V_891 ;
break;
case V_875 :
V_274 = V_895 ;
break;
case V_896 :
case V_897 :
V_274 = V_898 ;
break;
case V_877 :
V_274 = V_899 ;
break;
default:
return 0 ;
}
V_612 = F_405 ( & V_886 -> V_887 , V_274 ) ;
return V_612 ;
}
static int F_418 ( struct V_885 * V_886 ,
char T_15 * V_900 , int V_890 )
{
T_2 V_274 ;
if ( V_890 & V_901 )
V_274 = V_902 ;
else
V_274 = V_902 | V_903 ;
return F_405 ( & V_886 -> V_887 , V_274 ) ;
}
static int F_419 ( struct V_904 * V_905 )
{
struct V_854 * V_24 ;
struct V_288 V_289 ;
T_2 V_17 = F_22 () ;
int V_62 ;
V_62 = F_401 ( V_11 , & V_905 -> V_906 , V_907 ) ;
if ( V_62 )
return V_62 ;
V_24 = V_905 -> V_906 . V_19 ;
V_289 . type = V_859 ;
V_289 . V_294 . V_860 = V_905 -> V_906 . V_861 ;
V_62 = F_55 ( V_17 , V_24 -> V_17 , V_907 ,
V_908 , & V_289 ) ;
if ( V_62 ) {
F_402 ( & V_905 -> V_906 ) ;
return V_62 ;
}
return 0 ;
}
static void F_420 ( struct V_904 * V_905 )
{
F_402 ( & V_905 -> V_906 ) ;
}
static int F_421 ( struct V_904 * V_905 , int V_909 )
{
struct V_854 * V_24 ;
struct V_288 V_289 ;
T_2 V_17 = F_22 () ;
V_24 = V_905 -> V_906 . V_19 ;
V_289 . type = V_859 ;
V_289 . V_294 . V_860 = V_905 -> V_906 . V_861 ;
return F_55 ( V_17 , V_24 -> V_17 , V_907 ,
V_910 , & V_289 ) ;
}
static int F_422 ( struct V_904 * V_905 , int V_560 )
{
int V_612 ;
T_2 V_274 ;
switch ( V_560 ) {
case V_869 :
case V_911 :
return F_124 ( V_11 , V_871 ) ;
case V_912 :
case V_913 :
case V_914 :
V_274 = V_915 ;
break;
case V_916 :
case V_917 :
V_274 = V_918 ;
break;
case V_919 :
case V_920 :
V_274 = V_921 ;
break;
case V_877 :
V_274 = V_922 ;
break;
case V_875 :
V_274 = V_923 ;
break;
case V_872 :
case V_924 :
V_274 = V_915 | V_910 ;
break;
default:
return 0 ;
}
V_612 = F_405 ( & V_905 -> V_906 , V_274 ) ;
return V_612 ;
}
static int F_423 ( struct V_904 * V_905 ,
struct V_925 * V_926 , unsigned V_927 , int V_928 )
{
T_2 V_274 ;
if ( V_928 )
V_274 = V_918 | V_921 ;
else
V_274 = V_918 ;
return F_405 ( & V_905 -> V_906 , V_274 ) ;
}
static int F_424 ( struct V_853 * V_929 , short V_110 )
{
T_2 V_292 = 0 ;
V_292 = 0 ;
if ( V_110 & V_930 )
V_292 |= V_931 ;
if ( V_110 & V_932 )
V_292 |= V_933 ;
if ( V_292 == 0 )
return 0 ;
return F_405 ( V_929 , V_292 ) ;
}
static void F_425 ( struct V_853 * V_929 , T_2 * V_554 )
{
struct V_854 * V_24 = V_929 -> V_19 ;
* V_554 = V_24 -> V_17 ;
}
static void F_426 ( struct V_36 * V_36 , struct V_22 * V_22 )
{
if ( V_22 )
F_30 ( V_22 , V_36 ) ;
}
static int F_427 ( struct V_20 * V_153 ,
char * V_73 , char * * V_511 )
{
const struct V_13 * V_814 ;
T_2 V_17 ;
int error ;
unsigned V_96 ;
if ( V_11 != V_153 ) {
error = F_118 ( V_153 , V_934 ) ;
if ( error )
return error ;
}
F_19 () ;
V_814 = F_20 ( V_153 ) -> V_19 ;
if ( ! strcmp ( V_73 , L_50 ) )
V_17 = V_814 -> V_17 ;
else if ( ! strcmp ( V_73 , L_51 ) )
V_17 = V_814 -> V_16 ;
else if ( ! strcmp ( V_73 , L_52 ) )
V_17 = V_814 -> V_432 ;
else if ( ! strcmp ( V_73 , L_53 ) )
V_17 = V_814 -> V_311 ;
else if ( ! strcmp ( V_73 , L_54 ) )
V_17 = V_814 -> V_430 ;
else if ( ! strcmp ( V_73 , L_55 ) )
V_17 = V_814 -> V_431 ;
else
goto V_935;
F_21 () ;
if ( ! V_17 )
return 0 ;
error = F_71 ( V_17 , V_511 , & V_96 ) ;
if ( error )
return error ;
return V_96 ;
V_935:
F_21 () ;
return - V_98 ;
}
static int F_428 ( struct V_20 * V_153 ,
char * V_73 , void * V_511 , T_7 V_542 )
{
struct V_13 * V_14 ;
struct V_10 * V_138 ;
T_2 V_17 = 0 , V_440 ;
int error ;
char * V_1 = V_511 ;
if ( V_11 != V_153 ) {
return - V_131 ;
}
if ( ! strcmp ( V_73 , L_52 ) )
error = F_118 ( V_153 , V_936 ) ;
else if ( ! strcmp ( V_73 , L_53 ) )
error = F_118 ( V_153 , V_937 ) ;
else if ( ! strcmp ( V_73 , L_54 ) )
error = F_118 ( V_153 , V_938 ) ;
else if ( ! strcmp ( V_73 , L_55 ) )
error = F_118 ( V_153 , V_939 ) ;
else if ( ! strcmp ( V_73 , L_50 ) )
error = F_118 ( V_153 , V_940 ) ;
else
error = - V_98 ;
if ( error )
return error ;
if ( V_542 && V_1 [ 0 ] && V_1 [ 0 ] != '\n' ) {
if ( V_1 [ V_542 - 1 ] == '\n' ) {
V_1 [ V_542 - 1 ] = 0 ;
V_542 -- ;
}
error = F_237 ( V_511 , V_542 , & V_17 , V_15 ) ;
if ( error == - V_98 && ! strcmp ( V_73 , L_53 ) ) {
if ( ! F_234 ( V_544 ) ) {
struct V_545 * V_546 ;
T_7 V_547 ;
if ( V_1 [ V_542 - 1 ] == '\0' )
V_547 = V_542 - 1 ;
else
V_547 = V_542 ;
V_546 = F_238 ( V_11 -> V_548 , V_103 , V_549 ) ;
F_239 ( V_546 , L_56 ) ;
F_240 ( V_546 , V_511 , V_547 ) ;
F_241 ( V_546 ) ;
return error ;
}
error = F_242 ( V_511 , V_542 ,
& V_17 ) ;
}
if ( error )
return error ;
}
V_138 = F_254 () ;
if ( ! V_138 )
return - V_27 ;
V_14 = V_138 -> V_19 ;
if ( ! strcmp ( V_73 , L_52 ) ) {
V_14 -> V_432 = V_17 ;
} else if ( ! strcmp ( V_73 , L_53 ) ) {
V_14 -> V_311 = V_17 ;
} else if ( ! strcmp ( V_73 , L_54 ) ) {
error = F_135 ( V_17 , V_153 ) ;
if ( error )
goto V_941;
V_14 -> V_430 = V_17 ;
} else if ( ! strcmp ( V_73 , L_55 ) ) {
V_14 -> V_431 = V_17 ;
} else if ( ! strcmp ( V_73 , L_50 ) ) {
error = - V_98 ;
if ( V_17 == 0 )
goto V_941;
error = - V_428 ;
if ( ! F_429 () ) {
error = F_162 ( V_14 -> V_17 , V_17 ) ;
if ( error )
goto V_941;
}
error = F_55 ( V_14 -> V_17 , V_17 , V_277 ,
V_942 , NULL ) ;
if ( error )
goto V_941;
V_440 = F_158 ( V_153 ) ;
if ( V_440 != 0 ) {
error = F_55 ( V_440 , V_17 , V_277 ,
V_377 , NULL ) ;
if ( error )
goto V_941;
}
V_14 -> V_17 = V_17 ;
} else {
error = - V_98 ;
goto V_941;
}
F_430 ( V_138 ) ;
return V_542 ;
V_941:
F_431 ( V_138 ) ;
return error ;
}
static int F_432 ( const char * V_73 )
{
return ( strcmp ( V_73 , V_513 ) == 0 ) ;
}
static int F_433 ( T_2 V_554 , char * * V_495 , T_2 * V_943 )
{
return F_71 ( V_554 , V_495 , V_943 ) ;
}
static int F_434 ( const char * V_495 , T_2 V_943 , T_2 * V_554 )
{
return F_237 ( V_495 , V_943 , V_554 , V_15 ) ;
}
static void F_435 ( char * V_495 , T_2 V_943 )
{
F_52 ( V_495 ) ;
}
static void F_436 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_35 ;
F_43 ( & V_24 -> V_28 ) ;
V_24 -> V_33 = V_34 ;
F_45 ( & V_24 -> V_28 ) ;
}
static int F_437 ( struct V_22 * V_22 , void * V_319 , T_2 V_509 )
{
return F_250 ( V_22 , V_513 , V_319 , V_509 , 0 ) ;
}
static int F_438 ( struct V_36 * V_36 , void * V_319 , T_2 V_509 )
{
return F_439 ( V_36 , V_83 , V_319 , V_509 , 0 ) ;
}
static int F_440 ( struct V_22 * V_22 , void * * V_319 , T_2 * V_509 )
{
int V_96 = 0 ;
V_96 = F_248 ( V_22 , V_513 ,
V_319 , true ) ;
if ( V_96 < 0 )
return V_96 ;
* V_509 = V_96 ;
return 0 ;
}
static int F_441 ( struct V_861 * V_944 , const struct V_10 * V_10 ,
unsigned long V_87 )
{
const struct V_13 * V_14 ;
struct V_945 * V_946 ;
V_946 = F_15 ( sizeof( struct V_945 ) , V_15 ) ;
if ( ! V_946 )
return - V_27 ;
V_14 = V_10 -> V_19 ;
if ( V_14 -> V_430 )
V_946 -> V_17 = V_14 -> V_430 ;
else
V_946 -> V_17 = V_14 -> V_17 ;
V_944 -> V_19 = V_946 ;
return 0 ;
}
static void F_442 ( struct V_861 * V_944 )
{
struct V_945 * V_946 = V_944 -> V_19 ;
V_944 -> V_19 = NULL ;
F_52 ( V_946 ) ;
}
static int F_443 ( T_16 V_947 ,
const struct V_10 * V_10 ,
unsigned V_264 )
{
struct V_861 * V_861 ;
struct V_945 * V_946 ;
T_2 V_17 ;
if ( V_264 == 0 )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_861 = F_444 ( V_947 ) ;
V_946 = V_861 -> V_19 ;
return F_55 ( V_17 , V_946 -> V_17 , V_320 , V_264 , NULL ) ;
}
static int F_445 ( struct V_861 * V_861 , char * * V_948 )
{
struct V_945 * V_946 = V_861 -> V_19 ;
char * V_95 = NULL ;
unsigned V_96 ;
int V_62 ;
V_62 = F_71 ( V_946 -> V_17 , & V_95 , & V_96 ) ;
if ( ! V_62 )
V_62 = V_96 ;
* V_948 = V_95 ;
return V_62 ;
}
static T_1 int F_446 ( void )
{
if ( ! F_447 ( L_57 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_59 ( V_949 L_58 ) ;
return 0 ;
}
F_59 ( V_949 L_59 ) ;
F_14 () ;
V_583 = ! ( V_950 & V_598 ) ;
V_25 = F_448 ( L_60 ,
sizeof( struct V_23 ) ,
0 , V_951 , NULL ) ;
V_53 = F_448 ( L_61 ,
sizeof( struct V_51 ) ,
0 , V_951 , NULL ) ;
F_449 () ;
F_450 ( V_952 , F_61 ( V_952 ) ) ;
if ( F_451 ( F_9 , V_9 ) )
F_16 ( L_62 ) ;
if ( V_3 )
F_59 ( V_953 L_63 ) ;
else
F_59 ( V_953 L_64 ) ;
return 0 ;
}
static void F_452 ( struct V_56 * V_57 , void * V_954 )
{
F_88 ( V_57 , NULL ) ;
}
void F_453 ( void )
{
F_59 ( V_953 L_65 ) ;
F_59 ( V_953 L_66 ) ;
F_454 ( F_452 , NULL ) ;
}
static int T_1 F_455 ( void )
{
int V_612 ;
if ( ! V_5 )
return 0 ;
F_59 ( V_953 L_67 ) ;
V_612 = F_456 ( V_955 , F_61 ( V_955 ) ) ;
if ( V_612 )
F_16 ( L_68 , V_612 ) ;
return 0 ;
}
static void F_457 ( void )
{
F_59 ( V_953 L_69 ) ;
F_458 ( V_955 , F_61 ( V_955 ) ) ;
}
int F_459 ( void )
{
if ( V_39 ) {
return - V_98 ;
}
if ( V_956 ) {
return - V_98 ;
}
F_59 ( V_949 L_70 ) ;
V_956 = 1 ;
V_5 = 0 ;
F_460 ( V_952 , F_61 ( V_952 ) ) ;
F_461 () ;
F_457 () ;
F_462 () ;
return 0 ;
}
