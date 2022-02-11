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
if ( ! F_32 ( & V_24 -> V_29 ) ) {
F_33 ( & V_38 -> V_41 ) ;
F_34 ( & V_24 -> V_29 ) ;
F_35 ( & V_38 -> V_41 ) ;
}
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
V_38 -> V_58 == V_62 ||
! strcmp ( V_48 -> V_63 -> V_64 , L_2 ) ||
! strcmp ( V_48 -> V_63 -> V_64 , L_3 ) ||
! strcmp ( V_48 -> V_63 -> V_64 , L_4 ) ||
! strcmp ( V_48 -> V_63 -> V_64 , L_5 ) ;
}
static int F_49 ( struct V_47 * V_48 )
{
struct V_37 * V_38 = V_48 -> V_40 ;
struct V_65 * V_66 = V_48 -> V_67 ;
struct V_22 * V_68 = F_50 ( V_66 ) ;
int V_53 = 0 ;
if ( V_38 -> V_58 == V_59 ) {
if ( ! V_68 -> V_69 -> V_70 ) {
F_51 ( V_71 L_6
L_7 , V_48 -> V_72 , V_48 -> V_63 -> V_64 ) ;
V_53 = - V_73 ;
goto V_74;
}
V_53 = V_68 -> V_69 -> V_70 ( V_66 , V_75 , NULL , 0 ) ;
if ( V_53 < 0 && V_53 != - V_76 ) {
if ( V_53 == - V_73 )
F_51 ( V_71 L_8
L_9 ,
V_48 -> V_72 , V_48 -> V_63 -> V_64 ) ;
else
F_51 ( V_71 L_8
L_10 , V_48 -> V_72 ,
V_48 -> V_63 -> V_64 , - V_53 ) ;
goto V_74;
}
}
if ( V_38 -> V_58 > F_52 ( V_77 ) )
F_51 ( V_78 L_11 ,
V_48 -> V_72 , V_48 -> V_63 -> V_64 ) ;
V_38 -> V_79 |= V_80 ;
if ( F_48 ( V_48 ) )
V_38 -> V_79 |= V_81 ;
V_53 = F_44 ( V_68 , V_66 ) ;
F_33 ( & V_38 -> V_41 ) ;
V_82:
if ( ! F_53 ( & V_38 -> V_49 ) ) {
struct V_23 * V_24 =
F_54 ( V_38 -> V_49 . V_83 ,
struct V_23 , V_29 ) ;
struct V_22 * V_22 = V_24 -> V_22 ;
F_34 ( & V_24 -> V_29 ) ;
F_35 ( & V_38 -> V_41 ) ;
V_22 = F_55 ( V_22 ) ;
if ( V_22 ) {
if ( ! F_56 ( V_22 ) )
F_43 ( V_22 ) ;
F_57 ( V_22 ) ;
}
F_33 ( & V_38 -> V_41 ) ;
goto V_82;
}
F_35 ( & V_38 -> V_41 ) ;
V_74:
return V_53 ;
}
static int F_58 ( const struct V_47 * V_48 ,
struct V_84 * V_85 )
{
int V_53 = 0 , V_86 ;
struct V_37 * V_38 = V_48 -> V_40 ;
char * V_87 = NULL ;
T_2 V_88 ;
char V_89 ;
F_59 ( V_85 ) ;
if ( ! ( V_38 -> V_79 & V_80 ) )
return - V_90 ;
if ( ! V_91 )
return - V_90 ;
F_60 ( V_92 >= ( 1 << V_93 ) ) ;
V_89 = V_38 -> V_79 & V_92 ;
for ( V_86 = 0 ; V_86 < V_93 ; V_86 ++ ) {
if ( V_89 & 0x01 )
V_85 -> V_94 ++ ;
V_89 >>= 1 ;
}
if ( V_38 -> V_79 & V_81 )
V_85 -> V_94 ++ ;
V_85 -> V_95 = F_61 ( V_85 -> V_94 , sizeof( char * ) , V_96 ) ;
if ( ! V_85 -> V_95 ) {
V_53 = - V_27 ;
goto V_97;
}
V_85 -> V_98 = F_61 ( V_85 -> V_94 , sizeof( int ) , V_96 ) ;
if ( ! V_85 -> V_98 ) {
V_53 = - V_27 ;
goto V_97;
}
V_86 = 0 ;
if ( V_38 -> V_79 & V_99 ) {
V_53 = F_62 ( V_38 -> V_17 , & V_87 , & V_88 ) ;
if ( V_53 )
goto V_97;
V_85 -> V_95 [ V_86 ] = V_87 ;
V_85 -> V_98 [ V_86 ++ ] = V_99 ;
}
if ( V_38 -> V_79 & V_100 ) {
V_53 = F_62 ( V_38 -> V_52 , & V_87 , & V_88 ) ;
if ( V_53 )
goto V_97;
V_85 -> V_95 [ V_86 ] = V_87 ;
V_85 -> V_98 [ V_86 ++ ] = V_100 ;
}
if ( V_38 -> V_79 & V_101 ) {
V_53 = F_62 ( V_38 -> V_50 , & V_87 , & V_88 ) ;
if ( V_53 )
goto V_97;
V_85 -> V_95 [ V_86 ] = V_87 ;
V_85 -> V_98 [ V_86 ++ ] = V_101 ;
}
if ( V_38 -> V_79 & V_102 ) {
struct V_22 * V_66 = F_50 ( V_38 -> V_48 -> V_67 ) ;
struct V_23 * V_24 = V_66 -> V_33 ;
V_53 = F_62 ( V_24 -> V_17 , & V_87 , & V_88 ) ;
if ( V_53 )
goto V_97;
V_85 -> V_95 [ V_86 ] = V_87 ;
V_85 -> V_98 [ V_86 ++ ] = V_102 ;
}
if ( V_38 -> V_79 & V_81 ) {
V_85 -> V_95 [ V_86 ] = NULL ;
V_85 -> V_98 [ V_86 ++ ] = V_81 ;
}
F_63 ( V_86 != V_85 -> V_94 ) ;
return 0 ;
V_97:
F_64 ( V_85 ) ;
return V_53 ;
}
static int F_65 ( struct V_37 * V_38 , char V_103 ,
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
static int F_66 ( struct V_47 * V_48 ,
struct V_84 * V_85 ,
unsigned long V_107 ,
unsigned long * V_108 )
{
const struct V_10 * V_10 = F_67 () ;
int V_53 = 0 , V_86 ;
struct V_37 * V_38 = V_48 -> V_40 ;
const char * V_64 = V_48 -> V_63 -> V_64 ;
struct V_22 * V_22 = F_50 ( V_38 -> V_48 -> V_67 ) ;
struct V_23 * V_109 = V_22 -> V_33 ;
T_2 V_110 = 0 , V_111 = 0 , V_112 = 0 ;
T_2 V_113 = 0 ;
char * * V_114 = V_85 -> V_95 ;
int * V_79 = V_85 -> V_98 ;
int V_115 = V_85 -> V_94 ;
F_68 ( & V_38 -> V_28 ) ;
if ( ! V_91 ) {
if ( ! V_115 ) {
goto V_74;
}
V_53 = - V_90 ;
F_51 ( V_71 L_12
L_13 ) ;
goto V_74;
}
if ( V_107 && ! V_108 ) {
V_53 = - V_90 ;
goto V_74;
}
if ( ( V_38 -> V_79 & V_80 ) && ( V_48 -> V_63 -> V_116 & V_117 )
&& ( V_115 == 0 ) )
goto V_74;
for ( V_86 = 0 ; V_86 < V_115 ; V_86 ++ ) {
T_2 V_17 ;
if ( V_79 [ V_86 ] == V_81 )
continue;
V_53 = F_69 ( V_114 [ V_86 ] ,
strlen ( V_114 [ V_86 ] ) , & V_17 , V_15 ) ;
if ( V_53 ) {
F_51 ( V_71 L_14
L_15 ,
V_114 [ V_86 ] , V_48 -> V_72 , V_64 , V_53 ) ;
goto V_74;
}
switch ( V_79 [ V_86 ] ) {
case V_99 :
V_110 = V_17 ;
if ( F_65 ( V_38 , V_99 , V_38 -> V_17 ,
V_110 ) )
goto V_118;
V_38 -> V_79 |= V_99 ;
break;
case V_100 :
V_111 = V_17 ;
if ( F_65 ( V_38 , V_100 , V_38 -> V_52 ,
V_111 ) )
goto V_118;
V_38 -> V_79 |= V_100 ;
break;
case V_102 :
V_112 = V_17 ;
if ( F_65 ( V_38 , V_102 , V_109 -> V_17 ,
V_112 ) )
goto V_118;
V_38 -> V_79 |= V_102 ;
break;
case V_101 :
V_113 = V_17 ;
if ( F_65 ( V_38 , V_101 , V_38 -> V_50 ,
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
if ( strcmp ( V_48 -> V_63 -> V_64 , L_16 ) == 0 )
V_38 -> V_79 |= V_119 | V_120 ;
if ( ! strcmp ( V_48 -> V_63 -> V_64 , L_4 ) ||
! strcmp ( V_48 -> V_63 -> V_64 , L_2 ) ||
! strcmp ( V_48 -> V_63 -> V_64 , L_3 ) )
V_38 -> V_79 |= V_120 ;
if ( ! V_38 -> V_58 ) {
V_53 = F_70 ( V_48 ) ;
if ( V_53 ) {
F_51 ( V_71
L_17 ,
V_121 , V_48 -> V_63 -> V_64 , V_53 ) ;
goto V_74;
}
}
if ( V_110 ) {
V_53 = F_45 ( V_110 , V_38 , V_10 ) ;
if ( V_53 )
goto V_74;
V_38 -> V_17 = V_110 ;
}
if ( V_107 & V_122 && ! V_111 ) {
V_38 -> V_58 = V_62 ;
* V_108 |= V_122 ;
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
V_38 -> V_58 != V_62 ) {
V_53 = - V_90 ;
F_51 ( V_71 L_18
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
F_71 ( & V_38 -> V_28 ) ;
return V_53 ;
V_118:
V_53 = - V_90 ;
F_51 ( V_71 L_20
L_21 , V_48 -> V_72 , V_64 ) ;
goto V_74;
}
static int F_72 ( const struct V_47 * V_125 ,
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
struct V_23 * V_132 = F_50 ( V_125 -> V_67 ) -> V_33 ;
struct V_23 * V_133 = F_50 ( V_126 -> V_67 ) -> V_33 ;
if ( V_132 -> V_17 != V_133 -> V_17 )
goto V_131;
}
return 0 ;
V_131:
F_51 ( V_71 L_22
L_23
L_24 , V_126 -> V_72 , V_126 -> V_63 -> V_64 ) ;
return - V_134 ;
}
static int F_73 ( const struct V_47 * V_125 ,
struct V_47 * V_126 )
{
const struct V_37 * V_135 = V_125 -> V_40 ;
struct V_37 * V_136 = V_126 -> V_40 ;
int V_137 = ( V_135 -> V_79 & V_99 ) ;
int V_138 = ( V_135 -> V_79 & V_100 ) ;
int V_139 = ( V_135 -> V_79 & V_102 ) ;
if ( ! V_91 )
return 0 ;
F_63 ( ! ( V_135 -> V_79 & V_80 ) ) ;
if ( V_136 -> V_79 & V_80 )
return F_72 ( V_125 , V_126 ) ;
F_68 ( & V_136 -> V_28 ) ;
V_136 -> V_79 = V_135 -> V_79 ;
V_136 -> V_17 = V_135 -> V_17 ;
V_136 -> V_50 = V_135 -> V_50 ;
V_136 -> V_58 = V_135 -> V_58 ;
if ( V_138 ) {
T_2 V_17 = V_135 -> V_52 ;
if ( ! V_137 )
V_136 -> V_17 = V_17 ;
if ( ! V_139 ) {
struct V_22 * V_140 = F_50 ( V_126 -> V_67 ) ;
struct V_23 * V_141 = V_140 -> V_33 ;
V_141 -> V_17 = V_17 ;
}
V_136 -> V_52 = V_17 ;
}
if ( V_139 ) {
const struct V_22 * V_142 = F_50 ( V_125 -> V_67 ) ;
const struct V_23 * V_143 = V_142 -> V_33 ;
struct V_22 * V_140 = F_50 ( V_126 -> V_67 ) ;
struct V_23 * V_141 = V_140 -> V_33 ;
V_141 -> V_17 = V_143 -> V_17 ;
}
F_49 ( V_126 ) ;
F_71 ( & V_136 -> V_28 ) ;
return 0 ;
}
static int F_74 ( char * V_144 ,
struct V_84 * V_85 )
{
char * V_145 ;
char * V_87 = NULL , * V_146 = NULL ;
char * V_147 = NULL , * V_148 = NULL ;
int V_53 , V_94 = 0 ;
V_85 -> V_94 = 0 ;
while ( ( V_145 = F_75 ( & V_144 , L_25 ) ) != NULL ) {
int V_149 ;
T_3 args [ V_150 ] ;
if ( ! * V_145 )
continue;
V_149 = F_76 ( V_145 , V_151 , args ) ;
switch ( V_149 ) {
case V_152 :
if ( V_87 || V_146 ) {
V_53 = - V_90 ;
F_51 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_153;
}
V_87 = F_77 ( & args [ 0 ] ) ;
if ( ! V_87 ) {
V_53 = - V_27 ;
goto V_153;
}
break;
case V_154 :
if ( V_147 ) {
V_53 = - V_90 ;
F_51 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_153;
}
V_147 = F_77 ( & args [ 0 ] ) ;
if ( ! V_147 ) {
V_53 = - V_27 ;
goto V_153;
}
break;
case V_155 :
if ( V_148 ) {
V_53 = - V_90 ;
F_51 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_153;
}
V_148 = F_77 ( & args [ 0 ] ) ;
if ( ! V_148 ) {
V_53 = - V_27 ;
goto V_153;
}
break;
case V_156 :
if ( V_87 || V_146 ) {
V_53 = - V_90 ;
F_51 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_153;
}
V_146 = F_77 ( & args [ 0 ] ) ;
if ( ! V_146 ) {
V_53 = - V_27 ;
goto V_153;
}
break;
case V_157 :
break;
default:
V_53 = - V_90 ;
F_51 ( V_71 L_26 ) ;
goto V_153;
}
}
V_53 = - V_27 ;
V_85 -> V_95 = F_61 ( V_93 , sizeof( char * ) , V_96 ) ;
if ( ! V_85 -> V_95 )
goto V_153;
V_85 -> V_98 = F_61 ( V_93 , sizeof( int ) , V_96 ) ;
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
static int F_78 ( struct V_47 * V_48 , void * V_158 )
{
int V_53 = 0 ;
char * V_144 = V_158 ;
struct V_84 V_85 ;
F_59 ( & V_85 ) ;
if ( ! V_158 )
goto V_74;
F_63 ( V_48 -> V_63 -> V_116 & V_117 ) ;
V_53 = F_74 ( V_144 , & V_85 ) ;
if ( V_53 )
goto V_153;
V_74:
V_53 = F_66 ( V_48 , & V_85 , 0 , NULL ) ;
V_153:
F_64 ( & V_85 ) ;
return V_53 ;
}
static void F_79 ( struct V_159 * V_160 ,
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
F_80 ( V_160 , ',' ) ;
F_81 ( V_160 , V_167 ) ;
continue;
default:
F_82 () ;
return;
} ;
F_80 ( V_160 , ',' ) ;
F_81 ( V_160 , V_161 ) ;
if ( V_162 )
F_80 ( V_160 , '\"' ) ;
F_83 ( V_160 , V_85 -> V_95 [ V_86 ] , L_27 ) ;
if ( V_162 )
F_80 ( V_160 , '\"' ) ;
}
}
static int F_84 ( struct V_159 * V_160 , struct V_47 * V_48 )
{
struct V_84 V_85 ;
int V_53 ;
V_53 = F_58 ( V_48 , & V_85 ) ;
if ( V_53 ) {
if ( V_53 == - V_90 )
V_53 = 0 ;
return V_53 ;
}
F_79 ( V_160 , & V_85 ) ;
F_64 ( & V_85 ) ;
return V_53 ;
}
static inline T_4 F_85 ( T_5 V_168 )
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
static inline int F_86 ( int V_183 )
{
return ( V_183 == V_184 || V_183 == V_185 ) ;
}
static inline int F_87 ( int V_183 )
{
return ( V_183 == V_184 || V_183 == V_186 ) ;
}
static inline T_4 F_88 ( int V_187 , int type , int V_183 )
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
if ( F_86 ( V_183 ) )
return V_196 ;
else
return V_197 ;
case V_192 :
if ( F_87 ( V_183 ) )
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
default:
return V_234 ;
}
case V_235 :
return V_236 ;
case V_237 :
return V_238 ;
case V_239 :
return V_240 ;
}
return V_241 ;
}
static int F_89 ( struct V_65 * V_65 ,
T_4 V_242 ,
T_4 V_79 ,
T_2 * V_17 )
{
int V_53 ;
struct V_47 * V_48 = V_65 -> V_243 -> V_39 ;
char * V_244 , * V_245 ;
V_244 = ( char * ) F_90 ( V_15 ) ;
if ( ! V_244 )
return - V_27 ;
V_245 = F_91 ( V_65 , V_244 , V_246 ) ;
if ( F_92 ( V_245 ) )
V_53 = F_93 ( V_245 ) ;
else {
if ( V_79 & V_119 ) {
while ( V_245 [ 1 ] >= '0' && V_245 [ 1 ] <= '9' ) {
V_245 [ 1 ] = '/' ;
V_245 ++ ;
}
}
V_53 = F_94 ( V_48 -> V_63 -> V_64 , V_245 , V_242 , V_17 ) ;
}
F_95 ( ( unsigned long ) V_244 ) ;
return V_53 ;
}
static int F_44 ( struct V_22 * V_22 , struct V_65 * V_247 )
{
struct V_37 * V_38 = NULL ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 ;
struct V_65 * V_65 ;
#define F_96 255
char * V_87 = NULL ;
unsigned V_88 = 0 ;
int V_53 = 0 ;
if ( V_24 -> V_124 )
goto V_74;
F_68 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_124 )
goto V_248;
V_38 = V_22 -> V_39 -> V_40 ;
if ( ! ( V_38 -> V_79 & V_80 ) ) {
F_33 ( & V_38 -> V_41 ) ;
if ( F_53 ( & V_24 -> V_29 ) )
F_97 ( & V_24 -> V_29 , & V_38 -> V_49 ) ;
F_35 ( & V_38 -> V_41 ) ;
goto V_248;
}
switch ( V_38 -> V_58 ) {
case V_62 :
break;
case V_59 :
if ( ! V_22 -> V_69 -> V_70 ) {
V_24 -> V_17 = V_38 -> V_50 ;
break;
}
if ( V_247 ) {
V_65 = F_98 ( V_247 ) ;
} else {
V_65 = F_99 ( V_22 ) ;
}
if ( ! V_65 ) {
goto V_248;
}
V_88 = F_96 ;
V_87 = F_100 ( V_88 + 1 , V_26 ) ;
if ( ! V_87 ) {
V_53 = - V_27 ;
F_101 ( V_65 ) ;
goto V_248;
}
V_87 [ V_88 ] = '\0' ;
V_53 = V_22 -> V_69 -> V_70 ( V_65 , V_75 ,
V_87 , V_88 ) ;
if ( V_53 == - V_249 ) {
F_39 ( V_87 ) ;
V_53 = V_22 -> V_69 -> V_70 ( V_65 , V_75 ,
NULL , 0 ) ;
if ( V_53 < 0 ) {
F_101 ( V_65 ) ;
goto V_248;
}
V_88 = V_53 ;
V_87 = F_100 ( V_88 + 1 , V_26 ) ;
if ( ! V_87 ) {
V_53 = - V_27 ;
F_101 ( V_65 ) ;
goto V_248;
}
V_87 [ V_88 ] = '\0' ;
V_53 = V_22 -> V_69 -> V_70 ( V_65 ,
V_75 ,
V_87 , V_88 ) ;
}
F_101 ( V_65 ) ;
if ( V_53 < 0 ) {
if ( V_53 != - V_76 ) {
F_51 ( V_71 L_28
L_29 , V_121 ,
- V_53 , V_22 -> V_39 -> V_72 , V_22 -> V_250 ) ;
F_39 ( V_87 ) ;
goto V_248;
}
V_17 = V_38 -> V_50 ;
V_53 = 0 ;
} else {
V_53 = F_102 ( V_87 , V_53 , & V_17 ,
V_38 -> V_50 ,
V_26 ) ;
if ( V_53 ) {
char * V_251 = V_22 -> V_39 -> V_72 ;
unsigned long V_252 = V_22 -> V_250 ;
if ( V_53 == - V_90 ) {
if ( F_103 () )
F_51 ( V_253 L_30
L_31
L_32 , V_252 , V_251 , V_87 ) ;
} else {
F_51 ( V_71 L_33
L_34 ,
V_121 , V_87 , - V_53 , V_251 , V_252 ) ;
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
V_24 -> V_31 = F_85 ( V_22 -> V_254 ) ;
V_53 = F_104 ( V_24 -> F_18 , V_38 -> V_17 ,
V_24 -> V_31 , NULL , & V_17 ) ;
if ( V_53 )
goto V_248;
V_24 -> V_17 = V_17 ;
break;
case V_123 :
V_24 -> V_17 = V_38 -> V_52 ;
break;
default:
V_24 -> V_17 = V_38 -> V_17 ;
if ( ( V_38 -> V_79 & V_120 ) && ! F_105 ( V_22 -> V_254 ) ) {
if ( V_247 )
V_65 = F_98 ( V_247 ) ;
else
V_65 = F_99 ( V_22 ) ;
if ( ! V_65 )
goto V_248;
V_24 -> V_31 = F_85 ( V_22 -> V_254 ) ;
V_53 = F_89 ( V_65 , V_24 -> V_31 ,
V_38 -> V_79 , & V_17 ) ;
F_101 ( V_65 ) ;
if ( V_53 )
goto V_248;
V_24 -> V_17 = V_17 ;
}
break;
}
V_24 -> V_124 = 1 ;
V_248:
F_71 ( & V_24 -> V_28 ) ;
V_74:
if ( V_24 -> V_31 == V_32 )
V_24 -> V_31 = F_85 ( V_22 -> V_254 ) ;
return V_53 ;
}
static inline T_2 F_106 ( int V_255 )
{
T_2 V_256 = 0 ;
switch ( V_255 ) {
case V_257 :
V_256 = V_258 ;
break;
case V_259 :
V_256 = V_260 ;
break;
case V_261 :
V_256 = V_262 ;
break;
default:
V_256 = V_263 ;
break;
}
return V_256 ;
}
static int F_107 ( const struct V_10 * V_264 ,
const struct V_10 * V_265 ,
T_2 V_266 )
{
T_2 V_267 = F_17 ( V_264 ) , V_268 = F_17 ( V_265 ) ;
return F_46 ( V_267 , V_268 , V_269 , V_266 , NULL ) ;
}
static int F_108 ( const struct V_20 * V_270 ,
const struct V_20 * V_271 ,
T_2 V_266 )
{
const struct V_13 * V_272 , * V_273 ;
T_2 V_274 , V_275 ;
F_19 () ;
V_272 = F_20 ( V_270 ) -> V_19 ; V_274 = V_272 -> V_17 ;
V_273 = F_20 ( V_271 ) -> V_19 ; V_275 = V_273 -> V_17 ;
F_21 () ;
return F_46 ( V_274 , V_275 , V_269 , V_266 , NULL ) ;
}
static int F_109 ( const struct V_20 * V_276 ,
T_2 V_266 )
{
T_2 V_17 , V_268 ;
V_17 = F_22 () ;
V_268 = F_18 ( V_276 ) ;
return F_46 ( V_17 , V_268 , V_269 , V_266 , NULL ) ;
}
static int F_110 ( const struct V_10 * V_10 ,
int V_277 , int V_278 )
{
struct V_279 V_280 ;
struct V_281 V_282 ;
T_4 V_31 ;
T_2 V_17 = F_17 ( V_10 ) ;
T_2 V_283 = F_111 ( V_277 ) ;
int V_53 ;
V_280 . type = V_284 ;
V_280 . V_285 . V_277 = V_277 ;
switch ( F_112 ( V_277 ) ) {
case 0 :
V_31 = V_286 ;
break;
case 1 :
V_31 = V_287 ;
break;
default:
F_51 ( V_78
L_35 , V_277 ) ;
F_82 () ;
return - V_90 ;
}
V_53 = F_113 ( V_17 , V_17 , V_31 , V_283 , 0 , & V_282 ) ;
if ( V_278 == V_288 ) {
int V_289 = F_114 ( V_17 , V_17 , V_31 , V_283 , & V_282 , V_53 , & V_280 , 0 ) ;
if ( V_289 )
return V_289 ;
}
return V_53 ;
}
static int F_115 ( struct V_20 * V_276 ,
T_2 V_266 )
{
T_2 V_17 = F_18 ( V_276 ) ;
return F_46 ( V_17 , V_18 ,
V_290 , V_266 , NULL ) ;
}
static int F_116 ( const struct V_10 * V_10 ,
struct V_22 * V_22 ,
T_2 V_266 ,
struct V_279 * V_291 )
{
struct V_23 * V_24 ;
T_2 V_17 ;
F_117 ( V_10 ) ;
if ( F_118 ( F_56 ( V_22 ) ) )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
return F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_266 , V_291 ) ;
}
static inline int F_119 ( const struct V_10 * V_10 ,
struct V_65 * V_65 ,
T_2 V_283 )
{
struct V_22 * V_22 = F_50 ( V_65 ) ;
struct V_279 V_280 ;
V_280 . type = V_292 ;
V_280 . V_285 . V_65 = V_65 ;
return F_116 ( V_10 , V_22 , V_283 , & V_280 ) ;
}
static inline int F_120 ( const struct V_10 * V_10 ,
const struct V_245 * V_245 ,
T_2 V_283 )
{
struct V_22 * V_22 = F_50 ( V_245 -> V_65 ) ;
struct V_279 V_280 ;
V_280 . type = V_293 ;
V_280 . V_285 . V_245 = * V_245 ;
return F_116 ( V_10 , V_22 , V_283 , & V_280 ) ;
}
static inline int F_121 ( const struct V_10 * V_10 ,
struct V_42 * V_42 ,
T_2 V_283 )
{
struct V_279 V_280 ;
V_280 . type = V_293 ;
V_280 . V_285 . V_245 = V_42 -> V_294 ;
return F_116 ( V_10 , F_122 ( V_42 ) , V_283 , & V_280 ) ;
}
static int F_123 ( const struct V_10 * V_10 ,
struct V_42 * V_42 ,
T_2 V_283 )
{
struct V_43 * V_44 = V_42 -> V_46 ;
struct V_22 * V_22 = F_122 ( V_42 ) ;
struct V_279 V_280 ;
T_2 V_17 = F_17 ( V_10 ) ;
int V_53 ;
V_280 . type = V_293 ;
V_280 . V_285 . V_245 = V_42 -> V_294 ;
if ( V_17 != V_44 -> V_17 ) {
V_53 = F_46 ( V_17 , V_44 -> V_17 ,
V_295 ,
V_296 ,
& V_280 ) ;
if ( V_53 )
goto V_74;
}
V_53 = 0 ;
if ( V_283 )
V_53 = F_116 ( V_10 , V_22 , V_283 , & V_280 ) ;
V_74:
return V_53 ;
}
static int F_124 ( const struct V_22 * V_297 ,
const struct V_298 * V_64 ,
T_4 V_242 ,
T_2 * V_299 )
{
const struct V_37 * V_38 = V_297 -> V_39 -> V_40 ;
const struct V_23 * V_300 = V_297 -> V_33 ;
const struct V_13 * V_14 = F_23 () ;
if ( ( V_38 -> V_79 & V_80 ) &&
( V_38 -> V_58 == V_123 ) ) {
* V_299 = V_38 -> V_52 ;
} else if ( ( V_38 -> V_79 & V_81 ) &&
V_14 -> V_301 ) {
* V_299 = V_14 -> V_301 ;
} else {
return F_104 ( V_14 -> V_17 , V_300 -> V_17 , V_242 ,
V_64 , V_299 ) ;
}
return 0 ;
}
static int F_125 ( struct V_22 * V_297 ,
struct V_65 * V_65 ,
T_4 V_242 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_300 ;
struct V_37 * V_38 ;
T_2 V_17 , V_302 ;
struct V_279 V_280 ;
int V_53 ;
V_300 = V_297 -> V_33 ;
V_38 = V_297 -> V_39 -> V_40 ;
V_17 = V_14 -> V_17 ;
V_280 . type = V_292 ;
V_280 . V_285 . V_65 = V_65 ;
V_53 = F_46 ( V_17 , V_300 -> V_17 , V_178 ,
V_303 | V_304 ,
& V_280 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_124 ( V_297 , & V_65 -> V_305 , V_242 ,
& V_302 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_17 , V_302 , V_242 , V_306 , & V_280 ) ;
if ( V_53 )
return V_53 ;
return F_46 ( V_302 , V_38 -> V_17 ,
V_54 ,
V_57 , & V_280 ) ;
}
static int F_126 ( T_2 V_307 ,
struct V_20 * V_308 )
{
T_2 V_17 = F_18 ( V_308 ) ;
return F_46 ( V_17 , V_307 , V_309 , V_310 , NULL ) ;
}
static int F_127 ( struct V_22 * V_297 ,
struct V_65 * V_65 ,
int V_311 )
{
struct V_23 * V_300 , * V_24 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
T_2 V_283 ;
int V_53 ;
V_300 = V_297 -> V_33 ;
V_24 = F_50 ( V_65 ) -> V_33 ;
V_280 . type = V_292 ;
V_280 . V_285 . V_65 = V_65 ;
V_283 = V_304 ;
V_283 |= ( V_311 ? V_312 : V_303 ) ;
V_53 = F_46 ( V_17 , V_300 -> V_17 , V_178 , V_283 , & V_280 ) ;
if ( V_53 )
return V_53 ;
switch ( V_311 ) {
case V_313 :
V_283 = V_314 ;
break;
case V_315 :
V_283 = V_316 ;
break;
case V_317 :
V_283 = V_318 ;
break;
default:
F_51 ( V_71 L_36 ,
V_121 , V_311 ) ;
return 0 ;
}
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_283 , & V_280 ) ;
return V_53 ;
}
static inline int F_128 ( struct V_22 * V_319 ,
struct V_65 * V_320 ,
struct V_22 * V_321 ,
struct V_65 * V_322 )
{
struct V_23 * V_323 , * V_324 , * V_325 , * V_326 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
T_2 V_283 ;
int V_327 , V_328 ;
int V_53 ;
V_323 = V_319 -> V_33 ;
V_325 = F_50 ( V_320 ) -> V_33 ;
V_327 = F_129 ( V_320 ) ;
V_324 = V_321 -> V_33 ;
V_280 . type = V_292 ;
V_280 . V_285 . V_65 = V_320 ;
V_53 = F_46 ( V_17 , V_323 -> V_17 , V_178 ,
V_312 | V_304 , & V_280 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_17 , V_325 -> V_17 ,
V_325 -> V_31 , V_329 , & V_280 ) ;
if ( V_53 )
return V_53 ;
if ( V_327 && V_321 != V_319 ) {
V_53 = F_46 ( V_17 , V_325 -> V_17 ,
V_325 -> V_31 , V_330 , & V_280 ) ;
if ( V_53 )
return V_53 ;
}
V_280 . V_285 . V_65 = V_322 ;
V_283 = V_303 | V_304 ;
if ( F_130 ( V_322 ) )
V_283 |= V_312 ;
V_53 = F_46 ( V_17 , V_324 -> V_17 , V_178 , V_283 , & V_280 ) ;
if ( V_53 )
return V_53 ;
if ( F_130 ( V_322 ) ) {
V_326 = F_50 ( V_322 ) -> V_33 ;
V_328 = F_129 ( V_322 ) ;
V_53 = F_46 ( V_17 , V_326 -> V_17 ,
V_326 -> V_31 ,
( V_328 ? V_318 : V_316 ) , & V_280 ) ;
if ( V_53 )
return V_53 ;
}
return 0 ;
}
static int F_131 ( const struct V_10 * V_10 ,
struct V_47 * V_48 ,
T_2 V_266 ,
struct V_279 * V_280 )
{
struct V_37 * V_38 ;
T_2 V_17 = F_17 ( V_10 ) ;
V_38 = V_48 -> V_40 ;
return F_46 ( V_17 , V_38 -> V_17 , V_54 , V_266 , V_280 ) ;
}
static inline T_2 F_132 ( int V_168 , int V_331 )
{
T_2 V_283 = 0 ;
if ( ! F_133 ( V_168 ) ) {
if ( V_331 & V_332 )
V_283 |= V_333 ;
if ( V_331 & V_334 )
V_283 |= V_335 ;
if ( V_331 & V_336 )
V_283 |= V_337 ;
else if ( V_331 & V_338 )
V_283 |= V_339 ;
} else {
if ( V_331 & V_332 )
V_283 |= V_304 ;
if ( V_331 & V_338 )
V_283 |= V_340 ;
if ( V_331 & V_334 )
V_283 |= V_341 ;
}
return V_283 ;
}
static inline T_2 F_134 ( struct V_42 * V_42 )
{
T_2 V_283 = 0 ;
if ( V_42 -> V_342 & V_343 )
V_283 |= V_335 ;
if ( V_42 -> V_342 & V_344 ) {
if ( V_42 -> V_345 & V_346 )
V_283 |= V_337 ;
else
V_283 |= V_339 ;
}
if ( ! V_283 ) {
V_283 = V_347 ;
}
return V_283 ;
}
static inline T_2 F_135 ( struct V_42 * V_42 )
{
T_2 V_283 = F_134 ( V_42 ) ;
if ( V_348 )
V_283 |= V_349 ;
return V_283 ;
}
static int F_136 ( struct V_20 * V_350 )
{
T_2 V_351 = F_22 () ;
T_2 V_352 = F_18 ( V_350 ) ;
return F_46 ( V_351 , V_352 , V_353 ,
V_354 , NULL ) ;
}
static int F_137 ( struct V_20 * V_355 ,
struct V_20 * V_356 )
{
T_2 V_351 = F_22 () ;
T_2 V_357 = F_18 ( V_355 ) ;
T_2 V_358 = F_18 ( V_356 ) ;
int V_53 ;
if ( V_351 != V_357 ) {
V_53 = F_46 ( V_351 , V_357 , V_353 ,
V_359 , NULL ) ;
if ( V_53 )
return V_53 ;
}
return F_46 ( V_357 , V_358 , V_353 , V_360 ,
NULL ) ;
}
static int F_138 ( struct V_20 * V_355 ,
struct V_20 * V_356 )
{
T_2 V_357 = F_18 ( V_355 ) ;
T_2 V_358 = F_18 ( V_356 ) ;
return F_46 ( V_357 , V_358 , V_353 , V_361 ,
NULL ) ;
}
static int F_139 ( struct V_20 * V_355 ,
struct V_20 * V_356 ,
struct V_42 * V_42 )
{
T_2 V_17 = F_18 ( V_356 ) ;
struct V_43 * V_44 = V_42 -> V_46 ;
struct V_22 * V_22 = F_50 ( V_42 -> V_294 . V_65 ) ;
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_279 V_280 ;
int V_53 ;
V_280 . type = V_293 ;
V_280 . V_285 . V_245 = V_42 -> V_294 ;
if ( V_17 != V_44 -> V_17 ) {
V_53 = F_46 ( V_17 , V_44 -> V_17 ,
V_295 ,
V_296 ,
& V_280 ) ;
if ( V_53 )
return V_53 ;
}
if ( F_118 ( F_56 ( V_22 ) ) )
return 0 ;
return F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , F_134 ( V_42 ) ,
& V_280 ) ;
}
static int F_140 ( struct V_20 * V_362 ,
unsigned int V_168 )
{
if ( V_168 & V_363 ) {
T_2 V_17 = F_22 () ;
T_2 V_364 = F_18 ( V_362 ) ;
return F_46 ( V_17 , V_364 , V_32 , V_335 , NULL ) ;
}
return F_109 ( V_362 , V_365 ) ;
}
static int F_141 ( struct V_20 * V_366 )
{
return F_108 ( V_366 , V_11 , V_365 ) ;
}
static int F_142 ( struct V_20 * V_265 , T_6 * V_367 ,
T_6 * V_368 , T_6 * V_369 )
{
return F_109 ( V_265 , V_370 ) ;
}
static int F_143 ( struct V_10 * V_128 , const struct V_10 * V_127 ,
const T_6 * V_367 ,
const T_6 * V_368 ,
const T_6 * V_369 )
{
return F_107 ( V_127 , V_128 , V_371 ) ;
}
static int F_144 ( const struct V_10 * V_10 , struct V_372 * V_373 ,
int V_277 , int V_278 )
{
return F_110 ( V_10 , V_277 , V_278 ) ;
}
static int F_145 ( int V_374 , int type , int V_375 , struct V_47 * V_48 )
{
const struct V_10 * V_10 = F_67 () ;
int V_53 = 0 ;
if ( ! V_48 )
return 0 ;
switch ( V_374 ) {
case V_376 :
case V_377 :
case V_378 :
case V_379 :
case V_380 :
V_53 = F_131 ( V_10 , V_48 , V_381 , NULL ) ;
break;
case V_382 :
case V_383 :
case V_384 :
V_53 = F_131 ( V_10 , V_48 , V_385 , NULL ) ;
break;
default:
V_53 = 0 ;
break;
}
return V_53 ;
}
static int F_146 ( struct V_65 * V_65 )
{
const struct V_10 * V_10 = F_67 () ;
return F_119 ( V_10 , V_65 , V_386 ) ;
}
static int F_147 ( int type )
{
int V_53 ;
switch ( type ) {
case V_387 :
case V_388 :
V_53 = F_115 ( V_11 , V_389 ) ;
break;
case V_390 :
case V_391 :
case V_392 :
V_53 = F_115 ( V_11 , V_393 ) ;
break;
case V_394 :
case V_395 :
case V_396 :
case V_397 :
case V_398 :
default:
V_53 = F_115 ( V_11 , V_399 ) ;
break;
}
return V_53 ;
}
static int F_148 ( struct V_400 * V_401 , long V_402 )
{
int V_53 , V_403 = 0 ;
V_53 = F_110 ( F_67 () , V_404 ,
V_405 ) ;
if ( V_53 == 0 )
V_403 = 1 ;
return V_403 ;
}
static int F_149 ( const struct V_406 * V_407 ,
const struct V_13 * V_408 ,
const struct V_13 * V_409 )
{
int V_410 = ( V_407 -> V_411 & V_412 ) ;
int V_413 = ( V_407 -> V_42 -> V_294 . V_414 -> V_106 & V_415 ) ;
int V_53 ;
if ( ! V_410 && ! V_413 )
return 0 ;
if ( V_409 -> V_17 == V_408 -> V_17 )
return 0 ;
V_53 = F_150 ( V_408 -> V_17 , V_409 -> V_17 ) ;
if ( V_53 ) {
if ( V_410 )
return - V_416 ;
else
return - V_417 ;
}
return 0 ;
}
static int F_151 ( struct V_406 * V_407 )
{
const struct V_13 * V_408 ;
struct V_13 * V_409 ;
struct V_23 * V_24 ;
struct V_279 V_280 ;
struct V_22 * V_22 = F_122 ( V_407 -> V_42 ) ;
int V_53 ;
if ( V_407 -> V_418 )
return 0 ;
V_408 = F_23 () ;
V_409 = V_407 -> V_10 -> V_19 ;
V_24 = V_22 -> V_33 ;
V_409 -> V_17 = V_408 -> V_17 ;
V_409 -> V_16 = V_408 -> V_17 ;
V_409 -> V_301 = 0 ;
V_409 -> V_419 = 0 ;
V_409 -> V_420 = 0 ;
if ( V_408 -> V_421 ) {
V_409 -> V_17 = V_408 -> V_421 ;
V_409 -> V_421 = 0 ;
V_53 = F_149 ( V_407 , V_408 , V_409 ) ;
if ( V_53 )
return V_53 ;
} else {
V_53 = F_104 ( V_408 -> V_17 , V_24 -> V_17 ,
V_269 , NULL ,
& V_409 -> V_17 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_149 ( V_407 , V_408 , V_409 ) ;
if ( V_53 )
V_409 -> V_17 = V_408 -> V_17 ;
}
V_280 . type = V_293 ;
V_280 . V_285 . V_245 = V_407 -> V_42 -> V_294 ;
if ( V_409 -> V_17 == V_408 -> V_17 ) {
V_53 = F_46 ( V_408 -> V_17 , V_24 -> V_17 ,
V_32 , V_422 , & V_280 ) ;
if ( V_53 )
return V_53 ;
} else {
V_53 = F_46 ( V_408 -> V_17 , V_409 -> V_17 ,
V_269 , V_423 , & V_280 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_409 -> V_17 , V_24 -> V_17 ,
V_32 , V_424 , & V_280 ) ;
if ( V_53 )
return V_53 ;
if ( V_407 -> V_411 & V_425 ) {
V_53 = F_46 ( V_408 -> V_17 , V_409 -> V_17 ,
V_269 , V_426 ,
NULL ) ;
if ( V_53 )
return - V_416 ;
}
if ( V_407 -> V_411 &
( V_427 | V_428 ) ) {
struct V_20 * V_429 ;
struct V_13 * V_430 ;
T_2 V_431 = 0 ;
F_19 () ;
V_429 = F_152 ( V_11 ) ;
if ( F_153 ( V_429 != NULL ) ) {
V_430 = F_20 ( V_429 ) -> V_19 ;
V_431 = V_430 -> V_17 ;
}
F_21 () ;
if ( V_431 != 0 ) {
V_53 = F_46 ( V_431 , V_409 -> V_17 ,
V_269 ,
V_365 , NULL ) ;
if ( V_53 )
return - V_416 ;
}
}
V_407 -> V_432 |= V_433 ;
}
return 0 ;
}
static int F_154 ( struct V_406 * V_407 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_17 , V_16 ;
int V_434 = 0 ;
V_17 = V_14 -> V_17 ;
V_16 = V_14 -> V_16 ;
if ( V_16 != V_17 ) {
V_434 = F_46 ( V_16 , V_17 ,
V_269 ,
V_435 , NULL ) ;
}
return ! ! V_434 ;
}
static int F_155 ( const void * V_145 , struct V_42 * V_42 , unsigned V_436 )
{
return F_123 ( V_145 , V_42 , F_134 ( V_42 ) ) ? V_436 + 1 : 0 ;
}
static inline void F_156 ( const struct V_10 * V_10 ,
struct V_437 * V_438 )
{
struct V_42 * V_42 , * V_439 = NULL ;
struct V_440 * V_441 ;
int V_442 = 0 ;
unsigned V_443 ;
V_441 = F_157 () ;
if ( V_441 ) {
F_33 ( & V_444 ) ;
if ( ! F_53 ( & V_441 -> V_445 ) ) {
struct V_446 * V_447 ;
V_447 = F_158 ( & V_441 -> V_445 ,
struct V_446 , V_29 ) ;
V_42 = V_447 -> V_42 ;
if ( F_121 ( V_10 , V_42 , V_335 | V_339 ) )
V_442 = 1 ;
}
F_35 ( & V_444 ) ;
F_159 ( V_441 ) ;
}
if ( V_442 )
F_160 () ;
V_443 = F_161 ( V_438 , 0 , F_155 , V_10 ) ;
if ( ! V_443 )
return;
V_439 = F_162 ( & V_448 , V_449 , V_10 ) ;
if ( F_92 ( V_439 ) )
V_439 = NULL ;
do {
F_163 ( V_443 - 1 , V_439 , 0 ) ;
} while ( ( V_443 = F_161 ( V_438 , V_443 , F_155 , V_10 ) ) != 0 );
if ( V_439 )
F_164 ( V_439 ) ;
}
static void F_165 ( struct V_406 * V_407 )
{
struct V_13 * V_409 ;
struct V_450 * V_451 , * V_452 ;
int V_53 , V_86 ;
V_409 = V_407 -> V_10 -> V_19 ;
if ( V_409 -> V_17 == V_409 -> V_16 )
return;
F_156 ( V_407 -> V_10 , V_11 -> V_438 ) ;
V_11 -> V_453 = 0 ;
V_53 = F_46 ( V_409 -> V_16 , V_409 -> V_17 , V_269 ,
V_454 , NULL ) ;
if ( V_53 ) {
F_166 ( V_11 ) ;
for ( V_86 = 0 ; V_86 < V_455 ; V_86 ++ ) {
V_451 = V_11 -> signal -> V_451 + V_86 ;
V_452 = V_456 . signal -> V_451 + V_86 ;
V_451 -> V_457 = F_167 ( V_451 -> V_458 , V_452 -> V_457 ) ;
}
F_168 ( V_11 ) ;
F_169 ( V_11 , V_450 ( V_459 ) ) ;
}
}
static void F_170 ( struct V_406 * V_407 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_460 V_461 ;
T_2 V_16 , V_17 ;
int V_53 , V_86 ;
V_16 = V_14 -> V_16 ;
V_17 = V_14 -> V_17 ;
if ( V_17 == V_16 )
return;
V_53 = F_46 ( V_16 , V_17 , V_269 , V_462 , NULL ) ;
if ( V_53 ) {
memset ( & V_461 , 0 , sizeof V_461 ) ;
for ( V_86 = 0 ; V_86 < 3 ; V_86 ++ )
F_171 ( V_86 , & V_461 , NULL ) ;
F_172 ( & V_11 -> V_463 -> V_464 ) ;
if ( ! F_173 ( V_11 ) ) {
F_174 ( & V_11 -> V_465 ) ;
F_174 ( & V_11 -> signal -> V_466 ) ;
F_175 ( V_11 , 1 ) ;
F_176 ( & V_11 -> V_467 ) ;
F_177 () ;
}
F_178 ( & V_11 -> V_463 -> V_464 ) ;
}
F_179 ( & V_468 ) ;
F_180 ( V_11 , V_11 -> V_469 ) ;
F_181 ( & V_468 ) ;
}
static int F_182 ( struct V_47 * V_48 )
{
return F_40 ( V_48 ) ;
}
static void F_183 ( struct V_47 * V_48 )
{
F_42 ( V_48 ) ;
}
static inline int F_184 ( char * V_161 , int V_470 , char * V_471 , int V_472 )
{
if ( V_470 > V_472 )
return 0 ;
return ! memcmp ( V_161 , V_471 , V_470 ) ;
}
static inline int F_185 ( char * V_471 , int V_88 )
{
return ( F_184 ( V_163 , sizeof( V_163 ) - 1 , V_471 , V_88 ) ||
F_184 ( V_164 , sizeof( V_164 ) - 1 , V_471 , V_88 ) ||
F_184 ( V_166 , sizeof( V_166 ) - 1 , V_471 , V_88 ) ||
F_184 ( V_165 , sizeof( V_165 ) - 1 , V_471 , V_88 ) ||
F_184 ( V_167 , sizeof( V_167 ) - 1 , V_471 , V_88 ) ) ;
}
static inline void F_186 ( char * * V_356 , char * V_355 , int * V_473 , int V_88 )
{
if ( ! * V_473 ) {
* * V_356 = ',' ;
* V_356 += 1 ;
} else
* V_473 = 0 ;
memcpy ( * V_356 , V_355 , V_88 ) ;
* V_356 += V_88 ;
}
static inline void F_187 ( char * * V_356 , char * V_355 , int * V_473 ,
int V_88 )
{
int V_474 = 0 ;
if ( ! * V_473 ) {
* * V_356 = '|' ;
* V_356 += 1 ;
} else
* V_473 = 0 ;
while ( V_474 < V_88 ) {
if ( * V_355 != '"' ) {
* * V_356 = * V_355 ;
* V_356 += 1 ;
}
V_355 += 1 ;
V_474 += 1 ;
}
}
static int F_188 ( char * V_475 , char * V_476 )
{
int V_477 , V_44 , V_53 = 0 ;
char * V_478 , * V_479 , * V_480 ;
char * V_481 , * V_482 , * V_483 ;
int V_484 = 0 ;
V_479 = V_475 ;
V_481 = V_476 ;
V_483 = ( char * ) F_189 ( V_15 ) ;
if ( ! V_483 ) {
V_53 = - V_27 ;
goto V_74;
}
V_482 = V_483 ;
V_477 = V_44 = 1 ;
V_478 = V_480 = V_475 ;
do {
if ( * V_480 == '"' )
V_484 = ! V_484 ;
if ( ( * V_480 == ',' && V_484 == 0 ) ||
* V_480 == '\0' ) {
int V_88 = V_480 - V_479 ;
if ( F_185 ( V_479 , V_88 ) )
F_187 ( & V_481 , V_479 , & V_44 , V_88 ) ;
else
F_186 ( & V_483 , V_479 , & V_477 , V_88 ) ;
V_479 = V_480 + 1 ;
}
} while ( * V_480 ++ );
strcpy ( V_478 , V_482 ) ;
F_95 ( ( unsigned long ) V_482 ) ;
V_74:
return V_53 ;
}
static int F_190 ( struct V_47 * V_48 , void * V_158 )
{
int V_53 , V_86 , * V_79 ;
struct V_84 V_85 ;
char * V_485 , * * V_114 ;
struct V_37 * V_38 = V_48 -> V_40 ;
if ( ! ( V_38 -> V_79 & V_80 ) )
return 0 ;
if ( ! V_158 )
return 0 ;
if ( V_48 -> V_63 -> V_116 & V_117 )
return 0 ;
F_59 ( & V_85 ) ;
V_485 = F_191 () ;
if ( ! V_485 )
return - V_27 ;
V_53 = F_188 ( V_158 , V_485 ) ;
if ( V_53 )
goto V_486;
V_53 = F_74 ( V_485 , & V_85 ) ;
if ( V_53 )
goto V_486;
V_114 = V_85 . V_95 ;
V_79 = V_85 . V_98 ;
for ( V_86 = 0 ; V_86 < V_85 . V_94 ; V_86 ++ ) {
T_2 V_17 ;
T_7 V_88 ;
if ( V_79 [ V_86 ] == V_81 )
continue;
V_88 = strlen ( V_114 [ V_86 ] ) ;
V_53 = F_69 ( V_114 [ V_86 ] , V_88 , & V_17 ,
V_15 ) ;
if ( V_53 ) {
F_51 ( V_71 L_14
L_15 ,
V_114 [ V_86 ] , V_48 -> V_72 , V_48 -> V_63 -> V_64 , V_53 ) ;
goto V_487;
}
V_53 = - V_90 ;
switch ( V_79 [ V_86 ] ) {
case V_99 :
if ( F_65 ( V_38 , V_99 , V_38 -> V_17 , V_17 ) )
goto V_488;
break;
case V_100 :
if ( F_65 ( V_38 , V_100 , V_38 -> V_52 , V_17 ) )
goto V_488;
break;
case V_102 : {
struct V_23 * V_109 ;
V_109 = F_50 ( V_48 -> V_67 ) -> V_33 ;
if ( F_65 ( V_38 , V_102 , V_109 -> V_17 , V_17 ) )
goto V_488;
break;
}
case V_101 :
if ( F_65 ( V_38 , V_101 , V_38 -> V_50 , V_17 ) )
goto V_488;
break;
default:
goto V_487;
}
}
V_53 = 0 ;
V_487:
F_64 ( & V_85 ) ;
V_486:
F_192 ( V_485 ) ;
return V_53 ;
V_488:
F_51 ( V_71 L_37
L_38 , V_48 -> V_72 ,
V_48 -> V_63 -> V_64 ) ;
goto V_487;
}
static int F_193 ( struct V_47 * V_48 , int V_79 , void * V_158 )
{
const struct V_10 * V_10 = F_67 () ;
struct V_279 V_280 ;
int V_53 ;
V_53 = F_78 ( V_48 , V_158 ) ;
if ( V_53 )
return V_53 ;
if ( V_79 & V_489 )
return 0 ;
V_280 . type = V_292 ;
V_280 . V_285 . V_65 = V_48 -> V_67 ;
return F_131 ( V_10 , V_48 , V_490 , & V_280 ) ;
}
static int F_194 ( struct V_65 * V_65 )
{
const struct V_10 * V_10 = F_67 () ;
struct V_279 V_280 ;
V_280 . type = V_292 ;
V_280 . V_285 . V_65 = V_65 -> V_491 -> V_67 ;
return F_131 ( V_10 , V_65 -> V_491 , V_492 , & V_280 ) ;
}
static int F_195 ( const char * V_493 ,
struct V_245 * V_245 ,
const char * type ,
unsigned long V_79 ,
void * V_158 )
{
const struct V_10 * V_10 = F_67 () ;
if ( V_79 & V_494 )
return F_131 ( V_10 , V_245 -> V_65 -> V_491 ,
V_495 , NULL ) ;
else
return F_120 ( V_10 , V_245 , V_496 ) ;
}
static int F_196 ( struct V_497 * V_414 , int V_79 )
{
const struct V_10 * V_10 = F_67 () ;
return F_131 ( V_10 , V_414 -> V_498 ,
V_499 , NULL ) ;
}
static int F_197 ( struct V_22 * V_22 )
{
return F_24 ( V_22 ) ;
}
static void F_198 ( struct V_22 * V_22 )
{
F_31 ( V_22 ) ;
}
static int F_199 ( struct V_65 * V_65 , int V_168 ,
struct V_298 * V_64 , void * * V_308 ,
T_2 * V_500 )
{
T_2 V_302 ;
int V_53 ;
V_53 = F_124 ( V_243 ( V_65 -> V_501 ) , V_64 ,
F_85 ( V_168 ) ,
& V_302 ) ;
if ( V_53 )
return V_53 ;
return F_62 ( V_302 , ( char * * ) V_308 , V_500 ) ;
}
static int F_200 ( struct V_22 * V_22 , struct V_22 * V_297 ,
const struct V_298 * V_298 ,
const char * * V_64 ,
void * * V_502 , T_7 * V_88 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_300 ;
struct V_37 * V_38 ;
T_2 V_17 , V_302 , V_503 ;
int V_53 ;
char * V_87 ;
V_300 = V_297 -> V_33 ;
V_38 = V_297 -> V_39 -> V_40 ;
V_17 = V_14 -> V_17 ;
V_302 = V_14 -> V_301 ;
V_53 = F_124 (
V_297 , V_298 ,
F_85 ( V_22 -> V_254 ) ,
& V_302 ) ;
if ( V_53 )
return V_53 ;
if ( V_38 -> V_79 & V_80 ) {
struct V_23 * V_24 = V_22 -> V_33 ;
V_24 -> V_31 = F_85 ( V_22 -> V_254 ) ;
V_24 -> V_17 = V_302 ;
V_24 -> V_124 = 1 ;
}
if ( ! V_91 || ! ( V_38 -> V_79 & V_81 ) )
return - V_73 ;
if ( V_64 )
* V_64 = V_504 ;
if ( V_502 && V_88 ) {
V_53 = F_201 ( V_302 , & V_87 , & V_503 ) ;
if ( V_53 )
return V_53 ;
* V_502 = V_87 ;
* V_88 = V_503 ;
}
return 0 ;
}
static int F_202 ( struct V_22 * V_297 , struct V_65 * V_65 , T_5 V_168 )
{
return F_125 ( V_297 , V_65 , V_32 ) ;
}
static int F_203 ( struct V_65 * V_320 , struct V_22 * V_297 , struct V_65 * V_322 )
{
return F_127 ( V_297 , V_320 , V_313 ) ;
}
static int F_204 ( struct V_22 * V_297 , struct V_65 * V_65 )
{
return F_127 ( V_297 , V_65 , V_315 ) ;
}
static int F_205 ( struct V_22 * V_297 , struct V_65 * V_65 , const char * V_64 )
{
return F_125 ( V_297 , V_65 , V_173 ) ;
}
static int F_206 ( struct V_22 * V_297 , struct V_65 * V_65 , T_5 V_331 )
{
return F_125 ( V_297 , V_65 , V_178 ) ;
}
static int F_207 ( struct V_22 * V_297 , struct V_65 * V_65 )
{
return F_127 ( V_297 , V_65 , V_317 ) ;
}
static int F_208 ( struct V_22 * V_297 , struct V_65 * V_65 , T_5 V_168 , T_8 V_251 )
{
return F_125 ( V_297 , V_65 , F_85 ( V_168 ) ) ;
}
static int F_209 ( struct V_22 * V_505 , struct V_65 * V_320 ,
struct V_22 * V_506 , struct V_65 * V_322 )
{
return F_128 ( V_505 , V_320 , V_506 , V_322 ) ;
}
static int F_210 ( struct V_65 * V_65 )
{
const struct V_10 * V_10 = F_67 () ;
return F_119 ( V_10 , V_65 , V_335 ) ;
}
static int F_211 ( struct V_65 * V_65 , struct V_22 * V_22 ,
bool V_36 )
{
const struct V_10 * V_10 = F_67 () ;
struct V_279 V_280 ;
struct V_23 * V_24 ;
T_2 V_17 ;
F_117 ( V_10 ) ;
V_280 . type = V_292 ;
V_280 . V_285 . V_65 = V_65 ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
return F_212 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_335 , & V_280 ,
V_36 ? V_507 : 0 ) ;
}
static T_9 int F_213 ( struct V_22 * V_22 ,
T_2 V_266 , T_2 V_508 , T_2 V_509 ,
int V_510 ,
unsigned V_79 )
{
struct V_279 V_280 ;
struct V_23 * V_24 = V_22 -> V_33 ;
int V_53 ;
V_280 . type = V_511 ;
V_280 . V_285 . V_22 = V_22 ;
V_53 = F_214 ( F_22 () , V_24 -> V_17 , V_24 -> V_31 , V_266 ,
V_508 , V_509 , V_510 , & V_280 , V_79 ) ;
if ( V_53 )
return V_53 ;
return 0 ;
}
static int F_215 ( struct V_22 * V_22 , int V_331 )
{
const struct V_10 * V_10 = F_67 () ;
T_2 V_266 ;
bool V_512 ;
unsigned V_79 = V_331 & V_507 ;
struct V_23 * V_24 ;
T_2 V_17 ;
struct V_281 V_282 ;
int V_53 , V_289 ;
T_2 V_508 , V_509 ;
V_512 = V_331 & V_513 ;
V_331 &= ( V_334 | V_338 | V_332 | V_336 ) ;
if ( ! V_331 )
return 0 ;
F_117 ( V_10 ) ;
if ( F_118 ( F_56 ( V_22 ) ) )
return 0 ;
V_266 = F_132 ( V_22 -> V_254 , V_331 ) ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
V_53 = F_113 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_266 , 0 , & V_282 ) ;
V_508 = F_216 ( V_266 , & V_282 , V_53 ,
V_512 ? V_514 : 0 ,
& V_509 ) ;
if ( F_153 ( ! V_508 ) )
return V_53 ;
V_289 = F_213 ( V_22 , V_266 , V_508 , V_509 , V_53 , V_79 ) ;
if ( V_289 )
return V_289 ;
return V_53 ;
}
static int F_217 ( struct V_65 * V_65 , struct V_515 * V_515 )
{
const struct V_10 * V_10 = F_67 () ;
unsigned int V_516 = V_515 -> V_516 ;
T_10 V_283 = V_339 ;
if ( V_516 & V_517 ) {
V_516 &= ~ ( V_518 | V_519 | V_520 |
V_517 ) ;
if ( ! V_516 )
return 0 ;
}
if ( V_516 & ( V_520 | V_521 | V_522 |
V_523 | V_524 | V_525 ) )
return F_119 ( V_10 , V_65 , V_526 ) ;
if ( V_348 && ( V_516 & V_527 ) )
V_283 |= V_349 ;
return F_119 ( V_10 , V_65 , V_283 ) ;
}
static int F_218 ( const struct V_245 * V_245 )
{
return F_120 ( F_67 () , V_245 , V_528 ) ;
}
static int F_219 ( struct V_65 * V_65 , const char * V_64 )
{
const struct V_10 * V_10 = F_67 () ;
if ( ! strncmp ( V_64 , V_529 ,
sizeof V_529 - 1 ) ) {
if ( ! strcmp ( V_64 , V_530 ) ) {
if ( ! F_220 ( V_531 ) )
return - V_416 ;
} else if ( ! F_220 ( V_404 ) ) {
return - V_416 ;
}
}
return F_119 ( V_10 , V_65 , V_526 ) ;
}
static int F_221 ( struct V_65 * V_65 , const char * V_64 ,
const void * V_502 , T_7 V_532 , int V_79 )
{
struct V_22 * V_22 = F_50 ( V_65 ) ;
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_37 * V_38 ;
struct V_279 V_280 ;
T_2 V_302 , V_17 = F_22 () ;
int V_53 = 0 ;
if ( strcmp ( V_64 , V_75 ) )
return F_219 ( V_65 , V_64 ) ;
V_38 = V_22 -> V_39 -> V_40 ;
if ( ! ( V_38 -> V_79 & V_81 ) )
return - V_73 ;
if ( ! F_222 ( V_22 ) )
return - V_416 ;
V_280 . type = V_292 ;
V_280 . V_285 . V_65 = V_65 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 ,
V_533 , & V_280 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_69 ( V_502 , V_532 , & V_302 , V_15 ) ;
if ( V_53 == - V_90 ) {
if ( ! F_220 ( V_534 ) ) {
struct V_535 * V_536 ;
T_7 V_537 ;
const char * V_1 ;
if ( V_502 ) {
V_1 = V_502 ;
if ( V_1 [ V_532 - 1 ] == '\0' )
V_537 = V_532 - 1 ;
else
V_537 = V_532 ;
} else {
V_1 = L_39 ;
V_537 = 0 ;
}
V_536 = F_223 ( V_11 -> V_538 , V_96 , V_539 ) ;
F_224 ( V_536 , L_40 ) ;
F_225 ( V_536 , V_502 , V_537 ) ;
F_226 ( V_536 ) ;
return V_53 ;
}
V_53 = F_227 ( V_502 , V_532 , & V_302 ) ;
}
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_17 , V_302 , V_24 -> V_31 ,
V_540 , & V_280 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_228 ( V_24 -> V_17 , V_302 , V_17 ,
V_24 -> V_31 ) ;
if ( V_53 )
return V_53 ;
return F_46 ( V_302 ,
V_38 -> V_17 ,
V_54 ,
V_57 ,
& V_280 ) ;
}
static void F_229 ( struct V_65 * V_65 , const char * V_64 ,
const void * V_502 , T_7 V_532 ,
int V_79 )
{
struct V_22 * V_22 = F_50 ( V_65 ) ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_302 ;
int V_53 ;
if ( strcmp ( V_64 , V_75 ) ) {
return;
}
V_53 = F_227 ( V_502 , V_532 , & V_302 ) ;
if ( V_53 ) {
F_51 ( V_78 L_41
L_42 ,
V_22 -> V_39 -> V_72 , V_22 -> V_250 , - V_53 ) ;
return;
}
V_24 -> V_31 = F_85 ( V_22 -> V_254 ) ;
V_24 -> V_17 = V_302 ;
V_24 -> V_124 = 1 ;
return;
}
static int F_230 ( struct V_65 * V_65 , const char * V_64 )
{
const struct V_10 * V_10 = F_67 () ;
return F_119 ( V_10 , V_65 , V_528 ) ;
}
static int F_231 ( struct V_65 * V_65 )
{
const struct V_10 * V_10 = F_67 () ;
return F_119 ( V_10 , V_65 , V_528 ) ;
}
static int F_232 ( struct V_65 * V_65 , const char * V_64 )
{
if ( strcmp ( V_64 , V_75 ) )
return F_219 ( V_65 , V_64 ) ;
return - V_417 ;
}
static int F_233 ( const struct V_22 * V_22 , const char * V_64 , void * * V_244 , bool V_541 )
{
T_2 V_532 ;
int error ;
char * V_87 = NULL ;
struct V_23 * V_24 = V_22 -> V_33 ;
if ( strcmp ( V_64 , V_504 ) )
return - V_73 ;
error = F_234 ( F_67 () , & V_542 , V_534 ,
V_405 ) ;
if ( ! error )
error = F_110 ( F_67 () , V_534 ,
V_405 ) ;
if ( ! error )
error = F_201 ( V_24 -> V_17 , & V_87 ,
& V_532 ) ;
else
error = F_62 ( V_24 -> V_17 , & V_87 , & V_532 ) ;
if ( error )
return error ;
error = V_532 ;
if ( V_541 ) {
* V_244 = V_87 ;
goto V_543;
}
F_39 ( V_87 ) ;
V_543:
return error ;
}
static int F_235 ( struct V_22 * V_22 , const char * V_64 ,
const void * V_502 , T_7 V_532 , int V_79 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_302 ;
int V_53 ;
if ( strcmp ( V_64 , V_504 ) )
return - V_73 ;
if ( ! V_502 || ! V_532 )
return - V_417 ;
V_53 = F_69 ( ( void * ) V_502 , V_532 , & V_302 , V_15 ) ;
if ( V_53 )
return V_53 ;
V_24 -> V_31 = F_85 ( V_22 -> V_254 ) ;
V_24 -> V_17 = V_302 ;
V_24 -> V_124 = 1 ;
return 0 ;
}
static int F_236 ( struct V_22 * V_22 , char * V_244 , T_7 V_544 )
{
const int V_88 = sizeof( V_75 ) ;
if ( V_244 && V_88 <= V_544 )
memcpy ( V_244 , V_75 , V_88 ) ;
return V_88 ;
}
static void F_237 ( const struct V_22 * V_22 , T_2 * V_545 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
* V_545 = V_24 -> V_17 ;
}
static int F_238 ( struct V_42 * V_42 , int V_331 )
{
const struct V_10 * V_10 = F_67 () ;
struct V_22 * V_22 = F_122 ( V_42 ) ;
if ( ( V_42 -> V_345 & V_346 ) && ( V_331 & V_338 ) )
V_331 |= V_336 ;
return F_123 ( V_10 , V_42 ,
F_132 ( V_22 -> V_254 , V_331 ) ) ;
}
static int F_239 ( struct V_42 * V_42 , int V_331 )
{
struct V_22 * V_22 = F_122 ( V_42 ) ;
struct V_43 * V_44 = V_42 -> V_46 ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 = F_22 () ;
if ( ! V_331 )
return 0 ;
if ( V_17 == V_44 -> V_17 && V_44 -> V_546 == V_24 -> V_17 &&
V_44 -> V_547 == F_240 () )
return 0 ;
return F_238 ( V_42 , V_331 ) ;
}
static int F_241 ( struct V_42 * V_42 )
{
return F_37 ( V_42 ) ;
}
static void F_242 ( struct V_42 * V_42 )
{
F_38 ( V_42 ) ;
}
int F_243 ( const struct V_10 * V_10 , struct V_42 * V_42 ,
T_2 V_548 , T_4 V_549 )
{
struct V_279 V_280 ;
struct V_43 * V_44 = V_42 -> V_46 ;
struct V_22 * V_22 = F_122 ( V_42 ) ;
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_550 V_551 ;
T_2 V_552 = F_17 ( V_10 ) ;
int V_53 ;
T_11 V_553 = V_549 >> 8 ;
T_11 V_554 = V_549 & 0xff ;
V_280 . type = V_555 ;
V_280 . V_285 . V_556 = & V_551 ;
V_280 . V_285 . V_556 -> V_549 = V_549 ;
V_280 . V_285 . V_556 -> V_245 = V_42 -> V_294 ;
if ( V_552 != V_44 -> V_17 ) {
V_53 = F_46 ( V_552 , V_44 -> V_17 ,
V_295 ,
V_296 ,
& V_280 ) ;
if ( V_53 )
goto V_74;
}
if ( F_118 ( F_56 ( V_22 ) ) )
return 0 ;
V_53 = F_244 ( V_552 , V_24 -> V_17 , V_24 -> V_31 ,
V_548 , V_553 , V_554 , & V_280 ) ;
V_74:
return V_53 ;
}
static int F_245 ( struct V_42 * V_42 , unsigned int V_549 ,
unsigned long V_557 )
{
const struct V_10 * V_10 = F_67 () ;
int error = 0 ;
switch ( V_549 ) {
case V_558 :
case V_559 :
case V_560 :
case V_561 :
case V_562 :
error = F_123 ( V_10 , V_42 , V_528 ) ;
break;
case V_563 :
case V_564 :
error = F_123 ( V_10 , V_42 , V_526 ) ;
break;
case V_565 :
case V_566 :
error = F_123 ( V_10 , V_42 , 0 ) ;
break;
case V_567 :
case V_568 :
error = F_110 ( V_10 , V_569 ,
V_288 ) ;
break;
default:
error = F_243 ( V_10 , V_42 , V_347 , ( T_4 ) V_549 ) ;
}
return error ;
}
static int F_246 ( struct V_42 * V_42 , unsigned long V_570 , int V_571 )
{
const struct V_10 * V_10 = F_67 () ;
int V_53 = 0 ;
if ( V_572 &&
( V_570 & V_573 ) && ( ! V_42 || F_56 ( F_122 ( V_42 ) ) ||
( ! V_571 && ( V_570 & V_574 ) ) ) ) {
V_53 = F_107 ( V_10 , V_10 , V_575 ) ;
if ( V_53 )
goto error;
}
if ( V_42 ) {
T_2 V_283 = V_335 ;
if ( V_571 && ( V_570 & V_574 ) )
V_283 |= V_339 ;
if ( V_570 & V_573 )
V_283 |= V_333 ;
return F_123 ( V_10 , V_42 , V_283 ) ;
}
error:
return V_53 ;
}
static int F_247 ( unsigned long V_576 )
{
int V_53 = 0 ;
if ( V_576 < V_577 ) {
T_2 V_17 = F_22 () ;
V_53 = F_46 ( V_17 , V_17 , V_578 ,
V_579 , NULL ) ;
}
return V_53 ;
}
static int F_248 ( struct V_42 * V_42 , unsigned long V_580 ,
unsigned long V_570 , unsigned long V_79 )
{
if ( V_581 )
V_570 = V_580 ;
return F_246 ( V_42 , V_570 ,
( V_79 & V_582 ) == V_583 ) ;
}
static int F_249 ( struct V_584 * V_585 ,
unsigned long V_580 ,
unsigned long V_570 )
{
const struct V_10 * V_10 = F_67 () ;
if ( V_581 )
V_570 = V_580 ;
if ( V_572 &&
( V_570 & V_573 ) && ! ( V_585 -> V_586 & V_587 ) ) {
int V_53 = 0 ;
if ( V_585 -> V_588 >= V_585 -> V_589 -> V_590 &&
V_585 -> V_591 <= V_585 -> V_589 -> V_592 ) {
V_53 = F_107 ( V_10 , V_10 , V_593 ) ;
} else if ( ! V_585 -> V_594 &&
V_585 -> V_588 <= V_585 -> V_589 -> V_595 &&
V_585 -> V_591 >= V_585 -> V_589 -> V_595 ) {
V_53 = F_109 ( V_11 , V_596 ) ;
} else if ( V_585 -> V_594 && V_585 -> V_597 ) {
V_53 = F_123 ( V_10 , V_585 -> V_594 , V_598 ) ;
}
if ( V_53 )
return V_53 ;
}
return F_246 ( V_585 -> V_594 , V_570 , V_585 -> V_586 & V_599 ) ;
}
static int F_250 ( struct V_42 * V_42 , unsigned int V_549 )
{
const struct V_10 * V_10 = F_67 () ;
return F_123 ( V_10 , V_42 , V_600 ) ;
}
static int F_251 ( struct V_42 * V_42 , unsigned int V_549 ,
unsigned long V_557 )
{
const struct V_10 * V_10 = F_67 () ;
int V_601 = 0 ;
switch ( V_549 ) {
case V_602 :
if ( ( V_42 -> V_345 & V_346 ) && ! ( V_557 & V_346 ) ) {
V_601 = F_123 ( V_10 , V_42 , V_339 ) ;
break;
}
case V_603 :
case V_604 :
case V_605 :
case V_606 :
case V_607 :
case V_608 :
V_601 = F_123 ( V_10 , V_42 , 0 ) ;
break;
case V_609 :
case V_610 :
case V_611 :
case V_612 :
case V_613 :
case V_614 :
#if V_615 == 32
case V_616 :
case V_617 :
case V_618 :
#endif
V_601 = F_123 ( V_10 , V_42 , V_600 ) ;
break;
}
return V_601 ;
}
static void F_252 ( struct V_42 * V_42 )
{
struct V_43 * V_44 ;
V_44 = V_42 -> V_46 ;
V_44 -> V_45 = F_22 () ;
}
static int F_253 ( struct V_20 * V_276 ,
struct V_619 * V_620 , int V_621 )
{
struct V_42 * V_42 ;
T_2 V_17 = F_18 ( V_276 ) ;
T_2 V_256 ;
struct V_43 * V_44 ;
V_42 = F_29 ( V_620 , struct V_42 , V_622 ) ;
V_44 = V_42 -> V_46 ;
if ( ! V_621 )
V_256 = F_106 ( V_623 ) ;
else
V_256 = F_106 ( V_621 ) ;
return F_46 ( V_44 -> V_45 , V_17 ,
V_269 , V_256 , NULL ) ;
}
static int F_254 ( struct V_42 * V_42 )
{
const struct V_10 * V_10 = F_67 () ;
return F_123 ( V_10 , V_42 , F_134 ( V_42 ) ) ;
}
static int F_255 ( struct V_42 * V_42 , const struct V_10 * V_10 )
{
struct V_43 * V_44 ;
struct V_23 * V_24 ;
V_44 = V_42 -> V_46 ;
V_24 = F_122 ( V_42 ) -> V_33 ;
V_44 -> V_546 = V_24 -> V_17 ;
V_44 -> V_547 = F_240 () ;
return F_121 ( V_10 , V_42 , F_135 ( V_42 ) ) ;
}
static int F_256 ( unsigned long V_624 )
{
return F_109 ( V_11 , V_625 ) ;
}
static int F_257 ( struct V_10 * V_10 , T_12 V_626 )
{
struct V_13 * V_14 ;
V_14 = F_15 ( sizeof( struct V_13 ) , V_626 ) ;
if ( ! V_14 )
return - V_27 ;
V_10 -> V_19 = V_14 ;
return 0 ;
}
static void F_258 ( struct V_10 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_19 ;
F_63 ( V_10 -> V_19 && ( unsigned long ) V_10 -> V_19 < V_246 ) ;
V_10 -> V_19 = ( void * ) 0x7UL ;
F_39 ( V_14 ) ;
}
static int F_259 ( struct V_10 * V_128 , const struct V_10 * V_127 ,
T_12 V_626 )
{
const struct V_13 * V_408 ;
struct V_13 * V_14 ;
V_408 = V_127 -> V_19 ;
V_14 = F_260 ( V_408 , sizeof( struct V_13 ) , V_626 ) ;
if ( ! V_14 )
return - V_27 ;
V_128 -> V_19 = V_14 ;
return 0 ;
}
static void F_261 ( struct V_10 * V_128 , const struct V_10 * V_127 )
{
const struct V_13 * V_408 = V_127 -> V_19 ;
struct V_13 * V_14 = V_128 -> V_19 ;
* V_14 = * V_408 ;
}
static int F_262 ( struct V_10 * V_128 , T_2 V_545 )
{
struct V_13 * V_14 = V_128 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_627 ;
V_627 = F_46 ( V_17 , V_545 ,
V_628 ,
V_629 ,
NULL ) ;
if ( V_627 == 0 ) {
V_14 -> V_17 = V_545 ;
V_14 -> V_301 = 0 ;
V_14 -> V_419 = 0 ;
V_14 -> V_420 = 0 ;
}
return V_627 ;
}
static int F_263 ( struct V_10 * V_128 , struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_13 * V_14 = V_128 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_627 ;
V_627 = F_46 ( V_17 , V_24 -> V_17 ,
V_628 ,
V_630 ,
NULL ) ;
if ( V_627 == 0 )
V_14 -> V_301 = V_24 -> V_17 ;
return V_627 ;
}
static int F_264 ( char * V_631 )
{
T_2 V_17 ;
struct V_279 V_280 ;
V_17 = F_18 ( V_11 ) ;
V_280 . type = V_632 ;
V_280 . V_285 . V_631 = V_631 ;
return F_46 ( V_17 , V_18 , V_290 ,
V_633 , & V_280 ) ;
}
static int F_265 ( struct V_20 * V_145 , T_13 V_634 )
{
return F_109 ( V_145 , V_635 ) ;
}
static int F_266 ( struct V_20 * V_145 )
{
return F_109 ( V_145 , V_636 ) ;
}
static int F_267 ( struct V_20 * V_145 )
{
return F_109 ( V_145 , V_637 ) ;
}
static void F_268 ( struct V_20 * V_145 , T_2 * V_545 )
{
* V_545 = F_18 ( V_145 ) ;
}
static int F_269 ( struct V_20 * V_145 , int V_638 )
{
return F_109 ( V_145 , V_639 ) ;
}
static int F_270 ( struct V_20 * V_145 , int V_640 )
{
return F_109 ( V_145 , V_639 ) ;
}
static int F_271 ( struct V_20 * V_145 )
{
return F_109 ( V_145 , V_641 ) ;
}
static int F_272 ( struct V_20 * V_145 , unsigned int V_642 ,
struct V_450 * V_643 )
{
struct V_450 * V_644 = V_145 -> signal -> V_451 + V_642 ;
if ( V_644 -> V_458 != V_643 -> V_458 )
return F_109 ( V_145 , V_645 ) ;
return 0 ;
}
static int F_273 ( struct V_20 * V_145 )
{
return F_109 ( V_145 , V_639 ) ;
}
static int F_274 ( struct V_20 * V_145 )
{
return F_109 ( V_145 , V_641 ) ;
}
static int F_275 ( struct V_20 * V_145 )
{
return F_109 ( V_145 , V_639 ) ;
}
static int F_276 ( struct V_20 * V_145 , struct V_646 * V_647 ,
int V_255 , T_2 V_545 )
{
T_2 V_256 ;
int V_53 ;
if ( ! V_255 )
V_256 = V_648 ;
else
V_256 = F_106 ( V_255 ) ;
if ( V_545 )
V_53 = F_46 ( V_545 , F_18 ( V_145 ) ,
V_269 , V_256 , NULL ) ;
else
V_53 = F_109 ( V_145 , V_256 ) ;
return V_53 ;
}
static int F_277 ( struct V_20 * V_145 )
{
return F_108 ( V_145 , V_11 , V_258 ) ;
}
static void F_278 ( struct V_20 * V_145 ,
struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 = F_18 ( V_145 ) ;
V_24 -> V_17 = V_17 ;
V_24 -> V_124 = 1 ;
}
static int F_279 ( struct V_649 * V_650 ,
struct V_279 * V_280 , T_11 * V_651 )
{
int V_652 , V_653 , V_627 = - V_90 ;
struct V_654 V_655 , * V_656 ;
V_652 = F_280 ( V_650 ) ;
V_656 = F_281 ( V_650 , V_652 , sizeof( V_655 ) , & V_655 ) ;
if ( V_656 == NULL )
goto V_74;
V_653 = V_656 -> V_657 * 4 ;
if ( V_653 < sizeof( V_655 ) )
goto V_74;
V_280 -> V_285 . V_658 -> V_659 . V_660 = V_656 -> V_660 ;
V_280 -> V_285 . V_658 -> V_659 . V_661 = V_656 -> V_661 ;
V_627 = 0 ;
if ( V_651 )
* V_651 = V_656 -> V_183 ;
switch ( V_656 -> V_183 ) {
case V_185 : {
struct V_662 V_663 , * V_664 ;
if ( F_282 ( V_656 -> V_665 ) & V_666 )
break;
V_652 += V_653 ;
V_664 = F_281 ( V_650 , V_652 , sizeof( V_663 ) , & V_663 ) ;
if ( V_664 == NULL )
break;
V_280 -> V_285 . V_658 -> V_667 = V_664 -> V_668 ;
V_280 -> V_285 . V_658 -> V_669 = V_664 -> V_670 ;
break;
}
case V_186 : {
struct V_671 V_672 , * V_673 ;
if ( F_282 ( V_656 -> V_665 ) & V_666 )
break;
V_652 += V_653 ;
V_673 = F_281 ( V_650 , V_652 , sizeof( V_672 ) , & V_672 ) ;
if ( V_673 == NULL )
break;
V_280 -> V_285 . V_658 -> V_667 = V_673 -> V_668 ;
V_280 -> V_285 . V_658 -> V_669 = V_673 -> V_670 ;
break;
}
case V_674 : {
struct V_675 V_676 , * V_677 ;
if ( F_282 ( V_656 -> V_665 ) & V_666 )
break;
V_652 += V_653 ;
V_677 = F_281 ( V_650 , V_652 , sizeof( V_676 ) , & V_676 ) ;
if ( V_677 == NULL )
break;
V_280 -> V_285 . V_658 -> V_667 = V_677 -> V_678 ;
V_280 -> V_285 . V_658 -> V_669 = V_677 -> V_679 ;
break;
}
default:
break;
}
V_74:
return V_627 ;
}
static int F_283 ( struct V_649 * V_650 ,
struct V_279 * V_280 , T_11 * V_651 )
{
T_11 V_680 ;
int V_627 = - V_90 , V_652 ;
struct V_681 V_682 , * V_683 ;
T_14 V_665 ;
V_652 = F_280 ( V_650 ) ;
V_683 = F_281 ( V_650 , V_652 , sizeof( V_682 ) , & V_682 ) ;
if ( V_683 == NULL )
goto V_74;
V_280 -> V_285 . V_658 -> V_684 . V_660 = V_683 -> V_660 ;
V_280 -> V_285 . V_658 -> V_684 . V_661 = V_683 -> V_661 ;
V_627 = 0 ;
V_680 = V_683 -> V_680 ;
V_652 += sizeof( V_682 ) ;
V_652 = F_284 ( V_650 , V_652 , & V_680 , & V_665 ) ;
if ( V_652 < 0 )
goto V_74;
if ( V_651 )
* V_651 = V_680 ;
switch ( V_680 ) {
case V_185 : {
struct V_662 V_663 , * V_664 ;
V_664 = F_281 ( V_650 , V_652 , sizeof( V_663 ) , & V_663 ) ;
if ( V_664 == NULL )
break;
V_280 -> V_285 . V_658 -> V_667 = V_664 -> V_668 ;
V_280 -> V_285 . V_658 -> V_669 = V_664 -> V_670 ;
break;
}
case V_186 : {
struct V_671 V_672 , * V_673 ;
V_673 = F_281 ( V_650 , V_652 , sizeof( V_672 ) , & V_672 ) ;
if ( V_673 == NULL )
break;
V_280 -> V_285 . V_658 -> V_667 = V_673 -> V_668 ;
V_280 -> V_285 . V_658 -> V_669 = V_673 -> V_670 ;
break;
}
case V_674 : {
struct V_675 V_676 , * V_677 ;
V_677 = F_281 ( V_650 , V_652 , sizeof( V_676 ) , & V_676 ) ;
if ( V_677 == NULL )
break;
V_280 -> V_285 . V_658 -> V_667 = V_677 -> V_678 ;
V_280 -> V_285 . V_658 -> V_669 = V_677 -> V_679 ;
break;
}
default:
break;
}
V_74:
return V_627 ;
}
static int F_285 ( struct V_649 * V_650 , struct V_279 * V_280 ,
char * * V_685 , int V_686 , T_11 * V_651 )
{
char * V_687 ;
int V_627 ;
switch ( V_280 -> V_285 . V_658 -> V_187 ) {
case V_194 :
V_627 = F_279 ( V_650 , V_280 , V_651 ) ;
if ( V_627 )
goto V_688;
V_687 = ( char * ) ( V_686 ? & V_280 -> V_285 . V_658 -> V_659 . V_660 :
& V_280 -> V_285 . V_658 -> V_659 . V_661 ) ;
goto V_689;
#if F_286 ( V_690 ) || F_286 ( V_691 )
case V_195 :
V_627 = F_283 ( V_650 , V_280 , V_651 ) ;
if ( V_627 )
goto V_688;
V_687 = ( char * ) ( V_686 ? & V_280 -> V_285 . V_658 -> V_684 . V_660 :
& V_280 -> V_285 . V_658 -> V_684 . V_661 ) ;
goto V_689;
#endif
default:
V_687 = NULL ;
goto V_689;
}
V_688:
F_51 ( V_71
L_43
L_44 ) ;
return V_627 ;
V_689:
if ( V_685 )
* V_685 = V_687 ;
return 0 ;
}
static int F_287 ( struct V_649 * V_650 , T_4 V_187 , T_2 * V_17 )
{
int V_601 ;
T_2 V_692 ;
T_2 V_693 ;
T_2 V_694 ;
V_601 = F_288 ( V_650 , & V_692 ) ;
if ( F_118 ( V_601 ) )
return - V_417 ;
V_601 = F_289 ( V_650 , V_187 , & V_694 , & V_693 ) ;
if ( F_118 ( V_601 ) )
return - V_417 ;
V_601 = F_290 ( V_693 , V_694 , V_692 , V_17 ) ;
if ( F_118 ( V_601 ) ) {
F_51 ( V_71
L_45
L_46 ) ;
return - V_417 ;
}
return 0 ;
}
static int F_291 ( T_2 V_695 , T_2 V_696 , T_2 * V_697 )
{
int V_601 = 0 ;
if ( V_696 != V_698 )
V_601 = F_292 ( V_695 , V_696 , V_697 ) ;
else
* V_697 = V_695 ;
return V_601 ;
}
static int F_293 ( const struct V_13 * V_14 ,
T_4 V_699 , T_2 * V_700 )
{
if ( V_14 -> V_420 > V_698 ) {
* V_700 = V_14 -> V_420 ;
return 0 ;
}
return F_104 ( V_14 -> V_17 , V_14 -> V_17 , V_699 , NULL ,
V_700 ) ;
}
static int F_294 ( struct V_20 * V_21 , struct V_701 * V_702 , T_2 V_266 )
{
struct V_703 * V_704 = V_702 -> V_705 ;
struct V_279 V_280 ;
struct V_706 V_658 = { 0 ,} ;
T_2 V_268 = F_18 ( V_21 ) ;
if ( V_704 -> V_17 == V_18 )
return 0 ;
V_280 . type = V_707 ;
V_280 . V_285 . V_658 = & V_658 ;
V_280 . V_285 . V_658 -> V_702 = V_702 ;
return F_46 ( V_268 , V_704 -> V_17 , V_704 -> V_31 , V_266 , & V_280 ) ;
}
static int F_295 ( int V_187 , int type ,
int V_183 , int V_708 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_302 ;
T_4 V_699 ;
int V_53 ;
if ( V_708 )
return 0 ;
V_699 = F_88 ( V_187 , type , V_183 ) ;
V_53 = F_293 ( V_14 , V_699 , & V_302 ) ;
if ( V_53 )
return V_53 ;
return F_46 ( V_14 -> V_17 , V_302 , V_699 , V_709 , NULL ) ;
}
static int F_296 ( struct V_710 * V_701 , int V_187 ,
int type , int V_183 , int V_708 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_24 = F_297 ( V_701 ) -> V_33 ;
struct V_703 * V_704 ;
int V_601 = 0 ;
V_24 -> V_31 = F_88 ( V_187 , type , V_183 ) ;
if ( V_708 )
V_24 -> V_17 = V_18 ;
else {
V_601 = F_293 ( V_14 , V_24 -> V_31 , & ( V_24 -> V_17 ) ) ;
if ( V_601 )
return V_601 ;
}
V_24 -> V_124 = 1 ;
if ( V_701 -> V_702 ) {
V_704 = V_701 -> V_702 -> V_705 ;
V_704 -> V_17 = V_24 -> V_17 ;
V_704 -> V_31 = V_24 -> V_31 ;
V_601 = F_298 ( V_701 -> V_702 , V_187 ) ;
}
return V_601 ;
}
static int F_299 ( struct V_710 * V_701 , struct V_711 * V_712 , int V_713 )
{
struct V_701 * V_702 = V_701 -> V_702 ;
T_4 V_187 ;
int V_601 ;
V_601 = F_294 ( V_11 , V_702 , V_714 ) ;
if ( V_601 )
goto V_74;
V_187 = V_702 -> V_715 ;
if ( V_187 == V_194 || V_187 == V_195 ) {
char * V_687 ;
struct V_703 * V_704 = V_702 -> V_705 ;
struct V_279 V_280 ;
struct V_706 V_658 = { 0 ,} ;
struct V_716 * V_717 = NULL ;
struct V_718 * V_719 = NULL ;
unsigned short V_720 ;
T_2 V_17 , V_721 ;
if ( V_187 == V_194 ) {
V_717 = (struct V_716 * ) V_712 ;
V_720 = F_282 ( V_717 -> V_722 ) ;
V_687 = ( char * ) & V_717 -> V_723 . V_724 ;
} else {
V_719 = (struct V_718 * ) V_712 ;
V_720 = F_282 ( V_719 -> V_725 ) ;
V_687 = ( char * ) & V_719 -> V_726 . V_727 ;
}
if ( V_720 ) {
int V_728 , V_729 ;
F_300 ( F_301 ( V_702 ) , & V_728 , & V_729 ) ;
if ( V_720 < V_730 ( V_731, V_728 ) || V_720 > V_729 ) {
V_601 = F_302 ( V_702 -> V_732 ,
V_720 , & V_17 ) ;
if ( V_601 )
goto V_74;
V_280 . type = V_707 ;
V_280 . V_285 . V_658 = & V_658 ;
V_280 . V_285 . V_658 -> V_667 = F_303 ( V_720 ) ;
V_280 . V_285 . V_658 -> V_187 = V_187 ;
V_601 = F_46 ( V_704 -> V_17 , V_17 ,
V_704 -> V_31 ,
V_733 , & V_280 ) ;
if ( V_601 )
goto V_74;
}
}
switch ( V_704 -> V_31 ) {
case V_196 :
V_721 = V_734 ;
break;
case V_198 :
V_721 = V_735 ;
break;
case V_200 :
V_721 = V_736 ;
break;
default:
V_721 = V_737 ;
break;
}
V_601 = F_304 ( V_687 , V_187 , & V_17 ) ;
if ( V_601 )
goto V_74;
V_280 . type = V_707 ;
V_280 . V_285 . V_658 = & V_658 ;
V_280 . V_285 . V_658 -> V_667 = F_303 ( V_720 ) ;
V_280 . V_285 . V_658 -> V_187 = V_187 ;
if ( V_187 == V_194 )
V_280 . V_285 . V_658 -> V_659 . V_660 = V_717 -> V_723 . V_724 ;
else
V_280 . V_285 . V_658 -> V_684 . V_660 = V_719 -> V_726 ;
V_601 = F_46 ( V_704 -> V_17 , V_17 ,
V_704 -> V_31 , V_721 , & V_280 ) ;
if ( V_601 )
goto V_74;
}
V_74:
return V_601 ;
}
static int F_305 ( struct V_710 * V_701 , struct V_711 * V_712 , int V_713 )
{
struct V_701 * V_702 = V_701 -> V_702 ;
struct V_703 * V_704 = V_702 -> V_705 ;
int V_601 ;
V_601 = F_294 ( V_11 , V_702 , V_738 ) ;
if ( V_601 )
return V_601 ;
if ( V_704 -> V_31 == V_196 ||
V_704 -> V_31 == V_200 ) {
struct V_279 V_280 ;
struct V_706 V_658 = { 0 ,} ;
struct V_716 * V_717 = NULL ;
struct V_718 * V_719 = NULL ;
unsigned short V_720 ;
T_2 V_17 , V_256 ;
if ( V_702 -> V_715 == V_194 ) {
V_717 = (struct V_716 * ) V_712 ;
if ( V_713 < sizeof( struct V_716 ) )
return - V_90 ;
V_720 = F_282 ( V_717 -> V_722 ) ;
} else {
V_719 = (struct V_718 * ) V_712 ;
if ( V_713 < V_739 )
return - V_90 ;
V_720 = F_282 ( V_719 -> V_725 ) ;
}
V_601 = F_302 ( V_702 -> V_732 , V_720 , & V_17 ) ;
if ( V_601 )
goto V_74;
V_256 = ( V_704 -> V_31 == V_196 ) ?
V_740 : V_741 ;
V_280 . type = V_707 ;
V_280 . V_285 . V_658 = & V_658 ;
V_280 . V_285 . V_658 -> V_669 = F_303 ( V_720 ) ;
V_280 . V_285 . V_658 -> V_187 = V_702 -> V_715 ;
V_601 = F_46 ( V_704 -> V_17 , V_17 , V_704 -> V_31 , V_256 , & V_280 ) ;
if ( V_601 )
goto V_74;
}
V_601 = F_306 ( V_702 , V_712 ) ;
V_74:
return V_601 ;
}
static int F_307 ( struct V_710 * V_701 , int V_742 )
{
return F_294 ( V_11 , V_701 -> V_702 , V_743 ) ;
}
static int F_308 ( struct V_710 * V_701 , struct V_710 * V_744 )
{
int V_601 ;
struct V_23 * V_24 ;
struct V_23 * V_141 ;
V_601 = F_294 ( V_11 , V_701 -> V_702 , V_745 ) ;
if ( V_601 )
return V_601 ;
V_141 = F_297 ( V_744 ) -> V_33 ;
V_24 = F_297 ( V_701 ) -> V_33 ;
V_141 -> V_31 = V_24 -> V_31 ;
V_141 -> V_17 = V_24 -> V_17 ;
V_141 -> V_124 = 1 ;
return 0 ;
}
static int F_309 ( struct V_710 * V_701 , struct V_746 * V_747 ,
int V_532 )
{
return F_294 ( V_11 , V_701 -> V_702 , V_748 ) ;
}
static int F_310 ( struct V_710 * V_701 , struct V_746 * V_747 ,
int V_532 , int V_79 )
{
return F_294 ( V_11 , V_701 -> V_702 , V_749 ) ;
}
static int F_311 ( struct V_710 * V_701 )
{
return F_294 ( V_11 , V_701 -> V_702 , V_750 ) ;
}
static int F_312 ( struct V_710 * V_701 )
{
return F_294 ( V_11 , V_701 -> V_702 , V_750 ) ;
}
static int F_313 ( struct V_710 * V_701 , int V_751 , int V_752 )
{
int V_601 ;
V_601 = F_294 ( V_11 , V_701 -> V_702 , V_753 ) ;
if ( V_601 )
return V_601 ;
return F_314 ( V_701 , V_751 , V_752 ) ;
}
static int F_315 ( struct V_710 * V_701 , int V_751 ,
int V_752 )
{
return F_294 ( V_11 , V_701 -> V_702 , V_754 ) ;
}
static int F_316 ( struct V_710 * V_701 , int V_755 )
{
return F_294 ( V_11 , V_701 -> V_702 , V_756 ) ;
}
static int F_317 ( struct V_701 * V_701 ,
struct V_701 * V_757 ,
struct V_701 * V_758 )
{
struct V_703 * V_759 = V_701 -> V_705 ;
struct V_703 * V_760 = V_757 -> V_705 ;
struct V_703 * V_761 = V_758 -> V_705 ;
struct V_279 V_280 ;
struct V_706 V_658 = { 0 ,} ;
int V_601 ;
V_280 . type = V_707 ;
V_280 . V_285 . V_658 = & V_658 ;
V_280 . V_285 . V_658 -> V_702 = V_757 ;
V_601 = F_46 ( V_759 -> V_17 , V_760 -> V_17 ,
V_760 -> V_31 ,
V_762 , & V_280 ) ;
if ( V_601 )
return V_601 ;
V_761 -> V_763 = V_759 -> V_17 ;
V_601 = F_292 ( V_760 -> V_17 , V_759 -> V_17 ,
& V_761 -> V_17 ) ;
if ( V_601 )
return V_601 ;
V_759 -> V_763 = V_761 -> V_17 ;
return 0 ;
}
static int F_318 ( struct V_710 * V_701 ,
struct V_710 * V_757 )
{
struct V_703 * V_764 = V_701 -> V_702 -> V_705 ;
struct V_703 * V_765 = V_757 -> V_702 -> V_705 ;
struct V_279 V_280 ;
struct V_706 V_658 = { 0 ,} ;
V_280 . type = V_707 ;
V_280 . V_285 . V_658 = & V_658 ;
V_280 . V_285 . V_658 -> V_702 = V_757 -> V_702 ;
return F_46 ( V_764 -> V_17 , V_765 -> V_17 , V_765 -> V_31 , V_766 ,
& V_280 ) ;
}
static int F_319 ( struct V_658 * V_373 , int V_767 ,
char * V_687 , T_4 V_187 , T_2 V_763 ,
struct V_279 * V_280 )
{
int V_601 ;
T_2 V_768 ;
T_2 V_769 ;
V_601 = F_320 ( V_373 , V_767 , & V_768 ) ;
if ( V_601 )
return V_601 ;
V_601 = F_46 ( V_763 , V_768 ,
V_770 , V_771 , V_280 ) ;
if ( V_601 )
return V_601 ;
V_601 = F_304 ( V_687 , V_187 , & V_769 ) ;
if ( V_601 )
return V_601 ;
return F_46 ( V_763 , V_769 ,
V_772 , V_773 , V_280 ) ;
}
static int F_321 ( struct V_701 * V_702 , struct V_649 * V_650 ,
T_4 V_187 )
{
int V_601 = 0 ;
struct V_703 * V_704 = V_702 -> V_705 ;
T_2 V_695 = V_704 -> V_17 ;
struct V_279 V_280 ;
struct V_706 V_658 = { 0 ,} ;
char * V_687 ;
V_280 . type = V_707 ;
V_280 . V_285 . V_658 = & V_658 ;
V_280 . V_285 . V_658 -> V_774 = V_650 -> V_775 ;
V_280 . V_285 . V_658 -> V_187 = V_187 ;
V_601 = F_285 ( V_650 , & V_280 , & V_687 , 1 , NULL ) ;
if ( V_601 )
return V_601 ;
if ( F_4 () ) {
V_601 = F_46 ( V_695 , V_650 -> V_776 , V_777 ,
V_778 , & V_280 ) ;
if ( V_601 )
return V_601 ;
}
V_601 = F_322 ( V_704 , V_650 , V_187 , & V_280 ) ;
if ( V_601 )
return V_601 ;
V_601 = F_323 ( V_704 -> V_17 , V_650 , & V_280 ) ;
return V_601 ;
}
static int F_324 ( struct V_701 * V_702 , struct V_649 * V_650 )
{
int V_601 ;
struct V_703 * V_704 = V_702 -> V_705 ;
T_4 V_187 = V_702 -> V_715 ;
T_2 V_695 = V_704 -> V_17 ;
struct V_279 V_280 ;
struct V_706 V_658 = { 0 ,} ;
char * V_687 ;
T_11 V_779 ;
T_11 V_780 ;
if ( V_187 != V_194 && V_187 != V_195 )
return 0 ;
if ( V_187 == V_195 && V_650 -> V_183 == F_303 ( V_781 ) )
V_187 = V_194 ;
if ( ! V_782 )
return F_321 ( V_702 , V_650 , V_187 ) ;
V_779 = F_4 () ;
V_780 = F_6 () ;
if ( ! V_779 && ! V_780 )
return 0 ;
V_280 . type = V_707 ;
V_280 . V_285 . V_658 = & V_658 ;
V_280 . V_285 . V_658 -> V_774 = V_650 -> V_775 ;
V_280 . V_285 . V_658 -> V_187 = V_187 ;
V_601 = F_285 ( V_650 , & V_280 , & V_687 , 1 , NULL ) ;
if ( V_601 )
return V_601 ;
if ( V_780 ) {
T_2 V_763 ;
V_601 = F_287 ( V_650 , V_187 , & V_763 ) ;
if ( V_601 )
return V_601 ;
V_601 = F_319 ( F_301 ( V_702 ) , V_650 -> V_775 ,
V_687 , V_187 , V_763 , & V_280 ) ;
if ( V_601 ) {
F_325 ( V_650 , V_601 , 0 ) ;
return V_601 ;
}
V_601 = F_46 ( V_695 , V_763 , V_783 ,
V_784 , & V_280 ) ;
if ( V_601 ) {
F_325 ( V_650 , V_601 , 0 ) ;
return V_601 ;
}
}
if ( V_779 ) {
V_601 = F_46 ( V_695 , V_650 -> V_776 , V_777 ,
V_778 , & V_280 ) ;
if ( V_601 )
return V_601 ;
}
return V_601 ;
}
static int F_326 ( struct V_710 * V_701 , char T_15 * V_785 ,
int T_15 * V_786 , unsigned V_88 )
{
int V_601 = 0 ;
char * V_787 ;
T_2 V_788 ;
struct V_703 * V_704 = V_701 -> V_702 -> V_705 ;
T_2 V_763 = V_698 ;
if ( V_704 -> V_31 == V_191 ||
V_704 -> V_31 == V_196 )
V_763 = V_704 -> V_763 ;
if ( V_763 == V_698 )
return - V_789 ;
V_601 = F_62 ( V_763 , & V_787 , & V_788 ) ;
if ( V_601 )
return V_601 ;
if ( V_788 > V_88 ) {
V_601 = - V_249 ;
goto V_790;
}
if ( F_327 ( V_785 , V_787 , V_788 ) )
V_601 = - V_791 ;
V_790:
if ( F_328 ( V_788 , V_786 ) )
V_601 = - V_791 ;
F_39 ( V_787 ) ;
return V_601 ;
}
static int F_329 ( struct V_710 * V_701 , struct V_649 * V_650 , T_2 * V_545 )
{
T_2 V_792 = V_698 ;
T_4 V_187 ;
if ( V_650 && V_650 -> V_183 == F_303 ( V_781 ) )
V_187 = V_194 ;
else if ( V_650 && V_650 -> V_183 == F_303 ( V_793 ) )
V_187 = V_195 ;
else if ( V_701 )
V_187 = V_701 -> V_702 -> V_715 ;
else
goto V_74;
if ( V_701 && V_187 == V_188 )
F_237 ( F_297 ( V_701 ) , & V_792 ) ;
else if ( V_650 )
F_287 ( V_650 , V_187 , & V_792 ) ;
V_74:
* V_545 = V_792 ;
if ( V_792 == V_698 )
return - V_90 ;
return 0 ;
}
static int F_330 ( struct V_701 * V_702 , int V_187 , T_12 V_794 )
{
struct V_703 * V_704 ;
V_704 = F_15 ( sizeof( * V_704 ) , V_794 ) ;
if ( ! V_704 )
return - V_27 ;
V_704 -> V_763 = V_30 ;
V_704 -> V_17 = V_30 ;
V_704 -> V_31 = V_241 ;
F_331 ( V_704 ) ;
V_702 -> V_705 = V_704 ;
return 0 ;
}
static void F_332 ( struct V_701 * V_702 )
{
struct V_703 * V_704 = V_702 -> V_705 ;
V_702 -> V_705 = NULL ;
F_333 ( V_704 ) ;
F_39 ( V_704 ) ;
}
static void F_334 ( const struct V_701 * V_702 , struct V_701 * V_758 )
{
struct V_703 * V_704 = V_702 -> V_705 ;
struct V_703 * V_795 = V_758 -> V_705 ;
V_795 -> V_17 = V_704 -> V_17 ;
V_795 -> V_763 = V_704 -> V_763 ;
V_795 -> V_31 = V_704 -> V_31 ;
F_331 ( V_795 ) ;
}
static void F_335 ( struct V_701 * V_702 , T_2 * V_545 )
{
if ( ! V_702 )
* V_545 = V_796 ;
else {
struct V_703 * V_704 = V_702 -> V_705 ;
* V_545 = V_704 -> V_17 ;
}
}
static void F_336 ( struct V_701 * V_702 , struct V_710 * V_366 )
{
struct V_23 * V_24 = F_297 ( V_366 ) -> V_33 ;
struct V_703 * V_704 = V_702 -> V_705 ;
if ( V_702 -> V_715 == V_194 || V_702 -> V_715 == V_195 ||
V_702 -> V_715 == V_188 )
V_24 -> V_17 = V_704 -> V_17 ;
V_704 -> V_31 = V_24 -> V_31 ;
}
static int F_337 ( struct V_701 * V_702 , struct V_649 * V_650 ,
struct V_797 * V_798 )
{
struct V_703 * V_704 = V_702 -> V_705 ;
int V_601 ;
T_4 V_187 = V_798 -> V_799 -> V_187 ;
T_2 V_800 ;
T_2 V_801 ;
V_601 = F_287 ( V_650 , V_187 , & V_801 ) ;
if ( V_601 )
return V_601 ;
V_601 = F_291 ( V_704 -> V_17 , V_801 , & V_800 ) ;
if ( V_601 )
return V_601 ;
V_798 -> V_545 = V_800 ;
V_798 -> V_792 = V_801 ;
return F_338 ( V_798 , V_187 ) ;
}
static void F_339 ( struct V_701 * V_758 ,
const struct V_797 * V_798 )
{
struct V_703 * V_795 = V_758 -> V_705 ;
V_795 -> V_17 = V_798 -> V_545 ;
V_795 -> V_763 = V_798 -> V_792 ;
F_340 ( V_758 , V_798 -> V_799 -> V_187 ) ;
}
static void F_341 ( struct V_701 * V_702 , struct V_649 * V_650 )
{
T_4 V_187 = V_702 -> V_715 ;
struct V_703 * V_704 = V_702 -> V_705 ;
if ( V_187 == V_195 && V_650 -> V_183 == F_303 ( V_781 ) )
V_187 = V_194 ;
F_287 ( V_650 , V_187 , & V_704 -> V_763 ) ;
}
static int F_342 ( T_2 V_17 )
{
const struct V_13 * V_802 ;
T_2 V_268 ;
V_802 = F_23 () ;
V_268 = V_802 -> V_17 ;
return F_46 ( V_268 , V_17 , V_777 , V_803 , NULL ) ;
}
static void F_343 ( void )
{
F_344 ( & V_7 ) ;
}
static void F_345 ( void )
{
F_346 ( & V_7 ) ;
}
static void F_347 ( const struct V_797 * V_798 ,
struct V_804 * V_805 )
{
V_805 -> V_806 = V_798 -> V_545 ;
}
static int F_348 ( void * * V_19 )
{
struct V_807 * V_808 ;
V_808 = F_15 ( sizeof( * V_808 ) , V_15 ) ;
if ( ! V_808 )
return - V_27 ;
V_808 -> V_17 = F_22 () ;
* V_19 = V_808 ;
return 0 ;
}
static void F_349 ( void * V_19 )
{
F_39 ( V_19 ) ;
}
static int F_350 ( void )
{
T_2 V_17 = F_22 () ;
return F_46 ( V_17 , V_17 , V_809 , V_810 ,
NULL ) ;
}
static int F_351 ( void * V_19 )
{
struct V_807 * V_808 = V_19 ;
return F_46 ( F_22 () , V_808 -> V_17 , V_809 ,
V_811 , NULL ) ;
}
static int F_352 ( struct V_701 * V_702 , void * V_19 )
{
struct V_807 * V_808 = V_19 ;
struct V_703 * V_704 = V_702 -> V_705 ;
V_704 -> V_17 = V_808 -> V_17 ;
V_704 -> V_31 = V_809 ;
return 0 ;
}
static int F_353 ( void * V_19 )
{
struct V_807 * V_808 = V_19 ;
T_2 V_17 = F_22 () ;
int V_601 ;
V_601 = F_46 ( V_17 , V_808 -> V_17 , V_809 ,
V_812 , NULL ) ;
if ( V_601 )
return V_601 ;
V_601 = F_46 ( V_17 , V_17 , V_809 ,
V_813 , NULL ) ;
if ( V_601 )
return V_601 ;
V_808 -> V_17 = V_17 ;
return 0 ;
}
static int F_354 ( struct V_701 * V_702 , struct V_649 * V_650 )
{
int V_601 = 0 ;
T_2 V_256 ;
struct V_814 * V_815 ;
struct V_703 * V_704 = V_702 -> V_705 ;
if ( V_650 -> V_88 < V_816 ) {
V_601 = - V_90 ;
goto V_74;
}
V_815 = F_355 ( V_650 ) ;
V_601 = F_356 ( V_704 -> V_31 , V_815 -> V_817 , & V_256 ) ;
if ( V_601 ) {
if ( V_601 == - V_90 ) {
F_51 ( V_71
L_47
L_48 ,
V_702 -> V_732 , V_815 -> V_817 ,
V_818 [ V_704 -> V_31 - 1 ] . V_64 ) ;
if ( ! V_3 || F_357 () )
V_601 = 0 ;
}
if ( V_601 == - V_819 )
V_601 = 0 ;
goto V_74;
}
V_601 = F_294 ( V_11 , V_702 , V_256 ) ;
V_74:
return V_601 ;
}
static unsigned int F_358 ( struct V_649 * V_650 ,
const struct V_820 * V_821 ,
T_4 V_187 )
{
int V_601 ;
char * V_687 ;
T_2 V_763 ;
struct V_279 V_280 ;
struct V_706 V_658 = { 0 ,} ;
T_11 V_779 ;
T_11 V_822 ;
T_11 V_780 ;
if ( ! V_782 )
return V_823 ;
V_779 = F_4 () ;
V_822 = F_7 () ;
V_780 = F_6 () ;
if ( ! V_779 && ! V_780 )
return V_823 ;
if ( F_287 ( V_650 , V_187 , & V_763 ) != 0 )
return V_824 ;
V_280 . type = V_707 ;
V_280 . V_285 . V_658 = & V_658 ;
V_280 . V_285 . V_658 -> V_774 = V_821 -> V_767 ;
V_280 . V_285 . V_658 -> V_187 = V_187 ;
if ( F_285 ( V_650 , & V_280 , & V_687 , 1 , NULL ) != 0 )
return V_824 ;
if ( V_780 ) {
V_601 = F_319 ( F_359 ( V_821 ) , V_821 -> V_767 ,
V_687 , V_187 , V_763 , & V_280 ) ;
if ( V_601 ) {
F_325 ( V_650 , V_601 , 1 ) ;
return V_824 ;
}
}
if ( V_779 )
if ( F_46 ( V_763 , V_650 -> V_776 ,
V_777 , V_825 , & V_280 ) )
return V_824 ;
if ( V_822 )
if ( F_360 ( V_650 , V_187 , V_763 ) != 0 )
return V_824 ;
return V_823 ;
}
static unsigned int F_361 ( const struct V_826 * V_827 ,
struct V_649 * V_650 ,
const struct V_828 * V_829 )
{
return F_358 ( V_650 , V_829 -> V_830 , V_194 ) ;
}
static unsigned int F_362 ( const struct V_826 * V_827 ,
struct V_649 * V_650 ,
const struct V_828 * V_829 )
{
return F_358 ( V_650 , V_829 -> V_830 , V_195 ) ;
}
static unsigned int F_363 ( struct V_649 * V_650 ,
T_4 V_187 )
{
struct V_701 * V_702 ;
T_2 V_17 ;
if ( ! F_7 () )
return V_823 ;
V_702 = V_650 -> V_702 ;
if ( V_702 ) {
struct V_703 * V_704 ;
if ( V_702 -> V_831 == V_832 )
return V_823 ;
V_704 = V_702 -> V_705 ;
V_17 = V_704 -> V_17 ;
} else
V_17 = V_18 ;
if ( F_360 ( V_650 , V_187 , V_17 ) != 0 )
return V_824 ;
return V_823 ;
}
static unsigned int F_364 ( const struct V_826 * V_827 ,
struct V_649 * V_650 ,
const struct V_828 * V_829 )
{
return F_363 ( V_650 , V_194 ) ;
}
static unsigned int F_365 ( struct V_649 * V_650 ,
int V_767 ,
T_4 V_187 )
{
struct V_701 * V_702 = V_650 -> V_702 ;
struct V_703 * V_704 ;
struct V_279 V_280 ;
struct V_706 V_658 = { 0 ,} ;
char * V_687 ;
T_11 V_651 ;
if ( V_702 == NULL )
return V_823 ;
V_704 = V_702 -> V_705 ;
V_280 . type = V_707 ;
V_280 . V_285 . V_658 = & V_658 ;
V_280 . V_285 . V_658 -> V_774 = V_767 ;
V_280 . V_285 . V_658 -> V_187 = V_187 ;
if ( F_285 ( V_650 , & V_280 , & V_687 , 0 , & V_651 ) )
return V_824 ;
if ( F_4 () )
if ( F_46 ( V_704 -> V_17 , V_650 -> V_776 ,
V_777 , V_833 , & V_280 ) )
return F_366 ( - V_834 ) ;
if ( F_367 ( V_704 -> V_17 , V_650 , & V_280 , V_651 ) )
return F_366 ( - V_834 ) ;
return V_823 ;
}
static unsigned int F_368 ( struct V_649 * V_650 ,
const struct V_820 * V_835 ,
T_4 V_187 )
{
T_2 V_836 ;
T_2 V_763 ;
int V_767 = V_835 -> V_767 ;
struct V_701 * V_702 ;
struct V_279 V_280 ;
struct V_706 V_658 = { 0 ,} ;
char * V_687 ;
T_11 V_779 ;
T_11 V_780 ;
if ( ! V_782 )
return F_365 ( V_650 , V_767 , V_187 ) ;
V_779 = F_4 () ;
V_780 = F_6 () ;
if ( ! V_779 && ! V_780 )
return V_823 ;
V_702 = V_650 -> V_702 ;
#ifdef F_369
if ( F_370 ( V_650 ) != NULL && F_370 ( V_650 ) -> V_837 != NULL &&
! ( V_702 != NULL && V_702 -> V_831 == V_832 ) )
return V_823 ;
#endif
if ( V_702 == NULL ) {
if ( V_650 -> V_775 ) {
V_836 = V_838 ;
if ( F_287 ( V_650 , V_187 , & V_763 ) )
return V_824 ;
} else {
V_836 = V_833 ;
V_763 = V_18 ;
}
} else if ( V_702 -> V_831 == V_832 ) {
T_2 V_696 ;
struct V_703 * V_704 = V_702 -> V_705 ;
if ( F_287 ( V_650 , V_187 , & V_696 ) )
return V_824 ;
if ( V_696 == V_698 ) {
switch ( V_187 ) {
case V_194 :
if ( F_371 ( V_650 ) -> V_79 & V_839 )
return V_823 ;
break;
case V_195 :
if ( F_372 ( V_650 ) -> V_79 & V_840 )
return V_823 ;
break;
default:
return F_366 ( - V_834 ) ;
}
}
if ( F_291 ( V_704 -> V_17 , V_696 , & V_763 ) )
return V_824 ;
V_836 = V_833 ;
} else {
struct V_703 * V_704 = V_702 -> V_705 ;
V_763 = V_704 -> V_17 ;
V_836 = V_833 ;
}
V_280 . type = V_707 ;
V_280 . V_285 . V_658 = & V_658 ;
V_280 . V_285 . V_658 -> V_774 = V_767 ;
V_280 . V_285 . V_658 -> V_187 = V_187 ;
if ( F_285 ( V_650 , & V_280 , & V_687 , 0 , NULL ) )
return V_824 ;
if ( V_779 )
if ( F_46 ( V_763 , V_650 -> V_776 ,
V_777 , V_836 , & V_280 ) )
return F_366 ( - V_834 ) ;
if ( V_780 ) {
T_2 V_768 ;
T_2 V_769 ;
if ( F_320 ( F_359 ( V_835 ) , V_767 , & V_768 ) )
return V_824 ;
if ( F_46 ( V_763 , V_768 ,
V_770 , V_841 , & V_280 ) )
return F_366 ( - V_834 ) ;
if ( F_304 ( V_687 , V_187 , & V_769 ) )
return V_824 ;
if ( F_46 ( V_763 , V_769 ,
V_772 , V_842 , & V_280 ) )
return F_366 ( - V_834 ) ;
}
return V_823 ;
}
static unsigned int F_373 ( const struct V_826 * V_827 ,
struct V_649 * V_650 ,
const struct V_828 * V_829 )
{
return F_368 ( V_650 , V_829 -> V_74 , V_194 ) ;
}
static unsigned int F_374 ( const struct V_826 * V_827 ,
struct V_649 * V_650 ,
const struct V_828 * V_829 )
{
return F_368 ( V_650 , V_829 -> V_74 , V_195 ) ;
}
static int F_375 ( struct V_701 * V_702 , struct V_649 * V_650 )
{
return F_354 ( V_702 , V_650 ) ;
}
static int F_376 ( struct V_20 * V_21 ,
struct V_843 * V_256 ,
T_4 V_31 )
{
struct V_844 * V_24 ;
T_2 V_17 ;
V_24 = F_15 ( sizeof( struct V_844 ) , V_15 ) ;
if ( ! V_24 )
return - V_27 ;
V_17 = F_18 ( V_21 ) ;
V_24 -> V_31 = V_31 ;
V_24 -> V_17 = V_17 ;
V_256 -> V_19 = V_24 ;
return 0 ;
}
static void F_377 ( struct V_843 * V_256 )
{
struct V_844 * V_24 = V_256 -> V_19 ;
V_256 -> V_19 = NULL ;
F_39 ( V_24 ) ;
}
static int F_378 ( struct V_845 * V_747 )
{
struct V_846 * V_847 ;
V_847 = F_15 ( sizeof( struct V_846 ) , V_15 ) ;
if ( ! V_847 )
return - V_27 ;
V_847 -> V_17 = V_30 ;
V_747 -> V_19 = V_847 ;
return 0 ;
}
static void F_379 ( struct V_845 * V_747 )
{
struct V_846 * V_847 = V_747 -> V_19 ;
V_747 -> V_19 = NULL ;
F_39 ( V_847 ) ;
}
static int F_380 ( struct V_843 * V_848 ,
T_2 V_266 )
{
struct V_844 * V_24 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
V_24 = V_848 -> V_19 ;
V_280 . type = V_849 ;
V_280 . V_285 . V_850 = V_848 -> V_851 ;
return F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_266 , & V_280 ) ;
}
static int F_381 ( struct V_845 * V_747 )
{
return F_378 ( V_747 ) ;
}
static void F_382 ( struct V_845 * V_747 )
{
F_379 ( V_747 ) ;
}
static int F_383 ( struct V_852 * V_853 )
{
struct V_844 * V_24 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_53 = F_376 ( V_11 , & V_853 -> V_854 , V_855 ) ;
if ( V_53 )
return V_53 ;
V_24 = V_853 -> V_854 . V_19 ;
V_280 . type = V_849 ;
V_280 . V_285 . V_850 = V_853 -> V_854 . V_851 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_855 ,
V_856 , & V_280 ) ;
if ( V_53 ) {
F_377 ( & V_853 -> V_854 ) ;
return V_53 ;
}
return 0 ;
}
static void F_384 ( struct V_852 * V_853 )
{
F_377 ( & V_853 -> V_854 ) ;
}
static int F_385 ( struct V_852 * V_853 , int V_857 )
{
struct V_844 * V_24 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
V_24 = V_853 -> V_854 . V_19 ;
V_280 . type = V_849 ;
V_280 . V_285 . V_850 = V_853 -> V_854 . V_851 ;
return F_46 ( V_17 , V_24 -> V_17 , V_855 ,
V_858 , & V_280 ) ;
}
static int F_386 ( struct V_852 * V_853 , int V_549 )
{
int V_601 ;
int V_266 ;
switch ( V_549 ) {
case V_859 :
case V_860 :
return F_115 ( V_11 , V_861 ) ;
case V_862 :
case V_863 :
V_266 = V_864 | V_858 ;
break;
case V_865 :
V_266 = V_866 ;
break;
case V_867 :
V_266 = V_868 ;
break;
default:
return 0 ;
}
V_601 = F_380 ( & V_853 -> V_854 , V_266 ) ;
return V_601 ;
}
static int F_387 ( struct V_852 * V_853 , struct V_845 * V_747 , int V_857 )
{
struct V_844 * V_24 ;
struct V_846 * V_847 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_24 = V_853 -> V_854 . V_19 ;
V_847 = V_747 -> V_19 ;
if ( V_847 -> V_17 == V_30 ) {
V_53 = F_104 ( V_17 , V_24 -> V_17 , V_869 ,
NULL , & V_847 -> V_17 ) ;
if ( V_53 )
return V_53 ;
}
V_280 . type = V_849 ;
V_280 . V_285 . V_850 = V_853 -> V_854 . V_851 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_855 ,
V_870 , & V_280 ) ;
if ( ! V_53 )
V_53 = F_46 ( V_17 , V_847 -> V_17 , V_869 ,
V_871 , & V_280 ) ;
if ( ! V_53 )
V_53 = F_46 ( V_847 -> V_17 , V_24 -> V_17 , V_855 ,
V_872 , & V_280 ) ;
return V_53 ;
}
static int F_388 ( struct V_852 * V_853 , struct V_845 * V_747 ,
struct V_20 * V_265 ,
long type , int V_168 )
{
struct V_844 * V_24 ;
struct V_846 * V_847 ;
struct V_279 V_280 ;
T_2 V_17 = F_18 ( V_265 ) ;
int V_53 ;
V_24 = V_853 -> V_854 . V_19 ;
V_847 = V_747 -> V_19 ;
V_280 . type = V_849 ;
V_280 . V_285 . V_850 = V_853 -> V_854 . V_851 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 ,
V_855 , V_873 , & V_280 ) ;
if ( ! V_53 )
V_53 = F_46 ( V_17 , V_847 -> V_17 ,
V_869 , V_874 , & V_280 ) ;
return V_53 ;
}
static int F_389 ( struct V_875 * V_876 )
{
struct V_844 * V_24 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_53 = F_376 ( V_11 , & V_876 -> V_877 , V_878 ) ;
if ( V_53 )
return V_53 ;
V_24 = V_876 -> V_877 . V_19 ;
V_280 . type = V_849 ;
V_280 . V_285 . V_850 = V_876 -> V_877 . V_851 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_878 ,
V_879 , & V_280 ) ;
if ( V_53 ) {
F_377 ( & V_876 -> V_877 ) ;
return V_53 ;
}
return 0 ;
}
static void F_390 ( struct V_875 * V_876 )
{
F_377 ( & V_876 -> V_877 ) ;
}
static int F_391 ( struct V_875 * V_876 , int V_880 )
{
struct V_844 * V_24 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
V_24 = V_876 -> V_877 . V_19 ;
V_280 . type = V_849 ;
V_280 . V_285 . V_850 = V_876 -> V_877 . V_851 ;
return F_46 ( V_17 , V_24 -> V_17 , V_878 ,
V_881 , & V_280 ) ;
}
static int F_392 ( struct V_875 * V_876 , int V_549 )
{
int V_266 ;
int V_601 ;
switch ( V_549 ) {
case V_859 :
case V_882 :
return F_115 ( V_11 , V_861 ) ;
case V_862 :
case V_883 :
V_266 = V_884 | V_881 ;
break;
case V_865 :
V_266 = V_885 ;
break;
case V_886 :
case V_887 :
V_266 = V_888 ;
break;
case V_867 :
V_266 = V_889 ;
break;
default:
return 0 ;
}
V_601 = F_380 ( & V_876 -> V_877 , V_266 ) ;
return V_601 ;
}
static int F_393 ( struct V_875 * V_876 ,
char T_15 * V_890 , int V_880 )
{
T_2 V_266 ;
if ( V_880 & V_891 )
V_266 = V_892 ;
else
V_266 = V_892 | V_893 ;
return F_380 ( & V_876 -> V_877 , V_266 ) ;
}
static int F_394 ( struct V_894 * V_895 )
{
struct V_844 * V_24 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_53 = F_376 ( V_11 , & V_895 -> V_896 , V_897 ) ;
if ( V_53 )
return V_53 ;
V_24 = V_895 -> V_896 . V_19 ;
V_280 . type = V_849 ;
V_280 . V_285 . V_850 = V_895 -> V_896 . V_851 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_897 ,
V_898 , & V_280 ) ;
if ( V_53 ) {
F_377 ( & V_895 -> V_896 ) ;
return V_53 ;
}
return 0 ;
}
static void F_395 ( struct V_894 * V_895 )
{
F_377 ( & V_895 -> V_896 ) ;
}
static int F_396 ( struct V_894 * V_895 , int V_899 )
{
struct V_844 * V_24 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
V_24 = V_895 -> V_896 . V_19 ;
V_280 . type = V_849 ;
V_280 . V_285 . V_850 = V_895 -> V_896 . V_851 ;
return F_46 ( V_17 , V_24 -> V_17 , V_897 ,
V_900 , & V_280 ) ;
}
static int F_397 ( struct V_894 * V_895 , int V_549 )
{
int V_601 ;
T_2 V_266 ;
switch ( V_549 ) {
case V_859 :
case V_901 :
return F_115 ( V_11 , V_861 ) ;
case V_902 :
case V_903 :
case V_904 :
V_266 = V_905 ;
break;
case V_906 :
case V_907 :
V_266 = V_908 ;
break;
case V_909 :
case V_910 :
V_266 = V_911 ;
break;
case V_867 :
V_266 = V_912 ;
break;
case V_865 :
V_266 = V_913 ;
break;
case V_862 :
case V_914 :
V_266 = V_905 | V_900 ;
break;
default:
return 0 ;
}
V_601 = F_380 ( & V_895 -> V_896 , V_266 ) ;
return V_601 ;
}
static int F_398 ( struct V_894 * V_895 ,
struct V_915 * V_916 , unsigned V_917 , int V_918 )
{
T_2 V_266 ;
if ( V_918 )
V_266 = V_908 | V_911 ;
else
V_266 = V_908 ;
return F_380 ( & V_895 -> V_896 , V_266 ) ;
}
static int F_399 ( struct V_843 * V_919 , short V_103 )
{
T_2 V_283 = 0 ;
V_283 = 0 ;
if ( V_103 & V_920 )
V_283 |= V_921 ;
if ( V_103 & V_922 )
V_283 |= V_923 ;
if ( V_283 == 0 )
return 0 ;
return F_380 ( V_919 , V_283 ) ;
}
static void F_400 ( struct V_843 * V_919 , T_2 * V_545 )
{
struct V_844 * V_24 = V_919 -> V_19 ;
* V_545 = V_24 -> V_17 ;
}
static void F_401 ( struct V_65 * V_65 , struct V_22 * V_22 )
{
if ( V_22 )
F_44 ( V_22 , V_65 ) ;
}
static int F_402 ( struct V_20 * V_145 ,
char * V_64 , char * * V_502 )
{
const struct V_13 * V_802 ;
T_2 V_17 ;
int error ;
unsigned V_88 ;
if ( V_11 != V_145 ) {
error = F_109 ( V_145 , V_924 ) ;
if ( error )
return error ;
}
F_19 () ;
V_802 = F_20 ( V_145 ) -> V_19 ;
if ( ! strcmp ( V_64 , L_49 ) )
V_17 = V_802 -> V_17 ;
else if ( ! strcmp ( V_64 , L_50 ) )
V_17 = V_802 -> V_16 ;
else if ( ! strcmp ( V_64 , L_51 ) )
V_17 = V_802 -> V_421 ;
else if ( ! strcmp ( V_64 , L_52 ) )
V_17 = V_802 -> V_301 ;
else if ( ! strcmp ( V_64 , L_53 ) )
V_17 = V_802 -> V_419 ;
else if ( ! strcmp ( V_64 , L_54 ) )
V_17 = V_802 -> V_420 ;
else
goto V_925;
F_21 () ;
if ( ! V_17 )
return 0 ;
error = F_62 ( V_17 , V_502 , & V_88 ) ;
if ( error )
return error ;
return V_88 ;
V_925:
F_21 () ;
return - V_90 ;
}
static int F_403 ( struct V_20 * V_145 ,
char * V_64 , void * V_502 , T_7 V_532 )
{
struct V_13 * V_14 ;
struct V_20 * V_429 ;
struct V_10 * V_128 ;
T_2 V_17 = 0 , V_431 ;
int error ;
char * V_1 = V_502 ;
if ( V_11 != V_145 ) {
return - V_417 ;
}
if ( ! strcmp ( V_64 , L_51 ) )
error = F_109 ( V_145 , V_926 ) ;
else if ( ! strcmp ( V_64 , L_52 ) )
error = F_109 ( V_145 , V_927 ) ;
else if ( ! strcmp ( V_64 , L_53 ) )
error = F_109 ( V_145 , V_928 ) ;
else if ( ! strcmp ( V_64 , L_54 ) )
error = F_109 ( V_145 , V_929 ) ;
else if ( ! strcmp ( V_64 , L_49 ) )
error = F_109 ( V_145 , V_930 ) ;
else
error = - V_90 ;
if ( error )
return error ;
if ( V_532 && V_1 [ 1 ] && V_1 [ 1 ] != '\n' ) {
if ( V_1 [ V_532 - 1 ] == '\n' ) {
V_1 [ V_532 - 1 ] = 0 ;
V_532 -- ;
}
error = F_69 ( V_502 , V_532 , & V_17 , V_15 ) ;
if ( error == - V_90 && ! strcmp ( V_64 , L_52 ) ) {
if ( ! F_220 ( V_534 ) ) {
struct V_535 * V_536 ;
T_7 V_537 ;
if ( V_1 [ V_532 - 1 ] == '\0' )
V_537 = V_532 - 1 ;
else
V_537 = V_532 ;
V_536 = F_223 ( V_11 -> V_538 , V_96 , V_539 ) ;
F_224 ( V_536 , L_55 ) ;
F_225 ( V_536 , V_502 , V_537 ) ;
F_226 ( V_536 ) ;
return error ;
}
error = F_227 ( V_502 , V_532 ,
& V_17 ) ;
}
if ( error )
return error ;
}
V_128 = F_404 () ;
if ( ! V_128 )
return - V_27 ;
V_14 = V_128 -> V_19 ;
if ( ! strcmp ( V_64 , L_51 ) ) {
V_14 -> V_421 = V_17 ;
} else if ( ! strcmp ( V_64 , L_52 ) ) {
V_14 -> V_301 = V_17 ;
} else if ( ! strcmp ( V_64 , L_53 ) ) {
error = F_126 ( V_17 , V_145 ) ;
if ( error )
goto V_931;
V_14 -> V_419 = V_17 ;
} else if ( ! strcmp ( V_64 , L_54 ) ) {
V_14 -> V_420 = V_17 ;
} else if ( ! strcmp ( V_64 , L_49 ) ) {
error = - V_90 ;
if ( V_17 == 0 )
goto V_931;
error = - V_416 ;
if ( ! F_405 () ) {
error = F_150 ( V_14 -> V_17 , V_17 ) ;
if ( error )
goto V_931;
}
error = F_46 ( V_14 -> V_17 , V_17 , V_269 ,
V_932 , NULL ) ;
if ( error )
goto V_931;
V_431 = 0 ;
F_19 () ;
V_429 = F_152 ( V_145 ) ;
if ( V_429 )
V_431 = F_18 ( V_429 ) ;
F_21 () ;
if ( V_429 ) {
error = F_46 ( V_431 , V_17 , V_269 ,
V_365 , NULL ) ;
if ( error )
goto V_931;
}
V_14 -> V_17 = V_17 ;
} else {
error = - V_90 ;
goto V_931;
}
F_406 ( V_128 ) ;
return V_532 ;
V_931:
F_407 ( V_128 ) ;
return error ;
}
static int F_408 ( const char * V_64 )
{
return ( strcmp ( V_64 , V_504 ) == 0 ) ;
}
static int F_409 ( T_2 V_545 , char * * V_485 , T_2 * V_933 )
{
return F_62 ( V_545 , V_485 , V_933 ) ;
}
static int F_410 ( const char * V_485 , T_2 V_933 , T_2 * V_545 )
{
return F_69 ( V_485 , V_933 , V_545 , V_15 ) ;
}
static void F_411 ( char * V_485 , T_2 V_933 )
{
F_39 ( V_485 ) ;
}
static int F_412 ( struct V_22 * V_22 , void * V_308 , T_2 V_500 )
{
return F_235 ( V_22 , V_504 , V_308 , V_500 , 0 ) ;
}
static int F_413 ( struct V_65 * V_65 , void * V_308 , T_2 V_500 )
{
return F_414 ( V_65 , V_75 , V_308 , V_500 , 0 ) ;
}
static int F_415 ( struct V_22 * V_22 , void * * V_308 , T_2 * V_500 )
{
int V_88 = 0 ;
V_88 = F_233 ( V_22 , V_504 ,
V_308 , true ) ;
if ( V_88 < 0 )
return V_88 ;
* V_500 = V_88 ;
return 0 ;
}
static int F_416 ( struct V_851 * V_934 , const struct V_10 * V_10 ,
unsigned long V_79 )
{
const struct V_13 * V_14 ;
struct V_935 * V_936 ;
V_936 = F_15 ( sizeof( struct V_935 ) , V_15 ) ;
if ( ! V_936 )
return - V_27 ;
V_14 = V_10 -> V_19 ;
if ( V_14 -> V_419 )
V_936 -> V_17 = V_14 -> V_419 ;
else
V_936 -> V_17 = V_14 -> V_17 ;
V_934 -> V_19 = V_936 ;
return 0 ;
}
static void F_417 ( struct V_851 * V_934 )
{
struct V_935 * V_936 = V_934 -> V_19 ;
V_934 -> V_19 = NULL ;
F_39 ( V_936 ) ;
}
static int F_418 ( T_16 V_937 ,
const struct V_10 * V_10 ,
unsigned V_256 )
{
struct V_851 * V_851 ;
struct V_935 * V_936 ;
T_2 V_17 ;
if ( V_256 == 0 )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_851 = F_419 ( V_937 ) ;
V_936 = V_851 -> V_19 ;
return F_46 ( V_17 , V_936 -> V_17 , V_309 , V_256 , NULL ) ;
}
static int F_420 ( struct V_851 * V_851 , char * * V_938 )
{
struct V_935 * V_936 = V_851 -> V_19 ;
char * V_87 = NULL ;
unsigned V_88 ;
int V_53 ;
V_53 = F_62 ( V_936 -> V_17 , & V_87 , & V_88 ) ;
if ( ! V_53 )
V_53 = V_88 ;
* V_938 = V_87 ;
return V_53 ;
}
static T_1 int F_421 ( void )
{
if ( ! F_422 ( L_56 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_51 ( V_939 L_57 ) ;
return 0 ;
}
F_51 ( V_939 L_58 ) ;
F_14 () ;
V_572 = ! ( V_940 & V_587 ) ;
V_25 = F_423 ( L_59 ,
sizeof( struct V_23 ) ,
0 , V_941 , NULL ) ;
F_424 () ;
F_425 ( V_942 , F_52 ( V_942 ) ) ;
if ( F_426 ( F_9 , V_9 ) )
F_16 ( L_60 ) ;
if ( V_3 )
F_51 ( V_943 L_61 ) ;
else
F_51 ( V_943 L_62 ) ;
return 0 ;
}
static void F_427 ( struct V_47 * V_48 , void * V_944 )
{
F_78 ( V_48 , NULL ) ;
}
void F_428 ( void )
{
F_51 ( V_943 L_63 ) ;
F_51 ( V_943 L_64 ) ;
F_429 ( F_427 , NULL ) ;
}
static int T_1 F_430 ( void )
{
int V_601 ;
if ( ! V_5 )
return 0 ;
F_51 ( V_943 L_65 ) ;
V_601 = F_431 ( V_945 , F_52 ( V_945 ) ) ;
if ( V_601 )
F_16 ( L_66 , V_601 ) ;
return 0 ;
}
static void F_432 ( void )
{
F_51 ( V_943 L_67 ) ;
F_433 ( V_945 , F_52 ( V_945 ) ) ;
}
int F_434 ( void )
{
if ( V_91 ) {
return - V_90 ;
}
if ( V_946 ) {
return - V_90 ;
}
F_51 ( V_939 L_68 ) ;
V_946 = 1 ;
V_5 = 0 ;
F_435 ( V_942 , F_52 ( V_942 ) ) ;
F_436 () ;
F_432 () ;
F_437 () ;
return 0 ;
}
