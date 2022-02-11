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
F_34 ( & V_24 -> V_29 ) ;
F_35 ( & V_38 -> V_41 ) ;
V_22 = F_53 ( V_22 ) ;
if ( V_22 ) {
if ( ! F_54 ( V_22 ) )
F_43 ( V_22 ) ;
F_55 ( V_22 ) ;
}
F_32 ( & V_38 -> V_41 ) ;
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
static int F_145 ( const struct V_381 * V_382 ,
const struct V_13 * V_383 ,
const struct V_13 * V_384 )
{
int V_385 = ( V_382 -> V_386 & V_387 ) ;
int V_388 = ( V_382 -> V_42 -> V_282 . V_389 -> V_107 & V_390 ) ;
int V_53 ;
if ( ! V_385 && ! V_388 )
return 0 ;
if ( V_384 -> V_17 == V_383 -> V_17 )
return 0 ;
V_53 = F_146 ( V_383 -> V_17 , V_384 -> V_17 ) ;
if ( V_53 ) {
if ( V_385 )
return - V_391 ;
else
return - V_392 ;
}
return 0 ;
}
static int F_147 ( struct V_381 * V_382 )
{
const struct V_13 * V_383 ;
struct V_13 * V_384 ;
struct V_23 * V_24 ;
struct V_267 V_268 ;
struct V_22 * V_22 = F_119 ( V_382 -> V_42 ) ;
int V_53 ;
V_53 = F_148 ( V_382 ) ;
if ( V_53 )
return V_53 ;
if ( V_382 -> V_393 )
return 0 ;
V_383 = F_23 () ;
V_384 = V_382 -> V_10 -> V_19 ;
V_24 = V_22 -> V_33 ;
V_384 -> V_17 = V_383 -> V_17 ;
V_384 -> V_16 = V_383 -> V_17 ;
V_384 -> V_288 = 0 ;
V_384 -> V_394 = 0 ;
V_384 -> V_395 = 0 ;
if ( V_383 -> V_396 ) {
V_384 -> V_17 = V_383 -> V_396 ;
V_384 -> V_396 = 0 ;
V_53 = F_145 ( V_382 , V_383 , V_384 ) ;
if ( V_53 )
return V_53 ;
} else {
V_53 = F_101 ( V_383 -> V_17 , V_24 -> V_17 ,
V_257 , NULL ,
& V_384 -> V_17 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_145 ( V_382 , V_383 , V_384 ) ;
if ( V_53 )
V_384 -> V_17 = V_383 -> V_17 ;
}
V_268 . type = V_281 ;
V_268 . V_273 . V_233 = V_382 -> V_42 -> V_282 ;
if ( V_384 -> V_17 == V_383 -> V_17 ) {
V_53 = F_46 ( V_383 -> V_17 , V_24 -> V_17 ,
V_32 , V_397 , & V_268 ) ;
if ( V_53 )
return V_53 ;
} else {
V_53 = F_46 ( V_383 -> V_17 , V_384 -> V_17 ,
V_257 , V_398 , & V_268 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_384 -> V_17 , V_24 -> V_17 ,
V_32 , V_399 , & V_268 ) ;
if ( V_53 )
return V_53 ;
if ( V_382 -> V_386 & V_400 ) {
V_53 = F_46 ( V_383 -> V_17 , V_384 -> V_17 ,
V_257 , V_401 ,
NULL ) ;
if ( V_53 )
return - V_391 ;
}
if ( V_382 -> V_386 &
( V_402 | V_403 ) ) {
struct V_20 * V_404 ;
struct V_13 * V_405 ;
T_2 V_406 = 0 ;
F_19 () ;
V_404 = F_149 ( V_11 ) ;
if ( F_150 ( V_404 != NULL ) ) {
V_405 = F_20 ( V_404 ) -> V_19 ;
V_406 = V_405 -> V_17 ;
}
F_21 () ;
if ( V_406 != 0 ) {
V_53 = F_46 ( V_406 , V_384 -> V_17 ,
V_257 ,
V_339 , NULL ) ;
if ( V_53 )
return - V_391 ;
}
}
V_382 -> V_407 |= V_408 ;
}
return 0 ;
}
static int F_151 ( struct V_381 * V_382 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_17 , V_16 ;
int V_409 = 0 ;
V_17 = V_14 -> V_17 ;
V_16 = V_14 -> V_16 ;
if ( V_16 != V_17 ) {
V_409 = F_46 ( V_16 , V_17 ,
V_257 ,
V_410 , NULL ) ;
}
return ( V_409 || F_152 ( V_382 ) ) ;
}
static int F_153 ( const void * V_146 , struct V_42 * V_42 , unsigned V_411 )
{
return F_120 ( V_146 , V_42 , F_128 ( V_42 ) ) ? V_411 + 1 : 0 ;
}
static inline void F_154 ( const struct V_10 * V_10 ,
struct V_412 * V_413 )
{
struct V_42 * V_42 , * V_414 = NULL ;
struct V_415 * V_416 ;
int V_417 = 0 ;
unsigned V_418 ;
V_416 = F_155 () ;
if ( V_416 ) {
F_32 ( & V_419 ) ;
if ( ! F_33 ( & V_416 -> V_420 ) ) {
struct V_421 * V_422 ;
V_422 = F_156 ( & V_416 -> V_420 ,
struct V_421 , V_29 ) ;
V_42 = V_422 -> V_42 ;
if ( F_118 ( V_10 , V_42 , V_321 | V_325 ) )
V_417 = 1 ;
}
F_35 ( & V_419 ) ;
F_157 ( V_416 ) ;
}
if ( V_417 )
F_158 () ;
V_418 = F_159 ( V_413 , 0 , F_153 , V_10 ) ;
if ( ! V_418 )
return;
V_414 = F_160 ( & V_423 , V_424 , V_10 ) ;
if ( F_89 ( V_414 ) )
V_414 = NULL ;
do {
F_161 ( V_418 - 1 , V_414 , 0 ) ;
} while ( ( V_418 = F_159 ( V_413 , V_418 , F_153 , V_10 ) ) != 0 );
if ( V_414 )
F_162 ( V_414 ) ;
}
static void F_163 ( struct V_381 * V_382 )
{
struct V_13 * V_384 ;
struct V_425 * V_426 , * V_427 ;
int V_53 , V_87 ;
V_384 = V_382 -> V_10 -> V_19 ;
if ( V_384 -> V_17 == V_384 -> V_16 )
return;
F_154 ( V_382 -> V_10 , V_11 -> V_413 ) ;
V_11 -> V_428 = 0 ;
V_53 = F_46 ( V_384 -> V_16 , V_384 -> V_17 , V_257 ,
V_429 , NULL ) ;
if ( V_53 ) {
F_164 ( V_11 ) ;
for ( V_87 = 0 ; V_87 < V_430 ; V_87 ++ ) {
V_426 = V_11 -> signal -> V_426 + V_87 ;
V_427 = V_431 . signal -> V_426 + V_87 ;
V_426 -> V_432 = F_165 ( V_426 -> V_433 , V_427 -> V_432 ) ;
}
F_166 ( V_11 ) ;
F_167 ( V_11 , V_425 ( V_434 ) ) ;
}
}
static void F_168 ( struct V_381 * V_382 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_435 V_436 ;
T_2 V_16 , V_17 ;
int V_53 , V_87 ;
V_16 = V_14 -> V_16 ;
V_17 = V_14 -> V_17 ;
if ( V_17 == V_16 )
return;
V_53 = F_46 ( V_16 , V_17 , V_257 , V_437 , NULL ) ;
if ( V_53 ) {
memset ( & V_436 , 0 , sizeof V_436 ) ;
for ( V_87 = 0 ; V_87 < 3 ; V_87 ++ )
F_169 ( V_87 , & V_436 , NULL ) ;
F_170 ( & V_11 -> V_438 -> V_439 ) ;
if ( ! ( V_11 -> signal -> V_80 & V_440 ) ) {
F_171 ( V_11 ) ;
F_172 ( V_11 , 1 ) ;
F_173 ( & V_11 -> V_441 ) ;
}
F_174 ( & V_11 -> V_438 -> V_439 ) ;
}
F_175 ( & V_442 ) ;
F_176 ( V_11 , V_11 -> V_443 ) ;
F_177 ( & V_442 ) ;
}
static int F_178 ( struct V_47 * V_48 )
{
return F_40 ( V_48 ) ;
}
static void F_179 ( struct V_47 * V_48 )
{
F_42 ( V_48 ) ;
}
static inline int F_180 ( char * V_162 , int V_444 , char * V_445 , int V_446 )
{
if ( V_444 > V_446 )
return 0 ;
return ! memcmp ( V_162 , V_445 , V_444 ) ;
}
static inline int F_181 ( char * V_445 , int V_89 )
{
return ( F_180 ( V_164 , sizeof( V_164 ) - 1 , V_445 , V_89 ) ||
F_180 ( V_165 , sizeof( V_165 ) - 1 , V_445 , V_89 ) ||
F_180 ( V_167 , sizeof( V_167 ) - 1 , V_445 , V_89 ) ||
F_180 ( V_166 , sizeof( V_166 ) - 1 , V_445 , V_89 ) ||
F_180 ( V_168 , sizeof( V_168 ) - 1 , V_445 , V_89 ) ) ;
}
static inline void F_182 ( char * * V_447 , char * V_448 , int * V_449 , int V_89 )
{
if ( ! * V_449 ) {
* * V_447 = ',' ;
* V_447 += 1 ;
} else
* V_449 = 0 ;
memcpy ( * V_447 , V_448 , V_89 ) ;
* V_447 += V_89 ;
}
static inline void F_183 ( char * * V_447 , char * V_448 , int * V_449 ,
int V_89 )
{
int V_450 = 0 ;
if ( ! * V_449 ) {
* * V_447 = '|' ;
* V_447 += 1 ;
} else
* V_449 = 0 ;
while ( V_450 < V_89 ) {
if ( * V_448 != '"' ) {
* * V_447 = * V_448 ;
* V_447 += 1 ;
}
V_448 += 1 ;
V_450 += 1 ;
}
}
static int F_184 ( char * V_451 , char * V_452 )
{
int V_453 , V_44 , V_53 = 0 ;
char * V_454 , * V_455 , * V_456 ;
char * V_457 , * V_458 , * V_459 ;
int V_460 = 0 ;
V_455 = V_451 ;
V_457 = V_452 ;
V_459 = ( char * ) F_185 ( V_15 ) ;
if ( ! V_459 ) {
V_53 = - V_27 ;
goto V_74;
}
V_458 = V_459 ;
V_453 = V_44 = 1 ;
V_454 = V_456 = V_451 ;
do {
if ( * V_456 == '"' )
V_460 = ! V_460 ;
if ( ( * V_456 == ',' && V_460 == 0 ) ||
* V_456 == '\0' ) {
int V_89 = V_456 - V_455 ;
if ( F_181 ( V_455 , V_89 ) )
F_183 ( & V_457 , V_455 , & V_44 , V_89 ) ;
else
F_182 ( & V_459 , V_455 , & V_453 , V_89 ) ;
V_455 = V_456 + 1 ;
}
} while ( * V_456 ++ );
strcpy ( V_454 , V_458 ) ;
F_92 ( ( unsigned long ) V_458 ) ;
V_74:
return V_53 ;
}
static int F_186 ( struct V_47 * V_48 , void * V_159 )
{
int V_53 , V_87 , * V_80 ;
struct V_85 V_86 ;
char * V_461 , * * V_115 ;
struct V_37 * V_38 = V_48 -> V_40 ;
if ( ! ( V_38 -> V_80 & V_81 ) )
return 0 ;
if ( ! V_159 )
return 0 ;
if ( V_48 -> V_62 -> V_117 & V_118 )
return 0 ;
F_57 ( & V_86 ) ;
V_461 = F_187 () ;
if ( ! V_461 )
return - V_27 ;
V_53 = F_184 ( V_159 , V_461 ) ;
if ( V_53 )
goto V_462;
V_53 = F_72 ( V_461 , & V_86 ) ;
if ( V_53 )
goto V_462;
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
goto V_463;
}
V_53 = - V_91 ;
switch ( V_80 [ V_87 ] ) {
case V_100 :
if ( F_63 ( V_38 , V_100 , V_38 -> V_17 , V_17 ) )
goto V_464;
break;
case V_101 :
if ( F_63 ( V_38 , V_101 , V_38 -> V_52 , V_17 ) )
goto V_464;
break;
case V_103 : {
struct V_23 * V_110 ;
V_110 = V_48 -> V_66 -> V_68 -> V_33 ;
if ( F_63 ( V_38 , V_103 , V_110 -> V_17 , V_17 ) )
goto V_464;
break;
}
case V_102 :
if ( F_63 ( V_38 , V_102 , V_38 -> V_50 , V_17 ) )
goto V_464;
break;
default:
goto V_463;
}
}
V_53 = 0 ;
V_463:
F_62 ( & V_86 ) ;
V_462:
F_188 ( V_461 ) ;
return V_53 ;
V_464:
F_50 ( V_71 L_35
L_36 , V_48 -> V_72 ,
V_48 -> V_62 -> V_63 ) ;
goto V_463;
}
static int F_189 ( struct V_47 * V_48 , int V_80 , void * V_159 )
{
const struct V_10 * V_10 = F_65 () ;
struct V_267 V_268 ;
int V_53 ;
V_53 = F_76 ( V_48 , V_159 ) ;
if ( V_53 )
return V_53 ;
if ( V_80 & V_465 )
return 0 ;
V_268 . type = V_280 ;
V_268 . V_273 . V_64 = V_48 -> V_66 ;
return F_126 ( V_10 , V_48 , V_466 , & V_268 ) ;
}
static int F_190 ( struct V_64 * V_64 )
{
const struct V_10 * V_10 = F_65 () ;
struct V_267 V_268 ;
V_268 . type = V_280 ;
V_268 . V_273 . V_64 = V_64 -> V_467 -> V_66 ;
return F_126 ( V_10 , V_64 -> V_467 , V_468 , & V_268 ) ;
}
static int F_191 ( const char * V_469 ,
struct V_233 * V_233 ,
const char * type ,
unsigned long V_80 ,
void * V_159 )
{
const struct V_10 * V_10 = F_65 () ;
if ( V_80 & V_470 )
return F_126 ( V_10 , V_233 -> V_64 -> V_467 ,
V_471 , NULL ) ;
else
return F_117 ( V_10 , V_233 , V_472 ) ;
}
static int F_192 ( struct V_473 * V_389 , int V_80 )
{
const struct V_10 * V_10 = F_65 () ;
return F_126 ( V_10 , V_389 -> V_474 ,
V_475 , NULL ) ;
}
static int F_193 ( struct V_22 * V_22 )
{
return F_24 ( V_22 ) ;
}
static void F_194 ( struct V_22 * V_22 )
{
F_31 ( V_22 ) ;
}
static int F_195 ( struct V_64 * V_64 , int V_169 ,
struct V_476 * V_63 , void * * V_294 ,
T_2 * V_477 )
{
const struct V_10 * V_10 = F_65 () ;
struct V_13 * V_14 ;
struct V_23 * V_286 ;
struct V_37 * V_38 ;
struct V_22 * V_285 = V_64 -> V_478 -> V_68 ;
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
return F_60 ( V_287 , ( char * * ) V_294 , V_477 ) ;
}
static int F_196 ( struct V_22 * V_22 , struct V_22 * V_285 ,
const struct V_476 * V_476 ,
const char * * V_63 ,
void * * V_479 , T_7 * V_89 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_286 ;
struct V_37 * V_38 ;
T_2 V_17 , V_287 , V_480 ;
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
V_476 , & V_287 ) ;
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
* V_63 = V_481 ;
if ( V_479 && V_89 ) {
V_53 = F_197 ( V_287 , & V_88 , & V_480 ) ;
if ( V_53 )
return V_53 ;
* V_479 = V_88 ;
* V_89 = V_480 ;
}
return 0 ;
}
static int F_198 ( struct V_22 * V_285 , struct V_64 * V_64 , T_5 V_169 )
{
return F_121 ( V_285 , V_64 , V_32 ) ;
}
static int F_199 ( struct V_64 * V_306 , struct V_22 * V_285 , struct V_64 * V_308 )
{
return F_123 ( V_285 , V_306 , V_299 ) ;
}
static int F_200 ( struct V_22 * V_285 , struct V_64 * V_64 )
{
return F_123 ( V_285 , V_64 , V_301 ) ;
}
static int F_201 ( struct V_22 * V_285 , struct V_64 * V_64 , const char * V_63 )
{
return F_121 ( V_285 , V_64 , V_174 ) ;
}
static int F_202 ( struct V_22 * V_285 , struct V_64 * V_64 , T_5 V_317 )
{
return F_121 ( V_285 , V_64 , V_179 ) ;
}
static int F_203 ( struct V_22 * V_285 , struct V_64 * V_64 )
{
return F_123 ( V_285 , V_64 , V_303 ) ;
}
static int F_204 ( struct V_22 * V_285 , struct V_64 * V_64 , T_5 V_169 , T_8 V_239 )
{
return F_121 ( V_285 , V_64 , F_82 ( V_169 ) ) ;
}
static int F_205 ( struct V_22 * V_482 , struct V_64 * V_306 ,
struct V_22 * V_483 , struct V_64 * V_308 )
{
return F_124 ( V_482 , V_306 , V_483 , V_308 ) ;
}
static int F_206 ( struct V_64 * V_64 )
{
const struct V_10 * V_10 = F_65 () ;
return F_116 ( V_10 , V_64 , V_321 ) ;
}
static int F_207 ( struct V_64 * V_64 , struct V_484 * V_484 )
{
const struct V_10 * V_10 = F_65 () ;
return F_116 ( V_10 , V_64 , V_321 ) ;
}
static T_9 int F_208 ( struct V_22 * V_22 ,
T_2 V_254 , T_2 V_485 , T_2 V_486 ,
int V_487 ,
unsigned V_80 )
{
struct V_267 V_268 ;
struct V_23 * V_24 = V_22 -> V_33 ;
int V_53 ;
V_268 . type = V_488 ;
V_268 . V_273 . V_22 = V_22 ;
V_53 = F_209 ( F_22 () , V_24 -> V_17 , V_24 -> V_31 , V_254 ,
V_485 , V_486 , V_487 , & V_268 , V_80 ) ;
if ( V_53 )
return V_53 ;
return 0 ;
}
static int F_210 ( struct V_22 * V_22 , int V_317 )
{
const struct V_10 * V_10 = F_65 () ;
T_2 V_254 ;
bool V_489 ;
unsigned V_80 = V_317 & V_490 ;
struct V_23 * V_24 ;
T_2 V_17 ;
struct V_269 V_270 ;
int V_53 , V_277 ;
T_2 V_485 , V_486 ;
V_489 = V_317 & V_491 ;
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
V_485 = F_211 ( V_254 , & V_270 , V_53 ,
V_489 ? V_492 : 0 ,
& V_486 ) ;
if ( F_150 ( ! V_485 ) )
return V_53 ;
V_277 = F_208 ( V_22 , V_254 , V_485 , V_486 , V_53 , V_80 ) ;
if ( V_277 )
return V_277 ;
return V_53 ;
}
static int F_212 ( struct V_64 * V_64 , struct V_493 * V_493 )
{
const struct V_10 * V_10 = F_65 () ;
unsigned int V_494 = V_493 -> V_494 ;
T_10 V_271 = V_325 ;
if ( V_494 & V_495 ) {
V_494 &= ~ ( V_496 | V_497 | V_498 |
V_495 ) ;
if ( ! V_494 )
return 0 ;
}
if ( V_494 & ( V_498 | V_499 | V_500 |
V_501 | V_502 | V_503 ) )
return F_116 ( V_10 , V_64 , V_504 ) ;
if ( V_334 && ( V_494 & V_505 ) )
V_271 |= V_335 ;
return F_116 ( V_10 , V_64 , V_271 ) ;
}
static int F_213 ( struct V_473 * V_389 , struct V_64 * V_64 )
{
const struct V_10 * V_10 = F_65 () ;
struct V_233 V_233 ;
V_233 . V_64 = V_64 ;
V_233 . V_389 = V_389 ;
return F_117 ( V_10 , & V_233 , V_506 ) ;
}
static int F_214 ( struct V_64 * V_64 , const char * V_63 )
{
const struct V_10 * V_10 = F_65 () ;
if ( ! strncmp ( V_63 , V_507 ,
sizeof V_507 - 1 ) ) {
if ( ! strcmp ( V_63 , V_508 ) ) {
if ( ! F_215 ( V_509 ) )
return - V_391 ;
} else if ( ! F_215 ( V_379 ) ) {
return - V_391 ;
}
}
return F_116 ( V_10 , V_64 , V_504 ) ;
}
static int F_216 ( struct V_64 * V_64 , const char * V_63 ,
const void * V_479 , T_7 V_510 , int V_80 )
{
struct V_22 * V_22 = V_64 -> V_68 ;
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_37 * V_38 ;
struct V_267 V_268 ;
T_2 V_287 , V_17 = F_22 () ;
int V_53 = 0 ;
if ( strcmp ( V_63 , V_75 ) )
return F_214 ( V_64 , V_63 ) ;
V_38 = V_22 -> V_39 -> V_40 ;
if ( ! ( V_38 -> V_80 & V_82 ) )
return - V_73 ;
if ( ! F_217 ( V_22 ) )
return - V_391 ;
V_268 . type = V_280 ;
V_268 . V_273 . V_64 = V_64 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 ,
V_511 , & V_268 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_67 ( V_479 , V_510 , & V_287 , V_15 ) ;
if ( V_53 == - V_91 ) {
if ( ! F_215 ( V_512 ) ) {
struct V_513 * V_514 ;
T_7 V_515 ;
const char * V_1 ;
if ( V_479 ) {
V_1 = V_479 ;
if ( V_1 [ V_510 - 1 ] == '\0' )
V_515 = V_510 - 1 ;
else
V_515 = V_510 ;
} else {
V_1 = L_41 ;
V_515 = 0 ;
}
V_514 = F_218 ( V_11 -> V_516 , V_97 , V_517 ) ;
F_219 ( V_514 , L_42 ) ;
F_220 ( V_514 , V_479 , V_515 ) ;
F_221 ( V_514 ) ;
return V_53 ;
}
V_53 = F_222 ( V_479 , V_510 , & V_287 ) ;
}
if ( V_53 )
return V_53 ;
V_53 = F_46 ( V_17 , V_287 , V_24 -> V_31 ,
V_518 , & V_268 ) ;
if ( V_53 )
return V_53 ;
V_53 = F_223 ( V_24 -> V_17 , V_287 , V_17 ,
V_24 -> V_31 ) ;
if ( V_53 )
return V_53 ;
return F_46 ( V_287 ,
V_38 -> V_17 ,
V_54 ,
V_57 ,
& V_268 ) ;
}
static void F_224 ( struct V_64 * V_64 , const char * V_63 ,
const void * V_479 , T_7 V_510 ,
int V_80 )
{
struct V_22 * V_22 = V_64 -> V_68 ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_287 ;
int V_53 ;
if ( strcmp ( V_63 , V_75 ) ) {
return;
}
V_53 = F_222 ( V_479 , V_510 , & V_287 ) ;
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
static int F_225 ( struct V_64 * V_64 , const char * V_63 )
{
const struct V_10 * V_10 = F_65 () ;
return F_116 ( V_10 , V_64 , V_506 ) ;
}
static int F_226 ( struct V_64 * V_64 )
{
const struct V_10 * V_10 = F_65 () ;
return F_116 ( V_10 , V_64 , V_506 ) ;
}
static int F_227 ( struct V_64 * V_64 , const char * V_63 )
{
if ( strcmp ( V_63 , V_75 ) )
return F_214 ( V_64 , V_63 ) ;
return - V_392 ;
}
static int F_228 ( const struct V_22 * V_22 , const char * V_63 , void * * V_232 , bool V_519 )
{
T_2 V_510 ;
int error ;
char * V_88 = NULL ;
struct V_23 * V_24 = V_22 -> V_33 ;
if ( strcmp ( V_63 , V_481 ) )
return - V_73 ;
error = F_138 ( F_65 () , & V_378 , V_512 ,
V_380 ) ;
if ( ! error )
error = F_197 ( V_24 -> V_17 , & V_88 ,
& V_510 ) ;
else
error = F_60 ( V_24 -> V_17 , & V_88 , & V_510 ) ;
if ( error )
return error ;
error = V_510 ;
if ( V_519 ) {
* V_232 = V_88 ;
goto V_520;
}
F_39 ( V_88 ) ;
V_520:
return error ;
}
static int F_229 ( struct V_22 * V_22 , const char * V_63 ,
const void * V_479 , T_7 V_510 , int V_80 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_287 ;
int V_53 ;
if ( strcmp ( V_63 , V_481 ) )
return - V_73 ;
if ( ! V_479 || ! V_510 )
return - V_392 ;
V_53 = F_67 ( ( void * ) V_479 , V_510 , & V_287 , V_15 ) ;
if ( V_53 )
return V_53 ;
V_24 -> V_31 = F_82 ( V_22 -> V_242 ) ;
V_24 -> V_17 = V_287 ;
V_24 -> V_125 = 1 ;
return 0 ;
}
static int F_230 ( struct V_22 * V_22 , char * V_232 , T_7 V_521 )
{
const int V_89 = sizeof( V_75 ) ;
if ( V_232 && V_89 <= V_521 )
memcpy ( V_232 , V_75 , V_89 ) ;
return V_89 ;
}
static void F_231 ( const struct V_22 * V_22 , T_2 * V_522 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
* V_522 = V_24 -> V_17 ;
}
static int F_232 ( struct V_42 * V_42 , int V_317 )
{
const struct V_10 * V_10 = F_65 () ;
struct V_22 * V_22 = F_119 ( V_42 ) ;
if ( ( V_42 -> V_331 & V_332 ) && ( V_317 & V_324 ) )
V_317 |= V_322 ;
return F_120 ( V_10 , V_42 ,
F_127 ( V_22 -> V_242 , V_317 ) ) ;
}
static int F_233 ( struct V_42 * V_42 , int V_317 )
{
struct V_22 * V_22 = F_119 ( V_42 ) ;
struct V_43 * V_44 = V_42 -> V_46 ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 = F_22 () ;
if ( ! V_317 )
return 0 ;
if ( V_17 == V_44 -> V_17 && V_44 -> V_523 == V_24 -> V_17 &&
V_44 -> V_524 == F_234 () )
return 0 ;
return F_232 ( V_42 , V_317 ) ;
}
static int F_235 ( struct V_42 * V_42 )
{
return F_37 ( V_42 ) ;
}
static void F_236 ( struct V_42 * V_42 )
{
F_38 ( V_42 ) ;
}
static int F_237 ( struct V_42 * V_42 , unsigned int V_525 ,
unsigned long V_526 )
{
const struct V_10 * V_10 = F_65 () ;
int error = 0 ;
switch ( V_525 ) {
case V_527 :
case V_528 :
case V_529 :
case V_530 :
case V_531 :
error = F_120 ( V_10 , V_42 , V_506 ) ;
break;
case V_532 :
case V_533 :
error = F_120 ( V_10 , V_42 , V_504 ) ;
break;
case V_534 :
case V_535 :
error = F_120 ( V_10 , V_42 , 0 ) ;
break;
case V_536 :
case V_537 :
error = F_107 ( V_10 , V_538 ,
V_276 ) ;
break;
default:
error = F_120 ( V_10 , V_42 , V_333 ) ;
}
return error ;
}
static int F_238 ( struct V_42 * V_42 , unsigned long V_539 , int V_540 )
{
const struct V_10 * V_10 = F_65 () ;
int V_53 = 0 ;
if ( V_541 &&
( V_539 & V_542 ) && ( ! V_42 || ( ! V_540 && ( V_539 & V_543 ) ) ) ) {
V_53 = F_104 ( V_10 , V_10 , V_544 ) ;
if ( V_53 )
goto error;
}
if ( V_42 ) {
T_2 V_271 = V_321 ;
if ( V_540 && ( V_539 & V_543 ) )
V_271 |= V_325 ;
if ( V_539 & V_542 )
V_271 |= V_319 ;
return F_120 ( V_10 , V_42 , V_271 ) ;
}
error:
return V_53 ;
}
static int F_239 ( unsigned long V_545 )
{
int V_53 ;
V_53 = F_240 ( V_545 ) ;
if ( V_53 )
return V_53 ;
if ( V_545 < V_546 ) {
T_2 V_17 = F_22 () ;
V_53 = F_46 ( V_17 , V_17 , V_547 ,
V_548 , NULL ) ;
}
return V_53 ;
}
static int F_241 ( struct V_42 * V_42 , unsigned long V_549 ,
unsigned long V_539 , unsigned long V_80 )
{
if ( V_550 )
V_539 = V_549 ;
return F_238 ( V_42 , V_539 ,
( V_80 & V_551 ) == V_552 ) ;
}
static int F_242 ( struct V_553 * V_554 ,
unsigned long V_549 ,
unsigned long V_539 )
{
const struct V_10 * V_10 = F_65 () ;
if ( V_550 )
V_539 = V_549 ;
if ( V_541 &&
( V_539 & V_542 ) && ! ( V_554 -> V_555 & V_556 ) ) {
int V_53 = 0 ;
if ( V_554 -> V_557 >= V_554 -> V_558 -> V_559 &&
V_554 -> V_560 <= V_554 -> V_558 -> V_561 ) {
V_53 = F_104 ( V_10 , V_10 , V_562 ) ;
} else if ( ! V_554 -> V_563 &&
V_554 -> V_557 <= V_554 -> V_558 -> V_564 &&
V_554 -> V_560 >= V_554 -> V_558 -> V_564 ) {
V_53 = F_106 ( V_11 , V_565 ) ;
} else if ( V_554 -> V_563 && V_554 -> V_566 ) {
V_53 = F_120 ( V_10 , V_554 -> V_563 , V_567 ) ;
}
if ( V_53 )
return V_53 ;
}
return F_238 ( V_554 -> V_563 , V_539 , V_554 -> V_555 & V_568 ) ;
}
static int F_243 ( struct V_42 * V_42 , unsigned int V_525 )
{
const struct V_10 * V_10 = F_65 () ;
return F_120 ( V_10 , V_42 , V_569 ) ;
}
static int F_244 ( struct V_42 * V_42 , unsigned int V_525 ,
unsigned long V_526 )
{
const struct V_10 * V_10 = F_65 () ;
int V_570 = 0 ;
switch ( V_525 ) {
case V_571 :
if ( ( V_42 -> V_331 & V_332 ) && ! ( V_526 & V_332 ) ) {
V_570 = F_120 ( V_10 , V_42 , V_325 ) ;
break;
}
case V_572 :
case V_573 :
case V_574 :
case V_575 :
case V_576 :
case V_577 :
V_570 = F_120 ( V_10 , V_42 , 0 ) ;
break;
case V_578 :
case V_579 :
case V_580 :
case V_581 :
case V_582 :
case V_583 :
#if V_584 == 32
case V_585 :
case V_586 :
case V_587 :
#endif
V_570 = F_120 ( V_10 , V_42 , V_569 ) ;
break;
}
return V_570 ;
}
static void F_245 ( struct V_42 * V_42 )
{
struct V_43 * V_44 ;
V_44 = V_42 -> V_46 ;
V_44 -> V_45 = F_22 () ;
}
static int F_246 ( struct V_20 * V_264 ,
struct V_588 * V_589 , int V_590 )
{
struct V_42 * V_42 ;
T_2 V_17 = F_18 ( V_264 ) ;
T_2 V_244 ;
struct V_43 * V_44 ;
V_42 = F_29 ( V_589 , struct V_42 , V_591 ) ;
V_44 = V_42 -> V_46 ;
if ( ! V_590 )
V_244 = F_103 ( V_592 ) ;
else
V_244 = F_103 ( V_590 ) ;
return F_46 ( V_44 -> V_45 , V_17 ,
V_257 , V_244 , NULL ) ;
}
static int F_247 ( struct V_42 * V_42 )
{
const struct V_10 * V_10 = F_65 () ;
return F_120 ( V_10 , V_42 , F_128 ( V_42 ) ) ;
}
static int F_248 ( struct V_42 * V_42 , const struct V_10 * V_10 )
{
struct V_43 * V_44 ;
struct V_23 * V_24 ;
V_44 = V_42 -> V_46 ;
V_24 = F_119 ( V_42 ) -> V_33 ;
V_44 -> V_523 = V_24 -> V_17 ;
V_44 -> V_524 = F_234 () ;
return F_118 ( V_10 , V_42 , F_129 ( V_42 ) ) ;
}
static int F_249 ( unsigned long V_593 )
{
return F_106 ( V_11 , V_594 ) ;
}
static int F_250 ( struct V_10 * V_10 , T_11 V_595 )
{
struct V_13 * V_14 ;
V_14 = F_15 ( sizeof( struct V_13 ) , V_595 ) ;
if ( ! V_14 )
return - V_27 ;
V_10 -> V_19 = V_14 ;
return 0 ;
}
static void F_251 ( struct V_10 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_19 ;
F_61 ( V_10 -> V_19 && ( unsigned long ) V_10 -> V_19 < V_234 ) ;
V_10 -> V_19 = ( void * ) 0x7UL ;
F_39 ( V_14 ) ;
}
static int F_252 ( struct V_10 * V_129 , const struct V_10 * V_128 ,
T_11 V_595 )
{
const struct V_13 * V_383 ;
struct V_13 * V_14 ;
V_383 = V_128 -> V_19 ;
V_14 = F_253 ( V_383 , sizeof( struct V_13 ) , V_595 ) ;
if ( ! V_14 )
return - V_27 ;
V_129 -> V_19 = V_14 ;
return 0 ;
}
static void F_254 ( struct V_10 * V_129 , const struct V_10 * V_128 )
{
const struct V_13 * V_383 = V_128 -> V_19 ;
struct V_13 * V_14 = V_129 -> V_19 ;
* V_14 = * V_383 ;
}
static int F_255 ( struct V_10 * V_129 , T_2 V_522 )
{
struct V_13 * V_14 = V_129 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_596 ;
V_596 = F_46 ( V_17 , V_522 ,
V_597 ,
V_598 ,
NULL ) ;
if ( V_596 == 0 ) {
V_14 -> V_17 = V_522 ;
V_14 -> V_288 = 0 ;
V_14 -> V_394 = 0 ;
V_14 -> V_395 = 0 ;
}
return V_596 ;
}
static int F_256 ( struct V_10 * V_129 , struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_13 * V_14 = V_129 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_596 ;
V_596 = F_46 ( V_17 , V_24 -> V_17 ,
V_597 ,
V_599 ,
NULL ) ;
if ( V_596 == 0 )
V_14 -> V_288 = V_24 -> V_17 ;
return V_596 ;
}
static int F_257 ( char * V_600 )
{
T_2 V_17 ;
struct V_267 V_268 ;
V_17 = F_18 ( V_11 ) ;
V_268 . type = V_601 ;
V_268 . V_273 . V_600 = V_600 ;
return F_46 ( V_17 , V_18 , V_278 ,
V_602 , & V_268 ) ;
}
static int F_258 ( struct V_20 * V_146 , T_12 V_603 )
{
return F_106 ( V_146 , V_604 ) ;
}
static int F_259 ( struct V_20 * V_146 )
{
return F_106 ( V_146 , V_605 ) ;
}
static int F_260 ( struct V_20 * V_146 )
{
return F_106 ( V_146 , V_606 ) ;
}
static void F_261 ( struct V_20 * V_146 , T_2 * V_522 )
{
* V_522 = F_18 ( V_146 ) ;
}
static int F_262 ( struct V_20 * V_146 , int V_607 )
{
int V_53 ;
V_53 = F_263 ( V_146 , V_607 ) ;
if ( V_53 )
return V_53 ;
return F_106 ( V_146 , V_608 ) ;
}
static int F_264 ( struct V_20 * V_146 , int V_609 )
{
int V_53 ;
V_53 = F_265 ( V_146 , V_609 ) ;
if ( V_53 )
return V_53 ;
return F_106 ( V_146 , V_608 ) ;
}
static int F_266 ( struct V_20 * V_146 )
{
return F_106 ( V_146 , V_610 ) ;
}
static int F_267 ( struct V_20 * V_146 , unsigned int V_611 ,
struct V_425 * V_612 )
{
struct V_425 * V_613 = V_146 -> signal -> V_426 + V_611 ;
if ( V_613 -> V_433 != V_612 -> V_433 )
return F_106 ( V_146 , V_614 ) ;
return 0 ;
}
static int F_268 ( struct V_20 * V_146 )
{
int V_53 ;
V_53 = F_269 ( V_146 ) ;
if ( V_53 )
return V_53 ;
return F_106 ( V_146 , V_608 ) ;
}
static int F_270 ( struct V_20 * V_146 )
{
return F_106 ( V_146 , V_610 ) ;
}
static int F_271 ( struct V_20 * V_146 )
{
return F_106 ( V_146 , V_608 ) ;
}
static int F_272 ( struct V_20 * V_146 , struct V_615 * V_616 ,
int V_243 , T_2 V_522 )
{
T_2 V_244 ;
int V_53 ;
if ( ! V_243 )
V_244 = V_617 ;
else
V_244 = F_103 ( V_243 ) ;
if ( V_522 )
V_53 = F_46 ( V_522 , F_18 ( V_146 ) ,
V_257 , V_244 , NULL ) ;
else
V_53 = F_106 ( V_146 , V_244 ) ;
return V_53 ;
}
static int F_273 ( struct V_20 * V_146 )
{
return F_105 ( V_146 , V_11 , V_246 ) ;
}
static void F_274 ( struct V_20 * V_146 ,
struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 = F_18 ( V_146 ) ;
V_24 -> V_17 = V_17 ;
V_24 -> V_125 = 1 ;
}
static int F_275 ( struct V_618 * V_619 ,
struct V_267 * V_268 , T_13 * V_620 )
{
int V_621 , V_622 , V_596 = - V_91 ;
struct V_623 V_624 , * V_625 ;
V_621 = F_276 ( V_619 ) ;
V_625 = F_277 ( V_619 , V_621 , sizeof( V_624 ) , & V_624 ) ;
if ( V_625 == NULL )
goto V_74;
V_622 = V_625 -> V_626 * 4 ;
if ( V_622 < sizeof( V_624 ) )
goto V_74;
V_268 -> V_273 . V_627 -> V_628 . V_629 = V_625 -> V_629 ;
V_268 -> V_273 . V_627 -> V_628 . V_630 = V_625 -> V_630 ;
V_596 = 0 ;
if ( V_620 )
* V_620 = V_625 -> V_184 ;
switch ( V_625 -> V_184 ) {
case V_186 : {
struct V_631 V_632 , * V_633 ;
if ( F_278 ( V_625 -> V_634 ) & V_635 )
break;
V_621 += V_622 ;
V_633 = F_277 ( V_619 , V_621 , sizeof( V_632 ) , & V_632 ) ;
if ( V_633 == NULL )
break;
V_268 -> V_273 . V_627 -> V_636 = V_633 -> V_637 ;
V_268 -> V_273 . V_627 -> V_638 = V_633 -> V_639 ;
break;
}
case V_187 : {
struct V_640 V_641 , * V_642 ;
if ( F_278 ( V_625 -> V_634 ) & V_635 )
break;
V_621 += V_622 ;
V_642 = F_277 ( V_619 , V_621 , sizeof( V_641 ) , & V_641 ) ;
if ( V_642 == NULL )
break;
V_268 -> V_273 . V_627 -> V_636 = V_642 -> V_637 ;
V_268 -> V_273 . V_627 -> V_638 = V_642 -> V_639 ;
break;
}
case V_643 : {
struct V_644 V_645 , * V_646 ;
if ( F_278 ( V_625 -> V_634 ) & V_635 )
break;
V_621 += V_622 ;
V_646 = F_277 ( V_619 , V_621 , sizeof( V_645 ) , & V_645 ) ;
if ( V_646 == NULL )
break;
V_268 -> V_273 . V_627 -> V_636 = V_646 -> V_647 ;
V_268 -> V_273 . V_627 -> V_638 = V_646 -> V_648 ;
break;
}
default:
break;
}
V_74:
return V_596 ;
}
static int F_279 ( struct V_618 * V_619 ,
struct V_267 * V_268 , T_13 * V_620 )
{
T_13 V_649 ;
int V_596 = - V_91 , V_621 ;
struct V_650 V_651 , * V_652 ;
T_14 V_634 ;
V_621 = F_276 ( V_619 ) ;
V_652 = F_277 ( V_619 , V_621 , sizeof( V_651 ) , & V_651 ) ;
if ( V_652 == NULL )
goto V_74;
V_268 -> V_273 . V_627 -> V_653 . V_629 = V_652 -> V_629 ;
V_268 -> V_273 . V_627 -> V_653 . V_630 = V_652 -> V_630 ;
V_596 = 0 ;
V_649 = V_652 -> V_649 ;
V_621 += sizeof( V_651 ) ;
V_621 = F_280 ( V_619 , V_621 , & V_649 , & V_634 ) ;
if ( V_621 < 0 )
goto V_74;
if ( V_620 )
* V_620 = V_649 ;
switch ( V_649 ) {
case V_186 : {
struct V_631 V_632 , * V_633 ;
V_633 = F_277 ( V_619 , V_621 , sizeof( V_632 ) , & V_632 ) ;
if ( V_633 == NULL )
break;
V_268 -> V_273 . V_627 -> V_636 = V_633 -> V_637 ;
V_268 -> V_273 . V_627 -> V_638 = V_633 -> V_639 ;
break;
}
case V_187 : {
struct V_640 V_641 , * V_642 ;
V_642 = F_277 ( V_619 , V_621 , sizeof( V_641 ) , & V_641 ) ;
if ( V_642 == NULL )
break;
V_268 -> V_273 . V_627 -> V_636 = V_642 -> V_637 ;
V_268 -> V_273 . V_627 -> V_638 = V_642 -> V_639 ;
break;
}
case V_643 : {
struct V_644 V_645 , * V_646 ;
V_646 = F_277 ( V_619 , V_621 , sizeof( V_645 ) , & V_645 ) ;
if ( V_646 == NULL )
break;
V_268 -> V_273 . V_627 -> V_636 = V_646 -> V_647 ;
V_268 -> V_273 . V_627 -> V_638 = V_646 -> V_648 ;
break;
}
default:
break;
}
V_74:
return V_596 ;
}
static int F_281 ( struct V_618 * V_619 , struct V_267 * V_268 ,
char * * V_654 , int V_655 , T_13 * V_620 )
{
char * V_656 ;
int V_596 ;
switch ( V_268 -> V_273 . V_627 -> V_188 ) {
case V_195 :
V_596 = F_275 ( V_619 , V_268 , V_620 ) ;
if ( V_596 )
goto V_657;
V_656 = ( char * ) ( V_655 ? & V_268 -> V_273 . V_627 -> V_628 . V_629 :
& V_268 -> V_273 . V_627 -> V_628 . V_630 ) ;
goto V_658;
#if F_282 ( V_659 ) || F_282 ( V_660 )
case V_196 :
V_596 = F_279 ( V_619 , V_268 , V_620 ) ;
if ( V_596 )
goto V_657;
V_656 = ( char * ) ( V_655 ? & V_268 -> V_273 . V_627 -> V_653 . V_629 :
& V_268 -> V_273 . V_627 -> V_653 . V_630 ) ;
goto V_658;
#endif
default:
V_656 = NULL ;
goto V_658;
}
V_657:
F_50 ( V_71
L_45
L_46 ) ;
return V_596 ;
V_658:
if ( V_654 )
* V_654 = V_656 ;
return 0 ;
}
static int F_283 ( struct V_618 * V_619 , T_4 V_188 , T_2 * V_17 )
{
int V_570 ;
T_2 V_661 ;
T_2 V_662 ;
T_2 V_663 ;
V_570 = F_284 ( V_619 , & V_661 ) ;
if ( F_115 ( V_570 ) )
return - V_392 ;
V_570 = F_285 ( V_619 , V_188 , & V_663 , & V_662 ) ;
if ( F_115 ( V_570 ) )
return - V_392 ;
V_570 = F_286 ( V_662 , V_663 , V_661 , V_17 ) ;
if ( F_115 ( V_570 ) ) {
F_50 ( V_71
L_47
L_48 ) ;
return - V_392 ;
}
return 0 ;
}
static int F_287 ( T_2 V_664 , T_2 V_665 , T_2 * V_666 )
{
int V_570 = 0 ;
if ( V_665 != V_667 )
V_570 = F_288 ( V_664 , V_665 , V_666 ) ;
else
* V_666 = V_664 ;
return V_570 ;
}
static int F_289 ( const struct V_13 * V_14 ,
T_4 V_668 , T_2 * V_669 )
{
if ( V_14 -> V_395 > V_667 ) {
* V_669 = V_14 -> V_395 ;
return 0 ;
}
return F_101 ( V_14 -> V_17 , V_14 -> V_17 , V_668 , NULL ,
V_669 ) ;
}
static int F_290 ( struct V_20 * V_21 , struct V_670 * V_671 , T_2 V_254 )
{
struct V_672 * V_673 = V_671 -> V_674 ;
struct V_267 V_268 ;
struct V_675 V_627 = { 0 ,} ;
T_2 V_256 = F_18 ( V_21 ) ;
if ( V_673 -> V_17 == V_18 )
return 0 ;
V_268 . type = V_676 ;
V_268 . V_273 . V_627 = & V_627 ;
V_268 . V_273 . V_627 -> V_671 = V_671 ;
return F_46 ( V_256 , V_673 -> V_17 , V_673 -> V_31 , V_254 , & V_268 ) ;
}
static int F_291 ( int V_188 , int type ,
int V_184 , int V_677 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_287 ;
T_4 V_668 ;
int V_53 ;
if ( V_677 )
return 0 ;
V_668 = F_85 ( V_188 , type , V_184 ) ;
V_53 = F_289 ( V_14 , V_668 , & V_287 ) ;
if ( V_53 )
return V_53 ;
return F_46 ( V_14 -> V_17 , V_287 , V_668 , V_678 , NULL ) ;
}
static int F_292 ( struct V_679 * V_670 , int V_188 ,
int type , int V_184 , int V_677 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_24 = F_293 ( V_670 ) -> V_33 ;
struct V_672 * V_673 ;
int V_570 = 0 ;
V_24 -> V_31 = F_85 ( V_188 , type , V_184 ) ;
if ( V_677 )
V_24 -> V_17 = V_18 ;
else {
V_570 = F_289 ( V_14 , V_24 -> V_31 , & ( V_24 -> V_17 ) ) ;
if ( V_570 )
return V_570 ;
}
V_24 -> V_125 = 1 ;
if ( V_670 -> V_671 ) {
V_673 = V_670 -> V_671 -> V_674 ;
V_673 -> V_17 = V_24 -> V_17 ;
V_673 -> V_31 = V_24 -> V_31 ;
V_570 = F_294 ( V_670 -> V_671 , V_188 ) ;
}
return V_570 ;
}
static int F_295 ( struct V_679 * V_670 , struct V_680 * V_681 , int V_682 )
{
struct V_670 * V_671 = V_670 -> V_671 ;
T_4 V_188 ;
int V_570 ;
V_570 = F_290 ( V_11 , V_671 , V_683 ) ;
if ( V_570 )
goto V_74;
V_188 = V_671 -> V_684 ;
if ( V_188 == V_195 || V_188 == V_196 ) {
char * V_656 ;
struct V_672 * V_673 = V_671 -> V_674 ;
struct V_267 V_268 ;
struct V_675 V_627 = { 0 ,} ;
struct V_685 * V_686 = NULL ;
struct V_687 * V_688 = NULL ;
unsigned short V_689 ;
T_2 V_17 , V_690 ;
if ( V_188 == V_195 ) {
V_686 = (struct V_685 * ) V_681 ;
V_689 = F_278 ( V_686 -> V_691 ) ;
V_656 = ( char * ) & V_686 -> V_692 . V_693 ;
} else {
V_688 = (struct V_687 * ) V_681 ;
V_689 = F_278 ( V_688 -> V_694 ) ;
V_656 = ( char * ) & V_688 -> V_695 . V_696 ;
}
if ( V_689 ) {
int V_697 , V_698 ;
F_296 ( F_297 ( V_671 ) , & V_697 , & V_698 ) ;
if ( V_689 < V_699 ( V_700, V_697 ) || V_689 > V_698 ) {
V_570 = F_298 ( V_671 -> V_701 ,
V_689 , & V_17 ) ;
if ( V_570 )
goto V_74;
V_268 . type = V_676 ;
V_268 . V_273 . V_627 = & V_627 ;
V_268 . V_273 . V_627 -> V_636 = F_299 ( V_689 ) ;
V_268 . V_273 . V_627 -> V_188 = V_188 ;
V_570 = F_46 ( V_673 -> V_17 , V_17 ,
V_673 -> V_31 ,
V_702 , & V_268 ) ;
if ( V_570 )
goto V_74;
}
}
switch ( V_673 -> V_31 ) {
case V_197 :
V_690 = V_703 ;
break;
case V_199 :
V_690 = V_704 ;
break;
case V_201 :
V_690 = V_705 ;
break;
default:
V_690 = V_706 ;
break;
}
V_570 = F_300 ( V_656 , V_188 , & V_17 ) ;
if ( V_570 )
goto V_74;
V_268 . type = V_676 ;
V_268 . V_273 . V_627 = & V_627 ;
V_268 . V_273 . V_627 -> V_636 = F_299 ( V_689 ) ;
V_268 . V_273 . V_627 -> V_188 = V_188 ;
if ( V_188 == V_195 )
V_268 . V_273 . V_627 -> V_628 . V_629 = V_686 -> V_692 . V_693 ;
else
V_268 . V_273 . V_627 -> V_653 . V_629 = V_688 -> V_695 ;
V_570 = F_46 ( V_673 -> V_17 , V_17 ,
V_673 -> V_31 , V_690 , & V_268 ) ;
if ( V_570 )
goto V_74;
}
V_74:
return V_570 ;
}
static int F_301 ( struct V_679 * V_670 , struct V_680 * V_681 , int V_682 )
{
struct V_670 * V_671 = V_670 -> V_671 ;
struct V_672 * V_673 = V_671 -> V_674 ;
int V_570 ;
V_570 = F_290 ( V_11 , V_671 , V_707 ) ;
if ( V_570 )
return V_570 ;
if ( V_673 -> V_31 == V_197 ||
V_673 -> V_31 == V_201 ) {
struct V_267 V_268 ;
struct V_675 V_627 = { 0 ,} ;
struct V_685 * V_686 = NULL ;
struct V_687 * V_688 = NULL ;
unsigned short V_689 ;
T_2 V_17 , V_244 ;
if ( V_671 -> V_684 == V_195 ) {
V_686 = (struct V_685 * ) V_681 ;
if ( V_682 < sizeof( struct V_685 ) )
return - V_91 ;
V_689 = F_278 ( V_686 -> V_691 ) ;
} else {
V_688 = (struct V_687 * ) V_681 ;
if ( V_682 < V_708 )
return - V_91 ;
V_689 = F_278 ( V_688 -> V_694 ) ;
}
V_570 = F_298 ( V_671 -> V_701 , V_689 , & V_17 ) ;
if ( V_570 )
goto V_74;
V_244 = ( V_673 -> V_31 == V_197 ) ?
V_709 : V_710 ;
V_268 . type = V_676 ;
V_268 . V_273 . V_627 = & V_627 ;
V_268 . V_273 . V_627 -> V_638 = F_299 ( V_689 ) ;
V_268 . V_273 . V_627 -> V_188 = V_671 -> V_684 ;
V_570 = F_46 ( V_673 -> V_17 , V_17 , V_673 -> V_31 , V_244 , & V_268 ) ;
if ( V_570 )
goto V_74;
}
V_570 = F_302 ( V_671 , V_681 ) ;
V_74:
return V_570 ;
}
static int F_303 ( struct V_679 * V_670 , int V_711 )
{
return F_290 ( V_11 , V_670 -> V_671 , V_712 ) ;
}
static int F_304 ( struct V_679 * V_670 , struct V_679 * V_713 )
{
int V_570 ;
struct V_23 * V_24 ;
struct V_23 * V_142 ;
V_570 = F_290 ( V_11 , V_670 -> V_671 , V_714 ) ;
if ( V_570 )
return V_570 ;
V_142 = F_293 ( V_713 ) -> V_33 ;
V_24 = F_293 ( V_670 ) -> V_33 ;
V_142 -> V_31 = V_24 -> V_31 ;
V_142 -> V_17 = V_24 -> V_17 ;
V_142 -> V_125 = 1 ;
return 0 ;
}
static int F_305 ( struct V_679 * V_670 , struct V_715 * V_716 ,
int V_510 )
{
return F_290 ( V_11 , V_670 -> V_671 , V_717 ) ;
}
static int F_306 ( struct V_679 * V_670 , struct V_715 * V_716 ,
int V_510 , int V_80 )
{
return F_290 ( V_11 , V_670 -> V_671 , V_718 ) ;
}
static int F_307 ( struct V_679 * V_670 )
{
return F_290 ( V_11 , V_670 -> V_671 , V_719 ) ;
}
static int F_308 ( struct V_679 * V_670 )
{
return F_290 ( V_11 , V_670 -> V_671 , V_719 ) ;
}
static int F_309 ( struct V_679 * V_670 , int V_720 , int V_721 )
{
int V_570 ;
V_570 = F_290 ( V_11 , V_670 -> V_671 , V_722 ) ;
if ( V_570 )
return V_570 ;
return F_310 ( V_670 , V_720 , V_721 ) ;
}
static int F_311 ( struct V_679 * V_670 , int V_720 ,
int V_721 )
{
return F_290 ( V_11 , V_670 -> V_671 , V_723 ) ;
}
static int F_312 ( struct V_679 * V_670 , int V_724 )
{
return F_290 ( V_11 , V_670 -> V_671 , V_725 ) ;
}
static int F_313 ( struct V_670 * V_670 ,
struct V_670 * V_726 ,
struct V_670 * V_727 )
{
struct V_672 * V_728 = V_670 -> V_674 ;
struct V_672 * V_729 = V_726 -> V_674 ;
struct V_672 * V_730 = V_727 -> V_674 ;
struct V_267 V_268 ;
struct V_675 V_627 = { 0 ,} ;
int V_570 ;
V_268 . type = V_676 ;
V_268 . V_273 . V_627 = & V_627 ;
V_268 . V_273 . V_627 -> V_671 = V_726 ;
V_570 = F_46 ( V_728 -> V_17 , V_729 -> V_17 ,
V_729 -> V_31 ,
V_731 , & V_268 ) ;
if ( V_570 )
return V_570 ;
V_730 -> V_732 = V_728 -> V_17 ;
V_570 = F_288 ( V_729 -> V_17 , V_728 -> V_17 ,
& V_730 -> V_17 ) ;
if ( V_570 )
return V_570 ;
V_728 -> V_732 = V_730 -> V_17 ;
return 0 ;
}
static int F_314 ( struct V_679 * V_670 ,
struct V_679 * V_726 )
{
struct V_672 * V_733 = V_670 -> V_671 -> V_674 ;
struct V_672 * V_734 = V_726 -> V_671 -> V_674 ;
struct V_267 V_268 ;
struct V_675 V_627 = { 0 ,} ;
V_268 . type = V_676 ;
V_268 . V_273 . V_627 = & V_627 ;
V_268 . V_273 . V_627 -> V_671 = V_726 -> V_671 ;
return F_46 ( V_733 -> V_17 , V_734 -> V_17 , V_734 -> V_31 , V_735 ,
& V_268 ) ;
}
static int F_315 ( struct V_627 * V_347 , int V_736 ,
char * V_656 , T_4 V_188 , T_2 V_732 ,
struct V_267 * V_268 )
{
int V_570 ;
T_2 V_737 ;
T_2 V_738 ;
V_570 = F_316 ( V_347 , V_736 , & V_737 ) ;
if ( V_570 )
return V_570 ;
V_570 = F_46 ( V_732 , V_737 ,
V_739 , V_740 , V_268 ) ;
if ( V_570 )
return V_570 ;
V_570 = F_300 ( V_656 , V_188 , & V_738 ) ;
if ( V_570 )
return V_570 ;
return F_46 ( V_732 , V_738 ,
V_741 , V_742 , V_268 ) ;
}
static int F_317 ( struct V_670 * V_671 , struct V_618 * V_619 ,
T_4 V_188 )
{
int V_570 = 0 ;
struct V_672 * V_673 = V_671 -> V_674 ;
T_2 V_664 = V_673 -> V_17 ;
struct V_267 V_268 ;
struct V_675 V_627 = { 0 ,} ;
char * V_656 ;
V_268 . type = V_676 ;
V_268 . V_273 . V_627 = & V_627 ;
V_268 . V_273 . V_627 -> V_743 = V_619 -> V_744 ;
V_268 . V_273 . V_627 -> V_188 = V_188 ;
V_570 = F_281 ( V_619 , & V_268 , & V_656 , 1 , NULL ) ;
if ( V_570 )
return V_570 ;
if ( F_4 () ) {
V_570 = F_46 ( V_664 , V_619 -> V_745 , V_746 ,
V_747 , & V_268 ) ;
if ( V_570 )
return V_570 ;
}
V_570 = F_318 ( V_673 , V_619 , V_188 , & V_268 ) ;
if ( V_570 )
return V_570 ;
V_570 = F_319 ( V_673 -> V_17 , V_619 , & V_268 ) ;
return V_570 ;
}
static int F_320 ( struct V_670 * V_671 , struct V_618 * V_619 )
{
int V_570 ;
struct V_672 * V_673 = V_671 -> V_674 ;
T_4 V_188 = V_671 -> V_684 ;
T_2 V_664 = V_673 -> V_17 ;
struct V_267 V_268 ;
struct V_675 V_627 = { 0 ,} ;
char * V_656 ;
T_13 V_748 ;
T_13 V_749 ;
if ( V_188 != V_195 && V_188 != V_196 )
return 0 ;
if ( V_188 == V_196 && V_619 -> V_184 == F_299 ( V_750 ) )
V_188 = V_195 ;
if ( ! V_751 )
return F_317 ( V_671 , V_619 , V_188 ) ;
V_748 = F_4 () ;
V_749 = F_6 () ;
if ( ! V_748 && ! V_749 )
return 0 ;
V_268 . type = V_676 ;
V_268 . V_273 . V_627 = & V_627 ;
V_268 . V_273 . V_627 -> V_743 = V_619 -> V_744 ;
V_268 . V_273 . V_627 -> V_188 = V_188 ;
V_570 = F_281 ( V_619 , & V_268 , & V_656 , 1 , NULL ) ;
if ( V_570 )
return V_570 ;
if ( V_749 ) {
T_2 V_732 ;
V_570 = F_283 ( V_619 , V_188 , & V_732 ) ;
if ( V_570 )
return V_570 ;
V_570 = F_315 ( F_297 ( V_671 ) , V_619 -> V_744 ,
V_656 , V_188 , V_732 , & V_268 ) ;
if ( V_570 ) {
F_321 ( V_619 , V_570 , 0 ) ;
return V_570 ;
}
V_570 = F_46 ( V_664 , V_732 , V_752 ,
V_753 , & V_268 ) ;
if ( V_570 ) {
F_321 ( V_619 , V_570 , 0 ) ;
return V_570 ;
}
}
if ( V_748 ) {
V_570 = F_46 ( V_664 , V_619 -> V_745 , V_746 ,
V_747 , & V_268 ) ;
if ( V_570 )
return V_570 ;
}
return V_570 ;
}
static int F_322 ( struct V_679 * V_670 , char T_15 * V_754 ,
int T_15 * V_755 , unsigned V_89 )
{
int V_570 = 0 ;
char * V_756 ;
T_2 V_757 ;
struct V_672 * V_673 = V_670 -> V_671 -> V_674 ;
T_2 V_732 = V_667 ;
if ( V_673 -> V_31 == V_192 ||
V_673 -> V_31 == V_197 )
V_732 = V_673 -> V_732 ;
if ( V_732 == V_667 )
return - V_758 ;
V_570 = F_60 ( V_732 , & V_756 , & V_757 ) ;
if ( V_570 )
return V_570 ;
if ( V_757 > V_89 ) {
V_570 = - V_237 ;
goto V_759;
}
if ( F_323 ( V_754 , V_756 , V_757 ) )
V_570 = - V_760 ;
V_759:
if ( F_324 ( V_757 , V_755 ) )
V_570 = - V_760 ;
F_39 ( V_756 ) ;
return V_570 ;
}
static int F_325 ( struct V_679 * V_670 , struct V_618 * V_619 , T_2 * V_522 )
{
T_2 V_761 = V_667 ;
T_4 V_188 ;
if ( V_619 && V_619 -> V_184 == F_299 ( V_750 ) )
V_188 = V_195 ;
else if ( V_619 && V_619 -> V_184 == F_299 ( V_762 ) )
V_188 = V_196 ;
else if ( V_670 )
V_188 = V_670 -> V_671 -> V_684 ;
else
goto V_74;
if ( V_670 && V_188 == V_189 )
F_231 ( F_293 ( V_670 ) , & V_761 ) ;
else if ( V_619 )
F_283 ( V_619 , V_188 , & V_761 ) ;
V_74:
* V_522 = V_761 ;
if ( V_761 == V_667 )
return - V_91 ;
return 0 ;
}
static int F_326 ( struct V_670 * V_671 , int V_188 , T_11 V_763 )
{
struct V_672 * V_673 ;
V_673 = F_15 ( sizeof( * V_673 ) , V_763 ) ;
if ( ! V_673 )
return - V_27 ;
V_673 -> V_732 = V_30 ;
V_673 -> V_17 = V_30 ;
F_327 ( V_673 ) ;
V_671 -> V_674 = V_673 ;
return 0 ;
}
static void F_328 ( struct V_670 * V_671 )
{
struct V_672 * V_673 = V_671 -> V_674 ;
V_671 -> V_674 = NULL ;
F_329 ( V_673 ) ;
F_39 ( V_673 ) ;
}
static void F_330 ( const struct V_670 * V_671 , struct V_670 * V_727 )
{
struct V_672 * V_673 = V_671 -> V_674 ;
struct V_672 * V_764 = V_727 -> V_674 ;
V_764 -> V_17 = V_673 -> V_17 ;
V_764 -> V_732 = V_673 -> V_732 ;
V_764 -> V_31 = V_673 -> V_31 ;
F_327 ( V_764 ) ;
}
static void F_331 ( struct V_670 * V_671 , T_2 * V_522 )
{
if ( ! V_671 )
* V_522 = V_765 ;
else {
struct V_672 * V_673 = V_671 -> V_674 ;
* V_522 = V_673 -> V_17 ;
}
}
static void F_332 ( struct V_670 * V_671 , struct V_679 * V_340 )
{
struct V_23 * V_24 = F_293 ( V_340 ) -> V_33 ;
struct V_672 * V_673 = V_671 -> V_674 ;
if ( V_671 -> V_684 == V_195 || V_671 -> V_684 == V_196 ||
V_671 -> V_684 == V_189 )
V_24 -> V_17 = V_673 -> V_17 ;
V_673 -> V_31 = V_24 -> V_31 ;
}
static int F_333 ( struct V_670 * V_671 , struct V_618 * V_619 ,
struct V_766 * V_767 )
{
struct V_672 * V_673 = V_671 -> V_674 ;
int V_570 ;
T_4 V_188 = V_767 -> V_768 -> V_188 ;
T_2 V_769 ;
T_2 V_770 ;
V_570 = F_283 ( V_619 , V_188 , & V_770 ) ;
if ( V_570 )
return V_570 ;
V_570 = F_287 ( V_673 -> V_17 , V_770 , & V_769 ) ;
if ( V_570 )
return V_570 ;
V_767 -> V_522 = V_769 ;
V_767 -> V_761 = V_770 ;
return F_334 ( V_767 , V_188 ) ;
}
static void F_335 ( struct V_670 * V_727 ,
const struct V_766 * V_767 )
{
struct V_672 * V_764 = V_727 -> V_674 ;
V_764 -> V_17 = V_767 -> V_522 ;
V_764 -> V_732 = V_767 -> V_761 ;
F_336 ( V_727 , V_767 -> V_768 -> V_188 ) ;
}
static void F_337 ( struct V_670 * V_671 , struct V_618 * V_619 )
{
T_4 V_188 = V_671 -> V_684 ;
struct V_672 * V_673 = V_671 -> V_674 ;
if ( V_188 == V_196 && V_619 -> V_184 == F_299 ( V_750 ) )
V_188 = V_195 ;
F_283 ( V_619 , V_188 , & V_673 -> V_732 ) ;
}
static void F_338 ( struct V_618 * V_619 , struct V_670 * V_671 )
{
F_339 ( V_619 , V_671 ) ;
}
static int F_340 ( T_2 V_17 )
{
const struct V_13 * V_771 ;
T_2 V_256 ;
V_771 = F_23 () ;
V_256 = V_771 -> V_17 ;
return F_46 ( V_256 , V_17 , V_746 , V_772 , NULL ) ;
}
static void F_341 ( void )
{
F_342 ( & V_7 ) ;
}
static void F_343 ( void )
{
F_344 ( & V_7 ) ;
}
static void F_345 ( const struct V_766 * V_767 ,
struct V_773 * V_774 )
{
V_774 -> V_775 = V_767 -> V_522 ;
}
static int F_346 ( void * * V_19 )
{
struct V_776 * V_777 ;
V_777 = F_15 ( sizeof( * V_777 ) , V_15 ) ;
if ( ! V_777 )
return - V_27 ;
V_777 -> V_17 = F_22 () ;
* V_19 = V_777 ;
return 0 ;
}
static void F_347 ( void * V_19 )
{
F_39 ( V_19 ) ;
}
static int F_348 ( void )
{
T_2 V_17 = F_22 () ;
return F_46 ( V_17 , V_17 , V_778 , V_779 ,
NULL ) ;
}
static int F_349 ( void * V_19 )
{
struct V_776 * V_777 = V_19 ;
return F_46 ( F_22 () , V_777 -> V_17 , V_778 ,
V_780 , NULL ) ;
}
static int F_350 ( struct V_670 * V_671 , void * V_19 )
{
struct V_776 * V_777 = V_19 ;
struct V_672 * V_673 = V_671 -> V_674 ;
V_673 -> V_17 = V_777 -> V_17 ;
V_673 -> V_31 = V_778 ;
return 0 ;
}
static int F_351 ( void * V_19 )
{
struct V_776 * V_777 = V_19 ;
T_2 V_17 = F_22 () ;
int V_570 ;
V_570 = F_46 ( V_17 , V_777 -> V_17 , V_778 ,
V_781 , NULL ) ;
if ( V_570 )
return V_570 ;
V_570 = F_46 ( V_17 , V_17 , V_778 ,
V_782 , NULL ) ;
if ( V_570 )
return V_570 ;
V_777 -> V_17 = V_17 ;
return 0 ;
}
static int F_352 ( struct V_670 * V_671 , struct V_618 * V_619 )
{
int V_570 = 0 ;
T_2 V_244 ;
struct V_783 * V_784 ;
struct V_672 * V_673 = V_671 -> V_674 ;
if ( V_619 -> V_89 < V_785 ) {
V_570 = - V_91 ;
goto V_74;
}
V_784 = F_353 ( V_619 ) ;
V_570 = F_354 ( V_673 -> V_31 , V_784 -> V_786 , & V_244 ) ;
if ( V_570 ) {
if ( V_570 == - V_91 ) {
F_50 ( V_71
L_49
L_50 ,
V_671 -> V_701 , V_784 -> V_786 , V_673 -> V_31 ) ;
if ( ! V_3 || F_355 () )
V_570 = 0 ;
}
if ( V_570 == - V_787 )
V_570 = 0 ;
goto V_74;
}
V_570 = F_290 ( V_11 , V_671 , V_244 ) ;
V_74:
return V_570 ;
}
static unsigned int F_356 ( struct V_618 * V_619 ,
const struct V_788 * V_789 ,
T_4 V_188 )
{
int V_570 ;
char * V_656 ;
T_2 V_732 ;
struct V_267 V_268 ;
struct V_675 V_627 = { 0 ,} ;
T_13 V_748 ;
T_13 V_790 ;
T_13 V_749 ;
if ( ! V_751 )
return V_791 ;
V_748 = F_4 () ;
V_790 = F_7 () ;
V_749 = F_6 () ;
if ( ! V_748 && ! V_749 )
return V_791 ;
if ( F_283 ( V_619 , V_188 , & V_732 ) != 0 )
return V_792 ;
V_268 . type = V_676 ;
V_268 . V_273 . V_627 = & V_627 ;
V_268 . V_273 . V_627 -> V_743 = V_789 -> V_736 ;
V_268 . V_273 . V_627 -> V_188 = V_188 ;
if ( F_281 ( V_619 , & V_268 , & V_656 , 1 , NULL ) != 0 )
return V_792 ;
if ( V_749 ) {
V_570 = F_315 ( F_357 ( V_789 ) , V_789 -> V_736 ,
V_656 , V_188 , V_732 , & V_268 ) ;
if ( V_570 ) {
F_321 ( V_619 , V_570 , 1 ) ;
return V_792 ;
}
}
if ( V_748 )
if ( F_46 ( V_732 , V_619 -> V_745 ,
V_746 , V_793 , & V_268 ) )
return V_792 ;
if ( V_790 )
if ( F_358 ( V_619 , V_188 , V_732 ) != 0 )
return V_792 ;
return V_791 ;
}
static unsigned int F_359 ( const struct V_794 * V_795 ,
struct V_618 * V_619 ,
const struct V_788 * V_796 ,
const struct V_788 * V_74 ,
int (* F_360)( struct V_618 * ) )
{
return F_356 ( V_619 , V_796 , V_195 ) ;
}
static unsigned int F_361 ( const struct V_794 * V_795 ,
struct V_618 * V_619 ,
const struct V_788 * V_796 ,
const struct V_788 * V_74 ,
int (* F_360)( struct V_618 * ) )
{
return F_356 ( V_619 , V_796 , V_196 ) ;
}
static unsigned int F_362 ( struct V_618 * V_619 ,
T_4 V_188 )
{
struct V_670 * V_671 ;
T_2 V_17 ;
if ( ! F_7 () )
return V_791 ;
V_671 = V_619 -> V_671 ;
if ( V_671 ) {
struct V_672 * V_673 ;
if ( V_671 -> V_797 == V_798 )
return V_791 ;
V_673 = V_671 -> V_674 ;
V_17 = V_673 -> V_17 ;
} else
V_17 = V_18 ;
if ( F_358 ( V_619 , V_188 , V_17 ) != 0 )
return V_792 ;
return V_791 ;
}
static unsigned int F_363 ( const struct V_794 * V_795 ,
struct V_618 * V_619 ,
const struct V_788 * V_796 ,
const struct V_788 * V_74 ,
int (* F_360)( struct V_618 * ) )
{
return F_362 ( V_619 , V_195 ) ;
}
static unsigned int F_364 ( struct V_618 * V_619 ,
int V_736 ,
T_4 V_188 )
{
struct V_670 * V_671 = V_619 -> V_671 ;
struct V_672 * V_673 ;
struct V_267 V_268 ;
struct V_675 V_627 = { 0 ,} ;
char * V_656 ;
T_13 V_620 ;
if ( V_671 == NULL )
return V_791 ;
V_673 = V_671 -> V_674 ;
V_268 . type = V_676 ;
V_268 . V_273 . V_627 = & V_627 ;
V_268 . V_273 . V_627 -> V_743 = V_736 ;
V_268 . V_273 . V_627 -> V_188 = V_188 ;
if ( F_281 ( V_619 , & V_268 , & V_656 , 0 , & V_620 ) )
return V_792 ;
if ( F_4 () )
if ( F_46 ( V_673 -> V_17 , V_619 -> V_745 ,
V_746 , V_799 , & V_268 ) )
return F_365 ( - V_800 ) ;
if ( F_366 ( V_673 -> V_17 , V_619 , & V_268 , V_620 ) )
return F_365 ( - V_800 ) ;
return V_791 ;
}
static unsigned int F_367 ( struct V_618 * V_619 ,
const struct V_788 * V_801 ,
T_4 V_188 )
{
T_2 V_802 ;
T_2 V_732 ;
int V_736 = V_801 -> V_736 ;
struct V_670 * V_671 ;
struct V_267 V_268 ;
struct V_675 V_627 = { 0 ,} ;
char * V_656 ;
T_13 V_748 ;
T_13 V_749 ;
if ( ! V_751 )
return F_364 ( V_619 , V_736 , V_188 ) ;
V_748 = F_4 () ;
V_749 = F_6 () ;
if ( ! V_748 && ! V_749 )
return V_791 ;
V_671 = V_619 -> V_671 ;
#ifdef F_368
if ( F_369 ( V_619 ) != NULL && F_369 ( V_619 ) -> V_803 != NULL &&
! ( V_671 != NULL && V_671 -> V_797 == V_798 ) )
return V_791 ;
#endif
if ( V_671 == NULL ) {
if ( V_619 -> V_744 ) {
V_802 = V_804 ;
if ( F_283 ( V_619 , V_188 , & V_732 ) )
return V_792 ;
} else {
V_802 = V_799 ;
V_732 = V_18 ;
}
} else if ( V_671 -> V_797 == V_798 ) {
T_2 V_665 ;
struct V_672 * V_673 = V_671 -> V_674 ;
if ( F_283 ( V_619 , V_188 , & V_665 ) )
return V_792 ;
if ( V_665 == V_667 ) {
switch ( V_188 ) {
case V_195 :
if ( F_370 ( V_619 ) -> V_80 & V_805 )
return V_791 ;
break;
case V_196 :
if ( F_371 ( V_619 ) -> V_80 & V_806 )
return V_791 ;
break;
default:
return F_365 ( - V_800 ) ;
}
}
if ( F_287 ( V_673 -> V_17 , V_665 , & V_732 ) )
return V_792 ;
V_802 = V_799 ;
} else {
struct V_672 * V_673 = V_671 -> V_674 ;
V_732 = V_673 -> V_17 ;
V_802 = V_799 ;
}
V_268 . type = V_676 ;
V_268 . V_273 . V_627 = & V_627 ;
V_268 . V_273 . V_627 -> V_743 = V_736 ;
V_268 . V_273 . V_627 -> V_188 = V_188 ;
if ( F_281 ( V_619 , & V_268 , & V_656 , 0 , NULL ) )
return V_792 ;
if ( V_748 )
if ( F_46 ( V_732 , V_619 -> V_745 ,
V_746 , V_802 , & V_268 ) )
return F_365 ( - V_800 ) ;
if ( V_749 ) {
T_2 V_737 ;
T_2 V_738 ;
if ( F_316 ( F_357 ( V_801 ) , V_736 , & V_737 ) )
return V_792 ;
if ( F_46 ( V_732 , V_737 ,
V_739 , V_807 , & V_268 ) )
return F_365 ( - V_800 ) ;
if ( F_300 ( V_656 , V_188 , & V_738 ) )
return V_792 ;
if ( F_46 ( V_732 , V_738 ,
V_741 , V_808 , & V_268 ) )
return F_365 ( - V_800 ) ;
}
return V_791 ;
}
static unsigned int F_372 ( const struct V_794 * V_795 ,
struct V_618 * V_619 ,
const struct V_788 * V_796 ,
const struct V_788 * V_74 ,
int (* F_360)( struct V_618 * ) )
{
return F_367 ( V_619 , V_74 , V_195 ) ;
}
static unsigned int F_373 ( const struct V_794 * V_795 ,
struct V_618 * V_619 ,
const struct V_788 * V_796 ,
const struct V_788 * V_74 ,
int (* F_360)( struct V_618 * ) )
{
return F_367 ( V_619 , V_74 , V_196 ) ;
}
static int F_374 ( struct V_670 * V_671 , struct V_618 * V_619 )
{
int V_570 ;
V_570 = F_375 ( V_671 , V_619 ) ;
if ( V_570 )
return V_570 ;
return F_352 ( V_671 , V_619 ) ;
}
static int F_376 ( struct V_20 * V_21 ,
struct V_809 * V_244 ,
T_4 V_31 )
{
struct V_810 * V_24 ;
T_2 V_17 ;
V_24 = F_15 ( sizeof( struct V_810 ) , V_15 ) ;
if ( ! V_24 )
return - V_27 ;
V_17 = F_18 ( V_21 ) ;
V_24 -> V_31 = V_31 ;
V_24 -> V_17 = V_17 ;
V_244 -> V_19 = V_24 ;
return 0 ;
}
static void F_377 ( struct V_809 * V_244 )
{
struct V_810 * V_24 = V_244 -> V_19 ;
V_244 -> V_19 = NULL ;
F_39 ( V_24 ) ;
}
static int F_378 ( struct V_811 * V_716 )
{
struct V_812 * V_813 ;
V_813 = F_15 ( sizeof( struct V_812 ) , V_15 ) ;
if ( ! V_813 )
return - V_27 ;
V_813 -> V_17 = V_30 ;
V_716 -> V_19 = V_813 ;
return 0 ;
}
static void F_379 ( struct V_811 * V_716 )
{
struct V_812 * V_813 = V_716 -> V_19 ;
V_716 -> V_19 = NULL ;
F_39 ( V_813 ) ;
}
static int F_380 ( struct V_809 * V_814 ,
T_2 V_254 )
{
struct V_810 * V_24 ;
struct V_267 V_268 ;
T_2 V_17 = F_22 () ;
V_24 = V_814 -> V_19 ;
V_268 . type = V_815 ;
V_268 . V_273 . V_816 = V_814 -> V_817 ;
return F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_254 , & V_268 ) ;
}
static int F_381 ( struct V_811 * V_716 )
{
return F_378 ( V_716 ) ;
}
static void F_382 ( struct V_811 * V_716 )
{
F_379 ( V_716 ) ;
}
static int F_383 ( struct V_818 * V_819 )
{
struct V_810 * V_24 ;
struct V_267 V_268 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_53 = F_376 ( V_11 , & V_819 -> V_820 , V_821 ) ;
if ( V_53 )
return V_53 ;
V_24 = V_819 -> V_820 . V_19 ;
V_268 . type = V_815 ;
V_268 . V_273 . V_816 = V_819 -> V_820 . V_817 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_821 ,
V_822 , & V_268 ) ;
if ( V_53 ) {
F_377 ( & V_819 -> V_820 ) ;
return V_53 ;
}
return 0 ;
}
static void F_384 ( struct V_818 * V_819 )
{
F_377 ( & V_819 -> V_820 ) ;
}
static int F_385 ( struct V_818 * V_819 , int V_823 )
{
struct V_810 * V_24 ;
struct V_267 V_268 ;
T_2 V_17 = F_22 () ;
V_24 = V_819 -> V_820 . V_19 ;
V_268 . type = V_815 ;
V_268 . V_273 . V_816 = V_819 -> V_820 . V_817 ;
return F_46 ( V_17 , V_24 -> V_17 , V_821 ,
V_824 , & V_268 ) ;
}
static int F_386 ( struct V_818 * V_819 , int V_525 )
{
int V_570 ;
int V_254 ;
switch ( V_525 ) {
case V_825 :
case V_826 :
return F_112 ( V_11 , V_827 ) ;
case V_828 :
case V_829 :
V_254 = V_830 | V_824 ;
break;
case V_831 :
V_254 = V_832 ;
break;
case V_833 :
V_254 = V_834 ;
break;
default:
return 0 ;
}
V_570 = F_380 ( & V_819 -> V_820 , V_254 ) ;
return V_570 ;
}
static int F_387 ( struct V_818 * V_819 , struct V_811 * V_716 , int V_823 )
{
struct V_810 * V_24 ;
struct V_812 * V_813 ;
struct V_267 V_268 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_24 = V_819 -> V_820 . V_19 ;
V_813 = V_716 -> V_19 ;
if ( V_813 -> V_17 == V_30 ) {
V_53 = F_101 ( V_17 , V_24 -> V_17 , V_835 ,
NULL , & V_813 -> V_17 ) ;
if ( V_53 )
return V_53 ;
}
V_268 . type = V_815 ;
V_268 . V_273 . V_816 = V_819 -> V_820 . V_817 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_821 ,
V_836 , & V_268 ) ;
if ( ! V_53 )
V_53 = F_46 ( V_17 , V_813 -> V_17 , V_835 ,
V_837 , & V_268 ) ;
if ( ! V_53 )
V_53 = F_46 ( V_813 -> V_17 , V_24 -> V_17 , V_821 ,
V_838 , & V_268 ) ;
return V_53 ;
}
static int F_388 ( struct V_818 * V_819 , struct V_811 * V_716 ,
struct V_20 * V_253 ,
long type , int V_169 )
{
struct V_810 * V_24 ;
struct V_812 * V_813 ;
struct V_267 V_268 ;
T_2 V_17 = F_18 ( V_253 ) ;
int V_53 ;
V_24 = V_819 -> V_820 . V_19 ;
V_813 = V_716 -> V_19 ;
V_268 . type = V_815 ;
V_268 . V_273 . V_816 = V_819 -> V_820 . V_817 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 ,
V_821 , V_839 , & V_268 ) ;
if ( ! V_53 )
V_53 = F_46 ( V_17 , V_813 -> V_17 ,
V_835 , V_840 , & V_268 ) ;
return V_53 ;
}
static int F_389 ( struct V_841 * V_842 )
{
struct V_810 * V_24 ;
struct V_267 V_268 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_53 = F_376 ( V_11 , & V_842 -> V_843 , V_844 ) ;
if ( V_53 )
return V_53 ;
V_24 = V_842 -> V_843 . V_19 ;
V_268 . type = V_815 ;
V_268 . V_273 . V_816 = V_842 -> V_843 . V_817 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_844 ,
V_845 , & V_268 ) ;
if ( V_53 ) {
F_377 ( & V_842 -> V_843 ) ;
return V_53 ;
}
return 0 ;
}
static void F_390 ( struct V_841 * V_842 )
{
F_377 ( & V_842 -> V_843 ) ;
}
static int F_391 ( struct V_841 * V_842 , int V_846 )
{
struct V_810 * V_24 ;
struct V_267 V_268 ;
T_2 V_17 = F_22 () ;
V_24 = V_842 -> V_843 . V_19 ;
V_268 . type = V_815 ;
V_268 . V_273 . V_816 = V_842 -> V_843 . V_817 ;
return F_46 ( V_17 , V_24 -> V_17 , V_844 ,
V_847 , & V_268 ) ;
}
static int F_392 ( struct V_841 * V_842 , int V_525 )
{
int V_254 ;
int V_570 ;
switch ( V_525 ) {
case V_825 :
case V_848 :
return F_112 ( V_11 , V_827 ) ;
case V_828 :
case V_849 :
V_254 = V_850 | V_847 ;
break;
case V_831 :
V_254 = V_851 ;
break;
case V_852 :
case V_853 :
V_254 = V_854 ;
break;
case V_833 :
V_254 = V_855 ;
break;
default:
return 0 ;
}
V_570 = F_380 ( & V_842 -> V_843 , V_254 ) ;
return V_570 ;
}
static int F_393 ( struct V_841 * V_842 ,
char T_15 * V_856 , int V_846 )
{
T_2 V_254 ;
if ( V_846 & V_857 )
V_254 = V_858 ;
else
V_254 = V_858 | V_859 ;
return F_380 ( & V_842 -> V_843 , V_254 ) ;
}
static int F_394 ( struct V_860 * V_861 )
{
struct V_810 * V_24 ;
struct V_267 V_268 ;
T_2 V_17 = F_22 () ;
int V_53 ;
V_53 = F_376 ( V_11 , & V_861 -> V_862 , V_863 ) ;
if ( V_53 )
return V_53 ;
V_24 = V_861 -> V_862 . V_19 ;
V_268 . type = V_815 ;
V_268 . V_273 . V_816 = V_861 -> V_862 . V_817 ;
V_53 = F_46 ( V_17 , V_24 -> V_17 , V_863 ,
V_864 , & V_268 ) ;
if ( V_53 ) {
F_377 ( & V_861 -> V_862 ) ;
return V_53 ;
}
return 0 ;
}
static void F_395 ( struct V_860 * V_861 )
{
F_377 ( & V_861 -> V_862 ) ;
}
static int F_396 ( struct V_860 * V_861 , int V_865 )
{
struct V_810 * V_24 ;
struct V_267 V_268 ;
T_2 V_17 = F_22 () ;
V_24 = V_861 -> V_862 . V_19 ;
V_268 . type = V_815 ;
V_268 . V_273 . V_816 = V_861 -> V_862 . V_817 ;
return F_46 ( V_17 , V_24 -> V_17 , V_863 ,
V_866 , & V_268 ) ;
}
static int F_397 ( struct V_860 * V_861 , int V_525 )
{
int V_570 ;
T_2 V_254 ;
switch ( V_525 ) {
case V_825 :
case V_867 :
return F_112 ( V_11 , V_827 ) ;
case V_868 :
case V_869 :
case V_870 :
V_254 = V_871 ;
break;
case V_872 :
case V_873 :
V_254 = V_874 ;
break;
case V_875 :
case V_876 :
V_254 = V_877 ;
break;
case V_833 :
V_254 = V_878 ;
break;
case V_831 :
V_254 = V_879 ;
break;
case V_828 :
case V_880 :
V_254 = V_871 | V_866 ;
break;
default:
return 0 ;
}
V_570 = F_380 ( & V_861 -> V_862 , V_254 ) ;
return V_570 ;
}
static int F_398 ( struct V_860 * V_861 ,
struct V_881 * V_882 , unsigned V_883 , int V_884 )
{
T_2 V_254 ;
if ( V_884 )
V_254 = V_874 | V_877 ;
else
V_254 = V_874 ;
return F_380 ( & V_861 -> V_862 , V_254 ) ;
}
static int F_399 ( struct V_809 * V_885 , short V_104 )
{
T_2 V_271 = 0 ;
V_271 = 0 ;
if ( V_104 & V_886 )
V_271 |= V_887 ;
if ( V_104 & V_888 )
V_271 |= V_889 ;
if ( V_271 == 0 )
return 0 ;
return F_380 ( V_885 , V_271 ) ;
}
static void F_400 ( struct V_809 * V_885 , T_2 * V_522 )
{
struct V_810 * V_24 = V_885 -> V_19 ;
* V_522 = V_24 -> V_17 ;
}
static void F_401 ( struct V_64 * V_64 , struct V_22 * V_22 )
{
if ( V_22 )
F_44 ( V_22 , V_64 ) ;
}
static int F_402 ( struct V_20 * V_146 ,
char * V_63 , char * * V_479 )
{
const struct V_13 * V_771 ;
T_2 V_17 ;
int error ;
unsigned V_89 ;
if ( V_11 != V_146 ) {
error = F_106 ( V_146 , V_890 ) ;
if ( error )
return error ;
}
F_19 () ;
V_771 = F_20 ( V_146 ) -> V_19 ;
if ( ! strcmp ( V_63 , L_51 ) )
V_17 = V_771 -> V_17 ;
else if ( ! strcmp ( V_63 , L_52 ) )
V_17 = V_771 -> V_16 ;
else if ( ! strcmp ( V_63 , L_53 ) )
V_17 = V_771 -> V_396 ;
else if ( ! strcmp ( V_63 , L_54 ) )
V_17 = V_771 -> V_288 ;
else if ( ! strcmp ( V_63 , L_55 ) )
V_17 = V_771 -> V_394 ;
else if ( ! strcmp ( V_63 , L_56 ) )
V_17 = V_771 -> V_395 ;
else
goto V_891;
F_21 () ;
if ( ! V_17 )
return 0 ;
error = F_60 ( V_17 , V_479 , & V_89 ) ;
if ( error )
return error ;
return V_89 ;
V_891:
F_21 () ;
return - V_91 ;
}
static int F_403 ( struct V_20 * V_146 ,
char * V_63 , void * V_479 , T_7 V_510 )
{
struct V_13 * V_14 ;
struct V_20 * V_404 ;
struct V_10 * V_129 ;
T_2 V_17 = 0 , V_406 ;
int error ;
char * V_1 = V_479 ;
if ( V_11 != V_146 ) {
return - V_392 ;
}
if ( ! strcmp ( V_63 , L_53 ) )
error = F_106 ( V_146 , V_892 ) ;
else if ( ! strcmp ( V_63 , L_54 ) )
error = F_106 ( V_146 , V_893 ) ;
else if ( ! strcmp ( V_63 , L_55 ) )
error = F_106 ( V_146 , V_894 ) ;
else if ( ! strcmp ( V_63 , L_56 ) )
error = F_106 ( V_146 , V_895 ) ;
else if ( ! strcmp ( V_63 , L_51 ) )
error = F_106 ( V_146 , V_896 ) ;
else
error = - V_91 ;
if ( error )
return error ;
if ( V_510 && V_1 [ 1 ] && V_1 [ 1 ] != '\n' ) {
if ( V_1 [ V_510 - 1 ] == '\n' ) {
V_1 [ V_510 - 1 ] = 0 ;
V_510 -- ;
}
error = F_67 ( V_479 , V_510 , & V_17 , V_15 ) ;
if ( error == - V_91 && ! strcmp ( V_63 , L_54 ) ) {
if ( ! F_215 ( V_512 ) ) {
struct V_513 * V_514 ;
T_7 V_515 ;
if ( V_1 [ V_510 - 1 ] == '\0' )
V_515 = V_510 - 1 ;
else
V_515 = V_510 ;
V_514 = F_218 ( V_11 -> V_516 , V_97 , V_517 ) ;
F_219 ( V_514 , L_57 ) ;
F_220 ( V_514 , V_479 , V_515 ) ;
F_221 ( V_514 ) ;
return error ;
}
error = F_222 ( V_479 , V_510 ,
& V_17 ) ;
}
if ( error )
return error ;
}
V_129 = F_404 () ;
if ( ! V_129 )
return - V_27 ;
V_14 = V_129 -> V_19 ;
if ( ! strcmp ( V_63 , L_53 ) ) {
V_14 -> V_396 = V_17 ;
} else if ( ! strcmp ( V_63 , L_54 ) ) {
V_14 -> V_288 = V_17 ;
} else if ( ! strcmp ( V_63 , L_55 ) ) {
error = F_122 ( V_17 , V_146 ) ;
if ( error )
goto V_897;
V_14 -> V_394 = V_17 ;
} else if ( ! strcmp ( V_63 , L_56 ) ) {
V_14 -> V_395 = V_17 ;
} else if ( ! strcmp ( V_63 , L_51 ) ) {
error = - V_91 ;
if ( V_17 == 0 )
goto V_897;
error = - V_391 ;
if ( ! F_405 () ) {
error = F_146 ( V_14 -> V_17 , V_17 ) ;
if ( error )
goto V_897;
}
error = F_46 ( V_14 -> V_17 , V_17 , V_257 ,
V_898 , NULL ) ;
if ( error )
goto V_897;
V_406 = 0 ;
F_19 () ;
V_404 = F_149 ( V_146 ) ;
if ( V_404 )
V_406 = F_18 ( V_404 ) ;
F_21 () ;
if ( V_404 ) {
error = F_46 ( V_406 , V_17 , V_257 ,
V_339 , NULL ) ;
if ( error )
goto V_897;
}
V_14 -> V_17 = V_17 ;
} else {
error = - V_91 ;
goto V_897;
}
F_406 ( V_129 ) ;
return V_510 ;
V_897:
F_407 ( V_129 ) ;
return error ;
}
static int F_408 ( const char * V_63 )
{
return ( strcmp ( V_63 , V_481 ) == 0 ) ;
}
static int F_409 ( T_2 V_522 , char * * V_461 , T_2 * V_899 )
{
return F_60 ( V_522 , V_461 , V_899 ) ;
}
static int F_410 ( const char * V_461 , T_2 V_899 , T_2 * V_522 )
{
return F_67 ( V_461 , V_899 , V_522 , V_15 ) ;
}
static void F_411 ( char * V_461 , T_2 V_899 )
{
F_39 ( V_461 ) ;
}
static int F_412 ( struct V_22 * V_22 , void * V_294 , T_2 V_477 )
{
return F_229 ( V_22 , V_481 , V_294 , V_477 , 0 ) ;
}
static int F_413 ( struct V_64 * V_64 , void * V_294 , T_2 V_477 )
{
return F_414 ( V_64 , V_75 , V_294 , V_477 , 0 ) ;
}
static int F_415 ( struct V_22 * V_22 , void * * V_294 , T_2 * V_477 )
{
int V_89 = 0 ;
V_89 = F_228 ( V_22 , V_481 ,
V_294 , true ) ;
if ( V_89 < 0 )
return V_89 ;
* V_477 = V_89 ;
return 0 ;
}
static int F_416 ( struct V_817 * V_900 , const struct V_10 * V_10 ,
unsigned long V_80 )
{
const struct V_13 * V_14 ;
struct V_901 * V_902 ;
V_902 = F_15 ( sizeof( struct V_901 ) , V_15 ) ;
if ( ! V_902 )
return - V_27 ;
V_14 = V_10 -> V_19 ;
if ( V_14 -> V_394 )
V_902 -> V_17 = V_14 -> V_394 ;
else
V_902 -> V_17 = V_14 -> V_17 ;
V_900 -> V_19 = V_902 ;
return 0 ;
}
static void F_417 ( struct V_817 * V_900 )
{
struct V_901 * V_902 = V_900 -> V_19 ;
V_900 -> V_19 = NULL ;
F_39 ( V_902 ) ;
}
static int F_418 ( T_16 V_903 ,
const struct V_10 * V_10 ,
unsigned V_244 )
{
struct V_817 * V_817 ;
struct V_901 * V_902 ;
T_2 V_17 ;
if ( V_244 == 0 )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_817 = F_419 ( V_903 ) ;
V_902 = V_817 -> V_19 ;
return F_46 ( V_17 , V_902 -> V_17 , V_295 , V_244 , NULL ) ;
}
static int F_420 ( struct V_817 * V_817 , char * * V_904 )
{
struct V_901 * V_902 = V_817 -> V_19 ;
char * V_88 = NULL ;
unsigned V_89 ;
int V_53 ;
V_53 = F_60 ( V_902 -> V_17 , & V_88 , & V_89 ) ;
if ( ! V_53 )
V_53 = V_89 ;
* V_904 = V_88 ;
return V_53 ;
}
static T_1 int F_421 ( void )
{
if ( ! F_422 ( & V_905 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_50 ( V_906 L_58 ) ;
return 0 ;
}
F_50 ( V_906 L_59 ) ;
F_14 () ;
V_541 = ! ( V_907 & V_556 ) ;
V_25 = F_423 ( L_60 ,
sizeof( struct V_23 ) ,
0 , V_908 , NULL ) ;
F_424 () ;
if ( F_425 ( & V_905 ) )
F_16 ( L_61 ) ;
if ( F_426 ( F_9 , V_9 ) )
F_16 ( L_62 ) ;
if ( V_3 )
F_50 ( V_79 L_63 ) ;
else
F_50 ( V_79 L_64 ) ;
return 0 ;
}
static void F_427 ( struct V_47 * V_48 , void * V_909 )
{
F_76 ( V_48 , NULL ) ;
}
void F_428 ( void )
{
F_50 ( V_79 L_65 ) ;
F_50 ( V_79 L_66 ) ;
F_429 ( F_427 , NULL ) ;
}
static int T_1 F_430 ( void )
{
int V_570 ;
if ( ! V_5 )
return 0 ;
F_50 ( V_79 L_67 ) ;
V_570 = F_431 ( V_910 , F_51 ( V_910 ) ) ;
if ( V_570 )
F_16 ( L_68 , V_570 ) ;
return 0 ;
}
static void F_432 ( void )
{
F_50 ( V_79 L_69 ) ;
F_433 ( V_910 , F_51 ( V_910 ) ) ;
}
int F_434 ( void )
{
if ( V_92 ) {
return - V_91 ;
}
if ( V_911 ) {
return - V_91 ;
}
F_50 ( V_906 L_70 ) ;
V_911 = 1 ;
V_5 = 0 ;
F_435 () ;
F_436 () ;
F_432 () ;
F_437 () ;
return 0 ;
}
