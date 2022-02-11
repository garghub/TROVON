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
static void F_28 ( struct V_34 * V_35 )
{
struct V_23 * V_24 ;
V_24 = F_29 ( V_35 , struct V_23 , V_36 ) ;
F_30 ( V_25 , V_24 ) ;
}
static void F_31 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_37 * V_38 = V_22 -> V_39 -> V_40 ;
F_32 ( & V_38 -> V_41 ) ;
if ( ! F_33 ( & V_24 -> V_29 ) )
F_34 ( & V_24 -> V_29 ) ;
F_35 ( & V_38 -> V_41 ) ;
F_36 ( & V_24 -> V_36 , F_28 ) ;
}
static int F_37 ( struct V_42 * V_42 )
{
struct V_43 * V_44 ;
T_2 V_17 = F_22 () ;
V_44 = F_15 ( sizeof( struct V_43 ) , V_15 ) ;
if ( ! V_44 )
return - V_27 ;
V_44 -> V_17 = V_17 ;
V_44 -> V_45 = V_17 ;
V_42 -> V_46 = V_44 ;
return 0 ;
}
static void F_38 ( struct V_42 * V_42 )
{
struct V_43 * V_44 = V_42 -> V_46 ;
V_42 -> V_46 = NULL ;
F_39 ( V_44 ) ;
}
static int F_40 ( struct V_47 * V_48 )
{
struct V_37 * V_38 ;
V_38 = F_15 ( sizeof( struct V_37 ) , V_15 ) ;
if ( ! V_38 )
return - V_27 ;
F_26 ( & V_38 -> V_28 ) ;
F_27 ( & V_38 -> V_49 ) ;
F_41 ( & V_38 -> V_41 ) ;
V_38 -> V_48 = V_48 ;
V_38 -> V_17 = V_30 ;
V_38 -> V_50 = V_51 ;
V_38 -> V_52 = V_30 ;
V_48 -> V_40 = V_38 ;
return 0 ;
}
static void F_42 ( struct V_47 * V_48 )
{
struct V_37 * V_38 = V_48 -> V_40 ;
V_48 -> V_40 = NULL ;
F_39 ( V_38 ) ;
}
static inline int F_43 ( struct V_22 * V_22 )
{
return F_44 ( V_22 , NULL ) ;
}
static int F_45 ( T_2 V_17 ,
struct V_37 * V_38 ,
const struct V_10 * V_10 )
{
const struct V_13 * V_14 = V_10 -> V_19 ;
int V_53 ;
V_53 = F_46 ( V_14 -> V_17 , V_38 -> V_17 , V_54 ,
V_55 , NULL ) ;
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_14 -> V_17 , V_17 , V_54 ,
V_56 , NULL ) ;
return V_53 ;
}
static int F_47 ( T_2 V_17 ,
struct V_37 * V_38 ,
const struct V_10 * V_10 )
{
const struct V_13 * V_14 = V_10 -> V_19 ;
int V_53 ;
V_53 = F_46 ( V_14 -> V_17 , V_38 -> V_17 , V_54 ,
V_55 , NULL ) ;
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_17 , V_38 -> V_17 , V_54 ,
V_57 , NULL ) ;
return V_53 ;
}
static int F_48 ( struct V_47 * V_48 )
{
struct V_37 * V_38 = V_48 -> V_40 ;
return V_38 -> V_58 == V_59 ||
V_38 -> V_58 == V_60 ||
V_38 -> V_58 == V_61 ||
! strcmp ( V_48 -> V_62 -> V_63 , L_2 ) ||
! strcmp ( V_48 -> V_62 -> V_63 , L_3 ) ||
! strcmp ( V_48 -> V_62 -> V_63 , L_4 ) ||
! strcmp ( V_48 -> V_62 -> V_63 , L_5 ) ;
}
static int F_49 ( struct V_47 * V_48 )
{
struct V_37 * V_38 = V_48 -> V_40 ;
struct V_64 * V_65 = V_48 -> V_66 ;
struct V_22 * V_67 = V_65 -> V_68 ;
int V_53 = 0 ;
if ( V_38 -> V_58 == V_59 ) {
if ( ! V_67 -> V_69 -> V_70 ) {
F_50 ( V_71 L_6
L_7 , V_48 -> V_72 , V_48 -> V_62 -> V_63 ) ;
V_53 = - V_73 ;
goto V_74;
}
V_53 = V_67 -> V_69 -> V_70 ( V_65 , V_75 , NULL , 0 ) ;
if ( V_53 < 0 && V_53 != - V_76 ) {
if ( V_53 == - V_73 )
F_50 ( V_71 L_8
L_9 ,
V_48 -> V_72 , V_48 -> V_62 -> V_63 ) ;
else
F_50 ( V_71 L_8
L_10 , V_48 -> V_72 ,
V_48 -> V_62 -> V_63 , - V_53 ) ;
goto V_74;
}
}
if ( V_38 -> V_58 > F_51 ( V_77 ) )
F_50 ( V_78 L_11 ,
V_48 -> V_72 , V_48 -> V_62 -> V_63 ) ;
V_38 -> V_79 |= V_80 ;
if ( F_48 ( V_48 ) )
V_38 -> V_79 |= V_81 ;
V_53 = F_44 ( V_67 , V_65 ) ;
F_32 ( & V_38 -> V_41 ) ;
V_82:
if ( ! F_33 ( & V_38 -> V_49 ) ) {
struct V_23 * V_24 =
F_52 ( V_38 -> V_49 . V_83 ,
struct V_23 , V_29 ) ;
struct V_22 * V_22 = V_24 -> V_22 ;
F_34 ( & V_24 -> V_29 ) ;
F_35 ( & V_38 -> V_41 ) ;
V_22 = F_53 ( V_22 ) ;
if ( V_22 ) {
if ( ! F_54 ( V_22 ) )
F_43 ( V_22 ) ;
F_55 ( V_22 ) ;
}
F_32 ( & V_38 -> V_41 ) ;
goto V_82;
}
F_35 ( & V_38 -> V_41 ) ;
V_74:
return V_53 ;
}
static int F_56 ( const struct V_47 * V_48 ,
struct V_84 * V_85 )
{
int V_53 = 0 , V_86 ;
struct V_37 * V_38 = V_48 -> V_40 ;
char * V_87 = NULL ;
T_2 V_88 ;
char V_89 ;
F_57 ( V_85 ) ;
if ( ! ( V_38 -> V_79 & V_80 ) )
return - V_90 ;
if ( ! V_91 )
return - V_90 ;
F_58 ( V_92 >= ( 1 << V_93 ) ) ;
V_89 = V_38 -> V_79 & V_92 ;
for ( V_86 = 0 ; V_86 < V_93 ; V_86 ++ ) {
if ( V_89 & 0x01 )
V_85 -> V_94 ++ ;
V_89 >>= 1 ;
}
if ( V_38 -> V_79 & V_81 )
V_85 -> V_94 ++ ;
V_85 -> V_95 = F_59 ( V_85 -> V_94 , sizeof( char * ) , V_96 ) ;
if ( ! V_85 -> V_95 ) {
V_53 = - V_27 ;
goto V_97;
}
V_85 -> V_98 = F_59 ( V_85 -> V_94 , sizeof( int ) , V_96 ) ;
if ( ! V_85 -> V_98 ) {
V_53 = - V_27 ;
goto V_97;
}
V_86 = 0 ;
if ( V_38 -> V_79 & V_99 ) {
V_53 = F_60 ( V_38 -> V_17 , & V_87 , & V_88 ) ;
if ( V_53 )
goto V_97;
V_85 -> V_95 [ V_86 ] = V_87 ;
V_85 -> V_98 [ V_86 ++ ] = V_99 ;
}
if ( V_38 -> V_79 & V_100 ) {
V_53 = F_60 ( V_38 -> V_52 , & V_87 , & V_88 ) ;
if ( V_53 )
goto V_97;
V_85 -> V_95 [ V_86 ] = V_87 ;
V_85 -> V_98 [ V_86 ++ ] = V_100 ;
}
if ( V_38 -> V_79 & V_101 ) {
V_53 = F_60 ( V_38 -> V_50 , & V_87 , & V_88 ) ;
if ( V_53 )
goto V_97;
V_85 -> V_95 [ V_86 ] = V_87 ;
V_85 -> V_98 [ V_86 ++ ] = V_101 ;
}
if ( V_38 -> V_79 & V_102 ) {
struct V_22 * V_65 = V_38 -> V_48 -> V_66 -> V_68 ;
struct V_23 * V_24 = V_65 -> V_33 ;
V_53 = F_60 ( V_24 -> V_17 , & V_87 , & V_88 ) ;
if ( V_53 )
goto V_97;
V_85 -> V_95 [ V_86 ] = V_87 ;
V_85 -> V_98 [ V_86 ++ ] = V_102 ;
}
if ( V_38 -> V_79 & V_81 ) {
V_85 -> V_95 [ V_86 ] = NULL ;
V_85 -> V_98 [ V_86 ++ ] = V_81 ;
}
F_61 ( V_86 != V_85 -> V_94 ) ;
return 0 ;
V_97:
F_62 ( V_85 ) ;
return V_53 ;
}
static int F_63 ( struct V_37 * V_38 , char V_103 ,
T_2 V_104 , T_2 V_105 )
{
char V_106 = V_38 -> V_79 & V_92 ;
if ( V_38 -> V_79 & V_80 )
if ( ! ( V_38 -> V_79 & V_103 ) ||
( V_104 != V_105 ) )
return 1 ;
if ( ! ( V_38 -> V_79 & V_80 ) )
if ( V_106 & V_103 )
return 1 ;
return 0 ;
}
static int F_64 ( struct V_47 * V_48 ,
struct V_84 * V_85 ,
unsigned long V_107 ,
unsigned long * V_108 )
{
const struct V_10 * V_10 = F_65 () ;
int V_53 = 0 , V_86 ;
struct V_37 * V_38 = V_48 -> V_40 ;
const char * V_63 = V_48 -> V_62 -> V_63 ;
struct V_22 * V_22 = V_38 -> V_48 -> V_66 -> V_68 ;
struct V_23 * V_109 = V_22 -> V_33 ;
T_2 V_110 = 0 , V_111 = 0 , V_112 = 0 ;
T_2 V_113 = 0 ;
char * * V_114 = V_85 -> V_95 ;
int * V_79 = V_85 -> V_98 ;
int V_115 = V_85 -> V_94 ;
F_66 ( & V_38 -> V_28 ) ;
if ( ! V_91 ) {
if ( ! V_115 ) {
goto V_74;
}
V_53 = - V_90 ;
F_50 ( V_71 L_12
L_13 ) ;
goto V_74;
}
if ( V_107 && ! V_108 ) {
V_53 = - V_90 ;
goto V_74;
}
if ( ( V_38 -> V_79 & V_80 ) && ( V_48 -> V_62 -> V_116 & V_117 )
&& ( V_115 == 0 ) )
goto V_74;
for ( V_86 = 0 ; V_86 < V_115 ; V_86 ++ ) {
T_2 V_17 ;
if ( V_79 [ V_86 ] == V_81 )
continue;
V_53 = F_67 ( V_114 [ V_86 ] ,
strlen ( V_114 [ V_86 ] ) , & V_17 , V_15 ) ;
if ( V_53 ) {
F_50 ( V_71 L_14
L_15 ,
V_114 [ V_86 ] , V_48 -> V_72 , V_63 , V_53 ) ;
goto V_74;
}
switch ( V_79 [ V_86 ] ) {
case V_99 :
V_110 = V_17 ;
if ( F_63 ( V_38 , V_99 , V_38 -> V_17 ,
V_110 ) )
goto V_118;
V_38 -> V_79 |= V_99 ;
break;
case V_100 :
V_111 = V_17 ;
if ( F_63 ( V_38 , V_100 , V_38 -> V_52 ,
V_111 ) )
goto V_118;
V_38 -> V_79 |= V_100 ;
break;
case V_102 :
V_112 = V_17 ;
if ( F_63 ( V_38 , V_102 , V_109 -> V_17 ,
V_112 ) )
goto V_118;
V_38 -> V_79 |= V_102 ;
break;
case V_101 :
V_113 = V_17 ;
if ( F_63 ( V_38 , V_101 , V_38 -> V_50 ,
V_113 ) )
goto V_118;
V_38 -> V_79 |= V_101 ;
break;
default:
V_53 = - V_90 ;
goto V_74;
}
}
if ( V_38 -> V_79 & V_80 ) {
if ( ( V_38 -> V_79 & V_92 ) && ! V_115 )
goto V_118;
V_53 = 0 ;
goto V_74;
}
if ( strcmp ( V_48 -> V_62 -> V_63 , L_16 ) == 0 )
V_38 -> V_79 |= V_119 ;
if ( ! V_38 -> V_58 ) {
V_53 = F_68 ( V_48 ) ;
if ( V_53 ) {
F_50 ( V_71
L_17 ,
V_120 , V_48 -> V_62 -> V_63 , V_53 ) ;
goto V_74;
}
}
if ( V_110 ) {
V_53 = F_45 ( V_110 , V_38 , V_10 ) ;
if ( V_53 )
goto V_74;
V_38 -> V_17 = V_110 ;
}
if ( V_107 & V_121 && ! V_111 ) {
V_38 -> V_58 = V_122 ;
* V_108 |= V_121 ;
}
if ( V_111 ) {
if ( ! V_110 ) {
V_53 = F_45 ( V_111 , V_38 ,
V_10 ) ;
if ( V_53 )
goto V_74;
V_38 -> V_17 = V_111 ;
} else {
V_53 = F_47 ( V_111 , V_38 ,
V_10 ) ;
if ( V_53 )
goto V_74;
}
if ( ! V_112 )
V_112 = V_111 ;
V_38 -> V_52 = V_111 ;
V_38 -> V_58 = V_123 ;
}
if ( V_112 ) {
V_53 = F_47 ( V_112 , V_38 ,
V_10 ) ;
if ( V_53 )
goto V_74;
V_109 -> V_17 = V_112 ;
V_109 -> V_124 = 1 ;
}
if ( V_113 ) {
if ( V_38 -> V_58 != V_59 &&
V_38 -> V_58 != V_122 ) {
V_53 = - V_90 ;
F_50 ( V_71 L_18
L_19 ) ;
goto V_74;
}
if ( V_113 != V_38 -> V_50 ) {
V_53 = F_47 ( V_113 ,
V_38 , V_10 ) ;
if ( V_53 )
goto V_74;
}
V_38 -> V_50 = V_113 ;
}
V_53 = F_49 ( V_48 ) ;
V_74:
F_69 ( & V_38 -> V_28 ) ;
return V_53 ;
V_118:
V_53 = - V_90 ;
F_50 ( V_71 L_20
L_21 , V_48 -> V_72 , V_63 ) ;
goto V_74;
}
static int F_70 ( const struct V_47 * V_125 ,
const struct V_47 * V_126 )
{
struct V_37 * V_127 = V_125 -> V_40 ;
struct V_37 * V_128 = V_126 -> V_40 ;
char V_129 = V_127 -> V_79 & V_92 ;
char V_130 = V_128 -> V_79 & V_92 ;
if ( V_129 != V_130 )
goto V_131;
if ( ( V_129 & V_99 ) && V_127 -> V_17 != V_128 -> V_17 )
goto V_131;
if ( ( V_129 & V_100 ) && V_127 -> V_52 != V_128 -> V_52 )
goto V_131;
if ( ( V_129 & V_101 ) && V_127 -> V_50 != V_128 -> V_50 )
goto V_131;
if ( V_129 & V_102 ) {
struct V_23 * V_132 = V_125 -> V_66 -> V_68 -> V_33 ;
struct V_23 * V_133 = V_126 -> V_66 -> V_68 -> V_33 ;
if ( V_132 -> V_17 != V_133 -> V_17 )
goto V_131;
}
return 0 ;
V_131:
F_50 ( V_71 L_22
L_23
L_24 , V_126 -> V_72 , V_126 -> V_62 -> V_63 ) ;
return - V_134 ;
}
static int F_71 ( const struct V_47 * V_125 ,
struct V_47 * V_126 )
{
const struct V_37 * V_135 = V_125 -> V_40 ;
struct V_37 * V_136 = V_126 -> V_40 ;
int V_137 = ( V_135 -> V_79 & V_99 ) ;
int V_138 = ( V_135 -> V_79 & V_100 ) ;
int V_139 = ( V_135 -> V_79 & V_102 ) ;
if ( ! V_91 )
return 0 ;
F_61 ( ! ( V_135 -> V_79 & V_80 ) ) ;
if ( V_136 -> V_79 & V_80 )
return F_70 ( V_125 , V_126 ) ;
F_66 ( & V_136 -> V_28 ) ;
V_136 -> V_79 = V_135 -> V_79 ;
V_136 -> V_17 = V_135 -> V_17 ;
V_136 -> V_50 = V_135 -> V_50 ;
V_136 -> V_58 = V_135 -> V_58 ;
if ( V_138 ) {
T_2 V_17 = V_135 -> V_52 ;
if ( ! V_137 )
V_136 -> V_17 = V_17 ;
if ( ! V_139 ) {
struct V_22 * V_140 = V_126 -> V_66 -> V_68 ;
struct V_23 * V_141 = V_140 -> V_33 ;
V_141 -> V_17 = V_17 ;
}
V_136 -> V_52 = V_17 ;
}
if ( V_139 ) {
const struct V_22 * V_142 = V_125 -> V_66 -> V_68 ;
const struct V_23 * V_143 = V_142 -> V_33 ;
struct V_22 * V_140 = V_126 -> V_66 -> V_68 ;
struct V_23 * V_141 = V_140 -> V_33 ;
V_141 -> V_17 = V_143 -> V_17 ;
}
F_49 ( V_126 ) ;
F_69 ( & V_136 -> V_28 ) ;
return 0 ;
}
static int F_72 ( char * V_144 ,
struct V_84 * V_85 )
{
char * V_145 ;
char * V_87 = NULL , * V_146 = NULL ;
char * V_147 = NULL , * V_148 = NULL ;
int V_53 , V_94 = 0 ;
V_85 -> V_94 = 0 ;
while ( ( V_145 = F_73 ( & V_144 , L_25 ) ) != NULL ) {
int V_149 ;
T_3 args [ V_150 ] ;
if ( ! * V_145 )
continue;
V_149 = F_74 ( V_145 , V_151 , args ) ;
switch ( V_149 ) {
case V_152 :
if ( V_87 || V_146 ) {
V_53 = - V_90 ;
F_50 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_153;
}
V_87 = F_75 ( & args [ 0 ] ) ;
if ( ! V_87 ) {
V_53 = - V_27 ;
goto V_153;
}
break;
case V_154 :
if ( V_147 ) {
V_53 = - V_90 ;
F_50 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_153;
}
V_147 = F_75 ( & args [ 0 ] ) ;
if ( ! V_147 ) {
V_53 = - V_27 ;
goto V_153;
}
break;
case V_155 :
if ( V_148 ) {
V_53 = - V_90 ;
F_50 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_153;
}
V_148 = F_75 ( & args [ 0 ] ) ;
if ( ! V_148 ) {
V_53 = - V_27 ;
goto V_153;
}
break;
case V_156 :
if ( V_87 || V_146 ) {
V_53 = - V_90 ;
F_50 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_153;
}
V_146 = F_75 ( & args [ 0 ] ) ;
if ( ! V_146 ) {
V_53 = - V_27 ;
goto V_153;
}
break;
case V_157 :
break;
default:
V_53 = - V_90 ;
F_50 ( V_71 L_26 ) ;
goto V_153;
}
}
V_53 = - V_27 ;
V_85 -> V_95 = F_59 ( V_93 , sizeof( char * ) , V_96 ) ;
if ( ! V_85 -> V_95 )
goto V_153;
V_85 -> V_98 = F_59 ( V_93 , sizeof( int ) , V_96 ) ;
if ( ! V_85 -> V_98 ) {
F_39 ( V_85 -> V_95 ) ;
goto V_153;
}
if ( V_147 ) {
V_85 -> V_95 [ V_94 ] = V_147 ;
V_85 -> V_98 [ V_94 ++ ] = V_99 ;
}
if ( V_87 ) {
V_85 -> V_95 [ V_94 ] = V_87 ;
V_85 -> V_98 [ V_94 ++ ] = V_100 ;
}
if ( V_148 ) {
V_85 -> V_95 [ V_94 ] = V_148 ;
V_85 -> V_98 [ V_94 ++ ] = V_102 ;
}
if ( V_146 ) {
V_85 -> V_95 [ V_94 ] = V_146 ;
V_85 -> V_98 [ V_94 ++ ] = V_101 ;
}
V_85 -> V_94 = V_94 ;
return 0 ;
V_153:
F_39 ( V_87 ) ;
F_39 ( V_146 ) ;
F_39 ( V_147 ) ;
F_39 ( V_148 ) ;
return V_53 ;
}
static int F_76 ( struct V_47 * V_48 , void * V_158 )
{
int V_53 = 0 ;
char * V_144 = V_158 ;
struct V_84 V_85 ;
F_57 ( & V_85 ) ;
if ( ! V_158 )
goto V_74;
F_61 ( V_48 -> V_62 -> V_116 & V_117 ) ;
V_53 = F_72 ( V_144 , & V_85 ) ;
if ( V_53 )
goto V_153;
V_74:
V_53 = F_64 ( V_48 , & V_85 , 0 , NULL ) ;
V_153:
F_62 ( & V_85 ) ;
return V_53 ;
}
static void F_77 ( struct V_159 * V_160 ,
struct V_84 * V_85 )
{
int V_86 ;
char * V_161 ;
for ( V_86 = 0 ; V_86 < V_85 -> V_94 ; V_86 ++ ) {
char * V_162 ;
if ( V_85 -> V_95 [ V_86 ] )
V_162 = strchr ( V_85 -> V_95 [ V_86 ] , ',' ) ;
else
V_162 = NULL ;
switch ( V_85 -> V_98 [ V_86 ] ) {
case V_100 :
V_161 = V_163 ;
break;
case V_99 :
V_161 = V_164 ;
break;
case V_102 :
V_161 = V_165 ;
break;
case V_101 :
V_161 = V_166 ;
break;
case V_81 :
F_78 ( V_160 , ',' ) ;
F_79 ( V_160 , V_167 ) ;
continue;
default:
F_80 () ;
return;
} ;
F_78 ( V_160 , ',' ) ;
F_79 ( V_160 , V_161 ) ;
if ( V_162 )
F_78 ( V_160 , '\"' ) ;
F_79 ( V_160 , V_85 -> V_95 [ V_86 ] ) ;
if ( V_162 )
F_78 ( V_160 , '\"' ) ;
}
}
static int F_81 ( struct V_159 * V_160 , struct V_47 * V_48 )
{
struct V_84 V_85 ;
int V_53 ;
V_53 = F_56 ( V_48 , & V_85 ) ;
if ( V_53 ) {
if ( V_53 == - V_90 )
V_53 = 0 ;
return V_53 ;
}
F_77 ( V_160 , & V_85 ) ;
F_62 ( & V_85 ) ;
return V_53 ;
}
static inline T_4 F_82 ( T_5 V_168 )
{
switch ( V_168 & V_169 ) {
case V_170 :
return V_171 ;
case V_172 :
return V_173 ;
case V_174 :
return V_32 ;
case V_175 :
return V_176 ;
case V_177 :
return V_178 ;
case V_179 :
return V_180 ;
case V_181 :
return V_182 ;
}
return V_32 ;
}
static inline int F_83 ( int V_183 )
{
return ( V_183 == V_184 || V_183 == V_185 ) ;
}
static inline int F_84 ( int V_183 )
{
return ( V_183 == V_184 || V_183 == V_186 ) ;
}
static inline T_4 F_85 ( int V_187 , int type , int V_183 )
{
switch ( V_187 ) {
case V_188 :
switch ( type ) {
case V_189 :
case V_190 :
return V_191 ;
case V_192 :
return V_193 ;
}
break;
case V_194 :
case V_195 :
switch ( type ) {
case V_189 :
if ( F_83 ( V_183 ) )
return V_196 ;
else
return V_197 ;
case V_192 :
if ( F_84 ( V_183 ) )
return V_198 ;
else
return V_197 ;
case V_199 :
return V_200 ;
default:
return V_197 ;
}
break;
case V_201 :
switch ( V_183 ) {
case V_202 :
return V_203 ;
case V_204 :
return V_205 ;
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
default:
return V_222 ;
}
case V_223 :
return V_224 ;
case V_225 :
return V_226 ;
case V_227 :
return V_228 ;
}
return V_229 ;
}
static int F_86 ( struct V_64 * V_64 ,
T_4 V_230 ,
T_2 * V_17 )
{
int V_53 ;
char * V_231 , * V_232 ;
V_231 = ( char * ) F_87 ( V_15 ) ;
if ( ! V_231 )
return - V_27 ;
V_232 = F_88 ( V_64 , V_231 , V_233 ) ;
if ( F_89 ( V_232 ) )
V_53 = F_90 ( V_232 ) ;
else {
while ( V_232 [ 1 ] >= '0' && V_232 [ 1 ] <= '9' ) {
V_232 [ 1 ] = '/' ;
V_232 ++ ;
}
V_53 = F_91 ( L_16 , V_232 , V_230 , V_17 ) ;
}
F_92 ( ( unsigned long ) V_231 ) ;
return V_53 ;
}
static int F_86 ( struct V_64 * V_64 ,
T_4 V_230 ,
T_2 * V_17 )
{
return - V_90 ;
}
static int F_44 ( struct V_22 * V_22 , struct V_64 * V_234 )
{
struct V_37 * V_38 = NULL ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 ;
struct V_64 * V_64 ;
#define F_93 255
char * V_87 = NULL ;
unsigned V_88 = 0 ;
int V_53 = 0 ;
if ( V_24 -> V_124 )
goto V_74;
F_66 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_124 )
goto V_235;
V_38 = V_22 -> V_39 -> V_40 ;
if ( ! ( V_38 -> V_79 & V_80 ) ) {
F_32 ( & V_38 -> V_41 ) ;
if ( F_33 ( & V_24 -> V_29 ) )
F_94 ( & V_24 -> V_29 , & V_38 -> V_49 ) ;
F_35 ( & V_38 -> V_41 ) ;
goto V_235;
}
switch ( V_38 -> V_58 ) {
case V_122 :
break;
case V_59 :
if ( ! V_22 -> V_69 -> V_70 ) {
V_24 -> V_17 = V_38 -> V_50 ;
break;
}
if ( V_234 ) {
V_64 = F_95 ( V_234 ) ;
} else {
V_64 = F_96 ( V_22 ) ;
}
if ( ! V_64 ) {
goto V_235;
}
V_88 = F_93 ;
V_87 = F_97 ( V_88 + 1 , V_26 ) ;
if ( ! V_87 ) {
V_53 = - V_27 ;
F_98 ( V_64 ) ;
goto V_235;
}
V_87 [ V_88 ] = '\0' ;
V_53 = V_22 -> V_69 -> V_70 ( V_64 , V_75 ,
V_87 , V_88 ) ;
if ( V_53 == - V_236 ) {
F_39 ( V_87 ) ;
V_53 = V_22 -> V_69 -> V_70 ( V_64 , V_75 ,
NULL , 0 ) ;
if ( V_53 < 0 ) {
F_98 ( V_64 ) ;
goto V_235;
}
V_88 = V_53 ;
V_87 = F_97 ( V_88 + 1 , V_26 ) ;
if ( ! V_87 ) {
V_53 = - V_27 ;
F_98 ( V_64 ) ;
goto V_235;
}
V_87 [ V_88 ] = '\0' ;
V_53 = V_22 -> V_69 -> V_70 ( V_64 ,
V_75 ,
V_87 , V_88 ) ;
}
F_98 ( V_64 ) ;
if ( V_53 < 0 ) {
if ( V_53 != - V_76 ) {
F_50 ( V_71 L_27
L_28 , V_120 ,
- V_53 , V_22 -> V_39 -> V_72 , V_22 -> V_237 ) ;
F_39 ( V_87 ) ;
goto V_235;
}
V_17 = V_38 -> V_50 ;
V_53 = 0 ;
} else {
V_53 = F_99 ( V_87 , V_53 , & V_17 ,
V_38 -> V_50 ,
V_26 ) ;
if ( V_53 ) {
char * V_238 = V_22 -> V_39 -> V_72 ;
unsigned long V_239 = V_22 -> V_237 ;
if ( V_53 == - V_90 ) {
if ( F_100 () )
F_50 ( V_240 L_29
L_30
L_31 , V_239 , V_238 , V_87 ) ;
} else {
F_50 ( V_71 L_32
L_33 ,
V_120 , V_87 , - V_53 , V_238 , V_239 ) ;
}
F_39 ( V_87 ) ;
V_53 = 0 ;
break;
}
}
F_39 ( V_87 ) ;
V_24 -> V_17 = V_17 ;
break;
case V_61 :
V_24 -> V_17 = V_24 -> F_18 ;
break;
case V_60 :
V_24 -> V_17 = V_38 -> V_17 ;
V_24 -> V_31 = F_82 ( V_22 -> V_241 ) ;
V_53 = F_101 ( V_24 -> F_18 , V_38 -> V_17 ,
V_24 -> V_31 , NULL , & V_17 ) ;
if ( V_53 )
goto V_235;
V_24 -> V_17 = V_17 ;
break;
case V_123 :
V_24 -> V_17 = V_38 -> V_52 ;
break;
default:
V_24 -> V_17 = V_38 -> V_17 ;
if ( ( V_38 -> V_79 & V_119 ) && ! F_102 ( V_22 -> V_241 ) ) {
if ( V_234 )
V_64 = F_95 ( V_234 ) ;
else
V_64 = F_96 ( V_22 ) ;
if ( ! V_64 )
goto V_235;
V_24 -> V_31 = F_82 ( V_22 -> V_241 ) ;
V_53 = F_86 ( V_64 , V_24 -> V_31 , & V_17 ) ;
F_98 ( V_64 ) ;
if ( V_53 )
goto V_235;
V_24 -> V_17 = V_17 ;
}
break;
}
V_24 -> V_124 = 1 ;
V_235:
F_69 ( & V_24 -> V_28 ) ;
V_74:
if ( V_24 -> V_31 == V_32 )
V_24 -> V_31 = F_82 ( V_22 -> V_241 ) ;
return V_53 ;
}
static inline T_2 F_103 ( int V_242 )
{
T_2 V_243 = 0 ;
switch ( V_242 ) {
case V_244 :
V_243 = V_245 ;
break;
case V_246 :
V_243 = V_247 ;
break;
case V_248 :
V_243 = V_249 ;
break;
default:
V_243 = V_250 ;
break;
}
return V_243 ;
}
static int F_104 ( const struct V_10 * V_251 ,
const struct V_10 * V_252 ,
T_2 V_253 )
{
T_2 V_254 = F_17 ( V_251 ) , V_255 = F_17 ( V_252 ) ;
return F_46 ( V_254 , V_255 , V_256 , V_253 , NULL ) ;
}
static int F_105 ( const struct V_20 * V_257 ,
const struct V_20 * V_258 ,
T_2 V_253 )
{
const struct V_13 * V_259 , * V_260 ;
T_2 V_261 , V_262 ;
F_19 () ;
V_259 = F_20 ( V_257 ) -> V_19 ; V_261 = V_259 -> V_17 ;
V_260 = F_20 ( V_258 ) -> V_19 ; V_262 = V_260 -> V_17 ;
F_21 () ;
return F_46 ( V_261 , V_262 , V_256 , V_253 , NULL ) ;
}
static int F_106 ( const struct V_20 * V_263 ,
T_2 V_253 )
{
T_2 V_17 , V_255 ;
V_17 = F_22 () ;
V_255 = F_18 ( V_263 ) ;
return F_46 ( V_17 , V_255 , V_256 , V_253 , NULL ) ;
}
static int F_107 ( const struct V_10 * V_10 ,
int V_264 , int V_265 )
{
struct V_266 V_267 ;
struct V_268 V_269 ;
T_4 V_31 ;
T_2 V_17 = F_17 ( V_10 ) ;
T_2 V_270 = F_108 ( V_264 ) ;
int V_53 ;
V_267 . type = V_271 ;
V_267 . V_272 . V_264 = V_264 ;
switch ( F_109 ( V_264 ) ) {
case 0 :
V_31 = V_273 ;
break;
case 1 :
V_31 = V_274 ;
break;
default:
F_50 ( V_78
L_34 , V_264 ) ;
F_80 () ;
return - V_90 ;
}
V_53 = F_110 ( V_17 , V_17 , V_31 , V_270 , 0 , & V_269 ) ;
if ( V_265 == V_275 ) {
int V_276 = F_111 ( V_17 , V_17 , V_31 , V_270 , & V_269 , V_53 , & V_267 ) ;
if ( V_276 )
return V_276 ;
}
return V_53 ;
}
static int F_112 ( struct V_20 * V_263 ,
T_2 V_253 )
{
T_2 V_17 = F_18 ( V_263 ) ;
return F_46 ( V_17 , V_18 ,
V_277 , V_253 , NULL ) ;
}
static int F_113 ( const struct V_10 * V_10 ,
struct V_22 * V_22 ,
T_2 V_253 ,
struct V_266 * V_278 )
{
struct V_23 * V_24 ;
T_2 V_17 ;
F_114 ( V_10 ) ;
if ( F_115 ( F_54 ( V_22 ) ) )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
return F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_253 , V_278 ) ;
}
static inline int F_116 ( const struct V_10 * V_10 ,
struct V_64 * V_64 ,
T_2 V_270 )
{
struct V_22 * V_22 = V_64 -> V_68 ;
struct V_266 V_267 ;
V_267 . type = V_279 ;
V_267 . V_272 . V_64 = V_64 ;
return F_113 ( V_10 , V_22 , V_270 , & V_267 ) ;
}
static inline int F_117 ( const struct V_10 * V_10 ,
struct V_232 * V_232 ,
T_2 V_270 )
{
struct V_22 * V_22 = V_232 -> V_64 -> V_68 ;
struct V_266 V_267 ;
V_267 . type = V_280 ;
V_267 . V_272 . V_232 = * V_232 ;
return F_113 ( V_10 , V_22 , V_270 , & V_267 ) ;
}
static inline int F_118 ( const struct V_10 * V_10 ,
struct V_42 * V_42 ,
T_2 V_270 )
{
struct V_266 V_267 ;
V_267 . type = V_280 ;
V_267 . V_272 . V_232 = V_42 -> V_281 ;
return F_113 ( V_10 , F_119 ( V_42 ) , V_270 , & V_267 ) ;
}
static int F_120 ( const struct V_10 * V_10 ,
struct V_42 * V_42 ,
T_2 V_270 )
{
struct V_43 * V_44 = V_42 -> V_46 ;
struct V_22 * V_22 = F_119 ( V_42 ) ;
struct V_266 V_267 ;
T_2 V_17 = F_17 ( V_10 ) ;
int V_53 ;
V_267 . type = V_280 ;
V_267 . V_272 . V_232 = V_42 -> V_281 ;
if ( V_17 != V_44 -> V_17 ) {
V_53 = F_46 ( V_17 , V_44 -> V_17 ,
V_282 ,
V_283 ,
& V_267 ) ;
if ( V_53 )
goto V_74;
}
V_53 = 0 ;
if ( V_270 )
V_53 = F_113 ( V_10 , V_22 , V_270 , & V_267 ) ;
V_74:
return V_53 ;
}
static int F_121 ( struct V_22 * V_284 ,
struct V_64 * V_64 ,
T_4 V_230 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_285 ;
struct V_37 * V_38 ;
T_2 V_17 , V_286 ;
struct V_266 V_267 ;
int V_53 ;
V_285 = V_284 -> V_33 ;
V_38 = V_284 -> V_39 -> V_40 ;
V_17 = V_14 -> V_17 ;
V_286 = V_14 -> V_287 ;
V_267 . type = V_279 ;
V_267 . V_272 . V_64 = V_64 ;
V_53 = F_46 ( V_17 , V_285 -> V_17 , V_178 ,
V_288 | V_289 ,
& V_267 ) ;
if ( V_53 )
return V_53 ;
if ( ! V_286 || ! ( V_38 -> V_79 & V_81 ) ) {
V_53 = F_101 ( V_17 , V_285 -> V_17 , V_230 ,
& V_64 -> V_290 , & V_286 ) ;
if ( V_53 )
return V_53 ;
}
V_53 = F_46 ( V_17 , V_286 , V_230 , V_291 , & V_267 ) ;
if ( V_53 )
return V_53 ;
return F_46 ( V_286 , V_38 -> V_17 ,
V_54 ,
V_57 , & V_267 ) ;
}
static int F_122 ( T_2 V_292 ,
struct V_20 * V_293 )
{
T_2 V_17 = F_18 ( V_293 ) ;
return F_46 ( V_17 , V_292 , V_294 , V_295 , NULL ) ;
}
static int F_123 ( struct V_22 * V_284 ,
struct V_64 * V_64 ,
int V_296 )
{
struct V_23 * V_285 , * V_24 ;
struct V_266 V_267 ;
T_2 V_17 = F_22 () ;
T_2 V_270 ;
int V_53 ;
V_285 = V_284 -> V_33 ;
V_24 = V_64 -> V_68 -> V_33 ;
V_267 . type = V_279 ;
V_267 . V_272 . V_64 = V_64 ;
V_270 = V_289 ;
V_270 |= ( V_296 ? V_297 : V_288 ) ;
V_53 = F_46 ( V_17 , V_285 -> V_17 , V_178 , V_270 , & V_267 ) ;
if ( V_53 )
return V_53 ;
switch ( V_296 ) {
case V_298 :
V_270 = V_299 ;
break;
case V_300 :
V_270 = V_301 ;
break;
case V_302 :
V_270 = V_303 ;
break;
default:
F_50 ( V_71 L_35 ,
V_120 , V_296 ) ;
return 0 ;
}
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_270 , & V_267 ) ;
return V_53 ;
}
static inline int F_124 ( struct V_22 * V_304 ,
struct V_64 * V_305 ,
struct V_22 * V_306 ,
struct V_64 * V_307 )
{
struct V_23 * V_308 , * V_309 , * V_310 , * V_311 ;
struct V_266 V_267 ;
T_2 V_17 = F_22 () ;
T_2 V_270 ;
int V_312 , V_313 ;
int V_53 ;
V_308 = V_304 -> V_33 ;
V_310 = V_305 -> V_68 -> V_33 ;
V_312 = F_125 ( V_305 ) ;
V_309 = V_306 -> V_33 ;
V_267 . type = V_279 ;
V_267 . V_272 . V_64 = V_305 ;
V_53 = F_46 ( V_17 , V_308 -> V_17 , V_178 ,
V_297 | V_289 , & V_267 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_17 , V_310 -> V_17 ,
V_310 -> V_31 , V_314 , & V_267 ) ;
if ( V_53 )
return V_53 ;
if ( V_312 && V_306 != V_304 ) {
V_53 = F_46 ( V_17 , V_310 -> V_17 ,
V_310 -> V_31 , V_315 , & V_267 ) ;
if ( V_53 )
return V_53 ;
}
V_267 . V_272 . V_64 = V_307 ;
V_270 = V_288 | V_289 ;
if ( F_126 ( V_307 ) )
V_270 |= V_297 ;
V_53 = F_46 ( V_17 , V_309 -> V_17 , V_178 , V_270 , & V_267 ) ;
if ( V_53 )
return V_53 ;
if ( F_126 ( V_307 ) ) {
V_311 = V_307 -> V_68 -> V_33 ;
V_313 = F_125 ( V_307 ) ;
V_53 = F_46 ( V_17 , V_311 -> V_17 ,
V_311 -> V_31 ,
( V_313 ? V_303 : V_301 ) , & V_267 ) ;
if ( V_53 )
return V_53 ;
}
return 0 ;
}
static int F_127 ( const struct V_10 * V_10 ,
struct V_47 * V_48 ,
T_2 V_253 ,
struct V_266 * V_267 )
{
struct V_37 * V_38 ;
T_2 V_17 = F_17 ( V_10 ) ;
V_38 = V_48 -> V_40 ;
return F_46 ( V_17 , V_38 -> V_17 , V_54 , V_253 , V_267 ) ;
}
static inline T_2 F_128 ( int V_168 , int V_316 )
{
T_2 V_270 = 0 ;
if ( ! F_129 ( V_168 ) ) {
if ( V_316 & V_317 )
V_270 |= V_318 ;
if ( V_316 & V_319 )
V_270 |= V_320 ;
if ( V_316 & V_321 )
V_270 |= V_322 ;
else if ( V_316 & V_323 )
V_270 |= V_324 ;
} else {
if ( V_316 & V_317 )
V_270 |= V_289 ;
if ( V_316 & V_323 )
V_270 |= V_325 ;
if ( V_316 & V_319 )
V_270 |= V_326 ;
}
return V_270 ;
}
static inline T_2 F_130 ( struct V_42 * V_42 )
{
T_2 V_270 = 0 ;
if ( V_42 -> V_327 & V_328 )
V_270 |= V_320 ;
if ( V_42 -> V_327 & V_329 ) {
if ( V_42 -> V_330 & V_331 )
V_270 |= V_322 ;
else
V_270 |= V_324 ;
}
if ( ! V_270 ) {
V_270 = V_332 ;
}
return V_270 ;
}
static inline T_2 F_131 ( struct V_42 * V_42 )
{
T_2 V_270 = F_130 ( V_42 ) ;
if ( V_333 )
V_270 |= V_334 ;
return V_270 ;
}
static int F_132 ( struct V_20 * V_335 )
{
T_2 V_336 = F_22 () ;
T_2 V_337 = F_18 ( V_335 ) ;
return F_46 ( V_336 , V_337 , V_338 ,
V_339 , NULL ) ;
}
static int F_133 ( struct V_20 * V_340 ,
struct V_20 * V_341 )
{
T_2 V_336 = F_22 () ;
T_2 V_342 = F_18 ( V_340 ) ;
T_2 V_343 = F_18 ( V_341 ) ;
int V_53 ;
if ( V_336 != V_342 ) {
V_53 = F_46 ( V_336 , V_342 , V_338 ,
V_344 , NULL ) ;
if ( V_53 )
return V_53 ;
}
return F_46 ( V_342 , V_343 , V_338 , V_345 ,
NULL ) ;
}
static int F_134 ( struct V_20 * V_340 ,
struct V_20 * V_341 )
{
T_2 V_342 = F_18 ( V_340 ) ;
T_2 V_343 = F_18 ( V_341 ) ;
return F_46 ( V_342 , V_343 , V_338 , V_346 ,
NULL ) ;
}
static int F_135 ( struct V_20 * V_340 ,
struct V_20 * V_341 ,
struct V_42 * V_42 )
{
T_2 V_17 = F_18 ( V_341 ) ;
struct V_43 * V_44 = V_42 -> V_46 ;
struct V_22 * V_22 = V_42 -> V_281 . V_64 -> V_68 ;
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_266 V_267 ;
int V_53 ;
V_267 . type = V_280 ;
V_267 . V_272 . V_232 = V_42 -> V_281 ;
if ( V_17 != V_44 -> V_17 ) {
V_53 = F_46 ( V_17 , V_44 -> V_17 ,
V_282 ,
V_283 ,
& V_267 ) ;
if ( V_53 )
return V_53 ;
}
if ( F_115 ( F_54 ( V_22 ) ) )
return 0 ;
return F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , F_130 ( V_42 ) ,
& V_267 ) ;
}
static int F_136 ( struct V_20 * V_347 ,
unsigned int V_168 )
{
int V_53 ;
V_53 = F_137 ( V_347 , V_168 ) ;
if ( V_53 )
return V_53 ;
if ( V_168 & V_348 ) {
T_2 V_17 = F_22 () ;
T_2 V_349 = F_18 ( V_347 ) ;
return F_46 ( V_17 , V_349 , V_32 , V_320 , NULL ) ;
}
return F_106 ( V_347 , V_350 ) ;
}
static int F_138 ( struct V_20 * V_351 )
{
int V_53 ;
V_53 = F_139 ( V_351 ) ;
if ( V_53 )
return V_53 ;
return F_105 ( V_351 , V_11 , V_350 ) ;
}
static int F_140 ( struct V_20 * V_252 , T_6 * V_352 ,
T_6 * V_353 , T_6 * V_354 )
{
int error ;
error = F_106 ( V_252 , V_355 ) ;
if ( error )
return error ;
return F_141 ( V_252 , V_352 , V_353 , V_354 ) ;
}
static int F_142 ( struct V_10 * V_128 , const struct V_10 * V_127 ,
const T_6 * V_352 ,
const T_6 * V_353 ,
const T_6 * V_354 )
{
int error ;
error = F_143 ( V_128 , V_127 ,
V_352 , V_353 , V_354 ) ;
if ( error )
return error ;
return F_104 ( V_127 , V_128 , V_356 ) ;
}
static int F_144 ( const struct V_10 * V_10 , struct V_357 * V_358 ,
int V_264 , int V_265 )
{
int V_53 ;
V_53 = F_145 ( V_10 , V_358 , V_264 , V_265 ) ;
if ( V_53 )
return V_53 ;
return F_107 ( V_10 , V_264 , V_265 ) ;
}
static int F_146 ( int V_359 , int type , int V_360 , struct V_47 * V_48 )
{
const struct V_10 * V_10 = F_65 () ;
int V_53 = 0 ;
if ( ! V_48 )
return 0 ;
switch ( V_359 ) {
case V_361 :
case V_362 :
case V_363 :
case V_364 :
case V_365 :
V_53 = F_127 ( V_10 , V_48 , V_366 , NULL ) ;
break;
case V_367 :
case V_368 :
case V_369 :
V_53 = F_127 ( V_10 , V_48 , V_370 , NULL ) ;
break;
default:
V_53 = 0 ;
break;
}
return V_53 ;
}
static int F_147 ( struct V_64 * V_64 )
{
const struct V_10 * V_10 = F_65 () ;
return F_116 ( V_10 , V_64 , V_371 ) ;
}
static int F_148 ( int type )
{
int V_53 ;
switch ( type ) {
case V_372 :
case V_373 :
V_53 = F_112 ( V_11 , V_374 ) ;
break;
case V_375 :
case V_376 :
case V_377 :
V_53 = F_112 ( V_11 , V_378 ) ;
break;
case V_379 :
case V_380 :
case V_381 :
case V_382 :
case V_383 :
default:
V_53 = F_112 ( V_11 , V_384 ) ;
break;
}
return V_53 ;
}
static int F_149 ( struct V_385 * V_386 , long V_387 )
{
int V_53 , V_388 = 0 ;
V_53 = F_144 ( F_65 () , & V_389 , V_390 ,
V_391 ) ;
if ( V_53 == 0 )
V_388 = 1 ;
return F_150 ( V_386 , V_387 , V_388 ) ;
}
static int F_151 ( const struct V_392 * V_393 ,
const struct V_13 * V_394 ,
const struct V_13 * V_395 )
{
int V_396 = ( V_393 -> V_397 & V_398 ) ;
int V_399 = ( V_393 -> V_42 -> V_281 . V_400 -> V_106 & V_401 ) ;
int V_53 ;
if ( ! V_396 && ! V_399 )
return 0 ;
if ( V_395 -> V_17 == V_394 -> V_17 )
return 0 ;
V_53 = F_152 ( V_394 -> V_17 , V_395 -> V_17 ) ;
if ( V_53 ) {
if ( V_396 )
return - V_402 ;
else
return - V_403 ;
}
return 0 ;
}
static int F_153 ( struct V_392 * V_393 )
{
const struct V_13 * V_394 ;
struct V_13 * V_395 ;
struct V_23 * V_24 ;
struct V_266 V_267 ;
struct V_22 * V_22 = F_119 ( V_393 -> V_42 ) ;
int V_53 ;
V_53 = F_154 ( V_393 ) ;
if ( V_53 )
return V_53 ;
if ( V_393 -> V_404 )
return 0 ;
V_394 = F_23 () ;
V_395 = V_393 -> V_10 -> V_19 ;
V_24 = V_22 -> V_33 ;
V_395 -> V_17 = V_394 -> V_17 ;
V_395 -> V_16 = V_394 -> V_17 ;
V_395 -> V_287 = 0 ;
V_395 -> V_405 = 0 ;
V_395 -> V_406 = 0 ;
if ( V_394 -> V_407 ) {
V_395 -> V_17 = V_394 -> V_407 ;
V_395 -> V_407 = 0 ;
V_53 = F_151 ( V_393 , V_394 , V_395 ) ;
if ( V_53 )
return V_53 ;
} else {
V_53 = F_101 ( V_394 -> V_17 , V_24 -> V_17 ,
V_256 , NULL ,
& V_395 -> V_17 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_151 ( V_393 , V_394 , V_395 ) ;
if ( V_53 )
V_395 -> V_17 = V_394 -> V_17 ;
}
V_267 . type = V_280 ;
V_267 . V_272 . V_232 = V_393 -> V_42 -> V_281 ;
if ( V_395 -> V_17 == V_394 -> V_17 ) {
V_53 = F_46 ( V_394 -> V_17 , V_24 -> V_17 ,
V_32 , V_408 , & V_267 ) ;
if ( V_53 )
return V_53 ;
} else {
V_53 = F_46 ( V_394 -> V_17 , V_395 -> V_17 ,
V_256 , V_409 , & V_267 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_395 -> V_17 , V_24 -> V_17 ,
V_32 , V_410 , & V_267 ) ;
if ( V_53 )
return V_53 ;
if ( V_393 -> V_397 & V_411 ) {
V_53 = F_46 ( V_394 -> V_17 , V_395 -> V_17 ,
V_256 , V_412 ,
NULL ) ;
if ( V_53 )
return - V_402 ;
}
if ( V_393 -> V_397 &
( V_413 | V_414 ) ) {
struct V_20 * V_415 ;
struct V_13 * V_416 ;
T_2 V_417 = 0 ;
F_19 () ;
V_415 = F_155 ( V_11 ) ;
if ( F_156 ( V_415 != NULL ) ) {
V_416 = F_20 ( V_415 ) -> V_19 ;
V_417 = V_416 -> V_17 ;
}
F_21 () ;
if ( V_417 != 0 ) {
V_53 = F_46 ( V_417 , V_395 -> V_17 ,
V_256 ,
V_350 , NULL ) ;
if ( V_53 )
return - V_402 ;
}
}
V_393 -> V_418 |= V_419 ;
}
return 0 ;
}
static int F_157 ( struct V_392 * V_393 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_17 , V_16 ;
int V_420 = 0 ;
V_17 = V_14 -> V_17 ;
V_16 = V_14 -> V_16 ;
if ( V_16 != V_17 ) {
V_420 = F_46 ( V_16 , V_17 ,
V_256 ,
V_421 , NULL ) ;
}
return ( V_420 || F_158 ( V_393 ) ) ;
}
static int F_159 ( const void * V_145 , struct V_42 * V_42 , unsigned V_422 )
{
return F_120 ( V_145 , V_42 , F_130 ( V_42 ) ) ? V_422 + 1 : 0 ;
}
static inline void F_160 ( const struct V_10 * V_10 ,
struct V_423 * V_424 )
{
struct V_42 * V_42 , * V_425 = NULL ;
struct V_426 * V_427 ;
int V_428 = 0 ;
unsigned V_429 ;
V_427 = F_161 () ;
if ( V_427 ) {
F_32 ( & V_430 ) ;
if ( ! F_33 ( & V_427 -> V_431 ) ) {
struct V_432 * V_433 ;
V_433 = F_162 ( & V_427 -> V_431 ,
struct V_432 , V_29 ) ;
V_42 = V_433 -> V_42 ;
if ( F_118 ( V_10 , V_42 , V_320 | V_324 ) )
V_428 = 1 ;
}
F_35 ( & V_430 ) ;
F_163 ( V_427 ) ;
}
if ( V_428 )
F_164 () ;
V_429 = F_165 ( V_424 , 0 , F_159 , V_10 ) ;
if ( ! V_429 )
return;
V_425 = F_166 ( & V_434 , V_435 , V_10 ) ;
if ( F_89 ( V_425 ) )
V_425 = NULL ;
do {
F_167 ( V_429 - 1 , V_425 , 0 ) ;
} while ( ( V_429 = F_165 ( V_424 , V_429 , F_159 , V_10 ) ) != 0 );
if ( V_425 )
F_168 ( V_425 ) ;
}
static void F_169 ( struct V_392 * V_393 )
{
struct V_13 * V_395 ;
struct V_436 * V_437 , * V_438 ;
int V_53 , V_86 ;
V_395 = V_393 -> V_10 -> V_19 ;
if ( V_395 -> V_17 == V_395 -> V_16 )
return;
F_160 ( V_393 -> V_10 , V_11 -> V_424 ) ;
V_11 -> V_439 = 0 ;
V_53 = F_46 ( V_395 -> V_16 , V_395 -> V_17 , V_256 ,
V_440 , NULL ) ;
if ( V_53 ) {
F_170 ( V_11 ) ;
for ( V_86 = 0 ; V_86 < V_441 ; V_86 ++ ) {
V_437 = V_11 -> signal -> V_437 + V_86 ;
V_438 = V_442 . signal -> V_437 + V_86 ;
V_437 -> V_443 = F_171 ( V_437 -> V_444 , V_438 -> V_443 ) ;
}
F_172 ( V_11 ) ;
F_173 ( V_11 , V_436 ( V_445 ) ) ;
}
}
static void F_174 ( struct V_392 * V_393 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_446 V_447 ;
T_2 V_16 , V_17 ;
int V_53 , V_86 ;
V_16 = V_14 -> V_16 ;
V_17 = V_14 -> V_17 ;
if ( V_17 == V_16 )
return;
V_53 = F_46 ( V_16 , V_17 , V_256 , V_448 , NULL ) ;
if ( V_53 ) {
memset ( & V_447 , 0 , sizeof V_447 ) ;
for ( V_86 = 0 ; V_86 < 3 ; V_86 ++ )
F_175 ( V_86 , & V_447 , NULL ) ;
F_176 ( & V_11 -> V_449 -> V_450 ) ;
if ( ! ( V_11 -> signal -> V_79 & V_451 ) ) {
F_177 ( V_11 ) ;
F_178 ( V_11 , 1 ) ;
F_179 ( & V_11 -> V_452 ) ;
}
F_180 ( & V_11 -> V_449 -> V_450 ) ;
}
F_181 ( & V_453 ) ;
F_182 ( V_11 , V_11 -> V_454 ) ;
F_183 ( & V_453 ) ;
}
static int F_184 ( struct V_47 * V_48 )
{
return F_40 ( V_48 ) ;
}
static void F_185 ( struct V_47 * V_48 )
{
F_42 ( V_48 ) ;
}
static inline int F_186 ( char * V_161 , int V_455 , char * V_456 , int V_457 )
{
if ( V_455 > V_457 )
return 0 ;
return ! memcmp ( V_161 , V_456 , V_455 ) ;
}
static inline int F_187 ( char * V_456 , int V_88 )
{
return ( F_186 ( V_163 , sizeof( V_163 ) - 1 , V_456 , V_88 ) ||
F_186 ( V_164 , sizeof( V_164 ) - 1 , V_456 , V_88 ) ||
F_186 ( V_166 , sizeof( V_166 ) - 1 , V_456 , V_88 ) ||
F_186 ( V_165 , sizeof( V_165 ) - 1 , V_456 , V_88 ) ||
F_186 ( V_167 , sizeof( V_167 ) - 1 , V_456 , V_88 ) ) ;
}
static inline void F_188 ( char * * V_341 , char * V_340 , int * V_458 , int V_88 )
{
if ( ! * V_458 ) {
* * V_341 = ',' ;
* V_341 += 1 ;
} else
* V_458 = 0 ;
memcpy ( * V_341 , V_340 , V_88 ) ;
* V_341 += V_88 ;
}
static inline void F_189 ( char * * V_341 , char * V_340 , int * V_458 ,
int V_88 )
{
int V_459 = 0 ;
if ( ! * V_458 ) {
* * V_341 = '|' ;
* V_341 += 1 ;
} else
* V_458 = 0 ;
while ( V_459 < V_88 ) {
if ( * V_340 != '"' ) {
* * V_341 = * V_340 ;
* V_341 += 1 ;
}
V_340 += 1 ;
V_459 += 1 ;
}
}
static int F_190 ( char * V_460 , char * V_461 )
{
int V_462 , V_44 , V_53 = 0 ;
char * V_463 , * V_464 , * V_465 ;
char * V_466 , * V_467 , * V_468 ;
int V_469 = 0 ;
V_464 = V_460 ;
V_466 = V_461 ;
V_468 = ( char * ) F_191 ( V_15 ) ;
if ( ! V_468 ) {
V_53 = - V_27 ;
goto V_74;
}
V_467 = V_468 ;
V_462 = V_44 = 1 ;
V_463 = V_465 = V_460 ;
do {
if ( * V_465 == '"' )
V_469 = ! V_469 ;
if ( ( * V_465 == ',' && V_469 == 0 ) ||
* V_465 == '\0' ) {
int V_88 = V_465 - V_464 ;
if ( F_187 ( V_464 , V_88 ) )
F_189 ( & V_466 , V_464 , & V_44 , V_88 ) ;
else
F_188 ( & V_468 , V_464 , & V_462 , V_88 ) ;
V_464 = V_465 + 1 ;
}
} while ( * V_465 ++ );
strcpy ( V_463 , V_467 ) ;
F_92 ( ( unsigned long ) V_467 ) ;
V_74:
return V_53 ;
}
static int F_192 ( struct V_47 * V_48 , void * V_158 )
{
int V_53 , V_86 , * V_79 ;
struct V_84 V_85 ;
char * V_470 , * * V_114 ;
struct V_37 * V_38 = V_48 -> V_40 ;
if ( ! ( V_38 -> V_79 & V_80 ) )
return 0 ;
if ( ! V_158 )
return 0 ;
if ( V_48 -> V_62 -> V_116 & V_117 )
return 0 ;
F_57 ( & V_85 ) ;
V_470 = F_193 () ;
if ( ! V_470 )
return - V_27 ;
V_53 = F_190 ( V_158 , V_470 ) ;
if ( V_53 )
goto V_471;
V_53 = F_72 ( V_470 , & V_85 ) ;
if ( V_53 )
goto V_471;
V_114 = V_85 . V_95 ;
V_79 = V_85 . V_98 ;
for ( V_86 = 0 ; V_86 < V_85 . V_94 ; V_86 ++ ) {
T_2 V_17 ;
T_7 V_88 ;
if ( V_79 [ V_86 ] == V_81 )
continue;
V_88 = strlen ( V_114 [ V_86 ] ) ;
V_53 = F_67 ( V_114 [ V_86 ] , V_88 , & V_17 ,
V_15 ) ;
if ( V_53 ) {
F_50 ( V_71 L_14
L_15 ,
V_114 [ V_86 ] , V_48 -> V_72 , V_48 -> V_62 -> V_63 , V_53 ) ;
goto V_472;
}
V_53 = - V_90 ;
switch ( V_79 [ V_86 ] ) {
case V_99 :
if ( F_63 ( V_38 , V_99 , V_38 -> V_17 , V_17 ) )
goto V_473;
break;
case V_100 :
if ( F_63 ( V_38 , V_100 , V_38 -> V_52 , V_17 ) )
goto V_473;
break;
case V_102 : {
struct V_23 * V_109 ;
V_109 = V_48 -> V_66 -> V_68 -> V_33 ;
if ( F_63 ( V_38 , V_102 , V_109 -> V_17 , V_17 ) )
goto V_473;
break;
}
case V_101 :
if ( F_63 ( V_38 , V_101 , V_38 -> V_50 , V_17 ) )
goto V_473;
break;
default:
goto V_472;
}
}
V_53 = 0 ;
V_472:
F_62 ( & V_85 ) ;
V_471:
F_194 ( V_470 ) ;
return V_53 ;
V_473:
F_50 ( V_71 L_36
L_37 , V_48 -> V_72 ,
V_48 -> V_62 -> V_63 ) ;
goto V_472;
}
static int F_195 ( struct V_47 * V_48 , int V_79 , void * V_158 )
{
const struct V_10 * V_10 = F_65 () ;
struct V_266 V_267 ;
int V_53 ;
V_53 = F_76 ( V_48 , V_158 ) ;
if ( V_53 )
return V_53 ;
if ( V_79 & V_474 )
return 0 ;
V_267 . type = V_279 ;
V_267 . V_272 . V_64 = V_48 -> V_66 ;
return F_127 ( V_10 , V_48 , V_475 , & V_267 ) ;
}
static int F_196 ( struct V_64 * V_64 )
{
const struct V_10 * V_10 = F_65 () ;
struct V_266 V_267 ;
V_267 . type = V_279 ;
V_267 . V_272 . V_64 = V_64 -> V_476 -> V_66 ;
return F_127 ( V_10 , V_64 -> V_476 , V_477 , & V_267 ) ;
}
static int F_197 ( const char * V_478 ,
struct V_232 * V_232 ,
const char * type ,
unsigned long V_79 ,
void * V_158 )
{
const struct V_10 * V_10 = F_65 () ;
if ( V_79 & V_479 )
return F_127 ( V_10 , V_232 -> V_64 -> V_476 ,
V_480 , NULL ) ;
else
return F_117 ( V_10 , V_232 , V_481 ) ;
}
static int F_198 ( struct V_482 * V_400 , int V_79 )
{
const struct V_10 * V_10 = F_65 () ;
return F_127 ( V_10 , V_400 -> V_483 ,
V_484 , NULL ) ;
}
static int F_199 ( struct V_22 * V_22 )
{
return F_24 ( V_22 ) ;
}
static void F_200 ( struct V_22 * V_22 )
{
F_31 ( V_22 ) ;
}
static int F_201 ( struct V_64 * V_64 , int V_168 ,
struct V_485 * V_63 , void * * V_293 ,
T_2 * V_486 )
{
const struct V_10 * V_10 = F_65 () ;
struct V_13 * V_14 ;
struct V_23 * V_285 ;
struct V_37 * V_38 ;
struct V_22 * V_284 = V_64 -> V_487 -> V_68 ;
T_2 V_286 ;
int V_53 ;
V_14 = V_10 -> V_19 ;
V_285 = V_284 -> V_33 ;
V_38 = V_284 -> V_39 -> V_40 ;
if ( V_14 -> V_287 && V_38 -> V_58 != V_123 ) {
V_286 = V_14 -> V_287 ;
} else {
V_53 = F_101 ( V_14 -> V_17 , V_285 -> V_17 ,
F_82 ( V_168 ) ,
V_63 ,
& V_286 ) ;
if ( V_53 ) {
F_50 ( V_71
L_38 ,
V_120 , - V_53 ) ;
return V_53 ;
}
}
return F_60 ( V_286 , ( char * * ) V_293 , V_486 ) ;
}
static int F_202 ( struct V_22 * V_22 , struct V_22 * V_284 ,
const struct V_485 * V_485 ,
const char * * V_63 ,
void * * V_488 , T_7 * V_88 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_285 ;
struct V_37 * V_38 ;
T_2 V_17 , V_286 , V_489 ;
int V_53 ;
char * V_87 ;
V_285 = V_284 -> V_33 ;
V_38 = V_284 -> V_39 -> V_40 ;
V_17 = V_14 -> V_17 ;
V_286 = V_14 -> V_287 ;
if ( ( V_38 -> V_79 & V_80 ) &&
( V_38 -> V_58 == V_123 ) )
V_286 = V_38 -> V_52 ;
else if ( ! V_286 || ! ( V_38 -> V_79 & V_81 ) ) {
V_53 = F_101 ( V_17 , V_285 -> V_17 ,
F_82 ( V_22 -> V_241 ) ,
V_485 , & V_286 ) ;
if ( V_53 ) {
F_50 ( V_71 L_39
L_40
L_41 ,
V_120 ,
- V_53 , V_22 -> V_39 -> V_72 , V_22 -> V_237 ) ;
return V_53 ;
}
}
if ( V_38 -> V_79 & V_80 ) {
struct V_23 * V_24 = V_22 -> V_33 ;
V_24 -> V_31 = F_82 ( V_22 -> V_241 ) ;
V_24 -> V_17 = V_286 ;
V_24 -> V_124 = 1 ;
}
if ( ! V_91 || ! ( V_38 -> V_79 & V_81 ) )
return - V_73 ;
if ( V_63 )
* V_63 = V_490 ;
if ( V_488 && V_88 ) {
V_53 = F_203 ( V_286 , & V_87 , & V_489 ) ;
if ( V_53 )
return V_53 ;
* V_488 = V_87 ;
* V_88 = V_489 ;
}
return 0 ;
}
static int F_204 ( struct V_22 * V_284 , struct V_64 * V_64 , T_5 V_168 )
{
return F_121 ( V_284 , V_64 , V_32 ) ;
}
static int F_205 ( struct V_64 * V_305 , struct V_22 * V_284 , struct V_64 * V_307 )
{
return F_123 ( V_284 , V_305 , V_298 ) ;
}
static int F_206 ( struct V_22 * V_284 , struct V_64 * V_64 )
{
return F_123 ( V_284 , V_64 , V_300 ) ;
}
static int F_207 ( struct V_22 * V_284 , struct V_64 * V_64 , const char * V_63 )
{
return F_121 ( V_284 , V_64 , V_173 ) ;
}
static int F_208 ( struct V_22 * V_284 , struct V_64 * V_64 , T_5 V_316 )
{
return F_121 ( V_284 , V_64 , V_178 ) ;
}
static int F_209 ( struct V_22 * V_284 , struct V_64 * V_64 )
{
return F_123 ( V_284 , V_64 , V_302 ) ;
}
static int F_210 ( struct V_22 * V_284 , struct V_64 * V_64 , T_5 V_168 , T_8 V_238 )
{
return F_121 ( V_284 , V_64 , F_82 ( V_168 ) ) ;
}
static int F_211 ( struct V_22 * V_491 , struct V_64 * V_305 ,
struct V_22 * V_492 , struct V_64 * V_307 )
{
return F_124 ( V_491 , V_305 , V_492 , V_307 ) ;
}
static int F_212 ( struct V_64 * V_64 )
{
const struct V_10 * V_10 = F_65 () ;
return F_116 ( V_10 , V_64 , V_320 ) ;
}
static int F_213 ( struct V_64 * V_64 , struct V_493 * V_493 )
{
const struct V_10 * V_10 = F_65 () ;
return F_116 ( V_10 , V_64 , V_320 ) ;
}
static T_9 int F_214 ( struct V_22 * V_22 ,
T_2 V_253 , T_2 V_494 , T_2 V_495 ,
int V_496 ,
unsigned V_79 )
{
struct V_266 V_267 ;
struct V_23 * V_24 = V_22 -> V_33 ;
int V_53 ;
V_267 . type = V_497 ;
V_267 . V_272 . V_22 = V_22 ;
V_53 = F_215 ( F_22 () , V_24 -> V_17 , V_24 -> V_31 , V_253 ,
V_494 , V_495 , V_496 , & V_267 , V_79 ) ;
if ( V_53 )
return V_53 ;
return 0 ;
}
static int F_216 ( struct V_22 * V_22 , int V_316 )
{
const struct V_10 * V_10 = F_65 () ;
T_2 V_253 ;
bool V_498 ;
unsigned V_79 = V_316 & V_499 ;
struct V_23 * V_24 ;
T_2 V_17 ;
struct V_268 V_269 ;
int V_53 , V_276 ;
T_2 V_494 , V_495 ;
V_498 = V_316 & V_500 ;
V_316 &= ( V_319 | V_323 | V_317 | V_321 ) ;
if ( ! V_316 )
return 0 ;
F_114 ( V_10 ) ;
if ( F_115 ( F_54 ( V_22 ) ) )
return 0 ;
V_253 = F_128 ( V_22 -> V_241 , V_316 ) ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
V_53 = F_110 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_253 , 0 , & V_269 ) ;
V_494 = F_217 ( V_253 , & V_269 , V_53 ,
V_498 ? V_501 : 0 ,
& V_495 ) ;
if ( F_156 ( ! V_494 ) )
return V_53 ;
V_276 = F_214 ( V_22 , V_253 , V_494 , V_495 , V_53 , V_79 ) ;
if ( V_276 )
return V_276 ;
return V_53 ;
}
static int F_218 ( struct V_64 * V_64 , struct V_502 * V_502 )
{
const struct V_10 * V_10 = F_65 () ;
unsigned int V_503 = V_502 -> V_503 ;
T_10 V_270 = V_324 ;
if ( V_503 & V_504 ) {
V_503 &= ~ ( V_505 | V_506 | V_507 |
V_504 ) ;
if ( ! V_503 )
return 0 ;
}
if ( V_503 & ( V_507 | V_508 | V_509 |
V_510 | V_511 | V_512 ) )
return F_116 ( V_10 , V_64 , V_513 ) ;
if ( V_333 && ( V_503 & V_514 ) )
V_270 |= V_334 ;
return F_116 ( V_10 , V_64 , V_270 ) ;
}
static int F_219 ( struct V_482 * V_400 , struct V_64 * V_64 )
{
const struct V_10 * V_10 = F_65 () ;
struct V_232 V_232 ;
V_232 . V_64 = V_64 ;
V_232 . V_400 = V_400 ;
return F_117 ( V_10 , & V_232 , V_515 ) ;
}
static int F_220 ( struct V_64 * V_64 , const char * V_63 )
{
const struct V_10 * V_10 = F_65 () ;
if ( ! strncmp ( V_63 , V_516 ,
sizeof V_516 - 1 ) ) {
if ( ! strcmp ( V_63 , V_517 ) ) {
if ( ! F_221 ( V_518 ) )
return - V_402 ;
} else if ( ! F_221 ( V_390 ) ) {
return - V_402 ;
}
}
return F_116 ( V_10 , V_64 , V_513 ) ;
}
static int F_222 ( struct V_64 * V_64 , const char * V_63 ,
const void * V_488 , T_7 V_519 , int V_79 )
{
struct V_22 * V_22 = V_64 -> V_68 ;
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_37 * V_38 ;
struct V_266 V_267 ;
T_2 V_286 , V_17 = F_22 () ;
int V_53 = 0 ;
if ( strcmp ( V_63 , V_75 ) )
return F_220 ( V_64 , V_63 ) ;
V_38 = V_22 -> V_39 -> V_40 ;
if ( ! ( V_38 -> V_79 & V_81 ) )
return - V_73 ;
if ( ! F_223 ( V_22 ) )
return - V_402 ;
V_267 . type = V_279 ;
V_267 . V_272 . V_64 = V_64 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 ,
V_520 , & V_267 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_67 ( V_488 , V_519 , & V_286 , V_15 ) ;
if ( V_53 == - V_90 ) {
if ( ! F_221 ( V_521 ) ) {
struct V_522 * V_523 ;
T_7 V_524 ;
const char * V_1 ;
if ( V_488 ) {
V_1 = V_488 ;
if ( V_1 [ V_519 - 1 ] == '\0' )
V_524 = V_519 - 1 ;
else
V_524 = V_519 ;
} else {
V_1 = L_42 ;
V_524 = 0 ;
}
V_523 = F_224 ( V_11 -> V_525 , V_96 , V_526 ) ;
F_225 ( V_523 , L_43 ) ;
F_226 ( V_523 , V_488 , V_524 ) ;
F_227 ( V_523 ) ;
return V_53 ;
}
V_53 = F_228 ( V_488 , V_519 , & V_286 ) ;
}
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_17 , V_286 , V_24 -> V_31 ,
V_527 , & V_267 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_229 ( V_24 -> V_17 , V_286 , V_17 ,
V_24 -> V_31 ) ;
if ( V_53 )
return V_53 ;
return F_46 ( V_286 ,
V_38 -> V_17 ,
V_54 ,
V_57 ,
& V_267 ) ;
}
static void F_230 ( struct V_64 * V_64 , const char * V_63 ,
const void * V_488 , T_7 V_519 ,
int V_79 )
{
struct V_22 * V_22 = V_64 -> V_68 ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_286 ;
int V_53 ;
if ( strcmp ( V_63 , V_75 ) ) {
return;
}
V_53 = F_228 ( V_488 , V_519 , & V_286 ) ;
if ( V_53 ) {
F_50 ( V_78 L_44
L_45 ,
V_22 -> V_39 -> V_72 , V_22 -> V_237 , - V_53 ) ;
return;
}
V_24 -> V_31 = F_82 ( V_22 -> V_241 ) ;
V_24 -> V_17 = V_286 ;
V_24 -> V_124 = 1 ;
return;
}
static int F_231 ( struct V_64 * V_64 , const char * V_63 )
{
const struct V_10 * V_10 = F_65 () ;
return F_116 ( V_10 , V_64 , V_515 ) ;
}
static int F_232 ( struct V_64 * V_64 )
{
const struct V_10 * V_10 = F_65 () ;
return F_116 ( V_10 , V_64 , V_515 ) ;
}
static int F_233 ( struct V_64 * V_64 , const char * V_63 )
{
if ( strcmp ( V_63 , V_75 ) )
return F_220 ( V_64 , V_63 ) ;
return - V_403 ;
}
static int F_234 ( const struct V_22 * V_22 , const char * V_63 , void * * V_231 , bool V_528 )
{
T_2 V_519 ;
int error ;
char * V_87 = NULL ;
struct V_23 * V_24 = V_22 -> V_33 ;
if ( strcmp ( V_63 , V_490 ) )
return - V_73 ;
error = F_144 ( F_65 () , & V_389 , V_521 ,
V_391 ) ;
if ( ! error )
error = F_203 ( V_24 -> V_17 , & V_87 ,
& V_519 ) ;
else
error = F_60 ( V_24 -> V_17 , & V_87 , & V_519 ) ;
if ( error )
return error ;
error = V_519 ;
if ( V_528 ) {
* V_231 = V_87 ;
goto V_529;
}
F_39 ( V_87 ) ;
V_529:
return error ;
}
static int F_235 ( struct V_22 * V_22 , const char * V_63 ,
const void * V_488 , T_7 V_519 , int V_79 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_286 ;
int V_53 ;
if ( strcmp ( V_63 , V_490 ) )
return - V_73 ;
if ( ! V_488 || ! V_519 )
return - V_403 ;
V_53 = F_67 ( ( void * ) V_488 , V_519 , & V_286 , V_15 ) ;
if ( V_53 )
return V_53 ;
V_24 -> V_31 = F_82 ( V_22 -> V_241 ) ;
V_24 -> V_17 = V_286 ;
V_24 -> V_124 = 1 ;
return 0 ;
}
static int F_236 ( struct V_22 * V_22 , char * V_231 , T_7 V_530 )
{
const int V_88 = sizeof( V_75 ) ;
if ( V_231 && V_88 <= V_530 )
memcpy ( V_231 , V_75 , V_88 ) ;
return V_88 ;
}
static void F_237 ( const struct V_22 * V_22 , T_2 * V_531 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
* V_531 = V_24 -> V_17 ;
}
static int F_238 ( struct V_42 * V_42 , int V_316 )
{
const struct V_10 * V_10 = F_65 () ;
struct V_22 * V_22 = F_119 ( V_42 ) ;
if ( ( V_42 -> V_330 & V_331 ) && ( V_316 & V_323 ) )
V_316 |= V_321 ;
return F_120 ( V_10 , V_42 ,
F_128 ( V_22 -> V_241 , V_316 ) ) ;
}
static int F_239 ( struct V_42 * V_42 , int V_316 )
{
struct V_22 * V_22 = F_119 ( V_42 ) ;
struct V_43 * V_44 = V_42 -> V_46 ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 = F_22 () ;
if ( ! V_316 )
return 0 ;
if ( V_17 == V_44 -> V_17 && V_44 -> V_532 == V_24 -> V_17 &&
V_44 -> V_533 == F_240 () )
return 0 ;
return F_238 ( V_42 , V_316 ) ;
}
static int F_241 ( struct V_42 * V_42 )
{
return F_37 ( V_42 ) ;
}
static void F_242 ( struct V_42 * V_42 )
{
F_38 ( V_42 ) ;
}
static int F_243 ( struct V_42 * V_42 , unsigned int V_534 ,
unsigned long V_535 )
{
const struct V_10 * V_10 = F_65 () ;
int error = 0 ;
switch ( V_534 ) {
case V_536 :
case V_537 :
case V_538 :
case V_539 :
case V_540 :
error = F_120 ( V_10 , V_42 , V_515 ) ;
break;
case V_541 :
case V_542 :
error = F_120 ( V_10 , V_42 , V_513 ) ;
break;
case V_543 :
case V_544 :
error = F_120 ( V_10 , V_42 , 0 ) ;
break;
case V_545 :
case V_546 :
error = F_107 ( V_10 , V_547 ,
V_275 ) ;
break;
default:
error = F_120 ( V_10 , V_42 , V_332 ) ;
}
return error ;
}
static int F_244 ( struct V_42 * V_42 , unsigned long V_548 , int V_549 )
{
const struct V_10 * V_10 = F_65 () ;
int V_53 = 0 ;
if ( V_550 &&
( V_548 & V_551 ) && ( ! V_42 || ( ! V_549 && ( V_548 & V_552 ) ) ) ) {
V_53 = F_104 ( V_10 , V_10 , V_553 ) ;
if ( V_53 )
goto error;
}
if ( V_42 ) {
T_2 V_270 = V_320 ;
if ( V_549 && ( V_548 & V_552 ) )
V_270 |= V_324 ;
if ( V_548 & V_551 )
V_270 |= V_318 ;
return F_120 ( V_10 , V_42 , V_270 ) ;
}
error:
return V_53 ;
}
static int F_245 ( unsigned long V_554 )
{
int V_53 ;
V_53 = F_246 ( V_554 ) ;
if ( V_53 )
return V_53 ;
if ( V_554 < V_555 ) {
T_2 V_17 = F_22 () ;
V_53 = F_46 ( V_17 , V_17 , V_556 ,
V_557 , NULL ) ;
}
return V_53 ;
}
static int F_247 ( struct V_42 * V_42 , unsigned long V_558 ,
unsigned long V_548 , unsigned long V_79 )
{
if ( V_559 )
V_548 = V_558 ;
return F_244 ( V_42 , V_548 ,
( V_79 & V_560 ) == V_561 ) ;
}
static int F_248 ( struct V_562 * V_563 ,
unsigned long V_558 ,
unsigned long V_548 )
{
const struct V_10 * V_10 = F_65 () ;
if ( V_559 )
V_548 = V_558 ;
if ( V_550 &&
( V_548 & V_551 ) && ! ( V_563 -> V_564 & V_565 ) ) {
int V_53 = 0 ;
if ( V_563 -> V_566 >= V_563 -> V_567 -> V_568 &&
V_563 -> V_569 <= V_563 -> V_567 -> V_570 ) {
V_53 = F_104 ( V_10 , V_10 , V_571 ) ;
} else if ( ! V_563 -> V_572 &&
V_563 -> V_566 <= V_563 -> V_567 -> V_573 &&
V_563 -> V_569 >= V_563 -> V_567 -> V_573 ) {
V_53 = F_106 ( V_11 , V_574 ) ;
} else if ( V_563 -> V_572 && V_563 -> V_575 ) {
V_53 = F_120 ( V_10 , V_563 -> V_572 , V_576 ) ;
}
if ( V_53 )
return V_53 ;
}
return F_244 ( V_563 -> V_572 , V_548 , V_563 -> V_564 & V_577 ) ;
}
static int F_249 ( struct V_42 * V_42 , unsigned int V_534 )
{
const struct V_10 * V_10 = F_65 () ;
return F_120 ( V_10 , V_42 , V_578 ) ;
}
static int F_250 ( struct V_42 * V_42 , unsigned int V_534 ,
unsigned long V_535 )
{
const struct V_10 * V_10 = F_65 () ;
int V_579 = 0 ;
switch ( V_534 ) {
case V_580 :
if ( ( V_42 -> V_330 & V_331 ) && ! ( V_535 & V_331 ) ) {
V_579 = F_120 ( V_10 , V_42 , V_324 ) ;
break;
}
case V_581 :
case V_582 :
case V_583 :
case V_584 :
case V_585 :
case V_586 :
V_579 = F_120 ( V_10 , V_42 , 0 ) ;
break;
case V_587 :
case V_588 :
case V_589 :
case V_590 :
case V_591 :
case V_592 :
#if V_593 == 32
case V_594 :
case V_595 :
case V_596 :
#endif
V_579 = F_120 ( V_10 , V_42 , V_578 ) ;
break;
}
return V_579 ;
}
static void F_251 ( struct V_42 * V_42 )
{
struct V_43 * V_44 ;
V_44 = V_42 -> V_46 ;
V_44 -> V_45 = F_22 () ;
}
static int F_252 ( struct V_20 * V_263 ,
struct V_597 * V_598 , int V_599 )
{
struct V_42 * V_42 ;
T_2 V_17 = F_18 ( V_263 ) ;
T_2 V_243 ;
struct V_43 * V_44 ;
V_42 = F_29 ( V_598 , struct V_42 , V_600 ) ;
V_44 = V_42 -> V_46 ;
if ( ! V_599 )
V_243 = F_103 ( V_601 ) ;
else
V_243 = F_103 ( V_599 ) ;
return F_46 ( V_44 -> V_45 , V_17 ,
V_256 , V_243 , NULL ) ;
}
static int F_253 ( struct V_42 * V_42 )
{
const struct V_10 * V_10 = F_65 () ;
return F_120 ( V_10 , V_42 , F_130 ( V_42 ) ) ;
}
static int F_254 ( struct V_42 * V_42 , const struct V_10 * V_10 )
{
struct V_43 * V_44 ;
struct V_23 * V_24 ;
V_44 = V_42 -> V_46 ;
V_24 = F_119 ( V_42 ) -> V_33 ;
V_44 -> V_532 = V_24 -> V_17 ;
V_44 -> V_533 = F_240 () ;
return F_118 ( V_10 , V_42 , F_131 ( V_42 ) ) ;
}
static int F_255 ( unsigned long V_602 )
{
return F_106 ( V_11 , V_603 ) ;
}
static int F_256 ( struct V_10 * V_10 , T_11 V_604 )
{
struct V_13 * V_14 ;
V_14 = F_15 ( sizeof( struct V_13 ) , V_604 ) ;
if ( ! V_14 )
return - V_27 ;
V_10 -> V_19 = V_14 ;
return 0 ;
}
static void F_257 ( struct V_10 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_19 ;
F_61 ( V_10 -> V_19 && ( unsigned long ) V_10 -> V_19 < V_233 ) ;
V_10 -> V_19 = ( void * ) 0x7UL ;
F_39 ( V_14 ) ;
}
static int F_258 ( struct V_10 * V_128 , const struct V_10 * V_127 ,
T_11 V_604 )
{
const struct V_13 * V_394 ;
struct V_13 * V_14 ;
V_394 = V_127 -> V_19 ;
V_14 = F_259 ( V_394 , sizeof( struct V_13 ) , V_604 ) ;
if ( ! V_14 )
return - V_27 ;
V_128 -> V_19 = V_14 ;
return 0 ;
}
static void F_260 ( struct V_10 * V_128 , const struct V_10 * V_127 )
{
const struct V_13 * V_394 = V_127 -> V_19 ;
struct V_13 * V_14 = V_128 -> V_19 ;
* V_14 = * V_394 ;
}
static int F_261 ( struct V_10 * V_128 , T_2 V_531 )
{
struct V_13 * V_14 = V_128 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_605 ;
V_605 = F_46 ( V_17 , V_531 ,
V_606 ,
V_607 ,
NULL ) ;
if ( V_605 == 0 ) {
V_14 -> V_17 = V_531 ;
V_14 -> V_287 = 0 ;
V_14 -> V_405 = 0 ;
V_14 -> V_406 = 0 ;
}
return V_605 ;
}
static int F_262 ( struct V_10 * V_128 , struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_13 * V_14 = V_128 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_605 ;
V_605 = F_46 ( V_17 , V_24 -> V_17 ,
V_606 ,
V_608 ,
NULL ) ;
if ( V_605 == 0 )
V_14 -> V_287 = V_24 -> V_17 ;
return V_605 ;
}
static int F_263 ( char * V_609 )
{
T_2 V_17 ;
struct V_266 V_267 ;
V_17 = F_18 ( V_11 ) ;
V_267 . type = V_610 ;
V_267 . V_272 . V_609 = V_609 ;
return F_46 ( V_17 , V_18 , V_277 ,
V_611 , & V_267 ) ;
}
static int F_264 ( struct V_20 * V_145 , T_12 V_612 )
{
return F_106 ( V_145 , V_613 ) ;
}
static int F_265 ( struct V_20 * V_145 )
{
return F_106 ( V_145 , V_614 ) ;
}
static int F_266 ( struct V_20 * V_145 )
{
return F_106 ( V_145 , V_615 ) ;
}
static void F_267 ( struct V_20 * V_145 , T_2 * V_531 )
{
* V_531 = F_18 ( V_145 ) ;
}
static int F_268 ( struct V_20 * V_145 , int V_616 )
{
int V_53 ;
V_53 = F_269 ( V_145 , V_616 ) ;
if ( V_53 )
return V_53 ;
return F_106 ( V_145 , V_617 ) ;
}
static int F_270 ( struct V_20 * V_145 , int V_618 )
{
int V_53 ;
V_53 = F_271 ( V_145 , V_618 ) ;
if ( V_53 )
return V_53 ;
return F_106 ( V_145 , V_617 ) ;
}
static int F_272 ( struct V_20 * V_145 )
{
return F_106 ( V_145 , V_619 ) ;
}
static int F_273 ( struct V_20 * V_145 , unsigned int V_620 ,
struct V_436 * V_621 )
{
struct V_436 * V_622 = V_145 -> signal -> V_437 + V_620 ;
if ( V_622 -> V_444 != V_621 -> V_444 )
return F_106 ( V_145 , V_623 ) ;
return 0 ;
}
static int F_274 ( struct V_20 * V_145 )
{
int V_53 ;
V_53 = F_275 ( V_145 ) ;
if ( V_53 )
return V_53 ;
return F_106 ( V_145 , V_617 ) ;
}
static int F_276 ( struct V_20 * V_145 )
{
return F_106 ( V_145 , V_619 ) ;
}
static int F_277 ( struct V_20 * V_145 )
{
return F_106 ( V_145 , V_617 ) ;
}
static int F_278 ( struct V_20 * V_145 , struct V_624 * V_625 ,
int V_242 , T_2 V_531 )
{
T_2 V_243 ;
int V_53 ;
if ( ! V_242 )
V_243 = V_626 ;
else
V_243 = F_103 ( V_242 ) ;
if ( V_531 )
V_53 = F_46 ( V_531 , F_18 ( V_145 ) ,
V_256 , V_243 , NULL ) ;
else
V_53 = F_106 ( V_145 , V_243 ) ;
return V_53 ;
}
static int F_279 ( struct V_20 * V_145 )
{
return F_105 ( V_145 , V_11 , V_245 ) ;
}
static void F_280 ( struct V_20 * V_145 ,
struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 = F_18 ( V_145 ) ;
V_24 -> V_17 = V_17 ;
V_24 -> V_124 = 1 ;
}
static int F_281 ( struct V_627 * V_628 ,
struct V_266 * V_267 , T_13 * V_629 )
{
int V_630 , V_631 , V_605 = - V_90 ;
struct V_632 V_633 , * V_634 ;
V_630 = F_282 ( V_628 ) ;
V_634 = F_283 ( V_628 , V_630 , sizeof( V_633 ) , & V_633 ) ;
if ( V_634 == NULL )
goto V_74;
V_631 = V_634 -> V_635 * 4 ;
if ( V_631 < sizeof( V_633 ) )
goto V_74;
V_267 -> V_272 . V_636 -> V_637 . V_638 = V_634 -> V_638 ;
V_267 -> V_272 . V_636 -> V_637 . V_639 = V_634 -> V_639 ;
V_605 = 0 ;
if ( V_629 )
* V_629 = V_634 -> V_183 ;
switch ( V_634 -> V_183 ) {
case V_185 : {
struct V_640 V_641 , * V_642 ;
if ( F_284 ( V_634 -> V_643 ) & V_644 )
break;
V_630 += V_631 ;
V_642 = F_283 ( V_628 , V_630 , sizeof( V_641 ) , & V_641 ) ;
if ( V_642 == NULL )
break;
V_267 -> V_272 . V_636 -> V_645 = V_642 -> V_646 ;
V_267 -> V_272 . V_636 -> V_647 = V_642 -> V_648 ;
break;
}
case V_186 : {
struct V_649 V_650 , * V_651 ;
if ( F_284 ( V_634 -> V_643 ) & V_644 )
break;
V_630 += V_631 ;
V_651 = F_283 ( V_628 , V_630 , sizeof( V_650 ) , & V_650 ) ;
if ( V_651 == NULL )
break;
V_267 -> V_272 . V_636 -> V_645 = V_651 -> V_646 ;
V_267 -> V_272 . V_636 -> V_647 = V_651 -> V_648 ;
break;
}
case V_652 : {
struct V_653 V_654 , * V_655 ;
if ( F_284 ( V_634 -> V_643 ) & V_644 )
break;
V_630 += V_631 ;
V_655 = F_283 ( V_628 , V_630 , sizeof( V_654 ) , & V_654 ) ;
if ( V_655 == NULL )
break;
V_267 -> V_272 . V_636 -> V_645 = V_655 -> V_656 ;
V_267 -> V_272 . V_636 -> V_647 = V_655 -> V_657 ;
break;
}
default:
break;
}
V_74:
return V_605 ;
}
static int F_285 ( struct V_627 * V_628 ,
struct V_266 * V_267 , T_13 * V_629 )
{
T_13 V_658 ;
int V_605 = - V_90 , V_630 ;
struct V_659 V_660 , * V_661 ;
T_14 V_643 ;
V_630 = F_282 ( V_628 ) ;
V_661 = F_283 ( V_628 , V_630 , sizeof( V_660 ) , & V_660 ) ;
if ( V_661 == NULL )
goto V_74;
V_267 -> V_272 . V_636 -> V_662 . V_638 = V_661 -> V_638 ;
V_267 -> V_272 . V_636 -> V_662 . V_639 = V_661 -> V_639 ;
V_605 = 0 ;
V_658 = V_661 -> V_658 ;
V_630 += sizeof( V_660 ) ;
V_630 = F_286 ( V_628 , V_630 , & V_658 , & V_643 ) ;
if ( V_630 < 0 )
goto V_74;
if ( V_629 )
* V_629 = V_658 ;
switch ( V_658 ) {
case V_185 : {
struct V_640 V_641 , * V_642 ;
V_642 = F_283 ( V_628 , V_630 , sizeof( V_641 ) , & V_641 ) ;
if ( V_642 == NULL )
break;
V_267 -> V_272 . V_636 -> V_645 = V_642 -> V_646 ;
V_267 -> V_272 . V_636 -> V_647 = V_642 -> V_648 ;
break;
}
case V_186 : {
struct V_649 V_650 , * V_651 ;
V_651 = F_283 ( V_628 , V_630 , sizeof( V_650 ) , & V_650 ) ;
if ( V_651 == NULL )
break;
V_267 -> V_272 . V_636 -> V_645 = V_651 -> V_646 ;
V_267 -> V_272 . V_636 -> V_647 = V_651 -> V_648 ;
break;
}
case V_652 : {
struct V_653 V_654 , * V_655 ;
V_655 = F_283 ( V_628 , V_630 , sizeof( V_654 ) , & V_654 ) ;
if ( V_655 == NULL )
break;
V_267 -> V_272 . V_636 -> V_645 = V_655 -> V_656 ;
V_267 -> V_272 . V_636 -> V_647 = V_655 -> V_657 ;
break;
}
default:
break;
}
V_74:
return V_605 ;
}
static int F_287 ( struct V_627 * V_628 , struct V_266 * V_267 ,
char * * V_663 , int V_664 , T_13 * V_629 )
{
char * V_665 ;
int V_605 ;
switch ( V_267 -> V_272 . V_636 -> V_187 ) {
case V_194 :
V_605 = F_281 ( V_628 , V_267 , V_629 ) ;
if ( V_605 )
goto V_666;
V_665 = ( char * ) ( V_664 ? & V_267 -> V_272 . V_636 -> V_637 . V_638 :
& V_267 -> V_272 . V_636 -> V_637 . V_639 ) ;
goto V_667;
#if F_288 ( V_668 ) || F_288 ( V_669 )
case V_195 :
V_605 = F_285 ( V_628 , V_267 , V_629 ) ;
if ( V_605 )
goto V_666;
V_665 = ( char * ) ( V_664 ? & V_267 -> V_272 . V_636 -> V_662 . V_638 :
& V_267 -> V_272 . V_636 -> V_662 . V_639 ) ;
goto V_667;
#endif
default:
V_665 = NULL ;
goto V_667;
}
V_666:
F_50 ( V_71
L_46
L_47 ) ;
return V_605 ;
V_667:
if ( V_663 )
* V_663 = V_665 ;
return 0 ;
}
static int F_289 ( struct V_627 * V_628 , T_4 V_187 , T_2 * V_17 )
{
int V_579 ;
T_2 V_670 ;
T_2 V_671 ;
T_2 V_672 ;
V_579 = F_290 ( V_628 , & V_670 ) ;
if ( F_115 ( V_579 ) )
return - V_403 ;
V_579 = F_291 ( V_628 , V_187 , & V_672 , & V_671 ) ;
if ( F_115 ( V_579 ) )
return - V_403 ;
V_579 = F_292 ( V_671 , V_672 , V_670 , V_17 ) ;
if ( F_115 ( V_579 ) ) {
F_50 ( V_71
L_48
L_49 ) ;
return - V_403 ;
}
return 0 ;
}
static int F_293 ( T_2 V_673 , T_2 V_674 , T_2 * V_675 )
{
int V_579 = 0 ;
if ( V_674 != V_676 )
V_579 = F_294 ( V_673 , V_674 , V_675 ) ;
else
* V_675 = V_673 ;
return V_579 ;
}
static int F_295 ( const struct V_13 * V_14 ,
T_4 V_677 , T_2 * V_678 )
{
if ( V_14 -> V_406 > V_676 ) {
* V_678 = V_14 -> V_406 ;
return 0 ;
}
return F_101 ( V_14 -> V_17 , V_14 -> V_17 , V_677 , NULL ,
V_678 ) ;
}
static int F_296 ( struct V_20 * V_21 , struct V_679 * V_680 , T_2 V_253 )
{
struct V_681 * V_682 = V_680 -> V_683 ;
struct V_266 V_267 ;
struct V_684 V_636 = { 0 ,} ;
T_2 V_255 = F_18 ( V_21 ) ;
if ( V_682 -> V_17 == V_18 )
return 0 ;
V_267 . type = V_685 ;
V_267 . V_272 . V_636 = & V_636 ;
V_267 . V_272 . V_636 -> V_680 = V_680 ;
return F_46 ( V_255 , V_682 -> V_17 , V_682 -> V_31 , V_253 , & V_267 ) ;
}
static int F_297 ( int V_187 , int type ,
int V_183 , int V_686 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_286 ;
T_4 V_677 ;
int V_53 ;
if ( V_686 )
return 0 ;
V_677 = F_85 ( V_187 , type , V_183 ) ;
V_53 = F_295 ( V_14 , V_677 , & V_286 ) ;
if ( V_53 )
return V_53 ;
return F_46 ( V_14 -> V_17 , V_286 , V_677 , V_687 , NULL ) ;
}
static int F_298 ( struct V_688 * V_679 , int V_187 ,
int type , int V_183 , int V_686 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_24 = F_299 ( V_679 ) -> V_33 ;
struct V_681 * V_682 ;
int V_579 = 0 ;
V_24 -> V_31 = F_85 ( V_187 , type , V_183 ) ;
if ( V_686 )
V_24 -> V_17 = V_18 ;
else {
V_579 = F_295 ( V_14 , V_24 -> V_31 , & ( V_24 -> V_17 ) ) ;
if ( V_579 )
return V_579 ;
}
V_24 -> V_124 = 1 ;
if ( V_679 -> V_680 ) {
V_682 = V_679 -> V_680 -> V_683 ;
V_682 -> V_17 = V_24 -> V_17 ;
V_682 -> V_31 = V_24 -> V_31 ;
V_579 = F_300 ( V_679 -> V_680 , V_187 ) ;
}
return V_579 ;
}
static int F_301 ( struct V_688 * V_679 , struct V_689 * V_690 , int V_691 )
{
struct V_679 * V_680 = V_679 -> V_680 ;
T_4 V_187 ;
int V_579 ;
V_579 = F_296 ( V_11 , V_680 , V_692 ) ;
if ( V_579 )
goto V_74;
V_187 = V_680 -> V_693 ;
if ( V_187 == V_194 || V_187 == V_195 ) {
char * V_665 ;
struct V_681 * V_682 = V_680 -> V_683 ;
struct V_266 V_267 ;
struct V_684 V_636 = { 0 ,} ;
struct V_694 * V_695 = NULL ;
struct V_696 * V_697 = NULL ;
unsigned short V_698 ;
T_2 V_17 , V_699 ;
if ( V_187 == V_194 ) {
V_695 = (struct V_694 * ) V_690 ;
V_698 = F_284 ( V_695 -> V_700 ) ;
V_665 = ( char * ) & V_695 -> V_701 . V_702 ;
} else {
V_697 = (struct V_696 * ) V_690 ;
V_698 = F_284 ( V_697 -> V_703 ) ;
V_665 = ( char * ) & V_697 -> V_704 . V_705 ;
}
if ( V_698 ) {
int V_706 , V_707 ;
F_302 ( F_303 ( V_680 ) , & V_706 , & V_707 ) ;
if ( V_698 < V_708 ( V_709, V_706 ) || V_698 > V_707 ) {
V_579 = F_304 ( V_680 -> V_710 ,
V_698 , & V_17 ) ;
if ( V_579 )
goto V_74;
V_267 . type = V_685 ;
V_267 . V_272 . V_636 = & V_636 ;
V_267 . V_272 . V_636 -> V_645 = F_305 ( V_698 ) ;
V_267 . V_272 . V_636 -> V_187 = V_187 ;
V_579 = F_46 ( V_682 -> V_17 , V_17 ,
V_682 -> V_31 ,
V_711 , & V_267 ) ;
if ( V_579 )
goto V_74;
}
}
switch ( V_682 -> V_31 ) {
case V_196 :
V_699 = V_712 ;
break;
case V_198 :
V_699 = V_713 ;
break;
case V_200 :
V_699 = V_714 ;
break;
default:
V_699 = V_715 ;
break;
}
V_579 = F_306 ( V_665 , V_187 , & V_17 ) ;
if ( V_579 )
goto V_74;
V_267 . type = V_685 ;
V_267 . V_272 . V_636 = & V_636 ;
V_267 . V_272 . V_636 -> V_645 = F_305 ( V_698 ) ;
V_267 . V_272 . V_636 -> V_187 = V_187 ;
if ( V_187 == V_194 )
V_267 . V_272 . V_636 -> V_637 . V_638 = V_695 -> V_701 . V_702 ;
else
V_267 . V_272 . V_636 -> V_662 . V_638 = V_697 -> V_704 ;
V_579 = F_46 ( V_682 -> V_17 , V_17 ,
V_682 -> V_31 , V_699 , & V_267 ) ;
if ( V_579 )
goto V_74;
}
V_74:
return V_579 ;
}
static int F_307 ( struct V_688 * V_679 , struct V_689 * V_690 , int V_691 )
{
struct V_679 * V_680 = V_679 -> V_680 ;
struct V_681 * V_682 = V_680 -> V_683 ;
int V_579 ;
V_579 = F_296 ( V_11 , V_680 , V_716 ) ;
if ( V_579 )
return V_579 ;
if ( V_682 -> V_31 == V_196 ||
V_682 -> V_31 == V_200 ) {
struct V_266 V_267 ;
struct V_684 V_636 = { 0 ,} ;
struct V_694 * V_695 = NULL ;
struct V_696 * V_697 = NULL ;
unsigned short V_698 ;
T_2 V_17 , V_243 ;
if ( V_680 -> V_693 == V_194 ) {
V_695 = (struct V_694 * ) V_690 ;
if ( V_691 < sizeof( struct V_694 ) )
return - V_90 ;
V_698 = F_284 ( V_695 -> V_700 ) ;
} else {
V_697 = (struct V_696 * ) V_690 ;
if ( V_691 < V_717 )
return - V_90 ;
V_698 = F_284 ( V_697 -> V_703 ) ;
}
V_579 = F_304 ( V_680 -> V_710 , V_698 , & V_17 ) ;
if ( V_579 )
goto V_74;
V_243 = ( V_682 -> V_31 == V_196 ) ?
V_718 : V_719 ;
V_267 . type = V_685 ;
V_267 . V_272 . V_636 = & V_636 ;
V_267 . V_272 . V_636 -> V_647 = F_305 ( V_698 ) ;
V_267 . V_272 . V_636 -> V_187 = V_680 -> V_693 ;
V_579 = F_46 ( V_682 -> V_17 , V_17 , V_682 -> V_31 , V_243 , & V_267 ) ;
if ( V_579 )
goto V_74;
}
V_579 = F_308 ( V_680 , V_690 ) ;
V_74:
return V_579 ;
}
static int F_309 ( struct V_688 * V_679 , int V_720 )
{
return F_296 ( V_11 , V_679 -> V_680 , V_721 ) ;
}
static int F_310 ( struct V_688 * V_679 , struct V_688 * V_722 )
{
int V_579 ;
struct V_23 * V_24 ;
struct V_23 * V_141 ;
V_579 = F_296 ( V_11 , V_679 -> V_680 , V_723 ) ;
if ( V_579 )
return V_579 ;
V_141 = F_299 ( V_722 ) -> V_33 ;
V_24 = F_299 ( V_679 ) -> V_33 ;
V_141 -> V_31 = V_24 -> V_31 ;
V_141 -> V_17 = V_24 -> V_17 ;
V_141 -> V_124 = 1 ;
return 0 ;
}
static int F_311 ( struct V_688 * V_679 , struct V_724 * V_725 ,
int V_519 )
{
return F_296 ( V_11 , V_679 -> V_680 , V_726 ) ;
}
static int F_312 ( struct V_688 * V_679 , struct V_724 * V_725 ,
int V_519 , int V_79 )
{
return F_296 ( V_11 , V_679 -> V_680 , V_727 ) ;
}
static int F_313 ( struct V_688 * V_679 )
{
return F_296 ( V_11 , V_679 -> V_680 , V_728 ) ;
}
static int F_314 ( struct V_688 * V_679 )
{
return F_296 ( V_11 , V_679 -> V_680 , V_728 ) ;
}
static int F_315 ( struct V_688 * V_679 , int V_729 , int V_730 )
{
int V_579 ;
V_579 = F_296 ( V_11 , V_679 -> V_680 , V_731 ) ;
if ( V_579 )
return V_579 ;
return F_316 ( V_679 , V_729 , V_730 ) ;
}
static int F_317 ( struct V_688 * V_679 , int V_729 ,
int V_730 )
{
return F_296 ( V_11 , V_679 -> V_680 , V_732 ) ;
}
static int F_318 ( struct V_688 * V_679 , int V_733 )
{
return F_296 ( V_11 , V_679 -> V_680 , V_734 ) ;
}
static int F_319 ( struct V_679 * V_679 ,
struct V_679 * V_735 ,
struct V_679 * V_736 )
{
struct V_681 * V_737 = V_679 -> V_683 ;
struct V_681 * V_738 = V_735 -> V_683 ;
struct V_681 * V_739 = V_736 -> V_683 ;
struct V_266 V_267 ;
struct V_684 V_636 = { 0 ,} ;
int V_579 ;
V_267 . type = V_685 ;
V_267 . V_272 . V_636 = & V_636 ;
V_267 . V_272 . V_636 -> V_680 = V_735 ;
V_579 = F_46 ( V_737 -> V_17 , V_738 -> V_17 ,
V_738 -> V_31 ,
V_740 , & V_267 ) ;
if ( V_579 )
return V_579 ;
V_739 -> V_741 = V_737 -> V_17 ;
V_579 = F_294 ( V_738 -> V_17 , V_737 -> V_17 ,
& V_739 -> V_17 ) ;
if ( V_579 )
return V_579 ;
V_737 -> V_741 = V_739 -> V_17 ;
return 0 ;
}
static int F_320 ( struct V_688 * V_679 ,
struct V_688 * V_735 )
{
struct V_681 * V_742 = V_679 -> V_680 -> V_683 ;
struct V_681 * V_743 = V_735 -> V_680 -> V_683 ;
struct V_266 V_267 ;
struct V_684 V_636 = { 0 ,} ;
V_267 . type = V_685 ;
V_267 . V_272 . V_636 = & V_636 ;
V_267 . V_272 . V_636 -> V_680 = V_735 -> V_680 ;
return F_46 ( V_742 -> V_17 , V_743 -> V_17 , V_743 -> V_31 , V_744 ,
& V_267 ) ;
}
static int F_321 ( struct V_636 * V_358 , int V_745 ,
char * V_665 , T_4 V_187 , T_2 V_741 ,
struct V_266 * V_267 )
{
int V_579 ;
T_2 V_746 ;
T_2 V_747 ;
V_579 = F_322 ( V_358 , V_745 , & V_746 ) ;
if ( V_579 )
return V_579 ;
V_579 = F_46 ( V_741 , V_746 ,
V_748 , V_749 , V_267 ) ;
if ( V_579 )
return V_579 ;
V_579 = F_306 ( V_665 , V_187 , & V_747 ) ;
if ( V_579 )
return V_579 ;
return F_46 ( V_741 , V_747 ,
V_750 , V_751 , V_267 ) ;
}
static int F_323 ( struct V_679 * V_680 , struct V_627 * V_628 ,
T_4 V_187 )
{
int V_579 = 0 ;
struct V_681 * V_682 = V_680 -> V_683 ;
T_2 V_673 = V_682 -> V_17 ;
struct V_266 V_267 ;
struct V_684 V_636 = { 0 ,} ;
char * V_665 ;
V_267 . type = V_685 ;
V_267 . V_272 . V_636 = & V_636 ;
V_267 . V_272 . V_636 -> V_752 = V_628 -> V_753 ;
V_267 . V_272 . V_636 -> V_187 = V_187 ;
V_579 = F_287 ( V_628 , & V_267 , & V_665 , 1 , NULL ) ;
if ( V_579 )
return V_579 ;
if ( F_4 () ) {
V_579 = F_46 ( V_673 , V_628 -> V_754 , V_755 ,
V_756 , & V_267 ) ;
if ( V_579 )
return V_579 ;
}
V_579 = F_324 ( V_682 , V_628 , V_187 , & V_267 ) ;
if ( V_579 )
return V_579 ;
V_579 = F_325 ( V_682 -> V_17 , V_628 , & V_267 ) ;
return V_579 ;
}
static int F_326 ( struct V_679 * V_680 , struct V_627 * V_628 )
{
int V_579 ;
struct V_681 * V_682 = V_680 -> V_683 ;
T_4 V_187 = V_680 -> V_693 ;
T_2 V_673 = V_682 -> V_17 ;
struct V_266 V_267 ;
struct V_684 V_636 = { 0 ,} ;
char * V_665 ;
T_13 V_757 ;
T_13 V_758 ;
if ( V_187 != V_194 && V_187 != V_195 )
return 0 ;
if ( V_187 == V_195 && V_628 -> V_183 == F_305 ( V_759 ) )
V_187 = V_194 ;
if ( ! V_760 )
return F_323 ( V_680 , V_628 , V_187 ) ;
V_757 = F_4 () ;
V_758 = F_6 () ;
if ( ! V_757 && ! V_758 )
return 0 ;
V_267 . type = V_685 ;
V_267 . V_272 . V_636 = & V_636 ;
V_267 . V_272 . V_636 -> V_752 = V_628 -> V_753 ;
V_267 . V_272 . V_636 -> V_187 = V_187 ;
V_579 = F_287 ( V_628 , & V_267 , & V_665 , 1 , NULL ) ;
if ( V_579 )
return V_579 ;
if ( V_758 ) {
T_2 V_741 ;
V_579 = F_289 ( V_628 , V_187 , & V_741 ) ;
if ( V_579 )
return V_579 ;
V_579 = F_321 ( F_303 ( V_680 ) , V_628 -> V_753 ,
V_665 , V_187 , V_741 , & V_267 ) ;
if ( V_579 ) {
F_327 ( V_628 , V_579 , 0 ) ;
return V_579 ;
}
V_579 = F_46 ( V_673 , V_741 , V_761 ,
V_762 , & V_267 ) ;
if ( V_579 ) {
F_327 ( V_628 , V_579 , 0 ) ;
return V_579 ;
}
}
if ( V_757 ) {
V_579 = F_46 ( V_673 , V_628 -> V_754 , V_755 ,
V_756 , & V_267 ) ;
if ( V_579 )
return V_579 ;
}
return V_579 ;
}
static int F_328 ( struct V_688 * V_679 , char T_15 * V_763 ,
int T_15 * V_764 , unsigned V_88 )
{
int V_579 = 0 ;
char * V_765 ;
T_2 V_766 ;
struct V_681 * V_682 = V_679 -> V_680 -> V_683 ;
T_2 V_741 = V_676 ;
if ( V_682 -> V_31 == V_191 ||
V_682 -> V_31 == V_196 )
V_741 = V_682 -> V_741 ;
if ( V_741 == V_676 )
return - V_767 ;
V_579 = F_60 ( V_741 , & V_765 , & V_766 ) ;
if ( V_579 )
return V_579 ;
if ( V_766 > V_88 ) {
V_579 = - V_236 ;
goto V_768;
}
if ( F_329 ( V_763 , V_765 , V_766 ) )
V_579 = - V_769 ;
V_768:
if ( F_330 ( V_766 , V_764 ) )
V_579 = - V_769 ;
F_39 ( V_765 ) ;
return V_579 ;
}
static int F_331 ( struct V_688 * V_679 , struct V_627 * V_628 , T_2 * V_531 )
{
T_2 V_770 = V_676 ;
T_4 V_187 ;
if ( V_628 && V_628 -> V_183 == F_305 ( V_759 ) )
V_187 = V_194 ;
else if ( V_628 && V_628 -> V_183 == F_305 ( V_771 ) )
V_187 = V_195 ;
else if ( V_679 )
V_187 = V_679 -> V_680 -> V_693 ;
else
goto V_74;
if ( V_679 && V_187 == V_188 )
F_237 ( F_299 ( V_679 ) , & V_770 ) ;
else if ( V_628 )
F_289 ( V_628 , V_187 , & V_770 ) ;
V_74:
* V_531 = V_770 ;
if ( V_770 == V_676 )
return - V_90 ;
return 0 ;
}
static int F_332 ( struct V_679 * V_680 , int V_187 , T_11 V_772 )
{
struct V_681 * V_682 ;
V_682 = F_15 ( sizeof( * V_682 ) , V_772 ) ;
if ( ! V_682 )
return - V_27 ;
V_682 -> V_741 = V_30 ;
V_682 -> V_17 = V_30 ;
F_333 ( V_682 ) ;
V_680 -> V_683 = V_682 ;
return 0 ;
}
static void F_334 ( struct V_679 * V_680 )
{
struct V_681 * V_682 = V_680 -> V_683 ;
V_680 -> V_683 = NULL ;
F_335 ( V_682 ) ;
F_39 ( V_682 ) ;
}
static void F_336 ( const struct V_679 * V_680 , struct V_679 * V_736 )
{
struct V_681 * V_682 = V_680 -> V_683 ;
struct V_681 * V_773 = V_736 -> V_683 ;
V_773 -> V_17 = V_682 -> V_17 ;
V_773 -> V_741 = V_682 -> V_741 ;
V_773 -> V_31 = V_682 -> V_31 ;
F_333 ( V_773 ) ;
}
static void F_337 ( struct V_679 * V_680 , T_2 * V_531 )
{
if ( ! V_680 )
* V_531 = V_774 ;
else {
struct V_681 * V_682 = V_680 -> V_683 ;
* V_531 = V_682 -> V_17 ;
}
}
static void F_338 ( struct V_679 * V_680 , struct V_688 * V_351 )
{
struct V_23 * V_24 = F_299 ( V_351 ) -> V_33 ;
struct V_681 * V_682 = V_680 -> V_683 ;
if ( V_680 -> V_693 == V_194 || V_680 -> V_693 == V_195 ||
V_680 -> V_693 == V_188 )
V_24 -> V_17 = V_682 -> V_17 ;
V_682 -> V_31 = V_24 -> V_31 ;
}
static int F_339 ( struct V_679 * V_680 , struct V_627 * V_628 ,
struct V_775 * V_776 )
{
struct V_681 * V_682 = V_680 -> V_683 ;
int V_579 ;
T_4 V_187 = V_776 -> V_777 -> V_187 ;
T_2 V_778 ;
T_2 V_779 ;
V_579 = F_289 ( V_628 , V_187 , & V_779 ) ;
if ( V_579 )
return V_579 ;
V_579 = F_293 ( V_682 -> V_17 , V_779 , & V_778 ) ;
if ( V_579 )
return V_579 ;
V_776 -> V_531 = V_778 ;
V_776 -> V_770 = V_779 ;
return F_340 ( V_776 , V_187 ) ;
}
static void F_341 ( struct V_679 * V_736 ,
const struct V_775 * V_776 )
{
struct V_681 * V_773 = V_736 -> V_683 ;
V_773 -> V_17 = V_776 -> V_531 ;
V_773 -> V_741 = V_776 -> V_770 ;
F_342 ( V_736 , V_776 -> V_777 -> V_187 ) ;
}
static void F_343 ( struct V_679 * V_680 , struct V_627 * V_628 )
{
T_4 V_187 = V_680 -> V_693 ;
struct V_681 * V_682 = V_680 -> V_683 ;
if ( V_187 == V_195 && V_628 -> V_183 == F_305 ( V_759 ) )
V_187 = V_194 ;
F_289 ( V_628 , V_187 , & V_682 -> V_741 ) ;
}
static void F_344 ( struct V_627 * V_628 , struct V_679 * V_680 )
{
F_345 ( V_628 , V_680 ) ;
}
static int F_346 ( T_2 V_17 )
{
const struct V_13 * V_780 ;
T_2 V_255 ;
V_780 = F_23 () ;
V_255 = V_780 -> V_17 ;
return F_46 ( V_255 , V_17 , V_755 , V_781 , NULL ) ;
}
static void F_347 ( void )
{
F_348 ( & V_7 ) ;
}
static void F_349 ( void )
{
F_350 ( & V_7 ) ;
}
static void F_351 ( const struct V_775 * V_776 ,
struct V_782 * V_783 )
{
V_783 -> V_784 = V_776 -> V_531 ;
}
static int F_352 ( void * * V_19 )
{
struct V_785 * V_786 ;
V_786 = F_15 ( sizeof( * V_786 ) , V_15 ) ;
if ( ! V_786 )
return - V_27 ;
V_786 -> V_17 = F_22 () ;
* V_19 = V_786 ;
return 0 ;
}
static void F_353 ( void * V_19 )
{
F_39 ( V_19 ) ;
}
static int F_354 ( void )
{
T_2 V_17 = F_22 () ;
return F_46 ( V_17 , V_17 , V_787 , V_788 ,
NULL ) ;
}
static int F_355 ( void * V_19 )
{
struct V_785 * V_786 = V_19 ;
return F_46 ( F_22 () , V_786 -> V_17 , V_787 ,
V_789 , NULL ) ;
}
static int F_356 ( struct V_679 * V_680 , void * V_19 )
{
struct V_785 * V_786 = V_19 ;
struct V_681 * V_682 = V_680 -> V_683 ;
V_682 -> V_17 = V_786 -> V_17 ;
V_682 -> V_31 = V_787 ;
return 0 ;
}
static int F_357 ( void * V_19 )
{
struct V_785 * V_786 = V_19 ;
T_2 V_17 = F_22 () ;
int V_579 ;
V_579 = F_46 ( V_17 , V_786 -> V_17 , V_787 ,
V_790 , NULL ) ;
if ( V_579 )
return V_579 ;
V_579 = F_46 ( V_17 , V_17 , V_787 ,
V_791 , NULL ) ;
if ( V_579 )
return V_579 ;
V_786 -> V_17 = V_17 ;
return 0 ;
}
static int F_358 ( struct V_679 * V_680 , struct V_627 * V_628 )
{
int V_579 = 0 ;
T_2 V_243 ;
struct V_792 * V_793 ;
struct V_681 * V_682 = V_680 -> V_683 ;
if ( V_628 -> V_88 < V_794 ) {
V_579 = - V_90 ;
goto V_74;
}
V_793 = F_359 ( V_628 ) ;
V_579 = F_360 ( V_682 -> V_31 , V_793 -> V_795 , & V_243 ) ;
if ( V_579 ) {
if ( V_579 == - V_90 ) {
F_50 ( V_71
L_50
L_51 ,
V_680 -> V_710 , V_793 -> V_795 , V_682 -> V_31 ) ;
if ( ! V_3 || F_361 () )
V_579 = 0 ;
}
if ( V_579 == - V_796 )
V_579 = 0 ;
goto V_74;
}
V_579 = F_296 ( V_11 , V_680 , V_243 ) ;
V_74:
return V_579 ;
}
static unsigned int F_362 ( struct V_627 * V_628 ,
const struct V_797 * V_798 ,
T_4 V_187 )
{
int V_579 ;
char * V_665 ;
T_2 V_741 ;
struct V_266 V_267 ;
struct V_684 V_636 = { 0 ,} ;
T_13 V_757 ;
T_13 V_799 ;
T_13 V_758 ;
if ( ! V_760 )
return V_800 ;
V_757 = F_4 () ;
V_799 = F_7 () ;
V_758 = F_6 () ;
if ( ! V_757 && ! V_758 )
return V_800 ;
if ( F_289 ( V_628 , V_187 , & V_741 ) != 0 )
return V_801 ;
V_267 . type = V_685 ;
V_267 . V_272 . V_636 = & V_636 ;
V_267 . V_272 . V_636 -> V_752 = V_798 -> V_745 ;
V_267 . V_272 . V_636 -> V_187 = V_187 ;
if ( F_287 ( V_628 , & V_267 , & V_665 , 1 , NULL ) != 0 )
return V_801 ;
if ( V_758 ) {
V_579 = F_321 ( F_363 ( V_798 ) , V_798 -> V_745 ,
V_665 , V_187 , V_741 , & V_267 ) ;
if ( V_579 ) {
F_327 ( V_628 , V_579 , 1 ) ;
return V_801 ;
}
}
if ( V_757 )
if ( F_46 ( V_741 , V_628 -> V_754 ,
V_755 , V_802 , & V_267 ) )
return V_801 ;
if ( V_799 )
if ( F_364 ( V_628 , V_187 , V_741 ) != 0 )
return V_801 ;
return V_800 ;
}
static unsigned int F_365 ( const struct V_803 * V_804 ,
struct V_627 * V_628 ,
const struct V_797 * V_805 ,
const struct V_797 * V_74 ,
int (* F_366)( struct V_627 * ) )
{
return F_362 ( V_628 , V_805 , V_194 ) ;
}
static unsigned int F_367 ( const struct V_803 * V_804 ,
struct V_627 * V_628 ,
const struct V_797 * V_805 ,
const struct V_797 * V_74 ,
int (* F_366)( struct V_627 * ) )
{
return F_362 ( V_628 , V_805 , V_195 ) ;
}
static unsigned int F_368 ( struct V_627 * V_628 ,
T_4 V_187 )
{
struct V_679 * V_680 ;
T_2 V_17 ;
if ( ! F_7 () )
return V_800 ;
V_680 = V_628 -> V_680 ;
if ( V_680 ) {
struct V_681 * V_682 ;
if ( V_680 -> V_806 == V_807 )
return V_800 ;
V_682 = V_680 -> V_683 ;
V_17 = V_682 -> V_17 ;
} else
V_17 = V_18 ;
if ( F_364 ( V_628 , V_187 , V_17 ) != 0 )
return V_801 ;
return V_800 ;
}
static unsigned int F_369 ( const struct V_803 * V_804 ,
struct V_627 * V_628 ,
const struct V_797 * V_805 ,
const struct V_797 * V_74 ,
int (* F_366)( struct V_627 * ) )
{
return F_368 ( V_628 , V_194 ) ;
}
static unsigned int F_370 ( struct V_627 * V_628 ,
int V_745 ,
T_4 V_187 )
{
struct V_679 * V_680 = V_628 -> V_680 ;
struct V_681 * V_682 ;
struct V_266 V_267 ;
struct V_684 V_636 = { 0 ,} ;
char * V_665 ;
T_13 V_629 ;
if ( V_680 == NULL )
return V_800 ;
V_682 = V_680 -> V_683 ;
V_267 . type = V_685 ;
V_267 . V_272 . V_636 = & V_636 ;
V_267 . V_272 . V_636 -> V_752 = V_745 ;
V_267 . V_272 . V_636 -> V_187 = V_187 ;
if ( F_287 ( V_628 , & V_267 , & V_665 , 0 , & V_629 ) )
return V_801 ;
if ( F_4 () )
if ( F_46 ( V_682 -> V_17 , V_628 -> V_754 ,
V_755 , V_808 , & V_267 ) )
return F_371 ( - V_809 ) ;
if ( F_372 ( V_682 -> V_17 , V_628 , & V_267 , V_629 ) )
return F_371 ( - V_809 ) ;
return V_800 ;
}
static unsigned int F_373 ( struct V_627 * V_628 ,
const struct V_797 * V_810 ,
T_4 V_187 )
{
T_2 V_811 ;
T_2 V_741 ;
int V_745 = V_810 -> V_745 ;
struct V_679 * V_680 ;
struct V_266 V_267 ;
struct V_684 V_636 = { 0 ,} ;
char * V_665 ;
T_13 V_757 ;
T_13 V_758 ;
if ( ! V_760 )
return F_370 ( V_628 , V_745 , V_187 ) ;
V_757 = F_4 () ;
V_758 = F_6 () ;
if ( ! V_757 && ! V_758 )
return V_800 ;
V_680 = V_628 -> V_680 ;
#ifdef F_374
if ( F_375 ( V_628 ) != NULL && F_375 ( V_628 ) -> V_812 != NULL &&
! ( V_680 != NULL && V_680 -> V_806 == V_807 ) )
return V_800 ;
#endif
if ( V_680 == NULL ) {
if ( V_628 -> V_753 ) {
V_811 = V_813 ;
if ( F_289 ( V_628 , V_187 , & V_741 ) )
return V_801 ;
} else {
V_811 = V_808 ;
V_741 = V_18 ;
}
} else if ( V_680 -> V_806 == V_807 ) {
T_2 V_674 ;
struct V_681 * V_682 = V_680 -> V_683 ;
if ( F_289 ( V_628 , V_187 , & V_674 ) )
return V_801 ;
if ( V_674 == V_676 ) {
switch ( V_187 ) {
case V_194 :
if ( F_376 ( V_628 ) -> V_79 & V_814 )
return V_800 ;
break;
case V_195 :
if ( F_377 ( V_628 ) -> V_79 & V_815 )
return V_800 ;
break;
default:
return F_371 ( - V_809 ) ;
}
}
if ( F_293 ( V_682 -> V_17 , V_674 , & V_741 ) )
return V_801 ;
V_811 = V_808 ;
} else {
struct V_681 * V_682 = V_680 -> V_683 ;
V_741 = V_682 -> V_17 ;
V_811 = V_808 ;
}
V_267 . type = V_685 ;
V_267 . V_272 . V_636 = & V_636 ;
V_267 . V_272 . V_636 -> V_752 = V_745 ;
V_267 . V_272 . V_636 -> V_187 = V_187 ;
if ( F_287 ( V_628 , & V_267 , & V_665 , 0 , NULL ) )
return V_801 ;
if ( V_757 )
if ( F_46 ( V_741 , V_628 -> V_754 ,
V_755 , V_811 , & V_267 ) )
return F_371 ( - V_809 ) ;
if ( V_758 ) {
T_2 V_746 ;
T_2 V_747 ;
if ( F_322 ( F_363 ( V_810 ) , V_745 , & V_746 ) )
return V_801 ;
if ( F_46 ( V_741 , V_746 ,
V_748 , V_816 , & V_267 ) )
return F_371 ( - V_809 ) ;
if ( F_306 ( V_665 , V_187 , & V_747 ) )
return V_801 ;
if ( F_46 ( V_741 , V_747 ,
V_750 , V_817 , & V_267 ) )
return F_371 ( - V_809 ) ;
}
return V_800 ;
}
static unsigned int F_378 ( const struct V_803 * V_804 ,
struct V_627 * V_628 ,
const struct V_797 * V_805 ,
const struct V_797 * V_74 ,
int (* F_366)( struct V_627 * ) )
{
return F_373 ( V_628 , V_74 , V_194 ) ;
}
static unsigned int F_379 ( const struct V_803 * V_804 ,
struct V_627 * V_628 ,
const struct V_797 * V_805 ,
const struct V_797 * V_74 ,
int (* F_366)( struct V_627 * ) )
{
return F_373 ( V_628 , V_74 , V_195 ) ;
}
static int F_380 ( struct V_679 * V_680 , struct V_627 * V_628 )
{
int V_579 ;
V_579 = F_381 ( V_680 , V_628 ) ;
if ( V_579 )
return V_579 ;
return F_358 ( V_680 , V_628 ) ;
}
static int F_382 ( struct V_20 * V_21 ,
struct V_818 * V_243 ,
T_4 V_31 )
{
struct V_819 * V_24 ;
T_2 V_17 ;
V_24 = F_15 ( sizeof( struct V_819 ) , V_15 ) ;
if ( ! V_24 )
return - V_27 ;
V_17 = F_18 ( V_21 ) ;
V_24 -> V_31 = V_31 ;
V_24 -> V_17 = V_17 ;
V_243 -> V_19 = V_24 ;
return 0 ;
}
static void F_383 ( struct V_818 * V_243 )
{
struct V_819 * V_24 = V_243 -> V_19 ;
V_243 -> V_19 = NULL ;
F_39 ( V_24 ) ;
}
static int F_384 ( struct V_820 * V_725 )
{
struct V_821 * V_822 ;
V_822 = F_15 ( sizeof( struct V_821 ) , V_15 ) ;
if ( ! V_822 )
return - V_27 ;
V_822 -> V_17 = V_30 ;
V_725 -> V_19 = V_822 ;
return 0 ;
}
static void F_385 ( struct V_820 * V_725 )
{
struct V_821 * V_822 = V_725 -> V_19 ;
V_725 -> V_19 = NULL ;
F_39 ( V_822 ) ;
}
static int F_386 ( struct V_818 * V_823 ,
T_2 V_253 )
{
struct V_819 * V_24 ;
struct V_266 V_267 ;
T_2 V_17 = F_22 () ;
V_24 = V_823 -> V_19 ;
V_267 . type = V_824 ;
V_267 . V_272 . V_825 = V_823 -> V_826 ;
return F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_253 , & V_267 ) ;
}
static int F_387 ( struct V_820 * V_725 )
{
return F_384 ( V_725 ) ;
}
static void F_388 ( struct V_820 * V_725 )
{
F_385 ( V_725 ) ;
}
static int F_389 ( struct V_827 * V_828 )
{
struct V_819 * V_24 ;
struct V_266 V_267 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_53 = F_382 ( V_11 , & V_828 -> V_829 , V_830 ) ;
if ( V_53 )
return V_53 ;
V_24 = V_828 -> V_829 . V_19 ;
V_267 . type = V_824 ;
V_267 . V_272 . V_825 = V_828 -> V_829 . V_826 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_830 ,
V_831 , & V_267 ) ;
if ( V_53 ) {
F_383 ( & V_828 -> V_829 ) ;
return V_53 ;
}
return 0 ;
}
static void F_390 ( struct V_827 * V_828 )
{
F_383 ( & V_828 -> V_829 ) ;
}
static int F_391 ( struct V_827 * V_828 , int V_832 )
{
struct V_819 * V_24 ;
struct V_266 V_267 ;
T_2 V_17 = F_22 () ;
V_24 = V_828 -> V_829 . V_19 ;
V_267 . type = V_824 ;
V_267 . V_272 . V_825 = V_828 -> V_829 . V_826 ;
return F_46 ( V_17 , V_24 -> V_17 , V_830 ,
V_833 , & V_267 ) ;
}
static int F_392 ( struct V_827 * V_828 , int V_534 )
{
int V_579 ;
int V_253 ;
switch ( V_534 ) {
case V_834 :
case V_835 :
return F_112 ( V_11 , V_836 ) ;
case V_837 :
case V_838 :
V_253 = V_839 | V_833 ;
break;
case V_840 :
V_253 = V_841 ;
break;
case V_842 :
V_253 = V_843 ;
break;
default:
return 0 ;
}
V_579 = F_386 ( & V_828 -> V_829 , V_253 ) ;
return V_579 ;
}
static int F_393 ( struct V_827 * V_828 , struct V_820 * V_725 , int V_832 )
{
struct V_819 * V_24 ;
struct V_821 * V_822 ;
struct V_266 V_267 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_24 = V_828 -> V_829 . V_19 ;
V_822 = V_725 -> V_19 ;
if ( V_822 -> V_17 == V_30 ) {
V_53 = F_101 ( V_17 , V_24 -> V_17 , V_844 ,
NULL , & V_822 -> V_17 ) ;
if ( V_53 )
return V_53 ;
}
V_267 . type = V_824 ;
V_267 . V_272 . V_825 = V_828 -> V_829 . V_826 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_830 ,
V_845 , & V_267 ) ;
if ( ! V_53 )
V_53 = F_46 ( V_17 , V_822 -> V_17 , V_844 ,
V_846 , & V_267 ) ;
if ( ! V_53 )
V_53 = F_46 ( V_822 -> V_17 , V_24 -> V_17 , V_830 ,
V_847 , & V_267 ) ;
return V_53 ;
}
static int F_394 ( struct V_827 * V_828 , struct V_820 * V_725 ,
struct V_20 * V_252 ,
long type , int V_168 )
{
struct V_819 * V_24 ;
struct V_821 * V_822 ;
struct V_266 V_267 ;
T_2 V_17 = F_18 ( V_252 ) ;
int V_53 ;
V_24 = V_828 -> V_829 . V_19 ;
V_822 = V_725 -> V_19 ;
V_267 . type = V_824 ;
V_267 . V_272 . V_825 = V_828 -> V_829 . V_826 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 ,
V_830 , V_848 , & V_267 ) ;
if ( ! V_53 )
V_53 = F_46 ( V_17 , V_822 -> V_17 ,
V_844 , V_849 , & V_267 ) ;
return V_53 ;
}
static int F_395 ( struct V_850 * V_851 )
{
struct V_819 * V_24 ;
struct V_266 V_267 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_53 = F_382 ( V_11 , & V_851 -> V_852 , V_853 ) ;
if ( V_53 )
return V_53 ;
V_24 = V_851 -> V_852 . V_19 ;
V_267 . type = V_824 ;
V_267 . V_272 . V_825 = V_851 -> V_852 . V_826 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_853 ,
V_854 , & V_267 ) ;
if ( V_53 ) {
F_383 ( & V_851 -> V_852 ) ;
return V_53 ;
}
return 0 ;
}
static void F_396 ( struct V_850 * V_851 )
{
F_383 ( & V_851 -> V_852 ) ;
}
static int F_397 ( struct V_850 * V_851 , int V_855 )
{
struct V_819 * V_24 ;
struct V_266 V_267 ;
T_2 V_17 = F_22 () ;
V_24 = V_851 -> V_852 . V_19 ;
V_267 . type = V_824 ;
V_267 . V_272 . V_825 = V_851 -> V_852 . V_826 ;
return F_46 ( V_17 , V_24 -> V_17 , V_853 ,
V_856 , & V_267 ) ;
}
static int F_398 ( struct V_850 * V_851 , int V_534 )
{
int V_253 ;
int V_579 ;
switch ( V_534 ) {
case V_834 :
case V_857 :
return F_112 ( V_11 , V_836 ) ;
case V_837 :
case V_858 :
V_253 = V_859 | V_856 ;
break;
case V_840 :
V_253 = V_860 ;
break;
case V_861 :
case V_862 :
V_253 = V_863 ;
break;
case V_842 :
V_253 = V_864 ;
break;
default:
return 0 ;
}
V_579 = F_386 ( & V_851 -> V_852 , V_253 ) ;
return V_579 ;
}
static int F_399 ( struct V_850 * V_851 ,
char T_15 * V_865 , int V_855 )
{
T_2 V_253 ;
if ( V_855 & V_866 )
V_253 = V_867 ;
else
V_253 = V_867 | V_868 ;
return F_386 ( & V_851 -> V_852 , V_253 ) ;
}
static int F_400 ( struct V_869 * V_870 )
{
struct V_819 * V_24 ;
struct V_266 V_267 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_53 = F_382 ( V_11 , & V_870 -> V_871 , V_872 ) ;
if ( V_53 )
return V_53 ;
V_24 = V_870 -> V_871 . V_19 ;
V_267 . type = V_824 ;
V_267 . V_272 . V_825 = V_870 -> V_871 . V_826 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_872 ,
V_873 , & V_267 ) ;
if ( V_53 ) {
F_383 ( & V_870 -> V_871 ) ;
return V_53 ;
}
return 0 ;
}
static void F_401 ( struct V_869 * V_870 )
{
F_383 ( & V_870 -> V_871 ) ;
}
static int F_402 ( struct V_869 * V_870 , int V_874 )
{
struct V_819 * V_24 ;
struct V_266 V_267 ;
T_2 V_17 = F_22 () ;
V_24 = V_870 -> V_871 . V_19 ;
V_267 . type = V_824 ;
V_267 . V_272 . V_825 = V_870 -> V_871 . V_826 ;
return F_46 ( V_17 , V_24 -> V_17 , V_872 ,
V_875 , & V_267 ) ;
}
static int F_403 ( struct V_869 * V_870 , int V_534 )
{
int V_579 ;
T_2 V_253 ;
switch ( V_534 ) {
case V_834 :
case V_876 :
return F_112 ( V_11 , V_836 ) ;
case V_877 :
case V_878 :
case V_879 :
V_253 = V_880 ;
break;
case V_881 :
case V_882 :
V_253 = V_883 ;
break;
case V_884 :
case V_885 :
V_253 = V_886 ;
break;
case V_842 :
V_253 = V_887 ;
break;
case V_840 :
V_253 = V_888 ;
break;
case V_837 :
case V_889 :
V_253 = V_880 | V_875 ;
break;
default:
return 0 ;
}
V_579 = F_386 ( & V_870 -> V_871 , V_253 ) ;
return V_579 ;
}
static int F_404 ( struct V_869 * V_870 ,
struct V_890 * V_891 , unsigned V_892 , int V_893 )
{
T_2 V_253 ;
if ( V_893 )
V_253 = V_883 | V_886 ;
else
V_253 = V_883 ;
return F_386 ( & V_870 -> V_871 , V_253 ) ;
}
static int F_405 ( struct V_818 * V_894 , short V_103 )
{
T_2 V_270 = 0 ;
V_270 = 0 ;
if ( V_103 & V_895 )
V_270 |= V_896 ;
if ( V_103 & V_897 )
V_270 |= V_898 ;
if ( V_270 == 0 )
return 0 ;
return F_386 ( V_894 , V_270 ) ;
}
static void F_406 ( struct V_818 * V_894 , T_2 * V_531 )
{
struct V_819 * V_24 = V_894 -> V_19 ;
* V_531 = V_24 -> V_17 ;
}
static void F_407 ( struct V_64 * V_64 , struct V_22 * V_22 )
{
if ( V_22 )
F_44 ( V_22 , V_64 ) ;
}
static int F_408 ( struct V_20 * V_145 ,
char * V_63 , char * * V_488 )
{
const struct V_13 * V_780 ;
T_2 V_17 ;
int error ;
unsigned V_88 ;
if ( V_11 != V_145 ) {
error = F_106 ( V_145 , V_899 ) ;
if ( error )
return error ;
}
F_19 () ;
V_780 = F_20 ( V_145 ) -> V_19 ;
if ( ! strcmp ( V_63 , L_52 ) )
V_17 = V_780 -> V_17 ;
else if ( ! strcmp ( V_63 , L_53 ) )
V_17 = V_780 -> V_16 ;
else if ( ! strcmp ( V_63 , L_54 ) )
V_17 = V_780 -> V_407 ;
else if ( ! strcmp ( V_63 , L_55 ) )
V_17 = V_780 -> V_287 ;
else if ( ! strcmp ( V_63 , L_56 ) )
V_17 = V_780 -> V_405 ;
else if ( ! strcmp ( V_63 , L_57 ) )
V_17 = V_780 -> V_406 ;
else
goto V_900;
F_21 () ;
if ( ! V_17 )
return 0 ;
error = F_60 ( V_17 , V_488 , & V_88 ) ;
if ( error )
return error ;
return V_88 ;
V_900:
F_21 () ;
return - V_90 ;
}
static int F_409 ( struct V_20 * V_145 ,
char * V_63 , void * V_488 , T_7 V_519 )
{
struct V_13 * V_14 ;
struct V_20 * V_415 ;
struct V_10 * V_128 ;
T_2 V_17 = 0 , V_417 ;
int error ;
char * V_1 = V_488 ;
if ( V_11 != V_145 ) {
return - V_403 ;
}
if ( ! strcmp ( V_63 , L_54 ) )
error = F_106 ( V_145 , V_901 ) ;
else if ( ! strcmp ( V_63 , L_55 ) )
error = F_106 ( V_145 , V_902 ) ;
else if ( ! strcmp ( V_63 , L_56 ) )
error = F_106 ( V_145 , V_903 ) ;
else if ( ! strcmp ( V_63 , L_57 ) )
error = F_106 ( V_145 , V_904 ) ;
else if ( ! strcmp ( V_63 , L_52 ) )
error = F_106 ( V_145 , V_905 ) ;
else
error = - V_90 ;
if ( error )
return error ;
if ( V_519 && V_1 [ 1 ] && V_1 [ 1 ] != '\n' ) {
if ( V_1 [ V_519 - 1 ] == '\n' ) {
V_1 [ V_519 - 1 ] = 0 ;
V_519 -- ;
}
error = F_67 ( V_488 , V_519 , & V_17 , V_15 ) ;
if ( error == - V_90 && ! strcmp ( V_63 , L_55 ) ) {
if ( ! F_221 ( V_521 ) ) {
struct V_522 * V_523 ;
T_7 V_524 ;
if ( V_1 [ V_519 - 1 ] == '\0' )
V_524 = V_519 - 1 ;
else
V_524 = V_519 ;
V_523 = F_224 ( V_11 -> V_525 , V_96 , V_526 ) ;
F_225 ( V_523 , L_58 ) ;
F_226 ( V_523 , V_488 , V_524 ) ;
F_227 ( V_523 ) ;
return error ;
}
error = F_228 ( V_488 , V_519 ,
& V_17 ) ;
}
if ( error )
return error ;
}
V_128 = F_410 () ;
if ( ! V_128 )
return - V_27 ;
V_14 = V_128 -> V_19 ;
if ( ! strcmp ( V_63 , L_54 ) ) {
V_14 -> V_407 = V_17 ;
} else if ( ! strcmp ( V_63 , L_55 ) ) {
V_14 -> V_287 = V_17 ;
} else if ( ! strcmp ( V_63 , L_56 ) ) {
error = F_122 ( V_17 , V_145 ) ;
if ( error )
goto V_906;
V_14 -> V_405 = V_17 ;
} else if ( ! strcmp ( V_63 , L_57 ) ) {
V_14 -> V_406 = V_17 ;
} else if ( ! strcmp ( V_63 , L_52 ) ) {
error = - V_90 ;
if ( V_17 == 0 )
goto V_906;
error = - V_402 ;
if ( ! F_411 () ) {
error = F_152 ( V_14 -> V_17 , V_17 ) ;
if ( error )
goto V_906;
}
error = F_46 ( V_14 -> V_17 , V_17 , V_256 ,
V_907 , NULL ) ;
if ( error )
goto V_906;
V_417 = 0 ;
F_19 () ;
V_415 = F_155 ( V_145 ) ;
if ( V_415 )
V_417 = F_18 ( V_415 ) ;
F_21 () ;
if ( V_415 ) {
error = F_46 ( V_417 , V_17 , V_256 ,
V_350 , NULL ) ;
if ( error )
goto V_906;
}
V_14 -> V_17 = V_17 ;
} else {
error = - V_90 ;
goto V_906;
}
F_412 ( V_128 ) ;
return V_519 ;
V_906:
F_413 ( V_128 ) ;
return error ;
}
static int F_414 ( const char * V_63 )
{
return ( strcmp ( V_63 , V_490 ) == 0 ) ;
}
static int F_415 ( T_2 V_531 , char * * V_470 , T_2 * V_908 )
{
return F_60 ( V_531 , V_470 , V_908 ) ;
}
static int F_416 ( const char * V_470 , T_2 V_908 , T_2 * V_531 )
{
return F_67 ( V_470 , V_908 , V_531 , V_15 ) ;
}
static void F_417 ( char * V_470 , T_2 V_908 )
{
F_39 ( V_470 ) ;
}
static int F_418 ( struct V_22 * V_22 , void * V_293 , T_2 V_486 )
{
return F_235 ( V_22 , V_490 , V_293 , V_486 , 0 ) ;
}
static int F_419 ( struct V_64 * V_64 , void * V_293 , T_2 V_486 )
{
return F_420 ( V_64 , V_75 , V_293 , V_486 , 0 ) ;
}
static int F_421 ( struct V_22 * V_22 , void * * V_293 , T_2 * V_486 )
{
int V_88 = 0 ;
V_88 = F_234 ( V_22 , V_490 ,
V_293 , true ) ;
if ( V_88 < 0 )
return V_88 ;
* V_486 = V_88 ;
return 0 ;
}
static int F_422 ( struct V_826 * V_909 , const struct V_10 * V_10 ,
unsigned long V_79 )
{
const struct V_13 * V_14 ;
struct V_910 * V_911 ;
V_911 = F_15 ( sizeof( struct V_910 ) , V_15 ) ;
if ( ! V_911 )
return - V_27 ;
V_14 = V_10 -> V_19 ;
if ( V_14 -> V_405 )
V_911 -> V_17 = V_14 -> V_405 ;
else
V_911 -> V_17 = V_14 -> V_17 ;
V_909 -> V_19 = V_911 ;
return 0 ;
}
static void F_423 ( struct V_826 * V_909 )
{
struct V_910 * V_911 = V_909 -> V_19 ;
V_909 -> V_19 = NULL ;
F_39 ( V_911 ) ;
}
static int F_424 ( T_16 V_912 ,
const struct V_10 * V_10 ,
unsigned V_243 )
{
struct V_826 * V_826 ;
struct V_910 * V_911 ;
T_2 V_17 ;
if ( V_243 == 0 )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_826 = F_425 ( V_912 ) ;
V_911 = V_826 -> V_19 ;
return F_46 ( V_17 , V_911 -> V_17 , V_294 , V_243 , NULL ) ;
}
static int F_426 ( struct V_826 * V_826 , char * * V_913 )
{
struct V_910 * V_911 = V_826 -> V_19 ;
char * V_87 = NULL ;
unsigned V_88 ;
int V_53 ;
V_53 = F_60 ( V_911 -> V_17 , & V_87 , & V_88 ) ;
if ( ! V_53 )
V_53 = V_88 ;
* V_913 = V_87 ;
return V_53 ;
}
static T_1 int F_427 ( void )
{
if ( ! F_428 ( & V_914 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_50 ( V_915 L_59 ) ;
return 0 ;
}
F_50 ( V_915 L_60 ) ;
F_14 () ;
V_550 = ! ( V_916 & V_565 ) ;
V_25 = F_429 ( L_61 ,
sizeof( struct V_23 ) ,
0 , V_917 , NULL ) ;
F_430 () ;
if ( F_431 ( & V_914 ) )
F_16 ( L_62 ) ;
if ( F_432 ( F_9 , V_9 ) )
F_16 ( L_63 ) ;
if ( V_3 )
F_50 ( V_918 L_64 ) ;
else
F_50 ( V_918 L_65 ) ;
return 0 ;
}
static void F_433 ( struct V_47 * V_48 , void * V_919 )
{
F_76 ( V_48 , NULL ) ;
}
void F_434 ( void )
{
F_50 ( V_918 L_66 ) ;
F_50 ( V_918 L_67 ) ;
F_435 ( F_433 , NULL ) ;
}
static int T_1 F_436 ( void )
{
int V_579 ;
if ( ! V_5 )
return 0 ;
F_50 ( V_918 L_68 ) ;
V_579 = F_437 ( V_920 , F_51 ( V_920 ) ) ;
if ( V_579 )
F_16 ( L_69 , V_579 ) ;
return 0 ;
}
static void F_438 ( void )
{
F_50 ( V_918 L_70 ) ;
F_439 ( V_920 , F_51 ( V_920 ) ) ;
}
int F_440 ( void )
{
if ( V_91 ) {
return - V_90 ;
}
if ( V_921 ) {
return - V_90 ;
}
F_50 ( V_915 L_71 ) ;
V_921 = 1 ;
V_5 = 0 ;
F_441 () ;
F_442 () ;
F_438 () ;
F_443 () ;
return 0 ;
}
