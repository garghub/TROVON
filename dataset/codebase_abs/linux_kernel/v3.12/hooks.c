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
int V_273 = F_98 ( V_14 , V_14 , V_28 , V_267 , & V_266 , V_47 , & V_264 ) ;
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
struct V_263 * V_275 )
{
struct V_20 * V_21 ;
T_2 V_14 ;
F_101 ( V_7 ) ;
if ( F_102 ( F_42 ( V_19 ) ) )
return 0 ;
V_14 = F_9 ( V_7 ) ;
V_21 = V_19 -> V_30 ;
return F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_250 , V_275 ) ;
}
static inline int F_103 ( const struct V_7 * V_7 ,
struct V_52 * V_52 ,
T_2 V_267 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_263 V_264 ;
V_264 . type = V_276 ;
V_264 . V_269 . V_52 = V_52 ;
return F_100 ( V_7 , V_19 , V_267 , & V_264 ) ;
}
static inline int F_104 ( const struct V_7 * V_7 ,
struct V_227 * V_227 ,
T_2 V_267 )
{
struct V_19 * V_19 = V_227 -> V_52 -> V_56 ;
struct V_263 V_264 ;
V_264 . type = V_277 ;
V_264 . V_269 . V_227 = * V_227 ;
return F_100 ( V_7 , V_19 , V_267 , & V_264 ) ;
}
static inline int F_105 ( const struct V_7 * V_7 ,
struct V_36 * V_36 ,
T_2 V_267 )
{
struct V_263 V_264 ;
V_264 . type = V_277 ;
V_264 . V_269 . V_227 = V_36 -> V_278 ;
return F_100 ( V_7 , F_106 ( V_36 ) , V_267 , & V_264 ) ;
}
static int F_107 ( const struct V_7 * V_7 ,
struct V_36 * V_36 ,
T_2 V_267 )
{
struct V_37 * V_38 = V_36 -> V_40 ;
struct V_19 * V_19 = F_106 ( V_36 ) ;
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
V_47 = F_100 ( V_7 , V_19 , V_267 , & V_264 ) ;
V_66:
return V_47 ;
}
static int F_108 ( struct V_19 * V_281 ,
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
static int F_109 ( T_2 V_289 ,
struct V_17 * V_290 )
{
T_2 V_14 = F_10 ( V_290 ) ;
return F_35 ( V_14 , V_289 , V_291 , V_292 , NULL ) ;
}
static int F_110 ( struct V_19 * V_281 ,
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
static inline int F_111 ( struct V_19 * V_301 ,
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
V_309 = F_112 ( V_302 -> V_56 -> V_238 ) ;
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
V_310 = F_112 ( V_304 -> V_56 -> V_238 ) ;
V_47 = F_35 ( V_14 , V_308 -> V_14 ,
V_308 -> V_28 ,
( V_310 ? V_300 : V_298 ) , & V_264 ) ;
if ( V_47 )
return V_47 ;
}
return 0 ;
}
static int F_113 ( const struct V_7 * V_7 ,
struct V_41 * V_42 ,
T_2 V_250 ,
struct V_263 * V_264 )
{
struct V_31 * V_32 ;
T_2 V_14 = F_9 ( V_7 ) ;
V_32 = V_42 -> V_34 ;
return F_35 ( V_14 , V_32 -> V_14 , V_48 , V_250 , V_264 ) ;
}
static inline T_2 F_114 ( int V_163 , int V_313 )
{
T_2 V_267 = 0 ;
if ( ! F_112 ( V_163 ) ) {
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
static inline T_2 F_115 ( struct V_36 * V_36 )
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
static inline T_2 F_116 ( struct V_36 * V_36 )
{
T_2 V_267 = F_115 ( V_36 ) ;
if ( V_330 )
V_267 |= V_331 ;
return V_267 ;
}
static int F_117 ( struct V_17 * V_332 ,
unsigned int V_163 )
{
int V_47 ;
V_47 = F_118 ( V_332 , V_163 ) ;
if ( V_47 )
return V_47 ;
if ( V_163 & V_333 ) {
T_2 V_14 = F_14 () ;
T_2 V_334 = F_10 ( V_332 ) ;
return F_35 ( V_14 , V_334 , V_29 , V_317 , NULL ) ;
}
return F_93 ( V_332 , V_335 ) ;
}
static int F_119 ( struct V_17 * V_336 )
{
int V_47 ;
V_47 = F_120 ( V_336 ) ;
if ( V_47 )
return V_47 ;
return F_92 ( V_336 , V_8 , V_335 ) ;
}
static int F_121 ( struct V_17 * V_249 , T_6 * V_337 ,
T_6 * V_338 , T_6 * V_339 )
{
int error ;
error = F_93 ( V_249 , V_340 ) ;
if ( error )
return error ;
return F_122 ( V_249 , V_337 , V_338 , V_339 ) ;
}
static int F_123 ( struct V_7 * V_122 , const struct V_7 * V_121 ,
const T_6 * V_337 ,
const T_6 * V_338 ,
const T_6 * V_339 )
{
int error ;
error = F_124 ( V_122 , V_121 ,
V_337 , V_338 , V_339 ) ;
if ( error )
return error ;
return F_91 ( V_121 , V_122 , V_341 ) ;
}
static int F_125 ( const struct V_7 * V_7 , struct V_342 * V_343 ,
int V_261 , int V_262 )
{
int V_47 ;
V_47 = F_126 ( V_7 , V_343 , V_261 , V_262 ) ;
if ( V_47 )
return V_47 ;
return F_94 ( V_7 , V_261 , V_262 ) ;
}
static int F_127 ( int V_344 , int type , int V_345 , struct V_41 * V_42 )
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
V_47 = F_113 ( V_7 , V_42 , V_351 , NULL ) ;
break;
case V_352 :
case V_353 :
case V_354 :
V_47 = F_113 ( V_7 , V_42 , V_355 , NULL ) ;
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
return F_103 ( V_7 , V_52 , V_356 ) ;
}
static int F_129 ( int type )
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
static int F_130 ( struct V_370 * V_371 , long V_372 )
{
int V_47 , V_373 = 0 ;
V_47 = F_125 ( F_52 () , & V_374 , V_375 ,
V_376 ) ;
if ( V_47 == 0 )
V_373 = 1 ;
return F_131 ( V_371 , V_372 , V_373 ) ;
}
static int F_132 ( struct V_377 * V_378 )
{
const struct V_10 * V_379 ;
struct V_10 * V_380 ;
struct V_20 * V_21 ;
struct V_263 V_264 ;
struct V_19 * V_19 = F_106 ( V_378 -> V_36 ) ;
int V_47 ;
V_47 = F_133 ( V_378 ) ;
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
V_397 = F_134 ( V_8 ) ;
if ( F_135 ( V_397 != NULL ) ) {
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
static int F_136 ( struct V_377 * V_378 )
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
return ( V_402 || F_137 ( V_378 ) ) ;
}
static int F_138 ( const void * V_139 , struct V_36 * V_36 , unsigned V_404 )
{
return F_107 ( V_139 , V_36 , F_115 ( V_36 ) ) ? V_404 + 1 : 0 ;
}
static inline void F_139 ( const struct V_7 * V_7 ,
struct V_405 * V_406 )
{
struct V_36 * V_36 , * V_407 = NULL ;
struct V_408 * V_409 ;
int V_410 = 0 ;
unsigned V_411 ;
V_409 = F_140 () ;
if ( V_409 ) {
F_21 ( & V_412 ) ;
if ( ! F_22 ( & V_409 -> V_413 ) ) {
struct V_414 * V_415 ;
V_415 = F_141 ( & V_409 -> V_413 ,
struct V_414 , V_26 ) ;
V_36 = V_415 -> V_36 ;
if ( F_105 ( V_7 , V_36 , V_317 | V_321 ) )
V_410 = 1 ;
}
F_24 ( & V_412 ) ;
F_142 ( V_409 ) ;
}
if ( V_410 )
F_143 () ;
V_411 = F_144 ( V_406 , 0 , F_138 , V_7 ) ;
if ( ! V_411 )
return;
V_407 = F_145 ( & V_416 , V_417 , V_7 ) ;
if ( F_76 ( V_407 ) )
V_407 = NULL ;
do {
F_146 ( V_411 - 1 , V_407 , 0 ) ;
} while ( ( V_411 = F_144 ( V_406 , V_411 , F_138 , V_7 ) ) != 0 );
if ( V_407 )
F_147 ( V_407 ) ;
}
static void F_148 ( struct V_377 * V_378 )
{
struct V_10 * V_380 ;
struct V_418 * V_419 , * V_420 ;
int V_47 , V_82 ;
V_380 = V_378 -> V_7 -> V_16 ;
if ( V_380 -> V_14 == V_380 -> V_13 )
return;
F_139 ( V_378 -> V_7 , V_8 -> V_406 ) ;
V_8 -> V_421 = 0 ;
V_47 = F_35 ( V_380 -> V_13 , V_380 -> V_14 , V_253 ,
V_422 , NULL ) ;
if ( V_47 ) {
F_149 ( V_8 ) ;
for ( V_82 = 0 ; V_82 < V_423 ; V_82 ++ ) {
V_419 = V_8 -> signal -> V_419 + V_82 ;
V_420 = V_424 . signal -> V_419 + V_82 ;
V_419 -> V_425 = F_150 ( V_419 -> V_426 , V_420 -> V_425 ) ;
}
F_151 ( V_8 ) ;
F_152 ( V_8 , V_418 ( V_427 ) ) ;
}
}
static void F_153 ( struct V_377 * V_378 )
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
F_154 ( V_82 , & V_429 , NULL ) ;
F_155 ( & V_8 -> V_431 -> V_432 ) ;
if ( ! ( V_8 -> signal -> V_69 & V_433 ) ) {
F_156 ( V_8 ) ;
F_157 ( V_8 , 1 ) ;
F_158 ( & V_8 -> V_434 ) ;
}
F_159 ( & V_8 -> V_431 -> V_432 ) ;
}
F_160 ( & V_435 ) ;
F_161 ( V_8 , V_8 -> V_436 ) ;
F_162 ( & V_435 ) ;
}
static int F_163 ( struct V_41 * V_42 )
{
return F_29 ( V_42 ) ;
}
static void F_164 ( struct V_41 * V_42 )
{
F_31 ( V_42 ) ;
}
static inline int F_165 ( char * V_156 , int V_437 , char * V_438 , int V_439 )
{
if ( V_437 > V_439 )
return 0 ;
return ! memcmp ( V_156 , V_438 , V_437 ) ;
}
static inline int F_166 ( char * V_438 , int V_84 )
{
return ( F_165 ( V_158 , sizeof( V_158 ) - 1 , V_438 , V_84 ) ||
F_165 ( V_159 , sizeof( V_159 ) - 1 , V_438 , V_84 ) ||
F_165 ( V_161 , sizeof( V_161 ) - 1 , V_438 , V_84 ) ||
F_165 ( V_160 , sizeof( V_160 ) - 1 , V_438 , V_84 ) ||
F_165 ( V_162 , sizeof( V_162 ) - 1 , V_438 , V_84 ) ) ;
}
static inline void F_167 ( char * * V_440 , char * V_441 , int * V_442 , int V_84 )
{
if ( ! * V_442 ) {
* * V_440 = ',' ;
* V_440 += 1 ;
} else
* V_442 = 0 ;
memcpy ( * V_440 , V_441 , V_84 ) ;
* V_440 += V_84 ;
}
static inline void F_168 ( char * * V_440 , char * V_441 , int * V_442 ,
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
static int F_169 ( char * V_444 , char * V_445 )
{
int V_446 , V_38 , V_47 = 0 ;
char * V_447 , * V_448 , * V_449 ;
char * V_450 , * V_451 , * V_452 ;
int V_453 = 0 ;
V_448 = V_444 ;
V_450 = V_445 ;
V_452 = ( char * ) F_170 ( V_12 ) ;
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
if ( F_166 ( V_448 , V_84 ) )
F_168 ( & V_450 , V_448 , & V_38 , V_84 ) ;
else
F_167 ( & V_452 , V_448 , & V_446 , V_84 ) ;
V_448 = V_449 + 1 ;
}
} while ( * V_449 ++ );
strcpy ( V_447 , V_451 ) ;
F_79 ( ( unsigned long ) V_451 ) ;
V_66:
return V_47 ;
}
static int F_171 ( struct V_41 * V_42 , void * V_153 )
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
V_454 = F_172 () ;
if ( ! V_454 )
return - V_24 ;
V_47 = F_169 ( V_153 , V_454 ) ;
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
F_173 ( V_454 ) ;
return V_47 ;
V_457:
F_38 ( V_61 L_34
L_35 , V_42 -> V_62 ,
V_42 -> V_63 -> V_64 ) ;
goto V_456;
}
static int F_174 ( struct V_41 * V_42 , int V_69 , void * V_153 )
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
return F_113 ( V_7 , V_42 , V_459 , & V_264 ) ;
}
static int F_175 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_263 V_264 ;
V_264 . type = V_276 ;
V_264 . V_269 . V_52 = V_52 -> V_460 -> V_54 ;
return F_113 ( V_7 , V_52 -> V_460 , V_461 , & V_264 ) ;
}
static int F_176 ( const char * V_462 ,
struct V_227 * V_227 ,
const char * type ,
unsigned long V_69 ,
void * V_153 )
{
const struct V_7 * V_7 = F_52 () ;
if ( V_69 & V_463 )
return F_113 ( V_7 , V_227 -> V_52 -> V_460 ,
V_464 , NULL ) ;
else
return F_104 ( V_7 , V_227 , V_465 ) ;
}
static int F_177 ( struct V_466 * V_388 , int V_69 )
{
const struct V_7 * V_7 = F_52 () ;
return F_113 ( V_7 , V_388 -> V_467 ,
V_468 , NULL ) ;
}
static int F_178 ( struct V_19 * V_19 )
{
return F_16 ( V_19 ) ;
}
static void F_179 ( struct V_19 * V_19 )
{
F_20 ( V_19 ) ;
}
static int F_180 ( struct V_52 * V_52 , int V_163 ,
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
static int F_181 ( struct V_19 * V_19 , struct V_19 * V_281 ,
const struct V_469 * V_469 ,
const char * * V_64 ,
void * * V_472 , T_7 * V_84 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_282 ;
struct V_31 * V_32 ;
T_2 V_14 , V_283 , V_473 ;
int V_47 ;
char * V_83 ;
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
if ( V_64 )
* V_64 = V_474 ;
if ( V_472 && V_84 ) {
V_47 = F_182 ( V_283 , & V_83 , & V_473 ) ;
if ( V_47 )
return V_47 ;
* V_472 = V_83 ;
* V_84 = V_473 ;
}
return 0 ;
}
static int F_183 ( struct V_19 * V_281 , struct V_52 * V_52 , T_5 V_163 )
{
return F_108 ( V_281 , V_52 , V_29 ) ;
}
static int F_184 ( struct V_52 * V_302 , struct V_19 * V_281 , struct V_52 * V_304 )
{
return F_110 ( V_281 , V_302 , V_295 ) ;
}
static int F_185 ( struct V_19 * V_281 , struct V_52 * V_52 )
{
return F_110 ( V_281 , V_52 , V_297 ) ;
}
static int F_186 ( struct V_19 * V_281 , struct V_52 * V_52 , const char * V_64 )
{
return F_108 ( V_281 , V_52 , V_168 ) ;
}
static int F_187 ( struct V_19 * V_281 , struct V_52 * V_52 , T_5 V_313 )
{
return F_108 ( V_281 , V_52 , V_173 ) ;
}
static int F_188 ( struct V_19 * V_281 , struct V_52 * V_52 )
{
return F_110 ( V_281 , V_52 , V_299 ) ;
}
static int F_189 ( struct V_19 * V_281 , struct V_52 * V_52 , T_5 V_163 , T_8 V_233 )
{
return F_108 ( V_281 , V_52 , F_69 ( V_163 ) ) ;
}
static int F_190 ( struct V_19 * V_475 , struct V_52 * V_302 ,
struct V_19 * V_476 , struct V_52 * V_304 )
{
return F_111 ( V_475 , V_302 , V_476 , V_304 ) ;
}
static int F_191 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
return F_103 ( V_7 , V_52 , V_317 ) ;
}
static int F_192 ( struct V_52 * V_52 , struct V_477 * V_477 )
{
const struct V_7 * V_7 = F_52 () ;
return F_103 ( V_7 , V_52 , V_317 ) ;
}
static T_9 int F_193 ( struct V_19 * V_19 ,
T_2 V_250 , T_2 V_478 , T_2 V_479 ,
unsigned V_69 )
{
struct V_263 V_264 ;
struct V_20 * V_21 = V_19 -> V_30 ;
int V_47 ;
V_264 . type = V_480 ;
V_264 . V_269 . V_19 = V_19 ;
V_47 = F_194 ( F_14 () , V_21 -> V_14 , V_21 -> V_28 , V_250 ,
V_478 , V_479 , & V_264 , V_69 ) ;
if ( V_47 )
return V_47 ;
return 0 ;
}
static int F_195 ( struct V_19 * V_19 , int V_313 )
{
const struct V_7 * V_7 = F_52 () ;
T_2 V_250 ;
bool V_481 ;
unsigned V_69 = V_313 & V_482 ;
struct V_20 * V_21 ;
T_2 V_14 ;
struct V_265 V_266 ;
int V_47 , V_273 ;
T_2 V_478 , V_479 ;
V_481 = V_313 & V_483 ;
V_313 &= ( V_316 | V_320 | V_314 | V_318 ) ;
if ( ! V_313 )
return 0 ;
F_101 ( V_7 ) ;
if ( F_102 ( F_42 ( V_19 ) ) )
return 0 ;
V_250 = F_114 ( V_19 -> V_238 , V_313 ) ;
V_14 = F_9 ( V_7 ) ;
V_21 = V_19 -> V_30 ;
V_47 = F_97 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_250 , 0 , & V_266 ) ;
V_478 = F_196 ( V_250 , & V_266 , V_47 ,
V_481 ? V_484 : 0 ,
& V_479 ) ;
if ( F_135 ( ! V_478 ) )
return V_47 ;
V_273 = F_193 ( V_19 , V_250 , V_478 , V_479 , V_69 ) ;
if ( V_273 )
return V_273 ;
return V_47 ;
}
static int F_197 ( struct V_52 * V_52 , struct V_485 * V_485 )
{
const struct V_7 * V_7 = F_52 () ;
unsigned int V_486 = V_485 -> V_486 ;
T_10 V_267 = V_321 ;
if ( V_486 & V_487 ) {
V_486 &= ~ ( V_488 | V_489 | V_490 |
V_487 ) ;
if ( ! V_486 )
return 0 ;
}
if ( V_486 & ( V_490 | V_491 | V_492 |
V_493 | V_494 | V_495 ) )
return F_103 ( V_7 , V_52 , V_496 ) ;
if ( V_330 && ( V_486 & V_497 ) )
V_267 |= V_331 ;
return F_103 ( V_7 , V_52 , V_267 ) ;
}
static int F_198 ( struct V_466 * V_388 , struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_227 V_227 ;
V_227 . V_52 = V_52 ;
V_227 . V_388 = V_388 ;
return F_104 ( V_7 , & V_227 , V_498 ) ;
}
static int F_199 ( struct V_52 * V_52 , const char * V_64 )
{
const struct V_7 * V_7 = F_52 () ;
if ( ! strncmp ( V_64 , V_499 ,
sizeof V_499 - 1 ) ) {
if ( ! strcmp ( V_64 , V_500 ) ) {
if ( ! F_200 ( V_501 ) )
return - V_387 ;
} else if ( ! F_200 ( V_375 ) ) {
return - V_387 ;
}
}
return F_103 ( V_7 , V_52 , V_496 ) ;
}
static int F_201 ( struct V_52 * V_52 , const char * V_64 ,
const void * V_472 , T_7 V_502 , int V_69 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_20 * V_21 = V_19 -> V_30 ;
struct V_31 * V_32 ;
struct V_263 V_264 ;
T_2 V_283 , V_14 = F_14 () ;
int V_47 = 0 ;
if ( strcmp ( V_64 , V_67 ) )
return F_199 ( V_52 , V_64 ) ;
V_32 = V_19 -> V_33 -> V_34 ;
if ( ! ( V_32 -> V_69 & V_71 ) )
return - V_65 ;
if ( ! F_202 ( V_19 ) )
return - V_387 ;
V_264 . type = V_276 ;
V_264 . V_269 . V_52 = V_52 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 ,
V_503 , & V_264 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_54 ( V_472 , V_502 , & V_283 ) ;
if ( V_47 == - V_86 ) {
if ( ! F_200 ( V_504 ) ) {
struct V_505 * V_506 ;
T_7 V_507 ;
const char * V_1 ;
if ( V_472 ) {
V_1 = V_472 ;
if ( V_1 [ V_502 - 1 ] == '\0' )
V_507 = V_502 - 1 ;
else
V_507 = V_502 ;
} else {
V_1 = L_40 ;
V_507 = 0 ;
}
V_506 = F_203 ( V_8 -> V_508 , V_91 , V_509 ) ;
F_204 ( V_506 , L_41 ) ;
F_205 ( V_506 , V_472 , V_507 ) ;
F_206 ( V_506 ) ;
return V_47 ;
}
V_47 = F_207 ( V_472 , V_502 , & V_283 ) ;
}
if ( V_47 )
return V_47 ;
V_47 = F_35 ( V_14 , V_283 , V_21 -> V_28 ,
V_510 , & V_264 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_208 ( V_21 -> V_14 , V_283 , V_14 ,
V_21 -> V_28 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_283 ,
V_32 -> V_14 ,
V_48 ,
V_51 ,
& V_264 ) ;
}
static void F_209 ( struct V_52 * V_52 , const char * V_64 ,
const void * V_472 , T_7 V_502 ,
int V_69 )
{
struct V_19 * V_19 = V_52 -> V_56 ;
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_283 ;
int V_47 ;
if ( strcmp ( V_64 , V_67 ) ) {
return;
}
V_47 = F_207 ( V_472 , V_502 , & V_283 ) ;
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
static int F_210 ( struct V_52 * V_52 , const char * V_64 )
{
const struct V_7 * V_7 = F_52 () ;
return F_103 ( V_7 , V_52 , V_498 ) ;
}
static int F_211 ( struct V_52 * V_52 )
{
const struct V_7 * V_7 = F_52 () ;
return F_103 ( V_7 , V_52 , V_498 ) ;
}
static int F_212 ( struct V_52 * V_52 , const char * V_64 )
{
if ( strcmp ( V_64 , V_67 ) )
return F_199 ( V_52 , V_64 ) ;
return - V_511 ;
}
static int F_213 ( const struct V_19 * V_19 , const char * V_64 , void * * V_226 , bool V_512 )
{
T_2 V_502 ;
int error ;
char * V_83 = NULL ;
struct V_20 * V_21 = V_19 -> V_30 ;
if ( strcmp ( V_64 , V_474 ) )
return - V_65 ;
error = F_125 ( F_52 () , & V_374 , V_504 ,
V_376 ) ;
if ( ! error )
error = F_182 ( V_21 -> V_14 , & V_83 ,
& V_502 ) ;
else
error = F_47 ( V_21 -> V_14 , & V_83 , & V_502 ) ;
if ( error )
return error ;
error = V_502 ;
if ( V_512 ) {
* V_226 = V_83 ;
goto V_513;
}
F_28 ( V_83 ) ;
V_513:
return error ;
}
static int F_214 ( struct V_19 * V_19 , const char * V_64 ,
const void * V_472 , T_7 V_502 , int V_69 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_283 ;
int V_47 ;
if ( strcmp ( V_64 , V_474 ) )
return - V_65 ;
if ( ! V_472 || ! V_502 )
return - V_511 ;
V_47 = F_54 ( ( void * ) V_472 , V_502 , & V_283 ) ;
if ( V_47 )
return V_47 ;
V_21 -> V_28 = F_69 ( V_19 -> V_238 ) ;
V_21 -> V_14 = V_283 ;
V_21 -> V_118 = 1 ;
return 0 ;
}
static int F_215 ( struct V_19 * V_19 , char * V_226 , T_7 V_514 )
{
const int V_84 = sizeof( V_67 ) ;
if ( V_226 && V_84 <= V_514 )
memcpy ( V_226 , V_67 , V_84 ) ;
return V_84 ;
}
static void F_216 ( const struct V_19 * V_19 , T_2 * V_515 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
* V_515 = V_21 -> V_14 ;
}
static int F_217 ( struct V_36 * V_36 , int V_313 )
{
const struct V_7 * V_7 = F_52 () ;
struct V_19 * V_19 = F_106 ( V_36 ) ;
if ( ( V_36 -> V_327 & V_328 ) && ( V_313 & V_320 ) )
V_313 |= V_318 ;
return F_107 ( V_7 , V_36 ,
F_114 ( V_19 -> V_238 , V_313 ) ) ;
}
static int F_218 ( struct V_36 * V_36 , int V_313 )
{
struct V_19 * V_19 = F_106 ( V_36 ) ;
struct V_37 * V_38 = V_36 -> V_40 ;
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_14 = F_14 () ;
if ( ! V_313 )
return 0 ;
if ( V_14 == V_38 -> V_14 && V_38 -> V_516 == V_21 -> V_14 &&
V_38 -> V_517 == F_219 () )
return 0 ;
return F_217 ( V_36 , V_313 ) ;
}
static int F_220 ( struct V_36 * V_36 )
{
return F_26 ( V_36 ) ;
}
static void F_221 ( struct V_36 * V_36 )
{
F_27 ( V_36 ) ;
}
static int F_222 ( struct V_36 * V_36 , unsigned int V_518 ,
unsigned long V_519 )
{
const struct V_7 * V_7 = F_52 () ;
int error = 0 ;
switch ( V_518 ) {
case V_520 :
case V_521 :
case V_522 :
case V_523 :
case V_524 :
error = F_107 ( V_7 , V_36 , V_498 ) ;
break;
case V_525 :
case V_526 :
error = F_107 ( V_7 , V_36 , V_496 ) ;
break;
case V_527 :
case V_528 :
error = F_107 ( V_7 , V_36 , 0 ) ;
break;
case V_529 :
case V_530 :
error = F_94 ( V_7 , V_531 ,
V_272 ) ;
break;
default:
error = F_107 ( V_7 , V_36 , V_329 ) ;
}
return error ;
}
static int F_223 ( struct V_36 * V_36 , unsigned long V_532 , int V_533 )
{
const struct V_7 * V_7 = F_52 () ;
int V_47 = 0 ;
if ( V_534 &&
( V_532 & V_535 ) && ( ! V_36 || ( ! V_533 && ( V_532 & V_536 ) ) ) ) {
V_47 = F_91 ( V_7 , V_7 , V_537 ) ;
if ( V_47 )
goto error;
}
if ( V_36 ) {
T_2 V_267 = V_317 ;
if ( V_533 && ( V_532 & V_536 ) )
V_267 |= V_321 ;
if ( V_532 & V_535 )
V_267 |= V_315 ;
return F_107 ( V_7 , V_36 , V_267 ) ;
}
error:
return V_47 ;
}
static int F_224 ( unsigned long V_538 )
{
int V_47 = 0 ;
T_2 V_14 = F_14 () ;
if ( V_538 < V_539 ) {
V_47 = F_35 ( V_14 , V_14 , V_540 ,
V_541 , NULL ) ;
if ( V_47 )
return V_47 ;
}
return F_225 ( V_538 ) ;
}
static int F_226 ( struct V_36 * V_36 , unsigned long V_542 ,
unsigned long V_532 , unsigned long V_69 )
{
if ( V_543 )
V_532 = V_542 ;
return F_223 ( V_36 , V_532 ,
( V_69 & V_544 ) == V_545 ) ;
}
static int F_227 ( struct V_546 * V_547 ,
unsigned long V_542 ,
unsigned long V_532 )
{
const struct V_7 * V_7 = F_52 () ;
if ( V_543 )
V_532 = V_542 ;
if ( V_534 &&
( V_532 & V_535 ) && ! ( V_547 -> V_548 & V_549 ) ) {
int V_47 = 0 ;
if ( V_547 -> V_550 >= V_547 -> V_551 -> V_552 &&
V_547 -> V_553 <= V_547 -> V_551 -> V_554 ) {
V_47 = F_91 ( V_7 , V_7 , V_555 ) ;
} else if ( ! V_547 -> V_556 &&
V_547 -> V_550 <= V_547 -> V_551 -> V_557 &&
V_547 -> V_553 >= V_547 -> V_551 -> V_557 ) {
V_47 = F_93 ( V_8 , V_558 ) ;
} else if ( V_547 -> V_556 && V_547 -> V_559 ) {
V_47 = F_107 ( V_7 , V_547 -> V_556 , V_560 ) ;
}
if ( V_47 )
return V_47 ;
}
return F_223 ( V_547 -> V_556 , V_532 , V_547 -> V_548 & V_561 ) ;
}
static int F_228 ( struct V_36 * V_36 , unsigned int V_518 )
{
const struct V_7 * V_7 = F_52 () ;
return F_107 ( V_7 , V_36 , V_562 ) ;
}
static int F_229 ( struct V_36 * V_36 , unsigned int V_518 ,
unsigned long V_519 )
{
const struct V_7 * V_7 = F_52 () ;
int V_563 = 0 ;
switch ( V_518 ) {
case V_564 :
if ( ( V_36 -> V_327 & V_328 ) && ! ( V_519 & V_328 ) ) {
V_563 = F_107 ( V_7 , V_36 , V_321 ) ;
break;
}
case V_565 :
case V_566 :
case V_567 :
case V_568 :
case V_569 :
case V_570 :
V_563 = F_107 ( V_7 , V_36 , 0 ) ;
break;
case V_571 :
case V_572 :
case V_573 :
#if V_574 == 32
case V_575 :
case V_576 :
case V_577 :
#endif
V_563 = F_107 ( V_7 , V_36 , V_562 ) ;
break;
}
return V_563 ;
}
static int F_230 ( struct V_36 * V_36 )
{
struct V_37 * V_38 ;
V_38 = V_36 -> V_40 ;
V_38 -> V_39 = F_14 () ;
return 0 ;
}
static int F_231 ( struct V_17 * V_260 ,
struct V_578 * V_579 , int V_580 )
{
struct V_36 * V_36 ;
T_2 V_14 = F_10 ( V_260 ) ;
T_2 V_240 ;
struct V_37 * V_38 ;
V_36 = F_232 ( V_579 , struct V_36 , V_581 ) ;
V_38 = V_36 -> V_40 ;
if ( ! V_580 )
V_240 = F_90 ( V_582 ) ;
else
V_240 = F_90 ( V_580 ) ;
return F_35 ( V_38 -> V_39 , V_14 ,
V_253 , V_240 , NULL ) ;
}
static int F_233 ( struct V_36 * V_36 )
{
const struct V_7 * V_7 = F_52 () ;
return F_107 ( V_7 , V_36 , F_115 ( V_36 ) ) ;
}
static int F_234 ( struct V_36 * V_36 , const struct V_7 * V_7 )
{
struct V_37 * V_38 ;
struct V_20 * V_21 ;
V_38 = V_36 -> V_40 ;
V_21 = F_106 ( V_36 ) -> V_30 ;
V_38 -> V_516 = V_21 -> V_14 ;
V_38 -> V_517 = F_219 () ;
return F_105 ( V_7 , V_36 , F_116 ( V_36 ) ) ;
}
static int F_235 ( unsigned long V_583 )
{
return F_93 ( V_8 , V_584 ) ;
}
static int F_236 ( struct V_7 * V_7 , T_11 V_585 )
{
struct V_10 * V_11 ;
V_11 = F_7 ( sizeof( struct V_10 ) , V_585 ) ;
if ( ! V_11 )
return - V_24 ;
V_7 -> V_16 = V_11 ;
return 0 ;
}
static void F_237 ( struct V_7 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_16 ;
F_48 ( V_7 -> V_16 && ( unsigned long ) V_7 -> V_16 < V_228 ) ;
V_7 -> V_16 = ( void * ) 0x7UL ;
F_28 ( V_11 ) ;
}
static int F_238 ( struct V_7 * V_122 , const struct V_7 * V_121 ,
T_11 V_585 )
{
const struct V_10 * V_379 ;
struct V_10 * V_11 ;
V_379 = V_121 -> V_16 ;
V_11 = F_239 ( V_379 , sizeof( struct V_10 ) , V_585 ) ;
if ( ! V_11 )
return - V_24 ;
V_122 -> V_16 = V_11 ;
return 0 ;
}
static void F_240 ( struct V_7 * V_122 , const struct V_7 * V_121 )
{
const struct V_10 * V_379 = V_121 -> V_16 ;
struct V_10 * V_11 = V_122 -> V_16 ;
* V_11 = * V_379 ;
}
static int F_241 ( struct V_7 * V_122 , T_2 V_515 )
{
struct V_10 * V_11 = V_122 -> V_16 ;
T_2 V_14 = F_14 () ;
int V_586 ;
V_586 = F_35 ( V_14 , V_515 ,
V_587 ,
V_588 ,
NULL ) ;
if ( V_586 == 0 ) {
V_11 -> V_14 = V_515 ;
V_11 -> V_284 = 0 ;
V_11 -> V_382 = 0 ;
V_11 -> V_383 = 0 ;
}
return V_586 ;
}
static int F_242 ( struct V_7 * V_122 , struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
struct V_10 * V_11 = V_122 -> V_16 ;
T_2 V_14 = F_14 () ;
int V_586 ;
V_586 = F_35 ( V_14 , V_21 -> V_14 ,
V_587 ,
V_589 ,
NULL ) ;
if ( V_586 == 0 )
V_11 -> V_284 = V_21 -> V_14 ;
return V_586 ;
}
static int F_243 ( char * V_590 )
{
T_2 V_14 ;
struct V_263 V_264 ;
V_14 = F_10 ( V_8 ) ;
V_264 . type = V_591 ;
V_264 . V_269 . V_590 = V_590 ;
return F_35 ( V_14 , V_15 , V_274 ,
V_592 , & V_264 ) ;
}
static int F_244 ( struct V_17 * V_139 , T_12 V_593 )
{
return F_93 ( V_139 , V_594 ) ;
}
static int F_245 ( struct V_17 * V_139 )
{
return F_93 ( V_139 , V_595 ) ;
}
static int F_246 ( struct V_17 * V_139 )
{
return F_93 ( V_139 , V_596 ) ;
}
static void F_247 ( struct V_17 * V_139 , T_2 * V_515 )
{
* V_515 = F_10 ( V_139 ) ;
}
static int F_248 ( struct V_17 * V_139 , int V_597 )
{
int V_47 ;
V_47 = F_249 ( V_139 , V_597 ) ;
if ( V_47 )
return V_47 ;
return F_93 ( V_139 , V_598 ) ;
}
static int F_250 ( struct V_17 * V_139 , int V_599 )
{
int V_47 ;
V_47 = F_251 ( V_139 , V_599 ) ;
if ( V_47 )
return V_47 ;
return F_93 ( V_139 , V_598 ) ;
}
static int F_252 ( struct V_17 * V_139 )
{
return F_93 ( V_139 , V_600 ) ;
}
static int F_253 ( struct V_17 * V_139 , unsigned int V_601 ,
struct V_418 * V_602 )
{
struct V_418 * V_603 = V_139 -> signal -> V_419 + V_601 ;
if ( V_603 -> V_426 != V_602 -> V_426 )
return F_93 ( V_139 , V_604 ) ;
return 0 ;
}
static int F_254 ( struct V_17 * V_139 )
{
int V_47 ;
V_47 = F_255 ( V_139 ) ;
if ( V_47 )
return V_47 ;
return F_93 ( V_139 , V_598 ) ;
}
static int F_256 ( struct V_17 * V_139 )
{
return F_93 ( V_139 , V_600 ) ;
}
static int F_257 ( struct V_17 * V_139 )
{
return F_93 ( V_139 , V_598 ) ;
}
static int F_258 ( struct V_17 * V_139 , struct V_605 * V_606 ,
int V_239 , T_2 V_515 )
{
T_2 V_240 ;
int V_47 ;
if ( ! V_239 )
V_240 = V_607 ;
else
V_240 = F_90 ( V_239 ) ;
if ( V_515 )
V_47 = F_35 ( V_515 , F_10 ( V_139 ) ,
V_253 , V_240 , NULL ) ;
else
V_47 = F_93 ( V_139 , V_240 ) ;
return V_47 ;
}
static int F_259 ( struct V_17 * V_139 )
{
return F_92 ( V_139 , V_8 , V_242 ) ;
}
static void F_260 ( struct V_17 * V_139 ,
struct V_19 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_30 ;
T_2 V_14 = F_10 ( V_139 ) ;
V_21 -> V_14 = V_14 ;
V_21 -> V_118 = 1 ;
}
static int F_261 ( struct V_608 * V_609 ,
struct V_263 * V_264 , T_13 * V_610 )
{
int V_611 , V_612 , V_586 = - V_86 ;
struct V_613 V_614 , * V_615 ;
V_611 = F_262 ( V_609 ) ;
V_615 = F_263 ( V_609 , V_611 , sizeof( V_614 ) , & V_614 ) ;
if ( V_615 == NULL )
goto V_66;
V_612 = V_615 -> V_616 * 4 ;
if ( V_612 < sizeof( V_614 ) )
goto V_66;
V_264 -> V_269 . V_617 -> V_618 . V_619 = V_615 -> V_619 ;
V_264 -> V_269 . V_617 -> V_618 . V_620 = V_615 -> V_620 ;
V_586 = 0 ;
if ( V_610 )
* V_610 = V_615 -> V_178 ;
switch ( V_615 -> V_178 ) {
case V_180 : {
struct V_621 V_622 , * V_623 ;
if ( F_264 ( V_615 -> V_624 ) & V_625 )
break;
V_611 += V_612 ;
V_623 = F_263 ( V_609 , V_611 , sizeof( V_622 ) , & V_622 ) ;
if ( V_623 == NULL )
break;
V_264 -> V_269 . V_617 -> V_626 = V_623 -> V_627 ;
V_264 -> V_269 . V_617 -> V_628 = V_623 -> V_629 ;
break;
}
case V_181 : {
struct V_630 V_631 , * V_632 ;
if ( F_264 ( V_615 -> V_624 ) & V_625 )
break;
V_611 += V_612 ;
V_632 = F_263 ( V_609 , V_611 , sizeof( V_631 ) , & V_631 ) ;
if ( V_632 == NULL )
break;
V_264 -> V_269 . V_617 -> V_626 = V_632 -> V_627 ;
V_264 -> V_269 . V_617 -> V_628 = V_632 -> V_629 ;
break;
}
case V_633 : {
struct V_634 V_635 , * V_636 ;
if ( F_264 ( V_615 -> V_624 ) & V_625 )
break;
V_611 += V_612 ;
V_636 = F_263 ( V_609 , V_611 , sizeof( V_635 ) , & V_635 ) ;
if ( V_636 == NULL )
break;
V_264 -> V_269 . V_617 -> V_626 = V_636 -> V_637 ;
V_264 -> V_269 . V_617 -> V_628 = V_636 -> V_638 ;
break;
}
default:
break;
}
V_66:
return V_586 ;
}
static int F_265 ( struct V_608 * V_609 ,
struct V_263 * V_264 , T_13 * V_610 )
{
T_13 V_639 ;
int V_586 = - V_86 , V_611 ;
struct V_640 V_641 , * V_642 ;
T_14 V_624 ;
V_611 = F_262 ( V_609 ) ;
V_642 = F_263 ( V_609 , V_611 , sizeof( V_641 ) , & V_641 ) ;
if ( V_642 == NULL )
goto V_66;
V_264 -> V_269 . V_617 -> V_643 . V_619 = V_642 -> V_619 ;
V_264 -> V_269 . V_617 -> V_643 . V_620 = V_642 -> V_620 ;
V_586 = 0 ;
V_639 = V_642 -> V_639 ;
V_611 += sizeof( V_641 ) ;
V_611 = F_266 ( V_609 , V_611 , & V_639 , & V_624 ) ;
if ( V_611 < 0 )
goto V_66;
if ( V_610 )
* V_610 = V_639 ;
switch ( V_639 ) {
case V_180 : {
struct V_621 V_622 , * V_623 ;
V_623 = F_263 ( V_609 , V_611 , sizeof( V_622 ) , & V_622 ) ;
if ( V_623 == NULL )
break;
V_264 -> V_269 . V_617 -> V_626 = V_623 -> V_627 ;
V_264 -> V_269 . V_617 -> V_628 = V_623 -> V_629 ;
break;
}
case V_181 : {
struct V_630 V_631 , * V_632 ;
V_632 = F_263 ( V_609 , V_611 , sizeof( V_631 ) , & V_631 ) ;
if ( V_632 == NULL )
break;
V_264 -> V_269 . V_617 -> V_626 = V_632 -> V_627 ;
V_264 -> V_269 . V_617 -> V_628 = V_632 -> V_629 ;
break;
}
case V_633 : {
struct V_634 V_635 , * V_636 ;
V_636 = F_263 ( V_609 , V_611 , sizeof( V_635 ) , & V_635 ) ;
if ( V_636 == NULL )
break;
V_264 -> V_269 . V_617 -> V_626 = V_636 -> V_637 ;
V_264 -> V_269 . V_617 -> V_628 = V_636 -> V_638 ;
break;
}
default:
break;
}
V_66:
return V_586 ;
}
static int F_267 ( struct V_608 * V_609 , struct V_263 * V_264 ,
char * * V_644 , int V_645 , T_13 * V_610 )
{
char * V_646 ;
int V_586 ;
switch ( V_264 -> V_269 . V_617 -> V_182 ) {
case V_189 :
V_586 = F_261 ( V_609 , V_264 , V_610 ) ;
if ( V_586 )
goto V_647;
V_646 = ( char * ) ( V_645 ? & V_264 -> V_269 . V_617 -> V_618 . V_619 :
& V_264 -> V_269 . V_617 -> V_618 . V_620 ) ;
goto V_648;
#if F_268 ( V_649 ) || F_268 ( V_650 )
case V_190 :
V_586 = F_265 ( V_609 , V_264 , V_610 ) ;
if ( V_586 )
goto V_647;
V_646 = ( char * ) ( V_645 ? & V_264 -> V_269 . V_617 -> V_643 . V_619 :
& V_264 -> V_269 . V_617 -> V_643 . V_620 ) ;
goto V_648;
#endif
default:
V_646 = NULL ;
goto V_648;
}
V_647:
F_38 ( V_61
L_44
L_45 ) ;
return V_586 ;
V_648:
if ( V_644 )
* V_644 = V_646 ;
return 0 ;
}
static int F_269 ( struct V_608 * V_609 , T_4 V_182 , T_2 * V_14 )
{
int V_563 ;
T_2 V_651 ;
T_2 V_652 ;
T_2 V_653 ;
F_270 ( V_609 , & V_651 ) ;
F_271 ( V_609 , V_182 , & V_653 , & V_652 ) ;
V_563 = F_272 ( V_652 , V_653 , V_651 , V_14 ) ;
if ( F_102 ( V_563 ) ) {
F_38 ( V_61
L_46
L_47 ) ;
return - V_511 ;
}
return 0 ;
}
static int F_273 ( const struct V_10 * V_11 ,
T_4 V_654 , T_2 * V_655 )
{
if ( V_11 -> V_383 > V_656 ) {
* V_655 = V_11 -> V_383 ;
return 0 ;
}
return F_88 ( V_11 -> V_14 , V_11 -> V_14 , V_654 , NULL ,
V_655 ) ;
}
static int F_274 ( struct V_17 * V_18 , struct V_657 * V_658 , T_2 V_250 )
{
struct V_659 * V_660 = V_658 -> V_661 ;
struct V_263 V_264 ;
struct V_662 V_617 = { 0 ,} ;
T_2 V_252 = F_10 ( V_18 ) ;
if ( V_660 -> V_14 == V_15 )
return 0 ;
V_264 . type = V_663 ;
V_264 . V_269 . V_617 = & V_617 ;
V_264 . V_269 . V_617 -> V_658 = V_658 ;
return F_35 ( V_252 , V_660 -> V_14 , V_660 -> V_28 , V_250 , & V_264 ) ;
}
static int F_275 ( int V_182 , int type ,
int V_178 , int V_664 )
{
const struct V_10 * V_11 = F_15 () ;
T_2 V_283 ;
T_4 V_654 ;
int V_47 ;
if ( V_664 )
return 0 ;
V_654 = F_72 ( V_182 , type , V_178 ) ;
V_47 = F_273 ( V_11 , V_654 , & V_283 ) ;
if ( V_47 )
return V_47 ;
return F_35 ( V_11 -> V_14 , V_283 , V_654 , V_665 , NULL ) ;
}
static int F_276 ( struct V_666 * V_657 , int V_182 ,
int type , int V_178 , int V_664 )
{
const struct V_10 * V_11 = F_15 () ;
struct V_20 * V_21 = F_277 ( V_657 ) -> V_30 ;
struct V_659 * V_660 ;
int V_563 = 0 ;
V_21 -> V_28 = F_72 ( V_182 , type , V_178 ) ;
if ( V_664 )
V_21 -> V_14 = V_15 ;
else {
V_563 = F_273 ( V_11 , V_21 -> V_28 , & ( V_21 -> V_14 ) ) ;
if ( V_563 )
return V_563 ;
}
V_21 -> V_118 = 1 ;
if ( V_657 -> V_658 ) {
V_660 = V_657 -> V_658 -> V_661 ;
V_660 -> V_14 = V_21 -> V_14 ;
V_660 -> V_28 = V_21 -> V_28 ;
V_563 = F_278 ( V_657 -> V_658 , V_182 ) ;
}
return V_563 ;
}
static int F_279 ( struct V_666 * V_657 , struct V_667 * V_668 , int V_669 )
{
struct V_657 * V_658 = V_657 -> V_658 ;
T_4 V_182 ;
int V_563 ;
V_563 = F_274 ( V_8 , V_658 , V_670 ) ;
if ( V_563 )
goto V_66;
V_182 = V_658 -> V_671 ;
if ( V_182 == V_189 || V_182 == V_190 ) {
char * V_646 ;
struct V_659 * V_660 = V_658 -> V_661 ;
struct V_263 V_264 ;
struct V_662 V_617 = { 0 ,} ;
struct V_672 * V_673 = NULL ;
struct V_674 * V_675 = NULL ;
unsigned short V_676 ;
T_2 V_14 , V_677 ;
if ( V_182 == V_189 ) {
V_673 = (struct V_672 * ) V_668 ;
V_676 = F_264 ( V_673 -> V_678 ) ;
V_646 = ( char * ) & V_673 -> V_679 . V_680 ;
} else {
V_675 = (struct V_674 * ) V_668 ;
V_676 = F_264 ( V_675 -> V_681 ) ;
V_646 = ( char * ) & V_675 -> V_682 . V_683 ;
}
if ( V_676 ) {
int V_684 , V_685 ;
F_280 ( & V_684 , & V_685 ) ;
if ( V_676 < V_686 ( V_687, V_684 ) || V_676 > V_685 ) {
V_563 = F_281 ( V_658 -> V_688 ,
V_676 , & V_14 ) ;
if ( V_563 )
goto V_66;
V_264 . type = V_663 ;
V_264 . V_269 . V_617 = & V_617 ;
V_264 . V_269 . V_617 -> V_626 = F_282 ( V_676 ) ;
V_264 . V_269 . V_617 -> V_182 = V_182 ;
V_563 = F_35 ( V_660 -> V_14 , V_14 ,
V_660 -> V_28 ,
V_689 , & V_264 ) ;
if ( V_563 )
goto V_66;
}
}
switch ( V_660 -> V_28 ) {
case V_191 :
V_677 = V_690 ;
break;
case V_193 :
V_677 = V_691 ;
break;
case V_195 :
V_677 = V_692 ;
break;
default:
V_677 = V_693 ;
break;
}
V_563 = F_283 ( V_646 , V_182 , & V_14 ) ;
if ( V_563 )
goto V_66;
V_264 . type = V_663 ;
V_264 . V_269 . V_617 = & V_617 ;
V_264 . V_269 . V_617 -> V_626 = F_282 ( V_676 ) ;
V_264 . V_269 . V_617 -> V_182 = V_182 ;
if ( V_182 == V_189 )
V_264 . V_269 . V_617 -> V_618 . V_619 = V_673 -> V_679 . V_680 ;
else
V_264 . V_269 . V_617 -> V_643 . V_619 = V_675 -> V_682 ;
V_563 = F_35 ( V_660 -> V_14 , V_14 ,
V_660 -> V_28 , V_677 , & V_264 ) ;
if ( V_563 )
goto V_66;
}
V_66:
return V_563 ;
}
static int F_284 ( struct V_666 * V_657 , struct V_667 * V_668 , int V_669 )
{
struct V_657 * V_658 = V_657 -> V_658 ;
struct V_659 * V_660 = V_658 -> V_661 ;
int V_563 ;
V_563 = F_274 ( V_8 , V_658 , V_694 ) ;
if ( V_563 )
return V_563 ;
if ( V_660 -> V_28 == V_191 ||
V_660 -> V_28 == V_195 ) {
struct V_263 V_264 ;
struct V_662 V_617 = { 0 ,} ;
struct V_672 * V_673 = NULL ;
struct V_674 * V_675 = NULL ;
unsigned short V_676 ;
T_2 V_14 , V_240 ;
if ( V_658 -> V_671 == V_189 ) {
V_673 = (struct V_672 * ) V_668 ;
if ( V_669 < sizeof( struct V_672 ) )
return - V_86 ;
V_676 = F_264 ( V_673 -> V_678 ) ;
} else {
V_675 = (struct V_674 * ) V_668 ;
if ( V_669 < V_695 )
return - V_86 ;
V_676 = F_264 ( V_675 -> V_681 ) ;
}
V_563 = F_281 ( V_658 -> V_688 , V_676 , & V_14 ) ;
if ( V_563 )
goto V_66;
V_240 = ( V_660 -> V_28 == V_191 ) ?
V_696 : V_697 ;
V_264 . type = V_663 ;
V_264 . V_269 . V_617 = & V_617 ;
V_264 . V_269 . V_617 -> V_628 = F_282 ( V_676 ) ;
V_264 . V_269 . V_617 -> V_182 = V_658 -> V_671 ;
V_563 = F_35 ( V_660 -> V_14 , V_14 , V_660 -> V_28 , V_240 , & V_264 ) ;
if ( V_563 )
goto V_66;
}
V_563 = F_285 ( V_658 , V_668 ) ;
V_66:
return V_563 ;
}
static int F_286 ( struct V_666 * V_657 , int V_698 )
{
return F_274 ( V_8 , V_657 -> V_658 , V_699 ) ;
}
static int F_287 ( struct V_666 * V_657 , struct V_666 * V_700 )
{
int V_563 ;
struct V_20 * V_21 ;
struct V_20 * V_135 ;
V_563 = F_274 ( V_8 , V_657 -> V_658 , V_701 ) ;
if ( V_563 )
return V_563 ;
V_135 = F_277 ( V_700 ) -> V_30 ;
V_21 = F_277 ( V_657 ) -> V_30 ;
V_135 -> V_28 = V_21 -> V_28 ;
V_135 -> V_14 = V_21 -> V_14 ;
V_135 -> V_118 = 1 ;
return 0 ;
}
static int F_288 ( struct V_666 * V_657 , struct V_702 * V_703 ,
int V_502 )
{
return F_274 ( V_8 , V_657 -> V_658 , V_704 ) ;
}
static int F_289 ( struct V_666 * V_657 , struct V_702 * V_703 ,
int V_502 , int V_69 )
{
return F_274 ( V_8 , V_657 -> V_658 , V_705 ) ;
}
static int F_290 ( struct V_666 * V_657 )
{
return F_274 ( V_8 , V_657 -> V_658 , V_706 ) ;
}
static int F_291 ( struct V_666 * V_657 )
{
return F_274 ( V_8 , V_657 -> V_658 , V_706 ) ;
}
static int F_292 ( struct V_666 * V_657 , int V_707 , int V_708 )
{
int V_563 ;
V_563 = F_274 ( V_8 , V_657 -> V_658 , V_709 ) ;
if ( V_563 )
return V_563 ;
return F_293 ( V_657 , V_707 , V_708 ) ;
}
static int F_294 ( struct V_666 * V_657 , int V_707 ,
int V_708 )
{
return F_274 ( V_8 , V_657 -> V_658 , V_710 ) ;
}
static int F_295 ( struct V_666 * V_657 , int V_711 )
{
return F_274 ( V_8 , V_657 -> V_658 , V_712 ) ;
}
static int F_296 ( struct V_657 * V_657 ,
struct V_657 * V_713 ,
struct V_657 * V_714 )
{
struct V_659 * V_715 = V_657 -> V_661 ;
struct V_659 * V_716 = V_713 -> V_661 ;
struct V_659 * V_717 = V_714 -> V_661 ;
struct V_263 V_264 ;
struct V_662 V_617 = { 0 ,} ;
int V_563 ;
V_264 . type = V_663 ;
V_264 . V_269 . V_617 = & V_617 ;
V_264 . V_269 . V_617 -> V_658 = V_713 ;
V_563 = F_35 ( V_715 -> V_14 , V_716 -> V_14 ,
V_716 -> V_28 ,
V_718 , & V_264 ) ;
if ( V_563 )
return V_563 ;
V_717 -> V_719 = V_715 -> V_14 ;
V_563 = F_297 ( V_716 -> V_14 , V_715 -> V_14 ,
& V_717 -> V_14 ) ;
if ( V_563 )
return V_563 ;
V_715 -> V_719 = V_717 -> V_14 ;
return 0 ;
}
static int F_298 ( struct V_666 * V_657 ,
struct V_666 * V_713 )
{
struct V_659 * V_720 = V_657 -> V_658 -> V_661 ;
struct V_659 * V_721 = V_713 -> V_658 -> V_661 ;
struct V_263 V_264 ;
struct V_662 V_617 = { 0 ,} ;
V_264 . type = V_663 ;
V_264 . V_269 . V_617 = & V_617 ;
V_264 . V_269 . V_617 -> V_658 = V_713 -> V_658 ;
return F_35 ( V_720 -> V_14 , V_721 -> V_14 , V_721 -> V_28 , V_722 ,
& V_264 ) ;
}
static int F_299 ( int V_723 , char * V_646 , T_4 V_182 ,
T_2 V_719 ,
struct V_263 * V_264 )
{
int V_563 ;
T_2 V_724 ;
T_2 V_725 ;
V_563 = F_300 ( V_723 , & V_724 ) ;
if ( V_563 )
return V_563 ;
V_563 = F_35 ( V_719 , V_724 ,
V_726 , V_727 , V_264 ) ;
if ( V_563 )
return V_563 ;
V_563 = F_283 ( V_646 , V_182 , & V_725 ) ;
if ( V_563 )
return V_563 ;
return F_35 ( V_719 , V_725 ,
V_728 , V_729 , V_264 ) ;
}
static int F_301 ( struct V_657 * V_658 , struct V_608 * V_609 ,
T_4 V_182 )
{
int V_563 = 0 ;
struct V_659 * V_660 = V_658 -> V_661 ;
T_2 V_730 = V_660 -> V_14 ;
struct V_263 V_264 ;
struct V_662 V_617 = { 0 ,} ;
char * V_646 ;
V_264 . type = V_663 ;
V_264 . V_269 . V_617 = & V_617 ;
V_264 . V_269 . V_617 -> V_731 = V_609 -> V_732 ;
V_264 . V_269 . V_617 -> V_182 = V_182 ;
V_563 = F_267 ( V_609 , & V_264 , & V_646 , 1 , NULL ) ;
if ( V_563 )
return V_563 ;
if ( F_4 () ) {
V_563 = F_35 ( V_730 , V_609 -> V_733 , V_734 ,
V_735 , & V_264 ) ;
if ( V_563 )
return V_563 ;
}
V_563 = F_302 ( V_660 , V_609 , V_182 , & V_264 ) ;
if ( V_563 )
return V_563 ;
V_563 = F_303 ( V_660 -> V_14 , V_609 , & V_264 ) ;
return V_563 ;
}
static int F_304 ( struct V_657 * V_658 , struct V_608 * V_609 )
{
int V_563 ;
struct V_659 * V_660 = V_658 -> V_661 ;
T_4 V_182 = V_658 -> V_671 ;
T_2 V_730 = V_660 -> V_14 ;
struct V_263 V_264 ;
struct V_662 V_617 = { 0 ,} ;
char * V_646 ;
T_13 V_736 ;
T_13 V_737 ;
if ( V_182 != V_189 && V_182 != V_190 )
return 0 ;
if ( V_182 == V_190 && V_609 -> V_178 == F_282 ( V_738 ) )
V_182 = V_189 ;
if ( ! V_739 )
return F_301 ( V_658 , V_609 , V_182 ) ;
V_736 = F_4 () ;
V_737 = F_305 () || F_306 () ;
if ( ! V_736 && ! V_737 )
return 0 ;
V_264 . type = V_663 ;
V_264 . V_269 . V_617 = & V_617 ;
V_264 . V_269 . V_617 -> V_731 = V_609 -> V_732 ;
V_264 . V_269 . V_617 -> V_182 = V_182 ;
V_563 = F_267 ( V_609 , & V_264 , & V_646 , 1 , NULL ) ;
if ( V_563 )
return V_563 ;
if ( V_737 ) {
T_2 V_719 ;
V_563 = F_269 ( V_609 , V_182 , & V_719 ) ;
if ( V_563 )
return V_563 ;
V_563 = F_299 ( V_609 -> V_732 , V_646 , V_182 ,
V_719 , & V_264 ) ;
if ( V_563 ) {
F_307 ( V_609 , V_563 , 0 ) ;
return V_563 ;
}
V_563 = F_35 ( V_730 , V_719 , V_740 ,
V_741 , & V_264 ) ;
if ( V_563 )
F_307 ( V_609 , V_563 , 0 ) ;
}
if ( V_736 ) {
V_563 = F_35 ( V_730 , V_609 -> V_733 , V_734 ,
V_735 , & V_264 ) ;
if ( V_563 )
return V_563 ;
}
return V_563 ;
}
static int F_308 ( struct V_666 * V_657 , char T_15 * V_742 ,
int T_15 * V_743 , unsigned V_84 )
{
int V_563 = 0 ;
char * V_744 ;
T_2 V_745 ;
struct V_659 * V_660 = V_657 -> V_658 -> V_661 ;
T_2 V_719 = V_656 ;
if ( V_660 -> V_28 == V_186 ||
V_660 -> V_28 == V_191 )
V_719 = V_660 -> V_719 ;
if ( V_719 == V_656 )
return - V_746 ;
V_563 = F_47 ( V_719 , & V_744 , & V_745 ) ;
if ( V_563 )
return V_563 ;
if ( V_745 > V_84 ) {
V_563 = - V_231 ;
goto V_747;
}
if ( F_309 ( V_742 , V_744 , V_745 ) )
V_563 = - V_748 ;
V_747:
if ( F_310 ( V_745 , V_743 ) )
V_563 = - V_748 ;
F_28 ( V_744 ) ;
return V_563 ;
}
static int F_311 ( struct V_666 * V_657 , struct V_608 * V_609 , T_2 * V_515 )
{
T_2 V_749 = V_656 ;
T_4 V_182 ;
if ( V_609 && V_609 -> V_178 == F_282 ( V_738 ) )
V_182 = V_189 ;
else if ( V_609 && V_609 -> V_178 == F_282 ( V_750 ) )
V_182 = V_190 ;
else if ( V_657 )
V_182 = V_657 -> V_658 -> V_671 ;
else
goto V_66;
if ( V_657 && V_182 == V_183 )
F_216 ( F_277 ( V_657 ) , & V_749 ) ;
else if ( V_609 )
F_269 ( V_609 , V_182 , & V_749 ) ;
V_66:
* V_515 = V_749 ;
if ( V_749 == V_656 )
return - V_86 ;
return 0 ;
}
static int F_312 ( struct V_657 * V_658 , int V_182 , T_11 V_751 )
{
struct V_659 * V_660 ;
V_660 = F_7 ( sizeof( * V_660 ) , V_751 ) ;
if ( ! V_660 )
return - V_24 ;
V_660 -> V_719 = V_27 ;
V_660 -> V_14 = V_27 ;
F_313 ( V_660 ) ;
V_658 -> V_661 = V_660 ;
return 0 ;
}
static void F_314 ( struct V_657 * V_658 )
{
struct V_659 * V_660 = V_658 -> V_661 ;
V_658 -> V_661 = NULL ;
F_315 ( V_660 ) ;
F_28 ( V_660 ) ;
}
static void F_316 ( const struct V_657 * V_658 , struct V_657 * V_714 )
{
struct V_659 * V_660 = V_658 -> V_661 ;
struct V_659 * V_752 = V_714 -> V_661 ;
V_752 -> V_14 = V_660 -> V_14 ;
V_752 -> V_719 = V_660 -> V_719 ;
V_752 -> V_28 = V_660 -> V_28 ;
F_313 ( V_752 ) ;
}
static void F_317 ( struct V_657 * V_658 , T_2 * V_515 )
{
if ( ! V_658 )
* V_515 = V_753 ;
else {
struct V_659 * V_660 = V_658 -> V_661 ;
* V_515 = V_660 -> V_14 ;
}
}
static void F_318 ( struct V_657 * V_658 , struct V_666 * V_336 )
{
struct V_20 * V_21 = F_277 ( V_336 ) -> V_30 ;
struct V_659 * V_660 = V_658 -> V_661 ;
if ( V_658 -> V_671 == V_189 || V_658 -> V_671 == V_190 ||
V_658 -> V_671 == V_183 )
V_21 -> V_14 = V_660 -> V_14 ;
V_660 -> V_28 = V_21 -> V_28 ;
}
static int F_319 ( struct V_657 * V_658 , struct V_608 * V_609 ,
struct V_754 * V_755 )
{
struct V_659 * V_660 = V_658 -> V_661 ;
int V_563 ;
T_4 V_182 = V_658 -> V_671 ;
T_2 V_283 ;
T_2 V_756 ;
if ( V_182 == V_190 && V_609 -> V_178 == F_282 ( V_738 ) )
V_182 = V_189 ;
V_563 = F_269 ( V_609 , V_182 , & V_756 ) ;
if ( V_563 )
return V_563 ;
if ( V_756 == V_656 ) {
V_755 -> V_515 = V_660 -> V_14 ;
V_755 -> V_749 = V_656 ;
} else {
V_563 = F_297 ( V_660 -> V_14 , V_756 , & V_283 ) ;
if ( V_563 )
return V_563 ;
V_755 -> V_515 = V_283 ;
V_755 -> V_749 = V_756 ;
}
return F_320 ( V_755 , V_182 ) ;
}
static void F_321 ( struct V_657 * V_714 ,
const struct V_754 * V_755 )
{
struct V_659 * V_752 = V_714 -> V_661 ;
V_752 -> V_14 = V_755 -> V_515 ;
V_752 -> V_719 = V_755 -> V_749 ;
F_322 ( V_714 , V_755 -> V_757 -> V_182 ) ;
}
static void F_323 ( struct V_657 * V_658 , struct V_608 * V_609 )
{
T_4 V_182 = V_658 -> V_671 ;
struct V_659 * V_660 = V_658 -> V_661 ;
if ( V_182 == V_190 && V_609 -> V_178 == F_282 ( V_738 ) )
V_182 = V_189 ;
F_269 ( V_609 , V_182 , & V_660 -> V_719 ) ;
}
static void F_324 ( struct V_608 * V_609 , struct V_657 * V_658 )
{
F_325 ( V_609 , V_658 ) ;
}
static int F_326 ( T_2 V_14 )
{
const struct V_10 * V_758 ;
T_2 V_252 ;
V_758 = F_15 () ;
V_252 = V_758 -> V_14 ;
return F_35 ( V_252 , V_14 , V_734 , V_759 , NULL ) ;
}
static void F_327 ( void )
{
F_328 ( & V_6 ) ;
}
static void F_329 ( void )
{
F_330 ( & V_6 ) ;
}
static void F_331 ( const struct V_754 * V_755 ,
struct V_760 * V_761 )
{
V_761 -> V_762 = V_755 -> V_515 ;
}
static int F_332 ( void * * V_16 )
{
struct V_763 * V_764 ;
V_764 = F_7 ( sizeof( * V_764 ) , V_12 ) ;
if ( ! V_764 )
return - V_24 ;
V_764 -> V_14 = F_14 () ;
* V_16 = V_764 ;
return 0 ;
}
static void F_333 ( void * V_16 )
{
F_28 ( V_16 ) ;
}
static int F_334 ( void )
{
T_2 V_14 = F_14 () ;
return F_35 ( V_14 , V_14 , V_765 , V_766 ,
NULL ) ;
}
static int F_335 ( void * V_16 )
{
struct V_763 * V_764 = V_16 ;
return F_35 ( F_14 () , V_764 -> V_14 , V_765 ,
V_767 , NULL ) ;
}
static int F_336 ( struct V_657 * V_658 , void * V_16 )
{
struct V_763 * V_764 = V_16 ;
struct V_659 * V_660 = V_658 -> V_661 ;
V_660 -> V_14 = V_764 -> V_14 ;
V_660 -> V_28 = V_765 ;
return 0 ;
}
static int F_337 ( void * V_16 )
{
struct V_763 * V_764 = V_16 ;
T_2 V_14 = F_14 () ;
int V_563 ;
V_563 = F_35 ( V_14 , V_764 -> V_14 , V_765 ,
V_768 , NULL ) ;
if ( V_563 )
return V_563 ;
V_563 = F_35 ( V_14 , V_14 , V_765 ,
V_769 , NULL ) ;
if ( V_563 )
return V_563 ;
V_764 -> V_14 = V_14 ;
return 0 ;
}
static int F_338 ( struct V_657 * V_658 , struct V_608 * V_609 )
{
int V_563 = 0 ;
T_2 V_240 ;
struct V_770 * V_771 ;
struct V_659 * V_660 = V_658 -> V_661 ;
if ( V_609 -> V_84 < V_772 ) {
V_563 = - V_86 ;
goto V_66;
}
V_771 = F_339 ( V_609 ) ;
V_563 = F_340 ( V_660 -> V_28 , V_771 -> V_773 , & V_240 ) ;
if ( V_563 ) {
if ( V_563 == - V_86 ) {
F_341 ( V_8 -> V_508 , V_12 , V_509 ,
L_48
L_49 ,
V_771 -> V_773 , V_660 -> V_28 ) ;
if ( ! V_3 || F_342 () )
V_563 = 0 ;
}
if ( V_563 == - V_774 )
V_563 = 0 ;
goto V_66;
}
V_563 = F_274 ( V_8 , V_658 , V_240 ) ;
V_66:
return V_563 ;
}
static unsigned int F_343 ( struct V_608 * V_609 , int V_723 ,
T_4 V_182 )
{
int V_563 ;
char * V_646 ;
T_2 V_719 ;
struct V_263 V_264 ;
struct V_662 V_617 = { 0 ,} ;
T_13 V_736 ;
T_13 V_775 ;
T_13 V_737 ;
if ( ! V_739 )
return V_776 ;
V_736 = F_4 () ;
V_775 = F_305 () ;
V_737 = V_775 || F_306 () ;
if ( ! V_736 && ! V_737 )
return V_776 ;
if ( F_269 ( V_609 , V_182 , & V_719 ) != 0 )
return V_777 ;
V_264 . type = V_663 ;
V_264 . V_269 . V_617 = & V_617 ;
V_264 . V_269 . V_617 -> V_731 = V_723 ;
V_264 . V_269 . V_617 -> V_182 = V_182 ;
if ( F_267 ( V_609 , & V_264 , & V_646 , 1 , NULL ) != 0 )
return V_777 ;
if ( V_737 ) {
V_563 = F_299 ( V_723 , V_646 , V_182 ,
V_719 , & V_264 ) ;
if ( V_563 ) {
F_307 ( V_609 , V_563 , 1 ) ;
return V_777 ;
}
}
if ( V_736 )
if ( F_35 ( V_719 , V_609 -> V_733 ,
V_734 , V_778 , & V_264 ) )
return V_777 ;
if ( V_775 )
if ( F_344 ( V_609 , V_182 , V_719 ) != 0 )
return V_777 ;
return V_776 ;
}
static unsigned int F_345 ( unsigned int V_779 ,
struct V_608 * V_609 ,
const struct V_780 * V_781 ,
const struct V_780 * V_66 ,
int (* F_346)( struct V_608 * ) )
{
return F_343 ( V_609 , V_781 -> V_723 , V_189 ) ;
}
static unsigned int F_347 ( unsigned int V_779 ,
struct V_608 * V_609 ,
const struct V_780 * V_781 ,
const struct V_780 * V_66 ,
int (* F_346)( struct V_608 * ) )
{
return F_343 ( V_609 , V_781 -> V_723 , V_190 ) ;
}
static unsigned int F_348 ( struct V_608 * V_609 ,
T_4 V_182 )
{
T_2 V_14 ;
if ( ! F_305 () )
return V_776 ;
if ( V_609 -> V_658 ) {
struct V_659 * V_660 = V_609 -> V_658 -> V_661 ;
V_14 = V_660 -> V_14 ;
} else
V_14 = V_15 ;
if ( F_344 ( V_609 , V_182 , V_14 ) != 0 )
return V_777 ;
return V_776 ;
}
static unsigned int F_349 ( unsigned int V_779 ,
struct V_608 * V_609 ,
const struct V_780 * V_781 ,
const struct V_780 * V_66 ,
int (* F_346)( struct V_608 * ) )
{
return F_348 ( V_609 , V_189 ) ;
}
static unsigned int F_350 ( struct V_608 * V_609 ,
int V_723 ,
T_4 V_182 )
{
struct V_657 * V_658 = V_609 -> V_658 ;
struct V_659 * V_660 ;
struct V_263 V_264 ;
struct V_662 V_617 = { 0 ,} ;
char * V_646 ;
T_13 V_610 ;
if ( V_658 == NULL )
return V_776 ;
V_660 = V_658 -> V_661 ;
V_264 . type = V_663 ;
V_264 . V_269 . V_617 = & V_617 ;
V_264 . V_269 . V_617 -> V_731 = V_723 ;
V_264 . V_269 . V_617 -> V_182 = V_182 ;
if ( F_267 ( V_609 , & V_264 , & V_646 , 0 , & V_610 ) )
return V_777 ;
if ( F_4 () )
if ( F_35 ( V_660 -> V_14 , V_609 -> V_733 ,
V_734 , V_782 , & V_264 ) )
return F_351 ( - V_783 ) ;
if ( F_352 ( V_660 -> V_14 , V_609 , & V_264 , V_610 ) )
return F_351 ( - V_783 ) ;
return V_776 ;
}
static unsigned int F_353 ( struct V_608 * V_609 , int V_723 ,
T_4 V_182 )
{
T_2 V_784 ;
T_2 V_719 ;
struct V_657 * V_658 ;
struct V_263 V_264 ;
struct V_662 V_617 = { 0 ,} ;
char * V_646 ;
T_13 V_736 ;
T_13 V_737 ;
if ( ! V_739 )
return F_350 ( V_609 , V_723 , V_182 ) ;
#ifdef F_354
if ( F_355 ( V_609 ) != NULL && F_355 ( V_609 ) -> V_785 != NULL )
return V_776 ;
#endif
V_736 = F_4 () ;
V_737 = F_305 () || F_306 () ;
if ( ! V_736 && ! V_737 )
return V_776 ;
V_658 = V_609 -> V_658 ;
if ( V_658 == NULL ) {
if ( V_609 -> V_732 ) {
V_784 = V_786 ;
if ( F_269 ( V_609 , V_182 , & V_719 ) )
return V_777 ;
} else {
V_784 = V_782 ;
V_719 = V_15 ;
}
} else {
struct V_659 * V_660 = V_658 -> V_661 ;
V_719 = V_660 -> V_14 ;
V_784 = V_782 ;
}
V_264 . type = V_663 ;
V_264 . V_269 . V_617 = & V_617 ;
V_264 . V_269 . V_617 -> V_731 = V_723 ;
V_264 . V_269 . V_617 -> V_182 = V_182 ;
if ( F_267 ( V_609 , & V_264 , & V_646 , 0 , NULL ) )
return V_777 ;
if ( V_736 )
if ( F_35 ( V_719 , V_609 -> V_733 ,
V_734 , V_784 , & V_264 ) )
return F_351 ( - V_783 ) ;
if ( V_737 ) {
T_2 V_724 ;
T_2 V_725 ;
if ( F_300 ( V_723 , & V_724 ) )
return V_777 ;
if ( F_35 ( V_719 , V_724 ,
V_726 , V_787 , & V_264 ) )
return F_351 ( - V_783 ) ;
if ( F_283 ( V_646 , V_182 , & V_725 ) )
return V_777 ;
if ( F_35 ( V_719 , V_725 ,
V_728 , V_788 , & V_264 ) )
return F_351 ( - V_783 ) ;
}
return V_776 ;
}
static unsigned int F_356 ( unsigned int V_779 ,
struct V_608 * V_609 ,
const struct V_780 * V_781 ,
const struct V_780 * V_66 ,
int (* F_346)( struct V_608 * ) )
{
return F_353 ( V_609 , V_66 -> V_723 , V_189 ) ;
}
static unsigned int F_357 ( unsigned int V_779 ,
struct V_608 * V_609 ,
const struct V_780 * V_781 ,
const struct V_780 * V_66 ,
int (* F_346)( struct V_608 * ) )
{
return F_353 ( V_609 , V_66 -> V_723 , V_190 ) ;
}
static int F_358 ( struct V_657 * V_658 , struct V_608 * V_609 )
{
int V_563 ;
V_563 = F_359 ( V_658 , V_609 ) ;
if ( V_563 )
return V_563 ;
return F_338 ( V_658 , V_609 ) ;
}
static int F_360 ( struct V_17 * V_18 ,
struct V_789 * V_240 ,
T_4 V_28 )
{
struct V_790 * V_21 ;
T_2 V_14 ;
V_21 = F_7 ( sizeof( struct V_790 ) , V_12 ) ;
if ( ! V_21 )
return - V_24 ;
V_14 = F_10 ( V_18 ) ;
V_21 -> V_28 = V_28 ;
V_21 -> V_14 = V_14 ;
V_240 -> V_16 = V_21 ;
return 0 ;
}
static void F_361 ( struct V_789 * V_240 )
{
struct V_790 * V_21 = V_240 -> V_16 ;
V_240 -> V_16 = NULL ;
F_28 ( V_21 ) ;
}
static int F_362 ( struct V_791 * V_703 )
{
struct V_792 * V_793 ;
V_793 = F_7 ( sizeof( struct V_792 ) , V_12 ) ;
if ( ! V_793 )
return - V_24 ;
V_793 -> V_14 = V_27 ;
V_703 -> V_16 = V_793 ;
return 0 ;
}
static void F_363 ( struct V_791 * V_703 )
{
struct V_792 * V_793 = V_703 -> V_16 ;
V_703 -> V_16 = NULL ;
F_28 ( V_793 ) ;
}
static int F_364 ( struct V_789 * V_794 ,
T_2 V_250 )
{
struct V_790 * V_21 ;
struct V_263 V_264 ;
T_2 V_14 = F_14 () ;
V_21 = V_794 -> V_16 ;
V_264 . type = V_795 ;
V_264 . V_269 . V_796 = V_794 -> V_797 ;
return F_35 ( V_14 , V_21 -> V_14 , V_21 -> V_28 , V_250 , & V_264 ) ;
}
static int F_365 ( struct V_791 * V_703 )
{
return F_362 ( V_703 ) ;
}
static void F_366 ( struct V_791 * V_703 )
{
F_363 ( V_703 ) ;
}
static int F_367 ( struct V_798 * V_799 )
{
struct V_790 * V_21 ;
struct V_263 V_264 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_360 ( V_8 , & V_799 -> V_800 , V_801 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_799 -> V_800 . V_16 ;
V_264 . type = V_795 ;
V_264 . V_269 . V_796 = V_799 -> V_800 . V_797 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_801 ,
V_802 , & V_264 ) ;
if ( V_47 ) {
F_361 ( & V_799 -> V_800 ) ;
return V_47 ;
}
return 0 ;
}
static void F_368 ( struct V_798 * V_799 )
{
F_361 ( & V_799 -> V_800 ) ;
}
static int F_369 ( struct V_798 * V_799 , int V_803 )
{
struct V_790 * V_21 ;
struct V_263 V_264 ;
T_2 V_14 = F_14 () ;
V_21 = V_799 -> V_800 . V_16 ;
V_264 . type = V_795 ;
V_264 . V_269 . V_796 = V_799 -> V_800 . V_797 ;
return F_35 ( V_14 , V_21 -> V_14 , V_801 ,
V_804 , & V_264 ) ;
}
static int F_370 ( struct V_798 * V_799 , int V_518 )
{
int V_563 ;
int V_250 ;
switch ( V_518 ) {
case V_805 :
case V_806 :
return F_99 ( V_8 , V_807 ) ;
case V_808 :
case V_809 :
V_250 = V_810 | V_804 ;
break;
case V_811 :
V_250 = V_812 ;
break;
case V_813 :
V_250 = V_814 ;
break;
default:
return 0 ;
}
V_563 = F_364 ( & V_799 -> V_800 , V_250 ) ;
return V_563 ;
}
static int F_371 ( struct V_798 * V_799 , struct V_791 * V_703 , int V_803 )
{
struct V_790 * V_21 ;
struct V_792 * V_793 ;
struct V_263 V_264 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_21 = V_799 -> V_800 . V_16 ;
V_793 = V_703 -> V_16 ;
if ( V_793 -> V_14 == V_27 ) {
V_47 = F_88 ( V_14 , V_21 -> V_14 , V_815 ,
NULL , & V_793 -> V_14 ) ;
if ( V_47 )
return V_47 ;
}
V_264 . type = V_795 ;
V_264 . V_269 . V_796 = V_799 -> V_800 . V_797 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_801 ,
V_816 , & V_264 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_14 , V_793 -> V_14 , V_815 ,
V_817 , & V_264 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_793 -> V_14 , V_21 -> V_14 , V_801 ,
V_818 , & V_264 ) ;
return V_47 ;
}
static int F_372 ( struct V_798 * V_799 , struct V_791 * V_703 ,
struct V_17 * V_249 ,
long type , int V_163 )
{
struct V_790 * V_21 ;
struct V_792 * V_793 ;
struct V_263 V_264 ;
T_2 V_14 = F_10 ( V_249 ) ;
int V_47 ;
V_21 = V_799 -> V_800 . V_16 ;
V_793 = V_703 -> V_16 ;
V_264 . type = V_795 ;
V_264 . V_269 . V_796 = V_799 -> V_800 . V_797 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 ,
V_801 , V_819 , & V_264 ) ;
if ( ! V_47 )
V_47 = F_35 ( V_14 , V_793 -> V_14 ,
V_815 , V_820 , & V_264 ) ;
return V_47 ;
}
static int F_373 ( struct V_821 * V_822 )
{
struct V_790 * V_21 ;
struct V_263 V_264 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_360 ( V_8 , & V_822 -> V_823 , V_824 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_822 -> V_823 . V_16 ;
V_264 . type = V_795 ;
V_264 . V_269 . V_796 = V_822 -> V_823 . V_797 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_824 ,
V_825 , & V_264 ) ;
if ( V_47 ) {
F_361 ( & V_822 -> V_823 ) ;
return V_47 ;
}
return 0 ;
}
static void F_374 ( struct V_821 * V_822 )
{
F_361 ( & V_822 -> V_823 ) ;
}
static int F_375 ( struct V_821 * V_822 , int V_826 )
{
struct V_790 * V_21 ;
struct V_263 V_264 ;
T_2 V_14 = F_14 () ;
V_21 = V_822 -> V_823 . V_16 ;
V_264 . type = V_795 ;
V_264 . V_269 . V_796 = V_822 -> V_823 . V_797 ;
return F_35 ( V_14 , V_21 -> V_14 , V_824 ,
V_827 , & V_264 ) ;
}
static int F_376 ( struct V_821 * V_822 , int V_518 )
{
int V_250 ;
int V_563 ;
switch ( V_518 ) {
case V_805 :
case V_828 :
return F_99 ( V_8 , V_807 ) ;
case V_808 :
case V_829 :
V_250 = V_830 | V_827 ;
break;
case V_811 :
V_250 = V_831 ;
break;
case V_832 :
case V_833 :
V_250 = V_834 ;
break;
case V_813 :
V_250 = V_835 ;
break;
default:
return 0 ;
}
V_563 = F_364 ( & V_822 -> V_823 , V_250 ) ;
return V_563 ;
}
static int F_377 ( struct V_821 * V_822 ,
char T_15 * V_836 , int V_826 )
{
T_2 V_250 ;
if ( V_826 & V_837 )
V_250 = V_838 ;
else
V_250 = V_838 | V_839 ;
return F_364 ( & V_822 -> V_823 , V_250 ) ;
}
static int F_378 ( struct V_840 * V_841 )
{
struct V_790 * V_21 ;
struct V_263 V_264 ;
T_2 V_14 = F_14 () ;
int V_47 ;
V_47 = F_360 ( V_8 , & V_841 -> V_842 , V_843 ) ;
if ( V_47 )
return V_47 ;
V_21 = V_841 -> V_842 . V_16 ;
V_264 . type = V_795 ;
V_264 . V_269 . V_796 = V_841 -> V_842 . V_797 ;
V_47 = F_35 ( V_14 , V_21 -> V_14 , V_843 ,
V_844 , & V_264 ) ;
if ( V_47 ) {
F_361 ( & V_841 -> V_842 ) ;
return V_47 ;
}
return 0 ;
}
static void F_379 ( struct V_840 * V_841 )
{
F_361 ( & V_841 -> V_842 ) ;
}
static int F_380 ( struct V_840 * V_841 , int V_845 )
{
struct V_790 * V_21 ;
struct V_263 V_264 ;
T_2 V_14 = F_14 () ;
V_21 = V_841 -> V_842 . V_16 ;
V_264 . type = V_795 ;
V_264 . V_269 . V_796 = V_841 -> V_842 . V_797 ;
return F_35 ( V_14 , V_21 -> V_14 , V_843 ,
V_846 , & V_264 ) ;
}
static int F_381 ( struct V_840 * V_841 , int V_518 )
{
int V_563 ;
T_2 V_250 ;
switch ( V_518 ) {
case V_805 :
case V_847 :
return F_99 ( V_8 , V_807 ) ;
case V_848 :
case V_849 :
case V_850 :
V_250 = V_851 ;
break;
case V_852 :
case V_853 :
V_250 = V_854 ;
break;
case V_855 :
case V_856 :
V_250 = V_857 ;
break;
case V_813 :
V_250 = V_858 ;
break;
case V_811 :
V_250 = V_859 ;
break;
case V_808 :
case V_860 :
V_250 = V_851 | V_846 ;
break;
default:
return 0 ;
}
V_563 = F_364 ( & V_841 -> V_842 , V_250 ) ;
return V_563 ;
}
static int F_382 ( struct V_840 * V_841 ,
struct V_861 * V_862 , unsigned V_863 , int V_864 )
{
T_2 V_250 ;
if ( V_864 )
V_250 = V_854 | V_857 ;
else
V_250 = V_854 ;
return F_364 ( & V_841 -> V_842 , V_250 ) ;
}
static int F_383 ( struct V_789 * V_865 , short V_98 )
{
T_2 V_267 = 0 ;
V_267 = 0 ;
if ( V_98 & V_866 )
V_267 |= V_867 ;
if ( V_98 & V_868 )
V_267 |= V_869 ;
if ( V_267 == 0 )
return 0 ;
return F_364 ( V_865 , V_267 ) ;
}
static void F_384 ( struct V_789 * V_865 , T_2 * V_515 )
{
struct V_790 * V_21 = V_865 -> V_16 ;
* V_515 = V_21 -> V_14 ;
}
static void F_385 ( struct V_52 * V_52 , struct V_19 * V_19 )
{
if ( V_19 )
F_33 ( V_19 , V_52 ) ;
}
static int F_386 ( struct V_17 * V_139 ,
char * V_64 , char * * V_472 )
{
const struct V_10 * V_758 ;
T_2 V_14 ;
int error ;
unsigned V_84 ;
if ( V_8 != V_139 ) {
error = F_93 ( V_139 , V_870 ) ;
if ( error )
return error ;
}
F_11 () ;
V_758 = F_12 ( V_139 ) -> V_16 ;
if ( ! strcmp ( V_64 , L_50 ) )
V_14 = V_758 -> V_14 ;
else if ( ! strcmp ( V_64 , L_51 ) )
V_14 = V_758 -> V_13 ;
else if ( ! strcmp ( V_64 , L_52 ) )
V_14 = V_758 -> V_384 ;
else if ( ! strcmp ( V_64 , L_53 ) )
V_14 = V_758 -> V_284 ;
else if ( ! strcmp ( V_64 , L_54 ) )
V_14 = V_758 -> V_382 ;
else if ( ! strcmp ( V_64 , L_55 ) )
V_14 = V_758 -> V_383 ;
else
goto V_871;
F_13 () ;
if ( ! V_14 )
return 0 ;
error = F_47 ( V_14 , V_472 , & V_84 ) ;
if ( error )
return error ;
return V_84 ;
V_871:
F_13 () ;
return - V_86 ;
}
static int F_387 ( struct V_17 * V_139 ,
char * V_64 , void * V_472 , T_7 V_502 )
{
struct V_10 * V_11 ;
struct V_17 * V_397 ;
struct V_7 * V_122 ;
T_2 V_14 = 0 , V_399 ;
int error ;
char * V_1 = V_472 ;
if ( V_8 != V_139 ) {
return - V_511 ;
}
if ( ! strcmp ( V_64 , L_52 ) )
error = F_93 ( V_139 , V_872 ) ;
else if ( ! strcmp ( V_64 , L_53 ) )
error = F_93 ( V_139 , V_873 ) ;
else if ( ! strcmp ( V_64 , L_54 ) )
error = F_93 ( V_139 , V_874 ) ;
else if ( ! strcmp ( V_64 , L_55 ) )
error = F_93 ( V_139 , V_875 ) ;
else if ( ! strcmp ( V_64 , L_50 ) )
error = F_93 ( V_139 , V_876 ) ;
else
error = - V_86 ;
if ( error )
return error ;
if ( V_502 && V_1 [ 1 ] && V_1 [ 1 ] != '\n' ) {
if ( V_1 [ V_502 - 1 ] == '\n' ) {
V_1 [ V_502 - 1 ] = 0 ;
V_502 -- ;
}
error = F_54 ( V_472 , V_502 , & V_14 ) ;
if ( error == - V_86 && ! strcmp ( V_64 , L_53 ) ) {
if ( ! F_200 ( V_504 ) ) {
struct V_505 * V_506 ;
T_7 V_507 ;
if ( V_1 [ V_502 - 1 ] == '\0' )
V_507 = V_502 - 1 ;
else
V_507 = V_502 ;
V_506 = F_203 ( V_8 -> V_508 , V_91 , V_509 ) ;
F_204 ( V_506 , L_56 ) ;
F_205 ( V_506 , V_472 , V_507 ) ;
F_206 ( V_506 ) ;
return error ;
}
error = F_207 ( V_472 , V_502 ,
& V_14 ) ;
}
if ( error )
return error ;
}
V_122 = F_388 () ;
if ( ! V_122 )
return - V_24 ;
V_11 = V_122 -> V_16 ;
if ( ! strcmp ( V_64 , L_52 ) ) {
V_11 -> V_384 = V_14 ;
} else if ( ! strcmp ( V_64 , L_53 ) ) {
V_11 -> V_284 = V_14 ;
} else if ( ! strcmp ( V_64 , L_54 ) ) {
error = F_109 ( V_14 , V_139 ) ;
if ( error )
goto V_877;
V_11 -> V_382 = V_14 ;
} else if ( ! strcmp ( V_64 , L_55 ) ) {
V_11 -> V_383 = V_14 ;
} else if ( ! strcmp ( V_64 , L_50 ) ) {
error = - V_86 ;
if ( V_14 == 0 )
goto V_877;
error = - V_387 ;
if ( ! F_389 () ) {
error = F_390 ( V_11 -> V_14 , V_14 ) ;
if ( error )
goto V_877;
}
error = F_35 ( V_11 -> V_14 , V_14 , V_253 ,
V_878 , NULL ) ;
if ( error )
goto V_877;
V_399 = 0 ;
F_149 ( V_139 ) ;
V_397 = F_134 ( V_139 ) ;
if ( V_397 )
V_399 = F_10 ( V_397 ) ;
F_151 ( V_139 ) ;
if ( V_397 ) {
error = F_35 ( V_399 , V_14 , V_253 ,
V_335 , NULL ) ;
if ( error )
goto V_877;
}
V_11 -> V_14 = V_14 ;
} else {
error = - V_86 ;
goto V_877;
}
F_391 ( V_122 ) ;
return V_502 ;
V_877:
F_392 ( V_122 ) ;
return error ;
}
static int F_393 ( const char * V_64 )
{
return ( strcmp ( V_64 , V_474 ) == 0 ) ;
}
static int F_394 ( T_2 V_515 , char * * V_454 , T_2 * V_879 )
{
return F_47 ( V_515 , V_454 , V_879 ) ;
}
static int F_395 ( const char * V_454 , T_2 V_879 , T_2 * V_515 )
{
return F_54 ( V_454 , V_879 , V_515 ) ;
}
static void F_396 ( char * V_454 , T_2 V_879 )
{
F_28 ( V_454 ) ;
}
static int F_397 ( struct V_19 * V_19 , void * V_290 , T_2 V_470 )
{
return F_214 ( V_19 , V_474 , V_290 , V_470 , 0 ) ;
}
static int F_398 ( struct V_52 * V_52 , void * V_290 , T_2 V_470 )
{
return F_399 ( V_52 , V_67 , V_290 , V_470 , 0 ) ;
}
static int F_400 ( struct V_19 * V_19 , void * * V_290 , T_2 * V_470 )
{
int V_84 = 0 ;
V_84 = F_213 ( V_19 , V_474 ,
V_290 , true ) ;
if ( V_84 < 0 )
return V_84 ;
* V_470 = V_84 ;
return 0 ;
}
static int F_401 ( struct V_797 * V_880 , const struct V_7 * V_7 ,
unsigned long V_69 )
{
const struct V_10 * V_11 ;
struct V_881 * V_882 ;
V_882 = F_7 ( sizeof( struct V_881 ) , V_12 ) ;
if ( ! V_882 )
return - V_24 ;
V_11 = V_7 -> V_16 ;
if ( V_11 -> V_382 )
V_882 -> V_14 = V_11 -> V_382 ;
else
V_882 -> V_14 = V_11 -> V_14 ;
V_880 -> V_16 = V_882 ;
return 0 ;
}
static void F_402 ( struct V_797 * V_880 )
{
struct V_881 * V_882 = V_880 -> V_16 ;
V_880 -> V_16 = NULL ;
F_28 ( V_882 ) ;
}
static int F_403 ( T_16 V_883 ,
const struct V_7 * V_7 ,
T_17 V_240 )
{
struct V_797 * V_797 ;
struct V_881 * V_882 ;
T_2 V_14 ;
if ( V_240 == 0 )
return 0 ;
V_14 = F_9 ( V_7 ) ;
V_797 = F_404 ( V_883 ) ;
V_882 = V_797 -> V_16 ;
return F_35 ( V_14 , V_882 -> V_14 , V_291 , V_240 , NULL ) ;
}
static int F_405 ( struct V_797 * V_797 , char * * V_884 )
{
struct V_881 * V_882 = V_797 -> V_16 ;
char * V_83 = NULL ;
unsigned V_84 ;
int V_47 ;
V_47 = F_47 ( V_882 -> V_14 , & V_83 , & V_84 ) ;
if ( ! V_47 )
V_47 = V_84 ;
* V_884 = V_83 ;
return V_47 ;
}
static T_1 int F_406 ( void )
{
if ( ! F_407 ( & V_885 ) ) {
V_5 = 0 ;
return 0 ;
}
if ( ! V_5 ) {
F_38 ( V_886 L_57 ) ;
return 0 ;
}
F_38 ( V_886 L_58 ) ;
F_6 () ;
V_534 = ! ( V_887 & V_549 ) ;
V_22 = F_408 ( L_59 ,
sizeof( struct V_20 ) ,
0 , V_888 , NULL ) ;
F_409 () ;
if ( F_410 ( & V_885 ) )
F_8 ( L_60 ) ;
if ( V_3 )
F_38 ( V_74 L_61 ) ;
else
F_38 ( V_74 L_62 ) ;
return 0 ;
}
static void F_411 ( struct V_41 * V_42 , void * V_889 )
{
F_63 ( V_42 , NULL ) ;
}
void F_412 ( void )
{
F_38 ( V_74 L_63 ) ;
F_38 ( V_74 L_64 ) ;
F_413 ( F_411 , NULL ) ;
}
static int T_1 F_414 ( void )
{
int V_563 = 0 ;
if ( ! V_5 )
goto V_66;
F_38 ( V_74 L_65 ) ;
V_563 = F_415 ( V_890 , F_39 ( V_890 ) ) ;
if ( V_563 )
F_8 ( L_66 , V_563 ) ;
#if F_268 ( V_649 ) || F_268 ( V_650 )
V_563 = F_415 ( V_891 , F_39 ( V_891 ) ) ;
if ( V_563 )
F_8 ( L_67 , V_563 ) ;
#endif
V_66:
return V_563 ;
}
static void F_416 ( void )
{
F_38 ( V_74 L_68 ) ;
F_417 ( V_890 , F_39 ( V_890 ) ) ;
#if F_268 ( V_649 ) || F_268 ( V_650 )
F_417 ( V_891 , F_39 ( V_891 ) ) ;
#endif
}
int F_418 ( void )
{
if ( V_87 ) {
return - V_86 ;
}
if ( V_892 ) {
return - V_86 ;
}
F_38 ( V_886 L_69 ) ;
V_892 = 1 ;
V_5 = 0 ;
F_419 () ;
F_420 () ;
F_416 () ;
F_421 () ;
return 0 ;
}
