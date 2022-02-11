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
V_44 = F_25 ( V_45 , V_15 ) ;
if ( ! V_44 )
return - V_27 ;
V_44 -> V_17 = V_17 ;
V_44 -> V_46 = V_17 ;
V_42 -> V_47 = V_44 ;
return 0 ;
}
static void F_38 ( struct V_42 * V_42 )
{
struct V_43 * V_44 = V_42 -> V_47 ;
V_42 -> V_47 = NULL ;
F_30 ( V_45 , V_44 ) ;
}
static int F_39 ( struct V_48 * V_49 )
{
struct V_37 * V_38 ;
V_38 = F_15 ( sizeof( struct V_37 ) , V_15 ) ;
if ( ! V_38 )
return - V_27 ;
F_26 ( & V_38 -> V_28 ) ;
F_27 ( & V_38 -> V_50 ) ;
F_40 ( & V_38 -> V_41 ) ;
V_38 -> V_49 = V_49 ;
V_38 -> V_17 = V_30 ;
V_38 -> V_51 = V_52 ;
V_38 -> V_53 = V_30 ;
V_49 -> V_40 = V_38 ;
return 0 ;
}
static void F_41 ( struct V_48 * V_49 )
{
struct V_37 * V_38 = V_49 -> V_40 ;
V_49 -> V_40 = NULL ;
F_42 ( V_38 ) ;
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
int V_54 ;
V_54 = F_46 ( V_14 -> V_17 , V_38 -> V_17 , V_55 ,
V_56 , NULL ) ;
if ( V_54 )
return V_54 ;
V_54 = F_46 ( V_14 -> V_17 , V_17 , V_55 ,
V_57 , NULL ) ;
return V_54 ;
}
static int F_47 ( T_2 V_17 ,
struct V_37 * V_38 ,
const struct V_10 * V_10 )
{
const struct V_13 * V_14 = V_10 -> V_19 ;
int V_54 ;
V_54 = F_46 ( V_14 -> V_17 , V_38 -> V_17 , V_55 ,
V_56 , NULL ) ;
if ( V_54 )
return V_54 ;
V_54 = F_46 ( V_17 , V_38 -> V_17 , V_55 ,
V_58 , NULL ) ;
return V_54 ;
}
static int F_48 ( struct V_48 * V_49 )
{
struct V_37 * V_38 = V_49 -> V_40 ;
return V_38 -> V_59 == V_60 ||
V_38 -> V_59 == V_61 ||
V_38 -> V_59 == V_62 ||
V_38 -> V_59 == V_63 ||
! strcmp ( V_49 -> V_64 -> V_65 , L_2 ) ||
! strcmp ( V_49 -> V_64 -> V_65 , L_3 ) ||
! strcmp ( V_49 -> V_64 -> V_65 , L_4 ) ||
! strcmp ( V_49 -> V_64 -> V_65 , L_5 ) ;
}
static int F_49 ( struct V_48 * V_49 )
{
struct V_37 * V_38 = V_49 -> V_40 ;
struct V_66 * V_67 = V_49 -> V_68 ;
struct V_22 * V_69 = F_50 ( V_67 ) ;
int V_54 = 0 ;
if ( V_38 -> V_59 == V_60 ) {
if ( ! V_69 -> V_70 -> V_71 ) {
F_51 ( V_72 L_6
L_7 , V_49 -> V_73 , V_49 -> V_64 -> V_65 ) ;
V_54 = - V_74 ;
goto V_75;
}
V_54 = V_69 -> V_70 -> V_71 ( V_67 , V_76 , NULL , 0 ) ;
if ( V_54 < 0 && V_54 != - V_77 ) {
if ( V_54 == - V_74 )
F_51 ( V_72 L_8
L_9 ,
V_49 -> V_73 , V_49 -> V_64 -> V_65 ) ;
else
F_51 ( V_72 L_8
L_10 , V_49 -> V_73 ,
V_49 -> V_64 -> V_65 , - V_54 ) ;
goto V_75;
}
}
if ( V_38 -> V_59 > F_52 ( V_78 ) )
F_51 ( V_79 L_11 ,
V_49 -> V_73 , V_49 -> V_64 -> V_65 ) ;
V_38 -> V_80 |= V_81 ;
if ( F_48 ( V_49 ) )
V_38 -> V_80 |= V_82 ;
V_54 = F_44 ( V_69 , V_67 ) ;
F_33 ( & V_38 -> V_41 ) ;
V_83:
if ( ! F_53 ( & V_38 -> V_50 ) ) {
struct V_23 * V_24 =
F_54 ( V_38 -> V_50 . V_84 ,
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
goto V_83;
}
F_35 ( & V_38 -> V_41 ) ;
V_75:
return V_54 ;
}
static int F_58 ( const struct V_48 * V_49 ,
struct V_85 * V_86 )
{
int V_54 = 0 , V_87 ;
struct V_37 * V_38 = V_49 -> V_40 ;
char * V_88 = NULL ;
T_2 V_89 ;
char V_90 ;
F_59 ( V_86 ) ;
if ( ! ( V_38 -> V_80 & V_81 ) )
return - V_91 ;
if ( ! V_92 )
return - V_91 ;
F_60 ( V_93 >= ( 1 << V_94 ) ) ;
V_90 = V_38 -> V_80 & V_93 ;
for ( V_87 = 0 ; V_87 < V_94 ; V_87 ++ ) {
if ( V_90 & 0x01 )
V_86 -> V_95 ++ ;
V_90 >>= 1 ;
}
if ( V_38 -> V_80 & V_82 )
V_86 -> V_95 ++ ;
V_86 -> V_96 = F_61 ( V_86 -> V_95 , sizeof( char * ) , V_97 ) ;
if ( ! V_86 -> V_96 ) {
V_54 = - V_27 ;
goto V_98;
}
V_86 -> V_99 = F_61 ( V_86 -> V_95 , sizeof( int ) , V_97 ) ;
if ( ! V_86 -> V_99 ) {
V_54 = - V_27 ;
goto V_98;
}
V_87 = 0 ;
if ( V_38 -> V_80 & V_100 ) {
V_54 = F_62 ( V_38 -> V_17 , & V_88 , & V_89 ) ;
if ( V_54 )
goto V_98;
V_86 -> V_96 [ V_87 ] = V_88 ;
V_86 -> V_99 [ V_87 ++ ] = V_100 ;
}
if ( V_38 -> V_80 & V_101 ) {
V_54 = F_62 ( V_38 -> V_53 , & V_88 , & V_89 ) ;
if ( V_54 )
goto V_98;
V_86 -> V_96 [ V_87 ] = V_88 ;
V_86 -> V_99 [ V_87 ++ ] = V_101 ;
}
if ( V_38 -> V_80 & V_102 ) {
V_54 = F_62 ( V_38 -> V_51 , & V_88 , & V_89 ) ;
if ( V_54 )
goto V_98;
V_86 -> V_96 [ V_87 ] = V_88 ;
V_86 -> V_99 [ V_87 ++ ] = V_102 ;
}
if ( V_38 -> V_80 & V_103 ) {
struct V_22 * V_67 = F_50 ( V_38 -> V_49 -> V_68 ) ;
struct V_23 * V_24 = V_67 -> V_33 ;
V_54 = F_62 ( V_24 -> V_17 , & V_88 , & V_89 ) ;
if ( V_54 )
goto V_98;
V_86 -> V_96 [ V_87 ] = V_88 ;
V_86 -> V_99 [ V_87 ++ ] = V_103 ;
}
if ( V_38 -> V_80 & V_82 ) {
V_86 -> V_96 [ V_87 ] = NULL ;
V_86 -> V_99 [ V_87 ++ ] = V_82 ;
}
F_63 ( V_87 != V_86 -> V_95 ) ;
return 0 ;
V_98:
F_64 ( V_86 ) ;
return V_54 ;
}
static int F_65 ( struct V_37 * V_38 , char V_104 ,
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
static int F_66 ( struct V_48 * V_49 ,
struct V_85 * V_86 ,
unsigned long V_108 ,
unsigned long * V_109 )
{
const struct V_10 * V_10 = F_67 () ;
int V_54 = 0 , V_87 ;
struct V_37 * V_38 = V_49 -> V_40 ;
const char * V_65 = V_49 -> V_64 -> V_65 ;
struct V_22 * V_22 = F_50 ( V_38 -> V_49 -> V_68 ) ;
struct V_23 * V_110 = V_22 -> V_33 ;
T_2 V_111 = 0 , V_112 = 0 , V_113 = 0 ;
T_2 V_114 = 0 ;
char * * V_115 = V_86 -> V_96 ;
int * V_80 = V_86 -> V_99 ;
int V_116 = V_86 -> V_95 ;
F_68 ( & V_38 -> V_28 ) ;
if ( ! V_92 ) {
if ( ! V_116 ) {
goto V_75;
}
V_54 = - V_91 ;
F_51 ( V_72 L_12
L_13 ) ;
goto V_75;
}
if ( V_108 && ! V_109 ) {
V_54 = - V_91 ;
goto V_75;
}
if ( ( V_38 -> V_80 & V_81 ) && ( V_49 -> V_64 -> V_117 & V_118 )
&& ( V_116 == 0 ) )
goto V_75;
for ( V_87 = 0 ; V_87 < V_116 ; V_87 ++ ) {
T_2 V_17 ;
if ( V_80 [ V_87 ] == V_82 )
continue;
V_54 = F_69 ( V_115 [ V_87 ] , & V_17 , V_15 ) ;
if ( V_54 ) {
F_51 ( V_72 L_14
L_15 ,
V_115 [ V_87 ] , V_49 -> V_73 , V_65 , V_54 ) ;
goto V_75;
}
switch ( V_80 [ V_87 ] ) {
case V_100 :
V_111 = V_17 ;
if ( F_65 ( V_38 , V_100 , V_38 -> V_17 ,
V_111 ) )
goto V_119;
V_38 -> V_80 |= V_100 ;
break;
case V_101 :
V_112 = V_17 ;
if ( F_65 ( V_38 , V_101 , V_38 -> V_53 ,
V_112 ) )
goto V_119;
V_38 -> V_80 |= V_101 ;
break;
case V_103 :
V_113 = V_17 ;
if ( F_65 ( V_38 , V_103 , V_110 -> V_17 ,
V_113 ) )
goto V_119;
V_38 -> V_80 |= V_103 ;
break;
case V_102 :
V_114 = V_17 ;
if ( F_65 ( V_38 , V_102 , V_38 -> V_51 ,
V_114 ) )
goto V_119;
V_38 -> V_80 |= V_102 ;
break;
default:
V_54 = - V_91 ;
goto V_75;
}
}
if ( V_38 -> V_80 & V_81 ) {
if ( ( V_38 -> V_80 & V_93 ) && ! V_116 )
goto V_119;
V_54 = 0 ;
goto V_75;
}
if ( strcmp ( V_49 -> V_64 -> V_65 , L_16 ) == 0 )
V_38 -> V_80 |= V_120 | V_121 ;
if ( ! strcmp ( V_49 -> V_64 -> V_65 , L_4 ) ||
! strcmp ( V_49 -> V_64 -> V_65 , L_2 ) ||
! strcmp ( V_49 -> V_64 -> V_65 , L_3 ) )
V_38 -> V_80 |= V_121 ;
if ( ! V_38 -> V_59 ) {
V_54 = F_70 ( V_49 ) ;
if ( V_54 ) {
F_51 ( V_72
L_17 ,
V_122 , V_49 -> V_64 -> V_65 , V_54 ) ;
goto V_75;
}
}
if ( V_111 ) {
V_54 = F_45 ( V_111 , V_38 , V_10 ) ;
if ( V_54 )
goto V_75;
V_38 -> V_17 = V_111 ;
}
if ( V_108 & V_123 && ! V_112 ) {
V_38 -> V_59 = V_63 ;
* V_109 |= V_123 ;
}
if ( V_112 ) {
if ( ! V_111 ) {
V_54 = F_45 ( V_112 , V_38 ,
V_10 ) ;
if ( V_54 )
goto V_75;
V_38 -> V_17 = V_112 ;
} else {
V_54 = F_47 ( V_112 , V_38 ,
V_10 ) ;
if ( V_54 )
goto V_75;
}
if ( ! V_113 )
V_113 = V_112 ;
V_38 -> V_53 = V_112 ;
V_38 -> V_59 = V_124 ;
}
if ( V_113 ) {
V_54 = F_47 ( V_113 , V_38 ,
V_10 ) ;
if ( V_54 )
goto V_75;
V_110 -> V_17 = V_113 ;
V_110 -> V_125 = 1 ;
}
if ( V_114 ) {
if ( V_38 -> V_59 != V_60 &&
V_38 -> V_59 != V_63 ) {
V_54 = - V_91 ;
F_51 ( V_72 L_18
L_19 ) ;
goto V_75;
}
if ( V_114 != V_38 -> V_51 ) {
V_54 = F_47 ( V_114 ,
V_38 , V_10 ) ;
if ( V_54 )
goto V_75;
}
V_38 -> V_51 = V_114 ;
}
V_54 = F_49 ( V_49 ) ;
V_75:
F_71 ( & V_38 -> V_28 ) ;
return V_54 ;
V_119:
V_54 = - V_91 ;
F_51 ( V_72 L_20
L_21 , V_49 -> V_73 , V_65 ) ;
goto V_75;
}
static int F_72 ( const struct V_48 * V_126 ,
const struct V_48 * V_127 )
{
struct V_37 * V_128 = V_126 -> V_40 ;
struct V_37 * V_129 = V_127 -> V_40 ;
char V_130 = V_128 -> V_80 & V_93 ;
char V_131 = V_129 -> V_80 & V_93 ;
if ( V_130 != V_131 )
goto V_132;
if ( ( V_130 & V_100 ) && V_128 -> V_17 != V_129 -> V_17 )
goto V_132;
if ( ( V_130 & V_101 ) && V_128 -> V_53 != V_129 -> V_53 )
goto V_132;
if ( ( V_130 & V_102 ) && V_128 -> V_51 != V_129 -> V_51 )
goto V_132;
if ( V_130 & V_103 ) {
struct V_23 * V_133 = F_50 ( V_126 -> V_68 ) -> V_33 ;
struct V_23 * V_134 = F_50 ( V_127 -> V_68 ) -> V_33 ;
if ( V_133 -> V_17 != V_134 -> V_17 )
goto V_132;
}
return 0 ;
V_132:
F_51 ( V_72 L_22
L_23
L_24 , V_127 -> V_73 , V_127 -> V_64 -> V_65 ) ;
return - V_135 ;
}
static int F_73 ( const struct V_48 * V_126 ,
struct V_48 * V_127 )
{
const struct V_37 * V_136 = V_126 -> V_40 ;
struct V_37 * V_137 = V_127 -> V_40 ;
int V_138 = ( V_136 -> V_80 & V_100 ) ;
int V_139 = ( V_136 -> V_80 & V_101 ) ;
int V_140 = ( V_136 -> V_80 & V_103 ) ;
if ( ! V_92 )
return 0 ;
F_63 ( ! ( V_136 -> V_80 & V_81 ) ) ;
if ( V_137 -> V_80 & V_81 )
return F_72 ( V_126 , V_127 ) ;
F_68 ( & V_137 -> V_28 ) ;
V_137 -> V_80 = V_136 -> V_80 ;
V_137 -> V_17 = V_136 -> V_17 ;
V_137 -> V_51 = V_136 -> V_51 ;
V_137 -> V_59 = V_136 -> V_59 ;
if ( V_139 ) {
T_2 V_17 = V_136 -> V_53 ;
if ( ! V_138 )
V_137 -> V_17 = V_17 ;
if ( ! V_140 ) {
struct V_22 * V_141 = F_50 ( V_127 -> V_68 ) ;
struct V_23 * V_142 = V_141 -> V_33 ;
V_142 -> V_17 = V_17 ;
}
V_137 -> V_53 = V_17 ;
}
if ( V_140 ) {
const struct V_22 * V_143 = F_50 ( V_126 -> V_68 ) ;
const struct V_23 * V_144 = V_143 -> V_33 ;
struct V_22 * V_141 = F_50 ( V_127 -> V_68 ) ;
struct V_23 * V_142 = V_141 -> V_33 ;
V_142 -> V_17 = V_144 -> V_17 ;
}
F_49 ( V_127 ) ;
F_71 ( & V_137 -> V_28 ) ;
return 0 ;
}
static int F_74 ( char * V_145 ,
struct V_85 * V_86 )
{
char * V_146 ;
char * V_88 = NULL , * V_147 = NULL ;
char * V_148 = NULL , * V_149 = NULL ;
int V_54 , V_95 = 0 ;
V_86 -> V_95 = 0 ;
while ( ( V_146 = F_75 ( & V_145 , L_25 ) ) != NULL ) {
int V_150 ;
T_3 args [ V_151 ] ;
if ( ! * V_146 )
continue;
V_150 = F_76 ( V_146 , V_152 , args ) ;
switch ( V_150 ) {
case V_153 :
if ( V_88 || V_147 ) {
V_54 = - V_91 ;
F_51 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_154;
}
V_88 = F_77 ( & args [ 0 ] ) ;
if ( ! V_88 ) {
V_54 = - V_27 ;
goto V_154;
}
break;
case V_155 :
if ( V_148 ) {
V_54 = - V_91 ;
F_51 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_154;
}
V_148 = F_77 ( & args [ 0 ] ) ;
if ( ! V_148 ) {
V_54 = - V_27 ;
goto V_154;
}
break;
case V_156 :
if ( V_149 ) {
V_54 = - V_91 ;
F_51 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_154;
}
V_149 = F_77 ( & args [ 0 ] ) ;
if ( ! V_149 ) {
V_54 = - V_27 ;
goto V_154;
}
break;
case V_157 :
if ( V_88 || V_147 ) {
V_54 = - V_91 ;
F_51 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_154;
}
V_147 = F_77 ( & args [ 0 ] ) ;
if ( ! V_147 ) {
V_54 = - V_27 ;
goto V_154;
}
break;
case V_158 :
break;
default:
V_54 = - V_91 ;
F_51 ( V_72 L_26 ) ;
goto V_154;
}
}
V_54 = - V_27 ;
V_86 -> V_96 = F_61 ( V_94 , sizeof( char * ) , V_97 ) ;
if ( ! V_86 -> V_96 )
goto V_154;
V_86 -> V_99 = F_61 ( V_94 , sizeof( int ) , V_97 ) ;
if ( ! V_86 -> V_99 ) {
F_42 ( V_86 -> V_96 ) ;
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
F_42 ( V_88 ) ;
F_42 ( V_147 ) ;
F_42 ( V_148 ) ;
F_42 ( V_149 ) ;
return V_54 ;
}
static int F_78 ( struct V_48 * V_49 , void * V_159 )
{
int V_54 = 0 ;
char * V_145 = V_159 ;
struct V_85 V_86 ;
F_59 ( & V_86 ) ;
if ( ! V_159 )
goto V_75;
F_63 ( V_49 -> V_64 -> V_117 & V_118 ) ;
V_54 = F_74 ( V_145 , & V_86 ) ;
if ( V_54 )
goto V_154;
V_75:
V_54 = F_66 ( V_49 , & V_86 , 0 , NULL ) ;
V_154:
F_64 ( & V_86 ) ;
return V_54 ;
}
static void F_79 ( struct V_160 * V_161 ,
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
F_80 ( V_161 , ',' ) ;
F_81 ( V_161 , V_168 ) ;
continue;
default:
F_82 () ;
return;
} ;
F_80 ( V_161 , ',' ) ;
F_81 ( V_161 , V_162 ) ;
if ( V_163 )
F_80 ( V_161 , '\"' ) ;
F_83 ( V_161 , V_86 -> V_96 [ V_87 ] , L_27 ) ;
if ( V_163 )
F_80 ( V_161 , '\"' ) ;
}
}
static int F_84 ( struct V_160 * V_161 , struct V_48 * V_49 )
{
struct V_85 V_86 ;
int V_54 ;
V_54 = F_58 ( V_49 , & V_86 ) ;
if ( V_54 ) {
if ( V_54 == - V_91 )
V_54 = 0 ;
return V_54 ;
}
F_79 ( V_161 , & V_86 ) ;
F_64 ( & V_86 ) ;
return V_54 ;
}
static inline T_4 F_85 ( T_5 V_169 )
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
static inline int F_86 ( int V_184 )
{
return ( V_184 == V_185 || V_184 == V_186 ) ;
}
static inline int F_87 ( int V_184 )
{
return ( V_184 == V_185 || V_184 == V_187 ) ;
}
static inline T_4 F_88 ( int V_188 , int type , int V_184 )
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
if ( F_86 ( V_184 ) )
return V_197 ;
else
return V_198 ;
case V_193 :
if ( F_87 ( V_184 ) )
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
default:
return V_235 ;
}
case V_236 :
return V_237 ;
case V_238 :
return V_239 ;
case V_240 :
return V_241 ;
}
return V_242 ;
}
static int F_89 ( struct V_66 * V_66 ,
T_4 V_243 ,
T_4 V_80 ,
T_2 * V_17 )
{
int V_54 ;
struct V_48 * V_49 = V_66 -> V_244 -> V_39 ;
char * V_245 , * V_246 ;
V_245 = ( char * ) F_90 ( V_15 ) ;
if ( ! V_245 )
return - V_27 ;
V_246 = F_91 ( V_66 , V_245 , V_247 ) ;
if ( F_92 ( V_246 ) )
V_54 = F_93 ( V_246 ) ;
else {
if ( V_80 & V_120 ) {
while ( V_246 [ 1 ] >= '0' && V_246 [ 1 ] <= '9' ) {
V_246 [ 1 ] = '/' ;
V_246 ++ ;
}
}
V_54 = F_94 ( V_49 -> V_64 -> V_65 , V_246 , V_243 , V_17 ) ;
}
F_95 ( ( unsigned long ) V_245 ) ;
return V_54 ;
}
static int F_44 ( struct V_22 * V_22 , struct V_66 * V_248 )
{
struct V_37 * V_38 = NULL ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 ;
struct V_66 * V_66 ;
#define F_96 255
char * V_88 = NULL ;
unsigned V_89 = 0 ;
int V_54 = 0 ;
if ( V_24 -> V_125 )
goto V_75;
F_68 ( & V_24 -> V_28 ) ;
if ( V_24 -> V_125 )
goto V_249;
V_38 = V_22 -> V_39 -> V_40 ;
if ( ! ( V_38 -> V_80 & V_81 ) ) {
F_33 ( & V_38 -> V_41 ) ;
if ( F_53 ( & V_24 -> V_29 ) )
F_97 ( & V_24 -> V_29 , & V_38 -> V_50 ) ;
F_35 ( & V_38 -> V_41 ) ;
goto V_249;
}
switch ( V_38 -> V_59 ) {
case V_63 :
break;
case V_60 :
if ( ! V_22 -> V_70 -> V_71 ) {
V_24 -> V_17 = V_38 -> V_51 ;
break;
}
if ( V_248 ) {
V_66 = F_98 ( V_248 ) ;
} else {
V_66 = F_99 ( V_22 ) ;
}
if ( ! V_66 ) {
goto V_249;
}
V_89 = F_96 ;
V_88 = F_100 ( V_89 + 1 , V_26 ) ;
if ( ! V_88 ) {
V_54 = - V_27 ;
F_101 ( V_66 ) ;
goto V_249;
}
V_88 [ V_89 ] = '\0' ;
V_54 = V_22 -> V_70 -> V_71 ( V_66 , V_76 ,
V_88 , V_89 ) ;
if ( V_54 == - V_250 ) {
F_42 ( V_88 ) ;
V_54 = V_22 -> V_70 -> V_71 ( V_66 , V_76 ,
NULL , 0 ) ;
if ( V_54 < 0 ) {
F_101 ( V_66 ) ;
goto V_249;
}
V_89 = V_54 ;
V_88 = F_100 ( V_89 + 1 , V_26 ) ;
if ( ! V_88 ) {
V_54 = - V_27 ;
F_101 ( V_66 ) ;
goto V_249;
}
V_88 [ V_89 ] = '\0' ;
V_54 = V_22 -> V_70 -> V_71 ( V_66 ,
V_76 ,
V_88 , V_89 ) ;
}
F_101 ( V_66 ) ;
if ( V_54 < 0 ) {
if ( V_54 != - V_77 ) {
F_51 ( V_72 L_28
L_29 , V_122 ,
- V_54 , V_22 -> V_39 -> V_73 , V_22 -> V_251 ) ;
F_42 ( V_88 ) ;
goto V_249;
}
V_17 = V_38 -> V_51 ;
V_54 = 0 ;
} else {
V_54 = F_102 ( V_88 , V_54 , & V_17 ,
V_38 -> V_51 ,
V_26 ) ;
if ( V_54 ) {
char * V_252 = V_22 -> V_39 -> V_73 ;
unsigned long V_253 = V_22 -> V_251 ;
if ( V_54 == - V_91 ) {
if ( F_103 () )
F_51 ( V_254 L_30
L_31
L_32 , V_253 , V_252 , V_88 ) ;
} else {
F_51 ( V_72 L_33
L_34 ,
V_122 , V_88 , - V_54 , V_252 , V_253 ) ;
}
F_42 ( V_88 ) ;
V_54 = 0 ;
break;
}
}
F_42 ( V_88 ) ;
V_24 -> V_17 = V_17 ;
break;
case V_62 :
V_24 -> V_17 = V_24 -> F_18 ;
break;
case V_61 :
V_24 -> V_17 = V_38 -> V_17 ;
V_24 -> V_31 = F_85 ( V_22 -> V_255 ) ;
V_54 = F_104 ( V_24 -> F_18 , V_38 -> V_17 ,
V_24 -> V_31 , NULL , & V_17 ) ;
if ( V_54 )
goto V_249;
V_24 -> V_17 = V_17 ;
break;
case V_124 :
V_24 -> V_17 = V_38 -> V_53 ;
break;
default:
V_24 -> V_17 = V_38 -> V_17 ;
if ( ( V_38 -> V_80 & V_121 ) && ! F_105 ( V_22 -> V_255 ) ) {
if ( V_248 )
V_66 = F_98 ( V_248 ) ;
else
V_66 = F_99 ( V_22 ) ;
if ( ! V_66 )
goto V_249;
V_24 -> V_31 = F_85 ( V_22 -> V_255 ) ;
V_54 = F_89 ( V_66 , V_24 -> V_31 ,
V_38 -> V_80 , & V_17 ) ;
F_101 ( V_66 ) ;
if ( V_54 )
goto V_249;
V_24 -> V_17 = V_17 ;
}
break;
}
V_24 -> V_125 = 1 ;
V_249:
F_71 ( & V_24 -> V_28 ) ;
V_75:
if ( V_24 -> V_31 == V_32 )
V_24 -> V_31 = F_85 ( V_22 -> V_255 ) ;
return V_54 ;
}
static inline T_2 F_106 ( int V_256 )
{
T_2 V_257 = 0 ;
switch ( V_256 ) {
case V_258 :
V_257 = V_259 ;
break;
case V_260 :
V_257 = V_261 ;
break;
case V_262 :
V_257 = V_263 ;
break;
default:
V_257 = V_264 ;
break;
}
return V_257 ;
}
static int F_107 ( const struct V_10 * V_265 ,
const struct V_10 * V_266 ,
T_2 V_267 )
{
T_2 V_268 = F_17 ( V_265 ) , V_269 = F_17 ( V_266 ) ;
return F_46 ( V_268 , V_269 , V_270 , V_267 , NULL ) ;
}
static int F_108 ( const struct V_20 * V_271 ,
const struct V_20 * V_272 ,
T_2 V_267 )
{
const struct V_13 * V_273 , * V_274 ;
T_2 V_275 , V_276 ;
F_19 () ;
V_273 = F_20 ( V_271 ) -> V_19 ; V_275 = V_273 -> V_17 ;
V_274 = F_20 ( V_272 ) -> V_19 ; V_276 = V_274 -> V_17 ;
F_21 () ;
return F_46 ( V_275 , V_276 , V_270 , V_267 , NULL ) ;
}
static int F_109 ( const struct V_20 * V_277 ,
T_2 V_267 )
{
T_2 V_17 , V_269 ;
V_17 = F_22 () ;
V_269 = F_18 ( V_277 ) ;
return F_46 ( V_17 , V_269 , V_270 , V_267 , NULL ) ;
}
static int F_110 ( const struct V_10 * V_10 ,
int V_278 , int V_279 )
{
struct V_280 V_281 ;
struct V_282 V_283 ;
T_4 V_31 ;
T_2 V_17 = F_17 ( V_10 ) ;
T_2 V_284 = F_111 ( V_278 ) ;
int V_54 ;
V_281 . type = V_285 ;
V_281 . V_286 . V_278 = V_278 ;
switch ( F_112 ( V_278 ) ) {
case 0 :
V_31 = V_287 ;
break;
case 1 :
V_31 = V_288 ;
break;
default:
F_51 ( V_79
L_35 , V_278 ) ;
F_82 () ;
return - V_91 ;
}
V_54 = F_113 ( V_17 , V_17 , V_31 , V_284 , 0 , & V_283 ) ;
if ( V_279 == V_289 ) {
int V_290 = F_114 ( V_17 , V_17 , V_31 , V_284 , & V_283 , V_54 , & V_281 , 0 ) ;
if ( V_290 )
return V_290 ;
}
return V_54 ;
}
static int F_115 ( struct V_20 * V_277 ,
T_2 V_267 )
{
T_2 V_17 = F_18 ( V_277 ) ;
return F_46 ( V_17 , V_18 ,
V_291 , V_267 , NULL ) ;
}
static int F_116 ( const struct V_10 * V_10 ,
struct V_22 * V_22 ,
T_2 V_267 ,
struct V_280 * V_292 )
{
struct V_23 * V_24 ;
T_2 V_17 ;
F_117 ( V_10 ) ;
if ( F_118 ( F_56 ( V_22 ) ) )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
return F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_267 , V_292 ) ;
}
static inline int F_119 ( const struct V_10 * V_10 ,
struct V_66 * V_66 ,
T_2 V_284 )
{
struct V_22 * V_22 = F_50 ( V_66 ) ;
struct V_280 V_281 ;
V_281 . type = V_293 ;
V_281 . V_286 . V_66 = V_66 ;
return F_116 ( V_10 , V_22 , V_284 , & V_281 ) ;
}
static inline int F_120 ( const struct V_10 * V_10 ,
const struct V_246 * V_246 ,
T_2 V_284 )
{
struct V_22 * V_22 = F_50 ( V_246 -> V_66 ) ;
struct V_280 V_281 ;
V_281 . type = V_294 ;
V_281 . V_286 . V_246 = * V_246 ;
return F_116 ( V_10 , V_22 , V_284 , & V_281 ) ;
}
static inline int F_121 ( const struct V_10 * V_10 ,
struct V_42 * V_42 ,
T_2 V_284 )
{
struct V_280 V_281 ;
V_281 . type = V_294 ;
V_281 . V_286 . V_246 = V_42 -> V_295 ;
return F_116 ( V_10 , F_122 ( V_42 ) , V_284 , & V_281 ) ;
}
static int F_123 ( const struct V_10 * V_10 ,
struct V_42 * V_42 ,
T_2 V_284 )
{
struct V_43 * V_44 = V_42 -> V_47 ;
struct V_22 * V_22 = F_122 ( V_42 ) ;
struct V_280 V_281 ;
T_2 V_17 = F_17 ( V_10 ) ;
int V_54 ;
V_281 . type = V_294 ;
V_281 . V_286 . V_246 = V_42 -> V_295 ;
if ( V_17 != V_44 -> V_17 ) {
V_54 = F_46 ( V_17 , V_44 -> V_17 ,
V_296 ,
V_297 ,
& V_281 ) ;
if ( V_54 )
goto V_75;
}
V_54 = 0 ;
if ( V_284 )
V_54 = F_116 ( V_10 , V_22 , V_284 , & V_281 ) ;
V_75:
return V_54 ;
}
static int F_124 ( const struct V_22 * V_298 ,
const struct V_299 * V_65 ,
T_4 V_243 ,
T_2 * V_300 )
{
const struct V_37 * V_38 = V_298 -> V_39 -> V_40 ;
const struct V_23 * V_301 = V_298 -> V_33 ;
const struct V_13 * V_14 = F_23 () ;
if ( ( V_38 -> V_80 & V_81 ) &&
( V_38 -> V_59 == V_124 ) ) {
* V_300 = V_38 -> V_53 ;
} else if ( ( V_38 -> V_80 & V_82 ) &&
V_14 -> V_302 ) {
* V_300 = V_14 -> V_302 ;
} else {
return F_104 ( V_14 -> V_17 , V_301 -> V_17 , V_243 ,
V_65 , V_300 ) ;
}
return 0 ;
}
static int F_125 ( struct V_22 * V_298 ,
struct V_66 * V_66 ,
T_4 V_243 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_301 ;
struct V_37 * V_38 ;
T_2 V_17 , V_303 ;
struct V_280 V_281 ;
int V_54 ;
V_301 = V_298 -> V_33 ;
V_38 = V_298 -> V_39 -> V_40 ;
V_17 = V_14 -> V_17 ;
V_281 . type = V_293 ;
V_281 . V_286 . V_66 = V_66 ;
V_54 = F_46 ( V_17 , V_301 -> V_17 , V_179 ,
V_304 | V_305 ,
& V_281 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_124 ( V_298 , & V_66 -> V_306 , V_243 ,
& V_303 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_46 ( V_17 , V_303 , V_243 , V_307 , & V_281 ) ;
if ( V_54 )
return V_54 ;
return F_46 ( V_303 , V_38 -> V_17 ,
V_55 ,
V_58 , & V_281 ) ;
}
static int F_126 ( T_2 V_308 ,
struct V_20 * V_309 )
{
T_2 V_17 = F_18 ( V_309 ) ;
return F_46 ( V_17 , V_308 , V_310 , V_311 , NULL ) ;
}
static int F_127 ( struct V_22 * V_298 ,
struct V_66 * V_66 ,
int V_312 )
{
struct V_23 * V_301 , * V_24 ;
struct V_280 V_281 ;
T_2 V_17 = F_22 () ;
T_2 V_284 ;
int V_54 ;
V_301 = V_298 -> V_33 ;
V_24 = F_50 ( V_66 ) -> V_33 ;
V_281 . type = V_293 ;
V_281 . V_286 . V_66 = V_66 ;
V_284 = V_305 ;
V_284 |= ( V_312 ? V_313 : V_304 ) ;
V_54 = F_46 ( V_17 , V_301 -> V_17 , V_179 , V_284 , & V_281 ) ;
if ( V_54 )
return V_54 ;
switch ( V_312 ) {
case V_314 :
V_284 = V_315 ;
break;
case V_316 :
V_284 = V_317 ;
break;
case V_318 :
V_284 = V_319 ;
break;
default:
F_51 ( V_72 L_36 ,
V_122 , V_312 ) ;
return 0 ;
}
V_54 = F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_284 , & V_281 ) ;
return V_54 ;
}
static inline int F_128 ( struct V_22 * V_320 ,
struct V_66 * V_321 ,
struct V_22 * V_322 ,
struct V_66 * V_323 )
{
struct V_23 * V_324 , * V_325 , * V_326 , * V_327 ;
struct V_280 V_281 ;
T_2 V_17 = F_22 () ;
T_2 V_284 ;
int V_328 , V_329 ;
int V_54 ;
V_324 = V_320 -> V_33 ;
V_326 = F_50 ( V_321 ) -> V_33 ;
V_328 = F_129 ( V_321 ) ;
V_325 = V_322 -> V_33 ;
V_281 . type = V_293 ;
V_281 . V_286 . V_66 = V_321 ;
V_54 = F_46 ( V_17 , V_324 -> V_17 , V_179 ,
V_313 | V_305 , & V_281 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_46 ( V_17 , V_326 -> V_17 ,
V_326 -> V_31 , V_330 , & V_281 ) ;
if ( V_54 )
return V_54 ;
if ( V_328 && V_322 != V_320 ) {
V_54 = F_46 ( V_17 , V_326 -> V_17 ,
V_326 -> V_31 , V_331 , & V_281 ) ;
if ( V_54 )
return V_54 ;
}
V_281 . V_286 . V_66 = V_323 ;
V_284 = V_304 | V_305 ;
if ( F_130 ( V_323 ) )
V_284 |= V_313 ;
V_54 = F_46 ( V_17 , V_325 -> V_17 , V_179 , V_284 , & V_281 ) ;
if ( V_54 )
return V_54 ;
if ( F_130 ( V_323 ) ) {
V_327 = F_50 ( V_323 ) -> V_33 ;
V_329 = F_129 ( V_323 ) ;
V_54 = F_46 ( V_17 , V_327 -> V_17 ,
V_327 -> V_31 ,
( V_329 ? V_319 : V_317 ) , & V_281 ) ;
if ( V_54 )
return V_54 ;
}
return 0 ;
}
static int F_131 ( const struct V_10 * V_10 ,
struct V_48 * V_49 ,
T_2 V_267 ,
struct V_280 * V_281 )
{
struct V_37 * V_38 ;
T_2 V_17 = F_17 ( V_10 ) ;
V_38 = V_49 -> V_40 ;
return F_46 ( V_17 , V_38 -> V_17 , V_55 , V_267 , V_281 ) ;
}
static inline T_2 F_132 ( int V_169 , int V_332 )
{
T_2 V_284 = 0 ;
if ( ! F_133 ( V_169 ) ) {
if ( V_332 & V_333 )
V_284 |= V_334 ;
if ( V_332 & V_335 )
V_284 |= V_336 ;
if ( V_332 & V_337 )
V_284 |= V_338 ;
else if ( V_332 & V_339 )
V_284 |= V_340 ;
} else {
if ( V_332 & V_333 )
V_284 |= V_305 ;
if ( V_332 & V_339 )
V_284 |= V_341 ;
if ( V_332 & V_335 )
V_284 |= V_342 ;
}
return V_284 ;
}
static inline T_2 F_134 ( struct V_42 * V_42 )
{
T_2 V_284 = 0 ;
if ( V_42 -> V_343 & V_344 )
V_284 |= V_336 ;
if ( V_42 -> V_343 & V_345 ) {
if ( V_42 -> V_346 & V_347 )
V_284 |= V_338 ;
else
V_284 |= V_340 ;
}
if ( ! V_284 ) {
V_284 = V_348 ;
}
return V_284 ;
}
static inline T_2 F_135 ( struct V_42 * V_42 )
{
T_2 V_284 = F_134 ( V_42 ) ;
if ( V_349 )
V_284 |= V_350 ;
return V_284 ;
}
static int F_136 ( struct V_20 * V_351 )
{
T_2 V_352 = F_22 () ;
T_2 V_353 = F_18 ( V_351 ) ;
return F_46 ( V_352 , V_353 , V_354 ,
V_355 , NULL ) ;
}
static int F_137 ( struct V_20 * V_356 ,
struct V_20 * V_357 )
{
T_2 V_352 = F_22 () ;
T_2 V_358 = F_18 ( V_356 ) ;
T_2 V_359 = F_18 ( V_357 ) ;
int V_54 ;
if ( V_352 != V_358 ) {
V_54 = F_46 ( V_352 , V_358 , V_354 ,
V_360 , NULL ) ;
if ( V_54 )
return V_54 ;
}
return F_46 ( V_358 , V_359 , V_354 , V_361 ,
NULL ) ;
}
static int F_138 ( struct V_20 * V_356 ,
struct V_20 * V_357 )
{
T_2 V_358 = F_18 ( V_356 ) ;
T_2 V_359 = F_18 ( V_357 ) ;
return F_46 ( V_358 , V_359 , V_354 , V_362 ,
NULL ) ;
}
static int F_139 ( struct V_20 * V_356 ,
struct V_20 * V_357 ,
struct V_42 * V_42 )
{
T_2 V_17 = F_18 ( V_357 ) ;
struct V_43 * V_44 = V_42 -> V_47 ;
struct V_22 * V_22 = F_50 ( V_42 -> V_295 . V_66 ) ;
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_280 V_281 ;
int V_54 ;
V_281 . type = V_294 ;
V_281 . V_286 . V_246 = V_42 -> V_295 ;
if ( V_17 != V_44 -> V_17 ) {
V_54 = F_46 ( V_17 , V_44 -> V_17 ,
V_296 ,
V_297 ,
& V_281 ) ;
if ( V_54 )
return V_54 ;
}
if ( F_118 ( F_56 ( V_22 ) ) )
return 0 ;
return F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , F_134 ( V_42 ) ,
& V_281 ) ;
}
static int F_140 ( struct V_20 * V_363 ,
unsigned int V_169 )
{
if ( V_169 & V_364 ) {
T_2 V_17 = F_22 () ;
T_2 V_365 = F_18 ( V_363 ) ;
return F_46 ( V_17 , V_365 , V_32 , V_336 , NULL ) ;
}
return F_109 ( V_363 , V_366 ) ;
}
static int F_141 ( struct V_20 * V_367 )
{
return F_108 ( V_367 , V_11 , V_366 ) ;
}
static int F_142 ( struct V_20 * V_266 , T_6 * V_368 ,
T_6 * V_369 , T_6 * V_370 )
{
return F_109 ( V_266 , V_371 ) ;
}
static int F_143 ( struct V_10 * V_129 , const struct V_10 * V_128 ,
const T_6 * V_368 ,
const T_6 * V_369 ,
const T_6 * V_370 )
{
return F_107 ( V_128 , V_129 , V_372 ) ;
}
static int F_144 ( const struct V_10 * V_10 , struct V_373 * V_374 ,
int V_278 , int V_279 )
{
return F_110 ( V_10 , V_278 , V_279 ) ;
}
static int F_145 ( int V_375 , int type , int V_376 , struct V_48 * V_49 )
{
const struct V_10 * V_10 = F_67 () ;
int V_54 = 0 ;
if ( ! V_49 )
return 0 ;
switch ( V_375 ) {
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
V_54 = F_131 ( V_10 , V_49 , V_382 , NULL ) ;
break;
case V_383 :
case V_384 :
case V_385 :
V_54 = F_131 ( V_10 , V_49 , V_386 , NULL ) ;
break;
default:
V_54 = 0 ;
break;
}
return V_54 ;
}
static int F_146 ( struct V_66 * V_66 )
{
const struct V_10 * V_10 = F_67 () ;
return F_119 ( V_10 , V_66 , V_387 ) ;
}
static int F_147 ( int type )
{
int V_54 ;
switch ( type ) {
case V_388 :
case V_389 :
V_54 = F_115 ( V_11 , V_390 ) ;
break;
case V_391 :
case V_392 :
case V_393 :
V_54 = F_115 ( V_11 , V_394 ) ;
break;
case V_395 :
case V_396 :
case V_397 :
case V_398 :
case V_399 :
default:
V_54 = F_115 ( V_11 , V_400 ) ;
break;
}
return V_54 ;
}
static int F_148 ( struct V_401 * V_402 , long V_403 )
{
int V_54 , V_404 = 0 ;
V_54 = F_110 ( F_67 () , V_405 ,
V_406 ) ;
if ( V_54 == 0 )
V_404 = 1 ;
return V_404 ;
}
static int F_149 ( const struct V_407 * V_408 ,
const struct V_13 * V_409 ,
const struct V_13 * V_410 )
{
int V_411 = ( V_408 -> V_412 & V_413 ) ;
int V_414 = ( V_408 -> V_42 -> V_295 . V_415 -> V_107 & V_416 ) ;
int V_54 ;
if ( ! V_411 && ! V_414 )
return 0 ;
if ( V_410 -> V_17 == V_409 -> V_17 )
return 0 ;
V_54 = F_150 ( V_409 -> V_17 , V_410 -> V_17 ) ;
if ( V_54 ) {
if ( V_411 )
return - V_417 ;
else
return - V_418 ;
}
return 0 ;
}
static int F_151 ( struct V_407 * V_408 )
{
const struct V_13 * V_409 ;
struct V_13 * V_410 ;
struct V_23 * V_24 ;
struct V_280 V_281 ;
struct V_22 * V_22 = F_122 ( V_408 -> V_42 ) ;
int V_54 ;
if ( V_408 -> V_419 )
return 0 ;
V_409 = F_23 () ;
V_410 = V_408 -> V_10 -> V_19 ;
V_24 = V_22 -> V_33 ;
V_410 -> V_17 = V_409 -> V_17 ;
V_410 -> V_16 = V_409 -> V_17 ;
V_410 -> V_302 = 0 ;
V_410 -> V_420 = 0 ;
V_410 -> V_421 = 0 ;
if ( V_409 -> V_422 ) {
V_410 -> V_17 = V_409 -> V_422 ;
V_410 -> V_422 = 0 ;
V_54 = F_149 ( V_408 , V_409 , V_410 ) ;
if ( V_54 )
return V_54 ;
} else {
V_54 = F_104 ( V_409 -> V_17 , V_24 -> V_17 ,
V_270 , NULL ,
& V_410 -> V_17 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_149 ( V_408 , V_409 , V_410 ) ;
if ( V_54 )
V_410 -> V_17 = V_409 -> V_17 ;
}
V_281 . type = V_294 ;
V_281 . V_286 . V_246 = V_408 -> V_42 -> V_295 ;
if ( V_410 -> V_17 == V_409 -> V_17 ) {
V_54 = F_46 ( V_409 -> V_17 , V_24 -> V_17 ,
V_32 , V_423 , & V_281 ) ;
if ( V_54 )
return V_54 ;
} else {
V_54 = F_46 ( V_409 -> V_17 , V_410 -> V_17 ,
V_270 , V_424 , & V_281 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_46 ( V_410 -> V_17 , V_24 -> V_17 ,
V_32 , V_425 , & V_281 ) ;
if ( V_54 )
return V_54 ;
if ( V_408 -> V_412 & V_426 ) {
V_54 = F_46 ( V_409 -> V_17 , V_410 -> V_17 ,
V_270 , V_427 ,
NULL ) ;
if ( V_54 )
return - V_417 ;
}
if ( V_408 -> V_412 &
( V_428 | V_429 ) ) {
struct V_20 * V_430 ;
struct V_13 * V_431 ;
T_2 V_432 = 0 ;
F_19 () ;
V_430 = F_152 ( V_11 ) ;
if ( F_153 ( V_430 != NULL ) ) {
V_431 = F_20 ( V_430 ) -> V_19 ;
V_432 = V_431 -> V_17 ;
}
F_21 () ;
if ( V_432 != 0 ) {
V_54 = F_46 ( V_432 , V_410 -> V_17 ,
V_270 ,
V_366 , NULL ) ;
if ( V_54 )
return - V_417 ;
}
}
V_408 -> V_433 |= V_434 ;
}
return 0 ;
}
static int F_154 ( struct V_407 * V_408 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_17 , V_16 ;
int V_435 = 0 ;
V_17 = V_14 -> V_17 ;
V_16 = V_14 -> V_16 ;
if ( V_16 != V_17 ) {
V_435 = F_46 ( V_16 , V_17 ,
V_270 ,
V_436 , NULL ) ;
}
return ! ! V_435 ;
}
static int F_155 ( const void * V_146 , struct V_42 * V_42 , unsigned V_437 )
{
return F_123 ( V_146 , V_42 , F_134 ( V_42 ) ) ? V_437 + 1 : 0 ;
}
static inline void F_156 ( const struct V_10 * V_10 ,
struct V_438 * V_439 )
{
struct V_42 * V_42 , * V_440 = NULL ;
struct V_441 * V_442 ;
int V_443 = 0 ;
unsigned V_444 ;
V_442 = F_157 () ;
if ( V_442 ) {
F_33 ( & V_445 ) ;
if ( ! F_53 ( & V_442 -> V_446 ) ) {
struct V_447 * V_448 ;
V_448 = F_158 ( & V_442 -> V_446 ,
struct V_447 , V_29 ) ;
V_42 = V_448 -> V_42 ;
if ( F_121 ( V_10 , V_42 , V_336 | V_340 ) )
V_443 = 1 ;
}
F_35 ( & V_445 ) ;
F_159 ( V_442 ) ;
}
if ( V_443 )
F_160 () ;
V_444 = F_161 ( V_439 , 0 , F_155 , V_10 ) ;
if ( ! V_444 )
return;
V_440 = F_162 ( & V_449 , V_450 , V_10 ) ;
if ( F_92 ( V_440 ) )
V_440 = NULL ;
do {
F_163 ( V_444 - 1 , V_440 , 0 ) ;
} while ( ( V_444 = F_161 ( V_439 , V_444 , F_155 , V_10 ) ) != 0 );
if ( V_440 )
F_164 ( V_440 ) ;
}
static void F_165 ( struct V_407 * V_408 )
{
struct V_13 * V_410 ;
struct V_451 * V_452 , * V_453 ;
int V_54 , V_87 ;
V_410 = V_408 -> V_10 -> V_19 ;
if ( V_410 -> V_17 == V_410 -> V_16 )
return;
F_156 ( V_408 -> V_10 , V_11 -> V_439 ) ;
V_11 -> V_454 = 0 ;
V_54 = F_46 ( V_410 -> V_16 , V_410 -> V_17 , V_270 ,
V_455 , NULL ) ;
if ( V_54 ) {
F_166 ( V_11 ) ;
for ( V_87 = 0 ; V_87 < V_456 ; V_87 ++ ) {
V_452 = V_11 -> signal -> V_452 + V_87 ;
V_453 = V_457 . signal -> V_452 + V_87 ;
V_452 -> V_458 = F_167 ( V_452 -> V_459 , V_453 -> V_458 ) ;
}
F_168 ( V_11 ) ;
F_169 ( V_11 , V_451 ( V_460 ) ) ;
}
}
static void F_170 ( struct V_407 * V_408 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_461 V_462 ;
T_2 V_16 , V_17 ;
int V_54 , V_87 ;
V_16 = V_14 -> V_16 ;
V_17 = V_14 -> V_17 ;
if ( V_17 == V_16 )
return;
V_54 = F_46 ( V_16 , V_17 , V_270 , V_463 , NULL ) ;
if ( V_54 ) {
memset ( & V_462 , 0 , sizeof V_462 ) ;
for ( V_87 = 0 ; V_87 < 3 ; V_87 ++ )
F_171 ( V_87 , & V_462 , NULL ) ;
F_172 ( & V_11 -> V_464 -> V_465 ) ;
if ( ! F_173 ( V_11 ) ) {
F_174 ( & V_11 -> V_466 ) ;
F_174 ( & V_11 -> signal -> V_467 ) ;
F_175 ( V_11 , 1 ) ;
F_176 ( & V_11 -> V_468 ) ;
F_177 () ;
}
F_178 ( & V_11 -> V_464 -> V_465 ) ;
}
F_179 ( & V_469 ) ;
F_180 ( V_11 , V_11 -> V_470 ) ;
F_181 ( & V_469 ) ;
}
static int F_182 ( struct V_48 * V_49 )
{
return F_39 ( V_49 ) ;
}
static void F_183 ( struct V_48 * V_49 )
{
F_41 ( V_49 ) ;
}
static inline int F_184 ( char * V_162 , int V_471 , char * V_472 , int V_473 )
{
if ( V_471 > V_473 )
return 0 ;
return ! memcmp ( V_162 , V_472 , V_471 ) ;
}
static inline int F_185 ( char * V_472 , int V_89 )
{
return ( F_184 ( V_164 , sizeof( V_164 ) - 1 , V_472 , V_89 ) ||
F_184 ( V_165 , sizeof( V_165 ) - 1 , V_472 , V_89 ) ||
F_184 ( V_167 , sizeof( V_167 ) - 1 , V_472 , V_89 ) ||
F_184 ( V_166 , sizeof( V_166 ) - 1 , V_472 , V_89 ) ||
F_184 ( V_168 , sizeof( V_168 ) - 1 , V_472 , V_89 ) ) ;
}
static inline void F_186 ( char * * V_357 , char * V_356 , int * V_474 , int V_89 )
{
if ( ! * V_474 ) {
* * V_357 = ',' ;
* V_357 += 1 ;
} else
* V_474 = 0 ;
memcpy ( * V_357 , V_356 , V_89 ) ;
* V_357 += V_89 ;
}
static inline void F_187 ( char * * V_357 , char * V_356 , int * V_474 ,
int V_89 )
{
int V_475 = 0 ;
if ( ! * V_474 ) {
* * V_357 = '|' ;
* V_357 += 1 ;
} else
* V_474 = 0 ;
while ( V_475 < V_89 ) {
if ( * V_356 != '"' ) {
* * V_357 = * V_356 ;
* V_357 += 1 ;
}
V_356 += 1 ;
V_475 += 1 ;
}
}
static int F_188 ( char * V_476 , char * V_477 )
{
int V_478 , V_44 , V_54 = 0 ;
char * V_479 , * V_480 , * V_481 ;
char * V_482 , * V_483 , * V_484 ;
int V_485 = 0 ;
V_480 = V_476 ;
V_482 = V_477 ;
V_484 = ( char * ) F_189 ( V_15 ) ;
if ( ! V_484 ) {
V_54 = - V_27 ;
goto V_75;
}
V_483 = V_484 ;
V_478 = V_44 = 1 ;
V_479 = V_481 = V_476 ;
do {
if ( * V_481 == '"' )
V_485 = ! V_485 ;
if ( ( * V_481 == ',' && V_485 == 0 ) ||
* V_481 == '\0' ) {
int V_89 = V_481 - V_480 ;
if ( F_185 ( V_480 , V_89 ) )
F_187 ( & V_482 , V_480 , & V_44 , V_89 ) ;
else
F_186 ( & V_484 , V_480 , & V_478 , V_89 ) ;
V_480 = V_481 + 1 ;
}
} while ( * V_481 ++ );
strcpy ( V_479 , V_483 ) ;
F_95 ( ( unsigned long ) V_483 ) ;
V_75:
return V_54 ;
}
static int F_190 ( struct V_48 * V_49 , void * V_159 )
{
int V_54 , V_87 , * V_80 ;
struct V_85 V_86 ;
char * V_486 , * * V_115 ;
struct V_37 * V_38 = V_49 -> V_40 ;
if ( ! ( V_38 -> V_80 & V_81 ) )
return 0 ;
if ( ! V_159 )
return 0 ;
if ( V_49 -> V_64 -> V_117 & V_118 )
return 0 ;
F_59 ( & V_86 ) ;
V_486 = F_191 () ;
if ( ! V_486 )
return - V_27 ;
V_54 = F_188 ( V_159 , V_486 ) ;
if ( V_54 )
goto V_487;
V_54 = F_74 ( V_486 , & V_86 ) ;
if ( V_54 )
goto V_487;
V_115 = V_86 . V_96 ;
V_80 = V_86 . V_99 ;
for ( V_87 = 0 ; V_87 < V_86 . V_95 ; V_87 ++ ) {
T_2 V_17 ;
if ( V_80 [ V_87 ] == V_82 )
continue;
V_54 = F_69 ( V_115 [ V_87 ] , & V_17 , V_15 ) ;
if ( V_54 ) {
F_51 ( V_72 L_14
L_15 ,
V_115 [ V_87 ] , V_49 -> V_73 , V_49 -> V_64 -> V_65 , V_54 ) ;
goto V_488;
}
V_54 = - V_91 ;
switch ( V_80 [ V_87 ] ) {
case V_100 :
if ( F_65 ( V_38 , V_100 , V_38 -> V_17 , V_17 ) )
goto V_489;
break;
case V_101 :
if ( F_65 ( V_38 , V_101 , V_38 -> V_53 , V_17 ) )
goto V_489;
break;
case V_103 : {
struct V_23 * V_110 ;
V_110 = F_50 ( V_49 -> V_68 ) -> V_33 ;
if ( F_65 ( V_38 , V_103 , V_110 -> V_17 , V_17 ) )
goto V_489;
break;
}
case V_102 :
if ( F_65 ( V_38 , V_102 , V_38 -> V_51 , V_17 ) )
goto V_489;
break;
default:
goto V_488;
}
}
V_54 = 0 ;
V_488:
F_64 ( & V_86 ) ;
V_487:
F_192 ( V_486 ) ;
return V_54 ;
V_489:
F_51 ( V_72 L_37
L_38 , V_49 -> V_73 ,
V_49 -> V_64 -> V_65 ) ;
goto V_488;
}
static int F_193 ( struct V_48 * V_49 , int V_80 , void * V_159 )
{
const struct V_10 * V_10 = F_67 () ;
struct V_280 V_281 ;
int V_54 ;
V_54 = F_78 ( V_49 , V_159 ) ;
if ( V_54 )
return V_54 ;
if ( V_80 & V_490 )
return 0 ;
V_281 . type = V_293 ;
V_281 . V_286 . V_66 = V_49 -> V_68 ;
return F_131 ( V_10 , V_49 , V_491 , & V_281 ) ;
}
static int F_194 ( struct V_66 * V_66 )
{
const struct V_10 * V_10 = F_67 () ;
struct V_280 V_281 ;
V_281 . type = V_293 ;
V_281 . V_286 . V_66 = V_66 -> V_492 -> V_68 ;
return F_131 ( V_10 , V_66 -> V_492 , V_493 , & V_281 ) ;
}
static int F_195 ( const char * V_494 ,
struct V_246 * V_246 ,
const char * type ,
unsigned long V_80 ,
void * V_159 )
{
const struct V_10 * V_10 = F_67 () ;
if ( V_80 & V_495 )
return F_131 ( V_10 , V_246 -> V_66 -> V_492 ,
V_496 , NULL ) ;
else
return F_120 ( V_10 , V_246 , V_497 ) ;
}
static int F_196 ( struct V_498 * V_415 , int V_80 )
{
const struct V_10 * V_10 = F_67 () ;
return F_131 ( V_10 , V_415 -> V_499 ,
V_500 , NULL ) ;
}
static int F_197 ( struct V_22 * V_22 )
{
return F_24 ( V_22 ) ;
}
static void F_198 ( struct V_22 * V_22 )
{
F_31 ( V_22 ) ;
}
static int F_199 ( struct V_66 * V_66 , int V_169 ,
struct V_299 * V_65 , void * * V_309 ,
T_2 * V_501 )
{
T_2 V_303 ;
int V_54 ;
V_54 = F_124 ( V_244 ( V_66 -> V_502 ) , V_65 ,
F_85 ( V_169 ) ,
& V_303 ) ;
if ( V_54 )
return V_54 ;
return F_62 ( V_303 , ( char * * ) V_309 , V_501 ) ;
}
static int F_200 ( struct V_22 * V_22 , struct V_22 * V_298 ,
const struct V_299 * V_299 ,
const char * * V_65 ,
void * * V_503 , T_7 * V_89 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_301 ;
struct V_37 * V_38 ;
T_2 V_17 , V_303 , V_504 ;
int V_54 ;
char * V_88 ;
V_301 = V_298 -> V_33 ;
V_38 = V_298 -> V_39 -> V_40 ;
V_17 = V_14 -> V_17 ;
V_303 = V_14 -> V_302 ;
V_54 = F_124 (
V_298 , V_299 ,
F_85 ( V_22 -> V_255 ) ,
& V_303 ) ;
if ( V_54 )
return V_54 ;
if ( V_38 -> V_80 & V_81 ) {
struct V_23 * V_24 = V_22 -> V_33 ;
V_24 -> V_31 = F_85 ( V_22 -> V_255 ) ;
V_24 -> V_17 = V_303 ;
V_24 -> V_125 = 1 ;
}
if ( ! V_92 || ! ( V_38 -> V_80 & V_82 ) )
return - V_74 ;
if ( V_65 )
* V_65 = V_505 ;
if ( V_503 && V_89 ) {
V_54 = F_201 ( V_303 , & V_88 , & V_504 ) ;
if ( V_54 )
return V_54 ;
* V_503 = V_88 ;
* V_89 = V_504 ;
}
return 0 ;
}
static int F_202 ( struct V_22 * V_298 , struct V_66 * V_66 , T_5 V_169 )
{
return F_125 ( V_298 , V_66 , V_32 ) ;
}
static int F_203 ( struct V_66 * V_321 , struct V_22 * V_298 , struct V_66 * V_323 )
{
return F_127 ( V_298 , V_321 , V_314 ) ;
}
static int F_204 ( struct V_22 * V_298 , struct V_66 * V_66 )
{
return F_127 ( V_298 , V_66 , V_316 ) ;
}
static int F_205 ( struct V_22 * V_298 , struct V_66 * V_66 , const char * V_65 )
{
return F_125 ( V_298 , V_66 , V_174 ) ;
}
static int F_206 ( struct V_22 * V_298 , struct V_66 * V_66 , T_5 V_332 )
{
return F_125 ( V_298 , V_66 , V_179 ) ;
}
static int F_207 ( struct V_22 * V_298 , struct V_66 * V_66 )
{
return F_127 ( V_298 , V_66 , V_318 ) ;
}
static int F_208 ( struct V_22 * V_298 , struct V_66 * V_66 , T_5 V_169 , T_8 V_252 )
{
return F_125 ( V_298 , V_66 , F_85 ( V_169 ) ) ;
}
static int F_209 ( struct V_22 * V_506 , struct V_66 * V_321 ,
struct V_22 * V_507 , struct V_66 * V_323 )
{
return F_128 ( V_506 , V_321 , V_507 , V_323 ) ;
}
static int F_210 ( struct V_66 * V_66 )
{
const struct V_10 * V_10 = F_67 () ;
return F_119 ( V_10 , V_66 , V_336 ) ;
}
static int F_211 ( struct V_66 * V_66 , struct V_22 * V_22 ,
bool V_36 )
{
const struct V_10 * V_10 = F_67 () ;
struct V_280 V_281 ;
struct V_23 * V_24 ;
T_2 V_17 ;
F_117 ( V_10 ) ;
V_281 . type = V_293 ;
V_281 . V_286 . V_66 = V_66 ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
return F_212 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_336 , & V_281 ,
V_36 ? V_508 : 0 ) ;
}
static T_9 int F_213 ( struct V_22 * V_22 ,
T_2 V_267 , T_2 V_509 , T_2 V_510 ,
int V_511 ,
unsigned V_80 )
{
struct V_280 V_281 ;
struct V_23 * V_24 = V_22 -> V_33 ;
int V_54 ;
V_281 . type = V_512 ;
V_281 . V_286 . V_22 = V_22 ;
V_54 = F_214 ( F_22 () , V_24 -> V_17 , V_24 -> V_31 , V_267 ,
V_509 , V_510 , V_511 , & V_281 , V_80 ) ;
if ( V_54 )
return V_54 ;
return 0 ;
}
static int F_215 ( struct V_22 * V_22 , int V_332 )
{
const struct V_10 * V_10 = F_67 () ;
T_2 V_267 ;
bool V_513 ;
unsigned V_80 = V_332 & V_508 ;
struct V_23 * V_24 ;
T_2 V_17 ;
struct V_282 V_283 ;
int V_54 , V_290 ;
T_2 V_509 , V_510 ;
V_513 = V_332 & V_514 ;
V_332 &= ( V_335 | V_339 | V_333 | V_337 ) ;
if ( ! V_332 )
return 0 ;
F_117 ( V_10 ) ;
if ( F_118 ( F_56 ( V_22 ) ) )
return 0 ;
V_267 = F_132 ( V_22 -> V_255 , V_332 ) ;
V_17 = F_17 ( V_10 ) ;
V_24 = V_22 -> V_33 ;
V_54 = F_113 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_267 , 0 , & V_283 ) ;
V_509 = F_216 ( V_267 , & V_283 , V_54 ,
V_513 ? V_515 : 0 ,
& V_510 ) ;
if ( F_153 ( ! V_509 ) )
return V_54 ;
V_290 = F_213 ( V_22 , V_267 , V_509 , V_510 , V_54 , V_80 ) ;
if ( V_290 )
return V_290 ;
return V_54 ;
}
static int F_217 ( struct V_66 * V_66 , struct V_516 * V_516 )
{
const struct V_10 * V_10 = F_67 () ;
unsigned int V_517 = V_516 -> V_517 ;
T_10 V_284 = V_340 ;
if ( V_517 & V_518 ) {
V_517 &= ~ ( V_519 | V_520 | V_521 |
V_518 ) ;
if ( ! V_517 )
return 0 ;
}
if ( V_517 & ( V_521 | V_522 | V_523 |
V_524 | V_525 | V_526 ) )
return F_119 ( V_10 , V_66 , V_527 ) ;
if ( V_349 && ( V_517 & V_528 )
&& ! ( V_517 & V_529 ) )
V_284 |= V_350 ;
return F_119 ( V_10 , V_66 , V_284 ) ;
}
static int F_218 ( const struct V_246 * V_246 )
{
return F_120 ( F_67 () , V_246 , V_530 ) ;
}
static int F_219 ( struct V_66 * V_66 , const char * V_65 )
{
const struct V_10 * V_10 = F_67 () ;
if ( ! strncmp ( V_65 , V_531 ,
sizeof V_531 - 1 ) ) {
if ( ! strcmp ( V_65 , V_532 ) ) {
if ( ! F_220 ( V_533 ) )
return - V_417 ;
} else if ( ! F_220 ( V_405 ) ) {
return - V_417 ;
}
}
return F_119 ( V_10 , V_66 , V_527 ) ;
}
static int F_221 ( struct V_66 * V_66 , const char * V_65 ,
const void * V_503 , T_7 V_534 , int V_80 )
{
struct V_22 * V_22 = F_50 ( V_66 ) ;
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_37 * V_38 ;
struct V_280 V_281 ;
T_2 V_303 , V_17 = F_22 () ;
int V_54 = 0 ;
if ( strcmp ( V_65 , V_76 ) )
return F_219 ( V_66 , V_65 ) ;
V_38 = V_22 -> V_39 -> V_40 ;
if ( ! ( V_38 -> V_80 & V_82 ) )
return - V_74 ;
if ( ! F_222 ( V_22 ) )
return - V_417 ;
V_281 . type = V_293 ;
V_281 . V_286 . V_66 = V_66 ;
V_54 = F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 ,
V_535 , & V_281 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_223 ( V_503 , V_534 , & V_303 , V_15 ) ;
if ( V_54 == - V_91 ) {
if ( ! F_220 ( V_536 ) ) {
struct V_537 * V_538 ;
T_7 V_539 ;
const char * V_1 ;
if ( V_503 ) {
V_1 = V_503 ;
if ( V_1 [ V_534 - 1 ] == '\0' )
V_539 = V_534 - 1 ;
else
V_539 = V_534 ;
} else {
V_1 = L_39 ;
V_539 = 0 ;
}
V_538 = F_224 ( V_11 -> V_540 , V_97 , V_541 ) ;
F_225 ( V_538 , L_40 ) ;
F_226 ( V_538 , V_503 , V_539 ) ;
F_227 ( V_538 ) ;
return V_54 ;
}
V_54 = F_228 ( V_503 , V_534 , & V_303 ) ;
}
if ( V_54 )
return V_54 ;
V_54 = F_46 ( V_17 , V_303 , V_24 -> V_31 ,
V_542 , & V_281 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_229 ( V_24 -> V_17 , V_303 , V_17 ,
V_24 -> V_31 ) ;
if ( V_54 )
return V_54 ;
return F_46 ( V_303 ,
V_38 -> V_17 ,
V_55 ,
V_58 ,
& V_281 ) ;
}
static void F_230 ( struct V_66 * V_66 , const char * V_65 ,
const void * V_503 , T_7 V_534 ,
int V_80 )
{
struct V_22 * V_22 = F_50 ( V_66 ) ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_303 ;
int V_54 ;
if ( strcmp ( V_65 , V_76 ) ) {
return;
}
V_54 = F_228 ( V_503 , V_534 , & V_303 ) ;
if ( V_54 ) {
F_51 ( V_79 L_41
L_42 ,
V_22 -> V_39 -> V_73 , V_22 -> V_251 , - V_54 ) ;
return;
}
V_24 -> V_31 = F_85 ( V_22 -> V_255 ) ;
V_24 -> V_17 = V_303 ;
V_24 -> V_125 = 1 ;
return;
}
static int F_231 ( struct V_66 * V_66 , const char * V_65 )
{
const struct V_10 * V_10 = F_67 () ;
return F_119 ( V_10 , V_66 , V_530 ) ;
}
static int F_232 ( struct V_66 * V_66 )
{
const struct V_10 * V_10 = F_67 () ;
return F_119 ( V_10 , V_66 , V_530 ) ;
}
static int F_233 ( struct V_66 * V_66 , const char * V_65 )
{
if ( strcmp ( V_65 , V_76 ) )
return F_219 ( V_66 , V_65 ) ;
return - V_418 ;
}
static int F_234 ( const struct V_22 * V_22 , const char * V_65 , void * * V_245 , bool V_543 )
{
T_2 V_534 ;
int error ;
char * V_88 = NULL ;
struct V_23 * V_24 = V_22 -> V_33 ;
if ( strcmp ( V_65 , V_505 ) )
return - V_74 ;
error = F_235 ( F_67 () , & V_544 , V_536 ,
V_406 ) ;
if ( ! error )
error = F_110 ( F_67 () , V_536 ,
V_406 ) ;
if ( ! error )
error = F_201 ( V_24 -> V_17 , & V_88 ,
& V_534 ) ;
else
error = F_62 ( V_24 -> V_17 , & V_88 , & V_534 ) ;
if ( error )
return error ;
error = V_534 ;
if ( V_543 ) {
* V_245 = V_88 ;
goto V_545;
}
F_42 ( V_88 ) ;
V_545:
return error ;
}
static int F_236 ( struct V_22 * V_22 , const char * V_65 ,
const void * V_503 , T_7 V_534 , int V_80 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_303 ;
int V_54 ;
if ( strcmp ( V_65 , V_505 ) )
return - V_74 ;
if ( ! V_503 || ! V_534 )
return - V_418 ;
V_54 = F_223 ( V_503 , V_534 , & V_303 , V_15 ) ;
if ( V_54 )
return V_54 ;
V_24 -> V_31 = F_85 ( V_22 -> V_255 ) ;
V_24 -> V_17 = V_303 ;
V_24 -> V_125 = 1 ;
return 0 ;
}
static int F_237 ( struct V_22 * V_22 , char * V_245 , T_7 V_546 )
{
const int V_89 = sizeof( V_76 ) ;
if ( V_245 && V_89 <= V_546 )
memcpy ( V_245 , V_76 , V_89 ) ;
return V_89 ;
}
static void F_238 ( const struct V_22 * V_22 , T_2 * V_547 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
* V_547 = V_24 -> V_17 ;
}
static int F_239 ( struct V_42 * V_42 , int V_332 )
{
const struct V_10 * V_10 = F_67 () ;
struct V_22 * V_22 = F_122 ( V_42 ) ;
if ( ( V_42 -> V_346 & V_347 ) && ( V_332 & V_339 ) )
V_332 |= V_337 ;
return F_123 ( V_10 , V_42 ,
F_132 ( V_22 -> V_255 , V_332 ) ) ;
}
static int F_240 ( struct V_42 * V_42 , int V_332 )
{
struct V_22 * V_22 = F_122 ( V_42 ) ;
struct V_43 * V_44 = V_42 -> V_47 ;
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 = F_22 () ;
if ( ! V_332 )
return 0 ;
if ( V_17 == V_44 -> V_17 && V_44 -> V_548 == V_24 -> V_17 &&
V_44 -> V_549 == F_241 () )
return 0 ;
return F_239 ( V_42 , V_332 ) ;
}
static int F_242 ( struct V_42 * V_42 )
{
return F_37 ( V_42 ) ;
}
static void F_243 ( struct V_42 * V_42 )
{
F_38 ( V_42 ) ;
}
static int F_244 ( const struct V_10 * V_10 , struct V_42 * V_42 ,
T_2 V_550 , T_4 V_551 )
{
struct V_280 V_281 ;
struct V_43 * V_44 = V_42 -> V_47 ;
struct V_22 * V_22 = F_122 ( V_42 ) ;
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_552 V_553 ;
T_2 V_554 = F_17 ( V_10 ) ;
int V_54 ;
T_11 V_555 = V_551 >> 8 ;
T_11 V_556 = V_551 & 0xff ;
V_281 . type = V_557 ;
V_281 . V_286 . V_558 = & V_553 ;
V_281 . V_286 . V_558 -> V_551 = V_551 ;
V_281 . V_286 . V_558 -> V_246 = V_42 -> V_295 ;
if ( V_554 != V_44 -> V_17 ) {
V_54 = F_46 ( V_554 , V_44 -> V_17 ,
V_296 ,
V_297 ,
& V_281 ) ;
if ( V_54 )
goto V_75;
}
if ( F_118 ( F_56 ( V_22 ) ) )
return 0 ;
V_54 = F_245 ( V_554 , V_24 -> V_17 , V_24 -> V_31 ,
V_550 , V_555 , V_556 , & V_281 ) ;
V_75:
return V_54 ;
}
static int F_246 ( struct V_42 * V_42 , unsigned int V_551 ,
unsigned long V_559 )
{
const struct V_10 * V_10 = F_67 () ;
int error = 0 ;
switch ( V_551 ) {
case V_560 :
case V_561 :
case V_562 :
case V_563 :
case V_564 :
error = F_123 ( V_10 , V_42 , V_530 ) ;
break;
case V_565 :
case V_566 :
error = F_123 ( V_10 , V_42 , V_527 ) ;
break;
case V_567 :
case V_568 :
error = F_123 ( V_10 , V_42 , 0 ) ;
break;
case V_569 :
case V_570 :
error = F_110 ( V_10 , V_571 ,
V_289 ) ;
break;
default:
error = F_244 ( V_10 , V_42 , V_348 , ( T_4 ) V_551 ) ;
}
return error ;
}
static int F_247 ( struct V_42 * V_42 , unsigned long V_572 , int V_573 )
{
const struct V_10 * V_10 = F_67 () ;
int V_54 = 0 ;
if ( V_574 &&
( V_572 & V_575 ) && ( ! V_42 || F_56 ( F_122 ( V_42 ) ) ||
( ! V_573 && ( V_572 & V_576 ) ) ) ) {
V_54 = F_107 ( V_10 , V_10 , V_577 ) ;
if ( V_54 )
goto error;
}
if ( V_42 ) {
T_2 V_284 = V_336 ;
if ( V_573 && ( V_572 & V_576 ) )
V_284 |= V_340 ;
if ( V_572 & V_575 )
V_284 |= V_334 ;
return F_123 ( V_10 , V_42 , V_284 ) ;
}
error:
return V_54 ;
}
static int F_248 ( unsigned long V_578 )
{
int V_54 = 0 ;
if ( V_578 < V_579 ) {
T_2 V_17 = F_22 () ;
V_54 = F_46 ( V_17 , V_17 , V_580 ,
V_581 , NULL ) ;
}
return V_54 ;
}
static int F_249 ( struct V_42 * V_42 , unsigned long V_582 ,
unsigned long V_572 , unsigned long V_80 )
{
if ( V_583 )
V_572 = V_582 ;
return F_247 ( V_42 , V_572 ,
( V_80 & V_584 ) == V_585 ) ;
}
static int F_250 ( struct V_586 * V_587 ,
unsigned long V_582 ,
unsigned long V_572 )
{
const struct V_10 * V_10 = F_67 () ;
if ( V_583 )
V_572 = V_582 ;
if ( V_574 &&
( V_572 & V_575 ) && ! ( V_587 -> V_588 & V_589 ) ) {
int V_54 = 0 ;
if ( V_587 -> V_590 >= V_587 -> V_591 -> V_592 &&
V_587 -> V_593 <= V_587 -> V_591 -> V_594 ) {
V_54 = F_107 ( V_10 , V_10 , V_595 ) ;
} else if ( ! V_587 -> V_596 &&
V_587 -> V_590 <= V_587 -> V_591 -> V_597 &&
V_587 -> V_593 >= V_587 -> V_591 -> V_597 ) {
V_54 = F_109 ( V_11 , V_598 ) ;
} else if ( V_587 -> V_596 && V_587 -> V_599 ) {
V_54 = F_123 ( V_10 , V_587 -> V_596 , V_600 ) ;
}
if ( V_54 )
return V_54 ;
}
return F_247 ( V_587 -> V_596 , V_572 , V_587 -> V_588 & V_601 ) ;
}
static int F_251 ( struct V_42 * V_42 , unsigned int V_551 )
{
const struct V_10 * V_10 = F_67 () ;
return F_123 ( V_10 , V_42 , V_602 ) ;
}
static int F_252 ( struct V_42 * V_42 , unsigned int V_551 ,
unsigned long V_559 )
{
const struct V_10 * V_10 = F_67 () ;
int V_603 = 0 ;
switch ( V_551 ) {
case V_604 :
if ( ( V_42 -> V_346 & V_347 ) && ! ( V_559 & V_347 ) ) {
V_603 = F_123 ( V_10 , V_42 , V_340 ) ;
break;
}
case V_605 :
case V_606 :
case V_607 :
case V_608 :
case V_609 :
case V_610 :
V_603 = F_123 ( V_10 , V_42 , 0 ) ;
break;
case V_611 :
case V_612 :
case V_613 :
case V_614 :
case V_615 :
case V_616 :
#if V_617 == 32
case V_618 :
case V_619 :
case V_620 :
#endif
V_603 = F_123 ( V_10 , V_42 , V_602 ) ;
break;
}
return V_603 ;
}
static void F_253 ( struct V_42 * V_42 )
{
struct V_43 * V_44 ;
V_44 = V_42 -> V_47 ;
V_44 -> V_46 = F_22 () ;
}
static int F_254 ( struct V_20 * V_277 ,
struct V_621 * V_622 , int V_623 )
{
struct V_42 * V_42 ;
T_2 V_17 = F_18 ( V_277 ) ;
T_2 V_257 ;
struct V_43 * V_44 ;
V_42 = F_29 ( V_622 , struct V_42 , V_624 ) ;
V_44 = V_42 -> V_47 ;
if ( ! V_623 )
V_257 = F_106 ( V_625 ) ;
else
V_257 = F_106 ( V_623 ) ;
return F_46 ( V_44 -> V_46 , V_17 ,
V_270 , V_257 , NULL ) ;
}
static int F_255 ( struct V_42 * V_42 )
{
const struct V_10 * V_10 = F_67 () ;
return F_123 ( V_10 , V_42 , F_134 ( V_42 ) ) ;
}
static int F_256 ( struct V_42 * V_42 , const struct V_10 * V_10 )
{
struct V_43 * V_44 ;
struct V_23 * V_24 ;
V_44 = V_42 -> V_47 ;
V_24 = F_122 ( V_42 ) -> V_33 ;
V_44 -> V_548 = V_24 -> V_17 ;
V_44 -> V_549 = F_241 () ;
return F_121 ( V_10 , V_42 , F_135 ( V_42 ) ) ;
}
static int F_257 ( unsigned long V_626 )
{
return F_109 ( V_11 , V_627 ) ;
}
static int F_258 ( struct V_10 * V_10 , T_12 V_628 )
{
struct V_13 * V_14 ;
V_14 = F_15 ( sizeof( struct V_13 ) , V_628 ) ;
if ( ! V_14 )
return - V_27 ;
V_10 -> V_19 = V_14 ;
return 0 ;
}
static void F_259 ( struct V_10 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_19 ;
F_63 ( V_10 -> V_19 && ( unsigned long ) V_10 -> V_19 < V_247 ) ;
V_10 -> V_19 = ( void * ) 0x7UL ;
F_42 ( V_14 ) ;
}
static int F_260 ( struct V_10 * V_129 , const struct V_10 * V_128 ,
T_12 V_628 )
{
const struct V_13 * V_409 ;
struct V_13 * V_14 ;
V_409 = V_128 -> V_19 ;
V_14 = F_261 ( V_409 , sizeof( struct V_13 ) , V_628 ) ;
if ( ! V_14 )
return - V_27 ;
V_129 -> V_19 = V_14 ;
return 0 ;
}
static void F_262 ( struct V_10 * V_129 , const struct V_10 * V_128 )
{
const struct V_13 * V_409 = V_128 -> V_19 ;
struct V_13 * V_14 = V_129 -> V_19 ;
* V_14 = * V_409 ;
}
static int F_263 ( struct V_10 * V_129 , T_2 V_547 )
{
struct V_13 * V_14 = V_129 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_629 ;
V_629 = F_46 ( V_17 , V_547 ,
V_630 ,
V_631 ,
NULL ) ;
if ( V_629 == 0 ) {
V_14 -> V_17 = V_547 ;
V_14 -> V_302 = 0 ;
V_14 -> V_420 = 0 ;
V_14 -> V_421 = 0 ;
}
return V_629 ;
}
static int F_264 ( struct V_10 * V_129 , struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
struct V_13 * V_14 = V_129 -> V_19 ;
T_2 V_17 = F_22 () ;
int V_629 ;
V_629 = F_46 ( V_17 , V_24 -> V_17 ,
V_630 ,
V_632 ,
NULL ) ;
if ( V_629 == 0 )
V_14 -> V_302 = V_24 -> V_17 ;
return V_629 ;
}
static int F_265 ( char * V_633 )
{
T_2 V_17 ;
struct V_280 V_281 ;
V_17 = F_18 ( V_11 ) ;
V_281 . type = V_634 ;
V_281 . V_286 . V_633 = V_633 ;
return F_46 ( V_17 , V_18 , V_291 ,
V_635 , & V_281 ) ;
}
static int F_266 ( struct V_20 * V_146 , T_13 V_636 )
{
return F_109 ( V_146 , V_637 ) ;
}
static int F_267 ( struct V_20 * V_146 )
{
return F_109 ( V_146 , V_638 ) ;
}
static int F_268 ( struct V_20 * V_146 )
{
return F_109 ( V_146 , V_639 ) ;
}
static void F_269 ( struct V_20 * V_146 , T_2 * V_547 )
{
* V_547 = F_18 ( V_146 ) ;
}
static int F_270 ( struct V_20 * V_146 , int V_640 )
{
return F_109 ( V_146 , V_641 ) ;
}
static int F_271 ( struct V_20 * V_146 , int V_642 )
{
return F_109 ( V_146 , V_641 ) ;
}
static int F_272 ( struct V_20 * V_146 )
{
return F_109 ( V_146 , V_643 ) ;
}
static int F_273 ( struct V_20 * V_146 , unsigned int V_644 ,
struct V_451 * V_645 )
{
struct V_451 * V_646 = V_146 -> signal -> V_452 + V_644 ;
if ( V_646 -> V_459 != V_645 -> V_459 )
return F_109 ( V_146 , V_647 ) ;
return 0 ;
}
static int F_274 ( struct V_20 * V_146 )
{
return F_109 ( V_146 , V_641 ) ;
}
static int F_275 ( struct V_20 * V_146 )
{
return F_109 ( V_146 , V_643 ) ;
}
static int F_276 ( struct V_20 * V_146 )
{
return F_109 ( V_146 , V_641 ) ;
}
static int F_277 ( struct V_20 * V_146 , struct V_648 * V_649 ,
int V_256 , T_2 V_547 )
{
T_2 V_257 ;
int V_54 ;
if ( ! V_256 )
V_257 = V_650 ;
else
V_257 = F_106 ( V_256 ) ;
if ( V_547 )
V_54 = F_46 ( V_547 , F_18 ( V_146 ) ,
V_270 , V_257 , NULL ) ;
else
V_54 = F_109 ( V_146 , V_257 ) ;
return V_54 ;
}
static int F_278 ( struct V_20 * V_146 )
{
return F_108 ( V_146 , V_11 , V_259 ) ;
}
static void F_279 ( struct V_20 * V_146 ,
struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_33 ;
T_2 V_17 = F_18 ( V_146 ) ;
V_24 -> V_17 = V_17 ;
V_24 -> V_125 = 1 ;
}
static int F_280 ( struct V_651 * V_652 ,
struct V_280 * V_281 , T_11 * V_653 )
{
int V_654 , V_655 , V_629 = - V_91 ;
struct V_656 V_657 , * V_658 ;
V_654 = F_281 ( V_652 ) ;
V_658 = F_282 ( V_652 , V_654 , sizeof( V_657 ) , & V_657 ) ;
if ( V_658 == NULL )
goto V_75;
V_655 = V_658 -> V_659 * 4 ;
if ( V_655 < sizeof( V_657 ) )
goto V_75;
V_281 -> V_286 . V_660 -> V_661 . V_662 = V_658 -> V_662 ;
V_281 -> V_286 . V_660 -> V_661 . V_663 = V_658 -> V_663 ;
V_629 = 0 ;
if ( V_653 )
* V_653 = V_658 -> V_184 ;
switch ( V_658 -> V_184 ) {
case V_186 : {
struct V_664 V_665 , * V_666 ;
if ( F_283 ( V_658 -> V_667 ) & V_668 )
break;
V_654 += V_655 ;
V_666 = F_282 ( V_652 , V_654 , sizeof( V_665 ) , & V_665 ) ;
if ( V_666 == NULL )
break;
V_281 -> V_286 . V_660 -> V_669 = V_666 -> V_670 ;
V_281 -> V_286 . V_660 -> V_671 = V_666 -> V_672 ;
break;
}
case V_187 : {
struct V_673 V_674 , * V_675 ;
if ( F_283 ( V_658 -> V_667 ) & V_668 )
break;
V_654 += V_655 ;
V_675 = F_282 ( V_652 , V_654 , sizeof( V_674 ) , & V_674 ) ;
if ( V_675 == NULL )
break;
V_281 -> V_286 . V_660 -> V_669 = V_675 -> V_670 ;
V_281 -> V_286 . V_660 -> V_671 = V_675 -> V_672 ;
break;
}
case V_676 : {
struct V_677 V_678 , * V_679 ;
if ( F_283 ( V_658 -> V_667 ) & V_668 )
break;
V_654 += V_655 ;
V_679 = F_282 ( V_652 , V_654 , sizeof( V_678 ) , & V_678 ) ;
if ( V_679 == NULL )
break;
V_281 -> V_286 . V_660 -> V_669 = V_679 -> V_680 ;
V_281 -> V_286 . V_660 -> V_671 = V_679 -> V_681 ;
break;
}
default:
break;
}
V_75:
return V_629 ;
}
static int F_284 ( struct V_651 * V_652 ,
struct V_280 * V_281 , T_11 * V_653 )
{
T_11 V_682 ;
int V_629 = - V_91 , V_654 ;
struct V_683 V_684 , * V_685 ;
T_14 V_667 ;
V_654 = F_281 ( V_652 ) ;
V_685 = F_282 ( V_652 , V_654 , sizeof( V_684 ) , & V_684 ) ;
if ( V_685 == NULL )
goto V_75;
V_281 -> V_286 . V_660 -> V_686 . V_662 = V_685 -> V_662 ;
V_281 -> V_286 . V_660 -> V_686 . V_663 = V_685 -> V_663 ;
V_629 = 0 ;
V_682 = V_685 -> V_682 ;
V_654 += sizeof( V_684 ) ;
V_654 = F_285 ( V_652 , V_654 , & V_682 , & V_667 ) ;
if ( V_654 < 0 )
goto V_75;
if ( V_653 )
* V_653 = V_682 ;
switch ( V_682 ) {
case V_186 : {
struct V_664 V_665 , * V_666 ;
V_666 = F_282 ( V_652 , V_654 , sizeof( V_665 ) , & V_665 ) ;
if ( V_666 == NULL )
break;
V_281 -> V_286 . V_660 -> V_669 = V_666 -> V_670 ;
V_281 -> V_286 . V_660 -> V_671 = V_666 -> V_672 ;
break;
}
case V_187 : {
struct V_673 V_674 , * V_675 ;
V_675 = F_282 ( V_652 , V_654 , sizeof( V_674 ) , & V_674 ) ;
if ( V_675 == NULL )
break;
V_281 -> V_286 . V_660 -> V_669 = V_675 -> V_670 ;
V_281 -> V_286 . V_660 -> V_671 = V_675 -> V_672 ;
break;
}
case V_676 : {
struct V_677 V_678 , * V_679 ;
V_679 = F_282 ( V_652 , V_654 , sizeof( V_678 ) , & V_678 ) ;
if ( V_679 == NULL )
break;
V_281 -> V_286 . V_660 -> V_669 = V_679 -> V_680 ;
V_281 -> V_286 . V_660 -> V_671 = V_679 -> V_681 ;
break;
}
default:
break;
}
V_75:
return V_629 ;
}
static int F_286 ( struct V_651 * V_652 , struct V_280 * V_281 ,
char * * V_687 , int V_688 , T_11 * V_653 )
{
char * V_689 ;
int V_629 ;
switch ( V_281 -> V_286 . V_660 -> V_188 ) {
case V_195 :
V_629 = F_280 ( V_652 , V_281 , V_653 ) ;
if ( V_629 )
goto V_690;
V_689 = ( char * ) ( V_688 ? & V_281 -> V_286 . V_660 -> V_661 . V_662 :
& V_281 -> V_286 . V_660 -> V_661 . V_663 ) ;
goto V_691;
#if F_287 ( V_692 ) || F_287 ( V_693 )
case V_196 :
V_629 = F_284 ( V_652 , V_281 , V_653 ) ;
if ( V_629 )
goto V_690;
V_689 = ( char * ) ( V_688 ? & V_281 -> V_286 . V_660 -> V_686 . V_662 :
& V_281 -> V_286 . V_660 -> V_686 . V_663 ) ;
goto V_691;
#endif
default:
V_689 = NULL ;
goto V_691;
}
V_690:
F_51 ( V_72
L_43
L_44 ) ;
return V_629 ;
V_691:
if ( V_687 )
* V_687 = V_689 ;
return 0 ;
}
static int F_288 ( struct V_651 * V_652 , T_4 V_188 , T_2 * V_17 )
{
int V_603 ;
T_2 V_694 ;
T_2 V_695 ;
T_2 V_696 ;
V_603 = F_289 ( V_652 , & V_694 ) ;
if ( F_118 ( V_603 ) )
return - V_418 ;
V_603 = F_290 ( V_652 , V_188 , & V_696 , & V_695 ) ;
if ( F_118 ( V_603 ) )
return - V_418 ;
V_603 = F_291 ( V_695 , V_696 , V_694 , V_17 ) ;
if ( F_118 ( V_603 ) ) {
F_51 ( V_72
L_45
L_46 ) ;
return - V_418 ;
}
return 0 ;
}
static int F_292 ( T_2 V_697 , T_2 V_698 , T_2 * V_699 )
{
int V_603 = 0 ;
if ( V_698 != V_700 )
V_603 = F_293 ( V_697 , V_698 , V_699 ) ;
else
* V_699 = V_697 ;
return V_603 ;
}
static int F_294 ( const struct V_13 * V_14 ,
T_4 V_701 , T_2 * V_702 )
{
if ( V_14 -> V_421 > V_700 ) {
* V_702 = V_14 -> V_421 ;
return 0 ;
}
return F_104 ( V_14 -> V_17 , V_14 -> V_17 , V_701 , NULL ,
V_702 ) ;
}
static int F_295 ( struct V_20 * V_21 , struct V_703 * V_704 , T_2 V_267 )
{
struct V_705 * V_706 = V_704 -> V_707 ;
struct V_280 V_281 ;
struct V_708 V_660 = { 0 ,} ;
T_2 V_269 = F_18 ( V_21 ) ;
if ( V_706 -> V_17 == V_18 )
return 0 ;
V_281 . type = V_709 ;
V_281 . V_286 . V_660 = & V_660 ;
V_281 . V_286 . V_660 -> V_704 = V_704 ;
return F_46 ( V_269 , V_706 -> V_17 , V_706 -> V_31 , V_267 , & V_281 ) ;
}
static int F_296 ( int V_188 , int type ,
int V_184 , int V_710 )
{
const struct V_13 * V_14 = F_23 () ;
T_2 V_303 ;
T_4 V_701 ;
int V_54 ;
if ( V_710 )
return 0 ;
V_701 = F_88 ( V_188 , type , V_184 ) ;
V_54 = F_294 ( V_14 , V_701 , & V_303 ) ;
if ( V_54 )
return V_54 ;
return F_46 ( V_14 -> V_17 , V_303 , V_701 , V_711 , NULL ) ;
}
static int F_297 ( struct V_712 * V_703 , int V_188 ,
int type , int V_184 , int V_710 )
{
const struct V_13 * V_14 = F_23 () ;
struct V_23 * V_24 = F_298 ( V_703 ) -> V_33 ;
struct V_705 * V_706 ;
int V_603 = 0 ;
V_24 -> V_31 = F_88 ( V_188 , type , V_184 ) ;
if ( V_710 )
V_24 -> V_17 = V_18 ;
else {
V_603 = F_294 ( V_14 , V_24 -> V_31 , & ( V_24 -> V_17 ) ) ;
if ( V_603 )
return V_603 ;
}
V_24 -> V_125 = 1 ;
if ( V_703 -> V_704 ) {
V_706 = V_703 -> V_704 -> V_707 ;
V_706 -> V_17 = V_24 -> V_17 ;
V_706 -> V_31 = V_24 -> V_31 ;
V_603 = F_299 ( V_703 -> V_704 , V_188 ) ;
}
return V_603 ;
}
static int F_300 ( struct V_712 * V_703 , struct V_713 * V_714 , int V_715 )
{
struct V_703 * V_704 = V_703 -> V_704 ;
T_4 V_188 ;
int V_603 ;
V_603 = F_295 ( V_11 , V_704 , V_716 ) ;
if ( V_603 )
goto V_75;
V_188 = V_704 -> V_717 ;
if ( V_188 == V_195 || V_188 == V_196 ) {
char * V_689 ;
struct V_705 * V_706 = V_704 -> V_707 ;
struct V_280 V_281 ;
struct V_708 V_660 = { 0 ,} ;
struct V_718 * V_719 = NULL ;
struct V_720 * V_721 = NULL ;
unsigned short V_722 ;
T_2 V_17 , V_723 ;
if ( V_188 == V_195 ) {
V_719 = (struct V_718 * ) V_714 ;
V_722 = F_283 ( V_719 -> V_724 ) ;
V_689 = ( char * ) & V_719 -> V_725 . V_726 ;
} else {
V_721 = (struct V_720 * ) V_714 ;
V_722 = F_283 ( V_721 -> V_727 ) ;
V_689 = ( char * ) & V_721 -> V_728 . V_729 ;
}
if ( V_722 ) {
int V_730 , V_731 ;
F_301 ( F_302 ( V_704 ) , & V_730 , & V_731 ) ;
if ( V_722 < V_732 ( V_733, V_730 ) || V_722 > V_731 ) {
V_603 = F_303 ( V_704 -> V_734 ,
V_722 , & V_17 ) ;
if ( V_603 )
goto V_75;
V_281 . type = V_709 ;
V_281 . V_286 . V_660 = & V_660 ;
V_281 . V_286 . V_660 -> V_669 = F_304 ( V_722 ) ;
V_281 . V_286 . V_660 -> V_188 = V_188 ;
V_603 = F_46 ( V_706 -> V_17 , V_17 ,
V_706 -> V_31 ,
V_735 , & V_281 ) ;
if ( V_603 )
goto V_75;
}
}
switch ( V_706 -> V_31 ) {
case V_197 :
V_723 = V_736 ;
break;
case V_199 :
V_723 = V_737 ;
break;
case V_201 :
V_723 = V_738 ;
break;
default:
V_723 = V_739 ;
break;
}
V_603 = F_305 ( V_689 , V_188 , & V_17 ) ;
if ( V_603 )
goto V_75;
V_281 . type = V_709 ;
V_281 . V_286 . V_660 = & V_660 ;
V_281 . V_286 . V_660 -> V_669 = F_304 ( V_722 ) ;
V_281 . V_286 . V_660 -> V_188 = V_188 ;
if ( V_188 == V_195 )
V_281 . V_286 . V_660 -> V_661 . V_662 = V_719 -> V_725 . V_726 ;
else
V_281 . V_286 . V_660 -> V_686 . V_662 = V_721 -> V_728 ;
V_603 = F_46 ( V_706 -> V_17 , V_17 ,
V_706 -> V_31 , V_723 , & V_281 ) ;
if ( V_603 )
goto V_75;
}
V_75:
return V_603 ;
}
static int F_306 ( struct V_712 * V_703 , struct V_713 * V_714 , int V_715 )
{
struct V_703 * V_704 = V_703 -> V_704 ;
struct V_705 * V_706 = V_704 -> V_707 ;
int V_603 ;
V_603 = F_295 ( V_11 , V_704 , V_740 ) ;
if ( V_603 )
return V_603 ;
if ( V_706 -> V_31 == V_197 ||
V_706 -> V_31 == V_201 ) {
struct V_280 V_281 ;
struct V_708 V_660 = { 0 ,} ;
struct V_718 * V_719 = NULL ;
struct V_720 * V_721 = NULL ;
unsigned short V_722 ;
T_2 V_17 , V_257 ;
if ( V_704 -> V_717 == V_195 ) {
V_719 = (struct V_718 * ) V_714 ;
if ( V_715 < sizeof( struct V_718 ) )
return - V_91 ;
V_722 = F_283 ( V_719 -> V_724 ) ;
} else {
V_721 = (struct V_720 * ) V_714 ;
if ( V_715 < V_741 )
return - V_91 ;
V_722 = F_283 ( V_721 -> V_727 ) ;
}
V_603 = F_303 ( V_704 -> V_734 , V_722 , & V_17 ) ;
if ( V_603 )
goto V_75;
V_257 = ( V_706 -> V_31 == V_197 ) ?
V_742 : V_743 ;
V_281 . type = V_709 ;
V_281 . V_286 . V_660 = & V_660 ;
V_281 . V_286 . V_660 -> V_671 = F_304 ( V_722 ) ;
V_281 . V_286 . V_660 -> V_188 = V_704 -> V_717 ;
V_603 = F_46 ( V_706 -> V_17 , V_17 , V_706 -> V_31 , V_257 , & V_281 ) ;
if ( V_603 )
goto V_75;
}
V_603 = F_307 ( V_704 , V_714 ) ;
V_75:
return V_603 ;
}
static int F_308 ( struct V_712 * V_703 , int V_744 )
{
return F_295 ( V_11 , V_703 -> V_704 , V_745 ) ;
}
static int F_309 ( struct V_712 * V_703 , struct V_712 * V_746 )
{
int V_603 ;
struct V_23 * V_24 ;
struct V_23 * V_142 ;
V_603 = F_295 ( V_11 , V_703 -> V_704 , V_747 ) ;
if ( V_603 )
return V_603 ;
V_142 = F_298 ( V_746 ) -> V_33 ;
V_24 = F_298 ( V_703 ) -> V_33 ;
V_142 -> V_31 = V_24 -> V_31 ;
V_142 -> V_17 = V_24 -> V_17 ;
V_142 -> V_125 = 1 ;
return 0 ;
}
static int F_310 ( struct V_712 * V_703 , struct V_748 * V_749 ,
int V_534 )
{
return F_295 ( V_11 , V_703 -> V_704 , V_750 ) ;
}
static int F_311 ( struct V_712 * V_703 , struct V_748 * V_749 ,
int V_534 , int V_80 )
{
return F_295 ( V_11 , V_703 -> V_704 , V_751 ) ;
}
static int F_312 ( struct V_712 * V_703 )
{
return F_295 ( V_11 , V_703 -> V_704 , V_752 ) ;
}
static int F_313 ( struct V_712 * V_703 )
{
return F_295 ( V_11 , V_703 -> V_704 , V_752 ) ;
}
static int F_314 ( struct V_712 * V_703 , int V_753 , int V_754 )
{
int V_603 ;
V_603 = F_295 ( V_11 , V_703 -> V_704 , V_755 ) ;
if ( V_603 )
return V_603 ;
return F_315 ( V_703 , V_753 , V_754 ) ;
}
static int F_316 ( struct V_712 * V_703 , int V_753 ,
int V_754 )
{
return F_295 ( V_11 , V_703 -> V_704 , V_756 ) ;
}
static int F_317 ( struct V_712 * V_703 , int V_757 )
{
return F_295 ( V_11 , V_703 -> V_704 , V_758 ) ;
}
static int F_318 ( struct V_703 * V_703 ,
struct V_703 * V_759 ,
struct V_703 * V_760 )
{
struct V_705 * V_761 = V_703 -> V_707 ;
struct V_705 * V_762 = V_759 -> V_707 ;
struct V_705 * V_763 = V_760 -> V_707 ;
struct V_280 V_281 ;
struct V_708 V_660 = { 0 ,} ;
int V_603 ;
V_281 . type = V_709 ;
V_281 . V_286 . V_660 = & V_660 ;
V_281 . V_286 . V_660 -> V_704 = V_759 ;
V_603 = F_46 ( V_761 -> V_17 , V_762 -> V_17 ,
V_762 -> V_31 ,
V_764 , & V_281 ) ;
if ( V_603 )
return V_603 ;
V_763 -> V_765 = V_761 -> V_17 ;
V_603 = F_293 ( V_762 -> V_17 , V_761 -> V_17 ,
& V_763 -> V_17 ) ;
if ( V_603 )
return V_603 ;
V_761 -> V_765 = V_763 -> V_17 ;
return 0 ;
}
static int F_319 ( struct V_712 * V_703 ,
struct V_712 * V_759 )
{
struct V_705 * V_766 = V_703 -> V_704 -> V_707 ;
struct V_705 * V_767 = V_759 -> V_704 -> V_707 ;
struct V_280 V_281 ;
struct V_708 V_660 = { 0 ,} ;
V_281 . type = V_709 ;
V_281 . V_286 . V_660 = & V_660 ;
V_281 . V_286 . V_660 -> V_704 = V_759 -> V_704 ;
return F_46 ( V_766 -> V_17 , V_767 -> V_17 , V_767 -> V_31 , V_768 ,
& V_281 ) ;
}
static int F_320 ( struct V_660 * V_374 , int V_769 ,
char * V_689 , T_4 V_188 , T_2 V_765 ,
struct V_280 * V_281 )
{
int V_603 ;
T_2 V_770 ;
T_2 V_771 ;
V_603 = F_321 ( V_374 , V_769 , & V_770 ) ;
if ( V_603 )
return V_603 ;
V_603 = F_46 ( V_765 , V_770 ,
V_772 , V_773 , V_281 ) ;
if ( V_603 )
return V_603 ;
V_603 = F_305 ( V_689 , V_188 , & V_771 ) ;
if ( V_603 )
return V_603 ;
return F_46 ( V_765 , V_771 ,
V_774 , V_775 , V_281 ) ;
}
static int F_322 ( struct V_703 * V_704 , struct V_651 * V_652 ,
T_4 V_188 )
{
int V_603 = 0 ;
struct V_705 * V_706 = V_704 -> V_707 ;
T_2 V_697 = V_706 -> V_17 ;
struct V_280 V_281 ;
struct V_708 V_660 = { 0 ,} ;
char * V_689 ;
V_281 . type = V_709 ;
V_281 . V_286 . V_660 = & V_660 ;
V_281 . V_286 . V_660 -> V_776 = V_652 -> V_777 ;
V_281 . V_286 . V_660 -> V_188 = V_188 ;
V_603 = F_286 ( V_652 , & V_281 , & V_689 , 1 , NULL ) ;
if ( V_603 )
return V_603 ;
if ( F_4 () ) {
V_603 = F_46 ( V_697 , V_652 -> V_778 , V_779 ,
V_780 , & V_281 ) ;
if ( V_603 )
return V_603 ;
}
V_603 = F_323 ( V_706 , V_652 , V_188 , & V_281 ) ;
if ( V_603 )
return V_603 ;
V_603 = F_324 ( V_706 -> V_17 , V_652 , & V_281 ) ;
return V_603 ;
}
static int F_325 ( struct V_703 * V_704 , struct V_651 * V_652 )
{
int V_603 ;
struct V_705 * V_706 = V_704 -> V_707 ;
T_4 V_188 = V_704 -> V_717 ;
T_2 V_697 = V_706 -> V_17 ;
struct V_280 V_281 ;
struct V_708 V_660 = { 0 ,} ;
char * V_689 ;
T_11 V_781 ;
T_11 V_782 ;
if ( V_188 != V_195 && V_188 != V_196 )
return 0 ;
if ( V_188 == V_196 && V_652 -> V_184 == F_304 ( V_783 ) )
V_188 = V_195 ;
if ( ! V_784 )
return F_322 ( V_704 , V_652 , V_188 ) ;
V_781 = F_4 () ;
V_782 = F_6 () ;
if ( ! V_781 && ! V_782 )
return 0 ;
V_281 . type = V_709 ;
V_281 . V_286 . V_660 = & V_660 ;
V_281 . V_286 . V_660 -> V_776 = V_652 -> V_777 ;
V_281 . V_286 . V_660 -> V_188 = V_188 ;
V_603 = F_286 ( V_652 , & V_281 , & V_689 , 1 , NULL ) ;
if ( V_603 )
return V_603 ;
if ( V_782 ) {
T_2 V_765 ;
V_603 = F_288 ( V_652 , V_188 , & V_765 ) ;
if ( V_603 )
return V_603 ;
V_603 = F_320 ( F_302 ( V_704 ) , V_652 -> V_777 ,
V_689 , V_188 , V_765 , & V_281 ) ;
if ( V_603 ) {
F_326 ( V_652 , V_603 , 0 ) ;
return V_603 ;
}
V_603 = F_46 ( V_697 , V_765 , V_785 ,
V_786 , & V_281 ) ;
if ( V_603 ) {
F_326 ( V_652 , V_603 , 0 ) ;
return V_603 ;
}
}
if ( V_781 ) {
V_603 = F_46 ( V_697 , V_652 -> V_778 , V_779 ,
V_780 , & V_281 ) ;
if ( V_603 )
return V_603 ;
}
return V_603 ;
}
static int F_327 ( struct V_712 * V_703 , char T_15 * V_787 ,
int T_15 * V_788 , unsigned V_89 )
{
int V_603 = 0 ;
char * V_789 ;
T_2 V_790 ;
struct V_705 * V_706 = V_703 -> V_704 -> V_707 ;
T_2 V_765 = V_700 ;
if ( V_706 -> V_31 == V_192 ||
V_706 -> V_31 == V_197 )
V_765 = V_706 -> V_765 ;
if ( V_765 == V_700 )
return - V_791 ;
V_603 = F_62 ( V_765 , & V_789 , & V_790 ) ;
if ( V_603 )
return V_603 ;
if ( V_790 > V_89 ) {
V_603 = - V_250 ;
goto V_792;
}
if ( F_328 ( V_787 , V_789 , V_790 ) )
V_603 = - V_793 ;
V_792:
if ( F_329 ( V_790 , V_788 ) )
V_603 = - V_793 ;
F_42 ( V_789 ) ;
return V_603 ;
}
static int F_330 ( struct V_712 * V_703 , struct V_651 * V_652 , T_2 * V_547 )
{
T_2 V_794 = V_700 ;
T_4 V_188 ;
if ( V_652 && V_652 -> V_184 == F_304 ( V_783 ) )
V_188 = V_195 ;
else if ( V_652 && V_652 -> V_184 == F_304 ( V_795 ) )
V_188 = V_196 ;
else if ( V_703 )
V_188 = V_703 -> V_704 -> V_717 ;
else
goto V_75;
if ( V_703 && V_188 == V_189 )
F_238 ( F_298 ( V_703 ) , & V_794 ) ;
else if ( V_652 )
F_288 ( V_652 , V_188 , & V_794 ) ;
V_75:
* V_547 = V_794 ;
if ( V_794 == V_700 )
return - V_91 ;
return 0 ;
}
static int F_331 ( struct V_703 * V_704 , int V_188 , T_12 V_796 )
{
struct V_705 * V_706 ;
V_706 = F_15 ( sizeof( * V_706 ) , V_796 ) ;
if ( ! V_706 )
return - V_27 ;
V_706 -> V_765 = V_30 ;
V_706 -> V_17 = V_30 ;
V_706 -> V_31 = V_242 ;
F_332 ( V_706 ) ;
V_704 -> V_707 = V_706 ;
return 0 ;
}
static void F_333 ( struct V_703 * V_704 )
{
struct V_705 * V_706 = V_704 -> V_707 ;
V_704 -> V_707 = NULL ;
F_334 ( V_706 ) ;
F_42 ( V_706 ) ;
}
static void F_335 ( const struct V_703 * V_704 , struct V_703 * V_760 )
{
struct V_705 * V_706 = V_704 -> V_707 ;
struct V_705 * V_797 = V_760 -> V_707 ;
V_797 -> V_17 = V_706 -> V_17 ;
V_797 -> V_765 = V_706 -> V_765 ;
V_797 -> V_31 = V_706 -> V_31 ;
F_332 ( V_797 ) ;
}
static void F_336 ( struct V_703 * V_704 , T_2 * V_547 )
{
if ( ! V_704 )
* V_547 = V_798 ;
else {
struct V_705 * V_706 = V_704 -> V_707 ;
* V_547 = V_706 -> V_17 ;
}
}
static void F_337 ( struct V_703 * V_704 , struct V_712 * V_367 )
{
struct V_23 * V_24 = F_298 ( V_367 ) -> V_33 ;
struct V_705 * V_706 = V_704 -> V_707 ;
if ( V_704 -> V_717 == V_195 || V_704 -> V_717 == V_196 ||
V_704 -> V_717 == V_189 )
V_24 -> V_17 = V_706 -> V_17 ;
V_706 -> V_31 = V_24 -> V_31 ;
}
static int F_338 ( struct V_703 * V_704 , struct V_651 * V_652 ,
struct V_799 * V_800 )
{
struct V_705 * V_706 = V_704 -> V_707 ;
int V_603 ;
T_4 V_188 = V_800 -> V_801 -> V_188 ;
T_2 V_802 ;
T_2 V_803 ;
V_603 = F_288 ( V_652 , V_188 , & V_803 ) ;
if ( V_603 )
return V_603 ;
V_603 = F_292 ( V_706 -> V_17 , V_803 , & V_802 ) ;
if ( V_603 )
return V_603 ;
V_800 -> V_547 = V_802 ;
V_800 -> V_794 = V_803 ;
return F_339 ( V_800 , V_188 ) ;
}
static void F_340 ( struct V_703 * V_760 ,
const struct V_799 * V_800 )
{
struct V_705 * V_797 = V_760 -> V_707 ;
V_797 -> V_17 = V_800 -> V_547 ;
V_797 -> V_765 = V_800 -> V_794 ;
F_341 ( V_760 , V_800 -> V_801 -> V_188 ) ;
}
static void F_342 ( struct V_703 * V_704 , struct V_651 * V_652 )
{
T_4 V_188 = V_704 -> V_717 ;
struct V_705 * V_706 = V_704 -> V_707 ;
if ( V_188 == V_196 && V_652 -> V_184 == F_304 ( V_783 ) )
V_188 = V_195 ;
F_288 ( V_652 , V_188 , & V_706 -> V_765 ) ;
}
static int F_343 ( T_2 V_17 )
{
const struct V_13 * V_804 ;
T_2 V_269 ;
V_804 = F_23 () ;
V_269 = V_804 -> V_17 ;
return F_46 ( V_269 , V_17 , V_779 , V_805 , NULL ) ;
}
static void F_344 ( void )
{
F_345 ( & V_7 ) ;
}
static void F_346 ( void )
{
F_347 ( & V_7 ) ;
}
static void F_348 ( const struct V_799 * V_800 ,
struct V_806 * V_807 )
{
V_807 -> V_808 = V_800 -> V_547 ;
}
static int F_349 ( void * * V_19 )
{
struct V_809 * V_810 ;
V_810 = F_15 ( sizeof( * V_810 ) , V_15 ) ;
if ( ! V_810 )
return - V_27 ;
V_810 -> V_17 = F_22 () ;
* V_19 = V_810 ;
return 0 ;
}
static void F_350 ( void * V_19 )
{
F_42 ( V_19 ) ;
}
static int F_351 ( void )
{
T_2 V_17 = F_22 () ;
return F_46 ( V_17 , V_17 , V_811 , V_812 ,
NULL ) ;
}
static int F_352 ( void * V_19 )
{
struct V_809 * V_810 = V_19 ;
return F_46 ( F_22 () , V_810 -> V_17 , V_811 ,
V_813 , NULL ) ;
}
static int F_353 ( struct V_703 * V_704 , void * V_19 )
{
struct V_809 * V_810 = V_19 ;
struct V_705 * V_706 = V_704 -> V_707 ;
V_706 -> V_17 = V_810 -> V_17 ;
V_706 -> V_31 = V_811 ;
return 0 ;
}
static int F_354 ( void * V_19 )
{
struct V_809 * V_810 = V_19 ;
T_2 V_17 = F_22 () ;
int V_603 ;
V_603 = F_46 ( V_17 , V_810 -> V_17 , V_811 ,
V_814 , NULL ) ;
if ( V_603 )
return V_603 ;
V_603 = F_46 ( V_17 , V_17 , V_811 ,
V_815 , NULL ) ;
if ( V_603 )
return V_603 ;
V_810 -> V_17 = V_17 ;
return 0 ;
}
static int F_355 ( struct V_703 * V_704 , struct V_651 * V_652 )
{
int V_603 = 0 ;
T_2 V_257 ;
struct V_816 * V_817 ;
struct V_705 * V_706 = V_704 -> V_707 ;
if ( V_652 -> V_89 < V_818 ) {
V_603 = - V_91 ;
goto V_75;
}
V_817 = F_356 ( V_652 ) ;
V_603 = F_357 ( V_706 -> V_31 , V_817 -> V_819 , & V_257 ) ;
if ( V_603 ) {
if ( V_603 == - V_91 ) {
F_51 ( V_72
L_47
L_48 ,
V_704 -> V_734 , V_817 -> V_819 ,
V_820 [ V_706 -> V_31 - 1 ] . V_65 ) ;
if ( ! V_3 || F_358 () )
V_603 = 0 ;
}
if ( V_603 == - V_821 )
V_603 = 0 ;
goto V_75;
}
V_603 = F_295 ( V_11 , V_704 , V_257 ) ;
V_75:
return V_603 ;
}
static unsigned int F_359 ( struct V_651 * V_652 ,
const struct V_822 * V_823 ,
T_4 V_188 )
{
int V_603 ;
char * V_689 ;
T_2 V_765 ;
struct V_280 V_281 ;
struct V_708 V_660 = { 0 ,} ;
T_11 V_781 ;
T_11 V_824 ;
T_11 V_782 ;
if ( ! V_784 )
return V_825 ;
V_781 = F_4 () ;
V_824 = F_7 () ;
V_782 = F_6 () ;
if ( ! V_781 && ! V_782 )
return V_825 ;
if ( F_288 ( V_652 , V_188 , & V_765 ) != 0 )
return V_826 ;
V_281 . type = V_709 ;
V_281 . V_286 . V_660 = & V_660 ;
V_281 . V_286 . V_660 -> V_776 = V_823 -> V_769 ;
V_281 . V_286 . V_660 -> V_188 = V_188 ;
if ( F_286 ( V_652 , & V_281 , & V_689 , 1 , NULL ) != 0 )
return V_826 ;
if ( V_782 ) {
V_603 = F_320 ( F_360 ( V_823 ) , V_823 -> V_769 ,
V_689 , V_188 , V_765 , & V_281 ) ;
if ( V_603 ) {
F_326 ( V_652 , V_603 , 1 ) ;
return V_826 ;
}
}
if ( V_781 )
if ( F_46 ( V_765 , V_652 -> V_778 ,
V_779 , V_827 , & V_281 ) )
return V_826 ;
if ( V_824 )
if ( F_361 ( V_652 , V_188 , V_765 ) != 0 )
return V_826 ;
return V_825 ;
}
static unsigned int F_362 ( void * V_828 ,
struct V_651 * V_652 ,
const struct V_829 * V_830 )
{
return F_359 ( V_652 , V_830 -> V_831 , V_195 ) ;
}
static unsigned int F_363 ( void * V_828 ,
struct V_651 * V_652 ,
const struct V_829 * V_830 )
{
return F_359 ( V_652 , V_830 -> V_831 , V_196 ) ;
}
static unsigned int F_364 ( struct V_651 * V_652 ,
T_4 V_188 )
{
struct V_703 * V_704 ;
T_2 V_17 ;
if ( ! F_7 () )
return V_825 ;
V_704 = V_652 -> V_704 ;
if ( V_704 ) {
struct V_705 * V_706 ;
if ( F_365 ( V_704 ) )
return V_825 ;
V_706 = V_704 -> V_707 ;
V_17 = V_706 -> V_17 ;
} else
V_17 = V_18 ;
if ( F_361 ( V_652 , V_188 , V_17 ) != 0 )
return V_826 ;
return V_825 ;
}
static unsigned int F_366 ( void * V_828 ,
struct V_651 * V_652 ,
const struct V_829 * V_830 )
{
return F_364 ( V_652 , V_195 ) ;
}
static unsigned int F_367 ( struct V_651 * V_652 ,
int V_769 ,
T_4 V_188 )
{
struct V_703 * V_704 = F_368 ( V_652 ) ;
struct V_705 * V_706 ;
struct V_280 V_281 ;
struct V_708 V_660 = { 0 ,} ;
char * V_689 ;
T_11 V_653 ;
if ( V_704 == NULL )
return V_825 ;
V_706 = V_704 -> V_707 ;
V_281 . type = V_709 ;
V_281 . V_286 . V_660 = & V_660 ;
V_281 . V_286 . V_660 -> V_776 = V_769 ;
V_281 . V_286 . V_660 -> V_188 = V_188 ;
if ( F_286 ( V_652 , & V_281 , & V_689 , 0 , & V_653 ) )
return V_826 ;
if ( F_4 () )
if ( F_46 ( V_706 -> V_17 , V_652 -> V_778 ,
V_779 , V_832 , & V_281 ) )
return F_369 ( - V_833 ) ;
if ( F_370 ( V_706 -> V_17 , V_652 , & V_281 , V_653 ) )
return F_369 ( - V_833 ) ;
return V_825 ;
}
static unsigned int F_371 ( struct V_651 * V_652 ,
const struct V_822 * V_834 ,
T_4 V_188 )
{
T_2 V_835 ;
T_2 V_765 ;
int V_769 = V_834 -> V_769 ;
struct V_703 * V_704 ;
struct V_280 V_281 ;
struct V_708 V_660 = { 0 ,} ;
char * V_689 ;
T_11 V_781 ;
T_11 V_782 ;
if ( ! V_784 )
return F_367 ( V_652 , V_769 , V_188 ) ;
V_781 = F_4 () ;
V_782 = F_6 () ;
if ( ! V_781 && ! V_782 )
return V_825 ;
V_704 = F_368 ( V_652 ) ;
#ifdef F_372
if ( F_373 ( V_652 ) != NULL && F_373 ( V_652 ) -> V_836 != NULL &&
! ( V_704 && F_365 ( V_704 ) ) )
return V_825 ;
#endif
if ( V_704 == NULL ) {
if ( V_652 -> V_777 ) {
V_835 = V_837 ;
if ( F_288 ( V_652 , V_188 , & V_765 ) )
return V_826 ;
} else {
V_835 = V_832 ;
V_765 = V_18 ;
}
} else if ( F_365 ( V_704 ) ) {
T_2 V_698 ;
struct V_705 * V_706 ;
V_706 = V_704 -> V_707 ;
if ( F_288 ( V_652 , V_188 , & V_698 ) )
return V_826 ;
if ( V_698 == V_700 ) {
switch ( V_188 ) {
case V_195 :
if ( F_374 ( V_652 ) -> V_80 & V_838 )
return V_825 ;
break;
case V_196 :
if ( F_375 ( V_652 ) -> V_80 & V_839 )
return V_825 ;
break;
default:
return F_369 ( - V_833 ) ;
}
}
if ( F_292 ( V_706 -> V_17 , V_698 , & V_765 ) )
return V_826 ;
V_835 = V_832 ;
} else {
struct V_705 * V_706 = V_704 -> V_707 ;
V_765 = V_706 -> V_17 ;
V_835 = V_832 ;
}
V_281 . type = V_709 ;
V_281 . V_286 . V_660 = & V_660 ;
V_281 . V_286 . V_660 -> V_776 = V_769 ;
V_281 . V_286 . V_660 -> V_188 = V_188 ;
if ( F_286 ( V_652 , & V_281 , & V_689 , 0 , NULL ) )
return V_826 ;
if ( V_781 )
if ( F_46 ( V_765 , V_652 -> V_778 ,
V_779 , V_835 , & V_281 ) )
return F_369 ( - V_833 ) ;
if ( V_782 ) {
T_2 V_770 ;
T_2 V_771 ;
if ( F_321 ( F_360 ( V_834 ) , V_769 , & V_770 ) )
return V_826 ;
if ( F_46 ( V_765 , V_770 ,
V_772 , V_840 , & V_281 ) )
return F_369 ( - V_833 ) ;
if ( F_305 ( V_689 , V_188 , & V_771 ) )
return V_826 ;
if ( F_46 ( V_765 , V_771 ,
V_774 , V_841 , & V_281 ) )
return F_369 ( - V_833 ) ;
}
return V_825 ;
}
static unsigned int F_376 ( void * V_828 ,
struct V_651 * V_652 ,
const struct V_829 * V_830 )
{
return F_371 ( V_652 , V_830 -> V_75 , V_195 ) ;
}
static unsigned int F_377 ( void * V_828 ,
struct V_651 * V_652 ,
const struct V_829 * V_830 )
{
return F_371 ( V_652 , V_830 -> V_75 , V_196 ) ;
}
static int F_378 ( struct V_703 * V_704 , struct V_651 * V_652 )
{
return F_355 ( V_704 , V_652 ) ;
}
static int F_379 ( struct V_20 * V_21 ,
struct V_842 * V_257 ,
T_4 V_31 )
{
struct V_843 * V_24 ;
T_2 V_17 ;
V_24 = F_15 ( sizeof( struct V_843 ) , V_15 ) ;
if ( ! V_24 )
return - V_27 ;
V_17 = F_18 ( V_21 ) ;
V_24 -> V_31 = V_31 ;
V_24 -> V_17 = V_17 ;
V_257 -> V_19 = V_24 ;
return 0 ;
}
static void F_380 ( struct V_842 * V_257 )
{
struct V_843 * V_24 = V_257 -> V_19 ;
V_257 -> V_19 = NULL ;
F_42 ( V_24 ) ;
}
static int F_381 ( struct V_844 * V_749 )
{
struct V_845 * V_846 ;
V_846 = F_15 ( sizeof( struct V_845 ) , V_15 ) ;
if ( ! V_846 )
return - V_27 ;
V_846 -> V_17 = V_30 ;
V_749 -> V_19 = V_846 ;
return 0 ;
}
static void F_382 ( struct V_844 * V_749 )
{
struct V_845 * V_846 = V_749 -> V_19 ;
V_749 -> V_19 = NULL ;
F_42 ( V_846 ) ;
}
static int F_383 ( struct V_842 * V_847 ,
T_2 V_267 )
{
struct V_843 * V_24 ;
struct V_280 V_281 ;
T_2 V_17 = F_22 () ;
V_24 = V_847 -> V_19 ;
V_281 . type = V_848 ;
V_281 . V_286 . V_849 = V_847 -> V_850 ;
return F_46 ( V_17 , V_24 -> V_17 , V_24 -> V_31 , V_267 , & V_281 ) ;
}
static int F_384 ( struct V_844 * V_749 )
{
return F_381 ( V_749 ) ;
}
static void F_385 ( struct V_844 * V_749 )
{
F_382 ( V_749 ) ;
}
static int F_386 ( struct V_851 * V_852 )
{
struct V_843 * V_24 ;
struct V_280 V_281 ;
T_2 V_17 = F_22 () ;
int V_54 ;
V_54 = F_379 ( V_11 , & V_852 -> V_853 , V_854 ) ;
if ( V_54 )
return V_54 ;
V_24 = V_852 -> V_853 . V_19 ;
V_281 . type = V_848 ;
V_281 . V_286 . V_849 = V_852 -> V_853 . V_850 ;
V_54 = F_46 ( V_17 , V_24 -> V_17 , V_854 ,
V_855 , & V_281 ) ;
if ( V_54 ) {
F_380 ( & V_852 -> V_853 ) ;
return V_54 ;
}
return 0 ;
}
static void F_387 ( struct V_851 * V_852 )
{
F_380 ( & V_852 -> V_853 ) ;
}
static int F_388 ( struct V_851 * V_852 , int V_856 )
{
struct V_843 * V_24 ;
struct V_280 V_281 ;
T_2 V_17 = F_22 () ;
V_24 = V_852 -> V_853 . V_19 ;
V_281 . type = V_848 ;
V_281 . V_286 . V_849 = V_852 -> V_853 . V_850 ;
return F_46 ( V_17 , V_24 -> V_17 , V_854 ,
V_857 , & V_281 ) ;
}
static int F_389 ( struct V_851 * V_852 , int V_551 )
{
int V_603 ;
int V_267 ;
switch ( V_551 ) {
case V_858 :
case V_859 :
return F_115 ( V_11 , V_860 ) ;
case V_861 :
case V_862 :
V_267 = V_863 | V_857 ;
break;
case V_864 :
V_267 = V_865 ;
break;
case V_866 :
V_267 = V_867 ;
break;
default:
return 0 ;
}
V_603 = F_383 ( & V_852 -> V_853 , V_267 ) ;
return V_603 ;
}
static int F_390 ( struct V_851 * V_852 , struct V_844 * V_749 , int V_856 )
{
struct V_843 * V_24 ;
struct V_845 * V_846 ;
struct V_280 V_281 ;
T_2 V_17 = F_22 () ;
int V_54 ;
V_24 = V_852 -> V_853 . V_19 ;
V_846 = V_749 -> V_19 ;
if ( V_846 -> V_17 == V_30 ) {
V_54 = F_104 ( V_17 , V_24 -> V_17 , V_868 ,
NULL , & V_846 -> V_17 ) ;
if ( V_54 )
return V_54 ;
}
V_281 . type = V_848 ;
V_281 . V_286 . V_849 = V_852 -> V_853 . V_850 ;
V_54 = F_46 ( V_17 , V_24 -> V_17 , V_854 ,
V_869 , & V_281 ) ;
if ( ! V_54 )
V_54 = F_46 ( V_17 , V_846 -> V_17 , V_868 ,
V_870 , & V_281 ) ;
if ( ! V_54 )
V_54 = F_46 ( V_846 -> V_17 , V_24 -> V_17 , V_854 ,
V_871 , & V_281 ) ;
return V_54 ;
}
static int F_391 ( struct V_851 * V_852 , struct V_844 * V_749 ,
struct V_20 * V_266 ,
long type , int V_169 )
{
struct V_843 * V_24 ;
struct V_845 * V_846 ;
struct V_280 V_281 ;
T_2 V_17 = F_18 ( V_266 ) ;
int V_54 ;
V_24 = V_852 -> V_853 . V_19 ;
V_846 = V_749 -> V_19 ;
V_281 . type = V_848 ;
V_281 . V_286 . V_849 = V_852 -> V_853 . V_850 ;
V_54 = F_46 ( V_17 , V_24 -> V_17 ,
V_854 , V_872 , & V_281 ) ;
if ( ! V_54 )
V_54 = F_46 ( V_17 , V_846 -> V_17 ,
V_868 , V_873 , & V_281 ) ;
return V_54 ;
}
static int F_392 ( struct V_874 * V_875 )
{
struct V_843 * V_24 ;
struct V_280 V_281 ;
T_2 V_17 = F_22 () ;
int V_54 ;
V_54 = F_379 ( V_11 , & V_875 -> V_876 , V_877 ) ;
if ( V_54 )
return V_54 ;
V_24 = V_875 -> V_876 . V_19 ;
V_281 . type = V_848 ;
V_281 . V_286 . V_849 = V_875 -> V_876 . V_850 ;
V_54 = F_46 ( V_17 , V_24 -> V_17 , V_877 ,
V_878 , & V_281 ) ;
if ( V_54 ) {
F_380 ( & V_875 -> V_876 ) ;
return V_54 ;
}
return 0 ;
}
static void F_393 ( struct V_874 * V_875 )
{
F_380 ( & V_875 -> V_876 ) ;
}
static int F_394 ( struct V_874 * V_875 , int V_879 )
{
struct V_843 * V_24 ;
struct V_280 V_281 ;
T_2 V_17 = F_22 () ;
V_24 = V_875 -> V_876 . V_19 ;
V_281 . type = V_848 ;
V_281 . V_286 . V_849 = V_875 -> V_876 . V_850 ;
return F_46 ( V_17 , V_24 -> V_17 , V_877 ,
V_880 , & V_281 ) ;
}
static int F_395 ( struct V_874 * V_875 , int V_551 )
{
int V_267 ;
int V_603 ;
switch ( V_551 ) {
case V_858 :
case V_881 :
return F_115 ( V_11 , V_860 ) ;
case V_861 :
case V_882 :
V_267 = V_883 | V_880 ;
break;
case V_864 :
V_267 = V_884 ;
break;
case V_885 :
case V_886 :
V_267 = V_887 ;
break;
case V_866 :
V_267 = V_888 ;
break;
default:
return 0 ;
}
V_603 = F_383 ( & V_875 -> V_876 , V_267 ) ;
return V_603 ;
}
static int F_396 ( struct V_874 * V_875 ,
char T_15 * V_889 , int V_879 )
{
T_2 V_267 ;
if ( V_879 & V_890 )
V_267 = V_891 ;
else
V_267 = V_891 | V_892 ;
return F_383 ( & V_875 -> V_876 , V_267 ) ;
}
static int F_397 ( struct V_893 * V_894 )
{
struct V_843 * V_24 ;
struct V_280 V_281 ;
T_2 V_17 = F_22 () ;
int V_54 ;
V_54 = F_379 ( V_11 , & V_894 -> V_895 , V_896 ) ;
if ( V_54 )
return V_54 ;
V_24 = V_894 -> V_895 . V_19 ;
V_281 . type = V_848 ;
V_281 . V_286 . V_849 = V_894 -> V_895 . V_850 ;
V_54 = F_46 ( V_17 , V_24 -> V_17 , V_896 ,
V_897 , & V_281 ) ;
if ( V_54 ) {
F_380 ( & V_894 -> V_895 ) ;
return V_54 ;
}
return 0 ;
}
static void F_398 ( struct V_893 * V_894 )
{
F_380 ( & V_894 -> V_895 ) ;
}
static int F_399 ( struct V_893 * V_894 , int V_898 )
{
struct V_843 * V_24 ;
struct V_280 V_281 ;
T_2 V_17 = F_22 () ;
V_24 = V_894 -> V_895 . V_19 ;
V_281 . type = V_848 ;
V_281 . V_286 . V_849 = V_894 -> V_895 . V_850 ;
return F_46 ( V_17 , V_24 -> V_17 , V_896 ,
V_899 , & V_281 ) ;
}
static int F_400 ( struct V_893 * V_894 , int V_551 )
{
int V_603 ;
T_2 V_267 ;
switch ( V_551 ) {
case V_858 :
case V_900 :
return F_115 ( V_11 , V_860 ) ;
case V_901 :
case V_902 :
case V_903 :
V_267 = V_904 ;
break;
case V_905 :
case V_906 :
V_267 = V_907 ;
break;
case V_908 :
case V_909 :
V_267 = V_910 ;
break;
case V_866 :
V_267 = V_911 ;
break;
case V_864 :
V_267 = V_912 ;
break;
case V_861 :
case V_913 :
V_267 = V_904 | V_899 ;
break;
default:
return 0 ;
}
V_603 = F_383 ( & V_894 -> V_895 , V_267 ) ;
return V_603 ;
}
static int F_401 ( struct V_893 * V_894 ,
struct V_914 * V_915 , unsigned V_916 , int V_917 )
{
T_2 V_267 ;
if ( V_917 )
V_267 = V_907 | V_910 ;
else
V_267 = V_907 ;
return F_383 ( & V_894 -> V_895 , V_267 ) ;
}
static int F_402 ( struct V_842 * V_918 , short V_104 )
{
T_2 V_284 = 0 ;
V_284 = 0 ;
if ( V_104 & V_919 )
V_284 |= V_920 ;
if ( V_104 & V_921 )
V_284 |= V_922 ;
if ( V_284 == 0 )
return 0 ;
return F_383 ( V_918 , V_284 ) ;
}
static void F_403 ( struct V_842 * V_918 , T_2 * V_547 )
{
struct V_843 * V_24 = V_918 -> V_19 ;
* V_547 = V_24 -> V_17 ;
}
static void F_404 ( struct V_66 * V_66 , struct V_22 * V_22 )
{
if ( V_22 )
F_44 ( V_22 , V_66 ) ;
}
static int F_405 ( struct V_20 * V_146 ,
char * V_65 , char * * V_503 )
{
const struct V_13 * V_804 ;
T_2 V_17 ;
int error ;
unsigned V_89 ;
if ( V_11 != V_146 ) {
error = F_109 ( V_146 , V_923 ) ;
if ( error )
return error ;
}
F_19 () ;
V_804 = F_20 ( V_146 ) -> V_19 ;
if ( ! strcmp ( V_65 , L_49 ) )
V_17 = V_804 -> V_17 ;
else if ( ! strcmp ( V_65 , L_50 ) )
V_17 = V_804 -> V_16 ;
else if ( ! strcmp ( V_65 , L_51 ) )
V_17 = V_804 -> V_422 ;
else if ( ! strcmp ( V_65 , L_52 ) )
V_17 = V_804 -> V_302 ;
else if ( ! strcmp ( V_65 , L_53 ) )
V_17 = V_804 -> V_420 ;
else if ( ! strcmp ( V_65 , L_54 ) )
V_17 = V_804 -> V_421 ;
else
goto V_924;
F_21 () ;
if ( ! V_17 )
return 0 ;
error = F_62 ( V_17 , V_503 , & V_89 ) ;
if ( error )
return error ;
return V_89 ;
V_924:
F_21 () ;
return - V_91 ;
}
static int F_406 ( struct V_20 * V_146 ,
char * V_65 , void * V_503 , T_7 V_534 )
{
struct V_13 * V_14 ;
struct V_20 * V_430 ;
struct V_10 * V_129 ;
T_2 V_17 = 0 , V_432 ;
int error ;
char * V_1 = V_503 ;
if ( V_11 != V_146 ) {
return - V_418 ;
}
if ( ! strcmp ( V_65 , L_51 ) )
error = F_109 ( V_146 , V_925 ) ;
else if ( ! strcmp ( V_65 , L_52 ) )
error = F_109 ( V_146 , V_926 ) ;
else if ( ! strcmp ( V_65 , L_53 ) )
error = F_109 ( V_146 , V_927 ) ;
else if ( ! strcmp ( V_65 , L_54 ) )
error = F_109 ( V_146 , V_928 ) ;
else if ( ! strcmp ( V_65 , L_49 ) )
error = F_109 ( V_146 , V_929 ) ;
else
error = - V_91 ;
if ( error )
return error ;
if ( V_534 && V_1 [ 1 ] && V_1 [ 1 ] != '\n' ) {
if ( V_1 [ V_534 - 1 ] == '\n' ) {
V_1 [ V_534 - 1 ] = 0 ;
V_534 -- ;
}
error = F_223 ( V_503 , V_534 , & V_17 , V_15 ) ;
if ( error == - V_91 && ! strcmp ( V_65 , L_52 ) ) {
if ( ! F_220 ( V_536 ) ) {
struct V_537 * V_538 ;
T_7 V_539 ;
if ( V_1 [ V_534 - 1 ] == '\0' )
V_539 = V_534 - 1 ;
else
V_539 = V_534 ;
V_538 = F_224 ( V_11 -> V_540 , V_97 , V_541 ) ;
F_225 ( V_538 , L_55 ) ;
F_226 ( V_538 , V_503 , V_539 ) ;
F_227 ( V_538 ) ;
return error ;
}
error = F_228 ( V_503 , V_534 ,
& V_17 ) ;
}
if ( error )
return error ;
}
V_129 = F_407 () ;
if ( ! V_129 )
return - V_27 ;
V_14 = V_129 -> V_19 ;
if ( ! strcmp ( V_65 , L_51 ) ) {
V_14 -> V_422 = V_17 ;
} else if ( ! strcmp ( V_65 , L_52 ) ) {
V_14 -> V_302 = V_17 ;
} else if ( ! strcmp ( V_65 , L_53 ) ) {
error = F_126 ( V_17 , V_146 ) ;
if ( error )
goto V_930;
V_14 -> V_420 = V_17 ;
} else if ( ! strcmp ( V_65 , L_54 ) ) {
V_14 -> V_421 = V_17 ;
} else if ( ! strcmp ( V_65 , L_49 ) ) {
error = - V_91 ;
if ( V_17 == 0 )
goto V_930;
error = - V_417 ;
if ( ! F_408 () ) {
error = F_150 ( V_14 -> V_17 , V_17 ) ;
if ( error )
goto V_930;
}
error = F_46 ( V_14 -> V_17 , V_17 , V_270 ,
V_931 , NULL ) ;
if ( error )
goto V_930;
V_432 = 0 ;
F_19 () ;
V_430 = F_152 ( V_146 ) ;
if ( V_430 )
V_432 = F_18 ( V_430 ) ;
F_21 () ;
if ( V_430 ) {
error = F_46 ( V_432 , V_17 , V_270 ,
V_366 , NULL ) ;
if ( error )
goto V_930;
}
V_14 -> V_17 = V_17 ;
} else {
error = - V_91 ;
goto V_930;
}
F_409 ( V_129 ) ;
return V_534 ;
V_930:
F_410 ( V_129 ) ;
return error ;
}
static int F_411 ( const char * V_65 )
{
return ( strcmp ( V_65 , V_505 ) == 0 ) ;
}
static int F_412 ( T_2 V_547 , char * * V_486 , T_2 * V_932 )
{
return F_62 ( V_547 , V_486 , V_932 ) ;
}
static int F_413 ( const char * V_486 , T_2 V_932 , T_2 * V_547 )
{
return F_223 ( V_486 , V_932 , V_547 , V_15 ) ;
}
static void F_414 ( char * V_486 , T_2 V_932 )
{
F_42 ( V_486 ) ;
}
static int F_415 ( struct V_22 * V_22 , void * V_309 , T_2 V_501 )
{
return F_236 ( V_22 , V_505 , V_309 , V_501 , 0 ) ;
}
static int F_416 ( struct V_66 * V_66 , void * V_309 , T_2 V_501 )
{
return F_417 ( V_66 , V_76 , V_309 , V_501 , 0 ) ;
}
static int F_418 ( struct V_22 * V_22 , void * * V_309 , T_2 * V_501 )
{
int V_89 = 0 ;
V_89 = F_234 ( V_22 , V_505 ,
V_309 , true ) ;
if ( V_89 < 0 )
return V_89 ;
* V_501 = V_89 ;
return 0 ;
}
static int F_419 ( struct V_850 * V_933 , const struct V_10 * V_10 ,
unsigned long V_80 )
{
const struct V_13 * V_14 ;
struct V_934 * V_935 ;
V_935 = F_15 ( sizeof( struct V_934 ) , V_15 ) ;
if ( ! V_935 )
return - V_27 ;
V_14 = V_10 -> V_19 ;
if ( V_14 -> V_420 )
V_935 -> V_17 = V_14 -> V_420 ;
else
V_935 -> V_17 = V_14 -> V_17 ;
V_933 -> V_19 = V_935 ;
return 0 ;
}
static void F_420 ( struct V_850 * V_933 )
{
struct V_934 * V_935 = V_933 -> V_19 ;
V_933 -> V_19 = NULL ;
F_42 ( V_935 ) ;
}
static int F_421 ( T_16 V_936 ,
const struct V_10 * V_10 ,
unsigned V_257 )
{
struct V_850 * V_850 ;
struct V_934 * V_935 ;
T_2 V_17 ;
if ( V_257 == 0 )
return 0 ;
V_17 = F_17 ( V_10 ) ;
V_850 = F_422 ( V_936 ) ;
V_935 = V_850 -> V_19 ;
return F_46 ( V_17 , V_935 -> V_17 , V_310 , V_257 , NULL ) ;
}
static int F_423 ( struct V_850 * V_850 , char * * V_937 )
{
struct V_934 * V_935 = V_850 -> V_19 ;
char * V_88 = NULL ;
unsigned V_89 ;
int V_54 ;
V_54 = F_62 ( V_935 -> V_17 , & V_88 , & V_89 ) ;
if ( ! V_54 )
V_54 = V_89 ;
* V_937 = V_88 ;
return V_54 ;
}
static T_1 int F_424 ( void )
{
if ( ! F_425 ( L_56 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_51 ( V_938 L_57 ) ;
return 0 ;
}
F_51 ( V_938 L_58 ) ;
F_14 () ;
V_574 = ! ( V_939 & V_589 ) ;
V_25 = F_426 ( L_59 ,
sizeof( struct V_23 ) ,
0 , V_940 , NULL ) ;
V_45 = F_426 ( L_60 ,
sizeof( struct V_43 ) ,
0 , V_940 , NULL ) ;
F_427 () ;
F_428 ( V_941 , F_52 ( V_941 ) ) ;
if ( F_429 ( F_9 , V_9 ) )
F_16 ( L_61 ) ;
if ( V_3 )
F_51 ( V_942 L_62 ) ;
else
F_51 ( V_942 L_63 ) ;
return 0 ;
}
static void F_430 ( struct V_48 * V_49 , void * V_943 )
{
F_78 ( V_49 , NULL ) ;
}
void F_431 ( void )
{
F_51 ( V_942 L_64 ) ;
F_51 ( V_942 L_65 ) ;
F_432 ( F_430 , NULL ) ;
}
static int T_1 F_433 ( void )
{
int V_603 ;
if ( ! V_5 )
return 0 ;
F_51 ( V_942 L_66 ) ;
V_603 = F_434 ( V_944 , F_52 ( V_944 ) ) ;
if ( V_603 )
F_16 ( L_67 , V_603 ) ;
return 0 ;
}
static void F_435 ( void )
{
F_51 ( V_942 L_68 ) ;
F_436 ( V_944 , F_52 ( V_944 ) ) ;
}
int F_437 ( void )
{
if ( V_92 ) {
return - V_91 ;
}
if ( V_945 ) {
return - V_91 ;
}
F_51 ( V_938 L_69 ) ;
V_945 = 1 ;
V_5 = 0 ;
F_438 ( V_941 , F_52 ( V_941 ) ) ;
F_439 () ;
F_435 () ;
F_440 () ;
return 0 ;
}
