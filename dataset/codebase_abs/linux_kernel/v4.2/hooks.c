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
F_32 ( & V_38 -> V_41 ) ;
V_82:
if ( ! F_33 ( & V_38 -> V_49 ) ) {
struct V_23 * V_24 =
F_53 ( V_38 -> V_49 . V_83 ,
struct V_23 , V_29 ) ;
struct V_22 * V_22 = V_24 -> V_22 ;
F_34 ( & V_24 -> V_29 ) ;
F_35 ( & V_38 -> V_41 ) ;
V_22 = F_54 ( V_22 ) ;
if ( V_22 ) {
if ( ! F_55 ( V_22 ) )
F_43 ( V_22 ) ;
F_56 ( V_22 ) ;
}
F_32 ( & V_38 -> V_41 ) ;
goto V_82;
}
F_35 ( & V_38 -> V_41 ) ;
V_74:
return V_53 ;
}
static int F_57 ( const struct V_47 * V_48 ,
struct V_84 * V_85 )
{
int V_53 = 0 , V_86 ;
struct V_37 * V_38 = V_48 -> V_40 ;
char * V_87 = NULL ;
T_2 V_88 ;
char V_89 ;
F_58 ( V_85 ) ;
if ( ! ( V_38 -> V_79 & V_80 ) )
return - V_90 ;
if ( ! V_91 )
return - V_90 ;
F_59 ( V_92 >= ( 1 << V_93 ) ) ;
V_89 = V_38 -> V_79 & V_92 ;
for ( V_86 = 0 ; V_86 < V_93 ; V_86 ++ ) {
if ( V_89 & 0x01 )
V_85 -> V_94 ++ ;
V_89 >>= 1 ;
}
if ( V_38 -> V_79 & V_81 )
V_85 -> V_94 ++ ;
V_85 -> V_95 = F_60 ( V_85 -> V_94 , sizeof( char * ) , V_96 ) ;
if ( ! V_85 -> V_95 ) {
V_53 = - V_27 ;
goto V_97;
}
V_85 -> V_98 = F_60 ( V_85 -> V_94 , sizeof( int ) , V_96 ) ;
if ( ! V_85 -> V_98 ) {
V_53 = - V_27 ;
goto V_97;
}
V_86 = 0 ;
if ( V_38 -> V_79 & V_99 ) {
V_53 = F_61 ( V_38 -> V_17 , & V_87 , & V_88 ) ;
if ( V_53 )
goto V_97;
V_85 -> V_95 [ V_86 ] = V_87 ;
V_85 -> V_98 [ V_86 ++ ] = V_99 ;
}
if ( V_38 -> V_79 & V_100 ) {
V_53 = F_61 ( V_38 -> V_52 , & V_87 , & V_88 ) ;
if ( V_53 )
goto V_97;
V_85 -> V_95 [ V_86 ] = V_87 ;
V_85 -> V_98 [ V_86 ++ ] = V_100 ;
}
if ( V_38 -> V_79 & V_101 ) {
V_53 = F_61 ( V_38 -> V_50 , & V_87 , & V_88 ) ;
if ( V_53 )
goto V_97;
V_85 -> V_95 [ V_86 ] = V_87 ;
V_85 -> V_98 [ V_86 ++ ] = V_101 ;
}
if ( V_38 -> V_79 & V_102 ) {
struct V_22 * V_66 = F_50 ( V_38 -> V_48 -> V_67 ) ;
struct V_23 * V_24 = V_66 -> V_33 ;
V_53 = F_61 ( V_24 -> V_17 , & V_87 , & V_88 ) ;
if ( V_53 )
goto V_97;
V_85 -> V_95 [ V_86 ] = V_87 ;
V_85 -> V_98 [ V_86 ++ ] = V_102 ;
}
if ( V_38 -> V_79 & V_81 ) {
V_85 -> V_95 [ V_86 ] = NULL ;
V_85 -> V_98 [ V_86 ++ ] = V_81 ;
}
F_62 ( V_86 != V_85 -> V_94 ) ;
return 0 ;
V_97:
F_63 ( V_85 ) ;
return V_53 ;
}
static int F_64 ( struct V_37 * V_38 , char V_103 ,
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
static int F_65 ( struct V_47 * V_48 ,
struct V_84 * V_85 ,
unsigned long V_107 ,
unsigned long * V_108 )
{
const struct V_10 * V_10 = F_66 () ;
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
F_67 ( & V_38 -> V_28 ) ;
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
V_53 = F_68 ( V_114 [ V_86 ] ,
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
if ( F_64 ( V_38 , V_99 , V_38 -> V_17 ,
V_110 ) )
goto V_118;
V_38 -> V_79 |= V_99 ;
break;
case V_100 :
V_111 = V_17 ;
if ( F_64 ( V_38 , V_100 , V_38 -> V_52 ,
V_111 ) )
goto V_118;
V_38 -> V_79 |= V_100 ;
break;
case V_102 :
V_112 = V_17 ;
if ( F_64 ( V_38 , V_102 , V_109 -> V_17 ,
V_112 ) )
goto V_118;
V_38 -> V_79 |= V_102 ;
break;
case V_101 :
V_113 = V_17 ;
if ( F_64 ( V_38 , V_101 , V_38 -> V_50 ,
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
V_53 = F_69 ( V_48 ) ;
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
F_70 ( & V_38 -> V_28 ) ;
return V_53 ;
V_118:
V_53 = - V_90 ;
F_51 ( V_71 L_20
L_21 , V_48 -> V_72 , V_64 ) ;
goto V_74;
}
static int F_71 ( const struct V_47 * V_125 ,
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
static int F_72 ( const struct V_47 * V_125 ,
struct V_47 * V_126 )
{
const struct V_37 * V_135 = V_125 -> V_40 ;
struct V_37 * V_136 = V_126 -> V_40 ;
int V_137 = ( V_135 -> V_79 & V_99 ) ;
int V_138 = ( V_135 -> V_79 & V_100 ) ;
int V_139 = ( V_135 -> V_79 & V_102 ) ;
if ( ! V_91 )
return 0 ;
F_62 ( ! ( V_135 -> V_79 & V_80 ) ) ;
if ( V_136 -> V_79 & V_80 )
return F_71 ( V_125 , V_126 ) ;
F_67 ( & V_136 -> V_28 ) ;
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
F_70 ( & V_136 -> V_28 ) ;
return 0 ;
}
static int F_73 ( char * V_144 ,
struct V_84 * V_85 )
{
char * V_145 ;
char * V_87 = NULL , * V_146 = NULL ;
char * V_147 = NULL , * V_148 = NULL ;
int V_53 , V_94 = 0 ;
V_85 -> V_94 = 0 ;
while ( ( V_145 = F_74 ( & V_144 , L_25 ) ) != NULL ) {
int V_149 ;
T_3 args [ V_150 ] ;
if ( ! * V_145 )
continue;
V_149 = F_75 ( V_145 , V_151 , args ) ;
switch ( V_149 ) {
case V_152 :
if ( V_87 || V_146 ) {
V_53 = - V_90 ;
F_51 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_153;
}
V_87 = F_76 ( & args [ 0 ] ) ;
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
V_147 = F_76 ( & args [ 0 ] ) ;
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
V_148 = F_76 ( & args [ 0 ] ) ;
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
V_146 = F_76 ( & args [ 0 ] ) ;
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
V_85 -> V_95 = F_60 ( V_93 , sizeof( char * ) , V_96 ) ;
if ( ! V_85 -> V_95 )
goto V_153;
V_85 -> V_98 = F_60 ( V_93 , sizeof( int ) , V_96 ) ;
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
static int F_77 ( struct V_47 * V_48 , void * V_158 )
{
int V_53 = 0 ;
char * V_144 = V_158 ;
struct V_84 V_85 ;
F_58 ( & V_85 ) ;
if ( ! V_158 )
goto V_74;
F_62 ( V_48 -> V_63 -> V_116 & V_117 ) ;
V_53 = F_73 ( V_144 , & V_85 ) ;
if ( V_53 )
goto V_153;
V_74:
V_53 = F_65 ( V_48 , & V_85 , 0 , NULL ) ;
V_153:
F_63 ( & V_85 ) ;
return V_53 ;
}
static void F_78 ( struct V_159 * V_160 ,
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
F_79 ( V_160 , ',' ) ;
F_80 ( V_160 , V_167 ) ;
continue;
default:
F_81 () ;
return;
} ;
F_79 ( V_160 , ',' ) ;
F_80 ( V_160 , V_161 ) ;
if ( V_162 )
F_79 ( V_160 , '\"' ) ;
F_80 ( V_160 , V_85 -> V_95 [ V_86 ] ) ;
if ( V_162 )
F_79 ( V_160 , '\"' ) ;
}
}
static int F_82 ( struct V_159 * V_160 , struct V_47 * V_48 )
{
struct V_84 V_85 ;
int V_53 ;
V_53 = F_57 ( V_48 , & V_85 ) ;
if ( V_53 ) {
if ( V_53 == - V_90 )
V_53 = 0 ;
return V_53 ;
}
F_78 ( V_160 , & V_85 ) ;
F_63 ( & V_85 ) ;
return V_53 ;
}
static inline T_4 F_83 ( T_5 V_168 )
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
static inline int F_84 ( int V_183 )
{
return ( V_183 == V_184 || V_183 == V_185 ) ;
}
static inline int F_85 ( int V_183 )
{
return ( V_183 == V_184 || V_183 == V_186 ) ;
}
static inline T_4 F_86 ( int V_187 , int type , int V_183 )
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
if ( F_84 ( V_183 ) )
return V_196 ;
else
return V_197 ;
case V_192 :
if ( F_85 ( V_183 ) )
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
static int F_87 ( struct V_65 * V_65 ,
T_4 V_242 ,
T_4 V_79 ,
T_2 * V_17 )
{
int V_53 ;
struct V_47 * V_48 = V_65 -> V_243 -> V_39 ;
char * V_244 , * V_245 ;
V_244 = ( char * ) F_88 ( V_15 ) ;
if ( ! V_244 )
return - V_27 ;
V_245 = F_89 ( V_65 , V_244 , V_246 ) ;
if ( F_90 ( V_245 ) )
V_53 = F_91 ( V_245 ) ;
else {
if ( V_79 & V_119 ) {
while ( V_245 [ 1 ] >= '0' && V_245 [ 1 ] <= '9' ) {
V_245 [ 1 ] = '/' ;
V_245 ++ ;
}
}
V_53 = F_92 ( V_48 -> V_63 -> V_64 , V_245 , V_242 , V_17 ) ;
}
F_93 ( ( unsigned long ) V_244 ) ;
return V_53 ;
}
static int F_44 ( struct V_22 * V_22 , struct V_65 * V_247 )
{
struct V_37 * V_38 = NULL ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 ;
struct V_65 * V_65 ;
#define F_94 255
char * V_87 = NULL ;
unsigned V_88 = 0 ;
int V_53 = 0 ;
if ( V_24 -> V_124 )
goto V_74;
F_67 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_124 )
goto V_248;
V_38 = V_22 -> V_39 -> V_40 ;
if ( ! ( V_38 -> V_79 & V_80 ) ) {
F_32 ( & V_38 -> V_41 ) ;
if ( F_33 ( & V_24 -> V_29 ) )
F_95 ( & V_24 -> V_29 , & V_38 -> V_49 ) ;
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
V_65 = F_96 ( V_247 ) ;
} else {
V_65 = F_97 ( V_22 ) ;
}
if ( ! V_65 ) {
goto V_248;
}
V_88 = F_94 ;
V_87 = F_98 ( V_88 + 1 , V_26 ) ;
if ( ! V_87 ) {
V_53 = - V_27 ;
F_99 ( V_65 ) ;
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
F_99 ( V_65 ) ;
goto V_248;
}
V_88 = V_53 ;
V_87 = F_98 ( V_88 + 1 , V_26 ) ;
if ( ! V_87 ) {
V_53 = - V_27 ;
F_99 ( V_65 ) ;
goto V_248;
}
V_87 [ V_88 ] = '\0' ;
V_53 = V_22 -> V_69 -> V_70 ( V_65 ,
V_75 ,
V_87 , V_88 ) ;
}
F_99 ( V_65 ) ;
if ( V_53 < 0 ) {
if ( V_53 != - V_76 ) {
F_51 ( V_71 L_27
L_28 , V_121 ,
- V_53 , V_22 -> V_39 -> V_72 , V_22 -> V_250 ) ;
F_39 ( V_87 ) ;
goto V_248;
}
V_17 = V_38 -> V_50 ;
V_53 = 0 ;
} else {
V_53 = F_100 ( V_87 , V_53 , & V_17 ,
V_38 -> V_50 ,
V_26 ) ;
if ( V_53 ) {
char * V_251 = V_22 -> V_39 -> V_72 ;
unsigned long V_252 = V_22 -> V_250 ;
if ( V_53 == - V_90 ) {
if ( F_101 () )
F_51 ( V_253 L_29
L_30
L_31 , V_252 , V_251 , V_87 ) ;
} else {
F_51 ( V_71 L_32
L_33 ,
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
V_24 -> V_31 = F_83 ( V_22 -> V_254 ) ;
V_53 = F_102 ( V_24 -> F_18 , V_38 -> V_17 ,
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
if ( ( V_38 -> V_79 & V_120 ) && ! F_103 ( V_22 -> V_254 ) ) {
if ( V_247 )
V_65 = F_96 ( V_247 ) ;
else
V_65 = F_97 ( V_22 ) ;
if ( ! V_65 )
goto V_248;
V_24 -> V_31 = F_83 ( V_22 -> V_254 ) ;
V_53 = F_87 ( V_65 , V_24 -> V_31 ,
V_38 -> V_79 , & V_17 ) ;
F_99 ( V_65 ) ;
if ( V_53 )
goto V_248;
V_24 -> V_17 = V_17 ;
}
break;
}
V_24 -> V_124 = 1 ;
V_248:
F_70 ( & V_24 -> V_28 ) ;
V_74:
if ( V_24 -> V_31 == V_32 )
V_24 -> V_31 = F_83 ( V_22 -> V_254 ) ;
return V_53 ;
}
static inline T_2 F_104 ( int V_255 )
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
static int F_105 ( const struct V_10 * V_264 ,
const struct V_10 * V_265 ,
T_2 V_266 )
{
T_2 V_267 = F_17 ( V_264 ) , V_268 = F_17 ( V_265 ) ;
return F_46 ( V_267 , V_268 , V_269 , V_266 , NULL ) ;
}
static int F_106 ( const struct V_20 * V_270 ,
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
static int F_107 ( const struct V_20 * V_276 ,
T_2 V_266 )
{
T_2 V_17 , V_268 ;
V_17 = F_22 () ;
V_268 = F_18 ( V_276 ) ;
return F_46 ( V_17 , V_268 , V_269 , V_266 , NULL ) ;
}
static int F_108 ( const struct V_10 * V_10 ,
int V_277 , int V_278 )
{
struct V_279 V_280 ;
struct V_281 V_282 ;
T_4 V_31 ;
T_2 V_17 = F_17 ( V_10 ) ;
T_2 V_283 = F_109 ( V_277 ) ;
int V_53 ;
V_280 . type = V_284 ;
V_280 . V_285 . V_277 = V_277 ;
switch ( F_110 ( V_277 ) ) {
case 0 :
V_31 = V_286 ;
break;
case 1 :
V_31 = V_287 ;
break;
default:
F_51 ( V_78
L_34 , V_277 ) ;
F_81 () ;
return - V_90 ;
}
V_53 = F_111 ( V_17 , V_17 , V_31 , V_283 , 0 , & V_282 ) ;
if ( V_278 == V_288 ) {
int V_289 = F_112 ( V_17 , V_17 , V_31 , V_283 , & V_282 , V_53 , & V_280 , 0 ) ;
if ( V_289 )
return V_289 ;
}
return V_53 ;
}
static int F_113 ( struct V_20 * V_276 ,
T_2 V_266 )
{
T_2 V_17 = F_18 ( V_276 ) ;
return F_46 ( V_17 , V_18 ,
V_290 , V_266 , NULL ) ;
}
static int F_114 ( const struct V_10 * V_10 ,
struct V_22 * V_22 ,
T_2 V_266 ,
struct V_279 * V_291 )
{
struct V_23 * V_24 ;
T_2 V_17 ;
F_115 ( V_10 ) ;
if ( F_116 ( F_55 ( V_22 ) ) )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
return F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_266 , V_291 ) ;
}
static inline int F_117 ( const struct V_10 * V_10 ,
struct V_65 * V_65 ,
T_2 V_283 )
{
struct V_22 * V_22 = F_50 ( V_65 ) ;
struct V_279 V_280 ;
V_280 . type = V_292 ;
V_280 . V_285 . V_65 = V_65 ;
return F_114 ( V_10 , V_22 , V_283 , & V_280 ) ;
}
static inline int F_118 ( const struct V_10 * V_10 ,
const struct V_245 * V_245 ,
T_2 V_283 )
{
struct V_22 * V_22 = F_50 ( V_245 -> V_65 ) ;
struct V_279 V_280 ;
V_280 . type = V_293 ;
V_280 . V_285 . V_245 = * V_245 ;
return F_114 ( V_10 , V_22 , V_283 , & V_280 ) ;
}
static inline int F_119 ( const struct V_10 * V_10 ,
struct V_42 * V_42 ,
T_2 V_283 )
{
struct V_279 V_280 ;
V_280 . type = V_293 ;
V_280 . V_285 . V_245 = V_42 -> V_294 ;
return F_114 ( V_10 , F_120 ( V_42 ) , V_283 , & V_280 ) ;
}
static int F_121 ( const struct V_10 * V_10 ,
struct V_42 * V_42 ,
T_2 V_283 )
{
struct V_43 * V_44 = V_42 -> V_46 ;
struct V_22 * V_22 = F_120 ( V_42 ) ;
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
V_53 = F_114 ( V_10 , V_22 , V_283 , & V_280 ) ;
V_74:
return V_53 ;
}
static int F_122 ( struct V_22 * V_297 ,
struct V_65 * V_65 ,
T_4 V_242 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_298 ;
struct V_37 * V_38 ;
T_2 V_17 , V_299 ;
struct V_279 V_280 ;
int V_53 ;
V_298 = V_297 -> V_33 ;
V_38 = V_297 -> V_39 -> V_40 ;
V_17 = V_14 -> V_17 ;
V_299 = V_14 -> V_300 ;
V_280 . type = V_292 ;
V_280 . V_285 . V_65 = V_65 ;
V_53 = F_46 ( V_17 , V_298 -> V_17 , V_178 ,
V_301 | V_302 ,
& V_280 ) ;
if ( V_53 )
return V_53 ;
if ( ! V_299 || ! ( V_38 -> V_79 & V_81 ) ) {
V_53 = F_102 ( V_17 , V_298 -> V_17 , V_242 ,
& V_65 -> V_303 , & V_299 ) ;
if ( V_53 )
return V_53 ;
}
V_53 = F_46 ( V_17 , V_299 , V_242 , V_304 , & V_280 ) ;
if ( V_53 )
return V_53 ;
return F_46 ( V_299 , V_38 -> V_17 ,
V_54 ,
V_57 , & V_280 ) ;
}
static int F_123 ( T_2 V_305 ,
struct V_20 * V_306 )
{
T_2 V_17 = F_18 ( V_306 ) ;
return F_46 ( V_17 , V_305 , V_307 , V_308 , NULL ) ;
}
static int F_124 ( struct V_22 * V_297 ,
struct V_65 * V_65 ,
int V_309 )
{
struct V_23 * V_298 , * V_24 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
T_2 V_283 ;
int V_53 ;
V_298 = V_297 -> V_33 ;
V_24 = F_50 ( V_65 ) -> V_33 ;
V_280 . type = V_292 ;
V_280 . V_285 . V_65 = V_65 ;
V_283 = V_302 ;
V_283 |= ( V_309 ? V_310 : V_301 ) ;
V_53 = F_46 ( V_17 , V_298 -> V_17 , V_178 , V_283 , & V_280 ) ;
if ( V_53 )
return V_53 ;
switch ( V_309 ) {
case V_311 :
V_283 = V_312 ;
break;
case V_313 :
V_283 = V_314 ;
break;
case V_315 :
V_283 = V_316 ;
break;
default:
F_51 ( V_71 L_35 ,
V_121 , V_309 ) ;
return 0 ;
}
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_283 , & V_280 ) ;
return V_53 ;
}
static inline int F_125 ( struct V_22 * V_317 ,
struct V_65 * V_318 ,
struct V_22 * V_319 ,
struct V_65 * V_320 )
{
struct V_23 * V_321 , * V_322 , * V_323 , * V_324 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
T_2 V_283 ;
int V_325 , V_326 ;
int V_53 ;
V_321 = V_317 -> V_33 ;
V_323 = F_50 ( V_318 ) -> V_33 ;
V_325 = F_126 ( V_318 ) ;
V_322 = V_319 -> V_33 ;
V_280 . type = V_292 ;
V_280 . V_285 . V_65 = V_318 ;
V_53 = F_46 ( V_17 , V_321 -> V_17 , V_178 ,
V_310 | V_302 , & V_280 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_17 , V_323 -> V_17 ,
V_323 -> V_31 , V_327 , & V_280 ) ;
if ( V_53 )
return V_53 ;
if ( V_325 && V_319 != V_317 ) {
V_53 = F_46 ( V_17 , V_323 -> V_17 ,
V_323 -> V_31 , V_328 , & V_280 ) ;
if ( V_53 )
return V_53 ;
}
V_280 . V_285 . V_65 = V_320 ;
V_283 = V_301 | V_302 ;
if ( F_127 ( V_320 ) )
V_283 |= V_310 ;
V_53 = F_46 ( V_17 , V_322 -> V_17 , V_178 , V_283 , & V_280 ) ;
if ( V_53 )
return V_53 ;
if ( F_127 ( V_320 ) ) {
V_324 = F_50 ( V_320 ) -> V_33 ;
V_326 = F_126 ( V_320 ) ;
V_53 = F_46 ( V_17 , V_324 -> V_17 ,
V_324 -> V_31 ,
( V_326 ? V_316 : V_314 ) , & V_280 ) ;
if ( V_53 )
return V_53 ;
}
return 0 ;
}
static int F_128 ( const struct V_10 * V_10 ,
struct V_47 * V_48 ,
T_2 V_266 ,
struct V_279 * V_280 )
{
struct V_37 * V_38 ;
T_2 V_17 = F_17 ( V_10 ) ;
V_38 = V_48 -> V_40 ;
return F_46 ( V_17 , V_38 -> V_17 , V_54 , V_266 , V_280 ) ;
}
static inline T_2 F_129 ( int V_168 , int V_329 )
{
T_2 V_283 = 0 ;
if ( ! F_130 ( V_168 ) ) {
if ( V_329 & V_330 )
V_283 |= V_331 ;
if ( V_329 & V_332 )
V_283 |= V_333 ;
if ( V_329 & V_334 )
V_283 |= V_335 ;
else if ( V_329 & V_336 )
V_283 |= V_337 ;
} else {
if ( V_329 & V_330 )
V_283 |= V_302 ;
if ( V_329 & V_336 )
V_283 |= V_338 ;
if ( V_329 & V_332 )
V_283 |= V_339 ;
}
return V_283 ;
}
static inline T_2 F_131 ( struct V_42 * V_42 )
{
T_2 V_283 = 0 ;
if ( V_42 -> V_340 & V_341 )
V_283 |= V_333 ;
if ( V_42 -> V_340 & V_342 ) {
if ( V_42 -> V_343 & V_344 )
V_283 |= V_335 ;
else
V_283 |= V_337 ;
}
if ( ! V_283 ) {
V_283 = V_345 ;
}
return V_283 ;
}
static inline T_2 F_132 ( struct V_42 * V_42 )
{
T_2 V_283 = F_131 ( V_42 ) ;
if ( V_346 )
V_283 |= V_347 ;
return V_283 ;
}
static int F_133 ( struct V_20 * V_348 )
{
T_2 V_349 = F_22 () ;
T_2 V_350 = F_18 ( V_348 ) ;
return F_46 ( V_349 , V_350 , V_351 ,
V_352 , NULL ) ;
}
static int F_134 ( struct V_20 * V_353 ,
struct V_20 * V_354 )
{
T_2 V_349 = F_22 () ;
T_2 V_355 = F_18 ( V_353 ) ;
T_2 V_356 = F_18 ( V_354 ) ;
int V_53 ;
if ( V_349 != V_355 ) {
V_53 = F_46 ( V_349 , V_355 , V_351 ,
V_357 , NULL ) ;
if ( V_53 )
return V_53 ;
}
return F_46 ( V_355 , V_356 , V_351 , V_358 ,
NULL ) ;
}
static int F_135 ( struct V_20 * V_353 ,
struct V_20 * V_354 )
{
T_2 V_355 = F_18 ( V_353 ) ;
T_2 V_356 = F_18 ( V_354 ) ;
return F_46 ( V_355 , V_356 , V_351 , V_359 ,
NULL ) ;
}
static int F_136 ( struct V_20 * V_353 ,
struct V_20 * V_354 ,
struct V_42 * V_42 )
{
T_2 V_17 = F_18 ( V_354 ) ;
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
if ( F_116 ( F_55 ( V_22 ) ) )
return 0 ;
return F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , F_131 ( V_42 ) ,
& V_280 ) ;
}
static int F_137 ( struct V_20 * V_360 ,
unsigned int V_168 )
{
if ( V_168 & V_361 ) {
T_2 V_17 = F_22 () ;
T_2 V_362 = F_18 ( V_360 ) ;
return F_46 ( V_17 , V_362 , V_32 , V_333 , NULL ) ;
}
return F_107 ( V_360 , V_363 ) ;
}
static int F_138 ( struct V_20 * V_364 )
{
return F_106 ( V_364 , V_11 , V_363 ) ;
}
static int F_139 ( struct V_20 * V_265 , T_6 * V_365 ,
T_6 * V_366 , T_6 * V_367 )
{
return F_107 ( V_265 , V_368 ) ;
}
static int F_140 ( struct V_10 * V_128 , const struct V_10 * V_127 ,
const T_6 * V_365 ,
const T_6 * V_366 ,
const T_6 * V_367 )
{
return F_105 ( V_127 , V_128 , V_369 ) ;
}
static int F_141 ( const struct V_10 * V_10 , struct V_370 * V_371 ,
int V_277 , int V_278 )
{
return F_108 ( V_10 , V_277 , V_278 ) ;
}
static int F_142 ( int V_372 , int type , int V_373 , struct V_47 * V_48 )
{
const struct V_10 * V_10 = F_66 () ;
int V_53 = 0 ;
if ( ! V_48 )
return 0 ;
switch ( V_372 ) {
case V_374 :
case V_375 :
case V_376 :
case V_377 :
case V_378 :
V_53 = F_128 ( V_10 , V_48 , V_379 , NULL ) ;
break;
case V_380 :
case V_381 :
case V_382 :
V_53 = F_128 ( V_10 , V_48 , V_383 , NULL ) ;
break;
default:
V_53 = 0 ;
break;
}
return V_53 ;
}
static int F_143 ( struct V_65 * V_65 )
{
const struct V_10 * V_10 = F_66 () ;
return F_117 ( V_10 , V_65 , V_384 ) ;
}
static int F_144 ( int type )
{
int V_53 ;
switch ( type ) {
case V_385 :
case V_386 :
V_53 = F_113 ( V_11 , V_387 ) ;
break;
case V_388 :
case V_389 :
case V_390 :
V_53 = F_113 ( V_11 , V_391 ) ;
break;
case V_392 :
case V_393 :
case V_394 :
case V_395 :
case V_396 :
default:
V_53 = F_113 ( V_11 , V_397 ) ;
break;
}
return V_53 ;
}
static int F_145 ( struct V_398 * V_399 , long V_400 )
{
int V_53 , V_401 = 0 ;
V_53 = F_108 ( F_66 () , V_402 ,
V_403 ) ;
if ( V_53 == 0 )
V_401 = 1 ;
return V_401 ;
}
static int F_146 ( const struct V_404 * V_405 ,
const struct V_13 * V_406 ,
const struct V_13 * V_407 )
{
int V_408 = ( V_405 -> V_409 & V_410 ) ;
int V_411 = ( V_405 -> V_42 -> V_294 . V_412 -> V_106 & V_413 ) ;
int V_53 ;
if ( ! V_408 && ! V_411 )
return 0 ;
if ( V_407 -> V_17 == V_406 -> V_17 )
return 0 ;
V_53 = F_147 ( V_406 -> V_17 , V_407 -> V_17 ) ;
if ( V_53 ) {
if ( V_408 )
return - V_414 ;
else
return - V_415 ;
}
return 0 ;
}
static int F_148 ( struct V_404 * V_405 )
{
const struct V_13 * V_406 ;
struct V_13 * V_407 ;
struct V_23 * V_24 ;
struct V_279 V_280 ;
struct V_22 * V_22 = F_120 ( V_405 -> V_42 ) ;
int V_53 ;
if ( V_405 -> V_416 )
return 0 ;
V_406 = F_23 () ;
V_407 = V_405 -> V_10 -> V_19 ;
V_24 = V_22 -> V_33 ;
V_407 -> V_17 = V_406 -> V_17 ;
V_407 -> V_16 = V_406 -> V_17 ;
V_407 -> V_300 = 0 ;
V_407 -> V_417 = 0 ;
V_407 -> V_418 = 0 ;
if ( V_406 -> V_419 ) {
V_407 -> V_17 = V_406 -> V_419 ;
V_407 -> V_419 = 0 ;
V_53 = F_146 ( V_405 , V_406 , V_407 ) ;
if ( V_53 )
return V_53 ;
} else {
V_53 = F_102 ( V_406 -> V_17 , V_24 -> V_17 ,
V_269 , NULL ,
& V_407 -> V_17 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_146 ( V_405 , V_406 , V_407 ) ;
if ( V_53 )
V_407 -> V_17 = V_406 -> V_17 ;
}
V_280 . type = V_293 ;
V_280 . V_285 . V_245 = V_405 -> V_42 -> V_294 ;
if ( V_407 -> V_17 == V_406 -> V_17 ) {
V_53 = F_46 ( V_406 -> V_17 , V_24 -> V_17 ,
V_32 , V_420 , & V_280 ) ;
if ( V_53 )
return V_53 ;
} else {
V_53 = F_46 ( V_406 -> V_17 , V_407 -> V_17 ,
V_269 , V_421 , & V_280 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_407 -> V_17 , V_24 -> V_17 ,
V_32 , V_422 , & V_280 ) ;
if ( V_53 )
return V_53 ;
if ( V_405 -> V_409 & V_423 ) {
V_53 = F_46 ( V_406 -> V_17 , V_407 -> V_17 ,
V_269 , V_424 ,
NULL ) ;
if ( V_53 )
return - V_414 ;
}
if ( V_405 -> V_409 &
( V_425 | V_426 ) ) {
struct V_20 * V_427 ;
struct V_13 * V_428 ;
T_2 V_429 = 0 ;
F_19 () ;
V_427 = F_149 ( V_11 ) ;
if ( F_150 ( V_427 != NULL ) ) {
V_428 = F_20 ( V_427 ) -> V_19 ;
V_429 = V_428 -> V_17 ;
}
F_21 () ;
if ( V_429 != 0 ) {
V_53 = F_46 ( V_429 , V_407 -> V_17 ,
V_269 ,
V_363 , NULL ) ;
if ( V_53 )
return - V_414 ;
}
}
V_405 -> V_430 |= V_431 ;
}
return 0 ;
}
static int F_151 ( struct V_404 * V_405 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_17 , V_16 ;
int V_432 = 0 ;
V_17 = V_14 -> V_17 ;
V_16 = V_14 -> V_16 ;
if ( V_16 != V_17 ) {
V_432 = F_46 ( V_16 , V_17 ,
V_269 ,
V_433 , NULL ) ;
}
return ! ! V_432 ;
}
static int F_152 ( const void * V_145 , struct V_42 * V_42 , unsigned V_434 )
{
return F_121 ( V_145 , V_42 , F_131 ( V_42 ) ) ? V_434 + 1 : 0 ;
}
static inline void F_153 ( const struct V_10 * V_10 ,
struct V_435 * V_436 )
{
struct V_42 * V_42 , * V_437 = NULL ;
struct V_438 * V_439 ;
int V_440 = 0 ;
unsigned V_441 ;
V_439 = F_154 () ;
if ( V_439 ) {
F_32 ( & V_442 ) ;
if ( ! F_33 ( & V_439 -> V_443 ) ) {
struct V_444 * V_445 ;
V_445 = F_155 ( & V_439 -> V_443 ,
struct V_444 , V_29 ) ;
V_42 = V_445 -> V_42 ;
if ( F_119 ( V_10 , V_42 , V_333 | V_337 ) )
V_440 = 1 ;
}
F_35 ( & V_442 ) ;
F_156 ( V_439 ) ;
}
if ( V_440 )
F_157 () ;
V_441 = F_158 ( V_436 , 0 , F_152 , V_10 ) ;
if ( ! V_441 )
return;
V_437 = F_159 ( & V_446 , V_447 , V_10 ) ;
if ( F_90 ( V_437 ) )
V_437 = NULL ;
do {
F_160 ( V_441 - 1 , V_437 , 0 ) ;
} while ( ( V_441 = F_158 ( V_436 , V_441 , F_152 , V_10 ) ) != 0 );
if ( V_437 )
F_161 ( V_437 ) ;
}
static void F_162 ( struct V_404 * V_405 )
{
struct V_13 * V_407 ;
struct V_448 * V_449 , * V_450 ;
int V_53 , V_86 ;
V_407 = V_405 -> V_10 -> V_19 ;
if ( V_407 -> V_17 == V_407 -> V_16 )
return;
F_153 ( V_405 -> V_10 , V_11 -> V_436 ) ;
V_11 -> V_451 = 0 ;
V_53 = F_46 ( V_407 -> V_16 , V_407 -> V_17 , V_269 ,
V_452 , NULL ) ;
if ( V_53 ) {
F_163 ( V_11 ) ;
for ( V_86 = 0 ; V_86 < V_453 ; V_86 ++ ) {
V_449 = V_11 -> signal -> V_449 + V_86 ;
V_450 = V_454 . signal -> V_449 + V_86 ;
V_449 -> V_455 = F_164 ( V_449 -> V_456 , V_450 -> V_455 ) ;
}
F_165 ( V_11 ) ;
F_166 ( V_11 , V_448 ( V_457 ) ) ;
}
}
static void F_167 ( struct V_404 * V_405 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_458 V_459 ;
T_2 V_16 , V_17 ;
int V_53 , V_86 ;
V_16 = V_14 -> V_16 ;
V_17 = V_14 -> V_17 ;
if ( V_17 == V_16 )
return;
V_53 = F_46 ( V_16 , V_17 , V_269 , V_460 , NULL ) ;
if ( V_53 ) {
memset ( & V_459 , 0 , sizeof V_459 ) ;
for ( V_86 = 0 ; V_86 < 3 ; V_86 ++ )
F_168 ( V_86 , & V_459 , NULL ) ;
F_169 ( & V_11 -> V_461 -> V_462 ) ;
if ( ! F_170 ( V_11 ) ) {
F_171 ( & V_11 -> V_463 ) ;
F_171 ( & V_11 -> signal -> V_464 ) ;
F_172 ( V_11 , 1 ) ;
F_173 ( & V_11 -> V_465 ) ;
F_174 () ;
}
F_175 ( & V_11 -> V_461 -> V_462 ) ;
}
F_176 ( & V_466 ) ;
F_177 ( V_11 , V_11 -> V_467 ) ;
F_178 ( & V_466 ) ;
}
static int F_179 ( struct V_47 * V_48 )
{
return F_40 ( V_48 ) ;
}
static void F_180 ( struct V_47 * V_48 )
{
F_42 ( V_48 ) ;
}
static inline int F_181 ( char * V_161 , int V_468 , char * V_469 , int V_470 )
{
if ( V_468 > V_470 )
return 0 ;
return ! memcmp ( V_161 , V_469 , V_468 ) ;
}
static inline int F_182 ( char * V_469 , int V_88 )
{
return ( F_181 ( V_163 , sizeof( V_163 ) - 1 , V_469 , V_88 ) ||
F_181 ( V_164 , sizeof( V_164 ) - 1 , V_469 , V_88 ) ||
F_181 ( V_166 , sizeof( V_166 ) - 1 , V_469 , V_88 ) ||
F_181 ( V_165 , sizeof( V_165 ) - 1 , V_469 , V_88 ) ||
F_181 ( V_167 , sizeof( V_167 ) - 1 , V_469 , V_88 ) ) ;
}
static inline void F_183 ( char * * V_354 , char * V_353 , int * V_471 , int V_88 )
{
if ( ! * V_471 ) {
* * V_354 = ',' ;
* V_354 += 1 ;
} else
* V_471 = 0 ;
memcpy ( * V_354 , V_353 , V_88 ) ;
* V_354 += V_88 ;
}
static inline void F_184 ( char * * V_354 , char * V_353 , int * V_471 ,
int V_88 )
{
int V_472 = 0 ;
if ( ! * V_471 ) {
* * V_354 = '|' ;
* V_354 += 1 ;
} else
* V_471 = 0 ;
while ( V_472 < V_88 ) {
if ( * V_353 != '"' ) {
* * V_354 = * V_353 ;
* V_354 += 1 ;
}
V_353 += 1 ;
V_472 += 1 ;
}
}
static int F_185 ( char * V_473 , char * V_474 )
{
int V_475 , V_44 , V_53 = 0 ;
char * V_476 , * V_477 , * V_478 ;
char * V_479 , * V_480 , * V_481 ;
int V_482 = 0 ;
V_477 = V_473 ;
V_479 = V_474 ;
V_481 = ( char * ) F_186 ( V_15 ) ;
if ( ! V_481 ) {
V_53 = - V_27 ;
goto V_74;
}
V_480 = V_481 ;
V_475 = V_44 = 1 ;
V_476 = V_478 = V_473 ;
do {
if ( * V_478 == '"' )
V_482 = ! V_482 ;
if ( ( * V_478 == ',' && V_482 == 0 ) ||
* V_478 == '\0' ) {
int V_88 = V_478 - V_477 ;
if ( F_182 ( V_477 , V_88 ) )
F_184 ( & V_479 , V_477 , & V_44 , V_88 ) ;
else
F_183 ( & V_481 , V_477 , & V_475 , V_88 ) ;
V_477 = V_478 + 1 ;
}
} while ( * V_478 ++ );
strcpy ( V_476 , V_480 ) ;
F_93 ( ( unsigned long ) V_480 ) ;
V_74:
return V_53 ;
}
static int F_187 ( struct V_47 * V_48 , void * V_158 )
{
int V_53 , V_86 , * V_79 ;
struct V_84 V_85 ;
char * V_483 , * * V_114 ;
struct V_37 * V_38 = V_48 -> V_40 ;
if ( ! ( V_38 -> V_79 & V_80 ) )
return 0 ;
if ( ! V_158 )
return 0 ;
if ( V_48 -> V_63 -> V_116 & V_117 )
return 0 ;
F_58 ( & V_85 ) ;
V_483 = F_188 () ;
if ( ! V_483 )
return - V_27 ;
V_53 = F_185 ( V_158 , V_483 ) ;
if ( V_53 )
goto V_484;
V_53 = F_73 ( V_483 , & V_85 ) ;
if ( V_53 )
goto V_484;
V_114 = V_85 . V_95 ;
V_79 = V_85 . V_98 ;
for ( V_86 = 0 ; V_86 < V_85 . V_94 ; V_86 ++ ) {
T_2 V_17 ;
T_7 V_88 ;
if ( V_79 [ V_86 ] == V_81 )
continue;
V_88 = strlen ( V_114 [ V_86 ] ) ;
V_53 = F_68 ( V_114 [ V_86 ] , V_88 , & V_17 ,
V_15 ) ;
if ( V_53 ) {
F_51 ( V_71 L_14
L_15 ,
V_114 [ V_86 ] , V_48 -> V_72 , V_48 -> V_63 -> V_64 , V_53 ) ;
goto V_485;
}
V_53 = - V_90 ;
switch ( V_79 [ V_86 ] ) {
case V_99 :
if ( F_64 ( V_38 , V_99 , V_38 -> V_17 , V_17 ) )
goto V_486;
break;
case V_100 :
if ( F_64 ( V_38 , V_100 , V_38 -> V_52 , V_17 ) )
goto V_486;
break;
case V_102 : {
struct V_23 * V_109 ;
V_109 = F_50 ( V_48 -> V_67 ) -> V_33 ;
if ( F_64 ( V_38 , V_102 , V_109 -> V_17 , V_17 ) )
goto V_486;
break;
}
case V_101 :
if ( F_64 ( V_38 , V_101 , V_38 -> V_50 , V_17 ) )
goto V_486;
break;
default:
goto V_485;
}
}
V_53 = 0 ;
V_485:
F_63 ( & V_85 ) ;
V_484:
F_189 ( V_483 ) ;
return V_53 ;
V_486:
F_51 ( V_71 L_36
L_37 , V_48 -> V_72 ,
V_48 -> V_63 -> V_64 ) ;
goto V_485;
}
static int F_190 ( struct V_47 * V_48 , int V_79 , void * V_158 )
{
const struct V_10 * V_10 = F_66 () ;
struct V_279 V_280 ;
int V_53 ;
V_53 = F_77 ( V_48 , V_158 ) ;
if ( V_53 )
return V_53 ;
if ( V_79 & V_487 )
return 0 ;
V_280 . type = V_292 ;
V_280 . V_285 . V_65 = V_48 -> V_67 ;
return F_128 ( V_10 , V_48 , V_488 , & V_280 ) ;
}
static int F_191 ( struct V_65 * V_65 )
{
const struct V_10 * V_10 = F_66 () ;
struct V_279 V_280 ;
V_280 . type = V_292 ;
V_280 . V_285 . V_65 = V_65 -> V_489 -> V_67 ;
return F_128 ( V_10 , V_65 -> V_489 , V_490 , & V_280 ) ;
}
static int F_192 ( const char * V_491 ,
struct V_245 * V_245 ,
const char * type ,
unsigned long V_79 ,
void * V_158 )
{
const struct V_10 * V_10 = F_66 () ;
if ( V_79 & V_492 )
return F_128 ( V_10 , V_245 -> V_65 -> V_489 ,
V_493 , NULL ) ;
else
return F_118 ( V_10 , V_245 , V_494 ) ;
}
static int F_193 ( struct V_495 * V_412 , int V_79 )
{
const struct V_10 * V_10 = F_66 () ;
return F_128 ( V_10 , V_412 -> V_496 ,
V_497 , NULL ) ;
}
static int F_194 ( struct V_22 * V_22 )
{
return F_24 ( V_22 ) ;
}
static void F_195 ( struct V_22 * V_22 )
{
F_31 ( V_22 ) ;
}
static int F_196 ( struct V_65 * V_65 , int V_168 ,
struct V_498 * V_64 , void * * V_306 ,
T_2 * V_499 )
{
const struct V_10 * V_10 = F_66 () ;
struct V_13 * V_14 ;
struct V_23 * V_298 ;
struct V_37 * V_38 ;
struct V_22 * V_297 = F_50 ( V_65 -> V_500 ) ;
T_2 V_299 ;
int V_53 ;
V_14 = V_10 -> V_19 ;
V_298 = V_297 -> V_33 ;
V_38 = V_297 -> V_39 -> V_40 ;
if ( V_14 -> V_300 && V_38 -> V_58 != V_123 ) {
V_299 = V_14 -> V_300 ;
} else {
V_53 = F_102 ( V_14 -> V_17 , V_298 -> V_17 ,
F_83 ( V_168 ) ,
V_64 ,
& V_299 ) ;
if ( V_53 ) {
F_51 ( V_71
L_38 ,
V_121 , - V_53 ) ;
return V_53 ;
}
}
return F_61 ( V_299 , ( char * * ) V_306 , V_499 ) ;
}
static int F_197 ( struct V_22 * V_22 , struct V_22 * V_297 ,
const struct V_498 * V_498 ,
const char * * V_64 ,
void * * V_501 , T_7 * V_88 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_298 ;
struct V_37 * V_38 ;
T_2 V_17 , V_299 , V_502 ;
int V_53 ;
char * V_87 ;
V_298 = V_297 -> V_33 ;
V_38 = V_297 -> V_39 -> V_40 ;
V_17 = V_14 -> V_17 ;
V_299 = V_14 -> V_300 ;
if ( ( V_38 -> V_79 & V_80 ) &&
( V_38 -> V_58 == V_123 ) )
V_299 = V_38 -> V_52 ;
else if ( ! V_299 || ! ( V_38 -> V_79 & V_81 ) ) {
V_53 = F_102 ( V_17 , V_298 -> V_17 ,
F_83 ( V_22 -> V_254 ) ,
V_498 , & V_299 ) ;
if ( V_53 ) {
F_51 ( V_71 L_39
L_40
L_41 ,
V_121 ,
- V_53 , V_22 -> V_39 -> V_72 , V_22 -> V_250 ) ;
return V_53 ;
}
}
if ( V_38 -> V_79 & V_80 ) {
struct V_23 * V_24 = V_22 -> V_33 ;
V_24 -> V_31 = F_83 ( V_22 -> V_254 ) ;
V_24 -> V_17 = V_299 ;
V_24 -> V_124 = 1 ;
}
if ( ! V_91 || ! ( V_38 -> V_79 & V_81 ) )
return - V_73 ;
if ( V_64 )
* V_64 = V_503 ;
if ( V_501 && V_88 ) {
V_53 = F_198 ( V_299 , & V_87 , & V_502 ) ;
if ( V_53 )
return V_53 ;
* V_501 = V_87 ;
* V_88 = V_502 ;
}
return 0 ;
}
static int F_199 ( struct V_22 * V_297 , struct V_65 * V_65 , T_5 V_168 )
{
return F_122 ( V_297 , V_65 , V_32 ) ;
}
static int F_200 ( struct V_65 * V_318 , struct V_22 * V_297 , struct V_65 * V_320 )
{
return F_124 ( V_297 , V_318 , V_311 ) ;
}
static int F_201 ( struct V_22 * V_297 , struct V_65 * V_65 )
{
return F_124 ( V_297 , V_65 , V_313 ) ;
}
static int F_202 ( struct V_22 * V_297 , struct V_65 * V_65 , const char * V_64 )
{
return F_122 ( V_297 , V_65 , V_173 ) ;
}
static int F_203 ( struct V_22 * V_297 , struct V_65 * V_65 , T_5 V_329 )
{
return F_122 ( V_297 , V_65 , V_178 ) ;
}
static int F_204 ( struct V_22 * V_297 , struct V_65 * V_65 )
{
return F_124 ( V_297 , V_65 , V_315 ) ;
}
static int F_205 ( struct V_22 * V_297 , struct V_65 * V_65 , T_5 V_168 , T_8 V_251 )
{
return F_122 ( V_297 , V_65 , F_83 ( V_168 ) ) ;
}
static int F_206 ( struct V_22 * V_504 , struct V_65 * V_318 ,
struct V_22 * V_505 , struct V_65 * V_320 )
{
return F_125 ( V_504 , V_318 , V_505 , V_320 ) ;
}
static int F_207 ( struct V_65 * V_65 )
{
const struct V_10 * V_10 = F_66 () ;
return F_117 ( V_10 , V_65 , V_333 ) ;
}
static int F_208 ( struct V_65 * V_65 , struct V_22 * V_22 ,
bool V_36 )
{
const struct V_10 * V_10 = F_66 () ;
struct V_279 V_280 ;
struct V_23 * V_24 ;
T_2 V_17 ;
F_115 ( V_10 ) ;
V_280 . type = V_292 ;
V_280 . V_285 . V_65 = V_65 ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
return F_209 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_333 , & V_280 ,
V_36 ? V_506 : 0 ) ;
}
static T_9 int F_210 ( struct V_22 * V_22 ,
T_2 V_266 , T_2 V_507 , T_2 V_508 ,
int V_509 ,
unsigned V_79 )
{
struct V_279 V_280 ;
struct V_23 * V_24 = V_22 -> V_33 ;
int V_53 ;
V_280 . type = V_510 ;
V_280 . V_285 . V_22 = V_22 ;
V_53 = F_211 ( F_22 () , V_24 -> V_17 , V_24 -> V_31 , V_266 ,
V_507 , V_508 , V_509 , & V_280 , V_79 ) ;
if ( V_53 )
return V_53 ;
return 0 ;
}
static int F_212 ( struct V_22 * V_22 , int V_329 )
{
const struct V_10 * V_10 = F_66 () ;
T_2 V_266 ;
bool V_511 ;
unsigned V_79 = V_329 & V_506 ;
struct V_23 * V_24 ;
T_2 V_17 ;
struct V_281 V_282 ;
int V_53 , V_289 ;
T_2 V_507 , V_508 ;
V_511 = V_329 & V_512 ;
V_329 &= ( V_332 | V_336 | V_330 | V_334 ) ;
if ( ! V_329 )
return 0 ;
F_115 ( V_10 ) ;
if ( F_116 ( F_55 ( V_22 ) ) )
return 0 ;
V_266 = F_129 ( V_22 -> V_254 , V_329 ) ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
V_53 = F_111 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_266 , 0 , & V_282 ) ;
V_507 = F_213 ( V_266 , & V_282 , V_53 ,
V_511 ? V_513 : 0 ,
& V_508 ) ;
if ( F_150 ( ! V_507 ) )
return V_53 ;
V_289 = F_210 ( V_22 , V_266 , V_507 , V_508 , V_53 , V_79 ) ;
if ( V_289 )
return V_289 ;
return V_53 ;
}
static int F_214 ( struct V_65 * V_65 , struct V_514 * V_514 )
{
const struct V_10 * V_10 = F_66 () ;
unsigned int V_515 = V_514 -> V_515 ;
T_10 V_283 = V_337 ;
if ( V_515 & V_516 ) {
V_515 &= ~ ( V_517 | V_518 | V_519 |
V_516 ) ;
if ( ! V_515 )
return 0 ;
}
if ( V_515 & ( V_519 | V_520 | V_521 |
V_522 | V_523 | V_524 ) )
return F_117 ( V_10 , V_65 , V_525 ) ;
if ( V_346 && ( V_515 & V_526 ) )
V_283 |= V_347 ;
return F_117 ( V_10 , V_65 , V_283 ) ;
}
static int F_215 ( const struct V_245 * V_245 )
{
return F_118 ( F_66 () , V_245 , V_527 ) ;
}
static int F_216 ( struct V_65 * V_65 , const char * V_64 )
{
const struct V_10 * V_10 = F_66 () ;
if ( ! strncmp ( V_64 , V_528 ,
sizeof V_528 - 1 ) ) {
if ( ! strcmp ( V_64 , V_529 ) ) {
if ( ! F_217 ( V_530 ) )
return - V_414 ;
} else if ( ! F_217 ( V_402 ) ) {
return - V_414 ;
}
}
return F_117 ( V_10 , V_65 , V_525 ) ;
}
static int F_218 ( struct V_65 * V_65 , const char * V_64 ,
const void * V_501 , T_7 V_531 , int V_79 )
{
struct V_22 * V_22 = F_50 ( V_65 ) ;
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_37 * V_38 ;
struct V_279 V_280 ;
T_2 V_299 , V_17 = F_22 () ;
int V_53 = 0 ;
if ( strcmp ( V_64 , V_75 ) )
return F_216 ( V_65 , V_64 ) ;
V_38 = V_22 -> V_39 -> V_40 ;
if ( ! ( V_38 -> V_79 & V_81 ) )
return - V_73 ;
if ( ! F_219 ( V_22 ) )
return - V_414 ;
V_280 . type = V_292 ;
V_280 . V_285 . V_65 = V_65 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 ,
V_532 , & V_280 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_68 ( V_501 , V_531 , & V_299 , V_15 ) ;
if ( V_53 == - V_90 ) {
if ( ! F_217 ( V_533 ) ) {
struct V_534 * V_535 ;
T_7 V_536 ;
const char * V_1 ;
if ( V_501 ) {
V_1 = V_501 ;
if ( V_1 [ V_531 - 1 ] == '\0' )
V_536 = V_531 - 1 ;
else
V_536 = V_531 ;
} else {
V_1 = L_42 ;
V_536 = 0 ;
}
V_535 = F_220 ( V_11 -> V_537 , V_96 , V_538 ) ;
F_221 ( V_535 , L_43 ) ;
F_222 ( V_535 , V_501 , V_536 ) ;
F_223 ( V_535 ) ;
return V_53 ;
}
V_53 = F_224 ( V_501 , V_531 , & V_299 ) ;
}
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_17 , V_299 , V_24 -> V_31 ,
V_539 , & V_280 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_225 ( V_24 -> V_17 , V_299 , V_17 ,
V_24 -> V_31 ) ;
if ( V_53 )
return V_53 ;
return F_46 ( V_299 ,
V_38 -> V_17 ,
V_54 ,
V_57 ,
& V_280 ) ;
}
static void F_226 ( struct V_65 * V_65 , const char * V_64 ,
const void * V_501 , T_7 V_531 ,
int V_79 )
{
struct V_22 * V_22 = F_50 ( V_65 ) ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_299 ;
int V_53 ;
if ( strcmp ( V_64 , V_75 ) ) {
return;
}
V_53 = F_224 ( V_501 , V_531 , & V_299 ) ;
if ( V_53 ) {
F_51 ( V_78 L_44
L_45 ,
V_22 -> V_39 -> V_72 , V_22 -> V_250 , - V_53 ) ;
return;
}
V_24 -> V_31 = F_83 ( V_22 -> V_254 ) ;
V_24 -> V_17 = V_299 ;
V_24 -> V_124 = 1 ;
return;
}
static int F_227 ( struct V_65 * V_65 , const char * V_64 )
{
const struct V_10 * V_10 = F_66 () ;
return F_117 ( V_10 , V_65 , V_527 ) ;
}
static int F_228 ( struct V_65 * V_65 )
{
const struct V_10 * V_10 = F_66 () ;
return F_117 ( V_10 , V_65 , V_527 ) ;
}
static int F_229 ( struct V_65 * V_65 , const char * V_64 )
{
if ( strcmp ( V_64 , V_75 ) )
return F_216 ( V_65 , V_64 ) ;
return - V_415 ;
}
static int F_230 ( const struct V_22 * V_22 , const char * V_64 , void * * V_244 , bool V_540 )
{
T_2 V_531 ;
int error ;
char * V_87 = NULL ;
struct V_23 * V_24 = V_22 -> V_33 ;
if ( strcmp ( V_64 , V_503 ) )
return - V_73 ;
error = F_231 ( F_66 () , & V_541 , V_533 ,
V_403 ) ;
if ( ! error )
error = F_108 ( F_66 () , V_533 ,
V_403 ) ;
if ( ! error )
error = F_198 ( V_24 -> V_17 , & V_87 ,
& V_531 ) ;
else
error = F_61 ( V_24 -> V_17 , & V_87 , & V_531 ) ;
if ( error )
return error ;
error = V_531 ;
if ( V_540 ) {
* V_244 = V_87 ;
goto V_542;
}
F_39 ( V_87 ) ;
V_542:
return error ;
}
static int F_232 ( struct V_22 * V_22 , const char * V_64 ,
const void * V_501 , T_7 V_531 , int V_79 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_299 ;
int V_53 ;
if ( strcmp ( V_64 , V_503 ) )
return - V_73 ;
if ( ! V_501 || ! V_531 )
return - V_415 ;
V_53 = F_68 ( ( void * ) V_501 , V_531 , & V_299 , V_15 ) ;
if ( V_53 )
return V_53 ;
V_24 -> V_31 = F_83 ( V_22 -> V_254 ) ;
V_24 -> V_17 = V_299 ;
V_24 -> V_124 = 1 ;
return 0 ;
}
static int F_233 ( struct V_22 * V_22 , char * V_244 , T_7 V_543 )
{
const int V_88 = sizeof( V_75 ) ;
if ( V_244 && V_88 <= V_543 )
memcpy ( V_244 , V_75 , V_88 ) ;
return V_88 ;
}
static void F_234 ( const struct V_22 * V_22 , T_2 * V_544 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
* V_544 = V_24 -> V_17 ;
}
static int F_235 ( struct V_42 * V_42 , int V_329 )
{
const struct V_10 * V_10 = F_66 () ;
struct V_22 * V_22 = F_120 ( V_42 ) ;
if ( ( V_42 -> V_343 & V_344 ) && ( V_329 & V_336 ) )
V_329 |= V_334 ;
return F_121 ( V_10 , V_42 ,
F_129 ( V_22 -> V_254 , V_329 ) ) ;
}
static int F_236 ( struct V_42 * V_42 , int V_329 )
{
struct V_22 * V_22 = F_120 ( V_42 ) ;
struct V_43 * V_44 = V_42 -> V_46 ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 = F_22 () ;
if ( ! V_329 )
return 0 ;
if ( V_17 == V_44 -> V_17 && V_44 -> V_545 == V_24 -> V_17 &&
V_44 -> V_546 == F_237 () )
return 0 ;
return F_235 ( V_42 , V_329 ) ;
}
static int F_238 ( struct V_42 * V_42 )
{
return F_37 ( V_42 ) ;
}
static void F_239 ( struct V_42 * V_42 )
{
F_38 ( V_42 ) ;
}
static int F_240 ( struct V_42 * V_42 , unsigned int V_547 ,
unsigned long V_548 )
{
const struct V_10 * V_10 = F_66 () ;
int error = 0 ;
switch ( V_547 ) {
case V_549 :
case V_550 :
case V_551 :
case V_552 :
case V_553 :
error = F_121 ( V_10 , V_42 , V_527 ) ;
break;
case V_554 :
case V_555 :
error = F_121 ( V_10 , V_42 , V_525 ) ;
break;
case V_556 :
case V_557 :
error = F_121 ( V_10 , V_42 , 0 ) ;
break;
case V_558 :
case V_559 :
error = F_108 ( V_10 , V_560 ,
V_288 ) ;
break;
default:
error = F_121 ( V_10 , V_42 , V_345 ) ;
}
return error ;
}
static int F_241 ( struct V_42 * V_42 , unsigned long V_561 , int V_562 )
{
const struct V_10 * V_10 = F_66 () ;
int V_53 = 0 ;
if ( V_563 &&
( V_561 & V_564 ) && ( ! V_42 || F_55 ( F_120 ( V_42 ) ) ||
( ! V_562 && ( V_561 & V_565 ) ) ) ) {
V_53 = F_105 ( V_10 , V_10 , V_566 ) ;
if ( V_53 )
goto error;
}
if ( V_42 ) {
T_2 V_283 = V_333 ;
if ( V_562 && ( V_561 & V_565 ) )
V_283 |= V_337 ;
if ( V_561 & V_564 )
V_283 |= V_331 ;
return F_121 ( V_10 , V_42 , V_283 ) ;
}
error:
return V_53 ;
}
static int F_242 ( unsigned long V_567 )
{
int V_53 = 0 ;
if ( V_567 < V_568 ) {
T_2 V_17 = F_22 () ;
V_53 = F_46 ( V_17 , V_17 , V_569 ,
V_570 , NULL ) ;
}
return V_53 ;
}
static int F_243 ( struct V_42 * V_42 , unsigned long V_571 ,
unsigned long V_561 , unsigned long V_79 )
{
if ( V_572 )
V_561 = V_571 ;
return F_241 ( V_42 , V_561 ,
( V_79 & V_573 ) == V_574 ) ;
}
static int F_244 ( struct V_575 * V_576 ,
unsigned long V_571 ,
unsigned long V_561 )
{
const struct V_10 * V_10 = F_66 () ;
if ( V_572 )
V_561 = V_571 ;
if ( V_563 &&
( V_561 & V_564 ) && ! ( V_576 -> V_577 & V_578 ) ) {
int V_53 = 0 ;
if ( V_576 -> V_579 >= V_576 -> V_580 -> V_581 &&
V_576 -> V_582 <= V_576 -> V_580 -> V_583 ) {
V_53 = F_105 ( V_10 , V_10 , V_584 ) ;
} else if ( ! V_576 -> V_585 &&
V_576 -> V_579 <= V_576 -> V_580 -> V_586 &&
V_576 -> V_582 >= V_576 -> V_580 -> V_586 ) {
V_53 = F_107 ( V_11 , V_587 ) ;
} else if ( V_576 -> V_585 && V_576 -> V_588 ) {
V_53 = F_121 ( V_10 , V_576 -> V_585 , V_589 ) ;
}
if ( V_53 )
return V_53 ;
}
return F_241 ( V_576 -> V_585 , V_561 , V_576 -> V_577 & V_590 ) ;
}
static int F_245 ( struct V_42 * V_42 , unsigned int V_547 )
{
const struct V_10 * V_10 = F_66 () ;
return F_121 ( V_10 , V_42 , V_591 ) ;
}
static int F_246 ( struct V_42 * V_42 , unsigned int V_547 ,
unsigned long V_548 )
{
const struct V_10 * V_10 = F_66 () ;
int V_592 = 0 ;
switch ( V_547 ) {
case V_593 :
if ( ( V_42 -> V_343 & V_344 ) && ! ( V_548 & V_344 ) ) {
V_592 = F_121 ( V_10 , V_42 , V_337 ) ;
break;
}
case V_594 :
case V_595 :
case V_596 :
case V_597 :
case V_598 :
case V_599 :
V_592 = F_121 ( V_10 , V_42 , 0 ) ;
break;
case V_600 :
case V_601 :
case V_602 :
case V_603 :
case V_604 :
case V_605 :
#if V_606 == 32
case V_607 :
case V_608 :
case V_609 :
#endif
V_592 = F_121 ( V_10 , V_42 , V_591 ) ;
break;
}
return V_592 ;
}
static void F_247 ( struct V_42 * V_42 )
{
struct V_43 * V_44 ;
V_44 = V_42 -> V_46 ;
V_44 -> V_45 = F_22 () ;
}
static int F_248 ( struct V_20 * V_276 ,
struct V_610 * V_611 , int V_612 )
{
struct V_42 * V_42 ;
T_2 V_17 = F_18 ( V_276 ) ;
T_2 V_256 ;
struct V_43 * V_44 ;
V_42 = F_29 ( V_611 , struct V_42 , V_613 ) ;
V_44 = V_42 -> V_46 ;
if ( ! V_612 )
V_256 = F_104 ( V_614 ) ;
else
V_256 = F_104 ( V_612 ) ;
return F_46 ( V_44 -> V_45 , V_17 ,
V_269 , V_256 , NULL ) ;
}
static int F_249 ( struct V_42 * V_42 )
{
const struct V_10 * V_10 = F_66 () ;
return F_121 ( V_10 , V_42 , F_131 ( V_42 ) ) ;
}
static int F_250 ( struct V_42 * V_42 , const struct V_10 * V_10 )
{
struct V_43 * V_44 ;
struct V_23 * V_24 ;
V_44 = V_42 -> V_46 ;
V_24 = F_120 ( V_42 ) -> V_33 ;
V_44 -> V_545 = V_24 -> V_17 ;
V_44 -> V_546 = F_237 () ;
return F_119 ( V_10 , V_42 , F_132 ( V_42 ) ) ;
}
static int F_251 ( unsigned long V_615 )
{
return F_107 ( V_11 , V_616 ) ;
}
static int F_252 ( struct V_10 * V_10 , T_11 V_617 )
{
struct V_13 * V_14 ;
V_14 = F_15 ( sizeof( struct V_13 ) , V_617 ) ;
if ( ! V_14 )
return - V_27 ;
V_10 -> V_19 = V_14 ;
return 0 ;
}
static void F_253 ( struct V_10 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_19 ;
F_62 ( V_10 -> V_19 && ( unsigned long ) V_10 -> V_19 < V_246 ) ;
V_10 -> V_19 = ( void * ) 0x7UL ;
F_39 ( V_14 ) ;
}
static int F_254 ( struct V_10 * V_128 , const struct V_10 * V_127 ,
T_11 V_617 )
{
const struct V_13 * V_406 ;
struct V_13 * V_14 ;
V_406 = V_127 -> V_19 ;
V_14 = F_255 ( V_406 , sizeof( struct V_13 ) , V_617 ) ;
if ( ! V_14 )
return - V_27 ;
V_128 -> V_19 = V_14 ;
return 0 ;
}
static void F_256 ( struct V_10 * V_128 , const struct V_10 * V_127 )
{
const struct V_13 * V_406 = V_127 -> V_19 ;
struct V_13 * V_14 = V_128 -> V_19 ;
* V_14 = * V_406 ;
}
static int F_257 ( struct V_10 * V_128 , T_2 V_544 )
{
struct V_13 * V_14 = V_128 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_618 ;
V_618 = F_46 ( V_17 , V_544 ,
V_619 ,
V_620 ,
NULL ) ;
if ( V_618 == 0 ) {
V_14 -> V_17 = V_544 ;
V_14 -> V_300 = 0 ;
V_14 -> V_417 = 0 ;
V_14 -> V_418 = 0 ;
}
return V_618 ;
}
static int F_258 ( struct V_10 * V_128 , struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_13 * V_14 = V_128 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_618 ;
V_618 = F_46 ( V_17 , V_24 -> V_17 ,
V_619 ,
V_621 ,
NULL ) ;
if ( V_618 == 0 )
V_14 -> V_300 = V_24 -> V_17 ;
return V_618 ;
}
static int F_259 ( char * V_622 )
{
T_2 V_17 ;
struct V_279 V_280 ;
V_17 = F_18 ( V_11 ) ;
V_280 . type = V_623 ;
V_280 . V_285 . V_622 = V_622 ;
return F_46 ( V_17 , V_18 , V_290 ,
V_624 , & V_280 ) ;
}
static int F_260 ( struct V_20 * V_145 , T_12 V_625 )
{
return F_107 ( V_145 , V_626 ) ;
}
static int F_261 ( struct V_20 * V_145 )
{
return F_107 ( V_145 , V_627 ) ;
}
static int F_262 ( struct V_20 * V_145 )
{
return F_107 ( V_145 , V_628 ) ;
}
static void F_263 ( struct V_20 * V_145 , T_2 * V_544 )
{
* V_544 = F_18 ( V_145 ) ;
}
static int F_264 ( struct V_20 * V_145 , int V_629 )
{
return F_107 ( V_145 , V_630 ) ;
}
static int F_265 ( struct V_20 * V_145 , int V_631 )
{
return F_107 ( V_145 , V_630 ) ;
}
static int F_266 ( struct V_20 * V_145 )
{
return F_107 ( V_145 , V_632 ) ;
}
static int F_267 ( struct V_20 * V_145 , unsigned int V_633 ,
struct V_448 * V_634 )
{
struct V_448 * V_635 = V_145 -> signal -> V_449 + V_633 ;
if ( V_635 -> V_456 != V_634 -> V_456 )
return F_107 ( V_145 , V_636 ) ;
return 0 ;
}
static int F_268 ( struct V_20 * V_145 )
{
return F_107 ( V_145 , V_630 ) ;
}
static int F_269 ( struct V_20 * V_145 )
{
return F_107 ( V_145 , V_632 ) ;
}
static int F_270 ( struct V_20 * V_145 )
{
return F_107 ( V_145 , V_630 ) ;
}
static int F_271 ( struct V_20 * V_145 , struct V_637 * V_638 ,
int V_255 , T_2 V_544 )
{
T_2 V_256 ;
int V_53 ;
if ( ! V_255 )
V_256 = V_639 ;
else
V_256 = F_104 ( V_255 ) ;
if ( V_544 )
V_53 = F_46 ( V_544 , F_18 ( V_145 ) ,
V_269 , V_256 , NULL ) ;
else
V_53 = F_107 ( V_145 , V_256 ) ;
return V_53 ;
}
static int F_272 ( struct V_20 * V_145 )
{
return F_106 ( V_145 , V_11 , V_258 ) ;
}
static void F_273 ( struct V_20 * V_145 ,
struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 = F_18 ( V_145 ) ;
V_24 -> V_17 = V_17 ;
V_24 -> V_124 = 1 ;
}
static int F_274 ( struct V_640 * V_641 ,
struct V_279 * V_280 , T_13 * V_642 )
{
int V_643 , V_644 , V_618 = - V_90 ;
struct V_645 V_646 , * V_647 ;
V_643 = F_275 ( V_641 ) ;
V_647 = F_276 ( V_641 , V_643 , sizeof( V_646 ) , & V_646 ) ;
if ( V_647 == NULL )
goto V_74;
V_644 = V_647 -> V_648 * 4 ;
if ( V_644 < sizeof( V_646 ) )
goto V_74;
V_280 -> V_285 . V_649 -> V_650 . V_651 = V_647 -> V_651 ;
V_280 -> V_285 . V_649 -> V_650 . V_652 = V_647 -> V_652 ;
V_618 = 0 ;
if ( V_642 )
* V_642 = V_647 -> V_183 ;
switch ( V_647 -> V_183 ) {
case V_185 : {
struct V_653 V_654 , * V_655 ;
if ( F_277 ( V_647 -> V_656 ) & V_657 )
break;
V_643 += V_644 ;
V_655 = F_276 ( V_641 , V_643 , sizeof( V_654 ) , & V_654 ) ;
if ( V_655 == NULL )
break;
V_280 -> V_285 . V_649 -> V_658 = V_655 -> V_659 ;
V_280 -> V_285 . V_649 -> V_660 = V_655 -> V_661 ;
break;
}
case V_186 : {
struct V_662 V_663 , * V_664 ;
if ( F_277 ( V_647 -> V_656 ) & V_657 )
break;
V_643 += V_644 ;
V_664 = F_276 ( V_641 , V_643 , sizeof( V_663 ) , & V_663 ) ;
if ( V_664 == NULL )
break;
V_280 -> V_285 . V_649 -> V_658 = V_664 -> V_659 ;
V_280 -> V_285 . V_649 -> V_660 = V_664 -> V_661 ;
break;
}
case V_665 : {
struct V_666 V_667 , * V_668 ;
if ( F_277 ( V_647 -> V_656 ) & V_657 )
break;
V_643 += V_644 ;
V_668 = F_276 ( V_641 , V_643 , sizeof( V_667 ) , & V_667 ) ;
if ( V_668 == NULL )
break;
V_280 -> V_285 . V_649 -> V_658 = V_668 -> V_669 ;
V_280 -> V_285 . V_649 -> V_660 = V_668 -> V_670 ;
break;
}
default:
break;
}
V_74:
return V_618 ;
}
static int F_278 ( struct V_640 * V_641 ,
struct V_279 * V_280 , T_13 * V_642 )
{
T_13 V_671 ;
int V_618 = - V_90 , V_643 ;
struct V_672 V_673 , * V_674 ;
T_14 V_656 ;
V_643 = F_275 ( V_641 ) ;
V_674 = F_276 ( V_641 , V_643 , sizeof( V_673 ) , & V_673 ) ;
if ( V_674 == NULL )
goto V_74;
V_280 -> V_285 . V_649 -> V_675 . V_651 = V_674 -> V_651 ;
V_280 -> V_285 . V_649 -> V_675 . V_652 = V_674 -> V_652 ;
V_618 = 0 ;
V_671 = V_674 -> V_671 ;
V_643 += sizeof( V_673 ) ;
V_643 = F_279 ( V_641 , V_643 , & V_671 , & V_656 ) ;
if ( V_643 < 0 )
goto V_74;
if ( V_642 )
* V_642 = V_671 ;
switch ( V_671 ) {
case V_185 : {
struct V_653 V_654 , * V_655 ;
V_655 = F_276 ( V_641 , V_643 , sizeof( V_654 ) , & V_654 ) ;
if ( V_655 == NULL )
break;
V_280 -> V_285 . V_649 -> V_658 = V_655 -> V_659 ;
V_280 -> V_285 . V_649 -> V_660 = V_655 -> V_661 ;
break;
}
case V_186 : {
struct V_662 V_663 , * V_664 ;
V_664 = F_276 ( V_641 , V_643 , sizeof( V_663 ) , & V_663 ) ;
if ( V_664 == NULL )
break;
V_280 -> V_285 . V_649 -> V_658 = V_664 -> V_659 ;
V_280 -> V_285 . V_649 -> V_660 = V_664 -> V_661 ;
break;
}
case V_665 : {
struct V_666 V_667 , * V_668 ;
V_668 = F_276 ( V_641 , V_643 , sizeof( V_667 ) , & V_667 ) ;
if ( V_668 == NULL )
break;
V_280 -> V_285 . V_649 -> V_658 = V_668 -> V_669 ;
V_280 -> V_285 . V_649 -> V_660 = V_668 -> V_670 ;
break;
}
default:
break;
}
V_74:
return V_618 ;
}
static int F_280 ( struct V_640 * V_641 , struct V_279 * V_280 ,
char * * V_676 , int V_677 , T_13 * V_642 )
{
char * V_678 ;
int V_618 ;
switch ( V_280 -> V_285 . V_649 -> V_187 ) {
case V_194 :
V_618 = F_274 ( V_641 , V_280 , V_642 ) ;
if ( V_618 )
goto V_679;
V_678 = ( char * ) ( V_677 ? & V_280 -> V_285 . V_649 -> V_650 . V_651 :
& V_280 -> V_285 . V_649 -> V_650 . V_652 ) ;
goto V_680;
#if F_281 ( V_681 ) || F_281 ( V_682 )
case V_195 :
V_618 = F_278 ( V_641 , V_280 , V_642 ) ;
if ( V_618 )
goto V_679;
V_678 = ( char * ) ( V_677 ? & V_280 -> V_285 . V_649 -> V_675 . V_651 :
& V_280 -> V_285 . V_649 -> V_675 . V_652 ) ;
goto V_680;
#endif
default:
V_678 = NULL ;
goto V_680;
}
V_679:
F_51 ( V_71
L_46
L_47 ) ;
return V_618 ;
V_680:
if ( V_676 )
* V_676 = V_678 ;
return 0 ;
}
static int F_282 ( struct V_640 * V_641 , T_4 V_187 , T_2 * V_17 )
{
int V_592 ;
T_2 V_683 ;
T_2 V_684 ;
T_2 V_685 ;
V_592 = F_283 ( V_641 , & V_683 ) ;
if ( F_116 ( V_592 ) )
return - V_415 ;
V_592 = F_284 ( V_641 , V_187 , & V_685 , & V_684 ) ;
if ( F_116 ( V_592 ) )
return - V_415 ;
V_592 = F_285 ( V_684 , V_685 , V_683 , V_17 ) ;
if ( F_116 ( V_592 ) ) {
F_51 ( V_71
L_48
L_49 ) ;
return - V_415 ;
}
return 0 ;
}
static int F_286 ( T_2 V_686 , T_2 V_687 , T_2 * V_688 )
{
int V_592 = 0 ;
if ( V_687 != V_689 )
V_592 = F_287 ( V_686 , V_687 , V_688 ) ;
else
* V_688 = V_686 ;
return V_592 ;
}
static int F_288 ( const struct V_13 * V_14 ,
T_4 V_690 , T_2 * V_691 )
{
if ( V_14 -> V_418 > V_689 ) {
* V_691 = V_14 -> V_418 ;
return 0 ;
}
return F_102 ( V_14 -> V_17 , V_14 -> V_17 , V_690 , NULL ,
V_691 ) ;
}
static int F_289 ( struct V_20 * V_21 , struct V_692 * V_693 , T_2 V_266 )
{
struct V_694 * V_695 = V_693 -> V_696 ;
struct V_279 V_280 ;
struct V_697 V_649 = { 0 ,} ;
T_2 V_268 = F_18 ( V_21 ) ;
if ( V_695 -> V_17 == V_18 )
return 0 ;
V_280 . type = V_698 ;
V_280 . V_285 . V_649 = & V_649 ;
V_280 . V_285 . V_649 -> V_693 = V_693 ;
return F_46 ( V_268 , V_695 -> V_17 , V_695 -> V_31 , V_266 , & V_280 ) ;
}
static int F_290 ( int V_187 , int type ,
int V_183 , int V_699 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_299 ;
T_4 V_690 ;
int V_53 ;
if ( V_699 )
return 0 ;
V_690 = F_86 ( V_187 , type , V_183 ) ;
V_53 = F_288 ( V_14 , V_690 , & V_299 ) ;
if ( V_53 )
return V_53 ;
return F_46 ( V_14 -> V_17 , V_299 , V_690 , V_700 , NULL ) ;
}
static int F_291 ( struct V_701 * V_692 , int V_187 ,
int type , int V_183 , int V_699 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_24 = F_292 ( V_692 ) -> V_33 ;
struct V_694 * V_695 ;
int V_592 = 0 ;
V_24 -> V_31 = F_86 ( V_187 , type , V_183 ) ;
if ( V_699 )
V_24 -> V_17 = V_18 ;
else {
V_592 = F_288 ( V_14 , V_24 -> V_31 , & ( V_24 -> V_17 ) ) ;
if ( V_592 )
return V_592 ;
}
V_24 -> V_124 = 1 ;
if ( V_692 -> V_693 ) {
V_695 = V_692 -> V_693 -> V_696 ;
V_695 -> V_17 = V_24 -> V_17 ;
V_695 -> V_31 = V_24 -> V_31 ;
V_592 = F_293 ( V_692 -> V_693 , V_187 ) ;
}
return V_592 ;
}
static int F_294 ( struct V_701 * V_692 , struct V_702 * V_703 , int V_704 )
{
struct V_692 * V_693 = V_692 -> V_693 ;
T_4 V_187 ;
int V_592 ;
V_592 = F_289 ( V_11 , V_693 , V_705 ) ;
if ( V_592 )
goto V_74;
V_187 = V_693 -> V_706 ;
if ( V_187 == V_194 || V_187 == V_195 ) {
char * V_678 ;
struct V_694 * V_695 = V_693 -> V_696 ;
struct V_279 V_280 ;
struct V_697 V_649 = { 0 ,} ;
struct V_707 * V_708 = NULL ;
struct V_709 * V_710 = NULL ;
unsigned short V_711 ;
T_2 V_17 , V_712 ;
if ( V_187 == V_194 ) {
V_708 = (struct V_707 * ) V_703 ;
V_711 = F_277 ( V_708 -> V_713 ) ;
V_678 = ( char * ) & V_708 -> V_714 . V_715 ;
} else {
V_710 = (struct V_709 * ) V_703 ;
V_711 = F_277 ( V_710 -> V_716 ) ;
V_678 = ( char * ) & V_710 -> V_717 . V_718 ;
}
if ( V_711 ) {
int V_719 , V_720 ;
F_295 ( F_296 ( V_693 ) , & V_719 , & V_720 ) ;
if ( V_711 < V_721 ( V_722, V_719 ) || V_711 > V_720 ) {
V_592 = F_297 ( V_693 -> V_723 ,
V_711 , & V_17 ) ;
if ( V_592 )
goto V_74;
V_280 . type = V_698 ;
V_280 . V_285 . V_649 = & V_649 ;
V_280 . V_285 . V_649 -> V_658 = F_298 ( V_711 ) ;
V_280 . V_285 . V_649 -> V_187 = V_187 ;
V_592 = F_46 ( V_695 -> V_17 , V_17 ,
V_695 -> V_31 ,
V_724 , & V_280 ) ;
if ( V_592 )
goto V_74;
}
}
switch ( V_695 -> V_31 ) {
case V_196 :
V_712 = V_725 ;
break;
case V_198 :
V_712 = V_726 ;
break;
case V_200 :
V_712 = V_727 ;
break;
default:
V_712 = V_728 ;
break;
}
V_592 = F_299 ( V_678 , V_187 , & V_17 ) ;
if ( V_592 )
goto V_74;
V_280 . type = V_698 ;
V_280 . V_285 . V_649 = & V_649 ;
V_280 . V_285 . V_649 -> V_658 = F_298 ( V_711 ) ;
V_280 . V_285 . V_649 -> V_187 = V_187 ;
if ( V_187 == V_194 )
V_280 . V_285 . V_649 -> V_650 . V_651 = V_708 -> V_714 . V_715 ;
else
V_280 . V_285 . V_649 -> V_675 . V_651 = V_710 -> V_717 ;
V_592 = F_46 ( V_695 -> V_17 , V_17 ,
V_695 -> V_31 , V_712 , & V_280 ) ;
if ( V_592 )
goto V_74;
}
V_74:
return V_592 ;
}
static int F_300 ( struct V_701 * V_692 , struct V_702 * V_703 , int V_704 )
{
struct V_692 * V_693 = V_692 -> V_693 ;
struct V_694 * V_695 = V_693 -> V_696 ;
int V_592 ;
V_592 = F_289 ( V_11 , V_693 , V_729 ) ;
if ( V_592 )
return V_592 ;
if ( V_695 -> V_31 == V_196 ||
V_695 -> V_31 == V_200 ) {
struct V_279 V_280 ;
struct V_697 V_649 = { 0 ,} ;
struct V_707 * V_708 = NULL ;
struct V_709 * V_710 = NULL ;
unsigned short V_711 ;
T_2 V_17 , V_256 ;
if ( V_693 -> V_706 == V_194 ) {
V_708 = (struct V_707 * ) V_703 ;
if ( V_704 < sizeof( struct V_707 ) )
return - V_90 ;
V_711 = F_277 ( V_708 -> V_713 ) ;
} else {
V_710 = (struct V_709 * ) V_703 ;
if ( V_704 < V_730 )
return - V_90 ;
V_711 = F_277 ( V_710 -> V_716 ) ;
}
V_592 = F_297 ( V_693 -> V_723 , V_711 , & V_17 ) ;
if ( V_592 )
goto V_74;
V_256 = ( V_695 -> V_31 == V_196 ) ?
V_731 : V_732 ;
V_280 . type = V_698 ;
V_280 . V_285 . V_649 = & V_649 ;
V_280 . V_285 . V_649 -> V_660 = F_298 ( V_711 ) ;
V_280 . V_285 . V_649 -> V_187 = V_693 -> V_706 ;
V_592 = F_46 ( V_695 -> V_17 , V_17 , V_695 -> V_31 , V_256 , & V_280 ) ;
if ( V_592 )
goto V_74;
}
V_592 = F_301 ( V_693 , V_703 ) ;
V_74:
return V_592 ;
}
static int F_302 ( struct V_701 * V_692 , int V_733 )
{
return F_289 ( V_11 , V_692 -> V_693 , V_734 ) ;
}
static int F_303 ( struct V_701 * V_692 , struct V_701 * V_735 )
{
int V_592 ;
struct V_23 * V_24 ;
struct V_23 * V_141 ;
V_592 = F_289 ( V_11 , V_692 -> V_693 , V_736 ) ;
if ( V_592 )
return V_592 ;
V_141 = F_292 ( V_735 ) -> V_33 ;
V_24 = F_292 ( V_692 ) -> V_33 ;
V_141 -> V_31 = V_24 -> V_31 ;
V_141 -> V_17 = V_24 -> V_17 ;
V_141 -> V_124 = 1 ;
return 0 ;
}
static int F_304 ( struct V_701 * V_692 , struct V_737 * V_738 ,
int V_531 )
{
return F_289 ( V_11 , V_692 -> V_693 , V_739 ) ;
}
static int F_305 ( struct V_701 * V_692 , struct V_737 * V_738 ,
int V_531 , int V_79 )
{
return F_289 ( V_11 , V_692 -> V_693 , V_740 ) ;
}
static int F_306 ( struct V_701 * V_692 )
{
return F_289 ( V_11 , V_692 -> V_693 , V_741 ) ;
}
static int F_307 ( struct V_701 * V_692 )
{
return F_289 ( V_11 , V_692 -> V_693 , V_741 ) ;
}
static int F_308 ( struct V_701 * V_692 , int V_742 , int V_743 )
{
int V_592 ;
V_592 = F_289 ( V_11 , V_692 -> V_693 , V_744 ) ;
if ( V_592 )
return V_592 ;
return F_309 ( V_692 , V_742 , V_743 ) ;
}
static int F_310 ( struct V_701 * V_692 , int V_742 ,
int V_743 )
{
return F_289 ( V_11 , V_692 -> V_693 , V_745 ) ;
}
static int F_311 ( struct V_701 * V_692 , int V_746 )
{
return F_289 ( V_11 , V_692 -> V_693 , V_747 ) ;
}
static int F_312 ( struct V_692 * V_692 ,
struct V_692 * V_748 ,
struct V_692 * V_749 )
{
struct V_694 * V_750 = V_692 -> V_696 ;
struct V_694 * V_751 = V_748 -> V_696 ;
struct V_694 * V_752 = V_749 -> V_696 ;
struct V_279 V_280 ;
struct V_697 V_649 = { 0 ,} ;
int V_592 ;
V_280 . type = V_698 ;
V_280 . V_285 . V_649 = & V_649 ;
V_280 . V_285 . V_649 -> V_693 = V_748 ;
V_592 = F_46 ( V_750 -> V_17 , V_751 -> V_17 ,
V_751 -> V_31 ,
V_753 , & V_280 ) ;
if ( V_592 )
return V_592 ;
V_752 -> V_754 = V_750 -> V_17 ;
V_592 = F_287 ( V_751 -> V_17 , V_750 -> V_17 ,
& V_752 -> V_17 ) ;
if ( V_592 )
return V_592 ;
V_750 -> V_754 = V_752 -> V_17 ;
return 0 ;
}
static int F_313 ( struct V_701 * V_692 ,
struct V_701 * V_748 )
{
struct V_694 * V_755 = V_692 -> V_693 -> V_696 ;
struct V_694 * V_756 = V_748 -> V_693 -> V_696 ;
struct V_279 V_280 ;
struct V_697 V_649 = { 0 ,} ;
V_280 . type = V_698 ;
V_280 . V_285 . V_649 = & V_649 ;
V_280 . V_285 . V_649 -> V_693 = V_748 -> V_693 ;
return F_46 ( V_755 -> V_17 , V_756 -> V_17 , V_756 -> V_31 , V_757 ,
& V_280 ) ;
}
static int F_314 ( struct V_649 * V_371 , int V_758 ,
char * V_678 , T_4 V_187 , T_2 V_754 ,
struct V_279 * V_280 )
{
int V_592 ;
T_2 V_759 ;
T_2 V_760 ;
V_592 = F_315 ( V_371 , V_758 , & V_759 ) ;
if ( V_592 )
return V_592 ;
V_592 = F_46 ( V_754 , V_759 ,
V_761 , V_762 , V_280 ) ;
if ( V_592 )
return V_592 ;
V_592 = F_299 ( V_678 , V_187 , & V_760 ) ;
if ( V_592 )
return V_592 ;
return F_46 ( V_754 , V_760 ,
V_763 , V_764 , V_280 ) ;
}
static int F_316 ( struct V_692 * V_693 , struct V_640 * V_641 ,
T_4 V_187 )
{
int V_592 = 0 ;
struct V_694 * V_695 = V_693 -> V_696 ;
T_2 V_686 = V_695 -> V_17 ;
struct V_279 V_280 ;
struct V_697 V_649 = { 0 ,} ;
char * V_678 ;
V_280 . type = V_698 ;
V_280 . V_285 . V_649 = & V_649 ;
V_280 . V_285 . V_649 -> V_765 = V_641 -> V_766 ;
V_280 . V_285 . V_649 -> V_187 = V_187 ;
V_592 = F_280 ( V_641 , & V_280 , & V_678 , 1 , NULL ) ;
if ( V_592 )
return V_592 ;
if ( F_4 () ) {
V_592 = F_46 ( V_686 , V_641 -> V_767 , V_768 ,
V_769 , & V_280 ) ;
if ( V_592 )
return V_592 ;
}
V_592 = F_317 ( V_695 , V_641 , V_187 , & V_280 ) ;
if ( V_592 )
return V_592 ;
V_592 = F_318 ( V_695 -> V_17 , V_641 , & V_280 ) ;
return V_592 ;
}
static int F_319 ( struct V_692 * V_693 , struct V_640 * V_641 )
{
int V_592 ;
struct V_694 * V_695 = V_693 -> V_696 ;
T_4 V_187 = V_693 -> V_706 ;
T_2 V_686 = V_695 -> V_17 ;
struct V_279 V_280 ;
struct V_697 V_649 = { 0 ,} ;
char * V_678 ;
T_13 V_770 ;
T_13 V_771 ;
if ( V_187 != V_194 && V_187 != V_195 )
return 0 ;
if ( V_187 == V_195 && V_641 -> V_183 == F_298 ( V_772 ) )
V_187 = V_194 ;
if ( ! V_773 )
return F_316 ( V_693 , V_641 , V_187 ) ;
V_770 = F_4 () ;
V_771 = F_6 () ;
if ( ! V_770 && ! V_771 )
return 0 ;
V_280 . type = V_698 ;
V_280 . V_285 . V_649 = & V_649 ;
V_280 . V_285 . V_649 -> V_765 = V_641 -> V_766 ;
V_280 . V_285 . V_649 -> V_187 = V_187 ;
V_592 = F_280 ( V_641 , & V_280 , & V_678 , 1 , NULL ) ;
if ( V_592 )
return V_592 ;
if ( V_771 ) {
T_2 V_754 ;
V_592 = F_282 ( V_641 , V_187 , & V_754 ) ;
if ( V_592 )
return V_592 ;
V_592 = F_314 ( F_296 ( V_693 ) , V_641 -> V_766 ,
V_678 , V_187 , V_754 , & V_280 ) ;
if ( V_592 ) {
F_320 ( V_641 , V_592 , 0 ) ;
return V_592 ;
}
V_592 = F_46 ( V_686 , V_754 , V_774 ,
V_775 , & V_280 ) ;
if ( V_592 ) {
F_320 ( V_641 , V_592 , 0 ) ;
return V_592 ;
}
}
if ( V_770 ) {
V_592 = F_46 ( V_686 , V_641 -> V_767 , V_768 ,
V_769 , & V_280 ) ;
if ( V_592 )
return V_592 ;
}
return V_592 ;
}
static int F_321 ( struct V_701 * V_692 , char T_15 * V_776 ,
int T_15 * V_777 , unsigned V_88 )
{
int V_592 = 0 ;
char * V_778 ;
T_2 V_779 ;
struct V_694 * V_695 = V_692 -> V_693 -> V_696 ;
T_2 V_754 = V_689 ;
if ( V_695 -> V_31 == V_191 ||
V_695 -> V_31 == V_196 )
V_754 = V_695 -> V_754 ;
if ( V_754 == V_689 )
return - V_780 ;
V_592 = F_61 ( V_754 , & V_778 , & V_779 ) ;
if ( V_592 )
return V_592 ;
if ( V_779 > V_88 ) {
V_592 = - V_249 ;
goto V_781;
}
if ( F_322 ( V_776 , V_778 , V_779 ) )
V_592 = - V_782 ;
V_781:
if ( F_323 ( V_779 , V_777 ) )
V_592 = - V_782 ;
F_39 ( V_778 ) ;
return V_592 ;
}
static int F_324 ( struct V_701 * V_692 , struct V_640 * V_641 , T_2 * V_544 )
{
T_2 V_783 = V_689 ;
T_4 V_187 ;
if ( V_641 && V_641 -> V_183 == F_298 ( V_772 ) )
V_187 = V_194 ;
else if ( V_641 && V_641 -> V_183 == F_298 ( V_784 ) )
V_187 = V_195 ;
else if ( V_692 )
V_187 = V_692 -> V_693 -> V_706 ;
else
goto V_74;
if ( V_692 && V_187 == V_188 )
F_234 ( F_292 ( V_692 ) , & V_783 ) ;
else if ( V_641 )
F_282 ( V_641 , V_187 , & V_783 ) ;
V_74:
* V_544 = V_783 ;
if ( V_783 == V_689 )
return - V_90 ;
return 0 ;
}
static int F_325 ( struct V_692 * V_693 , int V_187 , T_11 V_785 )
{
struct V_694 * V_695 ;
V_695 = F_15 ( sizeof( * V_695 ) , V_785 ) ;
if ( ! V_695 )
return - V_27 ;
V_695 -> V_754 = V_30 ;
V_695 -> V_17 = V_30 ;
F_326 ( V_695 ) ;
V_693 -> V_696 = V_695 ;
return 0 ;
}
static void F_327 ( struct V_692 * V_693 )
{
struct V_694 * V_695 = V_693 -> V_696 ;
V_693 -> V_696 = NULL ;
F_328 ( V_695 ) ;
F_39 ( V_695 ) ;
}
static void F_329 ( const struct V_692 * V_693 , struct V_692 * V_749 )
{
struct V_694 * V_695 = V_693 -> V_696 ;
struct V_694 * V_786 = V_749 -> V_696 ;
V_786 -> V_17 = V_695 -> V_17 ;
V_786 -> V_754 = V_695 -> V_754 ;
V_786 -> V_31 = V_695 -> V_31 ;
F_326 ( V_786 ) ;
}
static void F_330 ( struct V_692 * V_693 , T_2 * V_544 )
{
if ( ! V_693 )
* V_544 = V_787 ;
else {
struct V_694 * V_695 = V_693 -> V_696 ;
* V_544 = V_695 -> V_17 ;
}
}
static void F_331 ( struct V_692 * V_693 , struct V_701 * V_364 )
{
struct V_23 * V_24 = F_292 ( V_364 ) -> V_33 ;
struct V_694 * V_695 = V_693 -> V_696 ;
if ( V_693 -> V_706 == V_194 || V_693 -> V_706 == V_195 ||
V_693 -> V_706 == V_188 )
V_24 -> V_17 = V_695 -> V_17 ;
V_695 -> V_31 = V_24 -> V_31 ;
}
static int F_332 ( struct V_692 * V_693 , struct V_640 * V_641 ,
struct V_788 * V_789 )
{
struct V_694 * V_695 = V_693 -> V_696 ;
int V_592 ;
T_4 V_187 = V_789 -> V_790 -> V_187 ;
T_2 V_791 ;
T_2 V_792 ;
V_592 = F_282 ( V_641 , V_187 , & V_792 ) ;
if ( V_592 )
return V_592 ;
V_592 = F_286 ( V_695 -> V_17 , V_792 , & V_791 ) ;
if ( V_592 )
return V_592 ;
V_789 -> V_544 = V_791 ;
V_789 -> V_783 = V_792 ;
return F_333 ( V_789 , V_187 ) ;
}
static void F_334 ( struct V_692 * V_749 ,
const struct V_788 * V_789 )
{
struct V_694 * V_786 = V_749 -> V_696 ;
V_786 -> V_17 = V_789 -> V_544 ;
V_786 -> V_754 = V_789 -> V_783 ;
F_335 ( V_749 , V_789 -> V_790 -> V_187 ) ;
}
static void F_336 ( struct V_692 * V_693 , struct V_640 * V_641 )
{
T_4 V_187 = V_693 -> V_706 ;
struct V_694 * V_695 = V_693 -> V_696 ;
if ( V_187 == V_195 && V_641 -> V_183 == F_298 ( V_772 ) )
V_187 = V_194 ;
F_282 ( V_641 , V_187 , & V_695 -> V_754 ) ;
}
static int F_337 ( T_2 V_17 )
{
const struct V_13 * V_793 ;
T_2 V_268 ;
V_793 = F_23 () ;
V_268 = V_793 -> V_17 ;
return F_46 ( V_268 , V_17 , V_768 , V_794 , NULL ) ;
}
static void F_338 ( void )
{
F_339 ( & V_7 ) ;
}
static void F_340 ( void )
{
F_341 ( & V_7 ) ;
}
static void F_342 ( const struct V_788 * V_789 ,
struct V_795 * V_796 )
{
V_796 -> V_797 = V_789 -> V_544 ;
}
static int F_343 ( void * * V_19 )
{
struct V_798 * V_799 ;
V_799 = F_15 ( sizeof( * V_799 ) , V_15 ) ;
if ( ! V_799 )
return - V_27 ;
V_799 -> V_17 = F_22 () ;
* V_19 = V_799 ;
return 0 ;
}
static void F_344 ( void * V_19 )
{
F_39 ( V_19 ) ;
}
static int F_345 ( void )
{
T_2 V_17 = F_22 () ;
return F_46 ( V_17 , V_17 , V_800 , V_801 ,
NULL ) ;
}
static int F_346 ( void * V_19 )
{
struct V_798 * V_799 = V_19 ;
return F_46 ( F_22 () , V_799 -> V_17 , V_800 ,
V_802 , NULL ) ;
}
static int F_347 ( struct V_692 * V_693 , void * V_19 )
{
struct V_798 * V_799 = V_19 ;
struct V_694 * V_695 = V_693 -> V_696 ;
V_695 -> V_17 = V_799 -> V_17 ;
V_695 -> V_31 = V_800 ;
return 0 ;
}
static int F_348 ( void * V_19 )
{
struct V_798 * V_799 = V_19 ;
T_2 V_17 = F_22 () ;
int V_592 ;
V_592 = F_46 ( V_17 , V_799 -> V_17 , V_800 ,
V_803 , NULL ) ;
if ( V_592 )
return V_592 ;
V_592 = F_46 ( V_17 , V_17 , V_800 ,
V_804 , NULL ) ;
if ( V_592 )
return V_592 ;
V_799 -> V_17 = V_17 ;
return 0 ;
}
static int F_349 ( struct V_692 * V_693 , struct V_640 * V_641 )
{
int V_592 = 0 ;
T_2 V_256 ;
struct V_805 * V_806 ;
struct V_694 * V_695 = V_693 -> V_696 ;
if ( V_641 -> V_88 < V_807 ) {
V_592 = - V_90 ;
goto V_74;
}
V_806 = F_350 ( V_641 ) ;
V_592 = F_351 ( V_695 -> V_31 , V_806 -> V_808 , & V_256 ) ;
if ( V_592 ) {
if ( V_592 == - V_90 ) {
F_51 ( V_71
L_50
L_51 ,
V_693 -> V_723 , V_806 -> V_808 ,
V_809 [ V_695 -> V_31 - 1 ] . V_64 ) ;
if ( ! V_3 || F_352 () )
V_592 = 0 ;
}
if ( V_592 == - V_810 )
V_592 = 0 ;
goto V_74;
}
V_592 = F_289 ( V_11 , V_693 , V_256 ) ;
V_74:
return V_592 ;
}
static unsigned int F_353 ( struct V_640 * V_641 ,
const struct V_811 * V_812 ,
T_4 V_187 )
{
int V_592 ;
char * V_678 ;
T_2 V_754 ;
struct V_279 V_280 ;
struct V_697 V_649 = { 0 ,} ;
T_13 V_770 ;
T_13 V_813 ;
T_13 V_771 ;
if ( ! V_773 )
return V_814 ;
V_770 = F_4 () ;
V_813 = F_7 () ;
V_771 = F_6 () ;
if ( ! V_770 && ! V_771 )
return V_814 ;
if ( F_282 ( V_641 , V_187 , & V_754 ) != 0 )
return V_815 ;
V_280 . type = V_698 ;
V_280 . V_285 . V_649 = & V_649 ;
V_280 . V_285 . V_649 -> V_765 = V_812 -> V_758 ;
V_280 . V_285 . V_649 -> V_187 = V_187 ;
if ( F_280 ( V_641 , & V_280 , & V_678 , 1 , NULL ) != 0 )
return V_815 ;
if ( V_771 ) {
V_592 = F_314 ( F_354 ( V_812 ) , V_812 -> V_758 ,
V_678 , V_187 , V_754 , & V_280 ) ;
if ( V_592 ) {
F_320 ( V_641 , V_592 , 1 ) ;
return V_815 ;
}
}
if ( V_770 )
if ( F_46 ( V_754 , V_641 -> V_767 ,
V_768 , V_816 , & V_280 ) )
return V_815 ;
if ( V_813 )
if ( F_355 ( V_641 , V_187 , V_754 ) != 0 )
return V_815 ;
return V_814 ;
}
static unsigned int F_356 ( const struct V_817 * V_818 ,
struct V_640 * V_641 ,
const struct V_819 * V_820 )
{
return F_353 ( V_641 , V_820 -> V_821 , V_194 ) ;
}
static unsigned int F_357 ( const struct V_817 * V_818 ,
struct V_640 * V_641 ,
const struct V_819 * V_820 )
{
return F_353 ( V_641 , V_820 -> V_821 , V_195 ) ;
}
static unsigned int F_358 ( struct V_640 * V_641 ,
T_4 V_187 )
{
struct V_692 * V_693 ;
T_2 V_17 ;
if ( ! F_7 () )
return V_814 ;
V_693 = V_641 -> V_693 ;
if ( V_693 ) {
struct V_694 * V_695 ;
if ( V_693 -> V_822 == V_823 )
return V_814 ;
V_695 = V_693 -> V_696 ;
V_17 = V_695 -> V_17 ;
} else
V_17 = V_18 ;
if ( F_355 ( V_641 , V_187 , V_17 ) != 0 )
return V_815 ;
return V_814 ;
}
static unsigned int F_359 ( const struct V_817 * V_818 ,
struct V_640 * V_641 ,
const struct V_819 * V_820 )
{
return F_358 ( V_641 , V_194 ) ;
}
static unsigned int F_360 ( struct V_640 * V_641 ,
int V_758 ,
T_4 V_187 )
{
struct V_692 * V_693 = V_641 -> V_693 ;
struct V_694 * V_695 ;
struct V_279 V_280 ;
struct V_697 V_649 = { 0 ,} ;
char * V_678 ;
T_13 V_642 ;
if ( V_693 == NULL )
return V_814 ;
V_695 = V_693 -> V_696 ;
V_280 . type = V_698 ;
V_280 . V_285 . V_649 = & V_649 ;
V_280 . V_285 . V_649 -> V_765 = V_758 ;
V_280 . V_285 . V_649 -> V_187 = V_187 ;
if ( F_280 ( V_641 , & V_280 , & V_678 , 0 , & V_642 ) )
return V_815 ;
if ( F_4 () )
if ( F_46 ( V_695 -> V_17 , V_641 -> V_767 ,
V_768 , V_824 , & V_280 ) )
return F_361 ( - V_825 ) ;
if ( F_362 ( V_695 -> V_17 , V_641 , & V_280 , V_642 ) )
return F_361 ( - V_825 ) ;
return V_814 ;
}
static unsigned int F_363 ( struct V_640 * V_641 ,
const struct V_811 * V_826 ,
T_4 V_187 )
{
T_2 V_827 ;
T_2 V_754 ;
int V_758 = V_826 -> V_758 ;
struct V_692 * V_693 ;
struct V_279 V_280 ;
struct V_697 V_649 = { 0 ,} ;
char * V_678 ;
T_13 V_770 ;
T_13 V_771 ;
if ( ! V_773 )
return F_360 ( V_641 , V_758 , V_187 ) ;
V_770 = F_4 () ;
V_771 = F_6 () ;
if ( ! V_770 && ! V_771 )
return V_814 ;
V_693 = V_641 -> V_693 ;
#ifdef F_364
if ( F_365 ( V_641 ) != NULL && F_365 ( V_641 ) -> V_828 != NULL &&
! ( V_693 != NULL && V_693 -> V_822 == V_823 ) )
return V_814 ;
#endif
if ( V_693 == NULL ) {
if ( V_641 -> V_766 ) {
V_827 = V_829 ;
if ( F_282 ( V_641 , V_187 , & V_754 ) )
return V_815 ;
} else {
V_827 = V_824 ;
V_754 = V_18 ;
}
} else if ( V_693 -> V_822 == V_823 ) {
T_2 V_687 ;
struct V_694 * V_695 = V_693 -> V_696 ;
if ( F_282 ( V_641 , V_187 , & V_687 ) )
return V_815 ;
if ( V_687 == V_689 ) {
switch ( V_187 ) {
case V_194 :
if ( F_366 ( V_641 ) -> V_79 & V_830 )
return V_814 ;
break;
case V_195 :
if ( F_367 ( V_641 ) -> V_79 & V_831 )
return V_814 ;
break;
default:
return F_361 ( - V_825 ) ;
}
}
if ( F_286 ( V_695 -> V_17 , V_687 , & V_754 ) )
return V_815 ;
V_827 = V_824 ;
} else {
struct V_694 * V_695 = V_693 -> V_696 ;
V_754 = V_695 -> V_17 ;
V_827 = V_824 ;
}
V_280 . type = V_698 ;
V_280 . V_285 . V_649 = & V_649 ;
V_280 . V_285 . V_649 -> V_765 = V_758 ;
V_280 . V_285 . V_649 -> V_187 = V_187 ;
if ( F_280 ( V_641 , & V_280 , & V_678 , 0 , NULL ) )
return V_815 ;
if ( V_770 )
if ( F_46 ( V_754 , V_641 -> V_767 ,
V_768 , V_827 , & V_280 ) )
return F_361 ( - V_825 ) ;
if ( V_771 ) {
T_2 V_759 ;
T_2 V_760 ;
if ( F_315 ( F_354 ( V_826 ) , V_758 , & V_759 ) )
return V_815 ;
if ( F_46 ( V_754 , V_759 ,
V_761 , V_832 , & V_280 ) )
return F_361 ( - V_825 ) ;
if ( F_299 ( V_678 , V_187 , & V_760 ) )
return V_815 ;
if ( F_46 ( V_754 , V_760 ,
V_763 , V_833 , & V_280 ) )
return F_361 ( - V_825 ) ;
}
return V_814 ;
}
static unsigned int F_368 ( const struct V_817 * V_818 ,
struct V_640 * V_641 ,
const struct V_819 * V_820 )
{
return F_363 ( V_641 , V_820 -> V_74 , V_194 ) ;
}
static unsigned int F_369 ( const struct V_817 * V_818 ,
struct V_640 * V_641 ,
const struct V_819 * V_820 )
{
return F_363 ( V_641 , V_820 -> V_74 , V_195 ) ;
}
static int F_370 ( struct V_692 * V_693 , struct V_640 * V_641 )
{
return F_349 ( V_693 , V_641 ) ;
}
static int F_371 ( struct V_20 * V_21 ,
struct V_834 * V_256 ,
T_4 V_31 )
{
struct V_835 * V_24 ;
T_2 V_17 ;
V_24 = F_15 ( sizeof( struct V_835 ) , V_15 ) ;
if ( ! V_24 )
return - V_27 ;
V_17 = F_18 ( V_21 ) ;
V_24 -> V_31 = V_31 ;
V_24 -> V_17 = V_17 ;
V_256 -> V_19 = V_24 ;
return 0 ;
}
static void F_372 ( struct V_834 * V_256 )
{
struct V_835 * V_24 = V_256 -> V_19 ;
V_256 -> V_19 = NULL ;
F_39 ( V_24 ) ;
}
static int F_373 ( struct V_836 * V_738 )
{
struct V_837 * V_838 ;
V_838 = F_15 ( sizeof( struct V_837 ) , V_15 ) ;
if ( ! V_838 )
return - V_27 ;
V_838 -> V_17 = V_30 ;
V_738 -> V_19 = V_838 ;
return 0 ;
}
static void F_374 ( struct V_836 * V_738 )
{
struct V_837 * V_838 = V_738 -> V_19 ;
V_738 -> V_19 = NULL ;
F_39 ( V_838 ) ;
}
static int F_375 ( struct V_834 * V_839 ,
T_2 V_266 )
{
struct V_835 * V_24 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
V_24 = V_839 -> V_19 ;
V_280 . type = V_840 ;
V_280 . V_285 . V_841 = V_839 -> V_842 ;
return F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_266 , & V_280 ) ;
}
static int F_376 ( struct V_836 * V_738 )
{
return F_373 ( V_738 ) ;
}
static void F_377 ( struct V_836 * V_738 )
{
F_374 ( V_738 ) ;
}
static int F_378 ( struct V_843 * V_844 )
{
struct V_835 * V_24 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_53 = F_371 ( V_11 , & V_844 -> V_845 , V_846 ) ;
if ( V_53 )
return V_53 ;
V_24 = V_844 -> V_845 . V_19 ;
V_280 . type = V_840 ;
V_280 . V_285 . V_841 = V_844 -> V_845 . V_842 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_846 ,
V_847 , & V_280 ) ;
if ( V_53 ) {
F_372 ( & V_844 -> V_845 ) ;
return V_53 ;
}
return 0 ;
}
static void F_379 ( struct V_843 * V_844 )
{
F_372 ( & V_844 -> V_845 ) ;
}
static int F_380 ( struct V_843 * V_844 , int V_848 )
{
struct V_835 * V_24 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
V_24 = V_844 -> V_845 . V_19 ;
V_280 . type = V_840 ;
V_280 . V_285 . V_841 = V_844 -> V_845 . V_842 ;
return F_46 ( V_17 , V_24 -> V_17 , V_846 ,
V_849 , & V_280 ) ;
}
static int F_381 ( struct V_843 * V_844 , int V_547 )
{
int V_592 ;
int V_266 ;
switch ( V_547 ) {
case V_850 :
case V_851 :
return F_113 ( V_11 , V_852 ) ;
case V_853 :
case V_854 :
V_266 = V_855 | V_849 ;
break;
case V_856 :
V_266 = V_857 ;
break;
case V_858 :
V_266 = V_859 ;
break;
default:
return 0 ;
}
V_592 = F_375 ( & V_844 -> V_845 , V_266 ) ;
return V_592 ;
}
static int F_382 ( struct V_843 * V_844 , struct V_836 * V_738 , int V_848 )
{
struct V_835 * V_24 ;
struct V_837 * V_838 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_24 = V_844 -> V_845 . V_19 ;
V_838 = V_738 -> V_19 ;
if ( V_838 -> V_17 == V_30 ) {
V_53 = F_102 ( V_17 , V_24 -> V_17 , V_860 ,
NULL , & V_838 -> V_17 ) ;
if ( V_53 )
return V_53 ;
}
V_280 . type = V_840 ;
V_280 . V_285 . V_841 = V_844 -> V_845 . V_842 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_846 ,
V_861 , & V_280 ) ;
if ( ! V_53 )
V_53 = F_46 ( V_17 , V_838 -> V_17 , V_860 ,
V_862 , & V_280 ) ;
if ( ! V_53 )
V_53 = F_46 ( V_838 -> V_17 , V_24 -> V_17 , V_846 ,
V_863 , & V_280 ) ;
return V_53 ;
}
static int F_383 ( struct V_843 * V_844 , struct V_836 * V_738 ,
struct V_20 * V_265 ,
long type , int V_168 )
{
struct V_835 * V_24 ;
struct V_837 * V_838 ;
struct V_279 V_280 ;
T_2 V_17 = F_18 ( V_265 ) ;
int V_53 ;
V_24 = V_844 -> V_845 . V_19 ;
V_838 = V_738 -> V_19 ;
V_280 . type = V_840 ;
V_280 . V_285 . V_841 = V_844 -> V_845 . V_842 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 ,
V_846 , V_864 , & V_280 ) ;
if ( ! V_53 )
V_53 = F_46 ( V_17 , V_838 -> V_17 ,
V_860 , V_865 , & V_280 ) ;
return V_53 ;
}
static int F_384 ( struct V_866 * V_867 )
{
struct V_835 * V_24 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_53 = F_371 ( V_11 , & V_867 -> V_868 , V_869 ) ;
if ( V_53 )
return V_53 ;
V_24 = V_867 -> V_868 . V_19 ;
V_280 . type = V_840 ;
V_280 . V_285 . V_841 = V_867 -> V_868 . V_842 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_869 ,
V_870 , & V_280 ) ;
if ( V_53 ) {
F_372 ( & V_867 -> V_868 ) ;
return V_53 ;
}
return 0 ;
}
static void F_385 ( struct V_866 * V_867 )
{
F_372 ( & V_867 -> V_868 ) ;
}
static int F_386 ( struct V_866 * V_867 , int V_871 )
{
struct V_835 * V_24 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
V_24 = V_867 -> V_868 . V_19 ;
V_280 . type = V_840 ;
V_280 . V_285 . V_841 = V_867 -> V_868 . V_842 ;
return F_46 ( V_17 , V_24 -> V_17 , V_869 ,
V_872 , & V_280 ) ;
}
static int F_387 ( struct V_866 * V_867 , int V_547 )
{
int V_266 ;
int V_592 ;
switch ( V_547 ) {
case V_850 :
case V_873 :
return F_113 ( V_11 , V_852 ) ;
case V_853 :
case V_874 :
V_266 = V_875 | V_872 ;
break;
case V_856 :
V_266 = V_876 ;
break;
case V_877 :
case V_878 :
V_266 = V_879 ;
break;
case V_858 :
V_266 = V_880 ;
break;
default:
return 0 ;
}
V_592 = F_375 ( & V_867 -> V_868 , V_266 ) ;
return V_592 ;
}
static int F_388 ( struct V_866 * V_867 ,
char T_15 * V_881 , int V_871 )
{
T_2 V_266 ;
if ( V_871 & V_882 )
V_266 = V_883 ;
else
V_266 = V_883 | V_884 ;
return F_375 ( & V_867 -> V_868 , V_266 ) ;
}
static int F_389 ( struct V_885 * V_886 )
{
struct V_835 * V_24 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_53 = F_371 ( V_11 , & V_886 -> V_887 , V_888 ) ;
if ( V_53 )
return V_53 ;
V_24 = V_886 -> V_887 . V_19 ;
V_280 . type = V_840 ;
V_280 . V_285 . V_841 = V_886 -> V_887 . V_842 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_888 ,
V_889 , & V_280 ) ;
if ( V_53 ) {
F_372 ( & V_886 -> V_887 ) ;
return V_53 ;
}
return 0 ;
}
static void F_390 ( struct V_885 * V_886 )
{
F_372 ( & V_886 -> V_887 ) ;
}
static int F_391 ( struct V_885 * V_886 , int V_890 )
{
struct V_835 * V_24 ;
struct V_279 V_280 ;
T_2 V_17 = F_22 () ;
V_24 = V_886 -> V_887 . V_19 ;
V_280 . type = V_840 ;
V_280 . V_285 . V_841 = V_886 -> V_887 . V_842 ;
return F_46 ( V_17 , V_24 -> V_17 , V_888 ,
V_891 , & V_280 ) ;
}
static int F_392 ( struct V_885 * V_886 , int V_547 )
{
int V_592 ;
T_2 V_266 ;
switch ( V_547 ) {
case V_850 :
case V_892 :
return F_113 ( V_11 , V_852 ) ;
case V_893 :
case V_894 :
case V_895 :
V_266 = V_896 ;
break;
case V_897 :
case V_898 :
V_266 = V_899 ;
break;
case V_900 :
case V_901 :
V_266 = V_902 ;
break;
case V_858 :
V_266 = V_903 ;
break;
case V_856 :
V_266 = V_904 ;
break;
case V_853 :
case V_905 :
V_266 = V_896 | V_891 ;
break;
default:
return 0 ;
}
V_592 = F_375 ( & V_886 -> V_887 , V_266 ) ;
return V_592 ;
}
static int F_393 ( struct V_885 * V_886 ,
struct V_906 * V_907 , unsigned V_908 , int V_909 )
{
T_2 V_266 ;
if ( V_909 )
V_266 = V_899 | V_902 ;
else
V_266 = V_899 ;
return F_375 ( & V_886 -> V_887 , V_266 ) ;
}
static int F_394 ( struct V_834 * V_910 , short V_103 )
{
T_2 V_283 = 0 ;
V_283 = 0 ;
if ( V_103 & V_911 )
V_283 |= V_912 ;
if ( V_103 & V_913 )
V_283 |= V_914 ;
if ( V_283 == 0 )
return 0 ;
return F_375 ( V_910 , V_283 ) ;
}
static void F_395 ( struct V_834 * V_910 , T_2 * V_544 )
{
struct V_835 * V_24 = V_910 -> V_19 ;
* V_544 = V_24 -> V_17 ;
}
static void F_396 ( struct V_65 * V_65 , struct V_22 * V_22 )
{
if ( V_22 )
F_44 ( V_22 , V_65 ) ;
}
static int F_397 ( struct V_20 * V_145 ,
char * V_64 , char * * V_501 )
{
const struct V_13 * V_793 ;
T_2 V_17 ;
int error ;
unsigned V_88 ;
if ( V_11 != V_145 ) {
error = F_107 ( V_145 , V_915 ) ;
if ( error )
return error ;
}
F_19 () ;
V_793 = F_20 ( V_145 ) -> V_19 ;
if ( ! strcmp ( V_64 , L_52 ) )
V_17 = V_793 -> V_17 ;
else if ( ! strcmp ( V_64 , L_53 ) )
V_17 = V_793 -> V_16 ;
else if ( ! strcmp ( V_64 , L_54 ) )
V_17 = V_793 -> V_419 ;
else if ( ! strcmp ( V_64 , L_55 ) )
V_17 = V_793 -> V_300 ;
else if ( ! strcmp ( V_64 , L_56 ) )
V_17 = V_793 -> V_417 ;
else if ( ! strcmp ( V_64 , L_57 ) )
V_17 = V_793 -> V_418 ;
else
goto V_916;
F_21 () ;
if ( ! V_17 )
return 0 ;
error = F_61 ( V_17 , V_501 , & V_88 ) ;
if ( error )
return error ;
return V_88 ;
V_916:
F_21 () ;
return - V_90 ;
}
static int F_398 ( struct V_20 * V_145 ,
char * V_64 , void * V_501 , T_7 V_531 )
{
struct V_13 * V_14 ;
struct V_20 * V_427 ;
struct V_10 * V_128 ;
T_2 V_17 = 0 , V_429 ;
int error ;
char * V_1 = V_501 ;
if ( V_11 != V_145 ) {
return - V_415 ;
}
if ( ! strcmp ( V_64 , L_54 ) )
error = F_107 ( V_145 , V_917 ) ;
else if ( ! strcmp ( V_64 , L_55 ) )
error = F_107 ( V_145 , V_918 ) ;
else if ( ! strcmp ( V_64 , L_56 ) )
error = F_107 ( V_145 , V_919 ) ;
else if ( ! strcmp ( V_64 , L_57 ) )
error = F_107 ( V_145 , V_920 ) ;
else if ( ! strcmp ( V_64 , L_52 ) )
error = F_107 ( V_145 , V_921 ) ;
else
error = - V_90 ;
if ( error )
return error ;
if ( V_531 && V_1 [ 1 ] && V_1 [ 1 ] != '\n' ) {
if ( V_1 [ V_531 - 1 ] == '\n' ) {
V_1 [ V_531 - 1 ] = 0 ;
V_531 -- ;
}
error = F_68 ( V_501 , V_531 , & V_17 , V_15 ) ;
if ( error == - V_90 && ! strcmp ( V_64 , L_55 ) ) {
if ( ! F_217 ( V_533 ) ) {
struct V_534 * V_535 ;
T_7 V_536 ;
if ( V_1 [ V_531 - 1 ] == '\0' )
V_536 = V_531 - 1 ;
else
V_536 = V_531 ;
V_535 = F_220 ( V_11 -> V_537 , V_96 , V_538 ) ;
F_221 ( V_535 , L_58 ) ;
F_222 ( V_535 , V_501 , V_536 ) ;
F_223 ( V_535 ) ;
return error ;
}
error = F_224 ( V_501 , V_531 ,
& V_17 ) ;
}
if ( error )
return error ;
}
V_128 = F_399 () ;
if ( ! V_128 )
return - V_27 ;
V_14 = V_128 -> V_19 ;
if ( ! strcmp ( V_64 , L_54 ) ) {
V_14 -> V_419 = V_17 ;
} else if ( ! strcmp ( V_64 , L_55 ) ) {
V_14 -> V_300 = V_17 ;
} else if ( ! strcmp ( V_64 , L_56 ) ) {
error = F_123 ( V_17 , V_145 ) ;
if ( error )
goto V_922;
V_14 -> V_417 = V_17 ;
} else if ( ! strcmp ( V_64 , L_57 ) ) {
V_14 -> V_418 = V_17 ;
} else if ( ! strcmp ( V_64 , L_52 ) ) {
error = - V_90 ;
if ( V_17 == 0 )
goto V_922;
error = - V_414 ;
if ( ! F_400 () ) {
error = F_147 ( V_14 -> V_17 , V_17 ) ;
if ( error )
goto V_922;
}
error = F_46 ( V_14 -> V_17 , V_17 , V_269 ,
V_923 , NULL ) ;
if ( error )
goto V_922;
V_429 = 0 ;
F_19 () ;
V_427 = F_149 ( V_145 ) ;
if ( V_427 )
V_429 = F_18 ( V_427 ) ;
F_21 () ;
if ( V_427 ) {
error = F_46 ( V_429 , V_17 , V_269 ,
V_363 , NULL ) ;
if ( error )
goto V_922;
}
V_14 -> V_17 = V_17 ;
} else {
error = - V_90 ;
goto V_922;
}
F_401 ( V_128 ) ;
return V_531 ;
V_922:
F_402 ( V_128 ) ;
return error ;
}
static int F_403 ( const char * V_64 )
{
return ( strcmp ( V_64 , V_503 ) == 0 ) ;
}
static int F_404 ( T_2 V_544 , char * * V_483 , T_2 * V_924 )
{
return F_61 ( V_544 , V_483 , V_924 ) ;
}
static int F_405 ( const char * V_483 , T_2 V_924 , T_2 * V_544 )
{
return F_68 ( V_483 , V_924 , V_544 , V_15 ) ;
}
static void F_406 ( char * V_483 , T_2 V_924 )
{
F_39 ( V_483 ) ;
}
static int F_407 ( struct V_22 * V_22 , void * V_306 , T_2 V_499 )
{
return F_232 ( V_22 , V_503 , V_306 , V_499 , 0 ) ;
}
static int F_408 ( struct V_65 * V_65 , void * V_306 , T_2 V_499 )
{
return F_409 ( V_65 , V_75 , V_306 , V_499 , 0 ) ;
}
static int F_410 ( struct V_22 * V_22 , void * * V_306 , T_2 * V_499 )
{
int V_88 = 0 ;
V_88 = F_230 ( V_22 , V_503 ,
V_306 , true ) ;
if ( V_88 < 0 )
return V_88 ;
* V_499 = V_88 ;
return 0 ;
}
static int F_411 ( struct V_842 * V_925 , const struct V_10 * V_10 ,
unsigned long V_79 )
{
const struct V_13 * V_14 ;
struct V_926 * V_927 ;
V_927 = F_15 ( sizeof( struct V_926 ) , V_15 ) ;
if ( ! V_927 )
return - V_27 ;
V_14 = V_10 -> V_19 ;
if ( V_14 -> V_417 )
V_927 -> V_17 = V_14 -> V_417 ;
else
V_927 -> V_17 = V_14 -> V_17 ;
V_925 -> V_19 = V_927 ;
return 0 ;
}
static void F_412 ( struct V_842 * V_925 )
{
struct V_926 * V_927 = V_925 -> V_19 ;
V_925 -> V_19 = NULL ;
F_39 ( V_927 ) ;
}
static int F_413 ( T_16 V_928 ,
const struct V_10 * V_10 ,
unsigned V_256 )
{
struct V_842 * V_842 ;
struct V_926 * V_927 ;
T_2 V_17 ;
if ( V_256 == 0 )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_842 = F_414 ( V_928 ) ;
V_927 = V_842 -> V_19 ;
return F_46 ( V_17 , V_927 -> V_17 , V_307 , V_256 , NULL ) ;
}
static int F_415 ( struct V_842 * V_842 , char * * V_929 )
{
struct V_926 * V_927 = V_842 -> V_19 ;
char * V_87 = NULL ;
unsigned V_88 ;
int V_53 ;
V_53 = F_61 ( V_927 -> V_17 , & V_87 , & V_88 ) ;
if ( ! V_53 )
V_53 = V_88 ;
* V_929 = V_87 ;
return V_53 ;
}
static T_1 int F_416 ( void )
{
if ( ! F_417 ( L_59 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_51 ( V_930 L_60 ) ;
return 0 ;
}
F_51 ( V_930 L_61 ) ;
F_14 () ;
V_563 = ! ( V_931 & V_578 ) ;
V_25 = F_418 ( L_62 ,
sizeof( struct V_23 ) ,
0 , V_932 , NULL ) ;
F_419 () ;
F_420 ( V_933 , F_52 ( V_933 ) ) ;
if ( F_421 ( F_9 , V_9 ) )
F_16 ( L_63 ) ;
if ( V_3 )
F_51 ( V_934 L_64 ) ;
else
F_51 ( V_934 L_65 ) ;
return 0 ;
}
static void F_422 ( struct V_47 * V_48 , void * V_935 )
{
F_77 ( V_48 , NULL ) ;
}
void F_423 ( void )
{
F_51 ( V_934 L_66 ) ;
F_51 ( V_934 L_67 ) ;
F_424 ( F_422 , NULL ) ;
}
static int T_1 F_425 ( void )
{
int V_592 ;
if ( ! V_5 )
return 0 ;
F_51 ( V_934 L_68 ) ;
V_592 = F_426 ( V_936 , F_52 ( V_936 ) ) ;
if ( V_592 )
F_16 ( L_69 , V_592 ) ;
return 0 ;
}
static void F_427 ( void )
{
F_51 ( V_934 L_70 ) ;
F_428 ( V_936 , F_52 ( V_936 ) ) ;
}
int F_429 ( void )
{
if ( V_91 ) {
return - V_90 ;
}
if ( V_937 ) {
return - V_90 ;
}
F_51 ( V_930 L_71 ) ;
V_937 = 1 ;
V_5 = 0 ;
F_430 ( V_933 , F_52 ( V_933 ) ) ;
F_431 () ;
F_427 () ;
F_432 () ;
return 0 ;
}
