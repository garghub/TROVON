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
struct V_22 * V_67 = F_50 ( V_65 ) ;
int V_53 = 0 ;
if ( V_38 -> V_58 == V_59 ) {
if ( ! V_67 -> V_68 -> V_69 ) {
F_51 ( V_70 L_6
L_7 , V_48 -> V_71 , V_48 -> V_62 -> V_63 ) ;
V_53 = - V_72 ;
goto V_73;
}
V_53 = V_67 -> V_68 -> V_69 ( V_65 , V_74 , NULL , 0 ) ;
if ( V_53 < 0 && V_53 != - V_75 ) {
if ( V_53 == - V_72 )
F_51 ( V_70 L_8
L_9 ,
V_48 -> V_71 , V_48 -> V_62 -> V_63 ) ;
else
F_51 ( V_70 L_8
L_10 , V_48 -> V_71 ,
V_48 -> V_62 -> V_63 , - V_53 ) ;
goto V_73;
}
}
if ( V_38 -> V_58 > F_52 ( V_76 ) )
F_51 ( V_77 L_11 ,
V_48 -> V_71 , V_48 -> V_62 -> V_63 ) ;
V_38 -> V_78 |= V_79 ;
if ( F_48 ( V_48 ) )
V_38 -> V_78 |= V_80 ;
V_53 = F_44 ( V_67 , V_65 ) ;
F_32 ( & V_38 -> V_41 ) ;
V_81:
if ( ! F_33 ( & V_38 -> V_49 ) ) {
struct V_23 * V_24 =
F_53 ( V_38 -> V_49 . V_82 ,
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
goto V_81;
}
F_35 ( & V_38 -> V_41 ) ;
V_73:
return V_53 ;
}
static int F_57 ( const struct V_47 * V_48 ,
struct V_83 * V_84 )
{
int V_53 = 0 , V_85 ;
struct V_37 * V_38 = V_48 -> V_40 ;
char * V_86 = NULL ;
T_2 V_87 ;
char V_88 ;
F_58 ( V_84 ) ;
if ( ! ( V_38 -> V_78 & V_79 ) )
return - V_89 ;
if ( ! V_90 )
return - V_89 ;
F_59 ( V_91 >= ( 1 << V_92 ) ) ;
V_88 = V_38 -> V_78 & V_91 ;
for ( V_85 = 0 ; V_85 < V_92 ; V_85 ++ ) {
if ( V_88 & 0x01 )
V_84 -> V_93 ++ ;
V_88 >>= 1 ;
}
if ( V_38 -> V_78 & V_80 )
V_84 -> V_93 ++ ;
V_84 -> V_94 = F_60 ( V_84 -> V_93 , sizeof( char * ) , V_95 ) ;
if ( ! V_84 -> V_94 ) {
V_53 = - V_27 ;
goto V_96;
}
V_84 -> V_97 = F_60 ( V_84 -> V_93 , sizeof( int ) , V_95 ) ;
if ( ! V_84 -> V_97 ) {
V_53 = - V_27 ;
goto V_96;
}
V_85 = 0 ;
if ( V_38 -> V_78 & V_98 ) {
V_53 = F_61 ( V_38 -> V_17 , & V_86 , & V_87 ) ;
if ( V_53 )
goto V_96;
V_84 -> V_94 [ V_85 ] = V_86 ;
V_84 -> V_97 [ V_85 ++ ] = V_98 ;
}
if ( V_38 -> V_78 & V_99 ) {
V_53 = F_61 ( V_38 -> V_52 , & V_86 , & V_87 ) ;
if ( V_53 )
goto V_96;
V_84 -> V_94 [ V_85 ] = V_86 ;
V_84 -> V_97 [ V_85 ++ ] = V_99 ;
}
if ( V_38 -> V_78 & V_100 ) {
V_53 = F_61 ( V_38 -> V_50 , & V_86 , & V_87 ) ;
if ( V_53 )
goto V_96;
V_84 -> V_94 [ V_85 ] = V_86 ;
V_84 -> V_97 [ V_85 ++ ] = V_100 ;
}
if ( V_38 -> V_78 & V_101 ) {
struct V_22 * V_65 = F_50 ( V_38 -> V_48 -> V_66 ) ;
struct V_23 * V_24 = V_65 -> V_33 ;
V_53 = F_61 ( V_24 -> V_17 , & V_86 , & V_87 ) ;
if ( V_53 )
goto V_96;
V_84 -> V_94 [ V_85 ] = V_86 ;
V_84 -> V_97 [ V_85 ++ ] = V_101 ;
}
if ( V_38 -> V_78 & V_80 ) {
V_84 -> V_94 [ V_85 ] = NULL ;
V_84 -> V_97 [ V_85 ++ ] = V_80 ;
}
F_62 ( V_85 != V_84 -> V_93 ) ;
return 0 ;
V_96:
F_63 ( V_84 ) ;
return V_53 ;
}
static int F_64 ( struct V_37 * V_38 , char V_102 ,
T_2 V_103 , T_2 V_104 )
{
char V_105 = V_38 -> V_78 & V_91 ;
if ( V_38 -> V_78 & V_79 )
if ( ! ( V_38 -> V_78 & V_102 ) ||
( V_103 != V_104 ) )
return 1 ;
if ( ! ( V_38 -> V_78 & V_79 ) )
if ( V_105 & V_102 )
return 1 ;
return 0 ;
}
static int F_65 ( struct V_47 * V_48 ,
struct V_83 * V_84 ,
unsigned long V_106 ,
unsigned long * V_107 )
{
const struct V_10 * V_10 = F_66 () ;
int V_53 = 0 , V_85 ;
struct V_37 * V_38 = V_48 -> V_40 ;
const char * V_63 = V_48 -> V_62 -> V_63 ;
struct V_22 * V_22 = F_50 ( V_38 -> V_48 -> V_66 ) ;
struct V_23 * V_108 = V_22 -> V_33 ;
T_2 V_109 = 0 , V_110 = 0 , V_111 = 0 ;
T_2 V_112 = 0 ;
char * * V_113 = V_84 -> V_94 ;
int * V_78 = V_84 -> V_97 ;
int V_114 = V_84 -> V_93 ;
F_67 ( & V_38 -> V_28 ) ;
if ( ! V_90 ) {
if ( ! V_114 ) {
goto V_73;
}
V_53 = - V_89 ;
F_51 ( V_70 L_12
L_13 ) ;
goto V_73;
}
if ( V_106 && ! V_107 ) {
V_53 = - V_89 ;
goto V_73;
}
if ( ( V_38 -> V_78 & V_79 ) && ( V_48 -> V_62 -> V_115 & V_116 )
&& ( V_114 == 0 ) )
goto V_73;
for ( V_85 = 0 ; V_85 < V_114 ; V_85 ++ ) {
T_2 V_17 ;
if ( V_78 [ V_85 ] == V_80 )
continue;
V_53 = F_68 ( V_113 [ V_85 ] ,
strlen ( V_113 [ V_85 ] ) , & V_17 , V_15 ) ;
if ( V_53 ) {
F_51 ( V_70 L_14
L_15 ,
V_113 [ V_85 ] , V_48 -> V_71 , V_63 , V_53 ) ;
goto V_73;
}
switch ( V_78 [ V_85 ] ) {
case V_98 :
V_109 = V_17 ;
if ( F_64 ( V_38 , V_98 , V_38 -> V_17 ,
V_109 ) )
goto V_117;
V_38 -> V_78 |= V_98 ;
break;
case V_99 :
V_110 = V_17 ;
if ( F_64 ( V_38 , V_99 , V_38 -> V_52 ,
V_110 ) )
goto V_117;
V_38 -> V_78 |= V_99 ;
break;
case V_101 :
V_111 = V_17 ;
if ( F_64 ( V_38 , V_101 , V_108 -> V_17 ,
V_111 ) )
goto V_117;
V_38 -> V_78 |= V_101 ;
break;
case V_100 :
V_112 = V_17 ;
if ( F_64 ( V_38 , V_100 , V_38 -> V_50 ,
V_112 ) )
goto V_117;
V_38 -> V_78 |= V_100 ;
break;
default:
V_53 = - V_89 ;
goto V_73;
}
}
if ( V_38 -> V_78 & V_79 ) {
if ( ( V_38 -> V_78 & V_91 ) && ! V_114 )
goto V_117;
V_53 = 0 ;
goto V_73;
}
if ( strcmp ( V_48 -> V_62 -> V_63 , L_16 ) == 0 )
V_38 -> V_78 |= V_118 ;
if ( ! V_38 -> V_58 ) {
V_53 = F_69 ( V_48 ) ;
if ( V_53 ) {
F_51 ( V_70
L_17 ,
V_119 , V_48 -> V_62 -> V_63 , V_53 ) ;
goto V_73;
}
}
if ( V_109 ) {
V_53 = F_45 ( V_109 , V_38 , V_10 ) ;
if ( V_53 )
goto V_73;
V_38 -> V_17 = V_109 ;
}
if ( V_106 & V_120 && ! V_110 ) {
V_38 -> V_58 = V_121 ;
* V_107 |= V_120 ;
}
if ( V_110 ) {
if ( ! V_109 ) {
V_53 = F_45 ( V_110 , V_38 ,
V_10 ) ;
if ( V_53 )
goto V_73;
V_38 -> V_17 = V_110 ;
} else {
V_53 = F_47 ( V_110 , V_38 ,
V_10 ) ;
if ( V_53 )
goto V_73;
}
if ( ! V_111 )
V_111 = V_110 ;
V_38 -> V_52 = V_110 ;
V_38 -> V_58 = V_122 ;
}
if ( V_111 ) {
V_53 = F_47 ( V_111 , V_38 ,
V_10 ) ;
if ( V_53 )
goto V_73;
V_108 -> V_17 = V_111 ;
V_108 -> V_123 = 1 ;
}
if ( V_112 ) {
if ( V_38 -> V_58 != V_59 &&
V_38 -> V_58 != V_121 ) {
V_53 = - V_89 ;
F_51 ( V_70 L_18
L_19 ) ;
goto V_73;
}
if ( V_112 != V_38 -> V_50 ) {
V_53 = F_47 ( V_112 ,
V_38 , V_10 ) ;
if ( V_53 )
goto V_73;
}
V_38 -> V_50 = V_112 ;
}
V_53 = F_49 ( V_48 ) ;
V_73:
F_70 ( & V_38 -> V_28 ) ;
return V_53 ;
V_117:
V_53 = - V_89 ;
F_51 ( V_70 L_20
L_21 , V_48 -> V_71 , V_63 ) ;
goto V_73;
}
static int F_71 ( const struct V_47 * V_124 ,
const struct V_47 * V_125 )
{
struct V_37 * V_126 = V_124 -> V_40 ;
struct V_37 * V_127 = V_125 -> V_40 ;
char V_128 = V_126 -> V_78 & V_91 ;
char V_129 = V_127 -> V_78 & V_91 ;
if ( V_128 != V_129 )
goto V_130;
if ( ( V_128 & V_98 ) && V_126 -> V_17 != V_127 -> V_17 )
goto V_130;
if ( ( V_128 & V_99 ) && V_126 -> V_52 != V_127 -> V_52 )
goto V_130;
if ( ( V_128 & V_100 ) && V_126 -> V_50 != V_127 -> V_50 )
goto V_130;
if ( V_128 & V_101 ) {
struct V_23 * V_131 = F_50 ( V_124 -> V_66 ) -> V_33 ;
struct V_23 * V_132 = F_50 ( V_125 -> V_66 ) -> V_33 ;
if ( V_131 -> V_17 != V_132 -> V_17 )
goto V_130;
}
return 0 ;
V_130:
F_51 ( V_70 L_22
L_23
L_24 , V_125 -> V_71 , V_125 -> V_62 -> V_63 ) ;
return - V_133 ;
}
static int F_72 ( const struct V_47 * V_124 ,
struct V_47 * V_125 )
{
const struct V_37 * V_134 = V_124 -> V_40 ;
struct V_37 * V_135 = V_125 -> V_40 ;
int V_136 = ( V_134 -> V_78 & V_98 ) ;
int V_137 = ( V_134 -> V_78 & V_99 ) ;
int V_138 = ( V_134 -> V_78 & V_101 ) ;
if ( ! V_90 )
return 0 ;
F_62 ( ! ( V_134 -> V_78 & V_79 ) ) ;
if ( V_135 -> V_78 & V_79 )
return F_71 ( V_124 , V_125 ) ;
F_67 ( & V_135 -> V_28 ) ;
V_135 -> V_78 = V_134 -> V_78 ;
V_135 -> V_17 = V_134 -> V_17 ;
V_135 -> V_50 = V_134 -> V_50 ;
V_135 -> V_58 = V_134 -> V_58 ;
if ( V_137 ) {
T_2 V_17 = V_134 -> V_52 ;
if ( ! V_136 )
V_135 -> V_17 = V_17 ;
if ( ! V_138 ) {
struct V_22 * V_139 = F_50 ( V_125 -> V_66 ) ;
struct V_23 * V_140 = V_139 -> V_33 ;
V_140 -> V_17 = V_17 ;
}
V_135 -> V_52 = V_17 ;
}
if ( V_138 ) {
const struct V_22 * V_141 = F_50 ( V_124 -> V_66 ) ;
const struct V_23 * V_142 = V_141 -> V_33 ;
struct V_22 * V_139 = F_50 ( V_125 -> V_66 ) ;
struct V_23 * V_140 = V_139 -> V_33 ;
V_140 -> V_17 = V_142 -> V_17 ;
}
F_49 ( V_125 ) ;
F_70 ( & V_135 -> V_28 ) ;
return 0 ;
}
static int F_73 ( char * V_143 ,
struct V_83 * V_84 )
{
char * V_144 ;
char * V_86 = NULL , * V_145 = NULL ;
char * V_146 = NULL , * V_147 = NULL ;
int V_53 , V_93 = 0 ;
V_84 -> V_93 = 0 ;
while ( ( V_144 = F_74 ( & V_143 , L_25 ) ) != NULL ) {
int V_148 ;
T_3 args [ V_149 ] ;
if ( ! * V_144 )
continue;
V_148 = F_75 ( V_144 , V_150 , args ) ;
switch ( V_148 ) {
case V_151 :
if ( V_86 || V_145 ) {
V_53 = - V_89 ;
F_51 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_152;
}
V_86 = F_76 ( & args [ 0 ] ) ;
if ( ! V_86 ) {
V_53 = - V_27 ;
goto V_152;
}
break;
case V_153 :
if ( V_146 ) {
V_53 = - V_89 ;
F_51 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_152;
}
V_146 = F_76 ( & args [ 0 ] ) ;
if ( ! V_146 ) {
V_53 = - V_27 ;
goto V_152;
}
break;
case V_154 :
if ( V_147 ) {
V_53 = - V_89 ;
F_51 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_152;
}
V_147 = F_76 ( & args [ 0 ] ) ;
if ( ! V_147 ) {
V_53 = - V_27 ;
goto V_152;
}
break;
case V_155 :
if ( V_86 || V_145 ) {
V_53 = - V_89 ;
F_51 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_152;
}
V_145 = F_76 ( & args [ 0 ] ) ;
if ( ! V_145 ) {
V_53 = - V_27 ;
goto V_152;
}
break;
case V_156 :
break;
default:
V_53 = - V_89 ;
F_51 ( V_70 L_26 ) ;
goto V_152;
}
}
V_53 = - V_27 ;
V_84 -> V_94 = F_60 ( V_92 , sizeof( char * ) , V_95 ) ;
if ( ! V_84 -> V_94 )
goto V_152;
V_84 -> V_97 = F_60 ( V_92 , sizeof( int ) , V_95 ) ;
if ( ! V_84 -> V_97 ) {
F_39 ( V_84 -> V_94 ) ;
goto V_152;
}
if ( V_146 ) {
V_84 -> V_94 [ V_93 ] = V_146 ;
V_84 -> V_97 [ V_93 ++ ] = V_98 ;
}
if ( V_86 ) {
V_84 -> V_94 [ V_93 ] = V_86 ;
V_84 -> V_97 [ V_93 ++ ] = V_99 ;
}
if ( V_147 ) {
V_84 -> V_94 [ V_93 ] = V_147 ;
V_84 -> V_97 [ V_93 ++ ] = V_101 ;
}
if ( V_145 ) {
V_84 -> V_94 [ V_93 ] = V_145 ;
V_84 -> V_97 [ V_93 ++ ] = V_100 ;
}
V_84 -> V_93 = V_93 ;
return 0 ;
V_152:
F_39 ( V_86 ) ;
F_39 ( V_145 ) ;
F_39 ( V_146 ) ;
F_39 ( V_147 ) ;
return V_53 ;
}
static int F_77 ( struct V_47 * V_48 , void * V_157 )
{
int V_53 = 0 ;
char * V_143 = V_157 ;
struct V_83 V_84 ;
F_58 ( & V_84 ) ;
if ( ! V_157 )
goto V_73;
F_62 ( V_48 -> V_62 -> V_115 & V_116 ) ;
V_53 = F_73 ( V_143 , & V_84 ) ;
if ( V_53 )
goto V_152;
V_73:
V_53 = F_65 ( V_48 , & V_84 , 0 , NULL ) ;
V_152:
F_63 ( & V_84 ) ;
return V_53 ;
}
static void F_78 ( struct V_158 * V_159 ,
struct V_83 * V_84 )
{
int V_85 ;
char * V_160 ;
for ( V_85 = 0 ; V_85 < V_84 -> V_93 ; V_85 ++ ) {
char * V_161 ;
if ( V_84 -> V_94 [ V_85 ] )
V_161 = strchr ( V_84 -> V_94 [ V_85 ] , ',' ) ;
else
V_161 = NULL ;
switch ( V_84 -> V_97 [ V_85 ] ) {
case V_99 :
V_160 = V_162 ;
break;
case V_98 :
V_160 = V_163 ;
break;
case V_101 :
V_160 = V_164 ;
break;
case V_100 :
V_160 = V_165 ;
break;
case V_80 :
F_79 ( V_159 , ',' ) ;
F_80 ( V_159 , V_166 ) ;
continue;
default:
F_81 () ;
return;
} ;
F_79 ( V_159 , ',' ) ;
F_80 ( V_159 , V_160 ) ;
if ( V_161 )
F_79 ( V_159 , '\"' ) ;
F_80 ( V_159 , V_84 -> V_94 [ V_85 ] ) ;
if ( V_161 )
F_79 ( V_159 , '\"' ) ;
}
}
static int F_82 ( struct V_158 * V_159 , struct V_47 * V_48 )
{
struct V_83 V_84 ;
int V_53 ;
V_53 = F_57 ( V_48 , & V_84 ) ;
if ( V_53 ) {
if ( V_53 == - V_89 )
V_53 = 0 ;
return V_53 ;
}
F_78 ( V_159 , & V_84 ) ;
F_63 ( & V_84 ) ;
return V_53 ;
}
static inline T_4 F_83 ( T_5 V_167 )
{
switch ( V_167 & V_168 ) {
case V_169 :
return V_170 ;
case V_171 :
return V_172 ;
case V_173 :
return V_32 ;
case V_174 :
return V_175 ;
case V_176 :
return V_177 ;
case V_178 :
return V_179 ;
case V_180 :
return V_181 ;
}
return V_32 ;
}
static inline int F_84 ( int V_182 )
{
return ( V_182 == V_183 || V_182 == V_184 ) ;
}
static inline int F_85 ( int V_182 )
{
return ( V_182 == V_183 || V_182 == V_185 ) ;
}
static inline T_4 F_86 ( int V_186 , int type , int V_182 )
{
switch ( V_186 ) {
case V_187 :
switch ( type ) {
case V_188 :
case V_189 :
return V_190 ;
case V_191 :
return V_192 ;
}
break;
case V_193 :
case V_194 :
switch ( type ) {
case V_188 :
if ( F_84 ( V_182 ) )
return V_195 ;
else
return V_196 ;
case V_191 :
if ( F_85 ( V_182 ) )
return V_197 ;
else
return V_196 ;
case V_198 :
return V_199 ;
default:
return V_196 ;
}
break;
case V_200 :
switch ( V_182 ) {
case V_201 :
return V_202 ;
case V_203 :
return V_204 ;
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
default:
return V_221 ;
}
case V_222 :
return V_223 ;
case V_224 :
return V_225 ;
case V_226 :
return V_227 ;
}
return V_228 ;
}
static int F_87 ( struct V_64 * V_64 ,
T_4 V_229 ,
T_2 * V_17 )
{
int V_53 ;
char * V_230 , * V_231 ;
V_230 = ( char * ) F_88 ( V_15 ) ;
if ( ! V_230 )
return - V_27 ;
V_231 = F_89 ( V_64 , V_230 , V_232 ) ;
if ( F_90 ( V_231 ) )
V_53 = F_91 ( V_231 ) ;
else {
while ( V_231 [ 1 ] >= '0' && V_231 [ 1 ] <= '9' ) {
V_231 [ 1 ] = '/' ;
V_231 ++ ;
}
V_53 = F_92 ( L_16 , V_231 , V_229 , V_17 ) ;
}
F_93 ( ( unsigned long ) V_230 ) ;
return V_53 ;
}
static int F_87 ( struct V_64 * V_64 ,
T_4 V_229 ,
T_2 * V_17 )
{
return - V_89 ;
}
static int F_44 ( struct V_22 * V_22 , struct V_64 * V_233 )
{
struct V_37 * V_38 = NULL ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 ;
struct V_64 * V_64 ;
#define F_94 255
char * V_86 = NULL ;
unsigned V_87 = 0 ;
int V_53 = 0 ;
if ( V_24 -> V_123 )
goto V_73;
F_67 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_123 )
goto V_234;
V_38 = V_22 -> V_39 -> V_40 ;
if ( ! ( V_38 -> V_78 & V_79 ) ) {
F_32 ( & V_38 -> V_41 ) ;
if ( F_33 ( & V_24 -> V_29 ) )
F_95 ( & V_24 -> V_29 , & V_38 -> V_49 ) ;
F_35 ( & V_38 -> V_41 ) ;
goto V_234;
}
switch ( V_38 -> V_58 ) {
case V_121 :
break;
case V_59 :
if ( ! V_22 -> V_68 -> V_69 ) {
V_24 -> V_17 = V_38 -> V_50 ;
break;
}
if ( V_233 ) {
V_64 = F_96 ( V_233 ) ;
} else {
V_64 = F_97 ( V_22 ) ;
}
if ( ! V_64 ) {
goto V_234;
}
V_87 = F_94 ;
V_86 = F_98 ( V_87 + 1 , V_26 ) ;
if ( ! V_86 ) {
V_53 = - V_27 ;
F_99 ( V_64 ) ;
goto V_234;
}
V_86 [ V_87 ] = '\0' ;
V_53 = V_22 -> V_68 -> V_69 ( V_64 , V_74 ,
V_86 , V_87 ) ;
if ( V_53 == - V_235 ) {
F_39 ( V_86 ) ;
V_53 = V_22 -> V_68 -> V_69 ( V_64 , V_74 ,
NULL , 0 ) ;
if ( V_53 < 0 ) {
F_99 ( V_64 ) ;
goto V_234;
}
V_87 = V_53 ;
V_86 = F_98 ( V_87 + 1 , V_26 ) ;
if ( ! V_86 ) {
V_53 = - V_27 ;
F_99 ( V_64 ) ;
goto V_234;
}
V_86 [ V_87 ] = '\0' ;
V_53 = V_22 -> V_68 -> V_69 ( V_64 ,
V_74 ,
V_86 , V_87 ) ;
}
F_99 ( V_64 ) ;
if ( V_53 < 0 ) {
if ( V_53 != - V_75 ) {
F_51 ( V_70 L_27
L_28 , V_119 ,
- V_53 , V_22 -> V_39 -> V_71 , V_22 -> V_236 ) ;
F_39 ( V_86 ) ;
goto V_234;
}
V_17 = V_38 -> V_50 ;
V_53 = 0 ;
} else {
V_53 = F_100 ( V_86 , V_53 , & V_17 ,
V_38 -> V_50 ,
V_26 ) ;
if ( V_53 ) {
char * V_237 = V_22 -> V_39 -> V_71 ;
unsigned long V_238 = V_22 -> V_236 ;
if ( V_53 == - V_89 ) {
if ( F_101 () )
F_51 ( V_239 L_29
L_30
L_31 , V_238 , V_237 , V_86 ) ;
} else {
F_51 ( V_70 L_32
L_33 ,
V_119 , V_86 , - V_53 , V_237 , V_238 ) ;
}
F_39 ( V_86 ) ;
V_53 = 0 ;
break;
}
}
F_39 ( V_86 ) ;
V_24 -> V_17 = V_17 ;
break;
case V_61 :
V_24 -> V_17 = V_24 -> F_18 ;
break;
case V_60 :
V_24 -> V_17 = V_38 -> V_17 ;
V_24 -> V_31 = F_83 ( V_22 -> V_240 ) ;
V_53 = F_102 ( V_24 -> F_18 , V_38 -> V_17 ,
V_24 -> V_31 , NULL , & V_17 ) ;
if ( V_53 )
goto V_234;
V_24 -> V_17 = V_17 ;
break;
case V_122 :
V_24 -> V_17 = V_38 -> V_52 ;
break;
default:
V_24 -> V_17 = V_38 -> V_17 ;
if ( ( V_38 -> V_78 & V_118 ) && ! F_103 ( V_22 -> V_240 ) ) {
if ( V_233 )
V_64 = F_96 ( V_233 ) ;
else
V_64 = F_97 ( V_22 ) ;
if ( ! V_64 )
goto V_234;
V_24 -> V_31 = F_83 ( V_22 -> V_240 ) ;
V_53 = F_87 ( V_64 , V_24 -> V_31 , & V_17 ) ;
F_99 ( V_64 ) ;
if ( V_53 )
goto V_234;
V_24 -> V_17 = V_17 ;
}
break;
}
V_24 -> V_123 = 1 ;
V_234:
F_70 ( & V_24 -> V_28 ) ;
V_73:
if ( V_24 -> V_31 == V_32 )
V_24 -> V_31 = F_83 ( V_22 -> V_240 ) ;
return V_53 ;
}
static inline T_2 F_104 ( int V_241 )
{
T_2 V_242 = 0 ;
switch ( V_241 ) {
case V_243 :
V_242 = V_244 ;
break;
case V_245 :
V_242 = V_246 ;
break;
case V_247 :
V_242 = V_248 ;
break;
default:
V_242 = V_249 ;
break;
}
return V_242 ;
}
static int F_105 ( const struct V_10 * V_250 ,
const struct V_10 * V_251 ,
T_2 V_252 )
{
T_2 V_253 = F_17 ( V_250 ) , V_254 = F_17 ( V_251 ) ;
return F_46 ( V_253 , V_254 , V_255 , V_252 , NULL ) ;
}
static int F_106 ( const struct V_20 * V_256 ,
const struct V_20 * V_257 ,
T_2 V_252 )
{
const struct V_13 * V_258 , * V_259 ;
T_2 V_260 , V_261 ;
F_19 () ;
V_258 = F_20 ( V_256 ) -> V_19 ; V_260 = V_258 -> V_17 ;
V_259 = F_20 ( V_257 ) -> V_19 ; V_261 = V_259 -> V_17 ;
F_21 () ;
return F_46 ( V_260 , V_261 , V_255 , V_252 , NULL ) ;
}
static int F_107 ( const struct V_20 * V_262 ,
T_2 V_252 )
{
T_2 V_17 , V_254 ;
V_17 = F_22 () ;
V_254 = F_18 ( V_262 ) ;
return F_46 ( V_17 , V_254 , V_255 , V_252 , NULL ) ;
}
static int F_108 ( const struct V_10 * V_10 ,
int V_263 , int V_264 )
{
struct V_265 V_266 ;
struct V_267 V_268 ;
T_4 V_31 ;
T_2 V_17 = F_17 ( V_10 ) ;
T_2 V_269 = F_109 ( V_263 ) ;
int V_53 ;
V_266 . type = V_270 ;
V_266 . V_271 . V_263 = V_263 ;
switch ( F_110 ( V_263 ) ) {
case 0 :
V_31 = V_272 ;
break;
case 1 :
V_31 = V_273 ;
break;
default:
F_51 ( V_77
L_34 , V_263 ) ;
F_81 () ;
return - V_89 ;
}
V_53 = F_111 ( V_17 , V_17 , V_31 , V_269 , 0 , & V_268 ) ;
if ( V_264 == V_274 ) {
int V_275 = F_112 ( V_17 , V_17 , V_31 , V_269 , & V_268 , V_53 , & V_266 ) ;
if ( V_275 )
return V_275 ;
}
return V_53 ;
}
static int F_113 ( struct V_20 * V_262 ,
T_2 V_252 )
{
T_2 V_17 = F_18 ( V_262 ) ;
return F_46 ( V_17 , V_18 ,
V_276 , V_252 , NULL ) ;
}
static int F_114 ( const struct V_10 * V_10 ,
struct V_22 * V_22 ,
T_2 V_252 ,
struct V_265 * V_277 )
{
struct V_23 * V_24 ;
T_2 V_17 ;
F_115 ( V_10 ) ;
if ( F_116 ( F_55 ( V_22 ) ) )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
return F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_252 , V_277 ) ;
}
static inline int F_117 ( const struct V_10 * V_10 ,
struct V_64 * V_64 ,
T_2 V_269 )
{
struct V_22 * V_22 = F_50 ( V_64 ) ;
struct V_265 V_266 ;
V_266 . type = V_278 ;
V_266 . V_271 . V_64 = V_64 ;
return F_114 ( V_10 , V_22 , V_269 , & V_266 ) ;
}
static inline int F_118 ( const struct V_10 * V_10 ,
const struct V_231 * V_231 ,
T_2 V_269 )
{
struct V_22 * V_22 = F_50 ( V_231 -> V_64 ) ;
struct V_265 V_266 ;
V_266 . type = V_279 ;
V_266 . V_271 . V_231 = * V_231 ;
return F_114 ( V_10 , V_22 , V_269 , & V_266 ) ;
}
static inline int F_119 ( const struct V_10 * V_10 ,
struct V_42 * V_42 ,
T_2 V_269 )
{
struct V_265 V_266 ;
V_266 . type = V_279 ;
V_266 . V_271 . V_231 = V_42 -> V_280 ;
return F_114 ( V_10 , F_120 ( V_42 ) , V_269 , & V_266 ) ;
}
static int F_121 ( const struct V_10 * V_10 ,
struct V_42 * V_42 ,
T_2 V_269 )
{
struct V_43 * V_44 = V_42 -> V_46 ;
struct V_22 * V_22 = F_120 ( V_42 ) ;
struct V_265 V_266 ;
T_2 V_17 = F_17 ( V_10 ) ;
int V_53 ;
V_266 . type = V_279 ;
V_266 . V_271 . V_231 = V_42 -> V_280 ;
if ( V_17 != V_44 -> V_17 ) {
V_53 = F_46 ( V_17 , V_44 -> V_17 ,
V_281 ,
V_282 ,
& V_266 ) ;
if ( V_53 )
goto V_73;
}
V_53 = 0 ;
if ( V_269 )
V_53 = F_114 ( V_10 , V_22 , V_269 , & V_266 ) ;
V_73:
return V_53 ;
}
static int F_122 ( struct V_22 * V_283 ,
struct V_64 * V_64 ,
T_4 V_229 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_284 ;
struct V_37 * V_38 ;
T_2 V_17 , V_285 ;
struct V_265 V_266 ;
int V_53 ;
V_284 = V_283 -> V_33 ;
V_38 = V_283 -> V_39 -> V_40 ;
V_17 = V_14 -> V_17 ;
V_285 = V_14 -> V_286 ;
V_266 . type = V_278 ;
V_266 . V_271 . V_64 = V_64 ;
V_53 = F_46 ( V_17 , V_284 -> V_17 , V_177 ,
V_287 | V_288 ,
& V_266 ) ;
if ( V_53 )
return V_53 ;
if ( ! V_285 || ! ( V_38 -> V_78 & V_80 ) ) {
V_53 = F_102 ( V_17 , V_284 -> V_17 , V_229 ,
& V_64 -> V_289 , & V_285 ) ;
if ( V_53 )
return V_53 ;
}
V_53 = F_46 ( V_17 , V_285 , V_229 , V_290 , & V_266 ) ;
if ( V_53 )
return V_53 ;
return F_46 ( V_285 , V_38 -> V_17 ,
V_54 ,
V_57 , & V_266 ) ;
}
static int F_123 ( T_2 V_291 ,
struct V_20 * V_292 )
{
T_2 V_17 = F_18 ( V_292 ) ;
return F_46 ( V_17 , V_291 , V_293 , V_294 , NULL ) ;
}
static int F_124 ( struct V_22 * V_283 ,
struct V_64 * V_64 ,
int V_295 )
{
struct V_23 * V_284 , * V_24 ;
struct V_265 V_266 ;
T_2 V_17 = F_22 () ;
T_2 V_269 ;
int V_53 ;
V_284 = V_283 -> V_33 ;
V_24 = F_50 ( V_64 ) -> V_33 ;
V_266 . type = V_278 ;
V_266 . V_271 . V_64 = V_64 ;
V_269 = V_288 ;
V_269 |= ( V_295 ? V_296 : V_287 ) ;
V_53 = F_46 ( V_17 , V_284 -> V_17 , V_177 , V_269 , & V_266 ) ;
if ( V_53 )
return V_53 ;
switch ( V_295 ) {
case V_297 :
V_269 = V_298 ;
break;
case V_299 :
V_269 = V_300 ;
break;
case V_301 :
V_269 = V_302 ;
break;
default:
F_51 ( V_70 L_35 ,
V_119 , V_295 ) ;
return 0 ;
}
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_269 , & V_266 ) ;
return V_53 ;
}
static inline int F_125 ( struct V_22 * V_303 ,
struct V_64 * V_304 ,
struct V_22 * V_305 ,
struct V_64 * V_306 )
{
struct V_23 * V_307 , * V_308 , * V_309 , * V_310 ;
struct V_265 V_266 ;
T_2 V_17 = F_22 () ;
T_2 V_269 ;
int V_311 , V_312 ;
int V_53 ;
V_307 = V_303 -> V_33 ;
V_309 = F_50 ( V_304 ) -> V_33 ;
V_311 = F_126 ( V_304 ) ;
V_308 = V_305 -> V_33 ;
V_266 . type = V_278 ;
V_266 . V_271 . V_64 = V_304 ;
V_53 = F_46 ( V_17 , V_307 -> V_17 , V_177 ,
V_296 | V_288 , & V_266 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_17 , V_309 -> V_17 ,
V_309 -> V_31 , V_313 , & V_266 ) ;
if ( V_53 )
return V_53 ;
if ( V_311 && V_305 != V_303 ) {
V_53 = F_46 ( V_17 , V_309 -> V_17 ,
V_309 -> V_31 , V_314 , & V_266 ) ;
if ( V_53 )
return V_53 ;
}
V_266 . V_271 . V_64 = V_306 ;
V_269 = V_287 | V_288 ;
if ( F_127 ( V_306 ) )
V_269 |= V_296 ;
V_53 = F_46 ( V_17 , V_308 -> V_17 , V_177 , V_269 , & V_266 ) ;
if ( V_53 )
return V_53 ;
if ( F_127 ( V_306 ) ) {
V_310 = F_50 ( V_306 ) -> V_33 ;
V_312 = F_126 ( V_306 ) ;
V_53 = F_46 ( V_17 , V_310 -> V_17 ,
V_310 -> V_31 ,
( V_312 ? V_302 : V_300 ) , & V_266 ) ;
if ( V_53 )
return V_53 ;
}
return 0 ;
}
static int F_128 ( const struct V_10 * V_10 ,
struct V_47 * V_48 ,
T_2 V_252 ,
struct V_265 * V_266 )
{
struct V_37 * V_38 ;
T_2 V_17 = F_17 ( V_10 ) ;
V_38 = V_48 -> V_40 ;
return F_46 ( V_17 , V_38 -> V_17 , V_54 , V_252 , V_266 ) ;
}
static inline T_2 F_129 ( int V_167 , int V_315 )
{
T_2 V_269 = 0 ;
if ( ! F_130 ( V_167 ) ) {
if ( V_315 & V_316 )
V_269 |= V_317 ;
if ( V_315 & V_318 )
V_269 |= V_319 ;
if ( V_315 & V_320 )
V_269 |= V_321 ;
else if ( V_315 & V_322 )
V_269 |= V_323 ;
} else {
if ( V_315 & V_316 )
V_269 |= V_288 ;
if ( V_315 & V_322 )
V_269 |= V_324 ;
if ( V_315 & V_318 )
V_269 |= V_325 ;
}
return V_269 ;
}
static inline T_2 F_131 ( struct V_42 * V_42 )
{
T_2 V_269 = 0 ;
if ( V_42 -> V_326 & V_327 )
V_269 |= V_319 ;
if ( V_42 -> V_326 & V_328 ) {
if ( V_42 -> V_329 & V_330 )
V_269 |= V_321 ;
else
V_269 |= V_323 ;
}
if ( ! V_269 ) {
V_269 = V_331 ;
}
return V_269 ;
}
static inline T_2 F_132 ( struct V_42 * V_42 )
{
T_2 V_269 = F_131 ( V_42 ) ;
if ( V_332 )
V_269 |= V_333 ;
return V_269 ;
}
static int F_133 ( struct V_20 * V_334 )
{
T_2 V_335 = F_22 () ;
T_2 V_336 = F_18 ( V_334 ) ;
return F_46 ( V_335 , V_336 , V_337 ,
V_338 , NULL ) ;
}
static int F_134 ( struct V_20 * V_339 ,
struct V_20 * V_340 )
{
T_2 V_335 = F_22 () ;
T_2 V_341 = F_18 ( V_339 ) ;
T_2 V_342 = F_18 ( V_340 ) ;
int V_53 ;
if ( V_335 != V_341 ) {
V_53 = F_46 ( V_335 , V_341 , V_337 ,
V_343 , NULL ) ;
if ( V_53 )
return V_53 ;
}
return F_46 ( V_341 , V_342 , V_337 , V_344 ,
NULL ) ;
}
static int F_135 ( struct V_20 * V_339 ,
struct V_20 * V_340 )
{
T_2 V_341 = F_18 ( V_339 ) ;
T_2 V_342 = F_18 ( V_340 ) ;
return F_46 ( V_341 , V_342 , V_337 , V_345 ,
NULL ) ;
}
static int F_136 ( struct V_20 * V_339 ,
struct V_20 * V_340 ,
struct V_42 * V_42 )
{
T_2 V_17 = F_18 ( V_340 ) ;
struct V_43 * V_44 = V_42 -> V_46 ;
struct V_22 * V_22 = F_50 ( V_42 -> V_280 . V_64 ) ;
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_265 V_266 ;
int V_53 ;
V_266 . type = V_279 ;
V_266 . V_271 . V_231 = V_42 -> V_280 ;
if ( V_17 != V_44 -> V_17 ) {
V_53 = F_46 ( V_17 , V_44 -> V_17 ,
V_281 ,
V_282 ,
& V_266 ) ;
if ( V_53 )
return V_53 ;
}
if ( F_116 ( F_55 ( V_22 ) ) )
return 0 ;
return F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , F_131 ( V_42 ) ,
& V_266 ) ;
}
static int F_137 ( struct V_20 * V_346 ,
unsigned int V_167 )
{
int V_53 ;
V_53 = F_138 ( V_346 , V_167 ) ;
if ( V_53 )
return V_53 ;
if ( V_167 & V_347 ) {
T_2 V_17 = F_22 () ;
T_2 V_348 = F_18 ( V_346 ) ;
return F_46 ( V_17 , V_348 , V_32 , V_319 , NULL ) ;
}
return F_107 ( V_346 , V_349 ) ;
}
static int F_139 ( struct V_20 * V_350 )
{
int V_53 ;
V_53 = F_140 ( V_350 ) ;
if ( V_53 )
return V_53 ;
return F_106 ( V_350 , V_11 , V_349 ) ;
}
static int F_141 ( struct V_20 * V_251 , T_6 * V_351 ,
T_6 * V_352 , T_6 * V_353 )
{
int error ;
error = F_107 ( V_251 , V_354 ) ;
if ( error )
return error ;
return F_142 ( V_251 , V_351 , V_352 , V_353 ) ;
}
static int F_143 ( struct V_10 * V_127 , const struct V_10 * V_126 ,
const T_6 * V_351 ,
const T_6 * V_352 ,
const T_6 * V_353 )
{
int error ;
error = F_144 ( V_127 , V_126 ,
V_351 , V_352 , V_353 ) ;
if ( error )
return error ;
return F_105 ( V_126 , V_127 , V_355 ) ;
}
static int F_145 ( const struct V_10 * V_10 , struct V_356 * V_357 ,
int V_263 , int V_264 )
{
int V_53 ;
V_53 = F_146 ( V_10 , V_357 , V_263 , V_264 ) ;
if ( V_53 )
return V_53 ;
return F_108 ( V_10 , V_263 , V_264 ) ;
}
static int F_147 ( int V_358 , int type , int V_359 , struct V_47 * V_48 )
{
const struct V_10 * V_10 = F_66 () ;
int V_53 = 0 ;
if ( ! V_48 )
return 0 ;
switch ( V_358 ) {
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
V_53 = F_128 ( V_10 , V_48 , V_365 , NULL ) ;
break;
case V_366 :
case V_367 :
case V_368 :
V_53 = F_128 ( V_10 , V_48 , V_369 , NULL ) ;
break;
default:
V_53 = 0 ;
break;
}
return V_53 ;
}
static int F_148 ( struct V_64 * V_64 )
{
const struct V_10 * V_10 = F_66 () ;
return F_117 ( V_10 , V_64 , V_370 ) ;
}
static int F_149 ( int type )
{
int V_53 ;
switch ( type ) {
case V_371 :
case V_372 :
V_53 = F_113 ( V_11 , V_373 ) ;
break;
case V_374 :
case V_375 :
case V_376 :
V_53 = F_113 ( V_11 , V_377 ) ;
break;
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_382 :
default:
V_53 = F_113 ( V_11 , V_383 ) ;
break;
}
return V_53 ;
}
static int F_150 ( struct V_384 * V_385 , long V_386 )
{
int V_53 , V_387 = 0 ;
V_53 = F_145 ( F_66 () , & V_388 , V_389 ,
V_390 ) ;
if ( V_53 == 0 )
V_387 = 1 ;
return F_151 ( V_385 , V_386 , V_387 ) ;
}
static int F_152 ( const struct V_391 * V_392 ,
const struct V_13 * V_393 ,
const struct V_13 * V_394 )
{
int V_395 = ( V_392 -> V_396 & V_397 ) ;
int V_398 = ( V_392 -> V_42 -> V_280 . V_399 -> V_105 & V_400 ) ;
int V_53 ;
if ( ! V_395 && ! V_398 )
return 0 ;
if ( V_394 -> V_17 == V_393 -> V_17 )
return 0 ;
V_53 = F_153 ( V_393 -> V_17 , V_394 -> V_17 ) ;
if ( V_53 ) {
if ( V_395 )
return - V_401 ;
else
return - V_402 ;
}
return 0 ;
}
static int F_154 ( struct V_391 * V_392 )
{
const struct V_13 * V_393 ;
struct V_13 * V_394 ;
struct V_23 * V_24 ;
struct V_265 V_266 ;
struct V_22 * V_22 = F_120 ( V_392 -> V_42 ) ;
int V_53 ;
V_53 = F_155 ( V_392 ) ;
if ( V_53 )
return V_53 ;
if ( V_392 -> V_403 )
return 0 ;
V_393 = F_23 () ;
V_394 = V_392 -> V_10 -> V_19 ;
V_24 = V_22 -> V_33 ;
V_394 -> V_17 = V_393 -> V_17 ;
V_394 -> V_16 = V_393 -> V_17 ;
V_394 -> V_286 = 0 ;
V_394 -> V_404 = 0 ;
V_394 -> V_405 = 0 ;
if ( V_393 -> V_406 ) {
V_394 -> V_17 = V_393 -> V_406 ;
V_394 -> V_406 = 0 ;
V_53 = F_152 ( V_392 , V_393 , V_394 ) ;
if ( V_53 )
return V_53 ;
} else {
V_53 = F_102 ( V_393 -> V_17 , V_24 -> V_17 ,
V_255 , NULL ,
& V_394 -> V_17 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_152 ( V_392 , V_393 , V_394 ) ;
if ( V_53 )
V_394 -> V_17 = V_393 -> V_17 ;
}
V_266 . type = V_279 ;
V_266 . V_271 . V_231 = V_392 -> V_42 -> V_280 ;
if ( V_394 -> V_17 == V_393 -> V_17 ) {
V_53 = F_46 ( V_393 -> V_17 , V_24 -> V_17 ,
V_32 , V_407 , & V_266 ) ;
if ( V_53 )
return V_53 ;
} else {
V_53 = F_46 ( V_393 -> V_17 , V_394 -> V_17 ,
V_255 , V_408 , & V_266 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_394 -> V_17 , V_24 -> V_17 ,
V_32 , V_409 , & V_266 ) ;
if ( V_53 )
return V_53 ;
if ( V_392 -> V_396 & V_410 ) {
V_53 = F_46 ( V_393 -> V_17 , V_394 -> V_17 ,
V_255 , V_411 ,
NULL ) ;
if ( V_53 )
return - V_401 ;
}
if ( V_392 -> V_396 &
( V_412 | V_413 ) ) {
struct V_20 * V_414 ;
struct V_13 * V_415 ;
T_2 V_416 = 0 ;
F_19 () ;
V_414 = F_156 ( V_11 ) ;
if ( F_157 ( V_414 != NULL ) ) {
V_415 = F_20 ( V_414 ) -> V_19 ;
V_416 = V_415 -> V_17 ;
}
F_21 () ;
if ( V_416 != 0 ) {
V_53 = F_46 ( V_416 , V_394 -> V_17 ,
V_255 ,
V_349 , NULL ) ;
if ( V_53 )
return - V_401 ;
}
}
V_392 -> V_417 |= V_418 ;
}
return 0 ;
}
static int F_158 ( struct V_391 * V_392 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_17 , V_16 ;
int V_419 = 0 ;
V_17 = V_14 -> V_17 ;
V_16 = V_14 -> V_16 ;
if ( V_16 != V_17 ) {
V_419 = F_46 ( V_16 , V_17 ,
V_255 ,
V_420 , NULL ) ;
}
return ( V_419 || F_159 ( V_392 ) ) ;
}
static int F_160 ( const void * V_144 , struct V_42 * V_42 , unsigned V_421 )
{
return F_121 ( V_144 , V_42 , F_131 ( V_42 ) ) ? V_421 + 1 : 0 ;
}
static inline void F_161 ( const struct V_10 * V_10 ,
struct V_422 * V_423 )
{
struct V_42 * V_42 , * V_424 = NULL ;
struct V_425 * V_426 ;
int V_427 = 0 ;
unsigned V_428 ;
V_426 = F_162 () ;
if ( V_426 ) {
F_32 ( & V_429 ) ;
if ( ! F_33 ( & V_426 -> V_430 ) ) {
struct V_431 * V_432 ;
V_432 = F_163 ( & V_426 -> V_430 ,
struct V_431 , V_29 ) ;
V_42 = V_432 -> V_42 ;
if ( F_119 ( V_10 , V_42 , V_319 | V_323 ) )
V_427 = 1 ;
}
F_35 ( & V_429 ) ;
F_164 ( V_426 ) ;
}
if ( V_427 )
F_165 () ;
V_428 = F_166 ( V_423 , 0 , F_160 , V_10 ) ;
if ( ! V_428 )
return;
V_424 = F_167 ( & V_433 , V_434 , V_10 ) ;
if ( F_90 ( V_424 ) )
V_424 = NULL ;
do {
F_168 ( V_428 - 1 , V_424 , 0 ) ;
} while ( ( V_428 = F_166 ( V_423 , V_428 , F_160 , V_10 ) ) != 0 );
if ( V_424 )
F_169 ( V_424 ) ;
}
static void F_170 ( struct V_391 * V_392 )
{
struct V_13 * V_394 ;
struct V_435 * V_436 , * V_437 ;
int V_53 , V_85 ;
V_394 = V_392 -> V_10 -> V_19 ;
if ( V_394 -> V_17 == V_394 -> V_16 )
return;
F_161 ( V_392 -> V_10 , V_11 -> V_423 ) ;
V_11 -> V_438 = 0 ;
V_53 = F_46 ( V_394 -> V_16 , V_394 -> V_17 , V_255 ,
V_439 , NULL ) ;
if ( V_53 ) {
F_171 ( V_11 ) ;
for ( V_85 = 0 ; V_85 < V_440 ; V_85 ++ ) {
V_436 = V_11 -> signal -> V_436 + V_85 ;
V_437 = V_441 . signal -> V_436 + V_85 ;
V_436 -> V_442 = F_172 ( V_436 -> V_443 , V_437 -> V_442 ) ;
}
F_173 ( V_11 ) ;
F_174 ( V_11 , V_435 ( V_444 ) ) ;
}
}
static void F_175 ( struct V_391 * V_392 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_445 V_446 ;
T_2 V_16 , V_17 ;
int V_53 , V_85 ;
V_16 = V_14 -> V_16 ;
V_17 = V_14 -> V_17 ;
if ( V_17 == V_16 )
return;
V_53 = F_46 ( V_16 , V_17 , V_255 , V_447 , NULL ) ;
if ( V_53 ) {
memset ( & V_446 , 0 , sizeof V_446 ) ;
for ( V_85 = 0 ; V_85 < 3 ; V_85 ++ )
F_176 ( V_85 , & V_446 , NULL ) ;
F_177 ( & V_11 -> V_448 -> V_449 ) ;
if ( ! ( V_11 -> signal -> V_78 & V_450 ) ) {
F_178 ( V_11 ) ;
F_179 ( V_11 , 1 ) ;
F_180 ( & V_11 -> V_451 ) ;
}
F_181 ( & V_11 -> V_448 -> V_449 ) ;
}
F_182 ( & V_452 ) ;
F_183 ( V_11 , V_11 -> V_453 ) ;
F_184 ( & V_452 ) ;
}
static int F_185 ( struct V_47 * V_48 )
{
return F_40 ( V_48 ) ;
}
static void F_186 ( struct V_47 * V_48 )
{
F_42 ( V_48 ) ;
}
static inline int F_187 ( char * V_160 , int V_454 , char * V_455 , int V_456 )
{
if ( V_454 > V_456 )
return 0 ;
return ! memcmp ( V_160 , V_455 , V_454 ) ;
}
static inline int F_188 ( char * V_455 , int V_87 )
{
return ( F_187 ( V_162 , sizeof( V_162 ) - 1 , V_455 , V_87 ) ||
F_187 ( V_163 , sizeof( V_163 ) - 1 , V_455 , V_87 ) ||
F_187 ( V_165 , sizeof( V_165 ) - 1 , V_455 , V_87 ) ||
F_187 ( V_164 , sizeof( V_164 ) - 1 , V_455 , V_87 ) ||
F_187 ( V_166 , sizeof( V_166 ) - 1 , V_455 , V_87 ) ) ;
}
static inline void F_189 ( char * * V_340 , char * V_339 , int * V_457 , int V_87 )
{
if ( ! * V_457 ) {
* * V_340 = ',' ;
* V_340 += 1 ;
} else
* V_457 = 0 ;
memcpy ( * V_340 , V_339 , V_87 ) ;
* V_340 += V_87 ;
}
static inline void F_190 ( char * * V_340 , char * V_339 , int * V_457 ,
int V_87 )
{
int V_458 = 0 ;
if ( ! * V_457 ) {
* * V_340 = '|' ;
* V_340 += 1 ;
} else
* V_457 = 0 ;
while ( V_458 < V_87 ) {
if ( * V_339 != '"' ) {
* * V_340 = * V_339 ;
* V_340 += 1 ;
}
V_339 += 1 ;
V_458 += 1 ;
}
}
static int F_191 ( char * V_459 , char * V_460 )
{
int V_461 , V_44 , V_53 = 0 ;
char * V_462 , * V_463 , * V_464 ;
char * V_465 , * V_466 , * V_467 ;
int V_468 = 0 ;
V_463 = V_459 ;
V_465 = V_460 ;
V_467 = ( char * ) F_192 ( V_15 ) ;
if ( ! V_467 ) {
V_53 = - V_27 ;
goto V_73;
}
V_466 = V_467 ;
V_461 = V_44 = 1 ;
V_462 = V_464 = V_459 ;
do {
if ( * V_464 == '"' )
V_468 = ! V_468 ;
if ( ( * V_464 == ',' && V_468 == 0 ) ||
* V_464 == '\0' ) {
int V_87 = V_464 - V_463 ;
if ( F_188 ( V_463 , V_87 ) )
F_190 ( & V_465 , V_463 , & V_44 , V_87 ) ;
else
F_189 ( & V_467 , V_463 , & V_461 , V_87 ) ;
V_463 = V_464 + 1 ;
}
} while ( * V_464 ++ );
strcpy ( V_462 , V_466 ) ;
F_93 ( ( unsigned long ) V_466 ) ;
V_73:
return V_53 ;
}
static int F_193 ( struct V_47 * V_48 , void * V_157 )
{
int V_53 , V_85 , * V_78 ;
struct V_83 V_84 ;
char * V_469 , * * V_113 ;
struct V_37 * V_38 = V_48 -> V_40 ;
if ( ! ( V_38 -> V_78 & V_79 ) )
return 0 ;
if ( ! V_157 )
return 0 ;
if ( V_48 -> V_62 -> V_115 & V_116 )
return 0 ;
F_58 ( & V_84 ) ;
V_469 = F_194 () ;
if ( ! V_469 )
return - V_27 ;
V_53 = F_191 ( V_157 , V_469 ) ;
if ( V_53 )
goto V_470;
V_53 = F_73 ( V_469 , & V_84 ) ;
if ( V_53 )
goto V_470;
V_113 = V_84 . V_94 ;
V_78 = V_84 . V_97 ;
for ( V_85 = 0 ; V_85 < V_84 . V_93 ; V_85 ++ ) {
T_2 V_17 ;
T_7 V_87 ;
if ( V_78 [ V_85 ] == V_80 )
continue;
V_87 = strlen ( V_113 [ V_85 ] ) ;
V_53 = F_68 ( V_113 [ V_85 ] , V_87 , & V_17 ,
V_15 ) ;
if ( V_53 ) {
F_51 ( V_70 L_14
L_15 ,
V_113 [ V_85 ] , V_48 -> V_71 , V_48 -> V_62 -> V_63 , V_53 ) ;
goto V_471;
}
V_53 = - V_89 ;
switch ( V_78 [ V_85 ] ) {
case V_98 :
if ( F_64 ( V_38 , V_98 , V_38 -> V_17 , V_17 ) )
goto V_472;
break;
case V_99 :
if ( F_64 ( V_38 , V_99 , V_38 -> V_52 , V_17 ) )
goto V_472;
break;
case V_101 : {
struct V_23 * V_108 ;
V_108 = F_50 ( V_48 -> V_66 ) -> V_33 ;
if ( F_64 ( V_38 , V_101 , V_108 -> V_17 , V_17 ) )
goto V_472;
break;
}
case V_100 :
if ( F_64 ( V_38 , V_100 , V_38 -> V_50 , V_17 ) )
goto V_472;
break;
default:
goto V_471;
}
}
V_53 = 0 ;
V_471:
F_63 ( & V_84 ) ;
V_470:
F_195 ( V_469 ) ;
return V_53 ;
V_472:
F_51 ( V_70 L_36
L_37 , V_48 -> V_71 ,
V_48 -> V_62 -> V_63 ) ;
goto V_471;
}
static int F_196 ( struct V_47 * V_48 , int V_78 , void * V_157 )
{
const struct V_10 * V_10 = F_66 () ;
struct V_265 V_266 ;
int V_53 ;
V_53 = F_77 ( V_48 , V_157 ) ;
if ( V_53 )
return V_53 ;
if ( V_78 & V_473 )
return 0 ;
V_266 . type = V_278 ;
V_266 . V_271 . V_64 = V_48 -> V_66 ;
return F_128 ( V_10 , V_48 , V_474 , & V_266 ) ;
}
static int F_197 ( struct V_64 * V_64 )
{
const struct V_10 * V_10 = F_66 () ;
struct V_265 V_266 ;
V_266 . type = V_278 ;
V_266 . V_271 . V_64 = V_64 -> V_475 -> V_66 ;
return F_128 ( V_10 , V_64 -> V_475 , V_476 , & V_266 ) ;
}
static int F_198 ( const char * V_477 ,
struct V_231 * V_231 ,
const char * type ,
unsigned long V_78 ,
void * V_157 )
{
const struct V_10 * V_10 = F_66 () ;
if ( V_78 & V_478 )
return F_128 ( V_10 , V_231 -> V_64 -> V_475 ,
V_479 , NULL ) ;
else
return F_118 ( V_10 , V_231 , V_480 ) ;
}
static int F_199 ( struct V_481 * V_399 , int V_78 )
{
const struct V_10 * V_10 = F_66 () ;
return F_128 ( V_10 , V_399 -> V_482 ,
V_483 , NULL ) ;
}
static int F_200 ( struct V_22 * V_22 )
{
return F_24 ( V_22 ) ;
}
static void F_201 ( struct V_22 * V_22 )
{
F_31 ( V_22 ) ;
}
static int F_202 ( struct V_64 * V_64 , int V_167 ,
struct V_484 * V_63 , void * * V_292 ,
T_2 * V_485 )
{
const struct V_10 * V_10 = F_66 () ;
struct V_13 * V_14 ;
struct V_23 * V_284 ;
struct V_37 * V_38 ;
struct V_22 * V_283 = F_50 ( V_64 -> V_486 ) ;
T_2 V_285 ;
int V_53 ;
V_14 = V_10 -> V_19 ;
V_284 = V_283 -> V_33 ;
V_38 = V_283 -> V_39 -> V_40 ;
if ( V_14 -> V_286 && V_38 -> V_58 != V_122 ) {
V_285 = V_14 -> V_286 ;
} else {
V_53 = F_102 ( V_14 -> V_17 , V_284 -> V_17 ,
F_83 ( V_167 ) ,
V_63 ,
& V_285 ) ;
if ( V_53 ) {
F_51 ( V_70
L_38 ,
V_119 , - V_53 ) ;
return V_53 ;
}
}
return F_61 ( V_285 , ( char * * ) V_292 , V_485 ) ;
}
static int F_203 ( struct V_22 * V_22 , struct V_22 * V_283 ,
const struct V_484 * V_484 ,
const char * * V_63 ,
void * * V_487 , T_7 * V_87 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_284 ;
struct V_37 * V_38 ;
T_2 V_17 , V_285 , V_488 ;
int V_53 ;
char * V_86 ;
V_284 = V_283 -> V_33 ;
V_38 = V_283 -> V_39 -> V_40 ;
V_17 = V_14 -> V_17 ;
V_285 = V_14 -> V_286 ;
if ( ( V_38 -> V_78 & V_79 ) &&
( V_38 -> V_58 == V_122 ) )
V_285 = V_38 -> V_52 ;
else if ( ! V_285 || ! ( V_38 -> V_78 & V_80 ) ) {
V_53 = F_102 ( V_17 , V_284 -> V_17 ,
F_83 ( V_22 -> V_240 ) ,
V_484 , & V_285 ) ;
if ( V_53 ) {
F_51 ( V_70 L_39
L_40
L_41 ,
V_119 ,
- V_53 , V_22 -> V_39 -> V_71 , V_22 -> V_236 ) ;
return V_53 ;
}
}
if ( V_38 -> V_78 & V_79 ) {
struct V_23 * V_24 = V_22 -> V_33 ;
V_24 -> V_31 = F_83 ( V_22 -> V_240 ) ;
V_24 -> V_17 = V_285 ;
V_24 -> V_123 = 1 ;
}
if ( ! V_90 || ! ( V_38 -> V_78 & V_80 ) )
return - V_72 ;
if ( V_63 )
* V_63 = V_489 ;
if ( V_487 && V_87 ) {
V_53 = F_204 ( V_285 , & V_86 , & V_488 ) ;
if ( V_53 )
return V_53 ;
* V_487 = V_86 ;
* V_87 = V_488 ;
}
return 0 ;
}
static int F_205 ( struct V_22 * V_283 , struct V_64 * V_64 , T_5 V_167 )
{
return F_122 ( V_283 , V_64 , V_32 ) ;
}
static int F_206 ( struct V_64 * V_304 , struct V_22 * V_283 , struct V_64 * V_306 )
{
return F_124 ( V_283 , V_304 , V_297 ) ;
}
static int F_207 ( struct V_22 * V_283 , struct V_64 * V_64 )
{
return F_124 ( V_283 , V_64 , V_299 ) ;
}
static int F_208 ( struct V_22 * V_283 , struct V_64 * V_64 , const char * V_63 )
{
return F_122 ( V_283 , V_64 , V_172 ) ;
}
static int F_209 ( struct V_22 * V_283 , struct V_64 * V_64 , T_5 V_315 )
{
return F_122 ( V_283 , V_64 , V_177 ) ;
}
static int F_210 ( struct V_22 * V_283 , struct V_64 * V_64 )
{
return F_124 ( V_283 , V_64 , V_301 ) ;
}
static int F_211 ( struct V_22 * V_283 , struct V_64 * V_64 , T_5 V_167 , T_8 V_237 )
{
return F_122 ( V_283 , V_64 , F_83 ( V_167 ) ) ;
}
static int F_212 ( struct V_22 * V_490 , struct V_64 * V_304 ,
struct V_22 * V_491 , struct V_64 * V_306 )
{
return F_125 ( V_490 , V_304 , V_491 , V_306 ) ;
}
static int F_213 ( struct V_64 * V_64 )
{
const struct V_10 * V_10 = F_66 () ;
return F_117 ( V_10 , V_64 , V_319 ) ;
}
static int F_214 ( struct V_64 * V_64 , struct V_492 * V_492 )
{
const struct V_10 * V_10 = F_66 () ;
return F_117 ( V_10 , V_64 , V_319 ) ;
}
static T_9 int F_215 ( struct V_22 * V_22 ,
T_2 V_252 , T_2 V_493 , T_2 V_494 ,
int V_495 ,
unsigned V_78 )
{
struct V_265 V_266 ;
struct V_23 * V_24 = V_22 -> V_33 ;
int V_53 ;
V_266 . type = V_496 ;
V_266 . V_271 . V_22 = V_22 ;
V_53 = F_216 ( F_22 () , V_24 -> V_17 , V_24 -> V_31 , V_252 ,
V_493 , V_494 , V_495 , & V_266 , V_78 ) ;
if ( V_53 )
return V_53 ;
return 0 ;
}
static int F_217 ( struct V_22 * V_22 , int V_315 )
{
const struct V_10 * V_10 = F_66 () ;
T_2 V_252 ;
bool V_497 ;
unsigned V_78 = V_315 & V_498 ;
struct V_23 * V_24 ;
T_2 V_17 ;
struct V_267 V_268 ;
int V_53 , V_275 ;
T_2 V_493 , V_494 ;
V_497 = V_315 & V_499 ;
V_315 &= ( V_318 | V_322 | V_316 | V_320 ) ;
if ( ! V_315 )
return 0 ;
F_115 ( V_10 ) ;
if ( F_116 ( F_55 ( V_22 ) ) )
return 0 ;
V_252 = F_129 ( V_22 -> V_240 , V_315 ) ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
V_53 = F_111 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_252 , 0 , & V_268 ) ;
V_493 = F_218 ( V_252 , & V_268 , V_53 ,
V_497 ? V_500 : 0 ,
& V_494 ) ;
if ( F_157 ( ! V_493 ) )
return V_53 ;
V_275 = F_215 ( V_22 , V_252 , V_493 , V_494 , V_53 , V_78 ) ;
if ( V_275 )
return V_275 ;
return V_53 ;
}
static int F_219 ( struct V_64 * V_64 , struct V_501 * V_501 )
{
const struct V_10 * V_10 = F_66 () ;
unsigned int V_502 = V_501 -> V_502 ;
T_10 V_269 = V_323 ;
if ( V_502 & V_503 ) {
V_502 &= ~ ( V_504 | V_505 | V_506 |
V_503 ) ;
if ( ! V_502 )
return 0 ;
}
if ( V_502 & ( V_506 | V_507 | V_508 |
V_509 | V_510 | V_511 ) )
return F_117 ( V_10 , V_64 , V_512 ) ;
if ( V_332 && ( V_502 & V_513 ) )
V_269 |= V_333 ;
return F_117 ( V_10 , V_64 , V_269 ) ;
}
static int F_220 ( const struct V_231 * V_231 )
{
return F_118 ( F_66 () , V_231 , V_514 ) ;
}
static int F_221 ( struct V_64 * V_64 , const char * V_63 )
{
const struct V_10 * V_10 = F_66 () ;
if ( ! strncmp ( V_63 , V_515 ,
sizeof V_515 - 1 ) ) {
if ( ! strcmp ( V_63 , V_516 ) ) {
if ( ! F_222 ( V_517 ) )
return - V_401 ;
} else if ( ! F_222 ( V_389 ) ) {
return - V_401 ;
}
}
return F_117 ( V_10 , V_64 , V_512 ) ;
}
static int F_223 ( struct V_64 * V_64 , const char * V_63 ,
const void * V_487 , T_7 V_518 , int V_78 )
{
struct V_22 * V_22 = F_50 ( V_64 ) ;
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_37 * V_38 ;
struct V_265 V_266 ;
T_2 V_285 , V_17 = F_22 () ;
int V_53 = 0 ;
if ( strcmp ( V_63 , V_74 ) )
return F_221 ( V_64 , V_63 ) ;
V_38 = V_22 -> V_39 -> V_40 ;
if ( ! ( V_38 -> V_78 & V_80 ) )
return - V_72 ;
if ( ! F_224 ( V_22 ) )
return - V_401 ;
V_266 . type = V_278 ;
V_266 . V_271 . V_64 = V_64 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 ,
V_519 , & V_266 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_68 ( V_487 , V_518 , & V_285 , V_15 ) ;
if ( V_53 == - V_89 ) {
if ( ! F_222 ( V_520 ) ) {
struct V_521 * V_522 ;
T_7 V_523 ;
const char * V_1 ;
if ( V_487 ) {
V_1 = V_487 ;
if ( V_1 [ V_518 - 1 ] == '\0' )
V_523 = V_518 - 1 ;
else
V_523 = V_518 ;
} else {
V_1 = L_42 ;
V_523 = 0 ;
}
V_522 = F_225 ( V_11 -> V_524 , V_95 , V_525 ) ;
F_226 ( V_522 , L_43 ) ;
F_227 ( V_522 , V_487 , V_523 ) ;
F_228 ( V_522 ) ;
return V_53 ;
}
V_53 = F_229 ( V_487 , V_518 , & V_285 ) ;
}
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_17 , V_285 , V_24 -> V_31 ,
V_526 , & V_266 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_230 ( V_24 -> V_17 , V_285 , V_17 ,
V_24 -> V_31 ) ;
if ( V_53 )
return V_53 ;
return F_46 ( V_285 ,
V_38 -> V_17 ,
V_54 ,
V_57 ,
& V_266 ) ;
}
static void F_231 ( struct V_64 * V_64 , const char * V_63 ,
const void * V_487 , T_7 V_518 ,
int V_78 )
{
struct V_22 * V_22 = F_50 ( V_64 ) ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_285 ;
int V_53 ;
if ( strcmp ( V_63 , V_74 ) ) {
return;
}
V_53 = F_229 ( V_487 , V_518 , & V_285 ) ;
if ( V_53 ) {
F_51 ( V_77 L_44
L_45 ,
V_22 -> V_39 -> V_71 , V_22 -> V_236 , - V_53 ) ;
return;
}
V_24 -> V_31 = F_83 ( V_22 -> V_240 ) ;
V_24 -> V_17 = V_285 ;
V_24 -> V_123 = 1 ;
return;
}
static int F_232 ( struct V_64 * V_64 , const char * V_63 )
{
const struct V_10 * V_10 = F_66 () ;
return F_117 ( V_10 , V_64 , V_514 ) ;
}
static int F_233 ( struct V_64 * V_64 )
{
const struct V_10 * V_10 = F_66 () ;
return F_117 ( V_10 , V_64 , V_514 ) ;
}
static int F_234 ( struct V_64 * V_64 , const char * V_63 )
{
if ( strcmp ( V_63 , V_74 ) )
return F_221 ( V_64 , V_63 ) ;
return - V_402 ;
}
static int F_235 ( const struct V_22 * V_22 , const char * V_63 , void * * V_230 , bool V_527 )
{
T_2 V_518 ;
int error ;
char * V_86 = NULL ;
struct V_23 * V_24 = V_22 -> V_33 ;
if ( strcmp ( V_63 , V_489 ) )
return - V_72 ;
error = F_145 ( F_66 () , & V_388 , V_520 ,
V_390 ) ;
if ( ! error )
error = F_204 ( V_24 -> V_17 , & V_86 ,
& V_518 ) ;
else
error = F_61 ( V_24 -> V_17 , & V_86 , & V_518 ) ;
if ( error )
return error ;
error = V_518 ;
if ( V_527 ) {
* V_230 = V_86 ;
goto V_528;
}
F_39 ( V_86 ) ;
V_528:
return error ;
}
static int F_236 ( struct V_22 * V_22 , const char * V_63 ,
const void * V_487 , T_7 V_518 , int V_78 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_285 ;
int V_53 ;
if ( strcmp ( V_63 , V_489 ) )
return - V_72 ;
if ( ! V_487 || ! V_518 )
return - V_402 ;
V_53 = F_68 ( ( void * ) V_487 , V_518 , & V_285 , V_15 ) ;
if ( V_53 )
return V_53 ;
V_24 -> V_31 = F_83 ( V_22 -> V_240 ) ;
V_24 -> V_17 = V_285 ;
V_24 -> V_123 = 1 ;
return 0 ;
}
static int F_237 ( struct V_22 * V_22 , char * V_230 , T_7 V_529 )
{
const int V_87 = sizeof( V_74 ) ;
if ( V_230 && V_87 <= V_529 )
memcpy ( V_230 , V_74 , V_87 ) ;
return V_87 ;
}
static void F_238 ( const struct V_22 * V_22 , T_2 * V_530 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
* V_530 = V_24 -> V_17 ;
}
static int F_239 ( struct V_42 * V_42 , int V_315 )
{
const struct V_10 * V_10 = F_66 () ;
struct V_22 * V_22 = F_120 ( V_42 ) ;
if ( ( V_42 -> V_329 & V_330 ) && ( V_315 & V_322 ) )
V_315 |= V_320 ;
return F_121 ( V_10 , V_42 ,
F_129 ( V_22 -> V_240 , V_315 ) ) ;
}
static int F_240 ( struct V_42 * V_42 , int V_315 )
{
struct V_22 * V_22 = F_120 ( V_42 ) ;
struct V_43 * V_44 = V_42 -> V_46 ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 = F_22 () ;
if ( ! V_315 )
return 0 ;
if ( V_17 == V_44 -> V_17 && V_44 -> V_531 == V_24 -> V_17 &&
V_44 -> V_532 == F_241 () )
return 0 ;
return F_239 ( V_42 , V_315 ) ;
}
static int F_242 ( struct V_42 * V_42 )
{
return F_37 ( V_42 ) ;
}
static void F_243 ( struct V_42 * V_42 )
{
F_38 ( V_42 ) ;
}
static int F_244 ( struct V_42 * V_42 , unsigned int V_533 ,
unsigned long V_534 )
{
const struct V_10 * V_10 = F_66 () ;
int error = 0 ;
switch ( V_533 ) {
case V_535 :
case V_536 :
case V_537 :
case V_538 :
case V_539 :
error = F_121 ( V_10 , V_42 , V_514 ) ;
break;
case V_540 :
case V_541 :
error = F_121 ( V_10 , V_42 , V_512 ) ;
break;
case V_542 :
case V_543 :
error = F_121 ( V_10 , V_42 , 0 ) ;
break;
case V_544 :
case V_545 :
error = F_108 ( V_10 , V_546 ,
V_274 ) ;
break;
default:
error = F_121 ( V_10 , V_42 , V_331 ) ;
}
return error ;
}
static int F_245 ( struct V_42 * V_42 , unsigned long V_547 , int V_548 )
{
const struct V_10 * V_10 = F_66 () ;
int V_53 = 0 ;
if ( V_549 &&
( V_547 & V_550 ) && ( ! V_42 || ( ! V_548 && ( V_547 & V_551 ) ) ) ) {
V_53 = F_105 ( V_10 , V_10 , V_552 ) ;
if ( V_53 )
goto error;
}
if ( V_42 ) {
T_2 V_269 = V_319 ;
if ( V_548 && ( V_547 & V_551 ) )
V_269 |= V_323 ;
if ( V_547 & V_550 )
V_269 |= V_317 ;
return F_121 ( V_10 , V_42 , V_269 ) ;
}
error:
return V_53 ;
}
static int F_246 ( unsigned long V_553 )
{
int V_53 ;
V_53 = F_247 ( V_553 ) ;
if ( V_53 )
return V_53 ;
if ( V_553 < V_554 ) {
T_2 V_17 = F_22 () ;
V_53 = F_46 ( V_17 , V_17 , V_555 ,
V_556 , NULL ) ;
}
return V_53 ;
}
static int F_248 ( struct V_42 * V_42 , unsigned long V_557 ,
unsigned long V_547 , unsigned long V_78 )
{
if ( V_558 )
V_547 = V_557 ;
return F_245 ( V_42 , V_547 ,
( V_78 & V_559 ) == V_560 ) ;
}
static int F_249 ( struct V_561 * V_562 ,
unsigned long V_557 ,
unsigned long V_547 )
{
const struct V_10 * V_10 = F_66 () ;
if ( V_558 )
V_547 = V_557 ;
if ( V_549 &&
( V_547 & V_550 ) && ! ( V_562 -> V_563 & V_564 ) ) {
int V_53 = 0 ;
if ( V_562 -> V_565 >= V_562 -> V_566 -> V_567 &&
V_562 -> V_568 <= V_562 -> V_566 -> V_569 ) {
V_53 = F_105 ( V_10 , V_10 , V_570 ) ;
} else if ( ! V_562 -> V_571 &&
V_562 -> V_565 <= V_562 -> V_566 -> V_572 &&
V_562 -> V_568 >= V_562 -> V_566 -> V_572 ) {
V_53 = F_107 ( V_11 , V_573 ) ;
} else if ( V_562 -> V_571 && V_562 -> V_574 ) {
V_53 = F_121 ( V_10 , V_562 -> V_571 , V_575 ) ;
}
if ( V_53 )
return V_53 ;
}
return F_245 ( V_562 -> V_571 , V_547 , V_562 -> V_563 & V_576 ) ;
}
static int F_250 ( struct V_42 * V_42 , unsigned int V_533 )
{
const struct V_10 * V_10 = F_66 () ;
return F_121 ( V_10 , V_42 , V_577 ) ;
}
static int F_251 ( struct V_42 * V_42 , unsigned int V_533 ,
unsigned long V_534 )
{
const struct V_10 * V_10 = F_66 () ;
int V_578 = 0 ;
switch ( V_533 ) {
case V_579 :
if ( ( V_42 -> V_329 & V_330 ) && ! ( V_534 & V_330 ) ) {
V_578 = F_121 ( V_10 , V_42 , V_323 ) ;
break;
}
case V_580 :
case V_581 :
case V_582 :
case V_583 :
case V_584 :
case V_585 :
V_578 = F_121 ( V_10 , V_42 , 0 ) ;
break;
case V_586 :
case V_587 :
case V_588 :
case V_589 :
case V_590 :
case V_591 :
#if V_592 == 32
case V_593 :
case V_594 :
case V_595 :
#endif
V_578 = F_121 ( V_10 , V_42 , V_577 ) ;
break;
}
return V_578 ;
}
static void F_252 ( struct V_42 * V_42 )
{
struct V_43 * V_44 ;
V_44 = V_42 -> V_46 ;
V_44 -> V_45 = F_22 () ;
}
static int F_253 ( struct V_20 * V_262 ,
struct V_596 * V_597 , int V_598 )
{
struct V_42 * V_42 ;
T_2 V_17 = F_18 ( V_262 ) ;
T_2 V_242 ;
struct V_43 * V_44 ;
V_42 = F_29 ( V_597 , struct V_42 , V_599 ) ;
V_44 = V_42 -> V_46 ;
if ( ! V_598 )
V_242 = F_104 ( V_600 ) ;
else
V_242 = F_104 ( V_598 ) ;
return F_46 ( V_44 -> V_45 , V_17 ,
V_255 , V_242 , NULL ) ;
}
static int F_254 ( struct V_42 * V_42 )
{
const struct V_10 * V_10 = F_66 () ;
return F_121 ( V_10 , V_42 , F_131 ( V_42 ) ) ;
}
static int F_255 ( struct V_42 * V_42 , const struct V_10 * V_10 )
{
struct V_43 * V_44 ;
struct V_23 * V_24 ;
V_44 = V_42 -> V_46 ;
V_24 = F_120 ( V_42 ) -> V_33 ;
V_44 -> V_531 = V_24 -> V_17 ;
V_44 -> V_532 = F_241 () ;
return F_119 ( V_10 , V_42 , F_132 ( V_42 ) ) ;
}
static int F_256 ( unsigned long V_601 )
{
return F_107 ( V_11 , V_602 ) ;
}
static int F_257 ( struct V_10 * V_10 , T_11 V_603 )
{
struct V_13 * V_14 ;
V_14 = F_15 ( sizeof( struct V_13 ) , V_603 ) ;
if ( ! V_14 )
return - V_27 ;
V_10 -> V_19 = V_14 ;
return 0 ;
}
static void F_258 ( struct V_10 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_19 ;
F_62 ( V_10 -> V_19 && ( unsigned long ) V_10 -> V_19 < V_232 ) ;
V_10 -> V_19 = ( void * ) 0x7UL ;
F_39 ( V_14 ) ;
}
static int F_259 ( struct V_10 * V_127 , const struct V_10 * V_126 ,
T_11 V_603 )
{
const struct V_13 * V_393 ;
struct V_13 * V_14 ;
V_393 = V_126 -> V_19 ;
V_14 = F_260 ( V_393 , sizeof( struct V_13 ) , V_603 ) ;
if ( ! V_14 )
return - V_27 ;
V_127 -> V_19 = V_14 ;
return 0 ;
}
static void F_261 ( struct V_10 * V_127 , const struct V_10 * V_126 )
{
const struct V_13 * V_393 = V_126 -> V_19 ;
struct V_13 * V_14 = V_127 -> V_19 ;
* V_14 = * V_393 ;
}
static int F_262 ( struct V_10 * V_127 , T_2 V_530 )
{
struct V_13 * V_14 = V_127 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_604 ;
V_604 = F_46 ( V_17 , V_530 ,
V_605 ,
V_606 ,
NULL ) ;
if ( V_604 == 0 ) {
V_14 -> V_17 = V_530 ;
V_14 -> V_286 = 0 ;
V_14 -> V_404 = 0 ;
V_14 -> V_405 = 0 ;
}
return V_604 ;
}
static int F_263 ( struct V_10 * V_127 , struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_13 * V_14 = V_127 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_604 ;
V_604 = F_46 ( V_17 , V_24 -> V_17 ,
V_605 ,
V_607 ,
NULL ) ;
if ( V_604 == 0 )
V_14 -> V_286 = V_24 -> V_17 ;
return V_604 ;
}
static int F_264 ( char * V_608 )
{
T_2 V_17 ;
struct V_265 V_266 ;
V_17 = F_18 ( V_11 ) ;
V_266 . type = V_609 ;
V_266 . V_271 . V_608 = V_608 ;
return F_46 ( V_17 , V_18 , V_276 ,
V_610 , & V_266 ) ;
}
static int F_265 ( struct V_20 * V_144 , T_12 V_611 )
{
return F_107 ( V_144 , V_612 ) ;
}
static int F_266 ( struct V_20 * V_144 )
{
return F_107 ( V_144 , V_613 ) ;
}
static int F_267 ( struct V_20 * V_144 )
{
return F_107 ( V_144 , V_614 ) ;
}
static void F_268 ( struct V_20 * V_144 , T_2 * V_530 )
{
* V_530 = F_18 ( V_144 ) ;
}
static int F_269 ( struct V_20 * V_144 , int V_615 )
{
int V_53 ;
V_53 = F_270 ( V_144 , V_615 ) ;
if ( V_53 )
return V_53 ;
return F_107 ( V_144 , V_616 ) ;
}
static int F_271 ( struct V_20 * V_144 , int V_617 )
{
int V_53 ;
V_53 = F_272 ( V_144 , V_617 ) ;
if ( V_53 )
return V_53 ;
return F_107 ( V_144 , V_616 ) ;
}
static int F_273 ( struct V_20 * V_144 )
{
return F_107 ( V_144 , V_618 ) ;
}
static int F_274 ( struct V_20 * V_144 , unsigned int V_619 ,
struct V_435 * V_620 )
{
struct V_435 * V_621 = V_144 -> signal -> V_436 + V_619 ;
if ( V_621 -> V_443 != V_620 -> V_443 )
return F_107 ( V_144 , V_622 ) ;
return 0 ;
}
static int F_275 ( struct V_20 * V_144 )
{
int V_53 ;
V_53 = F_276 ( V_144 ) ;
if ( V_53 )
return V_53 ;
return F_107 ( V_144 , V_616 ) ;
}
static int F_277 ( struct V_20 * V_144 )
{
return F_107 ( V_144 , V_618 ) ;
}
static int F_278 ( struct V_20 * V_144 )
{
return F_107 ( V_144 , V_616 ) ;
}
static int F_279 ( struct V_20 * V_144 , struct V_623 * V_624 ,
int V_241 , T_2 V_530 )
{
T_2 V_242 ;
int V_53 ;
if ( ! V_241 )
V_242 = V_625 ;
else
V_242 = F_104 ( V_241 ) ;
if ( V_530 )
V_53 = F_46 ( V_530 , F_18 ( V_144 ) ,
V_255 , V_242 , NULL ) ;
else
V_53 = F_107 ( V_144 , V_242 ) ;
return V_53 ;
}
static int F_280 ( struct V_20 * V_144 )
{
return F_106 ( V_144 , V_11 , V_244 ) ;
}
static void F_281 ( struct V_20 * V_144 ,
struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 = F_18 ( V_144 ) ;
V_24 -> V_17 = V_17 ;
V_24 -> V_123 = 1 ;
}
static int F_282 ( struct V_626 * V_627 ,
struct V_265 * V_266 , T_13 * V_628 )
{
int V_629 , V_630 , V_604 = - V_89 ;
struct V_631 V_632 , * V_633 ;
V_629 = F_283 ( V_627 ) ;
V_633 = F_284 ( V_627 , V_629 , sizeof( V_632 ) , & V_632 ) ;
if ( V_633 == NULL )
goto V_73;
V_630 = V_633 -> V_634 * 4 ;
if ( V_630 < sizeof( V_632 ) )
goto V_73;
V_266 -> V_271 . V_635 -> V_636 . V_637 = V_633 -> V_637 ;
V_266 -> V_271 . V_635 -> V_636 . V_638 = V_633 -> V_638 ;
V_604 = 0 ;
if ( V_628 )
* V_628 = V_633 -> V_182 ;
switch ( V_633 -> V_182 ) {
case V_184 : {
struct V_639 V_640 , * V_641 ;
if ( F_285 ( V_633 -> V_642 ) & V_643 )
break;
V_629 += V_630 ;
V_641 = F_284 ( V_627 , V_629 , sizeof( V_640 ) , & V_640 ) ;
if ( V_641 == NULL )
break;
V_266 -> V_271 . V_635 -> V_644 = V_641 -> V_645 ;
V_266 -> V_271 . V_635 -> V_646 = V_641 -> V_647 ;
break;
}
case V_185 : {
struct V_648 V_649 , * V_650 ;
if ( F_285 ( V_633 -> V_642 ) & V_643 )
break;
V_629 += V_630 ;
V_650 = F_284 ( V_627 , V_629 , sizeof( V_649 ) , & V_649 ) ;
if ( V_650 == NULL )
break;
V_266 -> V_271 . V_635 -> V_644 = V_650 -> V_645 ;
V_266 -> V_271 . V_635 -> V_646 = V_650 -> V_647 ;
break;
}
case V_651 : {
struct V_652 V_653 , * V_654 ;
if ( F_285 ( V_633 -> V_642 ) & V_643 )
break;
V_629 += V_630 ;
V_654 = F_284 ( V_627 , V_629 , sizeof( V_653 ) , & V_653 ) ;
if ( V_654 == NULL )
break;
V_266 -> V_271 . V_635 -> V_644 = V_654 -> V_655 ;
V_266 -> V_271 . V_635 -> V_646 = V_654 -> V_656 ;
break;
}
default:
break;
}
V_73:
return V_604 ;
}
static int F_286 ( struct V_626 * V_627 ,
struct V_265 * V_266 , T_13 * V_628 )
{
T_13 V_657 ;
int V_604 = - V_89 , V_629 ;
struct V_658 V_659 , * V_660 ;
T_14 V_642 ;
V_629 = F_283 ( V_627 ) ;
V_660 = F_284 ( V_627 , V_629 , sizeof( V_659 ) , & V_659 ) ;
if ( V_660 == NULL )
goto V_73;
V_266 -> V_271 . V_635 -> V_661 . V_637 = V_660 -> V_637 ;
V_266 -> V_271 . V_635 -> V_661 . V_638 = V_660 -> V_638 ;
V_604 = 0 ;
V_657 = V_660 -> V_657 ;
V_629 += sizeof( V_659 ) ;
V_629 = F_287 ( V_627 , V_629 , & V_657 , & V_642 ) ;
if ( V_629 < 0 )
goto V_73;
if ( V_628 )
* V_628 = V_657 ;
switch ( V_657 ) {
case V_184 : {
struct V_639 V_640 , * V_641 ;
V_641 = F_284 ( V_627 , V_629 , sizeof( V_640 ) , & V_640 ) ;
if ( V_641 == NULL )
break;
V_266 -> V_271 . V_635 -> V_644 = V_641 -> V_645 ;
V_266 -> V_271 . V_635 -> V_646 = V_641 -> V_647 ;
break;
}
case V_185 : {
struct V_648 V_649 , * V_650 ;
V_650 = F_284 ( V_627 , V_629 , sizeof( V_649 ) , & V_649 ) ;
if ( V_650 == NULL )
break;
V_266 -> V_271 . V_635 -> V_644 = V_650 -> V_645 ;
V_266 -> V_271 . V_635 -> V_646 = V_650 -> V_647 ;
break;
}
case V_651 : {
struct V_652 V_653 , * V_654 ;
V_654 = F_284 ( V_627 , V_629 , sizeof( V_653 ) , & V_653 ) ;
if ( V_654 == NULL )
break;
V_266 -> V_271 . V_635 -> V_644 = V_654 -> V_655 ;
V_266 -> V_271 . V_635 -> V_646 = V_654 -> V_656 ;
break;
}
default:
break;
}
V_73:
return V_604 ;
}
static int F_288 ( struct V_626 * V_627 , struct V_265 * V_266 ,
char * * V_662 , int V_663 , T_13 * V_628 )
{
char * V_664 ;
int V_604 ;
switch ( V_266 -> V_271 . V_635 -> V_186 ) {
case V_193 :
V_604 = F_282 ( V_627 , V_266 , V_628 ) ;
if ( V_604 )
goto V_665;
V_664 = ( char * ) ( V_663 ? & V_266 -> V_271 . V_635 -> V_636 . V_637 :
& V_266 -> V_271 . V_635 -> V_636 . V_638 ) ;
goto V_666;
#if F_289 ( V_667 ) || F_289 ( V_668 )
case V_194 :
V_604 = F_286 ( V_627 , V_266 , V_628 ) ;
if ( V_604 )
goto V_665;
V_664 = ( char * ) ( V_663 ? & V_266 -> V_271 . V_635 -> V_661 . V_637 :
& V_266 -> V_271 . V_635 -> V_661 . V_638 ) ;
goto V_666;
#endif
default:
V_664 = NULL ;
goto V_666;
}
V_665:
F_51 ( V_70
L_46
L_47 ) ;
return V_604 ;
V_666:
if ( V_662 )
* V_662 = V_664 ;
return 0 ;
}
static int F_290 ( struct V_626 * V_627 , T_4 V_186 , T_2 * V_17 )
{
int V_578 ;
T_2 V_669 ;
T_2 V_670 ;
T_2 V_671 ;
V_578 = F_291 ( V_627 , & V_669 ) ;
if ( F_116 ( V_578 ) )
return - V_402 ;
V_578 = F_292 ( V_627 , V_186 , & V_671 , & V_670 ) ;
if ( F_116 ( V_578 ) )
return - V_402 ;
V_578 = F_293 ( V_670 , V_671 , V_669 , V_17 ) ;
if ( F_116 ( V_578 ) ) {
F_51 ( V_70
L_48
L_49 ) ;
return - V_402 ;
}
return 0 ;
}
static int F_294 ( T_2 V_672 , T_2 V_673 , T_2 * V_674 )
{
int V_578 = 0 ;
if ( V_673 != V_675 )
V_578 = F_295 ( V_672 , V_673 , V_674 ) ;
else
* V_674 = V_672 ;
return V_578 ;
}
static int F_296 ( const struct V_13 * V_14 ,
T_4 V_676 , T_2 * V_677 )
{
if ( V_14 -> V_405 > V_675 ) {
* V_677 = V_14 -> V_405 ;
return 0 ;
}
return F_102 ( V_14 -> V_17 , V_14 -> V_17 , V_676 , NULL ,
V_677 ) ;
}
static int F_297 ( struct V_20 * V_21 , struct V_678 * V_679 , T_2 V_252 )
{
struct V_680 * V_681 = V_679 -> V_682 ;
struct V_265 V_266 ;
struct V_683 V_635 = { 0 ,} ;
T_2 V_254 = F_18 ( V_21 ) ;
if ( V_681 -> V_17 == V_18 )
return 0 ;
V_266 . type = V_684 ;
V_266 . V_271 . V_635 = & V_635 ;
V_266 . V_271 . V_635 -> V_679 = V_679 ;
return F_46 ( V_254 , V_681 -> V_17 , V_681 -> V_31 , V_252 , & V_266 ) ;
}
static int F_298 ( int V_186 , int type ,
int V_182 , int V_685 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_285 ;
T_4 V_676 ;
int V_53 ;
if ( V_685 )
return 0 ;
V_676 = F_86 ( V_186 , type , V_182 ) ;
V_53 = F_296 ( V_14 , V_676 , & V_285 ) ;
if ( V_53 )
return V_53 ;
return F_46 ( V_14 -> V_17 , V_285 , V_676 , V_686 , NULL ) ;
}
static int F_299 ( struct V_687 * V_678 , int V_186 ,
int type , int V_182 , int V_685 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_24 = F_300 ( V_678 ) -> V_33 ;
struct V_680 * V_681 ;
int V_578 = 0 ;
V_24 -> V_31 = F_86 ( V_186 , type , V_182 ) ;
if ( V_685 )
V_24 -> V_17 = V_18 ;
else {
V_578 = F_296 ( V_14 , V_24 -> V_31 , & ( V_24 -> V_17 ) ) ;
if ( V_578 )
return V_578 ;
}
V_24 -> V_123 = 1 ;
if ( V_678 -> V_679 ) {
V_681 = V_678 -> V_679 -> V_682 ;
V_681 -> V_17 = V_24 -> V_17 ;
V_681 -> V_31 = V_24 -> V_31 ;
V_578 = F_301 ( V_678 -> V_679 , V_186 ) ;
}
return V_578 ;
}
static int F_302 ( struct V_687 * V_678 , struct V_688 * V_689 , int V_690 )
{
struct V_678 * V_679 = V_678 -> V_679 ;
T_4 V_186 ;
int V_578 ;
V_578 = F_297 ( V_11 , V_679 , V_691 ) ;
if ( V_578 )
goto V_73;
V_186 = V_679 -> V_692 ;
if ( V_186 == V_193 || V_186 == V_194 ) {
char * V_664 ;
struct V_680 * V_681 = V_679 -> V_682 ;
struct V_265 V_266 ;
struct V_683 V_635 = { 0 ,} ;
struct V_693 * V_694 = NULL ;
struct V_695 * V_696 = NULL ;
unsigned short V_697 ;
T_2 V_17 , V_698 ;
if ( V_186 == V_193 ) {
V_694 = (struct V_693 * ) V_689 ;
V_697 = F_285 ( V_694 -> V_699 ) ;
V_664 = ( char * ) & V_694 -> V_700 . V_701 ;
} else {
V_696 = (struct V_695 * ) V_689 ;
V_697 = F_285 ( V_696 -> V_702 ) ;
V_664 = ( char * ) & V_696 -> V_703 . V_704 ;
}
if ( V_697 ) {
int V_705 , V_706 ;
F_303 ( F_304 ( V_679 ) , & V_705 , & V_706 ) ;
if ( V_697 < V_707 ( V_708, V_705 ) || V_697 > V_706 ) {
V_578 = F_305 ( V_679 -> V_709 ,
V_697 , & V_17 ) ;
if ( V_578 )
goto V_73;
V_266 . type = V_684 ;
V_266 . V_271 . V_635 = & V_635 ;
V_266 . V_271 . V_635 -> V_644 = F_306 ( V_697 ) ;
V_266 . V_271 . V_635 -> V_186 = V_186 ;
V_578 = F_46 ( V_681 -> V_17 , V_17 ,
V_681 -> V_31 ,
V_710 , & V_266 ) ;
if ( V_578 )
goto V_73;
}
}
switch ( V_681 -> V_31 ) {
case V_195 :
V_698 = V_711 ;
break;
case V_197 :
V_698 = V_712 ;
break;
case V_199 :
V_698 = V_713 ;
break;
default:
V_698 = V_714 ;
break;
}
V_578 = F_307 ( V_664 , V_186 , & V_17 ) ;
if ( V_578 )
goto V_73;
V_266 . type = V_684 ;
V_266 . V_271 . V_635 = & V_635 ;
V_266 . V_271 . V_635 -> V_644 = F_306 ( V_697 ) ;
V_266 . V_271 . V_635 -> V_186 = V_186 ;
if ( V_186 == V_193 )
V_266 . V_271 . V_635 -> V_636 . V_637 = V_694 -> V_700 . V_701 ;
else
V_266 . V_271 . V_635 -> V_661 . V_637 = V_696 -> V_703 ;
V_578 = F_46 ( V_681 -> V_17 , V_17 ,
V_681 -> V_31 , V_698 , & V_266 ) ;
if ( V_578 )
goto V_73;
}
V_73:
return V_578 ;
}
static int F_308 ( struct V_687 * V_678 , struct V_688 * V_689 , int V_690 )
{
struct V_678 * V_679 = V_678 -> V_679 ;
struct V_680 * V_681 = V_679 -> V_682 ;
int V_578 ;
V_578 = F_297 ( V_11 , V_679 , V_715 ) ;
if ( V_578 )
return V_578 ;
if ( V_681 -> V_31 == V_195 ||
V_681 -> V_31 == V_199 ) {
struct V_265 V_266 ;
struct V_683 V_635 = { 0 ,} ;
struct V_693 * V_694 = NULL ;
struct V_695 * V_696 = NULL ;
unsigned short V_697 ;
T_2 V_17 , V_242 ;
if ( V_679 -> V_692 == V_193 ) {
V_694 = (struct V_693 * ) V_689 ;
if ( V_690 < sizeof( struct V_693 ) )
return - V_89 ;
V_697 = F_285 ( V_694 -> V_699 ) ;
} else {
V_696 = (struct V_695 * ) V_689 ;
if ( V_690 < V_716 )
return - V_89 ;
V_697 = F_285 ( V_696 -> V_702 ) ;
}
V_578 = F_305 ( V_679 -> V_709 , V_697 , & V_17 ) ;
if ( V_578 )
goto V_73;
V_242 = ( V_681 -> V_31 == V_195 ) ?
V_717 : V_718 ;
V_266 . type = V_684 ;
V_266 . V_271 . V_635 = & V_635 ;
V_266 . V_271 . V_635 -> V_646 = F_306 ( V_697 ) ;
V_266 . V_271 . V_635 -> V_186 = V_679 -> V_692 ;
V_578 = F_46 ( V_681 -> V_17 , V_17 , V_681 -> V_31 , V_242 , & V_266 ) ;
if ( V_578 )
goto V_73;
}
V_578 = F_309 ( V_679 , V_689 ) ;
V_73:
return V_578 ;
}
static int F_310 ( struct V_687 * V_678 , int V_719 )
{
return F_297 ( V_11 , V_678 -> V_679 , V_720 ) ;
}
static int F_311 ( struct V_687 * V_678 , struct V_687 * V_721 )
{
int V_578 ;
struct V_23 * V_24 ;
struct V_23 * V_140 ;
V_578 = F_297 ( V_11 , V_678 -> V_679 , V_722 ) ;
if ( V_578 )
return V_578 ;
V_140 = F_300 ( V_721 ) -> V_33 ;
V_24 = F_300 ( V_678 ) -> V_33 ;
V_140 -> V_31 = V_24 -> V_31 ;
V_140 -> V_17 = V_24 -> V_17 ;
V_140 -> V_123 = 1 ;
return 0 ;
}
static int F_312 ( struct V_687 * V_678 , struct V_723 * V_724 ,
int V_518 )
{
return F_297 ( V_11 , V_678 -> V_679 , V_725 ) ;
}
static int F_313 ( struct V_687 * V_678 , struct V_723 * V_724 ,
int V_518 , int V_78 )
{
return F_297 ( V_11 , V_678 -> V_679 , V_726 ) ;
}
static int F_314 ( struct V_687 * V_678 )
{
return F_297 ( V_11 , V_678 -> V_679 , V_727 ) ;
}
static int F_315 ( struct V_687 * V_678 )
{
return F_297 ( V_11 , V_678 -> V_679 , V_727 ) ;
}
static int F_316 ( struct V_687 * V_678 , int V_728 , int V_729 )
{
int V_578 ;
V_578 = F_297 ( V_11 , V_678 -> V_679 , V_730 ) ;
if ( V_578 )
return V_578 ;
return F_317 ( V_678 , V_728 , V_729 ) ;
}
static int F_318 ( struct V_687 * V_678 , int V_728 ,
int V_729 )
{
return F_297 ( V_11 , V_678 -> V_679 , V_731 ) ;
}
static int F_319 ( struct V_687 * V_678 , int V_732 )
{
return F_297 ( V_11 , V_678 -> V_679 , V_733 ) ;
}
static int F_320 ( struct V_678 * V_678 ,
struct V_678 * V_734 ,
struct V_678 * V_735 )
{
struct V_680 * V_736 = V_678 -> V_682 ;
struct V_680 * V_737 = V_734 -> V_682 ;
struct V_680 * V_738 = V_735 -> V_682 ;
struct V_265 V_266 ;
struct V_683 V_635 = { 0 ,} ;
int V_578 ;
V_266 . type = V_684 ;
V_266 . V_271 . V_635 = & V_635 ;
V_266 . V_271 . V_635 -> V_679 = V_734 ;
V_578 = F_46 ( V_736 -> V_17 , V_737 -> V_17 ,
V_737 -> V_31 ,
V_739 , & V_266 ) ;
if ( V_578 )
return V_578 ;
V_738 -> V_740 = V_736 -> V_17 ;
V_578 = F_295 ( V_737 -> V_17 , V_736 -> V_17 ,
& V_738 -> V_17 ) ;
if ( V_578 )
return V_578 ;
V_736 -> V_740 = V_738 -> V_17 ;
return 0 ;
}
static int F_321 ( struct V_687 * V_678 ,
struct V_687 * V_734 )
{
struct V_680 * V_741 = V_678 -> V_679 -> V_682 ;
struct V_680 * V_742 = V_734 -> V_679 -> V_682 ;
struct V_265 V_266 ;
struct V_683 V_635 = { 0 ,} ;
V_266 . type = V_684 ;
V_266 . V_271 . V_635 = & V_635 ;
V_266 . V_271 . V_635 -> V_679 = V_734 -> V_679 ;
return F_46 ( V_741 -> V_17 , V_742 -> V_17 , V_742 -> V_31 , V_743 ,
& V_266 ) ;
}
static int F_322 ( struct V_635 * V_357 , int V_744 ,
char * V_664 , T_4 V_186 , T_2 V_740 ,
struct V_265 * V_266 )
{
int V_578 ;
T_2 V_745 ;
T_2 V_746 ;
V_578 = F_323 ( V_357 , V_744 , & V_745 ) ;
if ( V_578 )
return V_578 ;
V_578 = F_46 ( V_740 , V_745 ,
V_747 , V_748 , V_266 ) ;
if ( V_578 )
return V_578 ;
V_578 = F_307 ( V_664 , V_186 , & V_746 ) ;
if ( V_578 )
return V_578 ;
return F_46 ( V_740 , V_746 ,
V_749 , V_750 , V_266 ) ;
}
static int F_324 ( struct V_678 * V_679 , struct V_626 * V_627 ,
T_4 V_186 )
{
int V_578 = 0 ;
struct V_680 * V_681 = V_679 -> V_682 ;
T_2 V_672 = V_681 -> V_17 ;
struct V_265 V_266 ;
struct V_683 V_635 = { 0 ,} ;
char * V_664 ;
V_266 . type = V_684 ;
V_266 . V_271 . V_635 = & V_635 ;
V_266 . V_271 . V_635 -> V_751 = V_627 -> V_752 ;
V_266 . V_271 . V_635 -> V_186 = V_186 ;
V_578 = F_288 ( V_627 , & V_266 , & V_664 , 1 , NULL ) ;
if ( V_578 )
return V_578 ;
if ( F_4 () ) {
V_578 = F_46 ( V_672 , V_627 -> V_753 , V_754 ,
V_755 , & V_266 ) ;
if ( V_578 )
return V_578 ;
}
V_578 = F_325 ( V_681 , V_627 , V_186 , & V_266 ) ;
if ( V_578 )
return V_578 ;
V_578 = F_326 ( V_681 -> V_17 , V_627 , & V_266 ) ;
return V_578 ;
}
static int F_327 ( struct V_678 * V_679 , struct V_626 * V_627 )
{
int V_578 ;
struct V_680 * V_681 = V_679 -> V_682 ;
T_4 V_186 = V_679 -> V_692 ;
T_2 V_672 = V_681 -> V_17 ;
struct V_265 V_266 ;
struct V_683 V_635 = { 0 ,} ;
char * V_664 ;
T_13 V_756 ;
T_13 V_757 ;
if ( V_186 != V_193 && V_186 != V_194 )
return 0 ;
if ( V_186 == V_194 && V_627 -> V_182 == F_306 ( V_758 ) )
V_186 = V_193 ;
if ( ! V_759 )
return F_324 ( V_679 , V_627 , V_186 ) ;
V_756 = F_4 () ;
V_757 = F_6 () ;
if ( ! V_756 && ! V_757 )
return 0 ;
V_266 . type = V_684 ;
V_266 . V_271 . V_635 = & V_635 ;
V_266 . V_271 . V_635 -> V_751 = V_627 -> V_752 ;
V_266 . V_271 . V_635 -> V_186 = V_186 ;
V_578 = F_288 ( V_627 , & V_266 , & V_664 , 1 , NULL ) ;
if ( V_578 )
return V_578 ;
if ( V_757 ) {
T_2 V_740 ;
V_578 = F_290 ( V_627 , V_186 , & V_740 ) ;
if ( V_578 )
return V_578 ;
V_578 = F_322 ( F_304 ( V_679 ) , V_627 -> V_752 ,
V_664 , V_186 , V_740 , & V_266 ) ;
if ( V_578 ) {
F_328 ( V_627 , V_578 , 0 ) ;
return V_578 ;
}
V_578 = F_46 ( V_672 , V_740 , V_760 ,
V_761 , & V_266 ) ;
if ( V_578 ) {
F_328 ( V_627 , V_578 , 0 ) ;
return V_578 ;
}
}
if ( V_756 ) {
V_578 = F_46 ( V_672 , V_627 -> V_753 , V_754 ,
V_755 , & V_266 ) ;
if ( V_578 )
return V_578 ;
}
return V_578 ;
}
static int F_329 ( struct V_687 * V_678 , char T_15 * V_762 ,
int T_15 * V_763 , unsigned V_87 )
{
int V_578 = 0 ;
char * V_764 ;
T_2 V_765 ;
struct V_680 * V_681 = V_678 -> V_679 -> V_682 ;
T_2 V_740 = V_675 ;
if ( V_681 -> V_31 == V_190 ||
V_681 -> V_31 == V_195 )
V_740 = V_681 -> V_740 ;
if ( V_740 == V_675 )
return - V_766 ;
V_578 = F_61 ( V_740 , & V_764 , & V_765 ) ;
if ( V_578 )
return V_578 ;
if ( V_765 > V_87 ) {
V_578 = - V_235 ;
goto V_767;
}
if ( F_330 ( V_762 , V_764 , V_765 ) )
V_578 = - V_768 ;
V_767:
if ( F_331 ( V_765 , V_763 ) )
V_578 = - V_768 ;
F_39 ( V_764 ) ;
return V_578 ;
}
static int F_332 ( struct V_687 * V_678 , struct V_626 * V_627 , T_2 * V_530 )
{
T_2 V_769 = V_675 ;
T_4 V_186 ;
if ( V_627 && V_627 -> V_182 == F_306 ( V_758 ) )
V_186 = V_193 ;
else if ( V_627 && V_627 -> V_182 == F_306 ( V_770 ) )
V_186 = V_194 ;
else if ( V_678 )
V_186 = V_678 -> V_679 -> V_692 ;
else
goto V_73;
if ( V_678 && V_186 == V_187 )
F_238 ( F_300 ( V_678 ) , & V_769 ) ;
else if ( V_627 )
F_290 ( V_627 , V_186 , & V_769 ) ;
V_73:
* V_530 = V_769 ;
if ( V_769 == V_675 )
return - V_89 ;
return 0 ;
}
static int F_333 ( struct V_678 * V_679 , int V_186 , T_11 V_771 )
{
struct V_680 * V_681 ;
V_681 = F_15 ( sizeof( * V_681 ) , V_771 ) ;
if ( ! V_681 )
return - V_27 ;
V_681 -> V_740 = V_30 ;
V_681 -> V_17 = V_30 ;
F_334 ( V_681 ) ;
V_679 -> V_682 = V_681 ;
return 0 ;
}
static void F_335 ( struct V_678 * V_679 )
{
struct V_680 * V_681 = V_679 -> V_682 ;
V_679 -> V_682 = NULL ;
F_336 ( V_681 ) ;
F_39 ( V_681 ) ;
}
static void F_337 ( const struct V_678 * V_679 , struct V_678 * V_735 )
{
struct V_680 * V_681 = V_679 -> V_682 ;
struct V_680 * V_772 = V_735 -> V_682 ;
V_772 -> V_17 = V_681 -> V_17 ;
V_772 -> V_740 = V_681 -> V_740 ;
V_772 -> V_31 = V_681 -> V_31 ;
F_334 ( V_772 ) ;
}
static void F_338 ( struct V_678 * V_679 , T_2 * V_530 )
{
if ( ! V_679 )
* V_530 = V_773 ;
else {
struct V_680 * V_681 = V_679 -> V_682 ;
* V_530 = V_681 -> V_17 ;
}
}
static void F_339 ( struct V_678 * V_679 , struct V_687 * V_350 )
{
struct V_23 * V_24 = F_300 ( V_350 ) -> V_33 ;
struct V_680 * V_681 = V_679 -> V_682 ;
if ( V_679 -> V_692 == V_193 || V_679 -> V_692 == V_194 ||
V_679 -> V_692 == V_187 )
V_24 -> V_17 = V_681 -> V_17 ;
V_681 -> V_31 = V_24 -> V_31 ;
}
static int F_340 ( struct V_678 * V_679 , struct V_626 * V_627 ,
struct V_774 * V_775 )
{
struct V_680 * V_681 = V_679 -> V_682 ;
int V_578 ;
T_4 V_186 = V_775 -> V_776 -> V_186 ;
T_2 V_777 ;
T_2 V_778 ;
V_578 = F_290 ( V_627 , V_186 , & V_778 ) ;
if ( V_578 )
return V_578 ;
V_578 = F_294 ( V_681 -> V_17 , V_778 , & V_777 ) ;
if ( V_578 )
return V_578 ;
V_775 -> V_530 = V_777 ;
V_775 -> V_769 = V_778 ;
return F_341 ( V_775 , V_186 ) ;
}
static void F_342 ( struct V_678 * V_735 ,
const struct V_774 * V_775 )
{
struct V_680 * V_772 = V_735 -> V_682 ;
V_772 -> V_17 = V_775 -> V_530 ;
V_772 -> V_740 = V_775 -> V_769 ;
F_343 ( V_735 , V_775 -> V_776 -> V_186 ) ;
}
static void F_344 ( struct V_678 * V_679 , struct V_626 * V_627 )
{
T_4 V_186 = V_679 -> V_692 ;
struct V_680 * V_681 = V_679 -> V_682 ;
if ( V_186 == V_194 && V_627 -> V_182 == F_306 ( V_758 ) )
V_186 = V_193 ;
F_290 ( V_627 , V_186 , & V_681 -> V_740 ) ;
}
static int F_345 ( T_2 V_17 )
{
const struct V_13 * V_779 ;
T_2 V_254 ;
V_779 = F_23 () ;
V_254 = V_779 -> V_17 ;
return F_46 ( V_254 , V_17 , V_754 , V_780 , NULL ) ;
}
static void F_346 ( void )
{
F_347 ( & V_7 ) ;
}
static void F_348 ( void )
{
F_349 ( & V_7 ) ;
}
static void F_350 ( const struct V_774 * V_775 ,
struct V_781 * V_782 )
{
V_782 -> V_783 = V_775 -> V_530 ;
}
static int F_351 ( void * * V_19 )
{
struct V_784 * V_785 ;
V_785 = F_15 ( sizeof( * V_785 ) , V_15 ) ;
if ( ! V_785 )
return - V_27 ;
V_785 -> V_17 = F_22 () ;
* V_19 = V_785 ;
return 0 ;
}
static void F_352 ( void * V_19 )
{
F_39 ( V_19 ) ;
}
static int F_353 ( void )
{
T_2 V_17 = F_22 () ;
return F_46 ( V_17 , V_17 , V_786 , V_787 ,
NULL ) ;
}
static int F_354 ( void * V_19 )
{
struct V_784 * V_785 = V_19 ;
return F_46 ( F_22 () , V_785 -> V_17 , V_786 ,
V_788 , NULL ) ;
}
static int F_355 ( struct V_678 * V_679 , void * V_19 )
{
struct V_784 * V_785 = V_19 ;
struct V_680 * V_681 = V_679 -> V_682 ;
V_681 -> V_17 = V_785 -> V_17 ;
V_681 -> V_31 = V_786 ;
return 0 ;
}
static int F_356 ( void * V_19 )
{
struct V_784 * V_785 = V_19 ;
T_2 V_17 = F_22 () ;
int V_578 ;
V_578 = F_46 ( V_17 , V_785 -> V_17 , V_786 ,
V_789 , NULL ) ;
if ( V_578 )
return V_578 ;
V_578 = F_46 ( V_17 , V_17 , V_786 ,
V_790 , NULL ) ;
if ( V_578 )
return V_578 ;
V_785 -> V_17 = V_17 ;
return 0 ;
}
static int F_357 ( struct V_678 * V_679 , struct V_626 * V_627 )
{
int V_578 = 0 ;
T_2 V_242 ;
struct V_791 * V_792 ;
struct V_680 * V_681 = V_679 -> V_682 ;
if ( V_627 -> V_87 < V_793 ) {
V_578 = - V_89 ;
goto V_73;
}
V_792 = F_358 ( V_627 ) ;
V_578 = F_359 ( V_681 -> V_31 , V_792 -> V_794 , & V_242 ) ;
if ( V_578 ) {
if ( V_578 == - V_89 ) {
F_51 ( V_70
L_50
L_51 ,
V_679 -> V_709 , V_792 -> V_794 , V_681 -> V_31 ) ;
if ( ! V_3 || F_360 () )
V_578 = 0 ;
}
if ( V_578 == - V_795 )
V_578 = 0 ;
goto V_73;
}
V_578 = F_297 ( V_11 , V_679 , V_242 ) ;
V_73:
return V_578 ;
}
static unsigned int F_361 ( struct V_626 * V_627 ,
const struct V_796 * V_797 ,
T_4 V_186 )
{
int V_578 ;
char * V_664 ;
T_2 V_740 ;
struct V_265 V_266 ;
struct V_683 V_635 = { 0 ,} ;
T_13 V_756 ;
T_13 V_798 ;
T_13 V_757 ;
if ( ! V_759 )
return V_799 ;
V_756 = F_4 () ;
V_798 = F_7 () ;
V_757 = F_6 () ;
if ( ! V_756 && ! V_757 )
return V_799 ;
if ( F_290 ( V_627 , V_186 , & V_740 ) != 0 )
return V_800 ;
V_266 . type = V_684 ;
V_266 . V_271 . V_635 = & V_635 ;
V_266 . V_271 . V_635 -> V_751 = V_797 -> V_744 ;
V_266 . V_271 . V_635 -> V_186 = V_186 ;
if ( F_288 ( V_627 , & V_266 , & V_664 , 1 , NULL ) != 0 )
return V_800 ;
if ( V_757 ) {
V_578 = F_322 ( F_362 ( V_797 ) , V_797 -> V_744 ,
V_664 , V_186 , V_740 , & V_266 ) ;
if ( V_578 ) {
F_328 ( V_627 , V_578 , 1 ) ;
return V_800 ;
}
}
if ( V_756 )
if ( F_46 ( V_740 , V_627 -> V_753 ,
V_754 , V_801 , & V_266 ) )
return V_800 ;
if ( V_798 )
if ( F_363 ( V_627 , V_186 , V_740 ) != 0 )
return V_800 ;
return V_799 ;
}
static unsigned int F_364 ( const struct V_802 * V_803 ,
struct V_626 * V_627 ,
const struct V_804 * V_805 )
{
return F_361 ( V_627 , V_805 -> V_806 , V_193 ) ;
}
static unsigned int F_365 ( const struct V_802 * V_803 ,
struct V_626 * V_627 ,
const struct V_804 * V_805 )
{
return F_361 ( V_627 , V_805 -> V_806 , V_194 ) ;
}
static unsigned int F_366 ( struct V_626 * V_627 ,
T_4 V_186 )
{
struct V_678 * V_679 ;
T_2 V_17 ;
if ( ! F_7 () )
return V_799 ;
V_679 = V_627 -> V_679 ;
if ( V_679 ) {
struct V_680 * V_681 ;
if ( V_679 -> V_807 == V_808 )
return V_799 ;
V_681 = V_679 -> V_682 ;
V_17 = V_681 -> V_17 ;
} else
V_17 = V_18 ;
if ( F_363 ( V_627 , V_186 , V_17 ) != 0 )
return V_800 ;
return V_799 ;
}
static unsigned int F_367 ( const struct V_802 * V_803 ,
struct V_626 * V_627 ,
const struct V_804 * V_805 )
{
return F_366 ( V_627 , V_193 ) ;
}
static unsigned int F_368 ( struct V_626 * V_627 ,
int V_744 ,
T_4 V_186 )
{
struct V_678 * V_679 = V_627 -> V_679 ;
struct V_680 * V_681 ;
struct V_265 V_266 ;
struct V_683 V_635 = { 0 ,} ;
char * V_664 ;
T_13 V_628 ;
if ( V_679 == NULL )
return V_799 ;
V_681 = V_679 -> V_682 ;
V_266 . type = V_684 ;
V_266 . V_271 . V_635 = & V_635 ;
V_266 . V_271 . V_635 -> V_751 = V_744 ;
V_266 . V_271 . V_635 -> V_186 = V_186 ;
if ( F_288 ( V_627 , & V_266 , & V_664 , 0 , & V_628 ) )
return V_800 ;
if ( F_4 () )
if ( F_46 ( V_681 -> V_17 , V_627 -> V_753 ,
V_754 , V_809 , & V_266 ) )
return F_369 ( - V_810 ) ;
if ( F_370 ( V_681 -> V_17 , V_627 , & V_266 , V_628 ) )
return F_369 ( - V_810 ) ;
return V_799 ;
}
static unsigned int F_371 ( struct V_626 * V_627 ,
const struct V_796 * V_811 ,
T_4 V_186 )
{
T_2 V_812 ;
T_2 V_740 ;
int V_744 = V_811 -> V_744 ;
struct V_678 * V_679 ;
struct V_265 V_266 ;
struct V_683 V_635 = { 0 ,} ;
char * V_664 ;
T_13 V_756 ;
T_13 V_757 ;
if ( ! V_759 )
return F_368 ( V_627 , V_744 , V_186 ) ;
V_756 = F_4 () ;
V_757 = F_6 () ;
if ( ! V_756 && ! V_757 )
return V_799 ;
V_679 = V_627 -> V_679 ;
#ifdef F_372
if ( F_373 ( V_627 ) != NULL && F_373 ( V_627 ) -> V_813 != NULL &&
! ( V_679 != NULL && V_679 -> V_807 == V_808 ) )
return V_799 ;
#endif
if ( V_679 == NULL ) {
if ( V_627 -> V_752 ) {
V_812 = V_814 ;
if ( F_290 ( V_627 , V_186 , & V_740 ) )
return V_800 ;
} else {
V_812 = V_809 ;
V_740 = V_18 ;
}
} else if ( V_679 -> V_807 == V_808 ) {
T_2 V_673 ;
struct V_680 * V_681 = V_679 -> V_682 ;
if ( F_290 ( V_627 , V_186 , & V_673 ) )
return V_800 ;
if ( V_673 == V_675 ) {
switch ( V_186 ) {
case V_193 :
if ( F_374 ( V_627 ) -> V_78 & V_815 )
return V_799 ;
break;
case V_194 :
if ( F_375 ( V_627 ) -> V_78 & V_816 )
return V_799 ;
break;
default:
return F_369 ( - V_810 ) ;
}
}
if ( F_294 ( V_681 -> V_17 , V_673 , & V_740 ) )
return V_800 ;
V_812 = V_809 ;
} else {
struct V_680 * V_681 = V_679 -> V_682 ;
V_740 = V_681 -> V_17 ;
V_812 = V_809 ;
}
V_266 . type = V_684 ;
V_266 . V_271 . V_635 = & V_635 ;
V_266 . V_271 . V_635 -> V_751 = V_744 ;
V_266 . V_271 . V_635 -> V_186 = V_186 ;
if ( F_288 ( V_627 , & V_266 , & V_664 , 0 , NULL ) )
return V_800 ;
if ( V_756 )
if ( F_46 ( V_740 , V_627 -> V_753 ,
V_754 , V_812 , & V_266 ) )
return F_369 ( - V_810 ) ;
if ( V_757 ) {
T_2 V_745 ;
T_2 V_746 ;
if ( F_323 ( F_362 ( V_811 ) , V_744 , & V_745 ) )
return V_800 ;
if ( F_46 ( V_740 , V_745 ,
V_747 , V_817 , & V_266 ) )
return F_369 ( - V_810 ) ;
if ( F_307 ( V_664 , V_186 , & V_746 ) )
return V_800 ;
if ( F_46 ( V_740 , V_746 ,
V_749 , V_818 , & V_266 ) )
return F_369 ( - V_810 ) ;
}
return V_799 ;
}
static unsigned int F_376 ( const struct V_802 * V_803 ,
struct V_626 * V_627 ,
const struct V_804 * V_805 )
{
return F_371 ( V_627 , V_805 -> V_73 , V_193 ) ;
}
static unsigned int F_377 ( const struct V_802 * V_803 ,
struct V_626 * V_627 ,
const struct V_804 * V_805 )
{
return F_371 ( V_627 , V_805 -> V_73 , V_194 ) ;
}
static int F_378 ( struct V_678 * V_679 , struct V_626 * V_627 )
{
int V_578 ;
V_578 = F_379 ( V_679 , V_627 ) ;
if ( V_578 )
return V_578 ;
return F_357 ( V_679 , V_627 ) ;
}
static int F_380 ( struct V_20 * V_21 ,
struct V_819 * V_242 ,
T_4 V_31 )
{
struct V_820 * V_24 ;
T_2 V_17 ;
V_24 = F_15 ( sizeof( struct V_820 ) , V_15 ) ;
if ( ! V_24 )
return - V_27 ;
V_17 = F_18 ( V_21 ) ;
V_24 -> V_31 = V_31 ;
V_24 -> V_17 = V_17 ;
V_242 -> V_19 = V_24 ;
return 0 ;
}
static void F_381 ( struct V_819 * V_242 )
{
struct V_820 * V_24 = V_242 -> V_19 ;
V_242 -> V_19 = NULL ;
F_39 ( V_24 ) ;
}
static int F_382 ( struct V_821 * V_724 )
{
struct V_822 * V_823 ;
V_823 = F_15 ( sizeof( struct V_822 ) , V_15 ) ;
if ( ! V_823 )
return - V_27 ;
V_823 -> V_17 = V_30 ;
V_724 -> V_19 = V_823 ;
return 0 ;
}
static void F_383 ( struct V_821 * V_724 )
{
struct V_822 * V_823 = V_724 -> V_19 ;
V_724 -> V_19 = NULL ;
F_39 ( V_823 ) ;
}
static int F_384 ( struct V_819 * V_824 ,
T_2 V_252 )
{
struct V_820 * V_24 ;
struct V_265 V_266 ;
T_2 V_17 = F_22 () ;
V_24 = V_824 -> V_19 ;
V_266 . type = V_825 ;
V_266 . V_271 . V_826 = V_824 -> V_827 ;
return F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_252 , & V_266 ) ;
}
static int F_385 ( struct V_821 * V_724 )
{
return F_382 ( V_724 ) ;
}
static void F_386 ( struct V_821 * V_724 )
{
F_383 ( V_724 ) ;
}
static int F_387 ( struct V_828 * V_829 )
{
struct V_820 * V_24 ;
struct V_265 V_266 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_53 = F_380 ( V_11 , & V_829 -> V_830 , V_831 ) ;
if ( V_53 )
return V_53 ;
V_24 = V_829 -> V_830 . V_19 ;
V_266 . type = V_825 ;
V_266 . V_271 . V_826 = V_829 -> V_830 . V_827 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_831 ,
V_832 , & V_266 ) ;
if ( V_53 ) {
F_381 ( & V_829 -> V_830 ) ;
return V_53 ;
}
return 0 ;
}
static void F_388 ( struct V_828 * V_829 )
{
F_381 ( & V_829 -> V_830 ) ;
}
static int F_389 ( struct V_828 * V_829 , int V_833 )
{
struct V_820 * V_24 ;
struct V_265 V_266 ;
T_2 V_17 = F_22 () ;
V_24 = V_829 -> V_830 . V_19 ;
V_266 . type = V_825 ;
V_266 . V_271 . V_826 = V_829 -> V_830 . V_827 ;
return F_46 ( V_17 , V_24 -> V_17 , V_831 ,
V_834 , & V_266 ) ;
}
static int F_390 ( struct V_828 * V_829 , int V_533 )
{
int V_578 ;
int V_252 ;
switch ( V_533 ) {
case V_835 :
case V_836 :
return F_113 ( V_11 , V_837 ) ;
case V_838 :
case V_839 :
V_252 = V_840 | V_834 ;
break;
case V_841 :
V_252 = V_842 ;
break;
case V_843 :
V_252 = V_844 ;
break;
default:
return 0 ;
}
V_578 = F_384 ( & V_829 -> V_830 , V_252 ) ;
return V_578 ;
}
static int F_391 ( struct V_828 * V_829 , struct V_821 * V_724 , int V_833 )
{
struct V_820 * V_24 ;
struct V_822 * V_823 ;
struct V_265 V_266 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_24 = V_829 -> V_830 . V_19 ;
V_823 = V_724 -> V_19 ;
if ( V_823 -> V_17 == V_30 ) {
V_53 = F_102 ( V_17 , V_24 -> V_17 , V_845 ,
NULL , & V_823 -> V_17 ) ;
if ( V_53 )
return V_53 ;
}
V_266 . type = V_825 ;
V_266 . V_271 . V_826 = V_829 -> V_830 . V_827 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_831 ,
V_846 , & V_266 ) ;
if ( ! V_53 )
V_53 = F_46 ( V_17 , V_823 -> V_17 , V_845 ,
V_847 , & V_266 ) ;
if ( ! V_53 )
V_53 = F_46 ( V_823 -> V_17 , V_24 -> V_17 , V_831 ,
V_848 , & V_266 ) ;
return V_53 ;
}
static int F_392 ( struct V_828 * V_829 , struct V_821 * V_724 ,
struct V_20 * V_251 ,
long type , int V_167 )
{
struct V_820 * V_24 ;
struct V_822 * V_823 ;
struct V_265 V_266 ;
T_2 V_17 = F_18 ( V_251 ) ;
int V_53 ;
V_24 = V_829 -> V_830 . V_19 ;
V_823 = V_724 -> V_19 ;
V_266 . type = V_825 ;
V_266 . V_271 . V_826 = V_829 -> V_830 . V_827 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 ,
V_831 , V_849 , & V_266 ) ;
if ( ! V_53 )
V_53 = F_46 ( V_17 , V_823 -> V_17 ,
V_845 , V_850 , & V_266 ) ;
return V_53 ;
}
static int F_393 ( struct V_851 * V_852 )
{
struct V_820 * V_24 ;
struct V_265 V_266 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_53 = F_380 ( V_11 , & V_852 -> V_853 , V_854 ) ;
if ( V_53 )
return V_53 ;
V_24 = V_852 -> V_853 . V_19 ;
V_266 . type = V_825 ;
V_266 . V_271 . V_826 = V_852 -> V_853 . V_827 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_854 ,
V_855 , & V_266 ) ;
if ( V_53 ) {
F_381 ( & V_852 -> V_853 ) ;
return V_53 ;
}
return 0 ;
}
static void F_394 ( struct V_851 * V_852 )
{
F_381 ( & V_852 -> V_853 ) ;
}
static int F_395 ( struct V_851 * V_852 , int V_856 )
{
struct V_820 * V_24 ;
struct V_265 V_266 ;
T_2 V_17 = F_22 () ;
V_24 = V_852 -> V_853 . V_19 ;
V_266 . type = V_825 ;
V_266 . V_271 . V_826 = V_852 -> V_853 . V_827 ;
return F_46 ( V_17 , V_24 -> V_17 , V_854 ,
V_857 , & V_266 ) ;
}
static int F_396 ( struct V_851 * V_852 , int V_533 )
{
int V_252 ;
int V_578 ;
switch ( V_533 ) {
case V_835 :
case V_858 :
return F_113 ( V_11 , V_837 ) ;
case V_838 :
case V_859 :
V_252 = V_860 | V_857 ;
break;
case V_841 :
V_252 = V_861 ;
break;
case V_862 :
case V_863 :
V_252 = V_864 ;
break;
case V_843 :
V_252 = V_865 ;
break;
default:
return 0 ;
}
V_578 = F_384 ( & V_852 -> V_853 , V_252 ) ;
return V_578 ;
}
static int F_397 ( struct V_851 * V_852 ,
char T_15 * V_866 , int V_856 )
{
T_2 V_252 ;
if ( V_856 & V_867 )
V_252 = V_868 ;
else
V_252 = V_868 | V_869 ;
return F_384 ( & V_852 -> V_853 , V_252 ) ;
}
static int F_398 ( struct V_870 * V_871 )
{
struct V_820 * V_24 ;
struct V_265 V_266 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_53 = F_380 ( V_11 , & V_871 -> V_872 , V_873 ) ;
if ( V_53 )
return V_53 ;
V_24 = V_871 -> V_872 . V_19 ;
V_266 . type = V_825 ;
V_266 . V_271 . V_826 = V_871 -> V_872 . V_827 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_873 ,
V_874 , & V_266 ) ;
if ( V_53 ) {
F_381 ( & V_871 -> V_872 ) ;
return V_53 ;
}
return 0 ;
}
static void F_399 ( struct V_870 * V_871 )
{
F_381 ( & V_871 -> V_872 ) ;
}
static int F_400 ( struct V_870 * V_871 , int V_875 )
{
struct V_820 * V_24 ;
struct V_265 V_266 ;
T_2 V_17 = F_22 () ;
V_24 = V_871 -> V_872 . V_19 ;
V_266 . type = V_825 ;
V_266 . V_271 . V_826 = V_871 -> V_872 . V_827 ;
return F_46 ( V_17 , V_24 -> V_17 , V_873 ,
V_876 , & V_266 ) ;
}
static int F_401 ( struct V_870 * V_871 , int V_533 )
{
int V_578 ;
T_2 V_252 ;
switch ( V_533 ) {
case V_835 :
case V_877 :
return F_113 ( V_11 , V_837 ) ;
case V_878 :
case V_879 :
case V_880 :
V_252 = V_881 ;
break;
case V_882 :
case V_883 :
V_252 = V_884 ;
break;
case V_885 :
case V_886 :
V_252 = V_887 ;
break;
case V_843 :
V_252 = V_888 ;
break;
case V_841 :
V_252 = V_889 ;
break;
case V_838 :
case V_890 :
V_252 = V_881 | V_876 ;
break;
default:
return 0 ;
}
V_578 = F_384 ( & V_871 -> V_872 , V_252 ) ;
return V_578 ;
}
static int F_402 ( struct V_870 * V_871 ,
struct V_891 * V_892 , unsigned V_893 , int V_894 )
{
T_2 V_252 ;
if ( V_894 )
V_252 = V_884 | V_887 ;
else
V_252 = V_884 ;
return F_384 ( & V_871 -> V_872 , V_252 ) ;
}
static int F_403 ( struct V_819 * V_895 , short V_102 )
{
T_2 V_269 = 0 ;
V_269 = 0 ;
if ( V_102 & V_896 )
V_269 |= V_897 ;
if ( V_102 & V_898 )
V_269 |= V_899 ;
if ( V_269 == 0 )
return 0 ;
return F_384 ( V_895 , V_269 ) ;
}
static void F_404 ( struct V_819 * V_895 , T_2 * V_530 )
{
struct V_820 * V_24 = V_895 -> V_19 ;
* V_530 = V_24 -> V_17 ;
}
static void F_405 ( struct V_64 * V_64 , struct V_22 * V_22 )
{
if ( V_22 )
F_44 ( V_22 , V_64 ) ;
}
static int F_406 ( struct V_20 * V_144 ,
char * V_63 , char * * V_487 )
{
const struct V_13 * V_779 ;
T_2 V_17 ;
int error ;
unsigned V_87 ;
if ( V_11 != V_144 ) {
error = F_107 ( V_144 , V_900 ) ;
if ( error )
return error ;
}
F_19 () ;
V_779 = F_20 ( V_144 ) -> V_19 ;
if ( ! strcmp ( V_63 , L_52 ) )
V_17 = V_779 -> V_17 ;
else if ( ! strcmp ( V_63 , L_53 ) )
V_17 = V_779 -> V_16 ;
else if ( ! strcmp ( V_63 , L_54 ) )
V_17 = V_779 -> V_406 ;
else if ( ! strcmp ( V_63 , L_55 ) )
V_17 = V_779 -> V_286 ;
else if ( ! strcmp ( V_63 , L_56 ) )
V_17 = V_779 -> V_404 ;
else if ( ! strcmp ( V_63 , L_57 ) )
V_17 = V_779 -> V_405 ;
else
goto V_901;
F_21 () ;
if ( ! V_17 )
return 0 ;
error = F_61 ( V_17 , V_487 , & V_87 ) ;
if ( error )
return error ;
return V_87 ;
V_901:
F_21 () ;
return - V_89 ;
}
static int F_407 ( struct V_20 * V_144 ,
char * V_63 , void * V_487 , T_7 V_518 )
{
struct V_13 * V_14 ;
struct V_20 * V_414 ;
struct V_10 * V_127 ;
T_2 V_17 = 0 , V_416 ;
int error ;
char * V_1 = V_487 ;
if ( V_11 != V_144 ) {
return - V_402 ;
}
if ( ! strcmp ( V_63 , L_54 ) )
error = F_107 ( V_144 , V_902 ) ;
else if ( ! strcmp ( V_63 , L_55 ) )
error = F_107 ( V_144 , V_903 ) ;
else if ( ! strcmp ( V_63 , L_56 ) )
error = F_107 ( V_144 , V_904 ) ;
else if ( ! strcmp ( V_63 , L_57 ) )
error = F_107 ( V_144 , V_905 ) ;
else if ( ! strcmp ( V_63 , L_52 ) )
error = F_107 ( V_144 , V_906 ) ;
else
error = - V_89 ;
if ( error )
return error ;
if ( V_518 && V_1 [ 1 ] && V_1 [ 1 ] != '\n' ) {
if ( V_1 [ V_518 - 1 ] == '\n' ) {
V_1 [ V_518 - 1 ] = 0 ;
V_518 -- ;
}
error = F_68 ( V_487 , V_518 , & V_17 , V_15 ) ;
if ( error == - V_89 && ! strcmp ( V_63 , L_55 ) ) {
if ( ! F_222 ( V_520 ) ) {
struct V_521 * V_522 ;
T_7 V_523 ;
if ( V_1 [ V_518 - 1 ] == '\0' )
V_523 = V_518 - 1 ;
else
V_523 = V_518 ;
V_522 = F_225 ( V_11 -> V_524 , V_95 , V_525 ) ;
F_226 ( V_522 , L_58 ) ;
F_227 ( V_522 , V_487 , V_523 ) ;
F_228 ( V_522 ) ;
return error ;
}
error = F_229 ( V_487 , V_518 ,
& V_17 ) ;
}
if ( error )
return error ;
}
V_127 = F_408 () ;
if ( ! V_127 )
return - V_27 ;
V_14 = V_127 -> V_19 ;
if ( ! strcmp ( V_63 , L_54 ) ) {
V_14 -> V_406 = V_17 ;
} else if ( ! strcmp ( V_63 , L_55 ) ) {
V_14 -> V_286 = V_17 ;
} else if ( ! strcmp ( V_63 , L_56 ) ) {
error = F_123 ( V_17 , V_144 ) ;
if ( error )
goto V_907;
V_14 -> V_404 = V_17 ;
} else if ( ! strcmp ( V_63 , L_57 ) ) {
V_14 -> V_405 = V_17 ;
} else if ( ! strcmp ( V_63 , L_52 ) ) {
error = - V_89 ;
if ( V_17 == 0 )
goto V_907;
error = - V_401 ;
if ( ! F_409 () ) {
error = F_153 ( V_14 -> V_17 , V_17 ) ;
if ( error )
goto V_907;
}
error = F_46 ( V_14 -> V_17 , V_17 , V_255 ,
V_908 , NULL ) ;
if ( error )
goto V_907;
V_416 = 0 ;
F_19 () ;
V_414 = F_156 ( V_144 ) ;
if ( V_414 )
V_416 = F_18 ( V_414 ) ;
F_21 () ;
if ( V_414 ) {
error = F_46 ( V_416 , V_17 , V_255 ,
V_349 , NULL ) ;
if ( error )
goto V_907;
}
V_14 -> V_17 = V_17 ;
} else {
error = - V_89 ;
goto V_907;
}
F_410 ( V_127 ) ;
return V_518 ;
V_907:
F_411 ( V_127 ) ;
return error ;
}
static int F_412 ( const char * V_63 )
{
return ( strcmp ( V_63 , V_489 ) == 0 ) ;
}
static int F_413 ( T_2 V_530 , char * * V_469 , T_2 * V_909 )
{
return F_61 ( V_530 , V_469 , V_909 ) ;
}
static int F_414 ( const char * V_469 , T_2 V_909 , T_2 * V_530 )
{
return F_68 ( V_469 , V_909 , V_530 , V_15 ) ;
}
static void F_415 ( char * V_469 , T_2 V_909 )
{
F_39 ( V_469 ) ;
}
static int F_416 ( struct V_22 * V_22 , void * V_292 , T_2 V_485 )
{
return F_236 ( V_22 , V_489 , V_292 , V_485 , 0 ) ;
}
static int F_417 ( struct V_64 * V_64 , void * V_292 , T_2 V_485 )
{
return F_418 ( V_64 , V_74 , V_292 , V_485 , 0 ) ;
}
static int F_419 ( struct V_22 * V_22 , void * * V_292 , T_2 * V_485 )
{
int V_87 = 0 ;
V_87 = F_235 ( V_22 , V_489 ,
V_292 , true ) ;
if ( V_87 < 0 )
return V_87 ;
* V_485 = V_87 ;
return 0 ;
}
static int F_420 ( struct V_827 * V_910 , const struct V_10 * V_10 ,
unsigned long V_78 )
{
const struct V_13 * V_14 ;
struct V_911 * V_912 ;
V_912 = F_15 ( sizeof( struct V_911 ) , V_15 ) ;
if ( ! V_912 )
return - V_27 ;
V_14 = V_10 -> V_19 ;
if ( V_14 -> V_404 )
V_912 -> V_17 = V_14 -> V_404 ;
else
V_912 -> V_17 = V_14 -> V_17 ;
V_910 -> V_19 = V_912 ;
return 0 ;
}
static void F_421 ( struct V_827 * V_910 )
{
struct V_911 * V_912 = V_910 -> V_19 ;
V_910 -> V_19 = NULL ;
F_39 ( V_912 ) ;
}
static int F_422 ( T_16 V_913 ,
const struct V_10 * V_10 ,
unsigned V_242 )
{
struct V_827 * V_827 ;
struct V_911 * V_912 ;
T_2 V_17 ;
if ( V_242 == 0 )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_827 = F_423 ( V_913 ) ;
V_912 = V_827 -> V_19 ;
return F_46 ( V_17 , V_912 -> V_17 , V_293 , V_242 , NULL ) ;
}
static int F_424 ( struct V_827 * V_827 , char * * V_914 )
{
struct V_911 * V_912 = V_827 -> V_19 ;
char * V_86 = NULL ;
unsigned V_87 ;
int V_53 ;
V_53 = F_61 ( V_912 -> V_17 , & V_86 , & V_87 ) ;
if ( ! V_53 )
V_53 = V_87 ;
* V_914 = V_86 ;
return V_53 ;
}
static T_1 int F_425 ( void )
{
if ( ! F_426 ( & V_915 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_51 ( V_916 L_59 ) ;
return 0 ;
}
F_51 ( V_916 L_60 ) ;
F_14 () ;
V_549 = ! ( V_917 & V_564 ) ;
V_25 = F_427 ( L_61 ,
sizeof( struct V_23 ) ,
0 , V_918 , NULL ) ;
F_428 () ;
if ( F_429 ( & V_915 ) )
F_16 ( L_62 ) ;
if ( F_430 ( F_9 , V_9 ) )
F_16 ( L_63 ) ;
if ( V_3 )
F_51 ( V_919 L_64 ) ;
else
F_51 ( V_919 L_65 ) ;
return 0 ;
}
static void F_431 ( struct V_47 * V_48 , void * V_920 )
{
F_77 ( V_48 , NULL ) ;
}
void F_432 ( void )
{
F_51 ( V_919 L_66 ) ;
F_51 ( V_919 L_67 ) ;
F_433 ( F_431 , NULL ) ;
}
static int T_1 F_434 ( void )
{
int V_578 ;
if ( ! V_5 )
return 0 ;
F_51 ( V_919 L_68 ) ;
V_578 = F_435 ( V_921 , F_52 ( V_921 ) ) ;
if ( V_578 )
F_16 ( L_69 , V_578 ) ;
return 0 ;
}
static void F_436 ( void )
{
F_51 ( V_919 L_70 ) ;
F_437 ( V_921 , F_52 ( V_921 ) ) ;
}
int F_438 ( void )
{
if ( V_90 ) {
return - V_89 ;
}
if ( V_922 ) {
return - V_89 ;
}
F_51 ( V_916 L_71 ) ;
V_922 = 1 ;
V_5 = 0 ;
F_439 () ;
F_440 () ;
F_436 () ;
F_441 () ;
return 0 ;
}
