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
return ( F_5 ( & V_6 ) > 0 ) ;
}
static void F_6 ( void )
{
struct V_7 * V_7 = (struct V_7 * ) V_8 -> V_9 ;
struct V_10 * V_11 ;
V_11 = F_7 ( sizeof( struct V_10 ) , V_12 ) ;
if ( ! V_11 )
F_8 ( L_1 ) ;
V_11 -> V_13 = V_11 -> V_14 = V_15 ;
V_7 -> V_16 = V_11 ;
}
static inline T_2 F_9 ( const struct V_7 * V_7 )
{
const struct V_10 * V_11 ;
V_11 = V_7 -> V_16 ;
return V_11 -> V_14 ;
}
static inline T_2 F_10 ( const struct V_17 * V_18 )
{
T_2 V_14 ;
F_11 () ;
V_14 = F_9 ( F_12 ( V_18 ) ) ;
F_13 () ;
return V_14 ;
}
static inline T_2 F_14 ( void )
{
const struct V_10 * V_11 = F_15 () ;
return V_11 -> V_14 ;
}
static int F_16 ( struct V_19 * V_19 )
{
struct V_20 * V_21 ;
T_2 V_14 = F_14 () ;
V_21 = F_17 ( V_22 , V_23 ) ;
if ( ! V_21 )
return - V_24 ;
F_18 ( & V_21 -> V_25 ) ;
F_19 ( & V_21 -> V_26 ) ;
V_21 -> V_19 = V_19 ;
V_21 -> V_14 = V_27 ;
V_21 -> V_28 = V_29 ;
V_21 -> F_10 = V_14 ;
V_19 -> V_30 = V_21 ;
return 0 ;
}
static void F_20 ( struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
struct V_31 * V_32 = V_19 -> V_33 -> V_34 ;
F_21 ( & V_32 -> V_35 ) ;
if ( ! F_22 ( & V_21 -> V_26 ) )
F_23 ( & V_21 -> V_26 ) ;
F_24 ( & V_32 -> V_35 ) ;
V_19 -> V_30 = NULL ;
F_25 ( V_22 , V_21 ) ;
}
static int F_26 ( struct V_36 * V_36 )
{
struct V_37 * V_38 ;
T_2 V_14 = F_14 () ;
V_38 = F_7 ( sizeof( struct V_37 ) , V_12 ) ;
if ( ! V_38 )
return - V_24 ;
V_38 -> V_14 = V_14 ;
V_38 -> V_39 = V_14 ;
V_36 -> V_40 = V_38 ;
return 0 ;
}
static void F_27 ( struct V_36 * V_36 )
{
struct V_37 * V_38 = V_36 -> V_40 ;
V_36 -> V_40 = NULL ;
F_28 ( V_38 ) ;
}
static int F_29 ( struct V_41 * V_42 )
{
struct V_31 * V_32 ;
V_32 = F_7 ( sizeof( struct V_31 ) , V_12 ) ;
if ( ! V_32 )
return - V_24 ;
F_18 ( & V_32 -> V_25 ) ;
F_19 ( & V_32 -> V_43 ) ;
F_30 ( & V_32 -> V_35 ) ;
V_32 -> V_42 = V_42 ;
V_32 -> V_14 = V_27 ;
V_32 -> V_44 = V_45 ;
V_32 -> V_46 = V_27 ;
V_42 -> V_34 = V_32 ;
return 0 ;
}
static void F_31 ( struct V_41 * V_42 )
{
struct V_31 * V_32 = V_42 -> V_34 ;
V_42 -> V_34 = NULL ;
F_28 ( V_32 ) ;
}
static inline int F_32 ( struct V_19 * V_19 )
{
return F_33 ( V_19 , NULL ) ;
}
static int F_34 ( T_2 V_14 ,
struct V_31 * V_32 ,
const struct V_7 * V_7 )
{
const struct V_10 * V_11 = V_7 -> V_16 ;
int V_47 ;
V_47 = F_35 ( V_11 -> V_14 , V_32 -> V_14 , V_48 ,
V_49 , NULL ) ;
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_11 -> V_14 , V_14 , V_48 ,
V_50 , NULL ) ;
return V_47 ;
}
static int F_36 ( T_2 V_14 ,
struct V_31 * V_32 ,
const struct V_7 * V_7 )
{
const struct V_10 * V_11 = V_7 -> V_16 ;
int V_47 ;
V_47 = F_35 ( V_11 -> V_14 , V_32 -> V_14 , V_48 ,
V_49 , NULL ) ;
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_14 , V_32 -> V_14 , V_48 ,
V_51 , NULL ) ;
return V_47 ;
}
static int F_37 ( struct V_41 * V_42 )
{
struct V_31 * V_32 = V_42 -> V_34 ;
struct V_52 * V_53 = V_42 -> V_54 ;
struct V_19 * V_55 = V_53 -> V_56 ;
int V_47 = 0 ;
if ( V_32 -> V_57 == V_58 ) {
if ( ! V_55 -> V_59 -> V_60 ) {
F_38 ( V_61 L_2
L_3 , V_42 -> V_62 , V_42 -> V_63 -> V_64 ) ;
V_47 = - V_65 ;
goto V_66;
}
V_47 = V_55 -> V_59 -> V_60 ( V_53 , V_67 , NULL , 0 ) ;
if ( V_47 < 0 && V_47 != - V_68 ) {
if ( V_47 == - V_65 )
F_38 ( V_61 L_4
L_5 ,
V_42 -> V_62 , V_42 -> V_63 -> V_64 ) ;
else
F_38 ( V_61 L_4
L_6 , V_42 -> V_62 ,
V_42 -> V_63 -> V_64 , - V_47 ) ;
goto V_66;
}
}
V_32 -> V_69 |= ( V_70 | V_71 ) ;
if ( V_32 -> V_57 > F_39 ( V_72 ) )
F_38 ( V_73 L_7 ,
V_42 -> V_62 , V_42 -> V_63 -> V_64 ) ;
else
F_38 ( V_74 L_8 ,
V_42 -> V_62 , V_42 -> V_63 -> V_64 ,
V_72 [ V_32 -> V_57 - 1 ] ) ;
if ( V_32 -> V_57 == V_75 ||
V_32 -> V_57 == V_76 ||
V_32 -> V_57 == V_77 ||
V_32 -> V_57 > F_39 ( V_72 ) )
V_32 -> V_69 &= ~ V_71 ;
if ( strncmp ( V_42 -> V_63 -> V_64 , L_9 , sizeof( L_9 ) ) == 0 )
V_32 -> V_69 |= V_71 ;
V_47 = F_33 ( V_55 , V_53 ) ;
F_21 ( & V_32 -> V_35 ) ;
V_78:
if ( ! F_22 ( & V_32 -> V_43 ) ) {
struct V_20 * V_21 =
F_40 ( V_32 -> V_43 . V_79 ,
struct V_20 , V_26 ) ;
struct V_19 * V_19 = V_21 -> V_19 ;
F_24 ( & V_32 -> V_35 ) ;
V_19 = F_41 ( V_19 ) ;
if ( V_19 ) {
if ( ! F_42 ( V_19 ) )
F_32 ( V_19 ) ;
F_43 ( V_19 ) ;
}
F_21 ( & V_32 -> V_35 ) ;
F_23 ( & V_21 -> V_26 ) ;
goto V_78;
}
F_24 ( & V_32 -> V_35 ) ;
V_66:
return V_47 ;
}
static int F_44 ( const struct V_41 * V_42 ,
struct V_80 * V_81 )
{
int V_47 = 0 , V_82 ;
struct V_31 * V_32 = V_42 -> V_34 ;
char * V_83 = NULL ;
T_2 V_84 ;
char V_85 ;
F_45 ( V_81 ) ;
if ( ! ( V_32 -> V_69 & V_70 ) )
return - V_86 ;
if ( ! V_87 )
return - V_86 ;
V_85 = V_32 -> V_69 & V_88 ;
for ( V_82 = 0 ; V_82 < 8 ; V_82 ++ ) {
if ( V_85 & 0x01 )
V_81 -> V_89 ++ ;
V_85 >>= 1 ;
}
if ( V_32 -> V_69 & V_71 )
V_81 -> V_89 ++ ;
V_81 -> V_90 = F_46 ( V_81 -> V_89 , sizeof( char * ) , V_91 ) ;
if ( ! V_81 -> V_90 ) {
V_47 = - V_24 ;
goto V_92;
}
V_81 -> V_93 = F_46 ( V_81 -> V_89 , sizeof( int ) , V_91 ) ;
if ( ! V_81 -> V_93 ) {
V_47 = - V_24 ;
goto V_92;
}
V_82 = 0 ;
if ( V_32 -> V_69 & V_94 ) {
V_47 = F_47 ( V_32 -> V_14 , & V_83 , & V_84 ) ;
if ( V_47 )
goto V_92;
V_81 -> V_90 [ V_82 ] = V_83 ;
V_81 -> V_93 [ V_82 ++ ] = V_94 ;
}
if ( V_32 -> V_69 & V_95 ) {
V_47 = F_47 ( V_32 -> V_46 , & V_83 , & V_84 ) ;
if ( V_47 )
goto V_92;
V_81 -> V_90 [ V_82 ] = V_83 ;
V_81 -> V_93 [ V_82 ++ ] = V_95 ;
}
if ( V_32 -> V_69 & V_96 ) {
V_47 = F_47 ( V_32 -> V_44 , & V_83 , & V_84 ) ;
if ( V_47 )
goto V_92;
V_81 -> V_90 [ V_82 ] = V_83 ;
V_81 -> V_93 [ V_82 ++ ] = V_96 ;
}
if ( V_32 -> V_69 & V_97 ) {
struct V_19 * V_53 = V_32 -> V_42 -> V_54 -> V_56 ;
struct V_20 * V_21 = V_53 -> V_30 ;
V_47 = F_47 ( V_21 -> V_14 , & V_83 , & V_84 ) ;
if ( V_47 )
goto V_92;
V_81 -> V_90 [ V_82 ] = V_83 ;
V_81 -> V_93 [ V_82 ++ ] = V_97 ;
}
if ( V_32 -> V_69 & V_71 ) {
V_81 -> V_90 [ V_82 ] = NULL ;
V_81 -> V_93 [ V_82 ++ ] = V_71 ;
}
F_48 ( V_82 != V_81 -> V_89 ) ;
return 0 ;
V_92:
F_49 ( V_81 ) ;
return V_47 ;
}
static int F_50 ( struct V_31 * V_32 , char V_98 ,
T_2 V_99 , T_2 V_100 )
{
char V_101 = V_32 -> V_69 & V_88 ;
if ( V_32 -> V_69 & V_70 )
if ( ! ( V_32 -> V_69 & V_98 ) ||
( V_99 != V_100 ) )
return 1 ;
if ( ! ( V_32 -> V_69 & V_70 ) )
if ( V_101 & V_98 )
return 1 ;
return 0 ;
}
static int F_51 ( struct V_41 * V_42 ,
struct V_80 * V_81 )
{
const struct V_7 * V_7 = F_52 () ;
int V_47 = 0 , V_82 ;
struct V_31 * V_32 = V_42 -> V_34 ;
const char * V_64 = V_42 -> V_63 -> V_64 ;
struct V_19 * V_19 = V_32 -> V_42 -> V_54 -> V_56 ;
struct V_20 * V_102 = V_19 -> V_30 ;
T_2 V_103 = 0 , V_104 = 0 , V_105 = 0 ;
T_2 V_106 = 0 ;
char * * V_107 = V_81 -> V_90 ;
int * V_69 = V_81 -> V_93 ;
int V_108 = V_81 -> V_89 ;
F_53 ( & V_32 -> V_25 ) ;
if ( ! V_87 ) {
if ( ! V_108 ) {
goto V_66;
}
V_47 = - V_86 ;
F_38 ( V_61 L_10
L_11 ) ;
goto V_66;
}
if ( ( V_32 -> V_69 & V_70 ) && ( V_42 -> V_63 -> V_109 & V_110 )
&& ( V_108 == 0 ) )
goto V_66;
for ( V_82 = 0 ; V_82 < V_108 ; V_82 ++ ) {
T_2 V_14 ;
if ( V_69 [ V_82 ] == V_71 )
continue;
V_47 = F_54 ( V_107 [ V_82 ] ,
strlen ( V_107 [ V_82 ] ) , & V_14 ) ;
if ( V_47 ) {
F_38 ( V_61 L_12
L_13 ,
V_107 [ V_82 ] , V_42 -> V_62 , V_64 , V_47 ) ;
goto V_66;
}
switch ( V_69 [ V_82 ] ) {
case V_94 :
V_103 = V_14 ;
if ( F_50 ( V_32 , V_94 , V_32 -> V_14 ,
V_103 ) )
goto V_111;
V_32 -> V_69 |= V_94 ;
break;
case V_95 :
V_104 = V_14 ;
if ( F_50 ( V_32 , V_95 , V_32 -> V_46 ,
V_104 ) )
goto V_111;
V_32 -> V_69 |= V_95 ;
break;
case V_97 :
V_105 = V_14 ;
if ( F_50 ( V_32 , V_97 , V_102 -> V_14 ,
V_105 ) )
goto V_111;
V_32 -> V_69 |= V_97 ;
break;
case V_96 :
V_106 = V_14 ;
if ( F_50 ( V_32 , V_96 , V_32 -> V_44 ,
V_106 ) )
goto V_111;
V_32 -> V_69 |= V_96 ;
break;
default:
V_47 = - V_86 ;
goto V_66;
}
}
if ( V_32 -> V_69 & V_70 ) {
if ( ( V_32 -> V_69 & V_88 ) && ! V_108 )
goto V_111;
V_47 = 0 ;
goto V_66;
}
if ( strcmp ( V_42 -> V_63 -> V_64 , L_14 ) == 0 )
V_32 -> V_69 |= V_112 ;
V_47 = F_55 ( ( V_32 -> V_69 & V_112 ) ? L_14 : V_42 -> V_63 -> V_64 , & V_32 -> V_57 , & V_32 -> V_14 ) ;
if ( V_47 ) {
F_38 ( V_61 L_15 ,
V_113 , V_42 -> V_63 -> V_64 , V_47 ) ;
goto V_66;
}
if ( V_103 ) {
V_47 = F_34 ( V_103 , V_32 , V_7 ) ;
if ( V_47 )
goto V_66;
V_32 -> V_14 = V_103 ;
}
if ( V_104 ) {
if ( ! V_103 ) {
V_47 = F_34 ( V_104 , V_32 ,
V_7 ) ;
if ( V_47 )
goto V_66;
V_32 -> V_14 = V_104 ;
} else {
V_47 = F_36 ( V_104 , V_32 ,
V_7 ) ;
if ( V_47 )
goto V_66;
}
if ( ! V_105 )
V_105 = V_104 ;
V_32 -> V_46 = V_104 ;
V_32 -> V_57 = V_76 ;
}
if ( V_105 ) {
V_47 = F_36 ( V_105 , V_32 ,
V_7 ) ;
if ( V_47 )
goto V_66;
V_102 -> V_14 = V_105 ;
V_102 -> V_114 = 1 ;
}
if ( V_106 ) {
if ( V_32 -> V_57 != V_58 ) {
V_47 = - V_86 ;
F_38 ( V_61 L_16
L_17 ) ;
goto V_66;
}
if ( V_106 != V_32 -> V_44 ) {
V_47 = F_36 ( V_106 ,
V_32 , V_7 ) ;
if ( V_47 )
goto V_66;
}
V_32 -> V_44 = V_106 ;
}
V_47 = F_37 ( V_42 ) ;
V_66:
F_56 ( & V_32 -> V_25 ) ;
return V_47 ;
V_111:
V_47 = - V_86 ;
F_38 ( V_61 L_18
L_19 , V_42 -> V_62 , V_64 ) ;
goto V_66;
}
static int F_57 ( const struct V_41 * V_115 ,
const struct V_41 * V_116 )
{
struct V_31 * V_117 = V_115 -> V_34 ;
struct V_31 * V_118 = V_116 -> V_34 ;
char V_119 = V_117 -> V_69 & V_88 ;
char V_120 = V_118 -> V_69 & V_88 ;
if ( V_119 != V_120 )
goto V_121;
if ( ( V_119 & V_94 ) && V_117 -> V_14 != V_118 -> V_14 )
goto V_121;
if ( ( V_119 & V_95 ) && V_117 -> V_46 != V_118 -> V_46 )
goto V_121;
if ( ( V_119 & V_96 ) && V_117 -> V_44 != V_118 -> V_44 )
goto V_121;
if ( V_119 & V_97 ) {
struct V_20 * V_122 = V_115 -> V_54 -> V_56 -> V_30 ;
struct V_20 * V_123 = V_116 -> V_54 -> V_56 -> V_30 ;
if ( V_122 -> V_14 != V_123 -> V_14 )
goto V_121;
}
return 0 ;
V_121:
F_38 ( V_61 L_20
L_21
L_22 , V_116 -> V_62 , V_116 -> V_63 -> V_64 ) ;
return - V_124 ;
}
static int F_58 ( const struct V_41 * V_115 ,
struct V_41 * V_116 )
{
const struct V_31 * V_125 = V_115 -> V_34 ;
struct V_31 * V_126 = V_116 -> V_34 ;
int V_127 = ( V_125 -> V_69 & V_94 ) ;
int V_128 = ( V_125 -> V_69 & V_95 ) ;
int V_129 = ( V_125 -> V_69 & V_97 ) ;
if ( ! V_87 )
return 0 ;
F_48 ( ! ( V_125 -> V_69 & V_70 ) ) ;
if ( V_126 -> V_69 & V_70 )
return F_57 ( V_115 , V_116 ) ;
F_53 ( & V_126 -> V_25 ) ;
V_126 -> V_69 = V_125 -> V_69 ;
V_126 -> V_14 = V_125 -> V_14 ;
V_126 -> V_44 = V_125 -> V_44 ;
V_126 -> V_57 = V_125 -> V_57 ;
if ( V_128 ) {
T_2 V_14 = V_125 -> V_46 ;
if ( ! V_127 )
V_126 -> V_14 = V_14 ;
if ( ! V_129 ) {
struct V_19 * V_130 = V_116 -> V_54 -> V_56 ;
struct V_20 * V_131 = V_130 -> V_30 ;
V_131 -> V_14 = V_14 ;
}
V_126 -> V_46 = V_14 ;
}
if ( V_129 ) {
const struct V_19 * V_132 = V_115 -> V_54 -> V_56 ;
const struct V_20 * V_133 = V_132 -> V_30 ;
struct V_19 * V_130 = V_116 -> V_54 -> V_56 ;
struct V_20 * V_131 = V_130 -> V_30 ;
V_131 -> V_14 = V_133 -> V_14 ;
}
F_37 ( V_116 ) ;
F_56 ( & V_126 -> V_25 ) ;
return 0 ;
}
static int F_59 ( char * V_134 ,
struct V_80 * V_81 )
{
char * V_135 ;
char * V_83 = NULL , * V_136 = NULL ;
char * V_137 = NULL , * V_138 = NULL ;
int V_47 , V_89 = 0 ;
V_81 -> V_89 = 0 ;
while ( ( V_135 = F_60 ( & V_134 , L_23 ) ) != NULL ) {
int V_139 ;
T_3 args [ V_140 ] ;
if ( ! * V_135 )
continue;
V_139 = F_61 ( V_135 , V_141 , args ) ;
switch ( V_139 ) {
case V_142 :
if ( V_83 || V_136 ) {
V_47 = - V_86 ;
F_38 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_143;
}
V_83 = F_62 ( & args [ 0 ] ) ;
if ( ! V_83 ) {
V_47 = - V_24 ;
goto V_143;
}
break;
case V_144 :
if ( V_137 ) {
V_47 = - V_86 ;
F_38 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_143;
}
V_137 = F_62 ( & args [ 0 ] ) ;
if ( ! V_137 ) {
V_47 = - V_24 ;
goto V_143;
}
break;
case V_145 :
if ( V_138 ) {
V_47 = - V_86 ;
F_38 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_143;
}
V_138 = F_62 ( & args [ 0 ] ) ;
if ( ! V_138 ) {
V_47 = - V_24 ;
goto V_143;
}
break;
case V_146 :
if ( V_83 || V_136 ) {
V_47 = - V_86 ;
F_38 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_143;
}
V_136 = F_62 ( & args [ 0 ] ) ;
if ( ! V_136 ) {
V_47 = - V_24 ;
goto V_143;
}
break;
case V_147 :
break;
default:
V_47 = - V_86 ;
F_38 ( V_61 L_24 ) ;
goto V_143;
}
}
V_47 = - V_24 ;
V_81 -> V_90 = F_46 ( V_148 , sizeof( char * ) , V_91 ) ;
if ( ! V_81 -> V_90 )
goto V_143;
V_81 -> V_93 = F_46 ( V_148 , sizeof( int ) , V_91 ) ;
if ( ! V_81 -> V_93 ) {
F_28 ( V_81 -> V_90 ) ;
goto V_143;
}
if ( V_137 ) {
V_81 -> V_90 [ V_89 ] = V_137 ;
V_81 -> V_93 [ V_89 ++ ] = V_94 ;
}
if ( V_83 ) {
V_81 -> V_90 [ V_89 ] = V_83 ;
V_81 -> V_93 [ V_89 ++ ] = V_95 ;
}
if ( V_138 ) {
V_81 -> V_90 [ V_89 ] = V_138 ;
V_81 -> V_93 [ V_89 ++ ] = V_97 ;
}
if ( V_136 ) {
V_81 -> V_90 [ V_89 ] = V_136 ;
V_81 -> V_93 [ V_89 ++ ] = V_96 ;
}
V_81 -> V_89 = V_89 ;
return 0 ;
V_143:
F_28 ( V_83 ) ;
F_28 ( V_136 ) ;
F_28 ( V_137 ) ;
F_28 ( V_138 ) ;
return V_47 ;
}
static int F_63 ( struct V_41 * V_42 , void * V_149 )
{
int V_47 = 0 ;
char * V_134 = V_149 ;
struct V_80 V_81 ;
F_45 ( & V_81 ) ;
if ( ! V_149 )
goto V_66;
F_48 ( V_42 -> V_63 -> V_109 & V_110 ) ;
V_47 = F_59 ( V_134 , & V_81 ) ;
if ( V_47 )
goto V_143;
V_66:
V_47 = F_51 ( V_42 , & V_81 ) ;
V_143:
F_49 ( & V_81 ) ;
return V_47 ;
}
static void F_64 ( struct V_150 * V_151 ,
struct V_80 * V_81 )
{
int V_82 ;
char * V_152 ;
for ( V_82 = 0 ; V_82 < V_81 -> V_89 ; V_82 ++ ) {
char * V_153 ;
if ( V_81 -> V_90 [ V_82 ] )
V_153 = strchr ( V_81 -> V_90 [ V_82 ] , ',' ) ;
else
V_153 = NULL ;
switch ( V_81 -> V_93 [ V_82 ] ) {
case V_95 :
V_152 = V_154 ;
break;
case V_94 :
V_152 = V_155 ;
break;
case V_97 :
V_152 = V_156 ;
break;
case V_96 :
V_152 = V_157 ;
break;
case V_71 :
F_65 ( V_151 , ',' ) ;
F_66 ( V_151 , V_158 ) ;
continue;
default:
F_67 () ;
return;
} ;
F_65 ( V_151 , ',' ) ;
F_66 ( V_151 , V_152 ) ;
if ( V_153 )
F_65 ( V_151 , '\"' ) ;
F_66 ( V_151 , V_81 -> V_90 [ V_82 ] ) ;
if ( V_153 )
F_65 ( V_151 , '\"' ) ;
}
}
static int F_68 ( struct V_150 * V_151 , struct V_41 * V_42 )
{
struct V_80 V_81 ;
int V_47 ;
V_47 = F_44 ( V_42 , & V_81 ) ;
if ( V_47 ) {
if ( V_47 == - V_86 )
V_47 = 0 ;
return V_47 ;
}
F_64 ( V_151 , & V_81 ) ;
F_49 ( & V_81 ) ;
return V_47 ;
}
static inline T_4 F_69 ( T_5 V_159 )
{
switch ( V_159 & V_160 ) {
case V_161 :
return V_162 ;
case V_163 :
return V_164 ;
case V_165 :
return V_29 ;
case V_166 :
return V_167 ;
case V_168 :
return V_169 ;
case V_170 :
return V_171 ;
case V_172 :
return V_173 ;
}
return V_29 ;
}
static inline int F_70 ( int V_174 )
{
return ( V_174 == V_175 || V_174 == V_176 ) ;
}
static inline int F_71 ( int V_174 )
{
return ( V_174 == V_175 || V_174 == V_177 ) ;
}
static inline T_4 F_72 ( int V_178 , int type , int V_174 )
{
switch ( V_178 ) {
case V_179 :
switch ( type ) {
case V_180 :
case V_181 :
return V_182 ;
case V_183 :
return V_184 ;
}
break;
case V_185 :
case V_186 :
switch ( type ) {
case V_180 :
if ( F_70 ( V_174 ) )
return V_187 ;
else
return V_188 ;
case V_183 :
if ( F_71 ( V_174 ) )
return V_189 ;
else
return V_188 ;
case V_190 :
return V_191 ;
default:
return V_188 ;
}
break;
case V_192 :
switch ( V_174 ) {
case V_193 :
return V_194 ;
case V_195 :
return V_196 ;
case V_197 :
return V_198 ;
case V_199 :
return V_200 ;
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
default:
return V_213 ;
}
case V_214 :
return V_215 ;
case V_216 :
return V_217 ;
case V_218 :
return V_219 ;
}
return V_220 ;
}
static int F_73 ( struct V_52 * V_52 ,
T_4 V_221 ,
T_2 * V_14 )
{
int V_47 ;
char * V_222 , * V_223 ;
V_222 = ( char * ) F_74 ( V_12 ) ;
if ( ! V_222 )
return - V_24 ;
V_223 = F_75 ( V_52 , V_222 , V_224 ) ;
if ( F_76 ( V_223 ) )
V_47 = F_77 ( V_223 ) ;
else {
while ( V_223 [ 1 ] >= '0' && V_223 [ 1 ] <= '9' ) {
V_223 [ 1 ] = '/' ;
V_223 ++ ;
}
V_47 = F_78 ( L_14 , V_223 , V_221 , V_14 ) ;
}
F_79 ( ( unsigned long ) V_222 ) ;
return V_47 ;
}
static int F_73 ( struct V_52 * V_52 ,
T_4 V_221 ,
T_2 * V_14 )
{
return - V_86 ;
}
static int F_33 ( struct V_19 * V_19 , struct V_52 * V_225 )
{
struct V_31 * V_32 = NULL ;
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_14 ;
struct V_52 * V_52 ;
#define F_80 255
char * V_83 = NULL ;
unsigned V_84 = 0 ;
int V_47 = 0 ;
if ( V_21 -> V_114 )
goto V_66;
F_53 ( & V_21 -> V_25 ) ;
if ( V_21 -> V_114 )
goto V_226;
V_32 = V_19 -> V_33 -> V_34 ;
if ( ! ( V_32 -> V_69 & V_70 ) ) {
F_21 ( & V_32 -> V_35 ) ;
if ( F_22 ( & V_21 -> V_26 ) )
F_81 ( & V_21 -> V_26 , & V_32 -> V_43 ) ;
F_24 ( & V_32 -> V_35 ) ;
goto V_226;
}
switch ( V_32 -> V_57 ) {
case V_58 :
if ( ! V_19 -> V_59 -> V_60 ) {
V_21 -> V_14 = V_32 -> V_44 ;
break;
}
if ( V_225 ) {
V_52 = F_82 ( V_225 ) ;
} else {
V_52 = F_83 ( V_19 ) ;
}
if ( ! V_52 ) {
goto V_226;
}
V_84 = F_80 ;
V_83 = F_84 ( V_84 + 1 , V_23 ) ;
if ( ! V_83 ) {
V_47 = - V_24 ;
F_85 ( V_52 ) ;
goto V_226;
}
V_83 [ V_84 ] = '\0' ;
V_47 = V_19 -> V_59 -> V_60 ( V_52 , V_67 ,
V_83 , V_84 ) ;
if ( V_47 == - V_227 ) {
F_28 ( V_83 ) ;
V_47 = V_19 -> V_59 -> V_60 ( V_52 , V_67 ,
NULL , 0 ) ;
if ( V_47 < 0 ) {
F_85 ( V_52 ) ;
goto V_226;
}
V_84 = V_47 ;
V_83 = F_84 ( V_84 + 1 , V_23 ) ;
if ( ! V_83 ) {
V_47 = - V_24 ;
F_85 ( V_52 ) ;
goto V_226;
}
V_83 [ V_84 ] = '\0' ;
V_47 = V_19 -> V_59 -> V_60 ( V_52 ,
V_67 ,
V_83 , V_84 ) ;
}
F_85 ( V_52 ) ;
if ( V_47 < 0 ) {
if ( V_47 != - V_68 ) {
F_38 ( V_61 L_25
L_26 , V_113 ,
- V_47 , V_19 -> V_33 -> V_62 , V_19 -> V_228 ) ;
F_28 ( V_83 ) ;
goto V_226;
}
V_14 = V_32 -> V_44 ;
V_47 = 0 ;
} else {
V_47 = F_86 ( V_83 , V_47 , & V_14 ,
V_32 -> V_44 ,
V_23 ) ;
if ( V_47 ) {
char * V_229 = V_19 -> V_33 -> V_62 ;
unsigned long V_230 = V_19 -> V_228 ;
if ( V_47 == - V_86 ) {
if ( F_87 () )
F_38 ( V_231 L_27
L_28
L_29 , V_230 , V_229 , V_83 ) ;
} else {
F_38 ( V_61 L_30
L_31 ,
V_113 , V_83 , - V_47 , V_229 , V_230 ) ;
}
F_28 ( V_83 ) ;
V_47 = 0 ;
break;
}
}
F_28 ( V_83 ) ;
V_21 -> V_14 = V_14 ;
break;
case V_232 :
V_21 -> V_14 = V_21 -> F_10 ;
break;
case V_233 :
V_21 -> V_14 = V_32 -> V_14 ;
V_21 -> V_28 = F_69 ( V_19 -> V_234 ) ;
V_47 = F_88 ( V_21 -> F_10 , V_32 -> V_14 ,
V_21 -> V_28 , NULL , & V_14 ) ;
if ( V_47 )
goto V_226;
V_21 -> V_14 = V_14 ;
break;
case V_76 :
V_21 -> V_14 = V_32 -> V_46 ;
break;
default:
V_21 -> V_14 = V_32 -> V_14 ;
if ( ( V_32 -> V_69 & V_112 ) && ! F_89 ( V_19 -> V_234 ) ) {
if ( V_225 ) {
V_21 -> V_28 = F_69 ( V_19 -> V_234 ) ;
V_47 = F_73 ( V_225 ,
V_21 -> V_28 ,
& V_14 ) ;
if ( V_47 )
goto V_226;
V_21 -> V_14 = V_14 ;
}
}
break;
}
V_21 -> V_114 = 1 ;
V_226:
F_56 ( & V_21 -> V_25 ) ;
V_66:
if ( V_21 -> V_28 == V_29 )
V_21 -> V_28 = F_69 ( V_19 -> V_234 ) ;
return V_47 ;
}
static inline T_2 F_90 ( int V_235 )
{
T_2 V_236 = 0 ;
switch ( V_235 ) {
case V_237 :
V_236 = V_238 ;
break;
case V_239 :
V_236 = V_240 ;
break;
case V_241 :
V_236 = V_242 ;
break;
default:
V_236 = V_243 ;
break;
}
return V_236 ;
}
static int F_91 ( const struct V_7 * V_244 ,
const struct V_7 * V_245 ,
T_2 V_246 )
{
T_2 V_247 = F_9 ( V_244 ) , V_248 = F_9 ( V_245 ) ;
return F_35 ( V_247 , V_248 , V_249 , V_246 , NULL ) ;
}
static int F_92 ( const struct V_17 * V_250 ,
const struct V_17 * V_251 ,
T_2 V_246 )
{
const struct V_10 * V_252 , * V_253 ;
T_2 V_254 , V_255 ;
F_11 () ;
V_252 = F_12 ( V_250 ) -> V_16 ; V_254 = V_252 -> V_14 ;
V_253 = F_12 ( V_251 ) -> V_16 ; V_255 = V_253 -> V_14 ;
F_13 () ;
return F_35 ( V_254 , V_255 , V_249 , V_246 , NULL ) ;
}
static int F_93 ( const struct V_17 * V_256 ,
T_2 V_246 )
{
T_2 V_14 , V_248 ;
V_14 = F_14 () ;
V_248 = F_10 ( V_256 ) ;
return F_35 ( V_14 , V_248 , V_249 , V_246 , NULL ) ;
}
static int F_94 ( const struct V_7 * V_7 ,
int V_257 , int V_258 )
{
struct V_259 V_260 ;
struct V_261 V_262 ;
T_4 V_28 ;
T_2 V_14 = F_9 ( V_7 ) ;
T_2 V_263 = F_95 ( V_257 ) ;
int V_47 ;
V_260 . type = V_264 ;
V_260 . V_265 . V_257 = V_257 ;
switch ( F_96 ( V_257 ) ) {
case 0 :
V_28 = V_266 ;
break;
case 1 :
V_28 = V_267 ;
break;
default:
F_38 ( V_73
L_32 , V_257 ) ;
F_67 () ;
return - V_86 ;
}
V_47 = F_97 ( V_14 , V_14 , V_28 , V_263 , 0 , & V_262 ) ;
if ( V_258 == V_268 ) {
int V_269 = F_98 ( V_14 , V_14 , V_28 , V_263 , & V_262 , V_47 , & V_260 , 0 ) ;
if ( V_269 )
return V_269 ;
}
return V_47 ;
}
static int F_99 ( struct V_17 * V_256 ,
T_2 V_246 )
{
T_2 V_14 = F_10 ( V_256 ) ;
return F_35 ( V_14 , V_15 ,
V_270 , V_246 , NULL ) ;
}
static int F_100 ( const struct V_7 * V_7 ,
struct V_19 * V_19 ,
T_2 V_246 ,
struct V_259 * V_271 ,
unsigned V_69 )
{
struct V_20 * V_21 ;
T_2 V_14 ;
F_101 ( V_7 ) ;
if ( F_102 ( F_42 ( V_19 ) ) )
return 0 ;
V_14 = F_9 ( V_7 ) ;
V_21 = V_19 -> V_30 ;
return F_103 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_246 , V_271 , V_69 ) ;
}
static inline int F_104 ( const struct V_7 * V_7 ,
struct V_52 * V_52 ,
T_2 V_263 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_259 V_260 ;
V_260 . type = V_272 ;
V_260 . V_265 . V_52 = V_52 ;
return F_100 ( V_7 , V_19 , V_263 , & V_260 , 0 ) ;
}
static inline int F_105 ( const struct V_7 * V_7 ,
struct V_223 * V_223 ,
T_2 V_263 )
{
struct V_19 * V_19 = V_223 -> V_52 -> V_56 ;
struct V_259 V_260 ;
V_260 . type = V_273 ;
V_260 . V_265 . V_223 = * V_223 ;
return F_100 ( V_7 , V_19 , V_263 , & V_260 , 0 ) ;
}
static int F_106 ( const struct V_7 * V_7 ,
struct V_36 * V_36 ,
T_2 V_263 )
{
struct V_37 * V_38 = V_36 -> V_40 ;
struct V_19 * V_19 = F_107 ( V_36 ) ;
struct V_259 V_260 ;
T_2 V_14 = F_9 ( V_7 ) ;
int V_47 ;
V_260 . type = V_273 ;
V_260 . V_265 . V_223 = V_36 -> V_274 ;
if ( V_14 != V_38 -> V_14 ) {
V_47 = F_35 ( V_14 , V_38 -> V_14 ,
V_275 ,
V_276 ,
& V_260 ) ;
if ( V_47 )
goto V_66;
}
V_47 = 0 ;
if ( V_263 )
V_47 = F_100 ( V_7 , V_19 , V_263 , & V_260 , 0 ) ;
V_66:
return V_47 ;
}
static int F_108 ( struct V_19 * V_277 ,
struct V_52 * V_52 ,
T_4 V_221 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_278 ;
struct V_31 * V_32 ;
T_2 V_14 , V_279 ;
struct V_259 V_260 ;
int V_47 ;
V_278 = V_277 -> V_30 ;
V_32 = V_277 -> V_33 -> V_34 ;
V_14 = V_11 -> V_14 ;
V_279 = V_11 -> V_280 ;
V_260 . type = V_272 ;
V_260 . V_265 . V_52 = V_52 ;
V_47 = F_35 ( V_14 , V_278 -> V_14 , V_169 ,
V_281 | V_282 ,
& V_260 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_279 || ! ( V_32 -> V_69 & V_71 ) ) {
V_47 = F_88 ( V_14 , V_278 -> V_14 , V_221 ,
& V_52 -> V_283 , & V_279 ) ;
if ( V_47 )
return V_47 ;
}
V_47 = F_35 ( V_14 , V_279 , V_221 , V_284 , & V_260 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_279 , V_32 -> V_14 ,
V_48 ,
V_51 , & V_260 ) ;
}
static int F_109 ( T_2 V_285 ,
struct V_17 * V_286 )
{
T_2 V_14 = F_10 ( V_286 ) ;
return F_35 ( V_14 , V_285 , V_287 , V_288 , NULL ) ;
}
static int F_110 ( struct V_19 * V_277 ,
struct V_52 * V_52 ,
int V_289 )
{
struct V_20 * V_278 , * V_21 ;
struct V_259 V_260 ;
T_2 V_14 = F_14 () ;
T_2 V_263 ;
int V_47 ;
V_278 = V_277 -> V_30 ;
V_21 = V_52 -> V_56 -> V_30 ;
V_260 . type = V_272 ;
V_260 . V_265 . V_52 = V_52 ;
V_263 = V_282 ;
V_263 |= ( V_289 ? V_290 : V_281 ) ;
V_47 = F_35 ( V_14 , V_278 -> V_14 , V_169 , V_263 , & V_260 ) ;
if ( V_47 )
return V_47 ;
switch ( V_289 ) {
case V_291 :
V_263 = V_292 ;
break;
case V_293 :
V_263 = V_294 ;
break;
case V_295 :
V_263 = V_296 ;
break;
default:
F_38 ( V_61 L_33 ,
V_113 , V_289 ) ;
return 0 ;
}
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_263 , & V_260 ) ;
return V_47 ;
}
static inline int F_111 ( struct V_19 * V_297 ,
struct V_52 * V_298 ,
struct V_19 * V_299 ,
struct V_52 * V_300 )
{
struct V_20 * V_301 , * V_302 , * V_303 , * V_304 ;
struct V_259 V_260 ;
T_2 V_14 = F_14 () ;
T_2 V_263 ;
int V_305 , V_306 ;
int V_47 ;
V_301 = V_297 -> V_30 ;
V_303 = V_298 -> V_56 -> V_30 ;
V_305 = F_112 ( V_298 -> V_56 -> V_234 ) ;
V_302 = V_299 -> V_30 ;
V_260 . type = V_272 ;
V_260 . V_265 . V_52 = V_298 ;
V_47 = F_35 ( V_14 , V_301 -> V_14 , V_169 ,
V_290 | V_282 , & V_260 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_14 , V_303 -> V_14 ,
V_303 -> V_28 , V_307 , & V_260 ) ;
if ( V_47 )
return V_47 ;
if ( V_305 && V_299 != V_297 ) {
V_47 = F_35 ( V_14 , V_303 -> V_14 ,
V_303 -> V_28 , V_308 , & V_260 ) ;
if ( V_47 )
return V_47 ;
}
V_260 . V_265 . V_52 = V_300 ;
V_263 = V_281 | V_282 ;
if ( V_300 -> V_56 )
V_263 |= V_290 ;
V_47 = F_35 ( V_14 , V_302 -> V_14 , V_169 , V_263 , & V_260 ) ;
if ( V_47 )
return V_47 ;
if ( V_300 -> V_56 ) {
V_304 = V_300 -> V_56 -> V_30 ;
V_306 = F_112 ( V_300 -> V_56 -> V_234 ) ;
V_47 = F_35 ( V_14 , V_304 -> V_14 ,
V_304 -> V_28 ,
( V_306 ? V_296 : V_294 ) , & V_260 ) ;
if ( V_47 )
return V_47 ;
}
return 0 ;
}
static int F_113 ( const struct V_7 * V_7 ,
struct V_41 * V_42 ,
T_2 V_246 ,
struct V_259 * V_260 )
{
struct V_31 * V_32 ;
T_2 V_14 = F_9 ( V_7 ) ;
V_32 = V_42 -> V_34 ;
return F_35 ( V_14 , V_32 -> V_14 , V_48 , V_246 , V_260 ) ;
}
static inline T_2 F_114 ( int V_159 , int V_309 )
{
T_2 V_263 = 0 ;
if ( ! F_112 ( V_159 ) ) {
if ( V_309 & V_310 )
V_263 |= V_311 ;
if ( V_309 & V_312 )
V_263 |= V_313 ;
if ( V_309 & V_314 )
V_263 |= V_315 ;
else if ( V_309 & V_316 )
V_263 |= V_317 ;
} else {
if ( V_309 & V_310 )
V_263 |= V_282 ;
if ( V_309 & V_316 )
V_263 |= V_318 ;
if ( V_309 & V_312 )
V_263 |= V_319 ;
}
return V_263 ;
}
static inline T_2 F_115 ( struct V_36 * V_36 )
{
T_2 V_263 = 0 ;
if ( V_36 -> V_320 & V_321 )
V_263 |= V_313 ;
if ( V_36 -> V_320 & V_322 ) {
if ( V_36 -> V_323 & V_324 )
V_263 |= V_315 ;
else
V_263 |= V_317 ;
}
if ( ! V_263 ) {
V_263 = V_325 ;
}
return V_263 ;
}
static inline T_2 F_116 ( struct V_36 * V_36 )
{
T_2 V_263 = F_115 ( V_36 ) ;
if ( V_326 )
V_263 |= V_327 ;
return V_263 ;
}
static int F_117 ( struct V_17 * V_328 ,
unsigned int V_159 )
{
int V_47 ;
V_47 = F_118 ( V_328 , V_159 ) ;
if ( V_47 )
return V_47 ;
if ( V_159 & V_329 ) {
T_2 V_14 = F_14 () ;
T_2 V_330 = F_10 ( V_328 ) ;
return F_35 ( V_14 , V_330 , V_29 , V_313 , NULL ) ;
}
return F_93 ( V_328 , V_331 ) ;
}
static int F_119 ( struct V_17 * V_332 )
{
int V_47 ;
V_47 = F_120 ( V_332 ) ;
if ( V_47 )
return V_47 ;
return F_92 ( V_332 , V_8 , V_331 ) ;
}
static int F_121 ( struct V_17 * V_245 , T_6 * V_333 ,
T_6 * V_334 , T_6 * V_335 )
{
int error ;
error = F_93 ( V_245 , V_336 ) ;
if ( error )
return error ;
return F_122 ( V_245 , V_333 , V_334 , V_335 ) ;
}
static int F_123 ( struct V_7 * V_118 , const struct V_7 * V_117 ,
const T_6 * V_333 ,
const T_6 * V_334 ,
const T_6 * V_335 )
{
int error ;
error = F_124 ( V_118 , V_117 ,
V_333 , V_334 , V_335 ) ;
if ( error )
return error ;
return F_91 ( V_117 , V_118 , V_337 ) ;
}
static int F_125 ( const struct V_7 * V_7 , struct V_338 * V_339 ,
int V_257 , int V_258 )
{
int V_47 ;
V_47 = F_126 ( V_7 , V_339 , V_257 , V_258 ) ;
if ( V_47 )
return V_47 ;
return F_94 ( V_7 , V_257 , V_258 ) ;
}
static int F_127 ( int V_340 , int type , int V_341 , struct V_41 * V_42 )
{
const struct V_7 * V_7 = F_52 () ;
int V_47 = 0 ;
if ( ! V_42 )
return 0 ;
switch ( V_340 ) {
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
V_47 = F_113 ( V_7 , V_42 , V_347 , NULL ) ;
break;
case V_348 :
case V_349 :
case V_350 :
V_47 = F_113 ( V_7 , V_42 , V_351 , NULL ) ;
break;
default:
V_47 = 0 ;
break;
}
return V_47 ;
}
static int F_128 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
return F_104 ( V_7 , V_52 , V_352 ) ;
}
static int F_129 ( int type )
{
int V_47 ;
switch ( type ) {
case V_353 :
case V_354 :
V_47 = F_99 ( V_8 , V_355 ) ;
break;
case V_356 :
case V_357 :
case V_358 :
V_47 = F_99 ( V_8 , V_359 ) ;
break;
case V_360 :
case V_361 :
case V_362 :
case V_363 :
case V_364 :
default:
V_47 = F_99 ( V_8 , V_365 ) ;
break;
}
return V_47 ;
}
static int F_130 ( struct V_366 * V_367 , long V_368 )
{
int V_47 , V_369 = 0 ;
V_47 = F_125 ( F_52 () , & V_370 , V_371 ,
V_372 ) ;
if ( V_47 == 0 )
V_369 = 1 ;
return F_131 ( V_367 , V_368 , V_369 ) ;
}
static int F_132 ( struct V_373 * V_374 )
{
const struct V_10 * V_375 ;
struct V_10 * V_376 ;
struct V_20 * V_21 ;
struct V_259 V_260 ;
struct V_19 * V_19 = F_107 ( V_374 -> V_36 ) ;
int V_47 ;
V_47 = F_133 ( V_374 ) ;
if ( V_47 )
return V_47 ;
if ( V_374 -> V_377 )
return 0 ;
V_375 = F_15 () ;
V_376 = V_374 -> V_7 -> V_16 ;
V_21 = V_19 -> V_30 ;
V_376 -> V_14 = V_375 -> V_14 ;
V_376 -> V_13 = V_375 -> V_14 ;
V_376 -> V_280 = 0 ;
V_376 -> V_378 = 0 ;
V_376 -> V_379 = 0 ;
if ( V_375 -> V_380 ) {
V_376 -> V_14 = V_375 -> V_380 ;
V_376 -> V_380 = 0 ;
if ( V_374 -> V_381 & V_382 )
return - V_383 ;
} else {
V_47 = F_88 ( V_375 -> V_14 , V_21 -> V_14 ,
V_249 , NULL ,
& V_376 -> V_14 ) ;
if ( V_47 )
return V_47 ;
}
V_260 . type = V_273 ;
V_260 . V_265 . V_223 = V_374 -> V_36 -> V_274 ;
if ( ( V_374 -> V_36 -> V_274 . V_384 -> V_101 & V_385 ) ||
( V_374 -> V_381 & V_382 ) )
V_376 -> V_14 = V_375 -> V_14 ;
if ( V_376 -> V_14 == V_375 -> V_14 ) {
V_47 = F_35 ( V_375 -> V_14 , V_21 -> V_14 ,
V_29 , V_386 , & V_260 ) ;
if ( V_47 )
return V_47 ;
} else {
V_47 = F_35 ( V_375 -> V_14 , V_376 -> V_14 ,
V_249 , V_387 , & V_260 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_376 -> V_14 , V_21 -> V_14 ,
V_29 , V_388 , & V_260 ) ;
if ( V_47 )
return V_47 ;
if ( V_374 -> V_381 & V_389 ) {
V_47 = F_35 ( V_375 -> V_14 , V_376 -> V_14 ,
V_249 , V_390 ,
NULL ) ;
if ( V_47 )
return - V_383 ;
}
if ( V_374 -> V_381 &
( V_391 | V_392 ) ) {
struct V_17 * V_393 ;
struct V_10 * V_394 ;
T_2 V_395 = 0 ;
F_11 () ;
V_393 = F_134 ( V_8 ) ;
if ( F_135 ( V_393 != NULL ) ) {
V_394 = F_12 ( V_393 ) -> V_16 ;
V_395 = V_394 -> V_14 ;
}
F_13 () ;
if ( V_395 != 0 ) {
V_47 = F_35 ( V_395 , V_376 -> V_14 ,
V_249 ,
V_331 , NULL ) ;
if ( V_47 )
return - V_383 ;
}
}
V_374 -> V_396 |= V_397 ;
}
return 0 ;
}
static int F_136 ( struct V_373 * V_374 )
{
const struct V_10 * V_11 = F_15 () ;
T_2 V_14 , V_13 ;
int V_398 = 0 ;
V_14 = V_11 -> V_14 ;
V_13 = V_11 -> V_13 ;
if ( V_13 != V_14 ) {
V_398 = F_35 ( V_13 , V_14 ,
V_249 ,
V_399 , NULL ) ;
}
return ( V_398 || F_137 ( V_374 ) ) ;
}
static int F_138 ( const void * V_135 , struct V_36 * V_36 , unsigned V_400 )
{
return F_106 ( V_135 , V_36 , F_115 ( V_36 ) ) ? V_400 + 1 : 0 ;
}
static inline void F_139 ( const struct V_7 * V_7 ,
struct V_401 * V_402 )
{
struct V_36 * V_36 , * V_403 = NULL ;
struct V_404 * V_405 ;
int V_406 = 0 ;
unsigned V_407 ;
V_405 = F_140 () ;
if ( V_405 ) {
F_21 ( & V_408 ) ;
if ( ! F_22 ( & V_405 -> V_409 ) ) {
struct V_410 * V_411 ;
V_411 = F_141 ( & V_405 -> V_409 ,
struct V_410 , V_26 ) ;
V_36 = V_411 -> V_36 ;
if ( F_105 ( V_7 , & V_36 -> V_274 , V_313 | V_317 ) )
V_406 = 1 ;
}
F_24 ( & V_408 ) ;
F_142 ( V_405 ) ;
}
if ( V_406 )
F_143 () ;
V_407 = F_144 ( V_402 , 0 , F_138 , V_7 ) ;
if ( ! V_407 )
return;
V_403 = F_145 ( & V_412 , V_413 , V_7 ) ;
if ( F_76 ( V_403 ) )
V_403 = NULL ;
do {
F_146 ( V_407 - 1 , V_403 , 0 ) ;
} while ( ( V_407 = F_144 ( V_402 , V_407 , F_138 , V_7 ) ) != 0 );
if ( V_403 )
F_147 ( V_403 ) ;
}
static void F_148 ( struct V_373 * V_374 )
{
struct V_10 * V_376 ;
struct V_414 * V_415 , * V_416 ;
int V_47 , V_82 ;
V_376 = V_374 -> V_7 -> V_16 ;
if ( V_376 -> V_14 == V_376 -> V_13 )
return;
F_139 ( V_374 -> V_7 , V_8 -> V_402 ) ;
V_8 -> V_417 = 0 ;
V_47 = F_35 ( V_376 -> V_13 , V_376 -> V_14 , V_249 ,
V_418 , NULL ) ;
if ( V_47 ) {
F_149 ( V_8 ) ;
for ( V_82 = 0 ; V_82 < V_419 ; V_82 ++ ) {
V_415 = V_8 -> signal -> V_415 + V_82 ;
V_416 = V_420 . signal -> V_415 + V_82 ;
V_415 -> V_421 = F_150 ( V_415 -> V_422 , V_416 -> V_421 ) ;
}
F_151 ( V_8 ) ;
F_152 ( V_8 , V_414 ( V_423 ) ) ;
}
}
static void F_153 ( struct V_373 * V_374 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_424 V_425 ;
T_2 V_13 , V_14 ;
int V_47 , V_82 ;
V_13 = V_11 -> V_13 ;
V_14 = V_11 -> V_14 ;
if ( V_14 == V_13 )
return;
V_47 = F_35 ( V_13 , V_14 , V_249 , V_426 , NULL ) ;
if ( V_47 ) {
memset ( & V_425 , 0 , sizeof V_425 ) ;
for ( V_82 = 0 ; V_82 < 3 ; V_82 ++ )
F_154 ( V_82 , & V_425 , NULL ) ;
F_155 ( & V_8 -> V_427 -> V_428 ) ;
if ( ! ( V_8 -> signal -> V_69 & V_429 ) ) {
F_156 ( V_8 ) ;
F_157 ( V_8 , 1 ) ;
F_158 ( & V_8 -> V_430 ) ;
}
F_159 ( & V_8 -> V_427 -> V_428 ) ;
}
F_160 ( & V_431 ) ;
F_161 ( V_8 , V_8 -> V_432 ) ;
F_162 ( & V_431 ) ;
}
static int F_163 ( struct V_41 * V_42 )
{
return F_29 ( V_42 ) ;
}
static void F_164 ( struct V_41 * V_42 )
{
F_31 ( V_42 ) ;
}
static inline int F_165 ( char * V_152 , int V_433 , char * V_434 , int V_435 )
{
if ( V_433 > V_435 )
return 0 ;
return ! memcmp ( V_152 , V_434 , V_433 ) ;
}
static inline int F_166 ( char * V_434 , int V_84 )
{
return ( F_165 ( V_154 , sizeof( V_154 ) - 1 , V_434 , V_84 ) ||
F_165 ( V_155 , sizeof( V_155 ) - 1 , V_434 , V_84 ) ||
F_165 ( V_157 , sizeof( V_157 ) - 1 , V_434 , V_84 ) ||
F_165 ( V_156 , sizeof( V_156 ) - 1 , V_434 , V_84 ) ||
F_165 ( V_158 , sizeof( V_158 ) - 1 , V_434 , V_84 ) ) ;
}
static inline void F_167 ( char * * V_436 , char * V_437 , int * V_438 , int V_84 )
{
if ( ! * V_438 ) {
* * V_436 = ',' ;
* V_436 += 1 ;
} else
* V_438 = 0 ;
memcpy ( * V_436 , V_437 , V_84 ) ;
* V_436 += V_84 ;
}
static inline void F_168 ( char * * V_436 , char * V_437 , int * V_438 ,
int V_84 )
{
int V_439 = 0 ;
if ( ! * V_438 ) {
* * V_436 = '|' ;
* V_436 += 1 ;
} else
* V_438 = 0 ;
while ( V_439 < V_84 ) {
if ( * V_437 != '"' ) {
* * V_436 = * V_437 ;
* V_436 += 1 ;
}
V_437 += 1 ;
V_439 += 1 ;
}
}
static int F_169 ( char * V_440 , char * V_441 )
{
int V_442 , V_38 , V_47 = 0 ;
char * V_443 , * V_444 , * V_445 ;
char * V_446 , * V_447 , * V_448 ;
int V_449 = 0 ;
V_444 = V_440 ;
V_446 = V_441 ;
V_448 = ( char * ) F_170 ( V_12 ) ;
if ( ! V_448 ) {
V_47 = - V_24 ;
goto V_66;
}
V_447 = V_448 ;
V_442 = V_38 = 1 ;
V_443 = V_445 = V_440 ;
do {
if ( * V_445 == '"' )
V_449 = ! V_449 ;
if ( ( * V_445 == ',' && V_449 == 0 ) ||
* V_445 == '\0' ) {
int V_84 = V_445 - V_444 ;
if ( F_166 ( V_444 , V_84 ) )
F_168 ( & V_446 , V_444 , & V_38 , V_84 ) ;
else
F_167 ( & V_448 , V_444 , & V_442 , V_84 ) ;
V_444 = V_445 + 1 ;
}
} while ( * V_445 ++ );
strcpy ( V_443 , V_447 ) ;
F_79 ( ( unsigned long ) V_447 ) ;
V_66:
return V_47 ;
}
static int F_171 ( struct V_41 * V_42 , void * V_149 )
{
int V_47 , V_82 , * V_69 ;
struct V_80 V_81 ;
char * V_450 , * * V_107 ;
struct V_31 * V_32 = V_42 -> V_34 ;
if ( ! ( V_32 -> V_69 & V_70 ) )
return 0 ;
if ( ! V_149 )
return 0 ;
if ( V_42 -> V_63 -> V_109 & V_110 )
return 0 ;
F_45 ( & V_81 ) ;
V_450 = F_172 () ;
if ( ! V_450 )
return - V_24 ;
V_47 = F_169 ( V_149 , V_450 ) ;
if ( V_47 )
goto V_451;
V_47 = F_59 ( V_450 , & V_81 ) ;
if ( V_47 )
goto V_451;
V_107 = V_81 . V_90 ;
V_69 = V_81 . V_93 ;
for ( V_82 = 0 ; V_82 < V_81 . V_89 ; V_82 ++ ) {
T_2 V_14 ;
T_7 V_84 ;
if ( V_69 [ V_82 ] == V_71 )
continue;
V_84 = strlen ( V_107 [ V_82 ] ) ;
V_47 = F_54 ( V_107 [ V_82 ] , V_84 , & V_14 ) ;
if ( V_47 ) {
F_38 ( V_61 L_12
L_13 ,
V_107 [ V_82 ] , V_42 -> V_62 , V_42 -> V_63 -> V_64 , V_47 ) ;
goto V_452;
}
V_47 = - V_86 ;
switch ( V_69 [ V_82 ] ) {
case V_94 :
if ( F_50 ( V_32 , V_94 , V_32 -> V_14 , V_14 ) )
goto V_453;
break;
case V_95 :
if ( F_50 ( V_32 , V_95 , V_32 -> V_46 , V_14 ) )
goto V_453;
break;
case V_97 : {
struct V_20 * V_102 ;
V_102 = V_42 -> V_54 -> V_56 -> V_30 ;
if ( F_50 ( V_32 , V_97 , V_102 -> V_14 , V_14 ) )
goto V_453;
break;
}
case V_96 :
if ( F_50 ( V_32 , V_96 , V_32 -> V_44 , V_14 ) )
goto V_453;
break;
default:
goto V_452;
}
}
V_47 = 0 ;
V_452:
F_49 ( & V_81 ) ;
V_451:
F_173 ( V_450 ) ;
return V_47 ;
V_453:
F_38 ( V_61 L_34
L_35 , V_42 -> V_62 ,
V_42 -> V_63 -> V_64 ) ;
goto V_452;
}
static int F_174 ( struct V_41 * V_42 , int V_69 , void * V_149 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_259 V_260 ;
int V_47 ;
V_47 = F_63 ( V_42 , V_149 ) ;
if ( V_47 )
return V_47 ;
if ( V_69 & V_454 )
return 0 ;
V_260 . type = V_272 ;
V_260 . V_265 . V_52 = V_42 -> V_54 ;
return F_113 ( V_7 , V_42 , V_455 , & V_260 ) ;
}
static int F_175 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_259 V_260 ;
V_260 . type = V_272 ;
V_260 . V_265 . V_52 = V_52 -> V_456 -> V_54 ;
return F_113 ( V_7 , V_52 -> V_456 , V_457 , & V_260 ) ;
}
static int F_176 ( const char * V_458 ,
struct V_223 * V_223 ,
const char * type ,
unsigned long V_69 ,
void * V_149 )
{
const struct V_7 * V_7 = F_52 () ;
if ( V_69 & V_459 )
return F_113 ( V_7 , V_223 -> V_52 -> V_456 ,
V_460 , NULL ) ;
else
return F_105 ( V_7 , V_223 , V_461 ) ;
}
static int F_177 ( struct V_462 * V_384 , int V_69 )
{
const struct V_7 * V_7 = F_52 () ;
return F_113 ( V_7 , V_384 -> V_463 ,
V_464 , NULL ) ;
}
static int F_178 ( struct V_19 * V_19 )
{
return F_16 ( V_19 ) ;
}
static void F_179 ( struct V_19 * V_19 )
{
F_20 ( V_19 ) ;
}
static int F_180 ( struct V_19 * V_19 , struct V_19 * V_277 ,
const struct V_465 * V_465 , char * * V_64 ,
void * * V_466 , T_7 * V_84 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_278 ;
struct V_31 * V_32 ;
T_2 V_14 , V_279 , V_467 ;
int V_47 ;
char * V_468 = NULL , * V_83 ;
V_278 = V_277 -> V_30 ;
V_32 = V_277 -> V_33 -> V_34 ;
V_14 = V_11 -> V_14 ;
V_279 = V_11 -> V_280 ;
if ( ( V_32 -> V_69 & V_70 ) &&
( V_32 -> V_57 == V_76 ) )
V_279 = V_32 -> V_46 ;
else if ( ! V_279 || ! ( V_32 -> V_69 & V_71 ) ) {
V_47 = F_88 ( V_14 , V_278 -> V_14 ,
F_69 ( V_19 -> V_234 ) ,
V_465 , & V_279 ) ;
if ( V_47 ) {
F_38 ( V_61 L_36
L_37
L_38 ,
V_113 ,
- V_47 , V_19 -> V_33 -> V_62 , V_19 -> V_228 ) ;
return V_47 ;
}
}
if ( V_32 -> V_69 & V_70 ) {
struct V_20 * V_21 = V_19 -> V_30 ;
V_21 -> V_28 = F_69 ( V_19 -> V_234 ) ;
V_21 -> V_14 = V_279 ;
V_21 -> V_114 = 1 ;
}
if ( ! V_87 || ! ( V_32 -> V_69 & V_71 ) )
return - V_65 ;
if ( V_64 ) {
V_468 = F_181 ( V_469 , V_23 ) ;
if ( ! V_468 )
return - V_24 ;
* V_64 = V_468 ;
}
if ( V_466 && V_84 ) {
V_47 = F_182 ( V_279 , & V_83 , & V_467 ) ;
if ( V_47 ) {
F_28 ( V_468 ) ;
return V_47 ;
}
* V_466 = V_83 ;
* V_84 = V_467 ;
}
return 0 ;
}
static int F_183 ( struct V_19 * V_277 , struct V_52 * V_52 , T_5 V_159 )
{
return F_108 ( V_277 , V_52 , V_29 ) ;
}
static int F_184 ( struct V_52 * V_298 , struct V_19 * V_277 , struct V_52 * V_300 )
{
return F_110 ( V_277 , V_298 , V_291 ) ;
}
static int F_185 ( struct V_19 * V_277 , struct V_52 * V_52 )
{
return F_110 ( V_277 , V_52 , V_293 ) ;
}
static int F_186 ( struct V_19 * V_277 , struct V_52 * V_52 , const char * V_64 )
{
return F_108 ( V_277 , V_52 , V_164 ) ;
}
static int F_187 ( struct V_19 * V_277 , struct V_52 * V_52 , T_5 V_309 )
{
return F_108 ( V_277 , V_52 , V_169 ) ;
}
static int F_188 ( struct V_19 * V_277 , struct V_52 * V_52 )
{
return F_110 ( V_277 , V_52 , V_295 ) ;
}
static int F_189 ( struct V_19 * V_277 , struct V_52 * V_52 , T_5 V_159 , T_8 V_229 )
{
return F_108 ( V_277 , V_52 , F_69 ( V_159 ) ) ;
}
static int F_190 ( struct V_19 * V_470 , struct V_52 * V_298 ,
struct V_19 * V_471 , struct V_52 * V_300 )
{
return F_111 ( V_470 , V_298 , V_471 , V_300 ) ;
}
static int F_191 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
return F_104 ( V_7 , V_52 , V_313 ) ;
}
static int F_192 ( struct V_52 * V_52 , struct V_472 * V_472 )
{
const struct V_7 * V_7 = F_52 () ;
return F_104 ( V_7 , V_52 , V_313 ) ;
}
static T_9 int F_193 ( struct V_19 * V_19 ,
T_2 V_246 , T_2 V_473 , T_2 V_474 ,
unsigned V_69 )
{
struct V_259 V_260 ;
struct V_20 * V_21 = V_19 -> V_30 ;
int V_47 ;
V_260 . type = V_475 ;
V_260 . V_265 . V_19 = V_19 ;
V_47 = F_194 ( F_14 () , V_21 -> V_14 , V_21 -> V_28 , V_246 ,
V_473 , V_474 , & V_260 , V_69 ) ;
if ( V_47 )
return V_47 ;
return 0 ;
}
static int F_195 ( struct V_19 * V_19 , int V_309 )
{
const struct V_7 * V_7 = F_52 () ;
T_2 V_246 ;
bool V_476 ;
unsigned V_69 = V_309 & V_477 ;
struct V_20 * V_21 ;
T_2 V_14 ;
struct V_261 V_262 ;
int V_47 , V_269 ;
T_2 V_473 , V_474 ;
V_476 = V_309 & V_478 ;
V_309 &= ( V_312 | V_316 | V_310 | V_314 ) ;
if ( ! V_309 )
return 0 ;
F_101 ( V_7 ) ;
if ( F_102 ( F_42 ( V_19 ) ) )
return 0 ;
V_246 = F_114 ( V_19 -> V_234 , V_309 ) ;
V_14 = F_9 ( V_7 ) ;
V_21 = V_19 -> V_30 ;
V_47 = F_97 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_246 , 0 , & V_262 ) ;
V_473 = F_196 ( V_246 , & V_262 , V_47 ,
V_476 ? V_479 : 0 ,
& V_474 ) ;
if ( F_135 ( ! V_473 ) )
return V_47 ;
V_269 = F_193 ( V_19 , V_246 , V_473 , V_474 , V_69 ) ;
if ( V_269 )
return V_269 ;
return V_47 ;
}
static int F_197 ( struct V_52 * V_52 , struct V_480 * V_480 )
{
const struct V_7 * V_7 = F_52 () ;
unsigned int V_481 = V_480 -> V_481 ;
T_10 V_263 = V_317 ;
if ( V_481 & V_482 ) {
V_481 &= ~ ( V_483 | V_484 | V_485 |
V_482 ) ;
if ( ! V_481 )
return 0 ;
}
if ( V_481 & ( V_485 | V_486 | V_487 |
V_488 | V_489 | V_490 ) )
return F_104 ( V_7 , V_52 , V_491 ) ;
if ( V_326 && ( V_481 & V_492 ) )
V_263 |= V_327 ;
return F_104 ( V_7 , V_52 , V_263 ) ;
}
static int F_198 ( struct V_462 * V_384 , struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_223 V_223 ;
V_223 . V_52 = V_52 ;
V_223 . V_384 = V_384 ;
return F_105 ( V_7 , & V_223 , V_493 ) ;
}
static int F_199 ( struct V_52 * V_52 , const char * V_64 )
{
const struct V_7 * V_7 = F_52 () ;
if ( ! strncmp ( V_64 , V_494 ,
sizeof V_494 - 1 ) ) {
if ( ! strcmp ( V_64 , V_495 ) ) {
if ( ! F_200 ( V_496 ) )
return - V_383 ;
} else if ( ! F_200 ( V_371 ) ) {
return - V_383 ;
}
}
return F_104 ( V_7 , V_52 , V_491 ) ;
}
static int F_201 ( struct V_52 * V_52 , const char * V_64 ,
const void * V_466 , T_7 V_497 , int V_69 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_20 * V_21 = V_19 -> V_30 ;
struct V_31 * V_32 ;
struct V_259 V_260 ;
T_2 V_279 , V_14 = F_14 () ;
int V_47 = 0 ;
if ( strcmp ( V_64 , V_67 ) )
return F_199 ( V_52 , V_64 ) ;
V_32 = V_19 -> V_33 -> V_34 ;
if ( ! ( V_32 -> V_69 & V_71 ) )
return - V_65 ;
if ( ! F_202 ( V_19 ) )
return - V_383 ;
V_260 . type = V_272 ;
V_260 . V_265 . V_52 = V_52 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 ,
V_498 , & V_260 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_54 ( V_466 , V_497 , & V_279 ) ;
if ( V_47 == - V_86 ) {
if ( ! F_200 ( V_499 ) ) {
struct V_500 * V_501 ;
T_7 V_502 ;
const char * V_1 ;
if ( V_466 ) {
V_1 = V_466 ;
if ( V_1 [ V_497 - 1 ] == '\0' )
V_502 = V_497 - 1 ;
else
V_502 = V_497 ;
} else {
V_1 = L_39 ;
V_502 = 0 ;
}
V_501 = F_203 ( V_8 -> V_503 , V_91 , V_504 ) ;
F_204 ( V_501 , L_40 ) ;
F_205 ( V_501 , V_466 , V_502 ) ;
F_206 ( V_501 ) ;
return V_47 ;
}
V_47 = F_207 ( V_466 , V_497 , & V_279 ) ;
}
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_14 , V_279 , V_21 -> V_28 ,
V_505 , & V_260 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_208 ( V_21 -> V_14 , V_279 , V_14 ,
V_21 -> V_28 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_279 ,
V_32 -> V_14 ,
V_48 ,
V_51 ,
& V_260 ) ;
}
static void F_209 ( struct V_52 * V_52 , const char * V_64 ,
const void * V_466 , T_7 V_497 ,
int V_69 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_279 ;
int V_47 ;
if ( strcmp ( V_64 , V_67 ) ) {
return;
}
V_47 = F_207 ( V_466 , V_497 , & V_279 ) ;
if ( V_47 ) {
F_38 ( V_73 L_41
L_42 ,
V_19 -> V_33 -> V_62 , V_19 -> V_228 , - V_47 ) ;
return;
}
V_21 -> V_14 = V_279 ;
return;
}
static int F_210 ( struct V_52 * V_52 , const char * V_64 )
{
const struct V_7 * V_7 = F_52 () ;
return F_104 ( V_7 , V_52 , V_493 ) ;
}
static int F_211 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
return F_104 ( V_7 , V_52 , V_493 ) ;
}
static int F_212 ( struct V_52 * V_52 , const char * V_64 )
{
if ( strcmp ( V_64 , V_67 ) )
return F_199 ( V_52 , V_64 ) ;
return - V_506 ;
}
static int F_213 ( const struct V_19 * V_19 , const char * V_64 , void * * V_222 , bool V_507 )
{
T_2 V_497 ;
int error ;
char * V_83 = NULL ;
struct V_20 * V_21 = V_19 -> V_30 ;
if ( strcmp ( V_64 , V_469 ) )
return - V_65 ;
error = F_125 ( F_52 () , & V_370 , V_499 ,
V_372 ) ;
if ( ! error )
error = F_182 ( V_21 -> V_14 , & V_83 ,
& V_497 ) ;
else
error = F_47 ( V_21 -> V_14 , & V_83 , & V_497 ) ;
if ( error )
return error ;
error = V_497 ;
if ( V_507 ) {
* V_222 = V_83 ;
goto V_508;
}
F_28 ( V_83 ) ;
V_508:
return error ;
}
static int F_214 ( struct V_19 * V_19 , const char * V_64 ,
const void * V_466 , T_7 V_497 , int V_69 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_279 ;
int V_47 ;
if ( strcmp ( V_64 , V_469 ) )
return - V_65 ;
if ( ! V_466 || ! V_497 )
return - V_506 ;
V_47 = F_54 ( ( void * ) V_466 , V_497 , & V_279 ) ;
if ( V_47 )
return V_47 ;
V_21 -> V_14 = V_279 ;
V_21 -> V_114 = 1 ;
return 0 ;
}
static int F_215 ( struct V_19 * V_19 , char * V_222 , T_7 V_509 )
{
const int V_84 = sizeof( V_67 ) ;
if ( V_222 && V_84 <= V_509 )
memcpy ( V_222 , V_67 , V_84 ) ;
return V_84 ;
}
static void F_216 ( const struct V_19 * V_19 , T_2 * V_510 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
* V_510 = V_21 -> V_14 ;
}
static int F_217 ( struct V_36 * V_36 , int V_309 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_19 * V_19 = F_107 ( V_36 ) ;
if ( ( V_36 -> V_323 & V_324 ) && ( V_309 & V_316 ) )
V_309 |= V_314 ;
return F_106 ( V_7 , V_36 ,
F_114 ( V_19 -> V_234 , V_309 ) ) ;
}
static int F_218 ( struct V_36 * V_36 , int V_309 )
{
struct V_19 * V_19 = F_107 ( V_36 ) ;
struct V_37 * V_38 = V_36 -> V_40 ;
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_14 = F_14 () ;
if ( ! V_309 )
return 0 ;
if ( V_14 == V_38 -> V_14 && V_38 -> V_511 == V_21 -> V_14 &&
V_38 -> V_512 == F_219 () )
return 0 ;
return F_217 ( V_36 , V_309 ) ;
}
static int F_220 ( struct V_36 * V_36 )
{
return F_26 ( V_36 ) ;
}
static void F_221 ( struct V_36 * V_36 )
{
F_27 ( V_36 ) ;
}
static int F_222 ( struct V_36 * V_36 , unsigned int V_513 ,
unsigned long V_514 )
{
const struct V_7 * V_7 = F_52 () ;
int error = 0 ;
switch ( V_513 ) {
case V_515 :
case V_516 :
case V_517 :
case V_518 :
case V_519 :
error = F_106 ( V_7 , V_36 , V_493 ) ;
break;
case V_520 :
case V_521 :
error = F_106 ( V_7 , V_36 , V_491 ) ;
break;
case V_522 :
case V_523 :
error = F_106 ( V_7 , V_36 , 0 ) ;
break;
case V_524 :
case V_525 :
error = F_94 ( V_7 , V_526 ,
V_268 ) ;
break;
default:
error = F_106 ( V_7 , V_36 , V_325 ) ;
}
return error ;
}
static int F_223 ( struct V_36 * V_36 , unsigned long V_527 , int V_528 )
{
const struct V_7 * V_7 = F_52 () ;
int V_47 = 0 ;
if ( V_529 &&
( V_527 & V_530 ) && ( ! V_36 || ( ! V_528 && ( V_527 & V_531 ) ) ) ) {
V_47 = F_91 ( V_7 , V_7 , V_532 ) ;
if ( V_47 )
goto error;
}
if ( V_36 ) {
T_2 V_263 = V_313 ;
if ( V_528 && ( V_527 & V_531 ) )
V_263 |= V_317 ;
if ( V_527 & V_530 )
V_263 |= V_311 ;
return F_106 ( V_7 , V_36 , V_263 ) ;
}
error:
return V_47 ;
}
static int F_224 ( unsigned long V_533 )
{
int V_47 = 0 ;
T_2 V_14 = F_14 () ;
if ( V_533 < V_534 ) {
V_47 = F_35 ( V_14 , V_14 , V_535 ,
V_536 , NULL ) ;
if ( V_47 )
return V_47 ;
}
return F_225 ( V_533 ) ;
}
static int F_226 ( struct V_36 * V_36 , unsigned long V_537 ,
unsigned long V_527 , unsigned long V_69 )
{
if ( V_538 )
V_527 = V_537 ;
return F_223 ( V_36 , V_527 ,
( V_69 & V_539 ) == V_540 ) ;
}
static int F_227 ( struct V_541 * V_542 ,
unsigned long V_537 ,
unsigned long V_527 )
{
const struct V_7 * V_7 = F_52 () ;
if ( V_538 )
V_527 = V_537 ;
if ( V_529 &&
( V_527 & V_530 ) && ! ( V_542 -> V_543 & V_544 ) ) {
int V_47 = 0 ;
if ( V_542 -> V_545 >= V_542 -> V_546 -> V_547 &&
V_542 -> V_548 <= V_542 -> V_546 -> V_549 ) {
V_47 = F_91 ( V_7 , V_7 , V_550 ) ;
} else if ( ! V_542 -> V_551 &&
V_542 -> V_545 <= V_542 -> V_546 -> V_552 &&
V_542 -> V_548 >= V_542 -> V_546 -> V_552 ) {
V_47 = F_93 ( V_8 , V_553 ) ;
} else if ( V_542 -> V_551 && V_542 -> V_554 ) {
V_47 = F_106 ( V_7 , V_542 -> V_551 , V_555 ) ;
}
if ( V_47 )
return V_47 ;
}
return F_223 ( V_542 -> V_551 , V_527 , V_542 -> V_543 & V_556 ) ;
}
static int F_228 ( struct V_36 * V_36 , unsigned int V_513 )
{
const struct V_7 * V_7 = F_52 () ;
return F_106 ( V_7 , V_36 , V_557 ) ;
}
static int F_229 ( struct V_36 * V_36 , unsigned int V_513 ,
unsigned long V_514 )
{
const struct V_7 * V_7 = F_52 () ;
int V_558 = 0 ;
switch ( V_513 ) {
case V_559 :
if ( ( V_36 -> V_323 & V_324 ) && ! ( V_514 & V_324 ) ) {
V_558 = F_106 ( V_7 , V_36 , V_317 ) ;
break;
}
case V_560 :
case V_561 :
case V_562 :
case V_563 :
case V_564 :
case V_565 :
V_558 = F_106 ( V_7 , V_36 , 0 ) ;
break;
case V_566 :
case V_567 :
case V_568 :
#if V_569 == 32
case V_570 :
case V_571 :
case V_572 :
#endif
V_558 = F_106 ( V_7 , V_36 , V_557 ) ;
break;
}
return V_558 ;
}
static int F_230 ( struct V_36 * V_36 )
{
struct V_37 * V_38 ;
V_38 = V_36 -> V_40 ;
V_38 -> V_39 = F_14 () ;
return 0 ;
}
static int F_231 ( struct V_17 * V_256 ,
struct V_573 * V_574 , int V_575 )
{
struct V_36 * V_36 ;
T_2 V_14 = F_10 ( V_256 ) ;
T_2 V_236 ;
struct V_37 * V_38 ;
V_36 = F_232 ( V_574 , struct V_36 , V_576 ) ;
V_38 = V_36 -> V_40 ;
if ( ! V_575 )
V_236 = F_90 ( V_577 ) ;
else
V_236 = F_90 ( V_575 ) ;
return F_35 ( V_38 -> V_39 , V_14 ,
V_249 , V_236 , NULL ) ;
}
static int F_233 ( struct V_36 * V_36 )
{
const struct V_7 * V_7 = F_52 () ;
return F_106 ( V_7 , V_36 , F_115 ( V_36 ) ) ;
}
static int F_234 ( struct V_36 * V_36 , const struct V_7 * V_7 )
{
struct V_37 * V_38 ;
struct V_20 * V_21 ;
V_38 = V_36 -> V_40 ;
V_21 = F_107 ( V_36 ) -> V_30 ;
V_38 -> V_511 = V_21 -> V_14 ;
V_38 -> V_512 = F_219 () ;
return F_105 ( V_7 , & V_36 -> V_274 , F_116 ( V_36 ) ) ;
}
static int F_235 ( unsigned long V_578 )
{
return F_93 ( V_8 , V_579 ) ;
}
static int F_236 ( struct V_7 * V_7 , T_11 V_580 )
{
struct V_10 * V_11 ;
V_11 = F_7 ( sizeof( struct V_10 ) , V_580 ) ;
if ( ! V_11 )
return - V_24 ;
V_7 -> V_16 = V_11 ;
return 0 ;
}
static void F_237 ( struct V_7 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_16 ;
F_48 ( V_7 -> V_16 && ( unsigned long ) V_7 -> V_16 < V_224 ) ;
V_7 -> V_16 = ( void * ) 0x7UL ;
F_28 ( V_11 ) ;
}
static int F_238 ( struct V_7 * V_118 , const struct V_7 * V_117 ,
T_11 V_580 )
{
const struct V_10 * V_375 ;
struct V_10 * V_11 ;
V_375 = V_117 -> V_16 ;
V_11 = F_239 ( V_375 , sizeof( struct V_10 ) , V_580 ) ;
if ( ! V_11 )
return - V_24 ;
V_118 -> V_16 = V_11 ;
return 0 ;
}
static void F_240 ( struct V_7 * V_118 , const struct V_7 * V_117 )
{
const struct V_10 * V_375 = V_117 -> V_16 ;
struct V_10 * V_11 = V_118 -> V_16 ;
* V_11 = * V_375 ;
}
static int F_241 ( struct V_7 * V_118 , T_2 V_510 )
{
struct V_10 * V_11 = V_118 -> V_16 ;
T_2 V_14 = F_14 () ;
int V_581 ;
V_581 = F_35 ( V_14 , V_510 ,
V_582 ,
V_583 ,
NULL ) ;
if ( V_581 == 0 ) {
V_11 -> V_14 = V_510 ;
V_11 -> V_280 = 0 ;
V_11 -> V_378 = 0 ;
V_11 -> V_379 = 0 ;
}
return V_581 ;
}
static int F_242 ( struct V_7 * V_118 , struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
struct V_10 * V_11 = V_118 -> V_16 ;
T_2 V_14 = F_14 () ;
int V_581 ;
V_581 = F_35 ( V_14 , V_21 -> V_14 ,
V_582 ,
V_584 ,
NULL ) ;
if ( V_581 == 0 )
V_11 -> V_280 = V_21 -> V_14 ;
return V_581 ;
}
static int F_243 ( char * V_585 )
{
T_2 V_14 ;
struct V_259 V_260 ;
V_14 = F_10 ( V_8 ) ;
V_260 . type = V_586 ;
V_260 . V_265 . V_585 = V_585 ;
return F_35 ( V_14 , V_15 , V_270 ,
V_587 , & V_260 ) ;
}
static int F_244 ( struct V_17 * V_135 , T_12 V_588 )
{
return F_93 ( V_135 , V_589 ) ;
}
static int F_245 ( struct V_17 * V_135 )
{
return F_93 ( V_135 , V_590 ) ;
}
static int F_246 ( struct V_17 * V_135 )
{
return F_93 ( V_135 , V_591 ) ;
}
static void F_247 ( struct V_17 * V_135 , T_2 * V_510 )
{
* V_510 = F_10 ( V_135 ) ;
}
static int F_248 ( struct V_17 * V_135 , int V_592 )
{
int V_47 ;
V_47 = F_249 ( V_135 , V_592 ) ;
if ( V_47 )
return V_47 ;
return F_93 ( V_135 , V_593 ) ;
}
static int F_250 ( struct V_17 * V_135 , int V_594 )
{
int V_47 ;
V_47 = F_251 ( V_135 , V_594 ) ;
if ( V_47 )
return V_47 ;
return F_93 ( V_135 , V_593 ) ;
}
static int F_252 ( struct V_17 * V_135 )
{
return F_93 ( V_135 , V_595 ) ;
}
static int F_253 ( struct V_17 * V_135 , unsigned int V_596 ,
struct V_414 * V_597 )
{
struct V_414 * V_598 = V_135 -> signal -> V_415 + V_596 ;
if ( V_598 -> V_422 != V_597 -> V_422 )
return F_93 ( V_135 , V_599 ) ;
return 0 ;
}
static int F_254 ( struct V_17 * V_135 )
{
int V_47 ;
V_47 = F_255 ( V_135 ) ;
if ( V_47 )
return V_47 ;
return F_93 ( V_135 , V_593 ) ;
}
static int F_256 ( struct V_17 * V_135 )
{
return F_93 ( V_135 , V_595 ) ;
}
static int F_257 ( struct V_17 * V_135 )
{
return F_93 ( V_135 , V_593 ) ;
}
static int F_258 ( struct V_17 * V_135 , struct V_600 * V_601 ,
int V_235 , T_2 V_510 )
{
T_2 V_236 ;
int V_47 ;
if ( ! V_235 )
V_236 = V_602 ;
else
V_236 = F_90 ( V_235 ) ;
if ( V_510 )
V_47 = F_35 ( V_510 , F_10 ( V_135 ) ,
V_249 , V_236 , NULL ) ;
else
V_47 = F_93 ( V_135 , V_236 ) ;
return V_47 ;
}
static int F_259 ( struct V_17 * V_135 )
{
return F_92 ( V_135 , V_8 , V_238 ) ;
}
static void F_260 ( struct V_17 * V_135 ,
struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_14 = F_10 ( V_135 ) ;
V_21 -> V_14 = V_14 ;
V_21 -> V_114 = 1 ;
}
static int F_261 ( struct V_603 * V_604 ,
struct V_259 * V_260 , T_13 * V_605 )
{
int V_606 , V_607 , V_581 = - V_86 ;
struct V_608 V_609 , * V_610 ;
V_606 = F_262 ( V_604 ) ;
V_610 = F_263 ( V_604 , V_606 , sizeof( V_609 ) , & V_609 ) ;
if ( V_610 == NULL )
goto V_66;
V_607 = V_610 -> V_611 * 4 ;
if ( V_607 < sizeof( V_609 ) )
goto V_66;
V_260 -> V_265 . V_612 -> V_613 . V_614 = V_610 -> V_614 ;
V_260 -> V_265 . V_612 -> V_613 . V_615 = V_610 -> V_615 ;
V_581 = 0 ;
if ( V_605 )
* V_605 = V_610 -> V_174 ;
switch ( V_610 -> V_174 ) {
case V_176 : {
struct V_616 V_617 , * V_618 ;
if ( F_264 ( V_610 -> V_619 ) & V_620 )
break;
V_606 += V_607 ;
V_618 = F_263 ( V_604 , V_606 , sizeof( V_617 ) , & V_617 ) ;
if ( V_618 == NULL )
break;
V_260 -> V_265 . V_612 -> V_621 = V_618 -> V_622 ;
V_260 -> V_265 . V_612 -> V_623 = V_618 -> V_624 ;
break;
}
case V_177 : {
struct V_625 V_626 , * V_627 ;
if ( F_264 ( V_610 -> V_619 ) & V_620 )
break;
V_606 += V_607 ;
V_627 = F_263 ( V_604 , V_606 , sizeof( V_626 ) , & V_626 ) ;
if ( V_627 == NULL )
break;
V_260 -> V_265 . V_612 -> V_621 = V_627 -> V_622 ;
V_260 -> V_265 . V_612 -> V_623 = V_627 -> V_624 ;
break;
}
case V_628 : {
struct V_629 V_630 , * V_631 ;
if ( F_264 ( V_610 -> V_619 ) & V_620 )
break;
V_606 += V_607 ;
V_631 = F_263 ( V_604 , V_606 , sizeof( V_630 ) , & V_630 ) ;
if ( V_631 == NULL )
break;
V_260 -> V_265 . V_612 -> V_621 = V_631 -> V_632 ;
V_260 -> V_265 . V_612 -> V_623 = V_631 -> V_633 ;
break;
}
default:
break;
}
V_66:
return V_581 ;
}
static int F_265 ( struct V_603 * V_604 ,
struct V_259 * V_260 , T_13 * V_605 )
{
T_13 V_634 ;
int V_581 = - V_86 , V_606 ;
struct V_635 V_636 , * V_637 ;
T_14 V_619 ;
V_606 = F_262 ( V_604 ) ;
V_637 = F_263 ( V_604 , V_606 , sizeof( V_636 ) , & V_636 ) ;
if ( V_637 == NULL )
goto V_66;
V_260 -> V_265 . V_612 -> V_638 . V_614 = V_637 -> V_614 ;
V_260 -> V_265 . V_612 -> V_638 . V_615 = V_637 -> V_615 ;
V_581 = 0 ;
V_634 = V_637 -> V_634 ;
V_606 += sizeof( V_636 ) ;
V_606 = F_266 ( V_604 , V_606 , & V_634 , & V_619 ) ;
if ( V_606 < 0 )
goto V_66;
if ( V_605 )
* V_605 = V_634 ;
switch ( V_634 ) {
case V_176 : {
struct V_616 V_617 , * V_618 ;
V_618 = F_263 ( V_604 , V_606 , sizeof( V_617 ) , & V_617 ) ;
if ( V_618 == NULL )
break;
V_260 -> V_265 . V_612 -> V_621 = V_618 -> V_622 ;
V_260 -> V_265 . V_612 -> V_623 = V_618 -> V_624 ;
break;
}
case V_177 : {
struct V_625 V_626 , * V_627 ;
V_627 = F_263 ( V_604 , V_606 , sizeof( V_626 ) , & V_626 ) ;
if ( V_627 == NULL )
break;
V_260 -> V_265 . V_612 -> V_621 = V_627 -> V_622 ;
V_260 -> V_265 . V_612 -> V_623 = V_627 -> V_624 ;
break;
}
case V_628 : {
struct V_629 V_630 , * V_631 ;
V_631 = F_263 ( V_604 , V_606 , sizeof( V_630 ) , & V_630 ) ;
if ( V_631 == NULL )
break;
V_260 -> V_265 . V_612 -> V_621 = V_631 -> V_632 ;
V_260 -> V_265 . V_612 -> V_623 = V_631 -> V_633 ;
break;
}
default:
break;
}
V_66:
return V_581 ;
}
static int F_267 ( struct V_603 * V_604 , struct V_259 * V_260 ,
char * * V_639 , int V_640 , T_13 * V_605 )
{
char * V_641 ;
int V_581 ;
switch ( V_260 -> V_265 . V_612 -> V_178 ) {
case V_185 :
V_581 = F_261 ( V_604 , V_260 , V_605 ) ;
if ( V_581 )
goto V_642;
V_641 = ( char * ) ( V_640 ? & V_260 -> V_265 . V_612 -> V_613 . V_614 :
& V_260 -> V_265 . V_612 -> V_613 . V_615 ) ;
goto V_643;
#if F_268 ( V_644 ) || F_268 ( V_645 )
case V_186 :
V_581 = F_265 ( V_604 , V_260 , V_605 ) ;
if ( V_581 )
goto V_642;
V_641 = ( char * ) ( V_640 ? & V_260 -> V_265 . V_612 -> V_638 . V_614 :
& V_260 -> V_265 . V_612 -> V_638 . V_615 ) ;
goto V_643;
#endif
default:
V_641 = NULL ;
goto V_643;
}
V_642:
F_38 ( V_61
L_43
L_44 ) ;
return V_581 ;
V_643:
if ( V_639 )
* V_639 = V_641 ;
return 0 ;
}
static int F_269 ( struct V_603 * V_604 , T_4 V_178 , T_2 * V_14 )
{
int V_558 ;
T_2 V_646 ;
T_2 V_647 ;
T_2 V_648 ;
F_270 ( V_604 , & V_646 ) ;
F_271 ( V_604 , V_178 , & V_648 , & V_647 ) ;
V_558 = F_272 ( V_647 , V_648 , V_646 , V_14 ) ;
if ( F_102 ( V_558 ) ) {
F_38 ( V_61
L_45
L_46 ) ;
return - V_506 ;
}
return 0 ;
}
static int F_273 ( const struct V_10 * V_11 ,
T_4 V_649 , T_2 * V_650 )
{
if ( V_11 -> V_379 > V_651 ) {
* V_650 = V_11 -> V_379 ;
return 0 ;
}
return F_88 ( V_11 -> V_14 , V_11 -> V_14 , V_649 , NULL ,
V_650 ) ;
}
static int F_274 ( struct V_17 * V_18 , struct V_652 * V_653 , T_2 V_246 )
{
struct V_654 * V_655 = V_653 -> V_656 ;
struct V_259 V_260 ;
struct V_657 V_612 = { 0 ,} ;
T_2 V_248 = F_10 ( V_18 ) ;
if ( V_655 -> V_14 == V_15 )
return 0 ;
V_260 . type = V_658 ;
V_260 . V_265 . V_612 = & V_612 ;
V_260 . V_265 . V_612 -> V_653 = V_653 ;
return F_35 ( V_248 , V_655 -> V_14 , V_655 -> V_28 , V_246 , & V_260 ) ;
}
static int F_275 ( int V_178 , int type ,
int V_174 , int V_659 )
{
const struct V_10 * V_11 = F_15 () ;
T_2 V_279 ;
T_4 V_649 ;
int V_47 ;
if ( V_659 )
return 0 ;
V_649 = F_72 ( V_178 , type , V_174 ) ;
V_47 = F_273 ( V_11 , V_649 , & V_279 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_11 -> V_14 , V_279 , V_649 , V_660 , NULL ) ;
}
static int F_276 ( struct V_661 * V_652 , int V_178 ,
int type , int V_174 , int V_659 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_21 = F_277 ( V_652 ) -> V_30 ;
struct V_654 * V_655 ;
int V_558 = 0 ;
V_21 -> V_28 = F_72 ( V_178 , type , V_174 ) ;
if ( V_659 )
V_21 -> V_14 = V_15 ;
else {
V_558 = F_273 ( V_11 , V_21 -> V_28 , & ( V_21 -> V_14 ) ) ;
if ( V_558 )
return V_558 ;
}
V_21 -> V_114 = 1 ;
if ( V_652 -> V_653 ) {
V_655 = V_652 -> V_653 -> V_656 ;
V_655 -> V_14 = V_21 -> V_14 ;
V_655 -> V_28 = V_21 -> V_28 ;
V_558 = F_278 ( V_652 -> V_653 , V_178 ) ;
}
return V_558 ;
}
static int F_279 ( struct V_661 * V_652 , struct V_662 * V_663 , int V_664 )
{
struct V_652 * V_653 = V_652 -> V_653 ;
T_4 V_178 ;
int V_558 ;
V_558 = F_274 ( V_8 , V_653 , V_665 ) ;
if ( V_558 )
goto V_66;
V_178 = V_653 -> V_666 ;
if ( V_178 == V_185 || V_178 == V_186 ) {
char * V_641 ;
struct V_654 * V_655 = V_653 -> V_656 ;
struct V_259 V_260 ;
struct V_657 V_612 = { 0 ,} ;
struct V_667 * V_668 = NULL ;
struct V_669 * V_670 = NULL ;
unsigned short V_671 ;
T_2 V_14 , V_672 ;
if ( V_178 == V_185 ) {
V_668 = (struct V_667 * ) V_663 ;
V_671 = F_264 ( V_668 -> V_673 ) ;
V_641 = ( char * ) & V_668 -> V_674 . V_675 ;
} else {
V_670 = (struct V_669 * ) V_663 ;
V_671 = F_264 ( V_670 -> V_676 ) ;
V_641 = ( char * ) & V_670 -> V_677 . V_678 ;
}
if ( V_671 ) {
int V_679 , V_680 ;
F_280 ( & V_679 , & V_680 ) ;
if ( V_671 < V_681 ( V_682, V_679 ) || V_671 > V_680 ) {
V_558 = F_281 ( V_653 -> V_683 ,
V_671 , & V_14 ) ;
if ( V_558 )
goto V_66;
V_260 . type = V_658 ;
V_260 . V_265 . V_612 = & V_612 ;
V_260 . V_265 . V_612 -> V_621 = F_282 ( V_671 ) ;
V_260 . V_265 . V_612 -> V_178 = V_178 ;
V_558 = F_35 ( V_655 -> V_14 , V_14 ,
V_655 -> V_28 ,
V_684 , & V_260 ) ;
if ( V_558 )
goto V_66;
}
}
switch ( V_655 -> V_28 ) {
case V_187 :
V_672 = V_685 ;
break;
case V_189 :
V_672 = V_686 ;
break;
case V_191 :
V_672 = V_687 ;
break;
default:
V_672 = V_688 ;
break;
}
V_558 = F_283 ( V_641 , V_178 , & V_14 ) ;
if ( V_558 )
goto V_66;
V_260 . type = V_658 ;
V_260 . V_265 . V_612 = & V_612 ;
V_260 . V_265 . V_612 -> V_621 = F_282 ( V_671 ) ;
V_260 . V_265 . V_612 -> V_178 = V_178 ;
if ( V_178 == V_185 )
V_260 . V_265 . V_612 -> V_613 . V_614 = V_668 -> V_674 . V_675 ;
else
V_260 . V_265 . V_612 -> V_638 . V_614 = V_670 -> V_677 ;
V_558 = F_35 ( V_655 -> V_14 , V_14 ,
V_655 -> V_28 , V_672 , & V_260 ) ;
if ( V_558 )
goto V_66;
}
V_66:
return V_558 ;
}
static int F_284 ( struct V_661 * V_652 , struct V_662 * V_663 , int V_664 )
{
struct V_652 * V_653 = V_652 -> V_653 ;
struct V_654 * V_655 = V_653 -> V_656 ;
int V_558 ;
V_558 = F_274 ( V_8 , V_653 , V_689 ) ;
if ( V_558 )
return V_558 ;
if ( V_655 -> V_28 == V_187 ||
V_655 -> V_28 == V_191 ) {
struct V_259 V_260 ;
struct V_657 V_612 = { 0 ,} ;
struct V_667 * V_668 = NULL ;
struct V_669 * V_670 = NULL ;
unsigned short V_671 ;
T_2 V_14 , V_236 ;
if ( V_653 -> V_666 == V_185 ) {
V_668 = (struct V_667 * ) V_663 ;
if ( V_664 < sizeof( struct V_667 ) )
return - V_86 ;
V_671 = F_264 ( V_668 -> V_673 ) ;
} else {
V_670 = (struct V_669 * ) V_663 ;
if ( V_664 < V_690 )
return - V_86 ;
V_671 = F_264 ( V_670 -> V_676 ) ;
}
V_558 = F_281 ( V_653 -> V_683 , V_671 , & V_14 ) ;
if ( V_558 )
goto V_66;
V_236 = ( V_655 -> V_28 == V_187 ) ?
V_691 : V_692 ;
V_260 . type = V_658 ;
V_260 . V_265 . V_612 = & V_612 ;
V_260 . V_265 . V_612 -> V_623 = F_282 ( V_671 ) ;
V_260 . V_265 . V_612 -> V_178 = V_653 -> V_666 ;
V_558 = F_35 ( V_655 -> V_14 , V_14 , V_655 -> V_28 , V_236 , & V_260 ) ;
if ( V_558 )
goto V_66;
}
V_558 = F_285 ( V_653 , V_663 ) ;
V_66:
return V_558 ;
}
static int F_286 ( struct V_661 * V_652 , int V_693 )
{
return F_274 ( V_8 , V_652 -> V_653 , V_694 ) ;
}
static int F_287 ( struct V_661 * V_652 , struct V_661 * V_695 )
{
int V_558 ;
struct V_20 * V_21 ;
struct V_20 * V_131 ;
V_558 = F_274 ( V_8 , V_652 -> V_653 , V_696 ) ;
if ( V_558 )
return V_558 ;
V_131 = F_277 ( V_695 ) -> V_30 ;
V_21 = F_277 ( V_652 ) -> V_30 ;
V_131 -> V_28 = V_21 -> V_28 ;
V_131 -> V_14 = V_21 -> V_14 ;
V_131 -> V_114 = 1 ;
return 0 ;
}
static int F_288 ( struct V_661 * V_652 , struct V_697 * V_698 ,
int V_497 )
{
return F_274 ( V_8 , V_652 -> V_653 , V_699 ) ;
}
static int F_289 ( struct V_661 * V_652 , struct V_697 * V_698 ,
int V_497 , int V_69 )
{
return F_274 ( V_8 , V_652 -> V_653 , V_700 ) ;
}
static int F_290 ( struct V_661 * V_652 )
{
return F_274 ( V_8 , V_652 -> V_653 , V_701 ) ;
}
static int F_291 ( struct V_661 * V_652 )
{
return F_274 ( V_8 , V_652 -> V_653 , V_701 ) ;
}
static int F_292 ( struct V_661 * V_652 , int V_702 , int V_703 )
{
int V_558 ;
V_558 = F_274 ( V_8 , V_652 -> V_653 , V_704 ) ;
if ( V_558 )
return V_558 ;
return F_293 ( V_652 , V_702 , V_703 ) ;
}
static int F_294 ( struct V_661 * V_652 , int V_702 ,
int V_703 )
{
return F_274 ( V_8 , V_652 -> V_653 , V_705 ) ;
}
static int F_295 ( struct V_661 * V_652 , int V_706 )
{
return F_274 ( V_8 , V_652 -> V_653 , V_707 ) ;
}
static int F_296 ( struct V_652 * V_652 ,
struct V_652 * V_708 ,
struct V_652 * V_709 )
{
struct V_654 * V_710 = V_652 -> V_656 ;
struct V_654 * V_711 = V_708 -> V_656 ;
struct V_654 * V_712 = V_709 -> V_656 ;
struct V_259 V_260 ;
struct V_657 V_612 = { 0 ,} ;
int V_558 ;
V_260 . type = V_658 ;
V_260 . V_265 . V_612 = & V_612 ;
V_260 . V_265 . V_612 -> V_653 = V_708 ;
V_558 = F_35 ( V_710 -> V_14 , V_711 -> V_14 ,
V_711 -> V_28 ,
V_713 , & V_260 ) ;
if ( V_558 )
return V_558 ;
V_712 -> V_714 = V_710 -> V_14 ;
V_558 = F_297 ( V_711 -> V_14 , V_710 -> V_14 ,
& V_712 -> V_14 ) ;
if ( V_558 )
return V_558 ;
V_710 -> V_714 = V_712 -> V_14 ;
return 0 ;
}
static int F_298 ( struct V_661 * V_652 ,
struct V_661 * V_708 )
{
struct V_654 * V_715 = V_652 -> V_653 -> V_656 ;
struct V_654 * V_716 = V_708 -> V_653 -> V_656 ;
struct V_259 V_260 ;
struct V_657 V_612 = { 0 ,} ;
V_260 . type = V_658 ;
V_260 . V_265 . V_612 = & V_612 ;
V_260 . V_265 . V_612 -> V_653 = V_708 -> V_653 ;
return F_35 ( V_715 -> V_14 , V_716 -> V_14 , V_716 -> V_28 , V_717 ,
& V_260 ) ;
}
static int F_299 ( int V_718 , char * V_641 , T_4 V_178 ,
T_2 V_714 ,
struct V_259 * V_260 )
{
int V_558 ;
T_2 V_719 ;
T_2 V_720 ;
V_558 = F_300 ( V_718 , & V_719 ) ;
if ( V_558 )
return V_558 ;
V_558 = F_35 ( V_714 , V_719 ,
V_721 , V_722 , V_260 ) ;
if ( V_558 )
return V_558 ;
V_558 = F_283 ( V_641 , V_178 , & V_720 ) ;
if ( V_558 )
return V_558 ;
return F_35 ( V_714 , V_720 ,
V_723 , V_724 , V_260 ) ;
}
static int F_301 ( struct V_652 * V_653 , struct V_603 * V_604 ,
T_4 V_178 )
{
int V_558 = 0 ;
struct V_654 * V_655 = V_653 -> V_656 ;
T_2 V_725 = V_655 -> V_14 ;
struct V_259 V_260 ;
struct V_657 V_612 = { 0 ,} ;
char * V_641 ;
V_260 . type = V_658 ;
V_260 . V_265 . V_612 = & V_612 ;
V_260 . V_265 . V_612 -> V_726 = V_604 -> V_727 ;
V_260 . V_265 . V_612 -> V_178 = V_178 ;
V_558 = F_267 ( V_604 , & V_260 , & V_641 , 1 , NULL ) ;
if ( V_558 )
return V_558 ;
if ( F_4 () ) {
V_558 = F_35 ( V_725 , V_604 -> V_728 , V_729 ,
V_730 , & V_260 ) ;
if ( V_558 )
return V_558 ;
}
V_558 = F_302 ( V_655 , V_604 , V_178 , & V_260 ) ;
if ( V_558 )
return V_558 ;
V_558 = F_303 ( V_655 -> V_14 , V_604 , & V_260 ) ;
return V_558 ;
}
static int F_304 ( struct V_652 * V_653 , struct V_603 * V_604 )
{
int V_558 ;
struct V_654 * V_655 = V_653 -> V_656 ;
T_4 V_178 = V_653 -> V_666 ;
T_2 V_725 = V_655 -> V_14 ;
struct V_259 V_260 ;
struct V_657 V_612 = { 0 ,} ;
char * V_641 ;
T_13 V_731 ;
T_13 V_732 ;
if ( V_178 != V_185 && V_178 != V_186 )
return 0 ;
if ( V_178 == V_186 && V_604 -> V_174 == F_282 ( V_733 ) )
V_178 = V_185 ;
if ( ! V_734 )
return F_301 ( V_653 , V_604 , V_178 ) ;
V_731 = F_4 () ;
V_732 = F_305 () || F_306 () ;
if ( ! V_731 && ! V_732 )
return 0 ;
V_260 . type = V_658 ;
V_260 . V_265 . V_612 = & V_612 ;
V_260 . V_265 . V_612 -> V_726 = V_604 -> V_727 ;
V_260 . V_265 . V_612 -> V_178 = V_178 ;
V_558 = F_267 ( V_604 , & V_260 , & V_641 , 1 , NULL ) ;
if ( V_558 )
return V_558 ;
if ( V_732 ) {
T_2 V_714 ;
V_558 = F_269 ( V_604 , V_178 , & V_714 ) ;
if ( V_558 )
return V_558 ;
V_558 = F_299 ( V_604 -> V_727 , V_641 , V_178 ,
V_714 , & V_260 ) ;
if ( V_558 ) {
F_307 ( V_604 , V_558 , 0 ) ;
return V_558 ;
}
V_558 = F_35 ( V_725 , V_714 , V_735 ,
V_736 , & V_260 ) ;
if ( V_558 )
F_307 ( V_604 , V_558 , 0 ) ;
}
if ( V_731 ) {
V_558 = F_35 ( V_725 , V_604 -> V_728 , V_729 ,
V_730 , & V_260 ) ;
if ( V_558 )
return V_558 ;
}
return V_558 ;
}
static int F_308 ( struct V_661 * V_652 , char T_15 * V_737 ,
int T_15 * V_738 , unsigned V_84 )
{
int V_558 = 0 ;
char * V_739 ;
T_2 V_740 ;
struct V_654 * V_655 = V_652 -> V_653 -> V_656 ;
T_2 V_714 = V_651 ;
if ( V_655 -> V_28 == V_182 ||
V_655 -> V_28 == V_187 )
V_714 = V_655 -> V_714 ;
if ( V_714 == V_651 )
return - V_741 ;
V_558 = F_47 ( V_714 , & V_739 , & V_740 ) ;
if ( V_558 )
return V_558 ;
if ( V_740 > V_84 ) {
V_558 = - V_227 ;
goto V_742;
}
if ( F_309 ( V_737 , V_739 , V_740 ) )
V_558 = - V_743 ;
V_742:
if ( F_310 ( V_740 , V_738 ) )
V_558 = - V_743 ;
F_28 ( V_739 ) ;
return V_558 ;
}
static int F_311 ( struct V_661 * V_652 , struct V_603 * V_604 , T_2 * V_510 )
{
T_2 V_744 = V_651 ;
T_4 V_178 ;
if ( V_604 && V_604 -> V_174 == F_282 ( V_733 ) )
V_178 = V_185 ;
else if ( V_604 && V_604 -> V_174 == F_282 ( V_745 ) )
V_178 = V_186 ;
else if ( V_652 )
V_178 = V_652 -> V_653 -> V_666 ;
else
goto V_66;
if ( V_652 && V_178 == V_179 )
F_216 ( F_277 ( V_652 ) , & V_744 ) ;
else if ( V_604 )
F_269 ( V_604 , V_178 , & V_744 ) ;
V_66:
* V_510 = V_744 ;
if ( V_744 == V_651 )
return - V_86 ;
return 0 ;
}
static int F_312 ( struct V_652 * V_653 , int V_178 , T_11 V_746 )
{
struct V_654 * V_655 ;
V_655 = F_7 ( sizeof( * V_655 ) , V_746 ) ;
if ( ! V_655 )
return - V_24 ;
V_655 -> V_714 = V_27 ;
V_655 -> V_14 = V_27 ;
F_313 ( V_655 ) ;
V_653 -> V_656 = V_655 ;
return 0 ;
}
static void F_314 ( struct V_652 * V_653 )
{
struct V_654 * V_655 = V_653 -> V_656 ;
V_653 -> V_656 = NULL ;
F_315 ( V_655 ) ;
F_28 ( V_655 ) ;
}
static void F_316 ( const struct V_652 * V_653 , struct V_652 * V_709 )
{
struct V_654 * V_655 = V_653 -> V_656 ;
struct V_654 * V_747 = V_709 -> V_656 ;
V_747 -> V_14 = V_655 -> V_14 ;
V_747 -> V_714 = V_655 -> V_714 ;
V_747 -> V_28 = V_655 -> V_28 ;
F_313 ( V_747 ) ;
}
static void F_317 ( struct V_652 * V_653 , T_2 * V_510 )
{
if ( ! V_653 )
* V_510 = V_748 ;
else {
struct V_654 * V_655 = V_653 -> V_656 ;
* V_510 = V_655 -> V_14 ;
}
}
static void F_318 ( struct V_652 * V_653 , struct V_661 * V_332 )
{
struct V_20 * V_21 = F_277 ( V_332 ) -> V_30 ;
struct V_654 * V_655 = V_653 -> V_656 ;
if ( V_653 -> V_666 == V_185 || V_653 -> V_666 == V_186 ||
V_653 -> V_666 == V_179 )
V_21 -> V_14 = V_655 -> V_14 ;
V_655 -> V_28 = V_21 -> V_28 ;
}
static int F_319 ( struct V_652 * V_653 , struct V_603 * V_604 ,
struct V_749 * V_750 )
{
struct V_654 * V_655 = V_653 -> V_656 ;
int V_558 ;
T_4 V_178 = V_653 -> V_666 ;
T_2 V_279 ;
T_2 V_751 ;
if ( V_178 == V_186 && V_604 -> V_174 == F_282 ( V_733 ) )
V_178 = V_185 ;
V_558 = F_269 ( V_604 , V_178 , & V_751 ) ;
if ( V_558 )
return V_558 ;
if ( V_751 == V_651 ) {
V_750 -> V_510 = V_655 -> V_14 ;
V_750 -> V_744 = V_651 ;
} else {
V_558 = F_297 ( V_655 -> V_14 , V_751 , & V_279 ) ;
if ( V_558 )
return V_558 ;
V_750 -> V_510 = V_279 ;
V_750 -> V_744 = V_751 ;
}
return F_320 ( V_750 , V_178 ) ;
}
static void F_321 ( struct V_652 * V_709 ,
const struct V_749 * V_750 )
{
struct V_654 * V_747 = V_709 -> V_656 ;
V_747 -> V_14 = V_750 -> V_510 ;
V_747 -> V_714 = V_750 -> V_744 ;
F_322 ( V_709 , V_750 -> V_752 -> V_178 ) ;
}
static void F_323 ( struct V_652 * V_653 , struct V_603 * V_604 )
{
T_4 V_178 = V_653 -> V_666 ;
struct V_654 * V_655 = V_653 -> V_656 ;
if ( V_178 == V_186 && V_604 -> V_174 == F_282 ( V_733 ) )
V_178 = V_185 ;
F_269 ( V_604 , V_178 , & V_655 -> V_714 ) ;
}
static void F_324 ( struct V_603 * V_604 , struct V_652 * V_653 )
{
F_325 ( V_604 , V_653 ) ;
}
static int F_326 ( T_2 V_14 )
{
const struct V_10 * V_753 ;
T_2 V_248 ;
V_753 = F_15 () ;
V_248 = V_753 -> V_14 ;
return F_35 ( V_248 , V_14 , V_729 , V_754 , NULL ) ;
}
static void F_327 ( void )
{
F_328 ( & V_6 ) ;
}
static void F_329 ( void )
{
F_330 ( & V_6 ) ;
}
static void F_331 ( const struct V_749 * V_750 ,
struct V_755 * V_756 )
{
V_756 -> V_757 = V_750 -> V_510 ;
}
static int F_332 ( void * * V_16 )
{
struct V_758 * V_759 ;
V_759 = F_7 ( sizeof( * V_759 ) , V_12 ) ;
if ( ! V_759 )
return - V_24 ;
V_759 -> V_14 = F_14 () ;
* V_16 = V_759 ;
return 0 ;
}
static void F_333 ( void * V_16 )
{
F_28 ( V_16 ) ;
}
static int F_334 ( void )
{
T_2 V_14 = F_14 () ;
return F_35 ( V_14 , V_14 , V_760 , V_761 ,
NULL ) ;
}
static int F_335 ( void * V_16 )
{
struct V_758 * V_759 = V_16 ;
return F_35 ( F_14 () , V_759 -> V_14 , V_760 ,
V_762 , NULL ) ;
}
static int F_336 ( struct V_652 * V_653 , void * V_16 )
{
struct V_758 * V_759 = V_16 ;
struct V_654 * V_655 = V_653 -> V_656 ;
V_655 -> V_14 = V_759 -> V_14 ;
V_655 -> V_28 = V_760 ;
return 0 ;
}
static int F_337 ( void * V_16 )
{
struct V_758 * V_759 = V_16 ;
T_2 V_14 = F_14 () ;
int V_558 ;
V_558 = F_35 ( V_14 , V_759 -> V_14 , V_760 ,
V_763 , NULL ) ;
if ( V_558 )
return V_558 ;
V_558 = F_35 ( V_14 , V_14 , V_760 ,
V_764 , NULL ) ;
if ( V_558 )
return V_558 ;
V_759 -> V_14 = V_14 ;
return 0 ;
}
static int F_338 ( struct V_652 * V_653 , struct V_603 * V_604 )
{
int V_558 = 0 ;
T_2 V_236 ;
struct V_765 * V_766 ;
struct V_654 * V_655 = V_653 -> V_656 ;
if ( V_604 -> V_84 < V_767 ) {
V_558 = - V_86 ;
goto V_66;
}
V_766 = F_339 ( V_604 ) ;
V_558 = F_340 ( V_655 -> V_28 , V_766 -> V_768 , & V_236 ) ;
if ( V_558 ) {
if ( V_558 == - V_86 ) {
F_341 ( V_8 -> V_503 , V_12 , V_504 ,
L_47
L_48 ,
V_766 -> V_768 , V_655 -> V_28 ) ;
if ( ! V_3 || F_342 () )
V_558 = 0 ;
}
if ( V_558 == - V_769 )
V_558 = 0 ;
goto V_66;
}
V_558 = F_274 ( V_8 , V_653 , V_236 ) ;
V_66:
return V_558 ;
}
static unsigned int F_343 ( struct V_603 * V_604 , int V_718 ,
T_4 V_178 )
{
int V_558 ;
char * V_641 ;
T_2 V_714 ;
struct V_259 V_260 ;
struct V_657 V_612 = { 0 ,} ;
T_13 V_731 ;
T_13 V_770 ;
T_13 V_732 ;
if ( ! V_734 )
return V_771 ;
V_731 = F_4 () ;
V_770 = F_305 () ;
V_732 = V_770 || F_306 () ;
if ( ! V_731 && ! V_732 )
return V_771 ;
if ( F_269 ( V_604 , V_178 , & V_714 ) != 0 )
return V_772 ;
V_260 . type = V_658 ;
V_260 . V_265 . V_612 = & V_612 ;
V_260 . V_265 . V_612 -> V_726 = V_718 ;
V_260 . V_265 . V_612 -> V_178 = V_178 ;
if ( F_267 ( V_604 , & V_260 , & V_641 , 1 , NULL ) != 0 )
return V_772 ;
if ( V_732 ) {
V_558 = F_299 ( V_718 , V_641 , V_178 ,
V_714 , & V_260 ) ;
if ( V_558 ) {
F_307 ( V_604 , V_558 , 1 ) ;
return V_772 ;
}
}
if ( V_731 )
if ( F_35 ( V_714 , V_604 -> V_728 ,
V_729 , V_773 , & V_260 ) )
return V_772 ;
if ( V_770 )
if ( F_344 ( V_604 , V_178 , V_714 ) != 0 )
return V_772 ;
return V_771 ;
}
static unsigned int F_345 ( unsigned int V_774 ,
struct V_603 * V_604 ,
const struct V_775 * V_776 ,
const struct V_775 * V_66 ,
int (* F_346)( struct V_603 * ) )
{
return F_343 ( V_604 , V_776 -> V_718 , V_185 ) ;
}
static unsigned int F_347 ( unsigned int V_774 ,
struct V_603 * V_604 ,
const struct V_775 * V_776 ,
const struct V_775 * V_66 ,
int (* F_346)( struct V_603 * ) )
{
return F_343 ( V_604 , V_776 -> V_718 , V_186 ) ;
}
static unsigned int F_348 ( struct V_603 * V_604 ,
T_4 V_178 )
{
T_2 V_14 ;
if ( ! F_305 () )
return V_771 ;
if ( V_604 -> V_653 ) {
struct V_654 * V_655 = V_604 -> V_653 -> V_656 ;
V_14 = V_655 -> V_14 ;
} else
V_14 = V_15 ;
if ( F_344 ( V_604 , V_178 , V_14 ) != 0 )
return V_772 ;
return V_771 ;
}
static unsigned int F_349 ( unsigned int V_774 ,
struct V_603 * V_604 ,
const struct V_775 * V_776 ,
const struct V_775 * V_66 ,
int (* F_346)( struct V_603 * ) )
{
return F_348 ( V_604 , V_185 ) ;
}
static unsigned int F_350 ( struct V_603 * V_604 ,
int V_718 ,
T_4 V_178 )
{
struct V_652 * V_653 = V_604 -> V_653 ;
struct V_654 * V_655 ;
struct V_259 V_260 ;
struct V_657 V_612 = { 0 ,} ;
char * V_641 ;
T_13 V_605 ;
if ( V_653 == NULL )
return V_771 ;
V_655 = V_653 -> V_656 ;
V_260 . type = V_658 ;
V_260 . V_265 . V_612 = & V_612 ;
V_260 . V_265 . V_612 -> V_726 = V_718 ;
V_260 . V_265 . V_612 -> V_178 = V_178 ;
if ( F_267 ( V_604 , & V_260 , & V_641 , 0 , & V_605 ) )
return V_772 ;
if ( F_4 () )
if ( F_35 ( V_655 -> V_14 , V_604 -> V_728 ,
V_729 , V_777 , & V_260 ) )
return F_351 ( - V_778 ) ;
if ( F_352 ( V_655 -> V_14 , V_604 , & V_260 , V_605 ) )
return F_351 ( - V_778 ) ;
return V_771 ;
}
static unsigned int F_353 ( struct V_603 * V_604 , int V_718 ,
T_4 V_178 )
{
T_2 V_779 ;
T_2 V_714 ;
struct V_652 * V_653 ;
struct V_259 V_260 ;
struct V_657 V_612 = { 0 ,} ;
char * V_641 ;
T_13 V_731 ;
T_13 V_732 ;
if ( ! V_734 )
return F_350 ( V_604 , V_718 , V_178 ) ;
#ifdef F_354
if ( F_355 ( V_604 ) != NULL && F_355 ( V_604 ) -> V_780 != NULL )
return V_771 ;
#endif
V_731 = F_4 () ;
V_732 = F_305 () || F_306 () ;
if ( ! V_731 && ! V_732 )
return V_771 ;
V_653 = V_604 -> V_653 ;
if ( V_653 == NULL ) {
if ( V_604 -> V_727 ) {
V_779 = V_781 ;
if ( F_269 ( V_604 , V_178 , & V_714 ) )
return V_772 ;
} else {
V_779 = V_777 ;
V_714 = V_15 ;
}
} else {
struct V_654 * V_655 = V_653 -> V_656 ;
V_714 = V_655 -> V_14 ;
V_779 = V_777 ;
}
V_260 . type = V_658 ;
V_260 . V_265 . V_612 = & V_612 ;
V_260 . V_265 . V_612 -> V_726 = V_718 ;
V_260 . V_265 . V_612 -> V_178 = V_178 ;
if ( F_267 ( V_604 , & V_260 , & V_641 , 0 , NULL ) )
return V_772 ;
if ( V_731 )
if ( F_35 ( V_714 , V_604 -> V_728 ,
V_729 , V_779 , & V_260 ) )
return F_351 ( - V_778 ) ;
if ( V_732 ) {
T_2 V_719 ;
T_2 V_720 ;
if ( F_300 ( V_718 , & V_719 ) )
return V_772 ;
if ( F_35 ( V_714 , V_719 ,
V_721 , V_782 , & V_260 ) )
return F_351 ( - V_778 ) ;
if ( F_283 ( V_641 , V_178 , & V_720 ) )
return V_772 ;
if ( F_35 ( V_714 , V_720 ,
V_723 , V_783 , & V_260 ) )
return F_351 ( - V_778 ) ;
}
return V_771 ;
}
static unsigned int F_356 ( unsigned int V_774 ,
struct V_603 * V_604 ,
const struct V_775 * V_776 ,
const struct V_775 * V_66 ,
int (* F_346)( struct V_603 * ) )
{
return F_353 ( V_604 , V_66 -> V_718 , V_185 ) ;
}
static unsigned int F_357 ( unsigned int V_774 ,
struct V_603 * V_604 ,
const struct V_775 * V_776 ,
const struct V_775 * V_66 ,
int (* F_346)( struct V_603 * ) )
{
return F_353 ( V_604 , V_66 -> V_718 , V_186 ) ;
}
static int F_358 ( struct V_652 * V_653 , struct V_603 * V_604 )
{
int V_558 ;
V_558 = F_359 ( V_653 , V_604 ) ;
if ( V_558 )
return V_558 ;
return F_338 ( V_653 , V_604 ) ;
}
static int F_360 ( struct V_17 * V_18 ,
struct V_784 * V_236 ,
T_4 V_28 )
{
struct V_785 * V_21 ;
T_2 V_14 ;
V_21 = F_7 ( sizeof( struct V_785 ) , V_12 ) ;
if ( ! V_21 )
return - V_24 ;
V_14 = F_10 ( V_18 ) ;
V_21 -> V_28 = V_28 ;
V_21 -> V_14 = V_14 ;
V_236 -> V_16 = V_21 ;
return 0 ;
}
static void F_361 ( struct V_784 * V_236 )
{
struct V_785 * V_21 = V_236 -> V_16 ;
V_236 -> V_16 = NULL ;
F_28 ( V_21 ) ;
}
static int F_362 ( struct V_786 * V_698 )
{
struct V_787 * V_788 ;
V_788 = F_7 ( sizeof( struct V_787 ) , V_12 ) ;
if ( ! V_788 )
return - V_24 ;
V_788 -> V_14 = V_27 ;
V_698 -> V_16 = V_788 ;
return 0 ;
}
static void F_363 ( struct V_786 * V_698 )
{
struct V_787 * V_788 = V_698 -> V_16 ;
V_698 -> V_16 = NULL ;
F_28 ( V_788 ) ;
}
static int F_364 ( struct V_784 * V_789 ,
T_2 V_246 )
{
struct V_785 * V_21 ;
struct V_259 V_260 ;
T_2 V_14 = F_14 () ;
V_21 = V_789 -> V_16 ;
V_260 . type = V_790 ;
V_260 . V_265 . V_791 = V_789 -> V_792 ;
return F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_246 , & V_260 ) ;
}
static int F_365 ( struct V_786 * V_698 )
{
return F_362 ( V_698 ) ;
}
static void F_366 ( struct V_786 * V_698 )
{
F_363 ( V_698 ) ;
}
static int F_367 ( struct V_793 * V_794 )
{
struct V_785 * V_21 ;
struct V_259 V_260 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_360 ( V_8 , & V_794 -> V_795 , V_796 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_794 -> V_795 . V_16 ;
V_260 . type = V_790 ;
V_260 . V_265 . V_791 = V_794 -> V_795 . V_792 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_796 ,
V_797 , & V_260 ) ;
if ( V_47 ) {
F_361 ( & V_794 -> V_795 ) ;
return V_47 ;
}
return 0 ;
}
static void F_368 ( struct V_793 * V_794 )
{
F_361 ( & V_794 -> V_795 ) ;
}
static int F_369 ( struct V_793 * V_794 , int V_798 )
{
struct V_785 * V_21 ;
struct V_259 V_260 ;
T_2 V_14 = F_14 () ;
V_21 = V_794 -> V_795 . V_16 ;
V_260 . type = V_790 ;
V_260 . V_265 . V_791 = V_794 -> V_795 . V_792 ;
return F_35 ( V_14 , V_21 -> V_14 , V_796 ,
V_799 , & V_260 ) ;
}
static int F_370 ( struct V_793 * V_794 , int V_513 )
{
int V_558 ;
int V_246 ;
switch ( V_513 ) {
case V_800 :
case V_801 :
return F_99 ( V_8 , V_802 ) ;
case V_803 :
case V_804 :
V_246 = V_805 | V_799 ;
break;
case V_806 :
V_246 = V_807 ;
break;
case V_808 :
V_246 = V_809 ;
break;
default:
return 0 ;
}
V_558 = F_364 ( & V_794 -> V_795 , V_246 ) ;
return V_558 ;
}
static int F_371 ( struct V_793 * V_794 , struct V_786 * V_698 , int V_798 )
{
struct V_785 * V_21 ;
struct V_787 * V_788 ;
struct V_259 V_260 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_21 = V_794 -> V_795 . V_16 ;
V_788 = V_698 -> V_16 ;
if ( V_788 -> V_14 == V_27 ) {
V_47 = F_88 ( V_14 , V_21 -> V_14 , V_810 ,
NULL , & V_788 -> V_14 ) ;
if ( V_47 )
return V_47 ;
}
V_260 . type = V_790 ;
V_260 . V_265 . V_791 = V_794 -> V_795 . V_792 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_796 ,
V_811 , & V_260 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_14 , V_788 -> V_14 , V_810 ,
V_812 , & V_260 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_788 -> V_14 , V_21 -> V_14 , V_796 ,
V_813 , & V_260 ) ;
return V_47 ;
}
static int F_372 ( struct V_793 * V_794 , struct V_786 * V_698 ,
struct V_17 * V_245 ,
long type , int V_159 )
{
struct V_785 * V_21 ;
struct V_787 * V_788 ;
struct V_259 V_260 ;
T_2 V_14 = F_10 ( V_245 ) ;
int V_47 ;
V_21 = V_794 -> V_795 . V_16 ;
V_788 = V_698 -> V_16 ;
V_260 . type = V_790 ;
V_260 . V_265 . V_791 = V_794 -> V_795 . V_792 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 ,
V_796 , V_814 , & V_260 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_14 , V_788 -> V_14 ,
V_810 , V_815 , & V_260 ) ;
return V_47 ;
}
static int F_373 ( struct V_816 * V_817 )
{
struct V_785 * V_21 ;
struct V_259 V_260 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_360 ( V_8 , & V_817 -> V_818 , V_819 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_817 -> V_818 . V_16 ;
V_260 . type = V_790 ;
V_260 . V_265 . V_791 = V_817 -> V_818 . V_792 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_819 ,
V_820 , & V_260 ) ;
if ( V_47 ) {
F_361 ( & V_817 -> V_818 ) ;
return V_47 ;
}
return 0 ;
}
static void F_374 ( struct V_816 * V_817 )
{
F_361 ( & V_817 -> V_818 ) ;
}
static int F_375 ( struct V_816 * V_817 , int V_821 )
{
struct V_785 * V_21 ;
struct V_259 V_260 ;
T_2 V_14 = F_14 () ;
V_21 = V_817 -> V_818 . V_16 ;
V_260 . type = V_790 ;
V_260 . V_265 . V_791 = V_817 -> V_818 . V_792 ;
return F_35 ( V_14 , V_21 -> V_14 , V_819 ,
V_822 , & V_260 ) ;
}
static int F_376 ( struct V_816 * V_817 , int V_513 )
{
int V_246 ;
int V_558 ;
switch ( V_513 ) {
case V_800 :
case V_823 :
return F_99 ( V_8 , V_802 ) ;
case V_803 :
case V_824 :
V_246 = V_825 | V_822 ;
break;
case V_806 :
V_246 = V_826 ;
break;
case V_827 :
case V_828 :
V_246 = V_829 ;
break;
case V_808 :
V_246 = V_830 ;
break;
default:
return 0 ;
}
V_558 = F_364 ( & V_817 -> V_818 , V_246 ) ;
return V_558 ;
}
static int F_377 ( struct V_816 * V_817 ,
char T_15 * V_831 , int V_821 )
{
T_2 V_246 ;
if ( V_821 & V_832 )
V_246 = V_833 ;
else
V_246 = V_833 | V_834 ;
return F_364 ( & V_817 -> V_818 , V_246 ) ;
}
static int F_378 ( struct V_835 * V_836 )
{
struct V_785 * V_21 ;
struct V_259 V_260 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_360 ( V_8 , & V_836 -> V_837 , V_838 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_836 -> V_837 . V_16 ;
V_260 . type = V_790 ;
V_260 . V_265 . V_791 = V_836 -> V_837 . V_792 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_838 ,
V_839 , & V_260 ) ;
if ( V_47 ) {
F_361 ( & V_836 -> V_837 ) ;
return V_47 ;
}
return 0 ;
}
static void F_379 ( struct V_835 * V_836 )
{
F_361 ( & V_836 -> V_837 ) ;
}
static int F_380 ( struct V_835 * V_836 , int V_840 )
{
struct V_785 * V_21 ;
struct V_259 V_260 ;
T_2 V_14 = F_14 () ;
V_21 = V_836 -> V_837 . V_16 ;
V_260 . type = V_790 ;
V_260 . V_265 . V_791 = V_836 -> V_837 . V_792 ;
return F_35 ( V_14 , V_21 -> V_14 , V_838 ,
V_841 , & V_260 ) ;
}
static int F_381 ( struct V_835 * V_836 , int V_513 )
{
int V_558 ;
T_2 V_246 ;
switch ( V_513 ) {
case V_800 :
case V_842 :
return F_99 ( V_8 , V_802 ) ;
case V_843 :
case V_844 :
case V_845 :
V_246 = V_846 ;
break;
case V_847 :
case V_848 :
V_246 = V_849 ;
break;
case V_850 :
case V_851 :
V_246 = V_852 ;
break;
case V_808 :
V_246 = V_853 ;
break;
case V_806 :
V_246 = V_854 ;
break;
case V_803 :
case V_855 :
V_246 = V_846 | V_841 ;
break;
default:
return 0 ;
}
V_558 = F_364 ( & V_836 -> V_837 , V_246 ) ;
return V_558 ;
}
static int F_382 ( struct V_835 * V_836 ,
struct V_856 * V_857 , unsigned V_858 , int V_859 )
{
T_2 V_246 ;
if ( V_859 )
V_246 = V_849 | V_852 ;
else
V_246 = V_849 ;
return F_364 ( & V_836 -> V_837 , V_246 ) ;
}
static int F_383 ( struct V_784 * V_860 , short V_98 )
{
T_2 V_263 = 0 ;
V_263 = 0 ;
if ( V_98 & V_861 )
V_263 |= V_862 ;
if ( V_98 & V_863 )
V_263 |= V_864 ;
if ( V_263 == 0 )
return 0 ;
return F_364 ( V_860 , V_263 ) ;
}
static void F_384 ( struct V_784 * V_860 , T_2 * V_510 )
{
struct V_785 * V_21 = V_860 -> V_16 ;
* V_510 = V_21 -> V_14 ;
}
static void F_385 ( struct V_52 * V_52 , struct V_19 * V_19 )
{
if ( V_19 )
F_33 ( V_19 , V_52 ) ;
}
static int F_386 ( struct V_17 * V_135 ,
char * V_64 , char * * V_466 )
{
const struct V_10 * V_753 ;
T_2 V_14 ;
int error ;
unsigned V_84 ;
if ( V_8 != V_135 ) {
error = F_93 ( V_135 , V_865 ) ;
if ( error )
return error ;
}
F_11 () ;
V_753 = F_12 ( V_135 ) -> V_16 ;
if ( ! strcmp ( V_64 , L_49 ) )
V_14 = V_753 -> V_14 ;
else if ( ! strcmp ( V_64 , L_50 ) )
V_14 = V_753 -> V_13 ;
else if ( ! strcmp ( V_64 , L_51 ) )
V_14 = V_753 -> V_380 ;
else if ( ! strcmp ( V_64 , L_52 ) )
V_14 = V_753 -> V_280 ;
else if ( ! strcmp ( V_64 , L_53 ) )
V_14 = V_753 -> V_378 ;
else if ( ! strcmp ( V_64 , L_54 ) )
V_14 = V_753 -> V_379 ;
else
goto V_866;
F_13 () ;
if ( ! V_14 )
return 0 ;
error = F_47 ( V_14 , V_466 , & V_84 ) ;
if ( error )
return error ;
return V_84 ;
V_866:
F_13 () ;
return - V_86 ;
}
static int F_387 ( struct V_17 * V_135 ,
char * V_64 , void * V_466 , T_7 V_497 )
{
struct V_10 * V_11 ;
struct V_17 * V_393 ;
struct V_7 * V_118 ;
T_2 V_14 = 0 , V_395 ;
int error ;
char * V_1 = V_466 ;
if ( V_8 != V_135 ) {
return - V_506 ;
}
if ( ! strcmp ( V_64 , L_51 ) )
error = F_93 ( V_135 , V_867 ) ;
else if ( ! strcmp ( V_64 , L_52 ) )
error = F_93 ( V_135 , V_868 ) ;
else if ( ! strcmp ( V_64 , L_53 ) )
error = F_93 ( V_135 , V_869 ) ;
else if ( ! strcmp ( V_64 , L_54 ) )
error = F_93 ( V_135 , V_870 ) ;
else if ( ! strcmp ( V_64 , L_49 ) )
error = F_93 ( V_135 , V_871 ) ;
else
error = - V_86 ;
if ( error )
return error ;
if ( V_497 && V_1 [ 1 ] && V_1 [ 1 ] != '\n' ) {
if ( V_1 [ V_497 - 1 ] == '\n' ) {
V_1 [ V_497 - 1 ] = 0 ;
V_497 -- ;
}
error = F_54 ( V_466 , V_497 , & V_14 ) ;
if ( error == - V_86 && ! strcmp ( V_64 , L_52 ) ) {
if ( ! F_200 ( V_499 ) ) {
struct V_500 * V_501 ;
T_7 V_502 ;
if ( V_1 [ V_497 - 1 ] == '\0' )
V_502 = V_497 - 1 ;
else
V_502 = V_497 ;
V_501 = F_203 ( V_8 -> V_503 , V_91 , V_504 ) ;
F_204 ( V_501 , L_55 ) ;
F_205 ( V_501 , V_466 , V_502 ) ;
F_206 ( V_501 ) ;
return error ;
}
error = F_207 ( V_466 , V_497 ,
& V_14 ) ;
}
if ( error )
return error ;
}
V_118 = F_388 () ;
if ( ! V_118 )
return - V_24 ;
V_11 = V_118 -> V_16 ;
if ( ! strcmp ( V_64 , L_51 ) ) {
V_11 -> V_380 = V_14 ;
} else if ( ! strcmp ( V_64 , L_52 ) ) {
V_11 -> V_280 = V_14 ;
} else if ( ! strcmp ( V_64 , L_53 ) ) {
error = F_109 ( V_14 , V_135 ) ;
if ( error )
goto V_872;
V_11 -> V_378 = V_14 ;
} else if ( ! strcmp ( V_64 , L_54 ) ) {
V_11 -> V_379 = V_14 ;
} else if ( ! strcmp ( V_64 , L_49 ) ) {
error = - V_86 ;
if ( V_14 == 0 )
goto V_872;
error = - V_383 ;
if ( ! F_389 () ) {
error = F_390 ( V_11 -> V_14 , V_14 ) ;
if ( error )
goto V_872;
}
error = F_35 ( V_11 -> V_14 , V_14 , V_249 ,
V_873 , NULL ) ;
if ( error )
goto V_872;
V_395 = 0 ;
F_149 ( V_135 ) ;
V_393 = F_134 ( V_135 ) ;
if ( V_393 )
V_395 = F_10 ( V_393 ) ;
F_151 ( V_135 ) ;
if ( V_393 ) {
error = F_35 ( V_395 , V_14 , V_249 ,
V_331 , NULL ) ;
if ( error )
goto V_872;
}
V_11 -> V_14 = V_14 ;
} else {
error = - V_86 ;
goto V_872;
}
F_391 ( V_118 ) ;
return V_497 ;
V_872:
F_392 ( V_118 ) ;
return error ;
}
static int F_393 ( T_2 V_510 , char * * V_450 , T_2 * V_874 )
{
return F_47 ( V_510 , V_450 , V_874 ) ;
}
static int F_394 ( const char * V_450 , T_2 V_874 , T_2 * V_510 )
{
return F_54 ( V_450 , V_874 , V_510 ) ;
}
static void F_395 ( char * V_450 , T_2 V_874 )
{
F_28 ( V_450 ) ;
}
static int F_396 ( struct V_19 * V_19 , void * V_286 , T_2 V_875 )
{
return F_214 ( V_19 , V_469 , V_286 , V_875 , 0 ) ;
}
static int F_397 ( struct V_52 * V_52 , void * V_286 , T_2 V_875 )
{
return F_398 ( V_52 , V_67 , V_286 , V_875 , 0 ) ;
}
static int F_399 ( struct V_19 * V_19 , void * * V_286 , T_2 * V_875 )
{
int V_84 = 0 ;
V_84 = F_213 ( V_19 , V_469 ,
V_286 , true ) ;
if ( V_84 < 0 )
return V_84 ;
* V_875 = V_84 ;
return 0 ;
}
static int F_400 ( struct V_792 * V_876 , const struct V_7 * V_7 ,
unsigned long V_69 )
{
const struct V_10 * V_11 ;
struct V_877 * V_878 ;
V_878 = F_7 ( sizeof( struct V_877 ) , V_12 ) ;
if ( ! V_878 )
return - V_24 ;
V_11 = V_7 -> V_16 ;
if ( V_11 -> V_378 )
V_878 -> V_14 = V_11 -> V_378 ;
else
V_878 -> V_14 = V_11 -> V_14 ;
V_876 -> V_16 = V_878 ;
return 0 ;
}
static void F_401 ( struct V_792 * V_876 )
{
struct V_877 * V_878 = V_876 -> V_16 ;
V_876 -> V_16 = NULL ;
F_28 ( V_878 ) ;
}
static int F_402 ( T_16 V_879 ,
const struct V_7 * V_7 ,
T_17 V_236 )
{
struct V_792 * V_792 ;
struct V_877 * V_878 ;
T_2 V_14 ;
if ( V_236 == 0 )
return 0 ;
V_14 = F_9 ( V_7 ) ;
V_792 = F_403 ( V_879 ) ;
V_878 = V_792 -> V_16 ;
return F_35 ( V_14 , V_878 -> V_14 , V_287 , V_236 , NULL ) ;
}
static int F_404 ( struct V_792 * V_792 , char * * V_880 )
{
struct V_877 * V_878 = V_792 -> V_16 ;
char * V_83 = NULL ;
unsigned V_84 ;
int V_47 ;
V_47 = F_47 ( V_878 -> V_14 , & V_83 , & V_84 ) ;
if ( ! V_47 )
V_47 = V_84 ;
* V_880 = V_83 ;
return V_47 ;
}
static T_1 int F_405 ( void )
{
if ( ! F_406 ( & V_881 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_38 ( V_882 L_56 ) ;
return 0 ;
}
F_38 ( V_882 L_57 ) ;
F_6 () ;
V_529 = ! ( V_883 & V_544 ) ;
V_22 = F_407 ( L_58 ,
sizeof( struct V_20 ) ,
0 , V_884 , NULL ) ;
F_408 () ;
if ( F_409 ( & V_881 ) )
F_8 ( L_59 ) ;
if ( V_3 )
F_38 ( V_74 L_60 ) ;
else
F_38 ( V_74 L_61 ) ;
return 0 ;
}
static void F_410 ( struct V_41 * V_42 , void * V_885 )
{
F_63 ( V_42 , NULL ) ;
}
void F_411 ( void )
{
F_38 ( V_74 L_62 ) ;
F_38 ( V_74 L_63 ) ;
F_412 ( F_410 , NULL ) ;
}
static int T_1 F_413 ( void )
{
int V_558 = 0 ;
if ( ! V_5 )
goto V_66;
F_38 ( V_74 L_64 ) ;
V_558 = F_414 ( V_886 , F_39 ( V_886 ) ) ;
if ( V_558 )
F_8 ( L_65 , V_558 ) ;
#if F_268 ( V_644 ) || F_268 ( V_645 )
V_558 = F_414 ( V_887 , F_39 ( V_887 ) ) ;
if ( V_558 )
F_8 ( L_66 , V_558 ) ;
#endif
V_66:
return V_558 ;
}
static void F_415 ( void )
{
F_38 ( V_74 L_67 ) ;
F_416 ( V_886 , F_39 ( V_886 ) ) ;
#if F_268 ( V_644 ) || F_268 ( V_645 )
F_416 ( V_887 , F_39 ( V_887 ) ) ;
#endif
}
int F_417 ( void )
{
if ( V_87 ) {
return - V_86 ;
}
if ( V_888 ) {
return - V_86 ;
}
F_38 ( V_882 L_68 ) ;
V_888 = 1 ;
V_5 = 0 ;
F_418 () ;
F_419 () ;
F_415 () ;
F_420 () ;
return 0 ;
}
