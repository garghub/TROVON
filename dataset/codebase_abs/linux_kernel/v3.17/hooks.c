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
if ( V_38 -> V_58 == V_59 ||
V_38 -> V_58 == V_60 ||
V_38 -> V_58 == V_61 )
return 1 ;
if ( strncmp ( V_48 -> V_62 -> V_63 , L_2 , sizeof( L_2 ) ) == 0 )
return 1 ;
if ( strncmp ( V_48 -> V_62 -> V_63 , L_3 , sizeof( L_3 ) ) == 0 )
return 1 ;
return 0 ;
}
static int F_49 ( struct V_47 * V_48 )
{
struct V_37 * V_38 = V_48 -> V_40 ;
struct V_64 * V_65 = V_48 -> V_66 ;
struct V_22 * V_67 = V_65 -> V_68 ;
int V_53 = 0 ;
if ( V_38 -> V_58 == V_59 ) {
if ( ! V_67 -> V_69 -> V_70 ) {
F_50 ( V_71 L_4
L_5 , V_48 -> V_72 , V_48 -> V_62 -> V_63 ) ;
V_53 = - V_73 ;
goto V_74;
}
V_53 = V_67 -> V_69 -> V_70 ( V_65 , V_75 , NULL , 0 ) ;
if ( V_53 < 0 && V_53 != - V_76 ) {
if ( V_53 == - V_73 )
F_50 ( V_71 L_6
L_7 ,
V_48 -> V_72 , V_48 -> V_62 -> V_63 ) ;
else
F_50 ( V_71 L_6
L_8 , V_48 -> V_72 ,
V_48 -> V_62 -> V_63 , - V_53 ) ;
goto V_74;
}
}
if ( V_38 -> V_58 > F_51 ( V_77 ) )
F_50 ( V_78 L_9 ,
V_48 -> V_72 , V_48 -> V_62 -> V_63 ) ;
else
F_50 ( V_79 L_10 ,
V_48 -> V_72 , V_48 -> V_62 -> V_63 ,
V_77 [ V_38 -> V_58 - 1 ] ) ;
V_38 -> V_80 |= V_81 ;
if ( F_48 ( V_48 ) )
V_38 -> V_80 |= V_82 ;
V_53 = F_44 ( V_67 , V_65 ) ;
F_32 ( & V_38 -> V_41 ) ;
V_83:
if ( ! F_33 ( & V_38 -> V_49 ) ) {
struct V_23 * V_24 =
F_52 ( V_38 -> V_49 . V_84 ,
struct V_23 , V_29 ) ;
struct V_22 * V_22 = V_24 -> V_22 ;
F_35 ( & V_38 -> V_41 ) ;
V_22 = F_53 ( V_22 ) ;
if ( V_22 ) {
if ( ! F_54 ( V_22 ) )
F_43 ( V_22 ) ;
F_55 ( V_22 ) ;
}
F_32 ( & V_38 -> V_41 ) ;
F_34 ( & V_24 -> V_29 ) ;
goto V_83;
}
F_35 ( & V_38 -> V_41 ) ;
V_74:
return V_53 ;
}
static int F_56 ( const struct V_47 * V_48 ,
struct V_85 * V_86 )
{
int V_53 = 0 , V_87 ;
struct V_37 * V_38 = V_48 -> V_40 ;
char * V_88 = NULL ;
T_2 V_89 ;
char V_90 ;
F_57 ( V_86 ) ;
if ( ! ( V_38 -> V_80 & V_81 ) )
return - V_91 ;
if ( ! V_92 )
return - V_91 ;
F_58 ( V_93 >= ( 1 << V_94 ) ) ;
V_90 = V_38 -> V_80 & V_93 ;
for ( V_87 = 0 ; V_87 < V_94 ; V_87 ++ ) {
if ( V_90 & 0x01 )
V_86 -> V_95 ++ ;
V_90 >>= 1 ;
}
if ( V_38 -> V_80 & V_82 )
V_86 -> V_95 ++ ;
V_86 -> V_96 = F_59 ( V_86 -> V_95 , sizeof( char * ) , V_97 ) ;
if ( ! V_86 -> V_96 ) {
V_53 = - V_27 ;
goto V_98;
}
V_86 -> V_99 = F_59 ( V_86 -> V_95 , sizeof( int ) , V_97 ) ;
if ( ! V_86 -> V_99 ) {
V_53 = - V_27 ;
goto V_98;
}
V_87 = 0 ;
if ( V_38 -> V_80 & V_100 ) {
V_53 = F_60 ( V_38 -> V_17 , & V_88 , & V_89 ) ;
if ( V_53 )
goto V_98;
V_86 -> V_96 [ V_87 ] = V_88 ;
V_86 -> V_99 [ V_87 ++ ] = V_100 ;
}
if ( V_38 -> V_80 & V_101 ) {
V_53 = F_60 ( V_38 -> V_52 , & V_88 , & V_89 ) ;
if ( V_53 )
goto V_98;
V_86 -> V_96 [ V_87 ] = V_88 ;
V_86 -> V_99 [ V_87 ++ ] = V_101 ;
}
if ( V_38 -> V_80 & V_102 ) {
V_53 = F_60 ( V_38 -> V_50 , & V_88 , & V_89 ) ;
if ( V_53 )
goto V_98;
V_86 -> V_96 [ V_87 ] = V_88 ;
V_86 -> V_99 [ V_87 ++ ] = V_102 ;
}
if ( V_38 -> V_80 & V_103 ) {
struct V_22 * V_65 = V_38 -> V_48 -> V_66 -> V_68 ;
struct V_23 * V_24 = V_65 -> V_33 ;
V_53 = F_60 ( V_24 -> V_17 , & V_88 , & V_89 ) ;
if ( V_53 )
goto V_98;
V_86 -> V_96 [ V_87 ] = V_88 ;
V_86 -> V_99 [ V_87 ++ ] = V_103 ;
}
if ( V_38 -> V_80 & V_82 ) {
V_86 -> V_96 [ V_87 ] = NULL ;
V_86 -> V_99 [ V_87 ++ ] = V_82 ;
}
F_61 ( V_87 != V_86 -> V_95 ) ;
return 0 ;
V_98:
F_62 ( V_86 ) ;
return V_53 ;
}
static int F_63 ( struct V_37 * V_38 , char V_104 ,
T_2 V_105 , T_2 V_106 )
{
char V_107 = V_38 -> V_80 & V_93 ;
if ( V_38 -> V_80 & V_81 )
if ( ! ( V_38 -> V_80 & V_104 ) ||
( V_105 != V_106 ) )
return 1 ;
if ( ! ( V_38 -> V_80 & V_81 ) )
if ( V_107 & V_104 )
return 1 ;
return 0 ;
}
static int F_64 ( struct V_47 * V_48 ,
struct V_85 * V_86 ,
unsigned long V_108 ,
unsigned long * V_109 )
{
const struct V_10 * V_10 = F_65 () ;
int V_53 = 0 , V_87 ;
struct V_37 * V_38 = V_48 -> V_40 ;
const char * V_63 = V_48 -> V_62 -> V_63 ;
struct V_22 * V_22 = V_38 -> V_48 -> V_66 -> V_68 ;
struct V_23 * V_110 = V_22 -> V_33 ;
T_2 V_111 = 0 , V_112 = 0 , V_113 = 0 ;
T_2 V_114 = 0 ;
char * * V_115 = V_86 -> V_96 ;
int * V_80 = V_86 -> V_99 ;
int V_116 = V_86 -> V_95 ;
F_66 ( & V_38 -> V_28 ) ;
if ( ! V_92 ) {
if ( ! V_116 ) {
goto V_74;
}
V_53 = - V_91 ;
F_50 ( V_71 L_11
L_12 ) ;
goto V_74;
}
if ( V_108 && ! V_109 ) {
V_53 = - V_91 ;
goto V_74;
}
if ( ( V_38 -> V_80 & V_81 ) && ( V_48 -> V_62 -> V_117 & V_118 )
&& ( V_116 == 0 ) )
goto V_74;
for ( V_87 = 0 ; V_87 < V_116 ; V_87 ++ ) {
T_2 V_17 ;
if ( V_80 [ V_87 ] == V_82 )
continue;
V_53 = F_67 ( V_115 [ V_87 ] ,
strlen ( V_115 [ V_87 ] ) , & V_17 , V_15 ) ;
if ( V_53 ) {
F_50 ( V_71 L_13
L_14 ,
V_115 [ V_87 ] , V_48 -> V_72 , V_63 , V_53 ) ;
goto V_74;
}
switch ( V_80 [ V_87 ] ) {
case V_100 :
V_111 = V_17 ;
if ( F_63 ( V_38 , V_100 , V_38 -> V_17 ,
V_111 ) )
goto V_119;
V_38 -> V_80 |= V_100 ;
break;
case V_101 :
V_112 = V_17 ;
if ( F_63 ( V_38 , V_101 , V_38 -> V_52 ,
V_112 ) )
goto V_119;
V_38 -> V_80 |= V_101 ;
break;
case V_103 :
V_113 = V_17 ;
if ( F_63 ( V_38 , V_103 , V_110 -> V_17 ,
V_113 ) )
goto V_119;
V_38 -> V_80 |= V_103 ;
break;
case V_102 :
V_114 = V_17 ;
if ( F_63 ( V_38 , V_102 , V_38 -> V_50 ,
V_114 ) )
goto V_119;
V_38 -> V_80 |= V_102 ;
break;
default:
V_53 = - V_91 ;
goto V_74;
}
}
if ( V_38 -> V_80 & V_81 ) {
if ( ( V_38 -> V_80 & V_93 ) && ! V_116 )
goto V_119;
V_53 = 0 ;
goto V_74;
}
if ( strcmp ( V_48 -> V_62 -> V_63 , L_15 ) == 0 )
V_38 -> V_80 |= V_120 ;
if ( ! V_38 -> V_58 ) {
V_53 = F_68 ( V_48 ) ;
if ( V_53 ) {
F_50 ( V_71
L_16 ,
V_121 , V_48 -> V_62 -> V_63 , V_53 ) ;
goto V_74;
}
}
if ( V_111 ) {
V_53 = F_45 ( V_111 , V_38 , V_10 ) ;
if ( V_53 )
goto V_74;
V_38 -> V_17 = V_111 ;
}
if ( V_108 & V_122 && ! V_112 ) {
V_38 -> V_58 = V_123 ;
* V_109 |= V_122 ;
}
if ( V_112 ) {
if ( ! V_111 ) {
V_53 = F_45 ( V_112 , V_38 ,
V_10 ) ;
if ( V_53 )
goto V_74;
V_38 -> V_17 = V_112 ;
} else {
V_53 = F_47 ( V_112 , V_38 ,
V_10 ) ;
if ( V_53 )
goto V_74;
}
if ( ! V_113 )
V_113 = V_112 ;
V_38 -> V_52 = V_112 ;
V_38 -> V_58 = V_124 ;
}
if ( V_113 ) {
V_53 = F_47 ( V_113 , V_38 ,
V_10 ) ;
if ( V_53 )
goto V_74;
V_110 -> V_17 = V_113 ;
V_110 -> V_125 = 1 ;
}
if ( V_114 ) {
if ( V_38 -> V_58 != V_59 &&
V_38 -> V_58 != V_123 ) {
V_53 = - V_91 ;
F_50 ( V_71 L_17
L_18 ) ;
goto V_74;
}
if ( V_114 != V_38 -> V_50 ) {
V_53 = F_47 ( V_114 ,
V_38 , V_10 ) ;
if ( V_53 )
goto V_74;
}
V_38 -> V_50 = V_114 ;
}
V_53 = F_49 ( V_48 ) ;
V_74:
F_69 ( & V_38 -> V_28 ) ;
return V_53 ;
V_119:
V_53 = - V_91 ;
F_50 ( V_71 L_19
L_20 , V_48 -> V_72 , V_63 ) ;
goto V_74;
}
static int F_70 ( const struct V_47 * V_126 ,
const struct V_47 * V_127 )
{
struct V_37 * V_128 = V_126 -> V_40 ;
struct V_37 * V_129 = V_127 -> V_40 ;
char V_130 = V_128 -> V_80 & V_93 ;
char V_131 = V_129 -> V_80 & V_93 ;
if ( V_130 != V_131 )
goto V_132;
if ( ( V_130 & V_100 ) && V_128 -> V_17 != V_129 -> V_17 )
goto V_132;
if ( ( V_130 & V_101 ) && V_128 -> V_52 != V_129 -> V_52 )
goto V_132;
if ( ( V_130 & V_102 ) && V_128 -> V_50 != V_129 -> V_50 )
goto V_132;
if ( V_130 & V_103 ) {
struct V_23 * V_133 = V_126 -> V_66 -> V_68 -> V_33 ;
struct V_23 * V_134 = V_127 -> V_66 -> V_68 -> V_33 ;
if ( V_133 -> V_17 != V_134 -> V_17 )
goto V_132;
}
return 0 ;
V_132:
F_50 ( V_71 L_21
L_22
L_23 , V_127 -> V_72 , V_127 -> V_62 -> V_63 ) ;
return - V_135 ;
}
static int F_71 ( const struct V_47 * V_126 ,
struct V_47 * V_127 )
{
const struct V_37 * V_136 = V_126 -> V_40 ;
struct V_37 * V_137 = V_127 -> V_40 ;
int V_138 = ( V_136 -> V_80 & V_100 ) ;
int V_139 = ( V_136 -> V_80 & V_101 ) ;
int V_140 = ( V_136 -> V_80 & V_103 ) ;
if ( ! V_92 )
return 0 ;
F_61 ( ! ( V_136 -> V_80 & V_81 ) ) ;
if ( V_137 -> V_80 & V_81 )
return F_70 ( V_126 , V_127 ) ;
F_66 ( & V_137 -> V_28 ) ;
V_137 -> V_80 = V_136 -> V_80 ;
V_137 -> V_17 = V_136 -> V_17 ;
V_137 -> V_50 = V_136 -> V_50 ;
V_137 -> V_58 = V_136 -> V_58 ;
if ( V_139 ) {
T_2 V_17 = V_136 -> V_52 ;
if ( ! V_138 )
V_137 -> V_17 = V_17 ;
if ( ! V_140 ) {
struct V_22 * V_141 = V_127 -> V_66 -> V_68 ;
struct V_23 * V_142 = V_141 -> V_33 ;
V_142 -> V_17 = V_17 ;
}
V_137 -> V_52 = V_17 ;
}
if ( V_140 ) {
const struct V_22 * V_143 = V_126 -> V_66 -> V_68 ;
const struct V_23 * V_144 = V_143 -> V_33 ;
struct V_22 * V_141 = V_127 -> V_66 -> V_68 ;
struct V_23 * V_142 = V_141 -> V_33 ;
V_142 -> V_17 = V_144 -> V_17 ;
}
F_49 ( V_127 ) ;
F_69 ( & V_137 -> V_28 ) ;
return 0 ;
}
static int F_72 ( char * V_145 ,
struct V_85 * V_86 )
{
char * V_146 ;
char * V_88 = NULL , * V_147 = NULL ;
char * V_148 = NULL , * V_149 = NULL ;
int V_53 , V_95 = 0 ;
V_86 -> V_95 = 0 ;
while ( ( V_146 = F_73 ( & V_145 , L_24 ) ) != NULL ) {
int V_150 ;
T_3 args [ V_151 ] ;
if ( ! * V_146 )
continue;
V_150 = F_74 ( V_146 , V_152 , args ) ;
switch ( V_150 ) {
case V_153 :
if ( V_88 || V_147 ) {
V_53 = - V_91 ;
F_50 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_154;
}
V_88 = F_75 ( & args [ 0 ] ) ;
if ( ! V_88 ) {
V_53 = - V_27 ;
goto V_154;
}
break;
case V_155 :
if ( V_148 ) {
V_53 = - V_91 ;
F_50 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_154;
}
V_148 = F_75 ( & args [ 0 ] ) ;
if ( ! V_148 ) {
V_53 = - V_27 ;
goto V_154;
}
break;
case V_156 :
if ( V_149 ) {
V_53 = - V_91 ;
F_50 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_154;
}
V_149 = F_75 ( & args [ 0 ] ) ;
if ( ! V_149 ) {
V_53 = - V_27 ;
goto V_154;
}
break;
case V_157 :
if ( V_88 || V_147 ) {
V_53 = - V_91 ;
F_50 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_154;
}
V_147 = F_75 ( & args [ 0 ] ) ;
if ( ! V_147 ) {
V_53 = - V_27 ;
goto V_154;
}
break;
case V_158 :
break;
default:
V_53 = - V_91 ;
F_50 ( V_71 L_25 ) ;
goto V_154;
}
}
V_53 = - V_27 ;
V_86 -> V_96 = F_59 ( V_94 , sizeof( char * ) , V_97 ) ;
if ( ! V_86 -> V_96 )
goto V_154;
V_86 -> V_99 = F_59 ( V_94 , sizeof( int ) , V_97 ) ;
if ( ! V_86 -> V_99 ) {
F_39 ( V_86 -> V_96 ) ;
goto V_154;
}
if ( V_148 ) {
V_86 -> V_96 [ V_95 ] = V_148 ;
V_86 -> V_99 [ V_95 ++ ] = V_100 ;
}
if ( V_88 ) {
V_86 -> V_96 [ V_95 ] = V_88 ;
V_86 -> V_99 [ V_95 ++ ] = V_101 ;
}
if ( V_149 ) {
V_86 -> V_96 [ V_95 ] = V_149 ;
V_86 -> V_99 [ V_95 ++ ] = V_103 ;
}
if ( V_147 ) {
V_86 -> V_96 [ V_95 ] = V_147 ;
V_86 -> V_99 [ V_95 ++ ] = V_102 ;
}
V_86 -> V_95 = V_95 ;
return 0 ;
V_154:
F_39 ( V_88 ) ;
F_39 ( V_147 ) ;
F_39 ( V_148 ) ;
F_39 ( V_149 ) ;
return V_53 ;
}
static int F_76 ( struct V_47 * V_48 , void * V_159 )
{
int V_53 = 0 ;
char * V_145 = V_159 ;
struct V_85 V_86 ;
F_57 ( & V_86 ) ;
if ( ! V_159 )
goto V_74;
F_61 ( V_48 -> V_62 -> V_117 & V_118 ) ;
V_53 = F_72 ( V_145 , & V_86 ) ;
if ( V_53 )
goto V_154;
V_74:
V_53 = F_64 ( V_48 , & V_86 , 0 , NULL ) ;
V_154:
F_62 ( & V_86 ) ;
return V_53 ;
}
static void F_77 ( struct V_160 * V_161 ,
struct V_85 * V_86 )
{
int V_87 ;
char * V_162 ;
for ( V_87 = 0 ; V_87 < V_86 -> V_95 ; V_87 ++ ) {
char * V_163 ;
if ( V_86 -> V_96 [ V_87 ] )
V_163 = strchr ( V_86 -> V_96 [ V_87 ] , ',' ) ;
else
V_163 = NULL ;
switch ( V_86 -> V_99 [ V_87 ] ) {
case V_101 :
V_162 = V_164 ;
break;
case V_100 :
V_162 = V_165 ;
break;
case V_103 :
V_162 = V_166 ;
break;
case V_102 :
V_162 = V_167 ;
break;
case V_82 :
F_78 ( V_161 , ',' ) ;
F_79 ( V_161 , V_168 ) ;
continue;
default:
F_80 () ;
return;
} ;
F_78 ( V_161 , ',' ) ;
F_79 ( V_161 , V_162 ) ;
if ( V_163 )
F_78 ( V_161 , '\"' ) ;
F_79 ( V_161 , V_86 -> V_96 [ V_87 ] ) ;
if ( V_163 )
F_78 ( V_161 , '\"' ) ;
}
}
static int F_81 ( struct V_160 * V_161 , struct V_47 * V_48 )
{
struct V_85 V_86 ;
int V_53 ;
V_53 = F_56 ( V_48 , & V_86 ) ;
if ( V_53 ) {
if ( V_53 == - V_91 )
V_53 = 0 ;
return V_53 ;
}
F_77 ( V_161 , & V_86 ) ;
F_62 ( & V_86 ) ;
return V_53 ;
}
static inline T_4 F_82 ( T_5 V_169 )
{
switch ( V_169 & V_170 ) {
case V_171 :
return V_172 ;
case V_173 :
return V_174 ;
case V_175 :
return V_32 ;
case V_176 :
return V_177 ;
case V_178 :
return V_179 ;
case V_180 :
return V_181 ;
case V_182 :
return V_183 ;
}
return V_32 ;
}
static inline int F_83 ( int V_184 )
{
return ( V_184 == V_185 || V_184 == V_186 ) ;
}
static inline int F_84 ( int V_184 )
{
return ( V_184 == V_185 || V_184 == V_187 ) ;
}
static inline T_4 F_85 ( int V_188 , int type , int V_184 )
{
switch ( V_188 ) {
case V_189 :
switch ( type ) {
case V_190 :
case V_191 :
return V_192 ;
case V_193 :
return V_194 ;
}
break;
case V_195 :
case V_196 :
switch ( type ) {
case V_190 :
if ( F_83 ( V_184 ) )
return V_197 ;
else
return V_198 ;
case V_193 :
if ( F_84 ( V_184 ) )
return V_199 ;
else
return V_198 ;
case V_200 :
return V_201 ;
default:
return V_198 ;
}
break;
case V_202 :
switch ( V_184 ) {
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
case V_221 :
return V_222 ;
default:
return V_223 ;
}
case V_224 :
return V_225 ;
case V_226 :
return V_227 ;
case V_228 :
return V_229 ;
}
return V_230 ;
}
static int F_86 ( struct V_64 * V_64 ,
T_4 V_231 ,
T_2 * V_17 )
{
int V_53 ;
char * V_232 , * V_233 ;
V_232 = ( char * ) F_87 ( V_15 ) ;
if ( ! V_232 )
return - V_27 ;
V_233 = F_88 ( V_64 , V_232 , V_234 ) ;
if ( F_89 ( V_233 ) )
V_53 = F_90 ( V_233 ) ;
else {
while ( V_233 [ 1 ] >= '0' && V_233 [ 1 ] <= '9' ) {
V_233 [ 1 ] = '/' ;
V_233 ++ ;
}
V_53 = F_91 ( L_15 , V_233 , V_231 , V_17 ) ;
}
F_92 ( ( unsigned long ) V_232 ) ;
return V_53 ;
}
static int F_86 ( struct V_64 * V_64 ,
T_4 V_231 ,
T_2 * V_17 )
{
return - V_91 ;
}
static int F_44 ( struct V_22 * V_22 , struct V_64 * V_235 )
{
struct V_37 * V_38 = NULL ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 ;
struct V_64 * V_64 ;
#define F_93 255
char * V_88 = NULL ;
unsigned V_89 = 0 ;
int V_53 = 0 ;
if ( V_24 -> V_125 )
goto V_74;
F_66 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_125 )
goto V_236;
V_38 = V_22 -> V_39 -> V_40 ;
if ( ! ( V_38 -> V_80 & V_81 ) ) {
F_32 ( & V_38 -> V_41 ) ;
if ( F_33 ( & V_24 -> V_29 ) )
F_94 ( & V_24 -> V_29 , & V_38 -> V_49 ) ;
F_35 ( & V_38 -> V_41 ) ;
goto V_236;
}
switch ( V_38 -> V_58 ) {
case V_123 :
break;
case V_59 :
if ( ! V_22 -> V_69 -> V_70 ) {
V_24 -> V_17 = V_38 -> V_50 ;
break;
}
if ( V_235 ) {
V_64 = F_95 ( V_235 ) ;
} else {
V_64 = F_96 ( V_22 ) ;
}
if ( ! V_64 ) {
goto V_236;
}
V_89 = F_93 ;
V_88 = F_97 ( V_89 + 1 , V_26 ) ;
if ( ! V_88 ) {
V_53 = - V_27 ;
F_98 ( V_64 ) ;
goto V_236;
}
V_88 [ V_89 ] = '\0' ;
V_53 = V_22 -> V_69 -> V_70 ( V_64 , V_75 ,
V_88 , V_89 ) ;
if ( V_53 == - V_237 ) {
F_39 ( V_88 ) ;
V_53 = V_22 -> V_69 -> V_70 ( V_64 , V_75 ,
NULL , 0 ) ;
if ( V_53 < 0 ) {
F_98 ( V_64 ) ;
goto V_236;
}
V_89 = V_53 ;
V_88 = F_97 ( V_89 + 1 , V_26 ) ;
if ( ! V_88 ) {
V_53 = - V_27 ;
F_98 ( V_64 ) ;
goto V_236;
}
V_88 [ V_89 ] = '\0' ;
V_53 = V_22 -> V_69 -> V_70 ( V_64 ,
V_75 ,
V_88 , V_89 ) ;
}
F_98 ( V_64 ) ;
if ( V_53 < 0 ) {
if ( V_53 != - V_76 ) {
F_50 ( V_71 L_26
L_27 , V_121 ,
- V_53 , V_22 -> V_39 -> V_72 , V_22 -> V_238 ) ;
F_39 ( V_88 ) ;
goto V_236;
}
V_17 = V_38 -> V_50 ;
V_53 = 0 ;
} else {
V_53 = F_99 ( V_88 , V_53 , & V_17 ,
V_38 -> V_50 ,
V_26 ) ;
if ( V_53 ) {
char * V_239 = V_22 -> V_39 -> V_72 ;
unsigned long V_240 = V_22 -> V_238 ;
if ( V_53 == - V_91 ) {
if ( F_100 () )
F_50 ( V_241 L_28
L_29
L_30 , V_240 , V_239 , V_88 ) ;
} else {
F_50 ( V_71 L_31
L_32 ,
V_121 , V_88 , - V_53 , V_239 , V_240 ) ;
}
F_39 ( V_88 ) ;
V_53 = 0 ;
break;
}
}
F_39 ( V_88 ) ;
V_24 -> V_17 = V_17 ;
break;
case V_61 :
V_24 -> V_17 = V_24 -> F_18 ;
break;
case V_60 :
V_24 -> V_17 = V_38 -> V_17 ;
V_24 -> V_31 = F_82 ( V_22 -> V_242 ) ;
V_53 = F_101 ( V_24 -> F_18 , V_38 -> V_17 ,
V_24 -> V_31 , NULL , & V_17 ) ;
if ( V_53 )
goto V_236;
V_24 -> V_17 = V_17 ;
break;
case V_124 :
V_24 -> V_17 = V_38 -> V_52 ;
break;
default:
V_24 -> V_17 = V_38 -> V_17 ;
if ( ( V_38 -> V_80 & V_120 ) && ! F_102 ( V_22 -> V_242 ) ) {
if ( V_235 )
V_64 = F_95 ( V_235 ) ;
else
V_64 = F_96 ( V_22 ) ;
if ( ! V_64 )
goto V_236;
V_24 -> V_31 = F_82 ( V_22 -> V_242 ) ;
V_53 = F_86 ( V_64 , V_24 -> V_31 , & V_17 ) ;
F_98 ( V_64 ) ;
if ( V_53 )
goto V_236;
V_24 -> V_17 = V_17 ;
}
break;
}
V_24 -> V_125 = 1 ;
V_236:
F_69 ( & V_24 -> V_28 ) ;
V_74:
if ( V_24 -> V_31 == V_32 )
V_24 -> V_31 = F_82 ( V_22 -> V_242 ) ;
return V_53 ;
}
static inline T_2 F_103 ( int V_243 )
{
T_2 V_244 = 0 ;
switch ( V_243 ) {
case V_245 :
V_244 = V_246 ;
break;
case V_247 :
V_244 = V_248 ;
break;
case V_249 :
V_244 = V_250 ;
break;
default:
V_244 = V_251 ;
break;
}
return V_244 ;
}
static int F_104 ( const struct V_10 * V_252 ,
const struct V_10 * V_253 ,
T_2 V_254 )
{
T_2 V_255 = F_17 ( V_252 ) , V_256 = F_17 ( V_253 ) ;
return F_46 ( V_255 , V_256 , V_257 , V_254 , NULL ) ;
}
static int F_105 ( const struct V_20 * V_258 ,
const struct V_20 * V_259 ,
T_2 V_254 )
{
const struct V_13 * V_260 , * V_261 ;
T_2 V_262 , V_263 ;
F_19 () ;
V_260 = F_20 ( V_258 ) -> V_19 ; V_262 = V_260 -> V_17 ;
V_261 = F_20 ( V_259 ) -> V_19 ; V_263 = V_261 -> V_17 ;
F_21 () ;
return F_46 ( V_262 , V_263 , V_257 , V_254 , NULL ) ;
}
static int F_106 ( const struct V_20 * V_264 ,
T_2 V_254 )
{
T_2 V_17 , V_256 ;
V_17 = F_22 () ;
V_256 = F_18 ( V_264 ) ;
return F_46 ( V_17 , V_256 , V_257 , V_254 , NULL ) ;
}
static int F_107 ( const struct V_10 * V_10 ,
int V_265 , int V_266 )
{
struct V_267 V_268 ;
struct V_269 V_270 ;
T_4 V_31 ;
T_2 V_17 = F_17 ( V_10 ) ;
T_2 V_271 = F_108 ( V_265 ) ;
int V_53 ;
V_268 . type = V_272 ;
V_268 . V_273 . V_265 = V_265 ;
switch ( F_109 ( V_265 ) ) {
case 0 :
V_31 = V_274 ;
break;
case 1 :
V_31 = V_275 ;
break;
default:
F_50 ( V_78
L_33 , V_265 ) ;
F_80 () ;
return - V_91 ;
}
V_53 = F_110 ( V_17 , V_17 , V_31 , V_271 , 0 , & V_270 ) ;
if ( V_266 == V_276 ) {
int V_277 = F_111 ( V_17 , V_17 , V_31 , V_271 , & V_270 , V_53 , & V_268 ) ;
if ( V_277 )
return V_277 ;
}
return V_53 ;
}
static int F_112 ( struct V_20 * V_264 ,
T_2 V_254 )
{
T_2 V_17 = F_18 ( V_264 ) ;
return F_46 ( V_17 , V_18 ,
V_278 , V_254 , NULL ) ;
}
static int F_113 ( const struct V_10 * V_10 ,
struct V_22 * V_22 ,
T_2 V_254 ,
struct V_267 * V_279 )
{
struct V_23 * V_24 ;
T_2 V_17 ;
F_114 ( V_10 ) ;
if ( F_115 ( F_54 ( V_22 ) ) )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
return F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_254 , V_279 ) ;
}
static inline int F_116 ( const struct V_10 * V_10 ,
struct V_64 * V_64 ,
T_2 V_271 )
{
struct V_22 * V_22 = V_64 -> V_68 ;
struct V_267 V_268 ;
V_268 . type = V_280 ;
V_268 . V_273 . V_64 = V_64 ;
return F_113 ( V_10 , V_22 , V_271 , & V_268 ) ;
}
static inline int F_117 ( const struct V_10 * V_10 ,
struct V_233 * V_233 ,
T_2 V_271 )
{
struct V_22 * V_22 = V_233 -> V_64 -> V_68 ;
struct V_267 V_268 ;
V_268 . type = V_281 ;
V_268 . V_273 . V_233 = * V_233 ;
return F_113 ( V_10 , V_22 , V_271 , & V_268 ) ;
}
static inline int F_118 ( const struct V_10 * V_10 ,
struct V_42 * V_42 ,
T_2 V_271 )
{
struct V_267 V_268 ;
V_268 . type = V_281 ;
V_268 . V_273 . V_233 = V_42 -> V_282 ;
return F_113 ( V_10 , F_119 ( V_42 ) , V_271 , & V_268 ) ;
}
static int F_120 ( const struct V_10 * V_10 ,
struct V_42 * V_42 ,
T_2 V_271 )
{
struct V_43 * V_44 = V_42 -> V_46 ;
struct V_22 * V_22 = F_119 ( V_42 ) ;
struct V_267 V_268 ;
T_2 V_17 = F_17 ( V_10 ) ;
int V_53 ;
V_268 . type = V_281 ;
V_268 . V_273 . V_233 = V_42 -> V_282 ;
if ( V_17 != V_44 -> V_17 ) {
V_53 = F_46 ( V_17 , V_44 -> V_17 ,
V_283 ,
V_284 ,
& V_268 ) ;
if ( V_53 )
goto V_74;
}
V_53 = 0 ;
if ( V_271 )
V_53 = F_113 ( V_10 , V_22 , V_271 , & V_268 ) ;
V_74:
return V_53 ;
}
static int F_121 ( struct V_22 * V_285 ,
struct V_64 * V_64 ,
T_4 V_231 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_286 ;
struct V_37 * V_38 ;
T_2 V_17 , V_287 ;
struct V_267 V_268 ;
int V_53 ;
V_286 = V_285 -> V_33 ;
V_38 = V_285 -> V_39 -> V_40 ;
V_17 = V_14 -> V_17 ;
V_287 = V_14 -> V_288 ;
V_268 . type = V_280 ;
V_268 . V_273 . V_64 = V_64 ;
V_53 = F_46 ( V_17 , V_286 -> V_17 , V_179 ,
V_289 | V_290 ,
& V_268 ) ;
if ( V_53 )
return V_53 ;
if ( ! V_287 || ! ( V_38 -> V_80 & V_82 ) ) {
V_53 = F_101 ( V_17 , V_286 -> V_17 , V_231 ,
& V_64 -> V_291 , & V_287 ) ;
if ( V_53 )
return V_53 ;
}
V_53 = F_46 ( V_17 , V_287 , V_231 , V_292 , & V_268 ) ;
if ( V_53 )
return V_53 ;
return F_46 ( V_287 , V_38 -> V_17 ,
V_54 ,
V_57 , & V_268 ) ;
}
static int F_122 ( T_2 V_293 ,
struct V_20 * V_294 )
{
T_2 V_17 = F_18 ( V_294 ) ;
return F_46 ( V_17 , V_293 , V_295 , V_296 , NULL ) ;
}
static int F_123 ( struct V_22 * V_285 ,
struct V_64 * V_64 ,
int V_297 )
{
struct V_23 * V_286 , * V_24 ;
struct V_267 V_268 ;
T_2 V_17 = F_22 () ;
T_2 V_271 ;
int V_53 ;
V_286 = V_285 -> V_33 ;
V_24 = V_64 -> V_68 -> V_33 ;
V_268 . type = V_280 ;
V_268 . V_273 . V_64 = V_64 ;
V_271 = V_290 ;
V_271 |= ( V_297 ? V_298 : V_289 ) ;
V_53 = F_46 ( V_17 , V_286 -> V_17 , V_179 , V_271 , & V_268 ) ;
if ( V_53 )
return V_53 ;
switch ( V_297 ) {
case V_299 :
V_271 = V_300 ;
break;
case V_301 :
V_271 = V_302 ;
break;
case V_303 :
V_271 = V_304 ;
break;
default:
F_50 ( V_71 L_34 ,
V_121 , V_297 ) ;
return 0 ;
}
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_271 , & V_268 ) ;
return V_53 ;
}
static inline int F_124 ( struct V_22 * V_305 ,
struct V_64 * V_306 ,
struct V_22 * V_307 ,
struct V_64 * V_308 )
{
struct V_23 * V_309 , * V_310 , * V_311 , * V_312 ;
struct V_267 V_268 ;
T_2 V_17 = F_22 () ;
T_2 V_271 ;
int V_313 , V_314 ;
int V_53 ;
V_309 = V_305 -> V_33 ;
V_311 = V_306 -> V_68 -> V_33 ;
V_313 = F_125 ( V_306 -> V_68 -> V_242 ) ;
V_310 = V_307 -> V_33 ;
V_268 . type = V_280 ;
V_268 . V_273 . V_64 = V_306 ;
V_53 = F_46 ( V_17 , V_309 -> V_17 , V_179 ,
V_298 | V_290 , & V_268 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_17 , V_311 -> V_17 ,
V_311 -> V_31 , V_315 , & V_268 ) ;
if ( V_53 )
return V_53 ;
if ( V_313 && V_307 != V_305 ) {
V_53 = F_46 ( V_17 , V_311 -> V_17 ,
V_311 -> V_31 , V_316 , & V_268 ) ;
if ( V_53 )
return V_53 ;
}
V_268 . V_273 . V_64 = V_308 ;
V_271 = V_289 | V_290 ;
if ( V_308 -> V_68 )
V_271 |= V_298 ;
V_53 = F_46 ( V_17 , V_310 -> V_17 , V_179 , V_271 , & V_268 ) ;
if ( V_53 )
return V_53 ;
if ( V_308 -> V_68 ) {
V_312 = V_308 -> V_68 -> V_33 ;
V_314 = F_125 ( V_308 -> V_68 -> V_242 ) ;
V_53 = F_46 ( V_17 , V_312 -> V_17 ,
V_312 -> V_31 ,
( V_314 ? V_304 : V_302 ) , & V_268 ) ;
if ( V_53 )
return V_53 ;
}
return 0 ;
}
static int F_126 ( const struct V_10 * V_10 ,
struct V_47 * V_48 ,
T_2 V_254 ,
struct V_267 * V_268 )
{
struct V_37 * V_38 ;
T_2 V_17 = F_17 ( V_10 ) ;
V_38 = V_48 -> V_40 ;
return F_46 ( V_17 , V_38 -> V_17 , V_54 , V_254 , V_268 ) ;
}
static inline T_2 F_127 ( int V_169 , int V_317 )
{
T_2 V_271 = 0 ;
if ( ! F_125 ( V_169 ) ) {
if ( V_317 & V_318 )
V_271 |= V_319 ;
if ( V_317 & V_320 )
V_271 |= V_321 ;
if ( V_317 & V_322 )
V_271 |= V_323 ;
else if ( V_317 & V_324 )
V_271 |= V_325 ;
} else {
if ( V_317 & V_318 )
V_271 |= V_290 ;
if ( V_317 & V_324 )
V_271 |= V_326 ;
if ( V_317 & V_320 )
V_271 |= V_327 ;
}
return V_271 ;
}
static inline T_2 F_128 ( struct V_42 * V_42 )
{
T_2 V_271 = 0 ;
if ( V_42 -> V_328 & V_329 )
V_271 |= V_321 ;
if ( V_42 -> V_328 & V_330 ) {
if ( V_42 -> V_331 & V_332 )
V_271 |= V_323 ;
else
V_271 |= V_325 ;
}
if ( ! V_271 ) {
V_271 = V_333 ;
}
return V_271 ;
}
static inline T_2 F_129 ( struct V_42 * V_42 )
{
T_2 V_271 = F_128 ( V_42 ) ;
if ( V_334 )
V_271 |= V_335 ;
return V_271 ;
}
static int F_130 ( struct V_20 * V_336 ,
unsigned int V_169 )
{
int V_53 ;
V_53 = F_131 ( V_336 , V_169 ) ;
if ( V_53 )
return V_53 ;
if ( V_169 & V_337 ) {
T_2 V_17 = F_22 () ;
T_2 V_338 = F_18 ( V_336 ) ;
return F_46 ( V_17 , V_338 , V_32 , V_321 , NULL ) ;
}
return F_106 ( V_336 , V_339 ) ;
}
static int F_132 ( struct V_20 * V_340 )
{
int V_53 ;
V_53 = F_133 ( V_340 ) ;
if ( V_53 )
return V_53 ;
return F_105 ( V_340 , V_11 , V_339 ) ;
}
static int F_134 ( struct V_20 * V_253 , T_6 * V_341 ,
T_6 * V_342 , T_6 * V_343 )
{
int error ;
error = F_106 ( V_253 , V_344 ) ;
if ( error )
return error ;
return F_135 ( V_253 , V_341 , V_342 , V_343 ) ;
}
static int F_136 ( struct V_10 * V_129 , const struct V_10 * V_128 ,
const T_6 * V_341 ,
const T_6 * V_342 ,
const T_6 * V_343 )
{
int error ;
error = F_137 ( V_129 , V_128 ,
V_341 , V_342 , V_343 ) ;
if ( error )
return error ;
return F_104 ( V_128 , V_129 , V_345 ) ;
}
static int F_138 ( const struct V_10 * V_10 , struct V_346 * V_347 ,
int V_265 , int V_266 )
{
int V_53 ;
V_53 = F_139 ( V_10 , V_347 , V_265 , V_266 ) ;
if ( V_53 )
return V_53 ;
return F_107 ( V_10 , V_265 , V_266 ) ;
}
static int F_140 ( int V_348 , int type , int V_349 , struct V_47 * V_48 )
{
const struct V_10 * V_10 = F_65 () ;
int V_53 = 0 ;
if ( ! V_48 )
return 0 ;
switch ( V_348 ) {
case V_350 :
case V_351 :
case V_352 :
case V_353 :
case V_354 :
V_53 = F_126 ( V_10 , V_48 , V_355 , NULL ) ;
break;
case V_356 :
case V_357 :
case V_358 :
V_53 = F_126 ( V_10 , V_48 , V_359 , NULL ) ;
break;
default:
V_53 = 0 ;
break;
}
return V_53 ;
}
static int F_141 ( struct V_64 * V_64 )
{
const struct V_10 * V_10 = F_65 () ;
return F_116 ( V_10 , V_64 , V_360 ) ;
}
static int F_142 ( int type )
{
int V_53 ;
switch ( type ) {
case V_361 :
case V_362 :
V_53 = F_112 ( V_11 , V_363 ) ;
break;
case V_364 :
case V_365 :
case V_366 :
V_53 = F_112 ( V_11 , V_367 ) ;
break;
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
default:
V_53 = F_112 ( V_11 , V_373 ) ;
break;
}
return V_53 ;
}
static int F_143 ( struct V_374 * V_375 , long V_376 )
{
int V_53 , V_377 = 0 ;
V_53 = F_138 ( F_65 () , & V_378 , V_379 ,
V_380 ) ;
if ( V_53 == 0 )
V_377 = 1 ;
return F_144 ( V_375 , V_376 , V_377 ) ;
}
static int F_145 ( struct V_381 * V_382 )
{
const struct V_13 * V_383 ;
struct V_13 * V_384 ;
struct V_23 * V_24 ;
struct V_267 V_268 ;
struct V_22 * V_22 = F_119 ( V_382 -> V_42 ) ;
int V_53 ;
V_53 = F_146 ( V_382 ) ;
if ( V_53 )
return V_53 ;
if ( V_382 -> V_385 )
return 0 ;
V_383 = F_23 () ;
V_384 = V_382 -> V_10 -> V_19 ;
V_24 = V_22 -> V_33 ;
V_384 -> V_17 = V_383 -> V_17 ;
V_384 -> V_16 = V_383 -> V_17 ;
V_384 -> V_288 = 0 ;
V_384 -> V_386 = 0 ;
V_384 -> V_387 = 0 ;
if ( V_383 -> V_388 ) {
V_384 -> V_17 = V_383 -> V_388 ;
V_384 -> V_388 = 0 ;
if ( V_382 -> V_389 & V_390 )
return - V_391 ;
if ( V_382 -> V_42 -> V_282 . V_392 -> V_107 & V_393 )
return - V_394 ;
} else {
V_53 = F_101 ( V_383 -> V_17 , V_24 -> V_17 ,
V_257 , NULL ,
& V_384 -> V_17 ) ;
if ( V_53 )
return V_53 ;
}
V_268 . type = V_281 ;
V_268 . V_273 . V_233 = V_382 -> V_42 -> V_282 ;
if ( ( V_382 -> V_42 -> V_282 . V_392 -> V_107 & V_393 ) ||
( V_382 -> V_389 & V_390 ) )
V_384 -> V_17 = V_383 -> V_17 ;
if ( V_384 -> V_17 == V_383 -> V_17 ) {
V_53 = F_46 ( V_383 -> V_17 , V_24 -> V_17 ,
V_32 , V_395 , & V_268 ) ;
if ( V_53 )
return V_53 ;
} else {
V_53 = F_46 ( V_383 -> V_17 , V_384 -> V_17 ,
V_257 , V_396 , & V_268 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_384 -> V_17 , V_24 -> V_17 ,
V_32 , V_397 , & V_268 ) ;
if ( V_53 )
return V_53 ;
if ( V_382 -> V_389 & V_398 ) {
V_53 = F_46 ( V_383 -> V_17 , V_384 -> V_17 ,
V_257 , V_399 ,
NULL ) ;
if ( V_53 )
return - V_391 ;
}
if ( V_382 -> V_389 &
( V_400 | V_401 ) ) {
struct V_20 * V_402 ;
struct V_13 * V_403 ;
T_2 V_404 = 0 ;
F_19 () ;
V_402 = F_147 ( V_11 ) ;
if ( F_148 ( V_402 != NULL ) ) {
V_403 = F_20 ( V_402 ) -> V_19 ;
V_404 = V_403 -> V_17 ;
}
F_21 () ;
if ( V_404 != 0 ) {
V_53 = F_46 ( V_404 , V_384 -> V_17 ,
V_257 ,
V_339 , NULL ) ;
if ( V_53 )
return - V_391 ;
}
}
V_382 -> V_405 |= V_406 ;
}
return 0 ;
}
static int F_149 ( struct V_381 * V_382 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_17 , V_16 ;
int V_407 = 0 ;
V_17 = V_14 -> V_17 ;
V_16 = V_14 -> V_16 ;
if ( V_16 != V_17 ) {
V_407 = F_46 ( V_16 , V_17 ,
V_257 ,
V_408 , NULL ) ;
}
return ( V_407 || F_150 ( V_382 ) ) ;
}
static int F_151 ( const void * V_146 , struct V_42 * V_42 , unsigned V_409 )
{
return F_120 ( V_146 , V_42 , F_128 ( V_42 ) ) ? V_409 + 1 : 0 ;
}
static inline void F_152 ( const struct V_10 * V_10 ,
struct V_410 * V_411 )
{
struct V_42 * V_42 , * V_412 = NULL ;
struct V_413 * V_414 ;
int V_415 = 0 ;
unsigned V_416 ;
V_414 = F_153 () ;
if ( V_414 ) {
F_32 ( & V_417 ) ;
if ( ! F_33 ( & V_414 -> V_418 ) ) {
struct V_419 * V_420 ;
V_420 = F_154 ( & V_414 -> V_418 ,
struct V_419 , V_29 ) ;
V_42 = V_420 -> V_42 ;
if ( F_118 ( V_10 , V_42 , V_321 | V_325 ) )
V_415 = 1 ;
}
F_35 ( & V_417 ) ;
F_155 ( V_414 ) ;
}
if ( V_415 )
F_156 () ;
V_416 = F_157 ( V_411 , 0 , F_151 , V_10 ) ;
if ( ! V_416 )
return;
V_412 = F_158 ( & V_421 , V_422 , V_10 ) ;
if ( F_89 ( V_412 ) )
V_412 = NULL ;
do {
F_159 ( V_416 - 1 , V_412 , 0 ) ;
} while ( ( V_416 = F_157 ( V_411 , V_416 , F_151 , V_10 ) ) != 0 );
if ( V_412 )
F_160 ( V_412 ) ;
}
static void F_161 ( struct V_381 * V_382 )
{
struct V_13 * V_384 ;
struct V_423 * V_424 , * V_425 ;
int V_53 , V_87 ;
V_384 = V_382 -> V_10 -> V_19 ;
if ( V_384 -> V_17 == V_384 -> V_16 )
return;
F_152 ( V_382 -> V_10 , V_11 -> V_411 ) ;
V_11 -> V_426 = 0 ;
V_53 = F_46 ( V_384 -> V_16 , V_384 -> V_17 , V_257 ,
V_427 , NULL ) ;
if ( V_53 ) {
F_162 ( V_11 ) ;
for ( V_87 = 0 ; V_87 < V_428 ; V_87 ++ ) {
V_424 = V_11 -> signal -> V_424 + V_87 ;
V_425 = V_429 . signal -> V_424 + V_87 ;
V_424 -> V_430 = F_163 ( V_424 -> V_431 , V_425 -> V_430 ) ;
}
F_164 ( V_11 ) ;
F_165 ( V_11 , V_423 ( V_432 ) ) ;
}
}
static void F_166 ( struct V_381 * V_382 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_433 V_434 ;
T_2 V_16 , V_17 ;
int V_53 , V_87 ;
V_16 = V_14 -> V_16 ;
V_17 = V_14 -> V_17 ;
if ( V_17 == V_16 )
return;
V_53 = F_46 ( V_16 , V_17 , V_257 , V_435 , NULL ) ;
if ( V_53 ) {
memset ( & V_434 , 0 , sizeof V_434 ) ;
for ( V_87 = 0 ; V_87 < 3 ; V_87 ++ )
F_167 ( V_87 , & V_434 , NULL ) ;
F_168 ( & V_11 -> V_436 -> V_437 ) ;
if ( ! ( V_11 -> signal -> V_80 & V_438 ) ) {
F_169 ( V_11 ) ;
F_170 ( V_11 , 1 ) ;
F_171 ( & V_11 -> V_439 ) ;
}
F_172 ( & V_11 -> V_436 -> V_437 ) ;
}
F_173 ( & V_440 ) ;
F_174 ( V_11 , V_11 -> V_441 ) ;
F_175 ( & V_440 ) ;
}
static int F_176 ( struct V_47 * V_48 )
{
return F_40 ( V_48 ) ;
}
static void F_177 ( struct V_47 * V_48 )
{
F_42 ( V_48 ) ;
}
static inline int F_178 ( char * V_162 , int V_442 , char * V_443 , int V_444 )
{
if ( V_442 > V_444 )
return 0 ;
return ! memcmp ( V_162 , V_443 , V_442 ) ;
}
static inline int F_179 ( char * V_443 , int V_89 )
{
return ( F_178 ( V_164 , sizeof( V_164 ) - 1 , V_443 , V_89 ) ||
F_178 ( V_165 , sizeof( V_165 ) - 1 , V_443 , V_89 ) ||
F_178 ( V_167 , sizeof( V_167 ) - 1 , V_443 , V_89 ) ||
F_178 ( V_166 , sizeof( V_166 ) - 1 , V_443 , V_89 ) ||
F_178 ( V_168 , sizeof( V_168 ) - 1 , V_443 , V_89 ) ) ;
}
static inline void F_180 ( char * * V_445 , char * V_446 , int * V_447 , int V_89 )
{
if ( ! * V_447 ) {
* * V_445 = ',' ;
* V_445 += 1 ;
} else
* V_447 = 0 ;
memcpy ( * V_445 , V_446 , V_89 ) ;
* V_445 += V_89 ;
}
static inline void F_181 ( char * * V_445 , char * V_446 , int * V_447 ,
int V_89 )
{
int V_448 = 0 ;
if ( ! * V_447 ) {
* * V_445 = '|' ;
* V_445 += 1 ;
} else
* V_447 = 0 ;
while ( V_448 < V_89 ) {
if ( * V_446 != '"' ) {
* * V_445 = * V_446 ;
* V_445 += 1 ;
}
V_446 += 1 ;
V_448 += 1 ;
}
}
static int F_182 ( char * V_449 , char * V_450 )
{
int V_451 , V_44 , V_53 = 0 ;
char * V_452 , * V_453 , * V_454 ;
char * V_455 , * V_456 , * V_457 ;
int V_458 = 0 ;
V_453 = V_449 ;
V_455 = V_450 ;
V_457 = ( char * ) F_183 ( V_15 ) ;
if ( ! V_457 ) {
V_53 = - V_27 ;
goto V_74;
}
V_456 = V_457 ;
V_451 = V_44 = 1 ;
V_452 = V_454 = V_449 ;
do {
if ( * V_454 == '"' )
V_458 = ! V_458 ;
if ( ( * V_454 == ',' && V_458 == 0 ) ||
* V_454 == '\0' ) {
int V_89 = V_454 - V_453 ;
if ( F_179 ( V_453 , V_89 ) )
F_181 ( & V_455 , V_453 , & V_44 , V_89 ) ;
else
F_180 ( & V_457 , V_453 , & V_451 , V_89 ) ;
V_453 = V_454 + 1 ;
}
} while ( * V_454 ++ );
strcpy ( V_452 , V_456 ) ;
F_92 ( ( unsigned long ) V_456 ) ;
V_74:
return V_53 ;
}
static int F_184 ( struct V_47 * V_48 , void * V_159 )
{
int V_53 , V_87 , * V_80 ;
struct V_85 V_86 ;
char * V_459 , * * V_115 ;
struct V_37 * V_38 = V_48 -> V_40 ;
if ( ! ( V_38 -> V_80 & V_81 ) )
return 0 ;
if ( ! V_159 )
return 0 ;
if ( V_48 -> V_62 -> V_117 & V_118 )
return 0 ;
F_57 ( & V_86 ) ;
V_459 = F_185 () ;
if ( ! V_459 )
return - V_27 ;
V_53 = F_182 ( V_159 , V_459 ) ;
if ( V_53 )
goto V_460;
V_53 = F_72 ( V_459 , & V_86 ) ;
if ( V_53 )
goto V_460;
V_115 = V_86 . V_96 ;
V_80 = V_86 . V_99 ;
for ( V_87 = 0 ; V_87 < V_86 . V_95 ; V_87 ++ ) {
T_2 V_17 ;
T_7 V_89 ;
if ( V_80 [ V_87 ] == V_82 )
continue;
V_89 = strlen ( V_115 [ V_87 ] ) ;
V_53 = F_67 ( V_115 [ V_87 ] , V_89 , & V_17 ,
V_15 ) ;
if ( V_53 ) {
F_50 ( V_71 L_13
L_14 ,
V_115 [ V_87 ] , V_48 -> V_72 , V_48 -> V_62 -> V_63 , V_53 ) ;
goto V_461;
}
V_53 = - V_91 ;
switch ( V_80 [ V_87 ] ) {
case V_100 :
if ( F_63 ( V_38 , V_100 , V_38 -> V_17 , V_17 ) )
goto V_462;
break;
case V_101 :
if ( F_63 ( V_38 , V_101 , V_38 -> V_52 , V_17 ) )
goto V_462;
break;
case V_103 : {
struct V_23 * V_110 ;
V_110 = V_48 -> V_66 -> V_68 -> V_33 ;
if ( F_63 ( V_38 , V_103 , V_110 -> V_17 , V_17 ) )
goto V_462;
break;
}
case V_102 :
if ( F_63 ( V_38 , V_102 , V_38 -> V_50 , V_17 ) )
goto V_462;
break;
default:
goto V_461;
}
}
V_53 = 0 ;
V_461:
F_62 ( & V_86 ) ;
V_460:
F_186 ( V_459 ) ;
return V_53 ;
V_462:
F_50 ( V_71 L_35
L_36 , V_48 -> V_72 ,
V_48 -> V_62 -> V_63 ) ;
goto V_461;
}
static int F_187 ( struct V_47 * V_48 , int V_80 , void * V_159 )
{
const struct V_10 * V_10 = F_65 () ;
struct V_267 V_268 ;
int V_53 ;
V_53 = F_76 ( V_48 , V_159 ) ;
if ( V_53 )
return V_53 ;
if ( V_80 & V_463 )
return 0 ;
V_268 . type = V_280 ;
V_268 . V_273 . V_64 = V_48 -> V_66 ;
return F_126 ( V_10 , V_48 , V_464 , & V_268 ) ;
}
static int F_188 ( struct V_64 * V_64 )
{
const struct V_10 * V_10 = F_65 () ;
struct V_267 V_268 ;
V_268 . type = V_280 ;
V_268 . V_273 . V_64 = V_64 -> V_465 -> V_66 ;
return F_126 ( V_10 , V_64 -> V_465 , V_466 , & V_268 ) ;
}
static int F_189 ( const char * V_467 ,
struct V_233 * V_233 ,
const char * type ,
unsigned long V_80 ,
void * V_159 )
{
const struct V_10 * V_10 = F_65 () ;
if ( V_80 & V_468 )
return F_126 ( V_10 , V_233 -> V_64 -> V_465 ,
V_469 , NULL ) ;
else
return F_117 ( V_10 , V_233 , V_470 ) ;
}
static int F_190 ( struct V_471 * V_392 , int V_80 )
{
const struct V_10 * V_10 = F_65 () ;
return F_126 ( V_10 , V_392 -> V_472 ,
V_473 , NULL ) ;
}
static int F_191 ( struct V_22 * V_22 )
{
return F_24 ( V_22 ) ;
}
static void F_192 ( struct V_22 * V_22 )
{
F_31 ( V_22 ) ;
}
static int F_193 ( struct V_64 * V_64 , int V_169 ,
struct V_474 * V_63 , void * * V_294 ,
T_2 * V_475 )
{
const struct V_10 * V_10 = F_65 () ;
struct V_13 * V_14 ;
struct V_23 * V_286 ;
struct V_37 * V_38 ;
struct V_22 * V_285 = V_64 -> V_476 -> V_68 ;
T_2 V_287 ;
int V_53 ;
V_14 = V_10 -> V_19 ;
V_286 = V_285 -> V_33 ;
V_38 = V_285 -> V_39 -> V_40 ;
if ( V_14 -> V_288 && V_38 -> V_58 != V_124 ) {
V_287 = V_14 -> V_288 ;
} else {
V_53 = F_101 ( V_14 -> V_17 , V_286 -> V_17 ,
F_82 ( V_169 ) ,
V_63 ,
& V_287 ) ;
if ( V_53 ) {
F_50 ( V_71
L_37 ,
V_121 , - V_53 ) ;
return V_53 ;
}
}
return F_60 ( V_287 , ( char * * ) V_294 , V_475 ) ;
}
static int F_194 ( struct V_22 * V_22 , struct V_22 * V_285 ,
const struct V_474 * V_474 ,
const char * * V_63 ,
void * * V_477 , T_7 * V_89 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_286 ;
struct V_37 * V_38 ;
T_2 V_17 , V_287 , V_478 ;
int V_53 ;
char * V_88 ;
V_286 = V_285 -> V_33 ;
V_38 = V_285 -> V_39 -> V_40 ;
V_17 = V_14 -> V_17 ;
V_287 = V_14 -> V_288 ;
if ( ( V_38 -> V_80 & V_81 ) &&
( V_38 -> V_58 == V_124 ) )
V_287 = V_38 -> V_52 ;
else if ( ! V_287 || ! ( V_38 -> V_80 & V_82 ) ) {
V_53 = F_101 ( V_17 , V_286 -> V_17 ,
F_82 ( V_22 -> V_242 ) ,
V_474 , & V_287 ) ;
if ( V_53 ) {
F_50 ( V_71 L_38
L_39
L_40 ,
V_121 ,
- V_53 , V_22 -> V_39 -> V_72 , V_22 -> V_238 ) ;
return V_53 ;
}
}
if ( V_38 -> V_80 & V_81 ) {
struct V_23 * V_24 = V_22 -> V_33 ;
V_24 -> V_31 = F_82 ( V_22 -> V_242 ) ;
V_24 -> V_17 = V_287 ;
V_24 -> V_125 = 1 ;
}
if ( ! V_92 || ! ( V_38 -> V_80 & V_82 ) )
return - V_73 ;
if ( V_63 )
* V_63 = V_479 ;
if ( V_477 && V_89 ) {
V_53 = F_195 ( V_287 , & V_88 , & V_478 ) ;
if ( V_53 )
return V_53 ;
* V_477 = V_88 ;
* V_89 = V_478 ;
}
return 0 ;
}
static int F_196 ( struct V_22 * V_285 , struct V_64 * V_64 , T_5 V_169 )
{
return F_121 ( V_285 , V_64 , V_32 ) ;
}
static int F_197 ( struct V_64 * V_306 , struct V_22 * V_285 , struct V_64 * V_308 )
{
return F_123 ( V_285 , V_306 , V_299 ) ;
}
static int F_198 ( struct V_22 * V_285 , struct V_64 * V_64 )
{
return F_123 ( V_285 , V_64 , V_301 ) ;
}
static int F_199 ( struct V_22 * V_285 , struct V_64 * V_64 , const char * V_63 )
{
return F_121 ( V_285 , V_64 , V_174 ) ;
}
static int F_200 ( struct V_22 * V_285 , struct V_64 * V_64 , T_5 V_317 )
{
return F_121 ( V_285 , V_64 , V_179 ) ;
}
static int F_201 ( struct V_22 * V_285 , struct V_64 * V_64 )
{
return F_123 ( V_285 , V_64 , V_303 ) ;
}
static int F_202 ( struct V_22 * V_285 , struct V_64 * V_64 , T_5 V_169 , T_8 V_239 )
{
return F_121 ( V_285 , V_64 , F_82 ( V_169 ) ) ;
}
static int F_203 ( struct V_22 * V_480 , struct V_64 * V_306 ,
struct V_22 * V_481 , struct V_64 * V_308 )
{
return F_124 ( V_480 , V_306 , V_481 , V_308 ) ;
}
static int F_204 ( struct V_64 * V_64 )
{
const struct V_10 * V_10 = F_65 () ;
return F_116 ( V_10 , V_64 , V_321 ) ;
}
static int F_205 ( struct V_64 * V_64 , struct V_482 * V_482 )
{
const struct V_10 * V_10 = F_65 () ;
return F_116 ( V_10 , V_64 , V_321 ) ;
}
static T_9 int F_206 ( struct V_22 * V_22 ,
T_2 V_254 , T_2 V_483 , T_2 V_484 ,
int V_485 ,
unsigned V_80 )
{
struct V_267 V_268 ;
struct V_23 * V_24 = V_22 -> V_33 ;
int V_53 ;
V_268 . type = V_486 ;
V_268 . V_273 . V_22 = V_22 ;
V_53 = F_207 ( F_22 () , V_24 -> V_17 , V_24 -> V_31 , V_254 ,
V_483 , V_484 , V_485 , & V_268 , V_80 ) ;
if ( V_53 )
return V_53 ;
return 0 ;
}
static int F_208 ( struct V_22 * V_22 , int V_317 )
{
const struct V_10 * V_10 = F_65 () ;
T_2 V_254 ;
bool V_487 ;
unsigned V_80 = V_317 & V_488 ;
struct V_23 * V_24 ;
T_2 V_17 ;
struct V_269 V_270 ;
int V_53 , V_277 ;
T_2 V_483 , V_484 ;
V_487 = V_317 & V_489 ;
V_317 &= ( V_320 | V_324 | V_318 | V_322 ) ;
if ( ! V_317 )
return 0 ;
F_114 ( V_10 ) ;
if ( F_115 ( F_54 ( V_22 ) ) )
return 0 ;
V_254 = F_127 ( V_22 -> V_242 , V_317 ) ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
V_53 = F_110 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_254 , 0 , & V_270 ) ;
V_483 = F_209 ( V_254 , & V_270 , V_53 ,
V_487 ? V_490 : 0 ,
& V_484 ) ;
if ( F_148 ( ! V_483 ) )
return V_53 ;
V_277 = F_206 ( V_22 , V_254 , V_483 , V_484 , V_53 , V_80 ) ;
if ( V_277 )
return V_277 ;
return V_53 ;
}
static int F_210 ( struct V_64 * V_64 , struct V_491 * V_491 )
{
const struct V_10 * V_10 = F_65 () ;
unsigned int V_492 = V_491 -> V_492 ;
T_10 V_271 = V_325 ;
if ( V_492 & V_493 ) {
V_492 &= ~ ( V_494 | V_495 | V_496 |
V_493 ) ;
if ( ! V_492 )
return 0 ;
}
if ( V_492 & ( V_496 | V_497 | V_498 |
V_499 | V_500 | V_501 ) )
return F_116 ( V_10 , V_64 , V_502 ) ;
if ( V_334 && ( V_492 & V_503 ) )
V_271 |= V_335 ;
return F_116 ( V_10 , V_64 , V_271 ) ;
}
static int F_211 ( struct V_471 * V_392 , struct V_64 * V_64 )
{
const struct V_10 * V_10 = F_65 () ;
struct V_233 V_233 ;
V_233 . V_64 = V_64 ;
V_233 . V_392 = V_392 ;
return F_117 ( V_10 , & V_233 , V_504 ) ;
}
static int F_212 ( struct V_64 * V_64 , const char * V_63 )
{
const struct V_10 * V_10 = F_65 () ;
if ( ! strncmp ( V_63 , V_505 ,
sizeof V_505 - 1 ) ) {
if ( ! strcmp ( V_63 , V_506 ) ) {
if ( ! F_213 ( V_507 ) )
return - V_391 ;
} else if ( ! F_213 ( V_379 ) ) {
return - V_391 ;
}
}
return F_116 ( V_10 , V_64 , V_502 ) ;
}
static int F_214 ( struct V_64 * V_64 , const char * V_63 ,
const void * V_477 , T_7 V_508 , int V_80 )
{
struct V_22 * V_22 = V_64 -> V_68 ;
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_37 * V_38 ;
struct V_267 V_268 ;
T_2 V_287 , V_17 = F_22 () ;
int V_53 = 0 ;
if ( strcmp ( V_63 , V_75 ) )
return F_212 ( V_64 , V_63 ) ;
V_38 = V_22 -> V_39 -> V_40 ;
if ( ! ( V_38 -> V_80 & V_82 ) )
return - V_73 ;
if ( ! F_215 ( V_22 ) )
return - V_391 ;
V_268 . type = V_280 ;
V_268 . V_273 . V_64 = V_64 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 ,
V_509 , & V_268 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_67 ( V_477 , V_508 , & V_287 , V_15 ) ;
if ( V_53 == - V_91 ) {
if ( ! F_213 ( V_510 ) ) {
struct V_511 * V_512 ;
T_7 V_513 ;
const char * V_1 ;
if ( V_477 ) {
V_1 = V_477 ;
if ( V_1 [ V_508 - 1 ] == '\0' )
V_513 = V_508 - 1 ;
else
V_513 = V_508 ;
} else {
V_1 = L_41 ;
V_513 = 0 ;
}
V_512 = F_216 ( V_11 -> V_514 , V_97 , V_515 ) ;
F_217 ( V_512 , L_42 ) ;
F_218 ( V_512 , V_477 , V_513 ) ;
F_219 ( V_512 ) ;
return V_53 ;
}
V_53 = F_220 ( V_477 , V_508 , & V_287 ) ;
}
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_17 , V_287 , V_24 -> V_31 ,
V_516 , & V_268 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_221 ( V_24 -> V_17 , V_287 , V_17 ,
V_24 -> V_31 ) ;
if ( V_53 )
return V_53 ;
return F_46 ( V_287 ,
V_38 -> V_17 ,
V_54 ,
V_57 ,
& V_268 ) ;
}
static void F_222 ( struct V_64 * V_64 , const char * V_63 ,
const void * V_477 , T_7 V_508 ,
int V_80 )
{
struct V_22 * V_22 = V_64 -> V_68 ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_287 ;
int V_53 ;
if ( strcmp ( V_63 , V_75 ) ) {
return;
}
V_53 = F_220 ( V_477 , V_508 , & V_287 ) ;
if ( V_53 ) {
F_50 ( V_78 L_43
L_44 ,
V_22 -> V_39 -> V_72 , V_22 -> V_238 , - V_53 ) ;
return;
}
V_24 -> V_31 = F_82 ( V_22 -> V_242 ) ;
V_24 -> V_17 = V_287 ;
V_24 -> V_125 = 1 ;
return;
}
static int F_223 ( struct V_64 * V_64 , const char * V_63 )
{
const struct V_10 * V_10 = F_65 () ;
return F_116 ( V_10 , V_64 , V_504 ) ;
}
static int F_224 ( struct V_64 * V_64 )
{
const struct V_10 * V_10 = F_65 () ;
return F_116 ( V_10 , V_64 , V_504 ) ;
}
static int F_225 ( struct V_64 * V_64 , const char * V_63 )
{
if ( strcmp ( V_63 , V_75 ) )
return F_212 ( V_64 , V_63 ) ;
return - V_394 ;
}
static int F_226 ( const struct V_22 * V_22 , const char * V_63 , void * * V_232 , bool V_517 )
{
T_2 V_508 ;
int error ;
char * V_88 = NULL ;
struct V_23 * V_24 = V_22 -> V_33 ;
if ( strcmp ( V_63 , V_479 ) )
return - V_73 ;
error = F_138 ( F_65 () , & V_378 , V_510 ,
V_380 ) ;
if ( ! error )
error = F_195 ( V_24 -> V_17 , & V_88 ,
& V_508 ) ;
else
error = F_60 ( V_24 -> V_17 , & V_88 , & V_508 ) ;
if ( error )
return error ;
error = V_508 ;
if ( V_517 ) {
* V_232 = V_88 ;
goto V_518;
}
F_39 ( V_88 ) ;
V_518:
return error ;
}
static int F_227 ( struct V_22 * V_22 , const char * V_63 ,
const void * V_477 , T_7 V_508 , int V_80 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_287 ;
int V_53 ;
if ( strcmp ( V_63 , V_479 ) )
return - V_73 ;
if ( ! V_477 || ! V_508 )
return - V_394 ;
V_53 = F_67 ( ( void * ) V_477 , V_508 , & V_287 , V_15 ) ;
if ( V_53 )
return V_53 ;
V_24 -> V_31 = F_82 ( V_22 -> V_242 ) ;
V_24 -> V_17 = V_287 ;
V_24 -> V_125 = 1 ;
return 0 ;
}
static int F_228 ( struct V_22 * V_22 , char * V_232 , T_7 V_519 )
{
const int V_89 = sizeof( V_75 ) ;
if ( V_232 && V_89 <= V_519 )
memcpy ( V_232 , V_75 , V_89 ) ;
return V_89 ;
}
static void F_229 ( const struct V_22 * V_22 , T_2 * V_520 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
* V_520 = V_24 -> V_17 ;
}
static int F_230 ( struct V_42 * V_42 , int V_317 )
{
const struct V_10 * V_10 = F_65 () ;
struct V_22 * V_22 = F_119 ( V_42 ) ;
if ( ( V_42 -> V_331 & V_332 ) && ( V_317 & V_324 ) )
V_317 |= V_322 ;
return F_120 ( V_10 , V_42 ,
F_127 ( V_22 -> V_242 , V_317 ) ) ;
}
static int F_231 ( struct V_42 * V_42 , int V_317 )
{
struct V_22 * V_22 = F_119 ( V_42 ) ;
struct V_43 * V_44 = V_42 -> V_46 ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 = F_22 () ;
if ( ! V_317 )
return 0 ;
if ( V_17 == V_44 -> V_17 && V_44 -> V_521 == V_24 -> V_17 &&
V_44 -> V_522 == F_232 () )
return 0 ;
return F_230 ( V_42 , V_317 ) ;
}
static int F_233 ( struct V_42 * V_42 )
{
return F_37 ( V_42 ) ;
}
static void F_234 ( struct V_42 * V_42 )
{
F_38 ( V_42 ) ;
}
static int F_235 ( struct V_42 * V_42 , unsigned int V_523 ,
unsigned long V_524 )
{
const struct V_10 * V_10 = F_65 () ;
int error = 0 ;
switch ( V_523 ) {
case V_525 :
case V_526 :
case V_527 :
case V_528 :
case V_529 :
error = F_120 ( V_10 , V_42 , V_504 ) ;
break;
case V_530 :
case V_531 :
error = F_120 ( V_10 , V_42 , V_502 ) ;
break;
case V_532 :
case V_533 :
error = F_120 ( V_10 , V_42 , 0 ) ;
break;
case V_534 :
case V_535 :
error = F_107 ( V_10 , V_536 ,
V_276 ) ;
break;
default:
error = F_120 ( V_10 , V_42 , V_333 ) ;
}
return error ;
}
static int F_236 ( struct V_42 * V_42 , unsigned long V_537 , int V_538 )
{
const struct V_10 * V_10 = F_65 () ;
int V_53 = 0 ;
if ( V_539 &&
( V_537 & V_540 ) && ( ! V_42 || ( ! V_538 && ( V_537 & V_541 ) ) ) ) {
V_53 = F_104 ( V_10 , V_10 , V_542 ) ;
if ( V_53 )
goto error;
}
if ( V_42 ) {
T_2 V_271 = V_321 ;
if ( V_538 && ( V_537 & V_541 ) )
V_271 |= V_325 ;
if ( V_537 & V_540 )
V_271 |= V_319 ;
return F_120 ( V_10 , V_42 , V_271 ) ;
}
error:
return V_53 ;
}
static int F_237 ( unsigned long V_543 )
{
int V_53 ;
V_53 = F_238 ( V_543 ) ;
if ( V_53 )
return V_53 ;
if ( V_543 < V_544 ) {
T_2 V_17 = F_22 () ;
V_53 = F_46 ( V_17 , V_17 , V_545 ,
V_546 , NULL ) ;
}
return V_53 ;
}
static int F_239 ( struct V_42 * V_42 , unsigned long V_547 ,
unsigned long V_537 , unsigned long V_80 )
{
if ( V_548 )
V_537 = V_547 ;
return F_236 ( V_42 , V_537 ,
( V_80 & V_549 ) == V_550 ) ;
}
static int F_240 ( struct V_551 * V_552 ,
unsigned long V_547 ,
unsigned long V_537 )
{
const struct V_10 * V_10 = F_65 () ;
if ( V_548 )
V_537 = V_547 ;
if ( V_539 &&
( V_537 & V_540 ) && ! ( V_552 -> V_553 & V_554 ) ) {
int V_53 = 0 ;
if ( V_552 -> V_555 >= V_552 -> V_556 -> V_557 &&
V_552 -> V_558 <= V_552 -> V_556 -> V_559 ) {
V_53 = F_104 ( V_10 , V_10 , V_560 ) ;
} else if ( ! V_552 -> V_561 &&
V_552 -> V_555 <= V_552 -> V_556 -> V_562 &&
V_552 -> V_558 >= V_552 -> V_556 -> V_562 ) {
V_53 = F_106 ( V_11 , V_563 ) ;
} else if ( V_552 -> V_561 && V_552 -> V_564 ) {
V_53 = F_120 ( V_10 , V_552 -> V_561 , V_565 ) ;
}
if ( V_53 )
return V_53 ;
}
return F_236 ( V_552 -> V_561 , V_537 , V_552 -> V_553 & V_566 ) ;
}
static int F_241 ( struct V_42 * V_42 , unsigned int V_523 )
{
const struct V_10 * V_10 = F_65 () ;
return F_120 ( V_10 , V_42 , V_567 ) ;
}
static int F_242 ( struct V_42 * V_42 , unsigned int V_523 ,
unsigned long V_524 )
{
const struct V_10 * V_10 = F_65 () ;
int V_568 = 0 ;
switch ( V_523 ) {
case V_569 :
if ( ( V_42 -> V_331 & V_332 ) && ! ( V_524 & V_332 ) ) {
V_568 = F_120 ( V_10 , V_42 , V_325 ) ;
break;
}
case V_570 :
case V_571 :
case V_572 :
case V_573 :
case V_574 :
case V_575 :
V_568 = F_120 ( V_10 , V_42 , 0 ) ;
break;
case V_576 :
case V_577 :
case V_578 :
case V_579 :
case V_580 :
case V_581 :
#if V_582 == 32
case V_583 :
case V_584 :
case V_585 :
#endif
V_568 = F_120 ( V_10 , V_42 , V_567 ) ;
break;
}
return V_568 ;
}
static int F_243 ( struct V_42 * V_42 )
{
struct V_43 * V_44 ;
V_44 = V_42 -> V_46 ;
V_44 -> V_45 = F_22 () ;
return 0 ;
}
static int F_244 ( struct V_20 * V_264 ,
struct V_586 * V_587 , int V_588 )
{
struct V_42 * V_42 ;
T_2 V_17 = F_18 ( V_264 ) ;
T_2 V_244 ;
struct V_43 * V_44 ;
V_42 = F_29 ( V_587 , struct V_42 , V_589 ) ;
V_44 = V_42 -> V_46 ;
if ( ! V_588 )
V_244 = F_103 ( V_590 ) ;
else
V_244 = F_103 ( V_588 ) ;
return F_46 ( V_44 -> V_45 , V_17 ,
V_257 , V_244 , NULL ) ;
}
static int F_245 ( struct V_42 * V_42 )
{
const struct V_10 * V_10 = F_65 () ;
return F_120 ( V_10 , V_42 , F_128 ( V_42 ) ) ;
}
static int F_246 ( struct V_42 * V_42 , const struct V_10 * V_10 )
{
struct V_43 * V_44 ;
struct V_23 * V_24 ;
V_44 = V_42 -> V_46 ;
V_24 = F_119 ( V_42 ) -> V_33 ;
V_44 -> V_521 = V_24 -> V_17 ;
V_44 -> V_522 = F_232 () ;
return F_118 ( V_10 , V_42 , F_129 ( V_42 ) ) ;
}
static int F_247 ( unsigned long V_591 )
{
return F_106 ( V_11 , V_592 ) ;
}
static int F_248 ( struct V_10 * V_10 , T_11 V_593 )
{
struct V_13 * V_14 ;
V_14 = F_15 ( sizeof( struct V_13 ) , V_593 ) ;
if ( ! V_14 )
return - V_27 ;
V_10 -> V_19 = V_14 ;
return 0 ;
}
static void F_249 ( struct V_10 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_19 ;
F_61 ( V_10 -> V_19 && ( unsigned long ) V_10 -> V_19 < V_234 ) ;
V_10 -> V_19 = ( void * ) 0x7UL ;
F_39 ( V_14 ) ;
}
static int F_250 ( struct V_10 * V_129 , const struct V_10 * V_128 ,
T_11 V_593 )
{
const struct V_13 * V_383 ;
struct V_13 * V_14 ;
V_383 = V_128 -> V_19 ;
V_14 = F_251 ( V_383 , sizeof( struct V_13 ) , V_593 ) ;
if ( ! V_14 )
return - V_27 ;
V_129 -> V_19 = V_14 ;
return 0 ;
}
static void F_252 ( struct V_10 * V_129 , const struct V_10 * V_128 )
{
const struct V_13 * V_383 = V_128 -> V_19 ;
struct V_13 * V_14 = V_129 -> V_19 ;
* V_14 = * V_383 ;
}
static int F_253 ( struct V_10 * V_129 , T_2 V_520 )
{
struct V_13 * V_14 = V_129 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_594 ;
V_594 = F_46 ( V_17 , V_520 ,
V_595 ,
V_596 ,
NULL ) ;
if ( V_594 == 0 ) {
V_14 -> V_17 = V_520 ;
V_14 -> V_288 = 0 ;
V_14 -> V_386 = 0 ;
V_14 -> V_387 = 0 ;
}
return V_594 ;
}
static int F_254 ( struct V_10 * V_129 , struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_13 * V_14 = V_129 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_594 ;
V_594 = F_46 ( V_17 , V_24 -> V_17 ,
V_595 ,
V_597 ,
NULL ) ;
if ( V_594 == 0 )
V_14 -> V_288 = V_24 -> V_17 ;
return V_594 ;
}
static int F_255 ( char * V_598 )
{
T_2 V_17 ;
struct V_267 V_268 ;
V_17 = F_18 ( V_11 ) ;
V_268 . type = V_599 ;
V_268 . V_273 . V_598 = V_598 ;
return F_46 ( V_17 , V_18 , V_278 ,
V_600 , & V_268 ) ;
}
static int F_256 ( struct V_20 * V_146 , T_12 V_601 )
{
return F_106 ( V_146 , V_602 ) ;
}
static int F_257 ( struct V_20 * V_146 )
{
return F_106 ( V_146 , V_603 ) ;
}
static int F_258 ( struct V_20 * V_146 )
{
return F_106 ( V_146 , V_604 ) ;
}
static void F_259 ( struct V_20 * V_146 , T_2 * V_520 )
{
* V_520 = F_18 ( V_146 ) ;
}
static int F_260 ( struct V_20 * V_146 , int V_605 )
{
int V_53 ;
V_53 = F_261 ( V_146 , V_605 ) ;
if ( V_53 )
return V_53 ;
return F_106 ( V_146 , V_606 ) ;
}
static int F_262 ( struct V_20 * V_146 , int V_607 )
{
int V_53 ;
V_53 = F_263 ( V_146 , V_607 ) ;
if ( V_53 )
return V_53 ;
return F_106 ( V_146 , V_606 ) ;
}
static int F_264 ( struct V_20 * V_146 )
{
return F_106 ( V_146 , V_608 ) ;
}
static int F_265 ( struct V_20 * V_146 , unsigned int V_609 ,
struct V_423 * V_610 )
{
struct V_423 * V_611 = V_146 -> signal -> V_424 + V_609 ;
if ( V_611 -> V_431 != V_610 -> V_431 )
return F_106 ( V_146 , V_612 ) ;
return 0 ;
}
static int F_266 ( struct V_20 * V_146 )
{
int V_53 ;
V_53 = F_267 ( V_146 ) ;
if ( V_53 )
return V_53 ;
return F_106 ( V_146 , V_606 ) ;
}
static int F_268 ( struct V_20 * V_146 )
{
return F_106 ( V_146 , V_608 ) ;
}
static int F_269 ( struct V_20 * V_146 )
{
return F_106 ( V_146 , V_606 ) ;
}
static int F_270 ( struct V_20 * V_146 , struct V_613 * V_614 ,
int V_243 , T_2 V_520 )
{
T_2 V_244 ;
int V_53 ;
if ( ! V_243 )
V_244 = V_615 ;
else
V_244 = F_103 ( V_243 ) ;
if ( V_520 )
V_53 = F_46 ( V_520 , F_18 ( V_146 ) ,
V_257 , V_244 , NULL ) ;
else
V_53 = F_106 ( V_146 , V_244 ) ;
return V_53 ;
}
static int F_271 ( struct V_20 * V_146 )
{
return F_105 ( V_146 , V_11 , V_246 ) ;
}
static void F_272 ( struct V_20 * V_146 ,
struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 = F_18 ( V_146 ) ;
V_24 -> V_17 = V_17 ;
V_24 -> V_125 = 1 ;
}
static int F_273 ( struct V_616 * V_617 ,
struct V_267 * V_268 , T_13 * V_618 )
{
int V_619 , V_620 , V_594 = - V_91 ;
struct V_621 V_622 , * V_623 ;
V_619 = F_274 ( V_617 ) ;
V_623 = F_275 ( V_617 , V_619 , sizeof( V_622 ) , & V_622 ) ;
if ( V_623 == NULL )
goto V_74;
V_620 = V_623 -> V_624 * 4 ;
if ( V_620 < sizeof( V_622 ) )
goto V_74;
V_268 -> V_273 . V_625 -> V_626 . V_627 = V_623 -> V_627 ;
V_268 -> V_273 . V_625 -> V_626 . V_628 = V_623 -> V_628 ;
V_594 = 0 ;
if ( V_618 )
* V_618 = V_623 -> V_184 ;
switch ( V_623 -> V_184 ) {
case V_186 : {
struct V_629 V_630 , * V_631 ;
if ( F_276 ( V_623 -> V_632 ) & V_633 )
break;
V_619 += V_620 ;
V_631 = F_275 ( V_617 , V_619 , sizeof( V_630 ) , & V_630 ) ;
if ( V_631 == NULL )
break;
V_268 -> V_273 . V_625 -> V_634 = V_631 -> V_635 ;
V_268 -> V_273 . V_625 -> V_636 = V_631 -> V_637 ;
break;
}
case V_187 : {
struct V_638 V_639 , * V_640 ;
if ( F_276 ( V_623 -> V_632 ) & V_633 )
break;
V_619 += V_620 ;
V_640 = F_275 ( V_617 , V_619 , sizeof( V_639 ) , & V_639 ) ;
if ( V_640 == NULL )
break;
V_268 -> V_273 . V_625 -> V_634 = V_640 -> V_635 ;
V_268 -> V_273 . V_625 -> V_636 = V_640 -> V_637 ;
break;
}
case V_641 : {
struct V_642 V_643 , * V_644 ;
if ( F_276 ( V_623 -> V_632 ) & V_633 )
break;
V_619 += V_620 ;
V_644 = F_275 ( V_617 , V_619 , sizeof( V_643 ) , & V_643 ) ;
if ( V_644 == NULL )
break;
V_268 -> V_273 . V_625 -> V_634 = V_644 -> V_645 ;
V_268 -> V_273 . V_625 -> V_636 = V_644 -> V_646 ;
break;
}
default:
break;
}
V_74:
return V_594 ;
}
static int F_277 ( struct V_616 * V_617 ,
struct V_267 * V_268 , T_13 * V_618 )
{
T_13 V_647 ;
int V_594 = - V_91 , V_619 ;
struct V_648 V_649 , * V_650 ;
T_14 V_632 ;
V_619 = F_274 ( V_617 ) ;
V_650 = F_275 ( V_617 , V_619 , sizeof( V_649 ) , & V_649 ) ;
if ( V_650 == NULL )
goto V_74;
V_268 -> V_273 . V_625 -> V_651 . V_627 = V_650 -> V_627 ;
V_268 -> V_273 . V_625 -> V_651 . V_628 = V_650 -> V_628 ;
V_594 = 0 ;
V_647 = V_650 -> V_647 ;
V_619 += sizeof( V_649 ) ;
V_619 = F_278 ( V_617 , V_619 , & V_647 , & V_632 ) ;
if ( V_619 < 0 )
goto V_74;
if ( V_618 )
* V_618 = V_647 ;
switch ( V_647 ) {
case V_186 : {
struct V_629 V_630 , * V_631 ;
V_631 = F_275 ( V_617 , V_619 , sizeof( V_630 ) , & V_630 ) ;
if ( V_631 == NULL )
break;
V_268 -> V_273 . V_625 -> V_634 = V_631 -> V_635 ;
V_268 -> V_273 . V_625 -> V_636 = V_631 -> V_637 ;
break;
}
case V_187 : {
struct V_638 V_639 , * V_640 ;
V_640 = F_275 ( V_617 , V_619 , sizeof( V_639 ) , & V_639 ) ;
if ( V_640 == NULL )
break;
V_268 -> V_273 . V_625 -> V_634 = V_640 -> V_635 ;
V_268 -> V_273 . V_625 -> V_636 = V_640 -> V_637 ;
break;
}
case V_641 : {
struct V_642 V_643 , * V_644 ;
V_644 = F_275 ( V_617 , V_619 , sizeof( V_643 ) , & V_643 ) ;
if ( V_644 == NULL )
break;
V_268 -> V_273 . V_625 -> V_634 = V_644 -> V_645 ;
V_268 -> V_273 . V_625 -> V_636 = V_644 -> V_646 ;
break;
}
default:
break;
}
V_74:
return V_594 ;
}
static int F_279 ( struct V_616 * V_617 , struct V_267 * V_268 ,
char * * V_652 , int V_653 , T_13 * V_618 )
{
char * V_654 ;
int V_594 ;
switch ( V_268 -> V_273 . V_625 -> V_188 ) {
case V_195 :
V_594 = F_273 ( V_617 , V_268 , V_618 ) ;
if ( V_594 )
goto V_655;
V_654 = ( char * ) ( V_653 ? & V_268 -> V_273 . V_625 -> V_626 . V_627 :
& V_268 -> V_273 . V_625 -> V_626 . V_628 ) ;
goto V_656;
#if F_280 ( V_657 ) || F_280 ( V_658 )
case V_196 :
V_594 = F_277 ( V_617 , V_268 , V_618 ) ;
if ( V_594 )
goto V_655;
V_654 = ( char * ) ( V_653 ? & V_268 -> V_273 . V_625 -> V_651 . V_627 :
& V_268 -> V_273 . V_625 -> V_651 . V_628 ) ;
goto V_656;
#endif
default:
V_654 = NULL ;
goto V_656;
}
V_655:
F_50 ( V_71
L_45
L_46 ) ;
return V_594 ;
V_656:
if ( V_652 )
* V_652 = V_654 ;
return 0 ;
}
static int F_281 ( struct V_616 * V_617 , T_4 V_188 , T_2 * V_17 )
{
int V_568 ;
T_2 V_659 ;
T_2 V_660 ;
T_2 V_661 ;
V_568 = F_282 ( V_617 , & V_659 ) ;
if ( F_115 ( V_568 ) )
return - V_394 ;
V_568 = F_283 ( V_617 , V_188 , & V_661 , & V_660 ) ;
if ( F_115 ( V_568 ) )
return - V_394 ;
V_568 = F_284 ( V_660 , V_661 , V_659 , V_17 ) ;
if ( F_115 ( V_568 ) ) {
F_50 ( V_71
L_47
L_48 ) ;
return - V_394 ;
}
return 0 ;
}
static int F_285 ( T_2 V_662 , T_2 V_663 , T_2 * V_664 )
{
int V_568 = 0 ;
if ( V_663 != V_665 )
V_568 = F_286 ( V_662 , V_663 , V_664 ) ;
else
* V_664 = V_662 ;
return V_568 ;
}
static int F_287 ( const struct V_13 * V_14 ,
T_4 V_666 , T_2 * V_667 )
{
if ( V_14 -> V_387 > V_665 ) {
* V_667 = V_14 -> V_387 ;
return 0 ;
}
return F_101 ( V_14 -> V_17 , V_14 -> V_17 , V_666 , NULL ,
V_667 ) ;
}
static int F_288 ( struct V_20 * V_21 , struct V_668 * V_669 , T_2 V_254 )
{
struct V_670 * V_671 = V_669 -> V_672 ;
struct V_267 V_268 ;
struct V_673 V_625 = { 0 ,} ;
T_2 V_256 = F_18 ( V_21 ) ;
if ( V_671 -> V_17 == V_18 )
return 0 ;
V_268 . type = V_674 ;
V_268 . V_273 . V_625 = & V_625 ;
V_268 . V_273 . V_625 -> V_669 = V_669 ;
return F_46 ( V_256 , V_671 -> V_17 , V_671 -> V_31 , V_254 , & V_268 ) ;
}
static int F_289 ( int V_188 , int type ,
int V_184 , int V_675 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_287 ;
T_4 V_666 ;
int V_53 ;
if ( V_675 )
return 0 ;
V_666 = F_85 ( V_188 , type , V_184 ) ;
V_53 = F_287 ( V_14 , V_666 , & V_287 ) ;
if ( V_53 )
return V_53 ;
return F_46 ( V_14 -> V_17 , V_287 , V_666 , V_676 , NULL ) ;
}
static int F_290 ( struct V_677 * V_668 , int V_188 ,
int type , int V_184 , int V_675 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_24 = F_291 ( V_668 ) -> V_33 ;
struct V_670 * V_671 ;
int V_568 = 0 ;
V_24 -> V_31 = F_85 ( V_188 , type , V_184 ) ;
if ( V_675 )
V_24 -> V_17 = V_18 ;
else {
V_568 = F_287 ( V_14 , V_24 -> V_31 , & ( V_24 -> V_17 ) ) ;
if ( V_568 )
return V_568 ;
}
V_24 -> V_125 = 1 ;
if ( V_668 -> V_669 ) {
V_671 = V_668 -> V_669 -> V_672 ;
V_671 -> V_17 = V_24 -> V_17 ;
V_671 -> V_31 = V_24 -> V_31 ;
V_568 = F_292 ( V_668 -> V_669 , V_188 ) ;
}
return V_568 ;
}
static int F_293 ( struct V_677 * V_668 , struct V_678 * V_679 , int V_680 )
{
struct V_668 * V_669 = V_668 -> V_669 ;
T_4 V_188 ;
int V_568 ;
V_568 = F_288 ( V_11 , V_669 , V_681 ) ;
if ( V_568 )
goto V_74;
V_188 = V_669 -> V_682 ;
if ( V_188 == V_195 || V_188 == V_196 ) {
char * V_654 ;
struct V_670 * V_671 = V_669 -> V_672 ;
struct V_267 V_268 ;
struct V_673 V_625 = { 0 ,} ;
struct V_683 * V_684 = NULL ;
struct V_685 * V_686 = NULL ;
unsigned short V_687 ;
T_2 V_17 , V_688 ;
if ( V_188 == V_195 ) {
V_684 = (struct V_683 * ) V_679 ;
V_687 = F_276 ( V_684 -> V_689 ) ;
V_654 = ( char * ) & V_684 -> V_690 . V_691 ;
} else {
V_686 = (struct V_685 * ) V_679 ;
V_687 = F_276 ( V_686 -> V_692 ) ;
V_654 = ( char * ) & V_686 -> V_693 . V_694 ;
}
if ( V_687 ) {
int V_695 , V_696 ;
F_294 ( F_295 ( V_669 ) , & V_695 , & V_696 ) ;
if ( V_687 < V_697 ( V_698, V_695 ) || V_687 > V_696 ) {
V_568 = F_296 ( V_669 -> V_699 ,
V_687 , & V_17 ) ;
if ( V_568 )
goto V_74;
V_268 . type = V_674 ;
V_268 . V_273 . V_625 = & V_625 ;
V_268 . V_273 . V_625 -> V_634 = F_297 ( V_687 ) ;
V_268 . V_273 . V_625 -> V_188 = V_188 ;
V_568 = F_46 ( V_671 -> V_17 , V_17 ,
V_671 -> V_31 ,
V_700 , & V_268 ) ;
if ( V_568 )
goto V_74;
}
}
switch ( V_671 -> V_31 ) {
case V_197 :
V_688 = V_701 ;
break;
case V_199 :
V_688 = V_702 ;
break;
case V_201 :
V_688 = V_703 ;
break;
default:
V_688 = V_704 ;
break;
}
V_568 = F_298 ( V_654 , V_188 , & V_17 ) ;
if ( V_568 )
goto V_74;
V_268 . type = V_674 ;
V_268 . V_273 . V_625 = & V_625 ;
V_268 . V_273 . V_625 -> V_634 = F_297 ( V_687 ) ;
V_268 . V_273 . V_625 -> V_188 = V_188 ;
if ( V_188 == V_195 )
V_268 . V_273 . V_625 -> V_626 . V_627 = V_684 -> V_690 . V_691 ;
else
V_268 . V_273 . V_625 -> V_651 . V_627 = V_686 -> V_693 ;
V_568 = F_46 ( V_671 -> V_17 , V_17 ,
V_671 -> V_31 , V_688 , & V_268 ) ;
if ( V_568 )
goto V_74;
}
V_74:
return V_568 ;
}
static int F_299 ( struct V_677 * V_668 , struct V_678 * V_679 , int V_680 )
{
struct V_668 * V_669 = V_668 -> V_669 ;
struct V_670 * V_671 = V_669 -> V_672 ;
int V_568 ;
V_568 = F_288 ( V_11 , V_669 , V_705 ) ;
if ( V_568 )
return V_568 ;
if ( V_671 -> V_31 == V_197 ||
V_671 -> V_31 == V_201 ) {
struct V_267 V_268 ;
struct V_673 V_625 = { 0 ,} ;
struct V_683 * V_684 = NULL ;
struct V_685 * V_686 = NULL ;
unsigned short V_687 ;
T_2 V_17 , V_244 ;
if ( V_669 -> V_682 == V_195 ) {
V_684 = (struct V_683 * ) V_679 ;
if ( V_680 < sizeof( struct V_683 ) )
return - V_91 ;
V_687 = F_276 ( V_684 -> V_689 ) ;
} else {
V_686 = (struct V_685 * ) V_679 ;
if ( V_680 < V_706 )
return - V_91 ;
V_687 = F_276 ( V_686 -> V_692 ) ;
}
V_568 = F_296 ( V_669 -> V_699 , V_687 , & V_17 ) ;
if ( V_568 )
goto V_74;
V_244 = ( V_671 -> V_31 == V_197 ) ?
V_707 : V_708 ;
V_268 . type = V_674 ;
V_268 . V_273 . V_625 = & V_625 ;
V_268 . V_273 . V_625 -> V_636 = F_297 ( V_687 ) ;
V_268 . V_273 . V_625 -> V_188 = V_669 -> V_682 ;
V_568 = F_46 ( V_671 -> V_17 , V_17 , V_671 -> V_31 , V_244 , & V_268 ) ;
if ( V_568 )
goto V_74;
}
V_568 = F_300 ( V_669 , V_679 ) ;
V_74:
return V_568 ;
}
static int F_301 ( struct V_677 * V_668 , int V_709 )
{
return F_288 ( V_11 , V_668 -> V_669 , V_710 ) ;
}
static int F_302 ( struct V_677 * V_668 , struct V_677 * V_711 )
{
int V_568 ;
struct V_23 * V_24 ;
struct V_23 * V_142 ;
V_568 = F_288 ( V_11 , V_668 -> V_669 , V_712 ) ;
if ( V_568 )
return V_568 ;
V_142 = F_291 ( V_711 ) -> V_33 ;
V_24 = F_291 ( V_668 ) -> V_33 ;
V_142 -> V_31 = V_24 -> V_31 ;
V_142 -> V_17 = V_24 -> V_17 ;
V_142 -> V_125 = 1 ;
return 0 ;
}
static int F_303 ( struct V_677 * V_668 , struct V_713 * V_714 ,
int V_508 )
{
return F_288 ( V_11 , V_668 -> V_669 , V_715 ) ;
}
static int F_304 ( struct V_677 * V_668 , struct V_713 * V_714 ,
int V_508 , int V_80 )
{
return F_288 ( V_11 , V_668 -> V_669 , V_716 ) ;
}
static int F_305 ( struct V_677 * V_668 )
{
return F_288 ( V_11 , V_668 -> V_669 , V_717 ) ;
}
static int F_306 ( struct V_677 * V_668 )
{
return F_288 ( V_11 , V_668 -> V_669 , V_717 ) ;
}
static int F_307 ( struct V_677 * V_668 , int V_718 , int V_719 )
{
int V_568 ;
V_568 = F_288 ( V_11 , V_668 -> V_669 , V_720 ) ;
if ( V_568 )
return V_568 ;
return F_308 ( V_668 , V_718 , V_719 ) ;
}
static int F_309 ( struct V_677 * V_668 , int V_718 ,
int V_719 )
{
return F_288 ( V_11 , V_668 -> V_669 , V_721 ) ;
}
static int F_310 ( struct V_677 * V_668 , int V_722 )
{
return F_288 ( V_11 , V_668 -> V_669 , V_723 ) ;
}
static int F_311 ( struct V_668 * V_668 ,
struct V_668 * V_724 ,
struct V_668 * V_725 )
{
struct V_670 * V_726 = V_668 -> V_672 ;
struct V_670 * V_727 = V_724 -> V_672 ;
struct V_670 * V_728 = V_725 -> V_672 ;
struct V_267 V_268 ;
struct V_673 V_625 = { 0 ,} ;
int V_568 ;
V_268 . type = V_674 ;
V_268 . V_273 . V_625 = & V_625 ;
V_268 . V_273 . V_625 -> V_669 = V_724 ;
V_568 = F_46 ( V_726 -> V_17 , V_727 -> V_17 ,
V_727 -> V_31 ,
V_729 , & V_268 ) ;
if ( V_568 )
return V_568 ;
V_728 -> V_730 = V_726 -> V_17 ;
V_568 = F_286 ( V_727 -> V_17 , V_726 -> V_17 ,
& V_728 -> V_17 ) ;
if ( V_568 )
return V_568 ;
V_726 -> V_730 = V_728 -> V_17 ;
return 0 ;
}
static int F_312 ( struct V_677 * V_668 ,
struct V_677 * V_724 )
{
struct V_670 * V_731 = V_668 -> V_669 -> V_672 ;
struct V_670 * V_732 = V_724 -> V_669 -> V_672 ;
struct V_267 V_268 ;
struct V_673 V_625 = { 0 ,} ;
V_268 . type = V_674 ;
V_268 . V_273 . V_625 = & V_625 ;
V_268 . V_273 . V_625 -> V_669 = V_724 -> V_669 ;
return F_46 ( V_731 -> V_17 , V_732 -> V_17 , V_732 -> V_31 , V_733 ,
& V_268 ) ;
}
static int F_313 ( int V_734 , char * V_654 , T_4 V_188 ,
T_2 V_730 ,
struct V_267 * V_268 )
{
int V_568 ;
T_2 V_735 ;
T_2 V_736 ;
V_568 = F_314 ( V_734 , & V_735 ) ;
if ( V_568 )
return V_568 ;
V_568 = F_46 ( V_730 , V_735 ,
V_737 , V_738 , V_268 ) ;
if ( V_568 )
return V_568 ;
V_568 = F_298 ( V_654 , V_188 , & V_736 ) ;
if ( V_568 )
return V_568 ;
return F_46 ( V_730 , V_736 ,
V_739 , V_740 , V_268 ) ;
}
static int F_315 ( struct V_668 * V_669 , struct V_616 * V_617 ,
T_4 V_188 )
{
int V_568 = 0 ;
struct V_670 * V_671 = V_669 -> V_672 ;
T_2 V_662 = V_671 -> V_17 ;
struct V_267 V_268 ;
struct V_673 V_625 = { 0 ,} ;
char * V_654 ;
V_268 . type = V_674 ;
V_268 . V_273 . V_625 = & V_625 ;
V_268 . V_273 . V_625 -> V_741 = V_617 -> V_742 ;
V_268 . V_273 . V_625 -> V_188 = V_188 ;
V_568 = F_279 ( V_617 , & V_268 , & V_654 , 1 , NULL ) ;
if ( V_568 )
return V_568 ;
if ( F_4 () ) {
V_568 = F_46 ( V_662 , V_617 -> V_743 , V_744 ,
V_745 , & V_268 ) ;
if ( V_568 )
return V_568 ;
}
V_568 = F_316 ( V_671 , V_617 , V_188 , & V_268 ) ;
if ( V_568 )
return V_568 ;
V_568 = F_317 ( V_671 -> V_17 , V_617 , & V_268 ) ;
return V_568 ;
}
static int F_318 ( struct V_668 * V_669 , struct V_616 * V_617 )
{
int V_568 ;
struct V_670 * V_671 = V_669 -> V_672 ;
T_4 V_188 = V_669 -> V_682 ;
T_2 V_662 = V_671 -> V_17 ;
struct V_267 V_268 ;
struct V_673 V_625 = { 0 ,} ;
char * V_654 ;
T_13 V_746 ;
T_13 V_747 ;
if ( V_188 != V_195 && V_188 != V_196 )
return 0 ;
if ( V_188 == V_196 && V_617 -> V_184 == F_297 ( V_748 ) )
V_188 = V_195 ;
if ( ! V_749 )
return F_315 ( V_669 , V_617 , V_188 ) ;
V_746 = F_4 () ;
V_747 = F_6 () ;
if ( ! V_746 && ! V_747 )
return 0 ;
V_268 . type = V_674 ;
V_268 . V_273 . V_625 = & V_625 ;
V_268 . V_273 . V_625 -> V_741 = V_617 -> V_742 ;
V_268 . V_273 . V_625 -> V_188 = V_188 ;
V_568 = F_279 ( V_617 , & V_268 , & V_654 , 1 , NULL ) ;
if ( V_568 )
return V_568 ;
if ( V_747 ) {
T_2 V_730 ;
V_568 = F_281 ( V_617 , V_188 , & V_730 ) ;
if ( V_568 )
return V_568 ;
V_568 = F_313 ( V_617 -> V_742 , V_654 , V_188 ,
V_730 , & V_268 ) ;
if ( V_568 ) {
F_319 ( V_617 , V_568 , 0 ) ;
return V_568 ;
}
V_568 = F_46 ( V_662 , V_730 , V_750 ,
V_751 , & V_268 ) ;
if ( V_568 ) {
F_319 ( V_617 , V_568 , 0 ) ;
return V_568 ;
}
}
if ( V_746 ) {
V_568 = F_46 ( V_662 , V_617 -> V_743 , V_744 ,
V_745 , & V_268 ) ;
if ( V_568 )
return V_568 ;
}
return V_568 ;
}
static int F_320 ( struct V_677 * V_668 , char T_15 * V_752 ,
int T_15 * V_753 , unsigned V_89 )
{
int V_568 = 0 ;
char * V_754 ;
T_2 V_755 ;
struct V_670 * V_671 = V_668 -> V_669 -> V_672 ;
T_2 V_730 = V_665 ;
if ( V_671 -> V_31 == V_192 ||
V_671 -> V_31 == V_197 )
V_730 = V_671 -> V_730 ;
if ( V_730 == V_665 )
return - V_756 ;
V_568 = F_60 ( V_730 , & V_754 , & V_755 ) ;
if ( V_568 )
return V_568 ;
if ( V_755 > V_89 ) {
V_568 = - V_237 ;
goto V_757;
}
if ( F_321 ( V_752 , V_754 , V_755 ) )
V_568 = - V_758 ;
V_757:
if ( F_322 ( V_755 , V_753 ) )
V_568 = - V_758 ;
F_39 ( V_754 ) ;
return V_568 ;
}
static int F_323 ( struct V_677 * V_668 , struct V_616 * V_617 , T_2 * V_520 )
{
T_2 V_759 = V_665 ;
T_4 V_188 ;
if ( V_617 && V_617 -> V_184 == F_297 ( V_748 ) )
V_188 = V_195 ;
else if ( V_617 && V_617 -> V_184 == F_297 ( V_760 ) )
V_188 = V_196 ;
else if ( V_668 )
V_188 = V_668 -> V_669 -> V_682 ;
else
goto V_74;
if ( V_668 && V_188 == V_189 )
F_229 ( F_291 ( V_668 ) , & V_759 ) ;
else if ( V_617 )
F_281 ( V_617 , V_188 , & V_759 ) ;
V_74:
* V_520 = V_759 ;
if ( V_759 == V_665 )
return - V_91 ;
return 0 ;
}
static int F_324 ( struct V_668 * V_669 , int V_188 , T_11 V_761 )
{
struct V_670 * V_671 ;
V_671 = F_15 ( sizeof( * V_671 ) , V_761 ) ;
if ( ! V_671 )
return - V_27 ;
V_671 -> V_730 = V_30 ;
V_671 -> V_17 = V_30 ;
F_325 ( V_671 ) ;
V_669 -> V_672 = V_671 ;
return 0 ;
}
static void F_326 ( struct V_668 * V_669 )
{
struct V_670 * V_671 = V_669 -> V_672 ;
V_669 -> V_672 = NULL ;
F_327 ( V_671 ) ;
F_39 ( V_671 ) ;
}
static void F_328 ( const struct V_668 * V_669 , struct V_668 * V_725 )
{
struct V_670 * V_671 = V_669 -> V_672 ;
struct V_670 * V_762 = V_725 -> V_672 ;
V_762 -> V_17 = V_671 -> V_17 ;
V_762 -> V_730 = V_671 -> V_730 ;
V_762 -> V_31 = V_671 -> V_31 ;
F_325 ( V_762 ) ;
}
static void F_329 ( struct V_668 * V_669 , T_2 * V_520 )
{
if ( ! V_669 )
* V_520 = V_763 ;
else {
struct V_670 * V_671 = V_669 -> V_672 ;
* V_520 = V_671 -> V_17 ;
}
}
static void F_330 ( struct V_668 * V_669 , struct V_677 * V_340 )
{
struct V_23 * V_24 = F_291 ( V_340 ) -> V_33 ;
struct V_670 * V_671 = V_669 -> V_672 ;
if ( V_669 -> V_682 == V_195 || V_669 -> V_682 == V_196 ||
V_669 -> V_682 == V_189 )
V_24 -> V_17 = V_671 -> V_17 ;
V_671 -> V_31 = V_24 -> V_31 ;
}
static int F_331 ( struct V_668 * V_669 , struct V_616 * V_617 ,
struct V_764 * V_765 )
{
struct V_670 * V_671 = V_669 -> V_672 ;
int V_568 ;
T_4 V_188 = V_765 -> V_766 -> V_188 ;
T_2 V_767 ;
T_2 V_768 ;
V_568 = F_281 ( V_617 , V_188 , & V_768 ) ;
if ( V_568 )
return V_568 ;
V_568 = F_285 ( V_671 -> V_17 , V_768 , & V_767 ) ;
if ( V_568 )
return V_568 ;
V_765 -> V_520 = V_767 ;
V_765 -> V_759 = V_768 ;
return F_332 ( V_765 , V_188 ) ;
}
static void F_333 ( struct V_668 * V_725 ,
const struct V_764 * V_765 )
{
struct V_670 * V_762 = V_725 -> V_672 ;
V_762 -> V_17 = V_765 -> V_520 ;
V_762 -> V_730 = V_765 -> V_759 ;
F_334 ( V_725 , V_765 -> V_766 -> V_188 ) ;
}
static void F_335 ( struct V_668 * V_669 , struct V_616 * V_617 )
{
T_4 V_188 = V_669 -> V_682 ;
struct V_670 * V_671 = V_669 -> V_672 ;
if ( V_188 == V_196 && V_617 -> V_184 == F_297 ( V_748 ) )
V_188 = V_195 ;
F_281 ( V_617 , V_188 , & V_671 -> V_730 ) ;
}
static void F_336 ( struct V_616 * V_617 , struct V_668 * V_669 )
{
F_337 ( V_617 , V_669 ) ;
}
static int F_338 ( T_2 V_17 )
{
const struct V_13 * V_769 ;
T_2 V_256 ;
V_769 = F_23 () ;
V_256 = V_769 -> V_17 ;
return F_46 ( V_256 , V_17 , V_744 , V_770 , NULL ) ;
}
static void F_339 ( void )
{
F_340 ( & V_7 ) ;
}
static void F_341 ( void )
{
F_342 ( & V_7 ) ;
}
static void F_343 ( const struct V_764 * V_765 ,
struct V_771 * V_772 )
{
V_772 -> V_773 = V_765 -> V_520 ;
}
static int F_344 ( void * * V_19 )
{
struct V_774 * V_775 ;
V_775 = F_15 ( sizeof( * V_775 ) , V_15 ) ;
if ( ! V_775 )
return - V_27 ;
V_775 -> V_17 = F_22 () ;
* V_19 = V_775 ;
return 0 ;
}
static void F_345 ( void * V_19 )
{
F_39 ( V_19 ) ;
}
static int F_346 ( void )
{
T_2 V_17 = F_22 () ;
return F_46 ( V_17 , V_17 , V_776 , V_777 ,
NULL ) ;
}
static int F_347 ( void * V_19 )
{
struct V_774 * V_775 = V_19 ;
return F_46 ( F_22 () , V_775 -> V_17 , V_776 ,
V_778 , NULL ) ;
}
static int F_348 ( struct V_668 * V_669 , void * V_19 )
{
struct V_774 * V_775 = V_19 ;
struct V_670 * V_671 = V_669 -> V_672 ;
V_671 -> V_17 = V_775 -> V_17 ;
V_671 -> V_31 = V_776 ;
return 0 ;
}
static int F_349 ( void * V_19 )
{
struct V_774 * V_775 = V_19 ;
T_2 V_17 = F_22 () ;
int V_568 ;
V_568 = F_46 ( V_17 , V_775 -> V_17 , V_776 ,
V_779 , NULL ) ;
if ( V_568 )
return V_568 ;
V_568 = F_46 ( V_17 , V_17 , V_776 ,
V_780 , NULL ) ;
if ( V_568 )
return V_568 ;
V_775 -> V_17 = V_17 ;
return 0 ;
}
static int F_350 ( struct V_668 * V_669 , struct V_616 * V_617 )
{
int V_568 = 0 ;
T_2 V_244 ;
struct V_781 * V_782 ;
struct V_670 * V_671 = V_669 -> V_672 ;
if ( V_617 -> V_89 < V_783 ) {
V_568 = - V_91 ;
goto V_74;
}
V_782 = F_351 ( V_617 ) ;
V_568 = F_352 ( V_671 -> V_31 , V_782 -> V_784 , & V_244 ) ;
if ( V_568 ) {
if ( V_568 == - V_91 ) {
F_353 ( V_11 -> V_514 , V_15 , V_515 ,
L_49
L_50 ,
V_782 -> V_784 , V_671 -> V_31 ) ;
if ( ! V_3 || F_354 () )
V_568 = 0 ;
}
if ( V_568 == - V_785 )
V_568 = 0 ;
goto V_74;
}
V_568 = F_288 ( V_11 , V_669 , V_244 ) ;
V_74:
return V_568 ;
}
static unsigned int F_355 ( struct V_616 * V_617 , int V_734 ,
T_4 V_188 )
{
int V_568 ;
char * V_654 ;
T_2 V_730 ;
struct V_267 V_268 ;
struct V_673 V_625 = { 0 ,} ;
T_13 V_746 ;
T_13 V_786 ;
T_13 V_747 ;
if ( ! V_749 )
return V_787 ;
V_746 = F_4 () ;
V_786 = F_7 () ;
V_747 = F_6 () ;
if ( ! V_746 && ! V_747 )
return V_787 ;
if ( F_281 ( V_617 , V_188 , & V_730 ) != 0 )
return V_788 ;
V_268 . type = V_674 ;
V_268 . V_273 . V_625 = & V_625 ;
V_268 . V_273 . V_625 -> V_741 = V_734 ;
V_268 . V_273 . V_625 -> V_188 = V_188 ;
if ( F_279 ( V_617 , & V_268 , & V_654 , 1 , NULL ) != 0 )
return V_788 ;
if ( V_747 ) {
V_568 = F_313 ( V_734 , V_654 , V_188 ,
V_730 , & V_268 ) ;
if ( V_568 ) {
F_319 ( V_617 , V_568 , 1 ) ;
return V_788 ;
}
}
if ( V_746 )
if ( F_46 ( V_730 , V_617 -> V_743 ,
V_744 , V_789 , & V_268 ) )
return V_788 ;
if ( V_786 )
if ( F_356 ( V_617 , V_188 , V_730 ) != 0 )
return V_788 ;
return V_787 ;
}
static unsigned int F_357 ( const struct V_790 * V_791 ,
struct V_616 * V_617 ,
const struct V_792 * V_793 ,
const struct V_792 * V_74 ,
int (* F_358)( struct V_616 * ) )
{
return F_355 ( V_617 , V_793 -> V_734 , V_195 ) ;
}
static unsigned int F_359 ( const struct V_790 * V_791 ,
struct V_616 * V_617 ,
const struct V_792 * V_793 ,
const struct V_792 * V_74 ,
int (* F_358)( struct V_616 * ) )
{
return F_355 ( V_617 , V_793 -> V_734 , V_196 ) ;
}
static unsigned int F_360 ( struct V_616 * V_617 ,
T_4 V_188 )
{
struct V_668 * V_669 ;
T_2 V_17 ;
if ( ! F_7 () )
return V_787 ;
V_669 = V_617 -> V_669 ;
if ( V_669 ) {
struct V_670 * V_671 ;
if ( V_669 -> V_794 == V_795 )
return V_787 ;
V_671 = V_669 -> V_672 ;
V_17 = V_671 -> V_17 ;
} else
V_17 = V_18 ;
if ( F_356 ( V_617 , V_188 , V_17 ) != 0 )
return V_788 ;
return V_787 ;
}
static unsigned int F_361 ( const struct V_790 * V_791 ,
struct V_616 * V_617 ,
const struct V_792 * V_793 ,
const struct V_792 * V_74 ,
int (* F_358)( struct V_616 * ) )
{
return F_360 ( V_617 , V_195 ) ;
}
static unsigned int F_362 ( struct V_616 * V_617 ,
int V_734 ,
T_4 V_188 )
{
struct V_668 * V_669 = V_617 -> V_669 ;
struct V_670 * V_671 ;
struct V_267 V_268 ;
struct V_673 V_625 = { 0 ,} ;
char * V_654 ;
T_13 V_618 ;
if ( V_669 == NULL )
return V_787 ;
V_671 = V_669 -> V_672 ;
V_268 . type = V_674 ;
V_268 . V_273 . V_625 = & V_625 ;
V_268 . V_273 . V_625 -> V_741 = V_734 ;
V_268 . V_273 . V_625 -> V_188 = V_188 ;
if ( F_279 ( V_617 , & V_268 , & V_654 , 0 , & V_618 ) )
return V_788 ;
if ( F_4 () )
if ( F_46 ( V_671 -> V_17 , V_617 -> V_743 ,
V_744 , V_796 , & V_268 ) )
return F_363 ( - V_797 ) ;
if ( F_364 ( V_671 -> V_17 , V_617 , & V_268 , V_618 ) )
return F_363 ( - V_797 ) ;
return V_787 ;
}
static unsigned int F_365 ( struct V_616 * V_617 , int V_734 ,
T_4 V_188 )
{
T_2 V_798 ;
T_2 V_730 ;
struct V_668 * V_669 ;
struct V_267 V_268 ;
struct V_673 V_625 = { 0 ,} ;
char * V_654 ;
T_13 V_746 ;
T_13 V_747 ;
if ( ! V_749 )
return F_362 ( V_617 , V_734 , V_188 ) ;
V_746 = F_4 () ;
V_747 = F_6 () ;
if ( ! V_746 && ! V_747 )
return V_787 ;
V_669 = V_617 -> V_669 ;
#ifdef F_366
if ( F_367 ( V_617 ) != NULL && F_367 ( V_617 ) -> V_799 != NULL &&
! ( V_669 != NULL && V_669 -> V_794 == V_795 ) )
return V_787 ;
#endif
if ( V_669 == NULL ) {
if ( V_617 -> V_742 ) {
V_798 = V_800 ;
if ( F_281 ( V_617 , V_188 , & V_730 ) )
return V_788 ;
} else {
V_798 = V_796 ;
V_730 = V_18 ;
}
} else if ( V_669 -> V_794 == V_795 ) {
T_2 V_663 ;
struct V_670 * V_671 = V_669 -> V_672 ;
if ( F_281 ( V_617 , V_188 , & V_663 ) )
return V_788 ;
if ( V_663 == V_665 ) {
switch ( V_188 ) {
case V_195 :
if ( F_368 ( V_617 ) -> V_80 & V_801 )
return V_787 ;
break;
case V_196 :
if ( F_369 ( V_617 ) -> V_80 & V_802 )
return V_787 ;
default:
return F_363 ( - V_797 ) ;
}
}
if ( F_285 ( V_671 -> V_17 , V_663 , & V_730 ) )
return V_788 ;
V_798 = V_796 ;
} else {
struct V_670 * V_671 = V_669 -> V_672 ;
V_730 = V_671 -> V_17 ;
V_798 = V_796 ;
}
V_268 . type = V_674 ;
V_268 . V_273 . V_625 = & V_625 ;
V_268 . V_273 . V_625 -> V_741 = V_734 ;
V_268 . V_273 . V_625 -> V_188 = V_188 ;
if ( F_279 ( V_617 , & V_268 , & V_654 , 0 , NULL ) )
return V_788 ;
if ( V_746 )
if ( F_46 ( V_730 , V_617 -> V_743 ,
V_744 , V_798 , & V_268 ) )
return F_363 ( - V_797 ) ;
if ( V_747 ) {
T_2 V_735 ;
T_2 V_736 ;
if ( F_314 ( V_734 , & V_735 ) )
return V_788 ;
if ( F_46 ( V_730 , V_735 ,
V_737 , V_803 , & V_268 ) )
return F_363 ( - V_797 ) ;
if ( F_298 ( V_654 , V_188 , & V_736 ) )
return V_788 ;
if ( F_46 ( V_730 , V_736 ,
V_739 , V_804 , & V_268 ) )
return F_363 ( - V_797 ) ;
}
return V_787 ;
}
static unsigned int F_370 ( const struct V_790 * V_791 ,
struct V_616 * V_617 ,
const struct V_792 * V_793 ,
const struct V_792 * V_74 ,
int (* F_358)( struct V_616 * ) )
{
return F_365 ( V_617 , V_74 -> V_734 , V_195 ) ;
}
static unsigned int F_371 ( const struct V_790 * V_791 ,
struct V_616 * V_617 ,
const struct V_792 * V_793 ,
const struct V_792 * V_74 ,
int (* F_358)( struct V_616 * ) )
{
return F_365 ( V_617 , V_74 -> V_734 , V_196 ) ;
}
static int F_372 ( struct V_668 * V_669 , struct V_616 * V_617 )
{
int V_568 ;
V_568 = F_373 ( V_669 , V_617 ) ;
if ( V_568 )
return V_568 ;
return F_350 ( V_669 , V_617 ) ;
}
static int F_374 ( struct V_20 * V_21 ,
struct V_805 * V_244 ,
T_4 V_31 )
{
struct V_806 * V_24 ;
T_2 V_17 ;
V_24 = F_15 ( sizeof( struct V_806 ) , V_15 ) ;
if ( ! V_24 )
return - V_27 ;
V_17 = F_18 ( V_21 ) ;
V_24 -> V_31 = V_31 ;
V_24 -> V_17 = V_17 ;
V_244 -> V_19 = V_24 ;
return 0 ;
}
static void F_375 ( struct V_805 * V_244 )
{
struct V_806 * V_24 = V_244 -> V_19 ;
V_244 -> V_19 = NULL ;
F_39 ( V_24 ) ;
}
static int F_376 ( struct V_807 * V_714 )
{
struct V_808 * V_809 ;
V_809 = F_15 ( sizeof( struct V_808 ) , V_15 ) ;
if ( ! V_809 )
return - V_27 ;
V_809 -> V_17 = V_30 ;
V_714 -> V_19 = V_809 ;
return 0 ;
}
static void F_377 ( struct V_807 * V_714 )
{
struct V_808 * V_809 = V_714 -> V_19 ;
V_714 -> V_19 = NULL ;
F_39 ( V_809 ) ;
}
static int F_378 ( struct V_805 * V_810 ,
T_2 V_254 )
{
struct V_806 * V_24 ;
struct V_267 V_268 ;
T_2 V_17 = F_22 () ;
V_24 = V_810 -> V_19 ;
V_268 . type = V_811 ;
V_268 . V_273 . V_812 = V_810 -> V_813 ;
return F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_254 , & V_268 ) ;
}
static int F_379 ( struct V_807 * V_714 )
{
return F_376 ( V_714 ) ;
}
static void F_380 ( struct V_807 * V_714 )
{
F_377 ( V_714 ) ;
}
static int F_381 ( struct V_814 * V_815 )
{
struct V_806 * V_24 ;
struct V_267 V_268 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_53 = F_374 ( V_11 , & V_815 -> V_816 , V_817 ) ;
if ( V_53 )
return V_53 ;
V_24 = V_815 -> V_816 . V_19 ;
V_268 . type = V_811 ;
V_268 . V_273 . V_812 = V_815 -> V_816 . V_813 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_817 ,
V_818 , & V_268 ) ;
if ( V_53 ) {
F_375 ( & V_815 -> V_816 ) ;
return V_53 ;
}
return 0 ;
}
static void F_382 ( struct V_814 * V_815 )
{
F_375 ( & V_815 -> V_816 ) ;
}
static int F_383 ( struct V_814 * V_815 , int V_819 )
{
struct V_806 * V_24 ;
struct V_267 V_268 ;
T_2 V_17 = F_22 () ;
V_24 = V_815 -> V_816 . V_19 ;
V_268 . type = V_811 ;
V_268 . V_273 . V_812 = V_815 -> V_816 . V_813 ;
return F_46 ( V_17 , V_24 -> V_17 , V_817 ,
V_820 , & V_268 ) ;
}
static int F_384 ( struct V_814 * V_815 , int V_523 )
{
int V_568 ;
int V_254 ;
switch ( V_523 ) {
case V_821 :
case V_822 :
return F_112 ( V_11 , V_823 ) ;
case V_824 :
case V_825 :
V_254 = V_826 | V_820 ;
break;
case V_827 :
V_254 = V_828 ;
break;
case V_829 :
V_254 = V_830 ;
break;
default:
return 0 ;
}
V_568 = F_378 ( & V_815 -> V_816 , V_254 ) ;
return V_568 ;
}
static int F_385 ( struct V_814 * V_815 , struct V_807 * V_714 , int V_819 )
{
struct V_806 * V_24 ;
struct V_808 * V_809 ;
struct V_267 V_268 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_24 = V_815 -> V_816 . V_19 ;
V_809 = V_714 -> V_19 ;
if ( V_809 -> V_17 == V_30 ) {
V_53 = F_101 ( V_17 , V_24 -> V_17 , V_831 ,
NULL , & V_809 -> V_17 ) ;
if ( V_53 )
return V_53 ;
}
V_268 . type = V_811 ;
V_268 . V_273 . V_812 = V_815 -> V_816 . V_813 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_817 ,
V_832 , & V_268 ) ;
if ( ! V_53 )
V_53 = F_46 ( V_17 , V_809 -> V_17 , V_831 ,
V_833 , & V_268 ) ;
if ( ! V_53 )
V_53 = F_46 ( V_809 -> V_17 , V_24 -> V_17 , V_817 ,
V_834 , & V_268 ) ;
return V_53 ;
}
static int F_386 ( struct V_814 * V_815 , struct V_807 * V_714 ,
struct V_20 * V_253 ,
long type , int V_169 )
{
struct V_806 * V_24 ;
struct V_808 * V_809 ;
struct V_267 V_268 ;
T_2 V_17 = F_18 ( V_253 ) ;
int V_53 ;
V_24 = V_815 -> V_816 . V_19 ;
V_809 = V_714 -> V_19 ;
V_268 . type = V_811 ;
V_268 . V_273 . V_812 = V_815 -> V_816 . V_813 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 ,
V_817 , V_835 , & V_268 ) ;
if ( ! V_53 )
V_53 = F_46 ( V_17 , V_809 -> V_17 ,
V_831 , V_836 , & V_268 ) ;
return V_53 ;
}
static int F_387 ( struct V_837 * V_838 )
{
struct V_806 * V_24 ;
struct V_267 V_268 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_53 = F_374 ( V_11 , & V_838 -> V_839 , V_840 ) ;
if ( V_53 )
return V_53 ;
V_24 = V_838 -> V_839 . V_19 ;
V_268 . type = V_811 ;
V_268 . V_273 . V_812 = V_838 -> V_839 . V_813 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_840 ,
V_841 , & V_268 ) ;
if ( V_53 ) {
F_375 ( & V_838 -> V_839 ) ;
return V_53 ;
}
return 0 ;
}
static void F_388 ( struct V_837 * V_838 )
{
F_375 ( & V_838 -> V_839 ) ;
}
static int F_389 ( struct V_837 * V_838 , int V_842 )
{
struct V_806 * V_24 ;
struct V_267 V_268 ;
T_2 V_17 = F_22 () ;
V_24 = V_838 -> V_839 . V_19 ;
V_268 . type = V_811 ;
V_268 . V_273 . V_812 = V_838 -> V_839 . V_813 ;
return F_46 ( V_17 , V_24 -> V_17 , V_840 ,
V_843 , & V_268 ) ;
}
static int F_390 ( struct V_837 * V_838 , int V_523 )
{
int V_254 ;
int V_568 ;
switch ( V_523 ) {
case V_821 :
case V_844 :
return F_112 ( V_11 , V_823 ) ;
case V_824 :
case V_845 :
V_254 = V_846 | V_843 ;
break;
case V_827 :
V_254 = V_847 ;
break;
case V_848 :
case V_849 :
V_254 = V_850 ;
break;
case V_829 :
V_254 = V_851 ;
break;
default:
return 0 ;
}
V_568 = F_378 ( & V_838 -> V_839 , V_254 ) ;
return V_568 ;
}
static int F_391 ( struct V_837 * V_838 ,
char T_15 * V_852 , int V_842 )
{
T_2 V_254 ;
if ( V_842 & V_853 )
V_254 = V_854 ;
else
V_254 = V_854 | V_855 ;
return F_378 ( & V_838 -> V_839 , V_254 ) ;
}
static int F_392 ( struct V_856 * V_857 )
{
struct V_806 * V_24 ;
struct V_267 V_268 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_53 = F_374 ( V_11 , & V_857 -> V_858 , V_859 ) ;
if ( V_53 )
return V_53 ;
V_24 = V_857 -> V_858 . V_19 ;
V_268 . type = V_811 ;
V_268 . V_273 . V_812 = V_857 -> V_858 . V_813 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_859 ,
V_860 , & V_268 ) ;
if ( V_53 ) {
F_375 ( & V_857 -> V_858 ) ;
return V_53 ;
}
return 0 ;
}
static void F_393 ( struct V_856 * V_857 )
{
F_375 ( & V_857 -> V_858 ) ;
}
static int F_394 ( struct V_856 * V_857 , int V_861 )
{
struct V_806 * V_24 ;
struct V_267 V_268 ;
T_2 V_17 = F_22 () ;
V_24 = V_857 -> V_858 . V_19 ;
V_268 . type = V_811 ;
V_268 . V_273 . V_812 = V_857 -> V_858 . V_813 ;
return F_46 ( V_17 , V_24 -> V_17 , V_859 ,
V_862 , & V_268 ) ;
}
static int F_395 ( struct V_856 * V_857 , int V_523 )
{
int V_568 ;
T_2 V_254 ;
switch ( V_523 ) {
case V_821 :
case V_863 :
return F_112 ( V_11 , V_823 ) ;
case V_864 :
case V_865 :
case V_866 :
V_254 = V_867 ;
break;
case V_868 :
case V_869 :
V_254 = V_870 ;
break;
case V_871 :
case V_872 :
V_254 = V_873 ;
break;
case V_829 :
V_254 = V_874 ;
break;
case V_827 :
V_254 = V_875 ;
break;
case V_824 :
case V_876 :
V_254 = V_867 | V_862 ;
break;
default:
return 0 ;
}
V_568 = F_378 ( & V_857 -> V_858 , V_254 ) ;
return V_568 ;
}
static int F_396 ( struct V_856 * V_857 ,
struct V_877 * V_878 , unsigned V_879 , int V_880 )
{
T_2 V_254 ;
if ( V_880 )
V_254 = V_870 | V_873 ;
else
V_254 = V_870 ;
return F_378 ( & V_857 -> V_858 , V_254 ) ;
}
static int F_397 ( struct V_805 * V_881 , short V_104 )
{
T_2 V_271 = 0 ;
V_271 = 0 ;
if ( V_104 & V_882 )
V_271 |= V_883 ;
if ( V_104 & V_884 )
V_271 |= V_885 ;
if ( V_271 == 0 )
return 0 ;
return F_378 ( V_881 , V_271 ) ;
}
static void F_398 ( struct V_805 * V_881 , T_2 * V_520 )
{
struct V_806 * V_24 = V_881 -> V_19 ;
* V_520 = V_24 -> V_17 ;
}
static void F_399 ( struct V_64 * V_64 , struct V_22 * V_22 )
{
if ( V_22 )
F_44 ( V_22 , V_64 ) ;
}
static int F_400 ( struct V_20 * V_146 ,
char * V_63 , char * * V_477 )
{
const struct V_13 * V_769 ;
T_2 V_17 ;
int error ;
unsigned V_89 ;
if ( V_11 != V_146 ) {
error = F_106 ( V_146 , V_886 ) ;
if ( error )
return error ;
}
F_19 () ;
V_769 = F_20 ( V_146 ) -> V_19 ;
if ( ! strcmp ( V_63 , L_51 ) )
V_17 = V_769 -> V_17 ;
else if ( ! strcmp ( V_63 , L_52 ) )
V_17 = V_769 -> V_16 ;
else if ( ! strcmp ( V_63 , L_53 ) )
V_17 = V_769 -> V_388 ;
else if ( ! strcmp ( V_63 , L_54 ) )
V_17 = V_769 -> V_288 ;
else if ( ! strcmp ( V_63 , L_55 ) )
V_17 = V_769 -> V_386 ;
else if ( ! strcmp ( V_63 , L_56 ) )
V_17 = V_769 -> V_387 ;
else
goto V_887;
F_21 () ;
if ( ! V_17 )
return 0 ;
error = F_60 ( V_17 , V_477 , & V_89 ) ;
if ( error )
return error ;
return V_89 ;
V_887:
F_21 () ;
return - V_91 ;
}
static int F_401 ( struct V_20 * V_146 ,
char * V_63 , void * V_477 , T_7 V_508 )
{
struct V_13 * V_14 ;
struct V_20 * V_402 ;
struct V_10 * V_129 ;
T_2 V_17 = 0 , V_404 ;
int error ;
char * V_1 = V_477 ;
if ( V_11 != V_146 ) {
return - V_394 ;
}
if ( ! strcmp ( V_63 , L_53 ) )
error = F_106 ( V_146 , V_888 ) ;
else if ( ! strcmp ( V_63 , L_54 ) )
error = F_106 ( V_146 , V_889 ) ;
else if ( ! strcmp ( V_63 , L_55 ) )
error = F_106 ( V_146 , V_890 ) ;
else if ( ! strcmp ( V_63 , L_56 ) )
error = F_106 ( V_146 , V_891 ) ;
else if ( ! strcmp ( V_63 , L_51 ) )
error = F_106 ( V_146 , V_892 ) ;
else
error = - V_91 ;
if ( error )
return error ;
if ( V_508 && V_1 [ 1 ] && V_1 [ 1 ] != '\n' ) {
if ( V_1 [ V_508 - 1 ] == '\n' ) {
V_1 [ V_508 - 1 ] = 0 ;
V_508 -- ;
}
error = F_67 ( V_477 , V_508 , & V_17 , V_15 ) ;
if ( error == - V_91 && ! strcmp ( V_63 , L_54 ) ) {
if ( ! F_213 ( V_510 ) ) {
struct V_511 * V_512 ;
T_7 V_513 ;
if ( V_1 [ V_508 - 1 ] == '\0' )
V_513 = V_508 - 1 ;
else
V_513 = V_508 ;
V_512 = F_216 ( V_11 -> V_514 , V_97 , V_515 ) ;
F_217 ( V_512 , L_57 ) ;
F_218 ( V_512 , V_477 , V_513 ) ;
F_219 ( V_512 ) ;
return error ;
}
error = F_220 ( V_477 , V_508 ,
& V_17 ) ;
}
if ( error )
return error ;
}
V_129 = F_402 () ;
if ( ! V_129 )
return - V_27 ;
V_14 = V_129 -> V_19 ;
if ( ! strcmp ( V_63 , L_53 ) ) {
V_14 -> V_388 = V_17 ;
} else if ( ! strcmp ( V_63 , L_54 ) ) {
V_14 -> V_288 = V_17 ;
} else if ( ! strcmp ( V_63 , L_55 ) ) {
error = F_122 ( V_17 , V_146 ) ;
if ( error )
goto V_893;
V_14 -> V_386 = V_17 ;
} else if ( ! strcmp ( V_63 , L_56 ) ) {
V_14 -> V_387 = V_17 ;
} else if ( ! strcmp ( V_63 , L_51 ) ) {
error = - V_91 ;
if ( V_17 == 0 )
goto V_893;
error = - V_391 ;
if ( ! F_403 () ) {
error = F_404 ( V_14 -> V_17 , V_17 ) ;
if ( error )
goto V_893;
}
error = F_46 ( V_14 -> V_17 , V_17 , V_257 ,
V_894 , NULL ) ;
if ( error )
goto V_893;
V_404 = 0 ;
F_19 () ;
V_402 = F_147 ( V_146 ) ;
if ( V_402 )
V_404 = F_18 ( V_402 ) ;
F_21 () ;
if ( V_402 ) {
error = F_46 ( V_404 , V_17 , V_257 ,
V_339 , NULL ) ;
if ( error )
goto V_893;
}
V_14 -> V_17 = V_17 ;
} else {
error = - V_91 ;
goto V_893;
}
F_405 ( V_129 ) ;
return V_508 ;
V_893:
F_406 ( V_129 ) ;
return error ;
}
static int F_407 ( const char * V_63 )
{
return ( strcmp ( V_63 , V_479 ) == 0 ) ;
}
static int F_408 ( T_2 V_520 , char * * V_459 , T_2 * V_895 )
{
return F_60 ( V_520 , V_459 , V_895 ) ;
}
static int F_409 ( const char * V_459 , T_2 V_895 , T_2 * V_520 )
{
return F_67 ( V_459 , V_895 , V_520 , V_15 ) ;
}
static void F_410 ( char * V_459 , T_2 V_895 )
{
F_39 ( V_459 ) ;
}
static int F_411 ( struct V_22 * V_22 , void * V_294 , T_2 V_475 )
{
return F_227 ( V_22 , V_479 , V_294 , V_475 , 0 ) ;
}
static int F_412 ( struct V_64 * V_64 , void * V_294 , T_2 V_475 )
{
return F_413 ( V_64 , V_75 , V_294 , V_475 , 0 ) ;
}
static int F_414 ( struct V_22 * V_22 , void * * V_294 , T_2 * V_475 )
{
int V_89 = 0 ;
V_89 = F_226 ( V_22 , V_479 ,
V_294 , true ) ;
if ( V_89 < 0 )
return V_89 ;
* V_475 = V_89 ;
return 0 ;
}
static int F_415 ( struct V_813 * V_896 , const struct V_10 * V_10 ,
unsigned long V_80 )
{
const struct V_13 * V_14 ;
struct V_897 * V_898 ;
V_898 = F_15 ( sizeof( struct V_897 ) , V_15 ) ;
if ( ! V_898 )
return - V_27 ;
V_14 = V_10 -> V_19 ;
if ( V_14 -> V_386 )
V_898 -> V_17 = V_14 -> V_386 ;
else
V_898 -> V_17 = V_14 -> V_17 ;
V_896 -> V_19 = V_898 ;
return 0 ;
}
static void F_416 ( struct V_813 * V_896 )
{
struct V_897 * V_898 = V_896 -> V_19 ;
V_896 -> V_19 = NULL ;
F_39 ( V_898 ) ;
}
static int F_417 ( T_16 V_899 ,
const struct V_10 * V_10 ,
unsigned V_244 )
{
struct V_813 * V_813 ;
struct V_897 * V_898 ;
T_2 V_17 ;
if ( V_244 == 0 )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_813 = F_418 ( V_899 ) ;
V_898 = V_813 -> V_19 ;
return F_46 ( V_17 , V_898 -> V_17 , V_295 , V_244 , NULL ) ;
}
static int F_419 ( struct V_813 * V_813 , char * * V_900 )
{
struct V_897 * V_898 = V_813 -> V_19 ;
char * V_88 = NULL ;
unsigned V_89 ;
int V_53 ;
V_53 = F_60 ( V_898 -> V_17 , & V_88 , & V_89 ) ;
if ( ! V_53 )
V_53 = V_89 ;
* V_900 = V_88 ;
return V_53 ;
}
static T_1 int F_420 ( void )
{
if ( ! F_421 ( & V_901 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_50 ( V_902 L_58 ) ;
return 0 ;
}
F_50 ( V_902 L_59 ) ;
F_14 () ;
V_539 = ! ( V_903 & V_554 ) ;
V_25 = F_422 ( L_60 ,
sizeof( struct V_23 ) ,
0 , V_904 , NULL ) ;
F_423 () ;
if ( F_424 ( & V_901 ) )
F_16 ( L_61 ) ;
if ( F_425 ( F_9 , V_9 ) )
F_16 ( L_62 ) ;
if ( V_3 )
F_50 ( V_79 L_63 ) ;
else
F_50 ( V_79 L_64 ) ;
return 0 ;
}
static void F_426 ( struct V_47 * V_48 , void * V_905 )
{
F_76 ( V_48 , NULL ) ;
}
void F_427 ( void )
{
F_50 ( V_79 L_65 ) ;
F_50 ( V_79 L_66 ) ;
F_428 ( F_426 , NULL ) ;
}
static int T_1 F_429 ( void )
{
int V_568 = 0 ;
if ( ! V_5 )
goto V_74;
F_50 ( V_79 L_67 ) ;
V_568 = F_430 ( V_906 , F_51 ( V_906 ) ) ;
if ( V_568 )
F_16 ( L_68 , V_568 ) ;
#if F_280 ( V_657 ) || F_280 ( V_658 )
V_568 = F_430 ( V_907 , F_51 ( V_907 ) ) ;
if ( V_568 )
F_16 ( L_69 , V_568 ) ;
#endif
V_74:
return V_568 ;
}
static void F_431 ( void )
{
F_50 ( V_79 L_70 ) ;
F_432 ( V_906 , F_51 ( V_906 ) ) ;
#if F_280 ( V_657 ) || F_280 ( V_658 )
F_432 ( V_907 , F_51 ( V_907 ) ) ;
#endif
}
int F_433 ( void )
{
if ( V_92 ) {
return - V_91 ;
}
if ( V_908 ) {
return - V_91 ;
}
F_50 ( V_902 L_71 ) ;
V_908 = 1 ;
V_5 = 0 ;
F_434 () ;
F_435 () ;
F_431 () ;
F_436 () ;
return 0 ;
}
