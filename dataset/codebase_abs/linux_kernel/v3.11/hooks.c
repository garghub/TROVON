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
struct V_80 * V_81 ,
unsigned long V_102 ,
unsigned long * V_103 )
{
const struct V_7 * V_7 = F_52 () ;
int V_47 = 0 , V_82 ;
struct V_31 * V_32 = V_42 -> V_34 ;
const char * V_64 = V_42 -> V_63 -> V_64 ;
struct V_19 * V_19 = V_32 -> V_42 -> V_54 -> V_56 ;
struct V_20 * V_104 = V_19 -> V_30 ;
T_2 V_105 = 0 , V_106 = 0 , V_107 = 0 ;
T_2 V_108 = 0 ;
char * * V_109 = V_81 -> V_90 ;
int * V_69 = V_81 -> V_93 ;
int V_110 = V_81 -> V_89 ;
F_53 ( & V_32 -> V_25 ) ;
if ( ! V_87 ) {
if ( ! V_110 ) {
goto V_66;
}
V_47 = - V_86 ;
F_38 ( V_61 L_10
L_11 ) ;
goto V_66;
}
if ( V_102 && ! V_103 ) {
V_47 = - V_86 ;
goto V_66;
}
if ( ( V_32 -> V_69 & V_70 ) && ( V_42 -> V_63 -> V_111 & V_112 )
&& ( V_110 == 0 ) )
goto V_66;
for ( V_82 = 0 ; V_82 < V_110 ; V_82 ++ ) {
T_2 V_14 ;
if ( V_69 [ V_82 ] == V_71 )
continue;
V_47 = F_54 ( V_109 [ V_82 ] ,
strlen ( V_109 [ V_82 ] ) , & V_14 ) ;
if ( V_47 ) {
F_38 ( V_61 L_12
L_13 ,
V_109 [ V_82 ] , V_42 -> V_62 , V_64 , V_47 ) ;
goto V_66;
}
switch ( V_69 [ V_82 ] ) {
case V_94 :
V_105 = V_14 ;
if ( F_50 ( V_32 , V_94 , V_32 -> V_14 ,
V_105 ) )
goto V_113;
V_32 -> V_69 |= V_94 ;
break;
case V_95 :
V_106 = V_14 ;
if ( F_50 ( V_32 , V_95 , V_32 -> V_46 ,
V_106 ) )
goto V_113;
V_32 -> V_69 |= V_95 ;
break;
case V_97 :
V_107 = V_14 ;
if ( F_50 ( V_32 , V_97 , V_104 -> V_14 ,
V_107 ) )
goto V_113;
V_32 -> V_69 |= V_97 ;
break;
case V_96 :
V_108 = V_14 ;
if ( F_50 ( V_32 , V_96 , V_32 -> V_44 ,
V_108 ) )
goto V_113;
V_32 -> V_69 |= V_96 ;
break;
default:
V_47 = - V_86 ;
goto V_66;
}
}
if ( V_32 -> V_69 & V_70 ) {
if ( ( V_32 -> V_69 & V_88 ) && ! V_110 )
goto V_113;
V_47 = 0 ;
goto V_66;
}
if ( strcmp ( V_42 -> V_63 -> V_64 , L_14 ) == 0 )
V_32 -> V_69 |= V_114 ;
if ( ! V_32 -> V_57 ) {
V_47 = F_55 ( ( V_32 -> V_69 & V_114 ) ?
L_14 : V_42 -> V_63 -> V_64 ,
& V_32 -> V_57 , & V_32 -> V_14 ) ;
if ( V_47 ) {
F_38 ( V_61
L_15 ,
V_115 , V_42 -> V_63 -> V_64 , V_47 ) ;
goto V_66;
}
}
if ( V_105 ) {
V_47 = F_34 ( V_105 , V_32 , V_7 ) ;
if ( V_47 )
goto V_66;
V_32 -> V_14 = V_105 ;
}
if ( V_102 & V_116 && ! V_106 ) {
V_32 -> V_57 = V_117 ;
* V_103 |= V_116 ;
}
if ( V_106 ) {
if ( ! V_105 ) {
V_47 = F_34 ( V_106 , V_32 ,
V_7 ) ;
if ( V_47 )
goto V_66;
V_32 -> V_14 = V_106 ;
} else {
V_47 = F_36 ( V_106 , V_32 ,
V_7 ) ;
if ( V_47 )
goto V_66;
}
if ( ! V_107 )
V_107 = V_106 ;
V_32 -> V_46 = V_106 ;
V_32 -> V_57 = V_76 ;
}
if ( V_107 ) {
V_47 = F_36 ( V_107 , V_32 ,
V_7 ) ;
if ( V_47 )
goto V_66;
V_104 -> V_14 = V_107 ;
V_104 -> V_118 = 1 ;
}
if ( V_108 ) {
if ( V_32 -> V_57 != V_58 &&
V_32 -> V_57 != V_117 ) {
V_47 = - V_86 ;
F_38 ( V_61 L_16
L_17 ) ;
goto V_66;
}
if ( V_108 != V_32 -> V_44 ) {
V_47 = F_36 ( V_108 ,
V_32 , V_7 ) ;
if ( V_47 )
goto V_66;
}
V_32 -> V_44 = V_108 ;
}
V_47 = F_37 ( V_42 ) ;
V_66:
F_56 ( & V_32 -> V_25 ) ;
return V_47 ;
V_113:
V_47 = - V_86 ;
F_38 ( V_61 L_18
L_19 , V_42 -> V_62 , V_64 ) ;
goto V_66;
}
static int F_57 ( const struct V_41 * V_119 ,
const struct V_41 * V_120 )
{
struct V_31 * V_121 = V_119 -> V_34 ;
struct V_31 * V_122 = V_120 -> V_34 ;
char V_123 = V_121 -> V_69 & V_88 ;
char V_124 = V_122 -> V_69 & V_88 ;
if ( V_123 != V_124 )
goto V_125;
if ( ( V_123 & V_94 ) && V_121 -> V_14 != V_122 -> V_14 )
goto V_125;
if ( ( V_123 & V_95 ) && V_121 -> V_46 != V_122 -> V_46 )
goto V_125;
if ( ( V_123 & V_96 ) && V_121 -> V_44 != V_122 -> V_44 )
goto V_125;
if ( V_123 & V_97 ) {
struct V_20 * V_126 = V_119 -> V_54 -> V_56 -> V_30 ;
struct V_20 * V_127 = V_120 -> V_54 -> V_56 -> V_30 ;
if ( V_126 -> V_14 != V_127 -> V_14 )
goto V_125;
}
return 0 ;
V_125:
F_38 ( V_61 L_20
L_21
L_22 , V_120 -> V_62 , V_120 -> V_63 -> V_64 ) ;
return - V_128 ;
}
static int F_58 ( const struct V_41 * V_119 ,
struct V_41 * V_120 )
{
const struct V_31 * V_129 = V_119 -> V_34 ;
struct V_31 * V_130 = V_120 -> V_34 ;
int V_131 = ( V_129 -> V_69 & V_94 ) ;
int V_132 = ( V_129 -> V_69 & V_95 ) ;
int V_133 = ( V_129 -> V_69 & V_97 ) ;
if ( ! V_87 )
return 0 ;
F_48 ( ! ( V_129 -> V_69 & V_70 ) ) ;
if ( V_130 -> V_69 & V_70 )
return F_57 ( V_119 , V_120 ) ;
F_53 ( & V_130 -> V_25 ) ;
V_130 -> V_69 = V_129 -> V_69 ;
V_130 -> V_14 = V_129 -> V_14 ;
V_130 -> V_44 = V_129 -> V_44 ;
V_130 -> V_57 = V_129 -> V_57 ;
if ( V_132 ) {
T_2 V_14 = V_129 -> V_46 ;
if ( ! V_131 )
V_130 -> V_14 = V_14 ;
if ( ! V_133 ) {
struct V_19 * V_134 = V_120 -> V_54 -> V_56 ;
struct V_20 * V_135 = V_134 -> V_30 ;
V_135 -> V_14 = V_14 ;
}
V_130 -> V_46 = V_14 ;
}
if ( V_133 ) {
const struct V_19 * V_136 = V_119 -> V_54 -> V_56 ;
const struct V_20 * V_137 = V_136 -> V_30 ;
struct V_19 * V_134 = V_120 -> V_54 -> V_56 ;
struct V_20 * V_135 = V_134 -> V_30 ;
V_135 -> V_14 = V_137 -> V_14 ;
}
F_37 ( V_120 ) ;
F_56 ( & V_130 -> V_25 ) ;
return 0 ;
}
static int F_59 ( char * V_138 ,
struct V_80 * V_81 )
{
char * V_139 ;
char * V_83 = NULL , * V_140 = NULL ;
char * V_141 = NULL , * V_142 = NULL ;
int V_47 , V_89 = 0 ;
V_81 -> V_89 = 0 ;
while ( ( V_139 = F_60 ( & V_138 , L_23 ) ) != NULL ) {
int V_143 ;
T_3 args [ V_144 ] ;
if ( ! * V_139 )
continue;
V_143 = F_61 ( V_139 , V_145 , args ) ;
switch ( V_143 ) {
case V_146 :
if ( V_83 || V_140 ) {
V_47 = - V_86 ;
F_38 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_147;
}
V_83 = F_62 ( & args [ 0 ] ) ;
if ( ! V_83 ) {
V_47 = - V_24 ;
goto V_147;
}
break;
case V_148 :
if ( V_141 ) {
V_47 = - V_86 ;
F_38 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_147;
}
V_141 = F_62 ( & args [ 0 ] ) ;
if ( ! V_141 ) {
V_47 = - V_24 ;
goto V_147;
}
break;
case V_149 :
if ( V_142 ) {
V_47 = - V_86 ;
F_38 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_147;
}
V_142 = F_62 ( & args [ 0 ] ) ;
if ( ! V_142 ) {
V_47 = - V_24 ;
goto V_147;
}
break;
case V_150 :
if ( V_83 || V_140 ) {
V_47 = - V_86 ;
F_38 (KERN_WARNING SEL_MOUNT_FAIL_MSG) ;
goto V_147;
}
V_140 = F_62 ( & args [ 0 ] ) ;
if ( ! V_140 ) {
V_47 = - V_24 ;
goto V_147;
}
break;
case V_151 :
break;
default:
V_47 = - V_86 ;
F_38 ( V_61 L_24 ) ;
goto V_147;
}
}
V_47 = - V_24 ;
V_81 -> V_90 = F_46 ( V_152 , sizeof( char * ) , V_91 ) ;
if ( ! V_81 -> V_90 )
goto V_147;
V_81 -> V_93 = F_46 ( V_152 , sizeof( int ) , V_91 ) ;
if ( ! V_81 -> V_93 ) {
F_28 ( V_81 -> V_90 ) ;
goto V_147;
}
if ( V_141 ) {
V_81 -> V_90 [ V_89 ] = V_141 ;
V_81 -> V_93 [ V_89 ++ ] = V_94 ;
}
if ( V_83 ) {
V_81 -> V_90 [ V_89 ] = V_83 ;
V_81 -> V_93 [ V_89 ++ ] = V_95 ;
}
if ( V_142 ) {
V_81 -> V_90 [ V_89 ] = V_142 ;
V_81 -> V_93 [ V_89 ++ ] = V_97 ;
}
if ( V_140 ) {
V_81 -> V_90 [ V_89 ] = V_140 ;
V_81 -> V_93 [ V_89 ++ ] = V_96 ;
}
V_81 -> V_89 = V_89 ;
return 0 ;
V_147:
F_28 ( V_83 ) ;
F_28 ( V_140 ) ;
F_28 ( V_141 ) ;
F_28 ( V_142 ) ;
return V_47 ;
}
static int F_63 ( struct V_41 * V_42 , void * V_153 )
{
int V_47 = 0 ;
char * V_138 = V_153 ;
struct V_80 V_81 ;
F_45 ( & V_81 ) ;
if ( ! V_153 )
goto V_66;
F_48 ( V_42 -> V_63 -> V_111 & V_112 ) ;
V_47 = F_59 ( V_138 , & V_81 ) ;
if ( V_47 )
goto V_147;
V_66:
V_47 = F_51 ( V_42 , & V_81 , 0 , NULL ) ;
V_147:
F_49 ( & V_81 ) ;
return V_47 ;
}
static void F_64 ( struct V_154 * V_155 ,
struct V_80 * V_81 )
{
int V_82 ;
char * V_156 ;
for ( V_82 = 0 ; V_82 < V_81 -> V_89 ; V_82 ++ ) {
char * V_157 ;
if ( V_81 -> V_90 [ V_82 ] )
V_157 = strchr ( V_81 -> V_90 [ V_82 ] , ',' ) ;
else
V_157 = NULL ;
switch ( V_81 -> V_93 [ V_82 ] ) {
case V_95 :
V_156 = V_158 ;
break;
case V_94 :
V_156 = V_159 ;
break;
case V_97 :
V_156 = V_160 ;
break;
case V_96 :
V_156 = V_161 ;
break;
case V_71 :
F_65 ( V_155 , ',' ) ;
F_66 ( V_155 , V_162 ) ;
continue;
default:
F_67 () ;
return;
} ;
F_65 ( V_155 , ',' ) ;
F_66 ( V_155 , V_156 ) ;
if ( V_157 )
F_65 ( V_155 , '\"' ) ;
F_66 ( V_155 , V_81 -> V_90 [ V_82 ] ) ;
if ( V_157 )
F_65 ( V_155 , '\"' ) ;
}
}
static int F_68 ( struct V_154 * V_155 , struct V_41 * V_42 )
{
struct V_80 V_81 ;
int V_47 ;
V_47 = F_44 ( V_42 , & V_81 ) ;
if ( V_47 ) {
if ( V_47 == - V_86 )
V_47 = 0 ;
return V_47 ;
}
F_64 ( V_155 , & V_81 ) ;
F_49 ( & V_81 ) ;
return V_47 ;
}
static inline T_4 F_69 ( T_5 V_163 )
{
switch ( V_163 & V_164 ) {
case V_165 :
return V_166 ;
case V_167 :
return V_168 ;
case V_169 :
return V_29 ;
case V_170 :
return V_171 ;
case V_172 :
return V_173 ;
case V_174 :
return V_175 ;
case V_176 :
return V_177 ;
}
return V_29 ;
}
static inline int F_70 ( int V_178 )
{
return ( V_178 == V_179 || V_178 == V_180 ) ;
}
static inline int F_71 ( int V_178 )
{
return ( V_178 == V_179 || V_178 == V_181 ) ;
}
static inline T_4 F_72 ( int V_182 , int type , int V_178 )
{
switch ( V_182 ) {
case V_183 :
switch ( type ) {
case V_184 :
case V_185 :
return V_186 ;
case V_187 :
return V_188 ;
}
break;
case V_189 :
case V_190 :
switch ( type ) {
case V_184 :
if ( F_70 ( V_178 ) )
return V_191 ;
else
return V_192 ;
case V_187 :
if ( F_71 ( V_178 ) )
return V_193 ;
else
return V_192 ;
case V_194 :
return V_195 ;
default:
return V_192 ;
}
break;
case V_196 :
switch ( V_178 ) {
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
case V_213 :
return V_214 ;
case V_215 :
return V_216 ;
default:
return V_217 ;
}
case V_218 :
return V_219 ;
case V_220 :
return V_221 ;
case V_222 :
return V_223 ;
}
return V_224 ;
}
static int F_73 ( struct V_52 * V_52 ,
T_4 V_225 ,
T_2 * V_14 )
{
int V_47 ;
char * V_226 , * V_227 ;
V_226 = ( char * ) F_74 ( V_12 ) ;
if ( ! V_226 )
return - V_24 ;
V_227 = F_75 ( V_52 , V_226 , V_228 ) ;
if ( F_76 ( V_227 ) )
V_47 = F_77 ( V_227 ) ;
else {
while ( V_227 [ 1 ] >= '0' && V_227 [ 1 ] <= '9' ) {
V_227 [ 1 ] = '/' ;
V_227 ++ ;
}
V_47 = F_78 ( L_14 , V_227 , V_225 , V_14 ) ;
}
F_79 ( ( unsigned long ) V_226 ) ;
return V_47 ;
}
static int F_73 ( struct V_52 * V_52 ,
T_4 V_225 ,
T_2 * V_14 )
{
return - V_86 ;
}
static int F_33 ( struct V_19 * V_19 , struct V_52 * V_229 )
{
struct V_31 * V_32 = NULL ;
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_14 ;
struct V_52 * V_52 ;
#define F_80 255
char * V_83 = NULL ;
unsigned V_84 = 0 ;
int V_47 = 0 ;
if ( V_21 -> V_118 )
goto V_66;
F_53 ( & V_21 -> V_25 ) ;
if ( V_21 -> V_118 )
goto V_230;
V_32 = V_19 -> V_33 -> V_34 ;
if ( ! ( V_32 -> V_69 & V_70 ) ) {
F_21 ( & V_32 -> V_35 ) ;
if ( F_22 ( & V_21 -> V_26 ) )
F_81 ( & V_21 -> V_26 , & V_32 -> V_43 ) ;
F_24 ( & V_32 -> V_35 ) ;
goto V_230;
}
switch ( V_32 -> V_57 ) {
case V_117 :
break;
case V_58 :
if ( ! V_19 -> V_59 -> V_60 ) {
V_21 -> V_14 = V_32 -> V_44 ;
break;
}
if ( V_229 ) {
V_52 = F_82 ( V_229 ) ;
} else {
V_52 = F_83 ( V_19 ) ;
}
if ( ! V_52 ) {
goto V_230;
}
V_84 = F_80 ;
V_83 = F_84 ( V_84 + 1 , V_23 ) ;
if ( ! V_83 ) {
V_47 = - V_24 ;
F_85 ( V_52 ) ;
goto V_230;
}
V_83 [ V_84 ] = '\0' ;
V_47 = V_19 -> V_59 -> V_60 ( V_52 , V_67 ,
V_83 , V_84 ) ;
if ( V_47 == - V_231 ) {
F_28 ( V_83 ) ;
V_47 = V_19 -> V_59 -> V_60 ( V_52 , V_67 ,
NULL , 0 ) ;
if ( V_47 < 0 ) {
F_85 ( V_52 ) ;
goto V_230;
}
V_84 = V_47 ;
V_83 = F_84 ( V_84 + 1 , V_23 ) ;
if ( ! V_83 ) {
V_47 = - V_24 ;
F_85 ( V_52 ) ;
goto V_230;
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
L_26 , V_115 ,
- V_47 , V_19 -> V_33 -> V_62 , V_19 -> V_232 ) ;
F_28 ( V_83 ) ;
goto V_230;
}
V_14 = V_32 -> V_44 ;
V_47 = 0 ;
} else {
V_47 = F_86 ( V_83 , V_47 , & V_14 ,
V_32 -> V_44 ,
V_23 ) ;
if ( V_47 ) {
char * V_233 = V_19 -> V_33 -> V_62 ;
unsigned long V_234 = V_19 -> V_232 ;
if ( V_47 == - V_86 ) {
if ( F_87 () )
F_38 ( V_235 L_27
L_28
L_29 , V_234 , V_233 , V_83 ) ;
} else {
F_38 ( V_61 L_30
L_31 ,
V_115 , V_83 , - V_47 , V_233 , V_234 ) ;
}
F_28 ( V_83 ) ;
V_47 = 0 ;
break;
}
}
F_28 ( V_83 ) ;
V_21 -> V_14 = V_14 ;
break;
case V_236 :
V_21 -> V_14 = V_21 -> F_10 ;
break;
case V_237 :
V_21 -> V_14 = V_32 -> V_14 ;
V_21 -> V_28 = F_69 ( V_19 -> V_238 ) ;
V_47 = F_88 ( V_21 -> F_10 , V_32 -> V_14 ,
V_21 -> V_28 , NULL , & V_14 ) ;
if ( V_47 )
goto V_230;
V_21 -> V_14 = V_14 ;
break;
case V_76 :
V_21 -> V_14 = V_32 -> V_46 ;
break;
default:
V_21 -> V_14 = V_32 -> V_14 ;
if ( ( V_32 -> V_69 & V_114 ) && ! F_89 ( V_19 -> V_238 ) ) {
if ( V_229 ) {
V_21 -> V_28 = F_69 ( V_19 -> V_238 ) ;
V_47 = F_73 ( V_229 ,
V_21 -> V_28 ,
& V_14 ) ;
if ( V_47 )
goto V_230;
V_21 -> V_14 = V_14 ;
}
}
break;
}
V_21 -> V_118 = 1 ;
V_230:
F_56 ( & V_21 -> V_25 ) ;
V_66:
if ( V_21 -> V_28 == V_29 )
V_21 -> V_28 = F_69 ( V_19 -> V_238 ) ;
return V_47 ;
}
static inline T_2 F_90 ( int V_239 )
{
T_2 V_240 = 0 ;
switch ( V_239 ) {
case V_241 :
V_240 = V_242 ;
break;
case V_243 :
V_240 = V_244 ;
break;
case V_245 :
V_240 = V_246 ;
break;
default:
V_240 = V_247 ;
break;
}
return V_240 ;
}
static int F_91 ( const struct V_7 * V_248 ,
const struct V_7 * V_249 ,
T_2 V_250 )
{
T_2 V_251 = F_9 ( V_248 ) , V_252 = F_9 ( V_249 ) ;
return F_35 ( V_251 , V_252 , V_253 , V_250 , NULL ) ;
}
static int F_92 ( const struct V_17 * V_254 ,
const struct V_17 * V_255 ,
T_2 V_250 )
{
const struct V_10 * V_256 , * V_257 ;
T_2 V_258 , V_259 ;
F_11 () ;
V_256 = F_12 ( V_254 ) -> V_16 ; V_258 = V_256 -> V_14 ;
V_257 = F_12 ( V_255 ) -> V_16 ; V_259 = V_257 -> V_14 ;
F_13 () ;
return F_35 ( V_258 , V_259 , V_253 , V_250 , NULL ) ;
}
static int F_93 ( const struct V_17 * V_260 ,
T_2 V_250 )
{
T_2 V_14 , V_252 ;
V_14 = F_14 () ;
V_252 = F_10 ( V_260 ) ;
return F_35 ( V_14 , V_252 , V_253 , V_250 , NULL ) ;
}
static int F_94 ( const struct V_7 * V_7 ,
int V_261 , int V_262 )
{
struct V_263 V_264 ;
struct V_265 V_266 ;
T_4 V_28 ;
T_2 V_14 = F_9 ( V_7 ) ;
T_2 V_267 = F_95 ( V_261 ) ;
int V_47 ;
V_264 . type = V_268 ;
V_264 . V_269 . V_261 = V_261 ;
switch ( F_96 ( V_261 ) ) {
case 0 :
V_28 = V_270 ;
break;
case 1 :
V_28 = V_271 ;
break;
default:
F_38 ( V_73
L_32 , V_261 ) ;
F_67 () ;
return - V_86 ;
}
V_47 = F_97 ( V_14 , V_14 , V_28 , V_267 , 0 , & V_266 ) ;
if ( V_262 == V_272 ) {
int V_273 = F_98 ( V_14 , V_14 , V_28 , V_267 , & V_266 , V_47 , & V_264 , 0 ) ;
if ( V_273 )
return V_273 ;
}
return V_47 ;
}
static int F_99 ( struct V_17 * V_260 ,
T_2 V_250 )
{
T_2 V_14 = F_10 ( V_260 ) ;
return F_35 ( V_14 , V_15 ,
V_274 , V_250 , NULL ) ;
}
static int F_100 ( const struct V_7 * V_7 ,
struct V_19 * V_19 ,
T_2 V_250 ,
struct V_263 * V_275 ,
unsigned V_69 )
{
struct V_20 * V_21 ;
T_2 V_14 ;
F_101 ( V_7 ) ;
if ( F_102 ( F_42 ( V_19 ) ) )
return 0 ;
V_14 = F_9 ( V_7 ) ;
V_21 = V_19 -> V_30 ;
return F_103 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_250 , V_275 , V_69 ) ;
}
static inline int F_104 ( const struct V_7 * V_7 ,
struct V_52 * V_52 ,
T_2 V_267 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_263 V_264 ;
V_264 . type = V_276 ;
V_264 . V_269 . V_52 = V_52 ;
return F_100 ( V_7 , V_19 , V_267 , & V_264 , 0 ) ;
}
static inline int F_105 ( const struct V_7 * V_7 ,
struct V_227 * V_227 ,
T_2 V_267 )
{
struct V_19 * V_19 = V_227 -> V_52 -> V_56 ;
struct V_263 V_264 ;
V_264 . type = V_277 ;
V_264 . V_269 . V_227 = * V_227 ;
return F_100 ( V_7 , V_19 , V_267 , & V_264 , 0 ) ;
}
static inline int F_106 ( const struct V_7 * V_7 ,
struct V_36 * V_36 ,
T_2 V_267 )
{
struct V_263 V_264 ;
V_264 . type = V_277 ;
V_264 . V_269 . V_227 = V_36 -> V_278 ;
return F_100 ( V_7 , F_107 ( V_36 ) , V_267 , & V_264 , 0 ) ;
}
static int F_108 ( const struct V_7 * V_7 ,
struct V_36 * V_36 ,
T_2 V_267 )
{
struct V_37 * V_38 = V_36 -> V_40 ;
struct V_19 * V_19 = F_107 ( V_36 ) ;
struct V_263 V_264 ;
T_2 V_14 = F_9 ( V_7 ) ;
int V_47 ;
V_264 . type = V_277 ;
V_264 . V_269 . V_227 = V_36 -> V_278 ;
if ( V_14 != V_38 -> V_14 ) {
V_47 = F_35 ( V_14 , V_38 -> V_14 ,
V_279 ,
V_280 ,
& V_264 ) ;
if ( V_47 )
goto V_66;
}
V_47 = 0 ;
if ( V_267 )
V_47 = F_100 ( V_7 , V_19 , V_267 , & V_264 , 0 ) ;
V_66:
return V_47 ;
}
static int F_109 ( struct V_19 * V_281 ,
struct V_52 * V_52 ,
T_4 V_225 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_282 ;
struct V_31 * V_32 ;
T_2 V_14 , V_283 ;
struct V_263 V_264 ;
int V_47 ;
V_282 = V_281 -> V_30 ;
V_32 = V_281 -> V_33 -> V_34 ;
V_14 = V_11 -> V_14 ;
V_283 = V_11 -> V_284 ;
V_264 . type = V_276 ;
V_264 . V_269 . V_52 = V_52 ;
V_47 = F_35 ( V_14 , V_282 -> V_14 , V_173 ,
V_285 | V_286 ,
& V_264 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_283 || ! ( V_32 -> V_69 & V_71 ) ) {
V_47 = F_88 ( V_14 , V_282 -> V_14 , V_225 ,
& V_52 -> V_287 , & V_283 ) ;
if ( V_47 )
return V_47 ;
}
V_47 = F_35 ( V_14 , V_283 , V_225 , V_288 , & V_264 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_283 , V_32 -> V_14 ,
V_48 ,
V_51 , & V_264 ) ;
}
static int F_110 ( T_2 V_289 ,
struct V_17 * V_290 )
{
T_2 V_14 = F_10 ( V_290 ) ;
return F_35 ( V_14 , V_289 , V_291 , V_292 , NULL ) ;
}
static int F_111 ( struct V_19 * V_281 ,
struct V_52 * V_52 ,
int V_293 )
{
struct V_20 * V_282 , * V_21 ;
struct V_263 V_264 ;
T_2 V_14 = F_14 () ;
T_2 V_267 ;
int V_47 ;
V_282 = V_281 -> V_30 ;
V_21 = V_52 -> V_56 -> V_30 ;
V_264 . type = V_276 ;
V_264 . V_269 . V_52 = V_52 ;
V_267 = V_286 ;
V_267 |= ( V_293 ? V_294 : V_285 ) ;
V_47 = F_35 ( V_14 , V_282 -> V_14 , V_173 , V_267 , & V_264 ) ;
if ( V_47 )
return V_47 ;
switch ( V_293 ) {
case V_295 :
V_267 = V_296 ;
break;
case V_297 :
V_267 = V_298 ;
break;
case V_299 :
V_267 = V_300 ;
break;
default:
F_38 ( V_61 L_33 ,
V_115 , V_293 ) ;
return 0 ;
}
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_267 , & V_264 ) ;
return V_47 ;
}
static inline int F_112 ( struct V_19 * V_301 ,
struct V_52 * V_302 ,
struct V_19 * V_303 ,
struct V_52 * V_304 )
{
struct V_20 * V_305 , * V_306 , * V_307 , * V_308 ;
struct V_263 V_264 ;
T_2 V_14 = F_14 () ;
T_2 V_267 ;
int V_309 , V_310 ;
int V_47 ;
V_305 = V_301 -> V_30 ;
V_307 = V_302 -> V_56 -> V_30 ;
V_309 = F_113 ( V_302 -> V_56 -> V_238 ) ;
V_306 = V_303 -> V_30 ;
V_264 . type = V_276 ;
V_264 . V_269 . V_52 = V_302 ;
V_47 = F_35 ( V_14 , V_305 -> V_14 , V_173 ,
V_294 | V_286 , & V_264 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_14 , V_307 -> V_14 ,
V_307 -> V_28 , V_311 , & V_264 ) ;
if ( V_47 )
return V_47 ;
if ( V_309 && V_303 != V_301 ) {
V_47 = F_35 ( V_14 , V_307 -> V_14 ,
V_307 -> V_28 , V_312 , & V_264 ) ;
if ( V_47 )
return V_47 ;
}
V_264 . V_269 . V_52 = V_304 ;
V_267 = V_285 | V_286 ;
if ( V_304 -> V_56 )
V_267 |= V_294 ;
V_47 = F_35 ( V_14 , V_306 -> V_14 , V_173 , V_267 , & V_264 ) ;
if ( V_47 )
return V_47 ;
if ( V_304 -> V_56 ) {
V_308 = V_304 -> V_56 -> V_30 ;
V_310 = F_113 ( V_304 -> V_56 -> V_238 ) ;
V_47 = F_35 ( V_14 , V_308 -> V_14 ,
V_308 -> V_28 ,
( V_310 ? V_300 : V_298 ) , & V_264 ) ;
if ( V_47 )
return V_47 ;
}
return 0 ;
}
static int F_114 ( const struct V_7 * V_7 ,
struct V_41 * V_42 ,
T_2 V_250 ,
struct V_263 * V_264 )
{
struct V_31 * V_32 ;
T_2 V_14 = F_9 ( V_7 ) ;
V_32 = V_42 -> V_34 ;
return F_35 ( V_14 , V_32 -> V_14 , V_48 , V_250 , V_264 ) ;
}
static inline T_2 F_115 ( int V_163 , int V_313 )
{
T_2 V_267 = 0 ;
if ( ! F_113 ( V_163 ) ) {
if ( V_313 & V_314 )
V_267 |= V_315 ;
if ( V_313 & V_316 )
V_267 |= V_317 ;
if ( V_313 & V_318 )
V_267 |= V_319 ;
else if ( V_313 & V_320 )
V_267 |= V_321 ;
} else {
if ( V_313 & V_314 )
V_267 |= V_286 ;
if ( V_313 & V_320 )
V_267 |= V_322 ;
if ( V_313 & V_316 )
V_267 |= V_323 ;
}
return V_267 ;
}
static inline T_2 F_116 ( struct V_36 * V_36 )
{
T_2 V_267 = 0 ;
if ( V_36 -> V_324 & V_325 )
V_267 |= V_317 ;
if ( V_36 -> V_324 & V_326 ) {
if ( V_36 -> V_327 & V_328 )
V_267 |= V_319 ;
else
V_267 |= V_321 ;
}
if ( ! V_267 ) {
V_267 = V_329 ;
}
return V_267 ;
}
static inline T_2 F_117 ( struct V_36 * V_36 )
{
T_2 V_267 = F_116 ( V_36 ) ;
if ( V_330 )
V_267 |= V_331 ;
return V_267 ;
}
static int F_118 ( struct V_17 * V_332 ,
unsigned int V_163 )
{
int V_47 ;
V_47 = F_119 ( V_332 , V_163 ) ;
if ( V_47 )
return V_47 ;
if ( V_163 & V_333 ) {
T_2 V_14 = F_14 () ;
T_2 V_334 = F_10 ( V_332 ) ;
return F_35 ( V_14 , V_334 , V_29 , V_317 , NULL ) ;
}
return F_93 ( V_332 , V_335 ) ;
}
static int F_120 ( struct V_17 * V_336 )
{
int V_47 ;
V_47 = F_121 ( V_336 ) ;
if ( V_47 )
return V_47 ;
return F_92 ( V_336 , V_8 , V_335 ) ;
}
static int F_122 ( struct V_17 * V_249 , T_6 * V_337 ,
T_6 * V_338 , T_6 * V_339 )
{
int error ;
error = F_93 ( V_249 , V_340 ) ;
if ( error )
return error ;
return F_123 ( V_249 , V_337 , V_338 , V_339 ) ;
}
static int F_124 ( struct V_7 * V_122 , const struct V_7 * V_121 ,
const T_6 * V_337 ,
const T_6 * V_338 ,
const T_6 * V_339 )
{
int error ;
error = F_125 ( V_122 , V_121 ,
V_337 , V_338 , V_339 ) ;
if ( error )
return error ;
return F_91 ( V_121 , V_122 , V_341 ) ;
}
static int F_126 ( const struct V_7 * V_7 , struct V_342 * V_343 ,
int V_261 , int V_262 )
{
int V_47 ;
V_47 = F_127 ( V_7 , V_343 , V_261 , V_262 ) ;
if ( V_47 )
return V_47 ;
return F_94 ( V_7 , V_261 , V_262 ) ;
}
static int F_128 ( int V_344 , int type , int V_345 , struct V_41 * V_42 )
{
const struct V_7 * V_7 = F_52 () ;
int V_47 = 0 ;
if ( ! V_42 )
return 0 ;
switch ( V_344 ) {
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
V_47 = F_114 ( V_7 , V_42 , V_351 , NULL ) ;
break;
case V_352 :
case V_353 :
case V_354 :
V_47 = F_114 ( V_7 , V_42 , V_355 , NULL ) ;
break;
default:
V_47 = 0 ;
break;
}
return V_47 ;
}
static int F_129 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
return F_104 ( V_7 , V_52 , V_356 ) ;
}
static int F_130 ( int type )
{
int V_47 ;
switch ( type ) {
case V_357 :
case V_358 :
V_47 = F_99 ( V_8 , V_359 ) ;
break;
case V_360 :
case V_361 :
case V_362 :
V_47 = F_99 ( V_8 , V_363 ) ;
break;
case V_364 :
case V_365 :
case V_366 :
case V_367 :
case V_368 :
default:
V_47 = F_99 ( V_8 , V_369 ) ;
break;
}
return V_47 ;
}
static int F_131 ( struct V_370 * V_371 , long V_372 )
{
int V_47 , V_373 = 0 ;
V_47 = F_126 ( F_52 () , & V_374 , V_375 ,
V_376 ) ;
if ( V_47 == 0 )
V_373 = 1 ;
return F_132 ( V_371 , V_372 , V_373 ) ;
}
static int F_133 ( struct V_377 * V_378 )
{
const struct V_10 * V_379 ;
struct V_10 * V_380 ;
struct V_20 * V_21 ;
struct V_263 V_264 ;
struct V_19 * V_19 = F_107 ( V_378 -> V_36 ) ;
int V_47 ;
V_47 = F_134 ( V_378 ) ;
if ( V_47 )
return V_47 ;
if ( V_378 -> V_381 )
return 0 ;
V_379 = F_15 () ;
V_380 = V_378 -> V_7 -> V_16 ;
V_21 = V_19 -> V_30 ;
V_380 -> V_14 = V_379 -> V_14 ;
V_380 -> V_13 = V_379 -> V_14 ;
V_380 -> V_284 = 0 ;
V_380 -> V_382 = 0 ;
V_380 -> V_383 = 0 ;
if ( V_379 -> V_384 ) {
V_380 -> V_14 = V_379 -> V_384 ;
V_380 -> V_384 = 0 ;
if ( V_378 -> V_385 & V_386 )
return - V_387 ;
} else {
V_47 = F_88 ( V_379 -> V_14 , V_21 -> V_14 ,
V_253 , NULL ,
& V_380 -> V_14 ) ;
if ( V_47 )
return V_47 ;
}
V_264 . type = V_277 ;
V_264 . V_269 . V_227 = V_378 -> V_36 -> V_278 ;
if ( ( V_378 -> V_36 -> V_278 . V_388 -> V_101 & V_389 ) ||
( V_378 -> V_385 & V_386 ) )
V_380 -> V_14 = V_379 -> V_14 ;
if ( V_380 -> V_14 == V_379 -> V_14 ) {
V_47 = F_35 ( V_379 -> V_14 , V_21 -> V_14 ,
V_29 , V_390 , & V_264 ) ;
if ( V_47 )
return V_47 ;
} else {
V_47 = F_35 ( V_379 -> V_14 , V_380 -> V_14 ,
V_253 , V_391 , & V_264 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_380 -> V_14 , V_21 -> V_14 ,
V_29 , V_392 , & V_264 ) ;
if ( V_47 )
return V_47 ;
if ( V_378 -> V_385 & V_393 ) {
V_47 = F_35 ( V_379 -> V_14 , V_380 -> V_14 ,
V_253 , V_394 ,
NULL ) ;
if ( V_47 )
return - V_387 ;
}
if ( V_378 -> V_385 &
( V_395 | V_396 ) ) {
struct V_17 * V_397 ;
struct V_10 * V_398 ;
T_2 V_399 = 0 ;
F_11 () ;
V_397 = F_135 ( V_8 ) ;
if ( F_136 ( V_397 != NULL ) ) {
V_398 = F_12 ( V_397 ) -> V_16 ;
V_399 = V_398 -> V_14 ;
}
F_13 () ;
if ( V_399 != 0 ) {
V_47 = F_35 ( V_399 , V_380 -> V_14 ,
V_253 ,
V_335 , NULL ) ;
if ( V_47 )
return - V_387 ;
}
}
V_378 -> V_400 |= V_401 ;
}
return 0 ;
}
static int F_137 ( struct V_377 * V_378 )
{
const struct V_10 * V_11 = F_15 () ;
T_2 V_14 , V_13 ;
int V_402 = 0 ;
V_14 = V_11 -> V_14 ;
V_13 = V_11 -> V_13 ;
if ( V_13 != V_14 ) {
V_402 = F_35 ( V_13 , V_14 ,
V_253 ,
V_403 , NULL ) ;
}
return ( V_402 || F_138 ( V_378 ) ) ;
}
static int F_139 ( const void * V_139 , struct V_36 * V_36 , unsigned V_404 )
{
return F_108 ( V_139 , V_36 , F_116 ( V_36 ) ) ? V_404 + 1 : 0 ;
}
static inline void F_140 ( const struct V_7 * V_7 ,
struct V_405 * V_406 )
{
struct V_36 * V_36 , * V_407 = NULL ;
struct V_408 * V_409 ;
int V_410 = 0 ;
unsigned V_411 ;
V_409 = F_141 () ;
if ( V_409 ) {
F_21 ( & V_412 ) ;
if ( ! F_22 ( & V_409 -> V_413 ) ) {
struct V_414 * V_415 ;
V_415 = F_142 ( & V_409 -> V_413 ,
struct V_414 , V_26 ) ;
V_36 = V_415 -> V_36 ;
if ( F_106 ( V_7 , V_36 , V_317 | V_321 ) )
V_410 = 1 ;
}
F_24 ( & V_412 ) ;
F_143 ( V_409 ) ;
}
if ( V_410 )
F_144 () ;
V_411 = F_145 ( V_406 , 0 , F_139 , V_7 ) ;
if ( ! V_411 )
return;
V_407 = F_146 ( & V_416 , V_417 , V_7 ) ;
if ( F_76 ( V_407 ) )
V_407 = NULL ;
do {
F_147 ( V_411 - 1 , V_407 , 0 ) ;
} while ( ( V_411 = F_145 ( V_406 , V_411 , F_139 , V_7 ) ) != 0 );
if ( V_407 )
F_148 ( V_407 ) ;
}
static void F_149 ( struct V_377 * V_378 )
{
struct V_10 * V_380 ;
struct V_418 * V_419 , * V_420 ;
int V_47 , V_82 ;
V_380 = V_378 -> V_7 -> V_16 ;
if ( V_380 -> V_14 == V_380 -> V_13 )
return;
F_140 ( V_378 -> V_7 , V_8 -> V_406 ) ;
V_8 -> V_421 = 0 ;
V_47 = F_35 ( V_380 -> V_13 , V_380 -> V_14 , V_253 ,
V_422 , NULL ) ;
if ( V_47 ) {
F_150 ( V_8 ) ;
for ( V_82 = 0 ; V_82 < V_423 ; V_82 ++ ) {
V_419 = V_8 -> signal -> V_419 + V_82 ;
V_420 = V_424 . signal -> V_419 + V_82 ;
V_419 -> V_425 = F_151 ( V_419 -> V_426 , V_420 -> V_425 ) ;
}
F_152 ( V_8 ) ;
F_153 ( V_8 , V_418 ( V_427 ) ) ;
}
}
static void F_154 ( struct V_377 * V_378 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_428 V_429 ;
T_2 V_13 , V_14 ;
int V_47 , V_82 ;
V_13 = V_11 -> V_13 ;
V_14 = V_11 -> V_14 ;
if ( V_14 == V_13 )
return;
V_47 = F_35 ( V_13 , V_14 , V_253 , V_430 , NULL ) ;
if ( V_47 ) {
memset ( & V_429 , 0 , sizeof V_429 ) ;
for ( V_82 = 0 ; V_82 < 3 ; V_82 ++ )
F_155 ( V_82 , & V_429 , NULL ) ;
F_156 ( & V_8 -> V_431 -> V_432 ) ;
if ( ! ( V_8 -> signal -> V_69 & V_433 ) ) {
F_157 ( V_8 ) ;
F_158 ( V_8 , 1 ) ;
F_159 ( & V_8 -> V_434 ) ;
}
F_160 ( & V_8 -> V_431 -> V_432 ) ;
}
F_161 ( & V_435 ) ;
F_162 ( V_8 , V_8 -> V_436 ) ;
F_163 ( & V_435 ) ;
}
static int F_164 ( struct V_41 * V_42 )
{
return F_29 ( V_42 ) ;
}
static void F_165 ( struct V_41 * V_42 )
{
F_31 ( V_42 ) ;
}
static inline int F_166 ( char * V_156 , int V_437 , char * V_438 , int V_439 )
{
if ( V_437 > V_439 )
return 0 ;
return ! memcmp ( V_156 , V_438 , V_437 ) ;
}
static inline int F_167 ( char * V_438 , int V_84 )
{
return ( F_166 ( V_158 , sizeof( V_158 ) - 1 , V_438 , V_84 ) ||
F_166 ( V_159 , sizeof( V_159 ) - 1 , V_438 , V_84 ) ||
F_166 ( V_161 , sizeof( V_161 ) - 1 , V_438 , V_84 ) ||
F_166 ( V_160 , sizeof( V_160 ) - 1 , V_438 , V_84 ) ||
F_166 ( V_162 , sizeof( V_162 ) - 1 , V_438 , V_84 ) ) ;
}
static inline void F_168 ( char * * V_440 , char * V_441 , int * V_442 , int V_84 )
{
if ( ! * V_442 ) {
* * V_440 = ',' ;
* V_440 += 1 ;
} else
* V_442 = 0 ;
memcpy ( * V_440 , V_441 , V_84 ) ;
* V_440 += V_84 ;
}
static inline void F_169 ( char * * V_440 , char * V_441 , int * V_442 ,
int V_84 )
{
int V_443 = 0 ;
if ( ! * V_442 ) {
* * V_440 = '|' ;
* V_440 += 1 ;
} else
* V_442 = 0 ;
while ( V_443 < V_84 ) {
if ( * V_441 != '"' ) {
* * V_440 = * V_441 ;
* V_440 += 1 ;
}
V_441 += 1 ;
V_443 += 1 ;
}
}
static int F_170 ( char * V_444 , char * V_445 )
{
int V_446 , V_38 , V_47 = 0 ;
char * V_447 , * V_448 , * V_449 ;
char * V_450 , * V_451 , * V_452 ;
int V_453 = 0 ;
V_448 = V_444 ;
V_450 = V_445 ;
V_452 = ( char * ) F_171 ( V_12 ) ;
if ( ! V_452 ) {
V_47 = - V_24 ;
goto V_66;
}
V_451 = V_452 ;
V_446 = V_38 = 1 ;
V_447 = V_449 = V_444 ;
do {
if ( * V_449 == '"' )
V_453 = ! V_453 ;
if ( ( * V_449 == ',' && V_453 == 0 ) ||
* V_449 == '\0' ) {
int V_84 = V_449 - V_448 ;
if ( F_167 ( V_448 , V_84 ) )
F_169 ( & V_450 , V_448 , & V_38 , V_84 ) ;
else
F_168 ( & V_452 , V_448 , & V_446 , V_84 ) ;
V_448 = V_449 + 1 ;
}
} while ( * V_449 ++ );
strcpy ( V_447 , V_451 ) ;
F_79 ( ( unsigned long ) V_451 ) ;
V_66:
return V_47 ;
}
static int F_172 ( struct V_41 * V_42 , void * V_153 )
{
int V_47 , V_82 , * V_69 ;
struct V_80 V_81 ;
char * V_454 , * * V_109 ;
struct V_31 * V_32 = V_42 -> V_34 ;
if ( ! ( V_32 -> V_69 & V_70 ) )
return 0 ;
if ( ! V_153 )
return 0 ;
if ( V_42 -> V_63 -> V_111 & V_112 )
return 0 ;
F_45 ( & V_81 ) ;
V_454 = F_173 () ;
if ( ! V_454 )
return - V_24 ;
V_47 = F_170 ( V_153 , V_454 ) ;
if ( V_47 )
goto V_455;
V_47 = F_59 ( V_454 , & V_81 ) ;
if ( V_47 )
goto V_455;
V_109 = V_81 . V_90 ;
V_69 = V_81 . V_93 ;
for ( V_82 = 0 ; V_82 < V_81 . V_89 ; V_82 ++ ) {
T_2 V_14 ;
T_7 V_84 ;
if ( V_69 [ V_82 ] == V_71 )
continue;
V_84 = strlen ( V_109 [ V_82 ] ) ;
V_47 = F_54 ( V_109 [ V_82 ] , V_84 , & V_14 ) ;
if ( V_47 ) {
F_38 ( V_61 L_12
L_13 ,
V_109 [ V_82 ] , V_42 -> V_62 , V_42 -> V_63 -> V_64 , V_47 ) ;
goto V_456;
}
V_47 = - V_86 ;
switch ( V_69 [ V_82 ] ) {
case V_94 :
if ( F_50 ( V_32 , V_94 , V_32 -> V_14 , V_14 ) )
goto V_457;
break;
case V_95 :
if ( F_50 ( V_32 , V_95 , V_32 -> V_46 , V_14 ) )
goto V_457;
break;
case V_97 : {
struct V_20 * V_104 ;
V_104 = V_42 -> V_54 -> V_56 -> V_30 ;
if ( F_50 ( V_32 , V_97 , V_104 -> V_14 , V_14 ) )
goto V_457;
break;
}
case V_96 :
if ( F_50 ( V_32 , V_96 , V_32 -> V_44 , V_14 ) )
goto V_457;
break;
default:
goto V_456;
}
}
V_47 = 0 ;
V_456:
F_49 ( & V_81 ) ;
V_455:
F_174 ( V_454 ) ;
return V_47 ;
V_457:
F_38 ( V_61 L_34
L_35 , V_42 -> V_62 ,
V_42 -> V_63 -> V_64 ) ;
goto V_456;
}
static int F_175 ( struct V_41 * V_42 , int V_69 , void * V_153 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_263 V_264 ;
int V_47 ;
V_47 = F_63 ( V_42 , V_153 ) ;
if ( V_47 )
return V_47 ;
if ( V_69 & V_458 )
return 0 ;
V_264 . type = V_276 ;
V_264 . V_269 . V_52 = V_42 -> V_54 ;
return F_114 ( V_7 , V_42 , V_459 , & V_264 ) ;
}
static int F_176 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_263 V_264 ;
V_264 . type = V_276 ;
V_264 . V_269 . V_52 = V_52 -> V_460 -> V_54 ;
return F_114 ( V_7 , V_52 -> V_460 , V_461 , & V_264 ) ;
}
static int F_177 ( const char * V_462 ,
struct V_227 * V_227 ,
const char * type ,
unsigned long V_69 ,
void * V_153 )
{
const struct V_7 * V_7 = F_52 () ;
if ( V_69 & V_463 )
return F_114 ( V_7 , V_227 -> V_52 -> V_460 ,
V_464 , NULL ) ;
else
return F_105 ( V_7 , V_227 , V_465 ) ;
}
static int F_178 ( struct V_466 * V_388 , int V_69 )
{
const struct V_7 * V_7 = F_52 () ;
return F_114 ( V_7 , V_388 -> V_467 ,
V_468 , NULL ) ;
}
static int F_179 ( struct V_19 * V_19 )
{
return F_16 ( V_19 ) ;
}
static void F_180 ( struct V_19 * V_19 )
{
F_20 ( V_19 ) ;
}
static int F_181 ( struct V_52 * V_52 , int V_163 ,
struct V_469 * V_64 , void * * V_290 ,
T_2 * V_470 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_10 * V_11 ;
struct V_20 * V_282 ;
struct V_31 * V_32 ;
struct V_19 * V_281 = V_52 -> V_471 -> V_56 ;
T_2 V_283 ;
int V_47 ;
V_11 = V_7 -> V_16 ;
V_282 = V_281 -> V_30 ;
V_32 = V_281 -> V_33 -> V_34 ;
if ( V_11 -> V_284 && V_32 -> V_57 != V_76 ) {
V_283 = V_11 -> V_284 ;
} else {
V_47 = F_88 ( V_11 -> V_14 , V_282 -> V_14 ,
F_69 ( V_163 ) ,
V_64 ,
& V_283 ) ;
if ( V_47 ) {
F_38 ( V_61
L_36 ,
V_115 , - V_47 ) ;
return V_47 ;
}
}
return F_47 ( V_283 , ( char * * ) V_290 , V_470 ) ;
}
static int F_182 ( struct V_19 * V_19 , struct V_19 * V_281 ,
const struct V_469 * V_469 , char * * V_64 ,
void * * V_472 , T_7 * V_84 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_282 ;
struct V_31 * V_32 ;
T_2 V_14 , V_283 , V_473 ;
int V_47 ;
char * V_474 = NULL , * V_83 ;
V_282 = V_281 -> V_30 ;
V_32 = V_281 -> V_33 -> V_34 ;
V_14 = V_11 -> V_14 ;
V_283 = V_11 -> V_284 ;
if ( ( V_32 -> V_69 & V_70 ) &&
( V_32 -> V_57 == V_76 ) )
V_283 = V_32 -> V_46 ;
else if ( ! V_283 || ! ( V_32 -> V_69 & V_71 ) ) {
V_47 = F_88 ( V_14 , V_282 -> V_14 ,
F_69 ( V_19 -> V_238 ) ,
V_469 , & V_283 ) ;
if ( V_47 ) {
F_38 ( V_61 L_37
L_38
L_39 ,
V_115 ,
- V_47 , V_19 -> V_33 -> V_62 , V_19 -> V_232 ) ;
return V_47 ;
}
}
if ( V_32 -> V_69 & V_70 ) {
struct V_20 * V_21 = V_19 -> V_30 ;
V_21 -> V_28 = F_69 ( V_19 -> V_238 ) ;
V_21 -> V_14 = V_283 ;
V_21 -> V_118 = 1 ;
}
if ( ! V_87 || ! ( V_32 -> V_69 & V_71 ) )
return - V_65 ;
if ( V_64 ) {
V_474 = F_183 ( V_475 , V_23 ) ;
if ( ! V_474 )
return - V_24 ;
* V_64 = V_474 ;
}
if ( V_472 && V_84 ) {
V_47 = F_184 ( V_283 , & V_83 , & V_473 ) ;
if ( V_47 ) {
F_28 ( V_474 ) ;
return V_47 ;
}
* V_472 = V_83 ;
* V_84 = V_473 ;
}
return 0 ;
}
static int F_185 ( struct V_19 * V_281 , struct V_52 * V_52 , T_5 V_163 )
{
return F_109 ( V_281 , V_52 , V_29 ) ;
}
static int F_186 ( struct V_52 * V_302 , struct V_19 * V_281 , struct V_52 * V_304 )
{
return F_111 ( V_281 , V_302 , V_295 ) ;
}
static int F_187 ( struct V_19 * V_281 , struct V_52 * V_52 )
{
return F_111 ( V_281 , V_52 , V_297 ) ;
}
static int F_188 ( struct V_19 * V_281 , struct V_52 * V_52 , const char * V_64 )
{
return F_109 ( V_281 , V_52 , V_168 ) ;
}
static int F_189 ( struct V_19 * V_281 , struct V_52 * V_52 , T_5 V_313 )
{
return F_109 ( V_281 , V_52 , V_173 ) ;
}
static int F_190 ( struct V_19 * V_281 , struct V_52 * V_52 )
{
return F_111 ( V_281 , V_52 , V_299 ) ;
}
static int F_191 ( struct V_19 * V_281 , struct V_52 * V_52 , T_5 V_163 , T_8 V_233 )
{
return F_109 ( V_281 , V_52 , F_69 ( V_163 ) ) ;
}
static int F_192 ( struct V_19 * V_476 , struct V_52 * V_302 ,
struct V_19 * V_477 , struct V_52 * V_304 )
{
return F_112 ( V_476 , V_302 , V_477 , V_304 ) ;
}
static int F_193 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
return F_104 ( V_7 , V_52 , V_317 ) ;
}
static int F_194 ( struct V_52 * V_52 , struct V_478 * V_478 )
{
const struct V_7 * V_7 = F_52 () ;
return F_104 ( V_7 , V_52 , V_317 ) ;
}
static T_9 int F_195 ( struct V_19 * V_19 ,
T_2 V_250 , T_2 V_479 , T_2 V_480 ,
unsigned V_69 )
{
struct V_263 V_264 ;
struct V_20 * V_21 = V_19 -> V_30 ;
int V_47 ;
V_264 . type = V_481 ;
V_264 . V_269 . V_19 = V_19 ;
V_47 = F_196 ( F_14 () , V_21 -> V_14 , V_21 -> V_28 , V_250 ,
V_479 , V_480 , & V_264 , V_69 ) ;
if ( V_47 )
return V_47 ;
return 0 ;
}
static int F_197 ( struct V_19 * V_19 , int V_313 )
{
const struct V_7 * V_7 = F_52 () ;
T_2 V_250 ;
bool V_482 ;
unsigned V_69 = V_313 & V_483 ;
struct V_20 * V_21 ;
T_2 V_14 ;
struct V_265 V_266 ;
int V_47 , V_273 ;
T_2 V_479 , V_480 ;
V_482 = V_313 & V_484 ;
V_313 &= ( V_316 | V_320 | V_314 | V_318 ) ;
if ( ! V_313 )
return 0 ;
F_101 ( V_7 ) ;
if ( F_102 ( F_42 ( V_19 ) ) )
return 0 ;
V_250 = F_115 ( V_19 -> V_238 , V_313 ) ;
V_14 = F_9 ( V_7 ) ;
V_21 = V_19 -> V_30 ;
V_47 = F_97 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_250 , 0 , & V_266 ) ;
V_479 = F_198 ( V_250 , & V_266 , V_47 ,
V_482 ? V_485 : 0 ,
& V_480 ) ;
if ( F_136 ( ! V_479 ) )
return V_47 ;
V_273 = F_195 ( V_19 , V_250 , V_479 , V_480 , V_69 ) ;
if ( V_273 )
return V_273 ;
return V_47 ;
}
static int F_199 ( struct V_52 * V_52 , struct V_486 * V_486 )
{
const struct V_7 * V_7 = F_52 () ;
unsigned int V_487 = V_486 -> V_487 ;
T_10 V_267 = V_321 ;
if ( V_487 & V_488 ) {
V_487 &= ~ ( V_489 | V_490 | V_491 |
V_488 ) ;
if ( ! V_487 )
return 0 ;
}
if ( V_487 & ( V_491 | V_492 | V_493 |
V_494 | V_495 | V_496 ) )
return F_104 ( V_7 , V_52 , V_497 ) ;
if ( V_330 && ( V_487 & V_498 ) )
V_267 |= V_331 ;
return F_104 ( V_7 , V_52 , V_267 ) ;
}
static int F_200 ( struct V_466 * V_388 , struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_227 V_227 ;
V_227 . V_52 = V_52 ;
V_227 . V_388 = V_388 ;
return F_105 ( V_7 , & V_227 , V_499 ) ;
}
static int F_201 ( struct V_52 * V_52 , const char * V_64 )
{
const struct V_7 * V_7 = F_52 () ;
if ( ! strncmp ( V_64 , V_500 ,
sizeof V_500 - 1 ) ) {
if ( ! strcmp ( V_64 , V_501 ) ) {
if ( ! F_202 ( V_502 ) )
return - V_387 ;
} else if ( ! F_202 ( V_375 ) ) {
return - V_387 ;
}
}
return F_104 ( V_7 , V_52 , V_497 ) ;
}
static int F_203 ( struct V_52 * V_52 , const char * V_64 ,
const void * V_472 , T_7 V_503 , int V_69 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_20 * V_21 = V_19 -> V_30 ;
struct V_31 * V_32 ;
struct V_263 V_264 ;
T_2 V_283 , V_14 = F_14 () ;
int V_47 = 0 ;
if ( strcmp ( V_64 , V_67 ) )
return F_201 ( V_52 , V_64 ) ;
V_32 = V_19 -> V_33 -> V_34 ;
if ( ! ( V_32 -> V_69 & V_71 ) )
return - V_65 ;
if ( ! F_204 ( V_19 ) )
return - V_387 ;
V_264 . type = V_276 ;
V_264 . V_269 . V_52 = V_52 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 ,
V_504 , & V_264 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_54 ( V_472 , V_503 , & V_283 ) ;
if ( V_47 == - V_86 ) {
if ( ! F_202 ( V_505 ) ) {
struct V_506 * V_507 ;
T_7 V_508 ;
const char * V_1 ;
if ( V_472 ) {
V_1 = V_472 ;
if ( V_1 [ V_503 - 1 ] == '\0' )
V_508 = V_503 - 1 ;
else
V_508 = V_503 ;
} else {
V_1 = L_40 ;
V_508 = 0 ;
}
V_507 = F_205 ( V_8 -> V_509 , V_91 , V_510 ) ;
F_206 ( V_507 , L_41 ) ;
F_207 ( V_507 , V_472 , V_508 ) ;
F_208 ( V_507 ) ;
return V_47 ;
}
V_47 = F_209 ( V_472 , V_503 , & V_283 ) ;
}
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_14 , V_283 , V_21 -> V_28 ,
V_511 , & V_264 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_210 ( V_21 -> V_14 , V_283 , V_14 ,
V_21 -> V_28 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_283 ,
V_32 -> V_14 ,
V_48 ,
V_51 ,
& V_264 ) ;
}
static void F_211 ( struct V_52 * V_52 , const char * V_64 ,
const void * V_472 , T_7 V_503 ,
int V_69 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_283 ;
int V_47 ;
if ( strcmp ( V_64 , V_67 ) ) {
return;
}
V_47 = F_209 ( V_472 , V_503 , & V_283 ) ;
if ( V_47 ) {
F_38 ( V_73 L_42
L_43 ,
V_19 -> V_33 -> V_62 , V_19 -> V_232 , - V_47 ) ;
return;
}
V_21 -> V_28 = F_69 ( V_19 -> V_238 ) ;
V_21 -> V_14 = V_283 ;
V_21 -> V_118 = 1 ;
return;
}
static int F_212 ( struct V_52 * V_52 , const char * V_64 )
{
const struct V_7 * V_7 = F_52 () ;
return F_104 ( V_7 , V_52 , V_499 ) ;
}
static int F_213 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
return F_104 ( V_7 , V_52 , V_499 ) ;
}
static int F_214 ( struct V_52 * V_52 , const char * V_64 )
{
if ( strcmp ( V_64 , V_67 ) )
return F_201 ( V_52 , V_64 ) ;
return - V_512 ;
}
static int F_215 ( const struct V_19 * V_19 , const char * V_64 , void * * V_226 , bool V_513 )
{
T_2 V_503 ;
int error ;
char * V_83 = NULL ;
struct V_20 * V_21 = V_19 -> V_30 ;
if ( strcmp ( V_64 , V_475 ) )
return - V_65 ;
error = F_126 ( F_52 () , & V_374 , V_505 ,
V_376 ) ;
if ( ! error )
error = F_184 ( V_21 -> V_14 , & V_83 ,
& V_503 ) ;
else
error = F_47 ( V_21 -> V_14 , & V_83 , & V_503 ) ;
if ( error )
return error ;
error = V_503 ;
if ( V_513 ) {
* V_226 = V_83 ;
goto V_514;
}
F_28 ( V_83 ) ;
V_514:
return error ;
}
static int F_216 ( struct V_19 * V_19 , const char * V_64 ,
const void * V_472 , T_7 V_503 , int V_69 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_283 ;
int V_47 ;
if ( strcmp ( V_64 , V_475 ) )
return - V_65 ;
if ( ! V_472 || ! V_503 )
return - V_512 ;
V_47 = F_54 ( ( void * ) V_472 , V_503 , & V_283 ) ;
if ( V_47 )
return V_47 ;
V_21 -> V_28 = F_69 ( V_19 -> V_238 ) ;
V_21 -> V_14 = V_283 ;
V_21 -> V_118 = 1 ;
return 0 ;
}
static int F_217 ( struct V_19 * V_19 , char * V_226 , T_7 V_515 )
{
const int V_84 = sizeof( V_67 ) ;
if ( V_226 && V_84 <= V_515 )
memcpy ( V_226 , V_67 , V_84 ) ;
return V_84 ;
}
static void F_218 ( const struct V_19 * V_19 , T_2 * V_516 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
* V_516 = V_21 -> V_14 ;
}
static int F_219 ( struct V_36 * V_36 , int V_313 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_19 * V_19 = F_107 ( V_36 ) ;
if ( ( V_36 -> V_327 & V_328 ) && ( V_313 & V_320 ) )
V_313 |= V_318 ;
return F_108 ( V_7 , V_36 ,
F_115 ( V_19 -> V_238 , V_313 ) ) ;
}
static int F_220 ( struct V_36 * V_36 , int V_313 )
{
struct V_19 * V_19 = F_107 ( V_36 ) ;
struct V_37 * V_38 = V_36 -> V_40 ;
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_14 = F_14 () ;
if ( ! V_313 )
return 0 ;
if ( V_14 == V_38 -> V_14 && V_38 -> V_517 == V_21 -> V_14 &&
V_38 -> V_518 == F_221 () )
return 0 ;
return F_219 ( V_36 , V_313 ) ;
}
static int F_222 ( struct V_36 * V_36 )
{
return F_26 ( V_36 ) ;
}
static void F_223 ( struct V_36 * V_36 )
{
F_27 ( V_36 ) ;
}
static int F_224 ( struct V_36 * V_36 , unsigned int V_519 ,
unsigned long V_520 )
{
const struct V_7 * V_7 = F_52 () ;
int error = 0 ;
switch ( V_519 ) {
case V_521 :
case V_522 :
case V_523 :
case V_524 :
case V_525 :
error = F_108 ( V_7 , V_36 , V_499 ) ;
break;
case V_526 :
case V_527 :
error = F_108 ( V_7 , V_36 , V_497 ) ;
break;
case V_528 :
case V_529 :
error = F_108 ( V_7 , V_36 , 0 ) ;
break;
case V_530 :
case V_531 :
error = F_94 ( V_7 , V_532 ,
V_272 ) ;
break;
default:
error = F_108 ( V_7 , V_36 , V_329 ) ;
}
return error ;
}
static int F_225 ( struct V_36 * V_36 , unsigned long V_533 , int V_534 )
{
const struct V_7 * V_7 = F_52 () ;
int V_47 = 0 ;
if ( V_535 &&
( V_533 & V_536 ) && ( ! V_36 || ( ! V_534 && ( V_533 & V_537 ) ) ) ) {
V_47 = F_91 ( V_7 , V_7 , V_538 ) ;
if ( V_47 )
goto error;
}
if ( V_36 ) {
T_2 V_267 = V_317 ;
if ( V_534 && ( V_533 & V_537 ) )
V_267 |= V_321 ;
if ( V_533 & V_536 )
V_267 |= V_315 ;
return F_108 ( V_7 , V_36 , V_267 ) ;
}
error:
return V_47 ;
}
static int F_226 ( unsigned long V_539 )
{
int V_47 = 0 ;
T_2 V_14 = F_14 () ;
if ( V_539 < V_540 ) {
V_47 = F_35 ( V_14 , V_14 , V_541 ,
V_542 , NULL ) ;
if ( V_47 )
return V_47 ;
}
return F_227 ( V_539 ) ;
}
static int F_228 ( struct V_36 * V_36 , unsigned long V_543 ,
unsigned long V_533 , unsigned long V_69 )
{
if ( V_544 )
V_533 = V_543 ;
return F_225 ( V_36 , V_533 ,
( V_69 & V_545 ) == V_546 ) ;
}
static int F_229 ( struct V_547 * V_548 ,
unsigned long V_543 ,
unsigned long V_533 )
{
const struct V_7 * V_7 = F_52 () ;
if ( V_544 )
V_533 = V_543 ;
if ( V_535 &&
( V_533 & V_536 ) && ! ( V_548 -> V_549 & V_550 ) ) {
int V_47 = 0 ;
if ( V_548 -> V_551 >= V_548 -> V_552 -> V_553 &&
V_548 -> V_554 <= V_548 -> V_552 -> V_555 ) {
V_47 = F_91 ( V_7 , V_7 , V_556 ) ;
} else if ( ! V_548 -> V_557 &&
V_548 -> V_551 <= V_548 -> V_552 -> V_558 &&
V_548 -> V_554 >= V_548 -> V_552 -> V_558 ) {
V_47 = F_93 ( V_8 , V_559 ) ;
} else if ( V_548 -> V_557 && V_548 -> V_560 ) {
V_47 = F_108 ( V_7 , V_548 -> V_557 , V_561 ) ;
}
if ( V_47 )
return V_47 ;
}
return F_225 ( V_548 -> V_557 , V_533 , V_548 -> V_549 & V_562 ) ;
}
static int F_230 ( struct V_36 * V_36 , unsigned int V_519 )
{
const struct V_7 * V_7 = F_52 () ;
return F_108 ( V_7 , V_36 , V_563 ) ;
}
static int F_231 ( struct V_36 * V_36 , unsigned int V_519 ,
unsigned long V_520 )
{
const struct V_7 * V_7 = F_52 () ;
int V_564 = 0 ;
switch ( V_519 ) {
case V_565 :
if ( ( V_36 -> V_327 & V_328 ) && ! ( V_520 & V_328 ) ) {
V_564 = F_108 ( V_7 , V_36 , V_321 ) ;
break;
}
case V_566 :
case V_567 :
case V_568 :
case V_569 :
case V_570 :
case V_571 :
V_564 = F_108 ( V_7 , V_36 , 0 ) ;
break;
case V_572 :
case V_573 :
case V_574 :
#if V_575 == 32
case V_576 :
case V_577 :
case V_578 :
#endif
V_564 = F_108 ( V_7 , V_36 , V_563 ) ;
break;
}
return V_564 ;
}
static int F_232 ( struct V_36 * V_36 )
{
struct V_37 * V_38 ;
V_38 = V_36 -> V_40 ;
V_38 -> V_39 = F_14 () ;
return 0 ;
}
static int F_233 ( struct V_17 * V_260 ,
struct V_579 * V_580 , int V_581 )
{
struct V_36 * V_36 ;
T_2 V_14 = F_10 ( V_260 ) ;
T_2 V_240 ;
struct V_37 * V_38 ;
V_36 = F_234 ( V_580 , struct V_36 , V_582 ) ;
V_38 = V_36 -> V_40 ;
if ( ! V_581 )
V_240 = F_90 ( V_583 ) ;
else
V_240 = F_90 ( V_581 ) ;
return F_35 ( V_38 -> V_39 , V_14 ,
V_253 , V_240 , NULL ) ;
}
static int F_235 ( struct V_36 * V_36 )
{
const struct V_7 * V_7 = F_52 () ;
return F_108 ( V_7 , V_36 , F_116 ( V_36 ) ) ;
}
static int F_236 ( struct V_36 * V_36 , const struct V_7 * V_7 )
{
struct V_37 * V_38 ;
struct V_20 * V_21 ;
V_38 = V_36 -> V_40 ;
V_21 = F_107 ( V_36 ) -> V_30 ;
V_38 -> V_517 = V_21 -> V_14 ;
V_38 -> V_518 = F_221 () ;
return F_106 ( V_7 , V_36 , F_117 ( V_36 ) ) ;
}
static int F_237 ( unsigned long V_584 )
{
return F_93 ( V_8 , V_585 ) ;
}
static int F_238 ( struct V_7 * V_7 , T_11 V_586 )
{
struct V_10 * V_11 ;
V_11 = F_7 ( sizeof( struct V_10 ) , V_586 ) ;
if ( ! V_11 )
return - V_24 ;
V_7 -> V_16 = V_11 ;
return 0 ;
}
static void F_239 ( struct V_7 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_16 ;
F_48 ( V_7 -> V_16 && ( unsigned long ) V_7 -> V_16 < V_228 ) ;
V_7 -> V_16 = ( void * ) 0x7UL ;
F_28 ( V_11 ) ;
}
static int F_240 ( struct V_7 * V_122 , const struct V_7 * V_121 ,
T_11 V_586 )
{
const struct V_10 * V_379 ;
struct V_10 * V_11 ;
V_379 = V_121 -> V_16 ;
V_11 = F_241 ( V_379 , sizeof( struct V_10 ) , V_586 ) ;
if ( ! V_11 )
return - V_24 ;
V_122 -> V_16 = V_11 ;
return 0 ;
}
static void F_242 ( struct V_7 * V_122 , const struct V_7 * V_121 )
{
const struct V_10 * V_379 = V_121 -> V_16 ;
struct V_10 * V_11 = V_122 -> V_16 ;
* V_11 = * V_379 ;
}
static int F_243 ( struct V_7 * V_122 , T_2 V_516 )
{
struct V_10 * V_11 = V_122 -> V_16 ;
T_2 V_14 = F_14 () ;
int V_587 ;
V_587 = F_35 ( V_14 , V_516 ,
V_588 ,
V_589 ,
NULL ) ;
if ( V_587 == 0 ) {
V_11 -> V_14 = V_516 ;
V_11 -> V_284 = 0 ;
V_11 -> V_382 = 0 ;
V_11 -> V_383 = 0 ;
}
return V_587 ;
}
static int F_244 ( struct V_7 * V_122 , struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
struct V_10 * V_11 = V_122 -> V_16 ;
T_2 V_14 = F_14 () ;
int V_587 ;
V_587 = F_35 ( V_14 , V_21 -> V_14 ,
V_588 ,
V_590 ,
NULL ) ;
if ( V_587 == 0 )
V_11 -> V_284 = V_21 -> V_14 ;
return V_587 ;
}
static int F_245 ( char * V_591 )
{
T_2 V_14 ;
struct V_263 V_264 ;
V_14 = F_10 ( V_8 ) ;
V_264 . type = V_592 ;
V_264 . V_269 . V_591 = V_591 ;
return F_35 ( V_14 , V_15 , V_274 ,
V_593 , & V_264 ) ;
}
static int F_246 ( struct V_17 * V_139 , T_12 V_594 )
{
return F_93 ( V_139 , V_595 ) ;
}
static int F_247 ( struct V_17 * V_139 )
{
return F_93 ( V_139 , V_596 ) ;
}
static int F_248 ( struct V_17 * V_139 )
{
return F_93 ( V_139 , V_597 ) ;
}
static void F_249 ( struct V_17 * V_139 , T_2 * V_516 )
{
* V_516 = F_10 ( V_139 ) ;
}
static int F_250 ( struct V_17 * V_139 , int V_598 )
{
int V_47 ;
V_47 = F_251 ( V_139 , V_598 ) ;
if ( V_47 )
return V_47 ;
return F_93 ( V_139 , V_599 ) ;
}
static int F_252 ( struct V_17 * V_139 , int V_600 )
{
int V_47 ;
V_47 = F_253 ( V_139 , V_600 ) ;
if ( V_47 )
return V_47 ;
return F_93 ( V_139 , V_599 ) ;
}
static int F_254 ( struct V_17 * V_139 )
{
return F_93 ( V_139 , V_601 ) ;
}
static int F_255 ( struct V_17 * V_139 , unsigned int V_602 ,
struct V_418 * V_603 )
{
struct V_418 * V_604 = V_139 -> signal -> V_419 + V_602 ;
if ( V_604 -> V_426 != V_603 -> V_426 )
return F_93 ( V_139 , V_605 ) ;
return 0 ;
}
static int F_256 ( struct V_17 * V_139 )
{
int V_47 ;
V_47 = F_257 ( V_139 ) ;
if ( V_47 )
return V_47 ;
return F_93 ( V_139 , V_599 ) ;
}
static int F_258 ( struct V_17 * V_139 )
{
return F_93 ( V_139 , V_601 ) ;
}
static int F_259 ( struct V_17 * V_139 )
{
return F_93 ( V_139 , V_599 ) ;
}
static int F_260 ( struct V_17 * V_139 , struct V_606 * V_607 ,
int V_239 , T_2 V_516 )
{
T_2 V_240 ;
int V_47 ;
if ( ! V_239 )
V_240 = V_608 ;
else
V_240 = F_90 ( V_239 ) ;
if ( V_516 )
V_47 = F_35 ( V_516 , F_10 ( V_139 ) ,
V_253 , V_240 , NULL ) ;
else
V_47 = F_93 ( V_139 , V_240 ) ;
return V_47 ;
}
static int F_261 ( struct V_17 * V_139 )
{
return F_92 ( V_139 , V_8 , V_242 ) ;
}
static void F_262 ( struct V_17 * V_139 ,
struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_14 = F_10 ( V_139 ) ;
V_21 -> V_14 = V_14 ;
V_21 -> V_118 = 1 ;
}
static int F_263 ( struct V_609 * V_610 ,
struct V_263 * V_264 , T_13 * V_611 )
{
int V_612 , V_613 , V_587 = - V_86 ;
struct V_614 V_615 , * V_616 ;
V_612 = F_264 ( V_610 ) ;
V_616 = F_265 ( V_610 , V_612 , sizeof( V_615 ) , & V_615 ) ;
if ( V_616 == NULL )
goto V_66;
V_613 = V_616 -> V_617 * 4 ;
if ( V_613 < sizeof( V_615 ) )
goto V_66;
V_264 -> V_269 . V_618 -> V_619 . V_620 = V_616 -> V_620 ;
V_264 -> V_269 . V_618 -> V_619 . V_621 = V_616 -> V_621 ;
V_587 = 0 ;
if ( V_611 )
* V_611 = V_616 -> V_178 ;
switch ( V_616 -> V_178 ) {
case V_180 : {
struct V_622 V_623 , * V_624 ;
if ( F_266 ( V_616 -> V_625 ) & V_626 )
break;
V_612 += V_613 ;
V_624 = F_265 ( V_610 , V_612 , sizeof( V_623 ) , & V_623 ) ;
if ( V_624 == NULL )
break;
V_264 -> V_269 . V_618 -> V_627 = V_624 -> V_628 ;
V_264 -> V_269 . V_618 -> V_629 = V_624 -> V_630 ;
break;
}
case V_181 : {
struct V_631 V_632 , * V_633 ;
if ( F_266 ( V_616 -> V_625 ) & V_626 )
break;
V_612 += V_613 ;
V_633 = F_265 ( V_610 , V_612 , sizeof( V_632 ) , & V_632 ) ;
if ( V_633 == NULL )
break;
V_264 -> V_269 . V_618 -> V_627 = V_633 -> V_628 ;
V_264 -> V_269 . V_618 -> V_629 = V_633 -> V_630 ;
break;
}
case V_634 : {
struct V_635 V_636 , * V_637 ;
if ( F_266 ( V_616 -> V_625 ) & V_626 )
break;
V_612 += V_613 ;
V_637 = F_265 ( V_610 , V_612 , sizeof( V_636 ) , & V_636 ) ;
if ( V_637 == NULL )
break;
V_264 -> V_269 . V_618 -> V_627 = V_637 -> V_638 ;
V_264 -> V_269 . V_618 -> V_629 = V_637 -> V_639 ;
break;
}
default:
break;
}
V_66:
return V_587 ;
}
static int F_267 ( struct V_609 * V_610 ,
struct V_263 * V_264 , T_13 * V_611 )
{
T_13 V_640 ;
int V_587 = - V_86 , V_612 ;
struct V_641 V_642 , * V_643 ;
T_14 V_625 ;
V_612 = F_264 ( V_610 ) ;
V_643 = F_265 ( V_610 , V_612 , sizeof( V_642 ) , & V_642 ) ;
if ( V_643 == NULL )
goto V_66;
V_264 -> V_269 . V_618 -> V_644 . V_620 = V_643 -> V_620 ;
V_264 -> V_269 . V_618 -> V_644 . V_621 = V_643 -> V_621 ;
V_587 = 0 ;
V_640 = V_643 -> V_640 ;
V_612 += sizeof( V_642 ) ;
V_612 = F_268 ( V_610 , V_612 , & V_640 , & V_625 ) ;
if ( V_612 < 0 )
goto V_66;
if ( V_611 )
* V_611 = V_640 ;
switch ( V_640 ) {
case V_180 : {
struct V_622 V_623 , * V_624 ;
V_624 = F_265 ( V_610 , V_612 , sizeof( V_623 ) , & V_623 ) ;
if ( V_624 == NULL )
break;
V_264 -> V_269 . V_618 -> V_627 = V_624 -> V_628 ;
V_264 -> V_269 . V_618 -> V_629 = V_624 -> V_630 ;
break;
}
case V_181 : {
struct V_631 V_632 , * V_633 ;
V_633 = F_265 ( V_610 , V_612 , sizeof( V_632 ) , & V_632 ) ;
if ( V_633 == NULL )
break;
V_264 -> V_269 . V_618 -> V_627 = V_633 -> V_628 ;
V_264 -> V_269 . V_618 -> V_629 = V_633 -> V_630 ;
break;
}
case V_634 : {
struct V_635 V_636 , * V_637 ;
V_637 = F_265 ( V_610 , V_612 , sizeof( V_636 ) , & V_636 ) ;
if ( V_637 == NULL )
break;
V_264 -> V_269 . V_618 -> V_627 = V_637 -> V_638 ;
V_264 -> V_269 . V_618 -> V_629 = V_637 -> V_639 ;
break;
}
default:
break;
}
V_66:
return V_587 ;
}
static int F_269 ( struct V_609 * V_610 , struct V_263 * V_264 ,
char * * V_645 , int V_646 , T_13 * V_611 )
{
char * V_647 ;
int V_587 ;
switch ( V_264 -> V_269 . V_618 -> V_182 ) {
case V_189 :
V_587 = F_263 ( V_610 , V_264 , V_611 ) ;
if ( V_587 )
goto V_648;
V_647 = ( char * ) ( V_646 ? & V_264 -> V_269 . V_618 -> V_619 . V_620 :
& V_264 -> V_269 . V_618 -> V_619 . V_621 ) ;
goto V_649;
#if F_270 ( V_650 ) || F_270 ( V_651 )
case V_190 :
V_587 = F_267 ( V_610 , V_264 , V_611 ) ;
if ( V_587 )
goto V_648;
V_647 = ( char * ) ( V_646 ? & V_264 -> V_269 . V_618 -> V_644 . V_620 :
& V_264 -> V_269 . V_618 -> V_644 . V_621 ) ;
goto V_649;
#endif
default:
V_647 = NULL ;
goto V_649;
}
V_648:
F_38 ( V_61
L_44
L_45 ) ;
return V_587 ;
V_649:
if ( V_645 )
* V_645 = V_647 ;
return 0 ;
}
static int F_271 ( struct V_609 * V_610 , T_4 V_182 , T_2 * V_14 )
{
int V_564 ;
T_2 V_652 ;
T_2 V_653 ;
T_2 V_654 ;
F_272 ( V_610 , & V_652 ) ;
F_273 ( V_610 , V_182 , & V_654 , & V_653 ) ;
V_564 = F_274 ( V_653 , V_654 , V_652 , V_14 ) ;
if ( F_102 ( V_564 ) ) {
F_38 ( V_61
L_46
L_47 ) ;
return - V_512 ;
}
return 0 ;
}
static int F_275 ( const struct V_10 * V_11 ,
T_4 V_655 , T_2 * V_656 )
{
if ( V_11 -> V_383 > V_657 ) {
* V_656 = V_11 -> V_383 ;
return 0 ;
}
return F_88 ( V_11 -> V_14 , V_11 -> V_14 , V_655 , NULL ,
V_656 ) ;
}
static int F_276 ( struct V_17 * V_18 , struct V_658 * V_659 , T_2 V_250 )
{
struct V_660 * V_661 = V_659 -> V_662 ;
struct V_263 V_264 ;
struct V_663 V_618 = { 0 ,} ;
T_2 V_252 = F_10 ( V_18 ) ;
if ( V_661 -> V_14 == V_15 )
return 0 ;
V_264 . type = V_664 ;
V_264 . V_269 . V_618 = & V_618 ;
V_264 . V_269 . V_618 -> V_659 = V_659 ;
return F_35 ( V_252 , V_661 -> V_14 , V_661 -> V_28 , V_250 , & V_264 ) ;
}
static int F_277 ( int V_182 , int type ,
int V_178 , int V_665 )
{
const struct V_10 * V_11 = F_15 () ;
T_2 V_283 ;
T_4 V_655 ;
int V_47 ;
if ( V_665 )
return 0 ;
V_655 = F_72 ( V_182 , type , V_178 ) ;
V_47 = F_275 ( V_11 , V_655 , & V_283 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_11 -> V_14 , V_283 , V_655 , V_666 , NULL ) ;
}
static int F_278 ( struct V_667 * V_658 , int V_182 ,
int type , int V_178 , int V_665 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_21 = F_279 ( V_658 ) -> V_30 ;
struct V_660 * V_661 ;
int V_564 = 0 ;
V_21 -> V_28 = F_72 ( V_182 , type , V_178 ) ;
if ( V_665 )
V_21 -> V_14 = V_15 ;
else {
V_564 = F_275 ( V_11 , V_21 -> V_28 , & ( V_21 -> V_14 ) ) ;
if ( V_564 )
return V_564 ;
}
V_21 -> V_118 = 1 ;
if ( V_658 -> V_659 ) {
V_661 = V_658 -> V_659 -> V_662 ;
V_661 -> V_14 = V_21 -> V_14 ;
V_661 -> V_28 = V_21 -> V_28 ;
V_564 = F_280 ( V_658 -> V_659 , V_182 ) ;
}
return V_564 ;
}
static int F_281 ( struct V_667 * V_658 , struct V_668 * V_669 , int V_670 )
{
struct V_658 * V_659 = V_658 -> V_659 ;
T_4 V_182 ;
int V_564 ;
V_564 = F_276 ( V_8 , V_659 , V_671 ) ;
if ( V_564 )
goto V_66;
V_182 = V_659 -> V_672 ;
if ( V_182 == V_189 || V_182 == V_190 ) {
char * V_647 ;
struct V_660 * V_661 = V_659 -> V_662 ;
struct V_263 V_264 ;
struct V_663 V_618 = { 0 ,} ;
struct V_673 * V_674 = NULL ;
struct V_675 * V_676 = NULL ;
unsigned short V_677 ;
T_2 V_14 , V_678 ;
if ( V_182 == V_189 ) {
V_674 = (struct V_673 * ) V_669 ;
V_677 = F_266 ( V_674 -> V_679 ) ;
V_647 = ( char * ) & V_674 -> V_680 . V_681 ;
} else {
V_676 = (struct V_675 * ) V_669 ;
V_677 = F_266 ( V_676 -> V_682 ) ;
V_647 = ( char * ) & V_676 -> V_683 . V_684 ;
}
if ( V_677 ) {
int V_685 , V_686 ;
F_282 ( & V_685 , & V_686 ) ;
if ( V_677 < V_687 ( V_688, V_685 ) || V_677 > V_686 ) {
V_564 = F_283 ( V_659 -> V_689 ,
V_677 , & V_14 ) ;
if ( V_564 )
goto V_66;
V_264 . type = V_664 ;
V_264 . V_269 . V_618 = & V_618 ;
V_264 . V_269 . V_618 -> V_627 = F_284 ( V_677 ) ;
V_264 . V_269 . V_618 -> V_182 = V_182 ;
V_564 = F_35 ( V_661 -> V_14 , V_14 ,
V_661 -> V_28 ,
V_690 , & V_264 ) ;
if ( V_564 )
goto V_66;
}
}
switch ( V_661 -> V_28 ) {
case V_191 :
V_678 = V_691 ;
break;
case V_193 :
V_678 = V_692 ;
break;
case V_195 :
V_678 = V_693 ;
break;
default:
V_678 = V_694 ;
break;
}
V_564 = F_285 ( V_647 , V_182 , & V_14 ) ;
if ( V_564 )
goto V_66;
V_264 . type = V_664 ;
V_264 . V_269 . V_618 = & V_618 ;
V_264 . V_269 . V_618 -> V_627 = F_284 ( V_677 ) ;
V_264 . V_269 . V_618 -> V_182 = V_182 ;
if ( V_182 == V_189 )
V_264 . V_269 . V_618 -> V_619 . V_620 = V_674 -> V_680 . V_681 ;
else
V_264 . V_269 . V_618 -> V_644 . V_620 = V_676 -> V_683 ;
V_564 = F_35 ( V_661 -> V_14 , V_14 ,
V_661 -> V_28 , V_678 , & V_264 ) ;
if ( V_564 )
goto V_66;
}
V_66:
return V_564 ;
}
static int F_286 ( struct V_667 * V_658 , struct V_668 * V_669 , int V_670 )
{
struct V_658 * V_659 = V_658 -> V_659 ;
struct V_660 * V_661 = V_659 -> V_662 ;
int V_564 ;
V_564 = F_276 ( V_8 , V_659 , V_695 ) ;
if ( V_564 )
return V_564 ;
if ( V_661 -> V_28 == V_191 ||
V_661 -> V_28 == V_195 ) {
struct V_263 V_264 ;
struct V_663 V_618 = { 0 ,} ;
struct V_673 * V_674 = NULL ;
struct V_675 * V_676 = NULL ;
unsigned short V_677 ;
T_2 V_14 , V_240 ;
if ( V_659 -> V_672 == V_189 ) {
V_674 = (struct V_673 * ) V_669 ;
if ( V_670 < sizeof( struct V_673 ) )
return - V_86 ;
V_677 = F_266 ( V_674 -> V_679 ) ;
} else {
V_676 = (struct V_675 * ) V_669 ;
if ( V_670 < V_696 )
return - V_86 ;
V_677 = F_266 ( V_676 -> V_682 ) ;
}
V_564 = F_283 ( V_659 -> V_689 , V_677 , & V_14 ) ;
if ( V_564 )
goto V_66;
V_240 = ( V_661 -> V_28 == V_191 ) ?
V_697 : V_698 ;
V_264 . type = V_664 ;
V_264 . V_269 . V_618 = & V_618 ;
V_264 . V_269 . V_618 -> V_629 = F_284 ( V_677 ) ;
V_264 . V_269 . V_618 -> V_182 = V_659 -> V_672 ;
V_564 = F_35 ( V_661 -> V_14 , V_14 , V_661 -> V_28 , V_240 , & V_264 ) ;
if ( V_564 )
goto V_66;
}
V_564 = F_287 ( V_659 , V_669 ) ;
V_66:
return V_564 ;
}
static int F_288 ( struct V_667 * V_658 , int V_699 )
{
return F_276 ( V_8 , V_658 -> V_659 , V_700 ) ;
}
static int F_289 ( struct V_667 * V_658 , struct V_667 * V_701 )
{
int V_564 ;
struct V_20 * V_21 ;
struct V_20 * V_135 ;
V_564 = F_276 ( V_8 , V_658 -> V_659 , V_702 ) ;
if ( V_564 )
return V_564 ;
V_135 = F_279 ( V_701 ) -> V_30 ;
V_21 = F_279 ( V_658 ) -> V_30 ;
V_135 -> V_28 = V_21 -> V_28 ;
V_135 -> V_14 = V_21 -> V_14 ;
V_135 -> V_118 = 1 ;
return 0 ;
}
static int F_290 ( struct V_667 * V_658 , struct V_703 * V_704 ,
int V_503 )
{
return F_276 ( V_8 , V_658 -> V_659 , V_705 ) ;
}
static int F_291 ( struct V_667 * V_658 , struct V_703 * V_704 ,
int V_503 , int V_69 )
{
return F_276 ( V_8 , V_658 -> V_659 , V_706 ) ;
}
static int F_292 ( struct V_667 * V_658 )
{
return F_276 ( V_8 , V_658 -> V_659 , V_707 ) ;
}
static int F_293 ( struct V_667 * V_658 )
{
return F_276 ( V_8 , V_658 -> V_659 , V_707 ) ;
}
static int F_294 ( struct V_667 * V_658 , int V_708 , int V_709 )
{
int V_564 ;
V_564 = F_276 ( V_8 , V_658 -> V_659 , V_710 ) ;
if ( V_564 )
return V_564 ;
return F_295 ( V_658 , V_708 , V_709 ) ;
}
static int F_296 ( struct V_667 * V_658 , int V_708 ,
int V_709 )
{
return F_276 ( V_8 , V_658 -> V_659 , V_711 ) ;
}
static int F_297 ( struct V_667 * V_658 , int V_712 )
{
return F_276 ( V_8 , V_658 -> V_659 , V_713 ) ;
}
static int F_298 ( struct V_658 * V_658 ,
struct V_658 * V_714 ,
struct V_658 * V_715 )
{
struct V_660 * V_716 = V_658 -> V_662 ;
struct V_660 * V_717 = V_714 -> V_662 ;
struct V_660 * V_718 = V_715 -> V_662 ;
struct V_263 V_264 ;
struct V_663 V_618 = { 0 ,} ;
int V_564 ;
V_264 . type = V_664 ;
V_264 . V_269 . V_618 = & V_618 ;
V_264 . V_269 . V_618 -> V_659 = V_714 ;
V_564 = F_35 ( V_716 -> V_14 , V_717 -> V_14 ,
V_717 -> V_28 ,
V_719 , & V_264 ) ;
if ( V_564 )
return V_564 ;
V_718 -> V_720 = V_716 -> V_14 ;
V_564 = F_299 ( V_717 -> V_14 , V_716 -> V_14 ,
& V_718 -> V_14 ) ;
if ( V_564 )
return V_564 ;
V_716 -> V_720 = V_718 -> V_14 ;
return 0 ;
}
static int F_300 ( struct V_667 * V_658 ,
struct V_667 * V_714 )
{
struct V_660 * V_721 = V_658 -> V_659 -> V_662 ;
struct V_660 * V_722 = V_714 -> V_659 -> V_662 ;
struct V_263 V_264 ;
struct V_663 V_618 = { 0 ,} ;
V_264 . type = V_664 ;
V_264 . V_269 . V_618 = & V_618 ;
V_264 . V_269 . V_618 -> V_659 = V_714 -> V_659 ;
return F_35 ( V_721 -> V_14 , V_722 -> V_14 , V_722 -> V_28 , V_723 ,
& V_264 ) ;
}
static int F_301 ( int V_724 , char * V_647 , T_4 V_182 ,
T_2 V_720 ,
struct V_263 * V_264 )
{
int V_564 ;
T_2 V_725 ;
T_2 V_726 ;
V_564 = F_302 ( V_724 , & V_725 ) ;
if ( V_564 )
return V_564 ;
V_564 = F_35 ( V_720 , V_725 ,
V_727 , V_728 , V_264 ) ;
if ( V_564 )
return V_564 ;
V_564 = F_285 ( V_647 , V_182 , & V_726 ) ;
if ( V_564 )
return V_564 ;
return F_35 ( V_720 , V_726 ,
V_729 , V_730 , V_264 ) ;
}
static int F_303 ( struct V_658 * V_659 , struct V_609 * V_610 ,
T_4 V_182 )
{
int V_564 = 0 ;
struct V_660 * V_661 = V_659 -> V_662 ;
T_2 V_731 = V_661 -> V_14 ;
struct V_263 V_264 ;
struct V_663 V_618 = { 0 ,} ;
char * V_647 ;
V_264 . type = V_664 ;
V_264 . V_269 . V_618 = & V_618 ;
V_264 . V_269 . V_618 -> V_732 = V_610 -> V_733 ;
V_264 . V_269 . V_618 -> V_182 = V_182 ;
V_564 = F_269 ( V_610 , & V_264 , & V_647 , 1 , NULL ) ;
if ( V_564 )
return V_564 ;
if ( F_4 () ) {
V_564 = F_35 ( V_731 , V_610 -> V_734 , V_735 ,
V_736 , & V_264 ) ;
if ( V_564 )
return V_564 ;
}
V_564 = F_304 ( V_661 , V_610 , V_182 , & V_264 ) ;
if ( V_564 )
return V_564 ;
V_564 = F_305 ( V_661 -> V_14 , V_610 , & V_264 ) ;
return V_564 ;
}
static int F_306 ( struct V_658 * V_659 , struct V_609 * V_610 )
{
int V_564 ;
struct V_660 * V_661 = V_659 -> V_662 ;
T_4 V_182 = V_659 -> V_672 ;
T_2 V_731 = V_661 -> V_14 ;
struct V_263 V_264 ;
struct V_663 V_618 = { 0 ,} ;
char * V_647 ;
T_13 V_737 ;
T_13 V_738 ;
if ( V_182 != V_189 && V_182 != V_190 )
return 0 ;
if ( V_182 == V_190 && V_610 -> V_178 == F_284 ( V_739 ) )
V_182 = V_189 ;
if ( ! V_740 )
return F_303 ( V_659 , V_610 , V_182 ) ;
V_737 = F_4 () ;
V_738 = F_307 () || F_308 () ;
if ( ! V_737 && ! V_738 )
return 0 ;
V_264 . type = V_664 ;
V_264 . V_269 . V_618 = & V_618 ;
V_264 . V_269 . V_618 -> V_732 = V_610 -> V_733 ;
V_264 . V_269 . V_618 -> V_182 = V_182 ;
V_564 = F_269 ( V_610 , & V_264 , & V_647 , 1 , NULL ) ;
if ( V_564 )
return V_564 ;
if ( V_738 ) {
T_2 V_720 ;
V_564 = F_271 ( V_610 , V_182 , & V_720 ) ;
if ( V_564 )
return V_564 ;
V_564 = F_301 ( V_610 -> V_733 , V_647 , V_182 ,
V_720 , & V_264 ) ;
if ( V_564 ) {
F_309 ( V_610 , V_564 , 0 ) ;
return V_564 ;
}
V_564 = F_35 ( V_731 , V_720 , V_741 ,
V_742 , & V_264 ) ;
if ( V_564 )
F_309 ( V_610 , V_564 , 0 ) ;
}
if ( V_737 ) {
V_564 = F_35 ( V_731 , V_610 -> V_734 , V_735 ,
V_736 , & V_264 ) ;
if ( V_564 )
return V_564 ;
}
return V_564 ;
}
static int F_310 ( struct V_667 * V_658 , char T_15 * V_743 ,
int T_15 * V_744 , unsigned V_84 )
{
int V_564 = 0 ;
char * V_745 ;
T_2 V_746 ;
struct V_660 * V_661 = V_658 -> V_659 -> V_662 ;
T_2 V_720 = V_657 ;
if ( V_661 -> V_28 == V_186 ||
V_661 -> V_28 == V_191 )
V_720 = V_661 -> V_720 ;
if ( V_720 == V_657 )
return - V_747 ;
V_564 = F_47 ( V_720 , & V_745 , & V_746 ) ;
if ( V_564 )
return V_564 ;
if ( V_746 > V_84 ) {
V_564 = - V_231 ;
goto V_748;
}
if ( F_311 ( V_743 , V_745 , V_746 ) )
V_564 = - V_749 ;
V_748:
if ( F_312 ( V_746 , V_744 ) )
V_564 = - V_749 ;
F_28 ( V_745 ) ;
return V_564 ;
}
static int F_313 ( struct V_667 * V_658 , struct V_609 * V_610 , T_2 * V_516 )
{
T_2 V_750 = V_657 ;
T_4 V_182 ;
if ( V_610 && V_610 -> V_178 == F_284 ( V_739 ) )
V_182 = V_189 ;
else if ( V_610 && V_610 -> V_178 == F_284 ( V_751 ) )
V_182 = V_190 ;
else if ( V_658 )
V_182 = V_658 -> V_659 -> V_672 ;
else
goto V_66;
if ( V_658 && V_182 == V_183 )
F_218 ( F_279 ( V_658 ) , & V_750 ) ;
else if ( V_610 )
F_271 ( V_610 , V_182 , & V_750 ) ;
V_66:
* V_516 = V_750 ;
if ( V_750 == V_657 )
return - V_86 ;
return 0 ;
}
static int F_314 ( struct V_658 * V_659 , int V_182 , T_11 V_752 )
{
struct V_660 * V_661 ;
V_661 = F_7 ( sizeof( * V_661 ) , V_752 ) ;
if ( ! V_661 )
return - V_24 ;
V_661 -> V_720 = V_27 ;
V_661 -> V_14 = V_27 ;
F_315 ( V_661 ) ;
V_659 -> V_662 = V_661 ;
return 0 ;
}
static void F_316 ( struct V_658 * V_659 )
{
struct V_660 * V_661 = V_659 -> V_662 ;
V_659 -> V_662 = NULL ;
F_317 ( V_661 ) ;
F_28 ( V_661 ) ;
}
static void F_318 ( const struct V_658 * V_659 , struct V_658 * V_715 )
{
struct V_660 * V_661 = V_659 -> V_662 ;
struct V_660 * V_753 = V_715 -> V_662 ;
V_753 -> V_14 = V_661 -> V_14 ;
V_753 -> V_720 = V_661 -> V_720 ;
V_753 -> V_28 = V_661 -> V_28 ;
F_315 ( V_753 ) ;
}
static void F_319 ( struct V_658 * V_659 , T_2 * V_516 )
{
if ( ! V_659 )
* V_516 = V_754 ;
else {
struct V_660 * V_661 = V_659 -> V_662 ;
* V_516 = V_661 -> V_14 ;
}
}
static void F_320 ( struct V_658 * V_659 , struct V_667 * V_336 )
{
struct V_20 * V_21 = F_279 ( V_336 ) -> V_30 ;
struct V_660 * V_661 = V_659 -> V_662 ;
if ( V_659 -> V_672 == V_189 || V_659 -> V_672 == V_190 ||
V_659 -> V_672 == V_183 )
V_21 -> V_14 = V_661 -> V_14 ;
V_661 -> V_28 = V_21 -> V_28 ;
}
static int F_321 ( struct V_658 * V_659 , struct V_609 * V_610 ,
struct V_755 * V_756 )
{
struct V_660 * V_661 = V_659 -> V_662 ;
int V_564 ;
T_4 V_182 = V_659 -> V_672 ;
T_2 V_283 ;
T_2 V_757 ;
if ( V_182 == V_190 && V_610 -> V_178 == F_284 ( V_739 ) )
V_182 = V_189 ;
V_564 = F_271 ( V_610 , V_182 , & V_757 ) ;
if ( V_564 )
return V_564 ;
if ( V_757 == V_657 ) {
V_756 -> V_516 = V_661 -> V_14 ;
V_756 -> V_750 = V_657 ;
} else {
V_564 = F_299 ( V_661 -> V_14 , V_757 , & V_283 ) ;
if ( V_564 )
return V_564 ;
V_756 -> V_516 = V_283 ;
V_756 -> V_750 = V_757 ;
}
return F_322 ( V_756 , V_182 ) ;
}
static void F_323 ( struct V_658 * V_715 ,
const struct V_755 * V_756 )
{
struct V_660 * V_753 = V_715 -> V_662 ;
V_753 -> V_14 = V_756 -> V_516 ;
V_753 -> V_720 = V_756 -> V_750 ;
F_324 ( V_715 , V_756 -> V_758 -> V_182 ) ;
}
static void F_325 ( struct V_658 * V_659 , struct V_609 * V_610 )
{
T_4 V_182 = V_659 -> V_672 ;
struct V_660 * V_661 = V_659 -> V_662 ;
if ( V_182 == V_190 && V_610 -> V_178 == F_284 ( V_739 ) )
V_182 = V_189 ;
F_271 ( V_610 , V_182 , & V_661 -> V_720 ) ;
}
static void F_326 ( struct V_609 * V_610 , struct V_658 * V_659 )
{
F_327 ( V_610 , V_659 ) ;
}
static int F_328 ( T_2 V_14 )
{
const struct V_10 * V_759 ;
T_2 V_252 ;
V_759 = F_15 () ;
V_252 = V_759 -> V_14 ;
return F_35 ( V_252 , V_14 , V_735 , V_760 , NULL ) ;
}
static void F_329 ( void )
{
F_330 ( & V_6 ) ;
}
static void F_331 ( void )
{
F_332 ( & V_6 ) ;
}
static void F_333 ( const struct V_755 * V_756 ,
struct V_761 * V_762 )
{
V_762 -> V_763 = V_756 -> V_516 ;
}
static int F_334 ( void * * V_16 )
{
struct V_764 * V_765 ;
V_765 = F_7 ( sizeof( * V_765 ) , V_12 ) ;
if ( ! V_765 )
return - V_24 ;
V_765 -> V_14 = F_14 () ;
* V_16 = V_765 ;
return 0 ;
}
static void F_335 ( void * V_16 )
{
F_28 ( V_16 ) ;
}
static int F_336 ( void )
{
T_2 V_14 = F_14 () ;
return F_35 ( V_14 , V_14 , V_766 , V_767 ,
NULL ) ;
}
static int F_337 ( void * V_16 )
{
struct V_764 * V_765 = V_16 ;
return F_35 ( F_14 () , V_765 -> V_14 , V_766 ,
V_768 , NULL ) ;
}
static int F_338 ( struct V_658 * V_659 , void * V_16 )
{
struct V_764 * V_765 = V_16 ;
struct V_660 * V_661 = V_659 -> V_662 ;
V_661 -> V_14 = V_765 -> V_14 ;
V_661 -> V_28 = V_766 ;
return 0 ;
}
static int F_339 ( void * V_16 )
{
struct V_764 * V_765 = V_16 ;
T_2 V_14 = F_14 () ;
int V_564 ;
V_564 = F_35 ( V_14 , V_765 -> V_14 , V_766 ,
V_769 , NULL ) ;
if ( V_564 )
return V_564 ;
V_564 = F_35 ( V_14 , V_14 , V_766 ,
V_770 , NULL ) ;
if ( V_564 )
return V_564 ;
V_765 -> V_14 = V_14 ;
return 0 ;
}
static int F_340 ( struct V_658 * V_659 , struct V_609 * V_610 )
{
int V_564 = 0 ;
T_2 V_240 ;
struct V_771 * V_772 ;
struct V_660 * V_661 = V_659 -> V_662 ;
if ( V_610 -> V_84 < V_773 ) {
V_564 = - V_86 ;
goto V_66;
}
V_772 = F_341 ( V_610 ) ;
V_564 = F_342 ( V_661 -> V_28 , V_772 -> V_774 , & V_240 ) ;
if ( V_564 ) {
if ( V_564 == - V_86 ) {
F_343 ( V_8 -> V_509 , V_12 , V_510 ,
L_48
L_49 ,
V_772 -> V_774 , V_661 -> V_28 ) ;
if ( ! V_3 || F_344 () )
V_564 = 0 ;
}
if ( V_564 == - V_775 )
V_564 = 0 ;
goto V_66;
}
V_564 = F_276 ( V_8 , V_659 , V_240 ) ;
V_66:
return V_564 ;
}
static unsigned int F_345 ( struct V_609 * V_610 , int V_724 ,
T_4 V_182 )
{
int V_564 ;
char * V_647 ;
T_2 V_720 ;
struct V_263 V_264 ;
struct V_663 V_618 = { 0 ,} ;
T_13 V_737 ;
T_13 V_776 ;
T_13 V_738 ;
if ( ! V_740 )
return V_777 ;
V_737 = F_4 () ;
V_776 = F_307 () ;
V_738 = V_776 || F_308 () ;
if ( ! V_737 && ! V_738 )
return V_777 ;
if ( F_271 ( V_610 , V_182 , & V_720 ) != 0 )
return V_778 ;
V_264 . type = V_664 ;
V_264 . V_269 . V_618 = & V_618 ;
V_264 . V_269 . V_618 -> V_732 = V_724 ;
V_264 . V_269 . V_618 -> V_182 = V_182 ;
if ( F_269 ( V_610 , & V_264 , & V_647 , 1 , NULL ) != 0 )
return V_778 ;
if ( V_738 ) {
V_564 = F_301 ( V_724 , V_647 , V_182 ,
V_720 , & V_264 ) ;
if ( V_564 ) {
F_309 ( V_610 , V_564 , 1 ) ;
return V_778 ;
}
}
if ( V_737 )
if ( F_35 ( V_720 , V_610 -> V_734 ,
V_735 , V_779 , & V_264 ) )
return V_778 ;
if ( V_776 )
if ( F_346 ( V_610 , V_182 , V_720 ) != 0 )
return V_778 ;
return V_777 ;
}
static unsigned int F_347 ( unsigned int V_780 ,
struct V_609 * V_610 ,
const struct V_781 * V_782 ,
const struct V_781 * V_66 ,
int (* F_348)( struct V_609 * ) )
{
return F_345 ( V_610 , V_782 -> V_724 , V_189 ) ;
}
static unsigned int F_349 ( unsigned int V_780 ,
struct V_609 * V_610 ,
const struct V_781 * V_782 ,
const struct V_781 * V_66 ,
int (* F_348)( struct V_609 * ) )
{
return F_345 ( V_610 , V_782 -> V_724 , V_190 ) ;
}
static unsigned int F_350 ( struct V_609 * V_610 ,
T_4 V_182 )
{
T_2 V_14 ;
if ( ! F_307 () )
return V_777 ;
if ( V_610 -> V_659 ) {
struct V_660 * V_661 = V_610 -> V_659 -> V_662 ;
V_14 = V_661 -> V_14 ;
} else
V_14 = V_15 ;
if ( F_346 ( V_610 , V_182 , V_14 ) != 0 )
return V_778 ;
return V_777 ;
}
static unsigned int F_351 ( unsigned int V_780 ,
struct V_609 * V_610 ,
const struct V_781 * V_782 ,
const struct V_781 * V_66 ,
int (* F_348)( struct V_609 * ) )
{
return F_350 ( V_610 , V_189 ) ;
}
static unsigned int F_352 ( struct V_609 * V_610 ,
int V_724 ,
T_4 V_182 )
{
struct V_658 * V_659 = V_610 -> V_659 ;
struct V_660 * V_661 ;
struct V_263 V_264 ;
struct V_663 V_618 = { 0 ,} ;
char * V_647 ;
T_13 V_611 ;
if ( V_659 == NULL )
return V_777 ;
V_661 = V_659 -> V_662 ;
V_264 . type = V_664 ;
V_264 . V_269 . V_618 = & V_618 ;
V_264 . V_269 . V_618 -> V_732 = V_724 ;
V_264 . V_269 . V_618 -> V_182 = V_182 ;
if ( F_269 ( V_610 , & V_264 , & V_647 , 0 , & V_611 ) )
return V_778 ;
if ( F_4 () )
if ( F_35 ( V_661 -> V_14 , V_610 -> V_734 ,
V_735 , V_783 , & V_264 ) )
return F_353 ( - V_784 ) ;
if ( F_354 ( V_661 -> V_14 , V_610 , & V_264 , V_611 ) )
return F_353 ( - V_784 ) ;
return V_777 ;
}
static unsigned int F_355 ( struct V_609 * V_610 , int V_724 ,
T_4 V_182 )
{
T_2 V_785 ;
T_2 V_720 ;
struct V_658 * V_659 ;
struct V_263 V_264 ;
struct V_663 V_618 = { 0 ,} ;
char * V_647 ;
T_13 V_737 ;
T_13 V_738 ;
if ( ! V_740 )
return F_352 ( V_610 , V_724 , V_182 ) ;
#ifdef F_356
if ( F_357 ( V_610 ) != NULL && F_357 ( V_610 ) -> V_786 != NULL )
return V_777 ;
#endif
V_737 = F_4 () ;
V_738 = F_307 () || F_308 () ;
if ( ! V_737 && ! V_738 )
return V_777 ;
V_659 = V_610 -> V_659 ;
if ( V_659 == NULL ) {
if ( V_610 -> V_733 ) {
V_785 = V_787 ;
if ( F_271 ( V_610 , V_182 , & V_720 ) )
return V_778 ;
} else {
V_785 = V_783 ;
V_720 = V_15 ;
}
} else {
struct V_660 * V_661 = V_659 -> V_662 ;
V_720 = V_661 -> V_14 ;
V_785 = V_783 ;
}
V_264 . type = V_664 ;
V_264 . V_269 . V_618 = & V_618 ;
V_264 . V_269 . V_618 -> V_732 = V_724 ;
V_264 . V_269 . V_618 -> V_182 = V_182 ;
if ( F_269 ( V_610 , & V_264 , & V_647 , 0 , NULL ) )
return V_778 ;
if ( V_737 )
if ( F_35 ( V_720 , V_610 -> V_734 ,
V_735 , V_785 , & V_264 ) )
return F_353 ( - V_784 ) ;
if ( V_738 ) {
T_2 V_725 ;
T_2 V_726 ;
if ( F_302 ( V_724 , & V_725 ) )
return V_778 ;
if ( F_35 ( V_720 , V_725 ,
V_727 , V_788 , & V_264 ) )
return F_353 ( - V_784 ) ;
if ( F_285 ( V_647 , V_182 , & V_726 ) )
return V_778 ;
if ( F_35 ( V_720 , V_726 ,
V_729 , V_789 , & V_264 ) )
return F_353 ( - V_784 ) ;
}
return V_777 ;
}
static unsigned int F_358 ( unsigned int V_780 ,
struct V_609 * V_610 ,
const struct V_781 * V_782 ,
const struct V_781 * V_66 ,
int (* F_348)( struct V_609 * ) )
{
return F_355 ( V_610 , V_66 -> V_724 , V_189 ) ;
}
static unsigned int F_359 ( unsigned int V_780 ,
struct V_609 * V_610 ,
const struct V_781 * V_782 ,
const struct V_781 * V_66 ,
int (* F_348)( struct V_609 * ) )
{
return F_355 ( V_610 , V_66 -> V_724 , V_190 ) ;
}
static int F_360 ( struct V_658 * V_659 , struct V_609 * V_610 )
{
int V_564 ;
V_564 = F_361 ( V_659 , V_610 ) ;
if ( V_564 )
return V_564 ;
return F_340 ( V_659 , V_610 ) ;
}
static int F_362 ( struct V_17 * V_18 ,
struct V_790 * V_240 ,
T_4 V_28 )
{
struct V_791 * V_21 ;
T_2 V_14 ;
V_21 = F_7 ( sizeof( struct V_791 ) , V_12 ) ;
if ( ! V_21 )
return - V_24 ;
V_14 = F_10 ( V_18 ) ;
V_21 -> V_28 = V_28 ;
V_21 -> V_14 = V_14 ;
V_240 -> V_16 = V_21 ;
return 0 ;
}
static void F_363 ( struct V_790 * V_240 )
{
struct V_791 * V_21 = V_240 -> V_16 ;
V_240 -> V_16 = NULL ;
F_28 ( V_21 ) ;
}
static int F_364 ( struct V_792 * V_704 )
{
struct V_793 * V_794 ;
V_794 = F_7 ( sizeof( struct V_793 ) , V_12 ) ;
if ( ! V_794 )
return - V_24 ;
V_794 -> V_14 = V_27 ;
V_704 -> V_16 = V_794 ;
return 0 ;
}
static void F_365 ( struct V_792 * V_704 )
{
struct V_793 * V_794 = V_704 -> V_16 ;
V_704 -> V_16 = NULL ;
F_28 ( V_794 ) ;
}
static int F_366 ( struct V_790 * V_795 ,
T_2 V_250 )
{
struct V_791 * V_21 ;
struct V_263 V_264 ;
T_2 V_14 = F_14 () ;
V_21 = V_795 -> V_16 ;
V_264 . type = V_796 ;
V_264 . V_269 . V_797 = V_795 -> V_798 ;
return F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_250 , & V_264 ) ;
}
static int F_367 ( struct V_792 * V_704 )
{
return F_364 ( V_704 ) ;
}
static void F_368 ( struct V_792 * V_704 )
{
F_365 ( V_704 ) ;
}
static int F_369 ( struct V_799 * V_800 )
{
struct V_791 * V_21 ;
struct V_263 V_264 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_362 ( V_8 , & V_800 -> V_801 , V_802 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_800 -> V_801 . V_16 ;
V_264 . type = V_796 ;
V_264 . V_269 . V_797 = V_800 -> V_801 . V_798 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_802 ,
V_803 , & V_264 ) ;
if ( V_47 ) {
F_363 ( & V_800 -> V_801 ) ;
return V_47 ;
}
return 0 ;
}
static void F_370 ( struct V_799 * V_800 )
{
F_363 ( & V_800 -> V_801 ) ;
}
static int F_371 ( struct V_799 * V_800 , int V_804 )
{
struct V_791 * V_21 ;
struct V_263 V_264 ;
T_2 V_14 = F_14 () ;
V_21 = V_800 -> V_801 . V_16 ;
V_264 . type = V_796 ;
V_264 . V_269 . V_797 = V_800 -> V_801 . V_798 ;
return F_35 ( V_14 , V_21 -> V_14 , V_802 ,
V_805 , & V_264 ) ;
}
static int F_372 ( struct V_799 * V_800 , int V_519 )
{
int V_564 ;
int V_250 ;
switch ( V_519 ) {
case V_806 :
case V_807 :
return F_99 ( V_8 , V_808 ) ;
case V_809 :
case V_810 :
V_250 = V_811 | V_805 ;
break;
case V_812 :
V_250 = V_813 ;
break;
case V_814 :
V_250 = V_815 ;
break;
default:
return 0 ;
}
V_564 = F_366 ( & V_800 -> V_801 , V_250 ) ;
return V_564 ;
}
static int F_373 ( struct V_799 * V_800 , struct V_792 * V_704 , int V_804 )
{
struct V_791 * V_21 ;
struct V_793 * V_794 ;
struct V_263 V_264 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_21 = V_800 -> V_801 . V_16 ;
V_794 = V_704 -> V_16 ;
if ( V_794 -> V_14 == V_27 ) {
V_47 = F_88 ( V_14 , V_21 -> V_14 , V_816 ,
NULL , & V_794 -> V_14 ) ;
if ( V_47 )
return V_47 ;
}
V_264 . type = V_796 ;
V_264 . V_269 . V_797 = V_800 -> V_801 . V_798 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_802 ,
V_817 , & V_264 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_14 , V_794 -> V_14 , V_816 ,
V_818 , & V_264 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_794 -> V_14 , V_21 -> V_14 , V_802 ,
V_819 , & V_264 ) ;
return V_47 ;
}
static int F_374 ( struct V_799 * V_800 , struct V_792 * V_704 ,
struct V_17 * V_249 ,
long type , int V_163 )
{
struct V_791 * V_21 ;
struct V_793 * V_794 ;
struct V_263 V_264 ;
T_2 V_14 = F_10 ( V_249 ) ;
int V_47 ;
V_21 = V_800 -> V_801 . V_16 ;
V_794 = V_704 -> V_16 ;
V_264 . type = V_796 ;
V_264 . V_269 . V_797 = V_800 -> V_801 . V_798 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 ,
V_802 , V_820 , & V_264 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_14 , V_794 -> V_14 ,
V_816 , V_821 , & V_264 ) ;
return V_47 ;
}
static int F_375 ( struct V_822 * V_823 )
{
struct V_791 * V_21 ;
struct V_263 V_264 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_362 ( V_8 , & V_823 -> V_824 , V_825 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_823 -> V_824 . V_16 ;
V_264 . type = V_796 ;
V_264 . V_269 . V_797 = V_823 -> V_824 . V_798 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_825 ,
V_826 , & V_264 ) ;
if ( V_47 ) {
F_363 ( & V_823 -> V_824 ) ;
return V_47 ;
}
return 0 ;
}
static void F_376 ( struct V_822 * V_823 )
{
F_363 ( & V_823 -> V_824 ) ;
}
static int F_377 ( struct V_822 * V_823 , int V_827 )
{
struct V_791 * V_21 ;
struct V_263 V_264 ;
T_2 V_14 = F_14 () ;
V_21 = V_823 -> V_824 . V_16 ;
V_264 . type = V_796 ;
V_264 . V_269 . V_797 = V_823 -> V_824 . V_798 ;
return F_35 ( V_14 , V_21 -> V_14 , V_825 ,
V_828 , & V_264 ) ;
}
static int F_378 ( struct V_822 * V_823 , int V_519 )
{
int V_250 ;
int V_564 ;
switch ( V_519 ) {
case V_806 :
case V_829 :
return F_99 ( V_8 , V_808 ) ;
case V_809 :
case V_830 :
V_250 = V_831 | V_828 ;
break;
case V_812 :
V_250 = V_832 ;
break;
case V_833 :
case V_834 :
V_250 = V_835 ;
break;
case V_814 :
V_250 = V_836 ;
break;
default:
return 0 ;
}
V_564 = F_366 ( & V_823 -> V_824 , V_250 ) ;
return V_564 ;
}
static int F_379 ( struct V_822 * V_823 ,
char T_15 * V_837 , int V_827 )
{
T_2 V_250 ;
if ( V_827 & V_838 )
V_250 = V_839 ;
else
V_250 = V_839 | V_840 ;
return F_366 ( & V_823 -> V_824 , V_250 ) ;
}
static int F_380 ( struct V_841 * V_842 )
{
struct V_791 * V_21 ;
struct V_263 V_264 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_362 ( V_8 , & V_842 -> V_843 , V_844 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_842 -> V_843 . V_16 ;
V_264 . type = V_796 ;
V_264 . V_269 . V_797 = V_842 -> V_843 . V_798 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_844 ,
V_845 , & V_264 ) ;
if ( V_47 ) {
F_363 ( & V_842 -> V_843 ) ;
return V_47 ;
}
return 0 ;
}
static void F_381 ( struct V_841 * V_842 )
{
F_363 ( & V_842 -> V_843 ) ;
}
static int F_382 ( struct V_841 * V_842 , int V_846 )
{
struct V_791 * V_21 ;
struct V_263 V_264 ;
T_2 V_14 = F_14 () ;
V_21 = V_842 -> V_843 . V_16 ;
V_264 . type = V_796 ;
V_264 . V_269 . V_797 = V_842 -> V_843 . V_798 ;
return F_35 ( V_14 , V_21 -> V_14 , V_844 ,
V_847 , & V_264 ) ;
}
static int F_383 ( struct V_841 * V_842 , int V_519 )
{
int V_564 ;
T_2 V_250 ;
switch ( V_519 ) {
case V_806 :
case V_848 :
return F_99 ( V_8 , V_808 ) ;
case V_849 :
case V_850 :
case V_851 :
V_250 = V_852 ;
break;
case V_853 :
case V_854 :
V_250 = V_855 ;
break;
case V_856 :
case V_857 :
V_250 = V_858 ;
break;
case V_814 :
V_250 = V_859 ;
break;
case V_812 :
V_250 = V_860 ;
break;
case V_809 :
case V_861 :
V_250 = V_852 | V_847 ;
break;
default:
return 0 ;
}
V_564 = F_366 ( & V_842 -> V_843 , V_250 ) ;
return V_564 ;
}
static int F_384 ( struct V_841 * V_842 ,
struct V_862 * V_863 , unsigned V_864 , int V_865 )
{
T_2 V_250 ;
if ( V_865 )
V_250 = V_855 | V_858 ;
else
V_250 = V_855 ;
return F_366 ( & V_842 -> V_843 , V_250 ) ;
}
static int F_385 ( struct V_790 * V_866 , short V_98 )
{
T_2 V_267 = 0 ;
V_267 = 0 ;
if ( V_98 & V_867 )
V_267 |= V_868 ;
if ( V_98 & V_869 )
V_267 |= V_870 ;
if ( V_267 == 0 )
return 0 ;
return F_366 ( V_866 , V_267 ) ;
}
static void F_386 ( struct V_790 * V_866 , T_2 * V_516 )
{
struct V_791 * V_21 = V_866 -> V_16 ;
* V_516 = V_21 -> V_14 ;
}
static void F_387 ( struct V_52 * V_52 , struct V_19 * V_19 )
{
if ( V_19 )
F_33 ( V_19 , V_52 ) ;
}
static int F_388 ( struct V_17 * V_139 ,
char * V_64 , char * * V_472 )
{
const struct V_10 * V_759 ;
T_2 V_14 ;
int error ;
unsigned V_84 ;
if ( V_8 != V_139 ) {
error = F_93 ( V_139 , V_871 ) ;
if ( error )
return error ;
}
F_11 () ;
V_759 = F_12 ( V_139 ) -> V_16 ;
if ( ! strcmp ( V_64 , L_50 ) )
V_14 = V_759 -> V_14 ;
else if ( ! strcmp ( V_64 , L_51 ) )
V_14 = V_759 -> V_13 ;
else if ( ! strcmp ( V_64 , L_52 ) )
V_14 = V_759 -> V_384 ;
else if ( ! strcmp ( V_64 , L_53 ) )
V_14 = V_759 -> V_284 ;
else if ( ! strcmp ( V_64 , L_54 ) )
V_14 = V_759 -> V_382 ;
else if ( ! strcmp ( V_64 , L_55 ) )
V_14 = V_759 -> V_383 ;
else
goto V_872;
F_13 () ;
if ( ! V_14 )
return 0 ;
error = F_47 ( V_14 , V_472 , & V_84 ) ;
if ( error )
return error ;
return V_84 ;
V_872:
F_13 () ;
return - V_86 ;
}
static int F_389 ( struct V_17 * V_139 ,
char * V_64 , void * V_472 , T_7 V_503 )
{
struct V_10 * V_11 ;
struct V_17 * V_397 ;
struct V_7 * V_122 ;
T_2 V_14 = 0 , V_399 ;
int error ;
char * V_1 = V_472 ;
if ( V_8 != V_139 ) {
return - V_512 ;
}
if ( ! strcmp ( V_64 , L_52 ) )
error = F_93 ( V_139 , V_873 ) ;
else if ( ! strcmp ( V_64 , L_53 ) )
error = F_93 ( V_139 , V_874 ) ;
else if ( ! strcmp ( V_64 , L_54 ) )
error = F_93 ( V_139 , V_875 ) ;
else if ( ! strcmp ( V_64 , L_55 ) )
error = F_93 ( V_139 , V_876 ) ;
else if ( ! strcmp ( V_64 , L_50 ) )
error = F_93 ( V_139 , V_877 ) ;
else
error = - V_86 ;
if ( error )
return error ;
if ( V_503 && V_1 [ 1 ] && V_1 [ 1 ] != '\n' ) {
if ( V_1 [ V_503 - 1 ] == '\n' ) {
V_1 [ V_503 - 1 ] = 0 ;
V_503 -- ;
}
error = F_54 ( V_472 , V_503 , & V_14 ) ;
if ( error == - V_86 && ! strcmp ( V_64 , L_53 ) ) {
if ( ! F_202 ( V_505 ) ) {
struct V_506 * V_507 ;
T_7 V_508 ;
if ( V_1 [ V_503 - 1 ] == '\0' )
V_508 = V_503 - 1 ;
else
V_508 = V_503 ;
V_507 = F_205 ( V_8 -> V_509 , V_91 , V_510 ) ;
F_206 ( V_507 , L_56 ) ;
F_207 ( V_507 , V_472 , V_508 ) ;
F_208 ( V_507 ) ;
return error ;
}
error = F_209 ( V_472 , V_503 ,
& V_14 ) ;
}
if ( error )
return error ;
}
V_122 = F_390 () ;
if ( ! V_122 )
return - V_24 ;
V_11 = V_122 -> V_16 ;
if ( ! strcmp ( V_64 , L_52 ) ) {
V_11 -> V_384 = V_14 ;
} else if ( ! strcmp ( V_64 , L_53 ) ) {
V_11 -> V_284 = V_14 ;
} else if ( ! strcmp ( V_64 , L_54 ) ) {
error = F_110 ( V_14 , V_139 ) ;
if ( error )
goto V_878;
V_11 -> V_382 = V_14 ;
} else if ( ! strcmp ( V_64 , L_55 ) ) {
V_11 -> V_383 = V_14 ;
} else if ( ! strcmp ( V_64 , L_50 ) ) {
error = - V_86 ;
if ( V_14 == 0 )
goto V_878;
error = - V_387 ;
if ( ! F_391 () ) {
error = F_392 ( V_11 -> V_14 , V_14 ) ;
if ( error )
goto V_878;
}
error = F_35 ( V_11 -> V_14 , V_14 , V_253 ,
V_879 , NULL ) ;
if ( error )
goto V_878;
V_399 = 0 ;
F_150 ( V_139 ) ;
V_397 = F_135 ( V_139 ) ;
if ( V_397 )
V_399 = F_10 ( V_397 ) ;
F_152 ( V_139 ) ;
if ( V_397 ) {
error = F_35 ( V_399 , V_14 , V_253 ,
V_335 , NULL ) ;
if ( error )
goto V_878;
}
V_11 -> V_14 = V_14 ;
} else {
error = - V_86 ;
goto V_878;
}
F_393 ( V_122 ) ;
return V_503 ;
V_878:
F_394 ( V_122 ) ;
return error ;
}
static int F_395 ( const char * V_64 )
{
return ( strcmp ( V_64 , V_475 ) == 0 ) ;
}
static int F_396 ( T_2 V_516 , char * * V_454 , T_2 * V_880 )
{
return F_47 ( V_516 , V_454 , V_880 ) ;
}
static int F_397 ( const char * V_454 , T_2 V_880 , T_2 * V_516 )
{
return F_54 ( V_454 , V_880 , V_516 ) ;
}
static void F_398 ( char * V_454 , T_2 V_880 )
{
F_28 ( V_454 ) ;
}
static int F_399 ( struct V_19 * V_19 , void * V_290 , T_2 V_470 )
{
return F_216 ( V_19 , V_475 , V_290 , V_470 , 0 ) ;
}
static int F_400 ( struct V_52 * V_52 , void * V_290 , T_2 V_470 )
{
return F_401 ( V_52 , V_67 , V_290 , V_470 , 0 ) ;
}
static int F_402 ( struct V_19 * V_19 , void * * V_290 , T_2 * V_470 )
{
int V_84 = 0 ;
V_84 = F_215 ( V_19 , V_475 ,
V_290 , true ) ;
if ( V_84 < 0 )
return V_84 ;
* V_470 = V_84 ;
return 0 ;
}
static int F_403 ( struct V_798 * V_881 , const struct V_7 * V_7 ,
unsigned long V_69 )
{
const struct V_10 * V_11 ;
struct V_882 * V_883 ;
V_883 = F_7 ( sizeof( struct V_882 ) , V_12 ) ;
if ( ! V_883 )
return - V_24 ;
V_11 = V_7 -> V_16 ;
if ( V_11 -> V_382 )
V_883 -> V_14 = V_11 -> V_382 ;
else
V_883 -> V_14 = V_11 -> V_14 ;
V_881 -> V_16 = V_883 ;
return 0 ;
}
static void F_404 ( struct V_798 * V_881 )
{
struct V_882 * V_883 = V_881 -> V_16 ;
V_881 -> V_16 = NULL ;
F_28 ( V_883 ) ;
}
static int F_405 ( T_16 V_884 ,
const struct V_7 * V_7 ,
T_17 V_240 )
{
struct V_798 * V_798 ;
struct V_882 * V_883 ;
T_2 V_14 ;
if ( V_240 == 0 )
return 0 ;
V_14 = F_9 ( V_7 ) ;
V_798 = F_406 ( V_884 ) ;
V_883 = V_798 -> V_16 ;
return F_35 ( V_14 , V_883 -> V_14 , V_291 , V_240 , NULL ) ;
}
static int F_407 ( struct V_798 * V_798 , char * * V_885 )
{
struct V_882 * V_883 = V_798 -> V_16 ;
char * V_83 = NULL ;
unsigned V_84 ;
int V_47 ;
V_47 = F_47 ( V_883 -> V_14 , & V_83 , & V_84 ) ;
if ( ! V_47 )
V_47 = V_84 ;
* V_885 = V_83 ;
return V_47 ;
}
static T_1 int F_408 ( void )
{
if ( ! F_409 ( & V_886 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_38 ( V_887 L_57 ) ;
return 0 ;
}
F_38 ( V_887 L_58 ) ;
F_6 () ;
V_535 = ! ( V_888 & V_550 ) ;
V_22 = F_410 ( L_59 ,
sizeof( struct V_20 ) ,
0 , V_889 , NULL ) ;
F_411 () ;
if ( F_412 ( & V_886 ) )
F_8 ( L_60 ) ;
if ( V_3 )
F_38 ( V_74 L_61 ) ;
else
F_38 ( V_74 L_62 ) ;
return 0 ;
}
static void F_413 ( struct V_41 * V_42 , void * V_890 )
{
F_63 ( V_42 , NULL ) ;
}
void F_414 ( void )
{
F_38 ( V_74 L_63 ) ;
F_38 ( V_74 L_64 ) ;
F_415 ( F_413 , NULL ) ;
}
static int T_1 F_416 ( void )
{
int V_564 = 0 ;
if ( ! V_5 )
goto V_66;
F_38 ( V_74 L_65 ) ;
V_564 = F_417 ( V_891 , F_39 ( V_891 ) ) ;
if ( V_564 )
F_8 ( L_66 , V_564 ) ;
#if F_270 ( V_650 ) || F_270 ( V_651 )
V_564 = F_417 ( V_892 , F_39 ( V_892 ) ) ;
if ( V_564 )
F_8 ( L_67 , V_564 ) ;
#endif
V_66:
return V_564 ;
}
static void F_418 ( void )
{
F_38 ( V_74 L_68 ) ;
F_419 ( V_891 , F_39 ( V_891 ) ) ;
#if F_270 ( V_650 ) || F_270 ( V_651 )
F_419 ( V_892 , F_39 ( V_892 ) ) ;
#endif
}
int F_420 ( void )
{
if ( V_87 ) {
return - V_86 ;
}
if ( V_893 ) {
return - V_86 ;
}
F_38 ( V_887 L_69 ) ;
V_893 = 1 ;
V_5 = 0 ;
F_421 () ;
F_422 () ;
F_418 () ;
F_423 () ;
return 0 ;
}
